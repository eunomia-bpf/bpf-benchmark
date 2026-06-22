extern char binary_filter_version;
extern char cgroup_id_filter_version;
extern char comm_filter_version;
extern char config_map;
extern char containers_map;
extern char event_data_map;
extern char events;
extern char events_map_version;
extern char generic_sys_exit_tails;
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

static const __u64 __x86_rodata_0[2] = {68719476740ULL, 0ULL};

static __noinline __u64 tracee_trace_ret_arch_prctl_x86_chunk_0(
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
	case 25ULL: goto x86_l_19;
	case 27ULL: goto x86_l_1b;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 44ULL: goto x86_l_2c;
	case 49ULL: goto x86_l_31;
	case 54ULL: goto x86_l_36;
	case 59ULL: goto x86_l_3b;
	case 64ULL: goto x86_l_40;
	case 66ULL: goto x86_l_42;
	case 74ULL: goto x86_l_4a;
	case 79ULL: goto x86_l_4f;
	case 81ULL: goto x86_l_51;
	case 86ULL: goto x86_l_56;
	case 88ULL: goto x86_l_58;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 98ULL: goto x86_l_62;
	case 101ULL: goto x86_l_65;
	case 103ULL: goto x86_l_67;
	case 106ULL: goto x86_l_6a;
	case 108ULL: goto x86_l_6c;
	case 112ULL: goto x86_l_70;
	case 117ULL: goto x86_l_75;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 132ULL: goto x86_l_84;
	case 135ULL: goto x86_l_87;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 144ULL: goto x86_l_90;
	case 148ULL: goto x86_l_94;
	case 150ULL: goto x86_l_96;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 167ULL: goto x86_l_a7;
	case 169ULL: goto x86_l_a9;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 178ULL: goto x86_l_b2;
	case 183ULL: goto x86_l_b7;
	case 194ULL: goto x86_l_c2;
	case 201ULL: goto x86_l_c9;
	case 209ULL: goto x86_l_d1;
	case 214ULL: goto x86_l_d6;
	case 216ULL: goto x86_l_d8;
	case 219ULL: goto x86_l_db;
	case 225ULL: goto x86_l_e1;
	case 228ULL: goto x86_l_e4;
	case 235ULL: goto x86_l_eb;
	case 243ULL: goto x86_l_f3;
	case 248ULL: goto x86_l_f8;
	case 250ULL: goto x86_l_fa;
	case 253ULL: goto x86_l_fd;
	case 259ULL: goto x86_l_103;
	case 262ULL: goto x86_l_106;
	case 272ULL: goto x86_l_110;
	case 280ULL: goto x86_l_118;
	case 291ULL: goto x86_l_123;
	case 302ULL: goto x86_l_12e;
	case 313ULL: goto x86_l_139;
	case 324ULL: goto x86_l_144;
	case 335ULL: goto x86_l_14f;
	case 346ULL: goto x86_l_15a;
	case 357ULL: goto x86_l_165;
	case 368ULL: goto x86_l_170;
	case 375ULL: goto x86_l_177;
	case 383ULL: goto x86_l_17f;
	case 391ULL: goto x86_l_187;
	case 399ULL: goto x86_l_18f;
	case 407ULL: goto x86_l_197;
	case 415ULL: goto x86_l_19f;
	case 423ULL: goto x86_l_1a7;
	case 431ULL: goto x86_l_1af;
	case 439ULL: goto x86_l_1b7;
	case 447ULL: goto x86_l_1bf;
	case 455ULL: goto x86_l_1c7;
	case 463ULL: goto x86_l_1cf;
	case 471ULL: goto x86_l_1d7;
	case 479ULL: goto x86_l_1df;
	case 484ULL: goto x86_l_1e4;
	case 486ULL: goto x86_l_1e6;
	case 490ULL: goto x86_l_1ea;
	case 494ULL: goto x86_l_1ee;
	case 498ULL: goto x86_l_1f2;
	case 506ULL: goto x86_l_1fa;
	case 511ULL: goto x86_l_1ff;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 532ULL: goto x86_l_214;
	case 536ULL: goto x86_l_218;
	case 543ULL: goto x86_l_21f;
	case 550ULL: goto x86_l_226;
	case 558ULL: goto x86_l_22e;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 573ULL: goto x86_l_23d;
	case 576ULL: goto x86_l_240;
	case 578ULL: goto x86_l_242;
	case 582ULL: goto x86_l_246;
	case 589ULL: goto x86_l_24d;
	case 596ULL: goto x86_l_254;
	case 604ULL: goto x86_l_25c;
	case 609ULL: goto x86_l_261;
	case 611ULL: goto x86_l_263;
	case 614ULL: goto x86_l_266;
	case 617ULL: goto x86_l_269;
	case 625ULL: goto x86_l_271;
	case 633ULL: goto x86_l_279;
	case 639ULL: goto x86_l_27f;
	case 645ULL: goto x86_l_285;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 658ULL: goto x86_l_292;
	case 663ULL: goto x86_l_297;
	case 670ULL: goto x86_l_29e;
	case 674ULL: goto x86_l_2a2;
	case 682ULL: goto x86_l_2aa;
	case 689ULL: goto x86_l_2b1;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 701ULL: goto x86_l_2bd;
	case 704ULL: goto x86_l_2c0;
	case 710ULL: goto x86_l_2c6;
	case 713ULL: goto x86_l_2c9;
	case 717ULL: goto x86_l_2cd;
	case 721ULL: goto x86_l_2d1;
	case 732ULL: goto x86_l_2dc;
	case 743ULL: goto x86_l_2e7;
	case 754ULL: goto x86_l_2f2;
	case 765ULL: goto x86_l_2fd;
	case 776ULL: goto x86_l_308;
	case 787ULL: goto x86_l_313;
	case 798ULL: goto x86_l_31e;
	case 809ULL: goto x86_l_329;
	case 820ULL: goto x86_l_334;
	case 831ULL: goto x86_l_33f;
	case 842ULL: goto x86_l_34a;
	case 853ULL: goto x86_l_355;
	case 864ULL: goto x86_l_360;
	case 875ULL: goto x86_l_36b;
	case 886ULL: goto x86_l_376;
	case 897ULL: goto x86_l_381;
	case 908ULL: goto x86_l_38c;
	case 919ULL: goto x86_l_397;
	case 930ULL: goto x86_l_3a2;
	case 941ULL: goto x86_l_3ad;
	case 952ULL: goto x86_l_3b8;
	case 963ULL: goto x86_l_3c3;
	case 974ULL: goto x86_l_3ce;
	case 985ULL: goto x86_l_3d9;
	case 996ULL: goto x86_l_3e4;
	case 1007ULL: goto x86_l_3ef;
	case 1018ULL: goto x86_l_3fa;
	case 1029ULL: goto x86_l_405;
	case 1040ULL: goto x86_l_410;
	case 1051ULL: goto x86_l_41b;
	case 1059ULL: goto x86_l_423;
	case 1067ULL: goto x86_l_42b;
	case 1075ULL: goto x86_l_433;
	case 1083ULL: goto x86_l_43b;
	case 1091ULL: goto x86_l_443;
	case 1099ULL: goto x86_l_44b;
	case 1107ULL: goto x86_l_453;
	case 1115ULL: goto x86_l_45b;
	case 1123ULL: goto x86_l_463;
	case 1131ULL: goto x86_l_46b;
	case 1139ULL: goto x86_l_473;
	case 1147ULL: goto x86_l_47b;
	case 1155ULL: goto x86_l_483;
	case 1163ULL: goto x86_l_48b;
	case 1171ULL: goto x86_l_493;
	case 1178ULL: goto x86_l_49a;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1203ULL: goto x86_l_4b3;
	case 1205ULL: goto x86_l_4b5;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1218ULL: goto x86_l_4c2;
	case 1220ULL: goto x86_l_4c4;
	case 1228ULL: goto x86_l_4cc;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1249ULL: goto x86_l_4e1;
	case 1253ULL: goto x86_l_4e5;
	case 1261ULL: goto x86_l_4ed;
	case 1268ULL: goto x86_l_4f4;
	case 1273ULL: goto x86_l_4f9;
	case 1278ULL: goto x86_l_4fe;
	case 1284ULL: goto x86_l_504;
	case 1286ULL: goto x86_l_506;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1298ULL: goto x86_l_512;
	case 1302ULL: goto x86_l_516;
	case 1306ULL: goto x86_l_51a;
	case 1317ULL: goto x86_l_525;
	case 1328ULL: goto x86_l_530;
	case 1339ULL: goto x86_l_53b;
	case 1350ULL: goto x86_l_546;
	case 1361ULL: goto x86_l_551;
	case 1372ULL: goto x86_l_55c;
	case 1383ULL: goto x86_l_567;
	case 1394ULL: goto x86_l_572;
	case 1405ULL: goto x86_l_57d;
	case 1413ULL: goto x86_l_585;
	case 1421ULL: goto x86_l_58d;
	case 1429ULL: goto x86_l_595;
	case 1437ULL: goto x86_l_59d;
	case 1445ULL: goto x86_l_5a5;
	case 1453ULL: goto x86_l_5ad;
	case 1461ULL: goto x86_l_5b5;
	case 1469ULL: goto x86_l_5bd;
	case 1477ULL: goto x86_l_5c5;
	case 1485ULL: goto x86_l_5cd;
	case 1493ULL: goto x86_l_5d5;
	case 1501ULL: goto x86_l_5dd;
	case 1509ULL: goto x86_l_5e5;
	case 1517ULL: goto x86_l_5ed;
	case 1525ULL: goto x86_l_5f5;
	case 1532ULL: goto x86_l_5fc;
	case 1539ULL: goto x86_l_603;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1554ULL: goto x86_l_612;
	case 1557ULL: goto x86_l_615;
	case 1559ULL: goto x86_l_617;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1572ULL: goto x86_l_624;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1593ULL: goto x86_l_639;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1622ULL: goto x86_l_656;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1720ULL: goto x86_l_6b8;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1759ULL: goto x86_l_6df;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1781ULL: goto x86_l_6f5;
	case 1786ULL: goto x86_l_6fa;
	case 1789ULL: goto x86_l_6fd;
	case 1791ULL: goto x86_l_6ff;
	case 1795ULL: goto x86_l_703;
	case 1799ULL: goto x86_l_707;
	case 1803ULL: goto x86_l_70b;
	case 1807ULL: goto x86_l_70f;
	case 1812ULL: goto x86_l_714;
	case 1817ULL: goto x86_l_719;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1829ULL: goto x86_l_725;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1846ULL: goto x86_l_736;
	case 1851ULL: goto x86_l_73b;
	case 1856ULL: goto x86_l_740;
	case 1859ULL: goto x86_l_743;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1870ULL: goto x86_l_74e;
	case 1875ULL: goto x86_l_753;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1907ULL: goto x86_l_773;
	case 1912ULL: goto x86_l_778;
	case 1917ULL: goto x86_l_77d;
	case 1920ULL: goto x86_l_780;
	case 1922ULL: goto x86_l_782;
	case 1926ULL: goto x86_l_786;
	case 1930ULL: goto x86_l_78a;
	case 1934ULL: goto x86_l_78e;
	case 1938ULL: goto x86_l_792;
	case 1943ULL: goto x86_l_797;
	case 1948ULL: goto x86_l_79c;
	case 1953ULL: goto x86_l_7a1;
	case 1958ULL: goto x86_l_7a6;
	case 1960ULL: goto x86_l_7a8;
	case 1964ULL: goto x86_l_7ac;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1990ULL: goto x86_l_7c6;
	case 1992ULL: goto x86_l_7c8;
	case 1997ULL: goto x86_l_7cd;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2020ULL: goto x86_l_7e4;
	case 2022ULL: goto x86_l_7e6;
	case 2026ULL: goto x86_l_7ea;
	case 2030ULL: goto x86_l_7ee;
	case 2034ULL: goto x86_l_7f2;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2048ULL: goto x86_l_800;
	case 2053ULL: goto x86_l_805;
	case 2058ULL: goto x86_l_80a;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2069ULL: goto x86_l_815;
	case 2074ULL: goto x86_l_81a;
	case 2079ULL: goto x86_l_81f;
	case 2084ULL: goto x86_l_824;
	case 2089ULL: goto x86_l_829;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2105ULL: goto x86_l_839;
	case 2110ULL: goto x86_l_83e;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2128ULL: goto x86_l_850;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2140ULL: goto x86_l_85c;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_19:
	/* 0x19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b:
	/* 0x1b: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c:
	/* 0x2c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31:
	/* 0x31: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_36:
	/* 0x36: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3b:
	/* 0x3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_40:
	/* 0x40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42:
	/* 0x42: test   DWORD PTR [rsp+0x10],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68721573888ULL);
x86_l_4a:
	/* 0x4a: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_4f:
	/* 0x4f: jne    b7 <trace_ret_arch_prctl+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b7;
	}
x86_l_51:
	/* 0x51: mov    eax,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 158ULL);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_5b:
	/* 0x5b: mov    eax,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 175ULL);
x86_l_60:
	/* 0x60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62:
	/* 0x62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65:
	/* 0x65: je     6c <trace_ret_arch_prctl+0x6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c;
	}
x86_l_67:
	/* 0x67: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6a:
	/* 0x6a: jmp    6c <trace_ret_arch_prctl+0x6c> */
	goto x86_l_6c;
x86_l_6c:
	/* 0x6c: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_70:
	/* 0x70: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75:
	/* 0x75: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7a:
	/* 0x7a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f:
	/* 0x7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_84:
	/* 0x84: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_87:
	/* 0x87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89:
	/* 0x89: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_8e:
	/* 0x8e: jne    96 <trace_ret_arch_prctl+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_96;
	}
x86_l_90:
	/* 0x90: mov    ebp,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_94:
	/* 0x94: jmp    b7 <trace_ret_arch_prctl+0xb7> */
	goto x86_l_b7;
x86_l_96:
	/* 0x96: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_9d:
	/* 0x9d: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a2:
	/* 0xa2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a7:
	/* 0xa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9:
	/* 0xa9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ac:
	/* 0xac: je     b2 <trace_ret_arch_prctl+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2;
	}
x86_l_ae:
	/* 0xae: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b0:
	/* 0xb0: jmp    b7 <trace_ret_arch_prctl+0xb7> */
	goto x86_l_b7;
x86_l_b2:
	/* 0xb2: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_c2:
	/* 0xc2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c9:
	/* 0xc9: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_d1:
	/* 0xd1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d6:
	/* 0xd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8:
	/* 0xd8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: je     26ea <trace_ret_arch_prctl+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9962ULL;
	}
x86_l_e1:
	/* 0xe1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_e4:
	/* 0xe4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_eb:
	/* 0xeb: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_f3:
	/* 0xf3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f8:
	/* 0xf8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa:
	/* 0xfa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd:
	/* 0xfd: je     26ea <trace_ret_arch_prctl+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9962ULL;
	}
x86_l_103:
	/* 0x103: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_106:
	/* 0x106: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_110:
	/* 0x110: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_118:
	/* 0x118: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_123:
	/* 0x123: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_12e:
	/* 0x12e: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_139:
	/* 0x139: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_144:
	/* 0x144: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_14f:
	/* 0x14f: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_15a:
	/* 0x15a: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_165:
	/* 0x165: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_177:
	/* 0x177: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_17f:
	/* 0x17f: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_187:
	/* 0x187: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_197:
	/* 0x197: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19f:
	/* 0x19f: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1a7:
	/* 0x1a7: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1af:
	/* 0x1af: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1c7:
	/* 0x1c7: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1cf:
	/* 0x1cf: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1d7:
	/* 0x1d7: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1df:
	/* 0x1df: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1e4:
	/* 0x1e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6:
	/* 0x1e6: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ea:
	/* 0x1ea: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ee:
	/* 0x1ee: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f2:
	/* 0x1f2: mov    DWORD PTR [r14+0x70],0x9e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337310ULL);
x86_l_1fa:
	/* 0x1fa: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1ff:
	/* 0x1ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201:
	/* 0x201: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_204:
	/* 0x204: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_209:
	/* 0x209: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b:
	/* 0x20b: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_210:
	/* 0x210: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_214:
	/* 0x214: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_218:
	/* 0x218: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_21f:
	/* 0x21f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_226:
	/* 0x226: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22e:
	/* 0x22e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_233:
	/* 0x233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235:
	/* 0x235: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_23d:
	/* 0x23d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: je     297 <trace_ret_arch_prctl+0x297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_297;
	}
x86_l_242:
	/* 0x242: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_246:
	/* 0x246: mov    DWORD PTR [rsp+0x94],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_24d:
	/* 0x24d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_254:
	/* 0x254: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_25c:
	/* 0x25c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_261:
	/* 0x261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263:
	/* 0x263: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_266:
	/* 0x266: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_269:
	/* 0x269: mov    QWORD PTR [rsp+0xa0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_271:
	/* 0x271: mov    QWORD PTR [rsp+0xb0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_279:
	/* 0x279: je     4da <trace_ret_arch_prctl+0x4da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4da;
	}
x86_l_27f:
	/* 0x27f: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_285:
	/* 0x285: jne    ade <trace_ret_arch_prctl+0xade> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2782ULL;
	}
x86_l_28b:
	/* 0x28b: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_290:
	/* 0x290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292:
	/* 0x292: jmp    b88 <trace_ret_arch_prctl+0xb88> */
	return 2952ULL;
x86_l_297:
	/* 0x297: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_29e:
	/* 0x29e: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2a2:
	/* 0x2a2: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2aa:
	/* 0x2aa: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_2b1:
	/* 0x2b1: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2b6:
	/* 0x2b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bb:
	/* 0x2bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd:
	/* 0x2bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c0:
	/* 0x2c0: je     26ea <trace_ret_arch_prctl+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9962ULL;
	}
x86_l_2c6:
	/* 0x2c6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2c9:
	/* 0x2c9: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2cd:
	/* 0x2cd: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d1:
	/* 0x2d1: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2dc:
	/* 0x2dc: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2e7:
	/* 0x2e7: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2f2:
	/* 0x2f2: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2fd:
	/* 0x2fd: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_308:
	/* 0x308: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_313:
	/* 0x313: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_31e:
	/* 0x31e: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_329:
	/* 0x329: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_334:
	/* 0x334: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_33f:
	/* 0x33f: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_34a:
	/* 0x34a: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_355:
	/* 0x355: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_360:
	/* 0x360: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_376:
	/* 0x376: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_381:
	/* 0x381: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_38c:
	/* 0x38c: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_397:
	/* 0x397: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3a2:
	/* 0x3a2: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_3ad:
	/* 0x3ad: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_3b8:
	/* 0x3b8: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3c3:
	/* 0x3c3: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3ce:
	/* 0x3ce: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3d9:
	/* 0x3d9: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3e4:
	/* 0x3e4: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3ef:
	/* 0x3ef: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3fa:
	/* 0x3fa: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_405:
	/* 0x405: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_410:
	/* 0x410: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_42b:
	/* 0x42b: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_43b:
	/* 0x43b: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_443:
	/* 0x443: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_44b:
	/* 0x44b: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_453:
	/* 0x453: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_473:
	/* 0x473: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_483:
	/* 0x483: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_48b:
	/* 0x48b: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_493:
	/* 0x493: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49a:
	/* 0x49a: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_4a1:
	/* 0x4a1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a6:
	/* 0x4a6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ab:
	/* 0x4ab: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4b0:
	/* 0x4b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5:
	/* 0x4b5: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4ba:
	/* 0x4ba: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bf:
	/* 0x4bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4c2:
	/* 0x4c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c4:
	/* 0x4c4: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4cc:
	/* 0x4cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4cf:
	/* 0x4cf: jne    242 <trace_ret_arch_prctl+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_242;
	}
x86_l_4d5:
	/* 0x4d5: jmp    26ea <trace_ret_arch_prctl+0x26ea> */
	return 9962ULL;
x86_l_4da:
	/* 0x4da: mov    eax,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_4e1:
	/* 0x4e1: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e5:
	/* 0x4e5: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4ed:
	/* 0x4ed: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4f4:
	/* 0x4f4: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4f9:
	/* 0x4f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4fe:
	/* 0x4fe: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_504:
	/* 0x504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_506:
	/* 0x506: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_509:
	/* 0x509: je     26ea <trace_ret_arch_prctl+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9962ULL;
	}
x86_l_50f:
	/* 0x50f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_512:
	/* 0x512: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_516:
	/* 0x516: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51a:
	/* 0x51a: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_525:
	/* 0x525: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_530:
	/* 0x530: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_53b:
	/* 0x53b: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_546:
	/* 0x546: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_551:
	/* 0x551: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_55c:
	/* 0x55c: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_572:
	/* 0x572: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_585:
	/* 0x585: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_58d:
	/* 0x58d: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_595:
	/* 0x595: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5a5:
	/* 0x5a5: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5ad:
	/* 0x5ad: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5b5:
	/* 0x5b5: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5c5:
	/* 0x5c5: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5cd:
	/* 0x5cd: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5dd:
	/* 0x5dd: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5e5:
	/* 0x5e5: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5ed:
	/* 0x5ed: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fc:
	/* 0x5fc: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_603:
	/* 0x603: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_608:
	/* 0x608: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_60d:
	/* 0x60d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_612:
	/* 0x612: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_615:
	/* 0x615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_617:
	/* 0x617: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_61c:
	/* 0x61c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_621:
	/* 0x621: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_624:
	/* 0x624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_626:
	/* 0x626: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_629:
	/* 0x629: je     26ea <trace_ret_arch_prctl+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9962ULL;
	}
x86_l_62f:
	/* 0x62f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_632:
	/* 0x632: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_639:
	/* 0x639: lea    r15,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_63d:
	/* 0x63d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_642:
	/* 0x642: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_647:
	/* 0x647: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64c:
	/* 0x64c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_651:
	/* 0x651: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_654:
	/* 0x654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_656:
	/* 0x656: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_65b:
	/* 0x65b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_660:
	/* 0x660: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_664:
	/* 0x664: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_669:
	/* 0x669: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66e:
	/* 0x66e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_673:
	/* 0x673: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_678:
	/* 0x678: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67a:
	/* 0x67a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_67f:
	/* 0x67f: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_683:
	/* 0x683: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_688:
	/* 0x688: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_68d:
	/* 0x68d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_692:
	/* 0x692: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_697:
	/* 0x697: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_699:
	/* 0x699: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69e:
	/* 0x69e: lea    rdx,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6a2:
	/* 0x6a2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a7:
	/* 0x6a7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6ac:
	/* 0x6ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b1:
	/* 0x6b1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6b6:
	/* 0x6b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b8:
	/* 0x6b8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6bc:
	/* 0x6bc: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6bf:
	/* 0x6bf: mov    QWORD PTR [rsp+0x68],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6c4:
	/* 0x6c4: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6c8:
	/* 0x6c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6cd:
	/* 0x6cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6d2:
	/* 0x6d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d7:
	/* 0x6d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6dc:
	/* 0x6dc: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6df:
	/* 0x6df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e1:
	/* 0x6e1: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e6:
	/* 0x6e6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6eb:
	/* 0x6eb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6f0:
	/* 0x6f0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6f5:
	/* 0x6f5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6fa:
	/* 0x6fa: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6fd:
	/* 0x6fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ff:
	/* 0x6ff: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_703:
	/* 0x703: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_707:
	/* 0x707: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_70b:
	/* 0x70b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_70f:
	/* 0x70f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_714:
	/* 0x714: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_719:
	/* 0x719: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_71e:
	/* 0x71e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_723:
	/* 0x723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_725:
	/* 0x725: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_729:
	/* 0x729: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_72c:
	/* 0x72c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_731:
	/* 0x731: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_736:
	/* 0x736: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_73b:
	/* 0x73b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_740:
	/* 0x740: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_743:
	/* 0x743: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_745:
	/* 0x745: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_74a:
	/* 0x74a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_74e:
	/* 0x74e: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x764: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_769:
	/* 0x769: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x77d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_780:
	/* 0x780: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_782:
	/* 0x782: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_786:
	/* 0x786: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_78a:
	/* 0x78a: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_78e:
	/* 0x78e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_792:
	/* 0x792: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_797:
	/* 0x797: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_79c:
	/* 0x79c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7a1:
	/* 0x7a1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7a6:
	/* 0x7a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a8:
	/* 0x7a8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ac:
	/* 0x7ac: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7af:
	/* 0x7af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b4:
	/* 0x7b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b9:
	/* 0x7b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7be:
	/* 0x7be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7c3:
	/* 0x7c3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c8:
	/* 0x7c8: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7cd:
	/* 0x7cd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d2:
	/* 0x7d2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7d7:
	/* 0x7d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7dc:
	/* 0x7dc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7e1:
	/* 0x7e1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ea:
	/* 0x7ea: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7ee:
	/* 0x7ee: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7f2:
	/* 0x7f2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7f6:
	/* 0x7f6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fb:
	/* 0x7fb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_800:
	/* 0x800: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_805:
	/* 0x805: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_80a:
	/* 0x80a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80c:
	/* 0x80c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_811:
	/* 0x811: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_815:
	/* 0x815: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_81a:
	/* 0x81a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_81f:
	/* 0x81f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_824:
	/* 0x824: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_829:
	/* 0x829: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82b:
	/* 0x82b: mov    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_830:
	/* 0x830: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_835:
	/* 0x835: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_839:
	/* 0x839: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83e:
	/* 0x83e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_843:
	/* 0x843: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_848:
	/* 0x848: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_84d:
	/* 0x84d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_850:
	/* 0x850: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_852:
	/* 0x852: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_857:
	/* 0x857: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_85c:
	/* 0x85c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_861:
	/* 0x861: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_866:
	/* 0x866: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 2155ULL;
}

static __noinline __u64 tracee_trace_ret_arch_prctl_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
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
	case 2196ULL: goto x86_l_894;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2229ULL: goto x86_l_8b5;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2241ULL: goto x86_l_8c1;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2259ULL: goto x86_l_8d3;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2276ULL: goto x86_l_8e4;
	case 2281ULL: goto x86_l_8e9;
	case 2286ULL: goto x86_l_8ee;
	case 2289ULL: goto x86_l_8f1;
	case 2291ULL: goto x86_l_8f3;
	case 2295ULL: goto x86_l_8f7;
	case 2299ULL: goto x86_l_8fb;
	case 2303ULL: goto x86_l_8ff;
	case 2307ULL: goto x86_l_903;
	case 2312ULL: goto x86_l_908;
	case 2317ULL: goto x86_l_90d;
	case 2322ULL: goto x86_l_912;
	case 2327ULL: goto x86_l_917;
	case 2329ULL: goto x86_l_919;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2352ULL: goto x86_l_930;
	case 2357ULL: goto x86_l_935;
	case 2362ULL: goto x86_l_93a;
	case 2367ULL: goto x86_l_93f;
	case 2372ULL: goto x86_l_944;
	case 2375ULL: goto x86_l_947;
	case 2377ULL: goto x86_l_949;
	case 2382ULL: goto x86_l_94e;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2408ULL: goto x86_l_968;
	case 2413ULL: goto x86_l_96d;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2433ULL: goto x86_l_981;
	case 2438ULL: goto x86_l_986;
	case 2440ULL: goto x86_l_988;
	case 2444ULL: goto x86_l_98c;
	case 2447ULL: goto x86_l_98f;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2457ULL: goto x86_l_999;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2521ULL: goto x86_l_9d9;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2532ULL: goto x86_l_9e4;
	case 2537ULL: goto x86_l_9e9;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2551ULL: goto x86_l_9f7;
	case 2556ULL: goto x86_l_9fc;
	case 2561ULL: goto x86_l_a01;
	case 2563ULL: goto x86_l_a03;
	case 2568ULL: goto x86_l_a08;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2582ULL: goto x86_l_a16;
	case 2587ULL: goto x86_l_a1b;
	case 2592ULL: goto x86_l_a20;
	case 2595ULL: goto x86_l_a23;
	case 2597ULL: goto x86_l_a25;
	case 2602ULL: goto x86_l_a2a;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2616ULL: goto x86_l_a38;
	case 2624ULL: goto x86_l_a40;
	case 2628ULL: goto x86_l_a44;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2653ULL: goto x86_l_a5d;
	case 2658ULL: goto x86_l_a62;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2678ULL: goto x86_l_a76;
	case 2683ULL: goto x86_l_a7b;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2705ULL: goto x86_l_a91;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2725ULL: goto x86_l_aa5;
	case 2728ULL: goto x86_l_aa8;
	case 2733ULL: goto x86_l_aad;
	case 2735ULL: goto x86_l_aaf;
	case 2738ULL: goto x86_l_ab2;
	case 2742ULL: goto x86_l_ab6;
	case 2747ULL: goto x86_l_abb;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2760ULL: goto x86_l_ac8;
	case 2762ULL: goto x86_l_aca;
	case 2770ULL: goto x86_l_ad2;
	case 2776ULL: goto x86_l_ad8;
	case 2782ULL: goto x86_l_ade;
	case 2787ULL: goto x86_l_ae3;
	case 2794ULL: goto x86_l_aea;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2858ULL: goto x86_l_b2a;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2890ULL: goto x86_l_b4a;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2905ULL: goto x86_l_b59;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2915ULL: goto x86_l_b63;
	case 2917ULL: goto x86_l_b65;
	case 2921ULL: goto x86_l_b69;
	case 2926ULL: goto x86_l_b6e;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2941ULL: goto x86_l_b7d;
	case 2943ULL: goto x86_l_b7f;
	case 2948ULL: goto x86_l_b84;
	case 2950ULL: goto x86_l_b86;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2971ULL: goto x86_l_b9b;
	case 2976ULL: goto x86_l_ba0;
	case 2981ULL: goto x86_l_ba5;
	case 2983ULL: goto x86_l_ba7;
	case 2986ULL: goto x86_l_baa;
	case 2988ULL: goto x86_l_bac;
	case 2991ULL: goto x86_l_baf;
	case 2997ULL: goto x86_l_bb5;
	case 3000ULL: goto x86_l_bb8;
	case 3003ULL: goto x86_l_bbb;
	case 3005ULL: goto x86_l_bbd;
	case 3010ULL: goto x86_l_bc2;
	case 3015ULL: goto x86_l_bc7;
	case 3021ULL: goto x86_l_bcd;
	case 3027ULL: goto x86_l_bd3;
	case 3038ULL: goto x86_l_bde;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3058ULL: goto x86_l_bf2;
	case 3063ULL: goto x86_l_bf7;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3073ULL: goto x86_l_c01;
	case 3075ULL: goto x86_l_c03;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3088ULL: goto x86_l_c10;
	case 3090ULL: goto x86_l_c12;
	case 3093ULL: goto x86_l_c15;
	case 3095ULL: goto x86_l_c17;
	case 3099ULL: goto x86_l_c1b;
	case 3106ULL: goto x86_l_c22;
	case 3109ULL: goto x86_l_c25;
	case 3116ULL: goto x86_l_c2c;
	case 3120ULL: goto x86_l_c30;
	case 3124ULL: goto x86_l_c34;
	case 3131ULL: goto x86_l_c3b;
	case 3138ULL: goto x86_l_c42;
	case 3142ULL: goto x86_l_c46;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3160ULL: goto x86_l_c58;
	case 3164ULL: goto x86_l_c5c;
	case 3171ULL: goto x86_l_c63;
	case 3175ULL: goto x86_l_c67;
	case 3182ULL: goto x86_l_c6e;
	case 3189ULL: goto x86_l_c75;
	case 3196ULL: goto x86_l_c7c;
	case 3203ULL: goto x86_l_c83;
	case 3207ULL: goto x86_l_c87;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3218ULL: goto x86_l_c92;
	case 3221ULL: goto x86_l_c95;
	case 3224ULL: goto x86_l_c98;
	case 3231ULL: goto x86_l_c9f;
	case 3237ULL: goto x86_l_ca5;
	case 3242ULL: goto x86_l_caa;
	case 3249ULL: goto x86_l_cb1;
	case 3252ULL: goto x86_l_cb4;
	case 3258ULL: goto x86_l_cba;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3271ULL: goto x86_l_cc7;
	case 3274ULL: goto x86_l_cca;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3291ULL: goto x86_l_cdb;
	case 3294ULL: goto x86_l_cde;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3306ULL: goto x86_l_cea;
	case 3308ULL: goto x86_l_cec;
	case 3315ULL: goto x86_l_cf3;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3324ULL: goto x86_l_cfc;
	case 3331ULL: goto x86_l_d03;
	case 3334ULL: goto x86_l_d06;
	case 3337ULL: goto x86_l_d09;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3349ULL: goto x86_l_d15;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3369ULL: goto x86_l_d29;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3382ULL: goto x86_l_d36;
	case 3385ULL: goto x86_l_d39;
	case 3387ULL: goto x86_l_d3b;
	case 3390ULL: goto x86_l_d3e;
	case 3398ULL: goto x86_l_d46;
	case 3402ULL: goto x86_l_d4a;
	case 3405ULL: goto x86_l_d4d;
	case 3412ULL: goto x86_l_d54;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3430ULL: goto x86_l_d66;
	case 3433ULL: goto x86_l_d69;
	case 3438ULL: goto x86_l_d6e;
	case 3444ULL: goto x86_l_d74;
	case 3451ULL: goto x86_l_d7b;
	case 3459ULL: goto x86_l_d83;
	case 3466ULL: goto x86_l_d8a;
	case 3471ULL: goto x86_l_d8f;
	case 3478ULL: goto x86_l_d96;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3508ULL: goto x86_l_db4;
	case 3510ULL: goto x86_l_db6;
	case 3513ULL: goto x86_l_db9;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3529ULL: goto x86_l_dc9;
	case 3532ULL: goto x86_l_dcc;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3552ULL: goto x86_l_de0;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3566ULL: goto x86_l_dee;
	case 3569ULL: goto x86_l_df1;
	case 3577ULL: goto x86_l_df9;
	case 3582ULL: goto x86_l_dfe;
	case 3587ULL: goto x86_l_e03;
	case 3590ULL: goto x86_l_e06;
	case 3593ULL: goto x86_l_e09;
	case 3595ULL: goto x86_l_e0b;
	case 3599ULL: goto x86_l_e0f;
	case 3601ULL: goto x86_l_e11;
	case 3604ULL: goto x86_l_e14;
	case 3606ULL: goto x86_l_e16;
	case 3614ULL: goto x86_l_e1e;
	case 3617ULL: goto x86_l_e21;
	case 3621ULL: goto x86_l_e25;
	case 3626ULL: goto x86_l_e2a;
	case 3633ULL: goto x86_l_e31;
	case 3636ULL: goto x86_l_e34;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3656ULL: goto x86_l_e48;
	case 3658ULL: goto x86_l_e4a;
	case 3661ULL: goto x86_l_e4d;
	case 3663ULL: goto x86_l_e4f;
	case 3666ULL: goto x86_l_e52;
	case 3670ULL: goto x86_l_e56;
	case 3673ULL: goto x86_l_e59;
	case 3675ULL: goto x86_l_e5b;
	case 3682ULL: goto x86_l_e62;
	case 3689ULL: goto x86_l_e69;
	case 3692ULL: goto x86_l_e6c;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3722ULL: goto x86_l_e8a;
	case 3730ULL: goto x86_l_e92;
	case 3735ULL: goto x86_l_e97;
	case 3738ULL: goto x86_l_e9a;
	case 3743ULL: goto x86_l_e9f;
	case 3746ULL: goto x86_l_ea2;
	case 3748ULL: goto x86_l_ea4;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3767ULL: goto x86_l_eb7;
	case 3770ULL: goto x86_l_eba;
	case 3773ULL: goto x86_l_ebd;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3784ULL: goto x86_l_ec8;
	case 3792ULL: goto x86_l_ed0;
	case 3798ULL: goto x86_l_ed6;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3815ULL: goto x86_l_ee7;
	case 3822ULL: goto x86_l_eee;
	default: return 0xffffffffffffffffULL;
	}
x86_l_86b:
	/* 0x86b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_870:
	/* 0x870: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_874:
	/* 0x874: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_878:
	/* 0x878: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_87c:
	/* 0x87c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_880:
	/* 0x880: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_885:
	/* 0x885: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_88a:
	/* 0x88a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_88f:
	/* 0x88f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_894:
	/* 0x894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_896:
	/* 0x896: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89b:
	/* 0x89b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_89f:
	/* 0x89f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8a4:
	/* 0x8a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8a9:
	/* 0x8a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8ae:
	/* 0x8ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8b3:
	/* 0x8b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b5:
	/* 0x8b5: cmp    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_8ba:
	/* 0x8ba: jne    920 <trace_ret_arch_prctl+0x920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_920;
	}
x86_l_8bc:
	/* 0x8bc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c1:
	/* 0x8c1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8c6:
	/* 0x8c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8cb:
	/* 0x8cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d0:
	/* 0x8d0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8d3:
	/* 0x8d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d5:
	/* 0x8d5: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8da:
	/* 0x8da: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8df:
	/* 0x8df: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8e4:
	/* 0x8e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8e9:
	/* 0x8e9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8ee:
	/* 0x8ee: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_8f1:
	/* 0x8f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f3:
	/* 0x8f3: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f7:
	/* 0x8f7: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8fb:
	/* 0x8fb: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8ff:
	/* 0x8ff: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_903:
	/* 0x903: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_908:
	/* 0x908: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_90d:
	/* 0x90d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_912:
	/* 0x912: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_917:
	/* 0x917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_919:
	/* 0x919: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_91d:
	/* 0x91d: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_920:
	/* 0x920: mov    DWORD PTR [rbp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_924:
	/* 0x924: mov    rbx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_929:
	/* 0x929: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_930:
	/* 0x930: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_935:
	/* 0x935: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_93a:
	/* 0x93a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_93f:
	/* 0x93f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_944:
	/* 0x944: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_947:
	/* 0x947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_949:
	/* 0x949: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_94e:
	/* 0x94e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_952:
	/* 0x952: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x966: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_968:
	/* 0x968: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96d:
	/* 0x96d: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_972:
	/* 0x972: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_977:
	/* 0x977: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_97c:
	/* 0x97c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_981:
	/* 0x981: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_986:
	/* 0x986: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_988:
	/* 0x988: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_98c:
	/* 0x98c: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_98f:
	/* 0x98f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_994:
	/* 0x994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_996:
	/* 0x996: mov    DWORD PTR [rbp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_999:
	/* 0x999: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_99d:
	/* 0x99d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9a2:
	/* 0x9a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9a7:
	/* 0x9a7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9ac:
	/* 0x9ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9b1:
	/* 0x9b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b3:
	/* 0x9b3: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b8:
	/* 0x9b8: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9bc:
	/* 0x9bc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c1:
	/* 0x9c1: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9c5:
	/* 0x9c5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ca:
	/* 0x9ca: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9cf:
	/* 0x9cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9d4:
	/* 0x9d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9d9:
	/* 0x9d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9db:
	/* 0x9db: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e0:
	/* 0x9e0: mov    QWORD PTR [rbp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9e4:
	/* 0x9e4: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9e9:
	/* 0x9e9: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9ed:
	/* 0x9ed: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9f2:
	/* 0x9f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9f7:
	/* 0x9f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9fc:
	/* 0x9fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a01:
	/* 0xa01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a03:
	/* 0xa03: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a08:
	/* 0xa08: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a0c:
	/* 0xa0c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a11:
	/* 0xa11: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a16:
	/* 0xa16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a1b:
	/* 0xa1b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a20:
	/* 0xa20: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a23:
	/* 0xa23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a25:
	/* 0xa25: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_a2a:
	/* 0xa2a: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a32:
	/* 0xa32: je     a38 <trace_ret_arch_prctl+0xa38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a38;
	}
x86_l_a34:
	/* 0xa34: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a38:
	/* 0xa38: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a40:
	/* 0xa40: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a44:
	/* 0xa44: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a4c:
	/* 0xa4c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a51:
	/* 0xa51: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a56:
	/* 0xa56: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a5b:
	/* 0xa5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5d:
	/* 0xa5d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a62:
	/* 0xa62: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a67:
	/* 0xa67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a6c:
	/* 0xa6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a71:
	/* 0xa71: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a74:
	/* 0xa74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a76:
	/* 0xa76: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7b:
	/* 0xa7b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a80:
	/* 0xa80: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a85:
	/* 0xa85: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a8a:
	/* 0xa8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a8f:
	/* 0xa8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a91:
	/* 0xa91: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a96:
	/* 0xa96: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9b:
	/* 0xa9b: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_aa0:
	/* 0xaa0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aa5:
	/* 0xaa5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa8:
	/* 0xaa8: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_aad:
	/* 0xaad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aaf:
	/* 0xaaf: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ab2:
	/* 0xab2: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_ab6:
	/* 0xab6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_abb:
	/* 0xabb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_ac0:
	/* 0xac0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ac5:
	/* 0xac5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_ac8:
	/* 0xac8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aca:
	/* 0xaca: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ad2:
	/* 0xad2: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_ad8:
	/* 0xad8: je     28b <trace_ret_arch_prctl+0x28b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 651ULL;
	}
x86_l_ade:
	/* 0xade: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_ae3:
	/* 0xae3: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_aea:
	/* 0xaea: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_aef:
	/* 0xaef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_af4:
	/* 0xaf4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_af9:
	/* 0xaf9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_afe:
	/* 0xafe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b00:
	/* 0xb00: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b05:
	/* 0xb05: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b0a:
	/* 0xb0a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b0f:
	/* 0xb0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b14:
	/* 0xb14: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b19:
	/* 0xb19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b1e:
	/* 0xb1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b20:
	/* 0xb20: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b25:
	/* 0xb25: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b2a:
	/* 0xb2a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b2f:
	/* 0xb2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b34:
	/* 0xb34: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b39:
	/* 0xb39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b3e:
	/* 0xb3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b40:
	/* 0xb40: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b45:
	/* 0xb45: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4a:
	/* 0xb4a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b4f:
	/* 0xb4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b54:
	/* 0xb54: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b59:
	/* 0xb59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5b:
	/* 0xb5b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b60:
	/* 0xb60: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_b63:
	/* 0xb63: je     b86 <trace_ret_arch_prctl+0xb86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b86;
	}
x86_l_b65:
	/* 0xb65: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b69:
	/* 0xb69: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6e:
	/* 0xb6e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b73:
	/* 0xb73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b78:
	/* 0xb78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b7d:
	/* 0xb7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7f:
	/* 0xb7f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b84:
	/* 0xb84: jmp    b88 <trace_ret_arch_prctl+0xb88> */
	goto x86_l_b88;
x86_l_b86:
	/* 0xb86: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b88:
	/* 0xb88: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b8c:
	/* 0xb8c: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b90:
	/* 0xb90: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b94:
	/* 0xb94: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b9b:
	/* 0xb9b: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ba0:
	/* 0xba0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba5:
	/* 0xba5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba7:
	/* 0xba7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_baa:
	/* 0xbaa: je     bc2 <trace_ret_arch_prctl+0xbc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc2;
	}
x86_l_bac:
	/* 0xbac: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_baf:
	/* 0xbaf: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_bb5:
	/* 0xbb5: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_bb8:
	/* 0xbb8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_bbb:
	/* 0xbbb: jne    bc2 <trace_ret_arch_prctl+0xbc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bc2;
	}
x86_l_bbd:
	/* 0xbbd: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_bc2:
	/* 0xbc2: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_bc7:
	/* 0xbc7: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_bcd:
	/* 0xbcd: jne    2702 <trace_ret_arch_prctl+0x2702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9986ULL;
	}
x86_l_bd3:
	/* 0xbd3: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_bde:
	/* 0xbde: mov    DWORD PTR [rsp+0x10],0x9e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476894ULL);
x86_l_be6:
	/* 0xbe6: mov    WORD PTR [rsp+0x78],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_beb:
	/* 0xbeb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_bf2:
	/* 0xbf2: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bf7:
	/* 0xbf7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bfc:
	/* 0xbfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfe:
	/* 0xbfe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c01:
	/* 0xc01: je     c6e <trace_ret_arch_prctl+0xc6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c6e;
	}
x86_l_c03:
	/* 0xc03: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_c06:
	/* 0xc06: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c0b:
	/* 0xc0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c10:
	/* 0xc10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c12:
	/* 0xc12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c15:
	/* 0xc15: je     c6e <trace_ret_arch_prctl+0xc6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c6e;
	}
x86_l_c17:
	/* 0xc17: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c1b:
	/* 0xc1b: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c22:
	/* 0xc22: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c25:
	/* 0xc25: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c2c:
	/* 0xc2c: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c30:
	/* 0xc30: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c34:
	/* 0xc34: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_c3b:
	/* 0xc3b: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_c42:
	/* 0xc42: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c46:
	/* 0xc46: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_c4d:
	/* 0xc4d: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c51:
	/* 0xc51: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_c58:
	/* 0xc58: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c5c:
	/* 0xc5c: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_c63:
	/* 0xc63: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c67:
	/* 0xc67: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_c6e:
	/* 0xc6e: mov    rax,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c75:
	/* 0xc75: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c7c:
	/* 0xc7c: mov    BYTE PTR [rbp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_c83:
	/* 0xc83: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c87:
	/* 0xc87: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_c8b:
	/* 0xc8b: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c90:
	/* 0xc90: jne    caa <trace_ret_arch_prctl+0xcaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_caa;
	}
x86_l_c92:
	/* 0xc92: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c95:
	/* 0xc95: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_c98:
	/* 0xc98: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c9f:
	/* 0xc9f: jne    14a9 <trace_ret_arch_prctl+0x14a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5289ULL;
	}
x86_l_ca5:
	/* 0xca5: jmp    26cf <trace_ret_arch_prctl+0x26cf> */
	return 9935ULL;
x86_l_caa:
	/* 0xcaa: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_cb1:
	/* 0xcb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cb4:
	/* 0xcb4: je     e5b <trace_ret_arch_prctl+0xe5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5b;
	}
x86_l_cba:
	/* 0xcba: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_cc1:
	/* 0xcc1: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_cc4:
	/* 0xcc4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc7:
	/* 0xcc7: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_cca:
	/* 0xcca: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_cce:
	/* 0xcce: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cd1:
	/* 0xcd1: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cd4:
	/* 0xcd4: xor    r12,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_cdb:
	/* 0xcdb: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cde:
	/* 0xcde: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ce5:
	/* 0xce5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce8:
	/* 0xce8: je     d09 <trace_ret_arch_prctl+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d09;
	}
x86_l_cea:
	/* 0xcea: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cec:
	/* 0xcec: cmp    BYTE PTR [rbp+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_cf3:
	/* 0xcf3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_cf6:
	/* 0xcf6: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cf9:
	/* 0xcf9: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_cfc:
	/* 0xcfc: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_d03:
	/* 0xd03: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d06:
	/* 0xd06: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d09:
	/* 0xd09: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_d10:
	/* 0xd10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d13:
	/* 0xd13: je     d2f <trace_ret_arch_prctl+0xd2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2f;
	}
x86_l_d15:
	/* 0xd15: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_d19:
	/* 0xd19: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d1c:
	/* 0xd1c: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_d1f:
	/* 0xd1f: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d22:
	/* 0xd22: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_d29:
	/* 0xd29: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d2c:
	/* 0xd2c: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d2f:
	/* 0xd2f: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_d36:
	/* 0xd36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d39:
	/* 0xd39: je     d5a <trace_ret_arch_prctl+0xd5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d5a;
	}
x86_l_d3b:
	/* 0xd3b: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d3e:
	/* 0xd3e: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d46:
	/* 0xd46: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d4a:
	/* 0xd4a: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_d4d:
	/* 0xd4d: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_d54:
	/* 0xd54: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d57:
	/* 0xd57: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_d5a:
	/* 0xd5a: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_d5f:
	/* 0xd5f: mov    r15,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_d66:
	/* 0xd66: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_d69:
	/* 0xd69: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d6e:
	/* 0xd6e: je     ec8 <trace_ret_arch_prctl+0xec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec8;
	}
x86_l_d74:
	/* 0xd74: mov    rcx,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_d7b:
	/* 0xd7b: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d83:
	/* 0xd83: mov    rcx,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_d8a:
	/* 0xd8a: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d8f:
	/* 0xd8f: mov    rcx,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_d96:
	/* 0xd96: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d9e:
	/* 0xd9e: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_da3:
	/* 0xda3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_daa:
	/* 0xdaa: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_daf:
	/* 0xdaf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db4:
	/* 0xdb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db6:
	/* 0xdb6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_db9:
	/* 0xdb9: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dbd:
	/* 0xdbd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc2:
	/* 0xdc2: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_dc9:
	/* 0xdc9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_dcc:
	/* 0xdcc: je     dee <trace_ret_arch_prctl+0xdee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dee;
	}
x86_l_dce:
	/* 0xdce: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd3:
	/* 0xdd3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd8:
	/* 0xdd8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ddb:
	/* 0xddb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ddd:
	/* 0xddd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_de0:
	/* 0xde0: je     dee <trace_ret_arch_prctl+0xdee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dee;
	}
x86_l_de2:
	/* 0xde2: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de5:
	/* 0xde5: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de9:
	/* 0xde9: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_dec:
	/* 0xdec: jmp    df1 <trace_ret_arch_prctl+0xdf1> */
	goto x86_l_df1;
x86_l_dee:
	/* 0xdee: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df1:
	/* 0xdf1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_df9:
	/* 0xdf9: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dfe:
	/* 0xdfe: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e03:
	/* 0xe03: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e06:
	/* 0xe06: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e09:
	/* 0xe09: jb     e21 <trace_ret_arch_prctl+0xe21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e21;
	}
x86_l_e0b:
	/* 0xe0b: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e0f:
	/* 0xe0f: je     e16 <trace_ret_arch_prctl+0xe16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e16;
	}
x86_l_e11:
	/* 0xe11: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e14:
	/* 0xe14: jbe    e21 <trace_ret_arch_prctl+0xe21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e21;
	}
x86_l_e16:
	/* 0xe16: and    rbp,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_e1e:
	/* 0xe1e: or     r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_e21:
	/* 0xe21: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e25:
	/* 0xe25: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2a:
	/* 0xe2a: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e31:
	/* 0xe31: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_e34:
	/* 0xe34: je     e77 <trace_ret_arch_prctl+0xe77> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e77;
	}
x86_l_e36:
	/* 0xe36: mov    QWORD PTR [rsp+0x70],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e3b:
	/* 0xe3b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e40:
	/* 0xe40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e45:
	/* 0xe45: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e48:
	/* 0xe48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4a:
	/* 0xe4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4d:
	/* 0xe4d: je     e88 <trace_ret_arch_prctl+0xe88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e88;
	}
x86_l_e4f:
	/* 0xe4f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e52:
	/* 0xe52: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e56:
	/* 0xe56: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e59:
	/* 0xe59: jmp    e8a <trace_ret_arch_prctl+0xe8a> */
	goto x86_l_e8a;
x86_l_e5b:
	/* 0xe5b: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e62:
	/* 0xe62: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_e69:
	/* 0xe69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e6c:
	/* 0xe6c: jne    cea <trace_ret_arch_prctl+0xcea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cea;
	}
x86_l_e72:
	/* 0xe72: jmp    d09 <trace_ret_arch_prctl+0xd09> */
	goto x86_l_d09;
x86_l_e77:
	/* 0xe77: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e79:
	/* 0xe79: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e7c:
	/* 0xe7c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e81:
	/* 0xe81: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: jae    ea4 <trace_ret_arch_prctl+0xea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ea4;
	}
x86_l_e86:
	/* 0xe86: jmp    eba <trace_ret_arch_prctl+0xeba> */
	goto x86_l_eba;
x86_l_e88:
	/* 0xe88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8a:
	/* 0xe8a: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e92:
	/* 0xe92: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e97:
	/* 0xe97: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e9a:
	/* 0xe9a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9f:
	/* 0xe9f: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ea2:
	/* 0xea2: jb     eba <trace_ret_arch_prctl+0xeba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_eba;
	}
x86_l_ea4:
	/* 0xea4: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_ea8:
	/* 0xea8: je     eaf <trace_ret_arch_prctl+0xeaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eaf;
	}
x86_l_eaa:
	/* 0xeaa: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ead:
	/* 0xead: jbe    eba <trace_ret_arch_prctl+0xeba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_eba;
	}
x86_l_eaf:
	/* 0xeaf: and    rbp,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_eb7:
	/* 0xeb7: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_eba:
	/* 0xeba: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_ebd:
	/* 0xebd: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ec0:
	/* 0xec0: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_ec3:
	/* 0xec3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec8:
	/* 0xec8: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_ed0:
	/* 0xed0: movzx  r15d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_ed6:
	/* 0xed6: je     f8d <trace_ret_arch_prctl+0xf8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3981ULL;
	}
x86_l_edc:
	/* 0xedc: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_ee1:
	/* 0xee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee3:
	/* 0xee3: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ee7:
	/* 0xee7: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_eee:
	/* 0xeee: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
	return 3829ULL;
}

static __noinline __u64 tracee_trace_ret_arch_prctl_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3829ULL: goto x86_l_ef5;
	case 3834ULL: goto x86_l_efa;
	case 3841ULL: goto x86_l_f01;
	case 3848ULL: goto x86_l_f08;
	case 3854ULL: goto x86_l_f0e;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3871ULL: goto x86_l_f1f;
	case 3873ULL: goto x86_l_f21;
	case 3876ULL: goto x86_l_f24;
	case 3880ULL: goto x86_l_f28;
	case 3885ULL: goto x86_l_f2d;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3897ULL: goto x86_l_f39;
	case 3902ULL: goto x86_l_f3e;
	case 3907ULL: goto x86_l_f43;
	case 3909ULL: goto x86_l_f45;
	case 3912ULL: goto x86_l_f48;
	case 3914ULL: goto x86_l_f4a;
	case 3917ULL: goto x86_l_f4d;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3939ULL: goto x86_l_f63;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3949ULL: goto x86_l_f6d;
	case 3951ULL: goto x86_l_f6f;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3962ULL: goto x86_l_f7a;
	case 3965ULL: goto x86_l_f7d;
	case 3967ULL: goto x86_l_f7f;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3981ULL: goto x86_l_f8d;
	case 3989ULL: goto x86_l_f95;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4007ULL: goto x86_l_fa7;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4027ULL: goto x86_l_fbb;
	case 4029ULL: goto x86_l_fbd;
	case 4034ULL: goto x86_l_fc2;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4060ULL: goto x86_l_fdc;
	case 4065ULL: goto x86_l_fe1;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4090ULL: goto x86_l_ffa;
	case 4092ULL: goto x86_l_ffc;
	case 4096ULL: goto x86_l_1000;
	case 4100ULL: goto x86_l_1004;
	case 4107ULL: goto x86_l_100b;
	case 4114ULL: goto x86_l_1012;
	case 4119ULL: goto x86_l_1017;
	case 4124ULL: goto x86_l_101c;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4146ULL: goto x86_l_1032;
	case 4153ULL: goto x86_l_1039;
	case 4156ULL: goto x86_l_103c;
	case 4158ULL: goto x86_l_103e;
	case 4161ULL: goto x86_l_1041;
	case 4165ULL: goto x86_l_1045;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4175ULL: goto x86_l_104f;
	case 4177ULL: goto x86_l_1051;
	case 4180ULL: goto x86_l_1054;
	case 4184ULL: goto x86_l_1058;
	case 4187ULL: goto x86_l_105b;
	case 4189ULL: goto x86_l_105d;
	case 4191ULL: goto x86_l_105f;
	case 4194ULL: goto x86_l_1062;
	case 4197ULL: goto x86_l_1065;
	case 4200ULL: goto x86_l_1068;
	case 4203ULL: goto x86_l_106b;
	case 4211ULL: goto x86_l_1073;
	case 4217ULL: goto x86_l_1079;
	case 4224ULL: goto x86_l_1080;
	case 4228ULL: goto x86_l_1084;
	case 4233ULL: goto x86_l_1089;
	case 4238ULL: goto x86_l_108e;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4270ULL: goto x86_l_10ae;
	case 4275ULL: goto x86_l_10b3;
	case 4278ULL: goto x86_l_10b6;
	case 4280ULL: goto x86_l_10b8;
	case 4284ULL: goto x86_l_10bc;
	case 4288ULL: goto x86_l_10c0;
	case 4292ULL: goto x86_l_10c4;
	case 4296ULL: goto x86_l_10c8;
	case 4301ULL: goto x86_l_10cd;
	case 4306ULL: goto x86_l_10d2;
	case 4311ULL: goto x86_l_10d7;
	case 4316ULL: goto x86_l_10dc;
	case 4318ULL: goto x86_l_10de;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4332ULL: goto x86_l_10ec;
	case 4337ULL: goto x86_l_10f1;
	case 4342ULL: goto x86_l_10f6;
	case 4347ULL: goto x86_l_10fb;
	case 4349ULL: goto x86_l_10fd;
	case 4353ULL: goto x86_l_1101;
	case 4357ULL: goto x86_l_1105;
	case 4364ULL: goto x86_l_110c;
	case 4371ULL: goto x86_l_1113;
	case 4376ULL: goto x86_l_1118;
	case 4381ULL: goto x86_l_111d;
	case 4388ULL: goto x86_l_1124;
	case 4393ULL: goto x86_l_1129;
	case 4398ULL: goto x86_l_112e;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4410ULL: goto x86_l_113a;
	case 4413ULL: goto x86_l_113d;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4444ULL: goto x86_l_115c;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4454ULL: goto x86_l_1166;
	case 4457ULL: goto x86_l_1169;
	case 4460ULL: goto x86_l_116c;
	case 4468ULL: goto x86_l_1174;
	case 4474ULL: goto x86_l_117a;
	case 4479ULL: goto x86_l_117f;
	case 4486ULL: goto x86_l_1186;
	case 4491ULL: goto x86_l_118b;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4506ULL: goto x86_l_119a;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4533ULL: goto x86_l_11b5;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4565ULL: goto x86_l_11d5;
	case 4569ULL: goto x86_l_11d9;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4582ULL: goto x86_l_11e6;
	case 4587ULL: goto x86_l_11eb;
	case 4590ULL: goto x86_l_11ee;
	case 4592ULL: goto x86_l_11f0;
	case 4599ULL: goto x86_l_11f7;
	case 4606ULL: goto x86_l_11fe;
	case 4611ULL: goto x86_l_1203;
	case 4616ULL: goto x86_l_1208;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4638ULL: goto x86_l_121e;
	case 4645ULL: goto x86_l_1225;
	case 4648ULL: goto x86_l_1228;
	case 4650ULL: goto x86_l_122a;
	case 4653ULL: goto x86_l_122d;
	case 4658ULL: goto x86_l_1232;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4666ULL: goto x86_l_123a;
	case 4668ULL: goto x86_l_123c;
	case 4671ULL: goto x86_l_123f;
	case 4675ULL: goto x86_l_1243;
	case 4678ULL: goto x86_l_1246;
	case 4680ULL: goto x86_l_1248;
	case 4682ULL: goto x86_l_124a;
	case 4685ULL: goto x86_l_124d;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4694ULL: goto x86_l_1256;
	case 4699ULL: goto x86_l_125b;
	case 4707ULL: goto x86_l_1263;
	case 4713ULL: goto x86_l_1269;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4730ULL: goto x86_l_127a;
	case 4735ULL: goto x86_l_127f;
	case 4737ULL: goto x86_l_1281;
	case 4744ULL: goto x86_l_1288;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4795ULL: goto x86_l_12bb;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4806ULL: goto x86_l_12c6;
	case 4808ULL: goto x86_l_12c8;
	case 4811ULL: goto x86_l_12cb;
	case 4813ULL: goto x86_l_12cd;
	case 4816ULL: goto x86_l_12d0;
	case 4820ULL: goto x86_l_12d4;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4827ULL: goto x86_l_12db;
	case 4830ULL: goto x86_l_12de;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4839ULL: goto x86_l_12e7;
	case 4844ULL: goto x86_l_12ec;
	case 4851ULL: goto x86_l_12f3;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4860ULL: goto x86_l_12fc;
	case 4864ULL: goto x86_l_1300;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4881ULL: goto x86_l_1311;
	case 4888ULL: goto x86_l_1318;
	case 4893ULL: goto x86_l_131d;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4903ULL: goto x86_l_1327;
	case 4910ULL: goto x86_l_132e;
	case 4913ULL: goto x86_l_1331;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4930ULL: goto x86_l_1342;
	case 4933ULL: goto x86_l_1345;
	case 4935ULL: goto x86_l_1347;
	case 4938ULL: goto x86_l_134a;
	case 4942ULL: goto x86_l_134e;
	case 4945ULL: goto x86_l_1351;
	case 4947ULL: goto x86_l_1353;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4968ULL: goto x86_l_1368;
	case 4971ULL: goto x86_l_136b;
	case 4973ULL: goto x86_l_136d;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4997ULL: goto x86_l_1385;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5010ULL: goto x86_l_1392;
	case 5012ULL: goto x86_l_1394;
	case 5019ULL: goto x86_l_139b;
	case 5022ULL: goto x86_l_139e;
	case 5024ULL: goto x86_l_13a0;
	case 5027ULL: goto x86_l_13a3;
	case 5031ULL: goto x86_l_13a7;
	case 5036ULL: goto x86_l_13ac;
	case 5038ULL: goto x86_l_13ae;
	case 5041ULL: goto x86_l_13b1;
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5060ULL: goto x86_l_13c4;
	case 5063ULL: goto x86_l_13c7;
	case 5066ULL: goto x86_l_13ca;
	case 5069ULL: goto x86_l_13cd;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5085ULL: goto x86_l_13dd;
	case 5092ULL: goto x86_l_13e4;
	case 5097ULL: goto x86_l_13e9;
	case 5102ULL: goto x86_l_13ee;
	case 5109ULL: goto x86_l_13f5;
	case 5114ULL: goto x86_l_13fa;
	case 5119ULL: goto x86_l_13ff;
	case 5122ULL: goto x86_l_1402;
	case 5124ULL: goto x86_l_1404;
	case 5131ULL: goto x86_l_140b;
	case 5134ULL: goto x86_l_140e;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5147ULL: goto x86_l_141b;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5159ULL: goto x86_l_1427;
	case 5161ULL: goto x86_l_1429;
	case 5164ULL: goto x86_l_142c;
	case 5166ULL: goto x86_l_142e;
	case 5174ULL: goto x86_l_1436;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5186ULL: goto x86_l_1442;
	case 5188ULL: goto x86_l_1444;
	case 5191ULL: goto x86_l_1447;
	case 5193ULL: goto x86_l_1449;
	case 5196ULL: goto x86_l_144c;
	case 5200ULL: goto x86_l_1450;
	case 5203ULL: goto x86_l_1453;
	case 5205ULL: goto x86_l_1455;
	case 5207ULL: goto x86_l_1457;
	case 5210ULL: goto x86_l_145a;
	case 5213ULL: goto x86_l_145d;
	case 5216ULL: goto x86_l_1460;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5231ULL: goto x86_l_146f;
	case 5234ULL: goto x86_l_1472;
	case 5242ULL: goto x86_l_147a;
	case 5244ULL: goto x86_l_147c;
	case 5252ULL: goto x86_l_1484;
	case 5256ULL: goto x86_l_1488;
	case 5259ULL: goto x86_l_148b;
	case 5266ULL: goto x86_l_1492;
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5283ULL: goto x86_l_14a3;
	case 5289ULL: goto x86_l_14a9;
	case 5293ULL: goto x86_l_14ad;
	case 5300ULL: goto x86_l_14b4;
	case 5307ULL: goto x86_l_14bb;
	case 5310ULL: goto x86_l_14be;
	case 5316ULL: goto x86_l_14c4;
	case 5319ULL: goto x86_l_14c7;
	case 5322ULL: goto x86_l_14ca;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5336ULL: goto x86_l_14d8;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5345ULL: goto x86_l_14e1;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5362ULL: goto x86_l_14f2;
	case 5368ULL: goto x86_l_14f8;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5377ULL: goto x86_l_1501;
	case 5381ULL: goto x86_l_1505;
	case 5387ULL: goto x86_l_150b;
	case 5389ULL: goto x86_l_150d;
	case 5393ULL: goto x86_l_1511;
	case 5396ULL: goto x86_l_1514;
	case 5402ULL: goto x86_l_151a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_ef5:
	/* 0xef5: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_efa:
	/* 0xefa: mov    rbp,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_f01:
	/* 0xf01: mov    r13,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_f08:
	/* 0xf08: mov    WORD PTR [rsp+0x10],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0e:
	/* 0xf0e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_f15:
	/* 0xf15: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f1a:
	/* 0xf1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1f:
	/* 0xf1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f21:
	/* 0xf21: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f24:
	/* 0xf24: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f28:
	/* 0xf28: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f2d:
	/* 0xf2d: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f34:
	/* 0xf34: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_f37:
	/* 0xf37: je     f56 <trace_ret_arch_prctl+0xf56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f56;
	}
x86_l_f39:
	/* 0xf39: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3e:
	/* 0xf3e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f43:
	/* 0xf43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f45:
	/* 0xf45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f48:
	/* 0xf48: je     f56 <trace_ret_arch_prctl+0xf56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f56;
	}
x86_l_f4a:
	/* 0xf4a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4d:
	/* 0xf4d: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f51:
	/* 0xf51: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f54:
	/* 0xf54: jmp    f58 <trace_ret_arch_prctl+0xf58> */
	goto x86_l_f58;
x86_l_f56:
	/* 0xf56: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f58:
	/* 0xf58: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f5b:
	/* 0xf5b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f60:
	/* 0xf60: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_f63:
	/* 0xf63: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_f66:
	/* 0xf66: jae    f6f <trace_ret_arch_prctl+0xf6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f6f;
	}
x86_l_f68:
	/* 0xf68: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6d:
	/* 0xf6d: jmp    f87 <trace_ret_arch_prctl+0xf87> */
	goto x86_l_f87;
x86_l_f6f:
	/* 0xf6f: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f73:
	/* 0xf73: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f78:
	/* 0xf78: je     f7f <trace_ret_arch_prctl+0xf7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f7f;
	}
x86_l_f7a:
	/* 0xf7a: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_f7d:
	/* 0xf7d: jbe    f87 <trace_ret_arch_prctl+0xf87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_f87;
	}
x86_l_f7f:
	/* 0xf7f: and    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_f84:
	/* 0xf84: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_f87:
	/* 0xf87: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f8a:
	/* 0xf8a: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_f8d:
	/* 0xf8d: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_f95:
	/* 0xf95: je     106b <trace_ret_arch_prctl+0x106b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106b;
	}
x86_l_f9b:
	/* 0xf9b: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_fa0:
	/* 0xfa0: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_fa7:
	/* 0xfa7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fac:
	/* 0xfac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fb1:
	/* 0xfb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fb6:
	/* 0xfb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fbb:
	/* 0xfbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbd:
	/* 0xfbd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc2:
	/* 0xfc2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fc6:
	/* 0xfc6: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fcb:
	/* 0xfcb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fd0:
	/* 0xfd0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd5:
	/* 0xfd5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fda:
	/* 0xfda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdc:
	/* 0xfdc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe1:
	/* 0xfe1: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fe6:
	/* 0xfe6: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_feb:
	/* 0xfeb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ff0:
	/* 0xff0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff5:
	/* 0xff5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ffa:
	/* 0xffa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffc:
	/* 0xffc: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1000:
	/* 0x1000: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1004:
	/* 0x1004: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_100b:
	/* 0x100b: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_1012:
	/* 0x1012: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_1017:
	/* 0x1017: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101c:
	/* 0x101c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_1023:
	/* 0x1023: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1028:
	/* 0x1028: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_102d:
	/* 0x102d: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1030:
	/* 0x1030: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1032:
	/* 0x1032: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1039:
	/* 0x1039: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_103c:
	/* 0x103c: je     105d <trace_ret_arch_prctl+0x105d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105d;
	}
x86_l_103e:
	/* 0x103e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1041:
	/* 0x1041: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1045:
	/* 0x1045: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_104a:
	/* 0x104a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104c:
	/* 0x104c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_104f:
	/* 0x104f: je     105d <trace_ret_arch_prctl+0x105d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105d;
	}
x86_l_1051:
	/* 0x1051: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1054:
	/* 0x1054: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1058:
	/* 0x1058: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_105b:
	/* 0x105b: jmp    105f <trace_ret_arch_prctl+0x105f> */
	goto x86_l_105f;
x86_l_105d:
	/* 0x105d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_105f:
	/* 0x105f: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1062:
	/* 0x1062: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1065:
	/* 0x1065: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1068:
	/* 0x1068: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_106b:
	/* 0x106b: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_1073:
	/* 0x1073: je     116c <trace_ret_arch_prctl+0x116c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_116c;
	}
x86_l_1079:
	/* 0x1079: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1080:
	/* 0x1080: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1084:
	/* 0x1084: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1089:
	/* 0x1089: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_108e:
	/* 0x108e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1093:
	/* 0x1093: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1098:
	/* 0x1098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109a:
	/* 0x109a: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_109f:
	/* 0x109f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a4:
	/* 0x10a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10a9:
	/* 0x10a9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10ae:
	/* 0x10ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10b3:
	/* 0x10b3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_10b6:
	/* 0x10b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b8:
	/* 0x10b8: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10bc:
	/* 0x10bc: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_10c0:
	/* 0x10c0: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_10c4:
	/* 0x10c4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10c8:
	/* 0x10c8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10cd:
	/* 0x10cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10d2:
	/* 0x10d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10d7:
	/* 0x10d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_10dc:
	/* 0x10dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10de:
	/* 0x10de: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e3:
	/* 0x10e3: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_10e7:
	/* 0x10e7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ec:
	/* 0x10ec: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10f1:
	/* 0x10f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_10f6:
	/* 0x10f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10fb:
	/* 0x10fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fd:
	/* 0x10fd: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1101:
	/* 0x1101: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1105:
	/* 0x1105: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_110c:
	/* 0x110c: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_1113:
	/* 0x1113: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_1118:
	/* 0x1118: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_111d:
	/* 0x111d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1124:
	/* 0x1124: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1129:
	/* 0x1129: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_112e:
	/* 0x112e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1131:
	/* 0x1131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1133:
	/* 0x1133: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_113a:
	/* 0x113a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_113d:
	/* 0x113d: je     115e <trace_ret_arch_prctl+0x115e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115e;
	}
x86_l_113f:
	/* 0x113f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1142:
	/* 0x1142: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1146:
	/* 0x1146: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114b:
	/* 0x114b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114d:
	/* 0x114d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1150:
	/* 0x1150: je     115e <trace_ret_arch_prctl+0x115e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115e;
	}
x86_l_1152:
	/* 0x1152: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1155:
	/* 0x1155: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1159:
	/* 0x1159: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_115c:
	/* 0x115c: jmp    1160 <trace_ret_arch_prctl+0x1160> */
	goto x86_l_1160;
x86_l_115e:
	/* 0x115e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1160:
	/* 0x1160: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1163:
	/* 0x1163: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1166:
	/* 0x1166: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1169:
	/* 0x1169: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_116c:
	/* 0x116c: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1174:
	/* 0x1174: je     125b <trace_ret_arch_prctl+0x125b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125b;
	}
x86_l_117a:
	/* 0x117a: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_117f:
	/* 0x117f: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1186:
	/* 0x1186: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118b:
	/* 0x118b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1190:
	/* 0x1190: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1195:
	/* 0x1195: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_119a:
	/* 0x119a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119c:
	/* 0x119c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a1:
	/* 0x11a1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a6:
	/* 0x11a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11ab:
	/* 0x11ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11b0:
	/* 0x11b0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11b5:
	/* 0x11b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b7:
	/* 0x11b7: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11bc:
	/* 0x11bc: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11c1:
	/* 0x11c1: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_11c6:
	/* 0x11c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11cb:
	/* 0x11cb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_11ce:
	/* 0x11ce: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_11d3:
	/* 0x11d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d5:
	/* 0x11d5: lea    rbx,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_11d9:
	/* 0x11d9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_11de:
	/* 0x11de: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_11e3:
	/* 0x11e3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11e6:
	/* 0x11e6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_11eb:
	/* 0x11eb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11ee:
	/* 0x11ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f0:
	/* 0x11f0: mov    r15,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_11f7:
	/* 0x11f7: mov    r13,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_11fe:
	/* 0x11fe: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_1203:
	/* 0x1203: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1208:
	/* 0x1208: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_120f:
	/* 0x120f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1214:
	/* 0x1214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1219:
	/* 0x1219: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_121c:
	/* 0x121c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_121e:
	/* 0x121e: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1225:
	/* 0x1225: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1228:
	/* 0x1228: je     1248 <trace_ret_arch_prctl+0x1248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1248;
	}
x86_l_122a:
	/* 0x122a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_122d:
	/* 0x122d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1232:
	/* 0x1232: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1235:
	/* 0x1235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1237:
	/* 0x1237: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_123a:
	/* 0x123a: je     1248 <trace_ret_arch_prctl+0x1248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1248;
	}
x86_l_123c:
	/* 0x123c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123f:
	/* 0x123f: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1243:
	/* 0x1243: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1246:
	/* 0x1246: jmp    124a <trace_ret_arch_prctl+0x124a> */
	goto x86_l_124a;
x86_l_1248:
	/* 0x1248: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124a:
	/* 0x124a: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_124d:
	/* 0x124d: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1250:
	/* 0x1250: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1253:
	/* 0x1253: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1256:
	/* 0x1256: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125b:
	/* 0x125b: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1263:
	/* 0x1263: je     12ec <trace_ret_arch_prctl+0x12ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ec;
	}
x86_l_1269:
	/* 0x1269: lea    rbx,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_126d:
	/* 0x126d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1272:
	/* 0x1272: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1277:
	/* 0x1277: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_127a:
	/* 0x127a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_127f:
	/* 0x127f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1281:
	/* 0x1281: mov    r15,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1288:
	/* 0x1288: mov    r13,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_128f:
	/* 0x128f: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_1294:
	/* 0x1294: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1299:
	/* 0x1299: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_12a0:
	/* 0x12a0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12a5:
	/* 0x12a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12aa:
	/* 0x12aa: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12ad:
	/* 0x12ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12af:
	/* 0x12af: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12b6:
	/* 0x12b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b9:
	/* 0x12b9: je     12d9 <trace_ret_arch_prctl+0x12d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d9;
	}
x86_l_12bb:
	/* 0x12bb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12be:
	/* 0x12be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c3:
	/* 0x12c3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_12c6:
	/* 0x12c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c8:
	/* 0x12c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12cb:
	/* 0x12cb: je     12d9 <trace_ret_arch_prctl+0x12d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12d9;
	}
x86_l_12cd:
	/* 0x12cd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d0:
	/* 0x12d0: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d4:
	/* 0x12d4: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12d7:
	/* 0x12d7: jmp    12db <trace_ret_arch_prctl+0x12db> */
	goto x86_l_12db;
x86_l_12d9:
	/* 0x12d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12db:
	/* 0x12db: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12de:
	/* 0x12de: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_12e1:
	/* 0x12e1: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_12e4:
	/* 0x12e4: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_12e7:
	/* 0x12e7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ec:
	/* 0x12ec: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_12f3:
	/* 0x12f3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_12f6:
	/* 0x12f6: je     1361 <trace_ret_arch_prctl+0x1361> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1361;
	}
x86_l_12f8:
	/* 0x12f8: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12fc:
	/* 0x12fc: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1300:
	/* 0x1300: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_1307:
	/* 0x1307: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_130c:
	/* 0x130c: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1311:
	/* 0x1311: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_1318:
	/* 0x1318: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_131d:
	/* 0x131d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1322:
	/* 0x1322: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1325:
	/* 0x1325: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1327:
	/* 0x1327: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_132e:
	/* 0x132e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1331:
	/* 0x1331: je     1353 <trace_ret_arch_prctl+0x1353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1353;
	}
x86_l_1333:
	/* 0x1333: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1336:
	/* 0x1336: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_133b:
	/* 0x133b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1340:
	/* 0x1340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1342:
	/* 0x1342: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1345:
	/* 0x1345: je     1353 <trace_ret_arch_prctl+0x1353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1353;
	}
x86_l_1347:
	/* 0x1347: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_134a:
	/* 0x134a: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_134e:
	/* 0x134e: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1351:
	/* 0x1351: jmp    1355 <trace_ret_arch_prctl+0x1355> */
	goto x86_l_1355;
x86_l_1353:
	/* 0x1353: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1355:
	/* 0x1355: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1358:
	/* 0x1358: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_135b:
	/* 0x135b: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_135e:
	/* 0x135e: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1361:
	/* 0x1361: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1368:
	/* 0x1368: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_136b:
	/* 0x136b: je     13cd <trace_ret_arch_prctl+0x13cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13cd;
	}
x86_l_136d:
	/* 0x136d: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1374:
	/* 0x1374: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_1379:
	/* 0x1379: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_137e:
	/* 0x137e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1385:
	/* 0x1385: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_138a:
	/* 0x138a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138f:
	/* 0x138f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1392:
	/* 0x1392: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1394:
	/* 0x1394: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_139b:
	/* 0x139b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_139e:
	/* 0x139e: je     13bf <trace_ret_arch_prctl+0x13bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bf;
	}
x86_l_13a0:
	/* 0x13a0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13a3:
	/* 0x13a3: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13a7:
	/* 0x13a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ac:
	/* 0x13ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ae:
	/* 0x13ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b1:
	/* 0x13b1: je     13bf <trace_ret_arch_prctl+0x13bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bf;
	}
x86_l_13b3:
	/* 0x13b3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b6:
	/* 0x13b6: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ba:
	/* 0x13ba: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13bd:
	/* 0x13bd: jmp    13c1 <trace_ret_arch_prctl+0x13c1> */
	goto x86_l_13c1;
x86_l_13bf:
	/* 0x13bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c1:
	/* 0x13c1: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13c4:
	/* 0x13c4: and    r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_13c7:
	/* 0x13c7: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13ca:
	/* 0x13ca: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_13cd:
	/* 0x13cd: mov    r15,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_13d4:
	/* 0x13d4: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: je     1468 <trace_ret_arch_prctl+0x1468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1468;
	}
x86_l_13dd:
	/* 0x13dd: mov    r13,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_13e4:
	/* 0x13e4: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_13e9:
	/* 0x13e9: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13ee:
	/* 0x13ee: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_13f5:
	/* 0x13f5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13fa:
	/* 0x13fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ff:
	/* 0x13ff: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1402:
	/* 0x1402: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1404:
	/* 0x1404: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_140b:
	/* 0x140b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_140e:
	/* 0x140e: je     1455 <trace_ret_arch_prctl+0x1455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1455;
	}
x86_l_1410:
	/* 0x1410: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1413:
	/* 0x1413: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_141b:
	/* 0x141b: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_141f:
	/* 0x141f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1424:
	/* 0x1424: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1427:
	/* 0x1427: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1429:
	/* 0x1429: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_142c:
	/* 0x142c: jne    1449 <trace_ret_arch_prctl+0x1449> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1449;
	}
x86_l_142e:
	/* 0x142e: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1436:
	/* 0x1436: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_143a:
	/* 0x143a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_143f:
	/* 0x143f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1442:
	/* 0x1442: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1444:
	/* 0x1444: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1447:
	/* 0x1447: je     1455 <trace_ret_arch_prctl+0x1455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1455;
	}
x86_l_1449:
	/* 0x1449: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144c:
	/* 0x144c: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1450:
	/* 0x1450: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1453:
	/* 0x1453: jmp    1457 <trace_ret_arch_prctl+0x1457> */
	goto x86_l_1457;
x86_l_1455:
	/* 0x1455: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1457:
	/* 0x1457: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_145a:
	/* 0x145a: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_145d:
	/* 0x145d: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1460:
	/* 0x1460: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1463:
	/* 0x1463: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1468:
	/* 0x1468: mov    rax,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_146f:
	/* 0x146f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_147a:
	/* 0x147a: je     148b <trace_ret_arch_prctl+0x148b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148b;
	}
x86_l_147c:
	/* 0x147c: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1484:
	/* 0x1484: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1488:
	/* 0x1488: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_148b:
	/* 0x148b: and    r12,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1492:
	/* 0x1492: mov    rax,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1499:
	/* 0x1499: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_149c:
	/* 0x149c: mov    QWORD PTR [r14+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14a3:
	/* 0x14a3: je     26cf <trace_ret_arch_prctl+0x26cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9935ULL;
	}
x86_l_14a9:
	/* 0x14a9: mov    rax,QWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14ad:
	/* 0x14ad: mov    QWORD PTR [rbp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_14b4:
	/* 0x14b4: mov    rcx,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_14bb:
	/* 0x14bb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_14be:
	/* 0x14be: je     2736 <trace_ret_arch_prctl+0x2736> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10038ULL;
	}
x86_l_14c4:
	/* 0x14c4: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14c7:
	/* 0x14c7: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_14ca:
	/* 0x14ca: ja     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5818ULL;
	}
x86_l_14d0:
	/* 0x14d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d2:
	/* 0x14d2: je     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5818ULL;
	}
x86_l_14d8:
	/* 0x14d8: lea    rbx,[rbp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14dc:
	/* 0x14dc: movzx  edi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14df:
	/* 0x14df: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_14e1:
	/* 0x14e1: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_14e8:
	/* 0x14e8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_14ed:
	/* 0x14ed: shlx   rsi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_14f2:
	/* 0x14f2: mov    r8d,0xa880 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 43136ULL);
x86_l_14f8:
	/* 0x14f8: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_14fc:
	/* 0x14fc: jae    1501 <trace_ret_arch_prctl+0x1501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1501;
	}
x86_l_14fe:
	/* 0x14fe: mov    rbx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1501:
	/* 0x1501: mov    r15d,DWORD PTR [rdx+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1505:
	/* 0x1505: test   esi,0x177e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 6014ULL);
x86_l_150b:
	/* 0x150b: je     1533 <trace_ret_arch_prctl+0x1533> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5427ULL;
	}
x86_l_150d:
	/* 0x150d: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1511:
	/* 0x1511: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1514:
	/* 0x1514: jb     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5818ULL;
	}
x86_l_151a:
	/* 0x151a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
	return 5410ULL;
}

static __noinline __u64 tracee_trace_ret_arch_prctl_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5410ULL: goto x86_l_1522;
	case 5416ULL: goto x86_l_1528;
	case 5422ULL: goto x86_l_152e;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5435ULL: goto x86_l_153b;
	case 5441ULL: goto x86_l_1541;
	case 5444ULL: goto x86_l_1544;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5459ULL: goto x86_l_1553;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5484ULL: goto x86_l_156c;
	case 5493ULL: goto x86_l_1575;
	case 5501ULL: goto x86_l_157d;
	case 5509ULL: goto x86_l_1585;
	case 5515ULL: goto x86_l_158b;
	case 5521ULL: goto x86_l_1591;
	case 5525ULL: goto x86_l_1595;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5550ULL: goto x86_l_15ae;
	case 5554ULL: goto x86_l_15b2;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5569ULL: goto x86_l_15c1;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5577ULL: goto x86_l_15c9;
	case 5583ULL: goto x86_l_15cf;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5611ULL: goto x86_l_15eb;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5628ULL: goto x86_l_15fc;
	case 5631ULL: goto x86_l_15ff;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5653ULL: goto x86_l_1615;
	case 5656ULL: goto x86_l_1618;
	case 5658ULL: goto x86_l_161a;
	case 5663ULL: goto x86_l_161f;
	case 5666ULL: goto x86_l_1622;
	case 5668ULL: goto x86_l_1624;
	case 5671ULL: goto x86_l_1627;
	case 5673ULL: goto x86_l_1629;
	case 5676ULL: goto x86_l_162c;
	case 5678ULL: goto x86_l_162e;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5695ULL: goto x86_l_163f;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5717ULL: goto x86_l_1655;
	case 5722ULL: goto x86_l_165a;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5738ULL: goto x86_l_166a;
	case 5744ULL: goto x86_l_1670;
	case 5746ULL: goto x86_l_1672;
	case 5749ULL: goto x86_l_1675;
	case 5753ULL: goto x86_l_1679;
	case 5755ULL: goto x86_l_167b;
	case 5764ULL: goto x86_l_1684;
	case 5768ULL: goto x86_l_1688;
	case 5775ULL: goto x86_l_168f;
	case 5777ULL: goto x86_l_1691;
	case 5781ULL: goto x86_l_1695;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5796ULL: goto x86_l_16a4;
	case 5798ULL: goto x86_l_16a6;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5811ULL: goto x86_l_16b3;
	case 5818ULL: goto x86_l_16ba;
	case 5825ULL: goto x86_l_16c1;
	case 5829ULL: goto x86_l_16c5;
	case 5832ULL: goto x86_l_16c8;
	case 5835ULL: goto x86_l_16cb;
	case 5841ULL: goto x86_l_16d1;
	case 5843ULL: goto x86_l_16d3;
	case 5849ULL: goto x86_l_16d9;
	case 5852ULL: goto x86_l_16dc;
	case 5854ULL: goto x86_l_16de;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5875ULL: goto x86_l_16f3;
	case 5881ULL: goto x86_l_16f9;
	case 5885ULL: goto x86_l_16fd;
	case 5887ULL: goto x86_l_16ff;
	case 5890ULL: goto x86_l_1702;
	case 5894ULL: goto x86_l_1706;
	case 5900ULL: goto x86_l_170c;
	case 5902ULL: goto x86_l_170e;
	case 5906ULL: goto x86_l_1712;
	case 5909ULL: goto x86_l_1715;
	case 5915ULL: goto x86_l_171b;
	case 5923ULL: goto x86_l_1723;
	case 5929ULL: goto x86_l_1729;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5953ULL: goto x86_l_1741;
	case 5959ULL: goto x86_l_1747;
	case 5962ULL: goto x86_l_174a;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5977ULL: goto x86_l_1759;
	case 5982ULL: goto x86_l_175e;
	case 5987ULL: goto x86_l_1763;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6000ULL: goto x86_l_1770;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6010ULL: goto x86_l_177a;
	case 6016ULL: goto x86_l_1780;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6034ULL: goto x86_l_1792;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6052ULL: goto x86_l_17a4;
	case 6058ULL: goto x86_l_17aa;
	case 6064ULL: goto x86_l_17b0;
	case 6073ULL: goto x86_l_17b9;
	case 6081ULL: goto x86_l_17c1;
	case 6089ULL: goto x86_l_17c9;
	case 6095ULL: goto x86_l_17cf;
	case 6101ULL: goto x86_l_17d5;
	case 6105ULL: goto x86_l_17d9;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6130ULL: goto x86_l_17f2;
	case 6134ULL: goto x86_l_17f6;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6151ULL: goto x86_l_1807;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6163ULL: goto x86_l_1813;
	case 6171ULL: goto x86_l_181b;
	case 6177ULL: goto x86_l_1821;
	case 6183ULL: goto x86_l_1827;
	case 6191ULL: goto x86_l_182f;
	case 6199ULL: goto x86_l_1837;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6226ULL: goto x86_l_1852;
	case 6229ULL: goto x86_l_1855;
	case 6235ULL: goto x86_l_185b;
	case 6237ULL: goto x86_l_185d;
	case 6242ULL: goto x86_l_1862;
	case 6245ULL: goto x86_l_1865;
	case 6250ULL: goto x86_l_186a;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6269ULL: goto x86_l_187d;
	case 6273ULL: goto x86_l_1881;
	case 6275ULL: goto x86_l_1883;
	case 6284ULL: goto x86_l_188c;
	case 6288ULL: goto x86_l_1890;
	case 6295ULL: goto x86_l_1897;
	case 6297ULL: goto x86_l_1899;
	case 6301ULL: goto x86_l_189d;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6318ULL: goto x86_l_18ae;
	case 6321ULL: goto x86_l_18b1;
	case 6323ULL: goto x86_l_18b3;
	case 6331ULL: goto x86_l_18bb;
	case 6338ULL: goto x86_l_18c2;
	case 6345ULL: goto x86_l_18c9;
	case 6349ULL: goto x86_l_18cd;
	case 6352ULL: goto x86_l_18d0;
	case 6355ULL: goto x86_l_18d3;
	case 6361ULL: goto x86_l_18d9;
	case 6363ULL: goto x86_l_18db;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6381ULL: goto x86_l_18ed;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6398ULL: goto x86_l_18fe;
	case 6404ULL: goto x86_l_1904;
	case 6408ULL: goto x86_l_1908;
	case 6410ULL: goto x86_l_190a;
	case 6413ULL: goto x86_l_190d;
	case 6417ULL: goto x86_l_1911;
	case 6423ULL: goto x86_l_1917;
	case 6425ULL: goto x86_l_1919;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6482ULL: goto x86_l_1952;
	case 6485ULL: goto x86_l_1955;
	case 6491ULL: goto x86_l_195b;
	case 6494ULL: goto x86_l_195e;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6520ULL: goto x86_l_1978;
	case 6523ULL: goto x86_l_197b;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6533ULL: goto x86_l_1985;
	case 6539ULL: goto x86_l_198b;
	case 6542ULL: goto x86_l_198e;
	case 6548ULL: goto x86_l_1994;
	case 6551ULL: goto x86_l_1997;
	case 6557ULL: goto x86_l_199d;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6575ULL: goto x86_l_19af;
	case 6581ULL: goto x86_l_19b5;
	case 6587ULL: goto x86_l_19bb;
	case 6596ULL: goto x86_l_19c4;
	case 6604ULL: goto x86_l_19cc;
	case 6612ULL: goto x86_l_19d4;
	case 6618ULL: goto x86_l_19da;
	case 6624ULL: goto x86_l_19e0;
	case 6628ULL: goto x86_l_19e4;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6653ULL: goto x86_l_19fd;
	case 6657ULL: goto x86_l_1a01;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6680ULL: goto x86_l_1a18;
	case 6686ULL: goto x86_l_1a1e;
	case 6694ULL: goto x86_l_1a26;
	case 6700ULL: goto x86_l_1a2c;
	case 6706ULL: goto x86_l_1a32;
	case 6714ULL: goto x86_l_1a3a;
	case 6722ULL: goto x86_l_1a42;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6745ULL: goto x86_l_1a59;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6758ULL: goto x86_l_1a66;
	case 6760ULL: goto x86_l_1a68;
	case 6765ULL: goto x86_l_1a6d;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6781ULL: goto x86_l_1a7d;
	case 6787ULL: goto x86_l_1a83;
	case 6789ULL: goto x86_l_1a85;
	case 6792ULL: goto x86_l_1a88;
	case 6796ULL: goto x86_l_1a8c;
	case 6798ULL: goto x86_l_1a8e;
	case 6807ULL: goto x86_l_1a97;
	case 6811ULL: goto x86_l_1a9b;
	case 6818ULL: goto x86_l_1aa2;
	case 6820ULL: goto x86_l_1aa4;
	case 6824ULL: goto x86_l_1aa8;
	case 6831ULL: goto x86_l_1aaf;
	case 6836ULL: goto x86_l_1ab4;
	case 6839ULL: goto x86_l_1ab7;
	case 6841ULL: goto x86_l_1ab9;
	case 6844ULL: goto x86_l_1abc;
	case 6846ULL: goto x86_l_1abe;
	case 6854ULL: goto x86_l_1ac6;
	case 6861ULL: goto x86_l_1acd;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6878ULL: goto x86_l_1ade;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6892ULL: goto x86_l_1aec;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6921ULL: goto x86_l_1b09;
	case 6927ULL: goto x86_l_1b0f;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6940ULL: goto x86_l_1b1c;
	case 6946ULL: goto x86_l_1b22;
	case 6948ULL: goto x86_l_1b24;
	case 6952ULL: goto x86_l_1b28;
	case 6955ULL: goto x86_l_1b2b;
	case 6961ULL: goto x86_l_1b31;
	case 6969ULL: goto x86_l_1b39;
	case 6975ULL: goto x86_l_1b3f;
	case 6981ULL: goto x86_l_1b45;
	case 6986ULL: goto x86_l_1b4a;
	case 6989ULL: goto x86_l_1b4d;
	case 6991ULL: goto x86_l_1b4f;
	case 6996ULL: goto x86_l_1b54;
	case 6999ULL: goto x86_l_1b57;
	case 7005ULL: goto x86_l_1b5d;
	case 7008ULL: goto x86_l_1b60;
	case 7014ULL: goto x86_l_1b66;
	case 7017ULL: goto x86_l_1b69;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7056ULL: goto x86_l_1b90;
	case 7062ULL: goto x86_l_1b96;
	case 7065ULL: goto x86_l_1b99;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7098ULL: goto x86_l_1bba;
	case 7104ULL: goto x86_l_1bc0;
	case 7110ULL: goto x86_l_1bc6;
	case 7119ULL: goto x86_l_1bcf;
	case 7127ULL: goto x86_l_1bd7;
	case 7135ULL: goto x86_l_1bdf;
	case 7141ULL: goto x86_l_1be5;
	case 7147ULL: goto x86_l_1beb;
	case 7151ULL: goto x86_l_1bef;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7176ULL: goto x86_l_1c08;
	case 7180ULL: goto x86_l_1c0c;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7195ULL: goto x86_l_1c1b;
	case 7197ULL: goto x86_l_1c1d;
	case 7200ULL: goto x86_l_1c20;
	case 7203ULL: goto x86_l_1c23;
	case 7209ULL: goto x86_l_1c29;
	case 7217ULL: goto x86_l_1c31;
	case 7223ULL: goto x86_l_1c37;
	case 7229ULL: goto x86_l_1c3d;
	case 7237ULL: goto x86_l_1c45;
	case 7245ULL: goto x86_l_1c4d;
	case 7249ULL: goto x86_l_1c51;
	case 7251ULL: goto x86_l_1c53;
	case 7258ULL: goto x86_l_1c5a;
	case 7263ULL: goto x86_l_1c5f;
	case 7268ULL: goto x86_l_1c64;
	case 7272ULL: goto x86_l_1c68;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1522:
	/* 0x1522: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1528:
	/* 0x1528: jbe    1672 <trace_ret_arch_prctl+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1672;
	}
x86_l_152e:
	/* 0x152e: jmp    16ba <trace_ret_arch_prctl+0x16ba> */
	goto x86_l_16ba;
x86_l_1533:
	/* 0x1533: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1538:
	/* 0x1538: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_153b:
	/* 0x153b: je     165a <trace_ret_arch_prctl+0x165a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165a;
	}
x86_l_1541:
	/* 0x1541: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1544:
	/* 0x1544: je     15fc <trace_ret_arch_prctl+0x15fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15fc;
	}
x86_l_154a:
	/* 0x154a: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_154d:
	/* 0x154d: jne    162e <trace_ret_arch_prctl+0x162e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_162e;
	}
x86_l_1553:
	/* 0x1553: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_155b:
	/* 0x155b: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1561:
	/* 0x1561: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1566:
	/* 0x1566: ja     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16ba;
	}
x86_l_156c:
	/* 0x156c: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1575:
	/* 0x1575: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_157d:
	/* 0x157d: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1585:
	/* 0x1585: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_158b:
	/* 0x158b: ja     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16ba;
	}
x86_l_1591:
	/* 0x1591: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1595:
	/* 0x1595: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_159c:
	/* 0x159c: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_15a1:
	/* 0x15a1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15a6:
	/* 0x15a6: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15ae:
	/* 0x15ae: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_15b2:
	/* 0x15b2: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_15b9:
	/* 0x15b9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15be:
	/* 0x15be: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_15c1:
	/* 0x15c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c3:
	/* 0x15c3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15c6:
	/* 0x15c6: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_15c9:
	/* 0x15c9: jle    16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_16ba;
	}
x86_l_15cf:
	/* 0x15cf: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_15d7:
	/* 0x15d7: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_15dd:
	/* 0x15dd: ja     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16ba;
	}
x86_l_15e3:
	/* 0x15e3: mov    DWORD PTR [rax+r14*1+0x8a],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_15eb:
	/* 0x15eb: add    r15w,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_15f3:
	/* 0x15f3: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_15f7:
	/* 0x15f7: jmp    16ab <trace_ret_arch_prctl+0x16ab> */
	goto x86_l_16ab;
x86_l_15fc:
	/* 0x15fc: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_15ff:
	/* 0x15ff: je     1638 <trace_ret_arch_prctl+0x1638> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1638;
	}
x86_l_1601:
	/* 0x1601: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1606:
	/* 0x1606: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_160b:
	/* 0x160b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1610:
	/* 0x1610: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1615:
	/* 0x1615: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1618:
	/* 0x1618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161a:
	/* 0x161a: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_161f:
	/* 0x161f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1622:
	/* 0x1622: je     1655 <trace_ret_arch_prctl+0x1655> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1655;
	}
x86_l_1624:
	/* 0x1624: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1627:
	/* 0x1627: je     164e <trace_ret_arch_prctl+0x164e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_164e;
	}
x86_l_1629:
	/* 0x1629: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_162c:
	/* 0x162c: je     165a <trace_ret_arch_prctl+0x165a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165a;
	}
x86_l_162e:
	/* 0x162e: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1633:
	/* 0x1633: jmp    150d <trace_ret_arch_prctl+0x150d> */
	return 5389ULL;
x86_l_1638:
	/* 0x1638: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_163f:
	/* 0x163f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1644:
	/* 0x1644: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1649:
	/* 0x1649: jmp    150d <trace_ret_arch_prctl+0x150d> */
	return 5389ULL;
x86_l_164e:
	/* 0x164e: mov    ebp,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_1653:
	/* 0x1653: jmp    165a <trace_ret_arch_prctl+0x165a> */
	goto x86_l_165a;
x86_l_1655:
	/* 0x1655: mov    ebp,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 110ULL);
x86_l_165a:
	/* 0x165a: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_165d:
	/* 0x165d: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1662:
	/* 0x1662: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_166a:
	/* 0x166a: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1670:
	/* 0x1670: ja     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16ba;
	}
x86_l_1672:
	/* 0x1672: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1675:
	/* 0x1675: lea    rax,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1679:
	/* 0x1679: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_167b:
	/* 0x167b: mov    BYTE PTR [r14+rcx*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 588410519552ULL);
x86_l_1684:
	/* 0x1684: lea    r15d,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1688:
	/* 0x1688: cmp    r15d,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32000ULL);
x86_l_168f:
	/* 0x168f: ja     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16ba;
	}
x86_l_1691:
	/* 0x1691: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1695:
	/* 0x1695: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_169c:
	/* 0x169c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16a1:
	/* 0x16a1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_16a4:
	/* 0x16a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a6:
	/* 0x16a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16a9:
	/* 0x16a9: js     16ba <trace_ret_arch_prctl+0x16ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_16ba;
	}
x86_l_16ab:
	/* 0x16ab: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16b3:
	/* 0x16b3: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_16ba:
	/* 0x16ba: mov    rcx,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_16c1:
	/* 0x16c1: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_16c5:
	/* 0x16c5: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16c8:
	/* 0x16c8: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_16cb:
	/* 0x16cb: ja     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c2;
	}
x86_l_16d1:
	/* 0x16d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16d3:
	/* 0x16d3: je     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18c2;
	}
x86_l_16d9:
	/* 0x16d9: movzx  edi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16dc:
	/* 0x16dc: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_16de:
	/* 0x16de: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_16e5:
	/* 0x16e5: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_16ea:
	/* 0x16ea: shlx   rsi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_16ef:
	/* 0x16ef: lea    rbx,[rbp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16f3:
	/* 0x16f3: mov    r8d,0xa880 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 43136ULL);
x86_l_16f9:
	/* 0x16f9: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_16fd:
	/* 0x16fd: jae    1702 <trace_ret_arch_prctl+0x1702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1702;
	}
x86_l_16ff:
	/* 0x16ff: mov    rbx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1702:
	/* 0x1702: mov    r15d,DWORD PTR [rdx+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1706:
	/* 0x1706: test   esi,0x177e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 6014ULL);
x86_l_170c:
	/* 0x170c: je     1734 <trace_ret_arch_prctl+0x1734> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1734;
	}
x86_l_170e:
	/* 0x170e: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1712:
	/* 0x1712: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1715:
	/* 0x1715: jb     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18c2;
	}
x86_l_171b:
	/* 0x171b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1723:
	/* 0x1723: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1729:
	/* 0x1729: jbe    187a <trace_ret_arch_prctl+0x187a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_187a;
	}
x86_l_172f:
	/* 0x172f: jmp    18c2 <trace_ret_arch_prctl+0x18c2> */
	goto x86_l_18c2;
x86_l_1734:
	/* 0x1734: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1737:
	/* 0x1737: je     179c <trace_ret_arch_prctl+0x179c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_179c;
	}
x86_l_1739:
	/* 0x1739: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_173e:
	/* 0x173e: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1741:
	/* 0x1741: je     1862 <trace_ret_arch_prctl+0x1862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1862;
	}
x86_l_1747:
	/* 0x1747: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_174a:
	/* 0x174a: jne    1849 <trace_ret_arch_prctl+0x1849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1849;
	}
x86_l_1750:
	/* 0x1750: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1753:
	/* 0x1753: je     183d <trace_ret_arch_prctl+0x183d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183d;
	}
x86_l_1759:
	/* 0x1759: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_175e:
	/* 0x175e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1763:
	/* 0x1763: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1768:
	/* 0x1768: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_176d:
	/* 0x176d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1770:
	/* 0x1770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1772:
	/* 0x1772: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1777:
	/* 0x1777: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_177a:
	/* 0x177a: je     185d <trace_ret_arch_prctl+0x185d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_185d;
	}
x86_l_1780:
	/* 0x1780: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1783:
	/* 0x1783: je     1862 <trace_ret_arch_prctl+0x1862> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1862;
	}
x86_l_1789:
	/* 0x1789: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_178c:
	/* 0x178c: jne    1849 <trace_ret_arch_prctl+0x1849> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1849;
	}
x86_l_1792:
	/* 0x1792: mov    ebp,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_1797:
	/* 0x1797: jmp    1862 <trace_ret_arch_prctl+0x1862> */
	goto x86_l_1862;
x86_l_179c:
	/* 0x179c: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17a4:
	/* 0x17a4: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_17aa:
	/* 0x17aa: ja     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c2;
	}
x86_l_17b0:
	/* 0x17b0: mov    BYTE PTR [r14+rax*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519553ULL);
x86_l_17b9:
	/* 0x17b9: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17c1:
	/* 0x17c1: mov    WORD PTR [r14+0x7d8e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32142ULL);
x86_l_17c9:
	/* 0x17c9: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_17cf:
	/* 0x17cf: ja     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c2;
	}
x86_l_17d5:
	/* 0x17d5: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_17d9:
	/* 0x17d9: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_17e0:
	/* 0x17e0: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_17e5:
	/* 0x17e5: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_17ea:
	/* 0x17ea: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17f2:
	/* 0x17f2: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_17f6:
	/* 0x17f6: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_17fd:
	/* 0x17fd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1802:
	/* 0x1802: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1805:
	/* 0x1805: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1807:
	/* 0x1807: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_180a:
	/* 0x180a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_180d:
	/* 0x180d: jle    18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_18c2;
	}
x86_l_1813:
	/* 0x1813: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_181b:
	/* 0x181b: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1821:
	/* 0x1821: ja     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c2;
	}
x86_l_1827:
	/* 0x1827: mov    DWORD PTR [rax+r14*1+0x8a],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_182f:
	/* 0x182f: add    r15w,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1837:
	/* 0x1837: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_183b:
	/* 0x183b: jmp    18b3 <trace_ret_arch_prctl+0x18b3> */
	goto x86_l_18b3;
x86_l_183d:
	/* 0x183d: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1844:
	/* 0x1844: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1849:
	/* 0x1849: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_184e:
	/* 0x184e: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1852:
	/* 0x1852: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1855:
	/* 0x1855: jae    171b <trace_ret_arch_prctl+0x171b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_171b;
	}
x86_l_185b:
	/* 0x185b: jmp    18c2 <trace_ret_arch_prctl+0x18c2> */
	goto x86_l_18c2;
x86_l_185d:
	/* 0x185d: mov    ebp,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 110ULL);
x86_l_1862:
	/* 0x1862: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1865:
	/* 0x1865: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186a:
	/* 0x186a: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1872:
	/* 0x1872: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1878:
	/* 0x1878: ja     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c2;
	}
x86_l_187a:
	/* 0x187a: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_187d:
	/* 0x187d: lea    rax,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1881:
	/* 0x1881: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1883:
	/* 0x1883: mov    BYTE PTR [r14+rcx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 588410519553ULL);
x86_l_188c:
	/* 0x188c: lea    r15d,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1890:
	/* 0x1890: cmp    r15d,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32000ULL);
x86_l_1897:
	/* 0x1897: ja     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18c2;
	}
x86_l_1899:
	/* 0x1899: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_189d:
	/* 0x189d: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_18a4:
	/* 0x18a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a9:
	/* 0x18a9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_18ac:
	/* 0x18ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ae:
	/* 0x18ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b1:
	/* 0x18b1: js     18c2 <trace_ret_arch_prctl+0x18c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18c2;
	}
x86_l_18b3:
	/* 0x18b3: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_18bb:
	/* 0x18bb: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_18c2:
	/* 0x18c2: mov    rcx,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_18c9:
	/* 0x18c9: shr    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 16ULL);
x86_l_18cd:
	/* 0x18cd: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18d0:
	/* 0x18d0: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_18d3:
	/* 0x18d3: ja     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1acd;
	}
x86_l_18d9:
	/* 0x18d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18db:
	/* 0x18db: je     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1acd;
	}
x86_l_18e1:
	/* 0x18e1: movzx  edi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18e4:
	/* 0x18e4: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_18e6:
	/* 0x18e6: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_18ed:
	/* 0x18ed: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_18f2:
	/* 0x18f2: shlx   rsi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_18f7:
	/* 0x18f7: lea    rbx,[rbp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18fe:
	/* 0x18fe: mov    r8d,0xa880 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 43136ULL);
x86_l_1904:
	/* 0x1904: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_1908:
	/* 0x1908: jae    190d <trace_ret_arch_prctl+0x190d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_190d;
	}
x86_l_190a:
	/* 0x190a: mov    rbx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190d:
	/* 0x190d: mov    r15d,DWORD PTR [rdx+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1911:
	/* 0x1911: test   esi,0x177e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 6014ULL);
x86_l_1917:
	/* 0x1917: je     193f <trace_ret_arch_prctl+0x193f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_193f;
	}
x86_l_1919:
	/* 0x1919: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_191d:
	/* 0x191d: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1920:
	/* 0x1920: jb     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1acd;
	}
x86_l_1926:
	/* 0x1926: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_192e:
	/* 0x192e: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1934:
	/* 0x1934: jbe    1a85 <trace_ret_arch_prctl+0x1a85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a85;
	}
x86_l_193a:
	/* 0x193a: jmp    1acd <trace_ret_arch_prctl+0x1acd> */
	goto x86_l_1acd;
x86_l_193f:
	/* 0x193f: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1942:
	/* 0x1942: je     19a7 <trace_ret_arch_prctl+0x19a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a7;
	}
x86_l_1944:
	/* 0x1944: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1949:
	/* 0x1949: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_194c:
	/* 0x194c: je     1a6d <trace_ret_arch_prctl+0x1a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a6d;
	}
x86_l_1952:
	/* 0x1952: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1955:
	/* 0x1955: jne    1a54 <trace_ret_arch_prctl+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a54;
	}
x86_l_195b:
	/* 0x195b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_195e:
	/* 0x195e: je     1a48 <trace_ret_arch_prctl+0x1a48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a48;
	}
x86_l_1964:
	/* 0x1964: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1969:
	/* 0x1969: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_196e:
	/* 0x196e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1973:
	/* 0x1973: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1978:
	/* 0x1978: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_197b:
	/* 0x197b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197d:
	/* 0x197d: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1982:
	/* 0x1982: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1985:
	/* 0x1985: je     1a68 <trace_ret_arch_prctl+0x1a68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a68;
	}
x86_l_198b:
	/* 0x198b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_198e:
	/* 0x198e: je     1a6d <trace_ret_arch_prctl+0x1a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a6d;
	}
x86_l_1994:
	/* 0x1994: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1997:
	/* 0x1997: jne    1a54 <trace_ret_arch_prctl+0x1a54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a54;
	}
x86_l_199d:
	/* 0x199d: mov    ebp,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_19a2:
	/* 0x19a2: jmp    1a6d <trace_ret_arch_prctl+0x1a6d> */
	goto x86_l_1a6d;
x86_l_19a7:
	/* 0x19a7: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19af:
	/* 0x19af: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_19b5:
	/* 0x19b5: ja     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1acd;
	}
x86_l_19bb:
	/* 0x19bb: mov    BYTE PTR [r14+rax*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519554ULL);
x86_l_19c4:
	/* 0x19c4: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19cc:
	/* 0x19cc: mov    WORD PTR [r14+0x7d90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32144ULL);
x86_l_19d4:
	/* 0x19d4: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_19da:
	/* 0x19da: ja     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1acd;
	}
x86_l_19e0:
	/* 0x19e0: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_19e4:
	/* 0x19e4: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_19eb:
	/* 0x19eb: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_19f0:
	/* 0x19f0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_19f5:
	/* 0x19f5: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19fd:
	/* 0x19fd: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1a01:
	/* 0x1a01: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1a08:
	/* 0x1a08: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1a10:
	/* 0x1a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a12:
	/* 0x1a12: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1a15:
	/* 0x1a15: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1a18:
	/* 0x1a18: jle    1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1acd;
	}
x86_l_1a1e:
	/* 0x1a1e: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a26:
	/* 0x1a26: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1a2c:
	/* 0x1a2c: ja     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1acd;
	}
x86_l_1a32:
	/* 0x1a32: mov    DWORD PTR [rax+r14*1+0x8a],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1a3a:
	/* 0x1a3a: add    r15w,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a42:
	/* 0x1a42: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1a46:
	/* 0x1a46: jmp    1abe <trace_ret_arch_prctl+0x1abe> */
	goto x86_l_1abe;
x86_l_1a48:
	/* 0x1a48: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1a4f:
	/* 0x1a4f: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a54:
	/* 0x1a54: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a59:
	/* 0x1a59: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1a5d:
	/* 0x1a5d: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1a60:
	/* 0x1a60: jae    1926 <trace_ret_arch_prctl+0x1926> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1926;
	}
x86_l_1a66:
	/* 0x1a66: jmp    1acd <trace_ret_arch_prctl+0x1acd> */
	goto x86_l_1acd;
x86_l_1a68:
	/* 0x1a68: mov    ebp,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 110ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1a70:
	/* 0x1a70: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a75:
	/* 0x1a75: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a7d:
	/* 0x1a7d: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1a83:
	/* 0x1a83: ja     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1acd;
	}
x86_l_1a85:
	/* 0x1a85: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1a88:
	/* 0x1a88: lea    rax,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1a8e:
	/* 0x1a8e: mov    BYTE PTR [r14+rcx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 588410519554ULL);
x86_l_1a97:
	/* 0x1a97: lea    r15d,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1a9b:
	/* 0x1a9b: cmp    r15d,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32000ULL);
x86_l_1aa2:
	/* 0x1aa2: ja     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1acd;
	}
x86_l_1aa4:
	/* 0x1aa4: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1aa8:
	/* 0x1aa8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ab7:
	/* 0x1ab7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab9:
	/* 0x1ab9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1abc:
	/* 0x1abc: js     1acd <trace_ret_arch_prctl+0x1acd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1acd;
	}
x86_l_1abe:
	/* 0x1abe: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ac6:
	/* 0x1ac6: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1acd:
	/* 0x1acd: mov    rcx,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_1ad4:
	/* 0x1ad4: shr    rcx,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 24ULL);
x86_l_1ad8:
	/* 0x1ad8: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1adb:
	/* 0x1adb: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1ade:
	/* 0x1ade: ja     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7384ULL;
	}
x86_l_1ae4:
	/* 0x1ae4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ae6:
	/* 0x1ae6: je     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7384ULL;
	}
x86_l_1aec:
	/* 0x1aec: movzx  edi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1aef:
	/* 0x1aef: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_1af1:
	/* 0x1af1: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1af8:
	/* 0x1af8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1afd:
	/* 0x1afd: shlx   rsi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_1b02:
	/* 0x1b02: lea    rbx,[rbp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b09:
	/* 0x1b09: mov    r8d,0xa880 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 43136ULL);
x86_l_1b0f:
	/* 0x1b0f: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_1b13:
	/* 0x1b13: jae    1b18 <trace_ret_arch_prctl+0x1b18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b18;
	}
x86_l_1b15:
	/* 0x1b15: mov    rbx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b18:
	/* 0x1b18: mov    r15d,DWORD PTR [rdx+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1b1c:
	/* 0x1b1c: test   esi,0x177e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 6014ULL);
x86_l_1b22:
	/* 0x1b22: je     1b4a <trace_ret_arch_prctl+0x1b4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b4a;
	}
x86_l_1b24:
	/* 0x1b24: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1b28:
	/* 0x1b28: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1b2b:
	/* 0x1b2b: jb     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7384ULL;
	}
x86_l_1b31:
	/* 0x1b31: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b39:
	/* 0x1b39: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1b3f:
	/* 0x1b3f: jbe    1c90 <trace_ret_arch_prctl+0x1c90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7312ULL;
	}
x86_l_1b45:
	/* 0x1b45: jmp    1cd8 <trace_ret_arch_prctl+0x1cd8> */
	return 7384ULL;
x86_l_1b4a:
	/* 0x1b4a: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1b4d:
	/* 0x1b4d: je     1bb2 <trace_ret_arch_prctl+0x1bb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bb2;
	}
x86_l_1b4f:
	/* 0x1b4f: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1b54:
	/* 0x1b54: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1b57:
	/* 0x1b57: je     1c78 <trace_ret_arch_prctl+0x1c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7288ULL;
	}
x86_l_1b5d:
	/* 0x1b5d: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1b60:
	/* 0x1b60: jne    1c5f <trace_ret_arch_prctl+0x1c5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c5f;
	}
x86_l_1b66:
	/* 0x1b66: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1b69:
	/* 0x1b69: je     1c53 <trace_ret_arch_prctl+0x1c53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c53;
	}
x86_l_1b6f:
	/* 0x1b6f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b74:
	/* 0x1b74: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b79:
	/* 0x1b79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1b83:
	/* 0x1b83: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1b86:
	/* 0x1b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b88:
	/* 0x1b88: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1b8d:
	/* 0x1b8d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b90:
	/* 0x1b90: je     1c73 <trace_ret_arch_prctl+0x1c73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7283ULL;
	}
x86_l_1b96:
	/* 0x1b96: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b99:
	/* 0x1b99: je     1c78 <trace_ret_arch_prctl+0x1c78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7288ULL;
	}
x86_l_1b9f:
	/* 0x1b9f: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1ba2:
	/* 0x1ba2: jne    1c5f <trace_ret_arch_prctl+0x1c5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c5f;
	}
x86_l_1ba8:
	/* 0x1ba8: mov    ebp,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_1bad:
	/* 0x1bad: jmp    1c78 <trace_ret_arch_prctl+0x1c78> */
	return 7288ULL;
x86_l_1bb2:
	/* 0x1bb2: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bba:
	/* 0x1bba: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1bc0:
	/* 0x1bc0: ja     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7384ULL;
	}
x86_l_1bc6:
	/* 0x1bc6: mov    BYTE PTR [r14+rax*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519555ULL);
x86_l_1bcf:
	/* 0x1bcf: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1bd7:
	/* 0x1bd7: mov    WORD PTR [r14+0x7d92],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32146ULL);
x86_l_1bdf:
	/* 0x1bdf: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1be5:
	/* 0x1be5: ja     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7384ULL;
	}
x86_l_1beb:
	/* 0x1beb: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1bef:
	/* 0x1bef: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1c00:
	/* 0x1c00: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c08:
	/* 0x1c08: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1c0c:
	/* 0x1c0c: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1c13:
	/* 0x1c13: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1c18:
	/* 0x1c18: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1c1b:
	/* 0x1c1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1d:
	/* 0x1c1d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1c20:
	/* 0x1c20: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1c23:
	/* 0x1c23: jle    1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 7384ULL;
	}
x86_l_1c29:
	/* 0x1c29: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c31:
	/* 0x1c31: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1c37:
	/* 0x1c37: ja     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7384ULL;
	}
x86_l_1c3d:
	/* 0x1c3d: mov    DWORD PTR [rax+r14*1+0x8a],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1c45:
	/* 0x1c45: add    r15w,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1c4d:
	/* 0x1c4d: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1c51:
	/* 0x1c51: jmp    1cc9 <trace_ret_arch_prctl+0x1cc9> */
	return 7369ULL;
x86_l_1c53:
	/* 0x1c53: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c5a:
	/* 0x1c5a: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c64:
	/* 0x1c64: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1c68:
	/* 0x1c68: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
	return 7275ULL;
}

static __noinline __u64 tracee_trace_ret_arch_prctl_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7275ULL: goto x86_l_1c6b;
	case 7281ULL: goto x86_l_1c71;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7291ULL: goto x86_l_1c7b;
	case 7296ULL: goto x86_l_1c80;
	case 7304ULL: goto x86_l_1c88;
	case 7310ULL: goto x86_l_1c8e;
	case 7312ULL: goto x86_l_1c90;
	case 7315ULL: goto x86_l_1c93;
	case 7319ULL: goto x86_l_1c97;
	case 7321ULL: goto x86_l_1c99;
	case 7330ULL: goto x86_l_1ca2;
	case 7334ULL: goto x86_l_1ca6;
	case 7341ULL: goto x86_l_1cad;
	case 7343ULL: goto x86_l_1caf;
	case 7347ULL: goto x86_l_1cb3;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7364ULL: goto x86_l_1cc4;
	case 7367ULL: goto x86_l_1cc7;
	case 7369ULL: goto x86_l_1cc9;
	case 7377ULL: goto x86_l_1cd1;
	case 7384ULL: goto x86_l_1cd8;
	case 7391ULL: goto x86_l_1cdf;
	case 7395ULL: goto x86_l_1ce3;
	case 7398ULL: goto x86_l_1ce6;
	case 7401ULL: goto x86_l_1ce9;
	case 7407ULL: goto x86_l_1cef;
	case 7409ULL: goto x86_l_1cf1;
	case 7415ULL: goto x86_l_1cf7;
	case 7418ULL: goto x86_l_1cfa;
	case 7420ULL: goto x86_l_1cfc;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7437ULL: goto x86_l_1d0d;
	case 7444ULL: goto x86_l_1d14;
	case 7450ULL: goto x86_l_1d1a;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7459ULL: goto x86_l_1d23;
	case 7463ULL: goto x86_l_1d27;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7475ULL: goto x86_l_1d33;
	case 7478ULL: goto x86_l_1d36;
	case 7484ULL: goto x86_l_1d3c;
	case 7492ULL: goto x86_l_1d44;
	case 7498ULL: goto x86_l_1d4a;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7522ULL: goto x86_l_1d62;
	case 7528ULL: goto x86_l_1d68;
	case 7531ULL: goto x86_l_1d6b;
	case 7537ULL: goto x86_l_1d71;
	case 7540ULL: goto x86_l_1d74;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7585ULL: goto x86_l_1da1;
	case 7588ULL: goto x86_l_1da4;
	case 7594ULL: goto x86_l_1daa;
	case 7597ULL: goto x86_l_1dad;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7621ULL: goto x86_l_1dc5;
	case 7627ULL: goto x86_l_1dcb;
	case 7633ULL: goto x86_l_1dd1;
	case 7642ULL: goto x86_l_1dda;
	case 7650ULL: goto x86_l_1de2;
	case 7658ULL: goto x86_l_1dea;
	case 7664ULL: goto x86_l_1df0;
	case 7670ULL: goto x86_l_1df6;
	case 7674ULL: goto x86_l_1dfa;
	case 7681ULL: goto x86_l_1e01;
	case 7686ULL: goto x86_l_1e06;
	case 7691ULL: goto x86_l_1e0b;
	case 7699ULL: goto x86_l_1e13;
	case 7703ULL: goto x86_l_1e17;
	case 7710ULL: goto x86_l_1e1e;
	case 7715ULL: goto x86_l_1e23;
	case 7718ULL: goto x86_l_1e26;
	case 7720ULL: goto x86_l_1e28;
	case 7723ULL: goto x86_l_1e2b;
	case 7726ULL: goto x86_l_1e2e;
	case 7732ULL: goto x86_l_1e34;
	case 7740ULL: goto x86_l_1e3c;
	case 7746ULL: goto x86_l_1e42;
	case 7752ULL: goto x86_l_1e48;
	case 7760ULL: goto x86_l_1e50;
	case 7768ULL: goto x86_l_1e58;
	case 7772ULL: goto x86_l_1e5c;
	case 7774ULL: goto x86_l_1e5e;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7804ULL: goto x86_l_1e7c;
	case 7806ULL: goto x86_l_1e7e;
	case 7811ULL: goto x86_l_1e83;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7827ULL: goto x86_l_1e93;
	case 7833ULL: goto x86_l_1e99;
	case 7835ULL: goto x86_l_1e9b;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7853ULL: goto x86_l_1ead;
	case 7857ULL: goto x86_l_1eb1;
	case 7864ULL: goto x86_l_1eb8;
	case 7866ULL: goto x86_l_1eba;
	case 7870ULL: goto x86_l_1ebe;
	case 7877ULL: goto x86_l_1ec5;
	case 7882ULL: goto x86_l_1eca;
	case 7885ULL: goto x86_l_1ecd;
	case 7887ULL: goto x86_l_1ecf;
	case 7890ULL: goto x86_l_1ed2;
	case 7892ULL: goto x86_l_1ed4;
	case 7900ULL: goto x86_l_1edc;
	case 7907ULL: goto x86_l_1ee3;
	case 7914ULL: goto x86_l_1eea;
	case 7918ULL: goto x86_l_1eee;
	case 7921ULL: goto x86_l_1ef1;
	case 7924ULL: goto x86_l_1ef4;
	case 7930ULL: goto x86_l_1efa;
	case 7932ULL: goto x86_l_1efc;
	case 7938ULL: goto x86_l_1f02;
	case 7941ULL: goto x86_l_1f05;
	case 7943ULL: goto x86_l_1f07;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7960ULL: goto x86_l_1f18;
	case 7967ULL: goto x86_l_1f1f;
	case 7973ULL: goto x86_l_1f25;
	case 7977ULL: goto x86_l_1f29;
	case 7979ULL: goto x86_l_1f2b;
	case 7982ULL: goto x86_l_1f2e;
	case 7986ULL: goto x86_l_1f32;
	case 7992ULL: goto x86_l_1f38;
	case 7994ULL: goto x86_l_1f3a;
	case 7998ULL: goto x86_l_1f3e;
	case 8001ULL: goto x86_l_1f41;
	case 8007ULL: goto x86_l_1f47;
	case 8015ULL: goto x86_l_1f4f;
	case 8021ULL: goto x86_l_1f55;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8035ULL: goto x86_l_1f63;
	case 8037ULL: goto x86_l_1f65;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8051ULL: goto x86_l_1f73;
	case 8054ULL: goto x86_l_1f76;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8092ULL: goto x86_l_1f9c;
	case 8094ULL: goto x86_l_1f9e;
	case 8099ULL: goto x86_l_1fa3;
	case 8102ULL: goto x86_l_1fa6;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8126ULL: goto x86_l_1fbe;
	case 8131ULL: goto x86_l_1fc3;
	case 8136ULL: goto x86_l_1fc8;
	case 8144ULL: goto x86_l_1fd0;
	case 8150ULL: goto x86_l_1fd6;
	case 8156ULL: goto x86_l_1fdc;
	case 8165ULL: goto x86_l_1fe5;
	case 8173ULL: goto x86_l_1fed;
	case 8181ULL: goto x86_l_1ff5;
	case 8187ULL: goto x86_l_1ffb;
	case 8193ULL: goto x86_l_2001;
	case 8197ULL: goto x86_l_2005;
	case 8204ULL: goto x86_l_200c;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8222ULL: goto x86_l_201e;
	case 8226ULL: goto x86_l_2022;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8241ULL: goto x86_l_2031;
	case 8243ULL: goto x86_l_2033;
	case 8246ULL: goto x86_l_2036;
	case 8249ULL: goto x86_l_2039;
	case 8255ULL: goto x86_l_203f;
	case 8263ULL: goto x86_l_2047;
	case 8269ULL: goto x86_l_204d;
	case 8275ULL: goto x86_l_2053;
	case 8283ULL: goto x86_l_205b;
	case 8291ULL: goto x86_l_2063;
	case 8295ULL: goto x86_l_2067;
	case 8297ULL: goto x86_l_2069;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8314ULL: goto x86_l_207a;
	case 8318ULL: goto x86_l_207e;
	case 8321ULL: goto x86_l_2081;
	case 8327ULL: goto x86_l_2087;
	case 8329ULL: goto x86_l_2089;
	case 8334ULL: goto x86_l_208e;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8350ULL: goto x86_l_209e;
	case 8356ULL: goto x86_l_20a4;
	case 8358ULL: goto x86_l_20a6;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8367ULL: goto x86_l_20af;
	case 8376ULL: goto x86_l_20b8;
	case 8380ULL: goto x86_l_20bc;
	case 8387ULL: goto x86_l_20c3;
	case 8389ULL: goto x86_l_20c5;
	case 8393ULL: goto x86_l_20c9;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8413ULL: goto x86_l_20dd;
	case 8415ULL: goto x86_l_20df;
	case 8423ULL: goto x86_l_20e7;
	case 8430ULL: goto x86_l_20ee;
	case 8437ULL: goto x86_l_20f5;
	case 8444ULL: goto x86_l_20fc;
	case 8447ULL: goto x86_l_20ff;
	case 8455ULL: goto x86_l_2107;
	case 8462ULL: goto x86_l_210e;
	case 8468ULL: goto x86_l_2114;
	case 8470ULL: goto x86_l_2116;
	case 8473ULL: goto x86_l_2119;
	case 8475ULL: goto x86_l_211b;
	case 8481ULL: goto x86_l_2121;
	case 8485ULL: goto x86_l_2125;
	case 8488ULL: goto x86_l_2128;
	case 8490ULL: goto x86_l_212a;
	case 8496ULL: goto x86_l_2130;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8505ULL: goto x86_l_2139;
	case 8511ULL: goto x86_l_213f;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8528ULL: goto x86_l_2150;
	case 8531ULL: goto x86_l_2153;
	case 8535ULL: goto x86_l_2157;
	case 8538ULL: goto x86_l_215a;
	case 8548ULL: goto x86_l_2164;
	case 8551ULL: goto x86_l_2167;
	case 8555ULL: goto x86_l_216b;
	case 8558ULL: goto x86_l_216e;
	case 8566ULL: goto x86_l_2176;
	case 8572ULL: goto x86_l_217c;
	case 8574ULL: goto x86_l_217e;
	case 8581ULL: goto x86_l_2185;
	case 8585ULL: goto x86_l_2189;
	case 8592ULL: goto x86_l_2190;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8607ULL: goto x86_l_219f;
	case 8609ULL: goto x86_l_21a1;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8617ULL: goto x86_l_21a9;
	case 8625ULL: goto x86_l_21b1;
	case 8632ULL: goto x86_l_21b8;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8658ULL: goto x86_l_21d2;
	case 8663ULL: goto x86_l_21d7;
	case 8666ULL: goto x86_l_21da;
	case 8668ULL: goto x86_l_21dc;
	case 8673ULL: goto x86_l_21e1;
	case 8678ULL: goto x86_l_21e6;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8697ULL: goto x86_l_21f9;
	case 8702ULL: goto x86_l_21fe;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8713ULL: goto x86_l_2209;
	case 8718ULL: goto x86_l_220e;
	case 8723ULL: goto x86_l_2213;
	case 8728ULL: goto x86_l_2218;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8766ULL: goto x86_l_223e;
	case 8770ULL: goto x86_l_2242;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8793ULL: goto x86_l_2259;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8818ULL: goto x86_l_2272;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8845ULL: goto x86_l_228d;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8875ULL: goto x86_l_22ab;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8904ULL: goto x86_l_22c8;
	case 8909ULL: goto x86_l_22cd;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8955ULL: goto x86_l_22fb;
	case 8960ULL: goto x86_l_2300;
	case 8963ULL: goto x86_l_2303;
	case 8965ULL: goto x86_l_2305;
	case 8969ULL: goto x86_l_2309;
	case 8973ULL: goto x86_l_230d;
	case 8977ULL: goto x86_l_2311;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9003ULL: goto x86_l_232b;
	case 9007ULL: goto x86_l_232f;
	case 9011ULL: goto x86_l_2333;
	case 9016ULL: goto x86_l_2338;
	case 9021ULL: goto x86_l_233d;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9034ULL: goto x86_l_234a;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c6b:
	/* 0x1c6b: jae    1b31 <trace_ret_arch_prctl+0x1b31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6961ULL;
	}
x86_l_1c71:
	/* 0x1c71: jmp    1cd8 <trace_ret_arch_prctl+0x1cd8> */
	goto x86_l_1cd8;
x86_l_1c73:
	/* 0x1c73: mov    ebp,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 110ULL);
x86_l_1c78:
	/* 0x1c78: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1c7b:
	/* 0x1c7b: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c80:
	/* 0x1c80: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1c88:
	/* 0x1c88: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1c8e:
	/* 0x1c8e: ja     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cd8;
	}
x86_l_1c90:
	/* 0x1c90: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1c93:
	/* 0x1c93: lea    rax,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1c97:
	/* 0x1c97: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1c99:
	/* 0x1c99: mov    BYTE PTR [r14+rcx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 588410519555ULL);
x86_l_1ca2:
	/* 0x1ca2: lea    r15d,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1ca6:
	/* 0x1ca6: cmp    r15d,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32000ULL);
x86_l_1cad:
	/* 0x1cad: ja     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1cd8;
	}
x86_l_1caf:
	/* 0x1caf: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1cb3:
	/* 0x1cb3: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1cba:
	/* 0x1cba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1cc2:
	/* 0x1cc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc4:
	/* 0x1cc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cc7:
	/* 0x1cc7: js     1cd8 <trace_ret_arch_prctl+0x1cd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1cd8;
	}
x86_l_1cc9:
	/* 0x1cc9: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1cd1:
	/* 0x1cd1: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    rcx,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_1cdf:
	/* 0x1cdf: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1ce3:
	/* 0x1ce3: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ce6:
	/* 0x1ce6: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1ce9:
	/* 0x1ce9: ja     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee3;
	}
x86_l_1cef:
	/* 0x1cef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cf1:
	/* 0x1cf1: je     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee3;
	}
x86_l_1cf7:
	/* 0x1cf7: movzx  edi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1cfa:
	/* 0x1cfa: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_1cfc:
	/* 0x1cfc: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1d03:
	/* 0x1d03: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1d08:
	/* 0x1d08: shlx   rsi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_1d0d:
	/* 0x1d0d: lea    rbx,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d14:
	/* 0x1d14: mov    r8d,0xa880 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 43136ULL);
x86_l_1d1a:
	/* 0x1d1a: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_1d1e:
	/* 0x1d1e: jae    1d23 <trace_ret_arch_prctl+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d23;
	}
x86_l_1d20:
	/* 0x1d20: mov    rbx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d23:
	/* 0x1d23: mov    r15d,DWORD PTR [rdx+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1d27:
	/* 0x1d27: test   esi,0x177e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 6014ULL);
x86_l_1d2d:
	/* 0x1d2d: je     1d55 <trace_ret_arch_prctl+0x1d55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d55;
	}
x86_l_1d2f:
	/* 0x1d2f: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1d33:
	/* 0x1d33: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1d36:
	/* 0x1d36: jb     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ee3;
	}
x86_l_1d3c:
	/* 0x1d3c: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1d44:
	/* 0x1d44: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1d4a:
	/* 0x1d4a: jbe    1e9b <trace_ret_arch_prctl+0x1e9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e9b;
	}
x86_l_1d50:
	/* 0x1d50: jmp    1ee3 <trace_ret_arch_prctl+0x1ee3> */
	goto x86_l_1ee3;
x86_l_1d55:
	/* 0x1d55: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1d58:
	/* 0x1d58: je     1dbd <trace_ret_arch_prctl+0x1dbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dbd;
	}
x86_l_1d5a:
	/* 0x1d5a: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1d5f:
	/* 0x1d5f: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1d62:
	/* 0x1d62: je     1e83 <trace_ret_arch_prctl+0x1e83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e83;
	}
x86_l_1d68:
	/* 0x1d68: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1d6b:
	/* 0x1d6b: jne    1e6a <trace_ret_arch_prctl+0x1e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e6a;
	}
x86_l_1d71:
	/* 0x1d71: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1d74:
	/* 0x1d74: je     1e5e <trace_ret_arch_prctl+0x1e5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5e;
	}
x86_l_1d7a:
	/* 0x1d7a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d84:
	/* 0x1d84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d89:
	/* 0x1d89: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d91:
	/* 0x1d91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d93:
	/* 0x1d93: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1d98:
	/* 0x1d98: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d9b:
	/* 0x1d9b: je     1e7e <trace_ret_arch_prctl+0x1e7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e7e;
	}
x86_l_1da1:
	/* 0x1da1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1da4:
	/* 0x1da4: je     1e83 <trace_ret_arch_prctl+0x1e83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e83;
	}
x86_l_1daa:
	/* 0x1daa: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1dad:
	/* 0x1dad: jne    1e6a <trace_ret_arch_prctl+0x1e6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e6a;
	}
x86_l_1db3:
	/* 0x1db3: mov    ebp,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_1db8:
	/* 0x1db8: jmp    1e83 <trace_ret_arch_prctl+0x1e83> */
	goto x86_l_1e83;
x86_l_1dbd:
	/* 0x1dbd: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1dc5:
	/* 0x1dc5: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1dcb:
	/* 0x1dcb: ja     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee3;
	}
x86_l_1dd1:
	/* 0x1dd1: mov    BYTE PTR [r14+rax*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519556ULL);
x86_l_1dda:
	/* 0x1dda: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1de2:
	/* 0x1de2: mov    WORD PTR [r14+0x7d94],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32148ULL);
x86_l_1dea:
	/* 0x1dea: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1df0:
	/* 0x1df0: ja     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee3;
	}
x86_l_1df6:
	/* 0x1df6: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1dfa:
	/* 0x1dfa: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e01:
	/* 0x1e01: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1e06:
	/* 0x1e06: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e0b:
	/* 0x1e0b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e13:
	/* 0x1e13: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1e17:
	/* 0x1e17: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1e1e:
	/* 0x1e1e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1e23:
	/* 0x1e23: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e26:
	/* 0x1e26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e28:
	/* 0x1e28: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1e2b:
	/* 0x1e2b: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1e2e:
	/* 0x1e2e: jle    1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ee3;
	}
x86_l_1e34:
	/* 0x1e34: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e3c:
	/* 0x1e3c: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1e42:
	/* 0x1e42: ja     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee3;
	}
x86_l_1e48:
	/* 0x1e48: mov    DWORD PTR [rax+r14*1+0x8a],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1e50:
	/* 0x1e50: add    r15w,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e58:
	/* 0x1e58: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1e5c:
	/* 0x1e5c: jmp    1ed4 <trace_ret_arch_prctl+0x1ed4> */
	goto x86_l_1ed4;
x86_l_1e5e:
	/* 0x1e5e: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e65:
	/* 0x1e65: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e6f:
	/* 0x1e6f: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1e73:
	/* 0x1e73: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1e76:
	/* 0x1e76: jae    1d3c <trace_ret_arch_prctl+0x1d3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d3c;
	}
x86_l_1e7c:
	/* 0x1e7c: jmp    1ee3 <trace_ret_arch_prctl+0x1ee3> */
	goto x86_l_1ee3;
x86_l_1e7e:
	/* 0x1e7e: mov    ebp,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 110ULL);
x86_l_1e83:
	/* 0x1e83: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1e86:
	/* 0x1e86: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8b:
	/* 0x1e8b: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e93:
	/* 0x1e93: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1e99:
	/* 0x1e99: ja     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee3;
	}
x86_l_1e9b:
	/* 0x1e9b: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1e9e:
	/* 0x1e9e: lea    rax,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1ea2:
	/* 0x1ea2: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1ea4:
	/* 0x1ea4: mov    BYTE PTR [r14+rcx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 588410519556ULL);
x86_l_1ead:
	/* 0x1ead: lea    r15d,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1eb1:
	/* 0x1eb1: cmp    r15d,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32000ULL);
x86_l_1eb8:
	/* 0x1eb8: ja     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ee3;
	}
x86_l_1eba:
	/* 0x1eba: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ebe:
	/* 0x1ebe: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ec5:
	/* 0x1ec5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eca:
	/* 0x1eca: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ecd:
	/* 0x1ecd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ecf:
	/* 0x1ecf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed2:
	/* 0x1ed2: js     1ee3 <trace_ret_arch_prctl+0x1ee3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ee3;
	}
x86_l_1ed4:
	/* 0x1ed4: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1edc:
	/* 0x1edc: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    rcx,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_1eea:
	/* 0x1eea: shr    rcx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_1eee:
	/* 0x1eee: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ef1:
	/* 0x1ef1: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1ef4:
	/* 0x1ef4: ja     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20ee;
	}
x86_l_1efa:
	/* 0x1efa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1efc:
	/* 0x1efc: je     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20ee;
	}
x86_l_1f02:
	/* 0x1f02: movzx  edi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f05:
	/* 0x1f05: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_1f07:
	/* 0x1f07: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1f13:
	/* 0x1f13: shlx   rsi,rsi,rdi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_64, X86_RDI, X86_ALU_SHL);
x86_l_1f18:
	/* 0x1f18: lea    rbx,[rbp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f1f:
	/* 0x1f1f: mov    r8d,0xa880 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 43136ULL);
x86_l_1f25:
	/* 0x1f25: bt     r8,rdi */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_1f29:
	/* 0x1f29: jae    1f2e <trace_ret_arch_prctl+0x1f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f2e;
	}
x86_l_1f2b:
	/* 0x1f2b: mov    rbx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    r15d,DWORD PTR [rdx+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1f32:
	/* 0x1f32: test   esi,0x177e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 6014ULL);
x86_l_1f38:
	/* 0x1f38: je     1f60 <trace_ret_arch_prctl+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f60;
	}
x86_l_1f3a:
	/* 0x1f3a: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_1f3e:
	/* 0x1f3e: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_1f41:
	/* 0x1f41: jb     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_20ee;
	}
x86_l_1f47:
	/* 0x1f47: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f4f:
	/* 0x1f4f: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_1f55:
	/* 0x1f55: jbe    20a6 <trace_ret_arch_prctl+0x20a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_20a6;
	}
x86_l_1f5b:
	/* 0x1f5b: jmp    20ee <trace_ret_arch_prctl+0x20ee> */
	goto x86_l_20ee;
x86_l_1f60:
	/* 0x1f60: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1f63:
	/* 0x1f63: je     1fc8 <trace_ret_arch_prctl+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fc8;
	}
x86_l_1f65:
	/* 0x1f65: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_1f6a:
	/* 0x1f6a: cmp    eax,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1f6d:
	/* 0x1f6d: je     208e <trace_ret_arch_prctl+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_208e;
	}
x86_l_1f73:
	/* 0x1f73: cmp    eax,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 13ULL);
x86_l_1f76:
	/* 0x1f76: jne    2075 <trace_ret_arch_prctl+0x2075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2075;
	}
x86_l_1f7c:
	/* 0x1f7c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1f7f:
	/* 0x1f7f: je     2069 <trace_ret_arch_prctl+0x2069> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2069;
	}
x86_l_1f85:
	/* 0x1f85: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f94:
	/* 0x1f94: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1f99:
	/* 0x1f99: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1f9c:
	/* 0x1f9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f9e:
	/* 0x1f9e: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1fa3:
	/* 0x1fa3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fa6:
	/* 0x1fa6: je     2089 <trace_ret_arch_prctl+0x2089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2089;
	}
x86_l_1fac:
	/* 0x1fac: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1faf:
	/* 0x1faf: je     208e <trace_ret_arch_prctl+0x208e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_208e;
	}
x86_l_1fb5:
	/* 0x1fb5: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1fb8:
	/* 0x1fb8: jne    2075 <trace_ret_arch_prctl+0x2075> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2075;
	}
x86_l_1fbe:
	/* 0x1fbe: mov    ebp,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 28ULL);
x86_l_1fc3:
	/* 0x1fc3: jmp    208e <trace_ret_arch_prctl+0x208e> */
	goto x86_l_208e;
x86_l_1fc8:
	/* 0x1fc8: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fd0:
	/* 0x1fd0: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1fd6:
	/* 0x1fd6: ja     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20ee;
	}
x86_l_1fdc:
	/* 0x1fdc: mov    BYTE PTR [r14+rax*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519557ULL);
x86_l_1fe5:
	/* 0x1fe5: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fed:
	/* 0x1fed: mov    WORD PTR [r14+0x7d96],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32150ULL);
x86_l_1ff5:
	/* 0x1ff5: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_1ffb:
	/* 0x1ffb: ja     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20ee;
	}
x86_l_2001:
	/* 0x2001: lea    rcx,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2005:
	/* 0x2005: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_200c:
	/* 0x200c: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_2011:
	/* 0x2011: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2016:
	/* 0x2016: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_201e:
	/* 0x201e: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2022:
	/* 0x2022: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_2029:
	/* 0x2029: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_202e:
	/* 0x202e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2031:
	/* 0x2031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2033:
	/* 0x2033: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2036:
	/* 0x2036: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_2039:
	/* 0x2039: jle    20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_20ee;
	}
x86_l_203f:
	/* 0x203f: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2047:
	/* 0x2047: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_204d:
	/* 0x204d: ja     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20ee;
	}
x86_l_2053:
	/* 0x2053: mov    DWORD PTR [rax+r14*1+0x8a],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_205b:
	/* 0x205b: add    r15w,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2063:
	/* 0x2063: add    r15d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_2067:
	/* 0x2067: jmp    20df <trace_ret_arch_prctl+0x20df> */
	goto x86_l_20df;
x86_l_2069:
	/* 0x2069: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2070:
	/* 0x2070: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2075:
	/* 0x2075: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_207a:
	/* 0x207a: lea    eax,[r15-0x6f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551505ULL);
x86_l_207e:
	/* 0x207e: cmp    eax,0xffffff92 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967186ULL);
x86_l_2081:
	/* 0x2081: jae    1f47 <trace_ret_arch_prctl+0x1f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f47;
	}
x86_l_2087:
	/* 0x2087: jmp    20ee <trace_ret_arch_prctl+0x20ee> */
	goto x86_l_20ee;
x86_l_2089:
	/* 0x2089: mov    ebp,0x6e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 110ULL);
x86_l_208e:
	/* 0x208e: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_2091:
	/* 0x2091: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2096:
	/* 0x2096: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_209e:
	/* 0x209e: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_20a4:
	/* 0x20a4: ja     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20ee;
	}
x86_l_20a6:
	/* 0x20a6: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_20a9:
	/* 0x20a9: lea    rax,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_20ad:
	/* 0x20ad: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_20af:
	/* 0x20af: mov    BYTE PTR [r14+rcx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 588410519557ULL);
x86_l_20b8:
	/* 0x20b8: lea    r15d,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_20bc:
	/* 0x20bc: cmp    r15d,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32000ULL);
x86_l_20c3:
	/* 0x20c3: ja     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_20ee;
	}
x86_l_20c5:
	/* 0x20c5: lea    rdi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_20c9:
	/* 0x20c9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_20d0:
	/* 0x20d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20d5:
	/* 0x20d5: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_20d8:
	/* 0x20d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20da:
	/* 0x20da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20dd:
	/* 0x20dd: js     20ee <trace_ret_arch_prctl+0x20ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_20ee;
	}
x86_l_20df:
	/* 0x20df: mov    WORD PTR [r14+0x7d8a],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_20e7:
	/* 0x20e7: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_20ee:
	/* 0x20ee: mov    rax,QWORD PTR [r14+0x7de0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_20f5:
	/* 0x20f5: mov    rcx,QWORD PTR [rbp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_20fc:
	/* 0x20fc: mov    QWORD PTR [r14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ff:
	/* 0x20ff: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2107:
	/* 0x2107: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_210e:
	/* 0x210e: ja     21b8 <trace_ret_arch_prctl+0x21b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21b8;
	}
x86_l_2114:
	/* 0x2114: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2116:
	/* 0x2116: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2119:
	/* 0x2119: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_211b:
	/* 0x211b: and    edx,0xff00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 65280ULL);
x86_l_2121:
	/* 0x2121: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_2125:
	/* 0x2125: sbb    cl,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SBB, 255ULL);
x86_l_2128:
	/* 0x2128: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_212a:
	/* 0x212a: and    edx,0xff0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16711680ULL);
x86_l_2130:
	/* 0x2130: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_2134:
	/* 0x2134: sbb    cl,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SBB, 255ULL);
x86_l_2137:
	/* 0x2137: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_2139:
	/* 0x2139: and    edx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_213f:
	/* 0x213f: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_2143:
	/* 0x2143: sbb    cl,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SBB, 255ULL);
x86_l_2146:
	/* 0x2146: movabs rdx,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1095216660480ULL);
x86_l_2150:
	/* 0x2150: and    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2153:
	/* 0x2153: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_2157:
	/* 0x2157: sbb    cl,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SBB, 255ULL);
x86_l_215a:
	/* 0x215a: movabs rdx,0xff0000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 280375465082880ULL);
x86_l_2164:
	/* 0x2164: and    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2167:
	/* 0x2167: cmp    rdx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 1ULL);
x86_l_216b:
	/* 0x216b: sbb    cl,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SBB, 255ULL);
x86_l_216e:
	/* 0x216e: mov    BYTE PTR [r14+rbx*1+0x89],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 137ULL);
x86_l_2176:
	/* 0x2176: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_217c:
	/* 0x217c: ja     21b8 <trace_ret_arch_prctl+0x21b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21b8;
	}
x86_l_217e:
	/* 0x217e: lea    rdx,[rbp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2185:
	/* 0x2185: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2189:
	/* 0x2189: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_2190:
	/* 0x2190: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2195:
	/* 0x2195: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_219a:
	/* 0x219a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_219f:
	/* 0x219f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a1:
	/* 0x21a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21a4:
	/* 0x21a4: js     21b8 <trace_ret_arch_prctl+0x21b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_21b8;
	}
x86_l_21a6:
	/* 0x21a6: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_21a9:
	/* 0x21a9: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_21b1:
	/* 0x21b1: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_21b8:
	/* 0x21b8: mov    r13,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_21bf:
	/* 0x21bf: lea    r15,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21c3:
	/* 0x21c3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c8:
	/* 0x21c8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21cd:
	/* 0x21cd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21d2:
	/* 0x21d2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d7:
	/* 0x21d7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21da:
	/* 0x21da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21dc:
	/* 0x21dc: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21e1:
	/* 0x21e1: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_21e6:
	/* 0x21e6: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21ea:
	/* 0x21ea: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21ef:
	/* 0x21ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_21f4:
	/* 0x21f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21f9:
	/* 0x21f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21fe:
	/* 0x21fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2200:
	/* 0x2200: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2205:
	/* 0x2205: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2209:
	/* 0x2209: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_220e:
	/* 0x220e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2213:
	/* 0x2213: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2218:
	/* 0x2218: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_221d:
	/* 0x221d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221f:
	/* 0x221f: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2224:
	/* 0x2224: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2228:
	/* 0x2228: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_222d:
	/* 0x222d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2232:
	/* 0x2232: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2237:
	/* 0x2237: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_223c:
	/* 0x223c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223e:
	/* 0x223e: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2242:
	/* 0x2242: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2246:
	/* 0x2246: lea    r12,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_224a:
	/* 0x224a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_224f:
	/* 0x224f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2254:
	/* 0x2254: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2259:
	/* 0x2259: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_225e:
	/* 0x225e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2261:
	/* 0x2261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2263:
	/* 0x2263: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2268:
	/* 0x2268: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_226d:
	/* 0x226d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2272:
	/* 0x2272: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2277:
	/* 0x2277: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_227c:
	/* 0x227c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_227f:
	/* 0x227f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2281:
	/* 0x2281: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2285:
	/* 0x2285: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2289:
	/* 0x2289: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_228d:
	/* 0x228d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2291:
	/* 0x2291: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2296:
	/* 0x2296: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_229b:
	/* 0x229b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22a0:
	/* 0x22a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22a5:
	/* 0x22a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a7:
	/* 0x22a7: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ab:
	/* 0x22ab: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_22af:
	/* 0x22af: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b4:
	/* 0x22b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22b9:
	/* 0x22b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22be:
	/* 0x22be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c3:
	/* 0x22c3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22c6:
	/* 0x22c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c8:
	/* 0x22c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22cd:
	/* 0x22cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22d1:
	/* 0x22d1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22d6:
	/* 0x22d6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22db:
	/* 0x22db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22e0:
	/* 0x22e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e5:
	/* 0x22e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e7:
	/* 0x22e7: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ec:
	/* 0x22ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f1:
	/* 0x22f1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22f6:
	/* 0x22f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22fb:
	/* 0x22fb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2300:
	/* 0x2300: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2303:
	/* 0x2303: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2305:
	/* 0x2305: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2309:
	/* 0x2309: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_230d:
	/* 0x230d: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2311:
	/* 0x2311: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2315:
	/* 0x2315: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_231a:
	/* 0x231a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_231f:
	/* 0x231f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2324:
	/* 0x2324: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2329:
	/* 0x2329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232b:
	/* 0x232b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_232f:
	/* 0x232f: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2333:
	/* 0x2333: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2338:
	/* 0x2338: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_233d:
	/* 0x233d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2342:
	/* 0x2342: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2347:
	/* 0x2347: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_234a:
	/* 0x234a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_234c:
	/* 0x234c: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2351:
	/* 0x2351: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2356:
	/* 0x2356: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_235b:
	/* 0x235b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2360:
	/* 0x2360: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2365:
	/* 0x2365: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2368:
	/* 0x2368: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 9066ULL;
}

static __noinline __u64 tracee_trace_ret_arch_prctl_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9066ULL: goto x86_l_236a;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9078ULL: goto x86_l_2376;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9102ULL: goto x86_l_238e;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9118ULL: goto x86_l_239e;
	case 9123ULL: goto x86_l_23a3;
	case 9128ULL: goto x86_l_23a8;
	case 9133ULL: goto x86_l_23ad;
	case 9135ULL: goto x86_l_23af;
	case 9139ULL: goto x86_l_23b3;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9163ULL: goto x86_l_23cb;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9178ULL: goto x86_l_23da;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9196ULL: goto x86_l_23ec;
	case 9198ULL: goto x86_l_23ee;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9210ULL: goto x86_l_23fa;
	case 9214ULL: goto x86_l_23fe;
	case 9219ULL: goto x86_l_2403;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9234ULL: goto x86_l_2412;
	case 9236ULL: goto x86_l_2414;
	case 9241ULL: goto x86_l_2419;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9273ULL: goto x86_l_2439;
	case 9278ULL: goto x86_l_243e;
	case 9283ULL: goto x86_l_2443;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9326ULL: goto x86_l_246e;
	case 9328ULL: goto x86_l_2470;
	case 9332ULL: goto x86_l_2474;
	case 9336ULL: goto x86_l_2478;
	case 9340ULL: goto x86_l_247c;
	case 9344ULL: goto x86_l_2480;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9370ULL: goto x86_l_249a;
	case 9374ULL: goto x86_l_249e;
	case 9378ULL: goto x86_l_24a2;
	case 9385ULL: goto x86_l_24a9;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9404ULL: goto x86_l_24bc;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9460ULL: goto x86_l_24f4;
	case 9465ULL: goto x86_l_24f9;
	case 9470ULL: goto x86_l_24fe;
	case 9475ULL: goto x86_l_2503;
	case 9477ULL: goto x86_l_2505;
	case 9481ULL: goto x86_l_2509;
	case 9485ULL: goto x86_l_250d;
	case 9490ULL: goto x86_l_2512;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9510ULL: goto x86_l_2526;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9522ULL: goto x86_l_2532;
	case 9527ULL: goto x86_l_2537;
	case 9531ULL: goto x86_l_253b;
	case 9536ULL: goto x86_l_2540;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9562ULL: goto x86_l_255a;
	case 9567ULL: goto x86_l_255f;
	case 9571ULL: goto x86_l_2563;
	case 9575ULL: goto x86_l_2567;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9595ULL: goto x86_l_257b;
	case 9598ULL: goto x86_l_257e;
	case 9600ULL: goto x86_l_2580;
	case 9605ULL: goto x86_l_2585;
	case 9609ULL: goto x86_l_2589;
	case 9614ULL: goto x86_l_258e;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9629ULL: goto x86_l_259d;
	case 9632ULL: goto x86_l_25a0;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9654ULL: goto x86_l_25b6;
	case 9658ULL: goto x86_l_25ba;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9676ULL: goto x86_l_25cc;
	case 9681ULL: goto x86_l_25d1;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9703ULL: goto x86_l_25e7;
	case 9706ULL: goto x86_l_25ea;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9718ULL: goto x86_l_25f6;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9733ULL: goto x86_l_2605;
	case 9735ULL: goto x86_l_2607;
	case 9740ULL: goto x86_l_260c;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9765ULL: goto x86_l_2625;
	case 9768ULL: goto x86_l_2628;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9790ULL: goto x86_l_263e;
	case 9792ULL: goto x86_l_2640;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9812ULL: goto x86_l_2654;
	case 9815ULL: goto x86_l_2657;
	case 9817ULL: goto x86_l_2659;
	case 9825ULL: goto x86_l_2661;
	case 9829ULL: goto x86_l_2665;
	case 9837ULL: goto x86_l_266d;
	case 9839ULL: goto x86_l_266f;
	case 9846ULL: goto x86_l_2676;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9864ULL: goto x86_l_2688;
	case 9866ULL: goto x86_l_268a;
	case 9868ULL: goto x86_l_268c;
	case 9870ULL: goto x86_l_268e;
	case 9874ULL: goto x86_l_2692;
	case 9882ULL: goto x86_l_269a;
	case 9887ULL: goto x86_l_269f;
	case 9892ULL: goto x86_l_26a4;
	case 9895ULL: goto x86_l_26a7;
	case 9901ULL: goto x86_l_26ad;
	case 9905ULL: goto x86_l_26b1;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9922ULL: goto x86_l_26c2;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9933ULL: goto x86_l_26cd;
	case 9935ULL: goto x86_l_26cf;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9960ULL: goto x86_l_26e8;
	case 9962ULL: goto x86_l_26ea;
	case 9964ULL: goto x86_l_26ec;
	case 9971ULL: goto x86_l_26f3;
	case 9972ULL: goto x86_l_26f4;
	case 9974ULL: goto x86_l_26f6;
	case 9976ULL: goto x86_l_26f8;
	case 9978ULL: goto x86_l_26fa;
	case 9980ULL: goto x86_l_26fc;
	case 9981ULL: goto x86_l_26fd;
	case 9986ULL: goto x86_l_2702;
	case 9993ULL: goto x86_l_2709;
	case 9996ULL: goto x86_l_270c;
	case 10000ULL: goto x86_l_2710;
	case 10005ULL: goto x86_l_2715;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10017ULL: goto x86_l_2721;
	case 10020ULL: goto x86_l_2724;
	case 10022ULL: goto x86_l_2726;
	case 10028ULL: goto x86_l_272c;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10040ULL: goto x86_l_2738;
	default: return 0xffffffffffffffffULL;
	}
x86_l_236a:
	/* 0x236a: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236e:
	/* 0x236e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2372:
	/* 0x2372: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2376:
	/* 0x2376: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_237a:
	/* 0x237a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_237f:
	/* 0x237f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2384:
	/* 0x2384: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2389:
	/* 0x2389: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_238e:
	/* 0x238e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2390:
	/* 0x2390: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2395:
	/* 0x2395: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2399:
	/* 0x2399: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_239e:
	/* 0x239e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23a3:
	/* 0x23a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23a8:
	/* 0x23a8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23ad:
	/* 0x23ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23af:
	/* 0x23af: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b3:
	/* 0x23b3: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23b7:
	/* 0x23b7: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23bc:
	/* 0x23bc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_23c1:
	/* 0x23c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23c6:
	/* 0x23c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23cb:
	/* 0x23cb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23ce:
	/* 0x23ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d0:
	/* 0x23d0: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d5:
	/* 0x23d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23da:
	/* 0x23da: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23df:
	/* 0x23df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_23e4:
	/* 0x23e4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_23e9:
	/* 0x23e9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_23ec:
	/* 0x23ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ee:
	/* 0x23ee: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f2:
	/* 0x23f2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_23f6:
	/* 0x23f6: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_23fa:
	/* 0x23fa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_23fe:
	/* 0x23fe: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2403:
	/* 0x2403: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2408:
	/* 0x2408: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_240d:
	/* 0x240d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2412:
	/* 0x2412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2414:
	/* 0x2414: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2419:
	/* 0x2419: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_241d:
	/* 0x241d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2422:
	/* 0x2422: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2427:
	/* 0x2427: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_242c:
	/* 0x242c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2431:
	/* 0x2431: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2433:
	/* 0x2433: cmp    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_2437:
	/* 0x2437: jne    249e <trace_ret_arch_prctl+0x249e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_249e;
	}
x86_l_2439:
	/* 0x2439: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_243e:
	/* 0x243e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2443:
	/* 0x2443: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2448:
	/* 0x2448: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_244d:
	/* 0x244d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2450:
	/* 0x2450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2452:
	/* 0x2452: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2457:
	/* 0x2457: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_245c:
	/* 0x245c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2461:
	/* 0x2461: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2466:
	/* 0x2466: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_246b:
	/* 0x246b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_246e:
	/* 0x246e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2470:
	/* 0x2470: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2474:
	/* 0x2474: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_2478:
	/* 0x2478: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_247c:
	/* 0x247c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2480:
	/* 0x2480: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2485:
	/* 0x2485: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_248a:
	/* 0x248a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_248f:
	/* 0x248f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2494:
	/* 0x2494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2496:
	/* 0x2496: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_249a:
	/* 0x249a: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_249e:
	/* 0x249e: mov    DWORD PTR [r14+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24a2:
	/* 0x24a2: lea    r12,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_24a9:
	/* 0x24a9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ae:
	/* 0x24ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24b3:
	/* 0x24b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24b8:
	/* 0x24b8: lea    r15,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24bc:
	/* 0x24bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c1:
	/* 0x24c1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24c4:
	/* 0x24c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c6:
	/* 0x24c6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24cb:
	/* 0x24cb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24cf:
	/* 0x24cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d4:
	/* 0x24d4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_24d9:
	/* 0x24d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24de:
	/* 0x24de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24e3:
	/* 0x24e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e5:
	/* 0x24e5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ea:
	/* 0x24ea: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24ef:
	/* 0x24ef: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_24f4:
	/* 0x24f4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24f9:
	/* 0x24f9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24fe:
	/* 0x24fe: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2503:
	/* 0x2503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2505:
	/* 0x2505: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2509:
	/* 0x2509: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_250d:
	/* 0x250d: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_2512:
	/* 0x2512: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2514:
	/* 0x2514: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2518:
	/* 0x2518: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_251c:
	/* 0x251c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2521:
	/* 0x2521: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2526:
	/* 0x2526: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_252b:
	/* 0x252b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2530:
	/* 0x2530: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2532:
	/* 0x2532: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2537:
	/* 0x2537: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253b:
	/* 0x253b: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2540:
	/* 0x2540: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2544:
	/* 0x2544: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2549:
	/* 0x2549: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_254e:
	/* 0x254e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2553:
	/* 0x2553: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2558:
	/* 0x2558: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255a:
	/* 0x255a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_255f:
	/* 0x255f: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2563:
	/* 0x2563: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_2567:
	/* 0x2567: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256c:
	/* 0x256c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2571:
	/* 0x2571: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2576:
	/* 0x2576: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_257b:
	/* 0x257b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_257e:
	/* 0x257e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2580:
	/* 0x2580: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2585:
	/* 0x2585: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2589:
	/* 0x2589: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_258e:
	/* 0x258e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2593:
	/* 0x2593: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2598:
	/* 0x2598: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_259d:
	/* 0x259d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_25a0:
	/* 0x25a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a2:
	/* 0x25a2: test   BYTE PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_25a7:
	/* 0x25a7: je     25ae <trace_ret_arch_prctl+0x25ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ae;
	}
x86_l_25a9:
	/* 0x25a9: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_25ae:
	/* 0x25ae: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_25b6:
	/* 0x25b6: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_25ba:
	/* 0x25ba: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_25c2:
	/* 0x25c2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25c7:
	/* 0x25c7: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_25cc:
	/* 0x25cc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25d1:
	/* 0x25d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25d3:
	/* 0x25d3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d8:
	/* 0x25d8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25dd:
	/* 0x25dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25e2:
	/* 0x25e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25e7:
	/* 0x25e7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25ea:
	/* 0x25ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ec:
	/* 0x25ec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f1:
	/* 0x25f1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25f6:
	/* 0x25f6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_25fb:
	/* 0x25fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2600:
	/* 0x2600: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2605:
	/* 0x2605: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2607:
	/* 0x2607: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_260c:
	/* 0x260c: lea    rbx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2611:
	/* 0x2611: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_2616:
	/* 0x2616: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_261b:
	/* 0x261b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_261e:
	/* 0x261e: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2623:
	/* 0x2623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2625:
	/* 0x2625: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2628:
	/* 0x2628: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_262c:
	/* 0x262c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2631:
	/* 0x2631: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2636:
	/* 0x2636: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_263b:
	/* 0x263b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_263e:
	/* 0x263e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2640:
	/* 0x2640: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_2645:
	/* 0x2645: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_264a:
	/* 0x264a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_264f:
	/* 0x264f: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2654:
	/* 0x2654: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2657:
	/* 0x2657: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2659:
	/* 0x2659: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2661:
	/* 0x2661: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2665:
	/* 0x2665: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_266d:
	/* 0x266d: je     2692 <trace_ret_arch_prctl+0x2692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2692;
	}
x86_l_266f:
	/* 0x266f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_2676:
	/* 0x2676: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_267b:
	/* 0x267b: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_2680:
	/* 0x2680: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_2685:
	/* 0x2685: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2688:
	/* 0x2688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268a:
	/* 0x268a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_268c:
	/* 0x268c: js     2692 <trace_ret_arch_prctl+0x2692> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2692;
	}
x86_l_268e:
	/* 0x268e: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2692:
	/* 0x2692: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_269a:
	/* 0x269a: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_269f:
	/* 0x269f: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_26a4:
	/* 0x26a4: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_26a7:
	/* 0x26a7: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_26ad:
	/* 0x26ad: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_26b1:
	/* 0x26b1: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_26b8:
	/* 0x26b8: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_26bd:
	/* 0x26bd: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_26c2:
	/* 0x26c2: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_26c7:
	/* 0x26c7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_26ca:
	/* 0x26ca: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_26cd:
	/* 0x26cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26cf:
	/* 0x26cf: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&generic_sys_exit_tails)));
x86_l_26d6:
	/* 0x26d6: mov    ecx,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 158ULL);
x86_l_26db:
	/* 0x26db: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_26e0:
	/* 0x26e0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_26e3:
	/* 0x26e3: mov    edx,0x9e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 158ULL);
x86_l_26e8:
	/* 0x26e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26ea:
	/* 0x26ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26ec:
	/* 0x26ec: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_26f3:
	/* 0x26f3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_26f4:
	/* 0x26f4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_26f6:
	/* 0x26f6: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_26f8:
	/* 0x26f8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_26fa:
	/* 0x26fa: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_26fc:
	/* 0x26fc: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_26fd:
	/* 0x26fd: jmp    273d <trace_ret_arch_prctl+0x273d> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2702:
	/* 0x2702: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2709:
	/* 0x2709: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_270c:
	/* 0x270c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2710:
	/* 0x2710: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_2715:
	/* 0x2715: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_271a:
	/* 0x271a: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_271f:
	/* 0x271f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2721:
	/* 0x2721: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2724:
	/* 0x2724: jne    26ea <trace_ret_arch_prctl+0x26ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26ea;
	}
x86_l_2726:
	/* 0x2726: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_272c:
	/* 0x272c: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_2731:
	/* 0x2731: jmp    bd3 <trace_ret_arch_prctl+0xbd3> */
	return 3027ULL;
x86_l_2736:
	/* 0x2736: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2738:
	/* 0x2738: jmp    20f5 <trace_ret_arch_prctl+0x20f5> */
	return 8437ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_ret_arch_prctl_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 8600U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2150ULL)
			__x86_pc = tracee_trace_ret_arch_prctl_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2155ULL && __x86_pc <= 3822ULL)
			__x86_pc = tracee_trace_ret_arch_prctl_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3829ULL && __x86_pc <= 5402ULL)
			__x86_pc = tracee_trace_ret_arch_prctl_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5410ULL && __x86_pc <= 7272ULL)
			__x86_pc = tracee_trace_ret_arch_prctl_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7275ULL && __x86_pc <= 9064ULL)
			__x86_pc = tracee_trace_ret_arch_prctl_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9066ULL && __x86_pc <= 10040ULL)
			__x86_pc = tracee_trace_ret_arch_prctl_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

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
	case 190ULL: goto x86_l_be;
	case 197ULL: goto x86_l_c5;
	case 200ULL: goto x86_l_c8;
	case 205ULL: goto x86_l_cd;
	case 207ULL: goto x86_l_cf;
	case 210ULL: goto x86_l_d2;
	case 216ULL: goto x86_l_d8;
	case 219ULL: goto x86_l_db;
	case 226ULL: goto x86_l_e2;
	case 229ULL: goto x86_l_e5;
	case 234ULL: goto x86_l_ea;
	case 236ULL: goto x86_l_ec;
	case 239ULL: goto x86_l_ef;
	case 245ULL: goto x86_l_f5;
	case 248ULL: goto x86_l_f8;
	case 258ULL: goto x86_l_102;
	case 266ULL: goto x86_l_10a;
	case 277ULL: goto x86_l_115;
	case 288ULL: goto x86_l_120;
	case 299ULL: goto x86_l_12b;
	case 310ULL: goto x86_l_136;
	case 321ULL: goto x86_l_141;
	case 332ULL: goto x86_l_14c;
	case 343ULL: goto x86_l_157;
	case 354ULL: goto x86_l_162;
	case 361ULL: goto x86_l_169;
	case 369ULL: goto x86_l_171;
	case 377ULL: goto x86_l_179;
	case 385ULL: goto x86_l_181;
	case 393ULL: goto x86_l_189;
	case 401ULL: goto x86_l_191;
	case 409ULL: goto x86_l_199;
	case 417ULL: goto x86_l_1a1;
	case 425ULL: goto x86_l_1a9;
	case 433ULL: goto x86_l_1b1;
	case 441ULL: goto x86_l_1b9;
	case 449ULL: goto x86_l_1c1;
	case 457ULL: goto x86_l_1c9;
	case 465ULL: goto x86_l_1d1;
	case 470ULL: goto x86_l_1d6;
	case 472ULL: goto x86_l_1d8;
	case 476ULL: goto x86_l_1dc;
	case 480ULL: goto x86_l_1e0;
	case 484ULL: goto x86_l_1e4;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 499ULL: goto x86_l_1f3;
	case 503ULL: goto x86_l_1f7;
	case 508ULL: goto x86_l_1fc;
	case 510ULL: goto x86_l_1fe;
	case 515ULL: goto x86_l_203;
	case 519ULL: goto x86_l_207;
	case 523ULL: goto x86_l_20b;
	case 530ULL: goto x86_l_212;
	case 537ULL: goto x86_l_219;
	case 545ULL: goto x86_l_221;
	case 550ULL: goto x86_l_226;
	case 552ULL: goto x86_l_228;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 562ULL: goto x86_l_232;
	case 566ULL: goto x86_l_236;
	case 573ULL: goto x86_l_23d;
	case 580ULL: goto x86_l_244;
	case 588ULL: goto x86_l_24c;
	case 593ULL: goto x86_l_251;
	case 595ULL: goto x86_l_253;
	case 598ULL: goto x86_l_256;
	case 601ULL: goto x86_l_259;
	case 606ULL: goto x86_l_25e;
	case 612ULL: goto x86_l_264;
	case 618ULL: goto x86_l_26a;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 643ULL: goto x86_l_283;
	case 647ULL: goto x86_l_287;
	case 655ULL: goto x86_l_28f;
	case 662ULL: goto x86_l_296;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 674ULL: goto x86_l_2a2;
	case 677ULL: goto x86_l_2a5;
	case 683ULL: goto x86_l_2ab;
	case 686ULL: goto x86_l_2ae;
	case 690ULL: goto x86_l_2b2;
	case 694ULL: goto x86_l_2b6;
	case 705ULL: goto x86_l_2c1;
	case 716ULL: goto x86_l_2cc;
	case 727ULL: goto x86_l_2d7;
	case 738ULL: goto x86_l_2e2;
	case 749ULL: goto x86_l_2ed;
	case 760ULL: goto x86_l_2f8;
	case 771ULL: goto x86_l_303;
	case 782ULL: goto x86_l_30e;
	case 793ULL: goto x86_l_319;
	case 804ULL: goto x86_l_324;
	case 815ULL: goto x86_l_32f;
	case 826ULL: goto x86_l_33a;
	case 837ULL: goto x86_l_345;
	case 848ULL: goto x86_l_350;
	case 859ULL: goto x86_l_35b;
	case 870ULL: goto x86_l_366;
	case 881ULL: goto x86_l_371;
	case 892ULL: goto x86_l_37c;
	case 903ULL: goto x86_l_387;
	case 914ULL: goto x86_l_392;
	case 925ULL: goto x86_l_39d;
	case 936ULL: goto x86_l_3a8;
	case 947ULL: goto x86_l_3b3;
	case 958ULL: goto x86_l_3be;
	case 969ULL: goto x86_l_3c9;
	case 980ULL: goto x86_l_3d4;
	case 991ULL: goto x86_l_3df;
	case 1002ULL: goto x86_l_3ea;
	case 1013ULL: goto x86_l_3f5;
	case 1024ULL: goto x86_l_400;
	case 1032ULL: goto x86_l_408;
	case 1040ULL: goto x86_l_410;
	case 1048ULL: goto x86_l_418;
	case 1056ULL: goto x86_l_420;
	case 1064ULL: goto x86_l_428;
	case 1072ULL: goto x86_l_430;
	case 1080ULL: goto x86_l_438;
	case 1088ULL: goto x86_l_440;
	case 1096ULL: goto x86_l_448;
	case 1104ULL: goto x86_l_450;
	case 1112ULL: goto x86_l_458;
	case 1120ULL: goto x86_l_460;
	case 1128ULL: goto x86_l_468;
	case 1136ULL: goto x86_l_470;
	case 1144ULL: goto x86_l_478;
	case 1151ULL: goto x86_l_47f;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1168ULL: goto x86_l_490;
	case 1173ULL: goto x86_l_495;
	case 1176ULL: goto x86_l_498;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1191ULL: goto x86_l_4a7;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1219ULL: goto x86_l_4c3;
	case 1223ULL: goto x86_l_4c7;
	case 1231ULL: goto x86_l_4cf;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1248ULL: goto x86_l_4e0;
	case 1254ULL: goto x86_l_4e6;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1276ULL: goto x86_l_4fc;
	case 1284ULL: goto x86_l_504;
	case 1288ULL: goto x86_l_508;
	case 1292ULL: goto x86_l_50c;
	case 1303ULL: goto x86_l_517;
	case 1314ULL: goto x86_l_522;
	case 1325ULL: goto x86_l_52d;
	case 1336ULL: goto x86_l_538;
	case 1347ULL: goto x86_l_543;
	case 1358ULL: goto x86_l_54e;
	case 1369ULL: goto x86_l_559;
	case 1380ULL: goto x86_l_564;
	case 1391ULL: goto x86_l_56f;
	case 1399ULL: goto x86_l_577;
	case 1407ULL: goto x86_l_57f;
	case 1415ULL: goto x86_l_587;
	case 1423ULL: goto x86_l_58f;
	case 1431ULL: goto x86_l_597;
	case 1439ULL: goto x86_l_59f;
	case 1447ULL: goto x86_l_5a7;
	case 1455ULL: goto x86_l_5af;
	case 1463ULL: goto x86_l_5b7;
	case 1471ULL: goto x86_l_5bf;
	case 1479ULL: goto x86_l_5c7;
	case 1487ULL: goto x86_l_5cf;
	case 1495ULL: goto x86_l_5d7;
	case 1503ULL: goto x86_l_5df;
	case 1511ULL: goto x86_l_5e7;
	case 1518ULL: goto x86_l_5ee;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1558ULL: goto x86_l_616;
	case 1560ULL: goto x86_l_618;
	case 1563ULL: goto x86_l_61b;
	case 1569ULL: goto x86_l_621;
	case 1572ULL: goto x86_l_624;
	case 1579ULL: goto x86_l_62b;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1603ULL: goto x86_l_643;
	case 1606ULL: goto x86_l_646;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1621ULL: goto x86_l_655;
	case 1625ULL: goto x86_l_659;
	case 1630ULL: goto x86_l_65e;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1645ULL: goto x86_l_66d;
	case 1647ULL: goto x86_l_66f;
	case 1652ULL: goto x86_l_674;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1671ULL: goto x86_l_687;
	case 1676ULL: goto x86_l_68c;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1687ULL: goto x86_l_697;
	case 1692ULL: goto x86_l_69c;
	case 1697ULL: goto x86_l_6a1;
	case 1702ULL: goto x86_l_6a6;
	case 1707ULL: goto x86_l_6ab;
	case 1709ULL: goto x86_l_6ad;
	case 1713ULL: goto x86_l_6b1;
	case 1717ULL: goto x86_l_6b5;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1741ULL: goto x86_l_6cd;
	case 1744ULL: goto x86_l_6d0;
	case 1746ULL: goto x86_l_6d2;
	case 1751ULL: goto x86_l_6d7;
	case 1756ULL: goto x86_l_6dc;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1780ULL: goto x86_l_6f4;
	case 1784ULL: goto x86_l_6f8;
	case 1788ULL: goto x86_l_6fc;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1812ULL: goto x86_l_714;
	case 1814ULL: goto x86_l_716;
	case 1818ULL: goto x86_l_71a;
	case 1822ULL: goto x86_l_71e;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1837ULL: goto x86_l_72d;
	case 1842ULL: goto x86_l_732;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1852ULL: goto x86_l_73c;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1906ULL: goto x86_l_772;
	case 1908ULL: goto x86_l_774;
	case 1912ULL: goto x86_l_778;
	case 1916ULL: goto x86_l_77c;
	case 1920ULL: goto x86_l_780;
	case 1924ULL: goto x86_l_784;
	case 1929ULL: goto x86_l_789;
	case 1934ULL: goto x86_l_78e;
	case 1939ULL: goto x86_l_793;
	case 1944ULL: goto x86_l_798;
	case 1946ULL: goto x86_l_79a;
	case 1950ULL: goto x86_l_79e;
	case 1954ULL: goto x86_l_7a2;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1977ULL: goto x86_l_7b9;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1989ULL: goto x86_l_7c5;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2007ULL: goto x86_l_7d7;
	case 2009ULL: goto x86_l_7d9;
	case 2013ULL: goto x86_l_7dd;
	case 2017ULL: goto x86_l_7e1;
	case 2021ULL: goto x86_l_7e5;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2035ULL: goto x86_l_7f3;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2047ULL: goto x86_l_7ff;
	case 2052ULL: goto x86_l_804;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2066ULL: goto x86_l_812;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2097ULL: goto x86_l_831;
	case 2102ULL: goto x86_l_836;
	case 2107ULL: goto x86_l_83b;
	case 2110ULL: goto x86_l_83e;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
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
	/* 0x2c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x42: test   DWORD PTR [rsp+0x20],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137441050624ULL);
x86_l_4a:
	/* 0x4a: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_4f:
	/* 0x4f: jne    b7 <trace_security_mmap_file+0xb7> */
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
	/* 0x65: je     6c <trace_security_mmap_file+0x6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6c;
	}
x86_l_67:
	/* 0x67: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6a:
	/* 0x6a: jmp    6c <trace_security_mmap_file+0x6c> */
	goto x86_l_6c;
x86_l_6c:
	/* 0x6c: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70:
	/* 0x70: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x89: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_8e:
	/* 0x8e: jne    96 <trace_security_mmap_file+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_96;
	}
x86_l_90:
	/* 0x90: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_94:
	/* 0x94: jmp    b7 <trace_security_mmap_file+0xb7> */
	goto x86_l_b7;
x86_l_96:
	/* 0x96: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_9d:
	/* 0x9d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0xac: je     b2 <trace_security_mmap_file+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b2;
	}
x86_l_ae:
	/* 0xae: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b0:
	/* 0xb0: jmp    b7 <trace_security_mmap_file+0xb7> */
	goto x86_l_b7;
x86_l_b2:
	/* 0xb2: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be:
	/* 0xbe: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c5:
	/* 0xc5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c8:
	/* 0xc8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd:
	/* 0xcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf:
	/* 0xcf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d2:
	/* 0xd2: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_d8:
	/* 0xd8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e2:
	/* 0xe2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e5:
	/* 0xe5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea:
	/* 0xea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec:
	/* 0xec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef:
	/* 0xef: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_f5:
	/* 0xf5: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_f8:
	/* 0xf8: mov    WORD PTR [r13+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_102:
	/* 0x102: mov    BYTE PTR [r13+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10a:
	/* 0x10a: mov    QWORD PTR [r13+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_115:
	/* 0x115: mov    QWORD PTR [r13+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_120:
	/* 0x120: mov    QWORD PTR [r13+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_12b:
	/* 0x12b: mov    QWORD PTR [r13+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_136:
	/* 0x136: mov    QWORD PTR [r13+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_141:
	/* 0x141: mov    QWORD PTR [r13+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_14c:
	/* 0x14c: mov    QWORD PTR [r13+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_157:
	/* 0x157: mov    QWORD PTR [r13+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_162:
	/* 0x162: mov    QWORD PTR [r13+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_171:
	/* 0x171: mov    QWORD PTR [r13+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [r13+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_181:
	/* 0x181: mov    QWORD PTR [r13+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_189:
	/* 0x189: mov    QWORD PTR [r13+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_191:
	/* 0x191: mov    QWORD PTR [r13+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [r13+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [r13+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1a9:
	/* 0x1a9: mov    QWORD PTR [r13+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b1:
	/* 0x1b1: mov    QWORD PTR [r13+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [r13+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c1:
	/* 0x1c1: mov    QWORD PTR [r13+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1c9:
	/* 0x1c9: mov    QWORD PTR [r13+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1d1:
	/* 0x1d1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d6:
	/* 0x1d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8:
	/* 0x1d8: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dc:
	/* 0x1dc: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1e0:
	/* 0x1e0: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e4:
	/* 0x1e4: mov    DWORD PTR [r13+0x70],0x2f9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337913ULL);
x86_l_1ec:
	/* 0x1ec: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1f1:
	/* 0x1f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3:
	/* 0x1f3: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7:
	/* 0x1f7: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fc:
	/* 0x1fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe:
	/* 0x1fe: mov    WORD PTR [r13+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_203:
	/* 0x203: mov    DWORD PTR [r13+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_207:
	/* 0x207: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20b:
	/* 0x20b: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_212:
	/* 0x212: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_219:
	/* 0x219: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_221:
	/* 0x221: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_226:
	/* 0x226: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_228:
	/* 0x228: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_22d:
	/* 0x22d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_230:
	/* 0x230: je     27c <trace_security_mmap_file+0x27c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27c;
	}
x86_l_232:
	/* 0x232: mov    eax,DWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_236:
	/* 0x236: mov    DWORD PTR [rsp+0xb8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_23d:
	/* 0x23d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_244:
	/* 0x244: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_24c:
	/* 0x24c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_251:
	/* 0x251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_253:
	/* 0x253: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_256:
	/* 0x256: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_259:
	/* 0x259: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25e:
	/* 0x25e: je     4bc <trace_security_mmap_file+0x4bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc;
	}
x86_l_264:
	/* 0x264: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_26a:
	/* 0x26a: jne    ad2 <trace_security_mmap_file+0xad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2770ULL;
	}
x86_l_270:
	/* 0x270: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_275:
	/* 0x275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277:
	/* 0x277: jmp    b7c <trace_security_mmap_file+0xb7c> */
	return 2940ULL;
x86_l_27c:
	/* 0x27c: mov    eax,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_283:
	/* 0x283: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287:
	/* 0x287: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_28f:
	/* 0x28f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_296:
	/* 0x296: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29b:
	/* 0x29b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a0:
	/* 0x2a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a2:
	/* 0x2a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a5:
	/* 0x2a5: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_2ab:
	/* 0x2ab: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2ae:
	/* 0x2ae: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b2:
	/* 0x2b2: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b6:
	/* 0x2b6: mov    QWORD PTR [rdx+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2c1:
	/* 0x2c1: mov    QWORD PTR [rdx+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2cc:
	/* 0x2cc: mov    QWORD PTR [rdx+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2d7:
	/* 0x2d7: mov    QWORD PTR [rdx+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2e2:
	/* 0x2e2: mov    QWORD PTR [rdx+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2ed:
	/* 0x2ed: mov    QWORD PTR [rdx+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2f8:
	/* 0x2f8: mov    QWORD PTR [rdx+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_303:
	/* 0x303: mov    QWORD PTR [rdx+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_30e:
	/* 0x30e: mov    QWORD PTR [rdx+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_319:
	/* 0x319: mov    QWORD PTR [rdx+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_324:
	/* 0x324: mov    QWORD PTR [rdx+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_32f:
	/* 0x32f: mov    QWORD PTR [rdx+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_33a:
	/* 0x33a: mov    QWORD PTR [rdx+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_345:
	/* 0x345: mov    QWORD PTR [rdx+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_350:
	/* 0x350: mov    QWORD PTR [rdx+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_35b:
	/* 0x35b: mov    QWORD PTR [rdx+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_366:
	/* 0x366: mov    QWORD PTR [rdx+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_371:
	/* 0x371: mov    QWORD PTR [rdx+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_37c:
	/* 0x37c: mov    QWORD PTR [rdx+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rdx+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_392:
	/* 0x392: mov    QWORD PTR [rdx+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3a8:
	/* 0x3a8: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3b3:
	/* 0x3b3: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3be:
	/* 0x3be: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3c9:
	/* 0x3c9: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3d4:
	/* 0x3d4: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3df:
	/* 0x3df: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3ea:
	/* 0x3ea: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_400:
	/* 0x400: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_408:
	/* 0x408: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_410:
	/* 0x410: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_418:
	/* 0x418: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_420:
	/* 0x420: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_430:
	/* 0x430: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_438:
	/* 0x438: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_440:
	/* 0x440: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_448:
	/* 0x448: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_450:
	/* 0x450: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_458:
	/* 0x458: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_460:
	/* 0x460: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_468:
	/* 0x468: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_470:
	/* 0x470: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_478:
	/* 0x478: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47f:
	/* 0x47f: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_486:
	/* 0x486: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48b:
	/* 0x48b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_490:
	/* 0x490: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_495:
	/* 0x495: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_498:
	/* 0x498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49a:
	/* 0x49a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49f:
	/* 0x49f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a4:
	/* 0x4a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9:
	/* 0x4a9: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4ae:
	/* 0x4ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: jne    232 <trace_security_mmap_file+0x232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_232;
	}
x86_l_4b7:
	/* 0x4b7: jmp    3de5 <trace_security_mmap_file+0x3de5> */
	return 15845ULL;
x86_l_4bc:
	/* 0x4bc: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4c3:
	/* 0x4c3: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c7:
	/* 0x4c7: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4cf:
	/* 0x4cf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4d6:
	/* 0x4d6: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4db:
	/* 0x4db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e0:
	/* 0x4e0: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_4e6:
	/* 0x4e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e8:
	/* 0x4e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4eb:
	/* 0x4eb: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_4f1:
	/* 0x4f1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4f4:
	/* 0x4f4: mov    QWORD PTR [rsp+0xa8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4fc:
	/* 0x4fc: mov    QWORD PTR [rsp+0xd0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_504:
	/* 0x504: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_508:
	/* 0x508: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50c:
	/* 0x50c: mov    QWORD PTR [rdx+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_517:
	/* 0x517: mov    QWORD PTR [rdx+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_522:
	/* 0x522: mov    QWORD PTR [rdx+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_52d:
	/* 0x52d: mov    QWORD PTR [rdx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_538:
	/* 0x538: mov    QWORD PTR [rdx+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_543:
	/* 0x543: mov    QWORD PTR [rdx+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_54e:
	/* 0x54e: mov    QWORD PTR [rdx+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_559:
	/* 0x559: mov    QWORD PTR [rdx+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_564:
	/* 0x564: mov    QWORD PTR [rdx+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_56f:
	/* 0x56f: mov    QWORD PTR [rdx+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_577:
	/* 0x577: mov    QWORD PTR [rdx+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_57f:
	/* 0x57f: mov    QWORD PTR [rdx+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_587:
	/* 0x587: mov    QWORD PTR [rdx+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_58f:
	/* 0x58f: mov    QWORD PTR [rdx+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_597:
	/* 0x597: mov    QWORD PTR [rdx+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_59f:
	/* 0x59f: mov    QWORD PTR [rdx+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5a7:
	/* 0x5a7: mov    QWORD PTR [rdx+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5af:
	/* 0x5af: mov    QWORD PTR [rdx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5b7:
	/* 0x5b7: mov    QWORD PTR [rdx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5bf:
	/* 0x5bf: mov    QWORD PTR [rdx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5c7:
	/* 0x5c7: mov    QWORD PTR [rdx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rdx+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5d7:
	/* 0x5d7: mov    QWORD PTR [rdx+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5df:
	/* 0x5df: mov    QWORD PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ee:
	/* 0x5ee: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5f5:
	/* 0x5f5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ff:
	/* 0x5ff: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_604:
	/* 0x604: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_607:
	/* 0x607: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_609:
	/* 0x609: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60e:
	/* 0x60e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_613:
	/* 0x613: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_616:
	/* 0x616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_618:
	/* 0x618: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61b:
	/* 0x61b: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_621:
	/* 0x621: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_624:
	/* 0x624: mov    rbp,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_62b:
	/* 0x62b: lea    r12,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_62f:
	/* 0x62f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_634:
	/* 0x634: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_639:
	/* 0x639: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63e:
	/* 0x63e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_643:
	/* 0x643: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_646:
	/* 0x646: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_648:
	/* 0x648: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64d:
	/* 0x64d: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_655:
	/* 0x655: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_659:
	/* 0x659: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65e:
	/* 0x65e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_663:
	/* 0x663: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_668:
	/* 0x668: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66d:
	/* 0x66d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66f:
	/* 0x66f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_674:
	/* 0x674: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_678:
	/* 0x678: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67d:
	/* 0x67d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_682:
	/* 0x682: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_687:
	/* 0x687: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68c:
	/* 0x68c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68e:
	/* 0x68e: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_693:
	/* 0x693: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_697:
	/* 0x697: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69c:
	/* 0x69c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a6:
	/* 0x6a6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6ab:
	/* 0x6ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ad:
	/* 0x6ad: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b1:
	/* 0x6b1: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6b5:
	/* 0x6b5: lea    r13,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6b9:
	/* 0x6b9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6be:
	/* 0x6be: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6c3:
	/* 0x6c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c8:
	/* 0x6c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6cd:
	/* 0x6cd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6d0:
	/* 0x6d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d2:
	/* 0x6d2: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d7:
	/* 0x6d7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6dc:
	/* 0x6dc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6e1:
	/* 0x6e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6e6:
	/* 0x6e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6eb:
	/* 0x6eb: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f4:
	/* 0x6f4: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6f8:
	/* 0x6f8: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6fc:
	/* 0x6fc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_700:
	/* 0x700: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_705:
	/* 0x705: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_70a:
	/* 0x70a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70f:
	/* 0x70f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_714:
	/* 0x714: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_716:
	/* 0x716: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71a:
	/* 0x71a: mov    DWORD PTR [r14+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_71e:
	/* 0x71e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_723:
	/* 0x723: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_728:
	/* 0x728: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_72d:
	/* 0x72d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_732:
	/* 0x732: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_735:
	/* 0x735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_737:
	/* 0x737: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_73c:
	/* 0x73c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_740:
	/* 0x740: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_745:
	/* 0x745: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_74a:
	/* 0x74a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_74f:
	/* 0x74f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_754:
	/* 0x754: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_756:
	/* 0x756: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_75b:
	/* 0x75b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_760:
	/* 0x760: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_765:
	/* 0x765: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_76a:
	/* 0x76a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_76f:
	/* 0x76f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_772:
	/* 0x772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_774:
	/* 0x774: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_778:
	/* 0x778: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_77c:
	/* 0x77c: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_780:
	/* 0x780: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_784:
	/* 0x784: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_789:
	/* 0x789: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_78e:
	/* 0x78e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_793:
	/* 0x793: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_798:
	/* 0x798: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79a:
	/* 0x79a: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_79e:
	/* 0x79e: mov    DWORD PTR [r14+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a2:
	/* 0x7a2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a7:
	/* 0x7a7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7ac:
	/* 0x7ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b1:
	/* 0x7b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7b9:
	/* 0x7b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bb:
	/* 0x7bb: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c0:
	/* 0x7c0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c5:
	/* 0x7c5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ca:
	/* 0x7ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7cf:
	/* 0x7cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7d4:
	/* 0x7d4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d9:
	/* 0x7d9: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7dd:
	/* 0x7dd: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7e1:
	/* 0x7e1: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_7e5:
	/* 0x7e5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_7e9:
	/* 0x7e9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7ee:
	/* 0x7ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f3:
	/* 0x7f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7f8:
	/* 0x7f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7fd:
	/* 0x7fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ff:
	/* 0x7ff: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_804:
	/* 0x804: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_808:
	/* 0x808: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_80d:
	/* 0x80d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_812:
	/* 0x812: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_817:
	/* 0x817: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_81c:
	/* 0x81c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81e:
	/* 0x81e: mov    r13d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_823:
	/* 0x823: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_827:
	/* 0x827: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_82c:
	/* 0x82c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_831:
	/* 0x831: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_836:
	/* 0x836: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_83b:
	/* 0x83b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_83e:
	/* 0x83e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_840:
	/* 0x840: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_845:
	/* 0x845: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_84a:
	/* 0x84a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_84f:
	/* 0x84f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_854:
	/* 0x854: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_859:
	/* 0x859: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
	return 2140ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2140ULL: goto x86_l_85c;
	case 2142ULL: goto x86_l_85e;
	case 2146ULL: goto x86_l_862;
	case 2150ULL: goto x86_l_866;
	case 2154ULL: goto x86_l_86a;
	case 2158ULL: goto x86_l_86e;
	case 2163ULL: goto x86_l_873;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2180ULL: goto x86_l_884;
	case 2185ULL: goto x86_l_889;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2209ULL: goto x86_l_8a1;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2238ULL: goto x86_l_8be;
	case 2241ULL: goto x86_l_8c1;
	case 2243ULL: goto x86_l_8c3;
	case 2248ULL: goto x86_l_8c8;
	case 2253ULL: goto x86_l_8cd;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2323ULL: goto x86_l_913;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2353ULL: goto x86_l_931;
	case 2355ULL: goto x86_l_933;
	case 2360ULL: goto x86_l_938;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2396ULL: goto x86_l_95c;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2422ULL: goto x86_l_976;
	case 2426ULL: goto x86_l_97a;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2437ULL: goto x86_l_985;
	case 2441ULL: goto x86_l_989;
	case 2446ULL: goto x86_l_98e;
	case 2451ULL: goto x86_l_993;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2471ULL: goto x86_l_9a7;
	case 2479ULL: goto x86_l_9af;
	case 2483ULL: goto x86_l_9b3;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2498ULL: goto x86_l_9c2;
	case 2503ULL: goto x86_l_9c7;
	case 2505ULL: goto x86_l_9c9;
	case 2510ULL: goto x86_l_9ce;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2562ULL: goto x86_l_a02;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2575ULL: goto x86_l_a0f;
	case 2577ULL: goto x86_l_a11;
	case 2582ULL: goto x86_l_a16;
	case 2590ULL: goto x86_l_a1e;
	case 2593ULL: goto x86_l_a21;
	case 2595ULL: goto x86_l_a23;
	case 2599ULL: goto x86_l_a27;
	case 2607ULL: goto x86_l_a2f;
	case 2611ULL: goto x86_l_a33;
	case 2619ULL: goto x86_l_a3b;
	case 2624ULL: goto x86_l_a40;
	case 2629ULL: goto x86_l_a45;
	case 2634ULL: goto x86_l_a4a;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2659ULL: goto x86_l_a63;
	case 2661ULL: goto x86_l_a65;
	case 2666ULL: goto x86_l_a6a;
	case 2671ULL: goto x86_l_a6f;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2688ULL: goto x86_l_a80;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2703ULL: goto x86_l_a8f;
	case 2708ULL: goto x86_l_a94;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2725ULL: goto x86_l_aa5;
	case 2730ULL: goto x86_l_aaa;
	case 2735ULL: goto x86_l_aaf;
	case 2740ULL: goto x86_l_ab4;
	case 2743ULL: goto x86_l_ab7;
	case 2745ULL: goto x86_l_ab9;
	case 2753ULL: goto x86_l_ac1;
	case 2758ULL: goto x86_l_ac6;
	case 2764ULL: goto x86_l_acc;
	case 2770ULL: goto x86_l_ad2;
	case 2775ULL: goto x86_l_ad7;
	case 2782ULL: goto x86_l_ade;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2797ULL: goto x86_l_aed;
	case 2802ULL: goto x86_l_af2;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2836ULL: goto x86_l_b14;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2866ULL: goto x86_l_b32;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2893ULL: goto x86_l_b4d;
	case 2895ULL: goto x86_l_b4f;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2909ULL: goto x86_l_b5d;
	case 2914ULL: goto x86_l_b62;
	case 2919ULL: goto x86_l_b67;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2931ULL: goto x86_l_b73;
	case 2936ULL: goto x86_l_b78;
	case 2938ULL: goto x86_l_b7a;
	case 2940ULL: goto x86_l_b7c;
	case 2944ULL: goto x86_l_b80;
	case 2948ULL: goto x86_l_b84;
	case 2952ULL: goto x86_l_b88;
	case 2959ULL: goto x86_l_b8f;
	case 2964ULL: goto x86_l_b94;
	case 2969ULL: goto x86_l_b99;
	case 2971ULL: goto x86_l_b9b;
	case 2974ULL: goto x86_l_b9e;
	case 2976ULL: goto x86_l_ba0;
	case 2979ULL: goto x86_l_ba3;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2991ULL: goto x86_l_baf;
	case 2993ULL: goto x86_l_bb1;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3009ULL: goto x86_l_bc1;
	case 3015ULL: goto x86_l_bc7;
	case 3026ULL: goto x86_l_bd2;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3046ULL: goto x86_l_be6;
	case 3051ULL: goto x86_l_beb;
	case 3056ULL: goto x86_l_bf0;
	case 3058ULL: goto x86_l_bf2;
	case 3061ULL: goto x86_l_bf5;
	case 3063ULL: goto x86_l_bf7;
	case 3066ULL: goto x86_l_bfa;
	case 3071ULL: goto x86_l_bff;
	case 3076ULL: goto x86_l_c04;
	case 3078ULL: goto x86_l_c06;
	case 3081ULL: goto x86_l_c09;
	case 3083ULL: goto x86_l_c0b;
	case 3087ULL: goto x86_l_c0f;
	case 3094ULL: goto x86_l_c16;
	case 3097ULL: goto x86_l_c19;
	case 3104ULL: goto x86_l_c20;
	case 3108ULL: goto x86_l_c24;
	case 3112ULL: goto x86_l_c28;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3130ULL: goto x86_l_c3a;
	case 3137ULL: goto x86_l_c41;
	case 3141ULL: goto x86_l_c45;
	case 3148ULL: goto x86_l_c4c;
	case 3152ULL: goto x86_l_c50;
	case 3159ULL: goto x86_l_c57;
	case 3163ULL: goto x86_l_c5b;
	case 3170ULL: goto x86_l_c62;
	case 3177ULL: goto x86_l_c69;
	case 3184ULL: goto x86_l_c70;
	case 3188ULL: goto x86_l_c74;
	case 3191ULL: goto x86_l_c77;
	case 3197ULL: goto x86_l_c7d;
	case 3201ULL: goto x86_l_c81;
	case 3209ULL: goto x86_l_c89;
	case 3217ULL: goto x86_l_c91;
	case 3221ULL: goto x86_l_c95;
	case 3226ULL: goto x86_l_c9a;
	case 3231ULL: goto x86_l_c9f;
	case 3236ULL: goto x86_l_ca4;
	case 3241ULL: goto x86_l_ca9;
	case 3244ULL: goto x86_l_cac;
	case 3246ULL: goto x86_l_cae;
	case 3251ULL: goto x86_l_cb3;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3284ULL: goto x86_l_cd4;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3322ULL: goto x86_l_cfa;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3344ULL: goto x86_l_d10;
	case 3349ULL: goto x86_l_d15;
	case 3352ULL: goto x86_l_d18;
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3387ULL: goto x86_l_d3b;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3407ULL: goto x86_l_d4f;
	case 3412ULL: goto x86_l_d54;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3430ULL: goto x86_l_d66;
	case 3432ULL: goto x86_l_d68;
	case 3437ULL: goto x86_l_d6d;
	case 3446ULL: goto x86_l_d76;
	case 3455ULL: goto x86_l_d7f;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3469ULL: goto x86_l_d8d;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3481ULL: goto x86_l_d99;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3510ULL: goto x86_l_db6;
	case 3515ULL: goto x86_l_dbb;
	case 3518ULL: goto x86_l_dbe;
	case 3520ULL: goto x86_l_dc0;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3539ULL: goto x86_l_dd3;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3556ULL: goto x86_l_de4;
	case 3561ULL: goto x86_l_de9;
	case 3564ULL: goto x86_l_dec;
	case 3566ULL: goto x86_l_dee;
	case 3571ULL: goto x86_l_df3;
	case 3576ULL: goto x86_l_df8;
	case 3581ULL: goto x86_l_dfd;
	case 3586ULL: goto x86_l_e02;
	case 3591ULL: goto x86_l_e07;
	case 3593ULL: goto x86_l_e09;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3607ULL: goto x86_l_e17;
	case 3609ULL: goto x86_l_e19;
	case 3617ULL: goto x86_l_e21;
	case 3621ULL: goto x86_l_e25;
	case 3629ULL: goto x86_l_e2d;
	case 3633ULL: goto x86_l_e31;
	case 3641ULL: goto x86_l_e39;
	case 3645ULL: goto x86_l_e3d;
	case 3653ULL: goto x86_l_e45;
	case 3655ULL: goto x86_l_e47;
	case 3663ULL: goto x86_l_e4f;
	case 3671ULL: goto x86_l_e57;
	case 3679ULL: goto x86_l_e5f;
	case 3681ULL: goto x86_l_e61;
	case 3684ULL: goto x86_l_e64;
	case 3689ULL: goto x86_l_e69;
	case 3696ULL: goto x86_l_e70;
	case 3699ULL: goto x86_l_e73;
	case 3705ULL: goto x86_l_e79;
	case 3712ULL: goto x86_l_e80;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3721ULL: goto x86_l_e89;
	case 3725ULL: goto x86_l_e8d;
	case 3728ULL: goto x86_l_e90;
	case 3731ULL: goto x86_l_e93;
	case 3738ULL: goto x86_l_e9a;
	case 3741ULL: goto x86_l_e9d;
	case 3748ULL: goto x86_l_ea4;
	case 3751ULL: goto x86_l_ea7;
	case 3753ULL: goto x86_l_ea9;
	case 3755ULL: goto x86_l_eab;
	case 3762ULL: goto x86_l_eb2;
	case 3765ULL: goto x86_l_eb5;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3778ULL: goto x86_l_ec2;
	case 3781ULL: goto x86_l_ec5;
	case 3784ULL: goto x86_l_ec8;
	case 3791ULL: goto x86_l_ecf;
	case 3794ULL: goto x86_l_ed2;
	case 3796ULL: goto x86_l_ed4;
	case 3800ULL: goto x86_l_ed8;
	case 3803ULL: goto x86_l_edb;
	case 3806ULL: goto x86_l_ede;
	case 3809ULL: goto x86_l_ee1;
	case 3816ULL: goto x86_l_ee8;
	case 3819ULL: goto x86_l_eeb;
	case 3822ULL: goto x86_l_eee;
	case 3829ULL: goto x86_l_ef5;
	case 3832ULL: goto x86_l_ef8;
	case 3834ULL: goto x86_l_efa;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3846ULL: goto x86_l_f06;
	case 3849ULL: goto x86_l_f09;
	case 3856ULL: goto x86_l_f10;
	case 3859ULL: goto x86_l_f13;
	default: return 0xffffffffffffffffULL;
	}
x86_l_85c:
	/* 0x85c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85e:
	/* 0x85e: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_862:
	/* 0x862: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_866:
	/* 0x866: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_86a:
	/* 0x86a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_86e:
	/* 0x86e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_873:
	/* 0x873: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_878:
	/* 0x878: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_87d:
	/* 0x87d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_882:
	/* 0x882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_884:
	/* 0x884: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_889:
	/* 0x889: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_88d:
	/* 0x88d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_892:
	/* 0x892: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_897:
	/* 0x897: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89c:
	/* 0x89c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8a1:
	/* 0x8a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a3:
	/* 0x8a3: cmp    r13d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_8a8:
	/* 0x8a8: jne    90f <trace_security_mmap_file+0x90f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_90f;
	}
x86_l_8aa:
	/* 0x8aa: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8af:
	/* 0x8af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8b4:
	/* 0x8b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8b9:
	/* 0x8b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8be:
	/* 0x8be: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8c1:
	/* 0x8c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c3:
	/* 0x8c3: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c8:
	/* 0x8c8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8cd:
	/* 0x8cd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8d2:
	/* 0x8d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d7:
	/* 0x8d7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8dc:
	/* 0x8dc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8df:
	/* 0x8df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e1:
	/* 0x8e1: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8e5:
	/* 0x8e5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_8e9:
	/* 0x8e9: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8ed:
	/* 0x8ed: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_8f1:
	/* 0x8f1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8f6:
	/* 0x8f6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8fb:
	/* 0x8fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_900:
	/* 0x900: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_905:
	/* 0x905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_907:
	/* 0x907: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_90b:
	/* 0x90b: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_90f:
	/* 0x90f: mov    DWORD PTR [r14+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_913:
	/* 0x913: lea    r13,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_91a:
	/* 0x91a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_91f:
	/* 0x91f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_924:
	/* 0x924: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_929:
	/* 0x929: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_92e:
	/* 0x92e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_931:
	/* 0x931: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_933:
	/* 0x933: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_938:
	/* 0x938: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_93c:
	/* 0x93c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_941:
	/* 0x941: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_946:
	/* 0x946: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_94b:
	/* 0x94b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_950:
	/* 0x950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_952:
	/* 0x952: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_957:
	/* 0x957: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_95c:
	/* 0x95c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_961:
	/* 0x961: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_966:
	/* 0x966: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_96b:
	/* 0x96b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_970:
	/* 0x970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_972:
	/* 0x972: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_976:
	/* 0x976: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_97a:
	/* 0x97a: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_97f:
	/* 0x97f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_981:
	/* 0x981: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_985:
	/* 0x985: lea    rdx,[rbp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_989:
	/* 0x989: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_98e:
	/* 0x98e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_993:
	/* 0x993: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_998:
	/* 0x998: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_99d:
	/* 0x99d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99f:
	/* 0x99f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a4:
	/* 0x9a4: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a7:
	/* 0x9a7: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9af:
	/* 0x9af: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9b3:
	/* 0x9b3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9b8:
	/* 0x9b8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9bd:
	/* 0x9bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c2:
	/* 0x9c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9c7:
	/* 0x9c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c9:
	/* 0x9c9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ce:
	/* 0x9ce: mov    QWORD PTR [r14+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9d2:
	/* 0x9d2: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_9d6:
	/* 0x9d6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9db:
	/* 0x9db: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9e0:
	/* 0x9e0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9e5:
	/* 0x9e5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ea:
	/* 0x9ea: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ef:
	/* 0x9ef: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f4:
	/* 0x9f4: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f8:
	/* 0x9f8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9fd:
	/* 0x9fd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a02:
	/* 0xa02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a07:
	/* 0xa07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_a0c:
	/* 0xa0c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_a0f:
	/* 0xa0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a11:
	/* 0xa11: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_a16:
	/* 0xa16: mov    r12,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a1e:
	/* 0xa1e: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_a21:
	/* 0xa21: je     a27 <trace_security_mmap_file+0xa27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a27;
	}
x86_l_a23:
	/* 0xa23: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_a27:
	/* 0xa27: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_a2f:
	/* 0xa2f: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a33:
	/* 0xa33: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_a3b:
	/* 0xa3b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_a40:
	/* 0xa40: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_a45:
	/* 0xa45: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_a4a:
	/* 0xa4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4c:
	/* 0xa4c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a51:
	/* 0xa51: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a56:
	/* 0xa56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a5b:
	/* 0xa5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a60:
	/* 0xa60: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_a63:
	/* 0xa63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a65:
	/* 0xa65: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6a:
	/* 0xa6a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0xa7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a80:
	/* 0xa80: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a85:
	/* 0xa85: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a8a:
	/* 0xa8a: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_a8f:
	/* 0xa8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a94:
	/* 0xa94: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a97:
	/* 0xa97: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_a9c:
	/* 0xa9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a9e:
	/* 0xa9e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_aa5:
	/* 0xaa5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aaa:
	/* 0xaaa: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_aaf:
	/* 0xaaf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ab4:
	/* 0xab4: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_ab7:
	/* 0xab7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab9:
	/* 0xab9: mov    r15,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_ac1:
	/* 0xac1: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ac6:
	/* 0xac6: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_acc:
	/* 0xacc: je     270 <trace_security_mmap_file+0x270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 624ULL;
	}
x86_l_ad2:
	/* 0xad2: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_ad7:
	/* 0xad7: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_ade:
	/* 0xade: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae3:
	/* 0xae3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ae8:
	/* 0xae8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_aed:
	/* 0xaed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_af2:
	/* 0xaf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af4:
	/* 0xaf4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af9:
	/* 0xaf9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_afe:
	/* 0xafe: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b03:
	/* 0xb03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b08:
	/* 0xb08: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0d:
	/* 0xb0d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b12:
	/* 0xb12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b14:
	/* 0xb14: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b19:
	/* 0xb19: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b1e:
	/* 0xb1e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b23:
	/* 0xb23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b28:
	/* 0xb28: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b2d:
	/* 0xb2d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b32:
	/* 0xb32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b34:
	/* 0xb34: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0xb4f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b54:
	/* 0xb54: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_b57:
	/* 0xb57: je     b7a <trace_security_mmap_file+0xb7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7a;
	}
x86_l_b59:
	/* 0xb59: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b5d:
	/* 0xb5d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b62:
	/* 0xb62: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b67:
	/* 0xb67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b6c:
	/* 0xb6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b71:
	/* 0xb71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b73:
	/* 0xb73: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b78:
	/* 0xb78: jmp    b7c <trace_security_mmap_file+0xb7c> */
	goto x86_l_b7c;
x86_l_b7a:
	/* 0xb7a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7c:
	/* 0xb7c: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b80:
	/* 0xb80: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b84:
	/* 0xb84: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b88:
	/* 0xb88: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_b8f:
	/* 0xb8f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b94:
	/* 0xb94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b99:
	/* 0xb99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9b:
	/* 0xb9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9e:
	/* 0xb9e: je     bb6 <trace_security_mmap_file+0xbb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bb6;
	}
x86_l_ba0:
	/* 0xba0: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ba3:
	/* 0xba3: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ba9:
	/* 0xba9: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_bac:
	/* 0xbac: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_baf:
	/* 0xbaf: jne    bb6 <trace_security_mmap_file+0xbb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bb6;
	}
x86_l_bb1:
	/* 0xbb1: or     BYTE PTR [r13+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_bb6:
	/* 0xbb6: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_bbb:
	/* 0xbbb: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_bc1:
	/* 0xbc1: jne    3db1 <trace_security_mmap_file+0x3db1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 15793ULL;
	}
x86_l_bc7:
	/* 0xbc7: mov    QWORD PTR [r13+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_bd2:
	/* 0xbd2: mov    DWORD PTR [rsp+0x20],0x2f9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438954233ULL);
x86_l_bda:
	/* 0xbda: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bdf:
	/* 0xbdf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_be6:
	/* 0xbe6: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_beb:
	/* 0xbeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf0:
	/* 0xbf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf2:
	/* 0xbf2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf5:
	/* 0xbf5: je     c62 <trace_security_mmap_file+0xc62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c62;
	}
x86_l_bf7:
	/* 0xbf7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_bfa:
	/* 0xbfa: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bff:
	/* 0xbff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c04:
	/* 0xc04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c06:
	/* 0xc06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c09:
	/* 0xc09: je     c62 <trace_security_mmap_file+0xc62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c62;
	}
x86_l_c0b:
	/* 0xc0b: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c0f:
	/* 0xc0f: mov    QWORD PTR [r13+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_c16:
	/* 0xc16: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c19:
	/* 0xc19: mov    QWORD PTR [r13+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c20:
	/* 0xc20: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c24:
	/* 0xc24: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c28:
	/* 0xc28: mov    QWORD PTR [r13+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_c2f:
	/* 0xc2f: mov    QWORD PTR [r13+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_c36:
	/* 0xc36: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c3a:
	/* 0xc3a: mov    QWORD PTR [r13+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_c41:
	/* 0xc41: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c45:
	/* 0xc45: mov    QWORD PTR [r13+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_c4c:
	/* 0xc4c: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c50:
	/* 0xc50: mov    QWORD PTR [r13+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_c57:
	/* 0xc57: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c5b:
	/* 0xc5b: mov    QWORD PTR [r13+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_c62:
	/* 0xc62: mov    rax,QWORD PTR [r13+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_c69:
	/* 0xc69: mov    QWORD PTR [r13+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c70:
	/* 0xc70: mov    rax,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c74:
	/* 0xc74: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c77:
	/* 0xc77: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_c7d:
	/* 0xc7d: lea    rcx,[r13+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c81:
	/* 0xc81: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c89:
	/* 0xc89: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c91:
	/* 0xc91: lea    rbx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c95:
	/* 0xc95: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c9a:
	/* 0xc9a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c9f:
	/* 0xc9f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ca4:
	/* 0xca4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ca9:
	/* 0xca9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_cac:
	/* 0xcac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cae:
	/* 0xcae: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb3:
	/* 0xcb3: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_cb7:
	/* 0xcb7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cbc:
	/* 0xcbc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_cc1:
	/* 0xcc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cc6:
	/* 0xcc6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ccb:
	/* 0xccb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_ccf:
	/* 0xccf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cd4:
	/* 0xcd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd6:
	/* 0xcd6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cdb:
	/* 0xcdb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce0:
	/* 0xce0: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ce5:
	/* 0xce5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cea:
	/* 0xcea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cef:
	/* 0xcef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cf4:
	/* 0xcf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf6:
	/* 0xcf6: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cfa:
	/* 0xcfa: mov    DWORD PTR [rsp+0xcc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_d01:
	/* 0xd01: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d06:
	/* 0xd06: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d0b:
	/* 0xd0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d10:
	/* 0xd10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d15:
	/* 0xd15: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_d18:
	/* 0xd18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1a:
	/* 0xd1a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1f:
	/* 0xd1f: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d23:
	/* 0xd23: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d28:
	/* 0xd28: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d2d:
	/* 0xd2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d32:
	/* 0xd32: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d37:
	/* 0xd37: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d3b:
	/* 0xd3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d40:
	/* 0xd40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d42:
	/* 0xd42: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d47:
	/* 0xd47: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_d4f:
	/* 0xd4f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d54:
	/* 0xd54: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d59:
	/* 0xd59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d5e:
	/* 0xd5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d63:
	/* 0xd63: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_d66:
	/* 0xd66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d68:
	/* 0xd68: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d6d:
	/* 0xd6d: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d76:
	/* 0xd76: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_d7f:
	/* 0xd7f: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d83:
	/* 0xd83: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d88:
	/* 0xd88: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d8d:
	/* 0xd8d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d92:
	/* 0xd92: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d97:
	/* 0xd97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d99:
	/* 0xd99: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9e:
	/* 0xd9e: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da3:
	/* 0xda3: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_da7:
	/* 0xda7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dac:
	/* 0xdac: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_db1:
	/* 0xdb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_db6:
	/* 0xdb6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_dbb:
	/* 0xdbb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_dbe:
	/* 0xdbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc0:
	/* 0xdc0: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc4:
	/* 0xdc4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dc9:
	/* 0xdc9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dce:
	/* 0xdce: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd3:
	/* 0xdd3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dd8:
	/* 0xdd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ddd:
	/* 0xddd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_de2:
	/* 0xde2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de4:
	/* 0xde4: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de9:
	/* 0xde9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_dec:
	/* 0xdec: js     e17 <trace_security_mmap_file+0xe17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_e17;
	}
x86_l_dee:
	/* 0xdee: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_df3:
	/* 0xdf3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_df8:
	/* 0xdf8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dfd:
	/* 0xdfd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e02:
	/* 0xe02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e07:
	/* 0xe07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e09:
	/* 0xe09: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_e10:
	/* 0xe10: add    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e15:
	/* 0xe15: jmp    e19 <trace_security_mmap_file+0xe19> */
	goto x86_l_e19;
x86_l_e17:
	/* 0xe17: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e19:
	/* 0xe19: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_e21:
	/* 0xe21: mov    rax,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e25:
	/* 0xe25: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_e2d:
	/* 0xe2d: mov    rax,QWORD PTR [r15+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e31:
	/* 0xe31: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_e39:
	/* 0xe39: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3d:
	/* 0xe3d: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e45:
	/* 0xe45: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_e47:
	/* 0xe47: mov    QWORD PTR [rsp+0xd8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_e4f:
	/* 0xe4f: mov    QWORD PTR [rsp+0xd0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_e57:
	/* 0xe57: mov    QWORD PTR [rsp+0xa8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_e5f:
	/* 0xe5f: jne    e69 <trace_security_mmap_file+0xe69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e69;
	}
x86_l_e61:
	/* 0xe61: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e64:
	/* 0xe64: jmp    1636 <trace_security_mmap_file+0x1636> */
	return 5686ULL;
x86_l_e69:
	/* 0xe69: mov    rax,QWORD PTR [r13+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_e70:
	/* 0xe70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e73:
	/* 0xe73: je     1009 <trace_security_mmap_file+0x1009> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4105ULL;
	}
x86_l_e79:
	/* 0xe79: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_e80:
	/* 0xe80: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_e83:
	/* 0xe83: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e86:
	/* 0xe86: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_e89:
	/* 0xe89: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_e8d:
	/* 0xe8d: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e90:
	/* 0xe90: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_e93:
	/* 0xe93: xor    r12,QWORD PTR [r13+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_e9a:
	/* 0xe9a: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e9d:
	/* 0xe9d: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_ea4:
	/* 0xea4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea7:
	/* 0xea7: je     ec8 <trace_security_mmap_file+0xec8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec8;
	}
x86_l_ea9:
	/* 0xea9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eab:
	/* 0xeab: cmp    BYTE PTR [rbp+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_eb2:
	/* 0xeb2: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_eb5:
	/* 0xeb5: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_eb8:
	/* 0xeb8: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ebb:
	/* 0xebb: xor    rcx,QWORD PTR [r13+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_ec2:
	/* 0xec2: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ec5:
	/* 0xec5: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ec8:
	/* 0xec8: mov    rax,QWORD PTR [r13+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_ecf:
	/* 0xecf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ed2:
	/* 0xed2: je     eee <trace_security_mmap_file+0xeee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eee;
	}
x86_l_ed4:
	/* 0xed4: mov    ecx,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_ed8:
	/* 0xed8: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_edb:
	/* 0xedb: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_ede:
	/* 0xede: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_ee1:
	/* 0xee1: xor    rcx,QWORD PTR [r13+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_ee8:
	/* 0xee8: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_eeb:
	/* 0xeeb: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_eee:
	/* 0xeee: mov    rax,QWORD PTR [r13+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_ef5:
	/* 0xef5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ef8:
	/* 0xef8: je     f16 <trace_security_mmap_file+0xf16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3862ULL;
	}
x86_l_efa:
	/* 0xefa: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_efd:
	/* 0xefd: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f02:
	/* 0xf02: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f06:
	/* 0xf06: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_f09:
	/* 0xf09: xor    rcx,QWORD PTR [r13+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_f10:
	/* 0xf10: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f13:
	/* 0xf13: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
	return 3862ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3885ULL: goto x86_l_f2d;
	case 3891ULL: goto x86_l_f33;
	case 3898ULL: goto x86_l_f3a;
	case 3906ULL: goto x86_l_f42;
	case 3913ULL: goto x86_l_f49;
	case 3920ULL: goto x86_l_f50;
	case 3925ULL: goto x86_l_f55;
	case 3930ULL: goto x86_l_f5a;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3952ULL: goto x86_l_f70;
	case 3956ULL: goto x86_l_f74;
	case 3961ULL: goto x86_l_f79;
	case 3968ULL: goto x86_l_f80;
	case 3971ULL: goto x86_l_f83;
	case 3973ULL: goto x86_l_f85;
	case 3978ULL: goto x86_l_f8a;
	case 3983ULL: goto x86_l_f8f;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3993ULL: goto x86_l_f99;
	case 3996ULL: goto x86_l_f9c;
	case 4000ULL: goto x86_l_fa0;
	case 4003ULL: goto x86_l_fa3;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4021ULL: goto x86_l_fb5;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4030ULL: goto x86_l_fbe;
	case 4032ULL: goto x86_l_fc0;
	case 4035ULL: goto x86_l_fc3;
	case 4037ULL: goto x86_l_fc5;
	case 4045ULL: goto x86_l_fcd;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
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
	case 4112ULL: goto x86_l_1010;
	case 4119ULL: goto x86_l_1017;
	case 4122ULL: goto x86_l_101a;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4135ULL: goto x86_l_1027;
	case 4138ULL: goto x86_l_102a;
	case 4143ULL: goto x86_l_102f;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4150ULL: goto x86_l_1036;
	case 4152ULL: goto x86_l_1038;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4168ULL: goto x86_l_1048;
	case 4170ULL: goto x86_l_104a;
	case 4174ULL: goto x86_l_104e;
	case 4176ULL: goto x86_l_1050;
	case 4179ULL: goto x86_l_1053;
	case 4181ULL: goto x86_l_1055;
	case 4189ULL: goto x86_l_105d;
	case 4192ULL: goto x86_l_1060;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4201ULL: goto x86_l_1069;
	case 4206ULL: goto x86_l_106e;
	case 4214ULL: goto x86_l_1076;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4231ULL: goto x86_l_1087;
	case 4238ULL: goto x86_l_108e;
	case 4245ULL: goto x86_l_1095;
	case 4250ULL: goto x86_l_109a;
	case 4257ULL: goto x86_l_10a1;
	case 4260ULL: goto x86_l_10a4;
	case 4267ULL: goto x86_l_10ab;
	case 4275ULL: goto x86_l_10b3;
	case 4280ULL: goto x86_l_10b8;
	case 4287ULL: goto x86_l_10bf;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4306ULL: goto x86_l_10d2;
	case 4311ULL: goto x86_l_10d7;
	case 4318ULL: goto x86_l_10de;
	case 4321ULL: goto x86_l_10e1;
	case 4323ULL: goto x86_l_10e3;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4335ULL: goto x86_l_10ef;
	case 4338ULL: goto x86_l_10f2;
	case 4340ULL: goto x86_l_10f4;
	case 4343ULL: goto x86_l_10f7;
	case 4347ULL: goto x86_l_10fb;
	case 4350ULL: goto x86_l_10fe;
	case 4352ULL: goto x86_l_1100;
	case 4354ULL: goto x86_l_1102;
	case 4357ULL: goto x86_l_1105;
	case 4362ULL: goto x86_l_110a;
	case 4365ULL: goto x86_l_110d;
	case 4368ULL: goto x86_l_1110;
	case 4370ULL: goto x86_l_1112;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4388ULL: goto x86_l_1124;
	case 4396ULL: goto x86_l_112c;
	case 4398ULL: goto x86_l_112e;
	case 4403ULL: goto x86_l_1133;
	case 4407ULL: goto x86_l_1137;
	case 4415ULL: goto x86_l_113f;
	case 4417ULL: goto x86_l_1141;
	case 4420ULL: goto x86_l_1144;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4430ULL: goto x86_l_114e;
	case 4433ULL: goto x86_l_1151;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4449ULL: goto x86_l_1161;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4467ULL: goto x86_l_1173;
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
	case 4518ULL: goto x86_l_11a6;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4550ULL: goto x86_l_11c6;
	case 4552ULL: goto x86_l_11c8;
	case 4556ULL: goto x86_l_11cc;
	case 4560ULL: goto x86_l_11d0;
	case 4567ULL: goto x86_l_11d7;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4586ULL: goto x86_l_11ea;
	case 4591ULL: goto x86_l_11ef;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4601ULL: goto x86_l_11f9;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4616ULL: goto x86_l_1208;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4635ULL: goto x86_l_121b;
	case 4639ULL: goto x86_l_121f;
	case 4642ULL: goto x86_l_1222;
	case 4644ULL: goto x86_l_1224;
	case 4646ULL: goto x86_l_1226;
	case 4649ULL: goto x86_l_1229;
	case 4652ULL: goto x86_l_122c;
	case 4655ULL: goto x86_l_122f;
	case 4658ULL: goto x86_l_1232;
	case 4666ULL: goto x86_l_123a;
	case 4672ULL: goto x86_l_1240;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4698ULL: goto x86_l_125a;
	case 4703ULL: goto x86_l_125f;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4725ULL: goto x86_l_1275;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4735ULL: goto x86_l_127f;
	case 4739ULL: goto x86_l_1283;
	case 4743ULL: goto x86_l_1287;
	case 4747ULL: goto x86_l_128b;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4771ULL: goto x86_l_12a3;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4782ULL: goto x86_l_12ae;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4804ULL: goto x86_l_12c4;
	case 4808ULL: goto x86_l_12c8;
	case 4812ULL: goto x86_l_12cc;
	case 4819ULL: goto x86_l_12d3;
	case 4826ULL: goto x86_l_12da;
	case 4831ULL: goto x86_l_12df;
	case 4838ULL: goto x86_l_12e6;
	case 4843ULL: goto x86_l_12eb;
	case 4848ULL: goto x86_l_12f0;
	case 4851ULL: goto x86_l_12f3;
	case 4853ULL: goto x86_l_12f5;
	case 4860ULL: goto x86_l_12fc;
	case 4863ULL: goto x86_l_12ff;
	case 4865ULL: goto x86_l_1301;
	case 4868ULL: goto x86_l_1304;
	case 4872ULL: goto x86_l_1308;
	case 4877ULL: goto x86_l_130d;
	case 4879ULL: goto x86_l_130f;
	case 4882ULL: goto x86_l_1312;
	case 4884ULL: goto x86_l_1314;
	case 4887ULL: goto x86_l_1317;
	case 4891ULL: goto x86_l_131b;
	case 4894ULL: goto x86_l_131e;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4904ULL: goto x86_l_1328;
	case 4907ULL: goto x86_l_132b;
	case 4910ULL: goto x86_l_132e;
	case 4918ULL: goto x86_l_1336;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4936ULL: goto x86_l_1348;
	case 4941ULL: goto x86_l_134d;
	case 4946ULL: goto x86_l_1352;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4958ULL: goto x86_l_135e;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4985ULL: goto x86_l_1379;
	case 4990ULL: goto x86_l_137e;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5008ULL: goto x86_l_1390;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5032ULL: goto x86_l_13a8;
	case 5037ULL: goto x86_l_13ad;
	case 5040ULL: goto x86_l_13b0;
	case 5042ULL: goto x86_l_13b2;
	case 5049ULL: goto x86_l_13b9;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5068ULL: goto x86_l_13cc;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5081ULL: goto x86_l_13d9;
	case 5083ULL: goto x86_l_13db;
	case 5090ULL: goto x86_l_13e2;
	case 5093ULL: goto x86_l_13e5;
	case 5095ULL: goto x86_l_13e7;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
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
	case 5158ULL: goto x86_l_1426;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5189ULL: goto x86_l_1445;
	case 5196ULL: goto x86_l_144c;
	case 5201ULL: goto x86_l_1451;
	case 5208ULL: goto x86_l_1458;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5223ULL: goto x86_l_1467;
	case 5230ULL: goto x86_l_146e;
	case 5233ULL: goto x86_l_1471;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5248ULL: goto x86_l_1480;
	case 5251ULL: goto x86_l_1483;
	case 5253ULL: goto x86_l_1485;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5263ULL: goto x86_l_148f;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5270ULL: goto x86_l_1496;
	case 5273ULL: goto x86_l_1499;
	case 5276ULL: goto x86_l_149c;
	case 5279ULL: goto x86_l_149f;
	case 5284ULL: goto x86_l_14a4;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5296ULL: goto x86_l_14b0;
	case 5300ULL: goto x86_l_14b4;
	case 5304ULL: goto x86_l_14b8;
	case 5311ULL: goto x86_l_14bf;
	case 5316ULL: goto x86_l_14c4;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5336ULL: goto x86_l_14d8;
	case 5338ULL: goto x86_l_14da;
	case 5345ULL: goto x86_l_14e1;
	case 5348ULL: goto x86_l_14e4;
	case 5350ULL: goto x86_l_14e6;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5365ULL: goto x86_l_14f5;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5373ULL: goto x86_l_14fd;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5384ULL: goto x86_l_1508;
	case 5387ULL: goto x86_l_150b;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5396ULL: goto x86_l_1514;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5408ULL: goto x86_l_1520;
	case 5415ULL: goto x86_l_1527;
	case 5420ULL: goto x86_l_152c;
	case 5427ULL: goto x86_l_1533;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5440ULL: goto x86_l_1540;
	case 5442ULL: goto x86_l_1542;
	case 5449ULL: goto x86_l_1549;
	default: return 0xffffffffffffffffULL;
	}
x86_l_f16:
	/* 0xf16: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_f1b:
	/* 0xf1b: mov    r15,QWORD PTR [r13+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_f22:
	/* 0xf22: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_f2d:
	/* 0xf2d: je     106e <trace_security_mmap_file+0x106e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_106e;
	}
x86_l_f33:
	/* 0xf33: mov    rcx,QWORD PTR [r13+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_f3a:
	/* 0xf3a: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_f42:
	/* 0xf42: mov    rbp,QWORD PTR [r13+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_f49:
	/* 0xf49: mov    rcx,QWORD PTR [r13+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_f50:
	/* 0xf50: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f55:
	/* 0xf55: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f5a:
	/* 0xf5a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_f61:
	/* 0xf61: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f66:
	/* 0xf66: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f6b:
	/* 0xf6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6d:
	/* 0xf6d: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f70:
	/* 0xf70: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f74:
	/* 0xf74: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f79:
	/* 0xf79: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f80:
	/* 0xf80: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_f83:
	/* 0xf83: je     fa5 <trace_security_mmap_file+0xfa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fa5;
	}
x86_l_f85:
	/* 0xf85: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8a:
	/* 0xf8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f8f:
	/* 0xf8f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f92:
	/* 0xf92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f94:
	/* 0xf94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f97:
	/* 0xf97: je     fa5 <trace_security_mmap_file+0xfa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fa5;
	}
x86_l_f99:
	/* 0xf99: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9c:
	/* 0xf9c: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fa0:
	/* 0xfa0: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fa3:
	/* 0xfa3: jmp    fa8 <trace_security_mmap_file+0xfa8> */
	goto x86_l_fa8;
x86_l_fa5:
	/* 0xfa5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa8:
	/* 0xfa8: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fad:
	/* 0xfad: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fb2:
	/* 0xfb2: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_fb5:
	/* 0xfb5: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_fb8:
	/* 0xfb8: jb     fd0 <trace_security_mmap_file+0xfd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_fd0;
	}
x86_l_fba:
	/* 0xfba: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fbe:
	/* 0xfbe: je     fc5 <trace_security_mmap_file+0xfc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fc5;
	}
x86_l_fc0:
	/* 0xfc0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_fc3:
	/* 0xfc3: jbe    fd0 <trace_security_mmap_file+0xfd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_fd0;
	}
x86_l_fc5:
	/* 0xfc5: and    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 136ULL);
x86_l_fcd:
	/* 0xfcd: or     r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_fd0:
	/* 0xfd0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd5:
	/* 0xfd5: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fd8:
	/* 0xfd8: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fdd:
	/* 0xfdd: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_fe4:
	/* 0xfe4: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_fe7:
	/* 0xfe7: je     1025 <trace_security_mmap_file+0x1025> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1025;
	}
x86_l_fe9:
	/* 0xfe9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fee:
	/* 0xfee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff3:
	/* 0xff3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ff6:
	/* 0xff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff8:
	/* 0xff8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: je     1036 <trace_security_mmap_file+0x1036> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1036;
	}
x86_l_ffd:
	/* 0xffd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1000:
	/* 0x1000: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1004:
	/* 0x1004: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1007:
	/* 0x1007: jmp    1038 <trace_security_mmap_file+0x1038> */
	goto x86_l_1038;
x86_l_1009:
	/* 0x1009: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1010:
	/* 0x1010: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_1017:
	/* 0x1017: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_101a:
	/* 0x101a: jne    ea9 <trace_security_mmap_file+0xea9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3753ULL;
	}
x86_l_1020:
	/* 0x1020: jmp    ec8 <trace_security_mmap_file+0xec8> */
	return 3784ULL;
x86_l_1025:
	/* 0x1025: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1027:
	/* 0x1027: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_102a:
	/* 0x102a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_102f:
	/* 0x102f: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: jae    104a <trace_security_mmap_file+0x104a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_104a;
	}
x86_l_1034:
	/* 0x1034: jmp    1060 <trace_security_mmap_file+0x1060> */
	goto x86_l_1060;
x86_l_1036:
	/* 0x1036: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1038:
	/* 0x1038: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_103d:
	/* 0x103d: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1040:
	/* 0x1040: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1045:
	/* 0x1045: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1048:
	/* 0x1048: jb     1060 <trace_security_mmap_file+0x1060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1060;
	}
x86_l_104a:
	/* 0x104a: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_104e:
	/* 0x104e: je     1055 <trace_security_mmap_file+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1055;
	}
x86_l_1050:
	/* 0x1050: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1053:
	/* 0x1053: jbe    1060 <trace_security_mmap_file+0x1060> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1060;
	}
x86_l_1055:
	/* 0x1055: and    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 136ULL);
x86_l_105d:
	/* 0x105d: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_1060:
	/* 0x1060: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1063:
	/* 0x1063: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1066:
	/* 0x1066: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1069:
	/* 0x1069: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106e:
	/* 0x106e: cmp    QWORD PTR [r13+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_1076:
	/* 0x1076: je     111c <trace_security_mmap_file+0x111c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_111c;
	}
x86_l_107c:
	/* 0x107c: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1081:
	/* 0x1081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1083:
	/* 0x1083: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1087:
	/* 0x1087: mov    rbx,QWORD PTR [r13+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_108e:
	/* 0x108e: mov    rax,QWORD PTR [r13+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_1095:
	/* 0x1095: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_109a:
	/* 0x109a: mov    rbp,QWORD PTR [r13+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_10a1:
	/* 0x10a1: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_10a4:
	/* 0x10a4: mov    r13,QWORD PTR [r13+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_10ab:
	/* 0x10ab: movzx  eax,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_10b3:
	/* 0x10b3: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10b8:
	/* 0x10b8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_10bf:
	/* 0x10bf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10c4:
	/* 0x10c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c9:
	/* 0x10c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cb:
	/* 0x10cb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10ce:
	/* 0x10ce: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d2:
	/* 0x10d2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10d7:
	/* 0x10d7: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10de:
	/* 0x10de: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_10e1:
	/* 0x10e1: je     1100 <trace_security_mmap_file+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1100;
	}
x86_l_10e3:
	/* 0x10e3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10e8:
	/* 0x10e8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10ed:
	/* 0x10ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ef:
	/* 0x10ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f2:
	/* 0x10f2: je     1100 <trace_security_mmap_file+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1100;
	}
x86_l_10f4:
	/* 0x10f4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f7:
	/* 0x10f7: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fb:
	/* 0x10fb: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10fe:
	/* 0x10fe: jmp    1102 <trace_security_mmap_file+0x1102> */
	goto x86_l_1102;
x86_l_1100:
	/* 0x1100: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1102:
	/* 0x1102: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1105:
	/* 0x1105: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_110a:
	/* 0x110a: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_110d:
	/* 0x110d: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1110:
	/* 0x1110: jae    1133 <trace_security_mmap_file+0x1133> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1133;
	}
x86_l_1112:
	/* 0x1112: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_111a:
	/* 0x111a: jmp    114e <trace_security_mmap_file+0x114e> */
	goto x86_l_114e;
x86_l_111c:
	/* 0x111c: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_1124:
	/* 0x1124: cmp    QWORD PTR [r13+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_112c:
	/* 0x112c: jne    1167 <trace_security_mmap_file+0x1167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1167;
	}
x86_l_112e:
	/* 0x112e: jmp    1232 <trace_security_mmap_file+0x1232> */
	goto x86_l_1232;
x86_l_1133:
	/* 0x1133: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1137:
	/* 0x1137: movzx  ebp,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_113f:
	/* 0x113f: je     1146 <trace_security_mmap_file+0x1146> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1146;
	}
x86_l_1141:
	/* 0x1141: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1144:
	/* 0x1144: jbe    114e <trace_security_mmap_file+0x114e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_114e;
	}
x86_l_1146:
	/* 0x1146: and    r15,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 112ULL);
x86_l_114b:
	/* 0x114b: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_114e:
	/* 0x114e: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1151:
	/* 0x1151: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1154:
	/* 0x1154: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1159:
	/* 0x1159: cmp    QWORD PTR [r13+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_1161:
	/* 0x1161: je     1232 <trace_security_mmap_file+0x1232> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1232;
	}
x86_l_1167:
	/* 0x1167: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_116c:
	/* 0x116c: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1173:
	/* 0x1173: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1178:
	/* 0x1178: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_117d:
	/* 0x117d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1182:
	/* 0x1182: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1187:
	/* 0x1187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1189:
	/* 0x1189: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_118e:
	/* 0x118e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1192:
	/* 0x1192: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1197:
	/* 0x1197: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_119c:
	/* 0x119c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11a1:
	/* 0x11a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11a6:
	/* 0x11a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a8:
	/* 0x11a8: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ad:
	/* 0x11ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b2:
	/* 0x11b2: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_11b7:
	/* 0x11b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11bc:
	/* 0x11bc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c1:
	/* 0x11c1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11c6:
	/* 0x11c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c8:
	/* 0x11c8: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11cc:
	/* 0x11cc: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11d0:
	/* 0x11d0: mov    rbx,QWORD PTR [r13+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_11d7:
	/* 0x11d7: mov    r15,QWORD PTR [r13+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_11de:
	/* 0x11de: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e3:
	/* 0x11e3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_11ea:
	/* 0x11ea: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ef:
	/* 0x11ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11f4:
	/* 0x11f4: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11f7:
	/* 0x11f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f9:
	/* 0x11f9: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1200:
	/* 0x1200: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1203:
	/* 0x1203: je     1224 <trace_security_mmap_file+0x1224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1224;
	}
x86_l_1205:
	/* 0x1205: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1208:
	/* 0x1208: lea    rsi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_120c:
	/* 0x120c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1211:
	/* 0x1211: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1213:
	/* 0x1213: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1216:
	/* 0x1216: je     1224 <trace_security_mmap_file+0x1224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1224;
	}
x86_l_1218:
	/* 0x1218: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121b:
	/* 0x121b: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_121f:
	/* 0x121f: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1222:
	/* 0x1222: jmp    1226 <trace_security_mmap_file+0x1226> */
	goto x86_l_1226;
x86_l_1224:
	/* 0x1224: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1226:
	/* 0x1226: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1229:
	/* 0x1229: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_122c:
	/* 0x122c: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_122f:
	/* 0x122f: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1232:
	/* 0x1232: cmp    QWORD PTR [r13+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_123a:
	/* 0x123a: je     132e <trace_security_mmap_file+0x132e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_132e;
	}
x86_l_1240:
	/* 0x1240: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1247:
	/* 0x1247: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_124b:
	/* 0x124b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1250:
	/* 0x1250: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1255:
	/* 0x1255: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_125a:
	/* 0x125a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_125f:
	/* 0x125f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1261:
	/* 0x1261: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1266:
	/* 0x1266: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_126b:
	/* 0x126b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1270:
	/* 0x1270: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1275:
	/* 0x1275: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_127a:
	/* 0x127a: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_127d:
	/* 0x127d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_127f:
	/* 0x127f: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1283:
	/* 0x1283: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1287:
	/* 0x1287: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_128b:
	/* 0x128b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_128f:
	/* 0x128f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1294:
	/* 0x1294: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1299:
	/* 0x1299: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_129e:
	/* 0x129e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a3:
	/* 0x12a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a5:
	/* 0x12a5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12aa:
	/* 0x12aa: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_12ae:
	/* 0x12ae: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b3:
	/* 0x12b3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12b8:
	/* 0x12b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_12bd:
	/* 0x12bd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12c2:
	/* 0x12c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c4:
	/* 0x12c4: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12c8:
	/* 0x12c8: mov    DWORD PTR [r13+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12cc:
	/* 0x12cc: mov    rbx,QWORD PTR [r13+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_12d3:
	/* 0x12d3: mov    r15,QWORD PTR [r13+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_12da:
	/* 0x12da: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12df:
	/* 0x12df: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_12e6:
	/* 0x12e6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12eb:
	/* 0x12eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12f0:
	/* 0x12f0: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12f3:
	/* 0x12f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f5:
	/* 0x12f5: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12fc:
	/* 0x12fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ff:
	/* 0x12ff: je     1320 <trace_security_mmap_file+0x1320> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1320;
	}
x86_l_1301:
	/* 0x1301: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1304:
	/* 0x1304: lea    rsi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1308:
	/* 0x1308: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130d:
	/* 0x130d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130f:
	/* 0x130f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1312:
	/* 0x1312: je     1320 <trace_security_mmap_file+0x1320> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1320;
	}
x86_l_1314:
	/* 0x1314: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1317:
	/* 0x1317: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131b:
	/* 0x131b: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_131e:
	/* 0x131e: jmp    1322 <trace_security_mmap_file+0x1322> */
	goto x86_l_1322;
x86_l_1320:
	/* 0x1320: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1322:
	/* 0x1322: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1325:
	/* 0x1325: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1328:
	/* 0x1328: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_132b:
	/* 0x132b: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_132e:
	/* 0x132e: cmp    QWORD PTR [r13+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1336:
	/* 0x1336: je     1418 <trace_security_mmap_file+0x1418> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1418;
	}
x86_l_133c:
	/* 0x133c: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1341:
	/* 0x1341: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1348:
	/* 0x1348: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_134d:
	/* 0x134d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1352:
	/* 0x1352: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1357:
	/* 0x1357: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135c:
	/* 0x135c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135e:
	/* 0x135e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1363:
	/* 0x1363: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1368:
	/* 0x1368: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_136d:
	/* 0x136d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1372:
	/* 0x1372: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1377:
	/* 0x1377: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1379:
	/* 0x1379: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137e:
	/* 0x137e: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1383:
	/* 0x1383: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_1388:
	/* 0x1388: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_138d:
	/* 0x138d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1390:
	/* 0x1390: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1395:
	/* 0x1395: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1397:
	/* 0x1397: lea    rbx,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_139b:
	/* 0x139b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_13a0:
	/* 0x13a0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_13a5:
	/* 0x13a5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13a8:
	/* 0x13a8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13ad:
	/* 0x13ad: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13b0:
	/* 0x13b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b2:
	/* 0x13b2: mov    r15,QWORD PTR [r13+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_13b9:
	/* 0x13b9: mov    r13,QWORD PTR [r13+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_13c0:
	/* 0x13c0: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c5:
	/* 0x13c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_13cc:
	/* 0x13cc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13d1:
	/* 0x13d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d6:
	/* 0x13d6: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_13d9:
	/* 0x13d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13db:
	/* 0x13db: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_13e2:
	/* 0x13e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13e5:
	/* 0x13e5: je     1405 <trace_security_mmap_file+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_13e7:
	/* 0x13e7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_13ea:
	/* 0x13ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ef:
	/* 0x13ef: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_13f2:
	/* 0x13f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f4:
	/* 0x13f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13f7:
	/* 0x13f7: je     1405 <trace_security_mmap_file+0x1405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1405;
	}
x86_l_13f9:
	/* 0x13f9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13fc:
	/* 0x13fc: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1400:
	/* 0x1400: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1403:
	/* 0x1403: jmp    1407 <trace_security_mmap_file+0x1407> */
	goto x86_l_1407;
x86_l_1405:
	/* 0x1405: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1407:
	/* 0x1407: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_140a:
	/* 0x140a: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_140d:
	/* 0x140d: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1410:
	/* 0x1410: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1413:
	/* 0x1413: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1418:
	/* 0x1418: cmp    QWORD PTR [r13+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_1420:
	/* 0x1420: je     14a4 <trace_security_mmap_file+0x14a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a4;
	}
x86_l_1426:
	/* 0x1426: lea    rbx,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_142a:
	/* 0x142a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1434:
	/* 0x1434: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1437:
	/* 0x1437: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_143c:
	/* 0x143c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143e:
	/* 0x143e: mov    r15,QWORD PTR [r13+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1445:
	/* 0x1445: mov    r13,QWORD PTR [r13+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_144c:
	/* 0x144c: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1451:
	/* 0x1451: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1458:
	/* 0x1458: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_145d:
	/* 0x145d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1462:
	/* 0x1462: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1465:
	/* 0x1465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1467:
	/* 0x1467: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_146e:
	/* 0x146e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1471:
	/* 0x1471: je     1491 <trace_security_mmap_file+0x1491> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1491;
	}
x86_l_1473:
	/* 0x1473: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1476:
	/* 0x1476: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147b:
	/* 0x147b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_147e:
	/* 0x147e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1480:
	/* 0x1480: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1483:
	/* 0x1483: je     1491 <trace_security_mmap_file+0x1491> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1491;
	}
x86_l_1485:
	/* 0x1485: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1488:
	/* 0x1488: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_148c:
	/* 0x148c: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_148f:
	/* 0x148f: jmp    1493 <trace_security_mmap_file+0x1493> */
	goto x86_l_1493;
x86_l_1491:
	/* 0x1491: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1493:
	/* 0x1493: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1496:
	/* 0x1496: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1499:
	/* 0x1499: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_149c:
	/* 0x149c: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_149f:
	/* 0x149f: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14a4:
	/* 0x14a4: mov    rbx,QWORD PTR [r13+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_14ab:
	/* 0x14ab: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: je     1514 <trace_security_mmap_file+0x1514> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1514;
	}
x86_l_14b0:
	/* 0x14b0: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b4:
	/* 0x14b4: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14b8:
	/* 0x14b8: mov    r15,QWORD PTR [r13+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_14bf:
	/* 0x14bf: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14c4:
	/* 0x14c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_14cb:
	/* 0x14cb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14d0:
	/* 0x14d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d5:
	/* 0x14d5: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_14d8:
	/* 0x14d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14da:
	/* 0x14da: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_14e1:
	/* 0x14e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14e4:
	/* 0x14e4: je     1506 <trace_security_mmap_file+0x1506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1506;
	}
x86_l_14e6:
	/* 0x14e6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14e9:
	/* 0x14e9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14ee:
	/* 0x14ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f3:
	/* 0x14f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f5:
	/* 0x14f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f8:
	/* 0x14f8: je     1506 <trace_security_mmap_file+0x1506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1506;
	}
x86_l_14fa:
	/* 0x14fa: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fd:
	/* 0x14fd: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1501:
	/* 0x1501: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1504:
	/* 0x1504: jmp    1508 <trace_security_mmap_file+0x1508> */
	goto x86_l_1508;
x86_l_1506:
	/* 0x1506: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1508:
	/* 0x1508: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_150b:
	/* 0x150b: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_150e:
	/* 0x150e: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1511:
	/* 0x1511: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_1514:
	/* 0x1514: mov    rbx,QWORD PTR [r13+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_151b:
	/* 0x151b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_151e:
	/* 0x151e: je     157f <trace_security_mmap_file+0x157f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5503ULL;
	}
x86_l_1520:
	/* 0x1520: mov    r15,QWORD PTR [r13+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1527:
	/* 0x1527: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_152c:
	/* 0x152c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1533:
	/* 0x1533: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1538:
	/* 0x1538: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153d:
	/* 0x153d: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1540:
	/* 0x1540: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1542:
	/* 0x1542: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1549:
	/* 0x1549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 5452ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5452ULL: goto x86_l_154c;
	case 5454ULL: goto x86_l_154e;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5477ULL: goto x86_l_1565;
	case 5480ULL: goto x86_l_1568;
	case 5484ULL: goto x86_l_156c;
	case 5487ULL: goto x86_l_156f;
	case 5489ULL: goto x86_l_1571;
	case 5491ULL: goto x86_l_1573;
	case 5494ULL: goto x86_l_1576;
	case 5497ULL: goto x86_l_1579;
	case 5500ULL: goto x86_l_157c;
	case 5503ULL: goto x86_l_157f;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5519ULL: goto x86_l_158f;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5538ULL: goto x86_l_15a2;
	case 5543ULL: goto x86_l_15a7;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5565ULL: goto x86_l_15bd;
	case 5568ULL: goto x86_l_15c0;
	case 5573ULL: goto x86_l_15c5;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5587ULL: goto x86_l_15d3;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5597ULL: goto x86_l_15dd;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5609ULL: goto x86_l_15e9;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5616ULL: goto x86_l_15f0;
	case 5619ULL: goto x86_l_15f3;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5630ULL: goto x86_l_15fe;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5639ULL: goto x86_l_1607;
	case 5642ULL: goto x86_l_160a;
	case 5647ULL: goto x86_l_160f;
	case 5654ULL: goto x86_l_1616;
	case 5657ULL: goto x86_l_1619;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5676ULL: goto x86_l_162c;
	case 5679ULL: goto x86_l_162f;
	case 5686ULL: goto x86_l_1636;
	case 5693ULL: goto x86_l_163d;
	case 5697ULL: goto x86_l_1641;
	case 5705ULL: goto x86_l_1649;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5723ULL: goto x86_l_165b;
	case 5731ULL: goto x86_l_1663;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5756ULL: goto x86_l_167c;
	case 5764ULL: goto x86_l_1684;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5781ULL: goto x86_l_1695;
	case 5783ULL: goto x86_l_1697;
	case 5786ULL: goto x86_l_169a;
	case 5792ULL: goto x86_l_16a0;
	case 5795ULL: goto x86_l_16a3;
	case 5803ULL: goto x86_l_16ab;
	case 5807ULL: goto x86_l_16af;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5822ULL: goto x86_l_16be;
	case 5827ULL: goto x86_l_16c3;
	case 5829ULL: goto x86_l_16c5;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5877ULL: goto x86_l_16f5;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5891ULL: goto x86_l_1703;
	case 5896ULL: goto x86_l_1708;
	case 5901ULL: goto x86_l_170d;
	case 5903ULL: goto x86_l_170f;
	case 5908ULL: goto x86_l_1714;
	case 5912ULL: goto x86_l_1718;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5942ULL: goto x86_l_1736;
	case 5947ULL: goto x86_l_173b;
	case 5952ULL: goto x86_l_1740;
	case 5957ULL: goto x86_l_1745;
	case 5962ULL: goto x86_l_174a;
	case 5965ULL: goto x86_l_174d;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5977ULL: goto x86_l_1759;
	case 5981ULL: goto x86_l_175d;
	case 5986ULL: goto x86_l_1762;
	case 5991ULL: goto x86_l_1767;
	case 5996ULL: goto x86_l_176c;
	case 6001ULL: goto x86_l_1771;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6011ULL: goto x86_l_177b;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6025ULL: goto x86_l_1789;
	case 6031ULL: goto x86_l_178f;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6055ULL: goto x86_l_17a7;
	case 6057ULL: goto x86_l_17a9;
	case 6061ULL: goto x86_l_17ad;
	case 6066ULL: goto x86_l_17b2;
	case 6068ULL: goto x86_l_17b4;
	case 6074ULL: goto x86_l_17ba;
	case 6076ULL: goto x86_l_17bc;
	case 6078ULL: goto x86_l_17be;
	case 6084ULL: goto x86_l_17c4;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6138ULL: goto x86_l_17fa;
	case 6146ULL: goto x86_l_1802;
	case 6151ULL: goto x86_l_1807;
	case 6154ULL: goto x86_l_180a;
	case 6159ULL: goto x86_l_180f;
	case 6166ULL: goto x86_l_1816;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6187ULL: goto x86_l_182b;
	case 6193ULL: goto x86_l_1831;
	case 6197ULL: goto x86_l_1835;
	case 6202ULL: goto x86_l_183a;
	case 6208ULL: goto x86_l_1840;
	case 6212ULL: goto x86_l_1844;
	case 6217ULL: goto x86_l_1849;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6240ULL: goto x86_l_1860;
	case 6242ULL: goto x86_l_1862;
	case 6246ULL: goto x86_l_1866;
	case 6249ULL: goto x86_l_1869;
	case 6254ULL: goto x86_l_186e;
	case 6259ULL: goto x86_l_1873;
	case 6263ULL: goto x86_l_1877;
	case 6268ULL: goto x86_l_187c;
	case 6270ULL: goto x86_l_187e;
	case 6274ULL: goto x86_l_1882;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6300ULL: goto x86_l_189c;
	case 6304ULL: goto x86_l_18a0;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6323ULL: goto x86_l_18b3;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6336ULL: goto x86_l_18c0;
	case 6338ULL: goto x86_l_18c2;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6379ULL: goto x86_l_18eb;
	case 6382ULL: goto x86_l_18ee;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6394ULL: goto x86_l_18fa;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6420ULL: goto x86_l_1914;
	case 6424ULL: goto x86_l_1918;
	case 6426ULL: goto x86_l_191a;
	case 6432ULL: goto x86_l_1920;
	case 6434ULL: goto x86_l_1922;
	case 6436ULL: goto x86_l_1924;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6453ULL: goto x86_l_1935;
	case 6456ULL: goto x86_l_1938;
	case 6459ULL: goto x86_l_193b;
	case 6461ULL: goto x86_l_193d;
	case 6466ULL: goto x86_l_1942;
	case 6468ULL: goto x86_l_1944;
	case 6471ULL: goto x86_l_1947;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6499ULL: goto x86_l_1963;
	case 6502ULL: goto x86_l_1966;
	case 6508ULL: goto x86_l_196c;
	case 6514ULL: goto x86_l_1972;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6549ULL: goto x86_l_1995;
	case 6551ULL: goto x86_l_1997;
	case 6556ULL: goto x86_l_199c;
	case 6561ULL: goto x86_l_19a1;
	case 6566ULL: goto x86_l_19a6;
	case 6569ULL: goto x86_l_19a9;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6595ULL: goto x86_l_19c3;
	case 6601ULL: goto x86_l_19c9;
	case 6607ULL: goto x86_l_19cf;
	case 6616ULL: goto x86_l_19d8;
	case 6624ULL: goto x86_l_19e0;
	case 6632ULL: goto x86_l_19e8;
	case 6638ULL: goto x86_l_19ee;
	case 6640ULL: goto x86_l_19f0;
	case 6644ULL: goto x86_l_19f4;
	case 6651ULL: goto x86_l_19fb;
	case 6656ULL: goto x86_l_1a00;
	case 6661ULL: goto x86_l_1a05;
	case 6669ULL: goto x86_l_1a0d;
	case 6673ULL: goto x86_l_1a11;
	case 6680ULL: goto x86_l_1a18;
	case 6685ULL: goto x86_l_1a1d;
	case 6688ULL: goto x86_l_1a20;
	case 6690ULL: goto x86_l_1a22;
	case 6692ULL: goto x86_l_1a24;
	case 6694ULL: goto x86_l_1a26;
	case 6702ULL: goto x86_l_1a2e;
	case 6709ULL: goto x86_l_1a35;
	case 6711ULL: goto x86_l_1a37;
	case 6719ULL: goto x86_l_1a3f;
	case 6727ULL: goto x86_l_1a47;
	case 6730ULL: goto x86_l_1a4a;
	case 6738ULL: goto x86_l_1a52;
	case 6745ULL: goto x86_l_1a59;
	case 6753ULL: goto x86_l_1a61;
	case 6760ULL: goto x86_l_1a68;
	case 6762ULL: goto x86_l_1a6a;
	case 6771ULL: goto x86_l_1a73;
	case 6777ULL: goto x86_l_1a79;
	case 6779ULL: goto x86_l_1a7b;
	case 6787ULL: goto x86_l_1a83;
	case 6791ULL: goto x86_l_1a87;
	case 6795ULL: goto x86_l_1a8b;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6824ULL: goto x86_l_1aa8;
	case 6827ULL: goto x86_l_1aab;
	case 6835ULL: goto x86_l_1ab3;
	case 6842ULL: goto x86_l_1aba;
	case 6850ULL: goto x86_l_1ac2;
	case 6857ULL: goto x86_l_1ac9;
	case 6859ULL: goto x86_l_1acb;
	case 6868ULL: goto x86_l_1ad4;
	case 6874ULL: goto x86_l_1ada;
	case 6876ULL: goto x86_l_1adc;
	case 6880ULL: goto x86_l_1ae0;
	case 6887ULL: goto x86_l_1ae7;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6912ULL: goto x86_l_1b00;
	case 6915ULL: goto x86_l_1b03;
	case 6917ULL: goto x86_l_1b05;
	case 6920ULL: goto x86_l_1b08;
	case 6928ULL: goto x86_l_1b10;
	case 6935ULL: goto x86_l_1b17;
	case 6943ULL: goto x86_l_1b1f;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6961ULL: goto x86_l_1b31;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6973ULL: goto x86_l_1b3d;
	case 6980ULL: goto x86_l_1b44;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7003ULL: goto x86_l_1b5b;
	case 7005ULL: goto x86_l_1b5d;
	case 7008ULL: goto x86_l_1b60;
	case 7010ULL: goto x86_l_1b62;
	case 7013ULL: goto x86_l_1b65;
	case 7021ULL: goto x86_l_1b6d;
	case 7028ULL: goto x86_l_1b74;
	case 7036ULL: goto x86_l_1b7c;
	case 7044ULL: goto x86_l_1b84;
	case 7051ULL: goto x86_l_1b8b;
	case 7053ULL: goto x86_l_1b8d;
	case 7062ULL: goto x86_l_1b96;
	case 7068ULL: goto x86_l_1b9c;
	case 7070ULL: goto x86_l_1b9e;
	case 7074ULL: goto x86_l_1ba2;
	case 7081ULL: goto x86_l_1ba9;
	case 7089ULL: goto x86_l_1bb1;
	case 7094ULL: goto x86_l_1bb6;
	case 7099ULL: goto x86_l_1bbb;
	case 7104ULL: goto x86_l_1bc0;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7122ULL: goto x86_l_1bd2;
	case 7129ULL: goto x86_l_1bd9;
	case 7136ULL: goto x86_l_1be0;
	case 7140ULL: goto x86_l_1be4;
	case 7145ULL: goto x86_l_1be9;
	case 7150ULL: goto x86_l_1bee;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7163ULL: goto x86_l_1bfb;
	case 7165ULL: goto x86_l_1bfd;
	case 7170ULL: goto x86_l_1c02;
	case 7178ULL: goto x86_l_1c0a;
	case 7182ULL: goto x86_l_1c0e;
	case 7187ULL: goto x86_l_1c13;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7202ULL: goto x86_l_1c22;
	case 7204ULL: goto x86_l_1c24;
	default: return 0xffffffffffffffffULL;
	}
x86_l_154c:
	/* 0x154c: je     1571 <trace_security_mmap_file+0x1571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1571;
	}
x86_l_154e:
	/* 0x154e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1551:
	/* 0x1551: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1556:
	/* 0x1556: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_155e:
	/* 0x155e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1560:
	/* 0x1560: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1563:
	/* 0x1563: je     1571 <trace_security_mmap_file+0x1571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1571;
	}
x86_l_1565:
	/* 0x1565: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1568:
	/* 0x1568: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_156c:
	/* 0x156c: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_156f:
	/* 0x156f: jmp    1573 <trace_security_mmap_file+0x1573> */
	goto x86_l_1573;
x86_l_1571:
	/* 0x1571: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1573:
	/* 0x1573: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1576:
	/* 0x1576: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1579:
	/* 0x1579: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_157c:
	/* 0x157c: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_157f:
	/* 0x157f: mov    r15,QWORD PTR [r13+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1586:
	/* 0x1586: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1589:
	/* 0x1589: je     160f <trace_security_mmap_file+0x160f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_160f;
	}
x86_l_158f:
	/* 0x158f: mov    r13,QWORD PTR [r13+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1596:
	/* 0x1596: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_159b:
	/* 0x159b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_15a2:
	/* 0x15a2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a7:
	/* 0x15a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15ac:
	/* 0x15ac: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15af:
	/* 0x15af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b1:
	/* 0x15b1: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15b8:
	/* 0x15b8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15bb:
	/* 0x15bb: je     15fc <trace_security_mmap_file+0x15fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15fc;
	}
x86_l_15bd:
	/* 0x15bd: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_15c0:
	/* 0x15c0: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15c5:
	/* 0x15c5: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_15c9:
	/* 0x15c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15ce:
	/* 0x15ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15d1:
	/* 0x15d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d3:
	/* 0x15d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d6:
	/* 0x15d6: jne    15f0 <trace_security_mmap_file+0x15f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15f0;
	}
x86_l_15d8:
	/* 0x15d8: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_15dd:
	/* 0x15dd: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e1:
	/* 0x15e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15e6:
	/* 0x15e6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15e9:
	/* 0x15e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15eb:
	/* 0x15eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15ee:
	/* 0x15ee: je     15fc <trace_security_mmap_file+0x15fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15fc;
	}
x86_l_15f0:
	/* 0x15f0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f3:
	/* 0x15f3: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15f7:
	/* 0x15f7: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_15fa:
	/* 0x15fa: jmp    15fe <trace_security_mmap_file+0x15fe> */
	goto x86_l_15fe;
x86_l_15fc:
	/* 0x15fc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15fe:
	/* 0x15fe: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1601:
	/* 0x1601: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1604:
	/* 0x1604: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1607:
	/* 0x1607: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_160a:
	/* 0x160a: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_160f:
	/* 0x160f: mov    rax,QWORD PTR [r13+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1616:
	/* 0x1616: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1619:
	/* 0x1619: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1621:
	/* 0x1621: je     162f <trace_security_mmap_file+0x162f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_162f;
	}
x86_l_1623:
	/* 0x1623: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1628:
	/* 0x1628: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_162c:
	/* 0x162c: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_162f:
	/* 0x162f: and    r12,QWORD PTR [r13+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1636:
	/* 0x1636: lea    rcx,[r13+0x7d8c] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_163d:
	/* 0x163d: lea    rax,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1641:
	/* 0x1641: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1649:
	/* 0x1649: and    QWORD PTR [r13+0x80],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_1650:
	/* 0x1650: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1655:
	/* 0x1655: je     17f8 <trace_security_mmap_file+0x17f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17f8;
	}
x86_l_165b:
	/* 0x165b: test   BYTE PTR [rsp+0xe8],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 996432412676ULL);
x86_l_1663:
	/* 0x1663: mov    r14,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_166b:
	/* 0x166b: je     17f1 <trace_security_mmap_file+0x17f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17f1;
	}
x86_l_1671:
	/* 0x1671: cmp    DWORD PTR [r13+0x74],0x9 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206345ULL);
x86_l_1676:
	/* 0x1676: jne    17f1 <trace_security_mmap_file+0x17f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17f1;
	}
x86_l_167c:
	/* 0x167c: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1684:
	/* 0x1684: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_168b:
	/* 0x168b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1690:
	/* 0x1690: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1695:
	/* 0x1695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1697:
	/* 0x1697: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_169a:
	/* 0x169a: je     1807 <trace_security_mmap_file+0x1807> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1807;
	}
x86_l_16a0:
	/* 0x16a0: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_16a3:
	/* 0x16a3: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_16ab:
	/* 0x16ab: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16af:
	/* 0x16af: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16b4:
	/* 0x16b4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16b9:
	/* 0x16b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16be:
	/* 0x16be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c3:
	/* 0x16c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c5:
	/* 0x16c5: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16ca:
	/* 0x16ca: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cf:
	/* 0x16cf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16d4:
	/* 0x16d4: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_16d9:
	/* 0x16d9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16de:
	/* 0x16de: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e3:
	/* 0x16e3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16e8:
	/* 0x16e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ea:
	/* 0x16ea: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_16ef:
	/* 0x16ef: jne    180f <trace_security_mmap_file+0x180f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_180f;
	}
x86_l_16f5:
	/* 0x16f5: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f9:
	/* 0x16f9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16fe:
	/* 0x16fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1703:
	/* 0x1703: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1708:
	/* 0x1708: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_170d:
	/* 0x170d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170f:
	/* 0x170f: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1714:
	/* 0x1714: lea    rcx,[rbp-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_1718:
	/* 0x1718: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_171c:
	/* 0x171c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1721:
	/* 0x1721: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_1726:
	/* 0x1726: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_172b:
	/* 0x172b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172f:
	/* 0x172f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1734:
	/* 0x1734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1736:
	/* 0x1736: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_173b:
	/* 0x173b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1740:
	/* 0x1740: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1745:
	/* 0x1745: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_174a:
	/* 0x174a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_174d:
	/* 0x174d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174f:
	/* 0x174f: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1754:
	/* 0x1754: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1759:
	/* 0x1759: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_175d:
	/* 0x175d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x1773: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1778:
	/* 0x1778: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_177b:
	/* 0x177b: je     1828 <trace_security_mmap_file+0x1828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1828;
	}
x86_l_1781:
	/* 0x1781: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1786:
	/* 0x1786: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1789:
	/* 0x1789: je     1828 <trace_security_mmap_file+0x1828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1828;
	}
x86_l_178f:
	/* 0x178f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1793:
	/* 0x1793: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1798:
	/* 0x1798: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_179d:
	/* 0x179d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17a2:
	/* 0x17a2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17a7:
	/* 0x17a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a9:
	/* 0x17a9: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17ad:
	/* 0x17ad: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17b2:
	/* 0x17b2: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_17b4:
	/* 0x17b4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_17ba:
	/* 0x17ba: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_17bc:
	/* 0x17bc: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_17be:
	/* 0x17be: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_17c4:
	/* 0x17c4: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17c7:
	/* 0x17c7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_17cc:
	/* 0x17cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ce:
	/* 0x17ce: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17d1:
	/* 0x17d1: jl     1978 <trace_security_mmap_file+0x1978> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1978;
	}
x86_l_17d7:
	/* 0x17d7: mov    BYTE PTR [r12+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_17e0:
	/* 0x17e0: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_17e5:
	/* 0x17e5: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17e7:
	/* 0x17e7: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17ec:
	/* 0x17ec: jmp    18a9 <trace_security_mmap_file+0x18a9> */
	goto x86_l_18a9;
x86_l_17f1:
	/* 0x17f1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17f3:
	/* 0x17f3: jmp    210a <trace_security_mmap_file+0x210a> */
	return 8458ULL;
x86_l_17f8:
	/* 0x17f8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17fa:
	/* 0x17fa: mov    r14,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1802:
	/* 0x1802: jmp    210a <trace_security_mmap_file+0x210a> */
	return 8458ULL;
x86_l_1807:
	/* 0x1807: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_180a:
	/* 0x180a: jmp    19bb <trace_security_mmap_file+0x19bb> */
	goto x86_l_19bb;
x86_l_180f:
	/* 0x180f: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1816:
	/* 0x1816: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_181b:
	/* 0x181b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1820:
	/* 0x1820: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1823:
	/* 0x1823: jmp    19a9 <trace_security_mmap_file+0x19a9> */
	goto x86_l_19a9;
x86_l_1828:
	/* 0x1828: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_182b:
	/* 0x182b: jne    1978 <trace_security_mmap_file+0x1978> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1978;
	}
x86_l_1831:
	/* 0x1831: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1835:
	/* 0x1835: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_183a:
	/* 0x183a: je     1978 <trace_security_mmap_file+0x1978> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1978;
	}
x86_l_1840:
	/* 0x1840: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1844:
	/* 0x1844: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1849:
	/* 0x1849: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_184e:
	/* 0x184e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1853:
	/* 0x1853: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1857:
	/* 0x1857: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_185b:
	/* 0x185b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1860:
	/* 0x1860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1862:
	/* 0x1862: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1866:
	/* 0x1866: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1869:
	/* 0x1869: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_186e:
	/* 0x186e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1873:
	/* 0x1873: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1877:
	/* 0x1877: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_187c:
	/* 0x187c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187e:
	/* 0x187e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1882:
	/* 0x1882: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1887:
	/* 0x1887: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_188c:
	/* 0x188c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1891:
	/* 0x1891: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1895:
	/* 0x1895: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189a:
	/* 0x189a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189c:
	/* 0x189c: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a0:
	/* 0x18a0: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18a4:
	/* 0x18a4: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_18a9:
	/* 0x18a9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18ae:
	/* 0x18ae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18b3:
	/* 0x18b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18b8:
	/* 0x18b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18bd:
	/* 0x18bd: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_18c0:
	/* 0x18c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c2:
	/* 0x18c2: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c7:
	/* 0x18c7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18cc:
	/* 0x18cc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_18d0:
	/* 0x18d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18d5:
	/* 0x18d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18da:
	/* 0x18da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_18df:
	/* 0x18df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18e4:
	/* 0x18e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e6:
	/* 0x18e6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18eb:
	/* 0x18eb: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_18ee:
	/* 0x18ee: je     1963 <trace_security_mmap_file+0x1963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1963;
	}
x86_l_18f0:
	/* 0x18f0: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18f5:
	/* 0x18f5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18f8:
	/* 0x18f8: je     1963 <trace_security_mmap_file+0x1963> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1963;
	}
x86_l_18fa:
	/* 0x18fa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_18fe:
	/* 0x18fe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1903:
	/* 0x1903: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1908:
	/* 0x1908: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_190d:
	/* 0x190d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1912:
	/* 0x1912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1914:
	/* 0x1914: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1918:
	/* 0x1918: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_191a:
	/* 0x191a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1920:
	/* 0x1920: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_1922:
	/* 0x1922: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1924:
	/* 0x1924: jb     2e4c <trace_security_mmap_file+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11852ULL;
	}
x86_l_192a:
	/* 0x192a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_192f:
	/* 0x192f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1935:
	/* 0x1935: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_1938:
	/* 0x1938: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_193b:
	/* 0x193b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_193d:
	/* 0x193d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1942:
	/* 0x1942: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1944:
	/* 0x1944: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1947:
	/* 0x1947: jl     196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_196c;
	}
x86_l_1949:
	/* 0x1949: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_194c:
	/* 0x194c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1952:
	/* 0x1952: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1957:
	/* 0x1957: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1959:
	/* 0x1959: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_195e:
	/* 0x195e: jmp    2dcb <trace_security_mmap_file+0x2dcb> */
	return 11723ULL;
x86_l_1963:
	/* 0x1963: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1966:
	/* 0x1966: je     2d58 <trace_security_mmap_file+0x2d58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11608ULL;
	}
x86_l_196c:
	/* 0x196c: cmp    ebx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_1972:
	/* 0x1972: jne    2e4c <trace_security_mmap_file+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11852ULL;
	}
x86_l_1978:
	/* 0x1978: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197d:
	/* 0x197d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1981:
	/* 0x1981: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1986:
	/* 0x1986: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_198b:
	/* 0x198b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1990:
	/* 0x1990: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1995:
	/* 0x1995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1997:
	/* 0x1997: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_199c:
	/* 0x199c: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_19a1:
	/* 0x19a1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_19a6:
	/* 0x19a6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19a9:
	/* 0x19a9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_19ae:
	/* 0x19ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b0:
	/* 0x19b0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b2:
	/* 0x19b2: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19b8:
	/* 0x19b8: add    r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19bb:
	/* 0x19bb: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19c3:
	/* 0x19c3: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_19c9:
	/* 0x19c9: ja     1a59 <trace_security_mmap_file+0x1a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a59;
	}
x86_l_19cf:
	/* 0x19cf: mov    BYTE PTR [r13+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_19d8:
	/* 0x19d8: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_19e0:
	/* 0x19e0: mov    WORD PTR [r13+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_19e8:
	/* 0x19e8: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_19ee:
	/* 0x19ee: ja     1a59 <trace_security_mmap_file+0x1a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a59;
	}
x86_l_19f0:
	/* 0x19f0: lea    rcx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_19f4:
	/* 0x19f4: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_19fb:
	/* 0x19fb: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_1a00:
	/* 0x1a00: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1a05:
	/* 0x1a05: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a0d:
	/* 0x1a0d: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1a11:
	/* 0x1a11: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1a18:
	/* 0x1a18: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a20:
	/* 0x1a20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a22:
	/* 0x1a22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a24:
	/* 0x1a24: jle    1a59 <trace_security_mmap_file+0x1a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a59;
	}
x86_l_1a26:
	/* 0x1a26: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a2e:
	/* 0x1a2e: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_1a35:
	/* 0x1a35: ja     1a59 <trace_security_mmap_file+0x1a59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a59;
	}
x86_l_1a37:
	/* 0x1a37: mov    DWORD PTR [rcx+r13*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_1a3f:
	/* 0x1a3f: add    ax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1a47:
	/* 0x1a47: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    WORD PTR [r13+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1a52:
	/* 0x1a52: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1a59:
	/* 0x1a59: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1a61:
	/* 0x1a61: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1a68:
	/* 0x1a68: ja     1aba <trace_security_mmap_file+0x1aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1aba;
	}
x86_l_1a6a:
	/* 0x1a6a: mov    BYTE PTR [r13+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_1a73:
	/* 0x1a73: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1a79:
	/* 0x1a79: ja     1aba <trace_security_mmap_file+0x1aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1aba;
	}
x86_l_1a7b:
	/* 0x1a7b: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a83:
	/* 0x1a83: lea    rdx,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a87:
	/* 0x1a87: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1a8b:
	/* 0x1a8b: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1a92:
	/* 0x1a92: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a97:
	/* 0x1a97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aa1:
	/* 0x1aa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa3:
	/* 0x1aa3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1aa6:
	/* 0x1aa6: js     1aba <trace_security_mmap_file+0x1aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1aba;
	}
x86_l_1aa8:
	/* 0x1aa8: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1aab:
	/* 0x1aab: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1ab3:
	/* 0x1ab3: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1aba:
	/* 0x1aba: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1ac2:
	/* 0x1ac2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1ac9:
	/* 0x1ac9: ja     1b17 <trace_security_mmap_file+0x1b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b17;
	}
x86_l_1acb:
	/* 0x1acb: mov    BYTE PTR [r13+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1ad4:
	/* 0x1ad4: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1ada:
	/* 0x1ada: ja     1b17 <trace_security_mmap_file+0x1b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b17;
	}
x86_l_1adc:
	/* 0x1adc: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1ae0:
	/* 0x1ae0: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1ae7:
	/* 0x1ae7: lea    rdx,[rsp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1aef:
	/* 0x1aef: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1af4:
	/* 0x1af4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1af9:
	/* 0x1af9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1afe:
	/* 0x1afe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b00:
	/* 0x1b00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b03:
	/* 0x1b03: js     1b17 <trace_security_mmap_file+0x1b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b17;
	}
x86_l_1b05:
	/* 0x1b05: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1b08:
	/* 0x1b08: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b10:
	/* 0x1b10: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1b17:
	/* 0x1b17: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b1f:
	/* 0x1b1f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1b26:
	/* 0x1b26: ja     1b74 <trace_security_mmap_file+0x1b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b74;
	}
x86_l_1b28:
	/* 0x1b28: mov    BYTE PTR [r13+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_1b31:
	/* 0x1b31: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1b37:
	/* 0x1b37: ja     1b74 <trace_security_mmap_file+0x1b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b74;
	}
x86_l_1b39:
	/* 0x1b39: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1b3d:
	/* 0x1b3d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1b44:
	/* 0x1b44: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b51:
	/* 0x1b51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b56:
	/* 0x1b56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b5b:
	/* 0x1b5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5d:
	/* 0x1b5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b60:
	/* 0x1b60: js     1b74 <trace_security_mmap_file+0x1b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1b74;
	}
x86_l_1b62:
	/* 0x1b62: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1b65:
	/* 0x1b65: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1b6d:
	/* 0x1b6d: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1b74:
	/* 0x1b74: mov    QWORD PTR [rsp+0x88],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b7c:
	/* 0x1b7c: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1b84:
	/* 0x1b84: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1b8b:
	/* 0x1b8b: ja     1bd9 <trace_security_mmap_file+0x1bd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bd9;
	}
x86_l_1b8d:
	/* 0x1b8d: mov    BYTE PTR [r13+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_1b96:
	/* 0x1b96: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1b9c:
	/* 0x1b9c: ja     1bd9 <trace_security_mmap_file+0x1bd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1bd9;
	}
x86_l_1b9e:
	/* 0x1b9e: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1ba2:
	/* 0x1ba2: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_1ba9:
	/* 0x1ba9: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1bb1:
	/* 0x1bb1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bbb:
	/* 0x1bbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc0:
	/* 0x1bc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc2:
	/* 0x1bc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bc5:
	/* 0x1bc5: js     1bd9 <trace_security_mmap_file+0x1bd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1bd9;
	}
x86_l_1bc7:
	/* 0x1bc7: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1bca:
	/* 0x1bca: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1bd2:
	/* 0x1bd2: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1bd9:
	/* 0x1bd9: mov    rbp,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_1be0:
	/* 0x1be0: lea    r12,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1be4:
	/* 0x1be4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1be9:
	/* 0x1be9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bee:
	/* 0x1bee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bf8:
	/* 0x1bf8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bfb:
	/* 0x1bfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfd:
	/* 0x1bfd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c02:
	/* 0x1c02: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c0a:
	/* 0x1c0a: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c0e:
	/* 0x1c0e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c13:
	/* 0x1c13: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c18:
	/* 0x1c18: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c22:
	/* 0x1c22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c24:
	/* 0x1c24: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 7209ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7209ULL: goto x86_l_1c29;
	case 7213ULL: goto x86_l_1c2d;
	case 7218ULL: goto x86_l_1c32;
	case 7223ULL: goto x86_l_1c37;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7270ULL: goto x86_l_1c66;
	case 7274ULL: goto x86_l_1c6a;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7303ULL: goto x86_l_1c87;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7318ULL: goto x86_l_1c96;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7337ULL: goto x86_l_1ca9;
	case 7341ULL: goto x86_l_1cad;
	case 7345ULL: goto x86_l_1cb1;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7364ULL: goto x86_l_1cc4;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7375ULL: goto x86_l_1ccf;
	case 7379ULL: goto x86_l_1cd3;
	case 7384ULL: goto x86_l_1cd8;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7404ULL: goto x86_l_1cec;
	case 7409ULL: goto x86_l_1cf1;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7463ULL: goto x86_l_1d27;
	case 7465ULL: goto x86_l_1d29;
	case 7469ULL: goto x86_l_1d2d;
	case 7473ULL: goto x86_l_1d31;
	case 7477ULL: goto x86_l_1d35;
	case 7481ULL: goto x86_l_1d39;
	case 7486ULL: goto x86_l_1d3e;
	case 7491ULL: goto x86_l_1d43;
	case 7496ULL: goto x86_l_1d48;
	case 7501ULL: goto x86_l_1d4d;
	case 7503ULL: goto x86_l_1d4f;
	case 7507ULL: goto x86_l_1d53;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7526ULL: goto x86_l_1d66;
	case 7531ULL: goto x86_l_1d6b;
	case 7534ULL: goto x86_l_1d6e;
	case 7536ULL: goto x86_l_1d70;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7566ULL: goto x86_l_1d8e;
	case 7570ULL: goto x86_l_1d92;
	case 7574ULL: goto x86_l_1d96;
	case 7578ULL: goto x86_l_1d9a;
	case 7582ULL: goto x86_l_1d9e;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7628ULL: goto x86_l_1dcc;
	case 7633ULL: goto x86_l_1dd1;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7644ULL: goto x86_l_1ddc;
	case 7649ULL: goto x86_l_1de1;
	case 7654ULL: goto x86_l_1de6;
	case 7659ULL: goto x86_l_1deb;
	case 7664ULL: goto x86_l_1df0;
	case 7667ULL: goto x86_l_1df3;
	case 7669ULL: goto x86_l_1df5;
	case 7674ULL: goto x86_l_1dfa;
	case 7679ULL: goto x86_l_1dff;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7694ULL: goto x86_l_1e0e;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7703ULL: goto x86_l_1e17;
	case 7707ULL: goto x86_l_1e1b;
	case 7711ULL: goto x86_l_1e1f;
	case 7715ULL: goto x86_l_1e23;
	case 7720ULL: goto x86_l_1e28;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7746ULL: goto x86_l_1e42;
	case 7751ULL: goto x86_l_1e47;
	case 7756ULL: goto x86_l_1e4c;
	case 7761ULL: goto x86_l_1e51;
	case 7766ULL: goto x86_l_1e56;
	case 7768ULL: goto x86_l_1e58;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7780ULL: goto x86_l_1e64;
	case 7785ULL: goto x86_l_1e69;
	case 7790ULL: goto x86_l_1e6e;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7800ULL: goto x86_l_1e78;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7815ULL: goto x86_l_1e87;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7828ULL: goto x86_l_1e94;
	case 7830ULL: goto x86_l_1e96;
	case 7834ULL: goto x86_l_1e9a;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7851ULL: goto x86_l_1eab;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7866ULL: goto x86_l_1eba;
	case 7868ULL: goto x86_l_1ebc;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7880ULL: goto x86_l_1ec8;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7910ULL: goto x86_l_1ee6;
	case 7912ULL: goto x86_l_1ee8;
	case 7917ULL: goto x86_l_1eed;
	case 7921ULL: goto x86_l_1ef1;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7943ULL: goto x86_l_1f07;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7963ULL: goto x86_l_1f1b;
	case 7968ULL: goto x86_l_1f20;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7979ULL: goto x86_l_1f2b;
	case 7983ULL: goto x86_l_1f2f;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7994ULL: goto x86_l_1f3a;
	case 7998ULL: goto x86_l_1f3e;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8013ULL: goto x86_l_1f4d;
	case 8018ULL: goto x86_l_1f52;
	case 8020ULL: goto x86_l_1f54;
	case 8025ULL: goto x86_l_1f59;
	case 8029ULL: goto x86_l_1f5d;
	case 8037ULL: goto x86_l_1f65;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8056ULL: goto x86_l_1f78;
	case 8061ULL: goto x86_l_1f7d;
	case 8063ULL: goto x86_l_1f7f;
	case 8068ULL: goto x86_l_1f84;
	case 8072ULL: goto x86_l_1f88;
	case 8076ULL: goto x86_l_1f8c;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8135ULL: goto x86_l_1fc7;
	case 8140ULL: goto x86_l_1fcc;
	case 8142ULL: goto x86_l_1fce;
	case 8147ULL: goto x86_l_1fd3;
	case 8155ULL: goto x86_l_1fdb;
	case 8159ULL: goto x86_l_1fdf;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8184ULL: goto x86_l_1ff8;
	case 8189ULL: goto x86_l_1ffd;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8204ULL: goto x86_l_200c;
	case 8207ULL: goto x86_l_200f;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8300ULL: goto x86_l_206c;
	case 8308ULL: goto x86_l_2074;
	case 8316ULL: goto x86_l_207c;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8326ULL: goto x86_l_2086;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8347ULL: goto x86_l_209b;
	case 8349ULL: goto x86_l_209d;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8380ULL: goto x86_l_20bc;
	case 8384ULL: goto x86_l_20c0;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8411ULL: goto x86_l_20db;
	case 8415ULL: goto x86_l_20df;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8458ULL: goto x86_l_210a;
	case 8466ULL: goto x86_l_2112;
	case 8476ULL: goto x86_l_211c;
	case 8484ULL: goto x86_l_2124;
	case 8492ULL: goto x86_l_212c;
	case 8500ULL: goto x86_l_2134;
	case 8508ULL: goto x86_l_213c;
	case 8516ULL: goto x86_l_2144;
	case 8524ULL: goto x86_l_214c;
	case 8532ULL: goto x86_l_2154;
	case 8540ULL: goto x86_l_215c;
	case 8547ULL: goto x86_l_2163;
	case 8558ULL: goto x86_l_216e;
	case 8563ULL: goto x86_l_2173;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8595ULL: goto x86_l_2193;
	case 8598ULL: goto x86_l_2196;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8612ULL: goto x86_l_21a4;
	case 8617ULL: goto x86_l_21a9;
	case 8619ULL: goto x86_l_21ab;
	case 8622ULL: goto x86_l_21ae;
	case 8628ULL: goto x86_l_21b4;
	case 8632ULL: goto x86_l_21b8;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8649ULL: goto x86_l_21c9;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8667ULL: goto x86_l_21db;
	case 8671ULL: goto x86_l_21df;
	case 8678ULL: goto x86_l_21e6;
	case 8682ULL: goto x86_l_21ea;
	case 8689ULL: goto x86_l_21f1;
	case 8693ULL: goto x86_l_21f5;
	case 8700ULL: goto x86_l_21fc;
	case 8704ULL: goto x86_l_2200;
	case 8708ULL: goto x86_l_2204;
	case 8715ULL: goto x86_l_220b;
	case 8722ULL: goto x86_l_2212;
	case 8725ULL: goto x86_l_2215;
	case 8729ULL: goto x86_l_2219;
	case 8737ULL: goto x86_l_2221;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8752ULL: goto x86_l_2230;
	case 8758ULL: goto x86_l_2236;
	case 8763ULL: goto x86_l_223b;
	case 8770ULL: goto x86_l_2242;
	case 8773ULL: goto x86_l_2245;
	case 8779ULL: goto x86_l_224b;
	case 8786ULL: goto x86_l_2252;
	case 8789ULL: goto x86_l_2255;
	case 8792ULL: goto x86_l_2258;
	case 8795ULL: goto x86_l_225b;
	case 8799ULL: goto x86_l_225f;
	case 8802ULL: goto x86_l_2262;
	case 8805ULL: goto x86_l_2265;
	case 8812ULL: goto x86_l_226c;
	case 8815ULL: goto x86_l_226f;
	case 8822ULL: goto x86_l_2276;
	case 8825ULL: goto x86_l_2279;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8842ULL: goto x86_l_228a;
	case 8845ULL: goto x86_l_228d;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8865ULL: goto x86_l_22a1;
	case 8868ULL: goto x86_l_22a4;
	case 8870ULL: goto x86_l_22a6;
	case 8874ULL: goto x86_l_22aa;
	case 8877ULL: goto x86_l_22ad;
	case 8880ULL: goto x86_l_22b0;
	case 8883ULL: goto x86_l_22b3;
	case 8890ULL: goto x86_l_22ba;
	case 8893ULL: goto x86_l_22bd;
	case 8896ULL: goto x86_l_22c0;
	case 8903ULL: goto x86_l_22c7;
	case 8906ULL: goto x86_l_22ca;
	case 8908ULL: goto x86_l_22cc;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8920ULL: goto x86_l_22d8;
	case 8923ULL: goto x86_l_22db;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8936ULL: goto x86_l_22e8;
	case 8941ULL: goto x86_l_22ed;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1c29:
	/* 0x1c29: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1c2d:
	/* 0x1c2d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c32:
	/* 0x1c32: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c37:
	/* 0x1c37: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c41:
	/* 0x1c41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c43:
	/* 0x1c43: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c48:
	/* 0x1c48: lea    rdx,[r14+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1c4c:
	/* 0x1c4c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c51:
	/* 0x1c51: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c56:
	/* 0x1c56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c60:
	/* 0x1c60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c62:
	/* 0x1c62: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c66:
	/* 0x1c66: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1c6a:
	/* 0x1c6a: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6e:
	/* 0x1c6e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c73:
	/* 0x1c73: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1c78:
	/* 0x1c78: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c82:
	/* 0x1c82: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c85:
	/* 0x1c85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c87:
	/* 0x1c87: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c8c:
	/* 0x1c8c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c91:
	/* 0x1c91: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c96:
	/* 0x1c96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c9b:
	/* 0x1c9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1ca3:
	/* 0x1ca3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca5:
	/* 0x1ca5: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ca9:
	/* 0x1ca9: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1cad:
	/* 0x1cad: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1cb1:
	/* 0x1cb1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1cb5:
	/* 0x1cb5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cba:
	/* 0x1cba: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cc4:
	/* 0x1cc4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cc9:
	/* 0x1cc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccb:
	/* 0x1ccb: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    DWORD PTR [r13+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1cd3:
	/* 0x1cd3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cdd:
	/* 0x1cdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1cea:
	/* 0x1cea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cec:
	/* 0x1cec: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cf1:
	/* 0x1cf1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1cf5:
	/* 0x1cf5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cfa:
	/* 0x1cfa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cff:
	/* 0x1cff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d04:
	/* 0x1d04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d09:
	/* 0x1d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0b:
	/* 0x1d0b: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d10:
	/* 0x1d10: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d15:
	/* 0x1d15: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d24:
	/* 0x1d24: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d27:
	/* 0x1d27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d29:
	/* 0x1d29: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d2d:
	/* 0x1d2d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1d31:
	/* 0x1d31: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d35:
	/* 0x1d35: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d39:
	/* 0x1d39: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d3e:
	/* 0x1d3e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d43:
	/* 0x1d43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d48:
	/* 0x1d48: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d4d:
	/* 0x1d4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4f:
	/* 0x1d4f: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d53:
	/* 0x1d53: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d57:
	/* 0x1d57: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d61:
	/* 0x1d61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d66:
	/* 0x1d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d6b:
	/* 0x1d6b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d6e:
	/* 0x1d6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d70:
	/* 0x1d70: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d75:
	/* 0x1d75: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d7f:
	/* 0x1d7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d84:
	/* 0x1d84: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d89:
	/* 0x1d89: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d8c:
	/* 0x1d8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8e:
	/* 0x1d8e: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d92:
	/* 0x1d92: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1d96:
	/* 0x1d96: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1d9a:
	/* 0x1d9a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d9e:
	/* 0x1d9e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1da3:
	/* 0x1da3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1da8:
	/* 0x1da8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dad:
	/* 0x1dad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1db2:
	/* 0x1db2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db4:
	/* 0x1db4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1db9:
	/* 0x1db9: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1dbd:
	/* 0x1dbd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dd1:
	/* 0x1dd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd3:
	/* 0x1dd3: mov    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dd8:
	/* 0x1dd8: lea    r15,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ddc:
	/* 0x1ddc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1de1:
	/* 0x1de1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1de6:
	/* 0x1de6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1deb:
	/* 0x1deb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1df0:
	/* 0x1df0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1df3:
	/* 0x1df3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df5:
	/* 0x1df5: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dfa:
	/* 0x1dfa: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dff:
	/* 0x1dff: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e04:
	/* 0x1e04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e09:
	/* 0x1e09: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e11:
	/* 0x1e11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e13:
	/* 0x1e13: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e17:
	/* 0x1e17: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e1b:
	/* 0x1e1b: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e1f:
	/* 0x1e1f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e23:
	/* 0x1e23: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e28:
	/* 0x1e28: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e2d:
	/* 0x1e2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e32:
	/* 0x1e32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e37:
	/* 0x1e37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e39:
	/* 0x1e39: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e3e:
	/* 0x1e3e: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1e42:
	/* 0x1e42: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e47:
	/* 0x1e47: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e51:
	/* 0x1e51: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e56:
	/* 0x1e56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e58:
	/* 0x1e58: cmp    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_1e5d:
	/* 0x1e5d: jne    1ec4 <trace_security_mmap_file+0x1ec4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ec4;
	}
x86_l_1e5f:
	/* 0x1e5f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e64:
	/* 0x1e64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e69:
	/* 0x1e69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e73:
	/* 0x1e73: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e76:
	/* 0x1e76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e78:
	/* 0x1e78: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e7d:
	/* 0x1e7d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e82:
	/* 0x1e82: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e87:
	/* 0x1e87: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e91:
	/* 0x1e91: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1e94:
	/* 0x1e94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e96:
	/* 0x1e96: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e9a:
	/* 0x1e9a: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1e9e:
	/* 0x1e9e: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1ea2:
	/* 0x1ea2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ea6:
	/* 0x1ea6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eab:
	/* 0x1eab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1eb5:
	/* 0x1eb5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1eba:
	/* 0x1eba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ebc:
	/* 0x1ebc: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    DWORD PTR [r13+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ec4:
	/* 0x1ec4: mov    DWORD PTR [r13+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ec8:
	/* 0x1ec8: lea    r12,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ecf:
	/* 0x1ecf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ede:
	/* 0x1ede: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1ee6:
	/* 0x1ee6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee8:
	/* 0x1ee8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eed:
	/* 0x1eed: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ef1:
	/* 0x1ef1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ef6:
	/* 0x1ef6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1efb:
	/* 0x1efb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f00:
	/* 0x1f00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f05:
	/* 0x1f05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f07:
	/* 0x1f07: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f0c:
	/* 0x1f0c: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f11:
	/* 0x1f11: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1f16:
	/* 0x1f16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f1b:
	/* 0x1f1b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f20:
	/* 0x1f20: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f25:
	/* 0x1f25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f27:
	/* 0x1f27: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1f2f:
	/* 0x1f2f: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1f34:
	/* 0x1f34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f36:
	/* 0x1f36: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f3a:
	/* 0x1f3a: lea    rdx,[rbp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f3e:
	/* 0x1f3e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f43:
	/* 0x1f43: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f48:
	/* 0x1f48: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f4d:
	/* 0x1f4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f52:
	/* 0x1f52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f54:
	/* 0x1f54: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f59:
	/* 0x1f59: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f5d:
	/* 0x1f5d: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1f65:
	/* 0x1f65: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1f69:
	/* 0x1f69: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f73:
	/* 0x1f73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f78:
	/* 0x1f78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f7d:
	/* 0x1f7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f7f:
	/* 0x1f7f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f84:
	/* 0x1f84: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f88:
	/* 0x1f88: add    r14,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1f8c:
	/* 0x1f8c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f91:
	/* 0x1f91: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f96:
	/* 0x1f96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f9b:
	/* 0x1f9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fa0:
	/* 0x1fa0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1fa3:
	/* 0x1fa3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa5:
	/* 0x1fa5: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1faa:
	/* 0x1faa: mov    QWORD PTR [r13+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1fae:
	/* 0x1fae: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fb3:
	/* 0x1fb3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fb8:
	/* 0x1fb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fbd:
	/* 0x1fbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1fc5:
	/* 0x1fc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc7:
	/* 0x1fc7: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_1fcc:
	/* 0x1fcc: je     1fd3 <trace_security_mmap_file+0x1fd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd3;
	}
x86_l_1fce:
	/* 0x1fce: or     BYTE PTR [r13+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1fd3:
	/* 0x1fd3: mov    QWORD PTR [r13+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1fdb:
	/* 0x1fdb: lea    rdi,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1fec:
	/* 0x1fec: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ff6:
	/* 0x1ff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff8:
	/* 0x1ff8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ffd:
	/* 0x1ffd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2002:
	/* 0x2002: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2007:
	/* 0x2007: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_200c:
	/* 0x200c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_200f:
	/* 0x200f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2011:
	/* 0x2011: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2016:
	/* 0x2016: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_201b:
	/* 0x201b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2020:
	/* 0x2020: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2025:
	/* 0x2025: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_202a:
	/* 0x202a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202c:
	/* 0x202c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2031:
	/* 0x2031: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2036:
	/* 0x2036: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_203b:
	/* 0x203b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2040:
	/* 0x2040: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2043:
	/* 0x2043: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2048:
	/* 0x2048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204a:
	/* 0x204a: lea    rdi,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_204e:
	/* 0x204e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2053:
	/* 0x2053: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2058:
	/* 0x2058: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_205d:
	/* 0x205d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2060:
	/* 0x2060: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2062:
	/* 0x2062: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_2067:
	/* 0x2067: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_206c:
	/* 0x206c: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2074:
	/* 0x2074: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_207c:
	/* 0x207c: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_207f:
	/* 0x207f: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_2084:
	/* 0x2084: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2086:
	/* 0x2086: mov    r14,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_208e:
	/* 0x208e: test   BYTE PTR [r14+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_2093:
	/* 0x2093: mov    r15,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_209b:
	/* 0x209b: je     20c0 <trace_security_mmap_file+0x20c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c0;
	}
x86_l_209d:
	/* 0x209d: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_20a4:
	/* 0x20a4: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_20a9:
	/* 0x20a9: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_20ae:
	/* 0x20ae: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_20b3:
	/* 0x20b3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_20b6:
	/* 0x20b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b8:
	/* 0x20b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ba:
	/* 0x20ba: js     20c0 <trace_security_mmap_file+0x20c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_20c0;
	}
x86_l_20bc:
	/* 0x20bc: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_20c0:
	/* 0x20c0: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20c8:
	/* 0x20c8: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_20cd:
	/* 0x20cd: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_20d2:
	/* 0x20d2: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_20d5:
	/* 0x20d5: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_20db:
	/* 0x20db: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20df:
	/* 0x20df: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_20e6:
	/* 0x20e6: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_20eb:
	/* 0x20eb: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_20f0:
	/* 0x20f0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_20f5:
	/* 0x20f5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_20f8:
	/* 0x20f8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_20fb:
	/* 0x20fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20fd:
	/* 0x20fd: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2102:
	/* 0x2102: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_210a:
	/* 0x210a: mov    DWORD PTR [r13+0x70],0x2eb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337899ULL);
x86_l_2112:
	/* 0x2112: mov    WORD PTR [r13+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_211c:
	/* 0x211c: mov    BYTE PTR [r13+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2124:
	/* 0x2124: mov    QWORD PTR [rcx+0x38],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244813135871ULL);
x86_l_212c:
	/* 0x212c: mov    QWORD PTR [rcx+0x30],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 210453397503ULL);
x86_l_2134:
	/* 0x2134: mov    QWORD PTR [rcx+0x28],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176093659135ULL);
x86_l_213c:
	/* 0x213c: mov    QWORD PTR [rcx+0x20],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 141733920767ULL);
x86_l_2144:
	/* 0x2144: mov    QWORD PTR [rcx+0x18],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 107374182399ULL);
x86_l_214c:
	/* 0x214c: mov    QWORD PTR [rcx+0x10],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_2154:
	/* 0x2154: mov    QWORD PTR [rcx+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38654705663ULL);
x86_l_215c:
	/* 0x215c: mov    QWORD PTR [rcx],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4294967295ULL);
x86_l_2163:
	/* 0x2163: mov    QWORD PTR [r13+0x7dd8],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138370961375231ULL);
x86_l_216e:
	/* 0x216e: movzx  eax,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_2173:
	/* 0x2173: mov    DWORD PTR [rsp+0x20],0x2eb */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438954219ULL);
x86_l_217b:
	/* 0x217b: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2180:
	/* 0x2180: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_2187:
	/* 0x2187: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_218c:
	/* 0x218c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2191:
	/* 0x2191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2193:
	/* 0x2193: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2196:
	/* 0x2196: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_219c:
	/* 0x219c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_219f:
	/* 0x219f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21a4:
	/* 0x21a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21a9:
	/* 0x21a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ab:
	/* 0x21ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21ae:
	/* 0x21ae: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_21b4:
	/* 0x21b4: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b8:
	/* 0x21b8: mov    QWORD PTR [r13+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_21bf:
	/* 0x21bf: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21c2:
	/* 0x21c2: mov    QWORD PTR [r13+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_21c9:
	/* 0x21c9: mov    QWORD PTR [r13+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_21d0:
	/* 0x21d0: mov    rdx,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21d4:
	/* 0x21d4: mov    QWORD PTR [r13+0x7e10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_21db:
	/* 0x21db: mov    rdx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_21df:
	/* 0x21df: mov    QWORD PTR [r13+0x7e08],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_21e6:
	/* 0x21e6: mov    rdx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21ea:
	/* 0x21ea: mov    QWORD PTR [r13+0x7e00],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_21f1:
	/* 0x21f1: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21f5:
	/* 0x21f5: mov    QWORD PTR [r13+0x7df8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_21fc:
	/* 0x21fc: mov    rdx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2200:
	/* 0x2200: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2204:
	/* 0x2204: mov    QWORD PTR [r13+0x7df0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_220b:
	/* 0x220b: mov    QWORD PTR [r13+0x7de8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_2212:
	/* 0x2212: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2215:
	/* 0x2215: cmp    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_2219:
	/* 0x2219: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2221:
	/* 0x2221: jne    223b <trace_security_mmap_file+0x223b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_223b;
	}
x86_l_2223:
	/* 0x2223: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2226:
	/* 0x2226: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2229:
	/* 0x2229: mov    QWORD PTR [r13+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2230:
	/* 0x2230: jne    2a18 <trace_security_mmap_file+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10776ULL;
	}
x86_l_2236:
	/* 0x2236: jmp    3de5 <trace_security_mmap_file+0x3de5> */
	return 15845ULL;
x86_l_223b:
	/* 0x223b: mov    rax,QWORD PTR [r13+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_2242:
	/* 0x2242: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2245:
	/* 0x2245: je     23e3 <trace_security_mmap_file+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9187ULL;
	}
x86_l_224b:
	/* 0x224b: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_2252:
	/* 0x2252: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_2255:
	/* 0x2255: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2258:
	/* 0x2258: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_225b:
	/* 0x225b: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_225f:
	/* 0x225f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2262:
	/* 0x2262: neg    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_2265:
	/* 0x2265: xor    r12,QWORD PTR [r13+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_226c:
	/* 0x226c: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_226f:
	/* 0x226f: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_2276:
	/* 0x2276: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2279:
	/* 0x2279: je     229a <trace_security_mmap_file+0x229a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_229a;
	}
x86_l_227b:
	/* 0x227b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_227d:
	/* 0x227d: cmp    BYTE PTR [rbp+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_2284:
	/* 0x2284: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2287:
	/* 0x2287: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_228a:
	/* 0x228a: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_228d:
	/* 0x228d: xor    rcx,QWORD PTR [r13+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_2294:
	/* 0x2294: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2297:
	/* 0x2297: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_229a:
	/* 0x229a: mov    rax,QWORD PTR [r13+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_22a1:
	/* 0x22a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22a4:
	/* 0x22a4: je     22c0 <trace_security_mmap_file+0x22c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c0;
	}
x86_l_22a6:
	/* 0x22a6: mov    ecx,DWORD PTR [r13+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_22aa:
	/* 0x22aa: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22ad:
	/* 0x22ad: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_22b0:
	/* 0x22b0: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_22b3:
	/* 0x22b3: xor    rcx,QWORD PTR [r13+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_22ba:
	/* 0x22ba: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22bd:
	/* 0x22bd: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_22c0:
	/* 0x22c0: mov    rax,QWORD PTR [r13+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_22c7:
	/* 0x22c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22ca:
	/* 0x22ca: je     22e8 <trace_security_mmap_file+0x22e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e8;
	}
x86_l_22cc:
	/* 0x22cc: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_22cf:
	/* 0x22cf: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_22d4:
	/* 0x22d4: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22d8:
	/* 0x22d8: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_22db:
	/* 0x22db: xor    rcx,QWORD PTR [r13+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_22e2:
	/* 0x22e2: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22e5:
	/* 0x22e5: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_22e8:
	/* 0x22e8: movzx  ebp,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_22ed:
	/* 0x22ed: mov    r15,QWORD PTR [r13+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
	return 8948ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8959ULL: goto x86_l_22ff;
	case 8965ULL: goto x86_l_2305;
	case 8972ULL: goto x86_l_230c;
	case 8980ULL: goto x86_l_2314;
	case 8983ULL: goto x86_l_2317;
	case 8990ULL: goto x86_l_231e;
	case 8997ULL: goto x86_l_2325;
	case 9005ULL: goto x86_l_232d;
	case 9010ULL: goto x86_l_2332;
	case 9017ULL: goto x86_l_2339;
	case 9022ULL: goto x86_l_233e;
	case 9027ULL: goto x86_l_2343;
	case 9029ULL: goto x86_l_2345;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	case 9041ULL: goto x86_l_2351;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9066ULL: goto x86_l_236a;
	case 9068ULL: goto x86_l_236c;
	case 9071ULL: goto x86_l_236f;
	case 9073ULL: goto x86_l_2371;
	case 9076ULL: goto x86_l_2374;
	case 9080ULL: goto x86_l_2378;
	case 9083ULL: goto x86_l_237b;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9095ULL: goto x86_l_2387;
	case 9100ULL: goto x86_l_238c;
	case 9103ULL: goto x86_l_238f;
	case 9106ULL: goto x86_l_2392;
	case 9108ULL: goto x86_l_2394;
	case 9112ULL: goto x86_l_2398;
	case 9114ULL: goto x86_l_239a;
	case 9117ULL: goto x86_l_239d;
	case 9119ULL: goto x86_l_239f;
	case 9127ULL: goto x86_l_23a7;
	case 9130ULL: goto x86_l_23aa;
	case 9135ULL: goto x86_l_23af;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9150ULL: goto x86_l_23be;
	case 9153ULL: goto x86_l_23c1;
	case 9155ULL: goto x86_l_23c3;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9168ULL: goto x86_l_23d0;
	case 9170ULL: goto x86_l_23d2;
	case 9173ULL: goto x86_l_23d5;
	case 9175ULL: goto x86_l_23d7;
	case 9178ULL: goto x86_l_23da;
	case 9182ULL: goto x86_l_23de;
	case 9185ULL: goto x86_l_23e1;
	case 9187ULL: goto x86_l_23e3;
	case 9194ULL: goto x86_l_23ea;
	case 9201ULL: goto x86_l_23f1;
	case 9204ULL: goto x86_l_23f4;
	case 9210ULL: goto x86_l_23fa;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9225ULL: goto x86_l_2409;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9241ULL: goto x86_l_2419;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9254ULL: goto x86_l_2426;
	case 9257ULL: goto x86_l_2429;
	case 9259ULL: goto x86_l_242b;
	case 9261ULL: goto x86_l_242d;
	case 9269ULL: goto x86_l_2435;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9280ULL: goto x86_l_2440;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9293ULL: goto x86_l_244d;
	case 9296ULL: goto x86_l_2450;
	case 9304ULL: goto x86_l_2458;
	case 9312ULL: goto x86_l_2460;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9329ULL: goto x86_l_2471;
	case 9336ULL: goto x86_l_2478;
	case 9343ULL: goto x86_l_247f;
	case 9351ULL: goto x86_l_2487;
	case 9353ULL: goto x86_l_2489;
	case 9360ULL: goto x86_l_2490;
	case 9363ULL: goto x86_l_2493;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9382ULL: goto x86_l_24a6;
	case 9387ULL: goto x86_l_24ab;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9401ULL: goto x86_l_24b9;
	case 9406ULL: goto x86_l_24be;
	case 9413ULL: goto x86_l_24c5;
	case 9416ULL: goto x86_l_24c8;
	case 9418ULL: goto x86_l_24ca;
	case 9423ULL: goto x86_l_24cf;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9433ULL: goto x86_l_24d9;
	case 9435ULL: goto x86_l_24db;
	case 9438ULL: goto x86_l_24de;
	case 9442ULL: goto x86_l_24e2;
	case 9445ULL: goto x86_l_24e5;
	case 9447ULL: goto x86_l_24e7;
	case 9449ULL: goto x86_l_24e9;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9460ULL: goto x86_l_24f4;
	case 9463ULL: goto x86_l_24f7;
	case 9465ULL: goto x86_l_24f9;
	case 9473ULL: goto x86_l_2501;
	case 9475ULL: goto x86_l_2503;
	case 9479ULL: goto x86_l_2507;
	case 9487ULL: goto x86_l_250f;
	case 9489ULL: goto x86_l_2511;
	case 9492ULL: goto x86_l_2514;
	case 9494ULL: goto x86_l_2516;
	case 9502ULL: goto x86_l_251e;
	case 9505ULL: goto x86_l_2521;
	case 9508ULL: goto x86_l_2524;
	case 9511ULL: goto x86_l_2527;
	case 9516ULL: goto x86_l_252c;
	case 9524ULL: goto x86_l_2534;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9542ULL: goto x86_l_2546;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9564ULL: goto x86_l_255c;
	case 9569ULL: goto x86_l_2561;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9588ULL: goto x86_l_2574;
	case 9593ULL: goto x86_l_2579;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9605ULL: goto x86_l_2585;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9631ULL: goto x86_l_259f;
	case 9635ULL: goto x86_l_25a3;
	case 9642ULL: goto x86_l_25aa;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9674ULL: goto x86_l_25ca;
	case 9676ULL: goto x86_l_25cc;
	case 9683ULL: goto x86_l_25d3;
	case 9686ULL: goto x86_l_25d6;
	case 9688ULL: goto x86_l_25d8;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9702ULL: goto x86_l_25e6;
	case 9705ULL: goto x86_l_25e9;
	case 9707ULL: goto x86_l_25eb;
	case 9710ULL: goto x86_l_25ee;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9721ULL: goto x86_l_25f9;
	case 9724ULL: goto x86_l_25fc;
	case 9727ULL: goto x86_l_25ff;
	case 9730ULL: goto x86_l_2602;
	case 9733ULL: goto x86_l_2605;
	case 9741ULL: goto x86_l_260d;
	case 9747ULL: goto x86_l_2613;
	case 9754ULL: goto x86_l_261a;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9780ULL: goto x86_l_2634;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9800ULL: goto x86_l_2648;
	case 9805ULL: goto x86_l_264d;
	case 9808ULL: goto x86_l_2650;
	case 9810ULL: goto x86_l_2652;
	case 9814ULL: goto x86_l_2656;
	case 9818ULL: goto x86_l_265a;
	case 9822ULL: goto x86_l_265e;
	case 9826ULL: goto x86_l_2662;
	case 9831ULL: goto x86_l_2667;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9846ULL: goto x86_l_2676;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9857ULL: goto x86_l_2681;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	case 9877ULL: goto x86_l_2695;
	case 9879ULL: goto x86_l_2697;
	case 9883ULL: goto x86_l_269b;
	case 9887ULL: goto x86_l_269f;
	case 9894ULL: goto x86_l_26a6;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9913ULL: goto x86_l_26b9;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9926ULL: goto x86_l_26c6;
	case 9928ULL: goto x86_l_26c8;
	case 9935ULL: goto x86_l_26cf;
	case 9938ULL: goto x86_l_26d2;
	case 9940ULL: goto x86_l_26d4;
	case 9943ULL: goto x86_l_26d7;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9957ULL: goto x86_l_26e5;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9966ULL: goto x86_l_26ee;
	case 9969ULL: goto x86_l_26f1;
	case 9971ULL: goto x86_l_26f3;
	case 9973ULL: goto x86_l_26f5;
	case 9976ULL: goto x86_l_26f8;
	case 9979ULL: goto x86_l_26fb;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10004ULL: goto x86_l_2714;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10021ULL: goto x86_l_2725;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10053ULL: goto x86_l_2745;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10065ULL: goto x86_l_2751;
	case 10070ULL: goto x86_l_2756;
	case 10075ULL: goto x86_l_275b;
	case 10080ULL: goto x86_l_2760;
	case 10083ULL: goto x86_l_2763;
	case 10088ULL: goto x86_l_2768;
	case 10090ULL: goto x86_l_276a;
	case 10094ULL: goto x86_l_276e;
	case 10099ULL: goto x86_l_2773;
	case 10104ULL: goto x86_l_2778;
	case 10107ULL: goto x86_l_277b;
	case 10112ULL: goto x86_l_2780;
	case 10115ULL: goto x86_l_2783;
	case 10117ULL: goto x86_l_2785;
	case 10124ULL: goto x86_l_278c;
	case 10131ULL: goto x86_l_2793;
	case 10136ULL: goto x86_l_2798;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10153ULL: goto x86_l_27a9;
	case 10156ULL: goto x86_l_27ac;
	case 10158ULL: goto x86_l_27ae;
	case 10165ULL: goto x86_l_27b5;
	case 10168ULL: goto x86_l_27b8;
	case 10170ULL: goto x86_l_27ba;
	case 10173ULL: goto x86_l_27bd;
	case 10178ULL: goto x86_l_27c2;
	case 10181ULL: goto x86_l_27c5;
	case 10183ULL: goto x86_l_27c7;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10195ULL: goto x86_l_27d3;
	case 10198ULL: goto x86_l_27d6;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10205ULL: goto x86_l_27dd;
	case 10208ULL: goto x86_l_27e0;
	case 10211ULL: goto x86_l_27e3;
	case 10214ULL: goto x86_l_27e6;
	case 10219ULL: goto x86_l_27eb;
	case 10227ULL: goto x86_l_27f3;
	case 10233ULL: goto x86_l_27f9;
	case 10237ULL: goto x86_l_27fd;
	case 10242ULL: goto x86_l_2802;
	case 10247ULL: goto x86_l_2807;
	case 10250ULL: goto x86_l_280a;
	case 10255ULL: goto x86_l_280f;
	case 10257ULL: goto x86_l_2811;
	case 10264ULL: goto x86_l_2818;
	case 10271ULL: goto x86_l_281f;
	case 10276ULL: goto x86_l_2824;
	case 10283ULL: goto x86_l_282b;
	case 10288ULL: goto x86_l_2830;
	case 10293ULL: goto x86_l_2835;
	case 10296ULL: goto x86_l_2838;
	case 10298ULL: goto x86_l_283a;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10310ULL: goto x86_l_2846;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10323ULL: goto x86_l_2853;
	case 10326ULL: goto x86_l_2856;
	case 10328ULL: goto x86_l_2858;
	case 10331ULL: goto x86_l_285b;
	case 10335ULL: goto x86_l_285f;
	case 10338ULL: goto x86_l_2862;
	case 10340ULL: goto x86_l_2864;
	case 10342ULL: goto x86_l_2866;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10351ULL: goto x86_l_286f;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10366ULL: goto x86_l_287e;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10375ULL: goto x86_l_2887;
	case 10379ULL: goto x86_l_288b;
	case 10386ULL: goto x86_l_2892;
	case 10391ULL: goto x86_l_2897;
	case 10398ULL: goto x86_l_289e;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10411ULL: goto x86_l_28ab;
	case 10413ULL: goto x86_l_28ad;
	case 10420ULL: goto x86_l_28b4;
	case 10423ULL: goto x86_l_28b7;
	case 10425ULL: goto x86_l_28b9;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10438ULL: goto x86_l_28c6;
	case 10440ULL: goto x86_l_28c8;
	case 10443ULL: goto x86_l_28cb;
	case 10445ULL: goto x86_l_28cd;
	case 10448ULL: goto x86_l_28d0;
	case 10452ULL: goto x86_l_28d4;
	case 10455ULL: goto x86_l_28d7;
	case 10457ULL: goto x86_l_28d9;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10465ULL: goto x86_l_28e1;
	case 10468ULL: goto x86_l_28e4;
	case 10471ULL: goto x86_l_28e7;
	case 10478ULL: goto x86_l_28ee;
	case 10481ULL: goto x86_l_28f1;
	case 10483ULL: goto x86_l_28f3;
	case 10490ULL: goto x86_l_28fa;
	case 10495ULL: goto x86_l_28ff;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10515ULL: goto x86_l_2913;
	case 10517ULL: goto x86_l_2915;
	case 10524ULL: goto x86_l_291c;
	case 10527ULL: goto x86_l_291f;
	case 10529ULL: goto x86_l_2921;
	case 10532ULL: goto x86_l_2924;
	default: return 0xffffffffffffffffULL;
	}
x86_l_22f4:
	/* 0x22f4: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_22f7:
	/* 0x22f7: mov    WORD PTR [rsp+0xb0],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_22ff:
	/* 0x22ff: je     2458 <trace_security_mmap_file+0x2458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2458;
	}
x86_l_2305:
	/* 0x2305: mov    rax,QWORD PTR [r13+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_230c:
	/* 0x230c: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2314:
	/* 0x2314: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2317:
	/* 0x2317: mov    r13,QWORD PTR [r13+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_231e:
	/* 0x231e: mov    rax,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_2325:
	/* 0x2325: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_232d:
	/* 0x232d: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2332:
	/* 0x2332: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_2339:
	/* 0x2339: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_233e:
	/* 0x233e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2343:
	/* 0x2343: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2345:
	/* 0x2345: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2348:
	/* 0x2348: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_234c:
	/* 0x234c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2351:
	/* 0x2351: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2358:
	/* 0x2358: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_235b:
	/* 0x235b: je     237d <trace_security_mmap_file+0x237d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237d;
	}
x86_l_235d:
	/* 0x235d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2362:
	/* 0x2362: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2367:
	/* 0x2367: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_236a:
	/* 0x236a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236c:
	/* 0x236c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_236f:
	/* 0x236f: je     237d <trace_security_mmap_file+0x237d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237d;
	}
x86_l_2371:
	/* 0x2371: mov    rbp,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2374:
	/* 0x2374: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2378:
	/* 0x2378: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_237b:
	/* 0x237b: jmp    237f <trace_security_mmap_file+0x237f> */
	goto x86_l_237f;
x86_l_237d:
	/* 0x237d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_237f:
	/* 0x237f: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2387:
	/* 0x2387: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_238c:
	/* 0x238c: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_238f:
	/* 0x238f: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2392:
	/* 0x2392: jb     23aa <trace_security_mmap_file+0x23aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23aa;
	}
x86_l_2394:
	/* 0x2394: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2398:
	/* 0x2398: je     239f <trace_security_mmap_file+0x239f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239f;
	}
x86_l_239a:
	/* 0x239a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_239d:
	/* 0x239d: jbe    23aa <trace_security_mmap_file+0x23aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23aa;
	}
x86_l_239f:
	/* 0x239f: and    r14,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 224ULL);
x86_l_23a7:
	/* 0x23a7: or     rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_23aa:
	/* 0x23aa: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23af:
	/* 0x23af: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23b2:
	/* 0x23b2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23b7:
	/* 0x23b7: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23be:
	/* 0x23be: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_23c1:
	/* 0x23c1: je     23ff <trace_security_mmap_file+0x23ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ff;
	}
x86_l_23c3:
	/* 0x23c3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23c8:
	/* 0x23c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23cd:
	/* 0x23cd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23d0:
	/* 0x23d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d2:
	/* 0x23d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d5:
	/* 0x23d5: je     242b <trace_security_mmap_file+0x242b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_242b;
	}
x86_l_23d7:
	/* 0x23d7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23da:
	/* 0x23da: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23de:
	/* 0x23de: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_23e1:
	/* 0x23e1: jmp    242d <trace_security_mmap_file+0x242d> */
	goto x86_l_242d;
x86_l_23e3:
	/* 0x23e3: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_23ea:
	/* 0x23ea: mov    rax,QWORD PTR [r13+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_23f1:
	/* 0x23f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23f4:
	/* 0x23f4: jne    227b <trace_security_mmap_file+0x227b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8827ULL;
	}
x86_l_23fa:
	/* 0x23fa: jmp    229a <trace_security_mmap_file+0x229a> */
	return 8858ULL;
x86_l_23ff:
	/* 0x23ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2401:
	/* 0x2401: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2404:
	/* 0x2404: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2409:
	/* 0x2409: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_240c:
	/* 0x240c: jb     2442 <trace_security_mmap_file+0x2442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2442;
	}
x86_l_240e:
	/* 0x240e: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2412:
	/* 0x2412: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2417:
	/* 0x2417: je     241e <trace_security_mmap_file+0x241e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_241e;
	}
x86_l_2419:
	/* 0x2419: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_241c:
	/* 0x241c: jbe    2447 <trace_security_mmap_file+0x2447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2447;
	}
x86_l_241e:
	/* 0x241e: and    r14,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 224ULL);
x86_l_2426:
	/* 0x2426: or     rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_2429:
	/* 0x2429: jmp    2447 <trace_security_mmap_file+0x2447> */
	goto x86_l_2447;
x86_l_242b:
	/* 0x242b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_242d:
	/* 0x242d: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2435:
	/* 0x2435: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2438:
	/* 0x2438: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_243d:
	/* 0x243d: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2440:
	/* 0x2440: jae    240e <trace_security_mmap_file+0x240e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_240e;
	}
x86_l_2442:
	/* 0x2442: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2447:
	/* 0x2447: or     rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_244a:
	/* 0x244a: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_244d:
	/* 0x244d: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_2450:
	/* 0x2450: movzx  ebp,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_2458:
	/* 0x2458: cmp    QWORD PTR [r13+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_2460:
	/* 0x2460: je     252c <trace_security_mmap_file+0x252c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_252c;
	}
x86_l_2466:
	/* 0x2466: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_246b:
	/* 0x246b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246d:
	/* 0x246d: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2471:
	/* 0x2471: mov    rbx,QWORD PTR [r13+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2478:
	/* 0x2478: mov    rax,QWORD PTR [r13+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_247f:
	/* 0x247f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2487:
	/* 0x2487: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2489:
	/* 0x2489: mov    rbp,QWORD PTR [r13+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_2490:
	/* 0x2490: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_2493:
	/* 0x2493: mov    r13,QWORD PTR [r13+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_249a:
	/* 0x249a: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_249f:
	/* 0x249f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_24a6:
	/* 0x24a6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24ab:
	/* 0x24ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24b0:
	/* 0x24b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b2:
	/* 0x24b2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_24b5:
	/* 0x24b5: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24b9:
	/* 0x24b9: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24be:
	/* 0x24be: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_24c5:
	/* 0x24c5: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_24c8:
	/* 0x24c8: je     24e7 <trace_security_mmap_file+0x24e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e7;
	}
x86_l_24ca:
	/* 0x24ca: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24cf:
	/* 0x24cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24d4:
	/* 0x24d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d6:
	/* 0x24d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24d9:
	/* 0x24d9: je     24e7 <trace_security_mmap_file+0x24e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e7;
	}
x86_l_24db:
	/* 0x24db: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24de:
	/* 0x24de: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24e2:
	/* 0x24e2: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24e5:
	/* 0x24e5: jmp    24e9 <trace_security_mmap_file+0x24e9> */
	goto x86_l_24e9;
x86_l_24e7:
	/* 0x24e7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24e9:
	/* 0x24e9: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_24ec:
	/* 0x24ec: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24f1:
	/* 0x24f1: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_24f4:
	/* 0x24f4: cmp    rbp,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_24f7:
	/* 0x24f7: jae    2503 <trace_security_mmap_file+0x2503> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2503;
	}
x86_l_24f9:
	/* 0x24f9: movzx  ebp,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_2501:
	/* 0x2501: jmp    2521 <trace_security_mmap_file+0x2521> */
	goto x86_l_2521;
x86_l_2503:
	/* 0x2503: cmp    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2507:
	/* 0x2507: movzx  ebp,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_250f:
	/* 0x250f: je     2516 <trace_security_mmap_file+0x2516> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2516;
	}
x86_l_2511:
	/* 0x2511: cmp    rax,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2514:
	/* 0x2514: jbe    2521 <trace_security_mmap_file+0x2521> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2521;
	}
x86_l_2516:
	/* 0x2516: and    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 144ULL);
x86_l_251e:
	/* 0x251e: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_2521:
	/* 0x2521: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2524:
	/* 0x2524: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2527:
	/* 0x2527: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_252c:
	/* 0x252c: cmp    QWORD PTR [r13+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_2534:
	/* 0x2534: je     2605 <trace_security_mmap_file+0x2605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2605;
	}
x86_l_253a:
	/* 0x253a: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_253f:
	/* 0x253f: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_2546:
	/* 0x2546: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_254b:
	/* 0x254b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2550:
	/* 0x2550: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2555:
	/* 0x2555: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_255a:
	/* 0x255a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255c:
	/* 0x255c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2561:
	/* 0x2561: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2565:
	/* 0x2565: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_256a:
	/* 0x256a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_256f:
	/* 0x256f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2574:
	/* 0x2574: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2579:
	/* 0x2579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257b:
	/* 0x257b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2580:
	/* 0x2580: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2585:
	/* 0x2585: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_258a:
	/* 0x258a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_258f:
	/* 0x258f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2594:
	/* 0x2594: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2599:
	/* 0x2599: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259b:
	/* 0x259b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_259f:
	/* 0x259f: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_25a3:
	/* 0x25a3: mov    rbx,QWORD PTR [r13+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_25aa:
	/* 0x25aa: mov    r15,QWORD PTR [r13+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_25b1:
	/* 0x25b1: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25b6:
	/* 0x25b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_25bd:
	/* 0x25bd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25c2:
	/* 0x25c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25c7:
	/* 0x25c7: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_25ca:
	/* 0x25ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cc:
	/* 0x25cc: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_25d3:
	/* 0x25d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25d6:
	/* 0x25d6: je     25f7 <trace_security_mmap_file+0x25f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f7;
	}
x86_l_25d8:
	/* 0x25d8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_25db:
	/* 0x25db: lea    rsi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_25df:
	/* 0x25df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25e4:
	/* 0x25e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e6:
	/* 0x25e6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25e9:
	/* 0x25e9: je     25f7 <trace_security_mmap_file+0x25f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f7;
	}
x86_l_25eb:
	/* 0x25eb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25ee:
	/* 0x25ee: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f2:
	/* 0x25f2: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_25f5:
	/* 0x25f5: jmp    25f9 <trace_security_mmap_file+0x25f9> */
	goto x86_l_25f9;
x86_l_25f7:
	/* 0x25f7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25f9:
	/* 0x25f9: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25fc:
	/* 0x25fc: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_25ff:
	/* 0x25ff: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2602:
	/* 0x2602: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2605:
	/* 0x2605: cmp    QWORD PTR [r13+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_260d:
	/* 0x260d: je     2701 <trace_security_mmap_file+0x2701> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2701;
	}
x86_l_2613:
	/* 0x2613: mov    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_261a:
	/* 0x261a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_261e:
	/* 0x261e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2623:
	/* 0x2623: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2628:
	/* 0x2628: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_262d:
	/* 0x262d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2632:
	/* 0x2632: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2634:
	/* 0x2634: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2639:
	/* 0x2639: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_263e:
	/* 0x263e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2643:
	/* 0x2643: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2648:
	/* 0x2648: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_264d:
	/* 0x264d: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2650:
	/* 0x2650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2652:
	/* 0x2652: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2656:
	/* 0x2656: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_265a:
	/* 0x265a: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_265e:
	/* 0x265e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2662:
	/* 0x2662: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2667:
	/* 0x2667: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_266c:
	/* 0x266c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2671:
	/* 0x2671: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2676:
	/* 0x2676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2678:
	/* 0x2678: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_267d:
	/* 0x267d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2681:
	/* 0x2681: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2686:
	/* 0x2686: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_268b:
	/* 0x268b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2690:
	/* 0x2690: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2695:
	/* 0x2695: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2697:
	/* 0x2697: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_269b:
	/* 0x269b: mov    DWORD PTR [r13+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_269f:
	/* 0x269f: mov    rbx,QWORD PTR [r13+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_26a6:
	/* 0x26a6: mov    r15,QWORD PTR [r13+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_26ad:
	/* 0x26ad: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26b2:
	/* 0x26b2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_26b9:
	/* 0x26b9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26be:
	/* 0x26be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26c3:
	/* 0x26c3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_26c6:
	/* 0x26c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c8:
	/* 0x26c8: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_26cf:
	/* 0x26cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26d2:
	/* 0x26d2: je     26f3 <trace_security_mmap_file+0x26f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26f3;
	}
x86_l_26d4:
	/* 0x26d4: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_26d7:
	/* 0x26d7: lea    rsi,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26db:
	/* 0x26db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26e0:
	/* 0x26e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e2:
	/* 0x26e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e5:
	/* 0x26e5: je     26f3 <trace_security_mmap_file+0x26f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26f3;
	}
x86_l_26e7:
	/* 0x26e7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ea:
	/* 0x26ea: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26ee:
	/* 0x26ee: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_26f1:
	/* 0x26f1: jmp    26f5 <trace_security_mmap_file+0x26f5> */
	goto x86_l_26f5;
x86_l_26f3:
	/* 0x26f3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26f5:
	/* 0x26f5: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_26f8:
	/* 0x26f8: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_26fb:
	/* 0x26fb: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_26fe:
	/* 0x26fe: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2701:
	/* 0x2701: cmp    QWORD PTR [r13+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_2709:
	/* 0x2709: je     27eb <trace_security_mmap_file+0x27eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27eb;
	}
x86_l_270f:
	/* 0x270f: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_2714:
	/* 0x2714: add    rdx,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_271b:
	/* 0x271b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2720:
	/* 0x2720: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2725:
	/* 0x2725: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_272a:
	/* 0x272a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_272f:
	/* 0x272f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2731:
	/* 0x2731: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2736:
	/* 0x2736: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_273b:
	/* 0x273b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2740:
	/* 0x2740: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2745:
	/* 0x2745: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_274a:
	/* 0x274a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274c:
	/* 0x274c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2751:
	/* 0x2751: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2756:
	/* 0x2756: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_275b:
	/* 0x275b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2760:
	/* 0x2760: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2763:
	/* 0x2763: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_2768:
	/* 0x2768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276a:
	/* 0x276a: lea    rbx,[r13+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_276e:
	/* 0x276e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2773:
	/* 0x2773: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2778:
	/* 0x2778: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_277b:
	/* 0x277b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2780:
	/* 0x2780: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2783:
	/* 0x2783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2785:
	/* 0x2785: mov    r15,QWORD PTR [r13+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_278c:
	/* 0x278c: mov    r13,QWORD PTR [r13+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_2793:
	/* 0x2793: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2798:
	/* 0x2798: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_279f:
	/* 0x279f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27a4:
	/* 0x27a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27a9:
	/* 0x27a9: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_27ac:
	/* 0x27ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ae:
	/* 0x27ae: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_27b5:
	/* 0x27b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27b8:
	/* 0x27b8: je     27d8 <trace_security_mmap_file+0x27d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d8;
	}
x86_l_27ba:
	/* 0x27ba: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_27bd:
	/* 0x27bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27c2:
	/* 0x27c2: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_27c5:
	/* 0x27c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c7:
	/* 0x27c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27ca:
	/* 0x27ca: je     27d8 <trace_security_mmap_file+0x27d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d8;
	}
x86_l_27cc:
	/* 0x27cc: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27cf:
	/* 0x27cf: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27d3:
	/* 0x27d3: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_27d6:
	/* 0x27d6: jmp    27da <trace_security_mmap_file+0x27da> */
	goto x86_l_27da;
x86_l_27d8:
	/* 0x27d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27da:
	/* 0x27da: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_27dd:
	/* 0x27dd: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_27e0:
	/* 0x27e0: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_27e3:
	/* 0x27e3: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_27e6:
	/* 0x27e6: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27eb:
	/* 0x27eb: cmp    QWORD PTR [r13+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_27f3:
	/* 0x27f3: je     2877 <trace_security_mmap_file+0x2877> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2877;
	}
x86_l_27f9:
	/* 0x27f9: lea    rbx,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_27fd:
	/* 0x27fd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2802:
	/* 0x2802: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_2807:
	/* 0x2807: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_280a:
	/* 0x280a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_280f:
	/* 0x280f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2811:
	/* 0x2811: mov    r15,QWORD PTR [r13+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_2818:
	/* 0x2818: mov    r13,QWORD PTR [r13+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_281f:
	/* 0x281f: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2824:
	/* 0x2824: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_282b:
	/* 0x282b: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2830:
	/* 0x2830: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2835:
	/* 0x2835: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2838:
	/* 0x2838: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_283a:
	/* 0x283a: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_2841:
	/* 0x2841: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2844:
	/* 0x2844: je     2864 <trace_security_mmap_file+0x2864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2864;
	}
x86_l_2846:
	/* 0x2846: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2849:
	/* 0x2849: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_284e:
	/* 0x284e: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2851:
	/* 0x2851: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2853:
	/* 0x2853: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2856:
	/* 0x2856: je     2864 <trace_security_mmap_file+0x2864> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2864;
	}
x86_l_2858:
	/* 0x2858: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_285b:
	/* 0x285b: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_285f:
	/* 0x285f: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2862:
	/* 0x2862: jmp    2866 <trace_security_mmap_file+0x2866> */
	goto x86_l_2866;
x86_l_2864:
	/* 0x2864: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2866:
	/* 0x2866: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2869:
	/* 0x2869: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_286c:
	/* 0x286c: or     r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_286f:
	/* 0x286f: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2872:
	/* 0x2872: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2877:
	/* 0x2877: mov    rbx,QWORD PTR [r13+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_287e:
	/* 0x287e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_2881:
	/* 0x2881: je     28e7 <trace_security_mmap_file+0x28e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28e7;
	}
x86_l_2883:
	/* 0x2883: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2887:
	/* 0x2887: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_288b:
	/* 0x288b: mov    r15,QWORD PTR [r13+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_2892:
	/* 0x2892: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2897:
	/* 0x2897: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_289e:
	/* 0x289e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a3:
	/* 0x28a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28a8:
	/* 0x28a8: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_28ab:
	/* 0x28ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ad:
	/* 0x28ad: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_28b4:
	/* 0x28b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28b7:
	/* 0x28b7: je     28d9 <trace_security_mmap_file+0x28d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d9;
	}
x86_l_28b9:
	/* 0x28b9: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_28bc:
	/* 0x28bc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28c1:
	/* 0x28c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28c6:
	/* 0x28c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c8:
	/* 0x28c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28cb:
	/* 0x28cb: je     28d9 <trace_security_mmap_file+0x28d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d9;
	}
x86_l_28cd:
	/* 0x28cd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d0:
	/* 0x28d0: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28d4:
	/* 0x28d4: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_28d7:
	/* 0x28d7: jmp    28db <trace_security_mmap_file+0x28db> */
	goto x86_l_28db;
x86_l_28d9:
	/* 0x28d9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28db:
	/* 0x28db: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_28de:
	/* 0x28de: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_28e1:
	/* 0x28e1: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_28e4:
	/* 0x28e4: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_28e7:
	/* 0x28e7: mov    rbx,QWORD PTR [r13+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_28ee:
	/* 0x28ee: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_28f1:
	/* 0x28f1: je     2952 <trace_security_mmap_file+0x2952> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10578ULL;
	}
x86_l_28f3:
	/* 0x28f3: mov    r15,QWORD PTR [r13+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_28fa:
	/* 0x28fa: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28ff:
	/* 0x28ff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_2906:
	/* 0x2906: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_290b:
	/* 0x290b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2910:
	/* 0x2910: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2913:
	/* 0x2913: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2915:
	/* 0x2915: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_291c:
	/* 0x291c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_291f:
	/* 0x291f: je     2944 <trace_security_mmap_file+0x2944> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10564ULL;
	}
x86_l_2921:
	/* 0x2921: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2924:
	/* 0x2924: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
	return 10537ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10537ULL: goto x86_l_2929;
	case 10545ULL: goto x86_l_2931;
	case 10547ULL: goto x86_l_2933;
	case 10550ULL: goto x86_l_2936;
	case 10552ULL: goto x86_l_2938;
	case 10555ULL: goto x86_l_293b;
	case 10559ULL: goto x86_l_293f;
	case 10562ULL: goto x86_l_2942;
	case 10564ULL: goto x86_l_2944;
	case 10566ULL: goto x86_l_2946;
	case 10569ULL: goto x86_l_2949;
	case 10572ULL: goto x86_l_294c;
	case 10575ULL: goto x86_l_294f;
	case 10578ULL: goto x86_l_2952;
	case 10585ULL: goto x86_l_2959;
	case 10588ULL: goto x86_l_295c;
	case 10594ULL: goto x86_l_2962;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10613ULL: goto x86_l_2975;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10626ULL: goto x86_l_2982;
	case 10628ULL: goto x86_l_2984;
	case 10635ULL: goto x86_l_298b;
	case 10638ULL: goto x86_l_298e;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10660ULL: goto x86_l_29a4;
	case 10662ULL: goto x86_l_29a6;
	case 10665ULL: goto x86_l_29a9;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10676ULL: goto x86_l_29b4;
	case 10681ULL: goto x86_l_29b9;
	case 10684ULL: goto x86_l_29bc;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10691ULL: goto x86_l_29c3;
	case 10694ULL: goto x86_l_29c6;
	case 10698ULL: goto x86_l_29ca;
	case 10701ULL: goto x86_l_29cd;
	case 10703ULL: goto x86_l_29cf;
	case 10705ULL: goto x86_l_29d1;
	case 10708ULL: goto x86_l_29d4;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10722ULL: goto x86_l_29e2;
	case 10729ULL: goto x86_l_29e9;
	case 10732ULL: goto x86_l_29ec;
	case 10734ULL: goto x86_l_29ee;
	case 10739ULL: goto x86_l_29f3;
	case 10743ULL: goto x86_l_29f7;
	case 10746ULL: goto x86_l_29fa;
	case 10753ULL: goto x86_l_2a01;
	case 10760ULL: goto x86_l_2a08;
	case 10763ULL: goto x86_l_2a0b;
	case 10770ULL: goto x86_l_2a12;
	case 10776ULL: goto x86_l_2a18;
	case 10784ULL: goto x86_l_2a20;
	case 10787ULL: goto x86_l_2a23;
	case 10793ULL: goto x86_l_2a29;
	case 10801ULL: goto x86_l_2a31;
	case 10808ULL: goto x86_l_2a38;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10820ULL: goto x86_l_2a44;
	case 10823ULL: goto x86_l_2a47;
	case 10829ULL: goto x86_l_2a4d;
	case 10832ULL: goto x86_l_2a50;
	case 10840ULL: goto x86_l_2a58;
	case 10844ULL: goto x86_l_2a5c;
	case 10849ULL: goto x86_l_2a61;
	case 10854ULL: goto x86_l_2a66;
	case 10859ULL: goto x86_l_2a6b;
	case 10864ULL: goto x86_l_2a70;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10876ULL: goto x86_l_2a7c;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	case 10891ULL: goto x86_l_2a8b;
	case 10896ULL: goto x86_l_2a90;
	case 10901ULL: goto x86_l_2a95;
	case 10903ULL: goto x86_l_2a97;
	case 10908ULL: goto x86_l_2a9c;
	case 10914ULL: goto x86_l_2aa2;
	case 10917ULL: goto x86_l_2aa5;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10941ULL: goto x86_l_2abd;
	case 10943ULL: goto x86_l_2abf;
	case 10948ULL: goto x86_l_2ac4;
	case 10952ULL: goto x86_l_2ac8;
	case 10956ULL: goto x86_l_2acc;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10971ULL: goto x86_l_2adb;
	case 10975ULL: goto x86_l_2adf;
	case 10980ULL: goto x86_l_2ae4;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10997ULL: goto x86_l_2af5;
	case 11002ULL: goto x86_l_2afa;
	case 11005ULL: goto x86_l_2afd;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11021ULL: goto x86_l_2b0d;
	case 11026ULL: goto x86_l_2b12;
	case 11031ULL: goto x86_l_2b17;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11043ULL: goto x86_l_2b23;
	case 11048ULL: goto x86_l_2b28;
	case 11051ULL: goto x86_l_2b2b;
	case 11057ULL: goto x86_l_2b31;
	case 11062ULL: goto x86_l_2b36;
	case 11065ULL: goto x86_l_2b39;
	case 11071ULL: goto x86_l_2b3f;
	case 11075ULL: goto x86_l_2b43;
	case 11080ULL: goto x86_l_2b48;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11097ULL: goto x86_l_2b59;
	case 11101ULL: goto x86_l_2b5d;
	case 11106ULL: goto x86_l_2b62;
	case 11108ULL: goto x86_l_2b64;
	case 11114ULL: goto x86_l_2b6a;
	case 11116ULL: goto x86_l_2b6c;
	case 11118ULL: goto x86_l_2b6e;
	case 11124ULL: goto x86_l_2b74;
	case 11127ULL: goto x86_l_2b77;
	case 11132ULL: goto x86_l_2b7c;
	case 11134ULL: goto x86_l_2b7e;
	case 11137ULL: goto x86_l_2b81;
	case 11143ULL: goto x86_l_2b87;
	case 11150ULL: goto x86_l_2b8e;
	case 11155ULL: goto x86_l_2b93;
	case 11157ULL: goto x86_l_2b95;
	case 11162ULL: goto x86_l_2b9a;
	case 11167ULL: goto x86_l_2b9f;
	case 11170ULL: goto x86_l_2ba2;
	case 11175ULL: goto x86_l_2ba7;
	case 11182ULL: goto x86_l_2bae;
	case 11187ULL: goto x86_l_2bb3;
	case 11192ULL: goto x86_l_2bb8;
	case 11195ULL: goto x86_l_2bbb;
	case 11200ULL: goto x86_l_2bc0;
	case 11202ULL: goto x86_l_2bc2;
	case 11204ULL: goto x86_l_2bc4;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11218ULL: goto x86_l_2bd2;
	case 11222ULL: goto x86_l_2bd6;
	case 11227ULL: goto x86_l_2bdb;
	case 11233ULL: goto x86_l_2be1;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11247ULL: goto x86_l_2bef;
	case 11252ULL: goto x86_l_2bf4;
	case 11256ULL: goto x86_l_2bf8;
	case 11260ULL: goto x86_l_2bfc;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11271ULL: goto x86_l_2c07;
	case 11274ULL: goto x86_l_2c0a;
	case 11279ULL: goto x86_l_2c0f;
	case 11284ULL: goto x86_l_2c14;
	case 11288ULL: goto x86_l_2c18;
	case 11293ULL: goto x86_l_2c1d;
	case 11295ULL: goto x86_l_2c1f;
	case 11299ULL: goto x86_l_2c23;
	case 11304ULL: goto x86_l_2c28;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11325ULL: goto x86_l_2c3d;
	case 11329ULL: goto x86_l_2c41;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11343ULL: goto x86_l_2c4f;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11361ULL: goto x86_l_2c61;
	case 11363ULL: goto x86_l_2c63;
	case 11368ULL: goto x86_l_2c68;
	case 11373ULL: goto x86_l_2c6d;
	case 11377ULL: goto x86_l_2c71;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11392ULL: goto x86_l_2c80;
	case 11397ULL: goto x86_l_2c85;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11407ULL: goto x86_l_2c8f;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11417ULL: goto x86_l_2c99;
	case 11419ULL: goto x86_l_2c9b;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11438ULL: goto x86_l_2cae;
	case 11443ULL: goto x86_l_2cb3;
	case 11445ULL: goto x86_l_2cb5;
	case 11449ULL: goto x86_l_2cb9;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11459ULL: goto x86_l_2cc3;
	case 11461ULL: goto x86_l_2cc5;
	case 11467ULL: goto x86_l_2ccb;
	case 11472ULL: goto x86_l_2cd0;
	case 11478ULL: goto x86_l_2cd6;
	case 11481ULL: goto x86_l_2cd9;
	case 11484ULL: goto x86_l_2cdc;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11501ULL: goto x86_l_2ced;
	case 11507ULL: goto x86_l_2cf3;
	case 11512ULL: goto x86_l_2cf8;
	case 11514ULL: goto x86_l_2cfa;
	case 11519ULL: goto x86_l_2cff;
	case 11524ULL: goto x86_l_2d04;
	case 11527ULL: goto x86_l_2d07;
	case 11533ULL: goto x86_l_2d0d;
	case 11539ULL: goto x86_l_2d13;
	case 11545ULL: goto x86_l_2d19;
	case 11550ULL: goto x86_l_2d1e;
	case 11554ULL: goto x86_l_2d22;
	case 11559ULL: goto x86_l_2d27;
	case 11564ULL: goto x86_l_2d2c;
	case 11569ULL: goto x86_l_2d31;
	case 11574ULL: goto x86_l_2d36;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11594ULL: goto x86_l_2d4a;
	case 11599ULL: goto x86_l_2d4f;
	case 11601ULL: goto x86_l_2d51;
	case 11603ULL: goto x86_l_2d53;
	case 11608ULL: goto x86_l_2d58;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11623ULL: goto x86_l_2d67;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11637ULL: goto x86_l_2d75;
	case 11642ULL: goto x86_l_2d7a;
	case 11646ULL: goto x86_l_2d7e;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11657ULL: goto x86_l_2d89;
	case 11661ULL: goto x86_l_2d8d;
	case 11664ULL: goto x86_l_2d90;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11678ULL: goto x86_l_2d9e;
	case 11683ULL: goto x86_l_2da3;
	case 11685ULL: goto x86_l_2da5;
	case 11689ULL: goto x86_l_2da9;
	case 11694ULL: goto x86_l_2dae;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11708ULL: goto x86_l_2dbc;
	case 11713ULL: goto x86_l_2dc1;
	case 11715ULL: goto x86_l_2dc3;
	case 11719ULL: goto x86_l_2dc7;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11746ULL: goto x86_l_2de2;
	case 11748ULL: goto x86_l_2de4;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11762ULL: goto x86_l_2df2;
	case 11767ULL: goto x86_l_2df7;
	case 11772ULL: goto x86_l_2dfc;
	case 11777ULL: goto x86_l_2e01;
	case 11782ULL: goto x86_l_2e06;
	case 11784ULL: goto x86_l_2e08;
	case 11789ULL: goto x86_l_2e0d;
	case 11792ULL: goto x86_l_2e10;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11802ULL: goto x86_l_2e1a;
	case 11804ULL: goto x86_l_2e1c;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11823ULL: goto x86_l_2e2f;
	case 11828ULL: goto x86_l_2e34;
	case 11830ULL: goto x86_l_2e36;
	case 11834ULL: goto x86_l_2e3a;
	case 11836ULL: goto x86_l_2e3c;
	case 11842ULL: goto x86_l_2e42;
	case 11844ULL: goto x86_l_2e44;
	case 11846ULL: goto x86_l_2e46;
	case 11852ULL: goto x86_l_2e4c;
	case 11854ULL: goto x86_l_2e4e;
	case 11856ULL: goto x86_l_2e50;
	case 11861ULL: goto x86_l_2e55;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11878ULL: goto x86_l_2e66;
	case 11883ULL: goto x86_l_2e6b;
	case 11886ULL: goto x86_l_2e6e;
	case 11892ULL: goto x86_l_2e74;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11907ULL: goto x86_l_2e83;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11926ULL: goto x86_l_2e96;
	case 11930ULL: goto x86_l_2e9a;
	case 11934ULL: goto x86_l_2e9e;
	case 11939ULL: goto x86_l_2ea3;
	case 11941ULL: goto x86_l_2ea5;
	case 11945ULL: goto x86_l_2ea9;
	case 11948ULL: goto x86_l_2eac;
	case 11953ULL: goto x86_l_2eb1;
	case 11958ULL: goto x86_l_2eb6;
	case 11962ULL: goto x86_l_2eba;
	case 11967ULL: goto x86_l_2ebf;
	case 11969ULL: goto x86_l_2ec1;
	case 11973ULL: goto x86_l_2ec5;
	case 11978ULL: goto x86_l_2eca;
	case 11983ULL: goto x86_l_2ecf;
	case 11988ULL: goto x86_l_2ed4;
	case 11992ULL: goto x86_l_2ed8;
	case 11997ULL: goto x86_l_2edd;
	case 11999ULL: goto x86_l_2edf;
	case 12003ULL: goto x86_l_2ee3;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12016ULL: goto x86_l_2ef0;
	case 12021ULL: goto x86_l_2ef5;
	case 12027ULL: goto x86_l_2efb;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12050ULL: goto x86_l_2f12;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12065ULL: goto x86_l_2f21;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12082ULL: goto x86_l_2f32;
	case 12087ULL: goto x86_l_2f37;
	case 12089ULL: goto x86_l_2f39;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12103ULL: goto x86_l_2f47;
	case 12108ULL: goto x86_l_2f4c;
	case 12112ULL: goto x86_l_2f50;
	case 12117ULL: goto x86_l_2f55;
	case 12119ULL: goto x86_l_2f57;
	case 12123ULL: goto x86_l_2f5b;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12150ULL: goto x86_l_2f76;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2929:
	/* 0x2929: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2931:
	/* 0x2931: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2933:
	/* 0x2933: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2936:
	/* 0x2936: je     2944 <trace_security_mmap_file+0x2944> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2944;
	}
x86_l_2938:
	/* 0x2938: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293b:
	/* 0x293b: mov    r14,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_293f:
	/* 0x293f: not    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2942:
	/* 0x2942: jmp    2946 <trace_security_mmap_file+0x2946> */
	goto x86_l_2946;
x86_l_2944:
	/* 0x2944: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2946:
	/* 0x2946: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2949:
	/* 0x2949: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_294c:
	/* 0x294c: or     r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_294f:
	/* 0x294f: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2952:
	/* 0x2952: mov    r15,QWORD PTR [r13+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_2959:
	/* 0x2959: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_295c:
	/* 0x295c: je     29e2 <trace_security_mmap_file+0x29e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e2;
	}
x86_l_2962:
	/* 0x2962: mov    r13,QWORD PTR [r13+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_2969:
	/* 0x2969: mov    WORD PTR [rsp+0x20],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296e:
	/* 0x296e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_2975:
	/* 0x2975: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_297a:
	/* 0x297a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_297f:
	/* 0x297f: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_2982:
	/* 0x2982: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2984:
	/* 0x2984: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_298b:
	/* 0x298b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_298e:
	/* 0x298e: je     29cf <trace_security_mmap_file+0x29cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29cf;
	}
x86_l_2990:
	/* 0x2990: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2993:
	/* 0x2993: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2998:
	/* 0x2998: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_299c:
	/* 0x299c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29a1:
	/* 0x29a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29a4:
	/* 0x29a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a6:
	/* 0x29a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29a9:
	/* 0x29a9: jne    29c3 <trace_security_mmap_file+0x29c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_29c3;
	}
x86_l_29ab:
	/* 0x29ab: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_29b0:
	/* 0x29b0: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b4:
	/* 0x29b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29b9:
	/* 0x29b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29bc:
	/* 0x29bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29be:
	/* 0x29be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29c1:
	/* 0x29c1: je     29cf <trace_security_mmap_file+0x29cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29cf;
	}
x86_l_29c3:
	/* 0x29c3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c6:
	/* 0x29c6: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ca:
	/* 0x29ca: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_29cd:
	/* 0x29cd: jmp    29d1 <trace_security_mmap_file+0x29d1> */
	goto x86_l_29d1;
x86_l_29cf:
	/* 0x29cf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29d1:
	/* 0x29d1: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_29d4:
	/* 0x29d4: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_29d7:
	/* 0x29d7: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_29da:
	/* 0x29da: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_29dd:
	/* 0x29dd: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29e2:
	/* 0x29e2: mov    rax,QWORD PTR [r13+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_29e9:
	/* 0x29e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29ec:
	/* 0x29ec: je     29fa <trace_security_mmap_file+0x29fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29fa;
	}
x86_l_29ee:
	/* 0x29ee: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_29f3:
	/* 0x29f3: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_29f7:
	/* 0x29f7: or     r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_29fa:
	/* 0x29fa: and    r12,QWORD PTR [r13+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_2a01:
	/* 0x2a01: mov    rcx,QWORD PTR [r13+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a08:
	/* 0x2a08: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a0b:
	/* 0x2a0b: mov    QWORD PTR [r13+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2a12:
	/* 0x2a12: je     3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15845ULL;
	}
x86_l_2a18:
	/* 0x2a18: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2a20:
	/* 0x2a20: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_2a23:
	/* 0x2a23: jne    3011 <trace_security_mmap_file+0x3011> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12305ULL;
	}
x86_l_2a29:
	/* 0x2a29: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a31:
	/* 0x2a31: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_2a38:
	/* 0x2a38: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a3d:
	/* 0x2a3d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a42:
	/* 0x2a42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a44:
	/* 0x2a44: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a47:
	/* 0x2a47: je     2b9f <trace_security_mmap_file+0x2b9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b9f;
	}
x86_l_2a4d:
	/* 0x2a4d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2a50:
	/* 0x2a50: mov    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a58:
	/* 0x2a58: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5c:
	/* 0x2a5c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x2a70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a72:
	/* 0x2a72: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a77:
	/* 0x2a77: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a7c:
	/* 0x2a7c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a81:
	/* 0x2a81: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2a86:
	/* 0x2a86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a8b:
	/* 0x2a8b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a90:
	/* 0x2a90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a95:
	/* 0x2a95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a97:
	/* 0x2a97: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_2a9c:
	/* 0x2a9c: jne    2ba7 <trace_security_mmap_file+0x2ba7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ba7;
	}
x86_l_2aa2:
	/* 0x2aa2: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_2aa5:
	/* 0x2aa5: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2aa9:
	/* 0x2aa9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aae:
	/* 0x2aae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ab8:
	/* 0x2ab8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2abd:
	/* 0x2abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2abf:
	/* 0x2abf: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ac4:
	/* 0x2ac4: lea    rcx,[r13-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_2ac8:
	/* 0x2ac8: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2acc:
	/* 0x2acc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2adb:
	/* 0x2adb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2adf:
	/* 0x2adf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ae4:
	/* 0x2ae4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae6:
	/* 0x2ae6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2af0:
	/* 0x2af0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af5:
	/* 0x2af5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2afa:
	/* 0x2afa: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2afd:
	/* 0x2afd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aff:
	/* 0x2aff: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b04:
	/* 0x2b04: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b09:
	/* 0x2b09: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b0d:
	/* 0x2b0d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b12:
	/* 0x2b12: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b17:
	/* 0x2b17: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b1c:
	/* 0x2b1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b21:
	/* 0x2b21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b23:
	/* 0x2b23: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b28:
	/* 0x2b28: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2b2b:
	/* 0x2b2b: je     2bc9 <trace_security_mmap_file+0x2bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc9;
	}
x86_l_2b31:
	/* 0x2b31: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b36:
	/* 0x2b36: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b39:
	/* 0x2b39: je     2bc9 <trace_security_mmap_file+0x2bc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bc9;
	}
x86_l_2b3f:
	/* 0x2b3f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b43:
	/* 0x2b43: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b48:
	/* 0x2b48: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2b4d:
	/* 0x2b4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b52:
	/* 0x2b52: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2b57:
	/* 0x2b57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b59:
	/* 0x2b59: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b5d:
	/* 0x2b5d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2b62:
	/* 0x2b62: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b64:
	/* 0x2b64: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2b6a:
	/* 0x2b6a: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2b6c:
	/* 0x2b6c: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_2b6e:
	/* 0x2b6e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2b74:
	/* 0x2b74: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b77:
	/* 0x2b77: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2b7c:
	/* 0x2b7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7e:
	/* 0x2b7e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b81:
	/* 0x2b81: jl     2d19 <trace_security_mmap_file+0x2d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2d19;
	}
x86_l_2b87:
	/* 0x2b87: mov    BYTE PTR [rbp+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2b93:
	/* 0x2b93: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b95:
	/* 0x2b95: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b9a:
	/* 0x2b9a: jmp    2c4a <trace_security_mmap_file+0x2c4a> */
	goto x86_l_2c4a;
x86_l_2b9f:
	/* 0x2b9f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba2:
	/* 0x2ba2: jmp    3011 <trace_security_mmap_file+0x3011> */
	return 12305ULL;
x86_l_2ba7:
	/* 0x2ba7: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_2bae:
	/* 0x2bae: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_2bb3:
	/* 0x2bb3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2bb8:
	/* 0x2bb8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2bbb:
	/* 0x2bbb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bc0:
	/* 0x2bc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc2:
	/* 0x2bc2: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc4:
	/* 0x2bc4: jmp    3008 <trace_security_mmap_file+0x3008> */
	return 12296ULL;
x86_l_2bc9:
	/* 0x2bc9: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2bcc:
	/* 0x2bcc: jne    2d19 <trace_security_mmap_file+0x2d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d19;
	}
x86_l_2bd2:
	/* 0x2bd2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd6:
	/* 0x2bd6: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2bdb:
	/* 0x2bdb: je     2d19 <trace_security_mmap_file+0x2d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d19;
	}
x86_l_2be1:
	/* 0x2be1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2be5:
	/* 0x2be5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bea:
	/* 0x2bea: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2bef:
	/* 0x2bef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2bf4:
	/* 0x2bf4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf8:
	/* 0x2bf8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2bfc:
	/* 0x2bfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c01:
	/* 0x2c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c03:
	/* 0x2c03: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c07:
	/* 0x2c07: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2c0a:
	/* 0x2c0a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c0f:
	/* 0x2c0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c14:
	/* 0x2c14: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c18:
	/* 0x2c18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c1d:
	/* 0x2c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c1f:
	/* 0x2c1f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c23:
	/* 0x2c23: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c28:
	/* 0x2c28: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2c2d:
	/* 0x2c2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c32:
	/* 0x2c32: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c36:
	/* 0x2c36: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c3b:
	/* 0x2c3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3d:
	/* 0x2c3d: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c41:
	/* 0x2c41: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c45:
	/* 0x2c45: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2c4a:
	/* 0x2c4a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c4f:
	/* 0x2c4f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c54:
	/* 0x2c54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c59:
	/* 0x2c59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2c61:
	/* 0x2c61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c63:
	/* 0x2c63: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c68:
	/* 0x2c68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c6d:
	/* 0x2c6d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c71:
	/* 0x2c71: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c76:
	/* 0x2c76: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c80:
	/* 0x2c80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c85:
	/* 0x2c85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c87:
	/* 0x2c87: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c8c:
	/* 0x2c8c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2c8f:
	/* 0x2c8f: je     2d04 <trace_security_mmap_file+0x2d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d04;
	}
x86_l_2c91:
	/* 0x2c91: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c96:
	/* 0x2c96: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c99:
	/* 0x2c99: je     2d04 <trace_security_mmap_file+0x2d04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d04;
	}
x86_l_2c9b:
	/* 0x2c9b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c9f:
	/* 0x2c9f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cae:
	/* 0x2cae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2cb3:
	/* 0x2cb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb5:
	/* 0x2cb5: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2cb9:
	/* 0x2cb9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2cbb:
	/* 0x2cbb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2cc1:
	/* 0x2cc1: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2cc3:
	/* 0x2cc3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cc5:
	/* 0x2cc5: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_2ccb:
	/* 0x2ccb: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cd0:
	/* 0x2cd0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2cd6:
	/* 0x2cd6: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_2cd9:
	/* 0x2cd9: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cdc:
	/* 0x2cdc: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2cde:
	/* 0x2cde: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2ce3:
	/* 0x2ce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ce5:
	/* 0x2ce5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ce8:
	/* 0x2ce8: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_2d0d;
	}
x86_l_2cea:
	/* 0x2cea: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2ced:
	/* 0x2ced: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2cf3:
	/* 0x2cf3: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2cf8:
	/* 0x2cf8: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cfa:
	/* 0x2cfa: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cff:
	/* 0x2cff: jmp    2f5f <trace_security_mmap_file+0x2f5f> */
	goto x86_l_2f5f;
x86_l_2d04:
	/* 0x2d04: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d07:
	/* 0x2d07: je     2eec <trace_security_mmap_file+0x2eec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eec;
	}
x86_l_2d0d:
	/* 0x2d0d: cmp    ebx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_2d13:
	/* 0x2d13: jne    2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12264ULL;
	}
x86_l_2d19:
	/* 0x2d19: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d1e:
	/* 0x2d1e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d22:
	/* 0x2d22: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d27:
	/* 0x2d27: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2d2c:
	/* 0x2d2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d31:
	/* 0x2d31: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2d36:
	/* 0x2d36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d38:
	/* 0x2d38: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_2d42:
	/* 0x2d42: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2d47:
	/* 0x2d47: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2d4a:
	/* 0x2d4a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d4f:
	/* 0x2d4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d51:
	/* 0x2d51: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d53:
	/* 0x2d53: jmp    3000 <trace_security_mmap_file+0x3000> */
	return 12288ULL;
x86_l_2d58:
	/* 0x2d58: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d5c:
	/* 0x2d5c: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2d61:
	/* 0x2d61: je     196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6508ULL;
	}
x86_l_2d67:
	/* 0x2d67: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d6b:
	/* 0x2d6b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d70:
	/* 0x2d70: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d75:
	/* 0x2d75: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d7a:
	/* 0x2d7a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d7e:
	/* 0x2d7e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d82:
	/* 0x2d82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d87:
	/* 0x2d87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d89:
	/* 0x2d89: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d90:
	/* 0x2d90: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2d95:
	/* 0x2d95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d9a:
	/* 0x2d9a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d9e:
	/* 0x2d9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da3:
	/* 0x2da3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da5:
	/* 0x2da5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2da9:
	/* 0x2da9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2dae:
	/* 0x2dae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2db3:
	/* 0x2db3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2db8:
	/* 0x2db8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dbc:
	/* 0x2dbc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc1:
	/* 0x2dc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc3:
	/* 0x2dc3: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dc7:
	/* 0x2dc7: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dcb:
	/* 0x2dcb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dd0:
	/* 0x2dd0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dda:
	/* 0x2dda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ddf:
	/* 0x2ddf: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_2de2:
	/* 0x2de2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de4:
	/* 0x2de4: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2de9:
	/* 0x2de9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2dee:
	/* 0x2dee: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2df2:
	/* 0x2df2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2df7:
	/* 0x2df7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2dfc:
	/* 0x2dfc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e01:
	/* 0x2e01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e06:
	/* 0x2e06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e08:
	/* 0x2e08: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e0d:
	/* 0x2e0d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e10:
	/* 0x2e10: je     2e6b <trace_security_mmap_file+0x2e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e6b;
	}
x86_l_2e12:
	/* 0x2e12: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e17:
	/* 0x2e17: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e1a:
	/* 0x2e1a: je     2e6b <trace_security_mmap_file+0x2e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e6b;
	}
x86_l_2e1c:
	/* 0x2e1c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2e20:
	/* 0x2e20: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e25:
	/* 0x2e25: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2e2a:
	/* 0x2e2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e2f:
	/* 0x2e2f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2e34:
	/* 0x2e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e36:
	/* 0x2e36: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2e3a:
	/* 0x2e3a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e3c:
	/* 0x2e3c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e42:
	/* 0x2e42: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2e44:
	/* 0x2e44: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e46:
	/* 0x2e46: jae    3cb6 <trace_security_mmap_file+0x3cb6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 15542ULL;
	}
x86_l_2e4c:
	/* 0x2e4c: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2e4e:
	/* 0x2e4e: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2e50:
	/* 0x2e50: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e55:
	/* 0x2e55: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2e58:
	/* 0x2e58: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2e5d:
	/* 0x2e5d: mov    BYTE PTR [r12+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_2e66:
	/* 0x2e66: jmp    19b2 <trace_security_mmap_file+0x19b2> */
	return 6578ULL;
x86_l_2e6b:
	/* 0x2e6b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e6e:
	/* 0x2e6e: jne    196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6508ULL;
	}
x86_l_2e74:
	/* 0x2e74: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e78:
	/* 0x2e78: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2e7d:
	/* 0x2e7d: je     196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6508ULL;
	}
x86_l_2e83:
	/* 0x2e83: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e87:
	/* 0x2e87: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2e91:
	/* 0x2e91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e96:
	/* 0x2e96: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e9a:
	/* 0x2e9a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e9e:
	/* 0x2e9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea3:
	/* 0x2ea3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea5:
	/* 0x2ea5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ea9:
	/* 0x2ea9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2eac:
	/* 0x2eac: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2eb1:
	/* 0x2eb1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2eb6:
	/* 0x2eb6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eba:
	/* 0x2eba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ebf:
	/* 0x2ebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ec1:
	/* 0x2ec1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ec5:
	/* 0x2ec5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2eca:
	/* 0x2eca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2ecf:
	/* 0x2ecf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ed4:
	/* 0x2ed4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ed8:
	/* 0x2ed8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2edd:
	/* 0x2edd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2edf:
	/* 0x2edf: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ee3:
	/* 0x2ee3: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2ee7:
	/* 0x2ee7: jmp    3cee <trace_security_mmap_file+0x3cee> */
	return 15598ULL;
x86_l_2eec:
	/* 0x2eec: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef0:
	/* 0x2ef0: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2ef5:
	/* 0x2ef5: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d0d;
	}
x86_l_2efb:
	/* 0x2efb: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2eff:
	/* 0x2eff: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f04:
	/* 0x2f04: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f09:
	/* 0x2f09: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f0e:
	/* 0x2f0e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f12:
	/* 0x2f12: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f16:
	/* 0x2f16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f1b:
	/* 0x2f1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f1d:
	/* 0x2f1d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f21:
	/* 0x2f21: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2f24:
	/* 0x2f24: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f29:
	/* 0x2f29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f32:
	/* 0x2f32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f37:
	/* 0x2f37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f39:
	/* 0x2f39: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f3d:
	/* 0x2f3d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f42:
	/* 0x2f42: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_2f47:
	/* 0x2f47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f50:
	/* 0x2f50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f55:
	/* 0x2f55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f57:
	/* 0x2f57: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5b:
	/* 0x2f5b: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f5f:
	/* 0x2f5f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f64:
	/* 0x2f64: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f69:
	/* 0x2f69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f73:
	/* 0x2f73: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2f76:
	/* 0x2f76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 12152ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12162ULL: goto x86_l_2f82;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12186ULL: goto x86_l_2f9a;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12196ULL: goto x86_l_2fa4;
	case 12202ULL: goto x86_l_2faa;
	case 12207ULL: goto x86_l_2faf;
	case 12210ULL: goto x86_l_2fb2;
	case 12216ULL: goto x86_l_2fb8;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12235ULL: goto x86_l_2fcb;
	case 12240ULL: goto x86_l_2fd0;
	case 12242ULL: goto x86_l_2fd2;
	case 12246ULL: goto x86_l_2fd6;
	case 12248ULL: goto x86_l_2fd8;
	case 12254ULL: goto x86_l_2fde;
	case 12256ULL: goto x86_l_2fe0;
	case 12258ULL: goto x86_l_2fe2;
	case 12264ULL: goto x86_l_2fe8;
	case 12266ULL: goto x86_l_2fea;
	case 12268ULL: goto x86_l_2fec;
	case 12273ULL: goto x86_l_2ff1;
	case 12276ULL: goto x86_l_2ff4;
	case 12281ULL: goto x86_l_2ff9;
	case 12288ULL: goto x86_l_3000;
	case 12293ULL: goto x86_l_3005;
	case 12296ULL: goto x86_l_3008;
	case 12302ULL: goto x86_l_300e;
	case 12305ULL: goto x86_l_3011;
	case 12313ULL: goto x86_l_3019;
	case 12319ULL: goto x86_l_301f;
	case 12325ULL: goto x86_l_3025;
	case 12334ULL: goto x86_l_302e;
	case 12342ULL: goto x86_l_3036;
	case 12350ULL: goto x86_l_303e;
	case 12356ULL: goto x86_l_3044;
	case 12358ULL: goto x86_l_3046;
	case 12362ULL: goto x86_l_304a;
	case 12369ULL: goto x86_l_3051;
	case 12374ULL: goto x86_l_3056;
	case 12379ULL: goto x86_l_305b;
	case 12387ULL: goto x86_l_3063;
	case 12391ULL: goto x86_l_3067;
	case 12398ULL: goto x86_l_306e;
	case 12403ULL: goto x86_l_3073;
	case 12406ULL: goto x86_l_3076;
	case 12408ULL: goto x86_l_3078;
	case 12410ULL: goto x86_l_307a;
	case 12412ULL: goto x86_l_307c;
	case 12420ULL: goto x86_l_3084;
	case 12427ULL: goto x86_l_308b;
	case 12429ULL: goto x86_l_308d;
	case 12437ULL: goto x86_l_3095;
	case 12445ULL: goto x86_l_309d;
	case 12448ULL: goto x86_l_30a0;
	case 12456ULL: goto x86_l_30a8;
	case 12463ULL: goto x86_l_30af;
	case 12471ULL: goto x86_l_30b7;
	case 12478ULL: goto x86_l_30be;
	case 12480ULL: goto x86_l_30c0;
	case 12489ULL: goto x86_l_30c9;
	case 12495ULL: goto x86_l_30cf;
	case 12497ULL: goto x86_l_30d1;
	case 12505ULL: goto x86_l_30d9;
	case 12509ULL: goto x86_l_30dd;
	case 12513ULL: goto x86_l_30e1;
	case 12520ULL: goto x86_l_30e8;
	case 12525ULL: goto x86_l_30ed;
	case 12530ULL: goto x86_l_30f2;
	case 12535ULL: goto x86_l_30f7;
	case 12537ULL: goto x86_l_30f9;
	case 12540ULL: goto x86_l_30fc;
	case 12542ULL: goto x86_l_30fe;
	case 12545ULL: goto x86_l_3101;
	case 12553ULL: goto x86_l_3109;
	case 12560ULL: goto x86_l_3110;
	case 12568ULL: goto x86_l_3118;
	case 12575ULL: goto x86_l_311f;
	case 12577ULL: goto x86_l_3121;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12594ULL: goto x86_l_3132;
	case 12598ULL: goto x86_l_3136;
	case 12605ULL: goto x86_l_313d;
	case 12613ULL: goto x86_l_3145;
	case 12618ULL: goto x86_l_314a;
	case 12623ULL: goto x86_l_314f;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12633ULL: goto x86_l_3159;
	case 12635ULL: goto x86_l_315b;
	case 12638ULL: goto x86_l_315e;
	case 12646ULL: goto x86_l_3166;
	case 12653ULL: goto x86_l_316d;
	case 12661ULL: goto x86_l_3175;
	case 12668ULL: goto x86_l_317c;
	case 12670ULL: goto x86_l_317e;
	case 12679ULL: goto x86_l_3187;
	case 12685ULL: goto x86_l_318d;
	case 12687ULL: goto x86_l_318f;
	case 12691ULL: goto x86_l_3193;
	case 12698ULL: goto x86_l_319a;
	case 12706ULL: goto x86_l_31a2;
	case 12711ULL: goto x86_l_31a7;
	case 12716ULL: goto x86_l_31ac;
	case 12721ULL: goto x86_l_31b1;
	case 12723ULL: goto x86_l_31b3;
	case 12726ULL: goto x86_l_31b6;
	case 12728ULL: goto x86_l_31b8;
	case 12731ULL: goto x86_l_31bb;
	case 12739ULL: goto x86_l_31c3;
	case 12746ULL: goto x86_l_31ca;
	case 12754ULL: goto x86_l_31d2;
	case 12761ULL: goto x86_l_31d9;
	case 12763ULL: goto x86_l_31db;
	case 12772ULL: goto x86_l_31e4;
	case 12778ULL: goto x86_l_31ea;
	case 12780ULL: goto x86_l_31ec;
	case 12784ULL: goto x86_l_31f0;
	case 12791ULL: goto x86_l_31f7;
	case 12799ULL: goto x86_l_31ff;
	case 12804ULL: goto x86_l_3204;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12816ULL: goto x86_l_3210;
	case 12819ULL: goto x86_l_3213;
	case 12821ULL: goto x86_l_3215;
	case 12824ULL: goto x86_l_3218;
	case 12832ULL: goto x86_l_3220;
	case 12839ULL: goto x86_l_3227;
	case 12847ULL: goto x86_l_322f;
	case 12854ULL: goto x86_l_3236;
	case 12856ULL: goto x86_l_3238;
	case 12865ULL: goto x86_l_3241;
	case 12871ULL: goto x86_l_3247;
	case 12873ULL: goto x86_l_3249;
	case 12877ULL: goto x86_l_324d;
	case 12884ULL: goto x86_l_3254;
	case 12892ULL: goto x86_l_325c;
	case 12897ULL: goto x86_l_3261;
	case 12902ULL: goto x86_l_3266;
	case 12907ULL: goto x86_l_326b;
	case 12909ULL: goto x86_l_326d;
	case 12912ULL: goto x86_l_3270;
	case 12914ULL: goto x86_l_3272;
	case 12917ULL: goto x86_l_3275;
	case 12925ULL: goto x86_l_327d;
	case 12932ULL: goto x86_l_3284;
	case 12940ULL: goto x86_l_328c;
	case 12947ULL: goto x86_l_3293;
	case 12949ULL: goto x86_l_3295;
	case 12958ULL: goto x86_l_329e;
	case 12964ULL: goto x86_l_32a4;
	case 12966ULL: goto x86_l_32a6;
	case 12970ULL: goto x86_l_32aa;
	case 12977ULL: goto x86_l_32b1;
	case 12985ULL: goto x86_l_32b9;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13005ULL: goto x86_l_32cd;
	case 13007ULL: goto x86_l_32cf;
	case 13010ULL: goto x86_l_32d2;
	case 13018ULL: goto x86_l_32da;
	case 13025ULL: goto x86_l_32e1;
	case 13032ULL: goto x86_l_32e8;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13048ULL: goto x86_l_32f8;
	case 13055ULL: goto x86_l_32ff;
	case 13059ULL: goto x86_l_3303;
	case 13064ULL: goto x86_l_3308;
	case 13072ULL: goto x86_l_3310;
	case 13079ULL: goto x86_l_3317;
	case 13084ULL: goto x86_l_331c;
	case 13089ULL: goto x86_l_3321;
	case 13091ULL: goto x86_l_3323;
	case 13094ULL: goto x86_l_3326;
	case 13100ULL: goto x86_l_332c;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13113ULL: goto x86_l_3339;
	case 13115ULL: goto x86_l_333b;
	case 13120ULL: goto x86_l_3340;
	case 13125ULL: goto x86_l_3345;
	case 13128ULL: goto x86_l_3348;
	case 13134ULL: goto x86_l_334e;
	case 13140ULL: goto x86_l_3354;
	case 13145ULL: goto x86_l_3359;
	case 13152ULL: goto x86_l_3360;
	case 13159ULL: goto x86_l_3367;
	case 13165ULL: goto x86_l_336d;
	case 13168ULL: goto x86_l_3370;
	case 13171ULL: goto x86_l_3373;
	case 13174ULL: goto x86_l_3376;
	case 13180ULL: goto x86_l_337c;
	case 13186ULL: goto x86_l_3382;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13200ULL: goto x86_l_3390;
	case 13207ULL: goto x86_l_3397;
	case 13212ULL: goto x86_l_339c;
	case 13215ULL: goto x86_l_339f;
	case 13217ULL: goto x86_l_33a1;
	case 13219ULL: goto x86_l_33a3;
	case 13225ULL: goto x86_l_33a9;
	case 13232ULL: goto x86_l_33b0;
	case 13238ULL: goto x86_l_33b6;
	case 13245ULL: goto x86_l_33bd;
	case 13249ULL: goto x86_l_33c1;
	case 13253ULL: goto x86_l_33c5;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13270ULL: goto x86_l_33d6;
	case 13277ULL: goto x86_l_33dd;
	case 13279ULL: goto x86_l_33df;
	case 13282ULL: goto x86_l_33e2;
	case 13288ULL: goto x86_l_33e8;
	case 13291ULL: goto x86_l_33eb;
	case 13296ULL: goto x86_l_33f0;
	case 13299ULL: goto x86_l_33f3;
	case 13301ULL: goto x86_l_33f5;
	case 13304ULL: goto x86_l_33f8;
	case 13310ULL: goto x86_l_33fe;
	case 13313ULL: goto x86_l_3401;
	case 13317ULL: goto x86_l_3405;
	case 13320ULL: goto x86_l_3408;
	case 13325ULL: goto x86_l_340d;
	case 13330ULL: goto x86_l_3412;
	case 13333ULL: goto x86_l_3415;
	case 13335ULL: goto x86_l_3417;
	case 13343ULL: goto x86_l_341f;
	case 13349ULL: goto x86_l_3425;
	case 13352ULL: goto x86_l_3428;
	case 13359ULL: goto x86_l_342f;
	case 13366ULL: goto x86_l_3436;
	case 13369ULL: goto x86_l_3439;
	case 13372ULL: goto x86_l_343c;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13383ULL: goto x86_l_3447;
	case 13386ULL: goto x86_l_344a;
	case 13388ULL: goto x86_l_344c;
	case 13391ULL: goto x86_l_344f;
	case 13397ULL: goto x86_l_3455;
	case 13405ULL: goto x86_l_345d;
	case 13413ULL: goto x86_l_3465;
	case 13420ULL: goto x86_l_346c;
	case 13425ULL: goto x86_l_3471;
	case 13430ULL: goto x86_l_3476;
	case 13432ULL: goto x86_l_3478;
	case 13435ULL: goto x86_l_347b;
	case 13437ULL: goto x86_l_347d;
	case 13442ULL: goto x86_l_3482;
	case 13445ULL: goto x86_l_3485;
	case 13452ULL: goto x86_l_348c;
	case 13458ULL: goto x86_l_3492;
	case 13460ULL: goto x86_l_3494;
	case 13465ULL: goto x86_l_3499;
	case 13472ULL: goto x86_l_34a0;
	case 13477ULL: goto x86_l_34a5;
	case 13483ULL: goto x86_l_34ab;
	case 13490ULL: goto x86_l_34b2;
	case 13494ULL: goto x86_l_34b6;
	case 13499ULL: goto x86_l_34bb;
	case 13504ULL: goto x86_l_34c0;
	case 13509ULL: goto x86_l_34c5;
	case 13514ULL: goto x86_l_34ca;
	case 13517ULL: goto x86_l_34cd;
	case 13519ULL: goto x86_l_34cf;
	case 13524ULL: goto x86_l_34d4;
	case 13529ULL: goto x86_l_34d9;
	case 13533ULL: goto x86_l_34dd;
	case 13538ULL: goto x86_l_34e2;
	case 13543ULL: goto x86_l_34e7;
	case 13548ULL: goto x86_l_34ec;
	case 13553ULL: goto x86_l_34f1;
	case 13555ULL: goto x86_l_34f3;
	case 13560ULL: goto x86_l_34f8;
	case 13564ULL: goto x86_l_34fc;
	case 13569ULL: goto x86_l_3501;
	case 13574ULL: goto x86_l_3506;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13586ULL: goto x86_l_3512;
	case 13591ULL: goto x86_l_3517;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13605ULL: goto x86_l_3525;
	case 13610ULL: goto x86_l_352a;
	case 13615ULL: goto x86_l_352f;
	case 13617ULL: goto x86_l_3531;
	case 13621ULL: goto x86_l_3535;
	case 13625ULL: goto x86_l_3539;
	case 13629ULL: goto x86_l_353d;
	case 13634ULL: goto x86_l_3542;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13649ULL: goto x86_l_3551;
	case 13652ULL: goto x86_l_3554;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13664ULL: goto x86_l_3560;
	case 13669ULL: goto x86_l_3565;
	case 13674ULL: goto x86_l_356a;
	case 13679ULL: goto x86_l_356f;
	case 13682ULL: goto x86_l_3572;
	case 13684ULL: goto x86_l_3574;
	case 13688ULL: goto x86_l_3578;
	case 13692ULL: goto x86_l_357c;
	case 13696ULL: goto x86_l_3580;
	case 13700ULL: goto x86_l_3584;
	case 13705ULL: goto x86_l_3589;
	case 13710ULL: goto x86_l_358e;
	case 13715ULL: goto x86_l_3593;
	case 13720ULL: goto x86_l_3598;
	case 13722ULL: goto x86_l_359a;
	case 13726ULL: goto x86_l_359e;
	case 13730ULL: goto x86_l_35a2;
	case 13735ULL: goto x86_l_35a7;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13753ULL: goto x86_l_35b9;
	case 13755ULL: goto x86_l_35bb;
	case 13760ULL: goto x86_l_35c0;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13786ULL: goto x86_l_35da;
	case 13791ULL: goto x86_l_35df;
	case 13796ULL: goto x86_l_35e4;
	case 13801ULL: goto x86_l_35e9;
	case 13806ULL: goto x86_l_35ee;
	case 13811ULL: goto x86_l_35f3;
	case 13814ULL: goto x86_l_35f6;
	case 13816ULL: goto x86_l_35f8;
	case 13820ULL: goto x86_l_35fc;
	case 13824ULL: goto x86_l_3600;
	case 13828ULL: goto x86_l_3604;
	case 13832ULL: goto x86_l_3608;
	case 13837ULL: goto x86_l_360d;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13858ULL: goto x86_l_3622;
	case 13862ULL: goto x86_l_3626;
	case 13867ULL: goto x86_l_362b;
	case 13872ULL: goto x86_l_3630;
	case 13877ULL: goto x86_l_3635;
	case 13882ULL: goto x86_l_363a;
	case 13885ULL: goto x86_l_363d;
	case 13887ULL: goto x86_l_363f;
	case 13892ULL: goto x86_l_3644;
	case 13897ULL: goto x86_l_3649;
	case 13902ULL: goto x86_l_364e;
	case 13907ULL: goto x86_l_3653;
	case 13912ULL: goto x86_l_3658;
	case 13915ULL: goto x86_l_365b;
	case 13917ULL: goto x86_l_365d;
	case 13921ULL: goto x86_l_3661;
	case 13925ULL: goto x86_l_3665;
	case 13929ULL: goto x86_l_3669;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13943ULL: goto x86_l_3677;
	case 13948ULL: goto x86_l_367c;
	case 13953ULL: goto x86_l_3681;
	case 13955ULL: goto x86_l_3683;
	case 13960ULL: goto x86_l_3688;
	case 13964ULL: goto x86_l_368c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2f78:
	/* 0x2f78: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f82:
	/* 0x2f82: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f86:
	/* 0x2f86: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f8b:
	/* 0x2f8b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2f90:
	/* 0x2f90: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f95:
	/* 0x2f95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f9a:
	/* 0x2f9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9c:
	/* 0x2f9c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fa1:
	/* 0x2fa1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2fa4:
	/* 0x2fa4: je     3c35 <trace_security_mmap_file+0x3c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15413ULL;
	}
x86_l_2faa:
	/* 0x2faa: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2faf:
	/* 0x2faf: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2fb2:
	/* 0x2fb2: je     3c35 <trace_security_mmap_file+0x3c35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15413ULL;
	}
x86_l_2fb8:
	/* 0x2fb8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fbc:
	/* 0x2fbc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc1:
	/* 0x2fc1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2fc6:
	/* 0x2fc6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fcb:
	/* 0x2fcb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2fd0:
	/* 0x2fd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd2:
	/* 0x2fd2: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2fd6:
	/* 0x2fd6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fd8:
	/* 0x2fd8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2fde:
	/* 0x2fde: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2fe0:
	/* 0x2fe0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fe2:
	/* 0x2fe2: jae    3ead <trace_security_mmap_file+0x3ead> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 16045ULL;
	}
x86_l_2fe8:
	/* 0x2fe8: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_2fea:
	/* 0x2fea: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2fec:
	/* 0x2fec: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ff1:
	/* 0x2ff1: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2ff4:
	/* 0x2ff4: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_2ff9:
	/* 0x2ff9: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_3000:
	/* 0x3000: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3005:
	/* 0x3005: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_3008:
	/* 0x3008: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_300e:
	/* 0x300e: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3011:
	/* 0x3011: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3019:
	/* 0x3019: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_301f:
	/* 0x301f: ja     30af <trace_security_mmap_file+0x30af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_30af;
	}
x86_l_3025:
	/* 0x3025: mov    BYTE PTR [r13+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_302e:
	/* 0x302e: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3036:
	/* 0x3036: mov    WORD PTR [r13+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_303e:
	/* 0x303e: cmp    rax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 27899ULL);
x86_l_3044:
	/* 0x3044: ja     30af <trace_security_mmap_file+0x30af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_30af;
	}
x86_l_3046:
	/* 0x3046: lea    rcx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_304a:
	/* 0x304a: add    rcx,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_3051:
	/* 0x3051: mov    edx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_3056:
	/* 0x3056: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_305b:
	/* 0x305b: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3063:
	/* 0x3063: lea    rdi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3067:
	/* 0x3067: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_306e:
	/* 0x306e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3073:
	/* 0x3073: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3076:
	/* 0x3076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3078:
	/* 0x3078: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_307a:
	/* 0x307a: jle    30af <trace_security_mmap_file+0x30af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_30af;
	}
x86_l_307c:
	/* 0x307c: movzx  ecx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3084:
	/* 0x3084: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_308b:
	/* 0x308b: ja     30af <trace_security_mmap_file+0x30af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_30af;
	}
x86_l_308d:
	/* 0x308d: mov    DWORD PTR [rcx+r13*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_3095:
	/* 0x3095: add    ax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_309d:
	/* 0x309d: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_30a0:
	/* 0x30a0: mov    WORD PTR [r13+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30a8:
	/* 0x30a8: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_30af:
	/* 0x30af: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30b7:
	/* 0x30b7: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_30be:
	/* 0x30be: ja     3110 <trace_security_mmap_file+0x3110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3110;
	}
x86_l_30c0:
	/* 0x30c0: mov    BYTE PTR [r13+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_30c9:
	/* 0x30c9: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_30cf:
	/* 0x30cf: ja     3110 <trace_security_mmap_file+0x3110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3110;
	}
x86_l_30d1:
	/* 0x30d1: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_30d9:
	/* 0x30d9: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_30dd:
	/* 0x30dd: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_30e1:
	/* 0x30e1: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_30e8:
	/* 0x30e8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_30ed:
	/* 0x30ed: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30f2:
	/* 0x30f2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30f7:
	/* 0x30f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f9:
	/* 0x30f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30fc:
	/* 0x30fc: js     3110 <trace_security_mmap_file+0x3110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3110;
	}
x86_l_30fe:
	/* 0x30fe: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3101:
	/* 0x3101: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3109:
	/* 0x3109: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3110:
	/* 0x3110: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3118:
	/* 0x3118: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_311f:
	/* 0x311f: ja     316d <trace_security_mmap_file+0x316d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_316d;
	}
x86_l_3121:
	/* 0x3121: mov    BYTE PTR [r13+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_312a:
	/* 0x312a: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_3130:
	/* 0x3130: ja     316d <trace_security_mmap_file+0x316d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_316d;
	}
x86_l_3132:
	/* 0x3132: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3136:
	/* 0x3136: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_313d:
	/* 0x313d: lea    rdx,[rsp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_3145:
	/* 0x3145: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_314a:
	/* 0x314a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_314f:
	/* 0x314f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3154:
	/* 0x3154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3156:
	/* 0x3156: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3159:
	/* 0x3159: js     316d <trace_security_mmap_file+0x316d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_316d;
	}
x86_l_315b:
	/* 0x315b: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_315e:
	/* 0x315e: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3166:
	/* 0x3166: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_316d:
	/* 0x316d: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3175:
	/* 0x3175: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_317c:
	/* 0x317c: ja     31ca <trace_security_mmap_file+0x31ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31ca;
	}
x86_l_317e:
	/* 0x317e: mov    BYTE PTR [r13+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_3187:
	/* 0x3187: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_318d:
	/* 0x318d: ja     31ca <trace_security_mmap_file+0x31ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_31ca;
	}
x86_l_318f:
	/* 0x318f: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3193:
	/* 0x3193: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_319a:
	/* 0x319a: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_31a2:
	/* 0x31a2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31a7:
	/* 0x31a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31ac:
	/* 0x31ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31b1:
	/* 0x31b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31b3:
	/* 0x31b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31b6:
	/* 0x31b6: js     31ca <trace_security_mmap_file+0x31ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31ca;
	}
x86_l_31b8:
	/* 0x31b8: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_31bb:
	/* 0x31bb: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_31c3:
	/* 0x31c3: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_31ca:
	/* 0x31ca: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31d2:
	/* 0x31d2: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_31d9:
	/* 0x31d9: ja     3227 <trace_security_mmap_file+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3227;
	}
x86_l_31db:
	/* 0x31db: mov    BYTE PTR [r13+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_31e4:
	/* 0x31e4: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_31ea:
	/* 0x31ea: ja     3227 <trace_security_mmap_file+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3227;
	}
x86_l_31ec:
	/* 0x31ec: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_31f0:
	/* 0x31f0: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_31f7:
	/* 0x31f7: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_31ff:
	/* 0x31ff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3204:
	/* 0x3204: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3209:
	/* 0x3209: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_320e:
	/* 0x320e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3210:
	/* 0x3210: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3213:
	/* 0x3213: js     3227 <trace_security_mmap_file+0x3227> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3227;
	}
x86_l_3215:
	/* 0x3215: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3218:
	/* 0x3218: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3220:
	/* 0x3220: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3227:
	/* 0x3227: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_322f:
	/* 0x322f: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3236:
	/* 0x3236: ja     3284 <trace_security_mmap_file+0x3284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3284;
	}
x86_l_3238:
	/* 0x3238: mov    BYTE PTR [r13+rbx*1+0x89],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519557ULL);
x86_l_3241:
	/* 0x3241: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_3247:
	/* 0x3247: ja     3284 <trace_security_mmap_file+0x3284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3284;
	}
x86_l_3249:
	/* 0x3249: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_324d:
	/* 0x324d: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_3254:
	/* 0x3254: lea    rdx,[rsp+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_325c:
	/* 0x325c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3261:
	/* 0x3261: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3266:
	/* 0x3266: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_326b:
	/* 0x326b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_326d:
	/* 0x326d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3270:
	/* 0x3270: js     3284 <trace_security_mmap_file+0x3284> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3284;
	}
x86_l_3272:
	/* 0x3272: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_3275:
	/* 0x3275: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_327d:
	/* 0x327d: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_3284:
	/* 0x3284: movzx  ebx,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_328c:
	/* 0x328c: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_3293:
	/* 0x3293: ja     32e1 <trace_security_mmap_file+0x32e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32e1;
	}
x86_l_3295:
	/* 0x3295: mov    BYTE PTR [r13+rbx*1+0x89],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519558ULL);
x86_l_329e:
	/* 0x329e: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_32a4:
	/* 0x32a4: ja     32e1 <trace_security_mmap_file+0x32e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32e1;
	}
x86_l_32a6:
	/* 0x32a6: lea    rdi,[rbx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_32aa:
	/* 0x32aa: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_32b1:
	/* 0x32b1: lea    rdx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_32b9:
	/* 0x32b9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_32be:
	/* 0x32be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32c3:
	/* 0x32c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32c8:
	/* 0x32c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32ca:
	/* 0x32ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32cd:
	/* 0x32cd: js     32e1 <trace_security_mmap_file+0x32e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_32e1;
	}
x86_l_32cf:
	/* 0x32cf: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_32d2:
	/* 0x32d2: mov    WORD PTR [r13+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_32da:
	/* 0x32da: inc    BYTE PTR [r13+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_32e1:
	/* 0x32e1: mov    rbx,QWORD PTR [r13+0x7de8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_32e8:
	/* 0x32e8: mov    r15,QWORD PTR [r13+0x7df8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_32ef:
	/* 0x32ef: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_32f2:
	/* 0x32f2: je     3412 <trace_security_mmap_file+0x3412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3412;
	}
x86_l_32f8:
	/* 0x32f8: or     rbx,QWORD PTR [r13+0x7df0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 32240ULL);
x86_l_32ff:
	/* 0x32ff: mov    r14d,DWORD PTR [r13+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3303:
	/* 0x3303: movzx  r12d,WORD PTR [r13+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_3308:
	/* 0x3308: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3310:
	/* 0x3310: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_bufs)));
x86_l_3317:
	/* 0x3317: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_331c:
	/* 0x331c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3321:
	/* 0x3321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3323:
	/* 0x3323: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3326:
	/* 0x3326: je     3492 <trace_security_mmap_file+0x3492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3492;
	}
x86_l_332c:
	/* 0x332c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_332f:
	/* 0x332f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3331:
	/* 0x3331: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_3336:
	/* 0x3336: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3339:
	/* 0x3339: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_333b:
	/* 0x333b: call   3340 <trace_security_mmap_file+0x3340> */
	X86_SIM_L_EXEC_CALL_MEMSET(256ULL);
x86_l_3340:
	/* 0x3340: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3345:
	/* 0x3345: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3348:
	/* 0x3348: cmp    rax,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31995ULL);
x86_l_334e:
	/* 0x334e: ja     3494 <trace_security_mmap_file+0x3494> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3494;
	}
x86_l_3354:
	/* 0x3354: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3359:
	/* 0x3359: mov    esi,DWORD PTR [rax+rcx*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 138ULL);
x86_l_3360:
	/* 0x3360: cmp    rsi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 256ULL);
x86_l_3367:
	/* 0x3367: ja     3492 <trace_security_mmap_file+0x3492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3492;
	}
x86_l_336d:
	/* 0x336d: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3370:
	/* 0x3370: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3373:
	/* 0x3373: lea    ecx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3376:
	/* 0x3376: cmp    ecx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_337c:
	/* 0x337c: ja     3492 <trace_security_mmap_file+0x3492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3492;
	}
x86_l_3382:
	/* 0x3382: mov    DWORD PTR [rsp+0x78],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3387:
	/* 0x3387: mov    r14,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_338c:
	/* 0x338c: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3390:
	/* 0x3390: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3397:
	/* 0x3397: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_339c:
	/* 0x339c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_339f:
	/* 0x339f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a1:
	/* 0x33a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33a3:
	/* 0x33a3: je     3af4 <trace_security_mmap_file+0x3af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15092ULL;
	}
x86_l_33a9:
	/* 0x33a9: mov    rbp,QWORD PTR [r14+0x7e10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_33b0:
	/* 0x33b0: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33b6:
	/* 0x33b6: mov    WORD PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_33bd:
	/* 0x33bd: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_33c1:
	/* 0x33c1: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_33c5:
	/* 0x33c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_exact_version)));
x86_l_33cc:
	/* 0x33cc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33d1:
	/* 0x33d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d6:
	/* 0x33d6: add    r14,0x7de8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 32232ULL);
x86_l_33dd:
	/* 0x33dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33df:
	/* 0x33df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33e2:
	/* 0x33e2: je     3ab2 <trace_security_mmap_file+0x3ab2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15026ULL;
	}
x86_l_33e8:
	/* 0x33e8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_33eb:
	/* 0x33eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33f0:
	/* 0x33f0: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_33f3:
	/* 0x33f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33f5:
	/* 0x33f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33f8:
	/* 0x33f8: je     3ab2 <trace_security_mmap_file+0x3ab2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15026ULL;
	}
x86_l_33fe:
	/* 0x33fe: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3401:
	/* 0x3401: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3405:
	/* 0x3405: not    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3408:
	/* 0x3408: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_340d:
	/* 0x340d: jmp    3ac0 <trace_security_mmap_file+0x3ac0> */
	return 15040ULL;
x86_l_3412:
	/* 0x3412: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_3415:
	/* 0x3415: jne    3425 <trace_security_mmap_file+0x3425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3425;
	}
x86_l_3417:
	/* 0x3417: cmp    QWORD PTR [r13+0x7df0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138469745623040ULL);
x86_l_341f:
	/* 0x341f: je     3a9c <trace_security_mmap_file+0x3a9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15004ULL;
	}
x86_l_3425:
	/* 0x3425: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_3428:
	/* 0x3428: add    r13,0x7df0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32240ULL);
x86_l_342f:
	/* 0x342f: mov    r15,QWORD PTR [rax+0x7df0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_3436:
	/* 0x3436: or     r15,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3439:
	/* 0x3439: mov    ecx,DWORD PTR [rax+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_343c:
	/* 0x343c: mov    DWORD PTR [rsp+0x78],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3440:
	/* 0x3440: movzx  r12d,WORD PTR [rax+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_3445:
	/* 0x3445: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3447:
	/* 0x3447: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_344a:
	/* 0x344a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_344c:
	/* 0x344c: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_344f:
	/* 0x344f: je     3b2f <trace_security_mmap_file+0x3b2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15151ULL;
	}
x86_l_3455:
	/* 0x3455: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_345d:
	/* 0x345d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3465:
	/* 0x3465: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_346c:
	/* 0x346c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3471:
	/* 0x3471: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3476:
	/* 0x3476: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3478:
	/* 0x3478: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_347b:
	/* 0x347b: je     3492 <trace_security_mmap_file+0x3492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3492;
	}
x86_l_347d:
	/* 0x347d: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3482:
	/* 0x3482: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3485:
	/* 0x3485: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_348c:
	/* 0x348c: jbe    39cd <trace_security_mmap_file+0x39cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 14797ULL;
	}
x86_l_3492:
	/* 0x3492: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3494:
	/* 0x3494: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3499:
	/* 0x3499: and    QWORD PTR [r13+0x80],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 128ULL);
x86_l_34a0:
	/* 0x34a0: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_34a5:
	/* 0x34a5: je     3de7 <trace_security_mmap_file+0x3de7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15847ULL;
	}
x86_l_34ab:
	/* 0x34ab: mov    r14,QWORD PTR [r13+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_34b2:
	/* 0x34b2: lea    r12,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34b6:
	/* 0x34b6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34bb:
	/* 0x34bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34c0:
	/* 0x34c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34c5:
	/* 0x34c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34ca:
	/* 0x34ca: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_34cd:
	/* 0x34cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34cf:
	/* 0x34cf: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34d4:
	/* 0x34d4: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34d9:
	/* 0x34d9: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34dd:
	/* 0x34dd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34e2:
	/* 0x34e2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_34e7:
	/* 0x34e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_34ec:
	/* 0x34ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34f1:
	/* 0x34f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f3:
	/* 0x34f3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34f8:
	/* 0x34f8: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_34fc:
	/* 0x34fc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3501:
	/* 0x3501: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3506:
	/* 0x3506: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_350b:
	/* 0x350b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3510:
	/* 0x3510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3512:
	/* 0x3512: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3517:
	/* 0x3517: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_351b:
	/* 0x351b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3520:
	/* 0x3520: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3525:
	/* 0x3525: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_352a:
	/* 0x352a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_352f:
	/* 0x352f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3531:
	/* 0x3531: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3535:
	/* 0x3535: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3539:
	/* 0x3539: lea    r15,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_353d:
	/* 0x353d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3542:
	/* 0x3542: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3547:
	/* 0x3547: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_354c:
	/* 0x354c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3551:
	/* 0x3551: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3554:
	/* 0x3554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3556:
	/* 0x3556: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_355b:
	/* 0x355b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3560:
	/* 0x3560: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3565:
	/* 0x3565: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_356a:
	/* 0x356a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_356f:
	/* 0x356f: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3572:
	/* 0x3572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3574:
	/* 0x3574: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3578:
	/* 0x3578: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_357c:
	/* 0x357c: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3580:
	/* 0x3580: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3584:
	/* 0x3584: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3589:
	/* 0x3589: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_358e:
	/* 0x358e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3593:
	/* 0x3593: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3598:
	/* 0x3598: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_359a:
	/* 0x359a: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_359e:
	/* 0x359e: mov    DWORD PTR [r13+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_35a2:
	/* 0x35a2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35a7:
	/* 0x35a7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35ac:
	/* 0x35ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35b1:
	/* 0x35b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35b6:
	/* 0x35b6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_35b9:
	/* 0x35b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35bb:
	/* 0x35bb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35c0:
	/* 0x35c0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35c4:
	/* 0x35c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35c9:
	/* 0x35c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35ce:
	/* 0x35ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35d3:
	/* 0x35d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35d8:
	/* 0x35d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35da:
	/* 0x35da: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35df:
	/* 0x35df: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35e4:
	/* 0x35e4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_35e9:
	/* 0x35e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_35ee:
	/* 0x35ee: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_35f3:
	/* 0x35f3: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_35f6:
	/* 0x35f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f8:
	/* 0x35f8: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35fc:
	/* 0x35fc: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3600:
	/* 0x3600: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3604:
	/* 0x3604: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3608:
	/* 0x3608: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_360d:
	/* 0x360d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3612:
	/* 0x3612: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3617:
	/* 0x3617: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_361c:
	/* 0x361c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361e:
	/* 0x361e: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3622:
	/* 0x3622: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3626:
	/* 0x3626: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_362b:
	/* 0x362b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3630:
	/* 0x3630: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3635:
	/* 0x3635: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_363a:
	/* 0x363a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_363d:
	/* 0x363d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363f:
	/* 0x363f: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3644:
	/* 0x3644: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3649:
	/* 0x3649: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_364e:
	/* 0x364e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3653:
	/* 0x3653: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3658:
	/* 0x3658: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_365b:
	/* 0x365b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_365d:
	/* 0x365d: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3661:
	/* 0x3661: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_3665:
	/* 0x3665: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3669:
	/* 0x3669: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_366d:
	/* 0x366d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3672:
	/* 0x3672: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3677:
	/* 0x3677: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_367c:
	/* 0x367c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3681:
	/* 0x3681: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3683:
	/* 0x3683: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3688:
	/* 0x3688: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_368c:
	/* 0x368c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 13969ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13969ULL: goto x86_l_3691;
	case 13974ULL: goto x86_l_3696;
	case 13979ULL: goto x86_l_369b;
	case 13984ULL: goto x86_l_36a0;
	case 13986ULL: goto x86_l_36a2;
	case 13991ULL: goto x86_l_36a7;
	case 13995ULL: goto x86_l_36ab;
	case 14000ULL: goto x86_l_36b0;
	case 14005ULL: goto x86_l_36b5;
	case 14010ULL: goto x86_l_36ba;
	case 14015ULL: goto x86_l_36bf;
	case 14018ULL: goto x86_l_36c2;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14035ULL: goto x86_l_36d3;
	case 14040ULL: goto x86_l_36d8;
	case 14045ULL: goto x86_l_36dd;
	case 14048ULL: goto x86_l_36e0;
	case 14050ULL: goto x86_l_36e2;
	case 14054ULL: goto x86_l_36e6;
	case 14058ULL: goto x86_l_36ea;
	case 14062ULL: goto x86_l_36ee;
	case 14066ULL: goto x86_l_36f2;
	case 14071ULL: goto x86_l_36f7;
	case 14076ULL: goto x86_l_36fc;
	case 14081ULL: goto x86_l_3701;
	case 14086ULL: goto x86_l_3706;
	case 14088ULL: goto x86_l_3708;
	case 14093ULL: goto x86_l_370d;
	case 14097ULL: goto x86_l_3711;
	case 14102ULL: goto x86_l_3716;
	case 14107ULL: goto x86_l_371b;
	case 14112ULL: goto x86_l_3720;
	case 14117ULL: goto x86_l_3725;
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14126ULL: goto x86_l_372e;
	case 14131ULL: goto x86_l_3733;
	case 14136ULL: goto x86_l_3738;
	case 14141ULL: goto x86_l_373d;
	case 14146ULL: goto x86_l_3742;
	case 14149ULL: goto x86_l_3745;
	case 14151ULL: goto x86_l_3747;
	case 14156ULL: goto x86_l_374c;
	case 14161ULL: goto x86_l_3751;
	case 14166ULL: goto x86_l_3756;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14179ULL: goto x86_l_3763;
	case 14181ULL: goto x86_l_3765;
	case 14185ULL: goto x86_l_3769;
	case 14189ULL: goto x86_l_376d;
	case 14193ULL: goto x86_l_3771;
	case 14197ULL: goto x86_l_3775;
	case 14202ULL: goto x86_l_377a;
	case 14207ULL: goto x86_l_377f;
	case 14212ULL: goto x86_l_3784;
	case 14217ULL: goto x86_l_3789;
	case 14219ULL: goto x86_l_378b;
	case 14223ULL: goto x86_l_378f;
	case 14227ULL: goto x86_l_3793;
	case 14231ULL: goto x86_l_3797;
	case 14238ULL: goto x86_l_379e;
	case 14243ULL: goto x86_l_37a3;
	case 14248ULL: goto x86_l_37a8;
	case 14253ULL: goto x86_l_37ad;
	case 14258ULL: goto x86_l_37b2;
	case 14261ULL: goto x86_l_37b5;
	case 14263ULL: goto x86_l_37b7;
	case 14268ULL: goto x86_l_37bc;
	case 14272ULL: goto x86_l_37c0;
	case 14277ULL: goto x86_l_37c5;
	case 14282ULL: goto x86_l_37ca;
	case 14287ULL: goto x86_l_37cf;
	case 14292ULL: goto x86_l_37d4;
	case 14294ULL: goto x86_l_37d6;
	case 14299ULL: goto x86_l_37db;
	case 14304ULL: goto x86_l_37e0;
	case 14309ULL: goto x86_l_37e5;
	case 14314ULL: goto x86_l_37ea;
	case 14319ULL: goto x86_l_37ef;
	case 14324ULL: goto x86_l_37f4;
	case 14326ULL: goto x86_l_37f6;
	case 14330ULL: goto x86_l_37fa;
	case 14334ULL: goto x86_l_37fe;
	case 14339ULL: goto x86_l_3803;
	case 14341ULL: goto x86_l_3805;
	case 14345ULL: goto x86_l_3809;
	case 14349ULL: goto x86_l_380d;
	case 14354ULL: goto x86_l_3812;
	case 14359ULL: goto x86_l_3817;
	case 14364ULL: goto x86_l_381c;
	case 14369ULL: goto x86_l_3821;
	case 14371ULL: goto x86_l_3823;
	case 14376ULL: goto x86_l_3828;
	case 14380ULL: goto x86_l_382c;
	case 14385ULL: goto x86_l_3831;
	case 14389ULL: goto x86_l_3835;
	case 14394ULL: goto x86_l_383a;
	case 14399ULL: goto x86_l_383f;
	case 14404ULL: goto x86_l_3844;
	case 14409ULL: goto x86_l_3849;
	case 14411ULL: goto x86_l_384b;
	case 14416ULL: goto x86_l_3850;
	case 14420ULL: goto x86_l_3854;
	case 14424ULL: goto x86_l_3858;
	case 14429ULL: goto x86_l_385d;
	case 14434ULL: goto x86_l_3862;
	case 14439ULL: goto x86_l_3867;
	case 14444ULL: goto x86_l_386c;
	case 14447ULL: goto x86_l_386f;
	case 14449ULL: goto x86_l_3871;
	case 14454ULL: goto x86_l_3876;
	case 14458ULL: goto x86_l_387a;
	case 14463ULL: goto x86_l_387f;
	case 14468ULL: goto x86_l_3884;
	case 14473ULL: goto x86_l_3889;
	case 14478ULL: goto x86_l_388e;
	case 14481ULL: goto x86_l_3891;
	case 14483ULL: goto x86_l_3893;
	case 14488ULL: goto x86_l_3898;
	case 14490ULL: goto x86_l_389a;
	case 14495ULL: goto x86_l_389f;
	case 14503ULL: goto x86_l_38a7;
	case 14507ULL: goto x86_l_38ab;
	case 14515ULL: goto x86_l_38b3;
	case 14520ULL: goto x86_l_38b8;
	case 14525ULL: goto x86_l_38bd;
	case 14530ULL: goto x86_l_38c2;
	case 14532ULL: goto x86_l_38c4;
	case 14537ULL: goto x86_l_38c9;
	case 14542ULL: goto x86_l_38ce;
	case 14547ULL: goto x86_l_38d3;
	case 14552ULL: goto x86_l_38d8;
	case 14555ULL: goto x86_l_38db;
	case 14557ULL: goto x86_l_38dd;
	case 14562ULL: goto x86_l_38e2;
	case 14567ULL: goto x86_l_38e7;
	case 14572ULL: goto x86_l_38ec;
	case 14577ULL: goto x86_l_38f1;
	case 14582ULL: goto x86_l_38f6;
	case 14584ULL: goto x86_l_38f8;
	case 14589ULL: goto x86_l_38fd;
	case 14594ULL: goto x86_l_3902;
	case 14599ULL: goto x86_l_3907;
	case 14604ULL: goto x86_l_390c;
	case 14607ULL: goto x86_l_390f;
	case 14612ULL: goto x86_l_3914;
	case 14614ULL: goto x86_l_3916;
	case 14617ULL: goto x86_l_3919;
	case 14621ULL: goto x86_l_391d;
	case 14626ULL: goto x86_l_3922;
	case 14631ULL: goto x86_l_3927;
	case 14636ULL: goto x86_l_392c;
	case 14639ULL: goto x86_l_392f;
	case 14641ULL: goto x86_l_3931;
	case 14646ULL: goto x86_l_3936;
	case 14651ULL: goto x86_l_393b;
	case 14659ULL: goto x86_l_3943;
	case 14667ULL: goto x86_l_394b;
	case 14672ULL: goto x86_l_3950;
	case 14674ULL: goto x86_l_3952;
	case 14682ULL: goto x86_l_395a;
	case 14686ULL: goto x86_l_395e;
	case 14694ULL: goto x86_l_3966;
	case 14696ULL: goto x86_l_3968;
	case 14703ULL: goto x86_l_396f;
	case 14708ULL: goto x86_l_3974;
	case 14713ULL: goto x86_l_3979;
	case 14718ULL: goto x86_l_397e;
	case 14721ULL: goto x86_l_3981;
	case 14723ULL: goto x86_l_3983;
	case 14725ULL: goto x86_l_3985;
	case 14727ULL: goto x86_l_3987;
	case 14731ULL: goto x86_l_398b;
	case 14739ULL: goto x86_l_3993;
	case 14744ULL: goto x86_l_3998;
	case 14749ULL: goto x86_l_399d;
	case 14752ULL: goto x86_l_39a0;
	case 14758ULL: goto x86_l_39a6;
	case 14762ULL: goto x86_l_39aa;
	case 14769ULL: goto x86_l_39b1;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14784ULL: goto x86_l_39c0;
	case 14787ULL: goto x86_l_39c3;
	case 14790ULL: goto x86_l_39c6;
	case 14792ULL: goto x86_l_39c8;
	case 14797ULL: goto x86_l_39cd;
	case 14800ULL: goto x86_l_39d0;
	case 14805ULL: goto x86_l_39d5;
	case 14812ULL: goto x86_l_39dc;
	case 14818ULL: goto x86_l_39e2;
	case 14823ULL: goto x86_l_39e7;
	case 14826ULL: goto x86_l_39ea;
	case 14829ULL: goto x86_l_39ed;
	case 14832ULL: goto x86_l_39f0;
	case 14838ULL: goto x86_l_39f6;
	case 14844ULL: goto x86_l_39fc;
	case 14852ULL: goto x86_l_3a04;
	case 14856ULL: goto x86_l_3a08;
	case 14859ULL: goto x86_l_3a0b;
	case 14863ULL: goto x86_l_3a0f;
	case 14870ULL: goto x86_l_3a16;
	case 14875ULL: goto x86_l_3a1b;
	case 14877ULL: goto x86_l_3a1d;
	case 14879ULL: goto x86_l_3a1f;
	case 14885ULL: goto x86_l_3a25;
	case 14893ULL: goto x86_l_3a2d;
	case 14896ULL: goto x86_l_3a30;
	case 14904ULL: goto x86_l_3a38;
	case 14906ULL: goto x86_l_3a3a;
	case 14913ULL: goto x86_l_3a41;
	case 14919ULL: goto x86_l_3a47;
	case 14926ULL: goto x86_l_3a4e;
	case 14930ULL: goto x86_l_3a52;
	case 14934ULL: goto x86_l_3a56;
	case 14941ULL: goto x86_l_3a5d;
	case 14946ULL: goto x86_l_3a62;
	case 14951ULL: goto x86_l_3a67;
	case 14953ULL: goto x86_l_3a69;
	case 14960ULL: goto x86_l_3a70;
	case 14963ULL: goto x86_l_3a73;
	case 14969ULL: goto x86_l_3a79;
	case 14972ULL: goto x86_l_3a7c;
	case 14977ULL: goto x86_l_3a81;
	case 14985ULL: goto x86_l_3a89;
	case 14987ULL: goto x86_l_3a8b;
	case 14990ULL: goto x86_l_3a8e;
	case 14992ULL: goto x86_l_3a90;
	case 14995ULL: goto x86_l_3a93;
	case 14999ULL: goto x86_l_3a97;
	case 15002ULL: goto x86_l_3a9a;
	case 15004ULL: goto x86_l_3a9c;
	case 15011ULL: goto x86_l_3aa3;
	case 15016ULL: goto x86_l_3aa8;
	case 15018ULL: goto x86_l_3aaa;
	case 15021ULL: goto x86_l_3aad;
	case 15026ULL: goto x86_l_3ab2;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15040ULL: goto x86_l_3ac0;
	case 15043ULL: goto x86_l_3ac3;
	case 15050ULL: goto x86_l_3aca;
	case 15053ULL: goto x86_l_3acd;
	case 15056ULL: goto x86_l_3ad0;
	case 15059ULL: goto x86_l_3ad3;
	case 15064ULL: goto x86_l_3ad8;
	case 15069ULL: goto x86_l_3add;
	case 15072ULL: goto x86_l_3ae0;
	case 15075ULL: goto x86_l_3ae3;
	case 15078ULL: goto x86_l_3ae6;
	case 15081ULL: goto x86_l_3ae9;
	case 15084ULL: goto x86_l_3aec;
	case 15090ULL: goto x86_l_3af2;
	case 15092ULL: goto x86_l_3af4;
	case 15094ULL: goto x86_l_3af6;
	case 15097ULL: goto x86_l_3af9;
	case 15102ULL: goto x86_l_3afe;
	case 15104ULL: goto x86_l_3b00;
	case 15112ULL: goto x86_l_3b08;
	case 15115ULL: goto x86_l_3b0b;
	case 15118ULL: goto x86_l_3b0e;
	case 15123ULL: goto x86_l_3b13;
	case 15126ULL: goto x86_l_3b16;
	case 15131ULL: goto x86_l_3b1b;
	case 15134ULL: goto x86_l_3b1e;
	case 15137ULL: goto x86_l_3b21;
	case 15145ULL: goto x86_l_3b29;
	case 15148ULL: goto x86_l_3b2c;
	case 15151ULL: goto x86_l_3b2f;
	case 15156ULL: goto x86_l_3b34;
	case 15158ULL: goto x86_l_3b36;
	case 15166ULL: goto x86_l_3b3e;
	case 15174ULL: goto x86_l_3b46;
	case 15181ULL: goto x86_l_3b4d;
	case 15186ULL: goto x86_l_3b52;
	case 15191ULL: goto x86_l_3b57;
	case 15193ULL: goto x86_l_3b59;
	case 15196ULL: goto x86_l_3b5c;
	case 15201ULL: goto x86_l_3b61;
	case 15203ULL: goto x86_l_3b63;
	case 15208ULL: goto x86_l_3b68;
	case 15211ULL: goto x86_l_3b6b;
	case 15218ULL: goto x86_l_3b72;
	case 15220ULL: goto x86_l_3b74;
	case 15222ULL: goto x86_l_3b76;
	case 15227ULL: goto x86_l_3b7b;
	case 15232ULL: goto x86_l_3b80;
	case 15237ULL: goto x86_l_3b85;
	case 15240ULL: goto x86_l_3b88;
	case 15243ULL: goto x86_l_3b8b;
	case 15246ULL: goto x86_l_3b8e;
	case 15253ULL: goto x86_l_3b95;
	case 15256ULL: goto x86_l_3b98;
	case 15261ULL: goto x86_l_3b9d;
	case 15269ULL: goto x86_l_3ba5;
	case 15275ULL: goto x86_l_3bab;
	case 15277ULL: goto x86_l_3bad;
	case 15279ULL: goto x86_l_3baf;
	case 15285ULL: goto x86_l_3bb5;
	case 15288ULL: goto x86_l_3bb8;
	case 15293ULL: goto x86_l_3bbd;
	case 15299ULL: goto x86_l_3bc3;
	case 15301ULL: goto x86_l_3bc5;
	case 15303ULL: goto x86_l_3bc7;
	case 15306ULL: goto x86_l_3bca;
	case 15308ULL: goto x86_l_3bcc;
	case 15310ULL: goto x86_l_3bce;
	case 15316ULL: goto x86_l_3bd4;
	case 15319ULL: goto x86_l_3bd7;
	case 15322ULL: goto x86_l_3bda;
	case 15328ULL: goto x86_l_3be0;
	case 15334ULL: goto x86_l_3be6;
	case 15336ULL: goto x86_l_3be8;
	case 15342ULL: goto x86_l_3bee;
	case 15348ULL: goto x86_l_3bf4;
	case 15351ULL: goto x86_l_3bf7;
	case 15354ULL: goto x86_l_3bfa;
	case 15357ULL: goto x86_l_3bfd;
	case 15359ULL: goto x86_l_3bff;
	case 15361ULL: goto x86_l_3c01;
	case 15363ULL: goto x86_l_3c03;
	case 15365ULL: goto x86_l_3c05;
	case 15367ULL: goto x86_l_3c07;
	case 15373ULL: goto x86_l_3c0d;
	case 15379ULL: goto x86_l_3c13;
	case 15381ULL: goto x86_l_3c15;
	case 15390ULL: goto x86_l_3c1e;
	case 15395ULL: goto x86_l_3c23;
	case 15398ULL: goto x86_l_3c26;
	case 15400ULL: goto x86_l_3c28;
	case 15403ULL: goto x86_l_3c2b;
	case 15405ULL: goto x86_l_3c2d;
	case 15408ULL: goto x86_l_3c30;
	case 15413ULL: goto x86_l_3c35;
	case 15416ULL: goto x86_l_3c38;
	case 15422ULL: goto x86_l_3c3e;
	case 15426ULL: goto x86_l_3c42;
	case 15431ULL: goto x86_l_3c47;
	case 15437ULL: goto x86_l_3c4d;
	case 15441ULL: goto x86_l_3c51;
	case 15446ULL: goto x86_l_3c56;
	case 15451ULL: goto x86_l_3c5b;
	case 15456ULL: goto x86_l_3c60;
	case 15460ULL: goto x86_l_3c64;
	case 15464ULL: goto x86_l_3c68;
	case 15469ULL: goto x86_l_3c6d;
	case 15471ULL: goto x86_l_3c6f;
	case 15475ULL: goto x86_l_3c73;
	case 15478ULL: goto x86_l_3c76;
	case 15483ULL: goto x86_l_3c7b;
	case 15488ULL: goto x86_l_3c80;
	case 15492ULL: goto x86_l_3c84;
	case 15497ULL: goto x86_l_3c89;
	case 15499ULL: goto x86_l_3c8b;
	case 15503ULL: goto x86_l_3c8f;
	case 15508ULL: goto x86_l_3c94;
	case 15513ULL: goto x86_l_3c99;
	case 15518ULL: goto x86_l_3c9e;
	case 15522ULL: goto x86_l_3ca2;
	case 15527ULL: goto x86_l_3ca7;
	case 15529ULL: goto x86_l_3ca9;
	case 15533ULL: goto x86_l_3cad;
	case 15537ULL: goto x86_l_3cb1;
	case 15542ULL: goto x86_l_3cb6;
	case 15547ULL: goto x86_l_3cbb;
	case 15553ULL: goto x86_l_3cc1;
	case 15556ULL: goto x86_l_3cc4;
	case 15559ULL: goto x86_l_3cc7;
	case 15561ULL: goto x86_l_3cc9;
	case 15566ULL: goto x86_l_3cce;
	case 15568ULL: goto x86_l_3cd0;
	case 15571ULL: goto x86_l_3cd3;
	case 15577ULL: goto x86_l_3cd9;
	case 15580ULL: goto x86_l_3cdc;
	case 15586ULL: goto x86_l_3ce2;
	case 15591ULL: goto x86_l_3ce7;
	case 15593ULL: goto x86_l_3ce9;
	case 15598ULL: goto x86_l_3cee;
	case 15603ULL: goto x86_l_3cf3;
	case 15608ULL: goto x86_l_3cf8;
	case 15613ULL: goto x86_l_3cfd;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3691:
	/* 0x3691: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3696:
	/* 0x3696: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_369b:
	/* 0x369b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36a0:
	/* 0x36a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a2:
	/* 0x36a2: mov    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36a7:
	/* 0x36a7: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ab:
	/* 0x36ab: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36b0:
	/* 0x36b0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36b5:
	/* 0x36b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36ba:
	/* 0x36ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_36bf:
	/* 0x36bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_36c2:
	/* 0x36c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c4:
	/* 0x36c4: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36c9:
	/* 0x36c9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36ce:
	/* 0x36ce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_36d3:
	/* 0x36d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_36d8:
	/* 0x36d8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_36dd:
	/* 0x36dd: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_36e0:
	/* 0x36e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36e2:
	/* 0x36e2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36e6:
	/* 0x36e6: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_36ea:
	/* 0x36ea: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_36ee:
	/* 0x36ee: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_36f2:
	/* 0x36f2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36f7:
	/* 0x36f7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_36fc:
	/* 0x36fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3701:
	/* 0x3701: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3706:
	/* 0x3706: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3708:
	/* 0x3708: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_370d:
	/* 0x370d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_3711:
	/* 0x3711: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3716:
	/* 0x3716: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_371b:
	/* 0x371b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3720:
	/* 0x3720: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3725:
	/* 0x3725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3727:
	/* 0x3727: cmp    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_372c:
	/* 0x372c: jne    3793 <trace_security_mmap_file+0x3793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3793;
	}
x86_l_372e:
	/* 0x372e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3733:
	/* 0x3733: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3738:
	/* 0x3738: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_373d:
	/* 0x373d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3742:
	/* 0x3742: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3745:
	/* 0x3745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3747:
	/* 0x3747: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_374c:
	/* 0x374c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3751:
	/* 0x3751: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3756:
	/* 0x3756: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_375b:
	/* 0x375b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3760:
	/* 0x3760: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_3763:
	/* 0x3763: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3765:
	/* 0x3765: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3769:
	/* 0x3769: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_376d:
	/* 0x376d: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3771:
	/* 0x3771: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3775:
	/* 0x3775: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_377a:
	/* 0x377a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_377f:
	/* 0x377f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3784:
	/* 0x3784: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3789:
	/* 0x3789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_378b:
	/* 0x378b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_378f:
	/* 0x378f: mov    DWORD PTR [r13+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3793:
	/* 0x3793: mov    DWORD PTR [r13+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3797:
	/* 0x3797: lea    r12,[r14+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_379e:
	/* 0x379e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37a3:
	/* 0x37a3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37a8:
	/* 0x37a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ad:
	/* 0x37ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37b2:
	/* 0x37b2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_37b5:
	/* 0x37b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37b7:
	/* 0x37b7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37bc:
	/* 0x37bc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_37c0:
	/* 0x37c0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37c5:
	/* 0x37c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_37ca:
	/* 0x37ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37cf:
	/* 0x37cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_37d4:
	/* 0x37d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d6:
	/* 0x37d6: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37db:
	/* 0x37db: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37e0:
	/* 0x37e0: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_37e5:
	/* 0x37e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_37ea:
	/* 0x37ea: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37ef:
	/* 0x37ef: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37f4:
	/* 0x37f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37f6:
	/* 0x37f6: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37fa:
	/* 0x37fa: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_37fe:
	/* 0x37fe: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_3803:
	/* 0x3803: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3805:
	/* 0x3805: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3809:
	/* 0x3809: lea    rdx,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_380d:
	/* 0x380d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3812:
	/* 0x3812: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3817:
	/* 0x3817: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_381c:
	/* 0x381c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3821:
	/* 0x3821: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3823:
	/* 0x3823: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3828:
	/* 0x3828: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_382c:
	/* 0x382c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3831:
	/* 0x3831: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3835:
	/* 0x3835: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x384b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3850:
	/* 0x3850: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3854:
	/* 0x3854: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_3858:
	/* 0x3858: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_385d:
	/* 0x385d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3862:
	/* 0x3862: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3867:
	/* 0x3867: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_386c:
	/* 0x386c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_386f:
	/* 0x386f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3871:
	/* 0x3871: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3876:
	/* 0x3876: mov    QWORD PTR [r13+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_387a:
	/* 0x387a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_387f:
	/* 0x387f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3884:
	/* 0x3884: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3889:
	/* 0x3889: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_388e:
	/* 0x388e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3891:
	/* 0x3891: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3893:
	/* 0x3893: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_3898:
	/* 0x3898: je     389f <trace_security_mmap_file+0x389f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389f;
	}
x86_l_389a:
	/* 0x389a: or     BYTE PTR [r13+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_389f:
	/* 0x389f: mov    QWORD PTR [r13+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_38a7:
	/* 0x38a7: lea    rdi,[r13+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_38ab:
	/* 0x38ab: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_38b3:
	/* 0x38b3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_38b8:
	/* 0x38b8: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_38bd:
	/* 0x38bd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_38c2:
	/* 0x38c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38c4:
	/* 0x38c4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38c9:
	/* 0x38c9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_38ce:
	/* 0x38ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38d3:
	/* 0x38d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38d8:
	/* 0x38d8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_38db:
	/* 0x38db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38dd:
	/* 0x38dd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38e2:
	/* 0x38e2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38e7:
	/* 0x38e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_38ec:
	/* 0x38ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_38f1:
	/* 0x38f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38f6:
	/* 0x38f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38f8:
	/* 0x38f8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38fd:
	/* 0x38fd: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3902:
	/* 0x3902: mov    ecx,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65ULL);
x86_l_3907:
	/* 0x3907: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_390c:
	/* 0x390c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_390f:
	/* 0x390f: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_3914:
	/* 0x3914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3916:
	/* 0x3916: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_3919:
	/* 0x3919: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_391d:
	/* 0x391d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3922:
	/* 0x3922: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3927:
	/* 0x3927: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_392c:
	/* 0x392c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_392f:
	/* 0x392f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3931:
	/* 0x3931: mov    ecx,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 104ULL);
x86_l_3936:
	/* 0x3936: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_393b:
	/* 0x393b: mov    rdi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3943:
	/* 0x3943: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_394b:
	/* 0x394b: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_3950:
	/* 0x3950: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3952:
	/* 0x3952: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_395a:
	/* 0x395a: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_395e:
	/* 0x395e: mov    rbx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3966:
	/* 0x3966: je     398b <trace_security_mmap_file+0x398b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_398b;
	}
x86_l_3968:
	/* 0x3968: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_396f:
	/* 0x396f: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_3974:
	/* 0x3974: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_3979:
	/* 0x3979: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_397e:
	/* 0x397e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3981:
	/* 0x3981: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3983:
	/* 0x3983: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3985:
	/* 0x3985: js     398b <trace_security_mmap_file+0x398b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_398b;
	}
x86_l_3987:
	/* 0x3987: mov    DWORD PTR [r13+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_398b:
	/* 0x398b: movzx  eax,WORD PTR [r13+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3993:
	/* 0x3993: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_3998:
	/* 0x3998: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_399d:
	/* 0x399d: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_39a0:
	/* 0x39a0: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_39a6:
	/* 0x39a6: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_39aa:
	/* 0x39aa: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_39b1:
	/* 0x39b1: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_39b6:
	/* 0x39b6: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_39bb:
	/* 0x39bb: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_39c0:
	/* 0x39c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_39c3:
	/* 0x39c3: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_39c6:
	/* 0x39c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c8:
	/* 0x39c8: jmp    3de7 <trace_security_mmap_file+0x3de7> */
	return 15847ULL;
x86_l_39cd:
	/* 0x39cd: lea    edx,[rcx+0x5] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_39d0:
	/* 0x39d0: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39d5:
	/* 0x39d5: mov    ecx,DWORD PTR [rcx+rbx*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 138ULL);
x86_l_39dc:
	/* 0x39dc: cmp    ecx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_39e2:
	/* 0x39e2: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_39e7:
	/* 0x39e7: cmovb  esi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_39ea:
	/* 0x39ea: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_39ed:
	/* 0x39ed: lea    edx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_39f0:
	/* 0x39f0: cmp    edx,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 32000ULL);
x86_l_39f6:
	/* 0x39f6: ja     3aa8 <trace_security_mmap_file+0x3aa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3aa8;
	}
x86_l_39fc:
	/* 0x39fc: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3a04:
	/* 0x3a04: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3a08:
	/* 0x3a08: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_3a0b:
	/* 0x3a0b: lea    rdx,[rbx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a0f:
	/* 0x3a0f: add    rdx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a16:
	/* 0x3a16: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3a1b:
	/* 0x3a1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a1d:
	/* 0x3a1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a1f:
	/* 0x3a1f: je     3aa8 <trace_security_mmap_file+0x3aa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3aa8;
	}
x86_l_3a25:
	/* 0x3a25: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3a2d:
	/* 0x3a2d: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_3a30:
	/* 0x3a30: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3a38:
	/* 0x3a38: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a3a:
	/* 0x3a3a: mov    rbx,QWORD PTR [rbx+0x7e00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_3a41:
	/* 0x3a41: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a47:
	/* 0x3a47: mov    WORD PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_3a4e:
	/* 0x3a4e: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3a52:
	/* 0x3a52: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3a56:
	/* 0x3a56: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_prefix_version)));
x86_l_3a5d:
	/* 0x3a5d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a62:
	/* 0x3a62: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a67:
	/* 0x3a67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a69:
	/* 0x3a69: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3a70:
	/* 0x3a70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a73:
	/* 0x3a73: je     3afe <trace_security_mmap_file+0x3afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3afe;
	}
x86_l_3a79:
	/* 0x3a79: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3a7c:
	/* 0x3a7c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a81:
	/* 0x3a81: mov    rsi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3a89:
	/* 0x3a89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a8b:
	/* 0x3a8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a8e:
	/* 0x3a8e: je     3afe <trace_security_mmap_file+0x3afe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3afe;
	}
x86_l_3a90:
	/* 0x3a90: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a93:
	/* 0x3a93: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a97:
	/* 0x3a97: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3a9a:
	/* 0x3a9a: jmp    3b00 <trace_security_mmap_file+0x3b00> */
	goto x86_l_3b00;
x86_l_3a9c:
	/* 0x3a9c: mov    rbp,QWORD PTR [r13+0x7ef0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32496ULL);
x86_l_3aa3:
	/* 0x3aa3: jmp    3499 <trace_security_mmap_file+0x3499> */
	return 13465ULL;
x86_l_3aa8:
	/* 0x3aa8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3aaa:
	/* 0x3aaa: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_3aad:
	/* 0x3aad: jmp    3499 <trace_security_mmap_file+0x3499> */
	return 13465ULL;
x86_l_3ab2:
	/* 0x3ab2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ab4:
	/* 0x3ab4: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ab9:
	/* 0x3ab9: mov    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3ac0:
	/* 0x3ac0: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3ac3:
	/* 0x3ac3: lea    r13,[rax+0x7df0] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_3aca:
	/* 0x3aca: or     rbx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_3acd:
	/* 0x3acd: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_3ad0:
	/* 0x3ad0: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3ad3:
	/* 0x3ad3: andn   r14,rbp,rcx */
	X86_SIM_L_EXEC_ANDN(X86_R14, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_3ad8:
	/* 0x3ad8: andn   rsi,rdx,rbp */
	X86_SIM_L_EXEC_ANDN(X86_RSI, X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3add:
	/* 0x3add: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_3ae0:
	/* 0x3ae0: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_3ae3:
	/* 0x3ae3: mov    rbx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ae6:
	/* 0x3ae6: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_3ae9:
	/* 0x3ae9: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_3aec:
	/* 0x3aec: jne    3455 <trace_security_mmap_file+0x3455> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13397ULL;
	}
x86_l_3af2:
	/* 0x3af2: jmp    3b2f <trace_security_mmap_file+0x3b2f> */
	goto x86_l_3b2f;
x86_l_3af4:
	/* 0x3af4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3af6:
	/* 0x3af6: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_3af9:
	/* 0x3af9: jmp    3499 <trace_security_mmap_file+0x3499> */
	return 13465ULL;
x86_l_3afe:
	/* 0x3afe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b00:
	/* 0x3b00: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b08:
	/* 0x3b08: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_3b0b:
	/* 0x3b0b: or     rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b0e:
	/* 0x3b0e: andn   rax,rbx,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_3b13:
	/* 0x3b13: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b16:
	/* 0x3b16: andn   rax,rbp,rbx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_3b1b:
	/* 0x3b1b: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b1e:
	/* 0x3b1e: and    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_AND);
x86_l_3b21:
	/* 0x3b21: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3b29:
	/* 0x3b29: or     rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b2c:
	/* 0x3b2c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3b2f:
	/* 0x3b2f: cmp    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b34:
	/* 0x3b34: je     3b7b <trace_security_mmap_file+0x3b7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b7b;
	}
x86_l_3b36:
	/* 0x3b36: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b3e:
	/* 0x3b3e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3b46:
	/* 0x3b46: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_lpm_bufs)));
x86_l_3b4d:
	/* 0x3b4d: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3b52:
	/* 0x3b52: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b57:
	/* 0x3b57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b59:
	/* 0x3b59: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b5c:
	/* 0x3b5c: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b61:
	/* 0x3b61: je     3b74 <trace_security_mmap_file+0x3b74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b74;
	}
x86_l_3b63:
	/* 0x3b63: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3b68:
	/* 0x3b68: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b6b:
	/* 0x3b6b: cmp    rcx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 31995ULL);
x86_l_3b72:
	/* 0x3b72: jbe    3b9d <trace_security_mmap_file+0x3b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3b9d;
	}
x86_l_3b74:
	/* 0x3b74: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b76:
	/* 0x3b76: jmp    3499 <trace_security_mmap_file+0x3499> */
	return 13465ULL;
x86_l_3b7b:
	/* 0x3b7b: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b80:
	/* 0x3b80: andn   rax,rsi,rbp */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_3b85:
	/* 0x3b85: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3b88:
	/* 0x3b88: or     r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b8b:
	/* 0x3b8b: or     r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b8e:
	/* 0x3b8e: and    r15,QWORD PTR [r13+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_3b95:
	/* 0x3b95: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_3b98:
	/* 0x3b98: jmp    3499 <trace_security_mmap_file+0x3499> */
	return 13465ULL;
x86_l_3b9d:
	/* 0x3b9d: mov    edx,DWORD PTR [rcx+r13*1+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 138ULL);
x86_l_3ba5:
	/* 0x3ba5: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_3bab:
	/* 0x3bab: jbe    3bc7 <trace_security_mmap_file+0x3bc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3bc7;
	}
x86_l_3bad:
	/* 0x3bad: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3baf:
	/* 0x3baf: add    ecx,0xffffff05 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967045ULL);
x86_l_3bb5:
	/* 0x3bb5: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3bb8:
	/* 0x3bb8: mov    edx,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 255ULL);
x86_l_3bbd:
	/* 0x3bbd: cmp    ecx,0x7c00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31744ULL);
x86_l_3bc3:
	/* 0x3bc3: jbe    3bfa <trace_security_mmap_file+0x3bfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3bfa;
	}
x86_l_3bc5:
	/* 0x3bc5: jmp    3b74 <trace_security_mmap_file+0x3b74> */
	goto x86_l_3b74;
x86_l_3bc7:
	/* 0x3bc7: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3bca:
	/* 0x3bca: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3bcc:
	/* 0x3bcc: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3bce:
	/* 0x3bce: je     3499 <trace_security_mmap_file+0x3499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13465ULL;
	}
x86_l_3bd4:
	/* 0x3bd4: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3bd7:
	/* 0x3bd7: add    esi,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3bda:
	/* 0x3bda: cmp    esi,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 32000ULL);
x86_l_3be0:
	/* 0x3be0: ja     3499 <trace_security_mmap_file+0x3499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13465ULL;
	}
x86_l_3be6:
	/* 0x3be6: dec    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_3be8:
	/* 0x3be8: and    edx,0xff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 255ULL);
x86_l_3bee:
	/* 0x3bee: je     3dfd <trace_security_mmap_file+0x3dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15869ULL;
	}
x86_l_3bf4:
	/* 0x3bf4: add    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_3bf7:
	/* 0x3bf7: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_3bfa:
	/* 0x3bfa: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_3bfd:
	/* 0x3bfd: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_3bff:
	/* 0x3bff: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3c01:
	/* 0x3c01: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_3c03:
	/* 0x3c03: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c05:
	/* 0x3c05: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c07:
	/* 0x3c07: cmp    ecx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31999ULL);
x86_l_3c0d:
	/* 0x3c0d: ja     3499 <trace_security_mmap_file+0x3499> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13465ULL;
	}
x86_l_3c13:
	/* 0x3c13: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_3c15:
	/* 0x3c15: movzx  edi,BYTE PTR [r13+rdi*1+0x89] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDI, 0, X86_WIDTH_8), 137ULL);
x86_l_3c1e:
	/* 0x3c1e: mov    BYTE PTR [rax+rdx*1+0x4],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RDX, 0), 4ULL);
x86_l_3c23:
	/* 0x3c23: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_3c26:
	/* 0x3c26: dec    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_3c28:
	/* 0x3c28: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3c2b:
	/* 0x3c2b: jne    3c07 <trace_security_mmap_file+0x3c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c07;
	}
x86_l_3c2d:
	/* 0x3c2d: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_3c30:
	/* 0x3c30: jmp    3e02 <trace_security_mmap_file+0x3e02> */
	return 15874ULL;
x86_l_3c35:
	/* 0x3c35: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3c38:
	/* 0x3c38: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_3c3e:
	/* 0x3c3e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c42:
	/* 0x3c42: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3c47:
	/* 0x3c47: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_3c4d:
	/* 0x3c4d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c51:
	/* 0x3c51: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c56:
	/* 0x3c56: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c5b:
	/* 0x3c5b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c60:
	/* 0x3c60: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c64:
	/* 0x3c64: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3c68:
	/* 0x3c68: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c6d:
	/* 0x3c6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c6f:
	/* 0x3c6f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c73:
	/* 0x3c73: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3c76:
	/* 0x3c76: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c7b:
	/* 0x3c7b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c80:
	/* 0x3c80: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c84:
	/* 0x3c84: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c89:
	/* 0x3c89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c8b:
	/* 0x3c8b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c8f:
	/* 0x3c8f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c94:
	/* 0x3c94: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c99:
	/* 0x3c99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3c9e:
	/* 0x3c9e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ca2:
	/* 0x3ca2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ca7:
	/* 0x3ca7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca9:
	/* 0x3ca9: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cad:
	/* 0x3cad: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3cb1:
	/* 0x3cb1: jmp    3ee5 <trace_security_mmap_file+0x3ee5> */
	return 16101ULL;
x86_l_3cb6:
	/* 0x3cb6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3cbb:
	/* 0x3cbb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3cc1:
	/* 0x3cc1: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_3cc4:
	/* 0x3cc4: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3cc7:
	/* 0x3cc7: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3cc9:
	/* 0x3cc9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3cce:
	/* 0x3cce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd0:
	/* 0x3cd0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3cd3:
	/* 0x3cd3: jl     196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6508ULL;
	}
x86_l_3cd9:
	/* 0x3cd9: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3cdc:
	/* 0x3cdc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3ce2:
	/* 0x3ce2: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3ce7:
	/* 0x3ce7: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ce9:
	/* 0x3ce9: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3cee:
	/* 0x3cee: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3cf3:
	/* 0x3cf3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3cf8:
	/* 0x3cf8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3cfd:
	/* 0x3cfd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 15618ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15618ULL: goto x86_l_3d02;
	case 15621ULL: goto x86_l_3d05;
	case 15623ULL: goto x86_l_3d07;
	case 15628ULL: goto x86_l_3d0c;
	case 15633ULL: goto x86_l_3d11;
	case 15637ULL: goto x86_l_3d15;
	case 15642ULL: goto x86_l_3d1a;
	case 15647ULL: goto x86_l_3d1f;
	case 15652ULL: goto x86_l_3d24;
	case 15657ULL: goto x86_l_3d29;
	case 15659ULL: goto x86_l_3d2b;
	case 15664ULL: goto x86_l_3d30;
	case 15667ULL: goto x86_l_3d33;
	case 15673ULL: goto x86_l_3d39;
	case 15678ULL: goto x86_l_3d3e;
	case 15681ULL: goto x86_l_3d41;
	case 15687ULL: goto x86_l_3d47;
	case 15691ULL: goto x86_l_3d4b;
	case 15696ULL: goto x86_l_3d50;
	case 15701ULL: goto x86_l_3d55;
	case 15706ULL: goto x86_l_3d5a;
	case 15711ULL: goto x86_l_3d5f;
	case 15713ULL: goto x86_l_3d61;
	case 15717ULL: goto x86_l_3d65;
	case 15719ULL: goto x86_l_3d67;
	case 15725ULL: goto x86_l_3d6d;
	case 15727ULL: goto x86_l_3d6f;
	case 15729ULL: goto x86_l_3d71;
	case 15735ULL: goto x86_l_3d77;
	case 15740ULL: goto x86_l_3d7c;
	case 15746ULL: goto x86_l_3d82;
	case 15749ULL: goto x86_l_3d85;
	case 15751ULL: goto x86_l_3d87;
	case 15756ULL: goto x86_l_3d8c;
	case 15758ULL: goto x86_l_3d8e;
	case 15761ULL: goto x86_l_3d91;
	case 15767ULL: goto x86_l_3d97;
	case 15770ULL: goto x86_l_3d9a;
	case 15776ULL: goto x86_l_3da0;
	case 15781ULL: goto x86_l_3da5;
	case 15783ULL: goto x86_l_3da7;
	case 15788ULL: goto x86_l_3dac;
	case 15793ULL: goto x86_l_3db1;
	case 15800ULL: goto x86_l_3db8;
	case 15803ULL: goto x86_l_3dbb;
	case 15807ULL: goto x86_l_3dbf;
	case 15812ULL: goto x86_l_3dc4;
	case 15817ULL: goto x86_l_3dc9;
	case 15822ULL: goto x86_l_3dce;
	case 15824ULL: goto x86_l_3dd0;
	case 15827ULL: goto x86_l_3dd3;
	case 15829ULL: goto x86_l_3dd5;
	case 15835ULL: goto x86_l_3ddb;
	case 15840ULL: goto x86_l_3de0;
	case 15845ULL: goto x86_l_3de5;
	case 15847ULL: goto x86_l_3de7;
	case 15854ULL: goto x86_l_3dee;
	case 15855ULL: goto x86_l_3def;
	case 15857ULL: goto x86_l_3df1;
	case 15859ULL: goto x86_l_3df3;
	case 15861ULL: goto x86_l_3df5;
	case 15863ULL: goto x86_l_3df7;
	case 15864ULL: goto x86_l_3df8;
	case 15869ULL: goto x86_l_3dfd;
	case 15871ULL: goto x86_l_3dff;
	case 15874ULL: goto x86_l_3e02;
	case 15876ULL: goto x86_l_3e04;
	case 15881ULL: goto x86_l_3e09;
	case 15888ULL: goto x86_l_3e10;
	case 15891ULL: goto x86_l_3e13;
	case 15893ULL: goto x86_l_3e15;
	case 15898ULL: goto x86_l_3e1a;
	case 15905ULL: goto x86_l_3e21;
	case 15910ULL: goto x86_l_3e26;
	case 15916ULL: goto x86_l_3e2c;
	case 15923ULL: goto x86_l_3e33;
	case 15927ULL: goto x86_l_3e37;
	case 15931ULL: goto x86_l_3e3b;
	case 15938ULL: goto x86_l_3e42;
	case 15943ULL: goto x86_l_3e47;
	case 15948ULL: goto x86_l_3e4c;
	case 15950ULL: goto x86_l_3e4e;
	case 15957ULL: goto x86_l_3e55;
	case 15960ULL: goto x86_l_3e58;
	case 15962ULL: goto x86_l_3e5a;
	case 15965ULL: goto x86_l_3e5d;
	case 15970ULL: goto x86_l_3e62;
	case 15973ULL: goto x86_l_3e65;
	case 15975ULL: goto x86_l_3e67;
	case 15978ULL: goto x86_l_3e6a;
	case 15980ULL: goto x86_l_3e6c;
	case 15983ULL: goto x86_l_3e6f;
	case 15987ULL: goto x86_l_3e73;
	case 15990ULL: goto x86_l_3e76;
	case 15992ULL: goto x86_l_3e78;
	case 15994ULL: goto x86_l_3e7a;
	case 15999ULL: goto x86_l_3e7f;
	case 16007ULL: goto x86_l_3e87;
	case 16012ULL: goto x86_l_3e8c;
	case 16015ULL: goto x86_l_3e8f;
	case 16018ULL: goto x86_l_3e92;
	case 16023ULL: goto x86_l_3e97;
	case 16026ULL: goto x86_l_3e9a;
	case 16031ULL: goto x86_l_3e9f;
	case 16034ULL: goto x86_l_3ea2;
	case 16037ULL: goto x86_l_3ea5;
	case 16040ULL: goto x86_l_3ea8;
	case 16045ULL: goto x86_l_3ead;
	case 16050ULL: goto x86_l_3eb2;
	case 16056ULL: goto x86_l_3eb8;
	case 16059ULL: goto x86_l_3ebb;
	case 16062ULL: goto x86_l_3ebe;
	case 16064ULL: goto x86_l_3ec0;
	case 16069ULL: goto x86_l_3ec5;
	case 16071ULL: goto x86_l_3ec7;
	case 16074ULL: goto x86_l_3eca;
	case 16080ULL: goto x86_l_3ed0;
	case 16083ULL: goto x86_l_3ed3;
	case 16089ULL: goto x86_l_3ed9;
	case 16094ULL: goto x86_l_3ede;
	case 16096ULL: goto x86_l_3ee0;
	case 16101ULL: goto x86_l_3ee5;
	case 16106ULL: goto x86_l_3eea;
	case 16111ULL: goto x86_l_3eef;
	case 16116ULL: goto x86_l_3ef4;
	case 16121ULL: goto x86_l_3ef9;
	case 16124ULL: goto x86_l_3efc;
	case 16126ULL: goto x86_l_3efe;
	case 16131ULL: goto x86_l_3f03;
	case 16136ULL: goto x86_l_3f08;
	case 16140ULL: goto x86_l_3f0c;
	case 16145ULL: goto x86_l_3f11;
	case 16150ULL: goto x86_l_3f16;
	case 16155ULL: goto x86_l_3f1b;
	case 16160ULL: goto x86_l_3f20;
	case 16162ULL: goto x86_l_3f22;
	case 16167ULL: goto x86_l_3f27;
	case 16170ULL: goto x86_l_3f2a;
	case 16176ULL: goto x86_l_3f30;
	case 16181ULL: goto x86_l_3f35;
	case 16184ULL: goto x86_l_3f38;
	case 16190ULL: goto x86_l_3f3e;
	case 16194ULL: goto x86_l_3f42;
	case 16199ULL: goto x86_l_3f47;
	case 16204ULL: goto x86_l_3f4c;
	case 16209ULL: goto x86_l_3f51;
	case 16214ULL: goto x86_l_3f56;
	case 16216ULL: goto x86_l_3f58;
	case 16220ULL: goto x86_l_3f5c;
	case 16222ULL: goto x86_l_3f5e;
	case 16228ULL: goto x86_l_3f64;
	case 16230ULL: goto x86_l_3f66;
	case 16232ULL: goto x86_l_3f68;
	case 16238ULL: goto x86_l_3f6e;
	case 16243ULL: goto x86_l_3f73;
	case 16249ULL: goto x86_l_3f79;
	case 16252ULL: goto x86_l_3f7c;
	case 16254ULL: goto x86_l_3f7e;
	case 16259ULL: goto x86_l_3f83;
	case 16261ULL: goto x86_l_3f85;
	case 16264ULL: goto x86_l_3f88;
	case 16270ULL: goto x86_l_3f8e;
	case 16273ULL: goto x86_l_3f91;
	case 16279ULL: goto x86_l_3f97;
	case 16284ULL: goto x86_l_3f9c;
	case 16286ULL: goto x86_l_3f9e;
	case 16291ULL: goto x86_l_3fa3;
	case 16296ULL: goto x86_l_3fa8;
	case 16299ULL: goto x86_l_3fab;
	case 16305ULL: goto x86_l_3fb1;
	case 16309ULL: goto x86_l_3fb5;
	case 16314ULL: goto x86_l_3fba;
	case 16320ULL: goto x86_l_3fc0;
	case 16324ULL: goto x86_l_3fc4;
	case 16329ULL: goto x86_l_3fc9;
	case 16334ULL: goto x86_l_3fce;
	case 16339ULL: goto x86_l_3fd3;
	case 16343ULL: goto x86_l_3fd7;
	case 16347ULL: goto x86_l_3fdb;
	case 16352ULL: goto x86_l_3fe0;
	case 16354ULL: goto x86_l_3fe2;
	case 16358ULL: goto x86_l_3fe6;
	case 16361ULL: goto x86_l_3fe9;
	case 16366ULL: goto x86_l_3fee;
	case 16371ULL: goto x86_l_3ff3;
	case 16375ULL: goto x86_l_3ff7;
	case 16380ULL: goto x86_l_3ffc;
	case 16382ULL: goto x86_l_3ffe;
	case 16386ULL: goto x86_l_4002;
	case 16391ULL: goto x86_l_4007;
	case 16396ULL: goto x86_l_400c;
	case 16401ULL: goto x86_l_4011;
	case 16405ULL: goto x86_l_4015;
	case 16410ULL: goto x86_l_401a;
	case 16412ULL: goto x86_l_401c;
	case 16416ULL: goto x86_l_4020;
	case 16420ULL: goto x86_l_4024;
	case 16425ULL: goto x86_l_4029;
	case 16430ULL: goto x86_l_402e;
	case 16435ULL: goto x86_l_4033;
	case 16440ULL: goto x86_l_4038;
	case 16443ULL: goto x86_l_403b;
	case 16445ULL: goto x86_l_403d;
	case 16450ULL: goto x86_l_4042;
	case 16455ULL: goto x86_l_4047;
	case 16459ULL: goto x86_l_404b;
	case 16464ULL: goto x86_l_4050;
	case 16469ULL: goto x86_l_4055;
	case 16474ULL: goto x86_l_405a;
	case 16479ULL: goto x86_l_405f;
	case 16481ULL: goto x86_l_4061;
	case 16486ULL: goto x86_l_4066;
	case 16489ULL: goto x86_l_4069;
	case 16495ULL: goto x86_l_406f;
	case 16500ULL: goto x86_l_4074;
	case 16503ULL: goto x86_l_4077;
	case 16509ULL: goto x86_l_407d;
	case 16513ULL: goto x86_l_4081;
	case 16518ULL: goto x86_l_4086;
	case 16523ULL: goto x86_l_408b;
	case 16528ULL: goto x86_l_4090;
	case 16533ULL: goto x86_l_4095;
	case 16535ULL: goto x86_l_4097;
	case 16539ULL: goto x86_l_409b;
	case 16541ULL: goto x86_l_409d;
	case 16547ULL: goto x86_l_40a3;
	case 16549ULL: goto x86_l_40a5;
	case 16551ULL: goto x86_l_40a7;
	case 16557ULL: goto x86_l_40ad;
	case 16562ULL: goto x86_l_40b2;
	case 16567ULL: goto x86_l_40b7;
	case 16570ULL: goto x86_l_40ba;
	case 16576ULL: goto x86_l_40c0;
	case 16580ULL: goto x86_l_40c4;
	case 16585ULL: goto x86_l_40c9;
	case 16591ULL: goto x86_l_40cf;
	case 16595ULL: goto x86_l_40d3;
	case 16600ULL: goto x86_l_40d8;
	case 16605ULL: goto x86_l_40dd;
	case 16610ULL: goto x86_l_40e2;
	case 16614ULL: goto x86_l_40e6;
	case 16618ULL: goto x86_l_40ea;
	case 16623ULL: goto x86_l_40ef;
	case 16625ULL: goto x86_l_40f1;
	case 16629ULL: goto x86_l_40f5;
	case 16632ULL: goto x86_l_40f8;
	case 16637ULL: goto x86_l_40fd;
	case 16642ULL: goto x86_l_4102;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16653ULL: goto x86_l_410d;
	case 16657ULL: goto x86_l_4111;
	case 16662ULL: goto x86_l_4116;
	case 16667ULL: goto x86_l_411b;
	case 16672ULL: goto x86_l_4120;
	case 16676ULL: goto x86_l_4124;
	case 16681ULL: goto x86_l_4129;
	case 16683ULL: goto x86_l_412b;
	case 16687ULL: goto x86_l_412f;
	case 16691ULL: goto x86_l_4133;
	case 16696ULL: goto x86_l_4138;
	case 16701ULL: goto x86_l_413d;
	case 16706ULL: goto x86_l_4142;
	case 16711ULL: goto x86_l_4147;
	case 16714ULL: goto x86_l_414a;
	case 16716ULL: goto x86_l_414c;
	case 16721ULL: goto x86_l_4151;
	case 16726ULL: goto x86_l_4156;
	case 16730ULL: goto x86_l_415a;
	case 16735ULL: goto x86_l_415f;
	case 16740ULL: goto x86_l_4164;
	case 16745ULL: goto x86_l_4169;
	case 16750ULL: goto x86_l_416e;
	case 16752ULL: goto x86_l_4170;
	case 16757ULL: goto x86_l_4175;
	case 16760ULL: goto x86_l_4178;
	case 16766ULL: goto x86_l_417e;
	case 16771ULL: goto x86_l_4183;
	case 16774ULL: goto x86_l_4186;
	case 16780ULL: goto x86_l_418c;
	case 16784ULL: goto x86_l_4190;
	case 16789ULL: goto x86_l_4195;
	case 16794ULL: goto x86_l_419a;
	case 16799ULL: goto x86_l_419f;
	case 16804ULL: goto x86_l_41a4;
	case 16806ULL: goto x86_l_41a6;
	case 16810ULL: goto x86_l_41aa;
	case 16812ULL: goto x86_l_41ac;
	case 16818ULL: goto x86_l_41b2;
	case 16820ULL: goto x86_l_41b4;
	case 16822ULL: goto x86_l_41b6;
	case 16828ULL: goto x86_l_41bc;
	case 16833ULL: goto x86_l_41c1;
	case 16839ULL: goto x86_l_41c7;
	case 16842ULL: goto x86_l_41ca;
	case 16844ULL: goto x86_l_41cc;
	case 16849ULL: goto x86_l_41d1;
	case 16851ULL: goto x86_l_41d3;
	case 16854ULL: goto x86_l_41d6;
	case 16860ULL: goto x86_l_41dc;
	case 16863ULL: goto x86_l_41df;
	case 16869ULL: goto x86_l_41e5;
	case 16874ULL: goto x86_l_41ea;
	case 16876ULL: goto x86_l_41ec;
	case 16881ULL: goto x86_l_41f1;
	case 16886ULL: goto x86_l_41f6;
	case 16889ULL: goto x86_l_41f9;
	case 16895ULL: goto x86_l_41ff;
	case 16899ULL: goto x86_l_4203;
	case 16904ULL: goto x86_l_4208;
	case 16910ULL: goto x86_l_420e;
	case 16914ULL: goto x86_l_4212;
	case 16919ULL: goto x86_l_4217;
	case 16924ULL: goto x86_l_421c;
	case 16929ULL: goto x86_l_4221;
	case 16933ULL: goto x86_l_4225;
	case 16937ULL: goto x86_l_4229;
	case 16942ULL: goto x86_l_422e;
	case 16944ULL: goto x86_l_4230;
	case 16948ULL: goto x86_l_4234;
	case 16951ULL: goto x86_l_4237;
	case 16956ULL: goto x86_l_423c;
	case 16961ULL: goto x86_l_4241;
	case 16965ULL: goto x86_l_4245;
	case 16970ULL: goto x86_l_424a;
	case 16972ULL: goto x86_l_424c;
	case 16976ULL: goto x86_l_4250;
	case 16981ULL: goto x86_l_4255;
	case 16986ULL: goto x86_l_425a;
	case 16991ULL: goto x86_l_425f;
	case 16995ULL: goto x86_l_4263;
	case 17000ULL: goto x86_l_4268;
	case 17002ULL: goto x86_l_426a;
	case 17006ULL: goto x86_l_426e;
	case 17010ULL: goto x86_l_4272;
	case 17015ULL: goto x86_l_4277;
	case 17018ULL: goto x86_l_427a;
	case 17024ULL: goto x86_l_4280;
	case 17028ULL: goto x86_l_4284;
	case 17033ULL: goto x86_l_4289;
	case 17039ULL: goto x86_l_428f;
	case 17043ULL: goto x86_l_4293;
	case 17048ULL: goto x86_l_4298;
	case 17053ULL: goto x86_l_429d;
	case 17058ULL: goto x86_l_42a2;
	case 17062ULL: goto x86_l_42a6;
	case 17066ULL: goto x86_l_42aa;
	case 17071ULL: goto x86_l_42af;
	case 17073ULL: goto x86_l_42b1;
	case 17077ULL: goto x86_l_42b5;
	case 17080ULL: goto x86_l_42b8;
	case 17085ULL: goto x86_l_42bd;
	case 17090ULL: goto x86_l_42c2;
	case 17094ULL: goto x86_l_42c6;
	case 17099ULL: goto x86_l_42cb;
	case 17101ULL: goto x86_l_42cd;
	case 17105ULL: goto x86_l_42d1;
	case 17110ULL: goto x86_l_42d6;
	case 17115ULL: goto x86_l_42db;
	case 17120ULL: goto x86_l_42e0;
	case 17124ULL: goto x86_l_42e4;
	case 17129ULL: goto x86_l_42e9;
	case 17131ULL: goto x86_l_42eb;
	case 17135ULL: goto x86_l_42ef;
	case 17139ULL: goto x86_l_42f3;
	case 17144ULL: goto x86_l_42f8;
	case 17149ULL: goto x86_l_42fd;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17162ULL: goto x86_l_430a;
	case 17164ULL: goto x86_l_430c;
	case 17169ULL: goto x86_l_4311;
	case 17174ULL: goto x86_l_4316;
	case 17178ULL: goto x86_l_431a;
	case 17183ULL: goto x86_l_431f;
	case 17188ULL: goto x86_l_4324;
	case 17193ULL: goto x86_l_4329;
	case 17198ULL: goto x86_l_432e;
	case 17200ULL: goto x86_l_4330;
	case 17205ULL: goto x86_l_4335;
	case 17208ULL: goto x86_l_4338;
	case 17214ULL: goto x86_l_433e;
	case 17219ULL: goto x86_l_4343;
	case 17222ULL: goto x86_l_4346;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3d02:
	/* 0x3d02: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3d05:
	/* 0x3d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d07:
	/* 0x3d07: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d0c:
	/* 0x3d0c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d11:
	/* 0x3d11: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3d15:
	/* 0x3d15: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d1a:
	/* 0x3d1a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3d1f:
	/* 0x3d1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d24:
	/* 0x3d24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d29:
	/* 0x3d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d2b:
	/* 0x3d2b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d30:
	/* 0x3d30: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3d33:
	/* 0x3d33: je     3fa8 <trace_security_mmap_file+0x3fa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fa8;
	}
x86_l_3d39:
	/* 0x3d39: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d3e:
	/* 0x3d3e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3d41:
	/* 0x3d41: je     3fa8 <trace_security_mmap_file+0x3fa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fa8;
	}
x86_l_3d47:
	/* 0x3d47: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3d4b:
	/* 0x3d4b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d50:
	/* 0x3d50: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3d55:
	/* 0x3d55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3d5a:
	/* 0x3d5a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3d5f:
	/* 0x3d5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d61:
	/* 0x3d61: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3d65:
	/* 0x3d65: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3d67:
	/* 0x3d67: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3d6d:
	/* 0x3d6d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3d6f:
	/* 0x3d6f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3d71:
	/* 0x3d71: jb     2e4c <trace_security_mmap_file+0x2e4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11852ULL;
	}
x86_l_3d77:
	/* 0x3d77: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d7c:
	/* 0x3d7c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3d82:
	/* 0x3d82: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d85:
	/* 0x3d85: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3d87:
	/* 0x3d87: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3d8c:
	/* 0x3d8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d8e:
	/* 0x3d8e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d91:
	/* 0x3d91: jl     196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 6508ULL;
	}
x86_l_3d97:
	/* 0x3d97: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3d9a:
	/* 0x3d9a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3da0:
	/* 0x3da0: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3da5:
	/* 0x3da5: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3da7:
	/* 0x3da7: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dac:
	/* 0x3dac: jmp    4024 <trace_security_mmap_file+0x4024> */
	goto x86_l_4024;
x86_l_3db1:
	/* 0x3db1: lea    rdi,[r13+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_3db8:
	/* 0x3db8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3dbb:
	/* 0x3dbb: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3dbf:
	/* 0x3dbf: mov    ecx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 256ULL);
x86_l_3dc4:
	/* 0x3dc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3dc9:
	/* 0x3dc9: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_3dce:
	/* 0x3dce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dd0:
	/* 0x3dd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3dd3:
	/* 0x3dd3: jne    3de5 <trace_security_mmap_file+0x3de5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3de5;
	}
x86_l_3dd5:
	/* 0x3dd5: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3ddb:
	/* 0x3ddb: mov    WORD PTR [r13+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_3de0:
	/* 0x3de0: jmp    bc7 <trace_security_mmap_file+0xbc7> */
	return 3015ULL;
x86_l_3de5:
	/* 0x3de5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3de7:
	/* 0x3de7: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_3dee:
	/* 0x3dee: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3def:
	/* 0x3def: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3df1:
	/* 0x3df1: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3df3:
	/* 0x3df3: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3df5:
	/* 0x3df5: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3df7:
	/* 0x3df7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3df8:
	/* 0x3df8: jmp    6877 <trace_security_mmap_file+0x6877> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3dfd:
	/* 0x3dfd: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dff:
	/* 0x3dff: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_3e02:
	/* 0x3e02: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3e04:
	/* 0x3e04: mov    BYTE PTR [rax+rcx*1+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 17179869184ULL);
x86_l_3e09:
	/* 0x3e09: lea    ecx,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_3e10:
	/* 0x3e10: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3e13:
	/* 0x3e13: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e15:
	/* 0x3e15: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e1a:
	/* 0x3e1a: mov    rax,QWORD PTR [rax+0x7e08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_3e21:
	/* 0x3e21: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3e26:
	/* 0x3e26: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e2c:
	/* 0x3e2c: mov    WORD PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_3e33:
	/* 0x3e33: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3e37:
	/* 0x3e37: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3e3b:
	/* 0x3e3b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_filter_suffix_version)));
x86_l_3e42:
	/* 0x3e42: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e47:
	/* 0x3e47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e4c:
	/* 0x3e4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e4e:
	/* 0x3e4e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3e55:
	/* 0x3e55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e58:
	/* 0x3e58: je     3e78 <trace_security_mmap_file+0x3e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e78;
	}
x86_l_3e5a:
	/* 0x3e5a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3e5d:
	/* 0x3e5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e62:
	/* 0x3e62: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_3e65:
	/* 0x3e65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e67:
	/* 0x3e67: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e6a:
	/* 0x3e6a: je     3e78 <trace_security_mmap_file+0x3e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e78;
	}
x86_l_3e6c:
	/* 0x3e6c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e6f:
	/* 0x3e6f: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e73:
	/* 0x3e73: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_3e76:
	/* 0x3e76: jmp    3e7a <trace_security_mmap_file+0x3e7a> */
	goto x86_l_3e7a;
x86_l_3e78:
	/* 0x3e78: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e7a:
	/* 0x3e7a: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e7f:
	/* 0x3e7f: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3e87:
	/* 0x3e87: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3e8c:
	/* 0x3e8c: and    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_3e8f:
	/* 0x3e8f: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3e92:
	/* 0x3e92: andn   rax,rdx,rcx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_3e97:
	/* 0x3e97: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3e9a:
	/* 0x3e9a: andn   rax,r12,rdx */
	X86_SIM_L_EXEC_ANDN(X86_RAX, X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_3e9f:
	/* 0x3e9f: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3ea2:
	/* 0x3ea2: and    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_3ea5:
	/* 0x3ea5: or     rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_3ea8:
	/* 0x3ea8: jmp    3b80 <trace_security_mmap_file+0x3b80> */
	return 15232ULL;
x86_l_3ead:
	/* 0x3ead: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3eb2:
	/* 0x3eb2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3eb8:
	/* 0x3eb8: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_3ebb:
	/* 0x3ebb: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3ebe:
	/* 0x3ebe: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3ec0:
	/* 0x3ec0: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3ec5:
	/* 0x3ec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ec7:
	/* 0x3ec7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3eca:
	/* 0x3eca: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_3ed0:
	/* 0x3ed0: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3ed3:
	/* 0x3ed3: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3ed9:
	/* 0x3ed9: mov    BYTE PTR [r14+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3ede:
	/* 0x3ede: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3ee0:
	/* 0x3ee0: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ee5:
	/* 0x3ee5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3eea:
	/* 0x3eea: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3eef:
	/* 0x3eef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ef4:
	/* 0x3ef4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ef9:
	/* 0x3ef9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3efc:
	/* 0x3efc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3efe:
	/* 0x3efe: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f03:
	/* 0x3f03: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f08:
	/* 0x3f08: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f0c:
	/* 0x3f0c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f11:
	/* 0x3f11: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f16:
	/* 0x3f16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f1b:
	/* 0x3f1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f20:
	/* 0x3f20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f22:
	/* 0x3f22: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f27:
	/* 0x3f27: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3f2a:
	/* 0x3f2a: je     40b7 <trace_security_mmap_file+0x40b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b7;
	}
x86_l_3f30:
	/* 0x3f30: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f35:
	/* 0x3f35: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3f38:
	/* 0x3f38: je     40b7 <trace_security_mmap_file+0x40b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40b7;
	}
x86_l_3f3e:
	/* 0x3f3e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3f42:
	/* 0x3f42: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f47:
	/* 0x3f47: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3f4c:
	/* 0x3f4c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3f51:
	/* 0x3f51: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3f56:
	/* 0x3f56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f58:
	/* 0x3f58: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3f5c:
	/* 0x3f5c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3f5e:
	/* 0x3f5e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3f64:
	/* 0x3f64: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_3f66:
	/* 0x3f66: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f68:
	/* 0x3f68: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_3f6e:
	/* 0x3f6e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3f73:
	/* 0x3f73: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3f79:
	/* 0x3f79: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3f7c:
	/* 0x3f7c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_3f7e:
	/* 0x3f7e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3f83:
	/* 0x3f83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f85:
	/* 0x3f85: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3f88:
	/* 0x3f88: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_3f8e:
	/* 0x3f8e: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_3f91:
	/* 0x3f91: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3f97:
	/* 0x3f97: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3f9c:
	/* 0x3f9c: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3f9e:
	/* 0x3f9e: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fa3:
	/* 0x3fa3: jmp    4133 <trace_security_mmap_file+0x4133> */
	goto x86_l_4133;
x86_l_3fa8:
	/* 0x3fa8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_3fab:
	/* 0x3fab: jne    196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6508ULL;
	}
x86_l_3fb1:
	/* 0x3fb1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb5:
	/* 0x3fb5: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3fba:
	/* 0x3fba: je     196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6508ULL;
	}
x86_l_3fc0:
	/* 0x3fc0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fc4:
	/* 0x3fc4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fc9:
	/* 0x3fc9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fce:
	/* 0x3fce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3fd3:
	/* 0x3fd3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fd7:
	/* 0x3fd7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3fdb:
	/* 0x3fdb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fe0:
	/* 0x3fe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fe2:
	/* 0x3fe2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe6:
	/* 0x3fe6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_3fe9:
	/* 0x3fe9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3fee:
	/* 0x3fee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3ff3:
	/* 0x3ff3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ff7:
	/* 0x3ff7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3ffc:
	/* 0x3ffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ffe:
	/* 0x3ffe: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4002:
	/* 0x4002: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4007:
	/* 0x4007: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_400c:
	/* 0x400c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4011:
	/* 0x4011: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4015:
	/* 0x4015: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_401a:
	/* 0x401a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_401c:
	/* 0x401c: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4020:
	/* 0x4020: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4024:
	/* 0x4024: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4029:
	/* 0x4029: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_402e:
	/* 0x402e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4033:
	/* 0x4033: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4038:
	/* 0x4038: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_403b:
	/* 0x403b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_403d:
	/* 0x403d: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4042:
	/* 0x4042: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4047:
	/* 0x4047: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_404b:
	/* 0x404b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4050:
	/* 0x4050: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4055:
	/* 0x4055: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_405a:
	/* 0x405a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_405f:
	/* 0x405f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4061:
	/* 0x4061: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4066:
	/* 0x4066: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4069:
	/* 0x4069: je     41f6 <trace_security_mmap_file+0x41f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41f6;
	}
x86_l_406f:
	/* 0x406f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4074:
	/* 0x4074: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4077:
	/* 0x4077: je     41f6 <trace_security_mmap_file+0x41f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41f6;
	}
x86_l_407d:
	/* 0x407d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4081:
	/* 0x4081: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4086:
	/* 0x4086: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_408b:
	/* 0x408b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4090:
	/* 0x4090: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4095:
	/* 0x4095: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4097:
	/* 0x4097: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_409b:
	/* 0x409b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_409d:
	/* 0x409d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_40a3:
	/* 0x40a3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_40a5:
	/* 0x40a5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_40a7:
	/* 0x40a7: jae    43b6 <trace_security_mmap_file+0x43b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 17334ULL;
	}
x86_l_40ad:
	/* 0x40ad: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40b2:
	/* 0x40b2: jmp    2e4c <trace_security_mmap_file+0x2e4c> */
	return 11852ULL;
x86_l_40b7:
	/* 0x40b7: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_40ba:
	/* 0x40ba: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_40c0:
	/* 0x40c0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40c4:
	/* 0x40c4: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_40c9:
	/* 0x40c9: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_40cf:
	/* 0x40cf: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_40d3:
	/* 0x40d3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40d8:
	/* 0x40d8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40dd:
	/* 0x40dd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_40e2:
	/* 0x40e2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40e6:
	/* 0x40e6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_40ea:
	/* 0x40ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_40ef:
	/* 0x40ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40f1:
	/* 0x40f1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40f5:
	/* 0x40f5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_40f8:
	/* 0x40f8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_40fd:
	/* 0x40fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4102:
	/* 0x4102: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4106:
	/* 0x4106: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_410b:
	/* 0x410b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410d:
	/* 0x410d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4111:
	/* 0x4111: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4116:
	/* 0x4116: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_411b:
	/* 0x411b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4120:
	/* 0x4120: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4124:
	/* 0x4124: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4129:
	/* 0x4129: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_412b:
	/* 0x412b: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412f:
	/* 0x412f: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4133:
	/* 0x4133: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4138:
	/* 0x4138: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_413d:
	/* 0x413d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4142:
	/* 0x4142: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4147:
	/* 0x4147: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_414a:
	/* 0x414a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414c:
	/* 0x414c: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4151:
	/* 0x4151: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4156:
	/* 0x4156: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_415a:
	/* 0x415a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_415f:
	/* 0x415f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4164:
	/* 0x4164: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4169:
	/* 0x4169: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_416e:
	/* 0x416e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4170:
	/* 0x4170: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4175:
	/* 0x4175: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4178:
	/* 0x4178: je     4277 <trace_security_mmap_file+0x4277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4277;
	}
x86_l_417e:
	/* 0x417e: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4183:
	/* 0x4183: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4186:
	/* 0x4186: je     4277 <trace_security_mmap_file+0x4277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4277;
	}
x86_l_418c:
	/* 0x418c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4190:
	/* 0x4190: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4195:
	/* 0x4195: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_419a:
	/* 0x419a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_419f:
	/* 0x419f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_41a4:
	/* 0x41a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41a6:
	/* 0x41a6: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_41aa:
	/* 0x41aa: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_41ac:
	/* 0x41ac: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_41b2:
	/* 0x41b2: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_41b4:
	/* 0x41b4: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_41b6:
	/* 0x41b6: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_41bc:
	/* 0x41bc: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_41c1:
	/* 0x41c1: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_41c7:
	/* 0x41c7: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_41ca:
	/* 0x41ca: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_41cc:
	/* 0x41cc: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_41d1:
	/* 0x41d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41d3:
	/* 0x41d3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_41d6:
	/* 0x41d6: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_41dc:
	/* 0x41dc: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_41df:
	/* 0x41df: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_41e5:
	/* 0x41e5: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_41ea:
	/* 0x41ea: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_41ec:
	/* 0x41ec: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41f1:
	/* 0x41f1: jmp    42f3 <trace_security_mmap_file+0x42f3> */
	goto x86_l_42f3;
x86_l_41f6:
	/* 0x41f6: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_41f9:
	/* 0x41f9: jne    196c <trace_security_mmap_file+0x196c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6508ULL;
	}
x86_l_41ff:
	/* 0x41ff: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4203:
	/* 0x4203: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4208:
	/* 0x4208: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_420e:
	/* 0x420e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4212:
	/* 0x4212: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4217:
	/* 0x4217: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
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
	/* 0x4229: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_422e:
	/* 0x422e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4230:
	/* 0x4230: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4234:
	/* 0x4234: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4237:
	/* 0x4237: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_423c:
	/* 0x423c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4241:
	/* 0x4241: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4245:
	/* 0x4245: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_424a:
	/* 0x424a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_424c:
	/* 0x424c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4250:
	/* 0x4250: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4255:
	/* 0x4255: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_425a:
	/* 0x425a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_425f:
	/* 0x425f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4263:
	/* 0x4263: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4268:
	/* 0x4268: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_426a:
	/* 0x426a: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_426e:
	/* 0x426e: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4272:
	/* 0x4272: jmp    43eb <trace_security_mmap_file+0x43eb> */
	return 17387ULL;
x86_l_4277:
	/* 0x4277: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_427a:
	/* 0x427a: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_4280:
	/* 0x4280: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4284:
	/* 0x4284: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4289:
	/* 0x4289: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_428f:
	/* 0x428f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4293:
	/* 0x4293: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4298:
	/* 0x4298: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_429d:
	/* 0x429d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42a2:
	/* 0x42a2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42a6:
	/* 0x42a6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_42aa:
	/* 0x42aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42af:
	/* 0x42af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42b1:
	/* 0x42b1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42b5:
	/* 0x42b5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_42b8:
	/* 0x42b8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42bd:
	/* 0x42bd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42c2:
	/* 0x42c2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42c6:
	/* 0x42c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42cb:
	/* 0x42cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42cd:
	/* 0x42cd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42d1:
	/* 0x42d1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42d6:
	/* 0x42d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_42db:
	/* 0x42db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_42e0:
	/* 0x42e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e4:
	/* 0x42e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42e9:
	/* 0x42e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42eb:
	/* 0x42eb: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42ef:
	/* 0x42ef: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_42f3:
	/* 0x42f3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42f8:
	/* 0x42f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_42fd:
	/* 0x42fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4302:
	/* 0x4302: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4307:
	/* 0x4307: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_430a:
	/* 0x430a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_430c:
	/* 0x430c: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4311:
	/* 0x4311: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4316:
	/* 0x4316: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_431a:
	/* 0x431a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_431f:
	/* 0x431f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4324:
	/* 0x4324: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4329:
	/* 0x4329: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_432e:
	/* 0x432e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4330:
	/* 0x4330: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4335:
	/* 0x4335: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4338:
	/* 0x4338: je     44b5 <trace_security_mmap_file+0x44b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17589ULL;
	}
x86_l_433e:
	/* 0x433e: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4343:
	/* 0x4343: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4346:
	/* 0x4346: je     44b5 <trace_security_mmap_file+0x44b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17589ULL;
	}
	return 17228ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17228ULL: goto x86_l_434c;
	case 17232ULL: goto x86_l_4350;
	case 17237ULL: goto x86_l_4355;
	case 17242ULL: goto x86_l_435a;
	case 17247ULL: goto x86_l_435f;
	case 17252ULL: goto x86_l_4364;
	case 17254ULL: goto x86_l_4366;
	case 17258ULL: goto x86_l_436a;
	case 17260ULL: goto x86_l_436c;
	case 17266ULL: goto x86_l_4372;
	case 17268ULL: goto x86_l_4374;
	case 17270ULL: goto x86_l_4376;
	case 17276ULL: goto x86_l_437c;
	case 17281ULL: goto x86_l_4381;
	case 17287ULL: goto x86_l_4387;
	case 17290ULL: goto x86_l_438a;
	case 17292ULL: goto x86_l_438c;
	case 17297ULL: goto x86_l_4391;
	case 17299ULL: goto x86_l_4393;
	case 17302ULL: goto x86_l_4396;
	case 17308ULL: goto x86_l_439c;
	case 17311ULL: goto x86_l_439f;
	case 17317ULL: goto x86_l_43a5;
	case 17322ULL: goto x86_l_43aa;
	case 17324ULL: goto x86_l_43ac;
	case 17329ULL: goto x86_l_43b1;
	case 17334ULL: goto x86_l_43b6;
	case 17339ULL: goto x86_l_43bb;
	case 17345ULL: goto x86_l_43c1;
	case 17348ULL: goto x86_l_43c4;
	case 17350ULL: goto x86_l_43c6;
	case 17355ULL: goto x86_l_43cb;
	case 17357ULL: goto x86_l_43cd;
	case 17360ULL: goto x86_l_43d0;
	case 17366ULL: goto x86_l_43d6;
	case 17369ULL: goto x86_l_43d9;
	case 17375ULL: goto x86_l_43df;
	case 17380ULL: goto x86_l_43e4;
	case 17382ULL: goto x86_l_43e6;
	case 17387ULL: goto x86_l_43eb;
	case 17392ULL: goto x86_l_43f0;
	case 17397ULL: goto x86_l_43f5;
	case 17402ULL: goto x86_l_43fa;
	case 17407ULL: goto x86_l_43ff;
	case 17410ULL: goto x86_l_4402;
	case 17412ULL: goto x86_l_4404;
	case 17417ULL: goto x86_l_4409;
	case 17422ULL: goto x86_l_440e;
	case 17426ULL: goto x86_l_4412;
	case 17431ULL: goto x86_l_4417;
	case 17436ULL: goto x86_l_441c;
	case 17441ULL: goto x86_l_4421;
	case 17446ULL: goto x86_l_4426;
	case 17448ULL: goto x86_l_4428;
	case 17453ULL: goto x86_l_442d;
	case 17456ULL: goto x86_l_4430;
	case 17458ULL: goto x86_l_4432;
	case 17463ULL: goto x86_l_4437;
	case 17466ULL: goto x86_l_443a;
	case 17468ULL: goto x86_l_443c;
	case 17472ULL: goto x86_l_4440;
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17487ULL: goto x86_l_444f;
	case 17492ULL: goto x86_l_4454;
	case 17494ULL: goto x86_l_4456;
	case 17498ULL: goto x86_l_445a;
	case 17500ULL: goto x86_l_445c;
	case 17506ULL: goto x86_l_4462;
	case 17508ULL: goto x86_l_4464;
	case 17510ULL: goto x86_l_4466;
	case 17516ULL: goto x86_l_446c;
	case 17521ULL: goto x86_l_4471;
	case 17527ULL: goto x86_l_4477;
	case 17530ULL: goto x86_l_447a;
	case 17532ULL: goto x86_l_447c;
	case 17537ULL: goto x86_l_4481;
	case 17539ULL: goto x86_l_4483;
	case 17542ULL: goto x86_l_4486;
	case 17544ULL: goto x86_l_4488;
	case 17547ULL: goto x86_l_448b;
	case 17553ULL: goto x86_l_4491;
	case 17558ULL: goto x86_l_4496;
	case 17560ULL: goto x86_l_4498;
	case 17565ULL: goto x86_l_449d;
	case 17570ULL: goto x86_l_44a2;
	case 17573ULL: goto x86_l_44a5;
	case 17579ULL: goto x86_l_44ab;
	case 17584ULL: goto x86_l_44b0;
	case 17589ULL: goto x86_l_44b5;
	case 17592ULL: goto x86_l_44b8;
	case 17598ULL: goto x86_l_44be;
	case 17602ULL: goto x86_l_44c2;
	case 17607ULL: goto x86_l_44c7;
	case 17613ULL: goto x86_l_44cd;
	case 17617ULL: goto x86_l_44d1;
	case 17622ULL: goto x86_l_44d6;
	case 17627ULL: goto x86_l_44db;
	case 17632ULL: goto x86_l_44e0;
	case 17636ULL: goto x86_l_44e4;
	case 17640ULL: goto x86_l_44e8;
	case 17645ULL: goto x86_l_44ed;
	case 17647ULL: goto x86_l_44ef;
	case 17651ULL: goto x86_l_44f3;
	case 17654ULL: goto x86_l_44f6;
	case 17659ULL: goto x86_l_44fb;
	case 17664ULL: goto x86_l_4500;
	case 17668ULL: goto x86_l_4504;
	case 17673ULL: goto x86_l_4509;
	case 17675ULL: goto x86_l_450b;
	case 17679ULL: goto x86_l_450f;
	case 17684ULL: goto x86_l_4514;
	case 17689ULL: goto x86_l_4519;
	case 17694ULL: goto x86_l_451e;
	case 17698ULL: goto x86_l_4522;
	case 17703ULL: goto x86_l_4527;
	case 17705ULL: goto x86_l_4529;
	case 17709ULL: goto x86_l_452d;
	case 17713ULL: goto x86_l_4531;
	case 17718ULL: goto x86_l_4536;
	case 17723ULL: goto x86_l_453b;
	case 17728ULL: goto x86_l_4540;
	case 17733ULL: goto x86_l_4545;
	case 17736ULL: goto x86_l_4548;
	case 17738ULL: goto x86_l_454a;
	case 17743ULL: goto x86_l_454f;
	case 17748ULL: goto x86_l_4554;
	case 17752ULL: goto x86_l_4558;
	case 17757ULL: goto x86_l_455d;
	case 17762ULL: goto x86_l_4562;
	case 17767ULL: goto x86_l_4567;
	case 17772ULL: goto x86_l_456c;
	case 17774ULL: goto x86_l_456e;
	case 17779ULL: goto x86_l_4573;
	case 17782ULL: goto x86_l_4576;
	case 17788ULL: goto x86_l_457c;
	case 17793ULL: goto x86_l_4581;
	case 17796ULL: goto x86_l_4584;
	case 17802ULL: goto x86_l_458a;
	case 17806ULL: goto x86_l_458e;
	case 17811ULL: goto x86_l_4593;
	case 17816ULL: goto x86_l_4598;
	case 17821ULL: goto x86_l_459d;
	case 17826ULL: goto x86_l_45a2;
	case 17828ULL: goto x86_l_45a4;
	case 17832ULL: goto x86_l_45a8;
	case 17834ULL: goto x86_l_45aa;
	case 17840ULL: goto x86_l_45b0;
	case 17842ULL: goto x86_l_45b2;
	case 17844ULL: goto x86_l_45b4;
	case 17850ULL: goto x86_l_45ba;
	case 17855ULL: goto x86_l_45bf;
	case 17861ULL: goto x86_l_45c5;
	case 17864ULL: goto x86_l_45c8;
	case 17866ULL: goto x86_l_45ca;
	case 17871ULL: goto x86_l_45cf;
	case 17873ULL: goto x86_l_45d1;
	case 17876ULL: goto x86_l_45d4;
	case 17882ULL: goto x86_l_45da;
	case 17885ULL: goto x86_l_45dd;
	case 17891ULL: goto x86_l_45e3;
	case 17896ULL: goto x86_l_45e8;
	case 17898ULL: goto x86_l_45ea;
	case 17903ULL: goto x86_l_45ef;
	case 17908ULL: goto x86_l_45f4;
	case 17912ULL: goto x86_l_45f8;
	case 17917ULL: goto x86_l_45fd;
	case 17923ULL: goto x86_l_4603;
	case 17927ULL: goto x86_l_4607;
	case 17932ULL: goto x86_l_460c;
	case 17937ULL: goto x86_l_4611;
	case 17942ULL: goto x86_l_4616;
	case 17946ULL: goto x86_l_461a;
	case 17950ULL: goto x86_l_461e;
	case 17955ULL: goto x86_l_4623;
	case 17957ULL: goto x86_l_4625;
	case 17961ULL: goto x86_l_4629;
	case 17964ULL: goto x86_l_462c;
	case 17969ULL: goto x86_l_4631;
	case 17974ULL: goto x86_l_4636;
	case 17978ULL: goto x86_l_463a;
	case 17983ULL: goto x86_l_463f;
	case 17985ULL: goto x86_l_4641;
	case 17989ULL: goto x86_l_4645;
	case 17994ULL: goto x86_l_464a;
	case 17999ULL: goto x86_l_464f;
	case 18004ULL: goto x86_l_4654;
	case 18008ULL: goto x86_l_4658;
	case 18013ULL: goto x86_l_465d;
	case 18015ULL: goto x86_l_465f;
	case 18019ULL: goto x86_l_4663;
	case 18023ULL: goto x86_l_4667;
	case 18028ULL: goto x86_l_466c;
	case 18033ULL: goto x86_l_4671;
	case 18038ULL: goto x86_l_4676;
	case 18043ULL: goto x86_l_467b;
	case 18046ULL: goto x86_l_467e;
	case 18048ULL: goto x86_l_4680;
	case 18053ULL: goto x86_l_4685;
	case 18058ULL: goto x86_l_468a;
	case 18062ULL: goto x86_l_468e;
	case 18067ULL: goto x86_l_4693;
	case 18072ULL: goto x86_l_4698;
	case 18077ULL: goto x86_l_469d;
	case 18082ULL: goto x86_l_46a2;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18092ULL: goto x86_l_46ac;
	case 18094ULL: goto x86_l_46ae;
	case 18099ULL: goto x86_l_46b3;
	case 18102ULL: goto x86_l_46b6;
	case 18104ULL: goto x86_l_46b8;
	case 18108ULL: goto x86_l_46bc;
	case 18113ULL: goto x86_l_46c1;
	case 18118ULL: goto x86_l_46c6;
	case 18123ULL: goto x86_l_46cb;
	case 18128ULL: goto x86_l_46d0;
	case 18130ULL: goto x86_l_46d2;
	case 18134ULL: goto x86_l_46d6;
	case 18136ULL: goto x86_l_46d8;
	case 18142ULL: goto x86_l_46de;
	case 18144ULL: goto x86_l_46e0;
	case 18146ULL: goto x86_l_46e2;
	case 18152ULL: goto x86_l_46e8;
	case 18157ULL: goto x86_l_46ed;
	case 18163ULL: goto x86_l_46f3;
	case 18166ULL: goto x86_l_46f6;
	case 18168ULL: goto x86_l_46f8;
	case 18173ULL: goto x86_l_46fd;
	case 18175ULL: goto x86_l_46ff;
	case 18178ULL: goto x86_l_4702;
	case 18184ULL: goto x86_l_4708;
	case 18187ULL: goto x86_l_470b;
	case 18193ULL: goto x86_l_4711;
	case 18198ULL: goto x86_l_4716;
	case 18200ULL: goto x86_l_4718;
	case 18205ULL: goto x86_l_471d;
	case 18207ULL: goto x86_l_471f;
	case 18210ULL: goto x86_l_4722;
	case 18216ULL: goto x86_l_4728;
	case 18220ULL: goto x86_l_472c;
	case 18225ULL: goto x86_l_4731;
	case 18231ULL: goto x86_l_4737;
	case 18235ULL: goto x86_l_473b;
	case 18240ULL: goto x86_l_4740;
	case 18245ULL: goto x86_l_4745;
	case 18250ULL: goto x86_l_474a;
	case 18254ULL: goto x86_l_474e;
	case 18258ULL: goto x86_l_4752;
	case 18263ULL: goto x86_l_4757;
	case 18265ULL: goto x86_l_4759;
	case 18269ULL: goto x86_l_475d;
	case 18272ULL: goto x86_l_4760;
	case 18277ULL: goto x86_l_4765;
	case 18282ULL: goto x86_l_476a;
	case 18286ULL: goto x86_l_476e;
	case 18291ULL: goto x86_l_4773;
	case 18293ULL: goto x86_l_4775;
	case 18297ULL: goto x86_l_4779;
	case 18302ULL: goto x86_l_477e;
	case 18307ULL: goto x86_l_4783;
	case 18312ULL: goto x86_l_4788;
	case 18316ULL: goto x86_l_478c;
	case 18321ULL: goto x86_l_4791;
	case 18323ULL: goto x86_l_4793;
	case 18327ULL: goto x86_l_4797;
	case 18331ULL: goto x86_l_479b;
	case 18336ULL: goto x86_l_47a0;
	case 18341ULL: goto x86_l_47a5;
	case 18346ULL: goto x86_l_47aa;
	case 18351ULL: goto x86_l_47af;
	case 18354ULL: goto x86_l_47b2;
	case 18356ULL: goto x86_l_47b4;
	case 18361ULL: goto x86_l_47b9;
	case 18366ULL: goto x86_l_47be;
	case 18370ULL: goto x86_l_47c2;
	case 18375ULL: goto x86_l_47c7;
	case 18380ULL: goto x86_l_47cc;
	case 18385ULL: goto x86_l_47d1;
	case 18390ULL: goto x86_l_47d6;
	case 18392ULL: goto x86_l_47d8;
	case 18397ULL: goto x86_l_47dd;
	case 18400ULL: goto x86_l_47e0;
	case 18406ULL: goto x86_l_47e6;
	case 18411ULL: goto x86_l_47eb;
	case 18414ULL: goto x86_l_47ee;
	case 18420ULL: goto x86_l_47f4;
	case 18424ULL: goto x86_l_47f8;
	case 18429ULL: goto x86_l_47fd;
	case 18434ULL: goto x86_l_4802;
	case 18439ULL: goto x86_l_4807;
	case 18444ULL: goto x86_l_480c;
	case 18446ULL: goto x86_l_480e;
	case 18450ULL: goto x86_l_4812;
	case 18452ULL: goto x86_l_4814;
	case 18458ULL: goto x86_l_481a;
	case 18460ULL: goto x86_l_481c;
	case 18462ULL: goto x86_l_481e;
	case 18468ULL: goto x86_l_4824;
	case 18473ULL: goto x86_l_4829;
	case 18479ULL: goto x86_l_482f;
	case 18482ULL: goto x86_l_4832;
	case 18484ULL: goto x86_l_4834;
	case 18489ULL: goto x86_l_4839;
	case 18491ULL: goto x86_l_483b;
	case 18494ULL: goto x86_l_483e;
	case 18500ULL: goto x86_l_4844;
	case 18503ULL: goto x86_l_4847;
	case 18509ULL: goto x86_l_484d;
	case 18514ULL: goto x86_l_4852;
	case 18516ULL: goto x86_l_4854;
	case 18521ULL: goto x86_l_4859;
	case 18526ULL: goto x86_l_485e;
	case 18529ULL: goto x86_l_4861;
	case 18535ULL: goto x86_l_4867;
	case 18539ULL: goto x86_l_486b;
	case 18544ULL: goto x86_l_4870;
	case 18550ULL: goto x86_l_4876;
	case 18554ULL: goto x86_l_487a;
	case 18559ULL: goto x86_l_487f;
	case 18564ULL: goto x86_l_4884;
	case 18569ULL: goto x86_l_4889;
	case 18573ULL: goto x86_l_488d;
	case 18577ULL: goto x86_l_4891;
	case 18582ULL: goto x86_l_4896;
	case 18584ULL: goto x86_l_4898;
	case 18588ULL: goto x86_l_489c;
	case 18591ULL: goto x86_l_489f;
	case 18596ULL: goto x86_l_48a4;
	case 18601ULL: goto x86_l_48a9;
	case 18605ULL: goto x86_l_48ad;
	case 18610ULL: goto x86_l_48b2;
	case 18612ULL: goto x86_l_48b4;
	case 18616ULL: goto x86_l_48b8;
	case 18621ULL: goto x86_l_48bd;
	case 18626ULL: goto x86_l_48c2;
	case 18631ULL: goto x86_l_48c7;
	case 18635ULL: goto x86_l_48cb;
	case 18640ULL: goto x86_l_48d0;
	case 18642ULL: goto x86_l_48d2;
	case 18646ULL: goto x86_l_48d6;
	case 18650ULL: goto x86_l_48da;
	case 18655ULL: goto x86_l_48df;
	case 18660ULL: goto x86_l_48e4;
	case 18665ULL: goto x86_l_48e9;
	case 18670ULL: goto x86_l_48ee;
	case 18673ULL: goto x86_l_48f1;
	case 18675ULL: goto x86_l_48f3;
	case 18680ULL: goto x86_l_48f8;
	case 18685ULL: goto x86_l_48fd;
	case 18689ULL: goto x86_l_4901;
	case 18694ULL: goto x86_l_4906;
	case 18699ULL: goto x86_l_490b;
	case 18704ULL: goto x86_l_4910;
	case 18709ULL: goto x86_l_4915;
	case 18711ULL: goto x86_l_4917;
	case 18716ULL: goto x86_l_491c;
	case 18719ULL: goto x86_l_491f;
	case 18725ULL: goto x86_l_4925;
	case 18730ULL: goto x86_l_492a;
	case 18733ULL: goto x86_l_492d;
	case 18739ULL: goto x86_l_4933;
	case 18743ULL: goto x86_l_4937;
	case 18748ULL: goto x86_l_493c;
	case 18753ULL: goto x86_l_4941;
	case 18758ULL: goto x86_l_4946;
	case 18763ULL: goto x86_l_494b;
	case 18765ULL: goto x86_l_494d;
	case 18769ULL: goto x86_l_4951;
	case 18771ULL: goto x86_l_4953;
	case 18777ULL: goto x86_l_4959;
	case 18779ULL: goto x86_l_495b;
	case 18781ULL: goto x86_l_495d;
	case 18787ULL: goto x86_l_4963;
	case 18792ULL: goto x86_l_4968;
	case 18798ULL: goto x86_l_496e;
	case 18801ULL: goto x86_l_4971;
	case 18803ULL: goto x86_l_4973;
	case 18808ULL: goto x86_l_4978;
	case 18810ULL: goto x86_l_497a;
	case 18813ULL: goto x86_l_497d;
	case 18819ULL: goto x86_l_4983;
	case 18822ULL: goto x86_l_4986;
	case 18828ULL: goto x86_l_498c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_434c:
	/* 0x434c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4350:
	/* 0x4350: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4355:
	/* 0x4355: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_435a:
	/* 0x435a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_435f:
	/* 0x435f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4364:
	/* 0x4364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4366:
	/* 0x4366: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_436a:
	/* 0x436a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_436c:
	/* 0x436c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4372:
	/* 0x4372: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4374:
	/* 0x4374: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4376:
	/* 0x4376: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_437c:
	/* 0x437c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4381:
	/* 0x4381: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4387:
	/* 0x4387: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_438a:
	/* 0x438a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_438c:
	/* 0x438c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4391:
	/* 0x4391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4393:
	/* 0x4393: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4396:
	/* 0x4396: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_439c:
	/* 0x439c: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_439f:
	/* 0x439f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_43a5:
	/* 0x43a5: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_43aa:
	/* 0x43aa: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43ac:
	/* 0x43ac: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43b1:
	/* 0x43b1: jmp    4531 <trace_security_mmap_file+0x4531> */
	goto x86_l_4531;
x86_l_43b6:
	/* 0x43b6: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_43bb:
	/* 0x43bb: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_43c1:
	/* 0x43c1: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_43c4:
	/* 0x43c4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_43c6:
	/* 0x43c6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_43cb:
	/* 0x43cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43cd:
	/* 0x43cd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43d0:
	/* 0x43d0: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_44ab;
	}
x86_l_43d6:
	/* 0x43d6: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_43d9:
	/* 0x43d9: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_43df:
	/* 0x43df: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_43e4:
	/* 0x43e4: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43e6:
	/* 0x43e6: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43eb:
	/* 0x43eb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43f0:
	/* 0x43f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_43f5:
	/* 0x43f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_43fa:
	/* 0x43fa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43ff:
	/* 0x43ff: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4402:
	/* 0x4402: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4404:
	/* 0x4404: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4409:
	/* 0x4409: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_440e:
	/* 0x440e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4412:
	/* 0x4412: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4417:
	/* 0x4417: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_441c:
	/* 0x441c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4421:
	/* 0x4421: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4426:
	/* 0x4426: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4428:
	/* 0x4428: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_442d:
	/* 0x442d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4430:
	/* 0x4430: je     44a2 <trace_security_mmap_file+0x44a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44a2;
	}
x86_l_4432:
	/* 0x4432: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4437:
	/* 0x4437: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_443a:
	/* 0x443a: je     44a2 <trace_security_mmap_file+0x44a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44a2;
	}
x86_l_443c:
	/* 0x443c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4440:
	/* 0x4440: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4445:
	/* 0x4445: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_444a:
	/* 0x444a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_444f:
	/* 0x444f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4454:
	/* 0x4454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4456:
	/* 0x4456: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_445a:
	/* 0x445a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_445c:
	/* 0x445c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4462:
	/* 0x4462: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4464:
	/* 0x4464: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4466:
	/* 0x4466: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_446c:
	/* 0x446c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4471:
	/* 0x4471: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4477:
	/* 0x4477: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_447a:
	/* 0x447a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_447c:
	/* 0x447c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4481:
	/* 0x4481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4483:
	/* 0x4483: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4486:
	/* 0x4486: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_44ab;
	}
x86_l_4488:
	/* 0x4488: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_448b:
	/* 0x448b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4491:
	/* 0x4491: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4496:
	/* 0x4496: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4498:
	/* 0x4498: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_449d:
	/* 0x449d: jmp    4667 <trace_security_mmap_file+0x4667> */
	goto x86_l_4667;
x86_l_44a2:
	/* 0x44a2: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_44a5:
	/* 0x44a5: je     45f4 <trace_security_mmap_file+0x45f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45f4;
	}
x86_l_44ab:
	/* 0x44ab: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44b0:
	/* 0x44b0: jmp    196c <trace_security_mmap_file+0x196c> */
	return 6508ULL;
x86_l_44b5:
	/* 0x44b5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_44b8:
	/* 0x44b8: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_44be:
	/* 0x44be: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c2:
	/* 0x44c2: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_44c7:
	/* 0x44c7: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_44cd:
	/* 0x44cd: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_44d1:
	/* 0x44d1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d6:
	/* 0x44d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44db:
	/* 0x44db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_44e0:
	/* 0x44e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44e4:
	/* 0x44e4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_44e8:
	/* 0x44e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_44ed:
	/* 0x44ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44ef:
	/* 0x44ef: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44f3:
	/* 0x44f3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_44f6:
	/* 0x44f6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_44fb:
	/* 0x44fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4500:
	/* 0x4500: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4504:
	/* 0x4504: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4509:
	/* 0x4509: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_450b:
	/* 0x450b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_450f:
	/* 0x450f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4514:
	/* 0x4514: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4519:
	/* 0x4519: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_451e:
	/* 0x451e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4522:
	/* 0x4522: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4527:
	/* 0x4527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4529:
	/* 0x4529: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_452d:
	/* 0x452d: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4531:
	/* 0x4531: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4536:
	/* 0x4536: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_453b:
	/* 0x453b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4540:
	/* 0x4540: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4545:
	/* 0x4545: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4548:
	/* 0x4548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_454a:
	/* 0x454a: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_454f:
	/* 0x454f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4554:
	/* 0x4554: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4558:
	/* 0x4558: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_455d:
	/* 0x455d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4562:
	/* 0x4562: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4567:
	/* 0x4567: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_456c:
	/* 0x456c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_456e:
	/* 0x456e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4573:
	/* 0x4573: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4576:
	/* 0x4576: je     485e <trace_security_mmap_file+0x485e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485e;
	}
x86_l_457c:
	/* 0x457c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4581:
	/* 0x4581: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4584:
	/* 0x4584: je     485e <trace_security_mmap_file+0x485e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_485e;
	}
x86_l_458a:
	/* 0x458a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_458e:
	/* 0x458e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4593:
	/* 0x4593: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4598:
	/* 0x4598: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_459d:
	/* 0x459d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_45a2:
	/* 0x45a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a4:
	/* 0x45a4: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_45a8:
	/* 0x45a8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_45aa:
	/* 0x45aa: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_45b0:
	/* 0x45b0: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_45b2:
	/* 0x45b2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_45b4:
	/* 0x45b4: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_45ba:
	/* 0x45ba: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_45bf:
	/* 0x45bf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_45c5:
	/* 0x45c5: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_45c8:
	/* 0x45c8: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_45ca:
	/* 0x45ca: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_45cf:
	/* 0x45cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45d1:
	/* 0x45d1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_45d4:
	/* 0x45d4: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_45da:
	/* 0x45da: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_45dd:
	/* 0x45dd: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_45e3:
	/* 0x45e3: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_45e8:
	/* 0x45e8: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_45ea:
	/* 0x45ea: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45ef:
	/* 0x45ef: jmp    48da <trace_security_mmap_file+0x48da> */
	goto x86_l_48da;
x86_l_45f4:
	/* 0x45f4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45f8:
	/* 0x45f8: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_45fd:
	/* 0x45fd: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44ab;
	}
x86_l_4603:
	/* 0x4603: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4607:
	/* 0x4607: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_460c:
	/* 0x460c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4611:
	/* 0x4611: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4616:
	/* 0x4616: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_461a:
	/* 0x461a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_461e:
	/* 0x461e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4623:
	/* 0x4623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4625:
	/* 0x4625: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4629:
	/* 0x4629: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_462c:
	/* 0x462c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4631:
	/* 0x4631: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4636:
	/* 0x4636: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_463a:
	/* 0x463a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_463f:
	/* 0x463f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4641:
	/* 0x4641: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4645:
	/* 0x4645: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_464a:
	/* 0x464a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_464f:
	/* 0x464f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4654:
	/* 0x4654: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4658:
	/* 0x4658: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_465d:
	/* 0x465d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465f:
	/* 0x465f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4663:
	/* 0x4663: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4667:
	/* 0x4667: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_466c:
	/* 0x466c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4671:
	/* 0x4671: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4676:
	/* 0x4676: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_467b:
	/* 0x467b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_467e:
	/* 0x467e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4680:
	/* 0x4680: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4685:
	/* 0x4685: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_468a:
	/* 0x468a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_468e:
	/* 0x468e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4693:
	/* 0x4693: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4698:
	/* 0x4698: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_469d:
	/* 0x469d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_46a2:
	/* 0x46a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46a4:
	/* 0x46a4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a9:
	/* 0x46a9: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_46ac:
	/* 0x46ac: je     471f <trace_security_mmap_file+0x471f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_471f;
	}
x86_l_46ae:
	/* 0x46ae: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46b3:
	/* 0x46b3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_46b6:
	/* 0x46b6: je     471f <trace_security_mmap_file+0x471f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_471f;
	}
x86_l_46b8:
	/* 0x46b8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_46bc:
	/* 0x46bc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46c1:
	/* 0x46c1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_46c6:
	/* 0x46c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_46cb:
	/* 0x46cb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_46d0:
	/* 0x46d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46d2:
	/* 0x46d2: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_46d6:
	/* 0x46d6: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_46d8:
	/* 0x46d8: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_46de:
	/* 0x46de: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_46e0:
	/* 0x46e0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_46e2:
	/* 0x46e2: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_46e8:
	/* 0x46e8: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_46ed:
	/* 0x46ed: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_46f3:
	/* 0x46f3: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46f6:
	/* 0x46f6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_46f8:
	/* 0x46f8: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_46fd:
	/* 0x46fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46ff:
	/* 0x46ff: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4702:
	/* 0x4702: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_44ab;
	}
x86_l_4708:
	/* 0x4708: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_470b:
	/* 0x470b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4711:
	/* 0x4711: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4716:
	/* 0x4716: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4718:
	/* 0x4718: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_471d:
	/* 0x471d: jmp    479b <trace_security_mmap_file+0x479b> */
	goto x86_l_479b;
x86_l_471f:
	/* 0x471f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4722:
	/* 0x4722: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_44ab;
	}
x86_l_4728:
	/* 0x4728: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_472c:
	/* 0x472c: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4731:
	/* 0x4731: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44ab;
	}
x86_l_4737:
	/* 0x4737: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_473b:
	/* 0x473b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4740:
	/* 0x4740: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4745:
	/* 0x4745: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_474a:
	/* 0x474a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_474e:
	/* 0x474e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4752:
	/* 0x4752: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4757:
	/* 0x4757: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4759:
	/* 0x4759: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_475d:
	/* 0x475d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4760:
	/* 0x4760: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4765:
	/* 0x4765: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_476a:
	/* 0x476a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_476e:
	/* 0x476e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4773:
	/* 0x4773: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4775:
	/* 0x4775: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4779:
	/* 0x4779: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_477e:
	/* 0x477e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4783:
	/* 0x4783: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4788:
	/* 0x4788: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_478c:
	/* 0x478c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4791:
	/* 0x4791: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4793:
	/* 0x4793: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4797:
	/* 0x4797: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_479b:
	/* 0x479b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47a0:
	/* 0x47a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47a5:
	/* 0x47a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47aa:
	/* 0x47aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47af:
	/* 0x47af: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_47b2:
	/* 0x47b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47b4:
	/* 0x47b4: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47b9:
	/* 0x47b9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47be:
	/* 0x47be: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_47c2:
	/* 0x47c2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47c7:
	/* 0x47c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_47cc:
	/* 0x47cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_47d1:
	/* 0x47d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_47d6:
	/* 0x47d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47d8:
	/* 0x47d8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47dd:
	/* 0x47dd: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_47e0:
	/* 0x47e0: je     499d <trace_security_mmap_file+0x499d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18845ULL;
	}
x86_l_47e6:
	/* 0x47e6: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47eb:
	/* 0x47eb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_47ee:
	/* 0x47ee: je     499d <trace_security_mmap_file+0x499d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18845ULL;
	}
x86_l_47f4:
	/* 0x47f4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_47f8:
	/* 0x47f8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47fd:
	/* 0x47fd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4802:
	/* 0x4802: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4807:
	/* 0x4807: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_480c:
	/* 0x480c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_480e:
	/* 0x480e: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4812:
	/* 0x4812: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4814:
	/* 0x4814: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_481a:
	/* 0x481a: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_481c:
	/* 0x481c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_481e:
	/* 0x481e: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_4824:
	/* 0x4824: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4829:
	/* 0x4829: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_482f:
	/* 0x482f: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4832:
	/* 0x4832: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4834:
	/* 0x4834: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4839:
	/* 0x4839: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483b:
	/* 0x483b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_483e:
	/* 0x483e: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_44ab;
	}
x86_l_4844:
	/* 0x4844: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4847:
	/* 0x4847: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_484d:
	/* 0x484d: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4852:
	/* 0x4852: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4854:
	/* 0x4854: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4859:
	/* 0x4859: jmp    4a19 <trace_security_mmap_file+0x4a19> */
	return 18969ULL;
x86_l_485e:
	/* 0x485e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4861:
	/* 0x4861: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_4867:
	/* 0x4867: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_486b:
	/* 0x486b: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4870:
	/* 0x4870: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_4876:
	/* 0x4876: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_487a:
	/* 0x487a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_487f:
	/* 0x487f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4884:
	/* 0x4884: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4889:
	/* 0x4889: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_488d:
	/* 0x488d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4891:
	/* 0x4891: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4896:
	/* 0x4896: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4898:
	/* 0x4898: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_489c:
	/* 0x489c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_489f:
	/* 0x489f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48a4:
	/* 0x48a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48a9:
	/* 0x48a9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48ad:
	/* 0x48ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48b2:
	/* 0x48b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48b4:
	/* 0x48b4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48b8:
	/* 0x48b8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48bd:
	/* 0x48bd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_48c2:
	/* 0x48c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48c7:
	/* 0x48c7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48cb:
	/* 0x48cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48d0:
	/* 0x48d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d2:
	/* 0x48d2: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48d6:
	/* 0x48d6: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_48da:
	/* 0x48da: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48df:
	/* 0x48df: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_48e4:
	/* 0x48e4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_48e9:
	/* 0x48e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48ee:
	/* 0x48ee: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_48f1:
	/* 0x48f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48f3:
	/* 0x48f3: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48f8:
	/* 0x48f8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48fd:
	/* 0x48fd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4901:
	/* 0x4901: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4906:
	/* 0x4906: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_490b:
	/* 0x490b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4910:
	/* 0x4910: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4915:
	/* 0x4915: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4917:
	/* 0x4917: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_491c:
	/* 0x491c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_491f:
	/* 0x491f: je     4adc <trace_security_mmap_file+0x4adc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19164ULL;
	}
x86_l_4925:
	/* 0x4925: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_492a:
	/* 0x492a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_492d:
	/* 0x492d: je     4adc <trace_security_mmap_file+0x4adc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 19164ULL;
	}
x86_l_4933:
	/* 0x4933: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4937:
	/* 0x4937: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_493c:
	/* 0x493c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4941:
	/* 0x4941: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4946:
	/* 0x4946: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_494b:
	/* 0x494b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_494d:
	/* 0x494d: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4951:
	/* 0x4951: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4953:
	/* 0x4953: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4959:
	/* 0x4959: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_495b:
	/* 0x495b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_495d:
	/* 0x495d: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_4963:
	/* 0x4963: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4968:
	/* 0x4968: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_496e:
	/* 0x496e: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4971:
	/* 0x4971: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4973:
	/* 0x4973: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4978:
	/* 0x4978: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497a:
	/* 0x497a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_497d:
	/* 0x497d: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_4983:
	/* 0x4983: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4986:
	/* 0x4986: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_498c:
	/* 0x498c: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
	return 18833ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18833ULL: goto x86_l_4991;
	case 18835ULL: goto x86_l_4993;
	case 18840ULL: goto x86_l_4998;
	case 18845ULL: goto x86_l_499d;
	case 18848ULL: goto x86_l_49a0;
	case 18854ULL: goto x86_l_49a6;
	case 18858ULL: goto x86_l_49aa;
	case 18863ULL: goto x86_l_49af;
	case 18869ULL: goto x86_l_49b5;
	case 18873ULL: goto x86_l_49b9;
	case 18878ULL: goto x86_l_49be;
	case 18883ULL: goto x86_l_49c3;
	case 18888ULL: goto x86_l_49c8;
	case 18892ULL: goto x86_l_49cc;
	case 18896ULL: goto x86_l_49d0;
	case 18901ULL: goto x86_l_49d5;
	case 18903ULL: goto x86_l_49d7;
	case 18907ULL: goto x86_l_49db;
	case 18910ULL: goto x86_l_49de;
	case 18915ULL: goto x86_l_49e3;
	case 18920ULL: goto x86_l_49e8;
	case 18924ULL: goto x86_l_49ec;
	case 18929ULL: goto x86_l_49f1;
	case 18931ULL: goto x86_l_49f3;
	case 18935ULL: goto x86_l_49f7;
	case 18940ULL: goto x86_l_49fc;
	case 18945ULL: goto x86_l_4a01;
	case 18950ULL: goto x86_l_4a06;
	case 18954ULL: goto x86_l_4a0a;
	case 18959ULL: goto x86_l_4a0f;
	case 18961ULL: goto x86_l_4a11;
	case 18965ULL: goto x86_l_4a15;
	case 18969ULL: goto x86_l_4a19;
	case 18974ULL: goto x86_l_4a1e;
	case 18979ULL: goto x86_l_4a23;
	case 18984ULL: goto x86_l_4a28;
	case 18989ULL: goto x86_l_4a2d;
	case 18992ULL: goto x86_l_4a30;
	case 18994ULL: goto x86_l_4a32;
	case 18999ULL: goto x86_l_4a37;
	case 19004ULL: goto x86_l_4a3c;
	case 19008ULL: goto x86_l_4a40;
	case 19013ULL: goto x86_l_4a45;
	case 19018ULL: goto x86_l_4a4a;
	case 19023ULL: goto x86_l_4a4f;
	case 19028ULL: goto x86_l_4a54;
	case 19030ULL: goto x86_l_4a56;
	case 19035ULL: goto x86_l_4a5b;
	case 19038ULL: goto x86_l_4a5e;
	case 19044ULL: goto x86_l_4a64;
	case 19049ULL: goto x86_l_4a69;
	case 19052ULL: goto x86_l_4a6c;
	case 19058ULL: goto x86_l_4a72;
	case 19062ULL: goto x86_l_4a76;
	case 19067ULL: goto x86_l_4a7b;
	case 19072ULL: goto x86_l_4a80;
	case 19077ULL: goto x86_l_4a85;
	case 19082ULL: goto x86_l_4a8a;
	case 19084ULL: goto x86_l_4a8c;
	case 19088ULL: goto x86_l_4a90;
	case 19090ULL: goto x86_l_4a92;
	case 19096ULL: goto x86_l_4a98;
	case 19098ULL: goto x86_l_4a9a;
	case 19100ULL: goto x86_l_4a9c;
	case 19106ULL: goto x86_l_4aa2;
	case 19111ULL: goto x86_l_4aa7;
	case 19117ULL: goto x86_l_4aad;
	case 19120ULL: goto x86_l_4ab0;
	case 19122ULL: goto x86_l_4ab2;
	case 19127ULL: goto x86_l_4ab7;
	case 19129ULL: goto x86_l_4ab9;
	case 19132ULL: goto x86_l_4abc;
	case 19138ULL: goto x86_l_4ac2;
	case 19141ULL: goto x86_l_4ac5;
	case 19147ULL: goto x86_l_4acb;
	case 19152ULL: goto x86_l_4ad0;
	case 19154ULL: goto x86_l_4ad2;
	case 19159ULL: goto x86_l_4ad7;
	case 19164ULL: goto x86_l_4adc;
	case 19167ULL: goto x86_l_4adf;
	case 19173ULL: goto x86_l_4ae5;
	case 19177ULL: goto x86_l_4ae9;
	case 19182ULL: goto x86_l_4aee;
	case 19188ULL: goto x86_l_4af4;
	case 19192ULL: goto x86_l_4af8;
	case 19197ULL: goto x86_l_4afd;
	case 19202ULL: goto x86_l_4b02;
	case 19207ULL: goto x86_l_4b07;
	case 19211ULL: goto x86_l_4b0b;
	case 19215ULL: goto x86_l_4b0f;
	case 19220ULL: goto x86_l_4b14;
	case 19222ULL: goto x86_l_4b16;
	case 19226ULL: goto x86_l_4b1a;
	case 19229ULL: goto x86_l_4b1d;
	case 19234ULL: goto x86_l_4b22;
	case 19239ULL: goto x86_l_4b27;
	case 19243ULL: goto x86_l_4b2b;
	case 19248ULL: goto x86_l_4b30;
	case 19250ULL: goto x86_l_4b32;
	case 19254ULL: goto x86_l_4b36;
	case 19259ULL: goto x86_l_4b3b;
	case 19264ULL: goto x86_l_4b40;
	case 19269ULL: goto x86_l_4b45;
	case 19273ULL: goto x86_l_4b49;
	case 19278ULL: goto x86_l_4b4e;
	case 19280ULL: goto x86_l_4b50;
	case 19284ULL: goto x86_l_4b54;
	case 19288ULL: goto x86_l_4b58;
	case 19293ULL: goto x86_l_4b5d;
	case 19298ULL: goto x86_l_4b62;
	case 19303ULL: goto x86_l_4b67;
	case 19308ULL: goto x86_l_4b6c;
	case 19311ULL: goto x86_l_4b6f;
	case 19313ULL: goto x86_l_4b71;
	case 19318ULL: goto x86_l_4b76;
	case 19323ULL: goto x86_l_4b7b;
	case 19327ULL: goto x86_l_4b7f;
	case 19332ULL: goto x86_l_4b84;
	case 19337ULL: goto x86_l_4b89;
	case 19342ULL: goto x86_l_4b8e;
	case 19347ULL: goto x86_l_4b93;
	case 19349ULL: goto x86_l_4b95;
	case 19354ULL: goto x86_l_4b9a;
	case 19357ULL: goto x86_l_4b9d;
	case 19363ULL: goto x86_l_4ba3;
	case 19368ULL: goto x86_l_4ba8;
	case 19371ULL: goto x86_l_4bab;
	case 19377ULL: goto x86_l_4bb1;
	case 19381ULL: goto x86_l_4bb5;
	case 19386ULL: goto x86_l_4bba;
	case 19391ULL: goto x86_l_4bbf;
	case 19396ULL: goto x86_l_4bc4;
	case 19401ULL: goto x86_l_4bc9;
	case 19403ULL: goto x86_l_4bcb;
	case 19407ULL: goto x86_l_4bcf;
	case 19409ULL: goto x86_l_4bd1;
	case 19415ULL: goto x86_l_4bd7;
	case 19417ULL: goto x86_l_4bd9;
	case 19419ULL: goto x86_l_4bdb;
	case 19425ULL: goto x86_l_4be1;
	case 19430ULL: goto x86_l_4be6;
	case 19436ULL: goto x86_l_4bec;
	case 19439ULL: goto x86_l_4bef;
	case 19441ULL: goto x86_l_4bf1;
	case 19446ULL: goto x86_l_4bf6;
	case 19448ULL: goto x86_l_4bf8;
	case 19451ULL: goto x86_l_4bfb;
	case 19457ULL: goto x86_l_4c01;
	case 19460ULL: goto x86_l_4c04;
	case 19466ULL: goto x86_l_4c0a;
	case 19471ULL: goto x86_l_4c0f;
	case 19473ULL: goto x86_l_4c11;
	case 19478ULL: goto x86_l_4c16;
	case 19483ULL: goto x86_l_4c1b;
	case 19486ULL: goto x86_l_4c1e;
	case 19492ULL: goto x86_l_4c24;
	case 19496ULL: goto x86_l_4c28;
	case 19501ULL: goto x86_l_4c2d;
	case 19507ULL: goto x86_l_4c33;
	case 19511ULL: goto x86_l_4c37;
	case 19516ULL: goto x86_l_4c3c;
	case 19521ULL: goto x86_l_4c41;
	case 19526ULL: goto x86_l_4c46;
	case 19530ULL: goto x86_l_4c4a;
	case 19534ULL: goto x86_l_4c4e;
	case 19539ULL: goto x86_l_4c53;
	case 19541ULL: goto x86_l_4c55;
	case 19545ULL: goto x86_l_4c59;
	case 19548ULL: goto x86_l_4c5c;
	case 19553ULL: goto x86_l_4c61;
	case 19558ULL: goto x86_l_4c66;
	case 19562ULL: goto x86_l_4c6a;
	case 19567ULL: goto x86_l_4c6f;
	case 19569ULL: goto x86_l_4c71;
	case 19573ULL: goto x86_l_4c75;
	case 19578ULL: goto x86_l_4c7a;
	case 19583ULL: goto x86_l_4c7f;
	case 19588ULL: goto x86_l_4c84;
	case 19592ULL: goto x86_l_4c88;
	case 19597ULL: goto x86_l_4c8d;
	case 19599ULL: goto x86_l_4c8f;
	case 19603ULL: goto x86_l_4c93;
	case 19607ULL: goto x86_l_4c97;
	case 19612ULL: goto x86_l_4c9c;
	case 19617ULL: goto x86_l_4ca1;
	case 19622ULL: goto x86_l_4ca6;
	case 19627ULL: goto x86_l_4cab;
	case 19630ULL: goto x86_l_4cae;
	case 19632ULL: goto x86_l_4cb0;
	case 19637ULL: goto x86_l_4cb5;
	case 19642ULL: goto x86_l_4cba;
	case 19646ULL: goto x86_l_4cbe;
	case 19651ULL: goto x86_l_4cc3;
	case 19656ULL: goto x86_l_4cc8;
	case 19661ULL: goto x86_l_4ccd;
	case 19666ULL: goto x86_l_4cd2;
	case 19668ULL: goto x86_l_4cd4;
	case 19673ULL: goto x86_l_4cd9;
	case 19676ULL: goto x86_l_4cdc;
	case 19682ULL: goto x86_l_4ce2;
	case 19687ULL: goto x86_l_4ce7;
	case 19690ULL: goto x86_l_4cea;
	case 19696ULL: goto x86_l_4cf0;
	case 19700ULL: goto x86_l_4cf4;
	case 19705ULL: goto x86_l_4cf9;
	case 19710ULL: goto x86_l_4cfe;
	case 19715ULL: goto x86_l_4d03;
	case 19720ULL: goto x86_l_4d08;
	case 19722ULL: goto x86_l_4d0a;
	case 19726ULL: goto x86_l_4d0e;
	case 19728ULL: goto x86_l_4d10;
	case 19734ULL: goto x86_l_4d16;
	case 19736ULL: goto x86_l_4d18;
	case 19738ULL: goto x86_l_4d1a;
	case 19744ULL: goto x86_l_4d20;
	case 19749ULL: goto x86_l_4d25;
	case 19755ULL: goto x86_l_4d2b;
	case 19758ULL: goto x86_l_4d2e;
	case 19760ULL: goto x86_l_4d30;
	case 19765ULL: goto x86_l_4d35;
	case 19767ULL: goto x86_l_4d37;
	case 19770ULL: goto x86_l_4d3a;
	case 19776ULL: goto x86_l_4d40;
	case 19779ULL: goto x86_l_4d43;
	case 19785ULL: goto x86_l_4d49;
	case 19790ULL: goto x86_l_4d4e;
	case 19792ULL: goto x86_l_4d50;
	case 19797ULL: goto x86_l_4d55;
	case 19802ULL: goto x86_l_4d5a;
	case 19805ULL: goto x86_l_4d5d;
	case 19811ULL: goto x86_l_4d63;
	case 19815ULL: goto x86_l_4d67;
	case 19820ULL: goto x86_l_4d6c;
	case 19826ULL: goto x86_l_4d72;
	case 19830ULL: goto x86_l_4d76;
	case 19835ULL: goto x86_l_4d7b;
	case 19840ULL: goto x86_l_4d80;
	case 19845ULL: goto x86_l_4d85;
	case 19849ULL: goto x86_l_4d89;
	case 19853ULL: goto x86_l_4d8d;
	case 19858ULL: goto x86_l_4d92;
	case 19860ULL: goto x86_l_4d94;
	case 19864ULL: goto x86_l_4d98;
	case 19867ULL: goto x86_l_4d9b;
	case 19872ULL: goto x86_l_4da0;
	case 19877ULL: goto x86_l_4da5;
	case 19881ULL: goto x86_l_4da9;
	case 19886ULL: goto x86_l_4dae;
	case 19888ULL: goto x86_l_4db0;
	case 19892ULL: goto x86_l_4db4;
	case 19897ULL: goto x86_l_4db9;
	case 19902ULL: goto x86_l_4dbe;
	case 19907ULL: goto x86_l_4dc3;
	case 19911ULL: goto x86_l_4dc7;
	case 19916ULL: goto x86_l_4dcc;
	case 19918ULL: goto x86_l_4dce;
	case 19922ULL: goto x86_l_4dd2;
	case 19926ULL: goto x86_l_4dd6;
	case 19931ULL: goto x86_l_4ddb;
	case 19936ULL: goto x86_l_4de0;
	case 19941ULL: goto x86_l_4de5;
	case 19946ULL: goto x86_l_4dea;
	case 19949ULL: goto x86_l_4ded;
	case 19951ULL: goto x86_l_4def;
	case 19956ULL: goto x86_l_4df4;
	case 19961ULL: goto x86_l_4df9;
	case 19965ULL: goto x86_l_4dfd;
	case 19970ULL: goto x86_l_4e02;
	case 19975ULL: goto x86_l_4e07;
	case 19980ULL: goto x86_l_4e0c;
	case 19985ULL: goto x86_l_4e11;
	case 19987ULL: goto x86_l_4e13;
	case 19992ULL: goto x86_l_4e18;
	case 19995ULL: goto x86_l_4e1b;
	case 20001ULL: goto x86_l_4e21;
	case 20006ULL: goto x86_l_4e26;
	case 20009ULL: goto x86_l_4e29;
	case 20015ULL: goto x86_l_4e2f;
	case 20019ULL: goto x86_l_4e33;
	case 20024ULL: goto x86_l_4e38;
	case 20029ULL: goto x86_l_4e3d;
	case 20034ULL: goto x86_l_4e42;
	case 20039ULL: goto x86_l_4e47;
	case 20041ULL: goto x86_l_4e49;
	case 20045ULL: goto x86_l_4e4d;
	case 20047ULL: goto x86_l_4e4f;
	case 20053ULL: goto x86_l_4e55;
	case 20055ULL: goto x86_l_4e57;
	case 20057ULL: goto x86_l_4e59;
	case 20063ULL: goto x86_l_4e5f;
	case 20068ULL: goto x86_l_4e64;
	case 20074ULL: goto x86_l_4e6a;
	case 20077ULL: goto x86_l_4e6d;
	case 20079ULL: goto x86_l_4e6f;
	case 20084ULL: goto x86_l_4e74;
	case 20086ULL: goto x86_l_4e76;
	case 20089ULL: goto x86_l_4e79;
	case 20095ULL: goto x86_l_4e7f;
	case 20098ULL: goto x86_l_4e82;
	case 20104ULL: goto x86_l_4e88;
	case 20109ULL: goto x86_l_4e8d;
	case 20111ULL: goto x86_l_4e8f;
	case 20116ULL: goto x86_l_4e94;
	case 20121ULL: goto x86_l_4e99;
	case 20124ULL: goto x86_l_4e9c;
	case 20130ULL: goto x86_l_4ea2;
	case 20134ULL: goto x86_l_4ea6;
	case 20139ULL: goto x86_l_4eab;
	case 20145ULL: goto x86_l_4eb1;
	case 20149ULL: goto x86_l_4eb5;
	case 20154ULL: goto x86_l_4eba;
	case 20159ULL: goto x86_l_4ebf;
	case 20164ULL: goto x86_l_4ec4;
	case 20168ULL: goto x86_l_4ec8;
	case 20172ULL: goto x86_l_4ecc;
	case 20177ULL: goto x86_l_4ed1;
	case 20179ULL: goto x86_l_4ed3;
	case 20183ULL: goto x86_l_4ed7;
	case 20186ULL: goto x86_l_4eda;
	case 20191ULL: goto x86_l_4edf;
	case 20196ULL: goto x86_l_4ee4;
	case 20200ULL: goto x86_l_4ee8;
	case 20205ULL: goto x86_l_4eed;
	case 20207ULL: goto x86_l_4eef;
	case 20211ULL: goto x86_l_4ef3;
	case 20216ULL: goto x86_l_4ef8;
	case 20221ULL: goto x86_l_4efd;
	case 20226ULL: goto x86_l_4f02;
	case 20230ULL: goto x86_l_4f06;
	case 20235ULL: goto x86_l_4f0b;
	case 20237ULL: goto x86_l_4f0d;
	case 20241ULL: goto x86_l_4f11;
	case 20245ULL: goto x86_l_4f15;
	case 20250ULL: goto x86_l_4f1a;
	case 20255ULL: goto x86_l_4f1f;
	case 20260ULL: goto x86_l_4f24;
	case 20265ULL: goto x86_l_4f29;
	case 20268ULL: goto x86_l_4f2c;
	case 20270ULL: goto x86_l_4f2e;
	case 20275ULL: goto x86_l_4f33;
	case 20280ULL: goto x86_l_4f38;
	case 20284ULL: goto x86_l_4f3c;
	case 20289ULL: goto x86_l_4f41;
	case 20294ULL: goto x86_l_4f46;
	case 20299ULL: goto x86_l_4f4b;
	case 20304ULL: goto x86_l_4f50;
	case 20306ULL: goto x86_l_4f52;
	case 20311ULL: goto x86_l_4f57;
	case 20314ULL: goto x86_l_4f5a;
	case 20320ULL: goto x86_l_4f60;
	case 20325ULL: goto x86_l_4f65;
	case 20328ULL: goto x86_l_4f68;
	case 20334ULL: goto x86_l_4f6e;
	case 20338ULL: goto x86_l_4f72;
	case 20343ULL: goto x86_l_4f77;
	case 20348ULL: goto x86_l_4f7c;
	case 20353ULL: goto x86_l_4f81;
	case 20358ULL: goto x86_l_4f86;
	case 20360ULL: goto x86_l_4f88;
	case 20364ULL: goto x86_l_4f8c;
	case 20366ULL: goto x86_l_4f8e;
	case 20372ULL: goto x86_l_4f94;
	case 20374ULL: goto x86_l_4f96;
	case 20376ULL: goto x86_l_4f98;
	case 20382ULL: goto x86_l_4f9e;
	case 20387ULL: goto x86_l_4fa3;
	case 20393ULL: goto x86_l_4fa9;
	case 20396ULL: goto x86_l_4fac;
	case 20398ULL: goto x86_l_4fae;
	case 20403ULL: goto x86_l_4fb3;
	case 20405ULL: goto x86_l_4fb5;
	case 20408ULL: goto x86_l_4fb8;
	case 20414ULL: goto x86_l_4fbe;
	case 20417ULL: goto x86_l_4fc1;
	case 20423ULL: goto x86_l_4fc7;
	case 20428ULL: goto x86_l_4fcc;
	case 20430ULL: goto x86_l_4fce;
	case 20435ULL: goto x86_l_4fd3;
	case 20440ULL: goto x86_l_4fd8;
	case 20443ULL: goto x86_l_4fdb;
	case 20449ULL: goto x86_l_4fe1;
	case 20453ULL: goto x86_l_4fe5;
	case 20458ULL: goto x86_l_4fea;
	case 20464ULL: goto x86_l_4ff0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4991:
	/* 0x4991: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4993:
	/* 0x4993: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4998:
	/* 0x4998: jmp    4b58 <trace_security_mmap_file+0x4b58> */
	goto x86_l_4b58;
x86_l_499d:
	/* 0x499d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_49a0:
	/* 0x49a0: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_49a6:
	/* 0x49a6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49aa:
	/* 0x49aa: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_49af:
	/* 0x49af: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_49b5:
	/* 0x49b5: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49b9:
	/* 0x49b9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49be:
	/* 0x49be: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49c3:
	/* 0x49c3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49c8:
	/* 0x49c8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49cc:
	/* 0x49cc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49d0:
	/* 0x49d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49d5:
	/* 0x49d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49d7:
	/* 0x49d7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49db:
	/* 0x49db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_49de:
	/* 0x49de: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_49e3:
	/* 0x49e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_49e8:
	/* 0x49e8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49ec:
	/* 0x49ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_49f1:
	/* 0x49f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49f3:
	/* 0x49f3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f7:
	/* 0x49f7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_49fc:
	/* 0x49fc: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4a01:
	/* 0x4a01: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a06:
	/* 0x4a06: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a0a:
	/* 0x4a0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a0f:
	/* 0x4a0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a11:
	/* 0x4a11: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a15:
	/* 0x4a15: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a19:
	/* 0x4a19: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a1e:
	/* 0x4a1e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a23:
	/* 0x4a23: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a28:
	/* 0x4a28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a2d:
	/* 0x4a2d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4a30:
	/* 0x4a30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a32:
	/* 0x4a32: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a37:
	/* 0x4a37: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a3c:
	/* 0x4a3c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4a40:
	/* 0x4a40: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a45:
	/* 0x4a45: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4a4a:
	/* 0x4a4a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a4f:
	/* 0x4a4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a54:
	/* 0x4a54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a56:
	/* 0x4a56: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a5b:
	/* 0x4a5b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4a5e:
	/* 0x4a5e: je     4c1b <trace_security_mmap_file+0x4c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c1b;
	}
x86_l_4a64:
	/* 0x4a64: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a69:
	/* 0x4a69: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4a6c:
	/* 0x4a6c: je     4c1b <trace_security_mmap_file+0x4c1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c1b;
	}
x86_l_4a72:
	/* 0x4a72: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4a76:
	/* 0x4a76: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a7b:
	/* 0x4a7b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4a80:
	/* 0x4a80: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4a85:
	/* 0x4a85: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4a8a:
	/* 0x4a8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a8c:
	/* 0x4a8c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4a90:
	/* 0x4a90: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4a92:
	/* 0x4a92: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4a98:
	/* 0x4a98: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4a9a:
	/* 0x4a9a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4a9c:
	/* 0x4a9c: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_4aa2:
	/* 0x4aa2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4aa7:
	/* 0x4aa7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4aad:
	/* 0x4aad: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ab0:
	/* 0x4ab0: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4ab2:
	/* 0x4ab2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4ab7:
	/* 0x4ab7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ab9:
	/* 0x4ab9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4abc:
	/* 0x4abc: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_4ac2:
	/* 0x4ac2: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4ac5:
	/* 0x4ac5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4acb:
	/* 0x4acb: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4ad0:
	/* 0x4ad0: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4ad2:
	/* 0x4ad2: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ad7:
	/* 0x4ad7: jmp    4c97 <trace_security_mmap_file+0x4c97> */
	goto x86_l_4c97;
x86_l_4adc:
	/* 0x4adc: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4adf:
	/* 0x4adf: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_4ae5:
	/* 0x4ae5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae9:
	/* 0x4ae9: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4aee:
	/* 0x4aee: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_4af4:
	/* 0x4af4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4af8:
	/* 0x4af8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4afd:
	/* 0x4afd: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b02:
	/* 0x4b02: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b07:
	/* 0x4b07: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b0b:
	/* 0x4b0b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b0f:
	/* 0x4b0f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b14:
	/* 0x4b14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b16:
	/* 0x4b16: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b1a:
	/* 0x4b1a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4b1d:
	/* 0x4b1d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b22:
	/* 0x4b22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b27:
	/* 0x4b27: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b2b:
	/* 0x4b2b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b30:
	/* 0x4b30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b32:
	/* 0x4b32: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b36:
	/* 0x4b36: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4b3b:
	/* 0x4b3b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4b40:
	/* 0x4b40: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b45:
	/* 0x4b45: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b49:
	/* 0x4b49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b4e:
	/* 0x4b4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b50:
	/* 0x4b50: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b54:
	/* 0x4b54: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4b58:
	/* 0x4b58: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b5d:
	/* 0x4b5d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b62:
	/* 0x4b62: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b67:
	/* 0x4b67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b6c:
	/* 0x4b6c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4b6f:
	/* 0x4b6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b71:
	/* 0x4b71: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b76:
	/* 0x4b76: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b7b:
	/* 0x4b7b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4b7f:
	/* 0x4b7f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b84:
	/* 0x4b84: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4b89:
	/* 0x4b89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4b8e:
	/* 0x4b8e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b93:
	/* 0x4b93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b95:
	/* 0x4b95: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b9a:
	/* 0x4b9a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4b9d:
	/* 0x4b9d: je     4d5a <trace_security_mmap_file+0x4d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d5a;
	}
x86_l_4ba3:
	/* 0x4ba3: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ba8:
	/* 0x4ba8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4bab:
	/* 0x4bab: je     4d5a <trace_security_mmap_file+0x4d5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d5a;
	}
x86_l_4bb1:
	/* 0x4bb1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4bb5:
	/* 0x4bb5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4bba:
	/* 0x4bba: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4bbf:
	/* 0x4bbf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4bc4:
	/* 0x4bc4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4bc9:
	/* 0x4bc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bcb:
	/* 0x4bcb: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4bcf:
	/* 0x4bcf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4bd1:
	/* 0x4bd1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4bd7:
	/* 0x4bd7: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4bd9:
	/* 0x4bd9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4bdb:
	/* 0x4bdb: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_4be1:
	/* 0x4be1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4be6:
	/* 0x4be6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4bec:
	/* 0x4bec: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4bef:
	/* 0x4bef: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4bf1:
	/* 0x4bf1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4bf6:
	/* 0x4bf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bf8:
	/* 0x4bf8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bfb:
	/* 0x4bfb: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_4c01:
	/* 0x4c01: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4c04:
	/* 0x4c04: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4c0a:
	/* 0x4c0a: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4c0f:
	/* 0x4c0f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4c11:
	/* 0x4c11: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c16:
	/* 0x4c16: jmp    4dd6 <trace_security_mmap_file+0x4dd6> */
	goto x86_l_4dd6;
x86_l_4c1b:
	/* 0x4c1b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4c1e:
	/* 0x4c1e: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_4c24:
	/* 0x4c24: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c28:
	/* 0x4c28: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4c2d:
	/* 0x4c2d: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_4c33:
	/* 0x4c33: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c37:
	/* 0x4c37: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c3c:
	/* 0x4c3c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c41:
	/* 0x4c41: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c46:
	/* 0x4c46: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c4a:
	/* 0x4c4a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4c4e:
	/* 0x4c4e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c53:
	/* 0x4c53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c55:
	/* 0x4c55: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c59:
	/* 0x4c59: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4c5c:
	/* 0x4c5c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c61:
	/* 0x4c61: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c66:
	/* 0x4c66: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c6a:
	/* 0x4c6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c6f:
	/* 0x4c6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c71:
	/* 0x4c71: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c75:
	/* 0x4c75: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c7a:
	/* 0x4c7a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4c7f:
	/* 0x4c7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4c84:
	/* 0x4c84: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c88:
	/* 0x4c88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4c8d:
	/* 0x4c8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c8f:
	/* 0x4c8f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c93:
	/* 0x4c93: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4c97:
	/* 0x4c97: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c9c:
	/* 0x4c9c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4ca1:
	/* 0x4ca1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ca6:
	/* 0x4ca6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cab:
	/* 0x4cab: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4cae:
	/* 0x4cae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb0:
	/* 0x4cb0: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4cb5:
	/* 0x4cb5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cba:
	/* 0x4cba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4cbe:
	/* 0x4cbe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4cc3:
	/* 0x4cc3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4cc8:
	/* 0x4cc8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ccd:
	/* 0x4ccd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cd2:
	/* 0x4cd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cd4:
	/* 0x4cd4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cd9:
	/* 0x4cd9: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4cdc:
	/* 0x4cdc: je     4e99 <trace_security_mmap_file+0x4e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e99;
	}
x86_l_4ce2:
	/* 0x4ce2: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ce7:
	/* 0x4ce7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4cea:
	/* 0x4cea: je     4e99 <trace_security_mmap_file+0x4e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e99;
	}
x86_l_4cf0:
	/* 0x4cf0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4cf4:
	/* 0x4cf4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4cf9:
	/* 0x4cf9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4cfe:
	/* 0x4cfe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d03:
	/* 0x4d03: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4d08:
	/* 0x4d08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d0a:
	/* 0x4d0a: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4d0e:
	/* 0x4d0e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4d10:
	/* 0x4d10: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4d16:
	/* 0x4d16: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4d18:
	/* 0x4d18: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d1a:
	/* 0x4d1a: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_4d20:
	/* 0x4d20: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d25:
	/* 0x4d25: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4d2b:
	/* 0x4d2b: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4d2e:
	/* 0x4d2e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4d30:
	/* 0x4d30: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4d35:
	/* 0x4d35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d37:
	/* 0x4d37: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4d3a:
	/* 0x4d3a: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_4d40:
	/* 0x4d40: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4d43:
	/* 0x4d43: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4d49:
	/* 0x4d49: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4d4e:
	/* 0x4d4e: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d50:
	/* 0x4d50: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d55:
	/* 0x4d55: jmp    4f15 <trace_security_mmap_file+0x4f15> */
	goto x86_l_4f15;
x86_l_4d5a:
	/* 0x4d5a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4d5d:
	/* 0x4d5d: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_4d63:
	/* 0x4d63: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d67:
	/* 0x4d67: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4d6c:
	/* 0x4d6c: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_4d72:
	/* 0x4d72: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d76:
	/* 0x4d76: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d7b:
	/* 0x4d7b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4d80:
	/* 0x4d80: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4d85:
	/* 0x4d85: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d89:
	/* 0x4d89: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4d8d:
	/* 0x4d8d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d92:
	/* 0x4d92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d94:
	/* 0x4d94: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d98:
	/* 0x4d98: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d9b:
	/* 0x4d9b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4da0:
	/* 0x4da0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4da5:
	/* 0x4da5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4da9:
	/* 0x4da9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dae:
	/* 0x4dae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db0:
	/* 0x4db0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4db4:
	/* 0x4db4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4db9:
	/* 0x4db9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4dbe:
	/* 0x4dbe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4dc3:
	/* 0x4dc3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dc7:
	/* 0x4dc7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dcc:
	/* 0x4dcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dce:
	/* 0x4dce: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dd2:
	/* 0x4dd2: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4dd6:
	/* 0x4dd6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ddb:
	/* 0x4ddb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4de0:
	/* 0x4de0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4de5:
	/* 0x4de5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4dea:
	/* 0x4dea: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_4ded:
	/* 0x4ded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4def:
	/* 0x4def: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4df4:
	/* 0x4df4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4df9:
	/* 0x4df9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4dfd:
	/* 0x4dfd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e02:
	/* 0x4e02: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e07:
	/* 0x4e07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e0c:
	/* 0x4e0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e11:
	/* 0x4e11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e13:
	/* 0x4e13: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e18:
	/* 0x4e18: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4e1b:
	/* 0x4e1b: je     4fd8 <trace_security_mmap_file+0x4fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fd8;
	}
x86_l_4e21:
	/* 0x4e21: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e26:
	/* 0x4e26: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4e29:
	/* 0x4e29: je     4fd8 <trace_security_mmap_file+0x4fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fd8;
	}
x86_l_4e2f:
	/* 0x4e2f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e33:
	/* 0x4e33: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e38:
	/* 0x4e38: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4e3d:
	/* 0x4e3d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4e42:
	/* 0x4e42: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4e47:
	/* 0x4e47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e49:
	/* 0x4e49: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4e4d:
	/* 0x4e4d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4e4f:
	/* 0x4e4f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4e55:
	/* 0x4e55: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4e57:
	/* 0x4e57: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e59:
	/* 0x4e59: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_4e5f:
	/* 0x4e5f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4e64:
	/* 0x4e64: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4e6a:
	/* 0x4e6a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4e6d:
	/* 0x4e6d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4e6f:
	/* 0x4e6f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4e74:
	/* 0x4e74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e76:
	/* 0x4e76: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4e79:
	/* 0x4e79: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_4e7f:
	/* 0x4e7f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4e82:
	/* 0x4e82: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4e88:
	/* 0x4e88: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4e8d:
	/* 0x4e8d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4e8f:
	/* 0x4e8f: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e94:
	/* 0x4e94: jmp    5054 <trace_security_mmap_file+0x5054> */
	return 20564ULL;
x86_l_4e99:
	/* 0x4e99: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4e9c:
	/* 0x4e9c: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_4ea2:
	/* 0x4ea2: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ea6:
	/* 0x4ea6: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4eab:
	/* 0x4eab: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_4eb1:
	/* 0x4eb1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4eb5:
	/* 0x4eb5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4eba:
	/* 0x4eba: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ebf:
	/* 0x4ebf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ec4:
	/* 0x4ec4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ec8:
	/* 0x4ec8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4ecc:
	/* 0x4ecc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ed1:
	/* 0x4ed1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ed3:
	/* 0x4ed3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ed7:
	/* 0x4ed7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4eda:
	/* 0x4eda: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4edf:
	/* 0x4edf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4ee4:
	/* 0x4ee4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ee8:
	/* 0x4ee8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4eed:
	/* 0x4eed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4eef:
	/* 0x4eef: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ef3:
	/* 0x4ef3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ef8:
	/* 0x4ef8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4efd:
	/* 0x4efd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f02:
	/* 0x4f02: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f06:
	/* 0x4f06: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f0b:
	/* 0x4f0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0d:
	/* 0x4f0d: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f11:
	/* 0x4f11: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f15:
	/* 0x4f15: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f1a:
	/* 0x4f1a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f1f:
	/* 0x4f1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f24:
	/* 0x4f24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f29:
	/* 0x4f29: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_4f2c:
	/* 0x4f2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f2e:
	/* 0x4f2e: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f33:
	/* 0x4f33: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f38:
	/* 0x4f38: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_4f3c:
	/* 0x4f3c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f41:
	/* 0x4f41: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4f46:
	/* 0x4f46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f4b:
	/* 0x4f4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f50:
	/* 0x4f50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f52:
	/* 0x4f52: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f57:
	/* 0x4f57: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4f5a:
	/* 0x4f5a: je     5117 <trace_security_mmap_file+0x5117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20759ULL;
	}
x86_l_4f60:
	/* 0x4f60: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f65:
	/* 0x4f65: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4f68:
	/* 0x4f68: je     5117 <trace_security_mmap_file+0x5117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 20759ULL;
	}
x86_l_4f6e:
	/* 0x4f6e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4f72:
	/* 0x4f72: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f77:
	/* 0x4f77: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4f7c:
	/* 0x4f7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4f81:
	/* 0x4f81: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4f86:
	/* 0x4f86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f88:
	/* 0x4f88: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4f8c:
	/* 0x4f8c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4f8e:
	/* 0x4f8e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f94:
	/* 0x4f94: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_4f96:
	/* 0x4f96: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4f98:
	/* 0x4f98: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_4f9e:
	/* 0x4f9e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4fa3:
	/* 0x4fa3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_4fa9:
	/* 0x4fa9: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4fac:
	/* 0x4fac: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_4fae:
	/* 0x4fae: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_4fb3:
	/* 0x4fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fb5:
	/* 0x4fb5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4fb8:
	/* 0x4fb8: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_4fbe:
	/* 0x4fbe: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_4fc1:
	/* 0x4fc1: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_4fc7:
	/* 0x4fc7: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_4fcc:
	/* 0x4fcc: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4fce:
	/* 0x4fce: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fd3:
	/* 0x4fd3: jmp    5193 <trace_security_mmap_file+0x5193> */
	return 20883ULL;
x86_l_4fd8:
	/* 0x4fd8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4fdb:
	/* 0x4fdb: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_4fe1:
	/* 0x4fe1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fe5:
	/* 0x4fe5: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_4fea:
	/* 0x4fea: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_4ff0:
	/* 0x4ff0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
	return 20468ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20468ULL: goto x86_l_4ff4;
	case 20473ULL: goto x86_l_4ff9;
	case 20478ULL: goto x86_l_4ffe;
	case 20483ULL: goto x86_l_5003;
	case 20487ULL: goto x86_l_5007;
	case 20491ULL: goto x86_l_500b;
	case 20496ULL: goto x86_l_5010;
	case 20498ULL: goto x86_l_5012;
	case 20502ULL: goto x86_l_5016;
	case 20505ULL: goto x86_l_5019;
	case 20510ULL: goto x86_l_501e;
	case 20515ULL: goto x86_l_5023;
	case 20519ULL: goto x86_l_5027;
	case 20524ULL: goto x86_l_502c;
	case 20526ULL: goto x86_l_502e;
	case 20530ULL: goto x86_l_5032;
	case 20535ULL: goto x86_l_5037;
	case 20540ULL: goto x86_l_503c;
	case 20545ULL: goto x86_l_5041;
	case 20549ULL: goto x86_l_5045;
	case 20554ULL: goto x86_l_504a;
	case 20556ULL: goto x86_l_504c;
	case 20560ULL: goto x86_l_5050;
	case 20564ULL: goto x86_l_5054;
	case 20569ULL: goto x86_l_5059;
	case 20574ULL: goto x86_l_505e;
	case 20579ULL: goto x86_l_5063;
	case 20584ULL: goto x86_l_5068;
	case 20587ULL: goto x86_l_506b;
	case 20589ULL: goto x86_l_506d;
	case 20594ULL: goto x86_l_5072;
	case 20599ULL: goto x86_l_5077;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20613ULL: goto x86_l_5085;
	case 20618ULL: goto x86_l_508a;
	case 20623ULL: goto x86_l_508f;
	case 20625ULL: goto x86_l_5091;
	case 20630ULL: goto x86_l_5096;
	case 20633ULL: goto x86_l_5099;
	case 20639ULL: goto x86_l_509f;
	case 20644ULL: goto x86_l_50a4;
	case 20647ULL: goto x86_l_50a7;
	case 20653ULL: goto x86_l_50ad;
	case 20657ULL: goto x86_l_50b1;
	case 20662ULL: goto x86_l_50b6;
	case 20667ULL: goto x86_l_50bb;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20679ULL: goto x86_l_50c7;
	case 20683ULL: goto x86_l_50cb;
	case 20685ULL: goto x86_l_50cd;
	case 20691ULL: goto x86_l_50d3;
	case 20693ULL: goto x86_l_50d5;
	case 20695ULL: goto x86_l_50d7;
	case 20701ULL: goto x86_l_50dd;
	case 20706ULL: goto x86_l_50e2;
	case 20712ULL: goto x86_l_50e8;
	case 20715ULL: goto x86_l_50eb;
	case 20717ULL: goto x86_l_50ed;
	case 20722ULL: goto x86_l_50f2;
	case 20724ULL: goto x86_l_50f4;
	case 20727ULL: goto x86_l_50f7;
	case 20733ULL: goto x86_l_50fd;
	case 20736ULL: goto x86_l_5100;
	case 20742ULL: goto x86_l_5106;
	case 20747ULL: goto x86_l_510b;
	case 20749ULL: goto x86_l_510d;
	case 20754ULL: goto x86_l_5112;
	case 20759ULL: goto x86_l_5117;
	case 20762ULL: goto x86_l_511a;
	case 20768ULL: goto x86_l_5120;
	case 20772ULL: goto x86_l_5124;
	case 20777ULL: goto x86_l_5129;
	case 20783ULL: goto x86_l_512f;
	case 20787ULL: goto x86_l_5133;
	case 20792ULL: goto x86_l_5138;
	case 20797ULL: goto x86_l_513d;
	case 20802ULL: goto x86_l_5142;
	case 20806ULL: goto x86_l_5146;
	case 20810ULL: goto x86_l_514a;
	case 20815ULL: goto x86_l_514f;
	case 20817ULL: goto x86_l_5151;
	case 20821ULL: goto x86_l_5155;
	case 20824ULL: goto x86_l_5158;
	case 20829ULL: goto x86_l_515d;
	case 20834ULL: goto x86_l_5162;
	case 20838ULL: goto x86_l_5166;
	case 20843ULL: goto x86_l_516b;
	case 20845ULL: goto x86_l_516d;
	case 20849ULL: goto x86_l_5171;
	case 20854ULL: goto x86_l_5176;
	case 20859ULL: goto x86_l_517b;
	case 20864ULL: goto x86_l_5180;
	case 20868ULL: goto x86_l_5184;
	case 20873ULL: goto x86_l_5189;
	case 20875ULL: goto x86_l_518b;
	case 20879ULL: goto x86_l_518f;
	case 20883ULL: goto x86_l_5193;
	case 20888ULL: goto x86_l_5198;
	case 20893ULL: goto x86_l_519d;
	case 20898ULL: goto x86_l_51a2;
	case 20903ULL: goto x86_l_51a7;
	case 20906ULL: goto x86_l_51aa;
	case 20908ULL: goto x86_l_51ac;
	case 20913ULL: goto x86_l_51b1;
	case 20918ULL: goto x86_l_51b6;
	case 20922ULL: goto x86_l_51ba;
	case 20927ULL: goto x86_l_51bf;
	case 20932ULL: goto x86_l_51c4;
	case 20937ULL: goto x86_l_51c9;
	case 20942ULL: goto x86_l_51ce;
	case 20944ULL: goto x86_l_51d0;
	case 20949ULL: goto x86_l_51d5;
	case 20952ULL: goto x86_l_51d8;
	case 20958ULL: goto x86_l_51de;
	case 20963ULL: goto x86_l_51e3;
	case 20966ULL: goto x86_l_51e6;
	case 20972ULL: goto x86_l_51ec;
	case 20976ULL: goto x86_l_51f0;
	case 20981ULL: goto x86_l_51f5;
	case 20986ULL: goto x86_l_51fa;
	case 20991ULL: goto x86_l_51ff;
	case 20996ULL: goto x86_l_5204;
	case 20998ULL: goto x86_l_5206;
	case 21002ULL: goto x86_l_520a;
	case 21004ULL: goto x86_l_520c;
	case 21010ULL: goto x86_l_5212;
	case 21012ULL: goto x86_l_5214;
	case 21014ULL: goto x86_l_5216;
	case 21020ULL: goto x86_l_521c;
	case 21025ULL: goto x86_l_5221;
	case 21031ULL: goto x86_l_5227;
	case 21034ULL: goto x86_l_522a;
	case 21036ULL: goto x86_l_522c;
	case 21041ULL: goto x86_l_5231;
	case 21043ULL: goto x86_l_5233;
	case 21046ULL: goto x86_l_5236;
	case 21052ULL: goto x86_l_523c;
	case 21055ULL: goto x86_l_523f;
	case 21061ULL: goto x86_l_5245;
	case 21066ULL: goto x86_l_524a;
	case 21068ULL: goto x86_l_524c;
	case 21073ULL: goto x86_l_5251;
	case 21078ULL: goto x86_l_5256;
	case 21081ULL: goto x86_l_5259;
	case 21087ULL: goto x86_l_525f;
	case 21091ULL: goto x86_l_5263;
	case 21096ULL: goto x86_l_5268;
	case 21102ULL: goto x86_l_526e;
	case 21106ULL: goto x86_l_5272;
	case 21111ULL: goto x86_l_5277;
	case 21116ULL: goto x86_l_527c;
	case 21121ULL: goto x86_l_5281;
	case 21125ULL: goto x86_l_5285;
	case 21129ULL: goto x86_l_5289;
	case 21134ULL: goto x86_l_528e;
	case 21136ULL: goto x86_l_5290;
	case 21140ULL: goto x86_l_5294;
	case 21143ULL: goto x86_l_5297;
	case 21148ULL: goto x86_l_529c;
	case 21153ULL: goto x86_l_52a1;
	case 21157ULL: goto x86_l_52a5;
	case 21162ULL: goto x86_l_52aa;
	case 21164ULL: goto x86_l_52ac;
	case 21168ULL: goto x86_l_52b0;
	case 21173ULL: goto x86_l_52b5;
	case 21178ULL: goto x86_l_52ba;
	case 21183ULL: goto x86_l_52bf;
	case 21187ULL: goto x86_l_52c3;
	case 21192ULL: goto x86_l_52c8;
	case 21194ULL: goto x86_l_52ca;
	case 21198ULL: goto x86_l_52ce;
	case 21202ULL: goto x86_l_52d2;
	case 21207ULL: goto x86_l_52d7;
	case 21212ULL: goto x86_l_52dc;
	case 21217ULL: goto x86_l_52e1;
	case 21222ULL: goto x86_l_52e6;
	case 21225ULL: goto x86_l_52e9;
	case 21227ULL: goto x86_l_52eb;
	case 21232ULL: goto x86_l_52f0;
	case 21237ULL: goto x86_l_52f5;
	case 21241ULL: goto x86_l_52f9;
	case 21246ULL: goto x86_l_52fe;
	case 21251ULL: goto x86_l_5303;
	case 21256ULL: goto x86_l_5308;
	case 21261ULL: goto x86_l_530d;
	case 21263ULL: goto x86_l_530f;
	case 21268ULL: goto x86_l_5314;
	case 21271ULL: goto x86_l_5317;
	case 21277ULL: goto x86_l_531d;
	case 21282ULL: goto x86_l_5322;
	case 21285ULL: goto x86_l_5325;
	case 21291ULL: goto x86_l_532b;
	case 21295ULL: goto x86_l_532f;
	case 21300ULL: goto x86_l_5334;
	case 21305ULL: goto x86_l_5339;
	case 21310ULL: goto x86_l_533e;
	case 21315ULL: goto x86_l_5343;
	case 21317ULL: goto x86_l_5345;
	case 21321ULL: goto x86_l_5349;
	case 21323ULL: goto x86_l_534b;
	case 21329ULL: goto x86_l_5351;
	case 21331ULL: goto x86_l_5353;
	case 21333ULL: goto x86_l_5355;
	case 21339ULL: goto x86_l_535b;
	case 21344ULL: goto x86_l_5360;
	case 21350ULL: goto x86_l_5366;
	case 21353ULL: goto x86_l_5369;
	case 21355ULL: goto x86_l_536b;
	case 21360ULL: goto x86_l_5370;
	case 21362ULL: goto x86_l_5372;
	case 21365ULL: goto x86_l_5375;
	case 21371ULL: goto x86_l_537b;
	case 21374ULL: goto x86_l_537e;
	case 21380ULL: goto x86_l_5384;
	case 21385ULL: goto x86_l_5389;
	case 21387ULL: goto x86_l_538b;
	case 21392ULL: goto x86_l_5390;
	case 21397ULL: goto x86_l_5395;
	case 21400ULL: goto x86_l_5398;
	case 21406ULL: goto x86_l_539e;
	case 21410ULL: goto x86_l_53a2;
	case 21415ULL: goto x86_l_53a7;
	case 21421ULL: goto x86_l_53ad;
	case 21425ULL: goto x86_l_53b1;
	case 21430ULL: goto x86_l_53b6;
	case 21435ULL: goto x86_l_53bb;
	case 21440ULL: goto x86_l_53c0;
	case 21444ULL: goto x86_l_53c4;
	case 21448ULL: goto x86_l_53c8;
	case 21453ULL: goto x86_l_53cd;
	case 21455ULL: goto x86_l_53cf;
	case 21459ULL: goto x86_l_53d3;
	case 21462ULL: goto x86_l_53d6;
	case 21467ULL: goto x86_l_53db;
	case 21472ULL: goto x86_l_53e0;
	case 21476ULL: goto x86_l_53e4;
	case 21481ULL: goto x86_l_53e9;
	case 21483ULL: goto x86_l_53eb;
	case 21487ULL: goto x86_l_53ef;
	case 21492ULL: goto x86_l_53f4;
	case 21497ULL: goto x86_l_53f9;
	case 21502ULL: goto x86_l_53fe;
	case 21506ULL: goto x86_l_5402;
	case 21511ULL: goto x86_l_5407;
	case 21513ULL: goto x86_l_5409;
	case 21517ULL: goto x86_l_540d;
	case 21521ULL: goto x86_l_5411;
	case 21526ULL: goto x86_l_5416;
	case 21531ULL: goto x86_l_541b;
	case 21536ULL: goto x86_l_5420;
	case 21541ULL: goto x86_l_5425;
	case 21544ULL: goto x86_l_5428;
	case 21546ULL: goto x86_l_542a;
	case 21551ULL: goto x86_l_542f;
	case 21556ULL: goto x86_l_5434;
	case 21560ULL: goto x86_l_5438;
	case 21565ULL: goto x86_l_543d;
	case 21570ULL: goto x86_l_5442;
	case 21575ULL: goto x86_l_5447;
	case 21580ULL: goto x86_l_544c;
	case 21582ULL: goto x86_l_544e;
	case 21587ULL: goto x86_l_5453;
	case 21590ULL: goto x86_l_5456;
	case 21596ULL: goto x86_l_545c;
	case 21601ULL: goto x86_l_5461;
	case 21604ULL: goto x86_l_5464;
	case 21610ULL: goto x86_l_546a;
	case 21614ULL: goto x86_l_546e;
	case 21619ULL: goto x86_l_5473;
	case 21624ULL: goto x86_l_5478;
	case 21629ULL: goto x86_l_547d;
	case 21634ULL: goto x86_l_5482;
	case 21636ULL: goto x86_l_5484;
	case 21640ULL: goto x86_l_5488;
	case 21642ULL: goto x86_l_548a;
	case 21648ULL: goto x86_l_5490;
	case 21650ULL: goto x86_l_5492;
	case 21652ULL: goto x86_l_5494;
	case 21658ULL: goto x86_l_549a;
	case 21663ULL: goto x86_l_549f;
	case 21669ULL: goto x86_l_54a5;
	case 21672ULL: goto x86_l_54a8;
	case 21674ULL: goto x86_l_54aa;
	case 21679ULL: goto x86_l_54af;
	case 21681ULL: goto x86_l_54b1;
	case 21684ULL: goto x86_l_54b4;
	case 21690ULL: goto x86_l_54ba;
	case 21693ULL: goto x86_l_54bd;
	case 21699ULL: goto x86_l_54c3;
	case 21704ULL: goto x86_l_54c8;
	case 21706ULL: goto x86_l_54ca;
	case 21711ULL: goto x86_l_54cf;
	case 21716ULL: goto x86_l_54d4;
	case 21719ULL: goto x86_l_54d7;
	case 21725ULL: goto x86_l_54dd;
	case 21729ULL: goto x86_l_54e1;
	case 21734ULL: goto x86_l_54e6;
	case 21740ULL: goto x86_l_54ec;
	case 21744ULL: goto x86_l_54f0;
	case 21749ULL: goto x86_l_54f5;
	case 21754ULL: goto x86_l_54fa;
	case 21759ULL: goto x86_l_54ff;
	case 21763ULL: goto x86_l_5503;
	case 21767ULL: goto x86_l_5507;
	case 21772ULL: goto x86_l_550c;
	case 21774ULL: goto x86_l_550e;
	case 21778ULL: goto x86_l_5512;
	case 21781ULL: goto x86_l_5515;
	case 21786ULL: goto x86_l_551a;
	case 21791ULL: goto x86_l_551f;
	case 21795ULL: goto x86_l_5523;
	case 21800ULL: goto x86_l_5528;
	case 21802ULL: goto x86_l_552a;
	case 21806ULL: goto x86_l_552e;
	case 21811ULL: goto x86_l_5533;
	case 21816ULL: goto x86_l_5538;
	case 21821ULL: goto x86_l_553d;
	case 21825ULL: goto x86_l_5541;
	case 21830ULL: goto x86_l_5546;
	case 21832ULL: goto x86_l_5548;
	case 21836ULL: goto x86_l_554c;
	case 21840ULL: goto x86_l_5550;
	case 21845ULL: goto x86_l_5555;
	case 21850ULL: goto x86_l_555a;
	case 21855ULL: goto x86_l_555f;
	case 21860ULL: goto x86_l_5564;
	case 21863ULL: goto x86_l_5567;
	case 21865ULL: goto x86_l_5569;
	case 21870ULL: goto x86_l_556e;
	case 21875ULL: goto x86_l_5573;
	case 21879ULL: goto x86_l_5577;
	case 21884ULL: goto x86_l_557c;
	case 21889ULL: goto x86_l_5581;
	case 21894ULL: goto x86_l_5586;
	case 21899ULL: goto x86_l_558b;
	case 21901ULL: goto x86_l_558d;
	case 21906ULL: goto x86_l_5592;
	case 21909ULL: goto x86_l_5595;
	case 21915ULL: goto x86_l_559b;
	case 21920ULL: goto x86_l_55a0;
	case 21923ULL: goto x86_l_55a3;
	case 21929ULL: goto x86_l_55a9;
	case 21933ULL: goto x86_l_55ad;
	case 21938ULL: goto x86_l_55b2;
	case 21943ULL: goto x86_l_55b7;
	case 21948ULL: goto x86_l_55bc;
	case 21953ULL: goto x86_l_55c1;
	case 21955ULL: goto x86_l_55c3;
	case 21959ULL: goto x86_l_55c7;
	case 21961ULL: goto x86_l_55c9;
	case 21967ULL: goto x86_l_55cf;
	case 21969ULL: goto x86_l_55d1;
	case 21971ULL: goto x86_l_55d3;
	case 21977ULL: goto x86_l_55d9;
	case 21982ULL: goto x86_l_55de;
	case 21988ULL: goto x86_l_55e4;
	case 21991ULL: goto x86_l_55e7;
	case 21993ULL: goto x86_l_55e9;
	case 21998ULL: goto x86_l_55ee;
	case 22000ULL: goto x86_l_55f0;
	case 22003ULL: goto x86_l_55f3;
	case 22009ULL: goto x86_l_55f9;
	case 22012ULL: goto x86_l_55fc;
	case 22018ULL: goto x86_l_5602;
	case 22023ULL: goto x86_l_5607;
	case 22025ULL: goto x86_l_5609;
	case 22030ULL: goto x86_l_560e;
	case 22035ULL: goto x86_l_5613;
	case 22038ULL: goto x86_l_5616;
	case 22044ULL: goto x86_l_561c;
	case 22048ULL: goto x86_l_5620;
	case 22053ULL: goto x86_l_5625;
	case 22059ULL: goto x86_l_562b;
	case 22063ULL: goto x86_l_562f;
	case 22068ULL: goto x86_l_5634;
	case 22073ULL: goto x86_l_5639;
	case 22078ULL: goto x86_l_563e;
	case 22082ULL: goto x86_l_5642;
	case 22086ULL: goto x86_l_5646;
	case 22091ULL: goto x86_l_564b;
	case 22093ULL: goto x86_l_564d;
	case 22097ULL: goto x86_l_5651;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4ff4:
	/* 0x4ff4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ff9:
	/* 0x4ff9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_4ffe:
	/* 0x4ffe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5003:
	/* 0x5003: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5007:
	/* 0x5007: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_500b:
	/* 0x500b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5010:
	/* 0x5010: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5012:
	/* 0x5012: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5016:
	/* 0x5016: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5019:
	/* 0x5019: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_501e:
	/* 0x501e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5023:
	/* 0x5023: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5027:
	/* 0x5027: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_502c:
	/* 0x502c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_502e:
	/* 0x502e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5032:
	/* 0x5032: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5037:
	/* 0x5037: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_503c:
	/* 0x503c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5041:
	/* 0x5041: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5045:
	/* 0x5045: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_504a:
	/* 0x504a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_504c:
	/* 0x504c: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5050:
	/* 0x5050: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5054:
	/* 0x5054: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5059:
	/* 0x5059: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_505e:
	/* 0x505e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5063:
	/* 0x5063: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5068:
	/* 0x5068: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_506b:
	/* 0x506b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_506d:
	/* 0x506d: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5072:
	/* 0x5072: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5077:
	/* 0x5077: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_507b:
	/* 0x507b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5080:
	/* 0x5080: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5085:
	/* 0x5085: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_508a:
	/* 0x508a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_508f:
	/* 0x508f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5091:
	/* 0x5091: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5096:
	/* 0x5096: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5099:
	/* 0x5099: je     5256 <trace_security_mmap_file+0x5256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5256;
	}
x86_l_509f:
	/* 0x509f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50a4:
	/* 0x50a4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_50a7:
	/* 0x50a7: je     5256 <trace_security_mmap_file+0x5256> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5256;
	}
x86_l_50ad:
	/* 0x50ad: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_50b1:
	/* 0x50b1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50b6:
	/* 0x50b6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_50bb:
	/* 0x50bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_50c0:
	/* 0x50c0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_50c5:
	/* 0x50c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c7:
	/* 0x50c7: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_50cb:
	/* 0x50cb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_50cd:
	/* 0x50cd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_50d3:
	/* 0x50d3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_50d5:
	/* 0x50d5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_50d7:
	/* 0x50d7: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_50dd:
	/* 0x50dd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_50e2:
	/* 0x50e2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_50e8:
	/* 0x50e8: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_50eb:
	/* 0x50eb: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_50ed:
	/* 0x50ed: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_50f2:
	/* 0x50f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50f4:
	/* 0x50f4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_50f7:
	/* 0x50f7: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_50fd:
	/* 0x50fd: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5100:
	/* 0x5100: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5106:
	/* 0x5106: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_510b:
	/* 0x510b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_510d:
	/* 0x510d: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5112:
	/* 0x5112: jmp    52d2 <trace_security_mmap_file+0x52d2> */
	goto x86_l_52d2;
x86_l_5117:
	/* 0x5117: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_511a:
	/* 0x511a: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_5120:
	/* 0x5120: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5124:
	/* 0x5124: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5129:
	/* 0x5129: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_512f:
	/* 0x512f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5133:
	/* 0x5133: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5138:
	/* 0x5138: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_513d:
	/* 0x513d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5142:
	/* 0x5142: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5146:
	/* 0x5146: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_514a:
	/* 0x514a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_514f:
	/* 0x514f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5151:
	/* 0x5151: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5155:
	/* 0x5155: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5158:
	/* 0x5158: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_515d:
	/* 0x515d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5162:
	/* 0x5162: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5166:
	/* 0x5166: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_516b:
	/* 0x516b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_516d:
	/* 0x516d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5171:
	/* 0x5171: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5176:
	/* 0x5176: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_517b:
	/* 0x517b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5180:
	/* 0x5180: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5184:
	/* 0x5184: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5189:
	/* 0x5189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518b:
	/* 0x518b: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_518f:
	/* 0x518f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5193:
	/* 0x5193: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5198:
	/* 0x5198: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_519d:
	/* 0x519d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51a2:
	/* 0x51a2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51a7:
	/* 0x51a7: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_51aa:
	/* 0x51aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51ac:
	/* 0x51ac: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51b1:
	/* 0x51b1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51b6:
	/* 0x51b6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_51ba:
	/* 0x51ba: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51bf:
	/* 0x51bf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_51c4:
	/* 0x51c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51c9:
	/* 0x51c9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_51ce:
	/* 0x51ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51d0:
	/* 0x51d0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d5:
	/* 0x51d5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_51d8:
	/* 0x51d8: je     5395 <trace_security_mmap_file+0x5395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5395;
	}
x86_l_51de:
	/* 0x51de: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51e3:
	/* 0x51e3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_51e6:
	/* 0x51e6: je     5395 <trace_security_mmap_file+0x5395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5395;
	}
x86_l_51ec:
	/* 0x51ec: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_51f0:
	/* 0x51f0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51f5:
	/* 0x51f5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_51fa:
	/* 0x51fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_51ff:
	/* 0x51ff: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5204:
	/* 0x5204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5206:
	/* 0x5206: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_520a:
	/* 0x520a: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_520c:
	/* 0x520c: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5212:
	/* 0x5212: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5214:
	/* 0x5214: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5216:
	/* 0x5216: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_521c:
	/* 0x521c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5221:
	/* 0x5221: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5227:
	/* 0x5227: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_522a:
	/* 0x522a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_522c:
	/* 0x522c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5231:
	/* 0x5231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5233:
	/* 0x5233: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5236:
	/* 0x5236: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_523c:
	/* 0x523c: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_523f:
	/* 0x523f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5245:
	/* 0x5245: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_524a:
	/* 0x524a: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_524c:
	/* 0x524c: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5251:
	/* 0x5251: jmp    5411 <trace_security_mmap_file+0x5411> */
	goto x86_l_5411;
x86_l_5256:
	/* 0x5256: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5259:
	/* 0x5259: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_525f:
	/* 0x525f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5263:
	/* 0x5263: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5268:
	/* 0x5268: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_526e:
	/* 0x526e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5272:
	/* 0x5272: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5277:
	/* 0x5277: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_527c:
	/* 0x527c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5281:
	/* 0x5281: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5285:
	/* 0x5285: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5289:
	/* 0x5289: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_528e:
	/* 0x528e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5290:
	/* 0x5290: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5294:
	/* 0x5294: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5297:
	/* 0x5297: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_529c:
	/* 0x529c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52a1:
	/* 0x52a1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a5:
	/* 0x52a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52aa:
	/* 0x52aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52ac:
	/* 0x52ac: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52b0:
	/* 0x52b0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_52b5:
	/* 0x52b5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_52ba:
	/* 0x52ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52bf:
	/* 0x52bf: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c3:
	/* 0x52c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52c8:
	/* 0x52c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52ca:
	/* 0x52ca: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52ce:
	/* 0x52ce: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_52d2:
	/* 0x52d2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52d7:
	/* 0x52d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_52dc:
	/* 0x52dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52e1:
	/* 0x52e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52e6:
	/* 0x52e6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_52e9:
	/* 0x52e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52eb:
	/* 0x52eb: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52f0:
	/* 0x52f0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52f5:
	/* 0x52f5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_52f9:
	/* 0x52f9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52fe:
	/* 0x52fe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5303:
	/* 0x5303: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5308:
	/* 0x5308: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_530d:
	/* 0x530d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_530f:
	/* 0x530f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5314:
	/* 0x5314: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5317:
	/* 0x5317: je     54d4 <trace_security_mmap_file+0x54d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54d4;
	}
x86_l_531d:
	/* 0x531d: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5322:
	/* 0x5322: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5325:
	/* 0x5325: je     54d4 <trace_security_mmap_file+0x54d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_54d4;
	}
x86_l_532b:
	/* 0x532b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_532f:
	/* 0x532f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5334:
	/* 0x5334: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5339:
	/* 0x5339: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_533e:
	/* 0x533e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5343:
	/* 0x5343: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5345:
	/* 0x5345: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5349:
	/* 0x5349: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_534b:
	/* 0x534b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5351:
	/* 0x5351: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5353:
	/* 0x5353: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5355:
	/* 0x5355: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_535b:
	/* 0x535b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5360:
	/* 0x5360: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5366:
	/* 0x5366: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5369:
	/* 0x5369: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_536b:
	/* 0x536b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5370:
	/* 0x5370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5372:
	/* 0x5372: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5375:
	/* 0x5375: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_537b:
	/* 0x537b: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_537e:
	/* 0x537e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5384:
	/* 0x5384: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5389:
	/* 0x5389: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_538b:
	/* 0x538b: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5390:
	/* 0x5390: jmp    5550 <trace_security_mmap_file+0x5550> */
	goto x86_l_5550;
x86_l_5395:
	/* 0x5395: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5398:
	/* 0x5398: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_539e:
	/* 0x539e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53a2:
	/* 0x53a2: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_53a7:
	/* 0x53a7: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_53ad:
	/* 0x53ad: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_53b1:
	/* 0x53b1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53b6:
	/* 0x53b6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
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
	/* 0x53c8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53cd:
	/* 0x53cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53cf:
	/* 0x53cf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53d3:
	/* 0x53d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_53d6:
	/* 0x53d6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53db:
	/* 0x53db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53e0:
	/* 0x53e0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53e4:
	/* 0x53e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_53e9:
	/* 0x53e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53eb:
	/* 0x53eb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53ef:
	/* 0x53ef: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_53f4:
	/* 0x53f4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_53f9:
	/* 0x53f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_53fe:
	/* 0x53fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5402:
	/* 0x5402: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5407:
	/* 0x5407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5409:
	/* 0x5409: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_540d:
	/* 0x540d: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5411:
	/* 0x5411: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5416:
	/* 0x5416: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_541b:
	/* 0x541b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5420:
	/* 0x5420: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5425:
	/* 0x5425: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5428:
	/* 0x5428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_542a:
	/* 0x542a: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_542f:
	/* 0x542f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5434:
	/* 0x5434: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5438:
	/* 0x5438: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_543d:
	/* 0x543d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5442:
	/* 0x5442: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5447:
	/* 0x5447: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_544c:
	/* 0x544c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_544e:
	/* 0x544e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5453:
	/* 0x5453: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5456:
	/* 0x5456: je     5613 <trace_security_mmap_file+0x5613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5613;
	}
x86_l_545c:
	/* 0x545c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5461:
	/* 0x5461: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5464:
	/* 0x5464: je     5613 <trace_security_mmap_file+0x5613> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5613;
	}
x86_l_546a:
	/* 0x546a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_546e:
	/* 0x546e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5473:
	/* 0x5473: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5478:
	/* 0x5478: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_547d:
	/* 0x547d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5482:
	/* 0x5482: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5484:
	/* 0x5484: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5488:
	/* 0x5488: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_548a:
	/* 0x548a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5490:
	/* 0x5490: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5492:
	/* 0x5492: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5494:
	/* 0x5494: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_549a:
	/* 0x549a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_549f:
	/* 0x549f: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_54a5:
	/* 0x54a5: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54a8:
	/* 0x54a8: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_54aa:
	/* 0x54aa: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_54af:
	/* 0x54af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54b1:
	/* 0x54b1: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_54b4:
	/* 0x54b4: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_54ba:
	/* 0x54ba: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_54bd:
	/* 0x54bd: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_54c3:
	/* 0x54c3: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_54c8:
	/* 0x54c8: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_54ca:
	/* 0x54ca: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54cf:
	/* 0x54cf: jmp    568f <trace_security_mmap_file+0x568f> */
	return 22159ULL;
x86_l_54d4:
	/* 0x54d4: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_54d7:
	/* 0x54d7: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_54dd:
	/* 0x54dd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54e1:
	/* 0x54e1: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_54e6:
	/* 0x54e6: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_54ec:
	/* 0x54ec: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_54f0:
	/* 0x54f0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f5:
	/* 0x54f5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_54fa:
	/* 0x54fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_54ff:
	/* 0x54ff: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5503:
	/* 0x5503: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5507:
	/* 0x5507: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_550c:
	/* 0x550c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_550e:
	/* 0x550e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5512:
	/* 0x5512: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5515:
	/* 0x5515: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_551a:
	/* 0x551a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_551f:
	/* 0x551f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5523:
	/* 0x5523: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5528:
	/* 0x5528: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552a:
	/* 0x552a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_552e:
	/* 0x552e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5533:
	/* 0x5533: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5538:
	/* 0x5538: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_553d:
	/* 0x553d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5541:
	/* 0x5541: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5546:
	/* 0x5546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5548:
	/* 0x5548: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_554c:
	/* 0x554c: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5550:
	/* 0x5550: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5555:
	/* 0x5555: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_555a:
	/* 0x555a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_555f:
	/* 0x555f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5564:
	/* 0x5564: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5567:
	/* 0x5567: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5569:
	/* 0x5569: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_556e:
	/* 0x556e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5573:
	/* 0x5573: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5577:
	/* 0x5577: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_557c:
	/* 0x557c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5581:
	/* 0x5581: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5586:
	/* 0x5586: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_558b:
	/* 0x558b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_558d:
	/* 0x558d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5592:
	/* 0x5592: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5595:
	/* 0x5595: je     5752 <trace_security_mmap_file+0x5752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22354ULL;
	}
x86_l_559b:
	/* 0x559b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55a0:
	/* 0x55a0: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_55a3:
	/* 0x55a3: je     5752 <trace_security_mmap_file+0x5752> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22354ULL;
	}
x86_l_55a9:
	/* 0x55a9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_55ad:
	/* 0x55ad: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55b2:
	/* 0x55b2: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_55b7:
	/* 0x55b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_55bc:
	/* 0x55bc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_55c1:
	/* 0x55c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55c3:
	/* 0x55c3: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_55c7:
	/* 0x55c7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_55c9:
	/* 0x55c9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_55cf:
	/* 0x55cf: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_55d1:
	/* 0x55d1: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_55d3:
	/* 0x55d3: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_55d9:
	/* 0x55d9: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_55de:
	/* 0x55de: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_55e4:
	/* 0x55e4: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_55e7:
	/* 0x55e7: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_55e9:
	/* 0x55e9: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_55ee:
	/* 0x55ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55f0:
	/* 0x55f0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_55f3:
	/* 0x55f3: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_55f9:
	/* 0x55f9: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_55fc:
	/* 0x55fc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5602:
	/* 0x5602: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5607:
	/* 0x5607: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5609:
	/* 0x5609: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_560e:
	/* 0x560e: jmp    57ce <trace_security_mmap_file+0x57ce> */
	return 22478ULL;
x86_l_5613:
	/* 0x5613: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5616:
	/* 0x5616: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_561c:
	/* 0x561c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5620:
	/* 0x5620: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5625:
	/* 0x5625: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_562b:
	/* 0x562b: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_562f:
	/* 0x562f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5634:
	/* 0x5634: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5639:
	/* 0x5639: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_563e:
	/* 0x563e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5642:
	/* 0x5642: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5646:
	/* 0x5646: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_564b:
	/* 0x564b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564d:
	/* 0x564d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5651:
	/* 0x5651: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
	return 22100ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 22100ULL: goto x86_l_5654;
	case 22105ULL: goto x86_l_5659;
	case 22110ULL: goto x86_l_565e;
	case 22114ULL: goto x86_l_5662;
	case 22119ULL: goto x86_l_5667;
	case 22121ULL: goto x86_l_5669;
	case 22125ULL: goto x86_l_566d;
	case 22130ULL: goto x86_l_5672;
	case 22135ULL: goto x86_l_5677;
	case 22140ULL: goto x86_l_567c;
	case 22144ULL: goto x86_l_5680;
	case 22149ULL: goto x86_l_5685;
	case 22151ULL: goto x86_l_5687;
	case 22155ULL: goto x86_l_568b;
	case 22159ULL: goto x86_l_568f;
	case 22164ULL: goto x86_l_5694;
	case 22169ULL: goto x86_l_5699;
	case 22174ULL: goto x86_l_569e;
	case 22179ULL: goto x86_l_56a3;
	case 22182ULL: goto x86_l_56a6;
	case 22184ULL: goto x86_l_56a8;
	case 22189ULL: goto x86_l_56ad;
	case 22194ULL: goto x86_l_56b2;
	case 22198ULL: goto x86_l_56b6;
	case 22203ULL: goto x86_l_56bb;
	case 22208ULL: goto x86_l_56c0;
	case 22213ULL: goto x86_l_56c5;
	case 22218ULL: goto x86_l_56ca;
	case 22220ULL: goto x86_l_56cc;
	case 22225ULL: goto x86_l_56d1;
	case 22228ULL: goto x86_l_56d4;
	case 22234ULL: goto x86_l_56da;
	case 22239ULL: goto x86_l_56df;
	case 22242ULL: goto x86_l_56e2;
	case 22248ULL: goto x86_l_56e8;
	case 22252ULL: goto x86_l_56ec;
	case 22257ULL: goto x86_l_56f1;
	case 22262ULL: goto x86_l_56f6;
	case 22267ULL: goto x86_l_56fb;
	case 22272ULL: goto x86_l_5700;
	case 22274ULL: goto x86_l_5702;
	case 22278ULL: goto x86_l_5706;
	case 22280ULL: goto x86_l_5708;
	case 22286ULL: goto x86_l_570e;
	case 22288ULL: goto x86_l_5710;
	case 22290ULL: goto x86_l_5712;
	case 22296ULL: goto x86_l_5718;
	case 22301ULL: goto x86_l_571d;
	case 22307ULL: goto x86_l_5723;
	case 22310ULL: goto x86_l_5726;
	case 22312ULL: goto x86_l_5728;
	case 22317ULL: goto x86_l_572d;
	case 22319ULL: goto x86_l_572f;
	case 22322ULL: goto x86_l_5732;
	case 22328ULL: goto x86_l_5738;
	case 22331ULL: goto x86_l_573b;
	case 22337ULL: goto x86_l_5741;
	case 22342ULL: goto x86_l_5746;
	case 22344ULL: goto x86_l_5748;
	case 22349ULL: goto x86_l_574d;
	case 22354ULL: goto x86_l_5752;
	case 22357ULL: goto x86_l_5755;
	case 22363ULL: goto x86_l_575b;
	case 22367ULL: goto x86_l_575f;
	case 22372ULL: goto x86_l_5764;
	case 22378ULL: goto x86_l_576a;
	case 22382ULL: goto x86_l_576e;
	case 22387ULL: goto x86_l_5773;
	case 22392ULL: goto x86_l_5778;
	case 22397ULL: goto x86_l_577d;
	case 22401ULL: goto x86_l_5781;
	case 22405ULL: goto x86_l_5785;
	case 22410ULL: goto x86_l_578a;
	case 22412ULL: goto x86_l_578c;
	case 22416ULL: goto x86_l_5790;
	case 22419ULL: goto x86_l_5793;
	case 22424ULL: goto x86_l_5798;
	case 22429ULL: goto x86_l_579d;
	case 22433ULL: goto x86_l_57a1;
	case 22438ULL: goto x86_l_57a6;
	case 22440ULL: goto x86_l_57a8;
	case 22444ULL: goto x86_l_57ac;
	case 22449ULL: goto x86_l_57b1;
	case 22454ULL: goto x86_l_57b6;
	case 22459ULL: goto x86_l_57bb;
	case 22463ULL: goto x86_l_57bf;
	case 22468ULL: goto x86_l_57c4;
	case 22470ULL: goto x86_l_57c6;
	case 22474ULL: goto x86_l_57ca;
	case 22478ULL: goto x86_l_57ce;
	case 22483ULL: goto x86_l_57d3;
	case 22488ULL: goto x86_l_57d8;
	case 22493ULL: goto x86_l_57dd;
	case 22498ULL: goto x86_l_57e2;
	case 22501ULL: goto x86_l_57e5;
	case 22503ULL: goto x86_l_57e7;
	case 22508ULL: goto x86_l_57ec;
	case 22513ULL: goto x86_l_57f1;
	case 22517ULL: goto x86_l_57f5;
	case 22522ULL: goto x86_l_57fa;
	case 22527ULL: goto x86_l_57ff;
	case 22532ULL: goto x86_l_5804;
	case 22537ULL: goto x86_l_5809;
	case 22539ULL: goto x86_l_580b;
	case 22544ULL: goto x86_l_5810;
	case 22547ULL: goto x86_l_5813;
	case 22553ULL: goto x86_l_5819;
	case 22558ULL: goto x86_l_581e;
	case 22561ULL: goto x86_l_5821;
	case 22567ULL: goto x86_l_5827;
	case 22571ULL: goto x86_l_582b;
	case 22576ULL: goto x86_l_5830;
	case 22581ULL: goto x86_l_5835;
	case 22586ULL: goto x86_l_583a;
	case 22591ULL: goto x86_l_583f;
	case 22593ULL: goto x86_l_5841;
	case 22597ULL: goto x86_l_5845;
	case 22599ULL: goto x86_l_5847;
	case 22605ULL: goto x86_l_584d;
	case 22607ULL: goto x86_l_584f;
	case 22609ULL: goto x86_l_5851;
	case 22615ULL: goto x86_l_5857;
	case 22620ULL: goto x86_l_585c;
	case 22626ULL: goto x86_l_5862;
	case 22629ULL: goto x86_l_5865;
	case 22631ULL: goto x86_l_5867;
	case 22636ULL: goto x86_l_586c;
	case 22638ULL: goto x86_l_586e;
	case 22641ULL: goto x86_l_5871;
	case 22647ULL: goto x86_l_5877;
	case 22650ULL: goto x86_l_587a;
	case 22656ULL: goto x86_l_5880;
	case 22661ULL: goto x86_l_5885;
	case 22663ULL: goto x86_l_5887;
	case 22668ULL: goto x86_l_588c;
	case 22673ULL: goto x86_l_5891;
	case 22676ULL: goto x86_l_5894;
	case 22682ULL: goto x86_l_589a;
	case 22686ULL: goto x86_l_589e;
	case 22691ULL: goto x86_l_58a3;
	case 22697ULL: goto x86_l_58a9;
	case 22701ULL: goto x86_l_58ad;
	case 22706ULL: goto x86_l_58b2;
	case 22711ULL: goto x86_l_58b7;
	case 22716ULL: goto x86_l_58bc;
	case 22720ULL: goto x86_l_58c0;
	case 22724ULL: goto x86_l_58c4;
	case 22729ULL: goto x86_l_58c9;
	case 22731ULL: goto x86_l_58cb;
	case 22735ULL: goto x86_l_58cf;
	case 22738ULL: goto x86_l_58d2;
	case 22743ULL: goto x86_l_58d7;
	case 22748ULL: goto x86_l_58dc;
	case 22752ULL: goto x86_l_58e0;
	case 22757ULL: goto x86_l_58e5;
	case 22759ULL: goto x86_l_58e7;
	case 22763ULL: goto x86_l_58eb;
	case 22768ULL: goto x86_l_58f0;
	case 22773ULL: goto x86_l_58f5;
	case 22778ULL: goto x86_l_58fa;
	case 22782ULL: goto x86_l_58fe;
	case 22787ULL: goto x86_l_5903;
	case 22789ULL: goto x86_l_5905;
	case 22793ULL: goto x86_l_5909;
	case 22797ULL: goto x86_l_590d;
	case 22802ULL: goto x86_l_5912;
	case 22807ULL: goto x86_l_5917;
	case 22812ULL: goto x86_l_591c;
	case 22817ULL: goto x86_l_5921;
	case 22820ULL: goto x86_l_5924;
	case 22822ULL: goto x86_l_5926;
	case 22827ULL: goto x86_l_592b;
	case 22832ULL: goto x86_l_5930;
	case 22836ULL: goto x86_l_5934;
	case 22841ULL: goto x86_l_5939;
	case 22846ULL: goto x86_l_593e;
	case 22851ULL: goto x86_l_5943;
	case 22856ULL: goto x86_l_5948;
	case 22858ULL: goto x86_l_594a;
	case 22863ULL: goto x86_l_594f;
	case 22866ULL: goto x86_l_5952;
	case 22872ULL: goto x86_l_5958;
	case 22877ULL: goto x86_l_595d;
	case 22880ULL: goto x86_l_5960;
	case 22886ULL: goto x86_l_5966;
	case 22890ULL: goto x86_l_596a;
	case 22895ULL: goto x86_l_596f;
	case 22900ULL: goto x86_l_5974;
	case 22905ULL: goto x86_l_5979;
	case 22910ULL: goto x86_l_597e;
	case 22912ULL: goto x86_l_5980;
	case 22916ULL: goto x86_l_5984;
	case 22918ULL: goto x86_l_5986;
	case 22924ULL: goto x86_l_598c;
	case 22926ULL: goto x86_l_598e;
	case 22928ULL: goto x86_l_5990;
	case 22934ULL: goto x86_l_5996;
	case 22939ULL: goto x86_l_599b;
	case 22945ULL: goto x86_l_59a1;
	case 22948ULL: goto x86_l_59a4;
	case 22950ULL: goto x86_l_59a6;
	case 22955ULL: goto x86_l_59ab;
	case 22957ULL: goto x86_l_59ad;
	case 22960ULL: goto x86_l_59b0;
	case 22966ULL: goto x86_l_59b6;
	case 22969ULL: goto x86_l_59b9;
	case 22975ULL: goto x86_l_59bf;
	case 22980ULL: goto x86_l_59c4;
	case 22982ULL: goto x86_l_59c6;
	case 22987ULL: goto x86_l_59cb;
	case 22992ULL: goto x86_l_59d0;
	case 22995ULL: goto x86_l_59d3;
	case 23001ULL: goto x86_l_59d9;
	case 23005ULL: goto x86_l_59dd;
	case 23010ULL: goto x86_l_59e2;
	case 23016ULL: goto x86_l_59e8;
	case 23020ULL: goto x86_l_59ec;
	case 23025ULL: goto x86_l_59f1;
	case 23030ULL: goto x86_l_59f6;
	case 23035ULL: goto x86_l_59fb;
	case 23039ULL: goto x86_l_59ff;
	case 23043ULL: goto x86_l_5a03;
	case 23048ULL: goto x86_l_5a08;
	case 23050ULL: goto x86_l_5a0a;
	case 23054ULL: goto x86_l_5a0e;
	case 23057ULL: goto x86_l_5a11;
	case 23062ULL: goto x86_l_5a16;
	case 23067ULL: goto x86_l_5a1b;
	case 23071ULL: goto x86_l_5a1f;
	case 23076ULL: goto x86_l_5a24;
	case 23078ULL: goto x86_l_5a26;
	case 23082ULL: goto x86_l_5a2a;
	case 23087ULL: goto x86_l_5a2f;
	case 23092ULL: goto x86_l_5a34;
	case 23097ULL: goto x86_l_5a39;
	case 23101ULL: goto x86_l_5a3d;
	case 23106ULL: goto x86_l_5a42;
	case 23108ULL: goto x86_l_5a44;
	case 23112ULL: goto x86_l_5a48;
	case 23116ULL: goto x86_l_5a4c;
	case 23121ULL: goto x86_l_5a51;
	case 23126ULL: goto x86_l_5a56;
	case 23131ULL: goto x86_l_5a5b;
	case 23136ULL: goto x86_l_5a60;
	case 23139ULL: goto x86_l_5a63;
	case 23141ULL: goto x86_l_5a65;
	case 23146ULL: goto x86_l_5a6a;
	case 23151ULL: goto x86_l_5a6f;
	case 23155ULL: goto x86_l_5a73;
	case 23160ULL: goto x86_l_5a78;
	case 23165ULL: goto x86_l_5a7d;
	case 23170ULL: goto x86_l_5a82;
	case 23175ULL: goto x86_l_5a87;
	case 23177ULL: goto x86_l_5a89;
	case 23182ULL: goto x86_l_5a8e;
	case 23185ULL: goto x86_l_5a91;
	case 23191ULL: goto x86_l_5a97;
	case 23196ULL: goto x86_l_5a9c;
	case 23199ULL: goto x86_l_5a9f;
	case 23205ULL: goto x86_l_5aa5;
	case 23209ULL: goto x86_l_5aa9;
	case 23214ULL: goto x86_l_5aae;
	case 23219ULL: goto x86_l_5ab3;
	case 23224ULL: goto x86_l_5ab8;
	case 23229ULL: goto x86_l_5abd;
	case 23231ULL: goto x86_l_5abf;
	case 23235ULL: goto x86_l_5ac3;
	case 23237ULL: goto x86_l_5ac5;
	case 23243ULL: goto x86_l_5acb;
	case 23245ULL: goto x86_l_5acd;
	case 23247ULL: goto x86_l_5acf;
	case 23253ULL: goto x86_l_5ad5;
	case 23258ULL: goto x86_l_5ada;
	case 23264ULL: goto x86_l_5ae0;
	case 23267ULL: goto x86_l_5ae3;
	case 23269ULL: goto x86_l_5ae5;
	case 23274ULL: goto x86_l_5aea;
	case 23276ULL: goto x86_l_5aec;
	case 23279ULL: goto x86_l_5aef;
	case 23285ULL: goto x86_l_5af5;
	case 23288ULL: goto x86_l_5af8;
	case 23294ULL: goto x86_l_5afe;
	case 23299ULL: goto x86_l_5b03;
	case 23301ULL: goto x86_l_5b05;
	case 23306ULL: goto x86_l_5b0a;
	case 23311ULL: goto x86_l_5b0f;
	case 23314ULL: goto x86_l_5b12;
	case 23320ULL: goto x86_l_5b18;
	case 23324ULL: goto x86_l_5b1c;
	case 23329ULL: goto x86_l_5b21;
	case 23335ULL: goto x86_l_5b27;
	case 23339ULL: goto x86_l_5b2b;
	case 23344ULL: goto x86_l_5b30;
	case 23349ULL: goto x86_l_5b35;
	case 23354ULL: goto x86_l_5b3a;
	case 23358ULL: goto x86_l_5b3e;
	case 23362ULL: goto x86_l_5b42;
	case 23367ULL: goto x86_l_5b47;
	case 23369ULL: goto x86_l_5b49;
	case 23373ULL: goto x86_l_5b4d;
	case 23376ULL: goto x86_l_5b50;
	case 23381ULL: goto x86_l_5b55;
	case 23386ULL: goto x86_l_5b5a;
	case 23390ULL: goto x86_l_5b5e;
	case 23395ULL: goto x86_l_5b63;
	case 23397ULL: goto x86_l_5b65;
	case 23401ULL: goto x86_l_5b69;
	case 23406ULL: goto x86_l_5b6e;
	case 23411ULL: goto x86_l_5b73;
	case 23416ULL: goto x86_l_5b78;
	case 23420ULL: goto x86_l_5b7c;
	case 23425ULL: goto x86_l_5b81;
	case 23427ULL: goto x86_l_5b83;
	case 23431ULL: goto x86_l_5b87;
	case 23435ULL: goto x86_l_5b8b;
	case 23440ULL: goto x86_l_5b90;
	case 23445ULL: goto x86_l_5b95;
	case 23450ULL: goto x86_l_5b9a;
	case 23455ULL: goto x86_l_5b9f;
	case 23458ULL: goto x86_l_5ba2;
	case 23460ULL: goto x86_l_5ba4;
	case 23465ULL: goto x86_l_5ba9;
	case 23470ULL: goto x86_l_5bae;
	case 23474ULL: goto x86_l_5bb2;
	case 23479ULL: goto x86_l_5bb7;
	case 23484ULL: goto x86_l_5bbc;
	case 23489ULL: goto x86_l_5bc1;
	case 23494ULL: goto x86_l_5bc6;
	case 23496ULL: goto x86_l_5bc8;
	case 23501ULL: goto x86_l_5bcd;
	case 23504ULL: goto x86_l_5bd0;
	case 23510ULL: goto x86_l_5bd6;
	case 23515ULL: goto x86_l_5bdb;
	case 23518ULL: goto x86_l_5bde;
	case 23524ULL: goto x86_l_5be4;
	case 23528ULL: goto x86_l_5be8;
	case 23533ULL: goto x86_l_5bed;
	case 23538ULL: goto x86_l_5bf2;
	case 23543ULL: goto x86_l_5bf7;
	case 23548ULL: goto x86_l_5bfc;
	case 23550ULL: goto x86_l_5bfe;
	case 23554ULL: goto x86_l_5c02;
	case 23556ULL: goto x86_l_5c04;
	case 23562ULL: goto x86_l_5c0a;
	case 23564ULL: goto x86_l_5c0c;
	case 23566ULL: goto x86_l_5c0e;
	case 23572ULL: goto x86_l_5c14;
	case 23577ULL: goto x86_l_5c19;
	case 23583ULL: goto x86_l_5c1f;
	case 23586ULL: goto x86_l_5c22;
	case 23588ULL: goto x86_l_5c24;
	case 23593ULL: goto x86_l_5c29;
	case 23595ULL: goto x86_l_5c2b;
	case 23598ULL: goto x86_l_5c2e;
	case 23604ULL: goto x86_l_5c34;
	case 23607ULL: goto x86_l_5c37;
	case 23613ULL: goto x86_l_5c3d;
	case 23618ULL: goto x86_l_5c42;
	case 23620ULL: goto x86_l_5c44;
	case 23625ULL: goto x86_l_5c49;
	case 23630ULL: goto x86_l_5c4e;
	case 23633ULL: goto x86_l_5c51;
	case 23639ULL: goto x86_l_5c57;
	case 23643ULL: goto x86_l_5c5b;
	case 23648ULL: goto x86_l_5c60;
	case 23654ULL: goto x86_l_5c66;
	case 23658ULL: goto x86_l_5c6a;
	case 23663ULL: goto x86_l_5c6f;
	case 23668ULL: goto x86_l_5c74;
	case 23673ULL: goto x86_l_5c79;
	case 23677ULL: goto x86_l_5c7d;
	case 23681ULL: goto x86_l_5c81;
	case 23686ULL: goto x86_l_5c86;
	case 23688ULL: goto x86_l_5c88;
	case 23692ULL: goto x86_l_5c8c;
	case 23695ULL: goto x86_l_5c8f;
	case 23700ULL: goto x86_l_5c94;
	case 23705ULL: goto x86_l_5c99;
	case 23709ULL: goto x86_l_5c9d;
	case 23714ULL: goto x86_l_5ca2;
	case 23716ULL: goto x86_l_5ca4;
	case 23720ULL: goto x86_l_5ca8;
	case 23725ULL: goto x86_l_5cad;
	case 23730ULL: goto x86_l_5cb2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5654:
	/* 0x5654: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5659:
	/* 0x5659: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_565e:
	/* 0x565e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5662:
	/* 0x5662: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5667:
	/* 0x5667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5669:
	/* 0x5669: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_566d:
	/* 0x566d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5672:
	/* 0x5672: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5677:
	/* 0x5677: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_567c:
	/* 0x567c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5680:
	/* 0x5680: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5685:
	/* 0x5685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5687:
	/* 0x5687: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_568b:
	/* 0x568b: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_568f:
	/* 0x568f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5694:
	/* 0x5694: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5699:
	/* 0x5699: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_569e:
	/* 0x569e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56a3:
	/* 0x56a3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_56a6:
	/* 0x56a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56a8:
	/* 0x56a8: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56ad:
	/* 0x56ad: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56b2:
	/* 0x56b2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_56b6:
	/* 0x56b6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56bb:
	/* 0x56bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_56c0:
	/* 0x56c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56c5:
	/* 0x56c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56ca:
	/* 0x56ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56cc:
	/* 0x56cc: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56d1:
	/* 0x56d1: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_56d4:
	/* 0x56d4: je     5891 <trace_security_mmap_file+0x5891> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5891;
	}
x86_l_56da:
	/* 0x56da: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56df:
	/* 0x56df: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_56e2:
	/* 0x56e2: je     5891 <trace_security_mmap_file+0x5891> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5891;
	}
x86_l_56e8:
	/* 0x56e8: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_56ec:
	/* 0x56ec: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56f1:
	/* 0x56f1: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_56f6:
	/* 0x56f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_56fb:
	/* 0x56fb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5700:
	/* 0x5700: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5702:
	/* 0x5702: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5706:
	/* 0x5706: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5708:
	/* 0x5708: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_570e:
	/* 0x570e: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5710:
	/* 0x5710: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5712:
	/* 0x5712: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_5718:
	/* 0x5718: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_571d:
	/* 0x571d: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5723:
	/* 0x5723: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5726:
	/* 0x5726: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5728:
	/* 0x5728: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_572d:
	/* 0x572d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572f:
	/* 0x572f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5732:
	/* 0x5732: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_5738:
	/* 0x5738: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_573b:
	/* 0x573b: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5741:
	/* 0x5741: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5746:
	/* 0x5746: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5748:
	/* 0x5748: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_574d:
	/* 0x574d: jmp    590d <trace_security_mmap_file+0x590d> */
	goto x86_l_590d;
x86_l_5752:
	/* 0x5752: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5755:
	/* 0x5755: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_575b:
	/* 0x575b: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_575f:
	/* 0x575f: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5764:
	/* 0x5764: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_576a:
	/* 0x576a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_576e:
	/* 0x576e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5773:
	/* 0x5773: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5778:
	/* 0x5778: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_577d:
	/* 0x577d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5781:
	/* 0x5781: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5785:
	/* 0x5785: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_578a:
	/* 0x578a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_578c:
	/* 0x578c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5790:
	/* 0x5790: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5793:
	/* 0x5793: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5798:
	/* 0x5798: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_579d:
	/* 0x579d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57a1:
	/* 0x57a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57a6:
	/* 0x57a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57a8:
	/* 0x57a8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57ac:
	/* 0x57ac: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_57b1:
	/* 0x57b1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_57b6:
	/* 0x57b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57bb:
	/* 0x57bb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57bf:
	/* 0x57bf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57c4:
	/* 0x57c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57c6:
	/* 0x57c6: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57ca:
	/* 0x57ca: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_57ce:
	/* 0x57ce: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57d3:
	/* 0x57d3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57d8:
	/* 0x57d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_57dd:
	/* 0x57dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_57e2:
	/* 0x57e2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_57e5:
	/* 0x57e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e7:
	/* 0x57e7: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57ec:
	/* 0x57ec: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57f1:
	/* 0x57f1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_57f5:
	/* 0x57f5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57fa:
	/* 0x57fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_57ff:
	/* 0x57ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5804:
	/* 0x5804: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5809:
	/* 0x5809: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_580b:
	/* 0x580b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5810:
	/* 0x5810: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5813:
	/* 0x5813: je     59d0 <trace_security_mmap_file+0x59d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d0;
	}
x86_l_5819:
	/* 0x5819: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_581e:
	/* 0x581e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5821:
	/* 0x5821: je     59d0 <trace_security_mmap_file+0x59d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59d0;
	}
x86_l_5827:
	/* 0x5827: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_582b:
	/* 0x582b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5830:
	/* 0x5830: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5835:
	/* 0x5835: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_583a:
	/* 0x583a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_583f:
	/* 0x583f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5841:
	/* 0x5841: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5845:
	/* 0x5845: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5847:
	/* 0x5847: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_584d:
	/* 0x584d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_584f:
	/* 0x584f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5851:
	/* 0x5851: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_5857:
	/* 0x5857: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_585c:
	/* 0x585c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5862:
	/* 0x5862: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5865:
	/* 0x5865: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5867:
	/* 0x5867: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_586c:
	/* 0x586c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586e:
	/* 0x586e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5871:
	/* 0x5871: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_5877:
	/* 0x5877: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_587a:
	/* 0x587a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5880:
	/* 0x5880: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5885:
	/* 0x5885: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5887:
	/* 0x5887: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_588c:
	/* 0x588c: jmp    5a4c <trace_security_mmap_file+0x5a4c> */
	goto x86_l_5a4c;
x86_l_5891:
	/* 0x5891: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5894:
	/* 0x5894: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_589a:
	/* 0x589a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_589e:
	/* 0x589e: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_58a3:
	/* 0x58a3: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_58a9:
	/* 0x58a9: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_58ad:
	/* 0x58ad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58b2:
	/* 0x58b2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58b7:
	/* 0x58b7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58bc:
	/* 0x58bc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58c0:
	/* 0x58c0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_58c4:
	/* 0x58c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58c9:
	/* 0x58c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58cb:
	/* 0x58cb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58cf:
	/* 0x58cf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58d2:
	/* 0x58d2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58d7:
	/* 0x58d7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58dc:
	/* 0x58dc: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58e0:
	/* 0x58e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58e5:
	/* 0x58e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58e7:
	/* 0x58e7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58eb:
	/* 0x58eb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58f0:
	/* 0x58f0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58f5:
	/* 0x58f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58fa:
	/* 0x58fa: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58fe:
	/* 0x58fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5903:
	/* 0x5903: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5905:
	/* 0x5905: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5909:
	/* 0x5909: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_590d:
	/* 0x590d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5912:
	/* 0x5912: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5917:
	/* 0x5917: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_591c:
	/* 0x591c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5921:
	/* 0x5921: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5924:
	/* 0x5924: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5926:
	/* 0x5926: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_592b:
	/* 0x592b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5930:
	/* 0x5930: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5934:
	/* 0x5934: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5939:
	/* 0x5939: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_593e:
	/* 0x593e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5943:
	/* 0x5943: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5948:
	/* 0x5948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_594a:
	/* 0x594a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_594f:
	/* 0x594f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5952:
	/* 0x5952: je     5b0f <trace_security_mmap_file+0x5b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b0f;
	}
x86_l_5958:
	/* 0x5958: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_595d:
	/* 0x595d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5960:
	/* 0x5960: je     5b0f <trace_security_mmap_file+0x5b0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b0f;
	}
x86_l_5966:
	/* 0x5966: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_596a:
	/* 0x596a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_596f:
	/* 0x596f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5974:
	/* 0x5974: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5979:
	/* 0x5979: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_597e:
	/* 0x597e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5980:
	/* 0x5980: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5984:
	/* 0x5984: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5986:
	/* 0x5986: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_598c:
	/* 0x598c: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_598e:
	/* 0x598e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5990:
	/* 0x5990: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_5996:
	/* 0x5996: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_599b:
	/* 0x599b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_59a1:
	/* 0x59a1: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_59a4:
	/* 0x59a4: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_59a6:
	/* 0x59a6: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_59ab:
	/* 0x59ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59ad:
	/* 0x59ad: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_59b0:
	/* 0x59b0: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_59b6:
	/* 0x59b6: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_59b9:
	/* 0x59b9: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_59bf:
	/* 0x59bf: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_59c4:
	/* 0x59c4: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_59c6:
	/* 0x59c6: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59cb:
	/* 0x59cb: jmp    5b8b <trace_security_mmap_file+0x5b8b> */
	goto x86_l_5b8b;
x86_l_59d0:
	/* 0x59d0: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_59d3:
	/* 0x59d3: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_59d9:
	/* 0x59d9: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59dd:
	/* 0x59dd: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_59e2:
	/* 0x59e2: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_59e8:
	/* 0x59e8: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59ec:
	/* 0x59ec: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59f1:
	/* 0x59f1: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_59f6:
	/* 0x59f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59fb:
	/* 0x59fb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59ff:
	/* 0x59ff: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a03:
	/* 0x5a03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a08:
	/* 0x5a08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a0a:
	/* 0x5a0a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a0e:
	/* 0x5a0e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5a11:
	/* 0x5a11: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a16:
	/* 0x5a16: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a1b:
	/* 0x5a1b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a1f:
	/* 0x5a1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a24:
	/* 0x5a24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a26:
	/* 0x5a26: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a2a:
	/* 0x5a2a: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5a2f:
	/* 0x5a2f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5a34:
	/* 0x5a34: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a39:
	/* 0x5a39: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a3d:
	/* 0x5a3d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a42:
	/* 0x5a42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a44:
	/* 0x5a44: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a48:
	/* 0x5a48: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a4c:
	/* 0x5a4c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a51:
	/* 0x5a51: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a56:
	/* 0x5a56: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a5b:
	/* 0x5a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a60:
	/* 0x5a60: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5a63:
	/* 0x5a63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a65:
	/* 0x5a65: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a6a:
	/* 0x5a6a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a6f:
	/* 0x5a6f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a73:
	/* 0x5a73: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a78:
	/* 0x5a78: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5a7d:
	/* 0x5a7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a82:
	/* 0x5a82: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a87:
	/* 0x5a87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a89:
	/* 0x5a89: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a8e:
	/* 0x5a8e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5a91:
	/* 0x5a91: je     5c4e <trace_security_mmap_file+0x5c4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c4e;
	}
x86_l_5a97:
	/* 0x5a97: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a9c:
	/* 0x5a9c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5a9f:
	/* 0x5a9f: je     5c4e <trace_security_mmap_file+0x5c4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c4e;
	}
x86_l_5aa5:
	/* 0x5aa5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5aa9:
	/* 0x5aa9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5aae:
	/* 0x5aae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5ab3:
	/* 0x5ab3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ab8:
	/* 0x5ab8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5abd:
	/* 0x5abd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5abf:
	/* 0x5abf: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5ac3:
	/* 0x5ac3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5ac5:
	/* 0x5ac5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5acb:
	/* 0x5acb: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5acd:
	/* 0x5acd: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5acf:
	/* 0x5acf: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_5ad5:
	/* 0x5ad5: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5ada:
	/* 0x5ada: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5ae0:
	/* 0x5ae0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ae3:
	/* 0x5ae3: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5ae5:
	/* 0x5ae5: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5aea:
	/* 0x5aea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aec:
	/* 0x5aec: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5aef:
	/* 0x5aef: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_5af5:
	/* 0x5af5: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5af8:
	/* 0x5af8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5afe:
	/* 0x5afe: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5b03:
	/* 0x5b03: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5b05:
	/* 0x5b05: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b0a:
	/* 0x5b0a: jmp    5cca <trace_security_mmap_file+0x5cca> */
	return 23754ULL;
x86_l_5b0f:
	/* 0x5b0f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5b12:
	/* 0x5b12: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_5b18:
	/* 0x5b18: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b1c:
	/* 0x5b1c: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5b21:
	/* 0x5b21: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_5b27:
	/* 0x5b27: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b2b:
	/* 0x5b2b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b30:
	/* 0x5b30: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b35:
	/* 0x5b35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b3a:
	/* 0x5b3a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b3e:
	/* 0x5b3e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b42:
	/* 0x5b42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b47:
	/* 0x5b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b49:
	/* 0x5b49: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b4d:
	/* 0x5b4d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5b50:
	/* 0x5b50: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b55:
	/* 0x5b55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b5a:
	/* 0x5b5a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b5e:
	/* 0x5b5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b63:
	/* 0x5b63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b65:
	/* 0x5b65: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b69:
	/* 0x5b69: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b6e:
	/* 0x5b6e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5b73:
	/* 0x5b73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b78:
	/* 0x5b78: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b7c:
	/* 0x5b7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b81:
	/* 0x5b81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b83:
	/* 0x5b83: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b87:
	/* 0x5b87: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b8b:
	/* 0x5b8b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b90:
	/* 0x5b90: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5b95:
	/* 0x5b95: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b9a:
	/* 0x5b9a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b9f:
	/* 0x5b9f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5ba2:
	/* 0x5ba2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ba4:
	/* 0x5ba4: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ba9:
	/* 0x5ba9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bae:
	/* 0x5bae: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5bb2:
	/* 0x5bb2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bb7:
	/* 0x5bb7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5bbc:
	/* 0x5bbc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bc1:
	/* 0x5bc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bc6:
	/* 0x5bc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bc8:
	/* 0x5bc8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bcd:
	/* 0x5bcd: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5bd0:
	/* 0x5bd0: je     5d8d <trace_security_mmap_file+0x5d8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23949ULL;
	}
x86_l_5bd6:
	/* 0x5bd6: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bdb:
	/* 0x5bdb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5bde:
	/* 0x5bde: je     5d8d <trace_security_mmap_file+0x5d8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23949ULL;
	}
x86_l_5be4:
	/* 0x5be4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5be8:
	/* 0x5be8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bed:
	/* 0x5bed: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5bf2:
	/* 0x5bf2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bf7:
	/* 0x5bf7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5bfc:
	/* 0x5bfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bfe:
	/* 0x5bfe: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5c02:
	/* 0x5c02: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5c04:
	/* 0x5c04: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c0a:
	/* 0x5c0a: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5c0c:
	/* 0x5c0c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c0e:
	/* 0x5c0e: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_5c14:
	/* 0x5c14: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c19:
	/* 0x5c19: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5c1f:
	/* 0x5c1f: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5c22:
	/* 0x5c22: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5c24:
	/* 0x5c24: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5c29:
	/* 0x5c29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2b:
	/* 0x5c2b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c2e:
	/* 0x5c2e: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_5c34:
	/* 0x5c34: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5c37:
	/* 0x5c37: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5c3d:
	/* 0x5c3d: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5c42:
	/* 0x5c42: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5c44:
	/* 0x5c44: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c49:
	/* 0x5c49: jmp    5e09 <trace_security_mmap_file+0x5e09> */
	return 24073ULL;
x86_l_5c4e:
	/* 0x5c4e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5c51:
	/* 0x5c51: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_5c57:
	/* 0x5c57: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c5b:
	/* 0x5c5b: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5c60:
	/* 0x5c60: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_5c66:
	/* 0x5c66: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c6a:
	/* 0x5c6a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c6f:
	/* 0x5c6f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c74:
	/* 0x5c74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c79:
	/* 0x5c79: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c7d:
	/* 0x5c7d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c81:
	/* 0x5c81: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c86:
	/* 0x5c86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c88:
	/* 0x5c88: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c8c:
	/* 0x5c8c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5c8f:
	/* 0x5c8f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5c94:
	/* 0x5c94: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c99:
	/* 0x5c99: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c9d:
	/* 0x5c9d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ca2:
	/* 0x5ca2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ca4:
	/* 0x5ca4: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ca8:
	/* 0x5ca8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5cad:
	/* 0x5cad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5cb2:
	/* 0x5cb2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
	return 23735ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23735ULL: goto x86_l_5cb7;
	case 23739ULL: goto x86_l_5cbb;
	case 23744ULL: goto x86_l_5cc0;
	case 23746ULL: goto x86_l_5cc2;
	case 23750ULL: goto x86_l_5cc6;
	case 23754ULL: goto x86_l_5cca;
	case 23759ULL: goto x86_l_5ccf;
	case 23764ULL: goto x86_l_5cd4;
	case 23769ULL: goto x86_l_5cd9;
	case 23774ULL: goto x86_l_5cde;
	case 23777ULL: goto x86_l_5ce1;
	case 23779ULL: goto x86_l_5ce3;
	case 23784ULL: goto x86_l_5ce8;
	case 23789ULL: goto x86_l_5ced;
	case 23793ULL: goto x86_l_5cf1;
	case 23798ULL: goto x86_l_5cf6;
	case 23803ULL: goto x86_l_5cfb;
	case 23808ULL: goto x86_l_5d00;
	case 23813ULL: goto x86_l_5d05;
	case 23815ULL: goto x86_l_5d07;
	case 23820ULL: goto x86_l_5d0c;
	case 23823ULL: goto x86_l_5d0f;
	case 23829ULL: goto x86_l_5d15;
	case 23834ULL: goto x86_l_5d1a;
	case 23837ULL: goto x86_l_5d1d;
	case 23843ULL: goto x86_l_5d23;
	case 23847ULL: goto x86_l_5d27;
	case 23852ULL: goto x86_l_5d2c;
	case 23857ULL: goto x86_l_5d31;
	case 23862ULL: goto x86_l_5d36;
	case 23867ULL: goto x86_l_5d3b;
	case 23869ULL: goto x86_l_5d3d;
	case 23873ULL: goto x86_l_5d41;
	case 23875ULL: goto x86_l_5d43;
	case 23881ULL: goto x86_l_5d49;
	case 23883ULL: goto x86_l_5d4b;
	case 23885ULL: goto x86_l_5d4d;
	case 23891ULL: goto x86_l_5d53;
	case 23896ULL: goto x86_l_5d58;
	case 23902ULL: goto x86_l_5d5e;
	case 23905ULL: goto x86_l_5d61;
	case 23907ULL: goto x86_l_5d63;
	case 23912ULL: goto x86_l_5d68;
	case 23914ULL: goto x86_l_5d6a;
	case 23917ULL: goto x86_l_5d6d;
	case 23923ULL: goto x86_l_5d73;
	case 23926ULL: goto x86_l_5d76;
	case 23932ULL: goto x86_l_5d7c;
	case 23937ULL: goto x86_l_5d81;
	case 23939ULL: goto x86_l_5d83;
	case 23944ULL: goto x86_l_5d88;
	case 23949ULL: goto x86_l_5d8d;
	case 23952ULL: goto x86_l_5d90;
	case 23958ULL: goto x86_l_5d96;
	case 23962ULL: goto x86_l_5d9a;
	case 23967ULL: goto x86_l_5d9f;
	case 23973ULL: goto x86_l_5da5;
	case 23977ULL: goto x86_l_5da9;
	case 23982ULL: goto x86_l_5dae;
	case 23987ULL: goto x86_l_5db3;
	case 23992ULL: goto x86_l_5db8;
	case 23996ULL: goto x86_l_5dbc;
	case 24000ULL: goto x86_l_5dc0;
	case 24005ULL: goto x86_l_5dc5;
	case 24007ULL: goto x86_l_5dc7;
	case 24011ULL: goto x86_l_5dcb;
	case 24014ULL: goto x86_l_5dce;
	case 24019ULL: goto x86_l_5dd3;
	case 24024ULL: goto x86_l_5dd8;
	case 24028ULL: goto x86_l_5ddc;
	case 24033ULL: goto x86_l_5de1;
	case 24035ULL: goto x86_l_5de3;
	case 24039ULL: goto x86_l_5de7;
	case 24044ULL: goto x86_l_5dec;
	case 24049ULL: goto x86_l_5df1;
	case 24054ULL: goto x86_l_5df6;
	case 24058ULL: goto x86_l_5dfa;
	case 24063ULL: goto x86_l_5dff;
	case 24065ULL: goto x86_l_5e01;
	case 24069ULL: goto x86_l_5e05;
	case 24073ULL: goto x86_l_5e09;
	case 24078ULL: goto x86_l_5e0e;
	case 24083ULL: goto x86_l_5e13;
	case 24088ULL: goto x86_l_5e18;
	case 24093ULL: goto x86_l_5e1d;
	case 24096ULL: goto x86_l_5e20;
	case 24098ULL: goto x86_l_5e22;
	case 24103ULL: goto x86_l_5e27;
	case 24108ULL: goto x86_l_5e2c;
	case 24112ULL: goto x86_l_5e30;
	case 24117ULL: goto x86_l_5e35;
	case 24122ULL: goto x86_l_5e3a;
	case 24127ULL: goto x86_l_5e3f;
	case 24132ULL: goto x86_l_5e44;
	case 24134ULL: goto x86_l_5e46;
	case 24139ULL: goto x86_l_5e4b;
	case 24142ULL: goto x86_l_5e4e;
	case 24148ULL: goto x86_l_5e54;
	case 24153ULL: goto x86_l_5e59;
	case 24156ULL: goto x86_l_5e5c;
	case 24162ULL: goto x86_l_5e62;
	case 24166ULL: goto x86_l_5e66;
	case 24171ULL: goto x86_l_5e6b;
	case 24176ULL: goto x86_l_5e70;
	case 24181ULL: goto x86_l_5e75;
	case 24186ULL: goto x86_l_5e7a;
	case 24188ULL: goto x86_l_5e7c;
	case 24192ULL: goto x86_l_5e80;
	case 24194ULL: goto x86_l_5e82;
	case 24200ULL: goto x86_l_5e88;
	case 24202ULL: goto x86_l_5e8a;
	case 24204ULL: goto x86_l_5e8c;
	case 24210ULL: goto x86_l_5e92;
	case 24215ULL: goto x86_l_5e97;
	case 24221ULL: goto x86_l_5e9d;
	case 24224ULL: goto x86_l_5ea0;
	case 24226ULL: goto x86_l_5ea2;
	case 24231ULL: goto x86_l_5ea7;
	case 24233ULL: goto x86_l_5ea9;
	case 24236ULL: goto x86_l_5eac;
	case 24242ULL: goto x86_l_5eb2;
	case 24245ULL: goto x86_l_5eb5;
	case 24251ULL: goto x86_l_5ebb;
	case 24256ULL: goto x86_l_5ec0;
	case 24258ULL: goto x86_l_5ec2;
	case 24263ULL: goto x86_l_5ec7;
	case 24268ULL: goto x86_l_5ecc;
	case 24271ULL: goto x86_l_5ecf;
	case 24277ULL: goto x86_l_5ed5;
	case 24281ULL: goto x86_l_5ed9;
	case 24286ULL: goto x86_l_5ede;
	case 24292ULL: goto x86_l_5ee4;
	case 24296ULL: goto x86_l_5ee8;
	case 24301ULL: goto x86_l_5eed;
	case 24306ULL: goto x86_l_5ef2;
	case 24311ULL: goto x86_l_5ef7;
	case 24315ULL: goto x86_l_5efb;
	case 24319ULL: goto x86_l_5eff;
	case 24324ULL: goto x86_l_5f04;
	case 24326ULL: goto x86_l_5f06;
	case 24330ULL: goto x86_l_5f0a;
	case 24333ULL: goto x86_l_5f0d;
	case 24338ULL: goto x86_l_5f12;
	case 24343ULL: goto x86_l_5f17;
	case 24347ULL: goto x86_l_5f1b;
	case 24352ULL: goto x86_l_5f20;
	case 24354ULL: goto x86_l_5f22;
	case 24358ULL: goto x86_l_5f26;
	case 24363ULL: goto x86_l_5f2b;
	case 24368ULL: goto x86_l_5f30;
	case 24373ULL: goto x86_l_5f35;
	case 24377ULL: goto x86_l_5f39;
	case 24382ULL: goto x86_l_5f3e;
	case 24384ULL: goto x86_l_5f40;
	case 24388ULL: goto x86_l_5f44;
	case 24392ULL: goto x86_l_5f48;
	case 24397ULL: goto x86_l_5f4d;
	case 24402ULL: goto x86_l_5f52;
	case 24407ULL: goto x86_l_5f57;
	case 24412ULL: goto x86_l_5f5c;
	case 24415ULL: goto x86_l_5f5f;
	case 24417ULL: goto x86_l_5f61;
	case 24422ULL: goto x86_l_5f66;
	case 24427ULL: goto x86_l_5f6b;
	case 24431ULL: goto x86_l_5f6f;
	case 24436ULL: goto x86_l_5f74;
	case 24441ULL: goto x86_l_5f79;
	case 24446ULL: goto x86_l_5f7e;
	case 24451ULL: goto x86_l_5f83;
	case 24453ULL: goto x86_l_5f85;
	case 24458ULL: goto x86_l_5f8a;
	case 24461ULL: goto x86_l_5f8d;
	case 24467ULL: goto x86_l_5f93;
	case 24472ULL: goto x86_l_5f98;
	case 24475ULL: goto x86_l_5f9b;
	case 24481ULL: goto x86_l_5fa1;
	case 24485ULL: goto x86_l_5fa5;
	case 24490ULL: goto x86_l_5faa;
	case 24495ULL: goto x86_l_5faf;
	case 24500ULL: goto x86_l_5fb4;
	case 24505ULL: goto x86_l_5fb9;
	case 24507ULL: goto x86_l_5fbb;
	case 24511ULL: goto x86_l_5fbf;
	case 24513ULL: goto x86_l_5fc1;
	case 24519ULL: goto x86_l_5fc7;
	case 24521ULL: goto x86_l_5fc9;
	case 24523ULL: goto x86_l_5fcb;
	case 24529ULL: goto x86_l_5fd1;
	case 24534ULL: goto x86_l_5fd6;
	case 24540ULL: goto x86_l_5fdc;
	case 24543ULL: goto x86_l_5fdf;
	case 24545ULL: goto x86_l_5fe1;
	case 24550ULL: goto x86_l_5fe6;
	case 24552ULL: goto x86_l_5fe8;
	case 24555ULL: goto x86_l_5feb;
	case 24561ULL: goto x86_l_5ff1;
	case 24564ULL: goto x86_l_5ff4;
	case 24570ULL: goto x86_l_5ffa;
	case 24575ULL: goto x86_l_5fff;
	case 24577ULL: goto x86_l_6001;
	case 24582ULL: goto x86_l_6006;
	case 24587ULL: goto x86_l_600b;
	case 24590ULL: goto x86_l_600e;
	case 24596ULL: goto x86_l_6014;
	case 24600ULL: goto x86_l_6018;
	case 24605ULL: goto x86_l_601d;
	case 24611ULL: goto x86_l_6023;
	case 24615ULL: goto x86_l_6027;
	case 24620ULL: goto x86_l_602c;
	case 24625ULL: goto x86_l_6031;
	case 24630ULL: goto x86_l_6036;
	case 24634ULL: goto x86_l_603a;
	case 24638ULL: goto x86_l_603e;
	case 24643ULL: goto x86_l_6043;
	case 24645ULL: goto x86_l_6045;
	case 24649ULL: goto x86_l_6049;
	case 24652ULL: goto x86_l_604c;
	case 24657ULL: goto x86_l_6051;
	case 24662ULL: goto x86_l_6056;
	case 24666ULL: goto x86_l_605a;
	case 24671ULL: goto x86_l_605f;
	case 24673ULL: goto x86_l_6061;
	case 24677ULL: goto x86_l_6065;
	case 24682ULL: goto x86_l_606a;
	case 24687ULL: goto x86_l_606f;
	case 24692ULL: goto x86_l_6074;
	case 24696ULL: goto x86_l_6078;
	case 24701ULL: goto x86_l_607d;
	case 24703ULL: goto x86_l_607f;
	case 24707ULL: goto x86_l_6083;
	case 24711ULL: goto x86_l_6087;
	case 24716ULL: goto x86_l_608c;
	case 24721ULL: goto x86_l_6091;
	case 24726ULL: goto x86_l_6096;
	case 24731ULL: goto x86_l_609b;
	case 24734ULL: goto x86_l_609e;
	case 24736ULL: goto x86_l_60a0;
	case 24741ULL: goto x86_l_60a5;
	case 24746ULL: goto x86_l_60aa;
	case 24750ULL: goto x86_l_60ae;
	case 24755ULL: goto x86_l_60b3;
	case 24760ULL: goto x86_l_60b8;
	case 24765ULL: goto x86_l_60bd;
	case 24770ULL: goto x86_l_60c2;
	case 24772ULL: goto x86_l_60c4;
	case 24777ULL: goto x86_l_60c9;
	case 24780ULL: goto x86_l_60cc;
	case 24786ULL: goto x86_l_60d2;
	case 24791ULL: goto x86_l_60d7;
	case 24794ULL: goto x86_l_60da;
	case 24800ULL: goto x86_l_60e0;
	case 24804ULL: goto x86_l_60e4;
	case 24809ULL: goto x86_l_60e9;
	case 24814ULL: goto x86_l_60ee;
	case 24819ULL: goto x86_l_60f3;
	case 24824ULL: goto x86_l_60f8;
	case 24826ULL: goto x86_l_60fa;
	case 24830ULL: goto x86_l_60fe;
	case 24832ULL: goto x86_l_6100;
	case 24838ULL: goto x86_l_6106;
	case 24840ULL: goto x86_l_6108;
	case 24842ULL: goto x86_l_610a;
	case 24848ULL: goto x86_l_6110;
	case 24853ULL: goto x86_l_6115;
	case 24859ULL: goto x86_l_611b;
	case 24862ULL: goto x86_l_611e;
	case 24864ULL: goto x86_l_6120;
	case 24869ULL: goto x86_l_6125;
	case 24871ULL: goto x86_l_6127;
	case 24874ULL: goto x86_l_612a;
	case 24880ULL: goto x86_l_6130;
	case 24883ULL: goto x86_l_6133;
	case 24889ULL: goto x86_l_6139;
	case 24894ULL: goto x86_l_613e;
	case 24896ULL: goto x86_l_6140;
	case 24901ULL: goto x86_l_6145;
	case 24906ULL: goto x86_l_614a;
	case 24909ULL: goto x86_l_614d;
	case 24915ULL: goto x86_l_6153;
	case 24919ULL: goto x86_l_6157;
	case 24924ULL: goto x86_l_615c;
	case 24930ULL: goto x86_l_6162;
	case 24934ULL: goto x86_l_6166;
	case 24939ULL: goto x86_l_616b;
	case 24944ULL: goto x86_l_6170;
	case 24949ULL: goto x86_l_6175;
	case 24953ULL: goto x86_l_6179;
	case 24957ULL: goto x86_l_617d;
	case 24962ULL: goto x86_l_6182;
	case 24964ULL: goto x86_l_6184;
	case 24968ULL: goto x86_l_6188;
	case 24971ULL: goto x86_l_618b;
	case 24976ULL: goto x86_l_6190;
	case 24981ULL: goto x86_l_6195;
	case 24985ULL: goto x86_l_6199;
	case 24990ULL: goto x86_l_619e;
	case 24992ULL: goto x86_l_61a0;
	case 24996ULL: goto x86_l_61a4;
	case 25001ULL: goto x86_l_61a9;
	case 25006ULL: goto x86_l_61ae;
	case 25011ULL: goto x86_l_61b3;
	case 25015ULL: goto x86_l_61b7;
	case 25020ULL: goto x86_l_61bc;
	case 25022ULL: goto x86_l_61be;
	case 25026ULL: goto x86_l_61c2;
	case 25030ULL: goto x86_l_61c6;
	case 25035ULL: goto x86_l_61cb;
	case 25040ULL: goto x86_l_61d0;
	case 25045ULL: goto x86_l_61d5;
	case 25050ULL: goto x86_l_61da;
	case 25053ULL: goto x86_l_61dd;
	case 25055ULL: goto x86_l_61df;
	case 25060ULL: goto x86_l_61e4;
	case 25065ULL: goto x86_l_61e9;
	case 25069ULL: goto x86_l_61ed;
	case 25074ULL: goto x86_l_61f2;
	case 25079ULL: goto x86_l_61f7;
	case 25084ULL: goto x86_l_61fc;
	case 25089ULL: goto x86_l_6201;
	case 25091ULL: goto x86_l_6203;
	case 25096ULL: goto x86_l_6208;
	case 25099ULL: goto x86_l_620b;
	case 25105ULL: goto x86_l_6211;
	case 25110ULL: goto x86_l_6216;
	case 25113ULL: goto x86_l_6219;
	case 25119ULL: goto x86_l_621f;
	case 25123ULL: goto x86_l_6223;
	case 25128ULL: goto x86_l_6228;
	case 25133ULL: goto x86_l_622d;
	case 25138ULL: goto x86_l_6232;
	case 25143ULL: goto x86_l_6237;
	case 25145ULL: goto x86_l_6239;
	case 25149ULL: goto x86_l_623d;
	case 25151ULL: goto x86_l_623f;
	case 25157ULL: goto x86_l_6245;
	case 25159ULL: goto x86_l_6247;
	case 25161ULL: goto x86_l_6249;
	case 25167ULL: goto x86_l_624f;
	case 25172ULL: goto x86_l_6254;
	case 25178ULL: goto x86_l_625a;
	case 25181ULL: goto x86_l_625d;
	case 25183ULL: goto x86_l_625f;
	case 25188ULL: goto x86_l_6264;
	case 25190ULL: goto x86_l_6266;
	case 25193ULL: goto x86_l_6269;
	case 25199ULL: goto x86_l_626f;
	case 25202ULL: goto x86_l_6272;
	case 25208ULL: goto x86_l_6278;
	case 25213ULL: goto x86_l_627d;
	case 25215ULL: goto x86_l_627f;
	case 25220ULL: goto x86_l_6284;
	case 25225ULL: goto x86_l_6289;
	case 25228ULL: goto x86_l_628c;
	case 25234ULL: goto x86_l_6292;
	case 25238ULL: goto x86_l_6296;
	case 25243ULL: goto x86_l_629b;
	case 25249ULL: goto x86_l_62a1;
	case 25253ULL: goto x86_l_62a5;
	case 25258ULL: goto x86_l_62aa;
	case 25263ULL: goto x86_l_62af;
	case 25268ULL: goto x86_l_62b4;
	case 25272ULL: goto x86_l_62b8;
	case 25276ULL: goto x86_l_62bc;
	case 25281ULL: goto x86_l_62c1;
	case 25283ULL: goto x86_l_62c3;
	case 25287ULL: goto x86_l_62c7;
	case 25290ULL: goto x86_l_62ca;
	case 25295ULL: goto x86_l_62cf;
	case 25300ULL: goto x86_l_62d4;
	case 25304ULL: goto x86_l_62d8;
	case 25309ULL: goto x86_l_62dd;
	case 25311ULL: goto x86_l_62df;
	case 25315ULL: goto x86_l_62e3;
	case 25320ULL: goto x86_l_62e8;
	case 25325ULL: goto x86_l_62ed;
	case 25330ULL: goto x86_l_62f2;
	case 25334ULL: goto x86_l_62f6;
	case 25339ULL: goto x86_l_62fb;
	case 25341ULL: goto x86_l_62fd;
	case 25345ULL: goto x86_l_6301;
	case 25349ULL: goto x86_l_6305;
	case 25354ULL: goto x86_l_630a;
	case 25359ULL: goto x86_l_630f;
	case 25364ULL: goto x86_l_6314;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5cb7:
	/* 0x5cb7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cbb:
	/* 0x5cbb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5cc0:
	/* 0x5cc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc2:
	/* 0x5cc2: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5cc6:
	/* 0x5cc6: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5cca:
	/* 0x5cca: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x5cde: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5ce1:
	/* 0x5ce1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ce3:
	/* 0x5ce3: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ce8:
	/* 0x5ce8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ced:
	/* 0x5ced: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5cf1:
	/* 0x5cf1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cf6:
	/* 0x5cf6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5cfb:
	/* 0x5cfb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d00:
	/* 0x5d00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d05:
	/* 0x5d05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d07:
	/* 0x5d07: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d0c:
	/* 0x5d0c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5d0f:
	/* 0x5d0f: je     5ecc <trace_security_mmap_file+0x5ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ecc;
	}
x86_l_5d15:
	/* 0x5d15: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d1a:
	/* 0x5d1a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5d1d:
	/* 0x5d1d: je     5ecc <trace_security_mmap_file+0x5ecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ecc;
	}
x86_l_5d23:
	/* 0x5d23: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d27:
	/* 0x5d27: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d2c:
	/* 0x5d2c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5d31:
	/* 0x5d31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d36:
	/* 0x5d36: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5d3b:
	/* 0x5d3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d3d:
	/* 0x5d3d: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5d41:
	/* 0x5d41: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5d43:
	/* 0x5d43: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5d49:
	/* 0x5d49: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5d4b:
	/* 0x5d4b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d4d:
	/* 0x5d4d: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_5d53:
	/* 0x5d53: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d58:
	/* 0x5d58: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5d5e:
	/* 0x5d5e: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5d61:
	/* 0x5d61: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5d63:
	/* 0x5d63: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5d68:
	/* 0x5d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d6a:
	/* 0x5d6a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5d6d:
	/* 0x5d6d: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_5d73:
	/* 0x5d73: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5d76:
	/* 0x5d76: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5d7c:
	/* 0x5d7c: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5d81:
	/* 0x5d81: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5d83:
	/* 0x5d83: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d88:
	/* 0x5d88: jmp    5f48 <trace_security_mmap_file+0x5f48> */
	goto x86_l_5f48;
x86_l_5d8d:
	/* 0x5d8d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5d90:
	/* 0x5d90: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_5d96:
	/* 0x5d96: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d9a:
	/* 0x5d9a: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5d9f:
	/* 0x5d9f: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_5da5:
	/* 0x5da5: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5da9:
	/* 0x5da9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dae:
	/* 0x5dae: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5db3:
	/* 0x5db3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5db8:
	/* 0x5db8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dbc:
	/* 0x5dbc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5dc0:
	/* 0x5dc0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dc5:
	/* 0x5dc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5dc7:
	/* 0x5dc7: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dcb:
	/* 0x5dcb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5dce:
	/* 0x5dce: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5dd3:
	/* 0x5dd3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dd8:
	/* 0x5dd8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ddc:
	/* 0x5ddc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5de1:
	/* 0x5de1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5de3:
	/* 0x5de3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5de7:
	/* 0x5de7: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5dec:
	/* 0x5dec: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5df1:
	/* 0x5df1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5df6:
	/* 0x5df6: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dfa:
	/* 0x5dfa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5dff:
	/* 0x5dff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e01:
	/* 0x5e01: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e05:
	/* 0x5e05: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e09:
	/* 0x5e09: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e0e:
	/* 0x5e0e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e13:
	/* 0x5e13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e18:
	/* 0x5e18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e1d:
	/* 0x5e1d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_5e20:
	/* 0x5e20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e22:
	/* 0x5e22: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e27:
	/* 0x5e27: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e2c:
	/* 0x5e2c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e30:
	/* 0x5e30: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e35:
	/* 0x5e35: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e3a:
	/* 0x5e3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e3f:
	/* 0x5e3f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e44:
	/* 0x5e44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e46:
	/* 0x5e46: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e4b:
	/* 0x5e4b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5e4e:
	/* 0x5e4e: je     600b <trace_security_mmap_file+0x600b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_600b;
	}
x86_l_5e54:
	/* 0x5e54: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e59:
	/* 0x5e59: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5e5c:
	/* 0x5e5c: je     600b <trace_security_mmap_file+0x600b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_600b;
	}
x86_l_5e62:
	/* 0x5e62: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e66:
	/* 0x5e66: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e6b:
	/* 0x5e6b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5e70:
	/* 0x5e70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e75:
	/* 0x5e75: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5e7a:
	/* 0x5e7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e7c:
	/* 0x5e7c: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5e80:
	/* 0x5e80: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5e82:
	/* 0x5e82: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5e88:
	/* 0x5e88: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5e8a:
	/* 0x5e8a: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5e8c:
	/* 0x5e8c: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_5e92:
	/* 0x5e92: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e97:
	/* 0x5e97: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5e9d:
	/* 0x5e9d: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ea0:
	/* 0x5ea0: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5ea2:
	/* 0x5ea2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5ea7:
	/* 0x5ea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ea9:
	/* 0x5ea9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5eac:
	/* 0x5eac: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_5eb2:
	/* 0x5eb2: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5eb5:
	/* 0x5eb5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ebb:
	/* 0x5ebb: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5ec0:
	/* 0x5ec0: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ec2:
	/* 0x5ec2: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ec7:
	/* 0x5ec7: jmp    6087 <trace_security_mmap_file+0x6087> */
	goto x86_l_6087;
x86_l_5ecc:
	/* 0x5ecc: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5ecf:
	/* 0x5ecf: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_5ed5:
	/* 0x5ed5: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ed9:
	/* 0x5ed9: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_5ede:
	/* 0x5ede: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_5ee4:
	/* 0x5ee4: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ee8:
	/* 0x5ee8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eed:
	/* 0x5eed: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5ef2:
	/* 0x5ef2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ef7:
	/* 0x5ef7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5efb:
	/* 0x5efb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5eff:
	/* 0x5eff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f04:
	/* 0x5f04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f06:
	/* 0x5f06: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f0a:
	/* 0x5f0a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f0d:
	/* 0x5f0d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f12:
	/* 0x5f12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f17:
	/* 0x5f17: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f1b:
	/* 0x5f1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f20:
	/* 0x5f20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f22:
	/* 0x5f22: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f26:
	/* 0x5f26: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f2b:
	/* 0x5f2b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_5f30:
	/* 0x5f30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f35:
	/* 0x5f35: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f39:
	/* 0x5f39: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f3e:
	/* 0x5f3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f40:
	/* 0x5f40: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f44:
	/* 0x5f44: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5f48:
	/* 0x5f48: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f4d:
	/* 0x5f4d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f52:
	/* 0x5f52: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f57:
	/* 0x5f57: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f5c:
	/* 0x5f5c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5f5f:
	/* 0x5f5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f61:
	/* 0x5f61: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f66:
	/* 0x5f66: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6b:
	/* 0x5f6b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f6f:
	/* 0x5f6f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f74:
	/* 0x5f74: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5f79:
	/* 0x5f79: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f7e:
	/* 0x5f7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f83:
	/* 0x5f83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f85:
	/* 0x5f85: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f8a:
	/* 0x5f8a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5f8d:
	/* 0x5f8d: je     614a <trace_security_mmap_file+0x614a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_614a;
	}
x86_l_5f93:
	/* 0x5f93: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f98:
	/* 0x5f98: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5f9b:
	/* 0x5f9b: je     614a <trace_security_mmap_file+0x614a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_614a;
	}
x86_l_5fa1:
	/* 0x5fa1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5fa5:
	/* 0x5fa5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5faa:
	/* 0x5faa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_5faf:
	/* 0x5faf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fb4:
	/* 0x5fb4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5fb9:
	/* 0x5fb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fbb:
	/* 0x5fbb: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5fbf:
	/* 0x5fbf: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5fc1:
	/* 0x5fc1: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5fc7:
	/* 0x5fc7: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5fc9:
	/* 0x5fc9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5fcb:
	/* 0x5fcb: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_5fd1:
	/* 0x5fd1: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5fd6:
	/* 0x5fd6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5fdc:
	/* 0x5fdc: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5fdf:
	/* 0x5fdf: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_5fe1:
	/* 0x5fe1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5fe6:
	/* 0x5fe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe8:
	/* 0x5fe8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5feb:
	/* 0x5feb: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_5ff1:
	/* 0x5ff1: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ff4:
	/* 0x5ff4: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ffa:
	/* 0x5ffa: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5fff:
	/* 0x5fff: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6001:
	/* 0x6001: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6006:
	/* 0x6006: jmp    61c6 <trace_security_mmap_file+0x61c6> */
	goto x86_l_61c6;
x86_l_600b:
	/* 0x600b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_600e:
	/* 0x600e: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_6014:
	/* 0x6014: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6018:
	/* 0x6018: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_601d:
	/* 0x601d: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_6023:
	/* 0x6023: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6027:
	/* 0x6027: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_602c:
	/* 0x602c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6031:
	/* 0x6031: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6036:
	/* 0x6036: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_603a:
	/* 0x603a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_603e:
	/* 0x603e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6043:
	/* 0x6043: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6045:
	/* 0x6045: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6049:
	/* 0x6049: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_604c:
	/* 0x604c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6051:
	/* 0x6051: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6056:
	/* 0x6056: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_605a:
	/* 0x605a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_605f:
	/* 0x605f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6061:
	/* 0x6061: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6065:
	/* 0x6065: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_606a:
	/* 0x606a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_606f:
	/* 0x606f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6074:
	/* 0x6074: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6078:
	/* 0x6078: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_607d:
	/* 0x607d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_607f:
	/* 0x607f: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6083:
	/* 0x6083: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6087:
	/* 0x6087: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_608c:
	/* 0x608c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6091:
	/* 0x6091: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6096:
	/* 0x6096: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_609b:
	/* 0x609b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_609e:
	/* 0x609e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60a0:
	/* 0x60a0: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60a5:
	/* 0x60a5: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60aa:
	/* 0x60aa: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_60ae:
	/* 0x60ae: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60b3:
	/* 0x60b3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_60b8:
	/* 0x60b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60bd:
	/* 0x60bd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60c2:
	/* 0x60c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60c4:
	/* 0x60c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60c9:
	/* 0x60c9: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_60cc:
	/* 0x60cc: je     6289 <trace_security_mmap_file+0x6289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6289;
	}
x86_l_60d2:
	/* 0x60d2: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60d7:
	/* 0x60d7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_60da:
	/* 0x60da: je     6289 <trace_security_mmap_file+0x6289> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6289;
	}
x86_l_60e0:
	/* 0x60e0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_60e4:
	/* 0x60e4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60e9:
	/* 0x60e9: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_60ee:
	/* 0x60ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60f3:
	/* 0x60f3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_60f8:
	/* 0x60f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60fa:
	/* 0x60fa: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_60fe:
	/* 0x60fe: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6100:
	/* 0x6100: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6106:
	/* 0x6106: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6108:
	/* 0x6108: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_610a:
	/* 0x610a: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_6110:
	/* 0x6110: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6115:
	/* 0x6115: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_611b:
	/* 0x611b: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_611e:
	/* 0x611e: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6120:
	/* 0x6120: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6125:
	/* 0x6125: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6127:
	/* 0x6127: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_612a:
	/* 0x612a: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_6130:
	/* 0x6130: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6133:
	/* 0x6133: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6139:
	/* 0x6139: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_613e:
	/* 0x613e: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6140:
	/* 0x6140: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6145:
	/* 0x6145: jmp    6305 <trace_security_mmap_file+0x6305> */
	goto x86_l_6305;
x86_l_614a:
	/* 0x614a: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_614d:
	/* 0x614d: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_6153:
	/* 0x6153: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6157:
	/* 0x6157: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_615c:
	/* 0x615c: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_6162:
	/* 0x6162: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6166:
	/* 0x6166: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_616b:
	/* 0x616b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6170:
	/* 0x6170: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6175:
	/* 0x6175: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6179:
	/* 0x6179: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_617d:
	/* 0x617d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6182:
	/* 0x6182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6184:
	/* 0x6184: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6188:
	/* 0x6188: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_618b:
	/* 0x618b: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6190:
	/* 0x6190: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6195:
	/* 0x6195: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6199:
	/* 0x6199: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_619e:
	/* 0x619e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61a0:
	/* 0x61a0: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61a4:
	/* 0x61a4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61a9:
	/* 0x61a9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_61ae:
	/* 0x61ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61b3:
	/* 0x61b3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61b7:
	/* 0x61b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61bc:
	/* 0x61bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61be:
	/* 0x61be: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61c2:
	/* 0x61c2: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_61c6:
	/* 0x61c6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_61cb:
	/* 0x61cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61d0:
	/* 0x61d0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61d5:
	/* 0x61d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61da:
	/* 0x61da: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_61dd:
	/* 0x61dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61df:
	/* 0x61df: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_61e4:
	/* 0x61e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61e9:
	/* 0x61e9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_61ed:
	/* 0x61ed: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_61f2:
	/* 0x61f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_61f7:
	/* 0x61f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61fc:
	/* 0x61fc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6201:
	/* 0x6201: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6203:
	/* 0x6203: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6208:
	/* 0x6208: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_620b:
	/* 0x620b: je     63c8 <trace_security_mmap_file+0x63c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25544ULL;
	}
x86_l_6211:
	/* 0x6211: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6216:
	/* 0x6216: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6219:
	/* 0x6219: je     63c8 <trace_security_mmap_file+0x63c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25544ULL;
	}
x86_l_621f:
	/* 0x621f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6223:
	/* 0x6223: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6228:
	/* 0x6228: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_622d:
	/* 0x622d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6232:
	/* 0x6232: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6237:
	/* 0x6237: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6239:
	/* 0x6239: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_623d:
	/* 0x623d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_623f:
	/* 0x623f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6245:
	/* 0x6245: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6247:
	/* 0x6247: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6249:
	/* 0x6249: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_624f:
	/* 0x624f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6254:
	/* 0x6254: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_625a:
	/* 0x625a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_625d:
	/* 0x625d: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_625f:
	/* 0x625f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6264:
	/* 0x6264: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6266:
	/* 0x6266: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6269:
	/* 0x6269: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_626f:
	/* 0x626f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6272:
	/* 0x6272: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6278:
	/* 0x6278: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_627d:
	/* 0x627d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_627f:
	/* 0x627f: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6284:
	/* 0x6284: jmp    6444 <trace_security_mmap_file+0x6444> */
	return 25668ULL;
x86_l_6289:
	/* 0x6289: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_628c:
	/* 0x628c: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_6292:
	/* 0x6292: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6296:
	/* 0x6296: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_629b:
	/* 0x629b: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_62a1:
	/* 0x62a1: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_62a5:
	/* 0x62a5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_62aa:
	/* 0x62aa: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_62af:
	/* 0x62af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62b4:
	/* 0x62b4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62b8:
	/* 0x62b8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_62bc:
	/* 0x62bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62c1:
	/* 0x62c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62c3:
	/* 0x62c3: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62c7:
	/* 0x62c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_62ca:
	/* 0x62ca: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_62cf:
	/* 0x62cf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62d4:
	/* 0x62d4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62d8:
	/* 0x62d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62dd:
	/* 0x62dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62df:
	/* 0x62df: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62e3:
	/* 0x62e3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62e8:
	/* 0x62e8: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_62ed:
	/* 0x62ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62f2:
	/* 0x62f2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62f6:
	/* 0x62f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62fb:
	/* 0x62fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62fd:
	/* 0x62fd: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6301:
	/* 0x6301: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6305:
	/* 0x6305: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_630a:
	/* 0x630a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_630f:
	/* 0x630f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6314:
	/* 0x6314: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 25369ULL;
}

static __noinline __u64 tracee_trace_security_mmap_file_x86_chunk_15(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 25369ULL: goto x86_l_6319;
	case 25372ULL: goto x86_l_631c;
	case 25374ULL: goto x86_l_631e;
	case 25379ULL: goto x86_l_6323;
	case 25384ULL: goto x86_l_6328;
	case 25388ULL: goto x86_l_632c;
	case 25393ULL: goto x86_l_6331;
	case 25398ULL: goto x86_l_6336;
	case 25403ULL: goto x86_l_633b;
	case 25408ULL: goto x86_l_6340;
	case 25410ULL: goto x86_l_6342;
	case 25415ULL: goto x86_l_6347;
	case 25418ULL: goto x86_l_634a;
	case 25424ULL: goto x86_l_6350;
	case 25429ULL: goto x86_l_6355;
	case 25432ULL: goto x86_l_6358;
	case 25438ULL: goto x86_l_635e;
	case 25442ULL: goto x86_l_6362;
	case 25447ULL: goto x86_l_6367;
	case 25452ULL: goto x86_l_636c;
	case 25457ULL: goto x86_l_6371;
	case 25462ULL: goto x86_l_6376;
	case 25464ULL: goto x86_l_6378;
	case 25468ULL: goto x86_l_637c;
	case 25470ULL: goto x86_l_637e;
	case 25476ULL: goto x86_l_6384;
	case 25478ULL: goto x86_l_6386;
	case 25480ULL: goto x86_l_6388;
	case 25486ULL: goto x86_l_638e;
	case 25491ULL: goto x86_l_6393;
	case 25497ULL: goto x86_l_6399;
	case 25500ULL: goto x86_l_639c;
	case 25502ULL: goto x86_l_639e;
	case 25507ULL: goto x86_l_63a3;
	case 25509ULL: goto x86_l_63a5;
	case 25512ULL: goto x86_l_63a8;
	case 25518ULL: goto x86_l_63ae;
	case 25521ULL: goto x86_l_63b1;
	case 25527ULL: goto x86_l_63b7;
	case 25532ULL: goto x86_l_63bc;
	case 25534ULL: goto x86_l_63be;
	case 25539ULL: goto x86_l_63c3;
	case 25544ULL: goto x86_l_63c8;
	case 25547ULL: goto x86_l_63cb;
	case 25553ULL: goto x86_l_63d1;
	case 25557ULL: goto x86_l_63d5;
	case 25562ULL: goto x86_l_63da;
	case 25568ULL: goto x86_l_63e0;
	case 25572ULL: goto x86_l_63e4;
	case 25577ULL: goto x86_l_63e9;
	case 25582ULL: goto x86_l_63ee;
	case 25587ULL: goto x86_l_63f3;
	case 25591ULL: goto x86_l_63f7;
	case 25595ULL: goto x86_l_63fb;
	case 25600ULL: goto x86_l_6400;
	case 25602ULL: goto x86_l_6402;
	case 25606ULL: goto x86_l_6406;
	case 25609ULL: goto x86_l_6409;
	case 25614ULL: goto x86_l_640e;
	case 25619ULL: goto x86_l_6413;
	case 25623ULL: goto x86_l_6417;
	case 25628ULL: goto x86_l_641c;
	case 25630ULL: goto x86_l_641e;
	case 25634ULL: goto x86_l_6422;
	case 25639ULL: goto x86_l_6427;
	case 25644ULL: goto x86_l_642c;
	case 25649ULL: goto x86_l_6431;
	case 25653ULL: goto x86_l_6435;
	case 25658ULL: goto x86_l_643a;
	case 25660ULL: goto x86_l_643c;
	case 25664ULL: goto x86_l_6440;
	case 25668ULL: goto x86_l_6444;
	case 25673ULL: goto x86_l_6449;
	case 25678ULL: goto x86_l_644e;
	case 25683ULL: goto x86_l_6453;
	case 25688ULL: goto x86_l_6458;
	case 25691ULL: goto x86_l_645b;
	case 25693ULL: goto x86_l_645d;
	case 25698ULL: goto x86_l_6462;
	case 25703ULL: goto x86_l_6467;
	case 25707ULL: goto x86_l_646b;
	case 25712ULL: goto x86_l_6470;
	case 25717ULL: goto x86_l_6475;
	case 25722ULL: goto x86_l_647a;
	case 25727ULL: goto x86_l_647f;
	case 25729ULL: goto x86_l_6481;
	case 25734ULL: goto x86_l_6486;
	case 25737ULL: goto x86_l_6489;
	case 25743ULL: goto x86_l_648f;
	case 25748ULL: goto x86_l_6494;
	case 25751ULL: goto x86_l_6497;
	case 25757ULL: goto x86_l_649d;
	case 25761ULL: goto x86_l_64a1;
	case 25766ULL: goto x86_l_64a6;
	case 25771ULL: goto x86_l_64ab;
	case 25776ULL: goto x86_l_64b0;
	case 25781ULL: goto x86_l_64b5;
	case 25783ULL: goto x86_l_64b7;
	case 25787ULL: goto x86_l_64bb;
	case 25789ULL: goto x86_l_64bd;
	case 25795ULL: goto x86_l_64c3;
	case 25797ULL: goto x86_l_64c5;
	case 25799ULL: goto x86_l_64c7;
	case 25805ULL: goto x86_l_64cd;
	case 25810ULL: goto x86_l_64d2;
	case 25816ULL: goto x86_l_64d8;
	case 25819ULL: goto x86_l_64db;
	case 25821ULL: goto x86_l_64dd;
	case 25826ULL: goto x86_l_64e2;
	case 25828ULL: goto x86_l_64e4;
	case 25831ULL: goto x86_l_64e7;
	case 25837ULL: goto x86_l_64ed;
	case 25840ULL: goto x86_l_64f0;
	case 25846ULL: goto x86_l_64f6;
	case 25851ULL: goto x86_l_64fb;
	case 25853ULL: goto x86_l_64fd;
	case 25858ULL: goto x86_l_6502;
	case 25863ULL: goto x86_l_6507;
	case 25866ULL: goto x86_l_650a;
	case 25872ULL: goto x86_l_6510;
	case 25876ULL: goto x86_l_6514;
	case 25881ULL: goto x86_l_6519;
	case 25887ULL: goto x86_l_651f;
	case 25891ULL: goto x86_l_6523;
	case 25896ULL: goto x86_l_6528;
	case 25901ULL: goto x86_l_652d;
	case 25906ULL: goto x86_l_6532;
	case 25910ULL: goto x86_l_6536;
	case 25914ULL: goto x86_l_653a;
	case 25919ULL: goto x86_l_653f;
	case 25921ULL: goto x86_l_6541;
	case 25925ULL: goto x86_l_6545;
	case 25928ULL: goto x86_l_6548;
	case 25933ULL: goto x86_l_654d;
	case 25938ULL: goto x86_l_6552;
	case 25942ULL: goto x86_l_6556;
	case 25947ULL: goto x86_l_655b;
	case 25949ULL: goto x86_l_655d;
	case 25953ULL: goto x86_l_6561;
	case 25958ULL: goto x86_l_6566;
	case 25963ULL: goto x86_l_656b;
	case 25968ULL: goto x86_l_6570;
	case 25972ULL: goto x86_l_6574;
	case 25977ULL: goto x86_l_6579;
	case 25979ULL: goto x86_l_657b;
	case 25983ULL: goto x86_l_657f;
	case 25987ULL: goto x86_l_6583;
	case 25992ULL: goto x86_l_6588;
	case 25997ULL: goto x86_l_658d;
	case 26002ULL: goto x86_l_6592;
	case 26007ULL: goto x86_l_6597;
	case 26010ULL: goto x86_l_659a;
	case 26012ULL: goto x86_l_659c;
	case 26017ULL: goto x86_l_65a1;
	case 26022ULL: goto x86_l_65a6;
	case 26026ULL: goto x86_l_65aa;
	case 26031ULL: goto x86_l_65af;
	case 26036ULL: goto x86_l_65b4;
	case 26041ULL: goto x86_l_65b9;
	case 26046ULL: goto x86_l_65be;
	case 26048ULL: goto x86_l_65c0;
	case 26053ULL: goto x86_l_65c5;
	case 26056ULL: goto x86_l_65c8;
	case 26062ULL: goto x86_l_65ce;
	case 26067ULL: goto x86_l_65d3;
	case 26070ULL: goto x86_l_65d6;
	case 26076ULL: goto x86_l_65dc;
	case 26080ULL: goto x86_l_65e0;
	case 26085ULL: goto x86_l_65e5;
	case 26090ULL: goto x86_l_65ea;
	case 26095ULL: goto x86_l_65ef;
	case 26100ULL: goto x86_l_65f4;
	case 26102ULL: goto x86_l_65f6;
	case 26106ULL: goto x86_l_65fa;
	case 26108ULL: goto x86_l_65fc;
	case 26114ULL: goto x86_l_6602;
	case 26116ULL: goto x86_l_6604;
	case 26118ULL: goto x86_l_6606;
	case 26124ULL: goto x86_l_660c;
	case 26129ULL: goto x86_l_6611;
	case 26135ULL: goto x86_l_6617;
	case 26138ULL: goto x86_l_661a;
	case 26140ULL: goto x86_l_661c;
	case 26145ULL: goto x86_l_6621;
	case 26147ULL: goto x86_l_6623;
	case 26150ULL: goto x86_l_6626;
	case 26156ULL: goto x86_l_662c;
	case 26159ULL: goto x86_l_662f;
	case 26165ULL: goto x86_l_6635;
	case 26170ULL: goto x86_l_663a;
	case 26172ULL: goto x86_l_663c;
	case 26177ULL: goto x86_l_6641;
	case 26182ULL: goto x86_l_6646;
	case 26185ULL: goto x86_l_6649;
	case 26191ULL: goto x86_l_664f;
	case 26195ULL: goto x86_l_6653;
	case 26200ULL: goto x86_l_6658;
	case 26206ULL: goto x86_l_665e;
	case 26210ULL: goto x86_l_6662;
	case 26215ULL: goto x86_l_6667;
	case 26220ULL: goto x86_l_666c;
	case 26225ULL: goto x86_l_6671;
	case 26229ULL: goto x86_l_6675;
	case 26233ULL: goto x86_l_6679;
	case 26238ULL: goto x86_l_667e;
	case 26240ULL: goto x86_l_6680;
	case 26244ULL: goto x86_l_6684;
	case 26247ULL: goto x86_l_6687;
	case 26252ULL: goto x86_l_668c;
	case 26257ULL: goto x86_l_6691;
	case 26261ULL: goto x86_l_6695;
	case 26266ULL: goto x86_l_669a;
	case 26268ULL: goto x86_l_669c;
	case 26272ULL: goto x86_l_66a0;
	case 26277ULL: goto x86_l_66a5;
	case 26282ULL: goto x86_l_66aa;
	case 26287ULL: goto x86_l_66af;
	case 26291ULL: goto x86_l_66b3;
	case 26296ULL: goto x86_l_66b8;
	case 26298ULL: goto x86_l_66ba;
	case 26302ULL: goto x86_l_66be;
	case 26306ULL: goto x86_l_66c2;
	case 26311ULL: goto x86_l_66c7;
	case 26316ULL: goto x86_l_66cc;
	case 26321ULL: goto x86_l_66d1;
	case 26326ULL: goto x86_l_66d6;
	case 26329ULL: goto x86_l_66d9;
	case 26331ULL: goto x86_l_66db;
	case 26336ULL: goto x86_l_66e0;
	case 26341ULL: goto x86_l_66e5;
	case 26345ULL: goto x86_l_66e9;
	case 26350ULL: goto x86_l_66ee;
	case 26355ULL: goto x86_l_66f3;
	case 26360ULL: goto x86_l_66f8;
	case 26365ULL: goto x86_l_66fd;
	case 26367ULL: goto x86_l_66ff;
	case 26372ULL: goto x86_l_6704;
	case 26375ULL: goto x86_l_6707;
	case 26381ULL: goto x86_l_670d;
	case 26386ULL: goto x86_l_6712;
	case 26389ULL: goto x86_l_6715;
	case 26395ULL: goto x86_l_671b;
	case 26399ULL: goto x86_l_671f;
	case 26404ULL: goto x86_l_6724;
	case 26409ULL: goto x86_l_6729;
	case 26414ULL: goto x86_l_672e;
	case 26419ULL: goto x86_l_6733;
	case 26421ULL: goto x86_l_6735;
	case 26425ULL: goto x86_l_6739;
	case 26427ULL: goto x86_l_673b;
	case 26433ULL: goto x86_l_6741;
	case 26435ULL: goto x86_l_6743;
	case 26437ULL: goto x86_l_6745;
	case 26443ULL: goto x86_l_674b;
	case 26448ULL: goto x86_l_6750;
	case 26454ULL: goto x86_l_6756;
	case 26457ULL: goto x86_l_6759;
	case 26459ULL: goto x86_l_675b;
	case 26464ULL: goto x86_l_6760;
	case 26466ULL: goto x86_l_6762;
	case 26469ULL: goto x86_l_6765;
	case 26475ULL: goto x86_l_676b;
	case 26478ULL: goto x86_l_676e;
	case 26484ULL: goto x86_l_6774;
	case 26489ULL: goto x86_l_6779;
	case 26491ULL: goto x86_l_677b;
	case 26496ULL: goto x86_l_6780;
	case 26501ULL: goto x86_l_6785;
	case 26504ULL: goto x86_l_6788;
	case 26510ULL: goto x86_l_678e;
	case 26514ULL: goto x86_l_6792;
	case 26519ULL: goto x86_l_6797;
	case 26525ULL: goto x86_l_679d;
	case 26529ULL: goto x86_l_67a1;
	case 26534ULL: goto x86_l_67a6;
	case 26539ULL: goto x86_l_67ab;
	case 26544ULL: goto x86_l_67b0;
	case 26548ULL: goto x86_l_67b4;
	case 26552ULL: goto x86_l_67b8;
	case 26557ULL: goto x86_l_67bd;
	case 26559ULL: goto x86_l_67bf;
	case 26563ULL: goto x86_l_67c3;
	case 26566ULL: goto x86_l_67c6;
	case 26571ULL: goto x86_l_67cb;
	case 26576ULL: goto x86_l_67d0;
	case 26580ULL: goto x86_l_67d4;
	case 26585ULL: goto x86_l_67d9;
	case 26587ULL: goto x86_l_67db;
	case 26591ULL: goto x86_l_67df;
	case 26596ULL: goto x86_l_67e4;
	case 26601ULL: goto x86_l_67e9;
	case 26606ULL: goto x86_l_67ee;
	case 26610ULL: goto x86_l_67f2;
	case 26615ULL: goto x86_l_67f7;
	case 26617ULL: goto x86_l_67f9;
	case 26622ULL: goto x86_l_67fe;
	case 26625ULL: goto x86_l_6801;
	case 26631ULL: goto x86_l_6807;
	case 26635ULL: goto x86_l_680b;
	case 26640ULL: goto x86_l_6810;
	case 26646ULL: goto x86_l_6816;
	case 26650ULL: goto x86_l_681a;
	case 26655ULL: goto x86_l_681f;
	case 26660ULL: goto x86_l_6824;
	case 26665ULL: goto x86_l_6829;
	case 26669ULL: goto x86_l_682d;
	case 26673ULL: goto x86_l_6831;
	case 26678ULL: goto x86_l_6836;
	case 26680ULL: goto x86_l_6838;
	case 26684ULL: goto x86_l_683c;
	case 26687ULL: goto x86_l_683f;
	case 26692ULL: goto x86_l_6844;
	case 26697ULL: goto x86_l_6849;
	case 26701ULL: goto x86_l_684d;
	case 26706ULL: goto x86_l_6852;
	case 26708ULL: goto x86_l_6854;
	case 26712ULL: goto x86_l_6858;
	case 26717ULL: goto x86_l_685d;
	case 26722ULL: goto x86_l_6862;
	case 26727ULL: goto x86_l_6867;
	case 26731ULL: goto x86_l_686b;
	case 26736ULL: goto x86_l_6870;
	case 26738ULL: goto x86_l_6872;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6319:
	/* 0x6319: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_631c:
	/* 0x631c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_631e:
	/* 0x631e: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6323:
	/* 0x6323: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6328:
	/* 0x6328: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_632c:
	/* 0x632c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6331:
	/* 0x6331: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6336:
	/* 0x6336: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_633b:
	/* 0x633b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6340:
	/* 0x6340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6342:
	/* 0x6342: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6347:
	/* 0x6347: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_634a:
	/* 0x634a: je     6507 <trace_security_mmap_file+0x6507> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6507;
	}
x86_l_6350:
	/* 0x6350: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6355:
	/* 0x6355: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6358:
	/* 0x6358: je     6507 <trace_security_mmap_file+0x6507> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6507;
	}
x86_l_635e:
	/* 0x635e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6362:
	/* 0x6362: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6367:
	/* 0x6367: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_636c:
	/* 0x636c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6371:
	/* 0x6371: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6376:
	/* 0x6376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6378:
	/* 0x6378: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_637c:
	/* 0x637c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_637e:
	/* 0x637e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6384:
	/* 0x6384: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6386:
	/* 0x6386: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6388:
	/* 0x6388: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_638e:
	/* 0x638e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6393:
	/* 0x6393: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6399:
	/* 0x6399: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_639c:
	/* 0x639c: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_639e:
	/* 0x639e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_63a3:
	/* 0x63a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63a5:
	/* 0x63a5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_63a8:
	/* 0x63a8: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_63ae:
	/* 0x63ae: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_63b1:
	/* 0x63b1: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_63b7:
	/* 0x63b7: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_63bc:
	/* 0x63bc: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_63be:
	/* 0x63be: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63c3:
	/* 0x63c3: jmp    6583 <trace_security_mmap_file+0x6583> */
	goto x86_l_6583;
x86_l_63c8:
	/* 0x63c8: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_63cb:
	/* 0x63cb: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_63d1:
	/* 0x63d1: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63d5:
	/* 0x63d5: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_63da:
	/* 0x63da: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_63e0:
	/* 0x63e0: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_63e4:
	/* 0x63e4: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_63e9:
	/* 0x63e9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_63ee:
	/* 0x63ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63f3:
	/* 0x63f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63f7:
	/* 0x63f7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_63fb:
	/* 0x63fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6400:
	/* 0x6400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6402:
	/* 0x6402: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6406:
	/* 0x6406: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6409:
	/* 0x6409: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_640e:
	/* 0x640e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6413:
	/* 0x6413: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6417:
	/* 0x6417: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_641c:
	/* 0x641c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_641e:
	/* 0x641e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6422:
	/* 0x6422: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6427:
	/* 0x6427: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_642c:
	/* 0x642c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6431:
	/* 0x6431: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6435:
	/* 0x6435: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_643a:
	/* 0x643a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_643c:
	/* 0x643c: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6440:
	/* 0x6440: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6444:
	/* 0x6444: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6449:
	/* 0x6449: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_644e:
	/* 0x644e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6453:
	/* 0x6453: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6458:
	/* 0x6458: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_645b:
	/* 0x645b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_645d:
	/* 0x645d: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6462:
	/* 0x6462: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6467:
	/* 0x6467: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_646b:
	/* 0x646b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6470:
	/* 0x6470: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6475:
	/* 0x6475: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_647a:
	/* 0x647a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_647f:
	/* 0x647f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6481:
	/* 0x6481: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6486:
	/* 0x6486: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6489:
	/* 0x6489: je     6646 <trace_security_mmap_file+0x6646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6646;
	}
x86_l_648f:
	/* 0x648f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6494:
	/* 0x6494: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6497:
	/* 0x6497: je     6646 <trace_security_mmap_file+0x6646> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6646;
	}
x86_l_649d:
	/* 0x649d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_64a1:
	/* 0x64a1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64a6:
	/* 0x64a6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_64ab:
	/* 0x64ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64b0:
	/* 0x64b0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_64b5:
	/* 0x64b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64b7:
	/* 0x64b7: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_64bb:
	/* 0x64bb: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_64bd:
	/* 0x64bd: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_64c3:
	/* 0x64c3: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_64c5:
	/* 0x64c5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_64c7:
	/* 0x64c7: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_64cd:
	/* 0x64cd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_64d2:
	/* 0x64d2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_64d8:
	/* 0x64d8: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_64db:
	/* 0x64db: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_64dd:
	/* 0x64dd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_64e2:
	/* 0x64e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e4:
	/* 0x64e4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64e7:
	/* 0x64e7: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_64ed:
	/* 0x64ed: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_64f0:
	/* 0x64f0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_64f6:
	/* 0x64f6: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_64fb:
	/* 0x64fb: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_64fd:
	/* 0x64fd: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6502:
	/* 0x6502: jmp    66c2 <trace_security_mmap_file+0x66c2> */
	goto x86_l_66c2;
x86_l_6507:
	/* 0x6507: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_650a:
	/* 0x650a: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_6510:
	/* 0x6510: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6514:
	/* 0x6514: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6519:
	/* 0x6519: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_651f:
	/* 0x651f: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6523:
	/* 0x6523: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6528:
	/* 0x6528: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_652d:
	/* 0x652d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6532:
	/* 0x6532: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6536:
	/* 0x6536: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_653a:
	/* 0x653a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_653f:
	/* 0x653f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6541:
	/* 0x6541: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6545:
	/* 0x6545: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6548:
	/* 0x6548: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_654d:
	/* 0x654d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6552:
	/* 0x6552: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6556:
	/* 0x6556: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_655b:
	/* 0x655b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655d:
	/* 0x655d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6561:
	/* 0x6561: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6566:
	/* 0x6566: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_656b:
	/* 0x656b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6570:
	/* 0x6570: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6574:
	/* 0x6574: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6579:
	/* 0x6579: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_657b:
	/* 0x657b: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_657f:
	/* 0x657f: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6583:
	/* 0x6583: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6588:
	/* 0x6588: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_658d:
	/* 0x658d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6592:
	/* 0x6592: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6597:
	/* 0x6597: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_659a:
	/* 0x659a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659c:
	/* 0x659c: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65a1:
	/* 0x65a1: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65a6:
	/* 0x65a6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_65aa:
	/* 0x65aa: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65af:
	/* 0x65af: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_65b4:
	/* 0x65b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65b9:
	/* 0x65b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65be:
	/* 0x65be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65c0:
	/* 0x65c0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_65c5:
	/* 0x65c5: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_65c8:
	/* 0x65c8: je     6785 <trace_security_mmap_file+0x6785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6785;
	}
x86_l_65ce:
	/* 0x65ce: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65d3:
	/* 0x65d3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_65d6:
	/* 0x65d6: je     6785 <trace_security_mmap_file+0x6785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6785;
	}
x86_l_65dc:
	/* 0x65dc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_65e0:
	/* 0x65e0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65e5:
	/* 0x65e5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_65ea:
	/* 0x65ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65ef:
	/* 0x65ef: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_65f4:
	/* 0x65f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65f6:
	/* 0x65f6: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_65fa:
	/* 0x65fa: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_65fc:
	/* 0x65fc: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6602:
	/* 0x6602: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6604:
	/* 0x6604: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6606:
	/* 0x6606: jb     40ad <trace_security_mmap_file+0x40ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 16557ULL;
	}
x86_l_660c:
	/* 0x660c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6611:
	/* 0x6611: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6617:
	/* 0x6617: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_661a:
	/* 0x661a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_661c:
	/* 0x661c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6621:
	/* 0x6621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6623:
	/* 0x6623: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6626:
	/* 0x6626: jl     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 17579ULL;
	}
x86_l_662c:
	/* 0x662c: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_662f:
	/* 0x662f: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6635:
	/* 0x6635: mov    BYTE PTR [r12+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_663a:
	/* 0x663a: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_663c:
	/* 0x663c: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6641:
	/* 0x6641: jmp    44ab <trace_security_mmap_file+0x44ab> */
	return 17579ULL;
x86_l_6646:
	/* 0x6646: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6649:
	/* 0x6649: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_664f:
	/* 0x664f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6653:
	/* 0x6653: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6658:
	/* 0x6658: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_665e:
	/* 0x665e: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6662:
	/* 0x6662: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6667:
	/* 0x6667: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_666c:
	/* 0x666c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6671:
	/* 0x6671: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6675:
	/* 0x6675: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6679:
	/* 0x6679: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_667e:
	/* 0x667e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6680:
	/* 0x6680: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6684:
	/* 0x6684: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6687:
	/* 0x6687: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_668c:
	/* 0x668c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6691:
	/* 0x6691: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6695:
	/* 0x6695: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_669a:
	/* 0x669a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_669c:
	/* 0x669c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66a0:
	/* 0x66a0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66a5:
	/* 0x66a5: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_66aa:
	/* 0x66aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66af:
	/* 0x66af: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66b3:
	/* 0x66b3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66b8:
	/* 0x66b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66ba:
	/* 0x66ba: mov    r13,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66be:
	/* 0x66be: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_66c2:
	/* 0x66c2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66c7:
	/* 0x66c7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66cc:
	/* 0x66cc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66d1:
	/* 0x66d1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66d6:
	/* 0x66d6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_66d9:
	/* 0x66d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66db:
	/* 0x66db: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66e0:
	/* 0x66e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_66e5:
	/* 0x66e5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_66e9:
	/* 0x66e9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66ee:
	/* 0x66ee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66f3:
	/* 0x66f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66f8:
	/* 0x66f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66fd:
	/* 0x66fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66ff:
	/* 0x66ff: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6704:
	/* 0x6704: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6707:
	/* 0x6707: je     67fe <trace_security_mmap_file+0x67fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67fe;
	}
x86_l_670d:
	/* 0x670d: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6712:
	/* 0x6712: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6715:
	/* 0x6715: je     67fe <trace_security_mmap_file+0x67fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67fe;
	}
x86_l_671b:
	/* 0x671b: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_671f:
	/* 0x671f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6724:
	/* 0x6724: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6729:
	/* 0x6729: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_672e:
	/* 0x672e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6733:
	/* 0x6733: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6735:
	/* 0x6735: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6739:
	/* 0x6739: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_673b:
	/* 0x673b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6741:
	/* 0x6741: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6743:
	/* 0x6743: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6745:
	/* 0x6745: jb     2fe8 <trace_security_mmap_file+0x2fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12264ULL;
	}
x86_l_674b:
	/* 0x674b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6750:
	/* 0x6750: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6756:
	/* 0x6756: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6759:
	/* 0x6759: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_675b:
	/* 0x675b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6760:
	/* 0x6760: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6762:
	/* 0x6762: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6765:
	/* 0x6765: jl     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 11533ULL;
	}
x86_l_676b:
	/* 0x676b: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_676e:
	/* 0x676e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6774:
	/* 0x6774: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6779:
	/* 0x6779: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_677b:
	/* 0x677b: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6780:
	/* 0x6780: jmp    2d0d <trace_security_mmap_file+0x2d0d> */
	return 11533ULL;
x86_l_6785:
	/* 0x6785: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6788:
	/* 0x6788: jne    44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17579ULL;
	}
x86_l_678e:
	/* 0x678e: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6792:
	/* 0x6792: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6797:
	/* 0x6797: je     44ab <trace_security_mmap_file+0x44ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17579ULL;
	}
x86_l_679d:
	/* 0x679d: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_67a1:
	/* 0x67a1: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67a6:
	/* 0x67a6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_67ab:
	/* 0x67ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67b0:
	/* 0x67b0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67b4:
	/* 0x67b4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_67b8:
	/* 0x67b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67bd:
	/* 0x67bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67bf:
	/* 0x67bf: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67c3:
	/* 0x67c3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_67c6:
	/* 0x67c6: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_67cb:
	/* 0x67cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67d0:
	/* 0x67d0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67d4:
	/* 0x67d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67d9:
	/* 0x67d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67db:
	/* 0x67db: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67df:
	/* 0x67df: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67e4:
	/* 0x67e4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_67e9:
	/* 0x67e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67ee:
	/* 0x67ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67f2:
	/* 0x67f2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67f7:
	/* 0x67f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67f9:
	/* 0x67f9: jmp    44ab <trace_security_mmap_file+0x44ab> */
	return 17579ULL;
x86_l_67fe:
	/* 0x67fe: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6801:
	/* 0x6801: jne    2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11533ULL;
	}
x86_l_6807:
	/* 0x6807: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_680b:
	/* 0x680b: cmp    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6810:
	/* 0x6810: je     2d0d <trace_security_mmap_file+0x2d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11533ULL;
	}
x86_l_6816:
	/* 0x6816: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_681a:
	/* 0x681a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_681f:
	/* 0x681f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6824:
	/* 0x6824: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6829:
	/* 0x6829: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_682d:
	/* 0x682d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6831:
	/* 0x6831: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6836:
	/* 0x6836: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6838:
	/* 0x6838: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_683c:
	/* 0x683c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_683f:
	/* 0x683f: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6844:
	/* 0x6844: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6849:
	/* 0x6849: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_684d:
	/* 0x684d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6852:
	/* 0x6852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6854:
	/* 0x6854: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6858:
	/* 0x6858: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_685d:
	/* 0x685d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6862:
	/* 0x6862: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6867:
	/* 0x6867: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_686b:
	/* 0x686b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6870:
	/* 0x6870: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6872:
	/* 0x6872: jmp    2d0d <trace_security_mmap_file+0x2d0d> */
	return 11533ULL;
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
	for (__u32 __x86_iter = 0; __x86_iter < 24332U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2137ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2140ULL && __x86_pc <= 3859ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3862ULL && __x86_pc <= 5449ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5452ULL && __x86_pc <= 7204ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7209ULL && __x86_pc <= 8941ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8948ULL && __x86_pc <= 10532ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10537ULL && __x86_pc <= 12150ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12152ULL && __x86_pc <= 13964ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13969ULL && __x86_pc <= 15613ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15618ULL && __x86_pc <= 17222ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17228ULL && __x86_pc <= 18828ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 18833ULL && __x86_pc <= 20464ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 20468ULL && __x86_pc <= 22097ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 22100ULL && __x86_pc <= 23730ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 23735ULL && __x86_pc <= 25364ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_14(__x86_state, __x86_pc);
		else if (__x86_pc >= 25369ULL && __x86_pc <= 26738ULL)
			__x86_pc = tracee_trace_security_mmap_file_x86_chunk_15(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char binary_filter_version;
extern char bufs;
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

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_0(
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
	case 90ULL: goto x86_l_5a;
	case 95ULL: goto x86_l_5f;
	case 100ULL: goto x86_l_64;
	case 105ULL: goto x86_l_69;
	case 107ULL: goto x86_l_6b;
	case 111ULL: goto x86_l_6f;
	case 115ULL: goto x86_l_73;
	case 120ULL: goto x86_l_78;
	case 125ULL: goto x86_l_7d;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 135ULL: goto x86_l_87;
	case 140ULL: goto x86_l_8c;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 153ULL: goto x86_l_99;
	case 160ULL: goto x86_l_a0;
	case 165ULL: goto x86_l_a5;
	case 167ULL: goto x86_l_a7;
	case 170ULL: goto x86_l_aa;
	case 172ULL: goto x86_l_ac;
	case 174ULL: goto x86_l_ae;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 201ULL: goto x86_l_c9;
	case 206ULL: goto x86_l_ce;
	case 208ULL: goto x86_l_d0;
	case 211ULL: goto x86_l_d3;
	case 217ULL: goto x86_l_d9;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 248ULL: goto x86_l_f8;
	case 251ULL: goto x86_l_fb;
	case 261ULL: goto x86_l_105;
	case 269ULL: goto x86_l_10d;
	case 280ULL: goto x86_l_118;
	case 291ULL: goto x86_l_123;
	case 302ULL: goto x86_l_12e;
	case 313ULL: goto x86_l_139;
	case 324ULL: goto x86_l_144;
	case 335ULL: goto x86_l_14f;
	case 346ULL: goto x86_l_15a;
	case 357ULL: goto x86_l_165;
	case 364ULL: goto x86_l_16c;
	case 372ULL: goto x86_l_174;
	case 380ULL: goto x86_l_17c;
	case 388ULL: goto x86_l_184;
	case 396ULL: goto x86_l_18c;
	case 404ULL: goto x86_l_194;
	case 412ULL: goto x86_l_19c;
	case 420ULL: goto x86_l_1a4;
	case 428ULL: goto x86_l_1ac;
	case 436ULL: goto x86_l_1b4;
	case 444ULL: goto x86_l_1bc;
	case 452ULL: goto x86_l_1c4;
	case 460ULL: goto x86_l_1cc;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 475ULL: goto x86_l_1db;
	case 479ULL: goto x86_l_1df;
	case 483ULL: goto x86_l_1e3;
	case 487ULL: goto x86_l_1e7;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 502ULL: goto x86_l_1f6;
	case 505ULL: goto x86_l_1f9;
	case 510ULL: goto x86_l_1fe;
	case 512ULL: goto x86_l_200;
	case 517ULL: goto x86_l_205;
	case 521ULL: goto x86_l_209;
	case 525ULL: goto x86_l_20d;
	case 529ULL: goto x86_l_211;
	case 534ULL: goto x86_l_216;
	case 541ULL: goto x86_l_21d;
	case 546ULL: goto x86_l_222;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 556ULL: goto x86_l_22c;
	case 558ULL: goto x86_l_22e;
	case 562ULL: goto x86_l_232;
	case 566ULL: goto x86_l_236;
	case 571ULL: goto x86_l_23b;
	case 578ULL: goto x86_l_242;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 588ULL: goto x86_l_24c;
	case 591ULL: goto x86_l_24f;
	case 599ULL: goto x86_l_257;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 619ULL: goto x86_l_26b;
	case 625ULL: goto x86_l_271;
	case 630ULL: goto x86_l_276;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 641ULL: goto x86_l_281;
	case 645ULL: goto x86_l_285;
	case 653ULL: goto x86_l_28d;
	case 658ULL: goto x86_l_292;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 672ULL: goto x86_l_2a0;
	case 675ULL: goto x86_l_2a3;
	case 681ULL: goto x86_l_2a9;
	case 685ULL: goto x86_l_2ad;
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
	case 1008ULL: goto x86_l_3f0;
	case 1019ULL: goto x86_l_3fb;
	case 1027ULL: goto x86_l_403;
	case 1035ULL: goto x86_l_40b;
	case 1043ULL: goto x86_l_413;
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
	case 1146ULL: goto x86_l_47a;
	case 1152ULL: goto x86_l_480;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1169ULL: goto x86_l_491;
	case 1172ULL: goto x86_l_494;
	case 1175ULL: goto x86_l_497;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1188ULL: goto x86_l_4a4;
	case 1191ULL: goto x86_l_4a7;
	case 1193ULL: goto x86_l_4a9;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1212ULL: goto x86_l_4bc;
	case 1216ULL: goto x86_l_4c0;
	case 1220ULL: goto x86_l_4c4;
	case 1228ULL: goto x86_l_4cc;
	case 1233ULL: goto x86_l_4d1;
	case 1240ULL: goto x86_l_4d8;
	case 1245ULL: goto x86_l_4dd;
	case 1247ULL: goto x86_l_4df;
	case 1250ULL: goto x86_l_4e2;
	case 1256ULL: goto x86_l_4e8;
	case 1260ULL: goto x86_l_4ec;
	case 1264ULL: goto x86_l_4f0;
	case 1275ULL: goto x86_l_4fb;
	case 1286ULL: goto x86_l_506;
	case 1297ULL: goto x86_l_511;
	case 1308ULL: goto x86_l_51c;
	case 1319ULL: goto x86_l_527;
	case 1330ULL: goto x86_l_532;
	case 1341ULL: goto x86_l_53d;
	case 1352ULL: goto x86_l_548;
	case 1363ULL: goto x86_l_553;
	case 1371ULL: goto x86_l_55b;
	case 1379ULL: goto x86_l_563;
	case 1387ULL: goto x86_l_56b;
	case 1395ULL: goto x86_l_573;
	case 1403ULL: goto x86_l_57b;
	case 1411ULL: goto x86_l_583;
	case 1419ULL: goto x86_l_58b;
	case 1427ULL: goto x86_l_593;
	case 1435ULL: goto x86_l_59b;
	case 1443ULL: goto x86_l_5a3;
	case 1451ULL: goto x86_l_5ab;
	case 1459ULL: goto x86_l_5b3;
	case 1467ULL: goto x86_l_5bb;
	case 1475ULL: goto x86_l_5c3;
	case 1483ULL: goto x86_l_5cb;
	case 1490ULL: goto x86_l_5d2;
	case 1496ULL: goto x86_l_5d8;
	case 1503ULL: goto x86_l_5df;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1516ULL: goto x86_l_5ec;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1527ULL: goto x86_l_5f7;
	case 1532ULL: goto x86_l_5fc;
	case 1535ULL: goto x86_l_5ff;
	case 1537ULL: goto x86_l_601;
	case 1540ULL: goto x86_l_604;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1556ULL: goto x86_l_614;
	case 1560ULL: goto x86_l_618;
	case 1565ULL: goto x86_l_61d;
	case 1570ULL: goto x86_l_622;
	case 1575ULL: goto x86_l_627;
	case 1578ULL: goto x86_l_62a;
	case 1580ULL: goto x86_l_62c;
	case 1585ULL: goto x86_l_631;
	case 1589ULL: goto x86_l_635;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1619ULL: goto x86_l_653;
	case 1624ULL: goto x86_l_658;
	case 1629ULL: goto x86_l_65d;
	case 1634ULL: goto x86_l_662;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1645ULL: goto x86_l_66d;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1662ULL: goto x86_l_67e;
	case 1666ULL: goto x86_l_682;
	case 1669ULL: goto x86_l_685;
	case 1677ULL: goto x86_l_68d;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1699ULL: goto x86_l_6a3;
	case 1701ULL: goto x86_l_6a5;
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1724ULL: goto x86_l_6bc;
	case 1726ULL: goto x86_l_6be;
	case 1730ULL: goto x86_l_6c2;
	case 1734ULL: goto x86_l_6c6;
	case 1738ULL: goto x86_l_6ca;
	case 1742ULL: goto x86_l_6ce;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1762ULL: goto x86_l_6e2;
	case 1766ULL: goto x86_l_6e6;
	case 1769ULL: goto x86_l_6e9;
	case 1774ULL: goto x86_l_6ee;
	case 1779ULL: goto x86_l_6f3;
	case 1784ULL: goto x86_l_6f8;
	case 1787ULL: goto x86_l_6fb;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1813ULL: goto x86_l_715;
	case 1815ULL: goto x86_l_717;
	case 1820ULL: goto x86_l_71c;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1835ULL: goto x86_l_72b;
	case 1838ULL: goto x86_l_72e;
	case 1840ULL: goto x86_l_730;
	case 1844ULL: goto x86_l_734;
	case 1848ULL: goto x86_l_738;
	case 1852ULL: goto x86_l_73c;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1871ULL: goto x86_l_74f;
	case 1873ULL: goto x86_l_751;
	case 1877ULL: goto x86_l_755;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1898ULL: goto x86_l_76a;
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
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1982ULL: goto x86_l_7be;
	case 1984ULL: goto x86_l_7c0;
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
	case 2100ULL: goto x86_l_834;
	case 2102ULL: goto x86_l_836;
	case 2107ULL: goto x86_l_83b;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
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
	/* 0x2a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f:
	/* 0x2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34:
	/* 0x34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36:
	/* 0x36: test   DWORD PTR [rsp+0x30],0x200000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206160527360ULL);
x86_l_3e:
	/* 0x3e: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_43:
	/* 0x43: jne    b5 <trace_vfs_utimes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5;
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
	/* 0x56: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5a:
	/* 0x5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f:
	/* 0x5f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64:
	/* 0x64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69:
	/* 0x69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b:
	/* 0x6b: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f:
	/* 0x6f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_73:
	/* 0x73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_78:
	/* 0x78: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7d:
	/* 0x7d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_82:
	/* 0x82: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_85:
	/* 0x85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87:
	/* 0x87: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_8c:
	/* 0x8c: jne    94 <trace_vfs_utimes+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_94;
	}
x86_l_8e:
	/* 0x8e: mov    ebp,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92:
	/* 0x92: jmp    b5 <trace_vfs_utimes+0xb5> */
	goto x86_l_b5;
x86_l_94:
	/* 0x94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_99:
	/* 0x99: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_a0:
	/* 0xa0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a5:
	/* 0xa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7:
	/* 0xa7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: je     b0 <trace_vfs_utimes+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b0;
	}
x86_l_ac:
	/* 0xac: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: jmp    b5 <trace_vfs_utimes+0xb5> */
	goto x86_l_b5;
x86_l_b0:
	/* 0xb0: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_bd:
	/* 0xbd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c2:
	/* 0xc2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_c9:
	/* 0xc9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce:
	/* 0xce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0:
	/* 0xd0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: je     21a1 <trace_vfs_utimes+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8609ULL;
	}
x86_l_d9:
	/* 0xd9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_dc:
	/* 0xdc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e1:
	/* 0xe1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_e8:
	/* 0xe8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: je     21a1 <trace_vfs_utimes+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8609ULL;
	}
x86_l_f8:
	/* 0xf8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_105:
	/* 0x105: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_118:
	/* 0x118: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_123:
	/* 0x123: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_12e:
	/* 0x12e: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_139:
	/* 0x139: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_144:
	/* 0x144: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_14f:
	/* 0x14f: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_15a:
	/* 0x15a: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_165:
	/* 0x165: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_16c:
	/* 0x16c: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_174:
	/* 0x174: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17c:
	/* 0x17c: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18c:
	/* 0x18c: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_194:
	/* 0x194: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_19c:
	/* 0x19c: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a4:
	/* 0x1a4: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1bc:
	/* 0x1bc: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c4:
	/* 0x1c4: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1cc:
	/* 0x1cc: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1d9:
	/* 0x1d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db:
	/* 0x1db: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1df:
	/* 0x1df: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1e3:
	/* 0x1e3: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e7:
	/* 0x1e7: mov    DWORD PTR [r14+0x70],0x306 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337926ULL);
x86_l_1ef:
	/* 0x1ef: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1f4:
	/* 0x1f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6:
	/* 0x1f6: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f9:
	/* 0x1f9: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1fe:
	/* 0x1fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200:
	/* 0x200: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_205:
	/* 0x205: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_209:
	/* 0x209: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_20d:
	/* 0x20d: mov    DWORD PTR [rsp+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_211:
	/* 0x211: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_216:
	/* 0x216: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_21d:
	/* 0x21d: lea    rsi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_222:
	/* 0x222: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224:
	/* 0x224: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_229:
	/* 0x229: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: je     27d <trace_vfs_utimes+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d;
	}
x86_l_22e:
	/* 0x22e: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_232:
	/* 0x232: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_236:
	/* 0x236: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23b:
	/* 0x23b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_242:
	/* 0x242: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_24c:
	/* 0x24c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24f:
	/* 0x24f: mov    QWORD PTR [rsp+0x90],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_257:
	/* 0x257: mov    QWORD PTR [rsp+0xa0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_25f:
	/* 0x25f: je     4bc <trace_vfs_utimes+0x4bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4bc;
	}
x86_l_265:
	/* 0x265: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_26b:
	/* 0x26b: jne    a07 <trace_vfs_utimes+0xa07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2567ULL;
	}
x86_l_271:
	/* 0x271: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_276:
	/* 0x276: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_278:
	/* 0x278: jmp    a8e <trace_vfs_utimes+0xa8e> */
	return 2702ULL;
x86_l_27d:
	/* 0x27d: mov    eax,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_281:
	/* 0x281: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_285:
	/* 0x285: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_28d:
	/* 0x28d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_292:
	/* 0x292: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_299:
	/* 0x299: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29e:
	/* 0x29e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a0:
	/* 0x2a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a3:
	/* 0x2a3: je     21a1 <trace_vfs_utimes+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8609ULL;
	}
x86_l_2a9:
	/* 0x2a9: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad:
	/* 0x2ad: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b1:
	/* 0x2b1: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2bc:
	/* 0x2bc: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2c7:
	/* 0x2c7: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2d2:
	/* 0x2d2: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2dd:
	/* 0x2dd: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2e8:
	/* 0x2e8: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2fe:
	/* 0x2fe: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_309:
	/* 0x309: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_314:
	/* 0x314: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_31f:
	/* 0x31f: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_32a:
	/* 0x32a: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_335:
	/* 0x335: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_340:
	/* 0x340: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_34b:
	/* 0x34b: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_356:
	/* 0x356: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_361:
	/* 0x361: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_36c:
	/* 0x36c: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_377:
	/* 0x377: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_382:
	/* 0x382: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_38d:
	/* 0x38d: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_398:
	/* 0x398: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3a3:
	/* 0x3a3: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3ae:
	/* 0x3ae: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3b9:
	/* 0x3b9: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3c4:
	/* 0x3c4: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3cf:
	/* 0x3cf: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3da:
	/* 0x3da: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3e5:
	/* 0x3e5: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3f0:
	/* 0x3f0: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3fb:
	/* 0x3fb: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_403:
	/* 0x403: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_40b:
	/* 0x40b: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_413:
	/* 0x413: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_41b:
	/* 0x41b: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_423:
	/* 0x423: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_42b:
	/* 0x42b: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_43b:
	/* 0x43b: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_443:
	/* 0x443: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_44b:
	/* 0x44b: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_453:
	/* 0x453: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_473:
	/* 0x473: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47a:
	/* 0x47a: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_480:
	/* 0x480: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_487:
	/* 0x487: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_48c:
	/* 0x48c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_491:
	/* 0x491: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_497:
	/* 0x497: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_49a:
	/* 0x49a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_49f:
	/* 0x49f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a4:
	/* 0x4a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a9:
	/* 0x4a9: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ae:
	/* 0x4ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: jne    22e <trace_vfs_utimes+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e;
	}
x86_l_4b7:
	/* 0x4b7: jmp    21a1 <trace_vfs_utimes+0x21a1> */
	return 8609ULL;
x86_l_4bc:
	/* 0x4bc: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4c0:
	/* 0x4c0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c4:
	/* 0x4c4: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4cc:
	/* 0x4cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d1:
	/* 0x4d1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4d8:
	/* 0x4d8: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4dd:
	/* 0x4dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4df:
	/* 0x4df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e2:
	/* 0x4e2: je     21a1 <trace_vfs_utimes+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8609ULL;
	}
x86_l_4e8:
	/* 0x4e8: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ec:
	/* 0x4ec: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4f0:
	/* 0x4f0: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_4fb:
	/* 0x4fb: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_506:
	/* 0x506: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_511:
	/* 0x511: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_51c:
	/* 0x51c: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_527:
	/* 0x527: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_532:
	/* 0x532: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_53d:
	/* 0x53d: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_548:
	/* 0x548: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_553:
	/* 0x553: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_55b:
	/* 0x55b: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_563:
	/* 0x563: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_56b:
	/* 0x56b: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_573:
	/* 0x573: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_583:
	/* 0x583: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_58b:
	/* 0x58b: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_593:
	/* 0x593: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_59b:
	/* 0x59b: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5a3:
	/* 0x5a3: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5ab:
	/* 0x5ab: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5b3:
	/* 0x5b3: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5bb:
	/* 0x5bb: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5c3:
	/* 0x5c3: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5cb:
	/* 0x5cb: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d2:
	/* 0x5d2: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5d8:
	/* 0x5d8: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5df:
	/* 0x5df: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5e4:
	/* 0x5e4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5e9:
	/* 0x5e9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5ec:
	/* 0x5ec: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ef:
	/* 0x5ef: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5f2:
	/* 0x5f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5f7:
	/* 0x5f7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fc:
	/* 0x5fc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5ff:
	/* 0x5ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_601:
	/* 0x601: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_604:
	/* 0x604: je     21a1 <trace_vfs_utimes+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8609ULL;
	}
x86_l_60a:
	/* 0x60a: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_614:
	/* 0x614: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_618:
	/* 0x618: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61d:
	/* 0x61d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_622:
	/* 0x622: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_627:
	/* 0x627: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_62a:
	/* 0x62a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62c:
	/* 0x62c: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_631:
	/* 0x631: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_635:
	/* 0x635: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_639:
	/* 0x639: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63e:
	/* 0x63e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_643:
	/* 0x643: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_648:
	/* 0x648: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64a:
	/* 0x64a: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_64f:
	/* 0x64f: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_653:
	/* 0x653: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_658:
	/* 0x658: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_65d:
	/* 0x65d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_662:
	/* 0x662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_664:
	/* 0x664: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_669:
	/* 0x669: lea    rdx,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_66d:
	/* 0x66d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_672:
	/* 0x672: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_677:
	/* 0x677: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_67c:
	/* 0x67c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67e:
	/* 0x67e: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_682:
	/* 0x682: mov    DWORD PTR [rbp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_685:
	/* 0x685: mov    QWORD PTR [rsp+0x88],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_68d:
	/* 0x68d: add    rbx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_691:
	/* 0x691: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_696:
	/* 0x696: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_69b:
	/* 0x69b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a0:
	/* 0x6a0: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_6a3:
	/* 0x6a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a5:
	/* 0x6a5: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6aa:
	/* 0x6aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6af:
	/* 0x6af: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b4:
	/* 0x6b4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6b9:
	/* 0x6b9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6bc:
	/* 0x6bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6be:
	/* 0x6be: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6c2:
	/* 0x6c2: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6c6:
	/* 0x6c6: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_6ca:
	/* 0x6ca: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6ce:
	/* 0x6ce: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_6d1:
	/* 0x6d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d6:
	/* 0x6d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6db:
	/* 0x6db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6e0:
	/* 0x6e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e2:
	/* 0x6e2: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6e6:
	/* 0x6e6: mov    DWORD PTR [rbp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6e9:
	/* 0x6e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ee:
	/* 0x6ee: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f3:
	/* 0x6f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f8:
	/* 0x6f8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6fb:
	/* 0x6fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fd:
	/* 0x6fd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_702:
	/* 0x702: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_706:
	/* 0x706: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70b:
	/* 0x70b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_710:
	/* 0x710: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_715:
	/* 0x715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_717:
	/* 0x717: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_71c:
	/* 0x71c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_721:
	/* 0x721: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_726:
	/* 0x726: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_72b:
	/* 0x72b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_72e:
	/* 0x72e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_730:
	/* 0x730: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_734:
	/* 0x734: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_738:
	/* 0x738: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_73c:
	/* 0x73c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_740:
	/* 0x740: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_745:
	/* 0x745: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_74a:
	/* 0x74a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_74f:
	/* 0x74f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_751:
	/* 0x751: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_755:
	/* 0x755: mov    DWORD PTR [rbp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_758:
	/* 0x758: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75d:
	/* 0x75d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_762:
	/* 0x762: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_767:
	/* 0x767: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_771:
	/* 0x771: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_776:
	/* 0x776: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_77b:
	/* 0x77b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_780:
	/* 0x780: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_783:
	/* 0x783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_785:
	/* 0x785: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_789:
	/* 0x789: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_78d:
	/* 0x78d: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_791:
	/* 0x791: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_795:
	/* 0x795: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_79a:
	/* 0x79a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_79f:
	/* 0x79f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a4:
	/* 0x7a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a6:
	/* 0x7a6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ab:
	/* 0x7ab: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7af:
	/* 0x7af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b4:
	/* 0x7b4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7b9:
	/* 0x7b9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7be:
	/* 0x7be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c0:
	/* 0x7c0: mov    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7c4:
	/* 0x7c4: lea    r15,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c8:
	/* 0x7c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7cd:
	/* 0x7cd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x7dc: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7e1:
	/* 0x7e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e6:
	/* 0x7e6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x7f5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x80a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_80f:
	/* 0x80f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_814:
	/* 0x814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_816:
	/* 0x816: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_81b:
	/* 0x81b: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_81f:
	/* 0x81f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_824:
	/* 0x824: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_829:
	/* 0x829: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_82e:
	/* 0x82e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_830:
	/* 0x830: cmp    ebx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_834:
	/* 0x834: jne    88b <trace_vfs_utimes+0x88b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2187ULL;
	}
x86_l_836:
	/* 0x836: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_83b:
	/* 0x83b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_840:
	/* 0x840: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_845:
	/* 0x845: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
	return 2120ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2120ULL: goto x86_l_848;
	case 2122ULL: goto x86_l_84a;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2137ULL: goto x86_l_859;
	case 2142ULL: goto x86_l_85e;
	case 2145ULL: goto x86_l_861;
	case 2147ULL: goto x86_l_863;
	case 2151ULL: goto x86_l_867;
	case 2155ULL: goto x86_l_86b;
	case 2159ULL: goto x86_l_86f;
	case 2163ULL: goto x86_l_873;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2180ULL: goto x86_l_884;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2198ULL: goto x86_l_896;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2220ULL: goto x86_l_8ac;
	case 2223ULL: goto x86_l_8af;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2271ULL: goto x86_l_8df;
	case 2273ULL: goto x86_l_8e1;
	case 2277ULL: goto x86_l_8e5;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2309ULL: goto x86_l_905;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2320ULL: goto x86_l_910;
	case 2324ULL: goto x86_l_914;
	case 2328ULL: goto x86_l_918;
	case 2333ULL: goto x86_l_91d;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2345ULL: goto x86_l_929;
	case 2350ULL: goto x86_l_92e;
	case 2354ULL: goto x86_l_932;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2373ULL: goto x86_l_945;
	case 2376ULL: goto x86_l_948;
	case 2378ULL: goto x86_l_94a;
	case 2383ULL: goto x86_l_94f;
	case 2387ULL: goto x86_l_953;
	case 2392ULL: goto x86_l_958;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2405ULL: goto x86_l_965;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2414ULL: goto x86_l_96e;
	case 2418ULL: goto x86_l_972;
	case 2422ULL: goto x86_l_976;
	case 2430ULL: goto x86_l_97e;
	case 2438ULL: goto x86_l_986;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2450ULL: goto x86_l_992;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2468ULL: goto x86_l_9a4;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2492ULL: goto x86_l_9bc;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2510ULL: goto x86_l_9ce;
	case 2515ULL: goto x86_l_9d3;
	case 2517ULL: goto x86_l_9d5;
	case 2520ULL: goto x86_l_9d8;
	case 2524ULL: goto x86_l_9dc;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2537ULL: goto x86_l_9e9;
	case 2539ULL: goto x86_l_9eb;
	case 2547ULL: goto x86_l_9f3;
	case 2555ULL: goto x86_l_9fb;
	case 2561ULL: goto x86_l_a01;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2606ULL: goto x86_l_a2e;
	case 2611ULL: goto x86_l_a33;
	case 2616ULL: goto x86_l_a38;
	case 2618ULL: goto x86_l_a3a;
	case 2623ULL: goto x86_l_a3f;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2638ULL: goto x86_l_a4e;
	case 2640ULL: goto x86_l_a50;
	case 2645ULL: goto x86_l_a55;
	case 2650ULL: goto x86_l_a5a;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2662ULL: goto x86_l_a66;
	case 2667ULL: goto x86_l_a6b;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2676ULL: goto x86_l_a74;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2693ULL: goto x86_l_a85;
	case 2698ULL: goto x86_l_a8a;
	case 2700ULL: goto x86_l_a8c;
	case 2702ULL: goto x86_l_a8e;
	case 2706ULL: goto x86_l_a92;
	case 2710ULL: goto x86_l_a96;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2736ULL: goto x86_l_ab0;
	case 2738ULL: goto x86_l_ab2;
	case 2741ULL: goto x86_l_ab5;
	case 2747ULL: goto x86_l_abb;
	case 2750ULL: goto x86_l_abe;
	case 2753ULL: goto x86_l_ac1;
	case 2755ULL: goto x86_l_ac3;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2771ULL: goto x86_l_ad3;
	case 2777ULL: goto x86_l_ad9;
	case 2788ULL: goto x86_l_ae4;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2820ULL: goto x86_l_b04;
	case 2823ULL: goto x86_l_b07;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2835ULL: goto x86_l_b13;
	case 2838ULL: goto x86_l_b16;
	case 2840ULL: goto x86_l_b18;
	case 2843ULL: goto x86_l_b1b;
	case 2845ULL: goto x86_l_b1d;
	case 2849ULL: goto x86_l_b21;
	case 2856ULL: goto x86_l_b28;
	case 2859ULL: goto x86_l_b2b;
	case 2866ULL: goto x86_l_b32;
	case 2870ULL: goto x86_l_b36;
	case 2874ULL: goto x86_l_b3a;
	case 2881ULL: goto x86_l_b41;
	case 2888ULL: goto x86_l_b48;
	case 2892ULL: goto x86_l_b4c;
	case 2899ULL: goto x86_l_b53;
	case 2903ULL: goto x86_l_b57;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2921ULL: goto x86_l_b69;
	case 2925ULL: goto x86_l_b6d;
	case 2932ULL: goto x86_l_b74;
	case 2939ULL: goto x86_l_b7b;
	case 2946ULL: goto x86_l_b82;
	case 2950ULL: goto x86_l_b86;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2964ULL: goto x86_l_b94;
	case 2966ULL: goto x86_l_b96;
	case 2968ULL: goto x86_l_b98;
	case 2971ULL: goto x86_l_b9b;
	case 2978ULL: goto x86_l_ba2;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2996ULL: goto x86_l_bb4;
	case 2999ULL: goto x86_l_bb7;
	case 3005ULL: goto x86_l_bbd;
	case 3012ULL: goto x86_l_bc4;
	case 3015ULL: goto x86_l_bc7;
	case 3017ULL: goto x86_l_bc9;
	case 3020ULL: goto x86_l_bcc;
	case 3024ULL: goto x86_l_bd0;
	case 3027ULL: goto x86_l_bd3;
	case 3030ULL: goto x86_l_bd6;
	case 3037ULL: goto x86_l_bdd;
	case 3040ULL: goto x86_l_be0;
	case 3047ULL: goto x86_l_be7;
	case 3050ULL: goto x86_l_bea;
	case 3052ULL: goto x86_l_bec;
	case 3054ULL: goto x86_l_bee;
	case 3062ULL: goto x86_l_bf6;
	case 3069ULL: goto x86_l_bfd;
	case 3072ULL: goto x86_l_c00;
	case 3075ULL: goto x86_l_c03;
	case 3078ULL: goto x86_l_c06;
	case 3085ULL: goto x86_l_c0d;
	case 3088ULL: goto x86_l_c10;
	case 3091ULL: goto x86_l_c13;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3103ULL: goto x86_l_c1f;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3123ULL: goto x86_l_c33;
	case 3126ULL: goto x86_l_c36;
	case 3129ULL: goto x86_l_c39;
	case 3136ULL: goto x86_l_c40;
	case 3139ULL: goto x86_l_c43;
	case 3141ULL: goto x86_l_c45;
	case 3144ULL: goto x86_l_c48;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3156ULL: goto x86_l_c54;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3181ULL: goto x86_l_c6d;
	case 3184ULL: goto x86_l_c70;
	case 3189ULL: goto x86_l_c75;
	case 3195ULL: goto x86_l_c7b;
	case 3202ULL: goto x86_l_c82;
	case 3210ULL: goto x86_l_c8a;
	case 3217ULL: goto x86_l_c91;
	case 3222ULL: goto x86_l_c96;
	case 3229ULL: goto x86_l_c9d;
	case 3237ULL: goto x86_l_ca5;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3262ULL: goto x86_l_cbe;
	case 3265ULL: goto x86_l_cc1;
	case 3269ULL: goto x86_l_cc5;
	case 3274ULL: goto x86_l_cca;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3304ULL: goto x86_l_ce8;
	case 3306ULL: goto x86_l_cea;
	case 3309ULL: goto x86_l_ced;
	case 3313ULL: goto x86_l_cf1;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3329ULL: goto x86_l_d01;
	case 3334ULL: goto x86_l_d06;
	case 3339ULL: goto x86_l_d0b;
	case 3342ULL: goto x86_l_d0e;
	case 3345ULL: goto x86_l_d11;
	case 3347ULL: goto x86_l_d13;
	case 3351ULL: goto x86_l_d17;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3358ULL: goto x86_l_d1e;
	case 3366ULL: goto x86_l_d26;
	case 3369ULL: goto x86_l_d29;
	case 3373ULL: goto x86_l_d2d;
	case 3378ULL: goto x86_l_d32;
	case 3385ULL: goto x86_l_d39;
	case 3388ULL: goto x86_l_d3c;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3405ULL: goto x86_l_d4d;
	case 3408ULL: goto x86_l_d50;
	case 3410ULL: goto x86_l_d52;
	case 3413ULL: goto x86_l_d55;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3422ULL: goto x86_l_d5e;
	case 3425ULL: goto x86_l_d61;
	case 3427ULL: goto x86_l_d63;
	case 3434ULL: goto x86_l_d6a;
	case 3441ULL: goto x86_l_d71;
	case 3444ULL: goto x86_l_d74;
	case 3450ULL: goto x86_l_d7a;
	case 3455ULL: goto x86_l_d7f;
	case 3457ULL: goto x86_l_d81;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3468ULL: goto x86_l_d8c;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3482ULL: goto x86_l_d9a;
	case 3487ULL: goto x86_l_d9f;
	case 3490ULL: goto x86_l_da2;
	case 3495ULL: goto x86_l_da7;
	case 3498ULL: goto x86_l_daa;
	case 3500ULL: goto x86_l_dac;
	case 3504ULL: goto x86_l_db0;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3519ULL: goto x86_l_dbf;
	case 3522ULL: goto x86_l_dc2;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3531ULL: goto x86_l_dcb;
	case 3536ULL: goto x86_l_dd0;
	case 3544ULL: goto x86_l_dd8;
	case 3550ULL: goto x86_l_dde;
	case 3555ULL: goto x86_l_de3;
	case 3557ULL: goto x86_l_de5;
	case 3561ULL: goto x86_l_de9;
	case 3568ULL: goto x86_l_df0;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3590ULL: goto x86_l_e06;
	case 3597ULL: goto x86_l_e0d;
	case 3602ULL: goto x86_l_e12;
	case 3607ULL: goto x86_l_e17;
	case 3614ULL: goto x86_l_e1e;
	case 3619ULL: goto x86_l_e23;
	case 3621ULL: goto x86_l_e25;
	case 3625ULL: goto x86_l_e29;
	case 3630ULL: goto x86_l_e2e;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3652ULL: goto x86_l_e44;
	case 3655ULL: goto x86_l_e47;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3662ULL: goto x86_l_e4e;
	case 3665ULL: goto x86_l_e51;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3674ULL: goto x86_l_e5a;
	case 3676ULL: goto x86_l_e5c;
	case 3679ULL: goto x86_l_e5f;
	case 3684ULL: goto x86_l_e64;
	case 3687ULL: goto x86_l_e67;
	case 3690ULL: goto x86_l_e6a;
	case 3692ULL: goto x86_l_e6c;
	case 3697ULL: goto x86_l_e71;
	case 3699ULL: goto x86_l_e73;
	case 3703ULL: goto x86_l_e77;
	case 3708ULL: goto x86_l_e7c;
	case 3710ULL: goto x86_l_e7e;
	case 3713ULL: goto x86_l_e81;
	case 3715ULL: goto x86_l_e83;
	case 3720ULL: goto x86_l_e88;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3737ULL: goto x86_l_e99;
	case 3743ULL: goto x86_l_e9f;
	case 3748ULL: goto x86_l_ea4;
	case 3755ULL: goto x86_l_eab;
	case 3760ULL: goto x86_l_eb0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_848:
	/* 0x848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84a:
	/* 0x84a: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_84f:
	/* 0x84f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_854:
	/* 0x854: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_859:
	/* 0x859: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_85e:
	/* 0x85e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_861:
	/* 0x861: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_863:
	/* 0x863: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_867:
	/* 0x867: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_86b:
	/* 0x86b: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_86f:
	/* 0x86f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_873:
	/* 0x873: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_878:
	/* 0x878: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_87d:
	/* 0x87d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_882:
	/* 0x882: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_884:
	/* 0x884: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_888:
	/* 0x888: mov    DWORD PTR [rbp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88b:
	/* 0x88b: mov    DWORD PTR [rbp+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88e:
	/* 0x88e: mov    rbx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_896:
	/* 0x896: lea    r12,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_89d:
	/* 0x89d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8a2:
	/* 0x8a2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a7:
	/* 0x8a7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ac:
	/* 0x8ac: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_8af:
	/* 0x8af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b1:
	/* 0x8b1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b6:
	/* 0x8b6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8ba:
	/* 0x8ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8bf:
	/* 0x8bf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8c4:
	/* 0x8c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c9:
	/* 0x8c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cb:
	/* 0x8cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8d0:
	/* 0x8d0: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d5:
	/* 0x8d5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8da:
	/* 0x8da: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8df:
	/* 0x8df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e1:
	/* 0x8e1: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8e5:
	/* 0x8e5: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_8e8:
	/* 0x8e8: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_8ed:
	/* 0x8ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ef:
	/* 0x8ef: mov    DWORD PTR [rbp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8f2:
	/* 0x8f2: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8f6:
	/* 0x8f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8fb:
	/* 0x8fb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_900:
	/* 0x900: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_905:
	/* 0x905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_907:
	/* 0x907: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_90c:
	/* 0x90c: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_910:
	/* 0x910: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_914:
	/* 0x914: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_918:
	/* 0x918: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_91d:
	/* 0x91d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_922:
	/* 0x922: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_927:
	/* 0x927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_929:
	/* 0x929: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_92e:
	/* 0x92e: mov    QWORD PTR [rbp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_932:
	/* 0x932: add    r13,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_936:
	/* 0x936: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_93b:
	/* 0x93b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_940:
	/* 0x940: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_945:
	/* 0x945: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_948:
	/* 0x948: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94a:
	/* 0x94a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_94f:
	/* 0x94f: mov    QWORD PTR [rbp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_953:
	/* 0x953: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_958:
	/* 0x958: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95d:
	/* 0x95d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_962:
	/* 0x962: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_965:
	/* 0x965: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_967:
	/* 0x967: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_96c:
	/* 0x96c: je     972 <trace_vfs_utimes+0x972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_972;
	}
x86_l_96e:
	/* 0x96e: or     BYTE PTR [rbp+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_972:
	/* 0x972: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_976:
	/* 0x976: mov    QWORD PTR [rbp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_97e:
	/* 0x97e: mov    QWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_986:
	/* 0x986: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_98b:
	/* 0x98b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_990:
	/* 0x990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_992:
	/* 0x992: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_997:
	/* 0x997: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_99c:
	/* 0x99c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a1:
	/* 0x9a1: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_9a4:
	/* 0x9a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a6:
	/* 0x9a6: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ab:
	/* 0x9ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b0:
	/* 0x9b0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b5:
	/* 0x9b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9ba:
	/* 0x9ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bc:
	/* 0x9bc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c1:
	/* 0x9c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9c6:
	/* 0x9c6: lea    r15,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9cb:
	/* 0x9cb: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_9ce:
	/* 0x9ce: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_9d3:
	/* 0x9d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d5:
	/* 0x9d5: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9d8:
	/* 0x9d8: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_9dc:
	/* 0x9dc: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_9e1:
	/* 0x9e1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9e6:
	/* 0x9e6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9e9:
	/* 0x9e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9eb:
	/* 0x9eb: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9f3:
	/* 0x9f3: mov    r12,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_9fb:
	/* 0x9fb: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a01:
	/* 0xa01: je     271 <trace_vfs_utimes+0x271> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 625ULL;
	}
x86_l_a07:
	/* 0xa07: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a0c:
	/* 0xa0c: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_a13:
	/* 0xa13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a18:
	/* 0xa18: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0xa29: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a2e:
	/* 0xa2e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a33:
	/* 0xa33: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a38:
	/* 0xa38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3a:
	/* 0xa3a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3f:
	/* 0xa3f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a44:
	/* 0xa44: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a49:
	/* 0xa49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4e:
	/* 0xa4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a50:
	/* 0xa50: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a55:
	/* 0xa55: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a5a:
	/* 0xa5a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a5f:
	/* 0xa5f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a64:
	/* 0xa64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a66:
	/* 0xa66: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a6b:
	/* 0xa6b: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_a6e:
	/* 0xa6e: je     a8c <trace_vfs_utimes+0xa8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a8c;
	}
x86_l_a70:
	/* 0xa70: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a74:
	/* 0xa74: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a79:
	/* 0xa79: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7e:
	/* 0xa7e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a83:
	/* 0xa83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a85:
	/* 0xa85: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a8a:
	/* 0xa8a: jmp    a8e <trace_vfs_utimes+0xa8e> */
	goto x86_l_a8e;
x86_l_a8c:
	/* 0xa8c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8e:
	/* 0xa8e: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a92:
	/* 0xa92: mov    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a96:
	/* 0xa96: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9a:
	/* 0xa9a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9f:
	/* 0xa9f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_aa6:
	/* 0xaa6: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aab:
	/* 0xaab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aad:
	/* 0xaad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab0:
	/* 0xab0: je     ac8 <trace_vfs_utimes+0xac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac8;
	}
x86_l_ab2:
	/* 0xab2: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ab5:
	/* 0xab5: mov    BYTE PTR [rbp+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_abb:
	/* 0xabb: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_abe:
	/* 0xabe: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ac1:
	/* 0xac1: jne    ac8 <trace_vfs_utimes+0xac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ac8;
	}
x86_l_ac3:
	/* 0xac3: or     BYTE PTR [r14+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_ac8:
	/* 0xac8: movzx  eax,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_acd:
	/* 0xacd: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_ad3:
	/* 0xad3: jne    2172 <trace_vfs_utimes+0x2172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8562ULL;
	}
x86_l_ad9:
	/* 0xad9: mov    QWORD PTR [r14+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_ae4:
	/* 0xae4: mov    DWORD PTR [rsp+0x30],0x306 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430982ULL);
x86_l_aec:
	/* 0xaec: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_af1:
	/* 0xaf1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af6:
	/* 0xaf6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_afd:
	/* 0xafd: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b02:
	/* 0xb02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b04:
	/* 0xb04: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b07:
	/* 0xb07: je     b74 <trace_vfs_utimes+0xb74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b74;
	}
x86_l_b09:
	/* 0xb09: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b0e:
	/* 0xb0e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b13:
	/* 0xb13: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b16:
	/* 0xb16: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b18:
	/* 0xb18: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1b:
	/* 0xb1b: je     b74 <trace_vfs_utimes+0xb74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b74;
	}
x86_l_b1d:
	/* 0xb1d: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b21:
	/* 0xb21: mov    QWORD PTR [r14+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b28:
	/* 0xb28: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2b:
	/* 0xb2b: mov    QWORD PTR [r14+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b32:
	/* 0xb32: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b36:
	/* 0xb36: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b3a:
	/* 0xb3a: mov    QWORD PTR [r14+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b41:
	/* 0xb41: mov    QWORD PTR [r14+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b48:
	/* 0xb48: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b4c:
	/* 0xb4c: mov    QWORD PTR [r14+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b53:
	/* 0xb53: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b57:
	/* 0xb57: mov    QWORD PTR [r14+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b5e:
	/* 0xb5e: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b62:
	/* 0xb62: mov    QWORD PTR [r14+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b69:
	/* 0xb69: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b6d:
	/* 0xb6d: mov    QWORD PTR [r14+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b74:
	/* 0xb74: mov    rdx,QWORD PTR [r14+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b7b:
	/* 0xb7b: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b82:
	/* 0xb82: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b86:
	/* 0xb86: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b88:
	/* 0xb88: cmp    ecx,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_b8c:
	/* 0xb8c: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b94:
	/* 0xb94: jne    bad <trace_vfs_utimes+0xbad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bad;
	}
x86_l_b96:
	/* 0xb96: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b98:
	/* 0xb98: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_b9b:
	/* 0xb9b: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ba2:
	/* 0xba2: jne    1343 <trace_vfs_utimes+0x1343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4931ULL;
	}
x86_l_ba8:
	/* 0xba8: jmp    1dd3 <trace_vfs_utimes+0x1dd3> */
	return 7635ULL;
x86_l_bad:
	/* 0xbad: mov    rax,QWORD PTR [r14+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_bb4:
	/* 0xbb4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bb7:
	/* 0xbb7: je     d63 <trace_vfs_utimes+0xd63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d63;
	}
x86_l_bbd:
	/* 0xbbd: movzx  ecx,BYTE PTR [rbp+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_bc4:
	/* 0xbc4: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_bc7:
	/* 0xbc7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc9:
	/* 0xbc9: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_bcc:
	/* 0xbcc: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_bd0:
	/* 0xbd0: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_bd3:
	/* 0xbd3: neg    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_bd6:
	/* 0xbd6: xor    rbp,QWORD PTR [r14+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_bdd:
	/* 0xbdd: or     rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_be0:
	/* 0xbe0: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_be7:
	/* 0xbe7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bea:
	/* 0xbea: je     c13 <trace_vfs_utimes+0xc13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c13;
	}
x86_l_bec:
	/* 0xbec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bee:
	/* 0xbee: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bf6:
	/* 0xbf6: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_bfd:
	/* 0xbfd: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_c00:
	/* 0xc00: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c03:
	/* 0xc03: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c06:
	/* 0xc06: xor    rcx,QWORD PTR [r14+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_c0d:
	/* 0xc0d: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c10:
	/* 0xc10: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c13:
	/* 0xc13: mov    rax,QWORD PTR [r14+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_c1a:
	/* 0xc1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c1d:
	/* 0xc1d: je     c39 <trace_vfs_utimes+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c39;
	}
x86_l_c1f:
	/* 0xc1f: mov    ecx,DWORD PTR [r14+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c23:
	/* 0xc23: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c26:
	/* 0xc26: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_c29:
	/* 0xc29: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c2c:
	/* 0xc2c: xor    rcx,QWORD PTR [r14+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_c33:
	/* 0xc33: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c36:
	/* 0xc36: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c39:
	/* 0xc39: mov    rax,QWORD PTR [r14+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_c40:
	/* 0xc40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: je     c61 <trace_vfs_utimes+0xc61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c61;
	}
x86_l_c45:
	/* 0xc45: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c48:
	/* 0xc48: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4d:
	/* 0xc4d: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c51:
	/* 0xc51: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c54:
	/* 0xc54: xor    rcx,QWORD PTR [r14+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_c5b:
	/* 0xc5b: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c5e:
	/* 0xc5e: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c61:
	/* 0xc61: movzx  r13d,WORD PTR [r14+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c66:
	/* 0xc66: mov    r12,QWORD PTR [r14+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_c6d:
	/* 0xc6d: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_c70:
	/* 0xc70: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c75:
	/* 0xc75: je     dd0 <trace_vfs_utimes+0xdd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd0;
	}
x86_l_c7b:
	/* 0xc7b: mov    rax,QWORD PTR [r14+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_c82:
	/* 0xc82: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c8a:
	/* 0xc8a: mov    rax,QWORD PTR [r14+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_c91:
	/* 0xc91: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c96:
	/* 0xc96: mov    rax,QWORD PTR [r14+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_c9d:
	/* 0xc9d: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ca5:
	/* 0xca5: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cab:
	/* 0xcab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cb0:
	/* 0xcb0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_cb7:
	/* 0xcb7: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cbc:
	/* 0xcbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbe:
	/* 0xcbe: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_cc1:
	/* 0xcc1: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cc5:
	/* 0xcc5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cca:
	/* 0xcca: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_cd1:
	/* 0xcd1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_cd4:
	/* 0xcd4: je     cf6 <trace_vfs_utimes+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf6;
	}
x86_l_cd6:
	/* 0xcd6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdb:
	/* 0xcdb: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ce0:
	/* 0xce0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_ce3:
	/* 0xce3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce5:
	/* 0xce5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce8:
	/* 0xce8: je     cf6 <trace_vfs_utimes+0xcf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cf6;
	}
x86_l_cea:
	/* 0xcea: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ced:
	/* 0xced: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf1:
	/* 0xcf1: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_cf4:
	/* 0xcf4: jmp    cf9 <trace_vfs_utimes+0xcf9> */
	goto x86_l_cf9;
x86_l_cf6:
	/* 0xcf6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf9:
	/* 0xcf9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d01:
	/* 0xd01: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d06:
	/* 0xd06: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d0b:
	/* 0xd0b: dec    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_d0e:
	/* 0xd0e: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d11:
	/* 0xd11: jb     d29 <trace_vfs_utimes+0xd29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d29;
	}
x86_l_d13:
	/* 0xd13: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d17:
	/* 0xd17: je     d1e <trace_vfs_utimes+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_d19:
	/* 0xd19: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_d1c:
	/* 0xd1c: jbe    d29 <trace_vfs_utimes+0xd29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d29;
	}
x86_l_d1e:
	/* 0xd1e: and    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_d26:
	/* 0xd26: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d29:
	/* 0xd29: mov    eax,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d2d:
	/* 0xd2d: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d32:
	/* 0xd32: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d39:
	/* 0xd39: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_d3c:
	/* 0xd3c: je     d7f <trace_vfs_utimes+0xd7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d7f;
	}
x86_l_d3e:
	/* 0xd3e: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d43:
	/* 0xd43: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d48:
	/* 0xd48: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d4d:
	/* 0xd4d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_d50:
	/* 0xd50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d52:
	/* 0xd52: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d55:
	/* 0xd55: je     d90 <trace_vfs_utimes+0xd90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d90;
	}
x86_l_d57:
	/* 0xd57: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5a:
	/* 0xd5a: mov    rbx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5e:
	/* 0xd5e: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d61:
	/* 0xd61: jmp    d92 <trace_vfs_utimes+0xd92> */
	goto x86_l_d92;
x86_l_d63:
	/* 0xd63: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d6a:
	/* 0xd6a: mov    rax,QWORD PTR [r14+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d71:
	/* 0xd71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d74:
	/* 0xd74: jne    bec <trace_vfs_utimes+0xbec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bec;
	}
x86_l_d7a:
	/* 0xd7a: jmp    c13 <trace_vfs_utimes+0xc13> */
	goto x86_l_c13;
x86_l_d7f:
	/* 0xd7f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d81:
	/* 0xd81: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d84:
	/* 0xd84: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d89:
	/* 0xd89: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_d8c:
	/* 0xd8c: jae    dac <trace_vfs_utimes+0xdac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_dac;
	}
x86_l_d8e:
	/* 0xd8e: jmp    dc2 <trace_vfs_utimes+0xdc2> */
	goto x86_l_dc2;
x86_l_d90:
	/* 0xd90: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d92:
	/* 0xd92: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d9a:
	/* 0xd9a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9f:
	/* 0xd9f: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_da2:
	/* 0xda2: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_da7:
	/* 0xda7: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_daa:
	/* 0xdaa: jb     dc2 <trace_vfs_utimes+0xdc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_dc2;
	}
x86_l_dac:
	/* 0xdac: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_db0:
	/* 0xdb0: je     db7 <trace_vfs_utimes+0xdb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_db7;
	}
x86_l_db2:
	/* 0xdb2: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: jbe    dc2 <trace_vfs_utimes+0xdc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_dc2;
	}
x86_l_db7:
	/* 0xdb7: and    rbx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_dbf:
	/* 0xdbf: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dc2:
	/* 0xdc2: or     r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_OR);
x86_l_dc5:
	/* 0xdc5: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_dc8:
	/* 0xdc8: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_dcb:
	/* 0xdcb: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_dd0:
	/* 0xdd0: cmp    QWORD PTR [r14+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_dd8:
	/* 0xdd8: je     e91 <trace_vfs_utimes+0xe91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e91;
	}
x86_l_dde:
	/* 0xdde: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_de3:
	/* 0xde3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de5:
	/* 0xde5: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de9:
	/* 0xde9: mov    rbx,QWORD PTR [r14+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_df0:
	/* 0xdf0: mov    rax,QWORD PTR [r14+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_df7:
	/* 0xdf7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dfc:
	/* 0xdfc: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_dff:
	/* 0xdff: mov    r13,QWORD PTR [r14+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_e06:
	/* 0xe06: mov    r12,QWORD PTR [r14+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_e0d:
	/* 0xe0d: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e12:
	/* 0xe12: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e17:
	/* 0xe17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_e1e:
	/* 0xe1e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e23:
	/* 0xe23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e25:
	/* 0xe25: mov    ecx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e29:
	/* 0xe29: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e2e:
	/* 0xe2e: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e35:
	/* 0xe35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e38:
	/* 0xe38: je     e5a <trace_vfs_utimes+0xe5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5a;
	}
x86_l_e3a:
	/* 0xe3a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e3f:
	/* 0xe3f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e44:
	/* 0xe44: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e47:
	/* 0xe47: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e49:
	/* 0xe49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: je     e5a <trace_vfs_utimes+0xe5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5a;
	}
x86_l_e4e:
	/* 0xe4e: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e51:
	/* 0xe51: mov    r15,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e55:
	/* 0xe55: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e58:
	/* 0xe58: jmp    e5c <trace_vfs_utimes+0xe5c> */
	goto x86_l_e5c;
x86_l_e5a:
	/* 0xe5a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5c:
	/* 0xe5c: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e5f:
	/* 0xe5f: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e64:
	/* 0xe64: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e67:
	/* 0xe67: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e6a:
	/* 0xe6a: jae    e73 <trace_vfs_utimes+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e73;
	}
x86_l_e6c:
	/* 0xe6c: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e71:
	/* 0xe71: jmp    e8b <trace_vfs_utimes+0xe8b> */
	goto x86_l_e8b;
x86_l_e73:
	/* 0xe73: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e77:
	/* 0xe77: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e7c:
	/* 0xe7c: je     e83 <trace_vfs_utimes+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e83;
	}
x86_l_e7e:
	/* 0xe7e: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_e81:
	/* 0xe81: jbe    e8b <trace_vfs_utimes+0xe8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e8b;
	}
x86_l_e83:
	/* 0xe83: and    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32ULL);
x86_l_e88:
	/* 0xe88: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_e8b:
	/* 0xe8b: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e8e:
	/* 0xe8e: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e91:
	/* 0xe91: cmp    QWORD PTR [r14+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_e99:
	/* 0xe99: je     f57 <trace_vfs_utimes+0xf57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3927ULL;
	}
x86_l_e9f:
	/* 0xe9f: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_ea4:
	/* 0xea4: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_eab:
	/* 0xeab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eb0:
	/* 0xeb0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
	return 3765ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3772ULL: goto x86_l_ebc;
	case 3777ULL: goto x86_l_ec1;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3791ULL: goto x86_l_ecf;
	case 3796ULL: goto x86_l_ed4;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3820ULL: goto x86_l_eec;
	case 3824ULL: goto x86_l_ef0;
	case 3828ULL: goto x86_l_ef4;
	case 3835ULL: goto x86_l_efb;
	case 3842ULL: goto x86_l_f02;
	case 3845ULL: goto x86_l_f05;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3863ULL: goto x86_l_f17;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	case 3877ULL: goto x86_l_f25;
	case 3880ULL: goto x86_l_f28;
	case 3882ULL: goto x86_l_f2a;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3894ULL: goto x86_l_f36;
	case 3896ULL: goto x86_l_f38;
	case 3899ULL: goto x86_l_f3b;
	case 3901ULL: goto x86_l_f3d;
	case 3904ULL: goto x86_l_f40;
	case 3908ULL: goto x86_l_f44;
	case 3911ULL: goto x86_l_f47;
	case 3913ULL: goto x86_l_f49;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3927ULL: goto x86_l_f57;
	case 3935ULL: goto x86_l_f5f;
	case 3941ULL: goto x86_l_f65;
	case 3948ULL: goto x86_l_f6c;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3962ULL: goto x86_l_f7a;
	case 3967ULL: goto x86_l_f7f;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3989ULL: goto x86_l_f95;
	case 3992ULL: goto x86_l_f98;
	case 3994ULL: goto x86_l_f9a;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4006ULL: goto x86_l_fa6;
	case 4010ULL: goto x86_l_faa;
	case 4015ULL: goto x86_l_faf;
	case 4020ULL: goto x86_l_fb4;
	case 4025ULL: goto x86_l_fb9;
	case 4027ULL: goto x86_l_fbb;
	case 4032ULL: goto x86_l_fc0;
	case 4036ULL: goto x86_l_fc4;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4051ULL: goto x86_l_fd3;
	case 4053ULL: goto x86_l_fd5;
	case 4057ULL: goto x86_l_fd9;
	case 4061ULL: goto x86_l_fdd;
	case 4068ULL: goto x86_l_fe4;
	case 4075ULL: goto x86_l_feb;
	case 4078ULL: goto x86_l_fee;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4096ULL: goto x86_l_1000;
	case 4101ULL: goto x86_l_1005;
	case 4103ULL: goto x86_l_1007;
	case 4110ULL: goto x86_l_100e;
	case 4113ULL: goto x86_l_1011;
	case 4115ULL: goto x86_l_1013;
	case 4119ULL: goto x86_l_1017;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4129ULL: goto x86_l_1021;
	case 4132ULL: goto x86_l_1024;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4141ULL: goto x86_l_102d;
	case 4144ULL: goto x86_l_1030;
	case 4146ULL: goto x86_l_1032;
	case 4148ULL: goto x86_l_1034;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4157ULL: goto x86_l_103d;
	case 4160ULL: goto x86_l_1040;
	case 4168ULL: goto x86_l_1048;
	case 4174ULL: goto x86_l_104e;
	case 4179ULL: goto x86_l_1053;
	case 4186ULL: goto x86_l_105a;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4213ULL: goto x86_l_1075;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4225ULL: goto x86_l_1081;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4243ULL: goto x86_l_1093;
	case 4248ULL: goto x86_l_1098;
	case 4250ULL: goto x86_l_109a;
	case 4254ULL: goto x86_l_109e;
	case 4259ULL: goto x86_l_10a3;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4279ULL: goto x86_l_10b7;
	case 4286ULL: goto x86_l_10be;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4307ULL: goto x86_l_10d3;
	case 4312ULL: goto x86_l_10d8;
	case 4314ULL: goto x86_l_10da;
	case 4321ULL: goto x86_l_10e1;
	case 4324ULL: goto x86_l_10e4;
	case 4326ULL: goto x86_l_10e6;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4339ULL: goto x86_l_10f3;
	case 4342ULL: goto x86_l_10f6;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4351ULL: goto x86_l_10ff;
	case 4354ULL: goto x86_l_1102;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4389ULL: goto x86_l_1125;
	case 4394ULL: goto x86_l_112a;
	case 4397ULL: goto x86_l_112d;
	case 4402ULL: goto x86_l_1132;
	case 4404ULL: goto x86_l_1134;
	case 4411ULL: goto x86_l_113b;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4446ULL: goto x86_l_115e;
	case 4453ULL: goto x86_l_1165;
	case 4456ULL: goto x86_l_1168;
	case 4458ULL: goto x86_l_116a;
	case 4463ULL: goto x86_l_116f;
	case 4466ULL: goto x86_l_1172;
	case 4469ULL: goto x86_l_1175;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4476ULL: goto x86_l_117c;
	case 4479ULL: goto x86_l_117f;
	case 4483ULL: goto x86_l_1183;
	case 4486ULL: goto x86_l_1186;
	case 4488ULL: goto x86_l_1188;
	case 4490ULL: goto x86_l_118a;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4499ULL: goto x86_l_1193;
	case 4502ULL: goto x86_l_1196;
	case 4507ULL: goto x86_l_119b;
	case 4514ULL: goto x86_l_11a2;
	case 4517ULL: goto x86_l_11a5;
	case 4519ULL: goto x86_l_11a7;
	case 4523ULL: goto x86_l_11ab;
	case 4527ULL: goto x86_l_11af;
	case 4534ULL: goto x86_l_11b6;
	case 4537ULL: goto x86_l_11b9;
	case 4543ULL: goto x86_l_11bf;
	case 4548ULL: goto x86_l_11c4;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4562ULL: goto x86_l_11d2;
	case 4569ULL: goto x86_l_11d9;
	case 4572ULL: goto x86_l_11dc;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4587ULL: goto x86_l_11eb;
	case 4589ULL: goto x86_l_11ed;
	case 4592ULL: goto x86_l_11f0;
	case 4594ULL: goto x86_l_11f2;
	case 4597ULL: goto x86_l_11f5;
	case 4601ULL: goto x86_l_11f9;
	case 4604ULL: goto x86_l_11fc;
	case 4606ULL: goto x86_l_11fe;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4620ULL: goto x86_l_120c;
	case 4627ULL: goto x86_l_1213;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4639ULL: goto x86_l_121f;
	case 4642ULL: goto x86_l_1222;
	case 4648ULL: goto x86_l_1228;
	case 4653ULL: goto x86_l_122d;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4667ULL: goto x86_l_123b;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4698ULL: goto x86_l_125a;
	case 4701ULL: goto x86_l_125d;
	case 4705ULL: goto x86_l_1261;
	case 4708ULL: goto x86_l_1264;
	case 4710ULL: goto x86_l_1266;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4724ULL: goto x86_l_1274;
	case 4731ULL: goto x86_l_127b;
	case 4734ULL: goto x86_l_127e;
	case 4740ULL: goto x86_l_1284;
	case 4747ULL: goto x86_l_128b;
	case 4750ULL: goto x86_l_128e;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4775ULL: goto x86_l_12a7;
	case 4782ULL: goto x86_l_12ae;
	case 4785ULL: goto x86_l_12b1;
	case 4787ULL: goto x86_l_12b3;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4799ULL: goto x86_l_12bf;
	case 4804ULL: goto x86_l_12c4;
	case 4807ULL: goto x86_l_12c7;
	case 4809ULL: goto x86_l_12c9;
	case 4812ULL: goto x86_l_12cc;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4831ULL: goto x86_l_12df;
	case 4833ULL: goto x86_l_12e1;
	case 4836ULL: goto x86_l_12e4;
	case 4838ULL: goto x86_l_12e6;
	case 4841ULL: goto x86_l_12e9;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4850ULL: goto x86_l_12f2;
	case 4852ULL: goto x86_l_12f4;
	case 4855ULL: goto x86_l_12f7;
	case 4858ULL: goto x86_l_12fa;
	case 4861ULL: goto x86_l_12fd;
	case 4864ULL: goto x86_l_1300;
	case 4871ULL: goto x86_l_1307;
	case 4874ULL: goto x86_l_130a;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4889ULL: goto x86_l_1319;
	case 4894ULL: goto x86_l_131e;
	case 4898ULL: goto x86_l_1322;
	case 4901ULL: goto x86_l_1325;
	case 4908ULL: goto x86_l_132c;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4925ULL: goto x86_l_133d;
	case 4931ULL: goto x86_l_1343;
	case 4935ULL: goto x86_l_1347;
	case 4939ULL: goto x86_l_134b;
	case 4947ULL: goto x86_l_1353;
	case 4952ULL: goto x86_l_1358;
	case 4959ULL: goto x86_l_135f;
	case 4964ULL: goto x86_l_1364;
	case 4966ULL: goto x86_l_1366;
	case 4969ULL: goto x86_l_1369;
	case 4975ULL: goto x86_l_136f;
	case 4978ULL: goto x86_l_1372;
	case 4981ULL: goto x86_l_1375;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5001ULL: goto x86_l_1389;
	case 5006ULL: goto x86_l_138e;
	case 5008ULL: goto x86_l_1390;
	case 5013ULL: goto x86_l_1395;
	case 5018ULL: goto x86_l_139a;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5061ULL: goto x86_l_13c5;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5081ULL: goto x86_l_13d9;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5112ULL: goto x86_l_13f8;
	case 5117ULL: goto x86_l_13fd;
	case 5122ULL: goto x86_l_1402;
	case 5127ULL: goto x86_l_1407;
	case 5130ULL: goto x86_l_140a;
	case 5133ULL: goto x86_l_140d;
	case 5135ULL: goto x86_l_140f;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5149ULL: goto x86_l_141d;
	case 5154ULL: goto x86_l_1422;
	case 5159ULL: goto x86_l_1427;
	case 5164ULL: goto x86_l_142c;
	case 5166ULL: goto x86_l_142e;
	case 5171ULL: goto x86_l_1433;
	case 5174ULL: goto x86_l_1436;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5188ULL: goto x86_l_1444;
	case 5194ULL: goto x86_l_144a;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5213ULL: goto x86_l_145d;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5226ULL: goto x86_l_146a;
	case 5232ULL: goto x86_l_1470;
	case 5234ULL: goto x86_l_1472;
	case 5236ULL: goto x86_l_1474;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5257ULL: goto x86_l_1489;
	case 5263ULL: goto x86_l_148f;
	case 5268ULL: goto x86_l_1494;
	case 5275ULL: goto x86_l_149b;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5294ULL: goto x86_l_14ae;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5327ULL: goto x86_l_14cf;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	default: return 0xffffffffffffffffULL;
	}
x86_l_eb5:
	/* 0xeb5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_eba:
	/* 0xeba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebc:
	/* 0xebc: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ec1:
	/* 0xec1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ec5:
	/* 0xec5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eca:
	/* 0xeca: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ecf:
	/* 0xecf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed4:
	/* 0xed4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed6:
	/* 0xed6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_edb:
	/* 0xedb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ee0:
	/* 0xee0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee5:
	/* 0xee5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eea:
	/* 0xeea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eec:
	/* 0xeec: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef0:
	/* 0xef0: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ef4:
	/* 0xef4: mov    rbx,QWORD PTR [r14+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_efb:
	/* 0xefb: mov    r15,QWORD PTR [r14+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_f02:
	/* 0xf02: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f05:
	/* 0xf05: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f0b:
	/* 0xf0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f10:
	/* 0xf10: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_f17:
	/* 0xf17: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f1c:
	/* 0xf1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1e:
	/* 0xf1e: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f25:
	/* 0xf25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f28:
	/* 0xf28: je     f49 <trace_vfs_utimes+0xf49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f49;
	}
x86_l_f2a:
	/* 0xf2a: lea    rsi,[r14+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f2e:
	/* 0xf2e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f33:
	/* 0xf33: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f36:
	/* 0xf36: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f38:
	/* 0xf38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f3b:
	/* 0xf3b: je     f49 <trace_vfs_utimes+0xf49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f49;
	}
x86_l_f3d:
	/* 0xf3d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f40:
	/* 0xf40: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f44:
	/* 0xf44: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f47:
	/* 0xf47: jmp    f4b <trace_vfs_utimes+0xf4b> */
	goto x86_l_f4b;
x86_l_f49:
	/* 0xf49: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f4b:
	/* 0xf4b: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f4e:
	/* 0xf4e: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_f51:
	/* 0xf51: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f54:
	/* 0xf54: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_f57:
	/* 0xf57: cmp    QWORD PTR [r14+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_f5f:
	/* 0xf5f: je     1040 <trace_vfs_utimes+0x1040> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1040;
	}
x86_l_f65:
	/* 0xf65: mov    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_f6c:
	/* 0xf6c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f70:
	/* 0xf70: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f75:
	/* 0xf75: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f7a:
	/* 0xf7a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f7f:
	/* 0xf7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f81:
	/* 0xf81: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f86:
	/* 0xf86: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f8b:
	/* 0xf8b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f90:
	/* 0xf90: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f95:
	/* 0xf95: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f98:
	/* 0xf98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9a:
	/* 0xf9a: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f9e:
	/* 0xf9e: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_fa2:
	/* 0xfa2: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_fa6:
	/* 0xfa6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_faa:
	/* 0xfaa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_faf:
	/* 0xfaf: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fb4:
	/* 0xfb4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb9:
	/* 0xfb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fbb:
	/* 0xfbb: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc0:
	/* 0xfc0: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_fc4:
	/* 0xfc4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fc9:
	/* 0xfc9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fce:
	/* 0xfce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fd3:
	/* 0xfd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd5:
	/* 0xfd5: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd9:
	/* 0xfd9: mov    DWORD PTR [r14+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fdd:
	/* 0xfdd: mov    rbx,QWORD PTR [r14+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_fe4:
	/* 0xfe4: mov    r15,QWORD PTR [r14+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_feb:
	/* 0xfeb: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fee:
	/* 0xfee: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ff4:
	/* 0xff4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff9:
	/* 0xff9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_1000:
	/* 0x1000: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1005:
	/* 0x1005: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1007:
	/* 0x1007: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_100e:
	/* 0x100e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1011:
	/* 0x1011: je     1032 <trace_vfs_utimes+0x1032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1032;
	}
x86_l_1013:
	/* 0x1013: lea    rsi,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1017:
	/* 0x1017: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_101c:
	/* 0x101c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_101f:
	/* 0x101f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1021:
	/* 0x1021: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1024:
	/* 0x1024: je     1032 <trace_vfs_utimes+0x1032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1032;
	}
x86_l_1026:
	/* 0x1026: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1029:
	/* 0x1029: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102d:
	/* 0x102d: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1030:
	/* 0x1030: jmp    1034 <trace_vfs_utimes+0x1034> */
	goto x86_l_1034;
x86_l_1032:
	/* 0x1032: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1034:
	/* 0x1034: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1037:
	/* 0x1037: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_103a:
	/* 0x103a: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_103d:
	/* 0x103d: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1040:
	/* 0x1040: cmp    QWORD PTR [r14+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1048:
	/* 0x1048: je     1117 <trace_vfs_utimes+0x1117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1117;
	}
x86_l_104e:
	/* 0x104e: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_1053:
	/* 0x1053: add    rdx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_105a:
	/* 0x105a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_105f:
	/* 0x105f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1064:
	/* 0x1064: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1069:
	/* 0x1069: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_106b:
	/* 0x106b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1070:
	/* 0x1070: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1075:
	/* 0x1075: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_107a:
	/* 0x107a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_107f:
	/* 0x107f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1081:
	/* 0x1081: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1086:
	/* 0x1086: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_108b:
	/* 0x108b: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1090:
	/* 0x1090: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1093:
	/* 0x1093: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1098:
	/* 0x1098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109a:
	/* 0x109a: lea    r15,[r14+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_109e:
	/* 0x109e: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_10a3:
	/* 0x10a3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10a6:
	/* 0x10a6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10ab:
	/* 0x10ab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10ae:
	/* 0x10ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b0:
	/* 0x10b0: mov    rbx,QWORD PTR [r14+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_10b7:
	/* 0x10b7: mov    r12,QWORD PTR [r14+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_10be:
	/* 0x10be: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10c1:
	/* 0x10c1: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10c7:
	/* 0x10c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10cc:
	/* 0x10cc: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_10d3:
	/* 0x10d3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d8:
	/* 0x10d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10da:
	/* 0x10da: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10e1:
	/* 0x10e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e4:
	/* 0x10e4: je     1104 <trace_vfs_utimes+0x1104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1104;
	}
x86_l_10e6:
	/* 0x10e6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10eb:
	/* 0x10eb: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10ee:
	/* 0x10ee: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_10f1:
	/* 0x10f1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10f3:
	/* 0x10f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f6:
	/* 0x10f6: je     1104 <trace_vfs_utimes+0x1104> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1104;
	}
x86_l_10f8:
	/* 0x10f8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fb:
	/* 0x10fb: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ff:
	/* 0x10ff: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1102:
	/* 0x1102: jmp    1106 <trace_vfs_utimes+0x1106> */
	goto x86_l_1106;
x86_l_1104:
	/* 0x1104: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1106:
	/* 0x1106: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1109:
	/* 0x1109: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_110c:
	/* 0x110c: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_110f:
	/* 0x110f: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1112:
	/* 0x1112: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1117:
	/* 0x1117: cmp    QWORD PTR [r14+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_111f:
	/* 0x111f: je     119b <trace_vfs_utimes+0x119b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_119b;
	}
x86_l_1121:
	/* 0x1121: lea    r15,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1125:
	/* 0x1125: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_112a:
	/* 0x112a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_112d:
	/* 0x112d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1132:
	/* 0x1132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1134:
	/* 0x1134: mov    rbx,QWORD PTR [r14+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_113b:
	/* 0x113b: mov    r12,QWORD PTR [r14+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_1142:
	/* 0x1142: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1145:
	/* 0x1145: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_114b:
	/* 0x114b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1150:
	/* 0x1150: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1157:
	/* 0x1157: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_115c:
	/* 0x115c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115e:
	/* 0x115e: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1165:
	/* 0x1165: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1168:
	/* 0x1168: je     1188 <trace_vfs_utimes+0x1188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1188;
	}
x86_l_116a:
	/* 0x116a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_116f:
	/* 0x116f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1172:
	/* 0x1172: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1175:
	/* 0x1175: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1177:
	/* 0x1177: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_117a:
	/* 0x117a: je     1188 <trace_vfs_utimes+0x1188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1188;
	}
x86_l_117c:
	/* 0x117c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117f:
	/* 0x117f: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1183:
	/* 0x1183: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1186:
	/* 0x1186: jmp    118a <trace_vfs_utimes+0x118a> */
	goto x86_l_118a;
x86_l_1188:
	/* 0x1188: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118a:
	/* 0x118a: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_118d:
	/* 0x118d: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1190:
	/* 0x1190: or     r13,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1193:
	/* 0x1193: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1196:
	/* 0x1196: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_119b:
	/* 0x119b: mov    rbx,QWORD PTR [r14+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_11a2:
	/* 0x11a2: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_11a5:
	/* 0x11a5: je     120c <trace_vfs_utimes+0x120c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120c;
	}
x86_l_11a7:
	/* 0x11a7: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11ab:
	/* 0x11ab: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11af:
	/* 0x11af: mov    r15,QWORD PTR [r14+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_11b6:
	/* 0x11b6: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11b9:
	/* 0x11b9: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11bf:
	/* 0x11bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11c4:
	/* 0x11c4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_11cb:
	/* 0x11cb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d0:
	/* 0x11d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11d2:
	/* 0x11d2: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11d9:
	/* 0x11d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11dc:
	/* 0x11dc: je     11fe <trace_vfs_utimes+0x11fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11fe;
	}
x86_l_11de:
	/* 0x11de: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e3:
	/* 0x11e3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11e8:
	/* 0x11e8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11eb:
	/* 0x11eb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11ed:
	/* 0x11ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f0:
	/* 0x11f0: je     11fe <trace_vfs_utimes+0x11fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11fe;
	}
x86_l_11f2:
	/* 0x11f2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f5:
	/* 0x11f5: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f9:
	/* 0x11f9: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11fc:
	/* 0x11fc: jmp    1200 <trace_vfs_utimes+0x1200> */
	goto x86_l_1200;
x86_l_11fe:
	/* 0x11fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1200:
	/* 0x1200: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1203:
	/* 0x1203: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1206:
	/* 0x1206: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1209:
	/* 0x1209: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_120c:
	/* 0x120c: mov    rbx,QWORD PTR [r14+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_1213:
	/* 0x1213: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1216:
	/* 0x1216: je     1274 <trace_vfs_utimes+0x1274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1274;
	}
x86_l_1218:
	/* 0x1218: mov    r15,QWORD PTR [r14+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_121f:
	/* 0x121f: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1222:
	/* 0x1222: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1228:
	/* 0x1228: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122d:
	/* 0x122d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_1234:
	/* 0x1234: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1239:
	/* 0x1239: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123b:
	/* 0x123b: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1242:
	/* 0x1242: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1245:
	/* 0x1245: je     1266 <trace_vfs_utimes+0x1266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1266;
	}
x86_l_1247:
	/* 0x1247: lea    rsi,[r14+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_124b:
	/* 0x124b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1250:
	/* 0x1250: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1253:
	/* 0x1253: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1255:
	/* 0x1255: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1258:
	/* 0x1258: je     1266 <trace_vfs_utimes+0x1266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1266;
	}
x86_l_125a:
	/* 0x125a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125d:
	/* 0x125d: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1261:
	/* 0x1261: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1264:
	/* 0x1264: jmp    1268 <trace_vfs_utimes+0x1268> */
	goto x86_l_1268;
x86_l_1266:
	/* 0x1266: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1268:
	/* 0x1268: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_126b:
	/* 0x126b: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_126e:
	/* 0x126e: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1271:
	/* 0x1271: and    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1274:
	/* 0x1274: mov    rbx,QWORD PTR [r14+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_127b:
	/* 0x127b: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_127e:
	/* 0x127e: je     1300 <trace_vfs_utimes+0x1300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1300;
	}
x86_l_1284:
	/* 0x1284: mov    r12,QWORD PTR [r14+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_128b:
	/* 0x128b: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_128e:
	/* 0x128e: mov    WORD PTR [rsp+0x30],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1294:
	/* 0x1294: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1299:
	/* 0x1299: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_12a0:
	/* 0x12a0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a5:
	/* 0x12a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a7:
	/* 0x12a7: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12ae:
	/* 0x12ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12b1:
	/* 0x12b1: je     12f2 <trace_vfs_utimes+0x12f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f2;
	}
x86_l_12b3:
	/* 0x12b3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12b6:
	/* 0x12b6: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12bb:
	/* 0x12bb: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12bf:
	/* 0x12bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c4:
	/* 0x12c4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_12c7:
	/* 0x12c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c9:
	/* 0x12c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12cc:
	/* 0x12cc: jne    12e6 <trace_vfs_utimes+0x12e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12e6;
	}
x86_l_12ce:
	/* 0x12ce: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12d3:
	/* 0x12d3: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d7:
	/* 0x12d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12dc:
	/* 0x12dc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_12df:
	/* 0x12df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e1:
	/* 0x12e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e4:
	/* 0x12e4: je     12f2 <trace_vfs_utimes+0x12f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f2;
	}
x86_l_12e6:
	/* 0x12e6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e9:
	/* 0x12e9: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ed:
	/* 0x12ed: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_12f0:
	/* 0x12f0: jmp    12f4 <trace_vfs_utimes+0x12f4> */
	goto x86_l_12f4;
x86_l_12f2:
	/* 0x12f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f4:
	/* 0x12f4: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12f7:
	/* 0x12f7: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_12fa:
	/* 0x12fa: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12fd:
	/* 0x12fd: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1300:
	/* 0x1300: mov    rdx,QWORD PTR [r14+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1307:
	/* 0x1307: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1312:
	/* 0x1312: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1317:
	/* 0x1317: je     1325 <trace_vfs_utimes+0x1325> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1325;
	}
x86_l_1319:
	/* 0x1319: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_131e:
	/* 0x131e: and    rdx,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1322:
	/* 0x1322: or     rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1325:
	/* 0x1325: and    rbp,QWORD PTR [r14+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_132c:
	/* 0x132c: mov    rdx,QWORD PTR [r14+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1333:
	/* 0x1333: and    rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_1336:
	/* 0x1336: mov    QWORD PTR [r14+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_133d:
	/* 0x133d: je     1dd3 <trace_vfs_utimes+0x1dd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7635ULL;
	}
x86_l_1343:
	/* 0x1343: mov    rbp,QWORD PTR [r15+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1347:
	/* 0x1347: mov    rbx,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_134b:
	/* 0x134b: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1353:
	/* 0x1353: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1358:
	/* 0x1358: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_135f:
	/* 0x135f: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1364:
	/* 0x1364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1366:
	/* 0x1366: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1369:
	/* 0x1369: je     14b3 <trace_vfs_utimes+0x14b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b3;
	}
x86_l_136f:
	/* 0x136f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1372:
	/* 0x1372: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1375:
	/* 0x1375: je     164c <trace_vfs_utimes+0x164c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5708ULL;
	}
x86_l_137b:
	/* 0x137b: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_137f:
	/* 0x137f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1384:
	/* 0x1384: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1389:
	/* 0x1389: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_138e:
	/* 0x138e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1390:
	/* 0x1390: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1395:
	/* 0x1395: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139a:
	/* 0x139a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_139f:
	/* 0x139f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a4:
	/* 0x13a4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13a9:
	/* 0x13a9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13ae:
	/* 0x13ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13b0:
	/* 0x13b0: test   BYTE PTR [rsp+0x30],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430240ULL);
x86_l_13b5:
	/* 0x13b5: jne    14bb <trace_vfs_utimes+0x14bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14bb;
	}
x86_l_13bb:
	/* 0x13bb: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13c0:
	/* 0x13c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13c5:
	/* 0x13c5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ca:
	/* 0x13ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13cf:
	/* 0x13cf: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_13d2:
	/* 0x13d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d4:
	/* 0x13d4: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13d9:
	/* 0x13d9: lea    rax,[r15-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_13dd:
	/* 0x13dd: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e2:
	/* 0x13e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13e7:
	/* 0x13e7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ec:
	/* 0x13ec: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13f1:
	/* 0x13f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13f6:
	/* 0x13f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f8:
	/* 0x13f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13fd:
	/* 0x13fd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1402:
	/* 0x1402: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1407:
	/* 0x1407: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_140a:
	/* 0x140a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_140d:
	/* 0x140d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140f:
	/* 0x140f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1414:
	/* 0x1414: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1419:
	/* 0x1419: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_141d:
	/* 0x141d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1422:
	/* 0x1422: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1427:
	/* 0x1427: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_142c:
	/* 0x142c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142e:
	/* 0x142e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1433:
	/* 0x1433: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1436:
	/* 0x1436: je     14cc <trace_vfs_utimes+0x14cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cc;
	}
x86_l_143c:
	/* 0x143c: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1441:
	/* 0x1441: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1444:
	/* 0x1444: je     14cc <trace_vfs_utimes+0x14cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14cc;
	}
x86_l_144a:
	/* 0x144a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_144e:
	/* 0x144e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1453:
	/* 0x1453: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1458:
	/* 0x1458: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_145d:
	/* 0x145d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145f:
	/* 0x145f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1463:
	/* 0x1463: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1468:
	/* 0x1468: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_146a:
	/* 0x146a: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1470:
	/* 0x1470: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1472:
	/* 0x1472: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1474:
	/* 0x1474: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_147a:
	/* 0x147a: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_147f:
	/* 0x147f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1484:
	/* 0x1484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1486:
	/* 0x1486: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1489:
	/* 0x1489: jl     1619 <trace_vfs_utimes+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5657ULL;
	}
x86_l_148f:
	/* 0x148f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1494:
	/* 0x1494: mov    BYTE PTR [rcx+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_149b:
	/* 0x149b: mov    ecx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16384ULL);
x86_l_14a0:
	/* 0x14a0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_14a2:
	/* 0x14a2: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a6:
	/* 0x14a6: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ab:
	/* 0x14ab: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: jmp    153d <trace_vfs_utimes+0x153d> */
	return 5437ULL;
x86_l_14b3:
	/* 0x14b3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b6:
	/* 0x14b6: jmp    1659 <trace_vfs_utimes+0x1659> */
	return 5721ULL;
x86_l_14bb:
	/* 0x14bb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_14c0:
	/* 0x14c0: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_14c7:
	/* 0x14c7: jmp    1642 <trace_vfs_utimes+0x1642> */
	return 5698ULL;
x86_l_14cc:
	/* 0x14cc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14cf:
	/* 0x14cf: jne    1619 <trace_vfs_utimes+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5657ULL;
	}
x86_l_14d5:
	/* 0x14d5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14da:
	/* 0x14da: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
	return 5343ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5359ULL: goto x86_l_14ef;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5385ULL: goto x86_l_1509;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5397ULL: goto x86_l_1515;
	case 5402ULL: goto x86_l_151a;
	case 5407ULL: goto x86_l_151f;
	case 5412ULL: goto x86_l_1524;
	case 5417ULL: goto x86_l_1529;
	case 5419ULL: goto x86_l_152b;
	case 5424ULL: goto x86_l_1530;
	case 5428ULL: goto x86_l_1534;
	case 5433ULL: goto x86_l_1539;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5447ULL: goto x86_l_1547;
	case 5452ULL: goto x86_l_154c;
	case 5457ULL: goto x86_l_1551;
	case 5459ULL: goto x86_l_1553;
	case 5464ULL: goto x86_l_1558;
	case 5469ULL: goto x86_l_155d;
	case 5473ULL: goto x86_l_1561;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5498ULL: goto x86_l_157a;
	case 5504ULL: goto x86_l_1580;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5514ULL: goto x86_l_158a;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5528ULL: goto x86_l_1598;
	case 5533ULL: goto x86_l_159d;
	case 5535ULL: goto x86_l_159f;
	case 5539ULL: goto x86_l_15a3;
	case 5541ULL: goto x86_l_15a5;
	case 5547ULL: goto x86_l_15ab;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5562ULL: goto x86_l_15ba;
	case 5567ULL: goto x86_l_15bf;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5588ULL: goto x86_l_15d4;
	case 5591ULL: goto x86_l_15d7;
	case 5593ULL: goto x86_l_15d9;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5609ULL: goto x86_l_15e9;
	case 5612ULL: goto x86_l_15ec;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5634ULL: goto x86_l_1602;
	case 5640ULL: goto x86_l_1608;
	case 5644ULL: goto x86_l_160c;
	case 5651ULL: goto x86_l_1613;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5666ULL: goto x86_l_1622;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5681ULL: goto x86_l_1631;
	case 5683ULL: goto x86_l_1633;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5701ULL: goto x86_l_1645;
	case 5706ULL: goto x86_l_164a;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5718ULL: goto x86_l_1656;
	case 5721ULL: goto x86_l_1659;
	case 5725ULL: goto x86_l_165d;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5743ULL: goto x86_l_166f;
	case 5745ULL: goto x86_l_1671;
	case 5750ULL: goto x86_l_1676;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5772ULL: goto x86_l_168c;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5784ULL: goto x86_l_1698;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5798ULL: goto x86_l_16a6;
	case 5800ULL: goto x86_l_16a8;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5815ULL: goto x86_l_16b7;
	case 5818ULL: goto x86_l_16ba;
	case 5820ULL: goto x86_l_16bc;
	case 5825ULL: goto x86_l_16c1;
	case 5830ULL: goto x86_l_16c6;
	case 5834ULL: goto x86_l_16ca;
	case 5839ULL: goto x86_l_16cf;
	case 5844ULL: goto x86_l_16d4;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5856ULL: goto x86_l_16e0;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5868ULL: goto x86_l_16ec;
	case 5873ULL: goto x86_l_16f1;
	case 5878ULL: goto x86_l_16f6;
	case 5883ULL: goto x86_l_16fb;
	case 5886ULL: goto x86_l_16fe;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5896ULL: goto x86_l_1708;
	case 5898ULL: goto x86_l_170a;
	case 5902ULL: goto x86_l_170e;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5917ULL: goto x86_l_171d;
	case 5919ULL: goto x86_l_171f;
	case 5926ULL: goto x86_l_1726;
	case 5931ULL: goto x86_l_172b;
	case 5933ULL: goto x86_l_172d;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5959ULL: goto x86_l_1747;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5969ULL: goto x86_l_1751;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5993ULL: goto x86_l_1769;
	case 5995ULL: goto x86_l_176b;
	case 6002ULL: goto x86_l_1772;
	case 6007ULL: goto x86_l_1777;
	case 6012ULL: goto x86_l_177c;
	case 6020ULL: goto x86_l_1784;
	case 6026ULL: goto x86_l_178a;
	case 6028ULL: goto x86_l_178c;
	case 6033ULL: goto x86_l_1791;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6048ULL: goto x86_l_17a0;
	case 6054ULL: goto x86_l_17a6;
	case 6056ULL: goto x86_l_17a8;
	case 6065ULL: goto x86_l_17b1;
	case 6073ULL: goto x86_l_17b9;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6101ULL: goto x86_l_17d5;
	case 6105ULL: goto x86_l_17d9;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6120ULL: goto x86_l_17e8;
	case 6122ULL: goto x86_l_17ea;
	case 6124ULL: goto x86_l_17ec;
	case 6126ULL: goto x86_l_17ee;
	case 6134ULL: goto x86_l_17f6;
	case 6141ULL: goto x86_l_17fd;
	case 6143ULL: goto x86_l_17ff;
	case 6151ULL: goto x86_l_1807;
	case 6159ULL: goto x86_l_180f;
	case 6162ULL: goto x86_l_1812;
	case 6170ULL: goto x86_l_181a;
	case 6177ULL: goto x86_l_1821;
	case 6185ULL: goto x86_l_1829;
	case 6192ULL: goto x86_l_1830;
	case 6194ULL: goto x86_l_1832;
	case 6203ULL: goto x86_l_183b;
	case 6209ULL: goto x86_l_1841;
	case 6211ULL: goto x86_l_1843;
	case 6215ULL: goto x86_l_1847;
	case 6222ULL: goto x86_l_184e;
	case 6227ULL: goto x86_l_1853;
	case 6232ULL: goto x86_l_1858;
	case 6237ULL: goto x86_l_185d;
	case 6239ULL: goto x86_l_185f;
	case 6242ULL: goto x86_l_1862;
	case 6244ULL: goto x86_l_1864;
	case 6247ULL: goto x86_l_1867;
	case 6255ULL: goto x86_l_186f;
	case 6262ULL: goto x86_l_1876;
	case 6270ULL: goto x86_l_187e;
	case 6277ULL: goto x86_l_1885;
	case 6279ULL: goto x86_l_1887;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6296ULL: goto x86_l_1898;
	case 6300ULL: goto x86_l_189c;
	case 6307ULL: goto x86_l_18a3;
	case 6312ULL: goto x86_l_18a8;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6324ULL: goto x86_l_18b4;
	case 6327ULL: goto x86_l_18b7;
	case 6329ULL: goto x86_l_18b9;
	case 6332ULL: goto x86_l_18bc;
	case 6340ULL: goto x86_l_18c4;
	case 6347ULL: goto x86_l_18cb;
	case 6355ULL: goto x86_l_18d3;
	case 6362ULL: goto x86_l_18da;
	case 6364ULL: goto x86_l_18dc;
	case 6373ULL: goto x86_l_18e5;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6385ULL: goto x86_l_18f1;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6407ULL: goto x86_l_1907;
	case 6409ULL: goto x86_l_1909;
	case 6412ULL: goto x86_l_190c;
	case 6414ULL: goto x86_l_190e;
	case 6417ULL: goto x86_l_1911;
	case 6425ULL: goto x86_l_1919;
	case 6432ULL: goto x86_l_1920;
	case 6440ULL: goto x86_l_1928;
	case 6447ULL: goto x86_l_192f;
	case 6449ULL: goto x86_l_1931;
	case 6458ULL: goto x86_l_193a;
	case 6464ULL: goto x86_l_1940;
	case 6466ULL: goto x86_l_1942;
	case 6470ULL: goto x86_l_1946;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6502ULL: goto x86_l_1966;
	case 6510ULL: goto x86_l_196e;
	case 6517ULL: goto x86_l_1975;
	case 6524ULL: goto x86_l_197c;
	case 6528ULL: goto x86_l_1980;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6546ULL: goto x86_l_1992;
	case 6548ULL: goto x86_l_1994;
	case 6553ULL: goto x86_l_1999;
	case 6558ULL: goto x86_l_199e;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6572ULL: goto x86_l_19ac;
	case 6577ULL: goto x86_l_19b1;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6588ULL: goto x86_l_19bc;
	case 6593ULL: goto x86_l_19c1;
	case 6598ULL: goto x86_l_19c6;
	case 6603ULL: goto x86_l_19cb;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6635ULL: goto x86_l_19eb;
	case 6639ULL: goto x86_l_19ef;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6658ULL: goto x86_l_1a02;
	case 6661ULL: goto x86_l_1a05;
	case 6663ULL: goto x86_l_1a07;
	case 6668ULL: goto x86_l_1a0c;
	case 6673ULL: goto x86_l_1a11;
	case 6678ULL: goto x86_l_1a16;
	case 6683ULL: goto x86_l_1a1b;
	case 6686ULL: goto x86_l_1a1e;
	case 6688ULL: goto x86_l_1a20;
	case 6692ULL: goto x86_l_1a24;
	case 6696ULL: goto x86_l_1a28;
	case 6700ULL: goto x86_l_1a2c;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6714ULL: goto x86_l_1a3a;
	case 6719ULL: goto x86_l_1a3f;
	case 6721ULL: goto x86_l_1a41;
	case 6725ULL: goto x86_l_1a45;
	case 6729ULL: goto x86_l_1a49;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6749ULL: goto x86_l_1a5d;
	case 6754ULL: goto x86_l_1a62;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6775ULL: goto x86_l_1a77;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6795ULL: goto x86_l_1a8b;
	case 6798ULL: goto x86_l_1a8e;
	case 6800ULL: goto x86_l_1a90;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6812ULL: goto x86_l_1a9c;
	case 6816ULL: goto x86_l_1aa0;
	case 6821ULL: goto x86_l_1aa5;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6833ULL: goto x86_l_1ab1;
	case 6837ULL: goto x86_l_1ab5;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6859ULL: goto x86_l_1acb;
	case 6861ULL: goto x86_l_1acd;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6890ULL: goto x86_l_1aea;
	case 6894ULL: goto x86_l_1aee;
	case 6898ULL: goto x86_l_1af2;
	case 6902ULL: goto x86_l_1af6;
	case 6907ULL: goto x86_l_1afb;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6972ULL: goto x86_l_1b3c;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6997ULL: goto x86_l_1b55;
	case 6999ULL: goto x86_l_1b57;
	case 7003ULL: goto x86_l_1b5b;
	case 7007ULL: goto x86_l_1b5f;
	case 7011ULL: goto x86_l_1b63;
	case 7015ULL: goto x86_l_1b67;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7030ULL: goto x86_l_1b76;
	case 7032ULL: goto x86_l_1b78;
	case 7037ULL: goto x86_l_1b7d;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14df:
	/* 0x14df: je     1619 <trace_vfs_utimes+0x1619> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1619;
	}
x86_l_14e5:
	/* 0x14e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14ea:
	/* 0x14ea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ef:
	/* 0x14ef: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14f3:
	/* 0x14f3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14f8:
	/* 0x14f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14fd:
	/* 0x14fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ff:
	/* 0x14ff: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1504:
	/* 0x1504: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1509:
	/* 0x1509: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_150e:
	/* 0x150e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1513:
	/* 0x1513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1515:
	/* 0x1515: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_151a:
	/* 0x151a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_151f:
	/* 0x151f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1524:
	/* 0x1524: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1529:
	/* 0x1529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152b:
	/* 0x152b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1530:
	/* 0x1530: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1534:
	/* 0x1534: mov    eax,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16384ULL);
x86_l_1539:
	/* 0x1539: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153d:
	/* 0x153d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1542:
	/* 0x1542: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1547:
	/* 0x1547: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_154c:
	/* 0x154c: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1551:
	/* 0x1551: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1553:
	/* 0x1553: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1558:
	/* 0x1558: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_155d:
	/* 0x155d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1561:
	/* 0x1561: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1566:
	/* 0x1566: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_156b:
	/* 0x156b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1570:
	/* 0x1570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1572:
	/* 0x1572: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1577:
	/* 0x1577: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_157a:
	/* 0x157a: je     15ff <trace_vfs_utimes+0x15ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ff;
	}
x86_l_1580:
	/* 0x1580: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1585:
	/* 0x1585: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1588:
	/* 0x1588: je     15ff <trace_vfs_utimes+0x15ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ff;
	}
x86_l_158a:
	/* 0x158a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_158e:
	/* 0x158e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1593:
	/* 0x1593: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1598:
	/* 0x1598: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_159d:
	/* 0x159d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159f:
	/* 0x159f: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15a3:
	/* 0x15a3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_15a5:
	/* 0x15a5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15ab:
	/* 0x15ab: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15af:
	/* 0x15af: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_15b2:
	/* 0x15b2: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15b4:
	/* 0x15b4: jb     1ebf <trace_vfs_utimes+0x1ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7871ULL;
	}
x86_l_15ba:
	/* 0x15ba: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15bf:
	/* 0x15bf: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_15c5:
	/* 0x15c5: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15ca:
	/* 0x15ca: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15cd:
	/* 0x15cd: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_15d2:
	/* 0x15d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d4:
	/* 0x15d4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15d7:
	/* 0x15d7: jl     160c <trace_vfs_utimes+0x160c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_160c;
	}
x86_l_15d9:
	/* 0x15d9: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_15dd:
	/* 0x15dd: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_15e3:
	/* 0x15e3: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_15e9:
	/* 0x15e9: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_15ec:
	/* 0x15ec: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f0:
	/* 0x15f0: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15f5:
	/* 0x15f5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15fa:
	/* 0x15fa: jmp    1e46 <trace_vfs_utimes+0x1e46> */
	return 7750ULL;
x86_l_15ff:
	/* 0x15ff: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1602:
	/* 0x1602: je     1de2 <trace_vfs_utimes+0x1de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7650ULL;
	}
x86_l_1608:
	/* 0x1608: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_160c:
	/* 0x160c: cmp    r15d,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16384ULL);
x86_l_1613:
	/* 0x1613: jne    1ebf <trace_vfs_utimes+0x1ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7871ULL;
	}
x86_l_1619:
	/* 0x1619: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161e:
	/* 0x161e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1622:
	/* 0x1622: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1627:
	/* 0x1627: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_162c:
	/* 0x162c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1631:
	/* 0x1631: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1633:
	/* 0x1633: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1638:
	/* 0x1638: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_163d:
	/* 0x163d: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1642:
	/* 0x1642: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1645:
	/* 0x1645: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_164a:
	/* 0x164a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164c:
	/* 0x164c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_164f:
	/* 0x164f: and    r15d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1656:
	/* 0x1656: add    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1659:
	/* 0x1659: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_165d:
	/* 0x165d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1662:
	/* 0x1662: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1667:
	/* 0x1667: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_166c:
	/* 0x166c: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_166f:
	/* 0x166f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1671:
	/* 0x1671: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1676:
	/* 0x1676: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_167a:
	/* 0x167a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_167f:
	/* 0x167f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1684:
	/* 0x1684: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1689:
	/* 0x1689: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_168c:
	/* 0x168c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168e:
	/* 0x168e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1693:
	/* 0x1693: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1698:
	/* 0x1698: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_169c:
	/* 0x169c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16a1:
	/* 0x16a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16a6:
	/* 0x16a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a8:
	/* 0x16a8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16ad:
	/* 0x16ad: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16b2:
	/* 0x16b2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b7:
	/* 0x16b7: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_16ba:
	/* 0x16ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bc:
	/* 0x16bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16c1:
	/* 0x16c1: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16c6:
	/* 0x16c6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_16ca:
	/* 0x16ca: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16cf:
	/* 0x16cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16d4:
	/* 0x16d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d6:
	/* 0x16d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16db:
	/* 0x16db: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16e0:
	/* 0x16e0: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16e5:
	/* 0x16e5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_16ea:
	/* 0x16ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ec:
	/* 0x16ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_16f1:
	/* 0x16f1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f6:
	/* 0x16f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16fb:
	/* 0x16fb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_16fe:
	/* 0x16fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1700:
	/* 0x1700: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1705:
	/* 0x1705: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1708:
	/* 0x1708: js     172d <trace_vfs_utimes+0x172d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_172d;
	}
x86_l_170a:
	/* 0x170a: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_170e:
	/* 0x170e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1713:
	/* 0x1713: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1718:
	/* 0x1718: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_171d:
	/* 0x171d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_171f:
	/* 0x171f: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1726:
	/* 0x1726: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_172b:
	/* 0x172b: jmp    172f <trace_vfs_utimes+0x172f> */
	goto x86_l_172f;
x86_l_172d:
	/* 0x172d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172f:
	/* 0x172f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1734:
	/* 0x1734: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1738:
	/* 0x1738: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_173d:
	/* 0x173d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1742:
	/* 0x1742: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1747:
	/* 0x1747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1749:
	/* 0x1749: mov    rbx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_174e:
	/* 0x174e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1751:
	/* 0x1751: js     1791 <trace_vfs_utimes+0x1791> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1791;
	}
x86_l_1753:
	/* 0x1753: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1757:
	/* 0x1757: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_175c:
	/* 0x175c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1761:
	/* 0x1761: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1766:
	/* 0x1766: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1769:
	/* 0x1769: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176b:
	/* 0x176b: imul   rax,rbx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RAX, X86_RBX, X86_WIDTH_64, 1000000000ULL);
x86_l_1772:
	/* 0x1772: add    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1777:
	/* 0x1777: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_177c:
	/* 0x177c: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1784:
	/* 0x1784: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_178a:
	/* 0x178a: jbe    17a8 <trace_vfs_utimes+0x17a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17a8;
	}
x86_l_178c:
	/* 0x178c: jmp    1821 <trace_vfs_utimes+0x1821> */
	goto x86_l_1821;
x86_l_1791:
	/* 0x1791: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1793:
	/* 0x1793: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1798:
	/* 0x1798: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17a0:
	/* 0x17a0: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_17a6:
	/* 0x17a6: ja     1821 <trace_vfs_utimes+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1821;
	}
x86_l_17a8:
	/* 0x17a8: mov    BYTE PTR [r14+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_17b1:
	/* 0x17b1: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17b9:
	/* 0x17b9: mov    WORD PTR [r14+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_17c1:
	/* 0x17c1: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_17c6:
	/* 0x17c6: ja     1821 <trace_vfs_utimes+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1821;
	}
x86_l_17c8:
	/* 0x17c8: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_17cd:
	/* 0x17cd: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17d5:
	/* 0x17d5: lea    rdi,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_17d9:
	/* 0x17d9: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_17e0:
	/* 0x17e0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_17e5:
	/* 0x17e5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_17e8:
	/* 0x17e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ea:
	/* 0x17ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17ec:
	/* 0x17ec: jle    1821 <trace_vfs_utimes+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1821;
	}
x86_l_17ee:
	/* 0x17ee: movzx  ecx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_17f6:
	/* 0x17f6: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_17fd:
	/* 0x17fd: ja     1821 <trace_vfs_utimes+0x1821> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1821;
	}
x86_l_17ff:
	/* 0x17ff: mov    DWORD PTR [rcx+r14*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1807:
	/* 0x1807: add    ax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_180f:
	/* 0x180f: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1812:
	/* 0x1812: mov    WORD PTR [r14+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_181a:
	/* 0x181a: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1821:
	/* 0x1821: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1829:
	/* 0x1829: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1830:
	/* 0x1830: ja     1876 <trace_vfs_utimes+0x1876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1876;
	}
x86_l_1832:
	/* 0x1832: mov    BYTE PTR [r14+rbx*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519553ULL);
x86_l_183b:
	/* 0x183b: cmp    ebx,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31995ULL);
x86_l_1841:
	/* 0x1841: ja     1876 <trace_vfs_utimes+0x1876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1876;
	}
x86_l_1843:
	/* 0x1843: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1847:
	/* 0x1847: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_184e:
	/* 0x184e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1853:
	/* 0x1853: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1858:
	/* 0x1858: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_185d:
	/* 0x185d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185f:
	/* 0x185f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1862:
	/* 0x1862: js     1876 <trace_vfs_utimes+0x1876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1876;
	}
x86_l_1864:
	/* 0x1864: add    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1867:
	/* 0x1867: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_186f:
	/* 0x186f: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1876:
	/* 0x1876: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_187e:
	/* 0x187e: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_1885:
	/* 0x1885: ja     18cb <trace_vfs_utimes+0x18cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18cb;
	}
x86_l_1887:
	/* 0x1887: mov    BYTE PTR [r14+rbx*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519554ULL);
x86_l_1890:
	/* 0x1890: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1896:
	/* 0x1896: ja     18cb <trace_vfs_utimes+0x18cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18cb;
	}
x86_l_1898:
	/* 0x1898: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_189c:
	/* 0x189c: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_18a3:
	/* 0x18a3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a8:
	/* 0x18a8: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18ad:
	/* 0x18ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_18b2:
	/* 0x18b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b4:
	/* 0x18b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b7:
	/* 0x18b7: js     18cb <trace_vfs_utimes+0x18cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18cb;
	}
x86_l_18b9:
	/* 0x18b9: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_18bc:
	/* 0x18bc: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_18c4:
	/* 0x18c4: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_18cb:
	/* 0x18cb: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18d3:
	/* 0x18d3: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_18da:
	/* 0x18da: ja     1920 <trace_vfs_utimes+0x1920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1920;
	}
x86_l_18dc:
	/* 0x18dc: mov    BYTE PTR [r14+rbx*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519555ULL);
x86_l_18e5:
	/* 0x18e5: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_18eb:
	/* 0x18eb: ja     1920 <trace_vfs_utimes+0x1920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1920;
	}
x86_l_18ed:
	/* 0x18ed: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_18f1:
	/* 0x18f1: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_18f8:
	/* 0x18f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18fd:
	/* 0x18fd: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1902:
	/* 0x1902: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1907:
	/* 0x1907: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1909:
	/* 0x1909: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_190c:
	/* 0x190c: js     1920 <trace_vfs_utimes+0x1920> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1920;
	}
x86_l_190e:
	/* 0x190e: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1911:
	/* 0x1911: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1919:
	/* 0x1919: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1920:
	/* 0x1920: movzx  ebx,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1928:
	/* 0x1928: cmp    rbx,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 31999ULL);
x86_l_192f:
	/* 0x192f: ja     1975 <trace_vfs_utimes+0x1975> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1975;
	}
x86_l_1931:
	/* 0x1931: mov    BYTE PTR [r14+rbx*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RBX, 0), 588410519556ULL);
x86_l_193a:
	/* 0x193a: cmp    ebx,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 31991ULL);
x86_l_1940:
	/* 0x1940: ja     1975 <trace_vfs_utimes+0x1975> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1975;
	}
x86_l_1942:
	/* 0x1942: lea    rdi,[rbx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1946:
	/* 0x1946: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_194d:
	/* 0x194d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1952:
	/* 0x1952: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1957:
	/* 0x1957: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_195c:
	/* 0x195c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195e:
	/* 0x195e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1961:
	/* 0x1961: js     1975 <trace_vfs_utimes+0x1975> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1975;
	}
x86_l_1963:
	/* 0x1963: add    ebx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1966:
	/* 0x1966: mov    WORD PTR [r14+0x7d8a],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_196e:
	/* 0x196e: inc    BYTE PTR [r14+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1975:
	/* 0x1975: mov    rbx,QWORD PTR [r14+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_197c:
	/* 0x197c: lea    r12,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1980:
	/* 0x1980: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1985:
	/* 0x1985: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_198a:
	/* 0x198a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_198f:
	/* 0x198f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1992:
	/* 0x1992: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1994:
	/* 0x1994: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1999:
	/* 0x1999: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_199e:
	/* 0x199e: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a2:
	/* 0x19a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19a7:
	/* 0x19a7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19ac:
	/* 0x19ac: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19b1:
	/* 0x19b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b3:
	/* 0x19b3: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19b8:
	/* 0x19b8: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_19bc:
	/* 0x19bc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19c1:
	/* 0x19c1: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19c6:
	/* 0x19c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19cb:
	/* 0x19cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19cd:
	/* 0x19cd: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19d2:
	/* 0x19d2: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19d6:
	/* 0x19d6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19db:
	/* 0x19db: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19e0:
	/* 0x19e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19e5:
	/* 0x19e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e7:
	/* 0x19e7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19eb:
	/* 0x19eb: mov    DWORD PTR [r14+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19ef:
	/* 0x19ef: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f3:
	/* 0x19f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19f8:
	/* 0x19f8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19fd:
	/* 0x19fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a02:
	/* 0x1a02: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1a05:
	/* 0x1a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a07:
	/* 0x1a07: mov    r13,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a11:
	/* 0x1a11: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a16:
	/* 0x1a16: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1a1e:
	/* 0x1a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a20:
	/* 0x1a20: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a24:
	/* 0x1a24: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1a28:
	/* 0x1a28: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1a2c:
	/* 0x1a2c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a30:
	/* 0x1a30: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a35:
	/* 0x1a35: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a3a:
	/* 0x1a3a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a3f:
	/* 0x1a3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a41:
	/* 0x1a41: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a45:
	/* 0x1a45: mov    DWORD PTR [r14+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a49:
	/* 0x1a49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a4e:
	/* 0x1a4e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a53:
	/* 0x1a53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a58:
	/* 0x1a58: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a5b:
	/* 0x1a5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5d:
	/* 0x1a5d: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
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
	/* 0x1a70: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a75:
	/* 0x1a75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a77:
	/* 0x1a77: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a81:
	/* 0x1a81: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a86:
	/* 0x1a86: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a8b:
	/* 0x1a8b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1a8e:
	/* 0x1a8e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a90:
	/* 0x1a90: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a94:
	/* 0x1a94: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1a98:
	/* 0x1a98: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a9c:
	/* 0x1a9c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1aa0:
	/* 0x1aa0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa5:
	/* 0x1aa5: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aaf:
	/* 0x1aaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab1:
	/* 0x1ab1: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    DWORD PTR [r14+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1abe:
	/* 0x1abe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac8:
	/* 0x1ac8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1acb:
	/* 0x1acb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1acd:
	/* 0x1acd: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad7:
	/* 0x1ad7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1adc:
	/* 0x1adc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ae4:
	/* 0x1ae4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae6:
	/* 0x1ae6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1aea:
	/* 0x1aea: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1aee:
	/* 0x1aee: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1af2:
	/* 0x1af2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1af6:
	/* 0x1af6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1afb:
	/* 0x1afb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b00:
	/* 0x1b00: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b05:
	/* 0x1b05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b07:
	/* 0x1b07: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b0c:
	/* 0x1b0c: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1b10:
	/* 0x1b10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b15:
	/* 0x1b15: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b1f:
	/* 0x1b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b21:
	/* 0x1b21: mov    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b26:
	/* 0x1b26: lea    r15,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b2f:
	/* 0x1b2f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b34:
	/* 0x1b34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b39:
	/* 0x1b39: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b3c:
	/* 0x1b3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3e:
	/* 0x1b3e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b43:
	/* 0x1b43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b48:
	/* 0x1b48: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b52:
	/* 0x1b52: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1b55:
	/* 0x1b55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b57:
	/* 0x1b57: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b5b:
	/* 0x1b5b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1b5f:
	/* 0x1b5f: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b63:
	/* 0x1b63: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b67:
	/* 0x1b67: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b6c:
	/* 0x1b6c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b71:
	/* 0x1b71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b76:
	/* 0x1b76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b78:
	/* 0x1b78: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b7d:
	/* 0x1b7d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1b81:
	/* 0x1b81: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b86:
	/* 0x1b86: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
	return 7056ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7056ULL: goto x86_l_1b90;
	case 7058ULL: goto x86_l_1b92;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7083ULL: goto x86_l_1bab;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7100ULL: goto x86_l_1bbc;
	case 7105ULL: goto x86_l_1bc1;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7114ULL: goto x86_l_1bca;
	case 7118ULL: goto x86_l_1bce;
	case 7122ULL: goto x86_l_1bd2;
	case 7126ULL: goto x86_l_1bd6;
	case 7131ULL: goto x86_l_1bdb;
	case 7136ULL: goto x86_l_1be0;
	case 7141ULL: goto x86_l_1be5;
	case 7143ULL: goto x86_l_1be7;
	case 7147ULL: goto x86_l_1beb;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7159ULL: goto x86_l_1bf7;
	case 7166ULL: goto x86_l_1bfe;
	case 7171ULL: goto x86_l_1c03;
	case 7176ULL: goto x86_l_1c08;
	case 7181ULL: goto x86_l_1c0d;
	case 7184ULL: goto x86_l_1c10;
	case 7186ULL: goto x86_l_1c12;
	case 7191ULL: goto x86_l_1c17;
	case 7195ULL: goto x86_l_1c1b;
	case 7200ULL: goto x86_l_1c20;
	case 7205ULL: goto x86_l_1c25;
	case 7210ULL: goto x86_l_1c2a;
	case 7212ULL: goto x86_l_1c2c;
	case 7217ULL: goto x86_l_1c31;
	case 7222ULL: goto x86_l_1c36;
	case 7227ULL: goto x86_l_1c3b;
	case 7232ULL: goto x86_l_1c40;
	case 7234ULL: goto x86_l_1c42;
	case 7238ULL: goto x86_l_1c46;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7249ULL: goto x86_l_1c51;
	case 7253ULL: goto x86_l_1c55;
	case 7257ULL: goto x86_l_1c59;
	case 7262ULL: goto x86_l_1c5e;
	case 7267ULL: goto x86_l_1c63;
	case 7272ULL: goto x86_l_1c68;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7292ULL: goto x86_l_1c7c;
	case 7297ULL: goto x86_l_1c81;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7309ULL: goto x86_l_1c8d;
	case 7314ULL: goto x86_l_1c92;
	case 7318ULL: goto x86_l_1c96;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7332ULL: goto x86_l_1ca4;
	case 7337ULL: goto x86_l_1ca9;
	case 7340ULL: goto x86_l_1cac;
	case 7342ULL: goto x86_l_1cae;
	case 7347ULL: goto x86_l_1cb3;
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7369ULL: goto x86_l_1cc9;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7387ULL: goto x86_l_1cdb;
	case 7395ULL: goto x86_l_1ce3;
	case 7403ULL: goto x86_l_1ceb;
	case 7408ULL: goto x86_l_1cf0;
	case 7413ULL: goto x86_l_1cf5;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7435ULL: goto x86_l_1d0b;
	case 7440ULL: goto x86_l_1d10;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7467ULL: goto x86_l_1d2b;
	case 7472ULL: goto x86_l_1d30;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7482ULL: goto x86_l_1d3a;
	case 7485ULL: goto x86_l_1d3d;
	case 7489ULL: goto x86_l_1d41;
	case 7494ULL: goto x86_l_1d46;
	case 7499ULL: goto x86_l_1d4b;
	case 7502ULL: goto x86_l_1d4e;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7535ULL: goto x86_l_1d6f;
	case 7539ULL: goto x86_l_1d73;
	case 7547ULL: goto x86_l_1d7b;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7575ULL: goto x86_l_1d97;
	case 7579ULL: goto x86_l_1d9b;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7606ULL: goto x86_l_1db6;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7622ULL: goto x86_l_1dc6;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7635ULL: goto x86_l_1dd3;
	case 7642ULL: goto x86_l_1dda;
	case 7644ULL: goto x86_l_1ddc;
	case 7645ULL: goto x86_l_1ddd;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7660ULL: goto x86_l_1dec;
	case 7666ULL: goto x86_l_1df2;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7680ULL: goto x86_l_1e00;
	case 7685ULL: goto x86_l_1e05;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7714ULL: goto x86_l_1e22;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7736ULL: goto x86_l_1e38;
	case 7741ULL: goto x86_l_1e3d;
	case 7745ULL: goto x86_l_1e41;
	case 7750ULL: goto x86_l_1e46;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7782ULL: goto x86_l_1e66;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7801ULL: goto x86_l_1e79;
	case 7803ULL: goto x86_l_1e7b;
	case 7808ULL: goto x86_l_1e80;
	case 7811ULL: goto x86_l_1e83;
	case 7813ULL: goto x86_l_1e85;
	case 7818ULL: goto x86_l_1e8a;
	case 7821ULL: goto x86_l_1e8d;
	case 7823ULL: goto x86_l_1e8f;
	case 7827ULL: goto x86_l_1e93;
	case 7832ULL: goto x86_l_1e98;
	case 7837ULL: goto x86_l_1e9d;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7848ULL: goto x86_l_1ea8;
	case 7850ULL: goto x86_l_1eaa;
	case 7856ULL: goto x86_l_1eb0;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7871ULL: goto x86_l_1ebf;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7882ULL: goto x86_l_1eca;
	case 7887ULL: goto x86_l_1ecf;
	case 7892ULL: goto x86_l_1ed4;
	case 7901ULL: goto x86_l_1edd;
	case 7906ULL: goto x86_l_1ee2;
	case 7909ULL: goto x86_l_1ee5;
	case 7915ULL: goto x86_l_1eeb;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7931ULL: goto x86_l_1efb;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7945ULL: goto x86_l_1f09;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7977ULL: goto x86_l_1f29;
	case 7979ULL: goto x86_l_1f2b;
	case 7984ULL: goto x86_l_1f30;
	case 7989ULL: goto x86_l_1f35;
	case 7994ULL: goto x86_l_1f3a;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8010ULL: goto x86_l_1f4a;
	case 8012ULL: goto x86_l_1f4c;
	case 8017ULL: goto x86_l_1f51;
	case 8023ULL: goto x86_l_1f57;
	case 8026ULL: goto x86_l_1f5a;
	case 8031ULL: goto x86_l_1f5f;
	case 8033ULL: goto x86_l_1f61;
	case 8036ULL: goto x86_l_1f64;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8058ULL: goto x86_l_1f7a;
	case 8061ULL: goto x86_l_1f7d;
	case 8065ULL: goto x86_l_1f81;
	case 8070ULL: goto x86_l_1f86;
	case 8075ULL: goto x86_l_1f8b;
	case 8080ULL: goto x86_l_1f90;
	case 8085ULL: goto x86_l_1f95;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8097ULL: goto x86_l_1fa1;
	case 8102ULL: goto x86_l_1fa6;
	case 8107ULL: goto x86_l_1fab;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8121ULL: goto x86_l_1fb9;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8146ULL: goto x86_l_1fd2;
	case 8148ULL: goto x86_l_1fd4;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8181ULL: goto x86_l_1ff5;
	case 8185ULL: goto x86_l_1ff9;
	case 8188ULL: goto x86_l_1ffc;
	case 8190ULL: goto x86_l_1ffe;
	case 8196ULL: goto x86_l_2004;
	case 8201ULL: goto x86_l_2009;
	case 8207ULL: goto x86_l_200f;
	case 8210ULL: goto x86_l_2012;
	case 8215ULL: goto x86_l_2017;
	case 8217ULL: goto x86_l_2019;
	case 8220ULL: goto x86_l_201c;
	case 8226ULL: goto x86_l_2022;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8242ULL: goto x86_l_2032;
	case 8245ULL: goto x86_l_2035;
	case 8249ULL: goto x86_l_2039;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8261ULL: goto x86_l_2045;
	case 8264ULL: goto x86_l_2048;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8280ULL: goto x86_l_2058;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8300ULL: goto x86_l_206c;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8312ULL: goto x86_l_2078;
	case 8317ULL: goto x86_l_207d;
	case 8322ULL: goto x86_l_2082;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8354ULL: goto x86_l_20a2;
	case 8356ULL: goto x86_l_20a4;
	case 8361ULL: goto x86_l_20a9;
	case 8365ULL: goto x86_l_20ad;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8380ULL: goto x86_l_20bc;
	case 8385ULL: goto x86_l_20c1;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8397ULL: goto x86_l_20cd;
	case 8401ULL: goto x86_l_20d1;
	case 8406ULL: goto x86_l_20d6;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8423ULL: goto x86_l_20e7;
	case 8426ULL: goto x86_l_20ea;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8446ULL: goto x86_l_20fe;
	case 8450ULL: goto x86_l_2102;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8471ULL: goto x86_l_2117;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8483ULL: goto x86_l_2123;
	case 8486ULL: goto x86_l_2126;
	case 8488ULL: goto x86_l_2128;
	case 8494ULL: goto x86_l_212e;
	case 8499ULL: goto x86_l_2133;
	case 8505ULL: goto x86_l_2139;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8524ULL: goto x86_l_214c;
	case 8528ULL: goto x86_l_2150;
	case 8534ULL: goto x86_l_2156;
	case 8540ULL: goto x86_l_215c;
	case 8543ULL: goto x86_l_215f;
	case 8547ULL: goto x86_l_2163;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8569ULL: goto x86_l_2179;
	case 8572ULL: goto x86_l_217c;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8586ULL: goto x86_l_218a;
	case 8588ULL: goto x86_l_218c;
	case 8591ULL: goto x86_l_218f;
	case 8593ULL: goto x86_l_2191;
	case 8599ULL: goto x86_l_2197;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8611ULL: goto x86_l_21a3;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8625ULL: goto x86_l_21b1;
	case 8630ULL: goto x86_l_21b6;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8677ULL: goto x86_l_21e5;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8689ULL: goto x86_l_21f1;
	case 8694ULL: goto x86_l_21f6;
	case 8699ULL: goto x86_l_21fb;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b90:
	/* 0x1b90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b92:
	/* 0x1b92: cmp    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 48ULL);
x86_l_1b97:
	/* 0x1b97: jne    1bef <trace_vfs_utimes+0x1bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bef;
	}
x86_l_1b99:
	/* 0x1b99: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b9e:
	/* 0x1b9e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1bab:
	/* 0x1bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bad:
	/* 0x1bad: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bb7:
	/* 0x1bb7: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bbc:
	/* 0x1bbc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1bc4:
	/* 0x1bc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc6:
	/* 0x1bc6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bca:
	/* 0x1bca: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1bce:
	/* 0x1bce: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bd2:
	/* 0x1bd2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1bd6:
	/* 0x1bd6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bdb:
	/* 0x1bdb: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be0:
	/* 0x1be0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1be5:
	/* 0x1be5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be7:
	/* 0x1be7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1beb:
	/* 0x1beb: mov    DWORD PTR [r14+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bef:
	/* 0x1bef: lea    r12,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    DWORD PTR [r14+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bf7:
	/* 0x1bf7: lea    r15,[rbx+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1bfe:
	/* 0x1bfe: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c03:
	/* 0x1c03: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c08:
	/* 0x1c08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c0d:
	/* 0x1c0d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c10:
	/* 0x1c10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c12:
	/* 0x1c12: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c17:
	/* 0x1c17: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c1b:
	/* 0x1c1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c20:
	/* 0x1c20: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c25:
	/* 0x1c25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c2a:
	/* 0x1c2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c2c:
	/* 0x1c2c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c31:
	/* 0x1c31: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c36:
	/* 0x1c36: lea    rdi,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1c3b:
	/* 0x1c3b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c40:
	/* 0x1c40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c42:
	/* 0x1c42: mov    eax,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1c46:
	/* 0x1c46: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c4a:
	/* 0x1c4a: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1c4f:
	/* 0x1c4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c51:
	/* 0x1c51: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c55:
	/* 0x1c55: lea    rdx,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1c59:
	/* 0x1c59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c5e:
	/* 0x1c5e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c63:
	/* 0x1c63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c68:
	/* 0x1c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c6a:
	/* 0x1c6a: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c6f:
	/* 0x1c6f: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c73:
	/* 0x1c73: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c78:
	/* 0x1c78: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1c7c:
	/* 0x1c7c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c81:
	/* 0x1c81: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c86:
	/* 0x1c86: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c8b:
	/* 0x1c8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8d:
	/* 0x1c8d: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c92:
	/* 0x1c92: mov    QWORD PTR [r14+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c96:
	/* 0x1c96: add    rbp,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c9f:
	/* 0x1c9f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1cac:
	/* 0x1cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cae:
	/* 0x1cae: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cb3:
	/* 0x1cb3: mov    QWORD PTR [r14+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cbc:
	/* 0x1cbc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cc1:
	/* 0x1cc1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1cc9:
	/* 0x1cc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ccb:
	/* 0x1ccb: test   BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1cd0:
	/* 0x1cd0: je     1cd7 <trace_vfs_utimes+0x1cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd7;
	}
x86_l_1cd2:
	/* 0x1cd2: or     BYTE PTR [r14+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1cd7:
	/* 0x1cd7: lea    rdi,[r14+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1cdb:
	/* 0x1cdb: mov    QWORD PTR [r14+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1ce3:
	/* 0x1ce3: mov    QWORD PTR [r14+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1ceb:
	/* 0x1ceb: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1cf5:
	/* 0x1cf5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf7:
	/* 0x1cf7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cfc:
	/* 0x1cfc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d01:
	/* 0x1d01: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d06:
	/* 0x1d06: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d09:
	/* 0x1d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0b:
	/* 0x1d0b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d10:
	/* 0x1d10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d15:
	/* 0x1d15: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d1f:
	/* 0x1d1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d21:
	/* 0x1d21: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d26:
	/* 0x1d26: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d2b:
	/* 0x1d2b: lea    rbx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d30:
	/* 0x1d30: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d33:
	/* 0x1d33: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1d38:
	/* 0x1d38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3a:
	/* 0x1d3a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1d3d:
	/* 0x1d3d: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1d41:
	/* 0x1d41: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1d46:
	/* 0x1d46: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d4b:
	/* 0x1d4b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d4e:
	/* 0x1d4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d50:
	/* 0x1d50: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d55:
	/* 0x1d55: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1d5d:
	/* 0x1d5d: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1d62:
	/* 0x1d62: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d65:
	/* 0x1d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d67:
	/* 0x1d67: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1d6f:
	/* 0x1d6f: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1d73:
	/* 0x1d73: mov    rbx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1d7b:
	/* 0x1d7b: je     1d9b <trace_vfs_utimes+0x1d9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d9b;
	}
x86_l_1d7d:
	/* 0x1d7d: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1d82:
	/* 0x1d82: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1d89:
	/* 0x1d89: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1d8e:
	/* 0x1d8e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d91:
	/* 0x1d91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d93:
	/* 0x1d93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d95:
	/* 0x1d95: js     1d9b <trace_vfs_utimes+0x1d9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d9b;
	}
x86_l_1d97:
	/* 0x1d97: mov    DWORD PTR [r14+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d9b:
	/* 0x1d9b: movzx  eax,WORD PTR [r14+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1da3:
	/* 0x1da3: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1da8:
	/* 0x1da8: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1dad:
	/* 0x1dad: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1db0:
	/* 0x1db0: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1db6:
	/* 0x1db6: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1dba:
	/* 0x1dba: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1dc6:
	/* 0x1dc6: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1dcb:
	/* 0x1dcb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dce:
	/* 0x1dce: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1dd1:
	/* 0x1dd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd3:
	/* 0x1dd3: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_1dda:
	/* 0x1dda: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ddc:
	/* 0x1ddc: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1ddd:
	/* 0x1ddd: jmp    3347 <trace_vfs_utimes+0x3347> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1de2:
	/* 0x1de2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1de7:
	/* 0x1de7: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1dec:
	/* 0x1dec: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_1df2:
	/* 0x1df2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1df7:
	/* 0x1df7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dfc:
	/* 0x1dfc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e00:
	/* 0x1e00: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e05:
	/* 0x1e05: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e0a:
	/* 0x1e0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0c:
	/* 0x1e0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e11:
	/* 0x1e11: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e16:
	/* 0x1e16: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1b:
	/* 0x1e1b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e20:
	/* 0x1e20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e22:
	/* 0x1e22: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e27:
	/* 0x1e27: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e2c:
	/* 0x1e2c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e31:
	/* 0x1e31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e36:
	/* 0x1e36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e38:
	/* 0x1e38: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e3d:
	/* 0x1e3d: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e41:
	/* 0x1e41: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e46:
	/* 0x1e46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e4b:
	/* 0x1e4b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e50:
	/* 0x1e50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e55:
	/* 0x1e55: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e5a:
	/* 0x1e5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e5c:
	/* 0x1e5c: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e61:
	/* 0x1e61: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e66:
	/* 0x1e66: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e6f:
	/* 0x1e6f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e74:
	/* 0x1e74: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e79:
	/* 0x1e79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7b:
	/* 0x1e7b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e80:
	/* 0x1e80: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e83:
	/* 0x1e83: je     1ee2 <trace_vfs_utimes+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee2;
	}
x86_l_1e85:
	/* 0x1e85: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e8a:
	/* 0x1e8a: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e8d:
	/* 0x1e8d: je     1ee2 <trace_vfs_utimes+0x1ee2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ee2;
	}
x86_l_1e8f:
	/* 0x1e8f: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1e93:
	/* 0x1e93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1e98:
	/* 0x1e98: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e9d:
	/* 0x1e9d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ea2:
	/* 0x1ea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea4:
	/* 0x1ea4: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ea8:
	/* 0x1ea8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1eaa:
	/* 0x1eaa: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1eb0:
	/* 0x1eb0: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_1eb7:
	/* 0x1eb7: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1eb9:
	/* 0x1eb9: jae    1f4c <trace_vfs_utimes+0x1f4c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f4c;
	}
x86_l_1ebf:
	/* 0x1ebf: dec    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1ec2:
	/* 0x1ec2: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_1ec5:
	/* 0x1ec5: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1eca:
	/* 0x1eca: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ecf:
	/* 0x1ecf: mov    BYTE PTR [r12+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    BYTE PTR [r12+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_1edd:
	/* 0x1edd: jmp    164f <trace_vfs_utimes+0x164f> */
	return 5711ULL;
x86_l_1ee2:
	/* 0x1ee2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ee5:
	/* 0x1ee5: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_1eeb:
	/* 0x1eeb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef0:
	/* 0x1ef0: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1ef5:
	/* 0x1ef5: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_1efb:
	/* 0x1efb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f00:
	/* 0x1f00: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f05:
	/* 0x1f05: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1f09:
	/* 0x1f09: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0e:
	/* 0x1f0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f13:
	/* 0x1f13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f15:
	/* 0x1f15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f1f:
	/* 0x1f1f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f24:
	/* 0x1f24: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f29:
	/* 0x1f29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2b:
	/* 0x1f2b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f30:
	/* 0x1f30: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f35:
	/* 0x1f35: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f3a:
	/* 0x1f3a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f3f:
	/* 0x1f3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f41:
	/* 0x1f41: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f46:
	/* 0x1f46: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1f4a:
	/* 0x1f4a: jmp    1f8b <trace_vfs_utimes+0x1f8b> */
	goto x86_l_1f8b;
x86_l_1f4c:
	/* 0x1f4c: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f51:
	/* 0x1f51: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1f57:
	/* 0x1f57: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f5a:
	/* 0x1f5a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1f5f:
	/* 0x1f5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f61:
	/* 0x1f61: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f64:
	/* 0x1f64: jl     160c <trace_vfs_utimes+0x160c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5644ULL;
	}
x86_l_1f6a:
	/* 0x1f6a: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1f6e:
	/* 0x1f6e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1f74:
	/* 0x1f74: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1f7a:
	/* 0x1f7a: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f7d:
	/* 0x1f7d: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f81:
	/* 0x1f81: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f86:
	/* 0x1f86: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f8b:
	/* 0x1f8b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1f90:
	/* 0x1f90: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f95:
	/* 0x1f95: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f9f:
	/* 0x1f9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa1:
	/* 0x1fa1: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fa6:
	/* 0x1fa6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fab:
	/* 0x1fab: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1faf:
	/* 0x1faf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fb4:
	/* 0x1fb4: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fbe:
	/* 0x1fbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc0:
	/* 0x1fc0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fc5:
	/* 0x1fc5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1fc8:
	/* 0x1fc8: je     2045 <trace_vfs_utimes+0x2045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2045;
	}
x86_l_1fca:
	/* 0x1fca: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fcf:
	/* 0x1fcf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1fd2:
	/* 0x1fd2: je     2045 <trace_vfs_utimes+0x2045> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2045;
	}
x86_l_1fd4:
	/* 0x1fd4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1fdd:
	/* 0x1fdd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1fe7:
	/* 0x1fe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe9:
	/* 0x1fe9: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1fed:
	/* 0x1fed: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1fef:
	/* 0x1fef: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1ff5:
	/* 0x1ff5: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff9:
	/* 0x1ff9: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_1ffc:
	/* 0x1ffc: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ffe:
	/* 0x1ffe: jb     1ebf <trace_vfs_utimes+0x1ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ebf;
	}
x86_l_2004:
	/* 0x2004: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2009:
	/* 0x2009: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_200f:
	/* 0x200f: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2012:
	/* 0x2012: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2017:
	/* 0x2017: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2019:
	/* 0x2019: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_201c:
	/* 0x201c: jl     160c <trace_vfs_utimes+0x160c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5644ULL;
	}
x86_l_2022:
	/* 0x2022: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2026:
	/* 0x2026: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_202c:
	/* 0x202c: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2032:
	/* 0x2032: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2035:
	/* 0x2035: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2039:
	/* 0x2039: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203e:
	/* 0x203e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2043:
	/* 0x2043: jmp    20ad <trace_vfs_utimes+0x20ad> */
	goto x86_l_20ad;
x86_l_2045:
	/* 0x2045: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2048:
	/* 0x2048: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_204e:
	/* 0x204e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2053:
	/* 0x2053: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2058:
	/* 0x2058: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_205e:
	/* 0x205e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2063:
	/* 0x2063: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2068:
	/* 0x2068: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_206c:
	/* 0x206c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2071:
	/* 0x2071: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2076:
	/* 0x2076: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2078:
	/* 0x2078: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_207d:
	/* 0x207d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2082:
	/* 0x2082: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2087:
	/* 0x2087: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_208c:
	/* 0x208c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208e:
	/* 0x208e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2093:
	/* 0x2093: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2098:
	/* 0x2098: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_209d:
	/* 0x209d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a2:
	/* 0x20a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a4:
	/* 0x20a4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20a9:
	/* 0x20a9: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_20ad:
	/* 0x20ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20b2:
	/* 0x20b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20b7:
	/* 0x20b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20bc:
	/* 0x20bc: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20c1:
	/* 0x20c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c3:
	/* 0x20c3: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20c8:
	/* 0x20c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20cd:
	/* 0x20cd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_20d1:
	/* 0x20d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_20d6:
	/* 0x20d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20db:
	/* 0x20db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20e0:
	/* 0x20e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e2:
	/* 0x20e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e7:
	/* 0x20e7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20ea:
	/* 0x20ea: je     21a8 <trace_vfs_utimes+0x21a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a8;
	}
x86_l_20f0:
	/* 0x20f0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20f5:
	/* 0x20f5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20f8:
	/* 0x20f8: je     21a8 <trace_vfs_utimes+0x21a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a8;
	}
x86_l_20fe:
	/* 0x20fe: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2102:
	/* 0x2102: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2107:
	/* 0x2107: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_210c:
	/* 0x210c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2111:
	/* 0x2111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2113:
	/* 0x2113: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2117:
	/* 0x2117: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2119:
	/* 0x2119: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_211f:
	/* 0x211f: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2123:
	/* 0x2123: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_2126:
	/* 0x2126: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2128:
	/* 0x2128: jb     1ebf <trace_vfs_utimes+0x1ebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ebf;
	}
x86_l_212e:
	/* 0x212e: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2133:
	/* 0x2133: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2139:
	/* 0x2139: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_213c:
	/* 0x213c: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2141:
	/* 0x2141: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2143:
	/* 0x2143: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2146:
	/* 0x2146: jl     160c <trace_vfs_utimes+0x160c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5644ULL;
	}
x86_l_214c:
	/* 0x214c: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2150:
	/* 0x2150: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2156:
	/* 0x2156: mov    BYTE PTR [r13+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_215c:
	/* 0x215c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_215f:
	/* 0x215f: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2163:
	/* 0x2163: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2168:
	/* 0x2168: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_216d:
	/* 0x216d: jmp    2210 <trace_vfs_utimes+0x2210> */
	return 8720ULL;
x86_l_2172:
	/* 0x2172: lea    rdi,[r14+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_2179:
	/* 0x2179: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_217c:
	/* 0x217c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2180:
	/* 0x2180: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2185:
	/* 0x2185: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_218a:
	/* 0x218a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218c:
	/* 0x218c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_218f:
	/* 0x218f: jne    21a1 <trace_vfs_utimes+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21a1;
	}
x86_l_2191:
	/* 0x2191: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2197:
	/* 0x2197: mov    WORD PTR [r14+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_219c:
	/* 0x219c: jmp    ad9 <trace_vfs_utimes+0xad9> */
	return 2777ULL;
x86_l_21a1:
	/* 0x21a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a3:
	/* 0x21a3: jmp    1dd3 <trace_vfs_utimes+0x1dd3> */
	goto x86_l_1dd3;
x86_l_21a8:
	/* 0x21a8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21ab:
	/* 0x21ab: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_21b1:
	/* 0x21b1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21b6:
	/* 0x21b6: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_21bb:
	/* 0x21bb: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_21c1:
	/* 0x21c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21c6:
	/* 0x21c6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21cb:
	/* 0x21cb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_21cf:
	/* 0x21cf: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d4:
	/* 0x21d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21d9:
	/* 0x21d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21db:
	/* 0x21db: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21e0:
	/* 0x21e0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e5:
	/* 0x21e5: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21ea:
	/* 0x21ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21ef:
	/* 0x21ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f1:
	/* 0x21f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_21f6:
	/* 0x21f6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21fb:
	/* 0x21fb: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2200:
	/* 0x2200: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2205:
	/* 0x2205: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 8711ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8711ULL: goto x86_l_2207;
	case 8716ULL: goto x86_l_220c;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8756ULL: goto x86_l_2234;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8791ULL: goto x86_l_2257;
	case 8793ULL: goto x86_l_2259;
	case 8797ULL: goto x86_l_225d;
	case 8802ULL: goto x86_l_2262;
	case 8807ULL: goto x86_l_2267;
	case 8812ULL: goto x86_l_226c;
	case 8814ULL: goto x86_l_226e;
	case 8818ULL: goto x86_l_2272;
	case 8820ULL: goto x86_l_2274;
	case 8826ULL: goto x86_l_227a;
	case 8830ULL: goto x86_l_227e;
	case 8832ULL: goto x86_l_2280;
	case 8834ULL: goto x86_l_2282;
	case 8838ULL: goto x86_l_2286;
	case 8843ULL: goto x86_l_228b;
	case 8846ULL: goto x86_l_228e;
	case 8852ULL: goto x86_l_2294;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8882ULL: goto x86_l_22b2;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8894ULL: goto x86_l_22be;
	case 8899ULL: goto x86_l_22c3;
	case 8904ULL: goto x86_l_22c8;
	case 8909ULL: goto x86_l_22cd;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8943ULL: goto x86_l_22ef;
	case 8947ULL: goto x86_l_22f3;
	case 8952ULL: goto x86_l_22f8;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8975ULL: goto x86_l_230f;
	case 8977ULL: goto x86_l_2311;
	case 8980ULL: goto x86_l_2314;
	case 8986ULL: goto x86_l_231a;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9008ULL: goto x86_l_2330;
	case 9010ULL: goto x86_l_2332;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9046ULL: goto x86_l_2356;
	case 9051ULL: goto x86_l_235b;
	case 9055ULL: goto x86_l_235f;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9080ULL: goto x86_l_2378;
	case 9082ULL: goto x86_l_237a;
	case 9087ULL: goto x86_l_237f;
	case 9090ULL: goto x86_l_2382;
	case 9092ULL: goto x86_l_2384;
	case 9096ULL: goto x86_l_2388;
	case 9101ULL: goto x86_l_238d;
	case 9106ULL: goto x86_l_2392;
	case 9111ULL: goto x86_l_2397;
	case 9113ULL: goto x86_l_2399;
	case 9117ULL: goto x86_l_239d;
	case 9119ULL: goto x86_l_239f;
	case 9125ULL: goto x86_l_23a5;
	case 9129ULL: goto x86_l_23a9;
	case 9131ULL: goto x86_l_23ab;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9148ULL: goto x86_l_23bc;
	case 9153ULL: goto x86_l_23c1;
	case 9158ULL: goto x86_l_23c6;
	case 9160ULL: goto x86_l_23c8;
	case 9163ULL: goto x86_l_23cb;
	case 9169ULL: goto x86_l_23d1;
	case 9173ULL: goto x86_l_23d5;
	case 9176ULL: goto x86_l_23d8;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9191ULL: goto x86_l_23e7;
	case 9193ULL: goto x86_l_23e9;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9213ULL: goto x86_l_23fd;
	case 9218ULL: goto x86_l_2402;
	case 9223ULL: goto x86_l_2407;
	case 9229ULL: goto x86_l_240d;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9243ULL: goto x86_l_241b;
	case 9248ULL: goto x86_l_2420;
	case 9253ULL: goto x86_l_2425;
	case 9255ULL: goto x86_l_2427;
	case 9260ULL: goto x86_l_242c;
	case 9265ULL: goto x86_l_2431;
	case 9270ULL: goto x86_l_2436;
	case 9275ULL: goto x86_l_243b;
	case 9277ULL: goto x86_l_243d;
	case 9282ULL: goto x86_l_2442;
	case 9287ULL: goto x86_l_2447;
	case 9292ULL: goto x86_l_244c;
	case 9297ULL: goto x86_l_2451;
	case 9299ULL: goto x86_l_2453;
	case 9304ULL: goto x86_l_2458;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9323ULL: goto x86_l_246b;
	case 9328ULL: goto x86_l_2470;
	case 9333ULL: goto x86_l_2475;
	case 9335ULL: goto x86_l_2477;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9364ULL: goto x86_l_2494;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9374ULL: goto x86_l_249e;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9384ULL: goto x86_l_24a8;
	case 9386ULL: goto x86_l_24aa;
	case 9390ULL: goto x86_l_24ae;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9405ULL: goto x86_l_24bd;
	case 9407ULL: goto x86_l_24bf;
	case 9411ULL: goto x86_l_24c3;
	case 9413ULL: goto x86_l_24c5;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9425ULL: goto x86_l_24d1;
	case 9431ULL: goto x86_l_24d7;
	case 9436ULL: goto x86_l_24dc;
	case 9442ULL: goto x86_l_24e2;
	case 9447ULL: goto x86_l_24e7;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9457ULL: goto x86_l_24f1;
	case 9463ULL: goto x86_l_24f7;
	case 9467ULL: goto x86_l_24fb;
	case 9470ULL: goto x86_l_24fe;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9485ULL: goto x86_l_250d;
	case 9487ULL: goto x86_l_250f;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9498ULL: goto x86_l_251a;
	case 9501ULL: goto x86_l_251d;
	case 9507ULL: goto x86_l_2523;
	case 9512ULL: goto x86_l_2528;
	case 9517ULL: goto x86_l_252d;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9533ULL: goto x86_l_253d;
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
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9643ULL: goto x86_l_25ab;
	case 9648ULL: goto x86_l_25b0;
	case 9653ULL: goto x86_l_25b5;
	case 9658ULL: goto x86_l_25ba;
	case 9660ULL: goto x86_l_25bc;
	case 9665ULL: goto x86_l_25c1;
	case 9668ULL: goto x86_l_25c4;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9678ULL: goto x86_l_25ce;
	case 9680ULL: goto x86_l_25d0;
	case 9684ULL: goto x86_l_25d4;
	case 9689ULL: goto x86_l_25d9;
	case 9694ULL: goto x86_l_25de;
	case 9699ULL: goto x86_l_25e3;
	case 9701ULL: goto x86_l_25e5;
	case 9705ULL: goto x86_l_25e9;
	case 9707ULL: goto x86_l_25eb;
	case 9713ULL: goto x86_l_25f1;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9725ULL: goto x86_l_25fd;
	case 9730ULL: goto x86_l_2602;
	case 9736ULL: goto x86_l_2608;
	case 9741ULL: goto x86_l_260d;
	case 9746ULL: goto x86_l_2612;
	case 9748ULL: goto x86_l_2614;
	case 9751ULL: goto x86_l_2617;
	case 9757ULL: goto x86_l_261d;
	case 9761ULL: goto x86_l_2621;
	case 9764ULL: goto x86_l_2624;
	case 9770ULL: goto x86_l_262a;
	case 9775ULL: goto x86_l_262f;
	case 9779ULL: goto x86_l_2633;
	case 9781ULL: goto x86_l_2635;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9792ULL: goto x86_l_2640;
	case 9795ULL: goto x86_l_2643;
	case 9801ULL: goto x86_l_2649;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9831ULL: goto x86_l_2667;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9843ULL: goto x86_l_2673;
	case 9848ULL: goto x86_l_2678;
	case 9853ULL: goto x86_l_267d;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9865ULL: goto x86_l_2689;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9887ULL: goto x86_l_269f;
	case 9892ULL: goto x86_l_26a4;
	case 9896ULL: goto x86_l_26a8;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9911ULL: goto x86_l_26b7;
	case 9916ULL: goto x86_l_26bc;
	case 9921ULL: goto x86_l_26c1;
	case 9923ULL: goto x86_l_26c3;
	case 9928ULL: goto x86_l_26c8;
	case 9933ULL: goto x86_l_26cd;
	case 9937ULL: goto x86_l_26d1;
	case 9942ULL: goto x86_l_26d6;
	case 9947ULL: goto x86_l_26db;
	case 9952ULL: goto x86_l_26e0;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9962ULL: goto x86_l_26ea;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9972ULL: goto x86_l_26f4;
	case 9974ULL: goto x86_l_26f6;
	case 9978ULL: goto x86_l_26fa;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9995ULL: goto x86_l_270b;
	case 9999ULL: goto x86_l_270f;
	case 10001ULL: goto x86_l_2711;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10013ULL: goto x86_l_271d;
	case 10019ULL: goto x86_l_2723;
	case 10024ULL: goto x86_l_2728;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10045ULL: goto x86_l_273d;
	case 10051ULL: goto x86_l_2743;
	case 10055ULL: goto x86_l_2747;
	case 10058ULL: goto x86_l_274a;
	case 10064ULL: goto x86_l_2750;
	case 10069ULL: goto x86_l_2755;
	case 10073ULL: goto x86_l_2759;
	case 10075ULL: goto x86_l_275b;
	case 10079ULL: goto x86_l_275f;
	case 10084ULL: goto x86_l_2764;
	case 10086ULL: goto x86_l_2766;
	case 10089ULL: goto x86_l_2769;
	case 10095ULL: goto x86_l_276f;
	case 10100ULL: goto x86_l_2774;
	case 10105ULL: goto x86_l_2779;
	case 10111ULL: goto x86_l_277f;
	case 10116ULL: goto x86_l_2784;
	case 10121ULL: goto x86_l_2789;
	case 10125ULL: goto x86_l_278d;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10137ULL: goto x86_l_2799;
	case 10142ULL: goto x86_l_279e;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10157ULL: goto x86_l_27ad;
	case 10159ULL: goto x86_l_27af;
	case 10164ULL: goto x86_l_27b4;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10179ULL: goto x86_l_27c3;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10190ULL: goto x86_l_27ce;
	case 10195ULL: goto x86_l_27d3;
	case 10200ULL: goto x86_l_27d8;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10215ULL: goto x86_l_27e7;
	case 10217ULL: goto x86_l_27e9;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10231ULL: goto x86_l_27f7;
	case 10236ULL: goto x86_l_27fc;
	case 10241ULL: goto x86_l_2801;
	case 10246ULL: goto x86_l_2806;
	case 10248ULL: goto x86_l_2808;
	case 10253ULL: goto x86_l_280d;
	case 10256ULL: goto x86_l_2810;
	case 10258ULL: goto x86_l_2812;
	case 10263ULL: goto x86_l_2817;
	case 10266ULL: goto x86_l_281a;
	case 10268ULL: goto x86_l_281c;
	case 10272ULL: goto x86_l_2820;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10287ULL: goto x86_l_282f;
	case 10289ULL: goto x86_l_2831;
	case 10293ULL: goto x86_l_2835;
	case 10295ULL: goto x86_l_2837;
	case 10301ULL: goto x86_l_283d;
	case 10305ULL: goto x86_l_2841;
	case 10307ULL: goto x86_l_2843;
	case 10313ULL: goto x86_l_2849;
	case 10318ULL: goto x86_l_284e;
	case 10324ULL: goto x86_l_2854;
	case 10329ULL: goto x86_l_2859;
	case 10334ULL: goto x86_l_285e;
	case 10336ULL: goto x86_l_2860;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2207:
	/* 0x2207: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_220c:
	/* 0x220c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2210:
	/* 0x2210: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2215:
	/* 0x2215: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_221a:
	/* 0x221a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_221f:
	/* 0x221f: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2224:
	/* 0x2224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2226:
	/* 0x2226: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_222b:
	/* 0x222b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2230:
	/* 0x2230: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2234:
	/* 0x2234: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2239:
	/* 0x2239: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_223e:
	/* 0x223e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2243:
	/* 0x2243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2245:
	/* 0x2245: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_224a:
	/* 0x224a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_224d:
	/* 0x224d: je     228b <trace_vfs_utimes+0x228b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228b;
	}
x86_l_224f:
	/* 0x224f: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2254:
	/* 0x2254: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2257:
	/* 0x2257: je     228b <trace_vfs_utimes+0x228b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228b;
	}
x86_l_2259:
	/* 0x2259: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_225d:
	/* 0x225d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2262:
	/* 0x2262: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2267:
	/* 0x2267: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_226c:
	/* 0x226c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226e:
	/* 0x226e: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2272:
	/* 0x2272: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2274:
	/* 0x2274: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_227a:
	/* 0x227a: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227e:
	/* 0x227e: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2280:
	/* 0x2280: jae    22fa <trace_vfs_utimes+0x22fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22fa;
	}
x86_l_2282:
	/* 0x2282: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2286:
	/* 0x2286: jmp    1ebf <trace_vfs_utimes+0x1ebf> */
	return 7871ULL;
x86_l_228b:
	/* 0x228b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_228e:
	/* 0x228e: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2294:
	/* 0x2294: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2299:
	/* 0x2299: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_229e:
	/* 0x229e: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_22a4:
	/* 0x22a4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22a9:
	/* 0x22a9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ae:
	/* 0x22ae: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_22b2:
	/* 0x22b2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b7:
	/* 0x22b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22bc:
	/* 0x22bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22be:
	/* 0x22be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22c3:
	/* 0x22c3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c8:
	/* 0x22c8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22cd:
	/* 0x22cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d2:
	/* 0x22d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d4:
	/* 0x22d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_22d9:
	/* 0x22d9: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22de:
	/* 0x22de: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22e3:
	/* 0x22e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e8:
	/* 0x22e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ea:
	/* 0x22ea: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ef:
	/* 0x22ef: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_22f3:
	/* 0x22f3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22f8:
	/* 0x22f8: jmp    233b <trace_vfs_utimes+0x233b> */
	goto x86_l_233b;
x86_l_22fa:
	/* 0x22fa: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22ff:
	/* 0x22ff: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2305:
	/* 0x2305: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_230a:
	/* 0x230a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_230f:
	/* 0x230f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2311:
	/* 0x2311: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2314:
	/* 0x2314: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_231a:
	/* 0x231a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231e:
	/* 0x231e: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2321:
	/* 0x2321: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2327:
	/* 0x2327: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_232c:
	/* 0x232c: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2330:
	/* 0x2330: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2332:
	/* 0x2332: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2336:
	/* 0x2336: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_233b:
	/* 0x233b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2340:
	/* 0x2340: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2345:
	/* 0x2345: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_234a:
	/* 0x234a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_234f:
	/* 0x234f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2351:
	/* 0x2351: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2356:
	/* 0x2356: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_235b:
	/* 0x235b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_235f:
	/* 0x235f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2364:
	/* 0x2364: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2369:
	/* 0x2369: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_236e:
	/* 0x236e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2370:
	/* 0x2370: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2375:
	/* 0x2375: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2378:
	/* 0x2378: je     23f4 <trace_vfs_utimes+0x23f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f4;
	}
x86_l_237a:
	/* 0x237a: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_237f:
	/* 0x237f: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2382:
	/* 0x2382: je     23f4 <trace_vfs_utimes+0x23f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f4;
	}
x86_l_2384:
	/* 0x2384: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2388:
	/* 0x2388: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_238d:
	/* 0x238d: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2392:
	/* 0x2392: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2397:
	/* 0x2397: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2399:
	/* 0x2399: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_239d:
	/* 0x239d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_239f:
	/* 0x239f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_23a5:
	/* 0x23a5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a9:
	/* 0x23a9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23ab:
	/* 0x23ab: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2282;
	}
x86_l_23b1:
	/* 0x23b1: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23b6:
	/* 0x23b6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_23bc:
	/* 0x23bc: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_23c1:
	/* 0x23c1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_23c6:
	/* 0x23c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23c8:
	/* 0x23c8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23cb:
	/* 0x23cb: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_23d1:
	/* 0x23d1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d5:
	/* 0x23d5: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_23d8:
	/* 0x23d8: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_23de:
	/* 0x23de: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23e3:
	/* 0x23e3: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_23e7:
	/* 0x23e7: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23e9:
	/* 0x23e9: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ed:
	/* 0x23ed: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f2:
	/* 0x23f2: jmp    2461 <trace_vfs_utimes+0x2461> */
	goto x86_l_2461;
x86_l_23f4:
	/* 0x23f4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23f7:
	/* 0x23f7: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_23fd:
	/* 0x23fd: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2402:
	/* 0x2402: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2407:
	/* 0x2407: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_240d:
	/* 0x240d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2412:
	/* 0x2412: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2417:
	/* 0x2417: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_241b:
	/* 0x241b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2420:
	/* 0x2420: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2425:
	/* 0x2425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2427:
	/* 0x2427: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_242c:
	/* 0x242c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2431:
	/* 0x2431: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2436:
	/* 0x2436: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_243b:
	/* 0x243b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243d:
	/* 0x243d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2442:
	/* 0x2442: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2447:
	/* 0x2447: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_244c:
	/* 0x244c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2451:
	/* 0x2451: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2453:
	/* 0x2453: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2458:
	/* 0x2458: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_245c:
	/* 0x245c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2461:
	/* 0x2461: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2466:
	/* 0x2466: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_246b:
	/* 0x246b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2470:
	/* 0x2470: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2475:
	/* 0x2475: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2477:
	/* 0x2477: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_247c:
	/* 0x247c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2481:
	/* 0x2481: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2485:
	/* 0x2485: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_248a:
	/* 0x248a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_248f:
	/* 0x248f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2494:
	/* 0x2494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2496:
	/* 0x2496: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_249b:
	/* 0x249b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_249e:
	/* 0x249e: je     251a <trace_vfs_utimes+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_24a0:
	/* 0x24a0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24a5:
	/* 0x24a5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24a8:
	/* 0x24a8: je     251a <trace_vfs_utimes+0x251a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251a;
	}
x86_l_24aa:
	/* 0x24aa: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24ae:
	/* 0x24ae: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_24b3:
	/* 0x24b3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24b8:
	/* 0x24b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24bd:
	/* 0x24bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bf:
	/* 0x24bf: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_24c3:
	/* 0x24c3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_24c5:
	/* 0x24c5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_24cb:
	/* 0x24cb: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24cf:
	/* 0x24cf: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24d1:
	/* 0x24d1: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2282;
	}
x86_l_24d7:
	/* 0x24d7: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24dc:
	/* 0x24dc: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_24e2:
	/* 0x24e2: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_24e7:
	/* 0x24e7: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_24ec:
	/* 0x24ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ee:
	/* 0x24ee: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24f1:
	/* 0x24f1: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_24f7:
	/* 0x24f7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24fb:
	/* 0x24fb: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_24fe:
	/* 0x24fe: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2504:
	/* 0x2504: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2509:
	/* 0x2509: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_250d:
	/* 0x250d: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_250f:
	/* 0x250f: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2513:
	/* 0x2513: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2518:
	/* 0x2518: jmp    2587 <trace_vfs_utimes+0x2587> */
	goto x86_l_2587;
x86_l_251a:
	/* 0x251a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_251d:
	/* 0x251d: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2523:
	/* 0x2523: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2528:
	/* 0x2528: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_252d:
	/* 0x252d: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2533:
	/* 0x2533: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2538:
	/* 0x2538: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253d:
	/* 0x253d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2541:
	/* 0x2541: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
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
	/* 0x2557: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255c:
	/* 0x255c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2561:
	/* 0x2561: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2563:
	/* 0x2563: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2568:
	/* 0x2568: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_256d:
	/* 0x256d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2572:
	/* 0x2572: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2577:
	/* 0x2577: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2579:
	/* 0x2579: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_257e:
	/* 0x257e: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2582:
	/* 0x2582: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2587:
	/* 0x2587: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_258c:
	/* 0x258c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2591:
	/* 0x2591: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2596:
	/* 0x2596: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_259b:
	/* 0x259b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_259d:
	/* 0x259d: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25a2:
	/* 0x25a2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25a7:
	/* 0x25a7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_25ab:
	/* 0x25ab: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25b0:
	/* 0x25b0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25b5:
	/* 0x25b5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25ba:
	/* 0x25ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25bc:
	/* 0x25bc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c1:
	/* 0x25c1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25c4:
	/* 0x25c4: je     2640 <trace_vfs_utimes+0x2640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2640;
	}
x86_l_25c6:
	/* 0x25c6: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25cb:
	/* 0x25cb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_25ce:
	/* 0x25ce: je     2640 <trace_vfs_utimes+0x2640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2640;
	}
x86_l_25d0:
	/* 0x25d0: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_25d4:
	/* 0x25d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25d9:
	/* 0x25d9: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25de:
	/* 0x25de: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25e3:
	/* 0x25e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e5:
	/* 0x25e5: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_25e9:
	/* 0x25e9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_25eb:
	/* 0x25eb: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25f1:
	/* 0x25f1: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f5:
	/* 0x25f5: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25f7:
	/* 0x25f7: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2282;
	}
x86_l_25fd:
	/* 0x25fd: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2602:
	/* 0x2602: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2608:
	/* 0x2608: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_260d:
	/* 0x260d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2612:
	/* 0x2612: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2614:
	/* 0x2614: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2617:
	/* 0x2617: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_261d:
	/* 0x261d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2621:
	/* 0x2621: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2624:
	/* 0x2624: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_262a:
	/* 0x262a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_262f:
	/* 0x262f: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2633:
	/* 0x2633: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2635:
	/* 0x2635: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2639:
	/* 0x2639: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_263e:
	/* 0x263e: jmp    26ad <trace_vfs_utimes+0x26ad> */
	goto x86_l_26ad;
x86_l_2640:
	/* 0x2640: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2643:
	/* 0x2643: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2649:
	/* 0x2649: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_264e:
	/* 0x264e: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2653:
	/* 0x2653: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2659:
	/* 0x2659: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_265e:
	/* 0x265e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2663:
	/* 0x2663: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2667:
	/* 0x2667: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_266c:
	/* 0x266c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2671:
	/* 0x2671: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2673:
	/* 0x2673: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2678:
	/* 0x2678: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_267d:
	/* 0x267d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2682:
	/* 0x2682: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2687:
	/* 0x2687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2689:
	/* 0x2689: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_268e:
	/* 0x268e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2693:
	/* 0x2693: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2698:
	/* 0x2698: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_269d:
	/* 0x269d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269f:
	/* 0x269f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26a4:
	/* 0x26a4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26a8:
	/* 0x26a8: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26ad:
	/* 0x26ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26b2:
	/* 0x26b2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26b7:
	/* 0x26b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26bc:
	/* 0x26bc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26c1:
	/* 0x26c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c3:
	/* 0x26c3: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26c8:
	/* 0x26c8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26cd:
	/* 0x26cd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_26d1:
	/* 0x26d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26d6:
	/* 0x26d6: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26db:
	/* 0x26db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26e0:
	/* 0x26e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26e2:
	/* 0x26e2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e7:
	/* 0x26e7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_26ea:
	/* 0x26ea: je     2766 <trace_vfs_utimes+0x2766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2766;
	}
x86_l_26ec:
	/* 0x26ec: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26f1:
	/* 0x26f1: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_26f4:
	/* 0x26f4: je     2766 <trace_vfs_utimes+0x2766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2766;
	}
x86_l_26f6:
	/* 0x26f6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_26fa:
	/* 0x26fa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26ff:
	/* 0x26ff: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2704:
	/* 0x2704: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2709:
	/* 0x2709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270b:
	/* 0x270b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_270f:
	/* 0x270f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2711:
	/* 0x2711: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2717:
	/* 0x2717: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271b:
	/* 0x271b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_271d:
	/* 0x271d: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2282;
	}
x86_l_2723:
	/* 0x2723: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2728:
	/* 0x2728: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_272e:
	/* 0x272e: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2733:
	/* 0x2733: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2738:
	/* 0x2738: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_273a:
	/* 0x273a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_273d:
	/* 0x273d: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2743:
	/* 0x2743: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2747:
	/* 0x2747: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_274a:
	/* 0x274a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2750:
	/* 0x2750: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2755:
	/* 0x2755: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2759:
	/* 0x2759: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_275b:
	/* 0x275b: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_275f:
	/* 0x275f: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2764:
	/* 0x2764: jmp    27d3 <trace_vfs_utimes+0x27d3> */
	goto x86_l_27d3;
x86_l_2766:
	/* 0x2766: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2769:
	/* 0x2769: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_276f:
	/* 0x276f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2774:
	/* 0x2774: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2779:
	/* 0x2779: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_277f:
	/* 0x277f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2784:
	/* 0x2784: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2789:
	/* 0x2789: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_278d:
	/* 0x278d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2792:
	/* 0x2792: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2797:
	/* 0x2797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2799:
	/* 0x2799: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_279e:
	/* 0x279e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a3:
	/* 0x27a3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a8:
	/* 0x27a8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27ad:
	/* 0x27ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27af:
	/* 0x27af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27b4:
	/* 0x27b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b9:
	/* 0x27b9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27be:
	/* 0x27be: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27c3:
	/* 0x27c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27c5:
	/* 0x27c5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27ca:
	/* 0x27ca: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_27ce:
	/* 0x27ce: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27d3:
	/* 0x27d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27d8:
	/* 0x27d8: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27dd:
	/* 0x27dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_27e2:
	/* 0x27e2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27e7:
	/* 0x27e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e9:
	/* 0x27e9: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ee:
	/* 0x27ee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27f3:
	/* 0x27f3: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_27f7:
	/* 0x27f7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_27fc:
	/* 0x27fc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2801:
	/* 0x2801: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2806:
	/* 0x2806: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2808:
	/* 0x2808: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_280d:
	/* 0x280d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2810:
	/* 0x2810: je     288c <trace_vfs_utimes+0x288c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10380ULL;
	}
x86_l_2812:
	/* 0x2812: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2817:
	/* 0x2817: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_281a:
	/* 0x281a: je     288c <trace_vfs_utimes+0x288c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10380ULL;
	}
x86_l_281c:
	/* 0x281c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2820:
	/* 0x2820: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2825:
	/* 0x2825: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_282a:
	/* 0x282a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_282f:
	/* 0x282f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2831:
	/* 0x2831: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2835:
	/* 0x2835: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2837:
	/* 0x2837: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_283d:
	/* 0x283d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2841:
	/* 0x2841: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2843:
	/* 0x2843: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2282;
	}
x86_l_2849:
	/* 0x2849: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_284e:
	/* 0x284e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2854:
	/* 0x2854: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2859:
	/* 0x2859: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_285e:
	/* 0x285e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2860:
	/* 0x2860: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
	return 10339ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10339ULL: goto x86_l_2863;
	case 10345ULL: goto x86_l_2869;
	case 10349ULL: goto x86_l_286d;
	case 10352ULL: goto x86_l_2870;
	case 10358ULL: goto x86_l_2876;
	case 10363ULL: goto x86_l_287b;
	case 10367ULL: goto x86_l_287f;
	case 10369ULL: goto x86_l_2881;
	case 10373ULL: goto x86_l_2885;
	case 10378ULL: goto x86_l_288a;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10399ULL: goto x86_l_289f;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10415ULL: goto x86_l_28af;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10436ULL: goto x86_l_28c4;
	case 10441ULL: goto x86_l_28c9;
	case 10446ULL: goto x86_l_28ce;
	case 10451ULL: goto x86_l_28d3;
	case 10453ULL: goto x86_l_28d5;
	case 10458ULL: goto x86_l_28da;
	case 10463ULL: goto x86_l_28df;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10475ULL: goto x86_l_28eb;
	case 10480ULL: goto x86_l_28f0;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10499ULL: goto x86_l_2903;
	case 10504ULL: goto x86_l_2908;
	case 10509ULL: goto x86_l_290d;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10521ULL: goto x86_l_2919;
	case 10525ULL: goto x86_l_291d;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10540ULL: goto x86_l_292c;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10550ULL: goto x86_l_2936;
	case 10552ULL: goto x86_l_2938;
	case 10557ULL: goto x86_l_293d;
	case 10560ULL: goto x86_l_2940;
	case 10562ULL: goto x86_l_2942;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10576ULL: goto x86_l_2950;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10595ULL: goto x86_l_2963;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10618ULL: goto x86_l_297a;
	case 10623ULL: goto x86_l_297f;
	case 10628ULL: goto x86_l_2984;
	case 10630ULL: goto x86_l_2986;
	case 10633ULL: goto x86_l_2989;
	case 10639ULL: goto x86_l_298f;
	case 10643ULL: goto x86_l_2993;
	case 10646ULL: goto x86_l_2996;
	case 10652ULL: goto x86_l_299c;
	case 10657ULL: goto x86_l_29a1;
	case 10661ULL: goto x86_l_29a5;
	case 10663ULL: goto x86_l_29a7;
	case 10667ULL: goto x86_l_29ab;
	case 10672ULL: goto x86_l_29b0;
	case 10674ULL: goto x86_l_29b2;
	case 10677ULL: goto x86_l_29b5;
	case 10683ULL: goto x86_l_29bb;
	case 10688ULL: goto x86_l_29c0;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10704ULL: goto x86_l_29d0;
	case 10709ULL: goto x86_l_29d5;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10723ULL: goto x86_l_29e3;
	case 10725ULL: goto x86_l_29e5;
	case 10730ULL: goto x86_l_29ea;
	case 10735ULL: goto x86_l_29ef;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10747ULL: goto x86_l_29fb;
	case 10752ULL: goto x86_l_2a00;
	case 10757ULL: goto x86_l_2a05;
	case 10762ULL: goto x86_l_2a0a;
	case 10767ULL: goto x86_l_2a0f;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10778ULL: goto x86_l_2a1a;
	case 10783ULL: goto x86_l_2a1f;
	case 10788ULL: goto x86_l_2a24;
	case 10793ULL: goto x86_l_2a29;
	case 10798ULL: goto x86_l_2a2e;
	case 10803ULL: goto x86_l_2a33;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10819ULL: goto x86_l_2a43;
	case 10824ULL: goto x86_l_2a48;
	case 10829ULL: goto x86_l_2a4d;
	case 10834ULL: goto x86_l_2a52;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10844ULL: goto x86_l_2a5c;
	case 10846ULL: goto x86_l_2a5e;
	case 10851ULL: goto x86_l_2a63;
	case 10854ULL: goto x86_l_2a66;
	case 10856ULL: goto x86_l_2a68;
	case 10860ULL: goto x86_l_2a6c;
	case 10865ULL: goto x86_l_2a71;
	case 10870ULL: goto x86_l_2a76;
	case 10875ULL: goto x86_l_2a7b;
	case 10877ULL: goto x86_l_2a7d;
	case 10881ULL: goto x86_l_2a81;
	case 10883ULL: goto x86_l_2a83;
	case 10889ULL: goto x86_l_2a89;
	case 10893ULL: goto x86_l_2a8d;
	case 10895ULL: goto x86_l_2a8f;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10912ULL: goto x86_l_2aa0;
	case 10917ULL: goto x86_l_2aa5;
	case 10922ULL: goto x86_l_2aaa;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10933ULL: goto x86_l_2ab5;
	case 10937ULL: goto x86_l_2ab9;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10951ULL: goto x86_l_2ac7;
	case 10955ULL: goto x86_l_2acb;
	case 10957ULL: goto x86_l_2acd;
	case 10961ULL: goto x86_l_2ad1;
	case 10966ULL: goto x86_l_2ad6;
	case 10968ULL: goto x86_l_2ad8;
	case 10971ULL: goto x86_l_2adb;
	case 10977ULL: goto x86_l_2ae1;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11003ULL: goto x86_l_2afb;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11061ULL: goto x86_l_2b35;
	case 11063ULL: goto x86_l_2b37;
	case 11068ULL: goto x86_l_2b3c;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11082ULL: goto x86_l_2b4a;
	case 11087ULL: goto x86_l_2b4f;
	case 11092ULL: goto x86_l_2b54;
	case 11097ULL: goto x86_l_2b59;
	case 11099ULL: goto x86_l_2b5b;
	case 11104ULL: goto x86_l_2b60;
	case 11109ULL: goto x86_l_2b65;
	case 11113ULL: goto x86_l_2b69;
	case 11118ULL: goto x86_l_2b6e;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11138ULL: goto x86_l_2b82;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11148ULL: goto x86_l_2b8c;
	case 11150ULL: goto x86_l_2b8e;
	case 11154ULL: goto x86_l_2b92;
	case 11159ULL: goto x86_l_2b97;
	case 11164ULL: goto x86_l_2b9c;
	case 11169ULL: goto x86_l_2ba1;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11177ULL: goto x86_l_2ba9;
	case 11183ULL: goto x86_l_2baf;
	case 11187ULL: goto x86_l_2bb3;
	case 11189ULL: goto x86_l_2bb5;
	case 11195ULL: goto x86_l_2bbb;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11211ULL: goto x86_l_2bcb;
	case 11216ULL: goto x86_l_2bd0;
	case 11218ULL: goto x86_l_2bd2;
	case 11221ULL: goto x86_l_2bd5;
	case 11227ULL: goto x86_l_2bdb;
	case 11231ULL: goto x86_l_2bdf;
	case 11234ULL: goto x86_l_2be2;
	case 11240ULL: goto x86_l_2be8;
	case 11245ULL: goto x86_l_2bed;
	case 11249ULL: goto x86_l_2bf1;
	case 11251ULL: goto x86_l_2bf3;
	case 11255ULL: goto x86_l_2bf7;
	case 11260ULL: goto x86_l_2bfc;
	case 11262ULL: goto x86_l_2bfe;
	case 11265ULL: goto x86_l_2c01;
	case 11271ULL: goto x86_l_2c07;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11292ULL: goto x86_l_2c1c;
	case 11297ULL: goto x86_l_2c21;
	case 11301ULL: goto x86_l_2c25;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11313ULL: goto x86_l_2c31;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11335ULL: goto x86_l_2c47;
	case 11340ULL: goto x86_l_2c4c;
	case 11345ULL: goto x86_l_2c51;
	case 11350ULL: goto x86_l_2c56;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11366ULL: goto x86_l_2c66;
	case 11371ULL: goto x86_l_2c6b;
	case 11376ULL: goto x86_l_2c70;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11398ULL: goto x86_l_2c86;
	case 11403ULL: goto x86_l_2c8b;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11417ULL: goto x86_l_2c99;
	case 11422ULL: goto x86_l_2c9e;
	case 11424ULL: goto x86_l_2ca0;
	case 11429ULL: goto x86_l_2ca5;
	case 11432ULL: goto x86_l_2ca8;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11442ULL: goto x86_l_2cb2;
	case 11444ULL: goto x86_l_2cb4;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11465ULL: goto x86_l_2cc9;
	case 11469ULL: goto x86_l_2ccd;
	case 11471ULL: goto x86_l_2ccf;
	case 11477ULL: goto x86_l_2cd5;
	case 11481ULL: goto x86_l_2cd9;
	case 11483ULL: goto x86_l_2cdb;
	case 11489ULL: goto x86_l_2ce1;
	case 11494ULL: goto x86_l_2ce6;
	case 11500ULL: goto x86_l_2cec;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11515ULL: goto x86_l_2cfb;
	case 11521ULL: goto x86_l_2d01;
	case 11525ULL: goto x86_l_2d05;
	case 11528ULL: goto x86_l_2d08;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11545ULL: goto x86_l_2d19;
	case 11549ULL: goto x86_l_2d1d;
	case 11554ULL: goto x86_l_2d22;
	case 11556ULL: goto x86_l_2d24;
	case 11559ULL: goto x86_l_2d27;
	case 11565ULL: goto x86_l_2d2d;
	case 11570ULL: goto x86_l_2d32;
	case 11575ULL: goto x86_l_2d37;
	case 11581ULL: goto x86_l_2d3d;
	case 11586ULL: goto x86_l_2d42;
	case 11591ULL: goto x86_l_2d47;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11617ULL: goto x86_l_2d61;
	case 11622ULL: goto x86_l_2d66;
	case 11627ULL: goto x86_l_2d6b;
	case 11629ULL: goto x86_l_2d6d;
	case 11634ULL: goto x86_l_2d72;
	case 11639ULL: goto x86_l_2d77;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11651ULL: goto x86_l_2d83;
	case 11656ULL: goto x86_l_2d88;
	case 11660ULL: goto x86_l_2d8c;
	case 11665ULL: goto x86_l_2d91;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11680ULL: goto x86_l_2da0;
	case 11685ULL: goto x86_l_2da5;
	case 11687ULL: goto x86_l_2da7;
	case 11692ULL: goto x86_l_2dac;
	case 11697ULL: goto x86_l_2db1;
	case 11701ULL: goto x86_l_2db5;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11716ULL: goto x86_l_2dc4;
	case 11718ULL: goto x86_l_2dc6;
	case 11723ULL: goto x86_l_2dcb;
	case 11726ULL: goto x86_l_2dce;
	case 11728ULL: goto x86_l_2dd0;
	case 11733ULL: goto x86_l_2dd5;
	case 11736ULL: goto x86_l_2dd8;
	case 11738ULL: goto x86_l_2dda;
	case 11742ULL: goto x86_l_2dde;
	case 11747ULL: goto x86_l_2de3;
	case 11752ULL: goto x86_l_2de8;
	case 11757ULL: goto x86_l_2ded;
	case 11759ULL: goto x86_l_2def;
	case 11763ULL: goto x86_l_2df3;
	case 11765ULL: goto x86_l_2df5;
	case 11771ULL: goto x86_l_2dfb;
	case 11775ULL: goto x86_l_2dff;
	case 11777ULL: goto x86_l_2e01;
	case 11783ULL: goto x86_l_2e07;
	case 11788ULL: goto x86_l_2e0c;
	case 11794ULL: goto x86_l_2e12;
	case 11799ULL: goto x86_l_2e17;
	case 11804ULL: goto x86_l_2e1c;
	case 11806ULL: goto x86_l_2e1e;
	case 11809ULL: goto x86_l_2e21;
	case 11815ULL: goto x86_l_2e27;
	case 11819ULL: goto x86_l_2e2b;
	case 11822ULL: goto x86_l_2e2e;
	case 11828ULL: goto x86_l_2e34;
	case 11833ULL: goto x86_l_2e39;
	case 11837ULL: goto x86_l_2e3d;
	case 11839ULL: goto x86_l_2e3f;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11859ULL: goto x86_l_2e53;
	case 11864ULL: goto x86_l_2e58;
	case 11869ULL: goto x86_l_2e5d;
	case 11875ULL: goto x86_l_2e63;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11889ULL: goto x86_l_2e71;
	case 11894ULL: goto x86_l_2e76;
	case 11899ULL: goto x86_l_2e7b;
	case 11901ULL: goto x86_l_2e7d;
	case 11906ULL: goto x86_l_2e82;
	case 11911ULL: goto x86_l_2e87;
	case 11916ULL: goto x86_l_2e8c;
	case 11921ULL: goto x86_l_2e91;
	case 11923ULL: goto x86_l_2e93;
	case 11928ULL: goto x86_l_2e98;
	case 11933ULL: goto x86_l_2e9d;
	case 11938ULL: goto x86_l_2ea2;
	case 11943ULL: goto x86_l_2ea7;
	case 11945ULL: goto x86_l_2ea9;
	case 11950ULL: goto x86_l_2eae;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11969ULL: goto x86_l_2ec1;
	case 11974ULL: goto x86_l_2ec6;
	case 11979ULL: goto x86_l_2ecb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2863:
	/* 0x2863: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2869:
	/* 0x2869: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_286d:
	/* 0x286d: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2870:
	/* 0x2870: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2876:
	/* 0x2876: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_287b:
	/* 0x287b: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_287f:
	/* 0x287f: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2881:
	/* 0x2881: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2885:
	/* 0x2885: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_288a:
	/* 0x288a: jmp    28f9 <trace_vfs_utimes+0x28f9> */
	goto x86_l_28f9;
x86_l_288c:
	/* 0x288c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_288f:
	/* 0x288f: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2895:
	/* 0x2895: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_289a:
	/* 0x289a: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_289f:
	/* 0x289f: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_28a5:
	/* 0x28a5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28aa:
	/* 0x28aa: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28af:
	/* 0x28af: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_28b3:
	/* 0x28b3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28b8:
	/* 0x28b8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28bd:
	/* 0x28bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28bf:
	/* 0x28bf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28c4:
	/* 0x28c4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c9:
	/* 0x28c9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28ce:
	/* 0x28ce: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28d3:
	/* 0x28d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d5:
	/* 0x28d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28da:
	/* 0x28da: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28df:
	/* 0x28df: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28e4:
	/* 0x28e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_28e9:
	/* 0x28e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28eb:
	/* 0x28eb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28f0:
	/* 0x28f0: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_28f4:
	/* 0x28f4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28f9:
	/* 0x28f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_28fe:
	/* 0x28fe: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2903:
	/* 0x2903: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2908:
	/* 0x2908: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_290d:
	/* 0x290d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290f:
	/* 0x290f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2914:
	/* 0x2914: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2919:
	/* 0x2919: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_291d:
	/* 0x291d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2922:
	/* 0x2922: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2927:
	/* 0x2927: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_292c:
	/* 0x292c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292e:
	/* 0x292e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2933:
	/* 0x2933: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2936:
	/* 0x2936: je     29b2 <trace_vfs_utimes+0x29b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b2;
	}
x86_l_2938:
	/* 0x2938: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_293d:
	/* 0x293d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2940:
	/* 0x2940: je     29b2 <trace_vfs_utimes+0x29b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b2;
	}
x86_l_2942:
	/* 0x2942: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2946:
	/* 0x2946: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_294b:
	/* 0x294b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2950:
	/* 0x2950: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2955:
	/* 0x2955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2957:
	/* 0x2957: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_295b:
	/* 0x295b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_295d:
	/* 0x295d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2963:
	/* 0x2963: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2967:
	/* 0x2967: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2969:
	/* 0x2969: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_296f:
	/* 0x296f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2974:
	/* 0x2974: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_297a:
	/* 0x297a: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_297f:
	/* 0x297f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2984:
	/* 0x2984: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2986:
	/* 0x2986: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2989:
	/* 0x2989: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_298f:
	/* 0x298f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2993:
	/* 0x2993: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2996:
	/* 0x2996: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_299c:
	/* 0x299c: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29a1:
	/* 0x29a1: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_29a5:
	/* 0x29a5: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29a7:
	/* 0x29a7: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ab:
	/* 0x29ab: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b0:
	/* 0x29b0: jmp    2a1f <trace_vfs_utimes+0x2a1f> */
	goto x86_l_2a1f;
x86_l_29b2:
	/* 0x29b2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_29b5:
	/* 0x29b5: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_29bb:
	/* 0x29bb: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29c0:
	/* 0x29c0: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_29c5:
	/* 0x29c5: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_29cb:
	/* 0x29cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29d0:
	/* 0x29d0: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29d5:
	/* 0x29d5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_29d9:
	/* 0x29d9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29de:
	/* 0x29de: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29e3:
	/* 0x29e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e5:
	/* 0x29e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_29ea:
	/* 0x29ea: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29ef:
	/* 0x29ef: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29f4:
	/* 0x29f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29f9:
	/* 0x29f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29fb:
	/* 0x29fb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a00:
	/* 0x2a00: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a05:
	/* 0x2a05: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a0a:
	/* 0x2a0a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a0f:
	/* 0x2a0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a11:
	/* 0x2a11: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a16:
	/* 0x2a16: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a1a:
	/* 0x2a1a: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a24:
	/* 0x2a24: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a29:
	/* 0x2a29: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a33:
	/* 0x2a33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a35:
	/* 0x2a35: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a3a:
	/* 0x2a3a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3f:
	/* 0x2a3f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a43:
	/* 0x2a43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a48:
	/* 0x2a48: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a4d:
	/* 0x2a4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2a52:
	/* 0x2a52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a54:
	/* 0x2a54: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a59:
	/* 0x2a59: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2a5c:
	/* 0x2a5c: je     2ad8 <trace_vfs_utimes+0x2ad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ad8;
	}
x86_l_2a5e:
	/* 0x2a5e: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a63:
	/* 0x2a63: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2a66:
	/* 0x2a66: je     2ad8 <trace_vfs_utimes+0x2ad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ad8;
	}
x86_l_2a68:
	/* 0x2a68: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2a6c:
	/* 0x2a6c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2a71:
	/* 0x2a71: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a76:
	/* 0x2a76: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2a7b:
	/* 0x2a7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7d:
	/* 0x2a7d: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2a81:
	/* 0x2a81: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a83:
	/* 0x2a83: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2a89:
	/* 0x2a89: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a8d:
	/* 0x2a8d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a8f:
	/* 0x2a8f: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_2a95:
	/* 0x2a95: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a9a:
	/* 0x2a9a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2aa0:
	/* 0x2aa0: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2aaa:
	/* 0x2aaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aac:
	/* 0x2aac: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2aaf:
	/* 0x2aaf: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2ab5:
	/* 0x2ab5: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ab9:
	/* 0x2ab9: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2abc:
	/* 0x2abc: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2ac2:
	/* 0x2ac2: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2acb:
	/* 0x2acb: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2acd:
	/* 0x2acd: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad1:
	/* 0x2ad1: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ad6:
	/* 0x2ad6: jmp    2b45 <trace_vfs_utimes+0x2b45> */
	goto x86_l_2b45;
x86_l_2ad8:
	/* 0x2ad8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2adb:
	/* 0x2adb: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2ae1:
	/* 0x2ae1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae6:
	/* 0x2ae6: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2aeb:
	/* 0x2aeb: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2af1:
	/* 0x2af1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2af6:
	/* 0x2af6: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2afb:
	/* 0x2afb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2aff:
	/* 0x2aff: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b04:
	/* 0x2b04: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b09:
	/* 0x2b09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b0b:
	/* 0x2b0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b10:
	/* 0x2b10: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b15:
	/* 0x2b15: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b1f:
	/* 0x2b1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b21:
	/* 0x2b21: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b26:
	/* 0x2b26: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b2b:
	/* 0x2b2b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b30:
	/* 0x2b30: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b35:
	/* 0x2b35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b37:
	/* 0x2b37: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b3c:
	/* 0x2b3c: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b40:
	/* 0x2b40: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b45:
	/* 0x2b45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b4a:
	/* 0x2b4a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b54:
	/* 0x2b54: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b59:
	/* 0x2b59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5b:
	/* 0x2b5b: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b60:
	/* 0x2b60: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b65:
	/* 0x2b65: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b69:
	/* 0x2b69: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b6e:
	/* 0x2b6e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b73:
	/* 0x2b73: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b78:
	/* 0x2b78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7a:
	/* 0x2b7a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b7f:
	/* 0x2b7f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2b82:
	/* 0x2b82: je     2bfe <trace_vfs_utimes+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bfe;
	}
x86_l_2b84:
	/* 0x2b84: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b89:
	/* 0x2b89: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2b8c:
	/* 0x2b8c: je     2bfe <trace_vfs_utimes+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bfe;
	}
x86_l_2b8e:
	/* 0x2b8e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2b92:
	/* 0x2b92: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2b97:
	/* 0x2b97: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b9c:
	/* 0x2b9c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ba1:
	/* 0x2ba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ba3:
	/* 0x2ba3: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ba7:
	/* 0x2ba7: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ba9:
	/* 0x2ba9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2baf:
	/* 0x2baf: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb3:
	/* 0x2bb3: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bb5:
	/* 0x2bb5: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_2bbb:
	/* 0x2bbb: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bc0:
	/* 0x2bc0: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2bc6:
	/* 0x2bc6: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2bcb:
	/* 0x2bcb: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2bd0:
	/* 0x2bd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bd2:
	/* 0x2bd2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bd5:
	/* 0x2bd5: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2bdb:
	/* 0x2bdb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bdf:
	/* 0x2bdf: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2be2:
	/* 0x2be2: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2be8:
	/* 0x2be8: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bed:
	/* 0x2bed: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2bf1:
	/* 0x2bf1: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bf3:
	/* 0x2bf3: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf7:
	/* 0x2bf7: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bfc:
	/* 0x2bfc: jmp    2c6b <trace_vfs_utimes+0x2c6b> */
	goto x86_l_2c6b;
x86_l_2bfe:
	/* 0x2bfe: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c01:
	/* 0x2c01: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2c07:
	/* 0x2c07: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c0c:
	/* 0x2c0c: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2c11:
	/* 0x2c11: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2c17:
	/* 0x2c17: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c1c:
	/* 0x2c1c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c21:
	/* 0x2c21: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c25:
	/* 0x2c25: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c2a:
	/* 0x2c2a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c2f:
	/* 0x2c2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c31:
	/* 0x2c31: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c36:
	/* 0x2c36: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c3b:
	/* 0x2c3b: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c40:
	/* 0x2c40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c45:
	/* 0x2c45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c47:
	/* 0x2c47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c51:
	/* 0x2c51: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c56:
	/* 0x2c56: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c5b:
	/* 0x2c5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5d:
	/* 0x2c5d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c62:
	/* 0x2c62: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2c66:
	/* 0x2c66: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c6b:
	/* 0x2c6b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c70:
	/* 0x2c70: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c75:
	/* 0x2c75: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c7a:
	/* 0x2c7a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c7f:
	/* 0x2c7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c81:
	/* 0x2c81: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c86:
	/* 0x2c86: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c8b:
	/* 0x2c8b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c94:
	/* 0x2c94: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c99:
	/* 0x2c99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c9e:
	/* 0x2c9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ca0:
	/* 0x2ca0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ca5:
	/* 0x2ca5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ca8:
	/* 0x2ca8: je     2d24 <trace_vfs_utimes+0x2d24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d24;
	}
x86_l_2caa:
	/* 0x2caa: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2caf:
	/* 0x2caf: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2cb2:
	/* 0x2cb2: je     2d24 <trace_vfs_utimes+0x2d24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d24;
	}
x86_l_2cb4:
	/* 0x2cb4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2cb8:
	/* 0x2cb8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2cbd:
	/* 0x2cbd: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2cc7:
	/* 0x2cc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cc9:
	/* 0x2cc9: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ccd:
	/* 0x2ccd: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ccf:
	/* 0x2ccf: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2cd5:
	/* 0x2cd5: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd9:
	/* 0x2cd9: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2cdb:
	/* 0x2cdb: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_2ce1:
	/* 0x2ce1: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ce6:
	/* 0x2ce6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2cec:
	/* 0x2cec: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2cf1:
	/* 0x2cf1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2cf6:
	/* 0x2cf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cf8:
	/* 0x2cf8: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2cfb:
	/* 0x2cfb: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2d01:
	/* 0x2d01: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d05:
	/* 0x2d05: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2d08:
	/* 0x2d08: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2d0e:
	/* 0x2d0e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d13:
	/* 0x2d13: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2d17:
	/* 0x2d17: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d19:
	/* 0x2d19: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d1d:
	/* 0x2d1d: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d22:
	/* 0x2d22: jmp    2d91 <trace_vfs_utimes+0x2d91> */
	goto x86_l_2d91;
x86_l_2d24:
	/* 0x2d24: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2d27:
	/* 0x2d27: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2d2d:
	/* 0x2d2d: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d32:
	/* 0x2d32: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2d37:
	/* 0x2d37: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2d3d:
	/* 0x2d3d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d42:
	/* 0x2d42: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d47:
	/* 0x2d47: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2d4b:
	/* 0x2d4b: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d50:
	/* 0x2d50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d55:
	/* 0x2d55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d57:
	/* 0x2d57: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d61:
	/* 0x2d61: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d66:
	/* 0x2d66: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d6b:
	/* 0x2d6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6d:
	/* 0x2d6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d72:
	/* 0x2d72: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d77:
	/* 0x2d77: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d81:
	/* 0x2d81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d83:
	/* 0x2d83: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d88:
	/* 0x2d88: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2d8c:
	/* 0x2d8c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d91:
	/* 0x2d91: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2d96:
	/* 0x2d96: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d9b:
	/* 0x2d9b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2da0:
	/* 0x2da0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2da5:
	/* 0x2da5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da7:
	/* 0x2da7: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dac:
	/* 0x2dac: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2db1:
	/* 0x2db1: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2db5:
	/* 0x2db5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2dba:
	/* 0x2dba: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2dc4:
	/* 0x2dc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dc6:
	/* 0x2dc6: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dcb:
	/* 0x2dcb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2dce:
	/* 0x2dce: je     2e4a <trace_vfs_utimes+0x2e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4a;
	}
x86_l_2dd0:
	/* 0x2dd0: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dd5:
	/* 0x2dd5: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2dd8:
	/* 0x2dd8: je     2e4a <trace_vfs_utimes+0x2e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e4a;
	}
x86_l_2dda:
	/* 0x2dda: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2dde:
	/* 0x2dde: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2de3:
	/* 0x2de3: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2de8:
	/* 0x2de8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2ded:
	/* 0x2ded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2def:
	/* 0x2def: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2df3:
	/* 0x2df3: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2df5:
	/* 0x2df5: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2dfb:
	/* 0x2dfb: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dff:
	/* 0x2dff: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e01:
	/* 0x2e01: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_2e07:
	/* 0x2e07: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e0c:
	/* 0x2e0c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2e12:
	/* 0x2e12: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2e17:
	/* 0x2e17: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2e1c:
	/* 0x2e1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e1e:
	/* 0x2e1e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e21:
	/* 0x2e21: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2e27:
	/* 0x2e27: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2b:
	/* 0x2e2b: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2e2e:
	/* 0x2e2e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2e34:
	/* 0x2e34: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e39:
	/* 0x2e39: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2e3d:
	/* 0x2e3d: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e3f:
	/* 0x2e3f: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e43:
	/* 0x2e43: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e48:
	/* 0x2e48: jmp    2eb7 <trace_vfs_utimes+0x2eb7> */
	goto x86_l_2eb7;
x86_l_2e4a:
	/* 0x2e4a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2e4d:
	/* 0x2e4d: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2e53:
	/* 0x2e53: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e58:
	/* 0x2e58: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2e5d:
	/* 0x2e5d: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2e63:
	/* 0x2e63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e68:
	/* 0x2e68: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6d:
	/* 0x2e6d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2e71:
	/* 0x2e71: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e76:
	/* 0x2e76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e7b:
	/* 0x2e7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7d:
	/* 0x2e7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e82:
	/* 0x2e82: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e87:
	/* 0x2e87: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e8c:
	/* 0x2e8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2e91:
	/* 0x2e91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e93:
	/* 0x2e93: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2e98:
	/* 0x2e98: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9d:
	/* 0x2e9d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ea2:
	/* 0x2ea2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea7:
	/* 0x2ea7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea9:
	/* 0x2ea9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2eae:
	/* 0x2eae: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eb7:
	/* 0x2eb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ebc:
	/* 0x2ebc: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ec6:
	/* 0x2ec6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ecb:
	/* 0x2ecb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 11981ULL;
}

static __noinline __u64 tracee_trace_vfs_utimes_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11981ULL: goto x86_l_2ecd;
	case 11986ULL: goto x86_l_2ed2;
	case 11991ULL: goto x86_l_2ed7;
	case 11995ULL: goto x86_l_2edb;
	case 12000ULL: goto x86_l_2ee0;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12012ULL: goto x86_l_2eec;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12022ULL: goto x86_l_2ef6;
	case 12027ULL: goto x86_l_2efb;
	case 12030ULL: goto x86_l_2efe;
	case 12032ULL: goto x86_l_2f00;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12046ULL: goto x86_l_2f0e;
	case 12051ULL: goto x86_l_2f13;
	case 12053ULL: goto x86_l_2f15;
	case 12057ULL: goto x86_l_2f19;
	case 12059ULL: goto x86_l_2f1b;
	case 12065ULL: goto x86_l_2f21;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12077ULL: goto x86_l_2f2d;
	case 12082ULL: goto x86_l_2f32;
	case 12088ULL: goto x86_l_2f38;
	case 12093ULL: goto x86_l_2f3d;
	case 12098ULL: goto x86_l_2f42;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12109ULL: goto x86_l_2f4d;
	case 12113ULL: goto x86_l_2f51;
	case 12116ULL: goto x86_l_2f54;
	case 12122ULL: goto x86_l_2f5a;
	case 12127ULL: goto x86_l_2f5f;
	case 12131ULL: goto x86_l_2f63;
	case 12133ULL: goto x86_l_2f65;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12144ULL: goto x86_l_2f70;
	case 12147ULL: goto x86_l_2f73;
	case 12153ULL: goto x86_l_2f79;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12169ULL: goto x86_l_2f89;
	case 12174ULL: goto x86_l_2f8e;
	case 12179ULL: goto x86_l_2f93;
	case 12183ULL: goto x86_l_2f97;
	case 12188ULL: goto x86_l_2f9c;
	case 12193ULL: goto x86_l_2fa1;
	case 12195ULL: goto x86_l_2fa3;
	case 12200ULL: goto x86_l_2fa8;
	case 12205ULL: goto x86_l_2fad;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12217ULL: goto x86_l_2fb9;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12237ULL: goto x86_l_2fcd;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12248ULL: goto x86_l_2fd8;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12263ULL: goto x86_l_2fe7;
	case 12268ULL: goto x86_l_2fec;
	case 12273ULL: goto x86_l_2ff1;
	case 12275ULL: goto x86_l_2ff3;
	case 12280ULL: goto x86_l_2ff8;
	case 12285ULL: goto x86_l_2ffd;
	case 12289ULL: goto x86_l_3001;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12304ULL: goto x86_l_3010;
	case 12306ULL: goto x86_l_3012;
	case 12311ULL: goto x86_l_3017;
	case 12314ULL: goto x86_l_301a;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12324ULL: goto x86_l_3024;
	case 12326ULL: goto x86_l_3026;
	case 12330ULL: goto x86_l_302a;
	case 12335ULL: goto x86_l_302f;
	case 12340ULL: goto x86_l_3034;
	case 12345ULL: goto x86_l_3039;
	case 12347ULL: goto x86_l_303b;
	case 12351ULL: goto x86_l_303f;
	case 12353ULL: goto x86_l_3041;
	case 12359ULL: goto x86_l_3047;
	case 12363ULL: goto x86_l_304b;
	case 12365ULL: goto x86_l_304d;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12382ULL: goto x86_l_305e;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12397ULL: goto x86_l_306d;
	case 12403ULL: goto x86_l_3073;
	case 12407ULL: goto x86_l_3077;
	case 12410ULL: goto x86_l_307a;
	case 12416ULL: goto x86_l_3080;
	case 12421ULL: goto x86_l_3085;
	case 12425ULL: goto x86_l_3089;
	case 12427ULL: goto x86_l_308b;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12438ULL: goto x86_l_3096;
	case 12441ULL: goto x86_l_3099;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12473ULL: goto x86_l_30b9;
	case 12477ULL: goto x86_l_30bd;
	case 12482ULL: goto x86_l_30c2;
	case 12487ULL: goto x86_l_30c7;
	case 12489ULL: goto x86_l_30c9;
	case 12494ULL: goto x86_l_30ce;
	case 12499ULL: goto x86_l_30d3;
	case 12504ULL: goto x86_l_30d8;
	case 12509ULL: goto x86_l_30dd;
	case 12511ULL: goto x86_l_30df;
	case 12516ULL: goto x86_l_30e4;
	case 12521ULL: goto x86_l_30e9;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12533ULL: goto x86_l_30f5;
	case 12538ULL: goto x86_l_30fa;
	case 12542ULL: goto x86_l_30fe;
	case 12547ULL: goto x86_l_3103;
	case 12552ULL: goto x86_l_3108;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12567ULL: goto x86_l_3117;
	case 12569ULL: goto x86_l_3119;
	case 12574ULL: goto x86_l_311e;
	case 12579ULL: goto x86_l_3123;
	case 12583ULL: goto x86_l_3127;
	case 12588ULL: goto x86_l_312c;
	case 12593ULL: goto x86_l_3131;
	case 12598ULL: goto x86_l_3136;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12608ULL: goto x86_l_3140;
	case 12610ULL: goto x86_l_3142;
	case 12615ULL: goto x86_l_3147;
	case 12618ULL: goto x86_l_314a;
	case 12620ULL: goto x86_l_314c;
	case 12624ULL: goto x86_l_3150;
	case 12629ULL: goto x86_l_3155;
	case 12634ULL: goto x86_l_315a;
	case 12639ULL: goto x86_l_315f;
	case 12641ULL: goto x86_l_3161;
	case 12645ULL: goto x86_l_3165;
	case 12647ULL: goto x86_l_3167;
	case 12653ULL: goto x86_l_316d;
	case 12657ULL: goto x86_l_3171;
	case 12659ULL: goto x86_l_3173;
	case 12665ULL: goto x86_l_3179;
	case 12670ULL: goto x86_l_317e;
	case 12676ULL: goto x86_l_3184;
	case 12681ULL: goto x86_l_3189;
	case 12686ULL: goto x86_l_318e;
	case 12688ULL: goto x86_l_3190;
	case 12691ULL: goto x86_l_3193;
	case 12697ULL: goto x86_l_3199;
	case 12701ULL: goto x86_l_319d;
	case 12704ULL: goto x86_l_31a0;
	case 12710ULL: goto x86_l_31a6;
	case 12715ULL: goto x86_l_31ab;
	case 12719ULL: goto x86_l_31af;
	case 12721ULL: goto x86_l_31b1;
	case 12725ULL: goto x86_l_31b5;
	case 12730ULL: goto x86_l_31ba;
	case 12732ULL: goto x86_l_31bc;
	case 12735ULL: goto x86_l_31bf;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12751ULL: goto x86_l_31cf;
	case 12757ULL: goto x86_l_31d5;
	case 12762ULL: goto x86_l_31da;
	case 12767ULL: goto x86_l_31df;
	case 12771ULL: goto x86_l_31e3;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12783ULL: goto x86_l_31ef;
	case 12788ULL: goto x86_l_31f4;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12803ULL: goto x86_l_3203;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12815ULL: goto x86_l_320f;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12827ULL: goto x86_l_321b;
	case 12832ULL: goto x86_l_3220;
	case 12836ULL: goto x86_l_3224;
	case 12841ULL: goto x86_l_3229;
	case 12846ULL: goto x86_l_322e;
	case 12851ULL: goto x86_l_3233;
	case 12856ULL: goto x86_l_3238;
	case 12861ULL: goto x86_l_323d;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12873ULL: goto x86_l_3249;
	case 12877ULL: goto x86_l_324d;
	case 12882ULL: goto x86_l_3252;
	case 12887ULL: goto x86_l_3257;
	case 12892ULL: goto x86_l_325c;
	case 12894ULL: goto x86_l_325e;
	case 12899ULL: goto x86_l_3263;
	case 12902ULL: goto x86_l_3266;
	case 12904ULL: goto x86_l_3268;
	case 12909ULL: goto x86_l_326d;
	case 12912ULL: goto x86_l_3270;
	case 12914ULL: goto x86_l_3272;
	case 12918ULL: goto x86_l_3276;
	case 12923ULL: goto x86_l_327b;
	case 12928ULL: goto x86_l_3280;
	case 12933ULL: goto x86_l_3285;
	case 12935ULL: goto x86_l_3287;
	case 12939ULL: goto x86_l_328b;
	case 12941ULL: goto x86_l_328d;
	case 12947ULL: goto x86_l_3293;
	case 12951ULL: goto x86_l_3297;
	case 12953ULL: goto x86_l_3299;
	case 12959ULL: goto x86_l_329f;
	case 12964ULL: goto x86_l_32a4;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12982ULL: goto x86_l_32b6;
	case 12985ULL: goto x86_l_32b9;
	case 12991ULL: goto x86_l_32bf;
	case 12995ULL: goto x86_l_32c3;
	case 12999ULL: goto x86_l_32c7;
	case 13005ULL: goto x86_l_32cd;
	case 13010ULL: goto x86_l_32d2;
	case 13014ULL: goto x86_l_32d6;
	case 13017ULL: goto x86_l_32d9;
	case 13022ULL: goto x86_l_32de;
	case 13027ULL: goto x86_l_32e3;
	case 13030ULL: goto x86_l_32e6;
	case 13036ULL: goto x86_l_32ec;
	case 13041ULL: goto x86_l_32f1;
	case 13046ULL: goto x86_l_32f6;
	case 13052ULL: goto x86_l_32fc;
	case 13057ULL: goto x86_l_3301;
	case 13062ULL: goto x86_l_3306;
	case 13066ULL: goto x86_l_330a;
	case 13071ULL: goto x86_l_330f;
	case 13076ULL: goto x86_l_3314;
	case 13078ULL: goto x86_l_3316;
	case 13083ULL: goto x86_l_331b;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13098ULL: goto x86_l_332a;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13115ULL: goto x86_l_333b;
	case 13120ULL: goto x86_l_3340;
	case 13122ULL: goto x86_l_3342;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2ecd:
	/* 0x2ecd: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ed2:
	/* 0x2ed2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed7:
	/* 0x2ed7: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2edb:
	/* 0x2edb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ee0:
	/* 0x2ee0: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2eea:
	/* 0x2eea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eec:
	/* 0x2eec: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef1:
	/* 0x2ef1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2ef4:
	/* 0x2ef4: je     2f70 <trace_vfs_utimes+0x2f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f70;
	}
x86_l_2ef6:
	/* 0x2ef6: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2efb:
	/* 0x2efb: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2efe:
	/* 0x2efe: je     2f70 <trace_vfs_utimes+0x2f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f70;
	}
x86_l_2f00:
	/* 0x2f00: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2f04:
	/* 0x2f04: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f09:
	/* 0x2f09: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f0e:
	/* 0x2f0e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2f13:
	/* 0x2f13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f15:
	/* 0x2f15: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2f19:
	/* 0x2f19: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f1b:
	/* 0x2f1b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2f21:
	/* 0x2f21: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f25:
	/* 0x2f25: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f27:
	/* 0x2f27: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_2f2d:
	/* 0x2f2d: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f32:
	/* 0x2f32: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2f38:
	/* 0x2f38: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2f3d:
	/* 0x2f3d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_2f42:
	/* 0x2f42: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f44:
	/* 0x2f44: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f47:
	/* 0x2f47: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_2f4d:
	/* 0x2f4d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f51:
	/* 0x2f51: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2f54:
	/* 0x2f54: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_2f5a:
	/* 0x2f5a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_2f63:
	/* 0x2f63: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f65:
	/* 0x2f65: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f69:
	/* 0x2f69: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6e:
	/* 0x2f6e: jmp    2fdd <trace_vfs_utimes+0x2fdd> */
	goto x86_l_2fdd;
x86_l_2f70:
	/* 0x2f70: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2f73:
	/* 0x2f73: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_2f79:
	/* 0x2f79: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7e:
	/* 0x2f7e: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_2f83:
	/* 0x2f83: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_2f89:
	/* 0x2f89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f8e:
	/* 0x2f8e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f93:
	/* 0x2f93: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2f97:
	/* 0x2f97: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f9c:
	/* 0x2f9c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fa1:
	/* 0x2fa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fa3:
	/* 0x2fa3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fa8:
	/* 0x2fa8: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fad:
	/* 0x2fad: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fb7:
	/* 0x2fb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb9:
	/* 0x2fb9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fbe:
	/* 0x2fbe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fc3:
	/* 0x2fc3: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fc8:
	/* 0x2fc8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fcd:
	/* 0x2fcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fcf:
	/* 0x2fcf: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd4:
	/* 0x2fd4: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2fd8:
	/* 0x2fd8: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fdd:
	/* 0x2fdd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fe2:
	/* 0x2fe2: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fe7:
	/* 0x2fe7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2fec:
	/* 0x2fec: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff1:
	/* 0x2ff1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ff3:
	/* 0x2ff3: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ff8:
	/* 0x2ff8: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ffd:
	/* 0x2ffd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3001:
	/* 0x3001: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3006:
	/* 0x3006: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_300b:
	/* 0x300b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3010:
	/* 0x3010: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3012:
	/* 0x3012: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3017:
	/* 0x3017: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_301a:
	/* 0x301a: je     3096 <trace_vfs_utimes+0x3096> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3096;
	}
x86_l_301c:
	/* 0x301c: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3021:
	/* 0x3021: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3024:
	/* 0x3024: je     3096 <trace_vfs_utimes+0x3096> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3096;
	}
x86_l_3026:
	/* 0x3026: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_302a:
	/* 0x302a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_302f:
	/* 0x302f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3034:
	/* 0x3034: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3039:
	/* 0x3039: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_303b:
	/* 0x303b: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_303f:
	/* 0x303f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3041:
	/* 0x3041: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3047:
	/* 0x3047: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304b:
	/* 0x304b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_304d:
	/* 0x304d: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_3053:
	/* 0x3053: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3058:
	/* 0x3058: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_305e:
	/* 0x305e: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3063:
	/* 0x3063: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_3068:
	/* 0x3068: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_306a:
	/* 0x306a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_306d:
	/* 0x306d: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_3073:
	/* 0x3073: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3077:
	/* 0x3077: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_307a:
	/* 0x307a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_3080:
	/* 0x3080: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3085:
	/* 0x3085: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_3089:
	/* 0x3089: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_308b:
	/* 0x308b: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_308f:
	/* 0x308f: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3094:
	/* 0x3094: jmp    3103 <trace_vfs_utimes+0x3103> */
	goto x86_l_3103;
x86_l_3096:
	/* 0x3096: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3099:
	/* 0x3099: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_309f:
	/* 0x309f: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30a4:
	/* 0x30a4: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_30a9:
	/* 0x30a9: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_30af:
	/* 0x30af: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30b4:
	/* 0x30b4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30b9:
	/* 0x30b9: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_30bd:
	/* 0x30bd: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c2:
	/* 0x30c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30c7:
	/* 0x30c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c9:
	/* 0x30c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30ce:
	/* 0x30ce: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30d3:
	/* 0x30d3: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30d8:
	/* 0x30d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30dd:
	/* 0x30dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30df:
	/* 0x30df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30e4:
	/* 0x30e4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30e9:
	/* 0x30e9: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30ee:
	/* 0x30ee: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_30f3:
	/* 0x30f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f5:
	/* 0x30f5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_30fa:
	/* 0x30fa: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_30fe:
	/* 0x30fe: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3103:
	/* 0x3103: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3108:
	/* 0x3108: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_310d:
	/* 0x310d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3112:
	/* 0x3112: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3117:
	/* 0x3117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3119:
	/* 0x3119: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_311e:
	/* 0x311e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3123:
	/* 0x3123: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3127:
	/* 0x3127: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_312c:
	/* 0x312c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3131:
	/* 0x3131: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3136:
	/* 0x3136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3138:
	/* 0x3138: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_313d:
	/* 0x313d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3140:
	/* 0x3140: je     31bc <trace_vfs_utimes+0x31bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31bc;
	}
x86_l_3142:
	/* 0x3142: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3147:
	/* 0x3147: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_314a:
	/* 0x314a: je     31bc <trace_vfs_utimes+0x31bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31bc;
	}
x86_l_314c:
	/* 0x314c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3150:
	/* 0x3150: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3155:
	/* 0x3155: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_315a:
	/* 0x315a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_315f:
	/* 0x315f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3161:
	/* 0x3161: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3165:
	/* 0x3165: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3167:
	/* 0x3167: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_316d:
	/* 0x316d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3171:
	/* 0x3171: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3173:
	/* 0x3173: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_3179:
	/* 0x3179: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_317e:
	/* 0x317e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_3184:
	/* 0x3184: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3189:
	/* 0x3189: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_318e:
	/* 0x318e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3190:
	/* 0x3190: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3193:
	/* 0x3193: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_3199:
	/* 0x3199: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_319d:
	/* 0x319d: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_31a0:
	/* 0x31a0: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_31a6:
	/* 0x31a6: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31ab:
	/* 0x31ab: mov    BYTE PTR [rsi+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_31af:
	/* 0x31af: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31b1:
	/* 0x31b1: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31b5:
	/* 0x31b5: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ba:
	/* 0x31ba: jmp    3229 <trace_vfs_utimes+0x3229> */
	goto x86_l_3229;
x86_l_31bc:
	/* 0x31bc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_31bf:
	/* 0x31bf: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_31c5:
	/* 0x31c5: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31ca:
	/* 0x31ca: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_31cf:
	/* 0x31cf: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_31d5:
	/* 0x31d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31da:
	/* 0x31da: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31df:
	/* 0x31df: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31e3:
	/* 0x31e3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e8:
	/* 0x31e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31ed:
	/* 0x31ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31ef:
	/* 0x31ef: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_31f4:
	/* 0x31f4: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31f9:
	/* 0x31f9: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31fe:
	/* 0x31fe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3203:
	/* 0x3203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3205:
	/* 0x3205: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_320a:
	/* 0x320a: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_320f:
	/* 0x320f: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3214:
	/* 0x3214: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3219:
	/* 0x3219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321b:
	/* 0x321b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3220:
	/* 0x3220: add    rax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3224:
	/* 0x3224: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3229:
	/* 0x3229: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_322e:
	/* 0x322e: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3233:
	/* 0x3233: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3238:
	/* 0x3238: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_323d:
	/* 0x323d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323f:
	/* 0x323f: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3244:
	/* 0x3244: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3249:
	/* 0x3249: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_324d:
	/* 0x324d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3252:
	/* 0x3252: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3257:
	/* 0x3257: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_325c:
	/* 0x325c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325e:
	/* 0x325e: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3263:
	/* 0x3263: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3266:
	/* 0x3266: je     32e3 <trace_vfs_utimes+0x32e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e3;
	}
x86_l_3268:
	/* 0x3268: mov    r12,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_326d:
	/* 0x326d: cmp    rdx,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3270:
	/* 0x3270: je     32e3 <trace_vfs_utimes+0x32e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32e3;
	}
x86_l_3272:
	/* 0x3272: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_3276:
	/* 0x3276: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_327b:
	/* 0x327b: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3280:
	/* 0x3280: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3285:
	/* 0x3285: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3287:
	/* 0x3287: mov    esi,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_328b:
	/* 0x328b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_328d:
	/* 0x328d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_3293:
	/* 0x3293: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3297:
	/* 0x3297: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3299:
	/* 0x3299: jb     2282 <trace_vfs_utimes+0x2282> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8834ULL;
	}
x86_l_329f:
	/* 0x329f: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32a4:
	/* 0x32a4: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_32aa:
	/* 0x32aa: add    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_32af:
	/* 0x32af: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_32b4:
	/* 0x32b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b6:
	/* 0x32b6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32b9:
	/* 0x32b9: jl     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5640ULL;
	}
x86_l_32bf:
	/* 0x32bf: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32c3:
	/* 0x32c3: lea    ecx,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_32c7:
	/* 0x32c7: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_32cd:
	/* 0x32cd: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32d2:
	/* 0x32d2: mov    BYTE PTR [rdx+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_32d6:
	/* 0x32d6: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_32d9:
	/* 0x32d9: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32de:
	/* 0x32de: jmp    160c <trace_vfs_utimes+0x160c> */
	return 5644ULL;
x86_l_32e3:
	/* 0x32e3: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_32e6:
	/* 0x32e6: jne    1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5640ULL;
	}
x86_l_32ec:
	/* 0x32ec: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f1:
	/* 0x32f1: cmp    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_32f6:
	/* 0x32f6: je     1608 <trace_vfs_utimes+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5640ULL;
	}
x86_l_32fc:
	/* 0x32fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3301:
	/* 0x3301: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3306:
	/* 0x3306: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_330a:
	/* 0x330a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_330f:
	/* 0x330f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3314:
	/* 0x3314: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3316:
	/* 0x3316: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_331b:
	/* 0x331b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3320:
	/* 0x3320: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3325:
	/* 0x3325: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_332a:
	/* 0x332a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332c:
	/* 0x332c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_3331:
	/* 0x3331: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3336:
	/* 0x3336: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_333b:
	/* 0x333b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3340:
	/* 0x3340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3342:
	/* 0x3342: jmp    1608 <trace_vfs_utimes+0x1608> */
	return 5640ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_vfs_utimes_x86_sim_xdp(struct xdp_md *ctx)
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
		if (__x86_pc >= 0ULL && __x86_pc <= 2117ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2120ULL && __x86_pc <= 3760ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3765ULL && __x86_pc <= 5338ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5343ULL && __x86_pc <= 7051ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7056ULL && __x86_pc <= 8709ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8711ULL && __x86_pc <= 10336ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10339ULL && __x86_pc <= 11979ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11981ULL && __x86_pc <= 13122ULL)
			__x86_pc = tracee_trace_vfs_utimes_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

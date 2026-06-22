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

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_0(
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
	case 99ULL: goto x86_l_63;
	case 104ULL: goto x86_l_68;
	case 109ULL: goto x86_l_6d;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 119ULL: goto x86_l_77;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 129ULL: goto x86_l_81;
	case 131ULL: goto x86_l_83;
	case 136ULL: goto x86_l_88;
	case 143ULL: goto x86_l_8f;
	case 146ULL: goto x86_l_92;
	case 148ULL: goto x86_l_94;
	case 151ULL: goto x86_l_97;
	case 153ULL: goto x86_l_99;
	case 155ULL: goto x86_l_9b;
	case 157ULL: goto x86_l_9d;
	case 162ULL: goto x86_l_a2;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 182ULL: goto x86_l_b6;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 197ULL: goto x86_l_c5;
	case 203ULL: goto x86_l_cb;
	case 208ULL: goto x86_l_d0;
	case 215ULL: goto x86_l_d7;
	case 220ULL: goto x86_l_dc;
	case 222ULL: goto x86_l_de;
	case 225ULL: goto x86_l_e1;
	case 231ULL: goto x86_l_e7;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 249ULL: goto x86_l_f9;
	case 257ULL: goto x86_l_101;
	case 268ULL: goto x86_l_10c;
	case 279ULL: goto x86_l_117;
	case 290ULL: goto x86_l_122;
	case 301ULL: goto x86_l_12d;
	case 312ULL: goto x86_l_138;
	case 323ULL: goto x86_l_143;
	case 334ULL: goto x86_l_14e;
	case 345ULL: goto x86_l_159;
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
	case 456ULL: goto x86_l_1c8;
	case 461ULL: goto x86_l_1cd;
	case 463ULL: goto x86_l_1cf;
	case 467ULL: goto x86_l_1d3;
	case 471ULL: goto x86_l_1d7;
	case 475ULL: goto x86_l_1db;
	case 483ULL: goto x86_l_1e3;
	case 488ULL: goto x86_l_1e8;
	case 490ULL: goto x86_l_1ea;
	case 493ULL: goto x86_l_1ed;
	case 498ULL: goto x86_l_1f2;
	case 500ULL: goto x86_l_1f4;
	case 505ULL: goto x86_l_1f9;
	case 509ULL: goto x86_l_1fd;
	case 512ULL: goto x86_l_200;
	case 516ULL: goto x86_l_204;
	case 523ULL: goto x86_l_20b;
	case 528ULL: goto x86_l_210;
	case 535ULL: goto x86_l_217;
	case 543ULL: goto x86_l_21f;
	case 545ULL: goto x86_l_221;
	case 553ULL: goto x86_l_229;
	case 556ULL: goto x86_l_22c;
	case 558ULL: goto x86_l_22e;
	case 561ULL: goto x86_l_231;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 580ULL: goto x86_l_244;
	case 588ULL: goto x86_l_24c;
	case 590ULL: goto x86_l_24e;
	case 593ULL: goto x86_l_251;
	case 596ULL: goto x86_l_254;
	case 601ULL: goto x86_l_259;
	case 609ULL: goto x86_l_261;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 634ULL: goto x86_l_27a;
	case 639ULL: goto x86_l_27f;
	case 646ULL: goto x86_l_286;
	case 649ULL: goto x86_l_289;
	case 657ULL: goto x86_l_291;
	case 662ULL: goto x86_l_296;
	case 669ULL: goto x86_l_29d;
	case 674ULL: goto x86_l_2a2;
	case 676ULL: goto x86_l_2a4;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 692ULL: goto x86_l_2b4;
	case 703ULL: goto x86_l_2bf;
	case 714ULL: goto x86_l_2ca;
	case 725ULL: goto x86_l_2d5;
	case 736ULL: goto x86_l_2e0;
	case 747ULL: goto x86_l_2eb;
	case 758ULL: goto x86_l_2f6;
	case 769ULL: goto x86_l_301;
	case 780ULL: goto x86_l_30c;
	case 791ULL: goto x86_l_317;
	case 802ULL: goto x86_l_322;
	case 813ULL: goto x86_l_32d;
	case 824ULL: goto x86_l_338;
	case 835ULL: goto x86_l_343;
	case 846ULL: goto x86_l_34e;
	case 857ULL: goto x86_l_359;
	case 868ULL: goto x86_l_364;
	case 879ULL: goto x86_l_36f;
	case 890ULL: goto x86_l_37a;
	case 901ULL: goto x86_l_385;
	case 912ULL: goto x86_l_390;
	case 923ULL: goto x86_l_39b;
	case 934ULL: goto x86_l_3a6;
	case 945ULL: goto x86_l_3b1;
	case 956ULL: goto x86_l_3bc;
	case 967ULL: goto x86_l_3c7;
	case 978ULL: goto x86_l_3d2;
	case 989ULL: goto x86_l_3dd;
	case 1000ULL: goto x86_l_3e8;
	case 1011ULL: goto x86_l_3f3;
	case 1022ULL: goto x86_l_3fe;
	case 1030ULL: goto x86_l_406;
	case 1038ULL: goto x86_l_40e;
	case 1046ULL: goto x86_l_416;
	case 1054ULL: goto x86_l_41e;
	case 1062ULL: goto x86_l_426;
	case 1070ULL: goto x86_l_42e;
	case 1078ULL: goto x86_l_436;
	case 1086ULL: goto x86_l_43e;
	case 1094ULL: goto x86_l_446;
	case 1102ULL: goto x86_l_44e;
	case 1110ULL: goto x86_l_456;
	case 1118ULL: goto x86_l_45e;
	case 1126ULL: goto x86_l_466;
	case 1134ULL: goto x86_l_46e;
	case 1142ULL: goto x86_l_476;
	case 1149ULL: goto x86_l_47d;
	case 1155ULL: goto x86_l_483;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1172ULL: goto x86_l_494;
	case 1175ULL: goto x86_l_497;
	case 1178ULL: goto x86_l_49a;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1189ULL: goto x86_l_4a5;
	case 1192ULL: goto x86_l_4a8;
	case 1194ULL: goto x86_l_4aa;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1211ULL: goto x86_l_4bb;
	case 1216ULL: goto x86_l_4c0;
	case 1223ULL: goto x86_l_4c7;
	case 1226ULL: goto x86_l_4ca;
	case 1234ULL: goto x86_l_4d2;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1251ULL: goto x86_l_4e3;
	case 1253ULL: goto x86_l_4e5;
	case 1256ULL: goto x86_l_4e8;
	case 1262ULL: goto x86_l_4ee;
	case 1265ULL: goto x86_l_4f1;
	case 1269ULL: goto x86_l_4f5;
	case 1280ULL: goto x86_l_500;
	case 1291ULL: goto x86_l_50b;
	case 1302ULL: goto x86_l_516;
	case 1313ULL: goto x86_l_521;
	case 1324ULL: goto x86_l_52c;
	case 1335ULL: goto x86_l_537;
	case 1346ULL: goto x86_l_542;
	case 1357ULL: goto x86_l_54d;
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
	case 1488ULL: goto x86_l_5d0;
	case 1495ULL: goto x86_l_5d7;
	case 1501ULL: goto x86_l_5dd;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1527ULL: goto x86_l_5f7;
	case 1532ULL: goto x86_l_5fc;
	case 1535ULL: goto x86_l_5ff;
	case 1538ULL: goto x86_l_602;
	case 1540ULL: goto x86_l_604;
	case 1543ULL: goto x86_l_607;
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1559ULL: goto x86_l_617;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1578ULL: goto x86_l_62a;
	case 1581ULL: goto x86_l_62d;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1596ULL: goto x86_l_63c;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1622ULL: goto x86_l_656;
	case 1626ULL: goto x86_l_65a;
	case 1631ULL: goto x86_l_65f;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1652ULL: goto x86_l_674;
	case 1657ULL: goto x86_l_679;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1669ULL: goto x86_l_685;
	case 1673ULL: goto x86_l_689;
	case 1677ULL: goto x86_l_68d;
	case 1680ULL: goto x86_l_690;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1702ULL: goto x86_l_6a6;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
	case 1733ULL: goto x86_l_6c5;
	case 1737ULL: goto x86_l_6c9;
	case 1741ULL: goto x86_l_6cd;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1755ULL: goto x86_l_6db;
	case 1760ULL: goto x86_l_6e0;
	case 1762ULL: goto x86_l_6e2;
	case 1766ULL: goto x86_l_6e6;
	case 1770ULL: goto x86_l_6ea;
	case 1775ULL: goto x86_l_6ef;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1799ULL: goto x86_l_707;
	case 1804ULL: goto x86_l_70c;
	case 1809ULL: goto x86_l_711;
	case 1814ULL: goto x86_l_716;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1841ULL: goto x86_l_731;
	case 1845ULL: goto x86_l_735;
	case 1849ULL: goto x86_l_739;
	case 1853ULL: goto x86_l_73d;
	case 1857ULL: goto x86_l_741;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1872ULL: goto x86_l_750;
	case 1874ULL: goto x86_l_752;
	case 1878ULL: goto x86_l_756;
	case 1882ULL: goto x86_l_75a;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1900ULL: goto x86_l_76c;
	case 1902ULL: goto x86_l_76e;
	case 1907ULL: goto x86_l_773;
	case 1912ULL: goto x86_l_778;
	case 1917ULL: goto x86_l_77d;
	case 1922ULL: goto x86_l_782;
	case 1925ULL: goto x86_l_785;
	case 1927ULL: goto x86_l_787;
	case 1931ULL: goto x86_l_78b;
	case 1935ULL: goto x86_l_78f;
	case 1939ULL: goto x86_l_793;
	case 1943ULL: goto x86_l_797;
	case 1948ULL: goto x86_l_79c;
	case 1953ULL: goto x86_l_7a1;
	case 1958ULL: goto x86_l_7a6;
	case 1960ULL: goto x86_l_7a8;
	case 1965ULL: goto x86_l_7ad;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1986ULL: goto x86_l_7c2;
	case 1990ULL: goto x86_l_7c6;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2012ULL: goto x86_l_7dc;
	case 2014ULL: goto x86_l_7de;
	case 2019ULL: goto x86_l_7e3;
	case 2024ULL: goto x86_l_7e8;
	case 2029ULL: goto x86_l_7ed;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2043ULL: goto x86_l_7fb;
	case 2047ULL: goto x86_l_7ff;
	case 2051ULL: goto x86_l_803;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2070ULL: goto x86_l_816;
	case 2072ULL: goto x86_l_818;
	case 2077ULL: goto x86_l_81d;
	case 2081ULL: goto x86_l_821;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2096ULL: goto x86_l_830;
	case 2098ULL: goto x86_l_832;
	case 2102ULL: goto x86_l_836;
	case 2104ULL: goto x86_l_838;
	case 2109ULL: goto x86_l_83d;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2122ULL: goto x86_l_84a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
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
	/* 0x43: jne    a2 <trace_security_bprm_check+0xa2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a2;
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
	/* 0x59: je     60 <trace_security_bprm_check+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_60;
	}
x86_l_5b:
	/* 0x5b: mov    eax,DWORD PTR [rax+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5e:
	/* 0x5e: jmp    60 <trace_security_bprm_check+0x60> */
	goto x86_l_60;
x86_l_60:
	/* 0x60: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63:
	/* 0x63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68:
	/* 0x68: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d:
	/* 0x6d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_72:
	/* 0x72: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_75:
	/* 0x75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77:
	/* 0x77: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_7c:
	/* 0x7c: jne    83 <trace_security_bprm_check+0x83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_83;
	}
x86_l_7e:
	/* 0x7e: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81:
	/* 0x81: jmp    a2 <trace_security_bprm_check+0xa2> */
	goto x86_l_a2;
x86_l_83:
	/* 0x83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88:
	/* 0x88: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sys_32_to_64_map)));
x86_l_8f:
	/* 0x8f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_92:
	/* 0x92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94:
	/* 0x94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_97:
	/* 0x97: je     9d <trace_security_bprm_check+0x9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9d;
	}
x86_l_99:
	/* 0x99: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b:
	/* 0x9b: jmp    a2 <trace_security_bprm_check+0xa2> */
	goto x86_l_a2;
x86_l_9d:
	/* 0x9d: mov    ebp,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967295ULL);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_aa:
	/* 0xaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af:
	/* 0xaf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&event_data_map)));
x86_l_b6:
	/* 0xb6: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bb:
	/* 0xbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2:
	/* 0xc2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c5:
	/* 0xc5: je     5d15 <trace_security_bprm_check+0x5d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23829ULL;
	}
x86_l_cb:
	/* 0xcb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d0:
	/* 0xd0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_d7:
	/* 0xd7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dc:
	/* 0xdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de:
	/* 0xde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e1:
	/* 0xe1: je     5d15 <trace_security_bprm_check+0x5d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23829ULL;
	}
x86_l_e7:
	/* 0xe7: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ea:
	/* 0xea: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef:
	/* 0xef: mov    WORD PTR [r14+0x7d8a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138031658958848ULL);
x86_l_f9:
	/* 0xf9: mov    BYTE PTR [r14+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_101:
	/* 0x101: mov    QWORD PTR [r14+0x7d8c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138044543860735ULL);
x86_l_10c:
	/* 0x10c: mov    QWORD PTR [r14+0x7d94],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138078903599103ULL);
x86_l_117:
	/* 0x117: mov    QWORD PTR [r14+0x7d9c],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138113263337471ULL);
x86_l_122:
	/* 0x122: mov    QWORD PTR [r14+0x7da4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138147623075839ULL);
x86_l_12d:
	/* 0x12d: mov    QWORD PTR [r14+0x7dac],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138181982814207ULL);
x86_l_138:
	/* 0x138: mov    QWORD PTR [r14+0x7db4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138216342552575ULL);
x86_l_143:
	/* 0x143: mov    QWORD PTR [r14+0x7dbc],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138250702290943ULL);
x86_l_14e:
	/* 0x14e: mov    QWORD PTR [r14+0x7dc4],0xffffffffffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138285062029311ULL);
x86_l_159:
	/* 0x159: mov    QWORD PTR [r14+0x7dd0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_160:
	/* 0x160: mov    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_168:
	/* 0x168: mov    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_178:
	/* 0x178: mov    QWORD PTR [r14+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_180:
	/* 0x180: mov    QWORD PTR [r14+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [r14+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_190:
	/* 0x190: mov    QWORD PTR [r14+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_198:
	/* 0x198: mov    QWORD PTR [r14+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1a0:
	/* 0x1a0: mov    QWORD PTR [r14+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1a8:
	/* 0x1a8: mov    QWORD PTR [r14+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [r14+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1b8:
	/* 0x1b8: mov    QWORD PTR [r14+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1c0:
	/* 0x1c0: mov    QWORD PTR [r14+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1c8:
	/* 0x1c8: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1cd:
	/* 0x1cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf:
	/* 0x1cf: mov    DWORD PTR [r14+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d3:
	/* 0x1d3: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1d7:
	/* 0x1d7: mov    DWORD PTR [r14+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1db:
	/* 0x1db: mov    DWORD PTR [r14+0x70],0x2db */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337883ULL);
x86_l_1e3:
	/* 0x1e3: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_1e8:
	/* 0x1e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea:
	/* 0x1ea: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ed:
	/* 0x1ed: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1f2:
	/* 0x1f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f4:
	/* 0x1f4: mov    WORD PTR [r14+0x7c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1f9:
	/* 0x1f9: mov    DWORD PTR [r14+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1fd:
	/* 0x1fd: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_200:
	/* 0x200: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_204:
	/* 0x204: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_20b:
	/* 0x20b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_210:
	/* 0x210: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_217:
	/* 0x217: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_21f:
	/* 0x21f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221:
	/* 0x221: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_229:
	/* 0x229: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: je     27f <trace_security_bprm_check+0x27f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f;
	}
x86_l_22e:
	/* 0x22e: mov    eax,DWORD PTR [rbp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_231:
	/* 0x231: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_238:
	/* 0x238: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23d:
	/* 0x23d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_244:
	/* 0x244: lea    rsi,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_24c:
	/* 0x24c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e:
	/* 0x24e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_251:
	/* 0x251: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_254:
	/* 0x254: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_259:
	/* 0x259: mov    QWORD PTR [rsp+0xa8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_261:
	/* 0x261: je     4c0 <trace_security_bprm_check+0x4c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c0;
	}
x86_l_267:
	/* 0x267: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_26d:
	/* 0x26d: jne    a09 <trace_security_bprm_check+0xa09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2569ULL;
	}
x86_l_273:
	/* 0x273: mov    eax,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 80ULL);
x86_l_278:
	/* 0x278: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a:
	/* 0x27a: jmp    a8d <trace_security_bprm_check+0xa8d> */
	return 2701ULL;
x86_l_27f:
	/* 0x27f: mov    eax,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_286:
	/* 0x286: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_289:
	/* 0x289: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_291:
	/* 0x291: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_296:
	/* 0x296: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_29d:
	/* 0x29d: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: je     5d15 <trace_security_bprm_check+0x5d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23829ULL;
	}
x86_l_2ad:
	/* 0x2ad: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b0:
	/* 0x2b0: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b4:
	/* 0x2b4: mov    QWORD PTR [rax+0x168],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1546188226560ULL);
x86_l_2bf:
	/* 0x2bf: mov    QWORD PTR [rax+0x160],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1511828488192ULL);
x86_l_2ca:
	/* 0x2ca: mov    QWORD PTR [rax+0x158],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1477468749824ULL);
x86_l_2d5:
	/* 0x2d5: mov    QWORD PTR [rax+0x150],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1443109011456ULL);
x86_l_2e0:
	/* 0x2e0: mov    QWORD PTR [rax+0x148],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1408749273088ULL);
x86_l_2eb:
	/* 0x2eb: mov    QWORD PTR [rax+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_2f6:
	/* 0x2f6: mov    QWORD PTR [rax+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_301:
	/* 0x301: mov    QWORD PTR [rax+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_30c:
	/* 0x30c: mov    QWORD PTR [rax+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_317:
	/* 0x317: mov    QWORD PTR [rax+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_322:
	/* 0x322: mov    QWORD PTR [rax+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_32d:
	/* 0x32d: mov    QWORD PTR [rax+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_338:
	/* 0x338: mov    QWORD PTR [rax+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_343:
	/* 0x343: mov    QWORD PTR [rax+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_34e:
	/* 0x34e: mov    QWORD PTR [rax+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_359:
	/* 0x359: mov    QWORD PTR [rax+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_364:
	/* 0x364: mov    QWORD PTR [rax+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_36f:
	/* 0x36f: mov    QWORD PTR [rax+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_37a:
	/* 0x37a: mov    QWORD PTR [rax+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_385:
	/* 0x385: mov    QWORD PTR [rax+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_390:
	/* 0x390: mov    QWORD PTR [rax+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_39b:
	/* 0x39b: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_3a6:
	/* 0x3a6: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_3b1:
	/* 0x3b1: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_3bc:
	/* 0x3bc: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_3c7:
	/* 0x3c7: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3d2:
	/* 0x3d2: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_3dd:
	/* 0x3dd: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3e8:
	/* 0x3e8: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_3f3:
	/* 0x3f3: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3fe:
	/* 0x3fe: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_406:
	/* 0x406: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_40e:
	/* 0x40e: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_416:
	/* 0x416: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_41e:
	/* 0x41e: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_426:
	/* 0x426: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_42e:
	/* 0x42e: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_436:
	/* 0x436: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_43e:
	/* 0x43e: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_446:
	/* 0x446: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_44e:
	/* 0x44e: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_456:
	/* 0x456: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_45e:
	/* 0x45e: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_466:
	/* 0x466: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_46e:
	/* 0x46e: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_476:
	/* 0x476: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47d:
	/* 0x47d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_483:
	/* 0x483: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&proc_info_map)));
x86_l_48a:
	/* 0x48a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48f:
	/* 0x48f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_494:
	/* 0x494: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_497:
	/* 0x497: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_49a:
	/* 0x49a: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_49d:
	/* 0x49d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a2:
	/* 0x4a2: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4a5:
	/* 0x4a5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a8:
	/* 0x4a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4aa:
	/* 0x4aa: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4b2:
	/* 0x4b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b5:
	/* 0x4b5: jne    22e <trace_security_bprm_check+0x22e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e;
	}
x86_l_4bb:
	/* 0x4bb: jmp    5d15 <trace_security_bprm_check+0x5d15> */
	return 23829ULL;
x86_l_4c0:
	/* 0x4c0: mov    eax,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4c7:
	/* 0x4c7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ca:
	/* 0x4ca: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4d2:
	/* 0x4d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d7:
	/* 0x4d7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&scratch_map)));
x86_l_4de:
	/* 0x4de: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4e3:
	/* 0x4e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e5:
	/* 0x4e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e8:
	/* 0x4e8: je     5d15 <trace_security_bprm_check+0x5d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23829ULL;
	}
x86_l_4ee:
	/* 0x4ee: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f1:
	/* 0x4f1: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f5:
	/* 0x4f5: mov    QWORD PTR [rax+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_500:
	/* 0x500: mov    QWORD PTR [rax+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_50b:
	/* 0x50b: mov    QWORD PTR [rax+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_516:
	/* 0x516: mov    QWORD PTR [rax+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_521:
	/* 0x521: mov    QWORD PTR [rax+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_52c:
	/* 0x52c: mov    QWORD PTR [rax+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_537:
	/* 0x537: mov    QWORD PTR [rax+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_542:
	/* 0x542: mov    QWORD PTR [rax+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_54d:
	/* 0x54d: mov    QWORD PTR [rax+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_558:
	/* 0x558: mov    QWORD PTR [rax+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_560:
	/* 0x560: mov    QWORD PTR [rax+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_568:
	/* 0x568: mov    QWORD PTR [rax+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rax+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_580:
	/* 0x580: mov    QWORD PTR [rax+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_588:
	/* 0x588: mov    QWORD PTR [rax+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_590:
	/* 0x590: mov    QWORD PTR [rax+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rax+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5a0:
	/* 0x5a0: mov    QWORD PTR [rax+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b0:
	/* 0x5b0: mov    QWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5b8:
	/* 0x5b8: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5c0:
	/* 0x5c0: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d7:
	/* 0x5d7: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_5dd:
	/* 0x5dd: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&task_info_map)));
x86_l_5e4:
	/* 0x5e4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5e9:
	/* 0x5e9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5ee:
	/* 0x5ee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f1:
	/* 0x5f1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5f4:
	/* 0x5f4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_5f7:
	/* 0x5f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fc:
	/* 0x5fc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5ff:
	/* 0x5ff: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_602:
	/* 0x602: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_604:
	/* 0x604: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_607:
	/* 0x607: je     5d15 <trace_security_bprm_check+0x5d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 23829ULL;
	}
x86_l_60d:
	/* 0x60d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_610:
	/* 0x610: mov    r15,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_617:
	/* 0x617: lea    r12,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_61b:
	/* 0x61b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_620:
	/* 0x620: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_625:
	/* 0x625: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62a:
	/* 0x62a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_62d:
	/* 0x62d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62f:
	/* 0x62f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_634:
	/* 0x634: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_63c:
	/* 0x63c: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_640:
	/* 0x640: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_645:
	/* 0x645: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64a:
	/* 0x64a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64f:
	/* 0x64f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651:
	/* 0x651: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_656:
	/* 0x656: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_65a:
	/* 0x65a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65f:
	/* 0x65f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_664:
	/* 0x664: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_669:
	/* 0x669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66b:
	/* 0x66b: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_670:
	/* 0x670: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_674:
	/* 0x674: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_679:
	/* 0x679: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67e:
	/* 0x67e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_683:
	/* 0x683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_685:
	/* 0x685: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_689:
	/* 0x689: mov    DWORD PTR [r13+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_68d:
	/* 0x68d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_690:
	/* 0x690: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_694:
	/* 0x694: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_699:
	/* 0x699: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69e:
	/* 0x69e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a3:
	/* 0x6a3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6a6:
	/* 0x6a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a8:
	/* 0x6a8: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ad:
	/* 0x6ad: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b2:
	/* 0x6b2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b7:
	/* 0x6b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6bc:
	/* 0x6bc: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6bf:
	/* 0x6bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c1:
	/* 0x6c1: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c5:
	/* 0x6c5: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_6c9:
	/* 0x6c9: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_6cd:
	/* 0x6cd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6d1:
	/* 0x6d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d6:
	/* 0x6d6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6db:
	/* 0x6db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_6e0:
	/* 0x6e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e2:
	/* 0x6e2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e6:
	/* 0x6e6: mov    DWORD PTR [r13+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6ea:
	/* 0x6ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6ef:
	/* 0x6ef: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f4:
	/* 0x6f4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6f9:
	/* 0x6f9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_6fc:
	/* 0x6fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fe:
	/* 0x6fe: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_703:
	/* 0x703: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_707:
	/* 0x707: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_70c:
	/* 0x70c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_711:
	/* 0x711: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_716:
	/* 0x716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_718:
	/* 0x718: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_71d:
	/* 0x71d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_722:
	/* 0x722: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_727:
	/* 0x727: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_72c:
	/* 0x72c: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_72f:
	/* 0x72f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_731:
	/* 0x731: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_735:
	/* 0x735: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_739:
	/* 0x739: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_73d:
	/* 0x73d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_741:
	/* 0x741: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_746:
	/* 0x746: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_74b:
	/* 0x74b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_750:
	/* 0x750: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_752:
	/* 0x752: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_756:
	/* 0x756: mov    DWORD PTR [r13+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_75a:
	/* 0x75a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_75f:
	/* 0x75f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_764:
	/* 0x764: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_769:
	/* 0x769: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_76c:
	/* 0x76c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76e:
	/* 0x76e: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_773:
	/* 0x773: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_778:
	/* 0x778: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_77d:
	/* 0x77d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_782:
	/* 0x782: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_785:
	/* 0x785: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_787:
	/* 0x787: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_78b:
	/* 0x78b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_78f:
	/* 0x78f: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_793:
	/* 0x793: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_797:
	/* 0x797: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_79c:
	/* 0x79c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a1:
	/* 0x7a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a6:
	/* 0x7a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a8:
	/* 0x7a8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7ad:
	/* 0x7ad: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_7b1:
	/* 0x7b1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7b6:
	/* 0x7b6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7bb:
	/* 0x7bb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7c0:
	/* 0x7c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c2:
	/* 0x7c2: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c6:
	/* 0x7c6: lea    r15,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7ca:
	/* 0x7ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7cf:
	/* 0x7cf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7d4:
	/* 0x7d4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7d9:
	/* 0x7d9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7dc:
	/* 0x7dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7de:
	/* 0x7de: mov    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7e3:
	/* 0x7e3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_7e8:
	/* 0x7e8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7ed:
	/* 0x7ed: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_7f2:
	/* 0x7f2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7f5:
	/* 0x7f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f7:
	/* 0x7f7: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7fb:
	/* 0x7fb: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_7ff:
	/* 0x7ff: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_803:
	/* 0x803: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_807:
	/* 0x807: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_80c:
	/* 0x80c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_811:
	/* 0x811: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_816:
	/* 0x816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_818:
	/* 0x818: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_81d:
	/* 0x81d: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_821:
	/* 0x821: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_826:
	/* 0x826: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_82b:
	/* 0x82b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_830:
	/* 0x830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_832:
	/* 0x832: cmp    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_836:
	/* 0x836: jne    88e <trace_security_bprm_check+0x88e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2190ULL;
	}
x86_l_838:
	/* 0x838: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_83d:
	/* 0x83d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_842:
	/* 0x842: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_847:
	/* 0x847: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_84a:
	/* 0x84a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 2124ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2147ULL: goto x86_l_863;
	case 2149ULL: goto x86_l_865;
	case 2153ULL: goto x86_l_869;
	case 2157ULL: goto x86_l_86d;
	case 2161ULL: goto x86_l_871;
	case 2165ULL: goto x86_l_875;
	case 2170ULL: goto x86_l_87a;
	case 2175ULL: goto x86_l_87f;
	case 2180ULL: goto x86_l_884;
	case 2182ULL: goto x86_l_886;
	case 2186ULL: goto x86_l_88a;
	case 2190ULL: goto x86_l_88e;
	case 2194ULL: goto x86_l_892;
	case 2201ULL: goto x86_l_899;
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2219ULL: goto x86_l_8ab;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2240ULL: goto x86_l_8c0;
	case 2245ULL: goto x86_l_8c5;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2257ULL: goto x86_l_8d1;
	case 2260ULL: goto x86_l_8d4;
	case 2265ULL: goto x86_l_8d9;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2281ULL: goto x86_l_8e9;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2315ULL: goto x86_l_90b;
	case 2323ULL: goto x86_l_913;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2353ULL: goto x86_l_931;
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
	case 2404ULL: goto x86_l_964;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2427ULL: goto x86_l_97b;
	case 2435ULL: goto x86_l_983;
	case 2443ULL: goto x86_l_98b;
	case 2448ULL: goto x86_l_990;
	case 2453ULL: goto x86_l_995;
	case 2455ULL: goto x86_l_997;
	case 2460ULL: goto x86_l_99c;
	case 2465ULL: goto x86_l_9a1;
	case 2470ULL: goto x86_l_9a6;
	case 2473ULL: goto x86_l_9a9;
	case 2475ULL: goto x86_l_9ab;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2495ULL: goto x86_l_9bf;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2515ULL: goto x86_l_9d3;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2525ULL: goto x86_l_9dd;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2539ULL: goto x86_l_9eb;
	case 2542ULL: goto x86_l_9ee;
	case 2544ULL: goto x86_l_9f0;
	case 2552ULL: goto x86_l_9f8;
	case 2557ULL: goto x86_l_9fd;
	case 2563ULL: goto x86_l_a03;
	case 2569ULL: goto x86_l_a09;
	case 2574ULL: goto x86_l_a0e;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2615ULL: goto x86_l_a37;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2649ULL: goto x86_l_a59;
	case 2654ULL: goto x86_l_a5e;
	case 2659ULL: goto x86_l_a63;
	case 2661ULL: goto x86_l_a65;
	case 2666ULL: goto x86_l_a6a;
	case 2669ULL: goto x86_l_a6d;
	case 2671ULL: goto x86_l_a6f;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2690ULL: goto x86_l_a82;
	case 2692ULL: goto x86_l_a84;
	case 2697ULL: goto x86_l_a89;
	case 2699ULL: goto x86_l_a8b;
	case 2701ULL: goto x86_l_a8d;
	case 2705ULL: goto x86_l_a91;
	case 2709ULL: goto x86_l_a95;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2724ULL: goto x86_l_aa4;
	case 2727ULL: goto x86_l_aa7;
	case 2729ULL: goto x86_l_aa9;
	case 2732ULL: goto x86_l_aac;
	case 2734ULL: goto x86_l_aae;
	case 2737ULL: goto x86_l_ab1;
	case 2744ULL: goto x86_l_ab8;
	case 2747ULL: goto x86_l_abb;
	case 2750ULL: goto x86_l_abe;
	case 2752ULL: goto x86_l_ac0;
	case 2756ULL: goto x86_l_ac4;
	case 2760ULL: goto x86_l_ac8;
	case 2766ULL: goto x86_l_ace;
	case 2772ULL: goto x86_l_ad4;
	case 2783ULL: goto x86_l_adf;
	case 2791ULL: goto x86_l_ae7;
	case 2796ULL: goto x86_l_aec;
	case 2801ULL: goto x86_l_af1;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2815ULL: goto x86_l_aff;
	case 2818ULL: goto x86_l_b02;
	case 2820ULL: goto x86_l_b04;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2833ULL: goto x86_l_b11;
	case 2835ULL: goto x86_l_b13;
	case 2838ULL: goto x86_l_b16;
	case 2840ULL: goto x86_l_b18;
	case 2844ULL: goto x86_l_b1c;
	case 2851ULL: goto x86_l_b23;
	case 2854ULL: goto x86_l_b26;
	case 2861ULL: goto x86_l_b2d;
	case 2865ULL: goto x86_l_b31;
	case 2869ULL: goto x86_l_b35;
	case 2876ULL: goto x86_l_b3c;
	case 2883ULL: goto x86_l_b43;
	case 2887ULL: goto x86_l_b47;
	case 2894ULL: goto x86_l_b4e;
	case 2898ULL: goto x86_l_b52;
	case 2905ULL: goto x86_l_b59;
	case 2909ULL: goto x86_l_b5d;
	case 2916ULL: goto x86_l_b64;
	case 2920ULL: goto x86_l_b68;
	case 2927ULL: goto x86_l_b6f;
	case 2934ULL: goto x86_l_b76;
	case 2941ULL: goto x86_l_b7d;
	case 2945ULL: goto x86_l_b81;
	case 2948ULL: goto x86_l_b84;
	case 2956ULL: goto x86_l_b8c;
	case 2958ULL: goto x86_l_b8e;
	case 2961ULL: goto x86_l_b91;
	case 2963ULL: goto x86_l_b93;
	case 2966ULL: goto x86_l_b96;
	case 2973ULL: goto x86_l_b9d;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2991ULL: goto x86_l_baf;
	case 2994ULL: goto x86_l_bb2;
	case 3000ULL: goto x86_l_bb8;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3017ULL: goto x86_l_bc9;
	case 3021ULL: goto x86_l_bcd;
	case 3024ULL: goto x86_l_bd0;
	case 3027ULL: goto x86_l_bd3;
	case 3034ULL: goto x86_l_bda;
	case 3037ULL: goto x86_l_bdd;
	case 3044ULL: goto x86_l_be4;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3051ULL: goto x86_l_beb;
	case 3059ULL: goto x86_l_bf3;
	case 3066ULL: goto x86_l_bfa;
	case 3069ULL: goto x86_l_bfd;
	case 3072ULL: goto x86_l_c00;
	case 3075ULL: goto x86_l_c03;
	case 3082ULL: goto x86_l_c0a;
	case 3085ULL: goto x86_l_c0d;
	case 3088ULL: goto x86_l_c10;
	case 3095ULL: goto x86_l_c17;
	case 3098ULL: goto x86_l_c1a;
	case 3100ULL: goto x86_l_c1c;
	case 3103ULL: goto x86_l_c1f;
	case 3106ULL: goto x86_l_c22;
	case 3109ULL: goto x86_l_c25;
	case 3112ULL: goto x86_l_c28;
	case 3119ULL: goto x86_l_c2f;
	case 3122ULL: goto x86_l_c32;
	case 3125ULL: goto x86_l_c35;
	case 3132ULL: goto x86_l_c3c;
	case 3135ULL: goto x86_l_c3f;
	case 3137ULL: goto x86_l_c41;
	case 3140ULL: goto x86_l_c44;
	case 3148ULL: goto x86_l_c4c;
	case 3152ULL: goto x86_l_c50;
	case 3155ULL: goto x86_l_c53;
	case 3162ULL: goto x86_l_c5a;
	case 3165ULL: goto x86_l_c5d;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3179ULL: goto x86_l_c6b;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3193ULL: goto x86_l_c79;
	case 3200ULL: goto x86_l_c80;
	case 3208ULL: goto x86_l_c88;
	case 3215ULL: goto x86_l_c8f;
	case 3222ULL: goto x86_l_c96;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3247ULL: goto x86_l_caf;
	case 3252ULL: goto x86_l_cb4;
	case 3254ULL: goto x86_l_cb6;
	case 3257ULL: goto x86_l_cb9;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3272ULL: goto x86_l_cc8;
	case 3275ULL: goto x86_l_ccb;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3290ULL: goto x86_l_cda;
	case 3292ULL: goto x86_l_cdc;
	case 3295ULL: goto x86_l_cdf;
	case 3297ULL: goto x86_l_ce1;
	case 3300ULL: goto x86_l_ce4;
	case 3304ULL: goto x86_l_ce8;
	case 3307ULL: goto x86_l_ceb;
	case 3309ULL: goto x86_l_ced;
	case 3312ULL: goto x86_l_cf0;
	case 3320ULL: goto x86_l_cf8;
	case 3325ULL: goto x86_l_cfd;
	case 3328ULL: goto x86_l_d00;
	case 3331ULL: goto x86_l_d03;
	case 3333ULL: goto x86_l_d05;
	case 3337ULL: goto x86_l_d09;
	case 3339ULL: goto x86_l_d0b;
	case 3342ULL: goto x86_l_d0e;
	case 3344ULL: goto x86_l_d10;
	case 3352ULL: goto x86_l_d18;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3395ULL: goto x86_l_d43;
	case 3398ULL: goto x86_l_d46;
	case 3400ULL: goto x86_l_d48;
	case 3403ULL: goto x86_l_d4b;
	case 3407ULL: goto x86_l_d4f;
	case 3410ULL: goto x86_l_d52;
	case 3412ULL: goto x86_l_d54;
	case 3419ULL: goto x86_l_d5b;
	case 3426ULL: goto x86_l_d62;
	case 3429ULL: goto x86_l_d65;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3450ULL: goto x86_l_d7a;
	case 3453ULL: goto x86_l_d7d;
	case 3455ULL: goto x86_l_d7f;
	case 3457ULL: goto x86_l_d81;
	case 3459ULL: goto x86_l_d83;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3475ULL: goto x86_l_d93;
	case 3478ULL: goto x86_l_d96;
	case 3480ULL: goto x86_l_d98;
	case 3484ULL: goto x86_l_d9c;
	case 3486ULL: goto x86_l_d9e;
	case 3489ULL: goto x86_l_da1;
	case 3491ULL: goto x86_l_da3;
	case 3499ULL: goto x86_l_dab;
	case 3502ULL: goto x86_l_dae;
	case 3505ULL: goto x86_l_db1;
	case 3508ULL: goto x86_l_db4;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3535ULL: goto x86_l_dcf;
	case 3537ULL: goto x86_l_dd1;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3554ULL: goto x86_l_de2;
	case 3561ULL: goto x86_l_de9;
	case 3568ULL: goto x86_l_df0;
	case 3573ULL: goto x86_l_df5;
	case 3578ULL: goto x86_l_dfa;
	case 3583ULL: goto x86_l_dff;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3597ULL: goto x86_l_e0d;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3612ULL: goto x86_l_e1c;
	case 3615ULL: goto x86_l_e1f;
	case 3617ULL: goto x86_l_e21;
	case 3622ULL: goto x86_l_e26;
	case 3627ULL: goto x86_l_e2b;
	case 3630ULL: goto x86_l_e2e;
	case 3632ULL: goto x86_l_e30;
	case 3635ULL: goto x86_l_e33;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3647ULL: goto x86_l_e3f;
	case 3649ULL: goto x86_l_e41;
	case 3651ULL: goto x86_l_e43;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3662ULL: goto x86_l_e4e;
	case 3665ULL: goto x86_l_e51;
	case 3667ULL: goto x86_l_e53;
	case 3673ULL: goto x86_l_e59;
	case 3675ULL: goto x86_l_e5b;
	case 3681ULL: goto x86_l_e61;
	case 3689ULL: goto x86_l_e69;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3700ULL: goto x86_l_e74;
	case 3706ULL: goto x86_l_e7a;
	case 3708ULL: goto x86_l_e7c;
	case 3711ULL: goto x86_l_e7f;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3730ULL: goto x86_l_e92;
	case 3738ULL: goto x86_l_e9a;
	case 3744ULL: goto x86_l_ea0;
	case 3749ULL: goto x86_l_ea5;
	case 3756ULL: goto x86_l_eac;
	case 3761ULL: goto x86_l_eb1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_84c:
	/* 0x84c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_851:
	/* 0x851: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_856:
	/* 0x856: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_85b:
	/* 0x85b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_860:
	/* 0x860: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_863:
	/* 0x863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_865:
	/* 0x865: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_869:
	/* 0x869: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_86d:
	/* 0x86d: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_871:
	/* 0x871: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_875:
	/* 0x875: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_87a:
	/* 0x87a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87f:
	/* 0x87f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_884:
	/* 0x884: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_886:
	/* 0x886: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_88a:
	/* 0x88a: mov    DWORD PTR [r13+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88e:
	/* 0x88e: mov    DWORD PTR [r13+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_892:
	/* 0x892: lea    r15,[r14+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_899:
	/* 0x899: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_89e:
	/* 0x89e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8a3:
	/* 0x8a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8a8:
	/* 0x8a8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ad:
	/* 0x8ad: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8b2:
	/* 0x8b2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_8b6:
	/* 0x8b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8bb:
	/* 0x8bb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8c0:
	/* 0x8c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c5:
	/* 0x8c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8c7:
	/* 0x8c7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8cc:
	/* 0x8cc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8d1:
	/* 0x8d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8d4:
	/* 0x8d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_8d9:
	/* 0x8d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8db:
	/* 0x8db: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8de:
	/* 0x8de: mov    DWORD PTR [r13+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_8e2:
	/* 0x8e2: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_8e7:
	/* 0x8e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e9:
	/* 0x8e9: mov    DWORD PTR [r13+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8ed:
	/* 0x8ed: lea    rdx,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8f1:
	/* 0x8f1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_8f6:
	/* 0x8f6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8fb:
	/* 0x8fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_900:
	/* 0x900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_902:
	/* 0x902: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_907:
	/* 0x907: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90b:
	/* 0x90b: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_913:
	/* 0x913: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_917:
	/* 0x917: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_91c:
	/* 0x91c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_921:
	/* 0x921: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_926:
	/* 0x926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_928:
	/* 0x928: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_92d:
	/* 0x92d: mov    QWORD PTR [r13+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_931:
	/* 0x931: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_935:
	/* 0x935: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_93a:
	/* 0x93a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_93f:
	/* 0x93f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_944:
	/* 0x944: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_947:
	/* 0x947: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_949:
	/* 0x949: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_94e:
	/* 0x94e: mov    QWORD PTR [r13+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_952:
	/* 0x952: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_957:
	/* 0x957: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_95c:
	/* 0x95c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_961:
	/* 0x961: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_964:
	/* 0x964: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_966:
	/* 0x966: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_96b:
	/* 0x96b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_970:
	/* 0x970: je     977 <trace_security_bprm_check+0x977> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_977;
	}
x86_l_972:
	/* 0x972: or     BYTE PTR [r13+0x54],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 360777252866ULL);
x86_l_977:
	/* 0x977: lea    rdi,[r13+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_97b:
	/* 0x97b: mov    QWORD PTR [r13+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_983:
	/* 0x983: mov    QWORD PTR [r13+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_98b:
	/* 0x98b: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_990:
	/* 0x990: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_995:
	/* 0x995: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_997:
	/* 0x997: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_99c:
	/* 0x99c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a1:
	/* 0x9a1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9a6:
	/* 0x9a6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9a9:
	/* 0x9a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ab:
	/* 0x9ab: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9b0:
	/* 0x9b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9b5:
	/* 0x9b5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ba:
	/* 0x9ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9bf:
	/* 0x9bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c1:
	/* 0x9c1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c6:
	/* 0x9c6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_9cb:
	/* 0x9cb: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d0:
	/* 0x9d0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9d3:
	/* 0x9d3: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_9d8:
	/* 0x9d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9da:
	/* 0x9da: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_9dd:
	/* 0x9dd: add    rdi,0x44 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 68ULL);
x86_l_9e1:
	/* 0x9e1: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_9e6:
	/* 0x9e6: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_9eb:
	/* 0x9eb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_9ee:
	/* 0x9ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f0:
	/* 0x9f0: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_9f8:
	/* 0x9f8: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9fd:
	/* 0x9fd: test   BYTE PTR [r12+0x4],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869216ULL);
x86_l_a03:
	/* 0xa03: je     273 <trace_security_bprm_check+0x273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 627ULL;
	}
x86_l_a09:
	/* 0xa09: mov    edx,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 152ULL);
x86_l_a0e:
	/* 0xa0e: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_a15:
	/* 0xa15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a1a:
	/* 0xa1a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
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
	/* 0xa29: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2d:
	/* 0xa2d: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a32:
	/* 0xa32: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a37:
	/* 0xa37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a39:
	/* 0xa39: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a3e:
	/* 0xa3e: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a43:
	/* 0xa43: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a48:
	/* 0xa48: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a4d:
	/* 0xa4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4f:
	/* 0xa4f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a54:
	/* 0xa54: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a59:
	/* 0xa59: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5e:
	/* 0xa5e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a63:
	/* 0xa63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a65:
	/* 0xa65: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6a:
	/* 0xa6a: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_a6d:
	/* 0xa6d: je     a8b <trace_security_bprm_check+0xa8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a8b;
	}
x86_l_a6f:
	/* 0xa6f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_a73:
	/* 0xa73: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a78:
	/* 0xa78: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a7d:
	/* 0xa7d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a82:
	/* 0xa82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a84:
	/* 0xa84: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a89:
	/* 0xa89: jmp    a8d <trace_security_bprm_check+0xa8d> */
	goto x86_l_a8d;
x86_l_a8b:
	/* 0xa8b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8d:
	/* 0xa8d: mov    QWORD PTR [rbp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a91:
	/* 0xa91: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a95:
	/* 0xa95: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a98:
	/* 0xa98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9d:
	/* 0xa9d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&containers_map)));
x86_l_aa4:
	/* 0xaa4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_aa7:
	/* 0xaa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa9:
	/* 0xaa9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aac:
	/* 0xaac: je     ac4 <trace_security_bprm_check+0xac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac4;
	}
x86_l_aae:
	/* 0xaae: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ab1:
	/* 0xab1: mov    BYTE PTR [r13+0xb1],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 177ULL);
x86_l_ab8:
	/* 0xab8: or     eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_abb:
	/* 0xabb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_abe:
	/* 0xabe: jne    ac4 <trace_security_bprm_check+0xac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ac4;
	}
x86_l_ac0:
	/* 0xac0: or     BYTE PTR [rbp+0x5c],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991233ULL);
x86_l_ac4:
	/* 0xac4: movzx  eax,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_ac8:
	/* 0xac8: cmp    ax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_ace:
	/* 0xace: jne    5ce7 <trace_security_bprm_check+0x5ce7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 23783ULL;
	}
x86_l_ad4:
	/* 0xad4: mov    QWORD PTR [rbp+0x7dd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138366666407936ULL);
x86_l_adf:
	/* 0xadf: mov    DWORD PTR [rsp+0x20],0x2db */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438954203ULL);
x86_l_ae7:
	/* 0xae7: mov    WORD PTR [rsp+0x70],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aec:
	/* 0xaec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af1:
	/* 0xaf1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&events_map_version)));
x86_l_af8:
	/* 0xaf8: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_afd:
	/* 0xafd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aff:
	/* 0xaff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b02:
	/* 0xb02: je     b6f <trace_security_bprm_check+0xb6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6f;
	}
x86_l_b04:
	/* 0xb04: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b09:
	/* 0xb09: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b0e:
	/* 0xb0e: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_b11:
	/* 0xb11: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b13:
	/* 0xb13: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b16:
	/* 0xb16: je     b6f <trace_security_bprm_check+0xb6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b6f;
	}
x86_l_b18:
	/* 0xb18: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1c:
	/* 0xb1c: mov    QWORD PTR [rbp+0x7de0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32224ULL);
x86_l_b23:
	/* 0xb23: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b26:
	/* 0xb26: mov    QWORD PTR [rbp+0x7dd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b2d:
	/* 0xb2d: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b31:
	/* 0xb31: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b35:
	/* 0xb35: mov    QWORD PTR [rbp+0x7de8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32232ULL);
x86_l_b3c:
	/* 0xb3c: mov    QWORD PTR [rbp+0x7df0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32240ULL);
x86_l_b43:
	/* 0xb43: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b47:
	/* 0xb47: mov    QWORD PTR [rbp+0x7df8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32248ULL);
x86_l_b4e:
	/* 0xb4e: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b52:
	/* 0xb52: mov    QWORD PTR [rbp+0x7e00],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32256ULL);
x86_l_b59:
	/* 0xb59: mov    rcx,QWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b5d:
	/* 0xb5d: mov    QWORD PTR [rbp+0x7e08],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32264ULL);
x86_l_b64:
	/* 0xb64: mov    rax,QWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b68:
	/* 0xb68: mov    QWORD PTR [rbp+0x7e10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32272ULL);
x86_l_b6f:
	/* 0xb6f: mov    rdx,QWORD PTR [rbp+0x7dd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32216ULL);
x86_l_b76:
	/* 0xb76: mov    QWORD PTR [rbp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b7d:
	/* 0xb7d: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b81:
	/* 0xb81: cmp    ecx,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_b84:
	/* 0xb84: mov    QWORD PTR [rsp+0x88],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b8c:
	/* 0xb8c: jne    ba8 <trace_security_bprm_check+0xba8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ba8;
	}
x86_l_b8e:
	/* 0xb8e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b91:
	/* 0xb91: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b93:
	/* 0xb93: and    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_b96:
	/* 0xb96: mov    QWORD PTR [rbp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b9d:
	/* 0xb9d: jne    1348 <trace_security_bprm_check+0x1348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4936ULL;
	}
x86_l_ba3:
	/* 0xba3: jmp    1e20 <trace_security_bprm_check+0x1e20> */
	return 7712ULL;
x86_l_ba8:
	/* 0xba8: mov    rax,QWORD PTR [rbp+0x7e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32336ULL);
x86_l_baf:
	/* 0xbaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bb2:
	/* 0xbb2: je     d54 <trace_security_bprm_check+0xd54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d54;
	}
x86_l_bb8:
	/* 0xbb8: movzx  ecx,BYTE PTR [r13+0xb1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 177ULL);
x86_l_bc0:
	/* 0xbc0: and    cl,0xfd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 253ULL);
x86_l_bc3:
	/* 0xbc3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc6:
	/* 0xbc6: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_bc9:
	/* 0xbc9: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_bcd:
	/* 0xbcd: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_bd0:
	/* 0xbd0: neg    r14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_bd3:
	/* 0xbd3: xor    r14,QWORD PTR [rbp+0x7ec0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32448ULL);
x86_l_bda:
	/* 0xbda: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bdd:
	/* 0xbdd: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_be4:
	/* 0xbe4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be7:
	/* 0xbe7: je     c10 <trace_security_bprm_check+0xc10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c10;
	}
x86_l_be9:
	/* 0xbe9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_beb:
	/* 0xbeb: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_bf3:
	/* 0xbf3: cmp    BYTE PTR [rdx+0xb1],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 760209211395ULL);
x86_l_bfa:
	/* 0xbfa: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_bfd:
	/* 0xbfd: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c00:
	/* 0xc00: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c03:
	/* 0xc03: xor    rcx,QWORD PTR [rbp+0x7ec8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32456ULL);
x86_l_c0a:
	/* 0xc0a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c0d:
	/* 0xc0d: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c10:
	/* 0xc10: mov    rax,QWORD PTR [rbp+0x7e60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32352ULL);
x86_l_c17:
	/* 0xc17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c1a:
	/* 0xc1a: je     c35 <trace_security_bprm_check+0xc35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c35;
	}
x86_l_c1c:
	/* 0xc1c: mov    ecx,DWORD PTR [rbp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_c1f:
	/* 0xc1f: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c22:
	/* 0xc22: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_c25:
	/* 0xc25: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c28:
	/* 0xc28: xor    rcx,QWORD PTR [rbp+0x7ed0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32464ULL);
x86_l_c2f:
	/* 0xc2f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c32:
	/* 0xc32: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c35:
	/* 0xc35: mov    rax,QWORD PTR [rbp+0x7e68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32360ULL);
x86_l_c3c:
	/* 0xc3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c3f:
	/* 0xc3f: je     c60 <trace_security_bprm_check+0xc60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c60;
	}
x86_l_c41:
	/* 0xc41: not    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_c44:
	/* 0xc44: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c4c:
	/* 0xc4c: movsx  rcx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c50:
	/* 0xc50: neg    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_NEG, 0);
x86_l_c53:
	/* 0xc53: xor    rcx,QWORD PTR [rbp+0x7ed8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 32472ULL);
x86_l_c5a:
	/* 0xc5a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c5d:
	/* 0xc5d: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c60:
	/* 0xc60: movzx  eax,WORD PTR [rbp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_c64:
	/* 0xc64: mov    r15,QWORD PTR [rbp+0x7e20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32288ULL);
x86_l_c6b:
	/* 0xc6b: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_c6e:
	/* 0xc6e: mov    WORD PTR [rsp+0x78],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c73:
	/* 0xc73: je     dbc <trace_security_bprm_check+0xdbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dbc;
	}
x86_l_c79:
	/* 0xc79: mov    rcx,QWORD PTR [rbp+0x7e90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32400ULL);
x86_l_c80:
	/* 0xc80: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c88:
	/* 0xc88: mov    r13,QWORD PTR [rbp+0x7f08] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32520ULL);
x86_l_c8f:
	/* 0xc8f: mov    rcx,QWORD PTR [rbp+0x7f10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32528ULL);
x86_l_c96:
	/* 0xc96: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c9e:
	/* 0xc9e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca3:
	/* 0xca3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ca8:
	/* 0xca8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_filter_version)));
x86_l_caf:
	/* 0xcaf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb4:
	/* 0xcb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb6:
	/* 0xcb6: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_cb9:
	/* 0xcb9: mov    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cbc:
	/* 0xcbc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc1:
	/* 0xcc1: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_cc8:
	/* 0xcc8: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: je     ced <trace_security_bprm_check+0xced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ced;
	}
x86_l_ccd:
	/* 0xccd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd2:
	/* 0xcd2: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd7:
	/* 0xcd7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cda:
	/* 0xcda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdc:
	/* 0xcdc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cdf:
	/* 0xcdf: je     ced <trace_security_bprm_check+0xced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ced;
	}
x86_l_ce1:
	/* 0xce1: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce4:
	/* 0xce4: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce8:
	/* 0xce8: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_ceb:
	/* 0xceb: jmp    cf0 <trace_security_bprm_check+0xcf0> */
	goto x86_l_cf0;
x86_l_ced:
	/* 0xced: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf0:
	/* 0xcf0: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cf8:
	/* 0xcf8: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cfd:
	/* 0xcfd: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_d00:
	/* 0xd00: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d03:
	/* 0xd03: jb     d1b <trace_security_bprm_check+0xd1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d1b;
	}
x86_l_d05:
	/* 0xd05: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d09:
	/* 0xd09: je     d10 <trace_security_bprm_check+0xd10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d10;
	}
x86_l_d0b:
	/* 0xd0b: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_d0e:
	/* 0xd0e: jbe    d1b <trace_security_bprm_check+0xd1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_d1b;
	}
x86_l_d10:
	/* 0xd10: and    rbp,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 176ULL);
x86_l_d18:
	/* 0xd18: or     r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_d1b:
	/* 0xd1b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d20:
	/* 0xd20: mov    eax,DWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d23:
	/* 0xd23: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d28:
	/* 0xd28: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d2f:
	/* 0xd2f: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_d32:
	/* 0xd32: je     d70 <trace_security_bprm_check+0xd70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d70;
	}
x86_l_d34:
	/* 0xd34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d39:
	/* 0xd39: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d3e:
	/* 0xd3e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d41:
	/* 0xd41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d43:
	/* 0xd43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d46:
	/* 0xd46: je     d81 <trace_security_bprm_check+0xd81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d81;
	}
x86_l_d48:
	/* 0xd48: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4b:
	/* 0xd4b: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4f:
	/* 0xd4f: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d52:
	/* 0xd52: jmp    d83 <trace_security_bprm_check+0xd83> */
	goto x86_l_d83;
x86_l_d54:
	/* 0xd54: mov    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d5b:
	/* 0xd5b: mov    rax,QWORD PTR [rbp+0x7e58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32344ULL);
x86_l_d62:
	/* 0xd62: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d65:
	/* 0xd65: jne    be9 <trace_security_bprm_check+0xbe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_be9;
	}
x86_l_d6b:
	/* 0xd6b: jmp    c10 <trace_security_bprm_check+0xc10> */
	goto x86_l_c10;
x86_l_d70:
	/* 0xd70: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d72:
	/* 0xd72: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d75:
	/* 0xd75: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7a:
	/* 0xd7a: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d7d:
	/* 0xd7d: jae    d98 <trace_security_bprm_check+0xd98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d98;
	}
x86_l_d7f:
	/* 0xd7f: jmp    dae <trace_security_bprm_check+0xdae> */
	goto x86_l_dae;
x86_l_d81:
	/* 0xd81: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d83:
	/* 0xd83: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d8b:
	/* 0xd8b: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_d8e:
	/* 0xd8e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d93:
	/* 0xd93: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d96:
	/* 0xd96: jb     dae <trace_security_bprm_check+0xdae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_dae;
	}
x86_l_d98:
	/* 0xd98: cmp    rdx,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_d9c:
	/* 0xd9c: je     da3 <trace_security_bprm_check+0xda3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da3;
	}
x86_l_d9e:
	/* 0xd9e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_da1:
	/* 0xda1: jbe    dae <trace_security_bprm_check+0xdae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_dae;
	}
x86_l_da3:
	/* 0xda3: and    rbp,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 176ULL);
x86_l_dab:
	/* 0xdab: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_dae:
	/* 0xdae: or     r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_db1:
	/* 0xdb1: or     r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_db4:
	/* 0xdb4: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_db7:
	/* 0xdb7: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dbc:
	/* 0xdbc: cmp    QWORD PTR [rbp+0x7e18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138641544314880ULL);
x86_l_dc4:
	/* 0xdc4: je     e5b <trace_security_bprm_check+0xe5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e5b;
	}
x86_l_dca:
	/* 0xdca: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_dcf:
	/* 0xdcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd1:
	/* 0xdd1: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_dd4:
	/* 0xdd4: mov    rbx,QWORD PTR [rbp+0x7e18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_ddb:
	/* 0xddb: mov    r15,QWORD PTR [rbp+0x7e88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32392ULL);
x86_l_de2:
	/* 0xde2: mov    r13,QWORD PTR [rbp+0x7ef8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32504ULL);
x86_l_de9:
	/* 0xde9: mov    r12,QWORD PTR [rbp+0x7f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32512ULL);
x86_l_df0:
	/* 0xdf0: movzx  eax,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_df5:
	/* 0xdf5: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dfa:
	/* 0xdfa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dff:
	/* 0xdff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uid_filter_version)));
x86_l_e06:
	/* 0xe06: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e0b:
	/* 0xe0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0d:
	/* 0xe0d: mov    ecx,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e10:
	/* 0xe10: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e15:
	/* 0xe15: mov    rbp,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e1c:
	/* 0xe1c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e1f:
	/* 0xe1f: je     e41 <trace_security_bprm_check+0xe41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e41;
	}
x86_l_e21:
	/* 0xe21: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e26:
	/* 0xe26: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e2b:
	/* 0xe2b: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e2e:
	/* 0xe2e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e30:
	/* 0xe30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e33:
	/* 0xe33: je     e41 <trace_security_bprm_check+0xe41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e41;
	}
x86_l_e35:
	/* 0xe35: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e38:
	/* 0xe38: mov    rbp,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e3c:
	/* 0xe3c: not    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e3f:
	/* 0xe3f: jmp    e43 <trace_security_bprm_check+0xe43> */
	goto x86_l_e43;
x86_l_e41:
	/* 0xe41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e43:
	/* 0xe43: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_e46:
	/* 0xe46: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e4b:
	/* 0xe4b: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e4e:
	/* 0xe4e: cmp    r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e51:
	/* 0xe51: jae    e70 <trace_security_bprm_check+0xe70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e70;
	}
x86_l_e53:
	/* 0xe53: movzx  r13d,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_e59:
	/* 0xe59: jmp    e87 <trace_security_bprm_check+0xe87> */
	goto x86_l_e87;
x86_l_e5b:
	/* 0xe5b: movzx  r13d,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_e61:
	/* 0xe61: cmp    QWORD PTR [rbp+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_e69:
	/* 0xe69: jne    ea0 <trace_security_bprm_check+0xea0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ea0;
	}
x86_l_e6b:
	/* 0xe6b: jmp    f54 <trace_security_bprm_check+0xf54> */
	return 3924ULL;
x86_l_e70:
	/* 0xe70: cmp    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e74:
	/* 0xe74: movzx  r13d,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_e7a:
	/* 0xe7a: je     e81 <trace_security_bprm_check+0xe81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e81;
	}
x86_l_e7c:
	/* 0xe7c: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_e7f:
	/* 0xe7f: jbe    e87 <trace_security_bprm_check+0xe87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e87;
	}
x86_l_e81:
	/* 0xe81: and    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_e84:
	/* 0xe84: or     rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_e87:
	/* 0xe87: or     rcx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e8a:
	/* 0xe8a: and    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e8d:
	/* 0xe8d: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e92:
	/* 0xe92: cmp    QWORD PTR [rbp+0x7e28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138710263791616ULL);
x86_l_e9a:
	/* 0xe9a: je     f54 <trace_security_bprm_check+0xf54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3924ULL;
	}
x86_l_ea0:
	/* 0xea0: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_ea5:
	/* 0xea5: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_eac:
	/* 0xeac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_eb1:
	/* 0xeb1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 3766ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3766ULL: goto x86_l_eb6;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3778ULL: goto x86_l_ec2;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3797ULL: goto x86_l_ed5;
	case 3799ULL: goto x86_l_ed7;
	case 3804ULL: goto x86_l_edc;
	case 3809ULL: goto x86_l_ee1;
	case 3812ULL: goto x86_l_ee4;
	case 3817ULL: goto x86_l_ee9;
	case 3819ULL: goto x86_l_eeb;
	case 3822ULL: goto x86_l_eee;
	case 3825ULL: goto x86_l_ef1;
	case 3832ULL: goto x86_l_ef8;
	case 3839ULL: goto x86_l_eff;
	case 3842ULL: goto x86_l_f02;
	case 3848ULL: goto x86_l_f08;
	case 3853ULL: goto x86_l_f0d;
	case 3860ULL: goto x86_l_f14;
	case 3865ULL: goto x86_l_f19;
	case 3867ULL: goto x86_l_f1b;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3879ULL: goto x86_l_f27;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3891ULL: goto x86_l_f33;
	case 3893ULL: goto x86_l_f35;
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3905ULL: goto x86_l_f41;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3912ULL: goto x86_l_f48;
	case 3915ULL: goto x86_l_f4b;
	case 3918ULL: goto x86_l_f4e;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3932ULL: goto x86_l_f5c;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3949ULL: goto x86_l_f6d;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3964ULL: goto x86_l_f7c;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3976ULL: goto x86_l_f88;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3989ULL: goto x86_l_f95;
	case 3991ULL: goto x86_l_f97;
	case 3995ULL: goto x86_l_f9b;
	case 3999ULL: goto x86_l_f9f;
	case 4003ULL: goto x86_l_fa3;
	case 4007ULL: goto x86_l_fa7;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4024ULL: goto x86_l_fb8;
	case 4029ULL: goto x86_l_fbd;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4050ULL: goto x86_l_fd2;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4064ULL: goto x86_l_fe0;
	case 4071ULL: goto x86_l_fe7;
	case 4074ULL: goto x86_l_fea;
	case 4080ULL: goto x86_l_ff0;
	case 4085ULL: goto x86_l_ff5;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4099ULL: goto x86_l_1003;
	case 4106ULL: goto x86_l_100a;
	case 4109ULL: goto x86_l_100d;
	case 4111ULL: goto x86_l_100f;
	case 4115ULL: goto x86_l_1013;
	case 4120ULL: goto x86_l_1018;
	case 4123ULL: goto x86_l_101b;
	case 4125ULL: goto x86_l_101d;
	case 4128ULL: goto x86_l_1020;
	case 4130ULL: goto x86_l_1022;
	case 4133ULL: goto x86_l_1025;
	case 4137ULL: goto x86_l_1029;
	case 4140ULL: goto x86_l_102c;
	case 4142ULL: goto x86_l_102e;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4150ULL: goto x86_l_1036;
	case 4153ULL: goto x86_l_1039;
	case 4156ULL: goto x86_l_103c;
	case 4164ULL: goto x86_l_1044;
	case 4170ULL: goto x86_l_104a;
	case 4175ULL: goto x86_l_104f;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4192ULL: goto x86_l_1060;
	case 4197ULL: goto x86_l_1065;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4214ULL: goto x86_l_1076;
	case 4219ULL: goto x86_l_107b;
	case 4221ULL: goto x86_l_107d;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4236ULL: goto x86_l_108c;
	case 4239ULL: goto x86_l_108f;
	case 4244ULL: goto x86_l_1094;
	case 4246ULL: goto x86_l_1096;
	case 4250ULL: goto x86_l_109a;
	case 4255ULL: goto x86_l_109f;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4266ULL: goto x86_l_10aa;
	case 4268ULL: goto x86_l_10ac;
	case 4275ULL: goto x86_l_10b3;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4310ULL: goto x86_l_10d6;
	case 4317ULL: goto x86_l_10dd;
	case 4320ULL: goto x86_l_10e0;
	case 4322ULL: goto x86_l_10e2;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
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
	case 4360ULL: goto x86_l_1108;
	case 4363ULL: goto x86_l_110b;
	case 4366ULL: goto x86_l_110e;
	case 4372ULL: goto x86_l_1114;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4386ULL: goto x86_l_1122;
	case 4391ULL: goto x86_l_1127;
	case 4394ULL: goto x86_l_112a;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4408ULL: goto x86_l_1138;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4443ULL: goto x86_l_115b;
	case 4450ULL: goto x86_l_1162;
	case 4453ULL: goto x86_l_1165;
	case 4455ULL: goto x86_l_1167;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4466ULL: goto x86_l_1172;
	case 4468ULL: goto x86_l_1174;
	case 4471ULL: goto x86_l_1177;
	case 4473ULL: goto x86_l_1179;
	case 4476ULL: goto x86_l_117c;
	case 4480ULL: goto x86_l_1180;
	case 4483ULL: goto x86_l_1183;
	case 4485ULL: goto x86_l_1185;
	case 4487ULL: goto x86_l_1187;
	case 4490ULL: goto x86_l_118a;
	case 4493ULL: goto x86_l_118d;
	case 4496ULL: goto x86_l_1190;
	case 4499ULL: goto x86_l_1193;
	case 4505ULL: goto x86_l_1199;
	case 4512ULL: goto x86_l_11a0;
	case 4515ULL: goto x86_l_11a3;
	case 4517ULL: goto x86_l_11a5;
	case 4520ULL: goto x86_l_11a8;
	case 4524ULL: goto x86_l_11ac;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4556ULL: goto x86_l_11cc;
	case 4563ULL: goto x86_l_11d3;
	case 4566ULL: goto x86_l_11d6;
	case 4568ULL: goto x86_l_11d8;
	case 4573ULL: goto x86_l_11dd;
	case 4578ULL: goto x86_l_11e2;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4588ULL: goto x86_l_11ec;
	case 4591ULL: goto x86_l_11ef;
	case 4595ULL: goto x86_l_11f3;
	case 4598ULL: goto x86_l_11f6;
	case 4600ULL: goto x86_l_11f8;
	case 4602ULL: goto x86_l_11fa;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4611ULL: goto x86_l_1203;
	case 4614ULL: goto x86_l_1206;
	case 4621ULL: goto x86_l_120d;
	case 4624ULL: goto x86_l_1210;
	case 4626ULL: goto x86_l_1212;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4661ULL: goto x86_l_1235;
	case 4668ULL: goto x86_l_123c;
	case 4671ULL: goto x86_l_123f;
	case 4673ULL: goto x86_l_1241;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4685ULL: goto x86_l_124d;
	case 4687ULL: goto x86_l_124f;
	case 4690ULL: goto x86_l_1252;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4699ULL: goto x86_l_125b;
	case 4702ULL: goto x86_l_125e;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4709ULL: goto x86_l_1265;
	case 4712ULL: goto x86_l_1268;
	case 4715ULL: goto x86_l_126b;
	case 4718ULL: goto x86_l_126e;
	case 4725ULL: goto x86_l_1275;
	case 4728ULL: goto x86_l_1278;
	case 4734ULL: goto x86_l_127e;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4762ULL: goto x86_l_129a;
	case 4767ULL: goto x86_l_129f;
	case 4769ULL: goto x86_l_12a1;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4781ULL: goto x86_l_12ad;
	case 4784ULL: goto x86_l_12b0;
	case 4792ULL: goto x86_l_12b8;
	case 4796ULL: goto x86_l_12bc;
	case 4801ULL: goto x86_l_12c1;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4811ULL: goto x86_l_12cb;
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
	case 4897ULL: goto x86_l_1321;
	case 4901ULL: goto x86_l_1325;
	case 4904ULL: goto x86_l_1328;
	case 4906ULL: goto x86_l_132a;
	case 4913ULL: goto x86_l_1331;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4930ULL: goto x86_l_1342;
	case 4936ULL: goto x86_l_1348;
	case 4940ULL: goto x86_l_134c;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4957ULL: goto x86_l_135d;
	case 4962ULL: goto x86_l_1362;
	case 4966ULL: goto x86_l_1366;
	case 4971ULL: goto x86_l_136b;
	case 4976ULL: goto x86_l_1370;
	case 4981ULL: goto x86_l_1375;
	case 4984ULL: goto x86_l_1378;
	case 4986ULL: goto x86_l_137a;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 5000ULL: goto x86_l_1388;
	case 5003ULL: goto x86_l_138b;
	case 5008ULL: goto x86_l_1390;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5031ULL: goto x86_l_13a7;
	case 5035ULL: goto x86_l_13ab;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5050ULL: goto x86_l_13ba;
	case 5055ULL: goto x86_l_13bf;
	case 5058ULL: goto x86_l_13c2;
	case 5060ULL: goto x86_l_13c4;
	case 5065ULL: goto x86_l_13c9;
	case 5069ULL: goto x86_l_13cd;
	case 5073ULL: goto x86_l_13d1;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5098ULL: goto x86_l_13ea;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5118ULL: goto x86_l_13fe;
	case 5123ULL: goto x86_l_1403;
	case 5125ULL: goto x86_l_1405;
	case 5128ULL: goto x86_l_1408;
	case 5134ULL: goto x86_l_140e;
	case 5137ULL: goto x86_l_1411;
	case 5141ULL: goto x86_l_1415;
	case 5146ULL: goto x86_l_141a;
	case 5151ULL: goto x86_l_141f;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5163ULL: goto x86_l_142b;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5186ULL: goto x86_l_1442;
	case 5188ULL: goto x86_l_1444;
	case 5193ULL: goto x86_l_1449;
	case 5199ULL: goto x86_l_144f;
	case 5203ULL: goto x86_l_1453;
	case 5208ULL: goto x86_l_1458;
	case 5213ULL: goto x86_l_145d;
	case 5218ULL: goto x86_l_1462;
	case 5221ULL: goto x86_l_1465;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5232ULL: goto x86_l_1470;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5279ULL: goto x86_l_149f;
	case 5284ULL: goto x86_l_14a4;
	case 5288ULL: goto x86_l_14a8;
	case 5292ULL: goto x86_l_14ac;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5313ULL: goto x86_l_14c1;
	case 5316ULL: goto x86_l_14c4;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_eb6:
	/* 0xeb6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ebb:
	/* 0xebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebd:
	/* 0xebd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec2:
	/* 0xec2: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ec6:
	/* 0xec6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ecb:
	/* 0xecb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ed0:
	/* 0xed0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ed5:
	/* 0xed5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed7:
	/* 0xed7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_edc:
	/* 0xedc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee1:
	/* 0xee1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ee4:
	/* 0xee4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ee9:
	/* 0xee9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eeb:
	/* 0xeeb: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eee:
	/* 0xeee: mov    DWORD PTR [rbp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ef1:
	/* 0xef1: mov    rbx,QWORD PTR [rbp+0x7e28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32296ULL);
x86_l_ef8:
	/* 0xef8: mov    r15,QWORD PTR [rbp+0x7e98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32408ULL);
x86_l_eff:
	/* 0xeff: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f02:
	/* 0xf02: mov    WORD PTR [rsp+0x20],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f08:
	/* 0xf08: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f0d:
	/* 0xf0d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&mnt_ns_filter_version)));
x86_l_f14:
	/* 0xf14: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f19:
	/* 0xf19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1b:
	/* 0xf1b: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f22:
	/* 0xf22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: je     f46 <trace_security_bprm_check+0xf46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f46;
	}
x86_l_f27:
	/* 0xf27: lea    rsi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f2b:
	/* 0xf2b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f30:
	/* 0xf30: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f35:
	/* 0xf35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f38:
	/* 0xf38: je     f46 <trace_security_bprm_check+0xf46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f46;
	}
x86_l_f3a:
	/* 0xf3a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3d:
	/* 0xf3d: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f41:
	/* 0xf41: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_f44:
	/* 0xf44: jmp    f48 <trace_security_bprm_check+0xf48> */
	goto x86_l_f48;
x86_l_f46:
	/* 0xf46: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f48:
	/* 0xf48: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f4b:
	/* 0xf4b: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_f4e:
	/* 0xf4e: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f51:
	/* 0xf51: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_f54:
	/* 0xf54: cmp    QWORD PTR [rbp+0x7e30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138744623529984ULL);
x86_l_f5c:
	/* 0xf5c: je     103c <trace_security_bprm_check+0x103c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103c;
	}
x86_l_f62:
	/* 0xf62: mov    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_f69:
	/* 0xf69: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_f6d:
	/* 0xf6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f72:
	/* 0xf72: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f77:
	/* 0xf77: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f7c:
	/* 0xf7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f7e:
	/* 0xf7e: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f83:
	/* 0xf83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_f88:
	/* 0xf88: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8d:
	/* 0xf8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f92:
	/* 0xf92: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f95:
	/* 0xf95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f97:
	/* 0xf97: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f9b:
	/* 0xf9b: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_f9f:
	/* 0xf9f: lea    rdx,[rbx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_fa3:
	/* 0xfa3: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_fa7:
	/* 0xfa7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fac:
	/* 0xfac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fb1:
	/* 0xfb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb6:
	/* 0xfb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb8:
	/* 0xfb8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fbd:
	/* 0xfbd: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_fc1:
	/* 0xfc1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fc6:
	/* 0xfc6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fcb:
	/* 0xfcb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fd0:
	/* 0xfd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd2:
	/* 0xfd2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd6:
	/* 0xfd6: mov    DWORD PTR [rbp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fd9:
	/* 0xfd9: mov    rbx,QWORD PTR [rbp+0x7e30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32304ULL);
x86_l_fe0:
	/* 0xfe0: mov    r15,QWORD PTR [rbp+0x7ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32416ULL);
x86_l_fe7:
	/* 0xfe7: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_fea:
	/* 0xfea: mov    WORD PTR [rsp+0x20],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ff0:
	/* 0xff0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff5:
	/* 0xff5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&pid_ns_filter_version)));
x86_l_ffc:
	/* 0xffc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1001:
	/* 0x1001: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1003:
	/* 0x1003: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_100a:
	/* 0x100a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_100d:
	/* 0x100d: je     102e <trace_security_bprm_check+0x102e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102e;
	}
x86_l_100f:
	/* 0x100f: lea    rsi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1013:
	/* 0x1013: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1018:
	/* 0x1018: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_101b:
	/* 0x101b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_101d:
	/* 0x101d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1020:
	/* 0x1020: je     102e <trace_security_bprm_check+0x102e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102e;
	}
x86_l_1022:
	/* 0x1022: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1025:
	/* 0x1025: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1029:
	/* 0x1029: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_102c:
	/* 0x102c: jmp    1030 <trace_security_bprm_check+0x1030> */
	goto x86_l_1030;
x86_l_102e:
	/* 0x102e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1030:
	/* 0x1030: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1033:
	/* 0x1033: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1036:
	/* 0x1036: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1039:
	/* 0x1039: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_103c:
	/* 0x103c: cmp    QWORD PTR [rbp+0x7e38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138778983268352ULL);
x86_l_1044:
	/* 0x1044: je     1114 <trace_security_bprm_check+0x1114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1114;
	}
x86_l_104a:
	/* 0x104a: mov    edx,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 144ULL);
x86_l_104f:
	/* 0x104f: add    rdx,QWORD PTR [rbp+0x7dd0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32208ULL);
x86_l_1056:
	/* 0x1056: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_105b:
	/* 0x105b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1060:
	/* 0x1060: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1065:
	/* 0x1065: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1067:
	/* 0x1067: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_106c:
	/* 0x106c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1071:
	/* 0x1071: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1076:
	/* 0x1076: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_107b:
	/* 0x107b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107d:
	/* 0x107d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1082:
	/* 0x1082: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1087:
	/* 0x1087: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_108c:
	/* 0x108c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_108f:
	/* 0x108f: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1094:
	/* 0x1094: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1096:
	/* 0x1096: lea    rbx,[rbp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_109a:
	/* 0x109a: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_109f:
	/* 0x109f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10a2:
	/* 0x10a2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_10a7:
	/* 0x10a7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10aa:
	/* 0x10aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ac:
	/* 0x10ac: mov    r15,QWORD PTR [rbp+0x7e38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32312ULL);
x86_l_10b3:
	/* 0x10b3: mov    r12,QWORD PTR [rbp+0x7ea8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32424ULL);
x86_l_10ba:
	/* 0x10ba: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10bd:
	/* 0x10bd: mov    WORD PTR [rsp+0x20],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10c3:
	/* 0x10c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c8:
	/* 0x10c8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&uts_ns_filter_version)));
x86_l_10cf:
	/* 0x10cf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10d4:
	/* 0x10d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d6:
	/* 0x10d6: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_10dd:
	/* 0x10dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e0:
	/* 0x10e0: je     1100 <trace_security_bprm_check+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1100;
	}
x86_l_10e2:
	/* 0x10e2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10e7:
	/* 0x10e7: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10ea:
	/* 0x10ea: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_10ed:
	/* 0x10ed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10ef:
	/* 0x10ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10f2:
	/* 0x10f2: je     1100 <trace_security_bprm_check+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1100;
	}
x86_l_10f4:
	/* 0x10f4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f7:
	/* 0x10f7: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fb:
	/* 0x10fb: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_10fe:
	/* 0x10fe: jmp    1102 <trace_security_bprm_check+0x1102> */
	goto x86_l_1102;
x86_l_1100:
	/* 0x1100: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1102:
	/* 0x1102: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1105:
	/* 0x1105: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1108:
	/* 0x1108: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_110b:
	/* 0x110b: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_110e:
	/* 0x110e: movzx  r13d,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1114:
	/* 0x1114: cmp    QWORD PTR [rbp+0x7e40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138813343006720ULL);
x86_l_111c:
	/* 0x111c: je     1199 <trace_security_bprm_check+0x1199> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1199;
	}
x86_l_111e:
	/* 0x111e: lea    rbx,[rbp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1122:
	/* 0x1122: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1127:
	/* 0x1127: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_112a:
	/* 0x112a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_112f:
	/* 0x112f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1131:
	/* 0x1131: mov    r15,QWORD PTR [rbp+0x7e40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32320ULL);
x86_l_1138:
	/* 0x1138: mov    r12,QWORD PTR [rbp+0x7eb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32432ULL);
x86_l_113f:
	/* 0x113f: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1142:
	/* 0x1142: mov    WORD PTR [rsp+0x20],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1148:
	/* 0x1148: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114d:
	/* 0x114d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&comm_filter_version)));
x86_l_1154:
	/* 0x1154: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1159:
	/* 0x1159: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115b:
	/* 0x115b: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1162:
	/* 0x1162: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1165:
	/* 0x1165: je     1185 <trace_security_bprm_check+0x1185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1185;
	}
x86_l_1167:
	/* 0x1167: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_116c:
	/* 0x116c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_116f:
	/* 0x116f: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_1172:
	/* 0x1172: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1174:
	/* 0x1174: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1177:
	/* 0x1177: je     1185 <trace_security_bprm_check+0x1185> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1185;
	}
x86_l_1179:
	/* 0x1179: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117c:
	/* 0x117c: mov    r13,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1180:
	/* 0x1180: not    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1183:
	/* 0x1183: jmp    1187 <trace_security_bprm_check+0x1187> */
	goto x86_l_1187;
x86_l_1185:
	/* 0x1185: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1187:
	/* 0x1187: or     r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_118a:
	/* 0x118a: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_118d:
	/* 0x118d: or     r13,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_1190:
	/* 0x1190: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1193:
	/* 0x1193: movzx  r13d,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1199:
	/* 0x1199: mov    rbx,QWORD PTR [rbp+0x7e48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32328ULL);
x86_l_11a0:
	/* 0x11a0: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_11a3:
	/* 0x11a3: je     1206 <trace_security_bprm_check+0x1206> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1206;
	}
x86_l_11a5:
	/* 0x11a5: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a8:
	/* 0x11a8: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ac:
	/* 0x11ac: mov    r15,QWORD PTR [rbp+0x7eb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32440ULL);
x86_l_11b3:
	/* 0x11b3: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11b6:
	/* 0x11b6: mov    WORD PTR [rsp],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bb:
	/* 0x11bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11c0:
	/* 0x11c0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_id_filter_version)));
x86_l_11c7:
	/* 0x11c7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11ca:
	/* 0x11ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11cc:
	/* 0x11cc: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_11d3:
	/* 0x11d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11d6:
	/* 0x11d6: je     11f8 <trace_security_bprm_check+0x11f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f8;
	}
x86_l_11d8:
	/* 0x11d8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11dd:
	/* 0x11dd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e2:
	/* 0x11e2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11e5:
	/* 0x11e5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11e7:
	/* 0x11e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11ea:
	/* 0x11ea: je     11f8 <trace_security_bprm_check+0x11f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f8;
	}
x86_l_11ec:
	/* 0x11ec: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ef:
	/* 0x11ef: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f3:
	/* 0x11f3: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_11f6:
	/* 0x11f6: jmp    11fa <trace_security_bprm_check+0x11fa> */
	goto x86_l_11fa;
x86_l_11f8:
	/* 0x11f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11fa:
	/* 0x11fa: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_11fd:
	/* 0x11fd: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1200:
	/* 0x1200: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1203:
	/* 0x1203: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1206:
	/* 0x1206: mov    rbx,QWORD PTR [rbp+0x7e70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32368ULL);
x86_l_120d:
	/* 0x120d: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1210:
	/* 0x1210: je     126e <trace_security_bprm_check+0x126e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_126e;
	}
x86_l_1212:
	/* 0x1212: mov    r15,QWORD PTR [rbp+0x7ee0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32480ULL);
x86_l_1219:
	/* 0x1219: not    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_121c:
	/* 0x121c: mov    WORD PTR [rsp+0x20],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1222:
	/* 0x1222: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1227:
	/* 0x1227: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_tree_map_version)));
x86_l_122e:
	/* 0x122e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1233:
	/* 0x1233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1235:
	/* 0x1235: mov    r12,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_123c:
	/* 0x123c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_123f:
	/* 0x123f: je     1260 <trace_security_bprm_check+0x1260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1260;
	}
x86_l_1241:
	/* 0x1241: lea    rsi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1245:
	/* 0x1245: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_124a:
	/* 0x124a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_124d:
	/* 0x124d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_124f:
	/* 0x124f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1252:
	/* 0x1252: je     1260 <trace_security_bprm_check+0x1260> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1260;
	}
x86_l_1254:
	/* 0x1254: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1257:
	/* 0x1257: mov    r12,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125b:
	/* 0x125b: not    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_125e:
	/* 0x125e: jmp    1262 <trace_security_bprm_check+0x1262> */
	goto x86_l_1262;
x86_l_1260:
	/* 0x1260: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1262:
	/* 0x1262: or     rbx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1265:
	/* 0x1265: and    r12,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_1268:
	/* 0x1268: or     r12,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_64, X86_ALU_OR);
x86_l_126b:
	/* 0x126b: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_126e:
	/* 0x126e: mov    r15,QWORD PTR [rbp+0x7e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32376ULL);
x86_l_1275:
	/* 0x1275: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1278:
	/* 0x1278: je     1300 <trace_security_bprm_check+0x1300> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1300;
	}
x86_l_127e:
	/* 0x127e: mov    r12,QWORD PTR [rbp+0x7ee8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32488ULL);
x86_l_1285:
	/* 0x1285: not    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_NOT, 0);
x86_l_1288:
	/* 0x1288: mov    WORD PTR [rsp+0x20],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128e:
	/* 0x128e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1293:
	/* 0x1293: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&binary_filter_version)));
x86_l_129a:
	/* 0x129a: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_129f:
	/* 0x129f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a1:
	/* 0x12a1: mov    r13,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_12a8:
	/* 0x12a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ab:
	/* 0x12ab: je     12f2 <trace_security_bprm_check+0x12f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f2;
	}
x86_l_12ad:
	/* 0x12ad: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12b0:
	/* 0x12b0: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12b8:
	/* 0x12b8: lea    rsi,[rax+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12bc:
	/* 0x12bc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c1:
	/* 0x12c1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12c4:
	/* 0x12c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c6:
	/* 0x12c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12c9:
	/* 0x12c9: jne    12e6 <trace_security_bprm_check+0x12e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12e6;
	}
x86_l_12cb:
	/* 0x12cb: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12d3:
	/* 0x12d3: lea    rsi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d7:
	/* 0x12d7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12dc:
	/* 0x12dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12df:
	/* 0x12df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e1:
	/* 0x12e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e4:
	/* 0x12e4: je     12f2 <trace_security_bprm_check+0x12f2> */
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
	/* 0x12f0: jmp    12f4 <trace_security_bprm_check+0x12f4> */
	goto x86_l_12f4;
x86_l_12f2:
	/* 0x12f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f4:
	/* 0x12f4: or     rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_12f7:
	/* 0x12f7: and    r13,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_12fa:
	/* 0x12fa: or     r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_12fd:
	/* 0x12fd: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1300:
	/* 0x1300: mov    rax,QWORD PTR [rbp+0x7e80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32384ULL);
x86_l_1307:
	/* 0x1307: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1312:
	/* 0x1312: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1317:
	/* 0x1317: je     1328 <trace_security_bprm_check+0x1328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1328;
	}
x86_l_1319:
	/* 0x1319: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1321:
	/* 0x1321: and    rax,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1325:
	/* 0x1325: or     r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1328:
	/* 0x1328: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132a:
	/* 0x132a: and    r14,QWORD PTR [rbp+0x7ef0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32496ULL);
x86_l_1331:
	/* 0x1331: mov    rdx,QWORD PTR [rbp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1338:
	/* 0x1338: and    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_133b:
	/* 0x133b: mov    QWORD PTR [rbp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1342:
	/* 0x1342: je     1e20 <trace_security_bprm_check+0x1e20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7712ULL;
	}
x86_l_1348:
	/* 0x1348: mov    rdx,QWORD PTR [r15+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_134c:
	/* 0x134c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1351:
	/* 0x1351: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1356:
	/* 0x1356: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_135b:
	/* 0x135b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135d:
	/* 0x135d: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1362:
	/* 0x1362: lea    r15,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1366:
	/* 0x1366: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_136b:
	/* 0x136b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1370:
	/* 0x1370: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1375:
	/* 0x1375: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1378:
	/* 0x1378: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137a:
	/* 0x137a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_137f:
	/* 0x137f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1384:
	/* 0x1384: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1388:
	/* 0x1388: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_138b:
	/* 0x138b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1390:
	/* 0x1390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1392:
	/* 0x1392: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1397:
	/* 0x1397: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139b:
	/* 0x139b: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13a0:
	/* 0x13a0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13a5:
	/* 0x13a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a7:
	/* 0x13a7: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13ab:
	/* 0x13ab: mov    DWORD PTR [rsp+0x84],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_13b2:
	/* 0x13b2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13b7:
	/* 0x13b7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_13ba:
	/* 0x13ba: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13bf:
	/* 0x13bf: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13c2:
	/* 0x13c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c4:
	/* 0x13c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_13c9:
	/* 0x13c9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13cd:
	/* 0x13cd: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_13d1:
	/* 0x13d1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13d6:
	/* 0x13d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13e2:
	/* 0x13e2: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_13ea:
	/* 0x13ea: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13f2:
	/* 0x13f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f7:
	/* 0x13f7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&bufs)));
x86_l_13fe:
	/* 0x13fe: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1403:
	/* 0x1403: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1405:
	/* 0x1405: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1408:
	/* 0x1408: je     152e <trace_security_bprm_check+0x152e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5422ULL;
	}
x86_l_140e:
	/* 0x140e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1411:
	/* 0x1411: lea    rdx,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1415:
	/* 0x1415: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_141a:
	/* 0x141a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_141f:
	/* 0x141f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1424:
	/* 0x1424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1426:
	/* 0x1426: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_142b:
	/* 0x142b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1434:
	/* 0x1434: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1438:
	/* 0x1438: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_143d:
	/* 0x143d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1442:
	/* 0x1442: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1444:
	/* 0x1444: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_1449:
	/* 0x1449: jne    153d <trace_security_bprm_check+0x153d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5437ULL;
	}
x86_l_144f:
	/* 0x144f: add    rbx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1453:
	/* 0x1453: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1458:
	/* 0x1458: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_145d:
	/* 0x145d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1462:
	/* 0x1462: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1465:
	/* 0x1465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1467:
	/* 0x1467: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_146c:
	/* 0x146c: lea    rax,[r13-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_1470:
	/* 0x1470: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1475:
	/* 0x1475: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_147a:
	/* 0x147a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_147f:
	/* 0x147f: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1484:
	/* 0x1484: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1489:
	/* 0x1489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148b:
	/* 0x148b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1490:
	/* 0x1490: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1495:
	/* 0x1495: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_149a:
	/* 0x149a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149f:
	/* 0x149f: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14a4:
	/* 0x14a4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a8:
	/* 0x14a8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_14ac:
	/* 0x14ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14b1:
	/* 0x14b1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14b6:
	/* 0x14b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14bb:
	/* 0x14bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bd:
	/* 0x14bd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c1:
	/* 0x14c1: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_14c4:
	/* 0x14c4: je     154e <trace_security_bprm_check+0x154e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5454ULL;
	}
x86_l_14ca:
	/* 0x14ca: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14cf:
	/* 0x14cf: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_14d2:
	/* 0x14d2: je     154e <trace_security_bprm_check+0x154e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5454ULL;
	}
	return 5332ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5332ULL: goto x86_l_14d4;
	case 5336ULL: goto x86_l_14d8;
	case 5341ULL: goto x86_l_14dd;
	case 5346ULL: goto x86_l_14e2;
	case 5351ULL: goto x86_l_14e7;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5362ULL: goto x86_l_14f2;
	case 5364ULL: goto x86_l_14f4;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5388ULL: goto x86_l_150c;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5406ULL: goto x86_l_151e;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5424ULL: goto x86_l_1530;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5457ULL: goto x86_l_1551;
	case 5463ULL: goto x86_l_1557;
	case 5468ULL: goto x86_l_155c;
	case 5473ULL: goto x86_l_1561;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5503ULL: goto x86_l_157f;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5535ULL: goto x86_l_159f;
	case 5540ULL: goto x86_l_15a4;
	case 5545ULL: goto x86_l_15a9;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5556ULL: goto x86_l_15b4;
	case 5561ULL: goto x86_l_15b9;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5576ULL: goto x86_l_15c8;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5586ULL: goto x86_l_15d2;
	case 5590ULL: goto x86_l_15d6;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5609ULL: goto x86_l_15e9;
	case 5611ULL: goto x86_l_15eb;
	case 5615ULL: goto x86_l_15ef;
	case 5618ULL: goto x86_l_15f2;
	case 5620ULL: goto x86_l_15f4;
	case 5625ULL: goto x86_l_15f9;
	case 5628ULL: goto x86_l_15fc;
	case 5630ULL: goto x86_l_15fe;
	case 5634ULL: goto x86_l_1602;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5651ULL: goto x86_l_1613;
	case 5655ULL: goto x86_l_1617;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5684ULL: goto x86_l_1634;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5697ULL: goto x86_l_1641;
	case 5699ULL: goto x86_l_1643;
	case 5702ULL: goto x86_l_1646;
	case 5708ULL: goto x86_l_164c;
	case 5713ULL: goto x86_l_1651;
	case 5715ULL: goto x86_l_1653;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5727ULL: goto x86_l_165f;
	case 5733ULL: goto x86_l_1665;
	case 5739ULL: goto x86_l_166b;
	case 5745ULL: goto x86_l_1671;
	case 5749ULL: goto x86_l_1675;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5770ULL: goto x86_l_168a;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5788ULL: goto x86_l_169c;
	case 5790ULL: goto x86_l_169e;
	case 5792ULL: goto x86_l_16a0;
	case 5800ULL: goto x86_l_16a8;
	case 5806ULL: goto x86_l_16ae;
	case 5809ULL: goto x86_l_16b1;
	case 5814ULL: goto x86_l_16b6;
	case 5821ULL: goto x86_l_16bd;
	case 5824ULL: goto x86_l_16c0;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5834ULL: goto x86_l_16ca;
	case 5836ULL: goto x86_l_16cc;
	case 5840ULL: goto x86_l_16d0;
	case 5847ULL: goto x86_l_16d7;
	case 5849ULL: goto x86_l_16d9;
	case 5856ULL: goto x86_l_16e0;
	case 5863ULL: goto x86_l_16e7;
	case 5866ULL: goto x86_l_16ea;
	case 5869ULL: goto x86_l_16ed;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5890ULL: goto x86_l_1702;
	case 5893ULL: goto x86_l_1705;
	case 5895ULL: goto x86_l_1707;
	case 5900ULL: goto x86_l_170c;
	case 5903ULL: goto x86_l_170f;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5924ULL: goto x86_l_1724;
	case 5931ULL: goto x86_l_172b;
	case 5938ULL: goto x86_l_1732;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5962ULL: goto x86_l_174a;
	case 5966ULL: goto x86_l_174e;
	case 5973ULL: goto x86_l_1755;
	case 5978ULL: goto x86_l_175a;
	case 5981ULL: goto x86_l_175d;
	case 5983ULL: goto x86_l_175f;
	case 5985ULL: goto x86_l_1761;
	case 5987ULL: goto x86_l_1763;
	case 5990ULL: goto x86_l_1766;
	case 5997ULL: goto x86_l_176d;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6011ULL: goto x86_l_177b;
	case 6018ULL: goto x86_l_1782;
	case 6021ULL: goto x86_l_1785;
	case 6028ULL: goto x86_l_178c;
	case 6034ULL: goto x86_l_1792;
	case 6038ULL: goto x86_l_1796;
	case 6045ULL: goto x86_l_179d;
	case 6050ULL: goto x86_l_17a2;
	case 6052ULL: goto x86_l_17a4;
	case 6061ULL: goto x86_l_17ad;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6074ULL: goto x86_l_17ba;
	case 6081ULL: goto x86_l_17c1;
	case 6086ULL: goto x86_l_17c6;
	case 6094ULL: goto x86_l_17ce;
	case 6099ULL: goto x86_l_17d3;
	case 6101ULL: goto x86_l_17d5;
	case 6104ULL: goto x86_l_17d8;
	case 6106ULL: goto x86_l_17da;
	case 6110ULL: goto x86_l_17de;
	case 6118ULL: goto x86_l_17e6;
	case 6125ULL: goto x86_l_17ed;
	case 6129ULL: goto x86_l_17f1;
	case 6136ULL: goto x86_l_17f8;
	case 6142ULL: goto x86_l_17fe;
	case 6151ULL: goto x86_l_1807;
	case 6158ULL: goto x86_l_180e;
	case 6160ULL: goto x86_l_1810;
	case 6164ULL: goto x86_l_1814;
	case 6171ULL: goto x86_l_181b;
	case 6176ULL: goto x86_l_1820;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6191ULL: goto x86_l_182f;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6200ULL: goto x86_l_1838;
	case 6208ULL: goto x86_l_1840;
	case 6215ULL: goto x86_l_1847;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6250ULL: goto x86_l_186a;
	case 6259ULL: goto x86_l_1873;
	case 6267ULL: goto x86_l_187b;
	case 6271ULL: goto x86_l_187f;
	case 6279ULL: goto x86_l_1887;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6298ULL: goto x86_l_189a;
	case 6303ULL: goto x86_l_189f;
	case 6306ULL: goto x86_l_18a2;
	case 6308ULL: goto x86_l_18a4;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6326ULL: goto x86_l_18b6;
	case 6331ULL: goto x86_l_18bb;
	case 6339ULL: goto x86_l_18c3;
	case 6343ULL: goto x86_l_18c7;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6360ULL: goto x86_l_18d8;
	case 6362ULL: goto x86_l_18da;
	case 6365ULL: goto x86_l_18dd;
	case 6367ULL: goto x86_l_18df;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6383ULL: goto x86_l_18ef;
	case 6385ULL: goto x86_l_18f1;
	case 6392ULL: goto x86_l_18f8;
	case 6394ULL: goto x86_l_18fa;
	case 6402ULL: goto x86_l_1902;
	case 6409ULL: goto x86_l_1909;
	case 6415ULL: goto x86_l_190f;
	case 6421ULL: goto x86_l_1915;
	case 6424ULL: goto x86_l_1918;
	case 6430ULL: goto x86_l_191e;
	case 6436ULL: goto x86_l_1924;
	case 6445ULL: goto x86_l_192d;
	case 6453ULL: goto x86_l_1935;
	case 6457ULL: goto x86_l_1939;
	case 6465ULL: goto x86_l_1941;
	case 6474ULL: goto x86_l_194a;
	case 6479ULL: goto x86_l_194f;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6510ULL: goto x86_l_196e;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6530ULL: goto x86_l_1982;
	case 6534ULL: goto x86_l_1986;
	case 6541ULL: goto x86_l_198d;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6556ULL: goto x86_l_199c;
	case 6558ULL: goto x86_l_199e;
	case 6560ULL: goto x86_l_19a0;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6574ULL: goto x86_l_19ae;
	case 6576ULL: goto x86_l_19b0;
	case 6583ULL: goto x86_l_19b7;
	case 6585ULL: goto x86_l_19b9;
	case 6593ULL: goto x86_l_19c1;
	case 6600ULL: goto x86_l_19c8;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6631ULL: goto x86_l_19e7;
	case 6636ULL: goto x86_l_19ec;
	case 6641ULL: goto x86_l_19f1;
	case 6645ULL: goto x86_l_19f5;
	case 6650ULL: goto x86_l_19fa;
	case 6655ULL: goto x86_l_19ff;
	case 6660ULL: goto x86_l_1a04;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6671ULL: goto x86_l_1a0f;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6697ULL: goto x86_l_1a29;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6718ULL: goto x86_l_1a3e;
	case 6722ULL: goto x86_l_1a42;
	case 6726ULL: goto x86_l_1a46;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6746ULL: goto x86_l_1a5a;
	case 6751ULL: goto x86_l_1a5f;
	case 6756ULL: goto x86_l_1a64;
	case 6761ULL: goto x86_l_1a69;
	case 6766ULL: goto x86_l_1a6e;
	case 6769ULL: goto x86_l_1a71;
	case 6771ULL: goto x86_l_1a73;
	case 6775ULL: goto x86_l_1a77;
	case 6779ULL: goto x86_l_1a7b;
	case 6783ULL: goto x86_l_1a7f;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6804ULL: goto x86_l_1a94;
	case 6808ULL: goto x86_l_1a98;
	case 6812ULL: goto x86_l_1a9c;
	case 6817ULL: goto x86_l_1aa1;
	case 6822ULL: goto x86_l_1aa6;
	case 6827ULL: goto x86_l_1aab;
	case 6830ULL: goto x86_l_1aae;
	case 6832ULL: goto x86_l_1ab0;
	case 6837ULL: goto x86_l_1ab5;
	case 6841ULL: goto x86_l_1ab9;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6856ULL: goto x86_l_1ac8;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6873ULL: goto x86_l_1ad9;
	case 6878ULL: goto x86_l_1ade;
	case 6881ULL: goto x86_l_1ae1;
	case 6883ULL: goto x86_l_1ae3;
	case 6887ULL: goto x86_l_1ae7;
	case 6891ULL: goto x86_l_1aeb;
	case 6895ULL: goto x86_l_1aef;
	case 6899ULL: goto x86_l_1af3;
	case 6904ULL: goto x86_l_1af8;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6916ULL: goto x86_l_1b04;
	case 6920ULL: goto x86_l_1b08;
	case 6924ULL: goto x86_l_1b0c;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6949ULL: goto x86_l_1b25;
	case 6954ULL: goto x86_l_1b2a;
	case 6959ULL: goto x86_l_1b2f;
	case 6964ULL: goto x86_l_1b34;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6973ULL: goto x86_l_1b3d;
	case 6977ULL: goto x86_l_1b41;
	case 6981ULL: goto x86_l_1b45;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7002ULL: goto x86_l_1b5a;
	case 7007ULL: goto x86_l_1b5f;
	case 7011ULL: goto x86_l_1b63;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7037ULL: goto x86_l_1b7d;
	case 7042ULL: goto x86_l_1b82;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14d4:
	/* 0x14d4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_14d8:
	/* 0x14d8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14dd:
	/* 0x14dd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14e2:
	/* 0x14e2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_14e7:
	/* 0x14e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e9:
	/* 0x14e9: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14ed:
	/* 0x14ed: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_14f2:
	/* 0x14f2: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_14f4:
	/* 0x14f4: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_14fa:
	/* 0x14fa: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_14fc:
	/* 0x14fc: neg    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_14fe:
	/* 0x14fe: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1504:
	/* 0x1504: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1507:
	/* 0x1507: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_150c:
	/* 0x150c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150e:
	/* 0x150e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1511:
	/* 0x1511: jl     1671 <trace_security_bprm_check+0x1671> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1671;
	}
x86_l_1517:
	/* 0x1517: mov    BYTE PTR [rbp+0x3fff],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210415ULL);
x86_l_151e:
	/* 0x151e: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_1523:
	/* 0x1523: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1525:
	/* 0x1525: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1529:
	/* 0x1529: jmp    15b9 <trace_security_bprm_check+0x15b9> */
	goto x86_l_15b9;
x86_l_152e:
	/* 0x152e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1530:
	/* 0x1530: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1538:
	/* 0x1538: jmp    16b1 <trace_security_bprm_check+0x16b1> */
	goto x86_l_16b1;
x86_l_153d:
	/* 0x153d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1542:
	/* 0x1542: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_1549:
	/* 0x1549: jmp    1694 <trace_security_bprm_check+0x1694> */
	goto x86_l_1694;
x86_l_154e:
	/* 0x154e: cmp    rdx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1551:
	/* 0x1551: jne    1671 <trace_security_bprm_check+0x1671> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1671;
	}
x86_l_1557:
	/* 0x1557: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_155c:
	/* 0x155c: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_1561:
	/* 0x1561: je     1671 <trace_security_bprm_check+0x1671> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1671;
	}
x86_l_1567:
	/* 0x1567: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_156c:
	/* 0x156c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1571:
	/* 0x1571: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1575:
	/* 0x1575: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1578:
	/* 0x1578: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_157d:
	/* 0x157d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157f:
	/* 0x157f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1584:
	/* 0x1584: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1589:
	/* 0x1589: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_158e:
	/* 0x158e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1593:
	/* 0x1593: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1595:
	/* 0x1595: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_159a:
	/* 0x159a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_159f:
	/* 0x159f: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15a4:
	/* 0x15a4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15a9:
	/* 0x15a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ab:
	/* 0x15ab: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15b0:
	/* 0x15b0: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_15b4:
	/* 0x15b4: mov    ebx,0x4000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_15b9:
	/* 0x15b9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15be:
	/* 0x15be: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c3:
	/* 0x15c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15c8:
	/* 0x15c8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15cb:
	/* 0x15cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cd:
	/* 0x15cd: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15d2:
	/* 0x15d2: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d6:
	/* 0x15d6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_15da:
	/* 0x15da: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_15df:
	/* 0x15df: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15e4:
	/* 0x15e4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15e9:
	/* 0x15e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15eb:
	/* 0x15eb: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ef:
	/* 0x15ef: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15f2:
	/* 0x15f2: je     165c <trace_security_bprm_check+0x165c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165c;
	}
x86_l_15f4:
	/* 0x15f4: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15f9:
	/* 0x15f9: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_15fc:
	/* 0x15fc: je     165c <trace_security_bprm_check+0x165c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_165c;
	}
x86_l_15fe:
	/* 0x15fe: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1602:
	/* 0x1602: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1607:
	/* 0x1607: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_160c:
	/* 0x160c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1611:
	/* 0x1611: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1613:
	/* 0x1613: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1617:
	/* 0x1617: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1619:
	/* 0x1619: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_161f:
	/* 0x161f: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_1621:
	/* 0x1621: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1623:
	/* 0x1623: jb     5970 <trace_security_bprm_check+0x5970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 22896ULL;
	}
x86_l_1629:
	/* 0x1629: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_162e:
	/* 0x162e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1634:
	/* 0x1634: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1637:
	/* 0x1637: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_163c:
	/* 0x163c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163e:
	/* 0x163e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1641:
	/* 0x1641: jl     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1665;
	}
x86_l_1643:
	/* 0x1643: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1646:
	/* 0x1646: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_164c:
	/* 0x164c: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_1651:
	/* 0x1651: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1653:
	/* 0x1653: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1657:
	/* 0x1657: jmp    5900 <trace_security_bprm_check+0x5900> */
	return 22784ULL;
x86_l_165c:
	/* 0x165c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_165f:
	/* 0x165f: je     58a3 <trace_security_bprm_check+0x58a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 22691ULL;
	}
x86_l_1665:
	/* 0x1665: cmp    ebx,0x4000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 16384ULL);
x86_l_166b:
	/* 0x166b: jne    5970 <trace_security_bprm_check+0x5970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 22896ULL;
	}
x86_l_1671:
	/* 0x1671: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1675:
	/* 0x1675: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1679:
	/* 0x1679: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_167e:
	/* 0x167e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1683:
	/* 0x1683: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1688:
	/* 0x1688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168a:
	/* 0x168a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_168f:
	/* 0x168f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1694:
	/* 0x1694: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1697:
	/* 0x1697: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_169c:
	/* 0x169c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169e:
	/* 0x169e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a0:
	/* 0x16a0: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16a8:
	/* 0x16a8: and    ebx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_16ae:
	/* 0x16ae: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16b1:
	/* 0x16b1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16b6:
	/* 0x16b6: lea    rbx,[rax+0x7d8a] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_16bd:
	/* 0x16bd: mov    eax,DWORD PTR [rcx+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16c0:
	/* 0x16c0: cmp    eax,0x142 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 322ULL);
x86_l_16c5:
	/* 0x16c5: je     16d9 <trace_security_bprm_check+0x16d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d9;
	}
x86_l_16c7:
	/* 0x16c7: cmp    eax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 59ULL);
x86_l_16ca:
	/* 0x16ca: jne    1702 <trace_security_bprm_check+0x1702> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1702;
	}
x86_l_16cc:
	/* 0x16cc: lea    rax,[rcx+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16d0:
	/* 0x16d0: add    rcx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 128ULL);
x86_l_16d7:
	/* 0x16d7: jmp    16e7 <trace_security_bprm_check+0x16e7> */
	goto x86_l_16e7;
x86_l_16d9:
	/* 0x16d9: lea    rax,[rcx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16e0:
	/* 0x16e0: add    rcx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_16e7:
	/* 0x16e7: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ea:
	/* 0x16ea: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ed:
	/* 0x16ed: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16f2:
	/* 0x16f2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16f5:
	/* 0x16f5: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_16fb:
	/* 0x16fb: jbe    1717 <trace_security_bprm_check+0x1717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1717;
	}
x86_l_16fd:
	/* 0x16fd: jmp    1792 <trace_security_bprm_check+0x1792> */
	goto x86_l_1792;
x86_l_1702:
	/* 0x1702: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1705:
	/* 0x1705: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1707:
	/* 0x1707: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_170c:
	/* 0x170c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_170f:
	/* 0x170f: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_1715:
	/* 0x1715: ja     1792 <trace_security_bprm_check+0x1792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1792;
	}
x86_l_1717:
	/* 0x1717: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_171c:
	/* 0x171c: mov    BYTE PTR [rcx+rax*1+0x89],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519552ULL);
x86_l_1724:
	/* 0x1724: movzx  eax,WORD PTR [rcx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_172b:
	/* 0x172b: mov    WORD PTR [rcx+0x7d8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32140ULL);
x86_l_1732:
	/* 0x1732: cmp    eax,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27899ULL);
x86_l_1737:
	/* 0x1737: ja     1792 <trace_security_bprm_check+0x1792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1792;
	}
x86_l_1739:
	/* 0x1739: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_173e:
	/* 0x173e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1743:
	/* 0x1743: movzx  ecx,WORD PTR [rdx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_174a:
	/* 0x174a: lea    rdi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_174e:
	/* 0x174e: add    rdi,0x8e */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 142ULL);
x86_l_1755:
	/* 0x1755: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_175a:
	/* 0x175a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_175d:
	/* 0x175d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175f:
	/* 0x175f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1761:
	/* 0x1761: jle    1792 <trace_security_bprm_check+0x1792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1792;
	}
x86_l_1763:
	/* 0x1763: movzx  ecx,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1766:
	/* 0x1766: cmp    rcx,0x6cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 27899ULL);
x86_l_176d:
	/* 0x176d: ja     1792 <trace_security_bprm_check+0x1792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1792;
	}
x86_l_176f:
	/* 0x176f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1774:
	/* 0x1774: mov    DWORD PTR [rcx+rdx*1+0x8a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 138ULL);
x86_l_177b:
	/* 0x177b: add    ax,WORD PTR [rdx+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1782:
	/* 0x1782: add    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_1785:
	/* 0x1785: mov    WORD PTR [rdx+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_178c:
	/* 0x178c: inc    BYTE PTR [rdx+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDX, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1792:
	/* 0x1792: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1796:
	/* 0x1796: cmp    r14,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 31999ULL);
x86_l_179d:
	/* 0x179d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17a2:
	/* 0x17a2: ja     17ed <trace_security_bprm_check+0x17ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17ed;
	}
x86_l_17a4:
	/* 0x17a4: mov    BYTE PTR [r15+r14*1+0x89],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 588410519553ULL);
x86_l_17ad:
	/* 0x17ad: cmp    r14d,0x7cfb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31995ULL);
x86_l_17b4:
	/* 0x17b4: ja     17ed <trace_security_bprm_check+0x17ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17ed;
	}
x86_l_17b6:
	/* 0x17b6: lea    rdi,[r14+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_17ba:
	/* 0x17ba: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_17c1:
	/* 0x17c1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c6:
	/* 0x17c6: lea    rdx,[rsp+0x84] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_17ce:
	/* 0x17ce: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17d3:
	/* 0x17d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d5:
	/* 0x17d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17d8:
	/* 0x17d8: js     17ed <trace_security_bprm_check+0x17ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_17ed;
	}
x86_l_17da:
	/* 0x17da: add    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 5ULL);
x86_l_17de:
	/* 0x17de: mov    WORD PTR [r15+0x7d8a],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_17e6:
	/* 0x17e6: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_17ed:
	/* 0x17ed: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17f1:
	/* 0x17f1: cmp    r14,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 32000ULL);
x86_l_17f8:
	/* 0x17f8: jae    1909 <trace_security_bprm_check+0x1909> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1909;
	}
x86_l_17fe:
	/* 0x17fe: mov    BYTE PTR [r15+r14*1+0x89],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 588410519554ULL);
x86_l_1807:
	/* 0x1807: cmp    r14d,0x7cf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31991ULL);
x86_l_180e:
	/* 0x180e: ja     1857 <trace_security_bprm_check+0x1857> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1857;
	}
x86_l_1810:
	/* 0x1810: lea    rdi,[r14+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1814:
	/* 0x1814: add    rdi,0x8a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 138ULL);
x86_l_181b:
	/* 0x181b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1820:
	/* 0x1820: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1828:
	/* 0x1828: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_182d:
	/* 0x182d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182f:
	/* 0x182f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1832:
	/* 0x1832: js     1857 <trace_security_bprm_check+0x1857> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1857;
	}
x86_l_1834:
	/* 0x1834: add    r14d,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 9ULL);
x86_l_1838:
	/* 0x1838: mov    WORD PTR [r15+0x7d8a],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1840:
	/* 0x1840: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1847:
	/* 0x1847: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_184b:
	/* 0x184b: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1850:
	/* 0x1850: jbe    186a <trace_security_bprm_check+0x186a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_186a;
	}
x86_l_1852:
	/* 0x1852: jmp    1909 <trace_security_bprm_check+0x1909> */
	goto x86_l_1909;
x86_l_1857:
	/* 0x1857: movzx  r14d,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_185b:
	/* 0x185b: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_185f:
	/* 0x185f: cmp    eax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31999ULL);
x86_l_1864:
	/* 0x1864: ja     1909 <trace_security_bprm_check+0x1909> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1909;
	}
x86_l_186a:
	/* 0x186a: mov    BYTE PTR [r15+rax*1+0x89],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519555ULL);
x86_l_1873:
	/* 0x1873: movzx  r14d,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_187b:
	/* 0x187b: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_187f:
	/* 0x187f: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1887:
	/* 0x1887: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1890:
	/* 0x1890: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1895:
	/* 0x1895: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_189a:
	/* 0x189a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_189f:
	/* 0x189f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_18a2:
	/* 0x18a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18a4:
	/* 0x18a4: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_18aa:
	/* 0x18aa: je     18ef <trace_security_bprm_check+0x18ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ef;
	}
x86_l_18ac:
	/* 0x18ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18af:
	/* 0x18af: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_18b4:
	/* 0x18b4: ja     18ef <trace_security_bprm_check+0x18ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18ef;
	}
x86_l_18b6:
	/* 0x18b6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_18bb:
	/* 0x18bb: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_18c3:
	/* 0x18c3: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_18c7:
	/* 0x18c7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_18ce:
	/* 0x18ce: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18d3:
	/* 0x18d3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18d8:
	/* 0x18d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18da:
	/* 0x18da: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18dd:
	/* 0x18dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18df:
	/* 0x18df: jle    18ef <trace_security_bprm_check+0x18ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_18ef;
	}
x86_l_18e1:
	/* 0x18e1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18e4:
	/* 0x18e4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_18e9:
	/* 0x18e9: jbe    1e2f <trace_security_bprm_check+0x1e2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7727ULL;
	}
x86_l_18ef:
	/* 0x18ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f1:
	/* 0x18f1: cmp    r14d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31998ULL);
x86_l_18f8:
	/* 0x18f8: ja     1909 <trace_security_bprm_check+0x1909> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1909;
	}
x86_l_18fa:
	/* 0x18fa: mov    BYTE PTR [r15+r14*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_1902:
	/* 0x1902: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_1909:
	/* 0x1909: test   BYTE PTR [r12+0x4],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869185ULL);
x86_l_190f:
	/* 0x190f: je     19c8 <trace_security_bprm_check+0x19c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19c8;
	}
x86_l_1915:
	/* 0x1915: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1918:
	/* 0x1918: cmp    rax,0x7cff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 31999ULL);
x86_l_191e:
	/* 0x191e: ja     19c8 <trace_security_bprm_check+0x19c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19c8;
	}
x86_l_1924:
	/* 0x1924: mov    BYTE PTR [r15+rax*1+0x89],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 588410519556ULL);
x86_l_192d:
	/* 0x192d: movzx  r14d,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1935:
	/* 0x1935: lea    eax,[r14+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1939:
	/* 0x1939: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1941:
	/* 0x1941: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_194a:
	/* 0x194a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_194f:
	/* 0x194f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1954:
	/* 0x1954: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1959:
	/* 0x1959: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_195e:
	/* 0x195e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1961:
	/* 0x1961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1963:
	/* 0x1963: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1969:
	/* 0x1969: je     19ae <trace_security_bprm_check+0x19ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ae;
	}
x86_l_196b:
	/* 0x196b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_196e:
	/* 0x196e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1973:
	/* 0x1973: ja     19ae <trace_security_bprm_check+0x19ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19ae;
	}
x86_l_1975:
	/* 0x1975: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_197a:
	/* 0x197a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1982:
	/* 0x1982: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1986:
	/* 0x1986: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_198d:
	/* 0x198d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1992:
	/* 0x1992: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1997:
	/* 0x1997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1999:
	/* 0x1999: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_199c:
	/* 0x199c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_199e:
	/* 0x199e: jle    19ae <trace_security_bprm_check+0x19ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_19ae;
	}
x86_l_19a0:
	/* 0x19a0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19a3:
	/* 0x19a3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_19a8:
	/* 0x19a8: jbe    3bc1 <trace_security_bprm_check+0x3bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 15297ULL;
	}
x86_l_19ae:
	/* 0x19ae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b0:
	/* 0x19b0: cmp    r14d,0x7cfe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 31998ULL);
x86_l_19b7:
	/* 0x19b7: ja     19c8 <trace_security_bprm_check+0x19c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_19c8;
	}
x86_l_19b9:
	/* 0x19b9: mov    BYTE PTR [r15+r14*1+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 138ULL);
x86_l_19c1:
	/* 0x19c1: inc    BYTE PTR [r15+0x88] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 136ULL);
x86_l_19c8:
	/* 0x19c8: mov    r13,QWORD PTR [r15+0x7dd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32208ULL);
x86_l_19cf:
	/* 0x19cf: lea    r12,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19d3:
	/* 0x19d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19d8:
	/* 0x19d8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19dd:
	/* 0x19dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19e2:
	/* 0x19e2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_19e5:
	/* 0x19e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e7:
	/* 0x19e7: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ec:
	/* 0x19ec: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f1:
	/* 0x19f1: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19f5:
	/* 0x19f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_19fa:
	/* 0x19fa: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ff:
	/* 0x19ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a04:
	/* 0x1a04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a06:
	/* 0x1a06: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a0b:
	/* 0x1a0b: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a14:
	/* 0x1a14: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a19:
	/* 0x1a19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a1e:
	/* 0x1a1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a20:
	/* 0x1a20: mov    rbx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a25:
	/* 0x1a25: lea    rdx,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a29:
	/* 0x1a29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a2e:
	/* 0x1a2e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a33:
	/* 0x1a33: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a38:
	/* 0x1a38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3a:
	/* 0x1a3a: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a3e:
	/* 0x1a3e: mov    DWORD PTR [r15+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a42:
	/* 0x1a42: lea    rbp,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a46:
	/* 0x1a46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a4b:
	/* 0x1a4b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a50:
	/* 0x1a50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1a55:
	/* 0x1a55: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1a58:
	/* 0x1a58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a5a:
	/* 0x1a5a: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a5f:
	/* 0x1a5f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a64:
	/* 0x1a64: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a69:
	/* 0x1a69: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a71:
	/* 0x1a71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a73:
	/* 0x1a73: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a77:
	/* 0x1a77: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1a7b:
	/* 0x1a7b: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a7f:
	/* 0x1a7f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a83:
	/* 0x1a83: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1a88:
	/* 0x1a88: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a8d:
	/* 0x1a8d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1a92:
	/* 0x1a92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a94:
	/* 0x1a94: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a98:
	/* 0x1a98: mov    DWORD PTR [r15+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1aa1:
	/* 0x1aa1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1aa6:
	/* 0x1aa6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1aab:
	/* 0x1aab: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1aae:
	/* 0x1aae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab0:
	/* 0x1ab0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ab5:
	/* 0x1ab5: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1abe:
	/* 0x1abe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ac8:
	/* 0x1ac8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aca:
	/* 0x1aca: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1acf:
	/* 0x1acf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ad4:
	/* 0x1ad4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ad9:
	/* 0x1ad9: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ade:
	/* 0x1ade: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1ae1:
	/* 0x1ae1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae3:
	/* 0x1ae3: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae7:
	/* 0x1ae7: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1aeb:
	/* 0x1aeb: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1aef:
	/* 0x1aef: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1af3:
	/* 0x1af3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1af8:
	/* 0x1af8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1afd:
	/* 0x1afd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b02:
	/* 0x1b02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b04:
	/* 0x1b04: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b08:
	/* 0x1b08: mov    DWORD PTR [r15+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b11:
	/* 0x1b11: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b16:
	/* 0x1b16: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b1b:
	/* 0x1b1b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b1e:
	/* 0x1b1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b20:
	/* 0x1b20: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b25:
	/* 0x1b25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b2a:
	/* 0x1b2a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b34:
	/* 0x1b34: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1b37:
	/* 0x1b37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b39:
	/* 0x1b39: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3d:
	/* 0x1b3d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1b41:
	/* 0x1b41: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1b45:
	/* 0x1b45: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1b49:
	/* 0x1b49: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b4e:
	/* 0x1b4e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b53:
	/* 0x1b53: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b58:
	/* 0x1b58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5a:
	/* 0x1b5a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b5f:
	/* 0x1b5f: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1b63:
	/* 0x1b63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b68:
	/* 0x1b68: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b72:
	/* 0x1b72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b74:
	/* 0x1b74: mov    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b79:
	/* 0x1b79: lea    rbp,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b7d:
	/* 0x1b7d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b82:
	/* 0x1b82: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
	return 7047ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7047ULL: goto x86_l_1b87;
	case 7052ULL: goto x86_l_1b8c;
	case 7055ULL: goto x86_l_1b8f;
	case 7057ULL: goto x86_l_1b91;
	case 7062ULL: goto x86_l_1b96;
	case 7067ULL: goto x86_l_1b9b;
	case 7072ULL: goto x86_l_1ba0;
	case 7077ULL: goto x86_l_1ba5;
	case 7080ULL: goto x86_l_1ba8;
	case 7082ULL: goto x86_l_1baa;
	case 7086ULL: goto x86_l_1bae;
	case 7090ULL: goto x86_l_1bb2;
	case 7094ULL: goto x86_l_1bb6;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7108ULL: goto x86_l_1bc4;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7148ULL: goto x86_l_1bec;
	case 7153ULL: goto x86_l_1bf1;
	case 7158ULL: goto x86_l_1bf6;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7183ULL: goto x86_l_1c0f;
	case 7188ULL: goto x86_l_1c14;
	case 7191ULL: goto x86_l_1c17;
	case 7193ULL: goto x86_l_1c19;
	case 7197ULL: goto x86_l_1c1d;
	case 7201ULL: goto x86_l_1c21;
	case 7205ULL: goto x86_l_1c25;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7219ULL: goto x86_l_1c33;
	case 7224ULL: goto x86_l_1c38;
	case 7226ULL: goto x86_l_1c3a;
	case 7230ULL: goto x86_l_1c3e;
	case 7234ULL: goto x86_l_1c42;
	case 7238ULL: goto x86_l_1c46;
	case 7242ULL: goto x86_l_1c4a;
	case 7249ULL: goto x86_l_1c51;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7264ULL: goto x86_l_1c60;
	case 7267ULL: goto x86_l_1c63;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7278ULL: goto x86_l_1c6e;
	case 7283ULL: goto x86_l_1c73;
	case 7288ULL: goto x86_l_1c78;
	case 7293ULL: goto x86_l_1c7d;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7308ULL: goto x86_l_1c8c;
	case 7313ULL: goto x86_l_1c91;
	case 7315ULL: goto x86_l_1c93;
	case 7318ULL: goto x86_l_1c96;
	case 7322ULL: goto x86_l_1c9a;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7333ULL: goto x86_l_1ca5;
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7347ULL: goto x86_l_1cb3;
	case 7352ULL: goto x86_l_1cb8;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7372ULL: goto x86_l_1ccc;
	case 7377ULL: goto x86_l_1cd1;
	case 7382ULL: goto x86_l_1cd6;
	case 7387ULL: goto x86_l_1cdb;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7398ULL: goto x86_l_1ce6;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7417ULL: goto x86_l_1cf9;
	case 7420ULL: goto x86_l_1cfc;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7431ULL: goto x86_l_1d07;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7446ULL: goto x86_l_1d16;
	case 7449ULL: goto x86_l_1d19;
	case 7451ULL: goto x86_l_1d1b;
	case 7456ULL: goto x86_l_1d20;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7467ULL: goto x86_l_1d2b;
	case 7475ULL: goto x86_l_1d33;
	case 7483ULL: goto x86_l_1d3b;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7495ULL: goto x86_l_1d47;
	case 7500ULL: goto x86_l_1d4c;
	case 7505ULL: goto x86_l_1d51;
	case 7510ULL: goto x86_l_1d56;
	case 7513ULL: goto x86_l_1d59;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7547ULL: goto x86_l_1d7b;
	case 7552ULL: goto x86_l_1d80;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7562ULL: goto x86_l_1d8a;
	case 7565ULL: goto x86_l_1d8d;
	case 7569ULL: goto x86_l_1d91;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7597ULL: goto x86_l_1dad;
	case 7602ULL: goto x86_l_1db2;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7616ULL: goto x86_l_1dc0;
	case 7624ULL: goto x86_l_1dc8;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7656ULL: goto x86_l_1de8;
	case 7664ULL: goto x86_l_1df0;
	case 7669ULL: goto x86_l_1df5;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7683ULL: goto x86_l_1e03;
	case 7687ULL: goto x86_l_1e07;
	case 7692ULL: goto x86_l_1e0c;
	case 7699ULL: goto x86_l_1e13;
	case 7704ULL: goto x86_l_1e18;
	case 7707ULL: goto x86_l_1e1b;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7719ULL: goto x86_l_1e27;
	case 7721ULL: goto x86_l_1e29;
	case 7722ULL: goto x86_l_1e2a;
	case 7727ULL: goto x86_l_1e2f;
	case 7732ULL: goto x86_l_1e34;
	case 7740ULL: goto x86_l_1e3c;
	case 7744ULL: goto x86_l_1e40;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7761ULL: goto x86_l_1e51;
	case 7765ULL: goto x86_l_1e55;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7784ULL: goto x86_l_1e68;
	case 7793ULL: goto x86_l_1e71;
	case 7797ULL: goto x86_l_1e75;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7822ULL: goto x86_l_1e8e;
	case 7828ULL: goto x86_l_1e94;
	case 7831ULL: goto x86_l_1e97;
	case 7836ULL: goto x86_l_1e9c;
	case 7842ULL: goto x86_l_1ea2;
	case 7847ULL: goto x86_l_1ea7;
	case 7855ULL: goto x86_l_1eaf;
	case 7859ULL: goto x86_l_1eb3;
	case 7866ULL: goto x86_l_1eba;
	case 7871ULL: goto x86_l_1ebf;
	case 7876ULL: goto x86_l_1ec4;
	case 7878ULL: goto x86_l_1ec6;
	case 7881ULL: goto x86_l_1ec9;
	case 7883ULL: goto x86_l_1ecb;
	case 7885ULL: goto x86_l_1ecd;
	case 7891ULL: goto x86_l_1ed3;
	case 7894ULL: goto x86_l_1ed6;
	case 7899ULL: goto x86_l_1edb;
	case 7905ULL: goto x86_l_1ee1;
	case 7910ULL: goto x86_l_1ee6;
	case 7918ULL: goto x86_l_1eee;
	case 7922ULL: goto x86_l_1ef2;
	case 7929ULL: goto x86_l_1ef9;
	case 7932ULL: goto x86_l_1efc;
	case 7937ULL: goto x86_l_1f01;
	case 7939ULL: goto x86_l_1f03;
	case 7943ULL: goto x86_l_1f07;
	case 7951ULL: goto x86_l_1f0f;
	case 7954ULL: goto x86_l_1f12;
	case 7962ULL: goto x86_l_1f1a;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7992ULL: goto x86_l_1f38;
	case 7994ULL: goto x86_l_1f3a;
	case 8000ULL: goto x86_l_1f40;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8014ULL: goto x86_l_1f4e;
	case 8020ULL: goto x86_l_1f54;
	case 8025ULL: goto x86_l_1f59;
	case 8033ULL: goto x86_l_1f61;
	case 8037ULL: goto x86_l_1f65;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8054ULL: goto x86_l_1f76;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8061ULL: goto x86_l_1f7d;
	case 8063ULL: goto x86_l_1f7f;
	case 8069ULL: goto x86_l_1f85;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8096ULL: goto x86_l_1fa0;
	case 8100ULL: goto x86_l_1fa4;
	case 8107ULL: goto x86_l_1fab;
	case 8110ULL: goto x86_l_1fae;
	case 8115ULL: goto x86_l_1fb3;
	case 8117ULL: goto x86_l_1fb5;
	case 8121ULL: goto x86_l_1fb9;
	case 8129ULL: goto x86_l_1fc1;
	case 8132ULL: goto x86_l_1fc4;
	case 8140ULL: goto x86_l_1fcc;
	case 8149ULL: goto x86_l_1fd5;
	case 8153ULL: goto x86_l_1fd9;
	case 8158ULL: goto x86_l_1fde;
	case 8163ULL: goto x86_l_1fe3;
	case 8168ULL: goto x86_l_1fe8;
	case 8170ULL: goto x86_l_1fea;
	case 8172ULL: goto x86_l_1fec;
	case 8178ULL: goto x86_l_1ff2;
	case 8184ULL: goto x86_l_1ff8;
	case 8187ULL: goto x86_l_1ffb;
	case 8192ULL: goto x86_l_2000;
	case 8198ULL: goto x86_l_2006;
	case 8203ULL: goto x86_l_200b;
	case 8211ULL: goto x86_l_2013;
	case 8215ULL: goto x86_l_2017;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8232ULL: goto x86_l_2028;
	case 8234ULL: goto x86_l_202a;
	case 8237ULL: goto x86_l_202d;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8247ULL: goto x86_l_2037;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8265ULL: goto x86_l_2049;
	case 8271ULL: goto x86_l_204f;
	case 8276ULL: goto x86_l_2054;
	case 8284ULL: goto x86_l_205c;
	case 8288ULL: goto x86_l_2060;
	case 8295ULL: goto x86_l_2067;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8305ULL: goto x86_l_2071;
	case 8309ULL: goto x86_l_2075;
	case 8317ULL: goto x86_l_207d;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8337ULL: goto x86_l_2091;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8351ULL: goto x86_l_209f;
	case 8356ULL: goto x86_l_20a4;
	case 8358ULL: goto x86_l_20a6;
	case 8360ULL: goto x86_l_20a8;
	case 8366ULL: goto x86_l_20ae;
	case 8372ULL: goto x86_l_20b4;
	case 8375ULL: goto x86_l_20b7;
	case 8380ULL: goto x86_l_20bc;
	case 8385ULL: goto x86_l_20c1;
	case 8390ULL: goto x86_l_20c6;
	case 8396ULL: goto x86_l_20cc;
	case 8401ULL: goto x86_l_20d1;
	case 8409ULL: goto x86_l_20d9;
	case 8413ULL: goto x86_l_20dd;
	case 8420ULL: goto x86_l_20e4;
	case 8425ULL: goto x86_l_20e9;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8437ULL: goto x86_l_20f5;
	case 8439ULL: goto x86_l_20f7;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8458ULL: goto x86_l_210a;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8474ULL: goto x86_l_211a;
	case 8482ULL: goto x86_l_2122;
	case 8486ULL: goto x86_l_2126;
	case 8493ULL: goto x86_l_212d;
	case 8496ULL: goto x86_l_2130;
	case 8501ULL: goto x86_l_2135;
	case 8503ULL: goto x86_l_2137;
	case 8507ULL: goto x86_l_213b;
	case 8515ULL: goto x86_l_2143;
	case 8518ULL: goto x86_l_2146;
	case 8526ULL: goto x86_l_214e;
	case 8535ULL: goto x86_l_2157;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8556ULL: goto x86_l_216c;
	case 8558ULL: goto x86_l_216e;
	case 8564ULL: goto x86_l_2174;
	case 8570ULL: goto x86_l_217a;
	case 8573ULL: goto x86_l_217d;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8607ULL: goto x86_l_219f;
	case 8611ULL: goto x86_l_21a3;
	case 8618ULL: goto x86_l_21aa;
	case 8623ULL: goto x86_l_21af;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8633ULL: goto x86_l_21b9;
	case 8635ULL: goto x86_l_21bb;
	case 8637ULL: goto x86_l_21bd;
	case 8643ULL: goto x86_l_21c3;
	case 8646ULL: goto x86_l_21c6;
	case 8651ULL: goto x86_l_21cb;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8680ULL: goto x86_l_21e8;
	case 8684ULL: goto x86_l_21ec;
	case 8691ULL: goto x86_l_21f3;
	case 8694ULL: goto x86_l_21f6;
	case 8699ULL: goto x86_l_21fb;
	case 8701ULL: goto x86_l_21fd;
	case 8705ULL: goto x86_l_2201;
	case 8713ULL: goto x86_l_2209;
	case 8716ULL: goto x86_l_220c;
	case 8724ULL: goto x86_l_2214;
	case 8733ULL: goto x86_l_221d;
	case 8737ULL: goto x86_l_2221;
	case 8742ULL: goto x86_l_2226;
	case 8747ULL: goto x86_l_222b;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8756ULL: goto x86_l_2234;
	case 8762ULL: goto x86_l_223a;
	case 8768ULL: goto x86_l_2240;
	case 8771ULL: goto x86_l_2243;
	case 8776ULL: goto x86_l_2248;
	case 8781ULL: goto x86_l_224d;
	case 8786ULL: goto x86_l_2252;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b87:
	/* 0x1b87: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b8c:
	/* 0x1b8c: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1b8f:
	/* 0x1b8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b91:
	/* 0x1b91: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b96:
	/* 0x1b96: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1b9b:
	/* 0x1b9b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ba0:
	/* 0x1ba0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1ba8:
	/* 0x1ba8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1baa:
	/* 0x1baa: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bae:
	/* 0x1bae: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1bb2:
	/* 0x1bb2: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1bb6:
	/* 0x1bb6: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1bba:
	/* 0x1bba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bbf:
	/* 0x1bbf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bc9:
	/* 0x1bc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcb:
	/* 0x1bcb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bd0:
	/* 0x1bd0: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bd9:
	/* 0x1bd9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bde:
	/* 0x1bde: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1be3:
	/* 0x1be3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be5:
	/* 0x1be5: cmp    r12d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 32ULL);
x86_l_1bea:
	/* 0x1bea: jne    1c42 <trace_security_bprm_check+0x1c42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c42;
	}
x86_l_1bec:
	/* 0x1bec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bf1:
	/* 0x1bf1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1bfe:
	/* 0x1bfe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c00:
	/* 0x1c00: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c05:
	/* 0x1c05: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c0a:
	/* 0x1c0a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c0f:
	/* 0x1c0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c14:
	/* 0x1c14: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1c17:
	/* 0x1c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c19:
	/* 0x1c19: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c1d:
	/* 0x1c1d: shl    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_1c21:
	/* 0x1c21: lea    rdx,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c25:
	/* 0x1c25: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c29:
	/* 0x1c29: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c2e:
	/* 0x1c2e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c33:
	/* 0x1c33: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c38:
	/* 0x1c38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3a:
	/* 0x1c3a: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    DWORD PTR [r15+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c42:
	/* 0x1c42: lea    rbp,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c46:
	/* 0x1c46: mov    DWORD PTR [r15+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c4a:
	/* 0x1c4a: lea    r12,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c51:
	/* 0x1c51: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c56:
	/* 0x1c56: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c60:
	/* 0x1c60: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c63:
	/* 0x1c63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c65:
	/* 0x1c65: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c6a:
	/* 0x1c6a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1c6e:
	/* 0x1c6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c73:
	/* 0x1c73: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c78:
	/* 0x1c78: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c7d:
	/* 0x1c7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7f:
	/* 0x1c7f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1c84:
	/* 0x1c84: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c89:
	/* 0x1c89: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c8c:
	/* 0x1c8c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c91:
	/* 0x1c91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c93:
	/* 0x1c93: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c96:
	/* 0x1c96: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_1c9f:
	/* 0x1c9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca1:
	/* 0x1ca1: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ca5:
	/* 0x1ca5: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cae:
	/* 0x1cae: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cb3:
	/* 0x1cb3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cb8:
	/* 0x1cb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cba:
	/* 0x1cba: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc8:
	/* 0x1cc8: add    rdx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1ccc:
	/* 0x1ccc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cd1:
	/* 0x1cd1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd6:
	/* 0x1cd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cdb:
	/* 0x1cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cdd:
	/* 0x1cdd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    QWORD PTR [r15+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ce6:
	/* 0x1ce6: add    rbx,0x50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 80ULL);
x86_l_1cea:
	/* 0x1cea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1cef:
	/* 0x1cef: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cf4:
	/* 0x1cf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cf9:
	/* 0x1cf9: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1cfc:
	/* 0x1cfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cfe:
	/* 0x1cfe: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d03:
	/* 0x1d03: mov    QWORD PTR [r15+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d07:
	/* 0x1d07: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d0c:
	/* 0x1d0c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d11:
	/* 0x1d11: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d16:
	/* 0x1d16: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d19:
	/* 0x1d19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1b:
	/* 0x1d1b: test   BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_1d20:
	/* 0x1d20: je     1d27 <trace_security_bprm_check+0x1d27> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d27;
	}
x86_l_1d22:
	/* 0x1d22: or     BYTE PTR [r15+0x5c],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 395136991234ULL);
x86_l_1d27:
	/* 0x1d27: lea    rdi,[r15+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1d2b:
	/* 0x1d2b: mov    QWORD PTR [r15+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1d33:
	/* 0x1d33: mov    QWORD PTR [r15+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1d3b:
	/* 0x1d3b: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1d40:
	/* 0x1d40: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d45:
	/* 0x1d45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d47:
	/* 0x1d47: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d4c:
	/* 0x1d4c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d51:
	/* 0x1d51: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d56:
	/* 0x1d56: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1d59:
	/* 0x1d59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d5b:
	/* 0x1d5b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d60:
	/* 0x1d60: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d65:
	/* 0x1d65: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d6f:
	/* 0x1d6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d71:
	/* 0x1d71: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d76:
	/* 0x1d76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d7b:
	/* 0x1d7b: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d80:
	/* 0x1d80: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d83:
	/* 0x1d83: mov    esi,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65ULL);
x86_l_1d88:
	/* 0x1d88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8a:
	/* 0x1d8a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d8d:
	/* 0x1d8d: add    rdi,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1d91:
	/* 0x1d91: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1d96:
	/* 0x1d96: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1d9e:
	/* 0x1d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da0:
	/* 0x1da0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1da5:
	/* 0x1da5: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dad:
	/* 0x1dad: mov    esi,0x68 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 104ULL);
x86_l_1db2:
	/* 0x1db2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1db5:
	/* 0x1db5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1db7:
	/* 0x1db7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dbc:
	/* 0x1dbc: test   BYTE PTR [rax+0x4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869192ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    rbx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dc8:
	/* 0x1dc8: je     1de8 <trace_security_bprm_check+0x1de8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1de8;
	}
x86_l_1dca:
	/* 0x1dca: mov    eax,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&stack_addresses)));
x86_l_1dd6:
	/* 0x1dd6: mov    edx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dde:
	/* 0x1dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de0:
	/* 0x1de0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1de2:
	/* 0x1de2: js     1de8 <trace_security_bprm_check+0x1de8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1de8;
	}
x86_l_1de4:
	/* 0x1de4: mov    DWORD PTR [r15+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1de8:
	/* 0x1de8: movzx  eax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1df0:
	/* 0x1df0: cmp    eax,0x7d00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 32000ULL);
x86_l_1df5:
	/* 0x1df5: mov    ecx,0x7d00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32000ULL);
x86_l_1dfa:
	/* 0x1dfa: cmovb  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1dfd:
	/* 0x1dfd: add    ecx,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 137ULL);
x86_l_1e03:
	/* 0x1e03: movzx  r8d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e07:
	/* 0x1e07: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e0c:
	/* 0x1e0c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_1e13:
	/* 0x1e13: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1e18:
	/* 0x1e18: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e1b:
	/* 0x1e1b: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1e1e:
	/* 0x1e1e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e20:
	/* 0x1e20: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_1e27:
	/* 0x1e27: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1e29:
	/* 0x1e29: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1e2a:
	/* 0x1e2a: jmp    6c2e <trace_security_bprm_check+0x6c2e> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1e2f:
	/* 0x1e2f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e34:
	/* 0x1e34: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1e3c:
	/* 0x1e3c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1e40:
	/* 0x1e40: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1e47:
	/* 0x1e47: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1e4a:
	/* 0x1e4a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e4f:
	/* 0x1e4f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e51:
	/* 0x1e51: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e55:
	/* 0x1e55: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1e5d:
	/* 0x1e5d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1e60:
	/* 0x1e60: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1e68:
	/* 0x1e68: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e71:
	/* 0x1e71: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e75:
	/* 0x1e75: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e7a:
	/* 0x1e7a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e84:
	/* 0x1e84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e86:
	/* 0x1e86: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1e88:
	/* 0x1e88: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1e8e:
	/* 0x1e8e: je     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6385ULL;
	}
x86_l_1e94:
	/* 0x1e94: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e97:
	/* 0x1e97: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1e9c:
	/* 0x1e9c: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_1ea2:
	/* 0x1ea2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1ea7:
	/* 0x1ea7: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1eaf:
	/* 0x1eaf: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1eb3:
	/* 0x1eb3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1eba:
	/* 0x1eba: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ebf:
	/* 0x1ebf: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1ec4:
	/* 0x1ec4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec6:
	/* 0x1ec6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec9:
	/* 0x1ec9: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1ecb:
	/* 0x1ecb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ecd:
	/* 0x1ecd: jle    18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6385ULL;
	}
x86_l_1ed3:
	/* 0x1ed3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ed6:
	/* 0x1ed6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1edb:
	/* 0x1edb: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_1ee1:
	/* 0x1ee1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ee6:
	/* 0x1ee6: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1eee:
	/* 0x1eee: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1ef2:
	/* 0x1ef2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1ef9:
	/* 0x1ef9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1efc:
	/* 0x1efc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1f01:
	/* 0x1f01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f03:
	/* 0x1f03: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f07:
	/* 0x1f07: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1f0f:
	/* 0x1f0f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1f12:
	/* 0x1f12: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1f1a:
	/* 0x1f1a: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1f23:
	/* 0x1f23: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f27:
	/* 0x1f27: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f2c:
	/* 0x1f2c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f31:
	/* 0x1f31: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f36:
	/* 0x1f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f38:
	/* 0x1f38: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1f3a:
	/* 0x1f3a: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1f40:
	/* 0x1f40: je     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6385ULL;
	}
x86_l_1f46:
	/* 0x1f46: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f49:
	/* 0x1f49: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_1f4e:
	/* 0x1f4e: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_1f54:
	/* 0x1f54: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1f59:
	/* 0x1f59: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1f61:
	/* 0x1f61: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1f65:
	/* 0x1f65: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f71:
	/* 0x1f71: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1f76:
	/* 0x1f76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f78:
	/* 0x1f78: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1f7d:
	/* 0x1f7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f7f:
	/* 0x1f7f: jle    18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6385ULL;
	}
x86_l_1f85:
	/* 0x1f85: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f88:
	/* 0x1f88: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_1f8d:
	/* 0x1f8d: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_1f93:
	/* 0x1f93: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f98:
	/* 0x1f98: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_1fa0:
	/* 0x1fa0: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1fa4:
	/* 0x1fa4: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_1fab:
	/* 0x1fab: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1fae:
	/* 0x1fae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1fb3:
	/* 0x1fb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb5:
	/* 0x1fb5: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fb9:
	/* 0x1fb9: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_1fc1:
	/* 0x1fc1: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1fd5:
	/* 0x1fd5: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fd9:
	/* 0x1fd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fde:
	/* 0x1fde: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fe3:
	/* 0x1fe3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fe8:
	/* 0x1fe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fea:
	/* 0x1fea: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1fec:
	/* 0x1fec: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ff2:
	/* 0x1ff2: je     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6385ULL;
	}
x86_l_1ff8:
	/* 0x1ff8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ffb:
	/* 0x1ffb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2000:
	/* 0x2000: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2006:
	/* 0x2006: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_200b:
	/* 0x200b: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2013:
	/* 0x2013: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2017:
	/* 0x2017: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_201e:
	/* 0x201e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2023:
	/* 0x2023: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2028:
	/* 0x2028: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202a:
	/* 0x202a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202d:
	/* 0x202d: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_202f:
	/* 0x202f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2031:
	/* 0x2031: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2037:
	/* 0x2037: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_203a:
	/* 0x203a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_203f:
	/* 0x203f: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2044:
	/* 0x2044: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2049:
	/* 0x2049: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_204f:
	/* 0x204f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2054:
	/* 0x2054: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_205c:
	/* 0x205c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2060:
	/* 0x2060: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2067:
	/* 0x2067: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_206a:
	/* 0x206a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_206f:
	/* 0x206f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2071:
	/* 0x2071: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2075:
	/* 0x2075: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_207d:
	/* 0x207d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2080:
	/* 0x2080: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2088:
	/* 0x2088: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2091:
	/* 0x2091: lea    rdx,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2095:
	/* 0x2095: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_209a:
	/* 0x209a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_209f:
	/* 0x209f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_20a4:
	/* 0x20a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a6:
	/* 0x20a6: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_20a8:
	/* 0x20a8: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_20ae:
	/* 0x20ae: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_20b4:
	/* 0x20b4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_20b7:
	/* 0x20b7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_20bc:
	/* 0x20bc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20c1:
	/* 0x20c1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c6:
	/* 0x20c6: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_20cc:
	/* 0x20cc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_20d1:
	/* 0x20d1: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_20d9:
	/* 0x20d9: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_20dd:
	/* 0x20dd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_20e4:
	/* 0x20e4: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20e9:
	/* 0x20e9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_20ee:
	/* 0x20ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f0:
	/* 0x20f0: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f3:
	/* 0x20f3: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_20f5:
	/* 0x20f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20f7:
	/* 0x20f7: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_20fd:
	/* 0x20fd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2100:
	/* 0x2100: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2105:
	/* 0x2105: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_210a:
	/* 0x210a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_210f:
	/* 0x210f: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2115:
	/* 0x2115: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_211a:
	/* 0x211a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2122:
	/* 0x2122: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2126:
	/* 0x2126: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_212d:
	/* 0x212d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2130:
	/* 0x2130: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2135:
	/* 0x2135: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2137:
	/* 0x2137: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_213b:
	/* 0x213b: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2143:
	/* 0x2143: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2146:
	/* 0x2146: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_214e:
	/* 0x214e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2157:
	/* 0x2157: lea    rdx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_215b:
	/* 0x215b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2160:
	/* 0x2160: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2165:
	/* 0x2165: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_216a:
	/* 0x216a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216c:
	/* 0x216c: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_216e:
	/* 0x216e: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2174:
	/* 0x2174: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_217a:
	/* 0x217a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_217d:
	/* 0x217d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2182:
	/* 0x2182: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2187:
	/* 0x2187: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_218c:
	/* 0x218c: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2192:
	/* 0x2192: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2197:
	/* 0x2197: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_219f:
	/* 0x219f: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_21a3:
	/* 0x21a3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_21aa:
	/* 0x21aa: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21af:
	/* 0x21af: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_21b4:
	/* 0x21b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21b6:
	/* 0x21b6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b9:
	/* 0x21b9: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_21bb:
	/* 0x21bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21bd:
	/* 0x21bd: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_21c3:
	/* 0x21c3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_21c6:
	/* 0x21c6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_21cb:
	/* 0x21cb: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21d0:
	/* 0x21d0: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21d5:
	/* 0x21d5: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_21db:
	/* 0x21db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21e0:
	/* 0x21e0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_21e8:
	/* 0x21e8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_21ec:
	/* 0x21ec: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_21f3:
	/* 0x21f3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_21f6:
	/* 0x21f6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_21fb:
	/* 0x21fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21fd:
	/* 0x21fd: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2201:
	/* 0x2201: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2209:
	/* 0x2209: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_220c:
	/* 0x220c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2214:
	/* 0x2214: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_221d:
	/* 0x221d: lea    rdx,[r13+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2221:
	/* 0x2221: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2226:
	/* 0x2226: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_222b:
	/* 0x222b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2230:
	/* 0x2230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2232:
	/* 0x2232: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_2234:
	/* 0x2234: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_223a:
	/* 0x223a: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2240:
	/* 0x2240: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2243:
	/* 0x2243: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2248:
	/* 0x2248: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224d:
	/* 0x224d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2252:
	/* 0x2252: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2258:
	/* 0x2258: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_225d:
	/* 0x225d: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
	return 8805ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8805ULL: goto x86_l_2265;
	case 8809ULL: goto x86_l_2269;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8859ULL: goto x86_l_229b;
	case 8865ULL: goto x86_l_22a1;
	case 8870ULL: goto x86_l_22a6;
	case 8878ULL: goto x86_l_22ae;
	case 8882ULL: goto x86_l_22b2;
	case 8889ULL: goto x86_l_22b9;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8911ULL: goto x86_l_22cf;
	case 8914ULL: goto x86_l_22d2;
	case 8922ULL: goto x86_l_22da;
	case 8931ULL: goto x86_l_22e3;
	case 8935ULL: goto x86_l_22e7;
	case 8940ULL: goto x86_l_22ec;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8954ULL: goto x86_l_22fa;
	case 8960ULL: goto x86_l_2300;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8974ULL: goto x86_l_230e;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8990ULL: goto x86_l_231e;
	case 8995ULL: goto x86_l_2323;
	case 9003ULL: goto x86_l_232b;
	case 9007ULL: goto x86_l_232f;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9026ULL: goto x86_l_2342;
	case 9029ULL: goto x86_l_2345;
	case 9031ULL: goto x86_l_2347;
	case 9033ULL: goto x86_l_2349;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9047ULL: goto x86_l_2357;
	case 9052ULL: goto x86_l_235c;
	case 9057ULL: goto x86_l_2361;
	case 9063ULL: goto x86_l_2367;
	case 9068ULL: goto x86_l_236c;
	case 9076ULL: goto x86_l_2374;
	case 9080ULL: goto x86_l_2378;
	case 9087ULL: goto x86_l_237f;
	case 9090ULL: goto x86_l_2382;
	case 9095ULL: goto x86_l_2387;
	case 9097ULL: goto x86_l_2389;
	case 9101ULL: goto x86_l_238d;
	case 9109ULL: goto x86_l_2395;
	case 9112ULL: goto x86_l_2398;
	case 9120ULL: goto x86_l_23a0;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9138ULL: goto x86_l_23b2;
	case 9143ULL: goto x86_l_23b7;
	case 9148ULL: goto x86_l_23bc;
	case 9150ULL: goto x86_l_23be;
	case 9152ULL: goto x86_l_23c0;
	case 9158ULL: goto x86_l_23c6;
	case 9164ULL: goto x86_l_23cc;
	case 9167ULL: goto x86_l_23cf;
	case 9172ULL: goto x86_l_23d4;
	case 9177ULL: goto x86_l_23d9;
	case 9182ULL: goto x86_l_23de;
	case 9188ULL: goto x86_l_23e4;
	case 9193ULL: goto x86_l_23e9;
	case 9201ULL: goto x86_l_23f1;
	case 9205ULL: goto x86_l_23f5;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9222ULL: goto x86_l_2406;
	case 9224ULL: goto x86_l_2408;
	case 9227ULL: goto x86_l_240b;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9237ULL: goto x86_l_2415;
	case 9240ULL: goto x86_l_2418;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9274ULL: goto x86_l_243a;
	case 9278ULL: goto x86_l_243e;
	case 9285ULL: goto x86_l_2445;
	case 9288ULL: goto x86_l_2448;
	case 9293ULL: goto x86_l_244d;
	case 9295ULL: goto x86_l_244f;
	case 9299ULL: goto x86_l_2453;
	case 9307ULL: goto x86_l_245b;
	case 9310ULL: goto x86_l_245e;
	case 9318ULL: goto x86_l_2466;
	case 9327ULL: goto x86_l_246f;
	case 9331ULL: goto x86_l_2473;
	case 9336ULL: goto x86_l_2478;
	case 9341ULL: goto x86_l_247d;
	case 9346ULL: goto x86_l_2482;
	case 9348ULL: goto x86_l_2484;
	case 9350ULL: goto x86_l_2486;
	case 9356ULL: goto x86_l_248c;
	case 9362ULL: goto x86_l_2492;
	case 9365ULL: goto x86_l_2495;
	case 9370ULL: goto x86_l_249a;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9386ULL: goto x86_l_24aa;
	case 9391ULL: goto x86_l_24af;
	case 9399ULL: goto x86_l_24b7;
	case 9403ULL: goto x86_l_24bb;
	case 9410ULL: goto x86_l_24c2;
	case 9415ULL: goto x86_l_24c7;
	case 9420ULL: goto x86_l_24cc;
	case 9422ULL: goto x86_l_24ce;
	case 9425ULL: goto x86_l_24d1;
	case 9427ULL: goto x86_l_24d3;
	case 9429ULL: goto x86_l_24d5;
	case 9435ULL: goto x86_l_24db;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9448ULL: goto x86_l_24e8;
	case 9453ULL: goto x86_l_24ed;
	case 9459ULL: goto x86_l_24f3;
	case 9464ULL: goto x86_l_24f8;
	case 9472ULL: goto x86_l_2500;
	case 9476ULL: goto x86_l_2504;
	case 9483ULL: goto x86_l_250b;
	case 9486ULL: goto x86_l_250e;
	case 9491ULL: goto x86_l_2513;
	case 9493ULL: goto x86_l_2515;
	case 9497ULL: goto x86_l_2519;
	case 9505ULL: goto x86_l_2521;
	case 9508ULL: goto x86_l_2524;
	case 9516ULL: goto x86_l_252c;
	case 9525ULL: goto x86_l_2535;
	case 9529ULL: goto x86_l_2539;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9560ULL: goto x86_l_2558;
	case 9563ULL: goto x86_l_255b;
	case 9568ULL: goto x86_l_2560;
	case 9573ULL: goto x86_l_2565;
	case 9578ULL: goto x86_l_256a;
	case 9584ULL: goto x86_l_2570;
	case 9589ULL: goto x86_l_2575;
	case 9597ULL: goto x86_l_257d;
	case 9601ULL: goto x86_l_2581;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9618ULL: goto x86_l_2592;
	case 9620ULL: goto x86_l_2594;
	case 9623ULL: goto x86_l_2597;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9651ULL: goto x86_l_25b3;
	case 9657ULL: goto x86_l_25b9;
	case 9662ULL: goto x86_l_25be;
	case 9670ULL: goto x86_l_25c6;
	case 9674ULL: goto x86_l_25ca;
	case 9681ULL: goto x86_l_25d1;
	case 9684ULL: goto x86_l_25d4;
	case 9689ULL: goto x86_l_25d9;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9703ULL: goto x86_l_25e7;
	case 9706ULL: goto x86_l_25ea;
	case 9714ULL: goto x86_l_25f2;
	case 9723ULL: goto x86_l_25fb;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9746ULL: goto x86_l_2612;
	case 9752ULL: goto x86_l_2618;
	case 9758ULL: goto x86_l_261e;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9771ULL: goto x86_l_262b;
	case 9776ULL: goto x86_l_2630;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9795ULL: goto x86_l_2643;
	case 9799ULL: goto x86_l_2647;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9816ULL: goto x86_l_2658;
	case 9818ULL: goto x86_l_265a;
	case 9821ULL: goto x86_l_265d;
	case 9823ULL: goto x86_l_265f;
	case 9825ULL: goto x86_l_2661;
	case 9831ULL: goto x86_l_2667;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9855ULL: goto x86_l_267f;
	case 9860ULL: goto x86_l_2684;
	case 9868ULL: goto x86_l_268c;
	case 9872ULL: goto x86_l_2690;
	case 9879ULL: goto x86_l_2697;
	case 9882ULL: goto x86_l_269a;
	case 9887ULL: goto x86_l_269f;
	case 9889ULL: goto x86_l_26a1;
	case 9893ULL: goto x86_l_26a5;
	case 9901ULL: goto x86_l_26ad;
	case 9904ULL: goto x86_l_26b0;
	case 9912ULL: goto x86_l_26b8;
	case 9921ULL: goto x86_l_26c1;
	case 9925ULL: goto x86_l_26c5;
	case 9930ULL: goto x86_l_26ca;
	case 9935ULL: goto x86_l_26cf;
	case 9940ULL: goto x86_l_26d4;
	case 9942ULL: goto x86_l_26d6;
	case 9944ULL: goto x86_l_26d8;
	case 9950ULL: goto x86_l_26de;
	case 9956ULL: goto x86_l_26e4;
	case 9959ULL: goto x86_l_26e7;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9974ULL: goto x86_l_26f6;
	case 9980ULL: goto x86_l_26fc;
	case 9985ULL: goto x86_l_2701;
	case 9993ULL: goto x86_l_2709;
	case 9997ULL: goto x86_l_270d;
	case 10004ULL: goto x86_l_2714;
	case 10009ULL: goto x86_l_2719;
	case 10014ULL: goto x86_l_271e;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10021ULL: goto x86_l_2725;
	case 10023ULL: goto x86_l_2727;
	case 10029ULL: goto x86_l_272d;
	case 10032ULL: goto x86_l_2730;
	case 10037ULL: goto x86_l_2735;
	case 10042ULL: goto x86_l_273a;
	case 10047ULL: goto x86_l_273f;
	case 10053ULL: goto x86_l_2745;
	case 10058ULL: goto x86_l_274a;
	case 10066ULL: goto x86_l_2752;
	case 10070ULL: goto x86_l_2756;
	case 10077ULL: goto x86_l_275d;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10087ULL: goto x86_l_2767;
	case 10091ULL: goto x86_l_276b;
	case 10099ULL: goto x86_l_2773;
	case 10102ULL: goto x86_l_2776;
	case 10110ULL: goto x86_l_277e;
	case 10119ULL: goto x86_l_2787;
	case 10123ULL: goto x86_l_278b;
	case 10128ULL: goto x86_l_2790;
	case 10133ULL: goto x86_l_2795;
	case 10138ULL: goto x86_l_279a;
	case 10140ULL: goto x86_l_279c;
	case 10142ULL: goto x86_l_279e;
	case 10148ULL: goto x86_l_27a4;
	case 10154ULL: goto x86_l_27aa;
	case 10157ULL: goto x86_l_27ad;
	case 10162ULL: goto x86_l_27b2;
	case 10167ULL: goto x86_l_27b7;
	case 10172ULL: goto x86_l_27bc;
	case 10178ULL: goto x86_l_27c2;
	case 10183ULL: goto x86_l_27c7;
	case 10191ULL: goto x86_l_27cf;
	case 10195ULL: goto x86_l_27d3;
	case 10202ULL: goto x86_l_27da;
	case 10207ULL: goto x86_l_27df;
	case 10212ULL: goto x86_l_27e4;
	case 10214ULL: goto x86_l_27e6;
	case 10217ULL: goto x86_l_27e9;
	case 10219ULL: goto x86_l_27eb;
	case 10221ULL: goto x86_l_27ed;
	case 10227ULL: goto x86_l_27f3;
	case 10230ULL: goto x86_l_27f6;
	case 10235ULL: goto x86_l_27fb;
	case 10240ULL: goto x86_l_2800;
	case 10245ULL: goto x86_l_2805;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10264ULL: goto x86_l_2818;
	case 10268ULL: goto x86_l_281c;
	case 10275ULL: goto x86_l_2823;
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10285ULL: goto x86_l_282d;
	case 10289ULL: goto x86_l_2831;
	case 10297ULL: goto x86_l_2839;
	case 10300ULL: goto x86_l_283c;
	case 10308ULL: goto x86_l_2844;
	case 10317ULL: goto x86_l_284d;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10336ULL: goto x86_l_2860;
	case 10338ULL: goto x86_l_2862;
	case 10340ULL: goto x86_l_2864;
	case 10346ULL: goto x86_l_286a;
	case 10352ULL: goto x86_l_2870;
	case 10355ULL: goto x86_l_2873;
	case 10360ULL: goto x86_l_2878;
	case 10365ULL: goto x86_l_287d;
	case 10370ULL: goto x86_l_2882;
	case 10376ULL: goto x86_l_2888;
	case 10381ULL: goto x86_l_288d;
	case 10389ULL: goto x86_l_2895;
	case 10393ULL: goto x86_l_2899;
	case 10400ULL: goto x86_l_28a0;
	case 10405ULL: goto x86_l_28a5;
	case 10410ULL: goto x86_l_28aa;
	case 10412ULL: goto x86_l_28ac;
	case 10415ULL: goto x86_l_28af;
	case 10417ULL: goto x86_l_28b1;
	case 10419ULL: goto x86_l_28b3;
	case 10425ULL: goto x86_l_28b9;
	case 10428ULL: goto x86_l_28bc;
	case 10433ULL: goto x86_l_28c1;
	case 10438ULL: goto x86_l_28c6;
	case 10443ULL: goto x86_l_28cb;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10462ULL: goto x86_l_28de;
	case 10466ULL: goto x86_l_28e2;
	case 10473ULL: goto x86_l_28e9;
	case 10476ULL: goto x86_l_28ec;
	case 10481ULL: goto x86_l_28f1;
	case 10483ULL: goto x86_l_28f3;
	case 10487ULL: goto x86_l_28f7;
	case 10495ULL: goto x86_l_28ff;
	case 10498ULL: goto x86_l_2902;
	case 10506ULL: goto x86_l_290a;
	case 10515ULL: goto x86_l_2913;
	case 10519ULL: goto x86_l_2917;
	case 10524ULL: goto x86_l_291c;
	case 10529ULL: goto x86_l_2921;
	case 10534ULL: goto x86_l_2926;
	case 10536ULL: goto x86_l_2928;
	case 10538ULL: goto x86_l_292a;
	case 10544ULL: goto x86_l_2930;
	case 10550ULL: goto x86_l_2936;
	case 10553ULL: goto x86_l_2939;
	case 10558ULL: goto x86_l_293e;
	case 10563ULL: goto x86_l_2943;
	case 10568ULL: goto x86_l_2948;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10587ULL: goto x86_l_295b;
	case 10591ULL: goto x86_l_295f;
	case 10598ULL: goto x86_l_2966;
	case 10603ULL: goto x86_l_296b;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10613ULL: goto x86_l_2975;
	case 10615ULL: goto x86_l_2977;
	case 10617ULL: goto x86_l_2979;
	case 10623ULL: goto x86_l_297f;
	case 10626ULL: goto x86_l_2982;
	case 10631ULL: goto x86_l_2987;
	case 10636ULL: goto x86_l_298c;
	case 10641ULL: goto x86_l_2991;
	case 10647ULL: goto x86_l_2997;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2265:
	/* 0x2265: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2269:
	/* 0x2269: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2270:
	/* 0x2270: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2275:
	/* 0x2275: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_227a:
	/* 0x227a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227c:
	/* 0x227c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227f:
	/* 0x227f: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_2281:
	/* 0x2281: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2283:
	/* 0x2283: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2289:
	/* 0x2289: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_228c:
	/* 0x228c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2291:
	/* 0x2291: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2296:
	/* 0x2296: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229b:
	/* 0x229b: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_22a1:
	/* 0x22a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22a6:
	/* 0x22a6: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_22ae:
	/* 0x22ae: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_22b2:
	/* 0x22b2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_22b9:
	/* 0x22b9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_22bc:
	/* 0x22bc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_22c1:
	/* 0x22c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c3:
	/* 0x22c3: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22c7:
	/* 0x22c7: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_22cf:
	/* 0x22cf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_22d2:
	/* 0x22d2: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_22da:
	/* 0x22da: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_22e3:
	/* 0x22e3: lea    rdx,[r13+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22e7:
	/* 0x22e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ec:
	/* 0x22ec: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22f1:
	/* 0x22f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22f6:
	/* 0x22f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22f8:
	/* 0x22f8: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_22fa:
	/* 0x22fa: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2300:
	/* 0x2300: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2306:
	/* 0x2306: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2309:
	/* 0x2309: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_230e:
	/* 0x230e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2313:
	/* 0x2313: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2318:
	/* 0x2318: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_231e:
	/* 0x231e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2323:
	/* 0x2323: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_232b:
	/* 0x232b: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_232f:
	/* 0x232f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2336:
	/* 0x2336: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_233b:
	/* 0x233b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2340:
	/* 0x2340: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2342:
	/* 0x2342: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2345:
	/* 0x2345: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_2347:
	/* 0x2347: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2349:
	/* 0x2349: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_234f:
	/* 0x234f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2352:
	/* 0x2352: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2357:
	/* 0x2357: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235c:
	/* 0x235c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2361:
	/* 0x2361: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2367:
	/* 0x2367: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_236c:
	/* 0x236c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2374:
	/* 0x2374: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2378:
	/* 0x2378: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_237f:
	/* 0x237f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2382:
	/* 0x2382: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2387:
	/* 0x2387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2389:
	/* 0x2389: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_238d:
	/* 0x238d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2395:
	/* 0x2395: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2398:
	/* 0x2398: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_23a0:
	/* 0x23a0: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_23a9:
	/* 0x23a9: lea    rdx,[r13+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23ad:
	/* 0x23ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b2:
	/* 0x23b2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23b7:
	/* 0x23b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23bc:
	/* 0x23bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23be:
	/* 0x23be: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_23c0:
	/* 0x23c0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_23c6:
	/* 0x23c6: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_23cc:
	/* 0x23cc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23cf:
	/* 0x23cf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_23d4:
	/* 0x23d4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d9:
	/* 0x23d9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23de:
	/* 0x23de: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_23e4:
	/* 0x23e4: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_23e9:
	/* 0x23e9: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_23f1:
	/* 0x23f1: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_23f5:
	/* 0x23f5: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_23fc:
	/* 0x23fc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2401:
	/* 0x2401: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2406:
	/* 0x2406: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2408:
	/* 0x2408: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240b:
	/* 0x240b: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_240d:
	/* 0x240d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_240f:
	/* 0x240f: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2415:
	/* 0x2415: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2418:
	/* 0x2418: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_241d:
	/* 0x241d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2422:
	/* 0x2422: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2427:
	/* 0x2427: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_242d:
	/* 0x242d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2432:
	/* 0x2432: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_243a:
	/* 0x243a: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_243e:
	/* 0x243e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2445:
	/* 0x2445: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2448:
	/* 0x2448: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_244d:
	/* 0x244d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244f:
	/* 0x244f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2453:
	/* 0x2453: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_245b:
	/* 0x245b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_245e:
	/* 0x245e: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2466:
	/* 0x2466: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_246f:
	/* 0x246f: lea    rdx,[r13+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2473:
	/* 0x2473: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2478:
	/* 0x2478: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_247d:
	/* 0x247d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2482:
	/* 0x2482: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2484:
	/* 0x2484: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_2486:
	/* 0x2486: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_248c:
	/* 0x248c: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2492:
	/* 0x2492: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2495:
	/* 0x2495: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_249a:
	/* 0x249a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_249f:
	/* 0x249f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a4:
	/* 0x24a4: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_24aa:
	/* 0x24aa: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_24af:
	/* 0x24af: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_24b7:
	/* 0x24b7: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_24bb:
	/* 0x24bb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_24c2:
	/* 0x24c2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24c7:
	/* 0x24c7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_24cc:
	/* 0x24cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24ce:
	/* 0x24ce: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24d1:
	/* 0x24d1: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_24d3:
	/* 0x24d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24d5:
	/* 0x24d5: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_24db:
	/* 0x24db: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24de:
	/* 0x24de: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_24e3:
	/* 0x24e3: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24e8:
	/* 0x24e8: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ed:
	/* 0x24ed: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_24f3:
	/* 0x24f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24f8:
	/* 0x24f8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2500:
	/* 0x2500: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2504:
	/* 0x2504: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_250b:
	/* 0x250b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_250e:
	/* 0x250e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2513:
	/* 0x2513: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2515:
	/* 0x2515: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2519:
	/* 0x2519: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2521:
	/* 0x2521: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2524:
	/* 0x2524: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_252c:
	/* 0x252c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2535:
	/* 0x2535: lea    rdx,[r13+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2539:
	/* 0x2539: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_253e:
	/* 0x253e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2543:
	/* 0x2543: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2548:
	/* 0x2548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_254a:
	/* 0x254a: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_254c:
	/* 0x254c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2552:
	/* 0x2552: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2558:
	/* 0x2558: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_255b:
	/* 0x255b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2560:
	/* 0x2560: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2565:
	/* 0x2565: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256a:
	/* 0x256a: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2570:
	/* 0x2570: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2575:
	/* 0x2575: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_257d:
	/* 0x257d: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2581:
	/* 0x2581: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2588:
	/* 0x2588: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258d:
	/* 0x258d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2592:
	/* 0x2592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2594:
	/* 0x2594: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2597:
	/* 0x2597: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_2599:
	/* 0x2599: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_259b:
	/* 0x259b: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_25a1:
	/* 0x25a1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25a4:
	/* 0x25a4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_25a9:
	/* 0x25a9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ae:
	/* 0x25ae: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25b3:
	/* 0x25b3: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_25b9:
	/* 0x25b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25be:
	/* 0x25be: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_25c6:
	/* 0x25c6: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_25ca:
	/* 0x25ca: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_25d1:
	/* 0x25d1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_25d4:
	/* 0x25d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_25d9:
	/* 0x25d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25db:
	/* 0x25db: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25df:
	/* 0x25df: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_25e7:
	/* 0x25e7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_25ea:
	/* 0x25ea: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_25f2:
	/* 0x25f2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_25fb:
	/* 0x25fb: lea    rdx,[r13+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25ff:
	/* 0x25ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2604:
	/* 0x2604: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2609:
	/* 0x2609: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_260e:
	/* 0x260e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2610:
	/* 0x2610: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_2612:
	/* 0x2612: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2618:
	/* 0x2618: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_261e:
	/* 0x261e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2621:
	/* 0x2621: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2626:
	/* 0x2626: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_262b:
	/* 0x262b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2630:
	/* 0x2630: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2636:
	/* 0x2636: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_263b:
	/* 0x263b: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2643:
	/* 0x2643: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2647:
	/* 0x2647: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_264e:
	/* 0x264e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2653:
	/* 0x2653: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2658:
	/* 0x2658: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265a:
	/* 0x265a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265d:
	/* 0x265d: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_265f:
	/* 0x265f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2661:
	/* 0x2661: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2667:
	/* 0x2667: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_266a:
	/* 0x266a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_266f:
	/* 0x266f: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2674:
	/* 0x2674: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2679:
	/* 0x2679: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_267f:
	/* 0x267f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2684:
	/* 0x2684: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_268c:
	/* 0x268c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2690:
	/* 0x2690: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2697:
	/* 0x2697: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_269a:
	/* 0x269a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_269f:
	/* 0x269f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26a1:
	/* 0x26a1: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26a5:
	/* 0x26a5: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_26ad:
	/* 0x26ad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_26b0:
	/* 0x26b0: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_26b8:
	/* 0x26b8: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_26c1:
	/* 0x26c1: lea    rdx,[r13+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_26c5:
	/* 0x26c5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26ca:
	/* 0x26ca: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26cf:
	/* 0x26cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_26d4:
	/* 0x26d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d6:
	/* 0x26d6: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_26d8:
	/* 0x26d8: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_26de:
	/* 0x26de: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_26e4:
	/* 0x26e4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_26e7:
	/* 0x26e7: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_26ec:
	/* 0x26ec: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f1:
	/* 0x26f1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26f6:
	/* 0x26f6: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_26fc:
	/* 0x26fc: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2701:
	/* 0x2701: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2709:
	/* 0x2709: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_270d:
	/* 0x270d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2714:
	/* 0x2714: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2719:
	/* 0x2719: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_271e:
	/* 0x271e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2720:
	/* 0x2720: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2723:
	/* 0x2723: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_2725:
	/* 0x2725: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2727:
	/* 0x2727: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_272d:
	/* 0x272d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2730:
	/* 0x2730: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2735:
	/* 0x2735: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_273a:
	/* 0x273a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_273f:
	/* 0x273f: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2745:
	/* 0x2745: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_274a:
	/* 0x274a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2752:
	/* 0x2752: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2756:
	/* 0x2756: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_275d:
	/* 0x275d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2760:
	/* 0x2760: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2765:
	/* 0x2765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2767:
	/* 0x2767: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_276b:
	/* 0x276b: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2773:
	/* 0x2773: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2776:
	/* 0x2776: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_277e:
	/* 0x277e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2787:
	/* 0x2787: lea    rdx,[r13+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_278b:
	/* 0x278b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
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
	/* 0x279c: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_279e:
	/* 0x279e: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_27a4:
	/* 0x27a4: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_27aa:
	/* 0x27aa: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27ad:
	/* 0x27ad: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_27b2:
	/* 0x27b2: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b7:
	/* 0x27b7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27bc:
	/* 0x27bc: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_27c2:
	/* 0x27c2: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_27c7:
	/* 0x27c7: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_27cf:
	/* 0x27cf: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_27d3:
	/* 0x27d3: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_27da:
	/* 0x27da: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27df:
	/* 0x27df: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_27e4:
	/* 0x27e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e6:
	/* 0x27e6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e9:
	/* 0x27e9: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_27eb:
	/* 0x27eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27ed:
	/* 0x27ed: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_27f3:
	/* 0x27f3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_27f6:
	/* 0x27f6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_27fb:
	/* 0x27fb: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2800:
	/* 0x2800: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2805:
	/* 0x2805: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_280b:
	/* 0x280b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2810:
	/* 0x2810: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2818:
	/* 0x2818: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_281c:
	/* 0x281c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2823:
	/* 0x2823: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2826:
	/* 0x2826: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_282b:
	/* 0x282b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282d:
	/* 0x282d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2831:
	/* 0x2831: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2839:
	/* 0x2839: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_283c:
	/* 0x283c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2844:
	/* 0x2844: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_284d:
	/* 0x284d: lea    rdx,[r13+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2851:
	/* 0x2851: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2856:
	/* 0x2856: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_285b:
	/* 0x285b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2860:
	/* 0x2860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2862:
	/* 0x2862: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_2864:
	/* 0x2864: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_286a:
	/* 0x286a: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2870:
	/* 0x2870: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2873:
	/* 0x2873: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2878:
	/* 0x2878: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_287d:
	/* 0x287d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2882:
	/* 0x2882: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2888:
	/* 0x2888: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_288d:
	/* 0x288d: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2895:
	/* 0x2895: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2899:
	/* 0x2899: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_28a0:
	/* 0x28a0: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28a5:
	/* 0x28a5: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_28aa:
	/* 0x28aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ac:
	/* 0x28ac: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28af:
	/* 0x28af: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_28b1:
	/* 0x28b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28b3:
	/* 0x28b3: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_28b9:
	/* 0x28b9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28bc:
	/* 0x28bc: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_28c1:
	/* 0x28c1: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28c6:
	/* 0x28c6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28cb:
	/* 0x28cb: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_28d1:
	/* 0x28d1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_28d6:
	/* 0x28d6: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_28de:
	/* 0x28de: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_28e2:
	/* 0x28e2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_28e9:
	/* 0x28e9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_28ec:
	/* 0x28ec: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_28f1:
	/* 0x28f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f3:
	/* 0x28f3: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_28f7:
	/* 0x28f7: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_28ff:
	/* 0x28ff: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2902:
	/* 0x2902: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_290a:
	/* 0x290a: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2913:
	/* 0x2913: lea    rdx,[r13+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2917:
	/* 0x2917: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_291c:
	/* 0x291c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2921:
	/* 0x2921: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2926:
	/* 0x2926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2928:
	/* 0x2928: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_292a:
	/* 0x292a: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2930:
	/* 0x2930: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2936:
	/* 0x2936: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2939:
	/* 0x2939: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_293e:
	/* 0x293e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2943:
	/* 0x2943: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2948:
	/* 0x2948: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_294e:
	/* 0x294e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2953:
	/* 0x2953: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_295b:
	/* 0x295b: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_295f:
	/* 0x295f: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2966:
	/* 0x2966: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296b:
	/* 0x296b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2970:
	/* 0x2970: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2972:
	/* 0x2972: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2975:
	/* 0x2975: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_2977:
	/* 0x2977: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2979:
	/* 0x2979: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_297f:
	/* 0x297f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2982:
	/* 0x2982: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2987:
	/* 0x2987: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_298c:
	/* 0x298c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2991:
	/* 0x2991: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2997:
	/* 0x2997: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 10652ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10652ULL: goto x86_l_299c;
	case 10660ULL: goto x86_l_29a4;
	case 10664ULL: goto x86_l_29a8;
	case 10671ULL: goto x86_l_29af;
	case 10674ULL: goto x86_l_29b2;
	case 10679ULL: goto x86_l_29b7;
	case 10681ULL: goto x86_l_29b9;
	case 10685ULL: goto x86_l_29bd;
	case 10693ULL: goto x86_l_29c5;
	case 10696ULL: goto x86_l_29c8;
	case 10704ULL: goto x86_l_29d0;
	case 10713ULL: goto x86_l_29d9;
	case 10720ULL: goto x86_l_29e0;
	case 10725ULL: goto x86_l_29e5;
	case 10730ULL: goto x86_l_29ea;
	case 10735ULL: goto x86_l_29ef;
	case 10737ULL: goto x86_l_29f1;
	case 10739ULL: goto x86_l_29f3;
	case 10745ULL: goto x86_l_29f9;
	case 10751ULL: goto x86_l_29ff;
	case 10754ULL: goto x86_l_2a02;
	case 10759ULL: goto x86_l_2a07;
	case 10764ULL: goto x86_l_2a0c;
	case 10769ULL: goto x86_l_2a11;
	case 10775ULL: goto x86_l_2a17;
	case 10780ULL: goto x86_l_2a1c;
	case 10788ULL: goto x86_l_2a24;
	case 10792ULL: goto x86_l_2a28;
	case 10799ULL: goto x86_l_2a2f;
	case 10804ULL: goto x86_l_2a34;
	case 10809ULL: goto x86_l_2a39;
	case 10811ULL: goto x86_l_2a3b;
	case 10814ULL: goto x86_l_2a3e;
	case 10816ULL: goto x86_l_2a40;
	case 10818ULL: goto x86_l_2a42;
	case 10824ULL: goto x86_l_2a48;
	case 10827ULL: goto x86_l_2a4b;
	case 10832ULL: goto x86_l_2a50;
	case 10837ULL: goto x86_l_2a55;
	case 10842ULL: goto x86_l_2a5a;
	case 10848ULL: goto x86_l_2a60;
	case 10853ULL: goto x86_l_2a65;
	case 10861ULL: goto x86_l_2a6d;
	case 10865ULL: goto x86_l_2a71;
	case 10872ULL: goto x86_l_2a78;
	case 10875ULL: goto x86_l_2a7b;
	case 10880ULL: goto x86_l_2a80;
	case 10882ULL: goto x86_l_2a82;
	case 10886ULL: goto x86_l_2a86;
	case 10894ULL: goto x86_l_2a8e;
	case 10897ULL: goto x86_l_2a91;
	case 10905ULL: goto x86_l_2a99;
	case 10914ULL: goto x86_l_2aa2;
	case 10921ULL: goto x86_l_2aa9;
	case 10926ULL: goto x86_l_2aae;
	case 10931ULL: goto x86_l_2ab3;
	case 10936ULL: goto x86_l_2ab8;
	case 10938ULL: goto x86_l_2aba;
	case 10940ULL: goto x86_l_2abc;
	case 10946ULL: goto x86_l_2ac2;
	case 10952ULL: goto x86_l_2ac8;
	case 10955ULL: goto x86_l_2acb;
	case 10960ULL: goto x86_l_2ad0;
	case 10965ULL: goto x86_l_2ad5;
	case 10970ULL: goto x86_l_2ada;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10989ULL: goto x86_l_2aed;
	case 10993ULL: goto x86_l_2af1;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11012ULL: goto x86_l_2b04;
	case 11015ULL: goto x86_l_2b07;
	case 11017ULL: goto x86_l_2b09;
	case 11019ULL: goto x86_l_2b0b;
	case 11025ULL: goto x86_l_2b11;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11038ULL: goto x86_l_2b1e;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11054ULL: goto x86_l_2b2e;
	case 11062ULL: goto x86_l_2b36;
	case 11066ULL: goto x86_l_2b3a;
	case 11073ULL: goto x86_l_2b41;
	case 11076ULL: goto x86_l_2b44;
	case 11081ULL: goto x86_l_2b49;
	case 11083ULL: goto x86_l_2b4b;
	case 11087ULL: goto x86_l_2b4f;
	case 11095ULL: goto x86_l_2b57;
	case 11098ULL: goto x86_l_2b5a;
	case 11106ULL: goto x86_l_2b62;
	case 11115ULL: goto x86_l_2b6b;
	case 11122ULL: goto x86_l_2b72;
	case 11127ULL: goto x86_l_2b77;
	case 11132ULL: goto x86_l_2b7c;
	case 11137ULL: goto x86_l_2b81;
	case 11139ULL: goto x86_l_2b83;
	case 11141ULL: goto x86_l_2b85;
	case 11147ULL: goto x86_l_2b8b;
	case 11153ULL: goto x86_l_2b91;
	case 11156ULL: goto x86_l_2b94;
	case 11161ULL: goto x86_l_2b99;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11177ULL: goto x86_l_2ba9;
	case 11182ULL: goto x86_l_2bae;
	case 11190ULL: goto x86_l_2bb6;
	case 11194ULL: goto x86_l_2bba;
	case 11201ULL: goto x86_l_2bc1;
	case 11206ULL: goto x86_l_2bc6;
	case 11211ULL: goto x86_l_2bcb;
	case 11213ULL: goto x86_l_2bcd;
	case 11216ULL: goto x86_l_2bd0;
	case 11218ULL: goto x86_l_2bd2;
	case 11220ULL: goto x86_l_2bd4;
	case 11226ULL: goto x86_l_2bda;
	case 11229ULL: goto x86_l_2bdd;
	case 11234ULL: goto x86_l_2be2;
	case 11239ULL: goto x86_l_2be7;
	case 11244ULL: goto x86_l_2bec;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11263ULL: goto x86_l_2bff;
	case 11267ULL: goto x86_l_2c03;
	case 11274ULL: goto x86_l_2c0a;
	case 11277ULL: goto x86_l_2c0d;
	case 11282ULL: goto x86_l_2c12;
	case 11284ULL: goto x86_l_2c14;
	case 11288ULL: goto x86_l_2c18;
	case 11296ULL: goto x86_l_2c20;
	case 11299ULL: goto x86_l_2c23;
	case 11307ULL: goto x86_l_2c2b;
	case 11316ULL: goto x86_l_2c34;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11333ULL: goto x86_l_2c45;
	case 11338ULL: goto x86_l_2c4a;
	case 11340ULL: goto x86_l_2c4c;
	case 11342ULL: goto x86_l_2c4e;
	case 11348ULL: goto x86_l_2c54;
	case 11354ULL: goto x86_l_2c5a;
	case 11357ULL: goto x86_l_2c5d;
	case 11362ULL: goto x86_l_2c62;
	case 11367ULL: goto x86_l_2c67;
	case 11372ULL: goto x86_l_2c6c;
	case 11378ULL: goto x86_l_2c72;
	case 11383ULL: goto x86_l_2c77;
	case 11391ULL: goto x86_l_2c7f;
	case 11395ULL: goto x86_l_2c83;
	case 11402ULL: goto x86_l_2c8a;
	case 11407ULL: goto x86_l_2c8f;
	case 11412ULL: goto x86_l_2c94;
	case 11414ULL: goto x86_l_2c96;
	case 11417ULL: goto x86_l_2c99;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11427ULL: goto x86_l_2ca3;
	case 11430ULL: goto x86_l_2ca6;
	case 11435ULL: goto x86_l_2cab;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11456ULL: goto x86_l_2cc0;
	case 11464ULL: goto x86_l_2cc8;
	case 11468ULL: goto x86_l_2ccc;
	case 11475ULL: goto x86_l_2cd3;
	case 11478ULL: goto x86_l_2cd6;
	case 11483ULL: goto x86_l_2cdb;
	case 11485ULL: goto x86_l_2cdd;
	case 11489ULL: goto x86_l_2ce1;
	case 11497ULL: goto x86_l_2ce9;
	case 11500ULL: goto x86_l_2cec;
	case 11508ULL: goto x86_l_2cf4;
	case 11517ULL: goto x86_l_2cfd;
	case 11524ULL: goto x86_l_2d04;
	case 11529ULL: goto x86_l_2d09;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11541ULL: goto x86_l_2d15;
	case 11543ULL: goto x86_l_2d17;
	case 11549ULL: goto x86_l_2d1d;
	case 11555ULL: goto x86_l_2d23;
	case 11558ULL: goto x86_l_2d26;
	case 11563ULL: goto x86_l_2d2b;
	case 11568ULL: goto x86_l_2d30;
	case 11573ULL: goto x86_l_2d35;
	case 11579ULL: goto x86_l_2d3b;
	case 11584ULL: goto x86_l_2d40;
	case 11592ULL: goto x86_l_2d48;
	case 11596ULL: goto x86_l_2d4c;
	case 11603ULL: goto x86_l_2d53;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11622ULL: goto x86_l_2d66;
	case 11628ULL: goto x86_l_2d6c;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11641ULL: goto x86_l_2d79;
	case 11646ULL: goto x86_l_2d7e;
	case 11652ULL: goto x86_l_2d84;
	case 11657ULL: goto x86_l_2d89;
	case 11665ULL: goto x86_l_2d91;
	case 11669ULL: goto x86_l_2d95;
	case 11676ULL: goto x86_l_2d9c;
	case 11679ULL: goto x86_l_2d9f;
	case 11684ULL: goto x86_l_2da4;
	case 11686ULL: goto x86_l_2da6;
	case 11690ULL: goto x86_l_2daa;
	case 11698ULL: goto x86_l_2db2;
	case 11701ULL: goto x86_l_2db5;
	case 11709ULL: goto x86_l_2dbd;
	case 11718ULL: goto x86_l_2dc6;
	case 11725ULL: goto x86_l_2dcd;
	case 11730ULL: goto x86_l_2dd2;
	case 11735ULL: goto x86_l_2dd7;
	case 11740ULL: goto x86_l_2ddc;
	case 11742ULL: goto x86_l_2dde;
	case 11744ULL: goto x86_l_2de0;
	case 11750ULL: goto x86_l_2de6;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11793ULL: goto x86_l_2e11;
	case 11797ULL: goto x86_l_2e15;
	case 11804ULL: goto x86_l_2e1c;
	case 11809ULL: goto x86_l_2e21;
	case 11814ULL: goto x86_l_2e26;
	case 11816ULL: goto x86_l_2e28;
	case 11819ULL: goto x86_l_2e2b;
	case 11821ULL: goto x86_l_2e2d;
	case 11823ULL: goto x86_l_2e2f;
	case 11829ULL: goto x86_l_2e35;
	case 11832ULL: goto x86_l_2e38;
	case 11837ULL: goto x86_l_2e3d;
	case 11842ULL: goto x86_l_2e42;
	case 11847ULL: goto x86_l_2e47;
	case 11853ULL: goto x86_l_2e4d;
	case 11858ULL: goto x86_l_2e52;
	case 11866ULL: goto x86_l_2e5a;
	case 11870ULL: goto x86_l_2e5e;
	case 11877ULL: goto x86_l_2e65;
	case 11880ULL: goto x86_l_2e68;
	case 11885ULL: goto x86_l_2e6d;
	case 11887ULL: goto x86_l_2e6f;
	case 11891ULL: goto x86_l_2e73;
	case 11899ULL: goto x86_l_2e7b;
	case 11902ULL: goto x86_l_2e7e;
	case 11910ULL: goto x86_l_2e86;
	case 11919ULL: goto x86_l_2e8f;
	case 11926ULL: goto x86_l_2e96;
	case 11931ULL: goto x86_l_2e9b;
	case 11936ULL: goto x86_l_2ea0;
	case 11941ULL: goto x86_l_2ea5;
	case 11943ULL: goto x86_l_2ea7;
	case 11945ULL: goto x86_l_2ea9;
	case 11951ULL: goto x86_l_2eaf;
	case 11957ULL: goto x86_l_2eb5;
	case 11960ULL: goto x86_l_2eb8;
	case 11965ULL: goto x86_l_2ebd;
	case 11970ULL: goto x86_l_2ec2;
	case 11975ULL: goto x86_l_2ec7;
	case 11981ULL: goto x86_l_2ecd;
	case 11986ULL: goto x86_l_2ed2;
	case 11994ULL: goto x86_l_2eda;
	case 11998ULL: goto x86_l_2ede;
	case 12005ULL: goto x86_l_2ee5;
	case 12010ULL: goto x86_l_2eea;
	case 12015ULL: goto x86_l_2eef;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12022ULL: goto x86_l_2ef6;
	case 12024ULL: goto x86_l_2ef8;
	case 12030ULL: goto x86_l_2efe;
	case 12033ULL: goto x86_l_2f01;
	case 12038ULL: goto x86_l_2f06;
	case 12043ULL: goto x86_l_2f0b;
	case 12048ULL: goto x86_l_2f10;
	case 12054ULL: goto x86_l_2f16;
	case 12059ULL: goto x86_l_2f1b;
	case 12067ULL: goto x86_l_2f23;
	case 12071ULL: goto x86_l_2f27;
	case 12078ULL: goto x86_l_2f2e;
	case 12081ULL: goto x86_l_2f31;
	case 12086ULL: goto x86_l_2f36;
	case 12088ULL: goto x86_l_2f38;
	case 12092ULL: goto x86_l_2f3c;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12111ULL: goto x86_l_2f4f;
	case 12120ULL: goto x86_l_2f58;
	case 12127ULL: goto x86_l_2f5f;
	case 12132ULL: goto x86_l_2f64;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12144ULL: goto x86_l_2f70;
	case 12146ULL: goto x86_l_2f72;
	case 12152ULL: goto x86_l_2f78;
	case 12158ULL: goto x86_l_2f7e;
	case 12161ULL: goto x86_l_2f81;
	case 12166ULL: goto x86_l_2f86;
	case 12171ULL: goto x86_l_2f8b;
	case 12176ULL: goto x86_l_2f90;
	case 12182ULL: goto x86_l_2f96;
	case 12187ULL: goto x86_l_2f9b;
	case 12195ULL: goto x86_l_2fa3;
	case 12199ULL: goto x86_l_2fa7;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12216ULL: goto x86_l_2fb8;
	case 12218ULL: goto x86_l_2fba;
	case 12221ULL: goto x86_l_2fbd;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12231ULL: goto x86_l_2fc7;
	case 12234ULL: goto x86_l_2fca;
	case 12239ULL: goto x86_l_2fcf;
	case 12244ULL: goto x86_l_2fd4;
	case 12249ULL: goto x86_l_2fd9;
	case 12255ULL: goto x86_l_2fdf;
	case 12260ULL: goto x86_l_2fe4;
	case 12268ULL: goto x86_l_2fec;
	case 12272ULL: goto x86_l_2ff0;
	case 12279ULL: goto x86_l_2ff7;
	case 12282ULL: goto x86_l_2ffa;
	case 12287ULL: goto x86_l_2fff;
	case 12289ULL: goto x86_l_3001;
	case 12293ULL: goto x86_l_3005;
	case 12301ULL: goto x86_l_300d;
	case 12304ULL: goto x86_l_3010;
	case 12312ULL: goto x86_l_3018;
	case 12321ULL: goto x86_l_3021;
	case 12328ULL: goto x86_l_3028;
	case 12333ULL: goto x86_l_302d;
	case 12338ULL: goto x86_l_3032;
	case 12343ULL: goto x86_l_3037;
	case 12345ULL: goto x86_l_3039;
	case 12347ULL: goto x86_l_303b;
	case 12353ULL: goto x86_l_3041;
	case 12359ULL: goto x86_l_3047;
	case 12362ULL: goto x86_l_304a;
	case 12367ULL: goto x86_l_304f;
	case 12372ULL: goto x86_l_3054;
	case 12377ULL: goto x86_l_3059;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12396ULL: goto x86_l_306c;
	case 12400ULL: goto x86_l_3070;
	case 12407ULL: goto x86_l_3077;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12419ULL: goto x86_l_3083;
	case 12422ULL: goto x86_l_3086;
	case 12424ULL: goto x86_l_3088;
	case 12426ULL: goto x86_l_308a;
	case 12432ULL: goto x86_l_3090;
	case 12435ULL: goto x86_l_3093;
	case 12440ULL: goto x86_l_3098;
	case 12445ULL: goto x86_l_309d;
	case 12450ULL: goto x86_l_30a2;
	case 12456ULL: goto x86_l_30a8;
	case 12461ULL: goto x86_l_30ad;
	case 12469ULL: goto x86_l_30b5;
	case 12473ULL: goto x86_l_30b9;
	case 12480ULL: goto x86_l_30c0;
	case 12483ULL: goto x86_l_30c3;
	case 12488ULL: goto x86_l_30c8;
	case 12490ULL: goto x86_l_30ca;
	case 12494ULL: goto x86_l_30ce;
	case 12502ULL: goto x86_l_30d6;
	case 12505ULL: goto x86_l_30d9;
	case 12513ULL: goto x86_l_30e1;
	case 12522ULL: goto x86_l_30ea;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	default: return 0xffffffffffffffffULL;
	}
x86_l_299c:
	/* 0x299c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_29a4:
	/* 0x29a4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_29a8:
	/* 0x29a8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_29af:
	/* 0x29af: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_29b2:
	/* 0x29b2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_29b7:
	/* 0x29b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b9:
	/* 0x29b9: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_29bd:
	/* 0x29bd: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_29c5:
	/* 0x29c5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_29c8:
	/* 0x29c8: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_29d0:
	/* 0x29d0: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29d9:
	/* 0x29d9: lea    rdx,[r13+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_29e0:
	/* 0x29e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29e5:
	/* 0x29e5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29ea:
	/* 0x29ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_29ef:
	/* 0x29ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29f1:
	/* 0x29f1: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_29f3:
	/* 0x29f3: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29f9:
	/* 0x29f9: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_29ff:
	/* 0x29ff: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a02:
	/* 0x2a02: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2a07:
	/* 0x2a07: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a0c:
	/* 0x2a0c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a11:
	/* 0x2a11: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2a17:
	/* 0x2a17: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2a1c:
	/* 0x2a1c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a24:
	/* 0x2a24: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2a28:
	/* 0x2a28: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2a2f:
	/* 0x2a2f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a34:
	/* 0x2a34: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2a39:
	/* 0x2a39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a3b:
	/* 0x2a3b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a3e:
	/* 0x2a3e: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_2a40:
	/* 0x2a40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a42:
	/* 0x2a42: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2a48:
	/* 0x2a48: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a4b:
	/* 0x2a4b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2a50:
	/* 0x2a50: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a55:
	/* 0x2a55: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5a:
	/* 0x2a5a: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2a60:
	/* 0x2a60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a65:
	/* 0x2a65: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2a6d:
	/* 0x2a6d: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2a71:
	/* 0x2a71: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2a78:
	/* 0x2a78: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2a7b:
	/* 0x2a7b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2a80:
	/* 0x2a80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a82:
	/* 0x2a82: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a86:
	/* 0x2a86: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2a8e:
	/* 0x2a8e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2a91:
	/* 0x2a91: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2a99:
	/* 0x2a99: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2aa2:
	/* 0x2aa2: lea    rdx,[r13+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2aa9:
	/* 0x2aa9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2aae:
	/* 0x2aae: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ab3:
	/* 0x2ab3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ab8:
	/* 0x2ab8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2aba:
	/* 0x2aba: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2abc:
	/* 0x2abc: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2ac2:
	/* 0x2ac2: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2ac8:
	/* 0x2ac8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2acb:
	/* 0x2acb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2ad0:
	/* 0x2ad0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ada:
	/* 0x2ada: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2ae0:
	/* 0x2ae0: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ae5:
	/* 0x2ae5: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2aed:
	/* 0x2aed: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2af1:
	/* 0x2af1: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2af8:
	/* 0x2af8: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2afd:
	/* 0x2afd: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2b02:
	/* 0x2b02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b04:
	/* 0x2b04: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b07:
	/* 0x2b07: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_2b09:
	/* 0x2b09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b0b:
	/* 0x2b0b: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2b11:
	/* 0x2b11: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b14:
	/* 0x2b14: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2b19:
	/* 0x2b19: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b1e:
	/* 0x2b1e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b23:
	/* 0x2b23: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2b29:
	/* 0x2b29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b2e:
	/* 0x2b2e: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2b36:
	/* 0x2b36: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2b3a:
	/* 0x2b3a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2b41:
	/* 0x2b41: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2b44:
	/* 0x2b44: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2b49:
	/* 0x2b49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4b:
	/* 0x2b4b: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b4f:
	/* 0x2b4f: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2b57:
	/* 0x2b57: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2b5a:
	/* 0x2b5a: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2b62:
	/* 0x2b62: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2b6b:
	/* 0x2b6b: lea    rdx,[r13+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2b72:
	/* 0x2b72: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b77:
	/* 0x2b77: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b7c:
	/* 0x2b7c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b81:
	/* 0x2b81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b83:
	/* 0x2b83: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_2b85:
	/* 0x2b85: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2b8b:
	/* 0x2b8b: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2b91:
	/* 0x2b91: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b94:
	/* 0x2b94: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2b99:
	/* 0x2b99: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b9e:
	/* 0x2b9e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba3:
	/* 0x2ba3: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2ba9:
	/* 0x2ba9: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2bae:
	/* 0x2bae: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bb6:
	/* 0x2bb6: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2bba:
	/* 0x2bba: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2bc1:
	/* 0x2bc1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bc6:
	/* 0x2bc6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2bcb:
	/* 0x2bcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bcd:
	/* 0x2bcd: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd0:
	/* 0x2bd0: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_2bd2:
	/* 0x2bd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bd4:
	/* 0x2bd4: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2bda:
	/* 0x2bda: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2bdd:
	/* 0x2bdd: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2be2:
	/* 0x2be2: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be7:
	/* 0x2be7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bec:
	/* 0x2bec: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2bf2:
	/* 0x2bf2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bf7:
	/* 0x2bf7: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2bff:
	/* 0x2bff: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c03:
	/* 0x2c03: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2c0a:
	/* 0x2c0a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2c0d:
	/* 0x2c0d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c12:
	/* 0x2c12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c14:
	/* 0x2c14: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c18:
	/* 0x2c18: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2c20:
	/* 0x2c20: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2c23:
	/* 0x2c23: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2c2b:
	/* 0x2c2b: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c34:
	/* 0x2c34: lea    rdx,[r13+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2c3b:
	/* 0x2c3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c40:
	/* 0x2c40: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c45:
	/* 0x2c45: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c4a:
	/* 0x2c4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4c:
	/* 0x2c4c: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2c4e:
	/* 0x2c4e: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c54:
	/* 0x2c54: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2c5a:
	/* 0x2c5a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c5d:
	/* 0x2c5d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2c62:
	/* 0x2c62: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c67:
	/* 0x2c67: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c6c:
	/* 0x2c6c: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2c72:
	/* 0x2c72: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2c77:
	/* 0x2c77: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2c7f:
	/* 0x2c7f: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2c83:
	/* 0x2c83: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c8f:
	/* 0x2c8f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2c94:
	/* 0x2c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c96:
	/* 0x2c96: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c99:
	/* 0x2c99: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_2c9b:
	/* 0x2c9b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c9d:
	/* 0x2c9d: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2ca3:
	/* 0x2ca3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ca6:
	/* 0x2ca6: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2cab:
	/* 0x2cab: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2cb0:
	/* 0x2cb0: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cb5:
	/* 0x2cb5: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2cbb:
	/* 0x2cbb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cc0:
	/* 0x2cc0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2cc8:
	/* 0x2cc8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ccc:
	/* 0x2ccc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2cd3:
	/* 0x2cd3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2cd6:
	/* 0x2cd6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2cdb:
	/* 0x2cdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cdd:
	/* 0x2cdd: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2ce1:
	/* 0x2ce1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2ce9:
	/* 0x2ce9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2cec:
	/* 0x2cec: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2cf4:
	/* 0x2cf4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2cfd:
	/* 0x2cfd: lea    rdx,[r13+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d04:
	/* 0x2d04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d09:
	/* 0x2d09: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d0e:
	/* 0x2d0e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2d13:
	/* 0x2d13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d15:
	/* 0x2d15: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2d17:
	/* 0x2d17: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2d1d:
	/* 0x2d1d: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2d23:
	/* 0x2d23: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d26:
	/* 0x2d26: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2d2b:
	/* 0x2d2b: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d30:
	/* 0x2d30: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d35:
	/* 0x2d35: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2d3b:
	/* 0x2d3b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2d40:
	/* 0x2d40: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d48:
	/* 0x2d48: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2d4c:
	/* 0x2d4c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2d53:
	/* 0x2d53: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d58:
	/* 0x2d58: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2d5d:
	/* 0x2d5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d5f:
	/* 0x2d5f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d62:
	/* 0x2d62: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_2d64:
	/* 0x2d64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d66:
	/* 0x2d66: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2d6c:
	/* 0x2d6c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d6f:
	/* 0x2d6f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2d74:
	/* 0x2d74: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d79:
	/* 0x2d79: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d7e:
	/* 0x2d7e: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2d84:
	/* 0x2d84: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d89:
	/* 0x2d89: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2d91:
	/* 0x2d91: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2d95:
	/* 0x2d95: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2d9c:
	/* 0x2d9c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2d9f:
	/* 0x2d9f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2da4:
	/* 0x2da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da6:
	/* 0x2da6: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2daa:
	/* 0x2daa: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2db2:
	/* 0x2db2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2db5:
	/* 0x2db5: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2dbd:
	/* 0x2dbd: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2dc6:
	/* 0x2dc6: lea    rdx,[r13+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2dcd:
	/* 0x2dcd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2dd2:
	/* 0x2dd2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dd7:
	/* 0x2dd7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ddc:
	/* 0x2ddc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dde:
	/* 0x2dde: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_2de0:
	/* 0x2de0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2de6:
	/* 0x2de6: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2dec:
	/* 0x2dec: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2def:
	/* 0x2def: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2df4:
	/* 0x2df4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2df9:
	/* 0x2df9: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfe:
	/* 0x2dfe: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2e04:
	/* 0x2e04: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2e09:
	/* 0x2e09: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e11:
	/* 0x2e11: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2e15:
	/* 0x2e15: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e21:
	/* 0x2e21: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2e26:
	/* 0x2e26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e28:
	/* 0x2e28: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_2e2d:
	/* 0x2e2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e2f:
	/* 0x2e2f: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2e35:
	/* 0x2e35: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e38:
	/* 0x2e38: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2e3d:
	/* 0x2e3d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e42:
	/* 0x2e42: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e47:
	/* 0x2e47: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2e4d:
	/* 0x2e4d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e52:
	/* 0x2e52: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2e5a:
	/* 0x2e5a: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2e5e:
	/* 0x2e5e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2e65:
	/* 0x2e65: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2e68:
	/* 0x2e68: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e6d:
	/* 0x2e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e6f:
	/* 0x2e6f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e73:
	/* 0x2e73: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2e7b:
	/* 0x2e7b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2e86:
	/* 0x2e86: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2e8f:
	/* 0x2e8f: lea    rdx,[r13+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2e96:
	/* 0x2e96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e9b:
	/* 0x2e9b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ea0:
	/* 0x2ea0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2ea5:
	/* 0x2ea5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ea7:
	/* 0x2ea7: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2ea9:
	/* 0x2ea9: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2eaf:
	/* 0x2eaf: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2eb5:
	/* 0x2eb5: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2eb8:
	/* 0x2eb8: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2ebd:
	/* 0x2ebd: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ec2:
	/* 0x2ec2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ec7:
	/* 0x2ec7: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2ecd:
	/* 0x2ecd: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2ed2:
	/* 0x2ed2: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2eda:
	/* 0x2eda: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2ede:
	/* 0x2ede: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2ee5:
	/* 0x2ee5: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2eea:
	/* 0x2eea: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2eef:
	/* 0x2eef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ef1:
	/* 0x2ef1: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ef4:
	/* 0x2ef4: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_2ef6:
	/* 0x2ef6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ef8:
	/* 0x2ef8: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2efe:
	/* 0x2efe: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f01:
	/* 0x2f01: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2f06:
	/* 0x2f06: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f0b:
	/* 0x2f0b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f10:
	/* 0x2f10: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2f16:
	/* 0x2f16: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f1b:
	/* 0x2f1b: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2f23:
	/* 0x2f23: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2f27:
	/* 0x2f27: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2f31:
	/* 0x2f31: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2f36:
	/* 0x2f36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f38:
	/* 0x2f38: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f3c:
	/* 0x2f3c: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_2f44:
	/* 0x2f44: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2f47:
	/* 0x2f47: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_2f4f:
	/* 0x2f4f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2f58:
	/* 0x2f58: lea    rdx,[r13+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2f5f:
	/* 0x2f5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2f64:
	/* 0x2f64: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f69:
	/* 0x2f69: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f6e:
	/* 0x2f6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f70:
	/* 0x2f70: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2f72:
	/* 0x2f72: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2f78:
	/* 0x2f78: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_2f7e:
	/* 0x2f7e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f81:
	/* 0x2f81: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_2f86:
	/* 0x2f86: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f8b:
	/* 0x2f8b: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f90:
	/* 0x2f90: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2f96:
	/* 0x2f96: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2f9b:
	/* 0x2f9b: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fa3:
	/* 0x2fa3: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2fa7:
	/* 0x2fa7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_2fae:
	/* 0x2fae: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_2fb8:
	/* 0x2fb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fba:
	/* 0x2fba: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fbd:
	/* 0x2fbd: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_2fbf:
	/* 0x2fbf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fc1:
	/* 0x2fc1: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_2fc7:
	/* 0x2fc7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fca:
	/* 0x2fca: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_2fcf:
	/* 0x2fcf: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2fd4:
	/* 0x2fd4: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd9:
	/* 0x2fd9: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_2fdf:
	/* 0x2fdf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fe4:
	/* 0x2fe4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_2fec:
	/* 0x2fec: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2ff0:
	/* 0x2ff0: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_2ff7:
	/* 0x2ff7: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2ffa:
	/* 0x2ffa: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fff:
	/* 0x2fff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3001:
	/* 0x3001: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3005:
	/* 0x3005: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_300d:
	/* 0x300d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3010:
	/* 0x3010: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3018:
	/* 0x3018: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3021:
	/* 0x3021: lea    rdx,[r13+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3028:
	/* 0x3028: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_302d:
	/* 0x302d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3032:
	/* 0x3032: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3037:
	/* 0x3037: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3039:
	/* 0x3039: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_303b:
	/* 0x303b: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3041:
	/* 0x3041: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_3047:
	/* 0x3047: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_304a:
	/* 0x304a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_304f:
	/* 0x304f: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3054:
	/* 0x3054: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3059:
	/* 0x3059: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_305f:
	/* 0x305f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3064:
	/* 0x3064: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_306c:
	/* 0x306c: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3070:
	/* 0x3070: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3077:
	/* 0x3077: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_307c:
	/* 0x307c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3081:
	/* 0x3081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3083:
	/* 0x3083: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3086:
	/* 0x3086: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3088:
	/* 0x3088: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_308a:
	/* 0x308a: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3090:
	/* 0x3090: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3093:
	/* 0x3093: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3098:
	/* 0x3098: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_309d:
	/* 0x309d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a2:
	/* 0x30a2: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_30a8:
	/* 0x30a8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30ad:
	/* 0x30ad: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_30b5:
	/* 0x30b5: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_30b9:
	/* 0x30b9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_30c0:
	/* 0x30c0: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_30c3:
	/* 0x30c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_30c8:
	/* 0x30c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30ca:
	/* 0x30ca: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_30ce:
	/* 0x30ce: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_30d6:
	/* 0x30d6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_30d9:
	/* 0x30d9: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_30e1:
	/* 0x30e1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_30ea:
	/* 0x30ea: lea    rdx,[r13+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_30f1:
	/* 0x30f1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30f6:
	/* 0x30f6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30fb:
	/* 0x30fb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
	return 12544ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12544ULL: goto x86_l_3100;
	case 12546ULL: goto x86_l_3102;
	case 12548ULL: goto x86_l_3104;
	case 12554ULL: goto x86_l_310a;
	case 12560ULL: goto x86_l_3110;
	case 12563ULL: goto x86_l_3113;
	case 12568ULL: goto x86_l_3118;
	case 12573ULL: goto x86_l_311d;
	case 12578ULL: goto x86_l_3122;
	case 12584ULL: goto x86_l_3128;
	case 12589ULL: goto x86_l_312d;
	case 12597ULL: goto x86_l_3135;
	case 12601ULL: goto x86_l_3139;
	case 12608ULL: goto x86_l_3140;
	case 12613ULL: goto x86_l_3145;
	case 12618ULL: goto x86_l_314a;
	case 12620ULL: goto x86_l_314c;
	case 12623ULL: goto x86_l_314f;
	case 12625ULL: goto x86_l_3151;
	case 12627ULL: goto x86_l_3153;
	case 12633ULL: goto x86_l_3159;
	case 12636ULL: goto x86_l_315c;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12651ULL: goto x86_l_316b;
	case 12657ULL: goto x86_l_3171;
	case 12662ULL: goto x86_l_3176;
	case 12670ULL: goto x86_l_317e;
	case 12674ULL: goto x86_l_3182;
	case 12681ULL: goto x86_l_3189;
	case 12684ULL: goto x86_l_318c;
	case 12689ULL: goto x86_l_3191;
	case 12691ULL: goto x86_l_3193;
	case 12695ULL: goto x86_l_3197;
	case 12703ULL: goto x86_l_319f;
	case 12706ULL: goto x86_l_31a2;
	case 12714ULL: goto x86_l_31aa;
	case 12723ULL: goto x86_l_31b3;
	case 12730ULL: goto x86_l_31ba;
	case 12735ULL: goto x86_l_31bf;
	case 12740ULL: goto x86_l_31c4;
	case 12745ULL: goto x86_l_31c9;
	case 12747ULL: goto x86_l_31cb;
	case 12749ULL: goto x86_l_31cd;
	case 12755ULL: goto x86_l_31d3;
	case 12761ULL: goto x86_l_31d9;
	case 12764ULL: goto x86_l_31dc;
	case 12769ULL: goto x86_l_31e1;
	case 12774ULL: goto x86_l_31e6;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12798ULL: goto x86_l_31fe;
	case 12802ULL: goto x86_l_3202;
	case 12809ULL: goto x86_l_3209;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12821ULL: goto x86_l_3215;
	case 12824ULL: goto x86_l_3218;
	case 12826ULL: goto x86_l_321a;
	case 12828ULL: goto x86_l_321c;
	case 12834ULL: goto x86_l_3222;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12852ULL: goto x86_l_3234;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12871ULL: goto x86_l_3247;
	case 12875ULL: goto x86_l_324b;
	case 12882ULL: goto x86_l_3252;
	case 12885ULL: goto x86_l_3255;
	case 12890ULL: goto x86_l_325a;
	case 12892ULL: goto x86_l_325c;
	case 12896ULL: goto x86_l_3260;
	case 12904ULL: goto x86_l_3268;
	case 12907ULL: goto x86_l_326b;
	case 12915ULL: goto x86_l_3273;
	case 12924ULL: goto x86_l_327c;
	case 12931ULL: goto x86_l_3283;
	case 12936ULL: goto x86_l_3288;
	case 12941ULL: goto x86_l_328d;
	case 12946ULL: goto x86_l_3292;
	case 12948ULL: goto x86_l_3294;
	case 12950ULL: goto x86_l_3296;
	case 12956ULL: goto x86_l_329c;
	case 12962ULL: goto x86_l_32a2;
	case 12965ULL: goto x86_l_32a5;
	case 12970ULL: goto x86_l_32aa;
	case 12975ULL: goto x86_l_32af;
	case 12980ULL: goto x86_l_32b4;
	case 12986ULL: goto x86_l_32ba;
	case 12991ULL: goto x86_l_32bf;
	case 12999ULL: goto x86_l_32c7;
	case 13003ULL: goto x86_l_32cb;
	case 13010ULL: goto x86_l_32d2;
	case 13015ULL: goto x86_l_32d7;
	case 13020ULL: goto x86_l_32dc;
	case 13022ULL: goto x86_l_32de;
	case 13025ULL: goto x86_l_32e1;
	case 13027ULL: goto x86_l_32e3;
	case 13029ULL: goto x86_l_32e5;
	case 13035ULL: goto x86_l_32eb;
	case 13038ULL: goto x86_l_32ee;
	case 13043ULL: goto x86_l_32f3;
	case 13048ULL: goto x86_l_32f8;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13064ULL: goto x86_l_3308;
	case 13072ULL: goto x86_l_3310;
	case 13076ULL: goto x86_l_3314;
	case 13083ULL: goto x86_l_331b;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13093ULL: goto x86_l_3325;
	case 13097ULL: goto x86_l_3329;
	case 13105ULL: goto x86_l_3331;
	case 13108ULL: goto x86_l_3334;
	case 13116ULL: goto x86_l_333c;
	case 13125ULL: goto x86_l_3345;
	case 13132ULL: goto x86_l_334c;
	case 13137ULL: goto x86_l_3351;
	case 13142ULL: goto x86_l_3356;
	case 13147ULL: goto x86_l_335b;
	case 13149ULL: goto x86_l_335d;
	case 13151ULL: goto x86_l_335f;
	case 13157ULL: goto x86_l_3365;
	case 13163ULL: goto x86_l_336b;
	case 13166ULL: goto x86_l_336e;
	case 13171ULL: goto x86_l_3373;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13187ULL: goto x86_l_3383;
	case 13192ULL: goto x86_l_3388;
	case 13200ULL: goto x86_l_3390;
	case 13204ULL: goto x86_l_3394;
	case 13211ULL: goto x86_l_339b;
	case 13216ULL: goto x86_l_33a0;
	case 13221ULL: goto x86_l_33a5;
	case 13223ULL: goto x86_l_33a7;
	case 13226ULL: goto x86_l_33aa;
	case 13228ULL: goto x86_l_33ac;
	case 13230ULL: goto x86_l_33ae;
	case 13236ULL: goto x86_l_33b4;
	case 13239ULL: goto x86_l_33b7;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13254ULL: goto x86_l_33c6;
	case 13260ULL: goto x86_l_33cc;
	case 13265ULL: goto x86_l_33d1;
	case 13273ULL: goto x86_l_33d9;
	case 13277ULL: goto x86_l_33dd;
	case 13284ULL: goto x86_l_33e4;
	case 13287ULL: goto x86_l_33e7;
	case 13292ULL: goto x86_l_33ec;
	case 13294ULL: goto x86_l_33ee;
	case 13298ULL: goto x86_l_33f2;
	case 13306ULL: goto x86_l_33fa;
	case 13309ULL: goto x86_l_33fd;
	case 13317ULL: goto x86_l_3405;
	case 13326ULL: goto x86_l_340e;
	case 13333ULL: goto x86_l_3415;
	case 13338ULL: goto x86_l_341a;
	case 13343ULL: goto x86_l_341f;
	case 13348ULL: goto x86_l_3424;
	case 13350ULL: goto x86_l_3426;
	case 13352ULL: goto x86_l_3428;
	case 13358ULL: goto x86_l_342e;
	case 13364ULL: goto x86_l_3434;
	case 13367ULL: goto x86_l_3437;
	case 13372ULL: goto x86_l_343c;
	case 13377ULL: goto x86_l_3441;
	case 13382ULL: goto x86_l_3446;
	case 13388ULL: goto x86_l_344c;
	case 13393ULL: goto x86_l_3451;
	case 13401ULL: goto x86_l_3459;
	case 13405ULL: goto x86_l_345d;
	case 13412ULL: goto x86_l_3464;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13424ULL: goto x86_l_3470;
	case 13427ULL: goto x86_l_3473;
	case 13429ULL: goto x86_l_3475;
	case 13431ULL: goto x86_l_3477;
	case 13437ULL: goto x86_l_347d;
	case 13440ULL: goto x86_l_3480;
	case 13445ULL: goto x86_l_3485;
	case 13450ULL: goto x86_l_348a;
	case 13455ULL: goto x86_l_348f;
	case 13461ULL: goto x86_l_3495;
	case 13466ULL: goto x86_l_349a;
	case 13474ULL: goto x86_l_34a2;
	case 13478ULL: goto x86_l_34a6;
	case 13485ULL: goto x86_l_34ad;
	case 13488ULL: goto x86_l_34b0;
	case 13493ULL: goto x86_l_34b5;
	case 13495ULL: goto x86_l_34b7;
	case 13499ULL: goto x86_l_34bb;
	case 13507ULL: goto x86_l_34c3;
	case 13510ULL: goto x86_l_34c6;
	case 13518ULL: goto x86_l_34ce;
	case 13527ULL: goto x86_l_34d7;
	case 13534ULL: goto x86_l_34de;
	case 13539ULL: goto x86_l_34e3;
	case 13544ULL: goto x86_l_34e8;
	case 13549ULL: goto x86_l_34ed;
	case 13551ULL: goto x86_l_34ef;
	case 13553ULL: goto x86_l_34f1;
	case 13559ULL: goto x86_l_34f7;
	case 13565ULL: goto x86_l_34fd;
	case 13568ULL: goto x86_l_3500;
	case 13573ULL: goto x86_l_3505;
	case 13578ULL: goto x86_l_350a;
	case 13583ULL: goto x86_l_350f;
	case 13589ULL: goto x86_l_3515;
	case 13594ULL: goto x86_l_351a;
	case 13602ULL: goto x86_l_3522;
	case 13606ULL: goto x86_l_3526;
	case 13613ULL: goto x86_l_352d;
	case 13618ULL: goto x86_l_3532;
	case 13623ULL: goto x86_l_3537;
	case 13625ULL: goto x86_l_3539;
	case 13628ULL: goto x86_l_353c;
	case 13630ULL: goto x86_l_353e;
	case 13632ULL: goto x86_l_3540;
	case 13638ULL: goto x86_l_3546;
	case 13641ULL: goto x86_l_3549;
	case 13646ULL: goto x86_l_354e;
	case 13651ULL: goto x86_l_3553;
	case 13656ULL: goto x86_l_3558;
	case 13662ULL: goto x86_l_355e;
	case 13667ULL: goto x86_l_3563;
	case 13675ULL: goto x86_l_356b;
	case 13679ULL: goto x86_l_356f;
	case 13686ULL: goto x86_l_3576;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13696ULL: goto x86_l_3580;
	case 13700ULL: goto x86_l_3584;
	case 13708ULL: goto x86_l_358c;
	case 13711ULL: goto x86_l_358f;
	case 13719ULL: goto x86_l_3597;
	case 13728ULL: goto x86_l_35a0;
	case 13735ULL: goto x86_l_35a7;
	case 13740ULL: goto x86_l_35ac;
	case 13745ULL: goto x86_l_35b1;
	case 13750ULL: goto x86_l_35b6;
	case 13752ULL: goto x86_l_35b8;
	case 13754ULL: goto x86_l_35ba;
	case 13760ULL: goto x86_l_35c0;
	case 13766ULL: goto x86_l_35c6;
	case 13769ULL: goto x86_l_35c9;
	case 13774ULL: goto x86_l_35ce;
	case 13779ULL: goto x86_l_35d3;
	case 13784ULL: goto x86_l_35d8;
	case 13790ULL: goto x86_l_35de;
	case 13795ULL: goto x86_l_35e3;
	case 13803ULL: goto x86_l_35eb;
	case 13807ULL: goto x86_l_35ef;
	case 13814ULL: goto x86_l_35f6;
	case 13819ULL: goto x86_l_35fb;
	case 13824ULL: goto x86_l_3600;
	case 13826ULL: goto x86_l_3602;
	case 13829ULL: goto x86_l_3605;
	case 13831ULL: goto x86_l_3607;
	case 13833ULL: goto x86_l_3609;
	case 13839ULL: goto x86_l_360f;
	case 13842ULL: goto x86_l_3612;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13857ULL: goto x86_l_3621;
	case 13863ULL: goto x86_l_3627;
	case 13868ULL: goto x86_l_362c;
	case 13876ULL: goto x86_l_3634;
	case 13880ULL: goto x86_l_3638;
	case 13887ULL: goto x86_l_363f;
	case 13890ULL: goto x86_l_3642;
	case 13895ULL: goto x86_l_3647;
	case 13897ULL: goto x86_l_3649;
	case 13901ULL: goto x86_l_364d;
	case 13909ULL: goto x86_l_3655;
	case 13912ULL: goto x86_l_3658;
	case 13920ULL: goto x86_l_3660;
	case 13929ULL: goto x86_l_3669;
	case 13936ULL: goto x86_l_3670;
	case 13941ULL: goto x86_l_3675;
	case 13946ULL: goto x86_l_367a;
	case 13951ULL: goto x86_l_367f;
	case 13953ULL: goto x86_l_3681;
	case 13955ULL: goto x86_l_3683;
	case 13961ULL: goto x86_l_3689;
	case 13967ULL: goto x86_l_368f;
	case 13970ULL: goto x86_l_3692;
	case 13975ULL: goto x86_l_3697;
	case 13980ULL: goto x86_l_369c;
	case 13985ULL: goto x86_l_36a1;
	case 13991ULL: goto x86_l_36a7;
	case 13996ULL: goto x86_l_36ac;
	case 14004ULL: goto x86_l_36b4;
	case 14008ULL: goto x86_l_36b8;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14027ULL: goto x86_l_36cb;
	case 14030ULL: goto x86_l_36ce;
	case 14032ULL: goto x86_l_36d0;
	case 14034ULL: goto x86_l_36d2;
	case 14040ULL: goto x86_l_36d8;
	case 14043ULL: goto x86_l_36db;
	case 14048ULL: goto x86_l_36e0;
	case 14053ULL: goto x86_l_36e5;
	case 14058ULL: goto x86_l_36ea;
	case 14064ULL: goto x86_l_36f0;
	case 14069ULL: goto x86_l_36f5;
	case 14077ULL: goto x86_l_36fd;
	case 14081ULL: goto x86_l_3701;
	case 14088ULL: goto x86_l_3708;
	case 14091ULL: goto x86_l_370b;
	case 14096ULL: goto x86_l_3710;
	case 14098ULL: goto x86_l_3712;
	case 14102ULL: goto x86_l_3716;
	case 14110ULL: goto x86_l_371e;
	case 14113ULL: goto x86_l_3721;
	case 14121ULL: goto x86_l_3729;
	case 14130ULL: goto x86_l_3732;
	case 14137ULL: goto x86_l_3739;
	case 14142ULL: goto x86_l_373e;
	case 14147ULL: goto x86_l_3743;
	case 14152ULL: goto x86_l_3748;
	case 14154ULL: goto x86_l_374a;
	case 14156ULL: goto x86_l_374c;
	case 14162ULL: goto x86_l_3752;
	case 14168ULL: goto x86_l_3758;
	case 14171ULL: goto x86_l_375b;
	case 14176ULL: goto x86_l_3760;
	case 14181ULL: goto x86_l_3765;
	case 14186ULL: goto x86_l_376a;
	case 14192ULL: goto x86_l_3770;
	case 14197ULL: goto x86_l_3775;
	case 14205ULL: goto x86_l_377d;
	case 14209ULL: goto x86_l_3781;
	case 14216ULL: goto x86_l_3788;
	case 14221ULL: goto x86_l_378d;
	case 14226ULL: goto x86_l_3792;
	case 14228ULL: goto x86_l_3794;
	case 14231ULL: goto x86_l_3797;
	case 14233ULL: goto x86_l_3799;
	case 14235ULL: goto x86_l_379b;
	case 14241ULL: goto x86_l_37a1;
	case 14244ULL: goto x86_l_37a4;
	case 14249ULL: goto x86_l_37a9;
	case 14254ULL: goto x86_l_37ae;
	case 14259ULL: goto x86_l_37b3;
	case 14265ULL: goto x86_l_37b9;
	case 14270ULL: goto x86_l_37be;
	case 14278ULL: goto x86_l_37c6;
	case 14282ULL: goto x86_l_37ca;
	case 14289ULL: goto x86_l_37d1;
	case 14292ULL: goto x86_l_37d4;
	case 14297ULL: goto x86_l_37d9;
	case 14299ULL: goto x86_l_37db;
	case 14303ULL: goto x86_l_37df;
	case 14311ULL: goto x86_l_37e7;
	case 14314ULL: goto x86_l_37ea;
	case 14322ULL: goto x86_l_37f2;
	case 14331ULL: goto x86_l_37fb;
	case 14338ULL: goto x86_l_3802;
	case 14343ULL: goto x86_l_3807;
	case 14348ULL: goto x86_l_380c;
	case 14353ULL: goto x86_l_3811;
	case 14355ULL: goto x86_l_3813;
	case 14357ULL: goto x86_l_3815;
	case 14363ULL: goto x86_l_381b;
	case 14369ULL: goto x86_l_3821;
	case 14372ULL: goto x86_l_3824;
	case 14377ULL: goto x86_l_3829;
	case 14382ULL: goto x86_l_382e;
	case 14387ULL: goto x86_l_3833;
	case 14393ULL: goto x86_l_3839;
	case 14398ULL: goto x86_l_383e;
	case 14406ULL: goto x86_l_3846;
	case 14410ULL: goto x86_l_384a;
	case 14417ULL: goto x86_l_3851;
	case 14422ULL: goto x86_l_3856;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3100:
	/* 0x3100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3102:
	/* 0x3102: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3104:
	/* 0x3104: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_310a:
	/* 0x310a: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_3110:
	/* 0x3110: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3113:
	/* 0x3113: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3118:
	/* 0x3118: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_311d:
	/* 0x311d: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3122:
	/* 0x3122: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3128:
	/* 0x3128: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_312d:
	/* 0x312d: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3135:
	/* 0x3135: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3139:
	/* 0x3139: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3140:
	/* 0x3140: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3145:
	/* 0x3145: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_314a:
	/* 0x314a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314c:
	/* 0x314c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_314f:
	/* 0x314f: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_3151:
	/* 0x3151: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3153:
	/* 0x3153: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3159:
	/* 0x3159: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_315c:
	/* 0x315c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3161:
	/* 0x3161: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3166:
	/* 0x3166: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_316b:
	/* 0x316b: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3171:
	/* 0x3171: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3176:
	/* 0x3176: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_317e:
	/* 0x317e: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3182:
	/* 0x3182: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3189:
	/* 0x3189: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_318c:
	/* 0x318c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3191:
	/* 0x3191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3193:
	/* 0x3193: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3197:
	/* 0x3197: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_319f:
	/* 0x319f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_31a2:
	/* 0x31a2: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_31aa:
	/* 0x31aa: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_31b3:
	/* 0x31b3: lea    rdx,[r13+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_31ba:
	/* 0x31ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31bf:
	/* 0x31bf: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31c4:
	/* 0x31c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31c9:
	/* 0x31c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31cb:
	/* 0x31cb: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_31cd:
	/* 0x31cd: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_31d3:
	/* 0x31d3: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_31d9:
	/* 0x31d9: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_31dc:
	/* 0x31dc: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_31e1:
	/* 0x31e1: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31e6:
	/* 0x31e6: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31eb:
	/* 0x31eb: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_31f1:
	/* 0x31f1: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_31f6:
	/* 0x31f6: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_31fe:
	/* 0x31fe: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3202:
	/* 0x3202: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3209:
	/* 0x3209: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_320e:
	/* 0x320e: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3213:
	/* 0x3213: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3215:
	/* 0x3215: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3218:
	/* 0x3218: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_321a:
	/* 0x321a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_321c:
	/* 0x321c: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3222:
	/* 0x3222: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3225:
	/* 0x3225: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_322a:
	/* 0x322a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_322f:
	/* 0x322f: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3234:
	/* 0x3234: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_323a:
	/* 0x323a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_323f:
	/* 0x323f: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3247:
	/* 0x3247: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_324b:
	/* 0x324b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3252:
	/* 0x3252: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3255:
	/* 0x3255: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_325a:
	/* 0x325a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325c:
	/* 0x325c: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3260:
	/* 0x3260: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3268:
	/* 0x3268: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_326b:
	/* 0x326b: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3273:
	/* 0x3273: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_327c:
	/* 0x327c: lea    rdx,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_3283:
	/* 0x3283: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3288:
	/* 0x3288: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_328d:
	/* 0x328d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3292:
	/* 0x3292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3294:
	/* 0x3294: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_3296:
	/* 0x3296: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_329c:
	/* 0x329c: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_32a2:
	/* 0x32a2: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32a5:
	/* 0x32a5: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_32aa:
	/* 0x32aa: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32af:
	/* 0x32af: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32b4:
	/* 0x32b4: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_32ba:
	/* 0x32ba: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_32bf:
	/* 0x32bf: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_32c7:
	/* 0x32c7: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_32cb:
	/* 0x32cb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_32d2:
	/* 0x32d2: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32d7:
	/* 0x32d7: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_32dc:
	/* 0x32dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32de:
	/* 0x32de: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32e1:
	/* 0x32e1: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_32e3:
	/* 0x32e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_32e5:
	/* 0x32e5: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_32eb:
	/* 0x32eb: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_32ee:
	/* 0x32ee: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_32f3:
	/* 0x32f3: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32f8:
	/* 0x32f8: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32fd:
	/* 0x32fd: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3303:
	/* 0x3303: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3308:
	/* 0x3308: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3310:
	/* 0x3310: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3314:
	/* 0x3314: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_331b:
	/* 0x331b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_331e:
	/* 0x331e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3323:
	/* 0x3323: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3325:
	/* 0x3325: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3329:
	/* 0x3329: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3331:
	/* 0x3331: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3334:
	/* 0x3334: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_333c:
	/* 0x333c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3345:
	/* 0x3345: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_334c:
	/* 0x334c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3351:
	/* 0x3351: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3356:
	/* 0x3356: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_335b:
	/* 0x335b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335d:
	/* 0x335d: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_335f:
	/* 0x335f: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3365:
	/* 0x3365: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_336b:
	/* 0x336b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_336e:
	/* 0x336e: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3373:
	/* 0x3373: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3378:
	/* 0x3378: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337d:
	/* 0x337d: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3383:
	/* 0x3383: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3388:
	/* 0x3388: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3390:
	/* 0x3390: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3394:
	/* 0x3394: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_339b:
	/* 0x339b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33a0:
	/* 0x33a0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_33a5:
	/* 0x33a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a7:
	/* 0x33a7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33aa:
	/* 0x33aa: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_33ac:
	/* 0x33ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33ae:
	/* 0x33ae: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_33b4:
	/* 0x33b4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33b7:
	/* 0x33b7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_33bc:
	/* 0x33bc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33c1:
	/* 0x33c1: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_33c6:
	/* 0x33c6: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_33cc:
	/* 0x33cc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33d1:
	/* 0x33d1: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_33d9:
	/* 0x33d9: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_33dd:
	/* 0x33dd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_33e4:
	/* 0x33e4: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_33e7:
	/* 0x33e7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_33ec:
	/* 0x33ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ee:
	/* 0x33ee: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_33f2:
	/* 0x33f2: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_33fa:
	/* 0x33fa: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_33fd:
	/* 0x33fd: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3405:
	/* 0x3405: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_340e:
	/* 0x340e: lea    rdx,[r13+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_3415:
	/* 0x3415: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_341a:
	/* 0x341a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_341f:
	/* 0x341f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3424:
	/* 0x3424: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3426:
	/* 0x3426: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_3428:
	/* 0x3428: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_342e:
	/* 0x342e: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_3434:
	/* 0x3434: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3437:
	/* 0x3437: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_343c:
	/* 0x343c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3441:
	/* 0x3441: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3446:
	/* 0x3446: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_344c:
	/* 0x344c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3451:
	/* 0x3451: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3459:
	/* 0x3459: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_345d:
	/* 0x345d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3464:
	/* 0x3464: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3469:
	/* 0x3469: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_346e:
	/* 0x346e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3470:
	/* 0x3470: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3473:
	/* 0x3473: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_3475:
	/* 0x3475: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3477:
	/* 0x3477: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_347d:
	/* 0x347d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3480:
	/* 0x3480: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3485:
	/* 0x3485: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_348a:
	/* 0x348a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348f:
	/* 0x348f: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3495:
	/* 0x3495: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_349a:
	/* 0x349a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_34a2:
	/* 0x34a2: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_34a6:
	/* 0x34a6: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_34ad:
	/* 0x34ad: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_34b0:
	/* 0x34b0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_34b5:
	/* 0x34b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b7:
	/* 0x34b7: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_34bb:
	/* 0x34bb: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_34c3:
	/* 0x34c3: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_34c6:
	/* 0x34c6: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_34ce:
	/* 0x34ce: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_34d7:
	/* 0x34d7: lea    rdx,[r13+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_34de:
	/* 0x34de: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_34e3:
	/* 0x34e3: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34e8:
	/* 0x34e8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_34ed:
	/* 0x34ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34ef:
	/* 0x34ef: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_34f1:
	/* 0x34f1: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_34f7:
	/* 0x34f7: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_34fd:
	/* 0x34fd: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3500:
	/* 0x3500: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3505:
	/* 0x3505: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_350a:
	/* 0x350a: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_350f:
	/* 0x350f: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3515:
	/* 0x3515: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_351a:
	/* 0x351a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3522:
	/* 0x3522: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3526:
	/* 0x3526: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_352d:
	/* 0x352d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3532:
	/* 0x3532: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3537:
	/* 0x3537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3539:
	/* 0x3539: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_353c:
	/* 0x353c: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_353e:
	/* 0x353e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3540:
	/* 0x3540: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3546:
	/* 0x3546: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3549:
	/* 0x3549: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_354e:
	/* 0x354e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3553:
	/* 0x3553: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3558:
	/* 0x3558: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_355e:
	/* 0x355e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3563:
	/* 0x3563: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_356b:
	/* 0x356b: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_356f:
	/* 0x356f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3576:
	/* 0x3576: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3579:
	/* 0x3579: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_357e:
	/* 0x357e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3580:
	/* 0x3580: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3584:
	/* 0x3584: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_358c:
	/* 0x358c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_358f:
	/* 0x358f: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3597:
	/* 0x3597: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_35a0:
	/* 0x35a0: lea    rdx,[r13+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_35a7:
	/* 0x35a7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_35ac:
	/* 0x35ac: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35b1:
	/* 0x35b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_35b6:
	/* 0x35b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35b8:
	/* 0x35b8: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_35ba:
	/* 0x35ba: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_35c0:
	/* 0x35c0: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_35c6:
	/* 0x35c6: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_35c9:
	/* 0x35c9: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_35ce:
	/* 0x35ce: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35d3:
	/* 0x35d3: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35d8:
	/* 0x35d8: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_35de:
	/* 0x35de: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_35e3:
	/* 0x35e3: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_35eb:
	/* 0x35eb: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_35ef:
	/* 0x35ef: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_35f6:
	/* 0x35f6: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35fb:
	/* 0x35fb: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3600:
	/* 0x3600: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3602:
	/* 0x3602: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3605:
	/* 0x3605: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_3607:
	/* 0x3607: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3609:
	/* 0x3609: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_360f:
	/* 0x360f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3612:
	/* 0x3612: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3617:
	/* 0x3617: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_361c:
	/* 0x361c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3621:
	/* 0x3621: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3627:
	/* 0x3627: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_362c:
	/* 0x362c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3634:
	/* 0x3634: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3638:
	/* 0x3638: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_363f:
	/* 0x363f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3642:
	/* 0x3642: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3647:
	/* 0x3647: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3649:
	/* 0x3649: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_364d:
	/* 0x364d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3655:
	/* 0x3655: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3658:
	/* 0x3658: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3660:
	/* 0x3660: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3669:
	/* 0x3669: lea    rdx,[r13+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_3670:
	/* 0x3670: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3675:
	/* 0x3675: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_367a:
	/* 0x367a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_367f:
	/* 0x367f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3681:
	/* 0x3681: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_3683:
	/* 0x3683: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3689:
	/* 0x3689: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_368f:
	/* 0x368f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3692:
	/* 0x3692: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3697:
	/* 0x3697: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_369c:
	/* 0x369c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36a1:
	/* 0x36a1: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_36a7:
	/* 0x36a7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_36ac:
	/* 0x36ac: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36b4:
	/* 0x36b4: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_36b8:
	/* 0x36b8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_36bf:
	/* 0x36bf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36c4:
	/* 0x36c4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_36c9:
	/* 0x36c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36cb:
	/* 0x36cb: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36ce:
	/* 0x36ce: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_36d0:
	/* 0x36d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36d2:
	/* 0x36d2: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_36d8:
	/* 0x36d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_36db:
	/* 0x36db: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_36e0:
	/* 0x36e0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36e5:
	/* 0x36e5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36ea:
	/* 0x36ea: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_36f0:
	/* 0x36f0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_36f5:
	/* 0x36f5: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_36fd:
	/* 0x36fd: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3701:
	/* 0x3701: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3708:
	/* 0x3708: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_370b:
	/* 0x370b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3710:
	/* 0x3710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3712:
	/* 0x3712: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3716:
	/* 0x3716: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_371e:
	/* 0x371e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3721:
	/* 0x3721: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3729:
	/* 0x3729: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3732:
	/* 0x3732: lea    rdx,[r13+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_3739:
	/* 0x3739: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_373e:
	/* 0x373e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3743:
	/* 0x3743: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3748:
	/* 0x3748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_374a:
	/* 0x374a: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_374c:
	/* 0x374c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3752:
	/* 0x3752: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_3758:
	/* 0x3758: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_375b:
	/* 0x375b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3760:
	/* 0x3760: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3765:
	/* 0x3765: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_376a:
	/* 0x376a: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3770:
	/* 0x3770: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3775:
	/* 0x3775: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_377d:
	/* 0x377d: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3781:
	/* 0x3781: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3788:
	/* 0x3788: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_378d:
	/* 0x378d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3792:
	/* 0x3792: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3794:
	/* 0x3794: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3797:
	/* 0x3797: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_3799:
	/* 0x3799: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_379b:
	/* 0x379b: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_37a1:
	/* 0x37a1: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37a4:
	/* 0x37a4: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_37a9:
	/* 0x37a9: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37ae:
	/* 0x37ae: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37b3:
	/* 0x37b3: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_37b9:
	/* 0x37b9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_37be:
	/* 0x37be: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_37c6:
	/* 0x37c6: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_37ca:
	/* 0x37ca: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_37d1:
	/* 0x37d1: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_37d4:
	/* 0x37d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_37d9:
	/* 0x37d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37db:
	/* 0x37db: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_37df:
	/* 0x37df: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_37e7:
	/* 0x37e7: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_37ea:
	/* 0x37ea: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_37f2:
	/* 0x37f2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_37fb:
	/* 0x37fb: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_3802:
	/* 0x3802: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3807:
	/* 0x3807: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_380c:
	/* 0x380c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3811:
	/* 0x3811: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3813:
	/* 0x3813: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3815:
	/* 0x3815: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_381b:
	/* 0x381b: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_3821:
	/* 0x3821: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3824:
	/* 0x3824: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3829:
	/* 0x3829: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_382e:
	/* 0x382e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3833:
	/* 0x3833: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3839:
	/* 0x3839: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_383e:
	/* 0x383e: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3846:
	/* 0x3846: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_384a:
	/* 0x384a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3851:
	/* 0x3851: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3856:
	/* 0x3856: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
	return 14427ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14427ULL: goto x86_l_385b;
	case 14429ULL: goto x86_l_385d;
	case 14432ULL: goto x86_l_3860;
	case 14434ULL: goto x86_l_3862;
	case 14436ULL: goto x86_l_3864;
	case 14442ULL: goto x86_l_386a;
	case 14445ULL: goto x86_l_386d;
	case 14450ULL: goto x86_l_3872;
	case 14455ULL: goto x86_l_3877;
	case 14460ULL: goto x86_l_387c;
	case 14466ULL: goto x86_l_3882;
	case 14471ULL: goto x86_l_3887;
	case 14479ULL: goto x86_l_388f;
	case 14483ULL: goto x86_l_3893;
	case 14490ULL: goto x86_l_389a;
	case 14493ULL: goto x86_l_389d;
	case 14498ULL: goto x86_l_38a2;
	case 14500ULL: goto x86_l_38a4;
	case 14504ULL: goto x86_l_38a8;
	case 14512ULL: goto x86_l_38b0;
	case 14515ULL: goto x86_l_38b3;
	case 14523ULL: goto x86_l_38bb;
	case 14532ULL: goto x86_l_38c4;
	case 14539ULL: goto x86_l_38cb;
	case 14544ULL: goto x86_l_38d0;
	case 14549ULL: goto x86_l_38d5;
	case 14554ULL: goto x86_l_38da;
	case 14556ULL: goto x86_l_38dc;
	case 14558ULL: goto x86_l_38de;
	case 14564ULL: goto x86_l_38e4;
	case 14570ULL: goto x86_l_38ea;
	case 14573ULL: goto x86_l_38ed;
	case 14578ULL: goto x86_l_38f2;
	case 14583ULL: goto x86_l_38f7;
	case 14588ULL: goto x86_l_38fc;
	case 14594ULL: goto x86_l_3902;
	case 14599ULL: goto x86_l_3907;
	case 14607ULL: goto x86_l_390f;
	case 14611ULL: goto x86_l_3913;
	case 14618ULL: goto x86_l_391a;
	case 14623ULL: goto x86_l_391f;
	case 14628ULL: goto x86_l_3924;
	case 14630ULL: goto x86_l_3926;
	case 14633ULL: goto x86_l_3929;
	case 14635ULL: goto x86_l_392b;
	case 14637ULL: goto x86_l_392d;
	case 14643ULL: goto x86_l_3933;
	case 14646ULL: goto x86_l_3936;
	case 14651ULL: goto x86_l_393b;
	case 14656ULL: goto x86_l_3940;
	case 14661ULL: goto x86_l_3945;
	case 14667ULL: goto x86_l_394b;
	case 14672ULL: goto x86_l_3950;
	case 14680ULL: goto x86_l_3958;
	case 14684ULL: goto x86_l_395c;
	case 14691ULL: goto x86_l_3963;
	case 14694ULL: goto x86_l_3966;
	case 14699ULL: goto x86_l_396b;
	case 14701ULL: goto x86_l_396d;
	case 14705ULL: goto x86_l_3971;
	case 14713ULL: goto x86_l_3979;
	case 14716ULL: goto x86_l_397c;
	case 14724ULL: goto x86_l_3984;
	case 14733ULL: goto x86_l_398d;
	case 14740ULL: goto x86_l_3994;
	case 14745ULL: goto x86_l_3999;
	case 14750ULL: goto x86_l_399e;
	case 14755ULL: goto x86_l_39a3;
	case 14757ULL: goto x86_l_39a5;
	case 14759ULL: goto x86_l_39a7;
	case 14765ULL: goto x86_l_39ad;
	case 14771ULL: goto x86_l_39b3;
	case 14774ULL: goto x86_l_39b6;
	case 14779ULL: goto x86_l_39bb;
	case 14784ULL: goto x86_l_39c0;
	case 14789ULL: goto x86_l_39c5;
	case 14795ULL: goto x86_l_39cb;
	case 14800ULL: goto x86_l_39d0;
	case 14808ULL: goto x86_l_39d8;
	case 14812ULL: goto x86_l_39dc;
	case 14819ULL: goto x86_l_39e3;
	case 14824ULL: goto x86_l_39e8;
	case 14829ULL: goto x86_l_39ed;
	case 14831ULL: goto x86_l_39ef;
	case 14834ULL: goto x86_l_39f2;
	case 14836ULL: goto x86_l_39f4;
	case 14838ULL: goto x86_l_39f6;
	case 14844ULL: goto x86_l_39fc;
	case 14847ULL: goto x86_l_39ff;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14862ULL: goto x86_l_3a0e;
	case 14868ULL: goto x86_l_3a14;
	case 14873ULL: goto x86_l_3a19;
	case 14881ULL: goto x86_l_3a21;
	case 14885ULL: goto x86_l_3a25;
	case 14892ULL: goto x86_l_3a2c;
	case 14895ULL: goto x86_l_3a2f;
	case 14900ULL: goto x86_l_3a34;
	case 14902ULL: goto x86_l_3a36;
	case 14906ULL: goto x86_l_3a3a;
	case 14914ULL: goto x86_l_3a42;
	case 14917ULL: goto x86_l_3a45;
	case 14925ULL: goto x86_l_3a4d;
	case 14934ULL: goto x86_l_3a56;
	case 14941ULL: goto x86_l_3a5d;
	case 14946ULL: goto x86_l_3a62;
	case 14951ULL: goto x86_l_3a67;
	case 14956ULL: goto x86_l_3a6c;
	case 14959ULL: goto x86_l_3a6f;
	case 14961ULL: goto x86_l_3a71;
	case 14963ULL: goto x86_l_3a73;
	case 14969ULL: goto x86_l_3a79;
	case 14975ULL: goto x86_l_3a7f;
	case 14978ULL: goto x86_l_3a82;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14993ULL: goto x86_l_3a91;
	case 14999ULL: goto x86_l_3a97;
	case 15004ULL: goto x86_l_3a9c;
	case 15012ULL: goto x86_l_3aa4;
	case 15016ULL: goto x86_l_3aa8;
	case 15023ULL: goto x86_l_3aaf;
	case 15028ULL: goto x86_l_3ab4;
	case 15033ULL: goto x86_l_3ab9;
	case 15035ULL: goto x86_l_3abb;
	case 15038ULL: goto x86_l_3abe;
	case 15040ULL: goto x86_l_3ac0;
	case 15042ULL: goto x86_l_3ac2;
	case 15048ULL: goto x86_l_3ac8;
	case 15051ULL: goto x86_l_3acb;
	case 15056ULL: goto x86_l_3ad0;
	case 15061ULL: goto x86_l_3ad5;
	case 15066ULL: goto x86_l_3ada;
	case 15072ULL: goto x86_l_3ae0;
	case 15077ULL: goto x86_l_3ae5;
	case 15085ULL: goto x86_l_3aed;
	case 15089ULL: goto x86_l_3af1;
	case 15096ULL: goto x86_l_3af8;
	case 15099ULL: goto x86_l_3afb;
	case 15104ULL: goto x86_l_3b00;
	case 15106ULL: goto x86_l_3b02;
	case 15110ULL: goto x86_l_3b06;
	case 15118ULL: goto x86_l_3b0e;
	case 15121ULL: goto x86_l_3b11;
	case 15129ULL: goto x86_l_3b19;
	case 15137ULL: goto x86_l_3b21;
	case 15140ULL: goto x86_l_3b24;
	case 15145ULL: goto x86_l_3b29;
	case 15147ULL: goto x86_l_3b2b;
	case 15152ULL: goto x86_l_3b30;
	case 15157ULL: goto x86_l_3b35;
	case 15162ULL: goto x86_l_3b3a;
	case 15169ULL: goto x86_l_3b41;
	case 15173ULL: goto x86_l_3b45;
	case 15180ULL: goto x86_l_3b4c;
	case 15185ULL: goto x86_l_3b51;
	case 15190ULL: goto x86_l_3b56;
	case 15192ULL: goto x86_l_3b58;
	case 15196ULL: goto x86_l_3b5c;
	case 15198ULL: goto x86_l_3b5e;
	case 15200ULL: goto x86_l_3b60;
	case 15206ULL: goto x86_l_3b66;
	case 15209ULL: goto x86_l_3b69;
	case 15214ULL: goto x86_l_3b6e;
	case 15219ULL: goto x86_l_3b73;
	case 15224ULL: goto x86_l_3b78;
	case 15230ULL: goto x86_l_3b7e;
	case 15235ULL: goto x86_l_3b83;
	case 15243ULL: goto x86_l_3b8b;
	case 15247ULL: goto x86_l_3b8f;
	case 15254ULL: goto x86_l_3b96;
	case 15259ULL: goto x86_l_3b9b;
	case 15264ULL: goto x86_l_3ba0;
	case 15266ULL: goto x86_l_3ba2;
	case 15271ULL: goto x86_l_3ba7;
	case 15279ULL: goto x86_l_3baf;
	case 15282ULL: goto x86_l_3bb2;
	case 15290ULL: goto x86_l_3bba;
	case 15292ULL: goto x86_l_3bbc;
	case 15297ULL: goto x86_l_3bc1;
	case 15302ULL: goto x86_l_3bc6;
	case 15310ULL: goto x86_l_3bce;
	case 15314ULL: goto x86_l_3bd2;
	case 15321ULL: goto x86_l_3bd9;
	case 15324ULL: goto x86_l_3bdc;
	case 15329ULL: goto x86_l_3be1;
	case 15331ULL: goto x86_l_3be3;
	case 15335ULL: goto x86_l_3be7;
	case 15343ULL: goto x86_l_3bef;
	case 15346ULL: goto x86_l_3bf2;
	case 15354ULL: goto x86_l_3bfa;
	case 15363ULL: goto x86_l_3c03;
	case 15368ULL: goto x86_l_3c08;
	case 15373ULL: goto x86_l_3c0d;
	case 15378ULL: goto x86_l_3c12;
	case 15383ULL: goto x86_l_3c17;
	case 15385ULL: goto x86_l_3c19;
	case 15387ULL: goto x86_l_3c1b;
	case 15393ULL: goto x86_l_3c21;
	case 15399ULL: goto x86_l_3c27;
	case 15402ULL: goto x86_l_3c2a;
	case 15407ULL: goto x86_l_3c2f;
	case 15413ULL: goto x86_l_3c35;
	case 15418ULL: goto x86_l_3c3a;
	case 15426ULL: goto x86_l_3c42;
	case 15430ULL: goto x86_l_3c46;
	case 15437ULL: goto x86_l_3c4d;
	case 15442ULL: goto x86_l_3c52;
	case 15447ULL: goto x86_l_3c57;
	case 15449ULL: goto x86_l_3c59;
	case 15452ULL: goto x86_l_3c5c;
	case 15454ULL: goto x86_l_3c5e;
	case 15456ULL: goto x86_l_3c60;
	case 15462ULL: goto x86_l_3c66;
	case 15465ULL: goto x86_l_3c69;
	case 15470ULL: goto x86_l_3c6e;
	case 15476ULL: goto x86_l_3c74;
	case 15481ULL: goto x86_l_3c79;
	case 15489ULL: goto x86_l_3c81;
	case 15493ULL: goto x86_l_3c85;
	case 15500ULL: goto x86_l_3c8c;
	case 15503ULL: goto x86_l_3c8f;
	case 15508ULL: goto x86_l_3c94;
	case 15510ULL: goto x86_l_3c96;
	case 15514ULL: goto x86_l_3c9a;
	case 15522ULL: goto x86_l_3ca2;
	case 15525ULL: goto x86_l_3ca5;
	case 15533ULL: goto x86_l_3cad;
	case 15542ULL: goto x86_l_3cb6;
	case 15547ULL: goto x86_l_3cbb;
	case 15551ULL: goto x86_l_3cbf;
	case 15556ULL: goto x86_l_3cc4;
	case 15561ULL: goto x86_l_3cc9;
	case 15566ULL: goto x86_l_3cce;
	case 15568ULL: goto x86_l_3cd0;
	case 15570ULL: goto x86_l_3cd2;
	case 15576ULL: goto x86_l_3cd8;
	case 15582ULL: goto x86_l_3cde;
	case 15585ULL: goto x86_l_3ce1;
	case 15590ULL: goto x86_l_3ce6;
	case 15596ULL: goto x86_l_3cec;
	case 15601ULL: goto x86_l_3cf1;
	case 15609ULL: goto x86_l_3cf9;
	case 15613ULL: goto x86_l_3cfd;
	case 15620ULL: goto x86_l_3d04;
	case 15625ULL: goto x86_l_3d09;
	case 15630ULL: goto x86_l_3d0e;
	case 15632ULL: goto x86_l_3d10;
	case 15635ULL: goto x86_l_3d13;
	case 15637ULL: goto x86_l_3d15;
	case 15639ULL: goto x86_l_3d17;
	case 15645ULL: goto x86_l_3d1d;
	case 15648ULL: goto x86_l_3d20;
	case 15653ULL: goto x86_l_3d25;
	case 15659ULL: goto x86_l_3d2b;
	case 15664ULL: goto x86_l_3d30;
	case 15672ULL: goto x86_l_3d38;
	case 15676ULL: goto x86_l_3d3c;
	case 15683ULL: goto x86_l_3d43;
	case 15686ULL: goto x86_l_3d46;
	case 15691ULL: goto x86_l_3d4b;
	case 15693ULL: goto x86_l_3d4d;
	case 15697ULL: goto x86_l_3d51;
	case 15705ULL: goto x86_l_3d59;
	case 15708ULL: goto x86_l_3d5c;
	case 15716ULL: goto x86_l_3d64;
	case 15725ULL: goto x86_l_3d6d;
	case 15730ULL: goto x86_l_3d72;
	case 15734ULL: goto x86_l_3d76;
	case 15739ULL: goto x86_l_3d7b;
	case 15744ULL: goto x86_l_3d80;
	case 15749ULL: goto x86_l_3d85;
	case 15751ULL: goto x86_l_3d87;
	case 15753ULL: goto x86_l_3d89;
	case 15759ULL: goto x86_l_3d8f;
	case 15765ULL: goto x86_l_3d95;
	case 15768ULL: goto x86_l_3d98;
	case 15773ULL: goto x86_l_3d9d;
	case 15779ULL: goto x86_l_3da3;
	case 15784ULL: goto x86_l_3da8;
	case 15792ULL: goto x86_l_3db0;
	case 15796ULL: goto x86_l_3db4;
	case 15803ULL: goto x86_l_3dbb;
	case 15808ULL: goto x86_l_3dc0;
	case 15813ULL: goto x86_l_3dc5;
	case 15815ULL: goto x86_l_3dc7;
	case 15818ULL: goto x86_l_3dca;
	case 15820ULL: goto x86_l_3dcc;
	case 15822ULL: goto x86_l_3dce;
	case 15828ULL: goto x86_l_3dd4;
	case 15831ULL: goto x86_l_3dd7;
	case 15836ULL: goto x86_l_3ddc;
	case 15841ULL: goto x86_l_3de1;
	case 15847ULL: goto x86_l_3de7;
	case 15852ULL: goto x86_l_3dec;
	case 15860ULL: goto x86_l_3df4;
	case 15864ULL: goto x86_l_3df8;
	case 15871ULL: goto x86_l_3dff;
	case 15874ULL: goto x86_l_3e02;
	case 15879ULL: goto x86_l_3e07;
	case 15881ULL: goto x86_l_3e09;
	case 15885ULL: goto x86_l_3e0d;
	case 15893ULL: goto x86_l_3e15;
	case 15896ULL: goto x86_l_3e18;
	case 15904ULL: goto x86_l_3e20;
	case 15913ULL: goto x86_l_3e29;
	case 15918ULL: goto x86_l_3e2e;
	case 15922ULL: goto x86_l_3e32;
	case 15927ULL: goto x86_l_3e37;
	case 15932ULL: goto x86_l_3e3c;
	case 15937ULL: goto x86_l_3e41;
	case 15939ULL: goto x86_l_3e43;
	case 15941ULL: goto x86_l_3e45;
	case 15947ULL: goto x86_l_3e4b;
	case 15953ULL: goto x86_l_3e51;
	case 15956ULL: goto x86_l_3e54;
	case 15961ULL: goto x86_l_3e59;
	case 15966ULL: goto x86_l_3e5e;
	case 15972ULL: goto x86_l_3e64;
	case 15977ULL: goto x86_l_3e69;
	case 15985ULL: goto x86_l_3e71;
	case 15989ULL: goto x86_l_3e75;
	case 15996ULL: goto x86_l_3e7c;
	case 16001ULL: goto x86_l_3e81;
	case 16006ULL: goto x86_l_3e86;
	case 16008ULL: goto x86_l_3e88;
	case 16011ULL: goto x86_l_3e8b;
	case 16013ULL: goto x86_l_3e8d;
	case 16015ULL: goto x86_l_3e8f;
	case 16021ULL: goto x86_l_3e95;
	case 16024ULL: goto x86_l_3e98;
	case 16029ULL: goto x86_l_3e9d;
	case 16034ULL: goto x86_l_3ea2;
	case 16040ULL: goto x86_l_3ea8;
	case 16045ULL: goto x86_l_3ead;
	case 16053ULL: goto x86_l_3eb5;
	case 16057ULL: goto x86_l_3eb9;
	case 16064ULL: goto x86_l_3ec0;
	case 16067ULL: goto x86_l_3ec3;
	case 16072ULL: goto x86_l_3ec8;
	case 16074ULL: goto x86_l_3eca;
	case 16078ULL: goto x86_l_3ece;
	case 16086ULL: goto x86_l_3ed6;
	case 16089ULL: goto x86_l_3ed9;
	case 16097ULL: goto x86_l_3ee1;
	case 16106ULL: goto x86_l_3eea;
	case 16111ULL: goto x86_l_3eef;
	case 16115ULL: goto x86_l_3ef3;
	case 16120ULL: goto x86_l_3ef8;
	case 16125ULL: goto x86_l_3efd;
	case 16130ULL: goto x86_l_3f02;
	case 16132ULL: goto x86_l_3f04;
	case 16134ULL: goto x86_l_3f06;
	case 16140ULL: goto x86_l_3f0c;
	case 16146ULL: goto x86_l_3f12;
	case 16149ULL: goto x86_l_3f15;
	case 16154ULL: goto x86_l_3f1a;
	case 16159ULL: goto x86_l_3f1f;
	case 16165ULL: goto x86_l_3f25;
	case 16170ULL: goto x86_l_3f2a;
	case 16178ULL: goto x86_l_3f32;
	case 16182ULL: goto x86_l_3f36;
	case 16189ULL: goto x86_l_3f3d;
	case 16194ULL: goto x86_l_3f42;
	case 16199ULL: goto x86_l_3f47;
	case 16201ULL: goto x86_l_3f49;
	case 16204ULL: goto x86_l_3f4c;
	case 16206ULL: goto x86_l_3f4e;
	case 16208ULL: goto x86_l_3f50;
	case 16214ULL: goto x86_l_3f56;
	case 16217ULL: goto x86_l_3f59;
	case 16222ULL: goto x86_l_3f5e;
	case 16227ULL: goto x86_l_3f63;
	case 16233ULL: goto x86_l_3f69;
	case 16238ULL: goto x86_l_3f6e;
	case 16246ULL: goto x86_l_3f76;
	case 16250ULL: goto x86_l_3f7a;
	case 16257ULL: goto x86_l_3f81;
	case 16260ULL: goto x86_l_3f84;
	case 16265ULL: goto x86_l_3f89;
	case 16267ULL: goto x86_l_3f8b;
	case 16271ULL: goto x86_l_3f8f;
	case 16279ULL: goto x86_l_3f97;
	default: return 0xffffffffffffffffULL;
	}
x86_l_385b:
	/* 0x385b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_385d:
	/* 0x385d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3860:
	/* 0x3860: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_3862:
	/* 0x3862: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3864:
	/* 0x3864: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_386a:
	/* 0x386a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_386d:
	/* 0x386d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3872:
	/* 0x3872: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3877:
	/* 0x3877: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_387c:
	/* 0x387c: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3882:
	/* 0x3882: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3887:
	/* 0x3887: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_388f:
	/* 0x388f: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3893:
	/* 0x3893: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_389a:
	/* 0x389a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_389d:
	/* 0x389d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38a2:
	/* 0x38a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38a4:
	/* 0x38a4: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38a8:
	/* 0x38a8: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_38b0:
	/* 0x38b0: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_38b3:
	/* 0x38b3: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_38bb:
	/* 0x38bb: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_38c4:
	/* 0x38c4: lea    rdx,[r13+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_38cb:
	/* 0x38cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38d0:
	/* 0x38d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38d5:
	/* 0x38d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_38da:
	/* 0x38da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38dc:
	/* 0x38dc: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_38de:
	/* 0x38de: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_38e4:
	/* 0x38e4: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_38ea:
	/* 0x38ea: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38ed:
	/* 0x38ed: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_38f2:
	/* 0x38f2: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38f7:
	/* 0x38f7: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38fc:
	/* 0x38fc: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3902:
	/* 0x3902: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3907:
	/* 0x3907: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_390f:
	/* 0x390f: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3913:
	/* 0x3913: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_391a:
	/* 0x391a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_391f:
	/* 0x391f: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3924:
	/* 0x3924: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3926:
	/* 0x3926: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3929:
	/* 0x3929: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_392b:
	/* 0x392b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_392d:
	/* 0x392d: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3933:
	/* 0x3933: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3936:
	/* 0x3936: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_393b:
	/* 0x393b: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3940:
	/* 0x3940: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3945:
	/* 0x3945: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_394b:
	/* 0x394b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3950:
	/* 0x3950: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3958:
	/* 0x3958: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_395c:
	/* 0x395c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3963:
	/* 0x3963: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3966:
	/* 0x3966: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_396b:
	/* 0x396b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_396d:
	/* 0x396d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3971:
	/* 0x3971: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3979:
	/* 0x3979: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_397c:
	/* 0x397c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3984:
	/* 0x3984: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_398d:
	/* 0x398d: lea    rdx,[r13+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_3994:
	/* 0x3994: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3999:
	/* 0x3999: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_399e:
	/* 0x399e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_39a3:
	/* 0x39a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39a5:
	/* 0x39a5: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_39a7:
	/* 0x39a7: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_39ad:
	/* 0x39ad: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_39b3:
	/* 0x39b3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39b6:
	/* 0x39b6: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_39bb:
	/* 0x39bb: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39c0:
	/* 0x39c0: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c5:
	/* 0x39c5: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_39cb:
	/* 0x39cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_39d0:
	/* 0x39d0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_39d8:
	/* 0x39d8: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_39dc:
	/* 0x39dc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_39e3:
	/* 0x39e3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39e8:
	/* 0x39e8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_39ed:
	/* 0x39ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ef:
	/* 0x39ef: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39f2:
	/* 0x39f2: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_39f4:
	/* 0x39f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39f6:
	/* 0x39f6: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_39fc:
	/* 0x39fc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_39ff:
	/* 0x39ff: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3a04:
	/* 0x3a04: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a09:
	/* 0x3a09: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a0e:
	/* 0x3a0e: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3a14:
	/* 0x3a14: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a19:
	/* 0x3a19: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3a21:
	/* 0x3a21: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3a25:
	/* 0x3a25: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3a2c:
	/* 0x3a2c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3a2f:
	/* 0x3a2f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3a34:
	/* 0x3a34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a36:
	/* 0x3a36: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a3a:
	/* 0x3a3a: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3a42:
	/* 0x3a42: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3a45:
	/* 0x3a45: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3a4d:
	/* 0x3a4d: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3a56:
	/* 0x3a56: add    r13,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_3a5d:
	/* 0x3a5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3a62:
	/* 0x3a62: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a67:
	/* 0x3a67: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3a6c:
	/* 0x3a6c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a6f:
	/* 0x3a6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a71:
	/* 0x3a71: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_3a73:
	/* 0x3a73: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3a79:
	/* 0x3a79: je     5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24174ULL;
	}
x86_l_3a7f:
	/* 0x3a7f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a82:
	/* 0x3a82: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3a87:
	/* 0x3a87: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a91:
	/* 0x3a91: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3a97:
	/* 0x3a97: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3a9c:
	/* 0x3a9c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3aa4:
	/* 0x3aa4: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3aa8:
	/* 0x3aa8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3aaf:
	/* 0x3aaf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3ab4:
	/* 0x3ab4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3ab9:
	/* 0x3ab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3abb:
	/* 0x3abb: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3abe:
	/* 0x3abe: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_3ac0:
	/* 0x3ac0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ac2:
	/* 0x3ac2: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3ac8:
	/* 0x3ac8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3acb:
	/* 0x3acb: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3ad0:
	/* 0x3ad0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ad5:
	/* 0x3ad5: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ada:
	/* 0x3ada: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3ae0:
	/* 0x3ae0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ae5:
	/* 0x3ae5: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3aed:
	/* 0x3aed: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3af1:
	/* 0x3af1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3af8:
	/* 0x3af8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3afb:
	/* 0x3afb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3b00:
	/* 0x3b00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b02:
	/* 0x3b02: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b06:
	/* 0x3b06: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3b0e:
	/* 0x3b0e: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3b11:
	/* 0x3b11: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3b19:
	/* 0x3b19: mov    DWORD PTR [rsp+0x70],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481039363630ULL);
x86_l_3b21:
	/* 0x3b21: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3b24:
	/* 0x3b24: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_3b29:
	/* 0x3b29: jb     3b30 <trace_security_bprm_check+0x3b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3b30;
	}
x86_l_3b2b:
	/* 0x3b2b: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_3b30:
	/* 0x3b30: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3b35:
	/* 0x3b35: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b3a:
	/* 0x3b3a: movzx  ecx,WORD PTR [rdx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b41:
	/* 0x3b41: lea    rdi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_3b45:
	/* 0x3b45: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3b4c:
	/* 0x3b4c: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3b51:
	/* 0x3b51: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3b56:
	/* 0x3b56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b58:
	/* 0x3b58: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b5c:
	/* 0x3b5c: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_3b5e:
	/* 0x3b5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b60:
	/* 0x3b60: jle    5e6e <trace_security_bprm_check+0x5e6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24174ULL;
	}
x86_l_3b66:
	/* 0x3b66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3b69:
	/* 0x3b69: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3b6e:
	/* 0x3b6e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3b73:
	/* 0x3b73: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b78:
	/* 0x3b78: ja     18f1 <trace_security_bprm_check+0x18f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6385ULL;
	}
x86_l_3b7e:
	/* 0x3b7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b83:
	/* 0x3b83: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3b8b:
	/* 0x3b8b: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b8f:
	/* 0x3b8f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3b96:
	/* 0x3b96: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b9b:
	/* 0x3b9b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ba0:
	/* 0x3ba0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ba2:
	/* 0x3ba2: movzx  eax,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_3ba7:
	/* 0x3ba7: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3baf:
	/* 0x3baf: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bb2:
	/* 0x3bb2: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bba:
	/* 0x3bba: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_3bbc:
	/* 0x3bbc: jmp    18f1 <trace_security_bprm_check+0x18f1> */
	return 6385ULL;
x86_l_3bc1:
	/* 0x3bc1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3bc6:
	/* 0x3bc6: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3bce:
	/* 0x3bce: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3bd2:
	/* 0x3bd2: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3bd9:
	/* 0x3bd9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3bdc:
	/* 0x3bdc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3be1:
	/* 0x3be1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be3:
	/* 0x3be3: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3be7:
	/* 0x3be7: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3bef:
	/* 0x3bef: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3bf2:
	/* 0x3bf2: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3bfa:
	/* 0x3bfa: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3c03:
	/* 0x3c03: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c08:
	/* 0x3c08: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c0d:
	/* 0x3c0d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c12:
	/* 0x3c12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3c17:
	/* 0x3c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c19:
	/* 0x3c19: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3c1b:
	/* 0x3c1b: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3c21:
	/* 0x3c21: je     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6576ULL;
	}
x86_l_3c27:
	/* 0x3c27: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c2a:
	/* 0x3c2a: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3c2f:
	/* 0x3c2f: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3c35:
	/* 0x3c35: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3c3a:
	/* 0x3c3a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c42:
	/* 0x3c42: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3c46:
	/* 0x3c46: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3c4d:
	/* 0x3c4d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c52:
	/* 0x3c52: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3c57:
	/* 0x3c57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c59:
	/* 0x3c59: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c5c:
	/* 0x3c5c: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3c5e:
	/* 0x3c5e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c60:
	/* 0x3c60: jle    19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6576ULL;
	}
x86_l_3c66:
	/* 0x3c66: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c69:
	/* 0x3c69: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3c6e:
	/* 0x3c6e: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3c74:
	/* 0x3c74: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3c79:
	/* 0x3c79: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3c81:
	/* 0x3c81: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3c85:
	/* 0x3c85: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3c8c:
	/* 0x3c8c: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3c8f:
	/* 0x3c8f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3c94:
	/* 0x3c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c96:
	/* 0x3c96: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3c9a:
	/* 0x3c9a: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ca2:
	/* 0x3ca2: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ca5:
	/* 0x3ca5: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3cad:
	/* 0x3cad: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3cb6:
	/* 0x3cb6: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3cbb:
	/* 0x3cbb: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cbf:
	/* 0x3cbf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3cc4:
	/* 0x3cc4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3cc9:
	/* 0x3cc9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3cce:
	/* 0x3cce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cd0:
	/* 0x3cd0: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3cd2:
	/* 0x3cd2: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3cd8:
	/* 0x3cd8: je     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6576ULL;
	}
x86_l_3cde:
	/* 0x3cde: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ce1:
	/* 0x3ce1: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3ce6:
	/* 0x3ce6: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3cec:
	/* 0x3cec: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3cf1:
	/* 0x3cf1: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3cf9:
	/* 0x3cf9: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3cfd:
	/* 0x3cfd: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3d04:
	/* 0x3d04: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d09:
	/* 0x3d09: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3d0e:
	/* 0x3d0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d10:
	/* 0x3d10: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d13:
	/* 0x3d13: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3d15:
	/* 0x3d15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d17:
	/* 0x3d17: jle    19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 6576ULL;
	}
x86_l_3d1d:
	/* 0x3d1d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d20:
	/* 0x3d20: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3d25:
	/* 0x3d25: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3d2b:
	/* 0x3d2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d30:
	/* 0x3d30: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3d38:
	/* 0x3d38: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3d3c:
	/* 0x3d3c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3d43:
	/* 0x3d43: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3d46:
	/* 0x3d46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3d4b:
	/* 0x3d4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d4d:
	/* 0x3d4d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d51:
	/* 0x3d51: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3d59:
	/* 0x3d59: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3d5c:
	/* 0x3d5c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3d64:
	/* 0x3d64: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3d6d:
	/* 0x3d6d: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3d72:
	/* 0x3d72: lea    rdx,[rax+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d76:
	/* 0x3d76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3d7b:
	/* 0x3d7b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d80:
	/* 0x3d80: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d85:
	/* 0x3d85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d87:
	/* 0x3d87: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_3d89:
	/* 0x3d89: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3d8f:
	/* 0x3d8f: je     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6576ULL;
	}
x86_l_3d95:
	/* 0x3d95: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3d98:
	/* 0x3d98: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3d9d:
	/* 0x3d9d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3da3:
	/* 0x3da3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3da8:
	/* 0x3da8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3db0:
	/* 0x3db0: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3db4:
	/* 0x3db4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3dbb:
	/* 0x3dbb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3dc0:
	/* 0x3dc0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3dc5:
	/* 0x3dc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc7:
	/* 0x3dc7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3dca:
	/* 0x3dca: mov    cl,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_3dcc:
	/* 0x3dcc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dce:
	/* 0x3dce: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_3dd4:
	/* 0x3dd4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3dd7:
	/* 0x3dd7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3ddc:
	/* 0x3ddc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3de1:
	/* 0x3de1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3de7:
	/* 0x3de7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3dec:
	/* 0x3dec: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3df4:
	/* 0x3df4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3df8:
	/* 0x3df8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3dff:
	/* 0x3dff: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3e02:
	/* 0x3e02: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3e07:
	/* 0x3e07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e09:
	/* 0x3e09: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e0d:
	/* 0x3e0d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3e15:
	/* 0x3e15: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3e18:
	/* 0x3e18: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3e20:
	/* 0x3e20: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3e29:
	/* 0x3e29: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3e2e:
	/* 0x3e2e: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e32:
	/* 0x3e32: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3e37:
	/* 0x3e37: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e3c:
	/* 0x3e3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3e41:
	/* 0x3e41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e43:
	/* 0x3e43: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_3e45:
	/* 0x3e45: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3e4b:
	/* 0x3e4b: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_3e51:
	/* 0x3e51: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e54:
	/* 0x3e54: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3e59:
	/* 0x3e59: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e5e:
	/* 0x3e5e: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3e64:
	/* 0x3e64: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3e69:
	/* 0x3e69: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3e71:
	/* 0x3e71: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3e75:
	/* 0x3e75: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3e7c:
	/* 0x3e7c: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e81:
	/* 0x3e81: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3e86:
	/* 0x3e86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e88:
	/* 0x3e88: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e8b:
	/* 0x3e8b: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_3e8d:
	/* 0x3e8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e8f:
	/* 0x3e8f: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_3e95:
	/* 0x3e95: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3e98:
	/* 0x3e98: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3e9d:
	/* 0x3e9d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ea2:
	/* 0x3ea2: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3ea8:
	/* 0x3ea8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ead:
	/* 0x3ead: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3eb5:
	/* 0x3eb5: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3eb9:
	/* 0x3eb9: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3ec0:
	/* 0x3ec0: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3ec3:
	/* 0x3ec3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3ec8:
	/* 0x3ec8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3eca:
	/* 0x3eca: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ece:
	/* 0x3ece: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3ed6:
	/* 0x3ed6: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_3ed9:
	/* 0x3ed9: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3ee1:
	/* 0x3ee1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3eea:
	/* 0x3eea: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3eef:
	/* 0x3eef: lea    rdx,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ef3:
	/* 0x3ef3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3ef8:
	/* 0x3ef8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3efd:
	/* 0x3efd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3f02:
	/* 0x3f02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f04:
	/* 0x3f04: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_3f06:
	/* 0x3f06: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3f0c:
	/* 0x3f0c: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_3f12:
	/* 0x3f12: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f15:
	/* 0x3f15: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3f1a:
	/* 0x3f1a: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f1f:
	/* 0x3f1f: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3f25:
	/* 0x3f25: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3f2a:
	/* 0x3f2a: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f32:
	/* 0x3f32: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3f36:
	/* 0x3f36: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3f3d:
	/* 0x3f3d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f42:
	/* 0x3f42: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_3f47:
	/* 0x3f47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f49:
	/* 0x3f49: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f4c:
	/* 0x3f4c: mov    cl,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 5ULL);
x86_l_3f4e:
	/* 0x3f4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3f50:
	/* 0x3f50: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_3f56:
	/* 0x3f56: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f59:
	/* 0x3f59: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_3f5e:
	/* 0x3f5e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f63:
	/* 0x3f63: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3f69:
	/* 0x3f69: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3f6e:
	/* 0x3f6e: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3f76:
	/* 0x3f76: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3f7a:
	/* 0x3f7a: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_3f81:
	/* 0x3f81: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3f84:
	/* 0x3f84: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3f89:
	/* 0x3f89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8b:
	/* 0x3f8b: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3f8f:
	/* 0x3f8f: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_3f97:
	/* 0x3f97: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
	return 16282ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 16282ULL: goto x86_l_3f9a;
	case 16290ULL: goto x86_l_3fa2;
	case 16299ULL: goto x86_l_3fab;
	case 16304ULL: goto x86_l_3fb0;
	case 16308ULL: goto x86_l_3fb4;
	case 16313ULL: goto x86_l_3fb9;
	case 16318ULL: goto x86_l_3fbe;
	case 16323ULL: goto x86_l_3fc3;
	case 16325ULL: goto x86_l_3fc5;
	case 16327ULL: goto x86_l_3fc7;
	case 16333ULL: goto x86_l_3fcd;
	case 16339ULL: goto x86_l_3fd3;
	case 16342ULL: goto x86_l_3fd6;
	case 16347ULL: goto x86_l_3fdb;
	case 16352ULL: goto x86_l_3fe0;
	case 16358ULL: goto x86_l_3fe6;
	case 16363ULL: goto x86_l_3feb;
	case 16371ULL: goto x86_l_3ff3;
	case 16375ULL: goto x86_l_3ff7;
	case 16382ULL: goto x86_l_3ffe;
	case 16387ULL: goto x86_l_4003;
	case 16392ULL: goto x86_l_4008;
	case 16394ULL: goto x86_l_400a;
	case 16397ULL: goto x86_l_400d;
	case 16399ULL: goto x86_l_400f;
	case 16401ULL: goto x86_l_4011;
	case 16407ULL: goto x86_l_4017;
	case 16410ULL: goto x86_l_401a;
	case 16415ULL: goto x86_l_401f;
	case 16420ULL: goto x86_l_4024;
	case 16426ULL: goto x86_l_402a;
	case 16431ULL: goto x86_l_402f;
	case 16439ULL: goto x86_l_4037;
	case 16443ULL: goto x86_l_403b;
	case 16450ULL: goto x86_l_4042;
	case 16453ULL: goto x86_l_4045;
	case 16458ULL: goto x86_l_404a;
	case 16460ULL: goto x86_l_404c;
	case 16464ULL: goto x86_l_4050;
	case 16472ULL: goto x86_l_4058;
	case 16475ULL: goto x86_l_405b;
	case 16483ULL: goto x86_l_4063;
	case 16492ULL: goto x86_l_406c;
	case 16497ULL: goto x86_l_4071;
	case 16501ULL: goto x86_l_4075;
	case 16506ULL: goto x86_l_407a;
	case 16511ULL: goto x86_l_407f;
	case 16516ULL: goto x86_l_4084;
	case 16518ULL: goto x86_l_4086;
	case 16520ULL: goto x86_l_4088;
	case 16526ULL: goto x86_l_408e;
	case 16532ULL: goto x86_l_4094;
	case 16535ULL: goto x86_l_4097;
	case 16540ULL: goto x86_l_409c;
	case 16545ULL: goto x86_l_40a1;
	case 16551ULL: goto x86_l_40a7;
	case 16556ULL: goto x86_l_40ac;
	case 16564ULL: goto x86_l_40b4;
	case 16568ULL: goto x86_l_40b8;
	case 16575ULL: goto x86_l_40bf;
	case 16580ULL: goto x86_l_40c4;
	case 16585ULL: goto x86_l_40c9;
	case 16587ULL: goto x86_l_40cb;
	case 16590ULL: goto x86_l_40ce;
	case 16592ULL: goto x86_l_40d0;
	case 16594ULL: goto x86_l_40d2;
	case 16600ULL: goto x86_l_40d8;
	case 16603ULL: goto x86_l_40db;
	case 16608ULL: goto x86_l_40e0;
	case 16613ULL: goto x86_l_40e5;
	case 16619ULL: goto x86_l_40eb;
	case 16624ULL: goto x86_l_40f0;
	case 16632ULL: goto x86_l_40f8;
	case 16636ULL: goto x86_l_40fc;
	case 16643ULL: goto x86_l_4103;
	case 16646ULL: goto x86_l_4106;
	case 16651ULL: goto x86_l_410b;
	case 16653ULL: goto x86_l_410d;
	case 16657ULL: goto x86_l_4111;
	case 16665ULL: goto x86_l_4119;
	case 16668ULL: goto x86_l_411c;
	case 16676ULL: goto x86_l_4124;
	case 16685ULL: goto x86_l_412d;
	case 16690ULL: goto x86_l_4132;
	case 16694ULL: goto x86_l_4136;
	case 16699ULL: goto x86_l_413b;
	case 16704ULL: goto x86_l_4140;
	case 16709ULL: goto x86_l_4145;
	case 16711ULL: goto x86_l_4147;
	case 16713ULL: goto x86_l_4149;
	case 16719ULL: goto x86_l_414f;
	case 16725ULL: goto x86_l_4155;
	case 16728ULL: goto x86_l_4158;
	case 16733ULL: goto x86_l_415d;
	case 16738ULL: goto x86_l_4162;
	case 16744ULL: goto x86_l_4168;
	case 16749ULL: goto x86_l_416d;
	case 16757ULL: goto x86_l_4175;
	case 16761ULL: goto x86_l_4179;
	case 16768ULL: goto x86_l_4180;
	case 16773ULL: goto x86_l_4185;
	case 16778ULL: goto x86_l_418a;
	case 16780ULL: goto x86_l_418c;
	case 16783ULL: goto x86_l_418f;
	case 16785ULL: goto x86_l_4191;
	case 16787ULL: goto x86_l_4193;
	case 16793ULL: goto x86_l_4199;
	case 16796ULL: goto x86_l_419c;
	case 16801ULL: goto x86_l_41a1;
	case 16806ULL: goto x86_l_41a6;
	case 16812ULL: goto x86_l_41ac;
	case 16817ULL: goto x86_l_41b1;
	case 16825ULL: goto x86_l_41b9;
	case 16829ULL: goto x86_l_41bd;
	case 16836ULL: goto x86_l_41c4;
	case 16839ULL: goto x86_l_41c7;
	case 16844ULL: goto x86_l_41cc;
	case 16846ULL: goto x86_l_41ce;
	case 16850ULL: goto x86_l_41d2;
	case 16858ULL: goto x86_l_41da;
	case 16861ULL: goto x86_l_41dd;
	case 16869ULL: goto x86_l_41e5;
	case 16878ULL: goto x86_l_41ee;
	case 16883ULL: goto x86_l_41f3;
	case 16887ULL: goto x86_l_41f7;
	case 16892ULL: goto x86_l_41fc;
	case 16897ULL: goto x86_l_4201;
	case 16902ULL: goto x86_l_4206;
	case 16904ULL: goto x86_l_4208;
	case 16906ULL: goto x86_l_420a;
	case 16912ULL: goto x86_l_4210;
	case 16918ULL: goto x86_l_4216;
	case 16921ULL: goto x86_l_4219;
	case 16926ULL: goto x86_l_421e;
	case 16931ULL: goto x86_l_4223;
	case 16937ULL: goto x86_l_4229;
	case 16942ULL: goto x86_l_422e;
	case 16950ULL: goto x86_l_4236;
	case 16954ULL: goto x86_l_423a;
	case 16961ULL: goto x86_l_4241;
	case 16966ULL: goto x86_l_4246;
	case 16971ULL: goto x86_l_424b;
	case 16973ULL: goto x86_l_424d;
	case 16976ULL: goto x86_l_4250;
	case 16978ULL: goto x86_l_4252;
	case 16980ULL: goto x86_l_4254;
	case 16986ULL: goto x86_l_425a;
	case 16989ULL: goto x86_l_425d;
	case 16994ULL: goto x86_l_4262;
	case 16999ULL: goto x86_l_4267;
	case 17005ULL: goto x86_l_426d;
	case 17010ULL: goto x86_l_4272;
	case 17018ULL: goto x86_l_427a;
	case 17022ULL: goto x86_l_427e;
	case 17029ULL: goto x86_l_4285;
	case 17032ULL: goto x86_l_4288;
	case 17037ULL: goto x86_l_428d;
	case 17039ULL: goto x86_l_428f;
	case 17043ULL: goto x86_l_4293;
	case 17051ULL: goto x86_l_429b;
	case 17054ULL: goto x86_l_429e;
	case 17062ULL: goto x86_l_42a6;
	case 17071ULL: goto x86_l_42af;
	case 17076ULL: goto x86_l_42b4;
	case 17080ULL: goto x86_l_42b8;
	case 17085ULL: goto x86_l_42bd;
	case 17090ULL: goto x86_l_42c2;
	case 17095ULL: goto x86_l_42c7;
	case 17097ULL: goto x86_l_42c9;
	case 17099ULL: goto x86_l_42cb;
	case 17105ULL: goto x86_l_42d1;
	case 17111ULL: goto x86_l_42d7;
	case 17114ULL: goto x86_l_42da;
	case 17119ULL: goto x86_l_42df;
	case 17124ULL: goto x86_l_42e4;
	case 17130ULL: goto x86_l_42ea;
	case 17135ULL: goto x86_l_42ef;
	case 17143ULL: goto x86_l_42f7;
	case 17147ULL: goto x86_l_42fb;
	case 17154ULL: goto x86_l_4302;
	case 17159ULL: goto x86_l_4307;
	case 17164ULL: goto x86_l_430c;
	case 17166ULL: goto x86_l_430e;
	case 17169ULL: goto x86_l_4311;
	case 17171ULL: goto x86_l_4313;
	case 17173ULL: goto x86_l_4315;
	case 17179ULL: goto x86_l_431b;
	case 17182ULL: goto x86_l_431e;
	case 17187ULL: goto x86_l_4323;
	case 17192ULL: goto x86_l_4328;
	case 17198ULL: goto x86_l_432e;
	case 17203ULL: goto x86_l_4333;
	case 17211ULL: goto x86_l_433b;
	case 17215ULL: goto x86_l_433f;
	case 17222ULL: goto x86_l_4346;
	case 17225ULL: goto x86_l_4349;
	case 17230ULL: goto x86_l_434e;
	case 17232ULL: goto x86_l_4350;
	case 17236ULL: goto x86_l_4354;
	case 17244ULL: goto x86_l_435c;
	case 17247ULL: goto x86_l_435f;
	case 17255ULL: goto x86_l_4367;
	case 17264ULL: goto x86_l_4370;
	case 17269ULL: goto x86_l_4375;
	case 17273ULL: goto x86_l_4379;
	case 17278ULL: goto x86_l_437e;
	case 17283ULL: goto x86_l_4383;
	case 17288ULL: goto x86_l_4388;
	case 17290ULL: goto x86_l_438a;
	case 17292ULL: goto x86_l_438c;
	case 17298ULL: goto x86_l_4392;
	case 17304ULL: goto x86_l_4398;
	case 17307ULL: goto x86_l_439b;
	case 17312ULL: goto x86_l_43a0;
	case 17317ULL: goto x86_l_43a5;
	case 17323ULL: goto x86_l_43ab;
	case 17328ULL: goto x86_l_43b0;
	case 17336ULL: goto x86_l_43b8;
	case 17340ULL: goto x86_l_43bc;
	case 17347ULL: goto x86_l_43c3;
	case 17352ULL: goto x86_l_43c8;
	case 17357ULL: goto x86_l_43cd;
	case 17359ULL: goto x86_l_43cf;
	case 17362ULL: goto x86_l_43d2;
	case 17364ULL: goto x86_l_43d4;
	case 17366ULL: goto x86_l_43d6;
	case 17372ULL: goto x86_l_43dc;
	case 17375ULL: goto x86_l_43df;
	case 17380ULL: goto x86_l_43e4;
	case 17385ULL: goto x86_l_43e9;
	case 17391ULL: goto x86_l_43ef;
	case 17396ULL: goto x86_l_43f4;
	case 17404ULL: goto x86_l_43fc;
	case 17408ULL: goto x86_l_4400;
	case 17415ULL: goto x86_l_4407;
	case 17418ULL: goto x86_l_440a;
	case 17423ULL: goto x86_l_440f;
	case 17425ULL: goto x86_l_4411;
	case 17429ULL: goto x86_l_4415;
	case 17437ULL: goto x86_l_441d;
	case 17440ULL: goto x86_l_4420;
	case 17448ULL: goto x86_l_4428;
	case 17457ULL: goto x86_l_4431;
	case 17462ULL: goto x86_l_4436;
	case 17466ULL: goto x86_l_443a;
	case 17471ULL: goto x86_l_443f;
	case 17476ULL: goto x86_l_4444;
	case 17481ULL: goto x86_l_4449;
	case 17483ULL: goto x86_l_444b;
	case 17485ULL: goto x86_l_444d;
	case 17491ULL: goto x86_l_4453;
	case 17497ULL: goto x86_l_4459;
	case 17500ULL: goto x86_l_445c;
	case 17505ULL: goto x86_l_4461;
	case 17510ULL: goto x86_l_4466;
	case 17516ULL: goto x86_l_446c;
	case 17521ULL: goto x86_l_4471;
	case 17529ULL: goto x86_l_4479;
	case 17533ULL: goto x86_l_447d;
	case 17540ULL: goto x86_l_4484;
	case 17545ULL: goto x86_l_4489;
	case 17550ULL: goto x86_l_448e;
	case 17552ULL: goto x86_l_4490;
	case 17555ULL: goto x86_l_4493;
	case 17557ULL: goto x86_l_4495;
	case 17559ULL: goto x86_l_4497;
	case 17565ULL: goto x86_l_449d;
	case 17568ULL: goto x86_l_44a0;
	case 17573ULL: goto x86_l_44a5;
	case 17578ULL: goto x86_l_44aa;
	case 17584ULL: goto x86_l_44b0;
	case 17589ULL: goto x86_l_44b5;
	case 17597ULL: goto x86_l_44bd;
	case 17601ULL: goto x86_l_44c1;
	case 17608ULL: goto x86_l_44c8;
	case 17611ULL: goto x86_l_44cb;
	case 17616ULL: goto x86_l_44d0;
	case 17618ULL: goto x86_l_44d2;
	case 17622ULL: goto x86_l_44d6;
	case 17630ULL: goto x86_l_44de;
	case 17633ULL: goto x86_l_44e1;
	case 17641ULL: goto x86_l_44e9;
	case 17650ULL: goto x86_l_44f2;
	case 17655ULL: goto x86_l_44f7;
	case 17659ULL: goto x86_l_44fb;
	case 17664ULL: goto x86_l_4500;
	case 17669ULL: goto x86_l_4505;
	case 17674ULL: goto x86_l_450a;
	case 17676ULL: goto x86_l_450c;
	case 17678ULL: goto x86_l_450e;
	case 17684ULL: goto x86_l_4514;
	case 17690ULL: goto x86_l_451a;
	case 17693ULL: goto x86_l_451d;
	case 17698ULL: goto x86_l_4522;
	case 17703ULL: goto x86_l_4527;
	case 17709ULL: goto x86_l_452d;
	case 17714ULL: goto x86_l_4532;
	case 17722ULL: goto x86_l_453a;
	case 17726ULL: goto x86_l_453e;
	case 17733ULL: goto x86_l_4545;
	case 17738ULL: goto x86_l_454a;
	case 17743ULL: goto x86_l_454f;
	case 17745ULL: goto x86_l_4551;
	case 17748ULL: goto x86_l_4554;
	case 17750ULL: goto x86_l_4556;
	case 17752ULL: goto x86_l_4558;
	case 17758ULL: goto x86_l_455e;
	case 17761ULL: goto x86_l_4561;
	case 17766ULL: goto x86_l_4566;
	case 17771ULL: goto x86_l_456b;
	case 17777ULL: goto x86_l_4571;
	case 17782ULL: goto x86_l_4576;
	case 17790ULL: goto x86_l_457e;
	case 17794ULL: goto x86_l_4582;
	case 17801ULL: goto x86_l_4589;
	case 17804ULL: goto x86_l_458c;
	case 17809ULL: goto x86_l_4591;
	case 17811ULL: goto x86_l_4593;
	case 17815ULL: goto x86_l_4597;
	case 17823ULL: goto x86_l_459f;
	case 17826ULL: goto x86_l_45a2;
	case 17834ULL: goto x86_l_45aa;
	case 17843ULL: goto x86_l_45b3;
	case 17848ULL: goto x86_l_45b8;
	case 17852ULL: goto x86_l_45bc;
	case 17857ULL: goto x86_l_45c1;
	case 17862ULL: goto x86_l_45c6;
	case 17867ULL: goto x86_l_45cb;
	case 17869ULL: goto x86_l_45cd;
	case 17871ULL: goto x86_l_45cf;
	case 17877ULL: goto x86_l_45d5;
	case 17883ULL: goto x86_l_45db;
	case 17886ULL: goto x86_l_45de;
	case 17891ULL: goto x86_l_45e3;
	case 17896ULL: goto x86_l_45e8;
	case 17902ULL: goto x86_l_45ee;
	case 17907ULL: goto x86_l_45f3;
	case 17915ULL: goto x86_l_45fb;
	case 17919ULL: goto x86_l_45ff;
	case 17926ULL: goto x86_l_4606;
	case 17931ULL: goto x86_l_460b;
	case 17936ULL: goto x86_l_4610;
	case 17938ULL: goto x86_l_4612;
	case 17941ULL: goto x86_l_4615;
	case 17943ULL: goto x86_l_4617;
	case 17945ULL: goto x86_l_4619;
	case 17951ULL: goto x86_l_461f;
	case 17954ULL: goto x86_l_4622;
	case 17959ULL: goto x86_l_4627;
	case 17964ULL: goto x86_l_462c;
	case 17970ULL: goto x86_l_4632;
	case 17975ULL: goto x86_l_4637;
	case 17983ULL: goto x86_l_463f;
	case 17987ULL: goto x86_l_4643;
	case 17994ULL: goto x86_l_464a;
	case 17997ULL: goto x86_l_464d;
	case 18002ULL: goto x86_l_4652;
	case 18004ULL: goto x86_l_4654;
	case 18008ULL: goto x86_l_4658;
	case 18016ULL: goto x86_l_4660;
	case 18019ULL: goto x86_l_4663;
	case 18027ULL: goto x86_l_466b;
	case 18036ULL: goto x86_l_4674;
	case 18041ULL: goto x86_l_4679;
	case 18045ULL: goto x86_l_467d;
	case 18050ULL: goto x86_l_4682;
	case 18055ULL: goto x86_l_4687;
	case 18060ULL: goto x86_l_468c;
	case 18062ULL: goto x86_l_468e;
	case 18064ULL: goto x86_l_4690;
	case 18070ULL: goto x86_l_4696;
	case 18076ULL: goto x86_l_469c;
	case 18079ULL: goto x86_l_469f;
	case 18084ULL: goto x86_l_46a4;
	case 18089ULL: goto x86_l_46a9;
	case 18095ULL: goto x86_l_46af;
	case 18100ULL: goto x86_l_46b4;
	case 18108ULL: goto x86_l_46bc;
	case 18112ULL: goto x86_l_46c0;
	case 18119ULL: goto x86_l_46c7;
	case 18124ULL: goto x86_l_46cc;
	case 18129ULL: goto x86_l_46d1;
	case 18131ULL: goto x86_l_46d3;
	case 18134ULL: goto x86_l_46d6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3f9a:
	/* 0x3f9a: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_3fa2:
	/* 0x3fa2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3fab:
	/* 0x3fab: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3fb0:
	/* 0x3fb0: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3fb4:
	/* 0x3fb4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3fb9:
	/* 0x3fb9: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3fbe:
	/* 0x3fbe: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3fc3:
	/* 0x3fc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fc5:
	/* 0x3fc5: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3fc7:
	/* 0x3fc7: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3fcd:
	/* 0x3fcd: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_3fd3:
	/* 0x3fd3: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3fd6:
	/* 0x3fd6: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_3fdb:
	/* 0x3fdb: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fe0:
	/* 0x3fe0: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_3fe6:
	/* 0x3fe6: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_3feb:
	/* 0x3feb: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_3ff3:
	/* 0x3ff3: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_3ff7:
	/* 0x3ff7: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_3ffe:
	/* 0x3ffe: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4003:
	/* 0x4003: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4008:
	/* 0x4008: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_400a:
	/* 0x400a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_400d:
	/* 0x400d: mov    cl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_400f:
	/* 0x400f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4011:
	/* 0x4011: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4017:
	/* 0x4017: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_401a:
	/* 0x401a: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_401f:
	/* 0x401f: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4024:
	/* 0x4024: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_402a:
	/* 0x402a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_402f:
	/* 0x402f: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4037:
	/* 0x4037: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_403b:
	/* 0x403b: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4042:
	/* 0x4042: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4045:
	/* 0x4045: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_404a:
	/* 0x404a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_404c:
	/* 0x404c: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4050:
	/* 0x4050: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4058:
	/* 0x4058: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_405b:
	/* 0x405b: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4063:
	/* 0x4063: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_406c:
	/* 0x406c: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4071:
	/* 0x4071: lea    rdx,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4075:
	/* 0x4075: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_407a:
	/* 0x407a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_407f:
	/* 0x407f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4084:
	/* 0x4084: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4086:
	/* 0x4086: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_4088:
	/* 0x4088: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_408e:
	/* 0x408e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4094:
	/* 0x4094: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4097:
	/* 0x4097: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_409c:
	/* 0x409c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40a1:
	/* 0x40a1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_40a7:
	/* 0x40a7: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_40ac:
	/* 0x40ac: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40b4:
	/* 0x40b4: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_40b8:
	/* 0x40b8: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_40bf:
	/* 0x40bf: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40c4:
	/* 0x40c4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_40c9:
	/* 0x40c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40cb:
	/* 0x40cb: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40ce:
	/* 0x40ce: mov    cl,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 7ULL);
x86_l_40d0:
	/* 0x40d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40d2:
	/* 0x40d2: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_40d8:
	/* 0x40d8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40db:
	/* 0x40db: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_40e0:
	/* 0x40e0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e5:
	/* 0x40e5: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_40eb:
	/* 0x40eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_40f0:
	/* 0x40f0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_40f8:
	/* 0x40f8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_40fc:
	/* 0x40fc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4103:
	/* 0x4103: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4106:
	/* 0x4106: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_410b:
	/* 0x410b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410d:
	/* 0x410d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4111:
	/* 0x4111: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4119:
	/* 0x4119: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_411c:
	/* 0x411c: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4124:
	/* 0x4124: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_412d:
	/* 0x412d: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4132:
	/* 0x4132: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_4136:
	/* 0x4136: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_413b:
	/* 0x413b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4140:
	/* 0x4140: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4145:
	/* 0x4145: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4147:
	/* 0x4147: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_4149:
	/* 0x4149: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_414f:
	/* 0x414f: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4155:
	/* 0x4155: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4158:
	/* 0x4158: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_415d:
	/* 0x415d: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4162:
	/* 0x4162: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4168:
	/* 0x4168: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_416d:
	/* 0x416d: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4175:
	/* 0x4175: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4179:
	/* 0x4179: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4180:
	/* 0x4180: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4185:
	/* 0x4185: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_418a:
	/* 0x418a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418c:
	/* 0x418c: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_418f:
	/* 0x418f: mov    cl,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_4191:
	/* 0x4191: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4193:
	/* 0x4193: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4199:
	/* 0x4199: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_419c:
	/* 0x419c: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_41a1:
	/* 0x41a1: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a6:
	/* 0x41a6: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_41ac:
	/* 0x41ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41b1:
	/* 0x41b1: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_41b9:
	/* 0x41b9: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_41bd:
	/* 0x41bd: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_41c4:
	/* 0x41c4: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_41c7:
	/* 0x41c7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_41cc:
	/* 0x41cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41ce:
	/* 0x41ce: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_41d2:
	/* 0x41d2: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_41da:
	/* 0x41da: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_41dd:
	/* 0x41dd: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_41e5:
	/* 0x41e5: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_41ee:
	/* 0x41ee: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_41f3:
	/* 0x41f3: lea    rdx,[rax+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_41f7:
	/* 0x41f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_41fc:
	/* 0x41fc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4201:
	/* 0x4201: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4206:
	/* 0x4206: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4208:
	/* 0x4208: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_420a:
	/* 0x420a: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4210:
	/* 0x4210: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4216:
	/* 0x4216: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4219:
	/* 0x4219: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_421e:
	/* 0x421e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4223:
	/* 0x4223: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4229:
	/* 0x4229: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_422e:
	/* 0x422e: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4236:
	/* 0x4236: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_423a:
	/* 0x423a: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4241:
	/* 0x4241: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4246:
	/* 0x4246: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_424b:
	/* 0x424b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_424d:
	/* 0x424d: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4250:
	/* 0x4250: mov    cl,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 9ULL);
x86_l_4252:
	/* 0x4252: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4254:
	/* 0x4254: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_425a:
	/* 0x425a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_425d:
	/* 0x425d: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4262:
	/* 0x4262: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4267:
	/* 0x4267: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_426d:
	/* 0x426d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4272:
	/* 0x4272: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_427a:
	/* 0x427a: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_427e:
	/* 0x427e: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4285:
	/* 0x4285: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4288:
	/* 0x4288: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_428d:
	/* 0x428d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_428f:
	/* 0x428f: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4293:
	/* 0x4293: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_429b:
	/* 0x429b: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_429e:
	/* 0x429e: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_42a6:
	/* 0x42a6: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_42af:
	/* 0x42af: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_42b4:
	/* 0x42b4: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_42b8:
	/* 0x42b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_42bd:
	/* 0x42bd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_42c2:
	/* 0x42c2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_42c7:
	/* 0x42c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42c9:
	/* 0x42c9: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_42cb:
	/* 0x42cb: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_42d1:
	/* 0x42d1: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_42d7:
	/* 0x42d7: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42da:
	/* 0x42da: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_42df:
	/* 0x42df: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42e4:
	/* 0x42e4: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_42ea:
	/* 0x42ea: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_42ef:
	/* 0x42ef: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_42f7:
	/* 0x42f7: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_42fb:
	/* 0x42fb: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4302:
	/* 0x4302: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4307:
	/* 0x4307: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_430c:
	/* 0x430c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_430e:
	/* 0x430e: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4311:
	/* 0x4311: mov    cl,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 10ULL);
x86_l_4313:
	/* 0x4313: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4315:
	/* 0x4315: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_431b:
	/* 0x431b: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_431e:
	/* 0x431e: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4323:
	/* 0x4323: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4328:
	/* 0x4328: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_432e:
	/* 0x432e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4333:
	/* 0x4333: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_433b:
	/* 0x433b: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_433f:
	/* 0x433f: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4346:
	/* 0x4346: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4349:
	/* 0x4349: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_434e:
	/* 0x434e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4350:
	/* 0x4350: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4354:
	/* 0x4354: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_435c:
	/* 0x435c: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_435f:
	/* 0x435f: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4367:
	/* 0x4367: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4370:
	/* 0x4370: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4375:
	/* 0x4375: lea    rdx,[rax+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4379:
	/* 0x4379: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_437e:
	/* 0x437e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4383:
	/* 0x4383: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4388:
	/* 0x4388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_438a:
	/* 0x438a: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_438c:
	/* 0x438c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4392:
	/* 0x4392: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4398:
	/* 0x4398: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_439b:
	/* 0x439b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_43a0:
	/* 0x43a0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43a5:
	/* 0x43a5: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_43ab:
	/* 0x43ab: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_43b0:
	/* 0x43b0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43b8:
	/* 0x43b8: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_43bc:
	/* 0x43bc: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_43c3:
	/* 0x43c3: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43c8:
	/* 0x43c8: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_43cd:
	/* 0x43cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43cf:
	/* 0x43cf: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43d2:
	/* 0x43d2: mov    cl,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 11ULL);
x86_l_43d4:
	/* 0x43d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_43d6:
	/* 0x43d6: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_43dc:
	/* 0x43dc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_43df:
	/* 0x43df: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_43e4:
	/* 0x43e4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43e9:
	/* 0x43e9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_43ef:
	/* 0x43ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_43f4:
	/* 0x43f4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_43fc:
	/* 0x43fc: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4400:
	/* 0x4400: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4407:
	/* 0x4407: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_440a:
	/* 0x440a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_440f:
	/* 0x440f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4411:
	/* 0x4411: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4415:
	/* 0x4415: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_441d:
	/* 0x441d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4420:
	/* 0x4420: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4428:
	/* 0x4428: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4431:
	/* 0x4431: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4436:
	/* 0x4436: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_443a:
	/* 0x443a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_443f:
	/* 0x443f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4444:
	/* 0x4444: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4449:
	/* 0x4449: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_444b:
	/* 0x444b: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_444d:
	/* 0x444d: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4453:
	/* 0x4453: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4459:
	/* 0x4459: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_445c:
	/* 0x445c: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4461:
	/* 0x4461: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4466:
	/* 0x4466: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_446c:
	/* 0x446c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4471:
	/* 0x4471: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4479:
	/* 0x4479: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_447d:
	/* 0x447d: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4484:
	/* 0x4484: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4489:
	/* 0x4489: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_448e:
	/* 0x448e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4490:
	/* 0x4490: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4493:
	/* 0x4493: mov    cl,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 12ULL);
x86_l_4495:
	/* 0x4495: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4497:
	/* 0x4497: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_449d:
	/* 0x449d: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44a0:
	/* 0x44a0: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_44a5:
	/* 0x44a5: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44aa:
	/* 0x44aa: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_44b0:
	/* 0x44b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_44b5:
	/* 0x44b5: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_44bd:
	/* 0x44bd: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_44c1:
	/* 0x44c1: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_44c8:
	/* 0x44c8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_44cb:
	/* 0x44cb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_44d0:
	/* 0x44d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d2:
	/* 0x44d2: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_44d6:
	/* 0x44d6: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_44de:
	/* 0x44de: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_44e1:
	/* 0x44e1: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_44e9:
	/* 0x44e9: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_44f2:
	/* 0x44f2: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_44f7:
	/* 0x44f7: lea    rdx,[rax+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_44fb:
	/* 0x44fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4500:
	/* 0x4500: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4505:
	/* 0x4505: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_450a:
	/* 0x450a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_450c:
	/* 0x450c: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_450e:
	/* 0x450e: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4514:
	/* 0x4514: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_451a:
	/* 0x451a: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_451d:
	/* 0x451d: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4522:
	/* 0x4522: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4527:
	/* 0x4527: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_452d:
	/* 0x452d: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4532:
	/* 0x4532: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_453a:
	/* 0x453a: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_453e:
	/* 0x453e: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4545:
	/* 0x4545: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_454a:
	/* 0x454a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_454f:
	/* 0x454f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4551:
	/* 0x4551: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4554:
	/* 0x4554: mov    cl,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 13ULL);
x86_l_4556:
	/* 0x4556: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4558:
	/* 0x4558: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_455e:
	/* 0x455e: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4561:
	/* 0x4561: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4566:
	/* 0x4566: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_456b:
	/* 0x456b: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4571:
	/* 0x4571: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4576:
	/* 0x4576: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_457e:
	/* 0x457e: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4582:
	/* 0x4582: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4589:
	/* 0x4589: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_458c:
	/* 0x458c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4591:
	/* 0x4591: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4593:
	/* 0x4593: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4597:
	/* 0x4597: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_459f:
	/* 0x459f: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_45a2:
	/* 0x45a2: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_45aa:
	/* 0x45aa: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_45b3:
	/* 0x45b3: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_45b8:
	/* 0x45b8: lea    rdx,[rax+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_45bc:
	/* 0x45bc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_45c1:
	/* 0x45c1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45c6:
	/* 0x45c6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45cb:
	/* 0x45cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45cd:
	/* 0x45cd: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_45cf:
	/* 0x45cf: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_45d5:
	/* 0x45d5: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_45db:
	/* 0x45db: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_45de:
	/* 0x45de: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_45e3:
	/* 0x45e3: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45e8:
	/* 0x45e8: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_45ee:
	/* 0x45ee: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_45f3:
	/* 0x45f3: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_45fb:
	/* 0x45fb: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_45ff:
	/* 0x45ff: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4606:
	/* 0x4606: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_460b:
	/* 0x460b: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4610:
	/* 0x4610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4612:
	/* 0x4612: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4615:
	/* 0x4615: mov    cl,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 14ULL);
x86_l_4617:
	/* 0x4617: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4619:
	/* 0x4619: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_461f:
	/* 0x461f: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4622:
	/* 0x4622: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4627:
	/* 0x4627: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_462c:
	/* 0x462c: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4632:
	/* 0x4632: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4637:
	/* 0x4637: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_463f:
	/* 0x463f: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4643:
	/* 0x4643: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_464a:
	/* 0x464a: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_464d:
	/* 0x464d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4652:
	/* 0x4652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4654:
	/* 0x4654: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4658:
	/* 0x4658: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4660:
	/* 0x4660: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4663:
	/* 0x4663: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_466b:
	/* 0x466b: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4674:
	/* 0x4674: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4679:
	/* 0x4679: lea    rdx,[rax+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_467d:
	/* 0x467d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4682:
	/* 0x4682: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4687:
	/* 0x4687: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_468c:
	/* 0x468c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_468e:
	/* 0x468e: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
x86_l_4690:
	/* 0x4690: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4696:
	/* 0x4696: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_469c:
	/* 0x469c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_469f:
	/* 0x469f: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_46a4:
	/* 0x46a4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a9:
	/* 0x46a9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_46af:
	/* 0x46af: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_46b4:
	/* 0x46b4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_46bc:
	/* 0x46bc: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_46c0:
	/* 0x46c0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_46c7:
	/* 0x46c7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46cc:
	/* 0x46cc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_46d1:
	/* 0x46d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46d3:
	/* 0x46d3: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46d6:
	/* 0x46d6: mov    cl,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 15ULL);
	return 18136ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18136ULL: goto x86_l_46d8;
	case 18138ULL: goto x86_l_46da;
	case 18144ULL: goto x86_l_46e0;
	case 18147ULL: goto x86_l_46e3;
	case 18152ULL: goto x86_l_46e8;
	case 18157ULL: goto x86_l_46ed;
	case 18163ULL: goto x86_l_46f3;
	case 18168ULL: goto x86_l_46f8;
	case 18176ULL: goto x86_l_4700;
	case 18180ULL: goto x86_l_4704;
	case 18187ULL: goto x86_l_470b;
	case 18190ULL: goto x86_l_470e;
	case 18195ULL: goto x86_l_4713;
	case 18197ULL: goto x86_l_4715;
	case 18201ULL: goto x86_l_4719;
	case 18209ULL: goto x86_l_4721;
	case 18212ULL: goto x86_l_4724;
	case 18220ULL: goto x86_l_472c;
	case 18229ULL: goto x86_l_4735;
	case 18234ULL: goto x86_l_473a;
	case 18241ULL: goto x86_l_4741;
	case 18246ULL: goto x86_l_4746;
	case 18251ULL: goto x86_l_474b;
	case 18256ULL: goto x86_l_4750;
	case 18258ULL: goto x86_l_4752;
	case 18260ULL: goto x86_l_4754;
	case 18266ULL: goto x86_l_475a;
	case 18272ULL: goto x86_l_4760;
	case 18275ULL: goto x86_l_4763;
	case 18280ULL: goto x86_l_4768;
	case 18285ULL: goto x86_l_476d;
	case 18291ULL: goto x86_l_4773;
	case 18296ULL: goto x86_l_4778;
	case 18304ULL: goto x86_l_4780;
	case 18308ULL: goto x86_l_4784;
	case 18315ULL: goto x86_l_478b;
	case 18320ULL: goto x86_l_4790;
	case 18325ULL: goto x86_l_4795;
	case 18327ULL: goto x86_l_4797;
	case 18330ULL: goto x86_l_479a;
	case 18332ULL: goto x86_l_479c;
	case 18334ULL: goto x86_l_479e;
	case 18340ULL: goto x86_l_47a4;
	case 18343ULL: goto x86_l_47a7;
	case 18348ULL: goto x86_l_47ac;
	case 18353ULL: goto x86_l_47b1;
	case 18359ULL: goto x86_l_47b7;
	case 18364ULL: goto x86_l_47bc;
	case 18372ULL: goto x86_l_47c4;
	case 18376ULL: goto x86_l_47c8;
	case 18383ULL: goto x86_l_47cf;
	case 18386ULL: goto x86_l_47d2;
	case 18391ULL: goto x86_l_47d7;
	case 18393ULL: goto x86_l_47d9;
	case 18397ULL: goto x86_l_47dd;
	case 18405ULL: goto x86_l_47e5;
	case 18408ULL: goto x86_l_47e8;
	case 18416ULL: goto x86_l_47f0;
	case 18425ULL: goto x86_l_47f9;
	case 18430ULL: goto x86_l_47fe;
	case 18437ULL: goto x86_l_4805;
	case 18442ULL: goto x86_l_480a;
	case 18447ULL: goto x86_l_480f;
	case 18452ULL: goto x86_l_4814;
	case 18454ULL: goto x86_l_4816;
	case 18456ULL: goto x86_l_4818;
	case 18462ULL: goto x86_l_481e;
	case 18468ULL: goto x86_l_4824;
	case 18471ULL: goto x86_l_4827;
	case 18476ULL: goto x86_l_482c;
	case 18481ULL: goto x86_l_4831;
	case 18487ULL: goto x86_l_4837;
	case 18492ULL: goto x86_l_483c;
	case 18500ULL: goto x86_l_4844;
	case 18504ULL: goto x86_l_4848;
	case 18511ULL: goto x86_l_484f;
	case 18516ULL: goto x86_l_4854;
	case 18521ULL: goto x86_l_4859;
	case 18523ULL: goto x86_l_485b;
	case 18526ULL: goto x86_l_485e;
	case 18528ULL: goto x86_l_4860;
	case 18530ULL: goto x86_l_4862;
	case 18536ULL: goto x86_l_4868;
	case 18539ULL: goto x86_l_486b;
	case 18544ULL: goto x86_l_4870;
	case 18549ULL: goto x86_l_4875;
	case 18555ULL: goto x86_l_487b;
	case 18560ULL: goto x86_l_4880;
	case 18568ULL: goto x86_l_4888;
	case 18572ULL: goto x86_l_488c;
	case 18579ULL: goto x86_l_4893;
	case 18582ULL: goto x86_l_4896;
	case 18587ULL: goto x86_l_489b;
	case 18589ULL: goto x86_l_489d;
	case 18593ULL: goto x86_l_48a1;
	case 18601ULL: goto x86_l_48a9;
	case 18604ULL: goto x86_l_48ac;
	case 18612ULL: goto x86_l_48b4;
	case 18621ULL: goto x86_l_48bd;
	case 18626ULL: goto x86_l_48c2;
	case 18633ULL: goto x86_l_48c9;
	case 18638ULL: goto x86_l_48ce;
	case 18643ULL: goto x86_l_48d3;
	case 18648ULL: goto x86_l_48d8;
	case 18650ULL: goto x86_l_48da;
	case 18652ULL: goto x86_l_48dc;
	case 18658ULL: goto x86_l_48e2;
	case 18664ULL: goto x86_l_48e8;
	case 18667ULL: goto x86_l_48eb;
	case 18672ULL: goto x86_l_48f0;
	case 18677ULL: goto x86_l_48f5;
	case 18683ULL: goto x86_l_48fb;
	case 18688ULL: goto x86_l_4900;
	case 18696ULL: goto x86_l_4908;
	case 18700ULL: goto x86_l_490c;
	case 18707ULL: goto x86_l_4913;
	case 18712ULL: goto x86_l_4918;
	case 18717ULL: goto x86_l_491d;
	case 18719ULL: goto x86_l_491f;
	case 18722ULL: goto x86_l_4922;
	case 18724ULL: goto x86_l_4924;
	case 18726ULL: goto x86_l_4926;
	case 18732ULL: goto x86_l_492c;
	case 18735ULL: goto x86_l_492f;
	case 18740ULL: goto x86_l_4934;
	case 18745ULL: goto x86_l_4939;
	case 18751ULL: goto x86_l_493f;
	case 18756ULL: goto x86_l_4944;
	case 18764ULL: goto x86_l_494c;
	case 18768ULL: goto x86_l_4950;
	case 18775ULL: goto x86_l_4957;
	case 18778ULL: goto x86_l_495a;
	case 18783ULL: goto x86_l_495f;
	case 18785ULL: goto x86_l_4961;
	case 18789ULL: goto x86_l_4965;
	case 18797ULL: goto x86_l_496d;
	case 18800ULL: goto x86_l_4970;
	case 18808ULL: goto x86_l_4978;
	case 18817ULL: goto x86_l_4981;
	case 18822ULL: goto x86_l_4986;
	case 18829ULL: goto x86_l_498d;
	case 18834ULL: goto x86_l_4992;
	case 18839ULL: goto x86_l_4997;
	case 18844ULL: goto x86_l_499c;
	case 18846ULL: goto x86_l_499e;
	case 18848ULL: goto x86_l_49a0;
	case 18854ULL: goto x86_l_49a6;
	case 18860ULL: goto x86_l_49ac;
	case 18863ULL: goto x86_l_49af;
	case 18868ULL: goto x86_l_49b4;
	case 18873ULL: goto x86_l_49b9;
	case 18879ULL: goto x86_l_49bf;
	case 18884ULL: goto x86_l_49c4;
	case 18892ULL: goto x86_l_49cc;
	case 18896ULL: goto x86_l_49d0;
	case 18903ULL: goto x86_l_49d7;
	case 18908ULL: goto x86_l_49dc;
	case 18913ULL: goto x86_l_49e1;
	case 18915ULL: goto x86_l_49e3;
	case 18918ULL: goto x86_l_49e6;
	case 18920ULL: goto x86_l_49e8;
	case 18922ULL: goto x86_l_49ea;
	case 18928ULL: goto x86_l_49f0;
	case 18931ULL: goto x86_l_49f3;
	case 18936ULL: goto x86_l_49f8;
	case 18941ULL: goto x86_l_49fd;
	case 18947ULL: goto x86_l_4a03;
	case 18952ULL: goto x86_l_4a08;
	case 18960ULL: goto x86_l_4a10;
	case 18964ULL: goto x86_l_4a14;
	case 18971ULL: goto x86_l_4a1b;
	case 18974ULL: goto x86_l_4a1e;
	case 18979ULL: goto x86_l_4a23;
	case 18981ULL: goto x86_l_4a25;
	case 18985ULL: goto x86_l_4a29;
	case 18993ULL: goto x86_l_4a31;
	case 18996ULL: goto x86_l_4a34;
	case 19004ULL: goto x86_l_4a3c;
	case 19013ULL: goto x86_l_4a45;
	case 19018ULL: goto x86_l_4a4a;
	case 19025ULL: goto x86_l_4a51;
	case 19030ULL: goto x86_l_4a56;
	case 19035ULL: goto x86_l_4a5b;
	case 19040ULL: goto x86_l_4a60;
	case 19042ULL: goto x86_l_4a62;
	case 19044ULL: goto x86_l_4a64;
	case 19050ULL: goto x86_l_4a6a;
	case 19056ULL: goto x86_l_4a70;
	case 19059ULL: goto x86_l_4a73;
	case 19064ULL: goto x86_l_4a78;
	case 19069ULL: goto x86_l_4a7d;
	case 19075ULL: goto x86_l_4a83;
	case 19080ULL: goto x86_l_4a88;
	case 19088ULL: goto x86_l_4a90;
	case 19092ULL: goto x86_l_4a94;
	case 19099ULL: goto x86_l_4a9b;
	case 19104ULL: goto x86_l_4aa0;
	case 19109ULL: goto x86_l_4aa5;
	case 19111ULL: goto x86_l_4aa7;
	case 19114ULL: goto x86_l_4aaa;
	case 19116ULL: goto x86_l_4aac;
	case 19118ULL: goto x86_l_4aae;
	case 19124ULL: goto x86_l_4ab4;
	case 19127ULL: goto x86_l_4ab7;
	case 19132ULL: goto x86_l_4abc;
	case 19137ULL: goto x86_l_4ac1;
	case 19143ULL: goto x86_l_4ac7;
	case 19148ULL: goto x86_l_4acc;
	case 19156ULL: goto x86_l_4ad4;
	case 19160ULL: goto x86_l_4ad8;
	case 19167ULL: goto x86_l_4adf;
	case 19170ULL: goto x86_l_4ae2;
	case 19175ULL: goto x86_l_4ae7;
	case 19177ULL: goto x86_l_4ae9;
	case 19181ULL: goto x86_l_4aed;
	case 19189ULL: goto x86_l_4af5;
	case 19192ULL: goto x86_l_4af8;
	case 19200ULL: goto x86_l_4b00;
	case 19209ULL: goto x86_l_4b09;
	case 19214ULL: goto x86_l_4b0e;
	case 19221ULL: goto x86_l_4b15;
	case 19226ULL: goto x86_l_4b1a;
	case 19231ULL: goto x86_l_4b1f;
	case 19236ULL: goto x86_l_4b24;
	case 19238ULL: goto x86_l_4b26;
	case 19240ULL: goto x86_l_4b28;
	case 19246ULL: goto x86_l_4b2e;
	case 19252ULL: goto x86_l_4b34;
	case 19255ULL: goto x86_l_4b37;
	case 19260ULL: goto x86_l_4b3c;
	case 19265ULL: goto x86_l_4b41;
	case 19271ULL: goto x86_l_4b47;
	case 19276ULL: goto x86_l_4b4c;
	case 19284ULL: goto x86_l_4b54;
	case 19288ULL: goto x86_l_4b58;
	case 19295ULL: goto x86_l_4b5f;
	case 19300ULL: goto x86_l_4b64;
	case 19305ULL: goto x86_l_4b69;
	case 19307ULL: goto x86_l_4b6b;
	case 19310ULL: goto x86_l_4b6e;
	case 19312ULL: goto x86_l_4b70;
	case 19314ULL: goto x86_l_4b72;
	case 19320ULL: goto x86_l_4b78;
	case 19323ULL: goto x86_l_4b7b;
	case 19328ULL: goto x86_l_4b80;
	case 19333ULL: goto x86_l_4b85;
	case 19339ULL: goto x86_l_4b8b;
	case 19344ULL: goto x86_l_4b90;
	case 19352ULL: goto x86_l_4b98;
	case 19356ULL: goto x86_l_4b9c;
	case 19363ULL: goto x86_l_4ba3;
	case 19366ULL: goto x86_l_4ba6;
	case 19371ULL: goto x86_l_4bab;
	case 19373ULL: goto x86_l_4bad;
	case 19377ULL: goto x86_l_4bb1;
	case 19385ULL: goto x86_l_4bb9;
	case 19388ULL: goto x86_l_4bbc;
	case 19396ULL: goto x86_l_4bc4;
	case 19405ULL: goto x86_l_4bcd;
	case 19410ULL: goto x86_l_4bd2;
	case 19417ULL: goto x86_l_4bd9;
	case 19422ULL: goto x86_l_4bde;
	case 19427ULL: goto x86_l_4be3;
	case 19432ULL: goto x86_l_4be8;
	case 19434ULL: goto x86_l_4bea;
	case 19436ULL: goto x86_l_4bec;
	case 19442ULL: goto x86_l_4bf2;
	case 19448ULL: goto x86_l_4bf8;
	case 19451ULL: goto x86_l_4bfb;
	case 19456ULL: goto x86_l_4c00;
	case 19461ULL: goto x86_l_4c05;
	case 19467ULL: goto x86_l_4c0b;
	case 19472ULL: goto x86_l_4c10;
	case 19480ULL: goto x86_l_4c18;
	case 19484ULL: goto x86_l_4c1c;
	case 19491ULL: goto x86_l_4c23;
	case 19496ULL: goto x86_l_4c28;
	case 19501ULL: goto x86_l_4c2d;
	case 19503ULL: goto x86_l_4c2f;
	case 19506ULL: goto x86_l_4c32;
	case 19508ULL: goto x86_l_4c34;
	case 19510ULL: goto x86_l_4c36;
	case 19516ULL: goto x86_l_4c3c;
	case 19519ULL: goto x86_l_4c3f;
	case 19524ULL: goto x86_l_4c44;
	case 19529ULL: goto x86_l_4c49;
	case 19535ULL: goto x86_l_4c4f;
	case 19540ULL: goto x86_l_4c54;
	case 19548ULL: goto x86_l_4c5c;
	case 19552ULL: goto x86_l_4c60;
	case 19559ULL: goto x86_l_4c67;
	case 19562ULL: goto x86_l_4c6a;
	case 19567ULL: goto x86_l_4c6f;
	case 19569ULL: goto x86_l_4c71;
	case 19573ULL: goto x86_l_4c75;
	case 19581ULL: goto x86_l_4c7d;
	case 19584ULL: goto x86_l_4c80;
	case 19592ULL: goto x86_l_4c88;
	case 19601ULL: goto x86_l_4c91;
	case 19606ULL: goto x86_l_4c96;
	case 19613ULL: goto x86_l_4c9d;
	case 19618ULL: goto x86_l_4ca2;
	case 19623ULL: goto x86_l_4ca7;
	case 19628ULL: goto x86_l_4cac;
	case 19630ULL: goto x86_l_4cae;
	case 19632ULL: goto x86_l_4cb0;
	case 19638ULL: goto x86_l_4cb6;
	case 19644ULL: goto x86_l_4cbc;
	case 19647ULL: goto x86_l_4cbf;
	case 19652ULL: goto x86_l_4cc4;
	case 19657ULL: goto x86_l_4cc9;
	case 19663ULL: goto x86_l_4ccf;
	case 19668ULL: goto x86_l_4cd4;
	case 19676ULL: goto x86_l_4cdc;
	case 19680ULL: goto x86_l_4ce0;
	case 19687ULL: goto x86_l_4ce7;
	case 19692ULL: goto x86_l_4cec;
	case 19697ULL: goto x86_l_4cf1;
	case 19699ULL: goto x86_l_4cf3;
	case 19702ULL: goto x86_l_4cf6;
	case 19704ULL: goto x86_l_4cf8;
	case 19706ULL: goto x86_l_4cfa;
	case 19712ULL: goto x86_l_4d00;
	case 19715ULL: goto x86_l_4d03;
	case 19720ULL: goto x86_l_4d08;
	case 19725ULL: goto x86_l_4d0d;
	case 19731ULL: goto x86_l_4d13;
	case 19736ULL: goto x86_l_4d18;
	case 19744ULL: goto x86_l_4d20;
	case 19748ULL: goto x86_l_4d24;
	case 19755ULL: goto x86_l_4d2b;
	case 19758ULL: goto x86_l_4d2e;
	case 19763ULL: goto x86_l_4d33;
	case 19765ULL: goto x86_l_4d35;
	case 19769ULL: goto x86_l_4d39;
	case 19777ULL: goto x86_l_4d41;
	case 19780ULL: goto x86_l_4d44;
	case 19788ULL: goto x86_l_4d4c;
	case 19797ULL: goto x86_l_4d55;
	case 19802ULL: goto x86_l_4d5a;
	case 19809ULL: goto x86_l_4d61;
	case 19814ULL: goto x86_l_4d66;
	case 19819ULL: goto x86_l_4d6b;
	case 19824ULL: goto x86_l_4d70;
	case 19826ULL: goto x86_l_4d72;
	case 19828ULL: goto x86_l_4d74;
	case 19834ULL: goto x86_l_4d7a;
	case 19840ULL: goto x86_l_4d80;
	case 19843ULL: goto x86_l_4d83;
	case 19848ULL: goto x86_l_4d88;
	case 19853ULL: goto x86_l_4d8d;
	case 19859ULL: goto x86_l_4d93;
	case 19864ULL: goto x86_l_4d98;
	case 19872ULL: goto x86_l_4da0;
	case 19876ULL: goto x86_l_4da4;
	case 19883ULL: goto x86_l_4dab;
	case 19888ULL: goto x86_l_4db0;
	case 19893ULL: goto x86_l_4db5;
	case 19895ULL: goto x86_l_4db7;
	case 19898ULL: goto x86_l_4dba;
	case 19900ULL: goto x86_l_4dbc;
	case 19902ULL: goto x86_l_4dbe;
	case 19908ULL: goto x86_l_4dc4;
	case 19911ULL: goto x86_l_4dc7;
	case 19916ULL: goto x86_l_4dcc;
	case 19921ULL: goto x86_l_4dd1;
	case 19927ULL: goto x86_l_4dd7;
	case 19932ULL: goto x86_l_4ddc;
	case 19940ULL: goto x86_l_4de4;
	case 19944ULL: goto x86_l_4de8;
	case 19951ULL: goto x86_l_4def;
	case 19954ULL: goto x86_l_4df2;
	case 19959ULL: goto x86_l_4df7;
	case 19961ULL: goto x86_l_4df9;
	case 19965ULL: goto x86_l_4dfd;
	case 19973ULL: goto x86_l_4e05;
	case 19976ULL: goto x86_l_4e08;
	case 19984ULL: goto x86_l_4e10;
	case 19993ULL: goto x86_l_4e19;
	case 19998ULL: goto x86_l_4e1e;
	case 20005ULL: goto x86_l_4e25;
	case 20010ULL: goto x86_l_4e2a;
	case 20015ULL: goto x86_l_4e2f;
	case 20020ULL: goto x86_l_4e34;
	default: return 0xffffffffffffffffULL;
	}
x86_l_46d8:
	/* 0x46d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46da:
	/* 0x46da: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_46e0:
	/* 0x46e0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_46e3:
	/* 0x46e3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_46e8:
	/* 0x46e8: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46ed:
	/* 0x46ed: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_46f3:
	/* 0x46f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_46f8:
	/* 0x46f8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4700:
	/* 0x4700: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4704:
	/* 0x4704: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_470b:
	/* 0x470b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_470e:
	/* 0x470e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4713:
	/* 0x4713: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4715:
	/* 0x4715: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4719:
	/* 0x4719: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4721:
	/* 0x4721: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4724:
	/* 0x4724: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_472c:
	/* 0x472c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4735:
	/* 0x4735: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_473a:
	/* 0x473a: lea    rdx,[rax+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4741:
	/* 0x4741: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4746:
	/* 0x4746: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_474b:
	/* 0x474b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4750:
	/* 0x4750: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4752:
	/* 0x4752: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_4754:
	/* 0x4754: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_475a:
	/* 0x475a: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4760:
	/* 0x4760: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4763:
	/* 0x4763: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4768:
	/* 0x4768: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_476d:
	/* 0x476d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4773:
	/* 0x4773: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4778:
	/* 0x4778: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4780:
	/* 0x4780: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4784:
	/* 0x4784: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_478b:
	/* 0x478b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4790:
	/* 0x4790: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4795:
	/* 0x4795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4797:
	/* 0x4797: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_479a:
	/* 0x479a: mov    cl,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_479c:
	/* 0x479c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_479e:
	/* 0x479e: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_47a4:
	/* 0x47a4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47a7:
	/* 0x47a7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_47ac:
	/* 0x47ac: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47b1:
	/* 0x47b1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_47b7:
	/* 0x47b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_47bc:
	/* 0x47bc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_47c4:
	/* 0x47c4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_47c8:
	/* 0x47c8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_47cf:
	/* 0x47cf: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_47d2:
	/* 0x47d2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_47d7:
	/* 0x47d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47d9:
	/* 0x47d9: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47dd:
	/* 0x47dd: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_47e5:
	/* 0x47e5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_47e8:
	/* 0x47e8: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_47f0:
	/* 0x47f0: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_47f9:
	/* 0x47f9: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_47fe:
	/* 0x47fe: lea    rdx,[rax+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4805:
	/* 0x4805: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_480a:
	/* 0x480a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_480f:
	/* 0x480f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4814:
	/* 0x4814: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4816:
	/* 0x4816: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4818:
	/* 0x4818: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_481e:
	/* 0x481e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4824:
	/* 0x4824: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4827:
	/* 0x4827: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_482c:
	/* 0x482c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4831:
	/* 0x4831: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4837:
	/* 0x4837: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_483c:
	/* 0x483c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4844:
	/* 0x4844: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4848:
	/* 0x4848: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_484f:
	/* 0x484f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4854:
	/* 0x4854: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4859:
	/* 0x4859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485b:
	/* 0x485b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_485e:
	/* 0x485e: mov    cl,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 17ULL);
x86_l_4860:
	/* 0x4860: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4862:
	/* 0x4862: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4868:
	/* 0x4868: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_486b:
	/* 0x486b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4870:
	/* 0x4870: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4875:
	/* 0x4875: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_487b:
	/* 0x487b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4880:
	/* 0x4880: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4888:
	/* 0x4888: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_488c:
	/* 0x488c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4893:
	/* 0x4893: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4896:
	/* 0x4896: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_489b:
	/* 0x489b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489d:
	/* 0x489d: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48a1:
	/* 0x48a1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_48a9:
	/* 0x48a9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_48ac:
	/* 0x48ac: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_48b4:
	/* 0x48b4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_48bd:
	/* 0x48bd: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_48c2:
	/* 0x48c2: lea    rdx,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_48c9:
	/* 0x48c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_48ce:
	/* 0x48ce: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48d3:
	/* 0x48d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_48d8:
	/* 0x48d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48da:
	/* 0x48da: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_48dc:
	/* 0x48dc: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_48e2:
	/* 0x48e2: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_48e8:
	/* 0x48e8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48eb:
	/* 0x48eb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_48f0:
	/* 0x48f0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48f5:
	/* 0x48f5: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_48fb:
	/* 0x48fb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4900:
	/* 0x4900: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4908:
	/* 0x4908: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_490c:
	/* 0x490c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4913:
	/* 0x4913: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4918:
	/* 0x4918: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_491d:
	/* 0x491d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491f:
	/* 0x491f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4922:
	/* 0x4922: mov    cl,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 18ULL);
x86_l_4924:
	/* 0x4924: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4926:
	/* 0x4926: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_492c:
	/* 0x492c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_492f:
	/* 0x492f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4934:
	/* 0x4934: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4939:
	/* 0x4939: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_493f:
	/* 0x493f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4944:
	/* 0x4944: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_494c:
	/* 0x494c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4950:
	/* 0x4950: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4957:
	/* 0x4957: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_495a:
	/* 0x495a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_495f:
	/* 0x495f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4961:
	/* 0x4961: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4965:
	/* 0x4965: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_496d:
	/* 0x496d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4970:
	/* 0x4970: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4978:
	/* 0x4978: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4981:
	/* 0x4981: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4986:
	/* 0x4986: lea    rdx,[rax+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_498d:
	/* 0x498d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4992:
	/* 0x4992: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4997:
	/* 0x4997: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_499c:
	/* 0x499c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_499e:
	/* 0x499e: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_49a0:
	/* 0x49a0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_49a6:
	/* 0x49a6: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_49ac:
	/* 0x49ac: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49af:
	/* 0x49af: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_49b4:
	/* 0x49b4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b9:
	/* 0x49b9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_49bf:
	/* 0x49bf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_49c4:
	/* 0x49c4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_49cc:
	/* 0x49cc: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_49d0:
	/* 0x49d0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_49d7:
	/* 0x49d7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_49dc:
	/* 0x49dc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_49e1:
	/* 0x49e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49e3:
	/* 0x49e3: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e6:
	/* 0x49e6: mov    cl,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 19ULL);
x86_l_49e8:
	/* 0x49e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49ea:
	/* 0x49ea: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_49f0:
	/* 0x49f0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_49f3:
	/* 0x49f3: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_49f8:
	/* 0x49f8: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49fd:
	/* 0x49fd: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4a03:
	/* 0x4a03: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a08:
	/* 0x4a08: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a10:
	/* 0x4a10: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4a14:
	/* 0x4a14: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4a1b:
	/* 0x4a1b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4a1e:
	/* 0x4a1e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4a23:
	/* 0x4a23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a25:
	/* 0x4a25: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a29:
	/* 0x4a29: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4a31:
	/* 0x4a31: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4a34:
	/* 0x4a34: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4a3c:
	/* 0x4a3c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4a45:
	/* 0x4a45: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4a4a:
	/* 0x4a4a: lea    rdx,[rax+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4a51:
	/* 0x4a51: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4a56:
	/* 0x4a56: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a5b:
	/* 0x4a5b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4a60:
	/* 0x4a60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a62:
	/* 0x4a62: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4a64:
	/* 0x4a64: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4a6a:
	/* 0x4a6a: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4a70:
	/* 0x4a70: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4a73:
	/* 0x4a73: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4a78:
	/* 0x4a78: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7d:
	/* 0x4a7d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4a83:
	/* 0x4a83: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4a88:
	/* 0x4a88: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4a90:
	/* 0x4a90: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4a94:
	/* 0x4a94: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4a9b:
	/* 0x4a9b: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4aa0:
	/* 0x4aa0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4aa5:
	/* 0x4aa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4aa7:
	/* 0x4aa7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4aaa:
	/* 0x4aaa: mov    cl,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 20ULL);
x86_l_4aac:
	/* 0x4aac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4aae:
	/* 0x4aae: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4ab4:
	/* 0x4ab4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ab7:
	/* 0x4ab7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4abc:
	/* 0x4abc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ac1:
	/* 0x4ac1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4ac7:
	/* 0x4ac7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4acc:
	/* 0x4acc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ad4:
	/* 0x4ad4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4ad8:
	/* 0x4ad8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4adf:
	/* 0x4adf: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4ae2:
	/* 0x4ae2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ae7:
	/* 0x4ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae9:
	/* 0x4ae9: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4aed:
	/* 0x4aed: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4af5:
	/* 0x4af5: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4af8:
	/* 0x4af8: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4b00:
	/* 0x4b00: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4b09:
	/* 0x4b09: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4b0e:
	/* 0x4b0e: lea    rdx,[rax+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4b15:
	/* 0x4b15: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b1a:
	/* 0x4b1a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b1f:
	/* 0x4b1f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4b24:
	/* 0x4b24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b26:
	/* 0x4b26: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_4b28:
	/* 0x4b28: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4b2e:
	/* 0x4b2e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4b34:
	/* 0x4b34: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b37:
	/* 0x4b37: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4b3c:
	/* 0x4b3c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b41:
	/* 0x4b41: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4b47:
	/* 0x4b47: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4b4c:
	/* 0x4b4c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b54:
	/* 0x4b54: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4b58:
	/* 0x4b58: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4b5f:
	/* 0x4b5f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4b64:
	/* 0x4b64: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4b69:
	/* 0x4b69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b6b:
	/* 0x4b6b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b6e:
	/* 0x4b6e: mov    cl,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 21ULL);
x86_l_4b70:
	/* 0x4b70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b72:
	/* 0x4b72: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4b78:
	/* 0x4b78: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b7b:
	/* 0x4b7b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4b80:
	/* 0x4b80: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b85:
	/* 0x4b85: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4b8b:
	/* 0x4b8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4b90:
	/* 0x4b90: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4b98:
	/* 0x4b98: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4b9c:
	/* 0x4b9c: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4ba3:
	/* 0x4ba3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4ba6:
	/* 0x4ba6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4bab:
	/* 0x4bab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bad:
	/* 0x4bad: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bb1:
	/* 0x4bb1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4bb9:
	/* 0x4bb9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4bbc:
	/* 0x4bbc: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4bc4:
	/* 0x4bc4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4bcd:
	/* 0x4bcd: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4bd2:
	/* 0x4bd2: lea    rdx,[rax+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_4bd9:
	/* 0x4bd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4bde:
	/* 0x4bde: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4be3:
	/* 0x4be3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4be8:
	/* 0x4be8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bea:
	/* 0x4bea: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_4bec:
	/* 0x4bec: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4bf2:
	/* 0x4bf2: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4bf8:
	/* 0x4bf8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4bfb:
	/* 0x4bfb: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4c00:
	/* 0x4c00: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c05:
	/* 0x4c05: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4c0b:
	/* 0x4c0b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4c10:
	/* 0x4c10: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c18:
	/* 0x4c18: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4c1c:
	/* 0x4c1c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4c23:
	/* 0x4c23: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c28:
	/* 0x4c28: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4c2d:
	/* 0x4c2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2f:
	/* 0x4c2f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c32:
	/* 0x4c32: mov    cl,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 22ULL);
x86_l_4c34:
	/* 0x4c34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c36:
	/* 0x4c36: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4c3c:
	/* 0x4c3c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c3f:
	/* 0x4c3f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4c44:
	/* 0x4c44: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4c49:
	/* 0x4c49: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4c4f:
	/* 0x4c4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4c54:
	/* 0x4c54: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4c5c:
	/* 0x4c5c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4c60:
	/* 0x4c60: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4c67:
	/* 0x4c67: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4c6a:
	/* 0x4c6a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4c6f:
	/* 0x4c6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c71:
	/* 0x4c71: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4c75:
	/* 0x4c75: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4c7d:
	/* 0x4c7d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4c80:
	/* 0x4c80: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4c88:
	/* 0x4c88: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4c91:
	/* 0x4c91: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4c96:
	/* 0x4c96: lea    rdx,[rax+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_4c9d:
	/* 0x4c9d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ca2:
	/* 0x4ca2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ca7:
	/* 0x4ca7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4cac:
	/* 0x4cac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cae:
	/* 0x4cae: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_4cb0:
	/* 0x4cb0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4cb6:
	/* 0x4cb6: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4cbc:
	/* 0x4cbc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4cbf:
	/* 0x4cbf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4cc4:
	/* 0x4cc4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cc9:
	/* 0x4cc9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4ccf:
	/* 0x4ccf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4cd4:
	/* 0x4cd4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4cdc:
	/* 0x4cdc: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4ce0:
	/* 0x4ce0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ce7:
	/* 0x4ce7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4cec:
	/* 0x4cec: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4cf1:
	/* 0x4cf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cf3:
	/* 0x4cf3: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cf6:
	/* 0x4cf6: mov    cl,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 23ULL);
x86_l_4cf8:
	/* 0x4cf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4cfa:
	/* 0x4cfa: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4d00:
	/* 0x4d00: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d03:
	/* 0x4d03: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4d08:
	/* 0x4d08: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d0d:
	/* 0x4d0d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4d13:
	/* 0x4d13: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d18:
	/* 0x4d18: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4d20:
	/* 0x4d20: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4d24:
	/* 0x4d24: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4d2b:
	/* 0x4d2b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4d2e:
	/* 0x4d2e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4d33:
	/* 0x4d33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d35:
	/* 0x4d35: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d39:
	/* 0x4d39: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4d41:
	/* 0x4d41: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4d44:
	/* 0x4d44: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4d4c:
	/* 0x4d4c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d55:
	/* 0x4d55: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4d5a:
	/* 0x4d5a: lea    rdx,[rax+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4d61:
	/* 0x4d61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4d66:
	/* 0x4d66: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d6b:
	/* 0x4d6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4d70:
	/* 0x4d70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d72:
	/* 0x4d72: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4d74:
	/* 0x4d74: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d7a:
	/* 0x4d7a: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4d80:
	/* 0x4d80: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d83:
	/* 0x4d83: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4d88:
	/* 0x4d88: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4d8d:
	/* 0x4d8d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4d93:
	/* 0x4d93: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4d98:
	/* 0x4d98: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4da0:
	/* 0x4da0: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4da4:
	/* 0x4da4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4dab:
	/* 0x4dab: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4db0:
	/* 0x4db0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4db5:
	/* 0x4db5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db7:
	/* 0x4db7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dba:
	/* 0x4dba: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_4dbc:
	/* 0x4dbc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4dbe:
	/* 0x4dbe: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4dc4:
	/* 0x4dc4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4dc7:
	/* 0x4dc7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4dcc:
	/* 0x4dcc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4dd1:
	/* 0x4dd1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4dd7:
	/* 0x4dd7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ddc:
	/* 0x4ddc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4de4:
	/* 0x4de4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4de8:
	/* 0x4de8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4def:
	/* 0x4def: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4df2:
	/* 0x4df2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4df7:
	/* 0x4df7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4df9:
	/* 0x4df9: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4dfd:
	/* 0x4dfd: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4e05:
	/* 0x4e05: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4e08:
	/* 0x4e08: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4e10:
	/* 0x4e10: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4e19:
	/* 0x4e19: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4e1e:
	/* 0x4e1e: lea    rdx,[rax+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_4e25:
	/* 0x4e25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4e2a:
	/* 0x4e2a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e2f:
	/* 0x4e2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4e34:
	/* 0x4e34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 20022ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 20022ULL: goto x86_l_4e36;
	case 20024ULL: goto x86_l_4e38;
	case 20030ULL: goto x86_l_4e3e;
	case 20036ULL: goto x86_l_4e44;
	case 20039ULL: goto x86_l_4e47;
	case 20044ULL: goto x86_l_4e4c;
	case 20049ULL: goto x86_l_4e51;
	case 20055ULL: goto x86_l_4e57;
	case 20060ULL: goto x86_l_4e5c;
	case 20068ULL: goto x86_l_4e64;
	case 20072ULL: goto x86_l_4e68;
	case 20079ULL: goto x86_l_4e6f;
	case 20084ULL: goto x86_l_4e74;
	case 20089ULL: goto x86_l_4e79;
	case 20091ULL: goto x86_l_4e7b;
	case 20094ULL: goto x86_l_4e7e;
	case 20096ULL: goto x86_l_4e80;
	case 20098ULL: goto x86_l_4e82;
	case 20104ULL: goto x86_l_4e88;
	case 20107ULL: goto x86_l_4e8b;
	case 20112ULL: goto x86_l_4e90;
	case 20117ULL: goto x86_l_4e95;
	case 20123ULL: goto x86_l_4e9b;
	case 20128ULL: goto x86_l_4ea0;
	case 20136ULL: goto x86_l_4ea8;
	case 20140ULL: goto x86_l_4eac;
	case 20147ULL: goto x86_l_4eb3;
	case 20150ULL: goto x86_l_4eb6;
	case 20155ULL: goto x86_l_4ebb;
	case 20157ULL: goto x86_l_4ebd;
	case 20161ULL: goto x86_l_4ec1;
	case 20169ULL: goto x86_l_4ec9;
	case 20172ULL: goto x86_l_4ecc;
	case 20180ULL: goto x86_l_4ed4;
	case 20189ULL: goto x86_l_4edd;
	case 20194ULL: goto x86_l_4ee2;
	case 20201ULL: goto x86_l_4ee9;
	case 20206ULL: goto x86_l_4eee;
	case 20211ULL: goto x86_l_4ef3;
	case 20216ULL: goto x86_l_4ef8;
	case 20218ULL: goto x86_l_4efa;
	case 20220ULL: goto x86_l_4efc;
	case 20226ULL: goto x86_l_4f02;
	case 20232ULL: goto x86_l_4f08;
	case 20235ULL: goto x86_l_4f0b;
	case 20240ULL: goto x86_l_4f10;
	case 20245ULL: goto x86_l_4f15;
	case 20251ULL: goto x86_l_4f1b;
	case 20256ULL: goto x86_l_4f20;
	case 20264ULL: goto x86_l_4f28;
	case 20268ULL: goto x86_l_4f2c;
	case 20275ULL: goto x86_l_4f33;
	case 20280ULL: goto x86_l_4f38;
	case 20285ULL: goto x86_l_4f3d;
	case 20287ULL: goto x86_l_4f3f;
	case 20290ULL: goto x86_l_4f42;
	case 20292ULL: goto x86_l_4f44;
	case 20294ULL: goto x86_l_4f46;
	case 20300ULL: goto x86_l_4f4c;
	case 20303ULL: goto x86_l_4f4f;
	case 20308ULL: goto x86_l_4f54;
	case 20313ULL: goto x86_l_4f59;
	case 20319ULL: goto x86_l_4f5f;
	case 20324ULL: goto x86_l_4f64;
	case 20332ULL: goto x86_l_4f6c;
	case 20336ULL: goto x86_l_4f70;
	case 20343ULL: goto x86_l_4f77;
	case 20346ULL: goto x86_l_4f7a;
	case 20351ULL: goto x86_l_4f7f;
	case 20353ULL: goto x86_l_4f81;
	case 20357ULL: goto x86_l_4f85;
	case 20365ULL: goto x86_l_4f8d;
	case 20368ULL: goto x86_l_4f90;
	case 20376ULL: goto x86_l_4f98;
	case 20385ULL: goto x86_l_4fa1;
	case 20390ULL: goto x86_l_4fa6;
	case 20397ULL: goto x86_l_4fad;
	case 20402ULL: goto x86_l_4fb2;
	case 20407ULL: goto x86_l_4fb7;
	case 20412ULL: goto x86_l_4fbc;
	case 20414ULL: goto x86_l_4fbe;
	case 20416ULL: goto x86_l_4fc0;
	case 20422ULL: goto x86_l_4fc6;
	case 20428ULL: goto x86_l_4fcc;
	case 20431ULL: goto x86_l_4fcf;
	case 20436ULL: goto x86_l_4fd4;
	case 20441ULL: goto x86_l_4fd9;
	case 20447ULL: goto x86_l_4fdf;
	case 20452ULL: goto x86_l_4fe4;
	case 20460ULL: goto x86_l_4fec;
	case 20464ULL: goto x86_l_4ff0;
	case 20471ULL: goto x86_l_4ff7;
	case 20476ULL: goto x86_l_4ffc;
	case 20481ULL: goto x86_l_5001;
	case 20483ULL: goto x86_l_5003;
	case 20486ULL: goto x86_l_5006;
	case 20488ULL: goto x86_l_5008;
	case 20490ULL: goto x86_l_500a;
	case 20496ULL: goto x86_l_5010;
	case 20499ULL: goto x86_l_5013;
	case 20504ULL: goto x86_l_5018;
	case 20509ULL: goto x86_l_501d;
	case 20515ULL: goto x86_l_5023;
	case 20520ULL: goto x86_l_5028;
	case 20528ULL: goto x86_l_5030;
	case 20532ULL: goto x86_l_5034;
	case 20539ULL: goto x86_l_503b;
	case 20542ULL: goto x86_l_503e;
	case 20547ULL: goto x86_l_5043;
	case 20549ULL: goto x86_l_5045;
	case 20553ULL: goto x86_l_5049;
	case 20561ULL: goto x86_l_5051;
	case 20564ULL: goto x86_l_5054;
	case 20572ULL: goto x86_l_505c;
	case 20581ULL: goto x86_l_5065;
	case 20586ULL: goto x86_l_506a;
	case 20593ULL: goto x86_l_5071;
	case 20598ULL: goto x86_l_5076;
	case 20603ULL: goto x86_l_507b;
	case 20608ULL: goto x86_l_5080;
	case 20610ULL: goto x86_l_5082;
	case 20612ULL: goto x86_l_5084;
	case 20618ULL: goto x86_l_508a;
	case 20624ULL: goto x86_l_5090;
	case 20627ULL: goto x86_l_5093;
	case 20632ULL: goto x86_l_5098;
	case 20637ULL: goto x86_l_509d;
	case 20643ULL: goto x86_l_50a3;
	case 20648ULL: goto x86_l_50a8;
	case 20656ULL: goto x86_l_50b0;
	case 20660ULL: goto x86_l_50b4;
	case 20667ULL: goto x86_l_50bb;
	case 20672ULL: goto x86_l_50c0;
	case 20677ULL: goto x86_l_50c5;
	case 20679ULL: goto x86_l_50c7;
	case 20682ULL: goto x86_l_50ca;
	case 20684ULL: goto x86_l_50cc;
	case 20686ULL: goto x86_l_50ce;
	case 20692ULL: goto x86_l_50d4;
	case 20695ULL: goto x86_l_50d7;
	case 20700ULL: goto x86_l_50dc;
	case 20705ULL: goto x86_l_50e1;
	case 20711ULL: goto x86_l_50e7;
	case 20716ULL: goto x86_l_50ec;
	case 20724ULL: goto x86_l_50f4;
	case 20728ULL: goto x86_l_50f8;
	case 20735ULL: goto x86_l_50ff;
	case 20738ULL: goto x86_l_5102;
	case 20743ULL: goto x86_l_5107;
	case 20745ULL: goto x86_l_5109;
	case 20749ULL: goto x86_l_510d;
	case 20757ULL: goto x86_l_5115;
	case 20760ULL: goto x86_l_5118;
	case 20768ULL: goto x86_l_5120;
	case 20777ULL: goto x86_l_5129;
	case 20782ULL: goto x86_l_512e;
	case 20789ULL: goto x86_l_5135;
	case 20794ULL: goto x86_l_513a;
	case 20799ULL: goto x86_l_513f;
	case 20804ULL: goto x86_l_5144;
	case 20806ULL: goto x86_l_5146;
	case 20808ULL: goto x86_l_5148;
	case 20814ULL: goto x86_l_514e;
	case 20820ULL: goto x86_l_5154;
	case 20823ULL: goto x86_l_5157;
	case 20828ULL: goto x86_l_515c;
	case 20833ULL: goto x86_l_5161;
	case 20839ULL: goto x86_l_5167;
	case 20844ULL: goto x86_l_516c;
	case 20852ULL: goto x86_l_5174;
	case 20856ULL: goto x86_l_5178;
	case 20863ULL: goto x86_l_517f;
	case 20868ULL: goto x86_l_5184;
	case 20873ULL: goto x86_l_5189;
	case 20875ULL: goto x86_l_518b;
	case 20878ULL: goto x86_l_518e;
	case 20880ULL: goto x86_l_5190;
	case 20882ULL: goto x86_l_5192;
	case 20888ULL: goto x86_l_5198;
	case 20891ULL: goto x86_l_519b;
	case 20896ULL: goto x86_l_51a0;
	case 20901ULL: goto x86_l_51a5;
	case 20907ULL: goto x86_l_51ab;
	case 20912ULL: goto x86_l_51b0;
	case 20920ULL: goto x86_l_51b8;
	case 20924ULL: goto x86_l_51bc;
	case 20931ULL: goto x86_l_51c3;
	case 20934ULL: goto x86_l_51c6;
	case 20939ULL: goto x86_l_51cb;
	case 20941ULL: goto x86_l_51cd;
	case 20945ULL: goto x86_l_51d1;
	case 20953ULL: goto x86_l_51d9;
	case 20956ULL: goto x86_l_51dc;
	case 20964ULL: goto x86_l_51e4;
	case 20973ULL: goto x86_l_51ed;
	case 20978ULL: goto x86_l_51f2;
	case 20985ULL: goto x86_l_51f9;
	case 20990ULL: goto x86_l_51fe;
	case 20995ULL: goto x86_l_5203;
	case 21000ULL: goto x86_l_5208;
	case 21002ULL: goto x86_l_520a;
	case 21004ULL: goto x86_l_520c;
	case 21010ULL: goto x86_l_5212;
	case 21016ULL: goto x86_l_5218;
	case 21019ULL: goto x86_l_521b;
	case 21024ULL: goto x86_l_5220;
	case 21029ULL: goto x86_l_5225;
	case 21035ULL: goto x86_l_522b;
	case 21040ULL: goto x86_l_5230;
	case 21048ULL: goto x86_l_5238;
	case 21052ULL: goto x86_l_523c;
	case 21059ULL: goto x86_l_5243;
	case 21064ULL: goto x86_l_5248;
	case 21069ULL: goto x86_l_524d;
	case 21071ULL: goto x86_l_524f;
	case 21074ULL: goto x86_l_5252;
	case 21076ULL: goto x86_l_5254;
	case 21078ULL: goto x86_l_5256;
	case 21084ULL: goto x86_l_525c;
	case 21087ULL: goto x86_l_525f;
	case 21092ULL: goto x86_l_5264;
	case 21097ULL: goto x86_l_5269;
	case 21103ULL: goto x86_l_526f;
	case 21108ULL: goto x86_l_5274;
	case 21116ULL: goto x86_l_527c;
	case 21120ULL: goto x86_l_5280;
	case 21127ULL: goto x86_l_5287;
	case 21130ULL: goto x86_l_528a;
	case 21135ULL: goto x86_l_528f;
	case 21137ULL: goto x86_l_5291;
	case 21141ULL: goto x86_l_5295;
	case 21149ULL: goto x86_l_529d;
	case 21152ULL: goto x86_l_52a0;
	case 21160ULL: goto x86_l_52a8;
	case 21169ULL: goto x86_l_52b1;
	case 21174ULL: goto x86_l_52b6;
	case 21181ULL: goto x86_l_52bd;
	case 21186ULL: goto x86_l_52c2;
	case 21191ULL: goto x86_l_52c7;
	case 21196ULL: goto x86_l_52cc;
	case 21198ULL: goto x86_l_52ce;
	case 21200ULL: goto x86_l_52d0;
	case 21206ULL: goto x86_l_52d6;
	case 21212ULL: goto x86_l_52dc;
	case 21215ULL: goto x86_l_52df;
	case 21220ULL: goto x86_l_52e4;
	case 21225ULL: goto x86_l_52e9;
	case 21231ULL: goto x86_l_52ef;
	case 21236ULL: goto x86_l_52f4;
	case 21244ULL: goto x86_l_52fc;
	case 21248ULL: goto x86_l_5300;
	case 21255ULL: goto x86_l_5307;
	case 21260ULL: goto x86_l_530c;
	case 21265ULL: goto x86_l_5311;
	case 21267ULL: goto x86_l_5313;
	case 21270ULL: goto x86_l_5316;
	case 21272ULL: goto x86_l_5318;
	case 21274ULL: goto x86_l_531a;
	case 21280ULL: goto x86_l_5320;
	case 21283ULL: goto x86_l_5323;
	case 21288ULL: goto x86_l_5328;
	case 21293ULL: goto x86_l_532d;
	case 21299ULL: goto x86_l_5333;
	case 21304ULL: goto x86_l_5338;
	case 21312ULL: goto x86_l_5340;
	case 21316ULL: goto x86_l_5344;
	case 21323ULL: goto x86_l_534b;
	case 21326ULL: goto x86_l_534e;
	case 21331ULL: goto x86_l_5353;
	case 21333ULL: goto x86_l_5355;
	case 21337ULL: goto x86_l_5359;
	case 21345ULL: goto x86_l_5361;
	case 21348ULL: goto x86_l_5364;
	case 21356ULL: goto x86_l_536c;
	case 21365ULL: goto x86_l_5375;
	case 21370ULL: goto x86_l_537a;
	case 21377ULL: goto x86_l_5381;
	case 21382ULL: goto x86_l_5386;
	case 21387ULL: goto x86_l_538b;
	case 21392ULL: goto x86_l_5390;
	case 21394ULL: goto x86_l_5392;
	case 21396ULL: goto x86_l_5394;
	case 21402ULL: goto x86_l_539a;
	case 21408ULL: goto x86_l_53a0;
	case 21411ULL: goto x86_l_53a3;
	case 21416ULL: goto x86_l_53a8;
	case 21421ULL: goto x86_l_53ad;
	case 21427ULL: goto x86_l_53b3;
	case 21432ULL: goto x86_l_53b8;
	case 21440ULL: goto x86_l_53c0;
	case 21444ULL: goto x86_l_53c4;
	case 21451ULL: goto x86_l_53cb;
	case 21456ULL: goto x86_l_53d0;
	case 21461ULL: goto x86_l_53d5;
	case 21463ULL: goto x86_l_53d7;
	case 21466ULL: goto x86_l_53da;
	case 21468ULL: goto x86_l_53dc;
	case 21470ULL: goto x86_l_53de;
	case 21476ULL: goto x86_l_53e4;
	case 21479ULL: goto x86_l_53e7;
	case 21484ULL: goto x86_l_53ec;
	case 21489ULL: goto x86_l_53f1;
	case 21495ULL: goto x86_l_53f7;
	case 21500ULL: goto x86_l_53fc;
	case 21508ULL: goto x86_l_5404;
	case 21512ULL: goto x86_l_5408;
	case 21519ULL: goto x86_l_540f;
	case 21522ULL: goto x86_l_5412;
	case 21527ULL: goto x86_l_5417;
	case 21529ULL: goto x86_l_5419;
	case 21533ULL: goto x86_l_541d;
	case 21541ULL: goto x86_l_5425;
	case 21544ULL: goto x86_l_5428;
	case 21552ULL: goto x86_l_5430;
	case 21561ULL: goto x86_l_5439;
	case 21566ULL: goto x86_l_543e;
	case 21573ULL: goto x86_l_5445;
	case 21578ULL: goto x86_l_544a;
	case 21583ULL: goto x86_l_544f;
	case 21588ULL: goto x86_l_5454;
	case 21590ULL: goto x86_l_5456;
	case 21592ULL: goto x86_l_5458;
	case 21598ULL: goto x86_l_545e;
	case 21604ULL: goto x86_l_5464;
	case 21607ULL: goto x86_l_5467;
	case 21612ULL: goto x86_l_546c;
	case 21617ULL: goto x86_l_5471;
	case 21623ULL: goto x86_l_5477;
	case 21628ULL: goto x86_l_547c;
	case 21636ULL: goto x86_l_5484;
	case 21640ULL: goto x86_l_5488;
	case 21647ULL: goto x86_l_548f;
	case 21652ULL: goto x86_l_5494;
	case 21657ULL: goto x86_l_5499;
	case 21659ULL: goto x86_l_549b;
	case 21662ULL: goto x86_l_549e;
	case 21664ULL: goto x86_l_54a0;
	case 21666ULL: goto x86_l_54a2;
	case 21672ULL: goto x86_l_54a8;
	case 21675ULL: goto x86_l_54ab;
	case 21680ULL: goto x86_l_54b0;
	case 21685ULL: goto x86_l_54b5;
	case 21691ULL: goto x86_l_54bb;
	case 21696ULL: goto x86_l_54c0;
	case 21704ULL: goto x86_l_54c8;
	case 21708ULL: goto x86_l_54cc;
	case 21715ULL: goto x86_l_54d3;
	case 21718ULL: goto x86_l_54d6;
	case 21723ULL: goto x86_l_54db;
	case 21725ULL: goto x86_l_54dd;
	case 21729ULL: goto x86_l_54e1;
	case 21737ULL: goto x86_l_54e9;
	case 21740ULL: goto x86_l_54ec;
	case 21748ULL: goto x86_l_54f4;
	case 21757ULL: goto x86_l_54fd;
	case 21762ULL: goto x86_l_5502;
	case 21769ULL: goto x86_l_5509;
	case 21774ULL: goto x86_l_550e;
	case 21779ULL: goto x86_l_5513;
	case 21784ULL: goto x86_l_5518;
	case 21786ULL: goto x86_l_551a;
	case 21788ULL: goto x86_l_551c;
	case 21794ULL: goto x86_l_5522;
	case 21800ULL: goto x86_l_5528;
	case 21803ULL: goto x86_l_552b;
	case 21808ULL: goto x86_l_5530;
	case 21813ULL: goto x86_l_5535;
	case 21819ULL: goto x86_l_553b;
	case 21824ULL: goto x86_l_5540;
	case 21832ULL: goto x86_l_5548;
	case 21836ULL: goto x86_l_554c;
	case 21843ULL: goto x86_l_5553;
	case 21848ULL: goto x86_l_5558;
	case 21853ULL: goto x86_l_555d;
	case 21855ULL: goto x86_l_555f;
	case 21858ULL: goto x86_l_5562;
	case 21860ULL: goto x86_l_5564;
	case 21862ULL: goto x86_l_5566;
	case 21868ULL: goto x86_l_556c;
	case 21871ULL: goto x86_l_556f;
	case 21876ULL: goto x86_l_5574;
	case 21881ULL: goto x86_l_5579;
	case 21887ULL: goto x86_l_557f;
	case 21892ULL: goto x86_l_5584;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4e36:
	/* 0x4e36: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4e38:
	/* 0x4e38: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4e3e:
	/* 0x4e3e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4e44:
	/* 0x4e44: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e47:
	/* 0x4e47: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4e4c:
	/* 0x4e4c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e51:
	/* 0x4e51: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4e57:
	/* 0x4e57: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4e5c:
	/* 0x4e5c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4e64:
	/* 0x4e64: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4e68:
	/* 0x4e68: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4e6f:
	/* 0x4e6f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4e74:
	/* 0x4e74: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4e79:
	/* 0x4e79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e7b:
	/* 0x4e7b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e7e:
	/* 0x4e7e: mov    cl,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 25ULL);
x86_l_4e80:
	/* 0x4e80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e82:
	/* 0x4e82: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4e88:
	/* 0x4e88: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4e8b:
	/* 0x4e8b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4e90:
	/* 0x4e90: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e95:
	/* 0x4e95: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4e9b:
	/* 0x4e9b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ea0:
	/* 0x4ea0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4ea8:
	/* 0x4ea8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4eac:
	/* 0x4eac: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4eb3:
	/* 0x4eb3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4eb6:
	/* 0x4eb6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4ebb:
	/* 0x4ebb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ebd:
	/* 0x4ebd: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ec1:
	/* 0x4ec1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4ec9:
	/* 0x4ec9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4ecc:
	/* 0x4ecc: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4ed4:
	/* 0x4ed4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4edd:
	/* 0x4edd: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4ee2:
	/* 0x4ee2: lea    rdx,[rax+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_4ee9:
	/* 0x4ee9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4eee:
	/* 0x4eee: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ef3:
	/* 0x4ef3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4ef8:
	/* 0x4ef8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4efa:
	/* 0x4efa: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4efc:
	/* 0x4efc: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4f02:
	/* 0x4f02: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4f08:
	/* 0x4f08: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f0b:
	/* 0x4f0b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4f10:
	/* 0x4f10: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f15:
	/* 0x4f15: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4f1b:
	/* 0x4f1b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4f20:
	/* 0x4f20: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f28:
	/* 0x4f28: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4f2c:
	/* 0x4f2c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4f33:
	/* 0x4f33: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f38:
	/* 0x4f38: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_4f3d:
	/* 0x4f3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f3f:
	/* 0x4f3f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4f42:
	/* 0x4f42: mov    cl,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 26ULL);
x86_l_4f44:
	/* 0x4f44: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4f46:
	/* 0x4f46: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_4f4c:
	/* 0x4f4c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f4f:
	/* 0x4f4f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_4f54:
	/* 0x4f54: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f59:
	/* 0x4f59: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4f5f:
	/* 0x4f5f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4f64:
	/* 0x4f64: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4f6c:
	/* 0x4f6c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_4f70:
	/* 0x4f70: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_4f77:
	/* 0x4f77: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4f7a:
	/* 0x4f7a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_4f7f:
	/* 0x4f7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f81:
	/* 0x4f81: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f85:
	/* 0x4f85: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_4f8d:
	/* 0x4f8d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_4f90:
	/* 0x4f90: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_4f98:
	/* 0x4f98: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4fa1:
	/* 0x4fa1: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4fa6:
	/* 0x4fa6: lea    rdx,[rax+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_4fad:
	/* 0x4fad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4fb2:
	/* 0x4fb2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4fb7:
	/* 0x4fb7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4fbc:
	/* 0x4fbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fbe:
	/* 0x4fbe: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_4fc0:
	/* 0x4fc0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4fc6:
	/* 0x4fc6: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_4fcc:
	/* 0x4fcc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4fcf:
	/* 0x4fcf: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_4fd4:
	/* 0x4fd4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fd9:
	/* 0x4fd9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_4fdf:
	/* 0x4fdf: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_4fe4:
	/* 0x4fe4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_4fec:
	/* 0x4fec: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_4ff0:
	/* 0x4ff0: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_4ff7:
	/* 0x4ff7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4ffc:
	/* 0x4ffc: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5001:
	/* 0x5001: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5003:
	/* 0x5003: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5006:
	/* 0x5006: mov    cl,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 27ULL);
x86_l_5008:
	/* 0x5008: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_500a:
	/* 0x500a: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_5010:
	/* 0x5010: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5013:
	/* 0x5013: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_5018:
	/* 0x5018: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_501d:
	/* 0x501d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5023:
	/* 0x5023: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5028:
	/* 0x5028: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5030:
	/* 0x5030: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5034:
	/* 0x5034: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_503b:
	/* 0x503b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_503e:
	/* 0x503e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5043:
	/* 0x5043: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5045:
	/* 0x5045: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5049:
	/* 0x5049: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5051:
	/* 0x5051: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5054:
	/* 0x5054: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_505c:
	/* 0x505c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5065:
	/* 0x5065: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_506a:
	/* 0x506a: lea    rdx,[rax+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_5071:
	/* 0x5071: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5076:
	/* 0x5076: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_507b:
	/* 0x507b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5080:
	/* 0x5080: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5082:
	/* 0x5082: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_5084:
	/* 0x5084: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_508a:
	/* 0x508a: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_5090:
	/* 0x5090: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5093:
	/* 0x5093: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_5098:
	/* 0x5098: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_509d:
	/* 0x509d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_50a3:
	/* 0x50a3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_50a8:
	/* 0x50a8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_50b0:
	/* 0x50b0: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_50b4:
	/* 0x50b4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_50bb:
	/* 0x50bb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50c0:
	/* 0x50c0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_50c5:
	/* 0x50c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50c7:
	/* 0x50c7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50ca:
	/* 0x50ca: mov    cl,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 28ULL);
x86_l_50cc:
	/* 0x50cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50ce:
	/* 0x50ce: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_50d4:
	/* 0x50d4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_50d7:
	/* 0x50d7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_50dc:
	/* 0x50dc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50e1:
	/* 0x50e1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_50e7:
	/* 0x50e7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50ec:
	/* 0x50ec: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_50f4:
	/* 0x50f4: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_50f8:
	/* 0x50f8: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_50ff:
	/* 0x50ff: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5102:
	/* 0x5102: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5107:
	/* 0x5107: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5109:
	/* 0x5109: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_510d:
	/* 0x510d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5115:
	/* 0x5115: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5118:
	/* 0x5118: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5120:
	/* 0x5120: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5129:
	/* 0x5129: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_512e:
	/* 0x512e: lea    rdx,[rax+0xe8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5135:
	/* 0x5135: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_513a:
	/* 0x513a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_513f:
	/* 0x513f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5144:
	/* 0x5144: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5146:
	/* 0x5146: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5148:
	/* 0x5148: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_514e:
	/* 0x514e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_5154:
	/* 0x5154: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5157:
	/* 0x5157: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_515c:
	/* 0x515c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5161:
	/* 0x5161: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5167:
	/* 0x5167: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_516c:
	/* 0x516c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5174:
	/* 0x5174: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_5178:
	/* 0x5178: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_517f:
	/* 0x517f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5184:
	/* 0x5184: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5189:
	/* 0x5189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_518b:
	/* 0x518b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_518e:
	/* 0x518e: mov    cl,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 29ULL);
x86_l_5190:
	/* 0x5190: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5192:
	/* 0x5192: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_5198:
	/* 0x5198: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_519b:
	/* 0x519b: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_51a0:
	/* 0x51a0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51a5:
	/* 0x51a5: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_51ab:
	/* 0x51ab: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51b0:
	/* 0x51b0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_51b8:
	/* 0x51b8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_51bc:
	/* 0x51bc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_51c3:
	/* 0x51c3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_51c6:
	/* 0x51c6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51cb:
	/* 0x51cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51cd:
	/* 0x51cd: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_51d1:
	/* 0x51d1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_51d9:
	/* 0x51d9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_51dc:
	/* 0x51dc: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_51e4:
	/* 0x51e4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_51ed:
	/* 0x51ed: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_51f2:
	/* 0x51f2: lea    rdx,[rax+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_51f9:
	/* 0x51f9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_51fe:
	/* 0x51fe: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5203:
	/* 0x5203: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5208:
	/* 0x5208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_520a:
	/* 0x520a: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_520c:
	/* 0x520c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5212:
	/* 0x5212: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_5218:
	/* 0x5218: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_521b:
	/* 0x521b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_5220:
	/* 0x5220: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5225:
	/* 0x5225: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_522b:
	/* 0x522b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5230:
	/* 0x5230: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5238:
	/* 0x5238: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_523c:
	/* 0x523c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5243:
	/* 0x5243: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5248:
	/* 0x5248: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_524d:
	/* 0x524d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_524f:
	/* 0x524f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5252:
	/* 0x5252: mov    cl,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 30ULL);
x86_l_5254:
	/* 0x5254: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5256:
	/* 0x5256: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_525c:
	/* 0x525c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_525f:
	/* 0x525f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_5264:
	/* 0x5264: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5269:
	/* 0x5269: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_526f:
	/* 0x526f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5274:
	/* 0x5274: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_527c:
	/* 0x527c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5280:
	/* 0x5280: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5287:
	/* 0x5287: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_528a:
	/* 0x528a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_528f:
	/* 0x528f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5291:
	/* 0x5291: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5295:
	/* 0x5295: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_529d:
	/* 0x529d: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_52a0:
	/* 0x52a0: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_52a8:
	/* 0x52a8: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_52b1:
	/* 0x52b1: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_52b6:
	/* 0x52b6: lea    rdx,[rax+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_52bd:
	/* 0x52bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_52c2:
	/* 0x52c2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_52c7:
	/* 0x52c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52cc:
	/* 0x52cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52ce:
	/* 0x52ce: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_52d0:
	/* 0x52d0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_52d6:
	/* 0x52d6: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_52dc:
	/* 0x52dc: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52df:
	/* 0x52df: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_52e4:
	/* 0x52e4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52e9:
	/* 0x52e9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_52ef:
	/* 0x52ef: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_52f4:
	/* 0x52f4: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_52fc:
	/* 0x52fc: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_5300:
	/* 0x5300: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5307:
	/* 0x5307: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_530c:
	/* 0x530c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5311:
	/* 0x5311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5313:
	/* 0x5313: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5316:
	/* 0x5316: mov    cl,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 31ULL);
x86_l_5318:
	/* 0x5318: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_531a:
	/* 0x531a: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_5320:
	/* 0x5320: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5323:
	/* 0x5323: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_5328:
	/* 0x5328: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_532d:
	/* 0x532d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5333:
	/* 0x5333: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5338:
	/* 0x5338: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5340:
	/* 0x5340: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5344:
	/* 0x5344: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_534b:
	/* 0x534b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_534e:
	/* 0x534e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5353:
	/* 0x5353: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5355:
	/* 0x5355: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5359:
	/* 0x5359: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5361:
	/* 0x5361: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5364:
	/* 0x5364: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_536c:
	/* 0x536c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5375:
	/* 0x5375: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_537a:
	/* 0x537a: lea    rdx,[rax+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_5381:
	/* 0x5381: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5386:
	/* 0x5386: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_538b:
	/* 0x538b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5390:
	/* 0x5390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5392:
	/* 0x5392: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_5394:
	/* 0x5394: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_539a:
	/* 0x539a: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_53a0:
	/* 0x53a0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53a3:
	/* 0x53a3: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_53a8:
	/* 0x53a8: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53ad:
	/* 0x53ad: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_53b3:
	/* 0x53b3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_53b8:
	/* 0x53b8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_53c0:
	/* 0x53c0: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_53c4:
	/* 0x53c4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_53cb:
	/* 0x53cb: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_53d0:
	/* 0x53d0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_53d5:
	/* 0x53d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d7:
	/* 0x53d7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53da:
	/* 0x53da: mov    cl,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_53dc:
	/* 0x53dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_53de:
	/* 0x53de: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_53e4:
	/* 0x53e4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_53e7:
	/* 0x53e7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_53ec:
	/* 0x53ec: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53f1:
	/* 0x53f1: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_53f7:
	/* 0x53f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_53fc:
	/* 0x53fc: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5404:
	/* 0x5404: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5408:
	/* 0x5408: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_540f:
	/* 0x540f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5412:
	/* 0x5412: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5417:
	/* 0x5417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5419:
	/* 0x5419: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_541d:
	/* 0x541d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5425:
	/* 0x5425: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5428:
	/* 0x5428: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5430:
	/* 0x5430: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5439:
	/* 0x5439: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_543e:
	/* 0x543e: lea    rdx,[rax+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_5445:
	/* 0x5445: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_544a:
	/* 0x544a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_544f:
	/* 0x544f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5454:
	/* 0x5454: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5456:
	/* 0x5456: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_5458:
	/* 0x5458: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_545e:
	/* 0x545e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_5464:
	/* 0x5464: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5467:
	/* 0x5467: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_546c:
	/* 0x546c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5471:
	/* 0x5471: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5477:
	/* 0x5477: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_547c:
	/* 0x547c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5484:
	/* 0x5484: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_5488:
	/* 0x5488: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_548f:
	/* 0x548f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5494:
	/* 0x5494: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5499:
	/* 0x5499: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549b:
	/* 0x549b: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_549e:
	/* 0x549e: mov    cl,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 33ULL);
x86_l_54a0:
	/* 0x54a0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54a2:
	/* 0x54a2: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_54a8:
	/* 0x54a8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54ab:
	/* 0x54ab: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_54b0:
	/* 0x54b0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54b5:
	/* 0x54b5: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_54bb:
	/* 0x54bb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_54c0:
	/* 0x54c0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_54c8:
	/* 0x54c8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_54cc:
	/* 0x54cc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_54d3:
	/* 0x54d3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_54d6:
	/* 0x54d6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_54db:
	/* 0x54db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54dd:
	/* 0x54dd: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_54e1:
	/* 0x54e1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_54e9:
	/* 0x54e9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_54ec:
	/* 0x54ec: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_54f4:
	/* 0x54f4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_54fd:
	/* 0x54fd: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5502:
	/* 0x5502: lea    rdx,[rax+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_5509:
	/* 0x5509: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_550e:
	/* 0x550e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5513:
	/* 0x5513: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5518:
	/* 0x5518: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_551a:
	/* 0x551a: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_551c:
	/* 0x551c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5522:
	/* 0x5522: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_5528:
	/* 0x5528: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_552b:
	/* 0x552b: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_5530:
	/* 0x5530: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5535:
	/* 0x5535: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_553b:
	/* 0x553b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5540:
	/* 0x5540: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5548:
	/* 0x5548: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_554c:
	/* 0x554c: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5553:
	/* 0x5553: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5558:
	/* 0x5558: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_555d:
	/* 0x555d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_555f:
	/* 0x555f: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5562:
	/* 0x5562: mov    cl,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 34ULL);
x86_l_5564:
	/* 0x5564: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5566:
	/* 0x5566: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_556c:
	/* 0x556c: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_556f:
	/* 0x556f: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_5574:
	/* 0x5574: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5579:
	/* 0x5579: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_557f:
	/* 0x557f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5584:
	/* 0x5584: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
	return 21900ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_12(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 21900ULL: goto x86_l_558c;
	case 21904ULL: goto x86_l_5590;
	case 21911ULL: goto x86_l_5597;
	case 21914ULL: goto x86_l_559a;
	case 21919ULL: goto x86_l_559f;
	case 21921ULL: goto x86_l_55a1;
	case 21925ULL: goto x86_l_55a5;
	case 21933ULL: goto x86_l_55ad;
	case 21936ULL: goto x86_l_55b0;
	case 21944ULL: goto x86_l_55b8;
	case 21953ULL: goto x86_l_55c1;
	case 21958ULL: goto x86_l_55c6;
	case 21965ULL: goto x86_l_55cd;
	case 21970ULL: goto x86_l_55d2;
	case 21975ULL: goto x86_l_55d7;
	case 21980ULL: goto x86_l_55dc;
	case 21982ULL: goto x86_l_55de;
	case 21984ULL: goto x86_l_55e0;
	case 21990ULL: goto x86_l_55e6;
	case 21996ULL: goto x86_l_55ec;
	case 21999ULL: goto x86_l_55ef;
	case 22004ULL: goto x86_l_55f4;
	case 22009ULL: goto x86_l_55f9;
	case 22015ULL: goto x86_l_55ff;
	case 22020ULL: goto x86_l_5604;
	case 22028ULL: goto x86_l_560c;
	case 22032ULL: goto x86_l_5610;
	case 22039ULL: goto x86_l_5617;
	case 22044ULL: goto x86_l_561c;
	case 22049ULL: goto x86_l_5621;
	case 22051ULL: goto x86_l_5623;
	case 22054ULL: goto x86_l_5626;
	case 22056ULL: goto x86_l_5628;
	case 22058ULL: goto x86_l_562a;
	case 22064ULL: goto x86_l_5630;
	case 22067ULL: goto x86_l_5633;
	case 22072ULL: goto x86_l_5638;
	case 22077ULL: goto x86_l_563d;
	case 22083ULL: goto x86_l_5643;
	case 22088ULL: goto x86_l_5648;
	case 22096ULL: goto x86_l_5650;
	case 22100ULL: goto x86_l_5654;
	case 22107ULL: goto x86_l_565b;
	case 22110ULL: goto x86_l_565e;
	case 22115ULL: goto x86_l_5663;
	case 22117ULL: goto x86_l_5665;
	case 22121ULL: goto x86_l_5669;
	case 22129ULL: goto x86_l_5671;
	case 22132ULL: goto x86_l_5674;
	case 22140ULL: goto x86_l_567c;
	case 22149ULL: goto x86_l_5685;
	case 22154ULL: goto x86_l_568a;
	case 22161ULL: goto x86_l_5691;
	case 22166ULL: goto x86_l_5696;
	case 22171ULL: goto x86_l_569b;
	case 22176ULL: goto x86_l_56a0;
	case 22178ULL: goto x86_l_56a2;
	case 22180ULL: goto x86_l_56a4;
	case 22186ULL: goto x86_l_56aa;
	case 22192ULL: goto x86_l_56b0;
	case 22195ULL: goto x86_l_56b3;
	case 22200ULL: goto x86_l_56b8;
	case 22205ULL: goto x86_l_56bd;
	case 22211ULL: goto x86_l_56c3;
	case 22216ULL: goto x86_l_56c8;
	case 22224ULL: goto x86_l_56d0;
	case 22228ULL: goto x86_l_56d4;
	case 22235ULL: goto x86_l_56db;
	case 22240ULL: goto x86_l_56e0;
	case 22245ULL: goto x86_l_56e5;
	case 22247ULL: goto x86_l_56e7;
	case 22250ULL: goto x86_l_56ea;
	case 22252ULL: goto x86_l_56ec;
	case 22254ULL: goto x86_l_56ee;
	case 22260ULL: goto x86_l_56f4;
	case 22263ULL: goto x86_l_56f7;
	case 22268ULL: goto x86_l_56fc;
	case 22273ULL: goto x86_l_5701;
	case 22279ULL: goto x86_l_5707;
	case 22284ULL: goto x86_l_570c;
	case 22292ULL: goto x86_l_5714;
	case 22296ULL: goto x86_l_5718;
	case 22303ULL: goto x86_l_571f;
	case 22306ULL: goto x86_l_5722;
	case 22311ULL: goto x86_l_5727;
	case 22313ULL: goto x86_l_5729;
	case 22317ULL: goto x86_l_572d;
	case 22325ULL: goto x86_l_5735;
	case 22328ULL: goto x86_l_5738;
	case 22336ULL: goto x86_l_5740;
	case 22345ULL: goto x86_l_5749;
	case 22350ULL: goto x86_l_574e;
	case 22357ULL: goto x86_l_5755;
	case 22362ULL: goto x86_l_575a;
	case 22367ULL: goto x86_l_575f;
	case 22372ULL: goto x86_l_5764;
	case 22374ULL: goto x86_l_5766;
	case 22376ULL: goto x86_l_5768;
	case 22382ULL: goto x86_l_576e;
	case 22388ULL: goto x86_l_5774;
	case 22391ULL: goto x86_l_5777;
	case 22396ULL: goto x86_l_577c;
	case 22401ULL: goto x86_l_5781;
	case 22407ULL: goto x86_l_5787;
	case 22412ULL: goto x86_l_578c;
	case 22420ULL: goto x86_l_5794;
	case 22424ULL: goto x86_l_5798;
	case 22431ULL: goto x86_l_579f;
	case 22436ULL: goto x86_l_57a4;
	case 22441ULL: goto x86_l_57a9;
	case 22443ULL: goto x86_l_57ab;
	case 22446ULL: goto x86_l_57ae;
	case 22448ULL: goto x86_l_57b0;
	case 22450ULL: goto x86_l_57b2;
	case 22456ULL: goto x86_l_57b8;
	case 22459ULL: goto x86_l_57bb;
	case 22464ULL: goto x86_l_57c0;
	case 22469ULL: goto x86_l_57c5;
	case 22475ULL: goto x86_l_57cb;
	case 22480ULL: goto x86_l_57d0;
	case 22488ULL: goto x86_l_57d8;
	case 22492ULL: goto x86_l_57dc;
	case 22499ULL: goto x86_l_57e3;
	case 22502ULL: goto x86_l_57e6;
	case 22507ULL: goto x86_l_57eb;
	case 22509ULL: goto x86_l_57ed;
	case 22513ULL: goto x86_l_57f1;
	case 22521ULL: goto x86_l_57f9;
	case 22524ULL: goto x86_l_57fc;
	case 22532ULL: goto x86_l_5804;
	case 22540ULL: goto x86_l_580c;
	case 22543ULL: goto x86_l_580f;
	case 22548ULL: goto x86_l_5814;
	case 22550ULL: goto x86_l_5816;
	case 22555ULL: goto x86_l_581b;
	case 22560ULL: goto x86_l_5820;
	case 22565ULL: goto x86_l_5825;
	case 22572ULL: goto x86_l_582c;
	case 22576ULL: goto x86_l_5830;
	case 22583ULL: goto x86_l_5837;
	case 22588ULL: goto x86_l_583c;
	case 22593ULL: goto x86_l_5841;
	case 22595ULL: goto x86_l_5843;
	case 22598ULL: goto x86_l_5846;
	case 22600ULL: goto x86_l_5848;
	case 22602ULL: goto x86_l_584a;
	case 22608ULL: goto x86_l_5850;
	case 22611ULL: goto x86_l_5853;
	case 22616ULL: goto x86_l_5858;
	case 22621ULL: goto x86_l_585d;
	case 22627ULL: goto x86_l_5863;
	case 22632ULL: goto x86_l_5868;
	case 22640ULL: goto x86_l_5870;
	case 22644ULL: goto x86_l_5874;
	case 22651ULL: goto x86_l_587b;
	case 22654ULL: goto x86_l_587e;
	case 22659ULL: goto x86_l_5883;
	case 22661ULL: goto x86_l_5885;
	case 22665ULL: goto x86_l_5889;
	case 22673ULL: goto x86_l_5891;
	case 22676ULL: goto x86_l_5894;
	case 22684ULL: goto x86_l_589c;
	case 22686ULL: goto x86_l_589e;
	case 22691ULL: goto x86_l_58a3;
	case 22696ULL: goto x86_l_58a8;
	case 22701ULL: goto x86_l_58ad;
	case 22707ULL: goto x86_l_58b3;
	case 22712ULL: goto x86_l_58b8;
	case 22717ULL: goto x86_l_58bd;
	case 22721ULL: goto x86_l_58c1;
	case 22724ULL: goto x86_l_58c4;
	case 22729ULL: goto x86_l_58c9;
	case 22731ULL: goto x86_l_58cb;
	case 22736ULL: goto x86_l_58d0;
	case 22741ULL: goto x86_l_58d5;
	case 22746ULL: goto x86_l_58da;
	case 22751ULL: goto x86_l_58df;
	case 22753ULL: goto x86_l_58e1;
	case 22758ULL: goto x86_l_58e6;
	case 22763ULL: goto x86_l_58eb;
	case 22768ULL: goto x86_l_58f0;
	case 22773ULL: goto x86_l_58f5;
	case 22775ULL: goto x86_l_58f7;
	case 22780ULL: goto x86_l_58fc;
	case 22784ULL: goto x86_l_5900;
	case 22789ULL: goto x86_l_5905;
	case 22794ULL: goto x86_l_590a;
	case 22799ULL: goto x86_l_590f;
	case 22802ULL: goto x86_l_5912;
	case 22804ULL: goto x86_l_5914;
	case 22809ULL: goto x86_l_5919;
	case 22813ULL: goto x86_l_591d;
	case 22817ULL: goto x86_l_5921;
	case 22822ULL: goto x86_l_5926;
	case 22827ULL: goto x86_l_592b;
	case 22832ULL: goto x86_l_5930;
	case 22834ULL: goto x86_l_5932;
	case 22838ULL: goto x86_l_5936;
	case 22841ULL: goto x86_l_5939;
	case 22843ULL: goto x86_l_593b;
	case 22848ULL: goto x86_l_5940;
	case 22851ULL: goto x86_l_5943;
	case 22853ULL: goto x86_l_5945;
	case 22857ULL: goto x86_l_5949;
	case 22862ULL: goto x86_l_594e;
	case 22867ULL: goto x86_l_5953;
	case 22872ULL: goto x86_l_5958;
	case 22874ULL: goto x86_l_595a;
	case 22878ULL: goto x86_l_595e;
	case 22880ULL: goto x86_l_5960;
	case 22886ULL: goto x86_l_5966;
	case 22888ULL: goto x86_l_5968;
	case 22890ULL: goto x86_l_596a;
	case 22896ULL: goto x86_l_5970;
	case 22898ULL: goto x86_l_5972;
	case 22900ULL: goto x86_l_5974;
	case 22905ULL: goto x86_l_5979;
	case 22910ULL: goto x86_l_597e;
	case 22917ULL: goto x86_l_5985;
	case 22922ULL: goto x86_l_598a;
	case 22925ULL: goto x86_l_598d;
	case 22931ULL: goto x86_l_5993;
	case 22936ULL: goto x86_l_5998;
	case 22941ULL: goto x86_l_599d;
	case 22947ULL: goto x86_l_59a3;
	case 22952ULL: goto x86_l_59a8;
	case 22957ULL: goto x86_l_59ad;
	case 22961ULL: goto x86_l_59b1;
	case 22964ULL: goto x86_l_59b4;
	case 22969ULL: goto x86_l_59b9;
	case 22971ULL: goto x86_l_59bb;
	case 22976ULL: goto x86_l_59c0;
	case 22981ULL: goto x86_l_59c5;
	case 22986ULL: goto x86_l_59ca;
	case 22991ULL: goto x86_l_59cf;
	case 22993ULL: goto x86_l_59d1;
	case 22998ULL: goto x86_l_59d6;
	case 23003ULL: goto x86_l_59db;
	case 23008ULL: goto x86_l_59e0;
	case 23013ULL: goto x86_l_59e5;
	case 23015ULL: goto x86_l_59e7;
	case 23020ULL: goto x86_l_59ec;
	case 23024ULL: goto x86_l_59f0;
	case 23026ULL: goto x86_l_59f2;
	case 23031ULL: goto x86_l_59f7;
	case 23037ULL: goto x86_l_59fd;
	case 23040ULL: goto x86_l_5a00;
	case 23045ULL: goto x86_l_5a05;
	case 23047ULL: goto x86_l_5a07;
	case 23050ULL: goto x86_l_5a0a;
	case 23056ULL: goto x86_l_5a10;
	case 23059ULL: goto x86_l_5a13;
	case 23065ULL: goto x86_l_5a19;
	case 23070ULL: goto x86_l_5a1e;
	case 23072ULL: goto x86_l_5a20;
	case 23076ULL: goto x86_l_5a24;
	case 23081ULL: goto x86_l_5a29;
	case 23086ULL: goto x86_l_5a2e;
	case 23091ULL: goto x86_l_5a33;
	case 23094ULL: goto x86_l_5a36;
	case 23096ULL: goto x86_l_5a38;
	case 23101ULL: goto x86_l_5a3d;
	case 23105ULL: goto x86_l_5a41;
	case 23109ULL: goto x86_l_5a45;
	case 23114ULL: goto x86_l_5a4a;
	case 23119ULL: goto x86_l_5a4f;
	case 23124ULL: goto x86_l_5a54;
	case 23126ULL: goto x86_l_5a56;
	case 23130ULL: goto x86_l_5a5a;
	case 23133ULL: goto x86_l_5a5d;
	case 23135ULL: goto x86_l_5a5f;
	case 23140ULL: goto x86_l_5a64;
	case 23143ULL: goto x86_l_5a67;
	case 23145ULL: goto x86_l_5a69;
	case 23149ULL: goto x86_l_5a6d;
	case 23154ULL: goto x86_l_5a72;
	case 23159ULL: goto x86_l_5a77;
	case 23164ULL: goto x86_l_5a7c;
	case 23166ULL: goto x86_l_5a7e;
	case 23170ULL: goto x86_l_5a82;
	case 23172ULL: goto x86_l_5a84;
	case 23178ULL: goto x86_l_5a8a;
	case 23180ULL: goto x86_l_5a8c;
	case 23182ULL: goto x86_l_5a8e;
	case 23188ULL: goto x86_l_5a94;
	case 23193ULL: goto x86_l_5a99;
	case 23199ULL: goto x86_l_5a9f;
	case 23202ULL: goto x86_l_5aa2;
	case 23207ULL: goto x86_l_5aa7;
	case 23209ULL: goto x86_l_5aa9;
	case 23212ULL: goto x86_l_5aac;
	case 23218ULL: goto x86_l_5ab2;
	case 23221ULL: goto x86_l_5ab5;
	case 23227ULL: goto x86_l_5abb;
	case 23232ULL: goto x86_l_5ac0;
	case 23234ULL: goto x86_l_5ac2;
	case 23238ULL: goto x86_l_5ac6;
	case 23240ULL: goto x86_l_5ac8;
	case 23243ULL: goto x86_l_5acb;
	case 23249ULL: goto x86_l_5ad1;
	case 23254ULL: goto x86_l_5ad6;
	case 23259ULL: goto x86_l_5adb;
	case 23265ULL: goto x86_l_5ae1;
	case 23270ULL: goto x86_l_5ae6;
	case 23275ULL: goto x86_l_5aeb;
	case 23279ULL: goto x86_l_5aef;
	case 23282ULL: goto x86_l_5af2;
	case 23287ULL: goto x86_l_5af7;
	case 23289ULL: goto x86_l_5af9;
	case 23294ULL: goto x86_l_5afe;
	case 23299ULL: goto x86_l_5b03;
	case 23304ULL: goto x86_l_5b08;
	case 23309ULL: goto x86_l_5b0d;
	case 23311ULL: goto x86_l_5b0f;
	case 23316ULL: goto x86_l_5b14;
	case 23321ULL: goto x86_l_5b19;
	case 23326ULL: goto x86_l_5b1e;
	case 23331ULL: goto x86_l_5b23;
	case 23333ULL: goto x86_l_5b25;
	case 23338ULL: goto x86_l_5b2a;
	case 23342ULL: goto x86_l_5b2e;
	case 23347ULL: goto x86_l_5b33;
	case 23352ULL: goto x86_l_5b38;
	case 23357ULL: goto x86_l_5b3d;
	case 23360ULL: goto x86_l_5b40;
	case 23362ULL: goto x86_l_5b42;
	case 23367ULL: goto x86_l_5b47;
	case 23371ULL: goto x86_l_5b4b;
	case 23375ULL: goto x86_l_5b4f;
	case 23380ULL: goto x86_l_5b54;
	case 23385ULL: goto x86_l_5b59;
	case 23390ULL: goto x86_l_5b5e;
	case 23392ULL: goto x86_l_5b60;
	case 23396ULL: goto x86_l_5b64;
	case 23399ULL: goto x86_l_5b67;
	case 23401ULL: goto x86_l_5b69;
	case 23406ULL: goto x86_l_5b6e;
	case 23409ULL: goto x86_l_5b71;
	case 23411ULL: goto x86_l_5b73;
	case 23415ULL: goto x86_l_5b77;
	case 23420ULL: goto x86_l_5b7c;
	case 23425ULL: goto x86_l_5b81;
	case 23430ULL: goto x86_l_5b86;
	case 23432ULL: goto x86_l_5b88;
	case 23436ULL: goto x86_l_5b8c;
	case 23438ULL: goto x86_l_5b8e;
	case 23444ULL: goto x86_l_5b94;
	case 23446ULL: goto x86_l_5b96;
	case 23448ULL: goto x86_l_5b98;
	case 23454ULL: goto x86_l_5b9e;
	case 23459ULL: goto x86_l_5ba3;
	case 23465ULL: goto x86_l_5ba9;
	case 23468ULL: goto x86_l_5bac;
	case 23473ULL: goto x86_l_5bb1;
	case 23475ULL: goto x86_l_5bb3;
	case 23478ULL: goto x86_l_5bb6;
	case 23484ULL: goto x86_l_5bbc;
	case 23487ULL: goto x86_l_5bbf;
	case 23493ULL: goto x86_l_5bc5;
	case 23498ULL: goto x86_l_5bca;
	case 23500ULL: goto x86_l_5bcc;
	case 23504ULL: goto x86_l_5bd0;
	case 23506ULL: goto x86_l_5bd2;
	case 23509ULL: goto x86_l_5bd5;
	case 23515ULL: goto x86_l_5bdb;
	case 23520ULL: goto x86_l_5be0;
	case 23525ULL: goto x86_l_5be5;
	case 23531ULL: goto x86_l_5beb;
	case 23536ULL: goto x86_l_5bf0;
	case 23541ULL: goto x86_l_5bf5;
	case 23545ULL: goto x86_l_5bf9;
	case 23548ULL: goto x86_l_5bfc;
	case 23553ULL: goto x86_l_5c01;
	case 23555ULL: goto x86_l_5c03;
	case 23560ULL: goto x86_l_5c08;
	case 23565ULL: goto x86_l_5c0d;
	case 23570ULL: goto x86_l_5c12;
	case 23575ULL: goto x86_l_5c17;
	case 23577ULL: goto x86_l_5c19;
	case 23582ULL: goto x86_l_5c1e;
	case 23587ULL: goto x86_l_5c23;
	case 23592ULL: goto x86_l_5c28;
	case 23597ULL: goto x86_l_5c2d;
	case 23599ULL: goto x86_l_5c2f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_558c:
	/* 0x558c: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5590:
	/* 0x5590: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_5597:
	/* 0x5597: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_559a:
	/* 0x559a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_559f:
	/* 0x559f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55a1:
	/* 0x55a1: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55a5:
	/* 0x55a5: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_55ad:
	/* 0x55ad: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_55b0:
	/* 0x55b0: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_55b8:
	/* 0x55b8: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_55c1:
	/* 0x55c1: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_55c6:
	/* 0x55c6: lea    rdx,[rax+0x118] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_55cd:
	/* 0x55cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_55d2:
	/* 0x55d2: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55d7:
	/* 0x55d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55dc:
	/* 0x55dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55de:
	/* 0x55de: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_55e0:
	/* 0x55e0: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_55e6:
	/* 0x55e6: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_55ec:
	/* 0x55ec: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_55ef:
	/* 0x55ef: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_55f4:
	/* 0x55f4: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55f9:
	/* 0x55f9: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_55ff:
	/* 0x55ff: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5604:
	/* 0x5604: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_560c:
	/* 0x560c: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_5610:
	/* 0x5610: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5617:
	/* 0x5617: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_561c:
	/* 0x561c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5621:
	/* 0x5621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5623:
	/* 0x5623: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5626:
	/* 0x5626: mov    cl,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_5628:
	/* 0x5628: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_562a:
	/* 0x562a: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_5630:
	/* 0x5630: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5633:
	/* 0x5633: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_5638:
	/* 0x5638: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_563d:
	/* 0x563d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5643:
	/* 0x5643: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5648:
	/* 0x5648: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5650:
	/* 0x5650: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5654:
	/* 0x5654: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_565b:
	/* 0x565b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_565e:
	/* 0x565e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5663:
	/* 0x5663: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5665:
	/* 0x5665: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5669:
	/* 0x5669: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5671:
	/* 0x5671: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5674:
	/* 0x5674: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_567c:
	/* 0x567c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5685:
	/* 0x5685: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_568a:
	/* 0x568a: lea    rdx,[rax+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_5691:
	/* 0x5691: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5696:
	/* 0x5696: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_569b:
	/* 0x569b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_56a0:
	/* 0x56a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56a2:
	/* 0x56a2: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_56a4:
	/* 0x56a4: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_56aa:
	/* 0x56aa: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_56b0:
	/* 0x56b0: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56b3:
	/* 0x56b3: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_56b8:
	/* 0x56b8: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56bd:
	/* 0x56bd: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_56c3:
	/* 0x56c3: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_56c8:
	/* 0x56c8: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_56d0:
	/* 0x56d0: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_56d4:
	/* 0x56d4: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_56db:
	/* 0x56db: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56e0:
	/* 0x56e0: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_56e5:
	/* 0x56e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e7:
	/* 0x56e7: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56ea:
	/* 0x56ea: mov    cl,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 36ULL);
x86_l_56ec:
	/* 0x56ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56ee:
	/* 0x56ee: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_56f4:
	/* 0x56f4: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_56f7:
	/* 0x56f7: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_56fc:
	/* 0x56fc: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5701:
	/* 0x5701: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5707:
	/* 0x5707: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_570c:
	/* 0x570c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5714:
	/* 0x5714: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5718:
	/* 0x5718: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_571f:
	/* 0x571f: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5722:
	/* 0x5722: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5727:
	/* 0x5727: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5729:
	/* 0x5729: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_572d:
	/* 0x572d: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5735:
	/* 0x5735: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5738:
	/* 0x5738: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5740:
	/* 0x5740: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5749:
	/* 0x5749: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_574e:
	/* 0x574e: add    rdx,0x128 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 296ULL);
x86_l_5755:
	/* 0x5755: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_575a:
	/* 0x575a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_575f:
	/* 0x575f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5764:
	/* 0x5764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5766:
	/* 0x5766: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_5768:
	/* 0x5768: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_576e:
	/* 0x576e: je     5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24164ULL;
	}
x86_l_5774:
	/* 0x5774: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5777:
	/* 0x5777: cmp    eax,0x6cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27900ULL);
x86_l_577c:
	/* 0x577c: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5781:
	/* 0x5781: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5787:
	/* 0x5787: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_578c:
	/* 0x578c: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5794:
	/* 0x5794: lea    rdi,[rcx+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_5798:
	/* 0x5798: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_579f:
	/* 0x579f: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57a4:
	/* 0x57a4: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_57a9:
	/* 0x57a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57ab:
	/* 0x57ab: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57ae:
	/* 0x57ae: mov    cl,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 37ULL);
x86_l_57b0:
	/* 0x57b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57b2:
	/* 0x57b2: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_57b8:
	/* 0x57b8: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_57bb:
	/* 0x57bb: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_57c0:
	/* 0x57c0: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_57c5:
	/* 0x57c5: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_57cb:
	/* 0x57cb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_57d0:
	/* 0x57d0: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_57d8:
	/* 0x57d8: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_57dc:
	/* 0x57dc: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_57e3:
	/* 0x57e3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_57e6:
	/* 0x57e6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_57eb:
	/* 0x57eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57ed:
	/* 0x57ed: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_57f1:
	/* 0x57f1: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_57f9:
	/* 0x57f9: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_57fc:
	/* 0x57fc: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_5804:
	/* 0x5804: mov    DWORD PTR [rsp+0x20],0x2e2e2e */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137441979950ULL);
x86_l_580c:
	/* 0x580c: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_580f:
	/* 0x580f: cmp    eax,0x6cfd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27901ULL);
x86_l_5814:
	/* 0x5814: jb     581b <trace_security_bprm_check+0x581b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_581b;
	}
x86_l_5816:
	/* 0x5816: mov    WORD PTR [rbx],0x6cfc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 27900ULL);
x86_l_581b:
	/* 0x581b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_5820:
	/* 0x5820: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5825:
	/* 0x5825: movzx  ecx,WORD PTR [rdx+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_582c:
	/* 0x582c: lea    rdi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_5830:
	/* 0x5830: add    rdi,0x8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 141ULL);
x86_l_5837:
	/* 0x5837: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_583c:
	/* 0x583c: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_5841:
	/* 0x5841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5843:
	/* 0x5843: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5846:
	/* 0x5846: mov    cl,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 38ULL);
x86_l_5848:
	/* 0x5848: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_584a:
	/* 0x584a: jle    5e64 <trace_security_bprm_check+0x5e64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 24164ULL;
	}
x86_l_5850:
	/* 0x5850: movzx  eax,WORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5853:
	/* 0x5853: cmp    eax,0x7cfc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 31996ULL);
x86_l_5858:
	/* 0x5858: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_585d:
	/* 0x585d: ja     19b0 <trace_security_bprm_check+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6576ULL;
	}
x86_l_5863:
	/* 0x5863: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5868:
	/* 0x5868: movzx  ecx,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32138ULL);
x86_l_5870:
	/* 0x5870: lea    rdi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5874:
	/* 0x5874: add    rdi,0x89 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 137ULL);
x86_l_587b:
	/* 0x587b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_587e:
	/* 0x587e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_5883:
	/* 0x5883: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5885:
	/* 0x5885: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5889:
	/* 0x5889: add    ax,WORD PTR [r15+0x7d8a] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32138ULL);
x86_l_5891:
	/* 0x5891: add    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_5894:
	/* 0x5894: mov    WORD PTR [r15+0x7d8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32138ULL);
x86_l_589c:
	/* 0x589c: mov    cl,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 39ULL);
x86_l_589e:
	/* 0x589e: jmp    19b0 <trace_security_bprm_check+0x19b0> */
	return 6576ULL;
x86_l_58a3:
	/* 0x58a3: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58a8:
	/* 0x58a8: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_58ad:
	/* 0x58ad: je     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5733ULL;
	}
x86_l_58b3:
	/* 0x58b3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58b8:
	/* 0x58b8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58bd:
	/* 0x58bd: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_58c1:
	/* 0x58c1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_58c4:
	/* 0x58c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58c9:
	/* 0x58c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58cb:
	/* 0x58cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58d0:
	/* 0x58d0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58d5:
	/* 0x58d5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58da:
	/* 0x58da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58df:
	/* 0x58df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58e1:
	/* 0x58e1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_58e6:
	/* 0x58e6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58eb:
	/* 0x58eb: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_58f0:
	/* 0x58f0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58f5:
	/* 0x58f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f7:
	/* 0x58f7: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58fc:
	/* 0x58fc: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5900:
	/* 0x5900: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5905:
	/* 0x5905: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_590a:
	/* 0x590a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_590f:
	/* 0x590f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5912:
	/* 0x5912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5914:
	/* 0x5914: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5919:
	/* 0x5919: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_591d:
	/* 0x591d: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5921:
	/* 0x5921: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5926:
	/* 0x5926: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_592b:
	/* 0x592b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5930:
	/* 0x5930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5932:
	/* 0x5932: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5936:
	/* 0x5936: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5939:
	/* 0x5939: je     598a <trace_security_bprm_check+0x598a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_598a;
	}
x86_l_593b:
	/* 0x593b: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5940:
	/* 0x5940: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5943:
	/* 0x5943: je     598a <trace_security_bprm_check+0x598a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_598a;
	}
x86_l_5945:
	/* 0x5945: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5949:
	/* 0x5949: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_594e:
	/* 0x594e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5953:
	/* 0x5953: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5958:
	/* 0x5958: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_595a:
	/* 0x595a: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_595e:
	/* 0x595e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5960:
	/* 0x5960: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5966:
	/* 0x5966: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5968:
	/* 0x5968: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_596a:
	/* 0x596a: jae    59f2 <trace_security_bprm_check+0x59f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_59f2;
	}
x86_l_5970:
	/* 0x5970: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_5972:
	/* 0x5972: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_5974:
	/* 0x5974: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5979:
	/* 0x5979: mov    BYTE PTR [rbp+rax*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_597e:
	/* 0x597e: mov    BYTE PTR [rbp+0x3fff],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 70364449210368ULL);
x86_l_5985:
	/* 0x5985: jmp    16a0 <trace_security_bprm_check+0x16a0> */
	return 5792ULL;
x86_l_598a:
	/* 0x598a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_598d:
	/* 0x598d: jne    1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5733ULL;
	}
x86_l_5993:
	/* 0x5993: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5998:
	/* 0x5998: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_599d:
	/* 0x599d: je     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5733ULL;
	}
x86_l_59a3:
	/* 0x59a3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59a8:
	/* 0x59a8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59ad:
	/* 0x59ad: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_59b1:
	/* 0x59b1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_59b4:
	/* 0x59b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59b9:
	/* 0x59b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59bb:
	/* 0x59bb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59c0:
	/* 0x59c0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59c5:
	/* 0x59c5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59ca:
	/* 0x59ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59cf:
	/* 0x59cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59d1:
	/* 0x59d1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_59d6:
	/* 0x59d6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59db:
	/* 0x59db: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_59e0:
	/* 0x59e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_59e5:
	/* 0x59e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_59e7:
	/* 0x59e7: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59ec:
	/* 0x59ec: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_59f0:
	/* 0x59f0: jmp    5a24 <trace_security_bprm_check+0x5a24> */
	goto x86_l_5a24;
x86_l_59f2:
	/* 0x59f2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59f7:
	/* 0x59f7: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_59fd:
	/* 0x59fd: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5a00:
	/* 0x5a00: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5a05:
	/* 0x5a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a07:
	/* 0x5a07: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5a0a:
	/* 0x5a0a: jl     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5733ULL;
	}
x86_l_5a10:
	/* 0x5a10: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5a13:
	/* 0x5a13: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5a19:
	/* 0x5a19: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5a1e:
	/* 0x5a1e: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5a20:
	/* 0x5a20: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a24:
	/* 0x5a24: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a29:
	/* 0x5a29: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a2e:
	/* 0x5a2e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a33:
	/* 0x5a33: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5a36:
	/* 0x5a36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a38:
	/* 0x5a38: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a3d:
	/* 0x5a3d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a41:
	/* 0x5a41: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5a45:
	/* 0x5a45: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a4a:
	/* 0x5a4a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a4f:
	/* 0x5a4f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5a54:
	/* 0x5a54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a56:
	/* 0x5a56: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a5a:
	/* 0x5a5a: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5a5d:
	/* 0x5a5d: je     5ac8 <trace_security_bprm_check+0x5ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ac8;
	}
x86_l_5a5f:
	/* 0x5a5f: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a64:
	/* 0x5a64: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5a67:
	/* 0x5a67: je     5ac8 <trace_security_bprm_check+0x5ac8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ac8;
	}
x86_l_5a69:
	/* 0x5a69: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5a6d:
	/* 0x5a6d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5a72:
	/* 0x5a72: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a77:
	/* 0x5a77: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5a7c:
	/* 0x5a7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a7e:
	/* 0x5a7e: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5a82:
	/* 0x5a82: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5a84:
	/* 0x5a84: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5a8a:
	/* 0x5a8a: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5a8c:
	/* 0x5a8c: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5a8e:
	/* 0x5a8e: jb     5970 <trace_security_bprm_check+0x5970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5970;
	}
x86_l_5a94:
	/* 0x5a94: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a99:
	/* 0x5a99: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5a9f:
	/* 0x5a9f: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5aa2:
	/* 0x5aa2: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5aa7:
	/* 0x5aa7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5aa9:
	/* 0x5aa9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5aac:
	/* 0x5aac: jl     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5733ULL;
	}
x86_l_5ab2:
	/* 0x5ab2: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5ab5:
	/* 0x5ab5: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5abb:
	/* 0x5abb: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5ac0:
	/* 0x5ac0: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5ac2:
	/* 0x5ac2: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ac6:
	/* 0x5ac6: jmp    5b2e <trace_security_bprm_check+0x5b2e> */
	goto x86_l_5b2e;
x86_l_5ac8:
	/* 0x5ac8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5acb:
	/* 0x5acb: jne    1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5733ULL;
	}
x86_l_5ad1:
	/* 0x5ad1: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ad6:
	/* 0x5ad6: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_5adb:
	/* 0x5adb: je     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5733ULL;
	}
x86_l_5ae1:
	/* 0x5ae1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ae6:
	/* 0x5ae6: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5aeb:
	/* 0x5aeb: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5aef:
	/* 0x5aef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5af2:
	/* 0x5af2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5af7:
	/* 0x5af7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5af9:
	/* 0x5af9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5afe:
	/* 0x5afe: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b03:
	/* 0x5b03: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b08:
	/* 0x5b08: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b0d:
	/* 0x5b0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b0f:
	/* 0x5b0f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b14:
	/* 0x5b14: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b19:
	/* 0x5b19: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5b1e:
	/* 0x5b1e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b23:
	/* 0x5b23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b25:
	/* 0x5b25: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b2a:
	/* 0x5b2a: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b2e:
	/* 0x5b2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b33:
	/* 0x5b33: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b38:
	/* 0x5b38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b3d:
	/* 0x5b3d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5b40:
	/* 0x5b40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b42:
	/* 0x5b42: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b47:
	/* 0x5b47: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b4b:
	/* 0x5b4b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5b4f:
	/* 0x5b4f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b54:
	/* 0x5b54: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b59:
	/* 0x5b59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b5e:
	/* 0x5b5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b60:
	/* 0x5b60: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b64:
	/* 0x5b64: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5b67:
	/* 0x5b67: je     5bd2 <trace_security_bprm_check+0x5bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bd2;
	}
x86_l_5b69:
	/* 0x5b69: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b6e:
	/* 0x5b6e: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5b71:
	/* 0x5b71: je     5bd2 <trace_security_bprm_check+0x5bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bd2;
	}
x86_l_5b73:
	/* 0x5b73: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5b77:
	/* 0x5b77: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5b7c:
	/* 0x5b7c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b81:
	/* 0x5b81: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5b86:
	/* 0x5b86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b88:
	/* 0x5b88: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5b8c:
	/* 0x5b8c: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5b8e:
	/* 0x5b8e: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b94:
	/* 0x5b94: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5b96:
	/* 0x5b96: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5b98:
	/* 0x5b98: jb     5970 <trace_security_bprm_check+0x5970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5970;
	}
x86_l_5b9e:
	/* 0x5b9e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5ba3:
	/* 0x5ba3: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5ba9:
	/* 0x5ba9: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5bac:
	/* 0x5bac: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5bb1:
	/* 0x5bb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bb3:
	/* 0x5bb3: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5bb6:
	/* 0x5bb6: jl     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 5733ULL;
	}
x86_l_5bbc:
	/* 0x5bbc: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5bbf:
	/* 0x5bbf: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5bc5:
	/* 0x5bc5: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5bca:
	/* 0x5bca: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5bcc:
	/* 0x5bcc: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bd0:
	/* 0x5bd0: jmp    5c38 <trace_security_bprm_check+0x5c38> */
	return 23608ULL;
x86_l_5bd2:
	/* 0x5bd2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5bd5:
	/* 0x5bd5: jne    1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5733ULL;
	}
x86_l_5bdb:
	/* 0x5bdb: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5be0:
	/* 0x5be0: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_5be5:
	/* 0x5be5: je     1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5733ULL;
	}
x86_l_5beb:
	/* 0x5beb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5bf0:
	/* 0x5bf0: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5bf5:
	/* 0x5bf5: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5bf9:
	/* 0x5bf9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5bfc:
	/* 0x5bfc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c01:
	/* 0x5c01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c03:
	/* 0x5c03: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c08:
	/* 0x5c08: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c0d:
	/* 0x5c0d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c12:
	/* 0x5c12: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c17:
	/* 0x5c17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c19:
	/* 0x5c19: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c1e:
	/* 0x5c1e: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c23:
	/* 0x5c23: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5c28:
	/* 0x5c28: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c2d:
	/* 0x5c2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c2f:
	/* 0x5c2f: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
	return 23604ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_13(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 23604ULL: goto x86_l_5c34;
	case 23608ULL: goto x86_l_5c38;
	case 23613ULL: goto x86_l_5c3d;
	case 23618ULL: goto x86_l_5c42;
	case 23623ULL: goto x86_l_5c47;
	case 23626ULL: goto x86_l_5c4a;
	case 23628ULL: goto x86_l_5c4c;
	case 23633ULL: goto x86_l_5c51;
	case 23637ULL: goto x86_l_5c55;
	case 23641ULL: goto x86_l_5c59;
	case 23646ULL: goto x86_l_5c5e;
	case 23651ULL: goto x86_l_5c63;
	case 23656ULL: goto x86_l_5c68;
	case 23658ULL: goto x86_l_5c6a;
	case 23662ULL: goto x86_l_5c6e;
	case 23665ULL: goto x86_l_5c71;
	case 23671ULL: goto x86_l_5c77;
	case 23676ULL: goto x86_l_5c7c;
	case 23679ULL: goto x86_l_5c7f;
	case 23685ULL: goto x86_l_5c85;
	case 23689ULL: goto x86_l_5c89;
	case 23694ULL: goto x86_l_5c8e;
	case 23699ULL: goto x86_l_5c93;
	case 23704ULL: goto x86_l_5c98;
	case 23706ULL: goto x86_l_5c9a;
	case 23710ULL: goto x86_l_5c9e;
	case 23712ULL: goto x86_l_5ca0;
	case 23718ULL: goto x86_l_5ca6;
	case 23720ULL: goto x86_l_5ca8;
	case 23722ULL: goto x86_l_5caa;
	case 23728ULL: goto x86_l_5cb0;
	case 23733ULL: goto x86_l_5cb5;
	case 23739ULL: goto x86_l_5cbb;
	case 23742ULL: goto x86_l_5cbe;
	case 23747ULL: goto x86_l_5cc3;
	case 23749ULL: goto x86_l_5cc5;
	case 23752ULL: goto x86_l_5cc8;
	case 23758ULL: goto x86_l_5cce;
	case 23761ULL: goto x86_l_5cd1;
	case 23767ULL: goto x86_l_5cd7;
	case 23772ULL: goto x86_l_5cdc;
	case 23774ULL: goto x86_l_5cde;
	case 23778ULL: goto x86_l_5ce2;
	case 23783ULL: goto x86_l_5ce7;
	case 23790ULL: goto x86_l_5cee;
	case 23793ULL: goto x86_l_5cf1;
	case 23797ULL: goto x86_l_5cf5;
	case 23802ULL: goto x86_l_5cfa;
	case 23807ULL: goto x86_l_5cff;
	case 23809ULL: goto x86_l_5d01;
	case 23812ULL: goto x86_l_5d04;
	case 23814ULL: goto x86_l_5d06;
	case 23820ULL: goto x86_l_5d0c;
	case 23824ULL: goto x86_l_5d10;
	case 23829ULL: goto x86_l_5d15;
	case 23831ULL: goto x86_l_5d17;
	case 23836ULL: goto x86_l_5d1c;
	case 23839ULL: goto x86_l_5d1f;
	case 23845ULL: goto x86_l_5d25;
	case 23850ULL: goto x86_l_5d2a;
	case 23855ULL: goto x86_l_5d2f;
	case 23861ULL: goto x86_l_5d35;
	case 23866ULL: goto x86_l_5d3a;
	case 23871ULL: goto x86_l_5d3f;
	case 23875ULL: goto x86_l_5d43;
	case 23878ULL: goto x86_l_5d46;
	case 23883ULL: goto x86_l_5d4b;
	case 23885ULL: goto x86_l_5d4d;
	case 23890ULL: goto x86_l_5d52;
	case 23895ULL: goto x86_l_5d57;
	case 23900ULL: goto x86_l_5d5c;
	case 23905ULL: goto x86_l_5d61;
	case 23907ULL: goto x86_l_5d63;
	case 23912ULL: goto x86_l_5d68;
	case 23917ULL: goto x86_l_5d6d;
	case 23922ULL: goto x86_l_5d72;
	case 23927ULL: goto x86_l_5d77;
	case 23929ULL: goto x86_l_5d79;
	case 23934ULL: goto x86_l_5d7e;
	case 23938ULL: goto x86_l_5d82;
	case 23943ULL: goto x86_l_5d87;
	case 23948ULL: goto x86_l_5d8c;
	case 23953ULL: goto x86_l_5d91;
	case 23956ULL: goto x86_l_5d94;
	case 23958ULL: goto x86_l_5d96;
	case 23963ULL: goto x86_l_5d9b;
	case 23967ULL: goto x86_l_5d9f;
	case 23971ULL: goto x86_l_5da3;
	case 23976ULL: goto x86_l_5da8;
	case 23981ULL: goto x86_l_5dad;
	case 23986ULL: goto x86_l_5db2;
	case 23988ULL: goto x86_l_5db4;
	case 23992ULL: goto x86_l_5db8;
	case 23995ULL: goto x86_l_5dbb;
	case 23997ULL: goto x86_l_5dbd;
	case 24002ULL: goto x86_l_5dc2;
	case 24005ULL: goto x86_l_5dc5;
	case 24007ULL: goto x86_l_5dc7;
	case 24011ULL: goto x86_l_5dcb;
	case 24016ULL: goto x86_l_5dd0;
	case 24021ULL: goto x86_l_5dd5;
	case 24026ULL: goto x86_l_5dda;
	case 24028ULL: goto x86_l_5ddc;
	case 24032ULL: goto x86_l_5de0;
	case 24034ULL: goto x86_l_5de2;
	case 24040ULL: goto x86_l_5de8;
	case 24042ULL: goto x86_l_5dea;
	case 24044ULL: goto x86_l_5dec;
	case 24050ULL: goto x86_l_5df2;
	case 24055ULL: goto x86_l_5df7;
	case 24060ULL: goto x86_l_5dfc;
	case 24063ULL: goto x86_l_5dff;
	case 24069ULL: goto x86_l_5e05;
	case 24074ULL: goto x86_l_5e0a;
	case 24079ULL: goto x86_l_5e0f;
	case 24085ULL: goto x86_l_5e15;
	case 24090ULL: goto x86_l_5e1a;
	case 24095ULL: goto x86_l_5e1f;
	case 24099ULL: goto x86_l_5e23;
	case 24102ULL: goto x86_l_5e26;
	case 24107ULL: goto x86_l_5e2b;
	case 24109ULL: goto x86_l_5e2d;
	case 24114ULL: goto x86_l_5e32;
	case 24119ULL: goto x86_l_5e37;
	case 24124ULL: goto x86_l_5e3c;
	case 24129ULL: goto x86_l_5e41;
	case 24131ULL: goto x86_l_5e43;
	case 24136ULL: goto x86_l_5e48;
	case 24141ULL: goto x86_l_5e4d;
	case 24146ULL: goto x86_l_5e52;
	case 24151ULL: goto x86_l_5e57;
	case 24153ULL: goto x86_l_5e59;
	case 24158ULL: goto x86_l_5e5e;
	case 24162ULL: goto x86_l_5e62;
	case 24164ULL: goto x86_l_5e64;
	case 24169ULL: goto x86_l_5e69;
	case 24174ULL: goto x86_l_5e6e;
	case 24179ULL: goto x86_l_5e73;
	case 24184ULL: goto x86_l_5e78;
	case 24189ULL: goto x86_l_5e7d;
	case 24194ULL: goto x86_l_5e82;
	case 24200ULL: goto x86_l_5e88;
	case 24203ULL: goto x86_l_5e8b;
	case 24208ULL: goto x86_l_5e90;
	case 24210ULL: goto x86_l_5e92;
	case 24213ULL: goto x86_l_5e95;
	case 24219ULL: goto x86_l_5e9b;
	case 24222ULL: goto x86_l_5e9e;
	case 24228ULL: goto x86_l_5ea4;
	case 24233ULL: goto x86_l_5ea9;
	case 24235ULL: goto x86_l_5eab;
	case 24239ULL: goto x86_l_5eaf;
	case 24244ULL: goto x86_l_5eb4;
	case 24249ULL: goto x86_l_5eb9;
	case 24254ULL: goto x86_l_5ebe;
	case 24257ULL: goto x86_l_5ec1;
	case 24259ULL: goto x86_l_5ec3;
	case 24264ULL: goto x86_l_5ec8;
	case 24268ULL: goto x86_l_5ecc;
	case 24272ULL: goto x86_l_5ed0;
	case 24277ULL: goto x86_l_5ed5;
	case 24282ULL: goto x86_l_5eda;
	case 24287ULL: goto x86_l_5edf;
	case 24289ULL: goto x86_l_5ee1;
	case 24293ULL: goto x86_l_5ee5;
	case 24296ULL: goto x86_l_5ee8;
	case 24298ULL: goto x86_l_5eea;
	case 24303ULL: goto x86_l_5eef;
	case 24306ULL: goto x86_l_5ef2;
	case 24308ULL: goto x86_l_5ef4;
	case 24312ULL: goto x86_l_5ef8;
	case 24317ULL: goto x86_l_5efd;
	case 24322ULL: goto x86_l_5f02;
	case 24327ULL: goto x86_l_5f07;
	case 24329ULL: goto x86_l_5f09;
	case 24333ULL: goto x86_l_5f0d;
	case 24335ULL: goto x86_l_5f0f;
	case 24341ULL: goto x86_l_5f15;
	case 24343ULL: goto x86_l_5f17;
	case 24345ULL: goto x86_l_5f19;
	case 24351ULL: goto x86_l_5f1f;
	case 24356ULL: goto x86_l_5f24;
	case 24362ULL: goto x86_l_5f2a;
	case 24365ULL: goto x86_l_5f2d;
	case 24370ULL: goto x86_l_5f32;
	case 24372ULL: goto x86_l_5f34;
	case 24375ULL: goto x86_l_5f37;
	case 24377ULL: goto x86_l_5f39;
	case 24380ULL: goto x86_l_5f3c;
	case 24386ULL: goto x86_l_5f42;
	case 24391ULL: goto x86_l_5f47;
	case 24393ULL: goto x86_l_5f49;
	case 24397ULL: goto x86_l_5f4d;
	case 24399ULL: goto x86_l_5f4f;
	case 24402ULL: goto x86_l_5f52;
	case 24404ULL: goto x86_l_5f54;
	case 24409ULL: goto x86_l_5f59;
	case 24414ULL: goto x86_l_5f5e;
	case 24419ULL: goto x86_l_5f63;
	case 24424ULL: goto x86_l_5f68;
	case 24426ULL: goto x86_l_5f6a;
	case 24431ULL: goto x86_l_5f6f;
	case 24436ULL: goto x86_l_5f74;
	case 24440ULL: goto x86_l_5f78;
	case 24443ULL: goto x86_l_5f7b;
	case 24448ULL: goto x86_l_5f80;
	case 24450ULL: goto x86_l_5f82;
	case 24455ULL: goto x86_l_5f87;
	case 24460ULL: goto x86_l_5f8c;
	case 24465ULL: goto x86_l_5f91;
	case 24470ULL: goto x86_l_5f96;
	case 24472ULL: goto x86_l_5f98;
	case 24477ULL: goto x86_l_5f9d;
	case 24482ULL: goto x86_l_5fa2;
	case 24487ULL: goto x86_l_5fa7;
	case 24492ULL: goto x86_l_5fac;
	case 24494ULL: goto x86_l_5fae;
	case 24499ULL: goto x86_l_5fb3;
	case 24503ULL: goto x86_l_5fb7;
	case 24508ULL: goto x86_l_5fbc;
	case 24513ULL: goto x86_l_5fc1;
	case 24518ULL: goto x86_l_5fc6;
	case 24521ULL: goto x86_l_5fc9;
	case 24523ULL: goto x86_l_5fcb;
	case 24528ULL: goto x86_l_5fd0;
	case 24532ULL: goto x86_l_5fd4;
	case 24536ULL: goto x86_l_5fd8;
	case 24541ULL: goto x86_l_5fdd;
	case 24546ULL: goto x86_l_5fe2;
	case 24551ULL: goto x86_l_5fe7;
	case 24553ULL: goto x86_l_5fe9;
	case 24557ULL: goto x86_l_5fed;
	case 24560ULL: goto x86_l_5ff0;
	case 24562ULL: goto x86_l_5ff2;
	case 24567ULL: goto x86_l_5ff7;
	case 24570ULL: goto x86_l_5ffa;
	case 24572ULL: goto x86_l_5ffc;
	case 24576ULL: goto x86_l_6000;
	case 24581ULL: goto x86_l_6005;
	case 24586ULL: goto x86_l_600a;
	case 24591ULL: goto x86_l_600f;
	case 24593ULL: goto x86_l_6011;
	case 24597ULL: goto x86_l_6015;
	case 24599ULL: goto x86_l_6017;
	case 24605ULL: goto x86_l_601d;
	case 24607ULL: goto x86_l_601f;
	case 24609ULL: goto x86_l_6021;
	case 24615ULL: goto x86_l_6027;
	case 24620ULL: goto x86_l_602c;
	case 24626ULL: goto x86_l_6032;
	case 24629ULL: goto x86_l_6035;
	case 24634ULL: goto x86_l_603a;
	case 24636ULL: goto x86_l_603c;
	case 24639ULL: goto x86_l_603f;
	case 24645ULL: goto x86_l_6045;
	case 24648ULL: goto x86_l_6048;
	case 24654ULL: goto x86_l_604e;
	case 24659ULL: goto x86_l_6053;
	case 24661ULL: goto x86_l_6055;
	case 24665ULL: goto x86_l_6059;
	case 24667ULL: goto x86_l_605b;
	case 24670ULL: goto x86_l_605e;
	case 24676ULL: goto x86_l_6064;
	case 24681ULL: goto x86_l_6069;
	case 24686ULL: goto x86_l_606e;
	case 24692ULL: goto x86_l_6074;
	case 24697ULL: goto x86_l_6079;
	case 24702ULL: goto x86_l_607e;
	case 24706ULL: goto x86_l_6082;
	case 24709ULL: goto x86_l_6085;
	case 24714ULL: goto x86_l_608a;
	case 24716ULL: goto x86_l_608c;
	case 24721ULL: goto x86_l_6091;
	case 24726ULL: goto x86_l_6096;
	case 24731ULL: goto x86_l_609b;
	case 24736ULL: goto x86_l_60a0;
	case 24738ULL: goto x86_l_60a2;
	case 24743ULL: goto x86_l_60a7;
	case 24748ULL: goto x86_l_60ac;
	case 24753ULL: goto x86_l_60b1;
	case 24758ULL: goto x86_l_60b6;
	case 24760ULL: goto x86_l_60b8;
	case 24765ULL: goto x86_l_60bd;
	case 24769ULL: goto x86_l_60c1;
	case 24774ULL: goto x86_l_60c6;
	case 24779ULL: goto x86_l_60cb;
	case 24784ULL: goto x86_l_60d0;
	case 24787ULL: goto x86_l_60d3;
	case 24789ULL: goto x86_l_60d5;
	case 24794ULL: goto x86_l_60da;
	case 24798ULL: goto x86_l_60de;
	case 24802ULL: goto x86_l_60e2;
	case 24807ULL: goto x86_l_60e7;
	case 24812ULL: goto x86_l_60ec;
	case 24817ULL: goto x86_l_60f1;
	case 24819ULL: goto x86_l_60f3;
	case 24823ULL: goto x86_l_60f7;
	case 24826ULL: goto x86_l_60fa;
	case 24828ULL: goto x86_l_60fc;
	case 24833ULL: goto x86_l_6101;
	case 24836ULL: goto x86_l_6104;
	case 24838ULL: goto x86_l_6106;
	case 24842ULL: goto x86_l_610a;
	case 24847ULL: goto x86_l_610f;
	case 24852ULL: goto x86_l_6114;
	case 24857ULL: goto x86_l_6119;
	case 24859ULL: goto x86_l_611b;
	case 24863ULL: goto x86_l_611f;
	case 24865ULL: goto x86_l_6121;
	case 24871ULL: goto x86_l_6127;
	case 24873ULL: goto x86_l_6129;
	case 24875ULL: goto x86_l_612b;
	case 24881ULL: goto x86_l_6131;
	case 24886ULL: goto x86_l_6136;
	case 24892ULL: goto x86_l_613c;
	case 24895ULL: goto x86_l_613f;
	case 24900ULL: goto x86_l_6144;
	case 24902ULL: goto x86_l_6146;
	case 24905ULL: goto x86_l_6149;
	case 24911ULL: goto x86_l_614f;
	case 24914ULL: goto x86_l_6152;
	case 24920ULL: goto x86_l_6158;
	case 24925ULL: goto x86_l_615d;
	case 24927ULL: goto x86_l_615f;
	case 24931ULL: goto x86_l_6163;
	case 24933ULL: goto x86_l_6165;
	case 24936ULL: goto x86_l_6168;
	case 24942ULL: goto x86_l_616e;
	case 24947ULL: goto x86_l_6173;
	case 24952ULL: goto x86_l_6178;
	case 24958ULL: goto x86_l_617e;
	case 24963ULL: goto x86_l_6183;
	case 24968ULL: goto x86_l_6188;
	case 24972ULL: goto x86_l_618c;
	case 24975ULL: goto x86_l_618f;
	case 24980ULL: goto x86_l_6194;
	case 24982ULL: goto x86_l_6196;
	case 24987ULL: goto x86_l_619b;
	case 24992ULL: goto x86_l_61a0;
	case 24997ULL: goto x86_l_61a5;
	case 25002ULL: goto x86_l_61aa;
	case 25004ULL: goto x86_l_61ac;
	case 25009ULL: goto x86_l_61b1;
	case 25014ULL: goto x86_l_61b6;
	case 25019ULL: goto x86_l_61bb;
	case 25024ULL: goto x86_l_61c0;
	case 25026ULL: goto x86_l_61c2;
	case 25031ULL: goto x86_l_61c7;
	case 25035ULL: goto x86_l_61cb;
	case 25040ULL: goto x86_l_61d0;
	case 25045ULL: goto x86_l_61d5;
	case 25050ULL: goto x86_l_61da;
	case 25053ULL: goto x86_l_61dd;
	case 25055ULL: goto x86_l_61df;
	case 25060ULL: goto x86_l_61e4;
	case 25064ULL: goto x86_l_61e8;
	case 25068ULL: goto x86_l_61ec;
	case 25073ULL: goto x86_l_61f1;
	case 25078ULL: goto x86_l_61f6;
	case 25083ULL: goto x86_l_61fb;
	case 25085ULL: goto x86_l_61fd;
	case 25089ULL: goto x86_l_6201;
	case 25092ULL: goto x86_l_6204;
	case 25094ULL: goto x86_l_6206;
	case 25099ULL: goto x86_l_620b;
	case 25102ULL: goto x86_l_620e;
	case 25104ULL: goto x86_l_6210;
	case 25108ULL: goto x86_l_6214;
	case 25113ULL: goto x86_l_6219;
	case 25118ULL: goto x86_l_621e;
	case 25123ULL: goto x86_l_6223;
	case 25125ULL: goto x86_l_6225;
	case 25129ULL: goto x86_l_6229;
	case 25131ULL: goto x86_l_622b;
	case 25137ULL: goto x86_l_6231;
	case 25139ULL: goto x86_l_6233;
	case 25141ULL: goto x86_l_6235;
	case 25147ULL: goto x86_l_623b;
	case 25152ULL: goto x86_l_6240;
	case 25158ULL: goto x86_l_6246;
	case 25161ULL: goto x86_l_6249;
	case 25166ULL: goto x86_l_624e;
	case 25168ULL: goto x86_l_6250;
	case 25171ULL: goto x86_l_6253;
	default: return 0xffffffffffffffffULL;
	}
x86_l_5c34:
	/* 0x5c34: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c38:
	/* 0x5c38: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c3d:
	/* 0x5c3d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c42:
	/* 0x5c42: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c47:
	/* 0x5c47: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5c4a:
	/* 0x5c4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c4c:
	/* 0x5c4c: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c51:
	/* 0x5c51: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c55:
	/* 0x5c55: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5c59:
	/* 0x5c59: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c5e:
	/* 0x5c5e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c63:
	/* 0x5c63: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5c68:
	/* 0x5c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c6a:
	/* 0x5c6a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c6e:
	/* 0x5c6e: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5c71:
	/* 0x5c71: je     5d1c <trace_security_bprm_check+0x5d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1c;
	}
x86_l_5c77:
	/* 0x5c77: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c7c:
	/* 0x5c7c: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5c7f:
	/* 0x5c7f: je     5d1c <trace_security_bprm_check+0x5d1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1c;
	}
x86_l_5c85:
	/* 0x5c85: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5c89:
	/* 0x5c89: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5c8e:
	/* 0x5c8e: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c93:
	/* 0x5c93: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5c98:
	/* 0x5c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c9a:
	/* 0x5c9a: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5c9e:
	/* 0x5c9e: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5ca0:
	/* 0x5ca0: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5ca6:
	/* 0x5ca6: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5ca8:
	/* 0x5ca8: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5caa:
	/* 0x5caa: jb     5970 <trace_security_bprm_check+0x5970> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 22896ULL;
	}
x86_l_5cb0:
	/* 0x5cb0: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5cb5:
	/* 0x5cb5: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5cbb:
	/* 0x5cbb: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5cbe:
	/* 0x5cbe: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5cc3:
	/* 0x5cc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cc5:
	/* 0x5cc5: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5cc8:
	/* 0x5cc8: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_5f54;
	}
x86_l_5cce:
	/* 0x5cce: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5cd1:
	/* 0x5cd1: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5cd7:
	/* 0x5cd7: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5cdc:
	/* 0x5cdc: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5cde:
	/* 0x5cde: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ce2:
	/* 0x5ce2: jmp    5d82 <trace_security_bprm_check+0x5d82> */
	goto x86_l_5d82;
x86_l_5ce7:
	/* 0x5ce7: lea    rdi,[rbp+0x7e18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32280ULL);
x86_l_5cee:
	/* 0x5cee: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5cf1:
	/* 0x5cf1: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5cf5:
	/* 0x5cf5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5cfa:
	/* 0x5cfa: mov    esi,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_5cff:
	/* 0x5cff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d01:
	/* 0x5d01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d04:
	/* 0x5d04: jne    5d15 <trace_security_bprm_check+0x5d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5d15;
	}
x86_l_5d06:
	/* 0x5d06: movzx  eax,WORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_5d0c:
	/* 0x5d0c: mov    WORD PTR [rbp+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_5d10:
	/* 0x5d10: jmp    ad4 <trace_security_bprm_check+0xad4> */
	return 2772ULL;
x86_l_5d15:
	/* 0x5d15: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d17:
	/* 0x5d17: jmp    1e20 <trace_security_bprm_check+0x1e20> */
	return 7712ULL;
x86_l_5d1c:
	/* 0x5d1c: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5d1f:
	/* 0x5d1f: jne    1665 <trace_security_bprm_check+0x1665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5733ULL;
	}
x86_l_5d25:
	/* 0x5d25: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d2a:
	/* 0x5d2a: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_5d2f:
	/* 0x5d2f: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f54;
	}
x86_l_5d35:
	/* 0x5d35: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d3a:
	/* 0x5d3a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d3f:
	/* 0x5d3f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5d43:
	/* 0x5d43: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d46:
	/* 0x5d46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d4b:
	/* 0x5d4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d4d:
	/* 0x5d4d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d52:
	/* 0x5d52: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d57:
	/* 0x5d57: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d5c:
	/* 0x5d5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d61:
	/* 0x5d61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d63:
	/* 0x5d63: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d68:
	/* 0x5d68: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d6d:
	/* 0x5d6d: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d72:
	/* 0x5d72: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d77:
	/* 0x5d77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d79:
	/* 0x5d79: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d7e:
	/* 0x5d7e: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5d82:
	/* 0x5d82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d87:
	/* 0x5d87: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d8c:
	/* 0x5d8c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d91:
	/* 0x5d91: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5d94:
	/* 0x5d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d96:
	/* 0x5d96: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d9b:
	/* 0x5d9b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d9f:
	/* 0x5d9f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5da3:
	/* 0x5da3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5da8:
	/* 0x5da8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dad:
	/* 0x5dad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5db2:
	/* 0x5db2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5db4:
	/* 0x5db4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5db8:
	/* 0x5db8: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5dbb:
	/* 0x5dbb: je     5dfc <trace_security_bprm_check+0x5dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5dfc;
	}
x86_l_5dbd:
	/* 0x5dbd: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dc2:
	/* 0x5dc2: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5dc5:
	/* 0x5dc5: je     5dfc <trace_security_bprm_check+0x5dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5dfc;
	}
x86_l_5dc7:
	/* 0x5dc7: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5dcb:
	/* 0x5dcb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5dd0:
	/* 0x5dd0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dd5:
	/* 0x5dd5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5dda:
	/* 0x5dda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ddc:
	/* 0x5ddc: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5de0:
	/* 0x5de0: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5de2:
	/* 0x5de2: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5de8:
	/* 0x5de8: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5dea:
	/* 0x5dea: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5dec:
	/* 0x5dec: jae    5e7d <trace_security_bprm_check+0x5e7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5e7d;
	}
x86_l_5df2:
	/* 0x5df2: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5df7:
	/* 0x5df7: jmp    5970 <trace_security_bprm_check+0x5970> */
	return 22896ULL;
x86_l_5dfc:
	/* 0x5dfc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5dff:
	/* 0x5dff: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5f54;
	}
x86_l_5e05:
	/* 0x5e05: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e0a:
	/* 0x5e0a: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_5e0f:
	/* 0x5e0f: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f54;
	}
x86_l_5e15:
	/* 0x5e15: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e1a:
	/* 0x5e1a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e1f:
	/* 0x5e1f: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5e23:
	/* 0x5e23: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5e26:
	/* 0x5e26: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e2b:
	/* 0x5e2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e2d:
	/* 0x5e2d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e32:
	/* 0x5e32: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e37:
	/* 0x5e37: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e3c:
	/* 0x5e3c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e41:
	/* 0x5e41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e43:
	/* 0x5e43: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5e48:
	/* 0x5e48: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e4d:
	/* 0x5e4d: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5e52:
	/* 0x5e52: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5e57:
	/* 0x5e57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e59:
	/* 0x5e59: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e5e:
	/* 0x5e5e: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5e62:
	/* 0x5e62: jmp    5eaf <trace_security_bprm_check+0x5eaf> */
	goto x86_l_5eaf;
x86_l_5e64:
	/* 0x5e64: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e69:
	/* 0x5e69: jmp    19b0 <trace_security_bprm_check+0x19b0> */
	return 6576ULL;
x86_l_5e6e:
	/* 0x5e6e: mov    r15,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e73:
	/* 0x5e73: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e78:
	/* 0x5e78: jmp    18f1 <trace_security_bprm_check+0x18f1> */
	return 6385ULL;
x86_l_5e7d:
	/* 0x5e7d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e82:
	/* 0x5e82: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5e88:
	/* 0x5e88: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e8b:
	/* 0x5e8b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5e90:
	/* 0x5e90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e92:
	/* 0x5e92: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e95:
	/* 0x5e95: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_5f54;
	}
x86_l_5e9b:
	/* 0x5e9b: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5e9e:
	/* 0x5e9e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5ea4:
	/* 0x5ea4: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5ea9:
	/* 0x5ea9: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5eab:
	/* 0x5eab: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5eaf:
	/* 0x5eaf: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5eb4:
	/* 0x5eb4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5eb9:
	/* 0x5eb9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ebe:
	/* 0x5ebe: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5ec1:
	/* 0x5ec1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ec3:
	/* 0x5ec3: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ec8:
	/* 0x5ec8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ecc:
	/* 0x5ecc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5ed0:
	/* 0x5ed0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ed5:
	/* 0x5ed5: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5eda:
	/* 0x5eda: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5edf:
	/* 0x5edf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ee1:
	/* 0x5ee1: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ee5:
	/* 0x5ee5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5ee8:
	/* 0x5ee8: je     5f4f <trace_security_bprm_check+0x5f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f4f;
	}
x86_l_5eea:
	/* 0x5eea: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5eef:
	/* 0x5eef: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5ef2:
	/* 0x5ef2: je     5f4f <trace_security_bprm_check+0x5f4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f4f;
	}
x86_l_5ef4:
	/* 0x5ef4: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5ef8:
	/* 0x5ef8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5efd:
	/* 0x5efd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f02:
	/* 0x5f02: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_5f07:
	/* 0x5f07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f09:
	/* 0x5f09: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5f0d:
	/* 0x5f0d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5f0f:
	/* 0x5f0f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5f15:
	/* 0x5f15: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_5f17:
	/* 0x5f17: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5f19:
	/* 0x5f19: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5df2;
	}
x86_l_5f1f:
	/* 0x5f1f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f24:
	/* 0x5f24: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_5f2a:
	/* 0x5f2a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5f2d:
	/* 0x5f2d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_5f32:
	/* 0x5f32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f34:
	/* 0x5f34: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5f37:
	/* 0x5f37: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_5f54;
	}
x86_l_5f39:
	/* 0x5f39: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_5f3c:
	/* 0x5f3c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_5f42:
	/* 0x5f42: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_5f47:
	/* 0x5f47: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_5f49:
	/* 0x5f49: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f4d:
	/* 0x5f4d: jmp    5fb7 <trace_security_bprm_check+0x5fb7> */
	goto x86_l_5fb7;
x86_l_5f4f:
	/* 0x5f4f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5f52:
	/* 0x5f52: je     5f5e <trace_security_bprm_check+0x5f5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f5e;
	}
x86_l_5f54:
	/* 0x5f54: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f59:
	/* 0x5f59: jmp    1665 <trace_security_bprm_check+0x1665> */
	return 5733ULL;
x86_l_5f5e:
	/* 0x5f5e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f63:
	/* 0x5f63: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_5f68:
	/* 0x5f68: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f54;
	}
x86_l_5f6a:
	/* 0x5f6a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f6f:
	/* 0x5f6f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f74:
	/* 0x5f74: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5f78:
	/* 0x5f78: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5f7b:
	/* 0x5f7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f80:
	/* 0x5f80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f82:
	/* 0x5f82: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f87:
	/* 0x5f87: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f8c:
	/* 0x5f8c: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5f91:
	/* 0x5f91: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f96:
	/* 0x5f96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f98:
	/* 0x5f98: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f9d:
	/* 0x5f9d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fa2:
	/* 0x5fa2: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5fa7:
	/* 0x5fa7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fac:
	/* 0x5fac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fae:
	/* 0x5fae: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fb3:
	/* 0x5fb3: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_5fb7:
	/* 0x5fb7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fbc:
	/* 0x5fbc: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fc1:
	/* 0x5fc1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fc6:
	/* 0x5fc6: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5fc9:
	/* 0x5fc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fcb:
	/* 0x5fcb: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fd0:
	/* 0x5fd0: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fd4:
	/* 0x5fd4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_5fd8:
	/* 0x5fd8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5fdd:
	/* 0x5fdd: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fe2:
	/* 0x5fe2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5fe7:
	/* 0x5fe7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fe9:
	/* 0x5fe9: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fed:
	/* 0x5fed: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_5ff0:
	/* 0x5ff0: je     605b <trace_security_bprm_check+0x605b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_605b;
	}
x86_l_5ff2:
	/* 0x5ff2: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ff7:
	/* 0x5ff7: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5ffa:
	/* 0x5ffa: je     605b <trace_security_bprm_check+0x605b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_605b;
	}
x86_l_5ffc:
	/* 0x5ffc: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6000:
	/* 0x6000: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6005:
	/* 0x6005: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_600a:
	/* 0x600a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_600f:
	/* 0x600f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6011:
	/* 0x6011: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6015:
	/* 0x6015: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6017:
	/* 0x6017: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_601d:
	/* 0x601d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_601f:
	/* 0x601f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6021:
	/* 0x6021: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5df2;
	}
x86_l_6027:
	/* 0x6027: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_602c:
	/* 0x602c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6032:
	/* 0x6032: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6035:
	/* 0x6035: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_603a:
	/* 0x603a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_603c:
	/* 0x603c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_603f:
	/* 0x603f: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_5f54;
	}
x86_l_6045:
	/* 0x6045: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6048:
	/* 0x6048: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_604e:
	/* 0x604e: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6053:
	/* 0x6053: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6055:
	/* 0x6055: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6059:
	/* 0x6059: jmp    60c1 <trace_security_bprm_check+0x60c1> */
	goto x86_l_60c1;
x86_l_605b:
	/* 0x605b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_605e:
	/* 0x605e: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5f54;
	}
x86_l_6064:
	/* 0x6064: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6069:
	/* 0x6069: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_606e:
	/* 0x606e: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f54;
	}
x86_l_6074:
	/* 0x6074: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6079:
	/* 0x6079: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_607e:
	/* 0x607e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6082:
	/* 0x6082: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6085:
	/* 0x6085: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_608a:
	/* 0x608a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_608c:
	/* 0x608c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6091:
	/* 0x6091: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6096:
	/* 0x6096: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_609b:
	/* 0x609b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60a0:
	/* 0x60a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60a2:
	/* 0x60a2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60a7:
	/* 0x60a7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60ac:
	/* 0x60ac: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_60b1:
	/* 0x60b1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60b6:
	/* 0x60b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60b8:
	/* 0x60b8: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_60bd:
	/* 0x60bd: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_60c1:
	/* 0x60c1: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60c6:
	/* 0x60c6: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60cb:
	/* 0x60cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60d0:
	/* 0x60d0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_60d3:
	/* 0x60d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60d5:
	/* 0x60d5: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60da:
	/* 0x60da: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60de:
	/* 0x60de: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_60e2:
	/* 0x60e2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_60e7:
	/* 0x60e7: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_60ec:
	/* 0x60ec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_60f1:
	/* 0x60f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60f3:
	/* 0x60f3: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60f7:
	/* 0x60f7: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_60fa:
	/* 0x60fa: je     6165 <trace_security_bprm_check+0x6165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6165;
	}
x86_l_60fc:
	/* 0x60fc: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6101:
	/* 0x6101: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6104:
	/* 0x6104: je     6165 <trace_security_bprm_check+0x6165> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6165;
	}
x86_l_6106:
	/* 0x6106: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_610a:
	/* 0x610a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_610f:
	/* 0x610f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6114:
	/* 0x6114: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6119:
	/* 0x6119: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611b:
	/* 0x611b: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_611f:
	/* 0x611f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6121:
	/* 0x6121: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6127:
	/* 0x6127: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6129:
	/* 0x6129: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_612b:
	/* 0x612b: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5df2;
	}
x86_l_6131:
	/* 0x6131: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6136:
	/* 0x6136: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_613c:
	/* 0x613c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_613f:
	/* 0x613f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6144:
	/* 0x6144: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6146:
	/* 0x6146: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6149:
	/* 0x6149: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_5f54;
	}
x86_l_614f:
	/* 0x614f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6152:
	/* 0x6152: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6158:
	/* 0x6158: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_615d:
	/* 0x615d: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_615f:
	/* 0x615f: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6163:
	/* 0x6163: jmp    61cb <trace_security_bprm_check+0x61cb> */
	goto x86_l_61cb;
x86_l_6165:
	/* 0x6165: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6168:
	/* 0x6168: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5f54;
	}
x86_l_616e:
	/* 0x616e: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6173:
	/* 0x6173: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_6178:
	/* 0x6178: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5f54;
	}
x86_l_617e:
	/* 0x617e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6183:
	/* 0x6183: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6188:
	/* 0x6188: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_618c:
	/* 0x618c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_618f:
	/* 0x618f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6194:
	/* 0x6194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6196:
	/* 0x6196: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_619b:
	/* 0x619b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61a0:
	/* 0x61a0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61a5:
	/* 0x61a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61aa:
	/* 0x61aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61ac:
	/* 0x61ac: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61b1:
	/* 0x61b1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61b6:
	/* 0x61b6: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_61bb:
	/* 0x61bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61c0:
	/* 0x61c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61c2:
	/* 0x61c2: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61c7:
	/* 0x61c7: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_61cb:
	/* 0x61cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61d0:
	/* 0x61d0: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x61df: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_61e4:
	/* 0x61e4: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61e8:
	/* 0x61e8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_61ec:
	/* 0x61ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61f1:
	/* 0x61f1: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_61f6:
	/* 0x61f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_61fb:
	/* 0x61fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61fd:
	/* 0x61fd: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6201:
	/* 0x6201: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6204:
	/* 0x6204: je     626f <trace_security_bprm_check+0x626f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25199ULL;
	}
x86_l_6206:
	/* 0x6206: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_620b:
	/* 0x620b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_620e:
	/* 0x620e: je     626f <trace_security_bprm_check+0x626f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 25199ULL;
	}
x86_l_6210:
	/* 0x6210: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6214:
	/* 0x6214: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6219:
	/* 0x6219: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_621e:
	/* 0x621e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6223:
	/* 0x6223: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6225:
	/* 0x6225: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6229:
	/* 0x6229: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_622b:
	/* 0x622b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6231:
	/* 0x6231: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6233:
	/* 0x6233: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6235:
	/* 0x6235: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5df2;
	}
x86_l_623b:
	/* 0x623b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6240:
	/* 0x6240: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6246:
	/* 0x6246: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6249:
	/* 0x6249: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_624e:
	/* 0x624e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6250:
	/* 0x6250: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6253:
	/* 0x6253: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_5f54;
	}
	return 25177ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_14(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 25177ULL: goto x86_l_6259;
	case 25180ULL: goto x86_l_625c;
	case 25186ULL: goto x86_l_6262;
	case 25191ULL: goto x86_l_6267;
	case 25193ULL: goto x86_l_6269;
	case 25197ULL: goto x86_l_626d;
	case 25199ULL: goto x86_l_626f;
	case 25202ULL: goto x86_l_6272;
	case 25208ULL: goto x86_l_6278;
	case 25213ULL: goto x86_l_627d;
	case 25218ULL: goto x86_l_6282;
	case 25224ULL: goto x86_l_6288;
	case 25229ULL: goto x86_l_628d;
	case 25234ULL: goto x86_l_6292;
	case 25238ULL: goto x86_l_6296;
	case 25241ULL: goto x86_l_6299;
	case 25246ULL: goto x86_l_629e;
	case 25248ULL: goto x86_l_62a0;
	case 25253ULL: goto x86_l_62a5;
	case 25258ULL: goto x86_l_62aa;
	case 25263ULL: goto x86_l_62af;
	case 25268ULL: goto x86_l_62b4;
	case 25270ULL: goto x86_l_62b6;
	case 25275ULL: goto x86_l_62bb;
	case 25280ULL: goto x86_l_62c0;
	case 25285ULL: goto x86_l_62c5;
	case 25290ULL: goto x86_l_62ca;
	case 25292ULL: goto x86_l_62cc;
	case 25297ULL: goto x86_l_62d1;
	case 25301ULL: goto x86_l_62d5;
	case 25306ULL: goto x86_l_62da;
	case 25311ULL: goto x86_l_62df;
	case 25316ULL: goto x86_l_62e4;
	case 25319ULL: goto x86_l_62e7;
	case 25321ULL: goto x86_l_62e9;
	case 25326ULL: goto x86_l_62ee;
	case 25330ULL: goto x86_l_62f2;
	case 25334ULL: goto x86_l_62f6;
	case 25339ULL: goto x86_l_62fb;
	case 25344ULL: goto x86_l_6300;
	case 25349ULL: goto x86_l_6305;
	case 25351ULL: goto x86_l_6307;
	case 25355ULL: goto x86_l_630b;
	case 25358ULL: goto x86_l_630e;
	case 25360ULL: goto x86_l_6310;
	case 25365ULL: goto x86_l_6315;
	case 25368ULL: goto x86_l_6318;
	case 25370ULL: goto x86_l_631a;
	case 25374ULL: goto x86_l_631e;
	case 25379ULL: goto x86_l_6323;
	case 25384ULL: goto x86_l_6328;
	case 25389ULL: goto x86_l_632d;
	case 25391ULL: goto x86_l_632f;
	case 25395ULL: goto x86_l_6333;
	case 25397ULL: goto x86_l_6335;
	case 25403ULL: goto x86_l_633b;
	case 25405ULL: goto x86_l_633d;
	case 25407ULL: goto x86_l_633f;
	case 25413ULL: goto x86_l_6345;
	case 25418ULL: goto x86_l_634a;
	case 25424ULL: goto x86_l_6350;
	case 25427ULL: goto x86_l_6353;
	case 25432ULL: goto x86_l_6358;
	case 25434ULL: goto x86_l_635a;
	case 25437ULL: goto x86_l_635d;
	case 25443ULL: goto x86_l_6363;
	case 25446ULL: goto x86_l_6366;
	case 25452ULL: goto x86_l_636c;
	case 25457ULL: goto x86_l_6371;
	case 25459ULL: goto x86_l_6373;
	case 25463ULL: goto x86_l_6377;
	case 25465ULL: goto x86_l_6379;
	case 25468ULL: goto x86_l_637c;
	case 25474ULL: goto x86_l_6382;
	case 25479ULL: goto x86_l_6387;
	case 25484ULL: goto x86_l_638c;
	case 25490ULL: goto x86_l_6392;
	case 25495ULL: goto x86_l_6397;
	case 25500ULL: goto x86_l_639c;
	case 25504ULL: goto x86_l_63a0;
	case 25507ULL: goto x86_l_63a3;
	case 25512ULL: goto x86_l_63a8;
	case 25514ULL: goto x86_l_63aa;
	case 25519ULL: goto x86_l_63af;
	case 25524ULL: goto x86_l_63b4;
	case 25529ULL: goto x86_l_63b9;
	case 25534ULL: goto x86_l_63be;
	case 25536ULL: goto x86_l_63c0;
	case 25541ULL: goto x86_l_63c5;
	case 25546ULL: goto x86_l_63ca;
	case 25551ULL: goto x86_l_63cf;
	case 25556ULL: goto x86_l_63d4;
	case 25558ULL: goto x86_l_63d6;
	case 25563ULL: goto x86_l_63db;
	case 25567ULL: goto x86_l_63df;
	case 25572ULL: goto x86_l_63e4;
	case 25577ULL: goto x86_l_63e9;
	case 25582ULL: goto x86_l_63ee;
	case 25585ULL: goto x86_l_63f1;
	case 25587ULL: goto x86_l_63f3;
	case 25592ULL: goto x86_l_63f8;
	case 25596ULL: goto x86_l_63fc;
	case 25600ULL: goto x86_l_6400;
	case 25605ULL: goto x86_l_6405;
	case 25610ULL: goto x86_l_640a;
	case 25615ULL: goto x86_l_640f;
	case 25617ULL: goto x86_l_6411;
	case 25621ULL: goto x86_l_6415;
	case 25624ULL: goto x86_l_6418;
	case 25626ULL: goto x86_l_641a;
	case 25631ULL: goto x86_l_641f;
	case 25634ULL: goto x86_l_6422;
	case 25636ULL: goto x86_l_6424;
	case 25640ULL: goto x86_l_6428;
	case 25645ULL: goto x86_l_642d;
	case 25650ULL: goto x86_l_6432;
	case 25655ULL: goto x86_l_6437;
	case 25657ULL: goto x86_l_6439;
	case 25661ULL: goto x86_l_643d;
	case 25663ULL: goto x86_l_643f;
	case 25669ULL: goto x86_l_6445;
	case 25671ULL: goto x86_l_6447;
	case 25673ULL: goto x86_l_6449;
	case 25679ULL: goto x86_l_644f;
	case 25684ULL: goto x86_l_6454;
	case 25690ULL: goto x86_l_645a;
	case 25693ULL: goto x86_l_645d;
	case 25698ULL: goto x86_l_6462;
	case 25700ULL: goto x86_l_6464;
	case 25703ULL: goto x86_l_6467;
	case 25709ULL: goto x86_l_646d;
	case 25712ULL: goto x86_l_6470;
	case 25718ULL: goto x86_l_6476;
	case 25723ULL: goto x86_l_647b;
	case 25725ULL: goto x86_l_647d;
	case 25729ULL: goto x86_l_6481;
	case 25731ULL: goto x86_l_6483;
	case 25734ULL: goto x86_l_6486;
	case 25740ULL: goto x86_l_648c;
	case 25745ULL: goto x86_l_6491;
	case 25750ULL: goto x86_l_6496;
	case 25756ULL: goto x86_l_649c;
	case 25761ULL: goto x86_l_64a1;
	case 25766ULL: goto x86_l_64a6;
	case 25770ULL: goto x86_l_64aa;
	case 25773ULL: goto x86_l_64ad;
	case 25778ULL: goto x86_l_64b2;
	case 25780ULL: goto x86_l_64b4;
	case 25785ULL: goto x86_l_64b9;
	case 25790ULL: goto x86_l_64be;
	case 25795ULL: goto x86_l_64c3;
	case 25800ULL: goto x86_l_64c8;
	case 25802ULL: goto x86_l_64ca;
	case 25807ULL: goto x86_l_64cf;
	case 25812ULL: goto x86_l_64d4;
	case 25817ULL: goto x86_l_64d9;
	case 25822ULL: goto x86_l_64de;
	case 25824ULL: goto x86_l_64e0;
	case 25829ULL: goto x86_l_64e5;
	case 25833ULL: goto x86_l_64e9;
	case 25838ULL: goto x86_l_64ee;
	case 25843ULL: goto x86_l_64f3;
	case 25848ULL: goto x86_l_64f8;
	case 25851ULL: goto x86_l_64fb;
	case 25853ULL: goto x86_l_64fd;
	case 25858ULL: goto x86_l_6502;
	case 25862ULL: goto x86_l_6506;
	case 25866ULL: goto x86_l_650a;
	case 25871ULL: goto x86_l_650f;
	case 25876ULL: goto x86_l_6514;
	case 25881ULL: goto x86_l_6519;
	case 25883ULL: goto x86_l_651b;
	case 25887ULL: goto x86_l_651f;
	case 25890ULL: goto x86_l_6522;
	case 25892ULL: goto x86_l_6524;
	case 25897ULL: goto x86_l_6529;
	case 25900ULL: goto x86_l_652c;
	case 25902ULL: goto x86_l_652e;
	case 25906ULL: goto x86_l_6532;
	case 25911ULL: goto x86_l_6537;
	case 25916ULL: goto x86_l_653c;
	case 25921ULL: goto x86_l_6541;
	case 25923ULL: goto x86_l_6543;
	case 25927ULL: goto x86_l_6547;
	case 25929ULL: goto x86_l_6549;
	case 25935ULL: goto x86_l_654f;
	case 25937ULL: goto x86_l_6551;
	case 25939ULL: goto x86_l_6553;
	case 25945ULL: goto x86_l_6559;
	case 25950ULL: goto x86_l_655e;
	case 25956ULL: goto x86_l_6564;
	case 25959ULL: goto x86_l_6567;
	case 25964ULL: goto x86_l_656c;
	case 25966ULL: goto x86_l_656e;
	case 25969ULL: goto x86_l_6571;
	case 25975ULL: goto x86_l_6577;
	case 25978ULL: goto x86_l_657a;
	case 25984ULL: goto x86_l_6580;
	case 25989ULL: goto x86_l_6585;
	case 25991ULL: goto x86_l_6587;
	case 25995ULL: goto x86_l_658b;
	case 25997ULL: goto x86_l_658d;
	case 26000ULL: goto x86_l_6590;
	case 26006ULL: goto x86_l_6596;
	case 26011ULL: goto x86_l_659b;
	case 26016ULL: goto x86_l_65a0;
	case 26022ULL: goto x86_l_65a6;
	case 26027ULL: goto x86_l_65ab;
	case 26032ULL: goto x86_l_65b0;
	case 26036ULL: goto x86_l_65b4;
	case 26039ULL: goto x86_l_65b7;
	case 26044ULL: goto x86_l_65bc;
	case 26046ULL: goto x86_l_65be;
	case 26051ULL: goto x86_l_65c3;
	case 26056ULL: goto x86_l_65c8;
	case 26061ULL: goto x86_l_65cd;
	case 26066ULL: goto x86_l_65d2;
	case 26068ULL: goto x86_l_65d4;
	case 26073ULL: goto x86_l_65d9;
	case 26078ULL: goto x86_l_65de;
	case 26083ULL: goto x86_l_65e3;
	case 26088ULL: goto x86_l_65e8;
	case 26090ULL: goto x86_l_65ea;
	case 26095ULL: goto x86_l_65ef;
	case 26099ULL: goto x86_l_65f3;
	case 26104ULL: goto x86_l_65f8;
	case 26109ULL: goto x86_l_65fd;
	case 26114ULL: goto x86_l_6602;
	case 26117ULL: goto x86_l_6605;
	case 26119ULL: goto x86_l_6607;
	case 26124ULL: goto x86_l_660c;
	case 26128ULL: goto x86_l_6610;
	case 26132ULL: goto x86_l_6614;
	case 26137ULL: goto x86_l_6619;
	case 26142ULL: goto x86_l_661e;
	case 26147ULL: goto x86_l_6623;
	case 26149ULL: goto x86_l_6625;
	case 26153ULL: goto x86_l_6629;
	case 26156ULL: goto x86_l_662c;
	case 26158ULL: goto x86_l_662e;
	case 26163ULL: goto x86_l_6633;
	case 26166ULL: goto x86_l_6636;
	case 26168ULL: goto x86_l_6638;
	case 26172ULL: goto x86_l_663c;
	case 26177ULL: goto x86_l_6641;
	case 26182ULL: goto x86_l_6646;
	case 26187ULL: goto x86_l_664b;
	case 26189ULL: goto x86_l_664d;
	case 26193ULL: goto x86_l_6651;
	case 26195ULL: goto x86_l_6653;
	case 26201ULL: goto x86_l_6659;
	case 26203ULL: goto x86_l_665b;
	case 26205ULL: goto x86_l_665d;
	case 26211ULL: goto x86_l_6663;
	case 26216ULL: goto x86_l_6668;
	case 26222ULL: goto x86_l_666e;
	case 26225ULL: goto x86_l_6671;
	case 26230ULL: goto x86_l_6676;
	case 26232ULL: goto x86_l_6678;
	case 26235ULL: goto x86_l_667b;
	case 26241ULL: goto x86_l_6681;
	case 26244ULL: goto x86_l_6684;
	case 26250ULL: goto x86_l_668a;
	case 26255ULL: goto x86_l_668f;
	case 26257ULL: goto x86_l_6691;
	case 26261ULL: goto x86_l_6695;
	case 26263ULL: goto x86_l_6697;
	case 26266ULL: goto x86_l_669a;
	case 26272ULL: goto x86_l_66a0;
	case 26277ULL: goto x86_l_66a5;
	case 26282ULL: goto x86_l_66aa;
	case 26288ULL: goto x86_l_66b0;
	case 26293ULL: goto x86_l_66b5;
	case 26298ULL: goto x86_l_66ba;
	case 26302ULL: goto x86_l_66be;
	case 26305ULL: goto x86_l_66c1;
	case 26310ULL: goto x86_l_66c6;
	case 26312ULL: goto x86_l_66c8;
	case 26317ULL: goto x86_l_66cd;
	case 26322ULL: goto x86_l_66d2;
	case 26327ULL: goto x86_l_66d7;
	case 26332ULL: goto x86_l_66dc;
	case 26334ULL: goto x86_l_66de;
	case 26339ULL: goto x86_l_66e3;
	case 26344ULL: goto x86_l_66e8;
	case 26349ULL: goto x86_l_66ed;
	case 26354ULL: goto x86_l_66f2;
	case 26356ULL: goto x86_l_66f4;
	case 26361ULL: goto x86_l_66f9;
	case 26365ULL: goto x86_l_66fd;
	case 26370ULL: goto x86_l_6702;
	case 26375ULL: goto x86_l_6707;
	case 26380ULL: goto x86_l_670c;
	case 26383ULL: goto x86_l_670f;
	case 26385ULL: goto x86_l_6711;
	case 26390ULL: goto x86_l_6716;
	case 26394ULL: goto x86_l_671a;
	case 26398ULL: goto x86_l_671e;
	case 26403ULL: goto x86_l_6723;
	case 26408ULL: goto x86_l_6728;
	case 26413ULL: goto x86_l_672d;
	case 26415ULL: goto x86_l_672f;
	case 26419ULL: goto x86_l_6733;
	case 26422ULL: goto x86_l_6736;
	case 26424ULL: goto x86_l_6738;
	case 26429ULL: goto x86_l_673d;
	case 26432ULL: goto x86_l_6740;
	case 26434ULL: goto x86_l_6742;
	case 26438ULL: goto x86_l_6746;
	case 26443ULL: goto x86_l_674b;
	case 26448ULL: goto x86_l_6750;
	case 26453ULL: goto x86_l_6755;
	case 26455ULL: goto x86_l_6757;
	case 26459ULL: goto x86_l_675b;
	case 26461ULL: goto x86_l_675d;
	case 26467ULL: goto x86_l_6763;
	case 26469ULL: goto x86_l_6765;
	case 26471ULL: goto x86_l_6767;
	case 26477ULL: goto x86_l_676d;
	case 26482ULL: goto x86_l_6772;
	case 26488ULL: goto x86_l_6778;
	case 26491ULL: goto x86_l_677b;
	case 26496ULL: goto x86_l_6780;
	case 26498ULL: goto x86_l_6782;
	case 26501ULL: goto x86_l_6785;
	case 26507ULL: goto x86_l_678b;
	case 26510ULL: goto x86_l_678e;
	case 26516ULL: goto x86_l_6794;
	case 26521ULL: goto x86_l_6799;
	case 26523ULL: goto x86_l_679b;
	case 26527ULL: goto x86_l_679f;
	case 26529ULL: goto x86_l_67a1;
	case 26532ULL: goto x86_l_67a4;
	case 26538ULL: goto x86_l_67aa;
	case 26543ULL: goto x86_l_67af;
	case 26548ULL: goto x86_l_67b4;
	case 26554ULL: goto x86_l_67ba;
	case 26559ULL: goto x86_l_67bf;
	case 26564ULL: goto x86_l_67c4;
	case 26568ULL: goto x86_l_67c8;
	case 26571ULL: goto x86_l_67cb;
	case 26576ULL: goto x86_l_67d0;
	case 26578ULL: goto x86_l_67d2;
	case 26583ULL: goto x86_l_67d7;
	case 26588ULL: goto x86_l_67dc;
	case 26593ULL: goto x86_l_67e1;
	case 26598ULL: goto x86_l_67e6;
	case 26600ULL: goto x86_l_67e8;
	case 26605ULL: goto x86_l_67ed;
	case 26610ULL: goto x86_l_67f2;
	case 26615ULL: goto x86_l_67f7;
	case 26620ULL: goto x86_l_67fc;
	case 26622ULL: goto x86_l_67fe;
	case 26627ULL: goto x86_l_6803;
	case 26631ULL: goto x86_l_6807;
	case 26636ULL: goto x86_l_680c;
	case 26641ULL: goto x86_l_6811;
	case 26646ULL: goto x86_l_6816;
	case 26649ULL: goto x86_l_6819;
	case 26651ULL: goto x86_l_681b;
	case 26656ULL: goto x86_l_6820;
	case 26660ULL: goto x86_l_6824;
	case 26664ULL: goto x86_l_6828;
	case 26669ULL: goto x86_l_682d;
	case 26674ULL: goto x86_l_6832;
	case 26679ULL: goto x86_l_6837;
	case 26681ULL: goto x86_l_6839;
	case 26685ULL: goto x86_l_683d;
	case 26688ULL: goto x86_l_6840;
	case 26690ULL: goto x86_l_6842;
	case 26695ULL: goto x86_l_6847;
	case 26698ULL: goto x86_l_684a;
	case 26700ULL: goto x86_l_684c;
	case 26704ULL: goto x86_l_6850;
	case 26709ULL: goto x86_l_6855;
	case 26714ULL: goto x86_l_685a;
	case 26719ULL: goto x86_l_685f;
	case 26721ULL: goto x86_l_6861;
	case 26725ULL: goto x86_l_6865;
	case 26727ULL: goto x86_l_6867;
	case 26733ULL: goto x86_l_686d;
	case 26735ULL: goto x86_l_686f;
	case 26737ULL: goto x86_l_6871;
	case 26743ULL: goto x86_l_6877;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6259:
	/* 0x6259: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_625c:
	/* 0x625c: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6262:
	/* 0x6262: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6267:
	/* 0x6267: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6269:
	/* 0x6269: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_626d:
	/* 0x626d: jmp    62d5 <trace_security_bprm_check+0x62d5> */
	goto x86_l_62d5;
x86_l_626f:
	/* 0x626f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6272:
	/* 0x6272: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_6278:
	/* 0x6278: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_627d:
	/* 0x627d: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_6282:
	/* 0x6282: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_6288:
	/* 0x6288: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_628d:
	/* 0x628d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6292:
	/* 0x6292: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6296:
	/* 0x6296: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6299:
	/* 0x6299: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_629e:
	/* 0x629e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62a0:
	/* 0x62a0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62a5:
	/* 0x62a5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62aa:
	/* 0x62aa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62af:
	/* 0x62af: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62b4:
	/* 0x62b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b6:
	/* 0x62b6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62bb:
	/* 0x62bb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62c0:
	/* 0x62c0: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_62c5:
	/* 0x62c5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62ca:
	/* 0x62ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62cc:
	/* 0x62cc: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_62d1:
	/* 0x62d1: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_62d5:
	/* 0x62d5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62da:
	/* 0x62da: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62df:
	/* 0x62df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_62e4:
	/* 0x62e4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_62e7:
	/* 0x62e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62e9:
	/* 0x62e9: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62ee:
	/* 0x62ee: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62f2:
	/* 0x62f2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_62f6:
	/* 0x62f6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_62fb:
	/* 0x62fb: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6300:
	/* 0x6300: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6305:
	/* 0x6305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6307:
	/* 0x6307: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_630b:
	/* 0x630b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_630e:
	/* 0x630e: je     6379 <trace_security_bprm_check+0x6379> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6379;
	}
x86_l_6310:
	/* 0x6310: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6315:
	/* 0x6315: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6318:
	/* 0x6318: je     6379 <trace_security_bprm_check+0x6379> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6379;
	}
x86_l_631a:
	/* 0x631a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_631e:
	/* 0x631e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6323:
	/* 0x6323: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6328:
	/* 0x6328: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_632d:
	/* 0x632d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_632f:
	/* 0x632f: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6333:
	/* 0x6333: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6335:
	/* 0x6335: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_633b:
	/* 0x633b: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_633d:
	/* 0x633d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_633f:
	/* 0x633f: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6345:
	/* 0x6345: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_634a:
	/* 0x634a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6350:
	/* 0x6350: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6353:
	/* 0x6353: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6358:
	/* 0x6358: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_635a:
	/* 0x635a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_635d:
	/* 0x635d: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_6363:
	/* 0x6363: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6366:
	/* 0x6366: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_636c:
	/* 0x636c: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6371:
	/* 0x6371: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6373:
	/* 0x6373: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6377:
	/* 0x6377: jmp    63df <trace_security_bprm_check+0x63df> */
	goto x86_l_63df;
x86_l_6379:
	/* 0x6379: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_637c:
	/* 0x637c: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_6382:
	/* 0x6382: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6387:
	/* 0x6387: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_638c:
	/* 0x638c: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_6392:
	/* 0x6392: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6397:
	/* 0x6397: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_639c:
	/* 0x639c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_63a0:
	/* 0x63a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_63a3:
	/* 0x63a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63a8:
	/* 0x63a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63aa:
	/* 0x63aa: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63af:
	/* 0x63af: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63b4:
	/* 0x63b4: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63b9:
	/* 0x63b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63be:
	/* 0x63be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63c0:
	/* 0x63c0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63c5:
	/* 0x63c5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63ca:
	/* 0x63ca: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_63cf:
	/* 0x63cf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63d4:
	/* 0x63d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63d6:
	/* 0x63d6: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63db:
	/* 0x63db: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_63df:
	/* 0x63df: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_63e4:
	/* 0x63e4: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_63e9:
	/* 0x63e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_63ee:
	/* 0x63ee: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_63f1:
	/* 0x63f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_63f3:
	/* 0x63f3: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_63f8:
	/* 0x63f8: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63fc:
	/* 0x63fc: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6400:
	/* 0x6400: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6405:
	/* 0x6405: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_640a:
	/* 0x640a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_640f:
	/* 0x640f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6411:
	/* 0x6411: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6415:
	/* 0x6415: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6418:
	/* 0x6418: je     6483 <trace_security_bprm_check+0x6483> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6483;
	}
x86_l_641a:
	/* 0x641a: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_641f:
	/* 0x641f: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6422:
	/* 0x6422: je     6483 <trace_security_bprm_check+0x6483> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6483;
	}
x86_l_6424:
	/* 0x6424: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6428:
	/* 0x6428: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_642d:
	/* 0x642d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6432:
	/* 0x6432: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6437:
	/* 0x6437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6439:
	/* 0x6439: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_643d:
	/* 0x643d: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_643f:
	/* 0x643f: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6445:
	/* 0x6445: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6447:
	/* 0x6447: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6449:
	/* 0x6449: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_644f:
	/* 0x644f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6454:
	/* 0x6454: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_645a:
	/* 0x645a: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_645d:
	/* 0x645d: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6462:
	/* 0x6462: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6464:
	/* 0x6464: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6467:
	/* 0x6467: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_646d:
	/* 0x646d: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6470:
	/* 0x6470: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6476:
	/* 0x6476: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_647b:
	/* 0x647b: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_647d:
	/* 0x647d: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6481:
	/* 0x6481: jmp    64e9 <trace_security_bprm_check+0x64e9> */
	goto x86_l_64e9;
x86_l_6483:
	/* 0x6483: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6486:
	/* 0x6486: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_648c:
	/* 0x648c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6491:
	/* 0x6491: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_6496:
	/* 0x6496: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_649c:
	/* 0x649c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64a1:
	/* 0x64a1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64a6:
	/* 0x64a6: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_64aa:
	/* 0x64aa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_64ad:
	/* 0x64ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64b2:
	/* 0x64b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64b4:
	/* 0x64b4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64b9:
	/* 0x64b9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64be:
	/* 0x64be: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64c3:
	/* 0x64c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64c8:
	/* 0x64c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64ca:
	/* 0x64ca: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64cf:
	/* 0x64cf: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64d4:
	/* 0x64d4: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_64d9:
	/* 0x64d9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64de:
	/* 0x64de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64e0:
	/* 0x64e0: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_64e5:
	/* 0x64e5: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_64e9:
	/* 0x64e9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_64ee:
	/* 0x64ee: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64f3:
	/* 0x64f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64f8:
	/* 0x64f8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_64fb:
	/* 0x64fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64fd:
	/* 0x64fd: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6502:
	/* 0x6502: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6506:
	/* 0x6506: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_650a:
	/* 0x650a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_650f:
	/* 0x650f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6514:
	/* 0x6514: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6519:
	/* 0x6519: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651b:
	/* 0x651b: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_651f:
	/* 0x651f: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6522:
	/* 0x6522: je     658d <trace_security_bprm_check+0x658d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_658d;
	}
x86_l_6524:
	/* 0x6524: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6529:
	/* 0x6529: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_652c:
	/* 0x652c: je     658d <trace_security_bprm_check+0x658d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_658d;
	}
x86_l_652e:
	/* 0x652e: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6532:
	/* 0x6532: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6537:
	/* 0x6537: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_653c:
	/* 0x653c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6541:
	/* 0x6541: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6543:
	/* 0x6543: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6547:
	/* 0x6547: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6549:
	/* 0x6549: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_654f:
	/* 0x654f: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6551:
	/* 0x6551: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6553:
	/* 0x6553: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6559:
	/* 0x6559: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_655e:
	/* 0x655e: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6564:
	/* 0x6564: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6567:
	/* 0x6567: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_656c:
	/* 0x656c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_656e:
	/* 0x656e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6571:
	/* 0x6571: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_6577:
	/* 0x6577: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_657a:
	/* 0x657a: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6580:
	/* 0x6580: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6585:
	/* 0x6585: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6587:
	/* 0x6587: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_658b:
	/* 0x658b: jmp    65f3 <trace_security_bprm_check+0x65f3> */
	goto x86_l_65f3;
x86_l_658d:
	/* 0x658d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6590:
	/* 0x6590: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_6596:
	/* 0x6596: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_659b:
	/* 0x659b: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_65a0:
	/* 0x65a0: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_65a6:
	/* 0x65a6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65ab:
	/* 0x65ab: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65b0:
	/* 0x65b0: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_65b4:
	/* 0x65b4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_65b7:
	/* 0x65b7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65bc:
	/* 0x65bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65be:
	/* 0x65be: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65c3:
	/* 0x65c3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65c8:
	/* 0x65c8: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65cd:
	/* 0x65cd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65d2:
	/* 0x65d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65d4:
	/* 0x65d4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65d9:
	/* 0x65d9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65de:
	/* 0x65de: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_65e3:
	/* 0x65e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_65e8:
	/* 0x65e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65ea:
	/* 0x65ea: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65ef:
	/* 0x65ef: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_65f3:
	/* 0x65f3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_65f8:
	/* 0x65f8: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65fd:
	/* 0x65fd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6602:
	/* 0x6602: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6605:
	/* 0x6605: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6607:
	/* 0x6607: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_660c:
	/* 0x660c: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6610:
	/* 0x6610: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6614:
	/* 0x6614: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6619:
	/* 0x6619: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_661e:
	/* 0x661e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6623:
	/* 0x6623: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6625:
	/* 0x6625: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6629:
	/* 0x6629: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_662c:
	/* 0x662c: je     6697 <trace_security_bprm_check+0x6697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6697;
	}
x86_l_662e:
	/* 0x662e: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6633:
	/* 0x6633: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6636:
	/* 0x6636: je     6697 <trace_security_bprm_check+0x6697> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6697;
	}
x86_l_6638:
	/* 0x6638: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_663c:
	/* 0x663c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6641:
	/* 0x6641: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6646:
	/* 0x6646: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_664b:
	/* 0x664b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_664d:
	/* 0x664d: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6651:
	/* 0x6651: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6653:
	/* 0x6653: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6659:
	/* 0x6659: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_665b:
	/* 0x665b: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_665d:
	/* 0x665d: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6663:
	/* 0x6663: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6668:
	/* 0x6668: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_666e:
	/* 0x666e: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6671:
	/* 0x6671: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6676:
	/* 0x6676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6678:
	/* 0x6678: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_667b:
	/* 0x667b: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_6681:
	/* 0x6681: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6684:
	/* 0x6684: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_668a:
	/* 0x668a: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_668f:
	/* 0x668f: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6691:
	/* 0x6691: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6695:
	/* 0x6695: jmp    66fd <trace_security_bprm_check+0x66fd> */
	goto x86_l_66fd;
x86_l_6697:
	/* 0x6697: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_669a:
	/* 0x669a: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_66a0:
	/* 0x66a0: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66a5:
	/* 0x66a5: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_66aa:
	/* 0x66aa: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_66b0:
	/* 0x66b0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66b5:
	/* 0x66b5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66ba:
	/* 0x66ba: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_66be:
	/* 0x66be: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_66c1:
	/* 0x66c1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66c6:
	/* 0x66c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66c8:
	/* 0x66c8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66cd:
	/* 0x66cd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66d2:
	/* 0x66d2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66d7:
	/* 0x66d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66dc:
	/* 0x66dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66de:
	/* 0x66de: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_66e3:
	/* 0x66e3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66e8:
	/* 0x66e8: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_66ed:
	/* 0x66ed: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_66f2:
	/* 0x66f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66f4:
	/* 0x66f4: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66f9:
	/* 0x66f9: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_66fd:
	/* 0x66fd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6702:
	/* 0x6702: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6707:
	/* 0x6707: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_670c:
	/* 0x670c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_670f:
	/* 0x670f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6711:
	/* 0x6711: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6716:
	/* 0x6716: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_671a:
	/* 0x671a: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_671e:
	/* 0x671e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6723:
	/* 0x6723: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6728:
	/* 0x6728: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_672d:
	/* 0x672d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_672f:
	/* 0x672f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6733:
	/* 0x6733: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6736:
	/* 0x6736: je     67a1 <trace_security_bprm_check+0x67a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67a1;
	}
x86_l_6738:
	/* 0x6738: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_673d:
	/* 0x673d: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6740:
	/* 0x6740: je     67a1 <trace_security_bprm_check+0x67a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_67a1;
	}
x86_l_6742:
	/* 0x6742: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6746:
	/* 0x6746: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_674b:
	/* 0x674b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6750:
	/* 0x6750: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6755:
	/* 0x6755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6757:
	/* 0x6757: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_675b:
	/* 0x675b: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_675d:
	/* 0x675d: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6763:
	/* 0x6763: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6765:
	/* 0x6765: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6767:
	/* 0x6767: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_676d:
	/* 0x676d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6772:
	/* 0x6772: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6778:
	/* 0x6778: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_677b:
	/* 0x677b: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6780:
	/* 0x6780: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6782:
	/* 0x6782: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6785:
	/* 0x6785: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_678b:
	/* 0x678b: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_678e:
	/* 0x678e: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6794:
	/* 0x6794: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6799:
	/* 0x6799: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_679b:
	/* 0x679b: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_679f:
	/* 0x679f: jmp    6807 <trace_security_bprm_check+0x6807> */
	goto x86_l_6807;
x86_l_67a1:
	/* 0x67a1: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_67a4:
	/* 0x67a4: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_67aa:
	/* 0x67aa: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67af:
	/* 0x67af: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_67b4:
	/* 0x67b4: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_67ba:
	/* 0x67ba: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67bf:
	/* 0x67bf: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67c4:
	/* 0x67c4: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_67c8:
	/* 0x67c8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_67cb:
	/* 0x67cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67d0:
	/* 0x67d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67d2:
	/* 0x67d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67d7:
	/* 0x67d7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67dc:
	/* 0x67dc: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67e1:
	/* 0x67e1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67e6:
	/* 0x67e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67e8:
	/* 0x67e8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_67ed:
	/* 0x67ed: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_67f2:
	/* 0x67f2: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_67f7:
	/* 0x67f7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_67fc:
	/* 0x67fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67fe:
	/* 0x67fe: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6803:
	/* 0x6803: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6807:
	/* 0x6807: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_680c:
	/* 0x680c: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6811:
	/* 0x6811: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6816:
	/* 0x6816: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6819:
	/* 0x6819: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_681b:
	/* 0x681b: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6820:
	/* 0x6820: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6824:
	/* 0x6824: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6828:
	/* 0x6828: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_682d:
	/* 0x682d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6832:
	/* 0x6832: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6837:
	/* 0x6837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6839:
	/* 0x6839: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_683d:
	/* 0x683d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6840:
	/* 0x6840: je     68ab <trace_security_bprm_check+0x68ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26795ULL;
	}
x86_l_6842:
	/* 0x6842: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6847:
	/* 0x6847: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_684a:
	/* 0x684a: je     68ab <trace_security_bprm_check+0x68ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 26795ULL;
	}
x86_l_684c:
	/* 0x684c: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6850:
	/* 0x6850: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6855:
	/* 0x6855: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_685a:
	/* 0x685a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_685f:
	/* 0x685f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6861:
	/* 0x6861: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6865:
	/* 0x6865: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6867:
	/* 0x6867: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_686d:
	/* 0x686d: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_686f:
	/* 0x686f: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6871:
	/* 0x6871: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6877:
	/* 0x6877: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 26748ULL;
}

static __noinline __u64 tracee_trace_security_bprm_check_x86_chunk_15(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 26748ULL: goto x86_l_687c;
	case 26754ULL: goto x86_l_6882;
	case 26757ULL: goto x86_l_6885;
	case 26762ULL: goto x86_l_688a;
	case 26764ULL: goto x86_l_688c;
	case 26767ULL: goto x86_l_688f;
	case 26773ULL: goto x86_l_6895;
	case 26776ULL: goto x86_l_6898;
	case 26782ULL: goto x86_l_689e;
	case 26787ULL: goto x86_l_68a3;
	case 26789ULL: goto x86_l_68a5;
	case 26793ULL: goto x86_l_68a9;
	case 26795ULL: goto x86_l_68ab;
	case 26798ULL: goto x86_l_68ae;
	case 26804ULL: goto x86_l_68b4;
	case 26809ULL: goto x86_l_68b9;
	case 26814ULL: goto x86_l_68be;
	case 26820ULL: goto x86_l_68c4;
	case 26825ULL: goto x86_l_68c9;
	case 26830ULL: goto x86_l_68ce;
	case 26834ULL: goto x86_l_68d2;
	case 26837ULL: goto x86_l_68d5;
	case 26842ULL: goto x86_l_68da;
	case 26844ULL: goto x86_l_68dc;
	case 26849ULL: goto x86_l_68e1;
	case 26854ULL: goto x86_l_68e6;
	case 26859ULL: goto x86_l_68eb;
	case 26864ULL: goto x86_l_68f0;
	case 26866ULL: goto x86_l_68f2;
	case 26871ULL: goto x86_l_68f7;
	case 26876ULL: goto x86_l_68fc;
	case 26881ULL: goto x86_l_6901;
	case 26886ULL: goto x86_l_6906;
	case 26888ULL: goto x86_l_6908;
	case 26893ULL: goto x86_l_690d;
	case 26897ULL: goto x86_l_6911;
	case 26902ULL: goto x86_l_6916;
	case 26907ULL: goto x86_l_691b;
	case 26912ULL: goto x86_l_6920;
	case 26915ULL: goto x86_l_6923;
	case 26917ULL: goto x86_l_6925;
	case 26922ULL: goto x86_l_692a;
	case 26926ULL: goto x86_l_692e;
	case 26930ULL: goto x86_l_6932;
	case 26935ULL: goto x86_l_6937;
	case 26940ULL: goto x86_l_693c;
	case 26945ULL: goto x86_l_6941;
	case 26947ULL: goto x86_l_6943;
	case 26951ULL: goto x86_l_6947;
	case 26954ULL: goto x86_l_694a;
	case 26956ULL: goto x86_l_694c;
	case 26961ULL: goto x86_l_6951;
	case 26964ULL: goto x86_l_6954;
	case 26966ULL: goto x86_l_6956;
	case 26970ULL: goto x86_l_695a;
	case 26975ULL: goto x86_l_695f;
	case 26980ULL: goto x86_l_6964;
	case 26985ULL: goto x86_l_6969;
	case 26987ULL: goto x86_l_696b;
	case 26991ULL: goto x86_l_696f;
	case 26993ULL: goto x86_l_6971;
	case 26999ULL: goto x86_l_6977;
	case 27001ULL: goto x86_l_6979;
	case 27003ULL: goto x86_l_697b;
	case 27009ULL: goto x86_l_6981;
	case 27014ULL: goto x86_l_6986;
	case 27020ULL: goto x86_l_698c;
	case 27023ULL: goto x86_l_698f;
	case 27028ULL: goto x86_l_6994;
	case 27030ULL: goto x86_l_6996;
	case 27033ULL: goto x86_l_6999;
	case 27039ULL: goto x86_l_699f;
	case 27042ULL: goto x86_l_69a2;
	case 27048ULL: goto x86_l_69a8;
	case 27053ULL: goto x86_l_69ad;
	case 27055ULL: goto x86_l_69af;
	case 27059ULL: goto x86_l_69b3;
	case 27061ULL: goto x86_l_69b5;
	case 27064ULL: goto x86_l_69b8;
	case 27070ULL: goto x86_l_69be;
	case 27075ULL: goto x86_l_69c3;
	case 27080ULL: goto x86_l_69c8;
	case 27086ULL: goto x86_l_69ce;
	case 27091ULL: goto x86_l_69d3;
	case 27096ULL: goto x86_l_69d8;
	case 27100ULL: goto x86_l_69dc;
	case 27103ULL: goto x86_l_69df;
	case 27108ULL: goto x86_l_69e4;
	case 27110ULL: goto x86_l_69e6;
	case 27115ULL: goto x86_l_69eb;
	case 27120ULL: goto x86_l_69f0;
	case 27125ULL: goto x86_l_69f5;
	case 27130ULL: goto x86_l_69fa;
	case 27132ULL: goto x86_l_69fc;
	case 27137ULL: goto x86_l_6a01;
	case 27142ULL: goto x86_l_6a06;
	case 27147ULL: goto x86_l_6a0b;
	case 27152ULL: goto x86_l_6a10;
	case 27154ULL: goto x86_l_6a12;
	case 27159ULL: goto x86_l_6a17;
	case 27163ULL: goto x86_l_6a1b;
	case 27168ULL: goto x86_l_6a20;
	case 27173ULL: goto x86_l_6a25;
	case 27178ULL: goto x86_l_6a2a;
	case 27181ULL: goto x86_l_6a2d;
	case 27183ULL: goto x86_l_6a2f;
	case 27188ULL: goto x86_l_6a34;
	case 27192ULL: goto x86_l_6a38;
	case 27196ULL: goto x86_l_6a3c;
	case 27201ULL: goto x86_l_6a41;
	case 27206ULL: goto x86_l_6a46;
	case 27211ULL: goto x86_l_6a4b;
	case 27213ULL: goto x86_l_6a4d;
	case 27217ULL: goto x86_l_6a51;
	case 27220ULL: goto x86_l_6a54;
	case 27222ULL: goto x86_l_6a56;
	case 27227ULL: goto x86_l_6a5b;
	case 27230ULL: goto x86_l_6a5e;
	case 27232ULL: goto x86_l_6a60;
	case 27236ULL: goto x86_l_6a64;
	case 27241ULL: goto x86_l_6a69;
	case 27246ULL: goto x86_l_6a6e;
	case 27251ULL: goto x86_l_6a73;
	case 27253ULL: goto x86_l_6a75;
	case 27257ULL: goto x86_l_6a79;
	case 27259ULL: goto x86_l_6a7b;
	case 27265ULL: goto x86_l_6a81;
	case 27267ULL: goto x86_l_6a83;
	case 27269ULL: goto x86_l_6a85;
	case 27275ULL: goto x86_l_6a8b;
	case 27280ULL: goto x86_l_6a90;
	case 27286ULL: goto x86_l_6a96;
	case 27289ULL: goto x86_l_6a99;
	case 27294ULL: goto x86_l_6a9e;
	case 27296ULL: goto x86_l_6aa0;
	case 27299ULL: goto x86_l_6aa3;
	case 27305ULL: goto x86_l_6aa9;
	case 27308ULL: goto x86_l_6aac;
	case 27314ULL: goto x86_l_6ab2;
	case 27319ULL: goto x86_l_6ab7;
	case 27321ULL: goto x86_l_6ab9;
	case 27325ULL: goto x86_l_6abd;
	case 27327ULL: goto x86_l_6abf;
	case 27330ULL: goto x86_l_6ac2;
	case 27336ULL: goto x86_l_6ac8;
	case 27341ULL: goto x86_l_6acd;
	case 27346ULL: goto x86_l_6ad2;
	case 27352ULL: goto x86_l_6ad8;
	case 27357ULL: goto x86_l_6add;
	case 27362ULL: goto x86_l_6ae2;
	case 27366ULL: goto x86_l_6ae6;
	case 27369ULL: goto x86_l_6ae9;
	case 27374ULL: goto x86_l_6aee;
	case 27376ULL: goto x86_l_6af0;
	case 27381ULL: goto x86_l_6af5;
	case 27386ULL: goto x86_l_6afa;
	case 27391ULL: goto x86_l_6aff;
	case 27396ULL: goto x86_l_6b04;
	case 27398ULL: goto x86_l_6b06;
	case 27403ULL: goto x86_l_6b0b;
	case 27408ULL: goto x86_l_6b10;
	case 27413ULL: goto x86_l_6b15;
	case 27418ULL: goto x86_l_6b1a;
	case 27420ULL: goto x86_l_6b1c;
	case 27425ULL: goto x86_l_6b21;
	case 27429ULL: goto x86_l_6b25;
	case 27434ULL: goto x86_l_6b2a;
	case 27439ULL: goto x86_l_6b2f;
	case 27444ULL: goto x86_l_6b34;
	case 27447ULL: goto x86_l_6b37;
	case 27449ULL: goto x86_l_6b39;
	case 27454ULL: goto x86_l_6b3e;
	case 27458ULL: goto x86_l_6b42;
	case 27462ULL: goto x86_l_6b46;
	case 27467ULL: goto x86_l_6b4b;
	case 27472ULL: goto x86_l_6b50;
	case 27477ULL: goto x86_l_6b55;
	case 27479ULL: goto x86_l_6b57;
	case 27483ULL: goto x86_l_6b5b;
	case 27486ULL: goto x86_l_6b5e;
	case 27488ULL: goto x86_l_6b60;
	case 27493ULL: goto x86_l_6b65;
	case 27496ULL: goto x86_l_6b68;
	case 27498ULL: goto x86_l_6b6a;
	case 27502ULL: goto x86_l_6b6e;
	case 27507ULL: goto x86_l_6b73;
	case 27512ULL: goto x86_l_6b78;
	case 27517ULL: goto x86_l_6b7d;
	case 27519ULL: goto x86_l_6b7f;
	case 27523ULL: goto x86_l_6b83;
	case 27525ULL: goto x86_l_6b85;
	case 27531ULL: goto x86_l_6b8b;
	case 27533ULL: goto x86_l_6b8d;
	case 27535ULL: goto x86_l_6b8f;
	case 27541ULL: goto x86_l_6b95;
	case 27546ULL: goto x86_l_6b9a;
	case 27552ULL: goto x86_l_6ba0;
	case 27555ULL: goto x86_l_6ba3;
	case 27560ULL: goto x86_l_6ba8;
	case 27562ULL: goto x86_l_6baa;
	case 27565ULL: goto x86_l_6bad;
	case 27571ULL: goto x86_l_6bb3;
	case 27574ULL: goto x86_l_6bb6;
	case 27580ULL: goto x86_l_6bbc;
	case 27585ULL: goto x86_l_6bc1;
	case 27587ULL: goto x86_l_6bc3;
	case 27591ULL: goto x86_l_6bc7;
	case 27596ULL: goto x86_l_6bcc;
	case 27599ULL: goto x86_l_6bcf;
	case 27605ULL: goto x86_l_6bd5;
	case 27610ULL: goto x86_l_6bda;
	case 27615ULL: goto x86_l_6bdf;
	case 27621ULL: goto x86_l_6be5;
	case 27626ULL: goto x86_l_6bea;
	case 27631ULL: goto x86_l_6bef;
	case 27635ULL: goto x86_l_6bf3;
	case 27638ULL: goto x86_l_6bf6;
	case 27643ULL: goto x86_l_6bfb;
	case 27645ULL: goto x86_l_6bfd;
	case 27650ULL: goto x86_l_6c02;
	case 27655ULL: goto x86_l_6c07;
	case 27660ULL: goto x86_l_6c0c;
	case 27665ULL: goto x86_l_6c11;
	case 27667ULL: goto x86_l_6c13;
	case 27672ULL: goto x86_l_6c18;
	case 27677ULL: goto x86_l_6c1d;
	case 27682ULL: goto x86_l_6c22;
	case 27687ULL: goto x86_l_6c27;
	case 27689ULL: goto x86_l_6c29;
	default: return 0xffffffffffffffffULL;
	}
x86_l_687c:
	/* 0x687c: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6882:
	/* 0x6882: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6885:
	/* 0x6885: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_688a:
	/* 0x688a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_688c:
	/* 0x688c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_688f:
	/* 0x688f: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_6895:
	/* 0x6895: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6898:
	/* 0x6898: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_689e:
	/* 0x689e: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_68a3:
	/* 0x68a3: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_68a5:
	/* 0x68a5: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68a9:
	/* 0x68a9: jmp    6911 <trace_security_bprm_check+0x6911> */
	goto x86_l_6911;
x86_l_68ab:
	/* 0x68ab: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_68ae:
	/* 0x68ae: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_68b4:
	/* 0x68b4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68b9:
	/* 0x68b9: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_68be:
	/* 0x68be: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_68c4:
	/* 0x68c4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68c9:
	/* 0x68c9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68ce:
	/* 0x68ce: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_68d2:
	/* 0x68d2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_68d5:
	/* 0x68d5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68da:
	/* 0x68da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68dc:
	/* 0x68dc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68e1:
	/* 0x68e1: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68e6:
	/* 0x68e6: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68eb:
	/* 0x68eb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_68f0:
	/* 0x68f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68f2:
	/* 0x68f2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_68f7:
	/* 0x68f7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68fc:
	/* 0x68fc: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6901:
	/* 0x6901: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6906:
	/* 0x6906: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6908:
	/* 0x6908: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_690d:
	/* 0x690d: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6911:
	/* 0x6911: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6916:
	/* 0x6916: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_691b:
	/* 0x691b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6920:
	/* 0x6920: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6923:
	/* 0x6923: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6925:
	/* 0x6925: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_692a:
	/* 0x692a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692e:
	/* 0x692e: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6932:
	/* 0x6932: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6937:
	/* 0x6937: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_693c:
	/* 0x693c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6941:
	/* 0x6941: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6943:
	/* 0x6943: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6947:
	/* 0x6947: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_694a:
	/* 0x694a: je     69b5 <trace_security_bprm_check+0x69b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69b5;
	}
x86_l_694c:
	/* 0x694c: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6951:
	/* 0x6951: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6954:
	/* 0x6954: je     69b5 <trace_security_bprm_check+0x69b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_69b5;
	}
x86_l_6956:
	/* 0x6956: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_695a:
	/* 0x695a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_695f:
	/* 0x695f: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6964:
	/* 0x6964: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6969:
	/* 0x6969: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_696b:
	/* 0x696b: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_696f:
	/* 0x696f: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6971:
	/* 0x6971: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6977:
	/* 0x6977: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6979:
	/* 0x6979: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_697b:
	/* 0x697b: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6981:
	/* 0x6981: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6986:
	/* 0x6986: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_698c:
	/* 0x698c: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_698f:
	/* 0x698f: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6994:
	/* 0x6994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6996:
	/* 0x6996: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6999:
	/* 0x6999: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_699f:
	/* 0x699f: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_69a2:
	/* 0x69a2: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_69a8:
	/* 0x69a8: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_69ad:
	/* 0x69ad: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_69af:
	/* 0x69af: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69b3:
	/* 0x69b3: jmp    6a1b <trace_security_bprm_check+0x6a1b> */
	goto x86_l_6a1b;
x86_l_69b5:
	/* 0x69b5: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_69b8:
	/* 0x69b8: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_69be:
	/* 0x69be: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69c3:
	/* 0x69c3: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_69c8:
	/* 0x69c8: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_69ce:
	/* 0x69ce: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69d3:
	/* 0x69d3: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69d8:
	/* 0x69d8: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_69dc:
	/* 0x69dc: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_69df:
	/* 0x69df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69e4:
	/* 0x69e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69e6:
	/* 0x69e6: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_69eb:
	/* 0x69eb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69f0:
	/* 0x69f0: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_69f5:
	/* 0x69f5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69fa:
	/* 0x69fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69fc:
	/* 0x69fc: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a01:
	/* 0x6a01: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a06:
	/* 0x6a06: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6a0b:
	/* 0x6a0b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a10:
	/* 0x6a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a12:
	/* 0x6a12: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a17:
	/* 0x6a17: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6a1b:
	/* 0x6a1b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a20:
	/* 0x6a20: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a25:
	/* 0x6a25: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a2a:
	/* 0x6a2a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6a2d:
	/* 0x6a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a2f:
	/* 0x6a2f: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a34:
	/* 0x6a34: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a38:
	/* 0x6a38: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6a3c:
	/* 0x6a3c: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a41:
	/* 0x6a41: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a46:
	/* 0x6a46: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a4b:
	/* 0x6a4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a4d:
	/* 0x6a4d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a51:
	/* 0x6a51: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6a54:
	/* 0x6a54: je     6abf <trace_security_bprm_check+0x6abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6abf;
	}
x86_l_6a56:
	/* 0x6a56: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a5b:
	/* 0x6a5b: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6a5e:
	/* 0x6a5e: je     6abf <trace_security_bprm_check+0x6abf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6abf;
	}
x86_l_6a60:
	/* 0x6a60: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6a64:
	/* 0x6a64: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6a69:
	/* 0x6a69: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a6e:
	/* 0x6a6e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6a73:
	/* 0x6a73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a75:
	/* 0x6a75: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6a79:
	/* 0x6a79: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6a7b:
	/* 0x6a7b: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6a81:
	/* 0x6a81: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6a83:
	/* 0x6a83: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6a85:
	/* 0x6a85: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6a8b:
	/* 0x6a8b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a90:
	/* 0x6a90: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6a96:
	/* 0x6a96: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6a99:
	/* 0x6a99: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6a9e:
	/* 0x6a9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6aa0:
	/* 0x6aa0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6aa3:
	/* 0x6aa3: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_6aa9:
	/* 0x6aa9: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6aac:
	/* 0x6aac: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6ab2:
	/* 0x6ab2: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6ab7:
	/* 0x6ab7: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6ab9:
	/* 0x6ab9: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6abd:
	/* 0x6abd: jmp    6b25 <trace_security_bprm_check+0x6b25> */
	goto x86_l_6b25;
x86_l_6abf:
	/* 0x6abf: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6ac2:
	/* 0x6ac2: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_6ac8:
	/* 0x6ac8: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6acd:
	/* 0x6acd: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_6ad2:
	/* 0x6ad2: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_6ad8:
	/* 0x6ad8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6add:
	/* 0x6add: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ae2:
	/* 0x6ae2: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6ae6:
	/* 0x6ae6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6ae9:
	/* 0x6ae9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6aee:
	/* 0x6aee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6af0:
	/* 0x6af0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6af5:
	/* 0x6af5: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6afa:
	/* 0x6afa: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6aff:
	/* 0x6aff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b04:
	/* 0x6b04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b06:
	/* 0x6b06: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b0b:
	/* 0x6b0b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b10:
	/* 0x6b10: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6b15:
	/* 0x6b15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b1a:
	/* 0x6b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b1c:
	/* 0x6b1c: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b21:
	/* 0x6b21: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b25:
	/* 0x6b25: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b2a:
	/* 0x6b2a: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b2f:
	/* 0x6b2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b34:
	/* 0x6b34: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_6b37:
	/* 0x6b37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b39:
	/* 0x6b39: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b3e:
	/* 0x6b3e: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b42:
	/* 0x6b42: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6b46:
	/* 0x6b46: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b4b:
	/* 0x6b4b: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b50:
	/* 0x6b50: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b55:
	/* 0x6b55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b57:
	/* 0x6b57: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b5b:
	/* 0x6b5b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6b5e:
	/* 0x6b5e: je     6bcc <trace_security_bprm_check+0x6bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6bcc;
	}
x86_l_6b60:
	/* 0x6b60: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b65:
	/* 0x6b65: cmp    rdx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6b68:
	/* 0x6b68: je     6bcc <trace_security_bprm_check+0x6bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6bcc;
	}
x86_l_6b6a:
	/* 0x6b6a: add    rdx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_6b6e:
	/* 0x6b6e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6b73:
	/* 0x6b73: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b78:
	/* 0x6b78: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6b7d:
	/* 0x6b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b7f:
	/* 0x6b7f: mov    esi,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6b83:
	/* 0x6b83: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6b85:
	/* 0x6b85: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6b8b:
	/* 0x6b8b: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_6b8d:
	/* 0x6b8d: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6b8f:
	/* 0x6b8f: jb     5df2 <trace_security_bprm_check+0x5df2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 24050ULL;
	}
x86_l_6b95:
	/* 0x6b95: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6b9a:
	/* 0x6b9a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_6ba0:
	/* 0x6ba0: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6ba3:
	/* 0x6ba3: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_6ba8:
	/* 0x6ba8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6baa:
	/* 0x6baa: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6bad:
	/* 0x6bad: jl     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 24404ULL;
	}
x86_l_6bb3:
	/* 0x6bb3: lea    ecx,[rbx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_6bb6:
	/* 0x6bb6: and    ecx,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_6bbc:
	/* 0x6bbc: mov    BYTE PTR [rbp+rcx*1+0x0],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_6bc1:
	/* 0x6bc1: sub    ebx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_6bc3:
	/* 0x6bc3: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6bc7:
	/* 0x6bc7: jmp    5f54 <trace_security_bprm_check+0x5f54> */
	return 24404ULL;
x86_l_6bcc:
	/* 0x6bcc: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_6bcf:
	/* 0x6bcf: jne    5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 24404ULL;
	}
x86_l_6bd5:
	/* 0x6bd5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6bda:
	/* 0x6bda: cmp    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 112ULL);
x86_l_6bdf:
	/* 0x6bdf: je     5f54 <trace_security_bprm_check+0x5f54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 24404ULL;
	}
x86_l_6be5:
	/* 0x6be5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6bea:
	/* 0x6bea: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6bef:
	/* 0x6bef: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_6bf3:
	/* 0x6bf3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6bf6:
	/* 0x6bf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6bfb:
	/* 0x6bfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6bfd:
	/* 0x6bfd: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c02:
	/* 0x6c02: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c07:
	/* 0x6c07: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c0c:
	/* 0x6c0c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c11:
	/* 0x6c11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c13:
	/* 0x6c13: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6c18:
	/* 0x6c18: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c1d:
	/* 0x6c1d: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6c22:
	/* 0x6c22: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6c27:
	/* 0x6c27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c29:
	/* 0x6c29: jmp    5f54 <trace_security_bprm_check+0x5f54> */
	return 24404ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tracee_trace_security_bprm_check_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 23956U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 2122ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 2124ULL && __x86_pc <= 3761ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3766ULL && __x86_pc <= 5330ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5332ULL && __x86_pc <= 7042ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7047ULL && __x86_pc <= 8797ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8805ULL && __x86_pc <= 10647ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10652ULL && __x86_pc <= 12539ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12544ULL && __x86_pc <= 14422ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14427ULL && __x86_pc <= 16279ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 16282ULL && __x86_pc <= 18134ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 18136ULL && __x86_pc <= 20020ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 20022ULL && __x86_pc <= 21892ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_11(__x86_state, __x86_pc);
		else if (__x86_pc >= 21900ULL && __x86_pc <= 23599ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_12(__x86_state, __x86_pc);
		else if (__x86_pc >= 23604ULL && __x86_pc <= 25171ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_13(__x86_state, __x86_pc);
		else if (__x86_pc >= 25177ULL && __x86_pc <= 26743ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_14(__x86_state, __x86_pc);
		else if (__x86_pc >= 26748ULL && __x86_pc <= 27689ULL)
			__x86_pc = tracee_trace_security_bprm_check_x86_chunk_15(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

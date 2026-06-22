extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_netkit;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_eth_header_length;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_call_policy;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_devices;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_affinity;
extern char cilium_lb4_backends_v3;
extern char cilium_lb4_services_v2;
extern char cilium_lb4_source_range;
extern char cilium_lb_affinity_match;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_nodeport_neigh4;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 17ULL: goto x86_l_11;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 35ULL: goto x86_l_23;
	case 38ULL: goto x86_l_26;
	case 41ULL: goto x86_l_29;
	case 48ULL: goto x86_l_30;
	case 51ULL: goto x86_l_33;
	case 55ULL: goto x86_l_37;
	case 59ULL: goto x86_l_3b;
	case 62ULL: goto x86_l_3e;
	case 67ULL: goto x86_l_43;
	case 70ULL: goto x86_l_46;
	case 72ULL: goto x86_l_48;
	case 74ULL: goto x86_l_4a;
	case 78ULL: goto x86_l_4e;
	case 82ULL: goto x86_l_52;
	case 86ULL: goto x86_l_56;
	case 88ULL: goto x86_l_58;
	case 92ULL: goto x86_l_5c;
	case 99ULL: goto x86_l_63;
	case 102ULL: goto x86_l_66;
	case 112ULL: goto x86_l_70;
	case 116ULL: goto x86_l_74;
	case 120ULL: goto x86_l_78;
	case 130ULL: goto x86_l_82;
	case 138ULL: goto x86_l_8a;
	case 145ULL: goto x86_l_91;
	case 150ULL: goto x86_l_96;
	case 157ULL: goto x86_l_9d;
	case 165ULL: goto x86_l_a5;
	case 167ULL: goto x86_l_a7;
	case 170ULL: goto x86_l_aa;
	case 176ULL: goto x86_l_b0;
	case 179ULL: goto x86_l_b3;
	case 183ULL: goto x86_l_b7;
	case 188ULL: goto x86_l_bc;
	case 191ULL: goto x86_l_bf;
	case 198ULL: goto x86_l_c6;
	case 202ULL: goto x86_l_ca;
	case 208ULL: goto x86_l_d0;
	case 215ULL: goto x86_l_d7;
	case 219ULL: goto x86_l_db;
	case 222ULL: goto x86_l_de;
	case 229ULL: goto x86_l_e5;
	case 237ULL: goto x86_l_ed;
	case 243ULL: goto x86_l_f3;
	case 253ULL: goto x86_l_fd;
	case 263ULL: goto x86_l_107;
	case 270ULL: goto x86_l_10e;
	case 278ULL: goto x86_l_116;
	case 286ULL: goto x86_l_11e;
	case 295ULL: goto x86_l_127;
	case 299ULL: goto x86_l_12b;
	case 304ULL: goto x86_l_130;
	case 309ULL: goto x86_l_135;
	case 312ULL: goto x86_l_138;
	case 316ULL: goto x86_l_13c;
	case 319ULL: goto x86_l_13f;
	case 324ULL: goto x86_l_144;
	case 327ULL: goto x86_l_147;
	case 333ULL: goto x86_l_14d;
	case 337ULL: goto x86_l_151;
	case 341ULL: goto x86_l_155;
	case 347ULL: goto x86_l_15b;
	case 351ULL: goto x86_l_15f;
	case 355ULL: goto x86_l_163;
	case 359ULL: goto x86_l_167;
	case 363ULL: goto x86_l_16b;
	case 367ULL: goto x86_l_16f;
	case 371ULL: goto x86_l_173;
	case 375ULL: goto x86_l_177;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 387ULL: goto x86_l_183;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 414ULL: goto x86_l_19e;
	case 418ULL: goto x86_l_1a2;
	case 423ULL: goto x86_l_1a7;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 444ULL: goto x86_l_1bc;
	case 451ULL: goto x86_l_1c3;
	case 460ULL: goto x86_l_1cc;
	case 463ULL: goto x86_l_1cf;
	case 467ULL: goto x86_l_1d3;
	case 474ULL: goto x86_l_1da;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 511ULL: goto x86_l_1ff;
	case 517ULL: goto x86_l_205;
	case 527ULL: goto x86_l_20f;
	case 532ULL: goto x86_l_214;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 550ULL: goto x86_l_226;
	case 558ULL: goto x86_l_22e;
	case 561ULL: goto x86_l_231;
	case 563ULL: goto x86_l_233;
	case 565ULL: goto x86_l_235;
	case 567ULL: goto x86_l_237;
	case 573ULL: goto x86_l_23d;
	case 577ULL: goto x86_l_241;
	case 586ULL: goto x86_l_24a;
	case 595ULL: goto x86_l_253;
	case 605ULL: goto x86_l_25d;
	case 613ULL: goto x86_l_265;
	case 618ULL: goto x86_l_26a;
	case 625ULL: goto x86_l_271;
	case 633ULL: goto x86_l_279;
	case 635ULL: goto x86_l_27b;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 647ULL: goto x86_l_287;
	case 651ULL: goto x86_l_28b;
	case 656ULL: goto x86_l_290;
	case 665ULL: goto x86_l_299;
	case 670ULL: goto x86_l_29e;
	case 675ULL: goto x86_l_2a3;
	case 682ULL: goto x86_l_2aa;
	case 690ULL: goto x86_l_2b2;
	case 695ULL: goto x86_l_2b7;
	case 697ULL: goto x86_l_2b9;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 711ULL: goto x86_l_2c7;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 728ULL: goto x86_l_2d8;
	case 735ULL: goto x86_l_2df;
	case 737ULL: goto x86_l_2e1;
	case 738ULL: goto x86_l_2e2;
	case 743ULL: goto x86_l_2e7;
	case 748ULL: goto x86_l_2ec;
	case 753ULL: goto x86_l_2f1;
	case 759ULL: goto x86_l_2f7;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 786ULL: goto x86_l_312;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 796ULL: goto x86_l_31c;
	case 798ULL: goto x86_l_31e;
	case 804ULL: goto x86_l_324;
	case 809ULL: goto x86_l_329;
	case 814ULL: goto x86_l_32e;
	case 818ULL: goto x86_l_332;
	case 822ULL: goto x86_l_336;
	case 826ULL: goto x86_l_33a;
	case 831ULL: goto x86_l_33f;
	case 836ULL: goto x86_l_344;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 853ULL: goto x86_l_355;
	case 860ULL: goto x86_l_35c;
	case 865ULL: goto x86_l_361;
	case 867ULL: goto x86_l_363;
	case 870ULL: goto x86_l_366;
	case 873ULL: goto x86_l_369;
	case 875ULL: goto x86_l_36b;
	case 881ULL: goto x86_l_371;
	case 887ULL: goto x86_l_377;
	case 894ULL: goto x86_l_37e;
	case 899ULL: goto x86_l_383;
	case 904ULL: goto x86_l_388;
	case 911ULL: goto x86_l_38f;
	case 916ULL: goto x86_l_394;
	case 918ULL: goto x86_l_396;
	case 921ULL: goto x86_l_399;
	case 924ULL: goto x86_l_39c;
	case 930ULL: goto x86_l_3a2;
	case 932ULL: goto x86_l_3a4;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 952ULL: goto x86_l_3b8;
	case 957ULL: goto x86_l_3bd;
	case 962ULL: goto x86_l_3c2;
	case 967ULL: goto x86_l_3c7;
	case 970ULL: goto x86_l_3ca;
	case 975ULL: goto x86_l_3cf;
	case 979ULL: goto x86_l_3d3;
	case 984ULL: goto x86_l_3d8;
	case 986ULL: goto x86_l_3da;
	case 991ULL: goto x86_l_3df;
	case 993ULL: goto x86_l_3e1;
	case 997ULL: goto x86_l_3e5;
	case 1001ULL: goto x86_l_3e9;
	case 1009ULL: goto x86_l_3f1;
	case 1014ULL: goto x86_l_3f6;
	case 1021ULL: goto x86_l_3fd;
	case 1025ULL: goto x86_l_401;
	case 1030ULL: goto x86_l_406;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1052ULL: goto x86_l_41c;
	case 1055ULL: goto x86_l_41f;
	case 1059ULL: goto x86_l_423;
	case 1062ULL: goto x86_l_426;
	case 1065ULL: goto x86_l_429;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1077ULL: goto x86_l_435;
	case 1083ULL: goto x86_l_43b;
	case 1087ULL: goto x86_l_43f;
	case 1089ULL: goto x86_l_441;
	case 1094ULL: goto x86_l_446;
	case 1099ULL: goto x86_l_44b;
	case 1105ULL: goto x86_l_451;
	case 1109ULL: goto x86_l_455;
	case 1115ULL: goto x86_l_45b;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1132ULL: goto x86_l_46c;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1148ULL: goto x86_l_47c;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1170ULL: goto x86_l_492;
	case 1174ULL: goto x86_l_496;
	case 1180ULL: goto x86_l_49c;
	case 1183ULL: goto x86_l_49f;
	case 1194ULL: goto x86_l_4aa;
	case 1199ULL: goto x86_l_4af;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1213ULL: goto x86_l_4bd;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1223ULL: goto x86_l_4c7;
	case 1225ULL: goto x86_l_4c9;
	case 1231ULL: goto x86_l_4cf;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1247ULL: goto x86_l_4df;
	case 1255ULL: goto x86_l_4e7;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1272ULL: goto x86_l_4f8;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1306ULL: goto x86_l_51a;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1322ULL: goto x86_l_52a;
	case 1332ULL: goto x86_l_534;
	case 1338ULL: goto x86_l_53a;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1359ULL: goto x86_l_54f;
	case 1363ULL: goto x86_l_553;
	case 1371ULL: goto x86_l_55b;
	case 1376ULL: goto x86_l_560;
	case 1387ULL: goto x86_l_56b;
	case 1390ULL: goto x86_l_56e;
	case 1393ULL: goto x86_l_571;
	case 1401ULL: goto x86_l_579;
	case 1407ULL: goto x86_l_57f;
	case 1410ULL: goto x86_l_582;
	case 1416ULL: goto x86_l_588;
	case 1424ULL: goto x86_l_590;
	case 1428ULL: goto x86_l_594;
	case 1437ULL: goto x86_l_59d;
	case 1446ULL: goto x86_l_5a6;
	case 1456ULL: goto x86_l_5b0;
	case 1462ULL: goto x86_l_5b6;
	case 1470ULL: goto x86_l_5be;
	case 1475ULL: goto x86_l_5c3;
	case 1482ULL: goto x86_l_5ca;
	case 1490ULL: goto x86_l_5d2;
	case 1492ULL: goto x86_l_5d4;
	case 1495ULL: goto x86_l_5d7;
	case 1497ULL: goto x86_l_5d9;
	case 1500ULL: goto x86_l_5dc;
	case 1504ULL: goto x86_l_5e0;
	case 1506ULL: goto x86_l_5e2;
	case 1511ULL: goto x86_l_5e7;
	case 1516ULL: goto x86_l_5ec;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1535ULL: goto x86_l_5ff;
	case 1542ULL: goto x86_l_606;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1557ULL: goto x86_l_615;
	case 1559ULL: goto x86_l_617;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1577ULL: goto x86_l_629;
	case 1581ULL: goto x86_l_62d;
	case 1583ULL: goto x86_l_62f;
	case 1586ULL: goto x86_l_632;
	case 1589ULL: goto x86_l_635;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1599ULL: goto x86_l_63f;
	case 1607ULL: goto x86_l_647;
	case 1610ULL: goto x86_l_64a;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1619ULL: goto x86_l_653;
	case 1625ULL: goto x86_l_659;
	case 1633ULL: goto x86_l_661;
	case 1636ULL: goto x86_l_664;
	case 1641ULL: goto x86_l_669;
	case 1643ULL: goto x86_l_66b;
	case 1648ULL: goto x86_l_670;
	case 1651ULL: goto x86_l_673;
	case 1658ULL: goto x86_l_67a;
	case 1664ULL: goto x86_l_680;
	case 1666ULL: goto x86_l_682;
	case 1673ULL: goto x86_l_689;
	case 1675ULL: goto x86_l_68b;
	case 1686ULL: goto x86_l_696;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1719ULL: goto x86_l_6b7;
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
	case 1736ULL: goto x86_l_6c8;
	case 1740ULL: goto x86_l_6cc;
	case 1746ULL: goto x86_l_6d2;
	case 1753ULL: goto x86_l_6d9;
	case 1761ULL: goto x86_l_6e1;
	case 1767ULL: goto x86_l_6e7;
	case 1771ULL: goto x86_l_6eb;
	case 1777ULL: goto x86_l_6f1;
	case 1785ULL: goto x86_l_6f9;
	case 1792ULL: goto x86_l_700;
	case 1795ULL: goto x86_l_703;
	case 1801ULL: goto x86_l_709;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1815ULL: goto x86_l_717;
	case 1819ULL: goto x86_l_71b;
	case 1822ULL: goto x86_l_71e;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1868ULL: goto x86_l_74c;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1896ULL: goto x86_l_768;
	case 1898ULL: goto x86_l_76a;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r15d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_18:
	/* 0x18: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1f:
	/* 0x1f: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23:
	/* 0x23: mov    ecx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26:
	/* 0x26: sub    ecx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_29:
	/* 0x29: mov    r13,QWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_30:
	/* 0x30: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_33:
	/* 0x33: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37:
	/* 0x37: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_3b:
	/* 0x3b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e:
	/* 0x3e: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_43:
	/* 0x43: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: jbe    bc <tail_handle_ipv4_from_netdev+0xbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_bc;
	}
x86_l_48:
	/* 0x48: neg    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_4a:
	/* 0x4a: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4e:
	/* 0x4e: shl    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_52:
	/* 0x52: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_56:
	/* 0x56: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_58:
	/* 0x58: mov    DWORD PTR [rbx+0x28],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c:
	/* 0x5c: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_63:
	/* 0x63: mov    DWORD PTR [rbx+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_66:
	/* 0x66: movabs rcx,0x3bb010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 268809710860238848ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_74:
	/* 0x74: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_78:
	/* 0x78: movabs rcx,0x103bb0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4357554432ULL);
x86_l_82:
	/* 0x82: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a:
	/* 0x8a: mov    BYTE PTR [rsp+0x80],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_91:
	/* 0x91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_96:
	/* 0x96: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9d:
	/* 0x9d: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a5:
	/* 0xa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7:
	/* 0xa7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: je     290 <tail_handle_ipv4_from_netdev+0x290> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_290;
	}
x86_l_b0:
	/* 0xb0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b3:
	/* 0xb3: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b7:
	/* 0xb7: jmp    2bb <tail_handle_ipv4_from_netdev+0x2bb> */
	goto x86_l_2bb;
x86_l_bc:
	/* 0xbc: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bf:
	/* 0xbf: mov    r9,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_c6:
	/* 0xc6: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca:
	/* 0xca: je     2e7 <tail_handle_ipv4_from_netdev+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e7;
	}
x86_l_d0:
	/* 0xd0: movzx  eax,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_d7:
	/* 0xd7: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_db:
	/* 0xdb: and    eax,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_de:
	/* 0xde: mov    WORD PTR [rbx+0x86],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 134ULL);
x86_l_e5:
	/* 0xe5: test   DWORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_ed:
	/* 0xed: jne    1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8070ULL;
	}
x86_l_f3:
	/* 0xf3: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_fd:
	/* 0xfd: movabs rsi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1099511627776ULL);
x86_l_107:
	/* 0x107: mov    WORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_10e:
	/* 0x10e: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_116:
	/* 0x116: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_11e:
	/* 0x11e: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_127:
	/* 0x127: movzx  r10d,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_12b:
	/* 0x12b: movzx  ecx,WORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_130:
	/* 0x130: movzx  eax,BYTE PTR [r13+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_135:
	/* 0x135: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: shl    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_13c:
	/* 0x13c: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_13f:
	/* 0x13f: movzx  ecx,WORD PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_144:
	/* 0x144: add    rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_147:
	/* 0x147: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_14d:
	/* 0x14d: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_151:
	/* 0x151: lea    r8,[rsi+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_155:
	/* 0x155: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_15b:
	/* 0x15b: cmove  r8,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_15f:
	/* 0x15f: mov    esi,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163:
	/* 0x163: mov    BYTE PTR [rsp+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_167:
	/* 0x167: mov    ecx,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16b:
	/* 0x16b: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16f:
	/* 0x16f: mov    edx,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_173:
	/* 0x173: mov    DWORD PTR [rsp+0x24],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_177:
	/* 0x177: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a:
	/* 0x17a: je     8f7 <tail_handle_ipv4_from_netdev+0x8f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2295ULL;
	}
x86_l_180:
	/* 0x180: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_183:
	/* 0x183: je     18e <tail_handle_ipv4_from_netdev+0x18e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18e;
	}
x86_l_185:
	/* 0x185: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_188:
	/* 0x188: jne    1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8070ULL;
	}
x86_l_18e:
	/* 0x18e: and    esi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_191:
	/* 0x191: lea    esi,[r10+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_195:
	/* 0x195: lea    r14,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19a:
	/* 0x19a: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2:
	/* 0x1a2: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7:
	/* 0x1a7: mov    QWORD PTR [rsp+0xa8],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1af:
	/* 0x1af: je     301 <tail_handle_ipv4_from_netdev+0x301> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_301;
	}
x86_l_1b5:
	/* 0x1b5: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1bc:
	/* 0x1bc: mov    DWORD PTR [rsp+0x84],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1c3:
	/* 0x1c3: mov    WORD PTR [rsp+0x88],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1cc:
	/* 0x1cc: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_1cf:
	/* 0x1cf: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1d3:
	/* 0x1d3: mov    BYTE PTR [rsp+0x8a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_1da:
	/* 0x1da: mov    BYTE PTR [rsp+0x8b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 597000454144ULL);
x86_l_1e2:
	/* 0x1e2: test   r8,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: jne    1308 <tail_handle_ipv4_from_netdev+0x1308> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4872ULL;
	}
x86_l_1eb:
	/* 0x1eb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1f0:
	/* 0x1f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1fb:
	/* 0x1fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd:
	/* 0x1fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ff:
	/* 0x1ff: js     3c2 <tail_handle_ipv4_from_netdev+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c2;
	}
x86_l_205:
	/* 0x205: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_20f:
	/* 0x20f: test   QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_214:
	/* 0x214: je     324 <tail_handle_ipv4_from_netdev+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_324;
	}
x86_l_21a:
	/* 0x21a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21f:
	/* 0x21f: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_226:
	/* 0x226: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_22e:
	/* 0x22e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_231:
	/* 0x231: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_233:
	/* 0x233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235:
	/* 0x235: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237:
	/* 0x237: je     324 <tail_handle_ipv4_from_netdev+0x324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_324;
	}
x86_l_23d:
	/* 0x23d: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_241:
	/* 0x241: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_24a:
	/* 0x24a: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_253:
	/* 0x253: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_25d:
	/* 0x25d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_265:
	/* 0x265: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26a:
	/* 0x26a: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_271:
	/* 0x271: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_279:
	/* 0x279: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27b:
	/* 0x27b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27e:
	/* 0x27e: je     1348 <tail_handle_ipv4_from_netdev+0x1348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4936ULL;
	}
x86_l_284:
	/* 0x284: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_287:
	/* 0x287: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28b:
	/* 0x28b: jmp    324 <tail_handle_ipv4_from_netdev+0x324> */
	goto x86_l_324;
x86_l_290:
	/* 0x290: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_299:
	/* 0x299: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_29e:
	/* 0x29e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a3:
	/* 0x2a3: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2aa:
	/* 0x2aa: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2b2:
	/* 0x2b2: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b7:
	/* 0x2b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b9:
	/* 0x2b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bb:
	/* 0x2bb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c0:
	/* 0x2c0: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2c7:
	/* 0x2c7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2cf:
	/* 0x2cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1:
	/* 0x2d1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d6:
	/* 0x2d6: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2d8:
	/* 0x2d8: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_2df:
	/* 0x2df: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2e1:
	/* 0x2e1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2e2:
	/* 0x2e2: jmp    281b <tail_handle_ipv4_from_netdev+0x281b> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2e7:
	/* 0x2e7: movzx  eax,WORD PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2ec:
	/* 0x2ec: test   eax,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 65343ULL);
x86_l_2f1:
	/* 0x2f1: je     d0 <tail_handle_ipv4_from_netdev+0xd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d0;
	}
x86_l_2f7:
	/* 0x2f7: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_2fc:
	/* 0x2fc: jmp    48 <tail_handle_ipv4_from_netdev+0x48> */
	goto x86_l_48;
x86_l_301:
	/* 0x301: test   r8,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_304:
	/* 0x304: jne    132e <tail_handle_ipv4_from_netdev+0x132e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4910ULL;
	}
x86_l_30a:
	/* 0x30a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_30f:
	/* 0x30f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_312:
	/* 0x312: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_315:
	/* 0x315: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_31a:
	/* 0x31a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c:
	/* 0x31c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31e:
	/* 0x31e: js     3c2 <tail_handle_ipv4_from_netdev+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c2;
	}
x86_l_324:
	/* 0x324: mov    DWORD PTR [rsp+0x1c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_329:
	/* 0x329: movzx  eax,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_32e:
	/* 0x32e: mov    BYTE PTR [rsp+0x78],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_332:
	/* 0x332: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_336:
	/* 0x336: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_33a:
	/* 0x33a: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_33f:
	/* 0x33f: mov    WORD PTR [rsp+0x74],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_344:
	/* 0x344: mov    WORD PTR [rsp+0x76],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_34b:
	/* 0x34b: mov    BYTE PTR [rsp+0x79],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 519691042816ULL);
x86_l_350:
	/* 0x350: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_355:
	/* 0x355: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_35c:
	/* 0x35c: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_361:
	/* 0x361: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_363:
	/* 0x363: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_366:
	/* 0x366: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_369:
	/* 0x369: jne    3a2 <tail_handle_ipv4_from_netdev+0x3a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a2;
	}
x86_l_36b:
	/* 0x36b: movzx  r14d,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_371:
	/* 0x371: movzx  r15d,WORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_377:
	/* 0x377: mov    WORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_37e:
	/* 0x37e: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_383:
	/* 0x383: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_388:
	/* 0x388: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_38f:
	/* 0x38f: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_394:
	/* 0x394: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_396:
	/* 0x396: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_399:
	/* 0x399: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39c:
	/* 0x39c: je     467 <tail_handle_ipv4_from_netdev+0x467> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_467;
	}
x86_l_3a2:
	/* 0x3a2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a4:
	/* 0x3a4: cmp    WORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_3aa:
	/* 0x3aa: mov    esi,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967138ULL);
x86_l_3af:
	/* 0x3af: jne    3cf <tail_handle_ipv4_from_netdev+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cf;
	}
x86_l_3b1:
	/* 0x3b1: cmp    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3b6:
	/* 0x3b6: jne    3cf <tail_handle_ipv4_from_netdev+0x3cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3cf;
	}
x86_l_3b8:
	/* 0x3b8: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3bd:
	/* 0x3bd: jmp    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	return 7544ULL;
x86_l_3c2:
	/* 0x3c2: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_3c7:
	/* 0x3c7: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ca:
	/* 0x3ca: jmp    91c <tail_handle_ipv4_from_netdev+0x91c> */
	return 2332ULL;
x86_l_3cf:
	/* 0x3cf: cmp    BYTE PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3d3:
	/* 0x3d3: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d8:
	/* 0x3d8: js     3e1 <tail_handle_ipv4_from_netdev+0x3e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3e1;
	}
x86_l_3da:
	/* 0x3da: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3df:
	/* 0x3df: jmp    43b <tail_handle_ipv4_from_netdev+0x43b> */
	goto x86_l_43b;
x86_l_3e1:
	/* 0x3e1: mov    eax,DWORD PTR [r13+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3e5:
	/* 0x3e5: movzx  ecx,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_3e9:
	/* 0x3e9: mov    DWORD PTR [rsp+0x38],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168640ULL);
x86_l_3f1:
	/* 0x3f1: mov    WORD PTR [rsp+0x3c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3f6:
	/* 0x3f6: mov    WORD PTR [rsp+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_3fd:
	/* 0x3fd: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_401:
	/* 0x401: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_406:
	/* 0x406: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_source_range)));
x86_l_40d:
	/* 0x40d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_412:
	/* 0x412: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_414:
	/* 0x414: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_419:
	/* 0x419: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41c:
	/* 0x41c: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_41f:
	/* 0x41f: movzx  ecx,BYTE PTR [rdx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_423:
	/* 0x423: and    cl,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 64ULL);
x86_l_426:
	/* 0x426: shr    cl,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHR, 6ULL);
x86_l_429:
	/* 0x429: cmp    al,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_8);
x86_l_42b:
	/* 0x42b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_430:
	/* 0x430: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_435:
	/* 0x435: je     5e2 <tail_handle_ipv4_from_netdev+0x5e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e2;
	}
x86_l_43b:
	/* 0x43b: test   BYTE PTR [rdx+0x8],0x40 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_43f:
	/* 0x43f: jne    44b <tail_handle_ipv4_from_netdev+0x44b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_44b;
	}
x86_l_441:
	/* 0x441: mov    esi,0xffffff52 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967122ULL);
x86_l_446:
	/* 0x446: jmp    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	return 7544ULL;
x86_l_44b:
	/* 0x44b: movzx  r14d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_451:
	/* 0x451: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_455:
	/* 0x455: jne    504 <tail_handle_ipv4_from_netdev+0x504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_504;
	}
x86_l_45b:
	/* 0x45b: mov    rax,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_462:
	/* 0x462: jmp    50b <tail_handle_ipv4_from_netdev+0x50b> */
	goto x86_l_50b;
x86_l_467:
	/* 0x467: mov    BYTE PTR [rsp+0x78],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_46c:
	/* 0x46c: mov    WORD PTR [rsp+0x74],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_472:
	/* 0x472: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_477:
	/* 0x477: mov    rcx,QWORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_47c:
	/* 0x47c: mov    QWORD PTR [rsp+0x3e],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_481:
	/* 0x481: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_486:
	/* 0x486: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_48b:
	/* 0x48b: mov    rdx,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_492:
	/* 0x492: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_496:
	/* 0x496: jne    761 <tail_handle_ipv4_from_netdev+0x761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_761;
	}
x86_l_49c:
	/* 0x49c: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_49f:
	/* 0x49f: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_4aa:
	/* 0x4aa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4af:
	/* 0x4af: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_4b2:
	/* 0x4b2: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4b5:
	/* 0x4b5: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4bd:
	/* 0x4bd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4c0:
	/* 0x4c0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4c5:
	/* 0x4c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c7:
	/* 0x4c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c9:
	/* 0x4c9: js     727 <tail_handle_ipv4_from_netdev+0x727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_727;
	}
x86_l_4cf:
	/* 0x4cf: rol    QWORD PTR [rsp+0x38],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 240518168608ULL);
x86_l_4d5:
	/* 0x4d5: rol    DWORD PTR [rsp+0x40],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 274877906960ULL);
x86_l_4da:
	/* 0x4da: xor    BYTE PTR [rsp+0x45],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 296352743425ULL);
x86_l_4df:
	/* 0x4df: test   BYTE PTR [rsp+0x81],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 554050781186ULL);
x86_l_4e7:
	/* 0x4e7: jne    75b <tail_handle_ipv4_from_netdev+0x75b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_75b;
	}
x86_l_4ed:
	/* 0x4ed: cmp    BYTE PTR [rsp+0x44],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 292057776134ULL);
x86_l_4f2:
	/* 0x4f2: jne    85a <tail_handle_ipv4_from_netdev+0x85a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2138ULL;
	}
x86_l_4f8:
	/* 0x4f8: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_4ff:
	/* 0x4ff: jmp    861 <tail_handle_ipv4_from_netdev+0x861> */
	return 2145ULL;
x86_l_504:
	/* 0x504: mov    rax,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_50b:
	/* 0x50b: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_510:
	/* 0x510: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_51a:
	/* 0x51a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51e:
	/* 0x51e: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_523:
	/* 0x523: mov    rax,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_52a:
	/* 0x52a: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_534:
	/* 0x534: movzx  r8d,BYTE PTR [rsp+0x2d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_53a:
	/* 0x53a: mov    BYTE PTR [rsp+0xc0],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_542:
	/* 0x542: mov    r8d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_547:
	/* 0x547: mov    QWORD PTR [rsp+0xc8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_54f:
	/* 0x54f: movzx  edx,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_553:
	/* 0x553: mov    WORD PTR [rsp+0xb8],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_55b:
	/* 0x55b: mov    BYTE PTR [rsp+0x2d],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528324ULL);
x86_l_560:
	/* 0x560: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_56b:
	/* 0x56b: and    rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_AND);
x86_l_56e:
	/* 0x56e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_571:
	/* 0x571: mov    QWORD PTR [rsp+0xd0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_579:
	/* 0x579: je     629 <tail_handle_ipv4_from_netdev+0x629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_629;
	}
x86_l_57f:
	/* 0x57f: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_582:
	/* 0x582: je     629 <tail_handle_ipv4_from_netdev+0x629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_629;
	}
x86_l_588:
	/* 0x588: mov    BYTE PTR [rsp+0x90],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_590:
	/* 0x590: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5a6:
	/* 0x5a6: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_5b0:
	/* 0x5b0: or     rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 256ULL);
x86_l_5b6:
	/* 0x5b6: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5be:
	/* 0x5be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c3:
	/* 0x5c3: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_5ca:
	/* 0x5ca: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5d2:
	/* 0x5d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d4:
	/* 0x5d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d7:
	/* 0x5d7: je     5ec <tail_handle_ipv4_from_netdev+0x5ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ec;
	}
x86_l_5d9:
	/* 0x5d9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5dc:
	/* 0x5dc: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e0:
	/* 0x5e0: jmp    617 <tail_handle_ipv4_from_netdev+0x617> */
	goto x86_l_617;
x86_l_5e2:
	/* 0x5e2: mov    esi,0xffffff4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967119ULL);
x86_l_5e7:
	/* 0x5e7: jmp    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	return 7544ULL;
x86_l_5ec:
	/* 0x5ec: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5ff:
	/* 0x5ff: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_606:
	/* 0x606: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_60e:
	/* 0x60e: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_613:
	/* 0x613: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_615:
	/* 0x615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_617:
	/* 0x617: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61b:
	/* 0x61b: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_620:
	/* 0x620: movzx  r14d,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_629:
	/* 0x629: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_62d:
	/* 0x62d: jne    68b <tail_handle_ipv4_from_netdev+0x68b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_68b;
	}
x86_l_62f:
	/* 0x62f: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_632:
	/* 0x632: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_635:
	/* 0x635: jne    68b <tail_handle_ipv4_from_netdev+0x68b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_68b;
	}
x86_l_637:
	/* 0x637: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_63c:
	/* 0x63c: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_63f:
	/* 0x63f: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_647:
	/* 0x647: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_64a:
	/* 0x64a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_64f:
	/* 0x64f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_651:
	/* 0x651: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_653:
	/* 0x653: js     1d71 <tail_handle_ipv4_from_netdev+0x1d71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7537ULL;
	}
x86_l_659:
	/* 0x659: mov    r13d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_661:
	/* 0x661: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_664:
	/* 0x664: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_669:
	/* 0x669: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66b:
	/* 0x66b: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_670:
	/* 0x670: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_673:
	/* 0x673: test   r13d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 1280ULL);
x86_l_67a:
	/* 0x67a: jne    1378 <tail_handle_ipv4_from_netdev+0x1378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4984ULL;
	}
x86_l_680:
	/* 0x680: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_682:
	/* 0x682: mov    DWORD PTR [rsp+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_689:
	/* 0x689: jmp    69e <tail_handle_ipv4_from_netdev+0x69e> */
	goto x86_l_69e;
x86_l_68b:
	/* 0x68b: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_696:
	/* 0x696: mov    r13d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_69e:
	/* 0x69e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a3:
	/* 0x6a3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a8:
	/* 0x6a8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ad:
	/* 0x6ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6af:
	/* 0x6af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b7:
	/* 0x6b7: je     1474 <tail_handle_ipv4_from_netdev+0x1474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5236ULL;
	}
x86_l_6bd:
	/* 0x6bd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6c0:
	/* 0x6c0: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_6c8:
	/* 0x6c8: cmp    WORD PTR [rdi+0x26],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_6cc:
	/* 0x6cc: jne    1474 <tail_handle_ipv4_from_netdev+0x1474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5236ULL;
	}
x86_l_6d2:
	/* 0x6d2: test   r13d,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 512ULL);
x86_l_6d9:
	/* 0x6d9: mov    QWORD PTR [rsp+0xb0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_6e1:
	/* 0x6e1: je     b42 <tail_handle_ipv4_from_netdev+0xb42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2882ULL;
	}
x86_l_6e7:
	/* 0x6e7: test   BYTE PTR [rdi+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_6eb:
	/* 0x6eb: je     b42 <tail_handle_ipv4_from_netdev+0xb42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2882ULL;
	}
x86_l_6f1:
	/* 0x6f1: mov    BYTE PTR [rsp+0x90],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6f9:
	/* 0x6f9: mov    rax,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_700:
	/* 0x700: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_703:
	/* 0x703: je     ae2 <tail_handle_ipv4_from_netdev+0xae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2786ULL;
	}
x86_l_709:
	/* 0x709: mov    rcx,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_710:
	/* 0x710: mov    r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_713:
	/* 0x713: lea    ecx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_717:
	/* 0x717: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_71b:
	/* 0x71b: sub    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_71e:
	/* 0x71e: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_722:
	/* 0x722: jmp    ae8 <tail_handle_ipv4_from_netdev+0xae8> */
	return 2792ULL;
x86_l_727:
	/* 0x727: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_72c:
	/* 0x72c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72e:
	/* 0x72e: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_733:
	/* 0x733: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_73d:
	/* 0x73d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_740:
	/* 0x740: mov    r10,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_745:
	/* 0x745: mov    r8,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_74c:
	/* 0x74c: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_756:
	/* 0x756: jmp    8b3 <tail_handle_ipv4_from_netdev+0x8b3> */
	return 2227ULL;
x86_l_75b:
	/* 0x75b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_75e:
	/* 0x75e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_761:
	/* 0x761: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_766:
	/* 0x766: and    al,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_768:
	/* 0x768: cmp    al,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 7ULL);
x86_l_76a:
	/* 0x76a: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
	return 1903ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1903ULL: goto x86_l_76f;
	case 1905ULL: goto x86_l_771;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1916ULL: goto x86_l_77c;
	case 1919ULL: goto x86_l_77f;
	case 1927ULL: goto x86_l_787;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1939ULL: goto x86_l_793;
	case 1941ULL: goto x86_l_795;
	case 1949ULL: goto x86_l_79d;
	case 1959ULL: goto x86_l_7a7;
	case 1964ULL: goto x86_l_7ac;
	case 1971ULL: goto x86_l_7b3;
	case 1981ULL: goto x86_l_7bd;
	case 1983ULL: goto x86_l_7bf;
	case 1991ULL: goto x86_l_7c7;
	case 1993ULL: goto x86_l_7c9;
	case 2000ULL: goto x86_l_7d0;
	case 2006ULL: goto x86_l_7d6;
	case 2014ULL: goto x86_l_7de;
	case 2021ULL: goto x86_l_7e5;
	case 2023ULL: goto x86_l_7e7;
	case 2025ULL: goto x86_l_7e9;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2038ULL: goto x86_l_7f6;
	case 2043ULL: goto x86_l_7fb;
	case 2045ULL: goto x86_l_7fd;
	case 2052ULL: goto x86_l_804;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2061ULL: goto x86_l_80d;
	case 2071ULL: goto x86_l_817;
	case 2076ULL: goto x86_l_81c;
	case 2083ULL: goto x86_l_823;
	case 2093ULL: goto x86_l_82d;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2120ULL: goto x86_l_848;
	case 2123ULL: goto x86_l_84b;
	case 2129ULL: goto x86_l_851;
	case 2133ULL: goto x86_l_855;
	case 2138ULL: goto x86_l_85a;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2167ULL: goto x86_l_877;
	case 2169ULL: goto x86_l_879;
	case 2172ULL: goto x86_l_87c;
	case 2174ULL: goto x86_l_87e;
	case 2178ULL: goto x86_l_882;
	case 2181ULL: goto x86_l_885;
	case 2183ULL: goto x86_l_887;
	case 2185ULL: goto x86_l_889;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2210ULL: goto x86_l_8a2;
	case 2220ULL: goto x86_l_8ac;
	case 2227ULL: goto x86_l_8b3;
	case 2230ULL: goto x86_l_8b6;
	case 2232ULL: goto x86_l_8b8;
	case 2234ULL: goto x86_l_8ba;
	case 2236ULL: goto x86_l_8bc;
	case 2238ULL: goto x86_l_8be;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2253ULL: goto x86_l_8cd;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2274ULL: goto x86_l_8e2;
	case 2280ULL: goto x86_l_8e8;
	case 2284ULL: goto x86_l_8ec;
	case 2286ULL: goto x86_l_8ee;
	case 2293ULL: goto x86_l_8f5;
	case 2295ULL: goto x86_l_8f7;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2311ULL: goto x86_l_907;
	case 2317ULL: goto x86_l_90d;
	case 2320ULL: goto x86_l_910;
	case 2325ULL: goto x86_l_915;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2385ULL: goto x86_l_951;
	case 2388ULL: goto x86_l_954;
	case 2394ULL: goto x86_l_95a;
	case 2397ULL: goto x86_l_95d;
	case 2401ULL: goto x86_l_961;
	case 2410ULL: goto x86_l_96a;
	case 2419ULL: goto x86_l_973;
	case 2429ULL: goto x86_l_97d;
	case 2437ULL: goto x86_l_985;
	case 2442ULL: goto x86_l_98a;
	case 2449ULL: goto x86_l_991;
	case 2457ULL: goto x86_l_999;
	case 2459ULL: goto x86_l_99b;
	case 2462ULL: goto x86_l_99e;
	case 2464ULL: goto x86_l_9a0;
	case 2467ULL: goto x86_l_9a3;
	case 2471ULL: goto x86_l_9a7;
	case 2473ULL: goto x86_l_9a9;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2499ULL: goto x86_l_9c3;
	case 2507ULL: goto x86_l_9cb;
	case 2512ULL: goto x86_l_9d0;
	case 2514ULL: goto x86_l_9d2;
	case 2516ULL: goto x86_l_9d4;
	case 2519ULL: goto x86_l_9d7;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2531ULL: goto x86_l_9e3;
	case 2537ULL: goto x86_l_9e9;
	case 2542ULL: goto x86_l_9ee;
	case 2546ULL: goto x86_l_9f2;
	case 2548ULL: goto x86_l_9f4;
	case 2551ULL: goto x86_l_9f7;
	case 2553ULL: goto x86_l_9f9;
	case 2558ULL: goto x86_l_9fe;
	case 2561ULL: goto x86_l_a01;
	case 2569ULL: goto x86_l_a09;
	case 2572ULL: goto x86_l_a0c;
	case 2577ULL: goto x86_l_a11;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2587ULL: goto x86_l_a1b;
	case 2595ULL: goto x86_l_a23;
	case 2598ULL: goto x86_l_a26;
	case 2603ULL: goto x86_l_a2b;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2613ULL: goto x86_l_a35;
	case 2620ULL: goto x86_l_a3c;
	case 2626ULL: goto x86_l_a42;
	case 2628ULL: goto x86_l_a44;
	case 2633ULL: goto x86_l_a49;
	case 2637ULL: goto x86_l_a4d;
	case 2639ULL: goto x86_l_a4f;
	case 2647ULL: goto x86_l_a57;
	case 2655ULL: goto x86_l_a5f;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2667ULL: goto x86_l_a6b;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2676ULL: goto x86_l_a74;
	case 2678ULL: goto x86_l_a76;
	case 2680ULL: goto x86_l_a78;
	case 2687ULL: goto x86_l_a7f;
	case 2689ULL: goto x86_l_a81;
	case 2697ULL: goto x86_l_a89;
	case 2700ULL: goto x86_l_a8c;
	case 2702ULL: goto x86_l_a8e;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2717ULL: goto x86_l_a9d;
	case 2719ULL: goto x86_l_a9f;
	case 2721ULL: goto x86_l_aa1;
	case 2724ULL: goto x86_l_aa4;
	case 2730ULL: goto x86_l_aaa;
	case 2737ULL: goto x86_l_ab1;
	case 2740ULL: goto x86_l_ab4;
	case 2746ULL: goto x86_l_aba;
	case 2753ULL: goto x86_l_ac1;
	case 2757ULL: goto x86_l_ac5;
	case 2761ULL: goto x86_l_ac9;
	case 2766ULL: goto x86_l_ace;
	case 2771ULL: goto x86_l_ad3;
	case 2776ULL: goto x86_l_ad8;
	case 2781ULL: goto x86_l_add;
	case 2786ULL: goto x86_l_ae2;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2799ULL: goto x86_l_aef;
	case 2801ULL: goto x86_l_af1;
	case 2806ULL: goto x86_l_af6;
	case 2808ULL: goto x86_l_af8;
	case 2810ULL: goto x86_l_afa;
	case 2814ULL: goto x86_l_afe;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2823ULL: goto x86_l_b07;
	case 2825ULL: goto x86_l_b09;
	case 2829ULL: goto x86_l_b0d;
	case 2839ULL: goto x86_l_b17;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2851ULL: goto x86_l_b23;
	case 2854ULL: goto x86_l_b26;
	case 2859ULL: goto x86_l_b2b;
	case 2867ULL: goto x86_l_b33;
	case 2876ULL: goto x86_l_b3c;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2892ULL: goto x86_l_b4c;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2903ULL: goto x86_l_b57;
	case 2911ULL: goto x86_l_b5f;
	case 2918ULL: goto x86_l_b66;
	case 2921ULL: goto x86_l_b69;
	case 2923ULL: goto x86_l_b6b;
	case 2930ULL: goto x86_l_b72;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2940ULL: goto x86_l_b7c;
	case 2946ULL: goto x86_l_b82;
	case 2951ULL: goto x86_l_b87;
	case 2959ULL: goto x86_l_b8f;
	case 2961ULL: goto x86_l_b91;
	case 2964ULL: goto x86_l_b94;
	case 2966ULL: goto x86_l_b96;
	case 2969ULL: goto x86_l_b99;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2980ULL: goto x86_l_ba4;
	case 2985ULL: goto x86_l_ba9;
	case 2991ULL: goto x86_l_baf;
	case 2995ULL: goto x86_l_bb3;
	case 2998ULL: goto x86_l_bb6;
	case 3000ULL: goto x86_l_bb8;
	case 3007ULL: goto x86_l_bbf;
	case 3011ULL: goto x86_l_bc3;
	case 3015ULL: goto x86_l_bc7;
	case 3019ULL: goto x86_l_bcb;
	case 3022ULL: goto x86_l_bce;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3033ULL: goto x86_l_bd9;
	case 3037ULL: goto x86_l_bdd;
	case 3039ULL: goto x86_l_bdf;
	case 3044ULL: goto x86_l_be4;
	case 3046ULL: goto x86_l_be6;
	case 3048ULL: goto x86_l_be8;
	case 3052ULL: goto x86_l_bec;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3070ULL: goto x86_l_bfe;
	case 3074ULL: goto x86_l_c02;
	case 3077ULL: goto x86_l_c05;
	case 3085ULL: goto x86_l_c0d;
	case 3089ULL: goto x86_l_c11;
	case 3093ULL: goto x86_l_c15;
	case 3096ULL: goto x86_l_c18;
	case 3100ULL: goto x86_l_c1c;
	case 3107ULL: goto x86_l_c23;
	case 3110ULL: goto x86_l_c26;
	case 3112ULL: goto x86_l_c28;
	case 3119ULL: goto x86_l_c2f;
	case 3121ULL: goto x86_l_c31;
	case 3124ULL: goto x86_l_c34;
	case 3127ULL: goto x86_l_c37;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3143ULL: goto x86_l_c47;
	case 3145ULL: goto x86_l_c49;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3152ULL: goto x86_l_c50;
	case 3155ULL: goto x86_l_c53;
	case 3157ULL: goto x86_l_c55;
	case 3161ULL: goto x86_l_c59;
	case 3164ULL: goto x86_l_c5c;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3180ULL: goto x86_l_c6c;
	case 3183ULL: goto x86_l_c6f;
	case 3185ULL: goto x86_l_c71;
	case 3190ULL: goto x86_l_c76;
	case 3193ULL: goto x86_l_c79;
	case 3198ULL: goto x86_l_c7e;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3210ULL: goto x86_l_c8a;
	case 3213ULL: goto x86_l_c8d;
	case 3219ULL: goto x86_l_c93;
	case 3223ULL: goto x86_l_c97;
	case 3225ULL: goto x86_l_c99;
	case 3231ULL: goto x86_l_c9f;
	case 3234ULL: goto x86_l_ca2;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3259ULL: goto x86_l_cbb;
	case 3263ULL: goto x86_l_cbf;
	case 3269ULL: goto x86_l_cc5;
	case 3276ULL: goto x86_l_ccc;
	case 3280ULL: goto x86_l_cd0;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3293ULL: goto x86_l_cdd;
	case 3300ULL: goto x86_l_ce4;
	case 3302ULL: goto x86_l_ce6;
	case 3309ULL: goto x86_l_ced;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3326ULL: goto x86_l_cfe;
	case 3328ULL: goto x86_l_d00;
	case 3330ULL: goto x86_l_d02;
	case 3334ULL: goto x86_l_d06;
	case 3338ULL: goto x86_l_d0a;
	case 3340ULL: goto x86_l_d0c;
	case 3346ULL: goto x86_l_d12;
	case 3350ULL: goto x86_l_d16;
	case 3353ULL: goto x86_l_d19;
	case 3355ULL: goto x86_l_d1b;
	case 3360ULL: goto x86_l_d20;
	case 3362ULL: goto x86_l_d22;
	case 3364ULL: goto x86_l_d24;
	case 3368ULL: goto x86_l_d28;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3377ULL: goto x86_l_d31;
	case 3379ULL: goto x86_l_d33;
	case 3383ULL: goto x86_l_d37;
	case 3393ULL: goto x86_l_d41;
	case 3396ULL: goto x86_l_d44;
	case 3401ULL: goto x86_l_d49;
	case 3405ULL: goto x86_l_d4d;
	case 3408ULL: goto x86_l_d50;
	case 3416ULL: goto x86_l_d58;
	case 3420ULL: goto x86_l_d5c;
	case 3424ULL: goto x86_l_d60;
	case 3427ULL: goto x86_l_d63;
	case 3431ULL: goto x86_l_d67;
	case 3438ULL: goto x86_l_d6e;
	case 3441ULL: goto x86_l_d71;
	case 3443ULL: goto x86_l_d73;
	case 3450ULL: goto x86_l_d7a;
	case 3452ULL: goto x86_l_d7c;
	case 3455ULL: goto x86_l_d7f;
	case 3458ULL: goto x86_l_d82;
	case 3460ULL: goto x86_l_d84;
	case 3465ULL: goto x86_l_d89;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3477ULL: goto x86_l_d95;
	case 3479ULL: goto x86_l_d97;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3493ULL: goto x86_l_da5;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3502ULL: goto x86_l_dae;
	case 3506ULL: goto x86_l_db2;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3535ULL: goto x86_l_dcf;
	case 3540ULL: goto x86_l_dd4;
	case 3542ULL: goto x86_l_dd6;
	case 3545ULL: goto x86_l_dd9;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3554ULL: goto x86_l_de2;
	case 3559ULL: goto x86_l_de7;
	case 3565ULL: goto x86_l_ded;
	default: return 0xffffffffffffffffULL;
	}
x86_l_76f:
	/* 0x76f: jb     7eb <tail_handle_ipv4_from_netdev+0x7eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7eb;
	}
x86_l_771:
	/* 0x771: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_774:
	/* 0x774: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_779:
	/* 0x779: movzx  esi,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_77c:
	/* 0x77c: add    esi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_77f:
	/* 0x77f: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_787:
	/* 0x787: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_78a:
	/* 0x78a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_78f:
	/* 0x78f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_791:
	/* 0x791: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_793:
	/* 0x793: js     806 <tail_handle_ipv4_from_netdev+0x806> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_806;
	}
x86_l_795:
	/* 0x795: cmp    BYTE PTR [rsp+0x80],0x9a */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 549755814042ULL);
x86_l_79d:
	/* 0x79d: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_7a7:
	/* 0x7a7: mov    r10,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ac:
	/* 0x7ac: mov    r8,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_7b3:
	/* 0x7b3: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_7bd:
	/* 0x7bd: jne    7eb <tail_handle_ipv4_from_netdev+0x7eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7eb;
	}
x86_l_7bf:
	/* 0x7bf: cmp    BYTE PTR [rsp+0x81],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 554050781192ULL);
x86_l_7c7:
	/* 0x7c7: jne    7eb <tail_handle_ipv4_from_netdev+0x7eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7eb;
	}
x86_l_7c9:
	/* 0x7c9: mov    eax,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_7d0:
	/* 0x7d0: movbe  DWORD PTR [rsp+0x70],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 112ULL);
x86_l_7d6:
	/* 0x7d6: movzx  eax,WORD PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 130ULL);
x86_l_7de:
	/* 0x7de: movbe  WORD PTR [rsp+0x74],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_7e5:
	/* 0x7e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e7:
	/* 0x7e7: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_7e9:
	/* 0x7e9: jmp    82d <tail_handle_ipv4_from_netdev+0x82d> */
	goto x86_l_82d;
x86_l_7eb:
	/* 0x7eb: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_7f0:
	/* 0x7f0: jne    8f7 <tail_handle_ipv4_from_netdev+0x8f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f7;
	}
x86_l_7f6:
	/* 0x7f6: cmp    BYTE PTR [rsp+0x44],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 292057776134ULL);
x86_l_7fb:
	/* 0x7fb: jne    835 <tail_handle_ipv4_from_netdev+0x835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_835;
	}
x86_l_7fd:
	/* 0x7fd: mov    rdi,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_804:
	/* 0x804: jmp    83c <tail_handle_ipv4_from_netdev+0x83c> */
	goto x86_l_83c;
x86_l_806:
	/* 0x806: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_80b:
	/* 0x80b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80d:
	/* 0x80d: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_817:
	/* 0x817: mov    r10,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81c:
	/* 0x81c: mov    r8,QWORD PTR [rip+0xae0a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_823:
	/* 0x823: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_82d:
	/* 0x82d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_830:
	/* 0x830: jmp    8b3 <tail_handle_ipv4_from_netdev+0x8b3> */
	goto x86_l_8b3;
x86_l_835:
	/* 0x835: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_83c:
	/* 0x83c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_841:
	/* 0x841: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_846:
	/* 0x846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_848:
	/* 0x848: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_84b:
	/* 0x84b: je     8f7 <tail_handle_ipv4_from_netdev+0x8f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f7;
	}
x86_l_851:
	/* 0x851: and    BYTE PTR [rax+0x24],0x7f */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 154618822783ULL);
x86_l_855:
	/* 0x855: jmp    8f7 <tail_handle_ipv4_from_netdev+0x8f7> */
	goto x86_l_8f7;
x86_l_85a:
	/* 0x85a: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_861:
	/* 0x861: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_866:
	/* 0x866: mov    BYTE PTR [rsp+0x45],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 296352743424ULL);
x86_l_86b:
	/* 0x86b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_870:
	/* 0x870: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_875:
	/* 0x875: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_877:
	/* 0x877: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_879:
	/* 0x879: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_87c:
	/* 0x87c: je     887 <tail_handle_ipv4_from_netdev+0x887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_887;
	}
x86_l_87e:
	/* 0x87e: movzx  eax,BYTE PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_882:
	/* 0x882: shr    al,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 7ULL);
x86_l_885:
	/* 0x885: jmp    889 <tail_handle_ipv4_from_netdev+0x889> */
	goto x86_l_889;
x86_l_887:
	/* 0x887: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_889:
	/* 0x889: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_893:
	/* 0x893: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_896:
	/* 0x896: mov    r10,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_89b:
	/* 0x89b: mov    r8,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_8a2:
	/* 0x8a2: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_8ac:
	/* 0x8ac: mov    WORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_8b3:
	/* 0x8b3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b6:
	/* 0x8b6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_8b8:
	/* 0x8b8: js     91c <tail_handle_ipv4_from_netdev+0x91c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_91c;
	}
x86_l_8ba:
	/* 0x8ba: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_8bc:
	/* 0x8bc: je     8f7 <tail_handle_ipv4_from_netdev+0x8f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f7;
	}
x86_l_8be:
	/* 0x8be: rol    QWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 137438953504ULL);
x86_l_8c4:
	/* 0x8c4: rol    DWORD PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 171798691856ULL);
x86_l_8c9:
	/* 0x8c9: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8cd:
	/* 0x8cd: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_8d5:
	/* 0x8d5: movzx  eax,WORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_8da:
	/* 0x8da: mov    WORD PTR [rsp+0xa8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8e2:
	/* 0x8e2: movzx  r14d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_8e8:
	/* 0x8e8: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_8ec:
	/* 0x8ec: jne    926 <tail_handle_ipv4_from_netdev+0x926> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_926;
	}
x86_l_8ee:
	/* 0x8ee: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_8f5:
	/* 0x8f5: jmp    92d <tail_handle_ipv4_from_netdev+0x92d> */
	goto x86_l_92d;
x86_l_8f7:
	/* 0x8f7: mov    DWORD PTR [rbx+0x28],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8fb:
	/* 0x8fb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_900:
	/* 0x900: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_907:
	/* 0x907: mov    r13d,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 36ULL);
x86_l_90d:
	/* 0x90d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_910:
	/* 0x910: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_915:
	/* 0x915: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_917:
	/* 0x917: mov    ecx,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967156ULL);
x86_l_91c:
	/* 0x91c: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_91e:
	/* 0x91e: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_921:
	/* 0x921: jmp    48 <tail_handle_ipv4_from_netdev+0x48> */
	return 72ULL;
x86_l_926:
	/* 0x926: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_92d:
	/* 0x92d: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_932:
	/* 0x932: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_93d:
	/* 0x93d: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_941:
	/* 0x941: mov    BYTE PTR [rsp+0x10],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_946:
	/* 0x946: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_94b:
	/* 0x94b: je     9ee <tail_handle_ipv4_from_netdev+0x9ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ee;
	}
x86_l_951:
	/* 0x951: and    r9,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_954:
	/* 0x954: je     9ee <tail_handle_ipv4_from_netdev+0x9ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ee;
	}
x86_l_95a:
	/* 0x95a: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_95d:
	/* 0x95d: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_961:
	/* 0x961: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_96a:
	/* 0x96a: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_973:
	/* 0x973: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_97d:
	/* 0x97d: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_985:
	/* 0x985: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_98a:
	/* 0x98a: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_991:
	/* 0x991: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_999:
	/* 0x999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99b:
	/* 0x99b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99e:
	/* 0x99e: je     9a9 <tail_handle_ipv4_from_netdev+0x9a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a9;
	}
x86_l_9a0:
	/* 0x9a0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9a3:
	/* 0x9a3: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9a7:
	/* 0x9a7: jmp    9d4 <tail_handle_ipv4_from_netdev+0x9d4> */
	goto x86_l_9d4;
x86_l_9a9:
	/* 0x9a9: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_9b2:
	/* 0x9b2: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9b7:
	/* 0x9b7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9bc:
	/* 0x9bc: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9c3:
	/* 0x9c3: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9cb:
	/* 0x9cb: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9d0:
	/* 0x9d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9d2:
	/* 0x9d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d4:
	/* 0x9d4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_9d7:
	/* 0x9d7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9db:
	/* 0x9db: mov    r10,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e0:
	/* 0x9e0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9e3:
	/* 0x9e3: movzx  r14d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_9e9:
	/* 0x9e9: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ee:
	/* 0x9ee: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_9f2:
	/* 0x9f2: jne    a4f <tail_handle_ipv4_from_netdev+0xa4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a4f;
	}
x86_l_9f4:
	/* 0x9f4: and    r10,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_9f7:
	/* 0x9f7: jne    a4f <tail_handle_ipv4_from_netdev+0xa4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a4f;
	}
x86_l_9f9:
	/* 0x9f9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9fe:
	/* 0x9fe: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_a01:
	/* 0xa01: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a09:
	/* 0xa09: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a0c:
	/* 0xa0c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a11:
	/* 0xa11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a13:
	/* 0xa13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a15:
	/* 0xa15: js     ad8 <tail_handle_ipv4_from_netdev+0xad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ad8;
	}
x86_l_a1b:
	/* 0xa1b: mov    r14d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a23:
	/* 0xa23: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a26:
	/* 0xa26: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_a2b:
	/* 0xa2b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a2d:
	/* 0xa2d: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_a32:
	/* 0xa32: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_a35:
	/* 0xa35: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_a3c:
	/* 0xa3c: jne    1382 <tail_handle_ipv4_from_netdev+0x1382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4994ULL;
	}
x86_l_a42:
	/* 0xa42: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_a44:
	/* 0xa44: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a49:
	/* 0xa49: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4d:
	/* 0xa4d: jmp    a5f <tail_handle_ipv4_from_netdev+0xa5f> */
	goto x86_l_a5f;
x86_l_a4f:
	/* 0xa4f: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a57:
	/* 0xa57: mov    r14d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a5f:
	/* 0xa5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a64:
	/* 0xa64: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a69:
	/* 0xa69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6b:
	/* 0xa6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6e:
	/* 0xa6e: je     a78 <tail_handle_ipv4_from_netdev+0xa78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a78;
	}
x86_l_a70:
	/* 0xa70: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a74:
	/* 0xa74: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_a76:
	/* 0xa76: js     a99 <tail_handle_ipv4_from_netdev+0xa99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a99;
	}
x86_l_a78:
	/* 0xa78: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_a7f:
	/* 0xa7f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a81:
	/* 0xa81: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_a89:
	/* 0xa89: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_a8c:
	/* 0xa8c: je     ace <tail_handle_ipv4_from_netdev+0xace> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ace;
	}
x86_l_a8e:
	/* 0xa8e: movzx  r13d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_a94:
	/* 0xa94: jmp    1160 <tail_handle_ipv4_from_netdev+0x1160> */
	return 4448ULL;
x86_l_a99:
	/* 0xa99: mov    DWORD PTR [rsp],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9d:
	/* 0xa9d: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a9f:
	/* 0xa9f: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_aa1:
	/* 0xaa1: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_aa4:
	/* 0xaa4: je     fbd <tail_handle_ipv4_from_netdev+0xfbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4029ULL;
	}
x86_l_aaa:
	/* 0xaaa: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ab1:
	/* 0xab1: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab4:
	/* 0xab4: je     edb <tail_handle_ipv4_from_netdev+0xedb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3803ULL;
	}
x86_l_aba:
	/* 0xaba: mov    rdx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ac1:
	/* 0xac1: imul   r13d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_ac5:
	/* 0xac5: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ac9:
	/* 0xac9: jmp    ee1 <tail_handle_ipv4_from_netdev+0xee1> */
	return 3809ULL;
x86_l_ace:
	/* 0xace: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_ad3:
	/* 0xad3: jmp    91c <tail_handle_ipv4_from_netdev+0x91c> */
	goto x86_l_91c;
x86_l_ad8:
	/* 0xad8: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_add:
	/* 0xadd: jmp    91c <tail_handle_ipv4_from_netdev+0x91c> */
	goto x86_l_91c;
x86_l_ae2:
	/* 0xae2: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_ae8:
	/* 0xae8: add    r14d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_aec:
	/* 0xaec: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aef:
	/* 0xaef: je     b00 <tail_handle_ipv4_from_netdev+0xb00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b00;
	}
x86_l_af1:
	/* 0xaf1: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_af6:
	/* 0xaf6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af8:
	/* 0xaf8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_afa:
	/* 0xafa: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_afe:
	/* 0xafe: jmp    b23 <tail_handle_ipv4_from_netdev+0xb23> */
	goto x86_l_b23;
x86_l_b00:
	/* 0xb00: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_b05:
	/* 0xb05: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b07:
	/* 0xb07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b09:
	/* 0xb09: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_b0d:
	/* 0xb0d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_b17:
	/* 0xb17: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_b1a:
	/* 0xb1a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_b1f:
	/* 0xb1f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_b23:
	/* 0xb23: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_b26:
	/* 0xb26: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b2b:
	/* 0xb2b: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b33:
	/* 0xb33: movzx  r14d,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_b3c:
	/* 0xb3c: jae    1474 <tail_handle_ipv4_from_netdev+0x1474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5236ULL;
	}
x86_l_b42:
	/* 0xb42: mov    DWORD PTR [rsp+0x18],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b47:
	/* 0xb47: mov    eax,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b4a:
	/* 0xb4a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b4c:
	/* 0xb4c: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b4e:
	/* 0xb4e: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_b51:
	/* 0xb51: je     c65 <tail_handle_ipv4_from_netdev+0xc65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c65;
	}
x86_l_b57:
	/* 0xb57: mov    BYTE PTR [rsp+0x90],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b5f:
	/* 0xb5f: mov    rdx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b66:
	/* 0xb66: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b69:
	/* 0xb69: je     b7c <tail_handle_ipv4_from_netdev+0xb7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b7c;
	}
x86_l_b6b:
	/* 0xb6b: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b72:
	/* 0xb72: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_b76:
	/* 0xb76: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b7a:
	/* 0xb7a: jmp    b82 <tail_handle_ipv4_from_netdev+0xb82> */
	goto x86_l_b82;
x86_l_b7c:
	/* 0xb7c: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_b82:
	/* 0xb82: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b87:
	/* 0xb87: cmp    BYTE PTR [rsp+0x90],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290630ULL);
x86_l_b8f:
	/* 0xb8f: jne    bc7 <tail_handle_ipv4_from_netdev+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bc7;
	}
x86_l_b91:
	/* 0xb91: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_b94:
	/* 0xb94: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b96:
	/* 0xb96: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_b99:
	/* 0xb99: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_b9c:
	/* 0xb9c: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_b9e:
	/* 0xb9e: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ba2:
	/* 0xba2: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_ba4:
	/* 0xba4: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_ba9:
	/* 0xba9: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_baf:
	/* 0xbaf: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_bb3:
	/* 0xbb3: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb6:
	/* 0xbb6: je     bc7 <tail_handle_ipv4_from_netdev+0xbc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bc7;
	}
x86_l_bb8:
	/* 0xbb8: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bbf:
	/* 0xbbf: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_bc3:
	/* 0xbc3: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bc7:
	/* 0xbc7: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bcb:
	/* 0xbcb: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bce:
	/* 0xbce: je     bdf <tail_handle_ipv4_from_netdev+0xbdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bdf;
	}
x86_l_bd0:
	/* 0xbd0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bd5:
	/* 0xbd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd7:
	/* 0xbd7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bd9:
	/* 0xbd9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bdd:
	/* 0xbdd: jmp    c02 <tail_handle_ipv4_from_netdev+0xc02> */
	goto x86_l_c02;
x86_l_bdf:
	/* 0xbdf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_be4:
	/* 0xbe4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be6:
	/* 0xbe6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_be8:
	/* 0xbe8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_bec:
	/* 0xbec: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_bf6:
	/* 0xbf6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bf9:
	/* 0xbf9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bfe:
	/* 0xbfe: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c02:
	/* 0xc02: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c05:
	/* 0xc05: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c0d:
	/* 0xc0d: mov    DWORD PTR [rdi+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c11:
	/* 0xc11: movzx  ecx,BYTE PTR [rdi+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_c15:
	/* 0xc15: mov    edx,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c18:
	/* 0xc18: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c1c:
	/* 0xc1c: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c23:
	/* 0xc23: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c26:
	/* 0xc26: je     c39 <tail_handle_ipv4_from_netdev+0xc39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c39;
	}
x86_l_c28:
	/* 0xc28: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c2f:
	/* 0xc2f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c31:
	/* 0xc31: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c34:
	/* 0xc34: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c37:
	/* 0xc37: jmp    c3e <tail_handle_ipv4_from_netdev+0xc3e> */
	goto x86_l_c3e;
x86_l_c39:
	/* 0xc39: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c3e:
	/* 0xc3e: movzx  r14d,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_c47:
	/* 0xc47: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c49:
	/* 0xc49: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c4c:
	/* 0xc4c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c4e:
	/* 0xc4e: jb     c55 <tail_handle_ipv4_from_netdev+0xc55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c55;
	}
x86_l_c50:
	/* 0xc50: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_c53:
	/* 0xc53: je     c65 <tail_handle_ipv4_from_netdev+0xc65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c65;
	}
x86_l_c55:
	/* 0xc55: mov    BYTE PTR [rdi+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_c59:
	/* 0xc59: mov    DWORD PTR [rdi+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c5c:
	/* 0xc5c: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c63:
	/* 0xc63: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c65:
	/* 0xc65: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_c6c:
	/* 0xc6c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6f:
	/* 0xc6f: je     c7e <tail_handle_ipv4_from_netdev+0xc7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7e;
	}
x86_l_c71:
	/* 0xc71: inc QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_c76:
	/* 0xc76: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c79:
	/* 0xc79: add QWORD PTR [rdi+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RDI, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_c7e:
	/* 0xc7e: mov    eax,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_c85:
	/* 0xc85: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c88:
	/* 0xc88: je     cd9 <tail_handle_ipv4_from_netdev+0xcd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cd9;
	}
x86_l_c8a:
	/* 0xc8a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c8d:
	/* 0xc8d: jne    da7 <tail_handle_ipv4_from_netdev+0xda7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_da7;
	}
x86_l_c93:
	/* 0xc93: movzx  eax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_c97:
	/* 0xc97: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_c99:
	/* 0xc99: je     da7 <tail_handle_ipv4_from_netdev+0xda7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da7;
	}
x86_l_c9f:
	/* 0xc9f: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_ca2:
	/* 0xca2: mov    WORD PTR [rdi+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_ca8:
	/* 0xca8: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_cad:
	/* 0xcad: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_cb0:
	/* 0xcb0: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cb4:
	/* 0xcb4: mov    r15,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_cbb:
	/* 0xcbb: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cbf:
	/* 0xcbf: je     138c <tail_handle_ipv4_from_netdev+0x138c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5004ULL;
	}
x86_l_cc5:
	/* 0xcc5: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ccc:
	/* 0xccc: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_cd0:
	/* 0xcd0: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_cd4:
	/* 0xcd4: jmp    1392 <tail_handle_ipv4_from_netdev+0x1392> */
	return 5010ULL;
x86_l_cd9:
	/* 0xcd9: or     BYTE PTR [rdi+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDI, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_cdd:
	/* 0xcdd: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_ce4:
	/* 0xce4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce6:
	/* 0xce6: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ced:
	/* 0xced: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf0:
	/* 0xcf0: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cf5:
	/* 0xcf5: je     d0c <tail_handle_ipv4_from_netdev+0xd0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d0c;
	}
x86_l_cf7:
	/* 0xcf7: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_cfe:
	/* 0xcfe: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d00:
	/* 0xd00: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d02:
	/* 0xd02: lea    r14d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_d06:
	/* 0xd06: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d0a:
	/* 0xd0a: jmp    d12 <tail_handle_ipv4_from_netdev+0xd12> */
	goto x86_l_d12;
x86_l_d0c:
	/* 0xd0c: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_d12:
	/* 0xd12: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d16:
	/* 0xd16: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d19:
	/* 0xd19: je     d2a <tail_handle_ipv4_from_netdev+0xd2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d2a;
	}
x86_l_d1b:
	/* 0xd1b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d20:
	/* 0xd20: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d22:
	/* 0xd22: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d24:
	/* 0xd24: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d28:
	/* 0xd28: jmp    d4d <tail_handle_ipv4_from_netdev+0xd4d> */
	goto x86_l_d4d;
x86_l_d2a:
	/* 0xd2a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d2f:
	/* 0xd2f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d31:
	/* 0xd31: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d33:
	/* 0xd33: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d37:
	/* 0xd37: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d41:
	/* 0xd41: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d44:
	/* 0xd44: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d49:
	/* 0xd49: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d4d:
	/* 0xd4d: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d50:
	/* 0xd50: mov    rdi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d58:
	/* 0xd58: mov    DWORD PTR [rdi+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d5c:
	/* 0xd5c: movzx  ecx,BYTE PTR [rdi+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_d60:
	/* 0xd60: mov    edx,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d63:
	/* 0xd63: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_d67:
	/* 0xd67: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d6e:
	/* 0xd6e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d71:
	/* 0xd71: je     d84 <tail_handle_ipv4_from_netdev+0xd84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d84;
	}
x86_l_d73:
	/* 0xd73: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d7a:
	/* 0xd7a: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7c:
	/* 0xd7c: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_d7f:
	/* 0xd7f: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d82:
	/* 0xd82: jmp    d89 <tail_handle_ipv4_from_netdev+0xd89> */
	goto x86_l_d89;
x86_l_d84:
	/* 0xd84: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_d89:
	/* 0xd89: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d8b:
	/* 0xd8b: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_d8e:
	/* 0xd8e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_d90:
	/* 0xd90: jb     d97 <tail_handle_ipv4_from_netdev+0xd97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d97;
	}
x86_l_d92:
	/* 0xd92: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_d95:
	/* 0xd95: je     da7 <tail_handle_ipv4_from_netdev+0xda7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da7;
	}
x86_l_d97:
	/* 0xd97: mov    BYTE PTR [rdi+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_d9b:
	/* 0xd9b: mov    DWORD PTR [rdi+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d9e:
	/* 0xd9e: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_da5:
	/* 0xda5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da7:
	/* 0xda7: test   BYTE PTR [rsp+0x2d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528322ULL);
x86_l_dac:
	/* 0xdac: jne    dfc <tail_handle_ipv4_from_netdev+0xdfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3580ULL;
	}
x86_l_dae:
	/* 0xdae: movzx  eax,WORD PTR [rdi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_db2:
	/* 0xdb2: mov    WORD PTR [rsp+0xb8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_dba:
	/* 0xdba: mov    r13d,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dbe:
	/* 0xdbe: mov    DWORD PTR [rsp+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dc3:
	/* 0xdc3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dc8:
	/* 0xdc8: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_dcf:
	/* 0xdcf: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dd4:
	/* 0xdd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd6:
	/* 0xdd6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dd9:
	/* 0xdd9: je     e06 <tail_handle_ipv4_from_netdev+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3590ULL;
	}
x86_l_ddb:
	/* 0xddb: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_dde:
	/* 0xdde: cmp    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_de2:
	/* 0xde2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de7:
	/* 0xde7: je     184b <tail_handle_ipv4_from_netdev+0x184b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6219ULL;
	}
x86_l_ded:
	/* 0xded: test   DWORD PTR [rsp+0x18],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215616ULL);
	return 3573ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3573ULL: goto x86_l_df5;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3597ULL: goto x86_l_e0d;
	case 3600ULL: goto x86_l_e10;
	case 3605ULL: goto x86_l_e15;
	case 3610ULL: goto x86_l_e1a;
	case 3616ULL: goto x86_l_e20;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3629ULL: goto x86_l_e2d;
	case 3631ULL: goto x86_l_e2f;
	case 3636ULL: goto x86_l_e34;
	case 3638ULL: goto x86_l_e36;
	case 3640ULL: goto x86_l_e38;
	case 3642ULL: goto x86_l_e3a;
	case 3647ULL: goto x86_l_e3f;
	case 3654ULL: goto x86_l_e46;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3670ULL: goto x86_l_e56;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3708ULL: goto x86_l_e7c;
	case 3713ULL: goto x86_l_e81;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3724ULL: goto x86_l_e8c;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3762ULL: goto x86_l_eb2;
	case 3771ULL: goto x86_l_ebb;
	case 3773ULL: goto x86_l_ebd;
	case 3776ULL: goto x86_l_ec0;
	case 3780ULL: goto x86_l_ec4;
	case 3785ULL: goto x86_l_ec9;
	case 3790ULL: goto x86_l_ece;
	case 3798ULL: goto x86_l_ed6;
	case 3803ULL: goto x86_l_edb;
	case 3809ULL: goto x86_l_ee1;
	case 3813ULL: goto x86_l_ee5;
	case 3818ULL: goto x86_l_eea;
	case 3820ULL: goto x86_l_eec;
	case 3823ULL: goto x86_l_eef;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3837ULL: goto x86_l_efd;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3851ULL: goto x86_l_f0b;
	case 3855ULL: goto x86_l_f0f;
	case 3858ULL: goto x86_l_f12;
	case 3860ULL: goto x86_l_f14;
	case 3867ULL: goto x86_l_f1b;
	case 3871ULL: goto x86_l_f1f;
	case 3875ULL: goto x86_l_f23;
	case 3880ULL: goto x86_l_f28;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3896ULL: goto x86_l_f38;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3905ULL: goto x86_l_f41;
	case 3907ULL: goto x86_l_f43;
	case 3912ULL: goto x86_l_f48;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3920ULL: goto x86_l_f50;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3938ULL: goto x86_l_f62;
	case 3942ULL: goto x86_l_f66;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3954ULL: goto x86_l_f72;
	case 3958ULL: goto x86_l_f76;
	case 3961ULL: goto x86_l_f79;
	case 3965ULL: goto x86_l_f7d;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3984ULL: goto x86_l_f90;
	case 3986ULL: goto x86_l_f92;
	case 3989ULL: goto x86_l_f95;
	case 3992ULL: goto x86_l_f98;
	case 3994ULL: goto x86_l_f9a;
	case 3999ULL: goto x86_l_f9f;
	case 4001ULL: goto x86_l_fa1;
	case 4004ULL: goto x86_l_fa4;
	case 4006ULL: goto x86_l_fa6;
	case 4008ULL: goto x86_l_fa8;
	case 4011ULL: goto x86_l_fab;
	case 4013ULL: goto x86_l_fad;
	case 4017ULL: goto x86_l_fb1;
	case 4020ULL: goto x86_l_fb4;
	case 4027ULL: goto x86_l_fbb;
	case 4029ULL: goto x86_l_fbd;
	case 4036ULL: goto x86_l_fc4;
	case 4039ULL: goto x86_l_fc7;
	case 4041ULL: goto x86_l_fc9;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4058ULL: goto x86_l_fda;
	case 4061ULL: goto x86_l_fdd;
	case 4068ULL: goto x86_l_fe4;
	case 4076ULL: goto x86_l_fec;
	case 4078ULL: goto x86_l_fee;
	case 4081ULL: goto x86_l_ff1;
	case 4087ULL: goto x86_l_ff7;
	case 4091ULL: goto x86_l_ffb;
	case 4094ULL: goto x86_l_ffe;
	case 4100ULL: goto x86_l_1004;
	case 4106ULL: goto x86_l_100a;
	case 4112ULL: goto x86_l_1010;
	case 4115ULL: goto x86_l_1013;
	case 4119ULL: goto x86_l_1017;
	case 4126ULL: goto x86_l_101e;
	case 4130ULL: goto x86_l_1022;
	case 4136ULL: goto x86_l_1028;
	case 4143ULL: goto x86_l_102f;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4165ULL: goto x86_l_1045;
	case 4168ULL: goto x86_l_1048;
	case 4172ULL: goto x86_l_104c;
	case 4176ULL: goto x86_l_1050;
	case 4180ULL: goto x86_l_1054;
	case 4184ULL: goto x86_l_1058;
	case 4191ULL: goto x86_l_105f;
	case 4193ULL: goto x86_l_1061;
	case 4201ULL: goto x86_l_1069;
	case 4204ULL: goto x86_l_106c;
	case 4210ULL: goto x86_l_1072;
	case 4217ULL: goto x86_l_1079;
	case 4220ULL: goto x86_l_107c;
	case 4222ULL: goto x86_l_107e;
	case 4229ULL: goto x86_l_1085;
	case 4231ULL: goto x86_l_1087;
	case 4233ULL: goto x86_l_1089;
	case 4237ULL: goto x86_l_108d;
	case 4241ULL: goto x86_l_1091;
	case 4243ULL: goto x86_l_1093;
	case 4249ULL: goto x86_l_1099;
	case 4252ULL: goto x86_l_109c;
	case 4256ULL: goto x86_l_10a0;
	case 4259ULL: goto x86_l_10a3;
	case 4261ULL: goto x86_l_10a5;
	case 4266ULL: goto x86_l_10aa;
	case 4268ULL: goto x86_l_10ac;
	case 4270ULL: goto x86_l_10ae;
	case 4274ULL: goto x86_l_10b2;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4283ULL: goto x86_l_10bb;
	case 4285ULL: goto x86_l_10bd;
	case 4289ULL: goto x86_l_10c1;
	case 4299ULL: goto x86_l_10cb;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4311ULL: goto x86_l_10d7;
	case 4314ULL: goto x86_l_10da;
	case 4318ULL: goto x86_l_10de;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4334ULL: goto x86_l_10ee;
	case 4337ULL: goto x86_l_10f1;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4349ULL: goto x86_l_10fd;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4361ULL: goto x86_l_1109;
	case 4364ULL: goto x86_l_110c;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4390ULL: goto x86_l_1126;
	case 4398ULL: goto x86_l_112e;
	case 4405ULL: goto x86_l_1135;
	case 4407ULL: goto x86_l_1137;
	case 4410ULL: goto x86_l_113a;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4419ULL: goto x86_l_1143;
	case 4423ULL: goto x86_l_1147;
	case 4425ULL: goto x86_l_1149;
	case 4428ULL: goto x86_l_114c;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4442ULL: goto x86_l_115a;
	case 4448ULL: goto x86_l_1160;
	case 4452ULL: goto x86_l_1164;
	case 4454ULL: goto x86_l_1166;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4484ULL: goto x86_l_1184;
	case 4493ULL: goto x86_l_118d;
	case 4502ULL: goto x86_l_1196;
	case 4511ULL: goto x86_l_119f;
	case 4520ULL: goto x86_l_11a8;
	case 4528ULL: goto x86_l_11b0;
	case 4536ULL: goto x86_l_11b8;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4566ULL: goto x86_l_11d6;
	case 4573ULL: goto x86_l_11dd;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4585ULL: goto x86_l_11e9;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4595ULL: goto x86_l_11f3;
	case 4601ULL: goto x86_l_11f9;
	case 4605ULL: goto x86_l_11fd;
	case 4607ULL: goto x86_l_11ff;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4619ULL: goto x86_l_120b;
	case 4626ULL: goto x86_l_1212;
	case 4630ULL: goto x86_l_1216;
	case 4634ULL: goto x86_l_121a;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4645ULL: goto x86_l_1225;
	case 4647ULL: goto x86_l_1227;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4660ULL: goto x86_l_1234;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4669ULL: goto x86_l_123d;
	case 4671ULL: goto x86_l_123f;
	case 4675ULL: goto x86_l_1243;
	case 4685ULL: goto x86_l_124d;
	case 4688ULL: goto x86_l_1250;
	case 4693ULL: goto x86_l_1255;
	case 4697ULL: goto x86_l_1259;
	case 4701ULL: goto x86_l_125d;
	case 4704ULL: goto x86_l_1260;
	case 4707ULL: goto x86_l_1263;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4721ULL: goto x86_l_1271;
	case 4723ULL: goto x86_l_1273;
	case 4730ULL: goto x86_l_127a;
	case 4733ULL: goto x86_l_127d;
	case 4735ULL: goto x86_l_127f;
	case 4742ULL: goto x86_l_1286;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4752ULL: goto x86_l_1290;
	case 4754ULL: goto x86_l_1292;
	case 4760ULL: goto x86_l_1298;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4775ULL: goto x86_l_12a7;
	case 4777ULL: goto x86_l_12a9;
	case 4780ULL: goto x86_l_12ac;
	case 4782ULL: goto x86_l_12ae;
	case 4784ULL: goto x86_l_12b0;
	case 4786ULL: goto x86_l_12b2;
	case 4790ULL: goto x86_l_12b6;
	case 4794ULL: goto x86_l_12ba;
	case 4801ULL: goto x86_l_12c1;
	case 4803ULL: goto x86_l_12c3;
	case 4810ULL: goto x86_l_12ca;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4824ULL: goto x86_l_12d8;
	case 4827ULL: goto x86_l_12db;
	case 4832ULL: goto x86_l_12e0;
	case 4837ULL: goto x86_l_12e5;
	case 4842ULL: goto x86_l_12ea;
	case 4847ULL: goto x86_l_12ef;
	case 4849ULL: goto x86_l_12f1;
	case 4851ULL: goto x86_l_12f3;
	case 4853ULL: goto x86_l_12f5;
	case 4859ULL: goto x86_l_12fb;
	case 4862ULL: goto x86_l_12fe;
	case 4867ULL: goto x86_l_1303;
	case 4872ULL: goto x86_l_1308;
	case 4877ULL: goto x86_l_130d;
	case 4884ULL: goto x86_l_1314;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4897ULL: goto x86_l_1321;
	case 4899ULL: goto x86_l_1323;
	case 4901ULL: goto x86_l_1325;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4931ULL: goto x86_l_1343;
	case 4936ULL: goto x86_l_1348;
	case 4945ULL: goto x86_l_1351;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4962ULL: goto x86_l_1362;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4977ULL: goto x86_l_1371;
	case 4979ULL: goto x86_l_1373;
	case 4984ULL: goto x86_l_1378;
	case 4989ULL: goto x86_l_137d;
	case 4994ULL: goto x86_l_1382;
	case 4999ULL: goto x86_l_1387;
	case 5004ULL: goto x86_l_138c;
	case 5010ULL: goto x86_l_1392;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5027ULL: goto x86_l_13a3;
	case 5029ULL: goto x86_l_13a5;
	case 5034ULL: goto x86_l_13aa;
	case 5036ULL: goto x86_l_13ac;
	case 5041ULL: goto x86_l_13b1;
	case 5047ULL: goto x86_l_13b7;
	case 5051ULL: goto x86_l_13bb;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5064ULL: goto x86_l_13c8;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5081ULL: goto x86_l_13d9;
	case 5083ULL: goto x86_l_13db;
	case 5088ULL: goto x86_l_13e0;
	case 5090ULL: goto x86_l_13e2;
	case 5092ULL: goto x86_l_13e4;
	case 5096ULL: goto x86_l_13e8;
	case 5098ULL: goto x86_l_13ea;
	case 5103ULL: goto x86_l_13ef;
	case 5105ULL: goto x86_l_13f1;
	case 5107ULL: goto x86_l_13f3;
	case 5111ULL: goto x86_l_13f7;
	case 5121ULL: goto x86_l_1401;
	case 5124ULL: goto x86_l_1404;
	case 5129ULL: goto x86_l_1409;
	case 5133ULL: goto x86_l_140d;
	case 5136ULL: goto x86_l_1410;
	case 5139ULL: goto x86_l_1413;
	case 5143ULL: goto x86_l_1417;
	case 5148ULL: goto x86_l_141c;
	case 5152ULL: goto x86_l_1420;
	case 5156ULL: goto x86_l_1424;
	case 5160ULL: goto x86_l_1428;
	case 5164ULL: goto x86_l_142c;
	case 5168ULL: goto x86_l_1430;
	default: return 0xffffffffffffffffULL;
	}
x86_l_df5:
	/* 0xdf5: jne    e15 <tail_handle_ipv4_from_netdev+0xe15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e15;
	}
x86_l_df7:
	/* 0xdf7: jmp    184b <tail_handle_ipv4_from_netdev+0x184b> */
	return 6219ULL;
x86_l_dfc:
	/* 0xdfc: mov    esi,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967133ULL);
x86_l_e01:
	/* 0xe01: jmp    1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	return 7542ULL;
x86_l_e06:
	/* 0xe06: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_e0d:
	/* 0xe0d: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e10:
	/* 0xe10: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e15:
	/* 0xe15: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_e1a:
	/* 0xe1a: je     16dd <tail_handle_ipv4_from_netdev+0x16dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5853ULL;
	}
x86_l_e20:
	/* 0xe20: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_e25:
	/* 0xe25: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e28:
	/* 0xe28: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e2a:
	/* 0xe2a: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_e2d:
	/* 0xe2d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e2f:
	/* 0xe2f: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_e34:
	/* 0xe34: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e36:
	/* 0xe36: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_e38:
	/* 0xe38: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e3a:
	/* 0xe3a: mov    WORD PTR [rsp+0x76],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_e3f:
	/* 0xe3f: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_e46:
	/* 0xe46: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e4a:
	/* 0xe4a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e4f:
	/* 0xe4f: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_e56:
	/* 0xe56: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e5b:
	/* 0xe5b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5d:
	/* 0xe5d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e60:
	/* 0xe60: je     e67 <tail_handle_ipv4_from_netdev+0xe67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e67;
	}
x86_l_e62:
	/* 0xe62: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e65:
	/* 0xe65: jmp    e6b <tail_handle_ipv4_from_netdev+0xe6b> */
	goto x86_l_e6b;
x86_l_e67:
	/* 0xe67: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e6b:
	/* 0xe6b: mov    DWORD PTR [rsp+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e70:
	/* 0xe70: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e75:
	/* 0xe75: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_e7c:
	/* 0xe7c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e81:
	/* 0xe81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e83:
	/* 0xe83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e86:
	/* 0xe86: je     16ce <tail_handle_ipv4_from_netdev+0x16ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5838ULL;
	}
x86_l_e8c:
	/* 0xe8c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e94:
	/* 0xe94: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e99:
	/* 0xe99: movzx  r14d,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_e9e:
	/* 0xe9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea3:
	/* 0xea3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea8:
	/* 0xea8: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ead:
	/* 0xead: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eaf:
	/* 0xeaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eb2:
	/* 0xeb2: mov    WORD PTR [rsp+0xb8],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ebb:
	/* 0xebb: je     ec9 <tail_handle_ipv4_from_netdev+0xec9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ec9;
	}
x86_l_ebd:
	/* 0xebd: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_ec0:
	/* 0xec0: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec4:
	/* 0xec4: mov    WORD PTR [rax+0x26],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_ec9:
	/* 0xec9: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ece:
	/* 0xece: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_ed6:
	/* 0xed6: jmp    184b <tail_handle_ipv4_from_netdev+0x184b> */
	return 6219ULL;
x86_l_edb:
	/* 0xedb: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_ee1:
	/* 0xee1: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee5:
	/* 0xee5: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_eea:
	/* 0xeea: jne    f23 <tail_handle_ipv4_from_netdev+0xf23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f23;
	}
x86_l_eec:
	/* 0xeec: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_eef:
	/* 0xeef: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ef1:
	/* 0xef1: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_ef4:
	/* 0xef4: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_ef7:
	/* 0xef7: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_ef9:
	/* 0xef9: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_efd:
	/* 0xefd: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_f00:
	/* 0xf00: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_f05:
	/* 0xf05: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_f0b:
	/* 0xf0b: cmove  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_f0f:
	/* 0xf0f: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f12:
	/* 0xf12: je     f23 <tail_handle_ipv4_from_netdev+0xf23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f23;
	}
x86_l_f14:
	/* 0xf14: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f1b:
	/* 0xf1b: imul   r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_f1f:
	/* 0xf1f: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f23:
	/* 0xf23: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f28:
	/* 0xf28: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f2c:
	/* 0xf2c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2f:
	/* 0xf2f: je     f43 <tail_handle_ipv4_from_netdev+0xf43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f43;
	}
x86_l_f31:
	/* 0xf31: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_f36:
	/* 0xf36: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f38:
	/* 0xf38: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f3a:
	/* 0xf3a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f3d:
	/* 0xf3d: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_f41:
	/* 0xf41: jmp    f66 <tail_handle_ipv4_from_netdev+0xf66> */
	goto x86_l_f66;
x86_l_f43:
	/* 0xf43: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_f48:
	/* 0xf48: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f4a:
	/* 0xf4a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f4c:
	/* 0xf4c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_f50:
	/* 0xf50: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_f5a:
	/* 0xf5a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f5d:
	/* 0xf5d: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_f62:
	/* 0xf62: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_f66:
	/* 0xf66: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f69:
	/* 0xf69: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f6e:
	/* 0xf6e: mov    DWORD PTR [rax+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f72:
	/* 0xf72: movzx  edx,BYTE PTR [rax+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_f76:
	/* 0xf76: mov    esi,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f79:
	/* 0xf79: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_f7d:
	/* 0xf7d: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f84:
	/* 0xf84: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f87:
	/* 0xf87: je     f9a <tail_handle_ipv4_from_netdev+0xf9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f9a;
	}
x86_l_f89:
	/* 0xf89: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f90:
	/* 0xf90: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f92:
	/* 0xf92: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_f95:
	/* 0xf95: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f98:
	/* 0xf98: jmp    f9f <tail_handle_ipv4_from_netdev+0xf9f> */
	goto x86_l_f9f;
x86_l_f9a:
	/* 0xf9a: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_f9f:
	/* 0xf9f: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fa1:
	/* 0xfa1: or     r14b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_fa4:
	/* 0xfa4: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_fa6:
	/* 0xfa6: jb     fad <tail_handle_ipv4_from_netdev+0xfad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_fad;
	}
x86_l_fa8:
	/* 0xfa8: cmp    dl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_8);
x86_l_fab:
	/* 0xfab: je     fbd <tail_handle_ipv4_from_netdev+0xfbd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fbd;
	}
x86_l_fad:
	/* 0xfad: mov    BYTE PTR [rax+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_fb1:
	/* 0xfb1: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fb4:
	/* 0xfb4: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_fbb:
	/* 0xfbb: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbd:
	/* 0xfbd: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_fc4:
	/* 0xfc4: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc7:
	/* 0xfc7: je     fd6 <tail_handle_ipv4_from_netdev+0xfd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd6;
	}
x86_l_fc9:
	/* 0xfc9: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_fce:
	/* 0xfce: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fd1:
	/* 0xfd1: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_fd6:
	/* 0xfd6: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fda:
	/* 0xfda: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fdd:
	/* 0xfdd: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_fe4:
	/* 0xfe4: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_fec:
	/* 0xfec: je     103c <tail_handle_ipv4_from_netdev+0x103c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_103c;
	}
x86_l_fee:
	/* 0xfee: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ff1:
	/* 0xff1: jne    1149 <tail_handle_ipv4_from_netdev+0x1149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1149;
	}
x86_l_ff7:
	/* 0xff7: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_ffb:
	/* 0xffb: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_ffe:
	/* 0xffe: je     1149 <tail_handle_ipv4_from_netdev+0x1149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1149;
	}
x86_l_1004:
	/* 0x1004: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_100a:
	/* 0x100a: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1010:
	/* 0x1010: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1013:
	/* 0x1013: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1017:
	/* 0x1017: mov    r15,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_101e:
	/* 0x101e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1022:
	/* 0x1022: je     2633 <tail_handle_ipv4_from_netdev+0x2633> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9779ULL;
	}
x86_l_1028:
	/* 0x1028: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_102f:
	/* 0x102f: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1033:
	/* 0x1033: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1037:
	/* 0x1037: jmp    2639 <tail_handle_ipv4_from_netdev+0x2639> */
	return 9785ULL;
x86_l_103c:
	/* 0x103c: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103f:
	/* 0x103f: and    ecx,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_1045:
	/* 0x1045: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1048:
	/* 0x1048: mov    cx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_16, 3ULL);
x86_l_104c:
	/* 0x104c: sbb    cx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_1050:
	/* 0x1050: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1054:
	/* 0x1054: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1058:
	/* 0x1058: mov    rdx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_105f:
	/* 0x105f: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1061:
	/* 0x1061: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1069:
	/* 0x1069: test   cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_106c:
	/* 0x106c: je     1149 <tail_handle_ipv4_from_netdev+0x1149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1149;
	}
x86_l_1072:
	/* 0x1072: mov    rdx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1079:
	/* 0x1079: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_107c:
	/* 0x107c: je     1093 <tail_handle_ipv4_from_netdev+0x1093> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1093;
	}
x86_l_107e:
	/* 0x107e: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1085:
	/* 0x1085: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1087:
	/* 0x1087: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1089:
	/* 0x1089: lea    r14d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_108d:
	/* 0x108d: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1091:
	/* 0x1091: jmp    1099 <tail_handle_ipv4_from_netdev+0x1099> */
	goto x86_l_1099;
x86_l_1093:
	/* 0x1093: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_1099:
	/* 0x1099: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_109c:
	/* 0x109c: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_10a0:
	/* 0x10a0: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a3:
	/* 0x10a3: je     10b4 <tail_handle_ipv4_from_netdev+0x10b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b4;
	}
x86_l_10a5:
	/* 0x10a5: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_10aa:
	/* 0x10aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ac:
	/* 0x10ac: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10ae:
	/* 0x10ae: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_10b2:
	/* 0x10b2: jmp    10d7 <tail_handle_ipv4_from_netdev+0x10d7> */
	goto x86_l_10d7;
x86_l_10b4:
	/* 0x10b4: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_10b9:
	/* 0x10b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10bb:
	/* 0x10bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10bd:
	/* 0x10bd: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_10c1:
	/* 0x10c1: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_10cb:
	/* 0x10cb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10ce:
	/* 0x10ce: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10d3:
	/* 0x10d3: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_10d7:
	/* 0x10d7: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10da:
	/* 0x10da: mov    DWORD PTR [r13+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10de:
	/* 0x10de: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_10e3:
	/* 0x10e3: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10e7:
	/* 0x10e7: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ea:
	/* 0x10ea: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_10ee:
	/* 0x10ee: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f1:
	/* 0x10f1: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_10f8:
	/* 0x10f8: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fb:
	/* 0x10fb: je     110e <tail_handle_ipv4_from_netdev+0x110e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_110e;
	}
x86_l_10fd:
	/* 0x10fd: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1104:
	/* 0x1104: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1106:
	/* 0x1106: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1109:
	/* 0x1109: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_110c:
	/* 0x110c: jmp    1113 <tail_handle_ipv4_from_netdev+0x1113> */
	goto x86_l_1113;
x86_l_110e:
	/* 0x110e: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1113:
	/* 0x1113: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_111a:
	/* 0x111a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_111c:
	/* 0x111c: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111f:
	/* 0x111f: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1121:
	/* 0x1121: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1124:
	/* 0x1124: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1126:
	/* 0x1126: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_112e:
	/* 0x112e: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1135:
	/* 0x1135: jb     113c <tail_handle_ipv4_from_netdev+0x113c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_113c;
	}
x86_l_1137:
	/* 0x1137: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_113a:
	/* 0x113a: je     1149 <tail_handle_ipv4_from_netdev+0x1149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1149;
	}
x86_l_113c:
	/* 0x113c: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113f:
	/* 0x113f: mov    BYTE PTR [r13+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1143:
	/* 0x1143: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1147:
	/* 0x1147: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1149:
	/* 0x1149: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_114c:
	/* 0x114c: je     1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8070ULL;
	}
x86_l_1152:
	/* 0x1152: mov    r13b,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1155:
	/* 0x1155: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_115a:
	/* 0x115a: jne    1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8070ULL;
	}
x86_l_1160:
	/* 0x1160: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1164:
	/* 0x1164: jne    116f <tail_handle_ipv4_from_netdev+0x116f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_116f;
	}
x86_l_1166:
	/* 0x1166: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_116d:
	/* 0x116d: jmp    1176 <tail_handle_ipv4_from_netdev+0x1176> */
	goto x86_l_1176;
x86_l_116f:
	/* 0x116f: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1176:
	/* 0x1176: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_117b:
	/* 0x117b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1184:
	/* 0x1184: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_118d:
	/* 0x118d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1196:
	/* 0x1196: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_119f:
	/* 0x119f: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_11a8:
	/* 0x11a8: mov    DWORD PTR [rsp+0x64],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729602ULL);
x86_l_11b0:
	/* 0x11b0: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_11b8:
	/* 0x11b8: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_11bc:
	/* 0x11bc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11c1:
	/* 0x11c1: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_11ca:
	/* 0x11ca: mov    WORD PTR [rsp+0x60],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11cf:
	/* 0x11cf: mov    WORD PTR [rsp+0x5c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 395136991360ULL);
x86_l_11d6:
	/* 0x11d6: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11dd:
	/* 0x11dd: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e0:
	/* 0x11e0: je     11f3 <tail_handle_ipv4_from_netdev+0x11f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f3;
	}
x86_l_11e2:
	/* 0x11e2: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11e9:
	/* 0x11e9: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_11ed:
	/* 0x11ed: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11f1:
	/* 0x11f1: jmp    11f9 <tail_handle_ipv4_from_netdev+0x11f9> */
	goto x86_l_11f9;
x86_l_11f3:
	/* 0x11f3: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_11f9:
	/* 0x11f9: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_11fd:
	/* 0x11fd: jne    1222 <tail_handle_ipv4_from_netdev+0x1222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1222;
	}
x86_l_11ff:
	/* 0x11ff: mov    WORD PTR [rsp+0x5c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 395136991360ULL);
x86_l_1206:
	/* 0x1206: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1209:
	/* 0x1209: je     121c <tail_handle_ipv4_from_netdev+0x121c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_121c;
	}
x86_l_120b:
	/* 0x120b: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1212:
	/* 0x1212: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1216:
	/* 0x1216: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_121a:
	/* 0x121a: jmp    1222 <tail_handle_ipv4_from_netdev+0x1222> */
	goto x86_l_1222;
x86_l_121c:
	/* 0x121c: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1222:
	/* 0x1222: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1225:
	/* 0x1225: je     1236 <tail_handle_ipv4_from_netdev+0x1236> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1236;
	}
x86_l_1227:
	/* 0x1227: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_122c:
	/* 0x122c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_122e:
	/* 0x122e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1230:
	/* 0x1230: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1234:
	/* 0x1234: jmp    1259 <tail_handle_ipv4_from_netdev+0x1259> */
	goto x86_l_1259;
x86_l_1236:
	/* 0x1236: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_123b:
	/* 0x123b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_123d:
	/* 0x123d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_123f:
	/* 0x123f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1243:
	/* 0x1243: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_124d:
	/* 0x124d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1250:
	/* 0x1250: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1255:
	/* 0x1255: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1259:
	/* 0x1259: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_125d:
	/* 0x125d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1260:
	/* 0x1260: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1263:
	/* 0x1263: mov    DWORD PTR [rsp+0x58],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1268:
	/* 0x1268: movzx  edx,BYTE PTR [rsp+0x62] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 98ULL);
x86_l_126d:
	/* 0x126d: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1271:
	/* 0x1271: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1273:
	/* 0x1273: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_127a:
	/* 0x127a: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127d:
	/* 0x127d: je     1292 <tail_handle_ipv4_from_netdev+0x1292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1292;
	}
x86_l_127f:
	/* 0x127f: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1286:
	/* 0x1286: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1288:
	/* 0x1288: lea    r8d,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_128c:
	/* 0x128c: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1290:
	/* 0x1290: jmp    1298 <tail_handle_ipv4_from_netdev+0x1298> */
	goto x86_l_1298;
x86_l_1292:
	/* 0x1292: mov    r8d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5ULL);
x86_l_1298:
	/* 0x1298: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_129f:
	/* 0x129f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12a4:
	/* 0x12a4: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12a7:
	/* 0x12a7: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12a9:
	/* 0x12a9: cmp    r8d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_12ac:
	/* 0x12ac: jb     12b2 <tail_handle_ipv4_from_netdev+0x12b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_12b2;
	}
x86_l_12ae:
	/* 0x12ae: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_12b0:
	/* 0x12b0: je     12c3 <tail_handle_ipv4_from_netdev+0x12c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c3;
	}
x86_l_12b2:
	/* 0x12b2: mov    BYTE PTR [rsp+0x62],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_12b6:
	/* 0x12b6: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12ba:
	/* 0x12ba: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_12c1:
	/* 0x12c1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c3:
	/* 0x12c3: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_12ca:
	/* 0x12ca: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12cd:
	/* 0x12cd: je     12e0 <tail_handle_ipv4_from_netdev+0x12e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12e0;
	}
x86_l_12cf:
	/* 0x12cf: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_12d8:
	/* 0x12d8: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12db:
	/* 0x12db: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12e0:
	/* 0x12e0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12e5:
	/* 0x12e5: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12ea:
	/* 0x12ea: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12ef:
	/* 0x12ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f1:
	/* 0x12f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f3:
	/* 0x12f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12f5:
	/* 0x12f5: jns    1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 8070ULL;
	}
x86_l_12fb:
	/* 0x12fb: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_12fe:
	/* 0x12fe: mov    ecx,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967141ULL);
x86_l_1303:
	/* 0x1303: jmp    91c <tail_handle_ipv4_from_netdev+0x91c> */
	return 2332ULL;
x86_l_1308:
	/* 0x1308: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130d:
	/* 0x130d: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1314:
	/* 0x1314: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_131c:
	/* 0x131c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131e:
	/* 0x131e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1321:
	/* 0x1321: je     133b <tail_handle_ipv4_from_netdev+0x133b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133b;
	}
x86_l_1323:
	/* 0x1323: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1325:
	/* 0x1325: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1329:
	/* 0x1329: jmp    324 <tail_handle_ipv4_from_netdev+0x324> */
	return 804ULL;
x86_l_132e:
	/* 0x132e: mov    ecx,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967139ULL);
x86_l_1333:
	/* 0x1333: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1336:
	/* 0x1336: jmp    91c <tail_handle_ipv4_from_netdev+0x91c> */
	return 2332ULL;
x86_l_133b:
	/* 0x133b: mov    ecx,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967121ULL);
x86_l_1340:
	/* 0x1340: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1343:
	/* 0x1343: jmp    91c <tail_handle_ipv4_from_netdev+0x91c> */
	return 2332ULL;
x86_l_1348:
	/* 0x1348: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1351:
	/* 0x1351: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1356:
	/* 0x1356: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_135b:
	/* 0x135b: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1362:
	/* 0x1362: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_136a:
	/* 0x136a: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_136f:
	/* 0x136f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1371:
	/* 0x1371: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1373:
	/* 0x1373: jmp    324 <tail_handle_ipv4_from_netdev+0x324> */
	return 804ULL;
x86_l_1378:
	/* 0x1378: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_137d:
	/* 0x137d: jmp    682 <tail_handle_ipv4_from_netdev+0x682> */
	return 1666ULL;
x86_l_1382:
	/* 0x1382: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1387:
	/* 0x1387: jmp    a44 <tail_handle_ipv4_from_netdev+0xa44> */
	return 2628ULL;
x86_l_138c:
	/* 0x138c: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1392:
	/* 0x1392: cmp    dl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 6ULL);
x86_l_1395:
	/* 0x1395: jne    13d0 <tail_handle_ipv4_from_netdev+0x13d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13d0;
	}
x86_l_1397:
	/* 0x1397: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_139b:
	/* 0x139b: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_139d:
	/* 0x139d: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_13a0:
	/* 0x13a0: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_13a3:
	/* 0x13a3: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_13a5:
	/* 0x13a5: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13aa:
	/* 0x13aa: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_13ac:
	/* 0x13ac: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_13b1:
	/* 0x13b1: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_13b7:
	/* 0x13b7: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_13bb:
	/* 0x13bb: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13bf:
	/* 0x13bf: je     13d0 <tail_handle_ipv4_from_netdev+0x13d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d0;
	}
x86_l_13c1:
	/* 0x13c1: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_13c8:
	/* 0x13c8: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_13cc:
	/* 0x13cc: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13d0:
	/* 0x13d0: shr    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 103079215112ULL);
x86_l_13d5:
	/* 0x13d5: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d9:
	/* 0x13d9: je     13ea <tail_handle_ipv4_from_netdev+0x13ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13ea;
	}
x86_l_13db:
	/* 0x13db: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_13e0:
	/* 0x13e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e2:
	/* 0x13e2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13e4:
	/* 0x13e4: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_13e8:
	/* 0x13e8: jmp    140d <tail_handle_ipv4_from_netdev+0x140d> */
	goto x86_l_140d;
x86_l_13ea:
	/* 0x13ea: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_13ef:
	/* 0x13ef: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f1:
	/* 0x13f1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13f3:
	/* 0x13f3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_13f7:
	/* 0x13f7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1401:
	/* 0x1401: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1404:
	/* 0x1404: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1409:
	/* 0x1409: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_140d:
	/* 0x140d: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1410:
	/* 0x1410: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1413:
	/* 0x1413: mov    DWORD PTR [r13+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1417:
	/* 0x1417: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_141c:
	/* 0x141c: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1420:
	/* 0x1420: mov    esi,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1424:
	/* 0x1424: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1428:
	/* 0x1428: mov    DWORD PTR [rsp+0x18],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_142c:
	/* 0x142c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1430:
	/* 0x1430: je     1443 <tail_handle_ipv4_from_netdev+0x1443> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5187ULL;
	}
	return 5170ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5170ULL: goto x86_l_1432;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5182ULL: goto x86_l_143e;
	case 5185ULL: goto x86_l_1441;
	case 5187ULL: goto x86_l_1443;
	case 5192ULL: goto x86_l_1448;
	case 5194ULL: goto x86_l_144a;
	case 5198ULL: goto x86_l_144e;
	case 5200ULL: goto x86_l_1450;
	case 5204ULL: goto x86_l_1454;
	case 5206ULL: goto x86_l_1456;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5218ULL: goto x86_l_1462;
	case 5222ULL: goto x86_l_1466;
	case 5224ULL: goto x86_l_1468;
	case 5228ULL: goto x86_l_146c;
	case 5232ULL: goto x86_l_1470;
	case 5236ULL: goto x86_l_1474;
	case 5243ULL: goto x86_l_147b;
	case 5245ULL: goto x86_l_147d;
	case 5250ULL: goto x86_l_1482;
	case 5256ULL: goto x86_l_1488;
	case 5260ULL: goto x86_l_148c;
	case 5263ULL: goto x86_l_148f;
	case 5269ULL: goto x86_l_1495;
	case 5277ULL: goto x86_l_149d;
	case 5282ULL: goto x86_l_14a2;
	case 5287ULL: goto x86_l_14a7;
	case 5292ULL: goto x86_l_14ac;
	case 5299ULL: goto x86_l_14b3;
	case 5307ULL: goto x86_l_14bb;
	case 5312ULL: goto x86_l_14c0;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5326ULL: goto x86_l_14ce;
	case 5329ULL: goto x86_l_14d1;
	case 5335ULL: goto x86_l_14d7;
	case 5338ULL: goto x86_l_14da;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5352ULL: goto x86_l_14e8;
	case 5357ULL: goto x86_l_14ed;
	case 5359ULL: goto x86_l_14ef;
	case 5361ULL: goto x86_l_14f1;
	case 5365ULL: goto x86_l_14f5;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5374ULL: goto x86_l_14fe;
	case 5376ULL: goto x86_l_1500;
	case 5380ULL: goto x86_l_1504;
	case 5390ULL: goto x86_l_150e;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5402ULL: goto x86_l_151a;
	case 5406ULL: goto x86_l_151e;
	case 5413ULL: goto x86_l_1525;
	case 5418ULL: goto x86_l_152a;
	case 5422ULL: goto x86_l_152e;
	case 5430ULL: goto x86_l_1536;
	case 5440ULL: goto x86_l_1540;
	case 5443ULL: goto x86_l_1543;
	case 5448ULL: goto x86_l_1548;
	case 5450ULL: goto x86_l_154a;
	case 5455ULL: goto x86_l_154f;
	case 5457ULL: goto x86_l_1551;
	case 5464ULL: goto x86_l_1558;
	case 5467ULL: goto x86_l_155b;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5478ULL: goto x86_l_1566;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5495ULL: goto x86_l_1577;
	case 5503ULL: goto x86_l_157f;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5517ULL: goto x86_l_158d;
	case 5520ULL: goto x86_l_1590;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5542ULL: goto x86_l_15a6;
	case 5549ULL: goto x86_l_15ad;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5559ULL: goto x86_l_15b7;
	case 5562ULL: goto x86_l_15ba;
	case 5568ULL: goto x86_l_15c0;
	case 5575ULL: goto x86_l_15c7;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5585ULL: goto x86_l_15d1;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5599ULL: goto x86_l_15df;
	case 5604ULL: goto x86_l_15e4;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5624ULL: goto x86_l_15f8;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5633ULL: goto x86_l_1601;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5639ULL: goto x86_l_1607;
	case 5644ULL: goto x86_l_160c;
	case 5651ULL: goto x86_l_1613;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5674ULL: goto x86_l_162a;
	case 5677ULL: goto x86_l_162d;
	case 5679ULL: goto x86_l_162f;
	case 5682ULL: goto x86_l_1632;
	case 5684ULL: goto x86_l_1634;
	case 5688ULL: goto x86_l_1638;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5705ULL: goto x86_l_1649;
	case 5710ULL: goto x86_l_164e;
	case 5712ULL: goto x86_l_1650;
	case 5715ULL: goto x86_l_1653;
	case 5718ULL: goto x86_l_1656;
	case 5720ULL: goto x86_l_1658;
	case 5729ULL: goto x86_l_1661;
	case 5738ULL: goto x86_l_166a;
	case 5747ULL: goto x86_l_1673;
	case 5756ULL: goto x86_l_167c;
	case 5765ULL: goto x86_l_1685;
	case 5774ULL: goto x86_l_168e;
	case 5780ULL: goto x86_l_1694;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5801ULL: goto x86_l_16a9;
	case 5804ULL: goto x86_l_16ac;
	case 5809ULL: goto x86_l_16b1;
	case 5816ULL: goto x86_l_16b8;
	case 5819ULL: goto x86_l_16bb;
	case 5821ULL: goto x86_l_16bd;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5838ULL: goto x86_l_16ce;
	case 5845ULL: goto x86_l_16d5;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5861ULL: goto x86_l_16e5;
	case 5865ULL: goto x86_l_16e9;
	case 5872ULL: goto x86_l_16f0;
	case 5875ULL: goto x86_l_16f3;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5894ULL: goto x86_l_1706;
	case 5901ULL: goto x86_l_170d;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5921ULL: goto x86_l_1721;
	case 5926ULL: goto x86_l_1726;
	case 5932ULL: goto x86_l_172c;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5943ULL: goto x86_l_1737;
	case 5950ULL: goto x86_l_173e;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5960ULL: goto x86_l_1748;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5972ULL: goto x86_l_1754;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5985ULL: goto x86_l_1761;
	case 5993ULL: goto x86_l_1769;
	case 5996ULL: goto x86_l_176c;
	case 5998ULL: goto x86_l_176e;
	case 6003ULL: goto x86_l_1773;
	case 6005ULL: goto x86_l_1775;
	case 6007ULL: goto x86_l_1777;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6018ULL: goto x86_l_1782;
	case 6020ULL: goto x86_l_1784;
	case 6022ULL: goto x86_l_1786;
	case 6026ULL: goto x86_l_178a;
	case 6036ULL: goto x86_l_1794;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6048ULL: goto x86_l_17a0;
	case 6052ULL: goto x86_l_17a4;
	case 6055ULL: goto x86_l_17a7;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6074ULL: goto x86_l_17ba;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6086ULL: goto x86_l_17c6;
	case 6093ULL: goto x86_l_17cd;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6116ULL: goto x86_l_17e4;
	case 6118ULL: goto x86_l_17e6;
	case 6120ULL: goto x86_l_17e8;
	case 6122ULL: goto x86_l_17ea;
	case 6124ULL: goto x86_l_17ec;
	case 6126ULL: goto x86_l_17ee;
	case 6128ULL: goto x86_l_17f0;
	case 6132ULL: goto x86_l_17f4;
	case 6136ULL: goto x86_l_17f8;
	case 6143ULL: goto x86_l_17ff;
	case 6145ULL: goto x86_l_1801;
	case 6152ULL: goto x86_l_1808;
	case 6155ULL: goto x86_l_180b;
	case 6157ULL: goto x86_l_180d;
	case 6166ULL: goto x86_l_1816;
	case 6169ULL: goto x86_l_1819;
	case 6174ULL: goto x86_l_181e;
	case 6179ULL: goto x86_l_1823;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6213ULL: goto x86_l_1845;
	case 6219ULL: goto x86_l_184b;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6246ULL: goto x86_l_1866;
	case 6252ULL: goto x86_l_186c;
	case 6259ULL: goto x86_l_1873;
	case 6262ULL: goto x86_l_1876;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6271ULL: goto x86_l_187f;
	case 6273ULL: goto x86_l_1881;
	case 6277ULL: goto x86_l_1885;
	case 6279ULL: goto x86_l_1887;
	case 6284ULL: goto x86_l_188c;
	case 6286ULL: goto x86_l_188e;
	case 6288ULL: goto x86_l_1890;
	case 6292ULL: goto x86_l_1894;
	case 6302ULL: goto x86_l_189e;
	case 6305ULL: goto x86_l_18a1;
	case 6310ULL: goto x86_l_18a6;
	case 6314ULL: goto x86_l_18aa;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6332ULL: goto x86_l_18bc;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6349ULL: goto x86_l_18cd;
	case 6357ULL: goto x86_l_18d5;
	case 6359ULL: goto x86_l_18d7;
	case 6367ULL: goto x86_l_18df;
	case 6375ULL: goto x86_l_18e7;
	case 6386ULL: goto x86_l_18f2;
	case 6391ULL: goto x86_l_18f7;
	case 6398ULL: goto x86_l_18fe;
	case 6403ULL: goto x86_l_1903;
	case 6411ULL: goto x86_l_190b;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6423ULL: goto x86_l_1917;
	case 6425ULL: goto x86_l_1919;
	case 6434ULL: goto x86_l_1922;
	case 6442ULL: goto x86_l_192a;
	case 6451ULL: goto x86_l_1933;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6479ULL: goto x86_l_194f;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6490ULL: goto x86_l_195a;
	case 6492ULL: goto x86_l_195c;
	case 6494ULL: goto x86_l_195e;
	case 6504ULL: goto x86_l_1968;
	case 6509ULL: goto x86_l_196d;
	case 6517ULL: goto x86_l_1975;
	case 6519ULL: goto x86_l_1977;
	case 6522ULL: goto x86_l_197a;
	case 6524ULL: goto x86_l_197c;
	case 6529ULL: goto x86_l_1981;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6540ULL: goto x86_l_198c;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6552ULL: goto x86_l_1998;
	case 6562ULL: goto x86_l_19a2;
	case 6567ULL: goto x86_l_19a7;
	case 6575ULL: goto x86_l_19af;
	case 6581ULL: goto x86_l_19b5;
	case 6585ULL: goto x86_l_19b9;
	case 6590ULL: goto x86_l_19be;
	case 6594ULL: goto x86_l_19c2;
	case 6602ULL: goto x86_l_19ca;
	case 6605ULL: goto x86_l_19cd;
	case 6609ULL: goto x86_l_19d1;
	case 6614ULL: goto x86_l_19d6;
	case 6617ULL: goto x86_l_19d9;
	case 6619ULL: goto x86_l_19db;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6630ULL: goto x86_l_19e6;
	case 6638ULL: goto x86_l_19ee;
	case 6642ULL: goto x86_l_19f2;
	case 6648ULL: goto x86_l_19f8;
	case 6650ULL: goto x86_l_19fa;
	case 6658ULL: goto x86_l_1a02;
	case 6669ULL: goto x86_l_1a0d;
	case 6677ULL: goto x86_l_1a15;
	case 6682ULL: goto x86_l_1a1a;
	case 6686ULL: goto x86_l_1a1e;
	case 6689ULL: goto x86_l_1a21;
	case 6692ULL: goto x86_l_1a24;
	case 6697ULL: goto x86_l_1a29;
	case 6700ULL: goto x86_l_1a2c;
	case 6702ULL: goto x86_l_1a2e;
	case 6707ULL: goto x86_l_1a33;
	case 6709ULL: goto x86_l_1a35;
	case 6715ULL: goto x86_l_1a3b;
	case 6719ULL: goto x86_l_1a3f;
	case 6721ULL: goto x86_l_1a41;
	case 6724ULL: goto x86_l_1a44;
	case 6727ULL: goto x86_l_1a47;
	case 6731ULL: goto x86_l_1a4b;
	case 6735ULL: goto x86_l_1a4f;
	case 6740ULL: goto x86_l_1a54;
	case 6743ULL: goto x86_l_1a57;
	case 6746ULL: goto x86_l_1a5a;
	case 6748ULL: goto x86_l_1a5c;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6756ULL: goto x86_l_1a64;
	case 6758ULL: goto x86_l_1a66;
	case 6760ULL: goto x86_l_1a68;
	case 6768ULL: goto x86_l_1a70;
	case 6770ULL: goto x86_l_1a72;
	case 6780ULL: goto x86_l_1a7c;
	case 6785ULL: goto x86_l_1a81;
	case 6788ULL: goto x86_l_1a84;
	case 6792ULL: goto x86_l_1a88;
	case 6798ULL: goto x86_l_1a8e;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6811ULL: goto x86_l_1a9b;
	case 6817ULL: goto x86_l_1aa1;
	case 6820ULL: goto x86_l_1aa4;
	case 6826ULL: goto x86_l_1aaa;
	case 6831ULL: goto x86_l_1aaf;
	case 6839ULL: goto x86_l_1ab7;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1432:
	/* 0x1432: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1439:
	/* 0x1439: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143b:
	/* 0x143b: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_143e:
	/* 0x143e: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1441:
	/* 0x1441: jmp    1448 <tail_handle_ipv4_from_netdev+0x1448> */
	goto x86_l_1448;
x86_l_1443:
	/* 0x1443: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1448:
	/* 0x1448: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_144a:
	/* 0x144a: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_144e:
	/* 0x144e: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1450:
	/* 0x1450: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1454:
	/* 0x1454: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1456:
	/* 0x1456: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_145b:
	/* 0x145b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1460:
	/* 0x1460: jb     1468 <tail_handle_ipv4_from_netdev+0x1468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1468;
	}
x86_l_1462:
	/* 0x1462: cmp    cl,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1466:
	/* 0x1466: je     147d <tail_handle_ipv4_from_netdev+0x147d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_147d;
	}
x86_l_1468:
	/* 0x1468: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_146c:
	/* 0x146c: mov    BYTE PTR [r13+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1470:
	/* 0x1470: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1474:
	/* 0x1474: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_147b:
	/* 0x147b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147d:
	/* 0x147d: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1482:
	/* 0x1482: je     16dd <tail_handle_ipv4_from_netdev+0x16dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16dd;
	}
x86_l_1488:
	/* 0x1488: test   BYTE PTR [rdx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_148c:
	/* 0x148c: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_148f:
	/* 0x148f: je     15f0 <tail_handle_ipv4_from_netdev+0x15f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f0;
	}
x86_l_1495:
	/* 0x1495: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_149d:
	/* 0x149d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14a2:
	/* 0x14a2: movzx  eax,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_14a7:
	/* 0x14a7: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14ac:
	/* 0x14ac: mov    WORD PTR [rsp+0x42],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 283467841536ULL);
x86_l_14b3:
	/* 0x14b3: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_14bb:
	/* 0x14bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c0:
	/* 0x14c0: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_14c7:
	/* 0x14c7: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14cc:
	/* 0x14cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ce:
	/* 0x14ce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d1:
	/* 0x14d1: je     15eb <tail_handle_ipv4_from_netdev+0x15eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15eb;
	}
x86_l_14d7:
	/* 0x14d7: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_14da:
	/* 0x14da: mov    r13,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_14e1:
	/* 0x14e1: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e6:
	/* 0x14e6: je     14f7 <tail_handle_ipv4_from_netdev+0x14f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f7;
	}
x86_l_14e8:
	/* 0x14e8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_14ed:
	/* 0x14ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ef:
	/* 0x14ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14f1:
	/* 0x14f1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_14f5:
	/* 0x14f5: jmp    151a <tail_handle_ipv4_from_netdev+0x151a> */
	goto x86_l_151a;
x86_l_14f7:
	/* 0x14f7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_14fc:
	/* 0x14fc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14fe:
	/* 0x14fe: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1500:
	/* 0x1500: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1504:
	/* 0x1504: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_150e:
	/* 0x150e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1511:
	/* 0x1511: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1516:
	/* 0x1516: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_151a:
	/* 0x151a: mov    ecx,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_151e:
	/* 0x151e: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1525:
	/* 0x1525: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_152a:
	/* 0x152a: movzx  ecx,WORD PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_152e:
	/* 0x152e: mov    WORD PTR [rsp+0x84],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1536:
	/* 0x1536: mov    WORD PTR [rsp+0x86],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_1540:
	/* 0x1540: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1543:
	/* 0x1543: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_1548:
	/* 0x1548: and    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_154a:
	/* 0x154a: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154f:
	/* 0x154f: je     155e <tail_handle_ipv4_from_netdev+0x155e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_155e;
	}
x86_l_1551:
	/* 0x1551: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1558:
	/* 0x1558: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_155b:
	/* 0x155b: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_155e:
	/* 0x155e: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1560:
	/* 0x1560: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1563:
	/* 0x1563: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1566:
	/* 0x1566: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1569:
	/* 0x1569: jbe    15cc <tail_handle_ipv4_from_netdev+0x15cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_15cc;
	}
x86_l_156b:
	/* 0x156b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1570:
	/* 0x1570: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_1577:
	/* 0x1577: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_157f:
	/* 0x157f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1581:
	/* 0x1581: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1584:
	/* 0x1584: je     15d3 <tail_handle_ipv4_from_netdev+0x15d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d3;
	}
x86_l_1586:
	/* 0x1586: mov    QWORD PTR [r14],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1589:
	/* 0x1589: mov    r13d,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_158d:
	/* 0x158d: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1590:
	/* 0x1590: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1595:
	/* 0x1595: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_159a:
	/* 0x159a: je     15f0 <tail_handle_ipv4_from_netdev+0x15f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f0;
	}
x86_l_159c:
	/* 0x159c: mov    DWORD PTR [rsp+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15a1:
	/* 0x15a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a6:
	/* 0x15a6: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_15ad:
	/* 0x15ad: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15b2:
	/* 0x15b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b4:
	/* 0x15b4: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15b7:
	/* 0x15b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15ba:
	/* 0x15ba: jne    1658 <tail_handle_ipv4_from_netdev+0x1658> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1658;
	}
x86_l_15c0:
	/* 0x15c0: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_15c7:
	/* 0x15c7: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15ca:
	/* 0x15ca: jmp    15eb <tail_handle_ipv4_from_netdev+0x15eb> */
	goto x86_l_15eb;
x86_l_15cc:
	/* 0x15cc: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_15d1:
	/* 0x15d1: jmp    15d8 <tail_handle_ipv4_from_netdev+0x15d8> */
	goto x86_l_15d8;
x86_l_15d3:
	/* 0x15d3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_15d8:
	/* 0x15d8: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_15df:
	/* 0x15df: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15e4:
	/* 0x15e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e6:
	/* 0x15e6: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_15eb:
	/* 0x15eb: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15f0:
	/* 0x15f0: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_15f5:
	/* 0x15f5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f8:
	/* 0x15f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15fa:
	/* 0x15fa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15fc:
	/* 0x15fc: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1601:
	/* 0x1601: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1603:
	/* 0x1603: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1605:
	/* 0x1605: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1607:
	/* 0x1607: mov    WORD PTR [rsp+0x76],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_160c:
	/* 0x160c: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1613:
	/* 0x1613: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1617:
	/* 0x1617: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_161c:
	/* 0x161c: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_1623:
	/* 0x1623: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1628:
	/* 0x1628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162a:
	/* 0x162a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_162d:
	/* 0x162d: je     1634 <tail_handle_ipv4_from_netdev+0x1634> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1634;
	}
x86_l_162f:
	/* 0x162f: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1632:
	/* 0x1632: jmp    1638 <tail_handle_ipv4_from_netdev+0x1638> */
	goto x86_l_1638;
x86_l_1634:
	/* 0x1634: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1638:
	/* 0x1638: mov    DWORD PTR [rsp+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_163d:
	/* 0x163d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1642:
	/* 0x1642: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_1649:
	/* 0x1649: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_164e:
	/* 0x164e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1650:
	/* 0x1650: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1653:
	/* 0x1653: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1656:
	/* 0x1656: je     16ce <tail_handle_ipv4_from_netdev+0x16ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16ce;
	}
x86_l_1658:
	/* 0x1658: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1661:
	/* 0x1661: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_166a:
	/* 0x166a: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1673:
	/* 0x1673: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_167c:
	/* 0x167c: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1685:
	/* 0x1685: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_168e:
	/* 0x168e: movzx  r14d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1694:
	/* 0x1694: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_169c:
	/* 0x169c: mov    WORD PTR [rsp+0x5e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_16a1:
	/* 0x16a1: mov    DWORD PTR [rsp+0xa0],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_16a9:
	/* 0x16a9: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_16ac:
	/* 0x16ac: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16b1:
	/* 0x16b1: mov    rdx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_16b8:
	/* 0x16b8: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bb:
	/* 0x16bb: je     1726 <tail_handle_ipv4_from_netdev+0x1726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1726;
	}
x86_l_16bd:
	/* 0x16bd: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_16c4:
	/* 0x16c4: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_16c8:
	/* 0x16c8: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_16cc:
	/* 0x16cc: jmp    172c <tail_handle_ipv4_from_netdev+0x172c> */
	goto x86_l_172c;
x86_l_16ce:
	/* 0x16ce: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_16d5:
	/* 0x16d5: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_16d8:
	/* 0x16d8: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16dd:
	/* 0x16dd: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_16e5:
	/* 0x16e5: mov    BYTE PTR [rsp+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_16e9:
	/* 0x16e9: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_16f0:
	/* 0x16f0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f3:
	/* 0x16f3: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_16fa:
	/* 0x16fa: mov    esi,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967138ULL);
x86_l_16ff:
	/* 0x16ff: je     1748 <tail_handle_ipv4_from_netdev+0x1748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1748;
	}
x86_l_1701:
	/* 0x1701: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1706:
	/* 0x1706: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_170d:
	/* 0x170d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1710:
	/* 0x1710: mov    edx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 45ULL);
x86_l_1715:
	/* 0x1715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1717:
	/* 0x1717: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_171c:
	/* 0x171c: mov    esi,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967156ULL);
x86_l_1721:
	/* 0x1721: jmp    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	return 7544ULL;
x86_l_1726:
	/* 0x1726: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_172c:
	/* 0x172c: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_1730:
	/* 0x1730: jne    1761 <tail_handle_ipv4_from_netdev+0x1761> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1761;
	}
x86_l_1732:
	/* 0x1732: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1735:
	/* 0x1735: je     175b <tail_handle_ipv4_from_netdev+0x175b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_175b;
	}
x86_l_1737:
	/* 0x1737: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_173e:
	/* 0x173e: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1742:
	/* 0x1742: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1746:
	/* 0x1746: jmp    1761 <tail_handle_ipv4_from_netdev+0x1761> */
	goto x86_l_1761;
x86_l_1748:
	/* 0x1748: movzx  eax,BYTE PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_174c:
	/* 0x174c: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_174e:
	/* 0x174e: je     1bef <tail_handle_ipv4_from_netdev+0x1bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7151ULL;
	}
x86_l_1754:
	/* 0x1754: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_1756:
	/* 0x1756: jmp    1bf3 <tail_handle_ipv4_from_netdev+0x1bf3> */
	return 7155ULL;
x86_l_175b:
	/* 0x175b: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1761:
	/* 0x1761: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1769:
	/* 0x1769: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176c:
	/* 0x176c: je     177d <tail_handle_ipv4_from_netdev+0x177d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_177d;
	}
x86_l_176e:
	/* 0x176e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1773:
	/* 0x1773: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1775:
	/* 0x1775: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1777:
	/* 0x1777: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_177b:
	/* 0x177b: jmp    17a0 <tail_handle_ipv4_from_netdev+0x17a0> */
	goto x86_l_17a0;
x86_l_177d:
	/* 0x177d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1782:
	/* 0x1782: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1784:
	/* 0x1784: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1786:
	/* 0x1786: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_178a:
	/* 0x178a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1794:
	/* 0x1794: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1797:
	/* 0x1797: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_179c:
	/* 0x179c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_17a0:
	/* 0x17a0: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_17a4:
	/* 0x17a4: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_17a7:
	/* 0x17a7: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17aa:
	/* 0x17aa: mov    DWORD PTR [rsp+0x58],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17af:
	/* 0x17af: movzx  edx,BYTE PTR [rsp+0x62] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 98ULL);
x86_l_17b4:
	/* 0x17b4: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17b8:
	/* 0x17b8: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_17ba:
	/* 0x17ba: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_17c1:
	/* 0x17c1: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c4:
	/* 0x17c4: je     17d7 <tail_handle_ipv4_from_netdev+0x17d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17d7;
	}
x86_l_17c6:
	/* 0x17c6: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_17cd:
	/* 0x17cd: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17cf:
	/* 0x17cf: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_17d2:
	/* 0x17d2: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_17d5:
	/* 0x17d5: jmp    17dc <tail_handle_ipv4_from_netdev+0x17dc> */
	goto x86_l_17dc;
x86_l_17d7:
	/* 0x17d7: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_17dc:
	/* 0x17dc: mov    r13d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17e4:
	/* 0x17e4: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17e6:
	/* 0x17e6: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_17e8:
	/* 0x17e8: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_17ea:
	/* 0x17ea: jb     17f0 <tail_handle_ipv4_from_netdev+0x17f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17f0;
	}
x86_l_17ec:
	/* 0x17ec: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_17ee:
	/* 0x17ee: je     1801 <tail_handle_ipv4_from_netdev+0x1801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1801;
	}
x86_l_17f0:
	/* 0x17f0: mov    BYTE PTR [rsp+0x62],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_17f4:
	/* 0x17f4: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17f8:
	/* 0x17f8: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_17ff:
	/* 0x17ff: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1801:
	/* 0x1801: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1808:
	/* 0x1808: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_180b:
	/* 0x180b: je     181e <tail_handle_ipv4_from_netdev+0x181e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181e;
	}
x86_l_180d:
	/* 0x180d: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_1816:
	/* 0x1816: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1819:
	/* 0x1819: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_181e:
	/* 0x181e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1823:
	/* 0x1823: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1828:
	/* 0x1828: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_182d:
	/* 0x182d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1832:
	/* 0x1832: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1834:
	/* 0x1834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1836:
	/* 0x1836: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1838:
	/* 0x1838: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_183d:
	/* 0x183d: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1845:
	/* 0x1845: js     261c <tail_handle_ipv4_from_netdev+0x261c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9756ULL;
	}
x86_l_184b:
	/* 0x184b: movzx  eax,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_1853:
	/* 0x1853: mov    BYTE PTR [rsp+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1857:
	/* 0x1857: test   BYTE PTR [rdx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_185b:
	/* 0x185b: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_185e:
	/* 0x185e: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1866:
	/* 0x1866: je     1917 <tail_handle_ipv4_from_netdev+0x1917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1917;
	}
x86_l_186c:
	/* 0x186c: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1873:
	/* 0x1873: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1876:
	/* 0x1876: je     1887 <tail_handle_ipv4_from_netdev+0x1887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1887;
	}
x86_l_1878:
	/* 0x1878: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_187d:
	/* 0x187d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_187f:
	/* 0x187f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1881:
	/* 0x1881: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1885:
	/* 0x1885: jmp    18aa <tail_handle_ipv4_from_netdev+0x18aa> */
	goto x86_l_18aa;
x86_l_1887:
	/* 0x1887: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_188c:
	/* 0x188c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_188e:
	/* 0x188e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1890:
	/* 0x1890: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1894:
	/* 0x1894: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_189e:
	/* 0x189e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_18a1:
	/* 0x18a1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_18a6:
	/* 0x18a6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_18aa:
	/* 0x18aa: mov    rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18b2:
	/* 0x18b2: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18b7:
	/* 0x18b7: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18bc:
	/* 0x18bc: movzx  ecx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_18c1:
	/* 0x18c1: mov    WORD PTR [rsp+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18c6:
	/* 0x18c6: mov    WORD PTR [rsp+0x42],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 283467841536ULL);
x86_l_18cd:
	/* 0x18cd: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_18d5:
	/* 0x18d5: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18d7:
	/* 0x18d7: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18df:
	/* 0x18df: mov    DWORD PTR [rsp+0x88],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18e7:
	/* 0x18e7: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_18f2:
	/* 0x18f2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18f7:
	/* 0x18f7: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_18fe:
	/* 0x18fe: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1903:
	/* 0x1903: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_190b:
	/* 0x190b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_190d:
	/* 0x190d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190f:
	/* 0x190f: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1917:
	/* 0x1917: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1919:
	/* 0x1919: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1922:
	/* 0x1922: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_192a:
	/* 0x192a: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1933:
	/* 0x1933: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1937:
	/* 0x1937: mov    BYTE PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_193c:
	/* 0x193c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1941:
	/* 0x1941: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_1948:
	/* 0x1948: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_194d:
	/* 0x194d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_194f:
	/* 0x194f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1952:
	/* 0x1952: movzx  eax,BYTE PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1957:
	/* 0x1957: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_195a:
	/* 0x195a: je     198c <tail_handle_ipv4_from_netdev+0x198c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_198c;
	}
x86_l_195c:
	/* 0x195c: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_195e:
	/* 0x195e: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1968:
	/* 0x1968: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_196d:
	/* 0x196d: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1975:
	/* 0x1975: jne    19b5 <tail_handle_ipv4_from_netdev+0x19b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19b5;
	}
x86_l_1977:
	/* 0x1977: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_197a:
	/* 0x197a: je     19b5 <tail_handle_ipv4_from_netdev+0x19b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b5;
	}
x86_l_197c:
	/* 0x197c: movzx  eax,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1981:
	/* 0x1981: and    al,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_1983:
	/* 0x1983: je     19b5 <tail_handle_ipv4_from_netdev+0x19b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b5;
	}
x86_l_1985:
	/* 0x1985: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1987:
	/* 0x1987: jmp    2d6 <tail_handle_ipv4_from_netdev+0x2d6> */
	return 726ULL;
x86_l_198c:
	/* 0x198c: mov    esi,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967162ULL);
x86_l_1991:
	/* 0x1991: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_1993:
	/* 0x1993: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1998:
	/* 0x1998: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_19a2:
	/* 0x19a2: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19a7:
	/* 0x19a7: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_19af:
	/* 0x19af: jne    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7544ULL;
	}
x86_l_19b5:
	/* 0x19b5: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b9:
	/* 0x19b9: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_19be:
	/* 0x19be: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19c2:
	/* 0x19c2: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_19ca:
	/* 0x19ca: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19cd:
	/* 0x19cd: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19d1:
	/* 0x19d1: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19d6:
	/* 0x19d6: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_19d9:
	/* 0x19d9: je     19e0 <tail_handle_ipv4_from_netdev+0x19e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e0;
	}
x86_l_19db:
	/* 0x19db: mov    WORD PTR [rsp+0x2a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_19e0:
	/* 0x19e0: mov    r9b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 1ULL);
x86_l_19e3:
	/* 0x19e3: test   r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_19e6:
	/* 0x19e6: mov    QWORD PTR [rsp+0xc0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_19ee:
	/* 0x19ee: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f2:
	/* 0x19f2: je     1a93 <tail_handle_ipv4_from_netdev+0x1a93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a93;
	}
x86_l_19f8:
	/* 0x19f8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fa:
	/* 0x19fa: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a02:
	/* 0x1a02: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1a0d:
	/* 0x1a0d: mov    DWORD PTR [rsp+0xc8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1a15:
	/* 0x1a15: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1a1a:
	/* 0x1a1a: lea    esi,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a21:
	/* 0x1a21: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a24:
	/* 0x1a24: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a29:
	/* 0x1a29: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a2c:
	/* 0x1a2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2e:
	/* 0x1a2e: mov    esi,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967155ULL);
x86_l_1a33:
	/* 0x1a33: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a35:
	/* 0x1a35: js     1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7542ULL;
	}
x86_l_1a3b:
	/* 0x1a3b: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a3f:
	/* 0x1a3f: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a41:
	/* 0x1a41: add    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1a44:
	/* 0x1a44: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1a47:
	/* 0x1a47: adc    r14d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1a4b:
	/* 0x1a4b: add    r13d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1a54:
	/* 0x1a54: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a57:
	/* 0x1a57: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1a5a:
	/* 0x1a5a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a5c:
	/* 0x1a5c: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1a5f:
	/* 0x1a5f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a62:
	/* 0x1a62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a64:
	/* 0x1a64: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a66:
	/* 0x1a66: js     1ad8 <tail_handle_ipv4_from_netdev+0x1ad8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ad8;
	}
x86_l_1a68:
	/* 0x1a68: cmp    BYTE PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_1a70:
	/* 0x1a70: je     1ae2 <tail_handle_ipv4_from_netdev+0x1ae2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6882ULL;
	}
x86_l_1a72:
	/* 0x1a72: movabs r14,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 2199023255552ULL);
x86_l_1a7c:
	/* 0x1a7c: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a81:
	/* 0x1a81: test   r9,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R14, X86_WIDTH_64);
x86_l_1a84:
	/* 0x1a84: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a88:
	/* 0x1a88: je     1b3b <tail_handle_ipv4_from_netdev+0x1b3b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6971ULL;
	}
x86_l_1a8e:
	/* 0x1a8e: jmp    1c0f <tail_handle_ipv4_from_netdev+0x1c0f> */
	return 7183ULL;
x86_l_1a93:
	/* 0x1a93: movzx  eax,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1a98:
	/* 0x1a98: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1a9b:
	/* 0x1a9b: je     1be2 <tail_handle_ipv4_from_netdev+0x1be2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7138ULL;
	}
x86_l_1aa1:
	/* 0x1aa1: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1aa4:
	/* 0x1aa4: je     1bc2 <tail_handle_ipv4_from_netdev+0x1bc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7106ULL;
	}
x86_l_1aaa:
	/* 0x1aaa: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1ac2:
	/* 0x1ac2: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1ac5:
	/* 0x1ac5: jne    1a0d <tail_handle_ipv4_from_netdev+0x1a0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a0d;
	}
x86_l_1acb:
	/* 0x1acb: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ace:
	/* 0x1ace: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1ad3:
	/* 0x1ad3: jmp    19fa <tail_handle_ipv4_from_netdev+0x19fa> */
	goto x86_l_19fa;
x86_l_1ad8:
	/* 0x1ad8: mov    esi,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967143ULL);
x86_l_1add:
	/* 0x1add: jmp    1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	return 7542ULL;
	return 6882ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6882ULL: goto x86_l_1ae2;
	case 6886ULL: goto x86_l_1ae6;
	case 6894ULL: goto x86_l_1aee;
	case 6897ULL: goto x86_l_1af1;
	case 6905ULL: goto x86_l_1af9;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6917ULL: goto x86_l_1b05;
	case 6919ULL: goto x86_l_1b07;
	case 6922ULL: goto x86_l_1b0a;
	case 6924ULL: goto x86_l_1b0c;
	case 6926ULL: goto x86_l_1b0e;
	case 6929ULL: goto x86_l_1b11;
	case 6935ULL: goto x86_l_1b17;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6953ULL: goto x86_l_1b29;
	case 6959ULL: goto x86_l_1b2f;
	case 6961ULL: goto x86_l_1b31;
	case 6965ULL: goto x86_l_1b35;
	case 6971ULL: goto x86_l_1b3b;
	case 6979ULL: goto x86_l_1b43;
	case 6983ULL: goto x86_l_1b47;
	case 6986ULL: goto x86_l_1b4a;
	case 6992ULL: goto x86_l_1b50;
	case 6997ULL: goto x86_l_1b55;
	case 7003ULL: goto x86_l_1b5b;
	case 7008ULL: goto x86_l_1b60;
	case 7013ULL: goto x86_l_1b65;
	case 7016ULL: goto x86_l_1b68;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7027ULL: goto x86_l_1b73;
	case 7032ULL: goto x86_l_1b78;
	case 7035ULL: goto x86_l_1b7b;
	case 7037ULL: goto x86_l_1b7d;
	case 7039ULL: goto x86_l_1b7f;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7058ULL: goto x86_l_1b92;
	case 7061ULL: goto x86_l_1b95;
	case 7069ULL: goto x86_l_1b9d;
	case 7073ULL: goto x86_l_1ba1;
	case 7078ULL: goto x86_l_1ba6;
	case 7081ULL: goto x86_l_1ba9;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7089ULL: goto x86_l_1bb1;
	case 7092ULL: goto x86_l_1bb4;
	case 7097ULL: goto x86_l_1bb9;
	case 7099ULL: goto x86_l_1bbb;
	case 7104ULL: goto x86_l_1bc0;
	case 7106ULL: goto x86_l_1bc2;
	case 7117ULL: goto x86_l_1bcd;
	case 7122ULL: goto x86_l_1bd2;
	case 7130ULL: goto x86_l_1bda;
	case 7133ULL: goto x86_l_1bdd;
	case 7138ULL: goto x86_l_1be2;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7155ULL: goto x86_l_1bf3;
	case 7160ULL: goto x86_l_1bf8;
	case 7166ULL: goto x86_l_1bfe;
	case 7171ULL: goto x86_l_1c03;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7183ULL: goto x86_l_1c0f;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7204ULL: goto x86_l_1c24;
	case 7212ULL: goto x86_l_1c2c;
	case 7214ULL: goto x86_l_1c2e;
	case 7218ULL: goto x86_l_1c32;
	case 7224ULL: goto x86_l_1c38;
	case 7230ULL: goto x86_l_1c3e;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7247ULL: goto x86_l_1c4f;
	case 7249ULL: goto x86_l_1c51;
	case 7251ULL: goto x86_l_1c53;
	case 7258ULL: goto x86_l_1c5a;
	case 7260ULL: goto x86_l_1c5c;
	case 7267ULL: goto x86_l_1c63;
	case 7272ULL: goto x86_l_1c68;
	case 7283ULL: goto x86_l_1c73;
	case 7286ULL: goto x86_l_1c76;
	case 7292ULL: goto x86_l_1c7c;
	case 7295ULL: goto x86_l_1c7f;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7310ULL: goto x86_l_1c8e;
	case 7319ULL: goto x86_l_1c97;
	case 7328ULL: goto x86_l_1ca0;
	case 7338ULL: goto x86_l_1caa;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7358ULL: goto x86_l_1cbe;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7371ULL: goto x86_l_1ccb;
	case 7373ULL: goto x86_l_1ccd;
	case 7376ULL: goto x86_l_1cd0;
	case 7380ULL: goto x86_l_1cd4;
	case 7382ULL: goto x86_l_1cd6;
	case 7391ULL: goto x86_l_1cdf;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7408ULL: goto x86_l_1cf0;
	case 7416ULL: goto x86_l_1cf8;
	case 7421ULL: goto x86_l_1cfd;
	case 7423ULL: goto x86_l_1cff;
	case 7425ULL: goto x86_l_1d01;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7444ULL: goto x86_l_1d14;
	case 7452ULL: goto x86_l_1d1c;
	case 7454ULL: goto x86_l_1d1e;
	case 7457ULL: goto x86_l_1d21;
	case 7462ULL: goto x86_l_1d26;
	case 7465ULL: goto x86_l_1d29;
	case 7473ULL: goto x86_l_1d31;
	case 7476ULL: goto x86_l_1d34;
	case 7481ULL: goto x86_l_1d39;
	case 7483ULL: goto x86_l_1d3b;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7495ULL: goto x86_l_1d47;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7505ULL: goto x86_l_1d51;
	case 7510ULL: goto x86_l_1d56;
	case 7513ULL: goto x86_l_1d59;
	case 7520ULL: goto x86_l_1d60;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7532ULL: goto x86_l_1d6c;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7544ULL: goto x86_l_1d78;
	case 7546ULL: goto x86_l_1d7a;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7562ULL: goto x86_l_1d8a;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7582ULL: goto x86_l_1d9e;
	case 7585ULL: goto x86_l_1da1;
	case 7587ULL: goto x86_l_1da3;
	case 7591ULL: goto x86_l_1da7;
	case 7594ULL: goto x86_l_1daa;
	case 7596ULL: goto x86_l_1dac;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7614ULL: goto x86_l_1dbe;
	case 7620ULL: goto x86_l_1dc4;
	case 7628ULL: goto x86_l_1dcc;
	case 7634ULL: goto x86_l_1dd2;
	case 7641ULL: goto x86_l_1dd9;
	case 7643ULL: goto x86_l_1ddb;
	case 7649ULL: goto x86_l_1de1;
	case 7653ULL: goto x86_l_1de5;
	case 7655ULL: goto x86_l_1de7;
	case 7662ULL: goto x86_l_1dee;
	case 7664ULL: goto x86_l_1df0;
	case 7671ULL: goto x86_l_1df7;
	case 7676ULL: goto x86_l_1dfc;
	case 7684ULL: goto x86_l_1e04;
	case 7693ULL: goto x86_l_1e0d;
	case 7702ULL: goto x86_l_1e16;
	case 7711ULL: goto x86_l_1e1f;
	case 7720ULL: goto x86_l_1e28;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7742ULL: goto x86_l_1e3e;
	case 7751ULL: goto x86_l_1e47;
	case 7760ULL: goto x86_l_1e50;
	case 7767ULL: goto x86_l_1e57;
	case 7774ULL: goto x86_l_1e5e;
	case 7777ULL: goto x86_l_1e61;
	case 7779ULL: goto x86_l_1e63;
	case 7786ULL: goto x86_l_1e6a;
	case 7790ULL: goto x86_l_1e6e;
	case 7794ULL: goto x86_l_1e72;
	case 7796ULL: goto x86_l_1e74;
	case 7802ULL: goto x86_l_1e7a;
	case 7806ULL: goto x86_l_1e7e;
	case 7808ULL: goto x86_l_1e80;
	case 7815ULL: goto x86_l_1e87;
	case 7818ULL: goto x86_l_1e8a;
	case 7820ULL: goto x86_l_1e8c;
	case 7827ULL: goto x86_l_1e93;
	case 7831ULL: goto x86_l_1e97;
	case 7835ULL: goto x86_l_1e9b;
	case 7837ULL: goto x86_l_1e9d;
	case 7843ULL: goto x86_l_1ea3;
	case 7846ULL: goto x86_l_1ea6;
	case 7848ULL: goto x86_l_1ea8;
	case 7853ULL: goto x86_l_1ead;
	case 7855ULL: goto x86_l_1eaf;
	case 7857ULL: goto x86_l_1eb1;
	case 7861ULL: goto x86_l_1eb5;
	case 7863ULL: goto x86_l_1eb7;
	case 7868ULL: goto x86_l_1ebc;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7886ULL: goto x86_l_1ece;
	case 7889ULL: goto x86_l_1ed1;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7922ULL: goto x86_l_1ef2;
	case 7924ULL: goto x86_l_1ef4;
	case 7931ULL: goto x86_l_1efb;
	case 7934ULL: goto x86_l_1efe;
	case 7936ULL: goto x86_l_1f00;
	case 7943ULL: goto x86_l_1f07;
	case 7945ULL: goto x86_l_1f09;
	case 7948ULL: goto x86_l_1f0c;
	case 7951ULL: goto x86_l_1f0f;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7965ULL: goto x86_l_1f1d;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7977ULL: goto x86_l_1f29;
	case 7981ULL: goto x86_l_1f2d;
	case 7985ULL: goto x86_l_1f31;
	case 7992ULL: goto x86_l_1f38;
	case 7994ULL: goto x86_l_1f3a;
	case 8001ULL: goto x86_l_1f41;
	case 8004ULL: goto x86_l_1f44;
	case 8006ULL: goto x86_l_1f46;
	case 8015ULL: goto x86_l_1f4f;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8028ULL: goto x86_l_1f5c;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8043ULL: goto x86_l_1f6b;
	case 8045ULL: goto x86_l_1f6d;
	case 8047ULL: goto x86_l_1f6f;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8064ULL: goto x86_l_1f80;
	case 8070ULL: goto x86_l_1f86;
	case 8077ULL: goto x86_l_1f8d;
	case 8079ULL: goto x86_l_1f8f;
	case 8083ULL: goto x86_l_1f93;
	case 8090ULL: goto x86_l_1f9a;
	case 8093ULL: goto x86_l_1f9d;
	case 8096ULL: goto x86_l_1fa0;
	case 8099ULL: goto x86_l_1fa3;
	case 8103ULL: goto x86_l_1fa7;
	case 8107ULL: goto x86_l_1fab;
	case 8110ULL: goto x86_l_1fae;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8132ULL: goto x86_l_1fc4;
	case 8140ULL: goto x86_l_1fcc;
	case 8149ULL: goto x86_l_1fd5;
	case 8153ULL: goto x86_l_1fd9;
	case 8158ULL: goto x86_l_1fde;
	case 8163ULL: goto x86_l_1fe3;
	case 8170ULL: goto x86_l_1fea;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8182ULL: goto x86_l_1ff6;
	case 8188ULL: goto x86_l_1ffc;
	case 8191ULL: goto x86_l_1fff;
	case 8195ULL: goto x86_l_2003;
	case 8199ULL: goto x86_l_2007;
	case 8205ULL: goto x86_l_200d;
	case 8210ULL: goto x86_l_2012;
	case 8216ULL: goto x86_l_2018;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8229ULL: goto x86_l_2025;
	case 8234ULL: goto x86_l_202a;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8247ULL: goto x86_l_2037;
	case 8253ULL: goto x86_l_203d;
	case 8256ULL: goto x86_l_2040;
	case 8259ULL: goto x86_l_2043;
	case 8263ULL: goto x86_l_2047;
	case 8267ULL: goto x86_l_204b;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8291ULL: goto x86_l_2063;
	case 8297ULL: goto x86_l_2069;
	case 8302ULL: goto x86_l_206e;
	case 8307ULL: goto x86_l_2073;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8325ULL: goto x86_l_2085;
	case 8330ULL: goto x86_l_208a;
	case 8332ULL: goto x86_l_208c;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8361ULL: goto x86_l_20a9;
	case 8363ULL: goto x86_l_20ab;
	case 8365ULL: goto x86_l_20ad;
	case 8371ULL: goto x86_l_20b3;
	case 8375ULL: goto x86_l_20b7;
	case 8384ULL: goto x86_l_20c0;
	case 8393ULL: goto x86_l_20c9;
	case 8403ULL: goto x86_l_20d3;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8423ULL: goto x86_l_20e7;
	case 8431ULL: goto x86_l_20ef;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8445ULL: goto x86_l_20fd;
	case 8449ULL: goto x86_l_2101;
	case 8454ULL: goto x86_l_2106;
	case 8459ULL: goto x86_l_210b;
	case 8461ULL: goto x86_l_210d;
	case 8465ULL: goto x86_l_2111;
	case 8470ULL: goto x86_l_2116;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8484ULL: goto x86_l_2124;
	case 8487ULL: goto x86_l_2127;
	case 8489ULL: goto x86_l_2129;
	case 8493ULL: goto x86_l_212d;
	case 8495ULL: goto x86_l_212f;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8507ULL: goto x86_l_213b;
	case 8510ULL: goto x86_l_213e;
	case 8513ULL: goto x86_l_2141;
	case 8520ULL: goto x86_l_2148;
	case 8523ULL: goto x86_l_214b;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8533ULL: goto x86_l_2155;
	case 8536ULL: goto x86_l_2158;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8549ULL: goto x86_l_2165;
	case 8553ULL: goto x86_l_2169;
	case 8557ULL: goto x86_l_216d;
	case 8562ULL: goto x86_l_2172;
	case 8567ULL: goto x86_l_2177;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8585ULL: goto x86_l_2189;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8601ULL: goto x86_l_2199;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8611ULL: goto x86_l_21a3;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ae2:
	/* 0x1ae2: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1aee:
	/* 0x1aee: lea    esi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1af1:
	/* 0x1af1: mov    r8d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1af9:
	/* 0x1af9: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1afd:
	/* 0x1afd: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1b02:
	/* 0x1b02: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b05:
	/* 0x1b05: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b07:
	/* 0x1b07: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1b0a:
	/* 0x1b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0c:
	/* 0x1b0c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1b0e:
	/* 0x1b0e: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1b11:
	/* 0x1b11: and    ecx,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_1b17:
	/* 0x1b17: movabs r14,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b21:
	/* 0x1b21: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b26:
	/* 0x1b26: test   r9,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R14, X86_WIDTH_64);
x86_l_1b29:
	/* 0x1b29: jne    1c03 <tail_handle_ipv4_from_netdev+0x1c03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c03;
	}
x86_l_1b2f:
	/* 0x1b2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b31:
	/* 0x1b31: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b35:
	/* 0x1b35: js     1c07 <tail_handle_ipv4_from_netdev+0x1c07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c07;
	}
x86_l_1b3b:
	/* 0x1b3b: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1b43:
	/* 0x1b43: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1b47:
	/* 0x1b47: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1b4a:
	/* 0x1b4a: je     1c0f <tail_handle_ipv4_from_netdev+0x1c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c0f;
	}
x86_l_1b50:
	/* 0x1b50: cmp    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b55:
	/* 0x1b55: je     1c0f <tail_handle_ipv4_from_netdev+0x1c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c0f;
	}
x86_l_1b5b:
	/* 0x1b5b: mov    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b60:
	/* 0x1b60: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1b65:
	/* 0x1b65: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_1b68:
	/* 0x1b68: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_1b6b:
	/* 0x1b6b: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b70:
	/* 0x1b70: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b73:
	/* 0x1b73: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b78:
	/* 0x1b78: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7b:
	/* 0x1b7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7d:
	/* 0x1b7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b7f:
	/* 0x1b7f: js     225d <tail_handle_ipv4_from_netdev+0x225d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8797ULL;
	}
x86_l_1b85:
	/* 0x1b85: movzx  ecx,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    rsi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b92:
	/* 0x1b92: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b95:
	/* 0x1b95: mov    r8d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b9d:
	/* 0x1b9d: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ba9:
	/* 0x1ba9: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bad:
	/* 0x1bad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1baf:
	/* 0x1baf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bb1:
	/* 0x1bb1: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1bb4:
	/* 0x1bb4: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb9:
	/* 0x1bb9: jns    1c0f <tail_handle_ipv4_from_netdev+0x1c0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1c0f;
	}
x86_l_1bbb:
	/* 0x1bbb: mov    ecx,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967142ULL);
x86_l_1bc0:
	/* 0x1bc0: jmp    1c07 <tail_handle_ipv4_from_netdev+0x1c07> */
	goto x86_l_1c07;
x86_l_1bc2:
	/* 0x1bc2: mov    DWORD PTR [rsp+0xb0],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244128ULL);
x86_l_1bcd:
	/* 0x1bcd: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1bd2:
	/* 0x1bd2: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1bda:
	/* 0x1bda: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bdd:
	/* 0x1bdd: jmp    1a0d <tail_handle_ipv4_from_netdev+0x1a0d> */
	return 6669ULL;
x86_l_1be2:
	/* 0x1be2: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1be5:
	/* 0x1be5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bea:
	/* 0x1bea: jmp    19fa <tail_handle_ipv4_from_netdev+0x19fa> */
	return 6650ULL;
x86_l_1bef:
	/* 0x1bef: test   BYTE PTR [rdx+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1bf8:
	/* 0x1bf8: jne    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d78;
	}
x86_l_1bfe:
	/* 0x1bfe: jmp    1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	goto x86_l_1f86;
x86_l_1c03:
	/* 0x1c03: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c07:
	/* 0x1c07: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1c09:
	/* 0x1c09: js     2814 <tail_handle_ipv4_from_netdev+0x2814> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10260ULL;
	}
x86_l_1c0f:
	/* 0x1c0f: cmp    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1c18:
	/* 0x1c18: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1c24:
	/* 0x1c24: mov    r8,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c2c:
	/* 0x1c2c: jne    1c38 <tail_handle_ipv4_from_netdev+0x1c38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c38;
	}
x86_l_1c2e:
	/* 0x1c2e: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_1c32:
	/* 0x1c32: js     25e6 <tail_handle_ipv4_from_netdev+0x25e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9702ULL;
	}
x86_l_1c38:
	/* 0x1c38: rol    QWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 137438953504ULL);
x86_l_1c3e:
	/* 0x1c3e: rol    DWORD PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 171798691856ULL);
x86_l_1c43:
	/* 0x1c43: movzx  eax,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1c48:
	/* 0x1c48: mov    BYTE PTR [rsp+0xa8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c4f:
	/* 0x1c4f: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_1c51:
	/* 0x1c51: je     1c5c <tail_handle_ipv4_from_netdev+0x1c5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c5c;
	}
x86_l_1c53:
	/* 0x1c53: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1c5a:
	/* 0x1c5a: jmp    1c63 <tail_handle_ipv4_from_netdev+0x1c63> */
	goto x86_l_1c63;
x86_l_1c5c:
	/* 0x1c5c: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1c63:
	/* 0x1c63: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_1c68:
	/* 0x1c68: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1c73:
	/* 0x1c73: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c76:
	/* 0x1c76: je     1d0f <tail_handle_ipv4_from_netdev+0x1d0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d0f;
	}
x86_l_1c7c:
	/* 0x1c7c: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_1c7f:
	/* 0x1c7f: je     1d0f <tail_handle_ipv4_from_netdev+0x1d0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d0f;
	}
x86_l_1c85:
	/* 0x1c85: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c8a:
	/* 0x1c8a: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c8e:
	/* 0x1c8e: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1c97:
	/* 0x1c97: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1ca0:
	/* 0x1ca0: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_1caa:
	/* 0x1caa: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1cb2:
	/* 0x1cb2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1cbe:
	/* 0x1cbe: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1cc6:
	/* 0x1cc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cc8:
	/* 0x1cc8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ccb:
	/* 0x1ccb: je     1cd6 <tail_handle_ipv4_from_netdev+0x1cd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd6;
	}
x86_l_1ccd:
	/* 0x1ccd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1cd0:
	/* 0x1cd0: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1cd4:
	/* 0x1cd4: jmp    1d01 <tail_handle_ipv4_from_netdev+0x1d01> */
	goto x86_l_1d01;
x86_l_1cd6:
	/* 0x1cd6: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1cdf:
	/* 0x1cdf: mov    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ce4:
	/* 0x1ce4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1cf0:
	/* 0x1cf0: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1cf8:
	/* 0x1cf8: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cfd:
	/* 0x1cfd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cff:
	/* 0x1cff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d01:
	/* 0x1d01: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d05:
	/* 0x1d05: mov    r9,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d0f:
	/* 0x1d0f: test   r9,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R14, X86_WIDTH_64);
x86_l_1d12:
	/* 0x1d12: jne    1d82 <tail_handle_ipv4_from_netdev+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d82;
	}
x86_l_1d14:
	/* 0x1d14: cmp    BYTE PTR [rsp+0xa8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505734ULL);
x86_l_1d1c:
	/* 0x1d1c: jne    1d82 <tail_handle_ipv4_from_netdev+0x1d82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d82;
	}
x86_l_1d1e:
	/* 0x1d1e: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_1d21:
	/* 0x1d21: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1d26:
	/* 0x1d26: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_1d29:
	/* 0x1d29: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d31:
	/* 0x1d31: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d34:
	/* 0x1d34: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d39:
	/* 0x1d39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3b:
	/* 0x1d3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d3d:
	/* 0x1d3d: js     1d71 <tail_handle_ipv4_from_netdev+0x1d71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d71;
	}
x86_l_1d3f:
	/* 0x1d3f: mov    r14d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d47:
	/* 0x1d47: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1d4a:
	/* 0x1d4a: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1d4f:
	/* 0x1d4f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d51:
	/* 0x1d51: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1d56:
	/* 0x1d56: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1d59:
	/* 0x1d59: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_1d60:
	/* 0x1d60: jne    2626 <tail_handle_ipv4_from_netdev+0x2626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9766ULL;
	}
x86_l_1d66:
	/* 0x1d66: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_1d68:
	/* 0x1d68: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6c:
	/* 0x1d6c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1d6f:
	/* 0x1d6f: jmp    1d92 <tail_handle_ipv4_from_netdev+0x1d92> */
	goto x86_l_1d92;
x86_l_1d71:
	/* 0x1d71: mov    esi,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967161ULL);
x86_l_1d76:
	/* 0x1d76: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d78:
	/* 0x1d78: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_1d7a:
	/* 0x1d7a: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1d7d:
	/* 0x1d7d: jmp    48 <tail_handle_ipv4_from_netdev+0x48> */
	return 72ULL;
x86_l_1d82:
	/* 0x1d82: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d8a:
	/* 0x1d8a: mov    r14d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1d92:
	/* 0x1d92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d97:
	/* 0x1d97: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d9c:
	/* 0x1d9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9e:
	/* 0x1d9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1da1:
	/* 0x1da1: je     1dd2 <tail_handle_ipv4_from_netdev+0x1dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd2;
	}
x86_l_1da3:
	/* 0x1da3: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1da7:
	/* 0x1da7: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_1daa:
	/* 0x1daa: je     1dd2 <tail_handle_ipv4_from_netdev+0x1dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd2;
	}
x86_l_1dac:
	/* 0x1dac: movzx  edx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1db0:
	/* 0x1db0: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1db3:
	/* 0x1db3: je     1dd2 <tail_handle_ipv4_from_netdev+0x1dd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dd2;
	}
x86_l_1db5:
	/* 0x1db5: cmp    WORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_1dbe:
	/* 0x1dbe: je     2269 <tail_handle_ipv4_from_netdev+0x2269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8809ULL;
	}
x86_l_1dc4:
	/* 0x1dc4: cmp    dx,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1dcc:
	/* 0x1dcc: je     2269 <tail_handle_ipv4_from_netdev+0x2269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8809ULL;
	}
x86_l_1dd2:
	/* 0x1dd2: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1dd9:
	/* 0x1dd9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddb:
	/* 0x1ddb: movzx  r14d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1de1:
	/* 0x1de1: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_1de5:
	/* 0x1de5: jne    1df0 <tail_handle_ipv4_from_netdev+0x1df0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1df0;
	}
x86_l_1de7:
	/* 0x1de7: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1dee:
	/* 0x1dee: jmp    1df7 <tail_handle_ipv4_from_netdev+0x1df7> */
	goto x86_l_1df7;
x86_l_1df0:
	/* 0x1df0: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1df7:
	/* 0x1df7: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dfc:
	/* 0x1dfc: movzx  eax,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1e04:
	/* 0x1e04: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1e16:
	/* 0x1e16: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1e1f:
	/* 0x1e1f: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1e28:
	/* 0x1e28: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1e31:
	/* 0x1e31: mov    WORD PTR [rsp+0x5e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_1e36:
	/* 0x1e36: mov    DWORD PTR [rsp+0x64],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729602ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1e47:
	/* 0x1e47: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1e50:
	/* 0x1e50: mov    WORD PTR [rsp+0x5c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 395136991264ULL);
x86_l_1e57:
	/* 0x1e57: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1e5e:
	/* 0x1e5e: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e61:
	/* 0x1e61: je     1e74 <tail_handle_ipv4_from_netdev+0x1e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e74;
	}
x86_l_1e63:
	/* 0x1e63: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e6a:
	/* 0x1e6a: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1e6e:
	/* 0x1e6e: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e72:
	/* 0x1e72: jmp    1e7a <tail_handle_ipv4_from_netdev+0x1e7a> */
	goto x86_l_1e7a;
x86_l_1e74:
	/* 0x1e74: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1e7a:
	/* 0x1e7a: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_1e7e:
	/* 0x1e7e: jne    1ea3 <tail_handle_ipv4_from_netdev+0x1ea3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ea3;
	}
x86_l_1e80:
	/* 0x1e80: mov    WORD PTR [rsp+0x5c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 395136991264ULL);
x86_l_1e87:
	/* 0x1e87: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8a:
	/* 0x1e8a: je     1e9d <tail_handle_ipv4_from_netdev+0x1e9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9d;
	}
x86_l_1e8c:
	/* 0x1e8c: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e93:
	/* 0x1e93: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1e97:
	/* 0x1e97: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e9b:
	/* 0x1e9b: jmp    1ea3 <tail_handle_ipv4_from_netdev+0x1ea3> */
	goto x86_l_1ea3;
x86_l_1e9d:
	/* 0x1e9d: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1ea3:
	/* 0x1ea3: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ea6:
	/* 0x1ea6: je     1eb7 <tail_handle_ipv4_from_netdev+0x1eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb7;
	}
x86_l_1ea8:
	/* 0x1ea8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1ead:
	/* 0x1ead: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eaf:
	/* 0x1eaf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1eb1:
	/* 0x1eb1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1eb5:
	/* 0x1eb5: jmp    1eda <tail_handle_ipv4_from_netdev+0x1eda> */
	goto x86_l_1eda;
x86_l_1eb7:
	/* 0x1eb7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1ebc:
	/* 0x1ebc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ebe:
	/* 0x1ebe: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ec0:
	/* 0x1ec0: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1ec4:
	/* 0x1ec4: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1ece:
	/* 0x1ece: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ed1:
	/* 0x1ed1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ed6:
	/* 0x1ed6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1eda:
	/* 0x1eda: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_1ede:
	/* 0x1ede: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1ee1:
	/* 0x1ee1: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ee4:
	/* 0x1ee4: mov    DWORD PTR [rsp+0x58],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ee9:
	/* 0x1ee9: movzx  edx,BYTE PTR [rsp+0x62] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 98ULL);
x86_l_1eee:
	/* 0x1eee: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ef2:
	/* 0x1ef2: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1ef4:
	/* 0x1ef4: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1efb:
	/* 0x1efb: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1efe:
	/* 0x1efe: je     1f11 <tail_handle_ipv4_from_netdev+0x1f11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f11;
	}
x86_l_1f00:
	/* 0x1f00: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1f07:
	/* 0x1f07: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f09:
	/* 0x1f09: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1f0c:
	/* 0x1f0c: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f0f:
	/* 0x1f0f: jmp    1f16 <tail_handle_ipv4_from_netdev+0x1f16> */
	goto x86_l_1f16;
x86_l_1f11:
	/* 0x1f11: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1f16:
	/* 0x1f16: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1f1d:
	/* 0x1f1d: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f1f:
	/* 0x1f1f: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f21:
	/* 0x1f21: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1f23:
	/* 0x1f23: jb     1f29 <tail_handle_ipv4_from_netdev+0x1f29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f29;
	}
x86_l_1f25:
	/* 0x1f25: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_1f27:
	/* 0x1f27: je     1f3a <tail_handle_ipv4_from_netdev+0x1f3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3a;
	}
x86_l_1f29:
	/* 0x1f29: mov    BYTE PTR [rsp+0x62],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f31:
	/* 0x1f31: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f38:
	/* 0x1f38: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f3a:
	/* 0x1f3a: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1f41:
	/* 0x1f41: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f44:
	/* 0x1f44: je     1f57 <tail_handle_ipv4_from_netdev+0x1f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f57;
	}
x86_l_1f46:
	/* 0x1f46: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f52:
	/* 0x1f52: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f57:
	/* 0x1f57: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f5c:
	/* 0x1f5c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f61:
	/* 0x1f61: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f66:
	/* 0x1f66: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6b:
	/* 0x1f6b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6d:
	/* 0x1f6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f6f:
	/* 0x1f6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f71:
	/* 0x1f71: js     261c <tail_handle_ipv4_from_netdev+0x261c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9756ULL;
	}
x86_l_1f77:
	/* 0x1f77: cmp    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1f80:
	/* 0x1f80: je     250b <tail_handle_ipv4_from_netdev+0x250b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9483ULL;
	}
x86_l_1f86:
	/* 0x1f86: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f8d:
	/* 0x1f8d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f8f:
	/* 0x1f8f: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f93:
	/* 0x1f93: mov    r13,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1f9a:
	/* 0x1f9a: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f9d:
	/* 0x1f9d: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1fa0:
	/* 0x1fa0: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fa3:
	/* 0x1fa3: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1fa7:
	/* 0x1fa7: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_1fab:
	/* 0x1fab: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fae:
	/* 0x1fae: ja     48 <tail_handle_ipv4_from_netdev+0x48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 72ULL;
	}
x86_l_1fb4:
	/* 0x1fb4: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fb7:
	/* 0x1fb7: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fbb:
	/* 0x1fbb: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1fcc:
	/* 0x1fcc: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1fd5:
	/* 0x1fd5: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fd9:
	/* 0x1fd9: mov    BYTE PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_1fde:
	/* 0x1fde: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fe3:
	/* 0x1fe3: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_1fea:
	/* 0x1fea: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fef:
	/* 0x1fef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff1:
	/* 0x1ff1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff3:
	/* 0x1ff3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ff6:
	/* 0x1ff6: je     2d6 <tail_handle_ipv4_from_netdev+0x2d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 726ULL;
	}
x86_l_1ffc:
	/* 0x1ffc: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_1fff:
	/* 0x1fff: movzx  r14d,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2003:
	/* 0x2003: test   BYTE PTR [rax+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_2007:
	/* 0x2007: jne    2d6 <tail_handle_ipv4_from_netdev+0x2d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 726ULL;
	}
x86_l_200d:
	/* 0x200d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2012:
	/* 0x2012: je     2106 <tail_handle_ipv4_from_netdev+0x2106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2106;
	}
x86_l_2018:
	/* 0x2018: mov    rcx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_201c:
	/* 0x201c: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2021:
	/* 0x2021: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2025:
	/* 0x2025: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_202a:
	/* 0x202a: movzx  edx,BYTE PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_202f:
	/* 0x202f: mov    ebp,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967100ULL);
x86_l_2034:
	/* 0x2034: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2037:
	/* 0x2037: jb     2216 <tail_handle_ipv4_from_netdev+0x2216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8726ULL;
	}
x86_l_203d:
	/* 0x203d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_2040:
	/* 0x2040: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2043:
	/* 0x2043: mov    BYTE PTR [r13+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2047:
	/* 0x2047: add    r14d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_204b:
	/* 0x204b: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_204e:
	/* 0x204e: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2053:
	/* 0x2053: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2056:
	/* 0x2056: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_2059:
	/* 0x2059: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_205f:
	/* 0x205f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2061:
	/* 0x2061: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2063:
	/* 0x2063: js     2172 <tail_handle_ipv4_from_netdev+0x2172> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2172;
	}
x86_l_2069:
	/* 0x2069: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_206e:
	/* 0x206e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2073:
	/* 0x2073: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2076:
	/* 0x2076: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_207b:
	/* 0x207b: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2080:
	/* 0x2080: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2083:
	/* 0x2083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2085:
	/* 0x2085: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_208a:
	/* 0x208a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_208c:
	/* 0x208c: js     2216 <tail_handle_ipv4_from_netdev+0x2216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8726ULL;
	}
x86_l_2092:
	/* 0x2092: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2097:
	/* 0x2097: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_209c:
	/* 0x209c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_209f:
	/* 0x209f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a1:
	/* 0x20a1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_20a6:
	/* 0x20a6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a9:
	/* 0x20a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ab:
	/* 0x20ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ad:
	/* 0x20ad: js     2216 <tail_handle_ipv4_from_netdev+0x2216> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8726ULL;
	}
x86_l_20b3:
	/* 0x20b3: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_20b7:
	/* 0x20b7: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_20c0:
	/* 0x20c0: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_20c9:
	/* 0x20c9: movabs rax,0x6d00840100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 468160086272ULL);
x86_l_20d3:
	/* 0x20d3: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_20db:
	/* 0x20db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20e0:
	/* 0x20e0: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_20e7:
	/* 0x20e7: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_20ef:
	/* 0x20ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f1:
	/* 0x20f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20f4:
	/* 0x20f4: je     21b1 <tail_handle_ipv4_from_netdev+0x21b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8625ULL;
	}
x86_l_20fa:
	/* 0x20fa: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20fd:
	/* 0x20fd: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2101:
	/* 0x2101: jmp    21dc <tail_handle_ipv4_from_netdev+0x21dc> */
	return 8668ULL;
x86_l_2106:
	/* 0x2106: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_210b:
	/* 0x210b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_210d:
	/* 0x210d: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2111:
	/* 0x2111: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2116:
	/* 0x2116: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_211d:
	/* 0x211d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2122:
	/* 0x2122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2124:
	/* 0x2124: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2127:
	/* 0x2127: je     212f <tail_handle_ipv4_from_netdev+0x212f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212f;
	}
x86_l_2129:
	/* 0x2129: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_212d:
	/* 0x212d: jne    217c <tail_handle_ipv4_from_netdev+0x217c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_217c;
	}
x86_l_212f:
	/* 0x212f: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2134:
	/* 0x2134: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2139:
	/* 0x2139: je     2186 <tail_handle_ipv4_from_netdev+0x2186> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2186;
	}
x86_l_213b:
	/* 0x213b: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_213e:
	/* 0x213e: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_2141:
	/* 0x2141: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2148:
	/* 0x2148: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_214b:
	/* 0x214b: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_214e:
	/* 0x214e: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2151:
	/* 0x2151: add    rsi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 34ULL);
x86_l_2155:
	/* 0x2155: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2158:
	/* 0x2158: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_215b:
	/* 0x215b: ja     48 <tail_handle_ipv4_from_netdev+0x48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 72ULL;
	}
x86_l_2161:
	/* 0x2161: lea    r13,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2165:
	/* 0x2165: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2169:
	/* 0x2169: add    r14,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_216d:
	/* 0x216d: jmp    2018 <tail_handle_ipv4_from_netdev+0x2018> */
	goto x86_l_2018;
x86_l_2172:
	/* 0x2172: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_2177:
	/* 0x2177: jmp    2216 <tail_handle_ipv4_from_netdev+0x2216> */
	return 8726ULL;
x86_l_217c:
	/* 0x217c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2181:
	/* 0x2181: jmp    2018 <tail_handle_ipv4_from_netdev+0x2018> */
	goto x86_l_2018;
x86_l_2186:
	/* 0x2186: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_2189:
	/* 0x2189: movzx  r15d,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_2191:
	/* 0x2191: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2196:
	/* 0x2196: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2199:
	/* 0x2199: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_219c:
	/* 0x219c: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_21a1:
	/* 0x21a1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a3:
	/* 0x21a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a5:
	/* 0x21a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a7:
	/* 0x21a7: je     221e <tail_handle_ipv4_from_netdev+0x221e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8734ULL;
	}
	return 8617ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8644ULL: goto x86_l_21c4;
	case 8651ULL: goto x86_l_21cb;
	case 8659ULL: goto x86_l_21d3;
	case 8664ULL: goto x86_l_21d8;
	case 8666ULL: goto x86_l_21da;
	case 8668ULL: goto x86_l_21dc;
	case 8674ULL: goto x86_l_21e2;
	case 8681ULL: goto x86_l_21e9;
	case 8684ULL: goto x86_l_21ec;
	case 8688ULL: goto x86_l_21f0;
	case 8696ULL: goto x86_l_21f8;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8716ULL: goto x86_l_220c;
	case 8719ULL: goto x86_l_220f;
	case 8721ULL: goto x86_l_2211;
	case 8726ULL: goto x86_l_2216;
	case 8729ULL: goto x86_l_2219;
	case 8734ULL: goto x86_l_221e;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8756ULL: goto x86_l_2234;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8771ULL: goto x86_l_2243;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8781ULL: goto x86_l_224d;
	case 8787ULL: goto x86_l_2253;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8809ULL: goto x86_l_2269;
	case 8814ULL: goto x86_l_226e;
	case 8818ULL: goto x86_l_2272;
	case 8820ULL: goto x86_l_2274;
	case 8822ULL: goto x86_l_2276;
	case 8824ULL: goto x86_l_2278;
	case 8830ULL: goto x86_l_227e;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8843ULL: goto x86_l_228b;
	case 8850ULL: goto x86_l_2292;
	case 8854ULL: goto x86_l_2296;
	case 8858ULL: goto x86_l_229a;
	case 8860ULL: goto x86_l_229c;
	case 8866ULL: goto x86_l_22a2;
	case 8874ULL: goto x86_l_22aa;
	case 8876ULL: goto x86_l_22ac;
	case 8880ULL: goto x86_l_22b0;
	case 8882ULL: goto x86_l_22b2;
	case 8885ULL: goto x86_l_22b5;
	case 8888ULL: goto x86_l_22b8;
	case 8890ULL: goto x86_l_22ba;
	case 8894ULL: goto x86_l_22be;
	case 8898ULL: goto x86_l_22c2;
	case 8901ULL: goto x86_l_22c5;
	case 8906ULL: goto x86_l_22ca;
	case 8912ULL: goto x86_l_22d0;
	case 8916ULL: goto x86_l_22d4;
	case 8920ULL: goto x86_l_22d8;
	case 8922ULL: goto x86_l_22da;
	case 8929ULL: goto x86_l_22e1;
	case 8933ULL: goto x86_l_22e5;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8946ULL: goto x86_l_22f2;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8957ULL: goto x86_l_22fd;
	case 8959ULL: goto x86_l_22ff;
	case 8961ULL: goto x86_l_2301;
	case 8965ULL: goto x86_l_2305;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8974ULL: goto x86_l_230e;
	case 8976ULL: goto x86_l_2310;
	case 8980ULL: goto x86_l_2314;
	case 8990ULL: goto x86_l_231e;
	case 8993ULL: goto x86_l_2321;
	case 8998ULL: goto x86_l_2326;
	case 9002ULL: goto x86_l_232a;
	case 9005ULL: goto x86_l_232d;
	case 9009ULL: goto x86_l_2331;
	case 9013ULL: goto x86_l_2335;
	case 9017ULL: goto x86_l_2339;
	case 9020ULL: goto x86_l_233c;
	case 9024ULL: goto x86_l_2340;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9037ULL: goto x86_l_234d;
	case 9039ULL: goto x86_l_234f;
	case 9042ULL: goto x86_l_2352;
	case 9045ULL: goto x86_l_2355;
	case 9047ULL: goto x86_l_2357;
	case 9052ULL: goto x86_l_235c;
	case 9054ULL: goto x86_l_235e;
	case 9057ULL: goto x86_l_2361;
	case 9059ULL: goto x86_l_2363;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9066ULL: goto x86_l_236a;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9077ULL: goto x86_l_2375;
	case 9084ULL: goto x86_l_237c;
	case 9086ULL: goto x86_l_237e;
	case 9093ULL: goto x86_l_2385;
	case 9096ULL: goto x86_l_2388;
	case 9098ULL: goto x86_l_238a;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9127ULL: goto x86_l_23a7;
	case 9133ULL: goto x86_l_23ad;
	case 9137ULL: goto x86_l_23b1;
	case 9141ULL: goto x86_l_23b5;
	case 9143ULL: goto x86_l_23b7;
	case 9149ULL: goto x86_l_23bd;
	case 9153ULL: goto x86_l_23c1;
	case 9159ULL: goto x86_l_23c7;
	case 9164ULL: goto x86_l_23cc;
	case 9168ULL: goto x86_l_23d0;
	case 9175ULL: goto x86_l_23d7;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9192ULL: goto x86_l_23e8;
	case 9196ULL: goto x86_l_23ec;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9217ULL: goto x86_l_2401;
	case 9221ULL: goto x86_l_2405;
	case 9225ULL: goto x86_l_2409;
	case 9229ULL: goto x86_l_240d;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9244ULL: goto x86_l_241c;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9255ULL: goto x86_l_2427;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9269ULL: goto x86_l_2435;
	case 9276ULL: goto x86_l_243c;
	case 9278ULL: goto x86_l_243e;
	case 9280ULL: goto x86_l_2440;
	case 9284ULL: goto x86_l_2444;
	case 9288ULL: goto x86_l_2448;
	case 9290ULL: goto x86_l_244a;
	case 9296ULL: goto x86_l_2450;
	case 9301ULL: goto x86_l_2455;
	case 9306ULL: goto x86_l_245a;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9315ULL: goto x86_l_2463;
	case 9317ULL: goto x86_l_2465;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9328ULL: goto x86_l_2470;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9336ULL: goto x86_l_2478;
	case 9346ULL: goto x86_l_2482;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9361ULL: goto x86_l_2491;
	case 9365ULL: goto x86_l_2495;
	case 9369ULL: goto x86_l_2499;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9380ULL: goto x86_l_24a4;
	case 9384ULL: goto x86_l_24a8;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9402ULL: goto x86_l_24ba;
	case 9404ULL: goto x86_l_24bc;
	case 9407ULL: goto x86_l_24bf;
	case 9410ULL: goto x86_l_24c2;
	case 9412ULL: goto x86_l_24c4;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9425ULL: goto x86_l_24d1;
	case 9429ULL: goto x86_l_24d5;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9437ULL: goto x86_l_24dd;
	case 9439ULL: goto x86_l_24df;
	case 9443ULL: goto x86_l_24e3;
	case 9447ULL: goto x86_l_24e7;
	case 9450ULL: goto x86_l_24ea;
	case 9453ULL: goto x86_l_24ed;
	case 9456ULL: goto x86_l_24f0;
	case 9461ULL: goto x86_l_24f5;
	case 9468ULL: goto x86_l_24fc;
	case 9477ULL: goto x86_l_2505;
	case 9483ULL: goto x86_l_250b;
	case 9492ULL: goto x86_l_2514;
	case 9496ULL: goto x86_l_2518;
	case 9503ULL: goto x86_l_251f;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9512ULL: goto x86_l_2528;
	case 9516ULL: goto x86_l_252c;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9528ULL: goto x86_l_2538;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9544ULL: goto x86_l_2548;
	case 9547ULL: goto x86_l_254b;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9572ULL: goto x86_l_2564;
	case 9575ULL: goto x86_l_2567;
	case 9580ULL: goto x86_l_256c;
	case 9584ULL: goto x86_l_2570;
	case 9591ULL: goto x86_l_2577;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9599ULL: goto x86_l_257f;
	case 9601ULL: goto x86_l_2581;
	case 9605ULL: goto x86_l_2585;
	case 9607ULL: goto x86_l_2587;
	case 9612ULL: goto x86_l_258c;
	case 9616ULL: goto x86_l_2590;
	case 9619ULL: goto x86_l_2593;
	case 9621ULL: goto x86_l_2595;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9635ULL: goto x86_l_25a3;
	case 9640ULL: goto x86_l_25a8;
	case 9643ULL: goto x86_l_25ab;
	case 9645ULL: goto x86_l_25ad;
	case 9647ULL: goto x86_l_25af;
	case 9649ULL: goto x86_l_25b1;
	case 9651ULL: goto x86_l_25b3;
	case 9656ULL: goto x86_l_25b8;
	case 9660ULL: goto x86_l_25bc;
	case 9662ULL: goto x86_l_25be;
	case 9670ULL: goto x86_l_25c6;
	case 9675ULL: goto x86_l_25cb;
	case 9682ULL: goto x86_l_25d2;
	case 9685ULL: goto x86_l_25d5;
	case 9690ULL: goto x86_l_25da;
	case 9692ULL: goto x86_l_25dc;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9707ULL: goto x86_l_25eb;
	case 9710ULL: goto x86_l_25ee;
	case 9714ULL: goto x86_l_25f2;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9729ULL: goto x86_l_2601;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9739ULL: goto x86_l_260b;
	case 9744ULL: goto x86_l_2610;
	case 9749ULL: goto x86_l_2615;
	case 9751ULL: goto x86_l_2617;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9785ULL: goto x86_l_2639;
	case 9790ULL: goto x86_l_263e;
	case 9792ULL: goto x86_l_2640;
	case 9795ULL: goto x86_l_2643;
	case 9797ULL: goto x86_l_2645;
	case 9800ULL: goto x86_l_2648;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9810ULL: goto x86_l_2652;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9823ULL: goto x86_l_265f;
	case 9827ULL: goto x86_l_2663;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9840ULL: goto x86_l_2670;
	case 9844ULL: goto x86_l_2674;
	case 9848ULL: goto x86_l_2678;
	case 9852ULL: goto x86_l_267c;
	case 9856ULL: goto x86_l_2680;
	case 9858ULL: goto x86_l_2682;
	case 9863ULL: goto x86_l_2687;
	case 9865ULL: goto x86_l_2689;
	case 9867ULL: goto x86_l_268b;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9878ULL: goto x86_l_2696;
	case 9880ULL: goto x86_l_2698;
	case 9882ULL: goto x86_l_269a;
	case 9886ULL: goto x86_l_269e;
	case 9896ULL: goto x86_l_26a8;
	case 9899ULL: goto x86_l_26ab;
	case 9904ULL: goto x86_l_26b0;
	case 9908ULL: goto x86_l_26b4;
	case 9911ULL: goto x86_l_26b7;
	case 9914ULL: goto x86_l_26ba;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9927ULL: goto x86_l_26c7;
	case 9930ULL: goto x86_l_26ca;
	case 9934ULL: goto x86_l_26ce;
	case 9937ULL: goto x86_l_26d1;
	case 9941ULL: goto x86_l_26d5;
	case 9943ULL: goto x86_l_26d7;
	case 9950ULL: goto x86_l_26de;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9958ULL: goto x86_l_26e6;
	case 9960ULL: goto x86_l_26e8;
	case 9965ULL: goto x86_l_26ed;
	case 9967ULL: goto x86_l_26ef;
	case 9970ULL: goto x86_l_26f2;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9977ULL: goto x86_l_26f9;
	case 9982ULL: goto x86_l_26fe;
	case 9988ULL: goto x86_l_2704;
	case 9990ULL: goto x86_l_2706;
	case 9993ULL: goto x86_l_2709;
	case 9999ULL: goto x86_l_270f;
	case 10002ULL: goto x86_l_2712;
	case 10006ULL: goto x86_l_2716;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10021ULL: goto x86_l_2725;
	case 10029ULL: goto x86_l_272d;
	case 10031ULL: goto x86_l_272f;
	case 10035ULL: goto x86_l_2733;
	case 10037ULL: goto x86_l_2735;
	case 10040ULL: goto x86_l_2738;
	case 10043ULL: goto x86_l_273b;
	case 10045ULL: goto x86_l_273d;
	case 10049ULL: goto x86_l_2741;
	case 10053ULL: goto x86_l_2745;
	case 10055ULL: goto x86_l_2747;
	case 10060ULL: goto x86_l_274c;
	case 10066ULL: goto x86_l_2752;
	case 10070ULL: goto x86_l_2756;
	case 10074ULL: goto x86_l_275a;
	case 10076ULL: goto x86_l_275c;
	case 10083ULL: goto x86_l_2763;
	case 10087ULL: goto x86_l_2767;
	case 10091ULL: goto x86_l_276b;
	case 10096ULL: goto x86_l_2770;
	case 10100ULL: goto x86_l_2774;
	case 10102ULL: goto x86_l_2776;
	case 10107ULL: goto x86_l_277b;
	case 10109ULL: goto x86_l_277d;
	case 10111ULL: goto x86_l_277f;
	case 10115ULL: goto x86_l_2783;
	case 10117ULL: goto x86_l_2785;
	case 10122ULL: goto x86_l_278a;
	case 10124ULL: goto x86_l_278c;
	case 10126ULL: goto x86_l_278e;
	case 10130ULL: goto x86_l_2792;
	case 10140ULL: goto x86_l_279c;
	case 10143ULL: goto x86_l_279f;
	case 10148ULL: goto x86_l_27a4;
	case 10152ULL: goto x86_l_27a8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21a9:
	/* 0x21a9: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_21ac:
	/* 0x21ac: jmp    48 <tail_handle_ipv4_from_netdev+0x48> */
	return 72ULL;
x86_l_21b1:
	/* 0x21b1: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_21ba:
	/* 0x21ba: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21bf:
	/* 0x21bf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21c4:
	/* 0x21c4: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_21cb:
	/* 0x21cb: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_21d3:
	/* 0x21d3: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21d8:
	/* 0x21d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21da:
	/* 0x21da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21dc:
	/* 0x21dc: movzx  edx,WORD PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_21e2:
	/* 0x21e2: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_21e9:
	/* 0x21e9: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21ec:
	/* 0x21ec: mov    DWORD PTR [rbx+0x28],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21f0:
	/* 0x21f0: mov    QWORD PTR [rbx+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_21f8:
	/* 0x21f8: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2200:
	/* 0x2200: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2205:
	/* 0x2205: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_call_policy)));
x86_l_220c:
	/* 0x220c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_220f:
	/* 0x220f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2211:
	/* 0x2211: mov    ebp,0xffffff35 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967093ULL);
x86_l_2216:
	/* 0x2216: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2219:
	/* 0x2219: jmp    48 <tail_handle_ipv4_from_netdev+0x48> */
	return 72ULL;
x86_l_221e:
	/* 0x221e: mov    WORD PTR [rsp+0x38],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2224:
	/* 0x2224: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2229:
	/* 0x2229: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_222e:
	/* 0x222e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2231:
	/* 0x2231: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2234:
	/* 0x2234: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2239:
	/* 0x2239: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_223e:
	/* 0x223e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2241:
	/* 0x2241: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2243:
	/* 0x2243: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2245:
	/* 0x2245: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224a:
	/* 0x224a: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_224d:
	/* 0x224d: jns    213b <tail_handle_ipv4_from_netdev+0x213b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 8507ULL;
	}
x86_l_2253:
	/* 0x2253: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2258:
	/* 0x2258: jmp    48 <tail_handle_ipv4_from_netdev+0x48> */
	return 72ULL;
x86_l_225d:
	/* 0x225d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_225f:
	/* 0x225f: mov    esi,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967155ULL);
x86_l_2264:
	/* 0x2264: jmp    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	return 7544ULL;
x86_l_2269:
	/* 0x2269: mov    DWORD PTR [rsp+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_226e:
	/* 0x226e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2272:
	/* 0x2272: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2274:
	/* 0x2274: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2276:
	/* 0x2276: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_2278:
	/* 0x2278: je     237e <tail_handle_ipv4_from_netdev+0x237e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237e;
	}
x86_l_227e:
	/* 0x227e: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2285:
	/* 0x2285: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2289:
	/* 0x2289: je     229c <tail_handle_ipv4_from_netdev+0x229c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_229c;
	}
x86_l_228b:
	/* 0x228b: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2292:
	/* 0x2292: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2296:
	/* 0x2296: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_229a:
	/* 0x229a: jmp    22a2 <tail_handle_ipv4_from_netdev+0x22a2> */
	goto x86_l_22a2;
x86_l_229c:
	/* 0x229c: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_22a2:
	/* 0x22a2: cmp    BYTE PTR [rsp+0xa8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505734ULL);
x86_l_22aa:
	/* 0x22aa: jne    22e9 <tail_handle_ipv4_from_netdev+0x22e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22e9;
	}
x86_l_22ac:
	/* 0x22ac: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b0:
	/* 0x22b0: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_22b2:
	/* 0x22b2: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_22b5:
	/* 0x22b5: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_22b8:
	/* 0x22b8: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_22ba:
	/* 0x22ba: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22be:
	/* 0x22be: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22c2:
	/* 0x22c2: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_22c5:
	/* 0x22c5: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_22ca:
	/* 0x22ca: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_22d0:
	/* 0x22d0: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_22d4:
	/* 0x22d4: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d8:
	/* 0x22d8: je     22e9 <tail_handle_ipv4_from_netdev+0x22e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e9;
	}
x86_l_22da:
	/* 0x22da: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_22e1:
	/* 0x22e1: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_22e5:
	/* 0x22e5: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_22e9:
	/* 0x22e9: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ee:
	/* 0x22ee: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_22f2:
	/* 0x22f2: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f6:
	/* 0x22f6: je     2307 <tail_handle_ipv4_from_netdev+0x2307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2307;
	}
x86_l_22f8:
	/* 0x22f8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_22fd:
	/* 0x22fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22ff:
	/* 0x22ff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2301:
	/* 0x2301: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2305:
	/* 0x2305: jmp    232a <tail_handle_ipv4_from_netdev+0x232a> */
	goto x86_l_232a;
x86_l_2307:
	/* 0x2307: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_230c:
	/* 0x230c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_230e:
	/* 0x230e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2310:
	/* 0x2310: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2314:
	/* 0x2314: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_231e:
	/* 0x231e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2321:
	/* 0x2321: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2326:
	/* 0x2326: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_232a:
	/* 0x232a: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_232d:
	/* 0x232d: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2331:
	/* 0x2331: mov    DWORD PTR [rdx+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2335:
	/* 0x2335: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2339:
	/* 0x2339: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_233c:
	/* 0x233c: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2340:
	/* 0x2340: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2344:
	/* 0x2344: je     2357 <tail_handle_ipv4_from_netdev+0x2357> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2357;
	}
x86_l_2346:
	/* 0x2346: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_234d:
	/* 0x234d: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_234f:
	/* 0x234f: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2352:
	/* 0x2352: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2355:
	/* 0x2355: jmp    235c <tail_handle_ipv4_from_netdev+0x235c> */
	goto x86_l_235c;
x86_l_2357:
	/* 0x2357: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_235c:
	/* 0x235c: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_235e:
	/* 0x235e: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2361:
	/* 0x2361: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2363:
	/* 0x2363: jb     236a <tail_handle_ipv4_from_netdev+0x236a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_236a;
	}
x86_l_2365:
	/* 0x2365: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_2368:
	/* 0x2368: je     237e <tail_handle_ipv4_from_netdev+0x237e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237e;
	}
x86_l_236a:
	/* 0x236a: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_236e:
	/* 0x236e: mov    BYTE PTR [rcx+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2372:
	/* 0x2372: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2375:
	/* 0x2375: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_237c:
	/* 0x237c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_237e:
	/* 0x237e: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2385:
	/* 0x2385: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2388:
	/* 0x2388: je     239b <tail_handle_ipv4_from_netdev+0x239b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239b;
	}
x86_l_238a:
	/* 0x238a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_238e:
	/* 0x238e: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_2393:
	/* 0x2393: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2396:
	/* 0x2396: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_239b:
	/* 0x239b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_239f:
	/* 0x239f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23a2:
	/* 0x23a2: je     23f5 <tail_handle_ipv4_from_netdev+0x23f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23f5;
	}
x86_l_23a4:
	/* 0x23a4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23a7:
	/* 0x23a7: jne    24f0 <tail_handle_ipv4_from_netdev+0x24f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24f0;
	}
x86_l_23ad:
	/* 0x23ad: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23b1:
	/* 0x23b1: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_23b5:
	/* 0x23b5: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_23b7:
	/* 0x23b7: je     24f0 <tail_handle_ipv4_from_netdev+0x24f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f0;
	}
x86_l_23bd:
	/* 0x23bd: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23c1:
	/* 0x23c1: mov    WORD PTR [rcx+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_23c7:
	/* 0x23c7: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_23cc:
	/* 0x23cc: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23d0:
	/* 0x23d0: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_23d7:
	/* 0x23d7: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23db:
	/* 0x23db: je     271f <tail_handle_ipv4_from_netdev+0x271f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_271f;
	}
x86_l_23e1:
	/* 0x23e1: mov    rcx,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_23e8:
	/* 0x23e8: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_23ec:
	/* 0x23ec: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_23f0:
	/* 0x23f0: jmp    2725 <tail_handle_ipv4_from_netdev+0x2725> */
	goto x86_l_2725;
x86_l_23f5:
	/* 0x23f5: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23f9:
	/* 0x23f9: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_23fe:
	/* 0x23fe: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2401:
	/* 0x2401: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_2405:
	/* 0x2405: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_2409:
	/* 0x2409: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240d:
	/* 0x240d: or     ax,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_2411:
	/* 0x2411: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2415:
	/* 0x2415: mov    r15,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_241c:
	/* 0x241c: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_241f:
	/* 0x241f: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2421:
	/* 0x2421: je     24f0 <tail_handle_ipv4_from_netdev+0x24f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f0;
	}
x86_l_2427:
	/* 0x2427: mov    r13,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_242e:
	/* 0x242e: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2433:
	/* 0x2433: je     244a <tail_handle_ipv4_from_netdev+0x244a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_244a;
	}
x86_l_2435:
	/* 0x2435: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_243c:
	/* 0x243c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243e:
	/* 0x243e: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2440:
	/* 0x2440: lea    r14d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2444:
	/* 0x2444: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2448:
	/* 0x2448: jmp    2450 <tail_handle_ipv4_from_netdev+0x2450> */
	goto x86_l_2450;
x86_l_244a:
	/* 0x244a: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_2450:
	/* 0x2450: shr    DWORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 68719476744ULL);
x86_l_2455:
	/* 0x2455: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_245a:
	/* 0x245a: je     246b <tail_handle_ipv4_from_netdev+0x246b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_246b;
	}
x86_l_245c:
	/* 0x245c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2461:
	/* 0x2461: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2463:
	/* 0x2463: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2465:
	/* 0x2465: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2469:
	/* 0x2469: jmp    248e <tail_handle_ipv4_from_netdev+0x248e> */
	goto x86_l_248e;
x86_l_246b:
	/* 0x246b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2470:
	/* 0x2470: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2472:
	/* 0x2472: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2474:
	/* 0x2474: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2478:
	/* 0x2478: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2482:
	/* 0x2482: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2485:
	/* 0x2485: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_248a:
	/* 0x248a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_248e:
	/* 0x248e: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2491:
	/* 0x2491: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2495:
	/* 0x2495: mov    DWORD PTR [rdx+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2499:
	/* 0x2499: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_249d:
	/* 0x249d: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24a0:
	/* 0x24a0: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24a4:
	/* 0x24a4: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_24a8:
	/* 0x24a8: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ac:
	/* 0x24ac: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b1:
	/* 0x24b1: je     24c4 <tail_handle_ipv4_from_netdev+0x24c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24c4;
	}
x86_l_24b3:
	/* 0x24b3: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_24ba:
	/* 0x24ba: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24bc:
	/* 0x24bc: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_24bf:
	/* 0x24bf: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_24c2:
	/* 0x24c2: jmp    24c9 <tail_handle_ipv4_from_netdev+0x24c9> */
	goto x86_l_24c9;
x86_l_24c4:
	/* 0x24c4: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_24c9:
	/* 0x24c9: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24cb:
	/* 0x24cb: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24cf:
	/* 0x24cf: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_24d1:
	/* 0x24d1: mov    DWORD PTR [rsp+0x10],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24d5:
	/* 0x24d5: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_24d7:
	/* 0x24d7: jb     24df <tail_handle_ipv4_from_netdev+0x24df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24df;
	}
x86_l_24d9:
	/* 0x24d9: cmp    cl,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_24dd:
	/* 0x24dd: je     24f0 <tail_handle_ipv4_from_netdev+0x24f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f0;
	}
x86_l_24df:
	/* 0x24df: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e3:
	/* 0x24e3: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e7:
	/* 0x24e7: mov    BYTE PTR [rcx+0x2a],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_24ea:
	/* 0x24ea: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24ed:
	/* 0x24ed: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24f0:
	/* 0x24f0: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_24f5:
	/* 0x24f5: mov    r14,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_24fc:
	/* 0x24fc: cmp    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_2505:
	/* 0x2505: jne    1f86 <tail_handle_ipv4_from_netdev+0x1f86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8070ULL;
	}
x86_l_250b:
	/* 0x250b: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2514:
	/* 0x2514: movzx  r14d,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2518:
	/* 0x2518: mov    r12,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_251f:
	/* 0x251f: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2522:
	/* 0x2522: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_2525:
	/* 0x2525: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2528:
	/* 0x2528: lea    rcx,[r12+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_252c:
	/* 0x252c: add    rcx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_2530:
	/* 0x2530: mov    esi,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967162ULL);
x86_l_2535:
	/* 0x2535: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2538:
	/* 0x2538: ja     1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7542ULL;
	}
x86_l_253e:
	/* 0x253e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2543:
	/* 0x2543: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2548:
	/* 0x2548: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_254b:
	/* 0x254b: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_2550:
	/* 0x2550: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2555:
	/* 0x2555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2557:
	/* 0x2557: mov    esi,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967162ULL);
x86_l_255c:
	/* 0x255c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_255e:
	/* 0x255e: js     1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7542ULL;
	}
x86_l_2564:
	/* 0x2564: add    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2567:
	/* 0x2567: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_256c:
	/* 0x256c: add    r12,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2570:
	/* 0x2570: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_2577:
	/* 0x2577: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_257a:
	/* 0x257a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257c:
	/* 0x257c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_257f:
	/* 0x257f: je     2597 <tail_handle_ipv4_from_netdev+0x2597> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2597;
	}
x86_l_2581:
	/* 0x2581: mov    ecx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2585:
	/* 0x2585: xor    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 0ULL);
x86_l_2587:
	/* 0x2587: movzx  edx,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_258c:
	/* 0x258c: xor    dx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 4ULL);
x86_l_2590:
	/* 0x2590: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2593:
	/* 0x2593: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2595:
	/* 0x2595: je     25b3 <tail_handle_ipv4_from_netdev+0x25b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b3;
	}
x86_l_2597:
	/* 0x2597: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_259c:
	/* 0x259c: mov    rdi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_25a3:
	/* 0x25a3: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25a8:
	/* 0x25a8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_25ab:
	/* 0x25ab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25ad:
	/* 0x25ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25af:
	/* 0x25af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25b1:
	/* 0x25b1: js     2615 <tail_handle_ipv4_from_netdev+0x2615> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2615;
	}
x86_l_25b3:
	/* 0x25b3: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25b8:
	/* 0x25b8: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_25bc:
	/* 0x25bc: js     25e6 <tail_handle_ipv4_from_netdev+0x25e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25e6;
	}
x86_l_25be:
	/* 0x25be: mov    QWORD PTR [rbx+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_25c6:
	/* 0x25c6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_25cb:
	/* 0x25cb: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_25d2:
	/* 0x25d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25d5:
	/* 0x25d5: mov    edx,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 15ULL);
x86_l_25da:
	/* 0x25da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25dc:
	/* 0x25dc: mov    eax,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 15ULL);
x86_l_25e1:
	/* 0x25e1: jmp    171c <tail_handle_ipv4_from_netdev+0x171c> */
	return 5916ULL;
x86_l_25e6:
	/* 0x25e6: movzx  eax,WORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 116ULL);
x86_l_25eb:
	/* 0x25eb: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25ee:
	/* 0x25ee: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25f2:
	/* 0x25f2: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_25f5:
	/* 0x25f5: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_25fa:
	/* 0x25fa: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2601:
	/* 0x2601: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2604:
	/* 0x2604: mov    edx,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2609:
	/* 0x2609: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260b:
	/* 0x260b: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_2610:
	/* 0x2610: jmp    171c <tail_handle_ipv4_from_netdev+0x171c> */
	return 5916ULL;
x86_l_2615:
	/* 0x2615: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2617:
	/* 0x2617: jmp    1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	return 7542ULL;
x86_l_261c:
	/* 0x261c: mov    esi,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967141ULL);
x86_l_2621:
	/* 0x2621: jmp    1d78 <tail_handle_ipv4_from_netdev+0x1d78> */
	return 7544ULL;
x86_l_2626:
	/* 0x2626: mov    DWORD PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_262e:
	/* 0x262e: jmp    1d6c <tail_handle_ipv4_from_netdev+0x1d6c> */
	return 7532ULL;
x86_l_2633:
	/* 0x2633: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_2639:
	/* 0x2639: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_263e:
	/* 0x263e: jne    2678 <tail_handle_ipv4_from_netdev+0x2678> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2678;
	}
x86_l_2640:
	/* 0x2640: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2643:
	/* 0x2643: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2645:
	/* 0x2645: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2648:
	/* 0x2648: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_264b:
	/* 0x264b: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_264d:
	/* 0x264d: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2652:
	/* 0x2652: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2654:
	/* 0x2654: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2659:
	/* 0x2659: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_265f:
	/* 0x265f: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2663:
	/* 0x2663: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2667:
	/* 0x2667: je     2678 <tail_handle_ipv4_from_netdev+0x2678> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2678;
	}
x86_l_2669:
	/* 0x2669: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2670:
	/* 0x2670: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2674:
	/* 0x2674: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2678:
	/* 0x2678: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_267c:
	/* 0x267c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2680:
	/* 0x2680: je     2691 <tail_handle_ipv4_from_netdev+0x2691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2691;
	}
x86_l_2682:
	/* 0x2682: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2687:
	/* 0x2687: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2689:
	/* 0x2689: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_268b:
	/* 0x268b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_268f:
	/* 0x268f: jmp    26b4 <tail_handle_ipv4_from_netdev+0x26b4> */
	goto x86_l_26b4;
x86_l_2691:
	/* 0x2691: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2696:
	/* 0x2696: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2698:
	/* 0x2698: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_269a:
	/* 0x269a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_269e:
	/* 0x269e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_26a8:
	/* 0x26a8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_26ab:
	/* 0x26ab: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_26b0:
	/* 0x26b0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_26b4:
	/* 0x26b4: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26b7:
	/* 0x26b7: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_26ba:
	/* 0x26ba: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26be:
	/* 0x26be: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_26c3:
	/* 0x26c3: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26c7:
	/* 0x26c7: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ca:
	/* 0x26ca: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_26ce:
	/* 0x26ce: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d1:
	/* 0x26d1: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d5:
	/* 0x26d5: je     26e8 <tail_handle_ipv4_from_netdev+0x26e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e8;
	}
x86_l_26d7:
	/* 0x26d7: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_26de:
	/* 0x26de: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26e0:
	/* 0x26e0: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_26e3:
	/* 0x26e3: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_26e6:
	/* 0x26e6: jmp    26ed <tail_handle_ipv4_from_netdev+0x26ed> */
	goto x86_l_26ed;
x86_l_26e8:
	/* 0x26e8: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_26ed:
	/* 0x26ed: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26ef:
	/* 0x26ef: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f2:
	/* 0x26f2: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_26f4:
	/* 0x26f4: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f7:
	/* 0x26f7: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_26f9:
	/* 0x26f9: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_26fe:
	/* 0x26fe: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_2704:
	/* 0x2704: jb     270f <tail_handle_ipv4_from_netdev+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_270f;
	}
x86_l_2706:
	/* 0x2706: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2709:
	/* 0x2709: je     a81 <tail_handle_ipv4_from_netdev+0xa81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2689ULL;
	}
x86_l_270f:
	/* 0x270f: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2712:
	/* 0x2712: mov    BYTE PTR [r14+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2716:
	/* 0x2716: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_271a:
	/* 0x271a: jmp    a78 <tail_handle_ipv4_from_netdev+0xa78> */
	return 2680ULL;
x86_l_271f:
	/* 0x271f: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_2725:
	/* 0x2725: cmp    BYTE PTR [rsp+0xa8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505734ULL);
x86_l_272d:
	/* 0x272d: jne    276b <tail_handle_ipv4_from_netdev+0x276b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_276b;
	}
x86_l_272f:
	/* 0x272f: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2733:
	/* 0x2733: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2735:
	/* 0x2735: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2738:
	/* 0x2738: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_273b:
	/* 0x273b: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_273d:
	/* 0x273d: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2741:
	/* 0x2741: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2745:
	/* 0x2745: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2747:
	/* 0x2747: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_274c:
	/* 0x274c: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_2752:
	/* 0x2752: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2756:
	/* 0x2756: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_275a:
	/* 0x275a: je     276b <tail_handle_ipv4_from_netdev+0x276b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_276b;
	}
x86_l_275c:
	/* 0x275c: mov    rax,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2763:
	/* 0x2763: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2767:
	/* 0x2767: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_276b:
	/* 0x276b: shr    DWORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 68719476744ULL);
x86_l_2770:
	/* 0x2770: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2774:
	/* 0x2774: je     2785 <tail_handle_ipv4_from_netdev+0x2785> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2785;
	}
x86_l_2776:
	/* 0x2776: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_277b:
	/* 0x277b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_277d:
	/* 0x277d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_277f:
	/* 0x277f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2783:
	/* 0x2783: jmp    27a8 <tail_handle_ipv4_from_netdev+0x27a8> */
	goto x86_l_27a8;
x86_l_2785:
	/* 0x2785: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_278a:
	/* 0x278a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_278c:
	/* 0x278c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_278e:
	/* 0x278e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2792:
	/* 0x2792: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_279c:
	/* 0x279c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_279f:
	/* 0x279f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_27a4:
	/* 0x27a4: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_27a8:
	/* 0x27a8: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
	return 10155ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10155ULL: goto x86_l_27ab;
	case 10159ULL: goto x86_l_27af;
	case 10163ULL: goto x86_l_27b3;
	case 10167ULL: goto x86_l_27b7;
	case 10170ULL: goto x86_l_27ba;
	case 10174ULL: goto x86_l_27be;
	case 10178ULL: goto x86_l_27c2;
	case 10182ULL: goto x86_l_27c6;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10205ULL: goto x86_l_27dd;
	case 10210ULL: goto x86_l_27e2;
	case 10212ULL: goto x86_l_27e4;
	case 10216ULL: goto x86_l_27e8;
	case 10218ULL: goto x86_l_27ea;
	case 10222ULL: goto x86_l_27ee;
	case 10224ULL: goto x86_l_27f0;
	case 10229ULL: goto x86_l_27f5;
	case 10231ULL: goto x86_l_27f7;
	case 10235ULL: goto x86_l_27fb;
	case 10241ULL: goto x86_l_2801;
	case 10245ULL: goto x86_l_2805;
	case 10249ULL: goto x86_l_2809;
	case 10252ULL: goto x86_l_280c;
	case 10255ULL: goto x86_l_280f;
	case 10260ULL: goto x86_l_2814;
	case 10262ULL: goto x86_l_2816;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27ab:
	/* 0x27ab: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27af:
	/* 0x27af: mov    DWORD PTR [rdx+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27b3:
	/* 0x27b3: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_27b7:
	/* 0x27b7: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ba:
	/* 0x27ba: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27be:
	/* 0x27be: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_27c2:
	/* 0x27c2: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c6:
	/* 0x27c6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ca:
	/* 0x27ca: je     27dd <tail_handle_ipv4_from_netdev+0x27dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27dd;
	}
x86_l_27cc:
	/* 0x27cc: mov    rsi,QWORD PTR [rip+0xae07] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_27d3:
	/* 0x27d3: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d5:
	/* 0x27d5: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_27d8:
	/* 0x27d8: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_27db:
	/* 0x27db: jmp    27e2 <tail_handle_ipv4_from_netdev+0x27e2> */
	goto x86_l_27e2;
x86_l_27dd:
	/* 0x27dd: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_27e2:
	/* 0x27e2: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27e4:
	/* 0x27e4: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e8:
	/* 0x27e8: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_27ea:
	/* 0x27ea: mov    DWORD PTR [rsp+0x10],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27ee:
	/* 0x27ee: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_27f0:
	/* 0x27f0: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_27f5:
	/* 0x27f5: jb     2801 <tail_handle_ipv4_from_netdev+0x2801> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2801;
	}
x86_l_27f7:
	/* 0x27f7: cmp    cl,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_27fb:
	/* 0x27fb: je     1ddb <tail_handle_ipv4_from_netdev+0x1ddb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7643ULL;
	}
x86_l_2801:
	/* 0x2801: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2805:
	/* 0x2805: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2809:
	/* 0x2809: mov    BYTE PTR [rcx+0x2a],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_280c:
	/* 0x280c: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_280f:
	/* 0x280f: jmp    1dd2 <tail_handle_ipv4_from_netdev+0x1dd2> */
	return 7634ULL;
x86_l_2814:
	/* 0x2814: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_2816:
	/* 0x2816: jmp    1d76 <tail_handle_ipv4_from_netdev+0x1d76> */
	return 7542ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9340U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1898ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1903ULL && __x86_pc <= 3565ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3573ULL && __x86_pc <= 5168ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5170ULL && __x86_pc <= 6877ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6882ULL && __x86_pc <= 8615ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8617ULL && __x86_pc <= 10152ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10155ULL && __x86_pc <= 10262ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv4_from_netdev_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

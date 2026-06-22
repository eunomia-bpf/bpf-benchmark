extern char __aux_snat_v6_args;
extern char __aux_snat_v6_nhm_nat_entry;
extern char __aux_snat_v6_nhm_tuple;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_extended_ip_protocols;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_remote_node_masquerade;
extern char __config_eth_header_length;
extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_host_ep_id;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_nat_ipv6_masquerade;
extern char __config_nodeport_port_max;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char __config_trace_payload_len_overlay;
extern char __config_tracing_ip_option_type;
extern char __config_tunnel_protocol;
extern char _aux_max_off;
extern char _aux_stride;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_egress_gw_policy_v6;
extern char cilium_events;
extern char cilium_ipcache_v2;
extern char cilium_ipmasq_v6;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_signals;
extern char cilium_snat_v6_alloc_retries;
extern char cilium_snat_v6_external;
extern char fib_params_storage;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_0(
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
	case 29ULL: goto x86_l_1d;
	case 34ULL: goto x86_l_22;
	case 36ULL: goto x86_l_24;
	case 38ULL: goto x86_l_26;
	case 45ULL: goto x86_l_2d;
	case 47ULL: goto x86_l_2f;
	case 51ULL: goto x86_l_33;
	case 58ULL: goto x86_l_3a;
	case 61ULL: goto x86_l_3d;
	case 63ULL: goto x86_l_3f;
	case 66ULL: goto x86_l_42;
	case 73ULL: goto x86_l_49;
	case 82ULL: goto x86_l_52;
	case 91ULL: goto x86_l_5b;
	case 100ULL: goto x86_l_64;
	case 109ULL: goto x86_l_6d;
	case 118ULL: goto x86_l_76;
	case 127ULL: goto x86_l_7f;
	case 136ULL: goto x86_l_88;
	case 145ULL: goto x86_l_91;
	case 154ULL: goto x86_l_9a;
	case 163ULL: goto x86_l_a3;
	case 169ULL: goto x86_l_a9;
	case 176ULL: goto x86_l_b0;
	case 179ULL: goto x86_l_b3;
	case 181ULL: goto x86_l_b5;
	case 187ULL: goto x86_l_bb;
	case 195ULL: goto x86_l_c3;
	case 202ULL: goto x86_l_ca;
	case 205ULL: goto x86_l_cd;
	case 209ULL: goto x86_l_d1;
	case 212ULL: goto x86_l_d4;
	case 216ULL: goto x86_l_d8;
	case 220ULL: goto x86_l_dc;
	case 225ULL: goto x86_l_e1;
	case 228ULL: goto x86_l_e4;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 245ULL: goto x86_l_f5;
	case 251ULL: goto x86_l_fb;
	case 255ULL: goto x86_l_ff;
	case 258ULL: goto x86_l_102;
	case 260ULL: goto x86_l_104;
	case 265ULL: goto x86_l_109;
	case 269ULL: goto x86_l_10d;
	case 275ULL: goto x86_l_113;
	case 280ULL: goto x86_l_118;
	case 290ULL: goto x86_l_122;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 305ULL: goto x86_l_131;
	case 309ULL: goto x86_l_135;
	case 314ULL: goto x86_l_13a;
	case 319ULL: goto x86_l_13f;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 330ULL: goto x86_l_14a;
	case 332ULL: goto x86_l_14c;
	case 334ULL: goto x86_l_14e;
	case 340ULL: goto x86_l_154;
	case 345ULL: goto x86_l_159;
	case 349ULL: goto x86_l_15d;
	case 351ULL: goto x86_l_15f;
	case 355ULL: goto x86_l_163;
	case 357ULL: goto x86_l_165;
	case 361ULL: goto x86_l_169;
	case 363ULL: goto x86_l_16b;
	case 368ULL: goto x86_l_170;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 383ULL: goto x86_l_17f;
	case 391ULL: goto x86_l_187;
	case 395ULL: goto x86_l_18b;
	case 397ULL: goto x86_l_18d;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 407ULL: goto x86_l_197;
	case 409ULL: goto x86_l_199;
	case 413ULL: goto x86_l_19d;
	case 417ULL: goto x86_l_1a1;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 432ULL: goto x86_l_1b0;
	case 436ULL: goto x86_l_1b4;
	case 442ULL: goto x86_l_1ba;
	case 447ULL: goto x86_l_1bf;
	case 450ULL: goto x86_l_1c2;
	case 455ULL: goto x86_l_1c7;
	case 460ULL: goto x86_l_1cc;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 482ULL: goto x86_l_1e2;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 492ULL: goto x86_l_1ec;
	case 494ULL: goto x86_l_1ee;
	case 500ULL: goto x86_l_1f4;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 531ULL: goto x86_l_213;
	case 534ULL: goto x86_l_216;
	case 539ULL: goto x86_l_21b;
	case 543ULL: goto x86_l_21f;
	case 553ULL: goto x86_l_229;
	case 556ULL: goto x86_l_22c;
	case 561ULL: goto x86_l_231;
	case 565ULL: goto x86_l_235;
	case 568ULL: goto x86_l_238;
	case 573ULL: goto x86_l_23d;
	case 577ULL: goto x86_l_241;
	case 581ULL: goto x86_l_245;
	case 585ULL: goto x86_l_249;
	case 591ULL: goto x86_l_24f;
	case 594ULL: goto x86_l_252;
	case 604ULL: goto x86_l_25c;
	case 608ULL: goto x86_l_260;
	case 614ULL: goto x86_l_266;
	case 619ULL: goto x86_l_26b;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 634ULL: goto x86_l_27a;
	case 638ULL: goto x86_l_27e;
	case 642ULL: goto x86_l_282;
	case 647ULL: goto x86_l_287;
	case 652ULL: goto x86_l_28c;
	case 655ULL: goto x86_l_28f;
	case 658ULL: goto x86_l_292;
	case 663ULL: goto x86_l_297;
	case 665ULL: goto x86_l_299;
	case 667ULL: goto x86_l_29b;
	case 673ULL: goto x86_l_2a1;
	case 676ULL: goto x86_l_2a4;
	case 682ULL: goto x86_l_2aa;
	case 686ULL: goto x86_l_2ae;
	case 691ULL: goto x86_l_2b3;
	case 693ULL: goto x86_l_2b5;
	case 697ULL: goto x86_l_2b9;
	case 702ULL: goto x86_l_2be;
	case 704ULL: goto x86_l_2c0;
	case 708ULL: goto x86_l_2c4;
	case 713ULL: goto x86_l_2c9;
	case 715ULL: goto x86_l_2cb;
	case 720ULL: goto x86_l_2d0;
	case 727ULL: goto x86_l_2d7;
	case 732ULL: goto x86_l_2dc;
	case 737ULL: goto x86_l_2e1;
	case 742ULL: goto x86_l_2e6;
	case 747ULL: goto x86_l_2eb;
	case 754ULL: goto x86_l_2f2;
	case 757ULL: goto x86_l_2f5;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 769ULL: goto x86_l_301;
	case 778ULL: goto x86_l_30a;
	case 783ULL: goto x86_l_30f;
	case 788ULL: goto x86_l_314;
	case 791ULL: goto x86_l_317;
	case 794ULL: goto x86_l_31a;
	case 799ULL: goto x86_l_31f;
	case 801ULL: goto x86_l_321;
	case 803ULL: goto x86_l_323;
	case 809ULL: goto x86_l_329;
	case 813ULL: goto x86_l_32d;
	case 818ULL: goto x86_l_332;
	case 822ULL: goto x86_l_336;
	case 825ULL: goto x86_l_339;
	case 830ULL: goto x86_l_33e;
	case 840ULL: goto x86_l_348;
	case 843ULL: goto x86_l_34b;
	case 848ULL: goto x86_l_350;
	case 852ULL: goto x86_l_354;
	case 862ULL: goto x86_l_35e;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 888ULL: goto x86_l_378;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 901ULL: goto x86_l_385;
	case 911ULL: goto x86_l_38f;
	case 915ULL: goto x86_l_393;
	case 921ULL: goto x86_l_399;
	case 926ULL: goto x86_l_39e;
	case 931ULL: goto x86_l_3a3;
	case 936ULL: goto x86_l_3a8;
	case 939ULL: goto x86_l_3ab;
	case 944ULL: goto x86_l_3b0;
	case 949ULL: goto x86_l_3b5;
	case 952ULL: goto x86_l_3b8;
	case 956ULL: goto x86_l_3bc;
	case 961ULL: goto x86_l_3c1;
	case 963ULL: goto x86_l_3c3;
	case 965ULL: goto x86_l_3c5;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 987ULL: goto x86_l_3db;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 998ULL: goto x86_l_3e6;
	case 1002ULL: goto x86_l_3ea;
	case 1004ULL: goto x86_l_3ec;
	case 1009ULL: goto x86_l_3f1;
	case 1016ULL: goto x86_l_3f8;
	case 1021ULL: goto x86_l_3fd;
	case 1026ULL: goto x86_l_402;
	case 1031ULL: goto x86_l_407;
	case 1038ULL: goto x86_l_40e;
	case 1042ULL: goto x86_l_412;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1057ULL: goto x86_l_421;
	case 1060ULL: goto x86_l_424;
	case 1069ULL: goto x86_l_42d;
	case 1074ULL: goto x86_l_432;
	case 1079ULL: goto x86_l_437;
	case 1082ULL: goto x86_l_43a;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1093ULL: goto x86_l_445;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1105ULL: goto x86_l_451;
	case 1110ULL: goto x86_l_456;
	case 1114ULL: goto x86_l_45a;
	case 1117ULL: goto x86_l_45d;
	case 1122ULL: goto x86_l_462;
	case 1132ULL: goto x86_l_46c;
	case 1135ULL: goto x86_l_46f;
	case 1140ULL: goto x86_l_474;
	case 1144ULL: goto x86_l_478;
	case 1154ULL: goto x86_l_482;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1166ULL: goto x86_l_48e;
	case 1171ULL: goto x86_l_493;
	case 1174ULL: goto x86_l_496;
	case 1177ULL: goto x86_l_499;
	case 1181ULL: goto x86_l_49d;
	case 1183ULL: goto x86_l_49f;
	case 1187ULL: goto x86_l_4a3;
	case 1193ULL: goto x86_l_4a9;
	case 1196ULL: goto x86_l_4ac;
	case 1206ULL: goto x86_l_4b6;
	case 1210ULL: goto x86_l_4ba;
	case 1212ULL: goto x86_l_4bc;
	case 1215ULL: goto x86_l_4bf;
	case 1219ULL: goto x86_l_4c3;
	case 1224ULL: goto x86_l_4c8;
	case 1229ULL: goto x86_l_4cd;
	case 1232ULL: goto x86_l_4d0;
	case 1234ULL: goto x86_l_4d2;
	case 1237ULL: goto x86_l_4d5;
	case 1242ULL: goto x86_l_4da;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1251ULL: goto x86_l_4e3;
	case 1257ULL: goto x86_l_4e9;
	case 1260ULL: goto x86_l_4ec;
	case 1264ULL: goto x86_l_4f0;
	case 1270ULL: goto x86_l_4f6;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1285ULL: goto x86_l_505;
	case 1289ULL: goto x86_l_509;
	case 1295ULL: goto x86_l_50f;
	case 1300ULL: goto x86_l_514;
	case 1305ULL: goto x86_l_519;
	case 1308ULL: goto x86_l_51c;
	case 1312ULL: goto x86_l_520;
	case 1319ULL: goto x86_l_527;
	case 1325ULL: goto x86_l_52d;
	case 1327ULL: goto x86_l_52f;
	case 1330ULL: goto x86_l_532;
	case 1337ULL: goto x86_l_539;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1359ULL: goto x86_l_54f;
	case 1364ULL: goto x86_l_554;
	case 1368ULL: goto x86_l_558;
	case 1373ULL: goto x86_l_55d;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1385ULL: goto x86_l_569;
	case 1387ULL: goto x86_l_56b;
	case 1391ULL: goto x86_l_56f;
	case 1395ULL: goto x86_l_573;
	case 1397ULL: goto x86_l_575;
	case 1401ULL: goto x86_l_579;
	case 1404ULL: goto x86_l_57c;
	case 1406ULL: goto x86_l_57e;
	case 1411ULL: goto x86_l_583;
	case 1416ULL: goto x86_l_588;
	case 1419ULL: goto x86_l_58b;
	case 1427ULL: goto x86_l_593;
	case 1436ULL: goto x86_l_59c;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1467ULL: goto x86_l_5bb;
	case 1474ULL: goto x86_l_5c2;
	case 1477ULL: goto x86_l_5c5;
	case 1482ULL: goto x86_l_5ca;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1492ULL: goto x86_l_5d4;
	case 1498ULL: goto x86_l_5da;
	case 1504ULL: goto x86_l_5e0;
	case 1507ULL: goto x86_l_5e3;
	case 1509ULL: goto x86_l_5e5;
	case 1513ULL: goto x86_l_5e9;
	case 1519ULL: goto x86_l_5ef;
	case 1522ULL: goto x86_l_5f2;
	case 1527ULL: goto x86_l_5f7;
	case 1531ULL: goto x86_l_5fb;
	case 1536ULL: goto x86_l_600;
	case 1539ULL: goto x86_l_603;
	case 1541ULL: goto x86_l_605;
	case 1547ULL: goto x86_l_60b;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1561ULL: goto x86_l_619;
	case 1567ULL: goto x86_l_61f;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1594ULL: goto x86_l_63a;
	case 1598ULL: goto x86_l_63e;
	case 1600ULL: goto x86_l_640;
	case 1606ULL: goto x86_l_646;
	case 1613ULL: goto x86_l_64d;
	case 1615ULL: goto x86_l_64f;
	case 1617ULL: goto x86_l_651;
	case 1621ULL: goto x86_l_655;
	case 1629ULL: goto x86_l_65d;
	case 1631ULL: goto x86_l_65f;
	case 1637ULL: goto x86_l_665;
	case 1644ULL: goto x86_l_66c;
	case 1648ULL: goto x86_l_670;
	case 1654ULL: goto x86_l_676;
	case 1659ULL: goto x86_l_67b;
	case 1661ULL: goto x86_l_67d;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1673ULL: goto x86_l_689;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1696ULL: goto x86_l_6a0;
	case 1700ULL: goto x86_l_6a4;
	case 1704ULL: goto x86_l_6a8;
	case 1709ULL: goto x86_l_6ad;
	case 1712ULL: goto x86_l_6b0;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1723ULL: goto x86_l_6bb;
	case 1725ULL: goto x86_l_6bd;
	case 1728ULL: goto x86_l_6c0;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r15d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_18:
	/* 0x18: mov    BYTE PTR [rsp+0x3],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12884901888ULL);
x86_l_1d:
	/* 0x1d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22:
	/* 0x22: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24:
	/* 0x24: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_26:
	/* 0x26: mov    rcx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_2d:
	/* 0x2d: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f:
	/* 0x2f: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_33:
	/* 0x33: mov    rcx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_3a:
	/* 0x3a: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_3d:
	/* 0x3d: jbe    42 <tail_handle_snat_fwd_ipv6+0x42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_42;
	}
x86_l_3f:
	/* 0x3f: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42:
	/* 0x42: mov    r13,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__aux_snat_v6_args)));
x86_l_49:
	/* 0x49: mov    QWORD PTR [r13+rax*1+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 309237645312ULL);
x86_l_52:
	/* 0x52: mov    QWORD PTR [r13+rax*1+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 240518168576ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [r13+rax*1+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 274877906944ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [r13+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [r13+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_76:
	/* 0x76: mov    QWORD PTR [r13+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [r13+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [r13+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_91:
	/* 0x91: mov    QWORD PTR [r13+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [r13+rax*1+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a3:
	/* 0xa3: mov    BYTE PTR [r13+rax*1+0x48],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 309237645317ULL);
x86_l_a9:
	/* 0xa9: mov    rcx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_b0:
	/* 0xb0: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b3:
	/* 0xb3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b5:
	/* 0xb5: mov    WORD PTR [r13+rax*1+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 56ULL);
x86_l_bb:
	/* 0xbb: mov    WORD PTR [r13+rax*1+0x3a],0xffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 249108168703ULL);
x86_l_c3:
	/* 0xc3: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_ca:
	/* 0xca: movzx  ecx,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_cd:
	/* 0xcd: mov    r12d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_d1:
	/* 0xd1: mov    edx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d4:
	/* 0xd4: lea    rsi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_d8:
	/* 0xd8: add    rsi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_dc:
	/* 0xdc: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_e1:
	/* 0xe1: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e4:
	/* 0xe4: ja     b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2973ULL;
	}
x86_l_ea:
	/* 0xea: mov    DWORD PTR [rsp+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ef:
	/* 0xef: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f2:
	/* 0xf2: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f5:
	/* 0xf5: movzx  r15d,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_fb:
	/* 0xfb: mov    BYTE PTR [r13+0x24],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ff:
	/* 0xff: movzx  eax,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_102:
	/* 0x102: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104:
	/* 0x104: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_109:
	/* 0x109: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_10d:
	/* 0x10d: ja     539 <tail_handle_snat_fwd_ipv6+0x539> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_539;
	}
x86_l_113:
	/* 0x113: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_118:
	/* 0x118: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_122:
	/* 0x122: bt     rdx,r15 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_126:
	/* 0x126: jae    1b0 <tail_handle_snat_fwd_ipv6+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b0;
	}
x86_l_12c:
	/* 0x12c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_131:
	/* 0x131: lea    r14d,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_135:
	/* 0x135: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13a:
	/* 0x13a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_13f:
	/* 0x13f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_142:
	/* 0x142: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_145:
	/* 0x145: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_14a:
	/* 0x14a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c:
	/* 0x14c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14e:
	/* 0x14e: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2963ULL;
	}
x86_l_154:
	/* 0x154: movzx  edi,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_159:
	/* 0x159: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_15d:
	/* 0x15d: jle    17a <tail_handle_snat_fwd_ipv6+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_17a;
	}
x86_l_15f:
	/* 0x15f: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_163:
	/* 0x163: je     17a <tail_handle_snat_fwd_ipv6+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17a;
	}
x86_l_165:
	/* 0x165: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_169:
	/* 0x169: jne    1bf <tail_handle_snat_fwd_ipv6+0x1bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bf;
	}
x86_l_16b:
	/* 0x16b: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_170:
	/* 0x170: lea    r8d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_178:
	/* 0x178: jmp    197 <tail_handle_snat_fwd_ipv6+0x197> */
	goto x86_l_197;
x86_l_17a:
	/* 0x17a: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_17f:
	/* 0x17f: lea    r8d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_187:
	/* 0x187: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_18b:
	/* 0x18b: jne    197 <tail_handle_snat_fwd_ipv6+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_197;
	}
x86_l_18d:
	/* 0x18d: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192:
	/* 0x192: mov    r15d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_32);
x86_l_195:
	/* 0x195: jmp    1cc <tail_handle_snat_fwd_ipv6+0x1cc> */
	goto x86_l_1cc;
x86_l_197:
	/* 0x197: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199:
	/* 0x199: movzx  r14d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_19d:
	/* 0x19d: lea    ecx,[r8+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a1:
	/* 0x1a1: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1a5:
	/* 0x1a5: jbe    24f <tail_handle_snat_fwd_ipv6+0x24f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24f;
	}
x86_l_1ab:
	/* 0x1ab: jmp    52f <tail_handle_snat_fwd_ipv6+0x52f> */
	goto x86_l_52f;
x86_l_1b0:
	/* 0x1b0: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_1b4:
	/* 0x1b4: je     b98 <tail_handle_snat_fwd_ipv6+0xb98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2968ULL;
	}
x86_l_1ba:
	/* 0x1ba: jmp    539 <tail_handle_snat_fwd_ipv6+0x539> */
	goto x86_l_539;
x86_l_1bf:
	/* 0x1bf: mov    r15d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_32);
x86_l_1c2:
	/* 0x1c2: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1c7:
	/* 0x1c7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc:
	/* 0x1cc: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1d5:
	/* 0x1d5: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da:
	/* 0x1da: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1df:
	/* 0x1df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e2:
	/* 0x1e2: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1e5:
	/* 0x1e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ee:
	/* 0x1ee: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2963ULL;
	}
x86_l_1f4:
	/* 0x1f4: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1f8:
	/* 0x1f8: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1fd:
	/* 0x1fd: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_201:
	/* 0x201: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_204:
	/* 0x204: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_209:
	/* 0x209: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_213:
	/* 0x213: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_216:
	/* 0x216: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_21b:
	/* 0x21b: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_21f:
	/* 0x21f: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_229:
	/* 0x229: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22c:
	/* 0x22c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_231:
	/* 0x231: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_235:
	/* 0x235: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_238:
	/* 0x238: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23d:
	/* 0x23d: movzx  r14d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_241:
	/* 0x241: lea    ecx,[r8+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_245:
	/* 0x245: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_249:
	/* 0x249: ja     52f <tail_handle_snat_fwd_ipv6+0x52f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_52f;
	}
x86_l_24f:
	/* 0x24f: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_252:
	/* 0x252: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_25c:
	/* 0x25c: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_260:
	/* 0x260: jae    519 <tail_handle_snat_fwd_ipv6+0x519> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_519;
	}
x86_l_266:
	/* 0x266: mov    BYTE PTR [rsp+0x50],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26b:
	/* 0x26b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_270:
	/* 0x270: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_275:
	/* 0x275: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27a:
	/* 0x27a: lea    r15d,[r8+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_27e:
	/* 0x27e: add    r15d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_282:
	/* 0x282: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_287:
	/* 0x287: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_28c:
	/* 0x28c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_28f:
	/* 0x28f: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_292:
	/* 0x292: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_297:
	/* 0x297: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_299:
	/* 0x299: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29b:
	/* 0x29b: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2963ULL;
	}
x86_l_2a1:
	/* 0x2a1: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_2a4:
	/* 0x2a4: movzx  r15d,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_2aa:
	/* 0x2aa: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_2ae:
	/* 0x2ae: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b3:
	/* 0x2b3: jle    2dc <tail_handle_snat_fwd_ipv6+0x2dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2dc;
	}
x86_l_2b5:
	/* 0x2b5: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_2b9:
	/* 0x2b9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be:
	/* 0x2be: je     2f9 <tail_handle_snat_fwd_ipv6+0x2f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f9;
	}
x86_l_2c0:
	/* 0x2c0: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_2c4:
	/* 0x2c4: movzx  edx,BYTE PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 80ULL);
x86_l_2c9:
	/* 0x2c9: jne    2e6 <tail_handle_snat_fwd_ipv6+0x2e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e6;
	}
x86_l_2cb:
	/* 0x2cb: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2d0:
	/* 0x2d0: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d7:
	/* 0x2d7: jmp    372 <tail_handle_snat_fwd_ipv6+0x372> */
	goto x86_l_372;
x86_l_2dc:
	/* 0x2dc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e1:
	/* 0x2e1: movzx  edx,BYTE PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 80ULL);
x86_l_2e6:
	/* 0x2e6: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_2eb:
	/* 0x2eb: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2f2:
	/* 0x2f2: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_2f5:
	/* 0x2f5: je     2fe <tail_handle_snat_fwd_ipv6+0x2fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fe;
	}
x86_l_2f7:
	/* 0x2f7: jmp    372 <tail_handle_snat_fwd_ipv6+0x372> */
	goto x86_l_372;
x86_l_2f9:
	/* 0x2f9: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2fe:
	/* 0x2fe: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_301:
	/* 0x301: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_30a:
	/* 0x30a: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_30f:
	/* 0x30f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_314:
	/* 0x314: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_317:
	/* 0x317: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_31a:
	/* 0x31a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31f:
	/* 0x31f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321:
	/* 0x321: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_323:
	/* 0x323: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2963ULL;
	}
x86_l_329:
	/* 0x329: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_32d:
	/* 0x32d: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_332:
	/* 0x332: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_336:
	/* 0x336: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_339:
	/* 0x339: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_33e:
	/* 0x33e: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_348:
	/* 0x348: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_34b:
	/* 0x34b: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_350:
	/* 0x350: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_354:
	/* 0x354: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_35e:
	/* 0x35e: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_361:
	/* 0x361: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_366:
	/* 0x366: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_36a:
	/* 0x36a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36f:
	/* 0x36f: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_372:
	/* 0x372: movzx  r14d,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_376:
	/* 0x376: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_378:
	/* 0x378: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_37c:
	/* 0x37c: ja     532 <tail_handle_snat_fwd_ipv6+0x532> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_532;
	}
x86_l_382:
	/* 0x382: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_385:
	/* 0x385: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_38f:
	/* 0x38f: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_393:
	/* 0x393: jae    51c <tail_handle_snat_fwd_ipv6+0x51c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_51c;
	}
x86_l_399:
	/* 0x399: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39e:
	/* 0x39e: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a3:
	/* 0x3a3: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3a8:
	/* 0x3a8: lea    esi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3ab:
	/* 0x3ab: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b0:
	/* 0x3b0: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3b5:
	/* 0x3b5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3b8:
	/* 0x3b8: mov    DWORD PTR [rsp+0x50],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3bc:
	/* 0x3bc: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3c1:
	/* 0x3c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3:
	/* 0x3c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c5:
	/* 0x3c5: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2963ULL;
	}
x86_l_3cb:
	/* 0x3cb: movzx  edi,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_3d0:
	/* 0x3d0: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_3d4:
	/* 0x3d4: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d9:
	/* 0x3d9: jle    3fd <tail_handle_snat_fwd_ipv6+0x3fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3fd;
	}
x86_l_3db:
	/* 0x3db: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_3df:
	/* 0x3df: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e4:
	/* 0x3e4: je     419 <tail_handle_snat_fwd_ipv6+0x419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_419;
	}
x86_l_3e6:
	/* 0x3e6: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_3ea:
	/* 0x3ea: jne    402 <tail_handle_snat_fwd_ipv6+0x402> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_402;
	}
x86_l_3ec:
	/* 0x3ec: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_3f1:
	/* 0x3f1: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3f8:
	/* 0x3f8: jmp    499 <tail_handle_snat_fwd_ipv6+0x499> */
	goto x86_l_499;
x86_l_3fd:
	/* 0x3fd: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_402:
	/* 0x402: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_407:
	/* 0x407: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_40e:
	/* 0x40e: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_412:
	/* 0x412: je     41e <tail_handle_snat_fwd_ipv6+0x41e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41e;
	}
x86_l_414:
	/* 0x414: jmp    499 <tail_handle_snat_fwd_ipv6+0x499> */
	goto x86_l_499;
x86_l_419:
	/* 0x419: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_41e:
	/* 0x41e: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_421:
	/* 0x421: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_424:
	/* 0x424: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_42d:
	/* 0x42d: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_432:
	/* 0x432: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_437:
	/* 0x437: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_43a:
	/* 0x43a: mov    esi,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_43e:
	/* 0x43e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_443:
	/* 0x443: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_445:
	/* 0x445: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_447:
	/* 0x447: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2963ULL;
	}
x86_l_44d:
	/* 0x44d: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_451:
	/* 0x451: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_456:
	/* 0x456: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_45a:
	/* 0x45a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_45d:
	/* 0x45d: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_462:
	/* 0x462: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_46c:
	/* 0x46c: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_46f:
	/* 0x46f: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_474:
	/* 0x474: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_478:
	/* 0x478: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_482:
	/* 0x482: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_485:
	/* 0x485: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_48a:
	/* 0x48a: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_48e:
	/* 0x48e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_493:
	/* 0x493: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_496:
	/* 0x496: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_499:
	/* 0x499: movzx  r14d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_49d:
	/* 0x49d: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_49f:
	/* 0x49f: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_4a3:
	/* 0x4a3: ja     52f <tail_handle_snat_fwd_ipv6+0x52f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_52f;
	}
x86_l_4a9:
	/* 0x4a9: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_4ac:
	/* 0x4ac: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_4b6:
	/* 0x4b6: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4ba:
	/* 0x4ba: jae    519 <tail_handle_snat_fwd_ipv6+0x519> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_519;
	}
x86_l_4bc:
	/* 0x4bc: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_4bf:
	/* 0x4bf: add    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 88ULL);
x86_l_4c3:
	/* 0x4c3: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4c8:
	/* 0x4c8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4cd:
	/* 0x4cd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d0:
	/* 0x4d0: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_4d2:
	/* 0x4d2: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_4d5:
	/* 0x4d5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4da:
	/* 0x4da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc:
	/* 0x4dc: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_4e1:
	/* 0x4e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e3:
	/* 0x4e3: js     b98 <tail_handle_snat_fwd_ipv6+0xb98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2968ULL;
	}
x86_l_4e9:
	/* 0x4e9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4ec:
	/* 0x4ec: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_4f0:
	/* 0x4f0: jle    b5b <tail_handle_snat_fwd_ipv6+0xb5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2907ULL;
	}
x86_l_4f6:
	/* 0x4f6: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_4fa:
	/* 0x4fa: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4ff:
	/* 0x4ff: je     b6b <tail_handle_snat_fwd_ipv6+0xb6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2923ULL;
	}
x86_l_505:
	/* 0x505: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_509:
	/* 0x509: jne    b60 <tail_handle_snat_fwd_ipv6+0xb60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2912ULL;
	}
x86_l_50f:
	/* 0x50f: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_514:
	/* 0x514: jmp    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	return 2973ULL;
x86_l_519:
	/* 0x519: mov    r15d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_32);
x86_l_51c:
	/* 0x51c: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_520:
	/* 0x520: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_527:
	/* 0x527: je     b98 <tail_handle_snat_fwd_ipv6+0xb98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2968ULL;
	}
x86_l_52d:
	/* 0x52d: jmp    539 <tail_handle_snat_fwd_ipv6+0x539> */
	goto x86_l_539;
x86_l_52f:
	/* 0x52f: mov    r15d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_32);
x86_l_532:
	/* 0x532: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_539:
	/* 0x539: mov    BYTE PTR [r13+0x24],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_53d:
	/* 0x53d: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_542:
	/* 0x542: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_546:
	/* 0x546: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_54b:
	/* 0x54b: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54f:
	/* 0x54f: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_554:
	/* 0x554: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_558:
	/* 0x558: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55d:
	/* 0x55d: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_561:
	/* 0x561: mov    BYTE PTR [r13+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_566:
	/* 0x566: movzx  eax,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_569:
	/* 0x569: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_56b:
	/* 0x56b: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_56f:
	/* 0x56f: cmp    r15b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 17ULL);
x86_l_573:
	/* 0x573: je     57e <tail_handle_snat_fwd_ipv6+0x57e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_57e;
	}
x86_l_575:
	/* 0x575: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_579:
	/* 0x579: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_57c:
	/* 0x57c: jne    5ef <tail_handle_snat_fwd_ipv6+0x5ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5ef;
	}
x86_l_57e:
	/* 0x57e: lea    rax,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_583:
	/* 0x583: mov    ebp,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3840ULL);
x86_l_588:
	/* 0x588: and    ebp,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_58b:
	/* 0x58b: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_593:
	/* 0x593: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5a5:
	/* 0x5a5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a8:
	/* 0x5a8: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b1:
	/* 0x5b1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b6:
	/* 0x5b6: mov    BYTE PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_5bb:
	/* 0x5bb: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_5c2:
	/* 0x5c2: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_5c5:
	/* 0x5c5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ca:
	/* 0x5ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cf:
	/* 0x5cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d1:
	/* 0x5d1: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_5d4:
	/* 0x5d4: cmp    ebp,0xc00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3072ULL);
x86_l_5da:
	/* 0x5da: je     684 <tail_handle_snat_fwd_ipv6+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_684;
	}
x86_l_5e0:
	/* 0x5e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e3:
	/* 0x5e3: je     5ef <tail_handle_snat_fwd_ipv6+0x5ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5ef;
	}
x86_l_5e5:
	/* 0x5e5: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_5e9:
	/* 0x5e9: jne    684 <tail_handle_snat_fwd_ipv6+0x684> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_684;
	}
x86_l_5ef:
	/* 0x5ef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f2:
	/* 0x5f2: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f7:
	/* 0x5f7: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_5fb:
	/* 0x5fb: call   0 <tail_handle_snat_fwd_ipv6> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1536ULL);
	return 3603ULL;
x86_l_600:
	/* 0x600: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_603:
	/* 0x603: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_605:
	/* 0x605: js     e06 <tail_handle_snat_fwd_ipv6+0xe06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3590ULL;
	}
x86_l_60b:
	/* 0x60b: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_611:
	/* 0x611: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_614:
	/* 0x614: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_619:
	/* 0x619: je     6d3 <tail_handle_snat_fwd_ipv6+0x6d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1747ULL;
	}
x86_l_61f:
	/* 0x61f: cmp    BYTE PTR [r13+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_624:
	/* 0x624: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_629:
	/* 0x629: je     6a0 <tail_handle_snat_fwd_ipv6+0x6a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a0;
	}
x86_l_62b:
	/* 0x62b: mov    eax,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3840ULL);
x86_l_630:
	/* 0x630: and    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_633:
	/* 0x633: cmp    eax,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1280ULL);
x86_l_638:
	/* 0x638: je     6a0 <tail_handle_snat_fwd_ipv6+0x6a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a0;
	}
x86_l_63a:
	/* 0x63a: mov    edi,DWORD PTR [r13+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_63e:
	/* 0x63e: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_640:
	/* 0x640: je     93d <tail_handle_snat_fwd_ipv6+0x93d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2365ULL;
	}
x86_l_646:
	/* 0x646: mov    rax,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_64d:
	/* 0x64d: cmp    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_64f:
	/* 0x64f: je     6a0 <tail_handle_snat_fwd_ipv6+0x6a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a0;
	}
x86_l_651:
	/* 0x651: mov    ebp,DWORD PTR [r13+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_655:
	/* 0x655: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_65d:
	/* 0x65d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_65f:
	/* 0x65f: jne    949 <tail_handle_snat_fwd_ipv6+0x949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2377ULL;
	}
x86_l_665:
	/* 0x665: mov    r14,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_66c:
	/* 0x66c: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_670:
	/* 0x670: je     c68 <tail_handle_snat_fwd_ipv6+0xc68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3176ULL;
	}
x86_l_676:
	/* 0x676: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_67b:
	/* 0x67b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67d:
	/* 0x67d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67f:
	/* 0x67f: jmp    d6d <tail_handle_snat_fwd_ipv6+0xd6d> */
	return 3437ULL;
x86_l_684:
	/* 0x684: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_689:
	/* 0x689: mov    QWORD PTR [r13+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_68d:
	/* 0x68d: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_692:
	/* 0x692: mov    QWORD PTR [r13+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_696:
	/* 0x696: mov    BYTE PTR [r13+0x3d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005057ULL);
x86_l_69b:
	/* 0x69b: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6a0:
	/* 0x6a0: mov    r12,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6a4:
	/* 0x6a4: mov    r14,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a8:
	/* 0x6a8: lea    rcx,[rsp+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_6ad:
	/* 0x6ad: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6b0:
	/* 0x6b0: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6b4:
	/* 0x6b4: call   0 <tail_handle_snat_fwd_ipv6> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1721ULL);
	return 5282ULL;
x86_l_6b9:
	/* 0x6b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6bb:
	/* 0x6bb: js     6d3 <tail_handle_snat_fwd_ipv6+0x6d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1747ULL;
	}
x86_l_6bd:
	/* 0x6bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6c0:
	/* 0x6c0: je     6d3 <tail_handle_snat_fwd_ipv6+0x6d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1747ULL;
	}
	return 1730ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1730ULL: goto x86_l_6c2;
	case 1735ULL: goto x86_l_6c7;
	case 1738ULL: goto x86_l_6ca;
	case 1744ULL: goto x86_l_6d0;
	case 1747ULL: goto x86_l_6d3;
	case 1749ULL: goto x86_l_6d5;
	case 1754ULL: goto x86_l_6da;
	case 1757ULL: goto x86_l_6dd;
	case 1759ULL: goto x86_l_6df;
	case 1765ULL: goto x86_l_6e5;
	case 1768ULL: goto x86_l_6e8;
	case 1774ULL: goto x86_l_6ee;
	case 1776ULL: goto x86_l_6f0;
	case 1782ULL: goto x86_l_6f6;
	case 1789ULL: goto x86_l_6fd;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1800ULL: goto x86_l_708;
	case 1807ULL: goto x86_l_70f;
	case 1810ULL: goto x86_l_712;
	case 1814ULL: goto x86_l_716;
	case 1818ULL: goto x86_l_71a;
	case 1820ULL: goto x86_l_71c;
	case 1828ULL: goto x86_l_724;
	case 1835ULL: goto x86_l_72b;
	case 1840ULL: goto x86_l_730;
	case 1845ULL: goto x86_l_735;
	case 1847ULL: goto x86_l_737;
	case 1850ULL: goto x86_l_73a;
	case 1852ULL: goto x86_l_73c;
	case 1855ULL: goto x86_l_73f;
	case 1857ULL: goto x86_l_741;
	case 1860ULL: goto x86_l_744;
	case 1862ULL: goto x86_l_746;
	case 1874ULL: goto x86_l_752;
	case 1883ULL: goto x86_l_75b;
	case 1892ULL: goto x86_l_764;
	case 1901ULL: goto x86_l_76d;
	case 1910ULL: goto x86_l_776;
	case 1919ULL: goto x86_l_77f;
	case 1928ULL: goto x86_l_788;
	case 1937ULL: goto x86_l_791;
	case 1947ULL: goto x86_l_79b;
	case 1953ULL: goto x86_l_7a1;
	case 1958ULL: goto x86_l_7a6;
	case 1965ULL: goto x86_l_7ad;
	case 1970ULL: goto x86_l_7b2;
	case 1975ULL: goto x86_l_7b7;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1982ULL: goto x86_l_7be;
	case 1985ULL: goto x86_l_7c1;
	case 1989ULL: goto x86_l_7c5;
	case 1991ULL: goto x86_l_7c7;
	case 2000ULL: goto x86_l_7d0;
	case 2005ULL: goto x86_l_7d5;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2022ULL: goto x86_l_7e6;
	case 2027ULL: goto x86_l_7eb;
	case 2029ULL: goto x86_l_7ed;
	case 2031ULL: goto x86_l_7ef;
	case 2034ULL: goto x86_l_7f2;
	case 2037ULL: goto x86_l_7f5;
	case 2043ULL: goto x86_l_7fb;
	case 2046ULL: goto x86_l_7fe;
	case 2053ULL: goto x86_l_805;
	case 2056ULL: goto x86_l_808;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2087ULL: goto x86_l_827;
	case 2089ULL: goto x86_l_829;
	case 2097ULL: goto x86_l_831;
	case 2099ULL: goto x86_l_833;
	case 2107ULL: goto x86_l_83b;
	case 2112ULL: goto x86_l_840;
	case 2114ULL: goto x86_l_842;
	case 2116ULL: goto x86_l_844;
	case 2119ULL: goto x86_l_847;
	case 2127ULL: goto x86_l_84f;
	case 2134ULL: goto x86_l_856;
	case 2139ULL: goto x86_l_85b;
	case 2145ULL: goto x86_l_861;
	case 2148ULL: goto x86_l_864;
	case 2151ULL: goto x86_l_867;
	case 2154ULL: goto x86_l_86a;
	case 2156ULL: goto x86_l_86c;
	case 2165ULL: goto x86_l_875;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2182ULL: goto x86_l_886;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2192ULL: goto x86_l_890;
	case 2194ULL: goto x86_l_892;
	case 2196ULL: goto x86_l_894;
	case 2202ULL: goto x86_l_89a;
	case 2210ULL: goto x86_l_8a2;
	case 2217ULL: goto x86_l_8a9;
	case 2225ULL: goto x86_l_8b1;
	case 2228ULL: goto x86_l_8b4;
	case 2231ULL: goto x86_l_8b7;
	case 2237ULL: goto x86_l_8bd;
	case 2240ULL: goto x86_l_8c0;
	case 2243ULL: goto x86_l_8c3;
	case 2246ULL: goto x86_l_8c6;
	case 2253ULL: goto x86_l_8cd;
	case 2261ULL: goto x86_l_8d5;
	case 2267ULL: goto x86_l_8db;
	case 2270ULL: goto x86_l_8de;
	case 2274ULL: goto x86_l_8e2;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2300ULL: goto x86_l_8fc;
	case 2309ULL: goto x86_l_905;
	case 2313ULL: goto x86_l_909;
	case 2317ULL: goto x86_l_90d;
	case 2320ULL: goto x86_l_910;
	case 2323ULL: goto x86_l_913;
	case 2326ULL: goto x86_l_916;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2342ULL: goto x86_l_926;
	case 2347ULL: goto x86_l_92b;
	case 2353ULL: goto x86_l_931;
	case 2357ULL: goto x86_l_935;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2377ULL: goto x86_l_949;
	case 2381ULL: goto x86_l_94d;
	case 2388ULL: goto x86_l_954;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2400ULL: goto x86_l_960;
	case 2403ULL: goto x86_l_963;
	case 2410ULL: goto x86_l_96a;
	case 2416ULL: goto x86_l_970;
	case 2419ULL: goto x86_l_973;
	case 2421ULL: goto x86_l_975;
	case 2427ULL: goto x86_l_97b;
	case 2432ULL: goto x86_l_980;
	case 2437ULL: goto x86_l_985;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2454ULL: goto x86_l_996;
	case 2458ULL: goto x86_l_99a;
	case 2463ULL: goto x86_l_99f;
	case 2467ULL: goto x86_l_9a3;
	case 2472ULL: goto x86_l_9a8;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2488ULL: goto x86_l_9b8;
	case 2491ULL: goto x86_l_9bb;
	case 2494ULL: goto x86_l_9be;
	case 2497ULL: goto x86_l_9c1;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2515ULL: goto x86_l_9d3;
	case 2518ULL: goto x86_l_9d6;
	case 2523ULL: goto x86_l_9db;
	case 2530ULL: goto x86_l_9e2;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2550ULL: goto x86_l_9f6;
	case 2552ULL: goto x86_l_9f8;
	case 2554ULL: goto x86_l_9fa;
	case 2559ULL: goto x86_l_9ff;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2574ULL: goto x86_l_a0e;
	case 2579ULL: goto x86_l_a13;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2596ULL: goto x86_l_a24;
	case 2602ULL: goto x86_l_a2a;
	case 2605ULL: goto x86_l_a2d;
	case 2609ULL: goto x86_l_a31;
	case 2616ULL: goto x86_l_a38;
	case 2619ULL: goto x86_l_a3b;
	case 2622ULL: goto x86_l_a3e;
	case 2624ULL: goto x86_l_a40;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2634ULL: goto x86_l_a4a;
	case 2640ULL: goto x86_l_a50;
	case 2642ULL: goto x86_l_a52;
	case 2649ULL: goto x86_l_a59;
	case 2652ULL: goto x86_l_a5c;
	case 2654ULL: goto x86_l_a5e;
	case 2658ULL: goto x86_l_a62;
	case 2663ULL: goto x86_l_a67;
	case 2665ULL: goto x86_l_a69;
	case 2668ULL: goto x86_l_a6c;
	case 2671ULL: goto x86_l_a6f;
	case 2674ULL: goto x86_l_a72;
	case 2677ULL: goto x86_l_a75;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2693ULL: goto x86_l_a85;
	case 2695ULL: goto x86_l_a87;
	case 2702ULL: goto x86_l_a8e;
	case 2706ULL: goto x86_l_a92;
	case 2709ULL: goto x86_l_a95;
	case 2713ULL: goto x86_l_a99;
	case 2715ULL: goto x86_l_a9b;
	case 2718ULL: goto x86_l_a9e;
	case 2722ULL: goto x86_l_aa2;
	case 2726ULL: goto x86_l_aa6;
	case 2730ULL: goto x86_l_aaa;
	case 2733ULL: goto x86_l_aad;
	case 2735ULL: goto x86_l_aaf;
	case 2742ULL: goto x86_l_ab6;
	case 2744ULL: goto x86_l_ab8;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2751ULL: goto x86_l_abf;
	case 2753ULL: goto x86_l_ac1;
	case 2755ULL: goto x86_l_ac3;
	case 2762ULL: goto x86_l_aca;
	case 2765ULL: goto x86_l_acd;
	case 2768ULL: goto x86_l_ad0;
	case 2771ULL: goto x86_l_ad3;
	case 2778ULL: goto x86_l_ada;
	case 2783ULL: goto x86_l_adf;
	case 2787ULL: goto x86_l_ae3;
	case 2792ULL: goto x86_l_ae8;
	case 2797ULL: goto x86_l_aed;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2817ULL: goto x86_l_b01;
	case 2824ULL: goto x86_l_b08;
	case 2829ULL: goto x86_l_b0d;
	case 2833ULL: goto x86_l_b11;
	case 2837ULL: goto x86_l_b15;
	case 2841ULL: goto x86_l_b19;
	case 2845ULL: goto x86_l_b1d;
	case 2850ULL: goto x86_l_b22;
	case 2855ULL: goto x86_l_b27;
	case 2860ULL: goto x86_l_b2c;
	case 2864ULL: goto x86_l_b30;
	case 2869ULL: goto x86_l_b35;
	case 2872ULL: goto x86_l_b38;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2889ULL: goto x86_l_b49;
	case 2892ULL: goto x86_l_b4c;
	case 2898ULL: goto x86_l_b52;
	case 2900ULL: goto x86_l_b54;
	case 2902ULL: goto x86_l_b56;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2917ULL: goto x86_l_b65;
	case 2921ULL: goto x86_l_b69;
	case 2923ULL: goto x86_l_b6b;
	case 2932ULL: goto x86_l_b74;
	case 2937ULL: goto x86_l_b79;
	case 2942ULL: goto x86_l_b7e;
	case 2945ULL: goto x86_l_b81;
	case 2950ULL: goto x86_l_b86;
	case 2952ULL: goto x86_l_b88;
	case 2954ULL: goto x86_l_b8a;
	case 2956ULL: goto x86_l_b8c;
	case 2961ULL: goto x86_l_b91;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2977ULL: goto x86_l_ba1;
	case 2980ULL: goto x86_l_ba4;
	case 2983ULL: goto x86_l_ba7;
	case 2988ULL: goto x86_l_bac;
	case 2991ULL: goto x86_l_baf;
	case 2995ULL: goto x86_l_bb3;
	case 3002ULL: goto x86_l_bba;
	case 3004ULL: goto x86_l_bbc;
	case 3007ULL: goto x86_l_bbf;
	case 3017ULL: goto x86_l_bc9;
	case 3021ULL: goto x86_l_bcd;
	case 3024ULL: goto x86_l_bd0;
	case 3034ULL: goto x86_l_bda;
	case 3039ULL: goto x86_l_bdf;
	case 3043ULL: goto x86_l_be3;
	case 3050ULL: goto x86_l_bea;
	case 3055ULL: goto x86_l_bef;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3074ULL: goto x86_l_c02;
	case 3076ULL: goto x86_l_c04;
	case 3085ULL: goto x86_l_c0d;
	case 3090ULL: goto x86_l_c12;
	case 3097ULL: goto x86_l_c19;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3116ULL: goto x86_l_c2c;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3145ULL: goto x86_l_c49;
	case 3152ULL: goto x86_l_c50;
	case 3154ULL: goto x86_l_c52;
	case 3155ULL: goto x86_l_c53;
	case 3160ULL: goto x86_l_c58;
	case 3168ULL: goto x86_l_c60;
	case 3171ULL: goto x86_l_c63;
	case 3176ULL: goto x86_l_c68;
	case 3180ULL: goto x86_l_c6c;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3228ULL: goto x86_l_c9c;
	case 3233ULL: goto x86_l_ca1;
	case 3237ULL: goto x86_l_ca5;
	case 3242ULL: goto x86_l_caa;
	case 3246ULL: goto x86_l_cae;
	case 3251ULL: goto x86_l_cb3;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3267ULL: goto x86_l_cc3;
	case 3270ULL: goto x86_l_cc6;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3281ULL: goto x86_l_cd1;
	case 3284ULL: goto x86_l_cd4;
	case 3289ULL: goto x86_l_cd9;
	case 3291ULL: goto x86_l_cdb;
	case 3293ULL: goto x86_l_cdd;
	case 3295ULL: goto x86_l_cdf;
	case 3298ULL: goto x86_l_ce2;
	case 3301ULL: goto x86_l_ce5;
	case 3307ULL: goto x86_l_ceb;
	case 3311ULL: goto x86_l_cef;
	case 3313ULL: goto x86_l_cf1;
	case 3315ULL: goto x86_l_cf3;
	case 3320ULL: goto x86_l_cf8;
	case 3323ULL: goto x86_l_cfb;
	case 3325ULL: goto x86_l_cfd;
	case 3330ULL: goto x86_l_d02;
	case 3335ULL: goto x86_l_d07;
	case 3340ULL: goto x86_l_d0c;
	case 3345ULL: goto x86_l_d11;
	case 3349ULL: goto x86_l_d15;
	case 3353ULL: goto x86_l_d19;
	case 3360ULL: goto x86_l_d20;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3377ULL: goto x86_l_d31;
	case 3381ULL: goto x86_l_d35;
	case 3383ULL: goto x86_l_d37;
	case 3387ULL: goto x86_l_d3b;
	case 3389ULL: goto x86_l_d3d;
	case 3394ULL: goto x86_l_d42;
	case 3398ULL: goto x86_l_d46;
	case 3403ULL: goto x86_l_d4b;
	case 3408ULL: goto x86_l_d50;
	case 3413ULL: goto x86_l_d55;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3428ULL: goto x86_l_d64;
	case 3432ULL: goto x86_l_d68;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6c2:
	/* 0x6c2: mov    ecx,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294963455ULL);
x86_l_6c7:
	/* 0x6c7: and    ecx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_6ca:
	/* 0x6ca: or     ecx,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_6d0:
	/* 0x6d0: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d3:
	/* 0x6d3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d5:
	/* 0x6d5: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_6da:
	/* 0x6da: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_6dd:
	/* 0x6dd: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6df:
	/* 0x6df: js     b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b9d;
	}
x86_l_6e5:
	/* 0x6e5: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_6e8:
	/* 0x6e8: je     b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b9d;
	}
x86_l_6ee:
	/* 0x6ee: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_6f0:
	/* 0x6f0: jne    c47 <tail_handle_snat_fwd_ipv6+0xc47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c47;
	}
x86_l_6f6:
	/* 0x6f6: mov    rax,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_6fd:
	/* 0x6fd: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ff:
	/* 0x6ff: movzx  edx,BYTE PTR [r13+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_704:
	/* 0x704: mov    r13d,DWORD PTR [r13+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_708:
	/* 0x708: mov    rax,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_70f:
	/* 0x70f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_712:
	/* 0x712: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_716:
	/* 0x716: mov    BYTE PTR [rsp+0x10],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71a:
	/* 0x71a: je     741 <tail_handle_snat_fwd_ipv6+0x741> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_741;
	}
x86_l_71c:
	/* 0x71c: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_724:
	/* 0x724: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_72b:
	/* 0x72b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_730:
	/* 0x730: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_735:
	/* 0x735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_737:
	/* 0x737: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_73a:
	/* 0x73a: je     741 <tail_handle_snat_fwd_ipv6+0x741> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_741;
	}
x86_l_73c:
	/* 0x73c: mov    r15,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73f:
	/* 0x73f: jmp    744 <tail_handle_snat_fwd_ipv6+0x744> */
	goto x86_l_744;
x86_l_741:
	/* 0x741: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_744:
	/* 0x744: mov    ebp,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_746:
	/* 0x746: mov    QWORD PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_752:
	/* 0x752: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_75b:
	/* 0x75b: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_764:
	/* 0x764: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_76d:
	/* 0x76d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_776:
	/* 0x776: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_77f:
	/* 0x77f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_788:
	/* 0x788: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_791:
	/* 0x791: movabs rax,0x71008f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485340676608ULL);
x86_l_79b:
	/* 0x79b: add    rax,0xa0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 655360ULL);
x86_l_7a1:
	/* 0x7a1: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7a6:
	/* 0x7a6: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_7ad:
	/* 0x7ad: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7b2:
	/* 0x7b2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b7:
	/* 0x7b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b9:
	/* 0x7b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7bc:
	/* 0x7bc: je     7c7 <tail_handle_snat_fwd_ipv6+0x7c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7c7;
	}
x86_l_7be:
	/* 0x7be: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7c1:
	/* 0x7c1: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7c5:
	/* 0x7c5: jmp    7ef <tail_handle_snat_fwd_ipv6+0x7ef> */
	goto x86_l_7ef;
x86_l_7c7:
	/* 0x7c7: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_7d0:
	/* 0x7d0: mov    QWORD PTR [rsp+0x68],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7d5:
	/* 0x7d5: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_7dc:
	/* 0x7dc: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7e1:
	/* 0x7e1: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7e6:
	/* 0x7e6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7eb:
	/* 0x7eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ed:
	/* 0x7ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ef:
	/* 0x7ef: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_7f2:
	/* 0x7f2: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_7f5:
	/* 0x7f5: je     b54 <tail_handle_snat_fwd_ipv6+0xb54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b54;
	}
x86_l_7fb:
	/* 0x7fb: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_7fe:
	/* 0x7fe: mov    rax,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_805:
	/* 0x805: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_808:
	/* 0x808: je     a31 <tail_handle_snat_fwd_ipv6+0xa31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a31;
	}
x86_l_80e:
	/* 0x80e: mov    QWORD PTR [rsp+0x50],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_813:
	/* 0x813: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_81b:
	/* 0x81b: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_820:
	/* 0x820: mov    rcx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_827:
	/* 0x827: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_829:
	/* 0x829: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_831:
	/* 0x831: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_833:
	/* 0x833: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_83b:
	/* 0x83b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_840:
	/* 0x840: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_842:
	/* 0x842: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_844:
	/* 0x844: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_847:
	/* 0x847: mov    DWORD PTR [rsp+0x74],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206338ULL);
x86_l_84f:
	/* 0x84f: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_856:
	/* 0x856: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_85b:
	/* 0x85b: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_861:
	/* 0x861: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_864:
	/* 0x864: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_867:
	/* 0x867: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_86a:
	/* 0x86a: jne    89a <tail_handle_snat_fwd_ipv6+0x89a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_89a;
	}
x86_l_86c:
	/* 0x86c: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_875:
	/* 0x875: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_87c:
	/* 0x87c: lea    rsi,[rsp+0x74] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_881:
	/* 0x881: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_886:
	/* 0x886: lea    r15,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_88b:
	/* 0x88b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_88e:
	/* 0x88e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_890:
	/* 0x890: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_892:
	/* 0x892: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_894:
	/* 0x894: js     b54 <tail_handle_snat_fwd_ipv6+0xb54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b54;
	}
x86_l_89a:
	/* 0x89a: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8a2:
	/* 0x8a2: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_8a9:
	/* 0x8a9: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8b1:
	/* 0x8b1: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_8b4:
	/* 0x8b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b7:
	/* 0x8b7: je     9c6 <tail_handle_snat_fwd_ipv6+0x9c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9c6;
	}
x86_l_8bd:
	/* 0x8bd: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c0:
	/* 0x8c0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_8c6:
	/* 0x8c6: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_8cd:
	/* 0x8cd: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8d5:
	/* 0x8d5: jbe    a13 <tail_handle_snat_fwd_ipv6+0xa13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a13;
	}
x86_l_8db:
	/* 0x8db: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_8de:
	/* 0x8de: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_8e2:
	/* 0x8e2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_8ec:
	/* 0x8ec: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_8f1:
	/* 0x8f1: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_8f5:
	/* 0x8f5: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_8fc:
	/* 0x8fc: imul   rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 128ULL);
x86_l_905:
	/* 0x905: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_909:
	/* 0x909: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_90d:
	/* 0x90d: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_910:
	/* 0x910: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_913:
	/* 0x913: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_916:
	/* 0x916: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_91e:
	/* 0x91e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_921:
	/* 0x921: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_926:
	/* 0x926: mov    r10,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_92b:
	/* 0x92b: jbe    a21 <tail_handle_snat_fwd_ipv6+0xa21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a21;
	}
x86_l_931:
	/* 0x931: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_935:
	/* 0x935: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_938:
	/* 0x938: jmp    a21 <tail_handle_snat_fwd_ipv6+0xa21> */
	goto x86_l_a21;
x86_l_93d:
	/* 0x93d: mov    ebp,DWORD PTR [r13+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_941:
	/* 0x941: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_949:
	/* 0x949: mov    DWORD PTR [rsp+0x8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_94d:
	/* 0x94d: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fib_params_storage)));
x86_l_954:
	/* 0x954: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_959:
	/* 0x959: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_95e:
	/* 0x95e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_960:
	/* 0x960: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_963:
	/* 0x963: mov    r14,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_96a:
	/* 0x96a: je     d07 <tail_handle_snat_fwd_ipv6+0xd07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d07;
	}
x86_l_970:
	/* 0x970: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_973:
	/* 0x973: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_975:
	/* 0x975: je     c8b <tail_handle_snat_fwd_ipv6+0xc8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c8b;
	}
x86_l_97b:
	/* 0x97b: mov    DWORD PTR [r12+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_980:
	/* 0x980: mov    BYTE PTR [r12],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_985:
	/* 0x985: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_988:
	/* 0x988: mov    DWORD PTR [r12+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_98d:
	/* 0x98d: mov    rax,QWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_991:
	/* 0x991: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_996:
	/* 0x996: mov    rax,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99a:
	/* 0x99a: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_99f:
	/* 0x99f: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9a3:
	/* 0x9a3: mov    QWORD PTR [r12+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9a8:
	/* 0x9a8: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ac:
	/* 0x9ac: mov    QWORD PTR [r12+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9b1:
	/* 0x9b1: mov    rax,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_9b8:
	/* 0x9b8: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9bb:
	/* 0x9bb: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_9be:
	/* 0x9be: or     ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 9ULL);
x86_l_9c1:
	/* 0x9c1: jmp    cc9 <tail_handle_snat_fwd_ipv6+0xcc9> */
	goto x86_l_cc9;
x86_l_9c6:
	/* 0x9c6: mov    QWORD PTR [rsp+0x60],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9cb:
	/* 0x9cb: mov    r15,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9d3:
	/* 0x9d3: dec    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_9d6:
	/* 0x9d6: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9db:
	/* 0x9db: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_9e2:
	/* 0x9e2: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9ea:
	/* 0x9ea: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9f4:
	/* 0x9f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f6:
	/* 0x9f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f8:
	/* 0x9f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9fa:
	/* 0x9fa: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ff:
	/* 0x9ff: mov    r15,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a07:
	/* 0xa07: mov    r10,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a0c:
	/* 0xa0c: jns    a31 <tail_handle_snat_fwd_ipv6+0xa31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_a31;
	}
x86_l_a0e:
	/* 0xa0e: jmp    c58 <tail_handle_snat_fwd_ipv6+0xc58> */
	goto x86_l_c58;
x86_l_a13:
	/* 0xa13: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a17:
	/* 0xa17: mov    r12,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a1c:
	/* 0xa1c: mov    r10,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a21:
	/* 0xa21: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_a24:
	/* 0xa24: je     c58 <tail_handle_snat_fwd_ipv6+0xc58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c58;
	}
x86_l_a2a:
	/* 0xa2a: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_a2d:
	/* 0xa2d: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a31:
	/* 0xa31: mov    rax,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_a38:
	/* 0xa38: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3b:
	/* 0xa3b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_a3e:
	/* 0xa3e: add    al,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_a40:
	/* 0xa40: or     al,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_a42:
	/* 0xa42: mov    ecx,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3840ULL);
x86_l_a47:
	/* 0xa47: and    ecx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_a4a:
	/* 0xa4a: cmp    ecx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1024ULL);
x86_l_a50:
	/* 0xa50: jne    a79 <tail_handle_snat_fwd_ipv6+0xa79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a79;
	}
x86_l_a52:
	/* 0xa52: mov    rdx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_a59:
	/* 0xa59: movzx  esi,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a5c:
	/* 0xa5c: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_a5e:
	/* 0xa5e: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_a62:
	/* 0xa62: mov    r9d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a67:
	/* 0xa67: je     a75 <tail_handle_snat_fwd_ipv6+0xa75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a75;
	}
x86_l_a69:
	/* 0xa69: movzx  ecx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a6c:
	/* 0xa6c: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_a6f:
	/* 0xa6f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_a72:
	/* 0xa72: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_a75:
	/* 0xa75: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_a77:
	/* 0xa77: jmp    a7e <tail_handle_snat_fwd_ipv6+0xa7e> */
	goto x86_l_a7e;
x86_l_a79:
	/* 0xa79: mov    r9d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a7e:
	/* 0xa7e: mov    rdx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_a85:
	/* 0xa85: mov    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a87:
	/* 0xa87: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_a8e:
	/* 0xa8e: movzx  r8d,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a92:
	/* 0xa92: mov    sil,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 4ULL);
x86_l_a95:
	/* 0xa95: cmp    r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_a99:
	/* 0xa99: je     aaa <tail_handle_snat_fwd_ipv6+0xaaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aaa;
	}
x86_l_a9b:
	/* 0xa9b: movzx  esi,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a9e:
	/* 0xa9e: cmp    sil,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 2ULL);
x86_l_aa2:
	/* 0xaa2: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_aa6:
	/* 0xaa6: shl    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_aaa:
	/* 0xaaa: test   sil,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RAX, X86_WIDTH_8);
x86_l_aad:
	/* 0xaad: je     ab8 <tail_handle_snat_fwd_ipv6+0xab8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab8;
	}
x86_l_aaf:
	/* 0xaaf: mov    rcx,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len_overlay)));
x86_l_ab6:
	/* 0xab6: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab8:
	/* 0xab8: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aba:
	/* 0xaba: cmp    edx,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_abc:
	/* 0xabc: cmovne ecx,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBP, X86_WIDTH_32, X86_CC_NE);
x86_l_abf:
	/* 0xabf: mov    edx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac1:
	/* 0xac1: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_ac3:
	/* 0xac3: mov    rsi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_host_ep_id)));
x86_l_aca:
	/* 0xaca: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_acd:
	/* 0xacd: cmovae ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_AE);
x86_l_ad0:
	/* 0xad0: mov    edx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_ad3:
	/* 0xad3: mov    WORD PTR [rsp+0x18],0xb04 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 103079217924ULL);
x86_l_ada:
	/* 0xada: mov    WORD PTR [rsp+0x1a],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_adf:
	/* 0xadf: mov    DWORD PTR [rsp+0x1c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_ae3:
	/* 0xae3: mov    DWORD PTR [rsp+0x20],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ae8:
	/* 0xae8: mov    WORD PTR [rsp+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_aed:
	/* 0xaed: mov    WORD PTR [rsp+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_af4:
	/* 0xaf4: mov    DWORD PTR [rsp+0x28],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_af9:
	/* 0xaf9: mov    DWORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_b01:
	/* 0xb01: mov    WORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b08:
	/* 0xb08: movzx  edx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_b0d:
	/* 0xb0d: mov    BYTE PTR [rsp+0x32],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_b11:
	/* 0xb11: mov    BYTE PTR [rsp+0x33],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51ULL);
x86_l_b15:
	/* 0xb15: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b19:
	/* 0xb19: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b1d:
	/* 0xb1d: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b22:
	/* 0xb22: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b27:
	/* 0xb27: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b2c:
	/* 0xb2c: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_b30:
	/* 0xb30: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_b35:
	/* 0xb35: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_b38:
	/* 0xb38: mov    rsi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_b3f:
	/* 0xb3f: lea    rcx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b44:
	/* 0xb44: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_b49:
	/* 0xb49: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b4c:
	/* 0xb4c: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_b52:
	/* 0xb52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b54:
	/* 0xb54: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b56:
	/* 0xb56: jmp    c47 <tail_handle_snat_fwd_ipv6+0xc47> */
	goto x86_l_c47;
x86_l_b5b:
	/* 0xb5b: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b60:
	/* 0xb60: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_b65:
	/* 0xb65: cmp    r12b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 44ULL);
x86_l_b69:
	/* 0xb69: jne    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b9d;
	}
x86_l_b6b:
	/* 0xb6b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_b74:
	/* 0xb74: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b79:
	/* 0xb79: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b7e:
	/* 0xb7e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b81:
	/* 0xb81: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b86:
	/* 0xb86: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b88:
	/* 0xb88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b8a:
	/* 0xb8a: js     b93 <tail_handle_snat_fwd_ipv6+0xb93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b93;
	}
x86_l_b8c:
	/* 0xb8c: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_b91:
	/* 0xb91: jmp    b98 <tail_handle_snat_fwd_ipv6+0xb98> */
	goto x86_l_b98;
x86_l_b93:
	/* 0xb93: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_b98:
	/* 0xb98: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b9d:
	/* 0xb9d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_b9f:
	/* 0xb9f: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ba1:
	/* 0xba1: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_ba4:
	/* 0xba4: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ba7:
	/* 0xba7: movzx  ecx,BYTE PTR [rsp+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_bac:
	/* 0xbac: shl    ecx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_baf:
	/* 0xbaf: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb3:
	/* 0xbb3: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_bba:
	/* 0xbba: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_bbc:
	/* 0xbbc: mov    DWORD PTR [rbx+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bbf:
	/* 0xbbf: movabs rcx,0x8f710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 40375175073497088ULL);
x86_l_bc9:
	/* 0xbc9: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_bcd:
	/* 0xbcd: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd0:
	/* 0xbd0: movabs rcx,0x71008f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 485340676608ULL);
x86_l_bda:
	/* 0xbda: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bdf:
	/* 0xbdf: mov    BYTE PTR [rsp+0x60],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_be3:
	/* 0xbe3: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_bea:
	/* 0xbea: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bef:
	/* 0xbef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf4:
	/* 0xbf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf6:
	/* 0xbf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf9:
	/* 0xbf9: je     c04 <tail_handle_snat_fwd_ipv6+0xc04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c04;
	}
x86_l_bfb:
	/* 0xbfb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_bfe:
	/* 0xbfe: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c02:
	/* 0xc02: jmp    c2c <tail_handle_snat_fwd_ipv6+0xc2c> */
	goto x86_l_c2c;
x86_l_c04:
	/* 0xc04: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_c0d:
	/* 0xc0d: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c12:
	/* 0xc12: mov    rdi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c19:
	/* 0xc19: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c1e:
	/* 0xc1e: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c23:
	/* 0xc23: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c28:
	/* 0xc28: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c2a:
	/* 0xc2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2c:
	/* 0xc2c: mov    rsi,QWORD PTR [rip+0x10b87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_c33:
	/* 0xc33: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_c38:
	/* 0xc38: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c3b:
	/* 0xc3b: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_c40:
	/* 0xc40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c42:
	/* 0xc42: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_c47:
	/* 0xc47: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_c49:
	/* 0xc49: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_c50:
	/* 0xc50: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_c52:
	/* 0xc52: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_c53:
	/* 0xc53: jmp    36d8 <snat_v6_nat+0x2236> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_c58:
	/* 0xc58: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c60:
	/* 0xc60: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c63:
	/* 0xc63: jmp    b54 <tail_handle_snat_fwd_ipv6+0xb54> */
	goto x86_l_b54;
x86_l_c68:
	/* 0xc68: mov    DWORD PTR [rsp+0x8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c6c:
	/* 0xc6c: mov    rdi,QWORD PTR [rip+0x10b8a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fib_params_storage)));
x86_l_c73:
	/* 0xc73: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c78:
	/* 0xc78: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c7d:
	/* 0xc7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7f:
	/* 0xc7f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_c82:
	/* 0xc82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c85:
	/* 0xc85: je     d07 <tail_handle_snat_fwd_ipv6+0xd07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d07;
	}
x86_l_c8b:
	/* 0xc8b: mov    BYTE PTR [r12],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_c90:
	/* 0xc90: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c93:
	/* 0xc93: mov    DWORD PTR [r12+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c98:
	/* 0xc98: mov    rax,QWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c9c:
	/* 0xc9c: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca1:
	/* 0xca1: mov    rax,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca5:
	/* 0xca5: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_caa:
	/* 0xcaa: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cae:
	/* 0xcae: mov    QWORD PTR [r12+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cb3:
	/* 0xcb3: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb7:
	/* 0xcb7: mov    QWORD PTR [r12+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cbc:
	/* 0xcbc: mov    rax,QWORD PTR [rip+0x10b86] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_cc3:
	/* 0xcc3: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_cc6:
	/* 0xcc6: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_cc9:
	/* 0xcc9: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_cce:
	/* 0xcce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cd1:
	/* 0xcd1: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_cd4:
	/* 0xcd4: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_cd9:
	/* 0xcd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdb:
	/* 0xcdb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_cdd:
	/* 0xcdd: je     ceb <tail_handle_snat_fwd_ipv6+0xceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ceb;
	}
x86_l_cdf:
	/* 0xcdf: movsx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ce2:
	/* 0xce2: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_ce5:
	/* 0xce5: jne    d73 <tail_handle_snat_fwd_ipv6+0xd73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3443ULL;
	}
x86_l_ceb:
	/* 0xceb: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cef:
	/* 0xcef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf1:
	/* 0xcf1: jne    cf8 <tail_handle_snat_fwd_ipv6+0xcf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cf8;
	}
x86_l_cf3:
	/* 0xcf3: mov    eax,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf8:
	/* 0xcf8: cmp    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 40ULL);
x86_l_cfb:
	/* 0xcfb: jne    d11 <tail_handle_snat_fwd_ipv6+0xd11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d11;
	}
x86_l_cfd:
	/* 0xcfd: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d02:
	/* 0xd02: jmp    6a0 <tail_handle_snat_fwd_ipv6+0x6a0> */
	return 1696ULL;
x86_l_d07:
	/* 0xd07: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_d0c:
	/* 0xd0c: jmp    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	goto x86_l_b9d;
x86_l_d11:
	/* 0xd11: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d15:
	/* 0xd15: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d19:
	/* 0xd19: mov    rdi,QWORD PTR [rip+0x10b86] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_d20:
	/* 0xd20: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d25:
	/* 0xd25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d2a:
	/* 0xd2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2c:
	/* 0xd2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d2f:
	/* 0xd2f: je     d37 <tail_handle_snat_fwd_ipv6+0xd37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d37;
	}
x86_l_d31:
	/* 0xd31: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_d35:
	/* 0xd35: jne    d81 <tail_handle_snat_fwd_ipv6+0xd81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3457ULL;
	}
x86_l_d37:
	/* 0xd37: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d3b:
	/* 0xd3b: je     db0 <tail_handle_snat_fwd_ipv6+0xdb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3504ULL;
	}
x86_l_d3d:
	/* 0xd3d: movzx  eax,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d42:
	/* 0xd42: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d46:
	/* 0xd46: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d4b:
	/* 0xd4b: mov    rcx,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d50:
	/* 0xd50: mov    QWORD PTR [rsp+0x1c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d55:
	/* 0xd55: mov    QWORD PTR [rsp+0x24],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d5a:
	/* 0xd5a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d5f:
	/* 0xd5f: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_d64:
	/* 0xd64: mov    edi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d68:
	/* 0xd68: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
	return 3437ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3437ULL: goto x86_l_d6d;
	case 3439ULL: goto x86_l_d6f;
	case 3441ULL: goto x86_l_d71;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3457ULL: goto x86_l_d81;
	case 3462ULL: goto x86_l_d86;
	case 3466ULL: goto x86_l_d8a;
	case 3468ULL: goto x86_l_d8c;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3479ULL: goto x86_l_d97;
	case 3485ULL: goto x86_l_d9d;
	case 3488ULL: goto x86_l_da0;
	case 3491ULL: goto x86_l_da3;
	case 3493ULL: goto x86_l_da5;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3508ULL: goto x86_l_db4;
	case 3513ULL: goto x86_l_db9;
	case 3516ULL: goto x86_l_dbc;
	case 3521ULL: goto x86_l_dc1;
	case 3523ULL: goto x86_l_dc3;
	case 3525ULL: goto x86_l_dc5;
	case 3530ULL: goto x86_l_dca;
	case 3532ULL: goto x86_l_dcc;
	case 3538ULL: goto x86_l_dd2;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3554ULL: goto x86_l_de2;
	case 3557ULL: goto x86_l_de5;
	case 3562ULL: goto x86_l_dea;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3572ULL: goto x86_l_df4;
	case 3574ULL: goto x86_l_df6;
	case 3580ULL: goto x86_l_dfc;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	case 3603ULL: goto x86_l_e13;
	case 3604ULL: goto x86_l_e14;
	case 3606ULL: goto x86_l_e16;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3612ULL: goto x86_l_e1c;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3619ULL: goto x86_l_e23;
	case 3622ULL: goto x86_l_e26;
	case 3625ULL: goto x86_l_e29;
	case 3630ULL: goto x86_l_e2e;
	case 3632ULL: goto x86_l_e30;
	case 3634ULL: goto x86_l_e32;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3648ULL: goto x86_l_e40;
	case 3655ULL: goto x86_l_e47;
	case 3658ULL: goto x86_l_e4a;
	case 3660ULL: goto x86_l_e4c;
	case 3663ULL: goto x86_l_e4f;
	case 3670ULL: goto x86_l_e56;
	case 3677ULL: goto x86_l_e5d;
	case 3680ULL: goto x86_l_e60;
	case 3685ULL: goto x86_l_e65;
	case 3689ULL: goto x86_l_e69;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3709ULL: goto x86_l_e7d;
	case 3711ULL: goto x86_l_e7f;
	case 3715ULL: goto x86_l_e83;
	case 3719ULL: goto x86_l_e87;
	case 3723ULL: goto x86_l_e8b;
	case 3725ULL: goto x86_l_e8d;
	case 3727ULL: goto x86_l_e8f;
	case 3731ULL: goto x86_l_e93;
	case 3738ULL: goto x86_l_e9a;
	case 3741ULL: goto x86_l_e9d;
	case 3745ULL: goto x86_l_ea1;
	case 3749ULL: goto x86_l_ea5;
	case 3753ULL: goto x86_l_ea9;
	case 3757ULL: goto x86_l_ead;
	case 3762ULL: goto x86_l_eb2;
	case 3765ULL: goto x86_l_eb5;
	case 3767ULL: goto x86_l_eb7;
	case 3771ULL: goto x86_l_ebb;
	case 3772ULL: goto x86_l_ebc;
	case 3774ULL: goto x86_l_ebe;
	case 3776ULL: goto x86_l_ec0;
	case 3778ULL: goto x86_l_ec2;
	case 3780ULL: goto x86_l_ec4;
	case 3781ULL: goto x86_l_ec5;
	case 3782ULL: goto x86_l_ec6;
	case 3786ULL: goto x86_l_eca;
	case 3790ULL: goto x86_l_ece;
	case 3798ULL: goto x86_l_ed6;
	case 3801ULL: goto x86_l_ed9;
	case 3806ULL: goto x86_l_ede;
	case 3810ULL: goto x86_l_ee2;
	case 3815ULL: goto x86_l_ee7;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3832ULL: goto x86_l_ef8;
	case 3837ULL: goto x86_l_efd;
	case 3842ULL: goto x86_l_f02;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3852ULL: goto x86_l_f0c;
	case 3858ULL: goto x86_l_f12;
	case 3862ULL: goto x86_l_f16;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3875ULL: goto x86_l_f23;
	case 3878ULL: goto x86_l_f26;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3893ULL: goto x86_l_f35;
	case 3900ULL: goto x86_l_f3c;
	case 3905ULL: goto x86_l_f41;
	case 3911ULL: goto x86_l_f47;
	case 3916ULL: goto x86_l_f4c;
	case 3921ULL: goto x86_l_f51;
	case 3924ULL: goto x86_l_f54;
	case 3928ULL: goto x86_l_f58;
	case 3930ULL: goto x86_l_f5a;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3959ULL: goto x86_l_f77;
	case 3961ULL: goto x86_l_f79;
	case 3964ULL: goto x86_l_f7c;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3977ULL: goto x86_l_f89;
	case 3979ULL: goto x86_l_f8b;
	case 3984ULL: goto x86_l_f90;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 4001ULL: goto x86_l_fa1;
	case 4006ULL: goto x86_l_fa6;
	case 4013ULL: goto x86_l_fad;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4025ULL: goto x86_l_fb9;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4037ULL: goto x86_l_fc5;
	case 4042ULL: goto x86_l_fca;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4059ULL: goto x86_l_fdb;
	case 4064ULL: goto x86_l_fe0;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4083ULL: goto x86_l_ff3;
	case 4087ULL: goto x86_l_ff7;
	case 4094ULL: goto x86_l_ffe;
	case 4097ULL: goto x86_l_1001;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4123ULL: goto x86_l_101b;
	case 4127ULL: goto x86_l_101f;
	case 4130ULL: goto x86_l_1022;
	case 4134ULL: goto x86_l_1026;
	case 4139ULL: goto x86_l_102b;
	case 4142ULL: goto x86_l_102e;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4156ULL: goto x86_l_103c;
	case 4160ULL: goto x86_l_1040;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4170ULL: goto x86_l_104a;
	case 4172ULL: goto x86_l_104c;
	case 4178ULL: goto x86_l_1052;
	case 4180ULL: goto x86_l_1054;
	case 4185ULL: goto x86_l_1059;
	case 4191ULL: goto x86_l_105f;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4206ULL: goto x86_l_106e;
	case 4209ULL: goto x86_l_1071;
	case 4211ULL: goto x86_l_1073;
	case 4213ULL: goto x86_l_1075;
	case 4215ULL: goto x86_l_1077;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4234ULL: goto x86_l_108a;
	case 4239ULL: goto x86_l_108f;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4256ULL: goto x86_l_10a0;
	case 4258ULL: goto x86_l_10a2;
	case 4261ULL: goto x86_l_10a5;
	case 4267ULL: goto x86_l_10ab;
	case 4270ULL: goto x86_l_10ae;
	case 4274ULL: goto x86_l_10b2;
	case 4279ULL: goto x86_l_10b7;
	case 4286ULL: goto x86_l_10be;
	case 4289ULL: goto x86_l_10c1;
	case 4295ULL: goto x86_l_10c7;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4316ULL: goto x86_l_10dc;
	case 4321ULL: goto x86_l_10e1;
	case 4324ULL: goto x86_l_10e4;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4335ULL: goto x86_l_10ef;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4363ULL: goto x86_l_110b;
	case 4367ULL: goto x86_l_110f;
	case 4372ULL: goto x86_l_1114;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4387ULL: goto x86_l_1123;
	case 4390ULL: goto x86_l_1126;
	case 4392ULL: goto x86_l_1128;
	case 4395ULL: goto x86_l_112b;
	case 4397ULL: goto x86_l_112d;
	case 4400ULL: goto x86_l_1130;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4422ULL: goto x86_l_1146;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4439ULL: goto x86_l_1157;
	case 4442ULL: goto x86_l_115a;
	case 4446ULL: goto x86_l_115e;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4457ULL: goto x86_l_1169;
	case 4459ULL: goto x86_l_116b;
	case 4468ULL: goto x86_l_1174;
	case 4473ULL: goto x86_l_1179;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4490ULL: goto x86_l_118a;
	case 4495ULL: goto x86_l_118f;
	case 4497ULL: goto x86_l_1191;
	case 4499ULL: goto x86_l_1193;
	case 4503ULL: goto x86_l_1197;
	case 4507ULL: goto x86_l_119b;
	case 4511ULL: goto x86_l_119f;
	case 4513ULL: goto x86_l_11a1;
	case 4520ULL: goto x86_l_11a8;
	case 4522ULL: goto x86_l_11aa;
	case 4529ULL: goto x86_l_11b1;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4543ULL: goto x86_l_11bf;
	case 4546ULL: goto x86_l_11c2;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4564ULL: goto x86_l_11d4;
	case 4571ULL: goto x86_l_11db;
	case 4578ULL: goto x86_l_11e2;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4603ULL: goto x86_l_11fb;
	case 4610ULL: goto x86_l_1202;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4632ULL: goto x86_l_1218;
	case 4634ULL: goto x86_l_121a;
	case 4636ULL: goto x86_l_121c;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4653ULL: goto x86_l_122d;
	case 4659ULL: goto x86_l_1233;
	case 4667ULL: goto x86_l_123b;
	case 4672ULL: goto x86_l_1240;
	case 4675ULL: goto x86_l_1243;
	case 4679ULL: goto x86_l_1247;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4692ULL: goto x86_l_1254;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4723ULL: goto x86_l_1273;
	case 4725ULL: goto x86_l_1275;
	case 4728ULL: goto x86_l_1278;
	case 4730ULL: goto x86_l_127a;
	case 4737ULL: goto x86_l_1281;
	case 4743ULL: goto x86_l_1287;
	case 4745ULL: goto x86_l_1289;
	case 4751ULL: goto x86_l_128f;
	case 4756ULL: goto x86_l_1294;
	case 4758ULL: goto x86_l_1296;
	case 4763ULL: goto x86_l_129b;
	case 4767ULL: goto x86_l_129f;
	case 4773ULL: goto x86_l_12a5;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4794ULL: goto x86_l_12ba;
	case 4802ULL: goto x86_l_12c2;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4813ULL: goto x86_l_12cd;
	case 4816ULL: goto x86_l_12d0;
	case 4820ULL: goto x86_l_12d4;
	case 4823ULL: goto x86_l_12d7;
	case 4827ULL: goto x86_l_12db;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4845ULL: goto x86_l_12ed;
	case 4848ULL: goto x86_l_12f0;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4872ULL: goto x86_l_1308;
	case 4880ULL: goto x86_l_1310;
	case 4883ULL: goto x86_l_1313;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4897ULL: goto x86_l_1321;
	case 4904ULL: goto x86_l_1328;
	case 4911ULL: goto x86_l_132f;
	case 4916ULL: goto x86_l_1334;
	case 4919ULL: goto x86_l_1337;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4931ULL: goto x86_l_1343;
	case 4934ULL: goto x86_l_1346;
	case 4940ULL: goto x86_l_134c;
	case 4946ULL: goto x86_l_1352;
	case 4952ULL: goto x86_l_1358;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4984ULL: goto x86_l_1378;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4994ULL: goto x86_l_1382;
	case 4998ULL: goto x86_l_1386;
	case 5002ULL: goto x86_l_138a;
	case 5005ULL: goto x86_l_138d;
	case 5008ULL: goto x86_l_1390;
	case 5011ULL: goto x86_l_1393;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5030ULL: goto x86_l_13a6;
	case 5034ULL: goto x86_l_13aa;
	case 5037ULL: goto x86_l_13ad;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d6d:
	/* 0xd6d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d6f:
	/* 0xd6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d71:
	/* 0xd71: jmp    d8e <tail_handle_snat_fwd_ipv6+0xd8e> */
	goto x86_l_d8e;
x86_l_d73:
	/* 0xd73: mov    BYTE PTR [rsp+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_d77:
	/* 0xd77: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_d7c:
	/* 0xd7c: jmp    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	return 2973ULL;
x86_l_d81:
	/* 0xd81: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_d86:
	/* 0xd86: mov    edi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d8a:
	/* 0xd8a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8c:
	/* 0xd8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8e:
	/* 0xd8e: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_d90:
	/* 0xd90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d92:
	/* 0xd92: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d97:
	/* 0xd97: je     6a0 <tail_handle_snat_fwd_ipv6+0x6a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1696ULL;
	}
x86_l_d9d:
	/* 0xd9d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da0:
	/* 0xda0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da3:
	/* 0xda3: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_da5:
	/* 0xda5: jns    6e5 <tail_handle_snat_fwd_ipv6+0x6e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 1765ULL;
	}
x86_l_dab:
	/* 0xdab: jmp    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	return 2973ULL;
x86_l_db0:
	/* 0xdb0: mov    r14d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db4:
	/* 0xdb4: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_db9:
	/* 0xdb9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_dbc:
	/* 0xdbc: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_dc1:
	/* 0xdc1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dc3:
	/* 0xdc3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc5:
	/* 0xdc5: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_dca:
	/* 0xdca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dcc:
	/* 0xdcc: jne    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2973ULL;
	}
x86_l_dd2:
	/* 0xdd2: mov    WORD PTR [rsp+0x18],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd8:
	/* 0xdd8: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ddd:
	/* 0xddd: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_de2:
	/* 0xde2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_de5:
	/* 0xde5: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_dea:
	/* 0xdea: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_def:
	/* 0xdef: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df2:
	/* 0xdf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df4:
	/* 0xdf4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df6:
	/* 0xdf6: jns    d3d <tail_handle_snat_fwd_ipv6+0xd3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3389ULL;
	}
x86_l_dfc:
	/* 0xdfc: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_e01:
	/* 0xe01: jmp    b9d <tail_handle_snat_fwd_ipv6+0xb9d> */
	return 2973ULL;
x86_l_e06:
	/* 0xe06: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e09:
	/* 0xe09: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e0e:
	/* 0xe0e: jmp    6d3 <tail_handle_snat_fwd_ipv6+0x6d3> */
	return 1747ULL;
x86_l_e13:
	/* 0xe13: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_e14:
	/* 0xe14: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_e16:
	/* 0xe16: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_e18:
	/* 0xe18: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_e1a:
	/* 0xe1a: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_e1c:
	/* 0xe1c: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_e1d:
	/* 0xe1d: sub    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 104ULL);
x86_l_e21:
	/* 0xe21: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_e23:
	/* 0xe23: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_e26:
	/* 0xe26: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_e29:
	/* 0xe29: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e2e:
	/* 0xe2e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e30:
	/* 0xe30: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e32:
	/* 0xe32: mov    rcx,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_e39:
	/* 0xe39: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_e3c:
	/* 0xe3c: imul   r14,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_e40:
	/* 0xe40: mov    rax,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_e47:
	/* 0xe47: cmp    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_e4a:
	/* 0xe4a: jbe    e4f <snat_v6_needs_masquerade+0x3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e4f;
	}
x86_l_e4c:
	/* 0xe4c: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4f:
	/* 0xe4f: mov    rsi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__aux_snat_v6_args)));
x86_l_e56:
	/* 0xe56: mov    rcx,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nat_ipv6_masquerade)));
x86_l_e5d:
	/* 0xe5d: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e60:
	/* 0xe60: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e65:
	/* 0xe65: lea    rbx,[rsi+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_e69:
	/* 0xe69: mov    rcx,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e6d:
	/* 0xe6d: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e72:
	/* 0xe72: cmp    QWORD PTR [rsi+r14*1+0x10],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 16ULL);
x86_l_e77:
	/* 0xe77: jne    e8f <snat_v6_needs_masquerade+0x7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e8f;
	}
x86_l_e79:
	/* 0xe79: cmp    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e7d:
	/* 0xe7d: jne    e8f <snat_v6_needs_masquerade+0x7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e8f;
	}
x86_l_e7f:
	/* 0xe7f: mov    QWORD PTR [rbx+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e83:
	/* 0xe83: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e87:
	/* 0xe87: mov    BYTE PTR [rbx+0x3d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005057ULL);
x86_l_e8b:
	/* 0xe8b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e8d:
	/* 0xe8d: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	goto x86_l_eb7;
x86_l_e8f:
	/* 0xe8f: mov    DWORD PTR [rsp+0xc],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_e93:
	/* 0xe93: mov    rax,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_e9a:
	/* 0xe9a: movzx  ebp,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e9d:
	/* 0xe9d: mov    r12d,DWORD PTR [r15+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_ea1:
	/* 0xea1: mov    ecx,DWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ea5:
	/* 0xea5: lea    rdx,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_ea9:
	/* 0xea9: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_ead:
	/* 0xead: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_eb2:
	/* 0xeb2: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_eb5:
	/* 0xeb5: jbe    ec6 <snat_v6_needs_masquerade+0xb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ec6;
	}
x86_l_eb7:
	/* 0xeb7: add    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_ebb:
	/* 0xebb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ebc:
	/* 0xebc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_ebe:
	/* 0xebe: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_ec0:
	/* 0xec0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_ec2:
	/* 0xec2: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_ec4:
	/* 0xec4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_ec5:
	/* 0xec5: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ec6:
	/* 0xec6: lea    rcx,[rsi+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_eca:
	/* 0xeca: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ece:
	/* 0xece: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ed6:
	/* 0xed6: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed9:
	/* 0xed9: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ede:
	/* 0xede: mov    rcx,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee2:
	/* 0xee2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ee7:
	/* 0xee7: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eec:
	/* 0xeec: mov    BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_ef1:
	/* 0xef1: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_ef8:
	/* 0xef8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_efd:
	/* 0xefd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f02:
	/* 0xf02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f09:
	/* 0xf09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0c:
	/* 0xf0c: je     11db <snat_v6_needs_masquerade+0x3c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11db;
	}
x86_l_f12:
	/* 0xf12: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_f16:
	/* 0xf16: movzx  eax,BYTE PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_f1a:
	/* 0xf1a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_f1d:
	/* 0xf1d: je     fe9 <snat_v6_needs_masquerade+0x1d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe9;
	}
x86_l_f23:
	/* 0xf23: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_f26:
	/* 0xf26: je     fe9 <snat_v6_needs_masquerade+0x1d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fe9;
	}
x86_l_f2c:
	/* 0xf2c: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_f2f:
	/* 0xf2f: jne    10b7 <snat_v6_needs_masquerade+0x2a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10b7;
	}
x86_l_f35:
	/* 0xf35: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_f3c:
	/* 0xf3c: bt     r13,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 40ULL);
x86_l_f41:
	/* 0xf41: jb     144f <snat_v6_needs_masquerade+0x63c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5199ULL;
	}
x86_l_f47:
	/* 0xf47: lea    rdx,[rsp+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_f4c:
	/* 0xf4c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f51:
	/* 0xf51: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f54:
	/* 0xf54: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f58:
	/* 0xf58: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f5a:
	/* 0xf5a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f5f:
	/* 0xf5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f61:
	/* 0xf61: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f63:
	/* 0xf63: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_f68:
	/* 0xf68: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f6a:
	/* 0xf6a: js     110f <snat_v6_needs_masquerade+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_110f;
	}
x86_l_f70:
	/* 0xf70: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_f75:
	/* 0xf75: cmp    al,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 129ULL);
x86_l_f77:
	/* 0xf77: jg     fa6 <snat_v6_needs_masquerade+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_fa6;
	}
x86_l_f79:
	/* 0xf79: add    ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_f7c:
	/* 0xf7c: lea    rdx,[rsp+0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_f81:
	/* 0xf81: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f86:
	/* 0xf86: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f89:
	/* 0xf89: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_f8b:
	/* 0xf8b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f90:
	/* 0xf90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f92:
	/* 0xf92: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f94:
	/* 0xf94: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_f99:
	/* 0xf99: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f9b:
	/* 0xf9b: js     110f <snat_v6_needs_masquerade+0x2fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_110f;
	}
x86_l_fa1:
	/* 0xfa1: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_fa6:
	/* 0xfa6: mov    DWORD PTR [rbx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_fad:
	/* 0xfad: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_fb0:
	/* 0xfb0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fb3:
	/* 0xfb3: jle    1123 <snat_v6_needs_masquerade+0x310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1123;
	}
x86_l_fb9:
	/* 0xfb9: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_fbc:
	/* 0xfbc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fbf:
	/* 0xfbf: jb     1193 <snat_v6_needs_masquerade+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1193;
	}
x86_l_fc5:
	/* 0xfc5: cmp    eax,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_fca:
	/* 0xfca: je     1160 <snat_v6_needs_masquerade+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1160;
	}
x86_l_fd0:
	/* 0xfd0: cmp    eax,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 129ULL);
x86_l_fd5:
	/* 0xfd5: jne    1197 <snat_v6_needs_masquerade+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1197;
	}
x86_l_fdb:
	/* 0xfdb: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_fe0:
	/* 0xfe0: mov    WORD PTR [rbx+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_fe4:
	/* 0xfe4: jmp    1197 <snat_v6_needs_masquerade+0x384> */
	goto x86_l_1197;
x86_l_fe9:
	/* 0xfe9: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_ff3:
	/* 0xff3: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ff7:
	/* 0xff7: mov    rcx,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_ffe:
	/* 0xffe: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1001:
	/* 0x1001: je     10d3 <snat_v6_needs_masquerade+0x2c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d3;
	}
x86_l_1007:
	/* 0x1007: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_100a:
	/* 0x100a: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100e:
	/* 0x100e: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1013:
	/* 0x1013: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_101b:
	/* 0x101b: mov    DWORD PTR [r12],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_101f:
	/* 0x101f: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1022:
	/* 0x1022: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1026:
	/* 0x1026: mov    BYTE PTR [r12+0x4],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_102b:
	/* 0x102b: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_102e:
	/* 0x102e: jne    142a <snat_v6_needs_masquerade+0x617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5162ULL;
	}
x86_l_1034:
	/* 0x1034: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1039:
	/* 0x1039: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_103c:
	/* 0x103c: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1040:
	/* 0x1040: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1043:
	/* 0x1043: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1048:
	/* 0x1048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104a:
	/* 0x104a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_104c:
	/* 0x104c: js     1101 <snat_v6_needs_masquerade+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1101;
	}
x86_l_1052:
	/* 0x1052: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1054:
	/* 0x1054: bt     r13,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 40ULL);
x86_l_1059:
	/* 0x1059: jae    1106 <snat_v6_needs_masquerade+0x2f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1106;
	}
x86_l_105f:
	/* 0x105f: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1066:
	/* 0x1066: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_106b:
	/* 0x106b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_106e:
	/* 0x106e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1071:
	/* 0x1071: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1073:
	/* 0x1073: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1075:
	/* 0x1075: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1077:
	/* 0x1077: je     1448 <snat_v6_needs_masquerade+0x635> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5192ULL;
	}
x86_l_107d:
	/* 0x107d: mov    r15d,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1080:
	/* 0x1080: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_108a:
	/* 0x108a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_108f:
	/* 0x108f: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1096:
	/* 0x1096: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_109b:
	/* 0x109b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a0:
	/* 0x10a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a2:
	/* 0x10a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a5:
	/* 0x10a5: je     1478 <snat_v6_needs_masquerade+0x665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5240ULL;
	}
x86_l_10ab:
	/* 0x10ab: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10ae:
	/* 0x10ae: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10b2:
	/* 0x10b2: jmp    1448 <snat_v6_needs_masquerade+0x635> */
	return 5192ULL;
x86_l_10b7:
	/* 0x10b7: mov    rax,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_extended_ip_protocols)));
x86_l_10be:
	/* 0x10be: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c1:
	/* 0x10c1: je     11db <snat_v6_needs_masquerade+0x3c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11db;
	}
x86_l_10c7:
	/* 0x10c7: mov    DWORD PTR [rbx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10ce:
	/* 0x10ce: jmp    1197 <snat_v6_needs_masquerade+0x384> */
	goto x86_l_1197;
x86_l_10d3:
	/* 0x10d3: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_10d6:
	/* 0x10d6: jne    1464 <snat_v6_needs_masquerade+0x651> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5220ULL;
	}
x86_l_10dc:
	/* 0x10dc: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_10e1:
	/* 0x10e1: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10e4:
	/* 0x10e4: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10e8:
	/* 0x10e8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10ed:
	/* 0x10ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ef:
	/* 0x10ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10f1:
	/* 0x10f1: jns    1197 <snat_v6_needs_masquerade+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1197;
	}
x86_l_10f7:
	/* 0x10f7: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_10fc:
	/* 0x10fc: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	goto x86_l_eb7;
x86_l_1101:
	/* 0x1101: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_1106:
	/* 0x1106: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_110b:
	/* 0x110b: mov    QWORD PTR [r12],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110f:
	/* 0x110f: cmp    eax,0xffffff77 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967159ULL);
x86_l_1114:
	/* 0x1114: je     11db <snat_v6_needs_masquerade+0x3c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11db;
	}
x86_l_111a:
	/* 0x111a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_111c:
	/* 0x111c: je     1197 <snat_v6_needs_masquerade+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1197;
	}
x86_l_111e:
	/* 0x111e: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	goto x86_l_eb7;
x86_l_1123:
	/* 0x1123: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1126:
	/* 0x1126: je     1193 <snat_v6_needs_masquerade+0x380> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1193;
	}
x86_l_1128:
	/* 0x1128: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_112b:
	/* 0x112b: jne    1197 <snat_v6_needs_masquerade+0x384> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1197;
	}
x86_l_112d:
	/* 0x112d: mov    r15d,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1130:
	/* 0x1130: movabs rax,0x6c0269020f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463896904207ULL);
x86_l_113a:
	/* 0x113a: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_113f:
	/* 0x113f: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1146:
	/* 0x1146: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_114b:
	/* 0x114b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1150:
	/* 0x1150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1152:
	/* 0x1152: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1155:
	/* 0x1155: je     116b <snat_v6_needs_masquerade+0x358> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_116b;
	}
x86_l_1157:
	/* 0x1157: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_115a:
	/* 0x115a: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_115e:
	/* 0x115e: jmp    1193 <snat_v6_needs_masquerade+0x380> */
	goto x86_l_1193;
x86_l_1160:
	/* 0x1160: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_1165:
	/* 0x1165: mov    WORD PTR [rbx+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1169:
	/* 0x1169: jmp    1197 <snat_v6_needs_masquerade+0x384> */
	goto x86_l_1197;
x86_l_116b:
	/* 0x116b: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1174:
	/* 0x1174: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1179:
	/* 0x1179: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1180:
	/* 0x1180: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1185:
	/* 0x1185: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118a:
	/* 0x118a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_118f:
	/* 0x118f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1191:
	/* 0x1191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1193:
	/* 0x1193: or     BYTE PTR [rbx+0x25],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 158913789954ULL);
x86_l_1197:
	/* 0x1197: movzx  ebp,BYTE PTR [rbx+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_119b:
	/* 0x119b: cmp    BYTE PTR [rbx+0x24],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822662ULL);
x86_l_119f:
	/* 0x119f: jne    11aa <snat_v6_needs_masquerade+0x397> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11aa;
	}
x86_l_11a1:
	/* 0x11a1: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_11a8:
	/* 0x11a8: jmp    11b1 <snat_v6_needs_masquerade+0x39e> */
	goto x86_l_11b1;
x86_l_11aa:
	/* 0x11aa: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_11b1:
	/* 0x11b1: mov    BYTE PTR [rbx+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789953ULL);
x86_l_11b5:
	/* 0x11b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11ba:
	/* 0x11ba: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_11bd:
	/* 0x11bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bf:
	/* 0x11bf: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11c2:
	/* 0x11c2: mov    BYTE PTR [rbx+0x25],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_11c6:
	/* 0x11c6: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_11cb:
	/* 0x11cb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_11ce:
	/* 0x11ce: jne    eb7 <snat_v6_needs_masquerade+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_eb7;
	}
x86_l_11d4:
	/* 0x11d4: mov    DWORD PTR [rbx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11db:
	/* 0x11db: mov    WORD PTR [rsp+0x16],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489281024ULL);
x86_l_11e2:
	/* 0x11e2: mov    DWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476896ULL);
x86_l_11ea:
	/* 0x11ea: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ed:
	/* 0x11ed: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11f1:
	/* 0x11f1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f6:
	/* 0x11f6: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11fb:
	/* 0x11fb: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1202:
	/* 0x1202: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_1209:
	/* 0x1209: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_120e:
	/* 0x120e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1213:
	/* 0x1213: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1215:
	/* 0x1215: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1218:
	/* 0x1218: je     1233 <snat_v6_needs_masquerade+0x420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1233;
	}
x86_l_121a:
	/* 0x121a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121c:
	/* 0x121c: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_121f:
	/* 0x121f: ja     13c8 <snat_v6_needs_masquerade+0x5b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5064ULL;
	}
x86_l_1225:
	/* 0x1225: mov    ecx,0x604 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1540ULL);
x86_l_122a:
	/* 0x122a: bt     ecx,eax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_122d:
	/* 0x122d: jae    13c8 <snat_v6_needs_masquerade+0x5b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5064ULL;
	}
x86_l_1233:
	/* 0x1233: mov    DWORD PTR [rsp+0x10],0x100 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476992ULL);
x86_l_123b:
	/* 0x123b: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1240:
	/* 0x1240: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1243:
	/* 0x1243: mov    rcx,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1247:
	/* 0x1247: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_124c:
	/* 0x124c: mov    QWORD PTR [rsp+0x1c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1251:
	/* 0x1251: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1254:
	/* 0x1254: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1258:
	/* 0x1258: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_125d:
	/* 0x125d: mov    QWORD PTR [rsp+0x2c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1262:
	/* 0x1262: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_egress_gw_policy_v6)));
x86_l_1269:
	/* 0x1269: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_126e:
	/* 0x126e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1273:
	/* 0x1273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1275:
	/* 0x1275: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1278:
	/* 0x1278: je     1287 <snat_v6_needs_masquerade+0x474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1287;
	}
x86_l_127a:
	/* 0x127a: test   DWORD PTR [rax+0x10],0xfeffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72997666815ULL);
x86_l_1281:
	/* 0x1281: jne    1371 <snat_v6_needs_masquerade+0x55e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1371;
	}
x86_l_1287:
	/* 0x1287: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1289:
	/* 0x1289: cmp    ecx,0xffffcefa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4294954746ULL);
x86_l_128f:
	/* 0x128f: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1294:
	/* 0x1294: jne    12a5 <snat_v6_needs_masquerade+0x492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12a5;
	}
x86_l_1296:
	/* 0x1296: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_129b:
	/* 0x129b: cmp    BYTE PTR [rbx+0x4],0xff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869439ULL);
x86_l_129f:
	/* 0x129f: je     eb7 <snat_v6_needs_masquerade+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eb7;
	}
x86_l_12a5:
	/* 0x12a5: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_12a8:
	/* 0x12a8: je     12ba <snat_v6_needs_masquerade+0x4a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ba;
	}
x86_l_12aa:
	/* 0x12aa: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_12af:
	/* 0x12af: test   BYTE PTR [r15+0x8],0x9 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738377ULL);
x86_l_12b4:
	/* 0x12b4: jne    eb7 <snat_v6_needs_masquerade+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_eb7;
	}
x86_l_12ba:
	/* 0x12ba: mov    DWORD PTR [rsp+0x10],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476864ULL);
x86_l_12c2:
	/* 0x12c2: mov    DWORD PTR [rsp+0x14],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12c6:
	/* 0x12c6: mov    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12c9:
	/* 0x12c9: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12cd:
	/* 0x12cd: mov    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d0:
	/* 0x12d0: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_12d4:
	/* 0x12d4: mov    eax,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12d7:
	/* 0x12d7: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12db:
	/* 0x12db: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipmasq_v6)));
x86_l_12e2:
	/* 0x12e2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12e7:
	/* 0x12e7: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_12ed:
	/* 0x12ed: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_12f0:
	/* 0x12f0: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_12f3:
	/* 0x12f3: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_12f8:
	/* 0x12f8: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_12fb:
	/* 0x12fb: jne    eb7 <snat_v6_needs_masquerade+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_eb7;
	}
x86_l_1301:
	/* 0x1301: mov    WORD PTR [rsp+0x16],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489281024ULL);
x86_l_1308:
	/* 0x1308: mov    DWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476896ULL);
x86_l_1310:
	/* 0x1310: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1313:
	/* 0x1313: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1317:
	/* 0x1317: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_131c:
	/* 0x131c: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1321:
	/* 0x1321: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1328:
	/* 0x1328: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_132f:
	/* 0x132f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1334:
	/* 0x1334: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1337:
	/* 0x1337: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_133a:
	/* 0x133a: je     135e <snat_v6_needs_masquerade+0x54b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135e;
	}
x86_l_133c:
	/* 0x133c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133e:
	/* 0x133e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1340:
	/* 0x1340: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_1343:
	/* 0x1343: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1346:
	/* 0x1346: je     13dd <snat_v6_needs_masquerade+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5085ULL;
	}
x86_l_134c:
	/* 0x134c: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_1352:
	/* 0x1352: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_1358:
	/* 0x1358: je     13dd <snat_v6_needs_masquerade+0x5ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5085ULL;
	}
x86_l_135e:
	/* 0x135e: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1361:
	/* 0x1361: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_1366:
	/* 0x1366: jne    13ff <snat_v6_needs_masquerade+0x5ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5119ULL;
	}
x86_l_136c:
	/* 0x136c: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	goto x86_l_eb7;
x86_l_1371:
	/* 0x1371: mov    rcx,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_args)));
x86_l_1378:
	/* 0x1378: add    rcx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_137b:
	/* 0x137b: add    rcx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_137f:
	/* 0x137f: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1382:
	/* 0x1382: mov    rsi,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1386:
	/* 0x1386: mov    QWORD PTR [rcx+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_138a:
	/* 0x138a: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138d:
	/* 0x138d: mov    eax,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1390:
	/* 0x1390: mov    DWORD PTR [rbx+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1393:
	/* 0x1393: cmp    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1398:
	/* 0x1398: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_139d:
	/* 0x139d: jne    13a6 <snat_v6_needs_masquerade+0x593> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13a6;
	}
x86_l_139f:
	/* 0x139f: cmp    QWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_13a4:
	/* 0x13a4: je     1416 <snat_v6_needs_masquerade+0x603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5142ULL;
	}
x86_l_13a6:
	/* 0x13a6: mov    BYTE PTR [rbx+0x3e],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972353ULL);
x86_l_13aa:
	/* 0x13aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ad:
	/* 0x13ad: je     e87 <snat_v6_needs_masquerade+0x74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e87;
	}
	return 5043ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5043ULL: goto x86_l_13b3;
	case 5046ULL: goto x86_l_13b6;
	case 5048ULL: goto x86_l_13b8;
	case 5050ULL: goto x86_l_13ba;
	case 5056ULL: goto x86_l_13c0;
	case 5059ULL: goto x86_l_13c3;
	case 5064ULL: goto x86_l_13c8;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5080ULL: goto x86_l_13d8;
	case 5085ULL: goto x86_l_13dd;
	case 5092ULL: goto x86_l_13e4;
	case 5095ULL: goto x86_l_13e7;
	case 5097ULL: goto x86_l_13e9;
	case 5100ULL: goto x86_l_13ec;
	case 5102ULL: goto x86_l_13ee;
	case 5106ULL: goto x86_l_13f2;
	case 5108ULL: goto x86_l_13f4;
	case 5113ULL: goto x86_l_13f9;
	case 5119ULL: goto x86_l_13ff;
	case 5124ULL: goto x86_l_1404;
	case 5128ULL: goto x86_l_1408;
	case 5133ULL: goto x86_l_140d;
	case 5137ULL: goto x86_l_1411;
	case 5142ULL: goto x86_l_1416;
	case 5147ULL: goto x86_l_141b;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5162ULL: goto x86_l_142a;
	case 5165ULL: goto x86_l_142d;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5185ULL: goto x86_l_1441;
	case 5187ULL: goto x86_l_1443;
	case 5189ULL: goto x86_l_1445;
	case 5192ULL: goto x86_l_1448;
	case 5194ULL: goto x86_l_144a;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5225ULL: goto x86_l_1469;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5278ULL: goto x86_l_149e;
	case 5280ULL: goto x86_l_14a0;
	case 5282ULL: goto x86_l_14a2;
	case 5283ULL: goto x86_l_14a3;
	case 5285ULL: goto x86_l_14a5;
	case 5287ULL: goto x86_l_14a7;
	case 5289ULL: goto x86_l_14a9;
	case 5291ULL: goto x86_l_14ab;
	case 5292ULL: goto x86_l_14ac;
	case 5299ULL: goto x86_l_14b3;
	case 5304ULL: goto x86_l_14b8;
	case 5312ULL: goto x86_l_14c0;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5339ULL: goto x86_l_14db;
	case 5342ULL: goto x86_l_14de;
	case 5346ULL: goto x86_l_14e2;
	case 5353ULL: goto x86_l_14e9;
	case 5357ULL: goto x86_l_14ed;
	case 5359ULL: goto x86_l_14ef;
	case 5363ULL: goto x86_l_14f3;
	case 5370ULL: goto x86_l_14fa;
	case 5374ULL: goto x86_l_14fe;
	case 5378ULL: goto x86_l_1502;
	case 5381ULL: goto x86_l_1505;
	case 5385ULL: goto x86_l_1509;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5397ULL: goto x86_l_1515;
	case 5399ULL: goto x86_l_1517;
	case 5406ULL: goto x86_l_151e;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5415ULL: goto x86_l_1527;
	case 5416ULL: goto x86_l_1528;
	case 5417ULL: goto x86_l_1529;
	case 5424ULL: goto x86_l_1530;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5438ULL: goto x86_l_153e;
	case 5440ULL: goto x86_l_1540;
	case 5443ULL: goto x86_l_1543;
	case 5449ULL: goto x86_l_1549;
	case 5452ULL: goto x86_l_154c;
	case 5454ULL: goto x86_l_154e;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5474ULL: goto x86_l_1562;
	case 5479ULL: goto x86_l_1567;
	case 5481ULL: goto x86_l_1569;
	case 5483ULL: goto x86_l_156b;
	case 5485ULL: goto x86_l_156d;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5503ULL: goto x86_l_157f;
	case 5509ULL: goto x86_l_1585;
	case 5512ULL: goto x86_l_1588;
	case 5515ULL: goto x86_l_158b;
	case 5522ULL: goto x86_l_1592;
	case 5530ULL: goto x86_l_159a;
	case 5533ULL: goto x86_l_159d;
	case 5536ULL: goto x86_l_15a0;
	case 5540ULL: goto x86_l_15a4;
	case 5544ULL: goto x86_l_15a8;
	case 5547ULL: goto x86_l_15ab;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5569ULL: goto x86_l_15c1;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5587ULL: goto x86_l_15d3;
	case 5597ULL: goto x86_l_15dd;
	case 5605ULL: goto x86_l_15e5;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5641ULL: goto x86_l_1609;
	case 5647ULL: goto x86_l_160f;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5663ULL: goto x86_l_161f;
	case 5671ULL: goto x86_l_1627;
	case 5676ULL: goto x86_l_162c;
	case 5678ULL: goto x86_l_162e;
	case 5680ULL: goto x86_l_1630;
	case 5685ULL: goto x86_l_1635;
	case 5687ULL: goto x86_l_1637;
	case 5693ULL: goto x86_l_163d;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5710ULL: goto x86_l_164e;
	case 5713ULL: goto x86_l_1651;
	case 5719ULL: goto x86_l_1657;
	case 5722ULL: goto x86_l_165a;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5737ULL: goto x86_l_1669;
	case 5742ULL: goto x86_l_166e;
	case 5750ULL: goto x86_l_1676;
	case 5756ULL: goto x86_l_167c;
	case 5761ULL: goto x86_l_1681;
	case 5769ULL: goto x86_l_1689;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5791ULL: goto x86_l_169f;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5809ULL: goto x86_l_16b1;
	case 5815ULL: goto x86_l_16b7;
	case 5821ULL: goto x86_l_16bd;
	case 5827ULL: goto x86_l_16c3;
	case 5833ULL: goto x86_l_16c9;
	case 5839ULL: goto x86_l_16cf;
	case 5841ULL: goto x86_l_16d1;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5862ULL: goto x86_l_16e6;
	case 5868ULL: goto x86_l_16ec;
	case 5874ULL: goto x86_l_16f2;
	case 5878ULL: goto x86_l_16f6;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5898ULL: goto x86_l_170a;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5917ULL: goto x86_l_171d;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5933ULL: goto x86_l_172d;
	case 5936ULL: goto x86_l_1730;
	case 5942ULL: goto x86_l_1736;
	case 5948ULL: goto x86_l_173c;
	case 5954ULL: goto x86_l_1742;
	case 5960ULL: goto x86_l_1748;
	case 5966ULL: goto x86_l_174e;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5981ULL: goto x86_l_175d;
	case 5989ULL: goto x86_l_1765;
	case 5995ULL: goto x86_l_176b;
	case 6003ULL: goto x86_l_1773;
	case 6007ULL: goto x86_l_1777;
	case 6016ULL: goto x86_l_1780;
	case 6025ULL: goto x86_l_1789;
	case 6034ULL: goto x86_l_1792;
	case 6043ULL: goto x86_l_179b;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6080ULL: goto x86_l_17c0;
	case 6082ULL: goto x86_l_17c2;
	case 6087ULL: goto x86_l_17c7;
	case 6089ULL: goto x86_l_17c9;
	case 6095ULL: goto x86_l_17cf;
	case 6098ULL: goto x86_l_17d2;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6114ULL: goto x86_l_17e2;
	case 6119ULL: goto x86_l_17e7;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6134ULL: goto x86_l_17f6;
	case 6139ULL: goto x86_l_17fb;
	case 6144ULL: goto x86_l_1800;
	case 6149ULL: goto x86_l_1805;
	case 6154ULL: goto x86_l_180a;
	case 6158ULL: goto x86_l_180e;
	case 6164ULL: goto x86_l_1814;
	case 6169ULL: goto x86_l_1819;
	case 6179ULL: goto x86_l_1823;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6197ULL: goto x86_l_1835;
	case 6200ULL: goto x86_l_1838;
	case 6205ULL: goto x86_l_183d;
	case 6210ULL: goto x86_l_1842;
	case 6213ULL: goto x86_l_1845;
	case 6218ULL: goto x86_l_184a;
	case 6220ULL: goto x86_l_184c;
	case 6222ULL: goto x86_l_184e;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6236ULL: goto x86_l_185c;
	case 6240ULL: goto x86_l_1860;
	case 6245ULL: goto x86_l_1865;
	case 6247ULL: goto x86_l_1867;
	case 6251ULL: goto x86_l_186b;
	case 6257ULL: goto x86_l_1871;
	case 6261ULL: goto x86_l_1875;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6280ULL: goto x86_l_1888;
	case 6285ULL: goto x86_l_188d;
	case 6293ULL: goto x86_l_1895;
	case 6301ULL: goto x86_l_189d;
	case 6307ULL: goto x86_l_18a3;
	case 6316ULL: goto x86_l_18ac;
	case 6324ULL: goto x86_l_18b4;
	case 6330ULL: goto x86_l_18ba;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6347ULL: goto x86_l_18cb;
	case 6350ULL: goto x86_l_18ce;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6367ULL: goto x86_l_18df;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6379ULL: goto x86_l_18eb;
	case 6381ULL: goto x86_l_18ed;
	case 6384ULL: goto x86_l_18f0;
	case 6391ULL: goto x86_l_18f7;
	case 6395ULL: goto x86_l_18fb;
	case 6399ULL: goto x86_l_18ff;
	case 6401ULL: goto x86_l_1901;
	case 6405ULL: goto x86_l_1905;
	case 6412ULL: goto x86_l_190c;
	case 6418ULL: goto x86_l_1912;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6434ULL: goto x86_l_1922;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6483ULL: goto x86_l_1953;
	case 6487ULL: goto x86_l_1957;
	case 6489ULL: goto x86_l_1959;
	case 6496ULL: goto x86_l_1960;
	case 6498ULL: goto x86_l_1962;
	case 6505ULL: goto x86_l_1969;
	case 6511ULL: goto x86_l_196f;
	case 6522ULL: goto x86_l_197a;
	case 6529ULL: goto x86_l_1981;
	case 6532ULL: goto x86_l_1984;
	case 6542ULL: goto x86_l_198e;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6558ULL: goto x86_l_199e;
	case 6564ULL: goto x86_l_19a4;
	case 6567ULL: goto x86_l_19a7;
	case 6576ULL: goto x86_l_19b0;
	case 6585ULL: goto x86_l_19b9;
	case 6595ULL: goto x86_l_19c3;
	case 6600ULL: goto x86_l_19c8;
	case 6607ULL: goto x86_l_19cf;
	case 6612ULL: goto x86_l_19d4;
	case 6617ULL: goto x86_l_19d9;
	case 6619ULL: goto x86_l_19db;
	case 6622ULL: goto x86_l_19de;
	case 6624ULL: goto x86_l_19e0;
	case 6627ULL: goto x86_l_19e3;
	case 6631ULL: goto x86_l_19e7;
	case 6633ULL: goto x86_l_19e9;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6669ULL: goto x86_l_1a0d;
	case 6671ULL: goto x86_l_1a0f;
	case 6673ULL: goto x86_l_1a11;
	case 6680ULL: goto x86_l_1a18;
	case 6688ULL: goto x86_l_1a20;
	case 6698ULL: goto x86_l_1a2a;
	case 6700ULL: goto x86_l_1a2c;
	case 6709ULL: goto x86_l_1a35;
	case 6711ULL: goto x86_l_1a37;
	case 6719ULL: goto x86_l_1a3f;
	case 6722ULL: goto x86_l_1a42;
	case 6730ULL: goto x86_l_1a4a;
	case 6735ULL: goto x86_l_1a4f;
	case 6738ULL: goto x86_l_1a52;
	case 6743ULL: goto x86_l_1a57;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6749ULL: goto x86_l_1a5d;
	case 6756ULL: goto x86_l_1a64;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6765ULL: goto x86_l_1a6d;
	case 6770ULL: goto x86_l_1a72;
	case 6773ULL: goto x86_l_1a75;
	case 6777ULL: goto x86_l_1a79;
	case 6783ULL: goto x86_l_1a7f;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6799ULL: goto x86_l_1a8f;
	case 6806ULL: goto x86_l_1a96;
	case 6808ULL: goto x86_l_1a98;
	case 6813ULL: goto x86_l_1a9d;
	case 6818ULL: goto x86_l_1aa2;
	case 6829ULL: goto x86_l_1aad;
	case 6836ULL: goto x86_l_1ab4;
	case 6840ULL: goto x86_l_1ab8;
	case 6843ULL: goto x86_l_1abb;
	case 6848ULL: goto x86_l_1ac0;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6856ULL: goto x86_l_1ac8;
	case 6862ULL: goto x86_l_1ace;
	case 6865ULL: goto x86_l_1ad1;
	case 6868ULL: goto x86_l_1ad4;
	case 6870ULL: goto x86_l_1ad6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13b3:
	/* 0x13b3: mov    ecx,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13b6:
	/* 0x13b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b8:
	/* 0x13b8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_13ba:
	/* 0x13ba: je     eb7 <snat_v6_needs_masquerade+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3767ULL;
	}
x86_l_13c0:
	/* 0x13c0: mov    DWORD PTR [rbx+0x44],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_13c3:
	/* 0x13c3: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	return 3767ULL;
x86_l_13c8:
	/* 0x13c8: add    eax,0xfeff0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4278124544ULL);
x86_l_13cd:
	/* 0x13cd: cmp    eax,0xffff0001 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294901761ULL);
x86_l_13d2:
	/* 0x13d2: jae    1233 <snat_v6_needs_masquerade+0x420> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4659ULL;
	}
x86_l_13d8:
	/* 0x13d8: jmp    1287 <snat_v6_needs_masquerade+0x474> */
	return 4743ULL;
x86_l_13dd:
	/* 0x13dd: mov    rcx,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_remote_node_masquerade)));
x86_l_13e4:
	/* 0x13e4: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e7:
	/* 0x13e7: jne    13ff <snat_v6_needs_masquerade+0x5ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13ff;
	}
x86_l_13e9:
	/* 0x13e9: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_13ec:
	/* 0x13ec: je     1420 <snat_v6_needs_masquerade+0x60d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1420;
	}
x86_l_13ee:
	/* 0x13ee: movzx  eax,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_13f2:
	/* 0x13f2: and    al,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_13f4:
	/* 0x13f4: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_13f9:
	/* 0x13f9: jne    eb7 <snat_v6_needs_masquerade+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3767ULL;
	}
x86_l_13ff:
	/* 0x13ff: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1404:
	/* 0x1404: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1408:
	/* 0x1408: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_140d:
	/* 0x140d: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1411:
	/* 0x1411: jmp    e8b <snat_v6_needs_masquerade+0x78> */
	return 3723ULL;
x86_l_1416:
	/* 0x1416: mov    eax,0xffffff34 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967092ULL);
x86_l_141b:
	/* 0x141b: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	return 3767ULL;
x86_l_1420:
	/* 0x1420: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_1425:
	/* 0x1425: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	return 3767ULL;
x86_l_142a:
	/* 0x142a: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_142d:
	/* 0x142d: mov    rdi,QWORD PTR [rip+0x20] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1434:
	/* 0x1434: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1439:
	/* 0x1439: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_143c:
	/* 0x143c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143e:
	/* 0x143e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1441:
	/* 0x1441: je     146e <snat_v6_needs_masquerade+0x65b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_146e;
	}
x86_l_1443:
	/* 0x1443: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1445:
	/* 0x1445: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1448:
	/* 0x1448: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_144a:
	/* 0x144a: jmp    1106 <snat_v6_needs_masquerade+0x2f3> */
	return 4358ULL;
x86_l_144f:
	/* 0x144f: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1454:
	/* 0x1454: cmp    eax,0xffffff77 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967159ULL);
x86_l_1459:
	/* 0x1459: jne    111a <snat_v6_needs_masquerade+0x307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4378ULL;
	}
x86_l_145f:
	/* 0x145f: jmp    11db <snat_v6_needs_masquerade+0x3c8> */
	return 4571ULL;
x86_l_1464:
	/* 0x1464: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_1469:
	/* 0x1469: jmp    eb7 <snat_v6_needs_masquerade+0xa4> */
	return 3767ULL;
x86_l_146e:
	/* 0x146e: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_1473:
	/* 0x1473: jmp    1106 <snat_v6_needs_masquerade+0x2f3> */
	return 4358ULL;
x86_l_1478:
	/* 0x1478: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1481:
	/* 0x1481: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1486:
	/* 0x1486: mov    rdi,QWORD PTR [rip+0x1c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_148d:
	/* 0x148d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1492:
	/* 0x1492: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1497:
	/* 0x1497: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_149c:
	/* 0x149c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149e:
	/* 0x149e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a0:
	/* 0x14a0: jmp    1448 <snat_v6_needs_masquerade+0x635> */
	goto x86_l_1448;
x86_l_14a2:
	/* 0x14a2: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_14a3:
	/* 0x14a3: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_14a5:
	/* 0x14a5: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_14a7:
	/* 0x14a7: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_14a9:
	/* 0x14a9: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_14ab:
	/* 0x14ab: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_14ac:
	/* 0x14ac: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_14b3:
	/* 0x14b3: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14b8:
	/* 0x14b8: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14c0:
	/* 0x14c0: mov    QWORD PTR [rsp+0xa0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_14c8:
	/* 0x14c8: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14d0:
	/* 0x14d0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d2:
	/* 0x14d2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14d4:
	/* 0x14d4: mov    rcx,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_14db:
	/* 0x14db: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_14de:
	/* 0x14de: imul   r12,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_14e2:
	/* 0x14e2: mov    r13,QWORD PTR [rip+0x6b4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_14e9:
	/* 0x14e9: cmp    r12,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_14ed:
	/* 0x14ed: jbe    14f3 <snat_v6_nat+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_14f3;
	}
x86_l_14ef:
	/* 0x14ef: mov    r12,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f3:
	/* 0x14f3: mov    r15,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_14fa:
	/* 0x14fa: movzx  ecx,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14fe:
	/* 0x14fe: mov    r14d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1502:
	/* 0x1502: mov    edx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1505:
	/* 0x1505: lea    rsi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1509:
	/* 0x1509: add    rsi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_150d:
	/* 0x150d: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1512:
	/* 0x1512: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1515:
	/* 0x1515: jbe    1529 <snat_v6_nat+0x87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1529;
	}
x86_l_1517:
	/* 0x1517: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_151e:
	/* 0x151e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_151f:
	/* 0x151f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1521:
	/* 0x1521: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1523:
	/* 0x1523: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1525:
	/* 0x1525: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1527:
	/* 0x1527: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1528:
	/* 0x1528: ret */
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1529:
	/* 0x1529: add    r12,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 1712ULL);
x86_l_1530:
	/* 0x1530: movzx  edx,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1536:
	/* 0x1536: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_153b:
	/* 0x153b: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_153e:
	/* 0x153e: je     154e <snat_v6_nat+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_154e;
	}
x86_l_1540:
	/* 0x1540: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_1543:
	/* 0x1543: je     15fa <snat_v6_nat+0x158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15fa;
	}
x86_l_1549:
	/* 0x1549: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_154c:
	/* 0x154c: jne    1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1517;
	}
x86_l_154e:
	/* 0x154e: mov    rsi,QWORD PTR [rip+0x6b4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1555:
	/* 0x1555: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1558:
	/* 0x1558: bt     QWORD PTR [rsp+0xa0],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 687194767400ULL);
x86_l_1562:
	/* 0x1562: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_1567:
	/* 0x1567: jae    156d <snat_v6_nat+0xcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_156d;
	}
x86_l_1569:
	/* 0x1569: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_156b:
	/* 0x156b: je     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_156d:
	/* 0x156d: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1577:
	/* 0x1577: lea    rbp,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_157c:
	/* 0x157c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157f:
	/* 0x157f: je     1681 <snat_v6_nat+0x1df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1681;
	}
x86_l_1585:
	/* 0x1585: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1588:
	/* 0x1588: mov    r15,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158b:
	/* 0x158b: mov    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1592:
	/* 0x1592: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_159a:
	/* 0x159a: mov    DWORD PTR [r14],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159d:
	/* 0x159d: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_15a0:
	/* 0x15a0: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_15a4:
	/* 0x15a4: mov    BYTE PTR [r14+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15a8:
	/* 0x15a8: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_15ab:
	/* 0x15ab: jne    2209 <snat_v6_nat+0xd67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8713ULL;
	}
x86_l_15b1:
	/* 0x15b1: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_15b6:
	/* 0x15b6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_15c1:
	/* 0x15c1: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_15c4:
	/* 0x15c4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15c9:
	/* 0x15c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cb:
	/* 0x15cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15cd:
	/* 0x15cd: js     1715 <snat_v6_nat+0x273> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1715;
	}
x86_l_15d3:
	/* 0x15d3: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_15dd:
	/* 0x15dd: test   QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_15e5:
	/* 0x15e5: jne    2229 <snat_v6_nat+0xd87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8745ULL;
	}
x86_l_15eb:
	/* 0x15eb: mov    QWORD PTR [r14],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ee:
	/* 0x15ee: mov    r15,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_15f5:
	/* 0x15f5: jmp    16b1 <snat_v6_nat+0x20f> */
	goto x86_l_16b1;
x86_l_15fa:
	/* 0x15fa: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_15ff:
	/* 0x15ff: bt     QWORD PTR [rsp+0xa0],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 687194767400ULL);
x86_l_1609:
	/* 0x1609: jb     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1517;
	}
x86_l_160f:
	/* 0x160f: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1617:
	/* 0x1617: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_161c:
	/* 0x161c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_161f:
	/* 0x161f: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1627:
	/* 0x1627: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_162c:
	/* 0x162c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162e:
	/* 0x162e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1630:
	/* 0x1630: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1635:
	/* 0x1635: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1637:
	/* 0x1637: js     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1517;
	}
x86_l_163d:
	/* 0x163d: movzx  ecx,BYTE PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_1645:
	/* 0x1645: cmp    ecx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_1648:
	/* 0x1648: jg     1722 <snat_v6_nat+0x280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1722;
	}
x86_l_164e:
	/* 0x164e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1651:
	/* 0x1651: je     1758 <snat_v6_nat+0x2b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1758;
	}
x86_l_1657:
	/* 0x1657: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_165a:
	/* 0x165a: je     176b <snat_v6_nat+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_176b;
	}
x86_l_1660:
	/* 0x1660: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1663:
	/* 0x1663: jne    174e <snat_v6_nat+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_174e;
	}
x86_l_1669:
	/* 0x1669: mov    eax,0xffffff6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967151ULL);
x86_l_166e:
	/* 0x166e: cmp    BYTE PTR [rsp+0xb9],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 794568949761ULL);
x86_l_1676:
	/* 0x1676: jbe    176b <snat_v6_nat+0x2c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_176b;
	}
x86_l_167c:
	/* 0x167c: jmp    1517 <snat_v6_nat+0x75> */
	goto x86_l_1517;
x86_l_1681:
	/* 0x1681: test   QWORD PTR [rsp+0xa0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1689:
	/* 0x1689: jne    1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1517;
	}
x86_l_168f:
	/* 0x168f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1694:
	/* 0x1694: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1697:
	/* 0x1697: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_169f:
	/* 0x169f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_16a2:
	/* 0x16a2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_16a7:
	/* 0x16a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a9:
	/* 0x16a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16ab:
	/* 0x16ab: js     1a98 <snat_v6_nat+0x5f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a98;
	}
x86_l_16b1:
	/* 0x16b1: movzx  ecx,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_16b7:
	/* 0x16b7: movzx  eax,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_16bd:
	/* 0x16bd: mov    WORD PTR [r12+0x22],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_16c3:
	/* 0x16c3: mov    WORD PTR [r12+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16c9:
	/* 0x16c9: cmp    BYTE PTR [r12+0x3e],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_16cf:
	/* 0x16cf: je     16de <snat_v6_nat+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16de;
	}
x86_l_16d1:
	/* 0x16d1: mov    DWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_16d9:
	/* 0x16d9: jmp    18b4 <snat_v6_nat+0x412> */
	goto x86_l_18b4;
x86_l_16de:
	/* 0x16de: mov    DWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_16e6:
	/* 0x16e6: cmp    BYTE PTR [r12+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_16ec:
	/* 0x16ec: jne    18b4 <snat_v6_nat+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18b4;
	}
x86_l_16f2:
	/* 0x16f2: rol    cx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_16f6:
	/* 0x16f6: mov    rax,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_16fd:
	/* 0x16fd: movzx  edx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1700:
	/* 0x1700: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1702:
	/* 0x1702: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_1707:
	/* 0x1707: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_170a:
	/* 0x170a: jae    18b4 <snat_v6_nat+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18b4;
	}
x86_l_1710:
	/* 0x1710: jmp    1517 <snat_v6_nat+0x75> */
	goto x86_l_1517;
x86_l_1715:
	/* 0x1715: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_171a:
	/* 0x171a: mov    QWORD PTR [r14],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_171d:
	/* 0x171d: jmp    1517 <snat_v6_nat+0x75> */
	goto x86_l_1517;
x86_l_1722:
	/* 0x1722: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_1727:
	/* 0x1727: lea    edx,[rcx-0x87] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551481ULL);
x86_l_172d:
	/* 0x172d: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1730:
	/* 0x1730: jb     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1517;
	}
x86_l_1736:
	/* 0x1736: cmp    ecx,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 128ULL);
x86_l_173c:
	/* 0x173c: je     188d <snat_v6_nat+0x3eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_188d;
	}
x86_l_1742:
	/* 0x1742: cmp    ecx,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 129ULL);
x86_l_1748:
	/* 0x1748: je     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1517;
	}
x86_l_174e:
	/* 0x174e: mov    eax,0xffffff58 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967128ULL);
x86_l_1753:
	/* 0x1753: jmp    1517 <snat_v6_nat+0x75> */
	goto x86_l_1517;
x86_l_1758:
	/* 0x1758: mov    eax,0xffffff6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967151ULL);
x86_l_175d:
	/* 0x175d: cmp    BYTE PTR [rsp+0xb9],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 794568949766ULL);
x86_l_1765:
	/* 0x1765: ja     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1517;
	}
x86_l_176b:
	/* 0x176b: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1773:
	/* 0x1773: lea    r14d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1777:
	/* 0x1777: mov    QWORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_1780:
	/* 0x1780: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1789:
	/* 0x1789: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1792:
	/* 0x1792: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_179b:
	/* 0x179b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17a4:
	/* 0x17a4: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17a9:
	/* 0x17a9: mov    ebp,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 40ULL);
x86_l_17ae:
	/* 0x17ae: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_17b3:
	/* 0x17b3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17b6:
	/* 0x17b6: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_17b9:
	/* 0x17b9: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_17be:
	/* 0x17be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c0:
	/* 0x17c0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_17c2:
	/* 0x17c2: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_17c7:
	/* 0x17c7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_17c9:
	/* 0x17c9: js     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1517;
	}
x86_l_17cf:
	/* 0x17cf: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_17d2:
	/* 0x17d2: movzx  r15d,BYTE PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 86ULL);
x86_l_17d8:
	/* 0x17d8: mov    BYTE PTR [rsp+0x34],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_17dd:
	/* 0x17dd: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17e2:
	/* 0x17e2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17e7:
	/* 0x17e7: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17ec:
	/* 0x17ec: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f1:
	/* 0x17f1: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_17f6:
	/* 0x17f6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17fb:
	/* 0x17fb: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1800:
	/* 0x1800: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1805:
	/* 0x1805: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_180a:
	/* 0x180a: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_180e:
	/* 0x180e: ja     1f1a <snat_v6_nat+0xa78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7962ULL;
	}
x86_l_1814:
	/* 0x1814: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1819:
	/* 0x1819: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1823:
	/* 0x1823: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1827:
	/* 0x1827: jae    1d71 <snat_v6_nat+0x8cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7537ULL;
	}
x86_l_182d:
	/* 0x182d: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1835:
	/* 0x1835: lea    esi,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1838:
	/* 0x1838: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183d:
	/* 0x183d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1842:
	/* 0x1842: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1845:
	/* 0x1845: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_184a:
	/* 0x184a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184c:
	/* 0x184c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_184e:
	/* 0x184e: js     2046 <snat_v6_nat+0xba4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8262ULL;
	}
x86_l_1854:
	/* 0x1854: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1859:
	/* 0x1859: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_185c:
	/* 0x185c: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_1860:
	/* 0x1860: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1865:
	/* 0x1865: jle    187b <snat_v6_nat+0x3d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_187b;
	}
x86_l_1867:
	/* 0x1867: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_186b:
	/* 0x186b: je     1d80 <snat_v6_nat+0x8de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7552ULL;
	}
x86_l_1871:
	/* 0x1871: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_1875:
	/* 0x1875: jne    1d88 <snat_v6_nat+0x8e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7560ULL;
	}
x86_l_187b:
	/* 0x187b: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1880:
	/* 0x1880: lea    r14d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_1888:
	/* 0x1888: jmp    1d95 <snat_v6_nat+0x8f3> */
	return 7573ULL;
x86_l_188d:
	/* 0x188d: mov    WORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1895:
	/* 0x1895: movzx  eax,WORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 188ULL);
x86_l_189d:
	/* 0x189d: mov    WORD PTR [r12+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_18a3:
	/* 0x18a3: mov    DWORD PTR [r12+0x38],0xffff0000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244813070336ULL);
x86_l_18ac:
	/* 0x18ac: mov    DWORD PTR [rsp+0x4c],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514500ULL);
x86_l_18b4:
	/* 0x18b4: movzx  r14d,BYTE PTR [r12+0x3d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 61ULL);
x86_l_18ba:
	/* 0x18ba: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_18c1:
	/* 0x18c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c6:
	/* 0x18c6: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_18c9:
	/* 0x18c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cb:
	/* 0x18cb: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_18ce:
	/* 0x18ce: mov    QWORD PTR [rsp+0x88],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18d6:
	/* 0x18d6: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_18d9:
	/* 0x18d9: je     2564 <snat_v6_nat+0x10c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9572ULL;
	}
x86_l_18df:
	/* 0x18df: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e4:
	/* 0x18e4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18e9:
	/* 0x18e9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18eb:
	/* 0x18eb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18ed:
	/* 0x18ed: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_18f0:
	/* 0x18f0: mov    rax,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_18f7:
	/* 0x18f7: imul   r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_18fb:
	/* 0x18fb: cmp    r14,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_18ff:
	/* 0x18ff: jbe    1905 <snat_v6_nat+0x463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1905;
	}
x86_l_1901:
	/* 0x1901: mov    r14,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1905:
	/* 0x1905: mov    rbp,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_190c:
	/* 0x190c: movzx  eax,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1912:
	/* 0x1912: mov    WORD PTR [rbp+r14*1+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R14, 0), 36ULL);
x86_l_1918:
	/* 0x1918: mov    ecx,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_191d:
	/* 0x191d: mov    DWORD PTR [rbp+r14*1+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 32ULL);
x86_l_1922:
	/* 0x1922: mov    rcx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1927:
	/* 0x1927: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_192c:
	/* 0x192c: mov    rsi,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1930:
	/* 0x1930: mov    rdi,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1935:
	/* 0x1935: mov    QWORD PTR [rbp+r14*1+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 24ULL);
x86_l_193a:
	/* 0x193a: mov    QWORD PTR [rbp+r14*1+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 16ULL);
x86_l_193f:
	/* 0x193f: mov    QWORD PTR [rbp+r14*1+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 8ULL);
x86_l_1944:
	/* 0x1944: mov    QWORD PTR [rbp+r14*1+0x0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1949:
	/* 0x1949: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_194c:
	/* 0x194c: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1953:
	/* 0x1953: cmp    ax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 6ULL);
x86_l_1957:
	/* 0x1957: jne    1962 <snat_v6_nat+0x4c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1962;
	}
x86_l_1959:
	/* 0x1959: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_1960:
	/* 0x1960: jmp    1969 <snat_v6_nat+0x4c7> */
	goto x86_l_1969;
x86_l_1962:
	/* 0x1962: mov    rdi,QWORD PTR [rip+0x6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1969:
	/* 0x1969: mov    BYTE PTR [rbp+r14*1+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 158913789952ULL);
x86_l_196f:
	/* 0x196f: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_197a:
	/* 0x197a: mov    rax,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1981:
	/* 0x1981: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1984:
	/* 0x1984: bt     QWORD PTR [rsp+0xa0],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 687194767400ULL);
x86_l_198e:
	/* 0x198e: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1996:
	/* 0x1996: jae    1a20 <snat_v6_nat+0x57e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a20;
	}
x86_l_199c:
	/* 0x199c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_199e:
	/* 0x199e: je     1a20 <snat_v6_nat+0x57e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a20;
	}
x86_l_19a4:
	/* 0x19a4: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a7:
	/* 0x19a7: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_19b0:
	/* 0x19b0: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_19b9:
	/* 0x19b9: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_19c3:
	/* 0x19c3: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19c8:
	/* 0x19c8: mov    rdi,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_19cf:
	/* 0x19cf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19d4:
	/* 0x19d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19d9:
	/* 0x19d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19db:
	/* 0x19db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19de:
	/* 0x19de: je     19e9 <snat_v6_nat+0x547> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_19e0:
	/* 0x19e0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_19e3:
	/* 0x19e3: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19e7:
	/* 0x19e7: jmp    1a11 <snat_v6_nat+0x56f> */
	goto x86_l_1a11;
x86_l_19e9:
	/* 0x19e9: mov    QWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_19f2:
	/* 0x19f2: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_19f7:
	/* 0x19f7: mov    rdi,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_19fe:
	/* 0x19fe: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a03:
	/* 0x1a03: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a08:
	/* 0x1a08: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a0d:
	/* 0x1a0d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0f:
	/* 0x1a0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a11:
	/* 0x1a11: mov    r15,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1a18:
	/* 0x1a18: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a20:
	/* 0x1a20: bt     QWORD PTR [rsp+0xa0],0x29 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 687194767401ULL);
x86_l_1a2a:
	/* 0x1a2a: jb     1aa2 <snat_v6_nat+0x600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1aa2;
	}
x86_l_1a2c:
	/* 0x1a2c: cmp    WORD PTR [rsp+0x98],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 652835028998ULL);
x86_l_1a35:
	/* 0x1a35: jne    1aa2 <snat_v6_nat+0x600> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1aa2;
	}
x86_l_1a37:
	/* 0x1a37: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a3f:
	/* 0x1a3f: lea    esi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a42:
	/* 0x1a42: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1a4f:
	/* 0x1a4f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a52:
	/* 0x1a52: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a57:
	/* 0x1a57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a59:
	/* 0x1a59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a5b:
	/* 0x1a5b: js     1a98 <snat_v6_nat+0x5f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a98;
	}
x86_l_1a5d:
	/* 0x1a5d: mov    ecx,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1a64:
	/* 0x1a64: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1a66:
	/* 0x1a66: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1a6b:
	/* 0x1a6b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6d:
	/* 0x1a6d: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1a72:
	/* 0x1a72: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1a75:
	/* 0x1a75: mov    DWORD PTR [rsp+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a79:
	/* 0x1a79: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_1a7f:
	/* 0x1a7f: jne    2298 <snat_v6_nat+0xdf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8856ULL;
	}
x86_l_1a85:
	/* 0x1a85: mov    dl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_8);
x86_l_1a87:
	/* 0x1a87: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a8f:
	/* 0x1a8f: mov    DWORD PTR [rsp+0xb0],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a96:
	/* 0x1a96: jmp    1ab8 <snat_v6_nat+0x616> */
	goto x86_l_1ab8;
x86_l_1a98:
	/* 0x1a98: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_1a9d:
	/* 0x1a9d: jmp    1517 <snat_v6_nat+0x75> */
	goto x86_l_1517;
x86_l_1aa2:
	/* 0x1aa2: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1aad:
	/* 0x1aad: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ab8:
	/* 0x1ab8: add    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1abb:
	/* 0x1abb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1ac3:
	/* 0x1ac3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac5:
	/* 0x1ac5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac8:
	/* 0x1ac8: je     23c7 <snat_v6_nat+0xf25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9159ULL;
	}
x86_l_1ace:
	/* 0x1ace: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1ad1:
	/* 0x1ad1: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1ad6:
	/* 0x1ad6: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
	return 6872ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6881ULL: goto x86_l_1ae1;
	case 6888ULL: goto x86_l_1ae8;
	case 6891ULL: goto x86_l_1aeb;
	case 6893ULL: goto x86_l_1aed;
	case 6900ULL: goto x86_l_1af4;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6910ULL: goto x86_l_1afe;
	case 6916ULL: goto x86_l_1b04;
	case 6925ULL: goto x86_l_1b0d;
	case 6927ULL: goto x86_l_1b0f;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6939ULL: goto x86_l_1b1b;
	case 6941ULL: goto x86_l_1b1d;
	case 6945ULL: goto x86_l_1b21;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6958ULL: goto x86_l_1b2e;
	case 6962ULL: goto x86_l_1b32;
	case 6965ULL: goto x86_l_1b35;
	case 6967ULL: goto x86_l_1b37;
	case 6974ULL: goto x86_l_1b3e;
	case 6978ULL: goto x86_l_1b42;
	case 6982ULL: goto x86_l_1b46;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 6999ULL: goto x86_l_1b57;
	case 7002ULL: goto x86_l_1b5a;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7013ULL: goto x86_l_1b65;
	case 7017ULL: goto x86_l_1b69;
	case 7019ULL: goto x86_l_1b6b;
	case 7024ULL: goto x86_l_1b70;
	case 7026ULL: goto x86_l_1b72;
	case 7028ULL: goto x86_l_1b74;
	case 7032ULL: goto x86_l_1b78;
	case 7042ULL: goto x86_l_1b82;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7065ULL: goto x86_l_1b99;
	case 7069ULL: goto x86_l_1b9d;
	case 7073ULL: goto x86_l_1ba1;
	case 7076ULL: goto x86_l_1ba4;
	case 7080ULL: goto x86_l_1ba8;
	case 7087ULL: goto x86_l_1baf;
	case 7090ULL: goto x86_l_1bb2;
	case 7092ULL: goto x86_l_1bb4;
	case 7099ULL: goto x86_l_1bbb;
	case 7101ULL: goto x86_l_1bbd;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7109ULL: goto x86_l_1bc5;
	case 7114ULL: goto x86_l_1bca;
	case 7116ULL: goto x86_l_1bcc;
	case 7119ULL: goto x86_l_1bcf;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7125ULL: goto x86_l_1bd5;
	case 7128ULL: goto x86_l_1bd8;
	case 7130ULL: goto x86_l_1bda;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7144ULL: goto x86_l_1be8;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7158ULL: goto x86_l_1bf6;
	case 7165ULL: goto x86_l_1bfd;
	case 7168ULL: goto x86_l_1c00;
	case 7175ULL: goto x86_l_1c07;
	case 7177ULL: goto x86_l_1c09;
	case 7182ULL: goto x86_l_1c0e;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7194ULL: goto x86_l_1c1a;
	case 7197ULL: goto x86_l_1c1d;
	case 7203ULL: goto x86_l_1c23;
	case 7207ULL: goto x86_l_1c27;
	case 7209ULL: goto x86_l_1c29;
	case 7215ULL: goto x86_l_1c2f;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7229ULL: goto x86_l_1c3d;
	case 7233ULL: goto x86_l_1c41;
	case 7240ULL: goto x86_l_1c48;
	case 7243ULL: goto x86_l_1c4b;
	case 7249ULL: goto x86_l_1c51;
	case 7256ULL: goto x86_l_1c58;
	case 7260ULL: goto x86_l_1c5c;
	case 7264ULL: goto x86_l_1c60;
	case 7269ULL: goto x86_l_1c65;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7281ULL: goto x86_l_1c71;
	case 7285ULL: goto x86_l_1c75;
	case 7289ULL: goto x86_l_1c79;
	case 7293ULL: goto x86_l_1c7d;
	case 7300ULL: goto x86_l_1c84;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7310ULL: goto x86_l_1c8e;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7320ULL: goto x86_l_1c98;
	case 7327ULL: goto x86_l_1c9f;
	case 7331ULL: goto x86_l_1ca3;
	case 7333ULL: goto x86_l_1ca5;
	case 7340ULL: goto x86_l_1cac;
	case 7342ULL: goto x86_l_1cae;
	case 7344ULL: goto x86_l_1cb0;
	case 7348ULL: goto x86_l_1cb4;
	case 7352ULL: goto x86_l_1cb8;
	case 7354ULL: goto x86_l_1cba;
	case 7360ULL: goto x86_l_1cc0;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7372ULL: goto x86_l_1ccc;
	case 7374ULL: goto x86_l_1cce;
	case 7379ULL: goto x86_l_1cd3;
	case 7381ULL: goto x86_l_1cd5;
	case 7383ULL: goto x86_l_1cd7;
	case 7387ULL: goto x86_l_1cdb;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7396ULL: goto x86_l_1ce4;
	case 7398ULL: goto x86_l_1ce6;
	case 7402ULL: goto x86_l_1cea;
	case 7412ULL: goto x86_l_1cf4;
	case 7415ULL: goto x86_l_1cf7;
	case 7420ULL: goto x86_l_1cfc;
	case 7424ULL: goto x86_l_1d00;
	case 7427ULL: goto x86_l_1d03;
	case 7431ULL: goto x86_l_1d07;
	case 7435ULL: goto x86_l_1d0b;
	case 7438ULL: goto x86_l_1d0e;
	case 7442ULL: goto x86_l_1d12;
	case 7446ULL: goto x86_l_1d16;
	case 7450ULL: goto x86_l_1d1a;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7463ULL: goto x86_l_1d27;
	case 7465ULL: goto x86_l_1d29;
	case 7468ULL: goto x86_l_1d2c;
	case 7471ULL: goto x86_l_1d2f;
	case 7473ULL: goto x86_l_1d31;
	case 7478ULL: goto x86_l_1d36;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7491ULL: goto x86_l_1d43;
	case 7493ULL: goto x86_l_1d45;
	case 7497ULL: goto x86_l_1d49;
	case 7499ULL: goto x86_l_1d4b;
	case 7506ULL: goto x86_l_1d52;
	case 7508ULL: goto x86_l_1d54;
	case 7512ULL: goto x86_l_1d58;
	case 7514ULL: goto x86_l_1d5a;
	case 7518ULL: goto x86_l_1d5e;
	case 7521ULL: goto x86_l_1d61;
	case 7524ULL: goto x86_l_1d64;
	case 7526ULL: goto x86_l_1d66;
	case 7532ULL: goto x86_l_1d6c;
	case 7537ULL: goto x86_l_1d71;
	case 7541ULL: goto x86_l_1d75;
	case 7547ULL: goto x86_l_1d7b;
	case 7552ULL: goto x86_l_1d80;
	case 7558ULL: goto x86_l_1d86;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7573ULL: goto x86_l_1d95;
	case 7577ULL: goto x86_l_1d99;
	case 7580ULL: goto x86_l_1d9c;
	case 7586ULL: goto x86_l_1da2;
	case 7588ULL: goto x86_l_1da4;
	case 7598ULL: goto x86_l_1dae;
	case 7602ULL: goto x86_l_1db2;
	case 7604ULL: goto x86_l_1db4;
	case 7609ULL: goto x86_l_1db9;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7623ULL: goto x86_l_1dc7;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7633ULL: goto x86_l_1dd1;
	case 7635ULL: goto x86_l_1dd3;
	case 7641ULL: goto x86_l_1dd9;
	case 7647ULL: goto x86_l_1ddf;
	case 7651ULL: goto x86_l_1de3;
	case 7654ULL: goto x86_l_1de6;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7666ULL: goto x86_l_1df2;
	case 7671ULL: goto x86_l_1df7;
	case 7678ULL: goto x86_l_1dfe;
	case 7680ULL: goto x86_l_1e00;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7695ULL: goto x86_l_1e0f;
	case 7697ULL: goto x86_l_1e11;
	case 7700ULL: goto x86_l_1e14;
	case 7704ULL: goto x86_l_1e18;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7730ULL: goto x86_l_1e32;
	case 7732ULL: goto x86_l_1e34;
	case 7735ULL: goto x86_l_1e37;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7753ULL: goto x86_l_1e49;
	case 7757ULL: goto x86_l_1e4d;
	case 7763ULL: goto x86_l_1e53;
	case 7767ULL: goto x86_l_1e57;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7789ULL: goto x86_l_1e6d;
	case 7791ULL: goto x86_l_1e6f;
	case 7793ULL: goto x86_l_1e71;
	case 7799ULL: goto x86_l_1e77;
	case 7805ULL: goto x86_l_1e7d;
	case 7809ULL: goto x86_l_1e81;
	case 7813ULL: goto x86_l_1e85;
	case 7816ULL: goto x86_l_1e88;
	case 7818ULL: goto x86_l_1e8a;
	case 7821ULL: goto x86_l_1e8d;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7828ULL: goto x86_l_1e94;
	case 7833ULL: goto x86_l_1e99;
	case 7840ULL: goto x86_l_1ea0;
	case 7842ULL: goto x86_l_1ea2;
	case 7847ULL: goto x86_l_1ea7;
	case 7854ULL: goto x86_l_1eae;
	case 7856ULL: goto x86_l_1eb0;
	case 7859ULL: goto x86_l_1eb3;
	case 7862ULL: goto x86_l_1eb6;
	case 7867ULL: goto x86_l_1ebb;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7883ULL: goto x86_l_1ecb;
	case 7893ULL: goto x86_l_1ed5;
	case 7897ULL: goto x86_l_1ed9;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7915ULL: goto x86_l_1eeb;
	case 7917ULL: goto x86_l_1eed;
	case 7922ULL: goto x86_l_1ef2;
	case 7924ULL: goto x86_l_1ef4;
	case 7926ULL: goto x86_l_1ef6;
	case 7931ULL: goto x86_l_1efb;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7970ULL: goto x86_l_1f22;
	case 7974ULL: goto x86_l_1f26;
	case 7976ULL: goto x86_l_1f28;
	case 7980ULL: goto x86_l_1f2c;
	case 7983ULL: goto x86_l_1f2f;
	case 7989ULL: goto x86_l_1f35;
	case 7992ULL: goto x86_l_1f38;
	case 7998ULL: goto x86_l_1f3e;
	case 8003ULL: goto x86_l_1f43;
	case 8008ULL: goto x86_l_1f48;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8018ULL: goto x86_l_1f52;
	case 8023ULL: goto x86_l_1f57;
	case 8025ULL: goto x86_l_1f59;
	case 8027ULL: goto x86_l_1f5b;
	case 8032ULL: goto x86_l_1f60;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8045ULL: goto x86_l_1f6d;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8062ULL: goto x86_l_1f7e;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8073ULL: goto x86_l_1f89;
	case 8080ULL: goto x86_l_1f90;
	case 8086ULL: goto x86_l_1f96;
	case 8091ULL: goto x86_l_1f9b;
	case 8095ULL: goto x86_l_1f9f;
	case 8100ULL: goto x86_l_1fa4;
	case 8105ULL: goto x86_l_1fa9;
	case 8109ULL: goto x86_l_1fad;
	case 8113ULL: goto x86_l_1fb1;
	case 8118ULL: goto x86_l_1fb6;
	case 8124ULL: goto x86_l_1fbc;
	case 8127ULL: goto x86_l_1fbf;
	case 8131ULL: goto x86_l_1fc3;
	case 8137ULL: goto x86_l_1fc9;
	case 8142ULL: goto x86_l_1fce;
	case 8146ULL: goto x86_l_1fd2;
	case 8151ULL: goto x86_l_1fd7;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8184ULL: goto x86_l_1ff8;
	case 8186ULL: goto x86_l_1ffa;
	case 8188ULL: goto x86_l_1ffc;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8200ULL: goto x86_l_2008;
	case 8205ULL: goto x86_l_200d;
	case 8211ULL: goto x86_l_2013;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8224ULL: goto x86_l_2020;
	case 8229ULL: goto x86_l_2025;
	case 8232ULL: goto x86_l_2028;
	case 8237ULL: goto x86_l_202d;
	case 8239ULL: goto x86_l_202f;
	case 8244ULL: goto x86_l_2034;
	case 8246ULL: goto x86_l_2036;
	case 8251ULL: goto x86_l_203b;
	case 8257ULL: goto x86_l_2041;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8272ULL: goto x86_l_2050;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8285ULL: goto x86_l_205d;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8303ULL: goto x86_l_206f;
	case 8314ULL: goto x86_l_207a;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8335ULL: goto x86_l_208f;
	case 8337ULL: goto x86_l_2091;
	case 8344ULL: goto x86_l_2098;
	case 8352ULL: goto x86_l_20a0;
	case 8355ULL: goto x86_l_20a3;
	case 8360ULL: goto x86_l_20a8;
	case 8363ULL: goto x86_l_20ab;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8374ULL: goto x86_l_20b6;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8384ULL: goto x86_l_20c0;
	case 8388ULL: goto x86_l_20c4;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8408ULL: goto x86_l_20d8;
	case 8410ULL: goto x86_l_20da;
	case 8415ULL: goto x86_l_20df;
	case 8417ULL: goto x86_l_20e1;
	case 8422ULL: goto x86_l_20e6;
	case 8427ULL: goto x86_l_20eb;
	case 8432ULL: goto x86_l_20f0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ad8:
	/* 0x1ad8: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1adb:
	/* 0x1adb: je     1bf6 <snat_v6_nat+0x754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bf6;
	}
x86_l_1ae1:
	/* 0x1ae1: mov    rdx,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1ae8:
	/* 0x1ae8: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aeb:
	/* 0x1aeb: je     1afe <snat_v6_nat+0x65c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1afe;
	}
x86_l_1aed:
	/* 0x1aed: mov    rcx,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1af4:
	/* 0x1af4: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1af8:
	/* 0x1af8: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1afc:
	/* 0x1afc: jmp    1b04 <snat_v6_nat+0x662> */
	goto x86_l_1b04;
x86_l_1afe:
	/* 0x1afe: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1b04:
	/* 0x1b04: cmp    WORD PTR [rsp+0x98],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 652835028998ULL);
x86_l_1b0d:
	/* 0x1b0d: jne    1b46 <snat_v6_nat+0x6a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b46;
	}
x86_l_1b0f:
	/* 0x1b0f: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b13:
	/* 0x1b13: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b15:
	/* 0x1b15: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1b18:
	/* 0x1b18: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1b1b:
	/* 0x1b1b: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b1d:
	/* 0x1b1d: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b21:
	/* 0x1b21: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_1b23:
	/* 0x1b23: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1b28:
	/* 0x1b28: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_1b2e:
	/* 0x1b2e: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1b32:
	/* 0x1b32: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b35:
	/* 0x1b35: je     1b46 <snat_v6_nat+0x6a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b46;
	}
x86_l_1b37:
	/* 0x1b37: mov    rax,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1b3e:
	/* 0x1b3e: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1b42:
	/* 0x1b42: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b46:
	/* 0x1b46: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b4e:
	/* 0x1b4e: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b53:
	/* 0x1b53: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b57:
	/* 0x1b57: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5a:
	/* 0x1b5a: je     1b6b <snat_v6_nat+0x6c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b6b;
	}
x86_l_1b5c:
	/* 0x1b5c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1b61:
	/* 0x1b61: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b63:
	/* 0x1b63: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b65:
	/* 0x1b65: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1b69:
	/* 0x1b69: jmp    1b8e <snat_v6_nat+0x6ec> */
	goto x86_l_1b8e;
x86_l_1b6b:
	/* 0x1b6b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b70:
	/* 0x1b70: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b72:
	/* 0x1b72: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b74:
	/* 0x1b74: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1b78:
	/* 0x1b78: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1b82:
	/* 0x1b82: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1b85:
	/* 0x1b85: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b8a:
	/* 0x1b8a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1b8e:
	/* 0x1b8e: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b91:
	/* 0x1b91: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1b99:
	/* 0x1b99: mov    DWORD PTR [rdi+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b9d:
	/* 0x1b9d: movzx  ecx,BYTE PTR [rdi+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1ba1:
	/* 0x1ba1: mov    edx,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ba4:
	/* 0x1ba4: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    rsi,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1baf:
	/* 0x1baf: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb2:
	/* 0x1bb2: je     1bc5 <snat_v6_nat+0x723> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc5;
	}
x86_l_1bb4:
	/* 0x1bb4: mov    rsi,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1bbb:
	/* 0x1bbb: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bbd:
	/* 0x1bbd: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1bc0:
	/* 0x1bc0: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1bc3:
	/* 0x1bc3: jmp    1bca <snat_v6_nat+0x728> */
	goto x86_l_1bca;
x86_l_1bc5:
	/* 0x1bc5: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1bca:
	/* 0x1bca: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1bcc:
	/* 0x1bcc: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1bcf:
	/* 0x1bcf: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1bd1:
	/* 0x1bd1: jb     1bda <snat_v6_nat+0x738> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bda;
	}
x86_l_1bd3:
	/* 0x1bd3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd5:
	/* 0x1bd5: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_1bd8:
	/* 0x1bd8: je     1bea <snat_v6_nat+0x748> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bea;
	}
x86_l_1bda:
	/* 0x1bda: mov    BYTE PTR [rdi+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1bde:
	/* 0x1bde: mov    DWORD PTR [rdi+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1be1:
	/* 0x1be1: mov    rax,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1be8:
	/* 0x1be8: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bea:
	/* 0x1bea: mov    DWORD PTR [r12+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1bef:
	/* 0x1bef: mov    r15,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1bf6:
	/* 0x1bf6: mov    rax,QWORD PTR [rip+0x6b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1bfd:
	/* 0x1bfd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c00:
	/* 0x1c00: mov    ecx,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c07:
	/* 0x1c07: je     1c15 <snat_v6_nat+0x773> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c15;
	}
x86_l_1c09:
	/* 0x1c09: inc QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1c0e:
	/* 0x1c0e: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c10:
	/* 0x1c10: add QWORD PTR [rdi+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RDI, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1c15:
	/* 0x1c15: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c18:
	/* 0x1c18: je     1c65 <snat_v6_nat+0x7c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c65;
	}
x86_l_1c1a:
	/* 0x1c1a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c1d:
	/* 0x1c1d: jne    1d66 <snat_v6_nat+0x8c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d66;
	}
x86_l_1c23:
	/* 0x1c23: movzx  eax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1c27:
	/* 0x1c27: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1c29:
	/* 0x1c29: je     1d66 <snat_v6_nat+0x8c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d66;
	}
x86_l_1c2f:
	/* 0x1c2f: mov    WORD PTR [rdi+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1c35:
	/* 0x1c35: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1c3d:
	/* 0x1c3d: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c41:
	/* 0x1c41: mov    rcx,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1c48:
	/* 0x1c48: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c4b:
	/* 0x1c4b: je     22cf <snat_v6_nat+0xe2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8911ULL;
	}
x86_l_1c51:
	/* 0x1c51: mov    rcx,QWORD PTR [rip+0x6b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c58:
	/* 0x1c58: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1c5c:
	/* 0x1c5c: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c60:
	/* 0x1c60: jmp    22d5 <snat_v6_nat+0xe33> */
	return 8917ULL;
x86_l_1c65:
	/* 0x1c65: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c69:
	/* 0x1c69: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_1c6e:
	/* 0x1c6e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c71:
	/* 0x1c71: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_1c75:
	/* 0x1c75: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_1c79:
	/* 0x1c79: or     WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RDI, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1c7d:
	/* 0x1c7d: mov    rax,QWORD PTR [rip+0x6b3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1c84:
	/* 0x1c84: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c86:
	/* 0x1c86: mov    DWORD PTR [r12+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    eax,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c8e:
	/* 0x1c8e: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1c90:
	/* 0x1c90: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1c92:
	/* 0x1c92: jne    1d66 <snat_v6_nat+0x8c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d66;
	}
x86_l_1c98:
	/* 0x1c98: mov    r14,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1c9f:
	/* 0x1c9f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca3:
	/* 0x1ca3: je     1cba <snat_v6_nat+0x818> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cba;
	}
x86_l_1ca5:
	/* 0x1ca5: mov    rax,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1cac:
	/* 0x1cac: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cae:
	/* 0x1cae: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cb0:
	/* 0x1cb0: lea    r15d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1cb8:
	/* 0x1cb8: jmp    1cc0 <snat_v6_nat+0x81e> */
	goto x86_l_1cc0;
x86_l_1cba:
	/* 0x1cba: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_1cc3:
	/* 0x1cc3: shr    DWORD PTR [rsp+0x4],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 17179869192ULL);
x86_l_1cc8:
	/* 0x1cc8: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ccc:
	/* 0x1ccc: je     1cdd <snat_v6_nat+0x83b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cdd;
	}
x86_l_1cce:
	/* 0x1cce: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1cd3:
	/* 0x1cd3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cd5:
	/* 0x1cd5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cd7:
	/* 0x1cd7: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1cdb:
	/* 0x1cdb: jmp    1d00 <snat_v6_nat+0x85e> */
	goto x86_l_1d00;
x86_l_1cdd:
	/* 0x1cdd: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1ce2:
	/* 0x1ce2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce4:
	/* 0x1ce4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ce6:
	/* 0x1ce6: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1cea:
	/* 0x1cea: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1cf4:
	/* 0x1cf4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1cf7:
	/* 0x1cf7: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1cfc:
	/* 0x1cfc: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1d00:
	/* 0x1d00: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d03:
	/* 0x1d03: mov    DWORD PTR [rbp+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d07:
	/* 0x1d07: movzx  ecx,BYTE PTR [rbp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    edx,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d12:
	/* 0x1d12: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1d16:
	/* 0x1d16: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d1a:
	/* 0x1d1a: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1e:
	/* 0x1d1e: je     1d31 <snat_v6_nat+0x88f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d31;
	}
x86_l_1d20:
	/* 0x1d20: mov    rsi,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1d27:
	/* 0x1d27: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d29:
	/* 0x1d29: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1d2c:
	/* 0x1d2c: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d2f:
	/* 0x1d2f: jmp    1d36 <snat_v6_nat+0x894> */
	goto x86_l_1d36;
x86_l_1d31:
	/* 0x1d31: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1d36:
	/* 0x1d36: mov    r15,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1d3d:
	/* 0x1d3d: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d3f:
	/* 0x1d3f: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d43:
	/* 0x1d43: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d45:
	/* 0x1d45: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d49:
	/* 0x1d49: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1d4b:
	/* 0x1d4b: mov    rdx,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1d52:
	/* 0x1d52: jb     1d5a <snat_v6_nat+0x8b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d5a;
	}
x86_l_1d54:
	/* 0x1d54: cmp    cl,BYTE PTR [rsp+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_1d58:
	/* 0x1d58: je     1d66 <snat_v6_nat+0x8c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d66;
	}
x86_l_1d5a:
	/* 0x1d5a: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d5e:
	/* 0x1d5e: mov    BYTE PTR [rbp+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1d61:
	/* 0x1d61: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d64:
	/* 0x1d64: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d66:
	/* 0x1d66: mov    BYTE PTR [r12+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_1d6c:
	/* 0x1d6c: jmp    255f <snat_v6_nat+0x10bd> */
	return 9567ULL;
x86_l_1d71:
	/* 0x1d71: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_1d75:
	/* 0x1d75: je     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5399ULL;
	}
x86_l_1d7b:
	/* 0x1d7b: jmp    1f1a <snat_v6_nat+0xa78> */
	goto x86_l_1f1a;
x86_l_1d80:
	/* 0x1d80: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1d86:
	/* 0x1d86: jmp    1d95 <snat_v6_nat+0x8f3> */
	goto x86_l_1d95;
x86_l_1d88:
	/* 0x1d88: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1d8d:
	/* 0x1d8d: lea    r14d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_1d95:
	/* 0x1d95: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1d99:
	/* 0x1d99: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1d9c:
	/* 0x1d9c: ja     1eb0 <snat_v6_nat+0xa0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1eb0;
	}
x86_l_1da2:
	/* 0x1da2: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1da4:
	/* 0x1da4: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1dae:
	/* 0x1dae: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1db2:
	/* 0x1db2: jae    1e11 <snat_v6_nat+0x96f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e11;
	}
x86_l_1db4:
	/* 0x1db4: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1db9:
	/* 0x1db9: lea    esi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1dbd:
	/* 0x1dbd: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dc2:
	/* 0x1dc2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1dc7:
	/* 0x1dc7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dca:
	/* 0x1dca: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1dcf:
	/* 0x1dcf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd1:
	/* 0x1dd1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dd3:
	/* 0x1dd3: js     2046 <snat_v6_nat+0xba4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2046;
	}
x86_l_1dd9:
	/* 0x1dd9: movzx  r15d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1ddf:
	/* 0x1ddf: movzx  edx,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1de3:
	/* 0x1de3: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1de6:
	/* 0x1de6: jle    1e00 <snat_v6_nat+0x95e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1e00;
	}
x86_l_1de8:
	/* 0x1de8: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_1deb:
	/* 0x1deb: je     1e25 <snat_v6_nat+0x983> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e25;
	}
x86_l_1ded:
	/* 0x1ded: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1df0:
	/* 0x1df0: jne    1e00 <snat_v6_nat+0x95e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e00;
	}
x86_l_1df2:
	/* 0x1df2: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1df7:
	/* 0x1df7: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1dfe:
	/* 0x1dfe: jmp    1e2a <snat_v6_nat+0x988> */
	goto x86_l_1e2a;
x86_l_1e00:
	/* 0x1e00: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1e03:
	/* 0x1e03: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1e08:
	/* 0x1e08: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1e0f:
	/* 0x1e0f: jmp    1e2d <snat_v6_nat+0x98b> */
	goto x86_l_1e2d;
x86_l_1e11:
	/* 0x1e11: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1e14:
	/* 0x1e14: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_1e18:
	/* 0x1e18: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1e1b:
	/* 0x1e1b: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e20:
	/* 0x1e20: jmp    1f0f <snat_v6_nat+0xa6d> */
	goto x86_l_1f0f;
x86_l_1e25:
	/* 0x1e25: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1e2a:
	/* 0x1e2a: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1e2d:
	/* 0x1e2d: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e32:
	/* 0x1e32: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e34:
	/* 0x1e34: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_1e37:
	/* 0x1e37: ja     1f1a <snat_v6_nat+0xa78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f1a;
	}
x86_l_1e3d:
	/* 0x1e3d: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1e3f:
	/* 0x1e3f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1e49:
	/* 0x1e49: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1e4d:
	/* 0x1e4d: jae    1f0b <snat_v6_nat+0xa69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f0b;
	}
x86_l_1e53:
	/* 0x1e53: mov    DWORD PTR [rsp+0x40],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e57:
	/* 0x1e57: lea    esi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1e5b:
	/* 0x1e5b: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e60:
	/* 0x1e60: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1e65:
	/* 0x1e65: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e68:
	/* 0x1e68: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1e6d:
	/* 0x1e6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6f:
	/* 0x1e6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e71:
	/* 0x1e71: js     2046 <snat_v6_nat+0xba4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2046;
	}
x86_l_1e77:
	/* 0x1e77: movzx  r15d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1e7d:
	/* 0x1e7d: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e81:
	/* 0x1e81: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e85:
	/* 0x1e85: cmp    ecx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 43ULL);
x86_l_1e88:
	/* 0x1e88: jle    1ea2 <snat_v6_nat+0xa00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ea2;
	}
x86_l_1e8a:
	/* 0x1e8a: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_1e8d:
	/* 0x1e8d: je     1ebd <snat_v6_nat+0xa1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ebd;
	}
x86_l_1e8f:
	/* 0x1e8f: cmp    ecx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 51ULL);
x86_l_1e92:
	/* 0x1e92: jne    1ea2 <snat_v6_nat+0xa00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ea2;
	}
x86_l_1e94:
	/* 0x1e94: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1e99:
	/* 0x1e99: lea    ecx,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_1ea0:
	/* 0x1ea0: jmp    1ec2 <snat_v6_nat+0xa20> */
	goto x86_l_1ec2;
x86_l_1ea2:
	/* 0x1ea2: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1ea7:
	/* 0x1ea7: lea    ecx,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_1eae:
	/* 0x1eae: jmp    1ec2 <snat_v6_nat+0xa20> */
	goto x86_l_1ec2;
x86_l_1eb0:
	/* 0x1eb0: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1eb3:
	/* 0x1eb3: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1eb6:
	/* 0x1eb6: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ebb:
	/* 0x1ebb: jmp    1f1a <snat_v6_nat+0xa78> */
	goto x86_l_1f1a;
x86_l_1ebd:
	/* 0x1ebd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ec2:
	/* 0x1ec2: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ec4:
	/* 0x1ec4: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1ec7:
	/* 0x1ec7: ja     1f1a <snat_v6_nat+0xa78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f1a;
	}
x86_l_1ec9:
	/* 0x1ec9: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ecb:
	/* 0x1ecb: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1ed5:
	/* 0x1ed5: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ed9:
	/* 0x1ed9: jae    1f0b <snat_v6_nat+0xa69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f0b;
	}
x86_l_1edb:
	/* 0x1edb: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ede:
	/* 0x1ede: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1ee8:
	/* 0x1ee8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1eeb:
	/* 0x1eeb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1eed:
	/* 0x1eed: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ef2:
	/* 0x1ef2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef4:
	/* 0x1ef4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ef6:
	/* 0x1ef6: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1efb:
	/* 0x1efb: js     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5399ULL;
	}
x86_l_1f01:
	/* 0x1f01: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1f06:
	/* 0x1f06: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_1f0b:
	/* 0x1f0b: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_1f0f:
	/* 0x1f0f: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1f14:
	/* 0x1f14: je     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5399ULL;
	}
x86_l_1f1a:
	/* 0x1f1a: mov    BYTE PTR [rsp+0x34],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1f1f:
	/* 0x1f1f: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f22:
	/* 0x1f22: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1f26:
	/* 0x1f26: je     1f3e <snat_v6_nat+0xa9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f3e;
	}
x86_l_1f28:
	/* 0x1f28: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f2c:
	/* 0x1f2c: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1f2f:
	/* 0x1f2f: je     1fe2 <snat_v6_nat+0xb40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fe2;
	}
x86_l_1f35:
	/* 0x1f35: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1f38:
	/* 0x1f38: jne    21ff <snat_v6_nat+0xd5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8703ULL;
	}
x86_l_1f3e:
	/* 0x1f3e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f43:
	/* 0x1f43: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1f48:
	/* 0x1f48: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f4b:
	/* 0x1f4b: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f50:
	/* 0x1f50: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1f52:
	/* 0x1f52: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f57:
	/* 0x1f57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f59:
	/* 0x1f59: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1f5b:
	/* 0x1f5b: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1f60:
	/* 0x1f60: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1f65:
	/* 0x1f65: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1f67:
	/* 0x1f67: js     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5399ULL;
	}
x86_l_1f6d:
	/* 0x1f6d: mov    rdi,QWORD PTR [rip+0x6ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1f74:
	/* 0x1f74: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f79:
	/* 0x1f79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f7e:
	/* 0x1f7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f80:
	/* 0x1f80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f83:
	/* 0x1f83: je     2050 <snat_v6_nat+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2050;
	}
x86_l_1f89:
	/* 0x1f89: mov    DWORD PTR [rsp+0x98],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f90:
	/* 0x1f90: movzx  r15d,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_1f96:
	/* 0x1f96: movzx  edx,WORD PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_1f9b:
	/* 0x1f9b: movzx  esi,WORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1f9f:
	/* 0x1f9f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa4:
	/* 0x1fa4: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fa9:
	/* 0x1fa9: cmp    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1fad:
	/* 0x1fad: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    WORD PTR [rsp+0x4],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fb6:
	/* 0x1fb6: jne    205a <snat_v6_nat+0xbb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_205a;
	}
x86_l_1fbc:
	/* 0x1fbc: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_1fbf:
	/* 0x1fbf: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_1fc3:
	/* 0x1fc3: jne    2061 <snat_v6_nat+0xbbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2061;
	}
x86_l_1fc9:
	/* 0x1fc9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fce:
	/* 0x1fce: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fd2:
	/* 0x1fd2: cmp    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fd7:
	/* 0x1fd7: je     21ea <snat_v6_nat+0xd48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8682ULL;
	}
x86_l_1fdd:
	/* 0x1fdd: jmp    2061 <snat_v6_nat+0xbbf> */
	goto x86_l_2061;
x86_l_1fe2:
	/* 0x1fe2: lea    rdx,[rsp+0x4b] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1fec:
	/* 0x1fec: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fef:
	/* 0x1fef: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1ff1:
	/* 0x1ff1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ff6:
	/* 0x1ff6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff8:
	/* 0x1ff8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ffa:
	/* 0x1ffa: js     2046 <snat_v6_nat+0xba4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2046;
	}
x86_l_1ffc:
	/* 0x1ffc: movzx  eax,BYTE PTR [rsp+0x4b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 75ULL);
x86_l_2001:
	/* 0x2001: cmp    eax,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_2006:
	/* 0x2006: je     2050 <snat_v6_nat+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2050;
	}
x86_l_2008:
	/* 0x2008: cmp    eax,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 129ULL);
x86_l_200d:
	/* 0x200d: jne    20e1 <snat_v6_nat+0xc3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20e1;
	}
x86_l_2013:
	/* 0x2013: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2018:
	/* 0x2018: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_201b:
	/* 0x201b: lea    rdx,[rsp+0x32] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_2020:
	/* 0x2020: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2025:
	/* 0x2025: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2028:
	/* 0x2028: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_202d:
	/* 0x202d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_202f:
	/* 0x202f: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_2034:
	/* 0x2034: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2036:
	/* 0x2036: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_203b:
	/* 0x203b: jns    1f6d <snat_v6_nat+0xacb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1f6d;
	}
x86_l_2041:
	/* 0x2041: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_2046:
	/* 0x2046: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_204b:
	/* 0x204b: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_2050:
	/* 0x2050: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_2055:
	/* 0x2055: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_205a:
	/* 0x205a: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_205d:
	/* 0x205d: sete   bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_E);
x86_l_2061:
	/* 0x2061: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2066:
	/* 0x2066: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_206b:
	/* 0x206b: add    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_206f:
	/* 0x206f: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_207a:
	/* 0x207a: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_207f:
	/* 0x207f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2084:
	/* 0x2084: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2087:
	/* 0x2087: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_208c:
	/* 0x208c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_208f:
	/* 0x208f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2091:
	/* 0x2091: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2098:
	/* 0x2098: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_20a0:
	/* 0x20a0: lea    esi,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20a3:
	/* 0x20a3: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_20a8:
	/* 0x20a8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_20ab:
	/* 0x20ab: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_20ae:
	/* 0x20ae: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_20b3:
	/* 0x20b3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20b6:
	/* 0x20b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b8:
	/* 0x20b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20ba:
	/* 0x20ba: js     36ce <snat_v6_nat+0x222c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14030ULL;
	}
x86_l_20c0:
	/* 0x20c0: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_20c4:
	/* 0x20c4: je     20fd <snat_v6_nat+0xc5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8445ULL;
	}
x86_l_20c6:
	/* 0x20c6: cmp    r15d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 17ULL);
x86_l_20ca:
	/* 0x20ca: je     20eb <snat_v6_nat+0xc49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20eb;
	}
x86_l_20cc:
	/* 0x20cc: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_20cf:
	/* 0x20cf: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_20d4:
	/* 0x20d4: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_20d8:
	/* 0x20d8: jne    2110 <snat_v6_nat+0xc6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8464ULL;
	}
x86_l_20da:
	/* 0x20da: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20df:
	/* 0x20df: jmp    2102 <snat_v6_nat+0xc60> */
	return 8450ULL;
x86_l_20e1:
	/* 0x20e1: mov    eax,0xffffff6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967151ULL);
x86_l_20e6:
	/* 0x20e6: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_20eb:
	/* 0x20eb: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_20f0:
	/* 0x20f0: mov    DWORD PTR [rsp+0x88],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552288ULL);
	return 8443ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8443ULL: goto x86_l_20fb;
	case 8445ULL: goto x86_l_20fd;
	case 8450ULL: goto x86_l_2102;
	case 8461ULL: goto x86_l_210d;
	case 8464ULL: goto x86_l_2110;
	case 8467ULL: goto x86_l_2113;
	case 8473ULL: goto x86_l_2119;
	case 8481ULL: goto x86_l_2121;
	case 8485ULL: goto x86_l_2125;
	case 8491ULL: goto x86_l_212b;
	case 8494ULL: goto x86_l_212e;
	case 8504ULL: goto x86_l_2138;
	case 8508ULL: goto x86_l_213c;
	case 8513ULL: goto x86_l_2141;
	case 8520ULL: goto x86_l_2148;
	case 8526ULL: goto x86_l_214e;
	case 8531ULL: goto x86_l_2153;
	case 8536ULL: goto x86_l_2158;
	case 8540ULL: goto x86_l_215c;
	case 8545ULL: goto x86_l_2161;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8558ULL: goto x86_l_216e;
	case 8561ULL: goto x86_l_2171;
	case 8563ULL: goto x86_l_2173;
	case 8565ULL: goto x86_l_2175;
	case 8571ULL: goto x86_l_217b;
	case 8576ULL: goto x86_l_2180;
	case 8581ULL: goto x86_l_2185;
	case 8589ULL: goto x86_l_218d;
	case 8592ULL: goto x86_l_2190;
	case 8600ULL: goto x86_l_2198;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8612ULL: goto x86_l_21a4;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8620ULL: goto x86_l_21ac;
	case 8626ULL: goto x86_l_21b2;
	case 8634ULL: goto x86_l_21ba;
	case 8637ULL: goto x86_l_21bd;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8651ULL: goto x86_l_21cb;
	case 8655ULL: goto x86_l_21cf;
	case 8660ULL: goto x86_l_21d4;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8672ULL: goto x86_l_21e0;
	case 8674ULL: goto x86_l_21e2;
	case 8676ULL: goto x86_l_21e4;
	case 8682ULL: goto x86_l_21ea;
	case 8690ULL: goto x86_l_21f2;
	case 8693ULL: goto x86_l_21f5;
	case 8698ULL: goto x86_l_21fa;
	case 8703ULL: goto x86_l_21ff;
	case 8708ULL: goto x86_l_2204;
	case 8713ULL: goto x86_l_2209;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8728ULL: goto x86_l_2218;
	case 8730ULL: goto x86_l_221a;
	case 8733ULL: goto x86_l_221d;
	case 8735ULL: goto x86_l_221f;
	case 8737ULL: goto x86_l_2221;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8752ULL: goto x86_l_2230;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8763ULL: goto x86_l_223b;
	case 8765ULL: goto x86_l_223d;
	case 8767ULL: goto x86_l_223f;
	case 8769ULL: goto x86_l_2241;
	case 8775ULL: goto x86_l_2247;
	case 8777ULL: goto x86_l_2249;
	case 8786ULL: goto x86_l_2252;
	case 8795ULL: goto x86_l_225b;
	case 8805ULL: goto x86_l_2265;
	case 8810ULL: goto x86_l_226a;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8827ULL: goto x86_l_227b;
	case 8829ULL: goto x86_l_227d;
	case 8832ULL: goto x86_l_2280;
	case 8834ULL: goto x86_l_2282;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8875ULL: goto x86_l_22ab;
	case 8880ULL: goto x86_l_22b0;
	case 8887ULL: goto x86_l_22b7;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8902ULL: goto x86_l_22c6;
	case 8904ULL: goto x86_l_22c8;
	case 8906ULL: goto x86_l_22ca;
	case 8911ULL: goto x86_l_22cf;
	case 8917ULL: goto x86_l_22d5;
	case 8926ULL: goto x86_l_22de;
	case 8928ULL: goto x86_l_22e0;
	case 8932ULL: goto x86_l_22e4;
	case 8934ULL: goto x86_l_22e6;
	case 8937ULL: goto x86_l_22e9;
	case 8940ULL: goto x86_l_22ec;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8949ULL: goto x86_l_22f5;
	case 8954ULL: goto x86_l_22fa;
	case 8960ULL: goto x86_l_2300;
	case 8964ULL: goto x86_l_2304;
	case 8971ULL: goto x86_l_230b;
	case 8974ULL: goto x86_l_230e;
	case 8976ULL: goto x86_l_2310;
	case 8983ULL: goto x86_l_2317;
	case 8987ULL: goto x86_l_231b;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9003ULL: goto x86_l_232b;
	case 9006ULL: goto x86_l_232e;
	case 9008ULL: goto x86_l_2330;
	case 9013ULL: goto x86_l_2335;
	case 9015ULL: goto x86_l_2337;
	case 9017ULL: goto x86_l_2339;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9032ULL: goto x86_l_2348;
	case 9036ULL: goto x86_l_234c;
	case 9046ULL: goto x86_l_2356;
	case 9049ULL: goto x86_l_2359;
	case 9054ULL: goto x86_l_235e;
	case 9058ULL: goto x86_l_2362;
	case 9061ULL: goto x86_l_2365;
	case 9064ULL: goto x86_l_2368;
	case 9068ULL: goto x86_l_236c;
	case 9073ULL: goto x86_l_2371;
	case 9077ULL: goto x86_l_2375;
	case 9081ULL: goto x86_l_2379;
	case 9085ULL: goto x86_l_237d;
	case 9089ULL: goto x86_l_2381;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9101ULL: goto x86_l_238d;
	case 9108ULL: goto x86_l_2394;
	case 9110ULL: goto x86_l_2396;
	case 9113ULL: goto x86_l_2399;
	case 9116ULL: goto x86_l_239c;
	case 9118ULL: goto x86_l_239e;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9129ULL: goto x86_l_23a9;
	case 9131ULL: goto x86_l_23ab;
	case 9135ULL: goto x86_l_23af;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9141ULL: goto x86_l_23b5;
	case 9145ULL: goto x86_l_23b9;
	case 9147ULL: goto x86_l_23bb;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9159ULL: goto x86_l_23c7;
	case 9166ULL: goto x86_l_23ce;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9179ULL: goto x86_l_23db;
	case 9184ULL: goto x86_l_23e0;
	case 9188ULL: goto x86_l_23e4;
	case 9190ULL: goto x86_l_23e6;
	case 9197ULL: goto x86_l_23ed;
	case 9199ULL: goto x86_l_23ef;
	case 9206ULL: goto x86_l_23f6;
	case 9214ULL: goto x86_l_23fe;
	case 9226ULL: goto x86_l_240a;
	case 9235ULL: goto x86_l_2413;
	case 9244ULL: goto x86_l_241c;
	case 9253ULL: goto x86_l_2425;
	case 9262ULL: goto x86_l_242e;
	case 9271ULL: goto x86_l_2437;
	case 9280ULL: goto x86_l_2440;
	case 9287ULL: goto x86_l_2447;
	case 9290ULL: goto x86_l_244a;
	case 9292ULL: goto x86_l_244c;
	case 9299ULL: goto x86_l_2453;
	case 9303ULL: goto x86_l_2457;
	case 9307ULL: goto x86_l_245b;
	case 9309ULL: goto x86_l_245d;
	case 9315ULL: goto x86_l_2463;
	case 9319ULL: goto x86_l_2467;
	case 9321ULL: goto x86_l_2469;
	case 9324ULL: goto x86_l_246c;
	case 9326ULL: goto x86_l_246e;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9341ULL: goto x86_l_247d;
	case 9343ULL: goto x86_l_247f;
	case 9349ULL: goto x86_l_2485;
	case 9352ULL: goto x86_l_2488;
	case 9354ULL: goto x86_l_248a;
	case 9359ULL: goto x86_l_248f;
	case 9361ULL: goto x86_l_2491;
	case 9363ULL: goto x86_l_2493;
	case 9367ULL: goto x86_l_2497;
	case 9369ULL: goto x86_l_2499;
	case 9374ULL: goto x86_l_249e;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9382ULL: goto x86_l_24a6;
	case 9392ULL: goto x86_l_24b0;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9404ULL: goto x86_l_24bc;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9414ULL: goto x86_l_24c6;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9440ULL: goto x86_l_24e0;
	case 9443ULL: goto x86_l_24e3;
	case 9445ULL: goto x86_l_24e5;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9457ULL: goto x86_l_24f1;
	case 9460ULL: goto x86_l_24f4;
	case 9462ULL: goto x86_l_24f6;
	case 9467ULL: goto x86_l_24fb;
	case 9474ULL: goto x86_l_2502;
	case 9476ULL: goto x86_l_2504;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9482ULL: goto x86_l_250a;
	case 9484ULL: goto x86_l_250c;
	case 9486ULL: goto x86_l_250e;
	case 9490ULL: goto x86_l_2512;
	case 9497ULL: goto x86_l_2519;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9513ULL: goto x86_l_2529;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9527ULL: goto x86_l_2537;
	case 9529ULL: goto x86_l_2539;
	case 9534ULL: goto x86_l_253e;
	case 9539ULL: goto x86_l_2543;
	case 9544ULL: goto x86_l_2548;
	case 9552ULL: goto x86_l_2550;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9559ULL: goto x86_l_2557;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9572ULL: goto x86_l_2564;
	case 9575ULL: goto x86_l_2567;
	case 9581ULL: goto x86_l_256d;
	case 9586ULL: goto x86_l_2572;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9599ULL: goto x86_l_257f;
	case 9603ULL: goto x86_l_2583;
	case 9607ULL: goto x86_l_2587;
	case 9609ULL: goto x86_l_2589;
	case 9613ULL: goto x86_l_258d;
	case 9620ULL: goto x86_l_2594;
	case 9625ULL: goto x86_l_2599;
	case 9631ULL: goto x86_l_259f;
	case 9635ULL: goto x86_l_25a3;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9658ULL: goto x86_l_25ba;
	case 9662ULL: goto x86_l_25be;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9677ULL: goto x86_l_25cd;
	case 9682ULL: goto x86_l_25d2;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9704ULL: goto x86_l_25e8;
	case 9710ULL: goto x86_l_25ee;
	case 9715ULL: goto x86_l_25f3;
	case 9719ULL: goto x86_l_25f7;
	case 9725ULL: goto x86_l_25fd;
	case 9733ULL: goto x86_l_2605;
	case 9737ULL: goto x86_l_2609;
	case 9743ULL: goto x86_l_260f;
	case 9750ULL: goto x86_l_2616;
	case 9755ULL: goto x86_l_261b;
	case 9758ULL: goto x86_l_261e;
	case 9760ULL: goto x86_l_2620;
	case 9763ULL: goto x86_l_2623;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9779ULL: goto x86_l_2633;
	case 9781ULL: goto x86_l_2635;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9792ULL: goto x86_l_2640;
	case 9796ULL: goto x86_l_2644;
	case 9800ULL: goto x86_l_2648;
	case 9802ULL: goto x86_l_264a;
	case 9806ULL: goto x86_l_264e;
	case 9813ULL: goto x86_l_2655;
	case 9822ULL: goto x86_l_265e;
	case 9831ULL: goto x86_l_2667;
	case 9840ULL: goto x86_l_2670;
	case 9849ULL: goto x86_l_2679;
	case 9858ULL: goto x86_l_2682;
	case 9867ULL: goto x86_l_268b;
	case 9875ULL: goto x86_l_2693;
	case 9880ULL: goto x86_l_2698;
	case 9885ULL: goto x86_l_269d;
	case 9890ULL: goto x86_l_26a2;
	case 9895ULL: goto x86_l_26a7;
	case 9901ULL: goto x86_l_26ad;
	case 9906ULL: goto x86_l_26b2;
	case 9910ULL: goto x86_l_26b6;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9930ULL: goto x86_l_26ca;
	case 9933ULL: goto x86_l_26cd;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9946ULL: goto x86_l_26da;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9964ULL: goto x86_l_26ec;
	case 9969ULL: goto x86_l_26f1;
	case 9972ULL: goto x86_l_26f4;
	case 9974ULL: goto x86_l_26f6;
	case 9976ULL: goto x86_l_26f8;
	case 9982ULL: goto x86_l_26fe;
	case 9985ULL: goto x86_l_2701;
	case 9991ULL: goto x86_l_2707;
	case 9998ULL: goto x86_l_270e;
	case 10003ULL: goto x86_l_2713;
	case 10006ULL: goto x86_l_2716;
	case 10008ULL: goto x86_l_2718;
	case 10011ULL: goto x86_l_271b;
	case 10013ULL: goto x86_l_271d;
	case 10020ULL: goto x86_l_2724;
	case 10025ULL: goto x86_l_2729;
	case 10028ULL: goto x86_l_272c;
	case 10030ULL: goto x86_l_272e;
	case 10035ULL: goto x86_l_2733;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10046ULL: goto x86_l_273e;
	case 10053ULL: goto x86_l_2745;
	case 10057ULL: goto x86_l_2749;
	case 10061ULL: goto x86_l_274d;
	case 10063ULL: goto x86_l_274f;
	case 10067ULL: goto x86_l_2753;
	case 10074ULL: goto x86_l_275a;
	case 10078ULL: goto x86_l_275e;
	case 10083ULL: goto x86_l_2763;
	case 10095ULL: goto x86_l_276f;
	case 10104ULL: goto x86_l_2778;
	case 10113ULL: goto x86_l_2781;
	case 10122ULL: goto x86_l_278a;
	case 10131ULL: goto x86_l_2793;
	case 10140ULL: goto x86_l_279c;
	case 10149ULL: goto x86_l_27a5;
	case 10158ULL: goto x86_l_27ae;
	case 10167ULL: goto x86_l_27b7;
	case 10176ULL: goto x86_l_27c0;
	case 10185ULL: goto x86_l_27c9;
	case 10194ULL: goto x86_l_27d2;
	case 10203ULL: goto x86_l_27db;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10221ULL: goto x86_l_27ed;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20fb:
	/* 0x20fb: jmp    210d <snat_v6_nat+0xc6b> */
	goto x86_l_210d;
x86_l_20fd:
	/* 0x20fd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2102:
	/* 0x2102: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_210d:
	/* 0x210d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2110:
	/* 0x2110: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_2113:
	/* 0x2113: jne    21ba <snat_v6_nat+0xd18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21ba;
	}
x86_l_2119:
	/* 0x2119: mov    QWORD PTR [rsp+0xb0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2121:
	/* 0x2121: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_2125:
	/* 0x2125: ja     21ff <snat_v6_nat+0xd5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21ff;
	}
x86_l_212b:
	/* 0x212b: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_212e:
	/* 0x212e: movabs rcx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_2138:
	/* 0x2138: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_213c:
	/* 0x213c: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_2141:
	/* 0x2141: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2148:
	/* 0x2148: jae    1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5399ULL;
	}
x86_l_214e:
	/* 0x214e: movzx  eax,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2153:
	/* 0x2153: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2158:
	/* 0x2158: add    esi,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_215c:
	/* 0x215c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2161:
	/* 0x2161: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2166:
	/* 0x2166: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2169:
	/* 0x2169: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_216e:
	/* 0x216e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2171:
	/* 0x2171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2173:
	/* 0x2173: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2175:
	/* 0x2175: js     36ce <snat_v6_nat+0x222c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14030ULL;
	}
x86_l_217b:
	/* 0x217b: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2180:
	/* 0x2180: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2185:
	/* 0x2185: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_218d:
	/* 0x218d: lea    esi,[rdx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2190:
	/* 0x2190: mov    r8d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2198:
	/* 0x2198: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_219c:
	/* 0x219c: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_21a1:
	/* 0x21a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21a4:
	/* 0x21a4: mov    edx,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_21a8:
	/* 0x21a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21aa:
	/* 0x21aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21ac:
	/* 0x21ac: js     36c4 <snat_v6_nat+0x2222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14020ULL;
	}
x86_l_21b2:
	/* 0x21b2: mov    rsi,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_21ba:
	/* 0x21ba: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_21bd:
	/* 0x21bd: jne    21ea <snat_v6_nat+0xd48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21ea;
	}
x86_l_21bf:
	/* 0x21bf: add    esi,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_21c3:
	/* 0x21c3: mov    r8d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_21cb:
	/* 0x21cb: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_21cf:
	/* 0x21cf: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_21d4:
	/* 0x21d4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21d7:
	/* 0x21d7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21d9:
	/* 0x21d9: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_21e0:
	/* 0x21e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e2:
	/* 0x21e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21e4:
	/* 0x21e4: js     36c4 <snat_v6_nat+0x2222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14020ULL;
	}
x86_l_21ea:
	/* 0x21ea: mov    DWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_21f2:
	/* 0x21f2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21f5:
	/* 0x21f5: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21fa:
	/* 0x21fa: jmp    3520 <snat_v6_nat+0x207e> */
	return 13600ULL;
x86_l_21ff:
	/* 0x21ff: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_2204:
	/* 0x2204: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_2209:
	/* 0x2209: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_2210:
	/* 0x2210: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2215:
	/* 0x2215: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2218:
	/* 0x2218: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221a:
	/* 0x221a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_221d:
	/* 0x221d: je     228e <snat_v6_nat+0xdec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228e;
	}
x86_l_221f:
	/* 0x221f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2221:
	/* 0x2221: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2224:
	/* 0x2224: jmp    15eb <snat_v6_nat+0x149> */
	return 5611ULL;
x86_l_2229:
	/* 0x2229: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_2230:
	/* 0x2230: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2235:
	/* 0x2235: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2238:
	/* 0x2238: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_223b:
	/* 0x223b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_223d:
	/* 0x223d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223f:
	/* 0x223f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2241:
	/* 0x2241: je     15eb <snat_v6_nat+0x149> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5611ULL;
	}
x86_l_2247:
	/* 0x2247: mov    ebp,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2249:
	/* 0x2249: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2252:
	/* 0x2252: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_225b:
	/* 0x225b: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_2265:
	/* 0x2265: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_226a:
	/* 0x226a: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2271:
	/* 0x2271: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2276:
	/* 0x2276: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_227b:
	/* 0x227b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227d:
	/* 0x227d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2280:
	/* 0x2280: je     22a2 <snat_v6_nat+0xe00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a2;
	}
x86_l_2282:
	/* 0x2282: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2285:
	/* 0x2285: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2289:
	/* 0x2289: jmp    15eb <snat_v6_nat+0x149> */
	return 5611ULL;
x86_l_228e:
	/* 0x228e: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_2293:
	/* 0x2293: jmp    171a <snat_v6_nat+0x278> */
	return 5914ULL;
x86_l_2298:
	/* 0x2298: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_229d:
	/* 0x229d: jmp    1a87 <snat_v6_nat+0x5e5> */
	return 6791ULL;
x86_l_22a2:
	/* 0x22a2: mov    QWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_22ab:
	/* 0x22ab: mov    QWORD PTR [rsp+0x58],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22b0:
	/* 0x22b0: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_22b7:
	/* 0x22b7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22bc:
	/* 0x22bc: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22c1:
	/* 0x22c1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22c6:
	/* 0x22c6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22c8:
	/* 0x22c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ca:
	/* 0x22ca: jmp    15eb <snat_v6_nat+0x149> */
	return 5611ULL;
x86_l_22cf:
	/* 0x22cf: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_22d5:
	/* 0x22d5: cmp    WORD PTR [rsp+0x98],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 652835028998ULL);
x86_l_22de:
	/* 0x22de: jne    231f <snat_v6_nat+0xe7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_231f;
	}
x86_l_22e0:
	/* 0x22e0: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22e4:
	/* 0x22e4: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_22e6:
	/* 0x22e6: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_22e9:
	/* 0x22e9: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_22ec:
	/* 0x22ec: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_22ee:
	/* 0x22ee: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22f3:
	/* 0x22f3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_22f5:
	/* 0x22f5: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_22fa:
	/* 0x22fa: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_2300:
	/* 0x2300: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2304:
	/* 0x2304: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_230b:
	/* 0x230b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_230e:
	/* 0x230e: je     231f <snat_v6_nat+0xe7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_231f;
	}
x86_l_2310:
	/* 0x2310: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2317:
	/* 0x2317: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_231b:
	/* 0x231b: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_231f:
	/* 0x231f: shr    DWORD PTR [rsp+0x4],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 17179869192ULL);
x86_l_2324:
	/* 0x2324: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_232b:
	/* 0x232b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232e:
	/* 0x232e: je     233f <snat_v6_nat+0xe9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233f;
	}
x86_l_2330:
	/* 0x2330: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2335:
	/* 0x2335: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2337:
	/* 0x2337: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2339:
	/* 0x2339: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_233d:
	/* 0x233d: jmp    2362 <snat_v6_nat+0xec0> */
	goto x86_l_2362;
x86_l_233f:
	/* 0x233f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2344:
	/* 0x2344: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2346:
	/* 0x2346: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2348:
	/* 0x2348: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_234c:
	/* 0x234c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2356:
	/* 0x2356: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2359:
	/* 0x2359: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_235e:
	/* 0x235e: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2362:
	/* 0x2362: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2365:
	/* 0x2365: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2368:
	/* 0x2368: mov    DWORD PTR [r15+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_236c:
	/* 0x236c: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2371:
	/* 0x2371: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2375:
	/* 0x2375: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2379:
	/* 0x2379: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_237d:
	/* 0x237d: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2381:
	/* 0x2381: mov    rsi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2388:
	/* 0x2388: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_238b:
	/* 0x238b: je     239e <snat_v6_nat+0xefc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_239e;
	}
x86_l_238d:
	/* 0x238d: mov    rsi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2394:
	/* 0x2394: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2396:
	/* 0x2396: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2399:
	/* 0x2399: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_239c:
	/* 0x239c: jmp    23a3 <snat_v6_nat+0xf01> */
	goto x86_l_23a3;
x86_l_239e:
	/* 0x239e: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_23a3:
	/* 0x23a3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23a5:
	/* 0x23a5: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23a9:
	/* 0x23a9: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_23ab:
	/* 0x23ab: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23af:
	/* 0x23af: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_23b1:
	/* 0x23b1: jb     23bb <snat_v6_nat+0xf19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_23bb;
	}
x86_l_23b3:
	/* 0x23b3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23b5:
	/* 0x23b5: cmp    cl,BYTE PTR [rsp+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_23b9:
	/* 0x23b9: je     23d0 <snat_v6_nat+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23d0;
	}
x86_l_23bb:
	/* 0x23bb: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23bf:
	/* 0x23bf: mov    BYTE PTR [r15+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_23c3:
	/* 0x23c3: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23c7:
	/* 0x23c7: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_23ce:
	/* 0x23ce: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d0:
	/* 0x23d0: mov    DWORD PTR [r12+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_23d5:
	/* 0x23d5: mov    BYTE PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_23db:
	/* 0x23db: movzx  r15d,BYTE PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_23e0:
	/* 0x23e0: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_23e4:
	/* 0x23e4: jne    23ef <snat_v6_nat+0xf4d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23ef;
	}
x86_l_23e6:
	/* 0x23e6: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_23ed:
	/* 0x23ed: jmp    23f6 <snat_v6_nat+0xf54> */
	goto x86_l_23f6;
x86_l_23ef:
	/* 0x23ef: mov    rax,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_23f6:
	/* 0x23f6: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23fe:
	/* 0x23fe: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_240a:
	/* 0x240a: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2413:
	/* 0x2413: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_241c:
	/* 0x241c: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2425:
	/* 0x2425: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_242e:
	/* 0x242e: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2437:
	/* 0x2437: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2440:
	/* 0x2440: mov    rcx,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2447:
	/* 0x2447: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244a:
	/* 0x244a: je     245d <snat_v6_nat+0xfbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_245d;
	}
x86_l_244c:
	/* 0x244c: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2453:
	/* 0x2453: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2457:
	/* 0x2457: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_245b:
	/* 0x245b: jmp    2463 <snat_v6_nat+0xfc1> */
	goto x86_l_2463;
x86_l_245d:
	/* 0x245d: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_2463:
	/* 0x2463: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_2467:
	/* 0x2467: jne    2485 <snat_v6_nat+0xfe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2485;
	}
x86_l_2469:
	/* 0x2469: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246c:
	/* 0x246c: je     247f <snat_v6_nat+0xfdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247f;
	}
x86_l_246e:
	/* 0x246e: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2475:
	/* 0x2475: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2479:
	/* 0x2479: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_247d:
	/* 0x247d: jmp    2485 <snat_v6_nat+0xfe3> */
	goto x86_l_2485;
x86_l_247f:
	/* 0x247f: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_2485:
	/* 0x2485: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2488:
	/* 0x2488: je     2499 <snat_v6_nat+0xff7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2499;
	}
x86_l_248a:
	/* 0x248a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_248f:
	/* 0x248f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2491:
	/* 0x2491: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2493:
	/* 0x2493: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2497:
	/* 0x2497: jmp    24bc <snat_v6_nat+0x101a> */
	goto x86_l_24bc;
x86_l_2499:
	/* 0x2499: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_249e:
	/* 0x249e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a0:
	/* 0x24a0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_24a2:
	/* 0x24a2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_24a6:
	/* 0x24a6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_24b0:
	/* 0x24b0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_24b3:
	/* 0x24b3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_24b8:
	/* 0x24b8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_24bc:
	/* 0x24bc: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_24c0:
	/* 0x24c0: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_24c3:
	/* 0x24c3: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24c6:
	/* 0x24c6: mov    DWORD PTR [rsp+0x70],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24cb:
	/* 0x24cb: movzx  edx,BYTE PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 122ULL);
x86_l_24d0:
	/* 0x24d0: mov    esi,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_24d7:
	/* 0x24d7: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_24d9:
	/* 0x24d9: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_24e0:
	/* 0x24e0: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e3:
	/* 0x24e3: je     24f6 <snat_v6_nat+0x1054> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f6;
	}
x86_l_24e5:
	/* 0x24e5: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_24ec:
	/* 0x24ec: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ee:
	/* 0x24ee: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_24f1:
	/* 0x24f1: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_24f4:
	/* 0x24f4: jmp    24fb <snat_v6_nat+0x1059> */
	goto x86_l_24fb;
x86_l_24f6:
	/* 0x24f6: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_24fb:
	/* 0x24fb: mov    r15,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2502:
	/* 0x2502: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2504:
	/* 0x2504: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2506:
	/* 0x2506: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2508:
	/* 0x2508: jb     250e <snat_v6_nat+0x106c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_250e;
	}
x86_l_250a:
	/* 0x250a: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_250c:
	/* 0x250c: je     2522 <snat_v6_nat+0x1080> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2522;
	}
x86_l_250e:
	/* 0x250e: mov    BYTE PTR [rsp+0x7a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_2512:
	/* 0x2512: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2519:
	/* 0x2519: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2520:
	/* 0x2520: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2522:
	/* 0x2522: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2529:
	/* 0x2529: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252c:
	/* 0x252c: je     253e <snat_v6_nat+0x109c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253e;
	}
x86_l_252e:
	/* 0x252e: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_2537:
	/* 0x2537: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2539:
	/* 0x2539: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_253e:
	/* 0x253e: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2543:
	/* 0x2543: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2548:
	/* 0x2548: mov    rdi,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2550:
	/* 0x2550: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2553:
	/* 0x2553: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2555:
	/* 0x2555: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2557:
	/* 0x2557: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2559:
	/* 0x2559: js     33c1 <snat_v6_nat+0x1f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13249ULL;
	}
x86_l_255f:
	/* 0x255f: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2564:
	/* 0x2564: test   rbp,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_64);
x86_l_2567:
	/* 0x2567: je     272e <snat_v6_nat+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272e;
	}
x86_l_256d:
	/* 0x256d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2572:
	/* 0x2572: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2574:
	/* 0x2574: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2576:
	/* 0x2576: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2578:
	/* 0x2578: mov    rcx,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_257f:
	/* 0x257f: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2583:
	/* 0x2583: cmp    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2587:
	/* 0x2587: jbe    258d <snat_v6_nat+0x10eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_258d;
	}
x86_l_2589:
	/* 0x2589: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258d:
	/* 0x258d: mov    rcx,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_2594:
	/* 0x2594: mov    BYTE PTR [rcx+rax*1+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 158913789953ULL);
x86_l_2599:
	/* 0x2599: movzx  edx,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_259f:
	/* 0x259f: mov    BYTE PTR [rcx+rax*1+0x24],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 36ULL);
x86_l_25a3:
	/* 0x25a3: mov    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25a7:
	/* 0x25a7: mov    rsi,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25ac:
	/* 0x25ac: mov    QWORD PTR [rcx+rax*1+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_25b1:
	/* 0x25b1: mov    QWORD PTR [rcx+rax*1+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_25b6:
	/* 0x25b6: mov    rdx,QWORD PTR [rbp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25ba:
	/* 0x25ba: mov    rsi,QWORD PTR [rbp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25be:
	/* 0x25be: mov    QWORD PTR [rcx+rax*1],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_25c2:
	/* 0x25c2: mov    QWORD PTR [rcx+rax*1+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_25c7:
	/* 0x25c7: movzx  edx,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_25cd:
	/* 0x25cd: mov    WORD PTR [rcx+rax*1+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 34ULL);
x86_l_25d2:
	/* 0x25d2: movzx  edx,WORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_25d6:
	/* 0x25d6: lea    r14,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_25da:
	/* 0x25da: mov    WORD PTR [rcx+rax*1+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_25df:
	/* 0x25df: mov    rax,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25e4:
	/* 0x25e4: cmp    rax,QWORD PTR [rbp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_25e8:
	/* 0x25e8: jne    26e5 <snat_v6_nat+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26e5;
	}
x86_l_25ee:
	/* 0x25ee: mov    rax,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25f3:
	/* 0x25f3: cmp    rax,QWORD PTR [rbp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_25f7:
	/* 0x25f7: jne    26e5 <snat_v6_nat+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26e5;
	}
x86_l_25fd:
	/* 0x25fd: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2605:
	/* 0x2605: cmp    QWORD PTR [rbp+0x8],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2609:
	/* 0x2609: jne    26e5 <snat_v6_nat+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26e5;
	}
x86_l_260f:
	/* 0x260f: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2616:
	/* 0x2616: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_261b:
	/* 0x261b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_261e:
	/* 0x261e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2620:
	/* 0x2620: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2623:
	/* 0x2623: jne    3317 <snat_v6_nat+0x1e75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13079ULL;
	}
x86_l_2629:
	/* 0x2629: mov    QWORD PTR [rsp+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_262e:
	/* 0x262e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2633:
	/* 0x2633: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2635:
	/* 0x2635: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2637:
	/* 0x2637: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2639:
	/* 0x2639: mov    rcx,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_2640:
	/* 0x2640: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2644:
	/* 0x2644: cmp    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2648:
	/* 0x2648: jbe    264e <snat_v6_nat+0x11ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_264e;
	}
x86_l_264a:
	/* 0x264a: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_264e:
	/* 0x264e: mov    rcx,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_2655:
	/* 0x2655: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_265e:
	/* 0x265e: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_2667:
	/* 0x2667: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_2670:
	/* 0x2670: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_2679:
	/* 0x2679: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_2682:
	/* 0x2682: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_268b:
	/* 0x268b: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2693:
	/* 0x2693: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2698:
	/* 0x2698: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_269d:
	/* 0x269d: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_26a2:
	/* 0x26a2: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_26a7:
	/* 0x26a7: movzx  edx,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_26ad:
	/* 0x26ad: mov    WORD PTR [rcx+rax*1+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 48ULL);
x86_l_26b2:
	/* 0x26b2: lea    rbp,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_26b6:
	/* 0x26b6: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_26be:
	/* 0x26be: mov    QWORD PTR [rcx+rax*1+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_26c3:
	/* 0x26c3: mov    rax,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_26ca:
	/* 0x26ca: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26cd:
	/* 0x26cd: je     32d1 <snat_v6_nat+0x1e2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13009ULL;
	}
x86_l_26d3:
	/* 0x26d3: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_26d8:
	/* 0x26d8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26da:
	/* 0x26da: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_26dc:
	/* 0x26dc: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_26e0:
	/* 0x26e0: jmp    32f4 <snat_v6_nat+0x1e52> */
	return 13044ULL;
x86_l_26e5:
	/* 0x26e5: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_26ec:
	/* 0x26ec: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_26f1:
	/* 0x26f1: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_26f4:
	/* 0x26f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26f6:
	/* 0x26f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f8:
	/* 0x26f8: js     3510 <snat_v6_nat+0x206e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13584ULL;
	}
x86_l_26fe:
	/* 0x26fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2701:
	/* 0x2701: je     3510 <snat_v6_nat+0x206e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13584ULL;
	}
x86_l_2707:
	/* 0x2707: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_270e:
	/* 0x270e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2713:
	/* 0x2713: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2716:
	/* 0x2716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2718:
	/* 0x2718: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_271b:
	/* 0x271b: je     272e <snat_v6_nat+0x128c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272e;
	}
x86_l_271d:
	/* 0x271d: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2724:
	/* 0x2724: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2729:
	/* 0x2729: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_272c:
	/* 0x272c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_272e:
	/* 0x272e: lea    r14,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2733:
	/* 0x2733: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2738:
	/* 0x2738: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_273a:
	/* 0x273a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_273c:
	/* 0x273c: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273e:
	/* 0x273e: mov    rcx,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_2745:
	/* 0x2745: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2749:
	/* 0x2749: cmp    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_274d:
	/* 0x274d: jbe    2753 <snat_v6_nat+0x12b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2753;
	}
x86_l_274f:
	/* 0x274f: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2753:
	/* 0x2753: mov    rcx,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_275a:
	/* 0x275a: lea    rdx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_275e:
	/* 0x275e: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2763:
	/* 0x2763: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_276f:
	/* 0x276f: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_2778:
	/* 0x2778: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2781:
	/* 0x2781: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_278a:
	/* 0x278a: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2793:
	/* 0x2793: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_279c:
	/* 0x279c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_27a5:
	/* 0x27a5: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_27ae:
	/* 0x27ae: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_27b7:
	/* 0x27b7: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_27c0:
	/* 0x27c0: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_27c9:
	/* 0x27c9: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_27d2:
	/* 0x27d2: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_27db:
	/* 0x27db: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_27e3:
	/* 0x27e3: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e8:
	/* 0x27e8: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27ed:
	/* 0x27ed: mov    QWORD PTR [rsp+0x70],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 10226ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10226ULL: goto x86_l_27f2;
	case 10231ULL: goto x86_l_27f7;
	case 10237ULL: goto x86_l_27fd;
	case 10245ULL: goto x86_l_2805;
	case 10248ULL: goto x86_l_2808;
	case 10252ULL: goto x86_l_280c;
	case 10257ULL: goto x86_l_2811;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10277ULL: goto x86_l_2825;
	case 10281ULL: goto x86_l_2829;
	case 10286ULL: goto x86_l_282e;
	case 10291ULL: goto x86_l_2833;
	case 10296ULL: goto x86_l_2838;
	case 10299ULL: goto x86_l_283b;
	case 10303ULL: goto x86_l_283f;
	case 10308ULL: goto x86_l_2844;
	case 10313ULL: goto x86_l_2849;
	case 10319ULL: goto x86_l_284f;
	case 10324ULL: goto x86_l_2854;
	case 10331ULL: goto x86_l_285b;
	case 10337ULL: goto x86_l_2861;
	case 10343ULL: goto x86_l_2867;
	case 10347ULL: goto x86_l_286b;
	case 10351ULL: goto x86_l_286f;
	case 10353ULL: goto x86_l_2871;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10362ULL: goto x86_l_287a;
	case 10367ULL: goto x86_l_287f;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10374ULL: goto x86_l_2886;
	case 10377ULL: goto x86_l_2889;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10395ULL: goto x86_l_289b;
	case 10403ULL: goto x86_l_28a3;
	case 10407ULL: goto x86_l_28a7;
	case 10412ULL: goto x86_l_28ac;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10424ULL: goto x86_l_28b8;
	case 10429ULL: goto x86_l_28bd;
	case 10431ULL: goto x86_l_28bf;
	case 10433ULL: goto x86_l_28c1;
	case 10437ULL: goto x86_l_28c5;
	case 10439ULL: goto x86_l_28c7;
	case 10444ULL: goto x86_l_28cc;
	case 10446ULL: goto x86_l_28ce;
	case 10448ULL: goto x86_l_28d0;
	case 10452ULL: goto x86_l_28d4;
	case 10462ULL: goto x86_l_28de;
	case 10465ULL: goto x86_l_28e1;
	case 10470ULL: goto x86_l_28e6;
	case 10474ULL: goto x86_l_28ea;
	case 10479ULL: goto x86_l_28ef;
	case 10486ULL: goto x86_l_28f6;
	case 10493ULL: goto x86_l_28fd;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10509ULL: goto x86_l_290d;
	case 10515ULL: goto x86_l_2913;
	case 10520ULL: goto x86_l_2918;
	case 10523ULL: goto x86_l_291b;
	case 10525ULL: goto x86_l_291d;
	case 10531ULL: goto x86_l_2923;
	case 10537ULL: goto x86_l_2929;
	case 10543ULL: goto x86_l_292f;
	case 10548ULL: goto x86_l_2934;
	case 10550ULL: goto x86_l_2936;
	case 10552ULL: goto x86_l_2938;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10565ULL: goto x86_l_2945;
	case 10569ULL: goto x86_l_2949;
	case 10572ULL: goto x86_l_294c;
	case 10580ULL: goto x86_l_2954;
	case 10587ULL: goto x86_l_295b;
	case 10592ULL: goto x86_l_2960;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10605ULL: goto x86_l_296d;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10616ULL: goto x86_l_2978;
	case 10622ULL: goto x86_l_297e;
	case 10628ULL: goto x86_l_2984;
	case 10630ULL: goto x86_l_2986;
	case 10632ULL: goto x86_l_2988;
	case 10635ULL: goto x86_l_298b;
	case 10639ULL: goto x86_l_298f;
	case 10642ULL: goto x86_l_2992;
	case 10645ULL: goto x86_l_2995;
	case 10647ULL: goto x86_l_2997;
	case 10654ULL: goto x86_l_299e;
	case 10661ULL: goto x86_l_29a5;
	case 10666ULL: goto x86_l_29aa;
	case 10671ULL: goto x86_l_29af;
	case 10677ULL: goto x86_l_29b5;
	case 10682ULL: goto x86_l_29ba;
	case 10685ULL: goto x86_l_29bd;
	case 10687ULL: goto x86_l_29bf;
	case 10693ULL: goto x86_l_29c5;
	case 10699ULL: goto x86_l_29cb;
	case 10705ULL: goto x86_l_29d1;
	case 10707ULL: goto x86_l_29d3;
	case 10709ULL: goto x86_l_29d5;
	case 10711ULL: goto x86_l_29d7;
	case 10714ULL: goto x86_l_29da;
	case 10717ULL: goto x86_l_29dd;
	case 10720ULL: goto x86_l_29e0;
	case 10722ULL: goto x86_l_29e2;
	case 10729ULL: goto x86_l_29e9;
	case 10736ULL: goto x86_l_29f0;
	case 10741ULL: goto x86_l_29f5;
	case 10746ULL: goto x86_l_29fa;
	case 10751ULL: goto x86_l_29ff;
	case 10754ULL: goto x86_l_2a02;
	case 10756ULL: goto x86_l_2a04;
	case 10762ULL: goto x86_l_2a0a;
	case 10768ULL: goto x86_l_2a10;
	case 10774ULL: goto x86_l_2a16;
	case 10776ULL: goto x86_l_2a18;
	case 10778ULL: goto x86_l_2a1a;
	case 10780ULL: goto x86_l_2a1c;
	case 10783ULL: goto x86_l_2a1f;
	case 10786ULL: goto x86_l_2a22;
	case 10789ULL: goto x86_l_2a25;
	case 10791ULL: goto x86_l_2a27;
	case 10798ULL: goto x86_l_2a2e;
	case 10805ULL: goto x86_l_2a35;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10821ULL: goto x86_l_2a45;
	case 10826ULL: goto x86_l_2a4a;
	case 10829ULL: goto x86_l_2a4d;
	case 10831ULL: goto x86_l_2a4f;
	case 10837ULL: goto x86_l_2a55;
	case 10843ULL: goto x86_l_2a5b;
	case 10849ULL: goto x86_l_2a61;
	case 10851ULL: goto x86_l_2a63;
	case 10853ULL: goto x86_l_2a65;
	case 10855ULL: goto x86_l_2a67;
	case 10858ULL: goto x86_l_2a6a;
	case 10861ULL: goto x86_l_2a6d;
	case 10864ULL: goto x86_l_2a70;
	case 10866ULL: goto x86_l_2a72;
	case 10873ULL: goto x86_l_2a79;
	case 10880ULL: goto x86_l_2a80;
	case 10885ULL: goto x86_l_2a85;
	case 10890ULL: goto x86_l_2a8a;
	case 10895ULL: goto x86_l_2a8f;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10906ULL: goto x86_l_2a9a;
	case 10912ULL: goto x86_l_2aa0;
	case 10918ULL: goto x86_l_2aa6;
	case 10920ULL: goto x86_l_2aa8;
	case 10922ULL: goto x86_l_2aaa;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10930ULL: goto x86_l_2ab2;
	case 10933ULL: goto x86_l_2ab5;
	case 10935ULL: goto x86_l_2ab7;
	case 10942ULL: goto x86_l_2abe;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10959ULL: goto x86_l_2acf;
	case 10965ULL: goto x86_l_2ad5;
	case 10970ULL: goto x86_l_2ada;
	case 10973ULL: goto x86_l_2add;
	case 10975ULL: goto x86_l_2adf;
	case 10981ULL: goto x86_l_2ae5;
	case 10987ULL: goto x86_l_2aeb;
	case 10993ULL: goto x86_l_2af1;
	case 10995ULL: goto x86_l_2af3;
	case 10997ULL: goto x86_l_2af5;
	case 10999ULL: goto x86_l_2af7;
	case 11002ULL: goto x86_l_2afa;
	case 11005ULL: goto x86_l_2afd;
	case 11008ULL: goto x86_l_2b00;
	case 11010ULL: goto x86_l_2b02;
	case 11017ULL: goto x86_l_2b09;
	case 11024ULL: goto x86_l_2b10;
	case 11029ULL: goto x86_l_2b15;
	case 11034ULL: goto x86_l_2b1a;
	case 11039ULL: goto x86_l_2b1f;
	case 11042ULL: goto x86_l_2b22;
	case 11044ULL: goto x86_l_2b24;
	case 11050ULL: goto x86_l_2b2a;
	case 11056ULL: goto x86_l_2b30;
	case 11062ULL: goto x86_l_2b36;
	case 11064ULL: goto x86_l_2b38;
	case 11066ULL: goto x86_l_2b3a;
	case 11068ULL: goto x86_l_2b3c;
	case 11071ULL: goto x86_l_2b3f;
	case 11074ULL: goto x86_l_2b42;
	case 11077ULL: goto x86_l_2b45;
	case 11079ULL: goto x86_l_2b47;
	case 11086ULL: goto x86_l_2b4e;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11103ULL: goto x86_l_2b5f;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11117ULL: goto x86_l_2b6d;
	case 11119ULL: goto x86_l_2b6f;
	case 11125ULL: goto x86_l_2b75;
	case 11131ULL: goto x86_l_2b7b;
	case 11137ULL: goto x86_l_2b81;
	case 11139ULL: goto x86_l_2b83;
	case 11141ULL: goto x86_l_2b85;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11149ULL: goto x86_l_2b8d;
	case 11152ULL: goto x86_l_2b90;
	case 11154ULL: goto x86_l_2b92;
	case 11161ULL: goto x86_l_2b99;
	case 11168ULL: goto x86_l_2ba0;
	case 11173ULL: goto x86_l_2ba5;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11186ULL: goto x86_l_2bb2;
	case 11188ULL: goto x86_l_2bb4;
	case 11194ULL: goto x86_l_2bba;
	case 11200ULL: goto x86_l_2bc0;
	case 11206ULL: goto x86_l_2bc6;
	case 11208ULL: goto x86_l_2bc8;
	case 11210ULL: goto x86_l_2bca;
	case 11212ULL: goto x86_l_2bcc;
	case 11215ULL: goto x86_l_2bcf;
	case 11218ULL: goto x86_l_2bd2;
	case 11221ULL: goto x86_l_2bd5;
	case 11223ULL: goto x86_l_2bd7;
	case 11230ULL: goto x86_l_2bde;
	case 11237ULL: goto x86_l_2be5;
	case 11242ULL: goto x86_l_2bea;
	case 11247ULL: goto x86_l_2bef;
	case 11253ULL: goto x86_l_2bf5;
	case 11258ULL: goto x86_l_2bfa;
	case 11261ULL: goto x86_l_2bfd;
	case 11263ULL: goto x86_l_2bff;
	case 11269ULL: goto x86_l_2c05;
	case 11275ULL: goto x86_l_2c0b;
	case 11281ULL: goto x86_l_2c11;
	case 11283ULL: goto x86_l_2c13;
	case 11285ULL: goto x86_l_2c15;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11293ULL: goto x86_l_2c1d;
	case 11296ULL: goto x86_l_2c20;
	case 11298ULL: goto x86_l_2c22;
	case 11305ULL: goto x86_l_2c29;
	case 11312ULL: goto x86_l_2c30;
	case 11317ULL: goto x86_l_2c35;
	case 11322ULL: goto x86_l_2c3a;
	case 11327ULL: goto x86_l_2c3f;
	case 11330ULL: goto x86_l_2c42;
	case 11332ULL: goto x86_l_2c44;
	case 11338ULL: goto x86_l_2c4a;
	case 11344ULL: goto x86_l_2c50;
	case 11350ULL: goto x86_l_2c56;
	case 11352ULL: goto x86_l_2c58;
	case 11354ULL: goto x86_l_2c5a;
	case 11356ULL: goto x86_l_2c5c;
	case 11359ULL: goto x86_l_2c5f;
	case 11362ULL: goto x86_l_2c62;
	case 11365ULL: goto x86_l_2c65;
	case 11367ULL: goto x86_l_2c67;
	case 11374ULL: goto x86_l_2c6e;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11397ULL: goto x86_l_2c85;
	case 11402ULL: goto x86_l_2c8a;
	case 11405ULL: goto x86_l_2c8d;
	case 11407ULL: goto x86_l_2c8f;
	case 11413ULL: goto x86_l_2c95;
	case 11419ULL: goto x86_l_2c9b;
	case 11425ULL: goto x86_l_2ca1;
	case 11427ULL: goto x86_l_2ca3;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11434ULL: goto x86_l_2caa;
	case 11437ULL: goto x86_l_2cad;
	case 11440ULL: goto x86_l_2cb0;
	case 11442ULL: goto x86_l_2cb2;
	case 11449ULL: goto x86_l_2cb9;
	case 11456ULL: goto x86_l_2cc0;
	case 11461ULL: goto x86_l_2cc5;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11482ULL: goto x86_l_2cda;
	case 11488ULL: goto x86_l_2ce0;
	case 11494ULL: goto x86_l_2ce6;
	case 11496ULL: goto x86_l_2ce8;
	case 11498ULL: goto x86_l_2cea;
	case 11500ULL: goto x86_l_2cec;
	case 11503ULL: goto x86_l_2cef;
	case 11506ULL: goto x86_l_2cf2;
	case 11509ULL: goto x86_l_2cf5;
	case 11511ULL: goto x86_l_2cf7;
	case 11518ULL: goto x86_l_2cfe;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11535ULL: goto x86_l_2d0f;
	case 11541ULL: goto x86_l_2d15;
	case 11546ULL: goto x86_l_2d1a;
	case 11549ULL: goto x86_l_2d1d;
	case 11551ULL: goto x86_l_2d1f;
	case 11557ULL: goto x86_l_2d25;
	case 11563ULL: goto x86_l_2d2b;
	case 11569ULL: goto x86_l_2d31;
	case 11571ULL: goto x86_l_2d33;
	case 11573ULL: goto x86_l_2d35;
	case 11575ULL: goto x86_l_2d37;
	case 11578ULL: goto x86_l_2d3a;
	case 11581ULL: goto x86_l_2d3d;
	case 11584ULL: goto x86_l_2d40;
	case 11586ULL: goto x86_l_2d42;
	case 11593ULL: goto x86_l_2d49;
	case 11600ULL: goto x86_l_2d50;
	case 11605ULL: goto x86_l_2d55;
	case 11610ULL: goto x86_l_2d5a;
	case 11615ULL: goto x86_l_2d5f;
	case 11618ULL: goto x86_l_2d62;
	case 11620ULL: goto x86_l_2d64;
	case 11626ULL: goto x86_l_2d6a;
	case 11632ULL: goto x86_l_2d70;
	case 11638ULL: goto x86_l_2d76;
	case 11640ULL: goto x86_l_2d78;
	case 11642ULL: goto x86_l_2d7a;
	case 11644ULL: goto x86_l_2d7c;
	case 11647ULL: goto x86_l_2d7f;
	case 11650ULL: goto x86_l_2d82;
	case 11653ULL: goto x86_l_2d85;
	case 11655ULL: goto x86_l_2d87;
	case 11662ULL: goto x86_l_2d8e;
	case 11669ULL: goto x86_l_2d95;
	case 11674ULL: goto x86_l_2d9a;
	case 11679ULL: goto x86_l_2d9f;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11695ULL: goto x86_l_2daf;
	case 11701ULL: goto x86_l_2db5;
	case 11707ULL: goto x86_l_2dbb;
	case 11713ULL: goto x86_l_2dc1;
	case 11715ULL: goto x86_l_2dc3;
	case 11717ULL: goto x86_l_2dc5;
	case 11719ULL: goto x86_l_2dc7;
	case 11723ULL: goto x86_l_2dcb;
	case 11727ULL: goto x86_l_2dcf;
	case 11731ULL: goto x86_l_2dd3;
	case 11734ULL: goto x86_l_2dd6;
	case 11742ULL: goto x86_l_2dde;
	case 11749ULL: goto x86_l_2de5;
	case 11754ULL: goto x86_l_2dea;
	case 11759ULL: goto x86_l_2def;
	case 11764ULL: goto x86_l_2df4;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11775ULL: goto x86_l_2dff;
	case 11781ULL: goto x86_l_2e05;
	case 11787ULL: goto x86_l_2e0b;
	case 11789ULL: goto x86_l_2e0d;
	case 11791ULL: goto x86_l_2e0f;
	case 11794ULL: goto x86_l_2e12;
	case 11798ULL: goto x86_l_2e16;
	case 11802ULL: goto x86_l_2e1a;
	case 11806ULL: goto x86_l_2e1e;
	case 11809ULL: goto x86_l_2e21;
	case 11817ULL: goto x86_l_2e29;
	case 11824ULL: goto x86_l_2e30;
	case 11829ULL: goto x86_l_2e35;
	case 11834ULL: goto x86_l_2e3a;
	case 11840ULL: goto x86_l_2e40;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27f2:
	/* 0x27f2: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_27f7:
	/* 0x27f7: movzx  ebp,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_27fd:
	/* 0x27fd: mov    WORD PTR [rsp+0x80],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2805:
	/* 0x2805: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2808:
	/* 0x2808: mov    rsi,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_280c:
	/* 0x280c: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_2811:
	/* 0x2811: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_2816:
	/* 0x2816: mov    BYTE PTR [rsp+0x35],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266689ULL);
x86_l_281b:
	/* 0x281b: movzx  eax,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_2821:
	/* 0x2821: mov    BYTE PTR [rsp+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2825:
	/* 0x2825: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2829:
	/* 0x2829: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_282e:
	/* 0x282e: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2833:
	/* 0x2833: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2838:
	/* 0x2838: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283b:
	/* 0x283b: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_283f:
	/* 0x283f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2844:
	/* 0x2844: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2849:
	/* 0x2849: movzx  eax,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_284f:
	/* 0x284f: mov    WORD PTR [rsp+0x32],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_2854:
	/* 0x2854: mov    WORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_285b:
	/* 0x285b: movzx  r14d,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2861:
	/* 0x2861: movzx  eax,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2867:
	/* 0x2867: rol    bp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_286b:
	/* 0x286b: cmp    bp,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R14, X86_WIDTH_16);
x86_l_286f:
	/* 0x286f: jb     2876 <snat_v6_nat+0x13d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2876;
	}
x86_l_2871:
	/* 0x2871: cmp    bp,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_16);
x86_l_2874:
	/* 0x2874: jbe    2896 <snat_v6_nat+0x13f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2896;
	}
x86_l_2876:
	/* 0x2876: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_287a:
	/* 0x287a: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_287f:
	/* 0x287f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2881:
	/* 0x2881: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2883:
	/* 0x2883: sub    r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2886:
	/* 0x2886: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2889:
	/* 0x2889: movzx  ebp,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_288c:
	/* 0x288c: imul   ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2890:
	/* 0x2890: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2893:
	/* 0x2893: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2896:
	/* 0x2896: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_289b:
	/* 0x289b: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_28a3:
	/* 0x28a3: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28a7:
	/* 0x28a7: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28ac:
	/* 0x28ac: mov    rax,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_28b3:
	/* 0x28b3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28b6:
	/* 0x28b6: je     28c7 <snat_v6_nat+0x1425> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c7;
	}
x86_l_28b8:
	/* 0x28b8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_28bd:
	/* 0x28bd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28bf:
	/* 0x28bf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28c1:
	/* 0x28c1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_28c5:
	/* 0x28c5: jmp    28ea <snat_v6_nat+0x1448> */
	goto x86_l_28ea;
x86_l_28c7:
	/* 0x28c7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_28cc:
	/* 0x28cc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28ce:
	/* 0x28ce: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28d0:
	/* 0x28d0: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_28d4:
	/* 0x28d4: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_28de:
	/* 0x28de: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_28e1:
	/* 0x28e1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_28e6:
	/* 0x28e6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_28ea:
	/* 0x28ea: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28ef:
	/* 0x28ef: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_28f6:
	/* 0x28f6: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_28fd:
	/* 0x28fd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2902:
	/* 0x2902: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2907:
	/* 0x2907: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_290d:
	/* 0x290d: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_2913:
	/* 0x2913: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2918:
	/* 0x2918: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_291b:
	/* 0x291b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_291d:
	/* 0x291d: je     3272 <snat_v6_nat+0x1dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12914ULL;
	}
x86_l_2923:
	/* 0x2923: movzx  ebp,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2929:
	/* 0x2929: movzx  r15d,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_292f:
	/* 0x292f: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2934:
	/* 0x2934: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2936:
	/* 0x2936: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2938:
	/* 0x2938: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_293b:
	/* 0x293b: sub    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_293e:
	/* 0x293e: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2941:
	/* 0x2941: imul   r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2945:
	/* 0x2945: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2949:
	/* 0x2949: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_294c:
	/* 0x294c: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2954:
	/* 0x2954: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_295b:
	/* 0x295b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2960:
	/* 0x2960: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2965:
	/* 0x2965: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_296a:
	/* 0x296a: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_296d:
	/* 0x296d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2970:
	/* 0x2970: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2972:
	/* 0x2972: je     344b <snat_v6_nat+0x1fa9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13387ULL;
	}
x86_l_2978:
	/* 0x2978: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_297e:
	/* 0x297e: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2984:
	/* 0x2984: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2986:
	/* 0x2986: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2988:
	/* 0x2988: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_298b:
	/* 0x298b: movzx  ebp,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_298f:
	/* 0x298f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2992:
	/* 0x2992: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2995:
	/* 0x2995: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2997:
	/* 0x2997: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_299e:
	/* 0x299e: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_29a5:
	/* 0x29a5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29aa:
	/* 0x29aa: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29af:
	/* 0x29af: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_29b5:
	/* 0x29b5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_29ba:
	/* 0x29ba: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_29bd:
	/* 0x29bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29bf:
	/* 0x29bf: je     327d <snat_v6_nat+0x1ddb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12925ULL;
	}
x86_l_29c5:
	/* 0x29c5: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_29cb:
	/* 0x29cb: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_29d1:
	/* 0x29d1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29d3:
	/* 0x29d3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_29d5:
	/* 0x29d5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_29d7:
	/* 0x29d7: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_29da:
	/* 0x29da: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_29dd:
	/* 0x29dd: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_29e0:
	/* 0x29e0: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_29e2:
	/* 0x29e2: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_29e9:
	/* 0x29e9: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_29f0:
	/* 0x29f0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29f5:
	/* 0x29f5: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_29fa:
	/* 0x29fa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_29ff:
	/* 0x29ff: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2a02:
	/* 0x2a02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a04:
	/* 0x2a04: je     328b <snat_v6_nat+0x1de9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12939ULL;
	}
x86_l_2a0a:
	/* 0x2a0a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2a10:
	/* 0x2a10: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2a16:
	/* 0x2a16: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a18:
	/* 0x2a18: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a1a:
	/* 0x2a1a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a1c:
	/* 0x2a1c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a1f:
	/* 0x2a1f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2a22:
	/* 0x2a22: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2a25:
	/* 0x2a25: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a27:
	/* 0x2a27: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2a2e:
	/* 0x2a2e: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2a35:
	/* 0x2a35: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3a:
	/* 0x2a3a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a3f:
	/* 0x2a3f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2a45:
	/* 0x2a45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a4a:
	/* 0x2a4a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2a4d:
	/* 0x2a4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a4f:
	/* 0x2a4f: je     3299 <snat_v6_nat+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12953ULL;
	}
x86_l_2a55:
	/* 0x2a55: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2a5b:
	/* 0x2a5b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2a61:
	/* 0x2a61: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2a63:
	/* 0x2a63: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a65:
	/* 0x2a65: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2a67:
	/* 0x2a67: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a6a:
	/* 0x2a6a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2a6d:
	/* 0x2a6d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2a70:
	/* 0x2a70: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a72:
	/* 0x2a72: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2a79:
	/* 0x2a79: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2a80:
	/* 0x2a80: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a85:
	/* 0x2a85: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a8a:
	/* 0x2a8a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a8f:
	/* 0x2a8f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2a92:
	/* 0x2a92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a94:
	/* 0x2a94: je     32a7 <snat_v6_nat+0x1e05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12967ULL;
	}
x86_l_2a9a:
	/* 0x2a9a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2aa0:
	/* 0x2aa0: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2aa6:
	/* 0x2aa6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2aa8:
	/* 0x2aa8: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2aaa:
	/* 0x2aaa: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2aac:
	/* 0x2aac: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2aaf:
	/* 0x2aaf: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2ab2:
	/* 0x2ab2: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2ab5:
	/* 0x2ab5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ab7:
	/* 0x2ab7: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2abe:
	/* 0x2abe: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2ac5:
	/* 0x2ac5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2aca:
	/* 0x2aca: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2acf:
	/* 0x2acf: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2ad5:
	/* 0x2ad5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ada:
	/* 0x2ada: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2add:
	/* 0x2add: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2adf:
	/* 0x2adf: je     32b5 <snat_v6_nat+0x1e13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12981ULL;
	}
x86_l_2ae5:
	/* 0x2ae5: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2aeb:
	/* 0x2aeb: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2af1:
	/* 0x2af1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2af3:
	/* 0x2af3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2af5:
	/* 0x2af5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2af7:
	/* 0x2af7: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2afa:
	/* 0x2afa: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2afd:
	/* 0x2afd: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2b00:
	/* 0x2b00: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b02:
	/* 0x2b02: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2b09:
	/* 0x2b09: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2b10:
	/* 0x2b10: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b15:
	/* 0x2b15: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b1a:
	/* 0x2b1a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2b1f:
	/* 0x2b1f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2b22:
	/* 0x2b22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b24:
	/* 0x2b24: je     32c3 <snat_v6_nat+0x1e21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12995ULL;
	}
x86_l_2b2a:
	/* 0x2b2a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2b30:
	/* 0x2b30: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2b36:
	/* 0x2b36: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b38:
	/* 0x2b38: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b3a:
	/* 0x2b3a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b3c:
	/* 0x2b3c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b3f:
	/* 0x2b3f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2b42:
	/* 0x2b42: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2b45:
	/* 0x2b45: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b47:
	/* 0x2b47: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2b4e:
	/* 0x2b4e: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2b55:
	/* 0x2b55: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5a:
	/* 0x2b5a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b5f:
	/* 0x2b5f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2b65:
	/* 0x2b65: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2b6a:
	/* 0x2b6a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2b6d:
	/* 0x2b6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b6f:
	/* 0x2b6f: je     3338 <snat_v6_nat+0x1e96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13112ULL;
	}
x86_l_2b75:
	/* 0x2b75: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2b7b:
	/* 0x2b7b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2b81:
	/* 0x2b81: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2b83:
	/* 0x2b83: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b85:
	/* 0x2b85: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2b87:
	/* 0x2b87: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2b8a:
	/* 0x2b8a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2b8d:
	/* 0x2b8d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2b90:
	/* 0x2b90: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b92:
	/* 0x2b92: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2b99:
	/* 0x2b99: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2ba0:
	/* 0x2ba0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ba5:
	/* 0x2ba5: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2baa:
	/* 0x2baa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2baf:
	/* 0x2baf: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2bb2:
	/* 0x2bb2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bb4:
	/* 0x2bb4: je     3346 <snat_v6_nat+0x1ea4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13126ULL;
	}
x86_l_2bba:
	/* 0x2bba: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2bc0:
	/* 0x2bc0: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2bc6:
	/* 0x2bc6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2bc8:
	/* 0x2bc8: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2bca:
	/* 0x2bca: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2bcc:
	/* 0x2bcc: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2bcf:
	/* 0x2bcf: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2bd2:
	/* 0x2bd2: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2bd5:
	/* 0x2bd5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2bd7:
	/* 0x2bd7: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2bde:
	/* 0x2bde: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2be5:
	/* 0x2be5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bea:
	/* 0x2bea: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2bef:
	/* 0x2bef: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2bf5:
	/* 0x2bf5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2bfa:
	/* 0x2bfa: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2bfd:
	/* 0x2bfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bff:
	/* 0x2bff: je     3354 <snat_v6_nat+0x1eb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13140ULL;
	}
x86_l_2c05:
	/* 0x2c05: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2c0b:
	/* 0x2c0b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2c11:
	/* 0x2c11: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c13:
	/* 0x2c13: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c15:
	/* 0x2c15: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c17:
	/* 0x2c17: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c1a:
	/* 0x2c1a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2c1d:
	/* 0x2c1d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2c20:
	/* 0x2c20: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c22:
	/* 0x2c22: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2c29:
	/* 0x2c29: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2c30:
	/* 0x2c30: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c35:
	/* 0x2c35: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c3f:
	/* 0x2c3f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2c42:
	/* 0x2c42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c44:
	/* 0x2c44: je     3362 <snat_v6_nat+0x1ec0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13154ULL;
	}
x86_l_2c4a:
	/* 0x2c4a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2c50:
	/* 0x2c50: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2c56:
	/* 0x2c56: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2c58:
	/* 0x2c58: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c5a:
	/* 0x2c5a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2c5c:
	/* 0x2c5c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c5f:
	/* 0x2c5f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2c62:
	/* 0x2c62: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2c65:
	/* 0x2c65: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c67:
	/* 0x2c67: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2c6e:
	/* 0x2c6e: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2c75:
	/* 0x2c75: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c7a:
	/* 0x2c7a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c7f:
	/* 0x2c7f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2c85:
	/* 0x2c85: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c8a:
	/* 0x2c8a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2c8d:
	/* 0x2c8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c8f:
	/* 0x2c8f: je     3370 <snat_v6_nat+0x1ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13168ULL;
	}
x86_l_2c95:
	/* 0x2c95: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2c9b:
	/* 0x2c9b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2ca1:
	/* 0x2ca1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ca3:
	/* 0x2ca3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ca5:
	/* 0x2ca5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2ca7:
	/* 0x2ca7: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2caa:
	/* 0x2caa: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2cad:
	/* 0x2cad: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2cb0:
	/* 0x2cb0: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2cb2:
	/* 0x2cb2: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2cb9:
	/* 0x2cb9: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2cc0:
	/* 0x2cc0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cc5:
	/* 0x2cc5: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2cca:
	/* 0x2cca: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ccf:
	/* 0x2ccf: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2cd2:
	/* 0x2cd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cd4:
	/* 0x2cd4: je     337e <snat_v6_nat+0x1edc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13182ULL;
	}
x86_l_2cda:
	/* 0x2cda: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2ce0:
	/* 0x2ce0: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2ce6:
	/* 0x2ce6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ce8:
	/* 0x2ce8: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2cea:
	/* 0x2cea: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2cec:
	/* 0x2cec: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2cef:
	/* 0x2cef: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2cf2:
	/* 0x2cf2: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2cf5:
	/* 0x2cf5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2cf7:
	/* 0x2cf7: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2cfe:
	/* 0x2cfe: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2d05:
	/* 0x2d05: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d0a:
	/* 0x2d0a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d0f:
	/* 0x2d0f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2d15:
	/* 0x2d15: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d1a:
	/* 0x2d1a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2d1d:
	/* 0x2d1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d1f:
	/* 0x2d1f: je     338c <snat_v6_nat+0x1eea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13196ULL;
	}
x86_l_2d25:
	/* 0x2d25: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2d2b:
	/* 0x2d2b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2d31:
	/* 0x2d31: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d33:
	/* 0x2d33: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d35:
	/* 0x2d35: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d37:
	/* 0x2d37: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d3a:
	/* 0x2d3a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2d3d:
	/* 0x2d3d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2d40:
	/* 0x2d40: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d42:
	/* 0x2d42: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2d49:
	/* 0x2d49: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2d50:
	/* 0x2d50: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d55:
	/* 0x2d55: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d5a:
	/* 0x2d5a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d5f:
	/* 0x2d5f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2d62:
	/* 0x2d62: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d64:
	/* 0x2d64: je     339a <snat_v6_nat+0x1ef8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13210ULL;
	}
x86_l_2d6a:
	/* 0x2d6a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2d70:
	/* 0x2d70: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2d76:
	/* 0x2d76: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2d78:
	/* 0x2d78: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d7a:
	/* 0x2d7a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2d7c:
	/* 0x2d7c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d7f:
	/* 0x2d7f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2d82:
	/* 0x2d82: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2d85:
	/* 0x2d85: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d87:
	/* 0x2d87: movbe  WORD PTR [rsp+0x30],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2d8e:
	/* 0x2d8e: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2d95:
	/* 0x2d95: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9a:
	/* 0x2d9a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2d9f:
	/* 0x2d9f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2da5:
	/* 0x2da5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2daa:
	/* 0x2daa: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2dad:
	/* 0x2dad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2daf:
	/* 0x2daf: je     33a8 <snat_v6_nat+0x1f06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13224ULL;
	}
x86_l_2db5:
	/* 0x2db5: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2dbb:
	/* 0x2dbb: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2dc1:
	/* 0x2dc1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2dc3:
	/* 0x2dc3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dc5:
	/* 0x2dc5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2dc7:
	/* 0x2dc7: movzx  r15d,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2dcb:
	/* 0x2dcb: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2dcf:
	/* 0x2dcf: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2dd3:
	/* 0x2dd3: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2dd6:
	/* 0x2dd6: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2dde:
	/* 0x2dde: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2de5:
	/* 0x2de5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dea:
	/* 0x2dea: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2def:
	/* 0x2def: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2df4:
	/* 0x2df4: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2df7:
	/* 0x2df7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2df9:
	/* 0x2df9: je     33b6 <snat_v6_nat+0x1f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13238ULL;
	}
x86_l_2dff:
	/* 0x2dff: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2e05:
	/* 0x2e05: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2e0b:
	/* 0x2e0b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e0d:
	/* 0x2e0d: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e0f:
	/* 0x2e0f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e12:
	/* 0x2e12: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e16:
	/* 0x2e16: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2e1a:
	/* 0x2e1a: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2e1e:
	/* 0x2e1e: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e21:
	/* 0x2e21: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2e29:
	/* 0x2e29: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2e30:
	/* 0x2e30: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e35:
	/* 0x2e35: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e3a:
	/* 0x2e3a: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2e40:
	/* 0x2e40: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
	return 11845ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11845ULL: goto x86_l_2e45;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11856ULL: goto x86_l_2e50;
	case 11862ULL: goto x86_l_2e56;
	case 11868ULL: goto x86_l_2e5c;
	case 11870ULL: goto x86_l_2e5e;
	case 11872ULL: goto x86_l_2e60;
	case 11875ULL: goto x86_l_2e63;
	case 11879ULL: goto x86_l_2e67;
	case 11883ULL: goto x86_l_2e6b;
	case 11887ULL: goto x86_l_2e6f;
	case 11890ULL: goto x86_l_2e72;
	case 11898ULL: goto x86_l_2e7a;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11915ULL: goto x86_l_2e8b;
	case 11920ULL: goto x86_l_2e90;
	case 11923ULL: goto x86_l_2e93;
	case 11925ULL: goto x86_l_2e95;
	case 11931ULL: goto x86_l_2e9b;
	case 11937ULL: goto x86_l_2ea1;
	case 11943ULL: goto x86_l_2ea7;
	case 11945ULL: goto x86_l_2ea9;
	case 11947ULL: goto x86_l_2eab;
	case 11950ULL: goto x86_l_2eae;
	case 11954ULL: goto x86_l_2eb2;
	case 11958ULL: goto x86_l_2eb6;
	case 11962ULL: goto x86_l_2eba;
	case 11965ULL: goto x86_l_2ebd;
	case 11973ULL: goto x86_l_2ec5;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11996ULL: goto x86_l_2edc;
	case 12001ULL: goto x86_l_2ee1;
	case 12004ULL: goto x86_l_2ee4;
	case 12006ULL: goto x86_l_2ee6;
	case 12012ULL: goto x86_l_2eec;
	case 12018ULL: goto x86_l_2ef2;
	case 12024ULL: goto x86_l_2ef8;
	case 12026ULL: goto x86_l_2efa;
	case 12028ULL: goto x86_l_2efc;
	case 12031ULL: goto x86_l_2eff;
	case 12035ULL: goto x86_l_2f03;
	case 12039ULL: goto x86_l_2f07;
	case 12043ULL: goto x86_l_2f0b;
	case 12046ULL: goto x86_l_2f0e;
	case 12054ULL: goto x86_l_2f16;
	case 12061ULL: goto x86_l_2f1d;
	case 12066ULL: goto x86_l_2f22;
	case 12071ULL: goto x86_l_2f27;
	case 12076ULL: goto x86_l_2f2c;
	case 12079ULL: goto x86_l_2f2f;
	case 12081ULL: goto x86_l_2f31;
	case 12087ULL: goto x86_l_2f37;
	case 12093ULL: goto x86_l_2f3d;
	case 12099ULL: goto x86_l_2f43;
	case 12101ULL: goto x86_l_2f45;
	case 12103ULL: goto x86_l_2f47;
	case 12106ULL: goto x86_l_2f4a;
	case 12110ULL: goto x86_l_2f4e;
	case 12114ULL: goto x86_l_2f52;
	case 12118ULL: goto x86_l_2f56;
	case 12121ULL: goto x86_l_2f59;
	case 12129ULL: goto x86_l_2f61;
	case 12136ULL: goto x86_l_2f68;
	case 12141ULL: goto x86_l_2f6d;
	case 12146ULL: goto x86_l_2f72;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12160ULL: goto x86_l_2f80;
	case 12162ULL: goto x86_l_2f82;
	case 12168ULL: goto x86_l_2f88;
	case 12174ULL: goto x86_l_2f8e;
	case 12180ULL: goto x86_l_2f94;
	case 12182ULL: goto x86_l_2f96;
	case 12184ULL: goto x86_l_2f98;
	case 12187ULL: goto x86_l_2f9b;
	case 12191ULL: goto x86_l_2f9f;
	case 12195ULL: goto x86_l_2fa3;
	case 12199ULL: goto x86_l_2fa7;
	case 12202ULL: goto x86_l_2faa;
	case 12210ULL: goto x86_l_2fb2;
	case 12217ULL: goto x86_l_2fb9;
	case 12222ULL: goto x86_l_2fbe;
	case 12227ULL: goto x86_l_2fc3;
	case 12232ULL: goto x86_l_2fc8;
	case 12235ULL: goto x86_l_2fcb;
	case 12237ULL: goto x86_l_2fcd;
	case 12243ULL: goto x86_l_2fd3;
	case 12249ULL: goto x86_l_2fd9;
	case 12255ULL: goto x86_l_2fdf;
	case 12257ULL: goto x86_l_2fe1;
	case 12259ULL: goto x86_l_2fe3;
	case 12262ULL: goto x86_l_2fe6;
	case 12266ULL: goto x86_l_2fea;
	case 12270ULL: goto x86_l_2fee;
	case 12274ULL: goto x86_l_2ff2;
	case 12277ULL: goto x86_l_2ff5;
	case 12285ULL: goto x86_l_2ffd;
	case 12292ULL: goto x86_l_3004;
	case 12297ULL: goto x86_l_3009;
	case 12302ULL: goto x86_l_300e;
	case 12308ULL: goto x86_l_3014;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12318ULL: goto x86_l_301e;
	case 12324ULL: goto x86_l_3024;
	case 12330ULL: goto x86_l_302a;
	case 12336ULL: goto x86_l_3030;
	case 12338ULL: goto x86_l_3032;
	case 12340ULL: goto x86_l_3034;
	case 12343ULL: goto x86_l_3037;
	case 12347ULL: goto x86_l_303b;
	case 12351ULL: goto x86_l_303f;
	case 12355ULL: goto x86_l_3043;
	case 12358ULL: goto x86_l_3046;
	case 12366ULL: goto x86_l_304e;
	case 12373ULL: goto x86_l_3055;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12391ULL: goto x86_l_3067;
	case 12393ULL: goto x86_l_3069;
	case 12399ULL: goto x86_l_306f;
	case 12405ULL: goto x86_l_3075;
	case 12411ULL: goto x86_l_307b;
	case 12413ULL: goto x86_l_307d;
	case 12415ULL: goto x86_l_307f;
	case 12418ULL: goto x86_l_3082;
	case 12422ULL: goto x86_l_3086;
	case 12426ULL: goto x86_l_308a;
	case 12430ULL: goto x86_l_308e;
	case 12433ULL: goto x86_l_3091;
	case 12441ULL: goto x86_l_3099;
	case 12448ULL: goto x86_l_30a0;
	case 12453ULL: goto x86_l_30a5;
	case 12458ULL: goto x86_l_30aa;
	case 12464ULL: goto x86_l_30b0;
	case 12469ULL: goto x86_l_30b5;
	case 12472ULL: goto x86_l_30b8;
	case 12474ULL: goto x86_l_30ba;
	case 12480ULL: goto x86_l_30c0;
	case 12486ULL: goto x86_l_30c6;
	case 12492ULL: goto x86_l_30cc;
	case 12494ULL: goto x86_l_30ce;
	case 12496ULL: goto x86_l_30d0;
	case 12499ULL: goto x86_l_30d3;
	case 12503ULL: goto x86_l_30d7;
	case 12507ULL: goto x86_l_30db;
	case 12511ULL: goto x86_l_30df;
	case 12514ULL: goto x86_l_30e2;
	case 12522ULL: goto x86_l_30ea;
	case 12529ULL: goto x86_l_30f1;
	case 12534ULL: goto x86_l_30f6;
	case 12539ULL: goto x86_l_30fb;
	case 12544ULL: goto x86_l_3100;
	case 12547ULL: goto x86_l_3103;
	case 12549ULL: goto x86_l_3105;
	case 12555ULL: goto x86_l_310b;
	case 12561ULL: goto x86_l_3111;
	case 12567ULL: goto x86_l_3117;
	case 12569ULL: goto x86_l_3119;
	case 12571ULL: goto x86_l_311b;
	case 12574ULL: goto x86_l_311e;
	case 12578ULL: goto x86_l_3122;
	case 12582ULL: goto x86_l_3126;
	case 12586ULL: goto x86_l_312a;
	case 12589ULL: goto x86_l_312d;
	case 12597ULL: goto x86_l_3135;
	case 12604ULL: goto x86_l_313c;
	case 12609ULL: goto x86_l_3141;
	case 12614ULL: goto x86_l_3146;
	case 12620ULL: goto x86_l_314c;
	case 12625ULL: goto x86_l_3151;
	case 12628ULL: goto x86_l_3154;
	case 12630ULL: goto x86_l_3156;
	case 12636ULL: goto x86_l_315c;
	case 12642ULL: goto x86_l_3162;
	case 12648ULL: goto x86_l_3168;
	case 12650ULL: goto x86_l_316a;
	case 12652ULL: goto x86_l_316c;
	case 12655ULL: goto x86_l_316f;
	case 12659ULL: goto x86_l_3173;
	case 12663ULL: goto x86_l_3177;
	case 12667ULL: goto x86_l_317b;
	case 12670ULL: goto x86_l_317e;
	case 12678ULL: goto x86_l_3186;
	case 12685ULL: goto x86_l_318d;
	case 12690ULL: goto x86_l_3192;
	case 12695ULL: goto x86_l_3197;
	case 12700ULL: goto x86_l_319c;
	case 12703ULL: goto x86_l_319f;
	case 12705ULL: goto x86_l_31a1;
	case 12711ULL: goto x86_l_31a7;
	case 12717ULL: goto x86_l_31ad;
	case 12723ULL: goto x86_l_31b3;
	case 12725ULL: goto x86_l_31b5;
	case 12727ULL: goto x86_l_31b7;
	case 12730ULL: goto x86_l_31ba;
	case 12734ULL: goto x86_l_31be;
	case 12738ULL: goto x86_l_31c2;
	case 12742ULL: goto x86_l_31c6;
	case 12745ULL: goto x86_l_31c9;
	case 12753ULL: goto x86_l_31d1;
	case 12760ULL: goto x86_l_31d8;
	case 12765ULL: goto x86_l_31dd;
	case 12770ULL: goto x86_l_31e2;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12784ULL: goto x86_l_31f0;
	case 12786ULL: goto x86_l_31f2;
	case 12792ULL: goto x86_l_31f8;
	case 12798ULL: goto x86_l_31fe;
	case 12804ULL: goto x86_l_3204;
	case 12806ULL: goto x86_l_3206;
	case 12808ULL: goto x86_l_3208;
	case 12811ULL: goto x86_l_320b;
	case 12815ULL: goto x86_l_320f;
	case 12818ULL: goto x86_l_3212;
	case 12821ULL: goto x86_l_3215;
	case 12823ULL: goto x86_l_3217;
	case 12830ULL: goto x86_l_321e;
	case 12837ULL: goto x86_l_3225;
	case 12842ULL: goto x86_l_322a;
	case 12847ULL: goto x86_l_322f;
	case 12852ULL: goto x86_l_3234;
	case 12855ULL: goto x86_l_3237;
	case 12857ULL: goto x86_l_3239;
	case 12863ULL: goto x86_l_323f;
	case 12871ULL: goto x86_l_3247;
	case 12878ULL: goto x86_l_324e;
	case 12883ULL: goto x86_l_3253;
	case 12888ULL: goto x86_l_3258;
	case 12890ULL: goto x86_l_325a;
	case 12893ULL: goto x86_l_325d;
	case 12895ULL: goto x86_l_325f;
	case 12897ULL: goto x86_l_3261;
	case 12902ULL: goto x86_l_3266;
	case 12909ULL: goto x86_l_326d;
	case 12914ULL: goto x86_l_3272;
	case 12917ULL: goto x86_l_3275;
	case 12920ULL: goto x86_l_3278;
	case 12925ULL: goto x86_l_327d;
	case 12931ULL: goto x86_l_3283;
	case 12934ULL: goto x86_l_3286;
	case 12939ULL: goto x86_l_328b;
	case 12945ULL: goto x86_l_3291;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12959ULL: goto x86_l_329f;
	case 12962ULL: goto x86_l_32a2;
	case 12967ULL: goto x86_l_32a7;
	case 12973ULL: goto x86_l_32ad;
	case 12976ULL: goto x86_l_32b0;
	case 12981ULL: goto x86_l_32b5;
	case 12987ULL: goto x86_l_32bb;
	case 12990ULL: goto x86_l_32be;
	case 12995ULL: goto x86_l_32c3;
	case 13001ULL: goto x86_l_32c9;
	case 13004ULL: goto x86_l_32cc;
	case 13009ULL: goto x86_l_32d1;
	case 13014ULL: goto x86_l_32d6;
	case 13016ULL: goto x86_l_32d8;
	case 13018ULL: goto x86_l_32da;
	case 13022ULL: goto x86_l_32de;
	case 13032ULL: goto x86_l_32e8;
	case 13035ULL: goto x86_l_32eb;
	case 13040ULL: goto x86_l_32f0;
	case 13044ULL: goto x86_l_32f4;
	case 13048ULL: goto x86_l_32f8;
	case 13055ULL: goto x86_l_32ff;
	case 13060ULL: goto x86_l_3304;
	case 13063ULL: goto x86_l_3307;
	case 13066ULL: goto x86_l_330a;
	case 13068ULL: goto x86_l_330c;
	case 13070ULL: goto x86_l_330e;
	case 13072ULL: goto x86_l_3310;
	case 13077ULL: goto x86_l_3315;
	case 13079ULL: goto x86_l_3317;
	case 13084ULL: goto x86_l_331c;
	case 13086ULL: goto x86_l_331e;
	case 13091ULL: goto x86_l_3323;
	case 13096ULL: goto x86_l_3328;
	case 13099ULL: goto x86_l_332b;
	case 13105ULL: goto x86_l_3331;
	case 13107ULL: goto x86_l_3333;
	case 13112ULL: goto x86_l_3338;
	case 13118ULL: goto x86_l_333e;
	case 13121ULL: goto x86_l_3341;
	case 13126ULL: goto x86_l_3346;
	case 13132ULL: goto x86_l_334c;
	case 13135ULL: goto x86_l_334f;
	case 13140ULL: goto x86_l_3354;
	case 13146ULL: goto x86_l_335a;
	case 13149ULL: goto x86_l_335d;
	case 13154ULL: goto x86_l_3362;
	case 13160ULL: goto x86_l_3368;
	case 13163ULL: goto x86_l_336b;
	case 13168ULL: goto x86_l_3370;
	case 13174ULL: goto x86_l_3376;
	case 13177ULL: goto x86_l_3379;
	case 13182ULL: goto x86_l_337e;
	case 13188ULL: goto x86_l_3384;
	case 13191ULL: goto x86_l_3387;
	case 13196ULL: goto x86_l_338c;
	case 13202ULL: goto x86_l_3392;
	case 13205ULL: goto x86_l_3395;
	case 13210ULL: goto x86_l_339a;
	case 13216ULL: goto x86_l_33a0;
	case 13219ULL: goto x86_l_33a3;
	case 13224ULL: goto x86_l_33a8;
	case 13230ULL: goto x86_l_33ae;
	case 13233ULL: goto x86_l_33b1;
	case 13238ULL: goto x86_l_33b6;
	case 13244ULL: goto x86_l_33bc;
	case 13249ULL: goto x86_l_33c1;
	case 13255ULL: goto x86_l_33c7;
	case 13257ULL: goto x86_l_33c9;
	case 13262ULL: goto x86_l_33ce;
	case 13264ULL: goto x86_l_33d0;
	case 13269ULL: goto x86_l_33d5;
	case 13274ULL: goto x86_l_33da;
	case 13280ULL: goto x86_l_33e0;
	case 13282ULL: goto x86_l_33e2;
	case 13288ULL: goto x86_l_33e8;
	case 13290ULL: goto x86_l_33ea;
	case 13296ULL: goto x86_l_33f0;
	case 13298ULL: goto x86_l_33f2;
	case 13304ULL: goto x86_l_33f8;
	case 13306ULL: goto x86_l_33fa;
	case 13312ULL: goto x86_l_3400;
	case 13314ULL: goto x86_l_3402;
	case 13320ULL: goto x86_l_3408;
	case 13322ULL: goto x86_l_340a;
	case 13328ULL: goto x86_l_3410;
	case 13330ULL: goto x86_l_3412;
	case 13336ULL: goto x86_l_3418;
	case 13338ULL: goto x86_l_341a;
	case 13344ULL: goto x86_l_3420;
	case 13346ULL: goto x86_l_3422;
	case 13352ULL: goto x86_l_3428;
	case 13354ULL: goto x86_l_342a;
	case 13360ULL: goto x86_l_3430;
	case 13362ULL: goto x86_l_3432;
	case 13368ULL: goto x86_l_3438;
	case 13370ULL: goto x86_l_343a;
	case 13376ULL: goto x86_l_3440;
	case 13378ULL: goto x86_l_3442;
	case 13384ULL: goto x86_l_3448;
	case 13387ULL: goto x86_l_344b;
	case 13392ULL: goto x86_l_3450;
	case 13399ULL: goto x86_l_3457;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13411ULL: goto x86_l_3463;
	case 13414ULL: goto x86_l_3466;
	case 13416ULL: goto x86_l_3468;
	case 13418ULL: goto x86_l_346a;
	case 13423ULL: goto x86_l_346f;
	case 13428ULL: goto x86_l_3474;
	case 13432ULL: goto x86_l_3478;
	case 13437ULL: goto x86_l_347d;
	case 13441ULL: goto x86_l_3481;
	case 13448ULL: goto x86_l_3488;
	case 13453ULL: goto x86_l_348d;
	case 13456ULL: goto x86_l_3490;
	case 13459ULL: goto x86_l_3493;
	case 13461ULL: goto x86_l_3495;
	case 13463ULL: goto x86_l_3497;
	case 13465ULL: goto x86_l_3499;
	case 13472ULL: goto x86_l_34a0;
	case 13474ULL: goto x86_l_34a2;
	case 13477ULL: goto x86_l_34a5;
	case 13484ULL: goto x86_l_34ac;
	case 13489ULL: goto x86_l_34b1;
	case 13494ULL: goto x86_l_34b6;
	case 13496ULL: goto x86_l_34b8;
	case 13501ULL: goto x86_l_34bd;
	case 13506ULL: goto x86_l_34c2;
	case 13509ULL: goto x86_l_34c5;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2e45:
	/* 0x2e45: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2e48:
	/* 0x2e48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e4a:
	/* 0x2e4a: je     33da <snat_v6_nat+0x1f38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33da;
	}
x86_l_2e50:
	/* 0x2e50: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2e56:
	/* 0x2e56: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2e5c:
	/* 0x2e5c: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2e5e:
	/* 0x2e5e: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e60:
	/* 0x2e60: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e63:
	/* 0x2e63: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e67:
	/* 0x2e67: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2e6b:
	/* 0x2e6b: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2e6f:
	/* 0x2e6f: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e72:
	/* 0x2e72: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2e7a:
	/* 0x2e7a: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2e81:
	/* 0x2e81: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e86:
	/* 0x2e86: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e8b:
	/* 0x2e8b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e90:
	/* 0x2e90: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2e93:
	/* 0x2e93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e95:
	/* 0x2e95: je     33e2 <snat_v6_nat+0x1f40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33e2;
	}
x86_l_2e9b:
	/* 0x2e9b: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2ea1:
	/* 0x2ea1: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2ea7:
	/* 0x2ea7: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2ea9:
	/* 0x2ea9: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2eab:
	/* 0x2eab: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2eae:
	/* 0x2eae: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2eb2:
	/* 0x2eb2: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2eb6:
	/* 0x2eb6: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2eba:
	/* 0x2eba: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ebd:
	/* 0x2ebd: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2ec5:
	/* 0x2ec5: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2ecc:
	/* 0x2ecc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed1:
	/* 0x2ed1: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ed6:
	/* 0x2ed6: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2edc:
	/* 0x2edc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ee1:
	/* 0x2ee1: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2ee4:
	/* 0x2ee4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ee6:
	/* 0x2ee6: je     33ea <snat_v6_nat+0x1f48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33ea;
	}
x86_l_2eec:
	/* 0x2eec: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2ef2:
	/* 0x2ef2: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2ef8:
	/* 0x2ef8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2efa:
	/* 0x2efa: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2efc:
	/* 0x2efc: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2eff:
	/* 0x2eff: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f03:
	/* 0x2f03: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2f07:
	/* 0x2f07: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2f0b:
	/* 0x2f0b: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f0e:
	/* 0x2f0e: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2f16:
	/* 0x2f16: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2f1d:
	/* 0x2f1d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f22:
	/* 0x2f22: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f27:
	/* 0x2f27: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f2c:
	/* 0x2f2c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2f2f:
	/* 0x2f2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f31:
	/* 0x2f31: je     33f2 <snat_v6_nat+0x1f50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33f2;
	}
x86_l_2f37:
	/* 0x2f37: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2f3d:
	/* 0x2f3d: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2f43:
	/* 0x2f43: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f45:
	/* 0x2f45: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f47:
	/* 0x2f47: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f4a:
	/* 0x2f4a: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f4e:
	/* 0x2f4e: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2f52:
	/* 0x2f52: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2f56:
	/* 0x2f56: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f59:
	/* 0x2f59: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2f61:
	/* 0x2f61: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2f68:
	/* 0x2f68: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6d:
	/* 0x2f6d: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2f72:
	/* 0x2f72: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2f78:
	/* 0x2f78: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f7d:
	/* 0x2f7d: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2f80:
	/* 0x2f80: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f82:
	/* 0x2f82: je     33fa <snat_v6_nat+0x1f58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33fa;
	}
x86_l_2f88:
	/* 0x2f88: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2f8e:
	/* 0x2f8e: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2f94:
	/* 0x2f94: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f96:
	/* 0x2f96: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f98:
	/* 0x2f98: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2f9b:
	/* 0x2f9b: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f9f:
	/* 0x2f9f: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2fa3:
	/* 0x2fa3: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2fa7:
	/* 0x2fa7: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2faa:
	/* 0x2faa: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2fb2:
	/* 0x2fb2: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2fb9:
	/* 0x2fb9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fbe:
	/* 0x2fbe: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2fc3:
	/* 0x2fc3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2fc8:
	/* 0x2fc8: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2fcb:
	/* 0x2fcb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fcd:
	/* 0x2fcd: je     3402 <snat_v6_nat+0x1f60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3402;
	}
x86_l_2fd3:
	/* 0x2fd3: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2fd9:
	/* 0x2fd9: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2fdf:
	/* 0x2fdf: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2fe1:
	/* 0x2fe1: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fe3:
	/* 0x2fe3: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2fe6:
	/* 0x2fe6: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2fea:
	/* 0x2fea: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2fee:
	/* 0x2fee: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2ff2:
	/* 0x2ff2: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ff5:
	/* 0x2ff5: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_2ffd:
	/* 0x2ffd: mov    rdi,QWORD PTR [rip+0x6b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_3004:
	/* 0x3004: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3009:
	/* 0x3009: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_300e:
	/* 0x300e: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_3014:
	/* 0x3014: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3019:
	/* 0x3019: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_301c:
	/* 0x301c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_301e:
	/* 0x301e: je     340a <snat_v6_nat+0x1f68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_340a;
	}
x86_l_3024:
	/* 0x3024: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_302a:
	/* 0x302a: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_3030:
	/* 0x3030: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3032:
	/* 0x3032: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3034:
	/* 0x3034: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3037:
	/* 0x3037: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_303b:
	/* 0x303b: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_303f:
	/* 0x303f: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3043:
	/* 0x3043: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3046:
	/* 0x3046: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_304e:
	/* 0x304e: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_3055:
	/* 0x3055: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_305a:
	/* 0x305a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_305f:
	/* 0x305f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3064:
	/* 0x3064: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_3067:
	/* 0x3067: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3069:
	/* 0x3069: je     3412 <snat_v6_nat+0x1f70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3412;
	}
x86_l_306f:
	/* 0x306f: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_3075:
	/* 0x3075: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_307b:
	/* 0x307b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_307d:
	/* 0x307d: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_307f:
	/* 0x307f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3082:
	/* 0x3082: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3086:
	/* 0x3086: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_308a:
	/* 0x308a: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_308e:
	/* 0x308e: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3091:
	/* 0x3091: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_3099:
	/* 0x3099: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_30a0:
	/* 0x30a0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30a5:
	/* 0x30a5: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30aa:
	/* 0x30aa: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_30b0:
	/* 0x30b0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_30b5:
	/* 0x30b5: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_30b8:
	/* 0x30b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30ba:
	/* 0x30ba: je     341a <snat_v6_nat+0x1f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_341a;
	}
x86_l_30c0:
	/* 0x30c0: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_30c6:
	/* 0x30c6: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_30cc:
	/* 0x30cc: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_30ce:
	/* 0x30ce: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30d0:
	/* 0x30d0: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_30d3:
	/* 0x30d3: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_30d7:
	/* 0x30d7: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_30db:
	/* 0x30db: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_30df:
	/* 0x30df: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_30e2:
	/* 0x30e2: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_30ea:
	/* 0x30ea: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_30f1:
	/* 0x30f1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30f6:
	/* 0x30f6: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_30fb:
	/* 0x30fb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3100:
	/* 0x3100: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_3103:
	/* 0x3103: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3105:
	/* 0x3105: je     3422 <snat_v6_nat+0x1f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3422;
	}
x86_l_310b:
	/* 0x310b: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_3111:
	/* 0x3111: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_3117:
	/* 0x3117: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3119:
	/* 0x3119: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_311b:
	/* 0x311b: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_311e:
	/* 0x311e: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3122:
	/* 0x3122: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_3126:
	/* 0x3126: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_312a:
	/* 0x312a: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_312d:
	/* 0x312d: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_3135:
	/* 0x3135: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_313c:
	/* 0x313c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3141:
	/* 0x3141: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3146:
	/* 0x3146: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_314c:
	/* 0x314c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3151:
	/* 0x3151: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_3154:
	/* 0x3154: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3156:
	/* 0x3156: je     342a <snat_v6_nat+0x1f88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_342a;
	}
x86_l_315c:
	/* 0x315c: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_3162:
	/* 0x3162: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_3168:
	/* 0x3168: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_316a:
	/* 0x316a: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_316c:
	/* 0x316c: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_316f:
	/* 0x316f: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3173:
	/* 0x3173: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_3177:
	/* 0x3177: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_317b:
	/* 0x317b: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_317e:
	/* 0x317e: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_3186:
	/* 0x3186: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_318d:
	/* 0x318d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3192:
	/* 0x3192: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3197:
	/* 0x3197: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_319c:
	/* 0x319c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_319f:
	/* 0x319f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31a1:
	/* 0x31a1: je     3432 <snat_v6_nat+0x1f90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3432;
	}
x86_l_31a7:
	/* 0x31a7: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_31ad:
	/* 0x31ad: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_31b3:
	/* 0x31b3: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_31b5:
	/* 0x31b5: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_31b7:
	/* 0x31b7: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_31ba:
	/* 0x31ba: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_31be:
	/* 0x31be: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_31c2:
	/* 0x31c2: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_31c6:
	/* 0x31c6: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_31c9:
	/* 0x31c9: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_31d1:
	/* 0x31d1: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_31d8:
	/* 0x31d8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31dd:
	/* 0x31dd: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31e2:
	/* 0x31e2: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_31e8:
	/* 0x31e8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_31ed:
	/* 0x31ed: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_31f0:
	/* 0x31f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31f2:
	/* 0x31f2: je     343a <snat_v6_nat+0x1f98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_343a;
	}
x86_l_31f8:
	/* 0x31f8: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_31fe:
	/* 0x31fe: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_3204:
	/* 0x3204: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3206:
	/* 0x3206: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3208:
	/* 0x3208: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_320b:
	/* 0x320b: movzx  edx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_320f:
	/* 0x320f: imul   edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_3212:
	/* 0x3212: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3215:
	/* 0x3215: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3217:
	/* 0x3217: movbe  WORD PTR [rsp+0x30],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_321e:
	/* 0x321e: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_3225:
	/* 0x3225: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_322a:
	/* 0x322a: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_322f:
	/* 0x322f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3234:
	/* 0x3234: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_3237:
	/* 0x3237: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3239:
	/* 0x3239: je     3442 <snat_v6_nat+0x1fa0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3442;
	}
x86_l_323f:
	/* 0x323f: mov    DWORD PTR [rsp+0x8],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_3247:
	/* 0x3247: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_324e:
	/* 0x324e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3253:
	/* 0x3253: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3258:
	/* 0x3258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325a:
	/* 0x325a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_325d:
	/* 0x325d: je     3261 <snat_v6_nat+0x1dbf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3261;
	}
x86_l_325f:
	/* 0x325f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3261:
	/* 0x3261: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_3266:
	/* 0x3266: mov    r15,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_326d:
	/* 0x326d: jmp    34cf <snat_v6_nat+0x202d> */
	return 13519ULL;
x86_l_3272:
	/* 0x3272: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3275:
	/* 0x3275: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3278:
	/* 0x3278: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_327d:
	/* 0x327d: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_3283:
	/* 0x3283: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3286:
	/* 0x3286: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_328b:
	/* 0x328b: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_3291:
	/* 0x3291: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3294:
	/* 0x3294: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_3299:
	/* 0x3299: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_329f:
	/* 0x329f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32a2:
	/* 0x32a2: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_32a7:
	/* 0x32a7: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_32ad:
	/* 0x32ad: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32b0:
	/* 0x32b0: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_32b5:
	/* 0x32b5: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_32bb:
	/* 0x32bb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32be:
	/* 0x32be: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_32c3:
	/* 0x32c3: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_32c9:
	/* 0x32c9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32cc:
	/* 0x32cc: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_32d1:
	/* 0x32d1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_32d6:
	/* 0x32d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32d8:
	/* 0x32d8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_32da:
	/* 0x32da: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_32de:
	/* 0x32de: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_32e8:
	/* 0x32e8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_32eb:
	/* 0x32eb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_32f0:
	/* 0x32f0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_32f4:
	/* 0x32f4: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32f8:
	/* 0x32f8: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_32ff:
	/* 0x32ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3304:
	/* 0x3304: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3307:
	/* 0x3307: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_330a:
	/* 0x330a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_330c:
	/* 0x330c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330e:
	/* 0x330e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3310:
	/* 0x3310: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3315:
	/* 0x3315: js     331c <snat_v6_nat+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_331c;
	}
x86_l_3317:
	/* 0x3317: jmp    3518 <snat_v6_nat+0x2076> */
	return 13592ULL;
x86_l_331c:
	/* 0x331c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_331e:
	/* 0x331e: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_3323:
	/* 0x3323: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3328:
	/* 0x3328: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_332b:
	/* 0x332b: je     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5399ULL;
	}
x86_l_3331:
	/* 0x3331: mov    BYTE PTR [rdx],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3333:
	/* 0x3333: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_3338:
	/* 0x3338: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_333e:
	/* 0x333e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3341:
	/* 0x3341: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_3346:
	/* 0x3346: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_334c:
	/* 0x334c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_334f:
	/* 0x334f: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_3354:
	/* 0x3354: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_335a:
	/* 0x335a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_335d:
	/* 0x335d: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_3362:
	/* 0x3362: mov    r14d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 11ULL);
x86_l_3368:
	/* 0x3368: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_336b:
	/* 0x336b: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_3370:
	/* 0x3370: mov    r14d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 12ULL);
x86_l_3376:
	/* 0x3376: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3379:
	/* 0x3379: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_337e:
	/* 0x337e: mov    r14d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 13ULL);
x86_l_3384:
	/* 0x3384: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3387:
	/* 0x3387: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_338c:
	/* 0x338c: mov    r14d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 14ULL);
x86_l_3392:
	/* 0x3392: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3395:
	/* 0x3395: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_339a:
	/* 0x339a: mov    r14d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 15ULL);
x86_l_33a0:
	/* 0x33a0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a3:
	/* 0x33a3: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_33a8:
	/* 0x33a8: mov    r14d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16ULL);
x86_l_33ae:
	/* 0x33ae: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33b1:
	/* 0x33b1: jmp    344b <snat_v6_nat+0x1fa9> */
	goto x86_l_344b;
x86_l_33b6:
	/* 0x33b6: mov    r14d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 17ULL);
x86_l_33bc:
	/* 0x33bc: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_33c1:
	/* 0x33c1: cmp    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_33c7:
	/* 0x33c7: je     33d0 <snat_v6_nat+0x1f2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d0;
	}
x86_l_33c9:
	/* 0x33c9: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_33ce:
	/* 0x33ce: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d0:
	/* 0x33d0: mov    eax,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967141ULL);
x86_l_33d5:
	/* 0x33d5: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_33da:
	/* 0x33da: mov    r14d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 18ULL);
x86_l_33e0:
	/* 0x33e0: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_33e2:
	/* 0x33e2: mov    r14d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 19ULL);
x86_l_33e8:
	/* 0x33e8: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_33ea:
	/* 0x33ea: mov    r14d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 20ULL);
x86_l_33f0:
	/* 0x33f0: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_33f2:
	/* 0x33f2: mov    r14d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21ULL);
x86_l_33f8:
	/* 0x33f8: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_33fa:
	/* 0x33fa: mov    r14d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 22ULL);
x86_l_3400:
	/* 0x3400: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_3402:
	/* 0x3402: mov    r14d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 23ULL);
x86_l_3408:
	/* 0x3408: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_340a:
	/* 0x340a: mov    r14d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 24ULL);
x86_l_3410:
	/* 0x3410: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_3412:
	/* 0x3412: mov    r14d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 25ULL);
x86_l_3418:
	/* 0x3418: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_341a:
	/* 0x341a: mov    r14d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 26ULL);
x86_l_3420:
	/* 0x3420: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_3422:
	/* 0x3422: mov    r14d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 27ULL);
x86_l_3428:
	/* 0x3428: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_342a:
	/* 0x342a: mov    r14d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 28ULL);
x86_l_3430:
	/* 0x3430: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_3432:
	/* 0x3432: mov    r14d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 29ULL);
x86_l_3438:
	/* 0x3438: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_343a:
	/* 0x343a: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_3440:
	/* 0x3440: jmp    3448 <snat_v6_nat+0x1fa6> */
	goto x86_l_3448;
x86_l_3442:
	/* 0x3442: mov    r14d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 31ULL);
x86_l_3448:
	/* 0x3448: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_344b:
	/* 0x344b: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3450:
	/* 0x3450: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_3457:
	/* 0x3457: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_345c:
	/* 0x345c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3461:
	/* 0x3461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3463:
	/* 0x3463: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3466:
	/* 0x3466: je     346a <snat_v6_nat+0x1fc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_346a;
	}
x86_l_3468:
	/* 0x3468: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_346a:
	/* 0x346a: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_346f:
	/* 0x346f: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3474:
	/* 0x3474: mov    WORD PTR [rbp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3478:
	/* 0x3478: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_347d:
	/* 0x347d: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3481:
	/* 0x3481: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_3488:
	/* 0x3488: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_348d:
	/* 0x348d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_3490:
	/* 0x3490: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3493:
	/* 0x3493: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3495:
	/* 0x3495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3497:
	/* 0x3497: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3499:
	/* 0x3499: mov    r15,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_34a0:
	/* 0x34a0: jns    34ca <snat_v6_nat+0x2028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_34ca;
	}
x86_l_34a2:
	/* 0x34a2: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_34a5:
	/* 0x34a5: mov    rdi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_34ac:
	/* 0x34ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34b1:
	/* 0x34b1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_34b6:
	/* 0x34b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34b8:
	/* 0x34b8: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_34bd:
	/* 0x34bd: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34c2:
	/* 0x34c2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_34c5:
	/* 0x34c5: je     34ca <snat_v6_nat+0x2028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34ca;
	}
x86_l_34c7:
	/* 0x34c7: mov    BYTE PTR [rcx],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ca:
	/* 0x34ca: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
	return 13517ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13517ULL: goto x86_l_34cd;
	case 13519ULL: goto x86_l_34cf;
	case 13529ULL: goto x86_l_34d9;
	case 13537ULL: goto x86_l_34e1;
	case 13544ULL: goto x86_l_34e8;
	case 13552ULL: goto x86_l_34f0;
	case 13558ULL: goto x86_l_34f6;
	case 13563ULL: goto x86_l_34fb;
	case 13566ULL: goto x86_l_34fe;
	case 13572ULL: goto x86_l_3504;
	case 13574ULL: goto x86_l_3506;
	case 13577ULL: goto x86_l_3509;
	case 13579ULL: goto x86_l_350b;
	case 13584ULL: goto x86_l_3510;
	case 13586ULL: goto x86_l_3512;
	case 13592ULL: goto x86_l_3518;
	case 13595ULL: goto x86_l_351b;
	case 13600ULL: goto x86_l_3520;
	case 13606ULL: goto x86_l_3526;
	case 13611ULL: goto x86_l_352b;
	case 13617ULL: goto x86_l_3531;
	case 13622ULL: goto x86_l_3536;
	case 13626ULL: goto x86_l_353a;
	case 13630ULL: goto x86_l_353e;
	case 13632ULL: goto x86_l_3540;
	case 13636ULL: goto x86_l_3544;
	case 13640ULL: goto x86_l_3548;
	case 13642ULL: goto x86_l_354a;
	case 13646ULL: goto x86_l_354e;
	case 13648ULL: goto x86_l_3550;
	case 13653ULL: goto x86_l_3555;
	case 13659ULL: goto x86_l_355b;
	case 13661ULL: goto x86_l_355d;
	case 13665ULL: goto x86_l_3561;
	case 13669ULL: goto x86_l_3565;
	case 13673ULL: goto x86_l_3569;
	case 13677ULL: goto x86_l_356d;
	case 13681ULL: goto x86_l_3571;
	case 13686ULL: goto x86_l_3576;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13697ULL: goto x86_l_3581;
	case 13702ULL: goto x86_l_3586;
	case 13705ULL: goto x86_l_3589;
	case 13707ULL: goto x86_l_358b;
	case 13710ULL: goto x86_l_358e;
	case 13714ULL: goto x86_l_3592;
	case 13719ULL: goto x86_l_3597;
	case 13722ULL: goto x86_l_359a;
	case 13725ULL: goto x86_l_359d;
	case 13728ULL: goto x86_l_35a0;
	case 13733ULL: goto x86_l_35a5;
	case 13736ULL: goto x86_l_35a8;
	case 13738ULL: goto x86_l_35aa;
	case 13740ULL: goto x86_l_35ac;
	case 13743ULL: goto x86_l_35af;
	case 13748ULL: goto x86_l_35b4;
	case 13758ULL: goto x86_l_35be;
	case 13766ULL: goto x86_l_35c6;
	case 13772ULL: goto x86_l_35cc;
	case 13774ULL: goto x86_l_35ce;
	case 13778ULL: goto x86_l_35d2;
	case 13784ULL: goto x86_l_35d8;
	case 13787ULL: goto x86_l_35db;
	case 13790ULL: goto x86_l_35de;
	case 13793ULL: goto x86_l_35e1;
	case 13795ULL: goto x86_l_35e3;
	case 13798ULL: goto x86_l_35e6;
	case 13800ULL: goto x86_l_35e8;
	case 13803ULL: goto x86_l_35eb;
	case 13805ULL: goto x86_l_35ed;
	case 13811ULL: goto x86_l_35f3;
	case 13813ULL: goto x86_l_35f5;
	case 13819ULL: goto x86_l_35fb;
	case 13825ULL: goto x86_l_3601;
	case 13827ULL: goto x86_l_3603;
	case 13833ULL: goto x86_l_3609;
	case 13836ULL: goto x86_l_360c;
	case 13839ULL: goto x86_l_360f;
	case 13841ULL: goto x86_l_3611;
	case 13844ULL: goto x86_l_3614;
	case 13847ULL: goto x86_l_3617;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13859ULL: goto x86_l_3623;
	case 13862ULL: goto x86_l_3626;
	case 13868ULL: goto x86_l_362c;
	case 13870ULL: goto x86_l_362e;
	case 13880ULL: goto x86_l_3638;
	case 13884ULL: goto x86_l_363c;
	case 13890ULL: goto x86_l_3642;
	case 13896ULL: goto x86_l_3648;
	case 13904ULL: goto x86_l_3650;
	case 13908ULL: goto x86_l_3654;
	case 13911ULL: goto x86_l_3657;
	case 13916ULL: goto x86_l_365c;
	case 13921ULL: goto x86_l_3661;
	case 13924ULL: goto x86_l_3664;
	case 13929ULL: goto x86_l_3669;
	case 13932ULL: goto x86_l_366c;
	case 13934ULL: goto x86_l_366e;
	case 13936ULL: goto x86_l_3670;
	case 13938ULL: goto x86_l_3672;
	case 13943ULL: goto x86_l_3677;
	case 13947ULL: goto x86_l_367b;
	case 13950ULL: goto x86_l_367e;
	case 13954ULL: goto x86_l_3682;
	case 13959ULL: goto x86_l_3687;
	case 13962ULL: goto x86_l_368a;
	case 13966ULL: goto x86_l_368e;
	case 13968ULL: goto x86_l_3690;
	case 13970ULL: goto x86_l_3692;
	case 13972ULL: goto x86_l_3694;
	case 13975ULL: goto x86_l_3697;
	case 13977ULL: goto x86_l_3699;
	case 13985ULL: goto x86_l_36a1;
	case 13989ULL: goto x86_l_36a5;
	case 13994ULL: goto x86_l_36aa;
	case 13997ULL: goto x86_l_36ad;
	case 14000ULL: goto x86_l_36b0;
	case 14002ULL: goto x86_l_36b2;
	case 14004ULL: goto x86_l_36b4;
	case 14007ULL: goto x86_l_36b7;
	case 14009ULL: goto x86_l_36b9;
	case 14011ULL: goto x86_l_36bb;
	case 14013ULL: goto x86_l_36bd;
	case 14015ULL: goto x86_l_36bf;
	case 14020ULL: goto x86_l_36c4;
	case 14025ULL: goto x86_l_36c9;
	case 14030ULL: goto x86_l_36ce;
	case 14035ULL: goto x86_l_36d3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_34cd:
	/* 0x34cd: je     3510 <snat_v6_nat+0x206e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3510;
	}
x86_l_34cf:
	/* 0x34cf: movabs rcx,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4294967296ULL);
x86_l_34d9:
	/* 0x34d9: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_34e1:
	/* 0x34e1: mov    rsi,QWORD PTR [rip+0x6a9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_34e8:
	/* 0x34e8: lea    rcx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_34f0:
	/* 0x34f0: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_34f6:
	/* 0x34f6: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_34fb:
	/* 0x34fb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_34fe:
	/* 0x34fe: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_3504:
	/* 0x3504: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3506:
	/* 0x3506: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_3509:
	/* 0x3509: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_350b:
	/* 0x350b: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3510:
	/* 0x3510: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3512:
	/* 0x3512: js     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5399ULL;
	}
x86_l_3518:
	/* 0x3518: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_351b:
	/* 0x351b: movzx  r14d,WORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_3520:
	/* 0x3520: movzx  esi,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_3526:
	/* 0x3526: movzx  r13d,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_352b:
	/* 0x352b: movzx  ecx,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_3531:
	/* 0x3531: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3536:
	/* 0x3536: cmp    rax,QWORD PTR [rbp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_353a:
	/* 0x353a: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_353e:
	/* 0x353e: jne    355d <snat_v6_nat+0x20bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_355d;
	}
x86_l_3540:
	/* 0x3540: cmp    cx,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_16);
x86_l_3544:
	/* 0x3544: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_3548:
	/* 0x3548: jne    3565 <snat_v6_nat+0x20c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3565;
	}
x86_l_354a:
	/* 0x354a: mov    rcx,QWORD PTR [rbp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_354e:
	/* 0x354e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3550:
	/* 0x3550: cmp    QWORD PTR [r12+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3555:
	/* 0x3555: je     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5399ULL;
	}
x86_l_355b:
	/* 0x355b: jmp    3565 <snat_v6_nat+0x20c3> */
	goto x86_l_3565;
x86_l_355d:
	/* 0x355d: cmp    cx,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_16);
x86_l_3561:
	/* 0x3561: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_3565:
	/* 0x3565: mov    DWORD PTR [rsp+0x38],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3569:
	/* 0x3569: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_356d:
	/* 0x356d: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3571:
	/* 0x3571: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_3576:
	/* 0x3576: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3579:
	/* 0x3579: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_357e:
	/* 0x357e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_3581:
	/* 0x3581: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3586:
	/* 0x3586: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3589:
	/* 0x3589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_358b:
	/* 0x358b: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_358e:
	/* 0x358e: add    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_3592:
	/* 0x3592: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3597:
	/* 0x3597: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_359a:
	/* 0x359a: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_359d:
	/* 0x359d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_35a0:
	/* 0x35a0: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_35a5:
	/* 0x35a5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35a8:
	/* 0x35a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35aa:
	/* 0x35aa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_35ac:
	/* 0x35ac: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_35af:
	/* 0x35af: and    eax,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_35b4:
	/* 0x35b4: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_35be:
	/* 0x35be: test   QWORD PTR [rsp+0xa0],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_35c6:
	/* 0x35c6: jne    1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5399ULL;
	}
x86_l_35cc:
	/* 0x35cc: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_35ce:
	/* 0x35ce: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_35d2:
	/* 0x35d2: js     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5399ULL;
	}
x86_l_35d8:
	/* 0x35d8: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_35db:
	/* 0x35db: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_35de:
	/* 0x35de: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_35e1:
	/* 0x35e1: je     3603 <snat_v6_nat+0x2161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3603;
	}
x86_l_35e3:
	/* 0x35e3: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_35e6:
	/* 0x35e6: je     35f5 <snat_v6_nat+0x2153> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35f5;
	}
x86_l_35e8:
	/* 0x35e8: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_35eb:
	/* 0x35eb: jne    3611 <snat_v6_nat+0x216f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3611;
	}
x86_l_35ed:
	/* 0x35ed: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_35f3:
	/* 0x35f3: jmp    3609 <snat_v6_nat+0x2167> */
	goto x86_l_3609;
x86_l_35f5:
	/* 0x35f5: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_35fb:
	/* 0x35fb: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_3601:
	/* 0x3601: jmp    360c <snat_v6_nat+0x216a> */
	goto x86_l_360c;
x86_l_3603:
	/* 0x3603: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_3609:
	/* 0x3609: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_360c:
	/* 0x360c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_360f:
	/* 0x360f: jmp    361a <snat_v6_nat+0x2178> */
	goto x86_l_361a;
x86_l_3611:
	/* 0x3611: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_3614:
	/* 0x3614: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3617:
	/* 0x3617: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_361a:
	/* 0x361a: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_361c:
	/* 0x361c: jne    3694 <snat_v6_nat+0x21f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3694;
	}
x86_l_361e:
	/* 0x361e: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_3623:
	/* 0x3623: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_3626:
	/* 0x3626: ja     1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5399ULL;
	}
x86_l_362c:
	/* 0x362c: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_362e:
	/* 0x362e: movabs rdx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_3638:
	/* 0x3638: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_363c:
	/* 0x363c: jae    1517 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5399ULL;
	}
x86_l_3642:
	/* 0x3642: mov    WORD PTR [rsp+0x50],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3648:
	/* 0x3648: mov    r14,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3650:
	/* 0x3650: mov    esi,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3654:
	/* 0x3654: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3657:
	/* 0x3657: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_365c:
	/* 0x365c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3661:
	/* 0x3661: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3664:
	/* 0x3664: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3669:
	/* 0x3669: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_366c:
	/* 0x366c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_366e:
	/* 0x366e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3670:
	/* 0x3670: js     36ce <snat_v6_nat+0x222c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36ce;
	}
x86_l_3672:
	/* 0x3672: movzx  ecx,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_3677:
	/* 0x3677: lea    esi,[r12+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_367b:
	/* 0x367b: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_367e:
	/* 0x367e: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_3682:
	/* 0x3682: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3687:
	/* 0x3687: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_368a:
	/* 0x368a: mov    edx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_368e:
	/* 0x368e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3690:
	/* 0x3690: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3692:
	/* 0x3692: js     36c4 <snat_v6_nat+0x2222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36c4;
	}
x86_l_3694:
	/* 0x3694: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_3697:
	/* 0x3697: jne    36bd <snat_v6_nat+0x221b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36bd;
	}
x86_l_3699:
	/* 0x3699: add    r12d,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_36a1:
	/* 0x36a1: or     r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_36a5:
	/* 0x36a5: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_36aa:
	/* 0x36aa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_36ad:
	/* 0x36ad: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_36b0:
	/* 0x36b0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36b2:
	/* 0x36b2: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_36b4:
	/* 0x36b4: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_36b7:
	/* 0x36b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b9:
	/* 0x36b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36bb:
	/* 0x36bb: js     36c4 <snat_v6_nat+0x2222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_36c4;
	}
x86_l_36bd:
	/* 0x36bd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36bf:
	/* 0x36bf: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_36c4:
	/* 0x36c4: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_36c9:
	/* 0x36c9: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
x86_l_36ce:
	/* 0x36ce: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_36d3:
	/* 0x36d3: jmp    1517 <snat_v6_nat+0x75> */
	return 5399ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12816U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1728ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1730ULL && __x86_pc <= 3432ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3437ULL && __x86_pc <= 5037ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5043ULL && __x86_pc <= 6870ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6872ULL && __x86_pc <= 8432ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8443ULL && __x86_pc <= 10221ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10226ULL && __x86_pc <= 11840ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11845ULL && __x86_pc <= 13514ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13517ULL && __x86_pc <= 14035ULL)
			__x86_pc = cilium_bpf_host_tail_handle_snat_fwd_ipv6_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

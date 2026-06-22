extern char __config_allow_icmp_frag_needed;
extern char __config_cilium_net_ifindex;
extern char __config_cluster_id_bits;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_icmp_rule;
extern char __config_enable_identity_mark;
extern char __config_enable_jiffies;
extern char __config_enable_netkit;
extern char __config_enable_policy_accounting;
extern char __config_enable_tproxy;
extern char __config_endpoint_id;
extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_interface_mac;
extern char __config_kernel_hz;
extern char __config_policy_deny_response_enabled;
extern char __config_policy_verdict_log_filter;
extern char __config_rt_info;
extern char __config_security_label;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char __config_tunnel_port;
extern char cilium_auth_map;
extern char cilium_call_policy;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_events;
extern char cilium_ipcache_v2;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_node_map_v2;
extern char cilium_nodeport_nat_buffer;
extern char cilium_percpu_trace_id;
extern char cilium_policy_v2;
extern char cilium_policystats;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_runtime_config;
extern char cilium_signals;
extern char cilium_tail_call_buffer4;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 27ULL: goto x86_l_1b;
	case 30ULL: goto x86_l_1e;
	case 33ULL: goto x86_l_21;
	case 35ULL: goto x86_l_23;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 45ULL: goto x86_l_2d;
	case 50ULL: goto x86_l_32;
	case 57ULL: goto x86_l_39;
	case 60ULL: goto x86_l_3c;
	case 67ULL: goto x86_l_43;
	case 74ULL: goto x86_l_4a;
	case 78ULL: goto x86_l_4e;
	case 85ULL: goto x86_l_55;
	case 92ULL: goto x86_l_5c;
	case 97ULL: goto x86_l_61;
	case 104ULL: goto x86_l_68;
	case 112ULL: goto x86_l_70;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 119ULL: goto x86_l_77;
	case 122ULL: goto x86_l_7a;
	case 130ULL: goto x86_l_82;
	case 134ULL: goto x86_l_86;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 154ULL: goto x86_l_9a;
	case 161ULL: goto x86_l_a1;
	case 169ULL: goto x86_l_a9;
	case 175ULL: goto x86_l_af;
	case 177ULL: goto x86_l_b1;
	case 179ULL: goto x86_l_b3;
	case 187ULL: goto x86_l_bb;
	case 189ULL: goto x86_l_bd;
	case 197ULL: goto x86_l_c5;
	case 199ULL: goto x86_l_c7;
	case 207ULL: goto x86_l_cf;
	case 212ULL: goto x86_l_d4;
	case 221ULL: goto x86_l_dd;
	case 228ULL: goto x86_l_e4;
	case 237ULL: goto x86_l_ed;
	case 245ULL: goto x86_l_f5;
	case 250ULL: goto x86_l_fa;
	case 254ULL: goto x86_l_fe;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 280ULL: goto x86_l_118;
	case 283ULL: goto x86_l_11b;
	case 286ULL: goto x86_l_11e;
	case 288ULL: goto x86_l_120;
	case 291ULL: goto x86_l_123;
	case 293ULL: goto x86_l_125;
	case 299ULL: goto x86_l_12b;
	case 304ULL: goto x86_l_130;
	case 311ULL: goto x86_l_137;
	case 319ULL: goto x86_l_13f;
	case 321ULL: goto x86_l_141;
	case 326ULL: goto x86_l_146;
	case 329ULL: goto x86_l_149;
	case 335ULL: goto x86_l_14f;
	case 338ULL: goto x86_l_152;
	case 342ULL: goto x86_l_156;
	case 348ULL: goto x86_l_15c;
	case 356ULL: goto x86_l_164;
	case 363ULL: goto x86_l_16b;
	case 366ULL: goto x86_l_16e;
	case 370ULL: goto x86_l_172;
	case 377ULL: goto x86_l_179;
	case 381ULL: goto x86_l_17d;
	case 385ULL: goto x86_l_181;
	case 390ULL: goto x86_l_186;
	case 393ULL: goto x86_l_189;
	case 396ULL: goto x86_l_18c;
	case 402ULL: goto x86_l_192;
	case 405ULL: goto x86_l_195;
	case 411ULL: goto x86_l_19b;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 440ULL: goto x86_l_1b8;
	case 447ULL: goto x86_l_1bf;
	case 449ULL: goto x86_l_1c1;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 462ULL: goto x86_l_1ce;
	case 470ULL: goto x86_l_1d6;
	case 475ULL: goto x86_l_1db;
	case 482ULL: goto x86_l_1e2;
	case 488ULL: goto x86_l_1e8;
	case 496ULL: goto x86_l_1f0;
	case 500ULL: goto x86_l_1f4;
	case 504ULL: goto x86_l_1f8;
	case 509ULL: goto x86_l_1fd;
	case 514ULL: goto x86_l_202;
	case 519ULL: goto x86_l_207;
	case 526ULL: goto x86_l_20e;
	case 531ULL: goto x86_l_213;
	case 537ULL: goto x86_l_219;
	case 541ULL: goto x86_l_21d;
	case 547ULL: goto x86_l_223;
	case 552ULL: goto x86_l_228;
	case 554ULL: goto x86_l_22a;
	case 557ULL: goto x86_l_22d;
	case 564ULL: goto x86_l_234;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 571ULL: goto x86_l_23b;
	case 575ULL: goto x86_l_23f;
	case 578ULL: goto x86_l_242;
	case 582ULL: goto x86_l_246;
	case 585ULL: goto x86_l_249;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 607ULL: goto x86_l_25f;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 625ULL: goto x86_l_271;
	case 631ULL: goto x86_l_277;
	case 636ULL: goto x86_l_27c;
	case 640ULL: goto x86_l_280;
	case 645ULL: goto x86_l_285;
	case 652ULL: goto x86_l_28c;
	case 657ULL: goto x86_l_291;
	case 659ULL: goto x86_l_293;
	case 662ULL: goto x86_l_296;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 671ULL: goto x86_l_29f;
	case 673ULL: goto x86_l_2a1;
	case 682ULL: goto x86_l_2aa;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 699ULL: goto x86_l_2bb;
	case 704ULL: goto x86_l_2c0;
	case 709ULL: goto x86_l_2c5;
	case 711ULL: goto x86_l_2c7;
	case 713ULL: goto x86_l_2c9;
	case 718ULL: goto x86_l_2ce;
	case 725ULL: goto x86_l_2d5;
	case 728ULL: goto x86_l_2d8;
	case 733ULL: goto x86_l_2dd;
	case 735ULL: goto x86_l_2df;
	case 741ULL: goto x86_l_2e5;
	case 744ULL: goto x86_l_2e8;
	case 751ULL: goto x86_l_2ef;
	case 753ULL: goto x86_l_2f1;
	case 754ULL: goto x86_l_2f2;
	case 759ULL: goto x86_l_2f7;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 777ULL: goto x86_l_309;
	case 779ULL: goto x86_l_30b;
	case 782ULL: goto x86_l_30e;
	case 786ULL: goto x86_l_312;
	case 788ULL: goto x86_l_314;
	case 795ULL: goto x86_l_31b;
	case 798ULL: goto x86_l_31e;
	case 801ULL: goto x86_l_321;
	case 807ULL: goto x86_l_327;
	case 809ULL: goto x86_l_329;
	case 815ULL: goto x86_l_32f;
	case 822ULL: goto x86_l_336;
	case 824ULL: goto x86_l_338;
	case 829ULL: goto x86_l_33d;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 847ULL: goto x86_l_34f;
	case 852ULL: goto x86_l_354;
	case 857ULL: goto x86_l_359;
	case 863ULL: goto x86_l_35f;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 873ULL: goto x86_l_369;
	case 876ULL: goto x86_l_36c;
	case 882ULL: goto x86_l_372;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 899ULL: goto x86_l_383;
	case 902ULL: goto x86_l_386;
	case 908ULL: goto x86_l_38c;
	case 916ULL: goto x86_l_394;
	case 921ULL: goto x86_l_399;
	case 928ULL: goto x86_l_3a0;
	case 933ULL: goto x86_l_3a5;
	case 935ULL: goto x86_l_3a7;
	case 938ULL: goto x86_l_3aa;
	case 944ULL: goto x86_l_3b0;
	case 947ULL: goto x86_l_3b3;
	case 952ULL: goto x86_l_3b8;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 968ULL: goto x86_l_3c8;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 982ULL: goto x86_l_3d6;
	case 990ULL: goto x86_l_3de;
	case 995ULL: goto x86_l_3e3;
	case 1002ULL: goto x86_l_3ea;
	case 1007ULL: goto x86_l_3ef;
	case 1009ULL: goto x86_l_3f1;
	case 1012ULL: goto x86_l_3f4;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1034ULL: goto x86_l_40a;
	case 1040ULL: goto x86_l_410;
	case 1049ULL: goto x86_l_419;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1060ULL: goto x86_l_424;
	case 1062ULL: goto x86_l_426;
	case 1068ULL: goto x86_l_42c;
	case 1073ULL: goto x86_l_431;
	case 1077ULL: goto x86_l_435;
	case 1079ULL: goto x86_l_437;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1094ULL: goto x86_l_446;
	case 1096ULL: goto x86_l_448;
	case 1098ULL: goto x86_l_44a;
	case 1104ULL: goto x86_l_450;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1121ULL: goto x86_l_461;
	case 1123ULL: goto x86_l_463;
	case 1131ULL: goto x86_l_46b;
	case 1133ULL: goto x86_l_46d;
	case 1138ULL: goto x86_l_472;
	case 1146ULL: goto x86_l_47a;
	case 1150ULL: goto x86_l_47e;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1169ULL: goto x86_l_491;
	case 1176ULL: goto x86_l_498;
	case 1181ULL: goto x86_l_49d;
	case 1187ULL: goto x86_l_4a3;
	case 1191ULL: goto x86_l_4a7;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1205ULL: goto x86_l_4b5;
	case 1207ULL: goto x86_l_4b7;
	case 1211ULL: goto x86_l_4bb;
	case 1220ULL: goto x86_l_4c4;
	case 1228ULL: goto x86_l_4cc;
	case 1234ULL: goto x86_l_4d2;
	case 1241ULL: goto x86_l_4d9;
	case 1244ULL: goto x86_l_4dc;
	case 1247ULL: goto x86_l_4df;
	case 1253ULL: goto x86_l_4e5;
	case 1261ULL: goto x86_l_4ed;
	case 1268ULL: goto x86_l_4f4;
	case 1275ULL: goto x86_l_4fb;
	case 1277ULL: goto x86_l_4fd;
	case 1285ULL: goto x86_l_505;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1294ULL: goto x86_l_50e;
	case 1296ULL: goto x86_l_510;
	case 1299ULL: goto x86_l_513;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1322ULL: goto x86_l_52a;
	case 1330ULL: goto x86_l_532;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1338ULL: goto x86_l_53a;
	case 1340ULL: goto x86_l_53c;
	case 1349ULL: goto x86_l_545;
	case 1354ULL: goto x86_l_54a;
	case 1361ULL: goto x86_l_551;
	case 1369ULL: goto x86_l_559;
	case 1374ULL: goto x86_l_55e;
	case 1377ULL: goto x86_l_561;
	case 1379ULL: goto x86_l_563;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1389ULL: goto x86_l_56d;
	case 1394ULL: goto x86_l_572;
	case 1401ULL: goto x86_l_579;
	case 1406ULL: goto x86_l_57e;
	case 1408ULL: goto x86_l_580;
	case 1411ULL: goto x86_l_583;
	case 1417ULL: goto x86_l_589;
	case 1420ULL: goto x86_l_58c;
	case 1423ULL: goto x86_l_58f;
	case 1426ULL: goto x86_l_592;
	case 1433ULL: goto x86_l_599;
	case 1439ULL: goto x86_l_59f;
	case 1442ULL: goto x86_l_5a2;
	case 1446ULL: goto x86_l_5a6;
	case 1456ULL: goto x86_l_5b0;
	case 1461ULL: goto x86_l_5b5;
	case 1465ULL: goto x86_l_5b9;
	case 1472ULL: goto x86_l_5c0;
	case 1476ULL: goto x86_l_5c4;
	case 1480ULL: goto x86_l_5c8;
	case 1484ULL: goto x86_l_5cc;
	case 1487ULL: goto x86_l_5cf;
	case 1490ULL: goto x86_l_5d2;
	case 1493ULL: goto x86_l_5d5;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1514ULL: goto x86_l_5ea;
	case 1517ULL: goto x86_l_5ed;
	case 1522ULL: goto x86_l_5f2;
	case 1529ULL: goto x86_l_5f9;
	case 1537ULL: goto x86_l_601;
	case 1545ULL: goto x86_l_609;
	case 1548ULL: goto x86_l_60c;
	case 1550ULL: goto x86_l_60e;
	case 1559ULL: goto x86_l_617;
	case 1562ULL: goto x86_l_61a;
	case 1571ULL: goto x86_l_623;
	case 1580ULL: goto x86_l_62c;
	case 1589ULL: goto x86_l_635;
	case 1598ULL: goto x86_l_63e;
	case 1607ULL: goto x86_l_647;
	case 1616ULL: goto x86_l_650;
	case 1625ULL: goto x86_l_659;
	case 1630ULL: goto x86_l_65e;
	case 1633ULL: goto x86_l_661;
	case 1638ULL: goto x86_l_666;
	case 1642ULL: goto x86_l_66a;
	case 1650ULL: goto x86_l_672;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1668ULL: goto x86_l_684;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1684ULL: goto x86_l_694;
	case 1689ULL: goto x86_l_699;
	case 1696ULL: goto x86_l_6a0;
	case 1701ULL: goto x86_l_6a5;
	case 1707ULL: goto x86_l_6ab;
	case 1714ULL: goto x86_l_6b2;
	case 1718ULL: goto x86_l_6b6;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
	case 1737ULL: goto x86_l_6c9;
	case 1740ULL: goto x86_l_6cc;
	case 1752ULL: goto x86_l_6d8;
	case 1761ULL: goto x86_l_6e1;
	case 1770ULL: goto x86_l_6ea;
	case 1779ULL: goto x86_l_6f3;
	case 1788ULL: goto x86_l_6fc;
	case 1797ULL: goto x86_l_705;
	case 1806ULL: goto x86_l_70e;
	case 1815ULL: goto x86_l_717;
	case 1825ULL: goto x86_l_721;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1848ULL: goto x86_l_738;
	case 1853ULL: goto x86_l_73d;
	case 1856ULL: goto x86_l_740;
	case 1858ULL: goto x86_l_742;
	case 1861ULL: goto x86_l_745;
	case 1867ULL: goto x86_l_74b;
	case 1870ULL: goto x86_l_74e;
	case 1874ULL: goto x86_l_752;
	case 1879ULL: goto x86_l_757;
	case 1885ULL: goto x86_l_75d;
	case 1889ULL: goto x86_l_761;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1918ULL: goto x86_l_77e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x138 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 312ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x10c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1151051235328ULL);
x86_l_18:
	/* 0x18: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b:
	/* 0x1b: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1e:
	/* 0x1e: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_21:
	/* 0x21: jae    32 <tail_handle_ipv4_cont+0x32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_32;
	}
x86_l_23:
	/* 0x23: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_28:
	/* 0x28: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b:
	/* 0x2b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d:
	/* 0x2d: jmp    22a <tail_handle_ipv4_cont+0x22a> */
	goto x86_l_22a;
x86_l_32:
	/* 0x32: mov    r12,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_39:
	/* 0x39: mov    eax,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3c:
	/* 0x3c: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_43:
	/* 0x43: mov    DWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4a:
	/* 0x4a: movzx  eax,WORD PTR [rbx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_4e:
	/* 0x4e: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_55:
	/* 0x55: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5c:
	/* 0x5c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_61:
	/* 0x61: mov    rdi,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_nat_buffer)));
x86_l_68:
	/* 0x68: lea    rsi,[rsp+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: je     b1 <tail_handle_ipv4_cont+0xb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b1;
	}
x86_l_77:
	/* 0x77: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a:
	/* 0x7a: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_82:
	/* 0x82: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_86:
	/* 0x86: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_8e:
	/* 0x8e: movzx  ecx,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_92:
	/* 0x92: mov    QWORD PTR [rsp+0x100],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a9:
	/* 0xa9: mov    WORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_af:
	/* 0xaf: jmp    cf <tail_handle_ipv4_cont+0xcf> */
	goto x86_l_cf;
x86_l_b1:
	/* 0xb1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_bb:
	/* 0xbb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_c5:
	/* 0xc5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x100],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_cf:
	/* 0xcf: mov    eax,DWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_d4:
	/* 0xd4: mov    QWORD PTR [rsp+0x4e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_dd:
	/* 0xdd: mov    WORD PTR [rsp+0x5e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 403726925824ULL);
x86_l_e4:
	/* 0xe4: mov    QWORD PTR [rsp+0x56],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 369367187456ULL);
x86_l_ed:
	/* 0xed: mov    DWORD PTR [rsp+0x48],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645376ULL);
x86_l_f5:
	/* 0xf5: mov    BYTE PTR [rsp+0x4f],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 339302416385ULL);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fe:
	/* 0xfe: mov    WORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_105:
	/* 0x105: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a:
	/* 0x10a: mov    rdi,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_111:
	/* 0x111: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_116:
	/* 0x116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118:
	/* 0x118: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: je     125 <tail_handle_ipv4_cont+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125;
	}
x86_l_120:
	/* 0x120: mov    r13d,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123:
	/* 0x123: jmp    12b <tail_handle_ipv4_cont+0x12b> */
	goto x86_l_12b;
x86_l_125:
	/* 0x125: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_12b:
	/* 0x12b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130:
	/* 0x130: mov    rdi,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer4)));
x86_l_137:
	/* 0x137: lea    rsi,[rsp+0x10c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 268ULL);
x86_l_13f:
	/* 0x13f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141:
	/* 0x141: mov    ebp,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967112ULL);
x86_l_146:
	/* 0x146: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149:
	/* 0x149: je     228 <tail_handle_ipv4_cont+0x228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228;
	}
x86_l_14f:
	/* 0x14f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_152:
	/* 0x152: cmp    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_156:
	/* 0x156: je     228 <tail_handle_ipv4_cont+0x228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_228;
	}
x86_l_15c:
	/* 0x15c: mov    QWORD PTR [rsp+0xf8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_164:
	/* 0x164: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_16b:
	/* 0x16b: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_16e:
	/* 0x16e: mov    eax,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_172:
	/* 0x172: mov    DWORD PTR [rsp+0xac],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_179:
	/* 0x179: mov    r12d,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_17d:
	/* 0x17d: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_181:
	/* 0x181: mov    ebp,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967133ULL);
x86_l_186:
	/* 0x186: lea    eax,[rdx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_189:
	/* 0x189: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18c:
	/* 0x18c: jb     2f7 <tail_handle_ipv4_cont+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f7;
	}
x86_l_192:
	/* 0x192: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_195:
	/* 0x195: ja     228 <tail_handle_ipv4_cont+0x228> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_228;
	}
x86_l_19b:
	/* 0x19b: mov    DWORD PTR [rsp+0x108],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1a2:
	/* 0x1a2: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1a5:
	/* 0x1a5: jne    309 <tail_handle_ipv4_cont+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_309;
	}
x86_l_1ab:
	/* 0x1ab: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1af:
	/* 0x1af: mov    DWORD PTR [rsp+0xc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b4:
	/* 0x1b4: mov    esi,DWORD PTR [r14+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b8:
	/* 0x1b8: mov    rax,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1bf:
	/* 0x1bf: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1:
	/* 0x1c1: movzx  ecx,WORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1c6:
	/* 0x1c6: movzx  r13d,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1cb:
	/* 0x1cb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ce:
	/* 0x1ce: mov    QWORD PTR [rsp+0xc0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1d6:
	/* 0x1d6: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db:
	/* 0x1db: mov    DWORD PTR [rsp+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1e2:
	/* 0x1e2: jne    431 <tail_handle_ipv4_cont+0x431> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_431;
	}
x86_l_1e8:
	/* 0x1e8: mov    DWORD PTR [rsp+0x38],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168640ULL);
x86_l_1f0:
	/* 0x1f0: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f4:
	/* 0x1f4: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1f8:
	/* 0x1f8: mov    BYTE PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_1fd:
	/* 0x1fd: mov    BYTE PTR [rsp+0x41],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_202:
	/* 0x202: mov    WORD PTR [rsp+0x42],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_207:
	/* 0x207: mov    r12,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_allow_icmp_frag_needed)));
x86_l_20e:
	/* 0x20e: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_213:
	/* 0x213: je     78b <tail_handle_ipv4_cont+0x78b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1931ULL;
	}
x86_l_219:
	/* 0x219: cmp    r13b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 1ULL);
x86_l_21d:
	/* 0x21d: je     79f <tail_handle_ipv4_cont+0x79f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1951ULL;
	}
x86_l_223:
	/* 0x223: jmp    7fc <tail_handle_ipv4_cont+0x7fc> */
	return 2044ULL;
x86_l_228:
	/* 0x228: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a:
	/* 0x22a: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_22d:
	/* 0x22d: mov    rax,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_234:
	/* 0x234: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_236:
	/* 0x236: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_239:
	/* 0x239: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_23b:
	/* 0x23b: cmovs  ecx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R12, X86_WIDTH_32, X86_CC_S);
x86_l_23f:
	/* 0x23f: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_242:
	/* 0x242: movzx  edx,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_246:
	/* 0x246: shl    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_249:
	/* 0x249: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_24b:
	/* 0x24b: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24e:
	/* 0x24e: mov    DWORD PTR [rbx+0x2c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_252:
	/* 0x252: mov    DWORD PTR [rbx+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_255:
	/* 0x255: movabs rax,0x68a020200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 471191318626828288ULL);
x86_l_25f:
	/* 0x25f: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_263:
	/* 0x263: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_267:
	/* 0x267: movabs rax,0x200580200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8595702272ULL);
x86_l_271:
	/* 0x271: add    rax,0x6320000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 103940096ULL);
x86_l_277:
	/* 0x277: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27c:
	/* 0x27c: mov    BYTE PTR [rsp+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_280:
	/* 0x280: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_285:
	/* 0x285: mov    rdi,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_28c:
	/* 0x28c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_291:
	/* 0x291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293:
	/* 0x293: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_296:
	/* 0x296: je     2a1 <tail_handle_ipv4_cont+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a1;
	}
x86_l_298:
	/* 0x298: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_29b:
	/* 0x29b: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_29f:
	/* 0x29f: jmp    2c9 <tail_handle_ipv4_cont+0x2c9> */
	goto x86_l_2c9;
x86_l_2a1:
	/* 0x2a1: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2aa:
	/* 0x2aa: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2af:
	/* 0x2af: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b4:
	/* 0x2b4: mov    rdi,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2bb:
	/* 0x2bb: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c0:
	/* 0x2c0: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c5:
	/* 0x2c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c7:
	/* 0x2c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9:
	/* 0x2c9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2ce:
	/* 0x2ce: mov    rsi,QWORD PTR [rip+0x6357] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2d5:
	/* 0x2d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2d8:
	/* 0x2d8: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2dd:
	/* 0x2dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2df:
	/* 0x2df: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2e5:
	/* 0x2e5: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2e8:
	/* 0x2e8: add    rsp,0x138 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 312ULL);
x86_l_2ef:
	/* 0x2ef: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2f1:
	/* 0x2f1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2f2:
	/* 0x2f2: jmp    2f6d <tail_handle_ipv4_cont+0x2f6d> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_2f7:
	/* 0x2f7: test   BYTE PTR [r14+0x24],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822672ULL);
x86_l_2fc:
	/* 0x2fc: jne    3b8 <tail_handle_ipv4_cont+0x3b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3b8;
	}
x86_l_302:
	/* 0x302: mov    DWORD PTR [rsp+0x108],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_309:
	/* 0x309: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30b:
	/* 0x30b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_30e:
	/* 0x30e: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_312:
	/* 0x312: jb     354 <tail_handle_ipv4_cont+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_354;
	}
x86_l_314:
	/* 0x314: mov    eax,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_31b:
	/* 0x31b: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_31e:
	/* 0x31e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_321:
	/* 0x321: je     405 <tail_handle_ipv4_cont+0x405> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_405;
	}
x86_l_327:
	/* 0x327: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_329:
	/* 0x329: jne    22a <tail_handle_ipv4_cont+0x22a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22a;
	}
x86_l_32f:
	/* 0x32f: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_336:
	/* 0x336: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_338:
	/* 0x338: cmp    BYTE PTR [r14+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_33d:
	/* 0x33d: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_342:
	/* 0x342: jne    5f2 <tail_handle_ipv4_cont+0x5f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5f2;
	}
x86_l_348:
	/* 0x348: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_34f:
	/* 0x34f: jmp    5f9 <tail_handle_ipv4_cont+0x5f9> */
	goto x86_l_5f9;
x86_l_354:
	/* 0x354: test   BYTE PTR [r14+0x24],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822658ULL);
x86_l_359:
	/* 0x359: je     df7 <tail_handle_ipv4_cont+0xdf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3575ULL;
	}
x86_l_35f:
	/* 0x35f: movzx  eax,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_364:
	/* 0x364: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_367:
	/* 0x367: je     372 <tail_handle_ipv4_cont+0x372> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_372;
	}
x86_l_369:
	/* 0x369: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_36c:
	/* 0x36c: jne    df7 <tail_handle_ipv4_cont+0xdf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3575ULL;
	}
x86_l_372:
	/* 0x372: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_379:
	/* 0x379: mov    r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c:
	/* 0x37c: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_383:
	/* 0x383: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_386:
	/* 0x386: je     6bf <tail_handle_ipv4_cont+0x6bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6bf;
	}
x86_l_38c:
	/* 0x38c: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_394:
	/* 0x394: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_399:
	/* 0x399: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_3a0:
	/* 0x3a0: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3a5:
	/* 0x3a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a7:
	/* 0x3a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3aa:
	/* 0x3aa: je     6bf <tail_handle_ipv4_cont+0x6bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6bf;
	}
x86_l_3b0:
	/* 0x3b0: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b3:
	/* 0x3b3: jmp    6c1 <tail_handle_ipv4_cont+0x6c1> */
	goto x86_l_6c1;
x86_l_3b8:
	/* 0x3b8: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_3bf:
	/* 0x3bf: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c1:
	/* 0x3c1: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_3c8:
	/* 0x3c8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cb:
	/* 0x3cb: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d0:
	/* 0x3d0: je     4b2 <tail_handle_ipv4_cont+0x4b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b2;
	}
x86_l_3d6:
	/* 0x3d6: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_3de:
	/* 0x3de: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e3:
	/* 0x3e3: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_3ea:
	/* 0x3ea: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ef:
	/* 0x3ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f1:
	/* 0x3f1: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_3f4:
	/* 0x3f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f7:
	/* 0x3f7: je     4b5 <tail_handle_ipv4_cont+0x4b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4b5;
	}
x86_l_3fd:
	/* 0x3fd: mov    rdi,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_400:
	/* 0x400: jmp    4b7 <tail_handle_ipv4_cont+0x4b7> */
	goto x86_l_4b7;
x86_l_405:
	/* 0x405: cmp    WORD PTR [r14+0x22],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_40a:
	/* 0x40a: jne    32f <tail_handle_ipv4_cont+0x32f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32f;
	}
x86_l_410:
	/* 0x410: cmp    WORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_419:
	/* 0x419: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_41c:
	/* 0x41c: test   BYTE PTR [r14+0x24],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822672ULL);
x86_l_421:
	/* 0x421: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_424:
	/* 0x424: xor    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_XOR);
x86_l_426:
	/* 0x426: jne    df7 <tail_handle_ipv4_cont+0xdf7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3575ULL;
	}
x86_l_42c:
	/* 0x42c: jmp    32f <tail_handle_ipv4_cont+0x32f> */
	goto x86_l_32f;
x86_l_431:
	/* 0x431: cmp    r13b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 17ULL);
x86_l_435:
	/* 0x435: jne    472 <tail_handle_ipv4_cont+0x472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_472;
	}
x86_l_437:
	/* 0x437: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_port)));
x86_l_43e:
	/* 0x43e: movbe  ax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_443:
	/* 0x443: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_446:
	/* 0x446: jne    472 <tail_handle_ipv4_cont+0x472> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_472;
	}
x86_l_448:
	/* 0x448: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44a:
	/* 0x44a: mov    r12d,0xffffff56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967126ULL);
x86_l_450:
	/* 0x450: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_453:
	/* 0x453: mov    r9b,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 17ULL);
x86_l_456:
	/* 0x456: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_461:
	/* 0x461: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_463:
	/* 0x463: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_46b:
	/* 0x46b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46d:
	/* 0x46d: jmp    2075 <tail_handle_ipv4_cont+0x2075> */
	return 8309ULL;
x86_l_472:
	/* 0x472: mov    DWORD PTR [rsp+0x38],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168640ULL);
x86_l_47a:
	/* 0x47a: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_47e:
	/* 0x47e: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_482:
	/* 0x482: mov    BYTE PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_487:
	/* 0x487: mov    BYTE PTR [rsp+0x41],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 65ULL);
x86_l_48c:
	/* 0x48c: mov    WORD PTR [rsp+0x42],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_491:
	/* 0x491: mov    r12,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_allow_icmp_frag_needed)));
x86_l_498:
	/* 0x498: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49d:
	/* 0x49d: je     8e5 <tail_handle_ipv4_cont+0x8e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2277ULL;
	}
x86_l_4a3:
	/* 0x4a3: cmp    r13b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 1ULL);
x86_l_4a7:
	/* 0x4a7: je     8f9 <tail_handle_ipv4_cont+0x8f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2297ULL;
	}
x86_l_4ad:
	/* 0x4ad: jmp    956 <tail_handle_ipv4_cont+0x956> */
	return 2390ULL;
x86_l_4b2:
	/* 0x4b2: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_4b5:
	/* 0x4b5: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b7:
	/* 0x4b7: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4bb:
	/* 0x4bb: mov    QWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_4c4:
	/* 0x4c4: cmp    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_4cc:
	/* 0x4cc: je     c86 <tail_handle_ipv4_cont+0xc86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3206ULL;
	}
x86_l_4d2:
	/* 0x4d2: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_4d9:
	/* 0x4d9: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dc:
	/* 0x4dc: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_4df:
	/* 0x4df: je     bd0 <tail_handle_ipv4_cont+0xbd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3024ULL;
	}
x86_l_4e5:
	/* 0x4e5: mov    QWORD PTR [rsp+0x90],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4ed:
	/* 0x4ed: mov    DWORD PTR [rsp+0xd0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_4f4:
	/* 0x4f4: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_4fb:
	/* 0x4fb: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fd:
	/* 0x4fd: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_505:
	/* 0x505: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_507:
	/* 0x507: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_50c:
	/* 0x50c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50e:
	/* 0x50e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_510:
	/* 0x510: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_513:
	/* 0x513: mov    DWORD PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_51e:
	/* 0x51e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_523:
	/* 0x523: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_52a:
	/* 0x52a: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_532:
	/* 0x532: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_534:
	/* 0x534: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53a:
	/* 0x53a: jne    56d <tail_handle_ipv4_cont+0x56d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_56d;
	}
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_545:
	/* 0x545: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_54a:
	/* 0x54a: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_551:
	/* 0x551: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_559:
	/* 0x559: lea    r14,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55e:
	/* 0x55e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_561:
	/* 0x561: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_563:
	/* 0x563: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_565:
	/* 0x565: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_567:
	/* 0x567: js     c86 <tail_handle_ipv4_cont+0xc86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 3206ULL;
	}
x86_l_56d:
	/* 0x56d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_572:
	/* 0x572: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_579:
	/* 0x579: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_57e:
	/* 0x57e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_580:
	/* 0x580: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_583:
	/* 0x583: je     8b1 <tail_handle_ipv4_cont+0x8b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2225ULL;
	}
x86_l_589:
	/* 0x589: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58c:
	/* 0x58c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_58f:
	/* 0x58f: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_592:
	/* 0x592: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_599:
	/* 0x599: jbe    baa <tail_handle_ipv4_cont+0xbaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2986ULL;
	}
x86_l_59f:
	/* 0x59f: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_5a2:
	/* 0x5a2: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_5a6:
	/* 0x5a6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_5b0:
	/* 0x5b0: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_5b5:
	/* 0x5b5: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_5b9:
	/* 0x5b9: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_5c0:
	/* 0x5c0: imul   rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_5c4:
	/* 0x5c4: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5cc:
	/* 0x5cc: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5cf:
	/* 0x5cf: add    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5d2:
	/* 0x5d2: mov    QWORD PTR [rax],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d5:
	/* 0x5d5: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5dd:
	/* 0x5dd: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_5e0:
	/* 0x5e0: jbe    bae <tail_handle_ipv4_cont+0xbae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 2990ULL;
	}
x86_l_5e6:
	/* 0x5e6: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5ea:
	/* 0x5ea: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_5ed:
	/* 0x5ed: jmp    bae <tail_handle_ipv4_cont+0xbae> */
	return 2990ULL;
x86_l_5f2:
	/* 0x5f2: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_5f9:
	/* 0x5f9: mov    QWORD PTR [rsp+0xc0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_601:
	/* 0x601: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_609:
	/* 0x609: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_60c:
	/* 0x60c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60e:
	/* 0x60e: cmp    WORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_617:
	/* 0x617: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_62c:
	/* 0x62c: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_635:
	/* 0x635: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_63e:
	/* 0x63e: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_647:
	/* 0x647: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_650:
	/* 0x650: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_659:
	/* 0x659: movzx  ebp,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_65e:
	/* 0x65e: shl    edx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 6ULL);
x86_l_661:
	/* 0x661: mov    WORD PTR [rsp+0x6e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 110ULL);
x86_l_666:
	/* 0x666: mov    DWORD PTR [rsp+0x74],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_66a:
	/* 0x66a: movzx  eax,WORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 264ULL);
x86_l_672:
	/* 0x672: mov    rcx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_67a:
	/* 0x67a: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_67f:
	/* 0x67f: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_684:
	/* 0x684: mov    rcx,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_68c:
	/* 0x68c: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_691:
	/* 0x691: lea    eax,[rdx+rax*8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 0ULL);
x86_l_694:
	/* 0x694: mov    WORD PTR [rsp+0x6c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_699:
	/* 0x699: mov    r12,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_6a0:
	/* 0x6a0: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a5:
	/* 0x6a5: je     757 <tail_handle_ipv4_cont+0x757> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_757;
	}
x86_l_6ab:
	/* 0x6ab: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6b2:
	/* 0x6b2: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_6b6:
	/* 0x6b6: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6ba:
	/* 0x6ba: jmp    75d <tail_handle_ipv4_cont+0x75d> */
	goto x86_l_75d;
x86_l_6bf:
	/* 0x6bf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c1:
	/* 0x6c1: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_6c9:
	/* 0x6c9: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6cc:
	/* 0x6cc: mov    QWORD PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_6d8:
	/* 0x6d8: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_6e1:
	/* 0x6e1: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_6ea:
	/* 0x6ea: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6f3:
	/* 0x6f3: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_6fc:
	/* 0x6fc: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_705:
	/* 0x705: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_70e:
	/* 0x70e: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_717:
	/* 0x717: movabs rax,0x200580200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8595702272ULL);
x86_l_721:
	/* 0x721: add    rax,0x6150000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 102039552ULL);
x86_l_727:
	/* 0x727: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_72c:
	/* 0x72c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_731:
	/* 0x731: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_738:
	/* 0x738: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_73d:
	/* 0x73d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_740:
	/* 0x740: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_742:
	/* 0x742: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_745:
	/* 0x745: je     a48 <tail_handle_ipv4_cont+0xa48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2632ULL;
	}
x86_l_74b:
	/* 0x74b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_74e:
	/* 0x74e: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_752:
	/* 0x752: jmp    a70 <tail_handle_ipv4_cont+0xa70> */
	return 2672ULL;
x86_l_757:
	/* 0x757: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_75d:
	/* 0x75d: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_761:
	/* 0x761: jne    cd7 <tail_handle_ipv4_cont+0xcd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3287ULL;
	}
x86_l_767:
	/* 0x767: mov    WORD PTR [rsp+0x6c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_76c:
	/* 0x76c: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_771:
	/* 0x771: je     cd1 <tail_handle_ipv4_cont+0xcd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3281ULL;
	}
x86_l_777:
	/* 0x777: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_77e:
	/* 0x77e: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
	return 1922ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1922ULL: goto x86_l_782;
	case 1926ULL: goto x86_l_786;
	case 1931ULL: goto x86_l_78b;
	case 1938ULL: goto x86_l_792;
	case 1941ULL: goto x86_l_795;
	case 1945ULL: goto x86_l_799;
	case 1947ULL: goto x86_l_79b;
	case 1949ULL: goto x86_l_79d;
	case 1951ULL: goto x86_l_79f;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1973ULL: goto x86_l_7b5;
	case 1979ULL: goto x86_l_7bb;
	case 1984ULL: goto x86_l_7c0;
	case 1992ULL: goto x86_l_7c8;
	case 1994ULL: goto x86_l_7ca;
	case 1999ULL: goto x86_l_7cf;
	case 2001ULL: goto x86_l_7d1;
	case 2003ULL: goto x86_l_7d3;
	case 2008ULL: goto x86_l_7d8;
	case 2014ULL: goto x86_l_7de;
	case 2020ULL: goto x86_l_7e4;
	case 2027ULL: goto x86_l_7eb;
	case 2030ULL: goto x86_l_7ee;
	case 2032ULL: goto x86_l_7f0;
	case 2036ULL: goto x86_l_7f4;
	case 2039ULL: goto x86_l_7f7;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2061ULL: goto x86_l_80d;
	case 2063ULL: goto x86_l_80f;
	case 2066ULL: goto x86_l_812;
	case 2072ULL: goto x86_l_818;
	case 2076ULL: goto x86_l_81c;
	case 2082ULL: goto x86_l_822;
	case 2085ULL: goto x86_l_825;
	case 2090ULL: goto x86_l_82a;
	case 2097ULL: goto x86_l_831;
	case 2100ULL: goto x86_l_834;
	case 2103ULL: goto x86_l_837;
	case 2111ULL: goto x86_l_83f;
	case 2117ULL: goto x86_l_845;
	case 2120ULL: goto x86_l_848;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2132ULL: goto x86_l_854;
	case 2140ULL: goto x86_l_85c;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2160ULL: goto x86_l_870;
	case 2165ULL: goto x86_l_875;
	case 2168ULL: goto x86_l_878;
	case 2172ULL: goto x86_l_87c;
	case 2176ULL: goto x86_l_880;
	case 2180ULL: goto x86_l_884;
	case 2184ULL: goto x86_l_888;
	case 2189ULL: goto x86_l_88d;
	case 2197ULL: goto x86_l_895;
	case 2203ULL: goto x86_l_89b;
	case 2207ULL: goto x86_l_89f;
	case 2209ULL: goto x86_l_8a1;
	case 2212ULL: goto x86_l_8a4;
	case 2216ULL: goto x86_l_8a8;
	case 2220ULL: goto x86_l_8ac;
	case 2225ULL: goto x86_l_8b1;
	case 2230ULL: goto x86_l_8b6;
	case 2233ULL: goto x86_l_8b9;
	case 2238ULL: goto x86_l_8be;
	case 2243ULL: goto x86_l_8c3;
	case 2250ULL: goto x86_l_8ca;
	case 2255ULL: goto x86_l_8cf;
	case 2260ULL: goto x86_l_8d4;
	case 2262ULL: goto x86_l_8d6;
	case 2264ULL: goto x86_l_8d8;
	case 2266ULL: goto x86_l_8da;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2284ULL: goto x86_l_8ec;
	case 2287ULL: goto x86_l_8ef;
	case 2291ULL: goto x86_l_8f3;
	case 2293ULL: goto x86_l_8f5;
	case 2295ULL: goto x86_l_8f7;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2310ULL: goto x86_l_906;
	case 2315ULL: goto x86_l_90b;
	case 2317ULL: goto x86_l_90d;
	case 2319ULL: goto x86_l_90f;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2338ULL: goto x86_l_922;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2347ULL: goto x86_l_92b;
	case 2349ULL: goto x86_l_92d;
	case 2354ULL: goto x86_l_932;
	case 2360ULL: goto x86_l_938;
	case 2366ULL: goto x86_l_93e;
	case 2373ULL: goto x86_l_945;
	case 2376ULL: goto x86_l_948;
	case 2378ULL: goto x86_l_94a;
	case 2382ULL: goto x86_l_94e;
	case 2385ULL: goto x86_l_951;
	case 2390ULL: goto x86_l_956;
	case 2395ULL: goto x86_l_95b;
	case 2402ULL: goto x86_l_962;
	case 2407ULL: goto x86_l_967;
	case 2409ULL: goto x86_l_969;
	case 2412ULL: goto x86_l_96c;
	case 2418ULL: goto x86_l_972;
	case 2422ULL: goto x86_l_976;
	case 2428ULL: goto x86_l_97c;
	case 2431ULL: goto x86_l_97f;
	case 2436ULL: goto x86_l_984;
	case 2443ULL: goto x86_l_98b;
	case 2446ULL: goto x86_l_98e;
	case 2449ULL: goto x86_l_991;
	case 2457ULL: goto x86_l_999;
	case 2463ULL: goto x86_l_99f;
	case 2466ULL: goto x86_l_9a2;
	case 2470ULL: goto x86_l_9a6;
	case 2475ULL: goto x86_l_9ab;
	case 2478ULL: goto x86_l_9ae;
	case 2486ULL: goto x86_l_9b6;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2501ULL: goto x86_l_9c5;
	case 2506ULL: goto x86_l_9ca;
	case 2511ULL: goto x86_l_9cf;
	case 2514ULL: goto x86_l_9d2;
	case 2518ULL: goto x86_l_9d6;
	case 2522ULL: goto x86_l_9da;
	case 2526ULL: goto x86_l_9de;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2543ULL: goto x86_l_9ef;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2558ULL: goto x86_l_9fe;
	case 2562ULL: goto x86_l_a02;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2577ULL: goto x86_l_a11;
	case 2584ULL: goto x86_l_a18;
	case 2592ULL: goto x86_l_a20;
	case 2603ULL: goto x86_l_a2b;
	case 2610ULL: goto x86_l_a32;
	case 2612ULL: goto x86_l_a34;
	case 2620ULL: goto x86_l_a3c;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2658ULL: goto x86_l_a62;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2680ULL: goto x86_l_a78;
	case 2686ULL: goto x86_l_a7e;
	case 2693ULL: goto x86_l_a85;
	case 2696ULL: goto x86_l_a88;
	case 2702ULL: goto x86_l_a8e;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2720ULL: goto x86_l_aa0;
	case 2727ULL: goto x86_l_aa7;
	case 2729ULL: goto x86_l_aa9;
	case 2737ULL: goto x86_l_ab1;
	case 2740ULL: goto x86_l_ab4;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2749ULL: goto x86_l_abd;
	case 2752ULL: goto x86_l_ac0;
	case 2763ULL: goto x86_l_acb;
	case 2768ULL: goto x86_l_ad0;
	case 2775ULL: goto x86_l_ad7;
	case 2783ULL: goto x86_l_adf;
	case 2785ULL: goto x86_l_ae1;
	case 2788ULL: goto x86_l_ae4;
	case 2791ULL: goto x86_l_ae7;
	case 2793ULL: goto x86_l_ae9;
	case 2802ULL: goto x86_l_af2;
	case 2807ULL: goto x86_l_af7;
	case 2814ULL: goto x86_l_afe;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2827ULL: goto x86_l_b0b;
	case 2829ULL: goto x86_l_b0d;
	case 2832ULL: goto x86_l_b10;
	case 2834ULL: goto x86_l_b12;
	case 2840ULL: goto x86_l_b18;
	case 2845ULL: goto x86_l_b1d;
	case 2852ULL: goto x86_l_b24;
	case 2860ULL: goto x86_l_b2c;
	case 2862ULL: goto x86_l_b2e;
	case 2865ULL: goto x86_l_b31;
	case 2871ULL: goto x86_l_b37;
	case 2874ULL: goto x86_l_b3a;
	case 2877ULL: goto x86_l_b3d;
	case 2880ULL: goto x86_l_b40;
	case 2887ULL: goto x86_l_b47;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2900ULL: goto x86_l_b54;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2919ULL: goto x86_l_b67;
	case 2926ULL: goto x86_l_b6e;
	case 2930ULL: goto x86_l_b72;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2944ULL: goto x86_l_b80;
	case 2947ULL: goto x86_l_b83;
	case 2955ULL: goto x86_l_b8b;
	case 2958ULL: goto x86_l_b8e;
	case 2963ULL: goto x86_l_b93;
	case 2968ULL: goto x86_l_b98;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2981ULL: goto x86_l_ba5;
	case 2986ULL: goto x86_l_baa;
	case 2990ULL: goto x86_l_bae;
	case 2993ULL: goto x86_l_bb1;
	case 2999ULL: goto x86_l_bb7;
	case 3002ULL: goto x86_l_bba;
	case 3006ULL: goto x86_l_bbe;
	case 3009ULL: goto x86_l_bc1;
	case 3016ULL: goto x86_l_bc8;
	case 3024ULL: goto x86_l_bd0;
	case 3031ULL: goto x86_l_bd7;
	case 3033ULL: goto x86_l_bd9;
	case 3035ULL: goto x86_l_bdb;
	case 3042ULL: goto x86_l_be2;
	case 3044ULL: goto x86_l_be4;
	case 3047ULL: goto x86_l_be7;
	case 3049ULL: goto x86_l_be9;
	case 3052ULL: goto x86_l_bec;
	case 3059ULL: goto x86_l_bf3;
	case 3062ULL: goto x86_l_bf6;
	case 3068ULL: goto x86_l_bfc;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3084ULL: goto x86_l_c0c;
	case 3089ULL: goto x86_l_c11;
	case 3094ULL: goto x86_l_c16;
	case 3101ULL: goto x86_l_c1d;
	case 3105ULL: goto x86_l_c21;
	case 3113ULL: goto x86_l_c29;
	case 3120ULL: goto x86_l_c30;
	case 3124ULL: goto x86_l_c34;
	case 3128ULL: goto x86_l_c38;
	case 3133ULL: goto x86_l_c3d;
	case 3141ULL: goto x86_l_c45;
	case 3146ULL: goto x86_l_c4a;
	case 3155ULL: goto x86_l_c53;
	case 3164ULL: goto x86_l_c5c;
	case 3170ULL: goto x86_l_c62;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3182ULL: goto x86_l_c6e;
	case 3189ULL: goto x86_l_c75;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3203ULL: goto x86_l_c83;
	case 3206ULL: goto x86_l_c86;
	case 3213ULL: goto x86_l_c8d;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3233ULL: goto x86_l_ca1;
	case 3238ULL: goto x86_l_ca6;
	case 3242ULL: goto x86_l_caa;
	case 3248ULL: goto x86_l_cb0;
	case 3250ULL: goto x86_l_cb2;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3267ULL: goto x86_l_cc3;
	case 3274ULL: goto x86_l_cca;
	case 3276ULL: goto x86_l_ccc;
	case 3281ULL: goto x86_l_cd1;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3299ULL: goto x86_l_ce3;
	case 3301ULL: goto x86_l_ce5;
	case 3303ULL: goto x86_l_ce7;
	case 3307ULL: goto x86_l_ceb;
	case 3309ULL: goto x86_l_ced;
	case 3314ULL: goto x86_l_cf2;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3322ULL: goto x86_l_cfa;
	case 3332ULL: goto x86_l_d04;
	case 3335ULL: goto x86_l_d07;
	case 3340ULL: goto x86_l_d0c;
	case 3344ULL: goto x86_l_d10;
	case 3348ULL: goto x86_l_d14;
	case 3351ULL: goto x86_l_d17;
	case 3354ULL: goto x86_l_d1a;
	case 3359ULL: goto x86_l_d1f;
	case 3364ULL: goto x86_l_d24;
	case 3368ULL: goto x86_l_d28;
	case 3370ULL: goto x86_l_d2a;
	case 3375ULL: goto x86_l_d2f;
	case 3377ULL: goto x86_l_d31;
	case 3384ULL: goto x86_l_d38;
	case 3386ULL: goto x86_l_d3a;
	case 3389ULL: goto x86_l_d3d;
	case 3392ULL: goto x86_l_d40;
	case 3394ULL: goto x86_l_d42;
	case 3399ULL: goto x86_l_d47;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3409ULL: goto x86_l_d51;
	case 3411ULL: goto x86_l_d53;
	case 3413ULL: goto x86_l_d55;
	case 3415ULL: goto x86_l_d57;
	case 3417ULL: goto x86_l_d59;
	case 3419ULL: goto x86_l_d5b;
	case 3423ULL: goto x86_l_d5f;
	case 3427ULL: goto x86_l_d63;
	case 3434ULL: goto x86_l_d6a;
	case 3436ULL: goto x86_l_d6c;
	case 3439ULL: goto x86_l_d6f;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3451ULL: goto x86_l_d7b;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3469ULL: goto x86_l_d8d;
	case 3471ULL: goto x86_l_d8f;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3487ULL: goto x86_l_d9f;
	case 3492ULL: goto x86_l_da4;
	case 3497ULL: goto x86_l_da9;
	case 3499ULL: goto x86_l_dab;
	case 3501ULL: goto x86_l_dad;
	case 3503ULL: goto x86_l_daf;
	case 3509ULL: goto x86_l_db5;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3521ULL: goto x86_l_dc1;
	case 3530ULL: goto x86_l_dca;
	case 3533ULL: goto x86_l_dcd;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3548ULL: goto x86_l_ddc;
	case 3556ULL: goto x86_l_de4;
	case 3559ULL: goto x86_l_de7;
	case 3561ULL: goto x86_l_de9;
	case 3563ULL: goto x86_l_deb;
	case 3565ULL: goto x86_l_ded;
	case 3571ULL: goto x86_l_df3;
	case 3575ULL: goto x86_l_df7;
	case 3582ULL: goto x86_l_dfe;
	case 3585ULL: goto x86_l_e01;
	case 3593ULL: goto x86_l_e09;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3611ULL: goto x86_l_e1b;
	case 3614ULL: goto x86_l_e1e;
	case 3621ULL: goto x86_l_e25;
	case 3624ULL: goto x86_l_e28;
	case 3630ULL: goto x86_l_e2e;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3650ULL: goto x86_l_e42;
	case 3655ULL: goto x86_l_e47;
	case 3657ULL: goto x86_l_e49;
	case 3660ULL: goto x86_l_e4c;
	case 3666ULL: goto x86_l_e52;
	default: return 0xffffffffffffffffULL;
	}
x86_l_782:
	/* 0x782: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_786:
	/* 0x786: jmp    cd7 <tail_handle_ipv4_cont+0xcd7> */
	goto x86_l_cd7;
x86_l_78b:
	/* 0x78b: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_792:
	/* 0x792: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_795:
	/* 0x795: cmp    r13b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 1ULL);
x86_l_799:
	/* 0x799: jne    7fc <tail_handle_ipv4_cont+0x7fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7fc;
	}
x86_l_79b:
	/* 0x79b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_79d:
	/* 0x79d: je     7fc <tail_handle_ipv4_cont+0x7fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fc;
	}
x86_l_79f:
	/* 0x79f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7a4:
	/* 0x7a4: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7a9:
	/* 0x7a9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7ac:
	/* 0x7ac: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7b1:
	/* 0x7b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b3:
	/* 0x7b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b5:
	/* 0x7b5: js     a0b <tail_handle_ipv4_cont+0xa0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a0b;
	}
x86_l_7bb:
	/* 0x7bb: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c0:
	/* 0x7c0: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7c8:
	/* 0x7c8: je     7e4 <tail_handle_ipv4_cont+0x7e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e4;
	}
x86_l_7ca:
	/* 0x7ca: cmp    BYTE PTR [rsp+0x48],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645315ULL);
x86_l_7cf:
	/* 0x7cf: jne    7e4 <tail_handle_ipv4_cont+0x7e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7e4;
	}
x86_l_7d1:
	/* 0x7d1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d3:
	/* 0x7d3: cmp    BYTE PTR [rsp+0x49],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 313532612612ULL);
x86_l_7d8:
	/* 0x7d8: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_7de:
	/* 0x7de: je     a20 <tail_handle_ipv4_cont+0xa20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a20;
	}
x86_l_7e4:
	/* 0x7e4: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_7eb:
	/* 0x7eb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ee:
	/* 0x7ee: je     7fc <tail_handle_ipv4_cont+0x7fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7fc;
	}
x86_l_7f0:
	/* 0x7f0: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7f4:
	/* 0x7f4: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_7f7:
	/* 0x7f7: mov    WORD PTR [rsp+0x42],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_7fc:
	/* 0x7fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_801:
	/* 0x801: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_808:
	/* 0x808: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_80d:
	/* 0x80d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80f:
	/* 0x80f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_812:
	/* 0x812: je     2af2 <tail_handle_ipv4_cont+0x2af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10994ULL;
	}
x86_l_818:
	/* 0x818: cmp    DWORD PTR [rax+0x4],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21474836479ULL);
x86_l_81c:
	/* 0x81c: jne    2af2 <tail_handle_ipv4_cont+0x2af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10994ULL;
	}
x86_l_822:
	/* 0x822: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_825:
	/* 0x825: movzx  r12d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_82a:
	/* 0x82a: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_831:
	/* 0x831: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_834:
	/* 0x834: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_837:
	/* 0x837: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_83f:
	/* 0x83f: je     1e70 <tail_handle_ipv4_cont+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_845:
	/* 0x845: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_848:
	/* 0x848: shr    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_84c:
	/* 0x84c: movzx  ecx,BYTE PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_851:
	/* 0x851: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_854:
	/* 0x854: mov    QWORD PTR [rsp+0xc8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_85c:
	/* 0x85c: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_863:
	/* 0x863: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_866:
	/* 0x866: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_86b:
	/* 0x86b: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_870:
	/* 0x870: mov    BYTE PTR [rsp+0x23],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_875:
	/* 0x875: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_878:
	/* 0x878: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_87c:
	/* 0x87c: mov    DWORD PTR [rsp+0x24],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_880:
	/* 0x880: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_884:
	/* 0x884: cmp    r12b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 71ULL);
x86_l_888:
	/* 0x888: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88d:
	/* 0x88d: mov    QWORD PTR [rsp+0xa0],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_895:
	/* 0x895: ja     ca6 <tail_handle_ipv4_cont+0xca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ca6;
	}
x86_l_89b:
	/* 0x89b: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_89f:
	/* 0x89f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a1:
	/* 0x8a1: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_8a4:
	/* 0x8a4: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8a8:
	/* 0x8a8: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_8ac:
	/* 0x8ac: jmp    1903 <tail_handle_ipv4_cont+0x1903> */
	return 6403ULL;
x86_l_8b1:
	/* 0x8b1: mov    QWORD PTR [rsp+0x48],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8b6:
	/* 0x8b6: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_8b9:
	/* 0x8b9: mov    QWORD PTR [rsp+0x50],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8be:
	/* 0x8be: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8c3:
	/* 0x8c3: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_8ca:
	/* 0x8ca: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8cf:
	/* 0x8cf: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8d4:
	/* 0x8d4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8da:
	/* 0x8da: jns    bbe <tail_handle_ipv4_cont+0xbbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_bbe;
	}
x86_l_8e0:
	/* 0x8e0: jmp    164d <tail_handle_ipv4_cont+0x164d> */
	return 5709ULL;
x86_l_8e5:
	/* 0x8e5: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_8ec:
	/* 0x8ec: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_8ef:
	/* 0x8ef: cmp    r13b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 1ULL);
x86_l_8f3:
	/* 0x8f3: jne    956 <tail_handle_ipv4_cont+0x956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_956;
	}
x86_l_8f5:
	/* 0x8f5: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_8f7:
	/* 0x8f7: je     956 <tail_handle_ipv4_cont+0x956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_956;
	}
x86_l_8f9:
	/* 0x8f9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8fe:
	/* 0x8fe: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_903:
	/* 0x903: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_906:
	/* 0x906: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_90b:
	/* 0x90b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90d:
	/* 0x90d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_90f:
	/* 0x90f: js     a0b <tail_handle_ipv4_cont+0xa0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a0b;
	}
x86_l_915:
	/* 0x915: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_91a:
	/* 0x91a: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_922:
	/* 0x922: je     93e <tail_handle_ipv4_cont+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93e;
	}
x86_l_924:
	/* 0x924: cmp    BYTE PTR [rsp+0x48],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645315ULL);
x86_l_929:
	/* 0x929: jne    93e <tail_handle_ipv4_cont+0x93e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_93e;
	}
x86_l_92b:
	/* 0x92b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_92d:
	/* 0x92d: cmp    BYTE PTR [rsp+0x49],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 313532612612ULL);
x86_l_932:
	/* 0x932: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_938:
	/* 0x938: je     a20 <tail_handle_ipv4_cont+0xa20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a20;
	}
x86_l_93e:
	/* 0x93e: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_945:
	/* 0x945: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_948:
	/* 0x948: je     956 <tail_handle_ipv4_cont+0x956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_956;
	}
x86_l_94a:
	/* 0x94a: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_94e:
	/* 0x94e: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_951:
	/* 0x951: mov    WORD PTR [rsp+0x42],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_956:
	/* 0x956: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_95b:
	/* 0x95b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_962:
	/* 0x962: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_967:
	/* 0x967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_969:
	/* 0x969: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_96c:
	/* 0x96c: je     2be1 <tail_handle_ipv4_cont+0x2be1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11233ULL;
	}
x86_l_972:
	/* 0x972: cmp    DWORD PTR [rax+0x4],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21474836479ULL);
x86_l_976:
	/* 0x976: jne    2be1 <tail_handle_ipv4_cont+0x2be1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11233ULL;
	}
x86_l_97c:
	/* 0x97c: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_97f:
	/* 0x97f: movzx  r12d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_984:
	/* 0x984: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_98b:
	/* 0x98b: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98e:
	/* 0x98e: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_991:
	/* 0x991: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_999:
	/* 0x999: je     1e70 <tail_handle_ipv4_cont+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7792ULL;
	}
x86_l_99f:
	/* 0x99f: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_9a2:
	/* 0x9a2: shr    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_9a6:
	/* 0x9a6: movzx  ecx,BYTE PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_9ab:
	/* 0x9ab: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9ae:
	/* 0x9ae: mov    QWORD PTR [rsp+0xc8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_9b6:
	/* 0x9b6: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_9bd:
	/* 0x9bd: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9c0:
	/* 0x9c0: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c5:
	/* 0x9c5: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_9ca:
	/* 0x9ca: mov    BYTE PTR [rsp+0x23],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_9cf:
	/* 0x9cf: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_9d2:
	/* 0x9d2: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9d6:
	/* 0x9d6: mov    DWORD PTR [rsp+0x24],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9da:
	/* 0x9da: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9de:
	/* 0x9de: cmp    r12b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 71ULL);
x86_l_9e2:
	/* 0x9e2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e7:
	/* 0x9e7: mov    QWORD PTR [rsp+0xa0],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_9ef:
	/* 0x9ef: ja     168e <tail_handle_ipv4_cont+0x168e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5774ULL;
	}
x86_l_9f5:
	/* 0x9f5: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_9f9:
	/* 0x9f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9fb:
	/* 0x9fb: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_9fe:
	/* 0x9fe: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a02:
	/* 0xa02: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_a06:
	/* 0xa06: jmp    1dee <tail_handle_ipv4_cont+0x1dee> */
	return 7662ULL;
x86_l_a0b:
	/* 0xa0b: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_a11:
	/* 0xa11: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a18:
	/* 0xa18: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a20:
	/* 0xa20: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_a2b:
	/* 0xa2b: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a32:
	/* 0xa32: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a34:
	/* 0xa34: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_a3c:
	/* 0xa3c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3e:
	/* 0xa3e: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a43:
	/* 0xa43: jmp    1ef4 <tail_handle_ipv4_cont+0x1ef4> */
	return 7924ULL;
x86_l_a48:
	/* 0xa48: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_a51:
	/* 0xa51: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a56:
	/* 0xa56: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a5b:
	/* 0xa5b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a62:
	/* 0xa62: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a67:
	/* 0xa67: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a6c:
	/* 0xa6c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a6e:
	/* 0xa6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a70:
	/* 0xa70: cmp    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_a78:
	/* 0xa78: je     1c67 <tail_handle_ipv4_cont+0x1c67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7271ULL;
	}
x86_l_a7e:
	/* 0xa7e: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_a85:
	/* 0xa85: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a88:
	/* 0xa88: je     1bac <tail_handle_ipv4_cont+0x1bac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7084ULL;
	}
x86_l_a8e:
	/* 0xa8e: mov    DWORD PTR [rsp+0x90],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a96:
	/* 0xa96: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a9b:
	/* 0xa9b: mov    DWORD PTR [rsp+0xc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_aa0:
	/* 0xaa0: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_aa7:
	/* 0xaa7: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa9:
	/* 0xaa9: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ab1:
	/* 0xab1: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab4:
	/* 0xab4: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_ab9:
	/* 0xab9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abb:
	/* 0xabb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_abd:
	/* 0xabd: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ac0:
	/* 0xac0: mov    DWORD PTR [rsp+0x110],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104514ULL);
x86_l_acb:
	/* 0xacb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad0:
	/* 0xad0: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_ad7:
	/* 0xad7: lea    rsi,[rsp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_adf:
	/* 0xadf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae1:
	/* 0xae1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_ae4:
	/* 0xae4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ae7:
	/* 0xae7: jne    b18 <tail_handle_ipv4_cont+0xb18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b18;
	}
x86_l_ae9:
	/* 0xae9: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_af2:
	/* 0xaf2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_af7:
	/* 0xaf7: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_afe:
	/* 0xafe: lea    rsi,[rsp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_b06:
	/* 0xb06: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b09:
	/* 0xb09: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b0b:
	/* 0xb0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0d:
	/* 0xb0d: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_b10:
	/* 0xb10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b12:
	/* 0xb12: js     23e9 <tail_handle_ipv4_cont+0x23e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9193ULL;
	}
x86_l_b18:
	/* 0xb18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b1d:
	/* 0xb1d: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_b24:
	/* 0xb24: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b2c:
	/* 0xb2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2e:
	/* 0xb2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b31:
	/* 0xb31: je     1949 <tail_handle_ipv4_cont+0x1949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6473ULL;
	}
x86_l_b37:
	/* 0xb37: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3a:
	/* 0xb3a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_b3d:
	/* 0xb3d: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b40:
	/* 0xb40: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_b47:
	/* 0xb47: jbe    1b86 <tail_handle_ipv4_cont+0x1b86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7046ULL;
	}
x86_l_b4d:
	/* 0xb4d: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_b50:
	/* 0xb50: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_b54:
	/* 0xb54: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_b5e:
	/* 0xb5e: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b63:
	/* 0xb63: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_b67:
	/* 0xb67: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_b6e:
	/* 0xb6e: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_b72:
	/* 0xb72: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b76:
	/* 0xb76: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7a:
	/* 0xb7a: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b7d:
	/* 0xb7d: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b80:
	/* 0xb80: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b83:
	/* 0xb83: mov    rdx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_b8b:
	/* 0xb8b: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_b8e:
	/* 0xb8e: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b93:
	/* 0xb93: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b98:
	/* 0xb98: jbe    1b94 <tail_handle_ipv4_cont+0x1b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 7060ULL;
	}
x86_l_b9e:
	/* 0xb9e: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba2:
	/* 0xba2: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_ba5:
	/* 0xba5: jmp    1b94 <tail_handle_ipv4_cont+0x1b94> */
	return 7060ULL;
x86_l_baa:
	/* 0xbaa: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bae:
	/* 0xbae: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_bb1:
	/* 0xbb1: je     164d <tail_handle_ipv4_cont+0x164d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5709ULL;
	}
x86_l_bb7:
	/* 0xbb7: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_bba:
	/* 0xbba: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bbe:
	/* 0xbbe: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bc1:
	/* 0xbc1: mov    ebp,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_bc8:
	/* 0xbc8: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_bd0:
	/* 0xbd0: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_bd7:
	/* 0xbd7: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd9:
	/* 0xbd9: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bdb:
	/* 0xbdb: mov    esi,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_be2:
	/* 0xbe2: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_be4:
	/* 0xbe4: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_be7:
	/* 0xbe7: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_be9:
	/* 0xbe9: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_bec:
	/* 0xbec: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_bf3:
	/* 0xbf3: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bf6:
	/* 0xbf6: mov    edx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bfc:
	/* 0xbfc: mov    WORD PTR [rsp+0x48],0x104 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645572ULL);
x86_l_c03:
	/* 0xc03: mov    WORD PTR [rsp+0x4a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_c08:
	/* 0xc08: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_c0c:
	/* 0xc0c: mov    DWORD PTR [rsp+0x50],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c11:
	/* 0xc11: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_c16:
	/* 0xc16: mov    WORD PTR [rsp+0x56],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187458ULL);
x86_l_c1d:
	/* 0xc1d: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c21:
	/* 0xc21: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_c29:
	/* 0xc29: mov    WORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_c30:
	/* 0xc30: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c34:
	/* 0xc34: mov    BYTE PTR [rsp+0x62],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_c38:
	/* 0xc38: mov    BYTE PTR [rsp+0x63],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762304ULL);
x86_l_c3d:
	/* 0xc3d: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_c45:
	/* 0xc45: mov    QWORD PTR [rsp+0x78],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c4a:
	/* 0xc4a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_c53:
	/* 0xc53: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_c5c:
	/* 0xc5c: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_c62:
	/* 0xc62: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_c66:
	/* 0xc66: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_c6b:
	/* 0xc6b: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c6e:
	/* 0xc6e: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_c75:
	/* 0xc75: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c7a:
	/* 0xc7a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c7d:
	/* 0xc7d: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_c83:
	/* 0xc83: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_c86:
	/* 0xc86: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_c8d:
	/* 0xc8d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c90:
	/* 0xc90: je     1660 <tail_handle_ipv4_cont+0x1660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5728ULL;
	}
x86_l_c96:
	/* 0xc96: mov    ecx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_c9b:
	/* 0xc9b: or     ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 168ULL);
x86_l_ca1:
	/* 0xca1: jmp    1665 <tail_handle_ipv4_cont+0x1665> */
	return 5733ULL;
x86_l_ca6:
	/* 0xca6: cmp    r12b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 191ULL);
x86_l_caa:
	/* 0xcaa: ja     18fc <tail_handle_ipv4_cont+0x18fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6396ULL;
	}
x86_l_cb0:
	/* 0xcb0: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_cb2:
	/* 0xcb2: sub    cl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_cb5:
	/* 0xcb5: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_cba:
	/* 0xcba: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_cbf:
	/* 0xcbf: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_cc3:
	/* 0xcc3: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cca:
	/* 0xcca: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_ccc:
	/* 0xccc: jmp    1903 <tail_handle_ipv4_cont+0x1903> */
	return 6403ULL;
x86_l_cd1:
	/* 0xcd1: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_cd7:
	/* 0xcd7: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cdc:
	/* 0xcdc: je     ced <tail_handle_ipv4_cont+0xced> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ced;
	}
x86_l_cde:
	/* 0xcde: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_ce3:
	/* 0xce3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce5:
	/* 0xce5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ce7:
	/* 0xce7: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_ceb:
	/* 0xceb: jmp    d10 <tail_handle_ipv4_cont+0xd10> */
	goto x86_l_d10;
x86_l_ced:
	/* 0xced: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_cf2:
	/* 0xcf2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cf4:
	/* 0xcf4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cf6:
	/* 0xcf6: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_cfa:
	/* 0xcfa: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d04:
	/* 0xd04: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d07:
	/* 0xd07: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d0c:
	/* 0xd0c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d10:
	/* 0xd10: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_d14:
	/* 0xd14: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_d17:
	/* 0xd17: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d1a:
	/* 0xd1a: mov    DWORD PTR [rsp+0x68],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d1f:
	/* 0xd1f: movzx  edx,BYTE PTR [rsp+0x72] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 114ULL);
x86_l_d24:
	/* 0xd24: mov    esi,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d28:
	/* 0xd28: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_d2a:
	/* 0xd2a: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d2f:
	/* 0xd2f: je     d42 <tail_handle_ipv4_cont+0xd42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d42;
	}
x86_l_d31:
	/* 0xd31: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d38:
	/* 0xd38: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d3a:
	/* 0xd3a: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_d3d:
	/* 0xd3d: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d40:
	/* 0xd40: jmp    d47 <tail_handle_ipv4_cont+0xd47> */
	goto x86_l_d47;
x86_l_d42:
	/* 0xd42: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_d47:
	/* 0xd47: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_d4a:
	/* 0xd4a: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d4f:
	/* 0xd4f: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d51:
	/* 0xd51: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_d53:
	/* 0xd53: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_d55:
	/* 0xd55: jb     d5b <tail_handle_ipv4_cont+0xd5b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d5b;
	}
x86_l_d57:
	/* 0xd57: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_d59:
	/* 0xd59: je     d6c <tail_handle_ipv4_cont+0xd6c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6c;
	}
x86_l_d5b:
	/* 0xd5b: mov    BYTE PTR [rsp+0x72],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 114ULL);
x86_l_d5f:
	/* 0xd5f: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d63:
	/* 0xd63: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_d6a:
	/* 0xd6a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6c:
	/* 0xd6c: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6f:
	/* 0xd6f: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d73:
	/* 0xd73: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d77:
	/* 0xd77: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d7b:
	/* 0xd7b: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d83:
	/* 0xd83: mov    BYTE PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_d88:
	/* 0xd88: movzx  eax,BYTE PTR [r14+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_d8d:
	/* 0xd8d: or     al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_d8f:
	/* 0xd8f: mov    BYTE PTR [rsp+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_d93:
	/* 0xd93: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d98:
	/* 0xd98: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_d9f:
	/* 0xd9f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da4:
	/* 0xda4: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_da9:
	/* 0xda9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dab:
	/* 0xdab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dad:
	/* 0xdad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_daf:
	/* 0xdaf: js     12a5 <tail_handle_ipv4_cont+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4773ULL;
	}
x86_l_db5:
	/* 0xdb5: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_dbc:
	/* 0xdbc: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbf:
	/* 0xdbf: je     dd2 <tail_handle_ipv4_cont+0xdd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd2;
	}
x86_l_dc1:
	/* 0xdc1: mov    QWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_dca:
	/* 0xdca: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dcd:
	/* 0xdcd: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_dd2:
	/* 0xdd2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dd7:
	/* 0xdd7: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ddc:
	/* 0xddc: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_de4:
	/* 0xde4: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_de7:
	/* 0xde7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de9:
	/* 0xde9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_deb:
	/* 0xdeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ded:
	/* 0xded: js     12a5 <tail_handle_ipv4_cont+0x12a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4773ULL;
	}
x86_l_df3:
	/* 0xdf3: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df7:
	/* 0xdf7: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_dfe:
	/* 0xdfe: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e01:
	/* 0xe01: mov    QWORD PTR [rsp+0x110],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_e09:
	/* 0xe09: cmp    WORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_e12:
	/* 0xe12: je     e5a <tail_handle_ipv4_cont+0xe5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3674ULL;
	}
x86_l_e14:
	/* 0xe14: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_e1b:
	/* 0xe1b: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1e:
	/* 0xe1e: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_e25:
	/* 0xe25: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e28:
	/* 0xe28: je     fa5 <tail_handle_ipv4_cont+0xfa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4005ULL;
	}
x86_l_e2e:
	/* 0xe2e: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e36:
	/* 0xe36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3b:
	/* 0xe3b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_e42:
	/* 0xe42: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e47:
	/* 0xe47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e49:
	/* 0xe49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: je     faa <tail_handle_ipv4_cont+0xfaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4010ULL;
	}
x86_l_e52:
	/* 0xe52: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 3669ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3681ULL: goto x86_l_e61;
	case 3686ULL: goto x86_l_e66;
	case 3693ULL: goto x86_l_e6d;
	case 3700ULL: goto x86_l_e74;
	case 3703ULL: goto x86_l_e77;
	case 3705ULL: goto x86_l_e79;
	case 3712ULL: goto x86_l_e80;
	case 3714ULL: goto x86_l_e82;
	case 3721ULL: goto x86_l_e89;
	case 3723ULL: goto x86_l_e8b;
	case 3726ULL: goto x86_l_e8e;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3737ULL: goto x86_l_e99;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3753ULL: goto x86_l_ea9;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3764ULL: goto x86_l_eb4;
	case 3766ULL: goto x86_l_eb6;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3776ULL: goto x86_l_ec0;
	case 3779ULL: goto x86_l_ec3;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3792ULL: goto x86_l_ed0;
	case 3800ULL: goto x86_l_ed8;
	case 3803ULL: goto x86_l_edb;
	case 3807ULL: goto x86_l_edf;
	case 3810ULL: goto x86_l_ee2;
	case 3812ULL: goto x86_l_ee4;
	case 3815ULL: goto x86_l_ee7;
	case 3823ULL: goto x86_l_eef;
	case 3827ULL: goto x86_l_ef3;
	case 3836ULL: goto x86_l_efc;
	case 3844ULL: goto x86_l_f04;
	case 3853ULL: goto x86_l_f0d;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3867ULL: goto x86_l_f1b;
	case 3874ULL: goto x86_l_f22;
	case 3879ULL: goto x86_l_f27;
	case 3881ULL: goto x86_l_f29;
	case 3884ULL: goto x86_l_f2c;
	case 3890ULL: goto x86_l_f32;
	case 3894ULL: goto x86_l_f36;
	case 3898ULL: goto x86_l_f3a;
	case 3904ULL: goto x86_l_f40;
	case 3908ULL: goto x86_l_f44;
	case 3914ULL: goto x86_l_f4a;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3930ULL: goto x86_l_f5a;
	case 3937ULL: goto x86_l_f61;
	case 3940ULL: goto x86_l_f64;
	case 3947ULL: goto x86_l_f6b;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3961ULL: goto x86_l_f79;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3981ULL: goto x86_l_f8d;
	case 3986ULL: goto x86_l_f92;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3997ULL: goto x86_l_f9d;
	case 4000ULL: goto x86_l_fa0;
	case 4005ULL: goto x86_l_fa5;
	case 4008ULL: goto x86_l_fa8;
	case 4010ULL: goto x86_l_faa;
	case 4013ULL: goto x86_l_fad;
	case 4017ULL: goto x86_l_fb1;
	case 4020ULL: goto x86_l_fb4;
	case 4032ULL: goto x86_l_fc0;
	case 4041ULL: goto x86_l_fc9;
	case 4050ULL: goto x86_l_fd2;
	case 4059ULL: goto x86_l_fdb;
	case 4068ULL: goto x86_l_fe4;
	case 4077ULL: goto x86_l_fed;
	case 4086ULL: goto x86_l_ff6;
	case 4095ULL: goto x86_l_fff;
	case 4103ULL: goto x86_l_1007;
	case 4109ULL: goto x86_l_100d;
	case 4116ULL: goto x86_l_1014;
	case 4119ULL: goto x86_l_1017;
	case 4121ULL: goto x86_l_1019;
	case 4127ULL: goto x86_l_101f;
	case 4135ULL: goto x86_l_1027;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4153ULL: goto x86_l_1039;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4170ULL: goto x86_l_104a;
	case 4173ULL: goto x86_l_104d;
	case 4178ULL: goto x86_l_1052;
	case 4180ULL: goto x86_l_1054;
	case 4182ULL: goto x86_l_1056;
	case 4185ULL: goto x86_l_1059;
	case 4192ULL: goto x86_l_1060;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4211ULL: goto x86_l_1073;
	case 4219ULL: goto x86_l_107b;
	case 4221ULL: goto x86_l_107d;
	case 4224ULL: goto x86_l_1080;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4238ULL: goto x86_l_108e;
	case 4243ULL: goto x86_l_1093;
	case 4250ULL: goto x86_l_109a;
	case 4258ULL: goto x86_l_10a2;
	case 4263ULL: goto x86_l_10a7;
	case 4266ULL: goto x86_l_10aa;
	case 4268ULL: goto x86_l_10ac;
	case 4270ULL: goto x86_l_10ae;
	case 4272ULL: goto x86_l_10b0;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4290ULL: goto x86_l_10c2;
	case 4298ULL: goto x86_l_10ca;
	case 4300ULL: goto x86_l_10cc;
	case 4303ULL: goto x86_l_10cf;
	case 4309ULL: goto x86_l_10d5;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4318ULL: goto x86_l_10de;
	case 4325ULL: goto x86_l_10e5;
	case 4331ULL: goto x86_l_10eb;
	case 4334ULL: goto x86_l_10ee;
	case 4338ULL: goto x86_l_10f2;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4357ULL: goto x86_l_1105;
	case 4364ULL: goto x86_l_110c;
	case 4368ULL: goto x86_l_1110;
	case 4372ULL: goto x86_l_1114;
	case 4376ULL: goto x86_l_1118;
	case 4379ULL: goto x86_l_111b;
	case 4382ULL: goto x86_l_111e;
	case 4385ULL: goto x86_l_1121;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4406ULL: goto x86_l_1136;
	case 4414ULL: goto x86_l_113e;
	case 4420ULL: goto x86_l_1144;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4432ULL: goto x86_l_1150;
	case 4439ULL: goto x86_l_1157;
	case 4441ULL: goto x86_l_1159;
	case 4452ULL: goto x86_l_1164;
	case 4464ULL: goto x86_l_1170;
	case 4473ULL: goto x86_l_1179;
	case 4482ULL: goto x86_l_1182;
	case 4491ULL: goto x86_l_118b;
	case 4500ULL: goto x86_l_1194;
	case 4509ULL: goto x86_l_119d;
	case 4518ULL: goto x86_l_11a6;
	case 4527ULL: goto x86_l_11af;
	case 4529ULL: goto x86_l_11b1;
	case 4534ULL: goto x86_l_11b6;
	case 4536ULL: goto x86_l_11b8;
	case 4538ULL: goto x86_l_11ba;
	case 4542ULL: goto x86_l_11be;
	case 4547ULL: goto x86_l_11c3;
	case 4555ULL: goto x86_l_11cb;
	case 4558ULL: goto x86_l_11ce;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4570ULL: goto x86_l_11da;
	case 4573ULL: goto x86_l_11dd;
	case 4575ULL: goto x86_l_11df;
	case 4581ULL: goto x86_l_11e5;
	case 4584ULL: goto x86_l_11e8;
	case 4588ULL: goto x86_l_11ec;
	case 4592ULL: goto x86_l_11f0;
	case 4596ULL: goto x86_l_11f4;
	case 4603ULL: goto x86_l_11fb;
	case 4606ULL: goto x86_l_11fe;
	case 4609ULL: goto x86_l_1201;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4622ULL: goto x86_l_120e;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4655ULL: goto x86_l_122f;
	case 4659ULL: goto x86_l_1233;
	case 4665ULL: goto x86_l_1239;
	case 4668ULL: goto x86_l_123c;
	case 4674ULL: goto x86_l_1242;
	case 4677ULL: goto x86_l_1245;
	case 4680ULL: goto x86_l_1248;
	case 4683ULL: goto x86_l_124b;
	case 4688ULL: goto x86_l_1250;
	case 4691ULL: goto x86_l_1253;
	case 4696ULL: goto x86_l_1258;
	case 4702ULL: goto x86_l_125e;
	case 4704ULL: goto x86_l_1260;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4717ULL: goto x86_l_126d;
	case 4722ULL: goto x86_l_1272;
	case 4726ULL: goto x86_l_1276;
	case 4729ULL: goto x86_l_1279;
	case 4733ULL: goto x86_l_127d;
	case 4738ULL: goto x86_l_1282;
	case 4743ULL: goto x86_l_1287;
	case 4748ULL: goto x86_l_128c;
	case 4753ULL: goto x86_l_1291;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4763ULL: goto x86_l_129b;
	case 4765ULL: goto x86_l_129d;
	case 4768ULL: goto x86_l_12a0;
	case 4773ULL: goto x86_l_12a5;
	case 4775ULL: goto x86_l_12a7;
	case 4780ULL: goto x86_l_12ac;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4810ULL: goto x86_l_12ca;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4827ULL: goto x86_l_12db;
	case 4829ULL: goto x86_l_12dd;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4847ULL: goto x86_l_12ef;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4865ULL: goto x86_l_1301;
	case 4867ULL: goto x86_l_1303;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4880ULL: goto x86_l_1310;
	case 4888ULL: goto x86_l_1318;
	case 4896ULL: goto x86_l_1320;
	case 4900ULL: goto x86_l_1324;
	case 4906ULL: goto x86_l_132a;
	case 4909ULL: goto x86_l_132d;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4921ULL: goto x86_l_1339;
	case 4924ULL: goto x86_l_133c;
	case 4927ULL: goto x86_l_133f;
	case 4932ULL: goto x86_l_1344;
	case 4935ULL: goto x86_l_1347;
	case 4940ULL: goto x86_l_134c;
	case 4946ULL: goto x86_l_1352;
	case 4948ULL: goto x86_l_1354;
	case 4950ULL: goto x86_l_1356;
	case 4956ULL: goto x86_l_135c;
	case 4961ULL: goto x86_l_1361;
	case 4966ULL: goto x86_l_1366;
	case 4969ULL: goto x86_l_1369;
	case 4974ULL: goto x86_l_136e;
	case 4979ULL: goto x86_l_1373;
	case 4982ULL: goto x86_l_1376;
	case 4984ULL: goto x86_l_1378;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4998ULL: goto x86_l_1386;
	case 5003ULL: goto x86_l_138b;
	case 5011ULL: goto x86_l_1393;
	case 5014ULL: goto x86_l_1396;
	case 5016ULL: goto x86_l_1398;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5028ULL: goto x86_l_13a4;
	case 5032ULL: goto x86_l_13a8;
	case 5038ULL: goto x86_l_13ae;
	case 5042ULL: goto x86_l_13b2;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5069ULL: goto x86_l_13cd;
	case 5074ULL: goto x86_l_13d2;
	case 5076ULL: goto x86_l_13d4;
	case 5079ULL: goto x86_l_13d7;
	case 5085ULL: goto x86_l_13dd;
	case 5088ULL: goto x86_l_13e0;
	case 5092ULL: goto x86_l_13e4;
	case 5097ULL: goto x86_l_13e9;
	case 5101ULL: goto x86_l_13ed;
	case 5106ULL: goto x86_l_13f2;
	case 5111ULL: goto x86_l_13f7;
	case 5119ULL: goto x86_l_13ff;
	case 5122ULL: goto x86_l_1402;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5135ULL: goto x86_l_140f;
	case 5138ULL: goto x86_l_1412;
	case 5146ULL: goto x86_l_141a;
	case 5153ULL: goto x86_l_1421;
	case 5155ULL: goto x86_l_1423;
	case 5159ULL: goto x86_l_1427;
	case 5166ULL: goto x86_l_142e;
	case 5168ULL: goto x86_l_1430;
	case 5170ULL: goto x86_l_1432;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5194ULL: goto x86_l_144a;
	case 5197ULL: goto x86_l_144d;
	case 5203ULL: goto x86_l_1453;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5219ULL: goto x86_l_1463;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5235ULL: goto x86_l_1473;
	case 5240ULL: goto x86_l_1478;
	case 5248ULL: goto x86_l_1480;
	case 5253ULL: goto x86_l_1485;
	case 5258ULL: goto x86_l_148a;
	case 5263ULL: goto x86_l_148f;
	case 5271ULL: goto x86_l_1497;
	case 5276ULL: goto x86_l_149c;
	case 5285ULL: goto x86_l_14a5;
	case 5294ULL: goto x86_l_14ae;
	case 5300ULL: goto x86_l_14b4;
	case 5304ULL: goto x86_l_14b8;
	case 5309ULL: goto x86_l_14bd;
	case 5312ULL: goto x86_l_14c0;
	case 5319ULL: goto x86_l_14c7;
	case 5324ULL: goto x86_l_14cc;
	case 5327ULL: goto x86_l_14cf;
	case 5333ULL: goto x86_l_14d5;
	case 5336ULL: goto x86_l_14d8;
	case 5340ULL: goto x86_l_14dc;
	case 5347ULL: goto x86_l_14e3;
	case 5350ULL: goto x86_l_14e6;
	case 5352ULL: goto x86_l_14e8;
	case 5359ULL: goto x86_l_14ef;
	case 5361ULL: goto x86_l_14f1;
	case 5368ULL: goto x86_l_14f8;
	case 5371ULL: goto x86_l_14fb;
	case 5377ULL: goto x86_l_1501;
	case 5383ULL: goto x86_l_1507;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5405ULL: goto x86_l_151d;
	case 5408ULL: goto x86_l_1520;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5418ULL: goto x86_l_152a;
	case 5421ULL: goto x86_l_152d;
	case 5426ULL: goto x86_l_1532;
	case 5433ULL: goto x86_l_1539;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5443ULL: goto x86_l_1543;
	case 5446ULL: goto x86_l_1546;
	case 5452ULL: goto x86_l_154c;
	case 5455ULL: goto x86_l_154f;
	case 5458ULL: goto x86_l_1552;
	case 5460ULL: goto x86_l_1554;
	case 5463ULL: goto x86_l_1557;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5477ULL: goto x86_l_1565;
	case 5479ULL: goto x86_l_1567;
	case 5484ULL: goto x86_l_156c;
	case 5491ULL: goto x86_l_1573;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e55:
	/* 0xe55: jmp    fad <tail_handle_ipv4_cont+0xfad> */
	goto x86_l_fad;
x86_l_e5a:
	/* 0xe5a: mov    eax,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_e61:
	/* 0xe61: or     ax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_e66:
	/* 0xe66: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_e6d:
	/* 0xe6d: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_e74:
	/* 0xe74: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e77:
	/* 0xe77: je     ed0 <tail_handle_ipv4_cont+0xed0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ed0;
	}
x86_l_e79:
	/* 0xe79: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_e80:
	/* 0xe80: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e82:
	/* 0xe82: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_e89:
	/* 0xe89: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8b:
	/* 0xe8b: mov    sil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 24ULL);
x86_l_e8e:
	/* 0xe8e: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_e91:
	/* 0xe91: sub    dil,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_e94:
	/* 0xe94: shrx   edx,eax,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RAX, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_e99:
	/* 0xe99: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9b:
	/* 0xe9b: bzhi   edx,edx,edi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RDI, 0);
x86_l_ea0:
	/* 0xea0: movzx  edi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ea3:
	/* 0xea3: and    edx,0x7fffff00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2147483392ULL);
x86_l_ea9:
	/* 0xea9: mov    r8d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eac:
	/* 0xeac: neg    r8b */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_eaf:
	/* 0xeaf: shlx   edx,edx,r8d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_R8, X86_ALU_SHL);
x86_l_eb4:
	/* 0xeb4: or     edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_eb6:
	/* 0xeb6: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb8:
	/* 0xeb8: sub    sil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_ebb:
	/* 0xebb: bzhi   eax,eax,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RSI, 0);
x86_l_ec0:
	/* 0xec0: shl    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_ec3:
	/* 0xec3: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_ec5:
	/* 0xec5: or     eax,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 3840ULL);
x86_l_eca:
	/* 0xeca: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ed0:
	/* 0xed0: test   BYTE PTR [rsp+0xd0],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 893353197569ULL);
x86_l_ed8:
	/* 0xed8: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_edb:
	/* 0xedb: cmp    r12b,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 2ULL);
x86_l_edf:
	/* 0xedf: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_ee2:
	/* 0xee2: or     cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_ee4:
	/* 0xee4: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ee7:
	/* 0xee7: mov    rcx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_eef:
	/* 0xeef: mov    eax,DWORD PTR [rcx+rax*4+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 26ULL);
x86_l_ef3:
	/* 0xef3: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_efc:
	/* 0xefc: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_f04:
	/* 0xf04: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_f0d:
	/* 0xf0d: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f11:
	/* 0xf11: mov    BYTE PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_f16:
	/* 0xf16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f1b:
	/* 0xf1b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_f22:
	/* 0xf22: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f27:
	/* 0xf27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f29:
	/* 0xf29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2c:
	/* 0xf2c: je     1150 <tail_handle_ipv4_cont+0x1150> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1150;
	}
x86_l_f32:
	/* 0xf32: test   BYTE PTR [rax+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_f36:
	/* 0xf36: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3a:
	/* 0xf3a: je     12fa <tail_handle_ipv4_cont+0x12fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12fa;
	}
x86_l_f40:
	/* 0xf40: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_f44:
	/* 0xf44: jne    15eb <tail_handle_ipv4_cont+0x15eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5611ULL;
	}
x86_l_f4a:
	/* 0xf4a: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_f51:
	/* 0xf51: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f53:
	/* 0xf53: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f5a:
	/* 0xf5a: mov    r14,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_f61:
	/* 0xf61: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f64:
	/* 0xf64: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_f6b:
	/* 0xf6b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6e:
	/* 0xf6e: mov    DWORD PTR [rsp+0xc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f73:
	/* 0xf73: je     16c9 <tail_handle_ipv4_cont+0x16c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5833ULL;
	}
x86_l_f79:
	/* 0xf79: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f81:
	/* 0xf81: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f86:
	/* 0xf86: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_f8d:
	/* 0xf8d: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f92:
	/* 0xf92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f94:
	/* 0xf94: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f97:
	/* 0xf97: je     16c9 <tail_handle_ipv4_cont+0x16c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5833ULL;
	}
x86_l_f9d:
	/* 0xf9d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa0:
	/* 0xfa0: jmp    16cb <tail_handle_ipv4_cont+0x16cb> */
	return 5835ULL;
x86_l_fa5:
	/* 0xfa5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa8:
	/* 0xfa8: jmp    fb1 <tail_handle_ipv4_cont+0xfb1> */
	goto x86_l_fb1;
x86_l_faa:
	/* 0xfaa: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fad:
	/* 0xfad: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fb1:
	/* 0xfb1: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fb4:
	/* 0xfb4: mov    QWORD PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_fc0:
	/* 0xfc0: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_fc9:
	/* 0xfc9: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_fd2:
	/* 0xfd2: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_fdb:
	/* 0xfdb: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_fe4:
	/* 0xfe4: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_fed:
	/* 0xfed: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_ff6:
	/* 0xff6: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_fff:
	/* 0xfff: cmp    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1007:
	/* 0x1007: je     14dc <tail_handle_ipv4_cont+0x14dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14dc;
	}
x86_l_100d:
	/* 0x100d: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1014:
	/* 0x1014: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1017:
	/* 0x1017: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1019:
	/* 0x1019: je     141a <tail_handle_ipv4_cont+0x141a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_141a;
	}
x86_l_101f:
	/* 0x101f: mov    QWORD PTR [rsp+0xd0],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1027:
	/* 0x1027: mov    DWORD PTR [rsp+0xd8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_102f:
	/* 0x102f: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1034:
	/* 0x1034: mov    DWORD PTR [rsp+0xc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1039:
	/* 0x1039: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1040:
	/* 0x1040: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1042:
	/* 0x1042: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_104a:
	/* 0x104a: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104d:
	/* 0x104d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1052:
	/* 0x1052: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1054:
	/* 0x1054: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1056:
	/* 0x1056: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1059:
	/* 0x1059: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1060:
	/* 0x1060: mov    DWORD PTR [rsp+0xbc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1067:
	/* 0x1067: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_106c:
	/* 0x106c: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1073:
	/* 0x1073: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_107b:
	/* 0x107b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107d:
	/* 0x107d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1080:
	/* 0x1080: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1083:
	/* 0x1083: jne    10b6 <tail_handle_ipv4_cont+0x10b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10b6;
	}
x86_l_1085:
	/* 0x1085: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_108e:
	/* 0x108e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1093:
	/* 0x1093: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_109a:
	/* 0x109a: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_10a2:
	/* 0x10a2: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10a7:
	/* 0x10a7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10aa:
	/* 0x10aa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ac:
	/* 0x10ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ae:
	/* 0x10ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b0:
	/* 0x10b0: js     1643 <tail_handle_ipv4_cont+0x1643> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5699ULL;
	}
x86_l_10b6:
	/* 0x10b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10bb:
	/* 0x10bb: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_10c2:
	/* 0x10c2: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10ca:
	/* 0x10ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10cc:
	/* 0x10cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10cf:
	/* 0x10cf: je     12b1 <tail_handle_ipv4_cont+0x12b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b1;
	}
x86_l_10d5:
	/* 0x10d5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d8:
	/* 0x10d8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_10db:
	/* 0x10db: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10de:
	/* 0x10de: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_10e5:
	/* 0x10e5: jbe    13e9 <tail_handle_ipv4_cont+0x13e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_13e9;
	}
x86_l_10eb:
	/* 0x10eb: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_10ee:
	/* 0x10ee: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_10f2:
	/* 0x10f2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_10fc:
	/* 0x10fc: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1101:
	/* 0x1101: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1105:
	/* 0x1105: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_110c:
	/* 0x110c: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_1110:
	/* 0x1110: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1114:
	/* 0x1114: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1118:
	/* 0x1118: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_111b:
	/* 0x111b: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_111e:
	/* 0x111e: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1121:
	/* 0x1121: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1129:
	/* 0x1129: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_112c:
	/* 0x112c: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1131:
	/* 0x1131: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1136:
	/* 0x1136: mov    r8,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_113e:
	/* 0x113e: jbe    13ff <tail_handle_ipv4_cont+0x13ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_13ff;
	}
x86_l_1144:
	/* 0x1144: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1148:
	/* 0x1148: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_114b:
	/* 0x114b: jmp    13ff <tail_handle_ipv4_cont+0x13ff> */
	goto x86_l_13ff;
x86_l_1150:
	/* 0x1150: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_rt_info)));
x86_l_1157:
	/* 0x1157: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1159:
	/* 0x1159: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1164:
	/* 0x1164: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1170:
	/* 0x1170: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1179:
	/* 0x1179: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1182:
	/* 0x1182: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_118b:
	/* 0x118b: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1194:
	/* 0x1194: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_119d:
	/* 0x119d: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_11a6:
	/* 0x11a6: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_11af:
	/* 0x11af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b1:
	/* 0x11b1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_11b6:
	/* 0x11b6: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_11b8:
	/* 0x11b8: je     11c3 <tail_handle_ipv4_cont+0x11c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11c3;
	}
x86_l_11ba:
	/* 0x11ba: mov    DWORD PTR [rsp+0x78],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11be:
	/* 0x11be: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11c3:
	/* 0x11c3: mov    rsi,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_11cb:
	/* 0x11cb: mov    edx,DWORD PTR [rsi+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_11ce:
	/* 0x11ce: mov    esi,DWORD PTR [rsi+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_11d1:
	/* 0x11d1: mov    BYTE PTR [rsp+0x48],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645314ULL);
x86_l_11d6:
	/* 0x11d6: mov    rdi,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11da:
	/* 0x11da: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_11dd:
	/* 0x11dd: je     11e5 <tail_handle_ipv4_cont+0x11e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11e5;
	}
x86_l_11df:
	/* 0x11df: mov    ecx,DWORD PTR [rdi+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_11e5:
	/* 0x11e5: mov    r15d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_32);
x86_l_11e8:
	/* 0x11e8: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11ec:
	/* 0x11ec: mov    DWORD PTR [rsp+0x58],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11f0:
	/* 0x11f0: mov    DWORD PTR [rsp+0x68],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_11f4:
	/* 0x11f4: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_11fb:
	/* 0x11fb: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11fe:
	/* 0x11fe: lea    ecx,[rax+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1201:
	/* 0x1201: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_1206:
	/* 0x1206: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_120b:
	/* 0x120b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_120e:
	/* 0x120e: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_1213:
	/* 0x1213: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1215:
	/* 0x1215: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1217:
	/* 0x1217: je     1222 <tail_handle_ipv4_cont+0x1222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1222;
	}
x86_l_1219:
	/* 0x1219: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_121c:
	/* 0x121c: jne    16b9 <tail_handle_ipv4_cont+0x16b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5817ULL;
	}
x86_l_1222:
	/* 0x1222: mov    r14d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1227:
	/* 0x1227: mov    rcx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_122f:
	/* 0x122f: movzx  edx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1233:
	/* 0x1233: mov    r12d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967100ULL);
x86_l_1239:
	/* 0x1239: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_123c:
	/* 0x123c: jb     23f9 <tail_handle_ipv4_cont+0x23f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9209ULL;
	}
x86_l_1242:
	/* 0x1242: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1245:
	/* 0x1245: mov    BYTE PTR [rcx+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1248:
	/* 0x1248: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_124b:
	/* 0x124b: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1250:
	/* 0x1250: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1253:
	/* 0x1253: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1258:
	/* 0x1258: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_125e:
	/* 0x125e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1260:
	/* 0x1260: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1262:
	/* 0x1262: js     23f3 <tail_handle_ipv4_cont+0x23f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9203ULL;
	}
x86_l_1268:
	/* 0x1268: lea    rax,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_126d:
	/* 0x126d: movzx  ecx,BYTE PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_1272:
	/* 0x1272: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1276:
	/* 0x1276: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1279:
	/* 0x1279: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_127d:
	/* 0x127d: mov    QWORD PTR [rsp+0x24],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1282:
	/* 0x1282: mov    QWORD PTR [rsp+0x2c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1287:
	/* 0x1287: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128c:
	/* 0x128c: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_1291:
	/* 0x1291: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1294:
	/* 0x1294: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_1299:
	/* 0x1299: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_129b:
	/* 0x129b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129d:
	/* 0x129d: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_12a0:
	/* 0x12a0: jmp    23f9 <tail_handle_ipv4_cont+0x23f9> */
	return 9209ULL;
x86_l_12a5:
	/* 0x12a5: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_12a7:
	/* 0x12a7: mov    ebp,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967141ULL);
x86_l_12ac:
	/* 0x12ac: jmp    22a <tail_handle_ipv4_cont+0x22a> */
	return 554ULL;
x86_l_12b1:
	/* 0x12b1: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b6:
	/* 0x12b6: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_12b9:
	/* 0x12b9: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12be:
	/* 0x12be: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12c3:
	/* 0x12c3: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_12ca:
	/* 0x12ca: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12d2:
	/* 0x12d2: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12d7:
	/* 0x12d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d9:
	/* 0x12d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12db:
	/* 0x12db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12dd:
	/* 0x12dd: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12e2:
	/* 0x12e2: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12e7:
	/* 0x12e7: mov    r8,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_12ef:
	/* 0x12ef: jns    140f <tail_handle_ipv4_cont+0x140f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_140f;
	}
x86_l_12f5:
	/* 0x12f5: jmp    1640 <tail_handle_ipv4_cont+0x1640> */
	return 5696ULL;
x86_l_12fa:
	/* 0x12fa: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1301:
	/* 0x1301: mov    ebp,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1303:
	/* 0x1303: mov    rcx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1307:
	/* 0x1307: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_130c:
	/* 0x130c: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1310:
	/* 0x1310: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1318:
	/* 0x1318: mov    rcx,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1320:
	/* 0x1320: movzx  edx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1324:
	/* 0x1324: mov    r12d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967100ULL);
x86_l_132a:
	/* 0x132a: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_132d:
	/* 0x132d: jb     1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5750ULL;
	}
x86_l_1333:
	/* 0x1333: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1336:
	/* 0x1336: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1339:
	/* 0x1339: mov    BYTE PTR [rcx+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_133c:
	/* 0x133c: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_133f:
	/* 0x133f: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1344:
	/* 0x1344: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1347:
	/* 0x1347: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_134c:
	/* 0x134c: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1352:
	/* 0x1352: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1354:
	/* 0x1354: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1356:
	/* 0x1356: js     2489 <tail_handle_ipv4_cont+0x2489> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9353ULL;
	}
x86_l_135c:
	/* 0x135c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1361:
	/* 0x1361: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1366:
	/* 0x1366: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1369:
	/* 0x1369: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_136e:
	/* 0x136e: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1373:
	/* 0x1373: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1376:
	/* 0x1376: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1378:
	/* 0x1378: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_137e:
	/* 0x137e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1380:
	/* 0x1380: js     29aa <tail_handle_ipv4_cont+0x29aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10666ULL;
	}
x86_l_1386:
	/* 0x1386: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_138b:
	/* 0x138b: lea    rdx,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1393:
	/* 0x1393: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1396:
	/* 0x1396: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1398:
	/* 0x1398: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_139d:
	/* 0x139d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a0:
	/* 0x13a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a2:
	/* 0x13a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a4:
	/* 0x13a4: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a8:
	/* 0x13a8: js     1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5750ULL;
	}
x86_l_13ae:
	/* 0x13ae: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13b2:
	/* 0x13b2: movabs rax,0x6d00840200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 468160086528ULL);
x86_l_13bc:
	/* 0x13bc: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c1:
	/* 0x13c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c6:
	/* 0x13c6: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_13cd:
	/* 0x13cd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13d2:
	/* 0x13d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d4:
	/* 0x13d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d7:
	/* 0x13d7: je     2949 <tail_handle_ipv4_cont+0x2949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10569ULL;
	}
x86_l_13dd:
	/* 0x13dd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_13e0:
	/* 0x13e0: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13e4:
	/* 0x13e4: jmp    2971 <tail_handle_ipv4_cont+0x2971> */
	return 10609ULL;
x86_l_13e9:
	/* 0x13e9: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ed:
	/* 0x13ed: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13f2:
	/* 0x13f2: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13f7:
	/* 0x13f7: mov    r8,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_13ff:
	/* 0x13ff: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1402:
	/* 0x1402: je     1640 <tail_handle_ipv4_cont+0x1640> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5696ULL;
	}
x86_l_1408:
	/* 0x1408: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_140b:
	/* 0x140b: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140f:
	/* 0x140f: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1412:
	/* 0x1412: mov    r15d,DWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_141a:
	/* 0x141a: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1421:
	/* 0x1421: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1423:
	/* 0x1423: rol    dx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1427:
	/* 0x1427: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_142e:
	/* 0x142e: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1430:
	/* 0x1430: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1432:
	/* 0x1432: mov    edi,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1439:
	/* 0x1439: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_143b:
	/* 0x143b: cmovne eax,edi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_143e:
	/* 0x143e: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1440:
	/* 0x1440: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1443:
	/* 0x1443: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_144a:
	/* 0x144a: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_144d:
	/* 0x144d: mov    esi,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1453:
	/* 0x1453: mov    WORD PTR [rsp+0x48],0x104 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645572ULL);
x86_l_145a:
	/* 0x145a: mov    WORD PTR [rsp+0x4a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_145f:
	/* 0x145f: mov    DWORD PTR [rsp+0x4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1463:
	/* 0x1463: mov    DWORD PTR [rsp+0x50],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1467:
	/* 0x1467: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_146c:
	/* 0x146c: mov    WORD PTR [rsp+0x56],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187458ULL);
x86_l_1473:
	/* 0x1473: mov    DWORD PTR [rsp+0x58],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1478:
	/* 0x1478: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_1480:
	/* 0x1480: mov    WORD PTR [rsp+0x60],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1485:
	/* 0x1485: mov    BYTE PTR [rsp+0x62],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_148a:
	/* 0x148a: mov    BYTE PTR [rsp+0x63],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762304ULL);
x86_l_148f:
	/* 0x148f: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_1497:
	/* 0x1497: mov    QWORD PTR [rsp+0x78],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_149c:
	/* 0x149c: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_14a5:
	/* 0x14a5: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_14ae:
	/* 0x14ae: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_14b4:
	/* 0x14b4: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_14b8:
	/* 0x14b8: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_14bd:
	/* 0x14bd: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_14c0:
	/* 0x14c0: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_14c7:
	/* 0x14c7: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14cc:
	/* 0x14cc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14cf:
	/* 0x14cf: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_14d5:
	/* 0x14d5: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_14d8:
	/* 0x14d8: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14dc:
	/* 0x14dc: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_14e3:
	/* 0x14e3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e6:
	/* 0x14e6: je     14f1 <tail_handle_ipv4_cont+0x14f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f1;
	}
x86_l_14e8:
	/* 0x14e8: or     BYTE PTR [rbx+0xa9],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 725849473026ULL);
x86_l_14ef:
	/* 0x14ef: jmp    1507 <tail_handle_ipv4_cont+0x1507> */
	goto x86_l_1507;
x86_l_14f1:
	/* 0x14f1: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14f8:
	/* 0x14f8: shl    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_14fb:
	/* 0x14fb: or     ecx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_1501:
	/* 0x1501: mov    DWORD PTR [rbx+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1507:
	/* 0x1507: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150a:
	/* 0x150a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150d:
	/* 0x150d: je     1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5750ULL;
	}
x86_l_1513:
	/* 0x1513: movzx  ebp,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1518:
	/* 0x1518: rol    DWORD PTR [r14+0x8],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 34359738384ULL);
x86_l_151d:
	/* 0x151d: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1520:
	/* 0x1520: jne    156c <tail_handle_ipv4_cont+0x156c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_156c;
	}
x86_l_1522:
	/* 0x1522: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_1527:
	/* 0x1527: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_152a:
	/* 0x152a: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_152d:
	/* 0x152d: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1532:
	/* 0x1532: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1539:
	/* 0x1539: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153c:
	/* 0x153c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153e:
	/* 0x153e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1543:
	/* 0x1543: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1546:
	/* 0x1546: je     178a <tail_handle_ipv4_cont+0x178a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6026ULL;
	}
x86_l_154c:
	/* 0x154c: mov    ecx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_154f:
	/* 0x154f: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1552:
	/* 0x1552: je     155d <tail_handle_ipv4_cont+0x155d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_155d;
	}
x86_l_1554:
	/* 0x1554: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_1557:
	/* 0x1557: jne    175c <tail_handle_ipv4_cont+0x175c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5980ULL;
	}
x86_l_155d:
	/* 0x155d: mov    ecx,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 86ULL);
x86_l_1562:
	/* 0x1562: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1565:
	/* 0x1565: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1567:
	/* 0x1567: jmp    178a <tail_handle_ipv4_cont+0x178a> */
	return 6026ULL;
x86_l_156c:
	/* 0x156c: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1573:
	/* 0x1573: mov    WORD PTR [r14+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
	return 5496ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5496ULL: goto x86_l_1578;
	case 5503ULL: goto x86_l_157f;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5519ULL: goto x86_l_158f;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5533ULL: goto x86_l_159d;
	case 5536ULL: goto x86_l_15a0;
	case 5541ULL: goto x86_l_15a5;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5553ULL: goto x86_l_15b1;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5587ULL: goto x86_l_15d3;
	case 5589ULL: goto x86_l_15d5;
	case 5591ULL: goto x86_l_15d7;
	case 5597ULL: goto x86_l_15dd;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5614ULL: goto x86_l_15ee;
	case 5617ULL: goto x86_l_15f1;
	case 5624ULL: goto x86_l_15f8;
	case 5626ULL: goto x86_l_15fa;
	case 5633ULL: goto x86_l_1601;
	case 5636ULL: goto x86_l_1604;
	case 5643ULL: goto x86_l_160b;
	case 5649ULL: goto x86_l_1611;
	case 5657ULL: goto x86_l_1619;
	case 5662ULL: goto x86_l_161e;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5676ULL: goto x86_l_162c;
	case 5679ULL: goto x86_l_162f;
	case 5682ULL: goto x86_l_1632;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5699ULL: goto x86_l_1643;
	case 5704ULL: goto x86_l_1648;
	case 5709ULL: goto x86_l_164d;
	case 5712ULL: goto x86_l_1650;
	case 5719ULL: goto x86_l_1657;
	case 5722ULL: goto x86_l_165a;
	case 5728ULL: goto x86_l_1660;
	case 5733ULL: goto x86_l_1665;
	case 5736ULL: goto x86_l_1668;
	case 5742ULL: goto x86_l_166e;
	case 5745ULL: goto x86_l_1671;
	case 5747ULL: goto x86_l_1673;
	case 5750ULL: goto x86_l_1676;
	case 5753ULL: goto x86_l_1679;
	case 5759ULL: goto x86_l_167f;
	case 5763ULL: goto x86_l_1683;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5778ULL: goto x86_l_1692;
	case 5784ULL: goto x86_l_1698;
	case 5786ULL: goto x86_l_169a;
	case 5789ULL: goto x86_l_169d;
	case 5794ULL: goto x86_l_16a2;
	case 5799ULL: goto x86_l_16a7;
	case 5803ULL: goto x86_l_16ab;
	case 5810ULL: goto x86_l_16b2;
	case 5812ULL: goto x86_l_16b4;
	case 5817ULL: goto x86_l_16b9;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5828ULL: goto x86_l_16c4;
	case 5833ULL: goto x86_l_16c9;
	case 5835ULL: goto x86_l_16cb;
	case 5843ULL: goto x86_l_16d3;
	case 5847ULL: goto x86_l_16d7;
	case 5859ULL: goto x86_l_16e3;
	case 5868ULL: goto x86_l_16ec;
	case 5877ULL: goto x86_l_16f5;
	case 5886ULL: goto x86_l_16fe;
	case 5895ULL: goto x86_l_1707;
	case 5904ULL: goto x86_l_1710;
	case 5913ULL: goto x86_l_1719;
	case 5922ULL: goto x86_l_1722;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5957ULL: goto x86_l_1745;
	case 5959ULL: goto x86_l_1747;
	case 5962ULL: goto x86_l_174a;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5975ULL: goto x86_l_1757;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 6000ULL: goto x86_l_1770;
	case 6002ULL: goto x86_l_1772;
	case 6005ULL: goto x86_l_1775;
	case 6010ULL: goto x86_l_177a;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6020ULL: goto x86_l_1784;
	case 6026ULL: goto x86_l_178a;
	case 6033ULL: goto x86_l_1791;
	case 6038ULL: goto x86_l_1796;
	case 6045ULL: goto x86_l_179d;
	case 6055ULL: goto x86_l_17a7;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6066ULL: goto x86_l_17b2;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6081ULL: goto x86_l_17c1;
	case 6084ULL: goto x86_l_17c4;
	case 6086ULL: goto x86_l_17c6;
	case 6091ULL: goto x86_l_17cb;
	case 6094ULL: goto x86_l_17ce;
	case 6096ULL: goto x86_l_17d0;
	case 6101ULL: goto x86_l_17d5;
	case 6106ULL: goto x86_l_17da;
	case 6111ULL: goto x86_l_17df;
	case 6114ULL: goto x86_l_17e2;
	case 6116ULL: goto x86_l_17e4;
	case 6118ULL: goto x86_l_17e6;
	case 6120ULL: goto x86_l_17e8;
	case 6126ULL: goto x86_l_17ee;
	case 6130ULL: goto x86_l_17f2;
	case 6135ULL: goto x86_l_17f7;
	case 6140ULL: goto x86_l_17fc;
	case 6142ULL: goto x86_l_17fe;
	case 6144ULL: goto x86_l_1800;
	case 6150ULL: goto x86_l_1806;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6163ULL: goto x86_l_1813;
	case 6171ULL: goto x86_l_181b;
	case 6174ULL: goto x86_l_181e;
	case 6176ULL: goto x86_l_1820;
	case 6182ULL: goto x86_l_1826;
	case 6185ULL: goto x86_l_1829;
	case 6191ULL: goto x86_l_182f;
	case 6196ULL: goto x86_l_1834;
	case 6199ULL: goto x86_l_1837;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6214ULL: goto x86_l_1846;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6224ULL: goto x86_l_1850;
	case 6227ULL: goto x86_l_1853;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6248ULL: goto x86_l_1868;
	case 6251ULL: goto x86_l_186b;
	case 6253ULL: goto x86_l_186d;
	case 6255ULL: goto x86_l_186f;
	case 6257ULL: goto x86_l_1871;
	case 6263ULL: goto x86_l_1877;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6279ULL: goto x86_l_1887;
	case 6283ULL: goto x86_l_188b;
	case 6288ULL: goto x86_l_1890;
	case 6293ULL: goto x86_l_1895;
	case 6296ULL: goto x86_l_1898;
	case 6299ULL: goto x86_l_189b;
	case 6304ULL: goto x86_l_18a0;
	case 6311ULL: goto x86_l_18a7;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6324ULL: goto x86_l_18b4;
	case 6326ULL: goto x86_l_18b6;
	case 6331ULL: goto x86_l_18bb;
	case 6336ULL: goto x86_l_18c0;
	case 6341ULL: goto x86_l_18c5;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6356ULL: goto x86_l_18d4;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6372ULL: goto x86_l_18e4;
	case 6376ULL: goto x86_l_18e8;
	case 6381ULL: goto x86_l_18ed;
	case 6387ULL: goto x86_l_18f3;
	case 6391ULL: goto x86_l_18f7;
	case 6396ULL: goto x86_l_18fc;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6432ULL: goto x86_l_1920;
	case 6435ULL: goto x86_l_1923;
	case 6441ULL: goto x86_l_1929;
	case 6450ULL: goto x86_l_1932;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6468ULL: goto x86_l_1944;
	case 6473ULL: goto x86_l_1949;
	case 6478ULL: goto x86_l_194e;
	case 6481ULL: goto x86_l_1951;
	case 6486ULL: goto x86_l_1956;
	case 6491ULL: goto x86_l_195b;
	case 6498ULL: goto x86_l_1962;
	case 6506ULL: goto x86_l_196a;
	case 6511ULL: goto x86_l_196f;
	case 6513ULL: goto x86_l_1971;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6527ULL: goto x86_l_197f;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6551ULL: goto x86_l_1997;
	case 6554ULL: goto x86_l_199a;
	case 6558ULL: goto x86_l_199e;
	case 6570ULL: goto x86_l_19aa;
	case 6579ULL: goto x86_l_19b3;
	case 6588ULL: goto x86_l_19bc;
	case 6597ULL: goto x86_l_19c5;
	case 6606ULL: goto x86_l_19ce;
	case 6615ULL: goto x86_l_19d7;
	case 6624ULL: goto x86_l_19e0;
	case 6633ULL: goto x86_l_19e9;
	case 6643ULL: goto x86_l_19f3;
	case 6649ULL: goto x86_l_19f9;
	case 6654ULL: goto x86_l_19fe;
	case 6659ULL: goto x86_l_1a03;
	case 6666ULL: goto x86_l_1a0a;
	case 6671ULL: goto x86_l_1a0f;
	case 6674ULL: goto x86_l_1a12;
	case 6676ULL: goto x86_l_1a14;
	case 6679ULL: goto x86_l_1a17;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6688ULL: goto x86_l_1a20;
	case 6690ULL: goto x86_l_1a22;
	case 6699ULL: goto x86_l_1a2b;
	case 6704ULL: goto x86_l_1a30;
	case 6709ULL: goto x86_l_1a35;
	case 6716ULL: goto x86_l_1a3c;
	case 6721ULL: goto x86_l_1a41;
	case 6726ULL: goto x86_l_1a46;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6738ULL: goto x86_l_1a52;
	case 6744ULL: goto x86_l_1a58;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6760ULL: goto x86_l_1a68;
	case 6768ULL: goto x86_l_1a70;
	case 6773ULL: goto x86_l_1a75;
	case 6780ULL: goto x86_l_1a7c;
	case 6782ULL: goto x86_l_1a7e;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6807ULL: goto x86_l_1a97;
	case 6809ULL: goto x86_l_1a99;
	case 6812ULL: goto x86_l_1a9c;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6835ULL: goto x86_l_1ab3;
	case 6843ULL: goto x86_l_1abb;
	case 6845ULL: goto x86_l_1abd;
	case 6848ULL: goto x86_l_1ac0;
	case 6851ULL: goto x86_l_1ac3;
	case 6853ULL: goto x86_l_1ac5;
	case 6862ULL: goto x86_l_1ace;
	case 6867ULL: goto x86_l_1ad3;
	case 6874ULL: goto x86_l_1ada;
	case 6882ULL: goto x86_l_1ae2;
	case 6885ULL: goto x86_l_1ae5;
	case 6887ULL: goto x86_l_1ae7;
	case 6889ULL: goto x86_l_1ae9;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6912ULL: goto x86_l_1b00;
	case 6920ULL: goto x86_l_1b08;
	case 6922ULL: goto x86_l_1b0a;
	case 6925ULL: goto x86_l_1b0d;
	case 6931ULL: goto x86_l_1b13;
	case 6934ULL: goto x86_l_1b16;
	case 6937ULL: goto x86_l_1b19;
	case 6940ULL: goto x86_l_1b1c;
	case 6947ULL: goto x86_l_1b23;
	case 6953ULL: goto x86_l_1b29;
	case 6956ULL: goto x86_l_1b2c;
	case 6960ULL: goto x86_l_1b30;
	case 6970ULL: goto x86_l_1b3a;
	case 6975ULL: goto x86_l_1b3f;
	case 6979ULL: goto x86_l_1b43;
	case 6986ULL: goto x86_l_1b4a;
	case 6995ULL: goto x86_l_1b53;
	case 6999ULL: goto x86_l_1b57;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7009ULL: goto x86_l_1b61;
	case 7012ULL: goto x86_l_1b64;
	case 7020ULL: goto x86_l_1b6c;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7034ULL: goto x86_l_1b7a;
	case 7038ULL: goto x86_l_1b7e;
	case 7041ULL: goto x86_l_1b81;
	case 7046ULL: goto x86_l_1b86;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7063ULL: goto x86_l_1b97;
	case 7069ULL: goto x86_l_1b9d;
	case 7072ULL: goto x86_l_1ba0;
	case 7076ULL: goto x86_l_1ba4;
	case 7084ULL: goto x86_l_1bac;
	case 7091ULL: goto x86_l_1bb3;
	case 7093ULL: goto x86_l_1bb5;
	case 7095ULL: goto x86_l_1bb7;
	case 7102ULL: goto x86_l_1bbe;
	case 7104ULL: goto x86_l_1bc0;
	case 7107ULL: goto x86_l_1bc3;
	case 7110ULL: goto x86_l_1bc6;
	case 7112ULL: goto x86_l_1bc8;
	case 7115ULL: goto x86_l_1bcb;
	case 7122ULL: goto x86_l_1bd2;
	case 7125ULL: goto x86_l_1bd5;
	case 7131ULL: goto x86_l_1bdb;
	case 7138ULL: goto x86_l_1be2;
	case 7143ULL: goto x86_l_1be7;
	case 7147ULL: goto x86_l_1beb;
	case 7151ULL: goto x86_l_1bef;
	case 7156ULL: goto x86_l_1bf4;
	case 7163ULL: goto x86_l_1bfb;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7198ULL: goto x86_l_1c1e;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7220ULL: goto x86_l_1c34;
	case 7229ULL: goto x86_l_1c3d;
	case 7235ULL: goto x86_l_1c43;
	case 7239ULL: goto x86_l_1c47;
	case 7244ULL: goto x86_l_1c4c;
	case 7247ULL: goto x86_l_1c4f;
	case 7254ULL: goto x86_l_1c56;
	case 7259ULL: goto x86_l_1c5b;
	case 7262ULL: goto x86_l_1c5e;
	case 7268ULL: goto x86_l_1c64;
	case 7271ULL: goto x86_l_1c67;
	case 7276ULL: goto x86_l_1c6c;
	case 7283ULL: goto x86_l_1c73;
	case 7286ULL: goto x86_l_1c76;
	case 7291ULL: goto x86_l_1c7b;
	case 7293ULL: goto x86_l_1c7d;
	case 7298ULL: goto x86_l_1c82;
	case 7301ULL: goto x86_l_1c85;
	case 7306ULL: goto x86_l_1c8a;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7325ULL: goto x86_l_1c9d;
	case 7332ULL: goto x86_l_1ca4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1578:
	/* 0x1578: mov    WORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_157f:
	/* 0x157f: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_1589:
	/* 0x1589: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158c:
	/* 0x158c: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_158f:
	/* 0x158f: jne    1813 <tail_handle_ipv4_cont+0x1813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1813;
	}
x86_l_1595:
	/* 0x1595: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_159a:
	/* 0x159a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_159d:
	/* 0x159d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_15a0:
	/* 0x15a0: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_15a5:
	/* 0x15a5: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15ac:
	/* 0x15ac: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15af:
	/* 0x15af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b1:
	/* 0x15b1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15b6:
	/* 0x15b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: je     1800 <tail_handle_ipv4_cont+0x1800> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1800;
	}
x86_l_15bf:
	/* 0x15bf: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15c4:
	/* 0x15c4: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_15c9:
	/* 0x15c9: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15ce:
	/* 0x15ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15d1:
	/* 0x15d1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d3:
	/* 0x15d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d5:
	/* 0x15d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15d7:
	/* 0x15d7: mov    r15d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967117ULL);
x86_l_15dd:
	/* 0x15dd: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_15e1:
	/* 0x15e1: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_15e6:
	/* 0x15e6: jmp    17f7 <tail_handle_ipv4_cont+0x17f7> */
	goto x86_l_17f7;
x86_l_15eb:
	/* 0x15eb: mov    r15d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_32);
x86_l_15ee:
	/* 0x15ee: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_15f1:
	/* 0x15f1: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_15f8:
	/* 0x15f8: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15fa:
	/* 0x15fa: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1601:
	/* 0x1601: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1604:
	/* 0x1604: mov    DWORD PTR [rsp+0xd0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_160b:
	/* 0x160b: je     198a <tail_handle_ipv4_cont+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_198a;
	}
x86_l_1611:
	/* 0x1611: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1619:
	/* 0x1619: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_161e:
	/* 0x161e: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_1625:
	/* 0x1625: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_162a:
	/* 0x162a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162c:
	/* 0x162c: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_162f:
	/* 0x162f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1632:
	/* 0x1632: je     198d <tail_handle_ipv4_cont+0x198d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_198d;
	}
x86_l_1638:
	/* 0x1638: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163b:
	/* 0x163b: jmp    198f <tail_handle_ipv4_cont+0x198f> */
	goto x86_l_198f;
x86_l_1640:
	/* 0x1640: inc    QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1643:
	/* 0x1643: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1648:
	/* 0x1648: jmp    14d8 <tail_handle_ipv4_cont+0x14d8> */
	return 5336ULL;
x86_l_164d:
	/* 0x164d: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1650:
	/* 0x1650: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_1657:
	/* 0x1657: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165a:
	/* 0x165a: jne    c96 <tail_handle_ipv4_cont+0xc96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3222ULL;
	}
x86_l_1660:
	/* 0x1660: mov    ecx,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_1665:
	/* 0x1665: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_1668:
	/* 0x1668: mov    DWORD PTR [rbx+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_166e:
	/* 0x166e: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1671:
	/* 0x1671: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1673:
	/* 0x1673: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1676:
	/* 0x1676: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1679:
	/* 0x1679: js     22d <tail_handle_ipv4_cont+0x22d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 557ULL;
	}
x86_l_167f:
	/* 0x167f: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1683:
	/* 0x1683: jne    2e5 <tail_handle_ipv4_cont+0x2e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 741ULL;
	}
x86_l_1689:
	/* 0x1689: jmp    22d <tail_handle_ipv4_cont+0x22d> */
	return 557ULL;
x86_l_168e:
	/* 0x168e: cmp    r12b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 191ULL);
x86_l_1692:
	/* 0x1692: ja     1de7 <tail_handle_ipv4_cont+0x1de7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7655ULL;
	}
x86_l_1698:
	/* 0x1698: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_169a:
	/* 0x169a: sub    cl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_169d:
	/* 0x169d: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_16a2:
	/* 0x16a2: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_16a7:
	/* 0x16a7: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_16ab:
	/* 0x16ab: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16b2:
	/* 0x16b2: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_16b4:
	/* 0x16b4: jmp    1dee <tail_handle_ipv4_cont+0x1dee> */
	return 7662ULL;
x86_l_16b9:
	/* 0x16b9: mov    r12d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_16bf:
	/* 0x16bf: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c2:
	/* 0x16c2: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_16c4:
	/* 0x16c4: jmp    23fd <tail_handle_ipv4_cont+0x23fd> */
	return 9213ULL;
x86_l_16c9:
	/* 0x16c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16cb:
	/* 0x16cb: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_16d3:
	/* 0x16d3: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16d7:
	/* 0x16d7: mov    QWORD PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_16e3:
	/* 0x16e3: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_16ec:
	/* 0x16ec: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_16f5:
	/* 0x16f5: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_16fe:
	/* 0x16fe: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1707:
	/* 0x1707: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1710:
	/* 0x1710: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1719:
	/* 0x1719: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1722:
	/* 0x1722: movabs rax,0x200580200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8595702272ULL);
x86_l_172c:
	/* 0x172c: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1731:
	/* 0x1731: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1736:
	/* 0x1736: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_173d:
	/* 0x173d: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1742:
	/* 0x1742: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1745:
	/* 0x1745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1747:
	/* 0x1747: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_174a:
	/* 0x174a: je     1c8a <tail_handle_ipv4_cont+0x1c8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c8a;
	}
x86_l_1750:
	/* 0x1750: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1753:
	/* 0x1753: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1757:
	/* 0x1757: jmp    1cb2 <tail_handle_ipv4_cont+0x1cb2> */
	return 7346ULL;
x86_l_175c:
	/* 0x175c: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1761:
	/* 0x1761: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_1766:
	/* 0x1766: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_176b:
	/* 0x176b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_176e:
	/* 0x176e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1770:
	/* 0x1770: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1772:
	/* 0x1772: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1775:
	/* 0x1775: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_177a:
	/* 0x177a: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_177f:
	/* 0x177f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1781:
	/* 0x1781: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1784:
	/* 0x1784: je     2498 <tail_handle_ipv4_cont+0x2498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9368ULL;
	}
x86_l_178a:
	/* 0x178a: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1791:
	/* 0x1791: mov    WORD PTR [r14+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1796:
	/* 0x1796: mov    WORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_179d:
	/* 0x179d: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_17a7:
	/* 0x17a7: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17aa:
	/* 0x17aa: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_17af:
	/* 0x17af: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17b2:
	/* 0x17b2: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_17b5:
	/* 0x17b5: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_17ba:
	/* 0x17ba: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_17c1:
	/* 0x17c1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17c4:
	/* 0x17c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c6:
	/* 0x17c6: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17cb:
	/* 0x17cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17ce:
	/* 0x17ce: je     1800 <tail_handle_ipv4_cont+0x1800> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1800;
	}
x86_l_17d0:
	/* 0x17d0: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17d5:
	/* 0x17d5: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_17da:
	/* 0x17da: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17df:
	/* 0x17df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17e2:
	/* 0x17e2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e4:
	/* 0x17e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e6:
	/* 0x17e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e8:
	/* 0x17e8: mov    r15d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967117ULL);
x86_l_17ee:
	/* 0x17ee: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_17f2:
	/* 0x17f2: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_17f7:
	/* 0x17f7: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17fc:
	/* 0x17fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17fe:
	/* 0x17fe: jmp    1806 <tail_handle_ipv4_cont+0x1806> */
	goto x86_l_1806;
x86_l_1800:
	/* 0x1800: mov    r15d,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967118ULL);
x86_l_1806:
	/* 0x1806: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_180a:
	/* 0x180a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_180d:
	/* 0x180d: je     1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1676;
	}
x86_l_1813:
	/* 0x1813: mov    DWORD PTR [r14+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_181b:
	/* 0x181b: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_181e:
	/* 0x181e: je     1890 <tail_handle_ipv4_cont+0x1890> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1890;
	}
x86_l_1820:
	/* 0x1820: mov    r12d,0xffffff4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967116ULL);
x86_l_1826:
	/* 0x1826: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1829:
	/* 0x1829: jne    1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1676;
	}
x86_l_182f:
	/* 0x182f: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_1834:
	/* 0x1834: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1837:
	/* 0x1837: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_183a:
	/* 0x183a: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_183f:
	/* 0x183f: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1846:
	/* 0x1846: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1849:
	/* 0x1849: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184b:
	/* 0x184b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1850:
	/* 0x1850: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1853:
	/* 0x1853: je     18ed <tail_handle_ipv4_cont+0x18ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ed;
	}
x86_l_1859:
	/* 0x1859: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_185e:
	/* 0x185e: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_1863:
	/* 0x1863: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1868:
	/* 0x1868: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_186b:
	/* 0x186b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_186d:
	/* 0x186d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186f:
	/* 0x186f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1871:
	/* 0x1871: mov    r12d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967117ULL);
x86_l_1877:
	/* 0x1877: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_187b:
	/* 0x187b: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_1880:
	/* 0x1880: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1885:
	/* 0x1885: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1887:
	/* 0x1887: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_188b:
	/* 0x188b: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	goto x86_l_1676;
x86_l_1890:
	/* 0x1890: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_1895:
	/* 0x1895: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1898:
	/* 0x1898: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_189b:
	/* 0x189b: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_18a0:
	/* 0x18a0: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_18a7:
	/* 0x18a7: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18aa:
	/* 0x18aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ac:
	/* 0x18ac: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18b1:
	/* 0x18b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b4:
	/* 0x18b4: je     18ed <tail_handle_ipv4_cont+0x18ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18ed;
	}
x86_l_18b6:
	/* 0x18b6: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18bb:
	/* 0x18bb: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_18c0:
	/* 0x18c0: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18c5:
	/* 0x18c5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18c8:
	/* 0x18c8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ca:
	/* 0x18ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cc:
	/* 0x18cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18ce:
	/* 0x18ce: mov    r12d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967117ULL);
x86_l_18d4:
	/* 0x18d4: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_18d8:
	/* 0x18d8: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_18dd:
	/* 0x18dd: mov    rdi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18e2:
	/* 0x18e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e4:
	/* 0x18e4: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e8:
	/* 0x18e8: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	goto x86_l_1676;
x86_l_18ed:
	/* 0x18ed: mov    r12d,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967118ULL);
x86_l_18f3:
	/* 0x18f3: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18f7:
	/* 0x18f7: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	goto x86_l_1676;
x86_l_18fc:
	/* 0x18fc: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1903:
	/* 0x1903: mov    BYTE PTR [rsp+0x29],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_1908:
	/* 0x1908: mov    WORD PTR [rsp+0x2a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_190d:
	/* 0x190d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1912:
	/* 0x1912: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_1919:
	/* 0x1919: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_191e:
	/* 0x191e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1920:
	/* 0x1920: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1923:
	/* 0x1923: jne    1e10 <tail_handle_ipv4_cont+0x1e10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7696ULL;
	}
x86_l_1929:
	/* 0x1929: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_1932:
	/* 0x1932: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_193a:
	/* 0x193a: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_193f:
	/* 0x193f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1944:
	/* 0x1944: jmp    1e3e <tail_handle_ipv4_cont+0x1e3e> */
	return 7742ULL;
x86_l_1949:
	/* 0x1949: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_194e:
	/* 0x194e: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1951:
	/* 0x1951: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1956:
	/* 0x1956: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_195b:
	/* 0x195b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1962:
	/* 0x1962: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_196a:
	/* 0x196a: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_196f:
	/* 0x196f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1971:
	/* 0x1971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1973:
	/* 0x1973: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1975:
	/* 0x1975: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_197a:
	/* 0x197a: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_197f:
	/* 0x197f: jns    1ba4 <tail_handle_ipv4_cont+0x1ba4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1ba4;
	}
x86_l_1985:
	/* 0x1985: jmp    23e6 <tail_handle_ipv4_cont+0x23e6> */
	return 9190ULL;
x86_l_198a:
	/* 0x198a: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_198d:
	/* 0x198d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198f:
	/* 0x198f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1997:
	/* 0x1997: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_199a:
	/* 0x199a: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_199e:
	/* 0x199e: mov    QWORD PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_19aa:
	/* 0x19aa: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_19b3:
	/* 0x19b3: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_19bc:
	/* 0x19bc: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_19c5:
	/* 0x19c5: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_19ce:
	/* 0x19ce: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_19d7:
	/* 0x19d7: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_19e0:
	/* 0x19e0: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_19e9:
	/* 0x19e9: movabs rax,0x200580200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8595702272ULL);
x86_l_19f3:
	/* 0x19f3: or     rax,0x5200000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 85983232ULL);
x86_l_19f9:
	/* 0x19f9: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19fe:
	/* 0x19fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a03:
	/* 0x1a03: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a0a:
	/* 0x1a0a: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a0f:
	/* 0x1a0f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1a12:
	/* 0x1a12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a14:
	/* 0x1a14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a17:
	/* 0x1a17: je     1a22 <tail_handle_ipv4_cont+0x1a22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a22;
	}
x86_l_1a19:
	/* 0x1a19: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a1c:
	/* 0x1a1c: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a20:
	/* 0x1a20: jmp    1a4a <tail_handle_ipv4_cont+0x1a4a> */
	goto x86_l_1a4a;
x86_l_1a22:
	/* 0x1a22: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a30:
	/* 0x1a30: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a35:
	/* 0x1a35: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a3c:
	/* 0x1a3c: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a41:
	/* 0x1a41: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a46:
	/* 0x1a46: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a48:
	/* 0x1a48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4a:
	/* 0x1a4a: cmp    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1a52:
	/* 0x1a52: je     260a <tail_handle_ipv4_cont+0x260a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9738ULL;
	}
x86_l_1a58:
	/* 0x1a58: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1a5f:
	/* 0x1a5f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a62:
	/* 0x1a62: je     2549 <tail_handle_ipv4_cont+0x2549> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9545ULL;
	}
x86_l_1a68:
	/* 0x1a68: mov    BYTE PTR [rsp+0xd8],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1a70:
	/* 0x1a70: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a75:
	/* 0x1a75: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1a7c:
	/* 0x1a7c: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    QWORD PTR [rsp+0x100],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1a86:
	/* 0x1a86: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a88:
	/* 0x1a88: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1a90:
	/* 0x1a90: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1a95:
	/* 0x1a95: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a97:
	/* 0x1a97: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a99:
	/* 0x1a99: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1a9c:
	/* 0x1a9c: mov    DWORD PTR [rsp+0xbc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851650ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aac:
	/* 0x1aac: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1ab3:
	/* 0x1ab3: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1abb:
	/* 0x1abb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1abd:
	/* 0x1abd: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1ac0:
	/* 0x1ac0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ac3:
	/* 0x1ac3: jne    1af4 <tail_handle_ipv4_cont+0x1af4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1af4;
	}
x86_l_1ac5:
	/* 0x1ac5: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1ace:
	/* 0x1ace: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ad3:
	/* 0x1ad3: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1ada:
	/* 0x1ada: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1ae2:
	/* 0x1ae2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ae5:
	/* 0x1ae5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae7:
	/* 0x1ae7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae9:
	/* 0x1ae9: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1aec:
	/* 0x1aec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1aee:
	/* 0x1aee: js     2732 <tail_handle_ipv4_cont+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10034ULL;
	}
x86_l_1af4:
	/* 0x1af4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1af9:
	/* 0x1af9: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1b00:
	/* 0x1b00: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b08:
	/* 0x1b08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0a:
	/* 0x1b0a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b0d:
	/* 0x1b0d: je     24a4 <tail_handle_ipv4_cont+0x24a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9380ULL;
	}
x86_l_1b13:
	/* 0x1b13: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b16:
	/* 0x1b16: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1b19:
	/* 0x1b19: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1b1c:
	/* 0x1b1c: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_1b23:
	/* 0x1b23: jbe    2527 <tail_handle_ipv4_cont+0x2527> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9511ULL;
	}
x86_l_1b29:
	/* 0x1b29: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_1b2c:
	/* 0x1b2c: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1b30:
	/* 0x1b30: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1b3a:
	/* 0x1b3a: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1b3f:
	/* 0x1b3f: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1b43:
	/* 0x1b43: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1b4a:
	/* 0x1b4a: imul   rcx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 232ULL);
x86_l_1b53:
	/* 0x1b53: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b57:
	/* 0x1b57: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b5b:
	/* 0x1b5b: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1b5e:
	/* 0x1b5e: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b61:
	/* 0x1b61: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b64:
	/* 0x1b64: mov    rdx,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1b6c:
	/* 0x1b6c: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1b6f:
	/* 0x1b6f: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b74:
	/* 0x1b74: jbe    2530 <tail_handle_ipv4_cont+0x2530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9520ULL;
	}
x86_l_1b7a:
	/* 0x1b7a: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1b81:
	/* 0x1b81: jmp    2530 <tail_handle_ipv4_cont+0x2530> */
	return 9520ULL;
x86_l_1b86:
	/* 0x1b86: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b8f:
	/* 0x1b8f: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b94:
	/* 0x1b94: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1b97:
	/* 0x1b97: je     23e6 <tail_handle_ipv4_cont+0x23e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9190ULL;
	}
x86_l_1b9d:
	/* 0x1b9d: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1ba0:
	/* 0x1ba0: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ba4:
	/* 0x1ba4: mov    r14d,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1bac:
	/* 0x1bac: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1bb3:
	/* 0x1bb3: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb5:
	/* 0x1bb5: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    edx,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1bbe:
	/* 0x1bbe: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1bc0:
	/* 0x1bc0: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_1bc3:
	/* 0x1bc3: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1bc6:
	/* 0x1bc6: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1bc8:
	/* 0x1bc8: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1bcb:
	/* 0x1bcb: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1bd2:
	/* 0x1bd2: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bd5:
	/* 0x1bd5: mov    edx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    WORD PTR [rsp+0x48],0xb04 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237648132ULL);
x86_l_1be2:
	/* 0x1be2: mov    WORD PTR [rsp+0x4a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_1be7:
	/* 0x1be7: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1beb:
	/* 0x1beb: mov    DWORD PTR [rsp+0x50],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bef:
	/* 0x1bef: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1bf4:
	/* 0x1bf4: mov    WORD PTR [rsp+0x56],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187458ULL);
x86_l_1bfb:
	/* 0x1bfb: mov    DWORD PTR [rsp+0x58],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c00:
	/* 0x1c00: mov    DWORD PTR [rsp+0x5c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1c05:
	/* 0x1c05: mov    WORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1c0c:
	/* 0x1c0c: mov    BYTE PTR [rsp+0x62],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_1c11:
	/* 0x1c11: mov    BYTE PTR [rsp+0x63],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762304ULL);
x86_l_1c16:
	/* 0x1c16: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    rcx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c26:
	/* 0x1c26: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1c34:
	/* 0x1c34: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_1c43:
	/* 0x1c43: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1c47:
	/* 0x1c47: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c4c:
	/* 0x1c4c: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1c4f:
	/* 0x1c4f: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_1c56:
	/* 0x1c56: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c5e:
	/* 0x1c5e: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_1c64:
	/* 0x1c64: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1c67:
	/* 0x1c67: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1c73:
	/* 0x1c73: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c76:
	/* 0x1c76: mov    edx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c7b:
	/* 0x1c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7d:
	/* 0x1c7d: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_1c82:
	/* 0x1c82: mov    sil,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 17ULL);
x86_l_1c85:
	/* 0x1c85: jmp    22a <tail_handle_ipv4_cont+0x22a> */
	return 554ULL;
x86_l_1c8a:
	/* 0x1c8a: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_1c93:
	/* 0x1c93: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c98:
	/* 0x1c98: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c9d:
	/* 0x1c9d: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ca4:
	/* 0x1ca4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
	return 7337ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7337ULL: goto x86_l_1ca9;
	case 7342ULL: goto x86_l_1cae;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7354ULL: goto x86_l_1cba;
	case 7360ULL: goto x86_l_1cc0;
	case 7367ULL: goto x86_l_1cc7;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7383ULL: goto x86_l_1cd7;
	case 7388ULL: goto x86_l_1cdc;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7405ULL: goto x86_l_1ced;
	case 7407ULL: goto x86_l_1cef;
	case 7412ULL: goto x86_l_1cf4;
	case 7414ULL: goto x86_l_1cf6;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7430ULL: goto x86_l_1d06;
	case 7435ULL: goto x86_l_1d0b;
	case 7442ULL: goto x86_l_1d12;
	case 7450ULL: goto x86_l_1d1a;
	case 7452ULL: goto x86_l_1d1c;
	case 7455ULL: goto x86_l_1d1f;
	case 7458ULL: goto x86_l_1d22;
	case 7460ULL: goto x86_l_1d24;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7481ULL: goto x86_l_1d39;
	case 7489ULL: goto x86_l_1d41;
	case 7492ULL: goto x86_l_1d44;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7501ULL: goto x86_l_1d4d;
	case 7507ULL: goto x86_l_1d53;
	case 7512ULL: goto x86_l_1d58;
	case 7519ULL: goto x86_l_1d5f;
	case 7527ULL: goto x86_l_1d67;
	case 7529ULL: goto x86_l_1d69;
	case 7532ULL: goto x86_l_1d6c;
	case 7538ULL: goto x86_l_1d72;
	case 7541ULL: goto x86_l_1d75;
	case 7544ULL: goto x86_l_1d78;
	case 7547ULL: goto x86_l_1d7b;
	case 7554ULL: goto x86_l_1d82;
	case 7560ULL: goto x86_l_1d88;
	case 7563ULL: goto x86_l_1d8b;
	case 7567ULL: goto x86_l_1d8f;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7586ULL: goto x86_l_1da2;
	case 7593ULL: goto x86_l_1da9;
	case 7597ULL: goto x86_l_1dad;
	case 7601ULL: goto x86_l_1db1;
	case 7605ULL: goto x86_l_1db5;
	case 7608ULL: goto x86_l_1db8;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7622ULL: goto x86_l_1dc6;
	case 7625ULL: goto x86_l_1dc9;
	case 7630ULL: goto x86_l_1dce;
	case 7637ULL: goto x86_l_1dd5;
	case 7643ULL: goto x86_l_1ddb;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7655ULL: goto x86_l_1de7;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7684ULL: goto x86_l_1e04;
	case 7689ULL: goto x86_l_1e09;
	case 7691ULL: goto x86_l_1e0b;
	case 7694ULL: goto x86_l_1e0e;
	case 7696ULL: goto x86_l_1e10;
	case 7700ULL: goto x86_l_1e14;
	case 7708ULL: goto x86_l_1e1c;
	case 7713ULL: goto x86_l_1e21;
	case 7715ULL: goto x86_l_1e23;
	case 7724ULL: goto x86_l_1e2c;
	case 7732ULL: goto x86_l_1e34;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7749ULL: goto x86_l_1e45;
	case 7754ULL: goto x86_l_1e4a;
	case 7759ULL: goto x86_l_1e4f;
	case 7764ULL: goto x86_l_1e54;
	case 7766ULL: goto x86_l_1e56;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7784ULL: goto x86_l_1e68;
	case 7792ULL: goto x86_l_1e70;
	case 7796ULL: goto x86_l_1e74;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7817ULL: goto x86_l_1e89;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7827ULL: goto x86_l_1e93;
	case 7834ULL: goto x86_l_1e9a;
	case 7842ULL: goto x86_l_1ea2;
	case 7848ULL: goto x86_l_1ea8;
	case 7852ULL: goto x86_l_1eac;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7869ULL: goto x86_l_1ebd;
	case 7871ULL: goto x86_l_1ebf;
	case 7874ULL: goto x86_l_1ec2;
	case 7878ULL: goto x86_l_1ec6;
	case 7880ULL: goto x86_l_1ec8;
	case 7885ULL: goto x86_l_1ecd;
	case 7887ULL: goto x86_l_1ecf;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7899ULL: goto x86_l_1edb;
	case 7902ULL: goto x86_l_1ede;
	case 7909ULL: goto x86_l_1ee5;
	case 7912ULL: goto x86_l_1ee8;
	case 7916ULL: goto x86_l_1eec;
	case 7922ULL: goto x86_l_1ef2;
	case 7924ULL: goto x86_l_1ef4;
	case 7928ULL: goto x86_l_1ef8;
	case 7930ULL: goto x86_l_1efa;
	case 7937ULL: goto x86_l_1f01;
	case 7943ULL: goto x86_l_1f07;
	case 7946ULL: goto x86_l_1f0a;
	case 7948ULL: goto x86_l_1f0c;
	case 7952ULL: goto x86_l_1f10;
	case 7959ULL: goto x86_l_1f17;
	case 7961ULL: goto x86_l_1f19;
	case 7965ULL: goto x86_l_1f1d;
	case 7970ULL: goto x86_l_1f22;
	case 7977ULL: goto x86_l_1f29;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7995ULL: goto x86_l_1f3b;
	case 8004ULL: goto x86_l_1f44;
	case 8012ULL: goto x86_l_1f4c;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8042ULL: goto x86_l_1f6a;
	case 8047ULL: goto x86_l_1f6f;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8058ULL: goto x86_l_1f7a;
	case 8064ULL: goto x86_l_1f80;
	case 8067ULL: goto x86_l_1f83;
	case 8070ULL: goto x86_l_1f86;
	case 8072ULL: goto x86_l_1f88;
	case 8077ULL: goto x86_l_1f8d;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8089ULL: goto x86_l_1f99;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8103ULL: goto x86_l_1fa7;
	case 8106ULL: goto x86_l_1faa;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8121ULL: goto x86_l_1fb9;
	case 8123ULL: goto x86_l_1fbb;
	case 8126ULL: goto x86_l_1fbe;
	case 8130ULL: goto x86_l_1fc2;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8150ULL: goto x86_l_1fd6;
	case 8155ULL: goto x86_l_1fdb;
	case 8157ULL: goto x86_l_1fdd;
	case 8160ULL: goto x86_l_1fe0;
	case 8166ULL: goto x86_l_1fe6;
	case 8169ULL: goto x86_l_1fe9;
	case 8172ULL: goto x86_l_1fec;
	case 8175ULL: goto x86_l_1fef;
	case 8180ULL: goto x86_l_1ff4;
	case 8182ULL: goto x86_l_1ff6;
	case 8190ULL: goto x86_l_1ffe;
	case 8195ULL: goto x86_l_2003;
	case 8200ULL: goto x86_l_2008;
	case 8204ULL: goto x86_l_200c;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8220ULL: goto x86_l_201c;
	case 8225ULL: goto x86_l_2021;
	case 8230ULL: goto x86_l_2026;
	case 8233ULL: goto x86_l_2029;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8247ULL: goto x86_l_2037;
	case 8251ULL: goto x86_l_203b;
	case 8253ULL: goto x86_l_203d;
	case 8261ULL: goto x86_l_2045;
	case 8265ULL: goto x86_l_2049;
	case 8268ULL: goto x86_l_204c;
	case 8272ULL: goto x86_l_2050;
	case 8275ULL: goto x86_l_2053;
	case 8277ULL: goto x86_l_2055;
	case 8280ULL: goto x86_l_2058;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8292ULL: goto x86_l_2064;
	case 8297ULL: goto x86_l_2069;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8313ULL: goto x86_l_2079;
	case 8320ULL: goto x86_l_2080;
	case 8323ULL: goto x86_l_2083;
	case 8326ULL: goto x86_l_2086;
	case 8330ULL: goto x86_l_208a;
	case 8339ULL: goto x86_l_2093;
	case 8346ULL: goto x86_l_209a;
	case 8348ULL: goto x86_l_209c;
	case 8353ULL: goto x86_l_20a1;
	case 8358ULL: goto x86_l_20a6;
	case 8360ULL: goto x86_l_20a8;
	case 8366ULL: goto x86_l_20ae;
	case 8374ULL: goto x86_l_20b6;
	case 8378ULL: goto x86_l_20ba;
	case 8381ULL: goto x86_l_20bd;
	case 8389ULL: goto x86_l_20c5;
	case 8393ULL: goto x86_l_20c9;
	case 8400ULL: goto x86_l_20d0;
	case 8403ULL: goto x86_l_20d3;
	case 8409ULL: goto x86_l_20d9;
	case 8416ULL: goto x86_l_20e0;
	case 8424ULL: goto x86_l_20e8;
	case 8431ULL: goto x86_l_20ef;
	case 8438ULL: goto x86_l_20f6;
	case 8440ULL: goto x86_l_20f8;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8458ULL: goto x86_l_210a;
	case 8463ULL: goto x86_l_210f;
	case 8465ULL: goto x86_l_2111;
	case 8467ULL: goto x86_l_2113;
	case 8475ULL: goto x86_l_211b;
	case 8479ULL: goto x86_l_211f;
	case 8486ULL: goto x86_l_2126;
	case 8491ULL: goto x86_l_212b;
	case 8498ULL: goto x86_l_2132;
	case 8506ULL: goto x86_l_213a;
	case 8508ULL: goto x86_l_213c;
	case 8516ULL: goto x86_l_2144;
	case 8519ULL: goto x86_l_2147;
	case 8521ULL: goto x86_l_2149;
	case 8530ULL: goto x86_l_2152;
	case 8535ULL: goto x86_l_2157;
	case 8542ULL: goto x86_l_215e;
	case 8550ULL: goto x86_l_2166;
	case 8555ULL: goto x86_l_216b;
	case 8563ULL: goto x86_l_2173;
	case 8565ULL: goto x86_l_2175;
	case 8567ULL: goto x86_l_2177;
	case 8569ULL: goto x86_l_2179;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8587ULL: goto x86_l_218b;
	case 8592ULL: goto x86_l_2190;
	case 8594ULL: goto x86_l_2192;
	case 8597ULL: goto x86_l_2195;
	case 8603ULL: goto x86_l_219b;
	case 8606ULL: goto x86_l_219e;
	case 8614ULL: goto x86_l_21a6;
	case 8617ULL: goto x86_l_21a9;
	case 8620ULL: goto x86_l_21ac;
	case 8627ULL: goto x86_l_21b3;
	case 8633ULL: goto x86_l_21b9;
	case 8636ULL: goto x86_l_21bc;
	case 8640ULL: goto x86_l_21c0;
	case 8650ULL: goto x86_l_21ca;
	case 8655ULL: goto x86_l_21cf;
	case 8659ULL: goto x86_l_21d3;
	case 8666ULL: goto x86_l_21da;
	case 8675ULL: goto x86_l_21e3;
	case 8679ULL: goto x86_l_21e7;
	case 8683ULL: goto x86_l_21eb;
	case 8686ULL: goto x86_l_21ee;
	case 8689ULL: goto x86_l_21f1;
	case 8692ULL: goto x86_l_21f4;
	case 8700ULL: goto x86_l_21fc;
	case 8703ULL: goto x86_l_21ff;
	case 8710ULL: goto x86_l_2206;
	case 8719ULL: goto x86_l_220f;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8732ULL: goto x86_l_221c;
	case 8735ULL: goto x86_l_221f;
	case 8737ULL: goto x86_l_2221;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8771ULL: goto x86_l_2243;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8801ULL: goto x86_l_2261;
	case 8810ULL: goto x86_l_226a;
	case 8817ULL: goto x86_l_2271;
	case 8819ULL: goto x86_l_2273;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8835ULL: goto x86_l_2283;
	case 8844ULL: goto x86_l_228c;
	case 8851ULL: goto x86_l_2293;
	case 8854ULL: goto x86_l_2296;
	case 8860ULL: goto x86_l_229c;
	case 8863ULL: goto x86_l_229f;
	case 8867ULL: goto x86_l_22a3;
	case 8874ULL: goto x86_l_22aa;
	case 8877ULL: goto x86_l_22ad;
	case 8883ULL: goto x86_l_22b3;
	case 8888ULL: goto x86_l_22b8;
	case 8895ULL: goto x86_l_22bf;
	case 8902ULL: goto x86_l_22c6;
	case 8907ULL: goto x86_l_22cb;
	case 8911ULL: goto x86_l_22cf;
	case 8916ULL: goto x86_l_22d4;
	case 8922ULL: goto x86_l_22da;
	case 8929ULL: goto x86_l_22e1;
	case 8933ULL: goto x86_l_22e5;
	case 8937ULL: goto x86_l_22e9;
	case 8941ULL: goto x86_l_22ed;
	case 8948ULL: goto x86_l_22f4;
	case 8955ULL: goto x86_l_22fb;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8967ULL: goto x86_l_2307;
	case 8972ULL: goto x86_l_230c;
	case 8976ULL: goto x86_l_2310;
	case 8981ULL: goto x86_l_2315;
	case 8989ULL: goto x86_l_231d;
	case 8993ULL: goto x86_l_2321;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9010ULL: goto x86_l_2332;
	case 9015ULL: goto x86_l_2337;
	case 9018ULL: goto x86_l_233a;
	case 9025ULL: goto x86_l_2341;
	case 9030ULL: goto x86_l_2346;
	case 9033ULL: goto x86_l_2349;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9045ULL: goto x86_l_2355;
	case 9053ULL: goto x86_l_235d;
	case 9062ULL: goto x86_l_2366;
	case 9065ULL: goto x86_l_2369;
	case 9067ULL: goto x86_l_236b;
	case 9074ULL: goto x86_l_2372;
	case 9077ULL: goto x86_l_2375;
	case 9079ULL: goto x86_l_2377;
	case 9086ULL: goto x86_l_237e;
	case 9091ULL: goto x86_l_2383;
	case 9093ULL: goto x86_l_2385;
	case 9100ULL: goto x86_l_238c;
	case 9106ULL: goto x86_l_2392;
	case 9110ULL: goto x86_l_2396;
	case 9115ULL: goto x86_l_239b;
	case 9122ULL: goto x86_l_23a2;
	case 9125ULL: goto x86_l_23a5;
	case 9130ULL: goto x86_l_23aa;
	case 9132ULL: goto x86_l_23ac;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9150ULL: goto x86_l_23be;
	case 9155ULL: goto x86_l_23c3;
	case 9159ULL: goto x86_l_23c7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ca9:
	/* 0x1ca9: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cae:
	/* 0x1cae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb0:
	/* 0x1cb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb2:
	/* 0x1cb2: cmp    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_1cba:
	/* 0x1cba: je     2700 <tail_handle_ipv4_cont+0x2700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9984ULL;
	}
x86_l_1cc0:
	/* 0x1cc0: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1cc7:
	/* 0x1cc7: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cca:
	/* 0x1cca: je     263f <tail_handle_ipv4_cont+0x263f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9791ULL;
	}
x86_l_1cd0:
	/* 0x1cd0: mov    DWORD PTR [rsp+0xd8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1ce3:
	/* 0x1ce3: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1ced:
	/* 0x1ced: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cef:
	/* 0x1cef: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1cf4:
	/* 0x1cf4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cf6:
	/* 0x1cf6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cf8:
	/* 0x1cf8: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1cfb:
	/* 0x1cfb: mov    DWORD PTR [rsp+0xbc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851650ULL);
x86_l_1d06:
	/* 0x1d06: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d0b:
	/* 0x1d0b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1d12:
	/* 0x1d12: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d1a:
	/* 0x1d1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1c:
	/* 0x1d1c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1d1f:
	/* 0x1d1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d22:
	/* 0x1d22: jne    1d53 <tail_handle_ipv4_cont+0x1d53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d53;
	}
x86_l_1d24:
	/* 0x1d24: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d32:
	/* 0x1d32: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1d39:
	/* 0x1d39: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_1d41:
	/* 0x1d41: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d44:
	/* 0x1d44: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d46:
	/* 0x1d46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d48:
	/* 0x1d48: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_1d4b:
	/* 0x1d4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d4d:
	/* 0x1d4d: js     2743 <tail_handle_ipv4_cont+0x2743> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10051ULL;
	}
x86_l_1d53:
	/* 0x1d53: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d58:
	/* 0x1d58: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1d5f:
	/* 0x1d5f: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1d67:
	/* 0x1d67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d69:
	/* 0x1d69: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d6c:
	/* 0x1d6c: je     24e4 <tail_handle_ipv4_cont+0x24e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9444ULL;
	}
x86_l_1d72:
	/* 0x1d72: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d75:
	/* 0x1d75: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1d78:
	/* 0x1d78: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1d7b:
	/* 0x1d7b: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_1d82:
	/* 0x1d82: jbe    2618 <tail_handle_ipv4_cont+0x2618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9752ULL;
	}
x86_l_1d88:
	/* 0x1d88: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_1d8b:
	/* 0x1d8b: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1d8f:
	/* 0x1d8f: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1d99:
	/* 0x1d99: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1d9e:
	/* 0x1d9e: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1da2:
	/* 0x1da2: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1da9:
	/* 0x1da9: imul   rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_1dad:
	/* 0x1dad: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1db1:
	/* 0x1db1: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1db5:
	/* 0x1db5: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1db8:
	/* 0x1db8: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dbb:
	/* 0x1dbb: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dbe:
	/* 0x1dbe: mov    rdx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1dc6:
	/* 0x1dc6: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1dc9:
	/* 0x1dc9: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dce:
	/* 0x1dce: mov    ebp,DWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1dd5:
	/* 0x1dd5: jbe    2628 <tail_handle_ipv4_cont+0x2628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9768ULL;
	}
x86_l_1ddb:
	/* 0x1ddb: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1de2:
	/* 0x1de2: jmp    2628 <tail_handle_ipv4_cont+0x2628> */
	return 9768ULL;
x86_l_1de7:
	/* 0x1de7: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1dee:
	/* 0x1dee: mov    BYTE PTR [rsp+0x29],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_1df3:
	/* 0x1df3: mov    WORD PTR [rsp+0x2a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1df8:
	/* 0x1df8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_1e04:
	/* 0x1e04: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e09:
	/* 0x1e09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e0b:
	/* 0x1e0b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e0e:
	/* 0x1e0e: je     1e23 <tail_handle_ipv4_cont+0x1e23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e23;
	}
x86_l_1e10:
	/* 0x1e10: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e14:
	/* 0x1e14: mov    rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1e1c:
	/* 0x1e1c: add QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e21:
	/* 0x1e21: jmp    1e56 <tail_handle_ipv4_cont+0x1e56> */
	goto x86_l_1e56;
x86_l_1e23:
	/* 0x1e23: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1e34:
	/* 0x1e34: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e39:
	/* 0x1e39: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e3e:
	/* 0x1e3e: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_1e45:
	/* 0x1e45: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e4a:
	/* 0x1e4a: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e4f:
	/* 0x1e4f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1e54:
	/* 0x1e54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e56:
	/* 0x1e56: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e5b:
	/* 0x1e5b: movzx  r8d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1e60:
	/* 0x1e60: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e68:
	/* 0x1e68: mov    r9,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1e70:
	/* 0x1e70: cmp    r12b,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 8ULL);
x86_l_1e74:
	/* 0x1e74: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_1e77:
	/* 0x1e77: shl    cl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 2ULL);
x86_l_1e7a:
	/* 0x1e7a: or     cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_1e7d:
	/* 0x1e7d: cmp    r12b,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 72ULL);
x86_l_1e81:
	/* 0x1e81: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e84:
	/* 0x1e84: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1e89:
	/* 0x1e89: cmovb  edi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1e8c:
	/* 0x1e8c: mov    ecx,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e8f:
	/* 0x1e8f: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_1e93:
	/* 0x1e93: mov    DWORD PTR [rsp+0xe4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_1e9a:
	/* 0x1e9a: mov    QWORD PTR [rsp+0xc8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1ea2:
	/* 0x1ea2: jne    2bcb <tail_handle_ipv4_cont+0x2bcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11211ULL;
	}
x86_l_1ea8:
	/* 0x1ea8: movzx  esi,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1eac:
	/* 0x1eac: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1eaf:
	/* 0x1eaf: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_1eb2:
	/* 0x1eb2: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1eb7:
	/* 0x1eb7: je     1edb <tail_handle_ipv4_cont+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1edb;
	}
x86_l_1eb9:
	/* 0x1eb9: test   r8w,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_16);
x86_l_1ebd:
	/* 0x1ebd: js     1edb <tail_handle_ipv4_cont+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1edb;
	}
x86_l_1ebf:
	/* 0x1ebf: mov    ecx,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ec2:
	/* 0x1ec2: cmp    DWORD PTR [r9+0x4],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R9, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ec6:
	/* 0x1ec6: jne    1edb <tail_handle_ipv4_cont+0x1edb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1edb;
	}
x86_l_1ec8:
	/* 0x1ec8: movzx  edi,BYTE PTR [r9+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_1ecf:
	/* 0x1ecf: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_1ed2:
	/* 0x1ed2: cmp    cx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_16);
x86_l_1ed5:
	/* 0x1ed5: ja     2d18 <tail_handle_ipv4_cont+0x2d18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 11544ULL;
	}
x86_l_1edb:
	/* 0x1edb: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ede:
	/* 0x1ede: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ee5:
	/* 0x1ee5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee8:
	/* 0x1ee8: and    sil,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_1eec:
	/* 0x1eec: jne    2bd6 <tail_handle_ipv4_cont+0x2bd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11222ULL;
	}
x86_l_1ef2:
	/* 0x1ef2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef4:
	/* 0x1ef4: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ef8:
	/* 0x1ef8: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1efa:
	/* 0x1efa: cmp    r12d,0xffffff43 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_1f01:
	/* 0x1f01: jne    2049 <tail_handle_ipv4_cont+0x2049> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2049;
	}
x86_l_1f07:
	/* 0x1f07: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1f0a:
	/* 0x1f0a: je     1f10 <tail_handle_ipv4_cont+0x1f10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f10;
	}
x86_l_1f0c:
	/* 0x1f0c: mov    edi,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f10:
	/* 0x1f10: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1f17:
	/* 0x1f17: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f19:
	/* 0x1f19: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f1d:
	/* 0x1f1d: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f22:
	/* 0x1f22: mov    WORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1f29:
	/* 0x1f29: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f2d:
	/* 0x1f2d: mov    BYTE PTR [rsp+0x2a],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1f32:
	/* 0x1f32: mov    BYTE PTR [rsp+0x2b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 184683593728ULL);
x86_l_1f37:
	/* 0x1f37: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_1f39:
	/* 0x1f39: je     1f8d <tail_handle_ipv4_cont+0x1f8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f8d;
	}
x86_l_1f3b:
	/* 0x1f3b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1f44:
	/* 0x1f44: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1f4c:
	/* 0x1f4c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1f55:
	/* 0x1f55: mov    BYTE PTR [rsp+0x4b],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 322122547201ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    DWORD PTR [rsp+0x4c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f63:
	/* 0x1f63: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_node_map_v2)));
x86_l_1f6a:
	/* 0x1f6a: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f6f:
	/* 0x1f6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f71:
	/* 0x1f71: mov    r12d,0xffffff3b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967099ULL);
x86_l_1f77:
	/* 0x1f77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7a:
	/* 0x1f7a: je     2037 <tail_handle_ipv4_cont+0x2037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2037;
	}
x86_l_1f80:
	/* 0x1f80: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f83:
	/* 0x1f83: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1f86:
	/* 0x1f86: jne    1f8f <tail_handle_ipv4_cont+0x1f8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f8f;
	}
x86_l_1f88:
	/* 0x1f88: jmp    2037 <tail_handle_ipv4_cont+0x2037> */
	goto x86_l_2037;
x86_l_1f8d:
	/* 0x1f8d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f8f:
	/* 0x1f8f: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f94:
	/* 0x1f94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f99:
	/* 0x1f99: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_auth_map)));
x86_l_1fa0:
	/* 0x1fa0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa5:
	/* 0x1fa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fa7:
	/* 0x1fa7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1faa:
	/* 0x1faa: je     1ff6 <tail_handle_ipv4_cont+0x1ff6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ff6;
	}
x86_l_1fac:
	/* 0x1fac: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1faf:
	/* 0x1faf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1fb4:
	/* 0x1fb4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb7:
	/* 0x1fb7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb9:
	/* 0x1fb9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1fbb:
	/* 0x1fbb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1fbe:
	/* 0x1fbe: shr    r13,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1fc2:
	/* 0x1fc2: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1fca:
	/* 0x1fca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_1fd6:
	/* 0x1fd6: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1fdb:
	/* 0x1fdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fdd:
	/* 0x1fdd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fe0:
	/* 0x1fe0: je     2cba <tail_handle_ipv4_cont+0x2cba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11450ULL;
	}
x86_l_1fe6:
	/* 0x1fe6: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe9:
	/* 0x1fe9: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1fec:
	/* 0x1fec: cmp    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1fef:
	/* 0x1fef: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ff4:
	/* 0x1ff4: jb     2037 <tail_handle_ipv4_cont+0x2037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2037;
	}
x86_l_1ff6:
	/* 0x1ff6: mov    DWORD PTR [rsp+0x48],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645314ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2003:
	/* 0x2003: mov    QWORD PTR [rsp+0x4c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2008:
	/* 0x2008: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_200c:
	/* 0x200c: mov    DWORD PTR [rsp+0x54],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2010:
	/* 0x2010: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2015:
	/* 0x2015: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_201c:
	/* 0x201c: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2021:
	/* 0x2021: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2026:
	/* 0x2026: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2029:
	/* 0x2029: mov    r8d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 16ULL);
x86_l_202f:
	/* 0x202f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2031:
	/* 0x2031: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_2037:
	/* 0x2037: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_203b:
	/* 0x203b: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_203d:
	/* 0x203d: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2045:
	/* 0x2045: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2049:
	/* 0x2049: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_204c:
	/* 0x204c: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_2050:
	/* 0x2050: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2053:
	/* 0x2053: jne    2064 <tail_handle_ipv4_cont+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2064;
	}
x86_l_2055:
	/* 0x2055: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_2058:
	/* 0x2058: jne    2064 <tail_handle_ipv4_cont+0x2064> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2064;
	}
x86_l_205a:
	/* 0x205a: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205f:
	/* 0x205f: jmp    30b <tail_handle_ipv4_cont+0x30b> */
	return 779ULL;
x86_l_2064:
	/* 0x2064: movzx  eax,WORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2069:
	/* 0x2069: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2070:
	/* 0x2070: movzx  r9d,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_2075:
	/* 0x2075: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2079:
	/* 0x2079: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2080:
	/* 0x2080: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2083:
	/* 0x2083: cmp    r13d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R15, X86_WIDTH_32);
x86_l_2086:
	/* 0x2086: cmovb  r15d,r13d */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_208a:
	/* 0x208a: mov    QWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_2093:
	/* 0x2093: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_policy_verdict_log_filter)));
x86_l_209a:
	/* 0x209a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_209c:
	/* 0x209c: mov    BYTE PTR [rsp+0x48],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645314ULL);
x86_l_20a1:
	/* 0x20a1: movzx  ecx,BYTE PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_20a6:
	/* 0x20a6: test   eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_20a8:
	/* 0x20a8: je     2366 <tail_handle_ipv4_cont+0x2366> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2366;
	}
x86_l_20ae:
	/* 0x20ae: mov    BYTE PTR [rsp+0xa0],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_20b6:
	/* 0x20b6: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20ba:
	/* 0x20ba: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_20bd:
	/* 0x20bd: movzx  edx,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_20c5:
	/* 0x20c5: cmovne edx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_32, X86_CC_NE);
x86_l_20c9:
	/* 0x20c9: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_20d0:
	/* 0x20d0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d3:
	/* 0x20d3: je     22a3 <tail_handle_ipv4_cont+0x22a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a3;
	}
x86_l_20d9:
	/* 0x20d9: mov    DWORD PTR [rsp+0xf0],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_20e0:
	/* 0x20e0: mov    BYTE PTR [rsp+0x9f],r9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 159ULL);
x86_l_20e8:
	/* 0x20e8: mov    DWORD PTR [rsp+0xf4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_20ef:
	/* 0x20ef: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_20f6:
	/* 0x20f6: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f8:
	/* 0x20f8: mov    QWORD PTR [rsp+0x130],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_2100:
	/* 0x2100: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2102:
	/* 0x2102: mov    QWORD PTR [rsp+0x120],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_210a:
	/* 0x210a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_210f:
	/* 0x210f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2111:
	/* 0x2111: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2113:
	/* 0x2113: mov    QWORD PTR [rsp+0x128],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_211b:
	/* 0x211b: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_211f:
	/* 0x211f: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2126:
	/* 0x2126: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_212b:
	/* 0x212b: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_2132:
	/* 0x2132: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_213a:
	/* 0x213a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_213c:
	/* 0x213c: mov    QWORD PTR [rsp+0x118],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2144:
	/* 0x2144: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2147:
	/* 0x2147: jne    217f <tail_handle_ipv4_cont+0x217f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_217f;
	}
x86_l_2149:
	/* 0x2149: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2152:
	/* 0x2152: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2157:
	/* 0x2157: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_215e:
	/* 0x215e: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2166:
	/* 0x2166: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_216b:
	/* 0x216b: mov    QWORD PTR [rsp+0x118],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_2173:
	/* 0x2173: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2175:
	/* 0x2175: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2177:
	/* 0x2177: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2179:
	/* 0x2179: js     2351 <tail_handle_ipv4_cont+0x2351> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2351;
	}
x86_l_217f:
	/* 0x217f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2184:
	/* 0x2184: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_218b:
	/* 0x218b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2190:
	/* 0x2190: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2192:
	/* 0x2192: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2195:
	/* 0x2195: je     2221 <tail_handle_ipv4_cont+0x2221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2221;
	}
x86_l_219b:
	/* 0x219b: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_219e:
	/* 0x219e: mov    rdi,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_21a6:
	/* 0x21a6: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_21a9:
	/* 0x21a9: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21ac:
	/* 0x21ac: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_21b3:
	/* 0x21b3: jbe    2278 <tail_handle_ipv4_cont+0x2278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2278;
	}
x86_l_21b9:
	/* 0x21b9: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_21bc:
	/* 0x21bc: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_21c0:
	/* 0x21c0: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_21ca:
	/* 0x21ca: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_21cf:
	/* 0x21cf: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_21d3:
	/* 0x21d3: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_21da:
	/* 0x21da: imul   rcx,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 288ULL);
x86_l_21e3:
	/* 0x21e3: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_21e7:
	/* 0x21e7: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21eb:
	/* 0x21eb: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21ee:
	/* 0x21ee: add    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_21f1:
	/* 0x21f1: mov    QWORD PTR [rax],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21f4:
	/* 0x21f4: mov    rsi,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_21fc:
	/* 0x21fc: cmp    rcx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_21ff:
	/* 0x21ff: mov    edi,DWORD PTR [rsp+0xf4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_2206:
	/* 0x2206: movzx  r9d,BYTE PTR [rsp+0x9f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 159ULL);
x86_l_220f:
	/* 0x220f: mov    edx,DWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2216:
	/* 0x2216: jbe    2293 <tail_handle_ipv4_cont+0x2293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2293;
	}
x86_l_2218:
	/* 0x2218: mov    QWORD PTR [rax+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221c:
	/* 0x221c: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_221f:
	/* 0x221f: jmp    2293 <tail_handle_ipv4_cont+0x2293> */
	goto x86_l_2293;
x86_l_2221:
	/* 0x2221: mov    rax,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_2229:
	/* 0x2229: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_222e:
	/* 0x222e: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_2236:
	/* 0x2236: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2239:
	/* 0x2239: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_223e:
	/* 0x223e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2243:
	/* 0x2243: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_224a:
	/* 0x224a: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_224f:
	/* 0x224f: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2254:
	/* 0x2254: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2256:
	/* 0x2256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2258:
	/* 0x2258: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_225a:
	/* 0x225a: mov    edi,DWORD PTR [rsp+0xf4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_2261:
	/* 0x2261: movzx  r9d,BYTE PTR [rsp+0x9f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 159ULL);
x86_l_226a:
	/* 0x226a: mov    edx,DWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2271:
	/* 0x2271: jns    22a3 <tail_handle_ipv4_cont+0x22a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_22a3;
	}
x86_l_2273:
	/* 0x2273: jmp    23d6 <tail_handle_ipv4_cont+0x23d6> */
	return 9174ULL;
x86_l_2278:
	/* 0x2278: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227c:
	/* 0x227c: mov    edi,DWORD PTR [rsp+0xf4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_2283:
	/* 0x2283: movzx  r9d,BYTE PTR [rsp+0x9f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 159ULL);
x86_l_228c:
	/* 0x228c: mov    edx,DWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_2293:
	/* 0x2293: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2296:
	/* 0x2296: je     23d6 <tail_handle_ipv4_cont+0x23d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9174ULL;
	}
x86_l_229c:
	/* 0x229c: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_229f:
	/* 0x229f: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a3:
	/* 0x22a3: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_22aa:
	/* 0x22aa: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22ad:
	/* 0x22ad: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22b3:
	/* 0x22b3: mov    BYTE PTR [rsp+0x67],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 442381631488ULL);
x86_l_22b8:
	/* 0x22b8: mov    WORD PTR [rsp+0x65],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 433791696896ULL);
x86_l_22bf:
	/* 0x22bf: mov    WORD PTR [rsp+0x48],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645317ULL);
x86_l_22c6:
	/* 0x22c6: mov    WORD PTR [rsp+0x4a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_22cb:
	/* 0x22cb: mov    DWORD PTR [rsp+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_22cf:
	/* 0x22cf: mov    DWORD PTR [rsp+0x50],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_22d4:
	/* 0x22d4: mov    WORD PTR [rsp+0x54],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_22da:
	/* 0x22da: mov    WORD PTR [rsp+0x56],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187457ULL);
x86_l_22e1:
	/* 0x22e1: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22e5:
	/* 0x22e5: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22e9:
	/* 0x22e9: mov    DWORD PTR [rsp+0x5c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_22ed:
	/* 0x22ed: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_22f4:
	/* 0x22f4: movbe  WORD PTR [rsp+0x60],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_22fb:
	/* 0x22fb: mov    eax,DWORD PTR [rsp+0xe4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_2302:
	/* 0x2302: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_2305:
	/* 0x2305: or     al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_2307:
	/* 0x2307: mov    BYTE PTR [rsp+0x62],r9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_230c:
	/* 0x230c: mov    BYTE PTR [rsp+0x63],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 99ULL);
x86_l_2310:
	/* 0x2310: mov    BYTE PTR [rsp+0x64],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_2315:
	/* 0x2315: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_231d:
	/* 0x231d: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2321:
	/* 0x2321: mov    DWORD PTR [rsp+0x6c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467968ULL);
x86_l_2329:
	/* 0x2329: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_232e:
	/* 0x232e: shl    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2332:
	/* 0x2332: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2337:
	/* 0x2337: or     rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_233a:
	/* 0x233a: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_2341:
	/* 0x2341: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2346:
	/* 0x2346: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2349:
	/* 0x2349: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_234f:
	/* 0x234f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2351:
	/* 0x2351: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2355:
	/* 0x2355: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_235d:
	/* 0x235d: movzx  r8d,BYTE PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 160ULL);
x86_l_2366:
	/* 0x2366: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_2369:
	/* 0x2369: je     23b9 <tail_handle_ipv4_cont+0x23b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23b9;
	}
x86_l_236b:
	/* 0x236b: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_policy_deny_response_enabled)));
x86_l_2372:
	/* 0x2372: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2375:
	/* 0x2375: je     23cc <tail_handle_ipv4_cont+0x23cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9164ULL;
	}
x86_l_2377:
	/* 0x2377: cmp    r12d,0xffffff7b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967163ULL);
x86_l_237e:
	/* 0x237e: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2383:
	/* 0x2383: je     2392 <tail_handle_ipv4_cont+0x2392> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2392;
	}
x86_l_2385:
	/* 0x2385: cmp    r12d,0xffffff4b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967115ULL);
x86_l_238c:
	/* 0x238c: jne    1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5750ULL;
	}
x86_l_2392:
	/* 0x2392: mov    DWORD PTR [rbx+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2396:
	/* 0x2396: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_239b:
	/* 0x239b: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_23a2:
	/* 0x23a2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23a5:
	/* 0x23a5: mov    edx,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 48ULL);
x86_l_23aa:
	/* 0x23aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ac:
	/* 0x23ac: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_23b1:
	/* 0x23b1: mov    sil,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 48ULL);
x86_l_23b4:
	/* 0x23b4: jmp    22a <tail_handle_ipv4_cont+0x22a> */
	return 554ULL;
x86_l_23b9:
	/* 0x23b9: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23be:
	/* 0x23be: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23c3:
	/* 0x23c3: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_23c7:
	/* 0x23c7: jmp    30b <tail_handle_ipv4_cont+0x30b> */
	return 779ULL;
	return 9164ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9164ULL: goto x86_l_23cc;
	case 9169ULL: goto x86_l_23d1;
	case 9174ULL: goto x86_l_23d6;
	case 9182ULL: goto x86_l_23de;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9193ULL: goto x86_l_23e9;
	case 9198ULL: goto x86_l_23ee;
	case 9203ULL: goto x86_l_23f3;
	case 9209ULL: goto x86_l_23f9;
	case 9213ULL: goto x86_l_23fd;
	case 9215ULL: goto x86_l_23ff;
	case 9217ULL: goto x86_l_2401;
	case 9221ULL: goto x86_l_2405;
	case 9227ULL: goto x86_l_240b;
	case 9234ULL: goto x86_l_2412;
	case 9236ULL: goto x86_l_2414;
	case 9240ULL: goto x86_l_2418;
	case 9246ULL: goto x86_l_241e;
	case 9253ULL: goto x86_l_2425;
	case 9255ULL: goto x86_l_2427;
	case 9262ULL: goto x86_l_242e;
	case 9269ULL: goto x86_l_2435;
	case 9272ULL: goto x86_l_2438;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9290ULL: goto x86_l_244a;
	case 9295ULL: goto x86_l_244f;
	case 9302ULL: goto x86_l_2456;
	case 9307ULL: goto x86_l_245b;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9335ULL: goto x86_l_2477;
	case 9338ULL: goto x86_l_247a;
	case 9342ULL: goto x86_l_247e;
	case 9348ULL: goto x86_l_2484;
	case 9353ULL: goto x86_l_2489;
	case 9359ULL: goto x86_l_248f;
	case 9363ULL: goto x86_l_2493;
	case 9368ULL: goto x86_l_2498;
	case 9371ULL: goto x86_l_249b;
	case 9375ULL: goto x86_l_249f;
	case 9380ULL: goto x86_l_24a4;
	case 9385ULL: goto x86_l_24a9;
	case 9393ULL: goto x86_l_24b1;
	case 9396ULL: goto x86_l_24b4;
	case 9401ULL: goto x86_l_24b9;
	case 9406ULL: goto x86_l_24be;
	case 9413ULL: goto x86_l_24c5;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9432ULL: goto x86_l_24d8;
	case 9437ULL: goto x86_l_24dd;
	case 9439ULL: goto x86_l_24df;
	case 9444ULL: goto x86_l_24e4;
	case 9449ULL: goto x86_l_24e9;
	case 9452ULL: goto x86_l_24ec;
	case 9457ULL: goto x86_l_24f1;
	case 9462ULL: goto x86_l_24f6;
	case 9469ULL: goto x86_l_24fd;
	case 9477ULL: goto x86_l_2505;
	case 9482ULL: goto x86_l_250a;
	case 9484ULL: goto x86_l_250c;
	case 9486ULL: goto x86_l_250e;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9500ULL: goto x86_l_251c;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9523ULL: goto x86_l_2533;
	case 9529ULL: goto x86_l_2539;
	case 9532ULL: goto x86_l_253c;
	case 9536ULL: goto x86_l_2540;
	case 9545ULL: goto x86_l_2549;
	case 9552ULL: goto x86_l_2550;
	case 9554ULL: goto x86_l_2552;
	case 9556ULL: goto x86_l_2554;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9568ULL: goto x86_l_2560;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9576ULL: goto x86_l_2568;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9592ULL: goto x86_l_2578;
	case 9599ULL: goto x86_l_257f;
	case 9604ULL: goto x86_l_2584;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9618ULL: goto x86_l_2592;
	case 9625ULL: goto x86_l_2599;
	case 9632ULL: goto x86_l_25a0;
	case 9636ULL: goto x86_l_25a4;
	case 9640ULL: goto x86_l_25a8;
	case 9647ULL: goto x86_l_25af;
	case 9652ULL: goto x86_l_25b4;
	case 9657ULL: goto x86_l_25b9;
	case 9665ULL: goto x86_l_25c1;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9687ULL: goto x86_l_25d7;
	case 9696ULL: goto x86_l_25e0;
	case 9702ULL: goto x86_l_25e6;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9714ULL: goto x86_l_25f2;
	case 9721ULL: goto x86_l_25f9;
	case 9726ULL: goto x86_l_25fe;
	case 9729ULL: goto x86_l_2601;
	case 9735ULL: goto x86_l_2607;
	case 9738ULL: goto x86_l_260a;
	case 9741ULL: goto x86_l_260d;
	case 9744ULL: goto x86_l_2610;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9768ULL: goto x86_l_2628;
	case 9771ULL: goto x86_l_262b;
	case 9777ULL: goto x86_l_2631;
	case 9780ULL: goto x86_l_2634;
	case 9784ULL: goto x86_l_2638;
	case 9791ULL: goto x86_l_263f;
	case 9798ULL: goto x86_l_2646;
	case 9800ULL: goto x86_l_2648;
	case 9802ULL: goto x86_l_264a;
	case 9809ULL: goto x86_l_2651;
	case 9811ULL: goto x86_l_2653;
	case 9814ULL: goto x86_l_2656;
	case 9817ULL: goto x86_l_2659;
	case 9819ULL: goto x86_l_265b;
	case 9822ULL: goto x86_l_265e;
	case 9829ULL: goto x86_l_2665;
	case 9832ULL: goto x86_l_2668;
	case 9838ULL: goto x86_l_266e;
	case 9845ULL: goto x86_l_2675;
	case 9850ULL: goto x86_l_267a;
	case 9854ULL: goto x86_l_267e;
	case 9859ULL: goto x86_l_2683;
	case 9864ULL: goto x86_l_2688;
	case 9871ULL: goto x86_l_268f;
	case 9878ULL: goto x86_l_2696;
	case 9882ULL: goto x86_l_269a;
	case 9890ULL: goto x86_l_26a2;
	case 9897ULL: goto x86_l_26a9;
	case 9902ULL: goto x86_l_26ae;
	case 9907ULL: goto x86_l_26b3;
	case 9911ULL: goto x86_l_26b7;
	case 9919ULL: goto x86_l_26bf;
	case 9924ULL: goto x86_l_26c4;
	case 9933ULL: goto x86_l_26cd;
	case 9942ULL: goto x86_l_26d6;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9957ULL: goto x86_l_26e5;
	case 9960ULL: goto x86_l_26e8;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9981ULL: goto x86_l_26fd;
	case 9984ULL: goto x86_l_2700;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9997ULL: goto x86_l_270d;
	case 9999ULL: goto x86_l_270f;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10018ULL: goto x86_l_2722;
	case 10026ULL: goto x86_l_272a;
	case 10029ULL: goto x86_l_272d;
	case 10031ULL: goto x86_l_272f;
	case 10034ULL: goto x86_l_2732;
	case 10043ULL: goto x86_l_273b;
	case 10048ULL: goto x86_l_2740;
	case 10051ULL: goto x86_l_2743;
	case 10058ULL: goto x86_l_274a;
	case 10060ULL: goto x86_l_274c;
	case 10062ULL: goto x86_l_274e;
	case 10070ULL: goto x86_l_2756;
	case 10073ULL: goto x86_l_2759;
	case 10085ULL: goto x86_l_2765;
	case 10094ULL: goto x86_l_276e;
	case 10103ULL: goto x86_l_2777;
	case 10112ULL: goto x86_l_2780;
	case 10121ULL: goto x86_l_2789;
	case 10130ULL: goto x86_l_2792;
	case 10139ULL: goto x86_l_279b;
	case 10148ULL: goto x86_l_27a4;
	case 10158ULL: goto x86_l_27ae;
	case 10164ULL: goto x86_l_27b4;
	case 10169ULL: goto x86_l_27b9;
	case 10174ULL: goto x86_l_27be;
	case 10181ULL: goto x86_l_27c5;
	case 10186ULL: goto x86_l_27ca;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10193ULL: goto x86_l_27d1;
	case 10196ULL: goto x86_l_27d4;
	case 10200ULL: goto x86_l_27d8;
	case 10202ULL: goto x86_l_27da;
	case 10211ULL: goto x86_l_27e3;
	case 10216ULL: goto x86_l_27e8;
	case 10221ULL: goto x86_l_27ed;
	case 10228ULL: goto x86_l_27f4;
	case 10233ULL: goto x86_l_27f9;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	case 10242ULL: goto x86_l_2802;
	case 10250ULL: goto x86_l_280a;
	case 10256ULL: goto x86_l_2810;
	case 10263ULL: goto x86_l_2817;
	case 10266ULL: goto x86_l_281a;
	case 10272ULL: goto x86_l_2820;
	case 10280ULL: goto x86_l_2828;
	case 10287ULL: goto x86_l_282f;
	case 10289ULL: goto x86_l_2831;
	case 10297ULL: goto x86_l_2839;
	case 10299ULL: goto x86_l_283b;
	case 10307ULL: goto x86_l_2843;
	case 10312ULL: goto x86_l_2848;
	case 10314ULL: goto x86_l_284a;
	case 10316ULL: goto x86_l_284c;
	case 10319ULL: goto x86_l_284f;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10342ULL: goto x86_l_2866;
	case 10350ULL: goto x86_l_286e;
	case 10352ULL: goto x86_l_2870;
	case 10355ULL: goto x86_l_2873;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10369ULL: goto x86_l_2881;
	case 10374ULL: goto x86_l_2886;
	case 10381ULL: goto x86_l_288d;
	case 10389ULL: goto x86_l_2895;
	case 10394ULL: goto x86_l_289a;
	case 10397ULL: goto x86_l_289d;
	case 10399ULL: goto x86_l_289f;
	case 10401ULL: goto x86_l_28a1;
	case 10403ULL: goto x86_l_28a3;
	case 10409ULL: goto x86_l_28a9;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10429ULL: goto x86_l_28bd;
	case 10437ULL: goto x86_l_28c5;
	case 10439ULL: goto x86_l_28c7;
	case 10442ULL: goto x86_l_28ca;
	case 10448ULL: goto x86_l_28d0;
	case 10451ULL: goto x86_l_28d3;
	case 10454ULL: goto x86_l_28d6;
	case 10457ULL: goto x86_l_28d9;
	case 10464ULL: goto x86_l_28e0;
	case 10470ULL: goto x86_l_28e6;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10487ULL: goto x86_l_28f7;
	case 10492ULL: goto x86_l_28fc;
	case 10496ULL: goto x86_l_2900;
	case 10503ULL: goto x86_l_2907;
	case 10512ULL: goto x86_l_2910;
	case 10516ULL: goto x86_l_2914;
	case 10520ULL: goto x86_l_2918;
	case 10523ULL: goto x86_l_291b;
	case 10526ULL: goto x86_l_291e;
	case 10529ULL: goto x86_l_2921;
	case 10537ULL: goto x86_l_2929;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10551ULL: goto x86_l_2937;
	case 10557ULL: goto x86_l_293d;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10578ULL: goto x86_l_2952;
	case 10583ULL: goto x86_l_2957;
	case 10588ULL: goto x86_l_295c;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	case 10607ULL: goto x86_l_296f;
	case 10609ULL: goto x86_l_2971;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10622ULL: goto x86_l_297e;
	case 10630ULL: goto x86_l_2986;
	case 10638ULL: goto x86_l_298e;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10655ULL: goto x86_l_299f;
	case 10658ULL: goto x86_l_29a2;
	case 10660ULL: goto x86_l_29a4;
	case 10666ULL: goto x86_l_29aa;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10680ULL: goto x86_l_29b8;
	case 10688ULL: goto x86_l_29c0;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10708ULL: goto x86_l_29d4;
	case 10716ULL: goto x86_l_29dc;
	case 10721ULL: goto x86_l_29e1;
	case 10723ULL: goto x86_l_29e3;
	case 10725ULL: goto x86_l_29e5;
	case 10727ULL: goto x86_l_29e7;
	case 10730ULL: goto x86_l_29ea;
	case 10738ULL: goto x86_l_29f2;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10749ULL: goto x86_l_29fd;
	case 10752ULL: goto x86_l_2a00;
	case 10760ULL: goto x86_l_2a08;
	case 10763ULL: goto x86_l_2a0b;
	case 10769ULL: goto x86_l_2a11;
	case 10772ULL: goto x86_l_2a14;
	case 10776ULL: goto x86_l_2a18;
	case 10783ULL: goto x86_l_2a1f;
	case 10785ULL: goto x86_l_2a21;
	case 10787ULL: goto x86_l_2a23;
	case 10794ULL: goto x86_l_2a2a;
	case 10796ULL: goto x86_l_2a2c;
	case 10799ULL: goto x86_l_2a2f;
	case 10802ULL: goto x86_l_2a32;
	case 10804ULL: goto x86_l_2a34;
	case 10807ULL: goto x86_l_2a37;
	case 10814ULL: goto x86_l_2a3e;
	case 10817ULL: goto x86_l_2a41;
	case 10823ULL: goto x86_l_2a47;
	case 10830ULL: goto x86_l_2a4e;
	case 10835ULL: goto x86_l_2a53;
	case 10839ULL: goto x86_l_2a57;
	case 10843ULL: goto x86_l_2a5b;
	case 10848ULL: goto x86_l_2a60;
	case 10855ULL: goto x86_l_2a67;
	case 10862ULL: goto x86_l_2a6e;
	case 10866ULL: goto x86_l_2a72;
	case 10871ULL: goto x86_l_2a77;
	case 10878ULL: goto x86_l_2a7e;
	case 10883ULL: goto x86_l_2a83;
	case 10888ULL: goto x86_l_2a88;
	case 10893ULL: goto x86_l_2a8d;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10915ULL: goto x86_l_2aa3;
	case 10924ULL: goto x86_l_2aac;
	case 10930ULL: goto x86_l_2ab2;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10942ULL: goto x86_l_2abe;
	case 10949ULL: goto x86_l_2ac5;
	case 10954ULL: goto x86_l_2aca;
	case 10957ULL: goto x86_l_2acd;
	case 10963ULL: goto x86_l_2ad3;
	case 10966ULL: goto x86_l_2ad6;
	case 10972ULL: goto x86_l_2adc;
	case 10976ULL: goto x86_l_2ae0;
	case 10981ULL: goto x86_l_2ae5;
	case 10989ULL: goto x86_l_2aed;
	case 10992ULL: goto x86_l_2af0;
	case 10994ULL: goto x86_l_2af2;
	case 10999ULL: goto x86_l_2af7;
	case 11007ULL: goto x86_l_2aff;
	case 11012ULL: goto x86_l_2b04;
	case 11019ULL: goto x86_l_2b0b;
	case 11024ULL: goto x86_l_2b10;
	case 11026ULL: goto x86_l_2b12;
	case 11034ULL: goto x86_l_2b1a;
	case 11037ULL: goto x86_l_2b1d;
	case 11043ULL: goto x86_l_2b23;
	case 11049ULL: goto x86_l_2b29;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	default: return 0xffffffffffffffffULL;
	}
x86_l_23cc:
	/* 0x23cc: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23d1:
	/* 0x23d1: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_23d6:
	/* 0x23d6: mov    rax,QWORD PTR [rsp+0x118] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_23de:
	/* 0x23de: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_23e1:
	/* 0x23e1: jmp    2351 <tail_handle_ipv4_cont+0x2351> */
	return 9041ULL;
x86_l_23e6:
	/* 0x23e6: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_23e9:
	/* 0x23e9: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23ee:
	/* 0x23ee: jmp    1c67 <tail_handle_ipv4_cont+0x1c67> */
	return 7271ULL;
x86_l_23f3:
	/* 0x23f3: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_23f9:
	/* 0x23f9: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23fd:
	/* 0x23fd: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_23ff:
	/* 0x23ff: je     240b <tail_handle_ipv4_cont+0x240b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240b;
	}
x86_l_2401:
	/* 0x2401: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2405:
	/* 0x2405: jne    1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5750ULL;
	}
x86_l_240b:
	/* 0x240b: cmp    r12d,0xffffff57 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_2412:
	/* 0x2412: je     2471 <tail_handle_ipv4_cont+0x2471> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2471;
	}
x86_l_2414:
	/* 0x2414: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2418:
	/* 0x2418: jne    1676 <tail_handle_ipv4_cont+0x1676> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5750ULL;
	}
x86_l_241e:
	/* 0x241e: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_2425:
	/* 0x2425: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2427:
	/* 0x2427: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_242e:
	/* 0x242e: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_2435:
	/* 0x2435: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2438:
	/* 0x2438: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_243c:
	/* 0x243c: je     2720 <tail_handle_ipv4_cont+0x2720> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2720;
	}
x86_l_2442:
	/* 0x2442: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_244a:
	/* 0x244a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_244f:
	/* 0x244f: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_2456:
	/* 0x2456: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_245b:
	/* 0x245b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245d:
	/* 0x245d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2460:
	/* 0x2460: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_2463:
	/* 0x2463: je     274c <tail_handle_ipv4_cont+0x274c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_274c;
	}
x86_l_2469:
	/* 0x2469: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_246c:
	/* 0x246c: jmp    274e <tail_handle_ipv4_cont+0x274e> */
	goto x86_l_274e;
x86_l_2471:
	/* 0x2471: mov    r12d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_2477:
	/* 0x2477: mov    r14b,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 4ULL);
x86_l_247a:
	/* 0x247a: cmp    sil,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 4ULL);
x86_l_247e:
	/* 0x247e: je     15f1 <tail_handle_ipv4_cont+0x15f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5617ULL;
	}
x86_l_2484:
	/* 0x2484: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_2489:
	/* 0x2489: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_248f:
	/* 0x248f: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2493:
	/* 0x2493: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_2498:
	/* 0x2498: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_249b:
	/* 0x249b: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_249f:
	/* 0x249f: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_24a4:
	/* 0x24a4: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24a9:
	/* 0x24a9: mov    rax,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_24b1:
	/* 0x24b1: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_24b4:
	/* 0x24b4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24b9:
	/* 0x24b9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24be:
	/* 0x24be: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_24c5:
	/* 0x24c5: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_24cd:
	/* 0x24cd: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24d2:
	/* 0x24d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24d4:
	/* 0x24d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d6:
	/* 0x24d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24d8:
	/* 0x24d8: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24dd:
	/* 0x24dd: jns    2540 <tail_handle_ipv4_cont+0x2540> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2540;
	}
x86_l_24df:
	/* 0x24df: jmp    272f <tail_handle_ipv4_cont+0x272f> */
	goto x86_l_272f;
x86_l_24e4:
	/* 0x24e4: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24e9:
	/* 0x24e9: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_24ec:
	/* 0x24ec: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24f1:
	/* 0x24f1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24f6:
	/* 0x24f6: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_24fd:
	/* 0x24fd: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2505:
	/* 0x2505: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_250a:
	/* 0x250a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_250c:
	/* 0x250c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250e:
	/* 0x250e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2510:
	/* 0x2510: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2515:
	/* 0x2515: mov    ebp,DWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_251c:
	/* 0x251c: jns    2638 <tail_handle_ipv4_cont+0x2638> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2638;
	}
x86_l_2522:
	/* 0x2522: jmp    2740 <tail_handle_ipv4_cont+0x2740> */
	goto x86_l_2740;
x86_l_2527:
	/* 0x2527: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_252b:
	/* 0x252b: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2530:
	/* 0x2530: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2533:
	/* 0x2533: je     272f <tail_handle_ipv4_cont+0x272f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_272f;
	}
x86_l_2539:
	/* 0x2539: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_253c:
	/* 0x253c: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2540:
	/* 0x2540: movzx  r14d,BYTE PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 216ULL);
x86_l_2549:
	/* 0x2549: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2550:
	/* 0x2550: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2552:
	/* 0x2552: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2554:
	/* 0x2554: mov    edx,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_255b:
	/* 0x255b: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_255d:
	/* 0x255d: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_2560:
	/* 0x2560: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2563:
	/* 0x2563: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2565:
	/* 0x2565: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_2568:
	/* 0x2568: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_256f:
	/* 0x256f: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2572:
	/* 0x2572: mov    edx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2578:
	/* 0x2578: mov    WORD PTR [rsp+0x48],0x304 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237646084ULL);
x86_l_257f:
	/* 0x257f: mov    WORD PTR [rsp+0x4a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2584:
	/* 0x2584: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2588:
	/* 0x2588: mov    DWORD PTR [rsp+0x50],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_258d:
	/* 0x258d: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2592:
	/* 0x2592: mov    WORD PTR [rsp+0x56],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187458ULL);
x86_l_2599:
	/* 0x2599: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_25a0:
	/* 0x25a0: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25a4:
	/* 0x25a4: mov    DWORD PTR [rsp+0x5c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_25a8:
	/* 0x25a8: mov    WORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_25af:
	/* 0x25af: mov    BYTE PTR [rsp+0x62],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_25b4:
	/* 0x25b4: mov    BYTE PTR [rsp+0x63],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762304ULL);
x86_l_25b9:
	/* 0x25b9: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_25c1:
	/* 0x25c1: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_25c9:
	/* 0x25c9: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_25ce:
	/* 0x25ce: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_25d7:
	/* 0x25d7: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_25e0:
	/* 0x25e0: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_25e6:
	/* 0x25e6: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_25ea:
	/* 0x25ea: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_25ef:
	/* 0x25ef: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_25f2:
	/* 0x25f2: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_25f9:
	/* 0x25f9: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_25fe:
	/* 0x25fe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2601:
	/* 0x2601: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_2607:
	/* 0x2607: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_260a:
	/* 0x260a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_260d:
	/* 0x260d: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_2610:
	/* 0x2610: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_2613:
	/* 0x2613: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_2618:
	/* 0x2618: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_261c:
	/* 0x261c: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2621:
	/* 0x2621: mov    ebp,DWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2628:
	/* 0x2628: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_262b:
	/* 0x262b: je     2740 <tail_handle_ipv4_cont+0x2740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2740;
	}
x86_l_2631:
	/* 0x2631: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2634:
	/* 0x2634: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2638:
	/* 0x2638: mov    r14,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_263f:
	/* 0x263f: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2646:
	/* 0x2646: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2648:
	/* 0x2648: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_264a:
	/* 0x264a: mov    edx,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2651:
	/* 0x2651: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2653:
	/* 0x2653: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_2656:
	/* 0x2656: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2659:
	/* 0x2659: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_265b:
	/* 0x265b: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_265e:
	/* 0x265e: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_2665:
	/* 0x2665: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2668:
	/* 0x2668: mov    edx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_266e:
	/* 0x266e: mov    WORD PTR [rsp+0x48],0x204 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645828ULL);
x86_l_2675:
	/* 0x2675: mov    WORD PTR [rsp+0x4a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_267a:
	/* 0x267a: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_267e:
	/* 0x267e: mov    DWORD PTR [rsp+0x50],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2683:
	/* 0x2683: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2688:
	/* 0x2688: mov    WORD PTR [rsp+0x56],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187458ULL);
x86_l_268f:
	/* 0x268f: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2696:
	/* 0x2696: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_269a:
	/* 0x269a: mov    DWORD PTR [rsp+0x5c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991233ULL);
x86_l_26a2:
	/* 0x26a2: mov    WORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_26a9:
	/* 0x26a9: mov    BYTE PTR [rsp+0x62],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_26ae:
	/* 0x26ae: mov    BYTE PTR [rsp+0x63],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762304ULL);
x86_l_26b3:
	/* 0x26b3: mov    DWORD PTR [rsp+0x64],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_26b7:
	/* 0x26b7: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_26bf:
	/* 0x26bf: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_26c4:
	/* 0x26c4: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_26cd:
	/* 0x26cd: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_26d6:
	/* 0x26d6: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_26dc:
	/* 0x26dc: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_26e0:
	/* 0x26e0: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_26e5:
	/* 0x26e5: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_26e8:
	/* 0x26e8: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_26ef:
	/* 0x26ef: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_26f4:
	/* 0x26f4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26f7:
	/* 0x26f7: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_26fd:
	/* 0x26fd: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_2700:
	/* 0x2700: mov    edi,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2703:
	/* 0x2703: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_2708:
	/* 0x2708: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_270d:
	/* 0x270d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270f:
	/* 0x270f: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_2712:
	/* 0x2712: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2717:
	/* 0x2717: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_271b:
	/* 0x271b: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_2720:
	/* 0x2720: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2722:
	/* 0x2722: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_272a:
	/* 0x272a: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_272d:
	/* 0x272d: jmp    2756 <tail_handle_ipv4_cont+0x2756> */
	goto x86_l_2756;
x86_l_272f:
	/* 0x272f: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2732:
	/* 0x2732: movzx  r14d,BYTE PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 216ULL);
x86_l_273b:
	/* 0x273b: jmp    260a <tail_handle_ipv4_cont+0x260a> */
	goto x86_l_260a;
x86_l_2740:
	/* 0x2740: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2743:
	/* 0x2743: mov    r14,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_274a:
	/* 0x274a: jmp    2700 <tail_handle_ipv4_cont+0x2700> */
	goto x86_l_2700;
x86_l_274c:
	/* 0x274c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274e:
	/* 0x274e: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2756:
	/* 0x2756: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2759:
	/* 0x2759: mov    QWORD PTR [rsp+0xb0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244098ULL);
x86_l_2765:
	/* 0x2765: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_276e:
	/* 0x276e: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2777:
	/* 0x2777: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2780:
	/* 0x2780: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2789:
	/* 0x2789: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2792:
	/* 0x2792: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_279b:
	/* 0x279b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_27a4:
	/* 0x27a4: movabs rax,0x200580200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8595702272ULL);
x86_l_27ae:
	/* 0x27ae: or     rax,0x5020000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 84017152ULL);
x86_l_27b4:
	/* 0x27b4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27b9:
	/* 0x27b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_27be:
	/* 0x27be: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_27c5:
	/* 0x27c5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27ca:
	/* 0x27ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27cc:
	/* 0x27cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27cf:
	/* 0x27cf: je     27da <tail_handle_ipv4_cont+0x27da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27da;
	}
x86_l_27d1:
	/* 0x27d1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_27d4:
	/* 0x27d4: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27d8:
	/* 0x27d8: jmp    2802 <tail_handle_ipv4_cont+0x2802> */
	goto x86_l_2802;
x86_l_27da:
	/* 0x27da: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_27e3:
	/* 0x27e3: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27e8:
	/* 0x27e8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27ed:
	/* 0x27ed: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_27f4:
	/* 0x27f4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27f9:
	/* 0x27f9: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27fe:
	/* 0x27fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2800:
	/* 0x2800: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2802:
	/* 0x2802: cmp    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_280a:
	/* 0x280a: je     2ad6 <tail_handle_ipv4_cont+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ad6;
	}
x86_l_2810:
	/* 0x2810: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_2817:
	/* 0x2817: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_281a:
	/* 0x281a: je     2a18 <tail_handle_ipv4_cont+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a18;
	}
x86_l_2820:
	/* 0x2820: mov    QWORD PTR [rsp+0xd8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2828:
	/* 0x2828: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_282f:
	/* 0x282f: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2831:
	/* 0x2831: mov    QWORD PTR [rsp+0x100],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2839:
	/* 0x2839: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_283b:
	/* 0x283b: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_2843:
	/* 0x2843: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2848:
	/* 0x2848: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284a:
	/* 0x284a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_284c:
	/* 0x284c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_284f:
	/* 0x284f: mov    DWORD PTR [rsp+0xbc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851650ULL);
x86_l_285a:
	/* 0x285a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_285f:
	/* 0x285f: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_2866:
	/* 0x2866: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_286e:
	/* 0x286e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2870:
	/* 0x2870: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2873:
	/* 0x2873: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2876:
	/* 0x2876: jne    28a9 <tail_handle_ipv4_cont+0x28a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28a9;
	}
x86_l_2878:
	/* 0x2878: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2881:
	/* 0x2881: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2886:
	/* 0x2886: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_288d:
	/* 0x288d: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2895:
	/* 0x2895: lea    rbp,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_289a:
	/* 0x289a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_289d:
	/* 0x289d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_289f:
	/* 0x289f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28a1:
	/* 0x28a1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28a3:
	/* 0x28a3: js     2ad6 <tail_handle_ipv4_cont+0x2ad6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ad6;
	}
x86_l_28a9:
	/* 0x28a9: mov    QWORD PTR [rsp+0xf8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_28b1:
	/* 0x28b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28b6:
	/* 0x28b6: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_28bd:
	/* 0x28bd: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_28c5:
	/* 0x28c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c7:
	/* 0x28c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28ca:
	/* 0x28ca: je     29b3 <tail_handle_ipv4_cont+0x29b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29b3;
	}
x86_l_28d0:
	/* 0x28d0: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d3:
	/* 0x28d3: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_28d6:
	/* 0x28d6: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_28d9:
	/* 0x28d9: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_28e0:
	/* 0x28e0: jbe    29f9 <tail_handle_ipv4_cont+0x29f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_29f9;
	}
x86_l_28e6:
	/* 0x28e6: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_28e9:
	/* 0x28e9: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_28ed:
	/* 0x28ed: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_28f7:
	/* 0x28f7: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_28fc:
	/* 0x28fc: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2900:
	/* 0x2900: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_2907:
	/* 0x2907: imul   rcx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 232ULL);
x86_l_2910:
	/* 0x2910: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2914:
	/* 0x2914: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2918:
	/* 0x2918: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_291b:
	/* 0x291b: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_291e:
	/* 0x291e: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2921:
	/* 0x2921: mov    rdx,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2929:
	/* 0x2929: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_292c:
	/* 0x292c: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_292f:
	/* 0x292f: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2937:
	/* 0x2937: jbe    2a08 <tail_handle_ipv4_cont+0x2a08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2a08;
	}
x86_l_293d:
	/* 0x293d: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2941:
	/* 0x2941: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2944:
	/* 0x2944: jmp    2a08 <tail_handle_ipv4_cont+0x2a08> */
	goto x86_l_2a08;
x86_l_2949:
	/* 0x2949: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2952:
	/* 0x2952: mov    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2957:
	/* 0x2957: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_295c:
	/* 0x295c: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2963:
	/* 0x2963: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2968:
	/* 0x2968: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_296d:
	/* 0x296d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_296f:
	/* 0x296f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2971:
	/* 0x2971: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_2978:
	/* 0x2978: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_297b:
	/* 0x297b: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_297e:
	/* 0x297e: mov    QWORD PTR [rbx+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_2986:
	/* 0x2986: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_298e:
	/* 0x298e: movzx  edx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2993:
	/* 0x2993: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2998:
	/* 0x2998: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_call_policy)));
x86_l_299f:
	/* 0x299f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29a2:
	/* 0x29a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a4:
	/* 0x29a4: mov    r12d,0xffffff35 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967093ULL);
x86_l_29aa:
	/* 0x29aa: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29ae:
	/* 0x29ae: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_29b3:
	/* 0x29b3: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29b8:
	/* 0x29b8: mov    rbp,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_29c0:
	/* 0x29c0: dec    rbp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_29c3:
	/* 0x29c3: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_29c8:
	/* 0x29c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29cd:
	/* 0x29cd: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_29d4:
	/* 0x29d4: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_29dc:
	/* 0x29dc: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_29e1:
	/* 0x29e1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29e3:
	/* 0x29e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29e5:
	/* 0x29e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29e7:
	/* 0x29e7: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_29ea:
	/* 0x29ea: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_29f2:
	/* 0x29f2: jns    2a18 <tail_handle_ipv4_cont+0x2a18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2a18;
	}
x86_l_29f4:
	/* 0x29f4: jmp    2ae5 <tail_handle_ipv4_cont+0x2ae5> */
	goto x86_l_2ae5;
x86_l_29f9:
	/* 0x29f9: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29fd:
	/* 0x29fd: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_2a00:
	/* 0x2a00: mov    rbp,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2a08:
	/* 0x2a08: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_2a0b:
	/* 0x2a0b: je     2ae5 <tail_handle_ipv4_cont+0x2ae5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ae5;
	}
x86_l_2a11:
	/* 0x2a11: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2a14:
	/* 0x2a14: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a18:
	/* 0x2a18: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2a1f:
	/* 0x2a1f: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a21:
	/* 0x2a21: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a23:
	/* 0x2a23: mov    edx,DWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_2a2a:
	/* 0x2a2a: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2a2c:
	/* 0x2a2c: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_2a2f:
	/* 0x2a2f: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a32:
	/* 0x2a32: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_2a34:
	/* 0x2a34: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_2a37:
	/* 0x2a37: mov    rcx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_2a3e:
	/* 0x2a3e: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a41:
	/* 0x2a41: mov    edx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2a47:
	/* 0x2a47: mov    WORD PTR [rsp+0x48],0xb04 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237648132ULL);
x86_l_2a4e:
	/* 0x2a4e: mov    WORD PTR [rsp+0x4a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_2a53:
	/* 0x2a53: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2a57:
	/* 0x2a57: mov    DWORD PTR [rsp+0x50],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a5b:
	/* 0x2a5b: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2a60:
	/* 0x2a60: mov    WORD PTR [rsp+0x56],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 369367187458ULL);
x86_l_2a67:
	/* 0x2a67: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2a6e:
	/* 0x2a6e: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a72:
	/* 0x2a72: mov    DWORD PTR [rsp+0x5c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_2a77:
	/* 0x2a77: mov    WORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2a7e:
	/* 0x2a7e: mov    BYTE PTR [rsp+0x62],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_2a83:
	/* 0x2a83: mov    BYTE PTR [rsp+0x63],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 425201762304ULL);
x86_l_2a88:
	/* 0x2a88: mov    DWORD PTR [rsp+0x64],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_2a8d:
	/* 0x2a8d: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a95:
	/* 0x2a95: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_2aa3:
	/* 0x2aa3: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_2aac:
	/* 0x2aac: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_2ab2:
	/* 0x2ab2: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_2abb:
	/* 0x2abb: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2abe:
	/* 0x2abe: mov    rsi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_2ac5:
	/* 0x2ac5: lea    rcx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2aca:
	/* 0x2aca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2acd:
	/* 0x2acd: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_2ad3:
	/* 0x2ad3: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_2ad6:
	/* 0x2ad6: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_2adc:
	/* 0x2adc: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ae0:
	/* 0x2ae0: jmp    1676 <tail_handle_ipv4_cont+0x1676> */
	return 5750ULL;
x86_l_2ae5:
	/* 0x2ae5: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_2aed:
	/* 0x2aed: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2af0:
	/* 0x2af0: jmp    2ad6 <tail_handle_ipv4_cont+0x2ad6> */
	goto x86_l_2ad6;
x86_l_2af2:
	/* 0x2af2: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2af7:
	/* 0x2af7: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2aff:
	/* 0x2aff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b04:
	/* 0x2b04: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_2b0b:
	/* 0x2b0b: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b10:
	/* 0x2b10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b12:
	/* 0x2b12: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b1a:
	/* 0x2b1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b1d:
	/* 0x2b1d: je     2cd2 <tail_handle_ipv4_cont+0x2cd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11474ULL;
	}
x86_l_2b23:
	/* 0x2b23: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b29:
	/* 0x2b29: je     2b44 <tail_handle_ipv4_cont+0x2b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11076ULL;
	}
x86_l_2b2b:
	/* 0x2b2b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b30:
	/* 0x2b30: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b33:
	/* 0x2b33: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
	return 11067ULL;
}

static __noinline __u64 cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11067ULL: goto x86_l_2b3b;
	case 11070ULL: goto x86_l_2b3e;
	case 11076ULL: goto x86_l_2b44;
	case 11084ULL: goto x86_l_2b4c;
	case 11089ULL: goto x86_l_2b51;
	case 11096ULL: goto x86_l_2b58;
	case 11099ULL: goto x86_l_2b5b;
	case 11102ULL: goto x86_l_2b5e;
	case 11108ULL: goto x86_l_2b64;
	case 11111ULL: goto x86_l_2b67;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11122ULL: goto x86_l_2b72;
	case 11130ULL: goto x86_l_2b7a;
	case 11137ULL: goto x86_l_2b81;
	case 11140ULL: goto x86_l_2b84;
	case 11145ULL: goto x86_l_2b89;
	case 11150ULL: goto x86_l_2b8e;
	case 11154ULL: goto x86_l_2b92;
	case 11157ULL: goto x86_l_2b95;
	case 11165ULL: goto x86_l_2b9d;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11179ULL: goto x86_l_2bab;
	case 11182ULL: goto x86_l_2bae;
	case 11184ULL: goto x86_l_2bb0;
	case 11187ULL: goto x86_l_2bb3;
	case 11191ULL: goto x86_l_2bb7;
	case 11202ULL: goto x86_l_2bc2;
	case 11206ULL: goto x86_l_2bc6;
	case 11211ULL: goto x86_l_2bcb;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11228ULL: goto x86_l_2bdc;
	case 11233ULL: goto x86_l_2be1;
	case 11238ULL: goto x86_l_2be6;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11258ULL: goto x86_l_2bfa;
	case 11263ULL: goto x86_l_2bff;
	case 11265ULL: goto x86_l_2c01;
	case 11273ULL: goto x86_l_2c09;
	case 11276ULL: goto x86_l_2c0c;
	case 11282ULL: goto x86_l_2c12;
	case 11288ULL: goto x86_l_2c18;
	case 11290ULL: goto x86_l_2c1a;
	case 11295ULL: goto x86_l_2c1f;
	case 11298ULL: goto x86_l_2c22;
	case 11306ULL: goto x86_l_2c2a;
	case 11309ULL: goto x86_l_2c2d;
	case 11315ULL: goto x86_l_2c33;
	case 11323ULL: goto x86_l_2c3b;
	case 11328ULL: goto x86_l_2c40;
	case 11335ULL: goto x86_l_2c47;
	case 11338ULL: goto x86_l_2c4a;
	case 11341ULL: goto x86_l_2c4d;
	case 11347ULL: goto x86_l_2c53;
	case 11350ULL: goto x86_l_2c56;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11361ULL: goto x86_l_2c61;
	case 11369ULL: goto x86_l_2c69;
	case 11376ULL: goto x86_l_2c70;
	case 11379ULL: goto x86_l_2c73;
	case 11384ULL: goto x86_l_2c78;
	case 11389ULL: goto x86_l_2c7d;
	case 11393ULL: goto x86_l_2c81;
	case 11396ULL: goto x86_l_2c84;
	case 11404ULL: goto x86_l_2c8c;
	case 11408ULL: goto x86_l_2c90;
	case 11412ULL: goto x86_l_2c94;
	case 11418ULL: goto x86_l_2c9a;
	case 11421ULL: goto x86_l_2c9d;
	case 11423ULL: goto x86_l_2c9f;
	case 11426ULL: goto x86_l_2ca2;
	case 11430ULL: goto x86_l_2ca6;
	case 11441ULL: goto x86_l_2cb1;
	case 11445ULL: goto x86_l_2cb5;
	case 11450ULL: goto x86_l_2cba;
	case 11452ULL: goto x86_l_2cbc;
	case 11455ULL: goto x86_l_2cbf;
	case 11458ULL: goto x86_l_2cc2;
	case 11463ULL: goto x86_l_2cc7;
	case 11469ULL: goto x86_l_2ccd;
	case 11474ULL: goto x86_l_2cd2;
	case 11476ULL: goto x86_l_2cd4;
	case 11484ULL: goto x86_l_2cdc;
	case 11490ULL: goto x86_l_2ce2;
	case 11496ULL: goto x86_l_2ce8;
	case 11499ULL: goto x86_l_2ceb;
	case 11504ULL: goto x86_l_2cf0;
	case 11509ULL: goto x86_l_2cf5;
	case 11511ULL: goto x86_l_2cf7;
	case 11519ULL: goto x86_l_2cff;
	case 11525ULL: goto x86_l_2d05;
	case 11531ULL: goto x86_l_2d0b;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11544ULL: goto x86_l_2d18;
	case 11546ULL: goto x86_l_2d1a;
	case 11551ULL: goto x86_l_2d1f;
	case 11553ULL: goto x86_l_2d21;
	case 11561ULL: goto x86_l_2d29;
	case 11565ULL: goto x86_l_2d2d;
	case 11568ULL: goto x86_l_2d30;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11580ULL: goto x86_l_2d3c;
	case 11583ULL: goto x86_l_2d3f;
	case 11586ULL: goto x86_l_2d42;
	case 11589ULL: goto x86_l_2d45;
	case 11595ULL: goto x86_l_2d4b;
	case 11600ULL: goto x86_l_2d50;
	case 11608ULL: goto x86_l_2d58;
	case 11613ULL: goto x86_l_2d5d;
	case 11617ULL: goto x86_l_2d61;
	case 11619ULL: goto x86_l_2d63;
	case 11621ULL: goto x86_l_2d65;
	case 11623ULL: goto x86_l_2d67;
	case 11628ULL: goto x86_l_2d6c;
	case 11633ULL: goto x86_l_2d71;
	case 11637ULL: goto x86_l_2d75;
	case 11644ULL: goto x86_l_2d7c;
	case 11649ULL: goto x86_l_2d81;
	case 11656ULL: goto x86_l_2d88;
	case 11661ULL: goto x86_l_2d8d;
	case 11666ULL: goto x86_l_2d92;
	case 11673ULL: goto x86_l_2d99;
	case 11678ULL: goto x86_l_2d9e;
	case 11680ULL: goto x86_l_2da0;
	case 11683ULL: goto x86_l_2da3;
	case 11689ULL: goto x86_l_2da9;
	case 11698ULL: goto x86_l_2db2;
	case 11706ULL: goto x86_l_2dba;
	case 11711ULL: goto x86_l_2dbf;
	case 11716ULL: goto x86_l_2dc4;
	case 11721ULL: goto x86_l_2dc9;
	case 11723ULL: goto x86_l_2dcb;
	case 11731ULL: goto x86_l_2dd3;
	case 11735ULL: goto x86_l_2dd7;
	case 11738ULL: goto x86_l_2dda;
	case 11741ULL: goto x86_l_2ddd;
	case 11746ULL: goto x86_l_2de2;
	case 11750ULL: goto x86_l_2de6;
	case 11753ULL: goto x86_l_2de9;
	case 11756ULL: goto x86_l_2dec;
	case 11759ULL: goto x86_l_2def;
	case 11765ULL: goto x86_l_2df5;
	case 11770ULL: goto x86_l_2dfa;
	case 11778ULL: goto x86_l_2e02;
	case 11783ULL: goto x86_l_2e07;
	case 11787ULL: goto x86_l_2e0b;
	case 11789ULL: goto x86_l_2e0d;
	case 11791ULL: goto x86_l_2e0f;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11803ULL: goto x86_l_2e1b;
	case 11807ULL: goto x86_l_2e1f;
	case 11814ULL: goto x86_l_2e26;
	case 11819ULL: goto x86_l_2e2b;
	case 11826ULL: goto x86_l_2e32;
	case 11831ULL: goto x86_l_2e37;
	case 11836ULL: goto x86_l_2e3c;
	case 11843ULL: goto x86_l_2e43;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11853ULL: goto x86_l_2e4d;
	case 11855ULL: goto x86_l_2e4f;
	case 11859ULL: goto x86_l_2e53;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11874ULL: goto x86_l_2e62;
	case 11883ULL: goto x86_l_2e6b;
	case 11891ULL: goto x86_l_2e73;
	case 11896ULL: goto x86_l_2e78;
	case 11901ULL: goto x86_l_2e7d;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11918ULL: goto x86_l_2e8e;
	case 11923ULL: goto x86_l_2e93;
	case 11925ULL: goto x86_l_2e95;
	case 11933ULL: goto x86_l_2e9d;
	case 11937ULL: goto x86_l_2ea1;
	case 11939ULL: goto x86_l_2ea3;
	case 11943ULL: goto x86_l_2ea7;
	case 11946ULL: goto x86_l_2eaa;
	case 11950ULL: goto x86_l_2eae;
	case 11954ULL: goto x86_l_2eb2;
	case 11959ULL: goto x86_l_2eb7;
	case 11962ULL: goto x86_l_2eba;
	case 11969ULL: goto x86_l_2ec1;
	case 11977ULL: goto x86_l_2ec9;
	case 11980ULL: goto x86_l_2ecc;
	case 11988ULL: goto x86_l_2ed4;
	case 11990ULL: goto x86_l_2ed6;
	case 11996ULL: goto x86_l_2edc;
	case 11999ULL: goto x86_l_2edf;
	case 12002ULL: goto x86_l_2ee2;
	case 12008ULL: goto x86_l_2ee8;
	case 12010ULL: goto x86_l_2eea;
	case 12013ULL: goto x86_l_2eed;
	case 12015ULL: goto x86_l_2eef;
	case 12023ULL: goto x86_l_2ef7;
	case 12026ULL: goto x86_l_2efa;
	case 12031ULL: goto x86_l_2eff;
	case 12034ULL: goto x86_l_2f02;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12045ULL: goto x86_l_2f0d;
	case 12047ULL: goto x86_l_2f0f;
	case 12050ULL: goto x86_l_2f12;
	case 12053ULL: goto x86_l_2f15;
	case 12055ULL: goto x86_l_2f17;
	case 12063ULL: goto x86_l_2f1f;
	case 12066ULL: goto x86_l_2f22;
	case 12073ULL: goto x86_l_2f29;
	case 12076ULL: goto x86_l_2f2c;
	case 12080ULL: goto x86_l_2f30;
	case 12082ULL: goto x86_l_2f32;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12097ULL: goto x86_l_2f41;
	case 12102ULL: goto x86_l_2f46;
	case 12108ULL: goto x86_l_2f4c;
	case 12119ULL: goto x86_l_2f57;
	case 12121ULL: goto x86_l_2f59;
	case 12127ULL: goto x86_l_2f5f;
	case 12129ULL: goto x86_l_2f61;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12139ULL: goto x86_l_2f6b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2b3b:
	/* 0x2b3b: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b3e:
	/* 0x2b3e: jbe    2d1f <tail_handle_ipv4_cont+0x2d1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2d1f;
	}
x86_l_2b44:
	/* 0x2b44: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2b4c:
	/* 0x2b4c: movzx  r12d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2b51:
	/* 0x2b51: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_2b58:
	/* 0x2b58: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b5b:
	/* 0x2b5b: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2b5e:
	/* 0x2b5e: je     2ea1 <tail_handle_ipv4_cont+0x2ea1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea1;
	}
x86_l_2b64:
	/* 0x2b64: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2b67:
	/* 0x2b67: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_2b6a:
	/* 0x2b6a: movzx  ecx,BYTE PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b72:
	/* 0x2b72: mov    QWORD PTR [rsp+0xc8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2b7a:
	/* 0x2b7a: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_2b81:
	/* 0x2b81: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b84:
	/* 0x2b84: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b89:
	/* 0x2b89: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_2b8e:
	/* 0x2b8e: mov    BYTE PTR [rsp+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_2b92:
	/* 0x2b92: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_2b95:
	/* 0x2b95: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_2b9d:
	/* 0x2b9d: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2ba1:
	/* 0x2ba1: cmp    r12b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 71ULL);
x86_l_2ba5:
	/* 0x2ba5: ja     2d5d <tail_handle_ipv4_cont+0x2d5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d5d;
	}
x86_l_2bab:
	/* 0x2bab: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bae:
	/* 0x2bae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb0:
	/* 0x2bb0: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2bb3:
	/* 0x2bb3: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bb7:
	/* 0x2bb7: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2bc2:
	/* 0x2bc2: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_2bc6:
	/* 0x2bc6: jmp    2d7c <tail_handle_ipv4_cont+0x2d7c> */
	goto x86_l_2d7c;
x86_l_2bcb:
	/* 0x2bcb: mov    r12d,0xffffff4b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967115ULL);
x86_l_2bd1:
	/* 0x2bd1: jmp    a3c <tail_handle_ipv4_cont+0xa3c> */
	return 2620ULL;
x86_l_2bd6:
	/* 0x2bd6: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_2bdc:
	/* 0x2bdc: jmp    1ef4 <tail_handle_ipv4_cont+0x1ef4> */
	return 7924ULL;
x86_l_2be1:
	/* 0x2be1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be6:
	/* 0x2be6: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_2bee:
	/* 0x2bee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf3:
	/* 0x2bf3: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_2bfa:
	/* 0x2bfa: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2bff:
	/* 0x2bff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c01:
	/* 0x2c01: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c09:
	/* 0x2c09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c0c:
	/* 0x2c0c: je     2cf5 <tail_handle_ipv4_cont+0x2cf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf5;
	}
x86_l_2c12:
	/* 0x2c12: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c18:
	/* 0x2c18: je     2c33 <tail_handle_ipv4_cont+0x2c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c33;
	}
x86_l_2c1a:
	/* 0x2c1a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c1f:
	/* 0x2c1f: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c22:
	/* 0x2c22: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c2a:
	/* 0x2c2a: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c2d:
	/* 0x2c2d: jbe    2dc9 <tail_handle_ipv4_cont+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2dc9;
	}
x86_l_2c33:
	/* 0x2c33: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2c3b:
	/* 0x2c3b: movzx  r12d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2c40:
	/* 0x2c40: mov    rax,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_2c47:
	/* 0x2c47: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c4a:
	/* 0x2c4a: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2c4d:
	/* 0x2c4d: je     2ea1 <tail_handle_ipv4_cont+0x2ea1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ea1;
	}
x86_l_2c53:
	/* 0x2c53: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2c56:
	/* 0x2c56: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_2c59:
	/* 0x2c59: movzx  ecx,BYTE PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_2c5e:
	/* 0x2c5e: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c61:
	/* 0x2c61: mov    QWORD PTR [rsp+0xc8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2c69:
	/* 0x2c69: mov    rdx,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_2c70:
	/* 0x2c70: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c73:
	/* 0x2c73: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c78:
	/* 0x2c78: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_2c7d:
	/* 0x2c7d: mov    BYTE PTR [rsp+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_2c81:
	/* 0x2c81: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_2c84:
	/* 0x2c84: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_2c8c:
	/* 0x2c8c: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c90:
	/* 0x2c90: cmp    r12b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 71ULL);
x86_l_2c94:
	/* 0x2c94: ja     2e07 <tail_handle_ipv4_cont+0x2e07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e07;
	}
x86_l_2c9a:
	/* 0x2c9a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c9d:
	/* 0x2c9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c9f:
	/* 0x2c9f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_2ca2:
	/* 0x2ca2: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ca6:
	/* 0x2ca6: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2cb1:
	/* 0x2cb1: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_2cb5:
	/* 0x2cb5: jmp    2e26 <tail_handle_ipv4_cont+0x2e26> */
	goto x86_l_2e26;
x86_l_2cba:
	/* 0x2cba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cbc:
	/* 0x2cbc: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2cbf:
	/* 0x2cbf: cmp    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_2cc2:
	/* 0x2cc2: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2cc7:
	/* 0x2cc7: jae    1ff6 <tail_handle_ipv4_cont+0x1ff6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8182ULL;
	}
x86_l_2ccd:
	/* 0x2ccd: jmp    2037 <tail_handle_ipv4_cont+0x2037> */
	return 8247ULL;
x86_l_2cd2:
	/* 0x2cd2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd4:
	/* 0x2cd4: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2cdc:
	/* 0x2cdc: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ce2:
	/* 0x2ce2: je     2f46 <tail_handle_ipv4_cont+0x2f46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f46;
	}
x86_l_2ce8:
	/* 0x2ce8: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ceb:
	/* 0x2ceb: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cf0:
	/* 0x2cf0: jmp    825 <tail_handle_ipv4_cont+0x825> */
	return 2085ULL;
x86_l_2cf5:
	/* 0x2cf5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf7:
	/* 0x2cf7: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2cff:
	/* 0x2cff: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2d05:
	/* 0x2d05: je     2f46 <tail_handle_ipv4_cont+0x2f46> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f46;
	}
x86_l_2d0b:
	/* 0x2d0b: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d0e:
	/* 0x2d0e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d13:
	/* 0x2d13: jmp    97f <tail_handle_ipv4_cont+0x97f> */
	return 2431ULL;
x86_l_2d18:
	/* 0x2d18: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_2d1a:
	/* 0x2d1a: jmp    1edb <tail_handle_ipv4_cont+0x1edb> */
	return 7899ULL;
x86_l_2d1f:
	/* 0x2d1f: jne    2d4b <tail_handle_ipv4_cont+0x2d4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d4b;
	}
x86_l_2d21:
	/* 0x2d21: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d29:
	/* 0x2d29: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d2d:
	/* 0x2d2d: shr    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_2d30:
	/* 0x2d30: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_2d33:
	/* 0x2d33: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d38:
	/* 0x2d38: movzx  ecx,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d3c:
	/* 0x2d3c: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_2d3f:
	/* 0x2d3f: and    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_2d42:
	/* 0x2d42: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_2d45:
	/* 0x2d45: ja     2b44 <tail_handle_ipv4_cont+0x2b44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b44;
	}
x86_l_2d4b:
	/* 0x2d4b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d50:
	/* 0x2d50: mov    r9,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d58:
	/* 0x2d58: jmp    825 <tail_handle_ipv4_cont+0x825> */
	return 2085ULL;
x86_l_2d5d:
	/* 0x2d5d: cmp    r12b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 191ULL);
x86_l_2d61:
	/* 0x2d61: ja     2d7c <tail_handle_ipv4_cont+0x2d7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2d7c;
	}
x86_l_2d63:
	/* 0x2d63: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_2d65:
	/* 0x2d65: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2d67:
	/* 0x2d67: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_2d6c:
	/* 0x2d6c: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_2d71:
	/* 0x2d71: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_2d75:
	/* 0x2d75: and    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_2d7c:
	/* 0x2d7c: mov    BYTE PTR [rsp+0x29],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_2d81:
	/* 0x2d81: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2d88:
	/* 0x2d88: mov    WORD PTR [rsp+0x2a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2d8d:
	/* 0x2d8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d92:
	/* 0x2d92: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_2d99:
	/* 0x2d99: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d9e:
	/* 0x2d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da0:
	/* 0x2da0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2da3:
	/* 0x2da3: jne    2e4f <tail_handle_ipv4_cont+0x2e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e4f;
	}
x86_l_2da9:
	/* 0x2da9: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2db2:
	/* 0x2db2: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2dba:
	/* 0x2dba: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2dbf:
	/* 0x2dbf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dc4:
	/* 0x2dc4: jmp    2e7d <tail_handle_ipv4_cont+0x2e7d> */
	goto x86_l_2e7d;
x86_l_2dc9:
	/* 0x2dc9: jne    2df5 <tail_handle_ipv4_cont+0x2df5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2df5;
	}
x86_l_2dcb:
	/* 0x2dcb: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2dd3:
	/* 0x2dd3: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2dd7:
	/* 0x2dd7: shr    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_2dda:
	/* 0x2dda: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_2ddd:
	/* 0x2ddd: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2de2:
	/* 0x2de2: movzx  ecx,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2de6:
	/* 0x2de6: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_2de9:
	/* 0x2de9: and    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_2dec:
	/* 0x2dec: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_2def:
	/* 0x2def: ja     2c33 <tail_handle_ipv4_cont+0x2c33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2c33;
	}
x86_l_2df5:
	/* 0x2df5: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    r9,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e02:
	/* 0x2e02: jmp    97f <tail_handle_ipv4_cont+0x97f> */
	return 2431ULL;
x86_l_2e07:
	/* 0x2e07: cmp    r12b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 191ULL);
x86_l_2e0b:
	/* 0x2e0b: ja     2e26 <tail_handle_ipv4_cont+0x2e26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2e26;
	}
x86_l_2e0d:
	/* 0x2e0d: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_2e0f:
	/* 0x2e0f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2e11:
	/* 0x2e11: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_2e16:
	/* 0x2e16: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_2e1b:
	/* 0x2e1b: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_2e1f:
	/* 0x2e1f: and    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_2e26:
	/* 0x2e26: mov    BYTE PTR [rsp+0x29],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_2e2b:
	/* 0x2e2b: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2e32:
	/* 0x2e32: mov    WORD PTR [rsp+0x2a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2e37:
	/* 0x2e37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e3c:
	/* 0x2e3c: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_2e43:
	/* 0x2e43: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e48:
	/* 0x2e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e4a:
	/* 0x2e4a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e4d:
	/* 0x2e4d: je     2e62 <tail_handle_ipv4_cont+0x2e62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e62;
	}
x86_l_2e4f:
	/* 0x2e4f: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2e53:
	/* 0x2e53: mov    rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2e5b:
	/* 0x2e5b: add QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2e60:
	/* 0x2e60: jmp    2e95 <tail_handle_ipv4_cont+0x2e95> */
	goto x86_l_2e95;
x86_l_2e62:
	/* 0x2e62: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2e6b:
	/* 0x2e6b: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2e73:
	/* 0x2e73: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2e78:
	/* 0x2e78: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e7d:
	/* 0x2e7d: mov    rdi,QWORD PTR [rip+0x635a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_2e84:
	/* 0x2e84: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e89:
	/* 0x2e89: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2e8e:
	/* 0x2e8e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e93:
	/* 0x2e93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e95:
	/* 0x2e95: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e9d:
	/* 0x2e9d: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2ea1:
	/* 0x2ea1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ea3:
	/* 0x2ea3: cmp    r12b,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 72ULL);
x86_l_2ea7:
	/* 0x2ea7: setb   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_B);
x86_l_2eaa:
	/* 0x2eaa: cmp    r12b,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 8ULL);
x86_l_2eae:
	/* 0x2eae: lea    ecx,[rcx+rcx*2+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 3ULL);
x86_l_2eb2:
	/* 0x2eb2: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2eb7:
	/* 0x2eb7: cmovae edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_2eba:
	/* 0x2eba: mov    DWORD PTR [rsp+0xe4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_2ec1:
	/* 0x2ec1: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ec9:
	/* 0x2ec9: mov    ecx,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ecc:
	/* 0x2ecc: mov    QWORD PTR [rsp+0xc8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2ed4:
	/* 0x2ed4: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2ed6:
	/* 0x2ed6: jne    2f59 <tail_handle_ipv4_cont+0x2f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f59;
	}
x86_l_2edc:
	/* 0x2edc: movzx  esi,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2edf:
	/* 0x2edf: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2ee2:
	/* 0x2ee2: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2ee8:
	/* 0x2ee8: je     2f17 <tail_handle_ipv4_cont+0x2f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f17;
	}
x86_l_2eea:
	/* 0x2eea: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2eed:
	/* 0x2eed: js     2f17 <tail_handle_ipv4_cont+0x2f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f17;
	}
x86_l_2eef:
	/* 0x2eef: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ef7:
	/* 0x2ef7: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2efa:
	/* 0x2efa: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eff:
	/* 0x2eff: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2f02:
	/* 0x2f02: jne    2f17 <tail_handle_ipv4_cont+0x2f17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f17;
	}
x86_l_2f04:
	/* 0x2f04: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f09:
	/* 0x2f09: movzx  eax,BYTE PTR [rax+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_2f0d:
	/* 0x2f0d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2f0f:
	/* 0x2f0f: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_2f12:
	/* 0x2f12: cmp    cx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_16);
x86_l_2f15:
	/* 0x2f15: ja     2f69 <tail_handle_ipv4_cont+0x2f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2f69;
	}
x86_l_2f17:
	/* 0x2f17: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2f1f:
	/* 0x2f1f: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2f22:
	/* 0x2f22: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2f29:
	/* 0x2f29: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f2c:
	/* 0x2f2c: and    sil,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_2f30:
	/* 0x2f30: jne    2f61 <tail_handle_ipv4_cont+0x2f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f61;
	}
x86_l_2f32:
	/* 0x2f32: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f34:
	/* 0x2f34: mov    r13d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f39:
	/* 0x2f39: mov    rdx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2f41:
	/* 0x2f41: jmp    1ef4 <tail_handle_ipv4_cont+0x1ef4> */
	return 7924ULL;
x86_l_2f46:
	/* 0x2f46: mov    r12d,0xffffff7b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967163ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    DWORD PTR [rsp+0xe4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 979252543488ULL);
x86_l_2f57:
	/* 0x2f57: jmp    2f32 <tail_handle_ipv4_cont+0x2f32> */
	goto x86_l_2f32;
x86_l_2f59:
	/* 0x2f59: mov    r12d,0xffffff4b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967115ULL);
x86_l_2f5f:
	/* 0x2f5f: jmp    2f32 <tail_handle_ipv4_cont+0x2f32> */
	goto x86_l_2f32;
x86_l_2f61:
	/* 0x2f61: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_2f67:
	/* 0x2f67: jmp    2f34 <tail_handle_ipv4_cont+0x2f34> */
	goto x86_l_2f34;
x86_l_2f69:
	/* 0x2f69: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2f6b:
	/* 0x2f6b: jmp    2f17 <tail_handle_ipv4_cont+0x2f17> */
	goto x86_l_2f17;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_lxc_tail_handle_ipv4_cont_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10140U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1918ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1922ULL && __x86_pc <= 3666ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3669ULL && __x86_pc <= 5491ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5496ULL && __x86_pc <= 7332ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7337ULL && __x86_pc <= 9159ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9164ULL && __x86_pc <= 11059ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 11067ULL && __x86_pc <= 12139ULL)
			__x86_pc = cilium_bpf_lxc_tail_handle_ipv4_cont_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

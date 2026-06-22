extern char __config_cilium_host_mac;
extern char __config_cilium_net_ifindex;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_extended_ip_protocols;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_enable_tproxy;
extern char __config_eth_header_length;
extern char __config_interface_ifindex;
extern char __config_interface_mac;
extern char __config_kernel_hz;
extern char __config_proxy_redirect_via_cilium_net;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_affinity;
extern char cilium_lb6_backends_v3;
extern char cilium_lb6_services_v2;
extern char cilium_lb6_source_range;
extern char cilium_lb_affinity_match;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_nodeport_neigh6;
extern char cilium_percpu_trace_id;
extern char cilium_tail_call_buffer6;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_0(
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
	case 35ULL: goto x86_l_23;
	case 42ULL: goto x86_l_2a;
	case 47ULL: goto x86_l_2f;
	case 50ULL: goto x86_l_32;
	case 53ULL: goto x86_l_35;
	case 57ULL: goto x86_l_39;
	case 61ULL: goto x86_l_3d;
	case 67ULL: goto x86_l_43;
	case 70ULL: goto x86_l_46;
	case 73ULL: goto x86_l_49;
	case 79ULL: goto x86_l_4f;
	case 84ULL: goto x86_l_54;
	case 87ULL: goto x86_l_57;
	case 94ULL: goto x86_l_5e;
	case 97ULL: goto x86_l_61;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 118ULL: goto x86_l_76;
	case 122ULL: goto x86_l_7a;
	case 127ULL: goto x86_l_7f;
	case 133ULL: goto x86_l_85;
	case 137ULL: goto x86_l_89;
	case 143ULL: goto x86_l_8f;
	case 149ULL: goto x86_l_95;
	case 153ULL: goto x86_l_99;
	case 159ULL: goto x86_l_9f;
	case 164ULL: goto x86_l_a4;
	case 169ULL: goto x86_l_a9;
	case 174ULL: goto x86_l_ae;
	case 177ULL: goto x86_l_b1;
	case 182ULL: goto x86_l_b6;
	case 184ULL: goto x86_l_b8;
	case 186ULL: goto x86_l_ba;
	case 192ULL: goto x86_l_c0;
	case 195ULL: goto x86_l_c3;
	case 200ULL: goto x86_l_c8;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 212ULL: goto x86_l_d4;
	case 215ULL: goto x86_l_d7;
	case 225ULL: goto x86_l_e1;
	case 231ULL: goto x86_l_e7;
	case 234ULL: goto x86_l_ea;
	case 240ULL: goto x86_l_f0;
	case 245ULL: goto x86_l_f5;
	case 253ULL: goto x86_l_fd;
	case 257ULL: goto x86_l_101;
	case 260ULL: goto x86_l_104;
	case 266ULL: goto x86_l_10a;
	case 271ULL: goto x86_l_10f;
	case 276ULL: goto x86_l_114;
	case 280ULL: goto x86_l_118;
	case 286ULL: goto x86_l_11e;
	case 292ULL: goto x86_l_124;
	case 296ULL: goto x86_l_128;
	case 302ULL: goto x86_l_12e;
	case 307ULL: goto x86_l_133;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 320ULL: goto x86_l_140;
	case 325ULL: goto x86_l_145;
	case 328ULL: goto x86_l_148;
	case 331ULL: goto x86_l_14b;
	case 336ULL: goto x86_l_150;
	case 338ULL: goto x86_l_152;
	case 340ULL: goto x86_l_154;
	case 346ULL: goto x86_l_15a;
	case 351ULL: goto x86_l_15f;
	case 355ULL: goto x86_l_163;
	case 361ULL: goto x86_l_169;
	case 365ULL: goto x86_l_16d;
	case 371ULL: goto x86_l_173;
	case 375ULL: goto x86_l_177;
	case 381ULL: goto x86_l_17d;
	case 387ULL: goto x86_l_183;
	case 391ULL: goto x86_l_187;
	case 396ULL: goto x86_l_18c;
	case 400ULL: goto x86_l_190;
	case 406ULL: goto x86_l_196;
	case 411ULL: goto x86_l_19b;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 434ULL: goto x86_l_1b2;
	case 438ULL: goto x86_l_1b6;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 449ULL: goto x86_l_1c1;
	case 453ULL: goto x86_l_1c5;
	case 459ULL: goto x86_l_1cb;
	case 463ULL: goto x86_l_1cf;
	case 468ULL: goto x86_l_1d4;
	case 473ULL: goto x86_l_1d9;
	case 476ULL: goto x86_l_1dc;
	case 481ULL: goto x86_l_1e1;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 491ULL: goto x86_l_1eb;
	case 496ULL: goto x86_l_1f0;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 508ULL: goto x86_l_1fc;
	case 511ULL: goto x86_l_1ff;
	case 521ULL: goto x86_l_209;
	case 527ULL: goto x86_l_20f;
	case 530ULL: goto x86_l_212;
	case 536ULL: goto x86_l_218;
	case 541ULL: goto x86_l_21d;
	case 548ULL: goto x86_l_224;
	case 553ULL: goto x86_l_229;
	case 557ULL: goto x86_l_22d;
	case 564ULL: goto x86_l_234;
	case 570ULL: goto x86_l_23a;
	case 576ULL: goto x86_l_240;
	case 580ULL: goto x86_l_244;
	case 590ULL: goto x86_l_24e;
	case 593ULL: goto x86_l_251;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 605ULL: goto x86_l_25d;
	case 611ULL: goto x86_l_263;
	case 615ULL: goto x86_l_267;
	case 619ULL: goto x86_l_26b;
	case 624ULL: goto x86_l_270;
	case 629ULL: goto x86_l_275;
	case 632ULL: goto x86_l_278;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 642ULL: goto x86_l_282;
	case 644ULL: goto x86_l_284;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 660ULL: goto x86_l_294;
	case 663ULL: goto x86_l_297;
	case 669ULL: goto x86_l_29d;
	case 672ULL: goto x86_l_2a0;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 702ULL: goto x86_l_2be;
	case 707ULL: goto x86_l_2c3;
	case 713ULL: goto x86_l_2c9;
	case 716ULL: goto x86_l_2cc;
	case 721ULL: goto x86_l_2d1;
	case 725ULL: goto x86_l_2d5;
	case 731ULL: goto x86_l_2db;
	case 736ULL: goto x86_l_2e0;
	case 738ULL: goto x86_l_2e2;
	case 742ULL: goto x86_l_2e6;
	case 745ULL: goto x86_l_2e9;
	case 752ULL: goto x86_l_2f0;
	case 758ULL: goto x86_l_2f6;
	case 763ULL: goto x86_l_2fb;
	case 769ULL: goto x86_l_301;
	case 773ULL: goto x86_l_305;
	case 776ULL: goto x86_l_308;
	case 782ULL: goto x86_l_30e;
	case 784ULL: goto x86_l_310;
	case 787ULL: goto x86_l_313;
	case 794ULL: goto x86_l_31a;
	case 799ULL: goto x86_l_31f;
	case 802ULL: goto x86_l_322;
	case 812ULL: goto x86_l_32c;
	case 814ULL: goto x86_l_32e;
	case 821ULL: goto x86_l_335;
	case 826ULL: goto x86_l_33a;
	case 831ULL: goto x86_l_33f;
	case 834ULL: goto x86_l_342;
	case 836ULL: goto x86_l_344;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 851ULL: goto x86_l_353;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 864ULL: goto x86_l_360;
	case 870ULL: goto x86_l_366;
	case 872ULL: goto x86_l_368;
	case 876ULL: goto x86_l_36c;
	case 882ULL: goto x86_l_372;
	case 886ULL: goto x86_l_376;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 900ULL: goto x86_l_384;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 910ULL: goto x86_l_38e;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 926ULL: goto x86_l_39e;
	case 930ULL: goto x86_l_3a2;
	case 933ULL: goto x86_l_3a5;
	case 935ULL: goto x86_l_3a7;
	case 938ULL: goto x86_l_3aa;
	case 948ULL: goto x86_l_3b4;
	case 954ULL: goto x86_l_3ba;
	case 957ULL: goto x86_l_3bd;
	case 959ULL: goto x86_l_3bf;
	case 964ULL: goto x86_l_3c4;
	case 971ULL: goto x86_l_3cb;
	case 973ULL: goto x86_l_3cd;
	case 983ULL: goto x86_l_3d7;
	case 988ULL: goto x86_l_3dc;
	case 995ULL: goto x86_l_3e3;
	case 997ULL: goto x86_l_3e5;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1018ULL: goto x86_l_3fa;
	case 1023ULL: goto x86_l_3ff;
	case 1026ULL: goto x86_l_402;
	case 1029ULL: goto x86_l_405;
	case 1034ULL: goto x86_l_40a;
	case 1036ULL: goto x86_l_40c;
	case 1038ULL: goto x86_l_40e;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1054ULL: goto x86_l_41e;
	case 1064ULL: goto x86_l_428;
	case 1069ULL: goto x86_l_42d;
	case 1075ULL: goto x86_l_433;
	case 1081ULL: goto x86_l_439;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1094ULL: goto x86_l_446;
	case 1097ULL: goto x86_l_449;
	case 1099ULL: goto x86_l_44b;
	case 1101ULL: goto x86_l_44d;
	case 1105ULL: goto x86_l_451;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1115ULL: goto x86_l_45b;
	case 1120ULL: goto x86_l_460;
	case 1123ULL: goto x86_l_463;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1133ULL: goto x86_l_46d;
	case 1139ULL: goto x86_l_473;
	case 1141ULL: goto x86_l_475;
	case 1147ULL: goto x86_l_47b;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1162ULL: goto x86_l_48a;
	case 1168ULL: goto x86_l_490;
	case 1171ULL: goto x86_l_493;
	case 1176ULL: goto x86_l_498;
	case 1182ULL: goto x86_l_49e;
	case 1187ULL: goto x86_l_4a3;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1200ULL: goto x86_l_4b0;
	case 1203ULL: goto x86_l_4b3;
	case 1206ULL: goto x86_l_4b6;
	case 1211ULL: goto x86_l_4bb;
	case 1213ULL: goto x86_l_4bd;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1228ULL: goto x86_l_4cc;
	case 1234ULL: goto x86_l_4d2;
	case 1240ULL: goto x86_l_4d8;
	case 1246ULL: goto x86_l_4de;
	case 1251ULL: goto x86_l_4e3;
	case 1254ULL: goto x86_l_4e6;
	case 1260ULL: goto x86_l_4ec;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1274ULL: goto x86_l_4fa;
	case 1276ULL: goto x86_l_4fc;
	case 1281ULL: goto x86_l_501;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1313ULL: goto x86_l_521;
	case 1318ULL: goto x86_l_526;
	case 1324ULL: goto x86_l_52c;
	case 1326ULL: goto x86_l_52e;
	case 1330ULL: goto x86_l_532;
	case 1336ULL: goto x86_l_538;
	case 1339ULL: goto x86_l_53b;
	case 1342ULL: goto x86_l_53e;
	case 1346ULL: goto x86_l_542;
	case 1350ULL: goto x86_l_546;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1363ULL: goto x86_l_553;
	case 1366ULL: goto x86_l_556;
	case 1371ULL: goto x86_l_55b;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1385ULL: goto x86_l_569;
	case 1389ULL: goto x86_l_56d;
	case 1395ULL: goto x86_l_573;
	case 1398ULL: goto x86_l_576;
	case 1405ULL: goto x86_l_57d;
	case 1411ULL: goto x86_l_583;
	case 1414ULL: goto x86_l_586;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1439ULL: goto x86_l_59f;
	case 1444ULL: goto x86_l_5a4;
	case 1447ULL: goto x86_l_5a7;
	case 1450ULL: goto x86_l_5aa;
	case 1452ULL: goto x86_l_5ac;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1464ULL: goto x86_l_5b8;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1479ULL: goto x86_l_5c7;
	case 1481ULL: goto x86_l_5c9;
	case 1484ULL: goto x86_l_5cc;
	case 1494ULL: goto x86_l_5d6;
	case 1498ULL: goto x86_l_5da;
	case 1501ULL: goto x86_l_5dd;
	case 1511ULL: goto x86_l_5e7;
	case 1519ULL: goto x86_l_5ef;
	case 1526ULL: goto x86_l_5f6;
	case 1533ULL: goto x86_l_5fd;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1548ULL: goto x86_l_60c;
	case 1551ULL: goto x86_l_60f;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1560ULL: goto x86_l_618;
	case 1562ULL: goto x86_l_61a;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1583ULL: goto x86_l_62f;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1601ULL: goto x86_l_641;
	case 1603ULL: goto x86_l_643;
	case 1605ULL: goto x86_l_645;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1639ULL: goto x86_l_667;
	case 1641ULL: goto x86_l_669;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1657ULL: goto x86_l_679;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1677ULL: goto x86_l_68d;
	case 1679ULL: goto x86_l_68f;
	case 1684ULL: goto x86_l_694;
	case 1687ULL: goto x86_l_697;
	case 1694ULL: goto x86_l_69e;
	case 1701ULL: goto x86_l_6a5;
	case 1707ULL: goto x86_l_6ab;
	case 1712ULL: goto x86_l_6b0;
	case 1715ULL: goto x86_l_6b3;
	case 1720ULL: goto x86_l_6b8;
	case 1722ULL: goto x86_l_6ba;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1734ULL: goto x86_l_6c6;
	case 1737ULL: goto x86_l_6c9;
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1748ULL: goto x86_l_6d4;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_a:
	/* 0xa: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r12d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_23:
	/* 0x23: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2a:
	/* 0x2a: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f:
	/* 0x2f: mov    eax,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_32:
	/* 0x32: mov    ecx,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35:
	/* 0x35: lea    rdx,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_39:
	/* 0x39: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3d:
	/* 0x3d: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_43:
	/* 0x43: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46:
	/* 0x46: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_49:
	/* 0x49: ja     5a7 <tail_handle_ipv6_from_netdev+0x5a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5a7;
	}
x86_l_4f:
	/* 0x4f: mov    DWORD PTR [rsp+0x8],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54:
	/* 0x54: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_57:
	/* 0x57: mov    rcx,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_5e:
	/* 0x5e: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61:
	/* 0x61: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_70:
	/* 0x70: je     10f <tail_handle_ipv6_from_netdev+0x10f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10f;
	}
x86_l_76:
	/* 0x76: movzx  ebx,BYTE PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_7a:
	/* 0x7a: movzx  r12d,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7f:
	/* 0x7f: mov    r14d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 40ULL);
x86_l_85:
	/* 0x85: cmp    rbx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 60ULL);
x86_l_89:
	/* 0x89: ja     490 <tail_handle_ipv6_from_netdev+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_490;
	}
x86_l_8f:
	/* 0x8f: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_95:
	/* 0x95: bt     rdx,rbx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: jae    18c <tail_handle_ipv6_from_netdev+0x18c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18c;
	}
x86_l_9f:
	/* 0x9f: lea    esi,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a4:
	/* 0xa4: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a9:
	/* 0xa9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ae:
	/* 0xae: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_b1:
	/* 0xb1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b6:
	/* 0xb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8:
	/* 0xb8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ba:
	/* 0xba: js     599 <tail_handle_ipv6_from_netdev+0x599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_599;
	}
x86_l_c0:
	/* 0xc0: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_c8:
	/* 0xc8: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_cb:
	/* 0xcb: cmp    ebx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 43ULL);
x86_l_ce:
	/* 0xce: jle    19b <tail_handle_ipv6_from_netdev+0x19b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_19b;
	}
x86_l_d4:
	/* 0xd4: cmp    ebx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 44ULL);
x86_l_d7:
	/* 0xd7: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_e1:
	/* 0xe1: je     2fb <tail_handle_ipv6_from_netdev+0x2fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fb;
	}
x86_l_e7:
	/* 0xe7: cmp    ebx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 60ULL);
x86_l_ea:
	/* 0xea: je     1a5 <tail_handle_ipv6_from_netdev+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a5;
	}
x86_l_f0:
	/* 0xf0: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_f5:
	/* 0xf5: lea    r14d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_fd:
	/* 0xfd: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_101:
	/* 0x101: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_104:
	/* 0x104: jbe    1bf <tail_handle_ipv6_from_netdev+0x1bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1bf;
	}
x86_l_10a:
	/* 0x10a: jmp    30e <tail_handle_ipv6_from_netdev+0x30e> */
	goto x86_l_30e;
x86_l_10f:
	/* 0x10f: movzx  r13d,BYTE PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_114:
	/* 0x114: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_118:
	/* 0x118: ja     679 <tail_handle_ipv6_from_netdev+0x679> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_679;
	}
x86_l_11e:
	/* 0x11e: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_124:
	/* 0x124: bt     rdx,r13 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_128:
	/* 0x128: jae    2d1 <tail_handle_ipv6_from_netdev+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2d1;
	}
x86_l_12e:
	/* 0x12e: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_133:
	/* 0x133: sub    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_136:
	/* 0x136: lea    r14d,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13b:
	/* 0x13b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_140:
	/* 0x140: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_145:
	/* 0x145: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_148:
	/* 0x148: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_14b:
	/* 0x14b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_150:
	/* 0x150: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152:
	/* 0x152: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_154:
	/* 0x154: js     599 <tail_handle_ipv6_from_netdev+0x599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_599;
	}
x86_l_15a:
	/* 0x15a: movzx  ebx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_15f:
	/* 0x15f: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_163:
	/* 0x163: jle    229 <tail_handle_ipv6_from_netdev+0x229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_229;
	}
x86_l_169:
	/* 0x169: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_16d:
	/* 0x16d: je     229 <tail_handle_ipv6_from_netdev+0x229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_229;
	}
x86_l_173:
	/* 0x173: cmp    r13d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 51ULL);
x86_l_177:
	/* 0x177: jne    32e <tail_handle_ipv6_from_netdev+0x32e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_32e;
	}
x86_l_17d:
	/* 0x17d: movzx  r13d,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_183:
	/* 0x183: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_187:
	/* 0x187: jmp    244 <tail_handle_ipv6_from_netdev+0x244> */
	goto x86_l_244;
x86_l_18c:
	/* 0x18c: cmp    rbx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 59ULL);
x86_l_190:
	/* 0x190: je     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59f;
	}
x86_l_196:
	/* 0x196: jmp    490 <tail_handle_ipv6_from_netdev+0x490> */
	goto x86_l_490;
x86_l_19b:
	/* 0x19b: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1a5:
	/* 0x1a5: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_1aa:
	/* 0x1aa: lea    r14d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_1b2:
	/* 0x1b2: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1b6:
	/* 0x1b6: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1b9:
	/* 0x1b9: ja     30e <tail_handle_ipv6_from_netdev+0x30e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_30e;
	}
x86_l_1bf:
	/* 0x1bf: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1c1:
	/* 0x1c1: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1c5:
	/* 0x1c5: jae    2e0 <tail_handle_ipv6_from_netdev+0x2e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2e0;
	}
x86_l_1cb:
	/* 0x1cb: lea    esi,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1cf:
	/* 0x1cf: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d4:
	/* 0x1d4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1d9:
	/* 0x1d9: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1dc:
	/* 0x1dc: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1e1:
	/* 0x1e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3:
	/* 0x1e3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e5:
	/* 0x1e5: js     2c3 <tail_handle_ipv6_from_netdev+0x2c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c3;
	}
x86_l_1eb:
	/* 0x1eb: movzx  ebx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_1f0:
	/* 0x1f0: movzx  edx,bl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f3:
	/* 0x1f3: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1f6:
	/* 0x1f6: jle    31f <tail_handle_ipv6_from_netdev+0x31f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_31f;
	}
x86_l_1fc:
	/* 0x1fc: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_1ff:
	/* 0x1ff: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_209:
	/* 0x209: je     33a <tail_handle_ipv6_from_netdev+0x33a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a;
	}
x86_l_20f:
	/* 0x20f: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_212:
	/* 0x212: jne    344 <tail_handle_ipv6_from_netdev+0x344> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_344;
	}
x86_l_218:
	/* 0x218: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_21d:
	/* 0x21d: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_224:
	/* 0x224: jmp    33f <tail_handle_ipv6_from_netdev+0x33f> */
	goto x86_l_33f;
x86_l_229:
	/* 0x229: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_22d:
	/* 0x22d: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_234:
	/* 0x234: je     3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_23a:
	/* 0x23a: movzx  r13d,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_240:
	/* 0x240: shl    r13d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_244:
	/* 0x244: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_24e:
	/* 0x24e: cmp    ebx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 60ULL);
x86_l_251:
	/* 0x251: ja     679 <tail_handle_ipv6_from_netdev+0x679> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_679;
	}
x86_l_257:
	/* 0x257: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_259:
	/* 0x259: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_25d:
	/* 0x25d: jae    66f <tail_handle_ipv6_from_netdev+0x66f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_66f;
	}
x86_l_263:
	/* 0x263: lea    r14d,[r12+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_267:
	/* 0x267: add    r14d,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 48ULL);
x86_l_26b:
	/* 0x26b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_270:
	/* 0x270: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_275:
	/* 0x275: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_278:
	/* 0x278: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_27b:
	/* 0x27b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_280:
	/* 0x280: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282:
	/* 0x282: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_284:
	/* 0x284: js     599 <tail_handle_ipv6_from_netdev+0x599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_599;
	}
x86_l_28a:
	/* 0x28a: mov    QWORD PTR [rsp+0x68],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_28f:
	/* 0x28f: movzx  esi,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_294:
	/* 0x294: cmp    ebx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 43ULL);
x86_l_297:
	/* 0x297: jle    3e5 <tail_handle_ipv6_from_netdev+0x3e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3e5;
	}
x86_l_29d:
	/* 0x29d: cmp    ebx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 44ULL);
x86_l_2a0:
	/* 0x2a0: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2a7:
	/* 0x2a7: je     3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_2ad:
	/* 0x2ad: cmp    ebx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 51ULL);
x86_l_2b0:
	/* 0x2b0: jne    3ec <tail_handle_ipv6_from_netdev+0x3ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3ec;
	}
x86_l_2b6:
	/* 0x2b6: movzx  ebx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_2bb:
	/* 0x2bb: shl    ebx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_2be:
	/* 0x2be: jmp    514 <tail_handle_ipv6_from_netdev+0x514> */
	goto x86_l_514;
x86_l_2c3:
	/* 0x2c3: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_2c9:
	/* 0x2c9: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2cc:
	/* 0x2cc: jmp    59f <tail_handle_ipv6_from_netdev+0x59f> */
	goto x86_l_59f;
x86_l_2d1:
	/* 0x2d1: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_2d5:
	/* 0x2d5: je     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59f;
	}
x86_l_2db:
	/* 0x2db: jmp    679 <tail_handle_ipv6_from_netdev+0x679> */
	goto x86_l_679;
x86_l_2e0:
	/* 0x2e0: mov    ebx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_32);
x86_l_2e2:
	/* 0x2e2: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_2e6:
	/* 0x2e6: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_2e9:
	/* 0x2e9: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2f0:
	/* 0x2f0: je     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59f;
	}
x86_l_2f6:
	/* 0x2f6: jmp    490 <tail_handle_ipv6_from_netdev+0x490> */
	goto x86_l_490;
x86_l_2fb:
	/* 0x2fb: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_301:
	/* 0x301: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_305:
	/* 0x305: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_308:
	/* 0x308: jbe    1bf <tail_handle_ipv6_from_netdev+0x1bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1bf;
	}
x86_l_30e:
	/* 0x30e: mov    ebx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_32);
x86_l_310:
	/* 0x310: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_313:
	/* 0x313: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_31a:
	/* 0x31a: jmp    490 <tail_handle_ipv6_from_netdev+0x490> */
	goto x86_l_490;
x86_l_31f:
	/* 0x31f: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_322:
	/* 0x322: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_32c:
	/* 0x32c: jmp    347 <tail_handle_ipv6_from_netdev+0x347> */
	goto x86_l_347;
x86_l_32e:
	/* 0x32e: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_335:
	/* 0x335: jmp    3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	goto x86_l_3f5;
x86_l_33a:
	/* 0x33a: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_33f:
	/* 0x33f: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_342:
	/* 0x342: jmp    353 <tail_handle_ipv6_from_netdev+0x353> */
	goto x86_l_353;
x86_l_344:
	/* 0x344: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_347:
	/* 0x347: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_34c:
	/* 0x34c: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_353:
	/* 0x353: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_35a:
	/* 0x35a: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_35d:
	/* 0x35d: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_360:
	/* 0x360: ja     490 <tail_handle_ipv6_from_netdev+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_490;
	}
x86_l_366:
	/* 0x366: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_368:
	/* 0x368: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_36c:
	/* 0x36c: jae    486 <tail_handle_ipv6_from_netdev+0x486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_486;
	}
x86_l_372:
	/* 0x372: mov    DWORD PTR [rsp+0x68],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_376:
	/* 0x376: lea    esi,[r14+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_37a:
	/* 0x37a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37f:
	/* 0x37f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_384:
	/* 0x384: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_387:
	/* 0x387: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_38c:
	/* 0x38c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38e:
	/* 0x38e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_390:
	/* 0x390: js     599 <tail_handle_ipv6_from_netdev+0x599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_599;
	}
x86_l_396:
	/* 0x396: movzx  ebx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_39b:
	/* 0x39b: movzx  eax,bl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_39e:
	/* 0x39e: mov    ecx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3a2:
	/* 0x3a2: cmp    ecx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 43ULL);
x86_l_3a5:
	/* 0x3a5: jle    3cd <tail_handle_ipv6_from_netdev+0x3cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3cd;
	}
x86_l_3a7:
	/* 0x3a7: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_3aa:
	/* 0x3aa: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3b4:
	/* 0x3b4: je     43e <tail_handle_ipv6_from_netdev+0x43e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43e;
	}
x86_l_3ba:
	/* 0x3ba: cmp    ecx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 51ULL);
x86_l_3bd:
	/* 0x3bd: jne    3d7 <tail_handle_ipv6_from_netdev+0x3d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3d7;
	}
x86_l_3bf:
	/* 0x3bf: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_3c4:
	/* 0x3c4: lea    ecx,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_3cb:
	/* 0x3cb: jmp    443 <tail_handle_ipv6_from_netdev+0x443> */
	goto x86_l_443;
x86_l_3cd:
	/* 0x3cd: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3d7:
	/* 0x3d7: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_3dc:
	/* 0x3dc: lea    ecx,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_3e3:
	/* 0x3e3: jmp    443 <tail_handle_ipv6_from_netdev+0x443> */
	goto x86_l_443;
x86_l_3e5:
	/* 0x3e5: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_3ec:
	/* 0x3ec: cmp    ebx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 44ULL);
x86_l_3ef:
	/* 0x3ef: jne    50c <tail_handle_ipv6_from_netdev+0x50c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50c;
	}
x86_l_3f5:
	/* 0x3f5: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3fa:
	/* 0x3fa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3ff:
	/* 0x3ff: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_402:
	/* 0x402: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_405:
	/* 0x405: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_40a:
	/* 0x40a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40c:
	/* 0x40c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40e:
	/* 0x40e: js     599 <tail_handle_ipv6_from_netdev+0x599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_599;
	}
x86_l_414:
	/* 0x414: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_419:
	/* 0x419: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_41e:
	/* 0x41e: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_428:
	/* 0x428: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42d:
	/* 0x42d: je     76 <tail_handle_ipv6_from_netdev+0x76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76;
	}
x86_l_433:
	/* 0x433: mov    r15d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967139ULL);
x86_l_439:
	/* 0x439: jmp    59f <tail_handle_ipv6_from_netdev+0x59f> */
	goto x86_l_59f;
x86_l_43e:
	/* 0x43e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_443:
	/* 0x443: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_446:
	/* 0x446: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_449:
	/* 0x449: ja     490 <tail_handle_ipv6_from_netdev+0x490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_490;
	}
x86_l_44b:
	/* 0x44b: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_44d:
	/* 0x44d: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_451:
	/* 0x451: jae    486 <tail_handle_ipv6_from_netdev+0x486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_486;
	}
x86_l_453:
	/* 0x453: add    r14d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_456:
	/* 0x456: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_45b:
	/* 0x45b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_460:
	/* 0x460: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_463:
	/* 0x463: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_466:
	/* 0x466: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_46b:
	/* 0x46b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46d:
	/* 0x46d: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_473:
	/* 0x473: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_475:
	/* 0x475: js     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_59f;
	}
x86_l_47b:
	/* 0x47b: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_481:
	/* 0x481: jmp    59f <tail_handle_ipv6_from_netdev+0x59f> */
	goto x86_l_59f;
x86_l_486:
	/* 0x486: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_48a:
	/* 0x48a: je     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59f;
	}
x86_l_490:
	/* 0x490: cmp    bl,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_8, 58ULL);
x86_l_493:
	/* 0x493: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_498:
	/* 0x498: jne    16b3 <tail_handle_ipv6_from_netdev+0x16b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5811ULL;
	}
x86_l_49e:
	/* 0x49e: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4a3:
	/* 0x4a3: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4a6:
	/* 0x4a6: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4ab:
	/* 0x4ab: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4b0:
	/* 0x4b0: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_4b6:
	/* 0x4b6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4bb:
	/* 0x4bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bd:
	/* 0x4bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4bf:
	/* 0x4bf: js     501 <tail_handle_ipv6_from_netdev+0x501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_501;
	}
x86_l_4c1:
	/* 0x4c1: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_4c6:
	/* 0x4c6: lea    ecx,[rax-0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551488ULL);
x86_l_4c9:
	/* 0x4c9: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_4cc:
	/* 0x4cc: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_4d2:
	/* 0x4d2: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_4d8:
	/* 0x4d8: ja     6c4 <tail_handle_ipv6_from_netdev+0x6c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_6c4;
	}
x86_l_4de:
	/* 0x4de: mov    edx,0x3b0e17c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 61923708ULL);
x86_l_4e3:
	/* 0x4e3: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_4e6:
	/* 0x4e6: jb     6cf <tail_handle_ipv6_from_netdev+0x6cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6cf;
	}
x86_l_4ec:
	/* 0x4ec: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_4f1:
	/* 0x4f1: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_4f4:
	/* 0x4f4: jae    68a <tail_handle_ipv6_from_netdev+0x68a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_68a;
	}
x86_l_4fa:
	/* 0x4fa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fc:
	/* 0x4fc: jmp    6d1 <tail_handle_ipv6_from_netdev+0x6d1> */
	goto x86_l_6d1;
x86_l_501:
	/* 0x501: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_507:
	/* 0x507: jmp    5a4 <tail_handle_ipv6_from_netdev+0x5a4> */
	goto x86_l_5a4;
x86_l_50c:
	/* 0x50c: movzx  ebx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_511:
	/* 0x511: shl    ebx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_514:
	/* 0x514: cmp    esi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 60ULL);
x86_l_517:
	/* 0x517: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_521:
	/* 0x521: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_526:
	/* 0x526: ja     679 <tail_handle_ipv6_from_netdev+0x679> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_679;
	}
x86_l_52c:
	/* 0x52c: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_52e:
	/* 0x52e: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_532:
	/* 0x532: jae    66f <tail_handle_ipv6_from_netdev+0x66f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_66f;
	}
x86_l_538:
	/* 0x538: mov    r13d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_32);
x86_l_53b:
	/* 0x53b: lea    eax,[rcx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_53e:
	/* 0x53e: lea    r14d,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_542:
	/* 0x542: add    r14d,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_546:
	/* 0x546: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_54b:
	/* 0x54b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_550:
	/* 0x550: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_553:
	/* 0x553: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_556:
	/* 0x556: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_55b:
	/* 0x55b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55d:
	/* 0x55d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55f:
	/* 0x55f: js     599 <tail_handle_ipv6_from_netdev+0x599> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_599;
	}
x86_l_561:
	/* 0x561: movzx  edi,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_566:
	/* 0x566: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_569:
	/* 0x569: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_56d:
	/* 0x56d: jle    973 <tail_handle_ipv6_from_netdev+0x973> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2419ULL;
	}
x86_l_573:
	/* 0x573: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_576:
	/* 0x576: mov    r13,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_57d:
	/* 0x57d: je     3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f5;
	}
x86_l_583:
	/* 0x583: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_586:
	/* 0x586: jne    97a <tail_handle_ipv6_from_netdev+0x97a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2426ULL;
	}
x86_l_58c:
	/* 0x58c: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_591:
	/* 0x591: shl    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_594:
	/* 0x594: jmp    98b <tail_handle_ipv6_from_netdev+0x98b> */
	return 2443ULL;
x86_l_599:
	/* 0x599: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_59f:
	/* 0x59f: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a4:
	/* 0x5a4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a7:
	/* 0x5a7: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_5aa:
	/* 0x5aa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_5ac:
	/* 0x5ac: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_5ae:
	/* 0x5ae: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_5b1:
	/* 0x5b1: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b4:
	/* 0x5b4: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_5b8:
	/* 0x5b8: movzx  ecx,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5bc:
	/* 0x5bc: mov    DWORD PTR [rbp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c0:
	/* 0x5c0: mov    DWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_5c7:
	/* 0x5c7: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_5c9:
	/* 0x5c9: mov    DWORD PTR [rbp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5cc:
	/* 0x5cc: movabs rcx,0x1ee010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 139049746596626432ULL);
x86_l_5d6:
	/* 0x5d6: mov    QWORD PTR [rbp+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_5da:
	/* 0x5da: mov    ebx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5dd:
	/* 0x5dd: movabs rcx,0x101ee0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4327342336ULL);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5ef:
	/* 0x5ef: mov    BYTE PTR [rsp+0xa0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5f6:
	/* 0x5f6: mov    rdi,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_5fd:
	/* 0x5fd: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_605:
	/* 0x605: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60a:
	/* 0x60a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60c:
	/* 0x60c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60f:
	/* 0x60f: je     61a <tail_handle_ipv6_from_netdev+0x61a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_61a;
	}
x86_l_611:
	/* 0x611: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_614:
	/* 0x614: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_618:
	/* 0x618: jmp    645 <tail_handle_ipv6_from_netdev+0x645> */
	goto x86_l_645;
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_628:
	/* 0x628: mov    rdi,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_62f:
	/* 0x62f: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_637:
	/* 0x637: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_63c:
	/* 0x63c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_641:
	/* 0x641: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_643:
	/* 0x643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_645:
	/* 0x645: mov    rsi,QWORD PTR [rip+0x1bdc7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_64c:
	/* 0x64c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_651:
	/* 0x651: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_654:
	/* 0x654: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_659:
	/* 0x659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65b:
	/* 0x65b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_660:
	/* 0x660: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_667:
	/* 0x667: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_669:
	/* 0x669: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_66a:
	/* 0x66a: jmp    4a23 <tail_handle_ipv6_from_netdev+0x4a23> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_66f:
	/* 0x66f: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_673:
	/* 0x673: je     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_59f;
	}
x86_l_679:
	/* 0x679: mov    r13,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_680:
	/* 0x680: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_685:
	/* 0x685: jmp    76 <tail_handle_ipv6_from_netdev+0x76> */
	goto x86_l_76;
x86_l_68a:
	/* 0x68a: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_68d:
	/* 0x68d: jne    6c4 <tail_handle_ipv6_from_netdev+0x6c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6c4;
	}
x86_l_68f:
	/* 0x68f: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_694:
	/* 0x694: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_697:
	/* 0x697: mov    DWORD PTR [rbp+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_69e:
	/* 0x69e: mov    rsi,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_6a5:
	/* 0x6a5: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_6ab:
	/* 0x6ab: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_6b0:
	/* 0x6b0: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6b3:
	/* 0x6b3: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_6b8:
	/* 0x6b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ba:
	/* 0x6ba: mov    eax,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967156ULL);
x86_l_6bf:
	/* 0x6bf: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	goto x86_l_5aa;
x86_l_6c4:
	/* 0x6c4: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_6c6:
	/* 0x6c6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6c9:
	/* 0x6c9: jae    835 <tail_handle_ipv6_from_netdev+0x835> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2101ULL;
	}
x86_l_6cf:
	/* 0x6cf: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_6d1:
	/* 0x6d1: mov    eax,DWORD PTR [rbp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6d4:
	/* 0x6d4: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 1752ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1752ULL: goto x86_l_6d8;
	case 1755ULL: goto x86_l_6db;
	case 1758ULL: goto x86_l_6de;
	case 1766ULL: goto x86_l_6e6;
	case 1776ULL: goto x86_l_6f0;
	case 1782ULL: goto x86_l_6f6;
	case 1786ULL: goto x86_l_6fa;
	case 1791ULL: goto x86_l_6ff;
	case 1803ULL: goto x86_l_70b;
	case 1815ULL: goto x86_l_717;
	case 1827ULL: goto x86_l_723;
	case 1839ULL: goto x86_l_72f;
	case 1851ULL: goto x86_l_73b;
	case 1863ULL: goto x86_l_747;
	case 1875ULL: goto x86_l_753;
	case 1887ULL: goto x86_l_75f;
	case 1892ULL: goto x86_l_764;
	case 1897ULL: goto x86_l_769;
	case 1902ULL: goto x86_l_76e;
	case 1910ULL: goto x86_l_776;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1930ULL: goto x86_l_78a;
	case 1935ULL: goto x86_l_78f;
	case 1939ULL: goto x86_l_793;
	case 1941ULL: goto x86_l_795;
	case 1945ULL: goto x86_l_799;
	case 1950ULL: goto x86_l_79e;
	case 1955ULL: goto x86_l_7a3;
	case 1960ULL: goto x86_l_7a8;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1969ULL: goto x86_l_7b1;
	case 1971ULL: goto x86_l_7b3;
	case 1977ULL: goto x86_l_7b9;
	case 1983ULL: goto x86_l_7bf;
	case 1987ULL: goto x86_l_7c3;
	case 1992ULL: goto x86_l_7c8;
	case 1996ULL: goto x86_l_7cc;
	case 1998ULL: goto x86_l_7ce;
	case 2002ULL: goto x86_l_7d2;
	case 2007ULL: goto x86_l_7d7;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2023ULL: goto x86_l_7e7;
	case 2025ULL: goto x86_l_7e9;
	case 2030ULL: goto x86_l_7ee;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2049ULL: goto x86_l_801;
	case 2055ULL: goto x86_l_807;
	case 2060ULL: goto x86_l_80c;
	case 2065ULL: goto x86_l_811;
	case 2075ULL: goto x86_l_81b;
	case 2080ULL: goto x86_l_820;
	case 2088ULL: goto x86_l_828;
	case 2092ULL: goto x86_l_82c;
	case 2094ULL: goto x86_l_82e;
	case 2096ULL: goto x86_l_830;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2111ULL: goto x86_l_83f;
	case 2117ULL: goto x86_l_845;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2141ULL: goto x86_l_85d;
	case 2143ULL: goto x86_l_85f;
	case 2148ULL: goto x86_l_864;
	case 2150ULL: goto x86_l_866;
	case 2152ULL: goto x86_l_868;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2171ULL: goto x86_l_87b;
	case 2174ULL: goto x86_l_87e;
	case 2179ULL: goto x86_l_883;
	case 2189ULL: goto x86_l_88d;
	case 2192ULL: goto x86_l_890;
	case 2197ULL: goto x86_l_895;
	case 2201ULL: goto x86_l_899;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2238ULL: goto x86_l_8be;
	case 2242ULL: goto x86_l_8c2;
	case 2246ULL: goto x86_l_8c6;
	case 2250ULL: goto x86_l_8ca;
	case 2256ULL: goto x86_l_8d0;
	case 2259ULL: goto x86_l_8d3;
	case 2263ULL: goto x86_l_8d7;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2280ULL: goto x86_l_8e8;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2292ULL: goto x86_l_8f4;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2307ULL: goto x86_l_903;
	case 2309ULL: goto x86_l_905;
	case 2314ULL: goto x86_l_90a;
	case 2316ULL: goto x86_l_90c;
	case 2318ULL: goto x86_l_90e;
	case 2324ULL: goto x86_l_914;
	case 2330ULL: goto x86_l_91a;
	case 2334ULL: goto x86_l_91e;
	case 2340ULL: goto x86_l_924;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2359ULL: goto x86_l_937;
	case 2367ULL: goto x86_l_93f;
	case 2373ULL: goto x86_l_945;
	case 2376ULL: goto x86_l_948;
	case 2380ULL: goto x86_l_94c;
	case 2386ULL: goto x86_l_952;
	case 2391ULL: goto x86_l_957;
	case 2399ULL: goto x86_l_95f;
	case 2404ULL: goto x86_l_964;
	case 2407ULL: goto x86_l_967;
	case 2412ULL: goto x86_l_96c;
	case 2414ULL: goto x86_l_96e;
	case 2419ULL: goto x86_l_973;
	case 2426ULL: goto x86_l_97a;
	case 2429ULL: goto x86_l_97d;
	case 2435ULL: goto x86_l_983;
	case 2440ULL: goto x86_l_988;
	case 2443ULL: goto x86_l_98b;
	case 2446ULL: goto x86_l_98e;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2467ULL: goto x86_l_9a3;
	case 2469ULL: goto x86_l_9a5;
	case 2473ULL: goto x86_l_9a9;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2485ULL: goto x86_l_9b5;
	case 2487ULL: goto x86_l_9b7;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2505ULL: goto x86_l_9c9;
	case 2507ULL: goto x86_l_9cb;
	case 2510ULL: goto x86_l_9ce;
	case 2513ULL: goto x86_l_9d1;
	case 2518ULL: goto x86_l_9d6;
	case 2520ULL: goto x86_l_9d8;
	case 2526ULL: goto x86_l_9de;
	case 2528ULL: goto x86_l_9e0;
	case 2534ULL: goto x86_l_9e6;
	case 2536ULL: goto x86_l_9e8;
	case 2539ULL: goto x86_l_9eb;
	case 2545ULL: goto x86_l_9f1;
	case 2548ULL: goto x86_l_9f4;
	case 2555ULL: goto x86_l_9fb;
	case 2561ULL: goto x86_l_a01;
	case 2564ULL: goto x86_l_a04;
	case 2570ULL: goto x86_l_a0a;
	case 2575ULL: goto x86_l_a0f;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2595ULL: goto x86_l_a23;
	case 2603ULL: goto x86_l_a2b;
	case 2606ULL: goto x86_l_a2e;
	case 2608ULL: goto x86_l_a30;
	case 2614ULL: goto x86_l_a36;
	case 2619ULL: goto x86_l_a3b;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2639ULL: goto x86_l_a4f;
	case 2643ULL: goto x86_l_a53;
	case 2649ULL: goto x86_l_a59;
	case 2658ULL: goto x86_l_a62;
	case 2663ULL: goto x86_l_a67;
	case 2668ULL: goto x86_l_a6c;
	case 2673ULL: goto x86_l_a71;
	case 2675ULL: goto x86_l_a73;
	case 2680ULL: goto x86_l_a78;
	case 2682ULL: goto x86_l_a7a;
	case 2684ULL: goto x86_l_a7c;
	case 2690ULL: goto x86_l_a82;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2703ULL: goto x86_l_a8f;
	case 2706ULL: goto x86_l_a92;
	case 2711ULL: goto x86_l_a97;
	case 2721ULL: goto x86_l_aa1;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2733ULL: goto x86_l_aad;
	case 2743ULL: goto x86_l_ab7;
	case 2746ULL: goto x86_l_aba;
	case 2751ULL: goto x86_l_abf;
	case 2755ULL: goto x86_l_ac3;
	case 2760ULL: goto x86_l_ac8;
	case 2770ULL: goto x86_l_ad2;
	case 2778ULL: goto x86_l_ada;
	case 2782ULL: goto x86_l_ade;
	case 2785ULL: goto x86_l_ae1;
	case 2789ULL: goto x86_l_ae5;
	case 2795ULL: goto x86_l_aeb;
	case 2798ULL: goto x86_l_aee;
	case 2802ULL: goto x86_l_af2;
	case 2808ULL: goto x86_l_af8;
	case 2811ULL: goto x86_l_afb;
	case 2814ULL: goto x86_l_afe;
	case 2819ULL: goto x86_l_b03;
	case 2822ULL: goto x86_l_b06;
	case 2827ULL: goto x86_l_b0b;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2839ULL: goto x86_l_b17;
	case 2844ULL: goto x86_l_b1c;
	case 2846ULL: goto x86_l_b1e;
	case 2848ULL: goto x86_l_b20;
	case 2850ULL: goto x86_l_b22;
	case 2856ULL: goto x86_l_b28;
	case 2860ULL: goto x86_l_b2c;
	case 2866ULL: goto x86_l_b32;
	case 2870ULL: goto x86_l_b36;
	case 2875ULL: goto x86_l_b3b;
	case 2885ULL: goto x86_l_b45;
	case 2891ULL: goto x86_l_b4b;
	case 2894ULL: goto x86_l_b4e;
	case 2897ULL: goto x86_l_b51;
	case 2901ULL: goto x86_l_b55;
	case 2907ULL: goto x86_l_b5b;
	case 2912ULL: goto x86_l_b60;
	case 2920ULL: goto x86_l_b68;
	case 2925ULL: goto x86_l_b6d;
	case 2930ULL: goto x86_l_b72;
	case 2935ULL: goto x86_l_b77;
	case 2940ULL: goto x86_l_b7c;
	case 2945ULL: goto x86_l_b81;
	case 2949ULL: goto x86_l_b85;
	case 2954ULL: goto x86_l_b8a;
	case 2958ULL: goto x86_l_b8e;
	case 2964ULL: goto x86_l_b94;
	case 2966ULL: goto x86_l_b96;
	case 2969ULL: goto x86_l_b99;
	case 2974ULL: goto x86_l_b9e;
	case 2978ULL: goto x86_l_ba2;
	case 2986ULL: goto x86_l_baa;
	case 2993ULL: goto x86_l_bb1;
	case 2996ULL: goto x86_l_bb4;
	case 3001ULL: goto x86_l_bb9;
	case 3005ULL: goto x86_l_bbd;
	case 3013ULL: goto x86_l_bc5;
	case 3017ULL: goto x86_l_bc9;
	case 3025ULL: goto x86_l_bd1;
	case 3029ULL: goto x86_l_bd5;
	case 3037ULL: goto x86_l_bdd;
	case 3041ULL: goto x86_l_be1;
	case 3049ULL: goto x86_l_be9;
	case 3052ULL: goto x86_l_bec;
	case 3056ULL: goto x86_l_bf0;
	case 3061ULL: goto x86_l_bf5;
	case 3063ULL: goto x86_l_bf7;
	case 3067ULL: goto x86_l_bfb;
	case 3070ULL: goto x86_l_bfe;
	case 3076ULL: goto x86_l_c04;
	case 3079ULL: goto x86_l_c07;
	case 3085ULL: goto x86_l_c0d;
	case 3089ULL: goto x86_l_c11;
	case 3091ULL: goto x86_l_c13;
	case 3101ULL: goto x86_l_c1d;
	case 3109ULL: goto x86_l_c25;
	case 3116ULL: goto x86_l_c2c;
	case 3119ULL: goto x86_l_c2f;
	case 3127ULL: goto x86_l_c37;
	case 3133ULL: goto x86_l_c3d;
	case 3138ULL: goto x86_l_c42;
	case 3141ULL: goto x86_l_c45;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3153ULL: goto x86_l_c51;
	case 3157ULL: goto x86_l_c55;
	case 3160ULL: goto x86_l_c58;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3173ULL: goto x86_l_c65;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3187ULL: goto x86_l_c73;
	case 3190ULL: goto x86_l_c76;
	case 3195ULL: goto x86_l_c7b;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3211ULL: goto x86_l_c8b;
	case 3216ULL: goto x86_l_c90;
	case 3222ULL: goto x86_l_c96;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3237ULL: goto x86_l_ca5;
	case 3239ULL: goto x86_l_ca7;
	case 3241ULL: goto x86_l_ca9;
	case 3244ULL: goto x86_l_cac;
	case 3247ULL: goto x86_l_caf;
	case 3250ULL: goto x86_l_cb2;
	case 3252ULL: goto x86_l_cb4;
	case 3258ULL: goto x86_l_cba;
	case 3265ULL: goto x86_l_cc1;
	case 3269ULL: goto x86_l_cc5;
	case 3275ULL: goto x86_l_ccb;
	case 3277ULL: goto x86_l_ccd;
	case 3283ULL: goto x86_l_cd3;
	case 3285ULL: goto x86_l_cd5;
	case 3287ULL: goto x86_l_cd7;
	case 3293ULL: goto x86_l_cdd;
	case 3296ULL: goto x86_l_ce0;
	case 3303ULL: goto x86_l_ce7;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3318ULL: goto x86_l_cf6;
	case 3321ULL: goto x86_l_cf9;
	case 3327ULL: goto x86_l_cff;
	case 3330ULL: goto x86_l_d02;
	case 3334ULL: goto x86_l_d06;
	case 3337ULL: goto x86_l_d09;
	case 3340ULL: goto x86_l_d0c;
	case 3342ULL: goto x86_l_d0e;
	case 3350ULL: goto x86_l_d16;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3363ULL: goto x86_l_d23;
	case 3366ULL: goto x86_l_d26;
	case 3370ULL: goto x86_l_d2a;
	case 3374ULL: goto x86_l_d2e;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3386ULL: goto x86_l_d3a;
	case 3391ULL: goto x86_l_d3f;
	case 3394ULL: goto x86_l_d42;
	case 3397ULL: goto x86_l_d45;
	case 3401ULL: goto x86_l_d49;
	case 3405ULL: goto x86_l_d4d;
	case 3409ULL: goto x86_l_d51;
	case 3412ULL: goto x86_l_d54;
	case 3421ULL: goto x86_l_d5d;
	case 3429ULL: goto x86_l_d65;
	case 3438ULL: goto x86_l_d6e;
	case 3446ULL: goto x86_l_d76;
	case 3451ULL: goto x86_l_d7b;
	case 3454ULL: goto x86_l_d7e;
	case 3458ULL: goto x86_l_d82;
	case 3463ULL: goto x86_l_d87;
	case 3468ULL: goto x86_l_d8c;
	case 3475ULL: goto x86_l_d93;
	case 3480ULL: goto x86_l_d98;
	case 3485ULL: goto x86_l_d9d;
	case 3487ULL: goto x86_l_d9f;
	case 3489ULL: goto x86_l_da1;
	case 3492ULL: goto x86_l_da4;
	case 3498ULL: goto x86_l_daa;
	case 3501ULL: goto x86_l_dad;
	case 3506ULL: goto x86_l_db2;
	case 3516ULL: goto x86_l_dbc;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3531ULL: goto x86_l_dcb;
	case 3535ULL: goto x86_l_dcf;
	case 3539ULL: goto x86_l_dd3;
	case 3543ULL: goto x86_l_dd7;
	case 3547ULL: goto x86_l_ddb;
	case 3550ULL: goto x86_l_dde;
	case 3558ULL: goto x86_l_de6;
	case 3563ULL: goto x86_l_deb;
	case 3567ULL: goto x86_l_def;
	case 3572ULL: goto x86_l_df4;
	case 3577ULL: goto x86_l_df9;
	case 3583ULL: goto x86_l_dff;
	case 3591ULL: goto x86_l_e07;
	case 3595ULL: goto x86_l_e0b;
	case 3601ULL: goto x86_l_e11;
	case 3606ULL: goto x86_l_e16;
	case 3609ULL: goto x86_l_e19;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6d8:
	/* 0x6d8: and    eax,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_6db:
	/* 0x6db: mov    DWORD PTR [rbp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6de:
	/* 0x6de: test   DWORD PTR [rsp+0x28],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691844ULL);
x86_l_6e6:
	/* 0x6e6: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_6f0:
	/* 0x6f0: jne    cd3 <tail_handle_ipv6_from_netdev+0xcd3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cd3;
	}
x86_l_6f6:
	/* 0x6f6: mov    DWORD PTR [rsp+0x68],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6fa:
	/* 0x6fa: movzx  ebx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_6ff:
	/* 0x6ff: mov    QWORD PTR [rsp+0xbe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_70b:
	/* 0x70b: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_717:
	/* 0x717: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_723:
	/* 0x723: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_72f:
	/* 0x72f: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_73b:
	/* 0x73b: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_747:
	/* 0x747: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_753:
	/* 0x753: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_75f:
	/* 0x75f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_764:
	/* 0x764: movzx  r14d,BYTE PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_769:
	/* 0x769: movzx  r15d,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_76e:
	/* 0x76e: mov    BYTE PTR [rsp+0xc4],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_776:
	/* 0x776: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_77b:
	/* 0x77b: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_77f:
	/* 0x77f: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_784:
	/* 0x784: ja     96c <tail_handle_ipv6_from_netdev+0x96c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_96c;
	}
x86_l_78a:
	/* 0x78a: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_78f:
	/* 0x78f: bt     rcx,r14 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_793:
	/* 0x793: jae    7f8 <tail_handle_ipv6_from_netdev+0x7f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_7f8;
	}
x86_l_795:
	/* 0x795: lea    ebp,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_799:
	/* 0x799: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_79e:
	/* 0x79e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7a3:
	/* 0x7a3: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a8:
	/* 0x7a8: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_7aa:
	/* 0x7aa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7af:
	/* 0x7af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b1:
	/* 0x7b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7b3:
	/* 0x7b3: js     1493 <tail_handle_ipv6_from_netdev+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5267ULL;
	}
x86_l_7b9:
	/* 0x7b9: movzx  r13d,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_7bf:
	/* 0x7bf: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_7c3:
	/* 0x7c3: mov    QWORD PTR [rsp+0x78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7c8:
	/* 0x7c8: mov    DWORD PTR [rsp+0x60],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7cc:
	/* 0x7cc: jle    80c <tail_handle_ipv6_from_netdev+0x80c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_80c;
	}
x86_l_7ce:
	/* 0x7ce: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_7d2:
	/* 0x7d2: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_7d7:
	/* 0x7d7: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_7e1:
	/* 0x7e1: je     81b <tail_handle_ipv6_from_netdev+0x81b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_81b;
	}
x86_l_7e3:
	/* 0x7e3: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_7e7:
	/* 0x7e7: jne    83f <tail_handle_ipv6_from_netdev+0x83f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_83f;
	}
x86_l_7e9:
	/* 0x7e9: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_7ee:
	/* 0x7ee: lea    r15d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_7f6:
	/* 0x7f6: jmp    82e <tail_handle_ipv6_from_netdev+0x82e> */
	goto x86_l_82e;
x86_l_7f8:
	/* 0x7f8: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_7fd:
	/* 0x7fd: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_801:
	/* 0x801: je     1498 <tail_handle_ipv6_from_netdev+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5272ULL;
	}
x86_l_807:
	/* 0x807: jmp    ba2 <tail_handle_ipv6_from_netdev+0xba2> */
	goto x86_l_ba2;
x86_l_80c:
	/* 0x80c: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_811:
	/* 0x811: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_81b:
	/* 0x81b: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_820:
	/* 0x820: lea    r15d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_828:
	/* 0x828: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_82c:
	/* 0x82c: je     845 <tail_handle_ipv6_from_netdev+0x845> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_845;
	}
x86_l_82e:
	/* 0x82e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_830:
	/* 0x830: jmp    8be <tail_handle_ipv6_from_netdev+0x8be> */
	goto x86_l_8be;
x86_l_835:
	/* 0x835: mov    eax,0xffffff50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967120ULL);
x86_l_83a:
	/* 0x83a: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_83f:
	/* 0x83f: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_845:
	/* 0x845: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_84e:
	/* 0x84e: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_853:
	/* 0x853: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_858:
	/* 0x858: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_85d:
	/* 0x85d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_85f:
	/* 0x85f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_864:
	/* 0x864: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_866:
	/* 0x866: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_868:
	/* 0x868: js     1493 <tail_handle_ipv6_from_netdev+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5267ULL;
	}
x86_l_86e:
	/* 0x86e: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_872:
	/* 0x872: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_877:
	/* 0x877: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_87b:
	/* 0x87b: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_87e:
	/* 0x87e: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_883:
	/* 0x883: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_88d:
	/* 0x88d: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_890:
	/* 0x890: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_895:
	/* 0x895: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_899:
	/* 0x899: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_8a3:
	/* 0x8a3: or     rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8a6:
	/* 0x8a6: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_8ab:
	/* 0x8ab: cmove  rdi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_8af:
	/* 0x8af: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_8b4:
	/* 0x8b4: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_8be:
	/* 0x8be: movzx  r12d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8c2:
	/* 0x8c2: lea    esi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8c6:
	/* 0x8c6: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_8ca:
	/* 0x8ca: ja     b96 <tail_handle_ipv6_from_netdev+0xb96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b96;
	}
x86_l_8d0:
	/* 0x8d0: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_8d3:
	/* 0x8d3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_8d7:
	/* 0x8d7: jae    964 <tail_handle_ipv6_from_netdev+0x964> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_964;
	}
x86_l_8dd:
	/* 0x8dd: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8e0:
	/* 0x8e0: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8e8:
	/* 0x8e8: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8ed:
	/* 0x8ed: lea    ebp,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_8f1:
	/* 0x8f1: add    ebp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_8f4:
	/* 0x8f4: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8f9:
	/* 0x8f9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8fe:
	/* 0x8fe: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_903:
	/* 0x903: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_905:
	/* 0x905: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_90a:
	/* 0x90a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90c:
	/* 0x90c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_90e:
	/* 0x90e: js     b72 <tail_handle_ipv6_from_netdev+0xb72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b72;
	}
x86_l_914:
	/* 0x914: movzx  r14d,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_91a:
	/* 0x91a: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_91e:
	/* 0x91e: jle    a0f <tail_handle_ipv6_from_netdev+0xa0f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_a0f;
	}
x86_l_924:
	/* 0x924: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_928:
	/* 0x928: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_92d:
	/* 0x92d: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_937:
	/* 0x937: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_93f:
	/* 0x93f: je     a30 <tail_handle_ipv6_from_netdev+0xa30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a30;
	}
x86_l_945:
	/* 0x945: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_948:
	/* 0x948: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_94c:
	/* 0x94c: jne    a3d <tail_handle_ipv6_from_netdev+0xa3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a3d;
	}
x86_l_952:
	/* 0x952: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_957:
	/* 0x957: lea    r15d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_95f:
	/* 0x95f: jmp    ada <tail_handle_ipv6_from_netdev+0xada> */
	goto x86_l_ada;
x86_l_964:
	/* 0x964: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_967:
	/* 0x967: jmp    b81 <tail_handle_ipv6_from_netdev+0xb81> */
	goto x86_l_b81;
x86_l_96c:
	/* 0x96c: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_96e:
	/* 0x96e: jmp    ba2 <tail_handle_ipv6_from_netdev+0xba2> */
	goto x86_l_ba2;
x86_l_973:
	/* 0x973: mov    r13,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_97a:
	/* 0x97a: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_97d:
	/* 0x97d: je     3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1013ULL;
	}
x86_l_983:
	/* 0x983: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_988:
	/* 0x988: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_98b:
	/* 0x98b: cmp    edi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 60ULL);
x86_l_98e:
	/* 0x98e: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_998:
	/* 0x998: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_99d:
	/* 0x99d: ja     679 <tail_handle_ipv6_from_netdev+0x679> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1657ULL;
	}
x86_l_9a3:
	/* 0x9a3: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_9a5:
	/* 0x9a5: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9a9:
	/* 0x9a9: jae    fe4 <tail_handle_ipv6_from_netdev+0xfe4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4068ULL;
	}
x86_l_9af:
	/* 0x9af: lea    ecx,[rsi+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_9b2:
	/* 0x9b2: add    ecx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_9b5:
	/* 0x9b5: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9b7:
	/* 0x9b7: lea    r14d,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9bb:
	/* 0x9bb: add    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_9bf:
	/* 0x9bf: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9c4:
	/* 0x9c4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9c9:
	/* 0x9c9: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_9cb:
	/* 0x9cb: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9ce:
	/* 0x9ce: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_9d1:
	/* 0x9d1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_9d6:
	/* 0x9d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d8:
	/* 0x9d8: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_9de:
	/* 0x9de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9e0:
	/* 0x9e0: js     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1439ULL;
	}
x86_l_9e6:
	/* 0x9e6: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_9e8:
	/* 0x9e8: cmp    ebx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 43ULL);
x86_l_9eb:
	/* 0x9eb: jle    1008 <tail_handle_ipv6_from_netdev+0x1008> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4104ULL;
	}
x86_l_9f1:
	/* 0x9f1: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_9f4:
	/* 0x9f4: mov    r13,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_9fb:
	/* 0x9fb: je     3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1013ULL;
	}
x86_l_a01:
	/* 0xa01: cmp    ecx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 51ULL);
x86_l_a04:
	/* 0xa04: je     47b <tail_handle_ipv6_from_netdev+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1147ULL;
	}
x86_l_a0a:
	/* 0xa0a: jmp    100f <tail_handle_ipv6_from_netdev+0x100f> */
	return 4111ULL;
x86_l_a0f:
	/* 0xa0f: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_a14:
	/* 0xa14: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a19:
	/* 0xa19: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_a23:
	/* 0xa23: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a2b:
	/* 0xa2b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a2e:
	/* 0xa2e: jmp    a42 <tail_handle_ipv6_from_netdev+0xa42> */
	goto x86_l_a42;
x86_l_a30:
	/* 0xa30: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a36:
	/* 0xa36: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a3b:
	/* 0xa3b: jmp    a59 <tail_handle_ipv6_from_netdev+0xa59> */
	goto x86_l_a59;
x86_l_a3d:
	/* 0xa3d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a42:
	/* 0xa42: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_a47:
	/* 0xa47: lea    r15d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_a4f:
	/* 0xa4f: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_a53:
	/* 0xa53: jne    ada <tail_handle_ipv6_from_netdev+0xada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ada;
	}
x86_l_a59:
	/* 0xa59: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_a62:
	/* 0xa62: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a67:
	/* 0xa67: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a6c:
	/* 0xa6c: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a71:
	/* 0xa71: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_a73:
	/* 0xa73: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a78:
	/* 0xa78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7a:
	/* 0xa7a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a7c:
	/* 0xa7c: js     1493 <tail_handle_ipv6_from_netdev+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5267ULL;
	}
x86_l_a82:
	/* 0xa82: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a86:
	/* 0xa86: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_a8b:
	/* 0xa8b: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_a8f:
	/* 0xa8f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_a92:
	/* 0xa92: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_a97:
	/* 0xa97: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_aa1:
	/* 0xaa1: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_aa4:
	/* 0xaa4: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_aa9:
	/* 0xaa9: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_aad:
	/* 0xaad: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_ab7:
	/* 0xab7: or     rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_aba:
	/* 0xaba: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_abf:
	/* 0xabf: cmove  rdi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_ac3:
	/* 0xac3: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_ac8:
	/* 0xac8: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_ad2:
	/* 0xad2: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ada:
	/* 0xada: movzx  r12d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ade:
	/* 0xade: add    esi,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae1:
	/* 0xae1: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_ae5:
	/* 0xae5: ja     b99 <tail_handle_ipv6_from_netdev+0xb99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b99;
	}
x86_l_aeb:
	/* 0xaeb: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_aee:
	/* 0xaee: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_af2:
	/* 0xaf2: jae    b81 <tail_handle_ipv6_from_netdev+0xb81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b81;
	}
x86_l_af8:
	/* 0xaf8: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_afb:
	/* 0xafb: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_afe:
	/* 0xafe: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b03:
	/* 0xb03: lea    ebp,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b06:
	/* 0xb06: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b0b:
	/* 0xb0b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b10:
	/* 0xb10: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b15:
	/* 0xb15: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b17:
	/* 0xb17: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b1c:
	/* 0xb1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1e:
	/* 0xb1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b20:
	/* 0xb20: js     b72 <tail_handle_ipv6_from_netdev+0xb72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_b72;
	}
x86_l_b22:
	/* 0xb22: movzx  r13d,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_b28:
	/* 0xb28: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_b2c:
	/* 0xb2c: jle    fc8 <tail_handle_ipv6_from_netdev+0xfc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4040ULL;
	}
x86_l_b32:
	/* 0xb32: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_b36:
	/* 0xb36: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_b3b:
	/* 0xb3b: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_b45:
	/* 0xb45: je     1030 <tail_handle_ipv6_from_netdev+0x1030> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4144ULL;
	}
x86_l_b4b:
	/* 0xb4b: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_b4e:
	/* 0xb4e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_b51:
	/* 0xb51: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_b55:
	/* 0xb55: jne    103d <tail_handle_ipv6_from_netdev+0x103d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4157ULL;
	}
x86_l_b5b:
	/* 0xb5b: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_b60:
	/* 0xb60: lea    r15d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_b68:
	/* 0xb68: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b6d:
	/* 0xb6d: jmp    10d5 <tail_handle_ipv6_from_netdev+0x10d5> */
	return 4309ULL;
x86_l_b72:
	/* 0xb72: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_b77:
	/* 0xb77: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7c:
	/* 0xb7c: jmp    1498 <tail_handle_ipv6_from_netdev+0x1498> */
	return 5272ULL;
x86_l_b81:
	/* 0xb81: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_b85:
	/* 0xb85: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8a:
	/* 0xb8a: mov    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b8e:
	/* 0xb8e: je     1498 <tail_handle_ipv6_from_netdev+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5272ULL;
	}
x86_l_b94:
	/* 0xb94: jmp    ba2 <tail_handle_ipv6_from_netdev+0xba2> */
	goto x86_l_ba2;
x86_l_b96:
	/* 0xb96: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_b99:
	/* 0xb99: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9e:
	/* 0xb9e: mov    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ba2:
	/* 0xba2: mov    BYTE PTR [rsp+0xc4],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_baa:
	/* 0xbaa: mov    rax,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_bb1:
	/* 0xbb1: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_bb4:
	/* 0xbb4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb9:
	/* 0xbb9: mov    rcx,QWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bbd:
	/* 0xbbd: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_bc5:
	/* 0xbc5: mov    rcx,QWORD PTR [rdx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bc9:
	/* 0xbc9: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_bd1:
	/* 0xbd1: mov    rcx,QWORD PTR [rdx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bd5:
	/* 0xbd5: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_bdd:
	/* 0xbdd: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_be1:
	/* 0xbe1: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_be9:
	/* 0xbe9: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_bec:
	/* 0xbec: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_bf0:
	/* 0xbf0: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bf5:
	/* 0xbf5: je     c0d <tail_handle_ipv6_from_netdev+0xc0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c0d;
	}
x86_l_bf7:
	/* 0xbf7: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bfb:
	/* 0xbfb: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_bfe:
	/* 0xbfe: je     2998 <tail_handle_ipv6_from_netdev+0x2998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10648ULL;
	}
x86_l_c04:
	/* 0xc04: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_c07:
	/* 0xc07: jne    ca3 <tail_handle_ipv6_from_netdev+0xca3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ca3;
	}
x86_l_c0d:
	/* 0xc0d: mov    DWORD PTR [rsp+0x60],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c11:
	/* 0xc11: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c13:
	/* 0xc13: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_c1d:
	/* 0xc1d: lea    r14,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c25:
	/* 0xc25: mov    rax,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_c2c:
	/* 0xc2c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2f:
	/* 0xc2f: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c37:
	/* 0xc37: je     e83 <tail_handle_ipv6_from_netdev+0xe83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3715ULL;
	}
x86_l_c3d:
	/* 0xc3d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c42:
	/* 0xc42: mov    rbx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c45:
	/* 0xc45: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c4c:
	/* 0xc4c: mov    DWORD PTR [rdx],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c4e:
	/* 0xc4e: mov    rax,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_64);
x86_l_c51:
	/* 0xc51: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_c55:
	/* 0xc55: mov    BYTE PTR [rdx+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c58:
	/* 0xc58: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_c5b:
	/* 0xc5b: test   rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_c5e:
	/* 0xc5e: mov    r15,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_c65:
	/* 0xc65: jne    320a <tail_handle_ipv6_from_netdev+0x320a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12810ULL;
	}
x86_l_c6b:
	/* 0xc6b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_c70:
	/* 0xc70: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_c73:
	/* 0xc73: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c76:
	/* 0xc76: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_c7b:
	/* 0xc7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7d:
	/* 0xc7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c7f:
	/* 0xc7f: js     fae <tail_handle_ipv6_from_netdev+0xfae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4014ULL;
	}
x86_l_c85:
	/* 0xc85: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_c88:
	/* 0xc88: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_c8b:
	/* 0xc8b: bt     r13,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 40ULL);
x86_l_c90:
	/* 0xc90: jb     3237 <tail_handle_ipv6_from_netdev+0x3237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 12855ULL;
	}
x86_l_c96:
	/* 0xc96: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c9b:
	/* 0xc9b: mov    QWORD PTR [rax],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9e:
	/* 0xc9e: jmp    eb3 <tail_handle_ipv6_from_netdev+0xeb3> */
	return 3763ULL;
x86_l_ca3:
	/* 0xca3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca5:
	/* 0xca5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca7:
	/* 0xca7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ca9:
	/* 0xca9: sets   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_S);
x86_l_cac:
	/* 0xcac: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_caf:
	/* 0xcaf: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_cb2:
	/* 0xcb2: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_cb4:
	/* 0xcb4: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_cba:
	/* 0xcba: mov    r13,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_cc1:
	/* 0xcc1: mov    edx,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cc5:
	/* 0xcc5: jne    f87 <tail_handle_ipv6_from_netdev+0xf87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3975ULL;
	}
x86_l_ccb:
	/* 0xccb: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_ccd:
	/* 0xccd: jne    f87 <tail_handle_ipv6_from_netdev+0xf87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3975ULL;
	}
x86_l_cd3:
	/* 0xcd3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd5:
	/* 0xcd5: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_cd7:
	/* 0xcd7: jne    31dd <tail_handle_ipv6_from_netdev+0x31dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12765ULL;
	}
x86_l_cdd:
	/* 0xcdd: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_ce0:
	/* 0xce0: mov    rdi,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer6)));
x86_l_ce7:
	/* 0xce7: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_cef:
	/* 0xcef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cf4:
	/* 0xcf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf6:
	/* 0xcf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf9:
	/* 0xcf9: je     e78 <tail_handle_ipv6_from_netdev+0xe78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3704ULL;
	}
x86_l_cff:
	/* 0xcff: mov    ecx,DWORD PTR [rbp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d02:
	/* 0xd02: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d06:
	/* 0xd06: and    ecx,0xffffffef */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967279ULL);
x86_l_d09:
	/* 0xd09: mov    DWORD PTR [rbp+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d0c:
	/* 0xd0c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d0e:
	/* 0xd0e: test   DWORD PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691856ULL);
x86_l_d16:
	/* 0xd16: jne    31dd <tail_handle_ipv6_from_netdev+0x31dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12765ULL;
	}
x86_l_d1c:
	/* 0xd1c: movzx  ecx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d1f:
	/* 0xd1f: mov    r13d,DWORD PTR [rbp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_d23:
	/* 0xd23: mov    edx,DWORD PTR [rbp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d26:
	/* 0xd26: lea    rsi,[rcx+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_d2a:
	/* 0xd2a: add    rsi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_d2e:
	/* 0xd2e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d31:
	/* 0xd31: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_d34:
	/* 0xd34: ja     5a7 <tail_handle_ipv6_from_netdev+0x5a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1447ULL;
	}
x86_l_d3a:
	/* 0xd3a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d3f:
	/* 0xd3f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_d42:
	/* 0xd42: add    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d45:
	/* 0xd45: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d49:
	/* 0xd49: mov    QWORD PTR [r15+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4d:
	/* 0xd4d: mov    rax,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d51:
	/* 0xd51: mov    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d54:
	/* 0xd54: mov    QWORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_d5d:
	/* 0xd5d: mov    DWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_d65:
	/* 0xd65: mov    QWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_d6e:
	/* 0xd6e: mov    DWORD PTR [rsp+0x28],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798692000ULL);
x86_l_d76:
	/* 0xd76: mov    BYTE PTR [rsp+0x2f],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 201863462914ULL);
x86_l_d7b:
	/* 0xd7b: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7e:
	/* 0xd7e: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d82:
	/* 0xd82: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d87:
	/* 0xd87: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d8c:
	/* 0xd8c: mov    rdi,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_d93:
	/* 0xd93: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d98:
	/* 0xd98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d9d:
	/* 0xd9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9f:
	/* 0xd9f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da1:
	/* 0xda1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_da4:
	/* 0xda4: je     31dd <tail_handle_ipv6_from_netdev+0x31dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12765ULL;
	}
x86_l_daa:
	/* 0xdaa: cmp    DWORD PTR [rax],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_dad:
	/* 0xdad: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db2:
	/* 0xdb2: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_dbc:
	/* 0xdbc: jne    31dd <tail_handle_ipv6_from_netdev+0x31dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12765ULL;
	}
x86_l_dc2:
	/* 0xdc2: movzx  r14d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_dc7:
	/* 0xdc7: mov    BYTE PTR [r15+0x24],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dcb:
	/* 0xdcb: mov    rcx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dcf:
	/* 0xdcf: mov    QWORD PTR [r15+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd3:
	/* 0xdd3: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dd7:
	/* 0xdd7: mov    QWORD PTR [r15+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ddb:
	/* 0xddb: movzx  ecx,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_dde:
	/* 0xdde: mov    QWORD PTR [r15+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_de6:
	/* 0xde6: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_deb:
	/* 0xdeb: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_def:
	/* 0xdef: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_df4:
	/* 0xdf4: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_df9:
	/* 0xdf9: ja     2350 <tail_handle_ipv6_from_netdev+0x2350> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9040ULL;
	}
x86_l_dff:
	/* 0xdff: mov    DWORD PTR [rsp+0x78],0xffffff64 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 519691042660ULL);
x86_l_e07:
	/* 0xe07: bt     rdx,r14 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e0b:
	/* 0xe0b: jae    142e <tail_handle_ipv6_from_netdev+0x142e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5166ULL;
	}
x86_l_e11:
	/* 0xe11: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e16:
	/* 0xe16: lea    ebp,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e19:
	/* 0xe19: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
	return 3614ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3614ULL: goto x86_l_e1e;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3626ULL: goto x86_l_e2a;
	case 3631ULL: goto x86_l_e2f;
	case 3633ULL: goto x86_l_e31;
	case 3635ULL: goto x86_l_e33;
	case 3641ULL: goto x86_l_e39;
	case 3646ULL: goto x86_l_e3e;
	case 3650ULL: goto x86_l_e42;
	case 3656ULL: goto x86_l_e48;
	case 3660ULL: goto x86_l_e4c;
	case 3670ULL: goto x86_l_e56;
	case 3676ULL: goto x86_l_e5c;
	case 3680ULL: goto x86_l_e60;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3699ULL: goto x86_l_e73;
	case 3704ULL: goto x86_l_e78;
	case 3710ULL: goto x86_l_e7e;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3725ULL: goto x86_l_e8d;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3739ULL: goto x86_l_e9b;
	case 3742ULL: goto x86_l_e9e;
	case 3745ULL: goto x86_l_ea1;
	case 3748ULL: goto x86_l_ea4;
	case 3753ULL: goto x86_l_ea9;
	case 3755ULL: goto x86_l_eab;
	case 3757ULL: goto x86_l_ead;
	case 3763ULL: goto x86_l_eb3;
	case 3771ULL: goto x86_l_ebb;
	case 3778ULL: goto x86_l_ec2;
	case 3786ULL: goto x86_l_eca;
	case 3794ULL: goto x86_l_ed2;
	case 3802ULL: goto x86_l_eda;
	case 3810ULL: goto x86_l_ee2;
	case 3818ULL: goto x86_l_eea;
	case 3826ULL: goto x86_l_ef2;
	case 3836ULL: goto x86_l_efc;
	case 3844ULL: goto x86_l_f04;
	case 3851ULL: goto x86_l_f0b;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3866ULL: goto x86_l_f1a;
	case 3869ULL: goto x86_l_f1d;
	case 3871ULL: goto x86_l_f1f;
	case 3879ULL: goto x86_l_f27;
	case 3888ULL: goto x86_l_f30;
	case 3898ULL: goto x86_l_f3a;
	case 3906ULL: goto x86_l_f42;
	case 3913ULL: goto x86_l_f49;
	case 3921ULL: goto x86_l_f51;
	case 3923ULL: goto x86_l_f53;
	case 3926ULL: goto x86_l_f56;
	case 3932ULL: goto x86_l_f5c;
	case 3935ULL: goto x86_l_f5f;
	case 3944ULL: goto x86_l_f68;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3960ULL: goto x86_l_f78;
	case 3962ULL: goto x86_l_f7a;
	case 3965ULL: goto x86_l_f7d;
	case 3970ULL: goto x86_l_f82;
	case 3975ULL: goto x86_l_f87;
	case 3977ULL: goto x86_l_f89;
	case 3983ULL: goto x86_l_f8f;
	case 3985ULL: goto x86_l_f91;
	case 3988ULL: goto x86_l_f94;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4000ULL: goto x86_l_fa0;
	case 4006ULL: goto x86_l_fa6;
	case 4009ULL: goto x86_l_fa9;
	case 4014ULL: goto x86_l_fae;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4040ULL: goto x86_l_fc8;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4060ULL: goto x86_l_fdc;
	case 4063ULL: goto x86_l_fdf;
	case 4066ULL: goto x86_l_fe2;
	case 4068ULL: goto x86_l_fe4;
	case 4072ULL: goto x86_l_fe8;
	case 4078ULL: goto x86_l_fee;
	case 4083ULL: goto x86_l_ff3;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4099ULL: goto x86_l_1003;
	case 4104ULL: goto x86_l_1008;
	case 4111ULL: goto x86_l_100f;
	case 4114ULL: goto x86_l_1012;
	case 4120ULL: goto x86_l_1018;
	case 4125ULL: goto x86_l_101d;
	case 4128ULL: goto x86_l_1020;
	case 4130ULL: goto x86_l_1022;
	case 4133ULL: goto x86_l_1025;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4150ULL: goto x86_l_1036;
	case 4155ULL: goto x86_l_103b;
	case 4157ULL: goto x86_l_103d;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4185ULL: goto x86_l_1059;
	case 4194ULL: goto x86_l_1062;
	case 4199ULL: goto x86_l_1067;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4211ULL: goto x86_l_1073;
	case 4216ULL: goto x86_l_1078;
	case 4218ULL: goto x86_l_107a;
	case 4220ULL: goto x86_l_107c;
	case 4226ULL: goto x86_l_1082;
	case 4230ULL: goto x86_l_1086;
	case 4235ULL: goto x86_l_108b;
	case 4239ULL: goto x86_l_108f;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4257ULL: goto x86_l_10a1;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4269ULL: goto x86_l_10ad;
	case 4279ULL: goto x86_l_10b7;
	case 4282ULL: goto x86_l_10ba;
	case 4287ULL: goto x86_l_10bf;
	case 4291ULL: goto x86_l_10c3;
	case 4296ULL: goto x86_l_10c8;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4313ULL: goto x86_l_10d9;
	case 4316ULL: goto x86_l_10dc;
	case 4319ULL: goto x86_l_10df;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4331ULL: goto x86_l_10eb;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4353ULL: goto x86_l_1101;
	case 4358ULL: goto x86_l_1106;
	case 4363ULL: goto x86_l_110b;
	case 4366ULL: goto x86_l_110e;
	case 4371ULL: goto x86_l_1113;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4388ULL: goto x86_l_1124;
	case 4391ULL: goto x86_l_1127;
	case 4393ULL: goto x86_l_1129;
	case 4396ULL: goto x86_l_112c;
	case 4402ULL: goto x86_l_1132;
	case 4405ULL: goto x86_l_1135;
	case 4411ULL: goto x86_l_113b;
	case 4415ULL: goto x86_l_113f;
	case 4420ULL: goto x86_l_1144;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4434ULL: goto x86_l_1152;
	case 4439ULL: goto x86_l_1157;
	case 4444ULL: goto x86_l_115c;
	case 4448ULL: goto x86_l_1160;
	case 4451ULL: goto x86_l_1163;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4462ULL: goto x86_l_116e;
	case 4470ULL: goto x86_l_1176;
	case 4478ULL: goto x86_l_117e;
	case 4486ULL: goto x86_l_1186;
	case 4491ULL: goto x86_l_118b;
	case 4498ULL: goto x86_l_1192;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4515ULL: goto x86_l_11a3;
	case 4520ULL: goto x86_l_11a8;
	case 4525ULL: goto x86_l_11ad;
	case 4527ULL: goto x86_l_11af;
	case 4530ULL: goto x86_l_11b2;
	case 4533ULL: goto x86_l_11b5;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4543ULL: goto x86_l_11bf;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4551ULL: goto x86_l_11c7;
	case 4557ULL: goto x86_l_11cd;
	case 4561ULL: goto x86_l_11d1;
	case 4566ULL: goto x86_l_11d6;
	case 4568ULL: goto x86_l_11d8;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4589ULL: goto x86_l_11ed;
	case 4592ULL: goto x86_l_11f0;
	case 4595ULL: goto x86_l_11f3;
	case 4601ULL: goto x86_l_11f9;
	case 4604ULL: goto x86_l_11fc;
	case 4611ULL: goto x86_l_1203;
	case 4613ULL: goto x86_l_1205;
	case 4620ULL: goto x86_l_120c;
	case 4623ULL: goto x86_l_120f;
	case 4625ULL: goto x86_l_1211;
	case 4633ULL: goto x86_l_1219;
	case 4640ULL: goto x86_l_1220;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4652ULL: goto x86_l_122c;
	case 4659ULL: goto x86_l_1233;
	case 4662ULL: goto x86_l_1236;
	case 4664ULL: goto x86_l_1238;
	case 4671ULL: goto x86_l_123f;
	case 4674ULL: goto x86_l_1242;
	case 4680ULL: goto x86_l_1248;
	case 4687ULL: goto x86_l_124f;
	case 4690ULL: goto x86_l_1252;
	case 4695ULL: goto x86_l_1257;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4713ULL: goto x86_l_1269;
	case 4717ULL: goto x86_l_126d;
	case 4724ULL: goto x86_l_1274;
	case 4727ULL: goto x86_l_1277;
	case 4731ULL: goto x86_l_127b;
	case 4738ULL: goto x86_l_1282;
	case 4741ULL: goto x86_l_1285;
	case 4744ULL: goto x86_l_1288;
	case 4749ULL: goto x86_l_128d;
	case 4754ULL: goto x86_l_1292;
	case 4756ULL: goto x86_l_1294;
	case 4761ULL: goto x86_l_1299;
	case 4763ULL: goto x86_l_129b;
	case 4765ULL: goto x86_l_129d;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4784ULL: goto x86_l_12b0;
	case 4787ULL: goto x86_l_12b3;
	case 4791ULL: goto x86_l_12b7;
	case 4799ULL: goto x86_l_12bf;
	case 4806ULL: goto x86_l_12c6;
	case 4811ULL: goto x86_l_12cb;
	case 4816ULL: goto x86_l_12d0;
	case 4818ULL: goto x86_l_12d2;
	case 4823ULL: goto x86_l_12d7;
	case 4828ULL: goto x86_l_12dc;
	case 4831ULL: goto x86_l_12df;
	case 4835ULL: goto x86_l_12e3;
	case 4841ULL: goto x86_l_12e9;
	case 4846ULL: goto x86_l_12ee;
	case 4854ULL: goto x86_l_12f6;
	case 4863ULL: goto x86_l_12ff;
	case 4871ULL: goto x86_l_1307;
	case 4876ULL: goto x86_l_130c;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4897ULL: goto x86_l_1321;
	case 4902ULL: goto x86_l_1326;
	case 4910ULL: goto x86_l_132e;
	case 4918ULL: goto x86_l_1336;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4936ULL: goto x86_l_1348;
	case 4942ULL: goto x86_l_134e;
	case 4953ULL: goto x86_l_1359;
	case 4961ULL: goto x86_l_1361;
	case 4964ULL: goto x86_l_1364;
	case 4972ULL: goto x86_l_136c;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4985ULL: goto x86_l_1379;
	case 4987ULL: goto x86_l_137b;
	case 4989ULL: goto x86_l_137d;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5025ULL: goto x86_l_13a1;
	case 5030ULL: goto x86_l_13a6;
	case 5035ULL: goto x86_l_13ab;
	case 5040ULL: goto x86_l_13b0;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5052ULL: goto x86_l_13bc;
	case 5060ULL: goto x86_l_13c4;
	case 5066ULL: goto x86_l_13ca;
	case 5071ULL: goto x86_l_13cf;
	case 5077ULL: goto x86_l_13d5;
	case 5084ULL: goto x86_l_13dc;
	case 5089ULL: goto x86_l_13e1;
	case 5099ULL: goto x86_l_13eb;
	case 5107ULL: goto x86_l_13f3;
	case 5111ULL: goto x86_l_13f7;
	case 5114ULL: goto x86_l_13fa;
	case 5120ULL: goto x86_l_1400;
	case 5127ULL: goto x86_l_1407;
	case 5132ULL: goto x86_l_140c;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5166ULL: goto x86_l_142e;
	case 5170ULL: goto x86_l_1432;
	case 5176ULL: goto x86_l_1438;
	case 5181ULL: goto x86_l_143d;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5204ULL: goto x86_l_1454;
	case 5208ULL: goto x86_l_1458;
	case 5214ULL: goto x86_l_145e;
	case 5219ULL: goto x86_l_1463;
	case 5224ULL: goto x86_l_1468;
	case 5233ULL: goto x86_l_1471;
	case 5238ULL: goto x86_l_1476;
	case 5243ULL: goto x86_l_147b;
	case 5246ULL: goto x86_l_147e;
	case 5249ULL: goto x86_l_1481;
	case 5254ULL: goto x86_l_1486;
	case 5256ULL: goto x86_l_1488;
	case 5258ULL: goto x86_l_148a;
	case 5260ULL: goto x86_l_148c;
	case 5265ULL: goto x86_l_1491;
	case 5267ULL: goto x86_l_1493;
	case 5272ULL: goto x86_l_1498;
	case 5275ULL: goto x86_l_149b;
	case 5280ULL: goto x86_l_14a0;
	case 5285ULL: goto x86_l_14a5;
	case 5292ULL: goto x86_l_14ac;
	case 5297ULL: goto x86_l_14b1;
	case 5305ULL: goto x86_l_14b9;
	case 5312ULL: goto x86_l_14c0;
	case 5320ULL: goto x86_l_14c8;
	case 5328ULL: goto x86_l_14d0;
	case 5336ULL: goto x86_l_14d8;
	case 5344ULL: goto x86_l_14e0;
	case 5349ULL: goto x86_l_14e5;
	case 5353ULL: goto x86_l_14e9;
	case 5358ULL: goto x86_l_14ee;
	case 5366ULL: goto x86_l_14f6;
	case 5374ULL: goto x86_l_14fe;
	case 5377ULL: goto x86_l_1501;
	case 5384ULL: goto x86_l_1508;
	case 5387ULL: goto x86_l_150b;
	case 5393ULL: goto x86_l_1511;
	case 5396ULL: goto x86_l_1514;
	case 5402ULL: goto x86_l_151a;
	case 5405ULL: goto x86_l_151d;
	case 5408ULL: goto x86_l_1520;
	case 5417ULL: goto x86_l_1529;
	case 5426ULL: goto x86_l_1532;
	case 5436ULL: goto x86_l_153c;
	case 5442ULL: goto x86_l_1542;
	case 5450ULL: goto x86_l_154a;
	case 5457ULL: goto x86_l_1551;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5472ULL: goto x86_l_1560;
	case 5475ULL: goto x86_l_1563;
	case 5481ULL: goto x86_l_1569;
	case 5484ULL: goto x86_l_156c;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5536ULL: goto x86_l_15a0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e1e:
	/* 0xe1e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e23:
	/* 0xe23: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e28:
	/* 0xe28: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_e2a:
	/* 0xe2a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e2f:
	/* 0xe2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e31:
	/* 0xe31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e33:
	/* 0xe33: js     140c <tail_handle_ipv6_from_netdev+0x140c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_140c;
	}
x86_l_e39:
	/* 0xe39: movzx  edx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_e3e:
	/* 0xe3e: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_e42:
	/* 0xe42: jle    143d <tail_handle_ipv6_from_netdev+0x143d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_143d;
	}
x86_l_e48:
	/* 0xe48: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_e4c:
	/* 0xe4c: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_e56:
	/* 0xe56: je     1447 <tail_handle_ipv6_from_netdev+0x1447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1447;
	}
x86_l_e5c:
	/* 0xe5c: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_e60:
	/* 0xe60: jne    157d <tail_handle_ipv6_from_netdev+0x157d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_157d;
	}
x86_l_e66:
	/* 0xe66: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_e6b:
	/* 0xe6b: lea    r15d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_e73:
	/* 0xe73: jmp    1606 <tail_handle_ipv6_from_netdev+0x1606> */
	return 5638ULL;
x86_l_e78:
	/* 0xe78: mov    r15d,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967112ULL);
x86_l_e7e:
	/* 0xe7e: jmp    5a4 <tail_handle_ipv6_from_netdev+0x5a4> */
	return 1444ULL;
x86_l_e83:
	/* 0xe83: test   rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_e86:
	/* 0xe86: mov    r15,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_e8d:
	/* 0xe8d: jne    32a9 <tail_handle_ipv6_from_netdev+0x32a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12969ULL;
	}
x86_l_e93:
	/* 0xe93: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_e96:
	/* 0xe96: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e9b:
	/* 0xe9b: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_e9e:
	/* 0xe9e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_ea1:
	/* 0xea1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ea4:
	/* 0xea4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ea9:
	/* 0xea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eab:
	/* 0xeab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ead:
	/* 0xead: js     ff3 <tail_handle_ipv6_from_netdev+0xff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ff3;
	}
x86_l_eb3:
	/* 0xeb3: movzx  eax,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_ebb:
	/* 0xebb: mov    BYTE PTR [rsp+0xdc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_ec2:
	/* 0xec2: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_eca:
	/* 0xeca: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ed2:
	/* 0xed2: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_eda:
	/* 0xeda: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_ee2:
	/* 0xee2: movzx  eax,WORD PTR [rsp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_eea:
	/* 0xeea: mov    WORD PTR [rsp+0xd8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ef2:
	/* 0xef2: mov    WORD PTR [rsp+0xda],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 936302870528ULL);
x86_l_efc:
	/* 0xefc: mov    BYTE PTR [rsp+0xdd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 949187772416ULL);
x86_l_f04:
	/* 0xf04: mov    rdi,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_f0b:
	/* 0xf0b: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_f13:
	/* 0xf13: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_f18:
	/* 0xf18: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_f1a:
	/* 0xf1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f1d:
	/* 0xf1d: jne    f5c <tail_handle_ipv6_from_netdev+0xf5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f5c;
	}
x86_l_f1f:
	/* 0xf1f: movzx  ebp,BYTE PTR [rsp+0xdc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 220ULL);
x86_l_f27:
	/* 0xf27: movzx  r14d,WORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 216ULL);
x86_l_f30:
	/* 0xf30: mov    WORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_f3a:
	/* 0xf3a: mov    BYTE PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_f42:
	/* 0xf42: mov    rdi,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_f49:
	/* 0xf49: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_f51:
	/* 0xf51: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_f53:
	/* 0xf53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f56:
	/* 0xf56: je     12ee <tail_handle_ipv6_from_netdev+0x12ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ee;
	}
x86_l_f5c:
	/* 0xf5c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5f:
	/* 0xf5f: cmp    WORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_f68:
	/* 0xf68: mov    r15d,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967138ULL);
x86_l_f6e:
	/* 0xf6e: jne    f9c <tail_handle_ipv6_from_netdev+0xf9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f9c;
	}
x86_l_f70:
	/* 0xf70: cmp    BYTE PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_f78:
	/* 0xf78: jne    f9c <tail_handle_ipv6_from_netdev+0xf9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f9c;
	}
x86_l_f7a:
	/* 0xf7a: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_f7d:
	/* 0xf7d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f82:
	/* 0xf82: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
x86_l_f87:
	/* 0xf87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f89:
	/* 0xf89: je     101d <tail_handle_ipv6_from_netdev+0x101d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_101d;
	}
x86_l_f8f:
	/* 0xf8f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f91:
	/* 0xf91: shr    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 31ULL);
x86_l_f94:
	/* 0xf94: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f97:
	/* 0xf97: jmp    3c66 <tail_handle_ipv6_from_netdev+0x3c66> */
	return 15462ULL;
x86_l_f9c:
	/* 0xf9c: cmp    BYTE PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fa0:
	/* 0xfa0: js     1157 <tail_handle_ipv6_from_netdev+0x1157> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1157;
	}
x86_l_fa6:
	/* 0xfa6: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_fa9:
	/* 0xfa9: jmp    11cd <tail_handle_ipv6_from_netdev+0x11cd> */
	goto x86_l_11cd;
x86_l_fae:
	/* 0xfae: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_fb3:
	/* 0xfb3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fb8:
	/* 0xfb8: mov    QWORD PTR [rcx],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbb:
	/* 0xfbb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbe:
	/* 0xfbe: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc3:
	/* 0xfc3: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_fc8:
	/* 0xfc8: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_fcd:
	/* 0xfcd: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd2:
	/* 0xfd2: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_fdc:
	/* 0xfdc: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_fdf:
	/* 0xfdf: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fe2:
	/* 0xfe2: jmp    1042 <tail_handle_ipv6_from_netdev+0x1042> */
	goto x86_l_1042;
x86_l_fe4:
	/* 0xfe4: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_fe8:
	/* 0xfe8: je     59f <tail_handle_ipv6_from_netdev+0x59f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1439ULL;
	}
x86_l_fee:
	/* 0xfee: jmp    679 <tail_handle_ipv6_from_netdev+0x679> */
	return 1657ULL;
x86_l_ff3:
	/* 0xff3: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_ff8:
	/* 0xff8: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1000:
	/* 0x1000: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1003:
	/* 0x1003: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_1008:
	/* 0x1008: mov    r13,QWORD PTR [rip+0x1bdca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_100f:
	/* 0x100f: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_1012:
	/* 0x1012: je     3f5 <tail_handle_ipv6_from_netdev+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1013ULL;
	}
x86_l_1018:
	/* 0x1018: jmp    47b <tail_handle_ipv6_from_netdev+0x47b> */
	return 1147ULL;
x86_l_101d:
	/* 0x101d: and    cl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1020:
	/* 0x1020: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1022:
	/* 0x1022: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_1025:
	/* 0x1025: jne    660 <tail_handle_ipv6_from_netdev+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1632ULL;
	}
x86_l_102b:
	/* 0x102b: jmp    31e0 <tail_handle_ipv6_from_netdev+0x31e0> */
	return 12768ULL;
x86_l_1030:
	/* 0x1030: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1036:
	/* 0x1036: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103b:
	/* 0x103b: jmp    1059 <tail_handle_ipv6_from_netdev+0x1059> */
	goto x86_l_1059;
x86_l_103d:
	/* 0x103d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1042:
	/* 0x1042: movzx  ecx,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_1047:
	/* 0x1047: lea    r15d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_104f:
	/* 0x104f: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_1053:
	/* 0x1053: jne    10d5 <tail_handle_ipv6_from_netdev+0x10d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10d5;
	}
x86_l_1059:
	/* 0x1059: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1062:
	/* 0x1062: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1067:
	/* 0x1067: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_106c:
	/* 0x106c: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1071:
	/* 0x1071: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1073:
	/* 0x1073: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1078:
	/* 0x1078: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_107a:
	/* 0x107a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_107c:
	/* 0x107c: js     1493 <tail_handle_ipv6_from_netdev+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1493;
	}
x86_l_1082:
	/* 0x1082: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1086:
	/* 0x1086: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_108b:
	/* 0x108b: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_108f:
	/* 0x108f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1092:
	/* 0x1092: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_1097:
	/* 0x1097: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_10a1:
	/* 0x10a1: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10a4:
	/* 0x10a4: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_10a9:
	/* 0x10a9: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_10ad:
	/* 0x10ad: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_10b7:
	/* 0x10b7: or     rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_10ba:
	/* 0x10ba: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_10bf:
	/* 0x10bf: cmove  rdi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_10c3:
	/* 0x10c3: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_10c8:
	/* 0x10c8: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_10d2:
	/* 0x10d2: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_10d5:
	/* 0x10d5: movzx  ebp,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_10d9:
	/* 0x10d9: add    esi,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10dc:
	/* 0x10dc: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_10df:
	/* 0x10df: ja     1575 <tail_handle_ipv6_from_netdev+0x1575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1575;
	}
x86_l_10e5:
	/* 0x10e5: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_10e7:
	/* 0x10e7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_10eb:
	/* 0x10eb: mov    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10ef:
	/* 0x10ef: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10f4:
	/* 0x10f4: jae    12dc <tail_handle_ipv6_from_netdev+0x12dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_12dc;
	}
x86_l_10fa:
	/* 0x10fa: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10fc:
	/* 0x10fc: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1101:
	/* 0x1101: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1106:
	/* 0x1106: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_110b:
	/* 0x110b: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_110e:
	/* 0x110e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1113:
	/* 0x1113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1115:
	/* 0x1115: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1117:
	/* 0x1117: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_111c:
	/* 0x111c: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_111e:
	/* 0x111e: js     1498 <tail_handle_ipv6_from_netdev+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1498;
	}
x86_l_1124:
	/* 0x1124: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1127:
	/* 0x1127: jle    113b <tail_handle_ipv6_from_netdev+0x113b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_113b;
	}
x86_l_1129:
	/* 0x1129: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_112c:
	/* 0x112c: je     1463 <tail_handle_ipv6_from_netdev+0x1463> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1463;
	}
x86_l_1132:
	/* 0x1132: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1135:
	/* 0x1135: je     148c <tail_handle_ipv6_from_netdev+0x148c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148c;
	}
x86_l_113b:
	/* 0x113b: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_113f:
	/* 0x113f: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1144:
	/* 0x1144: je     1468 <tail_handle_ipv6_from_netdev+0x1468> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1468;
	}
x86_l_114a:
	/* 0x114a: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_114f:
	/* 0x114f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1152:
	/* 0x1152: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_1157:
	/* 0x1157: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_115c:
	/* 0x115c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1160:
	/* 0x1160: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1163:
	/* 0x1163: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1167:
	/* 0x1167: mov    rcx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116a:
	/* 0x116a: mov    rdx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_116e:
	/* 0x116e: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1176:
	/* 0x1176: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_117e:
	/* 0x117e: mov    DWORD PTR [rsp+0x28],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798692000ULL);
x86_l_1186:
	/* 0x1186: mov    WORD PTR [rsp+0x2c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_118b:
	/* 0x118b: mov    WORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_1192:
	/* 0x1192: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1197:
	/* 0x1197: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_119c:
	/* 0x119c: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_source_range)));
x86_l_11a3:
	/* 0x11a3: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11a8:
	/* 0x11a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11ad:
	/* 0x11ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11af:
	/* 0x11af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b2:
	/* 0x11b2: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_11b5:
	/* 0x11b5: movzx  ecx,BYTE PTR [rbx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_11b9:
	/* 0x11b9: and    cl,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 64ULL);
x86_l_11bc:
	/* 0x11bc: shr    cl,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHR, 6ULL);
x86_l_11bf:
	/* 0x11bf: cmp    al,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_8);
x86_l_11c1:
	/* 0x11c1: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_11c4:
	/* 0x11c4: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_11c7:
	/* 0x11c7: je     141e <tail_handle_ipv6_from_netdev+0x141e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_141e;
	}
x86_l_11cd:
	/* 0x11cd: test   BYTE PTR [rax+0x8],0x40 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_11d1:
	/* 0x11d1: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d6:
	/* 0x11d6: jne    11e3 <tail_handle_ipv6_from_netdev+0x11e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11e3;
	}
x86_l_11d8:
	/* 0x11d8: mov    r15d,0xffffff52 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967122ULL);
x86_l_11de:
	/* 0x11de: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
x86_l_11e3:
	/* 0x11e3: test   BYTE PTR [rax+0x9],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705668ULL);
x86_l_11e7:
	/* 0x11e7: je     13e1 <tail_handle_ipv6_from_netdev+0x13e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e1;
	}
x86_l_11ed:
	/* 0x11ed: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f0:
	/* 0x11f0: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_11f3:
	/* 0x11f3: je     13e1 <tail_handle_ipv6_from_netdev+0x13e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e1;
	}
x86_l_11f9:
	/* 0x11f9: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_11fc:
	/* 0x11fc: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_1203:
	/* 0x1203: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1205:
	/* 0x1205: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_120c:
	/* 0x120c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120f:
	/* 0x120f: je     122c <tail_handle_ipv6_from_netdev+0x122c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_122c;
	}
x86_l_1211:
	/* 0x1211: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1219:
	/* 0x1219: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_1220:
	/* 0x1220: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1225:
	/* 0x1225: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_122a:
	/* 0x122a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122c:
	/* 0x122c: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_1233:
	/* 0x1233: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1236:
	/* 0x1236: jne    1248 <tail_handle_ipv6_from_netdev+0x1248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1248;
	}
x86_l_1238:
	/* 0x1238: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_proxy_redirect_via_cilium_net)));
x86_l_123f:
	/* 0x123f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1242:
	/* 0x1242: je     1c59 <tail_handle_ipv6_from_netdev+0x1c59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7257ULL;
	}
x86_l_1248:
	/* 0x1248: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_124f:
	/* 0x124f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1252:
	/* 0x1252: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1257:
	/* 0x1257: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_125e:
	/* 0x125e: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1261:
	/* 0x1261: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1269:
	/* 0x1269: shl    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_126d:
	/* 0x126d: or     r15d,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_1274:
	/* 0x1274: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1277:
	/* 0x1277: mov    DWORD PTR [r14+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_127b:
	/* 0x127b: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1282:
	/* 0x1282: movzx  ebx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1285:
	/* 0x1285: lea    ebp,[rbx+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_1288:
	/* 0x1288: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128d:
	/* 0x128d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1292:
	/* 0x1292: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1294:
	/* 0x1294: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1299:
	/* 0x1299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129b:
	/* 0x129b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_129d:
	/* 0x129d: js     191b <tail_handle_ipv6_from_netdev+0x191b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6427ULL;
	}
x86_l_12a3:
	/* 0x12a3: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_12a8:
	/* 0x12a8: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_12aa:
	/* 0x12aa: jae    1925 <tail_handle_ipv6_from_netdev+0x1925> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 6437ULL;
	}
x86_l_12b0:
	/* 0x12b0: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_12b3:
	/* 0x12b3: mov    DWORD PTR [r14+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b7:
	/* 0x12b7: mov    DWORD PTR [r14+0x34],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299394ULL);
x86_l_12bf:
	/* 0x12bf: mov    rsi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_12c6:
	/* 0x12c6: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_12cb:
	/* 0x12cb: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_12d0:
	/* 0x12d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d2:
	/* 0x12d2: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_12d7:
	/* 0x12d7: jmp    1c72 <tail_handle_ipv6_from_netdev+0x1c72> */
	return 7282ULL;
x86_l_12dc:
	/* 0x12dc: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_12df:
	/* 0x12df: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_12e3:
	/* 0x12e3: je     1498 <tail_handle_ipv6_from_netdev+0x1498> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1498;
	}
x86_l_12e9:
	/* 0x12e9: jmp    ba2 <tail_handle_ipv6_from_netdev+0xba2> */
	return 2978ULL;
x86_l_12ee:
	/* 0x12ee: mov    BYTE PTR [rsp+0xdc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_12f6:
	/* 0x12f6: mov    WORD PTR [rsp+0xd8],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_12ff:
	/* 0x12ff: mov    rax,QWORD PTR [rsp+0xbe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 190ULL);
x86_l_1307:
	/* 0x1307: mov    QWORD PTR [rsp+0x46],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_130c:
	/* 0x130c: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1314:
	/* 0x1314: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1319:
	/* 0x1319: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1321:
	/* 0x1321: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1326:
	/* 0x1326: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_132e:
	/* 0x132e: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1336:
	/* 0x1336: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_133b:
	/* 0x133b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1340:
	/* 0x1340: cmp    BYTE PTR [rsp+0xc4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 841813590022ULL);
x86_l_1348:
	/* 0x1348: jne    17fb <tail_handle_ipv6_from_netdev+0x17fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6139ULL;
	}
x86_l_134e:
	/* 0x134e: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1359:
	/* 0x1359: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1361:
	/* 0x1361: lea    esi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1364:
	/* 0x1364: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_136c:
	/* 0x136c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1371:
	/* 0x1371: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1374:
	/* 0x1374: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1379:
	/* 0x1379: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_137b:
	/* 0x137b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_137d:
	/* 0x137d: js     16a8 <tail_handle_ipv6_from_netdev+0x16a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5800ULL;
	}
x86_l_1383:
	/* 0x1383: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1388:
	/* 0x1388: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_138d:
	/* 0x138d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1392:
	/* 0x1392: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1397:
	/* 0x1397: mov    QWORD PTR [rsp+0x40],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_139c:
	/* 0x139c: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13a1:
	/* 0x13a1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13a6:
	/* 0x13a6: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13ab:
	/* 0x13ab: rol    DWORD PTR [rsp+0x48],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 309237645328ULL);
x86_l_13b0:
	/* 0x13b0: movzx  ebx,BYTE PTR [rsp+0x4d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 77ULL);
x86_l_13b5:
	/* 0x13b5: xor    bl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_13b8:
	/* 0x13b8: mov    BYTE PTR [rsp+0x4d],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_13bc:
	/* 0x13bc: test   BYTE PTR [rsp+0x89],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 588410519554ULL);
x86_l_13c4:
	/* 0x13c4: jne    17f4 <tail_handle_ipv6_from_netdev+0x17f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6132ULL;
	}
x86_l_13ca:
	/* 0x13ca: cmp    BYTE PTR [rsp+0x4c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514502ULL);
x86_l_13cf:
	/* 0x13cf: jne    1af6 <tail_handle_ipv6_from_netdev+0x1af6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6902ULL;
	}
x86_l_13d5:
	/* 0x13d5: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_13dc:
	/* 0x13dc: jmp    1afd <tail_handle_ipv6_from_netdev+0x1afd> */
	return 6909ULL;
x86_l_13e1:
	/* 0x13e1: movabs r14,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 1099511627776ULL);
x86_l_13eb:
	/* 0x13eb: movzx  ecx,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_13f3:
	/* 0x13f3: mov    BYTE PTR [rsp+0x73],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115ULL);
x86_l_13f7:
	/* 0x13f7: cmp    cl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_13fa:
	/* 0x13fa: jne    14a5 <tail_handle_ipv6_from_netdev+0x14a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a5;
	}
x86_l_1400:
	/* 0x1400: mov    rcx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_1407:
	/* 0x1407: jmp    14ac <tail_handle_ipv6_from_netdev+0x14ac> */
	goto x86_l_14ac;
x86_l_140c:
	/* 0x140c: mov    DWORD PTR [rsp+0x78],0xffffff7a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 519691042682ULL);
x86_l_1414:
	/* 0x1414: mov    r15d,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1419:
	/* 0x1419: jmp    2325 <tail_handle_ipv6_from_netdev+0x2325> */
	return 8997ULL;
x86_l_141e:
	/* 0x141e: mov    r15d,0xffffff4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967119ULL);
x86_l_1424:
	/* 0x1424: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1429:
	/* 0x1429: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
x86_l_142e:
	/* 0x142e: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_1432:
	/* 0x1432: je     1dbb <tail_handle_ipv6_from_netdev+0x1dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7611ULL;
	}
x86_l_1438:
	/* 0x1438: jmp    2350 <tail_handle_ipv6_from_netdev+0x2350> */
	return 9040ULL;
x86_l_143d:
	/* 0x143d: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1447:
	/* 0x1447: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_144c:
	/* 0x144c: lea    r15d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1454:
	/* 0x1454: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_1458:
	/* 0x1458: je     1583 <tail_handle_ipv6_from_netdev+0x1583> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1583;
	}
x86_l_145e:
	/* 0x145e: jmp    1606 <tail_handle_ipv6_from_netdev+0x1606> */
	return 5638ULL;
x86_l_1463:
	/* 0x1463: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1468:
	/* 0x1468: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1471:
	/* 0x1471: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1476:
	/* 0x1476: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_147b:
	/* 0x147b: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_147e:
	/* 0x147e: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1481:
	/* 0x1481: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1486:
	/* 0x1486: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1488:
	/* 0x1488: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_148a:
	/* 0x148a: js     1493 <tail_handle_ipv6_from_netdev+0x1493> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1493;
	}
x86_l_148c:
	/* 0x148c: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1491:
	/* 0x1491: jmp    1498 <tail_handle_ipv6_from_netdev+0x1498> */
	goto x86_l_1498;
x86_l_1493:
	/* 0x1493: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1498:
	/* 0x1498: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149b:
	/* 0x149b: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14a0:
	/* 0x14a0: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_14a5:
	/* 0x14a5: mov    rcx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_14ac:
	/* 0x14ac: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14b1:
	/* 0x14b1: movzx  ecx,BYTE PTR [rsp+0xc5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 197ULL);
x86_l_14b9:
	/* 0x14b9: mov    BYTE PTR [rsp+0xc7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 199ULL);
x86_l_14c0:
	/* 0x14c0: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14c8:
	/* 0x14c8: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_14d0:
	/* 0x14d0: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_14d8:
	/* 0x14d8: mov    QWORD PTR [rsp+0xf8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_14e0:
	/* 0x14e0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e5:
	/* 0x14e5: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_14e9:
	/* 0x14e9: mov    WORD PTR [rsp+0xe],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_14ee:
	/* 0x14ee: mov    BYTE PTR [rsp+0xc5],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 846108557316ULL);
x86_l_14f6:
	/* 0x14f6: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_14fe:
	/* 0x14fe: and    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1501:
	/* 0x1501: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1508:
	/* 0x1508: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150b:
	/* 0x150b: je     16f3 <tail_handle_ipv6_from_netdev+0x16f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5875ULL;
	}
x86_l_1511:
	/* 0x1511: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1514:
	/* 0x1514: je     16f3 <tail_handle_ipv6_from_netdev+0x16f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5875ULL;
	}
x86_l_151a:
	/* 0x151a: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_151d:
	/* 0x151d: mov    ebx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1520:
	/* 0x1520: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1529:
	/* 0x1529: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1532:
	/* 0x1532: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_153c:
	/* 0x153c: or     rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 256ULL);
x86_l_1542:
	/* 0x1542: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_154a:
	/* 0x154a: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1551:
	/* 0x1551: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1559:
	/* 0x1559: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_155e:
	/* 0x155e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1560:
	/* 0x1560: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1563:
	/* 0x1563: je     16c0 <tail_handle_ipv6_from_netdev+0x16c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5824ULL;
	}
x86_l_1569:
	/* 0x1569: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_156c:
	/* 0x156c: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1570:
	/* 0x1570: jmp    16eb <tail_handle_ipv6_from_netdev+0x16eb> */
	return 5867ULL;
x86_l_1575:
	/* 0x1575: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_1578:
	/* 0x1578: jmp    b9e <tail_handle_ipv6_from_netdev+0xb9e> */
	return 2974ULL;
x86_l_157d:
	/* 0x157d: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1583:
	/* 0x1583: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_1586:
	/* 0x1586: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_158f:
	/* 0x158f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1594:
	/* 0x1594: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1599:
	/* 0x1599: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_159e:
	/* 0x159e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_15a0:
	/* 0x15a0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 5541ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5545ULL: goto x86_l_15a9;
	case 5551ULL: goto x86_l_15af;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5564ULL: goto x86_l_15bc;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5590ULL: goto x86_l_15d6;
	case 5594ULL: goto x86_l_15da;
	case 5604ULL: goto x86_l_15e4;
	case 5607ULL: goto x86_l_15e7;
	case 5612ULL: goto x86_l_15ec;
	case 5616ULL: goto x86_l_15f0;
	case 5621ULL: goto x86_l_15f5;
	case 5625ULL: goto x86_l_15f9;
	case 5635ULL: goto x86_l_1603;
	case 5638ULL: goto x86_l_1606;
	case 5642ULL: goto x86_l_160a;
	case 5646ULL: goto x86_l_160e;
	case 5650ULL: goto x86_l_1612;
	case 5656ULL: goto x86_l_1618;
	case 5660ULL: goto x86_l_161c;
	case 5668ULL: goto x86_l_1624;
	case 5671ULL: goto x86_l_1627;
	case 5675ULL: goto x86_l_162b;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5690ULL: goto x86_l_163a;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5710ULL: goto x86_l_164e;
	case 5715ULL: goto x86_l_1653;
	case 5717ULL: goto x86_l_1655;
	case 5719ULL: goto x86_l_1657;
	case 5725ULL: goto x86_l_165d;
	case 5731ULL: goto x86_l_1663;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5741ULL: goto x86_l_166d;
	case 5747ULL: goto x86_l_1673;
	case 5751ULL: goto x86_l_1677;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5766ULL: goto x86_l_1686;
	case 5771ULL: goto x86_l_168b;
	case 5776ULL: goto x86_l_1690;
	case 5784ULL: goto x86_l_1698;
	case 5789ULL: goto x86_l_169d;
	case 5795ULL: goto x86_l_16a3;
	case 5800ULL: goto x86_l_16a8;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5813ULL: goto x86_l_16b5;
	case 5819ULL: goto x86_l_16bb;
	case 5824ULL: goto x86_l_16c0;
	case 5833ULL: goto x86_l_16c9;
	case 5838ULL: goto x86_l_16ce;
	case 5845ULL: goto x86_l_16d5;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5867ULL: goto x86_l_16eb;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5888ULL: goto x86_l_1700;
	case 5896ULL: goto x86_l_1708;
	case 5898ULL: goto x86_l_170a;
	case 5901ULL: goto x86_l_170d;
	case 5911ULL: goto x86_l_1717;
	case 5914ULL: goto x86_l_171a;
	case 5916ULL: goto x86_l_171c;
	case 5924ULL: goto x86_l_1724;
	case 5927ULL: goto x86_l_1727;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5940ULL: goto x86_l_1734;
	case 5945ULL: goto x86_l_1739;
	case 5947ULL: goto x86_l_173b;
	case 5949ULL: goto x86_l_173d;
	case 5955ULL: goto x86_l_1743;
	case 5959ULL: goto x86_l_1747;
	case 5961ULL: goto x86_l_1749;
	case 5966ULL: goto x86_l_174e;
	case 5968ULL: goto x86_l_1750;
	case 5973ULL: goto x86_l_1755;
	case 5976ULL: goto x86_l_1758;
	case 5980ULL: goto x86_l_175c;
	case 5986ULL: goto x86_l_1762;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5997ULL: goto x86_l_176d;
	case 5999ULL: goto x86_l_176f;
	case 6003ULL: goto x86_l_1773;
	case 6007ULL: goto x86_l_1777;
	case 6015ULL: goto x86_l_177f;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6027ULL: goto x86_l_178b;
	case 6030ULL: goto x86_l_178e;
	case 6036ULL: goto x86_l_1794;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6055ULL: goto x86_l_17a7;
	case 6063ULL: goto x86_l_17af;
	case 6069ULL: goto x86_l_17b5;
	case 6074ULL: goto x86_l_17ba;
	case 6080ULL: goto x86_l_17c0;
	case 6087ULL: goto x86_l_17c7;
	case 6090ULL: goto x86_l_17ca;
	case 6096ULL: goto x86_l_17d0;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6108ULL: goto x86_l_17dc;
	case 6111ULL: goto x86_l_17df;
	case 6113ULL: goto x86_l_17e1;
	case 6116ULL: goto x86_l_17e4;
	case 6121ULL: goto x86_l_17e9;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6139ULL: goto x86_l_17fb;
	case 6151ULL: goto x86_l_1807;
	case 6163ULL: goto x86_l_1813;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6189ULL: goto x86_l_182d;
	case 6193ULL: goto x86_l_1831;
	case 6203ULL: goto x86_l_183b;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6219ULL: goto x86_l_184b;
	case 6225ULL: goto x86_l_1851;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6238ULL: goto x86_l_185e;
	case 6241ULL: goto x86_l_1861;
	case 6246ULL: goto x86_l_1866;
	case 6248ULL: goto x86_l_1868;
	case 6250ULL: goto x86_l_186a;
	case 6256ULL: goto x86_l_1870;
	case 6261ULL: goto x86_l_1875;
	case 6265ULL: goto x86_l_1879;
	case 6267ULL: goto x86_l_187b;
	case 6271ULL: goto x86_l_187f;
	case 6277ULL: goto x86_l_1885;
	case 6281ULL: goto x86_l_1889;
	case 6287ULL: goto x86_l_188f;
	case 6292ULL: goto x86_l_1894;
	case 6299ULL: goto x86_l_189b;
	case 6303ULL: goto x86_l_189f;
	case 6309ULL: goto x86_l_18a5;
	case 6312ULL: goto x86_l_18a8;
	case 6319ULL: goto x86_l_18af;
	case 6329ULL: goto x86_l_18b9;
	case 6335ULL: goto x86_l_18bf;
	case 6338ULL: goto x86_l_18c2;
	case 6341ULL: goto x86_l_18c5;
	case 6349ULL: goto x86_l_18cd;
	case 6354ULL: goto x86_l_18d2;
	case 6359ULL: goto x86_l_18d7;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6369ULL: goto x86_l_18e1;
	case 6371ULL: goto x86_l_18e3;
	case 6377ULL: goto x86_l_18e9;
	case 6385ULL: goto x86_l_18f1;
	case 6391ULL: goto x86_l_18f7;
	case 6399ULL: goto x86_l_18ff;
	case 6406ULL: goto x86_l_1906;
	case 6416ULL: goto x86_l_1910;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6439ULL: goto x86_l_1927;
	case 6443ULL: goto x86_l_192b;
	case 6448ULL: goto x86_l_1930;
	case 6453ULL: goto x86_l_1935;
	case 6456ULL: goto x86_l_1938;
	case 6458ULL: goto x86_l_193a;
	case 6463ULL: goto x86_l_193f;
	case 6469ULL: goto x86_l_1945;
	case 6471ULL: goto x86_l_1947;
	case 6473ULL: goto x86_l_1949;
	case 6479ULL: goto x86_l_194f;
	case 6487ULL: goto x86_l_1957;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6503ULL: goto x86_l_1967;
	case 6505ULL: goto x86_l_1969;
	case 6510ULL: goto x86_l_196e;
	case 6512ULL: goto x86_l_1970;
	case 6518ULL: goto x86_l_1976;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6541ULL: goto x86_l_198d;
	case 6543ULL: goto x86_l_198f;
	case 6545ULL: goto x86_l_1991;
	case 6551ULL: goto x86_l_1997;
	case 6558ULL: goto x86_l_199e;
	case 6560ULL: goto x86_l_19a0;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6569ULL: goto x86_l_19a9;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6582ULL: goto x86_l_19b6;
	case 6591ULL: goto x86_l_19bf;
	case 6596ULL: goto x86_l_19c4;
	case 6601ULL: goto x86_l_19c9;
	case 6606ULL: goto x86_l_19ce;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6615ULL: goto x86_l_19d7;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6628ULL: goto x86_l_19e4;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6641ULL: goto x86_l_19f1;
	case 6644ULL: goto x86_l_19f4;
	case 6649ULL: goto x86_l_19f9;
	case 6659ULL: goto x86_l_1a03;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6671ULL: goto x86_l_1a0f;
	case 6681ULL: goto x86_l_1a19;
	case 6684ULL: goto x86_l_1a1c;
	case 6689ULL: goto x86_l_1a21;
	case 6693ULL: goto x86_l_1a25;
	case 6698ULL: goto x86_l_1a2a;
	case 6702ULL: goto x86_l_1a2e;
	case 6706ULL: goto x86_l_1a32;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6725ULL: goto x86_l_1a45;
	case 6729ULL: goto x86_l_1a49;
	case 6735ULL: goto x86_l_1a4f;
	case 6738ULL: goto x86_l_1a52;
	case 6748ULL: goto x86_l_1a5c;
	case 6752ULL: goto x86_l_1a60;
	case 6758ULL: goto x86_l_1a66;
	case 6763ULL: goto x86_l_1a6b;
	case 6771ULL: goto x86_l_1a73;
	case 6774ULL: goto x86_l_1a76;
	case 6779ULL: goto x86_l_1a7b;
	case 6784ULL: goto x86_l_1a80;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6798ULL: goto x86_l_1a8e;
	case 6800ULL: goto x86_l_1a90;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6811ULL: goto x86_l_1a9b;
	case 6815ULL: goto x86_l_1a9f;
	case 6817ULL: goto x86_l_1aa1;
	case 6821ULL: goto x86_l_1aa5;
	case 6827ULL: goto x86_l_1aab;
	case 6831ULL: goto x86_l_1aaf;
	case 6833ULL: goto x86_l_1ab1;
	case 6838ULL: goto x86_l_1ab6;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6859ULL: goto x86_l_1acb;
	case 6864ULL: goto x86_l_1ad0;
	case 6869ULL: goto x86_l_1ad5;
	case 6874ULL: goto x86_l_1ada;
	case 6879ULL: goto x86_l_1adf;
	case 6887ULL: goto x86_l_1ae7;
	case 6891ULL: goto x86_l_1aeb;
	case 6897ULL: goto x86_l_1af1;
	case 6902ULL: goto x86_l_1af6;
	case 6909ULL: goto x86_l_1afd;
	case 6914ULL: goto x86_l_1b02;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6926ULL: goto x86_l_1b0e;
	case 6930ULL: goto x86_l_1b12;
	case 6933ULL: goto x86_l_1b15;
	case 6935ULL: goto x86_l_1b17;
	case 6939ULL: goto x86_l_1b1b;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6964ULL: goto x86_l_1b34;
	case 6966ULL: goto x86_l_1b36;
	case 6976ULL: goto x86_l_1b40;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6996ULL: goto x86_l_1b54;
	case 7003ULL: goto x86_l_1b5b;
	case 7013ULL: goto x86_l_1b65;
	case 7016ULL: goto x86_l_1b68;
	case 7019ULL: goto x86_l_1b6b;
	case 7025ULL: goto x86_l_1b71;
	case 7027ULL: goto x86_l_1b73;
	case 7031ULL: goto x86_l_1b77;
	case 7037ULL: goto x86_l_1b7d;
	case 7040ULL: goto x86_l_1b80;
	case 7042ULL: goto x86_l_1b82;
	case 7047ULL: goto x86_l_1b87;
	case 7052ULL: goto x86_l_1b8c;
	case 7055ULL: goto x86_l_1b8f;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7064ULL: goto x86_l_1b98;
	case 7070ULL: goto x86_l_1b9e;
	case 7075ULL: goto x86_l_1ba3;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7084ULL: goto x86_l_1bac;
	case 7087ULL: goto x86_l_1baf;
	case 7093ULL: goto x86_l_1bb5;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7103ULL: goto x86_l_1bbf;
	case 7111ULL: goto x86_l_1bc7;
	case 7116ULL: goto x86_l_1bcc;
	case 7121ULL: goto x86_l_1bd1;
	case 7129ULL: goto x86_l_1bd9;
	case 7132ULL: goto x86_l_1bdc;
	case 7138ULL: goto x86_l_1be2;
	case 7142ULL: goto x86_l_1be6;
	case 7149ULL: goto x86_l_1bed;
	case 7159ULL: goto x86_l_1bf7;
	case 7165ULL: goto x86_l_1bfd;
	case 7168ULL: goto x86_l_1c00;
	case 7170ULL: goto x86_l_1c02;
	case 7178ULL: goto x86_l_1c0a;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7197ULL: goto x86_l_1c1d;
	case 7199ULL: goto x86_l_1c1f;
	case 7201ULL: goto x86_l_1c21;
	case 7207ULL: goto x86_l_1c27;
	case 7215ULL: goto x86_l_1c2f;
	case 7221ULL: goto x86_l_1c35;
	case 7229ULL: goto x86_l_1c3d;
	case 7236ULL: goto x86_l_1c44;
	case 7246ULL: goto x86_l_1c4e;
	case 7252ULL: goto x86_l_1c54;
	case 7257ULL: goto x86_l_1c59;
	case 7261ULL: goto x86_l_1c5d;
	case 7268ULL: goto x86_l_1c64;
	case 7271ULL: goto x86_l_1c67;
	case 7273ULL: goto x86_l_1c69;
	case 7275ULL: goto x86_l_1c6b;
	case 7277ULL: goto x86_l_1c6d;
	case 7282ULL: goto x86_l_1c72;
	case 7286ULL: goto x86_l_1c76;
	case 7289ULL: goto x86_l_1c79;
	case 7291ULL: goto x86_l_1c7b;
	case 7295ULL: goto x86_l_1c7f;
	case 7297ULL: goto x86_l_1c81;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7310ULL: goto x86_l_1c8e;
	case 7316ULL: goto x86_l_1c94;
	case 7325ULL: goto x86_l_1c9d;
	case 7330ULL: goto x86_l_1ca2;
	case 7335ULL: goto x86_l_1ca7;
	case 7340ULL: goto x86_l_1cac;
	case 7342ULL: goto x86_l_1cae;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_15a5:
	/* 0x15a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a7:
	/* 0x15a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15a9:
	/* 0x15a9: js     231f <tail_handle_ipv6_from_netdev+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8991ULL;
	}
x86_l_15af:
	/* 0x15af: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15b3:
	/* 0x15b3: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_15b8:
	/* 0x15b8: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_15bc:
	/* 0x15bc: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15bf:
	/* 0x15bf: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_15c4:
	/* 0x15c4: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_15ce:
	/* 0x15ce: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15d1:
	/* 0x15d1: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_15d6:
	/* 0x15d6: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_15da:
	/* 0x15da: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_15e4:
	/* 0x15e4: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15e7:
	/* 0x15e7: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_15ec:
	/* 0x15ec: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_15f0:
	/* 0x15f0: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_15f5:
	/* 0x15f5: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15f9:
	/* 0x15f9: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1603:
	/* 0x1603: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_1606:
	/* 0x1606: movzx  r12d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_160a:
	/* 0x160a: lea    esi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_160e:
	/* 0x160e: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1612:
	/* 0x1612: ja     1b20 <tail_handle_ipv6_from_netdev+0x1b20> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1b20;
	}
x86_l_1618:
	/* 0x1618: mov    BYTE PTR [rsp+0xe],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_161c:
	/* 0x161c: mov    QWORD PTR [rsp+0x80],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1624:
	/* 0x1624: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1627:
	/* 0x1627: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_162b:
	/* 0x162b: jae    1d97 <tail_handle_ipv6_from_netdev+0x1d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7575ULL;
	}
x86_l_1631:
	/* 0x1631: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1636:
	/* 0x1636: lea    ebp,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_163a:
	/* 0x163a: add    ebp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_163d:
	/* 0x163d: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1642:
	/* 0x1642: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1647:
	/* 0x1647: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_164c:
	/* 0x164c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_164e:
	/* 0x164e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1653:
	/* 0x1653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1655:
	/* 0x1655: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1657:
	/* 0x1657: js     1ac3 <tail_handle_ipv6_from_netdev+0x1ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ac3;
	}
x86_l_165d:
	/* 0x165d: movzx  r14d,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_1663:
	/* 0x1663: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_1667:
	/* 0x1667: jle    168b <tail_handle_ipv6_from_netdev+0x168b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_168b;
	}
x86_l_1669:
	/* 0x1669: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_166d:
	/* 0x166d: je     19b0 <tail_handle_ipv6_from_netdev+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b0;
	}
x86_l_1673:
	/* 0x1673: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_1677:
	/* 0x1677: jne    168b <tail_handle_ipv6_from_netdev+0x168b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_168b;
	}
x86_l_1679:
	/* 0x1679: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_167e:
	/* 0x167e: lea    r15d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1686:
	/* 0x1686: jmp    1a2e <tail_handle_ipv6_from_netdev+0x1a2e> */
	goto x86_l_1a2e;
x86_l_168b:
	/* 0x168b: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_1690:
	/* 0x1690: lea    r15d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1698:
	/* 0x1698: cmp    BYTE PTR [rsp+0xe],0x2c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542188ULL);
x86_l_169d:
	/* 0x169d: je     19b6 <tail_handle_ipv6_from_netdev+0x19b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b6;
	}
x86_l_16a3:
	/* 0x16a3: jmp    1a2e <tail_handle_ipv6_from_netdev+0x1a2e> */
	goto x86_l_1a2e;
x86_l_16a8:
	/* 0x16a8: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_16ae:
	/* 0x16ae: jmp    270d <tail_handle_ipv6_from_netdev+0x270d> */
	return 9997ULL;
x86_l_16b3:
	/* 0x16b3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b5:
	/* 0x16b5: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_16bb:
	/* 0x16bb: jmp    6d1 <tail_handle_ipv6_from_netdev+0x6d1> */
	return 1745ULL;
x86_l_16c0:
	/* 0x16c0: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_16c9:
	/* 0x16c9: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16ce:
	/* 0x16ce: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_16d5:
	/* 0x16d5: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16dd:
	/* 0x16dd: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16e2:
	/* 0x16e2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16e7:
	/* 0x16e7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e9:
	/* 0x16e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16eb:
	/* 0x16eb: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_16ee:
	/* 0x16ee: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f3:
	/* 0x16f3: cmp    BYTE PTR [rsp+0x73],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239046ULL);
x86_l_16f8:
	/* 0x16f8: mov    QWORD PTR [rsp+0xe0],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1700:
	/* 0x1700: mov    QWORD PTR [rsp+0x100],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1708:
	/* 0x1708: jne    176d <tail_handle_ipv6_from_netdev+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_176d;
	}
x86_l_170a:
	/* 0x170a: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_170d:
	/* 0x170d: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1717:
	/* 0x1717: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_171a:
	/* 0x171a: jne    176d <tail_handle_ipv6_from_netdev+0x176d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_176d;
	}
x86_l_171c:
	/* 0x171c: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1724:
	/* 0x1724: lea    esi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1727:
	/* 0x1727: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_172c:
	/* 0x172c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1731:
	/* 0x1731: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1734:
	/* 0x1734: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1739:
	/* 0x1739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173b:
	/* 0x173b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_173d:
	/* 0x173d: js     17e9 <tail_handle_ipv6_from_netdev+0x17e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_17e9;
	}
x86_l_1743:
	/* 0x1743: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1747:
	/* 0x1747: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1749:
	/* 0x1749: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_174e:
	/* 0x174e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1750:
	/* 0x1750: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1755:
	/* 0x1755: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1758:
	/* 0x1758: mov    DWORD PTR [rsp+0x74],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_175c:
	/* 0x175c: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_1762:
	/* 0x1762: jne    3304 <tail_handle_ipv6_from_netdev+0x3304> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13060ULL;
	}
x86_l_1768:
	/* 0x1768: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_176b:
	/* 0x176b: jmp    1777 <tail_handle_ipv6_from_netdev+0x1777> */
	goto x86_l_1777;
x86_l_176d:
	/* 0x176d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176f:
	/* 0x176f: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1773:
	/* 0x1773: mov    DWORD PTR [rsp+0x74],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1777:
	/* 0x1777: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_177f:
	/* 0x177f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1784:
	/* 0x1784: mov    rdi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1789:
	/* 0x1789: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178b:
	/* 0x178b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_178e:
	/* 0x178e: je     34f6 <tail_handle_ipv6_from_netdev+0x34f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13558ULL;
	}
x86_l_1794:
	/* 0x1794: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1797:
	/* 0x1797: movzx  eax,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_179c:
	/* 0x179c: cmp    WORD PTR [r13+0x26],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_17a1:
	/* 0x17a1: jne    34f6 <tail_handle_ipv6_from_netdev+0x34f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13558ULL;
	}
x86_l_17a7:
	/* 0x17a7: test   DWORD PTR [rsp+0x74],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206848ULL);
x86_l_17af:
	/* 0x17af: je     1e29 <tail_handle_ipv6_from_netdev+0x1e29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7721ULL;
	}
x86_l_17b5:
	/* 0x17b5: test   BYTE PTR [r13+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_17ba:
	/* 0x17ba: je     1e29 <tail_handle_ipv6_from_netdev+0x1e29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7721ULL;
	}
x86_l_17c0:
	/* 0x17c0: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_17c7:
	/* 0x17c7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17ca:
	/* 0x17ca: je     1de0 <tail_handle_ipv6_from_netdev+0x1de0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7648ULL;
	}
x86_l_17d0:
	/* 0x17d0: mov    rcx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_17d7:
	/* 0x17d7: mov    ebx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d9:
	/* 0x17d9: lea    ecx,[rbx+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_17dc:
	/* 0x17dc: shl    ebx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_17df:
	/* 0x17df: sub    ebx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17e1:
	/* 0x17e1: shr    ebx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_17e4:
	/* 0x17e4: jmp    1de5 <tail_handle_ipv6_from_netdev+0x1de5> */
	return 7653ULL;
x86_l_17e9:
	/* 0x17e9: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_17ef:
	/* 0x17ef: jmp    3c5e <tail_handle_ipv6_from_netdev+0x3c5e> */
	return 15454ULL;
x86_l_17f4:
	/* 0x17f4: mov    r15,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_17fb:
	/* 0x17fb: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1807:
	/* 0x1807: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1813:
	/* 0x1813: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_181f:
	/* 0x181f: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1824:
	/* 0x1824: movzx  r14d,BYTE PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_1829:
	/* 0x1829: movzx  esi,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_182d:
	/* 0x182d: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_1831:
	/* 0x1831: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_183b:
	/* 0x183b: ja     282b <tail_handle_ipv6_from_netdev+0x282b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10283ULL;
	}
x86_l_1841:
	/* 0x1841: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_1847:
	/* 0x1847: bt     rax,r14 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_184b:
	/* 0x184b: jae    2703 <tail_handle_ipv6_from_netdev+0x2703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 9987ULL;
	}
x86_l_1851:
	/* 0x1851: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1854:
	/* 0x1854: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1859:
	/* 0x1859: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_185e:
	/* 0x185e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1861:
	/* 0x1861: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1866:
	/* 0x1866: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1868:
	/* 0x1868: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_186a:
	/* 0x186a: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9979ULL;
	}
x86_l_1870:
	/* 0x1870: movzx  ebp,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1875:
	/* 0x1875: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_1879:
	/* 0x1879: jle    188f <tail_handle_ipv6_from_netdev+0x188f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_188f;
	}
x86_l_187b:
	/* 0x187b: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_187f:
	/* 0x187f: je     1b2d <tail_handle_ipv6_from_netdev+0x1b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b2d;
	}
x86_l_1885:
	/* 0x1885: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1889:
	/* 0x1889: jne    1b48 <tail_handle_ipv6_from_netdev+0x1b48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b48;
	}
x86_l_188f:
	/* 0x188f: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1894:
	/* 0x1894: lea    ebx,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_189b:
	/* 0x189b: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_189f:
	/* 0x189f: jne    1b54 <tail_handle_ipv6_from_netdev+0x1b54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b54;
	}
x86_l_18a5:
	/* 0x18a5: cmp    ebx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 24ULL);
x86_l_18a8:
	/* 0x18a8: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_18af:
	/* 0x18af: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_18b9:
	/* 0x18b9: jne    1b65 <tail_handle_ipv6_from_netdev+0x1b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b65;
	}
x86_l_18bf:
	/* 0x18bf: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_18c2:
	/* 0x18c2: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_18c5:
	/* 0x18c5: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18cd:
	/* 0x18cd: mov    ebx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 24ULL);
x86_l_18d2:
	/* 0x18d2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_18d7:
	/* 0x18d7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_18da:
	/* 0x18da: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_18df:
	/* 0x18df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e1:
	/* 0x18e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18e3:
	/* 0x18e3: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9979ULL;
	}
x86_l_18e9:
	/* 0x18e9: cmp    BYTE PTR [rsp+0x8a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 592705486875ULL);
x86_l_18f1:
	/* 0x18f1: jne    1b54 <tail_handle_ipv6_from_netdev+0x1b54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b54;
	}
x86_l_18f7:
	/* 0x18f7: cmp    BYTE PTR [rsp+0x8b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 597000454164ULL);
x86_l_18ff:
	/* 0x18ff: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1906:
	/* 0x1906: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1910:
	/* 0x1910: je     26c4 <tail_handle_ipv6_from_netdev+0x26c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9924ULL;
	}
x86_l_1916:
	/* 0x1916: jmp    1b65 <tail_handle_ipv6_from_netdev+0x1b65> */
	goto x86_l_1b65;
x86_l_191b:
	/* 0x191b: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1920:
	/* 0x1920: jmp    1c72 <tail_handle_ipv6_from_netdev+0x1c72> */
	goto x86_l_1c72;
x86_l_1925:
	/* 0x1925: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_1927:
	/* 0x1927: mov    BYTE PTR [rsp+0x18],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_192b:
	/* 0x192b: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1930:
	/* 0x1930: mov    ebx,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 9ULL);
x86_l_1935:
	/* 0x1935: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1938:
	/* 0x1938: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_193a:
	/* 0x193a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_193f:
	/* 0x193f: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_1945:
	/* 0x1945: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1947:
	/* 0x1947: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1949:
	/* 0x1949: js     1c6d <tail_handle_ipv6_from_netdev+0x1c6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c6d;
	}
x86_l_194f:
	/* 0x194f: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1957:
	/* 0x1957: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_195a:
	/* 0x195a: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_195f:
	/* 0x195f: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1964:
	/* 0x1964: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1967:
	/* 0x1967: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1969:
	/* 0x1969: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_196e:
	/* 0x196e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1970:
	/* 0x1970: js     1c72 <tail_handle_ipv6_from_netdev+0x1c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c72;
	}
x86_l_1976:
	/* 0x1976: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_197b:
	/* 0x197b: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1980:
	/* 0x1980: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1983:
	/* 0x1983: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1985:
	/* 0x1985: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_198a:
	/* 0x198a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198d:
	/* 0x198d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198f:
	/* 0x198f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1991:
	/* 0x1991: js     1c72 <tail_handle_ipv6_from_netdev+0x1c72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1c72;
	}
x86_l_1997:
	/* 0x1997: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_199e:
	/* 0x199e: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a0:
	/* 0x19a0: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_19a5:
	/* 0x19a5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a7:
	/* 0x19a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a9:
	/* 0x19a9: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_19ab:
	/* 0x19ab: jmp    1c72 <tail_handle_ipv6_from_netdev+0x1c72> */
	goto x86_l_1c72;
x86_l_19b0:
	/* 0x19b0: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_19b6:
	/* 0x19b6: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19bf:
	/* 0x19bf: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19c4:
	/* 0x19c4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_19c9:
	/* 0x19c9: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19ce:
	/* 0x19ce: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_19d0:
	/* 0x19d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19d5:
	/* 0x19d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d7:
	/* 0x19d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d9:
	/* 0x19d9: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19de:
	/* 0x19de: js     231f <tail_handle_ipv6_from_netdev+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8991ULL;
	}
x86_l_19e4:
	/* 0x19e4: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19e8:
	/* 0x19e8: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_19ed:
	/* 0x19ed: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_19f1:
	/* 0x19f1: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_19f4:
	/* 0x19f4: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_19f9:
	/* 0x19f9: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1a03:
	/* 0x1a03: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a06:
	/* 0x1a06: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_1a0b:
	/* 0x1a0b: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_1a0f:
	/* 0x1a0f: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1a19:
	/* 0x1a19: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a1c:
	/* 0x1a1c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_1a21:
	/* 0x1a21: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1a25:
	/* 0x1a25: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a2a:
	/* 0x1a2a: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a2e:
	/* 0x1a2e: movzx  r12d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a32:
	/* 0x1a32: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a3a:
	/* 0x1a3a: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a3d:
	/* 0x1a3d: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a45:
	/* 0x1a45: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1a49:
	/* 0x1a49: ja     2343 <tail_handle_ipv6_from_netdev+0x2343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9027ULL;
	}
x86_l_1a4f:
	/* 0x1a4f: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1a52:
	/* 0x1a52: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1a5c:
	/* 0x1a5c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1a60:
	/* 0x1a60: jae    1d9f <tail_handle_ipv6_from_netdev+0x1d9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7583ULL;
	}
x86_l_1a66:
	/* 0x1a66: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a6b:
	/* 0x1a6b: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a73:
	/* 0x1a73: lea    ebp,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a76:
	/* 0x1a76: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a7b:
	/* 0x1a7b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1a80:
	/* 0x1a80: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a85:
	/* 0x1a85: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a87:
	/* 0x1a87: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a8c:
	/* 0x1a8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8e:
	/* 0x1a8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a90:
	/* 0x1a90: js     1ac3 <tail_handle_ipv6_from_netdev+0x1ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1ac3;
	}
x86_l_1a92:
	/* 0x1a92: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_1a97:
	/* 0x1a97: mov    BYTE PTR [rsp+0xe],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1a9b:
	/* 0x1a9b: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_1a9f:
	/* 0x1a9f: jle    1ada <tail_handle_ipv6_from_netdev+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ada;
	}
x86_l_1aa1:
	/* 0x1aa1: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_1aa5:
	/* 0x1aa5: je     1c8e <tail_handle_ipv6_from_netdev+0x1c8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c8e;
	}
x86_l_1aab:
	/* 0x1aab: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_1aaf:
	/* 0x1aaf: jne    1ada <tail_handle_ipv6_from_netdev+0x1ada> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ada;
	}
x86_l_1ab1:
	/* 0x1ab1: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_1ab6:
	/* 0x1ab6: lea    r15d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1abe:
	/* 0x1abe: jmp    1d0c <tail_handle_ipv6_from_netdev+0x1d0c> */
	return 7436ULL;
x86_l_1ac3:
	/* 0x1ac3: mov    DWORD PTR [rsp+0x78],0xffffff7a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 519691042682ULL);
x86_l_1acb:
	/* 0x1acb: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    r15d,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ad5:
	/* 0x1ad5: jmp    2325 <tail_handle_ipv6_from_netdev+0x2325> */
	return 8997ULL;
x86_l_1ada:
	/* 0x1ada: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_1adf:
	/* 0x1adf: lea    r15d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1ae7:
	/* 0x1ae7: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_1aeb:
	/* 0x1aeb: je     1c94 <tail_handle_ipv6_from_netdev+0x1c94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c94;
	}
x86_l_1af1:
	/* 0x1af1: jmp    1d0c <tail_handle_ipv6_from_netdev+0x1d0c> */
	return 7436ULL;
x86_l_1af6:
	/* 0x1af6: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1afd:
	/* 0x1afd: mov    BYTE PTR [rsp+0x4d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 330712481792ULL);
x86_l_1b02:
	/* 0x1b02: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b07:
	/* 0x1b07: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b0c:
	/* 0x1b0c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0e:
	/* 0x1b0e: mov    BYTE PTR [rsp+0x4d],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 77ULL);
x86_l_1b12:
	/* 0x1b12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b15:
	/* 0x1b15: je     1b34 <tail_handle_ipv6_from_netdev+0x1b34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b34;
	}
x86_l_1b17:
	/* 0x1b17: movzx  eax,BYTE PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1b1b:
	/* 0x1b1b: shr    al,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 7ULL);
x86_l_1b1e:
	/* 0x1b1e: jmp    1b36 <tail_handle_ipv6_from_netdev+0x1b36> */
	goto x86_l_1b36;
x86_l_1b20:
	/* 0x1b20: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_1b23:
	/* 0x1b23: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b28:
	/* 0x1b28: jmp    2350 <tail_handle_ipv6_from_netdev+0x2350> */
	return 9040ULL;
x86_l_1b2d:
	/* 0x1b2d: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1b32:
	/* 0x1b32: jmp    1b54 <tail_handle_ipv6_from_netdev+0x1b54> */
	goto x86_l_1b54;
x86_l_1b34:
	/* 0x1b34: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b36:
	/* 0x1b36: mov    WORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_1b40:
	/* 0x1b40: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b43:
	/* 0x1b43: jmp    270f <tail_handle_ipv6_from_netdev+0x270f> */
	return 9999ULL;
x86_l_1b48:
	/* 0x1b48: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1b4d:
	/* 0x1b4d: lea    ebx,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1b54:
	/* 0x1b54: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1b5b:
	/* 0x1b5b: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1b65:
	/* 0x1b65: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1b68:
	/* 0x1b68: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1b6b:
	/* 0x1b6b: ja     282b <tail_handle_ipv6_from_netdev+0x282b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10283ULL;
	}
x86_l_1b71:
	/* 0x1b71: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1b73:
	/* 0x1b73: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b77:
	/* 0x1b77: jae    21a6 <tail_handle_ipv6_from_netdev+0x21a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8614ULL;
	}
x86_l_1b7d:
	/* 0x1b7d: add    ebx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1b80:
	/* 0x1b80: add    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b82:
	/* 0x1b82: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b87:
	/* 0x1b87: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1b8c:
	/* 0x1b8c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1b8f:
	/* 0x1b8f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b94:
	/* 0x1b94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b96:
	/* 0x1b96: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b98:
	/* 0x1b98: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9979ULL;
	}
x86_l_1b9e:
	/* 0x1b9e: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1ba3:
	/* 0x1ba3: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ba7:
	/* 0x1ba7: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1baa:
	/* 0x1baa: jle    1bcc <tail_handle_ipv6_from_netdev+0x1bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1bcc;
	}
x86_l_1bac:
	/* 0x1bac: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_1baf:
	/* 0x1baf: je     211f <tail_handle_ipv6_from_netdev+0x211f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8479ULL;
	}
x86_l_1bb5:
	/* 0x1bb5: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1bb8:
	/* 0x1bb8: jne    1bcc <tail_handle_ipv6_from_netdev+0x1bcc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bcc;
	}
x86_l_1bba:
	/* 0x1bba: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1bbf:
	/* 0x1bbf: lea    r14d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1bc7:
	/* 0x1bc7: jmp    2125 <tail_handle_ipv6_from_netdev+0x2125> */
	return 8485ULL;
x86_l_1bcc:
	/* 0x1bcc: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1bd1:
	/* 0x1bd1: lea    r14d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1bd9:
	/* 0x1bd9: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1bdc:
	/* 0x1bdc: jne    2125 <tail_handle_ipv6_from_netdev+0x2125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8485ULL;
	}
x86_l_1be2:
	/* 0x1be2: cmp    r14d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 24ULL);
x86_l_1be6:
	/* 0x1be6: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1bed:
	/* 0x1bed: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1bf7:
	/* 0x1bf7: jne    2136 <tail_handle_ipv6_from_netdev+0x2136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8502ULL;
	}
x86_l_1bfd:
	/* 0x1bfd: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c00:
	/* 0x1c00: add    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c02:
	/* 0x1c02: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c0a:
	/* 0x1c0a: mov    r14d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 24ULL);
x86_l_1c10:
	/* 0x1c10: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1c15:
	/* 0x1c15: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c18:
	/* 0x1c18: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1c1d:
	/* 0x1c1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1f:
	/* 0x1c1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c21:
	/* 0x1c21: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9979ULL;
	}
x86_l_1c27:
	/* 0x1c27: cmp    BYTE PTR [rsp+0x8a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 592705486875ULL);
x86_l_1c2f:
	/* 0x1c2f: jne    2125 <tail_handle_ipv6_from_netdev+0x2125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8485ULL;
	}
x86_l_1c35:
	/* 0x1c35: cmp    BYTE PTR [rsp+0x8b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 597000454164ULL);
x86_l_1c3d:
	/* 0x1c3d: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1c44:
	/* 0x1c44: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1c4e:
	/* 0x1c4e: je     26c4 <tail_handle_ipv6_from_netdev+0x26c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9924ULL;
	}
x86_l_1c54:
	/* 0x1c54: jmp    2136 <tail_handle_ipv6_from_netdev+0x2136> */
	return 8502ULL;
x86_l_1c59:
	/* 0x1c59: shl    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1c5d:
	/* 0x1c5d: or     r15d,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_1c64:
	/* 0x1c64: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c67:
	/* 0x1c67: mov    bl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_1c69:
	/* 0x1c69: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c6b:
	/* 0x1c6b: jmp    1c7b <tail_handle_ipv6_from_netdev+0x1c7b> */
	goto x86_l_1c7b;
x86_l_1c6d:
	/* 0x1c6d: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1c72:
	/* 0x1c72: mov    r15d,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c76:
	/* 0x1c76: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_1c79:
	/* 0x1c79: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c7b:
	/* 0x1c7b: mov    DWORD PTR [r14+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1c81:
	/* 0x1c81: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1c84:
	/* 0x1c84: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c89:
	/* 0x1c89: jmp    ca7 <tail_handle_ipv6_from_netdev+0xca7> */
	return 3239ULL;
x86_l_1c8e:
	/* 0x1c8e: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_1c94:
	/* 0x1c94: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c9d:
	/* 0x1c9d: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ca2:
	/* 0x1ca2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1ca7:
	/* 0x1ca7: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cac:
	/* 0x1cac: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1cae:
	/* 0x1cae: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cb3:
	/* 0x1cb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb5:
	/* 0x1cb5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
	return 7351ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7351ULL: goto x86_l_1cb7;
	case 7356ULL: goto x86_l_1cbc;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7375ULL: goto x86_l_1ccf;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7393ULL: goto x86_l_1ce1;
	case 7396ULL: goto x86_l_1ce4;
	case 7401ULL: goto x86_l_1ce9;
	case 7405ULL: goto x86_l_1ced;
	case 7415ULL: goto x86_l_1cf7;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7436ULL: goto x86_l_1d0c;
	case 7441ULL: goto x86_l_1d11;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7460ULL: goto x86_l_1d24;
	case 7463ULL: goto x86_l_1d27;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7481ULL: goto x86_l_1d39;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7495ULL: goto x86_l_1d47;
	case 7499ULL: goto x86_l_1d4b;
	case 7504ULL: goto x86_l_1d50;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7523ULL: goto x86_l_1d63;
	case 7531ULL: goto x86_l_1d6b;
	case 7533ULL: goto x86_l_1d6d;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7543ULL: goto x86_l_1d77;
	case 7545ULL: goto x86_l_1d79;
	case 7548ULL: goto x86_l_1d7c;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7559ULL: goto x86_l_1d87;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7605ULL: goto x86_l_1db5;
	case 7611ULL: goto x86_l_1dbb;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7627ULL: goto x86_l_1dcb;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7653ULL: goto x86_l_1de5;
	case 7657ULL: goto x86_l_1de9;
	case 7660ULL: goto x86_l_1dec;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7669ULL: goto x86_l_1df5;
	case 7671ULL: goto x86_l_1df7;
	case 7675ULL: goto x86_l_1dfb;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7684ULL: goto x86_l_1e04;
	case 7686ULL: goto x86_l_1e06;
	case 7690ULL: goto x86_l_1e0a;
	case 7700ULL: goto x86_l_1e14;
	case 7703ULL: goto x86_l_1e17;
	case 7708ULL: goto x86_l_1e1c;
	case 7712ULL: goto x86_l_1e20;
	case 7715ULL: goto x86_l_1e23;
	case 7721ULL: goto x86_l_1e29;
	case 7725ULL: goto x86_l_1e2d;
	case 7727ULL: goto x86_l_1e2f;
	case 7729ULL: goto x86_l_1e31;
	case 7732ULL: goto x86_l_1e34;
	case 7738ULL: goto x86_l_1e3a;
	case 7745ULL: goto x86_l_1e41;
	case 7748ULL: goto x86_l_1e44;
	case 7750ULL: goto x86_l_1e46;
	case 7757ULL: goto x86_l_1e4d;
	case 7761ULL: goto x86_l_1e51;
	case 7765ULL: goto x86_l_1e55;
	case 7767ULL: goto x86_l_1e57;
	case 7773ULL: goto x86_l_1e5d;
	case 7778ULL: goto x86_l_1e62;
	case 7780ULL: goto x86_l_1e64;
	case 7784ULL: goto x86_l_1e68;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7792ULL: goto x86_l_1e70;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7801ULL: goto x86_l_1e79;
	case 7806ULL: goto x86_l_1e7e;
	case 7812ULL: goto x86_l_1e84;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7821ULL: goto x86_l_1e8d;
	case 7828ULL: goto x86_l_1e94;
	case 7832ULL: goto x86_l_1e98;
	case 7836ULL: goto x86_l_1e9c;
	case 7841ULL: goto x86_l_1ea1;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7857ULL: goto x86_l_1eb1;
	case 7859ULL: goto x86_l_1eb3;
	case 7863ULL: goto x86_l_1eb7;
	case 7865ULL: goto x86_l_1eb9;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7874ULL: goto x86_l_1ec2;
	case 7878ULL: goto x86_l_1ec6;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7896ULL: goto x86_l_1ed8;
	case 7900ULL: goto x86_l_1edc;
	case 7903ULL: goto x86_l_1edf;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7916ULL: goto x86_l_1eec;
	case 7920ULL: goto x86_l_1ef0;
	case 7923ULL: goto x86_l_1ef3;
	case 7925ULL: goto x86_l_1ef5;
	case 7932ULL: goto x86_l_1efc;
	case 7934ULL: goto x86_l_1efe;
	case 7937ULL: goto x86_l_1f01;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7949ULL: goto x86_l_1f0d;
	case 7952ULL: goto x86_l_1f10;
	case 7954ULL: goto x86_l_1f12;
	case 7956ULL: goto x86_l_1f14;
	case 7959ULL: goto x86_l_1f17;
	case 7961ULL: goto x86_l_1f19;
	case 7965ULL: goto x86_l_1f1d;
	case 7969ULL: goto x86_l_1f21;
	case 7976ULL: goto x86_l_1f28;
	case 7978ULL: goto x86_l_1f2a;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8007ULL: goto x86_l_1f47;
	case 8010ULL: goto x86_l_1f4a;
	case 8012ULL: goto x86_l_1f4c;
	case 8015ULL: goto x86_l_1f4f;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8028ULL: goto x86_l_1f5c;
	case 8034ULL: goto x86_l_1f62;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8058ULL: goto x86_l_1f7a;
	case 8061ULL: goto x86_l_1f7d;
	case 8067ULL: goto x86_l_1f83;
	case 8074ULL: goto x86_l_1f8a;
	case 8078ULL: goto x86_l_1f8e;
	case 8082ULL: goto x86_l_1f92;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8099ULL: goto x86_l_1fa3;
	case 8101ULL: goto x86_l_1fa5;
	case 8108ULL: goto x86_l_1fac;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8121ULL: goto x86_l_1fb9;
	case 8123ULL: goto x86_l_1fbb;
	case 8125ULL: goto x86_l_1fbd;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8133ULL: goto x86_l_1fc5;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8147ULL: goto x86_l_1fd3;
	case 8151ULL: goto x86_l_1fd7;
	case 8153ULL: goto x86_l_1fd9;
	case 8158ULL: goto x86_l_1fde;
	case 8160ULL: goto x86_l_1fe0;
	case 8162ULL: goto x86_l_1fe2;
	case 8166ULL: goto x86_l_1fe6;
	case 8168ULL: goto x86_l_1fe8;
	case 8173ULL: goto x86_l_1fed;
	case 8175ULL: goto x86_l_1fef;
	case 8177ULL: goto x86_l_1ff1;
	case 8181ULL: goto x86_l_1ff5;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8199ULL: goto x86_l_2007;
	case 8203ULL: goto x86_l_200b;
	case 8205ULL: goto x86_l_200d;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8218ULL: goto x86_l_201a;
	case 8222ULL: goto x86_l_201e;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8235ULL: goto x86_l_202b;
	case 8237ULL: goto x86_l_202d;
	case 8240ULL: goto x86_l_2030;
	case 8243ULL: goto x86_l_2033;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8252ULL: goto x86_l_203c;
	case 8255ULL: goto x86_l_203f;
	case 8257ULL: goto x86_l_2041;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8264ULL: goto x86_l_2048;
	case 8268ULL: goto x86_l_204c;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8282ULL: goto x86_l_205a;
	case 8284ULL: goto x86_l_205c;
	case 8289ULL: goto x86_l_2061;
	case 8294ULL: goto x86_l_2066;
	case 8298ULL: goto x86_l_206a;
	case 8303ULL: goto x86_l_206f;
	case 8310ULL: goto x86_l_2076;
	case 8315ULL: goto x86_l_207b;
	case 8320ULL: goto x86_l_2080;
	case 8322ULL: goto x86_l_2082;
	case 8325ULL: goto x86_l_2085;
	case 8327ULL: goto x86_l_2087;
	case 8330ULL: goto x86_l_208a;
	case 8334ULL: goto x86_l_208e;
	case 8340ULL: goto x86_l_2094;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8361ULL: goto x86_l_20a9;
	case 8366ULL: goto x86_l_20ae;
	case 8371ULL: goto x86_l_20b3;
	case 8378ULL: goto x86_l_20ba;
	case 8381ULL: goto x86_l_20bd;
	case 8386ULL: goto x86_l_20c2;
	case 8391ULL: goto x86_l_20c7;
	case 8397ULL: goto x86_l_20cd;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8407ULL: goto x86_l_20d7;
	case 8410ULL: goto x86_l_20da;
	case 8412ULL: goto x86_l_20dc;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8420ULL: goto x86_l_20e4;
	case 8422ULL: goto x86_l_20e6;
	case 8430ULL: goto x86_l_20ee;
	case 8437ULL: goto x86_l_20f5;
	case 8440ULL: goto x86_l_20f8;
	case 8447ULL: goto x86_l_20ff;
	case 8455ULL: goto x86_l_2107;
	case 8460ULL: goto x86_l_210c;
	case 8462ULL: goto x86_l_210e;
	case 8465ULL: goto x86_l_2111;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8492ULL: goto x86_l_212c;
	case 8502ULL: goto x86_l_2136;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8516ULL: goto x86_l_2144;
	case 8520ULL: goto x86_l_2148;
	case 8524ULL: goto x86_l_214c;
	case 8526ULL: goto x86_l_214e;
	case 8529ULL: goto x86_l_2151;
	case 8532ULL: goto x86_l_2154;
	case 8535ULL: goto x86_l_2157;
	case 8540ULL: goto x86_l_215c;
	case 8545ULL: goto x86_l_2161;
	case 8548ULL: goto x86_l_2164;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8557ULL: goto x86_l_216d;
	case 8563ULL: goto x86_l_2173;
	case 8568ULL: goto x86_l_2178;
	case 8572ULL: goto x86_l_217c;
	case 8577ULL: goto x86_l_2181;
	case 8579ULL: goto x86_l_2183;
	case 8584ULL: goto x86_l_2188;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8597ULL: goto x86_l_2195;
	case 8602ULL: goto x86_l_219a;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8652ULL: goto x86_l_21cc;
	case 8655ULL: goto x86_l_21cf;
	case 8662ULL: goto x86_l_21d6;
	case 8672ULL: goto x86_l_21e0;
	case 8678ULL: goto x86_l_21e6;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8691ULL: goto x86_l_21f3;
	case 8696ULL: goto x86_l_21f8;
	case 8701ULL: goto x86_l_21fd;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8711ULL: goto x86_l_2207;
	case 8713ULL: goto x86_l_2209;
	case 8719ULL: goto x86_l_220f;
	case 8727ULL: goto x86_l_2217;
	case 8733ULL: goto x86_l_221d;
	case 8741ULL: goto x86_l_2225;
	case 8748ULL: goto x86_l_222c;
	case 8758ULL: goto x86_l_2236;
	case 8764ULL: goto x86_l_223c;
	case 8769ULL: goto x86_l_2241;
	case 8772ULL: goto x86_l_2244;
	case 8777ULL: goto x86_l_2249;
	case 8784ULL: goto x86_l_2250;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8799ULL: goto x86_l_225f;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8817ULL: goto x86_l_2271;
	case 8822ULL: goto x86_l_2276;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8837ULL: goto x86_l_2285;
	case 8840ULL: goto x86_l_2288;
	case 8846ULL: goto x86_l_228e;
	case 8849ULL: goto x86_l_2291;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8862ULL: goto x86_l_229e;
	case 8867ULL: goto x86_l_22a3;
	case 8872ULL: goto x86_l_22a8;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8898ULL: goto x86_l_22c2;
	case 8903ULL: goto x86_l_22c7;
	case 8905ULL: goto x86_l_22c9;
	case 8907ULL: goto x86_l_22cb;
	case 8909ULL: goto x86_l_22cd;
	case 8913ULL: goto x86_l_22d1;
	case 8918ULL: goto x86_l_22d6;
	case 8922ULL: goto x86_l_22da;
	case 8925ULL: goto x86_l_22dd;
	case 8930ULL: goto x86_l_22e2;
	case 8940ULL: goto x86_l_22ec;
	case 8943ULL: goto x86_l_22ef;
	case 8948ULL: goto x86_l_22f4;
	case 8952ULL: goto x86_l_22f8;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8970ULL: goto x86_l_230a;
	case 8974ULL: goto x86_l_230e;
	case 8979ULL: goto x86_l_2313;
	case 8983ULL: goto x86_l_2317;
	case 8989ULL: goto x86_l_231d;
	case 8991ULL: goto x86_l_231f;
	case 8997ULL: goto x86_l_2325;
	case 9002ULL: goto x86_l_232a;
	case 9006ULL: goto x86_l_232e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1cb7:
	/* 0x1cb7: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cbc:
	/* 0x1cbc: js     231f <tail_handle_ipv6_from_netdev+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_231f;
	}
x86_l_1cc2:
	/* 0x1cc2: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1cc6:
	/* 0x1cc6: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_1ccb:
	/* 0x1ccb: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1ccf:
	/* 0x1ccf: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cd2:
	/* 0x1cd2: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_1cd7:
	/* 0x1cd7: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1ce1:
	/* 0x1ce1: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ce4:
	/* 0x1ce4: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_1ce9:
	/* 0x1ce9: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_1ced:
	/* 0x1ced: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1cf7:
	/* 0x1cf7: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1cfa:
	/* 0x1cfa: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_1cff:
	/* 0x1cff: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_1d03:
	/* 0x1d03: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1d08:
	/* 0x1d08: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d0c:
	/* 0x1d0c: movzx  ebp,BYTE PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_1d11:
	/* 0x1d11: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d19:
	/* 0x1d19: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d1c:
	/* 0x1d1c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d24:
	/* 0x1d24: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1d27:
	/* 0x1d27: ja     233b <tail_handle_ipv6_from_netdev+0x233b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9019ULL;
	}
x86_l_1d2d:
	/* 0x1d2d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1d2f:
	/* 0x1d2f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1d39:
	/* 0x1d39: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d3d:
	/* 0x1d3d: jae    1d97 <tail_handle_ipv6_from_netdev+0x1d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d97;
	}
x86_l_1d3f:
	/* 0x1d3f: mov    rbx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1d47:
	/* 0x1d47: add    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 96ULL);
x86_l_1d4b:
	/* 0x1d4b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d50:
	/* 0x1d50: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1d55:
	/* 0x1d55: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_1d5c:
	/* 0x1d5c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d61:
	/* 0x1d61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d63:
	/* 0x1d63: mov    DWORD PTR [rsp+0x78],0xffffff7a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 519691042682ULL);
x86_l_1d6b:
	/* 0x1d6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d6d:
	/* 0x1d6d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d72:
	/* 0x1d72: js     1dbb <tail_handle_ipv6_from_netdev+0x1dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1dbb;
	}
x86_l_1d74:
	/* 0x1d74: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1d77:
	/* 0x1d77: jle    1dc5 <tail_handle_ipv6_from_netdev+0x1dc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1dc5;
	}
x86_l_1d79:
	/* 0x1d79: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_1d7c:
	/* 0x1d7c: je     22a3 <tail_handle_ipv6_from_netdev+0x22a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a3;
	}
x86_l_1d82:
	/* 0x1d82: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1d85:
	/* 0x1d85: jne    1dc5 <tail_handle_ipv6_from_netdev+0x1dc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dc5;
	}
x86_l_1d87:
	/* 0x1d87: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d92:
	/* 0x1d92: jmp    2325 <tail_handle_ipv6_from_netdev+0x2325> */
	goto x86_l_2325;
x86_l_1d97:
	/* 0x1d97: movzx  ecx,BYTE PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    r14d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_32);
x86_l_1d9f:
	/* 0x1d9f: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_1da3:
	/* 0x1da3: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da8:
	/* 0x1da8: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dad:
	/* 0x1dad: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1db5:
	/* 0x1db5: jne    2350 <tail_handle_ipv6_from_netdev+0x2350> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9040ULL;
	}
x86_l_1dbb:
	/* 0x1dbb: mov    r15d,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1dc0:
	/* 0x1dc0: jmp    2325 <tail_handle_ipv6_from_netdev+0x2325> */
	goto x86_l_2325;
x86_l_1dc5:
	/* 0x1dc5: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_1dcb:
	/* 0x1dcb: cmp    BYTE PTR [rsp+0xe],0x2c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542188ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd5:
	/* 0x1dd5: je     22a8 <tail_handle_ipv6_from_netdev+0x22a8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a8;
	}
x86_l_1ddb:
	/* 0x1ddb: jmp    2325 <tail_handle_ipv6_from_netdev+0x2325> */
	goto x86_l_2325;
x86_l_1de0:
	/* 0x1de0: mov    ebx,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 30ULL);
x86_l_1de5:
	/* 0x1de5: add    ebx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R13, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1de9:
	/* 0x1de9: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dec:
	/* 0x1dec: je     1dfd <tail_handle_ipv6_from_netdev+0x1dfd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dfd;
	}
x86_l_1dee:
	/* 0x1dee: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1df3:
	/* 0x1df3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1df5:
	/* 0x1df5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1df7:
	/* 0x1df7: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1dfb:
	/* 0x1dfb: jmp    1e20 <tail_handle_ipv6_from_netdev+0x1e20> */
	goto x86_l_1e20;
x86_l_1dfd:
	/* 0x1dfd: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1e02:
	/* 0x1e02: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e04:
	/* 0x1e04: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e06:
	/* 0x1e06: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1e0a:
	/* 0x1e0a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1e14:
	/* 0x1e14: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1e17:
	/* 0x1e17: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1e1c:
	/* 0x1e1c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1e20:
	/* 0x1e20: cmp    rax,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_1e23:
	/* 0x1e23: jae    34f6 <tail_handle_ipv6_from_netdev+0x34f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13558ULL;
	}
x86_l_1e29:
	/* 0x1e29: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e2d:
	/* 0x1e2d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e2f:
	/* 0x1e2f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1e31:
	/* 0x1e31: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1e34:
	/* 0x1e34: je     1f2a <tail_handle_ipv6_from_netdev+0x1f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f2a;
	}
x86_l_1e3a:
	/* 0x1e3a: mov    rbx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1e41:
	/* 0x1e41: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e44:
	/* 0x1e44: je     1e57 <tail_handle_ipv6_from_netdev+0x1e57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e57;
	}
x86_l_1e46:
	/* 0x1e46: mov    rcx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e4d:
	/* 0x1e4d: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1e51:
	/* 0x1e51: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e55:
	/* 0x1e55: jmp    1e5d <tail_handle_ipv6_from_netdev+0x1e5d> */
	goto x86_l_1e5d;
x86_l_1e57:
	/* 0x1e57: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1e5d:
	/* 0x1e5d: cmp    BYTE PTR [rsp+0x73],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239046ULL);
x86_l_1e62:
	/* 0x1e62: jne    1e9c <tail_handle_ipv6_from_netdev+0x1e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e9c;
	}
x86_l_1e64:
	/* 0x1e64: mov    ecx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1e68:
	/* 0x1e68: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1e6a:
	/* 0x1e6a: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1e6d:
	/* 0x1e6d: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1e70:
	/* 0x1e70: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e72:
	/* 0x1e72: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e77:
	/* 0x1e77: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_1e79:
	/* 0x1e79: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1e7e:
	/* 0x1e7e: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_1e84:
	/* 0x1e84: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1e88:
	/* 0x1e88: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8b:
	/* 0x1e8b: je     1e9c <tail_handle_ipv6_from_netdev+0x1e9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9c;
	}
x86_l_1e8d:
	/* 0x1e8d: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e94:
	/* 0x1e94: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1e98:
	/* 0x1e98: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e9c:
	/* 0x1e9c: mov    r15d,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1ea1:
	/* 0x1ea1: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ea5:
	/* 0x1ea5: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ea8:
	/* 0x1ea8: je     1eb9 <tail_handle_ipv6_from_netdev+0x1eb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eb9;
	}
x86_l_1eaa:
	/* 0x1eaa: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1eaf:
	/* 0x1eaf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb1:
	/* 0x1eb1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1eb3:
	/* 0x1eb3: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1eb7:
	/* 0x1eb7: jmp    1edc <tail_handle_ipv6_from_netdev+0x1edc> */
	goto x86_l_1edc;
x86_l_1eb9:
	/* 0x1eb9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1ebe:
	/* 0x1ebe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ec0:
	/* 0x1ec0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ec2:
	/* 0x1ec2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1ec6:
	/* 0x1ec6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1ed0:
	/* 0x1ed0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ed3:
	/* 0x1ed3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ed8:
	/* 0x1ed8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1edc:
	/* 0x1edc: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1edf:
	/* 0x1edf: mov    DWORD PTR [r13+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee3:
	/* 0x1ee3: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1ee8:
	/* 0x1ee8: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1eec:
	/* 0x1eec: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1ef0:
	/* 0x1ef0: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ef3:
	/* 0x1ef3: je     1f06 <tail_handle_ipv6_from_netdev+0x1f06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f06;
	}
x86_l_1ef5:
	/* 0x1ef5: mov    rsi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1efc:
	/* 0x1efc: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1efe:
	/* 0x1efe: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1f01:
	/* 0x1f01: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f04:
	/* 0x1f04: jmp    1f0b <tail_handle_ipv6_from_netdev+0x1f0b> */
	goto x86_l_1f0b;
x86_l_1f06:
	/* 0x1f06: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1f0b:
	/* 0x1f0b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f0d:
	/* 0x1f0d: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f10:
	/* 0x1f10: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1f12:
	/* 0x1f12: jb     1f19 <tail_handle_ipv6_from_netdev+0x1f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f19;
	}
x86_l_1f14:
	/* 0x1f14: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_1f17:
	/* 0x1f17: je     1f2a <tail_handle_ipv6_from_netdev+0x1f2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f2a;
	}
x86_l_1f19:
	/* 0x1f19: mov    BYTE PTR [r13+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1f1d:
	/* 0x1f1d: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1f21:
	/* 0x1f21: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f28:
	/* 0x1f28: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f2a:
	/* 0x1f2a: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1f31:
	/* 0x1f31: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f34:
	/* 0x1f34: je     1f47 <tail_handle_ipv6_from_netdev+0x1f47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f47;
	}
x86_l_1f36:
	/* 0x1f36: inc QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f40:
	/* 0x1f40: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f42:
	/* 0x1f42: add QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1f47:
	/* 0x1f47: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1f4a:
	/* 0x1f4a: je     1f97 <tail_handle_ipv6_from_netdev+0x1f97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f97;
	}
x86_l_1f4c:
	/* 0x1f4c: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1f4f:
	/* 0x1f4f: jne    2052 <tail_handle_ipv6_from_netdev+0x2052> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2052;
	}
x86_l_1f55:
	/* 0x1f55: movzx  eax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1f5a:
	/* 0x1f5a: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1f5c:
	/* 0x1f5c: je     2052 <tail_handle_ipv6_from_netdev+0x2052> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2052;
	}
x86_l_1f62:
	/* 0x1f62: mov    WORD PTR [r13+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1f69:
	/* 0x1f69: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1f6e:
	/* 0x1f6e: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f73:
	/* 0x1f73: mov    rbx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1f7a:
	/* 0x1f7a: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7d:
	/* 0x1f7d: je     3417 <tail_handle_ipv6_from_netdev+0x3417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13335ULL;
	}
x86_l_1f83:
	/* 0x1f83: mov    rcx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1f8a:
	/* 0x1f8a: imul   r15d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1f8e:
	/* 0x1f8e: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f92:
	/* 0x1f92: jmp    341d <tail_handle_ipv6_from_netdev+0x341d> */
	return 13341ULL;
x86_l_1f97:
	/* 0x1f97: or     BYTE PTR [r13+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    rbx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1fa3:
	/* 0x1fa3: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa5:
	/* 0x1fa5: mov    r15,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1fac:
	/* 0x1fac: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb0:
	/* 0x1fb0: je     1fc5 <tail_handle_ipv6_from_netdev+0x1fc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fc5;
	}
x86_l_1fb2:
	/* 0x1fb2: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1fb9:
	/* 0x1fb9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fbb:
	/* 0x1fbb: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fbd:
	/* 0x1fbd: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1fc0:
	/* 0x1fc0: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1fc3:
	/* 0x1fc3: jmp    1fca <tail_handle_ipv6_from_netdev+0x1fca> */
	goto x86_l_1fca;
x86_l_1fc5:
	/* 0x1fc5: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1fca:
	/* 0x1fca: mov    r14d,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1fcf:
	/* 0x1fcf: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1fd3:
	/* 0x1fd3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd7:
	/* 0x1fd7: je     1fe8 <tail_handle_ipv6_from_netdev+0x1fe8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fe8;
	}
x86_l_1fd9:
	/* 0x1fd9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1fde:
	/* 0x1fde: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe0:
	/* 0x1fe0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1fe2:
	/* 0x1fe2: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1fe6:
	/* 0x1fe6: jmp    200b <tail_handle_ipv6_from_netdev+0x200b> */
	goto x86_l_200b;
x86_l_1fe8:
	/* 0x1fe8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1fed:
	/* 0x1fed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fef:
	/* 0x1fef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ff1:
	/* 0x1ff1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1ff5:
	/* 0x1ff5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1fff:
	/* 0x1fff: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2002:
	/* 0x2002: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2007:
	/* 0x2007: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_200b:
	/* 0x200b: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_200d:
	/* 0x200d: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2011:
	/* 0x2011: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2016:
	/* 0x2016: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_201a:
	/* 0x201a: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_201e:
	/* 0x201e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2022:
	/* 0x2022: je     2035 <tail_handle_ipv6_from_netdev+0x2035> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2035;
	}
x86_l_2024:
	/* 0x2024: mov    rsi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_202b:
	/* 0x202b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202d:
	/* 0x202d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2030:
	/* 0x2030: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2033:
	/* 0x2033: jmp    203a <tail_handle_ipv6_from_netdev+0x203a> */
	goto x86_l_203a;
x86_l_2035:
	/* 0x2035: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_203a:
	/* 0x203a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_203c:
	/* 0x203c: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_203f:
	/* 0x203f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2041:
	/* 0x2041: jb     2048 <tail_handle_ipv6_from_netdev+0x2048> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2048;
	}
x86_l_2043:
	/* 0x2043: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_2046:
	/* 0x2046: je     2052 <tail_handle_ipv6_from_netdev+0x2052> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2052;
	}
x86_l_2048:
	/* 0x2048: mov    BYTE PTR [r13+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_204c:
	/* 0x204c: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2050:
	/* 0x2050: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2052:
	/* 0x2052: test   BYTE PTR [rsp+0xc5],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 846108557314ULL);
x86_l_205a:
	/* 0x205a: jne    20a3 <tail_handle_ipv6_from_netdev+0x20a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20a3;
	}
x86_l_205c:
	/* 0x205c: movzx  eax,WORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2061:
	/* 0x2061: mov    WORD PTR [rsp+0xe],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2066:
	/* 0x2066: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_206a:
	/* 0x206a: mov    DWORD PTR [rsp+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_206f:
	/* 0x206f: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_2076:
	/* 0x2076: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_207b:
	/* 0x207b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2080:
	/* 0x2080: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2082:
	/* 0x2082: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2085:
	/* 0x2085: je     20b3 <tail_handle_ipv6_from_netdev+0x20b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20b3;
	}
x86_l_2087:
	/* 0x2087: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_208a:
	/* 0x208a: cmp    BYTE PTR [rax+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_208e:
	/* 0x208e: je     3898 <tail_handle_ipv6_from_netdev+0x3898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14488ULL;
	}
x86_l_2094:
	/* 0x2094: test   DWORD PTR [rsp+0x74],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206848ULL);
x86_l_209c:
	/* 0x209c: jne    20bd <tail_handle_ipv6_from_netdev+0x20bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20bd;
	}
x86_l_209e:
	/* 0x209e: jmp    3898 <tail_handle_ipv6_from_netdev+0x3898> */
	return 14488ULL;
x86_l_20a3:
	/* 0x20a3: mov    r15d,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967133ULL);
x86_l_20a9:
	/* 0x20a9: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20ae:
	/* 0x20ae: jmp    3c59 <tail_handle_ipv6_from_netdev+0x3c59> */
	return 15449ULL;
x86_l_20b3:
	/* 0x20b3: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_20ba:
	/* 0x20ba: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20bd:
	/* 0x20bd: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c2:
	/* 0x20c2: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_20c7:
	/* 0x20c7: je     375e <tail_handle_ipv6_from_netdev+0x375e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14174ULL;
	}
x86_l_20cd:
	/* 0x20cd: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d0:
	/* 0x20d0: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_20d5:
	/* 0x20d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d7:
	/* 0x20d7: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_20da:
	/* 0x20da: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_20dc:
	/* 0x20dc: movzx  ecx,WORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_20e0:
	/* 0x20e0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e2:
	/* 0x20e2: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_20e4:
	/* 0x20e4: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_20e6:
	/* 0x20e6: mov    WORD PTR [rsp+0xda],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 218ULL);
x86_l_20ee:
	/* 0x20ee: mov    rbx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_20f5:
	/* 0x20f5: movzx  eax,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20f8:
	/* 0x20f8: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_20ff:
	/* 0x20ff: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2107:
	/* 0x2107: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_210c:
	/* 0x210c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_210e:
	/* 0x210e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2111:
	/* 0x2111: je     2241 <tail_handle_ipv6_from_netdev+0x2241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2241;
	}
x86_l_2117:
	/* 0x2117: mov    r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_211a:
	/* 0x211a: jmp    2244 <tail_handle_ipv6_from_netdev+0x2244> */
	goto x86_l_2244;
x86_l_211f:
	/* 0x211f: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_2125:
	/* 0x2125: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_212c:
	/* 0x212c: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2136:
	/* 0x2136: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2139:
	/* 0x2139: cmp    DWORD PTR [rsp+0x10],0x3c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476796ULL);
x86_l_213e:
	/* 0x213e: ja     282b <tail_handle_ipv6_from_netdev+0x282b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10283ULL;
	}
x86_l_2144:
	/* 0x2144: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2148:
	/* 0x2148: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_214c:
	/* 0x214c: jae    21a6 <tail_handle_ipv6_from_netdev+0x21a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_21a6;
	}
x86_l_214e:
	/* 0x214e: add    r14d,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2151:
	/* 0x2151: mov    ebx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R14, X86_WIDTH_32);
x86_l_2154:
	/* 0x2154: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2157:
	/* 0x2157: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_215c:
	/* 0x215c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2161:
	/* 0x2161: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2164:
	/* 0x2164: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2169:
	/* 0x2169: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_216b:
	/* 0x216b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_216d:
	/* 0x216d: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9979ULL;
	}
x86_l_2173:
	/* 0x2173: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_2178:
	/* 0x2178: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_217c:
	/* 0x217c: cmp    DWORD PTR [rsp+0x10],0x2b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476779ULL);
x86_l_2181:
	/* 0x2181: jle    21b5 <tail_handle_ipv6_from_netdev+0x21b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_21b5;
	}
x86_l_2183:
	/* 0x2183: cmp    DWORD PTR [rsp+0x10],0x2c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476780ULL);
x86_l_2188:
	/* 0x2188: je     25fa <tail_handle_ipv6_from_netdev+0x25fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9722ULL;
	}
x86_l_218e:
	/* 0x218e: cmp    DWORD PTR [rsp+0x10],0x33 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476787ULL);
x86_l_2193:
	/* 0x2193: jne    21b5 <tail_handle_ipv6_from_netdev+0x21b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21b5;
	}
x86_l_2195:
	/* 0x2195: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_219a:
	/* 0x219a: lea    ebp,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_21a1:
	/* 0x21a1: jmp    25ff <tail_handle_ipv6_from_netdev+0x25ff> */
	return 9727ULL;
x86_l_21a6:
	/* 0x21a6: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_21aa:
	/* 0x21aa: je     270d <tail_handle_ipv6_from_netdev+0x270d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9997ULL;
	}
x86_l_21b0:
	/* 0x21b0: jmp    282b <tail_handle_ipv6_from_netdev+0x282b> */
	return 10283ULL;
x86_l_21b5:
	/* 0x21b5: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_21ba:
	/* 0x21ba: lea    ebp,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_21c1:
	/* 0x21c1: cmp    DWORD PTR [rsp+0x10],0x3c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476796ULL);
x86_l_21c6:
	/* 0x21c6: jne    25ff <tail_handle_ipv6_from_netdev+0x25ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9727ULL;
	}
x86_l_21cc:
	/* 0x21cc: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_21cf:
	/* 0x21cf: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_21d6:
	/* 0x21d6: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_21e0:
	/* 0x21e0: jne    2610 <tail_handle_ipv6_from_netdev+0x2610> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9744ULL;
	}
x86_l_21e6:
	/* 0x21e6: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21e9:
	/* 0x21e9: add    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21eb:
	/* 0x21eb: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_21f3:
	/* 0x21f3: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_21f8:
	/* 0x21f8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_21fd:
	/* 0x21fd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_2200:
	/* 0x2200: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_2205:
	/* 0x2205: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2207:
	/* 0x2207: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2209:
	/* 0x2209: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9979ULL;
	}
x86_l_220f:
	/* 0x220f: cmp    BYTE PTR [rsp+0x8a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 592705486875ULL);
x86_l_2217:
	/* 0x2217: jne    25ff <tail_handle_ipv6_from_netdev+0x25ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9727ULL;
	}
x86_l_221d:
	/* 0x221d: cmp    BYTE PTR [rsp+0x8b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 597000454164ULL);
x86_l_2225:
	/* 0x2225: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_222c:
	/* 0x222c: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2236:
	/* 0x2236: je     26c4 <tail_handle_ipv6_from_netdev+0x26c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9924ULL;
	}
x86_l_223c:
	/* 0x223c: jmp    2610 <tail_handle_ipv6_from_netdev+0x2610> */
	return 9744ULL;
x86_l_2241:
	/* 0x2241: movzx  eax,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2244:
	/* 0x2244: mov    DWORD PTR [rsp+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2249:
	/* 0x2249: mov    rdi,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_2250:
	/* 0x2250: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2255:
	/* 0x2255: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_225a:
	/* 0x225a: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_225c:
	/* 0x225c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_225f:
	/* 0x225f: je     3754 <tail_handle_ipv6_from_netdev+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14164ULL;
	}
x86_l_2265:
	/* 0x2265: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2268:
	/* 0x2268: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_226d:
	/* 0x226d: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2271:
	/* 0x2271: mov    WORD PTR [rsp+0xe],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2276:
	/* 0x2276: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_227e:
	/* 0x227e: mov    rdi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2283:
	/* 0x2283: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_2285:
	/* 0x2285: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2288:
	/* 0x2288: je     3898 <tail_handle_ipv6_from_netdev+0x3898> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14488ULL;
	}
x86_l_228e:
	/* 0x228e: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_2291:
	/* 0x2291: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2295:
	/* 0x2295: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_229a:
	/* 0x229a: mov    WORD PTR [rax+0x26],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_229e:
	/* 0x229e: jmp    3898 <tail_handle_ipv6_from_netdev+0x3898> */
	return 14488ULL;
x86_l_22a3:
	/* 0x22a3: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a8:
	/* 0x22a8: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_22b1:
	/* 0x22b1: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22b6:
	/* 0x22b6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_22bb:
	/* 0x22bb: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22c0:
	/* 0x22c0: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_22c2:
	/* 0x22c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22c7:
	/* 0x22c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c9:
	/* 0x22c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22cb:
	/* 0x22cb: js     231f <tail_handle_ipv6_from_netdev+0x231f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_231f;
	}
x86_l_22cd:
	/* 0x22cd: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_22d1:
	/* 0x22d1: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_22d6:
	/* 0x22d6: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_22da:
	/* 0x22da: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22dd:
	/* 0x22dd: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_22e2:
	/* 0x22e2: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_22ec:
	/* 0x22ec: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22ef:
	/* 0x22ef: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_22f4:
	/* 0x22f4: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_22f8:
	/* 0x22f8: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2302:
	/* 0x2302: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2305:
	/* 0x2305: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_230a:
	/* 0x230a: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_230e:
	/* 0x230e: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2313:
	/* 0x2313: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2317:
	/* 0x2317: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_231d:
	/* 0x231d: jmp    2325 <tail_handle_ipv6_from_netdev+0x2325> */
	goto x86_l_2325;
x86_l_231f:
	/* 0x231f: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_2325:
	/* 0x2325: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_232a:
	/* 0x232a: mov    DWORD PTR [rax+0x4c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_232e:
	/* 0x232e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
	return 9009ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9019ULL: goto x86_l_233b;
	case 9024ULL: goto x86_l_2340;
	case 9027ULL: goto x86_l_2343;
	case 9032ULL: goto x86_l_2348;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9049ULL: goto x86_l_2359;
	case 9052ULL: goto x86_l_235c;
	case 9054ULL: goto x86_l_235e;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9063ULL: goto x86_l_2367;
	case 9070ULL: goto x86_l_236e;
	case 9072ULL: goto x86_l_2370;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9094ULL: goto x86_l_2386;
	case 9104ULL: goto x86_l_2390;
	case 9109ULL: goto x86_l_2395;
	case 9113ULL: goto x86_l_2399;
	case 9117ULL: goto x86_l_239d;
	case 9123ULL: goto x86_l_23a3;
	case 9127ULL: goto x86_l_23a7;
	case 9130ULL: goto x86_l_23aa;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9142ULL: goto x86_l_23b6;
	case 9148ULL: goto x86_l_23bc;
	case 9158ULL: goto x86_l_23c6;
	case 9168ULL: goto x86_l_23d0;
	case 9171ULL: goto x86_l_23d3;
	case 9177ULL: goto x86_l_23d9;
	case 9185ULL: goto x86_l_23e1;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9204ULL: goto x86_l_23f4;
	case 9210ULL: goto x86_l_23fa;
	case 9212ULL: goto x86_l_23fc;
	case 9218ULL: goto x86_l_2402;
	case 9226ULL: goto x86_l_240a;
	case 9228ULL: goto x86_l_240c;
	case 9230ULL: goto x86_l_240e;
	case 9233ULL: goto x86_l_2411;
	case 9241ULL: goto x86_l_2419;
	case 9246ULL: goto x86_l_241e;
	case 9251ULL: goto x86_l_2423;
	case 9256ULL: goto x86_l_2428;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9266ULL: goto x86_l_2432;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9304ULL: goto x86_l_2458;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9321ULL: goto x86_l_2469;
	case 9326ULL: goto x86_l_246e;
	case 9332ULL: goto x86_l_2474;
	case 9340ULL: goto x86_l_247c;
	case 9345ULL: goto x86_l_2481;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9363ULL: goto x86_l_2493;
	case 9370ULL: goto x86_l_249a;
	case 9373ULL: goto x86_l_249d;
	case 9379ULL: goto x86_l_24a3;
	case 9383ULL: goto x86_l_24a7;
	case 9391ULL: goto x86_l_24af;
	case 9394ULL: goto x86_l_24b2;
	case 9398ULL: goto x86_l_24b6;
	case 9401ULL: goto x86_l_24b9;
	case 9405ULL: goto x86_l_24bd;
	case 9409ULL: goto x86_l_24c1;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9431ULL: goto x86_l_24d7;
	case 9433ULL: goto x86_l_24d9;
	case 9438ULL: goto x86_l_24de;
	case 9443ULL: goto x86_l_24e3;
	case 9445ULL: goto x86_l_24e5;
	case 9447ULL: goto x86_l_24e7;
	case 9449ULL: goto x86_l_24e9;
	case 9459ULL: goto x86_l_24f3;
	case 9462ULL: goto x86_l_24f6;
	case 9468ULL: goto x86_l_24fc;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9484ULL: goto x86_l_250c;
	case 9487ULL: goto x86_l_250f;
	case 9489ULL: goto x86_l_2511;
	case 9494ULL: goto x86_l_2516;
	case 9501ULL: goto x86_l_251d;
	case 9506ULL: goto x86_l_2522;
	case 9509ULL: goto x86_l_2525;
	case 9515ULL: goto x86_l_252b;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9528ULL: goto x86_l_2538;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9542ULL: goto x86_l_2546;
	case 9544ULL: goto x86_l_2548;
	case 9550ULL: goto x86_l_254e;
	case 9556ULL: goto x86_l_2554;
	case 9558ULL: goto x86_l_2556;
	case 9564ULL: goto x86_l_255c;
	case 9568ULL: goto x86_l_2560;
	case 9570ULL: goto x86_l_2562;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9585ULL: goto x86_l_2571;
	case 9590ULL: goto x86_l_2576;
	case 9593ULL: goto x86_l_2579;
	case 9599ULL: goto x86_l_257f;
	case 9602ULL: goto x86_l_2582;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9624ULL: goto x86_l_2598;
	case 9633ULL: goto x86_l_25a1;
	case 9643ULL: goto x86_l_25ab;
	case 9649ULL: goto x86_l_25b1;
	case 9657ULL: goto x86_l_25b9;
	case 9664ULL: goto x86_l_25c0;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9679ULL: goto x86_l_25cf;
	case 9682ULL: goto x86_l_25d2;
	case 9688ULL: goto x86_l_25d8;
	case 9691ULL: goto x86_l_25db;
	case 9695ULL: goto x86_l_25df;
	case 9700ULL: goto x86_l_25e4;
	case 9708ULL: goto x86_l_25ec;
	case 9713ULL: goto x86_l_25f1;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9734ULL: goto x86_l_2606;
	case 9744ULL: goto x86_l_2610;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9767ULL: goto x86_l_2627;
	case 9773ULL: goto x86_l_262d;
	case 9775ULL: goto x86_l_262f;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9790ULL: goto x86_l_263e;
	case 9795ULL: goto x86_l_2643;
	case 9797ULL: goto x86_l_2645;
	case 9803ULL: goto x86_l_264b;
	case 9805ULL: goto x86_l_264d;
	case 9811ULL: goto x86_l_2653;
	case 9821ULL: goto x86_l_265d;
	case 9825ULL: goto x86_l_2661;
	case 9831ULL: goto x86_l_2667;
	case 9833ULL: goto x86_l_2669;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9850ULL: goto x86_l_267a;
	case 9855ULL: goto x86_l_267f;
	case 9861ULL: goto x86_l_2685;
	case 9868ULL: goto x86_l_268c;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9881ULL: goto x86_l_2699;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9891ULL: goto x86_l_26a3;
	case 9896ULL: goto x86_l_26a8;
	case 9898ULL: goto x86_l_26aa;
	case 9900ULL: goto x86_l_26ac;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9912ULL: goto x86_l_26b8;
	case 9914ULL: goto x86_l_26ba;
	case 9922ULL: goto x86_l_26c2;
	case 9924ULL: goto x86_l_26c4;
	case 9932ULL: goto x86_l_26cc;
	case 9940ULL: goto x86_l_26d4;
	case 9948ULL: goto x86_l_26dc;
	case 9956ULL: goto x86_l_26e4;
	case 9964ULL: goto x86_l_26ec;
	case 9972ULL: goto x86_l_26f4;
	case 9975ULL: goto x86_l_26f7;
	case 9977ULL: goto x86_l_26f9;
	case 9979ULL: goto x86_l_26fb;
	case 9985ULL: goto x86_l_2701;
	case 9987ULL: goto x86_l_2703;
	case 9991ULL: goto x86_l_2707;
	case 9997ULL: goto x86_l_270d;
	case 9999ULL: goto x86_l_270f;
	case 10007ULL: goto x86_l_2717;
	case 10010ULL: goto x86_l_271a;
	case 10013ULL: goto x86_l_271d;
	case 10016ULL: goto x86_l_2720;
	case 10022ULL: goto x86_l_2726;
	case 10024ULL: goto x86_l_2728;
	case 10029ULL: goto x86_l_272d;
	case 10035ULL: goto x86_l_2733;
	case 10043ULL: goto x86_l_273b;
	case 10051ULL: goto x86_l_2743;
	case 10059ULL: goto x86_l_274b;
	case 10067ULL: goto x86_l_2753;
	case 10075ULL: goto x86_l_275b;
	case 10083ULL: goto x86_l_2763;
	case 10091ULL: goto x86_l_276b;
	case 10099ULL: goto x86_l_2773;
	case 10107ULL: goto x86_l_277b;
	case 10115ULL: goto x86_l_2783;
	case 10120ULL: goto x86_l_2788;
	case 10128ULL: goto x86_l_2790;
	case 10132ULL: goto x86_l_2794;
	case 10134ULL: goto x86_l_2796;
	case 10141ULL: goto x86_l_279d;
	case 10143ULL: goto x86_l_279f;
	case 10150ULL: goto x86_l_27a6;
	case 10158ULL: goto x86_l_27ae;
	case 10166ULL: goto x86_l_27b6;
	case 10173ULL: goto x86_l_27bd;
	case 10176ULL: goto x86_l_27c0;
	case 10182ULL: goto x86_l_27c6;
	case 10192ULL: goto x86_l_27d0;
	case 10195ULL: goto x86_l_27d3;
	case 10201ULL: goto x86_l_27d9;
	case 10204ULL: goto x86_l_27dc;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10220ULL: goto x86_l_27ec;
	case 10229ULL: goto x86_l_27f5;
	case 10239ULL: goto x86_l_27ff;
	case 10247ULL: goto x86_l_2807;
	case 10254ULL: goto x86_l_280e;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10269ULL: goto x86_l_281d;
	case 10272ULL: goto x86_l_2820;
	case 10274ULL: goto x86_l_2822;
	case 10277ULL: goto x86_l_2825;
	case 10281ULL: goto x86_l_2829;
	case 10283ULL: goto x86_l_282b;
	case 10291ULL: goto x86_l_2833;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10308ULL: goto x86_l_2844;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10329ULL: goto x86_l_2859;
	case 10334ULL: goto x86_l_285e;
	case 10341ULL: goto x86_l_2865;
	case 10349ULL: goto x86_l_286d;
	case 10354ULL: goto x86_l_2872;
	case 10359ULL: goto x86_l_2877;
	case 10361ULL: goto x86_l_2879;
	case 10363ULL: goto x86_l_287b;
	case 10366ULL: goto x86_l_287e;
	case 10370ULL: goto x86_l_2882;
	case 10372ULL: goto x86_l_2884;
	case 10382ULL: goto x86_l_288e;
	case 10385ULL: goto x86_l_2891;
	case 10387ULL: goto x86_l_2893;
	case 10390ULL: goto x86_l_2896;
	case 10393ULL: goto x86_l_2899;
	case 10398ULL: goto x86_l_289e;
	case 10403ULL: goto x86_l_28a3;
	case 10408ULL: goto x86_l_28a8;
	case 10413ULL: goto x86_l_28ad;
	case 10415ULL: goto x86_l_28af;
	case 10417ULL: goto x86_l_28b1;
	case 10423ULL: goto x86_l_28b7;
	case 10427ULL: goto x86_l_28bb;
	case 10429ULL: goto x86_l_28bd;
	case 10434ULL: goto x86_l_28c2;
	case 10437ULL: goto x86_l_28c5;
	case 10442ULL: goto x86_l_28ca;
	case 10445ULL: goto x86_l_28cd;
	case 10447ULL: goto x86_l_28cf;
	case 10453ULL: goto x86_l_28d5;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10464ULL: goto x86_l_28e0;
	case 10467ULL: goto x86_l_28e3;
	case 10471ULL: goto x86_l_28e7;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10487ULL: goto x86_l_28f7;
	case 10489ULL: goto x86_l_28f9;
	case 10492ULL: goto x86_l_28fc;
	case 10494ULL: goto x86_l_28fe;
	case 10497ULL: goto x86_l_2901;
	case 10501ULL: goto x86_l_2905;
	case 10503ULL: goto x86_l_2907;
	case 10505ULL: goto x86_l_2909;
	case 10512ULL: goto x86_l_2910;
	case 10514ULL: goto x86_l_2912;
	case 10520ULL: goto x86_l_2918;
	case 10522ULL: goto x86_l_291a;
	case 10531ULL: goto x86_l_2923;
	case 10536ULL: goto x86_l_2928;
	case 10538ULL: goto x86_l_292a;
	case 10540ULL: goto x86_l_292c;
	case 10543ULL: goto x86_l_292f;
	case 10549ULL: goto x86_l_2935;
	case 10556ULL: goto x86_l_293c;
	case 10559ULL: goto x86_l_293f;
	case 10565ULL: goto x86_l_2945;
	case 10572ULL: goto x86_l_294c;
	case 10576ULL: goto x86_l_2950;
	case 10580ULL: goto x86_l_2954;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10594ULL: goto x86_l_2962;
	case 10597ULL: goto x86_l_2965;
	case 10602ULL: goto x86_l_296a;
	case 10607ULL: goto x86_l_296f;
	case 10612ULL: goto x86_l_2974;
	case 10619ULL: goto x86_l_297b;
	case 10624ULL: goto x86_l_2980;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10634ULL: goto x86_l_298a;
	case 10636ULL: goto x86_l_298c;
	case 10640ULL: goto x86_l_2990;
	case 10643ULL: goto x86_l_2993;
	case 10648ULL: goto x86_l_2998;
	case 10655ULL: goto x86_l_299f;
	case 10659ULL: goto x86_l_29a3;
	case 10666ULL: goto x86_l_29aa;
	case 10672ULL: goto x86_l_29b0;
	case 10677ULL: goto x86_l_29b5;
	case 10680ULL: goto x86_l_29b8;
	case 10685ULL: goto x86_l_29bd;
	case 10690ULL: goto x86_l_29c2;
	case 10696ULL: goto x86_l_29c8;
	case 10700ULL: goto x86_l_29cc;
	case 10702ULL: goto x86_l_29ce;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10712ULL: goto x86_l_29d8;
	case 10714ULL: goto x86_l_29da;
	case 10719ULL: goto x86_l_29df;
	case 10721ULL: goto x86_l_29e1;
	case 10726ULL: goto x86_l_29e6;
	case 10732ULL: goto x86_l_29ec;
	case 10736ULL: goto x86_l_29f0;
	case 10743ULL: goto x86_l_29f7;
	case 10746ULL: goto x86_l_29fa;
	case 10748ULL: goto x86_l_29fc;
	case 10755ULL: goto x86_l_2a03;
	case 10759ULL: goto x86_l_2a07;
	case 10763ULL: goto x86_l_2a0b;
	case 10766ULL: goto x86_l_2a0e;
	case 10770ULL: goto x86_l_2a12;
	case 10777ULL: goto x86_l_2a19;
	case 10780ULL: goto x86_l_2a1c;
	case 10782ULL: goto x86_l_2a1e;
	case 10787ULL: goto x86_l_2a23;
	case 10789ULL: goto x86_l_2a25;
	case 10791ULL: goto x86_l_2a27;
	case 10795ULL: goto x86_l_2a2b;
	case 10797ULL: goto x86_l_2a2d;
	case 10802ULL: goto x86_l_2a32;
	case 10804ULL: goto x86_l_2a34;
	case 10806ULL: goto x86_l_2a36;
	case 10810ULL: goto x86_l_2a3a;
	case 10820ULL: goto x86_l_2a44;
	case 10823ULL: goto x86_l_2a47;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2331:
	/* 0x2331: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2336:
	/* 0x2336: jmp    5a7 <tail_handle_ipv6_from_netdev+0x5a7> */
	return 1447ULL;
x86_l_233b:
	/* 0x233b: movzx  eax,BYTE PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_2340:
	/* 0x2340: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_2343:
	/* 0x2343: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2348:
	/* 0x2348: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2350:
	/* 0x2350: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2355:
	/* 0x2355: mov    BYTE PTR [rcx+0x24],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2359:
	/* 0x2359: movzx  ebp,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_235c:
	/* 0x235c: add    ebp,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_235e:
	/* 0x235e: mov    DWORD PTR [rcx+0x50],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2361:
	/* 0x2361: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_2365:
	/* 0x2365: jne    2370 <tail_handle_ipv6_from_netdev+0x2370> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2370;
	}
x86_l_2367:
	/* 0x2367: mov    rdx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_236e:
	/* 0x236e: jmp    2377 <tail_handle_ipv6_from_netdev+0x2377> */
	goto x86_l_2377;
x86_l_2370:
	/* 0x2370: mov    rdx,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_2377:
	/* 0x2377: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_237c:
	/* 0x237c: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2386:
	/* 0x2386: movabs rsi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1099511627776ULL);
x86_l_2390:
	/* 0x2390: mov    QWORD PTR [rsp+0x60],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2395:
	/* 0x2395: mov    r12,QWORD PTR [rcx+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2399:
	/* 0x2399: mov    BYTE PTR [rcx+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_239d:
	/* 0x239d: je     248a <tail_handle_ipv6_from_netdev+0x248a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_248a;
	}
x86_l_23a3:
	/* 0x23a3: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23a7:
	/* 0x23a7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_23aa:
	/* 0x23aa: je     248a <tail_handle_ipv6_from_netdev+0x248a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_248a;
	}
x86_l_23b0:
	/* 0x23b0: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_23b3:
	/* 0x23b3: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_23b6:
	/* 0x23b6: jne    2505 <tail_handle_ipv6_from_netdev+0x2505> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2505;
	}
x86_l_23bc:
	/* 0x23bc: mov    WORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_23c6:
	/* 0x23c6: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_23d0:
	/* 0x23d0: test   r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_23d3:
	/* 0x23d3: jne    3341 <tail_handle_ipv6_from_netdev+0x3341> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13121ULL;
	}
x86_l_23d9:
	/* 0x23d9: lea    rdx,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_23e1:
	/* 0x23e1: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_23e6:
	/* 0x23e6: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23eb:
	/* 0x23eb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_23ed:
	/* 0x23ed: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_23f2:
	/* 0x23f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f4:
	/* 0x23f4: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_23fa:
	/* 0x23fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23fc:
	/* 0x23fc: js     2568 <tail_handle_ipv6_from_netdev+0x2568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2568;
	}
x86_l_2402:
	/* 0x2402: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_240a:
	/* 0x240a: cmp    al,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 129ULL);
x86_l_240c:
	/* 0x240c: jg     243a <tail_handle_ipv6_from_netdev+0x243a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_243a;
	}
x86_l_240e:
	/* 0x240e: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2411:
	/* 0x2411: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2419:
	/* 0x2419: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_241e:
	/* 0x241e: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2423:
	/* 0x2423: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2428:
	/* 0x2428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_242a:
	/* 0x242a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_242c:
	/* 0x242c: js     2568 <tail_handle_ipv6_from_netdev+0x2568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2568;
	}
x86_l_2432:
	/* 0x2432: movzx  eax,BYTE PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 200ULL);
x86_l_243a:
	/* 0x243a: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_243f:
	/* 0x243f: mov    DWORD PTR [rcx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2446:
	/* 0x2446: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2449:
	/* 0x2449: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_244c:
	/* 0x244c: jle    2576 <tail_handle_ipv6_from_netdev+0x2576> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2576;
	}
x86_l_2452:
	/* 0x2452: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_2455:
	/* 0x2455: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2458:
	/* 0x2458: jb     2dfb <tail_handle_ipv6_from_netdev+0x2dfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11771ULL;
	}
x86_l_245e:
	/* 0x245e: cmp    eax,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_2463:
	/* 0x2463: je     25e4 <tail_handle_ipv6_from_netdev+0x25e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25e4;
	}
x86_l_2469:
	/* 0x2469: cmp    eax,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 129ULL);
x86_l_246e:
	/* 0x246e: jne    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11780ULL;
	}
x86_l_2474:
	/* 0x2474: movzx  eax,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_247c:
	/* 0x247c: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2481:
	/* 0x2481: mov    WORD PTR [rcx+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2485:
	/* 0x2485: jmp    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	return 11780ULL;
x86_l_248a:
	/* 0x248a: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_248e:
	/* 0x248e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2493:
	/* 0x2493: mov    rax,QWORD PTR [rip+0x1bdc6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_249a:
	/* 0x249a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_249d:
	/* 0x249d: je     2522 <tail_handle_ipv6_from_netdev+0x2522> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2522;
	}
x86_l_24a3:
	/* 0x24a3: mov    rbx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a7:
	/* 0x24a7: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24af:
	/* 0x24af: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_24b2:
	/* 0x24b2: mov    DWORD PTR [r13+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b6:
	/* 0x24b6: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_24b9:
	/* 0x24b9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_24bd:
	/* 0x24bd: mov    BYTE PTR [r13+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24c1:
	/* 0x24c1: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_24c4:
	/* 0x24c4: test   r12,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_24c7:
	/* 0x24c7: jne    330e <tail_handle_ipv6_from_netdev+0x330e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13070ULL;
	}
x86_l_24cd:
	/* 0x24cd: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_24d2:
	/* 0x24d2: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24d7:
	/* 0x24d7: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24d9:
	/* 0x24d9: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24de:
	/* 0x24de: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_24e3:
	/* 0x24e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24e5:
	/* 0x24e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24e7:
	/* 0x24e7: js     2556 <tail_handle_ipv6_from_netdev+0x2556> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2556;
	}
x86_l_24e9:
	/* 0x24e9: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_24f3:
	/* 0x24f3: test   r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_24f6:
	/* 0x24f6: jne    334c <tail_handle_ipv6_from_netdev+0x334c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13132ULL;
	}
x86_l_24fc:
	/* 0x24fc: mov    QWORD PTR [r13+0x0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2500:
	/* 0x2500: jmp    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	return 11780ULL;
x86_l_2505:
	/* 0x2505: mov    rax,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_extended_ip_protocols)));
x86_l_250c:
	/* 0x250c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250f:
	/* 0x250f: je     2562 <tail_handle_ipv6_from_netdev+0x2562> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2562;
	}
x86_l_2511:
	/* 0x2511: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2516:
	/* 0x2516: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_251d:
	/* 0x251d: jmp    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	return 11780ULL;
x86_l_2522:
	/* 0x2522: test   r12,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_2525:
	/* 0x2525: jne    33c3 <tail_handle_ipv6_from_netdev+0x33c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13251ULL;
	}
x86_l_252b:
	/* 0x252b: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_252e:
	/* 0x252e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2533:
	/* 0x2533: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2538:
	/* 0x2538: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_253a:
	/* 0x253a: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_253f:
	/* 0x253f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2544:
	/* 0x2544: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2546:
	/* 0x2546: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2548:
	/* 0x2548: jns    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11780ULL;
	}
x86_l_254e:
	/* 0x254e: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_2554:
	/* 0x2554: jmp    2568 <tail_handle_ipv6_from_netdev+0x2568> */
	goto x86_l_2568;
x86_l_2556:
	/* 0x2556: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_255c:
	/* 0x255c: mov    QWORD PTR [r13+0x0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2560:
	/* 0x2560: jmp    2568 <tail_handle_ipv6_from_netdev+0x2568> */
	goto x86_l_2568;
x86_l_2562:
	/* 0x2562: mov    r15d,0xffffff77 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967159ULL);
x86_l_2568:
	/* 0x2568: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_256d:
	/* 0x256d: mov    DWORD PTR [rax+0x4c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2571:
	/* 0x2571: jmp    2f7b <tail_handle_ipv6_from_netdev+0x2f7b> */
	return 12155ULL;
x86_l_2576:
	/* 0x2576: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2579:
	/* 0x2579: je     2dfb <tail_handle_ipv6_from_netdev+0x2dfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11771ULL;
	}
x86_l_257f:
	/* 0x257f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2582:
	/* 0x2582: jne    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11780ULL;
	}
x86_l_2588:
	/* 0x2588: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258d:
	/* 0x258d: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258f:
	/* 0x258f: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2598:
	/* 0x2598: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_25a1:
	/* 0x25a1: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_25ab:
	/* 0x25ab: add    rax,0xffffffffffc5ff06 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073705750278ULL);
x86_l_25b1:
	/* 0x25b1: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_25b9:
	/* 0x25b9: mov    rdi,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_25c0:
	/* 0x25c0: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_25c8:
	/* 0x25c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25cd:
	/* 0x25cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25cf:
	/* 0x25cf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25d2:
	/* 0x25d2: je     2dd0 <tail_handle_ipv6_from_netdev+0x2dd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11728ULL;
	}
x86_l_25d8:
	/* 0x25d8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_25db:
	/* 0x25db: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_25df:
	/* 0x25df: jmp    2dfb <tail_handle_ipv6_from_netdev+0x2dfb> */
	return 11771ULL;
x86_l_25e4:
	/* 0x25e4: movzx  eax,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_25ec:
	/* 0x25ec: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25f1:
	/* 0x25f1: mov    WORD PTR [rcx+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25f5:
	/* 0x25f5: jmp    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	return 11780ULL;
x86_l_25fa:
	/* 0x25fa: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_25ff:
	/* 0x25ff: mov    rax,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2606:
	/* 0x2606: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2610:
	/* 0x2610: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2613:
	/* 0x2613: cmp    DWORD PTR [rsp+0x78],0x3c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075580ULL);
x86_l_2618:
	/* 0x2618: ja     282b <tail_handle_ipv6_from_netdev+0x282b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_282b;
	}
x86_l_261e:
	/* 0x261e: mov    r14d,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2623:
	/* 0x2623: bt     rcx,r14 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2627:
	/* 0x2627: jae    2703 <tail_handle_ipv6_from_netdev+0x2703> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2703;
	}
x86_l_262d:
	/* 0x262d: add    ebp,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_262f:
	/* 0x262f: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2631:
	/* 0x2631: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2636:
	/* 0x2636: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_263b:
	/* 0x263b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_263e:
	/* 0x263e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2643:
	/* 0x2643: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2645:
	/* 0x2645: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_264b:
	/* 0x264b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_264d:
	/* 0x264d: js     270d <tail_handle_ipv6_from_netdev+0x270d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_270d;
	}
x86_l_2653:
	/* 0x2653: movabs rax,0x1000080000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1152930300699869185ULL);
x86_l_265d:
	/* 0x265d: bt     rax,r14 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_2661:
	/* 0x2661: jae    2dc5 <tail_handle_ipv6_from_netdev+0x2dc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 11717ULL;
	}
x86_l_2667:
	/* 0x2667: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2669:
	/* 0x2669: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_266f:
	/* 0x266f: cmp    DWORD PTR [rsp+0x78],0x3c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075580ULL);
x86_l_2674:
	/* 0x2674: jne    270f <tail_handle_ipv6_from_netdev+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270f;
	}
x86_l_267a:
	/* 0x267a: cmp    BYTE PTR [rsp+0x19],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 107374182402ULL);
x86_l_267f:
	/* 0x267f: jne    270f <tail_handle_ipv6_from_netdev+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270f;
	}
x86_l_2685:
	/* 0x2685: mov    rax,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_268c:
	/* 0x268c: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_268f:
	/* 0x268f: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2691:
	/* 0x2691: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2699:
	/* 0x2699: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_269e:
	/* 0x269e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_26a1:
	/* 0x26a1: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_26a3:
	/* 0x26a3: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_26a8:
	/* 0x26a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26aa:
	/* 0x26aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26ac:
	/* 0x26ac: js     26fb <tail_handle_ipv6_from_netdev+0x26fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_26fb;
	}
x86_l_26ae:
	/* 0x26ae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26b0:
	/* 0x26b0: cmp    BYTE PTR [rsp+0x8a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 592705486875ULL);
x86_l_26b8:
	/* 0x26b8: jne    270f <tail_handle_ipv6_from_netdev+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270f;
	}
x86_l_26ba:
	/* 0x26ba: cmp    BYTE PTR [rsp+0x8b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 597000454164ULL);
x86_l_26c2:
	/* 0x26c2: jne    270f <tail_handle_ipv6_from_netdev+0x270f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_270f;
	}
x86_l_26c4:
	/* 0x26c4: mov    rax,QWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_26cc:
	/* 0x26cc: mov    rcx,QWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_26d4:
	/* 0x26d4: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_26dc:
	/* 0x26dc: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_26e4:
	/* 0x26e4: movzx  eax,WORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 156ULL);
x86_l_26ec:
	/* 0x26ec: mov    WORD PTR [rsp+0xd8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_26f4:
	/* 0x26f4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26f7:
	/* 0x26f7: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_26f9:
	/* 0x26f9: jmp    270f <tail_handle_ipv6_from_netdev+0x270f> */
	goto x86_l_270f;
x86_l_26fb:
	/* 0x26fb: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_2701:
	/* 0x2701: jmp    270d <tail_handle_ipv6_from_netdev+0x270d> */
	goto x86_l_270d;
x86_l_2703:
	/* 0x2703: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_2707:
	/* 0x2707: jne    282b <tail_handle_ipv6_from_netdev+0x282b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_282b;
	}
x86_l_270d:
	/* 0x270d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_270f:
	/* 0x270f: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2717:
	/* 0x2717: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_271a:
	/* 0x271a: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_271d:
	/* 0x271d: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2720:
	/* 0x2720: js     32f7 <tail_handle_ipv6_from_netdev+0x32f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13047ULL;
	}
x86_l_2726:
	/* 0x2726: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2728:
	/* 0x2728: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_272d:
	/* 0x272d: je     2998 <tail_handle_ipv6_from_netdev+0x2998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2998;
	}
x86_l_2733:
	/* 0x2733: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_273b:
	/* 0x273b: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2743:
	/* 0x2743: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_274b:
	/* 0x274b: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2753:
	/* 0x2753: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_275b:
	/* 0x275b: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2763:
	/* 0x2763: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_276b:
	/* 0x276b: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2773:
	/* 0x2773: rol    DWORD PTR [rsp+0xc0],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 824633720848ULL);
x86_l_277b:
	/* 0x277b: movzx  eax,WORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 216ULL);
x86_l_2783:
	/* 0x2783: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2788:
	/* 0x2788: movzx  ebp,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_2790:
	/* 0x2790: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2794:
	/* 0x2794: jne    279f <tail_handle_ipv6_from_netdev+0x279f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_279f;
	}
x86_l_2796:
	/* 0x2796: mov    r13,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_279d:
	/* 0x279d: jmp    27a6 <tail_handle_ipv6_from_netdev+0x27a6> */
	goto x86_l_27a6;
x86_l_279f:
	/* 0x279f: mov    r13,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_27a6:
	/* 0x27a6: mov    BYTE PTR [rsp+0xc5],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 846108557312ULL);
x86_l_27ae:
	/* 0x27ae: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_27b6:
	/* 0x27b6: mov    rax,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_27bd:
	/* 0x27bd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27c0:
	/* 0x27c0: je     287e <tail_handle_ipv6_from_netdev+0x287e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287e;
	}
x86_l_27c6:
	/* 0x27c6: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_27d0:
	/* 0x27d0: and    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_AND);
x86_l_27d3:
	/* 0x27d3: je     287e <tail_handle_ipv6_from_netdev+0x287e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_287e;
	}
x86_l_27d9:
	/* 0x27d9: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_27dc:
	/* 0x27dc: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27e1:
	/* 0x27e1: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e3:
	/* 0x27e3: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_27ec:
	/* 0x27ec: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_27f5:
	/* 0x27f5: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_27ff:
	/* 0x27ff: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2807:
	/* 0x2807: mov    rdi,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_280e:
	/* 0x280e: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2816:
	/* 0x2816: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_281b:
	/* 0x281b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281d:
	/* 0x281d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2820:
	/* 0x2820: je     2850 <tail_handle_ipv6_from_netdev+0x2850> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2850;
	}
x86_l_2822:
	/* 0x2822: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2825:
	/* 0x2825: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2829:
	/* 0x2829: jmp    287b <tail_handle_ipv6_from_netdev+0x287b> */
	goto x86_l_287b;
x86_l_282b:
	/* 0x282b: cmp    BYTE PTR [rsp+0xc4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 841813590022ULL);
x86_l_2833:
	/* 0x2833: jne    2990 <tail_handle_ipv6_from_netdev+0x2990> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2990;
	}
x86_l_2839:
	/* 0x2839: cmp    BYTE PTR [rsp+0x4c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514502ULL);
x86_l_283e:
	/* 0x283e: jne    2974 <tail_handle_ipv6_from_netdev+0x2974> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2974;
	}
x86_l_2844:
	/* 0x2844: mov    rdi,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_284b:
	/* 0x284b: jmp    297b <tail_handle_ipv6_from_netdev+0x297b> */
	goto x86_l_297b;
x86_l_2850:
	/* 0x2850: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2859:
	/* 0x2859: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_285e:
	/* 0x285e: mov    rdi,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2865:
	/* 0x2865: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_286d:
	/* 0x286d: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2872:
	/* 0x2872: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2877:
	/* 0x2877: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2879:
	/* 0x2879: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_287b:
	/* 0x287b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_287e:
	/* 0x287e: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2882:
	/* 0x2882: jne    28e0 <tail_handle_ipv6_from_netdev+0x28e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28e0;
	}
x86_l_2884:
	/* 0x2884: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_288e:
	/* 0x288e: and    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2891:
	/* 0x2891: jne    28e0 <tail_handle_ipv6_from_netdev+0x28e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28e0;
	}
x86_l_2893:
	/* 0x2893: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2896:
	/* 0x2896: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_2899:
	/* 0x2899: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_289e:
	/* 0x289e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_28a3:
	/* 0x28a3: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28a8:
	/* 0x28a8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_28ad:
	/* 0x28ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28af:
	/* 0x28af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28b1:
	/* 0x28b1: js     295d <tail_handle_ipv6_from_netdev+0x295d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_295d;
	}
x86_l_28b7:
	/* 0x28b7: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28bb:
	/* 0x28bb: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_28bd:
	/* 0x28bd: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_28c2:
	/* 0x28c2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28c5:
	/* 0x28c5: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_28ca:
	/* 0x28ca: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_28cd:
	/* 0x28cd: mov    ebx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_32);
x86_l_28cf:
	/* 0x28cf: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_28d5:
	/* 0x28d5: jne    3336 <tail_handle_ipv6_from_netdev+0x3336> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13110ULL;
	}
x86_l_28db:
	/* 0x28db: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_28de:
	/* 0x28de: jmp    28e7 <tail_handle_ipv6_from_netdev+0x28e7> */
	goto x86_l_28e7;
x86_l_28e0:
	/* 0x28e0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28e3:
	/* 0x28e3: mov    ebx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28e7:
	/* 0x28e7: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28ef:
	/* 0x28ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28f4:
	/* 0x28f4: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_28f7:
	/* 0x28f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28f9:
	/* 0x28f9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28fc:
	/* 0x28fc: je     2909 <tail_handle_ipv6_from_netdev+0x2909> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2909;
	}
x86_l_28fe:
	/* 0x28fe: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2901:
	/* 0x2901: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2905:
	/* 0x2905: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2907:
	/* 0x2907: js     2928 <tail_handle_ipv6_from_netdev+0x2928> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2928;
	}
x86_l_2909:
	/* 0x2909: mov    rax,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2910:
	/* 0x2910: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2912:
	/* 0x2912: cmp    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2918:
	/* 0x2918: je     2956 <tail_handle_ipv6_from_netdev+0x2956> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2956;
	}
x86_l_291a:
	/* 0x291a: movzx  r15d,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_2923:
	/* 0x2923: jmp    2c0a <tail_handle_ipv6_from_netdev+0x2c0a> */
	return 11274ULL;
x86_l_2928:
	/* 0x2928: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_292a:
	/* 0x292a: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_292c:
	/* 0x292c: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_292f:
	/* 0x292f: je     2aa5 <tail_handle_ipv6_from_netdev+0x2aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10917ULL;
	}
x86_l_2935:
	/* 0x2935: mov    rcx,QWORD PTR [rip+0x1bdc2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_293c:
	/* 0x293c: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293f:
	/* 0x293f: je     29c2 <tail_handle_ipv6_from_netdev+0x29c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c2;
	}
x86_l_2945:
	/* 0x2945: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_294c:
	/* 0x294c: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2950:
	/* 0x2950: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2954:
	/* 0x2954: jmp    29c8 <tail_handle_ipv6_from_netdev+0x29c8> */
	goto x86_l_29c8;
x86_l_2956:
	/* 0x2956: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_295b:
	/* 0x295b: jmp    2962 <tail_handle_ipv6_from_netdev+0x2962> */
	goto x86_l_2962;
x86_l_295d:
	/* 0x295d: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_2962:
	/* 0x2962: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2965:
	/* 0x2965: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296a:
	/* 0x296a: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_296f:
	/* 0x296f: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_2974:
	/* 0x2974: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_297b:
	/* 0x297b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2980:
	/* 0x2980: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2985:
	/* 0x2985: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2987:
	/* 0x2987: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_298a:
	/* 0x298a: je     2990 <tail_handle_ipv6_from_netdev+0x2990> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2990;
	}
x86_l_298c:
	/* 0x298c: and    BYTE PTR [rax+0x24],0x7f */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 154618822783ULL);
x86_l_2990:
	/* 0x2990: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_2993:
	/* 0x2993: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2998:
	/* 0x2998: mov    DWORD PTR [rbp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_299f:
	/* 0x299f: mov    DWORD PTR [rbp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29a3:
	/* 0x29a3: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_29aa:
	/* 0x29aa: mov    r14d,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 37ULL);
x86_l_29b0:
	/* 0x29b0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_29b5:
	/* 0x29b5: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_29b8:
	/* 0x29b8: mov    edx,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_29bd:
	/* 0x29bd: jmp    31fe <tail_handle_ipv6_from_netdev+0x31fe> */
	return 12798ULL;
x86_l_29c2:
	/* 0x29c2: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_29c8:
	/* 0x29c8: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_29cc:
	/* 0x29cc: jne    2a0b <tail_handle_ipv6_from_netdev+0x2a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a0b;
	}
x86_l_29ce:
	/* 0x29ce: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_29d0:
	/* 0x29d0: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_29d2:
	/* 0x29d2: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_29d5:
	/* 0x29d5: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_29d8:
	/* 0x29d8: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_29da:
	/* 0x29da: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_29df:
	/* 0x29df: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_29e1:
	/* 0x29e1: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_29e6:
	/* 0x29e6: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_29ec:
	/* 0x29ec: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_29f0:
	/* 0x29f0: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_29f7:
	/* 0x29f7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29fa:
	/* 0x29fa: je     2a0b <tail_handle_ipv6_from_netdev+0x2a0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a0b;
	}
x86_l_29fc:
	/* 0x29fc: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2a03:
	/* 0x2a03: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2a07:
	/* 0x2a07: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2a0b:
	/* 0x2a0b: mov    r12d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_32);
x86_l_2a0e:
	/* 0x2a0e: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2a12:
	/* 0x2a12: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2a19:
	/* 0x2a19: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1c:
	/* 0x2a1c: je     2a2d <tail_handle_ipv6_from_netdev+0x2a2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2d;
	}
x86_l_2a1e:
	/* 0x2a1e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2a23:
	/* 0x2a23: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a25:
	/* 0x2a25: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a27:
	/* 0x2a27: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2a2b:
	/* 0x2a2b: jmp    2a50 <tail_handle_ipv6_from_netdev+0x2a50> */
	return 10832ULL;
x86_l_2a2d:
	/* 0x2a2d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2a32:
	/* 0x2a32: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a34:
	/* 0x2a34: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2a36:
	/* 0x2a36: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2a3a:
	/* 0x2a3a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2a44:
	/* 0x2a44: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2a47:
	/* 0x2a47: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
	return 10828ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10828ULL: goto x86_l_2a4c;
	case 10832ULL: goto x86_l_2a50;
	case 10835ULL: goto x86_l_2a53;
	case 10839ULL: goto x86_l_2a57;
	case 10844ULL: goto x86_l_2a5c;
	case 10848ULL: goto x86_l_2a60;
	case 10852ULL: goto x86_l_2a64;
	case 10859ULL: goto x86_l_2a6b;
	case 10862ULL: goto x86_l_2a6e;
	case 10864ULL: goto x86_l_2a70;
	case 10871ULL: goto x86_l_2a77;
	case 10873ULL: goto x86_l_2a79;
	case 10876ULL: goto x86_l_2a7c;
	case 10879ULL: goto x86_l_2a7f;
	case 10881ULL: goto x86_l_2a81;
	case 10886ULL: goto x86_l_2a86;
	case 10888ULL: goto x86_l_2a88;
	case 10891ULL: goto x86_l_2a8b;
	case 10893ULL: goto x86_l_2a8d;
	case 10895ULL: goto x86_l_2a8f;
	case 10898ULL: goto x86_l_2a92;
	case 10900ULL: goto x86_l_2a94;
	case 10904ULL: goto x86_l_2a98;
	case 10908ULL: goto x86_l_2a9c;
	case 10915ULL: goto x86_l_2aa3;
	case 10917ULL: goto x86_l_2aa5;
	case 10924ULL: goto x86_l_2aac;
	case 10927ULL: goto x86_l_2aaf;
	case 10929ULL: goto x86_l_2ab1;
	case 10934ULL: goto x86_l_2ab6;
	case 10939ULL: goto x86_l_2abb;
	case 10941ULL: goto x86_l_2abd;
	case 10946ULL: goto x86_l_2ac2;
	case 10950ULL: goto x86_l_2ac6;
	case 10952ULL: goto x86_l_2ac8;
	case 10956ULL: goto x86_l_2acc;
	case 10962ULL: goto x86_l_2ad2;
	case 10967ULL: goto x86_l_2ad7;
	case 10969ULL: goto x86_l_2ad9;
	case 10975ULL: goto x86_l_2adf;
	case 10982ULL: goto x86_l_2ae6;
	case 10987ULL: goto x86_l_2aeb;
	case 10992ULL: goto x86_l_2af0;
	case 10999ULL: goto x86_l_2af7;
	case 11004ULL: goto x86_l_2afc;
	case 11010ULL: goto x86_l_2b02;
	case 11017ULL: goto x86_l_2b09;
	case 11021ULL: goto x86_l_2b0d;
	case 11025ULL: goto x86_l_2b11;
	case 11030ULL: goto x86_l_2b16;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11040ULL: goto x86_l_2b20;
	case 11044ULL: goto x86_l_2b24;
	case 11048ULL: goto x86_l_2b28;
	case 11053ULL: goto x86_l_2b2d;
	case 11058ULL: goto x86_l_2b32;
	case 11065ULL: goto x86_l_2b39;
	case 11069ULL: goto x86_l_2b3d;
	case 11071ULL: goto x86_l_2b3f;
	case 11077ULL: goto x86_l_2b45;
	case 11084ULL: goto x86_l_2b4c;
	case 11088ULL: goto x86_l_2b50;
	case 11090ULL: goto x86_l_2b52;
	case 11097ULL: goto x86_l_2b59;
	case 11099ULL: goto x86_l_2b5b;
	case 11101ULL: goto x86_l_2b5d;
	case 11104ULL: goto x86_l_2b60;
	case 11107ULL: goto x86_l_2b63;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11117ULL: goto x86_l_2b6d;
	case 11121ULL: goto x86_l_2b71;
	case 11123ULL: goto x86_l_2b73;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11132ULL: goto x86_l_2b7c;
	case 11136ULL: goto x86_l_2b80;
	case 11138ULL: goto x86_l_2b82;
	case 11143ULL: goto x86_l_2b87;
	case 11145ULL: goto x86_l_2b89;
	case 11147ULL: goto x86_l_2b8b;
	case 11151ULL: goto x86_l_2b8f;
	case 11161ULL: goto x86_l_2b99;
	case 11164ULL: goto x86_l_2b9c;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11175ULL: goto x86_l_2ba7;
	case 11179ULL: goto x86_l_2bab;
	case 11184ULL: goto x86_l_2bb0;
	case 11188ULL: goto x86_l_2bb4;
	case 11191ULL: goto x86_l_2bb7;
	case 11195ULL: goto x86_l_2bbb;
	case 11197ULL: goto x86_l_2bbd;
	case 11204ULL: goto x86_l_2bc4;
	case 11206ULL: goto x86_l_2bc6;
	case 11209ULL: goto x86_l_2bc9;
	case 11212ULL: goto x86_l_2bcc;
	case 11214ULL: goto x86_l_2bce;
	case 11219ULL: goto x86_l_2bd3;
	case 11221ULL: goto x86_l_2bd5;
	case 11223ULL: goto x86_l_2bd7;
	case 11225ULL: goto x86_l_2bd9;
	case 11227ULL: goto x86_l_2bdb;
	case 11229ULL: goto x86_l_2bdd;
	case 11231ULL: goto x86_l_2bdf;
	case 11235ULL: goto x86_l_2be3;
	case 11239ULL: goto x86_l_2be7;
	case 11243ULL: goto x86_l_2beb;
	case 11245ULL: goto x86_l_2bed;
	case 11251ULL: goto x86_l_2bf3;
	case 11257ULL: goto x86_l_2bf9;
	case 11260ULL: goto x86_l_2bfc;
	case 11268ULL: goto x86_l_2c04;
	case 11274ULL: goto x86_l_2c0a;
	case 11282ULL: goto x86_l_2c12;
	case 11290ULL: goto x86_l_2c1a;
	case 11294ULL: goto x86_l_2c1e;
	case 11296ULL: goto x86_l_2c20;
	case 11303ULL: goto x86_l_2c27;
	case 11305ULL: goto x86_l_2c29;
	case 11312ULL: goto x86_l_2c30;
	case 11321ULL: goto x86_l_2c39;
	case 11330ULL: goto x86_l_2c42;
	case 11339ULL: goto x86_l_2c4b;
	case 11348ULL: goto x86_l_2c54;
	case 11357ULL: goto x86_l_2c5d;
	case 11365ULL: goto x86_l_2c65;
	case 11370ULL: goto x86_l_2c6a;
	case 11375ULL: goto x86_l_2c6f;
	case 11380ULL: goto x86_l_2c74;
	case 11385ULL: goto x86_l_2c79;
	case 11392ULL: goto x86_l_2c80;
	case 11399ULL: goto x86_l_2c87;
	case 11403ULL: goto x86_l_2c8b;
	case 11405ULL: goto x86_l_2c8d;
	case 11412ULL: goto x86_l_2c94;
	case 11415ULL: goto x86_l_2c97;
	case 11418ULL: goto x86_l_2c9a;
	case 11420ULL: goto x86_l_2c9c;
	case 11425ULL: goto x86_l_2ca1;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11438ULL: goto x86_l_2cae;
	case 11442ULL: goto x86_l_2cb2;
	case 11444ULL: goto x86_l_2cb4;
	case 11451ULL: goto x86_l_2cbb;
	case 11454ULL: goto x86_l_2cbe;
	case 11457ULL: goto x86_l_2cc1;
	case 11459ULL: goto x86_l_2cc3;
	case 11461ULL: goto x86_l_2cc5;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11484ULL: goto x86_l_2cdc;
	case 11488ULL: goto x86_l_2ce0;
	case 11490ULL: goto x86_l_2ce2;
	case 11495ULL: goto x86_l_2ce7;
	case 11497ULL: goto x86_l_2ce9;
	case 11499ULL: goto x86_l_2ceb;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11514ULL: goto x86_l_2cfa;
	case 11518ULL: goto x86_l_2cfe;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11536ULL: goto x86_l_2d10;
	case 11540ULL: goto x86_l_2d14;
	case 11544ULL: goto x86_l_2d18;
	case 11547ULL: goto x86_l_2d1b;
	case 11549ULL: goto x86_l_2d1d;
	case 11553ULL: goto x86_l_2d21;
	case 11558ULL: goto x86_l_2d26;
	case 11562ULL: goto x86_l_2d2a;
	case 11564ULL: goto x86_l_2d2c;
	case 11568ULL: goto x86_l_2d30;
	case 11570ULL: goto x86_l_2d32;
	case 11577ULL: goto x86_l_2d39;
	case 11579ULL: goto x86_l_2d3b;
	case 11582ULL: goto x86_l_2d3e;
	case 11585ULL: goto x86_l_2d41;
	case 11587ULL: goto x86_l_2d43;
	case 11592ULL: goto x86_l_2d48;
	case 11594ULL: goto x86_l_2d4a;
	case 11596ULL: goto x86_l_2d4c;
	case 11598ULL: goto x86_l_2d4e;
	case 11600ULL: goto x86_l_2d50;
	case 11602ULL: goto x86_l_2d52;
	case 11604ULL: goto x86_l_2d54;
	case 11608ULL: goto x86_l_2d58;
	case 11612ULL: goto x86_l_2d5c;
	case 11619ULL: goto x86_l_2d63;
	case 11621ULL: goto x86_l_2d65;
	case 11628ULL: goto x86_l_2d6c;
	case 11631ULL: goto x86_l_2d6f;
	case 11636ULL: goto x86_l_2d74;
	case 11638ULL: goto x86_l_2d76;
	case 11647ULL: goto x86_l_2d7f;
	case 11650ULL: goto x86_l_2d82;
	case 11655ULL: goto x86_l_2d87;
	case 11663ULL: goto x86_l_2d8f;
	case 11668ULL: goto x86_l_2d94;
	case 11670ULL: goto x86_l_2d96;
	case 11675ULL: goto x86_l_2d9b;
	case 11678ULL: goto x86_l_2d9e;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11685ULL: goto x86_l_2da5;
	case 11690ULL: goto x86_l_2daa;
	case 11693ULL: goto x86_l_2dad;
	case 11698ULL: goto x86_l_2db2;
	case 11701ULL: goto x86_l_2db5;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11717ULL: goto x86_l_2dc5;
	case 11723ULL: goto x86_l_2dcb;
	case 11728ULL: goto x86_l_2dd0;
	case 11737ULL: goto x86_l_2dd9;
	case 11742ULL: goto x86_l_2dde;
	case 11749ULL: goto x86_l_2de5;
	case 11757ULL: goto x86_l_2ded;
	case 11762ULL: goto x86_l_2df2;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11771ULL: goto x86_l_2dfb;
	case 11776ULL: goto x86_l_2e00;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11789ULL: goto x86_l_2e0d;
	case 11793ULL: goto x86_l_2e11;
	case 11804ULL: goto x86_l_2e1c;
	case 11811ULL: goto x86_l_2e23;
	case 11814ULL: goto x86_l_2e26;
	case 11820ULL: goto x86_l_2e2c;
	case 11825ULL: goto x86_l_2e31;
	case 11831ULL: goto x86_l_2e37;
	case 11836ULL: goto x86_l_2e3c;
	case 11838ULL: goto x86_l_2e3e;
	case 11847ULL: goto x86_l_2e47;
	case 11856ULL: goto x86_l_2e50;
	case 11866ULL: goto x86_l_2e5a;
	case 11872ULL: goto x86_l_2e60;
	case 11880ULL: goto x86_l_2e68;
	case 11887ULL: goto x86_l_2e6f;
	case 11895ULL: goto x86_l_2e77;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11905ULL: goto x86_l_2e81;
	case 11907ULL: goto x86_l_2e83;
	case 11910ULL: goto x86_l_2e86;
	case 11914ULL: goto x86_l_2e8a;
	case 11916ULL: goto x86_l_2e8c;
	case 11925ULL: goto x86_l_2e95;
	case 11930ULL: goto x86_l_2e9a;
	case 11937ULL: goto x86_l_2ea1;
	case 11945ULL: goto x86_l_2ea9;
	case 11950ULL: goto x86_l_2eae;
	case 11955ULL: goto x86_l_2eb3;
	case 11957ULL: goto x86_l_2eb5;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11966ULL: goto x86_l_2ebe;
	case 11969ULL: goto x86_l_2ec1;
	case 11971ULL: goto x86_l_2ec3;
	case 11974ULL: goto x86_l_2ec6;
	case 11982ULL: goto x86_l_2ece;
	case 11987ULL: goto x86_l_2ed3;
	case 11992ULL: goto x86_l_2ed8;
	case 11994ULL: goto x86_l_2eda;
	case 11999ULL: goto x86_l_2edf;
	case 12001ULL: goto x86_l_2ee1;
	case 12003ULL: goto x86_l_2ee3;
	case 12009ULL: goto x86_l_2ee9;
	case 12017ULL: goto x86_l_2ef1;
	case 12020ULL: goto x86_l_2ef4;
	case 12025ULL: goto x86_l_2ef9;
	case 12027ULL: goto x86_l_2efb;
	case 12032ULL: goto x86_l_2f00;
	case 12035ULL: goto x86_l_2f03;
	case 12042ULL: goto x86_l_2f0a;
	case 12048ULL: goto x86_l_2f10;
	case 12051ULL: goto x86_l_2f13;
	case 12053ULL: goto x86_l_2f15;
	case 12055ULL: goto x86_l_2f17;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12073ULL: goto x86_l_2f29;
	case 12078ULL: goto x86_l_2f2e;
	case 12080ULL: goto x86_l_2f30;
	case 12083ULL: goto x86_l_2f33;
	case 12089ULL: goto x86_l_2f39;
	case 12092ULL: goto x86_l_2f3c;
	case 12095ULL: goto x86_l_2f3f;
	case 12097ULL: goto x86_l_2f41;
	case 12099ULL: goto x86_l_2f43;
	case 12102ULL: goto x86_l_2f46;
	case 12108ULL: goto x86_l_2f4c;
	case 12115ULL: goto x86_l_2f53;
	case 12118ULL: goto x86_l_2f56;
	case 12120ULL: goto x86_l_2f58;
	case 12127ULL: goto x86_l_2f5f;
	case 12131ULL: goto x86_l_2f63;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12149ULL: goto x86_l_2f75;
	case 12155ULL: goto x86_l_2f7b;
	case 12158ULL: goto x86_l_2f7e;
	case 12163ULL: goto x86_l_2f83;
	case 12168ULL: goto x86_l_2f88;
	case 12173ULL: goto x86_l_2f8d;
	case 12179ULL: goto x86_l_2f93;
	case 12184ULL: goto x86_l_2f98;
	case 12186ULL: goto x86_l_2f9a;
	case 12189ULL: goto x86_l_2f9d;
	case 12191ULL: goto x86_l_2f9f;
	case 12194ULL: goto x86_l_2fa2;
	case 12197ULL: goto x86_l_2fa5;
	case 12199ULL: goto x86_l_2fa7;
	case 12204ULL: goto x86_l_2fac;
	case 12206ULL: goto x86_l_2fae;
	case 12211ULL: goto x86_l_2fb3;
	case 12217ULL: goto x86_l_2fb9;
	case 12221ULL: goto x86_l_2fbd;
	case 12224ULL: goto x86_l_2fc0;
	case 12226ULL: goto x86_l_2fc2;
	case 12233ULL: goto x86_l_2fc9;
	case 12237ULL: goto x86_l_2fcd;
	case 12241ULL: goto x86_l_2fd1;
	case 12244ULL: goto x86_l_2fd4;
	case 12248ULL: goto x86_l_2fd8;
	case 12251ULL: goto x86_l_2fdb;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12260ULL: goto x86_l_2fe4;
	case 12262ULL: goto x86_l_2fe6;
	case 12266ULL: goto x86_l_2fea;
	case 12268ULL: goto x86_l_2fec;
	case 12273ULL: goto x86_l_2ff1;
	case 12275ULL: goto x86_l_2ff3;
	case 12277ULL: goto x86_l_2ff5;
	case 12281ULL: goto x86_l_2ff9;
	case 12291ULL: goto x86_l_3003;
	case 12294ULL: goto x86_l_3006;
	case 12299ULL: goto x86_l_300b;
	case 12303ULL: goto x86_l_300f;
	case 12306ULL: goto x86_l_3012;
	case 12310ULL: goto x86_l_3016;
	case 12315ULL: goto x86_l_301b;
	case 12319ULL: goto x86_l_301f;
	case 12323ULL: goto x86_l_3023;
	case 12326ULL: goto x86_l_3026;
	case 12328ULL: goto x86_l_3028;
	case 12335ULL: goto x86_l_302f;
	case 12337ULL: goto x86_l_3031;
	case 12340ULL: goto x86_l_3034;
	case 12343ULL: goto x86_l_3037;
	case 12345ULL: goto x86_l_3039;
	case 12350ULL: goto x86_l_303e;
	case 12352ULL: goto x86_l_3040;
	case 12355ULL: goto x86_l_3043;
	case 12357ULL: goto x86_l_3045;
	case 12359ULL: goto x86_l_3047;
	case 12361ULL: goto x86_l_3049;
	case 12364ULL: goto x86_l_304c;
	case 12366ULL: goto x86_l_304e;
	case 12370ULL: goto x86_l_3052;
	case 12374ULL: goto x86_l_3056;
	case 12381ULL: goto x86_l_305d;
	case 12383ULL: goto x86_l_305f;
	case 12388ULL: goto x86_l_3064;
	case 12391ULL: goto x86_l_3067;
	case 12398ULL: goto x86_l_306e;
	case 12401ULL: goto x86_l_3071;
	case 12403ULL: goto x86_l_3073;
	case 12408ULL: goto x86_l_3078;
	case 12413ULL: goto x86_l_307d;
	case 12415ULL: goto x86_l_307f;
	case 12420ULL: goto x86_l_3084;
	case 12423ULL: goto x86_l_3087;
	case 12425ULL: goto x86_l_3089;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a4c:
	/* 0x2a4c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2a50:
	/* 0x2a50: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a53:
	/* 0x2a53: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a57:
	/* 0x2a57: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2a5c:
	/* 0x2a5c: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a60:
	/* 0x2a60: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2a64:
	/* 0x2a64: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2a6b:
	/* 0x2a6b: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6e:
	/* 0x2a6e: je     2a81 <tail_handle_ipv6_from_netdev+0x2a81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a81;
	}
x86_l_2a70:
	/* 0x2a70: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2a77:
	/* 0x2a77: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a79:
	/* 0x2a79: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2a7c:
	/* 0x2a7c: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2a7f:
	/* 0x2a7f: jmp    2a86 <tail_handle_ipv6_from_netdev+0x2a86> */
	goto x86_l_2a86;
x86_l_2a81:
	/* 0x2a81: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2a86:
	/* 0x2a86: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a88:
	/* 0x2a88: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2a8b:
	/* 0x2a8b: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2a8d:
	/* 0x2a8d: jb     2a94 <tail_handle_ipv6_from_netdev+0x2a94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a94;
	}
x86_l_2a8f:
	/* 0x2a8f: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_2a92:
	/* 0x2a92: je     2aa5 <tail_handle_ipv6_from_netdev+0x2aa5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2aa5;
	}
x86_l_2a94:
	/* 0x2a94: mov    BYTE PTR [r14+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2a98:
	/* 0x2a98: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a9c:
	/* 0x2a9c: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2aa3:
	/* 0x2aa3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aa5:
	/* 0x2aa5: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2aac:
	/* 0x2aac: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2aaf:
	/* 0x2aaf: je     2ac2 <tail_handle_ipv6_from_netdev+0x2ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ac2;
	}
x86_l_2ab1:
	/* 0x2ab1: inc QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_2ab6:
	/* 0x2ab6: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2abb:
	/* 0x2abb: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2abd:
	/* 0x2abd: add QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2ac2:
	/* 0x2ac2: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_2ac6:
	/* 0x2ac6: je     2b16 <tail_handle_ipv6_from_netdev+0x2b16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b16;
	}
x86_l_2ac8:
	/* 0x2ac8: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_2acc:
	/* 0x2acc: jne    2beb <tail_handle_ipv6_from_netdev+0x2beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2beb;
	}
x86_l_2ad2:
	/* 0x2ad2: movzx  eax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2ad7:
	/* 0x2ad7: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_2ad9:
	/* 0x2ad9: je     2beb <tail_handle_ipv6_from_netdev+0x2beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2beb;
	}
x86_l_2adf:
	/* 0x2adf: mov    WORD PTR [r14+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_2ae6:
	/* 0x2ae6: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_2aeb:
	/* 0x2aeb: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2af0:
	/* 0x2af0: mov    r12,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2af7:
	/* 0x2af7: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2afc:
	/* 0x2afc: je     478b <tail_handle_ipv6_from_netdev+0x478b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18315ULL;
	}
x86_l_2b02:
	/* 0x2b02: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2b09:
	/* 0x2b09: imul   r15d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2b0d:
	/* 0x2b0d: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2b11:
	/* 0x2b11: jmp    4791 <tail_handle_ipv6_from_netdev+0x4791> */
	return 18321ULL;
x86_l_2b16:
	/* 0x2b16: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_2b18:
	/* 0x2b18: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_2b1d:
	/* 0x2b1d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b20:
	/* 0x2b20: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_2b24:
	/* 0x2b24: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_2b28:
	/* 0x2b28: or     ax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_2b2d:
	/* 0x2b2d: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b32:
	/* 0x2b32: mov    r12,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2b39:
	/* 0x2b39: mov    ecx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b3d:
	/* 0x2b3d: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2b3f:
	/* 0x2b3f: je     2beb <tail_handle_ipv6_from_netdev+0x2beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2beb;
	}
x86_l_2b45:
	/* 0x2b45: mov    r15,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2b4c:
	/* 0x2b4c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b50:
	/* 0x2b50: je     2b65 <tail_handle_ipv6_from_netdev+0x2b65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b65;
	}
x86_l_2b52:
	/* 0x2b52: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2b59:
	/* 0x2b59: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b5b:
	/* 0x2b5b: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b5d:
	/* 0x2b5d: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2b60:
	/* 0x2b60: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2b63:
	/* 0x2b63: jmp    2b6a <tail_handle_ipv6_from_netdev+0x2b6a> */
	goto x86_l_2b6a;
x86_l_2b65:
	/* 0x2b65: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_2b6a:
	/* 0x2b6a: shr    ebx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2b6d:
	/* 0x2b6d: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b71:
	/* 0x2b71: je     2b82 <tail_handle_ipv6_from_netdev+0x2b82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b82;
	}
x86_l_2b73:
	/* 0x2b73: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2b78:
	/* 0x2b78: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b7a:
	/* 0x2b7a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b7c:
	/* 0x2b7c: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2b80:
	/* 0x2b80: jmp    2ba5 <tail_handle_ipv6_from_netdev+0x2ba5> */
	goto x86_l_2ba5;
x86_l_2b82:
	/* 0x2b82: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2b87:
	/* 0x2b87: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b89:
	/* 0x2b89: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b8b:
	/* 0x2b8b: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2b8f:
	/* 0x2b8f: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2b99:
	/* 0x2b99: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b9c:
	/* 0x2b9c: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2ba1:
	/* 0x2ba1: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2ba5:
	/* 0x2ba5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2ba7:
	/* 0x2ba7: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bab:
	/* 0x2bab: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2bb0:
	/* 0x2bb0: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bb4:
	/* 0x2bb4: and    bl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2bb7:
	/* 0x2bb7: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbb:
	/* 0x2bbb: je     2bce <tail_handle_ipv6_from_netdev+0x2bce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bce;
	}
x86_l_2bbd:
	/* 0x2bbd: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2bc4:
	/* 0x2bc4: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc6:
	/* 0x2bc6: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2bc9:
	/* 0x2bc9: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2bcc:
	/* 0x2bcc: jmp    2bd3 <tail_handle_ipv6_from_netdev+0x2bd3> */
	goto x86_l_2bd3;
x86_l_2bce:
	/* 0x2bce: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2bd3:
	/* 0x2bd3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2bd5:
	/* 0x2bd5: or     bl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2bd7:
	/* 0x2bd7: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2bd9:
	/* 0x2bd9: jb     2bdf <tail_handle_ipv6_from_netdev+0x2bdf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2bdf;
	}
x86_l_2bdb:
	/* 0x2bdb: cmp    cl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_8);
x86_l_2bdd:
	/* 0x2bdd: je     2beb <tail_handle_ipv6_from_netdev+0x2beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2beb;
	}
x86_l_2bdf:
	/* 0x2bdf: mov    BYTE PTR [r14+0x2a],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2be3:
	/* 0x2be3: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2be7:
	/* 0x2be7: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2beb:
	/* 0x2beb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bed:
	/* 0x2bed: cmp    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2bf3:
	/* 0x2bf3: je     2cc3 <tail_handle_ipv6_from_netdev+0x2cc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cc3;
	}
x86_l_2bf9:
	/* 0x2bf9: mov    r15b,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 6ULL);
x86_l_2bfc:
	/* 0x2bfc: cmp    BYTE PTR [rsp+0xc4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 841813590022ULL);
x86_l_2c04:
	/* 0x2c04: jne    2cc3 <tail_handle_ipv6_from_netdev+0x2cc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cc3;
	}
x86_l_2c0a:
	/* 0x2c0a: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2c12:
	/* 0x2c12: mov    rcx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2c1a:
	/* 0x2c1a: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_2c1e:
	/* 0x2c1e: jne    2c29 <tail_handle_ipv6_from_netdev+0x2c29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c29;
	}
x86_l_2c20:
	/* 0x2c20: mov    r13,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_2c27:
	/* 0x2c27: jmp    2c30 <tail_handle_ipv6_from_netdev+0x2c30> */
	goto x86_l_2c30;
x86_l_2c29:
	/* 0x2c29: mov    r13,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_2c30:
	/* 0x2c30: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2c39:
	/* 0x2c39: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2c42:
	/* 0x2c42: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_2c4b:
	/* 0x2c4b: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2c54:
	/* 0x2c54: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    DWORD PTR [rsp+0x54],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252874ULL);
x86_l_2c65:
	/* 0x2c65: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c6a:
	/* 0x2c6a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c6f:
	/* 0x2c6f: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_2c74:
	/* 0x2c74: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c79:
	/* 0x2c79: mov    WORD PTR [rsp+0x4c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514624ULL);
x86_l_2c80:
	/* 0x2c80: mov    r14,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2c87:
	/* 0x2c87: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c8b:
	/* 0x2c8b: je     2c9c <tail_handle_ipv6_from_netdev+0x2c9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c9c;
	}
x86_l_2c8d:
	/* 0x2c8d: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2c94:
	/* 0x2c94: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2c97:
	/* 0x2c97: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2c9a:
	/* 0x2c9a: jmp    2ca1 <tail_handle_ipv6_from_netdev+0x2ca1> */
	goto x86_l_2ca1;
x86_l_2c9c:
	/* 0x2c9c: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_2ca1:
	/* 0x2ca1: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_2ca5:
	/* 0x2ca5: jne    2cdc <tail_handle_ipv6_from_netdev+0x2cdc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cdc;
	}
x86_l_2ca7:
	/* 0x2ca7: mov    WORD PTR [rsp+0x4c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514624ULL);
x86_l_2cae:
	/* 0x2cae: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb2:
	/* 0x2cb2: je     2cd7 <tail_handle_ipv6_from_netdev+0x2cd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cd7;
	}
x86_l_2cb4:
	/* 0x2cb4: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2cbb:
	/* 0x2cbb: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2cbe:
	/* 0x2cbe: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2cc1:
	/* 0x2cc1: jmp    2cdc <tail_handle_ipv6_from_netdev+0x2cdc> */
	goto x86_l_2cdc;
x86_l_2cc3:
	/* 0x2cc3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cc5:
	/* 0x2cc5: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2cca:
	/* 0x2cca: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ccf:
	/* 0x2ccf: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_2cd2:
	/* 0x2cd2: jmp    ca7 <tail_handle_ipv6_from_netdev+0xca7> */
	return 3239ULL;
x86_l_2cd7:
	/* 0x2cd7: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_2cdc:
	/* 0x2cdc: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce0:
	/* 0x2ce0: je     2cf1 <tail_handle_ipv6_from_netdev+0x2cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cf1;
	}
x86_l_2ce2:
	/* 0x2ce2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2ce7:
	/* 0x2ce7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ce9:
	/* 0x2ce9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ceb:
	/* 0x2ceb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2cef:
	/* 0x2cef: jmp    2d14 <tail_handle_ipv6_from_netdev+0x2d14> */
	goto x86_l_2d14;
x86_l_2cf1:
	/* 0x2cf1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2cf6:
	/* 0x2cf6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf8:
	/* 0x2cf8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2cfa:
	/* 0x2cfa: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2cfe:
	/* 0x2cfe: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2d08:
	/* 0x2d08: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d0b:
	/* 0x2d0b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2d10:
	/* 0x2d10: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2d14:
	/* 0x2d14: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_2d18:
	/* 0x2d18: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2d1b:
	/* 0x2d1b: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d1d:
	/* 0x2d1d: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2d21:
	/* 0x2d21: movzx  edx,BYTE PTR [rsp+0x52] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 82ULL);
x86_l_2d26:
	/* 0x2d26: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d2a:
	/* 0x2d2a: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_2d2c:
	/* 0x2d2c: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d30:
	/* 0x2d30: je     2d43 <tail_handle_ipv6_from_netdev+0x2d43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d43;
	}
x86_l_2d32:
	/* 0x2d32: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2d39:
	/* 0x2d39: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d3b:
	/* 0x2d3b: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_2d3e:
	/* 0x2d3e: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2d41:
	/* 0x2d41: jmp    2d48 <tail_handle_ipv6_from_netdev+0x2d48> */
	goto x86_l_2d48;
x86_l_2d43:
	/* 0x2d43: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_2d48:
	/* 0x2d48: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d4a:
	/* 0x2d4a: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2d4c:
	/* 0x2d4c: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2d4e:
	/* 0x2d4e: jb     2d54 <tail_handle_ipv6_from_netdev+0x2d54> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2d54;
	}
x86_l_2d50:
	/* 0x2d50: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_2d52:
	/* 0x2d52: je     2d65 <tail_handle_ipv6_from_netdev+0x2d65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d65;
	}
x86_l_2d54:
	/* 0x2d54: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2d58:
	/* 0x2d58: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d5c:
	/* 0x2d5c: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2d63:
	/* 0x2d63: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d65:
	/* 0x2d65: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2d6c:
	/* 0x2d6c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6f:
	/* 0x2d6f: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d74:
	/* 0x2d74: je     2d87 <tail_handle_ipv6_from_netdev+0x2d87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d87;
	}
x86_l_2d76:
	/* 0x2d76: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2d7f:
	/* 0x2d7f: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d82:
	/* 0x2d82: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d87:
	/* 0x2d87: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2d8f:
	/* 0x2d8f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d94:
	/* 0x2d94: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d96:
	/* 0x2d96: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d9b:
	/* 0x2d9b: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_2d9e:
	/* 0x2d9e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2da0:
	/* 0x2da0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da2:
	/* 0x2da2: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_2da5:
	/* 0x2da5: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2daa:
	/* 0x2daa: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_2dad:
	/* 0x2dad: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db2:
	/* 0x2db2: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_2db5:
	/* 0x2db5: jns    ca7 <tail_handle_ipv6_from_netdev+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 3239ULL;
	}
x86_l_2dbb:
	/* 0x2dbb: mov    eax,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967141ULL);
x86_l_2dc0:
	/* 0x2dc0: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_2dc5:
	/* 0x2dc5: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_2dcb:
	/* 0x2dcb: jmp    270d <tail_handle_ipv6_from_netdev+0x270d> */
	return 9997ULL;
x86_l_2dd0:
	/* 0x2dd0: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2dd9:
	/* 0x2dd9: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2dde:
	/* 0x2dde: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2de5:
	/* 0x2de5: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ded:
	/* 0x2ded: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2df2:
	/* 0x2df2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2df7:
	/* 0x2df7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df9:
	/* 0x2df9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dfb:
	/* 0x2dfb: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e00:
	/* 0x2e00: or     BYTE PTR [rax+0x25],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 158913789954ULL);
x86_l_2e04:
	/* 0x2e04: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e09:
	/* 0x2e09: movzx  eax,BYTE PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_2e0d:
	/* 0x2e0d: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e11:
	/* 0x2e11: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_2e1c:
	/* 0x2e1c: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_2e23:
	/* 0x2e23: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e26:
	/* 0x2e26: je     2eb7 <tail_handle_ipv6_from_netdev+0x2eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eb7;
	}
x86_l_2e2c:
	/* 0x2e2c: and    QWORD PTR [rsp+0x60],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 96ULL);
x86_l_2e31:
	/* 0x2e31: je     2eb7 <tail_handle_ipv6_from_netdev+0x2eb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2eb7;
	}
x86_l_2e37:
	/* 0x2e37: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e3c:
	/* 0x2e3c: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2e47:
	/* 0x2e47: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2e50:
	/* 0x2e50: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_2e5a:
	/* 0x2e5a: add    rax,0xffffffffffffff00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551360ULL);
x86_l_2e60:
	/* 0x2e60: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e68:
	/* 0x2e68: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2e6f:
	/* 0x2e6f: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2e77:
	/* 0x2e77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e7c:
	/* 0x2e7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7e:
	/* 0x2e7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e81:
	/* 0x2e81: je     2e8c <tail_handle_ipv6_from_netdev+0x2e8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8c;
	}
x86_l_2e83:
	/* 0x2e83: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2e86:
	/* 0x2e86: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2e8a:
	/* 0x2e8a: jmp    2eb7 <tail_handle_ipv6_from_netdev+0x2eb7> */
	goto x86_l_2eb7;
x86_l_2e8c:
	/* 0x2e8c: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2e95:
	/* 0x2e95: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e9a:
	/* 0x2e9a: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2ea1:
	/* 0x2ea1: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ea9:
	/* 0x2ea9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2eae:
	/* 0x2eae: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2eb3:
	/* 0x2eb3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb5:
	/* 0x2eb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb7:
	/* 0x2eb7: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_2ebc:
	/* 0x2ebc: jne    2f15 <tail_handle_ipv6_from_netdev+0x2f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f15;
	}
x86_l_2ebe:
	/* 0x2ebe: and    r12,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_2ec1:
	/* 0x2ec1: jne    2f15 <tail_handle_ipv6_from_netdev+0x2f15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f15;
	}
x86_l_2ec3:
	/* 0x2ec3: add    ebp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_2ec6:
	/* 0x2ec6: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2ece:
	/* 0x2ece: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2ed3:
	/* 0x2ed3: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ed8:
	/* 0x2ed8: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2eda:
	/* 0x2eda: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2edf:
	/* 0x2edf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ee1:
	/* 0x2ee1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ee3:
	/* 0x2ee3: js     2f69 <tail_handle_ipv6_from_netdev+0x2f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2f69;
	}
x86_l_2ee9:
	/* 0x2ee9: mov    r15d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2ef1:
	/* 0x2ef1: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_2ef4:
	/* 0x2ef4: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_2ef9:
	/* 0x2ef9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2efb:
	/* 0x2efb: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_2f00:
	/* 0x2f00: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2f03:
	/* 0x2f03: test   r15d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_32, 1280ULL);
x86_l_2f0a:
	/* 0x2f0a: jne    33ce <tail_handle_ipv6_from_netdev+0x33ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13262ULL;
	}
x86_l_2f10:
	/* 0x2f10: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_2f13:
	/* 0x2f13: jmp    2f1f <tail_handle_ipv6_from_netdev+0x2f1f> */
	goto x86_l_2f1f;
x86_l_2f15:
	/* 0x2f15: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f17:
	/* 0x2f17: mov    r15d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2f1f:
	/* 0x2f1f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f24:
	/* 0x2f24: mov    rdi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2f29:
	/* 0x2f29: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f2e:
	/* 0x2f2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f30:
	/* 0x2f30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f33:
	/* 0x2f33: je     44be <tail_handle_ipv6_from_netdev+0x44be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17598ULL;
	}
x86_l_2f39:
	/* 0x2f39: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2f3c:
	/* 0x2f3c: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2f3f:
	/* 0x2f3f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2f41:
	/* 0x2f41: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2f43:
	/* 0x2f43: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2f46:
	/* 0x2f46: je     3067 <tail_handle_ipv6_from_netdev+0x3067> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3067;
	}
x86_l_2f4c:
	/* 0x2f4c: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2f53:
	/* 0x2f53: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f56:
	/* 0x2f56: je     2f8d <tail_handle_ipv6_from_netdev+0x2f8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f8d;
	}
x86_l_2f58:
	/* 0x2f58: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2f5f:
	/* 0x2f5f: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2f63:
	/* 0x2f63: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2f67:
	/* 0x2f67: jmp    2f93 <tail_handle_ipv6_from_netdev+0x2f93> */
	goto x86_l_2f93;
x86_l_2f69:
	/* 0x2f69: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    DWORD PTR [rax+0x4c],0xffffff79 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 330712481657ULL);
x86_l_2f75:
	/* 0x2f75: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_2f7b:
	/* 0x2f7b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f7e:
	/* 0x2f7e: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f83:
	/* 0x2f83: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f88:
	/* 0x2f88: jmp    5a7 <tail_handle_ipv6_from_netdev+0x5a7> */
	return 1447ULL;
x86_l_2f8d:
	/* 0x2f8d: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2f93:
	/* 0x2f93: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_2f98:
	/* 0x2f98: jne    2fd1 <tail_handle_ipv6_from_netdev+0x2fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2fd1;
	}
x86_l_2f9a:
	/* 0x2f9a: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_2f9d:
	/* 0x2f9d: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2f9f:
	/* 0x2f9f: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2fa2:
	/* 0x2fa2: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2fa5:
	/* 0x2fa5: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2fa7:
	/* 0x2fa7: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2fac:
	/* 0x2fac: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_2fae:
	/* 0x2fae: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2fb3:
	/* 0x2fb3: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_2fb9:
	/* 0x2fb9: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2fbd:
	/* 0x2fbd: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc0:
	/* 0x2fc0: je     2fd1 <tail_handle_ipv6_from_netdev+0x2fd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fd1;
	}
x86_l_2fc2:
	/* 0x2fc2: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2fc9:
	/* 0x2fc9: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2fcd:
	/* 0x2fcd: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2fd1:
	/* 0x2fd1: mov    r14d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_32);
x86_l_2fd4:
	/* 0x2fd4: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2fd8:
	/* 0x2fd8: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fdb:
	/* 0x2fdb: je     2fec <tail_handle_ipv6_from_netdev+0x2fec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2fec;
	}
x86_l_2fdd:
	/* 0x2fdd: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2fe2:
	/* 0x2fe2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fe4:
	/* 0x2fe4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2fe6:
	/* 0x2fe6: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2fea:
	/* 0x2fea: jmp    300f <tail_handle_ipv6_from_netdev+0x300f> */
	goto x86_l_300f;
x86_l_2fec:
	/* 0x2fec: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2ff1:
	/* 0x2ff1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ff3:
	/* 0x2ff3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2ff5:
	/* 0x2ff5: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2ff9:
	/* 0x2ff9: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_3003:
	/* 0x3003: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3006:
	/* 0x3006: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_300b:
	/* 0x300b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_300f:
	/* 0x300f: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3012:
	/* 0x3012: mov    DWORD PTR [r13+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3016:
	/* 0x3016: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_301b:
	/* 0x301b: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_301f:
	/* 0x301f: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_3023:
	/* 0x3023: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3026:
	/* 0x3026: je     3039 <tail_handle_ipv6_from_netdev+0x3039> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3039;
	}
x86_l_3028:
	/* 0x3028: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_302f:
	/* 0x302f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3031:
	/* 0x3031: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_3034:
	/* 0x3034: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3037:
	/* 0x3037: jmp    303e <tail_handle_ipv6_from_netdev+0x303e> */
	goto x86_l_303e;
x86_l_3039:
	/* 0x3039: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_303e:
	/* 0x303e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3040:
	/* 0x3040: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_3043:
	/* 0x3043: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_3045:
	/* 0x3045: jb     304e <tail_handle_ipv6_from_netdev+0x304e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_304e;
	}
x86_l_3047:
	/* 0x3047: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3049:
	/* 0x3049: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_304c:
	/* 0x304c: je     305f <tail_handle_ipv6_from_netdev+0x305f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_305f;
	}
x86_l_304e:
	/* 0x304e: mov    BYTE PTR [r13+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_3052:
	/* 0x3052: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3056:
	/* 0x3056: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_305d:
	/* 0x305d: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_305f:
	/* 0x305f: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3064:
	/* 0x3064: mov    DWORD PTR [rax+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3067:
	/* 0x3067: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_306e:
	/* 0x306e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3071:
	/* 0x3071: je     3084 <tail_handle_ipv6_from_netdev+0x3084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3084;
	}
x86_l_3073:
	/* 0x3073: inc QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_3078:
	/* 0x3078: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_307d:
	/* 0x307d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_307f:
	/* 0x307f: add QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3084:
	/* 0x3084: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3087:
	/* 0x3087: je     30d4 <tail_handle_ipv6_from_netdev+0x30d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12500ULL;
	}
x86_l_3089:
	/* 0x3089: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
	return 12428ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12428ULL: goto x86_l_308c;
	case 12434ULL: goto x86_l_3092;
	case 12439ULL: goto x86_l_3097;
	case 12441ULL: goto x86_l_3099;
	case 12447ULL: goto x86_l_309f;
	case 12454ULL: goto x86_l_30a6;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12471ULL: goto x86_l_30b7;
	case 12474ULL: goto x86_l_30ba;
	case 12480ULL: goto x86_l_30c0;
	case 12487ULL: goto x86_l_30c7;
	case 12491ULL: goto x86_l_30cb;
	case 12495ULL: goto x86_l_30cf;
	case 12500ULL: goto x86_l_30d4;
	case 12503ULL: goto x86_l_30d7;
	case 12506ULL: goto x86_l_30da;
	case 12509ULL: goto x86_l_30dd;
	case 12514ULL: goto x86_l_30e2;
	case 12517ULL: goto x86_l_30e5;
	case 12522ULL: goto x86_l_30ea;
	case 12529ULL: goto x86_l_30f1;
	case 12531ULL: goto x86_l_30f3;
	case 12536ULL: goto x86_l_30f8;
	case 12539ULL: goto x86_l_30fb;
	case 12543ULL: goto x86_l_30ff;
	case 12545ULL: goto x86_l_3101;
	case 12547ULL: goto x86_l_3103;
	case 12553ULL: goto x86_l_3109;
	case 12560ULL: goto x86_l_3110;
	case 12564ULL: goto x86_l_3114;
	case 12566ULL: goto x86_l_3116;
	case 12573ULL: goto x86_l_311d;
	case 12575ULL: goto x86_l_311f;
	case 12577ULL: goto x86_l_3121;
	case 12580ULL: goto x86_l_3124;
	case 12583ULL: goto x86_l_3127;
	case 12585ULL: goto x86_l_3129;
	case 12590ULL: goto x86_l_312e;
	case 12594ULL: goto x86_l_3132;
	case 12598ULL: goto x86_l_3136;
	case 12600ULL: goto x86_l_3138;
	case 12605ULL: goto x86_l_313d;
	case 12607ULL: goto x86_l_313f;
	case 12609ULL: goto x86_l_3141;
	case 12613ULL: goto x86_l_3145;
	case 12615ULL: goto x86_l_3147;
	case 12620ULL: goto x86_l_314c;
	case 12622ULL: goto x86_l_314e;
	case 12624ULL: goto x86_l_3150;
	case 12628ULL: goto x86_l_3154;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12646ULL: goto x86_l_3166;
	case 12650ULL: goto x86_l_316a;
	case 12652ULL: goto x86_l_316c;
	case 12656ULL: goto x86_l_3170;
	case 12661ULL: goto x86_l_3175;
	case 12665ULL: goto x86_l_3179;
	case 12669ULL: goto x86_l_317d;
	case 12673ULL: goto x86_l_3181;
	case 12675ULL: goto x86_l_3183;
	case 12682ULL: goto x86_l_318a;
	case 12684ULL: goto x86_l_318c;
	case 12687ULL: goto x86_l_318f;
	case 12690ULL: goto x86_l_3192;
	case 12692ULL: goto x86_l_3194;
	case 12697ULL: goto x86_l_3199;
	case 12699ULL: goto x86_l_319b;
	case 12702ULL: goto x86_l_319e;
	case 12704ULL: goto x86_l_31a0;
	case 12706ULL: goto x86_l_31a2;
	case 12709ULL: goto x86_l_31a5;
	case 12711ULL: goto x86_l_31a7;
	case 12715ULL: goto x86_l_31ab;
	case 12719ULL: goto x86_l_31af;
	case 12721ULL: goto x86_l_31b1;
	case 12726ULL: goto x86_l_31b6;
	case 12730ULL: goto x86_l_31ba;
	case 12732ULL: goto x86_l_31bc;
	case 12734ULL: goto x86_l_31be;
	case 12739ULL: goto x86_l_31c3;
	case 12742ULL: goto x86_l_31c6;
	case 12747ULL: goto x86_l_31cb;
	case 12750ULL: goto x86_l_31ce;
	case 12755ULL: goto x86_l_31d3;
	case 12760ULL: goto x86_l_31d8;
	case 12765ULL: goto x86_l_31dd;
	case 12768ULL: goto x86_l_31e0;
	case 12772ULL: goto x86_l_31e4;
	case 12779ULL: goto x86_l_31eb;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12793ULL: goto x86_l_31f9;
	case 12798ULL: goto x86_l_31fe;
	case 12800ULL: goto x86_l_3200;
	case 12805ULL: goto x86_l_3205;
	case 12810ULL: goto x86_l_320a;
	case 12813ULL: goto x86_l_320d;
	case 12820ULL: goto x86_l_3214;
	case 12825ULL: goto x86_l_3219;
	case 12830ULL: goto x86_l_321e;
	case 12832ULL: goto x86_l_3220;
	case 12835ULL: goto x86_l_3223;
	case 12841ULL: goto x86_l_3229;
	case 12843ULL: goto x86_l_322b;
	case 12850ULL: goto x86_l_3232;
	case 12855ULL: goto x86_l_3237;
	case 12862ULL: goto x86_l_323e;
	case 12867ULL: goto x86_l_3243;
	case 12872ULL: goto x86_l_3248;
	case 12875ULL: goto x86_l_324b;
	case 12877ULL: goto x86_l_324d;
	case 12879ULL: goto x86_l_324f;
	case 12881ULL: goto x86_l_3251;
	case 12887ULL: goto x86_l_3257;
	case 12891ULL: goto x86_l_325b;
	case 12900ULL: goto x86_l_3264;
	case 12909ULL: goto x86_l_326d;
	case 12919ULL: goto x86_l_3277;
	case 12925ULL: goto x86_l_327d;
	case 12933ULL: goto x86_l_3285;
	case 12940ULL: goto x86_l_328c;
	case 12948ULL: goto x86_l_3294;
	case 12953ULL: goto x86_l_3299;
	case 12955ULL: goto x86_l_329b;
	case 12958ULL: goto x86_l_329e;
	case 12960ULL: goto x86_l_32a0;
	case 12963ULL: goto x86_l_32a3;
	case 12967ULL: goto x86_l_32a7;
	case 12969ULL: goto x86_l_32a9;
	case 12974ULL: goto x86_l_32ae;
	case 12979ULL: goto x86_l_32b3;
	case 12984ULL: goto x86_l_32b8;
	case 12987ULL: goto x86_l_32bb;
	case 12992ULL: goto x86_l_32c0;
	case 13001ULL: goto x86_l_32c9;
	case 13006ULL: goto x86_l_32ce;
	case 13013ULL: goto x86_l_32d5;
	case 13021ULL: goto x86_l_32dd;
	case 13026ULL: goto x86_l_32e2;
	case 13031ULL: goto x86_l_32e7;
	case 13033ULL: goto x86_l_32e9;
	case 13035ULL: goto x86_l_32eb;
	case 13042ULL: goto x86_l_32f2;
	case 13047ULL: goto x86_l_32f7;
	case 13050ULL: goto x86_l_32fa;
	case 13055ULL: goto x86_l_32ff;
	case 13060ULL: goto x86_l_3304;
	case 13065ULL: goto x86_l_3309;
	case 13070ULL: goto x86_l_330e;
	case 13077ULL: goto x86_l_3315;
	case 13082ULL: goto x86_l_331a;
	case 13085ULL: goto x86_l_331d;
	case 13087ULL: goto x86_l_331f;
	case 13090ULL: goto x86_l_3322;
	case 13096ULL: goto x86_l_3328;
	case 13098ULL: goto x86_l_332a;
	case 13103ULL: goto x86_l_332f;
	case 13105ULL: goto x86_l_3331;
	case 13110ULL: goto x86_l_3336;
	case 13116ULL: goto x86_l_333c;
	case 13121ULL: goto x86_l_3341;
	case 13127ULL: goto x86_l_3347;
	case 13132ULL: goto x86_l_334c;
	case 13139ULL: goto x86_l_3353;
	case 13144ULL: goto x86_l_3358;
	case 13147ULL: goto x86_l_335b;
	case 13152ULL: goto x86_l_3360;
	case 13154ULL: goto x86_l_3362;
	case 13156ULL: goto x86_l_3364;
	case 13158ULL: goto x86_l_3366;
	case 13164ULL: goto x86_l_336c;
	case 13169ULL: goto x86_l_3371;
	case 13172ULL: goto x86_l_3374;
	case 13181ULL: goto x86_l_337d;
	case 13190ULL: goto x86_l_3386;
	case 13200ULL: goto x86_l_3390;
	case 13208ULL: goto x86_l_3398;
	case 13215ULL: goto x86_l_339f;
	case 13223ULL: goto x86_l_33a7;
	case 13228ULL: goto x86_l_33ac;
	case 13230ULL: goto x86_l_33ae;
	case 13233ULL: goto x86_l_33b1;
	case 13235ULL: goto x86_l_33b3;
	case 13238ULL: goto x86_l_33b6;
	case 13242ULL: goto x86_l_33ba;
	case 13246ULL: goto x86_l_33be;
	case 13251ULL: goto x86_l_33c3;
	case 13257ULL: goto x86_l_33c9;
	case 13262ULL: goto x86_l_33ce;
	case 13267ULL: goto x86_l_33d3;
	case 13272ULL: goto x86_l_33d8;
	case 13278ULL: goto x86_l_33de;
	case 13283ULL: goto x86_l_33e3;
	case 13292ULL: goto x86_l_33ec;
	case 13297ULL: goto x86_l_33f1;
	case 13304ULL: goto x86_l_33f8;
	case 13312ULL: goto x86_l_3400;
	case 13317ULL: goto x86_l_3405;
	case 13322ULL: goto x86_l_340a;
	case 13324ULL: goto x86_l_340c;
	case 13326ULL: goto x86_l_340e;
	case 13330ULL: goto x86_l_3412;
	case 13335ULL: goto x86_l_3417;
	case 13341ULL: goto x86_l_341d;
	case 13346ULL: goto x86_l_3422;
	case 13348ULL: goto x86_l_3424;
	case 13352ULL: goto x86_l_3428;
	case 13354ULL: goto x86_l_342a;
	case 13357ULL: goto x86_l_342d;
	case 13360ULL: goto x86_l_3430;
	case 13362ULL: goto x86_l_3432;
	case 13367ULL: goto x86_l_3437;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13380ULL: goto x86_l_3444;
	case 13384ULL: goto x86_l_3448;
	case 13387ULL: goto x86_l_344b;
	case 13389ULL: goto x86_l_344d;
	case 13396ULL: goto x86_l_3454;
	case 13400ULL: goto x86_l_3458;
	case 13404ULL: goto x86_l_345c;
	case 13409ULL: goto x86_l_3461;
	case 13412ULL: goto x86_l_3464;
	case 13414ULL: goto x86_l_3466;
	case 13419ULL: goto x86_l_346b;
	case 13421ULL: goto x86_l_346d;
	case 13423ULL: goto x86_l_346f;
	case 13427ULL: goto x86_l_3473;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13436ULL: goto x86_l_347c;
	case 13438ULL: goto x86_l_347e;
	case 13442ULL: goto x86_l_3482;
	case 13452ULL: goto x86_l_348c;
	case 13455ULL: goto x86_l_348f;
	case 13460ULL: goto x86_l_3494;
	case 13464ULL: goto x86_l_3498;
	case 13467ULL: goto x86_l_349b;
	case 13471ULL: goto x86_l_349f;
	case 13476ULL: goto x86_l_34a4;
	case 13480ULL: goto x86_l_34a8;
	case 13484ULL: goto x86_l_34ac;
	case 13488ULL: goto x86_l_34b0;
	case 13492ULL: goto x86_l_34b4;
	case 13495ULL: goto x86_l_34b7;
	case 13497ULL: goto x86_l_34b9;
	case 13504ULL: goto x86_l_34c0;
	case 13506ULL: goto x86_l_34c2;
	case 13509ULL: goto x86_l_34c5;
	case 13512ULL: goto x86_l_34c8;
	case 13514ULL: goto x86_l_34ca;
	case 13519ULL: goto x86_l_34cf;
	case 13521ULL: goto x86_l_34d1;
	case 13525ULL: goto x86_l_34d5;
	case 13527ULL: goto x86_l_34d7;
	case 13531ULL: goto x86_l_34db;
	case 13533ULL: goto x86_l_34dd;
	case 13538ULL: goto x86_l_34e2;
	case 13540ULL: goto x86_l_34e4;
	case 13544ULL: goto x86_l_34e8;
	case 13546ULL: goto x86_l_34ea;
	case 13550ULL: goto x86_l_34ee;
	case 13554ULL: goto x86_l_34f2;
	case 13558ULL: goto x86_l_34f6;
	case 13565ULL: goto x86_l_34fd;
	case 13567ULL: goto x86_l_34ff;
	case 13572ULL: goto x86_l_3504;
	case 13577ULL: goto x86_l_3509;
	case 13583ULL: goto x86_l_350f;
	case 13587ULL: goto x86_l_3513;
	case 13593ULL: goto x86_l_3519;
	case 13602ULL: goto x86_l_3522;
	case 13611ULL: goto x86_l_352b;
	case 13620ULL: goto x86_l_3534;
	case 13624ULL: goto x86_l_3538;
	case 13629ULL: goto x86_l_353d;
	case 13634ULL: goto x86_l_3542;
	case 13642ULL: goto x86_l_354a;
	case 13647ULL: goto x86_l_354f;
	case 13655ULL: goto x86_l_3557;
	case 13660ULL: goto x86_l_355c;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13677ULL: goto x86_l_356d;
	case 13679ULL: goto x86_l_356f;
	case 13682ULL: goto x86_l_3572;
	case 13688ULL: goto x86_l_3578;
	case 13691ULL: goto x86_l_357b;
	case 13698ULL: goto x86_l_3582;
	case 13701ULL: goto x86_l_3585;
	case 13703ULL: goto x86_l_3587;
	case 13708ULL: goto x86_l_358c;
	case 13710ULL: goto x86_l_358e;
	case 13712ULL: goto x86_l_3590;
	case 13716ULL: goto x86_l_3594;
	case 13718ULL: goto x86_l_3596;
	case 13723ULL: goto x86_l_359b;
	case 13725ULL: goto x86_l_359d;
	case 13727ULL: goto x86_l_359f;
	case 13731ULL: goto x86_l_35a3;
	case 13741ULL: goto x86_l_35ad;
	case 13744ULL: goto x86_l_35b0;
	case 13749ULL: goto x86_l_35b5;
	case 13753ULL: goto x86_l_35b9;
	case 13757ULL: goto x86_l_35bd;
	case 13764ULL: goto x86_l_35c4;
	case 13769ULL: goto x86_l_35c9;
	case 13773ULL: goto x86_l_35cd;
	case 13781ULL: goto x86_l_35d5;
	case 13791ULL: goto x86_l_35df;
	case 13795ULL: goto x86_l_35e3;
	case 13800ULL: goto x86_l_35e8;
	case 13802ULL: goto x86_l_35ea;
	case 13805ULL: goto x86_l_35ed;
	case 13807ULL: goto x86_l_35ef;
	case 13814ULL: goto x86_l_35f6;
	case 13817ULL: goto x86_l_35f9;
	case 13820ULL: goto x86_l_35fc;
	case 13822ULL: goto x86_l_35fe;
	case 13825ULL: goto x86_l_3601;
	case 13827ULL: goto x86_l_3603;
	case 13830ULL: goto x86_l_3606;
	case 13832ULL: goto x86_l_3608;
	case 13839ULL: goto x86_l_360f;
	case 13847ULL: goto x86_l_3617;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13857ULL: goto x86_l_3621;
	case 13859ULL: goto x86_l_3623;
	case 13863ULL: goto x86_l_3627;
	case 13867ULL: goto x86_l_362b;
	case 13870ULL: goto x86_l_362e;
	case 13875ULL: goto x86_l_3633;
	case 13877ULL: goto x86_l_3635;
	case 13882ULL: goto x86_l_363a;
	case 13889ULL: goto x86_l_3641;
	case 13894ULL: goto x86_l_3646;
	case 13899ULL: goto x86_l_364b;
	case 13901ULL: goto x86_l_364d;
	case 13904ULL: goto x86_l_3650;
	case 13907ULL: goto x86_l_3653;
	case 13913ULL: goto x86_l_3659;
	case 13920ULL: goto x86_l_3660;
	case 13923ULL: goto x86_l_3663;
	case 13925ULL: goto x86_l_3665;
	case 13932ULL: goto x86_l_366c;
	case 13937ULL: goto x86_l_3671;
	case 13942ULL: goto x86_l_3676;
	case 13944ULL: goto x86_l_3678;
	case 13949ULL: goto x86_l_367d;
	case 13952ULL: goto x86_l_3680;
	case 13957ULL: goto x86_l_3685;
	case 13959ULL: goto x86_l_3687;
	case 13961ULL: goto x86_l_3689;
	case 13965ULL: goto x86_l_368d;
	case 13967ULL: goto x86_l_368f;
	case 13969ULL: goto x86_l_3691;
	case 13971ULL: goto x86_l_3693;
	case 13979ULL: goto x86_l_369b;
	case 13986ULL: goto x86_l_36a2;
	case 13989ULL: goto x86_l_36a5;
	case 13996ULL: goto x86_l_36ac;
	case 14004ULL: goto x86_l_36b4;
	case 14009ULL: goto x86_l_36b9;
	case 14011ULL: goto x86_l_36bb;
	case 14014ULL: goto x86_l_36be;
	case 14016ULL: goto x86_l_36c0;
	case 14019ULL: goto x86_l_36c3;
	case 14021ULL: goto x86_l_36c5;
	case 14024ULL: goto x86_l_36c8;
	case 14029ULL: goto x86_l_36cd;
	case 14036ULL: goto x86_l_36d4;
	case 14041ULL: goto x86_l_36d9;
	case 14046ULL: goto x86_l_36de;
	case 14048ULL: goto x86_l_36e0;
	case 14051ULL: goto x86_l_36e3;
	case 14054ULL: goto x86_l_36e6;
	case 14056ULL: goto x86_l_36e8;
	case 14065ULL: goto x86_l_36f1;
	case 14074ULL: goto x86_l_36fa;
	case 14083ULL: goto x86_l_3703;
	case 14092ULL: goto x86_l_370c;
	default: return 0xffffffffffffffffULL;
	}
x86_l_308c:
	/* 0x308c: jne    31b1 <tail_handle_ipv6_from_netdev+0x31b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31b1;
	}
x86_l_3092:
	/* 0x3092: movzx  eax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_3097:
	/* 0x3097: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_3099:
	/* 0x3099: je     31b1 <tail_handle_ipv6_from_netdev+0x31b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31b1;
	}
x86_l_309f:
	/* 0x309f: mov    WORD PTR [r13+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_30a6:
	/* 0x30a6: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_30ab:
	/* 0x30ab: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30b0:
	/* 0x30b0: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_30b7:
	/* 0x30b7: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30ba:
	/* 0x30ba: je     43f8 <tail_handle_ipv6_from_netdev+0x43f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17400ULL;
	}
x86_l_30c0:
	/* 0x30c0: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_30c7:
	/* 0x30c7: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_30cb:
	/* 0x30cb: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_30cf:
	/* 0x30cf: jmp    43fe <tail_handle_ipv6_from_netdev+0x43fe> */
	return 17406ULL;
x86_l_30d4:
	/* 0x30d4: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_30d7:
	/* 0x30d7: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_30da:
	/* 0x30da: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_30dd:
	/* 0x30dd: or     ax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_30e2:
	/* 0x30e2: or     eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_30e5:
	/* 0x30e5: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30ea:
	/* 0x30ea: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_30f1:
	/* 0x30f1: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f3:
	/* 0x30f3: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_30f8:
	/* 0x30f8: mov    DWORD PTR [rcx+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_30fb:
	/* 0x30fb: mov    eax,DWORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30ff:
	/* 0x30ff: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3101:
	/* 0x3101: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_3103:
	/* 0x3103: jne    31b1 <tail_handle_ipv6_from_netdev+0x31b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_31b1;
	}
x86_l_3109:
	/* 0x3109: mov    r14,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3110:
	/* 0x3110: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3114:
	/* 0x3114: je     3129 <tail_handle_ipv6_from_netdev+0x3129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3129;
	}
x86_l_3116:
	/* 0x3116: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_311d:
	/* 0x311d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311f:
	/* 0x311f: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3121:
	/* 0x3121: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_3124:
	/* 0x3124: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3127:
	/* 0x3127: jmp    312e <tail_handle_ipv6_from_netdev+0x312e> */
	goto x86_l_312e;
x86_l_3129:
	/* 0x3129: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_312e:
	/* 0x312e: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3132:
	/* 0x3132: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3136:
	/* 0x3136: je     3147 <tail_handle_ipv6_from_netdev+0x3147> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3147;
	}
x86_l_3138:
	/* 0x3138: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_313d:
	/* 0x313d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_313f:
	/* 0x313f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3141:
	/* 0x3141: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_3145:
	/* 0x3145: jmp    316a <tail_handle_ipv6_from_netdev+0x316a> */
	goto x86_l_316a;
x86_l_3147:
	/* 0x3147: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_314c:
	/* 0x314c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_314e:
	/* 0x314e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3150:
	/* 0x3150: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_3154:
	/* 0x3154: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_315e:
	/* 0x315e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3161:
	/* 0x3161: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3166:
	/* 0x3166: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_316a:
	/* 0x316a: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_316c:
	/* 0x316c: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3170:
	/* 0x3170: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_3175:
	/* 0x3175: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3179:
	/* 0x3179: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_317d:
	/* 0x317d: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3181:
	/* 0x3181: je     3194 <tail_handle_ipv6_from_netdev+0x3194> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3194;
	}
x86_l_3183:
	/* 0x3183: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_318a:
	/* 0x318a: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_318c:
	/* 0x318c: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_318f:
	/* 0x318f: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3192:
	/* 0x3192: jmp    3199 <tail_handle_ipv6_from_netdev+0x3199> */
	goto x86_l_3199;
x86_l_3194:
	/* 0x3194: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_3199:
	/* 0x3199: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_319b:
	/* 0x319b: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_319e:
	/* 0x319e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_31a0:
	/* 0x31a0: jb     31a7 <tail_handle_ipv6_from_netdev+0x31a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31a7;
	}
x86_l_31a2:
	/* 0x31a2: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_31a5:
	/* 0x31a5: je     31b1 <tail_handle_ipv6_from_netdev+0x31b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31b1;
	}
x86_l_31a7:
	/* 0x31a7: mov    BYTE PTR [r13+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_31ab:
	/* 0x31ab: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_31af:
	/* 0x31af: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31b1:
	/* 0x31b1: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_31b6:
	/* 0x31b6: movzx  eax,BYTE PTR [rax+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_31ba:
	/* 0x31ba: and    al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_31bc:
	/* 0x31bc: cmp    al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_31be:
	/* 0x31be: mov    ebx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 3ULL);
x86_l_31c3:
	/* 0x31c3: sbb    ebx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_31c6:
	/* 0x31c6: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_31cb:
	/* 0x31cb: mov    DWORD PTR [rax+0x4c],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_31ce:
	/* 0x31ce: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_31d3:
	/* 0x31d3: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31d8:
	/* 0x31d8: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31dd:
	/* 0x31dd: mov    DWORD PTR [rbp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_31e0:
	/* 0x31e0: mov    DWORD PTR [rbp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31e4:
	/* 0x31e4: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_31eb:
	/* 0x31eb: mov    r14d,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 44ULL);
x86_l_31f1:
	/* 0x31f1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_31f6:
	/* 0x31f6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_31f9:
	/* 0x31f9: mov    edx,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 44ULL);
x86_l_31fe:
	/* 0x31fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3200:
	/* 0x3200: mov    eax,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967156ULL);
x86_l_3205:
	/* 0x3205: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_320a:
	/* 0x320a: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_320d:
	/* 0x320d: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_3214:
	/* 0x3214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3219:
	/* 0x3219: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_321e:
	/* 0x321e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3220:
	/* 0x3220: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3223:
	/* 0x3223: je     32b3 <tail_handle_ipv6_from_netdev+0x32b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32b3;
	}
x86_l_3229:
	/* 0x3229: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_322b:
	/* 0x322b: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3232:
	/* 0x3232: jmp    32eb <tail_handle_ipv6_from_netdev+0x32eb> */
	goto x86_l_32eb;
x86_l_3237:
	/* 0x3237: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_323e:
	/* 0x323e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3243:
	/* 0x3243: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3248:
	/* 0x3248: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_324b:
	/* 0x324b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_324d:
	/* 0x324d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324f:
	/* 0x324f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3251:
	/* 0x3251: je     c96 <tail_handle_ipv6_from_netdev+0xc96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3222ULL;
	}
x86_l_3257:
	/* 0x3257: mov    r14d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_325b:
	/* 0x325b: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3264:
	/* 0x3264: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_326d:
	/* 0x326d: movabs rax,0x7201a9010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654124810ULL);
x86_l_3277:
	/* 0x3277: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_327d:
	/* 0x327d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3285:
	/* 0x3285: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_328c:
	/* 0x328c: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3294:
	/* 0x3294: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3299:
	/* 0x3299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_329b:
	/* 0x329b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_329e:
	/* 0x329e: je     32c0 <tail_handle_ipv6_from_netdev+0x32c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_32c0;
	}
x86_l_32a0:
	/* 0x32a0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_32a3:
	/* 0x32a3: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_32a7:
	/* 0x32a7: jmp    32eb <tail_handle_ipv6_from_netdev+0x32eb> */
	goto x86_l_32eb;
x86_l_32a9:
	/* 0x32a9: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_32ae:
	/* 0x32ae: jmp    ffb <tail_handle_ipv6_from_netdev+0xffb> */
	return 4091ULL;
x86_l_32b3:
	/* 0x32b3: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_32b8:
	/* 0x32b8: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_32bb:
	/* 0x32bb: jmp    fb3 <tail_handle_ipv6_from_netdev+0xfb3> */
	return 4019ULL;
x86_l_32c0:
	/* 0x32c0: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_32c9:
	/* 0x32c9: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_32ce:
	/* 0x32ce: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_32d5:
	/* 0x32d5: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_32dd:
	/* 0x32dd: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32e2:
	/* 0x32e2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_32e7:
	/* 0x32e7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32e9:
	/* 0x32e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32eb:
	/* 0x32eb: mov    r15,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_32f2:
	/* 0x32f2: jmp    c96 <tail_handle_ipv6_from_netdev+0xc96> */
	return 3222ULL;
x86_l_32f7:
	/* 0x32f7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32fa:
	/* 0x32fa: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32ff:
	/* 0x32ff: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
x86_l_3304:
	/* 0x3304: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_3309:
	/* 0x3309: jmp    1777 <tail_handle_ipv6_from_netdev+0x1777> */
	return 6007ULL;
x86_l_330e:
	/* 0x330e: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_3315:
	/* 0x3315: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_331a:
	/* 0x331a: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_331d:
	/* 0x331d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_331f:
	/* 0x331f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3322:
	/* 0x3322: je     33d8 <tail_handle_ipv6_from_netdev+0x33d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d8;
	}
x86_l_3328:
	/* 0x3328: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_332a:
	/* 0x332a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332f:
	/* 0x332f: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3331:
	/* 0x3331: jmp    24fc <tail_handle_ipv6_from_netdev+0x24fc> */
	return 9468ULL;
x86_l_3336:
	/* 0x3336: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_333c:
	/* 0x333c: jmp    28e7 <tail_handle_ipv6_from_netdev+0x28e7> */
	return 10471ULL;
x86_l_3341:
	/* 0x3341: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_3347:
	/* 0x3347: jmp    2568 <tail_handle_ipv6_from_netdev+0x2568> */
	return 9576ULL;
x86_l_334c:
	/* 0x334c: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_3353:
	/* 0x3353: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3358:
	/* 0x3358: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_335b:
	/* 0x335b: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3360:
	/* 0x3360: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3362:
	/* 0x3362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3364:
	/* 0x3364: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3366:
	/* 0x3366: je     24fc <tail_handle_ipv6_from_netdev+0x24fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9468ULL;
	}
x86_l_336c:
	/* 0x336c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3371:
	/* 0x3371: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3374:
	/* 0x3374: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_337d:
	/* 0x337d: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3386:
	/* 0x3386: movabs rax,0x7201a9010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654124810ULL);
x86_l_3390:
	/* 0x3390: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3398:
	/* 0x3398: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_339f:
	/* 0x339f: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_33a7:
	/* 0x33a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33ac:
	/* 0x33ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33ae:
	/* 0x33ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33b1:
	/* 0x33b1: je     33e3 <tail_handle_ipv6_from_netdev+0x33e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33e3;
	}
x86_l_33b3:
	/* 0x33b3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_33b6:
	/* 0x33b6: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_33ba:
	/* 0x33ba: mov    QWORD PTR [r13+0x0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33be:
	/* 0x33be: jmp    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	return 11780ULL;
x86_l_33c3:
	/* 0x33c3: mov    r15d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967139ULL);
x86_l_33c9:
	/* 0x33c9: jmp    2568 <tail_handle_ipv6_from_netdev+0x2568> */
	return 9576ULL;
x86_l_33ce:
	/* 0x33ce: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_33d3:
	/* 0x33d3: jmp    2f1f <tail_handle_ipv6_from_netdev+0x2f1f> */
	return 12063ULL;
x86_l_33d8:
	/* 0x33d8: mov    r15d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967121ULL);
x86_l_33de:
	/* 0x33de: jmp    255c <tail_handle_ipv6_from_netdev+0x255c> */
	return 9564ULL;
x86_l_33e3:
	/* 0x33e3: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_33ec:
	/* 0x33ec: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33f1:
	/* 0x33f1: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_33f8:
	/* 0x33f8: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3400:
	/* 0x3400: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3405:
	/* 0x3405: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_340a:
	/* 0x340a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_340c:
	/* 0x340c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_340e:
	/* 0x340e: mov    QWORD PTR [r13+0x0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3412:
	/* 0x3412: jmp    2e04 <tail_handle_ipv6_from_netdev+0x2e04> */
	return 11780ULL;
x86_l_3417:
	/* 0x3417: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_341d:
	/* 0x341d: cmp    BYTE PTR [rsp+0x73],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239046ULL);
x86_l_3422:
	/* 0x3422: jne    345c <tail_handle_ipv6_from_netdev+0x345c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_345c;
	}
x86_l_3424:
	/* 0x3424: mov    ecx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_3428:
	/* 0x3428: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_342a:
	/* 0x342a: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_342d:
	/* 0x342d: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_3430:
	/* 0x3430: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3432:
	/* 0x3432: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3437:
	/* 0x3437: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_3439:
	/* 0x3439: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_343e:
	/* 0x343e: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_3444:
	/* 0x3444: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_3448:
	/* 0x3448: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_344b:
	/* 0x344b: je     345c <tail_handle_ipv6_from_netdev+0x345c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_345c;
	}
x86_l_344d:
	/* 0x344d: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3454:
	/* 0x3454: imul   r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_3458:
	/* 0x3458: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_345c:
	/* 0x345c: shr    DWORD PTR [rsp+0x74],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 498216206344ULL);
x86_l_3461:
	/* 0x3461: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3464:
	/* 0x3464: je     3475 <tail_handle_ipv6_from_netdev+0x3475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3475;
	}
x86_l_3466:
	/* 0x3466: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_346b:
	/* 0x346b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_346d:
	/* 0x346d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_346f:
	/* 0x346f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_3473:
	/* 0x3473: jmp    3498 <tail_handle_ipv6_from_netdev+0x3498> */
	goto x86_l_3498;
x86_l_3475:
	/* 0x3475: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_347a:
	/* 0x347a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_347c:
	/* 0x347c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_347e:
	/* 0x347e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_3482:
	/* 0x3482: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_348c:
	/* 0x348c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_348f:
	/* 0x348f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3494:
	/* 0x3494: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_3498:
	/* 0x3498: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_349b:
	/* 0x349b: mov    DWORD PTR [r13+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_349f:
	/* 0x349f: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_34a4:
	/* 0x34a4: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34a8:
	/* 0x34a8: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_34ac:
	/* 0x34ac: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_34b0:
	/* 0x34b0: mov    DWORD PTR [rsp+0x74],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_34b4:
	/* 0x34b4: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34b7:
	/* 0x34b7: je     34ca <tail_handle_ipv6_from_netdev+0x34ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34ca;
	}
x86_l_34b9:
	/* 0x34b9: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_34c0:
	/* 0x34c0: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c2:
	/* 0x34c2: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_34c5:
	/* 0x34c5: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_34c8:
	/* 0x34c8: jmp    34cf <tail_handle_ipv6_from_netdev+0x34cf> */
	goto x86_l_34cf;
x86_l_34ca:
	/* 0x34ca: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_34cf:
	/* 0x34cf: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34d1:
	/* 0x34d1: mov    edx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_34d5:
	/* 0x34d5: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_34d7:
	/* 0x34d7: mov    DWORD PTR [rsp+0x74],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_34db:
	/* 0x34db: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_34dd:
	/* 0x34dd: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_34e2:
	/* 0x34e2: jb     34ea <tail_handle_ipv6_from_netdev+0x34ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_34ea;
	}
x86_l_34e4:
	/* 0x34e4: cmp    cl,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_34e8:
	/* 0x34e8: je     3504 <tail_handle_ipv6_from_netdev+0x3504> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3504;
	}
x86_l_34ea:
	/* 0x34ea: mov    ecx,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_34ee:
	/* 0x34ee: mov    BYTE PTR [r13+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_34f2:
	/* 0x34f2: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_34f6:
	/* 0x34f6: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_34fd:
	/* 0x34fd: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ff:
	/* 0x34ff: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3504:
	/* 0x3504: cmp    WORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3509:
	/* 0x3509: je     375e <tail_handle_ipv6_from_netdev+0x375e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14174ULL;
	}
x86_l_350f:
	/* 0x350f: test   BYTE PTR [rbx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_3513:
	/* 0x3513: je     367d <tail_handle_ipv6_from_netdev+0x367d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367d;
	}
x86_l_3519:
	/* 0x3519: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3522:
	/* 0x3522: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_352b:
	/* 0x352b: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3534:
	/* 0x3534: movzx  eax,WORD PTR [rbx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_3538:
	/* 0x3538: mov    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_353d:
	/* 0x353d: mov    BYTE PTR [rsp+0x3a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 249108103168ULL);
x86_l_3542:
	/* 0x3542: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_354a:
	/* 0x354a: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_354f:
	/* 0x354f: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_3557:
	/* 0x3557: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_355c:
	/* 0x355c: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_3563:
	/* 0x3563: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3568:
	/* 0x3568: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_356d:
	/* 0x356d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_356f:
	/* 0x356f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3572:
	/* 0x3572: je     3678 <tail_handle_ipv6_from_netdev+0x3678> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3678;
	}
x86_l_3578:
	/* 0x3578: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_357b:
	/* 0x357b: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3582:
	/* 0x3582: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3585:
	/* 0x3585: je     3596 <tail_handle_ipv6_from_netdev+0x3596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3596;
	}
x86_l_3587:
	/* 0x3587: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_358c:
	/* 0x358c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_358e:
	/* 0x358e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3590:
	/* 0x3590: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_3594:
	/* 0x3594: jmp    35b9 <tail_handle_ipv6_from_netdev+0x35b9> */
	goto x86_l_35b9;
x86_l_3596:
	/* 0x3596: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_359b:
	/* 0x359b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_359d:
	/* 0x359d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_359f:
	/* 0x359f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_35a3:
	/* 0x35a3: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_35ad:
	/* 0x35ad: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_35b0:
	/* 0x35b0: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_35b5:
	/* 0x35b5: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_35b9:
	/* 0x35b9: mov    ecx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_35bd:
	/* 0x35bd: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_35c4:
	/* 0x35c4: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35c9:
	/* 0x35c9: movzx  ecx,WORD PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_35cd:
	/* 0x35cd: mov    WORD PTR [rsp+0x8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_35d5:
	/* 0x35d5: mov    WORD PTR [rsp+0x8e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_35df:
	/* 0x35df: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e3:
	/* 0x35e3: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_35e8:
	/* 0x35e8: and    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_35ea:
	/* 0x35ea: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ed:
	/* 0x35ed: je     35fc <tail_handle_ipv6_from_netdev+0x35fc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35fc;
	}
x86_l_35ef:
	/* 0x35ef: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_35f6:
	/* 0x35f6: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_35f9:
	/* 0x35f9: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_35fc:
	/* 0x35fc: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_35fe:
	/* 0x35fe: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3601:
	/* 0x3601: mov    ebx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_32);
x86_l_3603:
	/* 0x3603: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3606:
	/* 0x3606: jbe    3665 <tail_handle_ipv6_from_netdev+0x3665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_3665;
	}
x86_l_3608:
	/* 0x3608: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_360f:
	/* 0x360f: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3617:
	/* 0x3617: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_361c:
	/* 0x361c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361e:
	/* 0x361e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3621:
	/* 0x3621: je     3665 <tail_handle_ipv6_from_netdev+0x3665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3665;
	}
x86_l_3623:
	/* 0x3623: mov    QWORD PTR [r13+0x0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3627:
	/* 0x3627: mov    r14d,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_362b:
	/* 0x362b: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_362e:
	/* 0x362e: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3633:
	/* 0x3633: je     367d <tail_handle_ipv6_from_netdev+0x367d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_367d;
	}
x86_l_3635:
	/* 0x3635: mov    DWORD PTR [rsp+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_363a:
	/* 0x363a: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_3641:
	/* 0x3641: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3646:
	/* 0x3646: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_364b:
	/* 0x364b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_364d:
	/* 0x364d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3650:
	/* 0x3650: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3653:
	/* 0x3653: jne    36e8 <tail_handle_ipv6_from_netdev+0x36e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_36e8;
	}
x86_l_3659:
	/* 0x3659: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_3660:
	/* 0x3660: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3663:
	/* 0x3663: jmp    3678 <tail_handle_ipv6_from_netdev+0x3678> */
	goto x86_l_3678;
x86_l_3665:
	/* 0x3665: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_366c:
	/* 0x366c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3671:
	/* 0x3671: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3676:
	/* 0x3676: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3678:
	/* 0x3678: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_367d:
	/* 0x367d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3680:
	/* 0x3680: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3685:
	/* 0x3685: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3687:
	/* 0x3687: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3689:
	/* 0x3689: movzx  ecx,WORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_368d:
	/* 0x368d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_368f:
	/* 0x368f: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_3691:
	/* 0x3691: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3693:
	/* 0x3693: mov    WORD PTR [rsp+0xda],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 218ULL);
x86_l_369b:
	/* 0x369b: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_36a2:
	/* 0x36a2: movzx  eax,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_36a5:
	/* 0x36a5: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_36ac:
	/* 0x36ac: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_36b4:
	/* 0x36b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36b9:
	/* 0x36b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36bb:
	/* 0x36bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36be:
	/* 0x36be: je     36c5 <tail_handle_ipv6_from_netdev+0x36c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36c5;
	}
x86_l_36c0:
	/* 0x36c0: mov    r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c3:
	/* 0x36c3: jmp    36c8 <tail_handle_ipv6_from_netdev+0x36c8> */
	goto x86_l_36c8;
x86_l_36c5:
	/* 0x36c5: movzx  eax,BYTE PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_36c8:
	/* 0x36c8: mov    DWORD PTR [rsp+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36cd:
	/* 0x36cd: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_36d4:
	/* 0x36d4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_36d9:
	/* 0x36d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_36de:
	/* 0x36de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36e0:
	/* 0x36e0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_36e3:
	/* 0x36e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36e6:
	/* 0x36e6: je     3754 <tail_handle_ipv6_from_netdev+0x3754> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 14164ULL;
	}
x86_l_36e8:
	/* 0x36e8: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_36f1:
	/* 0x36f1: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_36fa:
	/* 0x36fa: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3703:
	/* 0x3703: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_370c:
	/* 0x370c: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
	return 14101ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 14101ULL: goto x86_l_3715;
	case 14110ULL: goto x86_l_371e;
	case 14119ULL: goto x86_l_3727;
	case 14124ULL: goto x86_l_372c;
	case 14129ULL: goto x86_l_3731;
	case 14132ULL: goto x86_l_3734;
	case 14137ULL: goto x86_l_3739;
	case 14144ULL: goto x86_l_3740;
	case 14147ULL: goto x86_l_3743;
	case 14149ULL: goto x86_l_3745;
	case 14156ULL: goto x86_l_374c;
	case 14159ULL: goto x86_l_374f;
	case 14162ULL: goto x86_l_3752;
	case 14164ULL: goto x86_l_3754;
	case 14171ULL: goto x86_l_375b;
	case 14174ULL: goto x86_l_375e;
	case 14181ULL: goto x86_l_3765;
	case 14184ULL: goto x86_l_3768;
	case 14186ULL: goto x86_l_376a;
	case 14191ULL: goto x86_l_376f;
	case 14196ULL: goto x86_l_3774;
	case 14199ULL: goto x86_l_3777;
	case 14205ULL: goto x86_l_377d;
	case 14210ULL: goto x86_l_3782;
	case 14215ULL: goto x86_l_3787;
	case 14219ULL: goto x86_l_378b;
	case 14221ULL: goto x86_l_378d;
	case 14224ULL: goto x86_l_3790;
	case 14226ULL: goto x86_l_3792;
	case 14233ULL: goto x86_l_3799;
	case 14236ULL: goto x86_l_379c;
	case 14239ULL: goto x86_l_379f;
	case 14241ULL: goto x86_l_37a1;
	case 14246ULL: goto x86_l_37a6;
	case 14250ULL: goto x86_l_37aa;
	case 14253ULL: goto x86_l_37ad;
	case 14256ULL: goto x86_l_37b0;
	case 14262ULL: goto x86_l_37b6;
	case 14267ULL: goto x86_l_37bb;
	case 14272ULL: goto x86_l_37c0;
	case 14275ULL: goto x86_l_37c3;
	case 14280ULL: goto x86_l_37c8;
	case 14285ULL: goto x86_l_37cd;
	case 14288ULL: goto x86_l_37d0;
	case 14290ULL: goto x86_l_37d2;
	case 14295ULL: goto x86_l_37d7;
	case 14297ULL: goto x86_l_37d9;
	case 14299ULL: goto x86_l_37db;
	case 14303ULL: goto x86_l_37df;
	case 14305ULL: goto x86_l_37e1;
	case 14310ULL: goto x86_l_37e6;
	case 14312ULL: goto x86_l_37e8;
	case 14314ULL: goto x86_l_37ea;
	case 14318ULL: goto x86_l_37ee;
	case 14328ULL: goto x86_l_37f8;
	case 14331ULL: goto x86_l_37fb;
	case 14336ULL: goto x86_l_3800;
	case 14340ULL: goto x86_l_3804;
	case 14344ULL: goto x86_l_3808;
	case 14347ULL: goto x86_l_380b;
	case 14349ULL: goto x86_l_380d;
	case 14353ULL: goto x86_l_3811;
	case 14358ULL: goto x86_l_3816;
	case 14362ULL: goto x86_l_381a;
	case 14364ULL: goto x86_l_381c;
	case 14367ULL: goto x86_l_381f;
	case 14369ULL: goto x86_l_3821;
	case 14376ULL: goto x86_l_3828;
	case 14378ULL: goto x86_l_382a;
	case 14381ULL: goto x86_l_382d;
	case 14384ULL: goto x86_l_3830;
	case 14386ULL: goto x86_l_3832;
	case 14391ULL: goto x86_l_3837;
	case 14393ULL: goto x86_l_3839;
	case 14395ULL: goto x86_l_383b;
	case 14397ULL: goto x86_l_383d;
	case 14399ULL: goto x86_l_383f;
	case 14401ULL: goto x86_l_3841;
	case 14403ULL: goto x86_l_3843;
	case 14407ULL: goto x86_l_3847;
	case 14411ULL: goto x86_l_384b;
	case 14418ULL: goto x86_l_3852;
	case 14420ULL: goto x86_l_3854;
	case 14427ULL: goto x86_l_385b;
	case 14430ULL: goto x86_l_385e;
	case 14432ULL: goto x86_l_3860;
	case 14441ULL: goto x86_l_3869;
	case 14446ULL: goto x86_l_386e;
	case 14448ULL: goto x86_l_3870;
	case 14453ULL: goto x86_l_3875;
	case 14461ULL: goto x86_l_387d;
	case 14466ULL: goto x86_l_3882;
	case 14471ULL: goto x86_l_3887;
	case 14476ULL: goto x86_l_388c;
	case 14478ULL: goto x86_l_388e;
	case 14480ULL: goto x86_l_3890;
	case 14482ULL: goto x86_l_3892;
	case 14488ULL: goto x86_l_3898;
	case 14496ULL: goto x86_l_38a0;
	case 14503ULL: goto x86_l_38a7;
	case 14508ULL: goto x86_l_38ac;
	case 14512ULL: goto x86_l_38b0;
	case 14518ULL: goto x86_l_38b6;
	case 14525ULL: goto x86_l_38bd;
	case 14528ULL: goto x86_l_38c0;
	case 14530ULL: goto x86_l_38c2;
	case 14535ULL: goto x86_l_38c7;
	case 14537ULL: goto x86_l_38c9;
	case 14539ULL: goto x86_l_38cb;
	case 14543ULL: goto x86_l_38cf;
	case 14545ULL: goto x86_l_38d1;
	case 14550ULL: goto x86_l_38d6;
	case 14552ULL: goto x86_l_38d8;
	case 14554ULL: goto x86_l_38da;
	case 14558ULL: goto x86_l_38de;
	case 14568ULL: goto x86_l_38e8;
	case 14571ULL: goto x86_l_38eb;
	case 14576ULL: goto x86_l_38f0;
	case 14580ULL: goto x86_l_38f4;
	case 14589ULL: goto x86_l_38fd;
	case 14598ULL: goto x86_l_3906;
	case 14607ULL: goto x86_l_390f;
	case 14612ULL: goto x86_l_3914;
	case 14616ULL: goto x86_l_3918;
	case 14621ULL: goto x86_l_391d;
	case 14626ULL: goto x86_l_3922;
	case 14628ULL: goto x86_l_3924;
	case 14636ULL: goto x86_l_392c;
	case 14644ULL: goto x86_l_3934;
	case 14655ULL: goto x86_l_393f;
	case 14663ULL: goto x86_l_3947;
	case 14668ULL: goto x86_l_394c;
	case 14676ULL: goto x86_l_3954;
	case 14681ULL: goto x86_l_3959;
	case 14688ULL: goto x86_l_3960;
	case 14693ULL: goto x86_l_3965;
	case 14701ULL: goto x86_l_396d;
	case 14706ULL: goto x86_l_3972;
	case 14708ULL: goto x86_l_3974;
	case 14710ULL: goto x86_l_3976;
	case 14718ULL: goto x86_l_397e;
	case 14727ULL: goto x86_l_3987;
	case 14736ULL: goto x86_l_3990;
	case 14740ULL: goto x86_l_3994;
	case 14744ULL: goto x86_l_3998;
	case 14749ULL: goto x86_l_399d;
	case 14754ULL: goto x86_l_39a2;
	case 14759ULL: goto x86_l_39a7;
	case 14766ULL: goto x86_l_39ae;
	case 14771ULL: goto x86_l_39b3;
	case 14776ULL: goto x86_l_39b8;
	case 14778ULL: goto x86_l_39ba;
	case 14782ULL: goto x86_l_39be;
	case 14787ULL: goto x86_l_39c3;
	case 14790ULL: goto x86_l_39c6;
	case 14792ULL: goto x86_l_39c8;
	case 14795ULL: goto x86_l_39cb;
	case 14800ULL: goto x86_l_39d0;
	case 14805ULL: goto x86_l_39d5;
	case 14807ULL: goto x86_l_39d7;
	case 14813ULL: goto x86_l_39dd;
	case 14815ULL: goto x86_l_39df;
	case 14820ULL: goto x86_l_39e4;
	case 14824ULL: goto x86_l_39e8;
	case 14826ULL: goto x86_l_39ea;
	case 14828ULL: goto x86_l_39ec;
	case 14831ULL: goto x86_l_39ef;
	case 14833ULL: goto x86_l_39f1;
	case 14838ULL: goto x86_l_39f6;
	case 14844ULL: goto x86_l_39fc;
	case 14847ULL: goto x86_l_39ff;
	case 14852ULL: goto x86_l_3a04;
	case 14857ULL: goto x86_l_3a09;
	case 14863ULL: goto x86_l_3a0f;
	case 14869ULL: goto x86_l_3a15;
	case 14872ULL: goto x86_l_3a18;
	case 14880ULL: goto x86_l_3a20;
	case 14888ULL: goto x86_l_3a28;
	case 14893ULL: goto x86_l_3a2d;
	case 14898ULL: goto x86_l_3a32;
	case 14906ULL: goto x86_l_3a3a;
	case 14910ULL: goto x86_l_3a3e;
	case 14918ULL: goto x86_l_3a46;
	case 14922ULL: goto x86_l_3a4a;
	case 14930ULL: goto x86_l_3a52;
	case 14935ULL: goto x86_l_3a57;
	case 14938ULL: goto x86_l_3a5a;
	case 14940ULL: goto x86_l_3a5c;
	case 14948ULL: goto x86_l_3a64;
	case 14951ULL: goto x86_l_3a67;
	case 14953ULL: goto x86_l_3a69;
	case 14963ULL: goto x86_l_3a73;
	case 14971ULL: goto x86_l_3a7b;
	case 14973ULL: goto x86_l_3a7d;
	case 14976ULL: goto x86_l_3a80;
	case 14980ULL: goto x86_l_3a84;
	case 14983ULL: goto x86_l_3a87;
	case 14988ULL: goto x86_l_3a8c;
	case 14991ULL: goto x86_l_3a8f;
	case 14994ULL: goto x86_l_3a92;
	case 14999ULL: goto x86_l_3a97;
	case 15002ULL: goto x86_l_3a9a;
	case 15004ULL: goto x86_l_3a9c;
	case 15006ULL: goto x86_l_3a9e;
	case 15012ULL: goto x86_l_3aa4;
	case 15017ULL: goto x86_l_3aa9;
	case 15022ULL: goto x86_l_3aae;
	case 15027ULL: goto x86_l_3ab3;
	case 15030ULL: goto x86_l_3ab6;
	case 15035ULL: goto x86_l_3abb;
	case 15038ULL: goto x86_l_3abe;
	case 15040ULL: goto x86_l_3ac0;
	case 15042ULL: goto x86_l_3ac2;
	case 15044ULL: goto x86_l_3ac4;
	case 15054ULL: goto x86_l_3ace;
	case 15062ULL: goto x86_l_3ad6;
	case 15068ULL: goto x86_l_3adc;
	case 15073ULL: goto x86_l_3ae1;
	case 15081ULL: goto x86_l_3ae9;
	case 15084ULL: goto x86_l_3aec;
	case 15090ULL: goto x86_l_3af2;
	case 15093ULL: goto x86_l_3af5;
	case 15099ULL: goto x86_l_3afb;
	case 15105ULL: goto x86_l_3b01;
	case 15108ULL: goto x86_l_3b04;
	case 15114ULL: goto x86_l_3b0a;
	case 15116ULL: goto x86_l_3b0c;
	case 15122ULL: goto x86_l_3b12;
	case 15127ULL: goto x86_l_3b17;
	case 15135ULL: goto x86_l_3b1f;
	case 15139ULL: goto x86_l_3b23;
	case 15142ULL: goto x86_l_3b26;
	case 15146ULL: goto x86_l_3b2a;
	case 15152ULL: goto x86_l_3b30;
	case 15155ULL: goto x86_l_3b33;
	case 15157ULL: goto x86_l_3b35;
	case 15159ULL: goto x86_l_3b37;
	case 15162ULL: goto x86_l_3b3a;
	case 15164ULL: goto x86_l_3b3c;
	case 15167ULL: goto x86_l_3b3f;
	case 15173ULL: goto x86_l_3b45;
	case 15175ULL: goto x86_l_3b47;
	case 15185ULL: goto x86_l_3b51;
	case 15193ULL: goto x86_l_3b59;
	case 15195ULL: goto x86_l_3b5b;
	case 15197ULL: goto x86_l_3b5d;
	case 15199ULL: goto x86_l_3b5f;
	case 15204ULL: goto x86_l_3b64;
	case 15207ULL: goto x86_l_3b67;
	case 15209ULL: goto x86_l_3b69;
	case 15212ULL: goto x86_l_3b6c;
	case 15214ULL: goto x86_l_3b6e;
	case 15222ULL: goto x86_l_3b76;
	case 15230ULL: goto x86_l_3b7e;
	case 15233ULL: goto x86_l_3b81;
	case 15241ULL: goto x86_l_3b89;
	case 15246ULL: goto x86_l_3b8e;
	case 15249ULL: goto x86_l_3b91;
	case 15254ULL: goto x86_l_3b96;
	case 15257ULL: goto x86_l_3b99;
	case 15259ULL: goto x86_l_3b9b;
	case 15261ULL: goto x86_l_3b9d;
	case 15267ULL: goto x86_l_3ba3;
	case 15275ULL: goto x86_l_3bab;
	case 15283ULL: goto x86_l_3bb3;
	case 15287ULL: goto x86_l_3bb7;
	case 15292ULL: goto x86_l_3bbc;
	case 15295ULL: goto x86_l_3bbf;
	case 15298ULL: goto x86_l_3bc2;
	case 15300ULL: goto x86_l_3bc4;
	case 15303ULL: goto x86_l_3bc7;
	case 15305ULL: goto x86_l_3bc9;
	case 15307ULL: goto x86_l_3bcb;
	case 15309ULL: goto x86_l_3bcd;
	case 15314ULL: goto x86_l_3bd2;
	case 15316ULL: goto x86_l_3bd4;
	case 15322ULL: goto x86_l_3bda;
	case 15328ULL: goto x86_l_3be0;
	case 15330ULL: goto x86_l_3be2;
	case 15335ULL: goto x86_l_3be7;
	case 15339ULL: goto x86_l_3beb;
	case 15345ULL: goto x86_l_3bf1;
	case 15353ULL: goto x86_l_3bf9;
	case 15361ULL: goto x86_l_3c01;
	case 15369ULL: goto x86_l_3c09;
	case 15377ULL: goto x86_l_3c11;
	case 15385ULL: goto x86_l_3c19;
	case 15393ULL: goto x86_l_3c21;
	case 15401ULL: goto x86_l_3c29;
	case 15409ULL: goto x86_l_3c31;
	case 15417ULL: goto x86_l_3c39;
	case 15425ULL: goto x86_l_3c41;
	case 15429ULL: goto x86_l_3c45;
	case 15431ULL: goto x86_l_3c47;
	case 15438ULL: goto x86_l_3c4e;
	case 15440ULL: goto x86_l_3c50;
	case 15446ULL: goto x86_l_3c56;
	case 15449ULL: goto x86_l_3c59;
	case 15454ULL: goto x86_l_3c5e;
	case 15457ULL: goto x86_l_3c61;
	case 15459ULL: goto x86_l_3c63;
	case 15462ULL: goto x86_l_3c66;
	case 15464ULL: goto x86_l_3c68;
	case 15470ULL: goto x86_l_3c6e;
	case 15473ULL: goto x86_l_3c71;
	case 15479ULL: goto x86_l_3c77;
	case 15484ULL: goto x86_l_3c7c;
	case 15491ULL: goto x86_l_3c83;
	case 15499ULL: goto x86_l_3c8b;
	case 15507ULL: goto x86_l_3c93;
	case 15514ULL: goto x86_l_3c9a;
	case 15517ULL: goto x86_l_3c9d;
	case 15523ULL: goto x86_l_3ca3;
	case 15532ULL: goto x86_l_3cac;
	case 15538ULL: goto x86_l_3cb2;
	case 15542ULL: goto x86_l_3cb6;
	case 15551ULL: goto x86_l_3cbf;
	case 15560ULL: goto x86_l_3cc8;
	case 15570ULL: goto x86_l_3cd2;
	case 15578ULL: goto x86_l_3cda;
	case 15585ULL: goto x86_l_3ce1;
	case 15593ULL: goto x86_l_3ce9;
	case 15598ULL: goto x86_l_3cee;
	case 15600ULL: goto x86_l_3cf0;
	case 15603ULL: goto x86_l_3cf3;
	case 15605ULL: goto x86_l_3cf5;
	case 15608ULL: goto x86_l_3cf8;
	case 15612ULL: goto x86_l_3cfc;
	case 15614ULL: goto x86_l_3cfe;
	case 15620ULL: goto x86_l_3d04;
	case 15626ULL: goto x86_l_3d0a;
	case 15628ULL: goto x86_l_3d0c;
	case 15633ULL: goto x86_l_3d11;
	case 15635ULL: goto x86_l_3d13;
	case 15641ULL: goto x86_l_3d19;
	case 15646ULL: goto x86_l_3d1e;
	case 15651ULL: goto x86_l_3d23;
	case 15655ULL: goto x86_l_3d27;
	case 15660ULL: goto x86_l_3d2c;
	case 15665ULL: goto x86_l_3d31;
	case 15670ULL: goto x86_l_3d36;
	case 15675ULL: goto x86_l_3d3b;
	case 15678ULL: goto x86_l_3d3e;
	case 15684ULL: goto x86_l_3d44;
	case 15690ULL: goto x86_l_3d4a;
	case 15695ULL: goto x86_l_3d4f;
	case 15704ULL: goto x86_l_3d58;
	case 15709ULL: goto x86_l_3d5d;
	case 15716ULL: goto x86_l_3d64;
	case 15724ULL: goto x86_l_3d6c;
	case 15729ULL: goto x86_l_3d71;
	case 15734ULL: goto x86_l_3d76;
	case 15736ULL: goto x86_l_3d78;
	case 15738ULL: goto x86_l_3d7a;
	case 15748ULL: goto x86_l_3d84;
	case 15756ULL: goto x86_l_3d8c;
	case 15758ULL: goto x86_l_3d8e;
	case 15762ULL: goto x86_l_3d92;
	case 15764ULL: goto x86_l_3d94;
	case 15772ULL: goto x86_l_3d9c;
	case 15775ULL: goto x86_l_3d9f;
	case 15780ULL: goto x86_l_3da4;
	case 15785ULL: goto x86_l_3da9;
	case 15788ULL: goto x86_l_3dac;
	case 15793ULL: goto x86_l_3db1;
	case 15795ULL: goto x86_l_3db3;
	case 15797ULL: goto x86_l_3db5;
	case 15803ULL: goto x86_l_3dbb;
	case 15807ULL: goto x86_l_3dbf;
	case 15809ULL: goto x86_l_3dc1;
	case 15814ULL: goto x86_l_3dc6;
	case 15817ULL: goto x86_l_3dc9;
	case 15822ULL: goto x86_l_3dce;
	case 15825ULL: goto x86_l_3dd1;
	case 15829ULL: goto x86_l_3dd5;
	case 15835ULL: goto x86_l_3ddb;
	case 15841ULL: goto x86_l_3de1;
	case 15844ULL: goto x86_l_3de4;
	case 15846ULL: goto x86_l_3de6;
	case 15849ULL: goto x86_l_3de9;
	case 15853ULL: goto x86_l_3ded;
	case 15857ULL: goto x86_l_3df1;
	case 15865ULL: goto x86_l_3df9;
	case 15870ULL: goto x86_l_3dfe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3715:
	/* 0x3715: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_371e:
	/* 0x371e: movzx  r15d,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_3727:
	/* 0x3727: movzx  eax,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_372c:
	/* 0x372c: mov    WORD PTR [rsp+0x4e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_3731:
	/* 0x3731: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_3734:
	/* 0x3734: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3739:
	/* 0x3739: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3740:
	/* 0x3740: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3743:
	/* 0x3743: je     3782 <tail_handle_ipv6_from_netdev+0x3782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3782;
	}
x86_l_3745:
	/* 0x3745: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_374c:
	/* 0x374c: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_374f:
	/* 0x374f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3752:
	/* 0x3752: jmp    3787 <tail_handle_ipv6_from_netdev+0x3787> */
	goto x86_l_3787;
x86_l_3754:
	/* 0x3754: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_375b:
	/* 0x375b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_375e:
	/* 0x375e: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_3765:
	/* 0x3765: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3768:
	/* 0x3768: je     37a1 <tail_handle_ipv6_from_netdev+0x37a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37a1;
	}
x86_l_376a:
	/* 0x376a: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_376f:
	/* 0x376f: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3774:
	/* 0x3774: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3777:
	/* 0x3777: mov    r15d,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967138ULL);
x86_l_377d:
	/* 0x377d: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	goto x86_l_3c61;
x86_l_3782:
	/* 0x3782: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_3787:
	/* 0x3787: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_378b:
	/* 0x378b: jne    37cd <tail_handle_ipv6_from_netdev+0x37cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37cd;
	}
x86_l_378d:
	/* 0x378d: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3790:
	/* 0x3790: je     37c8 <tail_handle_ipv6_from_netdev+0x37c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37c8;
	}
x86_l_3792:
	/* 0x3792: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3799:
	/* 0x3799: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_379c:
	/* 0x379c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_379f:
	/* 0x379f: jmp    37cd <tail_handle_ipv6_from_netdev+0x37cd> */
	goto x86_l_37cd;
x86_l_37a1:
	/* 0x37a1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37a6:
	/* 0x37a6: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_37aa:
	/* 0x37aa: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37ad:
	/* 0x37ad: test   cl,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_37b0:
	/* 0x37b0: je     3d1e <tail_handle_ipv6_from_netdev+0x3d1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d1e;
	}
x86_l_37b6:
	/* 0x37b6: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_37bb:
	/* 0x37bb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_37c0:
	/* 0x37c0: test   cl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_37c3:
	/* 0x37c3: jmp    3d31 <tail_handle_ipv6_from_netdev+0x3d31> */
	goto x86_l_3d31;
x86_l_37c8:
	/* 0x37c8: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_37cd:
	/* 0x37cd: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d0:
	/* 0x37d0: je     37e1 <tail_handle_ipv6_from_netdev+0x37e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_37e1;
	}
x86_l_37d2:
	/* 0x37d2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_37d7:
	/* 0x37d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37d9:
	/* 0x37d9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_37db:
	/* 0x37db: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_37df:
	/* 0x37df: jmp    3804 <tail_handle_ipv6_from_netdev+0x3804> */
	goto x86_l_3804;
x86_l_37e1:
	/* 0x37e1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_37e6:
	/* 0x37e6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37e8:
	/* 0x37e8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_37ea:
	/* 0x37ea: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_37ee:
	/* 0x37ee: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_37f8:
	/* 0x37f8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_37fb:
	/* 0x37fb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3800:
	/* 0x3800: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_3804:
	/* 0x3804: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_3808:
	/* 0x3808: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_380b:
	/* 0x380b: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_380d:
	/* 0x380d: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3811:
	/* 0x3811: movzx  edx,BYTE PTR [rsp+0x52] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 82ULL);
x86_l_3816:
	/* 0x3816: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_381a:
	/* 0x381a: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_381c:
	/* 0x381c: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_381f:
	/* 0x381f: je     3832 <tail_handle_ipv6_from_netdev+0x3832> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3832;
	}
x86_l_3821:
	/* 0x3821: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3828:
	/* 0x3828: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_382a:
	/* 0x382a: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_382d:
	/* 0x382d: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3830:
	/* 0x3830: jmp    3837 <tail_handle_ipv6_from_netdev+0x3837> */
	goto x86_l_3837;
x86_l_3832:
	/* 0x3832: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_3837:
	/* 0x3837: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3839:
	/* 0x3839: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_383b:
	/* 0x383b: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_383d:
	/* 0x383d: jb     3843 <tail_handle_ipv6_from_netdev+0x3843> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3843;
	}
x86_l_383f:
	/* 0x383f: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_3841:
	/* 0x3841: je     3854 <tail_handle_ipv6_from_netdev+0x3854> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3854;
	}
x86_l_3843:
	/* 0x3843: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_3847:
	/* 0x3847: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_384b:
	/* 0x384b: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_3852:
	/* 0x3852: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3854:
	/* 0x3854: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_385b:
	/* 0x385b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_385e:
	/* 0x385e: je     3875 <tail_handle_ipv6_from_netdev+0x3875> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3875;
	}
x86_l_3860:
	/* 0x3860: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_3869:
	/* 0x3869: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_386e:
	/* 0x386e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3870:
	/* 0x3870: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3875:
	/* 0x3875: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_387d:
	/* 0x387d: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3882:
	/* 0x3882: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3887:
	/* 0x3887: mov    rdi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_388c:
	/* 0x388c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_388e:
	/* 0x388e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3890:
	/* 0x3890: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3892:
	/* 0x3892: js     43c7 <tail_handle_ipv6_from_netdev+0x43c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 17351ULL;
	}
x86_l_3898:
	/* 0x3898: movzx  eax,BYTE PTR [rsp+0xc7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 199ULL);
x86_l_38a0:
	/* 0x38a0: mov    BYTE PTR [rsp+0xc5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 197ULL);
x86_l_38a7:
	/* 0x38a7: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_38ac:
	/* 0x38ac: test   BYTE PTR [rbx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_38b0:
	/* 0x38b0: je     3976 <tail_handle_ipv6_from_netdev+0x3976> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3976;
	}
x86_l_38b6:
	/* 0x38b6: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_38bd:
	/* 0x38bd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38c0:
	/* 0x38c0: je     38d1 <tail_handle_ipv6_from_netdev+0x38d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38d1;
	}
x86_l_38c2:
	/* 0x38c2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_38c7:
	/* 0x38c7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38c9:
	/* 0x38c9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_38cb:
	/* 0x38cb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_38cf:
	/* 0x38cf: jmp    38f4 <tail_handle_ipv6_from_netdev+0x38f4> */
	goto x86_l_38f4;
x86_l_38d1:
	/* 0x38d1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_38d6:
	/* 0x38d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38d8:
	/* 0x38d8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_38da:
	/* 0x38da: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_38de:
	/* 0x38de: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_38e8:
	/* 0x38e8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_38eb:
	/* 0x38eb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_38f0:
	/* 0x38f0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_38f4:
	/* 0x38f4: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_38fd:
	/* 0x38fd: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3906:
	/* 0x3906: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_390f:
	/* 0x390f: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3914:
	/* 0x3914: movzx  ecx,WORD PTR [rbx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_3918:
	/* 0x3918: mov    WORD PTR [rsp+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_391d:
	/* 0x391d: mov    BYTE PTR [rsp+0x3a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 249108103168ULL);
x86_l_3922:
	/* 0x3922: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3924:
	/* 0x3924: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_392c:
	/* 0x392c: mov    DWORD PTR [rsp+0x90],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3934:
	/* 0x3934: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_393f:
	/* 0x393f: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_3947:
	/* 0x3947: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_394c:
	/* 0x394c: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_3954:
	/* 0x3954: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3959:
	/* 0x3959: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_3960:
	/* 0x3960: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3965:
	/* 0x3965: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_396d:
	/* 0x396d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3972:
	/* 0x3972: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3974:
	/* 0x3974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3976:
	/* 0x3976: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_397e:
	/* 0x397e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3987:
	/* 0x3987: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3990:
	/* 0x3990: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3994:
	/* 0x3994: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3998:
	/* 0x3998: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_399d:
	/* 0x399d: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_39a2:
	/* 0x39a2: mov    BYTE PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_39a7:
	/* 0x39a7: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_39ae:
	/* 0x39ae: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39b3:
	/* 0x39b3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_39b8:
	/* 0x39b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39ba:
	/* 0x39ba: movzx  ecx,BYTE PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_39be:
	/* 0x39be: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_39c3:
	/* 0x39c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39c6:
	/* 0x39c6: je     39f6 <tail_handle_ipv6_from_netdev+0x39f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_39f6;
	}
x86_l_39c8:
	/* 0x39c8: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_39cb:
	/* 0x39cb: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39d0:
	/* 0x39d0: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39d5:
	/* 0x39d5: jne    3a15 <tail_handle_ipv6_from_netdev+0x3a15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a15;
	}
x86_l_39d7:
	/* 0x39d7: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_39dd:
	/* 0x39dd: je     3a15 <tail_handle_ipv6_from_netdev+0x3a15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a15;
	}
x86_l_39df:
	/* 0x39df: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39e4:
	/* 0x39e4: movzx  eax,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_39e8:
	/* 0x39e8: and    al,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_39ea:
	/* 0x39ea: je     3a15 <tail_handle_ipv6_from_netdev+0x3a15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a15;
	}
x86_l_39ec:
	/* 0x39ec: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39ef:
	/* 0x39ef: mov    bl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_39f1:
	/* 0x39f1: jmp    ca5 <tail_handle_ipv6_from_netdev+0xca5> */
	return 3237ULL;
x86_l_39f6:
	/* 0x39f6: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_39fc:
	/* 0x39fc: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_39ff:
	/* 0x39ff: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3a04:
	/* 0x3a04: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a09:
	/* 0x3a09: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_3a0f:
	/* 0x3a0f: jne    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c61;
	}
x86_l_3a15:
	/* 0x3a15: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_3a18:
	/* 0x3a18: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a20:
	/* 0x3a20: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3a28:
	/* 0x3a28: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3a2d:
	/* 0x3a2d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3a32:
	/* 0x3a32: movzx  ebp,WORD PTR [rsp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_3a3a:
	/* 0x3a3a: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a3e:
	/* 0x3a3e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3a46:
	/* 0x3a46: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a4a:
	/* 0x3a4a: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3a52:
	/* 0x3a52: movzx  eax,WORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_3a57:
	/* 0x3a57: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3a5a:
	/* 0x3a5a: je     3a64 <tail_handle_ipv6_from_netdev+0x3a64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a64;
	}
x86_l_3a5c:
	/* 0x3a5c: mov    WORD PTR [rsp+0xc2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_3a64:
	/* 0x3a64: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a67:
	/* 0x3a67: mov    bl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_3a69:
	/* 0x3a69: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_3a73:
	/* 0x3a73: test   QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3a7b:
	/* 0x3a7b: je     3ae1 <tail_handle_ipv6_from_netdev+0x3ae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ae1;
	}
x86_l_3a7d:
	/* 0x3a7d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a80:
	/* 0x3a80: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3a84:
	/* 0x3a84: add    esi,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_3a87:
	/* 0x3a87: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3a8c:
	/* 0x3a8c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3a8f:
	/* 0x3a8f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3a92:
	/* 0x3a92: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3a97:
	/* 0x3a97: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a9a:
	/* 0x3a9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a9c:
	/* 0x3a9c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a9e:
	/* 0x3a9e: js     3c50 <tail_handle_ipv6_from_netdev+0x3c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c50;
	}
x86_l_3aa4:
	/* 0x3aa4: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3aa9:
	/* 0x3aa9: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_3aae:
	/* 0x3aae: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3ab3:
	/* 0x3ab3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_3ab6:
	/* 0x3ab6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3abb:
	/* 0x3abb: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3abe:
	/* 0x3abe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ac0:
	/* 0x3ac0: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_3ac2:
	/* 0x3ac2: je     3b17 <tail_handle_ipv6_from_netdev+0x3b17> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b17;
	}
x86_l_3ac4:
	/* 0x3ac4: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_3ace:
	/* 0x3ace: test   QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3ad6:
	/* 0x3ad6: je     3b5f <tail_handle_ipv6_from_netdev+0x3b5f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b5f;
	}
x86_l_3adc:
	/* 0x3adc: jmp    3bda <tail_handle_ipv6_from_netdev+0x3bda> */
	goto x86_l_3bda;
x86_l_3ae1:
	/* 0x3ae1: movzx  eax,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_3ae9:
	/* 0x3ae9: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_3aec:
	/* 0x3aec: je     3d11 <tail_handle_ipv6_from_netdev+0x3d11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d11;
	}
x86_l_3af2:
	/* 0x3af2: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3af5:
	/* 0x3af5: je     3cfe <tail_handle_ipv6_from_netdev+0x3cfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3cfe;
	}
x86_l_3afb:
	/* 0x3afb: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_3b01:
	/* 0x3b01: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3b04:
	/* 0x3b04: jne    3a80 <tail_handle_ipv6_from_netdev+0x3a80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3a80;
	}
x86_l_3b0a:
	/* 0x3b0a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b0c:
	/* 0x3b0c: mov    r14d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16ULL);
x86_l_3b12:
	/* 0x3b12: jmp    3a7d <tail_handle_ipv6_from_netdev+0x3a7d> */
	goto x86_l_3a7d;
x86_l_3b17:
	/* 0x3b17: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b1f:
	/* 0x3b1f: lea    esi,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b23:
	/* 0x3b23: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_3b26:
	/* 0x3b26: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_3b2a:
	/* 0x3b2a: mov    r9d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 11ULL);
x86_l_3b30:
	/* 0x3b30: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3b33:
	/* 0x3b33: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b35:
	/* 0x3b35: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3b37:
	/* 0x3b37: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_3b3a:
	/* 0x3b3a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_3b3c:
	/* 0x3b3c: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_3b3f:
	/* 0x3b3f: and    ecx,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_3b45:
	/* 0x3b45: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3b47:
	/* 0x3b47: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_3b51:
	/* 0x3b51: test   QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3b59:
	/* 0x3b59: jne    3bd2 <tail_handle_ipv6_from_netdev+0x3bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bd2;
	}
x86_l_3b5b:
	/* 0x3b5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b5d:
	/* 0x3b5d: js     3bd2 <tail_handle_ipv6_from_netdev+0x3bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3bd2;
	}
x86_l_3b5f:
	/* 0x3b5f: movzx  eax,WORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_3b64:
	/* 0x3b64: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_3b67:
	/* 0x3b67: je     3bda <tail_handle_ipv6_from_netdev+0x3bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bda;
	}
x86_l_3b69:
	/* 0x3b69: cmp    bp,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_16);
x86_l_3b6c:
	/* 0x3b6c: je     3bda <tail_handle_ipv6_from_netdev+0x3bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bda;
	}
x86_l_3b6e:
	/* 0x3b6e: mov    WORD PTR [rsp+0x88],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3b76:
	/* 0x3b76: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3b7e:
	/* 0x3b7e: lea    esi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3b81:
	/* 0x3b81: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3b89:
	/* 0x3b89: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3b8e:
	/* 0x3b8e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3b91:
	/* 0x3b91: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3b96:
	/* 0x3b96: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b99:
	/* 0x3b99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b9b:
	/* 0x3b9b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3b9d:
	/* 0x3b9d: js     3c50 <tail_handle_ipv6_from_netdev+0x3c50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3c50;
	}
x86_l_3ba3:
	/* 0x3ba3: movzx  ecx,WORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 136ULL);
x86_l_3bab:
	/* 0x3bab: add    r14d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_3bb3:
	/* 0x3bb3: or     r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_3bb7:
	/* 0x3bb7: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_3bbc:
	/* 0x3bbc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3bbf:
	/* 0x3bbf: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_3bc2:
	/* 0x3bc2: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3bc4:
	/* 0x3bc4: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_3bc7:
	/* 0x3bc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc9:
	/* 0x3bc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3bcb:
	/* 0x3bcb: jns    3bda <tail_handle_ipv6_from_netdev+0x3bda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3bda;
	}
x86_l_3bcd:
	/* 0x3bcd: mov    edx,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967142ULL);
x86_l_3bd2:
	/* 0x3bd2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_3bd4:
	/* 0x3bd4: js     4a10 <tail_handle_ipv6_from_netdev+0x4a10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 18960ULL;
	}
x86_l_3bda:
	/* 0x3bda: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3be0:
	/* 0x3be0: jne    3bf1 <tail_handle_ipv6_from_netdev+0x3bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3bf1;
	}
x86_l_3be2:
	/* 0x3be2: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3be7:
	/* 0x3be7: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_3beb:
	/* 0x3beb: js     3f0d <tail_handle_ipv6_from_netdev+0x3f0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16141ULL;
	}
x86_l_3bf1:
	/* 0x3bf1: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3bf9:
	/* 0x3bf9: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3c01:
	/* 0x3c01: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3c09:
	/* 0x3c09: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3c11:
	/* 0x3c11: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_3c19:
	/* 0x3c19: mov    QWORD PTR [rsp+0xb0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_3c21:
	/* 0x3c21: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3c29:
	/* 0x3c29: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3c31:
	/* 0x3c31: rol    DWORD PTR [rsp+0xc0],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 824633720848ULL);
x86_l_3c39:
	/* 0x3c39: movzx  ebp,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_3c41:
	/* 0x3c41: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_3c45:
	/* 0x3c45: je     3c7c <tail_handle_ipv6_from_netdev+0x3c7c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c7c;
	}
x86_l_3c47:
	/* 0x3c47: mov    r13,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_3c4e:
	/* 0x3c4e: jmp    3c83 <tail_handle_ipv6_from_netdev+0x3c83> */
	goto x86_l_3c83;
x86_l_3c50:
	/* 0x3c50: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_3c56:
	/* 0x3c56: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_3c59:
	/* 0x3c59: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c5e:
	/* 0x3c5e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c61:
	/* 0x3c61: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3c63:
	/* 0x3c63: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_3c66:
	/* 0x3c66: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_3c68:
	/* 0x3c68: jne    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1450ULL;
	}
x86_l_3c6e:
	/* 0x3c6e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3c71:
	/* 0x3c71: jne    660 <tail_handle_ipv6_from_netdev+0x660> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1632ULL;
	}
x86_l_3c77:
	/* 0x3c77: jmp    5aa <tail_handle_ipv6_from_netdev+0x5aa> */
	return 1450ULL;
x86_l_3c7c:
	/* 0x3c7c: mov    r13,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_3c83:
	/* 0x3c83: mov    BYTE PTR [rsp+0xc5],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 846108557312ULL);
x86_l_3c8b:
	/* 0x3c8b: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_3c93:
	/* 0x3c93: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_3c9a:
	/* 0x3c9a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c9d:
	/* 0x3c9d: je     3d7a <tail_handle_ipv6_from_netdev+0x3d7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7a;
	}
x86_l_3ca3:
	/* 0x3ca3: cmp    QWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_3cac:
	/* 0x3cac: je     3d7a <tail_handle_ipv6_from_netdev+0x3d7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d7a;
	}
x86_l_3cb2:
	/* 0x3cb2: mov    ebx,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3cb6:
	/* 0x3cb6: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3cbf:
	/* 0x3cbf: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3cc8:
	/* 0x3cc8: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_3cd2:
	/* 0x3cd2: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3cda:
	/* 0x3cda: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3ce1:
	/* 0x3ce1: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3ce9:
	/* 0x3ce9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cee:
	/* 0x3cee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cf0:
	/* 0x3cf0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cf3:
	/* 0x3cf3: je     3d4f <tail_handle_ipv6_from_netdev+0x3d4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3d4f;
	}
x86_l_3cf5:
	/* 0x3cf5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3cf8:
	/* 0x3cf8: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3cfc:
	/* 0x3cfc: jmp    3d7a <tail_handle_ipv6_from_netdev+0x3d7a> */
	goto x86_l_3d7a;
x86_l_3cfe:
	/* 0x3cfe: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_3d04:
	/* 0x3d04: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_3d0a:
	/* 0x3d0a: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d0c:
	/* 0x3d0c: jmp    3a80 <tail_handle_ipv6_from_netdev+0x3a80> */
	goto x86_l_3a80;
x86_l_3d11:
	/* 0x3d11: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d13:
	/* 0x3d13: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_3d19:
	/* 0x3d19: jmp    3a7d <tail_handle_ipv6_from_netdev+0x3a7d> */
	goto x86_l_3a7d;
x86_l_3d1e:
	/* 0x3d1e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d23:
	/* 0x3d23: test   BYTE PTR [rax+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_3d27:
	/* 0x3d27: mov    ebx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 0ULL);
x86_l_3d2c:
	/* 0x3d2c: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3d31:
	/* 0x3d31: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d36:
	/* 0x3d36: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d3b:
	/* 0x3d3b: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_3d3e:
	/* 0x3d3e: mov    r15d,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967138ULL);
x86_l_3d44:
	/* 0x3d44: je     ca7 <tail_handle_ipv6_from_netdev+0xca7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3239ULL;
	}
x86_l_3d4a:
	/* 0x3d4a: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	goto x86_l_3c61;
x86_l_3d4f:
	/* 0x3d4f: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_3d58:
	/* 0x3d58: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d5d:
	/* 0x3d5d: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3d64:
	/* 0x3d64: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3d6c:
	/* 0x3d6c: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d71:
	/* 0x3d71: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3d76:
	/* 0x3d76: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d78:
	/* 0x3d78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d7a:
	/* 0x3d7a: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_3d84:
	/* 0x3d84: test   QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_3d8c:
	/* 0x3d8c: jne    3de6 <tail_handle_ipv6_from_netdev+0x3de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3de6;
	}
x86_l_3d8e:
	/* 0x3d8e: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_3d92:
	/* 0x3d92: jne    3de6 <tail_handle_ipv6_from_netdev+0x3de6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3de6;
	}
x86_l_3d94:
	/* 0x3d94: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3d9c:
	/* 0x3d9c: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_3d9f:
	/* 0x3d9f: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3da4:
	/* 0x3da4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3da9:
	/* 0x3da9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3dac:
	/* 0x3dac: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3db1:
	/* 0x3db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db3:
	/* 0x3db3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3db5:
	/* 0x3db5: js     3eff <tail_handle_ipv6_from_netdev+0x3eff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 16127ULL;
	}
x86_l_3dbb:
	/* 0x3dbb: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3dbf:
	/* 0x3dbf: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3dc1:
	/* 0x3dc1: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_3dc6:
	/* 0x3dc6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dc9:
	/* 0x3dc9: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_3dce:
	/* 0x3dce: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3dd1:
	/* 0x3dd1: mov    DWORD PTR [rsp+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3dd5:
	/* 0x3dd5: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_3ddb:
	/* 0x3ddb: jne    43ed <tail_handle_ipv6_from_netdev+0x43ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 17389ULL;
	}
x86_l_3de1:
	/* 0x3de1: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_3de4:
	/* 0x3de4: jmp    3df1 <tail_handle_ipv6_from_netdev+0x3df1> */
	goto x86_l_3df1;
x86_l_3de6:
	/* 0x3de6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3de9:
	/* 0x3de9: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ded:
	/* 0x3ded: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3df1:
	/* 0x3df1: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3df9:
	/* 0x3df9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3dfe:
	/* 0x3dfe: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
	return 15873ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_9(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 15873ULL: goto x86_l_3e01;
	case 15875ULL: goto x86_l_3e03;
	case 15878ULL: goto x86_l_3e06;
	case 15880ULL: goto x86_l_3e08;
	case 15883ULL: goto x86_l_3e0b;
	case 15887ULL: goto x86_l_3e0f;
	case 15889ULL: goto x86_l_3e11;
	case 15891ULL: goto x86_l_3e13;
	case 15896ULL: goto x86_l_3e18;
	case 15899ULL: goto x86_l_3e1b;
	case 15901ULL: goto x86_l_3e1d;
	case 15907ULL: goto x86_l_3e23;
	case 15913ULL: goto x86_l_3e29;
	case 15918ULL: goto x86_l_3e2e;
	case 15924ULL: goto x86_l_3e34;
	case 15931ULL: goto x86_l_3e3b;
	case 15933ULL: goto x86_l_3e3d;
	case 15941ULL: goto x86_l_3e45;
	case 15944ULL: goto x86_l_3e48;
	case 15946ULL: goto x86_l_3e4a;
	case 15953ULL: goto x86_l_3e51;
	case 15955ULL: goto x86_l_3e53;
	case 15962ULL: goto x86_l_3e5a;
	case 15971ULL: goto x86_l_3e63;
	case 15980ULL: goto x86_l_3e6c;
	case 15989ULL: goto x86_l_3e75;
	case 15998ULL: goto x86_l_3e7e;
	case 16007ULL: goto x86_l_3e87;
	case 16012ULL: goto x86_l_3e8c;
	case 16017ULL: goto x86_l_3e91;
	case 16025ULL: goto x86_l_3e99;
	case 16034ULL: goto x86_l_3ea2;
	case 16043ULL: goto x86_l_3eab;
	case 16050ULL: goto x86_l_3eb2;
	case 16057ULL: goto x86_l_3eb9;
	case 16061ULL: goto x86_l_3ebd;
	case 16063ULL: goto x86_l_3ebf;
	case 16070ULL: goto x86_l_3ec6;
	case 16073ULL: goto x86_l_3ec9;
	case 16076ULL: goto x86_l_3ecc;
	case 16078ULL: goto x86_l_3ece;
	case 16083ULL: goto x86_l_3ed3;
	case 16086ULL: goto x86_l_3ed6;
	case 16092ULL: goto x86_l_3edc;
	case 16099ULL: goto x86_l_3ee3;
	case 16103ULL: goto x86_l_3ee7;
	case 16109ULL: goto x86_l_3eed;
	case 16116ULL: goto x86_l_3ef4;
	case 16119ULL: goto x86_l_3ef7;
	case 16122ULL: goto x86_l_3efa;
	case 16127ULL: goto x86_l_3eff;
	case 16133ULL: goto x86_l_3f05;
	case 16136ULL: goto x86_l_3f08;
	case 16141ULL: goto x86_l_3f0d;
	case 16150ULL: goto x86_l_3f16;
	case 16158ULL: goto x86_l_3f1e;
	case 16161ULL: goto x86_l_3f21;
	case 16166ULL: goto x86_l_3f26;
	case 16173ULL: goto x86_l_3f2d;
	case 16178ULL: goto x86_l_3f32;
	case 16185ULL: goto x86_l_3f39;
	case 16190ULL: goto x86_l_3f3e;
	case 16197ULL: goto x86_l_3f45;
	case 16202ULL: goto x86_l_3f4a;
	case 16209ULL: goto x86_l_3f51;
	case 16214ULL: goto x86_l_3f56;
	case 16221ULL: goto x86_l_3f5d;
	case 16227ULL: goto x86_l_3f63;
	case 16232ULL: goto x86_l_3f68;
	case 16235ULL: goto x86_l_3f6b;
	case 16240ULL: goto x86_l_3f70;
	case 16242ULL: goto x86_l_3f72;
	case 16248ULL: goto x86_l_3f78;
	case 16253ULL: goto x86_l_3f7d;
	case 16258ULL: goto x86_l_3f82;
	case 16263ULL: goto x86_l_3f87;
	case 16267ULL: goto x86_l_3f8b;
	case 16269ULL: goto x86_l_3f8d;
	case 16274ULL: goto x86_l_3f92;
	case 16276ULL: goto x86_l_3f94;
	case 16278ULL: goto x86_l_3f96;
	case 16282ULL: goto x86_l_3f9a;
	case 16284ULL: goto x86_l_3f9c;
	case 16289ULL: goto x86_l_3fa1;
	case 16291ULL: goto x86_l_3fa3;
	case 16293ULL: goto x86_l_3fa5;
	case 16297ULL: goto x86_l_3fa9;
	case 16307ULL: goto x86_l_3fb3;
	case 16310ULL: goto x86_l_3fb6;
	case 16315ULL: goto x86_l_3fbb;
	case 16319ULL: goto x86_l_3fbf;
	case 16322ULL: goto x86_l_3fc2;
	case 16325ULL: goto x86_l_3fc5;
	case 16327ULL: goto x86_l_3fc7;
	case 16331ULL: goto x86_l_3fcb;
	case 16336ULL: goto x86_l_3fd0;
	case 16340ULL: goto x86_l_3fd4;
	case 16342ULL: goto x86_l_3fd6;
	case 16346ULL: goto x86_l_3fda;
	case 16348ULL: goto x86_l_3fdc;
	case 16355ULL: goto x86_l_3fe3;
	case 16357ULL: goto x86_l_3fe5;
	case 16360ULL: goto x86_l_3fe8;
	case 16363ULL: goto x86_l_3feb;
	case 16365ULL: goto x86_l_3fed;
	case 16370ULL: goto x86_l_3ff2;
	case 16372ULL: goto x86_l_3ff4;
	case 16374ULL: goto x86_l_3ff6;
	case 16376ULL: goto x86_l_3ff8;
	case 16378ULL: goto x86_l_3ffa;
	case 16380ULL: goto x86_l_3ffc;
	case 16382ULL: goto x86_l_3ffe;
	case 16386ULL: goto x86_l_4002;
	case 16390ULL: goto x86_l_4006;
	case 16397ULL: goto x86_l_400d;
	case 16399ULL: goto x86_l_400f;
	case 16406ULL: goto x86_l_4016;
	case 16409ULL: goto x86_l_4019;
	case 16411ULL: goto x86_l_401b;
	case 16420ULL: goto x86_l_4024;
	case 16424ULL: goto x86_l_4028;
	case 16429ULL: goto x86_l_402d;
	case 16437ULL: goto x86_l_4035;
	case 16442ULL: goto x86_l_403a;
	case 16447ULL: goto x86_l_403f;
	case 16450ULL: goto x86_l_4042;
	case 16452ULL: goto x86_l_4044;
	case 16454ULL: goto x86_l_4046;
	case 16456ULL: goto x86_l_4048;
	case 16462ULL: goto x86_l_404e;
	case 16468ULL: goto x86_l_4054;
	case 16470ULL: goto x86_l_4056;
	case 16472ULL: goto x86_l_4058;
	case 16475ULL: goto x86_l_405b;
	case 16477ULL: goto x86_l_405d;
	case 16480ULL: goto x86_l_4060;
	case 16485ULL: goto x86_l_4065;
	case 16494ULL: goto x86_l_406e;
	case 16501ULL: goto x86_l_4075;
	case 16504ULL: goto x86_l_4078;
	case 16507ULL: goto x86_l_407b;
	case 16512ULL: goto x86_l_4080;
	case 16517ULL: goto x86_l_4085;
	case 16521ULL: goto x86_l_4089;
	case 16525ULL: goto x86_l_408d;
	case 16531ULL: goto x86_l_4093;
	case 16534ULL: goto x86_l_4096;
	case 16540ULL: goto x86_l_409c;
	case 16545ULL: goto x86_l_40a1;
	case 16550ULL: goto x86_l_40a6;
	case 16553ULL: goto x86_l_40a9;
	case 16558ULL: goto x86_l_40ae;
	case 16563ULL: goto x86_l_40b3;
	case 16565ULL: goto x86_l_40b5;
	case 16567ULL: goto x86_l_40b7;
	case 16573ULL: goto x86_l_40bd;
	case 16576ULL: goto x86_l_40c0;
	case 16580ULL: goto x86_l_40c4;
	case 16587ULL: goto x86_l_40cb;
	case 16592ULL: goto x86_l_40d0;
	case 16595ULL: goto x86_l_40d3;
	case 16597ULL: goto x86_l_40d5;
	case 16600ULL: goto x86_l_40d8;
	case 16602ULL: goto x86_l_40da;
	case 16606ULL: goto x86_l_40de;
	case 16608ULL: goto x86_l_40e0;
	case 16613ULL: goto x86_l_40e5;
	case 16617ULL: goto x86_l_40e9;
	case 16620ULL: goto x86_l_40ec;
	case 16622ULL: goto x86_l_40ee;
	case 16624ULL: goto x86_l_40f0;
	case 16631ULL: goto x86_l_40f7;
	case 16636ULL: goto x86_l_40fc;
	case 16641ULL: goto x86_l_4101;
	case 16644ULL: goto x86_l_4104;
	case 16646ULL: goto x86_l_4106;
	case 16648ULL: goto x86_l_4108;
	case 16650ULL: goto x86_l_410a;
	case 16652ULL: goto x86_l_410c;
	case 16657ULL: goto x86_l_4111;
	case 16661ULL: goto x86_l_4115;
	case 16670ULL: goto x86_l_411e;
	case 16676ULL: goto x86_l_4124;
	case 16679ULL: goto x86_l_4127;
	case 16688ULL: goto x86_l_4130;
	case 16695ULL: goto x86_l_4137;
	case 16701ULL: goto x86_l_413d;
	case 16706ULL: goto x86_l_4142;
	case 16709ULL: goto x86_l_4145;
	case 16714ULL: goto x86_l_414a;
	case 16719ULL: goto x86_l_414f;
	case 16721ULL: goto x86_l_4151;
	case 16723ULL: goto x86_l_4153;
	case 16726ULL: goto x86_l_4156;
	case 16732ULL: goto x86_l_415c;
	case 16739ULL: goto x86_l_4163;
	case 16742ULL: goto x86_l_4166;
	case 16744ULL: goto x86_l_4168;
	case 16751ULL: goto x86_l_416f;
	case 16755ULL: goto x86_l_4173;
	case 16759ULL: goto x86_l_4177;
	case 16761ULL: goto x86_l_4179;
	case 16764ULL: goto x86_l_417c;
	case 16767ULL: goto x86_l_417f;
	case 16772ULL: goto x86_l_4184;
	case 16778ULL: goto x86_l_418a;
	case 16782ULL: goto x86_l_418e;
	case 16784ULL: goto x86_l_4190;
	case 16788ULL: goto x86_l_4194;
	case 16790ULL: goto x86_l_4196;
	case 16793ULL: goto x86_l_4199;
	case 16796ULL: goto x86_l_419c;
	case 16798ULL: goto x86_l_419e;
	case 16803ULL: goto x86_l_41a3;
	case 16805ULL: goto x86_l_41a5;
	case 16810ULL: goto x86_l_41aa;
	case 16816ULL: goto x86_l_41b0;
	case 16820ULL: goto x86_l_41b4;
	case 16827ULL: goto x86_l_41bb;
	case 16830ULL: goto x86_l_41be;
	case 16832ULL: goto x86_l_41c0;
	case 16839ULL: goto x86_l_41c7;
	case 16843ULL: goto x86_l_41cb;
	case 16847ULL: goto x86_l_41cf;
	case 16851ULL: goto x86_l_41d3;
	case 16854ULL: goto x86_l_41d6;
	case 16861ULL: goto x86_l_41dd;
	case 16864ULL: goto x86_l_41e0;
	case 16866ULL: goto x86_l_41e2;
	case 16871ULL: goto x86_l_41e7;
	case 16873ULL: goto x86_l_41e9;
	case 16875ULL: goto x86_l_41eb;
	case 16879ULL: goto x86_l_41ef;
	case 16881ULL: goto x86_l_41f1;
	case 16886ULL: goto x86_l_41f6;
	case 16888ULL: goto x86_l_41f8;
	case 16890ULL: goto x86_l_41fa;
	case 16894ULL: goto x86_l_41fe;
	case 16904ULL: goto x86_l_4208;
	case 16907ULL: goto x86_l_420b;
	case 16912ULL: goto x86_l_4210;
	case 16916ULL: goto x86_l_4214;
	case 16919ULL: goto x86_l_4217;
	case 16923ULL: goto x86_l_421b;
	case 16928ULL: goto x86_l_4220;
	case 16932ULL: goto x86_l_4224;
	case 16935ULL: goto x86_l_4227;
	case 16942ULL: goto x86_l_422e;
	case 16945ULL: goto x86_l_4231;
	case 16947ULL: goto x86_l_4233;
	case 16954ULL: goto x86_l_423a;
	case 16956ULL: goto x86_l_423c;
	case 16959ULL: goto x86_l_423f;
	case 16962ULL: goto x86_l_4242;
	case 16964ULL: goto x86_l_4244;
	case 16969ULL: goto x86_l_4249;
	case 16971ULL: goto x86_l_424b;
	case 16973ULL: goto x86_l_424d;
	case 16975ULL: goto x86_l_424f;
	case 16977ULL: goto x86_l_4251;
	case 16979ULL: goto x86_l_4253;
	case 16981ULL: goto x86_l_4255;
	case 16985ULL: goto x86_l_4259;
	case 16989ULL: goto x86_l_425d;
	case 16996ULL: goto x86_l_4264;
	case 16998ULL: goto x86_l_4266;
	case 17005ULL: goto x86_l_426d;
	case 17008ULL: goto x86_l_4270;
	case 17010ULL: goto x86_l_4272;
	case 17015ULL: goto x86_l_4277;
	case 17019ULL: goto x86_l_427b;
	case 17024ULL: goto x86_l_4280;
	case 17028ULL: goto x86_l_4284;
	case 17030ULL: goto x86_l_4286;
	case 17034ULL: goto x86_l_428a;
	case 17040ULL: goto x86_l_4290;
	case 17045ULL: goto x86_l_4295;
	case 17047ULL: goto x86_l_4297;
	case 17053ULL: goto x86_l_429d;
	case 17060ULL: goto x86_l_42a4;
	case 17065ULL: goto x86_l_42a9;
	case 17070ULL: goto x86_l_42ae;
	case 17077ULL: goto x86_l_42b5;
	case 17080ULL: goto x86_l_42b8;
	case 17086ULL: goto x86_l_42be;
	case 17093ULL: goto x86_l_42c5;
	case 17097ULL: goto x86_l_42c9;
	case 17101ULL: goto x86_l_42cd;
	case 17106ULL: goto x86_l_42d2;
	case 17110ULL: goto x86_l_42d6;
	case 17115ULL: goto x86_l_42db;
	case 17118ULL: goto x86_l_42de;
	case 17122ULL: goto x86_l_42e2;
	case 17126ULL: goto x86_l_42e6;
	case 17131ULL: goto x86_l_42eb;
	case 17136ULL: goto x86_l_42f0;
	case 17143ULL: goto x86_l_42f7;
	case 17145ULL: goto x86_l_42f9;
	case 17147ULL: goto x86_l_42fb;
	case 17153ULL: goto x86_l_4301;
	case 17160ULL: goto x86_l_4308;
	case 17164ULL: goto x86_l_430c;
	case 17166ULL: goto x86_l_430e;
	case 17173ULL: goto x86_l_4315;
	case 17175ULL: goto x86_l_4317;
	case 17177ULL: goto x86_l_4319;
	case 17180ULL: goto x86_l_431c;
	case 17183ULL: goto x86_l_431f;
	case 17185ULL: goto x86_l_4321;
	case 17190ULL: goto x86_l_4326;
	case 17195ULL: goto x86_l_432b;
	case 17199ULL: goto x86_l_432f;
	case 17201ULL: goto x86_l_4331;
	case 17206ULL: goto x86_l_4336;
	case 17208ULL: goto x86_l_4338;
	case 17210ULL: goto x86_l_433a;
	case 17214ULL: goto x86_l_433e;
	case 17216ULL: goto x86_l_4340;
	case 17221ULL: goto x86_l_4345;
	case 17223ULL: goto x86_l_4347;
	case 17225ULL: goto x86_l_4349;
	case 17229ULL: goto x86_l_434d;
	case 17239ULL: goto x86_l_4357;
	case 17242ULL: goto x86_l_435a;
	case 17247ULL: goto x86_l_435f;
	case 17251ULL: goto x86_l_4363;
	case 17253ULL: goto x86_l_4365;
	case 17257ULL: goto x86_l_4369;
	case 17262ULL: goto x86_l_436e;
	case 17266ULL: goto x86_l_4372;
	case 17270ULL: goto x86_l_4376;
	case 17274ULL: goto x86_l_437a;
	case 17278ULL: goto x86_l_437e;
	case 17282ULL: goto x86_l_4382;
	case 17284ULL: goto x86_l_4384;
	case 17291ULL: goto x86_l_438b;
	case 17293ULL: goto x86_l_438d;
	case 17296ULL: goto x86_l_4390;
	case 17299ULL: goto x86_l_4393;
	case 17301ULL: goto x86_l_4395;
	case 17306ULL: goto x86_l_439a;
	case 17308ULL: goto x86_l_439c;
	case 17312ULL: goto x86_l_43a0;
	case 17314ULL: goto x86_l_43a2;
	case 17318ULL: goto x86_l_43a6;
	case 17320ULL: goto x86_l_43a8;
	case 17322ULL: goto x86_l_43aa;
	case 17326ULL: goto x86_l_43ae;
	case 17332ULL: goto x86_l_43b4;
	case 17336ULL: goto x86_l_43b8;
	case 17340ULL: goto x86_l_43bc;
	case 17344ULL: goto x86_l_43c0;
	case 17346ULL: goto x86_l_43c2;
	case 17351ULL: goto x86_l_43c7;
	case 17357ULL: goto x86_l_43cd;
	case 17360ULL: goto x86_l_43d0;
	case 17365ULL: goto x86_l_43d5;
	case 17370ULL: goto x86_l_43da;
	case 17375ULL: goto x86_l_43df;
	case 17378ULL: goto x86_l_43e2;
	case 17384ULL: goto x86_l_43e8;
	case 17389ULL: goto x86_l_43ed;
	case 17395ULL: goto x86_l_43f3;
	case 17400ULL: goto x86_l_43f8;
	case 17406ULL: goto x86_l_43fe;
	case 17411ULL: goto x86_l_4403;
	case 17413ULL: goto x86_l_4405;
	case 17416ULL: goto x86_l_4408;
	case 17418ULL: goto x86_l_440a;
	case 17421ULL: goto x86_l_440d;
	case 17424ULL: goto x86_l_4410;
	case 17426ULL: goto x86_l_4412;
	case 17431ULL: goto x86_l_4417;
	case 17433ULL: goto x86_l_4419;
	case 17438ULL: goto x86_l_441e;
	case 17444ULL: goto x86_l_4424;
	case 17448ULL: goto x86_l_4428;
	case 17451ULL: goto x86_l_442b;
	case 17453ULL: goto x86_l_442d;
	case 17460ULL: goto x86_l_4434;
	case 17464ULL: goto x86_l_4438;
	case 17468ULL: goto x86_l_443c;
	case 17472ULL: goto x86_l_4440;
	case 17475ULL: goto x86_l_4443;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3e01:
	/* 0x3e01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e03:
	/* 0x3e03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3e06:
	/* 0x3e06: je     3e34 <tail_handle_ipv6_from_netdev+0x3e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e34;
	}
x86_l_3e08:
	/* 0x3e08: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3e0b:
	/* 0x3e0b: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_3e0f:
	/* 0x3e0f: test   al,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 32ULL);
x86_l_3e11:
	/* 0x3e11: je     3e34 <tail_handle_ipv6_from_netdev+0x3e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e34;
	}
x86_l_3e13:
	/* 0x3e13: movzx  ecx,WORD PTR [r14+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_3e18:
	/* 0x3e18: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_3e1b:
	/* 0x3e1b: je     3e34 <tail_handle_ipv6_from_netdev+0x3e34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3e34;
	}
x86_l_3e1d:
	/* 0x3e1d: cmp    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_3e23:
	/* 0x3e23: je     414f <tail_handle_ipv6_from_netdev+0x414f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_414f;
	}
x86_l_3e29:
	/* 0x3e29: cmp    cx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3e2e:
	/* 0x3e2e: je     414f <tail_handle_ipv6_from_netdev+0x414f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_414f;
	}
x86_l_3e34:
	/* 0x3e34: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_3e3b:
	/* 0x3e3b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e3d:
	/* 0x3e3d: movzx  ebx,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_3e45:
	/* 0x3e45: cmp    bl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_8, 6ULL);
x86_l_3e48:
	/* 0x3e48: jne    3e53 <tail_handle_ipv6_from_netdev+0x3e53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3e53;
	}
x86_l_3e4a:
	/* 0x3e4a: mov    r14,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_3e51:
	/* 0x3e51: jmp    3e5a <tail_handle_ipv6_from_netdev+0x3e5a> */
	goto x86_l_3e5a;
x86_l_3e53:
	/* 0x3e53: mov    r14,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_3e5a:
	/* 0x3e5a: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_3e63:
	/* 0x3e63: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_3e6c:
	/* 0x3e6c: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_3e75:
	/* 0x3e75: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_3e7e:
	/* 0x3e7e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3e87:
	/* 0x3e87: movzx  eax,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_3e8c:
	/* 0x3e8c: mov    WORD PTR [rsp+0x4e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_3e91:
	/* 0x3e91: mov    DWORD PTR [rsp+0x54],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252874ULL);
x86_l_3e99:
	/* 0x3e99: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3ea2:
	/* 0x3ea2: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3eab:
	/* 0x3eab: mov    WORD PTR [rsp+0x4c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514528ULL);
x86_l_3eb2:
	/* 0x3eb2: mov    r15,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3eb9:
	/* 0x3eb9: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ebd:
	/* 0x3ebd: je     3ece <tail_handle_ipv6_from_netdev+0x3ece> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ece;
	}
x86_l_3ebf:
	/* 0x3ebf: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3ec6:
	/* 0x3ec6: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_3ec9:
	/* 0x3ec9: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3ecc:
	/* 0x3ecc: jmp    3ed3 <tail_handle_ipv6_from_netdev+0x3ed3> */
	goto x86_l_3ed3;
x86_l_3ece:
	/* 0x3ece: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_3ed3:
	/* 0x3ed3: cmp    bl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_8, 6ULL);
x86_l_3ed6:
	/* 0x3ed6: jne    3f87 <tail_handle_ipv6_from_netdev+0x3f87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3f87;
	}
x86_l_3edc:
	/* 0x3edc: mov    WORD PTR [rsp+0x4c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514528ULL);
x86_l_3ee3:
	/* 0x3ee3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee7:
	/* 0x3ee7: je     3f82 <tail_handle_ipv6_from_netdev+0x3f82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f82;
	}
x86_l_3eed:
	/* 0x3eed: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3ef4:
	/* 0x3ef4: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_3ef7:
	/* 0x3ef7: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3efa:
	/* 0x3efa: jmp    3f87 <tail_handle_ipv6_from_netdev+0x3f87> */
	goto x86_l_3f87;
x86_l_3eff:
	/* 0x3eff: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_3f05:
	/* 0x3f05: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f08:
	/* 0x3f08: jmp    f7a <tail_handle_ipv6_from_netdev+0xf7a> */
	return 3962ULL;
x86_l_3f0d:
	/* 0x3f0d: mov    DWORD PTR [r12+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_3f16:
	/* 0x3f16: movzx  eax,WORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 216ULL);
x86_l_3f1e:
	/* 0x3f1e: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_3f21:
	/* 0x3f21: mov    DWORD PTR [r12+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f26:
	/* 0x3f26: mov    eax,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3f2d:
	/* 0x3f2d: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3f32:
	/* 0x3f32: mov    eax,DWORD PTR [rsp+0xcc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_3f39:
	/* 0x3f39: mov    DWORD PTR [r12+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3f3e:
	/* 0x3f3e: mov    eax,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3f45:
	/* 0x3f45: mov    DWORD PTR [r12+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3f4a:
	/* 0x3f4a: mov    eax,DWORD PTR [rsp+0xd4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_3f51:
	/* 0x3f51: mov    DWORD PTR [r12+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3f56:
	/* 0x3f56: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_3f5d:
	/* 0x3f5d: mov    r14d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 22ULL);
x86_l_3f63:
	/* 0x3f63: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3f68:
	/* 0x3f68: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3f6b:
	/* 0x3f6b: mov    edx,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 22ULL);
x86_l_3f70:
	/* 0x3f70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f72:
	/* 0x3f72: mov    r15d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967156ULL);
x86_l_3f78:
	/* 0x3f78: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3f7d:
	/* 0x3f7d: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
x86_l_3f82:
	/* 0x3f82: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_3f87:
	/* 0x3f87: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f8b:
	/* 0x3f8b: je     3f9c <tail_handle_ipv6_from_netdev+0x3f9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f9c;
	}
x86_l_3f8d:
	/* 0x3f8d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_3f92:
	/* 0x3f92: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3f94:
	/* 0x3f94: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3f96:
	/* 0x3f96: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_3f9a:
	/* 0x3f9a: jmp    3fbf <tail_handle_ipv6_from_netdev+0x3fbf> */
	goto x86_l_3fbf;
x86_l_3f9c:
	/* 0x3f9c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3fa1:
	/* 0x3fa1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fa3:
	/* 0x3fa3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3fa5:
	/* 0x3fa5: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_3fa9:
	/* 0x3fa9: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_3fb3:
	/* 0x3fb3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3fb6:
	/* 0x3fb6: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3fbb:
	/* 0x3fbb: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_3fbf:
	/* 0x3fbf: cmp    bl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_8, 6ULL);
x86_l_3fc2:
	/* 0x3fc2: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_3fc5:
	/* 0x3fc5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3fc7:
	/* 0x3fc7: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3fcb:
	/* 0x3fcb: movzx  edx,BYTE PTR [rsp+0x52] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 82ULL);
x86_l_3fd0:
	/* 0x3fd0: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3fd4:
	/* 0x3fd4: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_3fd6:
	/* 0x3fd6: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fda:
	/* 0x3fda: je     3fed <tail_handle_ipv6_from_netdev+0x3fed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3fed;
	}
x86_l_3fdc:
	/* 0x3fdc: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3fe3:
	/* 0x3fe3: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fe5:
	/* 0x3fe5: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_3fe8:
	/* 0x3fe8: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3feb:
	/* 0x3feb: jmp    3ff2 <tail_handle_ipv6_from_netdev+0x3ff2> */
	goto x86_l_3ff2;
x86_l_3fed:
	/* 0x3fed: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_3ff2:
	/* 0x3ff2: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ff4:
	/* 0x3ff4: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_3ff6:
	/* 0x3ff6: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_3ff8:
	/* 0x3ff8: jb     3ffe <tail_handle_ipv6_from_netdev+0x3ffe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3ffe;
	}
x86_l_3ffa:
	/* 0x3ffa: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_3ffc:
	/* 0x3ffc: je     400f <tail_handle_ipv6_from_netdev+0x400f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_400f;
	}
x86_l_3ffe:
	/* 0x3ffe: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_4002:
	/* 0x4002: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4006:
	/* 0x4006: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_400d:
	/* 0x400d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_400f:
	/* 0x400f: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_4016:
	/* 0x4016: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4019:
	/* 0x4019: je     402d <tail_handle_ipv6_from_netdev+0x402d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_402d;
	}
x86_l_401b:
	/* 0x401b: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_4024:
	/* 0x4024: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4028:
	/* 0x4028: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_402d:
	/* 0x402d: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4035:
	/* 0x4035: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_403a:
	/* 0x403a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_403f:
	/* 0x403f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_4042:
	/* 0x4042: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4044:
	/* 0x4044: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4046:
	/* 0x4046: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4048:
	/* 0x4048: js     43df <tail_handle_ipv6_from_netdev+0x43df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_43df;
	}
x86_l_404e:
	/* 0x404e: cmp    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4054:
	/* 0x4054: je     4065 <tail_handle_ipv6_from_netdev+0x4065> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4065;
	}
x86_l_4056:
	/* 0x4056: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4058:
	/* 0x4058: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_405b:
	/* 0x405b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_405d:
	/* 0x405d: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_4060:
	/* 0x4060: jmp    1c84 <tail_handle_ipv6_from_netdev+0x1c84> */
	return 7300ULL;
x86_l_4065:
	/* 0x4065: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_406e:
	/* 0x406e: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_4075:
	/* 0x4075: movzx  ebx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4078:
	/* 0x4078: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_407b:
	/* 0x407b: mov    r14d,DWORD PTR [r12+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_4080:
	/* 0x4080: mov    eax,DWORD PTR [r12+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4085:
	/* 0x4085: lea    rcx,[r14+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_4089:
	/* 0x4089: add    rcx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_408d:
	/* 0x408d: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_4093:
	/* 0x4093: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4096:
	/* 0x4096: ja     417c <tail_handle_ipv6_from_netdev+0x417c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_417c;
	}
x86_l_409c:
	/* 0x409c: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_40a1:
	/* 0x40a1: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_40a6:
	/* 0x40a6: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_40a9:
	/* 0x40a9: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_40ae:
	/* 0x40ae: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_40b3:
	/* 0x40b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b5:
	/* 0x40b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40b7:
	/* 0x40b7: js     417c <tail_handle_ipv6_from_netdev+0x417c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_417c;
	}
x86_l_40bd:
	/* 0x40bd: add    r14,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_40c0:
	/* 0x40c0: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_40c4:
	/* 0x40c4: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_40cb:
	/* 0x40cb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40d0:
	/* 0x40d0: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_40d3:
	/* 0x40d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40d5:
	/* 0x40d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40d8:
	/* 0x40d8: je     40f0 <tail_handle_ipv6_from_netdev+0x40f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40f0;
	}
x86_l_40da:
	/* 0x40da: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_40de:
	/* 0x40de: xor    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 0ULL);
x86_l_40e0:
	/* 0x40e0: movzx  edx,WORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_40e5:
	/* 0x40e5: xor    dx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 4ULL);
x86_l_40e9:
	/* 0x40e9: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_40ec:
	/* 0x40ec: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_40ee:
	/* 0x40ee: je     410c <tail_handle_ipv6_from_netdev+0x410c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_410c;
	}
x86_l_40f0:
	/* 0x40f0: mov    rdi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_40f7:
	/* 0x40f7: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_40fc:
	/* 0x40fc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4101:
	/* 0x4101: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4104:
	/* 0x4104: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4106:
	/* 0x4106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4108:
	/* 0x4108: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_410a:
	/* 0x410a: js     4179 <tail_handle_ipv6_from_netdev+0x4179> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_4179;
	}
x86_l_410c:
	/* 0x410c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4111:
	/* 0x4111: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_4115:
	/* 0x4115: mov    DWORD PTR [r12+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_411e:
	/* 0x411e: js     3f16 <tail_handle_ipv6_from_netdev+0x3f16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3f16;
	}
x86_l_4124:
	/* 0x4124: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_4127:
	/* 0x4127: mov    DWORD PTR [r12+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_4130:
	/* 0x4130: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_4137:
	/* 0x4137: mov    r14d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16ULL);
x86_l_413d:
	/* 0x413d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_4142:
	/* 0x4142: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4145:
	/* 0x4145: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_414a:
	/* 0x414a: jmp    3f70 <tail_handle_ipv6_from_netdev+0x3f70> */
	goto x86_l_3f70;
x86_l_414f:
	/* 0x414f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4151:
	/* 0x4151: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4153:
	/* 0x4153: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4156:
	/* 0x4156: je     4266 <tail_handle_ipv6_from_netdev+0x4266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4266;
	}
x86_l_415c:
	/* 0x415c: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4163:
	/* 0x4163: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4166:
	/* 0x4166: je     4184 <tail_handle_ipv6_from_netdev+0x4184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4184;
	}
x86_l_4168:
	/* 0x4168: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_416f:
	/* 0x416f: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4173:
	/* 0x4173: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4177:
	/* 0x4177: jmp    418a <tail_handle_ipv6_from_netdev+0x418a> */
	goto x86_l_418a;
x86_l_4179:
	/* 0x4179: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_417c:
	/* 0x417c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_417f:
	/* 0x417f: jmp    f7a <tail_handle_ipv6_from_netdev+0xf7a> */
	return 3962ULL;
x86_l_4184:
	/* 0x4184: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_418a:
	/* 0x418a: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_418e:
	/* 0x418e: jne    41cf <tail_handle_ipv6_from_netdev+0x41cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_41cf;
	}
x86_l_4190:
	/* 0x4190: mov    ecx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4194:
	/* 0x4194: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4196:
	/* 0x4196: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_4199:
	/* 0x4199: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_419c:
	/* 0x419c: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_419e:
	/* 0x419e: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_41a3:
	/* 0x41a3: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_41a5:
	/* 0x41a5: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_41aa:
	/* 0x41aa: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_41b0:
	/* 0x41b0: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_41b4:
	/* 0x41b4: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_41bb:
	/* 0x41bb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41be:
	/* 0x41be: je     41cf <tail_handle_ipv6_from_netdev+0x41cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41cf;
	}
x86_l_41c0:
	/* 0x41c0: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_41c7:
	/* 0x41c7: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_41cb:
	/* 0x41cb: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_41cf:
	/* 0x41cf: mov    ebx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_41d3:
	/* 0x41d3: shr    ebx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_41d6:
	/* 0x41d6: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_41dd:
	/* 0x41dd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e0:
	/* 0x41e0: je     41f1 <tail_handle_ipv6_from_netdev+0x41f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41f1;
	}
x86_l_41e2:
	/* 0x41e2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_41e7:
	/* 0x41e7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41e9:
	/* 0x41e9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_41eb:
	/* 0x41eb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_41ef:
	/* 0x41ef: jmp    4214 <tail_handle_ipv6_from_netdev+0x4214> */
	goto x86_l_4214;
x86_l_41f1:
	/* 0x41f1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_41f6:
	/* 0x41f6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41f8:
	/* 0x41f8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_41fa:
	/* 0x41fa: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_41fe:
	/* 0x41fe: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_4208:
	/* 0x4208: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_420b:
	/* 0x420b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4210:
	/* 0x4210: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_4214:
	/* 0x4214: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4217:
	/* 0x4217: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_421b:
	/* 0x421b: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_4220:
	/* 0x4220: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4224:
	/* 0x4224: and    bl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_4227:
	/* 0x4227: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_422e:
	/* 0x422e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4231:
	/* 0x4231: je     4244 <tail_handle_ipv6_from_netdev+0x4244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4244;
	}
x86_l_4233:
	/* 0x4233: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_423a:
	/* 0x423a: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_423c:
	/* 0x423c: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_423f:
	/* 0x423f: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4242:
	/* 0x4242: jmp    4249 <tail_handle_ipv6_from_netdev+0x4249> */
	goto x86_l_4249;
x86_l_4244:
	/* 0x4244: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_4249:
	/* 0x4249: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_424b:
	/* 0x424b: or     bl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_424d:
	/* 0x424d: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_424f:
	/* 0x424f: jb     4255 <tail_handle_ipv6_from_netdev+0x4255> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4255;
	}
x86_l_4251:
	/* 0x4251: cmp    cl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_8);
x86_l_4253:
	/* 0x4253: je     4266 <tail_handle_ipv6_from_netdev+0x4266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4266;
	}
x86_l_4255:
	/* 0x4255: mov    BYTE PTR [r14+0x2a],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_4259:
	/* 0x4259: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_425d:
	/* 0x425d: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4264:
	/* 0x4264: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4266:
	/* 0x4266: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_426d:
	/* 0x426d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4270:
	/* 0x4270: je     4280 <tail_handle_ipv6_from_netdev+0x4280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4280;
	}
x86_l_4272:
	/* 0x4272: inc QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_4277:
	/* 0x4277: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_427b:
	/* 0x427b: add QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_4280:
	/* 0x4280: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_4284:
	/* 0x4284: je     42d2 <tail_handle_ipv6_from_netdev+0x42d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42d2;
	}
x86_l_4286:
	/* 0x4286: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_428a:
	/* 0x428a: jne    404e <tail_handle_ipv6_from_netdev+0x404e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_404e;
	}
x86_l_4290:
	/* 0x4290: movzx  eax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_4295:
	/* 0x4295: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_4297:
	/* 0x4297: je     404e <tail_handle_ipv6_from_netdev+0x404e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404e;
	}
x86_l_429d:
	/* 0x429d: mov    WORD PTR [r14+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_42a4:
	/* 0x42a4: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_42a9:
	/* 0x42a9: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_42ae:
	/* 0x42ae: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_42b5:
	/* 0x42b5: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42b8:
	/* 0x42b8: je     492e <tail_handle_ipv6_from_netdev+0x492e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18734ULL;
	}
x86_l_42be:
	/* 0x42be: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_42c5:
	/* 0x42c5: imul   r15d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_42c9:
	/* 0x42c9: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_42cd:
	/* 0x42cd: jmp    4934 <tail_handle_ipv6_from_netdev+0x4934> */
	return 18740ULL;
x86_l_42d2:
	/* 0x42d2: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_42d6:
	/* 0x42d6: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_42db:
	/* 0x42db: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42de:
	/* 0x42de: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_42e2:
	/* 0x42e2: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_42e6:
	/* 0x42e6: or     ax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_42eb:
	/* 0x42eb: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_42f0:
	/* 0x42f0: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_42f7:
	/* 0x42f7: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42f9:
	/* 0x42f9: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_42fb:
	/* 0x42fb: je     404e <tail_handle_ipv6_from_netdev+0x404e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404e;
	}
x86_l_4301:
	/* 0x4301: mov    r15,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4308:
	/* 0x4308: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_430c:
	/* 0x430c: je     4321 <tail_handle_ipv6_from_netdev+0x4321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4321;
	}
x86_l_430e:
	/* 0x430e: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4315:
	/* 0x4315: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4317:
	/* 0x4317: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4319:
	/* 0x4319: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_431c:
	/* 0x431c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_431f:
	/* 0x431f: jmp    4326 <tail_handle_ipv6_from_netdev+0x4326> */
	goto x86_l_4326;
x86_l_4321:
	/* 0x4321: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_4326:
	/* 0x4326: shr    DWORD PTR [rsp+0x60],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 412316860424ULL);
x86_l_432b:
	/* 0x432b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_432f:
	/* 0x432f: je     4340 <tail_handle_ipv6_from_netdev+0x4340> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4340;
	}
x86_l_4331:
	/* 0x4331: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_4336:
	/* 0x4336: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4338:
	/* 0x4338: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_433a:
	/* 0x433a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_433e:
	/* 0x433e: jmp    4363 <tail_handle_ipv6_from_netdev+0x4363> */
	goto x86_l_4363;
x86_l_4340:
	/* 0x4340: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4345:
	/* 0x4345: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4347:
	/* 0x4347: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4349:
	/* 0x4349: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_434d:
	/* 0x434d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_4357:
	/* 0x4357: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_435a:
	/* 0x435a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_435f:
	/* 0x435f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_4363:
	/* 0x4363: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4365:
	/* 0x4365: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4369:
	/* 0x4369: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_436e:
	/* 0x436e: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4372:
	/* 0x4372: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4376:
	/* 0x4376: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_437a:
	/* 0x437a: mov    DWORD PTR [rsp+0x60],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_437e:
	/* 0x437e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4382:
	/* 0x4382: je     4395 <tail_handle_ipv6_from_netdev+0x4395> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4395;
	}
x86_l_4384:
	/* 0x4384: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_438b:
	/* 0x438b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_438d:
	/* 0x438d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_4390:
	/* 0x4390: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4393:
	/* 0x4393: jmp    439a <tail_handle_ipv6_from_netdev+0x439a> */
	goto x86_l_439a;
x86_l_4395:
	/* 0x4395: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_439a:
	/* 0x439a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_439c:
	/* 0x439c: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_43a0:
	/* 0x43a0: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_43a2:
	/* 0x43a2: mov    DWORD PTR [rsp+0x60],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_43a6:
	/* 0x43a6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_43a8:
	/* 0x43a8: jb     43b4 <tail_handle_ipv6_from_netdev+0x43b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_43b4;
	}
x86_l_43aa:
	/* 0x43aa: cmp    cl,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_43ae:
	/* 0x43ae: je     404e <tail_handle_ipv6_from_netdev+0x404e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_404e;
	}
x86_l_43b4:
	/* 0x43b4: mov    ecx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_43b8:
	/* 0x43b8: mov    BYTE PTR [r14+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_43bc:
	/* 0x43bc: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43c0:
	/* 0x43c0: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43c2:
	/* 0x43c2: jmp    404e <tail_handle_ipv6_from_netdev+0x404e> */
	goto x86_l_404e;
x86_l_43c7:
	/* 0x43c7: mov    r15d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967141ULL);
x86_l_43cd:
	/* 0x43cd: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_43d0:
	/* 0x43d0: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43d5:
	/* 0x43d5: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43da:
	/* 0x43da: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
x86_l_43df:
	/* 0x43df: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_43e2:
	/* 0x43e2: mov    r15d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967141ULL);
x86_l_43e8:
	/* 0x43e8: jmp    f7a <tail_handle_ipv6_from_netdev+0xf7a> */
	return 3962ULL;
x86_l_43ed:
	/* 0x43ed: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_43f3:
	/* 0x43f3: jmp    3df1 <tail_handle_ipv6_from_netdev+0x3df1> */
	return 15857ULL;
x86_l_43f8:
	/* 0x43f8: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_43fe:
	/* 0x43fe: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_4403:
	/* 0x4403: jne    443c <tail_handle_ipv6_from_netdev+0x443c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_443c;
	}
x86_l_4405:
	/* 0x4405: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_4408:
	/* 0x4408: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_440a:
	/* 0x440a: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_440d:
	/* 0x440d: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_4410:
	/* 0x4410: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4412:
	/* 0x4412: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4417:
	/* 0x4417: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4419:
	/* 0x4419: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_441e:
	/* 0x441e: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_4424:
	/* 0x4424: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_4428:
	/* 0x4428: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_442b:
	/* 0x442b: je     443c <tail_handle_ipv6_from_netdev+0x443c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_443c;
	}
x86_l_442d:
	/* 0x442d: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4434:
	/* 0x4434: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_4438:
	/* 0x4438: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_443c:
	/* 0x443c: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4440:
	/* 0x4440: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4443:
	/* 0x4443: je     4454 <tail_handle_ipv6_from_netdev+0x4454> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 17492ULL;
	}
	return 17477ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_10(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 17477ULL: goto x86_l_4445;
	case 17482ULL: goto x86_l_444a;
	case 17484ULL: goto x86_l_444c;
	case 17486ULL: goto x86_l_444e;
	case 17490ULL: goto x86_l_4452;
	case 17492ULL: goto x86_l_4454;
	case 17497ULL: goto x86_l_4459;
	case 17499ULL: goto x86_l_445b;
	case 17501ULL: goto x86_l_445d;
	case 17505ULL: goto x86_l_4461;
	case 17515ULL: goto x86_l_446b;
	case 17518ULL: goto x86_l_446e;
	case 17523ULL: goto x86_l_4473;
	case 17527ULL: goto x86_l_4477;
	case 17530ULL: goto x86_l_447a;
	case 17534ULL: goto x86_l_447e;
	case 17539ULL: goto x86_l_4483;
	case 17543ULL: goto x86_l_4487;
	case 17547ULL: goto x86_l_448b;
	case 17550ULL: goto x86_l_448e;
	case 17552ULL: goto x86_l_4490;
	case 17559ULL: goto x86_l_4497;
	case 17561ULL: goto x86_l_4499;
	case 17564ULL: goto x86_l_449c;
	case 17567ULL: goto x86_l_449f;
	case 17569ULL: goto x86_l_44a1;
	case 17574ULL: goto x86_l_44a6;
	case 17576ULL: goto x86_l_44a8;
	case 17579ULL: goto x86_l_44ab;
	case 17581ULL: goto x86_l_44ad;
	case 17583ULL: goto x86_l_44af;
	case 17585ULL: goto x86_l_44b1;
	case 17588ULL: goto x86_l_44b4;
	case 17590ULL: goto x86_l_44b6;
	case 17594ULL: goto x86_l_44ba;
	case 17598ULL: goto x86_l_44be;
	case 17605ULL: goto x86_l_44c5;
	case 17607ULL: goto x86_l_44c7;
	case 17612ULL: goto x86_l_44cc;
	case 17615ULL: goto x86_l_44cf;
	case 17619ULL: goto x86_l_44d3;
	case 17623ULL: goto x86_l_44d7;
	case 17626ULL: goto x86_l_44da;
	case 17630ULL: goto x86_l_44de;
	case 17634ULL: goto x86_l_44e2;
	case 17638ULL: goto x86_l_44e6;
	case 17642ULL: goto x86_l_44ea;
	case 17645ULL: goto x86_l_44ed;
	case 17649ULL: goto x86_l_44f1;
	case 17653ULL: goto x86_l_44f5;
	case 17661ULL: goto x86_l_44fd;
	case 17666ULL: goto x86_l_4502;
	case 17671ULL: goto x86_l_4507;
	case 17673ULL: goto x86_l_4509;
	case 17676ULL: goto x86_l_450c;
	case 17678ULL: goto x86_l_450e;
	case 17681ULL: goto x86_l_4511;
	case 17684ULL: goto x86_l_4514;
	case 17686ULL: goto x86_l_4516;
	case 17688ULL: goto x86_l_4518;
	case 17691ULL: goto x86_l_451b;
	case 17697ULL: goto x86_l_4521;
	case 17704ULL: goto x86_l_4528;
	case 17707ULL: goto x86_l_452b;
	case 17709ULL: goto x86_l_452d;
	case 17716ULL: goto x86_l_4534;
	case 17720ULL: goto x86_l_4538;
	case 17724ULL: goto x86_l_453c;
	case 17726ULL: goto x86_l_453e;
	case 17733ULL: goto x86_l_4545;
	case 17735ULL: goto x86_l_4547;
	case 17740ULL: goto x86_l_454c;
	case 17743ULL: goto x86_l_454f;
	case 17745ULL: goto x86_l_4551;
	case 17750ULL: goto x86_l_4556;
	case 17756ULL: goto x86_l_455c;
	case 17761ULL: goto x86_l_4561;
	case 17763ULL: goto x86_l_4563;
	case 17766ULL: goto x86_l_4566;
	case 17768ULL: goto x86_l_4568;
	case 17771ULL: goto x86_l_456b;
	case 17774ULL: goto x86_l_456e;
	case 17776ULL: goto x86_l_4570;
	case 17781ULL: goto x86_l_4575;
	case 17783ULL: goto x86_l_4577;
	case 17788ULL: goto x86_l_457c;
	case 17794ULL: goto x86_l_4582;
	case 17798ULL: goto x86_l_4586;
	case 17801ULL: goto x86_l_4589;
	case 17803ULL: goto x86_l_458b;
	case 17810ULL: goto x86_l_4592;
	case 17814ULL: goto x86_l_4596;
	case 17818ULL: goto x86_l_459a;
	case 17821ULL: goto x86_l_459d;
	case 17825ULL: goto x86_l_45a1;
	case 17828ULL: goto x86_l_45a4;
	case 17830ULL: goto x86_l_45a6;
	case 17835ULL: goto x86_l_45ab;
	case 17837ULL: goto x86_l_45ad;
	case 17839ULL: goto x86_l_45af;
	case 17843ULL: goto x86_l_45b3;
	case 17845ULL: goto x86_l_45b5;
	case 17850ULL: goto x86_l_45ba;
	case 17852ULL: goto x86_l_45bc;
	case 17854ULL: goto x86_l_45be;
	case 17858ULL: goto x86_l_45c2;
	case 17868ULL: goto x86_l_45cc;
	case 17871ULL: goto x86_l_45cf;
	case 17876ULL: goto x86_l_45d4;
	case 17880ULL: goto x86_l_45d8;
	case 17883ULL: goto x86_l_45db;
	case 17887ULL: goto x86_l_45df;
	case 17892ULL: goto x86_l_45e4;
	case 17896ULL: goto x86_l_45e8;
	case 17900ULL: goto x86_l_45ec;
	case 17903ULL: goto x86_l_45ef;
	case 17905ULL: goto x86_l_45f1;
	case 17912ULL: goto x86_l_45f8;
	case 17914ULL: goto x86_l_45fa;
	case 17917ULL: goto x86_l_45fd;
	case 17920ULL: goto x86_l_4600;
	case 17922ULL: goto x86_l_4602;
	case 17927ULL: goto x86_l_4607;
	case 17929ULL: goto x86_l_4609;
	case 17932ULL: goto x86_l_460c;
	case 17934ULL: goto x86_l_460e;
	case 17936ULL: goto x86_l_4610;
	case 17938ULL: goto x86_l_4612;
	case 17941ULL: goto x86_l_4615;
	case 17943ULL: goto x86_l_4617;
	case 17947ULL: goto x86_l_461b;
	case 17951ULL: goto x86_l_461f;
	case 17958ULL: goto x86_l_4626;
	case 17960ULL: goto x86_l_4628;
	case 17965ULL: goto x86_l_462d;
	case 17968ULL: goto x86_l_4630;
	case 17975ULL: goto x86_l_4637;
	case 17978ULL: goto x86_l_463a;
	case 17980ULL: goto x86_l_463c;
	case 17985ULL: goto x86_l_4641;
	case 17990ULL: goto x86_l_4646;
	case 17992ULL: goto x86_l_4648;
	case 17997ULL: goto x86_l_464d;
	case 18002ULL: goto x86_l_4652;
	case 18005ULL: goto x86_l_4655;
	case 18007ULL: goto x86_l_4657;
	case 18010ULL: goto x86_l_465a;
	case 18016ULL: goto x86_l_4660;
	case 18021ULL: goto x86_l_4665;
	case 18023ULL: goto x86_l_4667;
	case 18029ULL: goto x86_l_466d;
	case 18036ULL: goto x86_l_4674;
	case 18041ULL: goto x86_l_4679;
	case 18046ULL: goto x86_l_467e;
	case 18053ULL: goto x86_l_4685;
	case 18056ULL: goto x86_l_4688;
	case 18062ULL: goto x86_l_468e;
	case 18069ULL: goto x86_l_4695;
	case 18072ULL: goto x86_l_4698;
	case 18075ULL: goto x86_l_469b;
	case 18080ULL: goto x86_l_46a0;
	case 18083ULL: goto x86_l_46a3;
	case 18086ULL: goto x86_l_46a6;
	case 18089ULL: goto x86_l_46a9;
	case 18094ULL: goto x86_l_46ae;
	case 18097ULL: goto x86_l_46b1;
	case 18102ULL: goto x86_l_46b6;
	case 18109ULL: goto x86_l_46bd;
	case 18112ULL: goto x86_l_46c0;
	case 18117ULL: goto x86_l_46c5;
	case 18120ULL: goto x86_l_46c8;
	case 18124ULL: goto x86_l_46cc;
	case 18126ULL: goto x86_l_46ce;
	case 18128ULL: goto x86_l_46d0;
	case 18134ULL: goto x86_l_46d6;
	case 18141ULL: goto x86_l_46dd;
	case 18146ULL: goto x86_l_46e2;
	case 18148ULL: goto x86_l_46e4;
	case 18155ULL: goto x86_l_46eb;
	case 18157ULL: goto x86_l_46ed;
	case 18159ULL: goto x86_l_46ef;
	case 18162ULL: goto x86_l_46f2;
	case 18165ULL: goto x86_l_46f5;
	case 18167ULL: goto x86_l_46f7;
	case 18172ULL: goto x86_l_46fc;
	case 18176ULL: goto x86_l_4700;
	case 18181ULL: goto x86_l_4705;
	case 18183ULL: goto x86_l_4707;
	case 18188ULL: goto x86_l_470c;
	case 18190ULL: goto x86_l_470e;
	case 18192ULL: goto x86_l_4710;
	case 18196ULL: goto x86_l_4714;
	case 18198ULL: goto x86_l_4716;
	case 18203ULL: goto x86_l_471b;
	case 18205ULL: goto x86_l_471d;
	case 18207ULL: goto x86_l_471f;
	case 18211ULL: goto x86_l_4723;
	case 18221ULL: goto x86_l_472d;
	case 18224ULL: goto x86_l_4730;
	case 18229ULL: goto x86_l_4735;
	case 18233ULL: goto x86_l_4739;
	case 18235ULL: goto x86_l_473b;
	case 18239ULL: goto x86_l_473f;
	case 18244ULL: goto x86_l_4744;
	case 18248ULL: goto x86_l_4748;
	case 18252ULL: goto x86_l_474c;
	case 18257ULL: goto x86_l_4751;
	case 18259ULL: goto x86_l_4753;
	case 18266ULL: goto x86_l_475a;
	case 18268ULL: goto x86_l_475c;
	case 18271ULL: goto x86_l_475f;
	case 18274ULL: goto x86_l_4762;
	case 18276ULL: goto x86_l_4764;
	case 18281ULL: goto x86_l_4769;
	case 18283ULL: goto x86_l_476b;
	case 18286ULL: goto x86_l_476e;
	case 18288ULL: goto x86_l_4770;
	case 18290ULL: goto x86_l_4772;
	case 18293ULL: goto x86_l_4775;
	case 18299ULL: goto x86_l_477b;
	case 18303ULL: goto x86_l_477f;
	case 18307ULL: goto x86_l_4783;
	case 18310ULL: goto x86_l_4786;
	case 18315ULL: goto x86_l_478b;
	case 18321ULL: goto x86_l_4791;
	case 18325ULL: goto x86_l_4795;
	case 18327ULL: goto x86_l_4797;
	case 18329ULL: goto x86_l_4799;
	case 18331ULL: goto x86_l_479b;
	case 18334ULL: goto x86_l_479e;
	case 18337ULL: goto x86_l_47a1;
	case 18339ULL: goto x86_l_47a3;
	case 18344ULL: goto x86_l_47a8;
	case 18346ULL: goto x86_l_47aa;
	case 18351ULL: goto x86_l_47af;
	case 18357ULL: goto x86_l_47b5;
	case 18361ULL: goto x86_l_47b9;
	case 18366ULL: goto x86_l_47be;
	case 18368ULL: goto x86_l_47c0;
	case 18375ULL: goto x86_l_47c7;
	case 18379ULL: goto x86_l_47cb;
	case 18383ULL: goto x86_l_47cf;
	case 18386ULL: goto x86_l_47d2;
	case 18391ULL: goto x86_l_47d7;
	case 18393ULL: goto x86_l_47d9;
	case 18398ULL: goto x86_l_47de;
	case 18400ULL: goto x86_l_47e0;
	case 18402ULL: goto x86_l_47e2;
	case 18406ULL: goto x86_l_47e6;
	case 18408ULL: goto x86_l_47e8;
	case 18413ULL: goto x86_l_47ed;
	case 18415ULL: goto x86_l_47ef;
	case 18417ULL: goto x86_l_47f1;
	case 18421ULL: goto x86_l_47f5;
	case 18431ULL: goto x86_l_47ff;
	case 18434ULL: goto x86_l_4802;
	case 18439ULL: goto x86_l_4807;
	case 18443ULL: goto x86_l_480b;
	case 18446ULL: goto x86_l_480e;
	case 18450ULL: goto x86_l_4812;
	case 18455ULL: goto x86_l_4817;
	case 18459ULL: goto x86_l_481b;
	case 18462ULL: goto x86_l_481e;
	case 18467ULL: goto x86_l_4823;
	case 18469ULL: goto x86_l_4825;
	case 18476ULL: goto x86_l_482c;
	case 18478ULL: goto x86_l_482e;
	case 18481ULL: goto x86_l_4831;
	case 18484ULL: goto x86_l_4834;
	case 18486ULL: goto x86_l_4836;
	case 18491ULL: goto x86_l_483b;
	case 18493ULL: goto x86_l_483d;
	case 18495ULL: goto x86_l_483f;
	case 18497ULL: goto x86_l_4841;
	case 18499ULL: goto x86_l_4843;
	case 18501ULL: goto x86_l_4845;
	case 18507ULL: goto x86_l_484b;
	case 18511ULL: goto x86_l_484f;
	case 18515ULL: goto x86_l_4853;
	case 18520ULL: goto x86_l_4858;
	case 18525ULL: goto x86_l_485d;
	case 18530ULL: goto x86_l_4862;
	case 18532ULL: goto x86_l_4864;
	case 18535ULL: goto x86_l_4867;
	case 18537ULL: goto x86_l_4869;
	case 18540ULL: goto x86_l_486c;
	case 18543ULL: goto x86_l_486f;
	case 18545ULL: goto x86_l_4871;
	case 18550ULL: goto x86_l_4876;
	case 18552ULL: goto x86_l_4878;
	case 18557ULL: goto x86_l_487d;
	case 18562ULL: goto x86_l_4882;
	case 18565ULL: goto x86_l_4885;
	case 18568ULL: goto x86_l_4888;
	case 18570ULL: goto x86_l_488a;
	case 18577ULL: goto x86_l_4891;
	case 18580ULL: goto x86_l_4894;
	case 18583ULL: goto x86_l_4897;
	case 18587ULL: goto x86_l_489b;
	case 18590ULL: goto x86_l_489e;
	case 18592ULL: goto x86_l_48a0;
	case 18597ULL: goto x86_l_48a5;
	case 18599ULL: goto x86_l_48a7;
	case 18601ULL: goto x86_l_48a9;
	case 18605ULL: goto x86_l_48ad;
	case 18607ULL: goto x86_l_48af;
	case 18612ULL: goto x86_l_48b4;
	case 18614ULL: goto x86_l_48b6;
	case 18616ULL: goto x86_l_48b8;
	case 18620ULL: goto x86_l_48bc;
	case 18630ULL: goto x86_l_48c6;
	case 18633ULL: goto x86_l_48c9;
	case 18638ULL: goto x86_l_48ce;
	case 18642ULL: goto x86_l_48d2;
	case 18644ULL: goto x86_l_48d4;
	case 18648ULL: goto x86_l_48d8;
	case 18653ULL: goto x86_l_48dd;
	case 18657ULL: goto x86_l_48e1;
	case 18661ULL: goto x86_l_48e5;
	case 18664ULL: goto x86_l_48e8;
	case 18666ULL: goto x86_l_48ea;
	case 18673ULL: goto x86_l_48f1;
	case 18675ULL: goto x86_l_48f3;
	case 18678ULL: goto x86_l_48f6;
	case 18681ULL: goto x86_l_48f9;
	case 18683ULL: goto x86_l_48fb;
	case 18688ULL: goto x86_l_4900;
	case 18690ULL: goto x86_l_4902;
	case 18693ULL: goto x86_l_4905;
	case 18695ULL: goto x86_l_4907;
	case 18697ULL: goto x86_l_4909;
	case 18699ULL: goto x86_l_490b;
	case 18702ULL: goto x86_l_490e;
	case 18704ULL: goto x86_l_4910;
	case 18708ULL: goto x86_l_4914;
	case 18712ULL: goto x86_l_4918;
	case 18719ULL: goto x86_l_491f;
	case 18721ULL: goto x86_l_4921;
	case 18726ULL: goto x86_l_4926;
	case 18729ULL: goto x86_l_4929;
	case 18734ULL: goto x86_l_492e;
	case 18740ULL: goto x86_l_4934;
	case 18744ULL: goto x86_l_4938;
	case 18746ULL: goto x86_l_493a;
	case 18750ULL: goto x86_l_493e;
	case 18752ULL: goto x86_l_4940;
	case 18755ULL: goto x86_l_4943;
	case 18758ULL: goto x86_l_4946;
	case 18760ULL: goto x86_l_4948;
	case 18765ULL: goto x86_l_494d;
	case 18767ULL: goto x86_l_494f;
	case 18772ULL: goto x86_l_4954;
	case 18778ULL: goto x86_l_495a;
	case 18782ULL: goto x86_l_495e;
	case 18785ULL: goto x86_l_4961;
	case 18787ULL: goto x86_l_4963;
	case 18794ULL: goto x86_l_496a;
	case 18798ULL: goto x86_l_496e;
	case 18802ULL: goto x86_l_4972;
	case 18807ULL: goto x86_l_4977;
	case 18810ULL: goto x86_l_497a;
	case 18812ULL: goto x86_l_497c;
	case 18817ULL: goto x86_l_4981;
	case 18819ULL: goto x86_l_4983;
	case 18821ULL: goto x86_l_4985;
	case 18825ULL: goto x86_l_4989;
	case 18827ULL: goto x86_l_498b;
	case 18832ULL: goto x86_l_4990;
	case 18834ULL: goto x86_l_4992;
	case 18836ULL: goto x86_l_4994;
	case 18840ULL: goto x86_l_4998;
	case 18850ULL: goto x86_l_49a2;
	case 18853ULL: goto x86_l_49a5;
	case 18858ULL: goto x86_l_49aa;
	case 18862ULL: goto x86_l_49ae;
	case 18865ULL: goto x86_l_49b1;
	case 18869ULL: goto x86_l_49b5;
	case 18874ULL: goto x86_l_49ba;
	case 18878ULL: goto x86_l_49be;
	case 18882ULL: goto x86_l_49c2;
	case 18886ULL: goto x86_l_49c6;
	case 18890ULL: goto x86_l_49ca;
	case 18893ULL: goto x86_l_49cd;
	case 18895ULL: goto x86_l_49cf;
	default: return 0xffffffffffffffffULL;
	}
x86_l_4445:
	/* 0x4445: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_444a:
	/* 0x444a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_444c:
	/* 0x444c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_444e:
	/* 0x444e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4452:
	/* 0x4452: jmp    4477 <tail_handle_ipv6_from_netdev+0x4477> */
	goto x86_l_4477;
x86_l_4454:
	/* 0x4454: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4459:
	/* 0x4459: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_445b:
	/* 0x445b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_445d:
	/* 0x445d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_4461:
	/* 0x4461: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_446b:
	/* 0x446b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_446e:
	/* 0x446e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4473:
	/* 0x4473: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_4477:
	/* 0x4477: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_447a:
	/* 0x447a: mov    DWORD PTR [r13+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_447e:
	/* 0x447e: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_4483:
	/* 0x4483: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4487:
	/* 0x4487: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_448b:
	/* 0x448b: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_448e:
	/* 0x448e: je     44a1 <tail_handle_ipv6_from_netdev+0x44a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44a1;
	}
x86_l_4490:
	/* 0x4490: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4497:
	/* 0x4497: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4499:
	/* 0x4499: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_449c:
	/* 0x449c: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_449f:
	/* 0x449f: jmp    44a6 <tail_handle_ipv6_from_netdev+0x44a6> */
	goto x86_l_44a6;
x86_l_44a1:
	/* 0x44a1: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_44a6:
	/* 0x44a6: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_44a8:
	/* 0x44a8: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_44ab:
	/* 0x44ab: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_44ad:
	/* 0x44ad: jb     44b6 <tail_handle_ipv6_from_netdev+0x44b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_44b6;
	}
x86_l_44af:
	/* 0x44af: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44b1:
	/* 0x44b1: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_44b4:
	/* 0x44b4: je     44c7 <tail_handle_ipv6_from_netdev+0x44c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_44c7;
	}
x86_l_44b6:
	/* 0x44b6: mov    BYTE PTR [r13+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_44ba:
	/* 0x44ba: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_44be:
	/* 0x44be: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_44c5:
	/* 0x44c5: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c7:
	/* 0x44c7: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_44cc:
	/* 0x44cc: mov    DWORD PTR [rsi+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_44cf:
	/* 0x44cf: mov    rax,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44d3:
	/* 0x44d3: mov    rcx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44d7:
	/* 0x44d7: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44da:
	/* 0x44da: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44de:
	/* 0x44de: mov    QWORD PTR [rsi+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_44e2:
	/* 0x44e2: mov    QWORD PTR [rsi+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44e6:
	/* 0x44e6: mov    QWORD PTR [rsi+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44ea:
	/* 0x44ea: mov    QWORD PTR [rsi],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44ed:
	/* 0x44ed: rol    DWORD PTR [rsi+0x20],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSI, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 137438953488ULL);
x86_l_44f1:
	/* 0x44f1: xor    BYTE PTR [rsi+0x25],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSI, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 158913789953ULL);
x86_l_44f5:
	/* 0x44f5: mov    r13d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_44fd:
	/* 0x44fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4502:
	/* 0x4502: mov    rdi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4507:
	/* 0x4507: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4509:
	/* 0x4509: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_450c:
	/* 0x450c: je     453e <tail_handle_ipv6_from_netdev+0x453e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_453e;
	}
x86_l_450e:
	/* 0x450e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4511:
	/* 0x4511: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4514:
	/* 0x4514: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4516:
	/* 0x4516: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4518:
	/* 0x4518: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_451b:
	/* 0x451b: je     4630 <tail_handle_ipv6_from_netdev+0x4630> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4630;
	}
x86_l_4521:
	/* 0x4521: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4528:
	/* 0x4528: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_452b:
	/* 0x452b: je     4556 <tail_handle_ipv6_from_netdev+0x4556> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4556;
	}
x86_l_452d:
	/* 0x452d: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4534:
	/* 0x4534: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4538:
	/* 0x4538: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_453c:
	/* 0x453c: jmp    455c <tail_handle_ipv6_from_netdev+0x455c> */
	goto x86_l_455c;
x86_l_453e:
	/* 0x453e: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4545:
	/* 0x4545: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4547:
	/* 0x4547: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_454c:
	/* 0x454c: mov    DWORD PTR [rcx+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_454f:
	/* 0x454f: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4551:
	/* 0x4551: jmp    31c6 <tail_handle_ipv6_from_netdev+0x31c6> */
	return 12742ULL;
x86_l_4556:
	/* 0x4556: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_455c:
	/* 0x455c: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_4561:
	/* 0x4561: jne    459a <tail_handle_ipv6_from_netdev+0x459a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_459a;
	}
x86_l_4563:
	/* 0x4563: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_4566:
	/* 0x4566: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4568:
	/* 0x4568: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_456b:
	/* 0x456b: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_456e:
	/* 0x456e: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4570:
	/* 0x4570: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4575:
	/* 0x4575: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_4577:
	/* 0x4577: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_457c:
	/* 0x457c: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_4582:
	/* 0x4582: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_4586:
	/* 0x4586: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4589:
	/* 0x4589: je     459a <tail_handle_ipv6_from_netdev+0x459a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_459a;
	}
x86_l_458b:
	/* 0x458b: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4592:
	/* 0x4592: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_4596:
	/* 0x4596: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_459a:
	/* 0x459a: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_459d:
	/* 0x459d: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_45a1:
	/* 0x45a1: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45a4:
	/* 0x45a4: je     45b5 <tail_handle_ipv6_from_netdev+0x45b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_45b5;
	}
x86_l_45a6:
	/* 0x45a6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_45ab:
	/* 0x45ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45ad:
	/* 0x45ad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_45af:
	/* 0x45af: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_45b3:
	/* 0x45b3: jmp    45d8 <tail_handle_ipv6_from_netdev+0x45d8> */
	goto x86_l_45d8;
x86_l_45b5:
	/* 0x45b5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_45ba:
	/* 0x45ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45bc:
	/* 0x45bc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_45be:
	/* 0x45be: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_45c2:
	/* 0x45c2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_45cc:
	/* 0x45cc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_45cf:
	/* 0x45cf: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_45d4:
	/* 0x45d4: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_45d8:
	/* 0x45d8: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_45db:
	/* 0x45db: mov    DWORD PTR [r15+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45df:
	/* 0x45df: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_45e4:
	/* 0x45e4: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_45e8:
	/* 0x45e8: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_45ec:
	/* 0x45ec: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45ef:
	/* 0x45ef: je     4602 <tail_handle_ipv6_from_netdev+0x4602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4602;
	}
x86_l_45f1:
	/* 0x45f1: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_45f8:
	/* 0x45f8: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45fa:
	/* 0x45fa: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_45fd:
	/* 0x45fd: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4600:
	/* 0x4600: jmp    4607 <tail_handle_ipv6_from_netdev+0x4607> */
	goto x86_l_4607;
x86_l_4602:
	/* 0x4602: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_4607:
	/* 0x4607: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4609:
	/* 0x4609: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_460c:
	/* 0x460c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_460e:
	/* 0x460e: jb     4617 <tail_handle_ipv6_from_netdev+0x4617> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4617;
	}
x86_l_4610:
	/* 0x4610: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4612:
	/* 0x4612: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_4615:
	/* 0x4615: je     4628 <tail_handle_ipv6_from_netdev+0x4628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4628;
	}
x86_l_4617:
	/* 0x4617: mov    BYTE PTR [r15+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_461b:
	/* 0x461b: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_461f:
	/* 0x461f: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4626:
	/* 0x4626: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4628:
	/* 0x4628: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_462d:
	/* 0x462d: mov    DWORD PTR [rax+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4630:
	/* 0x4630: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_4637:
	/* 0x4637: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_463a:
	/* 0x463a: je     464d <tail_handle_ipv6_from_netdev+0x464d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_464d;
	}
x86_l_463c:
	/* 0x463c: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_4641:
	/* 0x4641: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4646:
	/* 0x4646: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4648:
	/* 0x4648: add QWORD PTR [r15+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_464d:
	/* 0x464d: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_4652:
	/* 0x4652: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4655:
	/* 0x4655: je     46a0 <tail_handle_ipv6_from_netdev+0x46a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46a0;
	}
x86_l_4657:
	/* 0x4657: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_465a:
	/* 0x465a: jne    31c6 <tail_handle_ipv6_from_netdev+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12742ULL;
	}
x86_l_4660:
	/* 0x4660: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_4665:
	/* 0x4665: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_4667:
	/* 0x4667: je     31c6 <tail_handle_ipv6_from_netdev+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_466d:
	/* 0x466d: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_4674:
	/* 0x4674: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_4679:
	/* 0x4679: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_467e:
	/* 0x467e: mov    rbx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4685:
	/* 0x4685: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4688:
	/* 0x4688: je     4858 <tail_handle_ipv6_from_netdev+0x4858> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4858;
	}
x86_l_468e:
	/* 0x468e: mov    rcx,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4695:
	/* 0x4695: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4698:
	/* 0x4698: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_469b:
	/* 0x469b: jmp    485d <tail_handle_ipv6_from_netdev+0x485d> */
	goto x86_l_485d;
x86_l_46a0:
	/* 0x46a0: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_46a3:
	/* 0x46a3: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_46a6:
	/* 0x46a6: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_46a9:
	/* 0x46a9: or     ax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_46ae:
	/* 0x46ae: or     eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_46b1:
	/* 0x46b1: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_46b6:
	/* 0x46b6: mov    r14,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_46bd:
	/* 0x46bd: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46c0:
	/* 0x46c0: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_46c5:
	/* 0x46c5: mov    DWORD PTR [rcx+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_46c8:
	/* 0x46c8: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_46cc:
	/* 0x46cc: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_46ce:
	/* 0x46ce: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_46d0:
	/* 0x46d0: jne    31c6 <tail_handle_ipv6_from_netdev+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12742ULL;
	}
x86_l_46d6:
	/* 0x46d6: mov    r12,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_46dd:
	/* 0x46dd: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46e2:
	/* 0x46e2: je     46f7 <tail_handle_ipv6_from_netdev+0x46f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_46f7;
	}
x86_l_46e4:
	/* 0x46e4: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_46eb:
	/* 0x46eb: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46ed:
	/* 0x46ed: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_46ef:
	/* 0x46ef: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_46f2:
	/* 0x46f2: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_46f5:
	/* 0x46f5: jmp    46fc <tail_handle_ipv6_from_netdev+0x46fc> */
	goto x86_l_46fc;
x86_l_46f7:
	/* 0x46f7: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_46fc:
	/* 0x46fc: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4700:
	/* 0x4700: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4705:
	/* 0x4705: je     4716 <tail_handle_ipv6_from_netdev+0x4716> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4716;
	}
x86_l_4707:
	/* 0x4707: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_470c:
	/* 0x470c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_470e:
	/* 0x470e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4710:
	/* 0x4710: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4714:
	/* 0x4714: jmp    4739 <tail_handle_ipv6_from_netdev+0x4739> */
	goto x86_l_4739;
x86_l_4716:
	/* 0x4716: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_471b:
	/* 0x471b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_471d:
	/* 0x471d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_471f:
	/* 0x471f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_4723:
	/* 0x4723: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_472d:
	/* 0x472d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4730:
	/* 0x4730: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4735:
	/* 0x4735: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_4739:
	/* 0x4739: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_473b:
	/* 0x473b: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_473f:
	/* 0x473f: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_4744:
	/* 0x4744: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4748:
	/* 0x4748: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_474c:
	/* 0x474c: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4751:
	/* 0x4751: je     4764 <tail_handle_ipv6_from_netdev+0x4764> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4764;
	}
x86_l_4753:
	/* 0x4753: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_475a:
	/* 0x475a: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_475c:
	/* 0x475c: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_475f:
	/* 0x475f: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4762:
	/* 0x4762: jmp    4769 <tail_handle_ipv6_from_netdev+0x4769> */
	goto x86_l_4769;
x86_l_4764:
	/* 0x4764: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_4769:
	/* 0x4769: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_476b:
	/* 0x476b: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_476e:
	/* 0x476e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_4770:
	/* 0x4770: jb     477b <tail_handle_ipv6_from_netdev+0x477b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_477b;
	}
x86_l_4772:
	/* 0x4772: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_4775:
	/* 0x4775: je     31c6 <tail_handle_ipv6_from_netdev+0x31c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12742ULL;
	}
x86_l_477b:
	/* 0x477b: mov    BYTE PTR [r15+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_477f:
	/* 0x477f: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4783:
	/* 0x4783: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4786:
	/* 0x4786: jmp    31c6 <tail_handle_ipv6_from_netdev+0x31c6> */
	return 12742ULL;
x86_l_478b:
	/* 0x478b: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_4791:
	/* 0x4791: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_4795:
	/* 0x4795: jne    47cf <tail_handle_ipv6_from_netdev+0x47cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_47cf;
	}
x86_l_4797:
	/* 0x4797: mov    ecx,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_32);
x86_l_4799:
	/* 0x4799: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_479b:
	/* 0x479b: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_479e:
	/* 0x479e: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_47a1:
	/* 0x47a1: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_47a3:
	/* 0x47a3: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_47a8:
	/* 0x47a8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_47aa:
	/* 0x47aa: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_47af:
	/* 0x47af: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_47b5:
	/* 0x47b5: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_47b9:
	/* 0x47b9: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47be:
	/* 0x47be: je     47cf <tail_handle_ipv6_from_netdev+0x47cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47cf;
	}
x86_l_47c0:
	/* 0x47c0: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_47c7:
	/* 0x47c7: imul   r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_47cb:
	/* 0x47cb: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_47cf:
	/* 0x47cf: shr    ebx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_47d2:
	/* 0x47d2: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47d7:
	/* 0x47d7: je     47e8 <tail_handle_ipv6_from_netdev+0x47e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_47e8;
	}
x86_l_47d9:
	/* 0x47d9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_47de:
	/* 0x47de: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47e0:
	/* 0x47e0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_47e2:
	/* 0x47e2: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_47e6:
	/* 0x47e6: jmp    480b <tail_handle_ipv6_from_netdev+0x480b> */
	goto x86_l_480b;
x86_l_47e8:
	/* 0x47e8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_47ed:
	/* 0x47ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47ef:
	/* 0x47ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_47f1:
	/* 0x47f1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_47f5:
	/* 0x47f5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_47ff:
	/* 0x47ff: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4802:
	/* 0x4802: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4807:
	/* 0x4807: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_480b:
	/* 0x480b: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_480e:
	/* 0x480e: mov    DWORD PTR [r14+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4812:
	/* 0x4812: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_4817:
	/* 0x4817: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_481b:
	/* 0x481b: and    bl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_481e:
	/* 0x481e: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4823:
	/* 0x4823: je     4836 <tail_handle_ipv6_from_netdev+0x4836> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4836;
	}
x86_l_4825:
	/* 0x4825: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_482c:
	/* 0x482c: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_482e:
	/* 0x482e: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_4831:
	/* 0x4831: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4834:
	/* 0x4834: jmp    483b <tail_handle_ipv6_from_netdev+0x483b> */
	goto x86_l_483b;
x86_l_4836:
	/* 0x4836: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_483b:
	/* 0x483b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_483d:
	/* 0x483d: or     bl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_483f:
	/* 0x483f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_4841:
	/* 0x4841: jb     484b <tail_handle_ipv6_from_netdev+0x484b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_484b;
	}
x86_l_4843:
	/* 0x4843: cmp    cl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_8);
x86_l_4845:
	/* 0x4845: je     2912 <tail_handle_ipv6_from_netdev+0x2912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10514ULL;
	}
x86_l_484b:
	/* 0x484b: mov    BYTE PTR [r14+0x2a],bl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_484f:
	/* 0x484f: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4853:
	/* 0x4853: jmp    2909 <tail_handle_ipv6_from_netdev+0x2909> */
	return 10505ULL;
x86_l_4858:
	/* 0x4858: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_485d:
	/* 0x485d: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_4862:
	/* 0x4862: jne    4897 <tail_handle_ipv6_from_netdev+0x4897> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4897;
	}
x86_l_4864:
	/* 0x4864: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_4867:
	/* 0x4867: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4869:
	/* 0x4869: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_486c:
	/* 0x486c: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_486f:
	/* 0x486f: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4871:
	/* 0x4871: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4876:
	/* 0x4876: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4878:
	/* 0x4878: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_487d:
	/* 0x487d: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_4882:
	/* 0x4882: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_4885:
	/* 0x4885: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4888:
	/* 0x4888: je     4897 <tail_handle_ipv6_from_netdev+0x4897> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4897;
	}
x86_l_488a:
	/* 0x488a: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4891:
	/* 0x4891: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_4894:
	/* 0x4894: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4897:
	/* 0x4897: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_489b:
	/* 0x489b: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_489e:
	/* 0x489e: je     48af <tail_handle_ipv6_from_netdev+0x48af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48af;
	}
x86_l_48a0:
	/* 0x48a0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_48a5:
	/* 0x48a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48a7:
	/* 0x48a7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_48a9:
	/* 0x48a9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_48ad:
	/* 0x48ad: jmp    48d2 <tail_handle_ipv6_from_netdev+0x48d2> */
	goto x86_l_48d2;
x86_l_48af:
	/* 0x48af: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_48b4:
	/* 0x48b4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48b6:
	/* 0x48b6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_48b8:
	/* 0x48b8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_48bc:
	/* 0x48bc: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_48c6:
	/* 0x48c6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_48c9:
	/* 0x48c9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_48ce:
	/* 0x48ce: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_48d2:
	/* 0x48d2: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_48d4:
	/* 0x48d4: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48d8:
	/* 0x48d8: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_48dd:
	/* 0x48dd: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_48e1:
	/* 0x48e1: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_48e5:
	/* 0x48e5: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48e8:
	/* 0x48e8: je     48fb <tail_handle_ipv6_from_netdev+0x48fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_48fb;
	}
x86_l_48ea:
	/* 0x48ea: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_48f1:
	/* 0x48f1: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_48f3:
	/* 0x48f3: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_48f6:
	/* 0x48f6: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_48f9:
	/* 0x48f9: jmp    4900 <tail_handle_ipv6_from_netdev+0x4900> */
	goto x86_l_4900;
x86_l_48fb:
	/* 0x48fb: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_4900:
	/* 0x4900: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4902:
	/* 0x4902: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_4905:
	/* 0x4905: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_4907:
	/* 0x4907: jb     4910 <tail_handle_ipv6_from_netdev+0x4910> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4910;
	}
x86_l_4909:
	/* 0x4909: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_490b:
	/* 0x490b: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_490e:
	/* 0x490e: je     4921 <tail_handle_ipv6_from_netdev+0x4921> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4921;
	}
x86_l_4910:
	/* 0x4910: mov    BYTE PTR [r15+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_4914:
	/* 0x4914: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4918:
	/* 0x4918: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_491f:
	/* 0x491f: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4921:
	/* 0x4921: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4926:
	/* 0x4926: mov    DWORD PTR [rax+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4929:
	/* 0x4929: jmp    454f <tail_handle_ipv6_from_netdev+0x454f> */
	goto x86_l_454f;
x86_l_492e:
	/* 0x492e: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_4934:
	/* 0x4934: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_4938:
	/* 0x4938: jne    4972 <tail_handle_ipv6_from_netdev+0x4972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4972;
	}
x86_l_493a:
	/* 0x493a: mov    ecx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_493e:
	/* 0x493e: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4940:
	/* 0x4940: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_4943:
	/* 0x4943: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_4946:
	/* 0x4946: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4948:
	/* 0x4948: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_494d:
	/* 0x494d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_494f:
	/* 0x494f: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_4954:
	/* 0x4954: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_495a:
	/* 0x495a: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_495e:
	/* 0x495e: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4961:
	/* 0x4961: je     4972 <tail_handle_ipv6_from_netdev+0x4972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4972;
	}
x86_l_4963:
	/* 0x4963: mov    rax,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_496a:
	/* 0x496a: imul   r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_496e:
	/* 0x496e: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4972:
	/* 0x4972: shr    DWORD PTR [rsp+0x60],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 412316860424ULL);
x86_l_4977:
	/* 0x4977: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_497a:
	/* 0x497a: je     498b <tail_handle_ipv6_from_netdev+0x498b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_498b;
	}
x86_l_497c:
	/* 0x497c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_4981:
	/* 0x4981: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4983:
	/* 0x4983: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4985:
	/* 0x4985: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4989:
	/* 0x4989: jmp    49ae <tail_handle_ipv6_from_netdev+0x49ae> */
	goto x86_l_49ae;
x86_l_498b:
	/* 0x498b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4990:
	/* 0x4990: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4992:
	/* 0x4992: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4994:
	/* 0x4994: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_4998:
	/* 0x4998: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_49a2:
	/* 0x49a2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_49a5:
	/* 0x49a5: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_49aa:
	/* 0x49aa: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_49ae:
	/* 0x49ae: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_49b1:
	/* 0x49b1: mov    DWORD PTR [r14+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_49b5:
	/* 0x49b5: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_49ba:
	/* 0x49ba: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_49be:
	/* 0x49be: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49c2:
	/* 0x49c2: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_49c6:
	/* 0x49c6: mov    DWORD PTR [rsp+0x60],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49ca:
	/* 0x49ca: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49cd:
	/* 0x49cd: je     49e0 <tail_handle_ipv6_from_netdev+0x49e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 18912ULL;
	}
x86_l_49cf:
	/* 0x49cf: mov    rsi,QWORD PTR [rip+0x1bdbe] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
	return 18902ULL;
}

static __noinline __u64 cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_11(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 18902ULL: goto x86_l_49d6;
	case 18904ULL: goto x86_l_49d8;
	case 18907ULL: goto x86_l_49db;
	case 18910ULL: goto x86_l_49de;
	case 18912ULL: goto x86_l_49e0;
	case 18917ULL: goto x86_l_49e5;
	case 18919ULL: goto x86_l_49e7;
	case 18923ULL: goto x86_l_49eb;
	case 18925ULL: goto x86_l_49ed;
	case 18929ULL: goto x86_l_49f1;
	case 18931ULL: goto x86_l_49f3;
	case 18933ULL: goto x86_l_49f5;
	case 18937ULL: goto x86_l_49f9;
	case 18943ULL: goto x86_l_49ff;
	case 18947ULL: goto x86_l_4a03;
	case 18951ULL: goto x86_l_4a07;
	case 18955ULL: goto x86_l_4a0b;
	case 18960ULL: goto x86_l_4a10;
	case 18963ULL: goto x86_l_4a13;
	case 18966ULL: goto x86_l_4a16;
	case 18971ULL: goto x86_l_4a1b;
	case 18974ULL: goto x86_l_4a1e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_49d6:
	/* 0x49d6: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49d8:
	/* 0x49d8: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_49db:
	/* 0x49db: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_49de:
	/* 0x49de: jmp    49e5 <tail_handle_ipv6_from_netdev+0x49e5> */
	goto x86_l_49e5;
x86_l_49e0:
	/* 0x49e0: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_49e5:
	/* 0x49e5: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_49e7:
	/* 0x49e7: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49eb:
	/* 0x49eb: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_49ed:
	/* 0x49ed: mov    DWORD PTR [rsp+0x60],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49f1:
	/* 0x49f1: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_49f3:
	/* 0x49f3: jb     49ff <tail_handle_ipv6_from_netdev+0x49ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_49ff;
	}
x86_l_49f5:
	/* 0x49f5: cmp    cl,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_49f9:
	/* 0x49f9: je     3e3d <tail_handle_ipv6_from_netdev+0x3e3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 15933ULL;
	}
x86_l_49ff:
	/* 0x49ff: mov    ecx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4a03:
	/* 0x4a03: mov    BYTE PTR [r14+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_4a07:
	/* 0x4a07: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a0b:
	/* 0x4a0b: jmp    3e34 <tail_handle_ipv6_from_netdev+0x3e34> */
	return 15924ULL;
x86_l_4a10:
	/* 0x4a10: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a13:
	/* 0x4a13: mov    rbp,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_4a16:
	/* 0x4a16: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a1b:
	/* 0x4a1b: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_4a1e:
	/* 0x4a1e: jmp    3c61 <tail_handle_ipv6_from_netdev+0x3c61> */
	return 15457ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 16984U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1748ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1752ULL && __x86_pc <= 3609ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3614ULL && __x86_pc <= 5536ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5541ULL && __x86_pc <= 7349ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7351ULL && __x86_pc <= 9006ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9009ULL && __x86_pc <= 10823ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10828ULL && __x86_pc <= 12425ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12428ULL && __x86_pc <= 14092ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 14101ULL && __x86_pc <= 15870ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_8(__x86_state, __x86_pc);
		else if (__x86_pc >= 15873ULL && __x86_pc <= 17475ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_9(__x86_state, __x86_pc);
		else if (__x86_pc >= 17477ULL && __x86_pc <= 18895ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_10(__x86_state, __x86_pc);
		else if (__x86_pc >= 18902ULL && __x86_pc <= 18974ULL)
			__x86_pc = cilium_bpf_host_tail_handle_ipv6_from_netdev_x86_chunk_11(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

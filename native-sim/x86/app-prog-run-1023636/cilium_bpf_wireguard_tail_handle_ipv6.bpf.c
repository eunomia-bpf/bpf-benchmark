extern char __config_cilium_host_ifindex;
extern char __config_cilium_host_mac;
extern char __config_cilium_net_ifindex;
extern char __config_cluster_id_bits;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_identity_mark;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_netkit;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_enable_tproxy;
extern char __config_interface_ifindex;
extern char __config_interface_mac;
extern char __config_kernel_hz;
extern char __config_proxy_redirect_via_cilium_net;
extern char __config_trace_payload_len;
extern char cilium_call_policy;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_affinity;
extern char cilium_lb6_backends_v3;
extern char cilium_lb6_services_v2;
extern char cilium_lb6_source_range;
extern char cilium_lb_affinity_match;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_nodeport_neigh6;
extern char cilium_throttle;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_0(
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
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 47ULL: goto x86_l_2f;
	case 50ULL: goto x86_l_32;
	case 53ULL: goto x86_l_35;
	case 55ULL: goto x86_l_37;
	case 60ULL: goto x86_l_3c;
	case 62ULL: goto x86_l_3e;
	case 64ULL: goto x86_l_40;
	case 67ULL: goto x86_l_43;
	case 70ULL: goto x86_l_46;
	case 74ULL: goto x86_l_4a;
	case 78ULL: goto x86_l_4e;
	case 82ULL: goto x86_l_52;
	case 89ULL: goto x86_l_59;
	case 91ULL: goto x86_l_5b;
	case 94ULL: goto x86_l_5e;
	case 104ULL: goto x86_l_68;
	case 108ULL: goto x86_l_6c;
	case 111ULL: goto x86_l_6f;
	case 121ULL: goto x86_l_79;
	case 126ULL: goto x86_l_7e;
	case 130ULL: goto x86_l_82;
	case 137ULL: goto x86_l_89;
	case 142ULL: goto x86_l_8e;
	case 147ULL: goto x86_l_93;
	case 149ULL: goto x86_l_95;
	case 152ULL: goto x86_l_98;
	case 158ULL: goto x86_l_9e;
	case 161ULL: goto x86_l_a1;
	case 165ULL: goto x86_l_a5;
	case 170ULL: goto x86_l_aa;
	case 177ULL: goto x86_l_b1;
	case 180ULL: goto x86_l_b4;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 193ULL: goto x86_l_c1;
	case 196ULL: goto x86_l_c4;
	case 199ULL: goto x86_l_c7;
	case 207ULL: goto x86_l_cf;
	case 213ULL: goto x86_l_d5;
	case 218ULL: goto x86_l_da;
	case 230ULL: goto x86_l_e6;
	case 242ULL: goto x86_l_f2;
	case 254ULL: goto x86_l_fe;
	case 263ULL: goto x86_l_107;
	case 272ULL: goto x86_l_110;
	case 284ULL: goto x86_l_11c;
	case 296ULL: goto x86_l_128;
	case 308ULL: goto x86_l_134;
	case 313ULL: goto x86_l_139;
	case 315ULL: goto x86_l_13b;
	case 323ULL: goto x86_l_143;
	case 328ULL: goto x86_l_148;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 343ULL: goto x86_l_157;
	case 353ULL: goto x86_l_161;
	case 357ULL: goto x86_l_165;
	case 363ULL: goto x86_l_16b;
	case 368ULL: goto x86_l_170;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 381ULL: goto x86_l_17d;
	case 386ULL: goto x86_l_182;
	case 388ULL: goto x86_l_184;
	case 390ULL: goto x86_l_186;
	case 396ULL: goto x86_l_18c;
	case 401ULL: goto x86_l_191;
	case 405ULL: goto x86_l_195;
	case 411ULL: goto x86_l_19b;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 425ULL: goto x86_l_1a9;
	case 431ULL: goto x86_l_1af;
	case 436ULL: goto x86_l_1b4;
	case 443ULL: goto x86_l_1bb;
	case 448ULL: goto x86_l_1c0;
	case 457ULL: goto x86_l_1c9;
	case 462ULL: goto x86_l_1ce;
	case 469ULL: goto x86_l_1d5;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 484ULL: goto x86_l_1e4;
	case 486ULL: goto x86_l_1e6;
	case 488ULL: goto x86_l_1e8;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 503ULL: goto x86_l_1f7;
	case 508ULL: goto x86_l_1fc;
	case 510ULL: goto x86_l_1fe;
	case 515ULL: goto x86_l_203;
	case 517ULL: goto x86_l_205;
	case 524ULL: goto x86_l_20c;
	case 526ULL: goto x86_l_20e;
	case 527ULL: goto x86_l_20f;
	case 532ULL: goto x86_l_214;
	case 537ULL: goto x86_l_219;
	case 542ULL: goto x86_l_21e;
	case 546ULL: goto x86_l_222;
	case 552ULL: goto x86_l_228;
	case 557ULL: goto x86_l_22d;
	case 567ULL: goto x86_l_237;
	case 571ULL: goto x86_l_23b;
	case 577ULL: goto x86_l_241;
	case 582ULL: goto x86_l_246;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 595ULL: goto x86_l_253;
	case 600ULL: goto x86_l_258;
	case 602ULL: goto x86_l_25a;
	case 604ULL: goto x86_l_25c;
	case 610ULL: goto x86_l_262;
	case 616ULL: goto x86_l_268;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 626ULL: goto x86_l_272;
	case 628ULL: goto x86_l_274;
	case 632ULL: goto x86_l_278;
	case 638ULL: goto x86_l_27e;
	case 644ULL: goto x86_l_284;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 659ULL: goto x86_l_293;
	case 665ULL: goto x86_l_299;
	case 671ULL: goto x86_l_29f;
	case 675ULL: goto x86_l_2a3;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 688ULL: goto x86_l_2b0;
	case 698ULL: goto x86_l_2ba;
	case 702ULL: goto x86_l_2be;
	case 708ULL: goto x86_l_2c4;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 722ULL: goto x86_l_2d2;
	case 725ULL: goto x86_l_2d5;
	case 730ULL: goto x86_l_2da;
	case 735ULL: goto x86_l_2df;
	case 737ULL: goto x86_l_2e1;
	case 739ULL: goto x86_l_2e3;
	case 745ULL: goto x86_l_2e9;
	case 750ULL: goto x86_l_2ee;
	case 754ULL: goto x86_l_2f2;
	case 760ULL: goto x86_l_2f8;
	case 764ULL: goto x86_l_2fc;
	case 769ULL: goto x86_l_301;
	case 775ULL: goto x86_l_307;
	case 779ULL: goto x86_l_30b;
	case 785ULL: goto x86_l_311;
	case 790ULL: goto x86_l_316;
	case 793ULL: goto x86_l_319;
	case 798ULL: goto x86_l_31e;
	case 803ULL: goto x86_l_323;
	case 810ULL: goto x86_l_32a;
	case 814ULL: goto x86_l_32e;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 822ULL: goto x86_l_336;
	case 824ULL: goto x86_l_338;
	case 828ULL: goto x86_l_33c;
	case 834ULL: goto x86_l_342;
	case 839ULL: goto x86_l_347;
	case 844ULL: goto x86_l_34c;
	case 846ULL: goto x86_l_34e;
	case 851ULL: goto x86_l_353;
	case 856ULL: goto x86_l_358;
	case 860ULL: goto x86_l_35c;
	case 866ULL: goto x86_l_362;
	case 871ULL: goto x86_l_367;
	case 876ULL: goto x86_l_36c;
	case 881ULL: goto x86_l_371;
	case 884ULL: goto x86_l_374;
	case 890ULL: goto x86_l_37a;
	case 899ULL: goto x86_l_383;
	case 904ULL: goto x86_l_388;
	case 909ULL: goto x86_l_38d;
	case 912ULL: goto x86_l_390;
	case 917ULL: goto x86_l_395;
	case 922ULL: goto x86_l_39a;
	case 924ULL: goto x86_l_39c;
	case 926ULL: goto x86_l_39e;
	case 932ULL: goto x86_l_3a4;
	case 936ULL: goto x86_l_3a8;
	case 941ULL: goto x86_l_3ad;
	case 945ULL: goto x86_l_3b1;
	case 948ULL: goto x86_l_3b4;
	case 953ULL: goto x86_l_3b9;
	case 963ULL: goto x86_l_3c3;
	case 966ULL: goto x86_l_3c6;
	case 971ULL: goto x86_l_3cb;
	case 975ULL: goto x86_l_3cf;
	case 985ULL: goto x86_l_3d9;
	case 988ULL: goto x86_l_3dc;
	case 993ULL: goto x86_l_3e1;
	case 997ULL: goto x86_l_3e5;
	case 1000ULL: goto x86_l_3e8;
	case 1003ULL: goto x86_l_3eb;
	case 1007ULL: goto x86_l_3ef;
	case 1010ULL: goto x86_l_3f2;
	case 1014ULL: goto x86_l_3f6;
	case 1020ULL: goto x86_l_3fc;
	case 1023ULL: goto x86_l_3ff;
	case 1027ULL: goto x86_l_403;
	case 1029ULL: goto x86_l_405;
	case 1036ULL: goto x86_l_40c;
	case 1039ULL: goto x86_l_40f;
	case 1044ULL: goto x86_l_414;
	case 1049ULL: goto x86_l_419;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1064ULL: goto x86_l_428;
	case 1066ULL: goto x86_l_42a;
	case 1072ULL: goto x86_l_430;
	case 1078ULL: goto x86_l_436;
	case 1082ULL: goto x86_l_43a;
	case 1084ULL: goto x86_l_43c;
	case 1088ULL: goto x86_l_440;
	case 1093ULL: goto x86_l_445;
	case 1099ULL: goto x86_l_44b;
	case 1102ULL: goto x86_l_44e;
	case 1106ULL: goto x86_l_452;
	case 1116ULL: goto x86_l_45c;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1131ULL: goto x86_l_46b;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1146ULL: goto x86_l_47a;
	case 1151ULL: goto x86_l_47f;
	case 1153ULL: goto x86_l_481;
	case 1158ULL: goto x86_l_486;
	case 1163ULL: goto x86_l_48b;
	case 1166ULL: goto x86_l_48e;
	case 1176ULL: goto x86_l_498;
	case 1184ULL: goto x86_l_4a0;
	case 1189ULL: goto x86_l_4a5;
	case 1196ULL: goto x86_l_4ac;
	case 1199ULL: goto x86_l_4af;
	case 1201ULL: goto x86_l_4b1;
	case 1206ULL: goto x86_l_4b6;
	case 1210ULL: goto x86_l_4ba;
	case 1216ULL: goto x86_l_4c0;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1230ULL: goto x86_l_4ce;
	case 1236ULL: goto x86_l_4d4;
	case 1241ULL: goto x86_l_4d9;
	case 1246ULL: goto x86_l_4de;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1256ULL: goto x86_l_4e8;
	case 1258ULL: goto x86_l_4ea;
	case 1264ULL: goto x86_l_4f0;
	case 1269ULL: goto x86_l_4f5;
	case 1274ULL: goto x86_l_4fa;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1291ULL: goto x86_l_50b;
	case 1297ULL: goto x86_l_511;
	case 1302ULL: goto x86_l_516;
	case 1307ULL: goto x86_l_51b;
	case 1317ULL: goto x86_l_525;
	case 1320ULL: goto x86_l_528;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1342ULL: goto x86_l_53e;
	case 1347ULL: goto x86_l_543;
	case 1349ULL: goto x86_l_545;
	case 1351ULL: goto x86_l_547;
	case 1357ULL: goto x86_l_54d;
	case 1361ULL: goto x86_l_551;
	case 1366ULL: goto x86_l_556;
	case 1370ULL: goto x86_l_55a;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1388ULL: goto x86_l_56c;
	case 1391ULL: goto x86_l_56f;
	case 1396ULL: goto x86_l_574;
	case 1400ULL: goto x86_l_578;
	case 1410ULL: goto x86_l_582;
	case 1413ULL: goto x86_l_585;
	case 1418ULL: goto x86_l_58a;
	case 1422ULL: goto x86_l_58e;
	case 1427ULL: goto x86_l_593;
	case 1430ULL: goto x86_l_596;
	case 1434ULL: goto x86_l_59a;
	case 1436ULL: goto x86_l_59c;
	case 1440ULL: goto x86_l_5a0;
	case 1446ULL: goto x86_l_5a6;
	case 1449ULL: goto x86_l_5a9;
	case 1453ULL: goto x86_l_5ad;
	case 1459ULL: goto x86_l_5b3;
	case 1462ULL: goto x86_l_5b6;
	case 1467ULL: goto x86_l_5bb;
	case 1472ULL: goto x86_l_5c0;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1491ULL: goto x86_l_5d3;
	case 1496ULL: goto x86_l_5d8;
	case 1500ULL: goto x86_l_5dc;
	case 1506ULL: goto x86_l_5e2;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1521ULL: goto x86_l_5f1;
	case 1524ULL: goto x86_l_5f4;
	case 1528ULL: goto x86_l_5f8;
	case 1538ULL: goto x86_l_602;
	case 1544ULL: goto x86_l_608;
	case 1549ULL: goto x86_l_60d;
	case 1557ULL: goto x86_l_615;
	case 1564ULL: goto x86_l_61c;
	case 1569ULL: goto x86_l_621;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1593ULL: goto x86_l_639;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1607ULL: goto x86_l_647;
	case 1612ULL: goto x86_l_64c;
	case 1617ULL: goto x86_l_651;
	case 1620ULL: goto x86_l_654;
	case 1623ULL: goto x86_l_657;
	case 1629ULL: goto x86_l_65d;
	case 1631ULL: goto x86_l_65f;
	case 1641ULL: goto x86_l_669;
	case 1645ULL: goto x86_l_66d;
	case 1651ULL: goto x86_l_673;
	case 1655ULL: goto x86_l_677;
	case 1659ULL: goto x86_l_67b;
	case 1662ULL: goto x86_l_67e;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1675ULL: goto x86_l_68b;
	case 1678ULL: goto x86_l_68e;
	case 1683ULL: goto x86_l_693;
	case 1685ULL: goto x86_l_695;
	case 1687ULL: goto x86_l_697;
	case 1689ULL: goto x86_l_699;
	case 1695ULL: goto x86_l_69f;
	case 1699ULL: goto x86_l_6a3;
	case 1702ULL: goto x86_l_6a6;
	case 1708ULL: goto x86_l_6ac;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1720ULL: goto x86_l_6b8;
	case 1723ULL: goto x86_l_6bb;
	case 1729ULL: goto x86_l_6c1;
	case 1734ULL: goto x86_l_6c6;
	case 1737ULL: goto x86_l_6c9;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1757ULL: goto x86_l_6dd;
	case 1760ULL: goto x86_l_6e0;
	case 1767ULL: goto x86_l_6e7;
	case 1772ULL: goto x86_l_6ec;
	case 1779ULL: goto x86_l_6f3;
	case 1784ULL: goto x86_l_6f8;
	case 1787ULL: goto x86_l_6fb;
	case 1797ULL: goto x86_l_705;
	case 1799ULL: goto x86_l_707;
	case 1805ULL: goto x86_l_70d;
	case 1812ULL: goto x86_l_714;
	case 1822ULL: goto x86_l_71e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 232ULL);
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
	/* 0x18: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_1d:
	/* 0x1d: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_22:
	/* 0x22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24:
	/* 0x24: mov    r13d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_28:
	/* 0x28: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b:
	/* 0x2b: lea    rcx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2f:
	/* 0x2f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32:
	/* 0x32: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_35:
	/* 0x35: jbe    aa <tail_handle_ipv6+0xaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_aa;
	}
x86_l_37:
	/* 0x37: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_3c:
	/* 0x3c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3e:
	/* 0x3e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_40:
	/* 0x40: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_43:
	/* 0x43: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_46:
	/* 0x46: shl    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_4a:
	/* 0x4a: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4e:
	/* 0x4e: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_52:
	/* 0x52: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_59:
	/* 0x59: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_5b:
	/* 0x5b: mov    DWORD PTR [rbx+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5e:
	/* 0x5e: movabs rcx,0x77070200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 33503227399897088ULL);
x86_l_68:
	/* 0x68: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6c:
	/* 0x6c: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f:
	/* 0x6f: movabs rcx,0x700770100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 30072570112ULL);
x86_l_79:
	/* 0x79: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7e:
	/* 0x7e: mov    BYTE PTR [rsp+0x70],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_82:
	/* 0x82: mov    rdi,QWORD PTR [rip+0xec67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_89:
	/* 0x89: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8e:
	/* 0x8e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_93:
	/* 0x93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95:
	/* 0x95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98:
	/* 0x98: je     1c0 <tail_handle_ipv6+0x1c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c0;
	}
x86_l_9e:
	/* 0x9e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a1:
	/* 0xa1: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a5:
	/* 0xa5: jmp    1e8 <tail_handle_ipv6+0x1e8> */
	goto x86_l_1e8;
x86_l_aa:
	/* 0xaa: mov    rcx,QWORD PTR [rip+0xec67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_b1:
	/* 0xb1: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4:
	/* 0xb4: je     214 <tail_handle_ipv6+0x214> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214;
	}
x86_l_ba:
	/* 0xba: mov    eax,DWORD PTR [rbx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_bd:
	/* 0xbd: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c1:
	/* 0xc1: and    eax,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_c4:
	/* 0xc4: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c7:
	/* 0xc7: test   DWORD PTR [rsp+0x10],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476740ULL);
x86_l_cf:
	/* 0xcf: jne    2c2e <tail_handle_ipv6+0x2c2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11310ULL;
	}
x86_l_d5:
	/* 0xd5: mov    DWORD PTR [rsp+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_da:
	/* 0xda: mov    QWORD PTR [rsp+0x8e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_e6:
	/* 0xe6: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_f2:
	/* 0xf2: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_fe:
	/* 0xfe: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_107:
	/* 0x107: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_110:
	/* 0x110: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_11c:
	/* 0x11c: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_134:
	/* 0x134: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_139:
	/* 0x139: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b:
	/* 0x13b: mov    BYTE PTR [rsp+0x94],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_143:
	/* 0x143: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_148:
	/* 0x148: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_14c:
	/* 0x14c: ja     47f <tail_handle_ipv6+0x47f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_47f;
	}
x86_l_152:
	/* 0x152: mov    edx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967140ULL);
x86_l_157:
	/* 0x157: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_161:
	/* 0x161: bt     r12,r15 */
	X86_SIM_L_EXEC_BT(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_165:
	/* 0x165: jae    353 <tail_handle_ipv6+0x353> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_353;
	}
x86_l_16b:
	/* 0x16b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_170:
	/* 0x170: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_175:
	/* 0x175: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_178:
	/* 0x178: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_17d:
	/* 0x17d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_182:
	/* 0x182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184:
	/* 0x184: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_186:
	/* 0x186: js     621 <tail_handle_ipv6+0x621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_621;
	}
x86_l_18c:
	/* 0x18c: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_191:
	/* 0x191: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_195:
	/* 0x195: jle    31e <tail_handle_ipv6+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_31e;
	}
x86_l_19b:
	/* 0x19b: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_19f:
	/* 0x19f: je     31e <tail_handle_ipv6+0x31e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_31e;
	}
x86_l_1a5:
	/* 0x1a5: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_1a9:
	/* 0x1a9: jne    371 <tail_handle_ipv6+0x371> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_371;
	}
x86_l_1af:
	/* 0x1af: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_1b4:
	/* 0x1b4: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1bb:
	/* 0x1bb: jmp    34c <tail_handle_ipv6+0x34c> */
	goto x86_l_34c;
x86_l_1c0:
	/* 0x1c0: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1c9:
	/* 0x1c9: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ce:
	/* 0x1ce: mov    rdi,QWORD PTR [rip+0xec67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1d5:
	/* 0x1d5: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1da:
	/* 0x1da: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df:
	/* 0x1df: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e4:
	/* 0x1e4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e6:
	/* 0x1e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8:
	/* 0x1e8: mov    rsi,QWORD PTR [rip+0xec67] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1ef:
	/* 0x1ef: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f4:
	/* 0x1f4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f7:
	/* 0x1f7: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1fc:
	/* 0x1fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fe:
	/* 0x1fe: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_203:
	/* 0x203: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_205:
	/* 0x205: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_20c:
	/* 0x20c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_20e:
	/* 0x20e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_20f:
	/* 0x20f: jmp    372c <tail_handle_ipv6+0x372c> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_214:
	/* 0x214: mov    DWORD PTR [rsp+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_219:
	/* 0x219: movzx  r15d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_21e:
	/* 0x21e: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_222:
	/* 0x222: ja     8fb <tail_handle_ipv6+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2299ULL;
	}
x86_l_228:
	/* 0x228: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_22d:
	/* 0x22d: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_237:
	/* 0x237: bt     rax,r15 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_23b:
	/* 0x23b: jae    338 <tail_handle_ipv6+0x338> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_338;
	}
x86_l_241:
	/* 0x241: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_246:
	/* 0x246: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_24b:
	/* 0x24b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24e:
	/* 0x24e: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_253:
	/* 0x253: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_258:
	/* 0x258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a:
	/* 0x25a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c:
	/* 0x25c: js     6ce <tail_handle_ipv6+0x6ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_6ce;
	}
x86_l_262:
	/* 0x262: movzx  r14d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_268:
	/* 0x268: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_26c:
	/* 0x26c: jle    28a <tail_handle_ipv6+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_28a;
	}
x86_l_26e:
	/* 0x26e: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_272:
	/* 0x272: je     28a <tail_handle_ipv6+0x28a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28a;
	}
x86_l_274:
	/* 0x274: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_278:
	/* 0x278: jne    367 <tail_handle_ipv6+0x367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_367;
	}
x86_l_27e:
	/* 0x27e: movzx  r15d,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_284:
	/* 0x284: shl    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_288:
	/* 0x288: jmp    2a3 <tail_handle_ipv6+0x2a3> */
	goto x86_l_2a3;
x86_l_28a:
	/* 0x28a: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_28f:
	/* 0x28f: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_293:
	/* 0x293: je     4d4 <tail_handle_ipv6+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d4;
	}
x86_l_299:
	/* 0x299: movzx  r15d,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_29f:
	/* 0x29f: shl    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2a3:
	/* 0x2a3: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_2a7:
	/* 0x2a7: ja     8fb <tail_handle_ipv6+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2299ULL;
	}
x86_l_2ad:
	/* 0x2ad: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_2b0:
	/* 0x2b0: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2ba:
	/* 0x2ba: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2be:
	/* 0x2be: jae    4b6 <tail_handle_ipv6+0x4b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_4b6;
	}
x86_l_2c4:
	/* 0x2c4: lea    esi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c8:
	/* 0x2c8: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2cd:
	/* 0x2cd: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2d2:
	/* 0x2d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2d5:
	/* 0x2d5: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2da:
	/* 0x2da: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2df:
	/* 0x2df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e1:
	/* 0x2e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e3:
	/* 0x2e3: js     6ce <tail_handle_ipv6+0x6ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_6ce;
	}
x86_l_2e9:
	/* 0x2e9: movzx  edi,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2ee:
	/* 0x2ee: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_2f2:
	/* 0x2f2: jle    4c5 <tail_handle_ipv6+0x4c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_4c5;
	}
x86_l_2f8:
	/* 0x2f8: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_2fc:
	/* 0x2fc: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_301:
	/* 0x301: je     4d4 <tail_handle_ipv6+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d4;
	}
x86_l_307:
	/* 0x307: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_30b:
	/* 0x30b: jne    4ca <tail_handle_ipv6+0x4ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4ca;
	}
x86_l_311:
	/* 0x311: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_316:
	/* 0x316: shl    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_319:
	/* 0x319: jmp    654 <tail_handle_ipv6+0x654> */
	goto x86_l_654;
x86_l_31e:
	/* 0x31e: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_323:
	/* 0x323: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_32a:
	/* 0x32a: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_32e:
	/* 0x32e: jne    34c <tail_handle_ipv6+0x34c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34c;
	}
x86_l_330:
	/* 0x330: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_333:
	/* 0x333: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_336:
	/* 0x336: jmp    37a <tail_handle_ipv6+0x37a> */
	goto x86_l_37a;
x86_l_338:
	/* 0x338: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_33c:
	/* 0x33c: jne    8fb <tail_handle_ipv6+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2299ULL;
	}
x86_l_342:
	/* 0x342: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_347:
	/* 0x347: jmp    3c <tail_handle_ipv6+0x3c> */
	goto x86_l_3c;
x86_l_34c:
	/* 0x34c: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34e:
	/* 0x34e: jmp    3eb <tail_handle_ipv6+0x3eb> */
	goto x86_l_3eb;
x86_l_353:
	/* 0x353: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_358:
	/* 0x358: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_35c:
	/* 0x35c: je     626 <tail_handle_ipv6+0x626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_626;
	}
x86_l_362:
	/* 0x362: jmp    90f <tail_handle_ipv6+0x90f> */
	return 2319ULL;
x86_l_367:
	/* 0x367: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_36c:
	/* 0x36c: jmp    4d4 <tail_handle_ipv6+0x4d4> */
	goto x86_l_4d4;
x86_l_371:
	/* 0x371: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_374:
	/* 0x374: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_37a:
	/* 0x37a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_383:
	/* 0x383: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_388:
	/* 0x388: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_38d:
	/* 0x38d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_390:
	/* 0x390: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_395:
	/* 0x395: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_39a:
	/* 0x39a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c:
	/* 0x39c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_39e:
	/* 0x39e: js     185a <tail_handle_ipv6+0x185a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6234ULL;
	}
x86_l_3a4:
	/* 0x3a4: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3a8:
	/* 0x3a8: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_3ad:
	/* 0x3ad: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_3b1:
	/* 0x3b1: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b4:
	/* 0x3b4: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_3b9:
	/* 0x3b9: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_3c3:
	/* 0x3c3: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3c6:
	/* 0x3c6: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_3cb:
	/* 0x3cb: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_3cf:
	/* 0x3cf: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_3d9:
	/* 0x3d9: or     rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3dc:
	/* 0x3dc: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_3e1:
	/* 0x3e1: cmove  rdi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_3e5:
	/* 0x3e5: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3e8:
	/* 0x3e8: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_3eb:
	/* 0x3eb: movzx  r14d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3ef:
	/* 0x3ef: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_3f2:
	/* 0x3f2: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_3f6:
	/* 0x3f6: ja     6dd <tail_handle_ipv6+0x6dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_6dd;
	}
x86_l_3fc:
	/* 0x3fc: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_3ff:
	/* 0x3ff: bt     r12,rax */
	X86_SIM_L_EXEC_BT(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_403:
	/* 0x403: jae    477 <tail_handle_ipv6+0x477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_477;
	}
x86_l_405:
	/* 0x405: mov    BYTE PTR [rsp+0x98],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_40c:
	/* 0x40c: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_40f:
	/* 0x40f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_414:
	/* 0x414: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_419:
	/* 0x419: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_41c:
	/* 0x41c: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_421:
	/* 0x421: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_426:
	/* 0x426: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_428:
	/* 0x428: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42a:
	/* 0x42a: js     621 <tail_handle_ipv6+0x621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_621;
	}
x86_l_430:
	/* 0x430: movzx  r15d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_436:
	/* 0x436: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_43a:
	/* 0x43a: jle    486 <tail_handle_ipv6+0x486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_486;
	}
x86_l_43c:
	/* 0x43c: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_440:
	/* 0x440: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_445:
	/* 0x445: je     516 <tail_handle_ipv6+0x516> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_516;
	}
x86_l_44b:
	/* 0x44b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_44e:
	/* 0x44e: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_452:
	/* 0x452: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_45c:
	/* 0x45c: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_464:
	/* 0x464: jne    4a0 <tail_handle_ipv6+0x4a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4a0;
	}
x86_l_466:
	/* 0x466: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_46b:
	/* 0x46b: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_472:
	/* 0x472: jmp    596 <tail_handle_ipv6+0x596> */
	goto x86_l_596;
x86_l_477:
	/* 0x477: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_47a:
	/* 0x47a: jmp    635 <tail_handle_ipv6+0x635> */
	goto x86_l_635;
x86_l_47f:
	/* 0x47f: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_481:
	/* 0x481: jmp    90f <tail_handle_ipv6+0x90f> */
	return 2319ULL;
x86_l_486:
	/* 0x486: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48b:
	/* 0x48b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_48e:
	/* 0x48e: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_498:
	/* 0x498: movzx  ecx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_4a0:
	/* 0x4a0: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_4a5:
	/* 0x4a5: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_4ac:
	/* 0x4ac: cmp    cl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 44ULL);
x86_l_4af:
	/* 0x4af: je     525 <tail_handle_ipv6+0x525> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_525;
	}
x86_l_4b1:
	/* 0x4b1: jmp    596 <tail_handle_ipv6+0x596> */
	goto x86_l_596;
x86_l_4b6:
	/* 0x4b6: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_4ba:
	/* 0x4ba: je     342 <tail_handle_ipv6+0x342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_342;
	}
x86_l_4c0:
	/* 0x4c0: jmp    8fb <tail_handle_ipv6+0x8fb> */
	return 2299ULL;
x86_l_4c5:
	/* 0x4c5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ca:
	/* 0x4ca: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_4ce:
	/* 0x4ce: jne    64c <tail_handle_ipv6+0x64c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_64c;
	}
x86_l_4d4:
	/* 0x4d4: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d9:
	/* 0x4d9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4de:
	/* 0x4de: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4e1:
	/* 0x4e1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e6:
	/* 0x4e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e8:
	/* 0x4e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ea:
	/* 0x4ea: js     6ce <tail_handle_ipv6+0x6ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_6ce;
	}
x86_l_4f0:
	/* 0x4f0: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_4f5:
	/* 0x4f5: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_4fa:
	/* 0x4fa: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_4ff:
	/* 0x4ff: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_504:
	/* 0x504: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_50b:
	/* 0x50b: jne    3c <tail_handle_ipv6+0x3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3c;
	}
x86_l_511:
	/* 0x511: jmp    ba <tail_handle_ipv6+0xba> */
	goto x86_l_ba;
x86_l_516:
	/* 0x516: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_51b:
	/* 0x51b: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_525:
	/* 0x525: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_528:
	/* 0x528: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_531:
	/* 0x531: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_536:
	/* 0x536: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_53b:
	/* 0x53b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_53e:
	/* 0x53e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_543:
	/* 0x543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_545:
	/* 0x545: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_547:
	/* 0x547: js     185a <tail_handle_ipv6+0x185a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6234ULL;
	}
x86_l_54d:
	/* 0x54d: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_551:
	/* 0x551: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_556:
	/* 0x556: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_55a:
	/* 0x55a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_55d:
	/* 0x55d: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_562:
	/* 0x562: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_56c:
	/* 0x56c: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_56f:
	/* 0x56f: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_574:
	/* 0x574: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_578:
	/* 0x578: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_582:
	/* 0x582: or     rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_585:
	/* 0x585: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_58a:
	/* 0x58a: cmove  rdi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_58e:
	/* 0x58e: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_593:
	/* 0x593: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_596:
	/* 0x596: movzx  r14d,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_59a:
	/* 0x59a: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_59c:
	/* 0x59c: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_5a0:
	/* 0x5a0: ja     85f <tail_handle_ipv6+0x85f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2143ULL;
	}
x86_l_5a6:
	/* 0x5a6: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_5a9:
	/* 0x5a9: bt     r12,rax */
	X86_SIM_L_EXEC_BT(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_5ad:
	/* 0x5ad: jae    635 <tail_handle_ipv6+0x635> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_635;
	}
x86_l_5b3:
	/* 0x5b3: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_5b6:
	/* 0x5b6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5bb:
	/* 0x5bb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5c0:
	/* 0x5c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5c3:
	/* 0x5c3: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c8:
	/* 0x5c8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5cd:
	/* 0x5cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cf:
	/* 0x5cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5d1:
	/* 0x5d1: js     621 <tail_handle_ipv6+0x621> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_621;
	}
x86_l_5d3:
	/* 0x5d3: movzx  edx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_5d8:
	/* 0x5d8: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_5dc:
	/* 0x5dc: jle    6ec <tail_handle_ipv6+0x6ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6ec;
	}
x86_l_5e2:
	/* 0x5e2: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_5e6:
	/* 0x5e6: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5eb:
	/* 0x5eb: je     707 <tail_handle_ipv6+0x707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_707;
	}
x86_l_5f1:
	/* 0x5f1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_5f4:
	/* 0x5f4: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_5f8:
	/* 0x5f8: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_602:
	/* 0x602: jne    720 <tail_handle_ipv6+0x720> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1824ULL;
	}
x86_l_608:
	/* 0x608: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_60d:
	/* 0x60d: lea    r14d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_615:
	/* 0x615: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_61c:
	/* 0x61c: jmp    7be <tail_handle_ipv6+0x7be> */
	return 1982ULL;
x86_l_621:
	/* 0x621: mov    edx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967162ULL);
x86_l_626:
	/* 0x626: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_629:
	/* 0x629: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_62b:
	/* 0x62b: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_630:
	/* 0x630: jmp    3c <tail_handle_ipv6+0x3c> */
	goto x86_l_3c;
x86_l_635:
	/* 0x635: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_639:
	/* 0x639: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_640:
	/* 0x640: mov    edx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967140ULL);
x86_l_645:
	/* 0x645: je     626 <tail_handle_ipv6+0x626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_626;
	}
x86_l_647:
	/* 0x647: jmp    90f <tail_handle_ipv6+0x90f> */
	return 2319ULL;
x86_l_64c:
	/* 0x64c: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_651:
	/* 0x651: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_654:
	/* 0x654: cmp    edi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 60ULL);
x86_l_657:
	/* 0x657: ja     8fb <tail_handle_ipv6+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2299ULL;
	}
x86_l_65d:
	/* 0x65d: mov    ecx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDI, X86_WIDTH_32);
x86_l_65f:
	/* 0x65f: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_669:
	/* 0x669: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_66d:
	/* 0x66d: jae    8f1 <tail_handle_ipv6+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2289ULL;
	}
x86_l_673:
	/* 0x673: mov    DWORD PTR [rsp+0x8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_677:
	/* 0x677: lea    esi,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_67b:
	/* 0x67b: add    esi,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_67e:
	/* 0x67e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_683:
	/* 0x683: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_688:
	/* 0x688: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_68b:
	/* 0x68b: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_68e:
	/* 0x68e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_693:
	/* 0x693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_695:
	/* 0x695: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_697:
	/* 0x697: js     6ce <tail_handle_ipv6+0x6ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_6ce;
	}
x86_l_699:
	/* 0x699: movzx  r15d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_69f:
	/* 0x69f: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a3:
	/* 0x6a3: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_6a6:
	/* 0x6a6: jle    86b <tail_handle_ipv6+0x86b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2155ULL;
	}
x86_l_6ac:
	/* 0x6ac: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6af:
	/* 0x6af: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: je     4d4 <tail_handle_ipv6+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4d4;
	}
x86_l_6b8:
	/* 0x6b8: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_6bb:
	/* 0x6bb: jne    86e <tail_handle_ipv6+0x86e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2158ULL;
	}
x86_l_6c1:
	/* 0x6c1: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_6c6:
	/* 0x6c6: shl    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_6c9:
	/* 0x6c9: jmp    87f <tail_handle_ipv6+0x87f> */
	return 2175ULL;
x86_l_6ce:
	/* 0x6ce: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_6d3:
	/* 0x6d3: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6d8:
	/* 0x6d8: jmp    3c <tail_handle_ipv6+0x3c> */
	goto x86_l_3c;
x86_l_6dd:
	/* 0x6dd: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_6e0:
	/* 0x6e0: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_6e7:
	/* 0x6e7: jmp    90f <tail_handle_ipv6+0x90f> */
	return 2319ULL;
x86_l_6ec:
	/* 0x6ec: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_6f3:
	/* 0x6f3: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f8:
	/* 0x6f8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_6fb:
	/* 0x6fb: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_705:
	/* 0x705: jmp    727 <tail_handle_ipv6+0x727> */
	return 1831ULL;
x86_l_707:
	/* 0x707: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_70d:
	/* 0x70d: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_714:
	/* 0x714: movabs r12,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_71e:
	/* 0x71e: jmp    73e <tail_handle_ipv6+0x73e> */
	return 1854ULL;
	return 1824ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1824ULL: goto x86_l_720;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1844ULL: goto x86_l_734;
	case 1848ULL: goto x86_l_738;
	case 1854ULL: goto x86_l_73e;
	case 1861ULL: goto x86_l_745;
	case 1864ULL: goto x86_l_748;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1893ULL: goto x86_l_765;
	case 1895ULL: goto x86_l_767;
	case 1901ULL: goto x86_l_76d;
	case 1905ULL: goto x86_l_771;
	case 1910ULL: goto x86_l_776;
	case 1914ULL: goto x86_l_77a;
	case 1917ULL: goto x86_l_77d;
	case 1922ULL: goto x86_l_782;
	case 1932ULL: goto x86_l_78c;
	case 1935ULL: goto x86_l_78f;
	case 1940ULL: goto x86_l_794;
	case 1944ULL: goto x86_l_798;
	case 1954ULL: goto x86_l_7a2;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1966ULL: goto x86_l_7ae;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1982ULL: goto x86_l_7be;
	case 1986ULL: goto x86_l_7c2;
	case 1989ULL: goto x86_l_7c5;
	case 1993ULL: goto x86_l_7c9;
	case 1999ULL: goto x86_l_7cf;
	case 2002ULL: goto x86_l_7d2;
	case 2006ULL: goto x86_l_7d6;
	case 2008ULL: goto x86_l_7d8;
	case 2010ULL: goto x86_l_7da;
	case 2015ULL: goto x86_l_7df;
	case 2020ULL: goto x86_l_7e4;
	case 2023ULL: goto x86_l_7e7;
	case 2028ULL: goto x86_l_7ec;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2038ULL: goto x86_l_7f6;
	case 2040ULL: goto x86_l_7f8;
	case 2046ULL: goto x86_l_7fe;
	case 2049ULL: goto x86_l_801;
	case 2053ULL: goto x86_l_805;
	case 2055ULL: goto x86_l_807;
	case 2059ULL: goto x86_l_80b;
	case 2061ULL: goto x86_l_80d;
	case 2065ULL: goto x86_l_811;
	case 2067ULL: goto x86_l_813;
	case 2071ULL: goto x86_l_817;
	case 2073ULL: goto x86_l_819;
	case 2082ULL: goto x86_l_822;
	case 2087ULL: goto x86_l_827;
	case 2092ULL: goto x86_l_82c;
	case 2095ULL: goto x86_l_82f;
	case 2100ULL: goto x86_l_834;
	case 2102ULL: goto x86_l_836;
	case 2104ULL: goto x86_l_838;
	case 2110ULL: goto x86_l_83e;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2123ULL: goto x86_l_84b;
	case 2127ULL: goto x86_l_84f;
	case 2132ULL: goto x86_l_854;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2150ULL: goto x86_l_866;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2175ULL: goto x86_l_87f;
	case 2179ULL: goto x86_l_883;
	case 2181ULL: goto x86_l_885;
	case 2184ULL: goto x86_l_888;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2202ULL: goto x86_l_89a;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2215ULL: goto x86_l_8a7;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2235ULL: goto x86_l_8bb;
	case 2241ULL: goto x86_l_8c1;
	case 2244ULL: goto x86_l_8c4;
	case 2248ULL: goto x86_l_8c8;
	case 2254ULL: goto x86_l_8ce;
	case 2258ULL: goto x86_l_8d2;
	case 2264ULL: goto x86_l_8d8;
	case 2268ULL: goto x86_l_8dc;
	case 2274ULL: goto x86_l_8e2;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2299ULL: goto x86_l_8fb;
	case 2304ULL: goto x86_l_900;
	case 2311ULL: goto x86_l_907;
	case 2316ULL: goto x86_l_90c;
	case 2319ULL: goto x86_l_90f;
	case 2327ULL: goto x86_l_917;
	case 2331ULL: goto x86_l_91b;
	case 2336ULL: goto x86_l_920;
	case 2340ULL: goto x86_l_924;
	case 2345ULL: goto x86_l_929;
	case 2349ULL: goto x86_l_92d;
	case 2357ULL: goto x86_l_935;
	case 2361ULL: goto x86_l_939;
	case 2369ULL: goto x86_l_941;
	case 2373ULL: goto x86_l_945;
	case 2375ULL: goto x86_l_947;
	case 2379ULL: goto x86_l_94b;
	case 2382ULL: goto x86_l_94e;
	case 2388ULL: goto x86_l_954;
	case 2391ULL: goto x86_l_957;
	case 2397ULL: goto x86_l_95d;
	case 2407ULL: goto x86_l_967;
	case 2415ULL: goto x86_l_96f;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2431ULL: goto x86_l_97f;
	case 2433ULL: goto x86_l_981;
	case 2437ULL: goto x86_l_985;
	case 2445ULL: goto x86_l_98d;
	case 2449ULL: goto x86_l_991;
	case 2452ULL: goto x86_l_994;
	case 2456ULL: goto x86_l_998;
	case 2460ULL: goto x86_l_99c;
	case 2463ULL: goto x86_l_99f;
	case 2468ULL: goto x86_l_9a4;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2485ULL: goto x86_l_9b5;
	case 2490ULL: goto x86_l_9ba;
	case 2492ULL: goto x86_l_9bc;
	case 2494ULL: goto x86_l_9be;
	case 2500ULL: goto x86_l_9c4;
	case 2510ULL: goto x86_l_9ce;
	case 2516ULL: goto x86_l_9d4;
	case 2520ULL: goto x86_l_9d8;
	case 2522ULL: goto x86_l_9da;
	case 2525ULL: goto x86_l_9dd;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2539ULL: goto x86_l_9eb;
	case 2544ULL: goto x86_l_9f0;
	case 2547ULL: goto x86_l_9f3;
	case 2550ULL: goto x86_l_9f6;
	case 2555ULL: goto x86_l_9fb;
	case 2557ULL: goto x86_l_9fd;
	case 2559ULL: goto x86_l_9ff;
	case 2565ULL: goto x86_l_a05;
	case 2573ULL: goto x86_l_a0d;
	case 2580ULL: goto x86_l_a14;
	case 2585ULL: goto x86_l_a19;
	case 2590ULL: goto x86_l_a1e;
	case 2598ULL: goto x86_l_a26;
	case 2606ULL: goto x86_l_a2e;
	case 2614ULL: goto x86_l_a36;
	case 2622ULL: goto x86_l_a3e;
	case 2632ULL: goto x86_l_a48;
	case 2640ULL: goto x86_l_a50;
	case 2647ULL: goto x86_l_a57;
	case 2655ULL: goto x86_l_a5f;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2667ULL: goto x86_l_a6b;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2680ULL: goto x86_l_a78;
	case 2689ULL: goto x86_l_a81;
	case 2699ULL: goto x86_l_a8b;
	case 2707ULL: goto x86_l_a93;
	case 2714ULL: goto x86_l_a9a;
	case 2722ULL: goto x86_l_aa2;
	case 2725ULL: goto x86_l_aa5;
	case 2728ULL: goto x86_l_aa8;
	case 2731ULL: goto x86_l_aab;
	case 2737ULL: goto x86_l_ab1;
	case 2740ULL: goto x86_l_ab4;
	case 2749ULL: goto x86_l_abd;
	case 2754ULL: goto x86_l_ac2;
	case 2756ULL: goto x86_l_ac4;
	case 2764ULL: goto x86_l_acc;
	case 2770ULL: goto x86_l_ad2;
	case 2774ULL: goto x86_l_ad6;
	case 2776ULL: goto x86_l_ad8;
	case 2783ULL: goto x86_l_adf;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2797ULL: goto x86_l_aed;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2810ULL: goto x86_l_afa;
	case 2815ULL: goto x86_l_aff;
	case 2819ULL: goto x86_l_b03;
	case 2823ULL: goto x86_l_b07;
	case 2831ULL: goto x86_l_b0f;
	case 2836ULL: goto x86_l_b14;
	case 2843ULL: goto x86_l_b1b;
	case 2847ULL: goto x86_l_b1f;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2861ULL: goto x86_l_b2d;
	case 2864ULL: goto x86_l_b30;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2881ULL: goto x86_l_b41;
	case 2883ULL: goto x86_l_b43;
	case 2886ULL: goto x86_l_b46;
	case 2889ULL: goto x86_l_b49;
	case 2892ULL: goto x86_l_b4c;
	case 2897ULL: goto x86_l_b51;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2912ULL: goto x86_l_b60;
	case 2918ULL: goto x86_l_b66;
	case 2922ULL: goto x86_l_b6a;
	case 2924ULL: goto x86_l_b6c;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2944ULL: goto x86_l_b80;
	case 2946ULL: goto x86_l_b82;
	case 2948ULL: goto x86_l_b84;
	case 2954ULL: goto x86_l_b8a;
	case 2961ULL: goto x86_l_b91;
	case 2963ULL: goto x86_l_b93;
	case 2970ULL: goto x86_l_b9a;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2982ULL: goto x86_l_ba6;
	case 2985ULL: goto x86_l_ba9;
	case 2991ULL: goto x86_l_baf;
	case 2998ULL: goto x86_l_bb6;
	case 3001ULL: goto x86_l_bb9;
	case 3006ULL: goto x86_l_bbe;
	case 3013ULL: goto x86_l_bc5;
	case 3016ULL: goto x86_l_bc8;
	case 3021ULL: goto x86_l_bcd;
	case 3024ULL: goto x86_l_bd0;
	case 3029ULL: goto x86_l_bd5;
	case 3032ULL: goto x86_l_bd8;
	case 3035ULL: goto x86_l_bdb;
	case 3040ULL: goto x86_l_be0;
	case 3043ULL: goto x86_l_be3;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3055ULL: goto x86_l_bef;
	case 3057ULL: goto x86_l_bf1;
	case 3063ULL: goto x86_l_bf7;
	case 3067ULL: goto x86_l_bfb;
	case 3069ULL: goto x86_l_bfd;
	case 3075ULL: goto x86_l_c03;
	case 3085ULL: goto x86_l_c0d;
	case 3089ULL: goto x86_l_c11;
	case 3096ULL: goto x86_l_c18;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3111ULL: goto x86_l_c27;
	case 3116ULL: goto x86_l_c2c;
	case 3121ULL: goto x86_l_c31;
	case 3129ULL: goto x86_l_c39;
	case 3138ULL: goto x86_l_c42;
	case 3146ULL: goto x86_l_c4a;
	case 3151ULL: goto x86_l_c4f;
	case 3159ULL: goto x86_l_c57;
	case 3164ULL: goto x86_l_c5c;
	case 3172ULL: goto x86_l_c64;
	case 3177ULL: goto x86_l_c69;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3197ULL: goto x86_l_c7d;
	case 3205ULL: goto x86_l_c85;
	case 3210ULL: goto x86_l_c8a;
	case 3216ULL: goto x86_l_c90;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3235ULL: goto x86_l_ca3;
	case 3240ULL: goto x86_l_ca8;
	case 3243ULL: goto x86_l_cab;
	case 3248ULL: goto x86_l_cb0;
	case 3250ULL: goto x86_l_cb2;
	case 3252ULL: goto x86_l_cb4;
	case 3258ULL: goto x86_l_cba;
	case 3263ULL: goto x86_l_cbf;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3298ULL: goto x86_l_ce2;
	case 3303ULL: goto x86_l_ce7;
	case 3308ULL: goto x86_l_cec;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3322ULL: goto x86_l_cfa;
	case 3328ULL: goto x86_l_d00;
	case 3333ULL: goto x86_l_d05;
	case 3340ULL: goto x86_l_d0c;
	case 3346ULL: goto x86_l_d12;
	case 3353ULL: goto x86_l_d19;
	case 3358ULL: goto x86_l_d1e;
	case 3368ULL: goto x86_l_d28;
	case 3377ULL: goto x86_l_d31;
	case 3381ULL: goto x86_l_d35;
	case 3383ULL: goto x86_l_d37;
	case 3390ULL: goto x86_l_d3e;
	case 3392ULL: goto x86_l_d40;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3409ULL: goto x86_l_d51;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3430ULL: goto x86_l_d66;
	case 3438ULL: goto x86_l_d6e;
	case 3446ULL: goto x86_l_d76;
	case 3454ULL: goto x86_l_d7e;
	case 3462ULL: goto x86_l_d86;
	case 3470ULL: goto x86_l_d8e;
	case 3478ULL: goto x86_l_d96;
	case 3483ULL: goto x86_l_d9b;
	case 3491ULL: goto x86_l_da3;
	case 3498ULL: goto x86_l_daa;
	case 3501ULL: goto x86_l_dad;
	case 3504ULL: goto x86_l_db0;
	case 3512ULL: goto x86_l_db8;
	case 3520ULL: goto x86_l_dc0;
	case 3526ULL: goto x86_l_dc6;
	case 3529ULL: goto x86_l_dc9;
	case 3535ULL: goto x86_l_dcf;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3556ULL: goto x86_l_de4;
	case 3565ULL: goto x86_l_ded;
	case 3575ULL: goto x86_l_df7;
	case 3581ULL: goto x86_l_dfd;
	case 3586ULL: goto x86_l_e02;
	case 3593ULL: goto x86_l_e09;
	case 3598ULL: goto x86_l_e0e;
	case 3603ULL: goto x86_l_e13;
	case 3605ULL: goto x86_l_e15;
	case 3608ULL: goto x86_l_e18;
	case 3610ULL: goto x86_l_e1a;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3619ULL: goto x86_l_e23;
	case 3624ULL: goto x86_l_e28;
	case 3628ULL: goto x86_l_e2c;
	case 3634ULL: goto x86_l_e32;
	case 3639ULL: goto x86_l_e37;
	case 3644ULL: goto x86_l_e3c;
	case 3646ULL: goto x86_l_e3e;
	case 3653ULL: goto x86_l_e45;
	case 3656ULL: goto x86_l_e48;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3678ULL: goto x86_l_e5e;
	case 3683ULL: goto x86_l_e63;
	case 3690ULL: goto x86_l_e6a;
	case 3695ULL: goto x86_l_e6f;
	case 3700ULL: goto x86_l_e74;
	case 3705ULL: goto x86_l_e79;
	case 3707ULL: goto x86_l_e7b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_720:
	/* 0x720: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_727:
	/* 0x727: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_72c:
	/* 0x72c: lea    r14d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_734:
	/* 0x734: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_738:
	/* 0x738: jne    7be <tail_handle_ipv6+0x7be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7be;
	}
x86_l_73e:
	/* 0x73e: mov    BYTE PTR [rsp+0x98],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_745:
	/* 0x745: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_748:
	/* 0x748: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_751:
	/* 0x751: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_756:
	/* 0x756: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_75b:
	/* 0x75b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_75e:
	/* 0x75e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_763:
	/* 0x763: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_765:
	/* 0x765: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_767:
	/* 0x767: js     185a <tail_handle_ipv6+0x185a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6234ULL;
	}
x86_l_76d:
	/* 0x76d: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_771:
	/* 0x771: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_776:
	/* 0x776: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_77a:
	/* 0x77a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_77d:
	/* 0x77d: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_782:
	/* 0x782: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_78c:
	/* 0x78c: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_78f:
	/* 0x78f: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_794:
	/* 0x794: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_798:
	/* 0x798: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_7a2:
	/* 0x7a2: or     rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_7a5:
	/* 0x7a5: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_7aa:
	/* 0x7aa: cmove  rdi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_7ae:
	/* 0x7ae: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_7b1:
	/* 0x7b1: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b6:
	/* 0x7b6: movzx  edx,BYTE PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 152ULL);
x86_l_7be:
	/* 0x7be: movzx  r15d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_7c2:
	/* 0x7c2: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7c5:
	/* 0x7c5: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_7c9:
	/* 0x7c9: ja     90c <tail_handle_ipv6+0x90c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_90c;
	}
x86_l_7cf:
	/* 0x7cf: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_7d2:
	/* 0x7d2: bt     r12,rax */
	X86_SIM_L_EXEC_BT(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_7d6:
	/* 0x7d6: jae    848 <tail_handle_ipv6+0x848> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_848;
	}
x86_l_7d8:
	/* 0x7d8: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_7da:
	/* 0x7da: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7df:
	/* 0x7df: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7e4:
	/* 0x7e4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7e7:
	/* 0x7e7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7ec:
	/* 0x7ec: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_7ef:
	/* 0x7ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f1:
	/* 0x7f1: mov    edx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967162ULL);
x86_l_7f6:
	/* 0x7f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f8:
	/* 0x7f8: js     626 <tail_handle_ipv6+0x626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1574ULL;
	}
x86_l_7fe:
	/* 0x7fe: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_801:
	/* 0x801: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_805:
	/* 0x805: jle    813 <tail_handle_ipv6+0x813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_813;
	}
x86_l_807:
	/* 0x807: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_80b:
	/* 0x80b: je     819 <tail_handle_ipv6+0x819> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_819;
	}
x86_l_80d:
	/* 0x80d: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_811:
	/* 0x811: je     83e <tail_handle_ipv6+0x83e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_83e;
	}
x86_l_813:
	/* 0x813: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_817:
	/* 0x817: jne    83e <tail_handle_ipv6+0x83e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_83e;
	}
x86_l_819:
	/* 0x819: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_822:
	/* 0x822: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_827:
	/* 0x827: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_82c:
	/* 0x82c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_82f:
	/* 0x82f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_834:
	/* 0x834: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_836:
	/* 0x836: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_838:
	/* 0x838: js     185a <tail_handle_ipv6+0x185a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6234ULL;
	}
x86_l_83e:
	/* 0x83e: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_843:
	/* 0x843: jmp    185f <tail_handle_ipv6+0x185f> */
	return 6239ULL;
x86_l_848:
	/* 0x848: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_84b:
	/* 0x84b: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_84f:
	/* 0x84f: mov    edx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967140ULL);
x86_l_854:
	/* 0x854: je     626 <tail_handle_ipv6+0x626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1574ULL;
	}
x86_l_85a:
	/* 0x85a: jmp    90f <tail_handle_ipv6+0x90f> */
	goto x86_l_90f;
x86_l_85f:
	/* 0x85f: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_866:
	/* 0x866: jmp    90f <tail_handle_ipv6+0x90f> */
	goto x86_l_90f;
x86_l_86b:
	/* 0x86b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_871:
	/* 0x871: je     4d4 <tail_handle_ipv6+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1236ULL;
	}
x86_l_877:
	/* 0x877: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_87c:
	/* 0x87c: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_87f:
	/* 0x87f: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_883:
	/* 0x883: ja     8fb <tail_handle_ipv6+0x8fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8fb;
	}
x86_l_885:
	/* 0x885: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_888:
	/* 0x888: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_892:
	/* 0x892: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_896:
	/* 0x896: jae    8f1 <tail_handle_ipv6+0x8f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8f1;
	}
x86_l_898:
	/* 0x898: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_89a:
	/* 0x89a: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_89d:
	/* 0x89d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8a2:
	/* 0x8a2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8a7:
	/* 0x8a7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8aa:
	/* 0x8aa: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_8ad:
	/* 0x8ad: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8b2:
	/* 0x8b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b4:
	/* 0x8b4: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_8b9:
	/* 0x8b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8bb:
	/* 0x8bb: js     342 <tail_handle_ipv6+0x342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 834ULL;
	}
x86_l_8c1:
	/* 0x8c1: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_8c4:
	/* 0x8c4: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_8c8:
	/* 0x8c8: jle    e23 <tail_handle_ipv6+0xe23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e23;
	}
x86_l_8ce:
	/* 0x8ce: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_8d2:
	/* 0x8d2: je     4d4 <tail_handle_ipv6+0x4d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1236ULL;
	}
x86_l_8d8:
	/* 0x8d8: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_8dc:
	/* 0x8dc: jne    e23 <tail_handle_ipv6+0xe23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e23;
	}
x86_l_8e2:
	/* 0x8e2: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_8e7:
	/* 0x8e7: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8ec:
	/* 0x8ec: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_8f1:
	/* 0x8f1: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_8f5:
	/* 0x8f5: je     342 <tail_handle_ipv6+0x342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 834ULL;
	}
x86_l_8fb:
	/* 0x8fb: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_900:
	/* 0x900: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_907:
	/* 0x907: jmp    ba <tail_handle_ipv6+0xba> */
	return 186ULL;
x86_l_90c:
	/* 0x90c: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_90f:
	/* 0x90f: mov    BYTE PTR [rsp+0x94],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_917:
	/* 0x917: mov    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_91b:
	/* 0x91b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_920:
	/* 0x920: mov    rax,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_924:
	/* 0x924: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_929:
	/* 0x929: mov    rax,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_92d:
	/* 0x92d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_935:
	/* 0x935: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_939:
	/* 0x939: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_941:
	/* 0x941: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_945:
	/* 0x945: je     95d <tail_handle_ipv6+0x95d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_95d;
	}
x86_l_947:
	/* 0x947: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_94b:
	/* 0x94b: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_94e:
	/* 0x94e: je     1ecd <tail_handle_ipv6+0x1ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7885ULL;
	}
x86_l_954:
	/* 0x954: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_957:
	/* 0x957: jne    2bfe <tail_handle_ipv6+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11262ULL;
	}
x86_l_95d:
	/* 0x95d: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_967:
	/* 0x967: lea    rbp,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_96f:
	/* 0x96f: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_972:
	/* 0x972: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_977:
	/* 0x977: mov    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_97f:
	/* 0x97f: je     9da <tail_handle_ipv6+0x9da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9da;
	}
x86_l_981:
	/* 0x981: mov    r14,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_985:
	/* 0x985: mov    QWORD PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98d:
	/* 0x98d: mov    DWORD PTR [r13+0x0],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_991:
	/* 0x991: mov    rax,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_64);
x86_l_994:
	/* 0x994: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_998:
	/* 0x998: mov    BYTE PTR [r13+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_99c:
	/* 0x99c: test   rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_99f:
	/* 0x99f: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9a4:
	/* 0x9a4: jne    1f32 <tail_handle_ipv6+0x1f32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7986ULL;
	}
x86_l_9aa:
	/* 0x9aa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9af:
	/* 0x9af: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9b2:
	/* 0x9b2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9b5:
	/* 0x9b5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9ba:
	/* 0x9ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bc:
	/* 0x9bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9be:
	/* 0x9be: js     ae4 <tail_handle_ipv6+0xae4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_ae4;
	}
x86_l_9c4:
	/* 0x9c4: bt     QWORD PTR [rsp+0x98],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 652835029032ULL);
x86_l_9ce:
	/* 0x9ce: jb     1f5a <tail_handle_ipv6+0x1f5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8026ULL;
	}
x86_l_9d4:
	/* 0x9d4: mov    QWORD PTR [r13+0x0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d8:
	/* 0x9d8: jmp    a05 <tail_handle_ipv6+0xa05> */
	goto x86_l_a05;
x86_l_9da:
	/* 0x9da: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9dd:
	/* 0x9dd: test   rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_9e0:
	/* 0x9e0: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9e5:
	/* 0x9e5: jne    1fc0 <tail_handle_ipv6+0x1fc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8128ULL;
	}
x86_l_9eb:
	/* 0x9eb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9f0:
	/* 0x9f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9f3:
	/* 0x9f3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9f6:
	/* 0x9f6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9fb:
	/* 0x9fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fd:
	/* 0x9fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9ff:
	/* 0x9ff: js     af5 <tail_handle_ipv6+0xaf5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_af5;
	}
x86_l_a05:
	/* 0xa05: movzx  eax,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_a0d:
	/* 0xa0d: mov    BYTE PTR [rsp+0xc4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_a14:
	/* 0xa14: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a19:
	/* 0xa19: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a1e:
	/* 0xa1e: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_a26:
	/* 0xa26: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a2e:
	/* 0xa2e: movzx  eax,WORD PTR [rsp+0x92] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 146ULL);
x86_l_a36:
	/* 0xa36: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_a3e:
	/* 0xa3e: mov    WORD PTR [rsp+0xc2],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 833223655424ULL);
x86_l_a48:
	/* 0xa48: mov    BYTE PTR [rsp+0xc5],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 846108557312ULL);
x86_l_a50:
	/* 0xa50: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_a57:
	/* 0xa57: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a5f:
	/* 0xa5f: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_a65:
	/* 0xa65: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_a68:
	/* 0xa68: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a6b:
	/* 0xa6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6e:
	/* 0xa6e: jne    ab1 <tail_handle_ipv6+0xab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ab1;
	}
x86_l_a70:
	/* 0xa70: movzx  ebp,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_a78:
	/* 0xa78: movzx  r15d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_a81:
	/* 0xa81: mov    WORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_a8b:
	/* 0xa8b: mov    BYTE PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_a93:
	/* 0xa93: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_a9a:
	/* 0xa9a: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_aa2:
	/* 0xaa2: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_aa5:
	/* 0xaa5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_aa8:
	/* 0xaa8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aab:
	/* 0xaab: je     c31 <tail_handle_ipv6+0xc31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c31;
	}
x86_l_ab1:
	/* 0xab1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab4:
	/* 0xab4: cmp    WORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_abd:
	/* 0xabd: mov    ecx,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967138ULL);
x86_l_ac2:
	/* 0xac2: jne    ad2 <tail_handle_ipv6+0xad2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ad2;
	}
x86_l_ac4:
	/* 0xac4: cmp    BYTE PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_acc:
	/* 0xacc: je     32f4 <tail_handle_ipv6+0x32f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13044ULL;
	}
x86_l_ad2:
	/* 0xad2: cmp    BYTE PTR [rdx+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ad6:
	/* 0xad6: js     aff <tail_handle_ipv6+0xaff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_aff;
	}
x86_l_ad8:
	/* 0xad8: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_adf:
	/* 0xadf: jmp    b66 <tail_handle_ipv6+0xb66> */
	goto x86_l_b66;
x86_l_ae4:
	/* 0xae4: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_ae9:
	/* 0xae9: mov    QWORD PTR [r13+0x0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aed:
	/* 0xaed: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af0:
	/* 0xaf0: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_af5:
	/* 0xaf5: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_afa:
	/* 0xafa: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_aff:
	/* 0xaff: add    r13,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_b03:
	/* 0xb03: movzx  eax,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_b07:
	/* 0xb07: mov    DWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476896ULL);
x86_l_b0f:
	/* 0xb0f: mov    WORD PTR [rsp+0x14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_b14:
	/* 0xb14: mov    WORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_b1b:
	/* 0xb1b: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1f:
	/* 0xb1f: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b23:
	/* 0xb23: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b28:
	/* 0xb28: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b2d:
	/* 0xb2d: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_b30:
	/* 0xb30: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_source_range)));
x86_l_b37:
	/* 0xb37: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b3c:
	/* 0xb3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b41:
	/* 0xb41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b43:
	/* 0xb43: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_b46:
	/* 0xb46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b49:
	/* 0xb49: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_b4c:
	/* 0xb4c: movzx  ecx,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_b51:
	/* 0xb51: and    cl,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 64ULL);
x86_l_b54:
	/* 0xb54: shr    cl,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHR, 6ULL);
x86_l_b57:
	/* 0xb57: cmp    al,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_8);
x86_l_b59:
	/* 0xb59: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_b60:
	/* 0xb60: je     d40 <tail_handle_ipv6+0xd40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d40;
	}
x86_l_b66:
	/* 0xb66: test   BYTE PTR [rdx+0x8],0x40 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_b6a:
	/* 0xb6a: jne    b76 <tail_handle_ipv6+0xb76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b76;
	}
x86_l_b6c:
	/* 0xb6c: mov    ecx,0xffffff52 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967122ULL);
x86_l_b71:
	/* 0xb71: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_b76:
	/* 0xb76: test   BYTE PTR [rdx+0x9],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705668ULL);
x86_l_b7a:
	/* 0xb7a: je     d1e <tail_handle_ipv6+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b80:
	/* 0xb80: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b82:
	/* 0xb82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b84:
	/* 0xb84: je     d1e <tail_handle_ipv6+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d1e;
	}
x86_l_b8a:
	/* 0xb8a: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_b91:
	/* 0xb91: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b93:
	/* 0xb93: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_b9a:
	/* 0xb9a: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9d:
	/* 0xb9d: jne    baf <tail_handle_ipv6+0xbaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_baf;
	}
x86_l_b9f:
	/* 0xb9f: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_proxy_redirect_via_cilium_net)));
x86_l_ba6:
	/* 0xba6: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba9:
	/* 0xba9: je     126e <tail_handle_ipv6+0x126e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4718ULL;
	}
x86_l_baf:
	/* 0xbaf: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_bb6:
	/* 0xbb6: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb9:
	/* 0xbb9: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bbe:
	/* 0xbbe: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_bc5:
	/* 0xbc5: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc8:
	/* 0xbc8: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bcd:
	/* 0xbcd: shl    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_bd0:
	/* 0xbd0: or     eax,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_bd5:
	/* 0xbd5: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd8:
	/* 0xbd8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_bdb:
	/* 0xbdb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_be0:
	/* 0xbe0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_be3:
	/* 0xbe3: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_be8:
	/* 0xbe8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bed:
	/* 0xbed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bef:
	/* 0xbef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf1:
	/* 0xbf1: js     1037 <tail_handle_ipv6+0x1037> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4151ULL;
	}
x86_l_bf7:
	/* 0xbf7: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_bfb:
	/* 0xbfb: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_bfd:
	/* 0xbfd: jae    10b1 <tail_handle_ipv6+0x10b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4273ULL;
	}
x86_l_c03:
	/* 0xc03: movabs rax,0x200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934592ULL);
x86_l_c0d:
	/* 0xc0d: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c11:
	/* 0xc11: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_c18:
	/* 0xc18: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_c1d:
	/* 0xc1d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c20:
	/* 0xc20: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_c25:
	/* 0xc25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c27:
	/* 0xc27: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_c2c:
	/* 0xc2c: jmp    1297 <tail_handle_ipv6+0x1297> */
	return 4759ULL;
x86_l_c31:
	/* 0xc31: mov    BYTE PTR [rsp+0xc4],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_c39:
	/* 0xc39: mov    WORD PTR [rsp+0xc0],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c42:
	/* 0xc42: mov    rax,QWORD PTR [rsp+0x8e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 142ULL);
x86_l_c4a:
	/* 0xc4a: mov    QWORD PTR [rsp+0x2e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_c4f:
	/* 0xc4f: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c57:
	/* 0xc57: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c5c:
	/* 0xc5c: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c64:
	/* 0xc64: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c69:
	/* 0xc69: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c6e:
	/* 0xc6e: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c73:
	/* 0xc73: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c78:
	/* 0xc78: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7d:
	/* 0xc7d: cmp    BYTE PTR [rsp+0x94],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 635655159814ULL);
x86_l_c85:
	/* 0xc85: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8a:
	/* 0xc8a: jne    f7b <tail_handle_ipv6+0xf7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3963ULL;
	}
x86_l_c90:
	/* 0xc90: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_c98:
	/* 0xc98: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_c9b:
	/* 0xc9b: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_c9e:
	/* 0xc9e: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ca3:
	/* 0xca3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ca8:
	/* 0xca8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cab:
	/* 0xcab: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cb0:
	/* 0xcb0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb2:
	/* 0xcb2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb4:
	/* 0xcb4: js     e37 <tail_handle_ipv6+0xe37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_e37;
	}
x86_l_cba:
	/* 0xcba: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cbf:
	/* 0xcbf: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cc4:
	/* 0xcc4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc9:
	/* 0xcc9: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cce:
	/* 0xcce: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cd3:
	/* 0xcd3: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cd8:
	/* 0xcd8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cdd:
	/* 0xcdd: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce2:
	/* 0xce2: rol    DWORD PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 206158430224ULL);
x86_l_ce7:
	/* 0xce7: movzx  ebp,BYTE PTR [rsp+0x35] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 53ULL);
x86_l_cec:
	/* 0xcec: xor    bpl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_cf0:
	/* 0xcf0: mov    BYTE PTR [rsp+0x35],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_cf5:
	/* 0xcf5: test   BYTE PTR [rsp+0x59],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 382252089346ULL);
x86_l_cfa:
	/* 0xcfa: jne    f78 <tail_handle_ipv6+0xf78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3960ULL;
	}
x86_l_d00:
	/* 0xd00: cmp    BYTE PTR [rsp+0x34],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 223338299398ULL);
x86_l_d05:
	/* 0xd05: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_d0c:
	/* 0xd0c: jne    113c <tail_handle_ipv6+0x113c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4412ULL;
	}
x86_l_d12:
	/* 0xd12: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_d19:
	/* 0xd19: jmp    1143 <tail_handle_ipv6+0x1143> */
	return 4419ULL;
x86_l_d1e:
	/* 0xd1e: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_d28:
	/* 0xd28: movzx  r14d,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_d31:
	/* 0xd31: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_d35:
	/* 0xd35: jne    d4a <tail_handle_ipv6+0xd4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d4a;
	}
x86_l_d37:
	/* 0xd37: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_d3e:
	/* 0xd3e: jmp    d51 <tail_handle_ipv6+0xd51> */
	goto x86_l_d51;
x86_l_d40:
	/* 0xd40: mov    ecx,0xffffff4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967119ULL);
x86_l_d45:
	/* 0xd45: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_d4a:
	/* 0xd4a: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_d51:
	/* 0xd51: mov    QWORD PTR [rsp+0xc8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_d59:
	/* 0xd59: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5e:
	/* 0xd5e: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d66:
	/* 0xd66: movzx  esi,BYTE PTR [rsp+0x95] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 149ULL);
x86_l_d6e:
	/* 0xd6e: mov    BYTE PTR [rsp+0xa7],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 167ULL);
x86_l_d76:
	/* 0xd76: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_d7e:
	/* 0xd7e: mov    QWORD PTR [rsp+0xd8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d86:
	/* 0xd86: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d8e:
	/* 0xd8e: mov    QWORD PTR [rsp+0xd0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d96:
	/* 0xd96: movzx  r13d,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_d9b:
	/* 0xd9b: mov    BYTE PTR [rsp+0x95],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 639950127108ULL);
x86_l_da3:
	/* 0xda3: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_daa:
	/* 0xdaa: and    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_dad:
	/* 0xdad: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db0:
	/* 0xdb0: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_db8:
	/* 0xdb8: mov    BYTE PTR [rsp+0xa8],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_dc0:
	/* 0xdc0: je     e8f <tail_handle_ipv6+0xe8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3727ULL;
	}
x86_l_dc6:
	/* 0xdc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc9:
	/* 0xdc9: je     e8f <tail_handle_ipv6+0xe8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3727ULL;
	}
x86_l_dcf:
	/* 0xdcf: mov    WORD PTR [rsp+0x54],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_dd5:
	/* 0xdd5: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_dd8:
	/* 0xdd8: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ddb:
	/* 0xddb: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_de4:
	/* 0xde4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ded:
	/* 0xded: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_df7:
	/* 0xdf7: or     rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 256ULL);
x86_l_dfd:
	/* 0xdfd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e02:
	/* 0xe02: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_e09:
	/* 0xe09: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e0e:
	/* 0xe0e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e13:
	/* 0xe13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e15:
	/* 0xe15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e18:
	/* 0xe18: je     e55 <tail_handle_ipv6+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e55;
	}
x86_l_e1a:
	/* 0xe1a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e1d:
	/* 0xe1d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e21:
	/* 0xe21: jmp    e7d <tail_handle_ipv6+0xe7d> */
	return 3709ULL;
x86_l_e23:
	/* 0xe23: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_e28:
	/* 0xe28: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_e2c:
	/* 0xe2c: jne    342 <tail_handle_ipv6+0x342> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 834ULL;
	}
x86_l_e32:
	/* 0xe32: jmp    4d4 <tail_handle_ipv6+0x4d4> */
	return 1236ULL;
x86_l_e37:
	/* 0xe37: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_e3c:
	/* 0xe3c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e3e:
	/* 0xe3e: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_e45:
	/* 0xe45: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_e48:
	/* 0xe48: mov    r8,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e50:
	/* 0xe50: jmp    167b <tail_handle_ipv6+0x167b> */
	return 5755ULL;
x86_l_e55:
	/* 0xe55: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_e5e:
	/* 0xe5e: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e63:
	/* 0xe63: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_e6a:
	/* 0xe6a: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e6f:
	/* 0xe6f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e74:
	/* 0xe74: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e79:
	/* 0xe79: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7b:
	/* 0xe7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3709ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3709ULL: goto x86_l_e7d;
	case 3712ULL: goto x86_l_e80;
	case 3718ULL: goto x86_l_e86;
	case 3727ULL: goto x86_l_e8f;
	case 3731ULL: goto x86_l_e93;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3741ULL: goto x86_l_e9d;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3756ULL: goto x86_l_eac;
	case 3759ULL: goto x86_l_eaf;
	case 3762ULL: goto x86_l_eb2;
	case 3767ULL: goto x86_l_eb7;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3777ULL: goto x86_l_ec1;
	case 3779ULL: goto x86_l_ec3;
	case 3785ULL: goto x86_l_ec9;
	case 3789ULL: goto x86_l_ecd;
	case 3792ULL: goto x86_l_ed0;
	case 3797ULL: goto x86_l_ed5;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3815ULL: goto x86_l_ee7;
	case 3821ULL: goto x86_l_eed;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3829ULL: goto x86_l_ef5;
	case 3833ULL: goto x86_l_ef9;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3851ULL: goto x86_l_f0b;
	case 3853ULL: goto x86_l_f0d;
	case 3856ULL: goto x86_l_f10;
	case 3862ULL: goto x86_l_f16;
	case 3865ULL: goto x86_l_f19;
	case 3870ULL: goto x86_l_f1e;
	case 3876ULL: goto x86_l_f24;
	case 3883ULL: goto x86_l_f2b;
	case 3888ULL: goto x86_l_f30;
	case 3894ULL: goto x86_l_f36;
	case 3898ULL: goto x86_l_f3a;
	case 3904ULL: goto x86_l_f40;
	case 3911ULL: goto x86_l_f47;
	case 3914ULL: goto x86_l_f4a;
	case 3920ULL: goto x86_l_f50;
	case 3927ULL: goto x86_l_f57;
	case 3930ULL: goto x86_l_f5a;
	case 3934ULL: goto x86_l_f5e;
	case 3938ULL: goto x86_l_f62;
	case 3941ULL: goto x86_l_f65;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3955ULL: goto x86_l_f73;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3972ULL: goto x86_l_f84;
	case 3981ULL: goto x86_l_f8d;
	case 3990ULL: goto x86_l_f96;
	case 3995ULL: goto x86_l_f9b;
	case 3999ULL: goto x86_l_f9f;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4028ULL: goto x86_l_fbc;
	case 4032ULL: goto x86_l_fc0;
	case 4034ULL: goto x86_l_fc2;
	case 4037ULL: goto x86_l_fc5;
	case 4040ULL: goto x86_l_fc8;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4051ULL: goto x86_l_fd3;
	case 4056ULL: goto x86_l_fd8;
	case 4061ULL: goto x86_l_fdd;
	case 4063ULL: goto x86_l_fdf;
	case 4065ULL: goto x86_l_fe1;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4080ULL: goto x86_l_ff0;
	case 4083ULL: goto x86_l_ff3;
	case 4086ULL: goto x86_l_ff6;
	case 4088ULL: goto x86_l_ff8;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4103ULL: goto x86_l_1007;
	case 4107ULL: goto x86_l_100b;
	case 4109ULL: goto x86_l_100d;
	case 4114ULL: goto x86_l_1012;
	case 4121ULL: goto x86_l_1019;
	case 4125ULL: goto x86_l_101d;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4140ULL: goto x86_l_102c;
	case 4146ULL: goto x86_l_1032;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4161ULL: goto x86_l_1041;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4178ULL: goto x86_l_1052;
	case 4182ULL: goto x86_l_1056;
	case 4188ULL: goto x86_l_105c;
	case 4191ULL: goto x86_l_105f;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4207ULL: goto x86_l_106f;
	case 4212ULL: goto x86_l_1074;
	case 4215ULL: goto x86_l_1077;
	case 4220ULL: goto x86_l_107c;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4229ULL: goto x86_l_1085;
	case 4235ULL: goto x86_l_108b;
	case 4240ULL: goto x86_l_1090;
	case 4246ULL: goto x86_l_1096;
	case 4251ULL: goto x86_l_109b;
	case 4254ULL: goto x86_l_109e;
	case 4257ULL: goto x86_l_10a1;
	case 4262ULL: goto x86_l_10a6;
	case 4268ULL: goto x86_l_10ac;
	case 4273ULL: goto x86_l_10b1;
	case 4275ULL: goto x86_l_10b3;
	case 4278ULL: goto x86_l_10b6;
	case 4281ULL: goto x86_l_10b9;
	case 4287ULL: goto x86_l_10bf;
	case 4290ULL: goto x86_l_10c2;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4306ULL: goto x86_l_10d2;
	case 4309ULL: goto x86_l_10d5;
	case 4311ULL: goto x86_l_10d7;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4338ULL: goto x86_l_10f2;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4348ULL: goto x86_l_10fc;
	case 4354ULL: goto x86_l_1102;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4367ULL: goto x86_l_110f;
	case 4369ULL: goto x86_l_1111;
	case 4374ULL: goto x86_l_1116;
	case 4377ULL: goto x86_l_1119;
	case 4379ULL: goto x86_l_111b;
	case 4381ULL: goto x86_l_111d;
	case 4387ULL: goto x86_l_1123;
	case 4394ULL: goto x86_l_112a;
	case 4396ULL: goto x86_l_112c;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4405ULL: goto x86_l_1135;
	case 4407ULL: goto x86_l_1137;
	case 4412ULL: goto x86_l_113c;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4441ULL: goto x86_l_1159;
	case 4443ULL: goto x86_l_115b;
	case 4446ULL: goto x86_l_115e;
	case 4452ULL: goto x86_l_1164;
	case 4456ULL: goto x86_l_1168;
	case 4459ULL: goto x86_l_116b;
	case 4464ULL: goto x86_l_1170;
	case 4469ULL: goto x86_l_1175;
	case 4473ULL: goto x86_l_1179;
	case 4479ULL: goto x86_l_117f;
	case 4482ULL: goto x86_l_1182;
	case 4492ULL: goto x86_l_118c;
	case 4496ULL: goto x86_l_1190;
	case 4502ULL: goto x86_l_1196;
	case 4505ULL: goto x86_l_1199;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4516ULL: goto x86_l_11a4;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4525ULL: goto x86_l_11ad;
	case 4527ULL: goto x86_l_11af;
	case 4533ULL: goto x86_l_11b5;
	case 4538ULL: goto x86_l_11ba;
	case 4542ULL: goto x86_l_11be;
	case 4544ULL: goto x86_l_11c0;
	case 4548ULL: goto x86_l_11c4;
	case 4554ULL: goto x86_l_11ca;
	case 4558ULL: goto x86_l_11ce;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4573ULL: goto x86_l_11dd;
	case 4577ULL: goto x86_l_11e1;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4601ULL: goto x86_l_11f9;
	case 4605ULL: goto x86_l_11fd;
	case 4611ULL: goto x86_l_1203;
	case 4615ULL: goto x86_l_1207;
	case 4621ULL: goto x86_l_120d;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4634ULL: goto x86_l_121a;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4643ULL: goto x86_l_1223;
	case 4645ULL: goto x86_l_1225;
	case 4651ULL: goto x86_l_122b;
	case 4656ULL: goto x86_l_1230;
	case 4662ULL: goto x86_l_1236;
	case 4667ULL: goto x86_l_123b;
	case 4670ULL: goto x86_l_123e;
	case 4673ULL: goto x86_l_1241;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4690ULL: goto x86_l_1252;
	case 4692ULL: goto x86_l_1254;
	case 4695ULL: goto x86_l_1257;
	case 4703ULL: goto x86_l_125f;
	case 4713ULL: goto x86_l_1269;
	case 4718ULL: goto x86_l_126e;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4729ULL: goto x86_l_1279;
	case 4732ULL: goto x86_l_127c;
	case 4734ULL: goto x86_l_127e;
	case 4739ULL: goto x86_l_1283;
	case 4743ULL: goto x86_l_1287;
	case 4749ULL: goto x86_l_128d;
	case 4754ULL: goto x86_l_1292;
	case 4759ULL: goto x86_l_1297;
	case 4762ULL: goto x86_l_129a;
	case 4765ULL: goto x86_l_129d;
	case 4770ULL: goto x86_l_12a2;
	case 4776ULL: goto x86_l_12a8;
	case 4780ULL: goto x86_l_12ac;
	case 4783ULL: goto x86_l_12af;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4792ULL: goto x86_l_12b8;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4807ULL: goto x86_l_12c7;
	case 4809ULL: goto x86_l_12c9;
	case 4813ULL: goto x86_l_12cd;
	case 4823ULL: goto x86_l_12d7;
	case 4826ULL: goto x86_l_12da;
	case 4831ULL: goto x86_l_12df;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4849ULL: goto x86_l_12f1;
	case 4852ULL: goto x86_l_12f4;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4865ULL: goto x86_l_1301;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4877ULL: goto x86_l_130d;
	case 4884ULL: goto x86_l_1314;
	case 4888ULL: goto x86_l_1318;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4900ULL: goto x86_l_1324;
	case 4905ULL: goto x86_l_1329;
	case 4913ULL: goto x86_l_1331;
	case 4915ULL: goto x86_l_1333;
	case 4918ULL: goto x86_l_1336;
	case 4920ULL: goto x86_l_1338;
	case 4923ULL: goto x86_l_133b;
	case 4926ULL: goto x86_l_133e;
	case 4928ULL: goto x86_l_1340;
	case 4932ULL: goto x86_l_1344;
	case 4934ULL: goto x86_l_1346;
	case 4939ULL: goto x86_l_134b;
	case 4945ULL: goto x86_l_1351;
	case 4949ULL: goto x86_l_1355;
	case 4952ULL: goto x86_l_1358;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4965ULL: goto x86_l_1365;
	case 4969ULL: goto x86_l_1369;
	case 4973ULL: goto x86_l_136d;
	case 4976ULL: goto x86_l_1370;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4985ULL: goto x86_l_1379;
	case 4987ULL: goto x86_l_137b;
	case 4991ULL: goto x86_l_137f;
	case 4993ULL: goto x86_l_1381;
	case 4998ULL: goto x86_l_1386;
	case 5000ULL: goto x86_l_1388;
	case 5002ULL: goto x86_l_138a;
	case 5006ULL: goto x86_l_138e;
	case 5016ULL: goto x86_l_1398;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5028ULL: goto x86_l_13a4;
	case 5031ULL: goto x86_l_13a7;
	case 5035ULL: goto x86_l_13ab;
	case 5039ULL: goto x86_l_13af;
	case 5042ULL: goto x86_l_13b2;
	case 5046ULL: goto x86_l_13b6;
	case 5053ULL: goto x86_l_13bd;
	case 5056ULL: goto x86_l_13c0;
	case 5058ULL: goto x86_l_13c2;
	case 5065ULL: goto x86_l_13c9;
	case 5067ULL: goto x86_l_13cb;
	case 5070ULL: goto x86_l_13ce;
	case 5073ULL: goto x86_l_13d1;
	case 5075ULL: goto x86_l_13d3;
	case 5080ULL: goto x86_l_13d8;
	case 5082ULL: goto x86_l_13da;
	case 5085ULL: goto x86_l_13dd;
	case 5087ULL: goto x86_l_13df;
	case 5089ULL: goto x86_l_13e1;
	case 5092ULL: goto x86_l_13e4;
	case 5094ULL: goto x86_l_13e6;
	case 5098ULL: goto x86_l_13ea;
	case 5101ULL: goto x86_l_13ed;
	case 5108ULL: goto x86_l_13f4;
	case 5110ULL: goto x86_l_13f6;
	case 5117ULL: goto x86_l_13fd;
	case 5120ULL: goto x86_l_1400;
	case 5122ULL: goto x86_l_1402;
	case 5127ULL: goto x86_l_1407;
	case 5129ULL: goto x86_l_1409;
	case 5134ULL: goto x86_l_140e;
	case 5138ULL: goto x86_l_1412;
	case 5141ULL: goto x86_l_1415;
	case 5143ULL: goto x86_l_1417;
	case 5146ULL: goto x86_l_141a;
	case 5152ULL: goto x86_l_1420;
	case 5156ULL: goto x86_l_1424;
	case 5158ULL: goto x86_l_1426;
	case 5164ULL: goto x86_l_142c;
	case 5170ULL: goto x86_l_1432;
	case 5175ULL: goto x86_l_1437;
	case 5179ULL: goto x86_l_143b;
	case 5186ULL: goto x86_l_1442;
	case 5190ULL: goto x86_l_1446;
	case 5196ULL: goto x86_l_144c;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5211ULL: goto x86_l_145b;
	case 5216ULL: goto x86_l_1460;
	case 5220ULL: goto x86_l_1464;
	case 5227ULL: goto x86_l_146b;
	case 5229ULL: goto x86_l_146d;
	case 5236ULL: goto x86_l_1474;
	case 5241ULL: goto x86_l_1479;
	case 5243ULL: goto x86_l_147b;
	case 5250ULL: goto x86_l_1482;
	case 5252ULL: goto x86_l_1484;
	case 5254ULL: goto x86_l_1486;
	case 5258ULL: goto x86_l_148a;
	case 5262ULL: goto x86_l_148e;
	case 5264ULL: goto x86_l_1490;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5279ULL: goto x86_l_149f;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5293ULL: goto x86_l_14ad;
	case 5295ULL: goto x86_l_14af;
	case 5299ULL: goto x86_l_14b3;
	case 5301ULL: goto x86_l_14b5;
	case 5306ULL: goto x86_l_14ba;
	case 5308ULL: goto x86_l_14bc;
	case 5310ULL: goto x86_l_14be;
	case 5314ULL: goto x86_l_14c2;
	case 5324ULL: goto x86_l_14cc;
	case 5327ULL: goto x86_l_14cf;
	case 5332ULL: goto x86_l_14d4;
	case 5336ULL: goto x86_l_14d8;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e7d:
	/* 0xe7d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e80:
	/* 0xe80: movzx  r13d,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_e86:
	/* 0xe86: movzx  r14d,BYTE PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 168ULL);
x86_l_e8f:
	/* 0xe8f: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_e93:
	/* 0xe93: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e98:
	/* 0xe98: jne    ef2 <tail_handle_ipv6+0xef2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ef2;
	}
x86_l_e9a:
	/* 0xe9a: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_e9d:
	/* 0xe9d: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_ea7:
	/* 0xea7: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_eaa:
	/* 0xeaa: jne    ef2 <tail_handle_ipv6+0xef2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ef2;
	}
x86_l_eac:
	/* 0xeac: lea    esi,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eaf:
	/* 0xeaf: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_eb2:
	/* 0xeb2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_eb7:
	/* 0xeb7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_eba:
	/* 0xeba: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ebf:
	/* 0xebf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec1:
	/* 0xec1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ec3:
	/* 0xec3: js     f6e <tail_handle_ipv6+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_f6e;
	}
x86_l_ec9:
	/* 0xec9: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ecd:
	/* 0xecd: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_ed0:
	/* 0xed0: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_ed5:
	/* 0xed5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed8:
	/* 0xed8: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_edd:
	/* 0xedd: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_ee0:
	/* 0xee0: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_ee7:
	/* 0xee7: jne    200e <tail_handle_ipv6+0x200e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8206ULL;
	}
x86_l_eed:
	/* 0xeed: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_ef0:
	/* 0xef0: jmp    ef9 <tail_handle_ipv6+0xef9> */
	goto x86_l_ef9;
x86_l_ef2:
	/* 0xef2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef5:
	/* 0xef5: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef9:
	/* 0xef9: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_efe:
	/* 0xefe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f03:
	/* 0xf03: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_f0b:
	/* 0xf0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f0d:
	/* 0xf0d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f10:
	/* 0xf10: je     211c <tail_handle_ipv6+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8476ULL;
	}
x86_l_f16:
	/* 0xf16: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_f19:
	/* 0xf19: cmp    WORD PTR [rax+0x26],r13w */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_f1e:
	/* 0xf1e: jne    211c <tail_handle_ipv6+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8476ULL;
	}
x86_l_f24:
	/* 0xf24: test   r14d,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 512ULL);
x86_l_f2b:
	/* 0xf2b: mov    DWORD PTR [rsp+0x50],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f30:
	/* 0xf30: je     12ec <tail_handle_ipv6+0x12ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ec;
	}
x86_l_f36:
	/* 0xf36: test   BYTE PTR [rbp+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_f3a:
	/* 0xf3a: je     12ec <tail_handle_ipv6+0x12ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ec;
	}
x86_l_f40:
	/* 0xf40: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f47:
	/* 0xf47: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4a:
	/* 0xf4a: je     12a2 <tail_handle_ipv6+0x12a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12a2;
	}
x86_l_f50:
	/* 0xf50: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f57:
	/* 0xf57: mov    r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f5a:
	/* 0xf5a: lea    ecx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_f5e:
	/* 0xf5e: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_f62:
	/* 0xf62: sub    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f65:
	/* 0xf65: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f69:
	/* 0xf69: jmp    12a8 <tail_handle_ipv6+0x12a8> */
	goto x86_l_12a8;
x86_l_f6e:
	/* 0xf6e: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_f73:
	/* 0xf73: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_f78:
	/* 0xf78: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f84:
	/* 0xf84: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_f8d:
	/* 0xf8d: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_f96:
	/* 0xf96: movzx  r12d,BYTE PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_f9b:
	/* 0xf9b: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_f9f:
	/* 0xf9f: mov    r8,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_fa7:
	/* 0xfa7: ja     1e97 <tail_handle_ipv6+0x1e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7831ULL;
	}
x86_l_fad:
	/* 0xfad: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_fb2:
	/* 0xfb2: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_fbc:
	/* 0xfbc: bt     rax,r12 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_fc0:
	/* 0xfc0: jae    1028 <tail_handle_ipv6+0x1028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1028;
	}
x86_l_fc2:
	/* 0xfc2: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_fc5:
	/* 0xfc5: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_fc8:
	/* 0xfc8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_fcb:
	/* 0xfcb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_fd0:
	/* 0xfd0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fd3:
	/* 0xfd3: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_fd8:
	/* 0xfd8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fdd:
	/* 0xfdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdf:
	/* 0xfdf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fe1:
	/* 0xfe1: js     1667 <tail_handle_ipv6+0x1667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5735ULL;
	}
x86_l_fe7:
	/* 0xfe7: movzx  r15d,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_fec:
	/* 0xfec: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_ff0:
	/* 0xff0: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_ff3:
	/* 0xff3: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_ff6:
	/* 0xff6: jle    1041 <tail_handle_ipv6+0x1041> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1041;
	}
x86_l_ff8:
	/* 0xff8: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_ffc:
	/* 0xffc: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1001:
	/* 0x1001: je     1170 <tail_handle_ipv6+0x1170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1170;
	}
x86_l_1007:
	/* 0x1007: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_100b:
	/* 0x100b: je     1046 <tail_handle_ipv6+0x1046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1046;
	}
x86_l_100d:
	/* 0x100d: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1012:
	/* 0x1012: lea    ebp,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1019:
	/* 0x1019: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_101d:
	/* 0x101d: jbe    117f <tail_handle_ipv6+0x117f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_117f;
	}
x86_l_1023:
	/* 0x1023: jmp    1e97 <tail_handle_ipv6+0x1e97> */
	return 7831ULL;
x86_l_1028:
	/* 0x1028: cmp    r12,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 59ULL);
x86_l_102c:
	/* 0x102c: je     1672 <tail_handle_ipv6+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5746ULL;
	}
x86_l_1032:
	/* 0x1032: jmp    1e97 <tail_handle_ipv6+0x1e97> */
	return 7831ULL;
x86_l_1037:
	/* 0x1037: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_103c:
	/* 0x103c: jmp    1297 <tail_handle_ipv6+0x1297> */
	goto x86_l_1297;
x86_l_1041:
	/* 0x1041: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1046:
	/* 0x1046: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_104b:
	/* 0x104b: lea    ebp,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1052:
	/* 0x1052: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1056:
	/* 0x1056: jne    1175 <tail_handle_ipv6+0x1175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1175;
	}
x86_l_105c:
	/* 0x105c: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_105f:
	/* 0x105f: jne    1175 <tail_handle_ipv6+0x1175> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1175;
	}
x86_l_1065:
	/* 0x1065: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_106a:
	/* 0x106a: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_106f:
	/* 0x106f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1074:
	/* 0x1074: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1077:
	/* 0x1077: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_107c:
	/* 0x107c: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1081:
	/* 0x1081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1083:
	/* 0x1083: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1085:
	/* 0x1085: js     1e70 <tail_handle_ipv6+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7792ULL;
	}
x86_l_108b:
	/* 0x108b: cmp    BYTE PTR [rsp+0x5a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 386547056667ULL);
x86_l_1090:
	/* 0x1090: jne    1ac3 <tail_handle_ipv6+0x1ac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6851ULL;
	}
x86_l_1096:
	/* 0x1096: cmp    BYTE PTR [rsp+0x5b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 390842023956ULL);
x86_l_109b:
	/* 0x109b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_109e:
	/* 0x109e: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_10a1:
	/* 0x10a1: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_10a6:
	/* 0x10a6: je     1e40 <tail_handle_ipv6+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_10ac:
	/* 0x10ac: jmp    1175 <tail_handle_ipv6+0x1175> */
	goto x86_l_1175;
x86_l_10b1:
	/* 0x10b1: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_10b3:
	/* 0x10b3: mov    BYTE PTR [rsp],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b6:
	/* 0x10b6: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_10b9:
	/* 0x10b9: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_10bf:
	/* 0x10bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10c2:
	/* 0x10c2: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_10c7:
	/* 0x10c7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10cc:
	/* 0x10cc: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_10d2:
	/* 0x10d2: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_10d5:
	/* 0x10d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10d7:
	/* 0x10d7: js     1292 <tail_handle_ipv6+0x1292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1292;
	}
x86_l_10dd:
	/* 0x10dd: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10e2:
	/* 0x10e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10e5:
	/* 0x10e5: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_10ea:
	/* 0x10ea: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10ef:
	/* 0x10ef: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f2:
	/* 0x10f2: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_10f5:
	/* 0x10f5: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_10fa:
	/* 0x10fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10fc:
	/* 0x10fc: js     1297 <tail_handle_ipv6+0x1297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1297;
	}
x86_l_1102:
	/* 0x1102: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1107:
	/* 0x1107: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_110c:
	/* 0x110c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_110f:
	/* 0x110f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1111:
	/* 0x1111: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1116:
	/* 0x1116: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1119:
	/* 0x1119: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111b:
	/* 0x111b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_111d:
	/* 0x111d: js     1297 <tail_handle_ipv6+0x1297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1297;
	}
x86_l_1123:
	/* 0x1123: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_112a:
	/* 0x112a: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112c:
	/* 0x112c: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1131:
	/* 0x1131: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1133:
	/* 0x1133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1135:
	/* 0x1135: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1137:
	/* 0x1137: jmp    1297 <tail_handle_ipv6+0x1297> */
	goto x86_l_1297;
x86_l_113c:
	/* 0x113c: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1143:
	/* 0x1143: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_1148:
	/* 0x1148: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_114d:
	/* 0x114d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1152:
	/* 0x1152: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1154:
	/* 0x1154: mov    BYTE PTR [rsp+0x35],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_1159:
	/* 0x1159: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_115b:
	/* 0x115b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_115e:
	/* 0x115e: je     1252 <tail_handle_ipv6+0x1252> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1252;
	}
x86_l_1164:
	/* 0x1164: movzx  eax,BYTE PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1168:
	/* 0x1168: shr    al,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 7ULL);
x86_l_116b:
	/* 0x116b: jmp    1254 <tail_handle_ipv6+0x1254> */
	goto x86_l_1254;
x86_l_1170:
	/* 0x1170: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1175:
	/* 0x1175: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_1179:
	/* 0x1179: ja     1e97 <tail_handle_ipv6+0x1e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7831ULL;
	}
x86_l_117f:
	/* 0x117f: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_1182:
	/* 0x1182: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_118c:
	/* 0x118c: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1190:
	/* 0x1190: jae    1283 <tail_handle_ipv6+0x1283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1283;
	}
x86_l_1196:
	/* 0x1196: add    ebp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1199:
	/* 0x1199: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_119c:
	/* 0x119c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_11a1:
	/* 0x11a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11a4:
	/* 0x11a4: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_11a6:
	/* 0x11a6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11ab:
	/* 0x11ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ad:
	/* 0x11ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11af:
	/* 0x11af: js     1667 <tail_handle_ipv6+0x1667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5735ULL;
	}
x86_l_11b5:
	/* 0x11b5: movzx  r12d,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11ba:
	/* 0x11ba: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_11be:
	/* 0x11be: jle    11ec <tail_handle_ipv6+0x11ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_11ec;
	}
x86_l_11c0:
	/* 0x11c0: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_11c4:
	/* 0x11c4: je     15ea <tail_handle_ipv6+0x15ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5610ULL;
	}
x86_l_11ca:
	/* 0x11ca: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_11ce:
	/* 0x11ce: jne    11ec <tail_handle_ipv6+0x11ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11ec;
	}
x86_l_11d0:
	/* 0x11d0: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_11d5:
	/* 0x11d5: lea    r9d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_11dd:
	/* 0x11dd: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_11e1:
	/* 0x11e1: jbe    15fa <tail_handle_ipv6+0x15fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 5626ULL;
	}
x86_l_11e7:
	/* 0x11e7: jmp    1e97 <tail_handle_ipv6+0x1e97> */
	return 7831ULL;
x86_l_11ec:
	/* 0x11ec: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_11f1:
	/* 0x11f1: lea    r9d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_11f9:
	/* 0x11f9: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_11fd:
	/* 0x11fd: jne    15f0 <tail_handle_ipv6+0x15f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5616ULL;
	}
x86_l_1203:
	/* 0x1203: cmp    r9d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 24ULL);
x86_l_1207:
	/* 0x1207: jne    15f0 <tail_handle_ipv6+0x15f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5616ULL;
	}
x86_l_120d:
	/* 0x120d: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1212:
	/* 0x1212: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1217:
	/* 0x1217: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_121a:
	/* 0x121a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_121c:
	/* 0x121c: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1221:
	/* 0x1221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1223:
	/* 0x1223: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1225:
	/* 0x1225: js     1e70 <tail_handle_ipv6+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7792ULL;
	}
x86_l_122b:
	/* 0x122b: cmp    BYTE PTR [rsp+0x5a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 386547056667ULL);
x86_l_1230:
	/* 0x1230: jne    1f0d <tail_handle_ipv6+0x1f0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7949ULL;
	}
x86_l_1236:
	/* 0x1236: cmp    BYTE PTR [rsp+0x5b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 390842023956ULL);
x86_l_123b:
	/* 0x123b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_123e:
	/* 0x123e: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1241:
	/* 0x1241: mov    r9d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 24ULL);
x86_l_1247:
	/* 0x1247: je     1e40 <tail_handle_ipv6+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_124d:
	/* 0x124d: jmp    15f0 <tail_handle_ipv6+0x15f0> */
	return 5616ULL;
x86_l_1252:
	/* 0x1252: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1254:
	/* 0x1254: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1257:
	/* 0x1257: mov    r8,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_125f:
	/* 0x125f: mov    WORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1269:
	/* 0x1269: jmp    167b <tail_handle_ipv6+0x167b> */
	return 5755ULL;
x86_l_126e:
	/* 0x126e: shl    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1271:
	/* 0x1271: or     eax,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_1276:
	/* 0x1276: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1279:
	/* 0x1279: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_127c:
	/* 0x127c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_127e:
	/* 0x127e: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_1283:
	/* 0x1283: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_1287:
	/* 0x1287: je     1672 <tail_handle_ipv6+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5746ULL;
	}
x86_l_128d:
	/* 0x128d: jmp    1e97 <tail_handle_ipv6+0x1e97> */
	return 7831ULL;
x86_l_1292:
	/* 0x1292: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1297:
	/* 0x1297: mov    eax,DWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_129a:
	/* 0x129a: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_129d:
	/* 0x129d: jmp    2bfe <tail_handle_ipv6+0x2bfe> */
	return 11262ULL;
x86_l_12a2:
	/* 0x12a2: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_12a8:
	/* 0x12a8: add    r14d,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_12ac:
	/* 0x12ac: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12af:
	/* 0x12af: je     12c0 <tail_handle_ipv6+0x12c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c0;
	}
x86_l_12b1:
	/* 0x12b1: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_12b6:
	/* 0x12b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b8:
	/* 0x12b8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12ba:
	/* 0x12ba: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_12be:
	/* 0x12be: jmp    12e3 <tail_handle_ipv6+0x12e3> */
	goto x86_l_12e3;
x86_l_12c0:
	/* 0x12c0: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_12c5:
	/* 0x12c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c7:
	/* 0x12c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12c9:
	/* 0x12c9: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_12cd:
	/* 0x12cd: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_12d7:
	/* 0x12d7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_12da:
	/* 0x12da: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_12df:
	/* 0x12df: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_12e3:
	/* 0x12e3: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_12e6:
	/* 0x12e6: jae    211c <tail_handle_ipv6+0x211c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8476ULL;
	}
x86_l_12ec:
	/* 0x12ec: mov    DWORD PTR [rsp+0x54],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_12f1:
	/* 0x12f1: mov    eax,DWORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12f4:
	/* 0x12f4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_12f6:
	/* 0x12f6: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_12f8:
	/* 0x12f8: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_12fb:
	/* 0x12fb: je     13f6 <tail_handle_ipv6+0x13f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f6;
	}
x86_l_1301:
	/* 0x1301: mov    rdx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1308:
	/* 0x1308: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130b:
	/* 0x130b: je     131e <tail_handle_ipv6+0x131e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_131e;
	}
x86_l_130d:
	/* 0x130d: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1314:
	/* 0x1314: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1318:
	/* 0x1318: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_131c:
	/* 0x131c: jmp    1324 <tail_handle_ipv6+0x1324> */
	goto x86_l_1324;
x86_l_131e:
	/* 0x131e: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1324:
	/* 0x1324: mov    r15d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1329:
	/* 0x1329: cmp    BYTE PTR [rsp+0xa8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505734ULL);
x86_l_1331:
	/* 0x1331: jne    1369 <tail_handle_ipv6+0x1369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1369;
	}
x86_l_1333:
	/* 0x1333: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1336:
	/* 0x1336: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1338:
	/* 0x1338: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_133b:
	/* 0x133b: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_133e:
	/* 0x133e: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1340:
	/* 0x1340: mov    WORD PTR [rbp+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1344:
	/* 0x1344: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_1346:
	/* 0x1346: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_134b:
	/* 0x134b: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_1351:
	/* 0x1351: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1355:
	/* 0x1355: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1358:
	/* 0x1358: je     1369 <tail_handle_ipv6+0x1369> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1369;
	}
x86_l_135a:
	/* 0x135a: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1361:
	/* 0x1361: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1365:
	/* 0x1365: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1369:
	/* 0x1369: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_136d:
	/* 0x136d: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1370:
	/* 0x1370: je     1381 <tail_handle_ipv6+0x1381> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1381;
	}
x86_l_1372:
	/* 0x1372: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1377:
	/* 0x1377: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1379:
	/* 0x1379: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_137b:
	/* 0x137b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_137f:
	/* 0x137f: jmp    13a4 <tail_handle_ipv6+0x13a4> */
	goto x86_l_13a4;
x86_l_1381:
	/* 0x1381: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1386:
	/* 0x1386: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1388:
	/* 0x1388: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_138a:
	/* 0x138a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_138e:
	/* 0x138e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1398:
	/* 0x1398: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_139b:
	/* 0x139b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_13a0:
	/* 0x13a0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_13a4:
	/* 0x13a4: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13a7:
	/* 0x13a7: mov    DWORD PTR [rbp+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13ab:
	/* 0x13ab: movzx  ecx,BYTE PTR [rbp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_13af:
	/* 0x13af: mov    edx,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13b2:
	/* 0x13b2: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_13b6:
	/* 0x13b6: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_13bd:
	/* 0x13bd: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c0:
	/* 0x13c0: je     13d3 <tail_handle_ipv6+0x13d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d3;
	}
x86_l_13c2:
	/* 0x13c2: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_13c9:
	/* 0x13c9: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13cb:
	/* 0x13cb: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_13ce:
	/* 0x13ce: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13d1:
	/* 0x13d1: jmp    13d8 <tail_handle_ipv6+0x13d8> */
	goto x86_l_13d8;
x86_l_13d3:
	/* 0x13d3: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_13d8:
	/* 0x13d8: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13da:
	/* 0x13da: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_13dd:
	/* 0x13dd: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_13df:
	/* 0x13df: jb     13e6 <tail_handle_ipv6+0x13e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_13e6;
	}
x86_l_13e1:
	/* 0x13e1: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_13e4:
	/* 0x13e4: je     13f6 <tail_handle_ipv6+0x13f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13f6;
	}
x86_l_13e6:
	/* 0x13e6: mov    BYTE PTR [rbp+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_13ea:
	/* 0x13ea: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ed:
	/* 0x13ed: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_13f4:
	/* 0x13f4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f6:
	/* 0x13f6: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_13fd:
	/* 0x13fd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1400:
	/* 0x1400: je     140e <tail_handle_ipv6+0x140e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_140e;
	}
x86_l_1402:
	/* 0x1402: inc QWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1407:
	/* 0x1407: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1409:
	/* 0x1409: add QWORD PTR [rbp+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RBP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_140e:
	/* 0x140e: mov    eax,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1412:
	/* 0x1412: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1415:
	/* 0x1415: je     1460 <tail_handle_ipv6+0x1460> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1460;
	}
x86_l_1417:
	/* 0x1417: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141a:
	/* 0x141a: jne    1525 <tail_handle_ipv6+0x1525> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5413ULL;
	}
x86_l_1420:
	/* 0x1420: movzx  eax,WORD PTR [rbp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1424:
	/* 0x1424: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1426:
	/* 0x1426: je     1525 <tail_handle_ipv6+0x1525> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5413ULL;
	}
x86_l_142c:
	/* 0x142c: mov    WORD PTR [rbp+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1432:
	/* 0x1432: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1437:
	/* 0x1437: mov    WORD PTR [rbp+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_143b:
	/* 0x143b: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1442:
	/* 0x1442: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1446:
	/* 0x1446: je     203c <tail_handle_ipv6+0x203c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8252ULL;
	}
x86_l_144c:
	/* 0x144c: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1453:
	/* 0x1453: imul   r15d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1457:
	/* 0x1457: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_145b:
	/* 0x145b: jmp    2042 <tail_handle_ipv6+0x2042> */
	return 8258ULL;
x86_l_1460:
	/* 0x1460: or     BYTE PTR [rbp+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_1464:
	/* 0x1464: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_146b:
	/* 0x146b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146d:
	/* 0x146d: mov    r13,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1474:
	/* 0x1474: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1479:
	/* 0x1479: je     1490 <tail_handle_ipv6+0x1490> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1490;
	}
x86_l_147b:
	/* 0x147b: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1482:
	/* 0x1482: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1484:
	/* 0x1484: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1486:
	/* 0x1486: lea    r14d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_148a:
	/* 0x148a: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_148e:
	/* 0x148e: jmp    1496 <tail_handle_ipv6+0x1496> */
	goto x86_l_1496;
x86_l_1490:
	/* 0x1490: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_1496:
	/* 0x1496: mov    r15d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_149b:
	/* 0x149b: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_149f:
	/* 0x149f: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a4:
	/* 0x14a4: je     14b5 <tail_handle_ipv6+0x14b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b5;
	}
x86_l_14a6:
	/* 0x14a6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_14ab:
	/* 0x14ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ad:
	/* 0x14ad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14af:
	/* 0x14af: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_14b3:
	/* 0x14b3: jmp    14d8 <tail_handle_ipv6+0x14d8> */
	goto x86_l_14d8;
x86_l_14b5:
	/* 0x14b5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_14ba:
	/* 0x14ba: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14bc:
	/* 0x14bc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14be:
	/* 0x14be: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_14c2:
	/* 0x14c2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_14cc:
	/* 0x14cc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_14cf:
	/* 0x14cf: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14d4:
	/* 0x14d4: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_14d8:
	/* 0x14d8: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
	return 5339ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5339ULL: goto x86_l_14db;
	case 5343ULL: goto x86_l_14df;
	case 5347ULL: goto x86_l_14e3;
	case 5350ULL: goto x86_l_14e6;
	case 5354ULL: goto x86_l_14ea;
	case 5359ULL: goto x86_l_14ef;
	case 5361ULL: goto x86_l_14f1;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5373ULL: goto x86_l_14fd;
	case 5376ULL: goto x86_l_1500;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	case 5388ULL: goto x86_l_150c;
	case 5390ULL: goto x86_l_150e;
	case 5392ULL: goto x86_l_1510;
	case 5395ULL: goto x86_l_1513;
	case 5397ULL: goto x86_l_1515;
	case 5401ULL: goto x86_l_1519;
	case 5404ULL: goto x86_l_151c;
	case 5411ULL: goto x86_l_1523;
	case 5413ULL: goto x86_l_1525;
	case 5421ULL: goto x86_l_152d;
	case 5423ULL: goto x86_l_152f;
	case 5428ULL: goto x86_l_1534;
	case 5432ULL: goto x86_l_1538;
	case 5437ULL: goto x86_l_153d;
	case 5444ULL: goto x86_l_1544;
	case 5449ULL: goto x86_l_1549;
	case 5454ULL: goto x86_l_154e;
	case 5456ULL: goto x86_l_1550;
	case 5459ULL: goto x86_l_1553;
	case 5461ULL: goto x86_l_1555;
	case 5464ULL: goto x86_l_1558;
	case 5470ULL: goto x86_l_155e;
	case 5474ULL: goto x86_l_1562;
	case 5480ULL: goto x86_l_1568;
	case 5485ULL: goto x86_l_156d;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5507ULL: goto x86_l_1583;
	case 5510ULL: goto x86_l_1586;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5526ULL: goto x86_l_1596;
	case 5529ULL: goto x86_l_1599;
	case 5534ULL: goto x86_l_159e;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5541ULL: goto x86_l_15a5;
	case 5546ULL: goto x86_l_15aa;
	case 5548ULL: goto x86_l_15ac;
	case 5550ULL: goto x86_l_15ae;
	case 5552ULL: goto x86_l_15b0;
	case 5560ULL: goto x86_l_15b8;
	case 5567ULL: goto x86_l_15bf;
	case 5571ULL: goto x86_l_15c3;
	case 5578ULL: goto x86_l_15ca;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5593ULL: goto x86_l_15d9;
	case 5596ULL: goto x86_l_15dc;
	case 5602ULL: goto x86_l_15e2;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5616ULL: goto x86_l_15f0;
	case 5620ULL: goto x86_l_15f4;
	case 5626ULL: goto x86_l_15fa;
	case 5629ULL: goto x86_l_15fd;
	case 5639ULL: goto x86_l_1607;
	case 5643ULL: goto x86_l_160b;
	case 5649ULL: goto x86_l_1611;
	case 5652ULL: goto x86_l_1614;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5663ULL: goto x86_l_161f;
	case 5666ULL: goto x86_l_1622;
	case 5669ULL: goto x86_l_1625;
	case 5674ULL: goto x86_l_162a;
	case 5676ULL: goto x86_l_162c;
	case 5678ULL: goto x86_l_162e;
	case 5680ULL: goto x86_l_1630;
	case 5684ULL: goto x86_l_1634;
	case 5688ULL: goto x86_l_1638;
	case 5692ULL: goto x86_l_163c;
	case 5698ULL: goto x86_l_1642;
	case 5702ULL: goto x86_l_1646;
	case 5708ULL: goto x86_l_164c;
	case 5712ULL: goto x86_l_1650;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5743ULL: goto x86_l_166f;
	case 5746ULL: goto x86_l_1672;
	case 5748ULL: goto x86_l_1674;
	case 5755ULL: goto x86_l_167b;
	case 5765ULL: goto x86_l_1685;
	case 5767ULL: goto x86_l_1687;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5781ULL: goto x86_l_1695;
	case 5789ULL: goto x86_l_169d;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5807ULL: goto x86_l_16af;
	case 5815ULL: goto x86_l_16b7;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5833ULL: goto x86_l_16c9;
	case 5841ULL: goto x86_l_16d1;
	case 5850ULL: goto x86_l_16da;
	case 5858ULL: goto x86_l_16e2;
	case 5862ULL: goto x86_l_16e6;
	case 5864ULL: goto x86_l_16e8;
	case 5871ULL: goto x86_l_16ef;
	case 5873ULL: goto x86_l_16f1;
	case 5880ULL: goto x86_l_16f8;
	case 5888ULL: goto x86_l_1700;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5905ULL: goto x86_l_1711;
	case 5915ULL: goto x86_l_171b;
	case 5918ULL: goto x86_l_171e;
	case 5924ULL: goto x86_l_1724;
	case 5932ULL: goto x86_l_172c;
	case 5937ULL: goto x86_l_1731;
	case 5940ULL: goto x86_l_1734;
	case 5943ULL: goto x86_l_1737;
	case 5946ULL: goto x86_l_173a;
	case 5949ULL: goto x86_l_173d;
	case 5952ULL: goto x86_l_1740;
	case 5961ULL: goto x86_l_1749;
	case 5970ULL: goto x86_l_1752;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6004ULL: goto x86_l_1774;
	case 6007ULL: goto x86_l_1777;
	case 6009ULL: goto x86_l_1779;
	case 6012ULL: goto x86_l_177c;
	case 6016ULL: goto x86_l_1780;
	case 6018ULL: goto x86_l_1782;
	case 6027ULL: goto x86_l_178b;
	case 6032ULL: goto x86_l_1790;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6049ULL: goto x86_l_17a1;
	case 6054ULL: goto x86_l_17a6;
	case 6056ULL: goto x86_l_17a8;
	case 6058ULL: goto x86_l_17aa;
	case 6061ULL: goto x86_l_17ad;
	case 6064ULL: goto x86_l_17b0;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6083ULL: goto x86_l_17c3;
	case 6087ULL: goto x86_l_17c7;
	case 6089ULL: goto x86_l_17c9;
	case 6092ULL: goto x86_l_17cc;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6100ULL: goto x86_l_17d4;
	case 6103ULL: goto x86_l_17d7;
	case 6108ULL: goto x86_l_17dc;
	case 6111ULL: goto x86_l_17df;
	case 6116ULL: goto x86_l_17e4;
	case 6118ULL: goto x86_l_17e6;
	case 6120ULL: goto x86_l_17e8;
	case 6126ULL: goto x86_l_17ee;
	case 6130ULL: goto x86_l_17f2;
	case 6133ULL: goto x86_l_17f5;
	case 6138ULL: goto x86_l_17fa;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6149ULL: goto x86_l_1805;
	case 6156ULL: goto x86_l_180c;
	case 6162ULL: goto x86_l_1812;
	case 6165ULL: goto x86_l_1815;
	case 6168ULL: goto x86_l_1818;
	case 6170ULL: goto x86_l_181a;
	case 6173ULL: goto x86_l_181d;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6192ULL: goto x86_l_1830;
	case 6194ULL: goto x86_l_1832;
	case 6197ULL: goto x86_l_1835;
	case 6201ULL: goto x86_l_1839;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6212ULL: goto x86_l_1844;
	case 6214ULL: goto x86_l_1846;
	case 6218ULL: goto x86_l_184a;
	case 6220ULL: goto x86_l_184c;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6257ULL: goto x86_l_1871;
	case 6259ULL: goto x86_l_1873;
	case 6261ULL: goto x86_l_1875;
	case 6264ULL: goto x86_l_1878;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6284ULL: goto x86_l_188c;
	case 6291ULL: goto x86_l_1893;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6306ULL: goto x86_l_18a2;
	case 6310ULL: goto x86_l_18a6;
	case 6314ULL: goto x86_l_18aa;
	case 6316ULL: goto x86_l_18ac;
	case 6321ULL: goto x86_l_18b1;
	case 6323ULL: goto x86_l_18b3;
	case 6329ULL: goto x86_l_18b9;
	case 6334ULL: goto x86_l_18be;
	case 6336ULL: goto x86_l_18c0;
	case 6340ULL: goto x86_l_18c4;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6348ULL: goto x86_l_18cc;
	case 6350ULL: goto x86_l_18ce;
	case 6355ULL: goto x86_l_18d3;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6377ULL: goto x86_l_18e9;
	case 6379ULL: goto x86_l_18eb;
	case 6386ULL: goto x86_l_18f2;
	case 6390ULL: goto x86_l_18f6;
	case 6394ULL: goto x86_l_18fa;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6415ULL: goto x86_l_190f;
	case 6417ULL: goto x86_l_1911;
	case 6421ULL: goto x86_l_1915;
	case 6423ULL: goto x86_l_1917;
	case 6428ULL: goto x86_l_191c;
	case 6430ULL: goto x86_l_191e;
	case 6432ULL: goto x86_l_1920;
	case 6436ULL: goto x86_l_1924;
	case 6446ULL: goto x86_l_192e;
	case 6449ULL: goto x86_l_1931;
	case 6454ULL: goto x86_l_1936;
	case 6458ULL: goto x86_l_193a;
	case 6461ULL: goto x86_l_193d;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6474ULL: goto x86_l_194a;
	case 6478ULL: goto x86_l_194e;
	case 6483ULL: goto x86_l_1953;
	case 6485ULL: goto x86_l_1955;
	case 6492ULL: goto x86_l_195c;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6500ULL: goto x86_l_1964;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6514ULL: goto x86_l_1972;
	case 6523ULL: goto x86_l_197b;
	case 6528ULL: goto x86_l_1980;
	case 6530ULL: goto x86_l_1982;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6539ULL: goto x86_l_198b;
	case 6543ULL: goto x86_l_198f;
	case 6550ULL: goto x86_l_1996;
	case 6552ULL: goto x86_l_1998;
	case 6559ULL: goto x86_l_199f;
	case 6562ULL: goto x86_l_19a2;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6580ULL: goto x86_l_19b4;
	case 6582ULL: goto x86_l_19b6;
	case 6586ULL: goto x86_l_19ba;
	case 6592ULL: goto x86_l_19c0;
	case 6597ULL: goto x86_l_19c5;
	case 6599ULL: goto x86_l_19c7;
	case 6605ULL: goto x86_l_19cd;
	case 6612ULL: goto x86_l_19d4;
	case 6617ULL: goto x86_l_19d9;
	case 6622ULL: goto x86_l_19de;
	case 6629ULL: goto x86_l_19e5;
	case 6633ULL: goto x86_l_19e9;
	case 6639ULL: goto x86_l_19ef;
	case 6646ULL: goto x86_l_19f6;
	case 6649ULL: goto x86_l_19f9;
	case 6652ULL: goto x86_l_19fc;
	case 6657ULL: goto x86_l_1a01;
	case 6660ULL: goto x86_l_1a04;
	case 6665ULL: goto x86_l_1a09;
	case 6668ULL: goto x86_l_1a0c;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6693ULL: goto x86_l_1a25;
	case 6695ULL: goto x86_l_1a27;
	case 6697ULL: goto x86_l_1a29;
	case 6703ULL: goto x86_l_1a2f;
	case 6710ULL: goto x86_l_1a36;
	case 6714ULL: goto x86_l_1a3a;
	case 6720ULL: goto x86_l_1a40;
	case 6727ULL: goto x86_l_1a47;
	case 6729ULL: goto x86_l_1a49;
	case 6731ULL: goto x86_l_1a4b;
	case 6734ULL: goto x86_l_1a4e;
	case 6737ULL: goto x86_l_1a51;
	case 6742ULL: goto x86_l_1a56;
	case 6747ULL: goto x86_l_1a5b;
	case 6754ULL: goto x86_l_1a62;
	case 6758ULL: goto x86_l_1a66;
	case 6764ULL: goto x86_l_1a6c;
	case 6767ULL: goto x86_l_1a6f;
	case 6773ULL: goto x86_l_1a75;
	case 6776ULL: goto x86_l_1a78;
	case 6781ULL: goto x86_l_1a7d;
	case 6786ULL: goto x86_l_1a82;
	case 6791ULL: goto x86_l_1a87;
	case 6794ULL: goto x86_l_1a8a;
	case 6799ULL: goto x86_l_1a8f;
	case 6801ULL: goto x86_l_1a91;
	case 6803ULL: goto x86_l_1a93;
	case 6809ULL: goto x86_l_1a99;
	case 6814ULL: goto x86_l_1a9e;
	case 6820ULL: goto x86_l_1aa4;
	case 6825ULL: goto x86_l_1aa9;
	case 6828ULL: goto x86_l_1aac;
	case 6831ULL: goto x86_l_1aaf;
	case 6837ULL: goto x86_l_1ab5;
	case 6842ULL: goto x86_l_1aba;
	case 6846ULL: goto x86_l_1abe;
	case 6851ULL: goto x86_l_1ac3;
	case 6854ULL: goto x86_l_1ac6;
	case 6857ULL: goto x86_l_1ac9;
	case 6862ULL: goto x86_l_1ace;
	case 6866ULL: goto x86_l_1ad2;
	case 6872ULL: goto x86_l_1ad8;
	case 6877ULL: goto x86_l_1add;
	case 6881ULL: goto x86_l_1ae1;
	case 6886ULL: goto x86_l_1ae6;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6904ULL: goto x86_l_1af8;
	case 6907ULL: goto x86_l_1afb;
	case 6910ULL: goto x86_l_1afe;
	case 6916ULL: goto x86_l_1b04;
	case 6919ULL: goto x86_l_1b07;
	case 6924ULL: goto x86_l_1b0c;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6946ULL: goto x86_l_1b22;
	case 6949ULL: goto x86_l_1b25;
	case 6952ULL: goto x86_l_1b28;
	case 6958ULL: goto x86_l_1b2e;
	case 6961ULL: goto x86_l_1b31;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6988ULL: goto x86_l_1b4c;
	case 6992ULL: goto x86_l_1b50;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	default: return 0xffffffffffffffffULL;
	}
x86_l_14db:
	/* 0x14db: mov    DWORD PTR [rbp+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14df:
	/* 0x14df: movzx  ecx,BYTE PTR [rbp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_14e3:
	/* 0x14e3: mov    edx,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14e6:
	/* 0x14e6: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_14ea:
	/* 0x14ea: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ef:
	/* 0x14ef: je     1502 <tail_handle_ipv6+0x1502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1502;
	}
x86_l_14f1:
	/* 0x14f1: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_14f8:
	/* 0x14f8: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fa:
	/* 0x14fa: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_14fd:
	/* 0x14fd: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1500:
	/* 0x1500: jmp    1507 <tail_handle_ipv6+0x1507> */
	goto x86_l_1507;
x86_l_1502:
	/* 0x1502: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1507:
	/* 0x1507: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1509:
	/* 0x1509: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_150c:
	/* 0x150c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_150e:
	/* 0x150e: jb     1515 <tail_handle_ipv6+0x1515> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1515;
	}
x86_l_1510:
	/* 0x1510: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_1513:
	/* 0x1513: je     1525 <tail_handle_ipv6+0x1525> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1525;
	}
x86_l_1515:
	/* 0x1515: mov    BYTE PTR [rbp+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1519:
	/* 0x1519: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_151c:
	/* 0x151c: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1523:
	/* 0x1523: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1525:
	/* 0x1525: test   BYTE PTR [rsp+0x95],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 639950127106ULL);
x86_l_152d:
	/* 0x152d: jne    1572 <tail_handle_ipv6+0x1572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1572;
	}
x86_l_152f:
	/* 0x152f: movzx  r14d,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1534:
	/* 0x1534: mov    r15d,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1538:
	/* 0x1538: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_153d:
	/* 0x153d: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_1544:
	/* 0x1544: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1549:
	/* 0x1549: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_154e:
	/* 0x154e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1550:
	/* 0x1550: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1553:
	/* 0x1553: je     157c <tail_handle_ipv6+0x157c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157c;
	}
x86_l_1555:
	/* 0x1555: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1558:
	/* 0x1558: mov    WORD PTR [rsp+0x54],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_155e:
	/* 0x155e: cmp    BYTE PTR [rax+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_1562:
	/* 0x1562: jne    2024 <tail_handle_ipv6+0x2024> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8228ULL;
	}
x86_l_1568:
	/* 0x1568: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_156d:
	/* 0x156d: jmp    24ca <tail_handle_ipv6+0x24ca> */
	return 9418ULL;
x86_l_1572:
	/* 0x1572: mov    ecx,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967133ULL);
x86_l_1577:
	/* 0x1577: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_157c:
	/* 0x157c: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1583:
	/* 0x1583: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1586:
	/* 0x1586: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_158b:
	/* 0x158b: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1590:
	/* 0x1590: je     2394 <tail_handle_ipv6+0x2394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9108ULL;
	}
x86_l_1596:
	/* 0x1596: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1599:
	/* 0x1599: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_159e:
	/* 0x159e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a0:
	/* 0x15a0: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_15a3:
	/* 0x15a3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15a5:
	/* 0x15a5: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_15aa:
	/* 0x15aa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ac:
	/* 0x15ac: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_15ae:
	/* 0x15ae: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_15b0:
	/* 0x15b0: mov    WORD PTR [rsp+0xc2],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_15b8:
	/* 0x15b8: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_15bf:
	/* 0x15bf: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15c3:
	/* 0x15c3: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_15ca:
	/* 0x15ca: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15d2:
	/* 0x15d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d7:
	/* 0x15d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d9:
	/* 0x15d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15dc:
	/* 0x15dc: je     1add <tail_handle_ipv6+0x1add> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1add;
	}
x86_l_15e2:
	/* 0x15e2: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e5:
	/* 0x15e5: jmp    1ae1 <tail_handle_ipv6+0x1ae1> */
	goto x86_l_1ae1;
x86_l_15ea:
	/* 0x15ea: mov    r9d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 8ULL);
x86_l_15f0:
	/* 0x15f0: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_15f4:
	/* 0x15f4: ja     1e97 <tail_handle_ipv6+0x1e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7831ULL;
	}
x86_l_15fa:
	/* 0x15fa: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_15fd:
	/* 0x15fd: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1607:
	/* 0x1607: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: jae    1aba <tail_handle_ipv6+0x1aba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1aba;
	}
x86_l_1611:
	/* 0x1611: add    r9d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1614:
	/* 0x1614: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1617:
	/* 0x1617: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_161c:
	/* 0x161c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_161f:
	/* 0x161f: mov    r15d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_32);
x86_l_1622:
	/* 0x1622: mov    esi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R9, X86_WIDTH_32);
x86_l_1625:
	/* 0x1625: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_162a:
	/* 0x162a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162c:
	/* 0x162c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_162e:
	/* 0x162e: js     1667 <tail_handle_ipv6+0x1667> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1667;
	}
x86_l_1630:
	/* 0x1630: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1634:
	/* 0x1634: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1638:
	/* 0x1638: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_163c:
	/* 0x163c: jle    1a56 <tail_handle_ipv6+0x1a56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1a56;
	}
x86_l_1642:
	/* 0x1642: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_1646:
	/* 0x1646: je     1d84 <tail_handle_ipv6+0x1d84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7556ULL;
	}
x86_l_164c:
	/* 0x164c: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_1650:
	/* 0x1650: jne    1a56 <tail_handle_ipv6+0x1a56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a56;
	}
x86_l_1656:
	/* 0x1656: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_165b:
	/* 0x165b: lea    ebp,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1662:
	/* 0x1662: jmp    1d89 <tail_handle_ipv6+0x1d89> */
	return 7561ULL;
x86_l_1667:
	/* 0x1667: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_166c:
	/* 0x166c: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_166f:
	/* 0x166f: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1672:
	/* 0x1672: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1674:
	/* 0x1674: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_167b:
	/* 0x167b: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_1685:
	/* 0x1685: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1687:
	/* 0x1687: js     2006 <tail_handle_ipv6+0x2006> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8198ULL;
	}
x86_l_168d:
	/* 0x168d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_168f:
	/* 0x168f: je     1ecd <tail_handle_ipv6+0x1ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7885ULL;
	}
x86_l_1695:
	/* 0x1695: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_169d:
	/* 0x169d: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16a5:
	/* 0x16a5: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16aa:
	/* 0x16aa: mov    rdi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16af:
	/* 0x16af: mov    QWORD PTR [rsp+0x88],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16b7:
	/* 0x16b7: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16bf:
	/* 0x16bf: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16c4:
	/* 0x16c4: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16c9:
	/* 0x16c9: rol    DWORD PTR [rsp+0x90],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 618475290640ULL);
x86_l_16d1:
	/* 0x16d1: movzx  r13d,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_16da:
	/* 0x16da: movzx  ebp,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_16e2:
	/* 0x16e2: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_16e6:
	/* 0x16e6: jne    16f1 <tail_handle_ipv6+0x16f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f1;
	}
x86_l_16e8:
	/* 0x16e8: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_16ef:
	/* 0x16ef: jmp    16f8 <tail_handle_ipv6+0x16f8> */
	goto x86_l_16f8;
x86_l_16f1:
	/* 0x16f1: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_16f8:
	/* 0x16f8: mov    BYTE PTR [rsp+0x95],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 639950127104ULL);
x86_l_1700:
	/* 0x1700: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1707:
	/* 0x1707: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_170b:
	/* 0x170b: je     17c3 <tail_handle_ipv6+0x17c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c3;
	}
x86_l_1711:
	/* 0x1711: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_171b:
	/* 0x171b: and    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_171e:
	/* 0x171e: je     17c3 <tail_handle_ipv6+0x17c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17c3;
	}
x86_l_1724:
	/* 0x1724: mov    QWORD PTR [rsp+0xc8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_172c:
	/* 0x172c: mov    BYTE PTR [rsp+0x48],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1731:
	/* 0x1731: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_1734:
	/* 0x1734: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_1737:
	/* 0x1737: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_173a:
	/* 0x173a: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_173d:
	/* 0x173d: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1740:
	/* 0x1740: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1749:
	/* 0x1749: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1752:
	/* 0x1752: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_175c:
	/* 0x175c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1761:
	/* 0x1761: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1768:
	/* 0x1768: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_176d:
	/* 0x176d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1772:
	/* 0x1772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1774:
	/* 0x1774: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1777:
	/* 0x1777: je     1782 <tail_handle_ipv6+0x1782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1782;
	}
x86_l_1779:
	/* 0x1779: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_177c:
	/* 0x177c: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1780:
	/* 0x1780: jmp    17aa <tail_handle_ipv6+0x17aa> */
	goto x86_l_17aa;
x86_l_1782:
	/* 0x1782: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_178b:
	/* 0x178b: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1790:
	/* 0x1790: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1797:
	/* 0x1797: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_179c:
	/* 0x179c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a1:
	/* 0x17a1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17a6:
	/* 0x17a6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a8:
	/* 0x17a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17aa:
	/* 0x17aa: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_17ad:
	/* 0x17ad: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_17b0:
	/* 0x17b0: mov    r9,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_64);
x86_l_17b3:
	/* 0x17b3: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_17b6:
	/* 0x17b6: movzx  ebp,BYTE PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_17bb:
	/* 0x17bb: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_17c3:
	/* 0x17c3: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_17c7:
	/* 0x17c7: jne    181a <tail_handle_ipv6+0x181a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_181a;
	}
x86_l_17c9:
	/* 0x17c9: and    r8,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_17cc:
	/* 0x17cc: jne    181a <tail_handle_ipv6+0x181a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_181a;
	}
x86_l_17ce:
	/* 0x17ce: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_17d1:
	/* 0x17d1: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_17d4:
	/* 0x17d4: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_17d7:
	/* 0x17d7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_17dc:
	/* 0x17dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17df:
	/* 0x17df: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17e4:
	/* 0x17e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e6:
	/* 0x17e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e8:
	/* 0x17e8: js     18ac <tail_handle_ipv6+0x18ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_18ac;
	}
x86_l_17ee:
	/* 0x17ee: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f2:
	/* 0x17f2: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_17f5:
	/* 0x17f5: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_17fa:
	/* 0x17fa: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17fd:
	/* 0x17fd: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1802:
	/* 0x1802: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1805:
	/* 0x1805: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_180c:
	/* 0x180c: jne    2019 <tail_handle_ipv6+0x2019> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8217ULL;
	}
x86_l_1812:
	/* 0x1812: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_1815:
	/* 0x1815: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1818:
	/* 0x1818: jmp    1821 <tail_handle_ipv6+0x1821> */
	goto x86_l_1821;
x86_l_181a:
	/* 0x181a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_181d:
	/* 0x181d: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1821:
	/* 0x1821: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1826:
	/* 0x1826: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_182b:
	/* 0x182b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182d:
	/* 0x182d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1830:
	/* 0x1830: je     183d <tail_handle_ipv6+0x183d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183d;
	}
x86_l_1832:
	/* 0x1832: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1835:
	/* 0x1835: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1839:
	/* 0x1839: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_183b:
	/* 0x183b: js     186c <tail_handle_ipv6+0x186c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_186c;
	}
x86_l_183d:
	/* 0x183d: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1844:
	/* 0x1844: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1846:
	/* 0x1846: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_184a:
	/* 0x184a: je     185a <tail_handle_ipv6+0x185a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_185a;
	}
x86_l_184c:
	/* 0x184c: movzx  r15d,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_1855:
	/* 0x1855: jmp    1bef <tail_handle_ipv6+0x1bef> */
	return 7151ULL;
x86_l_185a:
	/* 0x185a: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_185f:
	/* 0x185f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1862:
	/* 0x1862: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1867:
	/* 0x1867: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_186c:
	/* 0x186c: mov    BYTE PTR [rsp+0x48],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1871:
	/* 0x1871: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1873:
	/* 0x1873: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1875:
	/* 0x1875: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1878:
	/* 0x1878: je     1998 <tail_handle_ipv6+0x1998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1998;
	}
x86_l_187e:
	/* 0x187e: mov    DWORD PTR [rsp+0x8],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1883:
	/* 0x1883: mov    WORD PTR [rsp+0x98],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_188c:
	/* 0x188c: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1893:
	/* 0x1893: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1896:
	/* 0x1896: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1899:
	/* 0x1899: je     18b3 <tail_handle_ipv6+0x18b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b3;
	}
x86_l_189b:
	/* 0x189b: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_18a2:
	/* 0x18a2: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_18a6:
	/* 0x18a6: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_18aa:
	/* 0x18aa: jmp    18b9 <tail_handle_ipv6+0x18b9> */
	goto x86_l_18b9;
x86_l_18ac:
	/* 0x18ac: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_18b1:
	/* 0x18b1: jmp    185f <tail_handle_ipv6+0x185f> */
	goto x86_l_185f;
x86_l_18b3:
	/* 0x18b3: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_18b9:
	/* 0x18b9: cmp    BYTE PTR [rsp+0x48],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645318ULL);
x86_l_18be:
	/* 0x18be: jne    18fa <tail_handle_ipv6+0x18fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18fa;
	}
x86_l_18c0:
	/* 0x18c0: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18c4:
	/* 0x18c4: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18c6:
	/* 0x18c6: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_18c9:
	/* 0x18c9: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_18cc:
	/* 0x18cc: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_18ce:
	/* 0x18ce: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18d3:
	/* 0x18d3: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_18d5:
	/* 0x18d5: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_18da:
	/* 0x18da: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_18e0:
	/* 0x18e0: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_18e4:
	/* 0x18e4: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e9:
	/* 0x18e9: je     18fa <tail_handle_ipv6+0x18fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18fa;
	}
x86_l_18eb:
	/* 0x18eb: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_18f2:
	/* 0x18f2: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_18f6:
	/* 0x18f6: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_18fa:
	/* 0x18fa: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18fe:
	/* 0x18fe: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1901:
	/* 0x1901: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1906:
	/* 0x1906: je     1917 <tail_handle_ipv6+0x1917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1917;
	}
x86_l_1908:
	/* 0x1908: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_190d:
	/* 0x190d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_190f:
	/* 0x190f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1911:
	/* 0x1911: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1915:
	/* 0x1915: jmp    193a <tail_handle_ipv6+0x193a> */
	goto x86_l_193a;
x86_l_1917:
	/* 0x1917: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_191c:
	/* 0x191c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_191e:
	/* 0x191e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1920:
	/* 0x1920: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1924:
	/* 0x1924: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_192e:
	/* 0x192e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1931:
	/* 0x1931: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1936:
	/* 0x1936: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_193a:
	/* 0x193a: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_193d:
	/* 0x193d: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1941:
	/* 0x1941: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1946:
	/* 0x1946: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_194a:
	/* 0x194a: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_194e:
	/* 0x194e: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1953:
	/* 0x1953: je     1966 <tail_handle_ipv6+0x1966> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1966;
	}
x86_l_1955:
	/* 0x1955: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_195c:
	/* 0x195c: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_195e:
	/* 0x195e: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1961:
	/* 0x1961: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1964:
	/* 0x1964: jmp    196b <tail_handle_ipv6+0x196b> */
	goto x86_l_196b;
x86_l_1966:
	/* 0x1966: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_196b:
	/* 0x196b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_196d:
	/* 0x196d: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1970:
	/* 0x1970: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1972:
	/* 0x1972: movzx  r13d,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_197b:
	/* 0x197b: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1980:
	/* 0x1980: jb     1987 <tail_handle_ipv6+0x1987> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1987;
	}
x86_l_1982:
	/* 0x1982: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1985:
	/* 0x1985: je     1998 <tail_handle_ipv6+0x1998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1998;
	}
x86_l_1987:
	/* 0x1987: mov    BYTE PTR [r14+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_198b:
	/* 0x198b: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_198f:
	/* 0x198f: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1996:
	/* 0x1996: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1998:
	/* 0x1998: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_199f:
	/* 0x199f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a2:
	/* 0x19a2: je     19b0 <tail_handle_ipv6+0x19b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b0;
	}
x86_l_19a4:
	/* 0x19a4: inc QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_19a9:
	/* 0x19a9: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ab:
	/* 0x19ab: add QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_19b0:
	/* 0x19b0: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_19b4:
	/* 0x19b4: je     1a01 <tail_handle_ipv6+0x1a01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a01;
	}
x86_l_19b6:
	/* 0x19b6: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_19ba:
	/* 0x19ba: jne    1bd2 <tail_handle_ipv6+0x1bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7122ULL;
	}
x86_l_19c0:
	/* 0x19c0: movzx  eax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_19c5:
	/* 0x19c5: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_19c7:
	/* 0x19c7: je     1bd2 <tail_handle_ipv6+0x1bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7122ULL;
	}
x86_l_19cd:
	/* 0x19cd: mov    WORD PTR [r14+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_19d4:
	/* 0x19d4: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_19d9:
	/* 0x19d9: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19de:
	/* 0x19de: mov    r15,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_19e5:
	/* 0x19e5: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e9:
	/* 0x19e9: je     3580 <tail_handle_ipv6+0x3580> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13696ULL;
	}
x86_l_19ef:
	/* 0x19ef: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_19f6:
	/* 0x19f6: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_19f9:
	/* 0x19f9: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_19fc:
	/* 0x19fc: jmp    3585 <tail_handle_ipv6+0x3585> */
	return 13701ULL;
x86_l_1a01:
	/* 0x1a01: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1a04:
	/* 0x1a04: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_1a09:
	/* 0x1a09: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_1a10:
	/* 0x1a10: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_1a14:
	/* 0x1a14: or     ax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1a19:
	/* 0x1a19: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    rcx,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1a25:
	/* 0x1a25: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a27:
	/* 0x1a27: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1a29:
	/* 0x1a29: je     1bd2 <tail_handle_ipv6+0x1bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7122ULL;
	}
x86_l_1a2f:
	/* 0x1a2f: mov    r15,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1a36:
	/* 0x1a36: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a3a:
	/* 0x1a3a: je     1b43 <tail_handle_ipv6+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b43;
	}
x86_l_1a40:
	/* 0x1a40: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1a47:
	/* 0x1a47: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a49:
	/* 0x1a49: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a4b:
	/* 0x1a4b: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1a4e:
	/* 0x1a4e: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1a51:
	/* 0x1a51: jmp    1b48 <tail_handle_ipv6+0x1b48> */
	goto x86_l_1b48;
x86_l_1a56:
	/* 0x1a56: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1a5b:
	/* 0x1a5b: lea    ebp,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1a62:
	/* 0x1a62: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1a66:
	/* 0x1a66: jne    1d89 <tail_handle_ipv6+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7561ULL;
	}
x86_l_1a6c:
	/* 0x1a6c: cmp    ebp,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1a6f:
	/* 0x1a6f: jne    1d89 <tail_handle_ipv6+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7561ULL;
	}
x86_l_1a75:
	/* 0x1a75: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1a78:
	/* 0x1a78: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a7d:
	/* 0x1a7d: mov    ebp,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 24ULL);
x86_l_1a82:
	/* 0x1a82: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1a87:
	/* 0x1a87: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a8a:
	/* 0x1a8a: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1a8f:
	/* 0x1a8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a91:
	/* 0x1a91: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a93:
	/* 0x1a93: js     1e70 <tail_handle_ipv6+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7792ULL;
	}
x86_l_1a99:
	/* 0x1a99: cmp    BYTE PTR [rsp+0x5a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 386547056667ULL);
x86_l_1a9e:
	/* 0x1a9e: jne    1d89 <tail_handle_ipv6+0x1d89> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7561ULL;
	}
x86_l_1aa4:
	/* 0x1aa4: cmp    BYTE PTR [rsp+0x5b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 390842023956ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1aac:
	/* 0x1aac: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1aaf:
	/* 0x1aaf: je     1e40 <tail_handle_ipv6+0x1e40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7744ULL;
	}
x86_l_1ab5:
	/* 0x1ab5: jmp    1d89 <tail_handle_ipv6+0x1d89> */
	return 7561ULL;
x86_l_1aba:
	/* 0x1aba: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_1abe:
	/* 0x1abe: jmp    1e86 <tail_handle_ipv6+0x1e86> */
	return 7814ULL;
x86_l_1ac3:
	/* 0x1ac3: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1ac6:
	/* 0x1ac6: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1ac9:
	/* 0x1ac9: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1ace:
	/* 0x1ace: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_1ad2:
	/* 0x1ad2: jbe    117f <tail_handle_ipv6+0x117f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 4479ULL;
	}
x86_l_1ad8:
	/* 0x1ad8: jmp    1e97 <tail_handle_ipv6+0x1e97> */
	return 7831ULL;
x86_l_1add:
	/* 0x1add: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ae1:
	/* 0x1ae1: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae6:
	/* 0x1ae6: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_1aed:
	/* 0x1aed: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af2:
	/* 0x1af2: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1af8:
	/* 0x1af8: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1afb:
	/* 0x1afb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1afe:
	/* 0x1afe: je     2385 <tail_handle_ipv6+0x2385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9093ULL;
	}
x86_l_1b04:
	/* 0x1b04: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1b07:
	/* 0x1b07: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b0c:
	/* 0x1b0c: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1b10:
	/* 0x1b10: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1b15:
	/* 0x1b15: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1b22:
	/* 0x1b22: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1b25:
	/* 0x1b25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b28:
	/* 0x1b28: je     1568 <tail_handle_ipv6+0x1568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1568;
	}
x86_l_1b2e:
	/* 0x1b2e: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1b31:
	/* 0x1b31: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b35:
	/* 0x1b35: movzx  ecx,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_1b3a:
	/* 0x1b3a: mov    WORD PTR [rax+0x26],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1b3e:
	/* 0x1b3e: jmp    1568 <tail_handle_ipv6+0x1568> */
	goto x86_l_1568;
x86_l_1b43:
	/* 0x1b43: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_1b48:
	/* 0x1b48: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b4c:
	/* 0x1b4c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b50:
	/* 0x1b50: je     1b61 <tail_handle_ipv6+0x1b61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7009ULL;
	}
x86_l_1b52:
	/* 0x1b52: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1b57:
	/* 0x1b57: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
	return 7001ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7001ULL: goto x86_l_1b59;
	case 7003ULL: goto x86_l_1b5b;
	case 7007ULL: goto x86_l_1b5f;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7016ULL: goto x86_l_1b68;
	case 7018ULL: goto x86_l_1b6a;
	case 7022ULL: goto x86_l_1b6e;
	case 7032ULL: goto x86_l_1b78;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7044ULL: goto x86_l_1b84;
	case 7046ULL: goto x86_l_1b86;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7059ULL: goto x86_l_1b93;
	case 7063ULL: goto x86_l_1b97;
	case 7067ULL: goto x86_l_1b9b;
	case 7069ULL: goto x86_l_1b9d;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7081ULL: goto x86_l_1ba9;
	case 7084ULL: goto x86_l_1bac;
	case 7086ULL: goto x86_l_1bae;
	case 7091ULL: goto x86_l_1bb3;
	case 7093ULL: goto x86_l_1bb5;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7100ULL: goto x86_l_1bbc;
	case 7103ULL: goto x86_l_1bbf;
	case 7105ULL: goto x86_l_1bc1;
	case 7109ULL: goto x86_l_1bc5;
	case 7113ULL: goto x86_l_1bc9;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7128ULL: goto x86_l_1bd8;
	case 7134ULL: goto x86_l_1bde;
	case 7137ULL: goto x86_l_1be1;
	case 7145ULL: goto x86_l_1be9;
	case 7151ULL: goto x86_l_1bef;
	case 7159ULL: goto x86_l_1bf7;
	case 7167ULL: goto x86_l_1bff;
	case 7171ULL: goto x86_l_1c03;
	case 7173ULL: goto x86_l_1c05;
	case 7180ULL: goto x86_l_1c0c;
	case 7182ULL: goto x86_l_1c0e;
	case 7189ULL: goto x86_l_1c15;
	case 7198ULL: goto x86_l_1c1e;
	case 7207ULL: goto x86_l_1c27;
	case 7216ULL: goto x86_l_1c30;
	case 7225ULL: goto x86_l_1c39;
	case 7234ULL: goto x86_l_1c42;
	case 7242ULL: goto x86_l_1c4a;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7258ULL: goto x86_l_1c5a;
	case 7265ULL: goto x86_l_1c61;
	case 7272ULL: goto x86_l_1c68;
	case 7277ULL: goto x86_l_1c6d;
	case 7279ULL: goto x86_l_1c6f;
	case 7286ULL: goto x86_l_1c76;
	case 7289ULL: goto x86_l_1c79;
	case 7292ULL: goto x86_l_1c7c;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7303ULL: goto x86_l_1c87;
	case 7305ULL: goto x86_l_1c89;
	case 7312ULL: goto x86_l_1c90;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7326ULL: goto x86_l_1c9e;
	case 7329ULL: goto x86_l_1ca1;
	case 7332ULL: goto x86_l_1ca4;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7351ULL: goto x86_l_1cb7;
	case 7353ULL: goto x86_l_1cb9;
	case 7355ULL: goto x86_l_1cbb;
	case 7359ULL: goto x86_l_1cbf;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7370ULL: goto x86_l_1cca;
	case 7374ULL: goto x86_l_1cce;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7392ULL: goto x86_l_1ce0;
	case 7396ULL: goto x86_l_1ce4;
	case 7400ULL: goto x86_l_1ce8;
	case 7403ULL: goto x86_l_1ceb;
	case 7405ULL: goto x86_l_1ced;
	case 7409ULL: goto x86_l_1cf1;
	case 7414ULL: goto x86_l_1cf6;
	case 7418ULL: goto x86_l_1cfa;
	case 7420ULL: goto x86_l_1cfc;
	case 7425ULL: goto x86_l_1d01;
	case 7427ULL: goto x86_l_1d03;
	case 7434ULL: goto x86_l_1d0a;
	case 7436ULL: goto x86_l_1d0c;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7451ULL: goto x86_l_1d1b;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7465ULL: goto x86_l_1d29;
	case 7469ULL: goto x86_l_1d2d;
	case 7476ULL: goto x86_l_1d34;
	case 7478ULL: goto x86_l_1d36;
	case 7485ULL: goto x86_l_1d3d;
	case 7488ULL: goto x86_l_1d40;
	case 7490ULL: goto x86_l_1d42;
	case 7499ULL: goto x86_l_1d4b;
	case 7501ULL: goto x86_l_1d4d;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7518ULL: goto x86_l_1d5e;
	case 7523ULL: goto x86_l_1d63;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7530ULL: goto x86_l_1d6a;
	case 7532ULL: goto x86_l_1d6c;
	case 7538ULL: goto x86_l_1d72;
	case 7541ULL: goto x86_l_1d75;
	case 7546ULL: goto x86_l_1d7a;
	case 7551ULL: goto x86_l_1d7f;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7566ULL: goto x86_l_1d8e;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7587ULL: goto x86_l_1da3;
	case 7591ULL: goto x86_l_1da7;
	case 7597ULL: goto x86_l_1dad;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7608ULL: goto x86_l_1db8;
	case 7611ULL: goto x86_l_1dbb;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7620ULL: goto x86_l_1dc4;
	case 7625ULL: goto x86_l_1dc9;
	case 7627ULL: goto x86_l_1dcb;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7639ULL: goto x86_l_1dd7;
	case 7649ULL: goto x86_l_1de1;
	case 7653ULL: goto x86_l_1de5;
	case 7659ULL: goto x86_l_1deb;
	case 7661ULL: goto x86_l_1ded;
	case 7666ULL: goto x86_l_1df2;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7693ULL: goto x86_l_1e0d;
	case 7696ULL: goto x86_l_1e10;
	case 7698ULL: goto x86_l_1e12;
	case 7703ULL: goto x86_l_1e17;
	case 7705ULL: goto x86_l_1e19;
	case 7707ULL: goto x86_l_1e1b;
	case 7709ULL: goto x86_l_1e1d;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7722ULL: goto x86_l_1e2a;
	case 7727ULL: goto x86_l_1e2f;
	case 7730ULL: goto x86_l_1e32;
	case 7733ULL: goto x86_l_1e35;
	case 7738ULL: goto x86_l_1e3a;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7754ULL: goto x86_l_1e4a;
	case 7762ULL: goto x86_l_1e52;
	case 7770ULL: goto x86_l_1e5a;
	case 7775ULL: goto x86_l_1e5f;
	case 7783ULL: goto x86_l_1e67;
	case 7785ULL: goto x86_l_1e69;
	case 7787ULL: goto x86_l_1e6b;
	case 7792ULL: goto x86_l_1e70;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7810ULL: goto x86_l_1e82;
	case 7814ULL: goto x86_l_1e86;
	case 7817ULL: goto x86_l_1e89;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7831ULL: goto x86_l_1e97;
	case 7839ULL: goto x86_l_1e9f;
	case 7841ULL: goto x86_l_1ea1;
	case 7846ULL: goto x86_l_1ea6;
	case 7848ULL: goto x86_l_1ea8;
	case 7855ULL: goto x86_l_1eaf;
	case 7857ULL: goto x86_l_1eb1;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7876ULL: goto x86_l_1ec4;
	case 7879ULL: goto x86_l_1ec7;
	case 7881ULL: goto x86_l_1ec9;
	case 7885ULL: goto x86_l_1ecd;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7901ULL: goto x86_l_1edd;
	case 7908ULL: goto x86_l_1ee4;
	case 7914ULL: goto x86_l_1eea;
	case 7919ULL: goto x86_l_1eef;
	case 7922ULL: goto x86_l_1ef2;
	case 7927ULL: goto x86_l_1ef7;
	case 7929ULL: goto x86_l_1ef9;
	case 7934ULL: goto x86_l_1efe;
	case 7939ULL: goto x86_l_1f03;
	case 7944ULL: goto x86_l_1f08;
	case 7949ULL: goto x86_l_1f0d;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7965ULL: goto x86_l_1f1d;
	case 7970ULL: goto x86_l_1f22;
	case 7973ULL: goto x86_l_1f25;
	case 7976ULL: goto x86_l_1f28;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7993ULL: goto x86_l_1f39;
	case 7998ULL: goto x86_l_1f3e;
	case 8001ULL: goto x86_l_1f41;
	case 8003ULL: goto x86_l_1f43;
	case 8006ULL: goto x86_l_1f46;
	case 8012ULL: goto x86_l_1f4c;
	case 8014ULL: goto x86_l_1f4e;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8033ULL: goto x86_l_1f61;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8044ULL: goto x86_l_1f6c;
	case 8046ULL: goto x86_l_1f6e;
	case 8048ULL: goto x86_l_1f70;
	case 8050ULL: goto x86_l_1f72;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8068ULL: goto x86_l_1f84;
	case 8077ULL: goto x86_l_1f8d;
	case 8087ULL: goto x86_l_1f97;
	case 8092ULL: goto x86_l_1f9c;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8109ULL: goto x86_l_1fad;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8123ULL: goto x86_l_1fbb;
	case 8128ULL: goto x86_l_1fc0;
	case 8133ULL: goto x86_l_1fc5;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8148ULL: goto x86_l_1fd4;
	case 8153ULL: goto x86_l_1fd9;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8174ULL: goto x86_l_1fee;
	case 8179ULL: goto x86_l_1ff3;
	case 8184ULL: goto x86_l_1ff8;
	case 8189ULL: goto x86_l_1ffd;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8206ULL: goto x86_l_200e;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8223ULL: goto x86_l_201f;
	case 8228ULL: goto x86_l_2024;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8247ULL: goto x86_l_2037;
	case 8252ULL: goto x86_l_203c;
	case 8258ULL: goto x86_l_2042;
	case 8266ULL: goto x86_l_204a;
	case 8268ULL: goto x86_l_204c;
	case 8272ULL: goto x86_l_2050;
	case 8274ULL: goto x86_l_2052;
	case 8277ULL: goto x86_l_2055;
	case 8280ULL: goto x86_l_2058;
	case 8282ULL: goto x86_l_205a;
	case 8286ULL: goto x86_l_205e;
	case 8288ULL: goto x86_l_2060;
	case 8293ULL: goto x86_l_2065;
	case 8299ULL: goto x86_l_206b;
	case 8303ULL: goto x86_l_206f;
	case 8307ULL: goto x86_l_2073;
	case 8309ULL: goto x86_l_2075;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8324ULL: goto x86_l_2084;
	case 8329ULL: goto x86_l_2089;
	case 8333ULL: goto x86_l_208d;
	case 8335ULL: goto x86_l_208f;
	case 8340ULL: goto x86_l_2094;
	case 8342ULL: goto x86_l_2096;
	case 8344ULL: goto x86_l_2098;
	case 8348ULL: goto x86_l_209c;
	case 8350ULL: goto x86_l_209e;
	case 8355ULL: goto x86_l_20a3;
	case 8357ULL: goto x86_l_20a5;
	case 8359ULL: goto x86_l_20a7;
	case 8363ULL: goto x86_l_20ab;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8381ULL: goto x86_l_20bd;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8392ULL: goto x86_l_20c8;
	case 8396ULL: goto x86_l_20cc;
	case 8399ULL: goto x86_l_20cf;
	case 8403ULL: goto x86_l_20d3;
	case 8407ULL: goto x86_l_20d7;
	case 8411ULL: goto x86_l_20db;
	case 8415ULL: goto x86_l_20df;
	case 8417ULL: goto x86_l_20e1;
	case 8424ULL: goto x86_l_20e8;
	case 8426ULL: goto x86_l_20ea;
	case 8429ULL: goto x86_l_20ed;
	case 8432ULL: goto x86_l_20f0;
	case 8434ULL: goto x86_l_20f2;
	case 8439ULL: goto x86_l_20f7;
	case 8441ULL: goto x86_l_20f9;
	case 8445ULL: goto x86_l_20fd;
	case 8447ULL: goto x86_l_20ff;
	case 8451ULL: goto x86_l_2103;
	case 8453ULL: goto x86_l_2105;
	case 8458ULL: goto x86_l_210a;
	case 8460ULL: goto x86_l_210c;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8470ULL: goto x86_l_2116;
	case 8473ULL: goto x86_l_2119;
	case 8476ULL: goto x86_l_211c;
	case 8483ULL: goto x86_l_2123;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8495ULL: goto x86_l_212f;
	case 8501ULL: goto x86_l_2135;
	case 8505ULL: goto x86_l_2139;
	case 8508ULL: goto x86_l_213c;
	case 8514ULL: goto x86_l_2142;
	case 8523ULL: goto x86_l_214b;
	case 8532ULL: goto x86_l_2154;
	case 8541ULL: goto x86_l_215d;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8556ULL: goto x86_l_216c;
	case 8564ULL: goto x86_l_2174;
	case 8569ULL: goto x86_l_2179;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8604ULL: goto x86_l_219c;
	case 8610ULL: goto x86_l_21a2;
	case 8613ULL: goto x86_l_21a5;
	case 8620ULL: goto x86_l_21ac;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8633ULL: goto x86_l_21b9;
	case 8635ULL: goto x86_l_21bb;
	case 8639ULL: goto x86_l_21bf;
	case 8641ULL: goto x86_l_21c1;
	case 8646ULL: goto x86_l_21c6;
	case 8648ULL: goto x86_l_21c8;
	case 8650ULL: goto x86_l_21ca;
	case 8654ULL: goto x86_l_21ce;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b59:
	/* 0x1b59: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b5b:
	/* 0x1b5b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1b5f:
	/* 0x1b5f: jmp    1b84 <tail_handle_ipv6+0x1b84> */
	goto x86_l_1b84;
x86_l_1b61:
	/* 0x1b61: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b66:
	/* 0x1b66: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b68:
	/* 0x1b68: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b6a:
	/* 0x1b6a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1b6e:
	/* 0x1b6e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1b78:
	/* 0x1b78: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1b7b:
	/* 0x1b7b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b80:
	/* 0x1b80: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1b84:
	/* 0x1b84: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b86:
	/* 0x1b86: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b8a:
	/* 0x1b8a: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1b8f:
	/* 0x1b8f: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b93:
	/* 0x1b93: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1b97:
	/* 0x1b97: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9b:
	/* 0x1b9b: je     1bae <tail_handle_ipv6+0x1bae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bae;
	}
x86_l_1b9d:
	/* 0x1b9d: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1ba4:
	/* 0x1ba4: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba6:
	/* 0x1ba6: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1ba9:
	/* 0x1ba9: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1bac:
	/* 0x1bac: jmp    1bb3 <tail_handle_ipv6+0x1bb3> */
	goto x86_l_1bb3;
x86_l_1bae:
	/* 0x1bae: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1bb3:
	/* 0x1bb3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1bb5:
	/* 0x1bb5: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1bb8:
	/* 0x1bb8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1bba:
	/* 0x1bba: jb     1bc1 <tail_handle_ipv6+0x1bc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bc1;
	}
x86_l_1bbc:
	/* 0x1bbc: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_1bbf:
	/* 0x1bbf: je     1bd2 <tail_handle_ipv6+0x1bd2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bd2;
	}
x86_l_1bc1:
	/* 0x1bc1: mov    BYTE PTR [r14+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1bc5:
	/* 0x1bc5: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1bd0:
	/* 0x1bd0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd2:
	/* 0x1bd2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd4:
	/* 0x1bd4: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1bd8:
	/* 0x1bd8: je     2bfe <tail_handle_ipv6+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11262ULL;
	}
x86_l_1bde:
	/* 0x1bde: mov    r15b,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1be1:
	/* 0x1be1: cmp    BYTE PTR [rsp+0x94],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 635655159814ULL);
x86_l_1be9:
	/* 0x1be9: jne    2bfe <tail_handle_ipv6+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11262ULL;
	}
x86_l_1bef:
	/* 0x1bef: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1bff:
	/* 0x1bff: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1c03:
	/* 0x1c03: jne    1c0e <tail_handle_ipv6+0x1c0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c0e;
	}
x86_l_1c05:
	/* 0x1c05: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_1c0c:
	/* 0x1c0c: jmp    1c15 <tail_handle_ipv6+0x1c15> */
	goto x86_l_1c15;
x86_l_1c0e:
	/* 0x1c0e: mov    r14,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1c15:
	/* 0x1c15: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c1e:
	/* 0x1c1e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c27:
	/* 0x1c27: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1c30:
	/* 0x1c30: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c39:
	/* 0x1c39: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c42:
	/* 0x1c42: mov    DWORD PTR [rsp+0x3c],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037770ULL);
x86_l_1c4a:
	/* 0x1c4a: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c4f:
	/* 0x1c4f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c54:
	/* 0x1c54: mov    WORD PTR [rsp+0x38],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c5a:
	/* 0x1c5a: mov    WORD PTR [rsp+0x34],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299520ULL);
x86_l_1c61:
	/* 0x1c61: mov    r12,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1c68:
	/* 0x1c68: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c6d:
	/* 0x1c6d: je     1c7e <tail_handle_ipv6+0x1c7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c7e;
	}
x86_l_1c6f:
	/* 0x1c6f: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c76:
	/* 0x1c76: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1c79:
	/* 0x1c79: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c7c:
	/* 0x1c7c: jmp    1c83 <tail_handle_ipv6+0x1c83> */
	goto x86_l_1c83;
x86_l_1c7e:
	/* 0x1c7e: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1c83:
	/* 0x1c83: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1c87:
	/* 0x1c87: jne    1cab <tail_handle_ipv6+0x1cab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cab;
	}
x86_l_1c89:
	/* 0x1c89: mov    WORD PTR [rsp+0x34],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299520ULL);
x86_l_1c90:
	/* 0x1c90: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c95:
	/* 0x1c95: je     1ca6 <tail_handle_ipv6+0x1ca6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca6;
	}
x86_l_1c97:
	/* 0x1c97: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c9e:
	/* 0x1c9e: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1ca1:
	/* 0x1ca1: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ca4:
	/* 0x1ca4: jmp    1cab <tail_handle_ipv6+0x1cab> */
	goto x86_l_1cab;
x86_l_1ca6:
	/* 0x1ca6: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1cab:
	/* 0x1cab: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb0:
	/* 0x1cb0: je     1cc1 <tail_handle_ipv6+0x1cc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cc1;
	}
x86_l_1cb2:
	/* 0x1cb2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1cb7:
	/* 0x1cb7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb9:
	/* 0x1cb9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cbb:
	/* 0x1cbb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1cbf:
	/* 0x1cbf: jmp    1ce4 <tail_handle_ipv6+0x1ce4> */
	goto x86_l_1ce4;
x86_l_1cc1:
	/* 0x1cc1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1cc6:
	/* 0x1cc6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cc8:
	/* 0x1cc8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cca:
	/* 0x1cca: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1cce:
	/* 0x1cce: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1cd8:
	/* 0x1cd8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1cdb:
	/* 0x1cdb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ce0:
	/* 0x1ce0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1ce4:
	/* 0x1ce4: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1ce8:
	/* 0x1ce8: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1ceb:
	/* 0x1ceb: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ced:
	/* 0x1ced: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cf1:
	/* 0x1cf1: movzx  edx,BYTE PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_1cf6:
	/* 0x1cf6: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1cfa:
	/* 0x1cfa: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1cfc:
	/* 0x1cfc: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d01:
	/* 0x1d01: je     1d14 <tail_handle_ipv6+0x1d14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d14;
	}
x86_l_1d03:
	/* 0x1d03: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1d0a:
	/* 0x1d0a: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d0c:
	/* 0x1d0c: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1d0f:
	/* 0x1d0f: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d12:
	/* 0x1d12: jmp    1d19 <tail_handle_ipv6+0x1d19> */
	goto x86_l_1d19;
x86_l_1d14:
	/* 0x1d14: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1d19:
	/* 0x1d19: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d1b:
	/* 0x1d1b: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d1d:
	/* 0x1d1d: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1d1f:
	/* 0x1d1f: jb     1d25 <tail_handle_ipv6+0x1d25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d25;
	}
x86_l_1d21:
	/* 0x1d21: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_1d23:
	/* 0x1d23: je     1d36 <tail_handle_ipv6+0x1d36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d36;
	}
x86_l_1d25:
	/* 0x1d25: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1d29:
	/* 0x1d29: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d2d:
	/* 0x1d2d: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1d34:
	/* 0x1d34: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d36:
	/* 0x1d36: mov    rax,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1d3d:
	/* 0x1d3d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d40:
	/* 0x1d40: je     1d52 <tail_handle_ipv6+0x1d52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d52;
	}
x86_l_1d42:
	/* 0x1d42: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_1d4b:
	/* 0x1d4b: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d52:
	/* 0x1d52: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d57:
	/* 0x1d57: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d5c:
	/* 0x1d5c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d5e:
	/* 0x1d5e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d63:
	/* 0x1d63: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1d66:
	/* 0x1d66: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d68:
	/* 0x1d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6a:
	/* 0x1d6a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d6c:
	/* 0x1d6c: jns    2bfe <tail_handle_ipv6+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 11262ULL;
	}
x86_l_1d72:
	/* 0x1d72: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1d75:
	/* 0x1d75: mov    ebp,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967141ULL);
x86_l_1d7a:
	/* 0x1d7a: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d7f:
	/* 0x1d7f: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_1d84:
	/* 0x1d84: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1d89:
	/* 0x1d89: cmp    DWORD PTR [rsp+0x48],0x3c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645372ULL);
x86_l_1d8e:
	/* 0x1d8e: ja     1e97 <tail_handle_ipv6+0x1e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e97;
	}
x86_l_1d94:
	/* 0x1d94: mov    r12d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d99:
	/* 0x1d99: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1da3:
	/* 0x1da3: bt     rax,r12 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1da7:
	/* 0x1da7: jae    1e82 <tail_handle_ipv6+0x1e82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e82;
	}
x86_l_1dad:
	/* 0x1dad: add    ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1db0:
	/* 0x1db0: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1db3:
	/* 0x1db3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1db8:
	/* 0x1db8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dbb:
	/* 0x1dbb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1dbd:
	/* 0x1dbd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1dc2:
	/* 0x1dc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc4:
	/* 0x1dc4: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_1dc9:
	/* 0x1dc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dcb:
	/* 0x1dcb: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1dce:
	/* 0x1dce: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1dd1:
	/* 0x1dd1: js     1672 <tail_handle_ipv6+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 5746ULL;
	}
x86_l_1dd7:
	/* 0x1dd7: movabs rax,0x1000080000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1152930300699869185ULL);
x86_l_1de1:
	/* 0x1de1: bt     rax,r12 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1de5:
	/* 0x1de5: jae    1f03 <tail_handle_ipv6+0x1f03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f03;
	}
x86_l_1deb:
	/* 0x1deb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ded:
	/* 0x1ded: cmp    DWORD PTR [rsp+0x48],0x3c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645372ULL);
x86_l_1df2:
	/* 0x1df2: jne    1f22 <tail_handle_ipv6+0x1f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f22;
	}
x86_l_1df8:
	/* 0x1df8: cmp    BYTE PTR [rsp+0x1],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4294967298ULL);
x86_l_1dfd:
	/* 0x1dfd: jne    1f22 <tail_handle_ipv6+0x1f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f22;
	}
x86_l_1e03:
	/* 0x1e03: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e08:
	/* 0x1e08: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e10:
	/* 0x1e10: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e12:
	/* 0x1e12: mov    ecx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_1e17:
	/* 0x1e17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e19:
	/* 0x1e19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e1b:
	/* 0x1e1b: js     1e70 <tail_handle_ipv6+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1e70;
	}
x86_l_1e1d:
	/* 0x1e1d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e1f:
	/* 0x1e1f: cmp    BYTE PTR [rsp+0x5a],0x1b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 386547056667ULL);
x86_l_1e24:
	/* 0x1e24: jne    1f22 <tail_handle_ipv6+0x1f22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f22;
	}
x86_l_1e2a:
	/* 0x1e2a: cmp    BYTE PTR [rsp+0x5b],0x14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 390842023956ULL);
x86_l_1e2f:
	/* 0x1e2f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1e32:
	/* 0x1e32: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1e35:
	/* 0x1e35: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1e3a:
	/* 0x1e3a: jne    1674 <tail_handle_ipv6+0x1674> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5748ULL;
	}
x86_l_1e40:
	/* 0x1e40: mov    rax,QWORD PTR [rsp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1e45:
	/* 0x1e45: mov    rcx,QWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_1e4a:
	/* 0x1e4a: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1e52:
	/* 0x1e52: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1e5a:
	/* 0x1e5a: movzx  eax,WORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 108ULL);
x86_l_1e5f:
	/* 0x1e5f: mov    WORD PTR [rsp+0xc0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e67:
	/* 0x1e67: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e69:
	/* 0x1e69: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1e6b:
	/* 0x1e6b: jmp    1674 <tail_handle_ipv6+0x1674> */
	return 5748ULL;
x86_l_1e70:
	/* 0x1e70: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_1e75:
	/* 0x1e75: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e77:
	/* 0x1e77: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1e7a:
	/* 0x1e7a: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1e7d:
	/* 0x1e7d: jmp    1674 <tail_handle_ipv6+0x1674> */
	return 5748ULL;
x86_l_1e82:
	/* 0x1e82: cmp    r12,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 59ULL);
x86_l_1e86:
	/* 0x1e86: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1e89:
	/* 0x1e89: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1e8c:
	/* 0x1e8c: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1e91:
	/* 0x1e91: je     1672 <tail_handle_ipv6+0x1672> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5746ULL;
	}
x86_l_1e97:
	/* 0x1e97: cmp    BYTE PTR [rsp+0x94],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 635655159814ULL);
x86_l_1e9f:
	/* 0x1e9f: jne    1ecd <tail_handle_ipv6+0x1ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ecd;
	}
x86_l_1ea1:
	/* 0x1ea1: cmp    BYTE PTR [rsp+0x34],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 223338299398ULL);
x86_l_1ea6:
	/* 0x1ea6: jne    1eb1 <tail_handle_ipv6+0x1eb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eb1;
	}
x86_l_1ea8:
	/* 0x1ea8: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_1eaf:
	/* 0x1eaf: jmp    1eb8 <tail_handle_ipv6+0x1eb8> */
	goto x86_l_1eb8;
x86_l_1eb1:
	/* 0x1eb1: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1eb8:
	/* 0x1eb8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ebd:
	/* 0x1ebd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ec2:
	/* 0x1ec2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec4:
	/* 0x1ec4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ec7:
	/* 0x1ec7: je     1ecd <tail_handle_ipv6+0x1ecd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ecd;
	}
x86_l_1ec9:
	/* 0x1ec9: and    BYTE PTR [rax+0x24],0x7f */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 154618822783ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1edd:
	/* 0x1edd: mov    rsi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1ee4:
	/* 0x1ee4: mov    r12d,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 37ULL);
x86_l_1eea:
	/* 0x1eea: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1eef:
	/* 0x1eef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ef2:
	/* 0x1ef2: mov    edx,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_1ef7:
	/* 0x1ef7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef9:
	/* 0x1ef9: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_1efe:
	/* 0x1efe: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_1f03:
	/* 0x1f03: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1f08:
	/* 0x1f08: jmp    1e75 <tail_handle_ipv6+0x1e75> */
	goto x86_l_1e75;
x86_l_1f0d:
	/* 0x1f0d: mov    r9d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 24ULL);
x86_l_1f13:
	/* 0x1f13: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1f17:
	/* 0x1f17: jbe    15fa <tail_handle_ipv6+0x15fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 5626ULL;
	}
x86_l_1f1d:
	/* 0x1f1d: jmp    1e97 <tail_handle_ipv6+0x1e97> */
	goto x86_l_1e97;
x86_l_1f22:
	/* 0x1f22: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1f25:
	/* 0x1f25: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_1f28:
	/* 0x1f28: mov    ecx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967140ULL);
x86_l_1f2d:
	/* 0x1f2d: jmp    1674 <tail_handle_ipv6+0x1674> */
	return 5748ULL;
x86_l_1f32:
	/* 0x1f32: mov    rdi,QWORD PTR [rip+0xec6a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1f39:
	/* 0x1f39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f3e:
	/* 0x1f3e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1f41:
	/* 0x1f41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f43:
	/* 0x1f43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f46:
	/* 0x1f46: je     1fca <tail_handle_ipv6+0x1fca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fca;
	}
x86_l_1f4c:
	/* 0x1f4c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4e:
	/* 0x1f4e: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f55:
	/* 0x1f55: jmp    9d4 <tail_handle_ipv6+0x9d4> */
	return 2516ULL;
x86_l_1f5a:
	/* 0x1f5a: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1f61:
	/* 0x1f61: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f66:
	/* 0x1f66: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1f69:
	/* 0x1f69: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1f6c:
	/* 0x1f6c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6e:
	/* 0x1f6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f70:
	/* 0x1f70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f72:
	/* 0x1f72: je     9d4 <tail_handle_ipv6+0x9d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2516ULL;
	}
x86_l_1f78:
	/* 0x1f78: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7b:
	/* 0x1f7b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1f84:
	/* 0x1f84: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1f8d:
	/* 0x1f8d: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1f97:
	/* 0x1f97: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f9c:
	/* 0x1f9c: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1fa3:
	/* 0x1fa3: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fad:
	/* 0x1fad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1faf:
	/* 0x1faf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb2:
	/* 0x1fb2: je     1fd9 <tail_handle_ipv6+0x1fd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd9;
	}
x86_l_1fb4:
	/* 0x1fb4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1fb7:
	/* 0x1fb7: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1fbb:
	/* 0x1fbb: jmp    9d4 <tail_handle_ipv6+0x9d4> */
	return 2516ULL;
x86_l_1fc0:
	/* 0x1fc0: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_1fc5:
	/* 0x1fc5: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_1fca:
	/* 0x1fca: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fd4:
	/* 0x1fd4: jmp    ae9 <tail_handle_ipv6+0xae9> */
	return 2793ULL;
x86_l_1fd9:
	/* 0x1fd9: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1fee:
	/* 0x1fee: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ff3:
	/* 0x1ff3: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff8:
	/* 0x1ff8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ffd:
	/* 0x1ffd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fff:
	/* 0x1fff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2001:
	/* 0x2001: jmp    9d4 <tail_handle_ipv6+0x9d4> */
	return 2516ULL;
x86_l_2006:
	/* 0x2006: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2009:
	/* 0x2009: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_200e:
	/* 0x200e: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_2014:
	/* 0x2014: jmp    ef9 <tail_handle_ipv6+0xef9> */
	return 3833ULL;
x86_l_2019:
	/* 0x2019: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_201f:
	/* 0x201f: jmp    1815 <tail_handle_ipv6+0x1815> */
	return 6165ULL;
x86_l_2024:
	/* 0x2024: test   DWORD PTR [rsp+0x50],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597384192ULL);
x86_l_202c:
	/* 0x202c: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2031:
	/* 0x2031: jne    158b <tail_handle_ipv6+0x158b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5515ULL;
	}
x86_l_2037:
	/* 0x2037: jmp    24ca <tail_handle_ipv6+0x24ca> */
	return 9418ULL;
x86_l_203c:
	/* 0x203c: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_2042:
	/* 0x2042: cmp    BYTE PTR [rsp+0xa8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505734ULL);
x86_l_204a:
	/* 0x204a: jne    2084 <tail_handle_ipv6+0x2084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2084;
	}
x86_l_204c:
	/* 0x204c: mov    ecx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2050:
	/* 0x2050: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2052:
	/* 0x2052: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2055:
	/* 0x2055: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2058:
	/* 0x2058: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_205a:
	/* 0x205a: mov    WORD PTR [rbp+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_205e:
	/* 0x205e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2060:
	/* 0x2060: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2065:
	/* 0x2065: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_206b:
	/* 0x206b: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_206f:
	/* 0x206f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2073:
	/* 0x2073: je     2084 <tail_handle_ipv6+0x2084> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2084;
	}
x86_l_2075:
	/* 0x2075: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_207c:
	/* 0x207c: imul   r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2080:
	/* 0x2080: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2084:
	/* 0x2084: shr    DWORD PTR [rsp+0x50],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 343597383688ULL);
x86_l_2089:
	/* 0x2089: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208d:
	/* 0x208d: je     209e <tail_handle_ipv6+0x209e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209e;
	}
x86_l_208f:
	/* 0x208f: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2094:
	/* 0x2094: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2096:
	/* 0x2096: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2098:
	/* 0x2098: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_209c:
	/* 0x209c: jmp    20c1 <tail_handle_ipv6+0x20c1> */
	goto x86_l_20c1;
x86_l_209e:
	/* 0x209e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_20a3:
	/* 0x20a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20a5:
	/* 0x20a5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_20a7:
	/* 0x20a7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_20ab:
	/* 0x20ab: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_20b5:
	/* 0x20b5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_20b8:
	/* 0x20b8: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_20bd:
	/* 0x20bd: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_20c1:
	/* 0x20c1: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20c4:
	/* 0x20c4: mov    DWORD PTR [rbp+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20c8:
	/* 0x20c8: movzx  ecx,BYTE PTR [rbp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_20cc:
	/* 0x20cc: mov    edx,DWORD PTR [rbp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_20cf:
	/* 0x20cf: mov    esi,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20d3:
	/* 0x20d3: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_20d7:
	/* 0x20d7: mov    DWORD PTR [rsp+0x50],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20db:
	/* 0x20db: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20df:
	/* 0x20df: je     20f2 <tail_handle_ipv6+0x20f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20f2;
	}
x86_l_20e1:
	/* 0x20e1: mov    rsi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_20e8:
	/* 0x20e8: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20ea:
	/* 0x20ea: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_20ed:
	/* 0x20ed: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_20f0:
	/* 0x20f0: jmp    20f7 <tail_handle_ipv6+0x20f7> */
	goto x86_l_20f7;
x86_l_20f2:
	/* 0x20f2: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_20f7:
	/* 0x20f7: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20f9:
	/* 0x20f9: mov    edx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20fd:
	/* 0x20fd: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_20ff:
	/* 0x20ff: mov    DWORD PTR [rsp+0x50],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2103:
	/* 0x2103: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2105:
	/* 0x2105: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_210a:
	/* 0x210a: jb     2112 <tail_handle_ipv6+0x2112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2112;
	}
x86_l_210c:
	/* 0x210c: cmp    cl,BYTE PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 80ULL);
x86_l_2110:
	/* 0x2110: je     212a <tail_handle_ipv6+0x212a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_212a;
	}
x86_l_2112:
	/* 0x2112: mov    ecx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2116:
	/* 0x2116: mov    BYTE PTR [rbp+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2119:
	/* 0x2119: mov    DWORD PTR [rbp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_211c:
	/* 0x211c: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2123:
	/* 0x2123: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2125:
	/* 0x2125: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_212a:
	/* 0x212a: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_212f:
	/* 0x212f: je     2394 <tail_handle_ipv6+0x2394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9108ULL;
	}
x86_l_2135:
	/* 0x2135: test   BYTE PTR [rdx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_2139:
	/* 0x2139: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_213c:
	/* 0x213c: je     229d <tail_handle_ipv6+0x229d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8861ULL;
	}
x86_l_2142:
	/* 0x2142: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_214b:
	/* 0x214b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2154:
	/* 0x2154: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_215d:
	/* 0x215d: movzx  eax,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2162:
	/* 0x2162: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2167:
	/* 0x2167: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_216c:
	/* 0x216c: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2174:
	/* 0x2174: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2179:
	/* 0x2179: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2181:
	/* 0x2181: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2186:
	/* 0x2186: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_218d:
	/* 0x218d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2192:
	/* 0x2192: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2197:
	/* 0x2197: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2199:
	/* 0x2199: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_219c:
	/* 0x219c: je     2298 <tail_handle_ipv6+0x2298> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8856ULL;
	}
x86_l_21a2:
	/* 0x21a2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_21a5:
	/* 0x21a5: mov    r14,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_21ac:
	/* 0x21ac: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b0:
	/* 0x21b0: je     21c1 <tail_handle_ipv6+0x21c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21c1;
	}
x86_l_21b2:
	/* 0x21b2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_21b7:
	/* 0x21b7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21b9:
	/* 0x21b9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21bb:
	/* 0x21bb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_21bf:
	/* 0x21bf: jmp    21e4 <tail_handle_ipv6+0x21e4> */
	return 8676ULL;
x86_l_21c1:
	/* 0x21c1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_21c6:
	/* 0x21c6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c8:
	/* 0x21c8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21ca:
	/* 0x21ca: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_21ce:
	/* 0x21ce: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
	return 8664ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8664ULL: goto x86_l_21d8;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8676ULL: goto x86_l_21e4;
	case 8679ULL: goto x86_l_21e7;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8692ULL: goto x86_l_21f4;
	case 8697ULL: goto x86_l_21f9;
	case 8704ULL: goto x86_l_2200;
	case 8708ULL: goto x86_l_2204;
	case 8713ULL: goto x86_l_2209;
	case 8715ULL: goto x86_l_220b;
	case 8719ULL: goto x86_l_220f;
	case 8721ULL: goto x86_l_2211;
	case 8728ULL: goto x86_l_2218;
	case 8731ULL: goto x86_l_221b;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8747ULL: goto x86_l_222b;
	case 8754ULL: goto x86_l_2232;
	case 8759ULL: goto x86_l_2237;
	case 8764ULL: goto x86_l_223c;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8771ULL: goto x86_l_2243;
	case 8775ULL: goto x86_l_2247;
	case 8779ULL: goto x86_l_224b;
	case 8782ULL: goto x86_l_224e;
	case 8787ULL: goto x86_l_2253;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8801ULL: goto x86_l_2261;
	case 8806ULL: goto x86_l_2266;
	case 8811ULL: goto x86_l_226b;
	case 8813ULL: goto x86_l_226d;
	case 8816ULL: goto x86_l_2270;
	case 8819ULL: goto x86_l_2273;
	case 8825ULL: goto x86_l_2279;
	case 8832ULL: goto x86_l_2280;
	case 8835ULL: goto x86_l_2283;
	case 8837ULL: goto x86_l_2285;
	case 8844ULL: goto x86_l_228c;
	case 8849ULL: goto x86_l_2291;
	case 8854ULL: goto x86_l_2296;
	case 8856ULL: goto x86_l_2298;
	case 8861ULL: goto x86_l_229d;
	case 8864ULL: goto x86_l_22a0;
	case 8869ULL: goto x86_l_22a5;
	case 8871ULL: goto x86_l_22a7;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8882ULL: goto x86_l_22b2;
	case 8884ULL: goto x86_l_22b4;
	case 8892ULL: goto x86_l_22bc;
	case 8899ULL: goto x86_l_22c3;
	case 8903ULL: goto x86_l_22c7;
	case 8910ULL: goto x86_l_22ce;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8925ULL: goto x86_l_22dd;
	case 8928ULL: goto x86_l_22e0;
	case 8930ULL: goto x86_l_22e2;
	case 8933ULL: goto x86_l_22e5;
	case 8935ULL: goto x86_l_22e7;
	case 8939ULL: goto x86_l_22eb;
	case 8944ULL: goto x86_l_22f0;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8971ULL: goto x86_l_230b;
	case 8980ULL: goto x86_l_2314;
	case 8989ULL: goto x86_l_231d;
	case 8998ULL: goto x86_l_2326;
	case 9007ULL: goto x86_l_232f;
	case 9016ULL: goto x86_l_2338;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9037ULL: goto x86_l_234d;
	case 9043ULL: goto x86_l_2353;
	case 9049ULL: goto x86_l_2359;
	case 9056ULL: goto x86_l_2360;
	case 9058ULL: goto x86_l_2362;
	case 9063ULL: goto x86_l_2367;
	case 9070ULL: goto x86_l_236e;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9083ULL: goto x86_l_237b;
	case 9087ULL: goto x86_l_237f;
	case 9091ULL: goto x86_l_2383;
	case 9093ULL: goto x86_l_2385;
	case 9100ULL: goto x86_l_238c;
	case 9103ULL: goto x86_l_238f;
	case 9108ULL: goto x86_l_2394;
	case 9115ULL: goto x86_l_239b;
	case 9118ULL: goto x86_l_239e;
	case 9123ULL: goto x86_l_23a3;
	case 9129ULL: goto x86_l_23a9;
	case 9133ULL: goto x86_l_23ad;
	case 9136ULL: goto x86_l_23b0;
	case 9138ULL: goto x86_l_23b2;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9151ULL: goto x86_l_23bf;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9168ULL: goto x86_l_23d0;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9178ULL: goto x86_l_23da;
	case 9180ULL: goto x86_l_23dc;
	case 9187ULL: goto x86_l_23e3;
	case 9191ULL: goto x86_l_23e7;
	case 9195ULL: goto x86_l_23eb;
	case 9197ULL: goto x86_l_23ed;
	case 9203ULL: goto x86_l_23f3;
	case 9207ULL: goto x86_l_23f7;
	case 9209ULL: goto x86_l_23f9;
	case 9214ULL: goto x86_l_23fe;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9222ULL: goto x86_l_2406;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9231ULL: goto x86_l_240f;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9247ULL: goto x86_l_241f;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9259ULL: goto x86_l_242b;
	case 9263ULL: goto x86_l_242f;
	case 9266ULL: goto x86_l_2432;
	case 9269ULL: goto x86_l_2435;
	case 9274ULL: goto x86_l_243a;
	case 9279ULL: goto x86_l_243f;
	case 9283ULL: goto x86_l_2443;
	case 9285ULL: goto x86_l_2445;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9298ULL: goto x86_l_2452;
	case 9300ULL: goto x86_l_2454;
	case 9303ULL: goto x86_l_2457;
	case 9306ULL: goto x86_l_245a;
	case 9308ULL: goto x86_l_245c;
	case 9313ULL: goto x86_l_2461;
	case 9321ULL: goto x86_l_2469;
	case 9323ULL: goto x86_l_246b;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9329ULL: goto x86_l_2471;
	case 9331ULL: goto x86_l_2473;
	case 9333ULL: goto x86_l_2475;
	case 9337ULL: goto x86_l_2479;
	case 9341ULL: goto x86_l_247d;
	case 9348ULL: goto x86_l_2484;
	case 9350ULL: goto x86_l_2486;
	case 9357ULL: goto x86_l_248d;
	case 9360ULL: goto x86_l_2490;
	case 9362ULL: goto x86_l_2492;
	case 9371ULL: goto x86_l_249b;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9383ULL: goto x86_l_24a7;
	case 9388ULL: goto x86_l_24ac;
	case 9393ULL: goto x86_l_24b1;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9405ULL: goto x86_l_24bd;
	case 9407ULL: goto x86_l_24bf;
	case 9412ULL: goto x86_l_24c4;
	case 9418ULL: goto x86_l_24ca;
	case 9426ULL: goto x86_l_24d2;
	case 9433ULL: goto x86_l_24d9;
	case 9437ULL: goto x86_l_24dd;
	case 9440ULL: goto x86_l_24e0;
	case 9446ULL: goto x86_l_24e6;
	case 9453ULL: goto x86_l_24ed;
	case 9456ULL: goto x86_l_24f0;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9465ULL: goto x86_l_24f9;
	case 9467ULL: goto x86_l_24fb;
	case 9471ULL: goto x86_l_24ff;
	case 9473ULL: goto x86_l_2501;
	case 9478ULL: goto x86_l_2506;
	case 9480ULL: goto x86_l_2508;
	case 9482ULL: goto x86_l_250a;
	case 9486ULL: goto x86_l_250e;
	case 9496ULL: goto x86_l_2518;
	case 9499ULL: goto x86_l_251b;
	case 9504ULL: goto x86_l_2520;
	case 9508ULL: goto x86_l_2524;
	case 9517ULL: goto x86_l_252d;
	case 9526ULL: goto x86_l_2536;
	case 9535ULL: goto x86_l_253f;
	case 9540ULL: goto x86_l_2544;
	case 9545ULL: goto x86_l_2549;
	case 9550ULL: goto x86_l_254e;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9562ULL: goto x86_l_255a;
	case 9570ULL: goto x86_l_2562;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9603ULL: goto x86_l_2583;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9618ULL: goto x86_l_2592;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9630ULL: goto x86_l_259e;
	case 9639ULL: goto x86_l_25a7;
	case 9648ULL: goto x86_l_25b0;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9661ULL: goto x86_l_25bd;
	case 9666ULL: goto x86_l_25c2;
	case 9671ULL: goto x86_l_25c7;
	case 9678ULL: goto x86_l_25ce;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9690ULL: goto x86_l_25da;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9701ULL: goto x86_l_25e5;
	case 9703ULL: goto x86_l_25e7;
	case 9705ULL: goto x86_l_25e9;
	case 9713ULL: goto x86_l_25f1;
	case 9715ULL: goto x86_l_25f3;
	case 9718ULL: goto x86_l_25f6;
	case 9720ULL: goto x86_l_25f8;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9731ULL: goto x86_l_2603;
	case 9736ULL: goto x86_l_2608;
	case 9738ULL: goto x86_l_260a;
	case 9744ULL: goto x86_l_2610;
	case 9746ULL: goto x86_l_2612;
	case 9751ULL: goto x86_l_2617;
	case 9753ULL: goto x86_l_2619;
	case 9761ULL: goto x86_l_2621;
	case 9767ULL: goto x86_l_2627;
	case 9772ULL: goto x86_l_262c;
	case 9777ULL: goto x86_l_2631;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9795ULL: goto x86_l_2643;
	case 9802ULL: goto x86_l_264a;
	case 9806ULL: goto x86_l_264e;
	case 9811ULL: goto x86_l_2653;
	case 9815ULL: goto x86_l_2657;
	case 9820ULL: goto x86_l_265c;
	case 9824ULL: goto x86_l_2660;
	case 9827ULL: goto x86_l_2663;
	case 9829ULL: goto x86_l_2665;
	case 9837ULL: goto x86_l_266d;
	case 9839ULL: goto x86_l_266f;
	case 9847ULL: goto x86_l_2677;
	case 9850ULL: goto x86_l_267a;
	case 9860ULL: goto x86_l_2684;
	case 9863ULL: goto x86_l_2687;
	case 9871ULL: goto x86_l_268f;
	case 9873ULL: goto x86_l_2691;
	case 9881ULL: goto x86_l_2699;
	case 9884ULL: goto x86_l_269c;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9891ULL: goto x86_l_26a3;
	case 9897ULL: goto x86_l_26a9;
	case 9900ULL: goto x86_l_26ac;
	case 9902ULL: goto x86_l_26ae;
	case 9905ULL: goto x86_l_26b1;
	case 9910ULL: goto x86_l_26b6;
	case 9912ULL: goto x86_l_26b8;
	case 9918ULL: goto x86_l_26be;
	case 9923ULL: goto x86_l_26c3;
	case 9931ULL: goto x86_l_26cb;
	case 9934ULL: goto x86_l_26ce;
	case 9936ULL: goto x86_l_26d0;
	case 9939ULL: goto x86_l_26d3;
	case 9944ULL: goto x86_l_26d8;
	case 9952ULL: goto x86_l_26e0;
	case 9955ULL: goto x86_l_26e3;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9966ULL: goto x86_l_26ee;
	case 9971ULL: goto x86_l_26f3;
	case 9974ULL: goto x86_l_26f6;
	case 9979ULL: goto x86_l_26fb;
	case 9982ULL: goto x86_l_26fe;
	case 9984ULL: goto x86_l_2700;
	case 9986ULL: goto x86_l_2702;
	case 9992ULL: goto x86_l_2708;
	case 9997ULL: goto x86_l_270d;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10010ULL: goto x86_l_271a;
	case 10015ULL: goto x86_l_271f;
	case 10018ULL: goto x86_l_2722;
	case 10020ULL: goto x86_l_2724;
	case 10023ULL: goto x86_l_2727;
	case 10025ULL: goto x86_l_2729;
	case 10035ULL: goto x86_l_2733;
	case 10038ULL: goto x86_l_2736;
	case 10045ULL: goto x86_l_273d;
	case 10047ULL: goto x86_l_273f;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10065ULL: goto x86_l_2751;
	case 10068ULL: goto x86_l_2754;
	case 10071ULL: goto x86_l_2757;
	case 10075ULL: goto x86_l_275b;
	case 10081ULL: goto x86_l_2761;
	case 10084ULL: goto x86_l_2764;
	case 10086ULL: goto x86_l_2766;
	case 10088ULL: goto x86_l_2768;
	case 10091ULL: goto x86_l_276b;
	case 10093ULL: goto x86_l_276d;
	case 10096ULL: goto x86_l_2770;
	case 10102ULL: goto x86_l_2776;
	case 10104ULL: goto x86_l_2778;
	case 10114ULL: goto x86_l_2782;
	case 10117ULL: goto x86_l_2785;
	case 10124ULL: goto x86_l_278c;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10138ULL: goto x86_l_279a;
	case 10142ULL: goto x86_l_279e;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10155ULL: goto x86_l_27ab;
	case 10157ULL: goto x86_l_27ad;
	case 10162ULL: goto x86_l_27b2;
	case 10167ULL: goto x86_l_27b7;
	case 10170ULL: goto x86_l_27ba;
	case 10175ULL: goto x86_l_27bf;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10197ULL: goto x86_l_27d5;
	case 10202ULL: goto x86_l_27da;
	case 10210ULL: goto x86_l_27e2;
	case 10214ULL: goto x86_l_27e6;
	case 10218ULL: goto x86_l_27ea;
	case 10223ULL: goto x86_l_27ef;
	case 10226ULL: goto x86_l_27f2;
	case 10233ULL: goto x86_l_27f9;
	case 10236ULL: goto x86_l_27fc;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	case 10247ULL: goto x86_l_2807;
	case 10249ULL: goto x86_l_2809;
	case 10257ULL: goto x86_l_2811;
	case 10259ULL: goto x86_l_2813;
	case 10264ULL: goto x86_l_2818;
	case 10269ULL: goto x86_l_281d;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10284ULL: goto x86_l_282c;
	case 10289ULL: goto x86_l_2831;
	case 10294ULL: goto x86_l_2836;
	case 10296ULL: goto x86_l_2838;
	case 10304ULL: goto x86_l_2840;
	case 10310ULL: goto x86_l_2846;
	case 10313ULL: goto x86_l_2849;
	case 10315ULL: goto x86_l_284b;
	case 10320ULL: goto x86_l_2850;
	case 10324ULL: goto x86_l_2854;
	case 10330ULL: goto x86_l_285a;
	case 10338ULL: goto x86_l_2862;
	case 10346ULL: goto x86_l_286a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_21d8:
	/* 0x21d8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_21db:
	/* 0x21db: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_21e0:
	/* 0x21e0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_21e4:
	/* 0x21e4: mov    ecx,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21e7:
	/* 0x21e7: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21eb:
	/* 0x21eb: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_21f0:
	/* 0x21f0: movzx  ecx,WORD PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_21f4:
	/* 0x21f4: mov    WORD PTR [rsp+0x5c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_21f9:
	/* 0x21f9: mov    WORD PTR [rsp+0x5e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 403726925824ULL);
x86_l_2200:
	/* 0x2200: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2204:
	/* 0x2204: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_2209:
	/* 0x2209: and    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_220b:
	/* 0x220b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_220f:
	/* 0x220f: je     221e <tail_handle_ipv6+0x221e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_221e;
	}
x86_l_2211:
	/* 0x2211: mov    rsi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2218:
	/* 0x2218: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_221b:
	/* 0x221b: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_221e:
	/* 0x221e: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2220:
	/* 0x2220: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2223:
	/* 0x2223: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_2226:
	/* 0x2226: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_2229:
	/* 0x2229: jbe    2285 <tail_handle_ipv6+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2285;
	}
x86_l_222b:
	/* 0x222b: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_2232:
	/* 0x2232: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2237:
	/* 0x2237: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_223c:
	/* 0x223c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223e:
	/* 0x223e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2241:
	/* 0x2241: je     2285 <tail_handle_ipv6+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2285;
	}
x86_l_2243:
	/* 0x2243: mov    QWORD PTR [rbp+0x0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2247:
	/* 0x2247: mov    r15d,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224b:
	/* 0x224b: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_224e:
	/* 0x224e: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2253:
	/* 0x2253: je     229d <tail_handle_ipv6+0x229d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_229d;
	}
x86_l_2255:
	/* 0x2255: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225a:
	/* 0x225a: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_2261:
	/* 0x2261: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2266:
	/* 0x2266: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_226b:
	/* 0x226b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226d:
	/* 0x226d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2270:
	/* 0x2270: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2273:
	/* 0x2273: jne    230b <tail_handle_ipv6+0x230b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_230b;
	}
x86_l_2279:
	/* 0x2279: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_2280:
	/* 0x2280: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2283:
	/* 0x2283: jmp    2298 <tail_handle_ipv6+0x2298> */
	goto x86_l_2298;
x86_l_2285:
	/* 0x2285: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_228c:
	/* 0x228c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2291:
	/* 0x2291: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2296:
	/* 0x2296: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2298:
	/* 0x2298: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_229d:
	/* 0x229d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a0:
	/* 0x22a0: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_22a5:
	/* 0x22a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a7:
	/* 0x22a7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_22a9:
	/* 0x22a9: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_22ae:
	/* 0x22ae: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22b0:
	/* 0x22b0: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_22b2:
	/* 0x22b2: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22b4:
	/* 0x22b4: mov    WORD PTR [rsp+0xc2],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_22bc:
	/* 0x22bc: mov    r14,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_22c3:
	/* 0x22c3: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22c7:
	/* 0x22c7: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_22ce:
	/* 0x22ce: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_22d6:
	/* 0x22d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22db:
	/* 0x22db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22dd:
	/* 0x22dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22e0:
	/* 0x22e0: je     22e7 <tail_handle_ipv6+0x22e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e7;
	}
x86_l_22e2:
	/* 0x22e2: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e5:
	/* 0x22e5: jmp    22eb <tail_handle_ipv6+0x22eb> */
	goto x86_l_22eb;
x86_l_22e7:
	/* 0x22e7: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22eb:
	/* 0x22eb: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f0:
	/* 0x22f0: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_22f7:
	/* 0x22f7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22fc:
	/* 0x22fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2301:
	/* 0x2301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2303:
	/* 0x2303: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_2306:
	/* 0x2306: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2309:
	/* 0x2309: je     2385 <tail_handle_ipv6+0x2385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2385;
	}
x86_l_230b:
	/* 0x230b: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2314:
	/* 0x2314: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_231d:
	/* 0x231d: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2326:
	/* 0x2326: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_232f:
	/* 0x232f: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2338:
	/* 0x2338: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2341:
	/* 0x2341: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_2344:
	/* 0x2344: movzx  r15d,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_234d:
	/* 0x234d: mov    WORD PTR [rsp+0x54],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_2353:
	/* 0x2353: mov    WORD PTR [rsp+0x36],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2359:
	/* 0x2359: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2360:
	/* 0x2360: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2362:
	/* 0x2362: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2367:
	/* 0x2367: mov    r14,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_236e:
	/* 0x236e: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2372:
	/* 0x2372: je     23ca <tail_handle_ipv6+0x23ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ca;
	}
x86_l_2374:
	/* 0x2374: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_237b:
	/* 0x237b: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_237f:
	/* 0x237f: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2383:
	/* 0x2383: jmp    23d0 <tail_handle_ipv6+0x23d0> */
	goto x86_l_23d0;
x86_l_2385:
	/* 0x2385: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_238c:
	/* 0x238c: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_238f:
	/* 0x238f: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2394:
	/* 0x2394: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_239b:
	/* 0x239b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239e:
	/* 0x239e: mov    ecx,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967138ULL);
x86_l_23a3:
	/* 0x23a3: jne    32f4 <tail_handle_ipv6+0x32f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13044ULL;
	}
x86_l_23a9:
	/* 0x23a9: movzx  eax,BYTE PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_23ad:
	/* 0x23ad: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23b0:
	/* 0x23b0: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_23b2:
	/* 0x23b2: je     281d <tail_handle_ipv6+0x281d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_281d;
	}
x86_l_23b8:
	/* 0x23b8: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_23bd:
	/* 0x23bd: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_23bf:
	/* 0x23bf: je     2bfe <tail_handle_ipv6+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11262ULL;
	}
x86_l_23c5:
	/* 0x23c5: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_23ca:
	/* 0x23ca: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_23d0:
	/* 0x23d0: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_23d4:
	/* 0x23d4: jne    23f3 <tail_handle_ipv6+0x23f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23f3;
	}
x86_l_23d6:
	/* 0x23d6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23da:
	/* 0x23da: je     23ed <tail_handle_ipv6+0x23ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ed;
	}
x86_l_23dc:
	/* 0x23dc: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_23e3:
	/* 0x23e3: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_23e7:
	/* 0x23e7: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_23eb:
	/* 0x23eb: jmp    23f3 <tail_handle_ipv6+0x23f3> */
	goto x86_l_23f3;
x86_l_23ed:
	/* 0x23ed: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_23f3:
	/* 0x23f3: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f7:
	/* 0x23f7: je     2408 <tail_handle_ipv6+0x2408> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2408;
	}
x86_l_23f9:
	/* 0x23f9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_23fe:
	/* 0x23fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2400:
	/* 0x2400: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2402:
	/* 0x2402: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2406:
	/* 0x2406: jmp    242b <tail_handle_ipv6+0x242b> */
	goto x86_l_242b;
x86_l_2408:
	/* 0x2408: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_240d:
	/* 0x240d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_240f:
	/* 0x240f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2411:
	/* 0x2411: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2415:
	/* 0x2415: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_241f:
	/* 0x241f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2422:
	/* 0x2422: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2427:
	/* 0x2427: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_242b:
	/* 0x242b: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_242f:
	/* 0x242f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2432:
	/* 0x2432: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2435:
	/* 0x2435: mov    DWORD PTR [rsp+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_243a:
	/* 0x243a: movzx  edx,BYTE PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_243f:
	/* 0x243f: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2443:
	/* 0x2443: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_2445:
	/* 0x2445: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2449:
	/* 0x2449: je     245c <tail_handle_ipv6+0x245c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_245c;
	}
x86_l_244b:
	/* 0x244b: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2452:
	/* 0x2452: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2454:
	/* 0x2454: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_2457:
	/* 0x2457: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_245a:
	/* 0x245a: jmp    2461 <tail_handle_ipv6+0x2461> */
	goto x86_l_2461;
x86_l_245c:
	/* 0x245c: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_2461:
	/* 0x2461: mov    r15d,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2469:
	/* 0x2469: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_246b:
	/* 0x246b: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_246d:
	/* 0x246d: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_246f:
	/* 0x246f: jb     2475 <tail_handle_ipv6+0x2475> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2475;
	}
x86_l_2471:
	/* 0x2471: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_2473:
	/* 0x2473: je     2486 <tail_handle_ipv6+0x2486> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2486;
	}
x86_l_2475:
	/* 0x2475: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_2479:
	/* 0x2479: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_247d:
	/* 0x247d: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2484:
	/* 0x2484: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2486:
	/* 0x2486: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_248d:
	/* 0x248d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2490:
	/* 0x2490: je     24a2 <tail_handle_ipv6+0x24a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a2;
	}
x86_l_2492:
	/* 0x2492: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_249b:
	/* 0x249b: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_249d:
	/* 0x249d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24a2:
	/* 0x24a2: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24a7:
	/* 0x24a7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24ac:
	/* 0x24ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24b1:
	/* 0x24b1: mov    rdi,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_24b9:
	/* 0x24b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24bb:
	/* 0x24bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24bd:
	/* 0x24bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24bf:
	/* 0x24bf: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24c4:
	/* 0x24c4: js     355b <tail_handle_ipv6+0x355b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13659ULL;
	}
x86_l_24ca:
	/* 0x24ca: movzx  eax,BYTE PTR [rsp+0xa7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 167ULL);
x86_l_24d2:
	/* 0x24d2: mov    BYTE PTR [rsp+0x95],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 149ULL);
x86_l_24d9:
	/* 0x24d9: test   BYTE PTR [rdx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_24dd:
	/* 0x24dd: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_24e0:
	/* 0x24e0: je     2596 <tail_handle_ipv6+0x2596> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2596;
	}
x86_l_24e6:
	/* 0x24e6: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_24ed:
	/* 0x24ed: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24f0:
	/* 0x24f0: je     2501 <tail_handle_ipv6+0x2501> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2501;
	}
x86_l_24f2:
	/* 0x24f2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_24f7:
	/* 0x24f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24f9:
	/* 0x24f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_24fb:
	/* 0x24fb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_24ff:
	/* 0x24ff: jmp    2524 <tail_handle_ipv6+0x2524> */
	goto x86_l_2524;
x86_l_2501:
	/* 0x2501: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2506:
	/* 0x2506: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2508:
	/* 0x2508: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_250a:
	/* 0x250a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_250e:
	/* 0x250e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2518:
	/* 0x2518: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_251b:
	/* 0x251b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2520:
	/* 0x2520: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2524:
	/* 0x2524: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_252d:
	/* 0x252d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2536:
	/* 0x2536: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_253f:
	/* 0x253f: movzx  ecx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2544:
	/* 0x2544: mov    WORD PTR [rsp+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2549:
	/* 0x2549: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_254e:
	/* 0x254e: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2550:
	/* 0x2550: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2555:
	/* 0x2555: mov    DWORD PTR [rsp+0x60],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_255a:
	/* 0x255a: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_2562:
	/* 0x2562: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_256a:
	/* 0x256a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_256f:
	/* 0x256f: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2577:
	/* 0x2577: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_257c:
	/* 0x257c: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_2583:
	/* 0x2583: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2588:
	/* 0x2588: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_258d:
	/* 0x258d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2592:
	/* 0x2592: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2594:
	/* 0x2594: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2596:
	/* 0x2596: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_259e:
	/* 0x259e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_25a7:
	/* 0x25a7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_25b0:
	/* 0x25b0: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b4:
	/* 0x25b4: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25b8:
	/* 0x25b8: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25bd:
	/* 0x25bd: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_25c2:
	/* 0x25c2: mov    BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_25c7:
	/* 0x25c7: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_25ce:
	/* 0x25ce: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25d3:
	/* 0x25d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_25d8:
	/* 0x25d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25da:
	/* 0x25da: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_25dd:
	/* 0x25dd: movzx  eax,BYTE PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_25e2:
	/* 0x25e2: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_25e5:
	/* 0x25e5: je     2612 <tail_handle_ipv6+0x2612> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2612;
	}
x86_l_25e7:
	/* 0x25e7: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_25e9:
	/* 0x25e9: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_25f1:
	/* 0x25f1: jne    2627 <tail_handle_ipv6+0x2627> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2627;
	}
x86_l_25f3:
	/* 0x25f3: test   rdi,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_64);
x86_l_25f6:
	/* 0x25f6: je     2627 <tail_handle_ipv6+0x2627> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2627;
	}
x86_l_25f8:
	/* 0x25f8: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_25fb:
	/* 0x25fb: movzx  eax,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_2600:
	/* 0x2600: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2603:
	/* 0x2603: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_2608:
	/* 0x2608: and    al,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_260a:
	/* 0x260a: jne    32f4 <tail_handle_ipv6+0x32f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13044ULL;
	}
x86_l_2610:
	/* 0x2610: jmp    2627 <tail_handle_ipv6+0x2627> */
	goto x86_l_2627;
x86_l_2612:
	/* 0x2612: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_2617:
	/* 0x2617: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_2619:
	/* 0x2619: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2621:
	/* 0x2621: jne    32f4 <tail_handle_ipv6+0x32f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13044ULL;
	}
x86_l_2627:
	/* 0x2627: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_262c:
	/* 0x262c: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2631:
	/* 0x2631: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2636:
	/* 0x2636: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_263b:
	/* 0x263b: movzx  eax,WORD PTR [rsp+0x92] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 146ULL);
x86_l_2643:
	/* 0x2643: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_264a:
	/* 0x264a: mov    rax,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_264e:
	/* 0x264e: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2653:
	/* 0x2653: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2657:
	/* 0x2657: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_265c:
	/* 0x265c: movzx  eax,WORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_2660:
	/* 0x2660: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_2663:
	/* 0x2663: je     266d <tail_handle_ipv6+0x266d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_266d;
	}
x86_l_2665:
	/* 0x2665: mov    WORD PTR [rsp+0x92],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 146ULL);
x86_l_266d:
	/* 0x266d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266f:
	/* 0x266f: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2677:
	/* 0x2677: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_267a:
	/* 0x267a: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2684:
	/* 0x2684: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2687:
	/* 0x2687: mov    QWORD PTR [rsp+0xc8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_268f:
	/* 0x268f: jne    26e0 <tail_handle_ipv6+0x26e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26e0;
	}
x86_l_2691:
	/* 0x2691: movzx  eax,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_2699:
	/* 0x2699: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_269c:
	/* 0x269c: je     26d0 <tail_handle_ipv6+0x26d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d0;
	}
x86_l_269e:
	/* 0x269e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_26a1:
	/* 0x26a1: je     26b8 <tail_handle_ipv6+0x26b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b8;
	}
x86_l_26a3:
	/* 0x26a3: mov    r13d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 0ULL);
x86_l_26a9:
	/* 0x26a9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_26ac:
	/* 0x26ac: jne    26e3 <tail_handle_ipv6+0x26e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_26e3;
	}
x86_l_26ae:
	/* 0x26ae: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26b1:
	/* 0x26b1: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_26b6:
	/* 0x26b6: jmp    26d8 <tail_handle_ipv6+0x26d8> */
	goto x86_l_26d8;
x86_l_26b8:
	/* 0x26b8: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_26be:
	/* 0x26be: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_26c3:
	/* 0x26c3: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_26cb:
	/* 0x26cb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26ce:
	/* 0x26ce: jmp    26e3 <tail_handle_ipv6+0x26e3> */
	goto x86_l_26e3;
x86_l_26d0:
	/* 0x26d0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26d3:
	/* 0x26d3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26d8:
	/* 0x26d8: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_26e0:
	/* 0x26e0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26e3:
	/* 0x26e3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26e6:
	/* 0x26e6: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_26eb:
	/* 0x26eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26ee:
	/* 0x26ee: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_26f3:
	/* 0x26f3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_26f6:
	/* 0x26f6: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_26fb:
	/* 0x26fb: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26fe:
	/* 0x26fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2700:
	/* 0x2700: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2702:
	/* 0x2702: js     2813 <tail_handle_ipv6+0x2813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2813;
	}
x86_l_2708:
	/* 0x2708: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_270d:
	/* 0x270d: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2712:
	/* 0x2712: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2717:
	/* 0x2717: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_271a:
	/* 0x271a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_271f:
	/* 0x271f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2722:
	/* 0x2722: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2724:
	/* 0x2724: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_2727:
	/* 0x2727: je     2744 <tail_handle_ipv6+0x2744> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2744;
	}
x86_l_2729:
	/* 0x2729: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2733:
	/* 0x2733: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2736:
	/* 0x2736: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_273d:
	/* 0x273d: je     279a <tail_handle_ipv6+0x279a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_279a;
	}
x86_l_273f:
	/* 0x273f: jmp    2809 <tail_handle_ipv6+0x2809> */
	goto x86_l_2809;
x86_l_2744:
	/* 0x2744: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2749:
	/* 0x2749: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2751:
	/* 0x2751: lea    esi,[rdx+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2754:
	/* 0x2754: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_2757:
	/* 0x2757: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_275b:
	/* 0x275b: mov    r9d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 11ULL);
x86_l_2761:
	/* 0x2761: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2764:
	/* 0x2764: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2766:
	/* 0x2766: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2768:
	/* 0x2768: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_276b:
	/* 0x276b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_276d:
	/* 0x276d: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_2770:
	/* 0x2770: and    ecx,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_2776:
	/* 0x2776: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2778:
	/* 0x2778: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2782:
	/* 0x2782: test   r15,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_2785:
	/* 0x2785: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_278c:
	/* 0x278c: jne    2836 <tail_handle_ipv6+0x2836> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2836;
	}
x86_l_2792:
	/* 0x2792: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2794:
	/* 0x2794: js     2836 <tail_handle_ipv6+0x2836> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2836;
	}
x86_l_279a:
	/* 0x279a: movzx  eax,WORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_279e:
	/* 0x279e: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_27a1:
	/* 0x27a1: je     2809 <tail_handle_ipv6+0x2809> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2809;
	}
x86_l_27a3:
	/* 0x27a3: cmp    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_27ab:
	/* 0x27ab: je     2809 <tail_handle_ipv6+0x2809> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2809;
	}
x86_l_27ad:
	/* 0x27ad: mov    WORD PTR [rsp+0x58],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27b2:
	/* 0x27b2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b7:
	/* 0x27b7: lea    esi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_27ba:
	/* 0x27ba: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27bf:
	/* 0x27bf: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_27c4:
	/* 0x27c4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27c7:
	/* 0x27c7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_27cc:
	/* 0x27cc: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27cf:
	/* 0x27cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d1:
	/* 0x27d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27d3:
	/* 0x27d3: js     2813 <tail_handle_ipv6+0x2813> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2813;
	}
x86_l_27d5:
	/* 0x27d5: movzx  ecx,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_27da:
	/* 0x27da: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_27e2:
	/* 0x27e2: add    esi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_27e6:
	/* 0x27e6: or     r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_27ea:
	/* 0x27ea: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_27ef:
	/* 0x27ef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_27f2:
	/* 0x27f2: mov    edx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_27f9:
	/* 0x27f9: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_27fc:
	/* 0x27fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27fe:
	/* 0x27fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2800:
	/* 0x2800: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_2807:
	/* 0x2807: js     2831 <tail_handle_ipv6+0x2831> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2831;
	}
x86_l_2809:
	/* 0x2809: mov    r8,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2811:
	/* 0x2811: jmp    2846 <tail_handle_ipv6+0x2846> */
	goto x86_l_2846;
x86_l_2813:
	/* 0x2813: mov    ecx,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967155ULL);
x86_l_2818:
	/* 0x2818: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_281d:
	/* 0x281d: test   BYTE PTR [rdx+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_2821:
	/* 0x2821: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_2826:
	/* 0x2826: je     2bfe <tail_handle_ipv6+0x2bfe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11262ULL;
	}
x86_l_282c:
	/* 0x282c: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_2831:
	/* 0x2831: mov    edx,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967142ULL);
x86_l_2836:
	/* 0x2836: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2838:
	/* 0x2838: mov    r8,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2840:
	/* 0x2840: js     3722 <tail_handle_ipv6+0x3722> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14114ULL;
	}
x86_l_2846:
	/* 0x2846: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_2849:
	/* 0x2849: jne    285a <tail_handle_ipv6+0x285a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_285a;
	}
x86_l_284b:
	/* 0x284b: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2850:
	/* 0x2850: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_2854:
	/* 0x2854: js     2abd <tail_handle_ipv6+0x2abd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10941ULL;
	}
x86_l_285a:
	/* 0x285a: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2862:
	/* 0x2862: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_286a:
	/* 0x286a: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 10351ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10351ULL: goto x86_l_286f;
	case 10356ULL: goto x86_l_2874;
	case 10364ULL: goto x86_l_287c;
	case 10372ULL: goto x86_l_2884;
	case 10377ULL: goto x86_l_2889;
	case 10382ULL: goto x86_l_288e;
	case 10390ULL: goto x86_l_2896;
	case 10399ULL: goto x86_l_289f;
	case 10403ULL: goto x86_l_28a3;
	case 10405ULL: goto x86_l_28a5;
	case 10412ULL: goto x86_l_28ac;
	case 10414ULL: goto x86_l_28ae;
	case 10421ULL: goto x86_l_28b5;
	case 10429ULL: goto x86_l_28bd;
	case 10436ULL: goto x86_l_28c4;
	case 10439ULL: goto x86_l_28c7;
	case 10441ULL: goto x86_l_28c9;
	case 10450ULL: goto x86_l_28d2;
	case 10452ULL: goto x86_l_28d4;
	case 10455ULL: goto x86_l_28d7;
	case 10464ULL: goto x86_l_28e0;
	case 10473ULL: goto x86_l_28e9;
	case 10483ULL: goto x86_l_28f3;
	case 10488ULL: goto x86_l_28f8;
	case 10495ULL: goto x86_l_28ff;
	case 10500ULL: goto x86_l_2904;
	case 10505ULL: goto x86_l_2909;
	case 10507ULL: goto x86_l_290b;
	case 10510ULL: goto x86_l_290e;
	case 10512ULL: goto x86_l_2910;
	case 10515ULL: goto x86_l_2913;
	case 10519ULL: goto x86_l_2917;
	case 10521ULL: goto x86_l_2919;
	case 10530ULL: goto x86_l_2922;
	case 10535ULL: goto x86_l_2927;
	case 10542ULL: goto x86_l_292e;
	case 10547ULL: goto x86_l_2933;
	case 10552ULL: goto x86_l_2938;
	case 10557ULL: goto x86_l_293d;
	case 10559ULL: goto x86_l_293f;
	case 10561ULL: goto x86_l_2941;
	case 10571ULL: goto x86_l_294b;
	case 10574ULL: goto x86_l_294e;
	case 10576ULL: goto x86_l_2950;
	case 10580ULL: goto x86_l_2954;
	case 10582ULL: goto x86_l_2956;
	case 10587ULL: goto x86_l_295b;
	case 10590ULL: goto x86_l_295e;
	case 10593ULL: goto x86_l_2961;
	case 10598ULL: goto x86_l_2966;
	case 10601ULL: goto x86_l_2969;
	case 10606ULL: goto x86_l_296e;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10616ULL: goto x86_l_2978;
	case 10619ULL: goto x86_l_297b;
	case 10621ULL: goto x86_l_297d;
	case 10626ULL: goto x86_l_2982;
	case 10629ULL: goto x86_l_2985;
	case 10634ULL: goto x86_l_298a;
	case 10637ULL: goto x86_l_298d;
	case 10643ULL: goto x86_l_2993;
	case 10649ULL: goto x86_l_2999;
	case 10652ULL: goto x86_l_299c;
	case 10654ULL: goto x86_l_299e;
	case 10657ULL: goto x86_l_29a1;
	case 10660ULL: goto x86_l_29a4;
	case 10665ULL: goto x86_l_29a9;
	case 10670ULL: goto x86_l_29ae;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10678ULL: goto x86_l_29b6;
	case 10680ULL: goto x86_l_29b8;
	case 10684ULL: goto x86_l_29bc;
	case 10687ULL: goto x86_l_29bf;
	case 10689ULL: goto x86_l_29c1;
	case 10693ULL: goto x86_l_29c5;
	case 10696ULL: goto x86_l_29c8;
	case 10698ULL: goto x86_l_29ca;
	case 10704ULL: goto x86_l_29d0;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10721ULL: goto x86_l_29e1;
	case 10728ULL: goto x86_l_29e8;
	case 10730ULL: goto x86_l_29ea;
	case 10738ULL: goto x86_l_29f2;
	case 10742ULL: goto x86_l_29f6;
	case 10747ULL: goto x86_l_29fb;
	case 10749ULL: goto x86_l_29fd;
	case 10756ULL: goto x86_l_2a04;
	case 10758ULL: goto x86_l_2a06;
	case 10765ULL: goto x86_l_2a0d;
	case 10774ULL: goto x86_l_2a16;
	case 10783ULL: goto x86_l_2a1f;
	case 10792ULL: goto x86_l_2a28;
	case 10801ULL: goto x86_l_2a31;
	case 10810ULL: goto x86_l_2a3a;
	case 10815ULL: goto x86_l_2a3f;
	case 10823ULL: goto x86_l_2a47;
	case 10832ULL: goto x86_l_2a50;
	case 10841ULL: goto x86_l_2a59;
	case 10848ULL: goto x86_l_2a60;
	case 10855ULL: goto x86_l_2a67;
	case 10859ULL: goto x86_l_2a6b;
	case 10861ULL: goto x86_l_2a6d;
	case 10868ULL: goto x86_l_2a74;
	case 10872ULL: goto x86_l_2a78;
	case 10876ULL: goto x86_l_2a7c;
	case 10878ULL: goto x86_l_2a7e;
	case 10884ULL: goto x86_l_2a84;
	case 10888ULL: goto x86_l_2a88;
	case 10894ULL: goto x86_l_2a8e;
	case 10901ULL: goto x86_l_2a95;
	case 10905ULL: goto x86_l_2a99;
	case 10911ULL: goto x86_l_2a9f;
	case 10918ULL: goto x86_l_2aa6;
	case 10922ULL: goto x86_l_2aaa;
	case 10926ULL: goto x86_l_2aae;
	case 10928ULL: goto x86_l_2ab0;
	case 10933ULL: goto x86_l_2ab5;
	case 10936ULL: goto x86_l_2ab8;
	case 10941ULL: goto x86_l_2abd;
	case 10948ULL: goto x86_l_2ac4;
	case 10956ULL: goto x86_l_2acc;
	case 10959ULL: goto x86_l_2acf;
	case 10966ULL: goto x86_l_2ad6;
	case 10969ULL: goto x86_l_2ad9;
	case 10976ULL: goto x86_l_2ae0;
	case 10979ULL: goto x86_l_2ae3;
	case 10986ULL: goto x86_l_2aea;
	case 10989ULL: goto x86_l_2aed;
	case 10996ULL: goto x86_l_2af4;
	case 10999ULL: goto x86_l_2af7;
	case 11006ULL: goto x86_l_2afe;
	case 11012ULL: goto x86_l_2b04;
	case 11017ULL: goto x86_l_2b09;
	case 11020ULL: goto x86_l_2b0c;
	case 11025ULL: goto x86_l_2b11;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11043ULL: goto x86_l_2b23;
	case 11047ULL: goto x86_l_2b27;
	case 11049ULL: goto x86_l_2b29;
	case 11054ULL: goto x86_l_2b2e;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11062ULL: goto x86_l_2b36;
	case 11064ULL: goto x86_l_2b38;
	case 11069ULL: goto x86_l_2b3d;
	case 11071ULL: goto x86_l_2b3f;
	case 11073ULL: goto x86_l_2b41;
	case 11077ULL: goto x86_l_2b45;
	case 11087ULL: goto x86_l_2b4f;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11099ULL: goto x86_l_2b5b;
	case 11103ULL: goto x86_l_2b5f;
	case 11106ULL: goto x86_l_2b62;
	case 11109ULL: goto x86_l_2b65;
	case 11114ULL: goto x86_l_2b6a;
	case 11119ULL: goto x86_l_2b6f;
	case 11123ULL: goto x86_l_2b73;
	case 11125ULL: goto x86_l_2b75;
	case 11129ULL: goto x86_l_2b79;
	case 11131ULL: goto x86_l_2b7b;
	case 11138ULL: goto x86_l_2b82;
	case 11140ULL: goto x86_l_2b84;
	case 11143ULL: goto x86_l_2b87;
	case 11146ULL: goto x86_l_2b8a;
	case 11148ULL: goto x86_l_2b8c;
	case 11153ULL: goto x86_l_2b91;
	case 11155ULL: goto x86_l_2b93;
	case 11157ULL: goto x86_l_2b95;
	case 11159ULL: goto x86_l_2b97;
	case 11161ULL: goto x86_l_2b99;
	case 11163ULL: goto x86_l_2b9b;
	case 11165ULL: goto x86_l_2b9d;
	case 11169ULL: goto x86_l_2ba1;
	case 11173ULL: goto x86_l_2ba5;
	case 11180ULL: goto x86_l_2bac;
	case 11182ULL: goto x86_l_2bae;
	case 11189ULL: goto x86_l_2bb5;
	case 11192ULL: goto x86_l_2bb8;
	case 11194ULL: goto x86_l_2bba;
	case 11203ULL: goto x86_l_2bc3;
	case 11205ULL: goto x86_l_2bc5;
	case 11210ULL: goto x86_l_2bca;
	case 11215ULL: goto x86_l_2bcf;
	case 11220ULL: goto x86_l_2bd4;
	case 11225ULL: goto x86_l_2bd9;
	case 11228ULL: goto x86_l_2bdc;
	case 11230ULL: goto x86_l_2bde;
	case 11232ULL: goto x86_l_2be0;
	case 11234ULL: goto x86_l_2be2;
	case 11240ULL: goto x86_l_2be8;
	case 11242ULL: goto x86_l_2bea;
	case 11251ULL: goto x86_l_2bf3;
	case 11256ULL: goto x86_l_2bf8;
	case 11262ULL: goto x86_l_2bfe;
	case 11265ULL: goto x86_l_2c01;
	case 11267ULL: goto x86_l_2c03;
	case 11273ULL: goto x86_l_2c09;
	case 11276ULL: goto x86_l_2c0c;
	case 11281ULL: goto x86_l_2c11;
	case 11287ULL: goto x86_l_2c17;
	case 11291ULL: goto x86_l_2c1b;
	case 11294ULL: goto x86_l_2c1e;
	case 11298ULL: goto x86_l_2c22;
	case 11301ULL: goto x86_l_2c25;
	case 11304ULL: goto x86_l_2c28;
	case 11310ULL: goto x86_l_2c2e;
	case 11318ULL: goto x86_l_2c36;
	case 11322ULL: goto x86_l_2c3a;
	case 11326ULL: goto x86_l_2c3e;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11341ULL: goto x86_l_2c4d;
	case 11348ULL: goto x86_l_2c54;
	case 11353ULL: goto x86_l_2c59;
	case 11358ULL: goto x86_l_2c5e;
	case 11360ULL: goto x86_l_2c60;
	case 11363ULL: goto x86_l_2c63;
	case 11365ULL: goto x86_l_2c65;
	case 11369ULL: goto x86_l_2c69;
	case 11375ULL: goto x86_l_2c6f;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11390ULL: goto x86_l_2c7e;
	case 11395ULL: goto x86_l_2c83;
	case 11397ULL: goto x86_l_2c85;
	case 11399ULL: goto x86_l_2c87;
	case 11404ULL: goto x86_l_2c8c;
	case 11406ULL: goto x86_l_2c8e;
	case 11412ULL: goto x86_l_2c94;
	case 11418ULL: goto x86_l_2c9a;
	case 11423ULL: goto x86_l_2c9f;
	case 11426ULL: goto x86_l_2ca2;
	case 11431ULL: goto x86_l_2ca7;
	case 11434ULL: goto x86_l_2caa;
	case 11439ULL: goto x86_l_2caf;
	case 11444ULL: goto x86_l_2cb4;
	case 11447ULL: goto x86_l_2cb7;
	case 11449ULL: goto x86_l_2cb9;
	case 11451ULL: goto x86_l_2cbb;
	case 11457ULL: goto x86_l_2cc1;
	case 11464ULL: goto x86_l_2cc8;
	case 11467ULL: goto x86_l_2ccb;
	case 11469ULL: goto x86_l_2ccd;
	case 11476ULL: goto x86_l_2cd4;
	case 11478ULL: goto x86_l_2cd6;
	case 11480ULL: goto x86_l_2cd8;
	case 11483ULL: goto x86_l_2cdb;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11493ULL: goto x86_l_2ce5;
	case 11498ULL: goto x86_l_2cea;
	case 11501ULL: goto x86_l_2ced;
	case 11507ULL: goto x86_l_2cf3;
	case 11509ULL: goto x86_l_2cf5;
	case 11512ULL: goto x86_l_2cf8;
	case 11517ULL: goto x86_l_2cfd;
	case 11519ULL: goto x86_l_2cff;
	case 11521ULL: goto x86_l_2d01;
	case 11523ULL: goto x86_l_2d03;
	case 11528ULL: goto x86_l_2d08;
	case 11531ULL: goto x86_l_2d0b;
	case 11533ULL: goto x86_l_2d0d;
	case 11538ULL: goto x86_l_2d12;
	case 11541ULL: goto x86_l_2d15;
	case 11548ULL: goto x86_l_2d1c;
	case 11551ULL: goto x86_l_2d1f;
	case 11556ULL: goto x86_l_2d24;
	case 11563ULL: goto x86_l_2d2b;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11576ULL: goto x86_l_2d38;
	case 11581ULL: goto x86_l_2d3d;
	case 11584ULL: goto x86_l_2d40;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11596ULL: goto x86_l_2d4c;
	case 11598ULL: goto x86_l_2d4e;
	case 11604ULL: goto x86_l_2d54;
	case 11609ULL: goto x86_l_2d59;
	case 11611ULL: goto x86_l_2d5b;
	case 11617ULL: goto x86_l_2d61;
	case 11627ULL: goto x86_l_2d6b;
	case 11632ULL: goto x86_l_2d70;
	case 11635ULL: goto x86_l_2d73;
	case 11637ULL: goto x86_l_2d75;
	case 11641ULL: goto x86_l_2d79;
	case 11648ULL: goto x86_l_2d80;
	case 11653ULL: goto x86_l_2d85;
	case 11658ULL: goto x86_l_2d8a;
	case 11660ULL: goto x86_l_2d8c;
	case 11663ULL: goto x86_l_2d8f;
	case 11665ULL: goto x86_l_2d91;
	case 11669ULL: goto x86_l_2d95;
	case 11675ULL: goto x86_l_2d9b;
	case 11679ULL: goto x86_l_2d9f;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11690ULL: goto x86_l_2daa;
	case 11695ULL: goto x86_l_2daf;
	case 11697ULL: goto x86_l_2db1;
	case 11699ULL: goto x86_l_2db3;
	case 11704ULL: goto x86_l_2db8;
	case 11706ULL: goto x86_l_2dba;
	case 11712ULL: goto x86_l_2dc0;
	case 11718ULL: goto x86_l_2dc6;
	case 11723ULL: goto x86_l_2dcb;
	case 11726ULL: goto x86_l_2dce;
	case 11731ULL: goto x86_l_2dd3;
	case 11734ULL: goto x86_l_2dd6;
	case 11739ULL: goto x86_l_2ddb;
	case 11744ULL: goto x86_l_2de0;
	case 11747ULL: goto x86_l_2de3;
	case 11749ULL: goto x86_l_2de5;
	case 11751ULL: goto x86_l_2de7;
	case 11757ULL: goto x86_l_2ded;
	case 11761ULL: goto x86_l_2df1;
	case 11766ULL: goto x86_l_2df6;
	case 11770ULL: goto x86_l_2dfa;
	case 11775ULL: goto x86_l_2dff;
	case 11780ULL: goto x86_l_2e04;
	case 11785ULL: goto x86_l_2e09;
	case 11788ULL: goto x86_l_2e0c;
	case 11793ULL: goto x86_l_2e11;
	case 11798ULL: goto x86_l_2e16;
	case 11800ULL: goto x86_l_2e18;
	case 11802ULL: goto x86_l_2e1a;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11815ULL: goto x86_l_2e27;
	case 11821ULL: goto x86_l_2e2d;
	case 11823ULL: goto x86_l_2e2f;
	case 11827ULL: goto x86_l_2e33;
	case 11832ULL: goto x86_l_2e38;
	case 11838ULL: goto x86_l_2e3e;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11851ULL: goto x86_l_2e4b;
	case 11857ULL: goto x86_l_2e51;
	case 11860ULL: goto x86_l_2e54;
	case 11862ULL: goto x86_l_2e56;
	case 11868ULL: goto x86_l_2e5c;
	case 11873ULL: goto x86_l_2e61;
	case 11876ULL: goto x86_l_2e64;
	case 11881ULL: goto x86_l_2e69;
	case 11886ULL: goto x86_l_2e6e;
	case 11889ULL: goto x86_l_2e71;
	case 11892ULL: goto x86_l_2e74;
	case 11897ULL: goto x86_l_2e79;
	case 11899ULL: goto x86_l_2e7b;
	case 11905ULL: goto x86_l_2e81;
	case 11910ULL: goto x86_l_2e86;
	case 11915ULL: goto x86_l_2e8b;
	case 11918ULL: goto x86_l_2e8e;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11928ULL: goto x86_l_2e98;
	case 11930ULL: goto x86_l_2e9a;
	case 11932ULL: goto x86_l_2e9c;
	case 11938ULL: goto x86_l_2ea2;
	case 11941ULL: goto x86_l_2ea5;
	case 11946ULL: goto x86_l_2eaa;
	case 11956ULL: goto x86_l_2eb4;
	case 11961ULL: goto x86_l_2eb9;
	case 11965ULL: goto x86_l_2ebd;
	case 11967ULL: goto x86_l_2ebf;
	case 11973ULL: goto x86_l_2ec5;
	case 11980ULL: goto x86_l_2ecc;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11992ULL: goto x86_l_2ed8;
	case 11995ULL: goto x86_l_2edb;
	case 11998ULL: goto x86_l_2ede;
	case 12001ULL: goto x86_l_2ee1;
	case 12007ULL: goto x86_l_2ee7;
	case 12011ULL: goto x86_l_2eeb;
	case 12017ULL: goto x86_l_2ef1;
	case 12022ULL: goto x86_l_2ef6;
	default: return 0xffffffffffffffffULL;
	}
x86_l_286f:
	/* 0x286f: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2874:
	/* 0x2874: mov    QWORD PTR [rsp+0x88],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_287c:
	/* 0x287c: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2884:
	/* 0x2884: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2889:
	/* 0x2889: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_288e:
	/* 0x288e: rol    DWORD PTR [rsp+0x90],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 618475290640ULL);
x86_l_2896:
	/* 0x2896: movzx  r13d,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_289f:
	/* 0x289f: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_28a3:
	/* 0x28a3: je     28ae <tail_handle_ipv6+0x28ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28ae;
	}
x86_l_28a5:
	/* 0x28a5: mov    r12,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_28ac:
	/* 0x28ac: jmp    28b5 <tail_handle_ipv6+0x28b5> */
	goto x86_l_28b5;
x86_l_28ae:
	/* 0x28ae: mov    r12,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_28b5:
	/* 0x28b5: mov    BYTE PTR [rsp+0x95],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 639950127104ULL);
x86_l_28bd:
	/* 0x28bd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c4:
	/* 0x28c4: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28c7:
	/* 0x28c7: je     2941 <tail_handle_ipv6+0x2941> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2941;
	}
x86_l_28c9:
	/* 0x28c9: cmp    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_28d2:
	/* 0x28d2: je     2941 <tail_handle_ipv6+0x2941> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2941;
	}
x86_l_28d4:
	/* 0x28d4: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28d7:
	/* 0x28d7: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_28e0:
	/* 0x28e0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_28e9:
	/* 0x28e9: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_28f3:
	/* 0x28f3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28f8:
	/* 0x28f8: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_28ff:
	/* 0x28ff: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2904:
	/* 0x2904: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2909:
	/* 0x2909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290b:
	/* 0x290b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_290e:
	/* 0x290e: je     2919 <tail_handle_ipv6+0x2919> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2919;
	}
x86_l_2910:
	/* 0x2910: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2913:
	/* 0x2913: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2917:
	/* 0x2917: jmp    2941 <tail_handle_ipv6+0x2941> */
	goto x86_l_2941;
x86_l_2919:
	/* 0x2919: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2922:
	/* 0x2922: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2927:
	/* 0x2927: mov    rdi,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_292e:
	/* 0x292e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2933:
	/* 0x2933: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2938:
	/* 0x2938: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_293d:
	/* 0x293d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_293f:
	/* 0x293f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2941:
	/* 0x2941: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_294b:
	/* 0x294b: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_294e:
	/* 0x294e: jne    299e <tail_handle_ipv6+0x299e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_299e;
	}
x86_l_2950:
	/* 0x2950: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_2954:
	/* 0x2954: jne    299e <tail_handle_ipv6+0x299e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_299e;
	}
x86_l_2956:
	/* 0x2956: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_295b:
	/* 0x295b: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_295e:
	/* 0x295e: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2961:
	/* 0x2961: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2966:
	/* 0x2966: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2969:
	/* 0x2969: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_296e:
	/* 0x296e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2970:
	/* 0x2970: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2972:
	/* 0x2972: js     2ab0 <tail_handle_ipv6+0x2ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2ab0;
	}
x86_l_2978:
	/* 0x2978: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_297b:
	/* 0x297b: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_297d:
	/* 0x297d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_2982:
	/* 0x2982: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2985:
	/* 0x2985: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_298a:
	/* 0x298a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_298d:
	/* 0x298d: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_2993:
	/* 0x2993: jne    3575 <tail_handle_ipv6+0x3575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13685ULL;
	}
x86_l_2999:
	/* 0x2999: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_299c:
	/* 0x299c: jmp    29a4 <tail_handle_ipv6+0x29a4> */
	goto x86_l_29a4;
x86_l_299e:
	/* 0x299e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29a1:
	/* 0x29a1: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29a4:
	/* 0x29a4: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_29a9:
	/* 0x29a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29ae:
	/* 0x29ae: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_29b1:
	/* 0x29b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b3:
	/* 0x29b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29b6:
	/* 0x29b6: je     29e1 <tail_handle_ipv6+0x29e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e1;
	}
x86_l_29b8:
	/* 0x29b8: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_29bc:
	/* 0x29bc: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_29bf:
	/* 0x29bf: je     29e1 <tail_handle_ipv6+0x29e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e1;
	}
x86_l_29c1:
	/* 0x29c1: movzx  edx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_29c5:
	/* 0x29c5: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_29c8:
	/* 0x29c8: je     29e1 <tail_handle_ipv6+0x29e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29e1;
	}
x86_l_29ca:
	/* 0x29ca: cmp    WORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_29d0:
	/* 0x29d0: je     32bf <tail_handle_ipv6+0x32bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12991ULL;
	}
x86_l_29d6:
	/* 0x29d6: cmp    dx,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_29db:
	/* 0x29db: je     32bf <tail_handle_ipv6+0x32bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12991ULL;
	}
x86_l_29e1:
	/* 0x29e1: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_29e8:
	/* 0x29e8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29ea:
	/* 0x29ea: movzx  ebp,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_29f2:
	/* 0x29f2: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_29f6:
	/* 0x29f6: movzx  eax,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_29fb:
	/* 0x29fb: jne    2a06 <tail_handle_ipv6+0x2a06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a06;
	}
x86_l_29fd:
	/* 0x29fd: mov    r14,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_2a04:
	/* 0x2a04: jmp    2a0d <tail_handle_ipv6+0x2a0d> */
	goto x86_l_2a0d;
x86_l_2a06:
	/* 0x2a06: mov    r14,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_2a0d:
	/* 0x2a0d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2a16:
	/* 0x2a16: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2a1f:
	/* 0x2a1f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2a28:
	/* 0x2a28: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2a31:
	/* 0x2a31: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2a3a:
	/* 0x2a3a: mov    WORD PTR [rsp+0x36],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2a3f:
	/* 0x2a3f: mov    DWORD PTR [rsp+0x3c],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 257698037770ULL);
x86_l_2a47:
	/* 0x2a47: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a50:
	/* 0x2a50: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2a59:
	/* 0x2a59: mov    WORD PTR [rsp+0x34],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299424ULL);
x86_l_2a60:
	/* 0x2a60: mov    r15,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2a67:
	/* 0x2a67: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a6b:
	/* 0x2a6b: je     2a7e <tail_handle_ipv6+0x2a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a7e;
	}
x86_l_2a6d:
	/* 0x2a6d: mov    rax,QWORD PTR [rip+0xec66] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2a74:
	/* 0x2a74: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2a78:
	/* 0x2a78: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2a7c:
	/* 0x2a7c: jmp    2a84 <tail_handle_ipv6+0x2a84> */
	goto x86_l_2a84;
x86_l_2a7e:
	/* 0x2a7e: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2a84:
	/* 0x2a84: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2a88:
	/* 0x2a88: jne    2b23 <tail_handle_ipv6+0x2b23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2b23;
	}
x86_l_2a8e:
	/* 0x2a8e: mov    WORD PTR [rsp+0x34],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299424ULL);
x86_l_2a95:
	/* 0x2a95: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a99:
	/* 0x2a99: je     2b1d <tail_handle_ipv6+0x2b1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b1d;
	}
x86_l_2a9f:
	/* 0x2a9f: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2aa6:
	/* 0x2aa6: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2aaa:
	/* 0x2aaa: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2aae:
	/* 0x2aae: jmp    2b23 <tail_handle_ipv6+0x2b23> */
	goto x86_l_2b23;
x86_l_2ab0:
	/* 0x2ab0: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_2ab5:
	/* 0x2ab5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ab8:
	/* 0x2ab8: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_2abd:
	/* 0x2abd: mov    DWORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_2ac4:
	/* 0x2ac4: movzx  eax,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_2acc:
	/* 0x2acc: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2acf:
	/* 0x2acf: mov    eax,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    DWORD PTR [rbx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ad9:
	/* 0x2ad9: mov    eax,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_2ae0:
	/* 0x2ae0: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ae3:
	/* 0x2ae3: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2aea:
	/* 0x2aea: mov    DWORD PTR [rbx+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2aed:
	/* 0x2aed: mov    eax,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_2af4:
	/* 0x2af4: mov    DWORD PTR [rbx+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2af7:
	/* 0x2af7: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2afe:
	/* 0x2afe: mov    r12d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 22ULL);
x86_l_2b04:
	/* 0x2b04: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b09:
	/* 0x2b09: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b0c:
	/* 0x2b0c: mov    edx,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 22ULL);
x86_l_2b11:
	/* 0x2b11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b13:
	/* 0x2b13: mov    ecx,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967156ULL);
x86_l_2b18:
	/* 0x2b18: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_2b1d:
	/* 0x2b1d: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2b23:
	/* 0x2b23: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b27:
	/* 0x2b27: je     2b38 <tail_handle_ipv6+0x2b38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b38;
	}
x86_l_2b29:
	/* 0x2b29: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2b2e:
	/* 0x2b2e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b30:
	/* 0x2b30: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b32:
	/* 0x2b32: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2b36:
	/* 0x2b36: jmp    2b5b <tail_handle_ipv6+0x2b5b> */
	goto x86_l_2b5b;
x86_l_2b38:
	/* 0x2b38: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2b3d:
	/* 0x2b3d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b3f:
	/* 0x2b3f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2b41:
	/* 0x2b41: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2b45:
	/* 0x2b45: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2b4f:
	/* 0x2b4f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b52:
	/* 0x2b52: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2b57:
	/* 0x2b57: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2b5b:
	/* 0x2b5b: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2b5f:
	/* 0x2b5f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2b62:
	/* 0x2b62: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b65:
	/* 0x2b65: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b6a:
	/* 0x2b6a: movzx  edx,BYTE PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_2b6f:
	/* 0x2b6f: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2b73:
	/* 0x2b73: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_2b75:
	/* 0x2b75: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b79:
	/* 0x2b79: je     2b8c <tail_handle_ipv6+0x2b8c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b8c;
	}
x86_l_2b7b:
	/* 0x2b7b: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2b82:
	/* 0x2b82: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b84:
	/* 0x2b84: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_2b87:
	/* 0x2b87: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2b8a:
	/* 0x2b8a: jmp    2b91 <tail_handle_ipv6+0x2b91> */
	goto x86_l_2b91;
x86_l_2b8c:
	/* 0x2b8c: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_2b91:
	/* 0x2b91: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b93:
	/* 0x2b93: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2b95:
	/* 0x2b95: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2b97:
	/* 0x2b97: jb     2b9d <tail_handle_ipv6+0x2b9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2b9d;
	}
x86_l_2b99:
	/* 0x2b99: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_2b9b:
	/* 0x2b9b: je     2bae <tail_handle_ipv6+0x2bae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bae;
	}
x86_l_2b9d:
	/* 0x2b9d: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_2ba1:
	/* 0x2ba1: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ba5:
	/* 0x2ba5: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2bac:
	/* 0x2bac: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bae:
	/* 0x2bae: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2bb5:
	/* 0x2bb5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bb8:
	/* 0x2bb8: je     2bca <tail_handle_ipv6+0x2bca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bca;
	}
x86_l_2bba:
	/* 0x2bba: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_2bc3:
	/* 0x2bc3: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc5:
	/* 0x2bc5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2bca:
	/* 0x2bca: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2bcf:
	/* 0x2bcf: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bd4:
	/* 0x2bd4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2bd9:
	/* 0x2bd9: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2bdc:
	/* 0x2bdc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bde:
	/* 0x2bde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be0:
	/* 0x2be0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2be2:
	/* 0x2be2: js     3568 <tail_handle_ipv6+0x3568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 13672ULL;
	}
x86_l_2be8:
	/* 0x2be8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bea:
	/* 0x2bea: cmp    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_2bf3:
	/* 0x2bf3: mov    r15,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bf8:
	/* 0x2bf8: je     31f8 <tail_handle_ipv6+0x31f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12792ULL;
	}
x86_l_2bfe:
	/* 0x2bfe: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c01:
	/* 0x2c01: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2c03:
	/* 0x2c03: js     31ea <tail_handle_ipv6+0x31ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12778ULL;
	}
x86_l_2c09:
	/* 0x2c09: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c11:
	/* 0x2c11: je     31d4 <tail_handle_ipv6+0x31d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12756ULL;
	}
x86_l_2c17:
	/* 0x2c17: mov    r13d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c1e:
	/* 0x2c1e: lea    rcx,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c22:
	/* 0x2c22: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c25:
	/* 0x2c25: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2c28:
	/* 0x2c28: ja     37 <tail_handle_ipv6+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 55ULL;
	}
x86_l_2c2e:
	/* 0x2c2e: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_2c36:
	/* 0x2c36: mov    rax,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c3a:
	/* 0x2c3a: mov    rcx,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c3e:
	/* 0x2c3e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c43:
	/* 0x2c43: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c48:
	/* 0x2c48: mov    BYTE PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_2c4d:
	/* 0x2c4d: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_2c54:
	/* 0x2c54: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c59:
	/* 0x2c59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c5e:
	/* 0x2c5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c60:
	/* 0x2c60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c63:
	/* 0x2c63: je     2c6f <tail_handle_ipv6+0x2c6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c6f;
	}
x86_l_2c65:
	/* 0x2c65: test   BYTE PTR [rax+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_2c69:
	/* 0x2c69: je     2d70 <tail_handle_ipv6+0x2d70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d70;
	}
x86_l_2c6f:
	/* 0x2c6f: mov    r14d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c73:
	/* 0x2c73: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c76:
	/* 0x2c76: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2c7b:
	/* 0x2c7b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2c7e:
	/* 0x2c7e: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_2c83:
	/* 0x2c83: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c85:
	/* 0x2c85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c87:
	/* 0x2c87: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_2c8c:
	/* 0x2c8c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c8e:
	/* 0x2c8e: jne    3c <tail_handle_ipv6+0x3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 60ULL;
	}
x86_l_2c94:
	/* 0x2c94: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c9a:
	/* 0x2c9a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c9f:
	/* 0x2c9f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ca2:
	/* 0x2ca2: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2ca7:
	/* 0x2ca7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2caa:
	/* 0x2caa: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2caf:
	/* 0x2caf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2cb4:
	/* 0x2cb4: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cb7:
	/* 0x2cb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb9:
	/* 0x2cb9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cbb:
	/* 0x2cbb: js     2f57 <tail_handle_ipv6+0x2f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12119ULL;
	}
x86_l_2cc1:
	/* 0x2cc1: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_2cc8:
	/* 0x2cc8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ccb:
	/* 0x2ccb: je     2d15 <tail_handle_ipv6+0x2d15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d15;
	}
x86_l_2ccd:
	/* 0x2ccd: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_2cd4:
	/* 0x2cd4: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cd6:
	/* 0x2cd6: mov    dl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 24ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    sil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 24ULL);
x86_l_2cdb:
	/* 0x2cdb: sub    sil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2cde:
	/* 0x2cde: shrx   ecx,r15d,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_R15, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_2ce3:
	/* 0x2ce3: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce5:
	/* 0x2ce5: bzhi   ecx,ecx,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_RSI, 0);
x86_l_2cea:
	/* 0x2cea: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2ced:
	/* 0x2ced: and    ecx,0x7fffff00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2147483392ULL);
x86_l_2cf3:
	/* 0x2cf3: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf5:
	/* 0x2cf5: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2cf8:
	/* 0x2cf8: shlx   ecx,ecx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RCX, X86_RCX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_2cfd:
	/* 0x2cfd: or     ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_2cff:
	/* 0x2cff: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d01:
	/* 0x2d01: sub    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2d03:
	/* 0x2d03: bzhi   eax,r15d,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_R15, X86_WIDTH_32, X86_RDX, 0);
x86_l_2d08:
	/* 0x2d08: shl    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_2d0b:
	/* 0x2d0b: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2d0d:
	/* 0x2d0d: or     eax,0xd00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 3328ULL);
x86_l_2d12:
	/* 0x2d12: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d15:
	/* 0x2d15: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_2d1c:
	/* 0x2d1c: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d1f:
	/* 0x2d1f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d24:
	/* 0x2d24: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_2d2b:
	/* 0x2d2b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d2e:
	/* 0x2d2e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d33:
	/* 0x2d33: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2d38:
	/* 0x2d38: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2d3d:
	/* 0x2d3d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2d40:
	/* 0x2d40: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_2d45:
	/* 0x2d45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2d4a:
	/* 0x2d4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4c:
	/* 0x2d4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d4e:
	/* 0x2d4e: js     2fcb <tail_handle_ipv6+0x2fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12235ULL;
	}
x86_l_2d54:
	/* 0x2d54: movzx  eax,BYTE PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 88ULL);
x86_l_2d59:
	/* 0x2d59: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_2d5b:
	/* 0x2d5b: jae    2fd5 <tail_handle_ipv6+0x2fd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 12245ULL;
	}
x86_l_2d61:
	/* 0x2d61: movabs rax,0x10000000e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967310ULL);
x86_l_2d6b:
	/* 0x2d6b: jmp    2fa7 <tail_handle_ipv6+0x2fa7> */
	return 12199ULL;
x86_l_2d70:
	/* 0x2d70: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2d73:
	/* 0x2d73: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d75:
	/* 0x2d75: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d79:
	/* 0x2d79: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_2d80:
	/* 0x2d80: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d85:
	/* 0x2d85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d8a:
	/* 0x2d8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8c:
	/* 0x2d8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d8f:
	/* 0x2d8f: je     2d9b <tail_handle_ipv6+0x2d9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d9b;
	}
x86_l_2d91:
	/* 0x2d91: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2d95:
	/* 0x2d95: jne    2f61 <tail_handle_ipv6+0x2f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12129ULL;
	}
x86_l_2d9b:
	/* 0x2d9b: mov    r14d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d9f:
	/* 0x2d9f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2da2:
	/* 0x2da2: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2da7:
	/* 0x2da7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2daa:
	/* 0x2daa: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_2daf:
	/* 0x2daf: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2db1:
	/* 0x2db1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db3:
	/* 0x2db3: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_2db8:
	/* 0x2db8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2dba:
	/* 0x2dba: jne    3c <tail_handle_ipv6+0x3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 60ULL;
	}
x86_l_2dc0:
	/* 0x2dc0: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dc6:
	/* 0x2dc6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dcb:
	/* 0x2dcb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dce:
	/* 0x2dce: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2dd3:
	/* 0x2dd3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2dd6:
	/* 0x2dd6: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2ddb:
	/* 0x2ddb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2de0:
	/* 0x2de0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de3:
	/* 0x2de3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2de5:
	/* 0x2de5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2de7:
	/* 0x2de7: js     2f57 <tail_handle_ipv6+0x2f57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12119ULL;
	}
x86_l_2ded:
	/* 0x2ded: mov    rcx,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2df1:
	/* 0x2df1: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2df6:
	/* 0x2df6: mov    rax,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2dfa:
	/* 0x2dfa: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2dff:
	/* 0x2dff: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e04:
	/* 0x2e04: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2e09:
	/* 0x2e09: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e0c:
	/* 0x2e0c: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_2e11:
	/* 0x2e11: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e16:
	/* 0x2e16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e18:
	/* 0x2e18: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e1a:
	/* 0x2e1a: js     2fcb <tail_handle_ipv6+0x2fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12235ULL;
	}
x86_l_2e20:
	/* 0x2e20: movzx  eax,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2e25:
	/* 0x2e25: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_2e27:
	/* 0x2e27: jb     2d61 <tail_handle_ipv6+0x2d61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2d61;
	}
x86_l_2e2d:
	/* 0x2e2d: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_2e2f:
	/* 0x2e2f: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e33:
	/* 0x2e33: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e38:
	/* 0x2e38: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_2e3e:
	/* 0x2e3e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e41:
	/* 0x2e41: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_2e46:
	/* 0x2e46: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e4b:
	/* 0x2e4b: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_2e51:
	/* 0x2e51: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2e54:
	/* 0x2e54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e56:
	/* 0x2e56: js     31cc <tail_handle_ipv6+0x31cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12748ULL;
	}
x86_l_2e5c:
	/* 0x2e5c: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e61:
	/* 0x2e61: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e64:
	/* 0x2e64: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_2e69:
	/* 0x2e69: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2e6e:
	/* 0x2e6e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e71:
	/* 0x2e71: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2e74:
	/* 0x2e74: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2e79:
	/* 0x2e79: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e7b:
	/* 0x2e7b: js     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12753ULL;
	}
x86_l_2e81:
	/* 0x2e81: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e86:
	/* 0x2e86: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2e8b:
	/* 0x2e8b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e8e:
	/* 0x2e8e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e90:
	/* 0x2e90: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2e95:
	/* 0x2e95: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e98:
	/* 0x2e98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9a:
	/* 0x2e9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e9c:
	/* 0x2e9c: js     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12753ULL;
	}
x86_l_2ea2:
	/* 0x2ea2: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2ea5:
	/* 0x2ea5: movzx  ecx,WORD PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2eaa:
	/* 0x2eaa: movabs rdx,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 4294967296ULL);
x86_l_2eb4:
	/* 0x2eb4: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2eb9:
	/* 0x2eb9: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ebd:
	/* 0x2ebd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2ebf:
	/* 0x2ebf: je     3192 <tail_handle_ipv6+0x3192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12690ULL;
	}
x86_l_2ec5:
	/* 0x2ec5: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_throttle)));
x86_l_2ecc:
	/* 0x2ecc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ed1:
	/* 0x2ed1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ed6:
	/* 0x2ed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed8:
	/* 0x2ed8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2edb:
	/* 0x2edb: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2ede:
	/* 0x2ede: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_2ee1:
	/* 0x2ee1: je     3192 <tail_handle_ipv6+0x3192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12690ULL;
	}
x86_l_2ee7:
	/* 0x2ee7: cmp    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eeb:
	/* 0x2eeb: je     3192 <tail_handle_ipv6+0x3192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12690ULL;
	}
x86_l_2ef1:
	/* 0x2ef1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2ef6:
	/* 0x2ef6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
	return 12024ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12024ULL: goto x86_l_2ef8;
	case 12026ULL: goto x86_l_2efa;
	case 12029ULL: goto x86_l_2efd;
	case 12033ULL: goto x86_l_2f01;
	case 12037ULL: goto x86_l_2f05;
	case 12040ULL: goto x86_l_2f08;
	case 12043ULL: goto x86_l_2f0b;
	case 12045ULL: goto x86_l_2f0d;
	case 12049ULL: goto x86_l_2f11;
	case 12053ULL: goto x86_l_2f15;
	case 12063ULL: goto x86_l_2f1f;
	case 12068ULL: goto x86_l_2f24;
	case 12072ULL: goto x86_l_2f28;
	case 12075ULL: goto x86_l_2f2b;
	case 12078ULL: goto x86_l_2f2e;
	case 12082ULL: goto x86_l_2f32;
	case 12085ULL: goto x86_l_2f35;
	case 12091ULL: goto x86_l_2f3b;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12100ULL: goto x86_l_2f44;
	case 12103ULL: goto x86_l_2f47;
	case 12106ULL: goto x86_l_2f4a;
	case 12110ULL: goto x86_l_2f4e;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12124ULL: goto x86_l_2f5c;
	case 12129ULL: goto x86_l_2f61;
	case 12133ULL: goto x86_l_2f65;
	case 12138ULL: goto x86_l_2f6a;
	case 12142ULL: goto x86_l_2f6e;
	case 12147ULL: goto x86_l_2f73;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12160ULL: goto x86_l_2f80;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12172ULL: goto x86_l_2f8c;
	case 12174ULL: goto x86_l_2f8e;
	case 12176ULL: goto x86_l_2f90;
	case 12181ULL: goto x86_l_2f95;
	case 12183ULL: goto x86_l_2f97;
	case 12189ULL: goto x86_l_2f9d;
	case 12199ULL: goto x86_l_2fa7;
	case 12203ULL: goto x86_l_2fab;
	case 12210ULL: goto x86_l_2fb2;
	case 12215ULL: goto x86_l_2fb7;
	case 12218ULL: goto x86_l_2fba;
	case 12223ULL: goto x86_l_2fbf;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12235ULL: goto x86_l_2fcb;
	case 12240ULL: goto x86_l_2fd0;
	case 12245ULL: goto x86_l_2fd5;
	case 12247ULL: goto x86_l_2fd7;
	case 12251ULL: goto x86_l_2fdb;
	case 12256ULL: goto x86_l_2fe0;
	case 12262ULL: goto x86_l_2fe6;
	case 12265ULL: goto x86_l_2fe9;
	case 12270ULL: goto x86_l_2fee;
	case 12275ULL: goto x86_l_2ff3;
	case 12281ULL: goto x86_l_2ff9;
	case 12284ULL: goto x86_l_2ffc;
	case 12286ULL: goto x86_l_2ffe;
	case 12292ULL: goto x86_l_3004;
	case 12297ULL: goto x86_l_3009;
	case 12300ULL: goto x86_l_300c;
	case 12305ULL: goto x86_l_3011;
	case 12310ULL: goto x86_l_3016;
	case 12313ULL: goto x86_l_3019;
	case 12316ULL: goto x86_l_301c;
	case 12321ULL: goto x86_l_3021;
	case 12323ULL: goto x86_l_3023;
	case 12329ULL: goto x86_l_3029;
	case 12334ULL: goto x86_l_302e;
	case 12339ULL: goto x86_l_3033;
	case 12342ULL: goto x86_l_3036;
	case 12344ULL: goto x86_l_3038;
	case 12349ULL: goto x86_l_303d;
	case 12352ULL: goto x86_l_3040;
	case 12354ULL: goto x86_l_3042;
	case 12356ULL: goto x86_l_3044;
	case 12362ULL: goto x86_l_304a;
	case 12369ULL: goto x86_l_3051;
	case 12371ULL: goto x86_l_3053;
	case 12373ULL: goto x86_l_3055;
	case 12378ULL: goto x86_l_305a;
	case 12383ULL: goto x86_l_305f;
	case 12385ULL: goto x86_l_3061;
	case 12387ULL: goto x86_l_3063;
	case 12392ULL: goto x86_l_3068;
	case 12394ULL: goto x86_l_306a;
	case 12398ULL: goto x86_l_306e;
	case 12403ULL: goto x86_l_3073;
	case 12409ULL: goto x86_l_3079;
	case 12412ULL: goto x86_l_307c;
	case 12417ULL: goto x86_l_3081;
	case 12422ULL: goto x86_l_3086;
	case 12428ULL: goto x86_l_308c;
	case 12431ULL: goto x86_l_308f;
	case 12433ULL: goto x86_l_3091;
	case 12439ULL: goto x86_l_3097;
	case 12444ULL: goto x86_l_309c;
	case 12447ULL: goto x86_l_309f;
	case 12452ULL: goto x86_l_30a4;
	case 12457ULL: goto x86_l_30a9;
	case 12460ULL: goto x86_l_30ac;
	case 12463ULL: goto x86_l_30af;
	case 12468ULL: goto x86_l_30b4;
	case 12470ULL: goto x86_l_30b6;
	case 12476ULL: goto x86_l_30bc;
	case 12481ULL: goto x86_l_30c1;
	case 12486ULL: goto x86_l_30c6;
	case 12489ULL: goto x86_l_30c9;
	case 12491ULL: goto x86_l_30cb;
	case 12496ULL: goto x86_l_30d0;
	case 12499ULL: goto x86_l_30d3;
	case 12501ULL: goto x86_l_30d5;
	case 12503ULL: goto x86_l_30d7;
	case 12509ULL: goto x86_l_30dd;
	case 12512ULL: goto x86_l_30e0;
	case 12517ULL: goto x86_l_30e5;
	case 12527ULL: goto x86_l_30ef;
	case 12532ULL: goto x86_l_30f4;
	case 12536ULL: goto x86_l_30f8;
	case 12538ULL: goto x86_l_30fa;
	case 12544ULL: goto x86_l_3100;
	case 12551ULL: goto x86_l_3107;
	case 12556ULL: goto x86_l_310c;
	case 12561ULL: goto x86_l_3111;
	case 12563ULL: goto x86_l_3113;
	case 12566ULL: goto x86_l_3116;
	case 12569ULL: goto x86_l_3119;
	case 12572ULL: goto x86_l_311c;
	case 12574ULL: goto x86_l_311e;
	case 12578ULL: goto x86_l_3122;
	case 12580ULL: goto x86_l_3124;
	case 12585ULL: goto x86_l_3129;
	case 12587ULL: goto x86_l_312b;
	case 12589ULL: goto x86_l_312d;
	case 12592ULL: goto x86_l_3130;
	case 12596ULL: goto x86_l_3134;
	case 12600ULL: goto x86_l_3138;
	case 12603ULL: goto x86_l_313b;
	case 12606ULL: goto x86_l_313e;
	case 12608ULL: goto x86_l_3140;
	case 12612ULL: goto x86_l_3144;
	case 12616ULL: goto x86_l_3148;
	case 12626ULL: goto x86_l_3152;
	case 12631ULL: goto x86_l_3157;
	case 12635ULL: goto x86_l_315b;
	case 12638ULL: goto x86_l_315e;
	case 12641ULL: goto x86_l_3161;
	case 12645ULL: goto x86_l_3165;
	case 12648ULL: goto x86_l_3168;
	case 12654ULL: goto x86_l_316e;
	case 12656ULL: goto x86_l_3170;
	case 12659ULL: goto x86_l_3173;
	case 12663ULL: goto x86_l_3177;
	case 12666ULL: goto x86_l_317a;
	case 12669ULL: goto x86_l_317d;
	case 12673ULL: goto x86_l_3181;
	case 12677ULL: goto x86_l_3185;
	case 12682ULL: goto x86_l_318a;
	case 12685ULL: goto x86_l_318d;
	case 12688ULL: goto x86_l_3190;
	case 12690ULL: goto x86_l_3192;
	case 12697ULL: goto x86_l_3199;
	case 12700ULL: goto x86_l_319c;
	case 12704ULL: goto x86_l_31a0;
	case 12712ULL: goto x86_l_31a8;
	case 12720ULL: goto x86_l_31b0;
	case 12724ULL: goto x86_l_31b4;
	case 12731ULL: goto x86_l_31bb;
	case 12736ULL: goto x86_l_31c0;
	case 12739ULL: goto x86_l_31c3;
	case 12741ULL: goto x86_l_31c5;
	case 12746ULL: goto x86_l_31ca;
	case 12748ULL: goto x86_l_31cc;
	case 12753ULL: goto x86_l_31d1;
	case 12756ULL: goto x86_l_31d4;
	case 12758ULL: goto x86_l_31d6;
	case 12764ULL: goto x86_l_31dc;
	case 12767ULL: goto x86_l_31df;
	case 12773ULL: goto x86_l_31e5;
	case 12778ULL: goto x86_l_31ea;
	case 12783ULL: goto x86_l_31ef;
	case 12785ULL: goto x86_l_31f1;
	case 12787ULL: goto x86_l_31f3;
	case 12792ULL: goto x86_l_31f8;
	case 12801ULL: goto x86_l_3201;
	case 12805ULL: goto x86_l_3205;
	case 12808ULL: goto x86_l_3208;
	case 12812ULL: goto x86_l_320c;
	case 12817ULL: goto x86_l_3211;
	case 12820ULL: goto x86_l_3214;
	case 12826ULL: goto x86_l_321a;
	case 12831ULL: goto x86_l_321f;
	case 12836ULL: goto x86_l_3224;
	case 12839ULL: goto x86_l_3227;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12851ULL: goto x86_l_3233;
	case 12853ULL: goto x86_l_3235;
	case 12859ULL: goto x86_l_323b;
	case 12863ULL: goto x86_l_323f;
	case 12870ULL: goto x86_l_3246;
	case 12875ULL: goto x86_l_324b;
	case 12878ULL: goto x86_l_324e;
	case 12880ULL: goto x86_l_3250;
	case 12883ULL: goto x86_l_3253;
	case 12885ULL: goto x86_l_3255;
	case 12889ULL: goto x86_l_3259;
	case 12891ULL: goto x86_l_325b;
	case 12896ULL: goto x86_l_3260;
	case 12900ULL: goto x86_l_3264;
	case 12903ULL: goto x86_l_3267;
	case 12905ULL: goto x86_l_3269;
	case 12907ULL: goto x86_l_326b;
	case 12914ULL: goto x86_l_3272;
	case 12919ULL: goto x86_l_3277;
	case 12924ULL: goto x86_l_327c;
	case 12927ULL: goto x86_l_327f;
	case 12929ULL: goto x86_l_3281;
	case 12931ULL: goto x86_l_3283;
	case 12933ULL: goto x86_l_3285;
	case 12935ULL: goto x86_l_3287;
	case 12940ULL: goto x86_l_328c;
	case 12947ULL: goto x86_l_3293;
	case 12953ULL: goto x86_l_3299;
	case 12960ULL: goto x86_l_32a0;
	case 12967ULL: goto x86_l_32a7;
	case 12973ULL: goto x86_l_32ad;
	case 12978ULL: goto x86_l_32b2;
	case 12981ULL: goto x86_l_32b5;
	case 12986ULL: goto x86_l_32ba;
	case 12991ULL: goto x86_l_32bf;
	case 12996ULL: goto x86_l_32c4;
	case 12998ULL: goto x86_l_32c6;
	case 13000ULL: goto x86_l_32c8;
	case 13002ULL: goto x86_l_32ca;
	case 13008ULL: goto x86_l_32d0;
	case 13015ULL: goto x86_l_32d7;
	case 13018ULL: goto x86_l_32da;
	case 13020ULL: goto x86_l_32dc;
	case 13027ULL: goto x86_l_32e3;
	case 13031ULL: goto x86_l_32e7;
	case 13035ULL: goto x86_l_32eb;
	case 13037ULL: goto x86_l_32ed;
	case 13039ULL: goto x86_l_32ef;
	case 13042ULL: goto x86_l_32f2;
	case 13044ULL: goto x86_l_32f4;
	case 13046ULL: goto x86_l_32f6;
	case 13051ULL: goto x86_l_32fb;
	case 13053ULL: goto x86_l_32fd;
	case 13059ULL: goto x86_l_3303;
	case 13064ULL: goto x86_l_3308;
	case 13070ULL: goto x86_l_330e;
	case 13074ULL: goto x86_l_3312;
	case 13076ULL: goto x86_l_3314;
	case 13078ULL: goto x86_l_3316;
	case 13080ULL: goto x86_l_3318;
	case 13083ULL: goto x86_l_331b;
	case 13086ULL: goto x86_l_331e;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13097ULL: goto x86_l_3329;
	case 13100ULL: goto x86_l_332c;
	case 13105ULL: goto x86_l_3331;
	case 13111ULL: goto x86_l_3337;
	case 13115ULL: goto x86_l_333b;
	case 13122ULL: goto x86_l_3342;
	case 13125ULL: goto x86_l_3345;
	case 13127ULL: goto x86_l_3347;
	case 13134ULL: goto x86_l_334e;
	case 13138ULL: goto x86_l_3352;
	case 13142ULL: goto x86_l_3356;
	case 13145ULL: goto x86_l_3359;
	case 13149ULL: goto x86_l_335d;
	case 13156ULL: goto x86_l_3364;
	case 13159ULL: goto x86_l_3367;
	case 13161ULL: goto x86_l_3369;
	case 13166ULL: goto x86_l_336e;
	case 13168ULL: goto x86_l_3370;
	case 13170ULL: goto x86_l_3372;
	case 13174ULL: goto x86_l_3376;
	case 13176ULL: goto x86_l_3378;
	case 13181ULL: goto x86_l_337d;
	case 13183ULL: goto x86_l_337f;
	case 13185ULL: goto x86_l_3381;
	case 13189ULL: goto x86_l_3385;
	case 13199ULL: goto x86_l_338f;
	case 13202ULL: goto x86_l_3392;
	case 13207ULL: goto x86_l_3397;
	case 13211ULL: goto x86_l_339b;
	case 13214ULL: goto x86_l_339e;
	case 13219ULL: goto x86_l_33a3;
	case 13223ULL: goto x86_l_33a7;
	case 13227ULL: goto x86_l_33ab;
	case 13230ULL: goto x86_l_33ae;
	case 13234ULL: goto x86_l_33b2;
	case 13241ULL: goto x86_l_33b9;
	case 13244ULL: goto x86_l_33bc;
	case 13246ULL: goto x86_l_33be;
	case 13253ULL: goto x86_l_33c5;
	case 13255ULL: goto x86_l_33c7;
	case 13258ULL: goto x86_l_33ca;
	case 13261ULL: goto x86_l_33cd;
	case 13263ULL: goto x86_l_33cf;
	case 13268ULL: goto x86_l_33d4;
	case 13270ULL: goto x86_l_33d6;
	case 13273ULL: goto x86_l_33d9;
	case 13275ULL: goto x86_l_33db;
	case 13277ULL: goto x86_l_33dd;
	case 13280ULL: goto x86_l_33e0;
	case 13282ULL: goto x86_l_33e2;
	case 13287ULL: goto x86_l_33e7;
	case 13291ULL: goto x86_l_33eb;
	case 13294ULL: goto x86_l_33ee;
	case 13301ULL: goto x86_l_33f5;
	case 13303ULL: goto x86_l_33f7;
	case 13310ULL: goto x86_l_33fe;
	case 13313ULL: goto x86_l_3401;
	case 13315ULL: goto x86_l_3403;
	case 13320ULL: goto x86_l_3408;
	case 13325ULL: goto x86_l_340d;
	case 13327ULL: goto x86_l_340f;
	case 13332ULL: goto x86_l_3414;
	case 13336ULL: goto x86_l_3418;
	case 13338ULL: goto x86_l_341a;
	case 13342ULL: goto x86_l_341e;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13357ULL: goto x86_l_342d;
	case 13359ULL: goto x86_l_342f;
	case 13365ULL: goto x86_l_3435;
	case 13370ULL: goto x86_l_343a;
	case 13376ULL: goto x86_l_3440;
	case 13381ULL: goto x86_l_3445;
	case 13385ULL: goto x86_l_3449;
	case 13392ULL: goto x86_l_3450;
	case 13396ULL: goto x86_l_3454;
	case 13402ULL: goto x86_l_345a;
	case 13409ULL: goto x86_l_3461;
	case 13413ULL: goto x86_l_3465;
	case 13417ULL: goto x86_l_3469;
	case 13422ULL: goto x86_l_346e;
	case 13424ULL: goto x86_l_3470;
	case 13429ULL: goto x86_l_3475;
	case 13432ULL: goto x86_l_3478;
	case 13436ULL: goto x86_l_347c;
	case 13440ULL: goto x86_l_3480;
	case 13445ULL: goto x86_l_3485;
	case 13449ULL: goto x86_l_3489;
	case 13453ULL: goto x86_l_348d;
	case 13460ULL: goto x86_l_3494;
	case 13463ULL: goto x86_l_3497;
	case 13465ULL: goto x86_l_3499;
	case 13471ULL: goto x86_l_349f;
	case 13478ULL: goto x86_l_34a6;
	case 13482ULL: goto x86_l_34aa;
	case 13484ULL: goto x86_l_34ac;
	case 13491ULL: goto x86_l_34b3;
	case 13493ULL: goto x86_l_34b5;
	case 13495ULL: goto x86_l_34b7;
	case 13499ULL: goto x86_l_34bb;
	case 13503ULL: goto x86_l_34bf;
	case 13505ULL: goto x86_l_34c1;
	case 13511ULL: goto x86_l_34c7;
	case 13514ULL: goto x86_l_34ca;
	case 13518ULL: goto x86_l_34ce;
	case 13520ULL: goto x86_l_34d0;
	case 13525ULL: goto x86_l_34d5;
	case 13527ULL: goto x86_l_34d7;
	case 13529ULL: goto x86_l_34d9;
	case 13533ULL: goto x86_l_34dd;
	case 13535ULL: goto x86_l_34df;
	case 13540ULL: goto x86_l_34e4;
	case 13542ULL: goto x86_l_34e6;
	case 13544ULL: goto x86_l_34e8;
	case 13548ULL: goto x86_l_34ec;
	case 13558ULL: goto x86_l_34f6;
	case 13561ULL: goto x86_l_34f9;
	case 13566ULL: goto x86_l_34fe;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2ef8:
	/* 0x2ef8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2efa:
	/* 0x2efa: mov    rsi,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2efd:
	/* 0x2efd: mov    rdi,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f01:
	/* 0x2f01: mov    rcx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f05:
	/* 0x2f05: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f08:
	/* 0x2f08: sub    rdx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f0b:
	/* 0x2f0b: je     2f35 <tail_handle_ipv6+0x2f35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f35;
	}
x86_l_2f0d:
	/* 0x2f0d: imul   rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_2f11:
	/* 0x2f11: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2f15:
	/* 0x2f15: movabs rdi,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2f1f:
	/* 0x2f1f: mulx   rdx,rdx,rdi */
	X86_SIM_L_EXEC_MULX(X86_RDX, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_2f24:
	/* 0x2f24: shr    rdx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2f28:
	/* 0x2f28: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2f2b:
	/* 0x2f2b: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2f2e:
	/* 0x2f2e: cmovae rdx,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RSI, X86_WIDTH_64, X86_CC_AE);
x86_l_2f32:
	/* 0x2f32: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2f35:
	/* 0x2f35: mov    edx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2f3b:
	/* 0x2f3b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f3d:
	/* 0x2f3d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2f40:
	/* 0x2f40: cmovae rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_AE);
x86_l_2f44:
	/* 0x2f44: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_2f47:
	/* 0x2f47: sub    rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2f4a:
	/* 0x2f4a: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f4e:
	/* 0x2f4e: mov    QWORD PTR [r14+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f52:
	/* 0x2f52: jmp    3185 <tail_handle_ipv6+0x3185> */
	goto x86_l_3185;
x86_l_2f57:
	/* 0x2f57: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2f5c:
	/* 0x2f5c: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_2f61:
	/* 0x2f61: mov    rcx,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2f65:
	/* 0x2f65: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f6a:
	/* 0x2f6a: mov    rax,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f6e:
	/* 0x2f6e: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f73:
	/* 0x2f73: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2f78:
	/* 0x2f78: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2f7d:
	/* 0x2f7d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2f80:
	/* 0x2f80: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_2f85:
	/* 0x2f85: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f8a:
	/* 0x2f8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8c:
	/* 0x2f8c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f8e:
	/* 0x2f8e: js     2fcb <tail_handle_ipv6+0x2fcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2fcb;
	}
x86_l_2f90:
	/* 0x2f90: movzx  eax,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2f95:
	/* 0x2f95: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_2f97:
	/* 0x2f97: jae    3068 <tail_handle_ipv6+0x3068> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3068;
	}
x86_l_2f9d:
	/* 0x2f9d: movabs rax,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967296ULL);
x86_l_2fa7:
	/* 0x2fa7: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2fab:
	/* 0x2fab: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2fb2:
	/* 0x2fb2: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2fb7:
	/* 0x2fb7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2fba:
	/* 0x2fba: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_2fbf:
	/* 0x2fbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fc1:
	/* 0x2fc1: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_2fc6:
	/* 0x2fc6: jmp    31d1 <tail_handle_ipv6+0x31d1> */
	goto x86_l_31d1;
x86_l_2fcb:
	/* 0x2fcb: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_2fd0:
	/* 0x2fd0: jmp    31d1 <tail_handle_ipv6+0x31d1> */
	goto x86_l_31d1;
x86_l_2fd5:
	/* 0x2fd5: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_2fd7:
	/* 0x2fd7: mov    BYTE PTR [rsp+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2fdb:
	/* 0x2fdb: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2fe0:
	/* 0x2fe0: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_2fe6:
	/* 0x2fe6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2fe9:
	/* 0x2fe9: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_2fee:
	/* 0x2fee: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2ff3:
	/* 0x2ff3: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_2ff9:
	/* 0x2ff9: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2ffc:
	/* 0x2ffc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ffe:
	/* 0x2ffe: js     31cc <tail_handle_ipv6+0x31cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31cc;
	}
x86_l_3004:
	/* 0x3004: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3009:
	/* 0x3009: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_300c:
	/* 0x300c: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_3011:
	/* 0x3011: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3016:
	/* 0x3016: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3019:
	/* 0x3019: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_301c:
	/* 0x301c: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_3021:
	/* 0x3021: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3023:
	/* 0x3023: js     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31d1;
	}
x86_l_3029:
	/* 0x3029: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_302e:
	/* 0x302e: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_3033:
	/* 0x3033: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3036:
	/* 0x3036: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3038:
	/* 0x3038: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_303d:
	/* 0x303d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3040:
	/* 0x3040: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3042:
	/* 0x3042: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3044:
	/* 0x3044: js     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31d1;
	}
x86_l_304a:
	/* 0x304a: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_ifindex)));
x86_l_3051:
	/* 0x3051: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3053:
	/* 0x3053: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3055:
	/* 0x3055: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_305a:
	/* 0x305a: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_305f:
	/* 0x305f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3061:
	/* 0x3061: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3063:
	/* 0x3063: jmp    31d1 <tail_handle_ipv6+0x31d1> */
	goto x86_l_31d1;
x86_l_3068:
	/* 0x3068: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_306a:
	/* 0x306a: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_306e:
	/* 0x306e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3073:
	/* 0x3073: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_3079:
	/* 0x3079: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_307c:
	/* 0x307c: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_3081:
	/* 0x3081: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3086:
	/* 0x3086: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_308c:
	/* 0x308c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_308f:
	/* 0x308f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3091:
	/* 0x3091: js     31cc <tail_handle_ipv6+0x31cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31cc;
	}
x86_l_3097:
	/* 0x3097: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_309c:
	/* 0x309c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_309f:
	/* 0x309f: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_30a4:
	/* 0x30a4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_30a9:
	/* 0x30a9: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30ac:
	/* 0x30ac: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_30af:
	/* 0x30af: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_30b4:
	/* 0x30b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b6:
	/* 0x30b6: js     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31d1;
	}
x86_l_30bc:
	/* 0x30bc: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_30c1:
	/* 0x30c1: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_30c6:
	/* 0x30c6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_30c9:
	/* 0x30c9: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30cb:
	/* 0x30cb: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_30d0:
	/* 0x30d0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30d3:
	/* 0x30d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30d5:
	/* 0x30d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30d7:
	/* 0x30d7: js     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_31d1;
	}
x86_l_30dd:
	/* 0x30dd: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_30e0:
	/* 0x30e0: movzx  ecx,WORD PTR [r13+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_30e5:
	/* 0x30e5: movabs rdx,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 4294967296ULL);
x86_l_30ef:
	/* 0x30ef: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30f4:
	/* 0x30f4: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30f8:
	/* 0x30f8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_30fa:
	/* 0x30fa: je     3192 <tail_handle_ipv6+0x3192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3192;
	}
x86_l_3100:
	/* 0x3100: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_throttle)));
x86_l_3107:
	/* 0x3107: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_310c:
	/* 0x310c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3111:
	/* 0x3111: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3113:
	/* 0x3113: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3116:
	/* 0x3116: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_3119:
	/* 0x3119: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_311c:
	/* 0x311c: je     3192 <tail_handle_ipv6+0x3192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3192;
	}
x86_l_311e:
	/* 0x311e: cmp    QWORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3122:
	/* 0x3122: je     3192 <tail_handle_ipv6+0x3192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3192;
	}
x86_l_3124:
	/* 0x3124: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3129:
	/* 0x3129: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_312b:
	/* 0x312b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_312d:
	/* 0x312d: mov    rsi,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3130:
	/* 0x3130: mov    rdi,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3134:
	/* 0x3134: mov    rcx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3138:
	/* 0x3138: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_313b:
	/* 0x313b: sub    rdx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_313e:
	/* 0x313e: je     3168 <tail_handle_ipv6+0x3168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3168;
	}
x86_l_3140:
	/* 0x3140: imul   rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_3144:
	/* 0x3144: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_3148:
	/* 0x3148: movabs rdi,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 19342813113834067ULL);
x86_l_3152:
	/* 0x3152: mulx   rdx,rdx,rdi */
	X86_SIM_L_EXEC_MULX(X86_RDX, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3157:
	/* 0x3157: shr    rdx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_315b:
	/* 0x315b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_315e:
	/* 0x315e: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_3161:
	/* 0x3161: cmovae rdx,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RSI, X86_WIDTH_64, X86_CC_AE);
x86_l_3165:
	/* 0x3165: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3168:
	/* 0x3168: mov    edx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_316e:
	/* 0x316e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3170:
	/* 0x3170: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_3173:
	/* 0x3173: cmovae rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_AE);
x86_l_3177:
	/* 0x3177: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_317a:
	/* 0x317a: sub    rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_317d:
	/* 0x317d: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3181:
	/* 0x3181: mov    QWORD PTR [r14+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3185:
	/* 0x3185: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_318a:
	/* 0x318a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_318d:
	/* 0x318d: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_3190:
	/* 0x3190: jb     31d1 <tail_handle_ipv6+0x31d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_31d1;
	}
x86_l_3192:
	/* 0x3192: mov    rcx,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_3199:
	/* 0x3199: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_319c:
	/* 0x319c: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_31a0:
	/* 0x31a0: mov    QWORD PTR [rbx+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_31a8:
	/* 0x31a8: mov    QWORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_31b0:
	/* 0x31b0: movzx  edx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_31b4:
	/* 0x31b4: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_call_policy)));
x86_l_31bb:
	/* 0x31bb: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_31c0:
	/* 0x31c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_31c3:
	/* 0x31c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c5:
	/* 0x31c5: mov    ebp,0xffffff35 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967093ULL);
x86_l_31ca:
	/* 0x31ca: jmp    31d1 <tail_handle_ipv6+0x31d1> */
	goto x86_l_31d1;
x86_l_31cc:
	/* 0x31cc: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_31d1:
	/* 0x31d1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31d4:
	/* 0x31d4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_31d6:
	/* 0x31d6: js     3c <tail_handle_ipv6+0x3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 60ULL;
	}
x86_l_31dc:
	/* 0x31dc: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_31df:
	/* 0x31df: jne    203 <tail_handle_ipv6+0x203> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 515ULL;
	}
x86_l_31e5:
	/* 0x31e5: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_31ea:
	/* 0x31ea: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31ef:
	/* 0x31ef: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_31f1:
	/* 0x31f1: jns    31dc <tail_handle_ipv6+0x31dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_31dc;
	}
x86_l_31f3:
	/* 0x31f3: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_31f8:
	/* 0x31f8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3201:
	/* 0x3201: mov    r14d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_3205:
	/* 0x3205: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3208:
	/* 0x3208: lea    rcx,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_320c:
	/* 0x320c: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_3211:
	/* 0x3211: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3214:
	/* 0x3214: ja     32ef <tail_handle_ipv6+0x32ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_32ef;
	}
x86_l_321a:
	/* 0x321a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_321f:
	/* 0x321f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3224:
	/* 0x3224: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3227:
	/* 0x3227: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_322c:
	/* 0x322c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_3231:
	/* 0x3231: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3233:
	/* 0x3233: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3235:
	/* 0x3235: js     32ef <tail_handle_ipv6+0x32ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_32ef;
	}
x86_l_323b:
	/* 0x323b: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_323f:
	/* 0x323f: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_3246:
	/* 0x3246: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_324b:
	/* 0x324b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_324e:
	/* 0x324e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3250:
	/* 0x3250: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3253:
	/* 0x3253: je     326b <tail_handle_ipv6+0x326b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_326b;
	}
x86_l_3255:
	/* 0x3255: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3259:
	/* 0x3259: xor    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 0ULL);
x86_l_325b:
	/* 0x325b: movzx  edx,WORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_3260:
	/* 0x3260: xor    dx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 4ULL);
x86_l_3264:
	/* 0x3264: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3267:
	/* 0x3267: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3269:
	/* 0x3269: je     3287 <tail_handle_ipv6+0x3287> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3287;
	}
x86_l_326b:
	/* 0x326b: mov    rdi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_3272:
	/* 0x3272: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3277:
	/* 0x3277: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_327c:
	/* 0x327c: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_327f:
	/* 0x327f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3281:
	/* 0x3281: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3283:
	/* 0x3283: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3285:
	/* 0x3285: js     32ed <tail_handle_ipv6+0x32ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_32ed;
	}
x86_l_3287:
	/* 0x3287: cmp    BYTE PTR [r15+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_328c:
	/* 0x328c: mov    DWORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_3293:
	/* 0x3293: js     2ac4 <tail_handle_ipv6+0x2ac4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10948ULL;
	}
x86_l_3299:
	/* 0x3299: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_32a0:
	/* 0x32a0: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_32a7:
	/* 0x32a7: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_32ad:
	/* 0x32ad: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_32b2:
	/* 0x32b2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_32b5:
	/* 0x32b5: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_32ba:
	/* 0x32ba: jmp    2b11 <tail_handle_ipv6+0x2b11> */
	return 11025ULL;
x86_l_32bf:
	/* 0x32bf: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32c4:
	/* 0x32c4: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_32c6:
	/* 0x32c6: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_32c8:
	/* 0x32c8: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_32ca:
	/* 0x32ca: je     33f7 <tail_handle_ipv6+0x33f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33f7;
	}
x86_l_32d0:
	/* 0x32d0: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_32d7:
	/* 0x32d7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32da:
	/* 0x32da: je     3308 <tail_handle_ipv6+0x3308> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3308;
	}
x86_l_32dc:
	/* 0x32dc: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_32e3:
	/* 0x32e3: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_32e7:
	/* 0x32e7: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_32eb:
	/* 0x32eb: jmp    330e <tail_handle_ipv6+0x330e> */
	goto x86_l_330e;
x86_l_32ed:
	/* 0x32ed: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_32ef:
	/* 0x32ef: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32f2:
	/* 0x32f2: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_32f4:
	/* 0x32f4: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_32f6:
	/* 0x32f6: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_32fb:
	/* 0x32fb: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_32fd:
	/* 0x32fd: jns    31dc <tail_handle_ipv6+0x31dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_31dc;
	}
x86_l_3303:
	/* 0x3303: jmp    3c <tail_handle_ipv6+0x3c> */
	return 60ULL;
x86_l_3308:
	/* 0x3308: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_330e:
	/* 0x330e: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_3312:
	/* 0x3312: jne    3356 <tail_handle_ipv6+0x3356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3356;
	}
x86_l_3314:
	/* 0x3314: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3316:
	/* 0x3316: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3318:
	/* 0x3318: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_331b:
	/* 0x331b: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_331e:
	/* 0x331e: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3320:
	/* 0x3320: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3325:
	/* 0x3325: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3329:
	/* 0x3329: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_332c:
	/* 0x332c: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3331:
	/* 0x3331: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_3337:
	/* 0x3337: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_333b:
	/* 0x333b: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3342:
	/* 0x3342: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3345:
	/* 0x3345: je     3356 <tail_handle_ipv6+0x3356> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3356;
	}
x86_l_3347:
	/* 0x3347: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_334e:
	/* 0x334e: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_3352:
	/* 0x3352: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3356:
	/* 0x3356: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_3359:
	/* 0x3359: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_335d:
	/* 0x335d: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3364:
	/* 0x3364: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3367:
	/* 0x3367: je     3378 <tail_handle_ipv6+0x3378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3378;
	}
x86_l_3369:
	/* 0x3369: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_336e:
	/* 0x336e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3370:
	/* 0x3370: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3372:
	/* 0x3372: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_3376:
	/* 0x3376: jmp    339b <tail_handle_ipv6+0x339b> */
	goto x86_l_339b;
x86_l_3378:
	/* 0x3378: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_337d:
	/* 0x337d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_337f:
	/* 0x337f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3381:
	/* 0x3381: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_3385:
	/* 0x3385: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_338f:
	/* 0x338f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3392:
	/* 0x3392: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3397:
	/* 0x3397: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_339b:
	/* 0x339b: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_339e:
	/* 0x339e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33a3:
	/* 0x33a3: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33a7:
	/* 0x33a7: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_33ab:
	/* 0x33ab: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33ae:
	/* 0x33ae: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_33b2:
	/* 0x33b2: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_33b9:
	/* 0x33b9: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33bc:
	/* 0x33bc: je     33cf <tail_handle_ipv6+0x33cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33cf;
	}
x86_l_33be:
	/* 0x33be: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_33c5:
	/* 0x33c5: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c7:
	/* 0x33c7: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_33ca:
	/* 0x33ca: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_33cd:
	/* 0x33cd: jmp    33d4 <tail_handle_ipv6+0x33d4> */
	goto x86_l_33d4;
x86_l_33cf:
	/* 0x33cf: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_33d4:
	/* 0x33d4: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_33d6:
	/* 0x33d6: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_33d9:
	/* 0x33d9: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_33db:
	/* 0x33db: jb     33e2 <tail_handle_ipv6+0x33e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_33e2;
	}
x86_l_33dd:
	/* 0x33dd: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_33e0:
	/* 0x33e0: je     33f7 <tail_handle_ipv6+0x33f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33f7;
	}
x86_l_33e2:
	/* 0x33e2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33e7:
	/* 0x33e7: mov    BYTE PTR [rcx+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_33eb:
	/* 0x33eb: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33ee:
	/* 0x33ee: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_33f5:
	/* 0x33f5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33f7:
	/* 0x33f7: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_33fe:
	/* 0x33fe: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3401:
	/* 0x3401: je     3414 <tail_handle_ipv6+0x3414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3414;
	}
x86_l_3403:
	/* 0x3403: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3408:
	/* 0x3408: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_340d:
	/* 0x340d: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_340f:
	/* 0x340f: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_3414:
	/* 0x3414: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_3418:
	/* 0x3418: je     346e <tail_handle_ipv6+0x346e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_346e;
	}
x86_l_341a:
	/* 0x341a: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_341e:
	/* 0x341e: jne    2be8 <tail_handle_ipv6+0x2be8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11240ULL;
	}
x86_l_3424:
	/* 0x3424: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3429:
	/* 0x3429: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_342d:
	/* 0x342d: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_342f:
	/* 0x342f: je     2be8 <tail_handle_ipv6+0x2be8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11240ULL;
	}
x86_l_3435:
	/* 0x3435: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_343a:
	/* 0x343a: mov    WORD PTR [rcx+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_3440:
	/* 0x3440: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_3445:
	/* 0x3445: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3449:
	/* 0x3449: mov    r15,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3450:
	/* 0x3450: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3454:
	/* 0x3454: je     364a <tail_handle_ipv6+0x364a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13898ULL;
	}
x86_l_345a:
	/* 0x345a: mov    rcx,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3461:
	/* 0x3461: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_3465:
	/* 0x3465: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3469:
	/* 0x3469: jmp    3650 <tail_handle_ipv6+0x3650> */
	return 13904ULL;
x86_l_346e:
	/* 0x346e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3470:
	/* 0x3470: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_3475:
	/* 0x3475: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3478:
	/* 0x3478: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_347c:
	/* 0x347c: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_3480:
	/* 0x3480: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3485:
	/* 0x3485: or     ax,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_3489:
	/* 0x3489: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_348d:
	/* 0x348d: mov    r15,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_3494:
	/* 0x3494: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3497:
	/* 0x3497: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_3499:
	/* 0x3499: je     2be8 <tail_handle_ipv6+0x2be8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11240ULL;
	}
x86_l_349f:
	/* 0x349f: mov    r14,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_34a6:
	/* 0x34a6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34aa:
	/* 0x34aa: je     34c1 <tail_handle_ipv6+0x34c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34c1;
	}
x86_l_34ac:
	/* 0x34ac: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_34b3:
	/* 0x34b3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34b5:
	/* 0x34b5: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34b7:
	/* 0x34b7: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_34bb:
	/* 0x34bb: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_34bf:
	/* 0x34bf: jmp    34c7 <tail_handle_ipv6+0x34c7> */
	goto x86_l_34c7;
x86_l_34c1:
	/* 0x34c1: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_34c7:
	/* 0x34c7: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_34ca:
	/* 0x34ca: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34ce:
	/* 0x34ce: je     34df <tail_handle_ipv6+0x34df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34df;
	}
x86_l_34d0:
	/* 0x34d0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_34d5:
	/* 0x34d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34d7:
	/* 0x34d7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34d9:
	/* 0x34d9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_34dd:
	/* 0x34dd: jmp    3502 <tail_handle_ipv6+0x3502> */
	return 13570ULL;
x86_l_34df:
	/* 0x34df: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_34e4:
	/* 0x34e4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34e6:
	/* 0x34e6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_34e8:
	/* 0x34e8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_34ec:
	/* 0x34ec: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_34f6:
	/* 0x34f6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_34f9:
	/* 0x34f9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_34fe:
	/* 0x34fe: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
	return 13570ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13570ULL: goto x86_l_3502;
	case 13573ULL: goto x86_l_3505;
	case 13578ULL: goto x86_l_350a;
	case 13582ULL: goto x86_l_350e;
	case 13586ULL: goto x86_l_3512;
	case 13589ULL: goto x86_l_3515;
	case 13593ULL: goto x86_l_3519;
	case 13597ULL: goto x86_l_351d;
	case 13599ULL: goto x86_l_351f;
	case 13606ULL: goto x86_l_3526;
	case 13608ULL: goto x86_l_3528;
	case 13611ULL: goto x86_l_352b;
	case 13614ULL: goto x86_l_352e;
	case 13616ULL: goto x86_l_3530;
	case 13621ULL: goto x86_l_3535;
	case 13623ULL: goto x86_l_3537;
	case 13626ULL: goto x86_l_353a;
	case 13628ULL: goto x86_l_353c;
	case 13630ULL: goto x86_l_353e;
	case 13633ULL: goto x86_l_3541;
	case 13639ULL: goto x86_l_3547;
	case 13644ULL: goto x86_l_354c;
	case 13648ULL: goto x86_l_3550;
	case 13651ULL: goto x86_l_3553;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13664ULL: goto x86_l_3560;
	case 13667ULL: goto x86_l_3563;
	case 13672ULL: goto x86_l_3568;
	case 13675ULL: goto x86_l_356b;
	case 13680ULL: goto x86_l_3570;
	case 13685ULL: goto x86_l_3575;
	case 13691ULL: goto x86_l_357b;
	case 13696ULL: goto x86_l_3580;
	case 13701ULL: goto x86_l_3585;
	case 13706ULL: goto x86_l_358a;
	case 13708ULL: goto x86_l_358c;
	case 13711ULL: goto x86_l_358f;
	case 13713ULL: goto x86_l_3591;
	case 13716ULL: goto x86_l_3594;
	case 13719ULL: goto x86_l_3597;
	case 13721ULL: goto x86_l_3599;
	case 13726ULL: goto x86_l_359e;
	case 13728ULL: goto x86_l_35a0;
	case 13733ULL: goto x86_l_35a5;
	case 13738ULL: goto x86_l_35aa;
	case 13741ULL: goto x86_l_35ad;
	case 13745ULL: goto x86_l_35b1;
	case 13747ULL: goto x86_l_35b3;
	case 13754ULL: goto x86_l_35ba;
	case 13757ULL: goto x86_l_35bd;
	case 13760ULL: goto x86_l_35c0;
	case 13764ULL: goto x86_l_35c4;
	case 13768ULL: goto x86_l_35c8;
	case 13770ULL: goto x86_l_35ca;
	case 13775ULL: goto x86_l_35cf;
	case 13777ULL: goto x86_l_35d1;
	case 13779ULL: goto x86_l_35d3;
	case 13783ULL: goto x86_l_35d7;
	case 13785ULL: goto x86_l_35d9;
	case 13790ULL: goto x86_l_35de;
	case 13792ULL: goto x86_l_35e0;
	case 13794ULL: goto x86_l_35e2;
	case 13798ULL: goto x86_l_35e6;
	case 13808ULL: goto x86_l_35f0;
	case 13811ULL: goto x86_l_35f3;
	case 13816ULL: goto x86_l_35f8;
	case 13820ULL: goto x86_l_35fc;
	case 13822ULL: goto x86_l_35fe;
	case 13826ULL: goto x86_l_3602;
	case 13831ULL: goto x86_l_3607;
	case 13835ULL: goto x86_l_360b;
	case 13839ULL: goto x86_l_360f;
	case 13843ULL: goto x86_l_3613;
	case 13845ULL: goto x86_l_3615;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13857ULL: goto x86_l_3621;
	case 13860ULL: goto x86_l_3624;
	case 13862ULL: goto x86_l_3626;
	case 13867ULL: goto x86_l_362b;
	case 13869ULL: goto x86_l_362d;
	case 13872ULL: goto x86_l_3630;
	case 13874ULL: goto x86_l_3632;
	case 13876ULL: goto x86_l_3634;
	case 13879ULL: goto x86_l_3637;
	case 13885ULL: goto x86_l_363d;
	case 13889ULL: goto x86_l_3641;
	case 13893ULL: goto x86_l_3645;
	case 13898ULL: goto x86_l_364a;
	case 13904ULL: goto x86_l_3650;
	case 13908ULL: goto x86_l_3654;
	case 13910ULL: goto x86_l_3656;
	case 13912ULL: goto x86_l_3658;
	case 13914ULL: goto x86_l_365a;
	case 13917ULL: goto x86_l_365d;
	case 13920ULL: goto x86_l_3660;
	case 13922ULL: goto x86_l_3662;
	case 13927ULL: goto x86_l_3667;
	case 13931ULL: goto x86_l_366b;
	case 13933ULL: goto x86_l_366d;
	case 13938ULL: goto x86_l_3672;
	case 13944ULL: goto x86_l_3678;
	case 13948ULL: goto x86_l_367c;
	case 13952ULL: goto x86_l_3680;
	case 13954ULL: goto x86_l_3682;
	case 13961ULL: goto x86_l_3689;
	case 13965ULL: goto x86_l_368d;
	case 13969ULL: goto x86_l_3691;
	case 13972ULL: goto x86_l_3694;
	case 13976ULL: goto x86_l_3698;
	case 13978ULL: goto x86_l_369a;
	case 13983ULL: goto x86_l_369f;
	case 13985ULL: goto x86_l_36a1;
	case 13987ULL: goto x86_l_36a3;
	case 13991ULL: goto x86_l_36a7;
	case 13993ULL: goto x86_l_36a9;
	case 13998ULL: goto x86_l_36ae;
	case 14000ULL: goto x86_l_36b0;
	case 14002ULL: goto x86_l_36b2;
	case 14006ULL: goto x86_l_36b6;
	case 14016ULL: goto x86_l_36c0;
	case 14019ULL: goto x86_l_36c3;
	case 14024ULL: goto x86_l_36c8;
	case 14028ULL: goto x86_l_36cc;
	case 14031ULL: goto x86_l_36cf;
	case 14036ULL: goto x86_l_36d4;
	case 14040ULL: goto x86_l_36d8;
	case 14044ULL: goto x86_l_36dc;
	case 14047ULL: goto x86_l_36df;
	case 14051ULL: goto x86_l_36e3;
	case 14055ULL: goto x86_l_36e7;
	case 14057ULL: goto x86_l_36e9;
	case 14064ULL: goto x86_l_36f0;
	case 14066ULL: goto x86_l_36f2;
	case 14069ULL: goto x86_l_36f5;
	case 14072ULL: goto x86_l_36f8;
	case 14074ULL: goto x86_l_36fa;
	case 14079ULL: goto x86_l_36ff;
	case 14081ULL: goto x86_l_3701;
	case 14084ULL: goto x86_l_3704;
	case 14086ULL: goto x86_l_3706;
	case 14088ULL: goto x86_l_3708;
	case 14091ULL: goto x86_l_370b;
	case 14097ULL: goto x86_l_3711;
	case 14102ULL: goto x86_l_3716;
	case 14106ULL: goto x86_l_371a;
	case 14109ULL: goto x86_l_371d;
	case 14114ULL: goto x86_l_3722;
	case 14117ULL: goto x86_l_3725;
	case 14119ULL: goto x86_l_3727;
	default: return 0xffffffffffffffffULL;
	}
x86_l_3502:
	/* 0x3502: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3505:
	/* 0x3505: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_350a:
	/* 0x350a: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_350e:
	/* 0x350e: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_3512:
	/* 0x3512: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3515:
	/* 0x3515: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_3519:
	/* 0x3519: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_351d:
	/* 0x351d: je     3530 <tail_handle_ipv6+0x3530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3530;
	}
x86_l_351f:
	/* 0x351f: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3526:
	/* 0x3526: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3528:
	/* 0x3528: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_352b:
	/* 0x352b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_352e:
	/* 0x352e: jmp    3535 <tail_handle_ipv6+0x3535> */
	goto x86_l_3535;
x86_l_3530:
	/* 0x3530: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_3535:
	/* 0x3535: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3537:
	/* 0x3537: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_353a:
	/* 0x353a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_353c:
	/* 0x353c: jb     3547 <tail_handle_ipv6+0x3547> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3547;
	}
x86_l_353e:
	/* 0x353e: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_3541:
	/* 0x3541: je     2be8 <tail_handle_ipv6+0x2be8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11240ULL;
	}
x86_l_3547:
	/* 0x3547: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_354c:
	/* 0x354c: mov    BYTE PTR [rcx+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_3550:
	/* 0x3550: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3553:
	/* 0x3553: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3556:
	/* 0x3556: jmp    2be8 <tail_handle_ipv6+0x2be8> */
	return 11240ULL;
x86_l_355b:
	/* 0x355b: mov    ecx,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967141ULL);
x86_l_3560:
	/* 0x3560: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_3563:
	/* 0x3563: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_3568:
	/* 0x3568: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_356b:
	/* 0x356b: mov    ecx,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967141ULL);
x86_l_3570:
	/* 0x3570: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
x86_l_3575:
	/* 0x3575: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_357b:
	/* 0x357b: jmp    29a4 <tail_handle_ipv6+0x29a4> */
	return 10660ULL;
x86_l_3580:
	/* 0x3580: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_3585:
	/* 0x3585: cmp    BYTE PTR [rsp+0x48],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645318ULL);
x86_l_358a:
	/* 0x358a: jne    35c0 <tail_handle_ipv6+0x35c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35c0;
	}
x86_l_358c:
	/* 0x358c: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_358f:
	/* 0x358f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3591:
	/* 0x3591: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_3594:
	/* 0x3594: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_3597:
	/* 0x3597: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3599:
	/* 0x3599: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_359e:
	/* 0x359e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_35a0:
	/* 0x35a0: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_35a5:
	/* 0x35a5: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_35aa:
	/* 0x35aa: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_35ad:
	/* 0x35ad: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b1:
	/* 0x35b1: je     35c0 <tail_handle_ipv6+0x35c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c0;
	}
x86_l_35b3:
	/* 0x35b3: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_35ba:
	/* 0x35ba: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_35bd:
	/* 0x35bd: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_35c0:
	/* 0x35c0: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_35c4:
	/* 0x35c4: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35c8:
	/* 0x35c8: je     35d9 <tail_handle_ipv6+0x35d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35d9;
	}
x86_l_35ca:
	/* 0x35ca: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_35cf:
	/* 0x35cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35d1:
	/* 0x35d1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_35d3:
	/* 0x35d3: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_35d7:
	/* 0x35d7: jmp    35fc <tail_handle_ipv6+0x35fc> */
	goto x86_l_35fc;
x86_l_35d9:
	/* 0x35d9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_35de:
	/* 0x35de: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35e0:
	/* 0x35e0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_35e2:
	/* 0x35e2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_35e6:
	/* 0x35e6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_35f0:
	/* 0x35f0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_35f3:
	/* 0x35f3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_35f8:
	/* 0x35f8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_35fc:
	/* 0x35fc: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_35fe:
	/* 0x35fe: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3602:
	/* 0x3602: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_3607:
	/* 0x3607: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_360b:
	/* 0x360b: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_360f:
	/* 0x360f: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3613:
	/* 0x3613: je     3626 <tail_handle_ipv6+0x3626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3626;
	}
x86_l_3615:
	/* 0x3615: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_361c:
	/* 0x361c: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_361e:
	/* 0x361e: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_3621:
	/* 0x3621: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3624:
	/* 0x3624: jmp    362b <tail_handle_ipv6+0x362b> */
	goto x86_l_362b;
x86_l_3626:
	/* 0x3626: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_362b:
	/* 0x362b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_362d:
	/* 0x362d: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_3630:
	/* 0x3630: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_3632:
	/* 0x3632: jb     363d <tail_handle_ipv6+0x363d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_363d;
	}
x86_l_3634:
	/* 0x3634: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_3637:
	/* 0x3637: je     1846 <tail_handle_ipv6+0x1846> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6214ULL;
	}
x86_l_363d:
	/* 0x363d: mov    BYTE PTR [r14+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_3641:
	/* 0x3641: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3645:
	/* 0x3645: jmp    183d <tail_handle_ipv6+0x183d> */
	return 6205ULL;
x86_l_364a:
	/* 0x364a: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_3650:
	/* 0x3650: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_3654:
	/* 0x3654: jne    3691 <tail_handle_ipv6+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3691;
	}
x86_l_3656:
	/* 0x3656: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_3658:
	/* 0x3658: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_365a:
	/* 0x365a: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_365d:
	/* 0x365d: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_3660:
	/* 0x3660: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3662:
	/* 0x3662: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3667:
	/* 0x3667: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_366b:
	/* 0x366b: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_366d:
	/* 0x366d: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_3672:
	/* 0x3672: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_3678:
	/* 0x3678: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_367c:
	/* 0x367c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3680:
	/* 0x3680: je     3691 <tail_handle_ipv6+0x3691> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3691;
	}
x86_l_3682:
	/* 0x3682: mov    rax,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3689:
	/* 0x3689: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_368d:
	/* 0x368d: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3691:
	/* 0x3691: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3694:
	/* 0x3694: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3698:
	/* 0x3698: je     36a9 <tail_handle_ipv6+0x36a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36a9;
	}
x86_l_369a:
	/* 0x369a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_369f:
	/* 0x369f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36a1:
	/* 0x36a1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36a3:
	/* 0x36a3: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_36a7:
	/* 0x36a7: jmp    36cc <tail_handle_ipv6+0x36cc> */
	goto x86_l_36cc;
x86_l_36a9:
	/* 0x36a9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_36ae:
	/* 0x36ae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36b0:
	/* 0x36b0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36b2:
	/* 0x36b2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_36b6:
	/* 0x36b6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_36c0:
	/* 0x36c0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_36c3:
	/* 0x36c3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_36c8:
	/* 0x36c8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_36cc:
	/* 0x36cc: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36cf:
	/* 0x36cf: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_36d4:
	/* 0x36d4: mov    DWORD PTR [rdx+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_36d8:
	/* 0x36d8: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_36dc:
	/* 0x36dc: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36df:
	/* 0x36df: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_36e3:
	/* 0x36e3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e7:
	/* 0x36e7: je     36fa <tail_handle_ipv6+0x36fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36fa;
	}
x86_l_36e9:
	/* 0x36e9: mov    rsi,QWORD PTR [rip+0xec62] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_36f0:
	/* 0x36f0: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36f2:
	/* 0x36f2: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_36f5:
	/* 0x36f5: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_36f8:
	/* 0x36f8: jmp    36ff <tail_handle_ipv6+0x36ff> */
	goto x86_l_36ff;
x86_l_36fa:
	/* 0x36fa: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_36ff:
	/* 0x36ff: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3701:
	/* 0x3701: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_3704:
	/* 0x3704: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_3706:
	/* 0x3706: jb     3711 <tail_handle_ipv6+0x3711> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3711;
	}
x86_l_3708:
	/* 0x3708: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_370b:
	/* 0x370b: je     29ea <tail_handle_ipv6+0x29ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10730ULL;
	}
x86_l_3711:
	/* 0x3711: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3716:
	/* 0x3716: mov    BYTE PTR [rcx+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_371a:
	/* 0x371a: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_371d:
	/* 0x371d: jmp    29e1 <tail_handle_ipv6+0x29e1> */
	return 10721ULL;
x86_l_3722:
	/* 0x3722: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3725:
	/* 0x3725: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_3727:
	/* 0x3727: jmp    32f4 <tail_handle_ipv6+0x32f4> */
	return 13044ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_wireguard_tail_handle_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 12892U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1822ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1824ULL && __x86_pc <= 3707ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3709ULL && __x86_pc <= 5336ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5339ULL && __x86_pc <= 6999ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7001ULL && __x86_pc <= 8654ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8664ULL && __x86_pc <= 10346ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10351ULL && __x86_pc <= 12022ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12024ULL && __x86_pc <= 13566ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13570ULL && __x86_pc <= 14119ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv6_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

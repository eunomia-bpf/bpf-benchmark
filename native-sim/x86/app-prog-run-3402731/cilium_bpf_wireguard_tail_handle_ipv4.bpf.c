extern char __config_cilium_host_ifindex;
extern char __config_cilium_host_mac;
extern char __config_cluster_id_bits;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_identity_mark;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_netkit;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_interface_mac;
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

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_0(
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
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 36ULL: goto x86_l_24;
	case 41ULL: goto x86_l_29;
	case 43ULL: goto x86_l_2b;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 52ULL: goto x86_l_34;
	case 57ULL: goto x86_l_39;
	case 60ULL: goto x86_l_3c;
	case 66ULL: goto x86_l_42;
	case 73ULL: goto x86_l_49;
	case 80ULL: goto x86_l_50;
	case 84ULL: goto x86_l_54;
	case 90ULL: goto x86_l_5a;
	case 97ULL: goto x86_l_61;
	case 101ULL: goto x86_l_65;
	case 104ULL: goto x86_l_68;
	case 111ULL: goto x86_l_6f;
	case 119ULL: goto x86_l_77;
	case 125ULL: goto x86_l_7d;
	case 135ULL: goto x86_l_87;
	case 142ULL: goto x86_l_8e;
	case 150ULL: goto x86_l_96;
	case 161ULL: goto x86_l_a1;
	case 171ULL: goto x86_l_ab;
	case 183ULL: goto x86_l_b7;
	case 187ULL: goto x86_l_bb;
	case 191ULL: goto x86_l_bf;
	case 194ULL: goto x86_l_c2;
	case 198ULL: goto x86_l_c6;
	case 201ULL: goto x86_l_c9;
	case 205ULL: goto x86_l_cd;
	case 208ULL: goto x86_l_d0;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 222ULL: goto x86_l_de;
	case 228ULL: goto x86_l_e4;
	case 232ULL: goto x86_l_e8;
	case 235ULL: goto x86_l_eb;
	case 239ULL: goto x86_l_ef;
	case 242ULL: goto x86_l_f2;
	case 246ULL: goto x86_l_f6;
	case 249ULL: goto x86_l_f9;
	case 253ULL: goto x86_l_fd;
	case 256ULL: goto x86_l_100;
	case 262ULL: goto x86_l_106;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 270ULL: goto x86_l_10e;
	case 276ULL: goto x86_l_114;
	case 279ULL: goto x86_l_117;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 307ULL: goto x86_l_133;
	case 311ULL: goto x86_l_137;
	case 315ULL: goto x86_l_13b;
	case 324ULL: goto x86_l_144;
	case 327ULL: goto x86_l_147;
	case 331ULL: goto x86_l_14b;
	case 338ULL: goto x86_l_152;
	case 346ULL: goto x86_l_15a;
	case 349ULL: goto x86_l_15d;
	case 355ULL: goto x86_l_163;
	case 360ULL: goto x86_l_168;
	case 363ULL: goto x86_l_16b;
	case 366ULL: goto x86_l_16e;
	case 369ULL: goto x86_l_171;
	case 374ULL: goto x86_l_176;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 384ULL: goto x86_l_180;
	case 394ULL: goto x86_l_18a;
	case 399ULL: goto x86_l_18f;
	case 405ULL: goto x86_l_195;
	case 410ULL: goto x86_l_19a;
	case 417ULL: goto x86_l_1a1;
	case 422ULL: goto x86_l_1a6;
	case 425ULL: goto x86_l_1a9;
	case 427ULL: goto x86_l_1ab;
	case 429ULL: goto x86_l_1ad;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 450ULL: goto x86_l_1c2;
	case 459ULL: goto x86_l_1cb;
	case 469ULL: goto x86_l_1d5;
	case 477ULL: goto x86_l_1dd;
	case 482ULL: goto x86_l_1e2;
	case 489ULL: goto x86_l_1e9;
	case 497ULL: goto x86_l_1f1;
	case 499ULL: goto x86_l_1f3;
	case 502ULL: goto x86_l_1f6;
	case 508ULL: goto x86_l_1fc;
	case 511ULL: goto x86_l_1ff;
	case 515ULL: goto x86_l_203;
	case 517ULL: goto x86_l_205;
	case 521ULL: goto x86_l_209;
	case 527ULL: goto x86_l_20f;
	case 533ULL: goto x86_l_215;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 546ULL: goto x86_l_222;
	case 549ULL: goto x86_l_225;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 566ULL: goto x86_l_236;
	case 569ULL: goto x86_l_239;
	case 574ULL: goto x86_l_23e;
	case 576ULL: goto x86_l_240;
	case 578ULL: goto x86_l_242;
	case 584ULL: goto x86_l_248;
	case 589ULL: goto x86_l_24d;
	case 596ULL: goto x86_l_254;
	case 600ULL: goto x86_l_258;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 620ULL: goto x86_l_26c;
	case 630ULL: goto x86_l_276;
	case 638ULL: goto x86_l_27e;
	case 643ULL: goto x86_l_283;
	case 650ULL: goto x86_l_28a;
	case 658ULL: goto x86_l_292;
	case 660ULL: goto x86_l_294;
	case 663ULL: goto x86_l_297;
	case 665ULL: goto x86_l_299;
	case 674ULL: goto x86_l_2a2;
	case 683ULL: goto x86_l_2ab;
	case 693ULL: goto x86_l_2b5;
	case 701ULL: goto x86_l_2bd;
	case 706ULL: goto x86_l_2c2;
	case 713ULL: goto x86_l_2c9;
	case 721ULL: goto x86_l_2d1;
	case 723ULL: goto x86_l_2d3;
	case 726ULL: goto x86_l_2d6;
	case 732ULL: goto x86_l_2dc;
	case 735ULL: goto x86_l_2df;
	case 744ULL: goto x86_l_2e8;
	case 749ULL: goto x86_l_2ed;
	case 751ULL: goto x86_l_2ef;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 766ULL: goto x86_l_2fe;
	case 771ULL: goto x86_l_303;
	case 775ULL: goto x86_l_307;
	case 780ULL: goto x86_l_30c;
	case 782ULL: goto x86_l_30e;
	case 785ULL: goto x86_l_311;
	case 788ULL: goto x86_l_314;
	case 792ULL: goto x86_l_318;
	case 800ULL: goto x86_l_320;
	case 805ULL: goto x86_l_325;
	case 812ULL: goto x86_l_32c;
	case 816ULL: goto x86_l_330;
	case 821ULL: goto x86_l_335;
	case 828ULL: goto x86_l_33c;
	case 833ULL: goto x86_l_341;
	case 835ULL: goto x86_l_343;
	case 840ULL: goto x86_l_348;
	case 843ULL: goto x86_l_34b;
	case 846ULL: goto x86_l_34e;
	case 850ULL: goto x86_l_352;
	case 853ULL: goto x86_l_355;
	case 856ULL: goto x86_l_358;
	case 858ULL: goto x86_l_35a;
	case 861ULL: goto x86_l_35d;
	case 867ULL: goto x86_l_363;
	case 871ULL: goto x86_l_367;
	case 873ULL: goto x86_l_369;
	case 878ULL: goto x86_l_36e;
	case 883ULL: goto x86_l_373;
	case 888ULL: goto x86_l_378;
	case 893ULL: goto x86_l_37d;
	case 896ULL: goto x86_l_380;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 918ULL: goto x86_l_396;
	case 922ULL: goto x86_l_39a;
	case 925ULL: goto x86_l_39d;
	case 931ULL: goto x86_l_3a3;
	case 938ULL: goto x86_l_3aa;
	case 943ULL: goto x86_l_3af;
	case 951ULL: goto x86_l_3b7;
	case 960ULL: goto x86_l_3c0;
	case 965ULL: goto x86_l_3c5;
	case 970ULL: goto x86_l_3ca;
	case 975ULL: goto x86_l_3cf;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 991ULL: goto x86_l_3df;
	case 999ULL: goto x86_l_3e7;
	case 1004ULL: goto x86_l_3ec;
	case 1007ULL: goto x86_l_3ef;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1019ULL: goto x86_l_3fb;
	case 1024ULL: goto x86_l_400;
	case 1026ULL: goto x86_l_402;
	case 1028ULL: goto x86_l_404;
	case 1034ULL: goto x86_l_40a;
	case 1040ULL: goto x86_l_410;
	case 1045ULL: goto x86_l_415;
	case 1050ULL: goto x86_l_41a;
	case 1055ULL: goto x86_l_41f;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1072ULL: goto x86_l_430;
	case 1079ULL: goto x86_l_437;
	case 1084ULL: goto x86_l_43c;
	case 1091ULL: goto x86_l_443;
	case 1099ULL: goto x86_l_44b;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1124ULL: goto x86_l_464;
	case 1129ULL: goto x86_l_469;
	case 1133ULL: goto x86_l_46d;
	case 1137ULL: goto x86_l_471;
	case 1145ULL: goto x86_l_479;
	case 1149ULL: goto x86_l_47d;
	case 1154ULL: goto x86_l_482;
	case 1159ULL: goto x86_l_487;
	case 1170ULL: goto x86_l_492;
	case 1173ULL: goto x86_l_495;
	case 1180ULL: goto x86_l_49c;
	case 1183ULL: goto x86_l_49f;
	case 1191ULL: goto x86_l_4a7;
	case 1197ULL: goto x86_l_4ad;
	case 1200ULL: goto x86_l_4b0;
	case 1206ULL: goto x86_l_4b6;
	case 1210ULL: goto x86_l_4ba;
	case 1219ULL: goto x86_l_4c3;
	case 1228ULL: goto x86_l_4cc;
	case 1238ULL: goto x86_l_4d6;
	case 1244ULL: goto x86_l_4dc;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1261ULL: goto x86_l_4ed;
	case 1266ULL: goto x86_l_4f2;
	case 1268ULL: goto x86_l_4f4;
	case 1271ULL: goto x86_l_4f7;
	case 1273ULL: goto x86_l_4f9;
	case 1276ULL: goto x86_l_4fc;
	case 1280ULL: goto x86_l_500;
	case 1282ULL: goto x86_l_502;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1306ULL: goto x86_l_51a;
	case 1311ULL: goto x86_l_51f;
	case 1316ULL: goto x86_l_524;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1333ULL: goto x86_l_535;
	case 1335ULL: goto x86_l_537;
	case 1337ULL: goto x86_l_539;
	case 1340ULL: goto x86_l_53c;
	case 1345ULL: goto x86_l_541;
	case 1353ULL: goto x86_l_549;
	case 1355ULL: goto x86_l_54b;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1363ULL: goto x86_l_553;
	case 1368ULL: goto x86_l_558;
	case 1372ULL: goto x86_l_55c;
	case 1380ULL: goto x86_l_564;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1390ULL: goto x86_l_56e;
	case 1392ULL: goto x86_l_570;
	case 1398ULL: goto x86_l_576;
	case 1405ULL: goto x86_l_57d;
	case 1407ULL: goto x86_l_57f;
	case 1412ULL: goto x86_l_584;
	case 1415ULL: goto x86_l_587;
	case 1420ULL: goto x86_l_58c;
	case 1423ULL: goto x86_l_58f;
	case 1429ULL: goto x86_l_595;
	case 1434ULL: goto x86_l_59a;
	case 1440ULL: goto x86_l_5a0;
	case 1443ULL: goto x86_l_5a3;
	case 1445ULL: goto x86_l_5a5;
	case 1448ULL: goto x86_l_5a8;
	case 1455ULL: goto x86_l_5af;
	case 1460ULL: goto x86_l_5b4;
	case 1465ULL: goto x86_l_5b9;
	case 1470ULL: goto x86_l_5be;
	case 1478ULL: goto x86_l_5c6;
	case 1480ULL: goto x86_l_5c8;
	case 1483ULL: goto x86_l_5cb;
	case 1489ULL: goto x86_l_5d1;
	case 1494ULL: goto x86_l_5d6;
	case 1498ULL: goto x86_l_5da;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1514ULL: goto x86_l_5ea;
	case 1520ULL: goto x86_l_5f0;
	case 1524ULL: goto x86_l_5f4;
	case 1530ULL: goto x86_l_5fa;
	case 1537ULL: goto x86_l_601;
	case 1540ULL: goto x86_l_604;
	case 1546ULL: goto x86_l_60a;
	case 1553ULL: goto x86_l_611;
	case 1556ULL: goto x86_l_614;
	case 1560ULL: goto x86_l_618;
	case 1564ULL: goto x86_l_61c;
	case 1567ULL: goto x86_l_61f;
	case 1571ULL: goto x86_l_623;
	case 1576ULL: goto x86_l_628;
	case 1581ULL: goto x86_l_62d;
	case 1586ULL: goto x86_l_632;
	case 1591ULL: goto x86_l_637;
	case 1596ULL: goto x86_l_63c;
	case 1598ULL: goto x86_l_63e;
	case 1601ULL: goto x86_l_641;
	case 1606ULL: goto x86_l_646;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1628ULL: goto x86_l_65c;
	case 1638ULL: goto x86_l_666;
	case 1643ULL: goto x86_l_66b;
	case 1646ULL: goto x86_l_66e;
	case 1650ULL: goto x86_l_672;
	case 1652ULL: goto x86_l_674;
	case 1654ULL: goto x86_l_676;
	case 1656ULL: goto x86_l_678;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1669ULL: goto x86_l_685;
	case 1672ULL: goto x86_l_688;
	case 1677ULL: goto x86_l_68d;
	case 1682ULL: goto x86_l_692;
	case 1684ULL: goto x86_l_694;
	case 1686ULL: goto x86_l_696;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1715ULL: goto x86_l_6b3;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	case 1732ULL: goto x86_l_6c4;
	case 1734ULL: goto x86_l_6c6;
	case 1738ULL: goto x86_l_6ca;
	case 1747ULL: goto x86_l_6d3;
	case 1752ULL: goto x86_l_6d8;
	case 1762ULL: goto x86_l_6e2;
	case 1764ULL: goto x86_l_6e4;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1783ULL: goto x86_l_6f7;
	case 1789ULL: goto x86_l_6fd;
	case 1794ULL: goto x86_l_702;
	case 1796ULL: goto x86_l_704;
	case 1803ULL: goto x86_l_70b;
	case 1805ULL: goto x86_l_70d;
	case 1810ULL: goto x86_l_712;
	case 1812ULL: goto x86_l_714;
	case 1817ULL: goto x86_l_719;
	case 1827ULL: goto x86_l_723;
	case 1832ULL: goto x86_l_728;
	case 1839ULL: goto x86_l_72f;
	case 1849ULL: goto x86_l_739;
	case 1852ULL: goto x86_l_73c;
	case 1857ULL: goto x86_l_741;
	case 1864ULL: goto x86_l_748;
	case 1869ULL: goto x86_l_74d;
	case 1874ULL: goto x86_l_752;
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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    r13d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1f:
	/* 0x1f: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_24:
	/* 0x24: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_29:
	/* 0x29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b:
	/* 0x2b: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2e:
	/* 0x2e: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_31:
	/* 0x31: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34:
	/* 0x34: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_39:
	/* 0x39: cmp    ecx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_3c:
	/* 0x3c: jb     1e76 <tail_handle_ipv4+0x1e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7798ULL;
	}
x86_l_42:
	/* 0x42: mov    rbp,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_49:
	/* 0x49: mov    r10,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R10, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_50:
	/* 0x50: cmp    BYTE PTR [r10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54:
	/* 0x54: je     205 <tail_handle_ipv4+0x205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_205;
	}
x86_l_5a:
	/* 0x5a: movzx  ecx,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_61:
	/* 0x61: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_65:
	/* 0x65: and    ecx,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_68:
	/* 0x68: mov    WORD PTR [rbx+0x86],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 134ULL);
x86_l_6f:
	/* 0x6f: test   DWORD PTR [rsp+0x40],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906948ULL);
x86_l_77:
	/* 0x77: jne    1e06 <tail_handle_ipv4+0x1e06> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7686ULL;
	}
x86_l_7d:
	/* 0x7d: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_87:
	/* 0x87: mov    WORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_8e:
	/* 0x8e: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_96:
	/* 0x96: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_a1:
	/* 0xa1: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_b7:
	/* 0xb7: movzx  edx,WORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_bb:
	/* 0xbb: movzx  ecx,BYTE PTR [rbp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_bf:
	/* 0xbf: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_c2:
	/* 0xc2: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_c6:
	/* 0xc6: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c9:
	/* 0xc9: movzx  edx,WORD PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_cd:
	/* 0xcd: add    rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d0:
	/* 0xd0: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_d6:
	/* 0xd6: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_da:
	/* 0xda: lea    r9,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_de:
	/* 0xde: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_e4:
	/* 0xe4: cmove  r9,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_e8:
	/* 0xe8: mov    esi,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb:
	/* 0xeb: mov    BYTE PTR [rsp+0x2c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ef:
	/* 0xef: mov    edx,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f2:
	/* 0xf2: mov    DWORD PTR [rsp+0x20],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6:
	/* 0xf6: mov    edi,DWORD PTR [rbp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f9:
	/* 0xf9: mov    DWORD PTR [rsp+0x24],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fd:
	/* 0xfd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_100:
	/* 0x100: je     80a <tail_handle_ipv4+0x80a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2058ULL;
	}
x86_l_106:
	/* 0x106: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_109:
	/* 0x109: je     114 <tail_handle_ipv4+0x114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_114;
	}
x86_l_10b:
	/* 0x10b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10e:
	/* 0x10e: jne    1df4 <tail_handle_ipv4+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7668ULL;
	}
x86_l_114:
	/* 0x114: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_117:
	/* 0x117: lea    r14,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11c:
	/* 0x11c: and    esi,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_11f:
	/* 0x11f: cmp    BYTE PTR [r10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R10, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_123:
	/* 0x123: mov    DWORD PTR [rsp+0x18],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128:
	/* 0x128: mov    QWORD PTR [rsp+0x30],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12d:
	/* 0x12d: je     21f <tail_handle_ipv4+0x21f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f;
	}
x86_l_133:
	/* 0x133: mov    DWORD PTR [rsp+0x78],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_137:
	/* 0x137: mov    DWORD PTR [rsp+0x7c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_13b:
	/* 0x13b: mov    WORD PTR [rsp+0x80],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_144:
	/* 0x144: mov    rax,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R9, X86_WIDTH_64);
x86_l_147:
	/* 0x147: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_14b:
	/* 0x14b: mov    BYTE PTR [rsp+0x82],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 130ULL);
x86_l_152:
	/* 0x152: mov    BYTE PTR [rsp+0x83],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 562640715776ULL);
x86_l_15a:
	/* 0x15a: test   r9,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R8, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: jne    11df <tail_handle_ipv4+0x11df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4575ULL;
	}
x86_l_163:
	/* 0x163: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_168:
	/* 0x168: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_16e:
	/* 0x16e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_171:
	/* 0x171: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_176:
	/* 0x176: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178:
	/* 0x178: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17a:
	/* 0x17a: js     378 <tail_handle_ipv4+0x378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_378;
	}
x86_l_180:
	/* 0x180: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_18a:
	/* 0x18a: test   QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18f:
	/* 0x18f: je     248 <tail_handle_ipv4+0x248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_248;
	}
x86_l_195:
	/* 0x195: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19a:
	/* 0x19a: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1a1:
	/* 0x1a1: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a6:
	/* 0x1a6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1a9:
	/* 0x1a9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab:
	/* 0x1ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad:
	/* 0x1ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1af:
	/* 0x1af: je     248 <tail_handle_ipv4+0x248> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_248;
	}
x86_l_1b5:
	/* 0x1b5: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1c2:
	/* 0x1c2: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1cb:
	/* 0x1cb: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1dd:
	/* 0x1dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e2:
	/* 0x1e2: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1e9:
	/* 0x1e9: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f1:
	/* 0x1f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3:
	/* 0x1f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: je     1221 <tail_handle_ipv4+0x1221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4641ULL;
	}
x86_l_1fc:
	/* 0x1fc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ff:
	/* 0x1ff: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_203:
	/* 0x203: jmp    248 <tail_handle_ipv4+0x248> */
	goto x86_l_248;
x86_l_205:
	/* 0x205: movzx  ecx,WORD PTR [rbp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_209:
	/* 0x209: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_20f:
	/* 0x20f: je     5a <tail_handle_ipv4+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5a;
	}
x86_l_215:
	/* 0x215: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_21a:
	/* 0x21a: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_21f:
	/* 0x21f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222:
	/* 0x222: test   r9,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R8, X86_WIDTH_64);
x86_l_225:
	/* 0x225: jne    1205 <tail_handle_ipv4+0x1205> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4613ULL;
	}
x86_l_22b:
	/* 0x22b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_230:
	/* 0x230: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_233:
	/* 0x233: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_236:
	/* 0x236: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_239:
	/* 0x239: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_23e:
	/* 0x23e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_240:
	/* 0x240: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_242:
	/* 0x242: js     382 <tail_handle_ipv4+0x382> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_382;
	}
x86_l_248:
	/* 0x248: movzx  eax,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_24d:
	/* 0x24d: mov    BYTE PTR [rsp+0x90],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_254:
	/* 0x254: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_258:
	/* 0x258: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25f:
	/* 0x25f: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_264:
	/* 0x264: mov    WORD PTR [rsp+0x8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_26c:
	/* 0x26c: mov    WORD PTR [rsp+0x8e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_276:
	/* 0x276: mov    BYTE PTR [rsp+0x91],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 622770257920ULL);
x86_l_27e:
	/* 0x27e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_283:
	/* 0x283: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_28a:
	/* 0x28a: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_292:
	/* 0x292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294:
	/* 0x294: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_297:
	/* 0x297: jne    2dc <tail_handle_ipv4+0x2dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2dc;
	}
x86_l_299:
	/* 0x299: movzx  r14d,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_2a2:
	/* 0x2a2: movzx  r15d,WORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 140ULL);
x86_l_2ab:
	/* 0x2ab: mov    WORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_2b5:
	/* 0x2b5: mov    BYTE PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_2bd:
	/* 0x2bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c2:
	/* 0x2c2: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_2c9:
	/* 0x2c9: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2d1:
	/* 0x2d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3:
	/* 0x2d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d6:
	/* 0x2d6: je     3af <tail_handle_ipv4+0x3af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3af;
	}
x86_l_2dc:
	/* 0x2dc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2df:
	/* 0x2df: cmp    WORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_2e8:
	/* 0x2e8: mov    edi,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967138ULL);
x86_l_2ed:
	/* 0x2ed: jne    303 <tail_handle_ipv4+0x303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_303;
	}
x86_l_2ef:
	/* 0x2ef: cmp    BYTE PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_2f7:
	/* 0x2f7: jne    303 <tail_handle_ipv4+0x303> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_303;
	}
x86_l_2f9:
	/* 0x2f9: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fe:
	/* 0x2fe: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_303:
	/* 0x303: cmp    BYTE PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_307:
	/* 0x307: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_30c:
	/* 0x30c: jns    363 <tail_handle_ipv4+0x363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_363;
	}
x86_l_30e:
	/* 0x30e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_311:
	/* 0x311: mov    eax,DWORD PTR [rbp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_314:
	/* 0x314: movzx  ecx,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_318:
	/* 0x318: mov    DWORD PTR [rsp+0x40],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877907008ULL);
x86_l_320:
	/* 0x320: mov    WORD PTR [rsp+0x44],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_325:
	/* 0x325: mov    WORD PTR [rsp+0x46],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_32c:
	/* 0x32c: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_330:
	/* 0x330: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_335:
	/* 0x335: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_source_range)));
x86_l_33c:
	/* 0x33c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_341:
	/* 0x341: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_343:
	/* 0x343: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_348:
	/* 0x348: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34b:
	/* 0x34b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_34e:
	/* 0x34e: movzx  ecx,BYTE PTR [rdx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_352:
	/* 0x352: and    cl,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 64ULL);
x86_l_355:
	/* 0x355: shr    cl,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHR, 6ULL);
x86_l_358:
	/* 0x358: cmp    al,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_8);
x86_l_35a:
	/* 0x35a: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_35d:
	/* 0x35d: je     502 <tail_handle_ipv4+0x502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_502;
	}
x86_l_363:
	/* 0x363: test   BYTE PTR [rax+0x8],0x40 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_367:
	/* 0x367: jne    391 <tail_handle_ipv4+0x391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_391;
	}
x86_l_369:
	/* 0x369: mov    edi,0xffffff52 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967122ULL);
x86_l_36e:
	/* 0x36e: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_373:
	/* 0x373: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_378:
	/* 0x378: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_37d:
	/* 0x37d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_380:
	/* 0x380: jmp    387 <tail_handle_ipv4+0x387> */
	goto x86_l_387;
x86_l_382:
	/* 0x382: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_387:
	/* 0x387: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38c:
	/* 0x38c: jmp    82f <tail_handle_ipv4+0x82f> */
	return 2095ULL;
x86_l_391:
	/* 0x391: movzx  ecx,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_396:
	/* 0x396: mov    BYTE PTR [rsp+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39a:
	/* 0x39a: cmp    cl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_39d:
	/* 0x39d: jne    43c <tail_handle_ipv4+0x43c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_43c;
	}
x86_l_3a3:
	/* 0x3a3: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_3aa:
	/* 0x3aa: jmp    443 <tail_handle_ipv4+0x443> */
	goto x86_l_443;
x86_l_3af:
	/* 0x3af: mov    BYTE PTR [rsp+0x90],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3b7:
	/* 0x3b7: mov    WORD PTR [rsp+0x8c],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_3c0:
	/* 0x3c0: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c5:
	/* 0x3c5: mov    rcx,QWORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_3ca:
	/* 0x3ca: mov    QWORD PTR [rsp+0x46],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_3cf:
	/* 0x3cf: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d4:
	/* 0x3d4: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_3d9:
	/* 0x3d9: jne    66e <tail_handle_ipv4+0x66e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_66e;
	}
x86_l_3df:
	/* 0x3df: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3e7:
	/* 0x3e7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3ec:
	/* 0x3ec: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_3ef:
	/* 0x3ef: lea    esi,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f3:
	/* 0x3f3: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3f8:
	/* 0x3f8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3fb:
	/* 0x3fb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_400:
	/* 0x400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_402:
	/* 0x402: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_404:
	/* 0x404: js     637 <tail_handle_ipv4+0x637> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_637;
	}
x86_l_40a:
	/* 0x40a: rol    QWORD PTR [rsp+0x40],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 274877906976ULL);
x86_l_410:
	/* 0x410: rol    DWORD PTR [rsp+0x48],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 309237645328ULL);
x86_l_415:
	/* 0x415: xor    BYTE PTR [rsp+0x4d],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 330712481793ULL);
x86_l_41a:
	/* 0x41a: test   BYTE PTR [rsp+0x79],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 519691042818ULL);
x86_l_41f:
	/* 0x41f: jne    66b <tail_handle_ipv4+0x66b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_66b;
	}
x86_l_425:
	/* 0x425: cmp    BYTE PTR [rsp+0x4c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514502ULL);
x86_l_42a:
	/* 0x42a: jne    766 <tail_handle_ipv4+0x766> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1894ULL;
	}
x86_l_430:
	/* 0x430: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_437:
	/* 0x437: jmp    76d <tail_handle_ipv4+0x76d> */
	return 1901ULL;
x86_l_43c:
	/* 0x43c: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_443:
	/* 0x443: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_44b:
	/* 0x44b: movabs rbp,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 2199023255552ULL);
x86_l_455:
	/* 0x455: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_45a:
	/* 0x45a: movabs rcx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1099511627776ULL);
x86_l_464:
	/* 0x464: movzx  edx,BYTE PTR [rsp+0x2d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_469:
	/* 0x469: mov    BYTE PTR [rsp+0x8],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46d:
	/* 0x46d: mov    edx,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_471:
	/* 0x471: mov    QWORD PTR [rsp+0xa0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_479:
	/* 0x479: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_47d:
	/* 0x47d: mov    WORD PTR [rsp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_482:
	/* 0x482: mov    BYTE PTR [rsp+0x2d],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528324ULL);
x86_l_487:
	/* 0x487: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_492:
	/* 0x492: and    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_495:
	/* 0x495: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_49c:
	/* 0x49c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49f:
	/* 0x49f: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4a7:
	/* 0x4a7: je     53c <tail_handle_ipv4+0x53c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53c;
	}
x86_l_4ad:
	/* 0x4ad: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4b0:
	/* 0x4b0: je     53c <tail_handle_ipv4+0x53c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53c;
	}
x86_l_4b6:
	/* 0x4b6: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4ba:
	/* 0x4ba: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_4c3:
	/* 0x4c3: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_4cc:
	/* 0x4cc: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_4d6:
	/* 0x4d6: or     rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 256ULL);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4e1:
	/* 0x4e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e6:
	/* 0x4e6: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4ed:
	/* 0x4ed: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4f2:
	/* 0x4f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f4:
	/* 0x4f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f7:
	/* 0x4f7: je     511 <tail_handle_ipv4+0x511> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_511;
	}
x86_l_4f9:
	/* 0x4f9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4fc:
	/* 0x4fc: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_500:
	/* 0x500: jmp    539 <tail_handle_ipv4+0x539> */
	goto x86_l_539;
x86_l_502:
	/* 0x502: mov    edi,0xffffff4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967119ULL);
x86_l_507:
	/* 0x507: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_50c:
	/* 0x50c: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_511:
	/* 0x511: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_51a:
	/* 0x51a: mov    QWORD PTR [rsp+0x48],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_51f:
	/* 0x51f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_524:
	/* 0x524: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_52b:
	/* 0x52b: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_530:
	/* 0x530: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_535:
	/* 0x535: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_537:
	/* 0x537: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_539:
	/* 0x539: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53c:
	/* 0x53c: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_541:
	/* 0x541: mov    QWORD PTR [rsp+0xb8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_549:
	/* 0x549: jne    5a5 <tail_handle_ipv4+0x5a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5a5;
	}
x86_l_54b:
	/* 0x54b: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_54e:
	/* 0x54e: and    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_551:
	/* 0x551: jne    5a5 <tail_handle_ipv4+0x5a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_5a5;
	}
x86_l_553:
	/* 0x553: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_558:
	/* 0x558: lea    esi,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_55c:
	/* 0x55c: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_564:
	/* 0x564: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_567:
	/* 0x567: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_56c:
	/* 0x56c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56e:
	/* 0x56e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_570:
	/* 0x570: js     628 <tail_handle_ipv4+0x628> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_628;
	}
x86_l_576:
	/* 0x576: mov    ebp,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_57d:
	/* 0x57d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_57f:
	/* 0x57f: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_584:
	/* 0x584: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_587:
	/* 0x587: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_58c:
	/* 0x58c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_58f:
	/* 0x58f: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_595:
	/* 0x595: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_59a:
	/* 0x59a: jne    1251 <tail_handle_ipv4+0x1251> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4689ULL;
	}
x86_l_5a0:
	/* 0x5a0: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_5a3:
	/* 0x5a3: jmp    5b4 <tail_handle_ipv4+0x5b4> */
	goto x86_l_5b4;
x86_l_5a5:
	/* 0x5a5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a8:
	/* 0x5a8: mov    ebp,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5af:
	/* 0x5af: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b4:
	/* 0x5b4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b9:
	/* 0x5b9: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5be:
	/* 0x5be: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5c6:
	/* 0x5c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c8:
	/* 0x5c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cb:
	/* 0x5cb: je     135a <tail_handle_ipv4+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4954ULL;
	}
x86_l_5d1:
	/* 0x5d1: movzx  ecx,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_5d6:
	/* 0x5d6: cmp    WORD PTR [rax+0x26],cx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_5da:
	/* 0x5da: jne    135a <tail_handle_ipv4+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4954ULL;
	}
x86_l_5e0:
	/* 0x5e0: test   ebp,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 512ULL);
x86_l_5e6:
	/* 0x5e6: mov    DWORD PTR [rsp+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5ea:
	/* 0x5ea: je     a4e <tail_handle_ipv4+0xa4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2638ULL;
	}
x86_l_5f0:
	/* 0x5f0: test   BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_5f4:
	/* 0x5f4: je     a4e <tail_handle_ipv4+0xa4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2638ULL;
	}
x86_l_5fa:
	/* 0x5fa: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_601:
	/* 0x601: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_604:
	/* 0x604: je     9f4 <tail_handle_ipv4+0x9f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2548ULL;
	}
x86_l_60a:
	/* 0x60a: mov    rdx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_611:
	/* 0x611: mov    r14d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_614:
	/* 0x614: lea    edx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_618:
	/* 0x618: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_61c:
	/* 0x61c: sub    r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_61f:
	/* 0x61f: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_623:
	/* 0x623: jmp    9fa <tail_handle_ipv4+0x9fa> */
	return 2554ULL;
x86_l_628:
	/* 0x628: mov    edi,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967161ULL);
x86_l_62d:
	/* 0x62d: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_632:
	/* 0x632: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_637:
	/* 0x637: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_63c:
	/* 0x63c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63e:
	/* 0x63e: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_641:
	/* 0x641: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_646:
	/* 0x646: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_650:
	/* 0x650: mov    r9,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_655:
	/* 0x655: mov    r15,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_65c:
	/* 0x65c: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_666:
	/* 0x666: jmp    7c2 <tail_handle_ipv4+0x7c2> */
	return 1986ULL;
x86_l_66b:
	/* 0x66b: mov    r13,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_64);
x86_l_66e:
	/* 0x66e: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_672:
	/* 0x672: and    al,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_674:
	/* 0x674: cmp    al,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 7ULL);
x86_l_676:
	/* 0x676: jb     6ed <tail_handle_ipv4+0x6ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_6ed;
	}
x86_l_678:
	/* 0x678: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_67b:
	/* 0x67b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_680:
	/* 0x680: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_685:
	/* 0x685: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_688:
	/* 0x688: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_68d:
	/* 0x68d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_692:
	/* 0x692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_694:
	/* 0x694: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_696:
	/* 0x696: js     70d <tail_handle_ipv4+0x70d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_70d;
	}
x86_l_698:
	/* 0x698: cmp    BYTE PTR [rsp+0x78],0x9a */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075674ULL);
x86_l_69d:
	/* 0x69d: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_6a7:
	/* 0x6a7: mov    r9,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6ac:
	/* 0x6ac: mov    r15,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_6b3:
	/* 0x6b3: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_6bd:
	/* 0x6bd: jne    6ed <tail_handle_ipv4+0x6ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6ed;
	}
x86_l_6bf:
	/* 0x6bf: cmp    BYTE PTR [rsp+0x79],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 519691042824ULL);
x86_l_6c4:
	/* 0x6c4: jne    6ed <tail_handle_ipv4+0x6ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6ed;
	}
x86_l_6c6:
	/* 0x6c6: mov    eax,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_6ca:
	/* 0x6ca: movbe  DWORD PTR [rsp+0x88],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 136ULL);
x86_l_6d3:
	/* 0x6d3: movzx  eax,WORD PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 122ULL);
x86_l_6d8:
	/* 0x6d8: movbe  WORD PTR [rsp+0x8c],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 140ULL);
x86_l_6e2:
	/* 0x6e2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e4:
	/* 0x6e4: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_6e6:
	/* 0x6e6: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6eb:
	/* 0x6eb: jmp    739 <tail_handle_ipv4+0x739> */
	goto x86_l_739;
x86_l_6ed:
	/* 0x6ed: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_6f2:
	/* 0x6f2: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6f7:
	/* 0x6f7: jne    80a <tail_handle_ipv4+0x80a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2058ULL;
	}
x86_l_6fd:
	/* 0x6fd: cmp    BYTE PTR [rsp+0x4c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514502ULL);
x86_l_702:
	/* 0x702: jne    741 <tail_handle_ipv4+0x741> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_741;
	}
x86_l_704:
	/* 0x704: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_70b:
	/* 0x70b: jmp    748 <tail_handle_ipv4+0x748> */
	goto x86_l_748;
x86_l_70d:
	/* 0x70d: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_712:
	/* 0x712: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_714:
	/* 0x714: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_719:
	/* 0x719: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_723:
	/* 0x723: mov    r9,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_728:
	/* 0x728: mov    r15,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_72f:
	/* 0x72f: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_739:
	/* 0x739: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_73c:
	/* 0x73c: jmp    7c2 <tail_handle_ipv4+0x7c2> */
	return 1986ULL;
x86_l_741:
	/* 0x741: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_748:
	/* 0x748: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_74d:
	/* 0x74d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_752:
	/* 0x752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1876ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1885ULL: goto x86_l_75d;
	case 1889ULL: goto x86_l_761;
	case 1894ULL: goto x86_l_766;
	case 1901ULL: goto x86_l_76d;
	case 1906ULL: goto x86_l_772;
	case 1913ULL: goto x86_l_779;
	case 1918ULL: goto x86_l_77e;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1930ULL: goto x86_l_78a;
	case 1932ULL: goto x86_l_78c;
	case 1935ULL: goto x86_l_78f;
	case 1937ULL: goto x86_l_791;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1946ULL: goto x86_l_79a;
	case 1948ULL: goto x86_l_79c;
	case 1951ULL: goto x86_l_79f;
	case 1961ULL: goto x86_l_7a9;
	case 1966ULL: goto x86_l_7ae;
	case 1976ULL: goto x86_l_7b8;
	case 1986ULL: goto x86_l_7c2;
	case 1988ULL: goto x86_l_7c4;
	case 1994ULL: goto x86_l_7ca;
	case 1996ULL: goto x86_l_7cc;
	case 1998ULL: goto x86_l_7ce;
	case 2004ULL: goto x86_l_7d4;
	case 2009ULL: goto x86_l_7d9;
	case 2016ULL: goto x86_l_7e0;
	case 2024ULL: goto x86_l_7e8;
	case 2032ULL: goto x86_l_7f0;
	case 2037ULL: goto x86_l_7f5;
	case 2043ULL: goto x86_l_7fb;
	case 2047ULL: goto x86_l_7ff;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2058ULL: goto x86_l_80a;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2074ULL: goto x86_l_81a;
	case 2080ULL: goto x86_l_820;
	case 2083ULL: goto x86_l_823;
	case 2088ULL: goto x86_l_828;
	case 2090ULL: goto x86_l_82a;
	case 2095ULL: goto x86_l_82f;
	case 2097ULL: goto x86_l_831;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2112ULL: goto x86_l_840;
	case 2117ULL: goto x86_l_845;
	case 2128ULL: goto x86_l_850;
	case 2132ULL: goto x86_l_854;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2157ULL: goto x86_l_86d;
	case 2160ULL: goto x86_l_870;
	case 2163ULL: goto x86_l_873;
	case 2166ULL: goto x86_l_876;
	case 2175ULL: goto x86_l_87f;
	case 2184ULL: goto x86_l_888;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2204ULL: goto x86_l_89c;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2226ULL: goto x86_l_8b2;
	case 2230ULL: goto x86_l_8b6;
	case 2232ULL: goto x86_l_8b8;
	case 2241ULL: goto x86_l_8c1;
	case 2246ULL: goto x86_l_8c6;
	case 2251ULL: goto x86_l_8cb;
	case 2258ULL: goto x86_l_8d2;
	case 2263ULL: goto x86_l_8d7;
	case 2268ULL: goto x86_l_8dc;
	case 2270ULL: goto x86_l_8de;
	case 2272ULL: goto x86_l_8e0;
	case 2275ULL: goto x86_l_8e3;
	case 2278ULL: goto x86_l_8e6;
	case 2283ULL: goto x86_l_8eb;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2298ULL: goto x86_l_8fa;
	case 2300ULL: goto x86_l_8fc;
	case 2303ULL: goto x86_l_8ff;
	case 2305ULL: goto x86_l_901;
	case 2308ULL: goto x86_l_904;
	case 2313ULL: goto x86_l_909;
	case 2316ULL: goto x86_l_90c;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2332ULL: goto x86_l_91c;
	case 2334ULL: goto x86_l_91e;
	case 2336ULL: goto x86_l_920;
	case 2342ULL: goto x86_l_926;
	case 2348ULL: goto x86_l_92c;
	case 2355ULL: goto x86_l_933;
	case 2357ULL: goto x86_l_935;
	case 2362ULL: goto x86_l_93a;
	case 2364ULL: goto x86_l_93c;
	case 2369ULL: goto x86_l_941;
	case 2372ULL: goto x86_l_944;
	case 2374ULL: goto x86_l_946;
	case 2380ULL: goto x86_l_94c;
	case 2386ULL: goto x86_l_952;
	case 2388ULL: goto x86_l_954;
	case 2391ULL: goto x86_l_957;
	case 2395ULL: goto x86_l_95b;
	case 2397ULL: goto x86_l_95d;
	case 2399ULL: goto x86_l_95f;
	case 2407ULL: goto x86_l_967;
	case 2414ULL: goto x86_l_96e;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2427ULL: goto x86_l_97b;
	case 2429ULL: goto x86_l_97d;
	case 2432ULL: goto x86_l_980;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2441ULL: goto x86_l_989;
	case 2443ULL: goto x86_l_98b;
	case 2445ULL: goto x86_l_98d;
	case 2452ULL: goto x86_l_994;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2462ULL: goto x86_l_99e;
	case 2464ULL: goto x86_l_9a0;
	case 2469ULL: goto x86_l_9a5;
	case 2474ULL: goto x86_l_9aa;
	case 2479ULL: goto x86_l_9af;
	case 2481ULL: goto x86_l_9b1;
	case 2483ULL: goto x86_l_9b3;
	case 2486ULL: goto x86_l_9b6;
	case 2492ULL: goto x86_l_9bc;
	case 2499ULL: goto x86_l_9c3;
	case 2502ULL: goto x86_l_9c6;
	case 2508ULL: goto x86_l_9cc;
	case 2515ULL: goto x86_l_9d3;
	case 2519ULL: goto x86_l_9d7;
	case 2523ULL: goto x86_l_9db;
	case 2528ULL: goto x86_l_9e0;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2543ULL: goto x86_l_9ef;
	case 2548ULL: goto x86_l_9f4;
	case 2554ULL: goto x86_l_9fa;
	case 2557ULL: goto x86_l_9fd;
	case 2561ULL: goto x86_l_a01;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2573ULL: goto x86_l_a0d;
	case 2575ULL: goto x86_l_a0f;
	case 2579ULL: goto x86_l_a13;
	case 2581ULL: goto x86_l_a15;
	case 2586ULL: goto x86_l_a1a;
	case 2588ULL: goto x86_l_a1c;
	case 2590ULL: goto x86_l_a1e;
	case 2594ULL: goto x86_l_a22;
	case 2604ULL: goto x86_l_a2c;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2616ULL: goto x86_l_a38;
	case 2619ULL: goto x86_l_a3b;
	case 2622ULL: goto x86_l_a3e;
	case 2628ULL: goto x86_l_a44;
	case 2632ULL: goto x86_l_a48;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2643ULL: goto x86_l_a53;
	case 2645ULL: goto x86_l_a55;
	case 2648ULL: goto x86_l_a58;
	case 2654ULL: goto x86_l_a5e;
	case 2661ULL: goto x86_l_a65;
	case 2664ULL: goto x86_l_a68;
	case 2666ULL: goto x86_l_a6a;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2693ULL: goto x86_l_a85;
	case 2697ULL: goto x86_l_a89;
	case 2699ULL: goto x86_l_a8b;
	case 2702ULL: goto x86_l_a8e;
	case 2705ULL: goto x86_l_a91;
	case 2707ULL: goto x86_l_a93;
	case 2711ULL: goto x86_l_a97;
	case 2714ULL: goto x86_l_a9a;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2727ULL: goto x86_l_aa7;
	case 2730ULL: goto x86_l_aaa;
	case 2732ULL: goto x86_l_aac;
	case 2739ULL: goto x86_l_ab3;
	case 2742ULL: goto x86_l_ab6;
	case 2745ULL: goto x86_l_ab9;
	case 2748ULL: goto x86_l_abc;
	case 2752ULL: goto x86_l_ac0;
	case 2755ULL: goto x86_l_ac3;
	case 2762ULL: goto x86_l_aca;
	case 2765ULL: goto x86_l_acd;
	case 2767ULL: goto x86_l_acf;
	case 2772ULL: goto x86_l_ad4;
	case 2774ULL: goto x86_l_ad6;
	case 2776ULL: goto x86_l_ad8;
	case 2779ULL: goto x86_l_adb;
	case 2783ULL: goto x86_l_adf;
	case 2785ULL: goto x86_l_ae1;
	case 2790ULL: goto x86_l_ae6;
	case 2792ULL: goto x86_l_ae8;
	case 2794ULL: goto x86_l_aea;
	case 2798ULL: goto x86_l_aee;
	case 2808ULL: goto x86_l_af8;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2820ULL: goto x86_l_b04;
	case 2822ULL: goto x86_l_b06;
	case 2825ULL: goto x86_l_b09;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2838ULL: goto x86_l_b16;
	case 2846ULL: goto x86_l_b1e;
	case 2850ULL: goto x86_l_b22;
	case 2857ULL: goto x86_l_b29;
	case 2860ULL: goto x86_l_b2c;
	case 2862ULL: goto x86_l_b2e;
	case 2869ULL: goto x86_l_b35;
	case 2871ULL: goto x86_l_b37;
	case 2874ULL: goto x86_l_b3a;
	case 2877ULL: goto x86_l_b3d;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2887ULL: goto x86_l_b47;
	case 2891ULL: goto x86_l_b4b;
	case 2893ULL: goto x86_l_b4d;
	case 2896ULL: goto x86_l_b50;
	case 2898ULL: goto x86_l_b52;
	case 2900ULL: goto x86_l_b54;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2909ULL: goto x86_l_b5d;
	case 2912ULL: goto x86_l_b60;
	case 2919ULL: goto x86_l_b67;
	case 2921ULL: goto x86_l_b69;
	case 2928ULL: goto x86_l_b70;
	case 2931ULL: goto x86_l_b73;
	case 2933ULL: goto x86_l_b75;
	case 2938ULL: goto x86_l_b7a;
	case 2941ULL: goto x86_l_b7d;
	case 2946ULL: goto x86_l_b82;
	case 2950ULL: goto x86_l_b86;
	case 2952ULL: goto x86_l_b88;
	case 2956ULL: goto x86_l_b8c;
	case 2962ULL: goto x86_l_b92;
	case 2966ULL: goto x86_l_b96;
	case 2969ULL: goto x86_l_b99;
	case 2975ULL: goto x86_l_b9f;
	case 2981ULL: goto x86_l_ba5;
	case 2987ULL: goto x86_l_bab;
	case 2995ULL: goto x86_l_bb3;
	case 2999ULL: goto x86_l_bb7;
	case 3006ULL: goto x86_l_bbe;
	case 3010ULL: goto x86_l_bc2;
	case 3016ULL: goto x86_l_bc8;
	case 3023ULL: goto x86_l_bcf;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3038ULL: goto x86_l_bde;
	case 3045ULL: goto x86_l_be5;
	case 3047ULL: goto x86_l_be7;
	case 3054ULL: goto x86_l_bee;
	case 3057ULL: goto x86_l_bf1;
	case 3059ULL: goto x86_l_bf3;
	case 3066ULL: goto x86_l_bfa;
	case 3068ULL: goto x86_l_bfc;
	case 3070ULL: goto x86_l_bfe;
	case 3074ULL: goto x86_l_c02;
	case 3078ULL: goto x86_l_c06;
	case 3080ULL: goto x86_l_c08;
	case 3086ULL: goto x86_l_c0e;
	case 3094ULL: goto x86_l_c16;
	case 3097ULL: goto x86_l_c19;
	case 3100ULL: goto x86_l_c1c;
	case 3103ULL: goto x86_l_c1f;
	case 3105ULL: goto x86_l_c21;
	case 3110ULL: goto x86_l_c26;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3123ULL: goto x86_l_c33;
	case 3128ULL: goto x86_l_c38;
	case 3130ULL: goto x86_l_c3a;
	case 3132ULL: goto x86_l_c3c;
	case 3136ULL: goto x86_l_c40;
	case 3146ULL: goto x86_l_c4a;
	case 3149ULL: goto x86_l_c4d;
	case 3154ULL: goto x86_l_c52;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3169ULL: goto x86_l_c61;
	case 3173ULL: goto x86_l_c65;
	case 3177ULL: goto x86_l_c69;
	case 3180ULL: goto x86_l_c6c;
	case 3184ULL: goto x86_l_c70;
	case 3188ULL: goto x86_l_c74;
	case 3190ULL: goto x86_l_c76;
	case 3197ULL: goto x86_l_c7d;
	case 3199ULL: goto x86_l_c7f;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3215ULL: goto x86_l_c8f;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3224ULL: goto x86_l_c98;
	case 3227ULL: goto x86_l_c9b;
	case 3229ULL: goto x86_l_c9d;
	case 3233ULL: goto x86_l_ca1;
	case 3236ULL: goto x86_l_ca4;
	case 3243ULL: goto x86_l_cab;
	case 3245ULL: goto x86_l_cad;
	case 3250ULL: goto x86_l_cb2;
	case 3252ULL: goto x86_l_cb4;
	case 3256ULL: goto x86_l_cb8;
	case 3261ULL: goto x86_l_cbd;
	case 3265ULL: goto x86_l_cc1;
	case 3270ULL: goto x86_l_cc6;
	case 3275ULL: goto x86_l_ccb;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3301ULL: goto x86_l_ce5;
	case 3306ULL: goto x86_l_cea;
	case 3312ULL: goto x86_l_cf0;
	case 3320ULL: goto x86_l_cf8;
	case 3322ULL: goto x86_l_cfa;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3337ULL: goto x86_l_d09;
	case 3344ULL: goto x86_l_d10;
	case 3347ULL: goto x86_l_d13;
	case 3352ULL: goto x86_l_d18;
	case 3357ULL: goto x86_l_d1d;
	case 3363ULL: goto x86_l_d23;
	case 3368ULL: goto x86_l_d28;
	case 3371ULL: goto x86_l_d2b;
	case 3373ULL: goto x86_l_d2d;
	case 3376ULL: goto x86_l_d30;
	case 3378ULL: goto x86_l_d32;
	case 3383ULL: goto x86_l_d37;
	case 3385ULL: goto x86_l_d39;
	case 3387ULL: goto x86_l_d3b;
	case 3389ULL: goto x86_l_d3d;
	case 3397ULL: goto x86_l_d45;
	case 3404ULL: goto x86_l_d4c;
	case 3408ULL: goto x86_l_d50;
	case 3413ULL: goto x86_l_d55;
	case 3420ULL: goto x86_l_d5c;
	case 3428ULL: goto x86_l_d64;
	case 3430ULL: goto x86_l_d66;
	case 3433ULL: goto x86_l_d69;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3440ULL: goto x86_l_d70;
	case 3444ULL: goto x86_l_d74;
	case 3449ULL: goto x86_l_d79;
	case 3454ULL: goto x86_l_d7e;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_754:
	/* 0x754: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_757:
	/* 0x757: je     80a <tail_handle_ipv4+0x80a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_80a;
	}
x86_l_75d:
	/* 0x75d: and    BYTE PTR [rax+0x24],0x7f */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 154618822783ULL);
x86_l_761:
	/* 0x761: jmp    80a <tail_handle_ipv4+0x80a> */
	goto x86_l_80a;
x86_l_766:
	/* 0x766: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_76d:
	/* 0x76d: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_772:
	/* 0x772: mov    r15,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_779:
	/* 0x779: mov    BYTE PTR [rsp+0x4d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 330712481792ULL);
x86_l_77e:
	/* 0x77e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_783:
	/* 0x783: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_788:
	/* 0x788: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78a:
	/* 0x78a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_78c:
	/* 0x78c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78f:
	/* 0x78f: je     79a <tail_handle_ipv4+0x79a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_79a;
	}
x86_l_791:
	/* 0x791: movzx  eax,BYTE PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_795:
	/* 0x795: shr    al,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 7ULL);
x86_l_798:
	/* 0x798: jmp    79c <tail_handle_ipv4+0x79c> */
	goto x86_l_79c;
x86_l_79a:
	/* 0x79a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_79c:
	/* 0x79c: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_79f:
	/* 0x79f: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_7a9:
	/* 0x7a9: mov    r9,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7ae:
	/* 0x7ae: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_7b8:
	/* 0x7b8: mov    WORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_7c2:
	/* 0x7c2: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7c4:
	/* 0x7c4: js     1219 <tail_handle_ipv4+0x1219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4633ULL;
	}
x86_l_7ca:
	/* 0x7ca: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_7cc:
	/* 0x7cc: je     80a <tail_handle_ipv4+0x80a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_80a;
	}
x86_l_7ce:
	/* 0x7ce: rol    QWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 137438953504ULL);
x86_l_7d4:
	/* 0x7d4: rol    DWORD PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 171798691856ULL);
x86_l_7d9:
	/* 0x7d9: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7e0:
	/* 0x7e0: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7e8:
	/* 0x7e8: movzx  eax,WORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 140ULL);
x86_l_7f0:
	/* 0x7f0: mov    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7f5:
	/* 0x7f5: movzx  r14d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_7fb:
	/* 0x7fb: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_7ff:
	/* 0x7ff: jne    839 <tail_handle_ipv4+0x839> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_839;
	}
x86_l_801:
	/* 0x801: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_808:
	/* 0x808: jmp    840 <tail_handle_ipv4+0x840> */
	goto x86_l_840;
x86_l_80a:
	/* 0x80a: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_80e:
	/* 0x80e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_813:
	/* 0x813: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_81a:
	/* 0x81a: mov    r15d,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 36ULL);
x86_l_820:
	/* 0x820: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_823:
	/* 0x823: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_828:
	/* 0x828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82a:
	/* 0x82a: mov    ecx,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967156ULL);
x86_l_82f:
	/* 0x82f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_831:
	/* 0x831: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_834:
	/* 0x834: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_839:
	/* 0x839: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_840:
	/* 0x840: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_845:
	/* 0x845: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_850:
	/* 0x850: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_854:
	/* 0x854: je     8f6 <tail_handle_ipv4+0x8f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f6;
	}
x86_l_85a:
	/* 0x85a: and    r8,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_85d:
	/* 0x85d: je     8f6 <tail_handle_ipv4+0x8f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8f6;
	}
x86_l_863:
	/* 0x863: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_868:
	/* 0x868: mov    BYTE PTR [rsp+0x2],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_86d:
	/* 0x86d: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_870:
	/* 0x870: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_873:
	/* 0x873: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_876:
	/* 0x876: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_87f:
	/* 0x87f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_888:
	/* 0x888: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_892:
	/* 0x892: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_897:
	/* 0x897: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89c:
	/* 0x89c: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8a3:
	/* 0x8a3: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8a8:
	/* 0x8a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8aa:
	/* 0x8aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8ad:
	/* 0x8ad: je     8b8 <tail_handle_ipv4+0x8b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b8;
	}
x86_l_8af:
	/* 0x8af: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8b2:
	/* 0x8b2: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8b6:
	/* 0x8b6: jmp    8e0 <tail_handle_ipv4+0x8e0> */
	goto x86_l_8e0;
x86_l_8b8:
	/* 0x8b8: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_8c1:
	/* 0x8c1: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8c6:
	/* 0x8c6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8cb:
	/* 0x8cb: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8d2:
	/* 0x8d2: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8d7:
	/* 0x8d7: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8dc:
	/* 0x8dc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8de:
	/* 0x8de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e0:
	/* 0x8e0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_8e3:
	/* 0x8e3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_8e6:
	/* 0x8e6: mov    r9,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8eb:
	/* 0x8eb: movzx  r14d,BYTE PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_8f1:
	/* 0x8f1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8f6:
	/* 0x8f6: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_8fa:
	/* 0x8fa: jne    95f <tail_handle_ipv4+0x95f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_95f;
	}
x86_l_8fc:
	/* 0x8fc: and    r9,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_8ff:
	/* 0x8ff: jne    95f <tail_handle_ipv4+0x95f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_95f;
	}
x86_l_901:
	/* 0x901: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_904:
	/* 0x904: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_909:
	/* 0x909: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_90c:
	/* 0x90c: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_914:
	/* 0x914: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_917:
	/* 0x917: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_91c:
	/* 0x91c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91e:
	/* 0x91e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_920:
	/* 0x920: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_926:
	/* 0x926: js     9ea <tail_handle_ipv4+0x9ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_9ea;
	}
x86_l_92c:
	/* 0x92c: mov    edx,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_933:
	/* 0x933: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_935:
	/* 0x935: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_93a:
	/* 0x93a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93c:
	/* 0x93c: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_941:
	/* 0x941: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_944:
	/* 0x944: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_946:
	/* 0x946: test   edx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1280ULL);
x86_l_94c:
	/* 0x94c: jne    125c <tail_handle_ipv4+0x125c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4700ULL;
	}
x86_l_952:
	/* 0x952: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_954:
	/* 0x954: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_957:
	/* 0x957: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95b:
	/* 0x95b: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_95d:
	/* 0x95d: jmp    971 <tail_handle_ipv4+0x971> */
	goto x86_l_971;
x86_l_95f:
	/* 0x95f: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_967:
	/* 0x967: mov    ebp,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_96e:
	/* 0x96e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_971:
	/* 0x971: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_976:
	/* 0x976: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_97b:
	/* 0x97b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_97d:
	/* 0x97d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_980:
	/* 0x980: je     98d <tail_handle_ipv4+0x98d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_98d;
	}
x86_l_982:
	/* 0x982: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_985:
	/* 0x985: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_989:
	/* 0x989: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_98b:
	/* 0x98b: js     9aa <tail_handle_ipv4+0x9aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_9aa;
	}
x86_l_98d:
	/* 0x98d: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_994:
	/* 0x994: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_996:
	/* 0x996: movzx  ecx,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_99b:
	/* 0x99b: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_99e:
	/* 0x99e: je     9e0 <tail_handle_ipv4+0x9e0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9e0;
	}
x86_l_9a0:
	/* 0x9a0: movzx  ebp,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_9a5:
	/* 0x9a5: jmp    103c <tail_handle_ipv4+0x103c> */
	return 4156ULL;
x86_l_9aa:
	/* 0x9aa: mov    BYTE PTR [rsp+0x2],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_9af:
	/* 0x9af: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_9b1:
	/* 0x9b1: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_9b3:
	/* 0x9b3: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_9b6:
	/* 0x9b6: je     ebc <tail_handle_ipv4+0xebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3772ULL;
	}
x86_l_9bc:
	/* 0x9bc: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_9c3:
	/* 0x9c3: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c6:
	/* 0x9c6: je     ddd <tail_handle_ipv4+0xddd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3549ULL;
	}
x86_l_9cc:
	/* 0x9cc: mov    rdx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9d3:
	/* 0x9d3: imul   r15d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_9d7:
	/* 0x9d7: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9db:
	/* 0x9db: jmp    de3 <tail_handle_ipv4+0xde3> */
	return 3555ULL;
x86_l_9e0:
	/* 0x9e0: mov    ecx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967162ULL);
x86_l_9e5:
	/* 0x9e5: jmp    82f <tail_handle_ipv4+0x82f> */
	goto x86_l_82f;
x86_l_9ea:
	/* 0x9ea: mov    ecx,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967161ULL);
x86_l_9ef:
	/* 0x9ef: jmp    82f <tail_handle_ipv4+0x82f> */
	goto x86_l_82f;
x86_l_9f4:
	/* 0x9f4: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_9fa:
	/* 0x9fa: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_9fd:
	/* 0x9fd: add    r14d,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_a01:
	/* 0xa01: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a04:
	/* 0xa04: je     a15 <tail_handle_ipv4+0xa15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a15;
	}
x86_l_a06:
	/* 0xa06: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_a0b:
	/* 0xa0b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a0d:
	/* 0xa0d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a0f:
	/* 0xa0f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_a13:
	/* 0xa13: jmp    a38 <tail_handle_ipv4+0xa38> */
	goto x86_l_a38;
x86_l_a15:
	/* 0xa15: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a1a:
	/* 0xa1a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a1c:
	/* 0xa1c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a1e:
	/* 0xa1e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_a22:
	/* 0xa22: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_a2c:
	/* 0xa2c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a2f:
	/* 0xa2f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a34:
	/* 0xa34: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_a38:
	/* 0xa38: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_a3b:
	/* 0xa3b: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_a3e:
	/* 0xa3e: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_a44:
	/* 0xa44: mov    ebp,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a48:
	/* 0xa48: jae    135a <tail_handle_ipv4+0x135a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4954ULL;
	}
x86_l_a4e:
	/* 0xa4e: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a51:
	/* 0xa51: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a53:
	/* 0xa53: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a55:
	/* 0xa55: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_a58:
	/* 0xa58: je     b69 <tail_handle_ipv4+0xb69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b69;
	}
x86_l_a5e:
	/* 0xa5e: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a65:
	/* 0xa65: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a68:
	/* 0xa68: je     a79 <tail_handle_ipv4+0xa79> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a79;
	}
x86_l_a6a:
	/* 0xa6a: mov    rdx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a71:
	/* 0xa71: imul   ebp,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_a74:
	/* 0xa74: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a77:
	/* 0xa77: jmp    a7e <tail_handle_ipv4+0xa7e> */
	goto x86_l_a7e;
x86_l_a79:
	/* 0xa79: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_a7e:
	/* 0xa7e: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_a83:
	/* 0xa83: jne    ab9 <tail_handle_ipv4+0xab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ab9;
	}
x86_l_a85:
	/* 0xa85: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a89:
	/* 0xa89: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a8b:
	/* 0xa8b: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_a8e:
	/* 0xa8e: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_a91:
	/* 0xa91: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_a93:
	/* 0xa93: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a97:
	/* 0xa97: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_a9a:
	/* 0xa9a: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_a9f:
	/* 0xa9f: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_aa4:
	/* 0xaa4: cmove  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_aa7:
	/* 0xaa7: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aaa:
	/* 0xaaa: je     ab9 <tail_handle_ipv4+0xab9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ab9;
	}
x86_l_aac:
	/* 0xaac: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ab3:
	/* 0xab3: imul   ebp,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_ab6:
	/* 0xab6: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ab9:
	/* 0xab9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_abc:
	/* 0xabc: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ac0:
	/* 0xac0: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ac3:
	/* 0xac3: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_aca:
	/* 0xaca: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_acd:
	/* 0xacd: je     ae1 <tail_handle_ipv4+0xae1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ae1;
	}
x86_l_acf:
	/* 0xacf: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_ad4:
	/* 0xad4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad6:
	/* 0xad6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ad8:
	/* 0xad8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_adb:
	/* 0xadb: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_adf:
	/* 0xadf: jmp    b04 <tail_handle_ipv4+0xb04> */
	goto x86_l_b04;
x86_l_ae1:
	/* 0xae1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_ae6:
	/* 0xae6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae8:
	/* 0xae8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_aea:
	/* 0xaea: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_aee:
	/* 0xaee: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_af8:
	/* 0xaf8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_afb:
	/* 0xafb: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b00:
	/* 0xb00: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_b04:
	/* 0xb04: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b06:
	/* 0xb06: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_b09:
	/* 0xb09: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b0d:
	/* 0xb0d: movzx  edx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_b12:
	/* 0xb12: mov    esi,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b16:
	/* 0xb16: mov    r8d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b1e:
	/* 0xb1e: and    r8b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_b22:
	/* 0xb22: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b29:
	/* 0xb29: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2c:
	/* 0xb2c: je     b3f <tail_handle_ipv4+0xb3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3f;
	}
x86_l_b2e:
	/* 0xb2e: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b35:
	/* 0xb35: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b37:
	/* 0xb37: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_b3a:
	/* 0xb3a: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b3d:
	/* 0xb3d: jmp    b44 <tail_handle_ipv4+0xb44> */
	goto x86_l_b44;
x86_l_b3f:
	/* 0xb3f: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_b44:
	/* 0xb44: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b47:
	/* 0xb47: mov    ebp,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b4b:
	/* 0xb4b: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b4d:
	/* 0xb4d: or     r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_b50:
	/* 0xb50: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_b52:
	/* 0xb52: jb     b59 <tail_handle_ipv4+0xb59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b59;
	}
x86_l_b54:
	/* 0xb54: cmp    dl,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_8);
x86_l_b57:
	/* 0xb57: je     b69 <tail_handle_ipv4+0xb69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b69;
	}
x86_l_b59:
	/* 0xb59: mov    BYTE PTR [rax+0x2a],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_b5d:
	/* 0xb5d: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b60:
	/* 0xb60: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_b67:
	/* 0xb67: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b69:
	/* 0xb69: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_b70:
	/* 0xb70: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b73:
	/* 0xb73: je     b82 <tail_handle_ipv4+0xb82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b82;
	}
x86_l_b75:
	/* 0xb75: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_b7a:
	/* 0xb7a: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b7d:
	/* 0xb7d: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_b82:
	/* 0xb82: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_b86:
	/* 0xb86: je     bda <tail_handle_ipv4+0xbda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bda;
	}
x86_l_b88:
	/* 0xb88: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_b8c:
	/* 0xb8c: jne    cad <tail_handle_ipv4+0xcad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cad;
	}
x86_l_b92:
	/* 0xb92: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_b96:
	/* 0xb96: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_b99:
	/* 0xb99: je     cad <tail_handle_ipv4+0xcad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cad;
	}
x86_l_b9f:
	/* 0xb9f: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_ba5:
	/* 0xba5: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_bab:
	/* 0xbab: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bb3:
	/* 0xbb3: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bb7:
	/* 0xbb7: mov    r14,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_bbe:
	/* 0xbbe: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc2:
	/* 0xbc2: je     1266 <tail_handle_ipv4+0x1266> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4710ULL;
	}
x86_l_bc8:
	/* 0xbc8: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bcf:
	/* 0xbcf: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_bd2:
	/* 0xbd2: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bd5:
	/* 0xbd5: jmp    126b <tail_handle_ipv4+0x126b> */
	return 4715ULL;
x86_l_bda:
	/* 0xbda: or     BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_bde:
	/* 0xbde: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_be5:
	/* 0xbe5: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be7:
	/* 0xbe7: mov    rdx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_bee:
	/* 0xbee: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf1:
	/* 0xbf1: je     c08 <tail_handle_ipv4+0xc08> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c08;
	}
x86_l_bf3:
	/* 0xbf3: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bfa:
	/* 0xbfa: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bfc:
	/* 0xbfc: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bfe:
	/* 0xbfe: lea    r14d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_c02:
	/* 0xc02: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c06:
	/* 0xc06: jmp    c0e <tail_handle_ipv4+0xc0e> */
	goto x86_l_c0e;
x86_l_c08:
	/* 0xc08: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_c0e:
	/* 0xc0e: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c16:
	/* 0xc16: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c19:
	/* 0xc19: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_c1c:
	/* 0xc1c: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1f:
	/* 0xc1f: je     c33 <tail_handle_ipv4+0xc33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c33;
	}
x86_l_c21:
	/* 0xc21: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_c26:
	/* 0xc26: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c28:
	/* 0xc28: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c2a:
	/* 0xc2a: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c2d:
	/* 0xc2d: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_c31:
	/* 0xc31: jmp    c56 <tail_handle_ipv4+0xc56> */
	goto x86_l_c56;
x86_l_c33:
	/* 0xc33: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c38:
	/* 0xc38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c3a:
	/* 0xc3a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c3c:
	/* 0xc3c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c40:
	/* 0xc40: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c4a:
	/* 0xc4a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c4d:
	/* 0xc4d: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c52:
	/* 0xc52: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c56:
	/* 0xc56: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c59:
	/* 0xc59: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c61:
	/* 0xc61: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c65:
	/* 0xc65: movzx  edx,BYTE PTR [rax+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_c69:
	/* 0xc69: mov    esi,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c6c:
	/* 0xc6c: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c70:
	/* 0xc70: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c74:
	/* 0xc74: je     c87 <tail_handle_ipv4+0xc87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c87;
	}
x86_l_c76:
	/* 0xc76: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c7d:
	/* 0xc7d: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7f:
	/* 0xc7f: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_c82:
	/* 0xc82: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c85:
	/* 0xc85: jmp    c8c <tail_handle_ipv4+0xc8c> */
	goto x86_l_c8c;
x86_l_c87:
	/* 0xc87: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_c8c:
	/* 0xc8c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c8f:
	/* 0xc8f: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c91:
	/* 0xc91: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c94:
	/* 0xc94: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_c96:
	/* 0xc96: jb     c9d <tail_handle_ipv4+0xc9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c9d;
	}
x86_l_c98:
	/* 0xc98: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_c9b:
	/* 0xc9b: je     cad <tail_handle_ipv4+0xcad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cad;
	}
x86_l_c9d:
	/* 0xc9d: mov    BYTE PTR [rax+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_ca1:
	/* 0xca1: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ca4:
	/* 0xca4: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_cab:
	/* 0xcab: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cad:
	/* 0xcad: test   BYTE PTR [rsp+0x2d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528322ULL);
x86_l_cb2:
	/* 0xcb2: jne    cff <tail_handle_ipv4+0xcff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cff;
	}
x86_l_cb4:
	/* 0xcb4: movzx  ecx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_cb8:
	/* 0xcb8: mov    WORD PTR [rsp+0x2],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_cbd:
	/* 0xcbd: mov    r15d,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cc1:
	/* 0xcc1: mov    DWORD PTR [rsp+0x40],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cc6:
	/* 0xcc6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ccb:
	/* 0xccb: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_cd2:
	/* 0xcd2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cd7:
	/* 0xcd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd9:
	/* 0xcd9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cdc:
	/* 0xcdc: je     d09 <tail_handle_ipv4+0xd09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d09;
	}
x86_l_cde:
	/* 0xcde: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ce1:
	/* 0xce1: cmp    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_ce5:
	/* 0xce5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cea:
	/* 0xcea: je     1700 <tail_handle_ipv4+0x1700> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5888ULL;
	}
x86_l_cf0:
	/* 0xcf0: test   DWORD PTR [rsp+0x4],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869696ULL);
x86_l_cf8:
	/* 0xcf8: jne    d18 <tail_handle_ipv4+0xd18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d18;
	}
x86_l_cfa:
	/* 0xcfa: jmp    1700 <tail_handle_ipv4+0x1700> */
	return 5888ULL;
x86_l_cff:
	/* 0xcff: mov    edi,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967133ULL);
x86_l_d04:
	/* 0xd04: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_d09:
	/* 0xd09: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_d10:
	/* 0xd10: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d13:
	/* 0xd13: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d18:
	/* 0xd18: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_d1d:
	/* 0xd1d: je     15ab <tail_handle_ipv4+0x15ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5547ULL;
	}
x86_l_d23:
	/* 0xd23: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d28:
	/* 0xd28: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2b:
	/* 0xd2b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2d:
	/* 0xd2d: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_d30:
	/* 0xd30: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d32:
	/* 0xd32: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_d37:
	/* 0xd37: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d39:
	/* 0xd39: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_d3b:
	/* 0xd3b: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d3d:
	/* 0xd3d: mov    WORD PTR [rsp+0x8e],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 142ULL);
x86_l_d45:
	/* 0xd45: mov    r14,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_d4c:
	/* 0xd4c: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d50:
	/* 0xd50: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d55:
	/* 0xd55: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_d5c:
	/* 0xd5c: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d64:
	/* 0xd64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d66:
	/* 0xd66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d69:
	/* 0xd69: je     d70 <tail_handle_ipv4+0xd70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d70;
	}
x86_l_d6b:
	/* 0xd6b: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6e:
	/* 0xd6e: jmp    d74 <tail_handle_ipv4+0xd74> */
	goto x86_l_d74;
x86_l_d70:
	/* 0xd70: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d74:
	/* 0xd74: mov    DWORD PTR [rsp+0x40],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d79:
	/* 0xd79: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d7e:
	/* 0xd7e: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_d85:
	/* 0xd85: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d8a:
	/* 0xd8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 3468ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3468ULL: goto x86_l_d8c;
	case 3471ULL: goto x86_l_d8f;
	case 3477ULL: goto x86_l_d95;
	case 3483ULL: goto x86_l_d9b;
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3495ULL: goto x86_l_da7;
	case 3500ULL: goto x86_l_dac;
	case 3505ULL: goto x86_l_db1;
	case 3513ULL: goto x86_l_db9;
	case 3515ULL: goto x86_l_dbb;
	case 3518ULL: goto x86_l_dbe;
	case 3523ULL: goto x86_l_dc3;
	case 3525ULL: goto x86_l_dc5;
	case 3528ULL: goto x86_l_dc8;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3549ULL: goto x86_l_ddd;
	case 3555ULL: goto x86_l_de3;
	case 3560ULL: goto x86_l_de8;
	case 3563ULL: goto x86_l_deb;
	case 3565ULL: goto x86_l_ded;
	case 3567ULL: goto x86_l_def;
	case 3569ULL: goto x86_l_df1;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3577ULL: goto x86_l_df9;
	case 3581ULL: goto x86_l_dfd;
	case 3583ULL: goto x86_l_dff;
	case 3588ULL: goto x86_l_e04;
	case 3594ULL: goto x86_l_e0a;
	case 3598ULL: goto x86_l_e0e;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3610ULL: goto x86_l_e1a;
	case 3614ULL: goto x86_l_e1e;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3630ULL: goto x86_l_e2e;
	case 3633ULL: goto x86_l_e31;
	case 3635ULL: goto x86_l_e33;
	case 3640ULL: goto x86_l_e38;
	case 3642ULL: goto x86_l_e3a;
	case 3644ULL: goto x86_l_e3c;
	case 3648ULL: goto x86_l_e40;
	case 3650ULL: goto x86_l_e42;
	case 3655ULL: goto x86_l_e47;
	case 3657ULL: goto x86_l_e49;
	case 3659ULL: goto x86_l_e4b;
	case 3663ULL: goto x86_l_e4f;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3681ULL: goto x86_l_e61;
	case 3685ULL: goto x86_l_e65;
	case 3688ULL: goto x86_l_e68;
	case 3693ULL: goto x86_l_e6d;
	case 3697ULL: goto x86_l_e71;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3708ULL: goto x86_l_e7c;
	case 3715ULL: goto x86_l_e83;
	case 3718ULL: goto x86_l_e86;
	case 3720ULL: goto x86_l_e88;
	case 3727ULL: goto x86_l_e8f;
	case 3729ULL: goto x86_l_e91;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3749ULL: goto x86_l_ea5;
	case 3751ULL: goto x86_l_ea7;
	case 3754ULL: goto x86_l_eaa;
	case 3756ULL: goto x86_l_eac;
	case 3760ULL: goto x86_l_eb0;
	case 3763ULL: goto x86_l_eb3;
	case 3770ULL: goto x86_l_eba;
	case 3772ULL: goto x86_l_ebc;
	case 3779ULL: goto x86_l_ec3;
	case 3782ULL: goto x86_l_ec6;
	case 3787ULL: goto x86_l_ecb;
	case 3789ULL: goto x86_l_ecd;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3802ULL: goto x86_l_eda;
	case 3806ULL: goto x86_l_ede;
	case 3809ULL: goto x86_l_ee1;
	case 3811ULL: goto x86_l_ee3;
	case 3814ULL: goto x86_l_ee6;
	case 3820ULL: goto x86_l_eec;
	case 3824ULL: goto x86_l_ef0;
	case 3827ULL: goto x86_l_ef3;
	case 3833ULL: goto x86_l_ef9;
	case 3839ULL: goto x86_l_eff;
	case 3845ULL: goto x86_l_f05;
	case 3848ULL: goto x86_l_f08;
	case 3852ULL: goto x86_l_f0c;
	case 3859ULL: goto x86_l_f13;
	case 3864ULL: goto x86_l_f18;
	case 3870ULL: goto x86_l_f1e;
	case 3877ULL: goto x86_l_f25;
	case 3881ULL: goto x86_l_f29;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3892ULL: goto x86_l_f34;
	case 3898ULL: goto x86_l_f3a;
	case 3901ULL: goto x86_l_f3d;
	case 3905ULL: goto x86_l_f41;
	case 3909ULL: goto x86_l_f45;
	case 3913ULL: goto x86_l_f49;
	case 3917ULL: goto x86_l_f4d;
	case 3924ULL: goto x86_l_f54;
	case 3926ULL: goto x86_l_f56;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3948ULL: goto x86_l_f6c;
	case 3950ULL: goto x86_l_f6e;
	case 3957ULL: goto x86_l_f75;
	case 3959ULL: goto x86_l_f77;
	case 3961ULL: goto x86_l_f79;
	case 3964ULL: goto x86_l_f7c;
	case 3967ULL: goto x86_l_f7f;
	case 3969ULL: goto x86_l_f81;
	case 3974ULL: goto x86_l_f86;
	case 3977ULL: goto x86_l_f89;
	case 3981ULL: goto x86_l_f8d;
	case 3984ULL: goto x86_l_f90;
	case 3986ULL: goto x86_l_f92;
	case 3991ULL: goto x86_l_f97;
	case 3993ULL: goto x86_l_f99;
	case 3995ULL: goto x86_l_f9b;
	case 3998ULL: goto x86_l_f9e;
	case 4002ULL: goto x86_l_fa2;
	case 4004ULL: goto x86_l_fa4;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4013ULL: goto x86_l_fad;
	case 4017ULL: goto x86_l_fb1;
	case 4027ULL: goto x86_l_fbb;
	case 4030ULL: goto x86_l_fbe;
	case 4035ULL: goto x86_l_fc3;
	case 4039ULL: goto x86_l_fc7;
	case 4041ULL: goto x86_l_fc9;
	case 4045ULL: goto x86_l_fcd;
	case 4050ULL: goto x86_l_fd2;
	case 4054ULL: goto x86_l_fd6;
	case 4058ULL: goto x86_l_fda;
	case 4065ULL: goto x86_l_fe1;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4075ULL: goto x86_l_feb;
	case 4082ULL: goto x86_l_ff2;
	case 4084ULL: goto x86_l_ff4;
	case 4087ULL: goto x86_l_ff7;
	case 4090ULL: goto x86_l_ffa;
	case 4092ULL: goto x86_l_ffc;
	case 4097ULL: goto x86_l_1001;
	case 4099ULL: goto x86_l_1003;
	case 4102ULL: goto x86_l_1006;
	case 4104ULL: goto x86_l_1008;
	case 4111ULL: goto x86_l_100f;
	case 4113ULL: goto x86_l_1011;
	case 4116ULL: goto x86_l_1014;
	case 4118ULL: goto x86_l_1016;
	case 4122ULL: goto x86_l_101a;
	case 4126ULL: goto x86_l_101e;
	case 4128ULL: goto x86_l_1020;
	case 4133ULL: goto x86_l_1025;
	case 4136ULL: goto x86_l_1028;
	case 4142ULL: goto x86_l_102e;
	case 4145ULL: goto x86_l_1031;
	case 4150ULL: goto x86_l_1036;
	case 4156ULL: goto x86_l_103c;
	case 4160ULL: goto x86_l_1040;
	case 4162ULL: goto x86_l_1042;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4178ULL: goto x86_l_1052;
	case 4183ULL: goto x86_l_1057;
	case 4192ULL: goto x86_l_1060;
	case 4201ULL: goto x86_l_1069;
	case 4210ULL: goto x86_l_1072;
	case 4219ULL: goto x86_l_107b;
	case 4228ULL: goto x86_l_1084;
	case 4236ULL: goto x86_l_108c;
	case 4244ULL: goto x86_l_1094;
	case 4248ULL: goto x86_l_1098;
	case 4253ULL: goto x86_l_109d;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4274ULL: goto x86_l_10b2;
	case 4281ULL: goto x86_l_10b9;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4294ULL: goto x86_l_10c6;
	case 4298ULL: goto x86_l_10ca;
	case 4302ULL: goto x86_l_10ce;
	case 4304ULL: goto x86_l_10d0;
	case 4310ULL: goto x86_l_10d6;
	case 4314ULL: goto x86_l_10da;
	case 4316ULL: goto x86_l_10dc;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4329ULL: goto x86_l_10e9;
	case 4336ULL: goto x86_l_10f0;
	case 4340ULL: goto x86_l_10f4;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4352ULL: goto x86_l_1100;
	case 4356ULL: goto x86_l_1104;
	case 4358ULL: goto x86_l_1106;
	case 4363ULL: goto x86_l_110b;
	case 4365ULL: goto x86_l_110d;
	case 4367ULL: goto x86_l_110f;
	case 4371ULL: goto x86_l_1113;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4386ULL: goto x86_l_1122;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4408ULL: goto x86_l_1138;
	case 4412ULL: goto x86_l_113c;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4438ULL: goto x86_l_1156;
	case 4440ULL: goto x86_l_1158;
	case 4447ULL: goto x86_l_115f;
	case 4449ULL: goto x86_l_1161;
	case 4453ULL: goto x86_l_1165;
	case 4457ULL: goto x86_l_1169;
	case 4459ULL: goto x86_l_116b;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4473ULL: goto x86_l_1179;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4488ULL: goto x86_l_1188;
	case 4492ULL: goto x86_l_118c;
	case 4499ULL: goto x86_l_1193;
	case 4501ULL: goto x86_l_1195;
	case 4508ULL: goto x86_l_119c;
	case 4511ULL: goto x86_l_119f;
	case 4513ULL: goto x86_l_11a1;
	case 4522ULL: goto x86_l_11aa;
	case 4525ULL: goto x86_l_11ad;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4540ULL: goto x86_l_11bc;
	case 4545ULL: goto x86_l_11c1;
	case 4547ULL: goto x86_l_11c3;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4554ULL: goto x86_l_11ca;
	case 4559ULL: goto x86_l_11cf;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4578ULL: goto x86_l_11e2;
	case 4583ULL: goto x86_l_11e7;
	case 4590ULL: goto x86_l_11ee;
	case 4595ULL: goto x86_l_11f3;
	case 4597ULL: goto x86_l_11f5;
	case 4600ULL: goto x86_l_11f8;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4608ULL: goto x86_l_1200;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4623ULL: goto x86_l_120f;
	case 4628ULL: goto x86_l_1214;
	case 4633ULL: goto x86_l_1219;
	case 4636ULL: goto x86_l_121c;
	case 4641ULL: goto x86_l_1221;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4660ULL: goto x86_l_1234;
	case 4667ULL: goto x86_l_123b;
	case 4675ULL: goto x86_l_1243;
	case 4680ULL: goto x86_l_1248;
	case 4682ULL: goto x86_l_124a;
	case 4684ULL: goto x86_l_124c;
	case 4689ULL: goto x86_l_1251;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4715ULL: goto x86_l_126b;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4731ULL: goto x86_l_127b;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4744ULL: goto x86_l_1288;
	case 4748ULL: goto x86_l_128c;
	case 4750ULL: goto x86_l_128e;
	case 4755ULL: goto x86_l_1293;
	case 4760ULL: goto x86_l_1298;
	case 4763ULL: goto x86_l_129b;
	case 4767ULL: goto x86_l_129f;
	case 4769ULL: goto x86_l_12a1;
	case 4776ULL: goto x86_l_12a8;
	case 4779ULL: goto x86_l_12ab;
	case 4782ULL: goto x86_l_12ae;
	case 4787ULL: goto x86_l_12b3;
	case 4791ULL: goto x86_l_12b7;
	case 4793ULL: goto x86_l_12b9;
	case 4798ULL: goto x86_l_12be;
	case 4800ULL: goto x86_l_12c0;
	case 4802ULL: goto x86_l_12c2;
	case 4806ULL: goto x86_l_12c6;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4817ULL: goto x86_l_12d1;
	case 4821ULL: goto x86_l_12d5;
	case 4831ULL: goto x86_l_12df;
	case 4834ULL: goto x86_l_12e2;
	case 4839ULL: goto x86_l_12e7;
	case 4843ULL: goto x86_l_12eb;
	case 4845ULL: goto x86_l_12ed;
	case 4853ULL: goto x86_l_12f5;
	case 4856ULL: goto x86_l_12f8;
	case 4860ULL: goto x86_l_12fc;
	case 4863ULL: goto x86_l_12ff;
	case 4867ULL: goto x86_l_1303;
	case 4871ULL: goto x86_l_1307;
	case 4875ULL: goto x86_l_130b;
	case 4879ULL: goto x86_l_130f;
	case 4881ULL: goto x86_l_1311;
	case 4888ULL: goto x86_l_1318;
	case 4890ULL: goto x86_l_131a;
	case 4893ULL: goto x86_l_131d;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4905ULL: goto x86_l_1329;
	case 4909ULL: goto x86_l_132d;
	case 4911ULL: goto x86_l_132f;
	case 4915ULL: goto x86_l_1333;
	case 4917ULL: goto x86_l_1335;
	case 4923ULL: goto x86_l_133b;
	case 4928ULL: goto x86_l_1340;
	case 4930ULL: goto x86_l_1342;
	case 4934ULL: goto x86_l_1346;
	case 4936ULL: goto x86_l_1348;
	case 4944ULL: goto x86_l_1350;
	case 4948ULL: goto x86_l_1354;
	case 4951ULL: goto x86_l_1357;
	case 4954ULL: goto x86_l_135a;
	case 4961ULL: goto x86_l_1361;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4992ULL: goto x86_l_1380;
	case 5000ULL: goto x86_l_1388;
	case 5005ULL: goto x86_l_138d;
	case 5010ULL: goto x86_l_1392;
	case 5015ULL: goto x86_l_1397;
	case 5022ULL: goto x86_l_139e;
	case 5030ULL: goto x86_l_13a6;
	case 5035ULL: goto x86_l_13ab;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d8c:
	/* 0xd8c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d8f:
	/* 0xd8f: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_d95:
	/* 0xd95: je     159c <tail_handle_ipv4+0x159c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5532ULL;
	}
x86_l_d9b:
	/* 0xd9b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d9e:
	/* 0xd9e: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_da3:
	/* 0xda3: movzx  ebp,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_da7:
	/* 0xda7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dac:
	/* 0xdac: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db1:
	/* 0xdb1: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_db9:
	/* 0xdb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbb:
	/* 0xdbb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dbe:
	/* 0xdbe: mov    WORD PTR [rsp+0x2],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_dc3:
	/* 0xdc3: je     dd0 <tail_handle_ipv4+0xdd0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd0;
	}
x86_l_dc5:
	/* 0xdc5: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_dc8:
	/* 0xdc8: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dcc:
	/* 0xdcc: mov    WORD PTR [rax+0x26],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_dd0:
	/* 0xdd0: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dd5:
	/* 0xdd5: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_dd8:
	/* 0xdd8: jmp    1700 <tail_handle_ipv4+0x1700> */
	return 5888ULL;
x86_l_ddd:
	/* 0xddd: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_de3:
	/* 0xde3: movzx  edx,BYTE PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 2ULL);
x86_l_de8:
	/* 0xde8: cmp    dl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 6ULL);
x86_l_deb:
	/* 0xdeb: jne    e22 <tail_handle_ipv4+0xe22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e22;
	}
x86_l_ded:
	/* 0xded: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_def:
	/* 0xdef: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_df1:
	/* 0xdf1: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_df4:
	/* 0xdf4: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_df7:
	/* 0xdf7: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_df9:
	/* 0xdf9: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dfd:
	/* 0xdfd: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_dff:
	/* 0xdff: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_e04:
	/* 0xe04: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_e0a:
	/* 0xe0a: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_e0e:
	/* 0xe0e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e11:
	/* 0xe11: je     e22 <tail_handle_ipv4+0xe22> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e22;
	}
x86_l_e13:
	/* 0xe13: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_e1a:
	/* 0xe1a: imul   r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_e1e:
	/* 0xe1e: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e22:
	/* 0xe22: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e27:
	/* 0xe27: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_e2a:
	/* 0xe2a: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e2e:
	/* 0xe2e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e31:
	/* 0xe31: je     e42 <tail_handle_ipv4+0xe42> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e42;
	}
x86_l_e33:
	/* 0xe33: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_e38:
	/* 0xe38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e3a:
	/* 0xe3a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e3c:
	/* 0xe3c: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_e40:
	/* 0xe40: jmp    e65 <tail_handle_ipv4+0xe65> */
	goto x86_l_e65;
x86_l_e42:
	/* 0xe42: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_e47:
	/* 0xe47: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e49:
	/* 0xe49: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e4b:
	/* 0xe4b: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_e4f:
	/* 0xe4f: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_e59:
	/* 0xe59: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e5c:
	/* 0xe5c: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e61:
	/* 0xe61: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_e65:
	/* 0xe65: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e68:
	/* 0xe68: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6d:
	/* 0xe6d: mov    DWORD PTR [rcx+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e71:
	/* 0xe71: movzx  edx,BYTE PTR [rcx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_e75:
	/* 0xe75: mov    esi,DWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e78:
	/* 0xe78: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_e7c:
	/* 0xe7c: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_e83:
	/* 0xe83: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e86:
	/* 0xe86: je     e99 <tail_handle_ipv4+0xe99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e99;
	}
x86_l_e88:
	/* 0xe88: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_e8f:
	/* 0xe8f: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e91:
	/* 0xe91: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_e94:
	/* 0xe94: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e97:
	/* 0xe97: jmp    e9e <tail_handle_ipv4+0xe9e> */
	goto x86_l_e9e;
x86_l_e99:
	/* 0xe99: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_e9e:
	/* 0xe9e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ea0:
	/* 0xea0: or     r14b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_ea3:
	/* 0xea3: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_ea5:
	/* 0xea5: jb     eac <tail_handle_ipv4+0xeac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_eac;
	}
x86_l_ea7:
	/* 0xea7: cmp    dl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_8);
x86_l_eaa:
	/* 0xeaa: je     ebc <tail_handle_ipv4+0xebc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebc;
	}
x86_l_eac:
	/* 0xeac: mov    BYTE PTR [rcx+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_eb0:
	/* 0xeb0: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eb3:
	/* 0xeb3: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_eba:
	/* 0xeba: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebc:
	/* 0xebc: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_ec3:
	/* 0xec3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec6:
	/* 0xec6: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_ecb:
	/* 0xecb: je     eda <tail_handle_ipv4+0xeda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eda;
	}
x86_l_ecd:
	/* 0xecd: inc QWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_ed2:
	/* 0xed2: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ed5:
	/* 0xed5: add QWORD PTR [rcx+0x18],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_eda:
	/* 0xeda: mov    edx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ede:
	/* 0xede: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_ee1:
	/* 0xee1: je     f32 <tail_handle_ipv4+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f32;
	}
x86_l_ee3:
	/* 0xee3: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_ee6:
	/* 0xee6: jne    1020 <tail_handle_ipv4+0x1020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1020;
	}
x86_l_eec:
	/* 0xeec: movzx  edx,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_ef0:
	/* 0xef0: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_ef3:
	/* 0xef3: je     1020 <tail_handle_ipv4+0x1020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1020;
	}
x86_l_ef9:
	/* 0xef9: mov    WORD PTR [rcx+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_eff:
	/* 0xeff: and    edx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_f05:
	/* 0xf05: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_f08:
	/* 0xf08: mov    WORD PTR [rcx+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f0c:
	/* 0xf0c: mov    r13,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f13:
	/* 0xf13: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f18:
	/* 0xf18: je     2603 <tail_handle_ipv4+0x2603> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9731ULL;
	}
x86_l_f1e:
	/* 0xf1e: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f25:
	/* 0xf25: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_f29:
	/* 0xf29: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f2d:
	/* 0xf2d: jmp    2609 <tail_handle_ipv4+0x2609> */
	return 9737ULL;
x86_l_f32:
	/* 0xf32: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_f34:
	/* 0xf34: and    edx,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_f3a:
	/* 0xf3a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_f3d:
	/* 0xf3d: mov    dx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 3ULL);
x86_l_f41:
	/* 0xf41: sbb    dx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_f45:
	/* 0xf45: or     dx,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_f49:
	/* 0xf49: mov    WORD PTR [rcx+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f4d:
	/* 0xf4d: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_f54:
	/* 0xf54: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f56:
	/* 0xf56: test   dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_f59:
	/* 0xf59: je     1020 <tail_handle_ipv4+0x1020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1020;
	}
x86_l_f5f:
	/* 0xf5f: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_f62:
	/* 0xf62: mov    rdx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f69:
	/* 0xf69: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6c:
	/* 0xf6c: je     f81 <tail_handle_ipv4+0xf81> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f81;
	}
x86_l_f6e:
	/* 0xf6e: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f75:
	/* 0xf75: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f77:
	/* 0xf77: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f79:
	/* 0xf79: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_f7c:
	/* 0xf7c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f7f:
	/* 0xf7f: jmp    f86 <tail_handle_ipv4+0xf86> */
	goto x86_l_f86;
x86_l_f81:
	/* 0xf81: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_f86:
	/* 0xf86: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_f89:
	/* 0xf89: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f8d:
	/* 0xf8d: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f90:
	/* 0xf90: je     fa4 <tail_handle_ipv4+0xfa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fa4;
	}
x86_l_f92:
	/* 0xf92: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_f97:
	/* 0xf97: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f99:
	/* 0xf99: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f9b:
	/* 0xf9b: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f9e:
	/* 0xf9e: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_fa2:
	/* 0xfa2: jmp    fc7 <tail_handle_ipv4+0xfc7> */
	goto x86_l_fc7;
x86_l_fa4:
	/* 0xfa4: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_fa9:
	/* 0xfa9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fab:
	/* 0xfab: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fad:
	/* 0xfad: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_fb1:
	/* 0xfb1: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_fbb:
	/* 0xfbb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fbe:
	/* 0xfbe: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_fc3:
	/* 0xfc3: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_fc7:
	/* 0xfc7: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fc9:
	/* 0xfc9: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fcd:
	/* 0xfcd: movzx  edx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_fd2:
	/* 0xfd2: mov    esi,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd6:
	/* 0xfd6: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_fda:
	/* 0xfda: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_fe1:
	/* 0xfe1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe4:
	/* 0xfe4: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_fe9:
	/* 0xfe9: je     ffc <tail_handle_ipv4+0xffc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ffc;
	}
x86_l_feb:
	/* 0xfeb: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ff2:
	/* 0xff2: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff4:
	/* 0xff4: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_ff7:
	/* 0xff7: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ffa:
	/* 0xffa: jmp    1001 <tail_handle_ipv4+0x1001> */
	goto x86_l_1001;
x86_l_ffc:
	/* 0xffc: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1001:
	/* 0x1001: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1003:
	/* 0x1003: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1006:
	/* 0x1006: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_1008:
	/* 0x1008: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_100f:
	/* 0x100f: jb     1016 <tail_handle_ipv4+0x1016> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1016;
	}
x86_l_1011:
	/* 0x1011: cmp    dl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_8);
x86_l_1014:
	/* 0x1014: je     1020 <tail_handle_ipv4+0x1020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1020;
	}
x86_l_1016:
	/* 0x1016: mov    BYTE PTR [r14+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_101a:
	/* 0x101a: mov    DWORD PTR [r14+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_101e:
	/* 0x101e: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1020:
	/* 0x1020: movzx  ecx,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1025:
	/* 0x1025: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1028:
	/* 0x1028: je     1df4 <tail_handle_ipv4+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7668ULL;
	}
x86_l_102e:
	/* 0x102e: mov    bpl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1031:
	/* 0x1031: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_1036:
	/* 0x1036: jne    1df4 <tail_handle_ipv4+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7668ULL;
	}
x86_l_103c:
	/* 0x103c: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1040:
	/* 0x1040: jne    104b <tail_handle_ipv4+0x104b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_104b;
	}
x86_l_1042:
	/* 0x1042: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1049:
	/* 0x1049: jmp    1052 <tail_handle_ipv4+0x1052> */
	goto x86_l_1052;
x86_l_104b:
	/* 0x104b: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1052:
	/* 0x1052: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1057:
	/* 0x1057: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1060:
	/* 0x1060: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1069:
	/* 0x1069: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1072:
	/* 0x1072: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_107b:
	/* 0x107b: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1084:
	/* 0x1084: mov    DWORD PTR [rsp+0x6c],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467970ULL);
x86_l_108c:
	/* 0x108c: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1094:
	/* 0x1094: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1098:
	/* 0x1098: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_109d:
	/* 0x109d: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_10a6:
	/* 0x10a6: mov    WORD PTR [rsp+0x68],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10ab:
	/* 0x10ab: mov    WORD PTR [rsp+0x64],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729728ULL);
x86_l_10b2:
	/* 0x10b2: mov    r15,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_10b9:
	/* 0x10b9: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10bd:
	/* 0x10bd: je     10d0 <tail_handle_ipv4+0x10d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10d0;
	}
x86_l_10bf:
	/* 0x10bf: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_10c6:
	/* 0x10c6: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_10ca:
	/* 0x10ca: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_10ce:
	/* 0x10ce: jmp    10d6 <tail_handle_ipv4+0x10d6> */
	goto x86_l_10d6;
x86_l_10d0:
	/* 0x10d0: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_10d6:
	/* 0x10d6: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_10da:
	/* 0x10da: jne    1100 <tail_handle_ipv4+0x1100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1100;
	}
x86_l_10dc:
	/* 0x10dc: mov    WORD PTR [rsp+0x64],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729728ULL);
x86_l_10e3:
	/* 0x10e3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e7:
	/* 0x10e7: je     10fa <tail_handle_ipv4+0x10fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10fa;
	}
x86_l_10e9:
	/* 0x10e9: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_10f0:
	/* 0x10f0: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_10f4:
	/* 0x10f4: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_10f8:
	/* 0x10f8: jmp    1100 <tail_handle_ipv4+0x1100> */
	goto x86_l_1100;
x86_l_10fa:
	/* 0x10fa: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1100:
	/* 0x1100: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1104:
	/* 0x1104: je     1115 <tail_handle_ipv4+0x1115> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1115;
	}
x86_l_1106:
	/* 0x1106: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_110b:
	/* 0x110b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110d:
	/* 0x110d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_110f:
	/* 0x110f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1113:
	/* 0x1113: jmp    1138 <tail_handle_ipv4+0x1138> */
	goto x86_l_1138;
x86_l_1115:
	/* 0x1115: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_111a:
	/* 0x111a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111c:
	/* 0x111c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_111e:
	/* 0x111e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1122:
	/* 0x1122: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_112c:
	/* 0x112c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1134:
	/* 0x1134: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1138:
	/* 0x1138: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_113c:
	/* 0x113c: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_113f:
	/* 0x113f: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1142:
	/* 0x1142: mov    DWORD PTR [rsp+0x60],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1147:
	/* 0x1147: movzx  edx,BYTE PTR [rsp+0x6a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 106ULL);
x86_l_114c:
	/* 0x114c: mov    esi,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1150:
	/* 0x1150: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1152:
	/* 0x1152: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1156:
	/* 0x1156: je     116b <tail_handle_ipv4+0x116b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_116b;
	}
x86_l_1158:
	/* 0x1158: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_115f:
	/* 0x115f: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1161:
	/* 0x1161: lea    r8d,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1165:
	/* 0x1165: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1169:
	/* 0x1169: jmp    1171 <tail_handle_ipv4+0x1171> */
	goto x86_l_1171;
x86_l_116b:
	/* 0x116b: mov    r8d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5ULL);
x86_l_1171:
	/* 0x1171: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1176:
	/* 0x1176: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1179:
	/* 0x1179: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_117b:
	/* 0x117b: cmp    r8d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_117e:
	/* 0x117e: jb     1184 <tail_handle_ipv4+0x1184> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1184;
	}
x86_l_1180:
	/* 0x1180: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_1182:
	/* 0x1182: je     1195 <tail_handle_ipv4+0x1195> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1195;
	}
x86_l_1184:
	/* 0x1184: mov    BYTE PTR [rsp+0x6a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_1188:
	/* 0x1188: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_118c:
	/* 0x118c: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1193:
	/* 0x1193: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1195:
	/* 0x1195: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_119c:
	/* 0x119c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119f:
	/* 0x119f: je     11b2 <tail_handle_ipv4+0x11b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11b2;
	}
x86_l_11a1:
	/* 0x11a1: mov    QWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_11aa:
	/* 0x11aa: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11ad:
	/* 0x11ad: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11b2:
	/* 0x11b2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11b7:
	/* 0x11b7: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11bc:
	/* 0x11bc: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11c1:
	/* 0x11c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11c3:
	/* 0x11c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c5:
	/* 0x11c5: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_11c8:
	/* 0x11c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11ca:
	/* 0x11ca: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_11cf:
	/* 0x11cf: jns    1df4 <tail_handle_ipv4+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 7668ULL;
	}
x86_l_11d5:
	/* 0x11d5: mov    ecx,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967141ULL);
x86_l_11da:
	/* 0x11da: jmp    82f <tail_handle_ipv4+0x82f> */
	return 2095ULL;
x86_l_11df:
	/* 0x11df: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_11e2:
	/* 0x11e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e7:
	/* 0x11e7: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_11ee:
	/* 0x11ee: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_11f3:
	/* 0x11f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f5:
	/* 0x11f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11f8:
	/* 0x11f8: je     120f <tail_handle_ipv4+0x120f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_120f;
	}
x86_l_11fa:
	/* 0x11fa: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fc:
	/* 0x11fc: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1200:
	/* 0x1200: jmp    248 <tail_handle_ipv4+0x248> */
	return 584ULL;
x86_l_1205:
	/* 0x1205: mov    ecx,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967139ULL);
x86_l_120a:
	/* 0x120a: jmp    387 <tail_handle_ipv4+0x387> */
	return 903ULL;
x86_l_120f:
	/* 0x120f: mov    ecx,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967121ULL);
x86_l_1214:
	/* 0x1214: jmp    37d <tail_handle_ipv4+0x37d> */
	return 893ULL;
x86_l_1219:
	/* 0x1219: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_121c:
	/* 0x121c: jmp    82f <tail_handle_ipv4+0x82f> */
	return 2095ULL;
x86_l_1221:
	/* 0x1221: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_122a:
	/* 0x122a: mov    QWORD PTR [rsp+0x48],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_122f:
	/* 0x122f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1234:
	/* 0x1234: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_123b:
	/* 0x123b: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1243:
	/* 0x1243: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1248:
	/* 0x1248: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124a:
	/* 0x124a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_124c:
	/* 0x124c: jmp    248 <tail_handle_ipv4+0x248> */
	return 584ULL;
x86_l_1251:
	/* 0x1251: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1257:
	/* 0x1257: jmp    5b4 <tail_handle_ipv4+0x5b4> */
	return 1460ULL;
x86_l_125c:
	/* 0x125c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1261:
	/* 0x1261: jmp    954 <tail_handle_ipv4+0x954> */
	return 2388ULL;
x86_l_1266:
	/* 0x1266: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_126b:
	/* 0x126b: cmp    BYTE PTR [rsp+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_1270:
	/* 0x1270: jne    12ae <tail_handle_ipv4+0x12ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12ae;
	}
x86_l_1272:
	/* 0x1272: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1276:
	/* 0x1276: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1278:
	/* 0x1278: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_127b:
	/* 0x127b: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_127e:
	/* 0x127e: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1280:
	/* 0x1280: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1288:
	/* 0x1288: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_128c:
	/* 0x128c: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_128e:
	/* 0x128e: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1293:
	/* 0x1293: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1298:
	/* 0x1298: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_129b:
	/* 0x129b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129f:
	/* 0x129f: je     12ae <tail_handle_ipv4+0x12ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ae;
	}
x86_l_12a1:
	/* 0x12a1: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_12a8:
	/* 0x12a8: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_12ab:
	/* 0x12ab: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12ae:
	/* 0x12ae: shr    DWORD PTR [rsp+0x4],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 17179869192ULL);
x86_l_12b3:
	/* 0x12b3: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b7:
	/* 0x12b7: je     12c8 <tail_handle_ipv4+0x12c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c8;
	}
x86_l_12b9:
	/* 0x12b9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_12be:
	/* 0x12be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c0:
	/* 0x12c0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12c2:
	/* 0x12c2: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_12c6:
	/* 0x12c6: jmp    12eb <tail_handle_ipv4+0x12eb> */
	goto x86_l_12eb;
x86_l_12c8:
	/* 0x12c8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_12cd:
	/* 0x12cd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12cf:
	/* 0x12cf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12d1:
	/* 0x12d1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_12d5:
	/* 0x12d5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_12df:
	/* 0x12df: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_12e2:
	/* 0x12e2: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_12e7:
	/* 0x12e7: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_12eb:
	/* 0x12eb: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12ed:
	/* 0x12ed: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12f5:
	/* 0x12f5: mov    DWORD PTR [rdx+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f8:
	/* 0x12f8: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_12fc:
	/* 0x12fc: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ff:
	/* 0x12ff: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1303:
	/* 0x1303: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1307:
	/* 0x1307: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_130b:
	/* 0x130b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130f:
	/* 0x130f: je     1322 <tail_handle_ipv4+0x1322> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1322;
	}
x86_l_1311:
	/* 0x1311: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1318:
	/* 0x1318: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131a:
	/* 0x131a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_131d:
	/* 0x131d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1320:
	/* 0x1320: jmp    1327 <tail_handle_ipv4+0x1327> */
	goto x86_l_1327;
x86_l_1322:
	/* 0x1322: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1327:
	/* 0x1327: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1329:
	/* 0x1329: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_132d:
	/* 0x132d: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_132f:
	/* 0x132f: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1333:
	/* 0x1333: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1335:
	/* 0x1335: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_133b:
	/* 0x133b: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1340:
	/* 0x1340: jb     1348 <tail_handle_ipv4+0x1348> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1348;
	}
x86_l_1342:
	/* 0x1342: cmp    cl,BYTE PTR [rsp+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_1346:
	/* 0x1346: je     1363 <tail_handle_ipv4+0x1363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1363;
	}
x86_l_1348:
	/* 0x1348: mov    rcx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1350:
	/* 0x1350: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1354:
	/* 0x1354: mov    BYTE PTR [rcx+0x2a],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1357:
	/* 0x1357: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_135a:
	/* 0x135a: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1361:
	/* 0x1361: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1363:
	/* 0x1363: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1368:
	/* 0x1368: cmp    WORD PTR [rdx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_136d:
	/* 0x136d: je     15ab <tail_handle_ipv4+0x15ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5547ULL;
	}
x86_l_1373:
	/* 0x1373: test   BYTE PTR [rdx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1377:
	/* 0x1377: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_137a:
	/* 0x137a: je     14be <tail_handle_ipv4+0x14be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5310ULL;
	}
x86_l_1380:
	/* 0x1380: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1388:
	/* 0x1388: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_138d:
	/* 0x138d: movzx  eax,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1392:
	/* 0x1392: mov    WORD PTR [rsp+0x48],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1397:
	/* 0x1397: mov    WORD PTR [rsp+0x4a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 317827579904ULL);
x86_l_139e:
	/* 0x139e: mov    DWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_13a6:
	/* 0x13a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ab:
	/* 0x13ab: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_13b2:
	/* 0x13b2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13b7:
	/* 0x13b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 5049ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5049ULL: goto x86_l_13b9;
	case 5052ULL: goto x86_l_13bc;
	case 5058ULL: goto x86_l_13c2;
	case 5061ULL: goto x86_l_13c5;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5074ULL: goto x86_l_13d2;
	case 5079ULL: goto x86_l_13d7;
	case 5081ULL: goto x86_l_13d9;
	case 5083ULL: goto x86_l_13db;
	case 5087ULL: goto x86_l_13df;
	case 5089ULL: goto x86_l_13e1;
	case 5094ULL: goto x86_l_13e6;
	case 5096ULL: goto x86_l_13e8;
	case 5098ULL: goto x86_l_13ea;
	case 5102ULL: goto x86_l_13ee;
	case 5112ULL: goto x86_l_13f8;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5124ULL: goto x86_l_1404;
	case 5127ULL: goto x86_l_1407;
	case 5131ULL: goto x86_l_140b;
	case 5136ULL: goto x86_l_1410;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5152ULL: goto x86_l_1420;
	case 5156ULL: goto x86_l_1424;
	case 5161ULL: goto x86_l_1429;
	case 5163ULL: goto x86_l_142b;
	case 5167ULL: goto x86_l_142f;
	case 5169ULL: goto x86_l_1431;
	case 5176ULL: goto x86_l_1438;
	case 5179ULL: goto x86_l_143b;
	case 5182ULL: goto x86_l_143e;
	case 5184ULL: goto x86_l_1440;
	case 5187ULL: goto x86_l_1443;
	case 5190ULL: goto x86_l_1446;
	case 5193ULL: goto x86_l_1449;
	case 5195ULL: goto x86_l_144b;
	case 5200ULL: goto x86_l_1450;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5214ULL: goto x86_l_145e;
	case 5217ULL: goto x86_l_1461;
	case 5219ULL: goto x86_l_1463;
	case 5223ULL: goto x86_l_1467;
	case 5226ULL: goto x86_l_146a;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5235ULL: goto x86_l_1473;
	case 5239ULL: goto x86_l_1477;
	case 5244ULL: goto x86_l_147c;
	case 5251ULL: goto x86_l_1483;
	case 5256ULL: goto x86_l_1488;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5267ULL: goto x86_l_1493;
	case 5274ULL: goto x86_l_149a;
	case 5277ULL: goto x86_l_149d;
	case 5279ULL: goto x86_l_149f;
	case 5284ULL: goto x86_l_14a4;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5298ULL: goto x86_l_14b2;
	case 5303ULL: goto x86_l_14b7;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5317ULL: goto x86_l_14c5;
	case 5319ULL: goto x86_l_14c7;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5340ULL: goto x86_l_14dc;
	case 5347ULL: goto x86_l_14e3;
	case 5351ULL: goto x86_l_14e7;
	case 5356ULL: goto x86_l_14ec;
	case 5363ULL: goto x86_l_14f3;
	case 5371ULL: goto x86_l_14fb;
	case 5373ULL: goto x86_l_14fd;
	case 5376ULL: goto x86_l_1500;
	case 5378ULL: goto x86_l_1502;
	case 5380ULL: goto x86_l_1504;
	case 5382ULL: goto x86_l_1506;
	case 5386ULL: goto x86_l_150a;
	case 5389ULL: goto x86_l_150d;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5405ULL: goto x86_l_151d;
	case 5410ULL: goto x86_l_1522;
	case 5412ULL: goto x86_l_1524;
	case 5415ULL: goto x86_l_1527;
	case 5417ULL: goto x86_l_1529;
	case 5422ULL: goto x86_l_152e;
	case 5424ULL: goto x86_l_1530;
	case 5433ULL: goto x86_l_1539;
	case 5442ULL: goto x86_l_1542;
	case 5451ULL: goto x86_l_154b;
	case 5460ULL: goto x86_l_1554;
	case 5469ULL: goto x86_l_155d;
	case 5478ULL: goto x86_l_1566;
	case 5483ULL: goto x86_l_156b;
	case 5488ULL: goto x86_l_1570;
	case 5493ULL: goto x86_l_1575;
	case 5496ULL: goto x86_l_1578;
	case 5498ULL: goto x86_l_157a;
	case 5503ULL: goto x86_l_157f;
	case 5510ULL: goto x86_l_1586;
	case 5513ULL: goto x86_l_1589;
	case 5515ULL: goto x86_l_158b;
	case 5522ULL: goto x86_l_1592;
	case 5526ULL: goto x86_l_1596;
	case 5530ULL: goto x86_l_159a;
	case 5532ULL: goto x86_l_159c;
	case 5539ULL: goto x86_l_15a3;
	case 5542ULL: goto x86_l_15a6;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5556ULL: goto x86_l_15b4;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5571ULL: goto x86_l_15c3;
	case 5573ULL: goto x86_l_15c5;
	case 5578ULL: goto x86_l_15ca;
	case 5585ULL: goto x86_l_15d1;
	case 5591ULL: goto x86_l_15d7;
	case 5594ULL: goto x86_l_15da;
	case 5599ULL: goto x86_l_15df;
	case 5601ULL: goto x86_l_15e1;
	case 5606ULL: goto x86_l_15e6;
	case 5611ULL: goto x86_l_15eb;
	case 5617ULL: goto x86_l_15f1;
	case 5621ULL: goto x86_l_15f5;
	case 5623ULL: goto x86_l_15f7;
	case 5626ULL: goto x86_l_15fa;
	case 5628ULL: goto x86_l_15fc;
	case 5635ULL: goto x86_l_1603;
	case 5639ULL: goto x86_l_1607;
	case 5643ULL: goto x86_l_160b;
	case 5645ULL: goto x86_l_160d;
	case 5649ULL: goto x86_l_1611;
	case 5651ULL: goto x86_l_1613;
	case 5657ULL: goto x86_l_1619;
	case 5659ULL: goto x86_l_161b;
	case 5664ULL: goto x86_l_1620;
	case 5670ULL: goto x86_l_1626;
	case 5673ULL: goto x86_l_1629;
	case 5675ULL: goto x86_l_162b;
	case 5680ULL: goto x86_l_1630;
	case 5682ULL: goto x86_l_1632;
	case 5684ULL: goto x86_l_1634;
	case 5688ULL: goto x86_l_1638;
	case 5690ULL: goto x86_l_163a;
	case 5695ULL: goto x86_l_163f;
	case 5697ULL: goto x86_l_1641;
	case 5699ULL: goto x86_l_1643;
	case 5703ULL: goto x86_l_1647;
	case 5713ULL: goto x86_l_1651;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5725ULL: goto x86_l_165d;
	case 5729ULL: goto x86_l_1661;
	case 5732ULL: goto x86_l_1664;
	case 5735ULL: goto x86_l_1667;
	case 5740ULL: goto x86_l_166c;
	case 5745ULL: goto x86_l_1671;
	case 5749ULL: goto x86_l_1675;
	case 5751ULL: goto x86_l_1677;
	case 5758ULL: goto x86_l_167e;
	case 5761ULL: goto x86_l_1681;
	case 5763ULL: goto x86_l_1683;
	case 5770ULL: goto x86_l_168a;
	case 5772ULL: goto x86_l_168c;
	case 5775ULL: goto x86_l_168f;
	case 5778ULL: goto x86_l_1692;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5790ULL: goto x86_l_169e;
	case 5792ULL: goto x86_l_16a0;
	case 5794ULL: goto x86_l_16a2;
	case 5796ULL: goto x86_l_16a4;
	case 5798ULL: goto x86_l_16a6;
	case 5800ULL: goto x86_l_16a8;
	case 5802ULL: goto x86_l_16aa;
	case 5806ULL: goto x86_l_16ae;
	case 5810ULL: goto x86_l_16b2;
	case 5817ULL: goto x86_l_16b9;
	case 5819ULL: goto x86_l_16bb;
	case 5826ULL: goto x86_l_16c2;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5840ULL: goto x86_l_16d0;
	case 5843ULL: goto x86_l_16d3;
	case 5848ULL: goto x86_l_16d8;
	case 5853ULL: goto x86_l_16dd;
	case 5858ULL: goto x86_l_16e2;
	case 5863ULL: goto x86_l_16e7;
	case 5871ULL: goto x86_l_16ef;
	case 5873ULL: goto x86_l_16f1;
	case 5875ULL: goto x86_l_16f3;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5888ULL: goto x86_l_1700;
	case 5893ULL: goto x86_l_1705;
	case 5897ULL: goto x86_l_1709;
	case 5901ULL: goto x86_l_170d;
	case 5904ULL: goto x86_l_1710;
	case 5910ULL: goto x86_l_1716;
	case 5917ULL: goto x86_l_171d;
	case 5920ULL: goto x86_l_1720;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5929ULL: goto x86_l_1729;
	case 5931ULL: goto x86_l_172b;
	case 5935ULL: goto x86_l_172f;
	case 5937ULL: goto x86_l_1731;
	case 5942ULL: goto x86_l_1736;
	case 5944ULL: goto x86_l_1738;
	case 5946ULL: goto x86_l_173a;
	case 5950ULL: goto x86_l_173e;
	case 5960ULL: goto x86_l_1748;
	case 5963ULL: goto x86_l_174b;
	case 5968ULL: goto x86_l_1750;
	case 5972ULL: goto x86_l_1754;
	case 5980ULL: goto x86_l_175c;
	case 5985ULL: goto x86_l_1761;
	case 5990ULL: goto x86_l_1766;
	case 5995ULL: goto x86_l_176b;
	case 6000ULL: goto x86_l_1770;
	case 6007ULL: goto x86_l_1777;
	case 6015ULL: goto x86_l_177f;
	case 6017ULL: goto x86_l_1781;
	case 6022ULL: goto x86_l_1786;
	case 6030ULL: goto x86_l_178e;
	case 6041ULL: goto x86_l_1799;
	case 6046ULL: goto x86_l_179e;
	case 6053ULL: goto x86_l_17a5;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6065ULL: goto x86_l_17b1;
	case 6067ULL: goto x86_l_17b3;
	case 6070ULL: goto x86_l_17b6;
	case 6079ULL: goto x86_l_17bf;
	case 6087ULL: goto x86_l_17c7;
	case 6096ULL: goto x86_l_17d0;
	case 6100ULL: goto x86_l_17d4;
	case 6105ULL: goto x86_l_17d9;
	case 6110ULL: goto x86_l_17de;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6124ULL: goto x86_l_17ec;
	case 6129ULL: goto x86_l_17f1;
	case 6132ULL: goto x86_l_17f4;
	case 6134ULL: goto x86_l_17f6;
	case 6137ULL: goto x86_l_17f9;
	case 6147ULL: goto x86_l_1803;
	case 6152ULL: goto x86_l_1808;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6159ULL: goto x86_l_180f;
	case 6164ULL: goto x86_l_1814;
	case 6167ULL: goto x86_l_1817;
	case 6172ULL: goto x86_l_181c;
	case 6176ULL: goto x86_l_1820;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6192ULL: goto x86_l_1830;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6213ULL: goto x86_l_1845;
	case 6219ULL: goto x86_l_184b;
	case 6222ULL: goto x86_l_184e;
	case 6226ULL: goto x86_l_1852;
	case 6231ULL: goto x86_l_1857;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6255ULL: goto x86_l_186f;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6265ULL: goto x86_l_1879;
	case 6273ULL: goto x86_l_1881;
	case 6279ULL: goto x86_l_1887;
	case 6282ULL: goto x86_l_188a;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6300ULL: goto x86_l_189c;
	case 6305ULL: goto x86_l_18a1;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6321ULL: goto x86_l_18b1;
	case 6326ULL: goto x86_l_18b6;
	case 6329ULL: goto x86_l_18b9;
	case 6331ULL: goto x86_l_18bb;
	case 6336ULL: goto x86_l_18c0;
	case 6338ULL: goto x86_l_18c2;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6349ULL: goto x86_l_18cd;
	case 6352ULL: goto x86_l_18d0;
	case 6357ULL: goto x86_l_18d5;
	case 6360ULL: goto x86_l_18d8;
	case 6365ULL: goto x86_l_18dd;
	case 6367ULL: goto x86_l_18df;
	case 6369ULL: goto x86_l_18e1;
	case 6372ULL: goto x86_l_18e4;
	case 6374ULL: goto x86_l_18e6;
	case 6376ULL: goto x86_l_18e8;
	case 6378ULL: goto x86_l_18ea;
	case 6381ULL: goto x86_l_18ed;
	case 6383ULL: goto x86_l_18ef;
	case 6393ULL: goto x86_l_18f9;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6409ULL: goto x86_l_1909;
	case 6415ULL: goto x86_l_190f;
	case 6420ULL: goto x86_l_1914;
	case 6425ULL: goto x86_l_1919;
	case 6428ULL: goto x86_l_191c;
	case 6434ULL: goto x86_l_1922;
	case 6437ULL: goto x86_l_1925;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6460ULL: goto x86_l_193c;
	case 6465ULL: goto x86_l_1941;
	case 6470ULL: goto x86_l_1946;
	case 6473ULL: goto x86_l_1949;
	case 6476ULL: goto x86_l_194c;
	case 6478ULL: goto x86_l_194e;
	case 6480ULL: goto x86_l_1950;
	case 6486ULL: goto x86_l_1956;
	case 6491ULL: goto x86_l_195b;
	case 6499ULL: goto x86_l_1963;
	case 6504ULL: goto x86_l_1968;
	case 6507ULL: goto x86_l_196b;
	case 6515ULL: goto x86_l_1973;
	case 6519ULL: goto x86_l_1977;
	case 6524ULL: goto x86_l_197c;
	case 6527ULL: goto x86_l_197f;
	case 6529ULL: goto x86_l_1981;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6535ULL: goto x86_l_1987;
	case 6538ULL: goto x86_l_198a;
	case 6544ULL: goto x86_l_1990;
	case 6554ULL: goto x86_l_199a;
	case 6559ULL: goto x86_l_199f;
	case 6562ULL: goto x86_l_19a2;
	case 6568ULL: goto x86_l_19a8;
	case 6570ULL: goto x86_l_19aa;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6589ULL: goto x86_l_19bd;
	case 6593ULL: goto x86_l_19c1;
	case 6596ULL: goto x86_l_19c4;
	case 6602ULL: goto x86_l_19ca;
	case 6607ULL: goto x86_l_19cf;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6637ULL: goto x86_l_19ed;
	case 6640ULL: goto x86_l_19f0;
	case 6645ULL: goto x86_l_19f5;
	case 6648ULL: goto x86_l_19f8;
	case 6651ULL: goto x86_l_19fb;
	case 6653ULL: goto x86_l_19fd;
	case 6655ULL: goto x86_l_19ff;
	case 6661ULL: goto x86_l_1a05;
	case 6666ULL: goto x86_l_1a0a;
	case 6670ULL: goto x86_l_1a0e;
	case 6675ULL: goto x86_l_1a13;
	case 6677ULL: goto x86_l_1a15;
	case 6685ULL: goto x86_l_1a1d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13b9:
	/* 0x13b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13bc:
	/* 0x13bc: je     14b9 <tail_handle_ipv4+0x14b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14b9;
	}
x86_l_13c2:
	/* 0x13c2: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_13c5:
	/* 0x13c5: mov    r14,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_13cc:
	/* 0x13cc: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13d0:
	/* 0x13d0: je     13e1 <tail_handle_ipv4+0x13e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13e1;
	}
x86_l_13d2:
	/* 0x13d2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_13d7:
	/* 0x13d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d9:
	/* 0x13d9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13db:
	/* 0x13db: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_13df:
	/* 0x13df: jmp    1404 <tail_handle_ipv4+0x1404> */
	goto x86_l_1404;
x86_l_13e1:
	/* 0x13e1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_13e6:
	/* 0x13e6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e8:
	/* 0x13e8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13ea:
	/* 0x13ea: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_13ee:
	/* 0x13ee: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_13f8:
	/* 0x13f8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_13fb:
	/* 0x13fb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1400:
	/* 0x1400: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1404:
	/* 0x1404: mov    ecx,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1407:
	/* 0x1407: mov    DWORD PTR [rsp+0x78],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_140b:
	/* 0x140b: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1410:
	/* 0x1410: movzx  ecx,WORD PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1414:
	/* 0x1414: mov    WORD PTR [rsp+0x7c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1419:
	/* 0x1419: mov    WORD PTR [rsp+0x7e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_1420:
	/* 0x1420: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1424:
	/* 0x1424: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_1429:
	/* 0x1429: and    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_142b:
	/* 0x142b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_142f:
	/* 0x142f: je     143e <tail_handle_ipv4+0x143e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_143e;
	}
x86_l_1431:
	/* 0x1431: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1438:
	/* 0x1438: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_143b:
	/* 0x143b: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_143e:
	/* 0x143e: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1440:
	/* 0x1440: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1443:
	/* 0x1443: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1446:
	/* 0x1446: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1449:
	/* 0x1449: jbe    149f <tail_handle_ipv4+0x149f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_149f;
	}
x86_l_144b:
	/* 0x144b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1450:
	/* 0x1450: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_1457:
	/* 0x1457: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_145c:
	/* 0x145c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145e:
	/* 0x145e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1461:
	/* 0x1461: je     14a6 <tail_handle_ipv4+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a6;
	}
x86_l_1463:
	/* 0x1463: mov    QWORD PTR [rbp+0x0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1467:
	/* 0x1467: mov    ebp,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_146a:
	/* 0x146a: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_146c:
	/* 0x146c: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1471:
	/* 0x1471: je     14be <tail_handle_ipv4+0x14be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14be;
	}
x86_l_1473:
	/* 0x1473: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1477:
	/* 0x1477: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147c:
	/* 0x147c: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_1483:
	/* 0x1483: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1488:
	/* 0x1488: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148a:
	/* 0x148a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_148d:
	/* 0x148d: jne    1529 <tail_handle_ipv4+0x1529> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1529;
	}
x86_l_1493:
	/* 0x1493: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_149a:
	/* 0x149a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_149d:
	/* 0x149d: jmp    14b9 <tail_handle_ipv4+0x14b9> */
	goto x86_l_14b9;
x86_l_149f:
	/* 0x149f: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14a4:
	/* 0x14a4: jmp    14ab <tail_handle_ipv4+0x14ab> */
	goto x86_l_14ab;
x86_l_14a6:
	/* 0x14a6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_14ab:
	/* 0x14ab: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_14b2:
	/* 0x14b2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14b7:
	/* 0x14b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b9:
	/* 0x14b9: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14be:
	/* 0x14be: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_14c3:
	/* 0x14c3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c5:
	/* 0x14c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c7:
	/* 0x14c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14c9:
	/* 0x14c9: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_14ce:
	/* 0x14ce: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d0:
	/* 0x14d0: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_14d2:
	/* 0x14d2: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_14d4:
	/* 0x14d4: mov    WORD PTR [rsp+0x8e],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 142ULL);
x86_l_14dc:
	/* 0x14dc: mov    r14,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_14e3:
	/* 0x14e3: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14e7:
	/* 0x14e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ec:
	/* 0x14ec: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_14f3:
	/* 0x14f3: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_14fb:
	/* 0x14fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fd:
	/* 0x14fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1500:
	/* 0x1500: je     1506 <tail_handle_ipv4+0x1506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1506;
	}
x86_l_1502:
	/* 0x1502: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1504:
	/* 0x1504: jmp    150a <tail_handle_ipv4+0x150a> */
	goto x86_l_150a;
x86_l_1506:
	/* 0x1506: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_150a:
	/* 0x150a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150d:
	/* 0x150d: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1511:
	/* 0x1511: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1516:
	/* 0x1516: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_151d:
	/* 0x151d: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1522:
	/* 0x1522: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1524:
	/* 0x1524: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1527:
	/* 0x1527: je     159c <tail_handle_ipv4+0x159c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_159c;
	}
x86_l_1529:
	/* 0x1529: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_152e:
	/* 0x152e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1530:
	/* 0x1530: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1539:
	/* 0x1539: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1542:
	/* 0x1542: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_154b:
	/* 0x154b: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1554:
	/* 0x1554: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_155d:
	/* 0x155d: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1566:
	/* 0x1566: movzx  ebp,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_156b:
	/* 0x156b: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1570:
	/* 0x1570: mov    WORD PTR [rsp+0x66],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_1575:
	/* 0x1575: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_1578:
	/* 0x1578: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_157a:
	/* 0x157a: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_157f:
	/* 0x157f: mov    rcx,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1586:
	/* 0x1586: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1589:
	/* 0x1589: je     15eb <tail_handle_ipv4+0x15eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15eb;
	}
x86_l_158b:
	/* 0x158b: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1592:
	/* 0x1592: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1596:
	/* 0x1596: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_159a:
	/* 0x159a: jmp    15f1 <tail_handle_ipv4+0x15f1> */
	goto x86_l_15f1;
x86_l_159c:
	/* 0x159c: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_15a3:
	/* 0x15a3: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15a6:
	/* 0x15a6: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15ab:
	/* 0x15ab: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_15b0:
	/* 0x15b0: mov    BYTE PTR [rsp+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_15b4:
	/* 0x15b4: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_15bb:
	/* 0x15bb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15be:
	/* 0x15be: mov    edi,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967138ULL);
x86_l_15c3:
	/* 0x15c3: je     160d <tail_handle_ipv4+0x160d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_160d;
	}
x86_l_15c5:
	/* 0x15c5: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_15ca:
	/* 0x15ca: mov    rsi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_15d1:
	/* 0x15d1: mov    r14d,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 45ULL);
x86_l_15d7:
	/* 0x15d7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15da:
	/* 0x15da: mov    edx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 45ULL);
x86_l_15df:
	/* 0x15df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e1:
	/* 0x15e1: mov    edi,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967156ULL);
x86_l_15e6:
	/* 0x15e6: jmp    1949 <tail_handle_ipv4+0x1949> */
	goto x86_l_1949;
x86_l_15eb:
	/* 0x15eb: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_15f1:
	/* 0x15f1: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_15f5:
	/* 0x15f5: jne    1626 <tail_handle_ipv4+0x1626> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1626;
	}
x86_l_15f7:
	/* 0x15f7: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15fa:
	/* 0x15fa: je     1620 <tail_handle_ipv4+0x1620> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1620;
	}
x86_l_15fc:
	/* 0x15fc: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1603:
	/* 0x1603: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1607:
	/* 0x1607: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_160b:
	/* 0x160b: jmp    1626 <tail_handle_ipv4+0x1626> */
	goto x86_l_1626;
x86_l_160d:
	/* 0x160d: movzx  eax,BYTE PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1611:
	/* 0x1611: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_1613:
	/* 0x1613: je     1a6a <tail_handle_ipv4+0x1a6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6762ULL;
	}
x86_l_1619:
	/* 0x1619: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_161b:
	/* 0x161b: jmp    1a6e <tail_handle_ipv4+0x1a6e> */
	return 6766ULL;
x86_l_1620:
	/* 0x1620: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1626:
	/* 0x1626: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1629:
	/* 0x1629: je     163a <tail_handle_ipv4+0x163a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_163a;
	}
x86_l_162b:
	/* 0x162b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1630:
	/* 0x1630: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1632:
	/* 0x1632: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1634:
	/* 0x1634: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1638:
	/* 0x1638: jmp    165d <tail_handle_ipv4+0x165d> */
	goto x86_l_165d;
x86_l_163a:
	/* 0x163a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_163f:
	/* 0x163f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1641:
	/* 0x1641: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1643:
	/* 0x1643: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1647:
	/* 0x1647: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1651:
	/* 0x1651: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1654:
	/* 0x1654: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1659:
	/* 0x1659: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_165d:
	/* 0x165d: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1661:
	/* 0x1661: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1664:
	/* 0x1664: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1667:
	/* 0x1667: mov    DWORD PTR [rsp+0x60],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_166c:
	/* 0x166c: movzx  edx,BYTE PTR [rsp+0x6a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 106ULL);
x86_l_1671:
	/* 0x1671: mov    esi,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1675:
	/* 0x1675: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1677:
	/* 0x1677: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_167e:
	/* 0x167e: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1681:
	/* 0x1681: je     1694 <tail_handle_ipv4+0x1694> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1694;
	}
x86_l_1683:
	/* 0x1683: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_168a:
	/* 0x168a: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_168c:
	/* 0x168c: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_168f:
	/* 0x168f: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1692:
	/* 0x1692: jmp    1699 <tail_handle_ipv4+0x1699> */
	goto x86_l_1699;
x86_l_1694:
	/* 0x1694: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1699:
	/* 0x1699: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_169e:
	/* 0x169e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16a0:
	/* 0x16a0: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_16a2:
	/* 0x16a2: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_16a4:
	/* 0x16a4: jb     16aa <tail_handle_ipv4+0x16aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_16aa;
	}
x86_l_16a6:
	/* 0x16a6: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_16a8:
	/* 0x16a8: je     16bb <tail_handle_ipv4+0x16bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16bb;
	}
x86_l_16aa:
	/* 0x16aa: mov    BYTE PTR [rsp+0x6a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_16ae:
	/* 0x16ae: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16b2:
	/* 0x16b2: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_16b9:
	/* 0x16b9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bb:
	/* 0x16bb: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_16c2:
	/* 0x16c2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16c5:
	/* 0x16c5: je     16d8 <tail_handle_ipv4+0x16d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16d8;
	}
x86_l_16c7:
	/* 0x16c7: mov    QWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_16d0:
	/* 0x16d0: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16d3:
	/* 0x16d3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16d8:
	/* 0x16d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16dd:
	/* 0x16dd: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e2:
	/* 0x16e2: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16e7:
	/* 0x16e7: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16ef:
	/* 0x16ef: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f1:
	/* 0x16f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f3:
	/* 0x16f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16f5:
	/* 0x16f5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16fa:
	/* 0x16fa: js     25e9 <tail_handle_ipv4+0x25e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9705ULL;
	}
x86_l_1700:
	/* 0x1700: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1705:
	/* 0x1705: mov    BYTE PTR [rsp+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_1709:
	/* 0x1709: test   BYTE PTR [rdx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_170d:
	/* 0x170d: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_1710:
	/* 0x1710: je     17b3 <tail_handle_ipv4+0x17b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b3;
	}
x86_l_1716:
	/* 0x1716: mov    rax,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_171d:
	/* 0x171d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1720:
	/* 0x1720: je     1731 <tail_handle_ipv4+0x1731> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1731;
	}
x86_l_1722:
	/* 0x1722: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1727:
	/* 0x1727: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1729:
	/* 0x1729: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_172b:
	/* 0x172b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_172f:
	/* 0x172f: jmp    1754 <tail_handle_ipv4+0x1754> */
	goto x86_l_1754;
x86_l_1731:
	/* 0x1731: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1736:
	/* 0x1736: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1738:
	/* 0x1738: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_173a:
	/* 0x173a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_173e:
	/* 0x173e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1748:
	/* 0x1748: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_174b:
	/* 0x174b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1750:
	/* 0x1750: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1754:
	/* 0x1754: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_175c:
	/* 0x175c: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1761:
	/* 0x1761: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1766:
	/* 0x1766: movzx  ecx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_176b:
	/* 0x176b: mov    WORD PTR [rsp+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1770:
	/* 0x1770: mov    WORD PTR [rsp+0x4a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 317827579904ULL);
x86_l_1777:
	/* 0x1777: mov    DWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_177f:
	/* 0x177f: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1781:
	/* 0x1781: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1786:
	/* 0x1786: mov    DWORD PTR [rsp+0x80],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_178e:
	/* 0x178e: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_1799:
	/* 0x1799: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_179e:
	/* 0x179e: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_17a5:
	/* 0x17a5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17aa:
	/* 0x17aa: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17af:
	/* 0x17af: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b1:
	/* 0x17b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b3:
	/* 0x17b3: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17b6:
	/* 0x17b6: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_17bf:
	/* 0x17bf: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_17c7:
	/* 0x17c7: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_17d0:
	/* 0x17d0: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17d4:
	/* 0x17d4: mov    BYTE PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_17d9:
	/* 0x17d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17de:
	/* 0x17de: mov    rdi,QWORD PTR [rip+0x69b0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_17e5:
	/* 0x17e5: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17ea:
	/* 0x17ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ec:
	/* 0x17ec: movzx  ecx,BYTE PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_17f1:
	/* 0x17f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17f4:
	/* 0x17f4: je     1828 <tail_handle_ipv4+0x1828> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1828;
	}
x86_l_17f6:
	/* 0x17f6: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_17f9:
	/* 0x17f9: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1803:
	/* 0x1803: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1808:
	/* 0x1808: jne    184b <tail_handle_ipv4+0x184b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_184b;
	}
x86_l_180a:
	/* 0x180a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_180d:
	/* 0x180d: je     184b <tail_handle_ipv4+0x184b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_184b;
	}
x86_l_180f:
	/* 0x180f: movzx  r8d,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1814:
	/* 0x1814: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1817:
	/* 0x1817: mov    edi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 0ULL);
x86_l_181c:
	/* 0x181c: and    r8b,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_1820:
	/* 0x1820: jne    1949 <tail_handle_ipv4+0x1949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1949;
	}
x86_l_1826:
	/* 0x1826: jmp    184b <tail_handle_ipv4+0x184b> */
	goto x86_l_184b;
x86_l_1828:
	/* 0x1828: mov    edi,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967162ULL);
x86_l_182d:
	/* 0x182d: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_1830:
	/* 0x1830: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_183a:
	/* 0x183a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_183f:
	/* 0x183f: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_1845:
	/* 0x1845: jne    1949 <tail_handle_ipv4+0x1949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1949;
	}
x86_l_184b:
	/* 0x184b: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_184e:
	/* 0x184e: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1852:
	/* 0x1852: movzx  edi,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_1857:
	/* 0x1857: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_185b:
	/* 0x185b: mov    edi,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_185e:
	/* 0x185e: mov    DWORD PTR [rsp+0x20],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1862:
	/* 0x1862: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1867:
	/* 0x1867: movzx  edi,WORD PTR [r8+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_186c:
	/* 0x186c: test   di,di */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_16);
x86_l_186f:
	/* 0x186f: je     1876 <tail_handle_ipv4+0x1876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1876;
	}
x86_l_1871:
	/* 0x1871: mov    WORD PTR [rsp+0x2a],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1876:
	/* 0x1876: test   rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1879:
	/* 0x1879: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1881:
	/* 0x1881: je     1914 <tail_handle_ipv4+0x1914> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1914;
	}
x86_l_1887:
	/* 0x1887: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_188a:
	/* 0x188a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_188c:
	/* 0x188c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1891:
	/* 0x1891: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_189c:
	/* 0x189c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_18a1:
	/* 0x18a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18a4:
	/* 0x18a4: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_18a9:
	/* 0x18a9: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ae:
	/* 0x18ae: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18b1:
	/* 0x18b1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18b6:
	/* 0x18b6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b9:
	/* 0x18b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18bb:
	/* 0x18bb: mov    edi,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967155ULL);
x86_l_18c0:
	/* 0x18c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18c2:
	/* 0x18c2: js     1946 <tail_handle_ipv4+0x1946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1946;
	}
x86_l_18c8:
	/* 0x18c8: not    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18ca:
	/* 0x18ca: add    ebp,DWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_18cd:
	/* 0x18cd: adc    ebp,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_18d0:
	/* 0x18d0: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_18d5:
	/* 0x18d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18d8:
	/* 0x18d8: mov    esi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 10ULL);
x86_l_18dd:
	/* 0x18dd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18df:
	/* 0x18df: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_18e1:
	/* 0x18e1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e4:
	/* 0x18e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e6:
	/* 0x18e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18e8:
	/* 0x18e8: js     1941 <tail_handle_ipv4+0x1941> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1941;
	}
x86_l_18ea:
	/* 0x18ea: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_18ed:
	/* 0x18ed: je     195b <tail_handle_ipv4+0x195b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_195b;
	}
x86_l_18ef:
	/* 0x18ef: movabs rbp,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 2199023255552ULL);
x86_l_18f9:
	/* 0x18f9: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18fe:
	/* 0x18fe: test   rsi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1901:
	/* 0x1901: mov    r8,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1909:
	/* 0x1909: je     19b8 <tail_handle_ipv4+0x19b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19b8;
	}
x86_l_190f:
	/* 0x190f: jmp    1a8e <tail_handle_ipv4+0x1a8e> */
	return 6798ULL;
x86_l_1914:
	/* 0x1914: movzx  edx,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1919:
	/* 0x1919: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_191c:
	/* 0x191c: je     1a5d <tail_handle_ipv4+0x1a5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6749ULL;
	}
x86_l_1922:
	/* 0x1922: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1925:
	/* 0x1925: je     1a40 <tail_handle_ipv4+0x1a40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6720ULL;
	}
x86_l_192b:
	/* 0x192b: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_192e:
	/* 0x192e: jne    1887 <tail_handle_ipv4+0x1887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1887;
	}
x86_l_1934:
	/* 0x1934: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1937:
	/* 0x1937: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_193c:
	/* 0x193c: jmp    188c <tail_handle_ipv4+0x188c> */
	goto x86_l_188c;
x86_l_1941:
	/* 0x1941: mov    edi,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967143ULL);
x86_l_1946:
	/* 0x1946: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1949:
	/* 0x1949: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_194c:
	/* 0x194c: mov    eax,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_32);
x86_l_194e:
	/* 0x194e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1950:
	/* 0x1950: jns    2234 <tail_handle_ipv4+0x2234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 8756ULL;
	}
x86_l_1956:
	/* 0x1956: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_195b:
	/* 0x195b: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1963:
	/* 0x1963: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1968:
	/* 0x1968: lea    esi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_196b:
	/* 0x196b: mov    r8d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1973:
	/* 0x1973: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1977:
	/* 0x1977: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_197c:
	/* 0x197c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_197f:
	/* 0x197f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1981:
	/* 0x1981: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1983:
	/* 0x1983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1985:
	/* 0x1985: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1987:
	/* 0x1987: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_198a:
	/* 0x198a: and    ecx,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_1990:
	/* 0x1990: movabs rbp,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 2199023255552ULL);
x86_l_199a:
	/* 0x199a: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_199f:
	/* 0x199f: test   rsi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_19a2:
	/* 0x19a2: jne    1a7e <tail_handle_ipv4+0x1a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6782ULL;
	}
x86_l_19a8:
	/* 0x19a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19aa:
	/* 0x19aa: mov    r8,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_19b2:
	/* 0x19b2: js     1a86 <tail_handle_ipv4+0x1a86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6790ULL;
	}
x86_l_19b8:
	/* 0x19b8: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19bd:
	/* 0x19bd: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19c1:
	/* 0x19c1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_19c4:
	/* 0x19c4: je     1a8e <tail_handle_ipv4+0x1a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6798ULL;
	}
x86_l_19ca:
	/* 0x19ca: cmp    WORD PTR [rsp+0x4],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19cf:
	/* 0x19cf: je     1a8e <tail_handle_ipv4+0x1a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6798ULL;
	}
x86_l_19d5:
	/* 0x19d5: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_19d8:
	/* 0x19d8: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19dd:
	/* 0x19dd: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_19e2:
	/* 0x19e2: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_19e5:
	/* 0x19e5: or     esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_19e8:
	/* 0x19e8: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19ed:
	/* 0x19ed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19f0:
	/* 0x19f0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19f5:
	/* 0x19f5: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_19f8:
	/* 0x19f8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fb:
	/* 0x19fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fd:
	/* 0x19fd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19ff:
	/* 0x19ff: js     2242 <tail_handle_ipv4+0x2242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8770ULL;
	}
x86_l_1a05:
	/* 0x1a05: movzx  ecx,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_1a0a:
	/* 0x1a0a: movzx  eax,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a0e:
	/* 0x1a0e: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a13:
	/* 0x1a13: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a15:
	/* 0x1a15: mov    r8d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a1d:
	/* 0x1a1d: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
	return 6689ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6689ULL: goto x86_l_1a21;
	case 6694ULL: goto x86_l_1a26;
	case 6697ULL: goto x86_l_1a29;
	case 6701ULL: goto x86_l_1a2d;
	case 6703ULL: goto x86_l_1a2f;
	case 6705ULL: goto x86_l_1a31;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6713ULL: goto x86_l_1a39;
	case 6718ULL: goto x86_l_1a3e;
	case 6720ULL: goto x86_l_1a40;
	case 6731ULL: goto x86_l_1a4b;
	case 6736ULL: goto x86_l_1a50;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6749ULL: goto x86_l_1a5d;
	case 6752ULL: goto x86_l_1a60;
	case 6757ULL: goto x86_l_1a65;
	case 6762ULL: goto x86_l_1a6a;
	case 6766ULL: goto x86_l_1a6e;
	case 6771ULL: goto x86_l_1a73;
	case 6777ULL: goto x86_l_1a79;
	case 6782ULL: goto x86_l_1a7e;
	case 6790ULL: goto x86_l_1a86;
	case 6792ULL: goto x86_l_1a88;
	case 6798ULL: goto x86_l_1a8e;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6820ULL: goto x86_l_1aa4;
	case 6822ULL: goto x86_l_1aa6;
	case 6826ULL: goto x86_l_1aaa;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6843ULL: goto x86_l_1abb;
	case 6849ULL: goto x86_l_1ac1;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6862ULL: goto x86_l_1ace;
	case 6864ULL: goto x86_l_1ad0;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	case 6887ULL: goto x86_l_1ae7;
	case 6894ULL: goto x86_l_1aee;
	case 6897ULL: goto x86_l_1af1;
	case 6903ULL: goto x86_l_1af7;
	case 6906ULL: goto x86_l_1afa;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6925ULL: goto x86_l_1b0d;
	case 6929ULL: goto x86_l_1b11;
	case 6938ULL: goto x86_l_1b1a;
	case 6947ULL: goto x86_l_1b23;
	case 6957ULL: goto x86_l_1b2d;
	case 6962ULL: goto x86_l_1b32;
	case 6967ULL: goto x86_l_1b37;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6981ULL: goto x86_l_1b45;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6989ULL: goto x86_l_1b4d;
	case 6993ULL: goto x86_l_1b51;
	case 6995ULL: goto x86_l_1b53;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7031ULL: goto x86_l_1b77;
	case 7033ULL: goto x86_l_1b79;
	case 7035ULL: goto x86_l_1b7b;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7057ULL: goto x86_l_1b91;
	case 7059ULL: goto x86_l_1b93;
	case 7063ULL: goto x86_l_1b97;
	case 7065ULL: goto x86_l_1b99;
	case 7068ULL: goto x86_l_1b9c;
	case 7073ULL: goto x86_l_1ba1;
	case 7077ULL: goto x86_l_1ba5;
	case 7085ULL: goto x86_l_1bad;
	case 7088ULL: goto x86_l_1bb0;
	case 7091ULL: goto x86_l_1bb3;
	case 7096ULL: goto x86_l_1bb8;
	case 7098ULL: goto x86_l_1bba;
	case 7100ULL: goto x86_l_1bbc;
	case 7106ULL: goto x86_l_1bc2;
	case 7113ULL: goto x86_l_1bc9;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7127ULL: goto x86_l_1bd7;
	case 7130ULL: goto x86_l_1bda;
	case 7136ULL: goto x86_l_1be0;
	case 7142ULL: goto x86_l_1be6;
	case 7144ULL: goto x86_l_1be8;
	case 7148ULL: goto x86_l_1bec;
	case 7151ULL: goto x86_l_1bef;
	case 7153ULL: goto x86_l_1bf1;
	case 7161ULL: goto x86_l_1bf9;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7178ULL: goto x86_l_1c0a;
	case 7180ULL: goto x86_l_1c0c;
	case 7183ULL: goto x86_l_1c0f;
	case 7185ULL: goto x86_l_1c11;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7194ULL: goto x86_l_1c1a;
	case 7198ULL: goto x86_l_1c1e;
	case 7201ULL: goto x86_l_1c21;
	case 7203ULL: goto x86_l_1c23;
	case 7209ULL: goto x86_l_1c29;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7226ULL: goto x86_l_1c3a;
	case 7233ULL: goto x86_l_1c41;
	case 7235ULL: goto x86_l_1c43;
	case 7240ULL: goto x86_l_1c48;
	case 7244ULL: goto x86_l_1c4c;
	case 7246ULL: goto x86_l_1c4e;
	case 7253ULL: goto x86_l_1c55;
	case 7255ULL: goto x86_l_1c57;
	case 7262ULL: goto x86_l_1c5e;
	case 7267ULL: goto x86_l_1c63;
	case 7272ULL: goto x86_l_1c68;
	case 7281ULL: goto x86_l_1c71;
	case 7290ULL: goto x86_l_1c7a;
	case 7299ULL: goto x86_l_1c83;
	case 7308ULL: goto x86_l_1c8c;
	case 7317ULL: goto x86_l_1c95;
	case 7322ULL: goto x86_l_1c9a;
	case 7330ULL: goto x86_l_1ca2;
	case 7339ULL: goto x86_l_1cab;
	case 7348ULL: goto x86_l_1cb4;
	case 7355ULL: goto x86_l_1cbb;
	case 7362ULL: goto x86_l_1cc2;
	case 7366ULL: goto x86_l_1cc6;
	case 7368ULL: goto x86_l_1cc8;
	case 7375ULL: goto x86_l_1ccf;
	case 7379ULL: goto x86_l_1cd3;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7391ULL: goto x86_l_1cdf;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7404ULL: goto x86_l_1cec;
	case 7408ULL: goto x86_l_1cf0;
	case 7410ULL: goto x86_l_1cf2;
	case 7417ULL: goto x86_l_1cf9;
	case 7421ULL: goto x86_l_1cfd;
	case 7425ULL: goto x86_l_1d01;
	case 7427ULL: goto x86_l_1d03;
	case 7432ULL: goto x86_l_1d08;
	case 7437ULL: goto x86_l_1d0d;
	case 7443ULL: goto x86_l_1d13;
	case 7447ULL: goto x86_l_1d17;
	case 7449ULL: goto x86_l_1d19;
	case 7454ULL: goto x86_l_1d1e;
	case 7456ULL: goto x86_l_1d20;
	case 7458ULL: goto x86_l_1d22;
	case 7462ULL: goto x86_l_1d26;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7471ULL: goto x86_l_1d2f;
	case 7473ULL: goto x86_l_1d31;
	case 7477ULL: goto x86_l_1d35;
	case 7487ULL: goto x86_l_1d3f;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7499ULL: goto x86_l_1d4b;
	case 7503ULL: goto x86_l_1d4f;
	case 7506ULL: goto x86_l_1d52;
	case 7509ULL: goto x86_l_1d55;
	case 7514ULL: goto x86_l_1d5a;
	case 7519ULL: goto x86_l_1d5f;
	case 7523ULL: goto x86_l_1d63;
	case 7525ULL: goto x86_l_1d65;
	case 7529ULL: goto x86_l_1d69;
	case 7531ULL: goto x86_l_1d6b;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7544ULL: goto x86_l_1d78;
	case 7548ULL: goto x86_l_1d7c;
	case 7550ULL: goto x86_l_1d7e;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7564ULL: goto x86_l_1d8c;
	case 7566ULL: goto x86_l_1d8e;
	case 7569ULL: goto x86_l_1d91;
	case 7571ULL: goto x86_l_1d93;
	case 7573ULL: goto x86_l_1d95;
	case 7575ULL: goto x86_l_1d97;
	case 7579ULL: goto x86_l_1d9b;
	case 7583ULL: goto x86_l_1d9f;
	case 7590ULL: goto x86_l_1da6;
	case 7592ULL: goto x86_l_1da8;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7604ULL: goto x86_l_1db4;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7631ULL: goto x86_l_1dcf;
	case 7636ULL: goto x86_l_1dd4;
	case 7638ULL: goto x86_l_1dd6;
	case 7640ULL: goto x86_l_1dd8;
	case 7642ULL: goto x86_l_1dda;
	case 7648ULL: goto x86_l_1de0;
	case 7657ULL: goto x86_l_1de9;
	case 7662ULL: goto x86_l_1dee;
	case 7668ULL: goto x86_l_1df4;
	case 7671ULL: goto x86_l_1df7;
	case 7674ULL: goto x86_l_1dfa;
	case 7677ULL: goto x86_l_1dfd;
	case 7679ULL: goto x86_l_1dff;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7698ULL: goto x86_l_1e12;
	case 7706ULL: goto x86_l_1e1a;
	case 7715ULL: goto x86_l_1e23;
	case 7719ULL: goto x86_l_1e27;
	case 7724ULL: goto x86_l_1e2c;
	case 7729ULL: goto x86_l_1e31;
	case 7736ULL: goto x86_l_1e38;
	case 7741ULL: goto x86_l_1e3d;
	case 7743ULL: goto x86_l_1e3f;
	case 7746ULL: goto x86_l_1e42;
	case 7748ULL: goto x86_l_1e44;
	case 7752ULL: goto x86_l_1e48;
	case 7758ULL: goto x86_l_1e4e;
	case 7765ULL: goto x86_l_1e55;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7783ULL: goto x86_l_1e67;
	case 7785ULL: goto x86_l_1e69;
	case 7787ULL: goto x86_l_1e6b;
	case 7793ULL: goto x86_l_1e71;
	case 7798ULL: goto x86_l_1e76;
	case 7800ULL: goto x86_l_1e78;
	case 7802ULL: goto x86_l_1e7a;
	case 7805ULL: goto x86_l_1e7d;
	case 7808ULL: goto x86_l_1e80;
	case 7812ULL: goto x86_l_1e84;
	case 7816ULL: goto x86_l_1e88;
	case 7818ULL: goto x86_l_1e8a;
	case 7822ULL: goto x86_l_1e8e;
	case 7829ULL: goto x86_l_1e95;
	case 7832ULL: goto x86_l_1e98;
	case 7842ULL: goto x86_l_1ea2;
	case 7846ULL: goto x86_l_1ea6;
	case 7850ULL: goto x86_l_1eaa;
	case 7860ULL: goto x86_l_1eb4;
	case 7865ULL: goto x86_l_1eb9;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7881ULL: goto x86_l_1ec9;
	case 7886ULL: goto x86_l_1ece;
	case 7888ULL: goto x86_l_1ed0;
	case 7891ULL: goto x86_l_1ed3;
	case 7893ULL: goto x86_l_1ed5;
	case 7896ULL: goto x86_l_1ed8;
	case 7900ULL: goto x86_l_1edc;
	case 7902ULL: goto x86_l_1ede;
	case 7911ULL: goto x86_l_1ee7;
	case 7916ULL: goto x86_l_1eec;
	case 7921ULL: goto x86_l_1ef1;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7942ULL: goto x86_l_1f06;
	case 7947ULL: goto x86_l_1f0b;
	case 7954ULL: goto x86_l_1f12;
	case 7957ULL: goto x86_l_1f15;
	case 7962ULL: goto x86_l_1f1a;
	case 7964ULL: goto x86_l_1f1c;
	case 7969ULL: goto x86_l_1f21;
	case 7976ULL: goto x86_l_1f28;
	case 7977ULL: goto x86_l_1f29;
	case 7979ULL: goto x86_l_1f2b;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7985ULL: goto x86_l_1f31;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8017ULL: goto x86_l_1f51;
	case 8022ULL: goto x86_l_1f56;
	case 8025ULL: goto x86_l_1f59;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8035ULL: goto x86_l_1f63;
	case 8038ULL: goto x86_l_1f66;
	case 8041ULL: goto x86_l_1f69;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8055ULL: goto x86_l_1f77;
	case 8062ULL: goto x86_l_1f7e;
	case 8069ULL: goto x86_l_1f85;
	case 8072ULL: goto x86_l_1f88;
	case 8074ULL: goto x86_l_1f8a;
	case 8081ULL: goto x86_l_1f91;
	case 8083ULL: goto x86_l_1f93;
	case 8086ULL: goto x86_l_1f96;
	case 8089ULL: goto x86_l_1f99;
	case 8092ULL: goto x86_l_1f9c;
	case 8097ULL: goto x86_l_1fa1;
	case 8099ULL: goto x86_l_1fa3;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8113ULL: goto x86_l_1fb1;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8126ULL: goto x86_l_1fbe;
	case 8128ULL: goto x86_l_1fc0;
	case 8131ULL: goto x86_l_1fc3;
	case 8136ULL: goto x86_l_1fc8;
	case 8139ULL: goto x86_l_1fcb;
	case 8141ULL: goto x86_l_1fcd;
	case 8146ULL: goto x86_l_1fd2;
	case 8152ULL: goto x86_l_1fd8;
	case 8159ULL: goto x86_l_1fdf;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8174ULL: goto x86_l_1fee;
	case 8177ULL: goto x86_l_1ff1;
	case 8182ULL: goto x86_l_1ff6;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8194ULL: goto x86_l_2002;
	case 8200ULL: goto x86_l_2008;
	case 8203ULL: goto x86_l_200b;
	case 8206ULL: goto x86_l_200e;
	case 8209ULL: goto x86_l_2011;
	case 8214ULL: goto x86_l_2016;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8228ULL: goto x86_l_2024;
	case 8230ULL: goto x86_l_2026;
	case 8232ULL: goto x86_l_2028;
	case 8238ULL: goto x86_l_202e;
	case 8243ULL: goto x86_l_2033;
	case 8248ULL: goto x86_l_2038;
	case 8251ULL: goto x86_l_203b;
	case 8256ULL: goto x86_l_2040;
	case 8261ULL: goto x86_l_2045;
	case 8264ULL: goto x86_l_2048;
	case 8266ULL: goto x86_l_204a;
	case 8268ULL: goto x86_l_204c;
	case 8273ULL: goto x86_l_2051;
	case 8275ULL: goto x86_l_2053;
	case 8281ULL: goto x86_l_2059;
	case 8286ULL: goto x86_l_205e;
	case 8291ULL: goto x86_l_2063;
	case 8294ULL: goto x86_l_2066;
	case 8296ULL: goto x86_l_2068;
	case 8301ULL: goto x86_l_206d;
	case 8304ULL: goto x86_l_2070;
	case 8306ULL: goto x86_l_2072;
	case 8308ULL: goto x86_l_2074;
	case 8313ULL: goto x86_l_2079;
	case 8315ULL: goto x86_l_207b;
	case 8321ULL: goto x86_l_2081;
	case 8328ULL: goto x86_l_2088;
	case 8330ULL: goto x86_l_208a;
	case 8332ULL: goto x86_l_208c;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8352ULL: goto x86_l_20a0;
	case 8354ULL: goto x86_l_20a2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a21:
	/* 0x1a21: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1a26:
	/* 0x1a26: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a29:
	/* 0x1a29: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a2d:
	/* 0x1a2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a2f:
	/* 0x1a2f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a31:
	/* 0x1a31: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_1a34:
	/* 0x1a34: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1a37:
	/* 0x1a37: jns    1a8e <tail_handle_ipv4+0x1a8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1a8e;
	}
x86_l_1a39:
	/* 0x1a39: mov    ecx,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967142ULL);
x86_l_1a3e:
	/* 0x1a3e: jmp    1a86 <tail_handle_ipv4+0x1a86> */
	goto x86_l_1a86;
x86_l_1a40:
	/* 0x1a40: mov    DWORD PTR [rsp+0xa0],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767392ULL);
x86_l_1a4b:
	/* 0x1a4b: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1a50:
	/* 0x1a50: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a55:
	/* 0x1a55: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a58:
	/* 0x1a58: jmp    189c <tail_handle_ipv4+0x189c> */
	return 6300ULL;
x86_l_1a5d:
	/* 0x1a5d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a60:
	/* 0x1a60: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a65:
	/* 0x1a65: jmp    188c <tail_handle_ipv4+0x188c> */
	return 6284ULL;
x86_l_1a6a:
	/* 0x1a6a: test   BYTE PTR [rdx+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1a73:
	/* 0x1a73: je     1df4 <tail_handle_ipv4+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df4;
	}
x86_l_1a79:
	/* 0x1a79: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_1a7e:
	/* 0x1a7e: mov    r8,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1a86:
	/* 0x1a86: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1a88:
	/* 0x1a88: js     27cf <tail_handle_ipv4+0x27cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10191ULL;
	}
x86_l_1a8e:
	/* 0x1a8e: cmp    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_1a97:
	/* 0x1a97: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    rcx,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1aa4:
	/* 0x1aa4: jne    1ab0 <tail_handle_ipv4+0x1ab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ab0;
	}
x86_l_1aa6:
	/* 0x1aa6: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_1aaa:
	/* 0x1aaa: js     25ae <tail_handle_ipv4+0x25ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9646ULL;
	}
x86_l_1ab0:
	/* 0x1ab0: rol    QWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 137438953504ULL);
x86_l_1ab6:
	/* 0x1ab6: rol    DWORD PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 171798691856ULL);
x86_l_1abb:
	/* 0x1abb: movzx  r14d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1ac1:
	/* 0x1ac1: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_1ac5:
	/* 0x1ac5: je     1ad0 <tail_handle_ipv4+0x1ad0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ad0;
	}
x86_l_1ac7:
	/* 0x1ac7: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1ace:
	/* 0x1ace: jmp    1ad7 <tail_handle_ipv4+0x1ad7> */
	goto x86_l_1ad7;
x86_l_1ad0:
	/* 0x1ad0: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1ad7:
	/* 0x1ad7: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_1adc:
	/* 0x1adc: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1aee:
	/* 0x1aee: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af1:
	/* 0x1af1: je     1b8e <tail_handle_ipv4+0x1b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8e;
	}
x86_l_1af7:
	/* 0x1af7: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1afa:
	/* 0x1afa: je     1b8e <tail_handle_ipv4+0x1b8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8e;
	}
x86_l_1b00:
	/* 0x1b00: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b05:
	/* 0x1b05: mov    BYTE PTR [rsp+0x10],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b0a:
	/* 0x1b0a: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_1b0d:
	/* 0x1b0d: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b11:
	/* 0x1b11: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b23:
	/* 0x1b23: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_1b2d:
	/* 0x1b2d: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b32:
	/* 0x1b32: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b37:
	/* 0x1b37: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b3e:
	/* 0x1b3e: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b43:
	/* 0x1b43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b45:
	/* 0x1b45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: je     1b53 <tail_handle_ipv4+0x1b53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b53;
	}
x86_l_1b4a:
	/* 0x1b4a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b4d:
	/* 0x1b4d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b51:
	/* 0x1b51: jmp    1b7b <tail_handle_ipv4+0x1b7b> */
	goto x86_l_1b7b;
x86_l_1b53:
	/* 0x1b53: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    QWORD PTR [rsp+0x48],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b61:
	/* 0x1b61: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b66:
	/* 0x1b66: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b6d:
	/* 0x1b6d: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b72:
	/* 0x1b72: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b77:
	/* 0x1b77: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b79:
	/* 0x1b79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7b:
	/* 0x1b7b: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_1b7e:
	/* 0x1b7e: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b83:
	/* 0x1b83: movzx  r14d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1b89:
	/* 0x1b89: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b8e:
	/* 0x1b8e: test   rsi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1b91:
	/* 0x1b91: jne    1bf1 <tail_handle_ipv4+0x1bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bf1;
	}
x86_l_1b93:
	/* 0x1b93: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_1b97:
	/* 0x1b97: jne    1bf1 <tail_handle_ipv4+0x1bf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1bf1;
	}
x86_l_1b99:
	/* 0x1b99: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_1b9c:
	/* 0x1b9c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1ba1:
	/* 0x1ba1: add    r8d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_1ba5:
	/* 0x1ba5: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bad:
	/* 0x1bad: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bb0:
	/* 0x1bb0: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_1bb3:
	/* 0x1bb3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1bb8:
	/* 0x1bb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bba:
	/* 0x1bba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bbc:
	/* 0x1bbc: js     1d03 <tail_handle_ipv4+0x1d03> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d03;
	}
x86_l_1bc2:
	/* 0x1bc2: mov    ebp,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1bcb:
	/* 0x1bcb: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1bd0:
	/* 0x1bd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd2:
	/* 0x1bd2: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1bd7:
	/* 0x1bd7: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1bda:
	/* 0x1bda: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_1be0:
	/* 0x1be0: jne    25f6 <tail_handle_ipv4+0x25f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9718ULL;
	}
x86_l_1be6:
	/* 0x1be6: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_1be8:
	/* 0x1be8: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bec:
	/* 0x1bec: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bef:
	/* 0x1bef: jmp    1c00 <tail_handle_ipv4+0x1c00> */
	goto x86_l_1c00;
x86_l_1bf1:
	/* 0x1bf1: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1bf9:
	/* 0x1bf9: mov    ebp,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1c00:
	/* 0x1c00: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c05:
	/* 0x1c05: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c0a:
	/* 0x1c0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0c:
	/* 0x1c0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c0f:
	/* 0x1c0f: je     1c3a <tail_handle_ipv4+0x1c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c3a;
	}
x86_l_1c11:
	/* 0x1c11: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1c15:
	/* 0x1c15: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_1c18:
	/* 0x1c18: je     1c3a <tail_handle_ipv4+0x1c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c3a;
	}
x86_l_1c1a:
	/* 0x1c1a: movzx  edx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1c1e:
	/* 0x1c1e: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1c21:
	/* 0x1c21: je     1c3a <tail_handle_ipv4+0x1c3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c3a;
	}
x86_l_1c23:
	/* 0x1c23: cmp    WORD PTR [rsp+0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934592ULL);
x86_l_1c29:
	/* 0x1c29: je     224f <tail_handle_ipv4+0x224f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8783ULL;
	}
x86_l_1c2f:
	/* 0x1c2f: cmp    dx,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1c34:
	/* 0x1c34: je     224f <tail_handle_ipv4+0x224f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8783ULL;
	}
x86_l_1c3a:
	/* 0x1c3a: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1c41:
	/* 0x1c41: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c43:
	/* 0x1c43: movzx  ebp,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_1c48:
	/* 0x1c48: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1c4c:
	/* 0x1c4c: jne    1c57 <tail_handle_ipv4+0x1c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c57;
	}
x86_l_1c4e:
	/* 0x1c4e: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1c55:
	/* 0x1c55: jmp    1c5e <tail_handle_ipv4+0x1c5e> */
	goto x86_l_1c5e;
x86_l_1c57:
	/* 0x1c57: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1c5e:
	/* 0x1c5e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c63:
	/* 0x1c63: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1c68:
	/* 0x1c68: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1c71:
	/* 0x1c71: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1c7a:
	/* 0x1c7a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1c83:
	/* 0x1c83: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1c95:
	/* 0x1c95: mov    WORD PTR [rsp+0x66],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    DWORD PTR [rsp+0x6c],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 463856467970ULL);
x86_l_1ca2:
	/* 0x1ca2: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1cab:
	/* 0x1cab: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    WORD PTR [rsp+0x64],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729632ULL);
x86_l_1cbb:
	/* 0x1cbb: mov    r15,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1cc2:
	/* 0x1cc2: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc6:
	/* 0x1cc6: je     1cd9 <tail_handle_ipv4+0x1cd9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd9;
	}
x86_l_1cc8:
	/* 0x1cc8: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1ccf:
	/* 0x1ccf: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1cd3:
	/* 0x1cd3: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1cd7:
	/* 0x1cd7: jmp    1cdf <tail_handle_ipv4+0x1cdf> */
	goto x86_l_1cdf;
x86_l_1cd9:
	/* 0x1cd9: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1cdf:
	/* 0x1cdf: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1ce3:
	/* 0x1ce3: jne    1d13 <tail_handle_ipv4+0x1d13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d13;
	}
x86_l_1ce5:
	/* 0x1ce5: mov    WORD PTR [rsp+0x64],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729632ULL);
x86_l_1cec:
	/* 0x1cec: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cf0:
	/* 0x1cf0: je     1d0d <tail_handle_ipv4+0x1d0d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d0d;
	}
x86_l_1cf2:
	/* 0x1cf2: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1cf9:
	/* 0x1cf9: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1cfd:
	/* 0x1cfd: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d01:
	/* 0x1d01: jmp    1d13 <tail_handle_ipv4+0x1d13> */
	goto x86_l_1d13;
x86_l_1d03:
	/* 0x1d03: mov    edi,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967161ULL);
x86_l_1d08:
	/* 0x1d08: jmp    1946 <tail_handle_ipv4+0x1946> */
	return 6470ULL;
x86_l_1d0d:
	/* 0x1d0d: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1d13:
	/* 0x1d13: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d17:
	/* 0x1d17: je     1d28 <tail_handle_ipv4+0x1d28> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d28;
	}
x86_l_1d19:
	/* 0x1d19: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1d1e:
	/* 0x1d1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d20:
	/* 0x1d20: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d22:
	/* 0x1d22: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1d26:
	/* 0x1d26: jmp    1d4b <tail_handle_ipv4+0x1d4b> */
	goto x86_l_1d4b;
x86_l_1d28:
	/* 0x1d28: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1d2d:
	/* 0x1d2d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d2f:
	/* 0x1d2f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1d31:
	/* 0x1d31: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1d35:
	/* 0x1d35: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1d3f:
	/* 0x1d3f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1d42:
	/* 0x1d42: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1d47:
	/* 0x1d47: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1d4b:
	/* 0x1d4b: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1d4f:
	/* 0x1d4f: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1d52:
	/* 0x1d52: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d55:
	/* 0x1d55: mov    DWORD PTR [rsp+0x60],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d5a:
	/* 0x1d5a: movzx  edx,BYTE PTR [rsp+0x6a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 106ULL);
x86_l_1d5f:
	/* 0x1d5f: mov    esi,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d63:
	/* 0x1d63: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1d65:
	/* 0x1d65: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d69:
	/* 0x1d69: je     1d7e <tail_handle_ipv4+0x1d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7e;
	}
x86_l_1d6b:
	/* 0x1d6b: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1d72:
	/* 0x1d72: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d74:
	/* 0x1d74: lea    r8d,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1d78:
	/* 0x1d78: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d7c:
	/* 0x1d7c: jmp    1d84 <tail_handle_ipv4+0x1d84> */
	goto x86_l_1d84;
x86_l_1d7e:
	/* 0x1d7e: mov    r8d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5ULL);
x86_l_1d84:
	/* 0x1d84: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d89:
	/* 0x1d89: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d8c:
	/* 0x1d8c: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d8e:
	/* 0x1d8e: cmp    r8d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_1d91:
	/* 0x1d91: jb     1d97 <tail_handle_ipv4+0x1d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d97;
	}
x86_l_1d93:
	/* 0x1d93: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_1d95:
	/* 0x1d95: je     1da8 <tail_handle_ipv4+0x1da8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1da8;
	}
x86_l_1d97:
	/* 0x1d97: mov    BYTE PTR [rsp+0x6a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1da6:
	/* 0x1da6: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da8:
	/* 0x1da8: mov    rax,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1daf:
	/* 0x1daf: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1db2:
	/* 0x1db2: je     1dc5 <tail_handle_ipv4+0x1dc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dc5;
	}
x86_l_1db4:
	/* 0x1db4: mov    QWORD PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1dc0:
	/* 0x1dc0: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dca:
	/* 0x1dca: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dcf:
	/* 0x1dcf: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dd4:
	/* 0x1dd4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd6:
	/* 0x1dd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dd8:
	/* 0x1dd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dda:
	/* 0x1dda: js     25e9 <tail_handle_ipv4+0x25e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9705ULL;
	}
x86_l_1de0:
	/* 0x1de0: cmp    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_1de9:
	/* 0x1de9: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1dee:
	/* 0x1dee: je     24e6 <tail_handle_ipv4+0x24e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9446ULL;
	}
x86_l_1df4:
	/* 0x1df4: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1df7:
	/* 0x1df7: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1dfa:
	/* 0x1dfa: cmp    ecx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_1dfd:
	/* 0x1dfd: jb     1e76 <tail_handle_ipv4+0x1e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1e76;
	}
x86_l_1dff:
	/* 0x1dff: mov    rbp,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e06:
	/* 0x1e06: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e09:
	/* 0x1e09: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1e12:
	/* 0x1e12: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1e1a:
	/* 0x1e1a: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1e23:
	/* 0x1e23: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e27:
	/* 0x1e27: mov    BYTE PTR [rsp+0x50],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383681ULL);
x86_l_1e2c:
	/* 0x1e2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e31:
	/* 0x1e31: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_1e38:
	/* 0x1e38: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e3d:
	/* 0x1e3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e3f:
	/* 0x1e3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e42:
	/* 0x1e42: je     1e4e <tail_handle_ipv4+0x1e4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e4e;
	}
x86_l_1e44:
	/* 0x1e44: test   BYTE PTR [rax+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_1e48:
	/* 0x1e48: je     209d <tail_handle_ipv4+0x209d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209d;
	}
x86_l_1e4e:
	/* 0x1e4e: movzx  ebp,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_1e55:
	/* 0x1e55: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1e5a:
	/* 0x1e5a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e5d:
	/* 0x1e5d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e60:
	/* 0x1e60: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_1e65:
	/* 0x1e65: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e67:
	/* 0x1e67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e69:
	/* 0x1e69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e6b:
	/* 0x1e6b: je     1f37 <tail_handle_ipv4+0x1f37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f37;
	}
x86_l_1e71:
	/* 0x1e71: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1e76:
	/* 0x1e76: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1e78:
	/* 0x1e78: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1e7a:
	/* 0x1e7a: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_1e7d:
	/* 0x1e7d: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e80:
	/* 0x1e80: shl    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1e84:
	/* 0x1e84: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e88:
	/* 0x1e88: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e8a:
	/* 0x1e8a: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e8e:
	/* 0x1e8e: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_1e95:
	/* 0x1e95: mov    DWORD PTR [rbx+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e98:
	/* 0x1e98: movabs rcx,0xf5070200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 68969074465439744ULL);
x86_l_1ea2:
	/* 0x1ea2: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1eaa:
	/* 0x1eaa: movabs rcx,0x700f50100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 30080827648ULL);
x86_l_1eb4:
	/* 0x1eb4: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1eb9:
	/* 0x1eb9: mov    BYTE PTR [rsp+0x78],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ebd:
	/* 0x1ebd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ec9:
	/* 0x1ec9: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ece:
	/* 0x1ece: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ed0:
	/* 0x1ed0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ed3:
	/* 0x1ed3: je     1ede <tail_handle_ipv4+0x1ede> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ede;
	}
x86_l_1ed5:
	/* 0x1ed5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ed8:
	/* 0x1ed8: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1edc:
	/* 0x1edc: jmp    1f06 <tail_handle_ipv4+0x1f06> */
	goto x86_l_1f06;
x86_l_1ede:
	/* 0x1ede: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_1ee7:
	/* 0x1ee7: mov    QWORD PTR [rsp+0x48],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1eec:
	/* 0x1eec: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ef1:
	/* 0x1ef1: mov    rdi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ef8:
	/* 0x1ef8: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1efd:
	/* 0x1efd: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f02:
	/* 0x1f02: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f04:
	/* 0x1f04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f06:
	/* 0x1f06: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f0b:
	/* 0x1f0b: mov    rsi,QWORD PTR [rip+0x69ac] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1f12:
	/* 0x1f12: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f15:
	/* 0x1f15: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1f1a:
	/* 0x1f1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1c:
	/* 0x1f1c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f21:
	/* 0x1f21: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1f28:
	/* 0x1f28: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f29:
	/* 0x1f29: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f2b:
	/* 0x1f2b: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1f2d:
	/* 0x1f2d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f2f:
	/* 0x1f2f: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1f31:
	/* 0x1f31: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f32:
	/* 0x1f32: jmp    27d6 <tail_handle_ipv4+0x27d6> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f37:
	/* 0x1f37: mov    WORD PTR [rsp+0x40],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1f41:
	/* 0x1f41: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f46:
	/* 0x1f46: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f49:
	/* 0x1f49: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f4c:
	/* 0x1f4c: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_1f51:
	/* 0x1f51: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1f56:
	/* 0x1f56: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f59:
	/* 0x1f59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5b:
	/* 0x1f5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f5d:
	/* 0x1f5d: js     2163 <tail_handle_ipv4+0x2163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8547ULL;
	}
x86_l_1f63:
	/* 0x1f63: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f66:
	/* 0x1f66: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1f69:
	/* 0x1f69: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1f71:
	/* 0x1f71: jb     1e76 <tail_handle_ipv4+0x1e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1e76;
	}
x86_l_1f77:
	/* 0x1f77: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_1f85:
	/* 0x1f85: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f88:
	/* 0x1f88: je     1fd8 <tail_handle_ipv4+0x1fd8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fd8;
	}
x86_l_1f8a:
	/* 0x1f8a: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_1f91:
	/* 0x1f91: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f93:
	/* 0x1f93: mov    sil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 24ULL);
x86_l_1f96:
	/* 0x1f96: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_1f99:
	/* 0x1f99: sub    dil,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1f9c:
	/* 0x1f9c: shrx   edx,r13d,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_R13, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_1fa1:
	/* 0x1fa1: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fa3:
	/* 0x1fa3: bzhi   edx,edx,edi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RDI, 0);
x86_l_1fa8:
	/* 0x1fa8: movzx  edi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fab:
	/* 0x1fab: and    edx,0x7fffff00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2147483392ULL);
x86_l_1fb1:
	/* 0x1fb1: mov    r8d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb4:
	/* 0x1fb4: neg    r8b */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_1fb7:
	/* 0x1fb7: shlx   edx,edx,r8d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_R8, X86_ALU_SHL);
x86_l_1fbc:
	/* 0x1fbc: or     edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fbe:
	/* 0x1fbe: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc0:
	/* 0x1fc0: sub    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1fc3:
	/* 0x1fc3: bzhi   eax,r13d,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_R13, X86_WIDTH_32, X86_RSI, 0);
x86_l_1fc8:
	/* 0x1fc8: shl    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1fcb:
	/* 0x1fcb: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1fcd:
	/* 0x1fcd: or     eax,0xd00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 3328ULL);
x86_l_1fd2:
	/* 0x1fd2: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_1fdf:
	/* 0x1fdf: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_1fee:
	/* 0x1fee: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ff1:
	/* 0x1ff1: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ff6:
	/* 0x1ff6: movzx  edx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_1fff:
	/* 0x1fff: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2002:
	/* 0x2002: jb     2229 <tail_handle_ipv4+0x2229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8745ULL;
	}
x86_l_2008:
	/* 0x2008: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_200b:
	/* 0x200b: mov    BYTE PTR [rcx+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_200e:
	/* 0x200e: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2011:
	/* 0x2011: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_2016:
	/* 0x2016: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2019:
	/* 0x2019: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_201e:
	/* 0x201e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2024:
	/* 0x2024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2026:
	/* 0x2026: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2028:
	/* 0x2028: js     2224 <tail_handle_ipv4+0x2224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8740ULL;
	}
x86_l_202e:
	/* 0x202e: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2033:
	/* 0x2033: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2038:
	/* 0x2038: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_203b:
	/* 0x203b: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_2040:
	/* 0x2040: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2045:
	/* 0x2045: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2048:
	/* 0x2048: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204a:
	/* 0x204a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_204c:
	/* 0x204c: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_2051:
	/* 0x2051: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2053:
	/* 0x2053: js     2229 <tail_handle_ipv4+0x2229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8745ULL;
	}
x86_l_2059:
	/* 0x2059: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_205e:
	/* 0x205e: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2063:
	/* 0x2063: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2066:
	/* 0x2066: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2068:
	/* 0x2068: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_206d:
	/* 0x206d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2070:
	/* 0x2070: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2072:
	/* 0x2072: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2074:
	/* 0x2074: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_2079:
	/* 0x2079: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_207b:
	/* 0x207b: js     2229 <tail_handle_ipv4+0x2229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8745ULL;
	}
x86_l_2081:
	/* 0x2081: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_ifindex)));
x86_l_2088:
	/* 0x2088: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208a:
	/* 0x208a: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208c:
	/* 0x208c: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_2091:
	/* 0x2091: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2096:
	/* 0x2096: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2098:
	/* 0x2098: jmp    2229 <tail_handle_ipv4+0x2229> */
	return 8745ULL;
x86_l_209d:
	/* 0x209d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_20a0:
	/* 0x20a0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a2:
	/* 0x20a2: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
	return 8358ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8377ULL: goto x86_l_20b9;
	case 8380ULL: goto x86_l_20bc;
	case 8382ULL: goto x86_l_20be;
	case 8387ULL: goto x86_l_20c3;
	case 8391ULL: goto x86_l_20c7;
	case 8393ULL: goto x86_l_20c9;
	case 8400ULL: goto x86_l_20d0;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8411ULL: goto x86_l_20db;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8420ULL: goto x86_l_20e4;
	case 8422ULL: goto x86_l_20e6;
	case 8428ULL: goto x86_l_20ec;
	case 8433ULL: goto x86_l_20f1;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8446ULL: goto x86_l_20fe;
	case 8449ULL: goto x86_l_2101;
	case 8454ULL: goto x86_l_2106;
	case 8459ULL: goto x86_l_210b;
	case 8462ULL: goto x86_l_210e;
	case 8464ULL: goto x86_l_2110;
	case 8466ULL: goto x86_l_2112;
	case 8468ULL: goto x86_l_2114;
	case 8471ULL: goto x86_l_2117;
	case 8474ULL: goto x86_l_211a;
	case 8477ULL: goto x86_l_211d;
	case 8482ULL: goto x86_l_2122;
	case 8488ULL: goto x86_l_2128;
	case 8495ULL: goto x86_l_212f;
	case 8499ULL: goto x86_l_2133;
	case 8504ULL: goto x86_l_2138;
	case 8507ULL: goto x86_l_213b;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8529ULL: goto x86_l_2151;
	case 8534ULL: goto x86_l_2156;
	case 8537ULL: goto x86_l_2159;
	case 8539ULL: goto x86_l_215b;
	case 8542ULL: goto x86_l_215e;
	case 8547ULL: goto x86_l_2163;
	case 8552ULL: goto x86_l_2168;
	case 8557ULL: goto x86_l_216d;
	case 8560ULL: goto x86_l_2170;
	case 8563ULL: goto x86_l_2173;
	case 8566ULL: goto x86_l_2176;
	case 8571ULL: goto x86_l_217b;
	case 8574ULL: goto x86_l_217e;
	case 8580ULL: goto x86_l_2184;
	case 8582ULL: goto x86_l_2186;
	case 8584ULL: goto x86_l_2188;
	case 8590ULL: goto x86_l_218e;
	case 8595ULL: goto x86_l_2193;
	case 8600ULL: goto x86_l_2198;
	case 8603ULL: goto x86_l_219b;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8620ULL: goto x86_l_21ac;
	case 8625ULL: goto x86_l_21b1;
	case 8627ULL: goto x86_l_21b3;
	case 8629ULL: goto x86_l_21b5;
	case 8634ULL: goto x86_l_21ba;
	case 8639ULL: goto x86_l_21bf;
	case 8642ULL: goto x86_l_21c2;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8652ULL: goto x86_l_21cc;
	case 8654ULL: goto x86_l_21ce;
	case 8656ULL: goto x86_l_21d0;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8684ULL: goto x86_l_21ec;
	case 8692ULL: goto x86_l_21f4;
	case 8700ULL: goto x86_l_21fc;
	case 8705ULL: goto x86_l_2201;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8717ULL: goto x86_l_220d;
	case 8722ULL: goto x86_l_2212;
	case 8727ULL: goto x86_l_2217;
	case 8732ULL: goto x86_l_221c;
	case 8735ULL: goto x86_l_221f;
	case 8740ULL: goto x86_l_2224;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8756ULL: goto x86_l_2234;
	case 8759ULL: goto x86_l_2237;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8773ULL: goto x86_l_2245;
	case 8778ULL: goto x86_l_224a;
	case 8783ULL: goto x86_l_224f;
	case 8787ULL: goto x86_l_2253;
	case 8792ULL: goto x86_l_2258;
	case 8794ULL: goto x86_l_225a;
	case 8796ULL: goto x86_l_225c;
	case 8798ULL: goto x86_l_225e;
	case 8804ULL: goto x86_l_2264;
	case 8811ULL: goto x86_l_226b;
	case 8815ULL: goto x86_l_226f;
	case 8817ULL: goto x86_l_2271;
	case 8824ULL: goto x86_l_2278;
	case 8827ULL: goto x86_l_227b;
	case 8830ULL: goto x86_l_227e;
	case 8832ULL: goto x86_l_2280;
	case 8837ULL: goto x86_l_2285;
	case 8841ULL: goto x86_l_2289;
	case 8843ULL: goto x86_l_228b;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8852ULL: goto x86_l_2294;
	case 8855ULL: goto x86_l_2297;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8882ULL: goto x86_l_22b2;
	case 8886ULL: goto x86_l_22b6;
	case 8888ULL: goto x86_l_22b8;
	case 8895ULL: goto x86_l_22bf;
	case 8898ULL: goto x86_l_22c2;
	case 8901ULL: goto x86_l_22c5;
	case 8906ULL: goto x86_l_22ca;
	case 8910ULL: goto x86_l_22ce;
	case 8914ULL: goto x86_l_22d2;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8923ULL: goto x86_l_22db;
	case 8925ULL: goto x86_l_22dd;
	case 8929ULL: goto x86_l_22e1;
	case 8931ULL: goto x86_l_22e3;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8940ULL: goto x86_l_22ec;
	case 8944ULL: goto x86_l_22f0;
	case 8954ULL: goto x86_l_22fa;
	case 8957ULL: goto x86_l_22fd;
	case 8962ULL: goto x86_l_2302;
	case 8966ULL: goto x86_l_2306;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8976ULL: goto x86_l_2310;
	case 8980ULL: goto x86_l_2314;
	case 8983ULL: goto x86_l_2317;
	case 8987ULL: goto x86_l_231b;
	case 8991ULL: goto x86_l_231f;
	case 8993ULL: goto x86_l_2321;
	case 9000ULL: goto x86_l_2328;
	case 9002ULL: goto x86_l_232a;
	case 9005ULL: goto x86_l_232d;
	case 9008ULL: goto x86_l_2330;
	case 9010ULL: goto x86_l_2332;
	case 9015ULL: goto x86_l_2337;
	case 9017ULL: goto x86_l_2339;
	case 9020ULL: goto x86_l_233c;
	case 9022ULL: goto x86_l_233e;
	case 9024ULL: goto x86_l_2340;
	case 9027ULL: goto x86_l_2343;
	case 9029ULL: goto x86_l_2345;
	case 9034ULL: goto x86_l_234a;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9048ULL: goto x86_l_2358;
	case 9050ULL: goto x86_l_235a;
	case 9057ULL: goto x86_l_2361;
	case 9060ULL: goto x86_l_2364;
	case 9062ULL: goto x86_l_2366;
	case 9067ULL: goto x86_l_236b;
	case 9072ULL: goto x86_l_2370;
	case 9075ULL: goto x86_l_2373;
	case 9080ULL: goto x86_l_2378;
	case 9084ULL: goto x86_l_237c;
	case 9087ULL: goto x86_l_237f;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9098ULL: goto x86_l_238a;
	case 9103ULL: goto x86_l_238f;
	case 9107ULL: goto x86_l_2393;
	case 9109ULL: goto x86_l_2395;
	case 9115ULL: goto x86_l_239b;
	case 9120ULL: goto x86_l_23a0;
	case 9126ULL: goto x86_l_23a6;
	case 9131ULL: goto x86_l_23ab;
	case 9135ULL: goto x86_l_23af;
	case 9142ULL: goto x86_l_23b6;
	case 9146ULL: goto x86_l_23ba;
	case 9152ULL: goto x86_l_23c0;
	case 9159ULL: goto x86_l_23c7;
	case 9162ULL: goto x86_l_23ca;
	case 9165ULL: goto x86_l_23cd;
	case 9170ULL: goto x86_l_23d2;
	case 9174ULL: goto x86_l_23d6;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9199ULL: goto x86_l_23ef;
	case 9203ULL: goto x86_l_23f3;
	case 9210ULL: goto x86_l_23fa;
	case 9213ULL: goto x86_l_23fd;
	case 9215ULL: goto x86_l_23ff;
	case 9221ULL: goto x86_l_2405;
	case 9228ULL: goto x86_l_240c;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9241ULL: goto x86_l_2419;
	case 9243ULL: goto x86_l_241b;
	case 9245ULL: goto x86_l_241d;
	case 9249ULL: goto x86_l_2421;
	case 9253ULL: goto x86_l_2425;
	case 9255ULL: goto x86_l_2427;
	case 9261ULL: goto x86_l_242d;
	case 9266ULL: goto x86_l_2432;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9285ULL: goto x86_l_2445;
	case 9287ULL: goto x86_l_2447;
	case 9292ULL: goto x86_l_244c;
	case 9294ULL: goto x86_l_244e;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9310ULL: goto x86_l_245e;
	case 9313ULL: goto x86_l_2461;
	case 9318ULL: goto x86_l_2466;
	case 9322ULL: goto x86_l_246a;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9334ULL: goto x86_l_2476;
	case 9338ULL: goto x86_l_247a;
	case 9341ULL: goto x86_l_247d;
	case 9345ULL: goto x86_l_2481;
	case 9349ULL: goto x86_l_2485;
	case 9353ULL: goto x86_l_2489;
	case 9357ULL: goto x86_l_248d;
	case 9359ULL: goto x86_l_248f;
	case 9366ULL: goto x86_l_2496;
	case 9368ULL: goto x86_l_2498;
	case 9371ULL: goto x86_l_249b;
	case 9374ULL: goto x86_l_249e;
	case 9376ULL: goto x86_l_24a0;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9389ULL: goto x86_l_24ad;
	case 9393ULL: goto x86_l_24b1;
	case 9395ULL: goto x86_l_24b3;
	case 9397ULL: goto x86_l_24b5;
	case 9401ULL: goto x86_l_24b9;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9412ULL: goto x86_l_24c4;
	case 9415ULL: goto x86_l_24c7;
	case 9418ULL: goto x86_l_24ca;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9435ULL: goto x86_l_24db;
	case 9440ULL: goto x86_l_24e0;
	case 9446ULL: goto x86_l_24e6;
	case 9455ULL: goto x86_l_24ef;
	case 9458ULL: goto x86_l_24f2;
	case 9461ULL: goto x86_l_24f5;
	case 9466ULL: goto x86_l_24fa;
	case 9469ULL: goto x86_l_24fd;
	case 9475ULL: goto x86_l_2503;
	case 9482ULL: goto x86_l_250a;
	case 9487ULL: goto x86_l_250f;
	case 9492ULL: goto x86_l_2514;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9505ULL: goto x86_l_2521;
	case 9507ULL: goto x86_l_2523;
	case 9512ULL: goto x86_l_2528;
	case 9514ULL: goto x86_l_252a;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9529ULL: goto x86_l_2539;
	case 9536ULL: goto x86_l_2540;
	case 9539ULL: goto x86_l_2543;
	case 9541ULL: goto x86_l_2545;
	case 9544ULL: goto x86_l_2548;
	case 9546ULL: goto x86_l_254a;
	case 9550ULL: goto x86_l_254e;
	case 9552ULL: goto x86_l_2550;
	case 9557ULL: goto x86_l_2555;
	case 9561ULL: goto x86_l_2559;
	case 9564ULL: goto x86_l_255c;
	case 9566ULL: goto x86_l_255e;
	case 9568ULL: goto x86_l_2560;
	case 9573ULL: goto x86_l_2565;
	case 9580ULL: goto x86_l_256c;
	case 9585ULL: goto x86_l_2571;
	case 9588ULL: goto x86_l_2574;
	case 9590ULL: goto x86_l_2576;
	case 9592ULL: goto x86_l_2578;
	case 9594ULL: goto x86_l_257a;
	case 9596ULL: goto x86_l_257c;
	case 9601ULL: goto x86_l_2581;
	case 9605ULL: goto x86_l_2585;
	case 9607ULL: goto x86_l_2587;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9627ULL: goto x86_l_259b;
	case 9633ULL: goto x86_l_25a1;
	case 9636ULL: goto x86_l_25a4;
	case 9641ULL: goto x86_l_25a9;
	case 9646ULL: goto x86_l_25ae;
	case 9654ULL: goto x86_l_25b6;
	case 9657ULL: goto x86_l_25b9;
	case 9664ULL: goto x86_l_25c0;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9679ULL: goto x86_l_25cf;
	case 9685ULL: goto x86_l_25d5;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9710ULL: goto x86_l_25ee;
	case 9713ULL: goto x86_l_25f1;
	case 9718ULL: goto x86_l_25f6;
	case 9726ULL: goto x86_l_25fe;
	case 9731ULL: goto x86_l_2603;
	case 9737ULL: goto x86_l_2609;
	case 9742ULL: goto x86_l_260e;
	case 9744ULL: goto x86_l_2610;
	case 9746ULL: goto x86_l_2612;
	case 9748ULL: goto x86_l_2614;
	case 9751ULL: goto x86_l_2617;
	case 9754ULL: goto x86_l_261a;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9763ULL: goto x86_l_2623;
	case 9768ULL: goto x86_l_2628;
	case 9774ULL: goto x86_l_262e;
	case 9778ULL: goto x86_l_2632;
	case 9783ULL: goto x86_l_2637;
	case 9785ULL: goto x86_l_2639;
	case 9792ULL: goto x86_l_2640;
	case 9796ULL: goto x86_l_2644;
	case 9800ULL: goto x86_l_2648;
	case 9803ULL: goto x86_l_264b;
	case 9808ULL: goto x86_l_2650;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9817ULL: goto x86_l_2659;
	case 9819ULL: goto x86_l_265b;
	case 9823ULL: goto x86_l_265f;
	case 9825ULL: goto x86_l_2661;
	case 9830ULL: goto x86_l_2666;
	case 9832ULL: goto x86_l_2668;
	case 9834ULL: goto x86_l_266a;
	case 9838ULL: goto x86_l_266e;
	case 9848ULL: goto x86_l_2678;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9860ULL: goto x86_l_2684;
	case 9863ULL: goto x86_l_2687;
	case 9866ULL: goto x86_l_268a;
	case 9870ULL: goto x86_l_268e;
	case 9875ULL: goto x86_l_2693;
	case 9879ULL: goto x86_l_2697;
	case 9883ULL: goto x86_l_269b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_20a6:
	/* 0x20a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20ab:
	/* 0x20ab: mov    rdi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_20b2:
	/* 0x20b2: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20b7:
	/* 0x20b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b9:
	/* 0x20b9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20bc:
	/* 0x20bc: je     20c9 <tail_handle_ipv4+0x20c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_20c9;
	}
x86_l_20be:
	/* 0x20be: mov    esi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 10ULL);
x86_l_20c3:
	/* 0x20c3: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_20c7:
	/* 0x20c7: jne    2138 <tail_handle_ipv4+0x2138> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2138;
	}
x86_l_20c9:
	/* 0x20c9: movzx  ebp,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_20d0:
	/* 0x20d0: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_20d5:
	/* 0x20d5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d8:
	/* 0x20d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_20db:
	/* 0x20db: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_20e0:
	/* 0x20e0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e2:
	/* 0x20e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e4:
	/* 0x20e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20e6:
	/* 0x20e6: jne    1e71 <tail_handle_ipv4+0x1e71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7793ULL;
	}
x86_l_20ec:
	/* 0x20ec: mov    WORD PTR [rsp+0x40],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20f1:
	/* 0x20f1: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_20f6:
	/* 0x20f6: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20fb:
	/* 0x20fb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20fe:
	/* 0x20fe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2101:
	/* 0x2101: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2106:
	/* 0x2106: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_210b:
	/* 0x210b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_210e:
	/* 0x210e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2110:
	/* 0x2110: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2112:
	/* 0x2112: js     2163 <tail_handle_ipv4+0x2163> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2163;
	}
x86_l_2114:
	/* 0x2114: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2117:
	/* 0x2117: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_211a:
	/* 0x211a: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_211d:
	/* 0x211d: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_2122:
	/* 0x2122: jb     1e76 <tail_handle_ipv4+0x1e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7798ULL;
	}
x86_l_2128:
	/* 0x2128: mov    rbp,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_212f:
	/* 0x212f: add    rbp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_2133:
	/* 0x2133: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_2138:
	/* 0x2138: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_213b:
	/* 0x213b: mov    rcx,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_213f:
	/* 0x213f: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2144:
	/* 0x2144: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2148:
	/* 0x2148: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_214d:
	/* 0x214d: movzx  edx,BYTE PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2151:
	/* 0x2151: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_2156:
	/* 0x2156: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2159:
	/* 0x2159: jae    216d <tail_handle_ipv4+0x216d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_216d;
	}
x86_l_215b:
	/* 0x215b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_215e:
	/* 0x215e: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_2163:
	/* 0x2163: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_2168:
	/* 0x2168: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_216d:
	/* 0x216d: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2170:
	/* 0x2170: mov    BYTE PTR [rbp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2173:
	/* 0x2173: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2176:
	/* 0x2176: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_217b:
	/* 0x217b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_217e:
	/* 0x217e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_2184:
	/* 0x2184: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2186:
	/* 0x2186: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2188:
	/* 0x2188: js     2217 <tail_handle_ipv4+0x2217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2217;
	}
x86_l_218e:
	/* 0x218e: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2193:
	/* 0x2193: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2198:
	/* 0x2198: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_219b:
	/* 0x219b: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_21a0:
	/* 0x21a0: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_21a5:
	/* 0x21a5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a8:
	/* 0x21a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21aa:
	/* 0x21aa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_21ac:
	/* 0x21ac: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_21b1:
	/* 0x21b1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_21b3:
	/* 0x21b3: js     215b <tail_handle_ipv4+0x215b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_215b;
	}
x86_l_21b5:
	/* 0x21b5: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_21ba:
	/* 0x21ba: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_21bf:
	/* 0x21bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21c2:
	/* 0x21c2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21c4:
	/* 0x21c4: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_21c9:
	/* 0x21c9: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21cc:
	/* 0x21cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21ce:
	/* 0x21ce: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_21d0:
	/* 0x21d0: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_21d5:
	/* 0x21d5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_21d7:
	/* 0x21d7: js     215b <tail_handle_ipv4+0x215b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_215b;
	}
x86_l_21d9:
	/* 0x21d9: movzx  edx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_21de:
	/* 0x21de: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_21e5:
	/* 0x21e5: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21e8:
	/* 0x21e8: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21ec:
	/* 0x21ec: mov    QWORD PTR [rbx+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_21f4:
	/* 0x21f4: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_21fc:
	/* 0x21fc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2201:
	/* 0x2201: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_call_policy)));
x86_l_2208:
	/* 0x2208: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_220b:
	/* 0x220b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220d:
	/* 0x220d: mov    eax,0xffffff35 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967093ULL);
x86_l_2212:
	/* 0x2212: jmp    215b <tail_handle_ipv4+0x215b> */
	goto x86_l_215b;
x86_l_2217:
	/* 0x2217: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_221c:
	/* 0x221c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_221f:
	/* 0x221f: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_2224:
	/* 0x2224: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_2229:
	/* 0x2229: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222c:
	/* 0x222c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222e:
	/* 0x222e: js     1e76 <tail_handle_ipv4+0x1e76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 7798ULL;
	}
x86_l_2234:
	/* 0x2234: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2237:
	/* 0x2237: jne    1f21 <tail_handle_ipv4+0x1f21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7969ULL;
	}
x86_l_223d:
	/* 0x223d: jmp    1e76 <tail_handle_ipv4+0x1e76> */
	return 7798ULL;
x86_l_2242:
	/* 0x2242: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2245:
	/* 0x2245: mov    edi,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967155ULL);
x86_l_224a:
	/* 0x224a: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_224f:
	/* 0x224f: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2253:
	/* 0x2253: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2258:
	/* 0x2258: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_225a:
	/* 0x225a: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_225c:
	/* 0x225c: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_225e:
	/* 0x225e: je     235a <tail_handle_ipv4+0x235a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235a;
	}
x86_l_2264:
	/* 0x2264: mov    r15,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_226b:
	/* 0x226b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_226f:
	/* 0x226f: je     2280 <tail_handle_ipv4+0x2280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2280;
	}
x86_l_2271:
	/* 0x2271: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2278:
	/* 0x2278: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_227b:
	/* 0x227b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_227e:
	/* 0x227e: jmp    2285 <tail_handle_ipv4+0x2285> */
	goto x86_l_2285;
x86_l_2280:
	/* 0x2280: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_2285:
	/* 0x2285: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_2289:
	/* 0x2289: jne    22c5 <tail_handle_ipv4+0x22c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22c5;
	}
x86_l_228b:
	/* 0x228b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_228f:
	/* 0x228f: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2291:
	/* 0x2291: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2294:
	/* 0x2294: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2297:
	/* 0x2297: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2299:
	/* 0x2299: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229e:
	/* 0x229e: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22a2:
	/* 0x22a2: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_22a5:
	/* 0x22a5: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_22aa:
	/* 0x22aa: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_22af:
	/* 0x22af: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_22b2:
	/* 0x22b2: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22b6:
	/* 0x22b6: je     22c5 <tail_handle_ipv4+0x22c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c5;
	}
x86_l_22b8:
	/* 0x22b8: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_22bf:
	/* 0x22bf: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_22c2:
	/* 0x22c2: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_22c5:
	/* 0x22c5: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ca:
	/* 0x22ca: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_22ce:
	/* 0x22ce: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22d2:
	/* 0x22d2: je     22e3 <tail_handle_ipv4+0x22e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22e3;
	}
x86_l_22d4:
	/* 0x22d4: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_22d9:
	/* 0x22d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22db:
	/* 0x22db: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_22dd:
	/* 0x22dd: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_22e1:
	/* 0x22e1: jmp    2306 <tail_handle_ipv4+0x2306> */
	goto x86_l_2306;
x86_l_22e3:
	/* 0x22e3: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_22e8:
	/* 0x22e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22ea:
	/* 0x22ea: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_22ec:
	/* 0x22ec: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_22f0:
	/* 0x22f0: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_22fa:
	/* 0x22fa: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_22fd:
	/* 0x22fd: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2302:
	/* 0x2302: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2306:
	/* 0x2306: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2308:
	/* 0x2308: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_230d:
	/* 0x230d: mov    DWORD PTR [rdx+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2310:
	/* 0x2310: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2314:
	/* 0x2314: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2317:
	/* 0x2317: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_231b:
	/* 0x231b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_231f:
	/* 0x231f: je     2332 <tail_handle_ipv4+0x2332> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2332;
	}
x86_l_2321:
	/* 0x2321: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2328:
	/* 0x2328: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_232a:
	/* 0x232a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_232d:
	/* 0x232d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2330:
	/* 0x2330: jmp    2337 <tail_handle_ipv4+0x2337> */
	goto x86_l_2337;
x86_l_2332:
	/* 0x2332: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2337:
	/* 0x2337: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2339:
	/* 0x2339: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_233c:
	/* 0x233c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_233e:
	/* 0x233e: jb     2345 <tail_handle_ipv4+0x2345> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2345;
	}
x86_l_2340:
	/* 0x2340: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_2343:
	/* 0x2343: je     235a <tail_handle_ipv4+0x235a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_235a;
	}
x86_l_2345:
	/* 0x2345: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_234a:
	/* 0x234a: mov    BYTE PTR [rcx+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_234e:
	/* 0x234e: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2351:
	/* 0x2351: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2358:
	/* 0x2358: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_235a:
	/* 0x235a: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2361:
	/* 0x2361: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2364:
	/* 0x2364: je     2378 <tail_handle_ipv4+0x2378> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2378;
	}
x86_l_2366:
	/* 0x2366: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236b:
	/* 0x236b: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_2370:
	/* 0x2370: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2373:
	/* 0x2373: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2378:
	/* 0x2378: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_237c:
	/* 0x237c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_237f:
	/* 0x237f: je     23d2 <tail_handle_ipv4+0x23d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23d2;
	}
x86_l_2381:
	/* 0x2381: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2384:
	/* 0x2384: jne    24cd <tail_handle_ipv4+0x24cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24cd;
	}
x86_l_238a:
	/* 0x238a: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_238f:
	/* 0x238f: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2393:
	/* 0x2393: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_2395:
	/* 0x2395: je     24cd <tail_handle_ipv4+0x24cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_239b:
	/* 0x239b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23a0:
	/* 0x23a0: mov    WORD PTR [rcx+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_23a6:
	/* 0x23a6: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_23ab:
	/* 0x23ab: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23af:
	/* 0x23af: mov    r15,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_23b6:
	/* 0x23b6: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23ba:
	/* 0x23ba: je     26e2 <tail_handle_ipv4+0x26e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9954ULL;
	}
x86_l_23c0:
	/* 0x23c0: mov    rcx,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_23c7:
	/* 0x23c7: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_23ca:
	/* 0x23ca: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_23cd:
	/* 0x23cd: jmp    26e7 <tail_handle_ipv4+0x26e7> */
	return 9959ULL;
x86_l_23d2:
	/* 0x23d2: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23d6:
	/* 0x23d6: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_23db:
	/* 0x23db: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23de:
	/* 0x23de: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_23e2:
	/* 0x23e2: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_23e6:
	/* 0x23e6: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23eb:
	/* 0x23eb: or     ax,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_23ef:
	/* 0x23ef: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_23f3:
	/* 0x23f3: mov    r15,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_23fa:
	/* 0x23fa: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23fd:
	/* 0x23fd: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_23ff:
	/* 0x23ff: je     24cd <tail_handle_ipv4+0x24cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_2405:
	/* 0x2405: mov    rbp,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_240c:
	/* 0x240c: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2410:
	/* 0x2410: je     2427 <tail_handle_ipv4+0x2427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2427;
	}
x86_l_2412:
	/* 0x2412: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2419:
	/* 0x2419: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_241b:
	/* 0x241b: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_241d:
	/* 0x241d: lea    r14d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2421:
	/* 0x2421: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2425:
	/* 0x2425: jmp    242d <tail_handle_ipv4+0x242d> */
	goto x86_l_242d;
x86_l_2427:
	/* 0x2427: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_242d:
	/* 0x242d: shr    DWORD PTR [rsp+0x8],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 34359738376ULL);
x86_l_2432:
	/* 0x2432: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2436:
	/* 0x2436: je     2447 <tail_handle_ipv4+0x2447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2447;
	}
x86_l_2438:
	/* 0x2438: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_243d:
	/* 0x243d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_243f:
	/* 0x243f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2441:
	/* 0x2441: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2445:
	/* 0x2445: jmp    246a <tail_handle_ipv4+0x246a> */
	goto x86_l_246a;
x86_l_2447:
	/* 0x2447: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_244c:
	/* 0x244c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_244e:
	/* 0x244e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2450:
	/* 0x2450: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2454:
	/* 0x2454: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_245e:
	/* 0x245e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2461:
	/* 0x2461: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2466:
	/* 0x2466: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_246a:
	/* 0x246a: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_246d:
	/* 0x246d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2472:
	/* 0x2472: mov    DWORD PTR [rdx+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2476:
	/* 0x2476: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_247a:
	/* 0x247a: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_247d:
	/* 0x247d: mov    esi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2481:
	/* 0x2481: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2485:
	/* 0x2485: mov    DWORD PTR [rsp+0x8],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2489:
	/* 0x2489: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248d:
	/* 0x248d: je     24a0 <tail_handle_ipv4+0x24a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24a0;
	}
x86_l_248f:
	/* 0x248f: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2496:
	/* 0x2496: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2498:
	/* 0x2498: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_249b:
	/* 0x249b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_249e:
	/* 0x249e: jmp    24a5 <tail_handle_ipv4+0x24a5> */
	goto x86_l_24a5;
x86_l_24a0:
	/* 0x24a0: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_24a5:
	/* 0x24a5: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24a7:
	/* 0x24a7: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24ab:
	/* 0x24ab: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_24ad:
	/* 0x24ad: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24b1:
	/* 0x24b1: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_24b3:
	/* 0x24b3: jb     24bb <tail_handle_ipv4+0x24bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24bb;
	}
x86_l_24b5:
	/* 0x24b5: cmp    cl,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_24b9:
	/* 0x24b9: je     24cd <tail_handle_ipv4+0x24cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_24bb:
	/* 0x24bb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24c0:
	/* 0x24c0: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c4:
	/* 0x24c4: mov    BYTE PTR [rcx+0x2a],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_24c7:
	/* 0x24c7: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24ca:
	/* 0x24ca: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24cd:
	/* 0x24cd: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24d2:
	/* 0x24d2: cmp    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_24db:
	/* 0x24db: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_24e0:
	/* 0x24e0: jne    1df4 <tail_handle_ipv4+0x1df4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7668ULL;
	}
x86_l_24e6:
	/* 0x24e6: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_24ef:
	/* 0x24ef: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_24f2:
	/* 0x24f2: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_24f5:
	/* 0x24f5: mov    edi,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967162ULL);
x86_l_24fa:
	/* 0x24fa: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_24fd:
	/* 0x24fd: jb     1946 <tail_handle_ipv4+0x1946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6470ULL;
	}
x86_l_2503:
	/* 0x2503: mov    r15,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_250a:
	/* 0x250a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_250f:
	/* 0x250f: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2514:
	/* 0x2514: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2517:
	/* 0x2517: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_251c:
	/* 0x251c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_2521:
	/* 0x2521: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2523:
	/* 0x2523: mov    edi,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967162ULL);
x86_l_2528:
	/* 0x2528: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_252a:
	/* 0x252a: js     1946 <tail_handle_ipv4+0x1946> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 6470ULL;
	}
x86_l_2530:
	/* 0x2530: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2535:
	/* 0x2535: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_2539:
	/* 0x2539: mov    rdi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_2540:
	/* 0x2540: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2543:
	/* 0x2543: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2545:
	/* 0x2545: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2548:
	/* 0x2548: je     2560 <tail_handle_ipv4+0x2560> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2560;
	}
x86_l_254a:
	/* 0x254a: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_254e:
	/* 0x254e: xor    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 0ULL);
x86_l_2550:
	/* 0x2550: movzx  edx,WORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 68ULL);
x86_l_2555:
	/* 0x2555: xor    dx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 4ULL);
x86_l_2559:
	/* 0x2559: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_255c:
	/* 0x255c: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_255e:
	/* 0x255e: je     257c <tail_handle_ipv4+0x257c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257c;
	}
x86_l_2560:
	/* 0x2560: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2565:
	/* 0x2565: mov    rdi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_256c:
	/* 0x256c: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2571:
	/* 0x2571: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_2574:
	/* 0x2574: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2576:
	/* 0x2576: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2578:
	/* 0x2578: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_257a:
	/* 0x257a: js     25e2 <tail_handle_ipv4+0x25e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25e2;
	}
x86_l_257c:
	/* 0x257c: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2581:
	/* 0x2581: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_2585:
	/* 0x2585: js     25ae <tail_handle_ipv4+0x25ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25ae;
	}
x86_l_2587:
	/* 0x2587: mov    QWORD PTR [rbx+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_258f:
	/* 0x258f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2594:
	/* 0x2594: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_259b:
	/* 0x259b: mov    r14d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 15ULL);
x86_l_25a1:
	/* 0x25a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25a4:
	/* 0x25a4: mov    edx,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 15ULL);
x86_l_25a9:
	/* 0x25a9: jmp    15df <tail_handle_ipv4+0x15df> */
	return 5599ULL;
x86_l_25ae:
	/* 0x25ae: movzx  eax,WORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 140ULL);
x86_l_25b6:
	/* 0x25b6: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25b9:
	/* 0x25b9: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_25c0:
	/* 0x25c0: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_25c3:
	/* 0x25c3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_25c8:
	/* 0x25c8: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_25cf:
	/* 0x25cf: mov    r14d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21ULL);
x86_l_25d5:
	/* 0x25d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25d8:
	/* 0x25d8: mov    edx,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_25dd:
	/* 0x25dd: jmp    15df <tail_handle_ipv4+0x15df> */
	return 5599ULL;
x86_l_25e2:
	/* 0x25e2: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_25e4:
	/* 0x25e4: jmp    1946 <tail_handle_ipv4+0x1946> */
	return 6470ULL;
x86_l_25e9:
	/* 0x25e9: mov    edi,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4294967141ULL);
x86_l_25ee:
	/* 0x25ee: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_25f1:
	/* 0x25f1: jmp    1949 <tail_handle_ipv4+0x1949> */
	return 6473ULL;
x86_l_25f6:
	/* 0x25f6: mov    DWORD PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_25fe:
	/* 0x25fe: jmp    1bec <tail_handle_ipv4+0x1bec> */
	return 7148ULL;
x86_l_2603:
	/* 0x2603: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_2609:
	/* 0x2609: cmp    BYTE PTR [rsp+0x2],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8589934598ULL);
x86_l_260e:
	/* 0x260e: jne    2648 <tail_handle_ipv4+0x2648> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2648;
	}
x86_l_2610:
	/* 0x2610: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2612:
	/* 0x2612: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2614:
	/* 0x2614: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2617:
	/* 0x2617: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_261a:
	/* 0x261a: or     edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_261c:
	/* 0x261c: mov    WORD PTR [r14+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2621:
	/* 0x2621: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2623:
	/* 0x2623: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2628:
	/* 0x2628: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_262e:
	/* 0x262e: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2632:
	/* 0x2632: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2637:
	/* 0x2637: je     2648 <tail_handle_ipv4+0x2648> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2648;
	}
x86_l_2639:
	/* 0x2639: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2640:
	/* 0x2640: imul   r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2644:
	/* 0x2644: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2648:
	/* 0x2648: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_264b:
	/* 0x264b: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2650:
	/* 0x2650: je     2661 <tail_handle_ipv4+0x2661> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2661;
	}
x86_l_2652:
	/* 0x2652: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2657:
	/* 0x2657: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2659:
	/* 0x2659: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_265b:
	/* 0x265b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_265f:
	/* 0x265f: jmp    2684 <tail_handle_ipv4+0x2684> */
	goto x86_l_2684;
x86_l_2661:
	/* 0x2661: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2666:
	/* 0x2666: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2668:
	/* 0x2668: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_266a:
	/* 0x266a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_266e:
	/* 0x266e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2678:
	/* 0x2678: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_267b:
	/* 0x267b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2680:
	/* 0x2680: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2684:
	/* 0x2684: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2687:
	/* 0x2687: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_268a:
	/* 0x268a: mov    DWORD PTR [r14+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_268e:
	/* 0x268e: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2693:
	/* 0x2693: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2697:
	/* 0x2697: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_269b:
	/* 0x269b: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
	return 9888ULL;
}

static __noinline __u64 cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9888ULL: goto x86_l_26a0;
	case 9890ULL: goto x86_l_26a2;
	case 9897ULL: goto x86_l_26a9;
	case 9899ULL: goto x86_l_26ab;
	case 9902ULL: goto x86_l_26ae;
	case 9905ULL: goto x86_l_26b1;
	case 9907ULL: goto x86_l_26b3;
	case 9912ULL: goto x86_l_26b8;
	case 9914ULL: goto x86_l_26ba;
	case 9917ULL: goto x86_l_26bd;
	case 9919ULL: goto x86_l_26bf;
	case 9924ULL: goto x86_l_26c4;
	case 9930ULL: goto x86_l_26ca;
	case 9932ULL: goto x86_l_26cc;
	case 9935ULL: goto x86_l_26cf;
	case 9941ULL: goto x86_l_26d5;
	case 9945ULL: goto x86_l_26d9;
	case 9949ULL: goto x86_l_26dd;
	case 9954ULL: goto x86_l_26e2;
	case 9959ULL: goto x86_l_26e7;
	case 9963ULL: goto x86_l_26eb;
	case 9965ULL: goto x86_l_26ed;
	case 9969ULL: goto x86_l_26f1;
	case 9971ULL: goto x86_l_26f3;
	case 9974ULL: goto x86_l_26f6;
	case 9977ULL: goto x86_l_26f9;
	case 9979ULL: goto x86_l_26fb;
	case 9984ULL: goto x86_l_2700;
	case 9988ULL: goto x86_l_2704;
	case 9990ULL: goto x86_l_2706;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10003ULL: goto x86_l_2713;
	case 10007ULL: goto x86_l_2717;
	case 10009ULL: goto x86_l_2719;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10022ULL: goto x86_l_2726;
	case 10027ULL: goto x86_l_272b;
	case 10031ULL: goto x86_l_272f;
	case 10033ULL: goto x86_l_2731;
	case 10038ULL: goto x86_l_2736;
	case 10040ULL: goto x86_l_2738;
	case 10042ULL: goto x86_l_273a;
	case 10046ULL: goto x86_l_273e;
	case 10048ULL: goto x86_l_2740;
	case 10053ULL: goto x86_l_2745;
	case 10055ULL: goto x86_l_2747;
	case 10057ULL: goto x86_l_2749;
	case 10061ULL: goto x86_l_274d;
	case 10071ULL: goto x86_l_2757;
	case 10074ULL: goto x86_l_275a;
	case 10079ULL: goto x86_l_275f;
	case 10083ULL: goto x86_l_2763;
	case 10085ULL: goto x86_l_2765;
	case 10090ULL: goto x86_l_276a;
	case 10093ULL: goto x86_l_276d;
	case 10097ULL: goto x86_l_2771;
	case 10100ULL: goto x86_l_2774;
	case 10104ULL: goto x86_l_2778;
	case 10108ULL: goto x86_l_277c;
	case 10112ULL: goto x86_l_2780;
	case 10116ULL: goto x86_l_2784;
	case 10118ULL: goto x86_l_2786;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10130ULL: goto x86_l_2792;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10140ULL: goto x86_l_279c;
	case 10142ULL: goto x86_l_279e;
	case 10146ULL: goto x86_l_27a2;
	case 10148ULL: goto x86_l_27a4;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10159ULL: goto x86_l_27af;
	case 10161ULL: goto x86_l_27b1;
	case 10165ULL: goto x86_l_27b5;
	case 10171ULL: goto x86_l_27bb;
	case 10176ULL: goto x86_l_27c0;
	case 10180ULL: goto x86_l_27c4;
	case 10183ULL: goto x86_l_27c7;
	case 10186ULL: goto x86_l_27ca;
	case 10191ULL: goto x86_l_27cf;
	case 10193ULL: goto x86_l_27d1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_26a0:
	/* 0x26a0: je     26b3 <tail_handle_ipv4+0x26b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b3;
	}
x86_l_26a2:
	/* 0x26a2: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_26a9:
	/* 0x26a9: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ab:
	/* 0x26ab: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_26ae:
	/* 0x26ae: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_26b1:
	/* 0x26b1: jmp    26b8 <tail_handle_ipv4+0x26b8> */
	goto x86_l_26b8;
x86_l_26b3:
	/* 0x26b3: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_26b8:
	/* 0x26b8: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26ba:
	/* 0x26ba: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_26bd:
	/* 0x26bd: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_26bf:
	/* 0x26bf: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_26c4:
	/* 0x26c4: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_26ca:
	/* 0x26ca: jb     26d5 <tail_handle_ipv4+0x26d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26d5;
	}
x86_l_26cc:
	/* 0x26cc: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_26cf:
	/* 0x26cf: je     996 <tail_handle_ipv4+0x996> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2454ULL;
	}
x86_l_26d5:
	/* 0x26d5: mov    BYTE PTR [r14+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_26d9:
	/* 0x26d9: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26dd:
	/* 0x26dd: jmp    98d <tail_handle_ipv4+0x98d> */
	return 2445ULL;
x86_l_26e2:
	/* 0x26e2: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_26e7:
	/* 0x26e7: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_26eb:
	/* 0x26eb: jne    2726 <tail_handle_ipv4+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2726;
	}
x86_l_26ed:
	/* 0x26ed: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26f1:
	/* 0x26f1: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_26f3:
	/* 0x26f3: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_26f6:
	/* 0x26f6: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_26f9:
	/* 0x26f9: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_26fb:
	/* 0x26fb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2700:
	/* 0x2700: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2704:
	/* 0x2704: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2706:
	/* 0x2706: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_270b:
	/* 0x270b: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_2710:
	/* 0x2710: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2713:
	/* 0x2713: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2717:
	/* 0x2717: je     2726 <tail_handle_ipv4+0x2726> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2726;
	}
x86_l_2719:
	/* 0x2719: mov    rax,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2720:
	/* 0x2720: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2723:
	/* 0x2723: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2726:
	/* 0x2726: shr    DWORD PTR [rsp+0x8],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 34359738376ULL);
x86_l_272b:
	/* 0x272b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_272f:
	/* 0x272f: je     2740 <tail_handle_ipv4+0x2740> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2740;
	}
x86_l_2731:
	/* 0x2731: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2736:
	/* 0x2736: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2738:
	/* 0x2738: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_273a:
	/* 0x273a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_273e:
	/* 0x273e: jmp    2763 <tail_handle_ipv4+0x2763> */
	goto x86_l_2763;
x86_l_2740:
	/* 0x2740: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2745:
	/* 0x2745: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2747:
	/* 0x2747: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2749:
	/* 0x2749: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_274d:
	/* 0x274d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2757:
	/* 0x2757: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_275a:
	/* 0x275a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_275f:
	/* 0x275f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2763:
	/* 0x2763: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2765:
	/* 0x2765: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_276a:
	/* 0x276a: mov    DWORD PTR [rdx+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_276d:
	/* 0x276d: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2771:
	/* 0x2771: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2774:
	/* 0x2774: mov    esi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2778:
	/* 0x2778: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_277c:
	/* 0x277c: mov    DWORD PTR [rsp+0x8],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2780:
	/* 0x2780: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2784:
	/* 0x2784: je     2797 <tail_handle_ipv4+0x2797> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2797;
	}
x86_l_2786:
	/* 0x2786: mov    rsi,QWORD PTR [rip+0x69a8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_278d:
	/* 0x278d: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278f:
	/* 0x278f: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2792:
	/* 0x2792: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2795:
	/* 0x2795: jmp    279c <tail_handle_ipv4+0x279c> */
	goto x86_l_279c;
x86_l_2797:
	/* 0x2797: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_279c:
	/* 0x279c: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_279e:
	/* 0x279e: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a2:
	/* 0x27a2: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_27a4:
	/* 0x27a4: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27a8:
	/* 0x27a8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_27aa:
	/* 0x27aa: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27af:
	/* 0x27af: jb     27bb <tail_handle_ipv4+0x27bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_27bb;
	}
x86_l_27b1:
	/* 0x27b1: cmp    cl,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_27b5:
	/* 0x27b5: je     1c43 <tail_handle_ipv4+0x1c43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7235ULL;
	}
x86_l_27bb:
	/* 0x27bb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27c0:
	/* 0x27c0: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27c4:
	/* 0x27c4: mov    BYTE PTR [rcx+0x2a],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_27c7:
	/* 0x27c7: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27ca:
	/* 0x27ca: jmp    1c3a <tail_handle_ipv4+0x1c3a> */
	return 7226ULL;
x86_l_27cf:
	/* 0x27cf: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_27d1:
	/* 0x27d1: jmp    1946 <tail_handle_ipv4+0x1946> */
	return 6470ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_wireguard_tail_handle_ipv4_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9556U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1874ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1876ULL && __x86_pc <= 3466ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3468ULL && __x86_pc <= 5047ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5049ULL && __x86_pc <= 6685ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6689ULL && __x86_pc <= 8354ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8358ULL && __x86_pc <= 9883ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9888ULL && __x86_pc <= 10193ULL)
			__x86_pc = cilium_bpf_wireguard_tail_handle_ipv4_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

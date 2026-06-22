extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_hash_init6_seed;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_supports_fib_lookup_src;
extern char __config_trace_payload_len;
extern char __config_tunnel_port;
extern char __config_tunnel_protocol;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_egress_gw_policy_v6;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
extern char cilium_nodeport_neigh4;
extern char cilium_nodeport_neigh6;
extern char cilium_snat_v6_external;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 20ULL: goto x86_l_14;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 33ULL: goto x86_l_21;
	case 41ULL: goto x86_l_29;
	case 48ULL: goto x86_l_30;
	case 53ULL: goto x86_l_35;
	case 58ULL: goto x86_l_3a;
	case 60ULL: goto x86_l_3c;
	case 63ULL: goto x86_l_3f;
	case 69ULL: goto x86_l_45;
	case 71ULL: goto x86_l_47;
	case 78ULL: goto x86_l_4e;
	case 90ULL: goto x86_l_5a;
	case 102ULL: goto x86_l_66;
	case 114ULL: goto x86_l_72;
	case 126ULL: goto x86_l_7e;
	case 135ULL: goto x86_l_87;
	case 138ULL: goto x86_l_8a;
	case 142ULL: goto x86_l_8e;
	case 146ULL: goto x86_l_92;
	case 149ULL: goto x86_l_95;
	case 155ULL: goto x86_l_9b;
	case 159ULL: goto x86_l_9f;
	case 162ULL: goto x86_l_a2;
	case 168ULL: goto x86_l_a8;
	case 172ULL: goto x86_l_ac;
	case 178ULL: goto x86_l_b2;
	case 183ULL: goto x86_l_b7;
	case 193ULL: goto x86_l_c1;
	case 197ULL: goto x86_l_c5;
	case 199ULL: goto x86_l_c7;
	case 203ULL: goto x86_l_cb;
	case 206ULL: goto x86_l_ce;
	case 212ULL: goto x86_l_d4;
	case 216ULL: goto x86_l_d8;
	case 219ULL: goto x86_l_db;
	case 223ULL: goto x86_l_df;
	case 226ULL: goto x86_l_e2;
	case 228ULL: goto x86_l_e4;
	case 231ULL: goto x86_l_e7;
	case 233ULL: goto x86_l_e9;
	case 236ULL: goto x86_l_ec;
	case 242ULL: goto x86_l_f2;
	case 246ULL: goto x86_l_f6;
	case 254ULL: goto x86_l_fe;
	case 258ULL: goto x86_l_102;
	case 264ULL: goto x86_l_108;
	case 268ULL: goto x86_l_10c;
	case 271ULL: goto x86_l_10f;
	case 277ULL: goto x86_l_115;
	case 279ULL: goto x86_l_117;
	case 283ULL: goto x86_l_11b;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 300ULL: goto x86_l_12c;
	case 304ULL: goto x86_l_130;
	case 307ULL: goto x86_l_133;
	case 313ULL: goto x86_l_139;
	case 316ULL: goto x86_l_13c;
	case 322ULL: goto x86_l_142;
	case 325ULL: goto x86_l_145;
	case 331ULL: goto x86_l_14b;
	case 341ULL: goto x86_l_155;
	case 344ULL: goto x86_l_158;
	case 347ULL: goto x86_l_15b;
	case 357ULL: goto x86_l_165;
	case 360ULL: goto x86_l_168;
	case 366ULL: goto x86_l_16e;
	case 370ULL: goto x86_l_172;
	case 380ULL: goto x86_l_17c;
	case 383ULL: goto x86_l_17f;
	case 389ULL: goto x86_l_185;
	case 393ULL: goto x86_l_189;
	case 395ULL: goto x86_l_18b;
	case 403ULL: goto x86_l_193;
	case 406ULL: goto x86_l_196;
	case 410ULL: goto x86_l_19a;
	case 414ULL: goto x86_l_19e;
	case 420ULL: goto x86_l_1a4;
	case 424ULL: goto x86_l_1a8;
	case 428ULL: goto x86_l_1ac;
	case 430ULL: goto x86_l_1ae;
	case 434ULL: goto x86_l_1b2;
	case 438ULL: goto x86_l_1b6;
	case 442ULL: goto x86_l_1ba;
	case 446ULL: goto x86_l_1be;
	case 449ULL: goto x86_l_1c1;
	case 455ULL: goto x86_l_1c7;
	case 458ULL: goto x86_l_1ca;
	case 462ULL: goto x86_l_1ce;
	case 465ULL: goto x86_l_1d1;
	case 469ULL: goto x86_l_1d5;
	case 473ULL: goto x86_l_1d9;
	case 475ULL: goto x86_l_1db;
	case 479ULL: goto x86_l_1df;
	case 481ULL: goto x86_l_1e1;
	case 485ULL: goto x86_l_1e5;
	case 487ULL: goto x86_l_1e7;
	case 491ULL: goto x86_l_1eb;
	case 499ULL: goto x86_l_1f3;
	case 504ULL: goto x86_l_1f8;
	case 506ULL: goto x86_l_1fa;
	case 510ULL: goto x86_l_1fe;
	case 516ULL: goto x86_l_204;
	case 521ULL: goto x86_l_209;
	case 529ULL: goto x86_l_211;
	case 533ULL: goto x86_l_215;
	case 535ULL: goto x86_l_217;
	case 537ULL: goto x86_l_219;
	case 543ULL: goto x86_l_21f;
	case 547ULL: goto x86_l_223;
	case 550ULL: goto x86_l_226;
	case 556ULL: goto x86_l_22c;
	case 559ULL: goto x86_l_22f;
	case 565ULL: goto x86_l_235;
	case 568ULL: goto x86_l_238;
	case 574ULL: goto x86_l_23e;
	case 584ULL: goto x86_l_248;
	case 587ULL: goto x86_l_24b;
	case 590ULL: goto x86_l_24e;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 609ULL: goto x86_l_261;
	case 613ULL: goto x86_l_265;
	case 623ULL: goto x86_l_26f;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 636ULL: goto x86_l_27c;
	case 639ULL: goto x86_l_27f;
	case 643ULL: goto x86_l_283;
	case 649ULL: goto x86_l_289;
	case 653ULL: goto x86_l_28d;
	case 657ULL: goto x86_l_291;
	case 663ULL: goto x86_l_297;
	case 667ULL: goto x86_l_29b;
	case 671ULL: goto x86_l_29f;
	case 675ULL: goto x86_l_2a3;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 688ULL: goto x86_l_2b0;
	case 691ULL: goto x86_l_2b3;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 702ULL: goto x86_l_2be;
	case 706ULL: goto x86_l_2c2;
	case 708ULL: goto x86_l_2c4;
	case 712ULL: goto x86_l_2c8;
	case 714ULL: goto x86_l_2ca;
	case 718ULL: goto x86_l_2ce;
	case 720ULL: goto x86_l_2d0;
	case 724ULL: goto x86_l_2d4;
	case 732ULL: goto x86_l_2dc;
	case 734ULL: goto x86_l_2de;
	case 742ULL: goto x86_l_2e6;
	case 746ULL: goto x86_l_2ea;
	case 748ULL: goto x86_l_2ec;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 760ULL: goto x86_l_2f8;
	case 763ULL: goto x86_l_2fb;
	case 769ULL: goto x86_l_301;
	case 772ULL: goto x86_l_304;
	case 778ULL: goto x86_l_30a;
	case 781ULL: goto x86_l_30d;
	case 787ULL: goto x86_l_313;
	case 797ULL: goto x86_l_31d;
	case 800ULL: goto x86_l_320;
	case 803ULL: goto x86_l_323;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 822ULL: goto x86_l_336;
	case 826ULL: goto x86_l_33a;
	case 836ULL: goto x86_l_344;
	case 839ULL: goto x86_l_347;
	case 845ULL: goto x86_l_34d;
	case 849ULL: goto x86_l_351;
	case 852ULL: goto x86_l_354;
	case 856ULL: goto x86_l_358;
	case 858ULL: goto x86_l_35a;
	case 862ULL: goto x86_l_35e;
	case 866ULL: goto x86_l_362;
	case 868ULL: goto x86_l_364;
	case 872ULL: goto x86_l_368;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 884ULL: goto x86_l_374;
	case 889ULL: goto x86_l_379;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 901ULL: goto x86_l_385;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 916ULL: goto x86_l_394;
	case 920ULL: goto x86_l_398;
	case 923ULL: goto x86_l_39b;
	case 926ULL: goto x86_l_39e;
	case 931ULL: goto x86_l_3a3;
	case 933ULL: goto x86_l_3a5;
	case 935ULL: goto x86_l_3a7;
	case 937ULL: goto x86_l_3a9;
	case 941ULL: goto x86_l_3ad;
	case 947ULL: goto x86_l_3b3;
	case 955ULL: goto x86_l_3bb;
	case 959ULL: goto x86_l_3bf;
	case 967ULL: goto x86_l_3c7;
	case 971ULL: goto x86_l_3cb;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 988ULL: goto x86_l_3dc;
	case 992ULL: goto x86_l_3e0;
	case 1000ULL: goto x86_l_3e8;
	case 1008ULL: goto x86_l_3f0;
	case 1012ULL: goto x86_l_3f4;
	case 1016ULL: goto x86_l_3f8;
	case 1018ULL: goto x86_l_3fa;
	case 1022ULL: goto x86_l_3fe;
	case 1025ULL: goto x86_l_401;
	case 1031ULL: goto x86_l_407;
	case 1034ULL: goto x86_l_40a;
	case 1040ULL: goto x86_l_410;
	case 1047ULL: goto x86_l_417;
	case 1050ULL: goto x86_l_41a;
	case 1056ULL: goto x86_l_420;
	case 1060ULL: goto x86_l_424;
	case 1064ULL: goto x86_l_428;
	case 1072ULL: goto x86_l_430;
	case 1076ULL: goto x86_l_434;
	case 1079ULL: goto x86_l_437;
	case 1083ULL: goto x86_l_43b;
	case 1086ULL: goto x86_l_43e;
	case 1091ULL: goto x86_l_443;
	case 1097ULL: goto x86_l_449;
	case 1100ULL: goto x86_l_44c;
	case 1104ULL: goto x86_l_450;
	case 1108ULL: goto x86_l_454;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1121ULL: goto x86_l_461;
	case 1127ULL: goto x86_l_467;
	case 1130ULL: goto x86_l_46a;
	case 1136ULL: goto x86_l_470;
	case 1142ULL: goto x86_l_476;
	case 1145ULL: goto x86_l_479;
	case 1151ULL: goto x86_l_47f;
	case 1157ULL: goto x86_l_485;
	case 1159ULL: goto x86_l_487;
	case 1164ULL: goto x86_l_48c;
	case 1166ULL: goto x86_l_48e;
	case 1170ULL: goto x86_l_492;
	case 1174ULL: goto x86_l_496;
	case 1178ULL: goto x86_l_49a;
	case 1183ULL: goto x86_l_49f;
	case 1186ULL: goto x86_l_4a2;
	case 1192ULL: goto x86_l_4a8;
	case 1195ULL: goto x86_l_4ab;
	case 1198ULL: goto x86_l_4ae;
	case 1201ULL: goto x86_l_4b1;
	case 1207ULL: goto x86_l_4b7;
	case 1210ULL: goto x86_l_4ba;
	case 1215ULL: goto x86_l_4bf;
	case 1221ULL: goto x86_l_4c5;
	case 1225ULL: goto x86_l_4c9;
	case 1233ULL: goto x86_l_4d1;
	case 1243ULL: goto x86_l_4db;
	case 1248ULL: goto x86_l_4e0;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1261ULL: goto x86_l_4ed;
	case 1264ULL: goto x86_l_4f0;
	case 1267ULL: goto x86_l_4f3;
	case 1271ULL: goto x86_l_4f7;
	case 1279ULL: goto x86_l_4ff;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1305ULL: goto x86_l_519;
	case 1312ULL: goto x86_l_520;
	case 1314ULL: goto x86_l_522;
	case 1322ULL: goto x86_l_52a;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1340ULL: goto x86_l_53c;
	case 1342ULL: goto x86_l_53e;
	case 1349ULL: goto x86_l_545;
	case 1357ULL: goto x86_l_54d;
	case 1364ULL: goto x86_l_554;
	case 1369ULL: goto x86_l_559;
	case 1375ULL: goto x86_l_55f;
	case 1378ULL: goto x86_l_562;
	case 1381ULL: goto x86_l_565;
	case 1383ULL: goto x86_l_567;
	case 1387ULL: goto x86_l_56b;
	case 1390ULL: goto x86_l_56e;
	case 1393ULL: goto x86_l_571;
	case 1401ULL: goto x86_l_579;
	case 1408ULL: goto x86_l_580;
	case 1413ULL: goto x86_l_585;
	case 1416ULL: goto x86_l_588;
	case 1419ULL: goto x86_l_58b;
	case 1421ULL: goto x86_l_58d;
	case 1428ULL: goto x86_l_594;
	case 1436ULL: goto x86_l_59c;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1454ULL: goto x86_l_5ae;
	case 1457ULL: goto x86_l_5b1;
	case 1460ULL: goto x86_l_5b4;
	case 1462ULL: goto x86_l_5b6;
	case 1469ULL: goto x86_l_5bd;
	case 1473ULL: goto x86_l_5c1;
	case 1476ULL: goto x86_l_5c4;
	case 1486ULL: goto x86_l_5ce;
	case 1494ULL: goto x86_l_5d6;
	case 1502ULL: goto x86_l_5de;
	case 1509ULL: goto x86_l_5e5;
	case 1517ULL: goto x86_l_5ed;
	case 1520ULL: goto x86_l_5f0;
	case 1523ULL: goto x86_l_5f3;
	case 1525ULL: goto x86_l_5f5;
	case 1528ULL: goto x86_l_5f8;
	case 1532ULL: goto x86_l_5fc;
	case 1534ULL: goto x86_l_5fe;
	case 1543ULL: goto x86_l_607;
	case 1548ULL: goto x86_l_60c;
	case 1555ULL: goto x86_l_613;
	case 1563ULL: goto x86_l_61b;
	case 1568ULL: goto x86_l_620;
	case 1573ULL: goto x86_l_625;
	case 1575ULL: goto x86_l_627;
	case 1577ULL: goto x86_l_629;
	case 1584ULL: goto x86_l_630;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1597ULL: goto x86_l_63d;
	case 1602ULL: goto x86_l_642;
	case 1604ULL: goto x86_l_644;
	case 1606ULL: goto x86_l_646;
	case 1613ULL: goto x86_l_64d;
	case 1615ULL: goto x86_l_64f;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1626ULL: goto x86_l_65a;
	case 1632ULL: goto x86_l_660;
	case 1636ULL: goto x86_l_664;
	case 1640ULL: goto x86_l_668;
	case 1644ULL: goto x86_l_66c;
	case 1649ULL: goto x86_l_671;
	case 1652ULL: goto x86_l_674;
	case 1658ULL: goto x86_l_67a;
	case 1661ULL: goto x86_l_67d;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1668ULL: goto x86_l_684;
	case 1670ULL: goto x86_l_686;
	case 1673ULL: goto x86_l_689;
	case 1675ULL: goto x86_l_68b;
	case 1682ULL: goto x86_l_692;
	case 1687ULL: goto x86_l_697;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1704ULL: goto x86_l_6a8;
	case 1712ULL: goto x86_l_6b0;
	case 1715ULL: goto x86_l_6b3;
	case 1723ULL: goto x86_l_6bb;
	case 1731ULL: goto x86_l_6c3;
	case 1735ULL: goto x86_l_6c7;
	case 1740ULL: goto x86_l_6cc;
	case 1744ULL: goto x86_l_6d0;
	case 1750ULL: goto x86_l_6d6;
	case 1755ULL: goto x86_l_6db;
	case 1762ULL: goto x86_l_6e2;
	case 1767ULL: goto x86_l_6e7;
	case 1773ULL: goto x86_l_6ed;
	case 1776ULL: goto x86_l_6f0;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_14:
	/* 0x14: movzx  r12d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18:
	/* 0x18: mov    rax,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f:
	/* 0x1f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21:
	/* 0x21: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_29:
	/* 0x29: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_30:
	/* 0x30: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35:
	/* 0x35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a:
	/* 0x3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     b80 <tail_nodeport_nat_ingress_ipv6+0xb80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2944ULL;
	}
x86_l_45:
	/* 0x45: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47:
	/* 0x47: mov    DWORD PTR [rsp+0xfc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 252ULL);
x86_l_4e:
	/* 0x4e: mov    QWORD PTR [rsp+0x96],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_5a:
	/* 0x5a: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_87:
	/* 0x87: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a:
	/* 0x8a: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e:
	/* 0x8e: lea    r9,[rax+0x36] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_92:
	/* 0x92: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_95:
	/* 0x95: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_9b:
	/* 0x9b: movzx  esi,BYTE PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_9f:
	/* 0x9f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a2:
	/* 0xa2: mov    r13d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 40ULL);
x86_l_a8:
	/* 0xa8: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_ac:
	/* 0xac: ja     3b3 <tail_nodeport_nat_ingress_ipv6+0x3b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3b3;
	}
x86_l_b2:
	/* 0xb2: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_b7:
	/* 0xb7: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_c1:
	/* 0xc1: bt     rdx,rsi */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_c5:
	/* 0xc5: jae    117 <tail_nodeport_nat_ingress_ipv6+0x117> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_117;
	}
x86_l_c7:
	/* 0xc7: lea    rdi,[rax+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cb:
	/* 0xcb: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_d4:
	/* 0xd4: movzx  edi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d8:
	/* 0xd8: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_db:
	/* 0xdb: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_df:
	/* 0xdf: cmp    esi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_e2:
	/* 0xe2: jle    f2 <tail_nodeport_nat_ingress_ipv6+0xf2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_f2;
	}
x86_l_e4:
	/* 0xe4: cmp    esi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_e7:
	/* 0xe7: je     126 <tail_nodeport_nat_ingress_ipv6+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_126;
	}
x86_l_e9:
	/* 0xe9: cmp    esi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 60ULL);
x86_l_ec:
	/* 0xec: jne    18b <tail_nodeport_nat_ingress_ipv6+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_18b;
	}
x86_l_f2:
	/* 0xf2: movzx  r8d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f6:
	/* 0xf6: lea    r8d,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_fe:
	/* 0xfe: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_102:
	/* 0x102: jne    193 <tail_nodeport_nat_ingress_ipv6+0x193> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_193;
	}
x86_l_108:
	/* 0x108: lea    rsi,[rax+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_10c:
	/* 0x10c: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_10f:
	/* 0x10f: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_115:
	/* 0x115: jmp    139 <tail_nodeport_nat_ingress_ipv6+0x139> */
	goto x86_l_139;
x86_l_117:
	/* 0x117: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_11b:
	/* 0x11b: je     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3699ULL;
	}
x86_l_121:
	/* 0x121: jmp    3b3 <tail_nodeport_nat_ingress_ipv6+0x3b3> */
	goto x86_l_3b3;
x86_l_126:
	/* 0x126: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_12c:
	/* 0x12c: lea    rsi,[rax+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_130:
	/* 0x130: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_133:
	/* 0x133: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_139:
	/* 0x139: mov    rsi,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c:
	/* 0x13c: rorx   r9,rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RSI, X86_WIDTH_64, 0, 32ULL);
x86_l_142:
	/* 0x142: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_145:
	/* 0x145: mov    r10d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 4294967295ULL);
x86_l_14b:
	/* 0x14b: movabs r11,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_64, 1095216660480ULL);
x86_l_155:
	/* 0x155: or     r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_158:
	/* 0x158: and    r9,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_AND);
x86_l_15b:
	/* 0x15b: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_165:
	/* 0x165: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_168:
	/* 0x168: test   esi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63999ULL);
x86_l_16e:
	/* 0x16e: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_172:
	/* 0x172: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_17c:
	/* 0x17c: or     r15,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_17f:
	/* 0x17f: test   esi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63743ULL);
x86_l_185:
	/* 0x185: cmove  r15,r10 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R10, X86_WIDTH_64, X86_CC_E);
x86_l_189:
	/* 0x189: jmp    196 <tail_nodeport_nat_ingress_ipv6+0x196> */
	goto x86_l_196;
x86_l_18b:
	/* 0x18b: lea    r8d,[r8*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 8ULL);
x86_l_193:
	/* 0x193: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_196:
	/* 0x196: lea    r13d,[r8+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19a:
	/* 0x19a: cmp    dil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 60ULL);
x86_l_19e:
	/* 0x19e: ja     3a3 <tail_nodeport_nat_ingress_ipv6+0x3a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a3;
	}
x86_l_1a4:
	/* 0x1a4: movzx  r10d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a8:
	/* 0x1a8: bt     rdx,r10 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R10, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: jae    1f8 <tail_nodeport_nat_ingress_ipv6+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1f8;
	}
x86_l_1ae:
	/* 0x1ae: add    r8d,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_1b2:
	/* 0x1b2: movzx  r9d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b6:
	/* 0x1b6: lea    rsi,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1ba:
	/* 0x1ba: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1be:
	/* 0x1be: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_1c1:
	/* 0x1c1: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_1c7:
	/* 0x1c7: add    r9,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ca:
	/* 0x1ca: movzx  esi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ce:
	/* 0x1ce: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1d1:
	/* 0x1d1: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d5:
	/* 0x1d5: cmp    r10d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 43ULL);
x86_l_1d9:
	/* 0x1d9: jle    209 <tail_nodeport_nat_ingress_ipv6+0x209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_209;
	}
x86_l_1db:
	/* 0x1db: cmp    r10d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 44ULL);
x86_l_1df:
	/* 0x1df: je     219 <tail_nodeport_nat_ingress_ipv6+0x219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_219;
	}
x86_l_1e1:
	/* 0x1e1: cmp    r10d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 51ULL);
x86_l_1e5:
	/* 0x1e5: jne    209 <tail_nodeport_nat_ingress_ipv6+0x209> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_209;
	}
x86_l_1e7:
	/* 0x1e7: movzx  edi,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1eb:
	/* 0x1eb: lea    r8d,[rdi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 8ULL);
x86_l_1f3:
	/* 0x1f3: jmp    27c <tail_nodeport_nat_ingress_ipv6+0x27c> */
	goto x86_l_27c;
x86_l_1f8:
	/* 0x1f8: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_1fa:
	/* 0x1fa: cmp    r10,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 59ULL);
x86_l_1fe:
	/* 0x1fe: je     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3699ULL;
	}
x86_l_204:
	/* 0x204: jmp    3b3 <tail_nodeport_nat_ingress_ipv6+0x3b3> */
	goto x86_l_3b3;
x86_l_209:
	/* 0x209: lea    r8d,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_211:
	/* 0x211: cmp    dil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 44ULL);
x86_l_215:
	/* 0x215: je     21f <tail_nodeport_nat_ingress_ipv6+0x21f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f;
	}
x86_l_217:
	/* 0x217: jmp    27c <tail_nodeport_nat_ingress_ipv6+0x27c> */
	goto x86_l_27c;
x86_l_219:
	/* 0x219: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_21f:
	/* 0x21f: lea    rdi,[r9+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_223:
	/* 0x223: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_226:
	/* 0x226: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_22c:
	/* 0x22c: mov    rdi,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22f:
	/* 0x22f: rorx   r9,rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RDI, X86_WIDTH_64, 0, 32ULL);
x86_l_235:
	/* 0x235: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_238:
	/* 0x238: mov    r10d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 4294967295ULL);
x86_l_23e:
	/* 0x23e: movabs r11,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_64, 1095216660480ULL);
x86_l_248:
	/* 0x248: or     r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_24b:
	/* 0x24b: and    r9,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_AND);
x86_l_24e:
	/* 0x24e: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_258:
	/* 0x258: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_25b:
	/* 0x25b: test   edi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63999ULL);
x86_l_261:
	/* 0x261: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_265:
	/* 0x265: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_26f:
	/* 0x26f: or     r15,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_272:
	/* 0x272: test   edi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63743ULL);
x86_l_278:
	/* 0x278: cmove  r15,r10 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R10, X86_WIDTH_64, X86_CC_E);
x86_l_27c:
	/* 0x27c: add    r13d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27f:
	/* 0x27f: cmp    sil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 60ULL);
x86_l_283:
	/* 0x283: ja     3b3 <tail_nodeport_nat_ingress_ipv6+0x3b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3b3;
	}
x86_l_289:
	/* 0x289: movzx  r8d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_28d:
	/* 0x28d: bt     rdx,r8 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_291:
	/* 0x291: jae    3a9 <tail_nodeport_nat_ingress_ipv6+0x3a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3a9;
	}
x86_l_297:
	/* 0x297: lea    edi,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_29b:
	/* 0x29b: movzx  r9d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_29f:
	/* 0x29f: lea    rdi,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_2a3:
	/* 0x2a3: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2a7:
	/* 0x2a7: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_2aa:
	/* 0x2aa: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_2b0:
	/* 0x2b0: add    r9,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b3:
	/* 0x2b3: movzx  edi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b7:
	/* 0x2b7: mov    r10d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RDI, X86_WIDTH_32);
x86_l_2ba:
	/* 0x2ba: shr    r10d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2be:
	/* 0x2be: cmp    r8d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 43ULL);
x86_l_2c2:
	/* 0x2c2: jle    2de <tail_nodeport_nat_ingress_ipv6+0x2de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2de;
	}
x86_l_2c4:
	/* 0x2c4: cmp    r8d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 44ULL);
x86_l_2c8:
	/* 0x2c8: je     2ee <tail_nodeport_nat_ingress_ipv6+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ee;
	}
x86_l_2ca:
	/* 0x2ca: cmp    r8d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 51ULL);
x86_l_2ce:
	/* 0x2ce: jne    2de <tail_nodeport_nat_ingress_ipv6+0x2de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2de;
	}
x86_l_2d0:
	/* 0x2d0: movzx  esi,r10w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R10, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d4:
	/* 0x2d4: lea    r8d,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_2dc:
	/* 0x2dc: jmp    351 <tail_nodeport_nat_ingress_ipv6+0x351> */
	goto x86_l_351;
x86_l_2de:
	/* 0x2de: lea    r8d,[r10*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 3), 8ULL);
x86_l_2e6:
	/* 0x2e6: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_2ea:
	/* 0x2ea: je     2f4 <tail_nodeport_nat_ingress_ipv6+0x2f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f4;
	}
x86_l_2ec:
	/* 0x2ec: jmp    351 <tail_nodeport_nat_ingress_ipv6+0x351> */
	goto x86_l_351;
x86_l_2ee:
	/* 0x2ee: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_2f4:
	/* 0x2f4: lea    rsi,[r9+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f8:
	/* 0x2f8: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: ja     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4e5;
	}
x86_l_301:
	/* 0x301: mov    rsi,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_304:
	/* 0x304: rorx   r9,rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RSI, X86_WIDTH_64, 0, 32ULL);
x86_l_30a:
	/* 0x30a: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_30d:
	/* 0x30d: mov    r10d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 4294967295ULL);
x86_l_313:
	/* 0x313: movabs r11,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_64, 1095216660480ULL);
x86_l_31d:
	/* 0x31d: or     r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_320:
	/* 0x320: and    r9,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_AND);
x86_l_323:
	/* 0x323: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_32d:
	/* 0x32d: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_330:
	/* 0x330: test   esi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63999ULL);
x86_l_336:
	/* 0x336: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_33a:
	/* 0x33a: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_344:
	/* 0x344: or     r15,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_347:
	/* 0x347: test   esi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63743ULL);
x86_l_34d:
	/* 0x34d: cmove  r15,r10 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R10, X86_WIDTH_64, X86_CC_E);
x86_l_351:
	/* 0x351: add    r13d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_354:
	/* 0x354: cmp    dil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 60ULL);
x86_l_358:
	/* 0x358: ja     3a3 <tail_nodeport_nat_ingress_ipv6+0x3a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3a3;
	}
x86_l_35a:
	/* 0x35a: movzx  r8d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_35e:
	/* 0x35e: bt     rdx,r8 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_362:
	/* 0x362: jae    3a7 <tail_nodeport_nat_ingress_ipv6+0x3a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_3a7;
	}
x86_l_364:
	/* 0x364: add    r13d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_368:
	/* 0x368: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_36c:
	/* 0x36c: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_370:
	/* 0x370: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_374:
	/* 0x374: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_379:
	/* 0x379: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_37c:
	/* 0x37c: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_382:
	/* 0x382: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_385:
	/* 0x385: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_389:
	/* 0x389: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_38c:
	/* 0x38c: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_391:
	/* 0x391: cmovbe ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_BE);
x86_l_394:
	/* 0x394: cmp    dil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 44ULL);
x86_l_398:
	/* 0x398: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_39b:
	/* 0x39b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39e:
	/* 0x39e: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	goto x86_l_4ed;
x86_l_3a3:
	/* 0x3a3: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_3a5:
	/* 0x3a5: jmp    3b3 <tail_nodeport_nat_ingress_ipv6+0x3b3> */
	goto x86_l_3b3;
x86_l_3a7:
	/* 0x3a7: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_3a9:
	/* 0x3a9: cmp    r8,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 59ULL);
x86_l_3ad:
	/* 0x3ad: je     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3699ULL;
	}
x86_l_3b3:
	/* 0x3b3: mov    BYTE PTR [rsp+0x9c],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_3bb:
	/* 0x3bb: mov    rdx,QWORD PTR [rax+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_3bf:
	/* 0x3bf: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_3c7:
	/* 0x3c7: mov    rdx,QWORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_3cb:
	/* 0x3cb: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3d0:
	/* 0x3d0: mov    rdx,QWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_3d4:
	/* 0x3d4: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3dc:
	/* 0x3dc: mov    rdx,QWORD PTR [rax+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_3e0:
	/* 0x3e0: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3e8:
	/* 0x3e8: mov    BYTE PTR [rsp+0x9d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 674309865473ULL);
x86_l_3f0:
	/* 0x3f0: lea    r10d,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_3f4:
	/* 0x3f4: cmp    sil,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 6ULL);
x86_l_3f8:
	/* 0x3f8: je     410 <tail_nodeport_nat_ingress_ipv6+0x410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_410;
	}
x86_l_3fa:
	/* 0x3fa: movzx  edx,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3fe:
	/* 0x3fe: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_401:
	/* 0x401: je     487 <tail_nodeport_nat_ingress_ipv6+0x487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_487;
	}
x86_l_407:
	/* 0x407: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_40a:
	/* 0x40a: jne    2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11394ULL;
	}
x86_l_410:
	/* 0x410: mov    rdx,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_417:
	/* 0x417: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41a:
	/* 0x41a: je     655 <tail_nodeport_nat_ingress_ipv6+0x655> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_655;
	}
x86_l_420:
	/* 0x420: lea    r14,[rax+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_424:
	/* 0x424: mov    rsi,QWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_428:
	/* 0x428: mov    QWORD PTR [rax+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_430:
	/* 0x430: mov    DWORD PTR [rax+0xe],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_434:
	/* 0x434: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_437:
	/* 0x437: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_43b:
	/* 0x43b: mov    BYTE PTR [rax+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_43e:
	/* 0x43e: bt     r15,0x29 */
	X86_SIM_L_EXEC_BT_IMM(X86_R15, X86_WIDTH_64, 41ULL);
x86_l_443:
	/* 0x443: jb     145f <tail_nodeport_nat_ingress_ipv6+0x145f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 5215ULL;
	}
x86_l_449:
	/* 0x449: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44c:
	/* 0x44c: movzx  ecx,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_450:
	/* 0x450: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_454:
	/* 0x454: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_458:
	/* 0x458: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_45d:
	/* 0x45d: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_461:
	/* 0x461: jbe    686 <tail_nodeport_nat_ingress_ipv6+0x686> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_686;
	}
x86_l_467:
	/* 0x467: mov    QWORD PTR [r14],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46a:
	/* 0x46a: cmp    ebp,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_470:
	/* 0x470: je     2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11394ULL;
	}
x86_l_476:
	/* 0x476: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_479:
	/* 0x479: cmp    ebp,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_47f:
	/* 0x47f: je     2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11394ULL;
	}
x86_l_485:
	/* 0x485: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	goto x86_l_4ed;
x86_l_487:
	/* 0x487: bt     r15,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R15, X86_WIDTH_64, 40ULL);
x86_l_48c:
	/* 0x48c: jb     4e5 <tail_nodeport_nat_ingress_ipv6+0x4e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_4e5;
	}
x86_l_48e:
	/* 0x48e: movzx  edx,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_492:
	/* 0x492: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_496:
	/* 0x496: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_49a:
	/* 0x49a: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_49f:
	/* 0x49f: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_4a8:
	/* 0x4a8: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ab:
	/* 0x4ab: mov    rdx,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae:
	/* 0x4ae: cmp    dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_4b1:
	/* 0x4b1: je     83a <tail_nodeport_nat_ingress_ipv6+0x83a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2106ULL;
	}
x86_l_4b7:
	/* 0x4b7: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4ba:
	/* 0x4ba: cmp    eax,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 129ULL);
x86_l_4bf:
	/* 0x4bf: jne    2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11394ULL;
	}
x86_l_4c5:
	/* 0x4c5: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4c9:
	/* 0x4c9: mov    WORD PTR [rsp+0x98],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_4d1:
	/* 0x4d1: mov    WORD PTR [rsp+0x9a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 661424963584ULL);
x86_l_4db:
	/* 0x4db: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_4e0:
	/* 0x4e0: jmp    6d6 <tail_nodeport_nat_ingress_ipv6+0x6d6> */
	goto x86_l_6d6;
x86_l_4e5:
	/* 0x4e5: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_4ea:
	/* 0x4ea: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ed:
	/* 0x4ed: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_4f0:
	/* 0x4f0: neg    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_4f3:
	/* 0x4f3: cmovs  r14d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_4f7:
	/* 0x4f7: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_4ff:
	/* 0x4ff: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_506:
	/* 0x506: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_50b:
	/* 0x50b: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_511:
	/* 0x511: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_514:
	/* 0x514: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_517:
	/* 0x517: je     522 <tail_nodeport_nat_ingress_ipv6+0x522> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_522;
	}
x86_l_519:
	/* 0x519: mov    ecx,DWORD PTR [rsp+0xfc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 252ULL);
x86_l_520:
	/* 0x520: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_522:
	/* 0x522: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_52a:
	/* 0x52a: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_531:
	/* 0x531: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_536:
	/* 0x536: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_539:
	/* 0x539: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53c:
	/* 0x53c: je     545 <tail_nodeport_nat_ingress_ipv6+0x545> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_545;
	}
x86_l_53e:
	/* 0x53e: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_545:
	/* 0x545: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_54d:
	/* 0x54d: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_554:
	/* 0x554: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_559:
	/* 0x559: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_55f:
	/* 0x55f: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_562:
	/* 0x562: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_565:
	/* 0x565: je     571 <tail_nodeport_nat_ingress_ipv6+0x571> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_571;
	}
x86_l_567:
	/* 0x567: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_56b:
	/* 0x56b: or     ecx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_32, X86_ALU_OR);
x86_l_56e:
	/* 0x56e: mov    DWORD PTR [rax+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_571:
	/* 0x571: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_579:
	/* 0x579: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_580:
	/* 0x580: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_585:
	/* 0x585: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_588:
	/* 0x588: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_58b:
	/* 0x58b: je     594 <tail_nodeport_nat_ingress_ipv6+0x594> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_594;
	}
x86_l_58d:
	/* 0x58d: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_594:
	/* 0x594: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_59c:
	/* 0x59c: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_5a3:
	/* 0x5a3: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a8:
	/* 0x5a8: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_5ae:
	/* 0x5ae: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_5b1:
	/* 0x5b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5b4:
	/* 0x5b4: je     5bd <tail_nodeport_nat_ingress_ipv6+0x5bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5bd;
	}
x86_l_5b6:
	/* 0x5b6: mov    DWORD PTR [rax+0x10],0x4b26801 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68798277633ULL);
x86_l_5bd:
	/* 0x5bd: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c1:
	/* 0x5c1: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_5c4:
	/* 0x5c4: movabs rax,0x6804b20100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 446755373312ULL);
x86_l_5ce:
	/* 0x5ce: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5d6:
	/* 0x5d6: mov    BYTE PTR [rsp+0xa8],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5de:
	/* 0x5de: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_5e5:
	/* 0x5e5: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5ed:
	/* 0x5ed: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_5f0:
	/* 0x5f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5f3:
	/* 0x5f3: je     5fe <tail_nodeport_nat_ingress_ipv6+0x5fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5fe;
	}
x86_l_5f5:
	/* 0x5f5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5f8:
	/* 0x5f8: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5fc:
	/* 0x5fc: jmp    629 <tail_nodeport_nat_ingress_ipv6+0x629> */
	goto x86_l_629;
x86_l_5fe:
	/* 0x5fe: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_607:
	/* 0x607: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_60c:
	/* 0x60c: mov    rdi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_613:
	/* 0x613: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_61b:
	/* 0x61b: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_620:
	/* 0x620: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_625:
	/* 0x625: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_627:
	/* 0x627: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_629:
	/* 0x629: mov    rsi,QWORD PTR [rip+0x3bd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_630:
	/* 0x630: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_635:
	/* 0x635: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_63a:
	/* 0x63a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_642:
	/* 0x642: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_644:
	/* 0x644: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_646:
	/* 0x646: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_64d:
	/* 0x64d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_64f:
	/* 0x64f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_650:
	/* 0x650: jmp    2cd6 <tail_nodeport_nat_ingress_ipv6+0x2cd6> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_655:
	/* 0x655: bt     r15,0x29 */
	X86_SIM_L_EXEC_BT_IMM(X86_R15, X86_WIDTH_64, 41ULL);
x86_l_65a:
	/* 0x65a: jb     1793 <tail_nodeport_nat_ingress_ipv6+0x1793> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6035ULL;
	}
x86_l_660:
	/* 0x660: movzx  edx,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_664:
	/* 0x664: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_668:
	/* 0x668: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_66c:
	/* 0x66c: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_671:
	/* 0x671: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_674:
	/* 0x674: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_67a:
	/* 0x67a: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67d:
	/* 0x67d: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67f:
	/* 0x67f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_681:
	/* 0x681: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_684:
	/* 0x684: jmp    6b0 <tail_nodeport_nat_ingress_ipv6+0x6b0> */
	goto x86_l_6b0;
x86_l_686:
	/* 0x686: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_689:
	/* 0x689: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68b:
	/* 0x68b: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_692:
	/* 0x692: bt     r15,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R15, X86_WIDTH_64, 40ULL);
x86_l_697:
	/* 0x697: jb     17a0 <tail_nodeport_nat_ingress_ipv6+0x17a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 6048ULL;
	}
x86_l_69d:
	/* 0x69d: mov    QWORD PTR [r14],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a0:
	/* 0x6a0: movzx  ecx,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_6a8:
	/* 0x6a8: movzx  eax,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_6b0:
	/* 0x6b0: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_6b3:
	/* 0x6b3: mov    WORD PTR [rsp+0x9a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154ULL);
x86_l_6bb:
	/* 0x6bb: mov    WORD PTR [rsp+0x98],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6c3:
	/* 0x6c3: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_6c7:
	/* 0x6c7: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_6cc:
	/* 0x6cc: cmp    ax,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_16);
x86_l_6d0:
	/* 0x6d0: jb     2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 11394ULL;
	}
x86_l_6d6:
	/* 0x6d6: mov    QWORD PTR [rsp+0x10],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6db:
	/* 0x6db: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_6e2:
	/* 0x6e2: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6e7:
	/* 0x6e7: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_6ed:
	/* 0x6ed: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_6f0:
	/* 0x6f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 1779ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1779ULL: goto x86_l_6f3;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1796ULL: goto x86_l_704;
	case 1808ULL: goto x86_l_710;
	case 1820ULL: goto x86_l_71c;
	case 1832ULL: goto x86_l_728;
	case 1844ULL: goto x86_l_734;
	case 1856ULL: goto x86_l_740;
	case 1860ULL: goto x86_l_744;
	case 1864ULL: goto x86_l_748;
	case 1872ULL: goto x86_l_750;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1893ULL: goto x86_l_765;
	case 1896ULL: goto x86_l_768;
	case 1900ULL: goto x86_l_76c;
	case 1908ULL: goto x86_l_774;
	case 1916ULL: goto x86_l_77c;
	case 1924ULL: goto x86_l_784;
	case 1932ULL: goto x86_l_78c;
	case 1940ULL: goto x86_l_794;
	case 1947ULL: goto x86_l_79b;
	case 1955ULL: goto x86_l_7a3;
	case 1962ULL: goto x86_l_7aa;
	case 1970ULL: goto x86_l_7b2;
	case 1973ULL: goto x86_l_7b5;
	case 1976ULL: goto x86_l_7b8;
	case 1982ULL: goto x86_l_7be;
	case 1991ULL: goto x86_l_7c7;
	case 2000ULL: goto x86_l_7d0;
	case 2009ULL: goto x86_l_7d9;
	case 2018ULL: goto x86_l_7e2;
	case 2027ULL: goto x86_l_7eb;
	case 2032ULL: goto x86_l_7f0;
	case 2040ULL: goto x86_l_7f8;
	case 2045ULL: goto x86_l_7fd;
	case 2050ULL: goto x86_l_802;
	case 2058ULL: goto x86_l_80a;
	case 2063ULL: goto x86_l_80f;
	case 2067ULL: goto x86_l_813;
	case 2072ULL: goto x86_l_818;
	case 2079ULL: goto x86_l_81f;
	case 2082ULL: goto x86_l_822;
	case 2088ULL: goto x86_l_828;
	case 2093ULL: goto x86_l_82d;
	case 2095ULL: goto x86_l_82f;
	case 2097ULL: goto x86_l_831;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2115ULL: goto x86_l_843;
	case 2124ULL: goto x86_l_84c;
	case 2133ULL: goto x86_l_855;
	case 2142ULL: goto x86_l_85e;
	case 2146ULL: goto x86_l_862;
	case 2155ULL: goto x86_l_86b;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2166ULL: goto x86_l_876;
	case 2169ULL: goto x86_l_879;
	case 2175ULL: goto x86_l_87f;
	case 2178ULL: goto x86_l_882;
	case 2182ULL: goto x86_l_886;
	case 2186ULL: goto x86_l_88a;
	case 2190ULL: goto x86_l_88e;
	case 2194ULL: goto x86_l_892;
	case 2198ULL: goto x86_l_896;
	case 2202ULL: goto x86_l_89a;
	case 2207ULL: goto x86_l_89f;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2232ULL: goto x86_l_8b8;
	case 2237ULL: goto x86_l_8bd;
	case 2243ULL: goto x86_l_8c3;
	case 2247ULL: goto x86_l_8c7;
	case 2253ULL: goto x86_l_8cd;
	case 2258ULL: goto x86_l_8d2;
	case 2268ULL: goto x86_l_8dc;
	case 2272ULL: goto x86_l_8e0;
	case 2278ULL: goto x86_l_8e6;
	case 2282ULL: goto x86_l_8ea;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2297ULL: goto x86_l_8f9;
	case 2301ULL: goto x86_l_8fd;
	case 2304ULL: goto x86_l_900;
	case 2310ULL: goto x86_l_906;
	case 2313ULL: goto x86_l_909;
	case 2317ULL: goto x86_l_90d;
	case 2320ULL: goto x86_l_910;
	case 2324ULL: goto x86_l_914;
	case 2327ULL: goto x86_l_917;
	case 2329ULL: goto x86_l_919;
	case 2332ULL: goto x86_l_91c;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2347ULL: goto x86_l_92b;
	case 2351ULL: goto x86_l_92f;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2370ULL: goto x86_l_942;
	case 2372ULL: goto x86_l_944;
	case 2376ULL: goto x86_l_948;
	case 2386ULL: goto x86_l_952;
	case 2389ULL: goto x86_l_955;
	case 2394ULL: goto x86_l_95a;
	case 2398ULL: goto x86_l_95e;
	case 2403ULL: goto x86_l_963;
	case 2410ULL: goto x86_l_96a;
	case 2418ULL: goto x86_l_972;
	case 2423ULL: goto x86_l_977;
	case 2428ULL: goto x86_l_97c;
	case 2430ULL: goto x86_l_97e;
	case 2432ULL: goto x86_l_980;
	case 2434ULL: goto x86_l_982;
	case 2440ULL: goto x86_l_988;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2456ULL: goto x86_l_998;
	case 2460ULL: goto x86_l_99c;
	case 2468ULL: goto x86_l_9a4;
	case 2473ULL: goto x86_l_9a9;
	case 2481ULL: goto x86_l_9b1;
	case 2489ULL: goto x86_l_9b9;
	case 2494ULL: goto x86_l_9be;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2511ULL: goto x86_l_9cf;
	case 2516ULL: goto x86_l_9d4;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2530ULL: goto x86_l_9e2;
	case 2535ULL: goto x86_l_9e7;
	case 2540ULL: goto x86_l_9ec;
	case 2543ULL: goto x86_l_9ef;
	case 2547ULL: goto x86_l_9f3;
	case 2549ULL: goto x86_l_9f5;
	case 2556ULL: goto x86_l_9fc;
	case 2558ULL: goto x86_l_9fe;
	case 2565ULL: goto x86_l_a05;
	case 2570ULL: goto x86_l_a0a;
	case 2577ULL: goto x86_l_a11;
	case 2580ULL: goto x86_l_a14;
	case 2586ULL: goto x86_l_a1a;
	case 2596ULL: goto x86_l_a24;
	case 2599ULL: goto x86_l_a27;
	case 2605ULL: goto x86_l_a2d;
	case 2610ULL: goto x86_l_a32;
	case 2614ULL: goto x86_l_a36;
	case 2617ULL: goto x86_l_a39;
	case 2629ULL: goto x86_l_a45;
	case 2641ULL: goto x86_l_a51;
	case 2651ULL: goto x86_l_a5b;
	case 2659ULL: goto x86_l_a63;
	case 2666ULL: goto x86_l_a6a;
	case 2674ULL: goto x86_l_a72;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2684ULL: goto x86_l_a7c;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2693ULL: goto x86_l_a85;
	case 2695ULL: goto x86_l_a87;
	case 2707ULL: goto x86_l_a93;
	case 2715ULL: goto x86_l_a9b;
	case 2722ULL: goto x86_l_aa2;
	case 2730ULL: goto x86_l_aaa;
	case 2738ULL: goto x86_l_ab2;
	case 2743ULL: goto x86_l_ab7;
	case 2745ULL: goto x86_l_ab9;
	case 2747ULL: goto x86_l_abb;
	case 2752ULL: goto x86_l_ac0;
	case 2754ULL: goto x86_l_ac2;
	case 2758ULL: goto x86_l_ac6;
	case 2760ULL: goto x86_l_ac8;
	case 2770ULL: goto x86_l_ad2;
	case 2776ULL: goto x86_l_ad8;
	case 2779ULL: goto x86_l_adb;
	case 2781ULL: goto x86_l_add;
	case 2785ULL: goto x86_l_ae1;
	case 2788ULL: goto x86_l_ae4;
	case 2792ULL: goto x86_l_ae8;
	case 2796ULL: goto x86_l_aec;
	case 2800ULL: goto x86_l_af0;
	case 2804ULL: goto x86_l_af4;
	case 2806ULL: goto x86_l_af6;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2819ULL: goto x86_l_b03;
	case 2821ULL: goto x86_l_b05;
	case 2824ULL: goto x86_l_b08;
	case 2827ULL: goto x86_l_b0b;
	case 2829ULL: goto x86_l_b0d;
	case 2834ULL: goto x86_l_b12;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2845ULL: goto x86_l_b1d;
	case 2851ULL: goto x86_l_b23;
	case 2857ULL: goto x86_l_b29;
	case 2860ULL: goto x86_l_b2c;
	case 2864ULL: goto x86_l_b30;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2878ULL: goto x86_l_b3e;
	case 2880ULL: goto x86_l_b40;
	case 2885ULL: goto x86_l_b45;
	case 2888ULL: goto x86_l_b48;
	case 2892ULL: goto x86_l_b4c;
	case 2898ULL: goto x86_l_b52;
	case 2901ULL: goto x86_l_b55;
	case 2904ULL: goto x86_l_b58;
	case 2906ULL: goto x86_l_b5a;
	case 2908ULL: goto x86_l_b5c;
	case 2911ULL: goto x86_l_b5f;
	case 2917ULL: goto x86_l_b65;
	case 2924ULL: goto x86_l_b6c;
	case 2927ULL: goto x86_l_b6f;
	case 2929ULL: goto x86_l_b71;
	case 2936ULL: goto x86_l_b78;
	case 2939ULL: goto x86_l_b7b;
	case 2942ULL: goto x86_l_b7e;
	case 2944ULL: goto x86_l_b80;
	case 2955ULL: goto x86_l_b8b;
	case 2960ULL: goto x86_l_b90;
	case 2965ULL: goto x86_l_b95;
	case 2969ULL: goto x86_l_b99;
	case 2973ULL: goto x86_l_b9d;
	case 2977ULL: goto x86_l_ba1;
	case 2979ULL: goto x86_l_ba3;
	case 2981ULL: goto x86_l_ba5;
	case 2983ULL: goto x86_l_ba7;
	case 2986ULL: goto x86_l_baa;
	case 2989ULL: goto x86_l_bad;
	case 2991ULL: goto x86_l_baf;
	case 2996ULL: goto x86_l_bb4;
	case 2998ULL: goto x86_l_bb6;
	case 3003ULL: goto x86_l_bbb;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3016ULL: goto x86_l_bc8;
	case 3023ULL: goto x86_l_bcf;
	case 3026ULL: goto x86_l_bd2;
	case 3029ULL: goto x86_l_bd5;
	case 3034ULL: goto x86_l_bda;
	case 3038ULL: goto x86_l_bde;
	case 3042ULL: goto x86_l_be2;
	case 3045ULL: goto x86_l_be5;
	case 3047ULL: goto x86_l_be7;
	case 3052ULL: goto x86_l_bec;
	case 3054ULL: goto x86_l_bee;
	case 3056ULL: goto x86_l_bf0;
	case 3060ULL: goto x86_l_bf4;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3069ULL: goto x86_l_bfd;
	case 3071ULL: goto x86_l_bff;
	case 3075ULL: goto x86_l_c03;
	case 3085ULL: goto x86_l_c0d;
	case 3088ULL: goto x86_l_c10;
	case 3093ULL: goto x86_l_c15;
	case 3097ULL: goto x86_l_c19;
	case 3099ULL: goto x86_l_c1b;
	case 3104ULL: goto x86_l_c20;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3117ULL: goto x86_l_c2d;
	case 3121ULL: goto x86_l_c31;
	case 3128ULL: goto x86_l_c38;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3138ULL: goto x86_l_c42;
	case 3145ULL: goto x86_l_c49;
	case 3147ULL: goto x86_l_c4b;
	case 3150ULL: goto x86_l_c4e;
	case 3153ULL: goto x86_l_c51;
	case 3155ULL: goto x86_l_c53;
	case 3160ULL: goto x86_l_c58;
	case 3164ULL: goto x86_l_c5c;
	case 3166ULL: goto x86_l_c5e;
	case 3169ULL: goto x86_l_c61;
	case 3171ULL: goto x86_l_c63;
	case 3173ULL: goto x86_l_c65;
	case 3176ULL: goto x86_l_c68;
	case 3178ULL: goto x86_l_c6a;
	case 3182ULL: goto x86_l_c6e;
	case 3186ULL: goto x86_l_c72;
	case 3193ULL: goto x86_l_c79;
	case 3195ULL: goto x86_l_c7b;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3207ULL: goto x86_l_c87;
	case 3212ULL: goto x86_l_c8c;
	case 3216ULL: goto x86_l_c90;
	case 3219ULL: goto x86_l_c93;
	case 3224ULL: goto x86_l_c98;
	case 3228ULL: goto x86_l_c9c;
	case 3230ULL: goto x86_l_c9e;
	case 3234ULL: goto x86_l_ca2;
	case 3240ULL: goto x86_l_ca8;
	case 3245ULL: goto x86_l_cad;
	case 3247ULL: goto x86_l_caf;
	case 3253ULL: goto x86_l_cb5;
	case 3260ULL: goto x86_l_cbc;
	case 3265ULL: goto x86_l_cc1;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3280ULL: goto x86_l_cd0;
	case 3283ULL: goto x86_l_cd3;
	case 3289ULL: goto x86_l_cd9;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3302ULL: goto x86_l_ce6;
	case 3307ULL: goto x86_l_ceb;
	case 3311ULL: goto x86_l_cef;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3322ULL: goto x86_l_cfa;
	case 3324ULL: goto x86_l_cfc;
	case 3327ULL: goto x86_l_cff;
	case 3332ULL: goto x86_l_d04;
	case 3339ULL: goto x86_l_d0b;
	case 3341ULL: goto x86_l_d0d;
	case 3343ULL: goto x86_l_d0f;
	case 3349ULL: goto x86_l_d15;
	case 3356ULL: goto x86_l_d1c;
	case 3359ULL: goto x86_l_d1f;
	case 3361ULL: goto x86_l_d21;
	case 3368ULL: goto x86_l_d28;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3375ULL: goto x86_l_d2f;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3384ULL: goto x86_l_d38;
	case 3390ULL: goto x86_l_d3e;
	case 3395ULL: goto x86_l_d43;
	case 3400ULL: goto x86_l_d48;
	case 3404ULL: goto x86_l_d4c;
	case 3407ULL: goto x86_l_d4f;
	case 3411ULL: goto x86_l_d53;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3427ULL: goto x86_l_d63;
	case 3429ULL: goto x86_l_d65;
	case 3433ULL: goto x86_l_d69;
	case 3435ULL: goto x86_l_d6b;
	case 3440ULL: goto x86_l_d70;
	case 3442ULL: goto x86_l_d72;
	case 3444ULL: goto x86_l_d74;
	case 3448ULL: goto x86_l_d78;
	case 3458ULL: goto x86_l_d82;
	case 3461ULL: goto x86_l_d85;
	case 3466ULL: goto x86_l_d8a;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3476ULL: goto x86_l_d94;
	case 3481ULL: goto x86_l_d99;
	case 3485ULL: goto x86_l_d9d;
	case 3489ULL: goto x86_l_da1;
	case 3496ULL: goto x86_l_da8;
	case 3499ULL: goto x86_l_dab;
	case 3504ULL: goto x86_l_db0;
	case 3506ULL: goto x86_l_db2;
	case 3513ULL: goto x86_l_db9;
	case 3515ULL: goto x86_l_dbb;
	case 3518ULL: goto x86_l_dbe;
	case 3521ULL: goto x86_l_dc1;
	case 3523ULL: goto x86_l_dc3;
	case 3528ULL: goto x86_l_dc8;
	case 3532ULL: goto x86_l_dcc;
	case 3534ULL: goto x86_l_dce;
	case 3537ULL: goto x86_l_dd1;
	case 3539ULL: goto x86_l_dd3;
	case 3541ULL: goto x86_l_dd5;
	case 3544ULL: goto x86_l_dd8;
	case 3546ULL: goto x86_l_dda;
	case 3550ULL: goto x86_l_dde;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6f3:
	/* 0x6f3: je     2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11394ULL;
	}
x86_l_6f9:
	/* 0x6f9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6fc:
	/* 0x6fc: lea    rax,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_704:
	/* 0x704: mov    QWORD PTR [rsp+0xc6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 850403524608ULL);
x86_l_710:
	/* 0x710: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_71c:
	/* 0x71c: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_728:
	/* 0x728: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_734:
	/* 0x734: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_740:
	/* 0x740: mov    rcx,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_744:
	/* 0x744: mov    rdx,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_748:
	/* 0x748: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_750:
	/* 0x750: mov    QWORD PTR [rsp+0xc0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_758:
	/* 0x758: movzx  ecx,WORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_75d:
	/* 0x75d: mov    WORD PTR [rsp+0xca],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 202ULL);
x86_l_765:
	/* 0x765: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_768:
	/* 0x768: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_76c:
	/* 0x76c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_774:
	/* 0x774: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_77c:
	/* 0x77c: movzx  eax,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_784:
	/* 0x784: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_78c:
	/* 0x78c: movzx  eax,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_794:
	/* 0x794: mov    BYTE PTR [rsp+0xcc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_79b:
	/* 0x79b: mov    BYTE PTR [rsp+0xcd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 880468295680ULL);
x86_l_7a3:
	/* 0x7a3: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_7aa:
	/* 0x7aa: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7b2:
	/* 0x7b2: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_7b5:
	/* 0x7b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b8:
	/* 0x7b8: jne    988 <tail_nodeport_nat_ingress_ipv6+0x988> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_988;
	}
x86_l_7be:
	/* 0x7be: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_7c7:
	/* 0x7c7: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_7d0:
	/* 0x7d0: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_7d9:
	/* 0x7d9: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_7e2:
	/* 0x7e2: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_7eb:
	/* 0x7eb: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7f0:
	/* 0x7f0: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7f8:
	/* 0x7f8: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7fd:
	/* 0x7fd: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_802:
	/* 0x802: movzx  eax,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_80a:
	/* 0x80a: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_80f:
	/* 0x80f: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_813:
	/* 0x813: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_818:
	/* 0x818: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_81f:
	/* 0x81f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_822:
	/* 0x822: je     93b <tail_nodeport_nat_ingress_ipv6+0x93b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_93b;
	}
x86_l_828:
	/* 0x828: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_82d:
	/* 0x82d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_82f:
	/* 0x82f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_831:
	/* 0x831: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_835:
	/* 0x835: jmp    95e <tail_nodeport_nat_ingress_ipv6+0x95e> */
	goto x86_l_95e;
x86_l_83a:
	/* 0x83a: mov    QWORD PTR [rsp+0x4e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_843:
	/* 0x843: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_84c:
	/* 0x84c: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_855:
	/* 0x855: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_85e:
	/* 0x85e: lea    edx,[r13+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_862:
	/* 0x862: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_86b:
	/* 0x86b: movzx  esi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_86e:
	/* 0x86e: lea    rdi,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_872:
	/* 0x872: add    rdi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_876:
	/* 0x876: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_879:
	/* 0x879: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_87f:
	/* 0x87f: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_882:
	/* 0x882: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_886:
	/* 0x886: mov    rsi,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88a:
	/* 0x88a: mov    rdi,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88e:
	/* 0x88e: mov    r8,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_892:
	/* 0x892: movzx  eax,BYTE PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_896:
	/* 0x896: mov    BYTE PTR [rsp+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_89a:
	/* 0x89a: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_89f:
	/* 0x89f: mov    QWORD PTR [rsp+0x40],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8a4:
	/* 0x8a4: mov    QWORD PTR [rsp+0x38],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_8a9:
	/* 0x8a9: mov    QWORD PTR [rsp+0x30],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ae:
	/* 0x8ae: mov    BYTE PTR [rsp+0x55],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 365072220161ULL);
x86_l_8b3:
	/* 0x8b3: lea    rax,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b8:
	/* 0x8b8: movzx  esi,BYTE PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 84ULL);
x86_l_8bd:
	/* 0x8bd: mov    r12d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 40ULL);
x86_l_8c3:
	/* 0x8c3: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_8c7:
	/* 0x8c7: ja     15ba <tail_nodeport_nat_ingress_ipv6+0x15ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5562ULL;
	}
x86_l_8cd:
	/* 0x8cd: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_8d2:
	/* 0x8d2: movabs rdi,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_8dc:
	/* 0x8dc: bt     rdi,rsi */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_8e0:
	/* 0x8e0: jae    d34 <tail_nodeport_nat_ingress_ipv6+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d34;
	}
x86_l_8e6:
	/* 0x8e6: lea    r8d,[r13+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_8ea:
	/* 0x8ea: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ed:
	/* 0x8ed: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f1:
	/* 0x8f1: movzx  r8d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8f5:
	/* 0x8f5: lea    r9,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_8f9:
	/* 0x8f9: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_8fd:
	/* 0x8fd: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_900:
	/* 0x900: ja     16e9 <tail_nodeport_nat_ingress_ipv6+0x16e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5865ULL;
	}
x86_l_906:
	/* 0x906: add    r8,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_909:
	/* 0x909: movzx  r8d,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_90d:
	/* 0x90d: mov    r9d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R8, X86_WIDTH_32);
x86_l_910:
	/* 0x910: shr    r9d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_914:
	/* 0x914: cmp    esi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_917:
	/* 0x917: jle    92b <tail_nodeport_nat_ingress_ipv6+0x92b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_92b;
	}
x86_l_919:
	/* 0x919: cmp    esi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_91c:
	/* 0x91c: je     122a <tail_nodeport_nat_ingress_ipv6+0x122a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4650ULL;
	}
x86_l_922:
	/* 0x922: cmp    esi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 60ULL);
x86_l_925:
	/* 0x925: jne    1230 <tail_nodeport_nat_ingress_ipv6+0x1230> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4656ULL;
	}
x86_l_92b:
	/* 0x92b: movzx  esi,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_92f:
	/* 0x92f: lea    esi,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_936:
	/* 0x936: jmp    123b <tail_nodeport_nat_ingress_ipv6+0x123b> */
	return 4667ULL;
x86_l_93b:
	/* 0x93b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_940:
	/* 0x940: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_942:
	/* 0x942: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_944:
	/* 0x944: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_948:
	/* 0x948: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_952:
	/* 0x952: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_955:
	/* 0x955: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_95a:
	/* 0x95a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_95e:
	/* 0x95e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_963:
	/* 0x963: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_96a:
	/* 0x96a: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_972:
	/* 0x972: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_977:
	/* 0x977: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_97c:
	/* 0x97c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_97e:
	/* 0x97e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_980:
	/* 0x980: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_982:
	/* 0x982: js     2c82 <tail_nodeport_nat_ingress_ipv6+0x2c82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11394ULL;
	}
x86_l_988:
	/* 0x988: cmp    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_98d:
	/* 0x98d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_992:
	/* 0x992: je     deb <tail_nodeport_nat_ingress_ipv6+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3563ULL;
	}
x86_l_998:
	/* 0x998: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_99c:
	/* 0x99c: movzx  eax,WORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 156ULL);
x86_l_9a4:
	/* 0x9a4: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_9a9:
	/* 0x9a9: movzx  ecx,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_9b1:
	/* 0x9b1: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9b9:
	/* 0x9b9: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9be:
	/* 0x9be: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9c6:
	/* 0x9c6: mov    QWORD PTR [rsp+0x40],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9cb:
	/* 0x9cb: mov    rdx,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9cf:
	/* 0x9cf: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9d4:
	/* 0x9d4: mov    rdx,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d8:
	/* 0x9d8: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9dd:
	/* 0x9dd: movzx  edx,WORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_9e2:
	/* 0x9e2: mov    WORD PTR [rsp+0x52],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_9e7:
	/* 0x9e7: mov    WORD PTR [rsp+0x50],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ec:
	/* 0x9ec: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_9ef:
	/* 0x9ef: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_9f3:
	/* 0x9f3: jne    9fe <tail_nodeport_nat_ingress_ipv6+0x9fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9fe;
	}
x86_l_9f5:
	/* 0x9f5: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_9fc:
	/* 0x9fc: jmp    a05 <tail_nodeport_nat_ingress_ipv6+0xa05> */
	goto x86_l_a05;
x86_l_9fe:
	/* 0x9fe: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_a05:
	/* 0xa05: mov    BYTE PTR [rsp+0x55],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 365072220160ULL);
x86_l_a0a:
	/* 0xa0a: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_a11:
	/* 0xa11: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a14:
	/* 0xa14: je     ac0 <tail_nodeport_nat_ingress_ipv6+0xac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac0;
	}
x86_l_a1a:
	/* 0xa1a: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_a24:
	/* 0xa24: and    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_a27:
	/* 0xa27: je     ac0 <tail_nodeport_nat_ingress_ipv6+0xac0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ac0;
	}
x86_l_a2d:
	/* 0xa2d: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a32:
	/* 0xa32: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a36:
	/* 0xa36: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_a39:
	/* 0xa39: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_a45:
	/* 0xa45: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_a51:
	/* 0xa51: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_a5b:
	/* 0xa5b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a63:
	/* 0xa63: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a6a:
	/* 0xa6a: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a72:
	/* 0xa72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a77:
	/* 0xa77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a79:
	/* 0xa79: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7c:
	/* 0xa7c: je     a87 <tail_nodeport_nat_ingress_ipv6+0xa87> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a87;
	}
x86_l_a7e:
	/* 0xa7e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a81:
	/* 0xa81: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a85:
	/* 0xa85: jmp    abb <tail_nodeport_nat_ingress_ipv6+0xabb> */
	goto x86_l_abb;
x86_l_a87:
	/* 0xa87: mov    QWORD PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_a93:
	/* 0xa93: mov    QWORD PTR [rsp+0xb0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a9b:
	/* 0xa9b: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_aa2:
	/* 0xaa2: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_aaa:
	/* 0xaaa: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ab2:
	/* 0xab2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ab7:
	/* 0xab7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab9:
	/* 0xab9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abb:
	/* 0xabb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ac0:
	/* 0xac0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac2:
	/* 0xac2: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_ac6:
	/* 0xac6: jne    b00 <tail_nodeport_nat_ingress_ipv6+0xb00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b00;
	}
x86_l_ac8:
	/* 0xac8: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_ad2:
	/* 0xad2: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_ad8:
	/* 0xad8: and    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_adb:
	/* 0xadb: jne    b2c <tail_nodeport_nat_ingress_ipv6+0xb2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b2c;
	}
x86_l_add:
	/* 0xadd: add    r13d,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 26ULL);
x86_l_ae1:
	/* 0xae1: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae4:
	/* 0xae4: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ae8:
	/* 0xae8: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_aec:
	/* 0xaec: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_af0:
	/* 0xaf0: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_af4:
	/* 0xaf4: jbe    b05 <tail_nodeport_nat_ingress_ipv6+0xb05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b05;
	}
x86_l_af6:
	/* 0xaf6: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_afb:
	/* 0xafb: jmp    e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	return 3699ULL;
x86_l_b00:
	/* 0xb00: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b03:
	/* 0xb03: jmp    b2c <tail_nodeport_nat_ingress_ipv6+0xb2c> */
	goto x86_l_b2c;
x86_l_b05:
	/* 0xb05: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b08:
	/* 0xb08: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b0b:
	/* 0xb0b: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_b0d:
	/* 0xb0d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_b12:
	/* 0xb12: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b15:
	/* 0xb15: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_b1a:
	/* 0xb1a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b1d:
	/* 0xb1d: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_b23:
	/* 0xb23: jne    1f63 <tail_nodeport_nat_ingress_ipv6+0x1f63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8035ULL;
	}
x86_l_b29:
	/* 0xb29: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_b2c:
	/* 0xb2c: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b30:
	/* 0xb30: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b34:
	/* 0xb34: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b39:
	/* 0xb39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b3e:
	/* 0xb3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b40:
	/* 0xb40: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b45:
	/* 0xb45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b48:
	/* 0xb48: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b4c:
	/* 0xb4c: je     de2 <tail_nodeport_nat_ingress_ipv6+0xde2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3554ULL;
	}
x86_l_b52:
	/* 0xb52: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_b55:
	/* 0xb55: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b58:
	/* 0xb58: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b5a:
	/* 0xb5a: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b5c:
	/* 0xb5c: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_b5f:
	/* 0xb5f: je     c7b <tail_nodeport_nat_ingress_ipv6+0xc7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7b;
	}
x86_l_b65:
	/* 0xb65: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b6c:
	/* 0xb6c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6f:
	/* 0xb6f: je     b90 <tail_nodeport_nat_ingress_ipv6+0xb90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b90;
	}
x86_l_b71:
	/* 0xb71: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b78:
	/* 0xb78: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_b7b:
	/* 0xb7b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b7e:
	/* 0xb7e: jmp    b95 <tail_nodeport_nat_ingress_ipv6+0xb95> */
	goto x86_l_b95;
x86_l_b80:
	/* 0xb80: mov    DWORD PTR [rsp+0xfc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1082331758592ULL);
x86_l_b8b:
	/* 0xb8b: jmp    4e <tail_nodeport_nat_ingress_ipv6+0x4e> */
	return 78ULL;
x86_l_b90:
	/* 0xb90: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_b95:
	/* 0xb95: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b99:
	/* 0xb99: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b9d:
	/* 0xb9d: cmp    cx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 6ULL);
x86_l_ba1:
	/* 0xba1: jne    bd5 <tail_nodeport_nat_ingress_ipv6+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bd5;
	}
x86_l_ba3:
	/* 0xba3: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_ba5:
	/* 0xba5: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ba7:
	/* 0xba7: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_baa:
	/* 0xbaa: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_bad:
	/* 0xbad: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_baf:
	/* 0xbaf: mov    WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bb4:
	/* 0xbb4: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_bb6:
	/* 0xbb6: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_bbb:
	/* 0xbbb: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_bc0:
	/* 0xbc0: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_bc3:
	/* 0xbc3: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc6:
	/* 0xbc6: je     bd5 <tail_nodeport_nat_ingress_ipv6+0xbd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bd5;
	}
x86_l_bc8:
	/* 0xbc8: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bcf:
	/* 0xbcf: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_bd2:
	/* 0xbd2: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bd5:
	/* 0xbd5: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bda:
	/* 0xbda: movzx  r13d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bde:
	/* 0xbde: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_be2:
	/* 0xbe2: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be5:
	/* 0xbe5: je     bf6 <tail_nodeport_nat_ingress_ipv6+0xbf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bf6;
	}
x86_l_be7:
	/* 0xbe7: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bec:
	/* 0xbec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bee:
	/* 0xbee: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bf0:
	/* 0xbf0: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bf4:
	/* 0xbf4: jmp    c19 <tail_nodeport_nat_ingress_ipv6+0xc19> */
	goto x86_l_c19;
x86_l_bf6:
	/* 0xbf6: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_bfb:
	/* 0xbfb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bfd:
	/* 0xbfd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bff:
	/* 0xbff: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c03:
	/* 0xc03: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c0d:
	/* 0xc0d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c10:
	/* 0xc10: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c15:
	/* 0xc15: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c19:
	/* 0xc19: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c1b:
	/* 0xc1b: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c20:
	/* 0xc20: mov    DWORD PTR [r8+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c24:
	/* 0xc24: movzx  ecx,BYTE PTR [r8+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_c29:
	/* 0xc29: mov    edx,DWORD PTR [r8+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c2d:
	/* 0xc2d: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c31:
	/* 0xc31: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c38:
	/* 0xc38: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c3b:
	/* 0xc3b: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c40:
	/* 0xc40: je     c53 <tail_nodeport_nat_ingress_ipv6+0xc53> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c53;
	}
x86_l_c42:
	/* 0xc42: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c49:
	/* 0xc49: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c4b:
	/* 0xc4b: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c4e:
	/* 0xc4e: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c51:
	/* 0xc51: jmp    c58 <tail_nodeport_nat_ingress_ipv6+0xc58> */
	goto x86_l_c58;
x86_l_c53:
	/* 0xc53: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c58:
	/* 0xc58: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c5c:
	/* 0xc5c: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c5e:
	/* 0xc5e: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c61:
	/* 0xc61: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c63:
	/* 0xc63: jb     c6a <tail_nodeport_nat_ingress_ipv6+0xc6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c6a;
	}
x86_l_c65:
	/* 0xc65: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_c68:
	/* 0xc68: je     c7b <tail_nodeport_nat_ingress_ipv6+0xc7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c7b;
	}
x86_l_c6a:
	/* 0xc6a: mov    BYTE PTR [r8+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_c6e:
	/* 0xc6e: mov    DWORD PTR [r8+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c72:
	/* 0xc72: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c79:
	/* 0xc79: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7b:
	/* 0xc7b: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_c82:
	/* 0xc82: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c85:
	/* 0xc85: je     c98 <tail_nodeport_nat_ingress_ipv6+0xc98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c98;
	}
x86_l_c87:
	/* 0xc87: inc QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_c8c:
	/* 0xc8c: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c90:
	/* 0xc90: sub    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_c93:
	/* 0xc93: add QWORD PTR [r8+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R8, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_c98:
	/* 0xc98: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_c9c:
	/* 0xc9c: je     ceb <tail_nodeport_nat_ingress_ipv6+0xceb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ceb;
	}
x86_l_c9e:
	/* 0xc9e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_ca2:
	/* 0xca2: jne    deb <tail_nodeport_nat_ingress_ipv6+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3563ULL;
	}
x86_l_ca8:
	/* 0xca8: movzx  eax,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_cad:
	/* 0xcad: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_caf:
	/* 0xcaf: je     deb <tail_nodeport_nat_ingress_ipv6+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3563ULL;
	}
x86_l_cb5:
	/* 0xcb5: mov    WORD PTR [r8+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_cbc:
	/* 0xcbc: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_cc1:
	/* 0xcc1: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_cc4:
	/* 0xcc4: mov    WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cc9:
	/* 0xcc9: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_cd0:
	/* 0xcd0: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd3:
	/* 0xcd3: je     2123 <tail_nodeport_nat_ingress_ipv6+0x2123> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8483ULL;
	}
x86_l_cd9:
	/* 0xcd9: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ce0:
	/* 0xce0: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_ce3:
	/* 0xce3: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ce6:
	/* 0xce6: jmp    2128 <tail_nodeport_nat_ingress_ipv6+0x2128> */
	return 8488ULL;
x86_l_ceb:
	/* 0xceb: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cef:
	/* 0xcef: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_cf2:
	/* 0xcf2: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_cf5:
	/* 0xcf5: or     ax,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R8, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_cfa:
	/* 0xcfa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_cfc:
	/* 0xcfc: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_cff:
	/* 0xcff: mov    WORD PTR [r8+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d04:
	/* 0xd04: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_d0b:
	/* 0xd0b: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0d:
	/* 0xd0d: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_d0f:
	/* 0xd0f: je     deb <tail_nodeport_nat_ingress_ipv6+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3563ULL;
	}
x86_l_d15:
	/* 0xd15: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d1c:
	/* 0xd1c: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d1f:
	/* 0xd1f: je     d43 <tail_nodeport_nat_ingress_ipv6+0xd43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d43;
	}
x86_l_d21:
	/* 0xd21: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d28:
	/* 0xd28: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d2a:
	/* 0xd2a: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d2c:
	/* 0xd2c: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_d2f:
	/* 0xd2f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d32:
	/* 0xd32: jmp    d48 <tail_nodeport_nat_ingress_ipv6+0xd48> */
	goto x86_l_d48;
x86_l_d34:
	/* 0xd34: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_d38:
	/* 0xd38: je     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1130ULL;
	}
x86_l_d3e:
	/* 0xd3e: jmp    15ba <tail_nodeport_nat_ingress_ipv6+0x15ba> */
	return 5562ULL;
x86_l_d43:
	/* 0xd43: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_d48:
	/* 0xd48: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d4c:
	/* 0xd4c: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_d4f:
	/* 0xd4f: movzx  r12d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d53:
	/* 0xd53: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d57:
	/* 0xd57: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5a:
	/* 0xd5a: je     d6b <tail_nodeport_nat_ingress_ipv6+0xd6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6b;
	}
x86_l_d5c:
	/* 0xd5c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d61:
	/* 0xd61: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d63:
	/* 0xd63: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d65:
	/* 0xd65: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d69:
	/* 0xd69: jmp    d8e <tail_nodeport_nat_ingress_ipv6+0xd8e> */
	goto x86_l_d8e;
x86_l_d6b:
	/* 0xd6b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d70:
	/* 0xd70: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d72:
	/* 0xd72: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d74:
	/* 0xd74: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d78:
	/* 0xd78: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d82:
	/* 0xd82: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d85:
	/* 0xd85: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d8a:
	/* 0xd8a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d8e:
	/* 0xd8e: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d90:
	/* 0xd90: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d94:
	/* 0xd94: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_d99:
	/* 0xd99: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_d9d:
	/* 0xd9d: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_da1:
	/* 0xda1: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_da8:
	/* 0xda8: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dab:
	/* 0xdab: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db0:
	/* 0xdb0: je     dc3 <tail_nodeport_nat_ingress_ipv6+0xdc3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dc3;
	}
x86_l_db2:
	/* 0xdb2: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_db9:
	/* 0xdb9: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbb:
	/* 0xdbb: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_dbe:
	/* 0xdbe: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_dc1:
	/* 0xdc1: jmp    dc8 <tail_nodeport_nat_ingress_ipv6+0xdc8> */
	goto x86_l_dc8;
x86_l_dc3:
	/* 0xdc3: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_dc8:
	/* 0xdc8: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dcc:
	/* 0xdcc: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dce:
	/* 0xdce: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_dd1:
	/* 0xdd1: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_dd3:
	/* 0xdd3: jb     dda <tail_nodeport_nat_ingress_ipv6+0xdda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_dda;
	}
x86_l_dd5:
	/* 0xdd5: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_dd8:
	/* 0xdd8: je     deb <tail_nodeport_nat_ingress_ipv6+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3563ULL;
	}
x86_l_dda:
	/* 0xdda: mov    BYTE PTR [r13+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_dde:
	/* 0xdde: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
	return 3554ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3554ULL: goto x86_l_de2;
	case 3561ULL: goto x86_l_de9;
	case 3563ULL: goto x86_l_deb;
	case 3568ULL: goto x86_l_df0;
	case 3577ULL: goto x86_l_df9;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3594ULL: goto x86_l_e0a;
	case 3596ULL: goto x86_l_e0c;
	case 3599ULL: goto x86_l_e0f;
	case 3603ULL: goto x86_l_e13;
	case 3605ULL: goto x86_l_e15;
	case 3609ULL: goto x86_l_e19;
	case 3617ULL: goto x86_l_e21;
	case 3623ULL: goto x86_l_e27;
	case 3625ULL: goto x86_l_e29;
	case 3628ULL: goto x86_l_e2c;
	case 3632ULL: goto x86_l_e30;
	case 3636ULL: goto x86_l_e34;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3673ULL: goto x86_l_e59;
	case 3676ULL: goto x86_l_e5c;
	case 3678ULL: goto x86_l_e5e;
	case 3681ULL: goto x86_l_e61;
	case 3685ULL: goto x86_l_e65;
	case 3689ULL: goto x86_l_e69;
	case 3694ULL: goto x86_l_e6e;
	case 3697ULL: goto x86_l_e71;
	case 3699ULL: goto x86_l_e73;
	case 3702ULL: goto x86_l_e76;
	case 3707ULL: goto x86_l_e7b;
	case 3711ULL: goto x86_l_e7f;
	case 3715ULL: goto x86_l_e83;
	case 3719ULL: goto x86_l_e87;
	case 3723ULL: goto x86_l_e8b;
	case 3733ULL: goto x86_l_e95;
	case 3736ULL: goto x86_l_e98;
	case 3738ULL: goto x86_l_e9a;
	case 3740ULL: goto x86_l_e9c;
	case 3744ULL: goto x86_l_ea0;
	case 3746ULL: goto x86_l_ea2;
	case 3750ULL: goto x86_l_ea6;
	case 3755ULL: goto x86_l_eab;
	case 3757ULL: goto x86_l_ead;
	case 3759ULL: goto x86_l_eaf;
	case 3763ULL: goto x86_l_eb3;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3773ULL: goto x86_l_ebd;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3782ULL: goto x86_l_ec6;
	case 3785ULL: goto x86_l_ec9;
	case 3787ULL: goto x86_l_ecb;
	case 3792ULL: goto x86_l_ed0;
	case 3795ULL: goto x86_l_ed3;
	case 3800ULL: goto x86_l_ed8;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3814ULL: goto x86_l_ee6;
	case 3817ULL: goto x86_l_ee9;
	case 3823ULL: goto x86_l_eef;
	case 3831ULL: goto x86_l_ef7;
	case 3838ULL: goto x86_l_efe;
	case 3843ULL: goto x86_l_f03;
	case 3849ULL: goto x86_l_f09;
	case 3852ULL: goto x86_l_f0c;
	case 3855ULL: goto x86_l_f0f;
	case 3861ULL: goto x86_l_f15;
	case 3864ULL: goto x86_l_f18;
	case 3872ULL: goto x86_l_f20;
	case 3879ULL: goto x86_l_f27;
	case 3884ULL: goto x86_l_f2c;
	case 3887ULL: goto x86_l_f2f;
	case 3890ULL: goto x86_l_f32;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3905ULL: goto x86_l_f41;
	case 3910ULL: goto x86_l_f46;
	case 3912ULL: goto x86_l_f48;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3934ULL: goto x86_l_f5e;
	case 3939ULL: goto x86_l_f63;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3962ULL: goto x86_l_f7a;
	case 3973ULL: goto x86_l_f85;
	case 3985ULL: goto x86_l_f91;
	case 3997ULL: goto x86_l_f9d;
	case 4009ULL: goto x86_l_fa9;
	case 4021ULL: goto x86_l_fb5;
	case 4033ULL: goto x86_l_fc1;
	case 4045ULL: goto x86_l_fcd;
	case 4057ULL: goto x86_l_fd9;
	case 4065ULL: goto x86_l_fe1;
	case 4068ULL: goto x86_l_fe4;
	case 4075ULL: goto x86_l_feb;
	case 4087ULL: goto x86_l_ff7;
	case 4099ULL: goto x86_l_1003;
	case 4111ULL: goto x86_l_100f;
	case 4123ULL: goto x86_l_101b;
	case 4132ULL: goto x86_l_1024;
	case 4135ULL: goto x86_l_1027;
	case 4139ULL: goto x86_l_102b;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4151ULL: goto x86_l_1037;
	case 4154ULL: goto x86_l_103a;
	case 4160ULL: goto x86_l_1040;
	case 4165ULL: goto x86_l_1045;
	case 4168ULL: goto x86_l_1048;
	case 4174ULL: goto x86_l_104e;
	case 4178ULL: goto x86_l_1052;
	case 4184ULL: goto x86_l_1058;
	case 4189ULL: goto x86_l_105d;
	case 4199ULL: goto x86_l_1067;
	case 4203ULL: goto x86_l_106b;
	case 4209ULL: goto x86_l_1071;
	case 4213ULL: goto x86_l_1075;
	case 4216ULL: goto x86_l_1078;
	case 4222ULL: goto x86_l_107e;
	case 4225ULL: goto x86_l_1081;
	case 4227ULL: goto x86_l_1083;
	case 4230ULL: goto x86_l_1086;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4240ULL: goto x86_l_1090;
	case 4246ULL: goto x86_l_1096;
	case 4250ULL: goto x86_l_109a;
	case 4256ULL: goto x86_l_10a0;
	case 4259ULL: goto x86_l_10a3;
	case 4266ULL: goto x86_l_10aa;
	case 4270ULL: goto x86_l_10ae;
	case 4276ULL: goto x86_l_10b4;
	case 4281ULL: goto x86_l_10b9;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4296ULL: goto x86_l_10c8;
	case 4299ULL: goto x86_l_10cb;
	case 4309ULL: goto x86_l_10d5;
	case 4313ULL: goto x86_l_10d9;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4327ULL: goto x86_l_10e7;
	case 4331ULL: goto x86_l_10eb;
	case 4335ULL: goto x86_l_10ef;
	case 4339ULL: goto x86_l_10f3;
	case 4344ULL: goto x86_l_10f8;
	case 4347ULL: goto x86_l_10fb;
	case 4353ULL: goto x86_l_1101;
	case 4356ULL: goto x86_l_1104;
	case 4361ULL: goto x86_l_1109;
	case 4365ULL: goto x86_l_110d;
	case 4369ULL: goto x86_l_1111;
	case 4373ULL: goto x86_l_1115;
	case 4377ULL: goto x86_l_1119;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4389ULL: goto x86_l_1125;
	case 4395ULL: goto x86_l_112b;
	case 4398ULL: goto x86_l_112e;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4413ULL: goto x86_l_113d;
	case 4419ULL: goto x86_l_1143;
	case 4424ULL: goto x86_l_1148;
	case 4427ULL: goto x86_l_114b;
	case 4429ULL: goto x86_l_114d;
	case 4432ULL: goto x86_l_1150;
	case 4435ULL: goto x86_l_1153;
	case 4439ULL: goto x86_l_1157;
	case 4442ULL: goto x86_l_115a;
	case 4446ULL: goto x86_l_115e;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4456ULL: goto x86_l_1168;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4467ULL: goto x86_l_1173;
	case 4471ULL: goto x86_l_1177;
	case 4474ULL: goto x86_l_117a;
	case 4477ULL: goto x86_l_117d;
	case 4481ULL: goto x86_l_1181;
	case 4484ULL: goto x86_l_1184;
	case 4489ULL: goto x86_l_1189;
	case 4492ULL: goto x86_l_118c;
	case 4498ULL: goto x86_l_1192;
	case 4502ULL: goto x86_l_1196;
	case 4504ULL: goto x86_l_1198;
	case 4508ULL: goto x86_l_119c;
	case 4512ULL: goto x86_l_11a0;
	case 4517ULL: goto x86_l_11a5;
	case 4522ULL: goto x86_l_11aa;
	case 4525ULL: goto x86_l_11ad;
	case 4529ULL: goto x86_l_11b1;
	case 4533ULL: goto x86_l_11b5;
	case 4537ULL: goto x86_l_11b9;
	case 4542ULL: goto x86_l_11be;
	case 4545ULL: goto x86_l_11c1;
	case 4551ULL: goto x86_l_11c7;
	case 4554ULL: goto x86_l_11ca;
	case 4557ULL: goto x86_l_11cd;
	case 4559ULL: goto x86_l_11cf;
	case 4563ULL: goto x86_l_11d3;
	case 4566ULL: goto x86_l_11d6;
	case 4570ULL: goto x86_l_11da;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4583ULL: goto x86_l_11e7;
	case 4586ULL: goto x86_l_11ea;
	case 4589ULL: goto x86_l_11ed;
	case 4591ULL: goto x86_l_11ef;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4598ULL: goto x86_l_11f6;
	case 4602ULL: goto x86_l_11fa;
	case 4604ULL: goto x86_l_11fc;
	case 4609ULL: goto x86_l_1201;
	case 4612ULL: goto x86_l_1204;
	case 4614ULL: goto x86_l_1206;
	case 4617ULL: goto x86_l_1209;
	case 4620ULL: goto x86_l_120c;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4635ULL: goto x86_l_121b;
	case 4639ULL: goto x86_l_121f;
	case 4645ULL: goto x86_l_1225;
	case 4650ULL: goto x86_l_122a;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4660ULL: goto x86_l_1234;
	case 4667ULL: goto x86_l_123b;
	case 4671ULL: goto x86_l_123f;
	case 4675ULL: goto x86_l_1243;
	case 4679ULL: goto x86_l_1247;
	case 4685ULL: goto x86_l_124d;
	case 4689ULL: goto x86_l_1251;
	case 4693ULL: goto x86_l_1255;
	case 4695ULL: goto x86_l_1257;
	case 4699ULL: goto x86_l_125b;
	case 4703ULL: goto x86_l_125f;
	case 4707ULL: goto x86_l_1263;
	case 4711ULL: goto x86_l_1267;
	case 4714ULL: goto x86_l_126a;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4726ULL: goto x86_l_1276;
	case 4729ULL: goto x86_l_1279;
	case 4733ULL: goto x86_l_127d;
	case 4737ULL: goto x86_l_1281;
	case 4739ULL: goto x86_l_1283;
	case 4743ULL: goto x86_l_1287;
	case 4749ULL: goto x86_l_128d;
	case 4753ULL: goto x86_l_1291;
	case 4755ULL: goto x86_l_1293;
	case 4759ULL: goto x86_l_1297;
	case 4767ULL: goto x86_l_129f;
	case 4772ULL: goto x86_l_12a4;
	case 4775ULL: goto x86_l_12a7;
	case 4779ULL: goto x86_l_12ab;
	case 4785ULL: goto x86_l_12b1;
	case 4790ULL: goto x86_l_12b6;
	case 4794ULL: goto x86_l_12ba;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4816ULL: goto x86_l_12d0;
	case 4819ULL: goto x86_l_12d3;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4834ULL: goto x86_l_12e2;
	case 4837ULL: goto x86_l_12e5;
	case 4843ULL: goto x86_l_12eb;
	case 4853ULL: goto x86_l_12f5;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4878ULL: goto x86_l_130e;
	case 4882ULL: goto x86_l_1312;
	case 4885ULL: goto x86_l_1315;
	case 4895ULL: goto x86_l_131f;
	case 4898ULL: goto x86_l_1322;
	case 4904ULL: goto x86_l_1328;
	case 4908ULL: goto x86_l_132c;
	case 4913ULL: goto x86_l_1331;
	case 4915ULL: goto x86_l_1333;
	case 4922ULL: goto x86_l_133a;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4933ULL: goto x86_l_1345;
	case 4936ULL: goto x86_l_1348;
	case 4942ULL: goto x86_l_134e;
	case 4946ULL: goto x86_l_1352;
	case 4950ULL: goto x86_l_1356;
	case 4952ULL: goto x86_l_1358;
	case 4955ULL: goto x86_l_135b;
	case 4959ULL: goto x86_l_135f;
	case 4963ULL: goto x86_l_1363;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4976ULL: goto x86_l_1370;
	case 4979ULL: goto x86_l_1373;
	case 4983ULL: goto x86_l_1377;
	case 4986ULL: goto x86_l_137a;
	case 4989ULL: goto x86_l_137d;
	case 4993ULL: goto x86_l_1381;
	case 4995ULL: goto x86_l_1383;
	case 4999ULL: goto x86_l_1387;
	case 5005ULL: goto x86_l_138d;
	case 5009ULL: goto x86_l_1391;
	case 5011ULL: goto x86_l_1393;
	case 5014ULL: goto x86_l_1396;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5028ULL: goto x86_l_13a4;
	case 5033ULL: goto x86_l_13a9;
	case 5038ULL: goto x86_l_13ae;
	case 5041ULL: goto x86_l_13b1;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5056ULL: goto x86_l_13c0;
	case 5063ULL: goto x86_l_13c7;
	case 5066ULL: goto x86_l_13ca;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5086ULL: goto x86_l_13de;
	case 5089ULL: goto x86_l_13e1;
	case 5093ULL: goto x86_l_13e5;
	case 5099ULL: goto x86_l_13eb;
	case 5103ULL: goto x86_l_13ef;
	case 5107ULL: goto x86_l_13f3;
	case 5113ULL: goto x86_l_13f9;
	case 5117ULL: goto x86_l_13fd;
	case 5121ULL: goto x86_l_1401;
	case 5125ULL: goto x86_l_1405;
	case 5129ULL: goto x86_l_1409;
	case 5132ULL: goto x86_l_140c;
	case 5138ULL: goto x86_l_1412;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5147ULL: goto x86_l_141b;
	case 5151ULL: goto x86_l_141f;
	case 5155ULL: goto x86_l_1423;
	case 5157ULL: goto x86_l_1425;
	case 5161ULL: goto x86_l_1429;
	case 5167ULL: goto x86_l_142f;
	case 5171ULL: goto x86_l_1433;
	case 5173ULL: goto x86_l_1435;
	case 5177ULL: goto x86_l_1439;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5194ULL: goto x86_l_144a;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5210ULL: goto x86_l_145a;
	case 5215ULL: goto x86_l_145f;
	case 5220ULL: goto x86_l_1464;
	case 5223ULL: goto x86_l_1467;
	case 5230ULL: goto x86_l_146e;
	case 5235ULL: goto x86_l_1473;
	case 5238ULL: goto x86_l_1476;
	case 5240ULL: goto x86_l_1478;
	case 5243ULL: goto x86_l_147b;
	case 5249ULL: goto x86_l_1481;
	case 5251ULL: goto x86_l_1483;
	case 5258ULL: goto x86_l_148a;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5271ULL: goto x86_l_1497;
	default: return 0xffffffffffffffffULL;
	}
x86_l_de2:
	/* 0xde2: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_de9:
	/* 0xde9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_deb:
	/* 0xdeb: movzx  ecx,WORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_df0:
	/* 0xdf0: movzx  r12d,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_df9:
	/* 0xdf9: movzx  edx,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_e01:
	/* 0xe01: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e06:
	/* 0xe06: cmp    rax,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_e0a:
	/* 0xe0a: jne    e29 <tail_nodeport_nat_ingress_ipv6+0xe29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e29;
	}
x86_l_e0c:
	/* 0xe0c: cmp    dx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_16);
x86_l_e0f:
	/* 0xe0f: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_e13:
	/* 0xe13: jne    e30 <tail_nodeport_nat_ingress_ipv6+0xe30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e30;
	}
x86_l_e15:
	/* 0xe15: mov    rax,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e19:
	/* 0xe19: cmp    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e21:
	/* 0xe21: je     eef <tail_nodeport_nat_ingress_ipv6+0xeef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eef;
	}
x86_l_e27:
	/* 0xe27: jmp    e30 <tail_nodeport_nat_ingress_ipv6+0xe30> */
	goto x86_l_e30;
x86_l_e29:
	/* 0xe29: cmp    dx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_16);
x86_l_e2c:
	/* 0xe2c: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_e30:
	/* 0xe30: mov    DWORD PTR [rsp+0x28],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e34:
	/* 0xe34: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e38:
	/* 0xe38: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e3c:
	/* 0xe3c: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e41:
	/* 0xe41: lea    rdx,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e45:
	/* 0xe45: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e4a:
	/* 0xe4a: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_e4f:
	/* 0xe4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_e54:
	/* 0xe54: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_e59:
	/* 0xe59: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5c:
	/* 0xe5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5e:
	/* 0xe5e: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e61:
	/* 0xe61: mov    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e65:
	/* 0xe65: lea    rdx,[rcx+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_e69:
	/* 0xe69: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_e6e:
	/* 0xe6e: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_e71:
	/* 0xe71: jbe    e7b <tail_nodeport_nat_ingress_ipv6+0xe7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e7b;
	}
x86_l_e73:
	/* 0xe73: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e76:
	/* 0xe76: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	return 1261ULL;
x86_l_e7b:
	/* 0xe7b: mov    rdx,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e7f:
	/* 0xe7f: mov    QWORD PTR [rcx+0x2e],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_e83:
	/* 0xe83: mov    rdx,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e87:
	/* 0xe87: mov    QWORD PTR [rcx+0x26],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_e8b:
	/* 0xe8b: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_e95:
	/* 0xe95: test   r15,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_e98:
	/* 0xe98: jne    eef <tail_nodeport_nat_ingress_ipv6+0xeef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_eef;
	}
x86_l_e9a:
	/* 0xe9a: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_e9c:
	/* 0xe9c: cmp    r12d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 58ULL);
x86_l_ea0:
	/* 0xea0: je     ecb <tail_nodeport_nat_ingress_ipv6+0xecb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ecb;
	}
x86_l_ea2:
	/* 0xea2: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_ea6:
	/* 0xea6: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eab:
	/* 0xeab: je     ebf <tail_nodeport_nat_ingress_ipv6+0xebf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ebf;
	}
x86_l_ead:
	/* 0xead: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eaf:
	/* 0xeaf: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_eb3:
	/* 0xeb3: jne    eda <tail_nodeport_nat_ingress_ipv6+0xeda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_eda;
	}
x86_l_eb5:
	/* 0xeb5: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_eba:
	/* 0xeba: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ebd:
	/* 0xebd: jmp    edd <tail_nodeport_nat_ingress_ipv6+0xedd> */
	goto x86_l_edd;
x86_l_ebf:
	/* 0xebf: mov    edi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_ec4:
	/* 0xec4: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec6:
	/* 0xec6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec9:
	/* 0xec9: jmp    edd <tail_nodeport_nat_ingress_ipv6+0xedd> */
	goto x86_l_edd;
x86_l_ecb:
	/* 0xecb: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_ed0:
	/* 0xed0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed3:
	/* 0xed3: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ed8:
	/* 0xed8: jmp    edd <tail_nodeport_nat_ingress_ipv6+0xedd> */
	goto x86_l_edd;
x86_l_eda:
	/* 0xeda: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_edd:
	/* 0xedd: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_ee0:
	/* 0xee0: je     10b9 <tail_nodeport_nat_ingress_ipv6+0x10b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_10b9;
	}
x86_l_ee6:
	/* 0xee6: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_ee9:
	/* 0xee9: je     11aa <tail_nodeport_nat_ingress_ipv6+0x11aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11aa;
	}
x86_l_eef:
	/* 0xeef: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ef7:
	/* 0xef7: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_efe:
	/* 0xefe: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f03:
	/* 0xf03: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_f09:
	/* 0xf09: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_f0c:
	/* 0xf0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0f:
	/* 0xf0f: je     1da5 <tail_nodeport_nat_ingress_ipv6+0x1da5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7589ULL;
	}
x86_l_f15:
	/* 0xf15: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f18:
	/* 0xf18: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_f20:
	/* 0xf20: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_f27:
	/* 0xf27: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f2c:
	/* 0xf2c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_f2f:
	/* 0xf2f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f32:
	/* 0xf32: je     f3a <tail_nodeport_nat_ingress_ipv6+0xf3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f3a;
	}
x86_l_f34:
	/* 0xf34: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_f37:
	/* 0xf37: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f3a:
	/* 0xf3a: mov    r12,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_f41:
	/* 0xf41: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f46:
	/* 0xf46: je     f6e <tail_nodeport_nat_ingress_ipv6+0xf6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f6e;
	}
x86_l_f48:
	/* 0xf48: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_f4f:
	/* 0xf4f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_f54:
	/* 0xf54: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f57:
	/* 0xf57: mov    edx,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 18ULL);
x86_l_f5c:
	/* 0xf5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5e:
	/* 0xf5e: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_f63:
	/* 0xf63: mov    r15d,0x1200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4608ULL);
x86_l_f69:
	/* 0xf69: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	return 1261ULL;
x86_l_f6e:
	/* 0xf6e: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_f7a:
	/* 0xf7a: mov    DWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_f85:
	/* 0xf85: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_f91:
	/* 0xf91: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_f9d:
	/* 0xf9d: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_fa9:
	/* 0xfa9: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_fb5:
	/* 0xfb5: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_fc1:
	/* 0xfc1: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_fcd:
	/* 0xfcd: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_fd9:
	/* 0xfd9: mov    BYTE PTR [rsp+0xa8],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505738ULL);
x86_l_fe1:
	/* 0xfe1: mov    eax,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fe4:
	/* 0xfe4: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_feb:
	/* 0xfeb: mov    QWORD PTR [rsp+0x96],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 644245094400ULL);
x86_l_ff7:
	/* 0xff7: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1003:
	/* 0x1003: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_100f:
	/* 0x100f: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_101b:
	/* 0x101b: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1024:
	/* 0x1024: mov    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1027:
	/* 0x1027: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_102b:
	/* 0x102b: lea    rdi,[r15+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_102f:
	/* 0x102f: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1034:
	/* 0x1034: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1037:
	/* 0x1037: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_103a:
	/* 0x103a: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10567ULL;
	}
x86_l_1040:
	/* 0x1040: movzx  r13d,BYTE PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_1045:
	/* 0x1045: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1048:
	/* 0x1048: mov    r11d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 40ULL);
x86_l_104e:
	/* 0x104e: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_1052:
	/* 0x1052: ja     13a2 <tail_nodeport_nat_ingress_ipv6+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_13a2;
	}
x86_l_1058:
	/* 0x1058: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_105d:
	/* 0x105d: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1067:
	/* 0x1067: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_106b:
	/* 0x106b: jae    1211 <tail_nodeport_nat_ingress_ipv6+0x1211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1211;
	}
x86_l_1071:
	/* 0x1071: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1075:
	/* 0x1075: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1078:
	/* 0x1078: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_107e:
	/* 0x107e: movzx  edx,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1081:
	/* 0x1081: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1083:
	/* 0x1083: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1086:
	/* 0x1086: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_108a:
	/* 0x108a: jle    10a0 <tail_nodeport_nat_ingress_ipv6+0x10a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_10a0;
	}
x86_l_108c:
	/* 0x108c: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_1090:
	/* 0x1090: je     12c7 <tail_nodeport_nat_ingress_ipv6+0x12c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12c7;
	}
x86_l_1096:
	/* 0x1096: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_109a:
	/* 0x109a: jne    1333 <tail_nodeport_nat_ingress_ipv6+0x1333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1333;
	}
x86_l_10a0:
	/* 0x10a0: movzx  esi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10a3:
	/* 0x10a3: lea    esi,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_10aa:
	/* 0x10aa: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_10ae:
	/* 0x10ae: je     12cc <tail_nodeport_nat_ingress_ipv6+0x12cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12cc;
	}
x86_l_10b4:
	/* 0x10b4: jmp    133a <tail_nodeport_nat_ingress_ipv6+0x133a> */
	goto x86_l_133a;
x86_l_10b9:
	/* 0x10b9: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_10be:
	/* 0x10be: cmp    r12d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 58ULL);
x86_l_10c2:
	/* 0x10c2: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e73;
	}
x86_l_10c8:
	/* 0x10c8: mov    r9d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R12, X86_WIDTH_32);
x86_l_10cb:
	/* 0x10cb: movabs r10,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 288230376151842880ULL);
x86_l_10d5:
	/* 0x10d5: bt     r10,r9 */
	X86_SIM_L_EXEC_BT(X86_R10, X86_R9, X86_WIDTH_64);
x86_l_10d9:
	/* 0x10d9: jae    e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e73;
	}
x86_l_10df:
	/* 0x10df: mov    r9d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10e4:
	/* 0x10e4: add    r9d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10e7:
	/* 0x10e7: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_10eb:
	/* 0x10eb: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10ef:
	/* 0x10ef: add    r10,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_10f3:
	/* 0x10f3: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_10f8:
	/* 0x10f8: cmp    r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_10fb:
	/* 0x10fb: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e73;
	}
x86_l_1101:
	/* 0x1101: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1104:
	/* 0x1104: mov    r10d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1109:
	/* 0x1109: mov    WORD PTR [r9],r10w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R10, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110d:
	/* 0x110d: lea    r9d,[rdi+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1111:
	/* 0x1111: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1115:
	/* 0x1115: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1119:
	/* 0x1119: add    r10,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_111d:
	/* 0x111d: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1122:
	/* 0x1122: cmp    r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_1125:
	/* 0x1125: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e73;
	}
x86_l_112b:
	/* 0x112b: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_112e:
	/* 0x112e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1130:
	/* 0x1130: jne    113d <tail_nodeport_nat_ingress_ipv6+0x113d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_113d;
	}
x86_l_1132:
	/* 0x1132: cmp    WORD PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1137:
	/* 0x1137: je     ee6 <tail_nodeport_nat_ingress_ipv6+0xee6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ee6;
	}
x86_l_113d:
	/* 0x113d: movzx  r11d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1143:
	/* 0x1143: mov    r10d,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1148:
	/* 0x1148: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_114b:
	/* 0x114b: je     115a <tail_nodeport_nat_ingress_ipv6+0x115a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115a;
	}
x86_l_114d:
	/* 0x114d: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1150:
	/* 0x1150: add    r10d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1153:
	/* 0x1153: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1157:
	/* 0x1157: mov    r11d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R10, X86_WIDTH_32);
x86_l_115a:
	/* 0x115a: movzx  r10d,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_115e:
	/* 0x115e: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1161:
	/* 0x1161: add    r10d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1164:
	/* 0x1164: setb   r11b */
	X86_SIM_L_EXEC_SETCC(X86_R11, X86_CC_B);
x86_l_1168:
	/* 0x1168: movzx  r11d,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_116c:
	/* 0x116c: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_116f:
	/* 0x116f: movzx  r10d,r11w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1173:
	/* 0x1173: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1177:
	/* 0x1177: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_117a:
	/* 0x117a: mov    r10d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R11, X86_WIDTH_32);
x86_l_117d:
	/* 0x117d: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1181:
	/* 0x1181: add    r10d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1184:
	/* 0x1184: cmp    r10w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_16, 65535ULL);
x86_l_1189:
	/* 0x1189: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_118c:
	/* 0x118c: mov    r11d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 65535ULL);
x86_l_1192:
	/* 0x1192: cmovne r11d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1196:
	/* 0x1196: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1198:
	/* 0x1198: cmovne r11d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_119c:
	/* 0x119c: mov    WORD PTR [r9],r11w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R11, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a0:
	/* 0x11a0: mov    r11,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11a5:
	/* 0x11a5: jmp    ee6 <tail_nodeport_nat_ingress_ipv6+0xee6> */
	goto x86_l_ee6;
x86_l_11aa:
	/* 0x11aa: add    edi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11ad:
	/* 0x11ad: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11b1:
	/* 0x11b1: lea    r8,[rcx+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_11b5:
	/* 0x11b5: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_11b9:
	/* 0x11b9: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_11be:
	/* 0x11be: cmp    r8,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_11c1:
	/* 0x11c1: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e73;
	}
x86_l_11c7:
	/* 0x11c7: add    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_11ca:
	/* 0x11ca: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11cd:
	/* 0x11cd: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_11cf:
	/* 0x11cf: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_11d3:
	/* 0x11d3: or     dil,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_11d6:
	/* 0x11d6: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_11da:
	/* 0x11da: jne    eef <tail_nodeport_nat_ingress_ipv6+0xeef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_eef;
	}
x86_l_11e0:
	/* 0x11e0: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11e2:
	/* 0x11e2: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11e4:
	/* 0x11e4: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_11e7:
	/* 0x11e7: movzx  esi,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11ea:
	/* 0x11ea: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11ed:
	/* 0x11ed: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11ef:
	/* 0x11ef: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_11f1:
	/* 0x11f1: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11f4:
	/* 0x11f4: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11f6:
	/* 0x11f6: cmp    si,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 65535ULL);
x86_l_11fa:
	/* 0x11fa: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11fc:
	/* 0x11fc: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_1201:
	/* 0x1201: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_1204:
	/* 0x1204: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1206:
	/* 0x1206: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_1209:
	/* 0x1209: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120c:
	/* 0x120c: jmp    eef <tail_nodeport_nat_ingress_ipv6+0xeef> */
	goto x86_l_eef;
x86_l_1211:
	/* 0x1211: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_1216:
	/* 0x1216: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_121b:
	/* 0x121b: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_121f:
	/* 0x121f: je     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10567ULL;
	}
x86_l_1225:
	/* 0x1225: jmp    1ab1 <tail_nodeport_nat_ingress_ipv6+0x1ab1> */
	return 6833ULL;
x86_l_122a:
	/* 0x122a: mov    si,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_122e:
	/* 0x122e: jmp    123b <tail_nodeport_nat_ingress_ipv6+0x123b> */
	goto x86_l_123b;
x86_l_1230:
	/* 0x1230: movzx  esi,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1234:
	/* 0x1234: lea    esi,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_123b:
	/* 0x123b: movzx  r12d,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_123f:
	/* 0x123f: add    r12d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1243:
	/* 0x1243: cmp    r8b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 60ULL);
x86_l_1247:
	/* 0x1247: ja     1457 <tail_nodeport_nat_ingress_ipv6+0x1457> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1457;
	}
x86_l_124d:
	/* 0x124d: movzx  r9d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1251:
	/* 0x1251: bt     rdi,r9 */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_R9, X86_WIDTH_64);
x86_l_1255:
	/* 0x1255: jae    12a4 <tail_nodeport_nat_ingress_ipv6+0x12a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_12a4;
	}
x86_l_1257:
	/* 0x1257: lea    esi,[r12+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_125b:
	/* 0x125b: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_125f:
	/* 0x125f: lea    r8,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1263:
	/* 0x1263: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1267:
	/* 0x1267: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_126a:
	/* 0x126a: ja     16e9 <tail_nodeport_nat_ingress_ipv6+0x16e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5865ULL;
	}
x86_l_1270:
	/* 0x1270: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1273:
	/* 0x1273: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1276:
	/* 0x1276: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_1279:
	/* 0x1279: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_127d:
	/* 0x127d: cmp    r9d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 43ULL);
x86_l_1281:
	/* 0x1281: jle    12b6 <tail_nodeport_nat_ingress_ipv6+0x12b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_12b6;
	}
x86_l_1283:
	/* 0x1283: cmp    r9d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 44ULL);
x86_l_1287:
	/* 0x1287: je     13d5 <tail_nodeport_nat_ingress_ipv6+0x13d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d5;
	}
x86_l_128d:
	/* 0x128d: cmp    r9d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 51ULL);
x86_l_1291:
	/* 0x1291: jne    12b6 <tail_nodeport_nat_ingress_ipv6+0x12b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12b6;
	}
x86_l_1293:
	/* 0x1293: movzx  r8d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1297:
	/* 0x1297: lea    r8d,[r8*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 8ULL);
x86_l_129f:
	/* 0x129f: jmp    13da <tail_nodeport_nat_ingress_ipv6+0x13da> */
	goto x86_l_13da;
x86_l_12a4:
	/* 0x12a4: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_12a7:
	/* 0x12a7: cmp    r9,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 59ULL);
x86_l_12ab:
	/* 0x12ab: je     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1130ULL;
	}
x86_l_12b1:
	/* 0x12b1: jmp    15ba <tail_nodeport_nat_ingress_ipv6+0x15ba> */
	return 5562ULL;
x86_l_12b6:
	/* 0x12b6: movzx  r8d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12ba:
	/* 0x12ba: lea    r8d,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_12c2:
	/* 0x12c2: jmp    13da <tail_nodeport_nat_ingress_ipv6+0x13da> */
	goto x86_l_13da;
x86_l_12c7:
	/* 0x12c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12cc:
	/* 0x12cc: lea    r8,[r15+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_12d0:
	/* 0x12d0: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_12d3:
	/* 0x12d3: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_12d9:
	/* 0x12d9: mov    rdi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12dc:
	/* 0x12dc: rorx   r8,rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_64, 0, 32ULL);
x86_l_12e2:
	/* 0x12e2: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12e5:
	/* 0x12e5: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_12eb:
	/* 0x12eb: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_12f5:
	/* 0x12f5: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_12f8:
	/* 0x12f8: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_12fb:
	/* 0x12fb: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_1305:
	/* 0x1305: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1308:
	/* 0x1308: test   edi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63999ULL);
x86_l_130e:
	/* 0x130e: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_1312:
	/* 0x1312: mov    r10,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_64);
x86_l_1315:
	/* 0x1315: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_131f:
	/* 0x131f: or     r10,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1322:
	/* 0x1322: test   edi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63743ULL);
x86_l_1328:
	/* 0x1328: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_132c:
	/* 0x132c: mov    QWORD PTR [rsp+0x10],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1331:
	/* 0x1331: jmp    1341 <tail_nodeport_nat_ingress_ipv6+0x1341> */
	goto x86_l_1341;
x86_l_1333:
	/* 0x1333: lea    esi,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_133a:
	/* 0x133a: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_133c:
	/* 0x133c: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1341:
	/* 0x1341: lea    r11d,[rsi+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1345:
	/* 0x1345: cmp    dl,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 60ULL);
x86_l_1348:
	/* 0x1348: ja     1a9f <tail_nodeport_nat_ingress_ipv6+0x1a9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 6815ULL;
	}
x86_l_134e:
	/* 0x134e: movzx  r8d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1352:
	/* 0x1352: bt     rcx,r8 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_1356:
	/* 0x1356: jae    13ae <tail_nodeport_nat_ingress_ipv6+0x13ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_13ae;
	}
x86_l_1358:
	/* 0x1358: add    esi,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_135b:
	/* 0x135b: movzx  edi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_135f:
	/* 0x135f: lea    rsi,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1363:
	/* 0x1363: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1367:
	/* 0x1367: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_136a:
	/* 0x136a: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_1370:
	/* 0x1370: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1373:
	/* 0x1373: movzx  r13d,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1377:
	/* 0x1377: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_137a:
	/* 0x137a: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_137d:
	/* 0x137d: cmp    r8d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 43ULL);
x86_l_1381:
	/* 0x1381: jle    13c0 <tail_nodeport_nat_ingress_ipv6+0x13c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13c0;
	}
x86_l_1383:
	/* 0x1383: cmp    r8d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 44ULL);
x86_l_1387:
	/* 0x1387: je     1492 <tail_nodeport_nat_ingress_ipv6+0x1492> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1492;
	}
x86_l_138d:
	/* 0x138d: cmp    r8d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 51ULL);
x86_l_1391:
	/* 0x1391: jne    13c0 <tail_nodeport_nat_ingress_ipv6+0x13c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13c0;
	}
x86_l_1393:
	/* 0x1393: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1396:
	/* 0x1396: lea    esi,[rdx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 8ULL);
x86_l_139d:
	/* 0x139d: jmp    14fc <tail_nodeport_nat_ingress_ipv6+0x14fc> */
	return 5372ULL;
x86_l_13a2:
	/* 0x13a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a4:
	/* 0x13a4: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13a9:
	/* 0x13a9: jmp    1ab1 <tail_nodeport_nat_ingress_ipv6+0x1ab1> */
	return 6833ULL;
x86_l_13ae:
	/* 0x13ae: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_13b1:
	/* 0x13b1: cmp    r8,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 59ULL);
x86_l_13b5:
	/* 0x13b5: je     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10567ULL;
	}
x86_l_13bb:
	/* 0x13bb: jmp    1ab1 <tail_nodeport_nat_ingress_ipv6+0x1ab1> */
	return 6833ULL;
x86_l_13c0:
	/* 0x13c0: lea    esi,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_13c7:
	/* 0x13c7: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_13ca:
	/* 0x13ca: je     1497 <tail_nodeport_nat_ingress_ipv6+0x1497> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1497;
	}
x86_l_13d0:
	/* 0x13d0: jmp    14fc <tail_nodeport_nat_ingress_ipv6+0x14fc> */
	return 5372ULL;
x86_l_13d5:
	/* 0x13d5: mov    r8w,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_16, 8ULL);
x86_l_13da:
	/* 0x13da: movzx  r8d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13de:
	/* 0x13de: add    r12d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13e1:
	/* 0x13e1: cmp    sil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 60ULL);
x86_l_13e5:
	/* 0x13e5: ja     15ba <tail_nodeport_nat_ingress_ipv6+0x15ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5562ULL;
	}
x86_l_13eb:
	/* 0x13eb: movzx  r8d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_13ef:
	/* 0x13ef: bt     rdi,r8 */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_R8, X86_WIDTH_64);
x86_l_13f3:
	/* 0x13f3: jae    15b0 <tail_nodeport_nat_ingress_ipv6+0x15b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5552ULL;
	}
x86_l_13f9:
	/* 0x13f9: lea    esi,[r12+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_13fd:
	/* 0x13fd: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1401:
	/* 0x1401: lea    r9,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1405:
	/* 0x1405: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1409:
	/* 0x1409: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_140c:
	/* 0x140c: ja     16e9 <tail_nodeport_nat_ingress_ipv6+0x16e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 5865ULL;
	}
x86_l_1412:
	/* 0x1412: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1415:
	/* 0x1415: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1418:
	/* 0x1418: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_141b:
	/* 0x141b: shr    r9d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_141f:
	/* 0x141f: cmp    r8d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 43ULL);
x86_l_1423:
	/* 0x1423: jle    1446 <tail_nodeport_nat_ingress_ipv6+0x1446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1446;
	}
x86_l_1425:
	/* 0x1425: cmp    r8d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 44ULL);
x86_l_1429:
	/* 0x1429: je     1576 <tail_nodeport_nat_ingress_ipv6+0x1576> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5494ULL;
	}
x86_l_142f:
	/* 0x142f: cmp    r8d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 51ULL);
x86_l_1433:
	/* 0x1433: jne    1446 <tail_nodeport_nat_ingress_ipv6+0x1446> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1446;
	}
x86_l_1435:
	/* 0x1435: movzx  r8d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1439:
	/* 0x1439: lea    r8d,[r8*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 8ULL);
x86_l_1441:
	/* 0x1441: jmp    157b <tail_nodeport_nat_ingress_ipv6+0x157b> */
	return 5499ULL;
x86_l_1446:
	/* 0x1446: movzx  r8d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_144a:
	/* 0x144a: lea    r8d,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_1452:
	/* 0x1452: jmp    157b <tail_nodeport_nat_ingress_ipv6+0x157b> */
	return 5499ULL;
x86_l_1457:
	/* 0x1457: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_145a:
	/* 0x145a: jmp    15ba <tail_nodeport_nat_ingress_ipv6+0x15ba> */
	return 5562ULL;
x86_l_145f:
	/* 0x145f: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1464:
	/* 0x1464: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_1467:
	/* 0x1467: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_146e:
	/* 0x146e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1473:
	/* 0x1473: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1476:
	/* 0x1476: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1478:
	/* 0x1478: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_147b:
	/* 0x147b: je     182d <tail_nodeport_nat_ingress_ipv6+0x182d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6189ULL;
	}
x86_l_1481:
	/* 0x1481: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1483:
	/* 0x1483: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_148a:
	/* 0x148a: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_148d:
	/* 0x148d: jmp    1d9b <tail_nodeport_nat_ingress_ipv6+0x1d9b> */
	return 7579ULL;
x86_l_1492:
	/* 0x1492: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1497:
	/* 0x1497: lea    rdx,[rdi+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 5275ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5275ULL: goto x86_l_149b;
	case 5278ULL: goto x86_l_149e;
	case 5284ULL: goto x86_l_14a4;
	case 5287ULL: goto x86_l_14a7;
	case 5293ULL: goto x86_l_14ad;
	case 5296ULL: goto x86_l_14b0;
	case 5302ULL: goto x86_l_14b6;
	case 5312ULL: goto x86_l_14c0;
	case 5315ULL: goto x86_l_14c3;
	case 5318ULL: goto x86_l_14c6;
	case 5328ULL: goto x86_l_14d0;
	case 5331ULL: goto x86_l_14d3;
	case 5337ULL: goto x86_l_14d9;
	case 5341ULL: goto x86_l_14dd;
	case 5344ULL: goto x86_l_14e0;
	case 5354ULL: goto x86_l_14ea;
	case 5357ULL: goto x86_l_14ed;
	case 5363ULL: goto x86_l_14f3;
	case 5367ULL: goto x86_l_14f7;
	case 5372ULL: goto x86_l_14fc;
	case 5375ULL: goto x86_l_14ff;
	case 5379ULL: goto x86_l_1503;
	case 5385ULL: goto x86_l_1509;
	case 5389ULL: goto x86_l_150d;
	case 5393ULL: goto x86_l_1511;
	case 5399ULL: goto x86_l_1517;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5410ULL: goto x86_l_1522;
	case 5414ULL: goto x86_l_1526;
	case 5417ULL: goto x86_l_1529;
	case 5423ULL: goto x86_l_152f;
	case 5426ULL: goto x86_l_1532;
	case 5429ULL: goto x86_l_1535;
	case 5432ULL: goto x86_l_1538;
	case 5436ULL: goto x86_l_153c;
	case 5439ULL: goto x86_l_153f;
	case 5441ULL: goto x86_l_1541;
	case 5444ULL: goto x86_l_1544;
	case 5450ULL: goto x86_l_154a;
	case 5453ULL: goto x86_l_154d;
	case 5455ULL: goto x86_l_154f;
	case 5459ULL: goto x86_l_1553;
	case 5466ULL: goto x86_l_155a;
	case 5471ULL: goto x86_l_155f;
	case 5479ULL: goto x86_l_1567;
	case 5483ULL: goto x86_l_156b;
	case 5489ULL: goto x86_l_1571;
	case 5494ULL: goto x86_l_1576;
	case 5499ULL: goto x86_l_157b;
	case 5503ULL: goto x86_l_157f;
	case 5506ULL: goto x86_l_1582;
	case 5510ULL: goto x86_l_1586;
	case 5512ULL: goto x86_l_1588;
	case 5516ULL: goto x86_l_158c;
	case 5520ULL: goto x86_l_1590;
	case 5522ULL: goto x86_l_1592;
	case 5525ULL: goto x86_l_1595;
	case 5529ULL: goto x86_l_1599;
	case 5532ULL: goto x86_l_159c;
	case 5536ULL: goto x86_l_15a0;
	case 5539ULL: goto x86_l_15a3;
	case 5544ULL: goto x86_l_15a8;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5556ULL: goto x86_l_15b4;
	case 5562ULL: goto x86_l_15ba;
	case 5567ULL: goto x86_l_15bf;
	case 5570ULL: goto x86_l_15c2;
	case 5575ULL: goto x86_l_15c7;
	case 5579ULL: goto x86_l_15cb;
	case 5581ULL: goto x86_l_15cd;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5594ULL: goto x86_l_15da;
	case 5597ULL: goto x86_l_15dd;
	case 5603ULL: goto x86_l_15e3;
	case 5606ULL: goto x86_l_15e6;
	case 5610ULL: goto x86_l_15ea;
	case 5614ULL: goto x86_l_15ee;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5627ULL: goto x86_l_15fb;
	case 5633ULL: goto x86_l_1601;
	case 5638ULL: goto x86_l_1606;
	case 5641ULL: goto x86_l_1609;
	case 5643ULL: goto x86_l_160b;
	case 5647ULL: goto x86_l_160f;
	case 5655ULL: goto x86_l_1617;
	case 5662ULL: goto x86_l_161e;
	case 5667ULL: goto x86_l_1623;
	case 5672ULL: goto x86_l_1628;
	case 5674ULL: goto x86_l_162a;
	case 5679ULL: goto x86_l_162f;
	case 5682ULL: goto x86_l_1632;
	case 5688ULL: goto x86_l_1638;
	case 5691ULL: goto x86_l_163b;
	case 5696ULL: goto x86_l_1640;
	case 5700ULL: goto x86_l_1644;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5714ULL: goto x86_l_1652;
	case 5719ULL: goto x86_l_1657;
	case 5724ULL: goto x86_l_165c;
	case 5728ULL: goto x86_l_1660;
	case 5734ULL: goto x86_l_1666;
	case 5739ULL: goto x86_l_166b;
	case 5744ULL: goto x86_l_1670;
	case 5752ULL: goto x86_l_1678;
	case 5758ULL: goto x86_l_167e;
	case 5762ULL: goto x86_l_1682;
	case 5767ULL: goto x86_l_1687;
	case 5773ULL: goto x86_l_168d;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5783ULL: goto x86_l_1697;
	case 5787ULL: goto x86_l_169b;
	case 5791ULL: goto x86_l_169f;
	case 5795ULL: goto x86_l_16a3;
	case 5798ULL: goto x86_l_16a6;
	case 5801ULL: goto x86_l_16a9;
	case 5803ULL: goto x86_l_16ab;
	case 5806ULL: goto x86_l_16ae;
	case 5809ULL: goto x86_l_16b1;
	case 5811ULL: goto x86_l_16b3;
	case 5816ULL: goto x86_l_16b8;
	case 5819ULL: goto x86_l_16bb;
	case 5823ULL: goto x86_l_16bf;
	case 5827ULL: goto x86_l_16c3;
	case 5832ULL: goto x86_l_16c8;
	case 5835ULL: goto x86_l_16cb;
	case 5841ULL: goto x86_l_16d1;
	case 5844ULL: goto x86_l_16d4;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5860ULL: goto x86_l_16e4;
	case 5865ULL: goto x86_l_16e9;
	case 5870ULL: goto x86_l_16ee;
	case 5875ULL: goto x86_l_16f3;
	case 5880ULL: goto x86_l_16f8;
	case 5885ULL: goto x86_l_16fd;
	case 5893ULL: goto x86_l_1705;
	case 5896ULL: goto x86_l_1708;
	case 5900ULL: goto x86_l_170c;
	case 5905ULL: goto x86_l_1711;
	case 5907ULL: goto x86_l_1713;
	case 5915ULL: goto x86_l_171b;
	case 5920ULL: goto x86_l_1720;
	case 5925ULL: goto x86_l_1725;
	case 5930ULL: goto x86_l_172a;
	case 5933ULL: goto x86_l_172d;
	case 5935ULL: goto x86_l_172f;
	case 5939ULL: goto x86_l_1733;
	case 5942ULL: goto x86_l_1736;
	case 5946ULL: goto x86_l_173a;
	case 5950ULL: goto x86_l_173e;
	case 5954ULL: goto x86_l_1742;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5966ULL: goto x86_l_174e;
	case 5972ULL: goto x86_l_1754;
	case 5975ULL: goto x86_l_1757;
	case 5979ULL: goto x86_l_175b;
	case 5983ULL: goto x86_l_175f;
	case 5987ULL: goto x86_l_1763;
	case 5990ULL: goto x86_l_1766;
	case 5992ULL: goto x86_l_1768;
	case 5997ULL: goto x86_l_176d;
	case 6003ULL: goto x86_l_1773;
	case 6008ULL: goto x86_l_1778;
	case 6014ULL: goto x86_l_177e;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6043ULL: goto x86_l_179b;
	case 6048ULL: goto x86_l_17a0;
	case 6056ULL: goto x86_l_17a8;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6076ULL: goto x86_l_17bc;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6085ULL: goto x86_l_17c5;
	case 6090ULL: goto x86_l_17ca;
	case 6095ULL: goto x86_l_17cf;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6107ULL: goto x86_l_17db;
	case 6110ULL: goto x86_l_17de;
	case 6119ULL: goto x86_l_17e7;
	case 6128ULL: goto x86_l_17f0;
	case 6138ULL: goto x86_l_17fa;
	case 6146ULL: goto x86_l_1802;
	case 6153ULL: goto x86_l_1809;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6168ULL: goto x86_l_1818;
	case 6171ULL: goto x86_l_181b;
	case 6177ULL: goto x86_l_1821;
	case 6180ULL: goto x86_l_1824;
	case 6184ULL: goto x86_l_1828;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6209ULL: goto x86_l_1841;
	case 6217ULL: goto x86_l_1849;
	case 6219ULL: goto x86_l_184b;
	case 6221ULL: goto x86_l_184d;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6236ULL: goto x86_l_185c;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6243ULL: goto x86_l_1863;
	case 6251ULL: goto x86_l_186b;
	case 6253ULL: goto x86_l_186d;
	case 6256ULL: goto x86_l_1870;
	case 6262ULL: goto x86_l_1876;
	case 6264ULL: goto x86_l_1878;
	case 6266ULL: goto x86_l_187a;
	case 6271ULL: goto x86_l_187f;
	case 6276ULL: goto x86_l_1884;
	case 6281ULL: goto x86_l_1889;
	case 6286ULL: goto x86_l_188e;
	case 6292ULL: goto x86_l_1894;
	case 6297ULL: goto x86_l_1899;
	case 6307ULL: goto x86_l_18a3;
	case 6311ULL: goto x86_l_18a7;
	case 6317ULL: goto x86_l_18ad;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6329ULL: goto x86_l_18b9;
	case 6333ULL: goto x86_l_18bd;
	case 6337ULL: goto x86_l_18c1;
	case 6342ULL: goto x86_l_18c6;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6354ULL: goto x86_l_18d2;
	case 6360ULL: goto x86_l_18d8;
	case 6364ULL: goto x86_l_18dc;
	case 6372ULL: goto x86_l_18e4;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6395ULL: goto x86_l_18fb;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6406ULL: goto x86_l_1906;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6419ULL: goto x86_l_1913;
	case 6425ULL: goto x86_l_1919;
	case 6430ULL: goto x86_l_191e;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6440ULL: goto x86_l_1928;
	case 6443ULL: goto x86_l_192b;
	case 6447ULL: goto x86_l_192f;
	case 6451ULL: goto x86_l_1933;
	case 6454ULL: goto x86_l_1936;
	case 6457ULL: goto x86_l_1939;
	case 6461ULL: goto x86_l_193d;
	case 6465ULL: goto x86_l_1941;
	case 6468ULL: goto x86_l_1944;
	case 6472ULL: goto x86_l_1948;
	case 6476ULL: goto x86_l_194c;
	case 6479ULL: goto x86_l_194f;
	case 6482ULL: goto x86_l_1952;
	case 6486ULL: goto x86_l_1956;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6507ULL: goto x86_l_196b;
	case 6509ULL: goto x86_l_196d;
	case 6513ULL: goto x86_l_1971;
	case 6517ULL: goto x86_l_1975;
	case 6522ULL: goto x86_l_197a;
	case 6530ULL: goto x86_l_1982;
	case 6533ULL: goto x86_l_1985;
	case 6537ULL: goto x86_l_1989;
	case 6541ULL: goto x86_l_198d;
	case 6545ULL: goto x86_l_1991;
	case 6550ULL: goto x86_l_1996;
	case 6553ULL: goto x86_l_1999;
	case 6559ULL: goto x86_l_199f;
	case 6562ULL: goto x86_l_19a2;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6571ULL: goto x86_l_19ab;
	case 6574ULL: goto x86_l_19ae;
	case 6578ULL: goto x86_l_19b2;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6588ULL: goto x86_l_19bc;
	case 6591ULL: goto x86_l_19bf;
	case 6594ULL: goto x86_l_19c2;
	case 6597ULL: goto x86_l_19c5;
	case 6599ULL: goto x86_l_19c7;
	case 6601ULL: goto x86_l_19c9;
	case 6604ULL: goto x86_l_19cc;
	case 6606ULL: goto x86_l_19ce;
	case 6610ULL: goto x86_l_19d2;
	case 6612ULL: goto x86_l_19d4;
	case 6617ULL: goto x86_l_19d9;
	case 6620ULL: goto x86_l_19dc;
	case 6622ULL: goto x86_l_19de;
	case 6625ULL: goto x86_l_19e1;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6642ULL: goto x86_l_19f2;
	case 6645ULL: goto x86_l_19f5;
	case 6651ULL: goto x86_l_19fb;
	case 6654ULL: goto x86_l_19fe;
	case 6660ULL: goto x86_l_1a04;
	case 6663ULL: goto x86_l_1a07;
	case 6669ULL: goto x86_l_1a0d;
	case 6679ULL: goto x86_l_1a17;
	case 6682ULL: goto x86_l_1a1a;
	case 6685ULL: goto x86_l_1a1d;
	case 6695ULL: goto x86_l_1a27;
	case 6698ULL: goto x86_l_1a2a;
	case 6704ULL: goto x86_l_1a30;
	case 6708ULL: goto x86_l_1a34;
	case 6711ULL: goto x86_l_1a37;
	case 6721ULL: goto x86_l_1a41;
	case 6724ULL: goto x86_l_1a44;
	case 6730ULL: goto x86_l_1a4a;
	case 6734ULL: goto x86_l_1a4e;
	case 6739ULL: goto x86_l_1a53;
	case 6742ULL: goto x86_l_1a56;
	case 6745ULL: goto x86_l_1a59;
	case 6747ULL: goto x86_l_1a5b;
	case 6750ULL: goto x86_l_1a5e;
	case 6754ULL: goto x86_l_1a62;
	case 6756ULL: goto x86_l_1a64;
	case 6760ULL: goto x86_l_1a68;
	case 6764ULL: goto x86_l_1a6c;
	case 6768ULL: goto x86_l_1a70;
	case 6772ULL: goto x86_l_1a74;
	case 6775ULL: goto x86_l_1a77;
	case 6781ULL: goto x86_l_1a7d;
	case 6784ULL: goto x86_l_1a80;
	case 6788ULL: goto x86_l_1a84;
	case 6791ULL: goto x86_l_1a87;
	case 6796ULL: goto x86_l_1a8c;
	case 6801ULL: goto x86_l_1a91;
	case 6804ULL: goto x86_l_1a94;
	case 6807ULL: goto x86_l_1a97;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6818ULL: goto x86_l_1aa2;
	case 6820ULL: goto x86_l_1aa4;
	case 6823ULL: goto x86_l_1aa7;
	case 6827ULL: goto x86_l_1aab;
	case 6833ULL: goto x86_l_1ab1;
	case 6841ULL: goto x86_l_1ab9;
	case 6845ULL: goto x86_l_1abd;
	case 6853ULL: goto x86_l_1ac5;
	case 6857ULL: goto x86_l_1ac9;
	case 6862ULL: goto x86_l_1ace;
	case 6866ULL: goto x86_l_1ad2;
	case 6874ULL: goto x86_l_1ada;
	case 6878ULL: goto x86_l_1ade;
	case 6886ULL: goto x86_l_1ae6;
	case 6890ULL: goto x86_l_1aea;
	case 6892ULL: goto x86_l_1aec;
	case 6896ULL: goto x86_l_1af0;
	case 6899ULL: goto x86_l_1af3;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6925ULL: goto x86_l_1b0d;
	case 6929ULL: goto x86_l_1b11;
	case 6934ULL: goto x86_l_1b16;
	default: return 0xffffffffffffffffULL;
	}
x86_l_149b:
	/* 0x149b: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_149e:
	/* 0x149e: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_14a4:
	/* 0x14a4: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a7:
	/* 0x14a7: rorx   rdi,rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 32ULL);
x86_l_14ad:
	/* 0x14ad: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_14b0:
	/* 0x14b0: mov    r8d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4294967295ULL);
x86_l_14b6:
	/* 0x14b6: movabs r9,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1095216660480ULL);
x86_l_14c0:
	/* 0x14c0: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_14c3:
	/* 0x14c3: and    rdi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_14c6:
	/* 0x14c6: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_14d0:
	/* 0x14d0: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_14d3:
	/* 0x14d3: test   edx,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63999ULL);
x86_l_14d9:
	/* 0x14d9: cmove  r8,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_14dd:
	/* 0x14dd: mov    r9,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R8, X86_WIDTH_64);
x86_l_14e0:
	/* 0x14e0: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_14ea:
	/* 0x14ea: or     r9,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_14ed:
	/* 0x14ed: test   edx,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63743ULL);
x86_l_14f3:
	/* 0x14f3: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_14f7:
	/* 0x14f7: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14fc:
	/* 0x14fc: add    r11d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14ff:
	/* 0x14ff: cmp    r13b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 60ULL);
x86_l_1503:
	/* 0x1503: ja     1ab1 <tail_nodeport_nat_ingress_ipv6+0x1ab1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab1;
	}
x86_l_1509:
	/* 0x1509: movzx  esi,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_150d:
	/* 0x150d: bt     rcx,rsi */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_1511:
	/* 0x1511: jae    1aa7 <tail_nodeport_nat_ingress_ipv6+0x1aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1aa7;
	}
x86_l_1517:
	/* 0x1517: lea    edx,[r11+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_151b:
	/* 0x151b: movzx  edi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_151e:
	/* 0x151e: lea    rdx,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1522:
	/* 0x1522: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1526:
	/* 0x1526: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_152f:
	/* 0x152f: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1532:
	/* 0x1532: movzx  edx,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1535:
	/* 0x1535: mov    r8d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_1538:
	/* 0x1538: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_153c:
	/* 0x153c: cmp    esi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_153f:
	/* 0x153f: jle    155f <tail_nodeport_nat_ingress_ipv6+0x155f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_155f;
	}
x86_l_1541:
	/* 0x1541: cmp    esi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_1544:
	/* 0x1544: je     19e9 <tail_nodeport_nat_ingress_ipv6+0x19e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19e9;
	}
x86_l_154a:
	/* 0x154a: cmp    esi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 51ULL);
x86_l_154d:
	/* 0x154d: jne    155f <tail_nodeport_nat_ingress_ipv6+0x155f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_155f;
	}
x86_l_154f:
	/* 0x154f: movzx  esi,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1553:
	/* 0x1553: lea    esi,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_155a:
	/* 0x155a: jmp    1a53 <tail_nodeport_nat_ingress_ipv6+0x1a53> */
	goto x86_l_1a53;
x86_l_155f:
	/* 0x155f: lea    esi,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_1567:
	/* 0x1567: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_156b:
	/* 0x156b: je     19ee <tail_nodeport_nat_ingress_ipv6+0x19ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ee;
	}
x86_l_1571:
	/* 0x1571: jmp    1a53 <tail_nodeport_nat_ingress_ipv6+0x1a53> */
	goto x86_l_1a53;
x86_l_1576:
	/* 0x1576: mov    r8w,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_16, 8ULL);
x86_l_157b:
	/* 0x157b: movzx  r8d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_157f:
	/* 0x157f: add    r12d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1582:
	/* 0x1582: cmp    sil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 60ULL);
x86_l_1586:
	/* 0x1586: ja     15ba <tail_nodeport_nat_ingress_ipv6+0x15ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_15ba;
	}
x86_l_1588:
	/* 0x1588: movzx  r8d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_158c:
	/* 0x158c: bt     rdi,r8 */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_R8, X86_WIDTH_64);
x86_l_1590:
	/* 0x1590: jae    15b0 <tail_nodeport_nat_ingress_ipv6+0x15b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15b0;
	}
x86_l_1592:
	/* 0x1592: add    r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1595:
	/* 0x1595: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1599:
	/* 0x1599: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_159c:
	/* 0x159c: add    rax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_15a0:
	/* 0x15a0: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_15a3:
	/* 0x15a3: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_15a8:
	/* 0x15a8: cmova  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_A);
x86_l_15ab:
	/* 0x15ab: jmp    46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	return 1130ULL;
x86_l_15b0:
	/* 0x15b0: cmp    r8,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 59ULL);
x86_l_15b4:
	/* 0x15b4: je     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1130ULL;
	}
x86_l_15ba:
	/* 0x15ba: mov    BYTE PTR [rsp+0x54],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_15bf:
	/* 0x15bf: add    r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15c2:
	/* 0x15c2: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_15c7:
	/* 0x15c7: cmp    sil,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 6ULL);
x86_l_15cb:
	/* 0x15cb: je     15e3 <tail_nodeport_nat_ingress_ipv6+0x15e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15e3;
	}
x86_l_15cd:
	/* 0x15cd: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15d1:
	/* 0x15d1: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_15d4:
	/* 0x15d4: je     168f <tail_nodeport_nat_ingress_ipv6+0x168f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_168f;
	}
x86_l_15da:
	/* 0x15da: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_15dd:
	/* 0x15dd: jne    46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1130ULL;
	}
x86_l_15e3:
	/* 0x15e3: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e6:
	/* 0x15e6: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15ea:
	/* 0x15ea: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_15ee:
	/* 0x15ee: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_15f2:
	/* 0x15f2: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_15f7:
	/* 0x15f7: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_15fb:
	/* 0x15fb: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_1601:
	/* 0x1601: mov    QWORD PTR [rsp+0x10],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1606:
	/* 0x1606: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1609:
	/* 0x1609: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_160b:
	/* 0x160b: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_160f:
	/* 0x160f: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1617:
	/* 0x1617: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_161e:
	/* 0x161e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1623:
	/* 0x1623: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1628:
	/* 0x1628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162a:
	/* 0x162a: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_162f:
	/* 0x162f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1632:
	/* 0x1632: je     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1130ULL;
	}
x86_l_1638:
	/* 0x1638: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_163b:
	/* 0x163b: movzx  eax,BYTE PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 84ULL);
x86_l_1640:
	/* 0x1640: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1644:
	/* 0x1644: movzx  eax,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_1649:
	/* 0x1649: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_164d:
	/* 0x164d: movzx  eax,WORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1652:
	/* 0x1652: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1657:
	/* 0x1657: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_165c:
	/* 0x165c: cmp    rax,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1660:
	/* 0x1660: jne    16f3 <tail_nodeport_nat_ingress_ipv6+0x16f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16f3;
	}
x86_l_1666:
	/* 0x1666: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_166b:
	/* 0x166b: cmp    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1670:
	/* 0x1670: sete   BYTE PTR [rsp+0x100] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 256ULL);
x86_l_1678:
	/* 0x1678: jne    1705 <tail_nodeport_nat_ingress_ipv6+0x1705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1705;
	}
x86_l_167e:
	/* 0x167e: mov    rax,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1682:
	/* 0x1682: cmp    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1687:
	/* 0x1687: je     1876 <tail_nodeport_nat_ingress_ipv6+0x1876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1876;
	}
x86_l_168d:
	/* 0x168d: jmp    1705 <tail_nodeport_nat_ingress_ipv6+0x1705> */
	goto x86_l_1705;
x86_l_168f:
	/* 0x168f: mov    QWORD PTR [rsp+0x10],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1694:
	/* 0x1694: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1697:
	/* 0x1697: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_169b:
	/* 0x169b: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_169f:
	/* 0x169f: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_16a3:
	/* 0x16a3: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_16a6:
	/* 0x16a6: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_16a9:
	/* 0x16a9: ja     16e9 <tail_nodeport_nat_ingress_ipv6+0x16e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_16e9;
	}
x86_l_16ab:
	/* 0x16ab: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16ae:
	/* 0x16ae: cmp    BYTE PTR [rdx],0x80 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16b1:
	/* 0x16b1: jne    16e9 <tail_nodeport_nat_ingress_ipv6+0x16e9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e9;
	}
x86_l_16b3:
	/* 0x16b3: lea    edx,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16b8:
	/* 0x16b8: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16bb:
	/* 0x16bb: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_16bf:
	/* 0x16bf: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_16c3:
	/* 0x16c3: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_16c8:
	/* 0x16c8: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_16cb:
	/* 0x16cb: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_16d1:
	/* 0x16d1: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16d4:
	/* 0x16d4: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16d7:
	/* 0x16d7: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16dc:
	/* 0x16dc: mov    DWORD PTR [rsp+0x20],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953476ULL);
x86_l_16e4:
	/* 0x16e4: jmp    1617 <tail_nodeport_nat_ingress_ipv6+0x1617> */
	goto x86_l_1617;
x86_l_16e9:
	/* 0x16e9: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_16ee:
	/* 0x16ee: jmp    46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	return 1130ULL;
x86_l_16f3:
	/* 0x16f3: movzx  eax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_16f8:
	/* 0x16f8: cmp    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16fd:
	/* 0x16fd: sete   BYTE PTR [rsp+0x100] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 256ULL);
x86_l_1705:
	/* 0x1705: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1708:
	/* 0x1708: add    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_170c:
	/* 0x170c: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1711:
	/* 0x1711: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1713:
	/* 0x1713: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_171b:
	/* 0x171b: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1720:
	/* 0x1720: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1725:
	/* 0x1725: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_172a:
	/* 0x172a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172d:
	/* 0x172d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172f:
	/* 0x172f: add    r13d,0x1e */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 30ULL);
x86_l_1733:
	/* 0x1733: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1736:
	/* 0x1736: mov    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_173a:
	/* 0x173a: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_173e:
	/* 0x173e: lea    rdi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_1742:
	/* 0x1742: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1746:
	/* 0x1746: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_174b:
	/* 0x174b: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_174e:
	/* 0x174e: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_1754:
	/* 0x1754: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1757:
	/* 0x1757: mov    rdi,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_175b:
	/* 0x175b: mov    QWORD PTR [rdx+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_175f:
	/* 0x175f: mov    rdi,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1763:
	/* 0x1763: mov    QWORD PTR [rdx],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1766:
	/* 0x1766: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_1768:
	/* 0x1768: cmp    DWORD PTR [rsp+0x18],0x3a */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215162ULL);
x86_l_176d:
	/* 0x176d: je     184f <tail_nodeport_nat_ingress_ipv6+0x184f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_184f;
	}
x86_l_1773:
	/* 0x1773: cmp    DWORD PTR [rsp+0x18],0x11 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215121ULL);
x86_l_1778:
	/* 0x1778: je     183c <tail_nodeport_nat_ingress_ipv6+0x183c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183c;
	}
x86_l_177e:
	/* 0x177e: cmp    DWORD PTR [rsp+0x18],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215110ULL);
x86_l_1783:
	/* 0x1783: jne    1860 <tail_nodeport_nat_ingress_ipv6+0x1860> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1860;
	}
x86_l_1789:
	/* 0x1789: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_178e:
	/* 0x178e: jmp    1854 <tail_nodeport_nat_ingress_ipv6+0x1854> */
	goto x86_l_1854;
x86_l_1793:
	/* 0x1793: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_1798:
	/* 0x1798: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_179b:
	/* 0x179b: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	return 1261ULL;
x86_l_17a0:
	/* 0x17a0: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_17a8:
	/* 0x17a8: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_17af:
	/* 0x17af: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17b4:
	/* 0x17b4: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17b9:
	/* 0x17b9: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_17bc:
	/* 0x17bc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17be:
	/* 0x17be: mov    QWORD PTR [rsp+0x10],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17c3:
	/* 0x17c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c5:
	/* 0x17c5: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ca:
	/* 0x17ca: mov    r10,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17cf:
	/* 0x17cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17d1:
	/* 0x17d1: je     69d <tail_nodeport_nat_ingress_ipv6+0x69d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1693ULL;
	}
x86_l_17d7:
	/* 0x17d7: mov    rbp,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17db:
	/* 0x17db: sub    rbp,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_17de:
	/* 0x17de: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_17e7:
	/* 0x17e7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_17f0:
	/* 0x17f0: movabs rax,0x7201a9010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654124810ULL);
x86_l_17fa:
	/* 0x17fa: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1802:
	/* 0x1802: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1809:
	/* 0x1809: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1811:
	/* 0x1811: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1816:
	/* 0x1816: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1818:
	/* 0x1818: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_181b:
	/* 0x181b: je     1d6b <tail_nodeport_nat_ingress_ipv6+0x1d6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7531ULL;
	}
x86_l_1821:
	/* 0x1821: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1824:
	/* 0x1824: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1828:
	/* 0x1828: jmp    1d96 <tail_nodeport_nat_ingress_ipv6+0x1d96> */
	return 7574ULL;
x86_l_182d:
	/* 0x182d: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1832:
	/* 0x1832: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1837:
	/* 0x1837: jmp    467 <tail_nodeport_nat_ingress_ipv6+0x467> */
	return 1127ULL;
x86_l_183c:
	/* 0x183c: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1841:
	/* 0x1841: mov    QWORD PTR [rsp+0xf0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1849:
	/* 0x1849: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184b:
	/* 0x184b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184d:
	/* 0x184d: jmp    1863 <tail_nodeport_nat_ingress_ipv6+0x1863> */
	goto x86_l_1863;
x86_l_184f:
	/* 0x184f: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1854:
	/* 0x1854: mov    QWORD PTR [rsp+0xf0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_185c:
	/* 0x185c: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_185e:
	/* 0x185e: jmp    1863 <tail_nodeport_nat_ingress_ipv6+0x1863> */
	goto x86_l_1863;
x86_l_1860:
	/* 0x1860: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_1863:
	/* 0x1863: cmp    BYTE PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_186b:
	/* 0x186b: je     1884 <tail_nodeport_nat_ingress_ipv6+0x1884> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1884;
	}
x86_l_186d:
	/* 0x186d: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1870:
	/* 0x1870: je     197a <tail_nodeport_nat_ingress_ipv6+0x197a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_197a;
	}
x86_l_1876:
	/* 0x1876: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1878:
	/* 0x1878: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_187a:
	/* 0x187a: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187f:
	/* 0x187f: jmp    df0 <tail_nodeport_nat_ingress_ipv6+0xdf0> */
	return 3568ULL;
x86_l_1884:
	/* 0x1884: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_1889:
	/* 0x1889: cmp    DWORD PTR [rsp+0x18],0x3a */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215162ULL);
x86_l_188e:
	/* 0x188e: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_1894:
	/* 0x1894: mov    r8d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1899:
	/* 0x1899: movabs r9,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 288230376151842880ULL);
x86_l_18a3:
	/* 0x18a3: bt     r9,r8 */
	X86_SIM_L_EXEC_BT(X86_R9, X86_R8, X86_WIDTH_64);
x86_l_18a7:
	/* 0x18a7: jae    46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 1130ULL;
	}
x86_l_18ad:
	/* 0x18ad: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18b2:
	/* 0x18b2: add    r8d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18b5:
	/* 0x18b5: movzx  r8d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18b9:
	/* 0x18b9: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_18bd:
	/* 0x18bd: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_18c1:
	/* 0x18c1: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_18c6:
	/* 0x18c6: cmp    r9,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RSI, X86_WIDTH_64);
x86_l_18c9:
	/* 0x18c9: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_18cf:
	/* 0x18cf: add    r8,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18d2:
	/* 0x18d2: movzx  r9d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_18d8:
	/* 0x18d8: mov    WORD PTR [r8],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18dc:
	/* 0x18dc: mov    r8,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_18e4:
	/* 0x18e4: add    r8d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18e7:
	/* 0x18e7: movzx  r8d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18eb:
	/* 0x18eb: lea    r9,[rcx+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_18ef:
	/* 0x18ef: add    r9,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_18f3:
	/* 0x18f3: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_18f8:
	/* 0x18f8: cmp    r9,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RSI, X86_WIDTH_64);
x86_l_18fb:
	/* 0x18fb: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_1901:
	/* 0x1901: add    r8,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1904:
	/* 0x1904: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1906:
	/* 0x1906: jne    1913 <tail_nodeport_nat_ingress_ipv6+0x1913> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1913;
	}
x86_l_1908:
	/* 0x1908: cmp    WORD PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190d:
	/* 0x190d: je     186d <tail_nodeport_nat_ingress_ipv6+0x186d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_186d;
	}
x86_l_1913:
	/* 0x1913: movzx  r10d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1919:
	/* 0x1919: cmp    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_191e:
	/* 0x191e: je     192f <tail_nodeport_nat_ingress_ipv6+0x192f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_192f;
	}
x86_l_1920:
	/* 0x1920: mov    r9d,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1925:
	/* 0x1925: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1928:
	/* 0x1928: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_192b:
	/* 0x192b: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_192f:
	/* 0x192f: movzx  r9d,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1933:
	/* 0x1933: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1936:
	/* 0x1936: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1939:
	/* 0x1939: setb   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_B);
x86_l_193d:
	/* 0x193d: movzx  r10d,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1941:
	/* 0x1941: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1944:
	/* 0x1944: movzx  r9d,r10w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1948:
	/* 0x1948: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_194c:
	/* 0x194c: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_194f:
	/* 0x194f: mov    r9d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R10, X86_WIDTH_32);
x86_l_1952:
	/* 0x1952: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1956:
	/* 0x1956: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1959:
	/* 0x1959: cmp    r9w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_16, 65535ULL);
x86_l_195e:
	/* 0x195e: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1961:
	/* 0x1961: mov    r10d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 65535ULL);
x86_l_1967:
	/* 0x1967: cmovne r10d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_32, X86_CC_NE);
x86_l_196b:
	/* 0x196b: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_196d:
	/* 0x196d: cmovne r10d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_32, X86_CC_NE);
x86_l_1971:
	/* 0x1971: mov    WORD PTR [r8],r10w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R10, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1975:
	/* 0x1975: jmp    186d <tail_nodeport_nat_ingress_ipv6+0x186d> */
	goto x86_l_186d;
x86_l_197a:
	/* 0x197a: mov    rdi,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1982:
	/* 0x1982: add    edi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1985:
	/* 0x1985: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1989:
	/* 0x1989: lea    r8,[rcx+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_198d:
	/* 0x198d: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1991:
	/* 0x1991: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1996:
	/* 0x1996: cmp    r8,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_1999:
	/* 0x1999: ja     46a <tail_nodeport_nat_ingress_ipv6+0x46a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1130ULL;
	}
x86_l_199f:
	/* 0x199f: add    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19a2:
	/* 0x19a2: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19a5:
	/* 0x19a5: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_19a7:
	/* 0x19a7: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_19ab:
	/* 0x19ab: or     dil,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_19ae:
	/* 0x19ae: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_19b2:
	/* 0x19b2: jne    1876 <tail_nodeport_nat_ingress_ipv6+0x1876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1876;
	}
x86_l_19b8:
	/* 0x19b8: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_19ba:
	/* 0x19ba: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19bc:
	/* 0x19bc: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_19bf:
	/* 0x19bf: movzx  esi,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_19c2:
	/* 0x19c2: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_19c5:
	/* 0x19c5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19c7:
	/* 0x19c7: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_19c9:
	/* 0x19c9: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_19cc:
	/* 0x19cc: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19ce:
	/* 0x19ce: cmp    si,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 65535ULL);
x86_l_19d2:
	/* 0x19d2: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_19d4:
	/* 0x19d4: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_19d9:
	/* 0x19d9: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_19dc:
	/* 0x19dc: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_19de:
	/* 0x19de: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_19e1:
	/* 0x19e1: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19e4:
	/* 0x19e4: jmp    1876 <tail_nodeport_nat_ingress_ipv6+0x1876> */
	goto x86_l_1876;
x86_l_19e9:
	/* 0x19e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_19ee:
	/* 0x19ee: lea    r8,[rdi+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19f2:
	/* 0x19f2: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_19f5:
	/* 0x19f5: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_19fb:
	/* 0x19fb: mov    rdi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19fe:
	/* 0x19fe: rorx   r8,rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_64, 0, 32ULL);
x86_l_1a04:
	/* 0x1a04: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a07:
	/* 0x1a07: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_1a0d:
	/* 0x1a0d: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_1a17:
	/* 0x1a17: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a1a:
	/* 0x1a1a: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_1a1d:
	/* 0x1a1d: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_1a27:
	/* 0x1a27: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a2a:
	/* 0x1a2a: test   edi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63999ULL);
x86_l_1a30:
	/* 0x1a30: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_1a34:
	/* 0x1a34: mov    r10,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_64);
x86_l_1a37:
	/* 0x1a37: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_1a41:
	/* 0x1a41: or     r10,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1a44:
	/* 0x1a44: test   edi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63743ULL);
x86_l_1a4a:
	/* 0x1a4a: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_1a4e:
	/* 0x1a4e: mov    QWORD PTR [rsp+0x10],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a53:
	/* 0x1a53: add    r11d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a56:
	/* 0x1a56: cmp    dl,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 60ULL);
x86_l_1a59:
	/* 0x1a59: ja     1a9f <tail_nodeport_nat_ingress_ipv6+0x1a9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a9f;
	}
x86_l_1a5b:
	/* 0x1a5b: movzx  esi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a5e:
	/* 0x1a5e: bt     rcx,rsi */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_1a62:
	/* 0x1a62: jae    1aa4 <tail_nodeport_nat_ingress_ipv6+0x1aa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1aa4;
	}
x86_l_1a64:
	/* 0x1a64: add    r11d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_1a68:
	/* 0x1a68: movzx  ecx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a6c:
	/* 0x1a6c: lea    rsi,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1a70:
	/* 0x1a70: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a74:
	/* 0x1a74: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1a77:
	/* 0x1a77: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_1a7d:
	/* 0x1a7d: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a80:
	/* 0x1a80: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1a84:
	/* 0x1a84: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1a87:
	/* 0x1a87: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_1a91:
	/* 0x1a91: cmovbe ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_BE);
x86_l_1a94:
	/* 0x1a94: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_1a97:
	/* 0x1a97: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1a9a:
	/* 0x1a9a: jmp    2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	return 10567ULL;
x86_l_1a9f:
	/* 0x1a9f: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1aa2:
	/* 0x1aa2: jmp    1ab1 <tail_nodeport_nat_ingress_ipv6+0x1ab1> */
	goto x86_l_1ab1;
x86_l_1aa4:
	/* 0x1aa4: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1aa7:
	/* 0x1aa7: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_1aab:
	/* 0x1aab: je     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10567ULL;
	}
x86_l_1ab1:
	/* 0x1ab1: mov    BYTE PTR [rsp+0x9c],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1ab9:
	/* 0x1ab9: mov    rcx,QWORD PTR [r15+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1abd:
	/* 0x1abd: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ac5:
	/* 0x1ac5: mov    rcx,QWORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_1ac9:
	/* 0x1ac9: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1ace:
	/* 0x1ace: mov    rcx,QWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ada:
	/* 0x1ada: mov    rcx,QWORD PTR [r15+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1ade:
	/* 0x1ade: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ae6:
	/* 0x1ae6: cmp    r13b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 17ULL);
x86_l_1aea:
	/* 0x1aea: je     1af9 <tail_nodeport_nat_ingress_ipv6+0x1af9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af9;
	}
x86_l_1aec:
	/* 0x1aec: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1af0:
	/* 0x1af0: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1af3:
	/* 0x1af3: jne    2642 <tail_nodeport_nat_ingress_ipv6+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9794ULL;
	}
x86_l_1af9:
	/* 0x1af9: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1afe:
	/* 0x1afe: lea    ecx,[r11+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1b02:
	/* 0x1b02: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b06:
	/* 0x1b06: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0b:
	/* 0x1b0b: je     1b71 <tail_nodeport_nat_ingress_ipv6+0x1b71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7025ULL;
	}
x86_l_1b0d:
	/* 0x1b0d: lea    rax,[r15+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1b11:
	/* 0x1b11: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b16:
	/* 0x1b16: mov    r13,QWORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
	return 6938ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6938ULL: goto x86_l_1b1a;
	case 6946ULL: goto x86_l_1b22;
	case 6951ULL: goto x86_l_1b27;
	case 6955ULL: goto x86_l_1b2b;
	case 6958ULL: goto x86_l_1b2e;
	case 6962ULL: goto x86_l_1b32;
	case 6966ULL: goto x86_l_1b36;
	case 6976ULL: goto x86_l_1b40;
	case 6979ULL: goto x86_l_1b43;
	case 6985ULL: goto x86_l_1b49;
	case 6988ULL: goto x86_l_1b4c;
	case 6993ULL: goto x86_l_1b51;
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7006ULL: goto x86_l_1b5e;
	case 7010ULL: goto x86_l_1b62;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7035ULL: goto x86_l_1b7b;
	case 7040ULL: goto x86_l_1b80;
	case 7046ULL: goto x86_l_1b86;
	case 7051ULL: goto x86_l_1b8b;
	case 7055ULL: goto x86_l_1b8f;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7067ULL: goto x86_l_1b9b;
	case 7073ULL: goto x86_l_1ba1;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7085ULL: goto x86_l_1bad;
	case 7087ULL: goto x86_l_1baf;
	case 7090ULL: goto x86_l_1bb2;
	case 7092ULL: goto x86_l_1bb4;
	case 7099ULL: goto x86_l_1bbb;
	case 7106ULL: goto x86_l_1bc2;
	case 7112ULL: goto x86_l_1bc8;
	case 7117ULL: goto x86_l_1bcd;
	case 7120ULL: goto x86_l_1bd0;
	case 7129ULL: goto x86_l_1bd9;
	case 7133ULL: goto x86_l_1bdd;
	case 7135ULL: goto x86_l_1bdf;
	case 7142ULL: goto x86_l_1be6;
	case 7144ULL: goto x86_l_1be8;
	case 7151ULL: goto x86_l_1bef;
	case 7159ULL: goto x86_l_1bf7;
	case 7164ULL: goto x86_l_1bfc;
	case 7170ULL: goto x86_l_1c02;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7187ULL: goto x86_l_1c13;
	case 7191ULL: goto x86_l_1c17;
	case 7194ULL: goto x86_l_1c1a;
	case 7203ULL: goto x86_l_1c23;
	case 7212ULL: goto x86_l_1c2c;
	case 7222ULL: goto x86_l_1c36;
	case 7230ULL: goto x86_l_1c3e;
	case 7237ULL: goto x86_l_1c45;
	case 7245ULL: goto x86_l_1c4d;
	case 7250ULL: goto x86_l_1c52;
	case 7252ULL: goto x86_l_1c54;
	case 7255ULL: goto x86_l_1c57;
	case 7257ULL: goto x86_l_1c59;
	case 7260ULL: goto x86_l_1c5c;
	case 7264ULL: goto x86_l_1c60;
	case 7266ULL: goto x86_l_1c62;
	case 7275ULL: goto x86_l_1c6b;
	case 7280ULL: goto x86_l_1c70;
	case 7287ULL: goto x86_l_1c77;
	case 7295ULL: goto x86_l_1c7f;
	case 7300ULL: goto x86_l_1c84;
	case 7305ULL: goto x86_l_1c89;
	case 7307ULL: goto x86_l_1c8b;
	case 7309ULL: goto x86_l_1c8d;
	case 7317ULL: goto x86_l_1c95;
	case 7321ULL: goto x86_l_1c99;
	case 7323ULL: goto x86_l_1c9b;
	case 7328ULL: goto x86_l_1ca0;
	case 7334ULL: goto x86_l_1ca6;
	case 7344ULL: goto x86_l_1cb0;
	case 7347ULL: goto x86_l_1cb3;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7357ULL: goto x86_l_1cbd;
	case 7360ULL: goto x86_l_1cc0;
	case 7363ULL: goto x86_l_1cc3;
	case 7367ULL: goto x86_l_1cc7;
	case 7371ULL: goto x86_l_1ccb;
	case 7375ULL: goto x86_l_1ccf;
	case 7381ULL: goto x86_l_1cd5;
	case 7384ULL: goto x86_l_1cd8;
	case 7387ULL: goto x86_l_1cdb;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7397ULL: goto x86_l_1ce5;
	case 7402ULL: goto x86_l_1cea;
	case 7405ULL: goto x86_l_1ced;
	case 7409ULL: goto x86_l_1cf1;
	case 7415ULL: goto x86_l_1cf7;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7439ULL: goto x86_l_1d0f;
	case 7442ULL: goto x86_l_1d12;
	case 7444ULL: goto x86_l_1d14;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7458ULL: goto x86_l_1d22;
	case 7463ULL: goto x86_l_1d27;
	case 7467ULL: goto x86_l_1d2b;
	case 7469ULL: goto x86_l_1d2d;
	case 7475ULL: goto x86_l_1d33;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7491ULL: goto x86_l_1d43;
	case 7493ULL: goto x86_l_1d45;
	case 7495ULL: goto x86_l_1d47;
	case 7498ULL: goto x86_l_1d4a;
	case 7504ULL: goto x86_l_1d50;
	case 7511ULL: goto x86_l_1d57;
	case 7514ULL: goto x86_l_1d5a;
	case 7516ULL: goto x86_l_1d5c;
	case 7523ULL: goto x86_l_1d63;
	case 7526ULL: goto x86_l_1d66;
	case 7529ULL: goto x86_l_1d69;
	case 7531ULL: goto x86_l_1d6b;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7552ULL: goto x86_l_1d80;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7570ULL: goto x86_l_1d92;
	case 7572ULL: goto x86_l_1d94;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7591ULL: goto x86_l_1da7;
	case 7596ULL: goto x86_l_1dac;
	case 7601ULL: goto x86_l_1db1;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7611ULL: goto x86_l_1dbb;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7619ULL: goto x86_l_1dc3;
	case 7621ULL: goto x86_l_1dc5;
	case 7626ULL: goto x86_l_1dca;
	case 7630ULL: goto x86_l_1dce;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7645ULL: goto x86_l_1ddd;
	case 7652ULL: goto x86_l_1de4;
	case 7655ULL: goto x86_l_1de7;
	case 7657ULL: goto x86_l_1de9;
	case 7664ULL: goto x86_l_1df0;
	case 7667ULL: goto x86_l_1df3;
	case 7670ULL: goto x86_l_1df6;
	case 7676ULL: goto x86_l_1dfc;
	case 7680ULL: goto x86_l_1e00;
	case 7687ULL: goto x86_l_1e07;
	case 7690ULL: goto x86_l_1e0a;
	case 7692ULL: goto x86_l_1e0c;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7701ULL: goto x86_l_1e15;
	case 7705ULL: goto x86_l_1e19;
	case 7707ULL: goto x86_l_1e1b;
	case 7712ULL: goto x86_l_1e20;
	case 7714ULL: goto x86_l_1e22;
	case 7716ULL: goto x86_l_1e24;
	case 7720ULL: goto x86_l_1e28;
	case 7730ULL: goto x86_l_1e32;
	case 7733ULL: goto x86_l_1e35;
	case 7738ULL: goto x86_l_1e3a;
	case 7742ULL: goto x86_l_1e3e;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7756ULL: goto x86_l_1e4c;
	case 7759ULL: goto x86_l_1e4f;
	case 7763ULL: goto x86_l_1e53;
	case 7770ULL: goto x86_l_1e5a;
	case 7773ULL: goto x86_l_1e5d;
	case 7775ULL: goto x86_l_1e5f;
	case 7782ULL: goto x86_l_1e66;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7790ULL: goto x86_l_1e6e;
	case 7792ULL: goto x86_l_1e70;
	case 7797ULL: goto x86_l_1e75;
	case 7799ULL: goto x86_l_1e77;
	case 7802ULL: goto x86_l_1e7a;
	case 7804ULL: goto x86_l_1e7c;
	case 7806ULL: goto x86_l_1e7e;
	case 7809ULL: goto x86_l_1e81;
	case 7811ULL: goto x86_l_1e83;
	case 7816ULL: goto x86_l_1e88;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7830ULL: goto x86_l_1e96;
	case 7832ULL: goto x86_l_1e98;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7844ULL: goto x86_l_1ea4;
	case 7849ULL: goto x86_l_1ea9;
	case 7854ULL: goto x86_l_1eae;
	case 7858ULL: goto x86_l_1eb2;
	case 7861ULL: goto x86_l_1eb5;
	case 7866ULL: goto x86_l_1eba;
	case 7870ULL: goto x86_l_1ebe;
	case 7872ULL: goto x86_l_1ec0;
	case 7876ULL: goto x86_l_1ec4;
	case 7882ULL: goto x86_l_1eca;
	case 7887ULL: goto x86_l_1ecf;
	case 7891ULL: goto x86_l_1ed3;
	case 7893ULL: goto x86_l_1ed5;
	case 7899ULL: goto x86_l_1edb;
	case 7904ULL: goto x86_l_1ee0;
	case 7910ULL: goto x86_l_1ee6;
	case 7915ULL: goto x86_l_1eeb;
	case 7919ULL: goto x86_l_1eef;
	case 7926ULL: goto x86_l_1ef6;
	case 7930ULL: goto x86_l_1efa;
	case 7936ULL: goto x86_l_1f00;
	case 7943ULL: goto x86_l_1f07;
	case 7947ULL: goto x86_l_1f0b;
	case 7951ULL: goto x86_l_1f0f;
	case 7956ULL: goto x86_l_1f14;
	case 7960ULL: goto x86_l_1f18;
	case 7963ULL: goto x86_l_1f1b;
	case 7966ULL: goto x86_l_1f1e;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7977ULL: goto x86_l_1f29;
	case 7980ULL: goto x86_l_1f2c;
	case 7984ULL: goto x86_l_1f30;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7995ULL: goto x86_l_1f3b;
	case 8001ULL: goto x86_l_1f41;
	case 8008ULL: goto x86_l_1f48;
	case 8012ULL: goto x86_l_1f4c;
	case 8014ULL: goto x86_l_1f4e;
	case 8021ULL: goto x86_l_1f55;
	case 8023ULL: goto x86_l_1f57;
	case 8025ULL: goto x86_l_1f59;
	case 8029ULL: goto x86_l_1f5d;
	case 8033ULL: goto x86_l_1f61;
	case 8035ULL: goto x86_l_1f63;
	case 8041ULL: goto x86_l_1f69;
	case 8046ULL: goto x86_l_1f6e;
	case 8052ULL: goto x86_l_1f74;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8064ULL: goto x86_l_1f80;
	case 8066ULL: goto x86_l_1f82;
	case 8071ULL: goto x86_l_1f87;
	case 8073ULL: goto x86_l_1f89;
	case 8075ULL: goto x86_l_1f8b;
	case 8079ULL: goto x86_l_1f8f;
	case 8081ULL: goto x86_l_1f91;
	case 8086ULL: goto x86_l_1f96;
	case 8088ULL: goto x86_l_1f98;
	case 8090ULL: goto x86_l_1f9a;
	case 8094ULL: goto x86_l_1f9e;
	case 8104ULL: goto x86_l_1fa8;
	case 8107ULL: goto x86_l_1fab;
	case 8112ULL: goto x86_l_1fb0;
	case 8116ULL: goto x86_l_1fb4;
	case 8119ULL: goto x86_l_1fb7;
	case 8124ULL: goto x86_l_1fbc;
	case 8128ULL: goto x86_l_1fc0;
	case 8132ULL: goto x86_l_1fc4;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8143ULL: goto x86_l_1fcf;
	case 8145ULL: goto x86_l_1fd1;
	case 8152ULL: goto x86_l_1fd8;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8160ULL: goto x86_l_1fe0;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8169ULL: goto x86_l_1fe9;
	case 8172ULL: goto x86_l_1fec;
	case 8174ULL: goto x86_l_1fee;
	case 8176ULL: goto x86_l_1ff0;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8186ULL: goto x86_l_1ffa;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8200ULL: goto x86_l_2008;
	case 8202ULL: goto x86_l_200a;
	case 8210ULL: goto x86_l_2012;
	case 8216ULL: goto x86_l_2018;
	case 8219ULL: goto x86_l_201b;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8230ULL: goto x86_l_2026;
	case 8236ULL: goto x86_l_202c;
	case 8240ULL: goto x86_l_2030;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8263ULL: goto x86_l_2047;
	case 8265ULL: goto x86_l_2049;
	case 8268ULL: goto x86_l_204c;
	case 8273ULL: goto x86_l_2051;
	case 8280ULL: goto x86_l_2058;
	case 8284ULL: goto x86_l_205c;
	case 8291ULL: goto x86_l_2063;
	case 8296ULL: goto x86_l_2068;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8306ULL: goto x86_l_2072;
	case 8312ULL: goto x86_l_2078;
	case 8316ULL: goto x86_l_207c;
	case 8320ULL: goto x86_l_2080;
	case 8328ULL: goto x86_l_2088;
	case 8336ULL: goto x86_l_2090;
	case 8341ULL: goto x86_l_2095;
	case 8346ULL: goto x86_l_209a;
	case 8350ULL: goto x86_l_209e;
	case 8358ULL: goto x86_l_20a6;
	case 8361ULL: goto x86_l_20a9;
	case 8369ULL: goto x86_l_20b1;
	case 8372ULL: goto x86_l_20b4;
	case 8376ULL: goto x86_l_20b8;
	case 8380ULL: goto x86_l_20bc;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8394ULL: goto x86_l_20ca;
	case 8398ULL: goto x86_l_20ce;
	case 8402ULL: goto x86_l_20d2;
	case 8405ULL: goto x86_l_20d5;
	case 8409ULL: goto x86_l_20d9;
	case 8419ULL: goto x86_l_20e3;
	case 8424ULL: goto x86_l_20e8;
	case 8430ULL: goto x86_l_20ee;
	case 8439ULL: goto x86_l_20f7;
	case 8442ULL: goto x86_l_20fa;
	case 8446ULL: goto x86_l_20fe;
	case 8452ULL: goto x86_l_2104;
	case 8456ULL: goto x86_l_2108;
	case 8462ULL: goto x86_l_210e;
	case 8466ULL: goto x86_l_2112;
	case 8472ULL: goto x86_l_2118;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8494ULL: goto x86_l_212e;
	case 8496ULL: goto x86_l_2130;
	case 8500ULL: goto x86_l_2134;
	case 8502ULL: goto x86_l_2136;
	case 8505ULL: goto x86_l_2139;
	case 8508ULL: goto x86_l_213c;
	case 8510ULL: goto x86_l_213e;
	case 8516ULL: goto x86_l_2144;
	case 8518ULL: goto x86_l_2146;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8531ULL: goto x86_l_2153;
	case 8538ULL: goto x86_l_215a;
	case 8541ULL: goto x86_l_215d;
	case 8543ULL: goto x86_l_215f;
	case 8550ULL: goto x86_l_2166;
	case 8553ULL: goto x86_l_2169;
	case 8556ULL: goto x86_l_216c;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8573ULL: goto x86_l_217d;
	case 8576ULL: goto x86_l_2180;
	case 8578ULL: goto x86_l_2182;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8587ULL: goto x86_l_218b;
	case 8591ULL: goto x86_l_218f;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b1a:
	/* 0x1b1a: mov    QWORD PTR [r15+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_1b22:
	/* 0x1b22: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b27:
	/* 0x1b27: mov    DWORD PTR [r15+0xe],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1b2b:
	/* 0x1b2b: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1b2e:
	/* 0x1b2e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1b32:
	/* 0x1b32: mov    BYTE PTR [r15+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1b36:
	/* 0x1b36: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b40:
	/* 0x1b40: test   rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b43:
	/* 0x1b43: jne    23b9 <tail_nodeport_nat_ingress_ipv6+0x23b9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9145ULL;
	}
x86_l_1b49:
	/* 0x1b49: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b4c:
	/* 0x1b4c: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1b51:
	/* 0x1b51: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b55:
	/* 0x1b55: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b59:
	/* 0x1b59: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_1b5e:
	/* 0x1b5e: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1b62:
	/* 0x1b62: jbe    1baf <tail_nodeport_nat_ingress_ipv6+0x1baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1baf;
	}
x86_l_1b64:
	/* 0x1b64: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b69:
	/* 0x1b69: mov    QWORD PTR [rax],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6c:
	/* 0x1b6c: jmp    2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	return 10567ULL;
x86_l_1b71:
	/* 0x1b71: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b7b:
	/* 0x1b7b: test   QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b80:
	/* 0x1b80: jne    23e3 <tail_nodeport_nat_ingress_ipv6+0x23e3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9187ULL;
	}
x86_l_1b86:
	/* 0x1b86: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1b8b:
	/* 0x1b8b: lea    rdx,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b8f:
	/* 0x1b8f: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1b93:
	/* 0x1b93: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_1b98:
	/* 0x1b98: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1b9b:
	/* 0x1b9b: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10567ULL;
	}
x86_l_1ba1:
	/* 0x1ba1: add    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ba4:
	/* 0x1ba4: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bad:
	/* 0x1bad: jmp    1bd9 <tail_nodeport_nat_ingress_ipv6+0x1bd9> */
	goto x86_l_1bd9;
x86_l_1baf:
	/* 0x1baf: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1bb2:
	/* 0x1bb2: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1bbb:
	/* 0x1bbb: bt     QWORD PTR [rsp+0x10],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 68719476776ULL);
x86_l_1bc2:
	/* 0x1bc2: jb     2465 <tail_nodeport_nat_ingress_ipv6+0x2465> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 9317ULL;
	}
x86_l_1bc8:
	/* 0x1bc8: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bcd:
	/* 0x1bcd: mov    QWORD PTR [rax],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd0:
	/* 0x1bd0: movzx  r13d,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_1bd9:
	/* 0x1bd9: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1bdd:
	/* 0x1bdd: jne    1be8 <tail_nodeport_nat_ingress_ipv6+0x1be8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1be8;
	}
x86_l_1bdf:
	/* 0x1bdf: mov    r14,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_1be6:
	/* 0x1be6: jmp    1bef <tail_nodeport_nat_ingress_ipv6+0x1bef> */
	goto x86_l_1bef;
x86_l_1be8:
	/* 0x1be8: mov    r14,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1bef:
	/* 0x1bef: mov    BYTE PTR [rsp+0x9d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 674309865472ULL);
x86_l_1bf7:
	/* 0x1bf7: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bfc:
	/* 0x1bfc: je     1c8d <tail_nodeport_nat_ingress_ipv6+0x1c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c8d;
	}
x86_l_1c02:
	/* 0x1c02: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1c0c:
	/* 0x1c0c: and    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 16ULL);
x86_l_1c11:
	/* 0x1c11: je     1c8d <tail_nodeport_nat_ingress_ipv6+0x1c8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c8d;
	}
x86_l_1c13:
	/* 0x1c13: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c17:
	/* 0x1c17: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1c1a:
	/* 0x1c1a: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c23:
	/* 0x1c23: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c2c:
	/* 0x1c2c: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_1c36:
	/* 0x1c36: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c3e:
	/* 0x1c3e: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c45:
	/* 0x1c45: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c52:
	/* 0x1c52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c54:
	/* 0x1c54: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c57:
	/* 0x1c57: je     1c62 <tail_nodeport_nat_ingress_ipv6+0x1c62> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c62;
	}
x86_l_1c59:
	/* 0x1c59: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c5c:
	/* 0x1c5c: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c60:
	/* 0x1c60: jmp    1c8d <tail_nodeport_nat_ingress_ipv6+0x1c8d> */
	goto x86_l_1c8d;
x86_l_1c62:
	/* 0x1c62: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1c6b:
	/* 0x1c6b: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c70:
	/* 0x1c70: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c77:
	/* 0x1c77: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1c7f:
	/* 0x1c7f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c84:
	/* 0x1c84: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c89:
	/* 0x1c89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c8b:
	/* 0x1c8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c8d:
	/* 0x1c8d: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c95:
	/* 0x1c95: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1c99:
	/* 0x1c99: jne    1d02 <tail_nodeport_nat_ingress_ipv6+0x1d02> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d02;
	}
x86_l_1c9b:
	/* 0x1c9b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ca0:
	/* 0x1ca0: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_1ca6:
	/* 0x1ca6: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1cb0:
	/* 0x1cb0: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_1cb3:
	/* 0x1cb3: jne    1d05 <tail_nodeport_nat_ingress_ipv6+0x1d05> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d05;
	}
x86_l_1cb5:
	/* 0x1cb5: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cba:
	/* 0x1cba: add    ecx,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 26ULL);
x86_l_1cbd:
	/* 0x1cbd: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cc0:
	/* 0x1cc0: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1cc3:
	/* 0x1cc3: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1cc7:
	/* 0x1cc7: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1ccb:
	/* 0x1ccb: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1ccf:
	/* 0x1ccf: ja     2642 <tail_nodeport_nat_ingress_ipv6+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 9794ULL;
	}
x86_l_1cd5:
	/* 0x1cd5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cd8:
	/* 0x1cd8: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cdb:
	/* 0x1cdb: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1cdd:
	/* 0x1cdd: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1ce2:
	/* 0x1ce2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce5:
	/* 0x1ce5: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1cea:
	/* 0x1cea: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1ced:
	/* 0x1ced: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cf1:
	/* 0x1cf1: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_1cf7:
	/* 0x1cf7: jne    24ec <tail_nodeport_nat_ingress_ipv6+0x24ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9452ULL;
	}
x86_l_1cfd:
	/* 0x1cfd: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_1d00:
	/* 0x1d00: jmp    1d05 <tail_nodeport_nat_ingress_ipv6+0x1d05> */
	goto x86_l_1d05;
x86_l_1d02:
	/* 0x1d02: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d05:
	/* 0x1d05: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d0f:
	/* 0x1d0f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1d12:
	/* 0x1d12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d14:
	/* 0x1d14: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d19:
	/* 0x1d19: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d1c:
	/* 0x1d1c: je     2639 <tail_nodeport_nat_ingress_ipv6+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9785ULL;
	}
x86_l_1d22:
	/* 0x1d22: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d27:
	/* 0x1d27: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1d2b:
	/* 0x1d2b: test   al,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 32ULL);
x86_l_1d2d:
	/* 0x1d2d: je     2639 <tail_nodeport_nat_ingress_ipv6+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9785ULL;
	}
x86_l_1d33:
	/* 0x1d33: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d38:
	/* 0x1d38: cmp    WORD PTR [rcx+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1d3d:
	/* 0x1d3d: je     2639 <tail_nodeport_nat_ingress_ipv6+0x2639> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9785ULL;
	}
x86_l_1d43:
	/* 0x1d43: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1d45:
	/* 0x1d45: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1d47:
	/* 0x1d47: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1d4a:
	/* 0x1d4a: je     1e98 <tail_nodeport_nat_ingress_ipv6+0x1e98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e98;
	}
x86_l_1d50:
	/* 0x1d50: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1d57:
	/* 0x1d57: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d5a:
	/* 0x1d5a: je     1dac <tail_nodeport_nat_ingress_ipv6+0x1dac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1dac;
	}
x86_l_1d5c:
	/* 0x1d5c: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1d63:
	/* 0x1d63: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1d66:
	/* 0x1d66: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d69:
	/* 0x1d69: jmp    1db1 <tail_nodeport_nat_ingress_ipv6+0x1db1> */
	goto x86_l_1db1;
x86_l_1d6b:
	/* 0x1d6b: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1d74:
	/* 0x1d74: mov    QWORD PTR [rsp+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d79:
	/* 0x1d79: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1d80:
	/* 0x1d80: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d88:
	/* 0x1d88: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d8d:
	/* 0x1d8d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d92:
	/* 0x1d92: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d94:
	/* 0x1d94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d96:
	/* 0x1d96: mov    r10,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da0:
	/* 0x1da0: jmp    69d <tail_nodeport_nat_ingress_ipv6+0x69d> */
	return 1693ULL;
x86_l_1da5:
	/* 0x1da5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da7:
	/* 0x1da7: jmp    f18 <tail_nodeport_nat_ingress_ipv6+0xf18> */
	return 3864ULL;
x86_l_1dac:
	/* 0x1dac: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1db1:
	/* 0x1db1: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1db5:
	/* 0x1db5: jne    1df6 <tail_nodeport_nat_ingress_ipv6+0x1df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1df6;
	}
x86_l_1db7:
	/* 0x1db7: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dbb:
	/* 0x1dbb: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1dbd:
	/* 0x1dbd: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1dc0:
	/* 0x1dc0: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1dc3:
	/* 0x1dc3: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1dc5:
	/* 0x1dc5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dca:
	/* 0x1dca: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1dce:
	/* 0x1dce: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_1dd0:
	/* 0x1dd0: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1dda:
	/* 0x1dda: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1ddd:
	/* 0x1ddd: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1de4:
	/* 0x1de4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de7:
	/* 0x1de7: je     1df6 <tail_nodeport_nat_ingress_ipv6+0x1df6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1df6;
	}
x86_l_1de9:
	/* 0x1de9: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1df0:
	/* 0x1df0: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1df3:
	/* 0x1df3: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1df6:
	/* 0x1df6: movzx  r14d,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1dfc:
	/* 0x1dfc: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e00:
	/* 0x1e00: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1e07:
	/* 0x1e07: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0a:
	/* 0x1e0a: je     1e1b <tail_nodeport_nat_ingress_ipv6+0x1e1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1b;
	}
x86_l_1e0c:
	/* 0x1e0c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1e11:
	/* 0x1e11: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e13:
	/* 0x1e13: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e15:
	/* 0x1e15: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1e19:
	/* 0x1e19: jmp    1e3e <tail_nodeport_nat_ingress_ipv6+0x1e3e> */
	goto x86_l_1e3e;
x86_l_1e1b:
	/* 0x1e1b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1e20:
	/* 0x1e20: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e22:
	/* 0x1e22: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e24:
	/* 0x1e24: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1e28:
	/* 0x1e28: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1e32:
	/* 0x1e32: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1e35:
	/* 0x1e35: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1e3a:
	/* 0x1e3a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1e3e:
	/* 0x1e3e: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e40:
	/* 0x1e40: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e45:
	/* 0x1e45: mov    DWORD PTR [rdx+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e48:
	/* 0x1e48: movzx  ecx,BYTE PTR [rdx+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1e4c:
	/* 0x1e4c: mov    edx,DWORD PTR [rdx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1e4f:
	/* 0x1e4f: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1e53:
	/* 0x1e53: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1e5a:
	/* 0x1e5a: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5d:
	/* 0x1e5d: je     1e70 <tail_nodeport_nat_ingress_ipv6+0x1e70> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e70;
	}
x86_l_1e5f:
	/* 0x1e5f: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e66:
	/* 0x1e66: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e68:
	/* 0x1e68: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1e6b:
	/* 0x1e6b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e6e:
	/* 0x1e6e: jmp    1e75 <tail_nodeport_nat_ingress_ipv6+0x1e75> */
	goto x86_l_1e75;
x86_l_1e70:
	/* 0x1e70: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1e75:
	/* 0x1e75: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e77:
	/* 0x1e77: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e7a:
	/* 0x1e7a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1e7c:
	/* 0x1e7c: jb     1e83 <tail_nodeport_nat_ingress_ipv6+0x1e83> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1e83;
	}
x86_l_1e7e:
	/* 0x1e7e: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_1e81:
	/* 0x1e81: je     1e98 <tail_nodeport_nat_ingress_ipv6+0x1e98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e98;
	}
x86_l_1e83:
	/* 0x1e83: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e88:
	/* 0x1e88: mov    BYTE PTR [rcx+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    DWORD PTR [rcx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1e8f:
	/* 0x1e8f: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1e96:
	/* 0x1e96: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e98:
	/* 0x1e98: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1e9f:
	/* 0x1e9f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ea2:
	/* 0x1ea2: je     1eba <tail_nodeport_nat_ingress_ipv6+0x1eba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1eba;
	}
x86_l_1ea4:
	/* 0x1ea4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea9:
	/* 0x1ea9: inc QWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1eae:
	/* 0x1eae: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb2:
	/* 0x1eb2: sub    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1eb5:
	/* 0x1eb5: add QWORD PTR [rcx+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1eba:
	/* 0x1eba: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1ebe:
	/* 0x1ebe: je     1f14 <tail_nodeport_nat_ingress_ipv6+0x1f14> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f14;
	}
x86_l_1ec0:
	/* 0x1ec0: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1ec4:
	/* 0x1ec4: jne    200a <tail_nodeport_nat_ingress_ipv6+0x200a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_200a;
	}
x86_l_1eca:
	/* 0x1eca: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ecf:
	/* 0x1ecf: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1ed3:
	/* 0x1ed3: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1ed5:
	/* 0x1ed5: je     200a <tail_nodeport_nat_ingress_ipv6+0x200a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200a;
	}
x86_l_1edb:
	/* 0x1edb: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ee0:
	/* 0x1ee0: mov    WORD PTR [rcx+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1ee6:
	/* 0x1ee6: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1eeb:
	/* 0x1eeb: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1eef:
	/* 0x1eef: mov    r14,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1ef6:
	/* 0x1ef6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1efa:
	/* 0x1efa: je     2563 <tail_nodeport_nat_ingress_ipv6+0x2563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9571ULL;
	}
x86_l_1f00:
	/* 0x1f00: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1f07:
	/* 0x1f07: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1f0b:
	/* 0x1f0b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f0f:
	/* 0x1f0f: jmp    2569 <tail_nodeport_nat_ingress_ipv6+0x2569> */
	return 9577ULL;
x86_l_1f14:
	/* 0x1f14: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f18:
	/* 0x1f18: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1f1b:
	/* 0x1f1b: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f23:
	/* 0x1f23: or     ax,WORD PTR [rdx+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1f27:
	/* 0x1f27: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1f29:
	/* 0x1f29: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    WORD PTR [rdx+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f30:
	/* 0x1f30: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f37:
	/* 0x1f37: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f39:
	/* 0x1f39: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_1f3b:
	/* 0x1f3b: je     200a <tail_nodeport_nat_ingress_ipv6+0x200a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200a;
	}
x86_l_1f41:
	/* 0x1f41: mov    r14,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1f48:
	/* 0x1f48: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4c:
	/* 0x1f4c: je     1f6e <tail_nodeport_nat_ingress_ipv6+0x1f6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f6e;
	}
x86_l_1f4e:
	/* 0x1f4e: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1f55:
	/* 0x1f55: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f57:
	/* 0x1f57: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f59:
	/* 0x1f59: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1f5d:
	/* 0x1f5d: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f61:
	/* 0x1f61: jmp    1f74 <tail_nodeport_nat_ingress_ipv6+0x1f74> */
	goto x86_l_1f74;
x86_l_1f63:
	/* 0x1f63: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1f69:
	/* 0x1f69: jmp    b2c <tail_nodeport_nat_ingress_ipv6+0xb2c> */
	return 2860ULL;
x86_l_1f6e:
	/* 0x1f6e: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1f74:
	/* 0x1f74: movzx  ebp,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1f79:
	/* 0x1f79: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1f7c:
	/* 0x1f7c: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f80:
	/* 0x1f80: je     1f91 <tail_nodeport_nat_ingress_ipv6+0x1f91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f91;
	}
x86_l_1f82:
	/* 0x1f82: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1f87:
	/* 0x1f87: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f89:
	/* 0x1f89: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f8b:
	/* 0x1f8b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1f8f:
	/* 0x1f8f: jmp    1fb4 <tail_nodeport_nat_ingress_ipv6+0x1fb4> */
	goto x86_l_1fb4;
x86_l_1f91:
	/* 0x1f91: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1f96:
	/* 0x1f96: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f98:
	/* 0x1f98: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1f9a:
	/* 0x1f9a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1f9e:
	/* 0x1f9e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1fa8:
	/* 0x1fa8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1fab:
	/* 0x1fab: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1fb0:
	/* 0x1fb0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1fb4:
	/* 0x1fb4: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fb7:
	/* 0x1fb7: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fbc:
	/* 0x1fbc: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fc0:
	/* 0x1fc0: movzx  ecx,BYTE PTR [rdx+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1fc4:
	/* 0x1fc4: mov    edx,DWORD PTR [rdx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1fc7:
	/* 0x1fc7: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1fcb:
	/* 0x1fcb: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fcf:
	/* 0x1fcf: je     1fe2 <tail_nodeport_nat_ingress_ipv6+0x1fe2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fe2;
	}
x86_l_1fd1:
	/* 0x1fd1: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1fd8:
	/* 0x1fd8: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fda:
	/* 0x1fda: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1fdd:
	/* 0x1fdd: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1fe0:
	/* 0x1fe0: jmp    1fe7 <tail_nodeport_nat_ingress_ipv6+0x1fe7> */
	goto x86_l_1fe7;
x86_l_1fe2:
	/* 0x1fe2: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1fe7:
	/* 0x1fe7: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fe9:
	/* 0x1fe9: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1fec:
	/* 0x1fec: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1fee:
	/* 0x1fee: jb     1ff5 <tail_nodeport_nat_ingress_ipv6+0x1ff5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ff5;
	}
x86_l_1ff0:
	/* 0x1ff0: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1ff3:
	/* 0x1ff3: je     200a <tail_nodeport_nat_ingress_ipv6+0x200a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_200a;
	}
x86_l_1ff5:
	/* 0x1ff5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    BYTE PTR [rcx+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1ffe:
	/* 0x1ffe: mov    DWORD PTR [rcx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2001:
	/* 0x2001: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2008:
	/* 0x2008: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_200a:
	/* 0x200a: test   BYTE PTR [rsp+0x9d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 674309865474ULL);
x86_l_2012:
	/* 0x2012: jne    2642 <tail_nodeport_nat_ingress_ipv6+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9794ULL;
	}
x86_l_2018:
	/* 0x2018: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_201b:
	/* 0x201b: lea    rcx,[rax+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_201f:
	/* 0x201f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2022:
	/* 0x2022: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2026:
	/* 0x2026: ja     2942 <tail_nodeport_nat_ingress_ipv6+0x2942> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10562ULL;
	}
x86_l_202c:
	/* 0x202c: movzx  ecx,BYTE PTR [rax+0x15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 21ULL);
x86_l_2030:
	/* 0x2030: mov    ebp,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967100ULL);
x86_l_2035:
	/* 0x2035: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_2038:
	/* 0x2038: jb     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10567ULL;
	}
x86_l_203e:
	/* 0x203e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2043:
	/* 0x2043: movzx  edx,WORD PTR [rdx+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2047:
	/* 0x2047: dec    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_2049:
	/* 0x2049: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_204c:
	/* 0x204c: mov    WORD PTR [rsp+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2051:
	/* 0x2051: mov    r15,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_2058:
	/* 0x2058: movzx  eax,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_205c:
	/* 0x205c: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_2063:
	/* 0x2063: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2068:
	/* 0x2068: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_206d:
	/* 0x206d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_206f:
	/* 0x206f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2072:
	/* 0x2072: je     2302 <tail_nodeport_nat_ingress_ipv6+0x2302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8962ULL;
	}
x86_l_2078:
	/* 0x2078: movzx  esi,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_207c:
	/* 0x207c: movzx  ecx,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2080:
	/* 0x2080: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2088:
	/* 0x2088: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2090:
	/* 0x2090: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2095:
	/* 0x2095: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_209a:
	/* 0x209a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_209e:
	/* 0x209e: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_20a6:
	/* 0x20a6: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20a9:
	/* 0x20a9: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_20b1:
	/* 0x20b1: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b4:
	/* 0x20b4: mov    rdi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20b8:
	/* 0x20b8: lea    rdx,[rcx+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_20bc:
	/* 0x20bc: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_20c1:
	/* 0x20c1: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_20c4:
	/* 0x20c4: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_20ca:
	/* 0x20ca: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ce:
	/* 0x20ce: mov    QWORD PTR [rcx+0x1e],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_20d2:
	/* 0x20d2: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d5:
	/* 0x20d5: mov    QWORD PTR [rcx+0x16],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_20d9:
	/* 0x20d9: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_20e3:
	/* 0x20e3: test   QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e8:
	/* 0x20e8: jne    2302 <tail_nodeport_nat_ingress_ipv6+0x2302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8962ULL;
	}
x86_l_20ee:
	/* 0x20ee: movzx  r9d,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_20f7:
	/* 0x20f7: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_20fa:
	/* 0x20fa: cmp    r9d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 58ULL);
x86_l_20fe:
	/* 0x20fe: je     2219 <tail_nodeport_nat_ingress_ipv6+0x2219> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8729ULL;
	}
x86_l_2104:
	/* 0x2104: cmp    r9d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 17ULL);
x86_l_2108:
	/* 0x2108: je     2221 <tail_nodeport_nat_ingress_ipv6+0x2221> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8737ULL;
	}
x86_l_210e:
	/* 0x210e: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_2112:
	/* 0x2112: jne    222e <tail_nodeport_nat_ingress_ipv6+0x222e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8750ULL;
	}
x86_l_2118:
	/* 0x2118: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_211e:
	/* 0x211e: jmp    222a <tail_nodeport_nat_ingress_ipv6+0x222a> */
	return 8746ULL;
x86_l_2123:
	/* 0x2123: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_2128:
	/* 0x2128: cmp    WORD PTR [rsp+0x28],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691846ULL);
x86_l_212e:
	/* 0x212e: jne    216c <tail_nodeport_nat_ingress_ipv6+0x216c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_216c;
	}
x86_l_2130:
	/* 0x2130: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2134:
	/* 0x2134: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2136:
	/* 0x2136: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2139:
	/* 0x2139: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_213c:
	/* 0x213c: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_213e:
	/* 0x213e: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2144:
	/* 0x2144: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2146:
	/* 0x2146: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_214b:
	/* 0x214b: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_2150:
	/* 0x2150: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2153:
	/* 0x2153: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_215a:
	/* 0x215a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_215d:
	/* 0x215d: je     216c <tail_nodeport_nat_ingress_ipv6+0x216c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_216c;
	}
x86_l_215f:
	/* 0x215f: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2166:
	/* 0x2166: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2169:
	/* 0x2169: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_216c:
	/* 0x216c: movzx  r13d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_2172:
	/* 0x2172: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2176:
	/* 0x2176: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_217d:
	/* 0x217d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2180:
	/* 0x2180: je     2191 <tail_nodeport_nat_ingress_ipv6+0x2191> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8593ULL;
	}
x86_l_2182:
	/* 0x2182: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2187:
	/* 0x2187: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2189:
	/* 0x2189: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_218b:
	/* 0x218b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_218f:
	/* 0x218f: jmp    21b4 <tail_nodeport_nat_ingress_ipv6+0x21b4> */
	return 8628ULL;
	return 8593ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8600ULL: goto x86_l_2198;
	case 8602ULL: goto x86_l_219a;
	case 8606ULL: goto x86_l_219e;
	case 8616ULL: goto x86_l_21a8;
	case 8619ULL: goto x86_l_21ab;
	case 8624ULL: goto x86_l_21b0;
	case 8628ULL: goto x86_l_21b4;
	case 8630ULL: goto x86_l_21b6;
	case 8633ULL: goto x86_l_21b9;
	case 8638ULL: goto x86_l_21be;
	case 8644ULL: goto x86_l_21c4;
	case 8649ULL: goto x86_l_21c9;
	case 8653ULL: goto x86_l_21cd;
	case 8660ULL: goto x86_l_21d4;
	case 8663ULL: goto x86_l_21d7;
	case 8665ULL: goto x86_l_21d9;
	case 8672ULL: goto x86_l_21e0;
	case 8674ULL: goto x86_l_21e2;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8682ULL: goto x86_l_21ea;
	case 8687ULL: goto x86_l_21ef;
	case 8689ULL: goto x86_l_21f1;
	case 8692ULL: goto x86_l_21f4;
	case 8694ULL: goto x86_l_21f6;
	case 8699ULL: goto x86_l_21fb;
	case 8703ULL: goto x86_l_21ff;
	case 8705ULL: goto x86_l_2201;
	case 8708ULL: goto x86_l_2204;
	case 8714ULL: goto x86_l_220a;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8729ULL: goto x86_l_2219;
	case 8735ULL: goto x86_l_221f;
	case 8737ULL: goto x86_l_2221;
	case 8743ULL: goto x86_l_2227;
	case 8746ULL: goto x86_l_222a;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8753ULL: goto x86_l_2231;
	case 8755ULL: goto x86_l_2233;
	case 8758ULL: goto x86_l_2236;
	case 8760ULL: goto x86_l_2238;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8784ULL: goto x86_l_2250;
	case 8786ULL: goto x86_l_2252;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8797ULL: goto x86_l_225d;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8813ULL: goto x86_l_226d;
	case 8817ULL: goto x86_l_2271;
	case 8823ULL: goto x86_l_2277;
	case 8825ULL: goto x86_l_2279;
	case 8831ULL: goto x86_l_227f;
	case 8836ULL: goto x86_l_2284;
	case 8842ULL: goto x86_l_228a;
	case 8847ULL: goto x86_l_228f;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8858ULL: goto x86_l_229a;
	case 8861ULL: goto x86_l_229d;
	case 8866ULL: goto x86_l_22a2;
	case 8869ULL: goto x86_l_22a5;
	case 8873ULL: goto x86_l_22a9;
	case 8877ULL: goto x86_l_22ad;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8890ULL: goto x86_l_22ba;
	case 8896ULL: goto x86_l_22c0;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8904ULL: goto x86_l_22c8;
	case 8908ULL: goto x86_l_22cc;
	case 8911ULL: goto x86_l_22cf;
	case 8915ULL: goto x86_l_22d3;
	case 8917ULL: goto x86_l_22d5;
	case 8919ULL: goto x86_l_22d7;
	case 8921ULL: goto x86_l_22d9;
	case 8924ULL: goto x86_l_22dc;
	case 8927ULL: goto x86_l_22df;
	case 8930ULL: goto x86_l_22e2;
	case 8932ULL: goto x86_l_22e4;
	case 8934ULL: goto x86_l_22e6;
	case 8937ULL: goto x86_l_22e9;
	case 8939ULL: goto x86_l_22eb;
	case 8943ULL: goto x86_l_22ef;
	case 8945ULL: goto x86_l_22f1;
	case 8950ULL: goto x86_l_22f6;
	case 8953ULL: goto x86_l_22f9;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8962ULL: goto x86_l_2302;
	case 8965ULL: goto x86_l_2305;
	case 8969ULL: goto x86_l_2309;
	case 8974ULL: goto x86_l_230e;
	case 8978ULL: goto x86_l_2312;
	case 8984ULL: goto x86_l_2318;
	case 8992ULL: goto x86_l_2320;
	case 8999ULL: goto x86_l_2327;
	case 9004ULL: goto x86_l_232c;
	case 9010ULL: goto x86_l_2332;
	case 9013ULL: goto x86_l_2335;
	case 9016ULL: goto x86_l_2338;
	case 9022ULL: goto x86_l_233e;
	case 9025ULL: goto x86_l_2341;
	case 9033ULL: goto x86_l_2349;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9048ULL: goto x86_l_2358;
	case 9051ULL: goto x86_l_235b;
	case 9053ULL: goto x86_l_235d;
	case 9056ULL: goto x86_l_2360;
	case 9059ULL: goto x86_l_2363;
	case 9064ULL: goto x86_l_2368;
	case 9066ULL: goto x86_l_236a;
	case 9074ULL: goto x86_l_2372;
	case 9076ULL: goto x86_l_2374;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9093ULL: goto x86_l_2385;
	case 9101ULL: goto x86_l_238d;
	case 9105ULL: goto x86_l_2391;
	case 9113ULL: goto x86_l_2399;
	case 9117ULL: goto x86_l_239d;
	case 9125ULL: goto x86_l_23a5;
	case 9129ULL: goto x86_l_23a9;
	case 9137ULL: goto x86_l_23b1;
	case 9140ULL: goto x86_l_23b4;
	case 9145ULL: goto x86_l_23b9;
	case 9152ULL: goto x86_l_23c0;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9164ULL: goto x86_l_23cc;
	case 9167ULL: goto x86_l_23cf;
	case 9173ULL: goto x86_l_23d5;
	case 9175ULL: goto x86_l_23d7;
	case 9182ULL: goto x86_l_23de;
	case 9187ULL: goto x86_l_23e3;
	case 9192ULL: goto x86_l_23e8;
	case 9197ULL: goto x86_l_23ed;
	case 9202ULL: goto x86_l_23f2;
	case 9206ULL: goto x86_l_23f6;
	case 9210ULL: goto x86_l_23fa;
	case 9214ULL: goto x86_l_23fe;
	case 9219ULL: goto x86_l_2403;
	case 9222ULL: goto x86_l_2406;
	case 9228ULL: goto x86_l_240c;
	case 9231ULL: goto x86_l_240f;
	case 9235ULL: goto x86_l_2413;
	case 9238ULL: goto x86_l_2416;
	case 9242ULL: goto x86_l_241a;
	case 9246ULL: goto x86_l_241e;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9258ULL: goto x86_l_242a;
	case 9264ULL: goto x86_l_2430;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9276ULL: goto x86_l_243c;
	case 9282ULL: goto x86_l_2442;
	case 9285ULL: goto x86_l_2445;
	case 9288ULL: goto x86_l_2448;
	case 9294ULL: goto x86_l_244e;
	case 9297ULL: goto x86_l_2451;
	case 9300ULL: goto x86_l_2454;
	case 9304ULL: goto x86_l_2458;
	case 9307ULL: goto x86_l_245b;
	case 9309ULL: goto x86_l_245d;
	case 9312ULL: goto x86_l_2460;
	case 9317ULL: goto x86_l_2465;
	case 9325ULL: goto x86_l_246d;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9344ULL: goto x86_l_2480;
	case 9346ULL: goto x86_l_2482;
	case 9348ULL: goto x86_l_2484;
	case 9354ULL: goto x86_l_248a;
	case 9358ULL: goto x86_l_248e;
	case 9361ULL: goto x86_l_2491;
	case 9370ULL: goto x86_l_249a;
	case 9379ULL: goto x86_l_24a3;
	case 9389ULL: goto x86_l_24ad;
	case 9395ULL: goto x86_l_24b3;
	case 9403ULL: goto x86_l_24bb;
	case 9410ULL: goto x86_l_24c2;
	case 9418ULL: goto x86_l_24ca;
	case 9423ULL: goto x86_l_24cf;
	case 9425ULL: goto x86_l_24d1;
	case 9428ULL: goto x86_l_24d4;
	case 9430ULL: goto x86_l_24d6;
	case 9433ULL: goto x86_l_24d9;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9447ULL: goto x86_l_24e7;
	case 9452ULL: goto x86_l_24ec;
	case 9458ULL: goto x86_l_24f2;
	case 9463ULL: goto x86_l_24f7;
	case 9472ULL: goto x86_l_2500;
	case 9477ULL: goto x86_l_2505;
	case 9484ULL: goto x86_l_250c;
	case 9492ULL: goto x86_l_2514;
	case 9497ULL: goto x86_l_2519;
	case 9502ULL: goto x86_l_251e;
	case 9504ULL: goto x86_l_2520;
	case 9506ULL: goto x86_l_2522;
	case 9511ULL: goto x86_l_2527;
	case 9514ULL: goto x86_l_252a;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9522ULL: goto x86_l_2532;
	case 9526ULL: goto x86_l_2536;
	case 9528ULL: goto x86_l_2538;
	case 9531ULL: goto x86_l_253b;
	case 9534ULL: goto x86_l_253e;
	case 9536ULL: goto x86_l_2540;
	case 9538ULL: goto x86_l_2542;
	case 9541ULL: goto x86_l_2545;
	case 9543ULL: goto x86_l_2547;
	case 9547ULL: goto x86_l_254b;
	case 9549ULL: goto x86_l_254d;
	case 9554ULL: goto x86_l_2552;
	case 9557ULL: goto x86_l_2555;
	case 9560ULL: goto x86_l_2558;
	case 9563ULL: goto x86_l_255b;
	case 9566ULL: goto x86_l_255e;
	case 9571ULL: goto x86_l_2563;
	case 9577ULL: goto x86_l_2569;
	case 9581ULL: goto x86_l_256d;
	case 9583ULL: goto x86_l_256f;
	case 9587ULL: goto x86_l_2573;
	case 9589ULL: goto x86_l_2575;
	case 9592ULL: goto x86_l_2578;
	case 9595ULL: goto x86_l_257b;
	case 9597ULL: goto x86_l_257d;
	case 9602ULL: goto x86_l_2582;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9619ULL: goto x86_l_2593;
	case 9623ULL: goto x86_l_2597;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9636ULL: goto x86_l_25a4;
	case 9640ULL: goto x86_l_25a8;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9652ULL: goto x86_l_25b4;
	case 9656ULL: goto x86_l_25b8;
	case 9658ULL: goto x86_l_25ba;
	case 9663ULL: goto x86_l_25bf;
	case 9665ULL: goto x86_l_25c1;
	case 9667ULL: goto x86_l_25c3;
	case 9671ULL: goto x86_l_25c7;
	case 9673ULL: goto x86_l_25c9;
	case 9678ULL: goto x86_l_25ce;
	case 9680ULL: goto x86_l_25d0;
	case 9682ULL: goto x86_l_25d2;
	case 9686ULL: goto x86_l_25d6;
	case 9696ULL: goto x86_l_25e0;
	case 9699ULL: goto x86_l_25e3;
	case 9704ULL: goto x86_l_25e8;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9720ULL: goto x86_l_25f8;
	case 9724ULL: goto x86_l_25fc;
	case 9727ULL: goto x86_l_25ff;
	case 9731ULL: goto x86_l_2603;
	case 9735ULL: goto x86_l_2607;
	case 9737ULL: goto x86_l_2609;
	case 9744ULL: goto x86_l_2610;
	case 9746ULL: goto x86_l_2612;
	case 9749ULL: goto x86_l_2615;
	case 9752ULL: goto x86_l_2618;
	case 9754ULL: goto x86_l_261a;
	case 9759ULL: goto x86_l_261f;
	case 9761ULL: goto x86_l_2621;
	case 9764ULL: goto x86_l_2624;
	case 9766ULL: goto x86_l_2626;
	case 9768ULL: goto x86_l_2628;
	case 9771ULL: goto x86_l_262b;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9782ULL: goto x86_l_2636;
	case 9785ULL: goto x86_l_2639;
	case 9792ULL: goto x86_l_2640;
	case 9794ULL: goto x86_l_2642;
	case 9798ULL: goto x86_l_2646;
	case 9802ULL: goto x86_l_264a;
	case 9810ULL: goto x86_l_2652;
	case 9813ULL: goto x86_l_2655;
	case 9817ULL: goto x86_l_2659;
	case 9822ULL: goto x86_l_265e;
	case 9827ULL: goto x86_l_2663;
	case 9830ULL: goto x86_l_2666;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9844ULL: goto x86_l_2674;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9863ULL: goto x86_l_2687;
	case 9868ULL: goto x86_l_268c;
	case 9871ULL: goto x86_l_268f;
	case 9877ULL: goto x86_l_2695;
	case 9884ULL: goto x86_l_269c;
	case 9890ULL: goto x86_l_26a2;
	case 9897ULL: goto x86_l_26a9;
	case 9905ULL: goto x86_l_26b1;
	case 9908ULL: goto x86_l_26b4;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9922ULL: goto x86_l_26c2;
	case 9929ULL: goto x86_l_26c9;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9946ULL: goto x86_l_26da;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9956ULL: goto x86_l_26e4;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9970ULL: goto x86_l_26f2;
	case 9972ULL: goto x86_l_26f4;
	case 9978ULL: goto x86_l_26fa;
	case 9986ULL: goto x86_l_2702;
	case 9993ULL: goto x86_l_2709;
	case 10000ULL: goto x86_l_2710;
	case 10007ULL: goto x86_l_2717;
	case 10009ULL: goto x86_l_2719;
	case 10015ULL: goto x86_l_271f;
	case 10018ULL: goto x86_l_2722;
	case 10020ULL: goto x86_l_2724;
	case 10023ULL: goto x86_l_2727;
	case 10029ULL: goto x86_l_272d;
	case 10031ULL: goto x86_l_272f;
	case 10034ULL: goto x86_l_2732;
	case 10036ULL: goto x86_l_2734;
	case 10042ULL: goto x86_l_273a;
	case 10044ULL: goto x86_l_273c;
	case 10047ULL: goto x86_l_273f;
	case 10050ULL: goto x86_l_2742;
	case 10056ULL: goto x86_l_2748;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10063ULL: goto x86_l_274f;
	case 10069ULL: goto x86_l_2755;
	case 10072ULL: goto x86_l_2758;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10083ULL: goto x86_l_2763;
	case 10085ULL: goto x86_l_2765;
	case 10092ULL: goto x86_l_276c;
	case 10094ULL: goto x86_l_276e;
	case 10102ULL: goto x86_l_2776;
	case 10106ULL: goto x86_l_277a;
	case 10109ULL: goto x86_l_277d;
	case 10112ULL: goto x86_l_2780;
	case 10115ULL: goto x86_l_2783;
	case 10123ULL: goto x86_l_278b;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10133ULL: goto x86_l_2795;
	case 10135ULL: goto x86_l_2797;
	case 10138ULL: goto x86_l_279a;
	case 10141ULL: goto x86_l_279d;
	case 10147ULL: goto x86_l_27a3;
	case 10150ULL: goto x86_l_27a6;
	case 10152ULL: goto x86_l_27a8;
	case 10155ULL: goto x86_l_27ab;
	case 10161ULL: goto x86_l_27b1;
	case 10164ULL: goto x86_l_27b4;
	case 10167ULL: goto x86_l_27b7;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2191:
	/* 0x2191: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2196:
	/* 0x2196: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2198:
	/* 0x2198: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_219a:
	/* 0x219a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_219e:
	/* 0x219e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_21a8:
	/* 0x21a8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_21ab:
	/* 0x21ab: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_21b0:
	/* 0x21b0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_21b4:
	/* 0x21b4: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21b6:
	/* 0x21b6: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_21b9:
	/* 0x21b9: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21be:
	/* 0x21be: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_21c4:
	/* 0x21c4: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_21c9:
	/* 0x21c9: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_21cd:
	/* 0x21cd: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_21d4:
	/* 0x21d4: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d7:
	/* 0x21d7: je     21ea <tail_nodeport_nat_ingress_ipv6+0x21ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ea;
	}
x86_l_21d9:
	/* 0x21d9: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_21e0:
	/* 0x21e0: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e2:
	/* 0x21e2: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_21e5:
	/* 0x21e5: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_21e8:
	/* 0x21e8: jmp    21ef <tail_nodeport_nat_ingress_ipv6+0x21ef> */
	goto x86_l_21ef;
x86_l_21ea:
	/* 0x21ea: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_21ef:
	/* 0x21ef: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21f1:
	/* 0x21f1: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_21f4:
	/* 0x21f4: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_21f6:
	/* 0x21f6: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21fb:
	/* 0x21fb: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21ff:
	/* 0x21ff: jb     220a <tail_nodeport_nat_ingress_ipv6+0x220a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_220a;
	}
x86_l_2201:
	/* 0x2201: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_2204:
	/* 0x2204: je     deb <tail_nodeport_nat_ingress_ipv6+0xdeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3563ULL;
	}
x86_l_220a:
	/* 0x220a: mov    BYTE PTR [r12+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_220f:
	/* 0x220f: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2214:
	/* 0x2214: jmp    de2 <tail_nodeport_nat_ingress_ipv6+0xde2> */
	return 3554ULL;
x86_l_2219:
	/* 0x2219: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_221f:
	/* 0x221f: jmp    222a <tail_nodeport_nat_ingress_ipv6+0x222a> */
	goto x86_l_222a;
x86_l_2221:
	/* 0x2221: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2227:
	/* 0x2227: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222a:
	/* 0x222a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_222c:
	/* 0x222c: jmp    2233 <tail_nodeport_nat_ingress_ipv6+0x2233> */
	goto x86_l_2233;
x86_l_222e:
	/* 0x222e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2231:
	/* 0x2231: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_2233:
	/* 0x2233: test   si,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_16);
x86_l_2236:
	/* 0x2236: je     2277 <tail_nodeport_nat_ingress_ipv6+0x2277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2277;
	}
x86_l_2238:
	/* 0x2238: movzx  r8d,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_2241:
	/* 0x2241: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_2246:
	/* 0x2246: cmp    r9d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 16ULL);
x86_l_224a:
	/* 0x224a: jg     225d <tail_nodeport_nat_ingress_ipv6+0x225d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_225d;
	}
x86_l_224c:
	/* 0x224c: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_2250:
	/* 0x2250: je     2277 <tail_nodeport_nat_ingress_ipv6+0x2277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2277;
	}
x86_l_2252:
	/* 0x2252: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_2256:
	/* 0x2256: je     226d <tail_nodeport_nat_ingress_ipv6+0x226d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_226d;
	}
x86_l_2258:
	/* 0x2258: jmp    e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	return 3699ULL;
x86_l_225d:
	/* 0x225d: cmp    r9d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 58ULL);
x86_l_2261:
	/* 0x2261: je     2277 <tail_nodeport_nat_ingress_ipv6+0x2277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2277;
	}
x86_l_2263:
	/* 0x2263: cmp    r9d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 17ULL);
x86_l_2267:
	/* 0x2267: jne    e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3699ULL;
	}
x86_l_226d:
	/* 0x226d: cmp    si,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_16);
x86_l_2271:
	/* 0x2271: jne    23ed <tail_nodeport_nat_ingress_ipv6+0x23ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23ed;
	}
x86_l_2277:
	/* 0x2277: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_2279:
	/* 0x2279: jne    2302 <tail_nodeport_nat_ingress_ipv6+0x2302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2302;
	}
x86_l_227f:
	/* 0x227f: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2284:
	/* 0x2284: mov    r9d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 28ULL);
x86_l_228a:
	/* 0x228a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_228f:
	/* 0x228f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2292:
	/* 0x2292: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2297:
	/* 0x2297: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_229a:
	/* 0x229a: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_229d:
	/* 0x229d: add    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_22a2:
	/* 0x22a2: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22a5:
	/* 0x22a5: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_22a9:
	/* 0x22a9: lea    rsi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_22ad:
	/* 0x22ad: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_22b1:
	/* 0x22b1: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_22b6:
	/* 0x22b6: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_22ba:
	/* 0x22ba: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_22c0:
	/* 0x22c0: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22c3:
	/* 0x22c3: movzx  edx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_22c6:
	/* 0x22c6: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_22c8:
	/* 0x22c8: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_22cc:
	/* 0x22cc: or     sil,r15b */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_8, X86_ALU_OR);
x86_l_22cf:
	/* 0x22cf: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_22d3:
	/* 0x22d3: jne    2302 <tail_nodeport_nat_ingress_ipv6+0x2302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2302;
	}
x86_l_22d5:
	/* 0x22d5: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_22d7:
	/* 0x22d7: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22d9:
	/* 0x22d9: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_22dc:
	/* 0x22dc: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_22df:
	/* 0x22df: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_22e2:
	/* 0x22e2: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22e4:
	/* 0x22e4: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_22e6:
	/* 0x22e6: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_22e9:
	/* 0x22e9: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22eb:
	/* 0x22eb: cmp    dx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 65535ULL);
x86_l_22ef:
	/* 0x22ef: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_22f1:
	/* 0x22f1: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_22f6:
	/* 0x22f6: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_22f9:
	/* 0x22f9: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_22fc:
	/* 0x22fc: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_22ff:
	/* 0x22ff: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2302:
	/* 0x2302: mov    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2305:
	/* 0x2305: lea    rax,[r15+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_2309:
	/* 0x2309: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_230e:
	/* 0x230e: cmp    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2312:
	/* 0x2312: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 10567ULL;
	}
x86_l_2318:
	/* 0x2318: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2320:
	/* 0x2320: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2327:
	/* 0x2327: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_232c:
	/* 0x232c: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2332:
	/* 0x2332: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2335:
	/* 0x2335: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2338:
	/* 0x2338: je     2ccf <tail_nodeport_nat_ingress_ipv6+0x2ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11471ULL;
	}
x86_l_233e:
	/* 0x233e: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2341:
	/* 0x2341: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2349:
	/* 0x2349: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2350:
	/* 0x2350: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2355:
	/* 0x2355: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2358:
	/* 0x2358: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_235b:
	/* 0x235b: je     2363 <tail_nodeport_nat_ingress_ipv6+0x2363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2363;
	}
x86_l_235d:
	/* 0x235d: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_2360:
	/* 0x2360: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2363:
	/* 0x2363: cmp    QWORD PTR [r15+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_2368:
	/* 0x2368: jne    2381 <tail_nodeport_nat_ingress_ipv6+0x2381> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2381;
	}
x86_l_236a:
	/* 0x236a: cmp    DWORD PTR [r15+0x1e],0xffff0000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 133143920640ULL);
x86_l_2372:
	/* 0x2372: jne    2381 <tail_nodeport_nat_ingress_ipv6+0x2381> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2381;
	}
x86_l_2374:
	/* 0x2374: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2377:
	/* 0x2377: mov    ebp,0xffffff5f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967135ULL);
x86_l_237c:
	/* 0x237c: jmp    2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	return 10567ULL;
x86_l_2381:
	/* 0x2381: mov    rax,QWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_2385:
	/* 0x2385: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_238d:
	/* 0x238d: mov    rax,QWORD PTR [r15+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_2391:
	/* 0x2391: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2399:
	/* 0x2399: mov    rax,QWORD PTR [r15+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_239d:
	/* 0x239d: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_23a5:
	/* 0x23a5: mov    rax,QWORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_23a9:
	/* 0x23a9: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_23b1:
	/* 0x23b1: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_23b4:
	/* 0x23b4: jmp    2ae1 <tail_nodeport_nat_ingress_ipv6+0x2ae1> */
	return 10977ULL;
x86_l_23b9:
	/* 0x23b9: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_23c0:
	/* 0x23c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23c5:
	/* 0x23c5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ca:
	/* 0x23ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23cc:
	/* 0x23cc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23cf:
	/* 0x23cf: je     24e2 <tail_nodeport_nat_ingress_ipv6+0x24e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24e2;
	}
x86_l_23d5:
	/* 0x23d5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23d7:
	/* 0x23d7: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_23de:
	/* 0x23de: jmp    1bc8 <tail_nodeport_nat_ingress_ipv6+0x1bc8> */
	return 7112ULL;
x86_l_23e3:
	/* 0x23e3: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_23e8:
	/* 0x23e8: jmp    2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	return 10567ULL;
x86_l_23ed:
	/* 0x23ed: mov    r9d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23f2:
	/* 0x23f2: movzx  r10d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23f6:
	/* 0x23f6: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_23fa:
	/* 0x23fa: add    r11,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_23fe:
	/* 0x23fe: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2403:
	/* 0x2403: cmp    r11,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RDI, X86_WIDTH_64);
x86_l_2406:
	/* 0x2406: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_240c:
	/* 0x240c: add    r10,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_240f:
	/* 0x240f: mov    WORD PTR [r10],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R10, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2413:
	/* 0x2413: add    r9d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2416:
	/* 0x2416: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_241a:
	/* 0x241a: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_241e:
	/* 0x241e: add    r10,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2422:
	/* 0x2422: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_2427:
	/* 0x2427: cmp    r10,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RDI, X86_WIDTH_64);
x86_l_242a:
	/* 0x242a: ja     e73 <tail_nodeport_nat_ingress_ipv6+0xe73> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3699ULL;
	}
x86_l_2430:
	/* 0x2430: add    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2433:
	/* 0x2433: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_2436:
	/* 0x2436: jne    2442 <tail_nodeport_nat_ingress_ipv6+0x2442> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2442;
	}
x86_l_2438:
	/* 0x2438: cmp    WORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243c:
	/* 0x243c: je     2277 <tail_nodeport_nat_ingress_ipv6+0x2277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2277;
	}
x86_l_2442:
	/* 0x2442: movzx  edi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2445:
	/* 0x2445: test   r8d,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_32);
x86_l_2448:
	/* 0x2448: je     2527 <tail_nodeport_nat_ingress_ipv6+0x2527> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2527;
	}
x86_l_244e:
	/* 0x244e: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2451:
	/* 0x2451: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2454:
	/* 0x2454: adc    r8d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_2458:
	/* 0x2458: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_245b:
	/* 0x245b: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_245d:
	/* 0x245d: add    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2460:
	/* 0x2460: jmp    252e <tail_nodeport_nat_ingress_ipv6+0x252e> */
	goto x86_l_252e;
x86_l_2465:
	/* 0x2465: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_246d:
	/* 0x246d: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_2474:
	/* 0x2474: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2479:
	/* 0x2479: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_247e:
	/* 0x247e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2480:
	/* 0x2480: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2482:
	/* 0x2482: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2484:
	/* 0x2484: je     1bc8 <tail_nodeport_nat_ingress_ipv6+0x1bc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7112ULL;
	}
x86_l_248a:
	/* 0x248a: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_248e:
	/* 0x248e: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_2491:
	/* 0x2491: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_249a:
	/* 0x249a: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_24a3:
	/* 0x24a3: movabs rax,0x7201a9010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654124810ULL);
x86_l_24ad:
	/* 0x24ad: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_24b3:
	/* 0x24b3: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24bb:
	/* 0x24bb: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_24c2:
	/* 0x24c2: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_24ca:
	/* 0x24ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24cf:
	/* 0x24cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24d1:
	/* 0x24d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24d4:
	/* 0x24d4: je     24f7 <tail_nodeport_nat_ingress_ipv6+0x24f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24f7;
	}
x86_l_24d6:
	/* 0x24d6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24d9:
	/* 0x24d9: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_24dd:
	/* 0x24dd: jmp    1bc8 <tail_nodeport_nat_ingress_ipv6+0x1bc8> */
	return 7112ULL;
x86_l_24e2:
	/* 0x24e2: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_24e7:
	/* 0x24e7: jmp    1b64 <tail_nodeport_nat_ingress_ipv6+0x1b64> */
	return 7012ULL;
x86_l_24ec:
	/* 0x24ec: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_24f2:
	/* 0x24f2: jmp    1d05 <tail_nodeport_nat_ingress_ipv6+0x1d05> */
	return 7429ULL;
x86_l_24f7:
	/* 0x24f7: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_2500:
	/* 0x2500: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2505:
	/* 0x2505: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_250c:
	/* 0x250c: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2514:
	/* 0x2514: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2519:
	/* 0x2519: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_251e:
	/* 0x251e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2520:
	/* 0x2520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2522:
	/* 0x2522: jmp    1bc8 <tail_nodeport_nat_ingress_ipv6+0x1bc8> */
	return 7112ULL;
x86_l_2527:
	/* 0x2527: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_252a:
	/* 0x252a: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_252c:
	/* 0x252c: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_252e:
	/* 0x252e: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_2532:
	/* 0x2532: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2536:
	/* 0x2536: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2538:
	/* 0x2538: movzx  esi,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_253b:
	/* 0x253b: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_253e:
	/* 0x253e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2540:
	/* 0x2540: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_2542:
	/* 0x2542: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2545:
	/* 0x2545: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2547:
	/* 0x2547: cmp    si,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 65535ULL);
x86_l_254b:
	/* 0x254b: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_254d:
	/* 0x254d: mov    edi,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 65535ULL);
x86_l_2552:
	/* 0x2552: cmovne edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_2555:
	/* 0x2555: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_2558:
	/* 0x2558: cmovne edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_255b:
	/* 0x255b: mov    WORD PTR [rcx],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_255e:
	/* 0x255e: jmp    2277 <tail_nodeport_nat_ingress_ipv6+0x2277> */
	goto x86_l_2277;
x86_l_2563:
	/* 0x2563: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2569:
	/* 0x2569: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_256d:
	/* 0x256d: jne    25ac <tail_nodeport_nat_ingress_ipv6+0x25ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25ac;
	}
x86_l_256f:
	/* 0x256f: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2573:
	/* 0x2573: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2575:
	/* 0x2575: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2578:
	/* 0x2578: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_257b:
	/* 0x257b: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_257d:
	/* 0x257d: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2582:
	/* 0x2582: mov    WORD PTR [rdx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2586:
	/* 0x2586: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2588:
	/* 0x2588: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_258d:
	/* 0x258d: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_2593:
	/* 0x2593: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2597:
	/* 0x2597: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_259b:
	/* 0x259b: je     25ac <tail_nodeport_nat_ingress_ipv6+0x25ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ac;
	}
x86_l_259d:
	/* 0x259d: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_25a4:
	/* 0x25a4: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_25a8:
	/* 0x25a8: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_25ac:
	/* 0x25ac: movzx  ebp,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_25b1:
	/* 0x25b1: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_25b4:
	/* 0x25b4: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b8:
	/* 0x25b8: je     25c9 <tail_nodeport_nat_ingress_ipv6+0x25c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25c9;
	}
x86_l_25ba:
	/* 0x25ba: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_25bf:
	/* 0x25bf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25c1:
	/* 0x25c1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_25c3:
	/* 0x25c3: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_25c7:
	/* 0x25c7: jmp    25ec <tail_nodeport_nat_ingress_ipv6+0x25ec> */
	goto x86_l_25ec;
x86_l_25c9:
	/* 0x25c9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_25ce:
	/* 0x25ce: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d0:
	/* 0x25d0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_25d2:
	/* 0x25d2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_25d6:
	/* 0x25d6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_25e0:
	/* 0x25e0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_25e3:
	/* 0x25e3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_25e8:
	/* 0x25e8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_25ec:
	/* 0x25ec: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25ef:
	/* 0x25ef: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25f4:
	/* 0x25f4: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25f8:
	/* 0x25f8: movzx  ecx,BYTE PTR [rdx+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_25fc:
	/* 0x25fc: mov    edx,DWORD PTR [rdx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_25ff:
	/* 0x25ff: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2603:
	/* 0x2603: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2607:
	/* 0x2607: je     261a <tail_nodeport_nat_ingress_ipv6+0x261a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_261a;
	}
x86_l_2609:
	/* 0x2609: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2610:
	/* 0x2610: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2612:
	/* 0x2612: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2615:
	/* 0x2615: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2618:
	/* 0x2618: jmp    261f <tail_nodeport_nat_ingress_ipv6+0x261f> */
	goto x86_l_261f;
x86_l_261a:
	/* 0x261a: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_261f:
	/* 0x261f: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2621:
	/* 0x2621: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2624:
	/* 0x2624: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2626:
	/* 0x2626: jb     262d <tail_nodeport_nat_ingress_ipv6+0x262d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_262d;
	}
x86_l_2628:
	/* 0x2628: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_262b:
	/* 0x262b: je     2642 <tail_nodeport_nat_ingress_ipv6+0x2642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2642;
	}
x86_l_262d:
	/* 0x262d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2632:
	/* 0x2632: mov    BYTE PTR [rcx+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_2636:
	/* 0x2636: mov    DWORD PTR [rcx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2639:
	/* 0x2639: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2640:
	/* 0x2640: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2642:
	/* 0x2642: lea    r14,[r15+0x26] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2646:
	/* 0x2646: add    r15,0x16 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 22ULL);
x86_l_264a:
	/* 0x264a: mov    DWORD PTR [rsp+0x30],0x100 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430464ULL);
x86_l_2652:
	/* 0x2652: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2655:
	/* 0x2655: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2659:
	/* 0x2659: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_265e:
	/* 0x265e: mov    QWORD PTR [rsp+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2663:
	/* 0x2663: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2666:
	/* 0x2666: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_266a:
	/* 0x266a: mov    QWORD PTR [rsp+0x44],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_266f:
	/* 0x266f: mov    QWORD PTR [rsp+0x4c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_2674:
	/* 0x2674: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_egress_gw_policy_v6)));
x86_l_267b:
	/* 0x267b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2680:
	/* 0x2680: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2685:
	/* 0x2685: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2687:
	/* 0x2687: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_268c:
	/* 0x268c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_268f:
	/* 0x268f: je     2c65 <tail_nodeport_nat_ingress_ipv6+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_2695:
	/* 0x2695: test   DWORD PTR [rax+0x10],0xfeffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72997666815ULL);
x86_l_269c:
	/* 0x269c: je     2c65 <tail_nodeport_nat_ingress_ipv6+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_26a2:
	/* 0x26a2: mov    WORD PTR [rsp+0x36],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928234496ULL);
x86_l_26a9:
	/* 0x26a9: mov    DWORD PTR [rsp+0x30],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430368ULL);
x86_l_26b1:
	/* 0x26b1: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26b4:
	/* 0x26b4: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b8:
	/* 0x26b8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26bd:
	/* 0x26bd: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26c2:
	/* 0x26c2: mov    WORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_26c9:
	/* 0x26c9: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_26d0:
	/* 0x26d0: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d5:
	/* 0x26d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26da:
	/* 0x26da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26dc:
	/* 0x26dc: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26e1:
	/* 0x26e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26e4:
	/* 0x26e4: je     2c65 <tail_nodeport_nat_ingress_ipv6+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_26ea:
	/* 0x26ea: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26ef:
	/* 0x26ef: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26f2:
	/* 0x26f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f4:
	/* 0x26f4: je     2c65 <tail_nodeport_nat_ingress_ipv6+0x2c65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11365ULL;
	}
x86_l_26fa:
	/* 0x26fa: movzx  ecx,WORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 154ULL);
x86_l_2702:
	/* 0x2702: mov    edx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2709:
	/* 0x2709: mov    esi,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_2710:
	/* 0x2710: mov    edi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2717:
	/* 0x2717: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2719:
	/* 0x2719: rorx   r8d,edi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_32, 0, 28ULL);
x86_l_271f:
	/* 0x271f: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2722:
	/* 0x2722: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2724:
	/* 0x2724: sub    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2727:
	/* 0x2727: rorx   edx,r8d,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_32, 0, 26ULL);
x86_l_272d:
	/* 0x272d: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_272f:
	/* 0x272f: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2732:
	/* 0x2732: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2734:
	/* 0x2734: rorx   esi,edx,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 24ULL);
x86_l_273a:
	/* 0x273a: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_273c:
	/* 0x273c: add    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_273f:
	/* 0x273f: sub    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2742:
	/* 0x2742: rorx   edi,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_2748:
	/* 0x2748: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_274b:
	/* 0x274b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_274d:
	/* 0x274d: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_274f:
	/* 0x274f: rorx   r8d,edi,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_32, 0, 13ULL);
x86_l_2755:
	/* 0x2755: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2758:
	/* 0x2758: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_275a:
	/* 0x275a: sub    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_275d:
	/* 0x275d: rorx   edx,r8d,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_32, 0, 28ULL);
x86_l_2763:
	/* 0x2763: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2765:
	/* 0x2765: mov    esi,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_276c:
	/* 0x276c: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_276e:
	/* 0x276e: mov    r9d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2776:
	/* 0x2776: shl    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_277a:
	/* 0x277a: or     r9d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_277d:
	/* 0x277d: add    r9d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2780:
	/* 0x2780: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2783:
	/* 0x2783: movzx  ecx,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_278b:
	/* 0x278b: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_278d:
	/* 0x278d: sub    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_278f:
	/* 0x278f: rorx   edx,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_2795:
	/* 0x2795: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2797:
	/* 0x2797: add    ecx,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_279a:
	/* 0x279a: sub    r9d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_279d:
	/* 0x279d: rorx   r12d,edx,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R12, X86_RDX, X86_WIDTH_32, 0, 26ULL);
x86_l_27a3:
	/* 0x27a3: xor    r12d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27a6:
	/* 0x27a6: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27a8:
	/* 0x27a8: sub    ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_27ab:
	/* 0x27ab: rorx   r13d,r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R13, X86_R12, X86_WIDTH_32, 0, 24ULL);
x86_l_27b1:
	/* 0x27b1: xor    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27b4:
	/* 0x27b4: add    r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27b7:
	/* 0x27b7: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
	return 10170ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10170ULL: goto x86_l_27ba;
	case 10176ULL: goto x86_l_27c0;
	case 10179ULL: goto x86_l_27c3;
	case 10182ULL: goto x86_l_27c6;
	case 10186ULL: goto x86_l_27ca;
	case 10193ULL: goto x86_l_27d1;
	case 10195ULL: goto x86_l_27d3;
	case 10203ULL: goto x86_l_27db;
	case 10212ULL: goto x86_l_27e4;
	case 10221ULL: goto x86_l_27ed;
	case 10230ULL: goto x86_l_27f6;
	case 10239ULL: goto x86_l_27ff;
	case 10248ULL: goto x86_l_2808;
	case 10257ULL: goto x86_l_2811;
	case 10266ULL: goto x86_l_281a;
	case 10270ULL: goto x86_l_281e;
	case 10272ULL: goto x86_l_2820;
	case 10276ULL: goto x86_l_2824;
	case 10285ULL: goto x86_l_282d;
	case 10292ULL: goto x86_l_2834;
	case 10295ULL: goto x86_l_2837;
	case 10297ULL: goto x86_l_2839;
	case 10302ULL: goto x86_l_283e;
	case 10305ULL: goto x86_l_2841;
	case 10309ULL: goto x86_l_2845;
	case 10317ULL: goto x86_l_284d;
	case 10321ULL: goto x86_l_2851;
	case 10326ULL: goto x86_l_2856;
	case 10331ULL: goto x86_l_285b;
	case 10334ULL: goto x86_l_285e;
	case 10339ULL: goto x86_l_2863;
	case 10344ULL: goto x86_l_2868;
	case 10346ULL: goto x86_l_286a;
	case 10354ULL: goto x86_l_2872;
	case 10356ULL: goto x86_l_2874;
	case 10358ULL: goto x86_l_2876;
	case 10362ULL: goto x86_l_287a;
	case 10366ULL: goto x86_l_287e;
	case 10368ULL: goto x86_l_2880;
	case 10376ULL: goto x86_l_2888;
	case 10380ULL: goto x86_l_288c;
	case 10383ULL: goto x86_l_288f;
	case 10392ULL: goto x86_l_2898;
	case 10401ULL: goto x86_l_28a1;
	case 10411ULL: goto x86_l_28ab;
	case 10419ULL: goto x86_l_28b3;
	case 10426ULL: goto x86_l_28ba;
	case 10434ULL: goto x86_l_28c2;
	case 10439ULL: goto x86_l_28c7;
	case 10441ULL: goto x86_l_28c9;
	case 10444ULL: goto x86_l_28cc;
	case 10446ULL: goto x86_l_28ce;
	case 10449ULL: goto x86_l_28d1;
	case 10453ULL: goto x86_l_28d5;
	case 10455ULL: goto x86_l_28d7;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10476ULL: goto x86_l_28ec;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10496ULL: goto x86_l_2900;
	case 10498ULL: goto x86_l_2902;
	case 10503ULL: goto x86_l_2907;
	case 10507ULL: goto x86_l_290b;
	case 10513ULL: goto x86_l_2911;
	case 10518ULL: goto x86_l_2916;
	case 10521ULL: goto x86_l_2919;
	case 10525ULL: goto x86_l_291d;
	case 10529ULL: goto x86_l_2921;
	case 10532ULL: goto x86_l_2924;
	case 10540ULL: goto x86_l_292c;
	case 10545ULL: goto x86_l_2931;
	case 10548ULL: goto x86_l_2934;
	case 10553ULL: goto x86_l_2939;
	case 10555ULL: goto x86_l_293b;
	case 10558ULL: goto x86_l_293e;
	case 10560ULL: goto x86_l_2940;
	case 10562ULL: goto x86_l_2942;
	case 10567ULL: goto x86_l_2947;
	case 10571ULL: goto x86_l_294b;
	case 10575ULL: goto x86_l_294f;
	case 10580ULL: goto x86_l_2954;
	case 10583ULL: goto x86_l_2957;
	case 10586ULL: goto x86_l_295a;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10599ULL: goto x86_l_2967;
	case 10601ULL: goto x86_l_2969;
	case 10604ULL: goto x86_l_296c;
	case 10610ULL: goto x86_l_2972;
	case 10613ULL: goto x86_l_2975;
	case 10616ULL: goto x86_l_2978;
	case 10622ULL: goto x86_l_297e;
	case 10625ULL: goto x86_l_2981;
	case 10629ULL: goto x86_l_2985;
	case 10631ULL: goto x86_l_2987;
	case 10637ULL: goto x86_l_298d;
	case 10639ULL: goto x86_l_298f;
	case 10643ULL: goto x86_l_2993;
	case 10645ULL: goto x86_l_2995;
	case 10651ULL: goto x86_l_299b;
	case 10653ULL: goto x86_l_299d;
	case 10655ULL: goto x86_l_299f;
	case 10661ULL: goto x86_l_29a5;
	case 10663ULL: goto x86_l_29a7;
	case 10665ULL: goto x86_l_29a9;
	case 10671ULL: goto x86_l_29af;
	case 10673ULL: goto x86_l_29b1;
	case 10675ULL: goto x86_l_29b3;
	case 10681ULL: goto x86_l_29b9;
	case 10683ULL: goto x86_l_29bb;
	case 10685ULL: goto x86_l_29bd;
	case 10691ULL: goto x86_l_29c3;
	case 10693ULL: goto x86_l_29c5;
	case 10695ULL: goto x86_l_29c7;
	case 10701ULL: goto x86_l_29cd;
	case 10703ULL: goto x86_l_29cf;
	case 10705ULL: goto x86_l_29d1;
	case 10708ULL: goto x86_l_29d4;
	case 10710ULL: goto x86_l_29d6;
	case 10713ULL: goto x86_l_29d9;
	case 10719ULL: goto x86_l_29df;
	case 10727ULL: goto x86_l_29e7;
	case 10735ULL: goto x86_l_29ef;
	case 10743ULL: goto x86_l_29f7;
	case 10751ULL: goto x86_l_29ff;
	case 10759ULL: goto x86_l_2a07;
	case 10763ULL: goto x86_l_2a0b;
	case 10770ULL: goto x86_l_2a12;
	case 10777ULL: goto x86_l_2a19;
	case 10780ULL: goto x86_l_2a1c;
	case 10783ULL: goto x86_l_2a1f;
	case 10785ULL: goto x86_l_2a21;
	case 10788ULL: goto x86_l_2a24;
	case 10790ULL: goto x86_l_2a26;
	case 10797ULL: goto x86_l_2a2d;
	case 10799ULL: goto x86_l_2a2f;
	case 10806ULL: goto x86_l_2a36;
	case 10813ULL: goto x86_l_2a3d;
	case 10816ULL: goto x86_l_2a40;
	case 10820ULL: goto x86_l_2a44;
	case 10827ULL: goto x86_l_2a4b;
	case 10830ULL: goto x86_l_2a4e;
	case 10836ULL: goto x86_l_2a54;
	case 10844ULL: goto x86_l_2a5c;
	case 10847ULL: goto x86_l_2a5f;
	case 10853ULL: goto x86_l_2a65;
	case 10859ULL: goto x86_l_2a6b;
	case 10863ULL: goto x86_l_2a6f;
	case 10866ULL: goto x86_l_2a72;
	case 10872ULL: goto x86_l_2a78;
	case 10878ULL: goto x86_l_2a7e;
	case 10882ULL: goto x86_l_2a82;
	case 10885ULL: goto x86_l_2a85;
	case 10889ULL: goto x86_l_2a89;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10899ULL: goto x86_l_2a93;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10909ULL: goto x86_l_2a9d;
	case 10911ULL: goto x86_l_2a9f;
	case 10914ULL: goto x86_l_2aa2;
	case 10917ULL: goto x86_l_2aa5;
	case 10919ULL: goto x86_l_2aa7;
	case 10921ULL: goto x86_l_2aa9;
	case 10924ULL: goto x86_l_2aac;
	case 10926ULL: goto x86_l_2aae;
	case 10928ULL: goto x86_l_2ab0;
	case 10933ULL: goto x86_l_2ab5;
	case 10940ULL: goto x86_l_2abc;
	case 10951ULL: goto x86_l_2ac7;
	case 10956ULL: goto x86_l_2acc;
	case 10959ULL: goto x86_l_2acf;
	case 10966ULL: goto x86_l_2ad6;
	case 10974ULL: goto x86_l_2ade;
	case 10977ULL: goto x86_l_2ae1;
	case 10985ULL: goto x86_l_2ae9;
	case 10990ULL: goto x86_l_2aee;
	case 10993ULL: goto x86_l_2af1;
	case 10998ULL: goto x86_l_2af6;
	case 11000ULL: goto x86_l_2af8;
	case 11002ULL: goto x86_l_2afa;
	case 11005ULL: goto x86_l_2afd;
	case 11010ULL: goto x86_l_2b02;
	case 11013ULL: goto x86_l_2b05;
	case 11015ULL: goto x86_l_2b07;
	case 11018ULL: goto x86_l_2b0a;
	case 11024ULL: goto x86_l_2b10;
	case 11032ULL: goto x86_l_2b18;
	case 11037ULL: goto x86_l_2b1d;
	case 11044ULL: goto x86_l_2b24;
	case 11049ULL: goto x86_l_2b29;
	case 11054ULL: goto x86_l_2b2e;
	case 11056ULL: goto x86_l_2b30;
	case 11059ULL: goto x86_l_2b33;
	case 11061ULL: goto x86_l_2b35;
	case 11065ULL: goto x86_l_2b39;
	case 11071ULL: goto x86_l_2b3f;
	case 11074ULL: goto x86_l_2b42;
	case 11076ULL: goto x86_l_2b44;
	case 11081ULL: goto x86_l_2b49;
	case 11088ULL: goto x86_l_2b50;
	case 11093ULL: goto x86_l_2b55;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11103ULL: goto x86_l_2b5f;
	case 11110ULL: goto x86_l_2b66;
	case 11114ULL: goto x86_l_2b6a;
	case 11120ULL: goto x86_l_2b70;
	case 11123ULL: goto x86_l_2b73;
	case 11129ULL: goto x86_l_2b79;
	case 11137ULL: goto x86_l_2b81;
	case 11145ULL: goto x86_l_2b89;
	case 11147ULL: goto x86_l_2b8b;
	case 11154ULL: goto x86_l_2b92;
	case 11156ULL: goto x86_l_2b94;
	case 11159ULL: goto x86_l_2b97;
	case 11163ULL: goto x86_l_2b9b;
	case 11168ULL: goto x86_l_2ba0;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11181ULL: goto x86_l_2bad;
	case 11189ULL: goto x86_l_2bb5;
	case 11193ULL: goto x86_l_2bb9;
	case 11200ULL: goto x86_l_2bc0;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11209ULL: goto x86_l_2bc9;
	case 11213ULL: goto x86_l_2bcd;
	case 11219ULL: goto x86_l_2bd3;
	case 11227ULL: goto x86_l_2bdb;
	case 11231ULL: goto x86_l_2bdf;
	case 11238ULL: goto x86_l_2be6;
	case 11241ULL: goto x86_l_2be9;
	case 11243ULL: goto x86_l_2beb;
	case 11250ULL: goto x86_l_2bf2;
	case 11255ULL: goto x86_l_2bf7;
	case 11257ULL: goto x86_l_2bf9;
	case 11260ULL: goto x86_l_2bfc;
	case 11266ULL: goto x86_l_2c02;
	case 11269ULL: goto x86_l_2c05;
	case 11273ULL: goto x86_l_2c09;
	case 11277ULL: goto x86_l_2c0d;
	case 11282ULL: goto x86_l_2c12;
	case 11285ULL: goto x86_l_2c15;
	case 11288ULL: goto x86_l_2c18;
	case 11294ULL: goto x86_l_2c1e;
	case 11298ULL: goto x86_l_2c22;
	case 11302ULL: goto x86_l_2c26;
	case 11304ULL: goto x86_l_2c28;
	case 11306ULL: goto x86_l_2c2a;
	case 11310ULL: goto x86_l_2c2e;
	case 11313ULL: goto x86_l_2c31;
	case 11319ULL: goto x86_l_2c37;
	case 11324ULL: goto x86_l_2c3c;
	case 11328ULL: goto x86_l_2c40;
	case 11332ULL: goto x86_l_2c44;
	case 11335ULL: goto x86_l_2c47;
	case 11339ULL: goto x86_l_2c4b;
	case 11341ULL: goto x86_l_2c4d;
	case 11346ULL: goto x86_l_2c52;
	case 11351ULL: goto x86_l_2c57;
	case 11356ULL: goto x86_l_2c5c;
	case 11359ULL: goto x86_l_2c5f;
	case 11361ULL: goto x86_l_2c61;
	case 11363ULL: goto x86_l_2c63;
	case 11365ULL: goto x86_l_2c65;
	case 11368ULL: goto x86_l_2c68;
	case 11370ULL: goto x86_l_2c6a;
	case 11376ULL: goto x86_l_2c70;
	case 11379ULL: goto x86_l_2c73;
	case 11385ULL: goto x86_l_2c79;
	case 11388ULL: goto x86_l_2c7c;
	case 11394ULL: goto x86_l_2c82;
	case 11402ULL: goto x86_l_2c8a;
	case 11409ULL: goto x86_l_2c91;
	case 11414ULL: goto x86_l_2c96;
	case 11419ULL: goto x86_l_2c9b;
	case 11421ULL: goto x86_l_2c9d;
	case 11424ULL: goto x86_l_2ca0;
	case 11426ULL: goto x86_l_2ca2;
	case 11433ULL: goto x86_l_2ca9;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11448ULL: goto x86_l_2cb8;
	case 11453ULL: goto x86_l_2cbd;
	case 11455ULL: goto x86_l_2cbf;
	case 11460ULL: goto x86_l_2cc4;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11473ULL: goto x86_l_2cd1;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27ba:
	/* 0x27ba: rorx   r15d,r13d,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R15, X86_R13, X86_WIDTH_32, 0, 16ULL);
x86_l_27c0:
	/* 0x27c0: xor    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27c3:
	/* 0x27c3: add    r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27c6:
	/* 0x27c6: lea    edx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_27ca:
	/* 0x27ca: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_hash_init6_seed)));
x86_l_27d1:
	/* 0x27d1: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27d3:
	/* 0x27d3: mov    DWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_27db:
	/* 0x27db: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_27e4:
	/* 0x27e4: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_27ed:
	/* 0x27ed: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_27f6:
	/* 0x27f6: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_27ff:
	/* 0x27ff: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_2808:
	/* 0x2808: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2811:
	/* 0x2811: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_281a:
	/* 0x281a: mov    DWORD PTR [rsp+0x28],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_281e:
	/* 0x281e: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2820:
	/* 0x2820: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2824:
	/* 0x2824: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_282d:
	/* 0x282d: mov    rcx,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_src)));
x86_l_2834:
	/* 0x2834: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2837:
	/* 0x2837: je     2880 <tail_nodeport_nat_ingress_ipv6+0x2880> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2880;
	}
x86_l_2839:
	/* 0x2839: mov    BYTE PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_283e:
	/* 0x283e: mov    ecx,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2841:
	/* 0x2841: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2845:
	/* 0x2845: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_284d:
	/* 0x284d: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2851:
	/* 0x2851: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2856:
	/* 0x2856: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_285b:
	/* 0x285b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_285e:
	/* 0x285e: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_2863:
	/* 0x2863: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2868:
	/* 0x2868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_286a:
	/* 0x286a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2872:
	/* 0x2872: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2874:
	/* 0x2874: jne    2888 <tail_nodeport_nat_ingress_ipv6+0x2888> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2888;
	}
x86_l_2876:
	/* 0x2876: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_287a:
	/* 0x287a: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_287e:
	/* 0x287e: jmp    2888 <tail_nodeport_nat_ingress_ipv6+0x2888> */
	goto x86_l_2888;
x86_l_2880:
	/* 0x2880: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2888:
	/* 0x2888: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_288c:
	/* 0x288c: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_288f:
	/* 0x288f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2898:
	/* 0x2898: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_28a1:
	/* 0x28a1: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_28ab:
	/* 0x28ab: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28b3:
	/* 0x28b3: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_28ba:
	/* 0x28ba: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28c2:
	/* 0x28c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28c7:
	/* 0x28c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c9:
	/* 0x28c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28cc:
	/* 0x28cc: je     28d7 <tail_nodeport_nat_ingress_ipv6+0x28d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28d7;
	}
x86_l_28ce:
	/* 0x28ce: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_28d1:
	/* 0x28d1: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_28d5:
	/* 0x28d5: jmp    2902 <tail_nodeport_nat_ingress_ipv6+0x2902> */
	goto x86_l_2902;
x86_l_28d7:
	/* 0x28d7: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_28e0:
	/* 0x28e0: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28e5:
	/* 0x28e5: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_28ec:
	/* 0x28ec: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28f4:
	/* 0x28f4: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28f9:
	/* 0x28f9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28fe:
	/* 0x28fe: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2900:
	/* 0x2900: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2902:
	/* 0x2902: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2907:
	/* 0x2907: test   BYTE PTR [rax+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_290b:
	/* 0x290b: jne    2abc <tail_nodeport_nat_ingress_ipv6+0x2abc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2abc;
	}
x86_l_2911:
	/* 0x2911: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2916:
	/* 0x2916: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2919:
	/* 0x2919: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_291d:
	/* 0x291d: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2921:
	/* 0x2921: sub    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_2924:
	/* 0x2924: mov    QWORD PTR [rsp+0x100],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_292c:
	/* 0x292c: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2931:
	/* 0x2931: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2934:
	/* 0x2934: mov    esi,0xffffffce */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967246ULL);
x86_l_2939:
	/* 0x2939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293b:
	/* 0x293b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_293e:
	/* 0x293e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2940:
	/* 0x2940: je     2954 <tail_nodeport_nat_ingress_ipv6+0x2954> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2954;
	}
x86_l_2942:
	/* 0x2942: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_2947:
	/* 0x2947: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_294b:
	/* 0x294b: movzx  r15d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_294f:
	/* 0x294f: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	return 1261ULL;
x86_l_2954:
	/* 0x2954: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2957:
	/* 0x2957: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_295a:
	/* 0x295a: add    rax,0x32 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 50ULL);
x86_l_295e:
	/* 0x295e: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_2963:
	/* 0x2963: cmp    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2967:
	/* 0x2967: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2947;
	}
x86_l_2969:
	/* 0x2969: sub    r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_296c:
	/* 0x296c: rorx   ecx,r15d,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_R15, X86_WIDTH_32, 0, 13ULL);
x86_l_2972:
	/* 0x2972: xor    ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2975:
	/* 0x2975: sub    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2978:
	/* 0x2978: rorx   eax,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_297e:
	/* 0x297e: xor    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2981:
	/* 0x2981: add    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_2985:
	/* 0x2985: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2987:
	/* 0x2987: rorx   edx,ecx,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 18ULL);
x86_l_298d:
	/* 0x298d: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_298f:
	/* 0x298f: mov    esi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2993:
	/* 0x2993: xor    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2995:
	/* 0x2995: rorx   edx,eax,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 21ULL);
x86_l_299b:
	/* 0x299b: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_299d:
	/* 0x299d: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_299f:
	/* 0x299f: rorx   edx,esi,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 7ULL);
x86_l_29a5:
	/* 0x29a5: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29a7:
	/* 0x29a7: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29a9:
	/* 0x29a9: rorx   edx,ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 16ULL);
x86_l_29af:
	/* 0x29af: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29b1:
	/* 0x29b1: xor    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29b3:
	/* 0x29b3: rorx   edx,eax,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 28ULL);
x86_l_29b9:
	/* 0x29b9: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29bb:
	/* 0x29bb: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29bd:
	/* 0x29bd: rorx   edx,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_29c3:
	/* 0x29c3: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29c5:
	/* 0x29c5: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29c7:
	/* 0x29c7: rorx   ecx,ecx,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 8ULL);
x86_l_29cd:
	/* 0x29cd: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_29cf:
	/* 0x29cf: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_29d1:
	/* 0x29d1: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_29d4:
	/* 0x29d4: xor    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_29d6:
	/* 0x29d6: mov    rax,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_64);
x86_l_29d9:
	/* 0x29d9: mov    WORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_29df:
	/* 0x29df: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_29e7:
	/* 0x29e7: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_29ef:
	/* 0x29ef: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_29f7:
	/* 0x29f7: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_29ff:
	/* 0x29ff: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a07:
	/* 0x2a07: lea    rdx,[rdi+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2a0b:
	/* 0x2a0b: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a12:
	/* 0x2a12: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_2a19:
	/* 0x2a19: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2a1c:
	/* 0x2a1c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a1f:
	/* 0x2a1f: je     2a2f <tail_nodeport_nat_ingress_ipv6+0x2a2f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a2f;
	}
x86_l_2a21:
	/* 0x2a21: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a24:
	/* 0x2a24: jne    2a3d <tail_nodeport_nat_ingress_ipv6+0x2a3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a3d;
	}
x86_l_2a26:
	/* 0x2a26: mov    DWORD PTR [rdi+0x2a],0x58650000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 181871640576ULL);
x86_l_2a2d:
	/* 0x2a2d: jmp    2a36 <tail_nodeport_nat_ingress_ipv6+0x2a36> */
	goto x86_l_2a36;
x86_l_2a2f:
	/* 0x2a2f: mov    DWORD PTR [rdi+0x2a],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180388626440ULL);
x86_l_2a36:
	/* 0x2a36: mov    DWORD PTR [rdi+0x2e],0x20000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 197568626688ULL);
x86_l_2a3d:
	/* 0x2a3d: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_2a40:
	/* 0x2a40: mov    WORD PTR [rdi+0x22],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2a44:
	/* 0x2a44: mov    rax,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_port)));
x86_l_2a4b:
	/* 0x2a4b: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2a4e:
	/* 0x2a4e: movbe  WORD PTR [rdi+0x24],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2a54:
	/* 0x2a54: mov    rcx,QWORD PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2a5c:
	/* 0x2a5c: lea    eax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a5f:
	/* 0x2a5f: movbe  WORD PTR [rdi+0x26],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2a65:
	/* 0x2a65: mov    WORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2a6b:
	/* 0x2a6b: mov    BYTE PTR [rdi+0xe],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542213ULL);
x86_l_2a6f:
	/* 0x2a6f: add    ecx,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 36ULL);
x86_l_2a72:
	/* 0x2a72: movbe  WORD PTR [rdi+0x10],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_2a78:
	/* 0x2a78: mov    WORD PTR [rdi+0x16],0x1140 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489284928ULL);
x86_l_2a7e:
	/* 0x2a7e: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a82:
	/* 0x2a82: mov    DWORD PTR [rdi+0x1a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_2a85:
	/* 0x2a85: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a89:
	/* 0x2a89: mov    DWORD PTR [rdi+0x1e],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_2a8c:
	/* 0x2a8c: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2a91:
	/* 0x2a91: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a93:
	/* 0x2a93: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a95:
	/* 0x2a95: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_2a9a:
	/* 0x2a9a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a9d:
	/* 0x2a9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9f:
	/* 0x2a9f: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2aa2:
	/* 0x2aa2: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2aa5:
	/* 0x2aa5: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2aa7:
	/* 0x2aa7: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2aa9:
	/* 0x2aa9: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2aac:
	/* 0x2aac: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2aae:
	/* 0x2aae: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2ab0:
	/* 0x2ab0: mov    WORD PTR [r14+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ab5:
	/* 0x2ab5: mov    WORD PTR [r14+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2abc:
	/* 0x2abc: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2ac7:
	/* 0x2ac7: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2acc:
	/* 0x2acc: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2acf:
	/* 0x2acf: mov    DWORD PTR [rsp+0xc8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2ad6:
	/* 0x2ad6: mov    BYTE PTR [rsp+0xa8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505730ULL);
x86_l_2ade:
	/* 0x2ade: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ae1:
	/* 0x2ae1: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2ae9:
	/* 0x2ae9: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_2aee:
	/* 0x2aee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2af1:
	/* 0x2af1: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_2af6:
	/* 0x2af6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2af8:
	/* 0x2af8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2afa:
	/* 0x2afa: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_2afd:
	/* 0x2afd: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_2b02:
	/* 0x2b02: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2b05:
	/* 0x2b05: je     2b10 <tail_nodeport_nat_ingress_ipv6+0x2b10> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b10;
	}
x86_l_2b07:
	/* 0x2b07: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_2b0a:
	/* 0x2b0a: jne    2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2947;
	}
x86_l_2b10:
	/* 0x2b10: mov    r15d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2b18:
	/* 0x2b18: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b1d:
	/* 0x2b1d: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_2b24:
	/* 0x2b24: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b29:
	/* 0x2b29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b2e:
	/* 0x2b2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b30:
	/* 0x2b30: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b33:
	/* 0x2b33: je     2b3f <tail_nodeport_nat_ingress_ipv6+0x2b3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b3f;
	}
x86_l_2b35:
	/* 0x2b35: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2b39:
	/* 0x2b39: jne    2c47 <tail_nodeport_nat_ingress_ipv6+0x2c47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c47;
	}
x86_l_2b3f:
	/* 0x2b3f: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_2b42:
	/* 0x2b42: je     2b94 <tail_nodeport_nat_ingress_ipv6+0x2b94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b94;
	}
x86_l_2b44:
	/* 0x2b44: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b49:
	/* 0x2b49: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_2b50:
	/* 0x2b50: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2b55:
	/* 0x2b55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b5a:
	/* 0x2b5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5c:
	/* 0x2b5c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b5f:
	/* 0x2b5f: lea    r13,[rip+0x3bda] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 15322ULL);
x86_l_2b66:
	/* 0x2b66: cmovne r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_2b6a:
	/* 0x2b6a: mov    r14d,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 100ULL);
x86_l_2b70:
	/* 0x2b70: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_2b73:
	/* 0x2b73: je     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2947;
	}
x86_l_2b79:
	/* 0x2b79: cmp    BYTE PTR [rsp+0xa8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505730ULL);
x86_l_2b81:
	/* 0x2b81: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_2b89:
	/* 0x2b89: jne    2beb <tail_nodeport_nat_ingress_ipv6+0x2beb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2beb;
	}
x86_l_2b8b:
	/* 0x2b8b: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_2b92:
	/* 0x2b92: jmp    2bf2 <tail_nodeport_nat_ingress_ipv6+0x2bf2> */
	goto x86_l_2bf2;
x86_l_2b94:
	/* 0x2b94: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b97:
	/* 0x2b97: lea    rcx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2ba0:
	/* 0x2ba0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba3:
	/* 0x2ba3: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2ba7:
	/* 0x2ba7: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2947;
	}
x86_l_2bad:
	/* 0x2bad: movzx  ecx,WORD PTR [rsp+0xe6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 230ULL);
x86_l_2bb5:
	/* 0x2bb5: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2bb9:
	/* 0x2bb9: mov    ecx,DWORD PTR [rsp+0xe2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 226ULL);
x86_l_2bc0:
	/* 0x2bc0: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc2:
	/* 0x2bc2: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc5:
	/* 0x2bc5: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2bc9:
	/* 0x2bc9: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_2bcd:
	/* 0x2bcd: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2947;
	}
x86_l_2bd3:
	/* 0x2bd3: movzx  ecx,WORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 224ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2bdf:
	/* 0x2bdf: mov    ecx,DWORD PTR [rsp+0xdc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_2be6:
	/* 0x2be6: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2be9:
	/* 0x2be9: jmp    2c47 <tail_nodeport_nat_ingress_ipv6+0x2c47> */
	goto x86_l_2c47;
x86_l_2beb:
	/* 0x2beb: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_2bf2:
	/* 0x2bf2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bf7:
	/* 0x2bf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf9:
	/* 0x2bf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bfc:
	/* 0x2bfc: je     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2947;
	}
x86_l_2c02:
	/* 0x2c02: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c05:
	/* 0x2c05: mov    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c09:
	/* 0x2c09: lea    rsi,[rcx+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2c0d:
	/* 0x2c0d: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2c12:
	/* 0x2c12: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c15:
	/* 0x2c15: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2c18:
	/* 0x2c18: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2947;
	}
x86_l_2c1e:
	/* 0x2c1e: movzx  esi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2c22:
	/* 0x2c22: mov    WORD PTR [rcx+0x4],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c26:
	/* 0x2c26: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c28:
	/* 0x2c28: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c2a:
	/* 0x2c2a: lea    rax,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c2e:
	/* 0x2c2e: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_2c31:
	/* 0x2c31: ja     2947 <tail_nodeport_nat_ingress_ipv6+0x2947> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2947;
	}
x86_l_2c37:
	/* 0x2c37: movzx  eax,WORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2c3c:
	/* 0x2c3c: mov    WORD PTR [rcx+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2c40:
	/* 0x2c40: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c44:
	/* 0x2c44: mov    DWORD PTR [rcx+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2c47:
	/* 0x2c47: cmp    DWORD PTR [rbx+0xc],r15d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2c4b:
	/* 0x2c4b: jne    2c57 <tail_nodeport_nat_ingress_ipv6+0x2c57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2c57;
	}
x86_l_2c4d:
	/* 0x2c4d: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_2c52:
	/* 0x2c52: jmp    644 <tail_nodeport_nat_ingress_ipv6+0x644> */
	return 1604ULL;
x86_l_2c57:
	/* 0x2c57: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_2c5c:
	/* 0x2c5c: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_2c5f:
	/* 0x2c5f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c61:
	/* 0x2c61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c63:
	/* 0x2c63: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2c65:
	/* 0x2c65: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c68:
	/* 0x2c68: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2c6a:
	/* 0x2c6a: js     4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1261ULL;
	}
x86_l_2c70:
	/* 0x2c70: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2c73:
	/* 0x2c73: je     4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1261ULL;
	}
x86_l_2c79:
	/* 0x2c79: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_2c7c:
	/* 0x2c7c: jne    644 <tail_nodeport_nat_ingress_ipv6+0x644> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1604ULL;
	}
x86_l_2c82:
	/* 0x2c82: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2c8a:
	/* 0x2c8a: mov    rdi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2c91:
	/* 0x2c91: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c96:
	/* 0x2c96: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c9b:
	/* 0x2c9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c9d:
	/* 0x2c9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ca0:
	/* 0x2ca0: je     2ca9 <tail_nodeport_nat_ingress_ipv6+0x2ca9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ca9;
	}
x86_l_2ca2:
	/* 0x2ca2: mov    DWORD PTR [rax+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    rsi,QWORD PTR [rip+0x3bda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2cb0:
	/* 0x2cb0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2cb5:
	/* 0x2cb5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2cb8:
	/* 0x2cb8: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_2cbd:
	/* 0x2cbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cbf:
	/* 0x2cbf: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_2cc4:
	/* 0x2cc4: mov    r15d,0xa00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2560ULL);
x86_l_2cca:
	/* 0x2cca: jmp    4ed <tail_nodeport_nat_ingress_ipv6+0x4ed> */
	return 1261ULL;
x86_l_2ccf:
	/* 0x2ccf: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cd1:
	/* 0x2cd1: jmp    2341 <tail_nodeport_nat_ingress_ipv6+0x2341> */
	return 9025ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10388U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1776ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1779ULL && __x86_pc <= 3550ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3554ULL && __x86_pc <= 5271ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5275ULL && __x86_pc <= 6934ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6938ULL && __x86_pc <= 8591ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8593ULL && __x86_pc <= 10167ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10170ULL && __x86_pc <= 11473ULL)
			__x86_pc = cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

extern char __aux_snat_v6_args;
extern char __aux_snat_v6_nhm_nat_entry;
extern char __aux_snat_v6_nhm_tuple;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_router_ipv6;
extern char __config_trace_payload_len;
extern char _aux_max_off;
extern char _aux_stride;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_metrics;
extern char cilium_signals;
extern char cilium_snat_v6_alloc_retries;
extern char cilium_snat_v6_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 7ULL: goto x86_l_7;
	case 10ULL: goto x86_l_a;
	case 14ULL: goto x86_l_e;
	case 21ULL: goto x86_l_15;
	case 26ULL: goto x86_l_1a;
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
	case 199ULL: goto x86_l_c7;
	case 202ULL: goto x86_l_ca;
	case 206ULL: goto x86_l_ce;
	case 211ULL: goto x86_l_d3;
	case 214ULL: goto x86_l_d6;
	case 220ULL: goto x86_l_dc;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 230ULL: goto x86_l_e6;
	case 234ULL: goto x86_l_ea;
	case 239ULL: goto x86_l_ef;
	case 243ULL: goto x86_l_f3;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 258ULL: goto x86_l_102;
	case 268ULL: goto x86_l_10c;
	case 272ULL: goto x86_l_110;
	case 278ULL: goto x86_l_116;
	case 283ULL: goto x86_l_11b;
	case 288ULL: goto x86_l_120;
	case 291ULL: goto x86_l_123;
	case 296ULL: goto x86_l_128;
	case 301ULL: goto x86_l_12d;
	case 303ULL: goto x86_l_12f;
	case 305ULL: goto x86_l_131;
	case 311ULL: goto x86_l_137;
	case 316ULL: goto x86_l_13c;
	case 320ULL: goto x86_l_140;
	case 322ULL: goto x86_l_142;
	case 326ULL: goto x86_l_146;
	case 328ULL: goto x86_l_148;
	case 332ULL: goto x86_l_14c;
	case 336ULL: goto x86_l_150;
	case 338ULL: goto x86_l_152;
	case 343ULL: goto x86_l_157;
	case 351ULL: goto x86_l_15f;
	case 353ULL: goto x86_l_161;
	case 358ULL: goto x86_l_166;
	case 366ULL: goto x86_l_16e;
	case 370ULL: goto x86_l_172;
	case 374ULL: goto x86_l_176;
	case 376ULL: goto x86_l_178;
	case 381ULL: goto x86_l_17d;
	case 384ULL: goto x86_l_180;
	case 386ULL: goto x86_l_182;
	case 388ULL: goto x86_l_184;
	case 392ULL: goto x86_l_188;
	case 396ULL: goto x86_l_18c;
	case 400ULL: goto x86_l_190;
	case 406ULL: goto x86_l_196;
	case 411ULL: goto x86_l_19b;
	case 415ULL: goto x86_l_19f;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 439ULL: goto x86_l_1b7;
	case 448ULL: goto x86_l_1c0;
	case 453ULL: goto x86_l_1c5;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 466ULL: goto x86_l_1d2;
	case 471ULL: goto x86_l_1d7;
	case 473ULL: goto x86_l_1d9;
	case 475ULL: goto x86_l_1db;
	case 481ULL: goto x86_l_1e1;
	case 485ULL: goto x86_l_1e5;
	case 490ULL: goto x86_l_1ea;
	case 494ULL: goto x86_l_1ee;
	case 497ULL: goto x86_l_1f1;
	case 502ULL: goto x86_l_1f6;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 520ULL: goto x86_l_208;
	case 524ULL: goto x86_l_20c;
	case 534ULL: goto x86_l_216;
	case 537ULL: goto x86_l_219;
	case 542ULL: goto x86_l_21e;
	case 546ULL: goto x86_l_222;
	case 549ULL: goto x86_l_225;
	case 554ULL: goto x86_l_22a;
	case 558ULL: goto x86_l_22e;
	case 562ULL: goto x86_l_232;
	case 566ULL: goto x86_l_236;
	case 572ULL: goto x86_l_23c;
	case 575ULL: goto x86_l_23f;
	case 585ULL: goto x86_l_249;
	case 589ULL: goto x86_l_24d;
	case 595ULL: goto x86_l_253;
	case 600ULL: goto x86_l_258;
	case 605ULL: goto x86_l_25d;
	case 610ULL: goto x86_l_262;
	case 614ULL: goto x86_l_266;
	case 619ULL: goto x86_l_26b;
	case 624ULL: goto x86_l_270;
	case 627ULL: goto x86_l_273;
	case 632ULL: goto x86_l_278;
	case 635ULL: goto x86_l_27b;
	case 640ULL: goto x86_l_280;
	case 642ULL: goto x86_l_282;
	case 644ULL: goto x86_l_284;
	case 650ULL: goto x86_l_28a;
	case 656ULL: goto x86_l_290;
	case 660ULL: goto x86_l_294;
	case 665ULL: goto x86_l_299;
	case 667ULL: goto x86_l_29b;
	case 671ULL: goto x86_l_29f;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 694ULL: goto x86_l_2b6;
	case 699ULL: goto x86_l_2bb;
	case 707ULL: goto x86_l_2c3;
	case 712ULL: goto x86_l_2c8;
	case 716ULL: goto x86_l_2cc;
	case 721ULL: goto x86_l_2d1;
	case 726ULL: goto x86_l_2d6;
	case 731ULL: goto x86_l_2db;
	case 736ULL: goto x86_l_2e0;
	case 744ULL: goto x86_l_2e8;
	case 747ULL: goto x86_l_2eb;
	case 753ULL: goto x86_l_2f1;
	case 755ULL: goto x86_l_2f3;
	case 761ULL: goto x86_l_2f9;
	case 765ULL: goto x86_l_2fd;
	case 767ULL: goto x86_l_2ff;
	case 771ULL: goto x86_l_303;
	case 776ULL: goto x86_l_308;
	case 784ULL: goto x86_l_310;
	case 787ULL: goto x86_l_313;
	case 789ULL: goto x86_l_315;
	case 794ULL: goto x86_l_31a;
	case 803ULL: goto x86_l_323;
	case 808ULL: goto x86_l_328;
	case 813ULL: goto x86_l_32d;
	case 816ULL: goto x86_l_330;
	case 819ULL: goto x86_l_333;
	case 824ULL: goto x86_l_338;
	case 826ULL: goto x86_l_33a;
	case 828ULL: goto x86_l_33c;
	case 834ULL: goto x86_l_342;
	case 838ULL: goto x86_l_346;
	case 843ULL: goto x86_l_34b;
	case 847ULL: goto x86_l_34f;
	case 850ULL: goto x86_l_352;
	case 855ULL: goto x86_l_357;
	case 865ULL: goto x86_l_361;
	case 868ULL: goto x86_l_364;
	case 873ULL: goto x86_l_369;
	case 877ULL: goto x86_l_36d;
	case 887ULL: goto x86_l_377;
	case 890ULL: goto x86_l_37a;
	case 895ULL: goto x86_l_37f;
	case 899ULL: goto x86_l_383;
	case 904ULL: goto x86_l_388;
	case 909ULL: goto x86_l_38d;
	case 913ULL: goto x86_l_391;
	case 917ULL: goto x86_l_395;
	case 921ULL: goto x86_l_399;
	case 927ULL: goto x86_l_39f;
	case 930ULL: goto x86_l_3a2;
	case 940ULL: goto x86_l_3ac;
	case 944ULL: goto x86_l_3b0;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 956ULL: goto x86_l_3bc;
	case 960ULL: goto x86_l_3c0;
	case 963ULL: goto x86_l_3c3;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 985ULL: goto x86_l_3d9;
	case 987ULL: goto x86_l_3db;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 996ULL: goto x86_l_3e4;
	case 1000ULL: goto x86_l_3e8;
	case 1005ULL: goto x86_l_3ed;
	case 1007ULL: goto x86_l_3ef;
	case 1011ULL: goto x86_l_3f3;
	case 1016ULL: goto x86_l_3f8;
	case 1018ULL: goto x86_l_3fa;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1029ULL: goto x86_l_405;
	case 1037ULL: goto x86_l_40d;
	case 1042ULL: goto x86_l_412;
	case 1047ULL: goto x86_l_417;
	case 1050ULL: goto x86_l_41a;
	case 1054ULL: goto x86_l_41e;
	case 1059ULL: goto x86_l_423;
	case 1061ULL: goto x86_l_425;
	case 1066ULL: goto x86_l_42a;
	case 1070ULL: goto x86_l_42e;
	case 1075ULL: goto x86_l_433;
	case 1077ULL: goto x86_l_435;
	case 1083ULL: goto x86_l_43b;
	case 1087ULL: goto x86_l_43f;
	case 1089ULL: goto x86_l_441;
	case 1093ULL: goto x86_l_445;
	case 1098ULL: goto x86_l_44a;
	case 1106ULL: goto x86_l_452;
	case 1110ULL: goto x86_l_456;
	case 1116ULL: goto x86_l_45c;
	case 1121ULL: goto x86_l_461;
	case 1124ULL: goto x86_l_464;
	case 1133ULL: goto x86_l_46d;
	case 1138ULL: goto x86_l_472;
	case 1143ULL: goto x86_l_477;
	case 1146ULL: goto x86_l_47a;
	case 1150ULL: goto x86_l_47e;
	case 1155ULL: goto x86_l_483;
	case 1157ULL: goto x86_l_485;
	case 1159ULL: goto x86_l_487;
	case 1165ULL: goto x86_l_48d;
	case 1169ULL: goto x86_l_491;
	case 1174ULL: goto x86_l_496;
	case 1178ULL: goto x86_l_49a;
	case 1181ULL: goto x86_l_49d;
	case 1186ULL: goto x86_l_4a2;
	case 1196ULL: goto x86_l_4ac;
	case 1199ULL: goto x86_l_4af;
	case 1204ULL: goto x86_l_4b4;
	case 1208ULL: goto x86_l_4b8;
	case 1218ULL: goto x86_l_4c2;
	case 1221ULL: goto x86_l_4c5;
	case 1226ULL: goto x86_l_4ca;
	case 1230ULL: goto x86_l_4ce;
	case 1233ULL: goto x86_l_4d1;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1247ULL: goto x86_l_4df;
	case 1251ULL: goto x86_l_4e3;
	case 1255ULL: goto x86_l_4e7;
	case 1257ULL: goto x86_l_4e9;
	case 1260ULL: goto x86_l_4ec;
	case 1270ULL: goto x86_l_4f6;
	case 1274ULL: goto x86_l_4fa;
	case 1276ULL: goto x86_l_4fc;
	case 1279ULL: goto x86_l_4ff;
	case 1283ULL: goto x86_l_503;
	case 1287ULL: goto x86_l_507;
	case 1292ULL: goto x86_l_50c;
	case 1297ULL: goto x86_l_511;
	case 1300ULL: goto x86_l_514;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1310ULL: goto x86_l_51e;
	case 1315ULL: goto x86_l_523;
	case 1317ULL: goto x86_l_525;
	case 1319ULL: goto x86_l_527;
	case 1323ULL: goto x86_l_52b;
	case 1325ULL: goto x86_l_52d;
	case 1329ULL: goto x86_l_531;
	case 1335ULL: goto x86_l_537;
	case 1339ULL: goto x86_l_53b;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1349ULL: goto x86_l_545;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1361ULL: goto x86_l_551;
	case 1365ULL: goto x86_l_555;
	case 1367ULL: goto x86_l_557;
	case 1370ULL: goto x86_l_55a;
	case 1374ULL: goto x86_l_55e;
	case 1379ULL: goto x86_l_563;
	case 1382ULL: goto x86_l_566;
	case 1384ULL: goto x86_l_568;
	case 1388ULL: goto x86_l_56c;
	case 1392ULL: goto x86_l_570;
	case 1398ULL: goto x86_l_576;
	case 1403ULL: goto x86_l_57b;
	case 1405ULL: goto x86_l_57d;
	case 1409ULL: goto x86_l_581;
	case 1413ULL: goto x86_l_585;
	case 1417ULL: goto x86_l_589;
	case 1421ULL: goto x86_l_58d;
	case 1425ULL: goto x86_l_591;
	case 1429ULL: goto x86_l_595;
	case 1433ULL: goto x86_l_599;
	case 1437ULL: goto x86_l_59d;
	case 1441ULL: goto x86_l_5a1;
	case 1446ULL: goto x86_l_5a6;
	case 1450ULL: goto x86_l_5aa;
	case 1452ULL: goto x86_l_5ac;
	case 1456ULL: goto x86_l_5b0;
	case 1459ULL: goto x86_l_5b3;
	case 1461ULL: goto x86_l_5b5;
	case 1468ULL: goto x86_l_5bc;
	case 1471ULL: goto x86_l_5bf;
	case 1476ULL: goto x86_l_5c4;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1489ULL: goto x86_l_5d1;
	case 1491ULL: goto x86_l_5d3;
	case 1495ULL: goto x86_l_5d7;
	case 1497ULL: goto x86_l_5d9;
	case 1500ULL: goto x86_l_5dc;
	case 1504ULL: goto x86_l_5e0;
	case 1508ULL: goto x86_l_5e4;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1535ULL: goto x86_l_5ff;
	case 1537ULL: goto x86_l_601;
	case 1543ULL: goto x86_l_607;
	case 1546ULL: goto x86_l_60a;
	case 1552ULL: goto x86_l_610;
	case 1554ULL: goto x86_l_612;
	case 1560ULL: goto x86_l_618;
	case 1567ULL: goto x86_l_61f;
	case 1569ULL: goto x86_l_621;
	case 1571ULL: goto x86_l_623;
	case 1581ULL: goto x86_l_62d;
	case 1587ULL: goto x86_l_633;
	case 1592ULL: goto x86_l_638;
	case 1599ULL: goto x86_l_63f;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1611ULL: goto x86_l_64b;
	case 1614ULL: goto x86_l_64e;
	case 1616ULL: goto x86_l_650;
	case 1619ULL: goto x86_l_653;
	case 1623ULL: goto x86_l_657;
	case 1625ULL: goto x86_l_659;
	case 1634ULL: goto x86_l_662;
	case 1639ULL: goto x86_l_667;
	case 1646ULL: goto x86_l_66e;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1663ULL: goto x86_l_67f;
	case 1665ULL: goto x86_l_681;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1676ULL: goto x86_l_68c;
	case 1685ULL: goto x86_l_695;
	case 1690ULL: goto x86_l_69a;
	case 1695ULL: goto x86_l_69f;
	case 1698ULL: goto x86_l_6a2;
	case 1701ULL: goto x86_l_6a5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r12d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e:
	/* 0xe: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_15:
	/* 0x15: mov    BYTE PTR [rsp+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1a:
	/* 0x1a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
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
	/* 0x26: mov    rcx,QWORD PTR [rip+0xc8a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_2d:
	/* 0x2d: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f:
	/* 0x2f: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_33:
	/* 0x33: mov    rcx,QWORD PTR [rip+0xc8a7] */
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
	/* 0x42: mov    r13,QWORD PTR [rip+0xc8a7] */
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
	/* 0xa9: mov    rcx,QWORD PTR [rip+0xc8a7] */
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
	/* 0xc3: mov    r15d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_c7:
	/* 0xc7: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ca:
	/* 0xca: lea    rdx,[r15+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_ce:
	/* 0xce: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_d3:
	/* 0xd3: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: ja     6bf <tail_handle_snat_fwd_ipv6+0x6bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1727ULL;
	}
x86_l_dc:
	/* 0xdc: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_df:
	/* 0xdf: movzx  r14d,BYTE PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_e4:
	/* 0xe4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e6:
	/* 0xe6: mov    BYTE PTR [r13+0x24],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ea:
	/* 0xea: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_ef:
	/* 0xef: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_f3:
	/* 0xf3: mov    DWORD PTR [rsp],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f7:
	/* 0xf7: ja     57d <tail_handle_snat_fwd_ipv6+0x57d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_57d;
	}
x86_l_fd:
	/* 0xfd: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_102:
	/* 0x102: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_10c:
	/* 0x10c: bt     rax,r14 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_110:
	/* 0x110: jae    19b <tail_handle_snat_fwd_ipv6+0x19b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_19b;
	}
x86_l_116:
	/* 0x116: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11b:
	/* 0x11b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_120:
	/* 0x120: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_123:
	/* 0x123: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_128:
	/* 0x128: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12d:
	/* 0x12d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12f:
	/* 0x12f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_131:
	/* 0x131: js     412 <tail_handle_snat_fwd_ipv6+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_412;
	}
x86_l_137:
	/* 0x137: movzx  edi,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_13c:
	/* 0x13c: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_140:
	/* 0x140: jle    161 <tail_handle_snat_fwd_ipv6+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_161;
	}
x86_l_142:
	/* 0x142: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_146:
	/* 0x146: je     161 <tail_handle_snat_fwd_ipv6+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_161;
	}
x86_l_148:
	/* 0x148: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_14c:
	/* 0x14c: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150:
	/* 0x150: jne    1aa <tail_handle_snat_fwd_ipv6+0x1aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1aa;
	}
x86_l_152:
	/* 0x152: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_157:
	/* 0x157: lea    r8d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_15f:
	/* 0x15f: jmp    182 <tail_handle_snat_fwd_ipv6+0x182> */
	goto x86_l_182;
x86_l_161:
	/* 0x161: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_166:
	/* 0x166: lea    r8d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_16e:
	/* 0x16e: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_172:
	/* 0x172: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176:
	/* 0x176: jne    182 <tail_handle_snat_fwd_ipv6+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_182;
	}
x86_l_178:
	/* 0x178: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17d:
	/* 0x17d: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_180:
	/* 0x180: jmp    1b7 <tail_handle_snat_fwd_ipv6+0x1b7> */
	goto x86_l_1b7;
x86_l_182:
	/* 0x182: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184:
	/* 0x184: movzx  r12d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_188:
	/* 0x188: lea    edx,[r8+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18c:
	/* 0x18c: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_190:
	/* 0x190: jbe    23c <tail_handle_snat_fwd_ipv6+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_23c;
	}
x86_l_196:
	/* 0x196: jmp    563 <tail_handle_snat_fwd_ipv6+0x563> */
	goto x86_l_563;
x86_l_19b:
	/* 0x19b: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_19f:
	/* 0x19f: je     557 <tail_handle_snat_fwd_ipv6+0x557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_557;
	}
x86_l_1a5:
	/* 0x1a5: jmp    57d <tail_handle_snat_fwd_ipv6+0x57d> */
	goto x86_l_57d;
x86_l_1aa:
	/* 0x1aa: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_1ad:
	/* 0x1ad: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1b2:
	/* 0x1b2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1c0:
	/* 0x1c0: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5:
	/* 0x1c5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1ca:
	/* 0x1ca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_1d2:
	/* 0x1d2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d7:
	/* 0x1d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9:
	/* 0x1d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1db:
	/* 0x1db: js     6b7 <tail_handle_snat_fwd_ipv6+0x6b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1719ULL;
	}
x86_l_1e1:
	/* 0x1e1: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e5:
	/* 0x1e5: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1ea:
	/* 0x1ea: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1ee:
	/* 0x1ee: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f1:
	/* 0x1f1: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_1f6:
	/* 0x1f6: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_200:
	/* 0x200: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_203:
	/* 0x203: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_208:
	/* 0x208: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_20c:
	/* 0x20c: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_216:
	/* 0x216: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_219:
	/* 0x219: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_21e:
	/* 0x21e: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_222:
	/* 0x222: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_225:
	/* 0x225: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22a:
	/* 0x22a: movzx  r12d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_22e:
	/* 0x22e: lea    edx,[r8+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_232:
	/* 0x232: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_236:
	/* 0x236: ja     563 <tail_handle_snat_fwd_ipv6+0x563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_563;
	}
x86_l_23c:
	/* 0x23c: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_23f:
	/* 0x23f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_249:
	/* 0x249: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: jae    54e <tail_handle_snat_fwd_ipv6+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_54e;
	}
x86_l_253:
	/* 0x253: mov    BYTE PTR [rsp+0x6],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_258:
	/* 0x258: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25d:
	/* 0x25d: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_262:
	/* 0x262: add    r8d,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_266:
	/* 0x266: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_26b:
	/* 0x26b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_270:
	/* 0x270: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_273:
	/* 0x273: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_278:
	/* 0x278: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
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
	/* 0x284: js     412 <tail_handle_snat_fwd_ipv6+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_412;
	}
x86_l_28a:
	/* 0x28a: movzx  r14d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_290:
	/* 0x290: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_294:
	/* 0x294: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_299:
	/* 0x299: jle    2c8 <tail_handle_snat_fwd_ipv6+0x2c8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2c8;
	}
x86_l_29b:
	/* 0x29b: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_29f:
	/* 0x29f: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2a4:
	/* 0x2a4: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a9:
	/* 0x2a9: je     2f3 <tail_handle_snat_fwd_ipv6+0x2f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f3;
	}
x86_l_2ab:
	/* 0x2ab: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_2af:
	/* 0x2af: movzx  ecx,BYTE PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2b4:
	/* 0x2b4: jne    2ff <tail_handle_snat_fwd_ipv6+0x2ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ff;
	}
x86_l_2b6:
	/* 0x2b6: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_2bb:
	/* 0x2bb: lea    r9d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c3:
	/* 0x2c3: jmp    38d <tail_handle_snat_fwd_ipv6+0x38d> */
	goto x86_l_38d;
x86_l_2c8:
	/* 0x2c8: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cc:
	/* 0x2cc: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d1:
	/* 0x2d1: movzx  ecx,BYTE PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d6:
	/* 0x2d6: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2db:
	/* 0x2db: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_2e0:
	/* 0x2e0: lea    r9d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e8:
	/* 0x2e8: cmp    cl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 44ULL);
x86_l_2eb:
	/* 0x2eb: jne    38d <tail_handle_snat_fwd_ipv6+0x38d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38d;
	}
x86_l_2f1:
	/* 0x2f1: jmp    315 <tail_handle_snat_fwd_ipv6+0x315> */
	goto x86_l_315;
x86_l_2f3:
	/* 0x2f3: mov    r9d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 8ULL);
x86_l_2f9:
	/* 0x2f9: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fd:
	/* 0x2fd: jmp    315 <tail_handle_snat_fwd_ipv6+0x315> */
	goto x86_l_315;
x86_l_2ff:
	/* 0x2ff: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_303:
	/* 0x303: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_308:
	/* 0x308: lea    r9d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_310:
	/* 0x310: cmp    cl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 44ULL);
x86_l_313:
	/* 0x313: jne    38d <tail_handle_snat_fwd_ipv6+0x38d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_38d;
	}
x86_l_315:
	/* 0x315: mov    QWORD PTR [rsp+0x18],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31a:
	/* 0x31a: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_323:
	/* 0x323: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_328:
	/* 0x328: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_32d:
	/* 0x32d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_330:
	/* 0x330: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_333:
	/* 0x333: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_338:
	/* 0x338: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33a:
	/* 0x33a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33c:
	/* 0x33c: js     6b7 <tail_handle_snat_fwd_ipv6+0x6b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1719ULL;
	}
x86_l_342:
	/* 0x342: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_346:
	/* 0x346: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_34b:
	/* 0x34b: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_34f:
	/* 0x34f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_352:
	/* 0x352: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_357:
	/* 0x357: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_361:
	/* 0x361: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_364:
	/* 0x364: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_369:
	/* 0x369: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_36d:
	/* 0x36d: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_377:
	/* 0x377: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_37a:
	/* 0x37a: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_37f:
	/* 0x37f: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_383:
	/* 0x383: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_388:
	/* 0x388: mov    r9,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38d:
	/* 0x38d: movzx  r12d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_391:
	/* 0x391: lea    edi,[r9+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_395:
	/* 0x395: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_399:
	/* 0x399: ja     57b <tail_handle_snat_fwd_ipv6+0x57b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_57b;
	}
x86_l_39f:
	/* 0x39f: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_3a2:
	/* 0x3a2: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3ac:
	/* 0x3ac: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: jae    423 <tail_handle_snat_fwd_ipv6+0x423> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_423;
	}
x86_l_3b2:
	/* 0x3b2: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b7:
	/* 0x3b7: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3bc:
	/* 0x3bc: lea    esi,[r9+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_3c0:
	/* 0x3c0: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_3c3:
	/* 0x3c3: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c8:
	/* 0x3c8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3cd:
	/* 0x3cd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3d0:
	/* 0x3d0: mov    DWORD PTR [rsp+0x28],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d4:
	/* 0x3d4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3d9:
	/* 0x3d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3db:
	/* 0x3db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3dd:
	/* 0x3dd: js     412 <tail_handle_snat_fwd_ipv6+0x412> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_412;
	}
x86_l_3df:
	/* 0x3df: movzx  edi,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_3e4:
	/* 0x3e4: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_3e8:
	/* 0x3e8: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ed:
	/* 0x3ed: jle    42a <tail_handle_snat_fwd_ipv6+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_42a;
	}
x86_l_3ef:
	/* 0x3ef: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_3f3:
	/* 0x3f3: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f8:
	/* 0x3f8: je     435 <tail_handle_snat_fwd_ipv6+0x435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_435;
	}
x86_l_3fa:
	/* 0x3fa: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_3fe:
	/* 0x3fe: jne    441 <tail_handle_snat_fwd_ipv6+0x441> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_441;
	}
x86_l_400:
	/* 0x400: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_405:
	/* 0x405: lea    r9d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_40d:
	/* 0x40d: jmp    4db <tail_handle_snat_fwd_ipv6+0x4db> */
	goto x86_l_4db;
x86_l_412:
	/* 0x412: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_417:
	/* 0x417: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41a:
	/* 0x41a: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e:
	/* 0x41e: jmp    6bf <tail_handle_snat_fwd_ipv6+0x6bf> */
	return 1727ULL;
x86_l_423:
	/* 0x423: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_425:
	/* 0x425: jmp    551 <tail_handle_snat_fwd_ipv6+0x551> */
	goto x86_l_551;
x86_l_42a:
	/* 0x42a: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42e:
	/* 0x42e: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_433:
	/* 0x433: jmp    445 <tail_handle_snat_fwd_ipv6+0x445> */
	goto x86_l_445;
x86_l_435:
	/* 0x435: mov    r9d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 8ULL);
x86_l_43b:
	/* 0x43b: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43f:
	/* 0x43f: jmp    45c <tail_handle_snat_fwd_ipv6+0x45c> */
	goto x86_l_45c;
x86_l_441:
	/* 0x441: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_445:
	/* 0x445: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_44a:
	/* 0x44a: lea    r9d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_452:
	/* 0x452: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_456:
	/* 0x456: jne    4db <tail_handle_snat_fwd_ipv6+0x4db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4db;
	}
x86_l_45c:
	/* 0x45c: mov    QWORD PTR [rsp+0x30],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_461:
	/* 0x461: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_464:
	/* 0x464: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_46d:
	/* 0x46d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_472:
	/* 0x472: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_477:
	/* 0x477: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_47a:
	/* 0x47a: mov    esi,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_47e:
	/* 0x47e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_483:
	/* 0x483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485:
	/* 0x485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_487:
	/* 0x487: js     6b7 <tail_handle_snat_fwd_ipv6+0x6b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1719ULL;
	}
x86_l_48d:
	/* 0x48d: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_491:
	/* 0x491: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_496:
	/* 0x496: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_49a:
	/* 0x49a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_49d:
	/* 0x49d: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_4a2:
	/* 0x4a2: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_4ac:
	/* 0x4ac: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_4af:
	/* 0x4af: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_4b4:
	/* 0x4b4: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_4b8:
	/* 0x4b8: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_4c2:
	/* 0x4c2: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_4c5:
	/* 0x4c5: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_4ca:
	/* 0x4ca: cmove  rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_4ce:
	/* 0x4ce: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_4d1:
	/* 0x4d1: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d6:
	/* 0x4d6: mov    r9,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4db:
	/* 0x4db: movzx  r12d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4df:
	/* 0x4df: lea    edx,[r9+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_4e3:
	/* 0x4e3: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_4e7:
	/* 0x4e7: ja     563 <tail_handle_snat_fwd_ipv6+0x563> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_563;
	}
x86_l_4e9:
	/* 0x4e9: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_4ec:
	/* 0x4ec: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_4f6:
	/* 0x4f6: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4fa:
	/* 0x4fa: jae    54e <tail_handle_snat_fwd_ipv6+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_54e;
	}
x86_l_4fc:
	/* 0x4fc: mov    r15d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_32);
x86_l_4ff:
	/* 0x4ff: lea    r14d,[r9+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_503:
	/* 0x503: add    r14d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_507:
	/* 0x507: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50c:
	/* 0x50c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_511:
	/* 0x511: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_514:
	/* 0x514: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_517:
	/* 0x517: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_51c:
	/* 0x51c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51e:
	/* 0x51e: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_523:
	/* 0x523: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_525:
	/* 0x525: js     557 <tail_handle_snat_fwd_ipv6+0x557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_557;
	}
x86_l_527:
	/* 0x527: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_52b:
	/* 0x52b: jle    568 <tail_handle_snat_fwd_ipv6+0x568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_568;
	}
x86_l_52d:
	/* 0x52d: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_531:
	/* 0x531: je     688 <tail_handle_snat_fwd_ipv6+0x688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_688;
	}
x86_l_537:
	/* 0x537: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_53b:
	/* 0x53b: jne    568 <tail_handle_snat_fwd_ipv6+0x568> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_568;
	}
x86_l_53d:
	/* 0x53d: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_542:
	/* 0x542: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_545:
	/* 0x545: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_549:
	/* 0x549: jmp    6bf <tail_handle_snat_fwd_ipv6+0x6bf> */
	return 1727ULL;
x86_l_54e:
	/* 0x54e: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_551:
	/* 0x551: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_555:
	/* 0x555: jne    57d <tail_handle_snat_fwd_ipv6+0x57d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_57d;
	}
x86_l_557:
	/* 0x557: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55a:
	/* 0x55a: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55e:
	/* 0x55e: jmp    6bf <tail_handle_snat_fwd_ipv6+0x6bf> */
	return 1727ULL;
x86_l_563:
	/* 0x563: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_566:
	/* 0x566: jmp    57d <tail_handle_snat_fwd_ipv6+0x57d> */
	goto x86_l_57d;
x86_l_568:
	/* 0x568: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56c:
	/* 0x56c: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_570:
	/* 0x570: je     68c <tail_handle_snat_fwd_ipv6+0x68c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68c;
	}
x86_l_576:
	/* 0x576: jmp    6b0 <tail_handle_snat_fwd_ipv6+0x6b0> */
	return 1712ULL;
x86_l_57b:
	/* 0x57b: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_57d:
	/* 0x57d: mov    BYTE PTR [r13+0x24],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_581:
	/* 0x581: mov    rax,QWORD PTR [r15+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_585:
	/* 0x585: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_589:
	/* 0x589: mov    rax,QWORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_58d:
	/* 0x58d: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_591:
	/* 0x591: mov    rax,QWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_595:
	/* 0x595: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_599:
	/* 0x599: mov    rax,QWORD PTR [r15+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_59d:
	/* 0x59d: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a1:
	/* 0x5a1: mov    BYTE PTR [r13+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_5a6:
	/* 0x5a6: cmp    r14b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 17ULL);
x86_l_5aa:
	/* 0x5aa: je     5b5 <tail_handle_snat_fwd_ipv6+0x5b5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5b5;
	}
x86_l_5ac:
	/* 0x5ac: movzx  eax,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b0:
	/* 0x5b0: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_5b3:
	/* 0x5b3: jne    618 <tail_handle_snat_fwd_ipv6+0x618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_618;
	}
x86_l_5b5:
	/* 0x5b5: mov    rcx,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_router_ipv6)));
x86_l_5bc:
	/* 0x5bc: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bf:
	/* 0x5bf: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c4:
	/* 0x5c4: mov    rcx,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c8:
	/* 0x5c8: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cd:
	/* 0x5cd: cmp    QWORD PTR [r15+0x16],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_5d1:
	/* 0x5d1: jne    618 <tail_handle_snat_fwd_ipv6+0x618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_618;
	}
x86_l_5d3:
	/* 0x5d3: cmp    QWORD PTR [r15+0x1e],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_5d7:
	/* 0x5d7: jne    618 <tail_handle_snat_fwd_ipv6+0x618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_618;
	}
x86_l_5d9:
	/* 0x5d9: add    edx,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_5dc:
	/* 0x5dc: mov    QWORD PTR [r13+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5e0:
	/* 0x5e0: mov    QWORD PTR [r13+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e4:
	/* 0x5e4: mov    BYTE PTR [r13+0x3d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005057ULL);
x86_l_5e9:
	/* 0x5e9: lea    rcx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_5ee:
	/* 0x5ee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f1:
	/* 0x5f1: call   0 <tail_handle_snat_fwd_ipv6> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1526ULL);
	__x86_sim_call_depth++;
	return 1924ULL;
x86_l_5f6:
	/* 0x5f6: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_5fb:
	/* 0x5fb: je     618 <tail_handle_snat_fwd_ipv6+0x618> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_618;
	}
x86_l_5fd:
	/* 0x5fd: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5ff:
	/* 0x5ff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_601:
	/* 0x601: js     771 <tail_handle_snat_fwd_ipv6+0x771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 1905ULL;
	}
x86_l_607:
	/* 0x607: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_60a:
	/* 0x60a: je     771 <tail_handle_snat_fwd_ipv6+0x771> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1905ULL;
	}
x86_l_610:
	/* 0x610: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_612:
	/* 0x612: jne    763 <tail_handle_snat_fwd_ipv6+0x763> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1891ULL;
	}
x86_l_618:
	/* 0x618: mov    rax,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_61f:
	/* 0x61f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_621:
	/* 0x621: mov    ebx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_623:
	/* 0x623: movabs rax,0x71008f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485340676608ULL);
x86_l_62d:
	/* 0x62d: add    rax,0xa0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 655360ULL);
x86_l_633:
	/* 0x633: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_638:
	/* 0x638: mov    rdi,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_63f:
	/* 0x63f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_644:
	/* 0x644: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_649:
	/* 0x649: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64b:
	/* 0x64b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: je     659 <tail_handle_snat_fwd_ipv6+0x659> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_659;
	}
x86_l_650:
	/* 0x650: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_653:
	/* 0x653: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_657:
	/* 0x657: jmp    681 <tail_handle_snat_fwd_ipv6+0x681> */
	goto x86_l_681;
x86_l_659:
	/* 0x659: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_662:
	/* 0x662: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_667:
	/* 0x667: mov    rdi,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_66e:
	/* 0x66e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_673:
	/* 0x673: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_678:
	/* 0x678: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_67d:
	/* 0x67d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67f:
	/* 0x67f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_681:
	/* 0x681: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_683:
	/* 0x683: jmp    763 <tail_handle_snat_fwd_ipv6+0x763> */
	return 1891ULL;
x86_l_688:
	/* 0x688: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68c:
	/* 0x68c: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_695:
	/* 0x695: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69a:
	/* 0x69a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_69f:
	/* 0x69f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6a2:
	/* 0x6a2: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_6a5:
	/* 0x6a5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 1706ULL;
}

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1706ULL: goto x86_l_6aa;
	case 1708ULL: goto x86_l_6ac;
	case 1710ULL: goto x86_l_6ae;
	case 1712ULL: goto x86_l_6b0;
	case 1717ULL: goto x86_l_6b5;
	case 1719ULL: goto x86_l_6b7;
	case 1724ULL: goto x86_l_6bc;
	case 1727ULL: goto x86_l_6bf;
	case 1729ULL: goto x86_l_6c1;
	case 1731ULL: goto x86_l_6c3;
	case 1734ULL: goto x86_l_6c6;
	case 1737ULL: goto x86_l_6c9;
	case 1741ULL: goto x86_l_6cd;
	case 1748ULL: goto x86_l_6d4;
	case 1751ULL: goto x86_l_6d7;
	case 1755ULL: goto x86_l_6db;
	case 1765ULL: goto x86_l_6e5;
	case 1769ULL: goto x86_l_6e9;
	case 1772ULL: goto x86_l_6ec;
	case 1782ULL: goto x86_l_6f6;
	case 1787ULL: goto x86_l_6fb;
	case 1791ULL: goto x86_l_6ff;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1813ULL: goto x86_l_715;
	case 1815ULL: goto x86_l_717;
	case 1818ULL: goto x86_l_71a;
	case 1822ULL: goto x86_l_71e;
	case 1824ULL: goto x86_l_720;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1855ULL: goto x86_l_73f;
	case 1860ULL: goto x86_l_744;
	case 1862ULL: goto x86_l_746;
	case 1864ULL: goto x86_l_748;
	case 1871ULL: goto x86_l_74f;
	case 1876ULL: goto x86_l_754;
	case 1879ULL: goto x86_l_757;
	case 1884ULL: goto x86_l_75c;
	case 1886ULL: goto x86_l_75e;
	case 1891ULL: goto x86_l_763;
	case 1893ULL: goto x86_l_765;
	case 1897ULL: goto x86_l_769;
	case 1899ULL: goto x86_l_76b;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1911ULL: goto x86_l_777;
	case 1915ULL: goto x86_l_77b;
	case 1919ULL: goto x86_l_77f;
	case 1924ULL: goto x86_l_784;
	case 1925ULL: goto x86_l_785;
	case 1927ULL: goto x86_l_787;
	case 1929ULL: goto x86_l_789;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1934ULL: goto x86_l_78e;
	case 1941ULL: goto x86_l_795;
	case 1944ULL: goto x86_l_798;
	case 1947ULL: goto x86_l_79b;
	case 1955ULL: goto x86_l_7a3;
	case 1958ULL: goto x86_l_7a6;
	case 1963ULL: goto x86_l_7ab;
	case 1965ULL: goto x86_l_7ad;
	case 1967ULL: goto x86_l_7af;
	case 1974ULL: goto x86_l_7b6;
	case 1977ULL: goto x86_l_7b9;
	case 1981ULL: goto x86_l_7bd;
	case 1988ULL: goto x86_l_7c4;
	case 1992ULL: goto x86_l_7c8;
	case 1994ULL: goto x86_l_7ca;
	case 1998ULL: goto x86_l_7ce;
	case 2001ULL: goto x86_l_7d1;
	case 2006ULL: goto x86_l_7d6;
	case 2009ULL: goto x86_l_7d9;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2021ULL: goto x86_l_7e5;
	case 2023ULL: goto x86_l_7e7;
	case 2030ULL: goto x86_l_7ee;
	case 2031ULL: goto x86_l_7ef;
	case 2033ULL: goto x86_l_7f1;
	case 2035ULL: goto x86_l_7f3;
	case 2037ULL: goto x86_l_7f5;
	case 2039ULL: goto x86_l_7f7;
	case 2040ULL: goto x86_l_7f8;
	case 2041ULL: goto x86_l_7f9;
	case 2048ULL: goto x86_l_800;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2069ULL: goto x86_l_815;
	case 2072ULL: goto x86_l_818;
	case 2078ULL: goto x86_l_81e;
	case 2081ULL: goto x86_l_821;
	case 2083ULL: goto x86_l_823;
	case 2090ULL: goto x86_l_82a;
	case 2093ULL: goto x86_l_82d;
	case 2103ULL: goto x86_l_837;
	case 2108ULL: goto x86_l_83c;
	case 2110ULL: goto x86_l_83e;
	case 2112ULL: goto x86_l_840;
	case 2114ULL: goto x86_l_842;
	case 2124ULL: goto x86_l_84c;
	case 2129ULL: goto x86_l_851;
	case 2132ULL: goto x86_l_854;
	case 2138ULL: goto x86_l_85a;
	case 2143ULL: goto x86_l_85f;
	case 2147ULL: goto x86_l_863;
	case 2151ULL: goto x86_l_867;
	case 2159ULL: goto x86_l_86f;
	case 2167ULL: goto x86_l_877;
	case 2170ULL: goto x86_l_87a;
	case 2173ULL: goto x86_l_87d;
	case 2177ULL: goto x86_l_881;
	case 2180ULL: goto x86_l_884;
	case 2183ULL: goto x86_l_887;
	case 2189ULL: goto x86_l_88d;
	case 2194ULL: goto x86_l_892;
	case 2199ULL: goto x86_l_897;
	case 2202ULL: goto x86_l_89a;
	case 2205ULL: goto x86_l_89d;
	case 2210ULL: goto x86_l_8a2;
	case 2212ULL: goto x86_l_8a4;
	case 2214ULL: goto x86_l_8a6;
	case 2220ULL: goto x86_l_8ac;
	case 2230ULL: goto x86_l_8b6;
	case 2238ULL: goto x86_l_8be;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2252ULL: goto x86_l_8cc;
	case 2257ULL: goto x86_l_8d1;
	case 2262ULL: goto x86_l_8d6;
	case 2272ULL: goto x86_l_8e0;
	case 2278ULL: goto x86_l_8e6;
	case 2286ULL: goto x86_l_8ee;
	case 2291ULL: goto x86_l_8f3;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2302ULL: goto x86_l_8fe;
	case 2304ULL: goto x86_l_900;
	case 2306ULL: goto x86_l_902;
	case 2311ULL: goto x86_l_907;
	case 2313ULL: goto x86_l_909;
	case 2319ULL: goto x86_l_90f;
	case 2327ULL: goto x86_l_917;
	case 2330ULL: goto x86_l_91a;
	case 2336ULL: goto x86_l_920;
	case 2339ULL: goto x86_l_923;
	case 2345ULL: goto x86_l_929;
	case 2348ULL: goto x86_l_92c;
	case 2354ULL: goto x86_l_932;
	case 2357ULL: goto x86_l_935;
	case 2363ULL: goto x86_l_93b;
	case 2368ULL: goto x86_l_940;
	case 2376ULL: goto x86_l_948;
	case 2382ULL: goto x86_l_94e;
	case 2387ULL: goto x86_l_953;
	case 2395ULL: goto x86_l_95b;
	case 2401ULL: goto x86_l_961;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2414ULL: goto x86_l_96e;
	case 2417ULL: goto x86_l_971;
	case 2422ULL: goto x86_l_976;
	case 2424ULL: goto x86_l_978;
	case 2426ULL: goto x86_l_97a;
	case 2432ULL: goto x86_l_980;
	case 2438ULL: goto x86_l_986;
	case 2444ULL: goto x86_l_98c;
	case 2450ULL: goto x86_l_992;
	case 2456ULL: goto x86_l_998;
	case 2464ULL: goto x86_l_9a0;
	case 2470ULL: goto x86_l_9a6;
	case 2472ULL: goto x86_l_9a8;
	case 2476ULL: goto x86_l_9ac;
	case 2483ULL: goto x86_l_9b3;
	case 2486ULL: goto x86_l_9b6;
	case 2488ULL: goto x86_l_9b8;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2513ULL: goto x86_l_9d1;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2528ULL: goto x86_l_9e0;
	case 2530ULL: goto x86_l_9e2;
	case 2533ULL: goto x86_l_9e5;
	case 2538ULL: goto x86_l_9ea;
	case 2541ULL: goto x86_l_9ed;
	case 2549ULL: goto x86_l_9f5;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2562ULL: goto x86_l_a02;
	case 2564ULL: goto x86_l_a04;
	case 2567ULL: goto x86_l_a07;
	case 2574ULL: goto x86_l_a0e;
	case 2578ULL: goto x86_l_a12;
	case 2582ULL: goto x86_l_a16;
	case 2584ULL: goto x86_l_a18;
	case 2588ULL: goto x86_l_a1c;
	case 2595ULL: goto x86_l_a23;
	case 2601ULL: goto x86_l_a29;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2631ULL: goto x86_l_a47;
	case 2636ULL: goto x86_l_a4c;
	case 2641ULL: goto x86_l_a51;
	case 2646ULL: goto x86_l_a56;
	case 2651ULL: goto x86_l_a5b;
	case 2656ULL: goto x86_l_a60;
	case 2659ULL: goto x86_l_a63;
	case 2666ULL: goto x86_l_a6a;
	case 2670ULL: goto x86_l_a6e;
	case 2672ULL: goto x86_l_a70;
	case 2679ULL: goto x86_l_a77;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2689ULL: goto x86_l_a81;
	case 2694ULL: goto x86_l_a86;
	case 2701ULL: goto x86_l_a8d;
	case 2707ULL: goto x86_l_a93;
	case 2718ULL: goto x86_l_a9e;
	case 2725ULL: goto x86_l_aa5;
	case 2728ULL: goto x86_l_aa8;
	case 2738ULL: goto x86_l_ab2;
	case 2746ULL: goto x86_l_aba;
	case 2752ULL: goto x86_l_ac0;
	case 2754ULL: goto x86_l_ac2;
	case 2760ULL: goto x86_l_ac8;
	case 2765ULL: goto x86_l_acd;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2785ULL: goto x86_l_ae1;
	case 2794ULL: goto x86_l_aea;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2816ULL: goto x86_l_b00;
	case 2821ULL: goto x86_l_b05;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2831ULL: goto x86_l_b0f;
	case 2833ULL: goto x86_l_b11;
	case 2836ULL: goto x86_l_b14;
	case 2840ULL: goto x86_l_b18;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2853ULL: goto x86_l_b25;
	case 2856ULL: goto x86_l_b28;
	case 2862ULL: goto x86_l_b2e;
	case 2868ULL: goto x86_l_b34;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2917ULL: goto x86_l_b65;
	case 2922ULL: goto x86_l_b6a;
	case 2927ULL: goto x86_l_b6f;
	case 2932ULL: goto x86_l_b74;
	case 2934ULL: goto x86_l_b76;
	case 2936ULL: goto x86_l_b78;
	case 2939ULL: goto x86_l_b7b;
	case 2947ULL: goto x86_l_b83;
	case 2952ULL: goto x86_l_b88;
	case 2962ULL: goto x86_l_b92;
	case 2964ULL: goto x86_l_b94;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2978ULL: goto x86_l_ba2;
	case 2982ULL: goto x86_l_ba6;
	case 2990ULL: goto x86_l_bae;
	case 2995ULL: goto x86_l_bb3;
	case 3000ULL: goto x86_l_bb8;
	case 3005ULL: goto x86_l_bbd;
	case 3007ULL: goto x86_l_bbf;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3018ULL: goto x86_l_bca;
	case 3020ULL: goto x86_l_bcc;
	case 3025ULL: goto x86_l_bd1;
	case 3027ULL: goto x86_l_bd3;
	case 3032ULL: goto x86_l_bd8;
	case 3035ULL: goto x86_l_bdb;
	case 3039ULL: goto x86_l_bdf;
	case 3045ULL: goto x86_l_be5;
	case 3051ULL: goto x86_l_beb;
	case 3053ULL: goto x86_l_bed;
	case 3056ULL: goto x86_l_bf0;
	case 3063ULL: goto x86_l_bf7;
	case 3071ULL: goto x86_l_bff;
	case 3073ULL: goto x86_l_c01;
	case 3078ULL: goto x86_l_c06;
	case 3083ULL: goto x86_l_c0b;
	case 3094ULL: goto x86_l_c16;
	case 3101ULL: goto x86_l_c1d;
	case 3105ULL: goto x86_l_c21;
	case 3108ULL: goto x86_l_c24;
	case 3113ULL: goto x86_l_c29;
	case 3116ULL: goto x86_l_c2c;
	case 3118ULL: goto x86_l_c2e;
	case 3121ULL: goto x86_l_c31;
	case 3127ULL: goto x86_l_c37;
	case 3130ULL: goto x86_l_c3a;
	case 3133ULL: goto x86_l_c3d;
	case 3135ULL: goto x86_l_c3f;
	case 3137ULL: goto x86_l_c41;
	case 3140ULL: goto x86_l_c44;
	case 3145ULL: goto x86_l_c49;
	case 3151ULL: goto x86_l_c4f;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3167ULL: goto x86_l_c5f;
	case 3174ULL: goto x86_l_c66;
	case 3178ULL: goto x86_l_c6a;
	case 3182ULL: goto x86_l_c6e;
	case 3187ULL: goto x86_l_c73;
	case 3192ULL: goto x86_l_c78;
	case 3200ULL: goto x86_l_c80;
	case 3206ULL: goto x86_l_c86;
	case 3210ULL: goto x86_l_c8a;
	case 3219ULL: goto x86_l_c93;
	case 3228ULL: goto x86_l_c9c;
	case 3237ULL: goto x86_l_ca5;
	case 3246ULL: goto x86_l_cae;
	case 3255ULL: goto x86_l_cb7;
	case 3260ULL: goto x86_l_cbc;
	case 3266ULL: goto x86_l_cc2;
	case 3271ULL: goto x86_l_cc7;
	case 3274ULL: goto x86_l_cca;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3284ULL: goto x86_l_cd4;
	case 3286ULL: goto x86_l_cd6;
	case 3291ULL: goto x86_l_cdb;
	case 3293ULL: goto x86_l_cdd;
	case 3299ULL: goto x86_l_ce3;
	case 3307ULL: goto x86_l_ceb;
	case 3313ULL: goto x86_l_cf1;
	case 3318ULL: goto x86_l_cf6;
	case 3326ULL: goto x86_l_cfe;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3341ULL: goto x86_l_d0d;
	case 3346ULL: goto x86_l_d12;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3361ULL: goto x86_l_d21;
	case 3366ULL: goto x86_l_d26;
	case 3370ULL: goto x86_l_d2a;
	case 3376ULL: goto x86_l_d30;
	case 3381ULL: goto x86_l_d35;
	case 3391ULL: goto x86_l_d3f;
	case 3395ULL: goto x86_l_d43;
	case 3401ULL: goto x86_l_d49;
	case 3409ULL: goto x86_l_d51;
	case 3412ULL: goto x86_l_d54;
	case 3415ULL: goto x86_l_d57;
	case 3420ULL: goto x86_l_d5c;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3432ULL: goto x86_l_d68;
	case 3434ULL: goto x86_l_d6a;
	case 3440ULL: goto x86_l_d70;
	case 3444ULL: goto x86_l_d74;
	case 3447ULL: goto x86_l_d77;
	case 3451ULL: goto x86_l_d7b;
	case 3453ULL: goto x86_l_d7d;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3467ULL: goto x86_l_d8b;
	case 3473ULL: goto x86_l_d91;
	case 3478ULL: goto x86_l_d96;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6aa:
	/* 0x6aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ac:
	/* 0x6ac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ae:
	/* 0x6ae: js     6b7 <tail_handle_snat_fwd_ipv6+0x6b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_6b7;
	}
x86_l_6b0:
	/* 0x6b0: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_6b5:
	/* 0x6b5: jmp    6bc <tail_handle_snat_fwd_ipv6+0x6bc> */
	goto x86_l_6bc;
x86_l_6b7:
	/* 0x6b7: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_6bc:
	/* 0x6bc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6bf:
	/* 0x6bf: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_6c1:
	/* 0x6c1: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_6c3:
	/* 0x6c3: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_6c6:
	/* 0x6c6: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6c9:
	/* 0x6c9: mov    DWORD PTR [rbx+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6cd:
	/* 0x6cd: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_6d4:
	/* 0x6d4: or     r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_6d7:
	/* 0x6d7: mov    DWORD PTR [rbx+0x38],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6db:
	/* 0x6db: movabs rcx,0x8f710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 40375175073497088ULL);
x86_l_6e5:
	/* 0x6e5: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6e9:
	/* 0x6e9: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ec:
	/* 0x6ec: movabs rcx,0x71008f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 485340676608ULL);
x86_l_6f6:
	/* 0x6f6: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6fb:
	/* 0x6fb: mov    BYTE PTR [rsp+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ff:
	/* 0x6ff: mov    rdi,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_706:
	/* 0x706: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_70b:
	/* 0x70b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_710:
	/* 0x710: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_712:
	/* 0x712: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_715:
	/* 0x715: je     720 <tail_handle_snat_fwd_ipv6+0x720> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_720;
	}
x86_l_717:
	/* 0x717: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_71a:
	/* 0x71a: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_71e:
	/* 0x71e: jmp    748 <tail_handle_snat_fwd_ipv6+0x748> */
	goto x86_l_748;
x86_l_720:
	/* 0x720: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_729:
	/* 0x729: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72e:
	/* 0x72e: mov    rdi,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_735:
	/* 0x735: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_73a:
	/* 0x73a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_73f:
	/* 0x73f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_744:
	/* 0x744: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_746:
	/* 0x746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_748:
	/* 0x748: mov    rsi,QWORD PTR [rip+0xc8a3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_74f:
	/* 0x74f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_754:
	/* 0x754: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_757:
	/* 0x757: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_75c:
	/* 0x75c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75e:
	/* 0x75e: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_763:
	/* 0x763: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_765:
	/* 0x765: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_769:
	/* 0x769: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_76b:
	/* 0x76b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_76c:
	/* 0x76c: jmp    2972 <snat_v6_nat+0x21ee> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_771:
	/* 0x771: movzx  r14d,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_777:
	/* 0x777: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_77b:
	/* 0x77b: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77f:
	/* 0x77f: jmp    6bf <tail_handle_snat_fwd_ipv6+0x6bf> */
	goto x86_l_6bf;
x86_l_784:
	/* 0x784: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_785:
	/* 0x785: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_787:
	/* 0x787: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_789:
	/* 0x789: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_78b:
	/* 0x78b: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_78d:
	/* 0x78d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_78e:
	/* 0x78e: sub    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 216ULL);
x86_l_795:
	/* 0x795: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_798:
	/* 0x798: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_79b:
	/* 0x79b: mov    QWORD PTR [rsp+0xa8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7a3:
	/* 0x7a3: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7a6:
	/* 0x7a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7ab:
	/* 0x7ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ad:
	/* 0x7ad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7af:
	/* 0x7af: mov    rcx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_7b6:
	/* 0x7b6: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_7b9:
	/* 0x7b9: imul   r12,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_7bd:
	/* 0x7bd: mov    rbp,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_7c4:
	/* 0x7c4: cmp    r12,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_7c8:
	/* 0x7c8: jbe    7ce <snat_v6_nat+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_7ce;
	}
x86_l_7ca:
	/* 0x7ca: mov    r12,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ce:
	/* 0x7ce: mov    ecx,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_7d1:
	/* 0x7d1: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d6:
	/* 0x7d6: mov    edx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7d9:
	/* 0x7d9: lea    rsi,[rcx+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_7dd:
	/* 0x7dd: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_7e2:
	/* 0x7e2: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_7e5:
	/* 0x7e5: jbe    7f9 <snat_v6_nat+0x75> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_7f9;
	}
x86_l_7e7:
	/* 0x7e7: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_7ee:
	/* 0x7ee: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_7ef:
	/* 0x7ef: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_7f1:
	/* 0x7f1: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_7f3:
	/* 0x7f3: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_7f5:
	/* 0x7f5: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_7f7:
	/* 0x7f7: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_7f8:
	/* 0x7f8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_7f9:
	/* 0x7f9: add    r12,QWORD PTR [rip+0x690] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_REG_NONE, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 1680ULL);
x86_l_800:
	/* 0x800: movzx  edx,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_806:
	/* 0x806: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_80b:
	/* 0x80b: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_80e:
	/* 0x80e: mov    rbx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_813:
	/* 0x813: je     823 <snat_v6_nat+0x9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_823;
	}
x86_l_815:
	/* 0x815: cmp    edx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 58ULL);
x86_l_818:
	/* 0x818: je     8d1 <snat_v6_nat+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8d1;
	}
x86_l_81e:
	/* 0x81e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_821:
	/* 0x821: jne    7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7e7;
	}
x86_l_823:
	/* 0x823: mov    rsi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_82a:
	/* 0x82a: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_82d:
	/* 0x82d: bt     QWORD PTR [rsp+0xa8],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 721554505768ULL);
x86_l_837:
	/* 0x837: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_83c:
	/* 0x83c: jae    842 <snat_v6_nat+0xbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_842;
	}
x86_l_83e:
	/* 0x83e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_840:
	/* 0x840: je     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e7;
	}
x86_l_842:
	/* 0x842: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_84c:
	/* 0x84c: lea    r13,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_851:
	/* 0x851: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_854:
	/* 0x854: je     953 <snat_v6_nat+0x1cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_953;
	}
x86_l_85a:
	/* 0x85a: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_85f:
	/* 0x85f: lea    r14,[rcx+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_863:
	/* 0x863: mov    rbx,QWORD PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_867:
	/* 0x867: mov    QWORD PTR [rcx+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_86f:
	/* 0x86f: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_877:
	/* 0x877: mov    DWORD PTR [rcx+0xe],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_87a:
	/* 0x87a: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_87d:
	/* 0x87d: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_881:
	/* 0x881: mov    BYTE PTR [rcx+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_884:
	/* 0x884: test   rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_887:
	/* 0x887: jne    14c3 <snat_v6_nat+0xd3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5315ULL;
	}
x86_l_88d:
	/* 0x88d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_892:
	/* 0x892: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_897:
	/* 0x897: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_89a:
	/* 0x89a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_89d:
	/* 0x89d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8a2:
	/* 0x8a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a4:
	/* 0x8a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a6:
	/* 0x8a6: js     a79 <snat_v6_nat+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_a79;
	}
x86_l_8ac:
	/* 0x8ac: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_8b6:
	/* 0x8b6: test   QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8be:
	/* 0x8be: jne    14e4 <snat_v6_nat+0xd60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5348ULL;
	}
x86_l_8c4:
	/* 0x8c4: mov    QWORD PTR [r14],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c7:
	/* 0x8c7: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8cc:
	/* 0x8cc: jmp    980 <snat_v6_nat+0x1fc> */
	goto x86_l_980;
x86_l_8d1:
	/* 0x8d1: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_8d6:
	/* 0x8d6: bt     QWORD PTR [rsp+0xa8],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 721554505768ULL);
x86_l_8e0:
	/* 0x8e0: jb     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7e7;
	}
x86_l_8e6:
	/* 0x8e6: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_8ee:
	/* 0x8ee: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8f3:
	/* 0x8f3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8f6:
	/* 0x8f6: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_8f9:
	/* 0x8f9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8fe:
	/* 0x8fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_900:
	/* 0x900: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_902:
	/* 0x902: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_907:
	/* 0x907: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_909:
	/* 0x909: js     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_7e7;
	}
x86_l_90f:
	/* 0x90f: movzx  ecx,BYTE PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 192ULL);
x86_l_917:
	/* 0x917: cmp    ecx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 127ULL);
x86_l_91a:
	/* 0x91a: jg     b1a <snat_v6_nat+0x396> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b1a;
	}
x86_l_920:
	/* 0x920: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_923:
	/* 0x923: je     c73 <snat_v6_nat+0x4ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c73;
	}
x86_l_929:
	/* 0x929: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_92c:
	/* 0x92c: je     c86 <snat_v6_nat+0x502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c86;
	}
x86_l_932:
	/* 0x932: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_935:
	/* 0x935: jne    b46 <snat_v6_nat+0x3c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b46;
	}
x86_l_93b:
	/* 0x93b: mov    eax,0xffffff6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967151ULL);
x86_l_940:
	/* 0x940: cmp    BYTE PTR [rsp+0xc1],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 828928688129ULL);
x86_l_948:
	/* 0x948: jbe    c86 <snat_v6_nat+0x502> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c86;
	}
x86_l_94e:
	/* 0x94e: jmp    7e7 <snat_v6_nat+0x63> */
	goto x86_l_7e7;
x86_l_953:
	/* 0x953: test   QWORD PTR [rsp+0xa8],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_95b:
	/* 0x95b: jne    7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_7e7;
	}
x86_l_961:
	/* 0x961: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_966:
	/* 0x966: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_96b:
	/* 0x96b: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_96e:
	/* 0x96e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_971:
	/* 0x971: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_976:
	/* 0x976: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_978:
	/* 0x978: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_97a:
	/* 0x97a: js     c01 <snat_v6_nat+0x47d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_c01;
	}
x86_l_980:
	/* 0x980: movzx  ecx,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_986:
	/* 0x986: movzx  eax,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_98c:
	/* 0x98c: mov    WORD PTR [r12+0x22],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_992:
	/* 0x992: mov    WORD PTR [r12+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_998:
	/* 0x998: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_9a0:
	/* 0x9a0: cmp    BYTE PTR [r12+0x3c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_9a6:
	/* 0x9a6: jne    9c6 <snat_v6_nat+0x242> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9c6;
	}
x86_l_9a8:
	/* 0x9a8: rol    cx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_9ac:
	/* 0x9ac: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_9b3:
	/* 0x9b3: movzx  edx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_9b6:
	/* 0x9b6: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_9b8:
	/* 0x9b8: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_9bd:
	/* 0x9bd: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_9c0:
	/* 0x9c0: jb     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7e7;
	}
x86_l_9c6:
	/* 0x9c6: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9cb:
	/* 0x9cb: movzx  r14d,BYTE PTR [r12+0x3d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 61ULL);
x86_l_9d1:
	/* 0x9d1: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_9d8:
	/* 0x9d8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9dd:
	/* 0x9dd: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_9e0:
	/* 0x9e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e2:
	/* 0x9e2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_9e5:
	/* 0x9e5: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9ea:
	/* 0x9ea: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_9ed:
	/* 0x9ed: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9f5:
	/* 0x9f5: je     182e <snat_v6_nat+0x10aa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6190ULL;
	}
x86_l_9fb:
	/* 0x9fb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a00:
	/* 0xa00: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a02:
	/* 0xa02: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a04:
	/* 0xa04: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_a07:
	/* 0xa07: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_a0e:
	/* 0xa0e: imul   r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_a12:
	/* 0xa12: cmp    r14,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_a16:
	/* 0xa16: jbe    a1c <snat_v6_nat+0x298> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_a1c;
	}
x86_l_a18:
	/* 0xa18: mov    r14,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1c:
	/* 0xa1c: mov    r13,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_a23:
	/* 0xa23: movzx  eax,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a29:
	/* 0xa29: mov    WORD PTR [r13+r14*1+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R14, 0), 36ULL);
x86_l_a2f:
	/* 0xa2f: mov    ecx,DWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a34:
	/* 0xa34: mov    DWORD PTR [r13+r14*1+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 32ULL);
x86_l_a39:
	/* 0xa39: mov    rcx,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a3e:
	/* 0xa3e: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a43:
	/* 0xa43: mov    rsi,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a47:
	/* 0xa47: mov    rdi,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4c:
	/* 0xa4c: mov    QWORD PTR [r13+r14*1+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 24ULL);
x86_l_a51:
	/* 0xa51: mov    QWORD PTR [r13+r14*1+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 16ULL);
x86_l_a56:
	/* 0xa56: mov    QWORD PTR [r13+r14*1+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 8ULL);
x86_l_a5b:
	/* 0xa5b: mov    QWORD PTR [r13+r14*1+0x0],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_a60:
	/* 0xa60: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a63:
	/* 0xa63: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a6a:
	/* 0xa6a: cmp    ax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 6ULL);
x86_l_a6e:
	/* 0xa6e: jne    a86 <snat_v6_nat+0x302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a86;
	}
x86_l_a70:
	/* 0xa70: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_a77:
	/* 0xa77: jmp    a8d <snat_v6_nat+0x309> */
	goto x86_l_a8d;
x86_l_a79:
	/* 0xa79: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_a7e:
	/* 0xa7e: mov    QWORD PTR [r14],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a81:
	/* 0xa81: jmp    7e7 <snat_v6_nat+0x63> */
	goto x86_l_7e7;
x86_l_a86:
	/* 0xa86: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_a8d:
	/* 0xa8d: mov    BYTE PTR [r13+r14*1+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R14, 0), 158913789952ULL);
x86_l_a93:
	/* 0xa93: mov    DWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_a9e:
	/* 0xa9e: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_aa5:
	/* 0xaa5: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_aa8:
	/* 0xaa8: bt     QWORD PTR [rsp+0xa8],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 721554505768ULL);
x86_l_ab2:
	/* 0xab2: mov    QWORD PTR [rsp+0xb0],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_aba:
	/* 0xaba: jae    b88 <snat_v6_nat+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b88;
	}
x86_l_ac0:
	/* 0xac0: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_ac2:
	/* 0xac2: je     b88 <snat_v6_nat+0x404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b88;
	}
x86_l_ac8:
	/* 0xac8: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_acd:
	/* 0xacd: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_ad0:
	/* 0xad0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad5:
	/* 0xad5: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad8:
	/* 0xad8: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_ae1:
	/* 0xae1: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_aea:
	/* 0xaea: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_af4:
	/* 0xaf4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_af9:
	/* 0xaf9: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b00:
	/* 0xb00: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b05:
	/* 0xb05: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b0a:
	/* 0xb0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0c:
	/* 0xb0c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b0f:
	/* 0xb0f: je     b50 <snat_v6_nat+0x3cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b50;
	}
x86_l_b11:
	/* 0xb11: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b14:
	/* 0xb14: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b18:
	/* 0xb18: jmp    b78 <snat_v6_nat+0x3f4> */
	goto x86_l_b78;
x86_l_b1a:
	/* 0xb1a: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_b1f:
	/* 0xb1f: lea    edx,[rcx-0x87] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551481ULL);
x86_l_b25:
	/* 0xb25: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_b28:
	/* 0xb28: jb     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7e7;
	}
x86_l_b2e:
	/* 0xb2e: cmp    ecx,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 128ULL);
x86_l_b34:
	/* 0xb34: je     f77 <snat_v6_nat+0x7f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3959ULL;
	}
x86_l_b3a:
	/* 0xb3a: cmp    ecx,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 129ULL);
x86_l_b40:
	/* 0xb40: je     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e7;
	}
x86_l_b46:
	/* 0xb46: mov    eax,0xffffff58 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967128ULL);
x86_l_b4b:
	/* 0xb4b: jmp    7e7 <snat_v6_nat+0x63> */
	goto x86_l_7e7;
x86_l_b50:
	/* 0xb50: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_b59:
	/* 0xb59: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b5e:
	/* 0xb5e: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b65:
	/* 0xb65: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b6a:
	/* 0xb6a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b6f:
	/* 0xb6f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b74:
	/* 0xb74: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b76:
	/* 0xb76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b78:
	/* 0xb78: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_b7b:
	/* 0xb7b: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b83:
	/* 0xb83: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b88:
	/* 0xb88: bt     QWORD PTR [rsp+0xa8],0x29 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 721554505769ULL);
x86_l_b92:
	/* 0xb92: jb     c0b <snat_v6_nat+0x487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c0b;
	}
x86_l_b94:
	/* 0xb94: cmp    WORD PTR [rsp+0xa0],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 687194767366ULL);
x86_l_b9d:
	/* 0xb9d: jne    c0b <snat_v6_nat+0x487> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c0b;
	}
x86_l_b9f:
	/* 0xb9f: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_ba2:
	/* 0xba2: lea    esi,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ba6:
	/* 0xba6: lea    rdx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_bae:
	/* 0xbae: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_bb3:
	/* 0xbb3: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bb8:
	/* 0xbb8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bbd:
	/* 0xbbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbf:
	/* 0xbbf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc1:
	/* 0xbc1: js     c01 <snat_v6_nat+0x47d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_c01;
	}
x86_l_bc3:
	/* 0xbc3: mov    ecx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_bca:
	/* 0xbca: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_bcc:
	/* 0xbcc: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_bd1:
	/* 0xbd1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd3:
	/* 0xbd3: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_bd8:
	/* 0xbd8: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_bdb:
	/* 0xbdb: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bdf:
	/* 0xbdf: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_be5:
	/* 0xbe5: jne    1559 <snat_v6_nat+0xdd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5465ULL;
	}
x86_l_beb:
	/* 0xbeb: mov    dl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_8);
x86_l_bed:
	/* 0xbed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bf0:
	/* 0xbf0: mov    DWORD PTR [rsp+0xbc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_bf7:
	/* 0xbf7: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bff:
	/* 0xbff: jmp    c21 <snat_v6_nat+0x49d> */
	goto x86_l_c21;
x86_l_c01:
	/* 0xc01: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_c06:
	/* 0xc06: jmp    7e7 <snat_v6_nat+0x63> */
	goto x86_l_7e7;
x86_l_c0b:
	/* 0xc0b: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_c16:
	/* 0xc16: mov    eax,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c1d:
	/* 0xc1d: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c21:
	/* 0xc21: add    r13,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c24:
	/* 0xc24: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c29:
	/* 0xc29: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_c2c:
	/* 0xc2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2e:
	/* 0xc2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c31:
	/* 0xc31: je     167b <snat_v6_nat+0xef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5755ULL;
	}
x86_l_c37:
	/* 0xc37: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_c3a:
	/* 0xc3a: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c3d:
	/* 0xc3d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c3f:
	/* 0xc3f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c41:
	/* 0xc41: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_c44:
	/* 0xc44: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c49:
	/* 0xc49: je     eab <snat_v6_nat+0x727> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3755ULL;
	}
x86_l_c4f:
	/* 0xc4f: mov    rdx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c56:
	/* 0xc56: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c59:
	/* 0xc59: je     da3 <snat_v6_nat+0x61f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3491ULL;
	}
x86_l_c5f:
	/* 0xc5f: mov    rcx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c66:
	/* 0xc66: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_c6a:
	/* 0xc6a: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c6e:
	/* 0xc6e: jmp    da9 <snat_v6_nat+0x625> */
	return 3497ULL;
x86_l_c73:
	/* 0xc73: mov    eax,0xffffff6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967151ULL);
x86_l_c78:
	/* 0xc78: cmp    BYTE PTR [rsp+0xc1],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 828928688134ULL);
x86_l_c80:
	/* 0xc80: ja     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_7e7;
	}
x86_l_c86:
	/* 0xc86: lea    r14d,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c8a:
	/* 0xc8a: mov    QWORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_c93:
	/* 0xc93: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_c9c:
	/* 0xc9c: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ca5:
	/* 0xca5: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_cae:
	/* 0xcae: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cb7:
	/* 0xcb7: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cbc:
	/* 0xcbc: mov    r13d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 40ULL);
x86_l_cc2:
	/* 0xcc2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_cc7:
	/* 0xcc7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cca:
	/* 0xcca: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_ccd:
	/* 0xccd: mov    ecx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 40ULL);
x86_l_cd2:
	/* 0xcd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd4:
	/* 0xcd4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_cd6:
	/* 0xcd6: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_cdb:
	/* 0xcdb: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_cdd:
	/* 0xcdd: js     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_7e7;
	}
x86_l_ce3:
	/* 0xce3: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ceb:
	/* 0xceb: movzx  r15d,BYTE PTR [rsp+0x66] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 102ULL);
x86_l_cf1:
	/* 0xcf1: mov    BYTE PTR [rsp+0x3c],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_cf6:
	/* 0xcf6: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cfe:
	/* 0xcfe: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d03:
	/* 0xd03: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d08:
	/* 0xd08: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d0d:
	/* 0xd0d: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d12:
	/* 0xd12: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d17:
	/* 0xd17: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d1c:
	/* 0xd1c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d21:
	/* 0xd21: mov    BYTE PTR [rsp+0x3d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005056ULL);
x86_l_d26:
	/* 0xd26: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_d2a:
	/* 0xd2a: ja     11fa <snat_v6_nat+0xa76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 4602ULL;
	}
x86_l_d30:
	/* 0xd30: mov    ebx,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967140ULL);
x86_l_d35:
	/* 0xd35: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_d3f:
	/* 0xd3f: bt     rax,r15 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_d43:
	/* 0xd43: jae    fa3 <snat_v6_nat+0x81f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 4003ULL;
	}
x86_l_d49:
	/* 0xd49: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d51:
	/* 0xd51: lea    esi,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d54:
	/* 0xd54: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_d57:
	/* 0xd57: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_d5c:
	/* 0xd5c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d61:
	/* 0xd61: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d66:
	/* 0xd66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d68:
	/* 0xd68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d6a:
	/* 0xd6a: js     1319 <snat_v6_nat+0xb95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4889ULL;
	}
x86_l_d70:
	/* 0xd70: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d74:
	/* 0xd74: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d77:
	/* 0xd77: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_d7b:
	/* 0xd7b: jle    d91 <snat_v6_nat+0x60d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_d91;
	}
x86_l_d7d:
	/* 0xd7d: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_d81:
	/* 0xd81: je     1071 <snat_v6_nat+0x8ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4209ULL;
	}
x86_l_d87:
	/* 0xd87: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_d8b:
	/* 0xd8b: jne    1079 <snat_v6_nat+0x8f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4217ULL;
	}
x86_l_d91:
	/* 0xd91: movzx  ecx,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_d96:
	/* 0xd96: lea    r13d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
	return 3486ULL;
}

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3486ULL: goto x86_l_d9e;
	case 3491ULL: goto x86_l_da3;
	case 3497ULL: goto x86_l_da9;
	case 3506ULL: goto x86_l_db2;
	case 3508ULL: goto x86_l_db4;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3522ULL: goto x86_l_dc2;
	case 3527ULL: goto x86_l_dc7;
	case 3529ULL: goto x86_l_dc9;
	case 3534ULL: goto x86_l_dce;
	case 3540ULL: goto x86_l_dd4;
	case 3544ULL: goto x86_l_dd8;
	case 3547ULL: goto x86_l_ddb;
	case 3549ULL: goto x86_l_ddd;
	case 3556ULL: goto x86_l_de4;
	case 3560ULL: goto x86_l_de8;
	case 3564ULL: goto x86_l_dec;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3584ULL: goto x86_l_e00;
	case 3587ULL: goto x86_l_e03;
	case 3589ULL: goto x86_l_e05;
	case 3594ULL: goto x86_l_e0a;
	case 3596ULL: goto x86_l_e0c;
	case 3598ULL: goto x86_l_e0e;
	case 3602ULL: goto x86_l_e12;
	case 3604ULL: goto x86_l_e14;
	case 3609ULL: goto x86_l_e19;
	case 3611ULL: goto x86_l_e1b;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3627ULL: goto x86_l_e2b;
	case 3630ULL: goto x86_l_e2e;
	case 3635ULL: goto x86_l_e33;
	case 3639ULL: goto x86_l_e37;
	case 3642ULL: goto x86_l_e3a;
	case 3650ULL: goto x86_l_e42;
	case 3654ULL: goto x86_l_e46;
	case 3659ULL: goto x86_l_e4b;
	case 3663ULL: goto x86_l_e4f;
	case 3667ULL: goto x86_l_e53;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3679ULL: goto x86_l_e5f;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3691ULL: goto x86_l_e6b;
	case 3694ULL: goto x86_l_e6e;
	case 3696ULL: goto x86_l_e70;
	case 3701ULL: goto x86_l_e75;
	case 3706ULL: goto x86_l_e7a;
	case 3708ULL: goto x86_l_e7c;
	case 3711ULL: goto x86_l_e7f;
	case 3713ULL: goto x86_l_e81;
	case 3715ULL: goto x86_l_e83;
	case 3717ULL: goto x86_l_e85;
	case 3720ULL: goto x86_l_e88;
	case 3722ULL: goto x86_l_e8a;
	case 3726ULL: goto x86_l_e8e;
	case 3730ULL: goto x86_l_e92;
	case 3737ULL: goto x86_l_e99;
	case 3739ULL: goto x86_l_e9b;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3755ULL: goto x86_l_eab;
	case 3762ULL: goto x86_l_eb2;
	case 3765ULL: goto x86_l_eb5;
	case 3772ULL: goto x86_l_ebc;
	case 3774ULL: goto x86_l_ebe;
	case 3779ULL: goto x86_l_ec3;
	case 3781ULL: goto x86_l_ec5;
	case 3786ULL: goto x86_l_eca;
	case 3789ULL: goto x86_l_ecd;
	case 3791ULL: goto x86_l_ecf;
	case 3794ULL: goto x86_l_ed2;
	case 3800ULL: goto x86_l_ed8;
	case 3805ULL: goto x86_l_edd;
	case 3807ULL: goto x86_l_edf;
	case 3813ULL: goto x86_l_ee5;
	case 3820ULL: goto x86_l_eec;
	case 3825ULL: goto x86_l_ef1;
	case 3828ULL: goto x86_l_ef4;
	case 3833ULL: goto x86_l_ef9;
	case 3840ULL: goto x86_l_f00;
	case 3843ULL: goto x86_l_f03;
	case 3849ULL: goto x86_l_f09;
	case 3856ULL: goto x86_l_f10;
	case 3860ULL: goto x86_l_f14;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3873ULL: goto x86_l_f21;
	case 3878ULL: goto x86_l_f26;
	case 3881ULL: goto x86_l_f29;
	case 3885ULL: goto x86_l_f2d;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3901ULL: goto x86_l_f3d;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3912ULL: goto x86_l_f48;
	case 3914ULL: goto x86_l_f4a;
	case 3916ULL: goto x86_l_f4c;
	case 3922ULL: goto x86_l_f52;
	case 3925ULL: goto x86_l_f55;
	case 3932ULL: goto x86_l_f5c;
	case 3936ULL: goto x86_l_f60;
	case 3938ULL: goto x86_l_f62;
	case 3945ULL: goto x86_l_f69;
	case 3947ULL: goto x86_l_f6b;
	case 3949ULL: goto x86_l_f6d;
	case 3953ULL: goto x86_l_f71;
	case 3957ULL: goto x86_l_f75;
	case 3959ULL: goto x86_l_f77;
	case 3967ULL: goto x86_l_f7f;
	case 3975ULL: goto x86_l_f87;
	case 3981ULL: goto x86_l_f8d;
	case 3990ULL: goto x86_l_f96;
	case 3998ULL: goto x86_l_f9e;
	case 4003ULL: goto x86_l_fa3;
	case 4007ULL: goto x86_l_fa7;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4024ULL: goto x86_l_fb8;
	case 4027ULL: goto x86_l_fbb;
	case 4032ULL: goto x86_l_fc0;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4045ULL: goto x86_l_fcd;
	case 4047ULL: goto x86_l_fcf;
	case 4051ULL: goto x86_l_fd3;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4060ULL: goto x86_l_fdc;
	case 4062ULL: goto x86_l_fde;
	case 4066ULL: goto x86_l_fe2;
	case 4076ULL: goto x86_l_fec;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4088ULL: goto x86_l_ff8;
	case 4091ULL: goto x86_l_ffb;
	case 4095ULL: goto x86_l_fff;
	case 4100ULL: goto x86_l_1004;
	case 4104ULL: goto x86_l_1008;
	case 4108ULL: goto x86_l_100c;
	case 4112ULL: goto x86_l_1010;
	case 4116ULL: goto x86_l_1014;
	case 4120ULL: goto x86_l_1018;
	case 4122ULL: goto x86_l_101a;
	case 4129ULL: goto x86_l_1021;
	case 4131ULL: goto x86_l_1023;
	case 4134ULL: goto x86_l_1026;
	case 4137ULL: goto x86_l_1029;
	case 4139ULL: goto x86_l_102b;
	case 4144ULL: goto x86_l_1030;
	case 4147ULL: goto x86_l_1033;
	case 4149ULL: goto x86_l_1035;
	case 4153ULL: goto x86_l_1039;
	case 4155ULL: goto x86_l_103b;
	case 4159ULL: goto x86_l_103f;
	case 4161ULL: goto x86_l_1041;
	case 4169ULL: goto x86_l_1049;
	case 4176ULL: goto x86_l_1050;
	case 4178ULL: goto x86_l_1052;
	case 4182ULL: goto x86_l_1056;
	case 4184ULL: goto x86_l_1058;
	case 4188ULL: goto x86_l_105c;
	case 4192ULL: goto x86_l_1060;
	case 4196ULL: goto x86_l_1064;
	case 4198ULL: goto x86_l_1066;
	case 4204ULL: goto x86_l_106c;
	case 4209ULL: goto x86_l_1071;
	case 4215ULL: goto x86_l_1077;
	case 4217ULL: goto x86_l_1079;
	case 4222ULL: goto x86_l_107e;
	case 4230ULL: goto x86_l_1086;
	case 4234ULL: goto x86_l_108a;
	case 4237ULL: goto x86_l_108d;
	case 4243ULL: goto x86_l_1093;
	case 4245ULL: goto x86_l_1095;
	case 4255ULL: goto x86_l_109f;
	case 4259ULL: goto x86_l_10a3;
	case 4261ULL: goto x86_l_10a5;
	case 4265ULL: goto x86_l_10a9;
	case 4268ULL: goto x86_l_10ac;
	case 4273ULL: goto x86_l_10b1;
	case 4278ULL: goto x86_l_10b6;
	case 4283ULL: goto x86_l_10bb;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4293ULL: goto x86_l_10c5;
	case 4298ULL: goto x86_l_10ca;
	case 4302ULL: goto x86_l_10ce;
	case 4305ULL: goto x86_l_10d1;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4329ULL: goto x86_l_10e9;
	case 4331ULL: goto x86_l_10eb;
	case 4341ULL: goto x86_l_10f5;
	case 4346ULL: goto x86_l_10fa;
	case 4353ULL: goto x86_l_1101;
	case 4355ULL: goto x86_l_1103;
	case 4358ULL: goto x86_l_1106;
	case 4362ULL: goto x86_l_110a;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4378ULL: goto x86_l_111a;
	case 4388ULL: goto x86_l_1124;
	case 4391ULL: goto x86_l_1127;
	case 4394ULL: goto x86_l_112a;
	case 4400ULL: goto x86_l_1130;
	case 4402ULL: goto x86_l_1132;
	case 4406ULL: goto x86_l_1136;
	case 4412ULL: goto x86_l_113c;
	case 4414ULL: goto x86_l_113e;
	case 4418ULL: goto x86_l_1142;
	case 4421ULL: goto x86_l_1145;
	case 4426ULL: goto x86_l_114a;
	case 4431ULL: goto x86_l_114f;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4440ULL: goto x86_l_1158;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4455ULL: goto x86_l_1167;
	case 4458ULL: goto x86_l_116a;
	case 4460ULL: goto x86_l_116c;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4468ULL: goto x86_l_1174;
	case 4470ULL: goto x86_l_1176;
	case 4475ULL: goto x86_l_117b;
	case 4482ULL: goto x86_l_1182;
	case 4484ULL: goto x86_l_1184;
	case 4494ULL: goto x86_l_118e;
	case 4499ULL: goto x86_l_1193;
	case 4506ULL: goto x86_l_119a;
	case 4508ULL: goto x86_l_119c;
	case 4511ULL: goto x86_l_119f;
	case 4513ULL: goto x86_l_11a1;
	case 4518ULL: goto x86_l_11a6;
	case 4528ULL: goto x86_l_11b0;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4536ULL: goto x86_l_11b8;
	case 4538ULL: goto x86_l_11ba;
	case 4542ULL: goto x86_l_11be;
	case 4544ULL: goto x86_l_11c0;
	case 4547ULL: goto x86_l_11c3;
	case 4550ULL: goto x86_l_11c6;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4563ULL: goto x86_l_11d3;
	case 4568ULL: goto x86_l_11d8;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4577ULL: goto x86_l_11e1;
	case 4579ULL: goto x86_l_11e3;
	case 4584ULL: goto x86_l_11e8;
	case 4589ULL: goto x86_l_11ed;
	case 4593ULL: goto x86_l_11f1;
	case 4595ULL: goto x86_l_11f3;
	case 4597ULL: goto x86_l_11f5;
	case 4602ULL: goto x86_l_11fa;
	case 4607ULL: goto x86_l_11ff;
	case 4610ULL: goto x86_l_1202;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4621ULL: goto x86_l_120d;
	case 4625ULL: goto x86_l_1211;
	case 4628ULL: goto x86_l_1214;
	case 4634ULL: goto x86_l_121a;
	case 4637ULL: goto x86_l_121d;
	case 4643ULL: goto x86_l_1223;
	case 4648ULL: goto x86_l_1228;
	case 4653ULL: goto x86_l_122d;
	case 4656ULL: goto x86_l_1230;
	case 4661ULL: goto x86_l_1235;
	case 4663ULL: goto x86_l_1237;
	case 4665ULL: goto x86_l_1239;
	case 4670ULL: goto x86_l_123e;
	case 4675ULL: goto x86_l_1243;
	case 4677ULL: goto x86_l_1245;
	case 4683ULL: goto x86_l_124b;
	case 4690ULL: goto x86_l_1252;
	case 4695ULL: goto x86_l_1257;
	case 4700ULL: goto x86_l_125c;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4711ULL: goto x86_l_1267;
	case 4714ULL: goto x86_l_126a;
	case 4720ULL: goto x86_l_1270;
	case 4725ULL: goto x86_l_1275;
	case 4729ULL: goto x86_l_1279;
	case 4734ULL: goto x86_l_127e;
	case 4738ULL: goto x86_l_1282;
	case 4742ULL: goto x86_l_1286;
	case 4750ULL: goto x86_l_128e;
	case 4756ULL: goto x86_l_1294;
	case 4759ULL: goto x86_l_1297;
	case 4762ULL: goto x86_l_129a;
	case 4766ULL: goto x86_l_129e;
	case 4772ULL: goto x86_l_12a4;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4787ULL: goto x86_l_12b3;
	case 4792ULL: goto x86_l_12b8;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4817ULL: goto x86_l_12d1;
	case 4819ULL: goto x86_l_12d3;
	case 4824ULL: goto x86_l_12d8;
	case 4829ULL: goto x86_l_12dd;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4842ULL: goto x86_l_12ea;
	case 4846ULL: goto x86_l_12ee;
	case 4851ULL: goto x86_l_12f3;
	case 4856ULL: goto x86_l_12f8;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4866ULL: goto x86_l_1302;
	case 4871ULL: goto x86_l_1307;
	case 4873ULL: goto x86_l_1309;
	case 4878ULL: goto x86_l_130e;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4894ULL: goto x86_l_131e;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4909ULL: goto x86_l_132d;
	case 4912ULL: goto x86_l_1330;
	case 4917ULL: goto x86_l_1335;
	case 4922ULL: goto x86_l_133a;
	case 4925ULL: goto x86_l_133d;
	case 4929ULL: goto x86_l_1341;
	case 4937ULL: goto x86_l_1349;
	case 4942ULL: goto x86_l_134e;
	case 4947ULL: goto x86_l_1353;
	case 4950ULL: goto x86_l_1356;
	case 4955ULL: goto x86_l_135b;
	case 4958ULL: goto x86_l_135e;
	case 4960ULL: goto x86_l_1360;
	case 4967ULL: goto x86_l_1367;
	case 4975ULL: goto x86_l_136f;
	case 4978ULL: goto x86_l_1372;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4991ULL: goto x86_l_137f;
	case 4996ULL: goto x86_l_1384;
	case 4999ULL: goto x86_l_1387;
	case 5001ULL: goto x86_l_1389;
	case 5003ULL: goto x86_l_138b;
	case 5009ULL: goto x86_l_1391;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5021ULL: goto x86_l_139d;
	case 5024ULL: goto x86_l_13a0;
	case 5029ULL: goto x86_l_13a5;
	case 5033ULL: goto x86_l_13a9;
	case 5035ULL: goto x86_l_13ab;
	case 5040ULL: goto x86_l_13b0;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5065ULL: goto x86_l_13c9;
	case 5067ULL: goto x86_l_13cb;
	case 5072ULL: goto x86_l_13d0;
	case 5080ULL: goto x86_l_13d8;
	case 5083ULL: goto x86_l_13db;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d9e:
	/* 0xd9e: jmp    1086 <snat_v6_nat+0x902> */
	goto x86_l_1086;
x86_l_da3:
	/* 0xda3: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_da9:
	/* 0xda9: cmp    WORD PTR [rsp+0xa0],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 687194767366ULL);
x86_l_db2:
	/* 0xdb2: jne    dec <snat_v6_nat+0x668> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dec;
	}
x86_l_db4:
	/* 0xdb4: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db8:
	/* 0xdb8: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_dba:
	/* 0xdba: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_dbd:
	/* 0xdbd: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_dc0:
	/* 0xdc0: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_dc2:
	/* 0xdc2: mov    WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dc7:
	/* 0xdc7: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_dc9:
	/* 0xdc9: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_dce:
	/* 0xdce: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_dd4:
	/* 0xdd4: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_dd8:
	/* 0xdd8: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ddb:
	/* 0xddb: je     dec <snat_v6_nat+0x668> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dec;
	}
x86_l_ddd:
	/* 0xddd: mov    rax,QWORD PTR [rip+0x693] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_de4:
	/* 0xde4: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_de8:
	/* 0xde8: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_dec:
	/* 0xdec: mov    QWORD PTR [rsp+0xd0],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_df4:
	/* 0xdf4: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_df7:
	/* 0xdf7: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfc:
	/* 0xdfc: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e00:
	/* 0xe00: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e03:
	/* 0xe03: je     e14 <snat_v6_nat+0x690> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e14;
	}
x86_l_e05:
	/* 0xe05: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_e0a:
	/* 0xe0a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e0c:
	/* 0xe0c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e0e:
	/* 0xe0e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_e12:
	/* 0xe12: jmp    e37 <snat_v6_nat+0x6b3> */
	goto x86_l_e37;
x86_l_e14:
	/* 0xe14: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_e19:
	/* 0xe19: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e1b:
	/* 0xe1b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e1d:
	/* 0xe1d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_e21:
	/* 0xe21: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_e2b:
	/* 0xe2b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e2e:
	/* 0xe2e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e33:
	/* 0xe33: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_e37:
	/* 0xe37: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e3a:
	/* 0xe3a: mov    r8,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_e42:
	/* 0xe42: mov    DWORD PTR [r8+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e46:
	/* 0xe46: movzx  ecx,BYTE PTR [r8+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_e4b:
	/* 0xe4b: mov    edx,DWORD PTR [r8+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e4f:
	/* 0xe4f: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_e53:
	/* 0xe53: mov    rsi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_e5a:
	/* 0xe5a: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5d:
	/* 0xe5d: je     e70 <snat_v6_nat+0x6ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e70;
	}
x86_l_e5f:
	/* 0xe5f: mov    rsi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_e66:
	/* 0xe66: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e68:
	/* 0xe68: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_e6b:
	/* 0xe6b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e6e:
	/* 0xe6e: jmp    e75 <snat_v6_nat+0x6f1> */
	goto x86_l_e75;
x86_l_e70:
	/* 0xe70: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_e75:
	/* 0xe75: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e7a:
	/* 0xe7a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e7c:
	/* 0xe7c: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_e7f:
	/* 0xe7f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_e81:
	/* 0xe81: jb     e8a <snat_v6_nat+0x706> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e8a;
	}
x86_l_e83:
	/* 0xe83: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e85:
	/* 0xe85: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_e88:
	/* 0xe88: je     e9b <snat_v6_nat+0x717> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e9b;
	}
x86_l_e8a:
	/* 0xe8a: mov    BYTE PTR [r8+0x2a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_e8e:
	/* 0xe8e: mov    DWORD PTR [r8+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e92:
	/* 0xe92: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_e99:
	/* 0xe99: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9b:
	/* 0xe9b: mov    DWORD PTR [r12+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_ea0:
	/* 0xea0: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_ea3:
	/* 0xea3: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_eab:
	/* 0xeab: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_eb2:
	/* 0xeb2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb5:
	/* 0xeb5: mov    ecx,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_ebc:
	/* 0xebc: je     eca <snat_v6_nat+0x746> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eca;
	}
x86_l_ebe:
	/* 0xebe: inc QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_ec3:
	/* 0xec3: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec5:
	/* 0xec5: add QWORD PTR [r8+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R8, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_eca:
	/* 0xeca: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ecd:
	/* 0xecd: je     f1d <snat_v6_nat+0x799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f1d;
	}
x86_l_ecf:
	/* 0xecf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ed2:
	/* 0xed2: jne    1066 <snat_v6_nat+0x8e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1066;
	}
x86_l_ed8:
	/* 0xed8: movzx  eax,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_edd:
	/* 0xedd: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_edf:
	/* 0xedf: je     1066 <snat_v6_nat+0x8e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1066;
	}
x86_l_ee5:
	/* 0xee5: mov    WORD PTR [r8+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_eec:
	/* 0xeec: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_ef1:
	/* 0xef1: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_ef4:
	/* 0xef4: mov    WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ef9:
	/* 0xef9: mov    rbx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f00:
	/* 0xf00: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f03:
	/* 0xf03: je     1590 <snat_v6_nat+0xe0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5520ULL;
	}
x86_l_f09:
	/* 0xf09: mov    rcx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f10:
	/* 0xf10: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_f14:
	/* 0xf14: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f18:
	/* 0xf18: jmp    1596 <snat_v6_nat+0xe12> */
	return 5526ULL;
x86_l_f1d:
	/* 0xf1d: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f21:
	/* 0xf21: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_f26:
	/* 0xf26: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f29:
	/* 0xf29: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_f2d:
	/* 0xf2d: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_f31:
	/* 0xf31: or     WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R8, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_f36:
	/* 0xf36: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_f3d:
	/* 0xf3d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3f:
	/* 0xf3f: mov    DWORD PTR [r12+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_f44:
	/* 0xf44: mov    eax,DWORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f48:
	/* 0xf48: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f4a:
	/* 0xf4a: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_f4c:
	/* 0xf4c: jne    1066 <snat_v6_nat+0x8e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1066;
	}
x86_l_f52:
	/* 0xf52: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_f55:
	/* 0xf55: mov    r14,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f5c:
	/* 0xf5c: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f60:
	/* 0xf60: je     fb2 <snat_v6_nat+0x82e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb2;
	}
x86_l_f62:
	/* 0xf62: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f69:
	/* 0xf69: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6b:
	/* 0xf6b: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f6d:
	/* 0xf6d: lea    r15d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_f71:
	/* 0xf71: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f75:
	/* 0xf75: jmp    fb8 <snat_v6_nat+0x834> */
	goto x86_l_fb8;
x86_l_f77:
	/* 0xf77: mov    WORD PTR [r12+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_f7f:
	/* 0xf7f: movzx  eax,WORD PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 196ULL);
x86_l_f87:
	/* 0xf87: mov    WORD PTR [r12+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_f8d:
	/* 0xf8d: mov    DWORD PTR [r12+0x38],0xffff0000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244813070336ULL);
x86_l_f96:
	/* 0xf96: mov    DWORD PTR [rsp+0x5c],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991236ULL);
x86_l_f9e:
	/* 0xf9e: jmp    9c6 <snat_v6_nat+0x242> */
	return 2502ULL;
x86_l_fa3:
	/* 0xfa3: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_fa7:
	/* 0xfa7: je     11f3 <snat_v6_nat+0xa6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f3;
	}
x86_l_fad:
	/* 0xfad: jmp    11fa <snat_v6_nat+0xa76> */
	goto x86_l_11fa;
x86_l_fb2:
	/* 0xfb2: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_fb8:
	/* 0xfb8: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_fbb:
	/* 0xfbb: shr    DWORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 68719476744ULL);
x86_l_fc0:
	/* 0xfc0: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc4:
	/* 0xfc4: je     fd5 <snat_v6_nat+0x851> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd5;
	}
x86_l_fc6:
	/* 0xfc6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_fcb:
	/* 0xfcb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fcd:
	/* 0xfcd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fcf:
	/* 0xfcf: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_fd3:
	/* 0xfd3: jmp    ff8 <snat_v6_nat+0x874> */
	goto x86_l_ff8;
x86_l_fd5:
	/* 0xfd5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_fda:
	/* 0xfda: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fdc:
	/* 0xfdc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fde:
	/* 0xfde: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_fe2:
	/* 0xfe2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_fec:
	/* 0xfec: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fef:
	/* 0xfef: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_ff4:
	/* 0xff4: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_ff8:
	/* 0xff8: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ffb:
	/* 0xffb: mov    DWORD PTR [r13+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fff:
	/* 0xfff: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1004:
	/* 0x1004: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1008:
	/* 0x1008: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100c:
	/* 0x100c: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1010:
	/* 0x1010: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1014:
	/* 0x1014: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1018:
	/* 0x1018: je     102b <snat_v6_nat+0x8a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_102b;
	}
x86_l_101a:
	/* 0x101a: mov    rsi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1021:
	/* 0x1021: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1023:
	/* 0x1023: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1026:
	/* 0x1026: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1029:
	/* 0x1029: jmp    1030 <snat_v6_nat+0x8ac> */
	goto x86_l_1030;
x86_l_102b:
	/* 0x102b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1030:
	/* 0x1030: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1035:
	/* 0x1035: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1039:
	/* 0x1039: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_103b:
	/* 0x103b: mov    DWORD PTR [rsp+0x10],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_103f:
	/* 0x103f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1041:
	/* 0x1041: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1049:
	/* 0x1049: mov    rdx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1050:
	/* 0x1050: jb     1058 <snat_v6_nat+0x8d4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1058;
	}
x86_l_1052:
	/* 0x1052: cmp    cl,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1056:
	/* 0x1056: je     1066 <snat_v6_nat+0x8e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1066;
	}
x86_l_1058:
	/* 0x1058: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105c:
	/* 0x105c: mov    BYTE PTR [r13+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1060:
	/* 0x1060: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1064:
	/* 0x1064: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1066:
	/* 0x1066: mov    BYTE PTR [r12+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_106c:
	/* 0x106c: jmp    182e <snat_v6_nat+0x10aa> */
	return 6190ULL;
x86_l_1071:
	/* 0x1071: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1077:
	/* 0x1077: jmp    1086 <snat_v6_nat+0x902> */
	goto x86_l_1086;
x86_l_1079:
	/* 0x1079: movzx  ecx,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_107e:
	/* 0x107e: lea    r13d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_1086:
	/* 0x1086: add    r13d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_108a:
	/* 0x108a: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_108d:
	/* 0x108d: ja     119c <snat_v6_nat+0xa18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_119c;
	}
x86_l_1093:
	/* 0x1093: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1095:
	/* 0x1095: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_109f:
	/* 0x109f: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_10a3:
	/* 0x10a3: jae    1103 <snat_v6_nat+0x97f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1103;
	}
x86_l_10a5:
	/* 0x10a5: lea    esi,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_10a9:
	/* 0x10a9: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_10ac:
	/* 0x10ac: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_10b1:
	/* 0x10b1: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b6:
	/* 0x10b6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10bb:
	/* 0x10bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bd:
	/* 0x10bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10bf:
	/* 0x10bf: js     1319 <snat_v6_nat+0xb95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1319;
	}
x86_l_10c5:
	/* 0x10c5: movzx  r15d,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_10ca:
	/* 0x10ca: movzx  ecx,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_10ce:
	/* 0x10ce: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_10d1:
	/* 0x10d1: jle    10eb <snat_v6_nat+0x967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_10eb;
	}
x86_l_10d3:
	/* 0x10d3: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_10d6:
	/* 0x10d6: je     1115 <snat_v6_nat+0x991> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1115;
	}
x86_l_10d8:
	/* 0x10d8: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_10db:
	/* 0x10db: jne    10eb <snat_v6_nat+0x967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10eb;
	}
x86_l_10dd:
	/* 0x10dd: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_10e2:
	/* 0x10e2: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_10e9:
	/* 0x10e9: jmp    111a <snat_v6_nat+0x996> */
	goto x86_l_111a;
x86_l_10eb:
	/* 0x10eb: movabs rbp,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_10f5:
	/* 0x10f5: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_10fa:
	/* 0x10fa: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_1101:
	/* 0x1101: jmp    1124 <snat_v6_nat+0x9a0> */
	goto x86_l_1124;
x86_l_1103:
	/* 0x1103: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1106:
	/* 0x1106: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_110a:
	/* 0x110a: je     11f3 <snat_v6_nat+0xa6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f3;
	}
x86_l_1110:
	/* 0x1110: jmp    11fa <snat_v6_nat+0xa76> */
	goto x86_l_11fa;
x86_l_1115:
	/* 0x1115: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_111a:
	/* 0x111a: movabs rbp,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1124:
	/* 0x1124: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1127:
	/* 0x1127: cmp    ecx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_112a:
	/* 0x112a: ja     11fa <snat_v6_nat+0xa76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11fa;
	}
x86_l_1130:
	/* 0x1130: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1132:
	/* 0x1132: bt     rbp,rax */
	X86_SIM_L_EXEC_BT(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1136:
	/* 0x1136: jae    11ed <snat_v6_nat+0xa69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11ed;
	}
x86_l_113c:
	/* 0x113c: mov    ebp,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_32);
x86_l_113e:
	/* 0x113e: lea    esi,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1142:
	/* 0x1142: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1145:
	/* 0x1145: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_114a:
	/* 0x114a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_114f:
	/* 0x114f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1154:
	/* 0x1154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1156:
	/* 0x1156: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1158:
	/* 0x1158: js     1319 <snat_v6_nat+0xb95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1319;
	}
x86_l_115e:
	/* 0x115e: movzx  r15d,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1163:
	/* 0x1163: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1167:
	/* 0x1167: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_116a:
	/* 0x116a: jle    1184 <snat_v6_nat+0xa00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1184;
	}
x86_l_116c:
	/* 0x116c: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_116f:
	/* 0x116f: je     11a1 <snat_v6_nat+0xa1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11a1;
	}
x86_l_1171:
	/* 0x1171: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1174:
	/* 0x1174: jne    1184 <snat_v6_nat+0xa00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1184;
	}
x86_l_1176:
	/* 0x1176: movzx  ecx,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_117b:
	/* 0x117b: lea    ecx,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_1182:
	/* 0x1182: jmp    11a6 <snat_v6_nat+0xa22> */
	goto x86_l_11a6;
x86_l_1184:
	/* 0x1184: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_118e:
	/* 0x118e: movzx  ecx,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1193:
	/* 0x1193: lea    ecx,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_119a:
	/* 0x119a: jmp    11b0 <snat_v6_nat+0xa2c> */
	goto x86_l_11b0;
x86_l_119c:
	/* 0x119c: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_119f:
	/* 0x119f: jmp    11fa <snat_v6_nat+0xa76> */
	goto x86_l_11fa;
x86_l_11a1:
	/* 0x11a1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11a6:
	/* 0x11a6: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_11b0:
	/* 0x11b0: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11b3:
	/* 0x11b3: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_11b6:
	/* 0x11b6: ja     11fa <snat_v6_nat+0xa76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_11fa;
	}
x86_l_11b8:
	/* 0x11b8: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11ba:
	/* 0x11ba: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_11be:
	/* 0x11be: jae    11ed <snat_v6_nat+0xa69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_11ed;
	}
x86_l_11c0:
	/* 0x11c0: add    r13d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11c3:
	/* 0x11c3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_11c6:
	/* 0x11c6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_11cb:
	/* 0x11cb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d0:
	/* 0x11d0: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_11d3:
	/* 0x11d3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11d8:
	/* 0x11d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11da:
	/* 0x11da: mov    ebx,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 4294967162ULL);
x86_l_11df:
	/* 0x11df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11e1:
	/* 0x11e1: js     11f3 <snat_v6_nat+0xa6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_11f3;
	}
x86_l_11e3:
	/* 0x11e3: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_11e8:
	/* 0x11e8: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_11ed:
	/* 0x11ed: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_11f1:
	/* 0x11f1: jne    11fa <snat_v6_nat+0xa76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_11fa;
	}
x86_l_11f3:
	/* 0x11f3: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_11f5:
	/* 0x11f5: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_11fa:
	/* 0x11fa: mov    BYTE PTR [rsp+0x3c],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_11ff:
	/* 0x11ff: add    r13d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1202:
	/* 0x1202: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1206:
	/* 0x1206: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120b:
	/* 0x120b: je     1223 <snat_v6_nat+0xa9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1223;
	}
x86_l_120d:
	/* 0x120d: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1211:
	/* 0x1211: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1214:
	/* 0x1214: je     12b8 <snat_v6_nat+0xb34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12b8;
	}
x86_l_121a:
	/* 0x121a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_121d:
	/* 0x121d: jne    14b9 <snat_v6_nat+0xd35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5305ULL;
	}
x86_l_1223:
	/* 0x1223: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1228:
	/* 0x1228: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_122d:
	/* 0x122d: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_1230:
	/* 0x1230: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1235:
	/* 0x1235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1237:
	/* 0x1237: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1239:
	/* 0x1239: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_123e:
	/* 0x123e: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1243:
	/* 0x1243: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1245:
	/* 0x1245: js     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2023ULL;
	}
x86_l_124b:
	/* 0x124b: mov    rdi,QWORD PTR [rip+0x693] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1252:
	/* 0x1252: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1257:
	/* 0x1257: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_125c:
	/* 0x125c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125e:
	/* 0x125e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1261:
	/* 0x1261: je     1323 <snat_v6_nat+0xb9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1323;
	}
x86_l_1267:
	/* 0x1267: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_126a:
	/* 0x126a: movzx  r15d,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_1270:
	/* 0x1270: movzx  ecx,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1275:
	/* 0x1275: movzx  edx,WORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1279:
	/* 0x1279: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_127e:
	/* 0x127e: cmp    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1282:
	/* 0x1282: mov    DWORD PTR [rsp+0x5c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1286:
	/* 0x1286: mov    WORD PTR [rsp+0xb0],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_128e:
	/* 0x128e: jne    132d <snat_v6_nat+0xba9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_132d;
	}
x86_l_1294:
	/* 0x1294: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_1297:
	/* 0x1297: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_129a:
	/* 0x129a: mov    BYTE PTR [rsp+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_129e:
	/* 0x129e: jne    1335 <snat_v6_nat+0xbb1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1335;
	}
x86_l_12a4:
	/* 0x12a4: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12a8:
	/* 0x12a8: cmp    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12ad:
	/* 0x12ad: je     14a2 <snat_v6_nat+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5282ULL;
	}
x86_l_12b3:
	/* 0x12b3: jmp    1335 <snat_v6_nat+0xbb1> */
	goto x86_l_1335;
x86_l_12b8:
	/* 0x12b8: lea    rdx,[rsp+0x4f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 79ULL);
x86_l_12bd:
	/* 0x12bd: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_12c2:
	/* 0x12c2: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_12c5:
	/* 0x12c5: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_12c8:
	/* 0x12c8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12cd:
	/* 0x12cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cf:
	/* 0x12cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d1:
	/* 0x12d1: js     1319 <snat_v6_nat+0xb95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1319;
	}
x86_l_12d3:
	/* 0x12d3: movzx  eax,BYTE PTR [rsp+0x4f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 79ULL);
x86_l_12d8:
	/* 0x12d8: cmp    eax,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_12dd:
	/* 0x12dd: je     1323 <snat_v6_nat+0xb9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1323;
	}
x86_l_12df:
	/* 0x12df: cmp    eax,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 129ULL);
x86_l_12e4:
	/* 0x12e4: jne    13b2 <snat_v6_nat+0xc2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13b2;
	}
x86_l_12ea:
	/* 0x12ea: lea    esi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12ee:
	/* 0x12ee: lea    rdx,[rsp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_12f3:
	/* 0x12f3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_12f8:
	/* 0x12f8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12fb:
	/* 0x12fb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1300:
	/* 0x1300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1302:
	/* 0x1302: mov    ebp,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_1307:
	/* 0x1307: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1309:
	/* 0x1309: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_130e:
	/* 0x130e: jns    124b <snat_v6_nat+0xac7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_124b;
	}
x86_l_1314:
	/* 0x1314: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_1319:
	/* 0x1319: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_131e:
	/* 0x131e: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_1323:
	/* 0x1323: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_1328:
	/* 0x1328: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_132d:
	/* 0x132d: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_1330:
	/* 0x1330: sete   BYTE PTR [rsp+0x40] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 64ULL);
x86_l_1335:
	/* 0x1335: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_133a:
	/* 0x133a: mov    r14,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBX, X86_WIDTH_64);
x86_l_133d:
	/* 0x133d: add    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1341:
	/* 0x1341: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1349:
	/* 0x1349: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_134e:
	/* 0x134e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1353:
	/* 0x1353: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1356:
	/* 0x1356: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_135b:
	/* 0x135b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_135e:
	/* 0x135e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1360:
	/* 0x1360: mov    DWORD PTR [rsp+0xa0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1367:
	/* 0x1367: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_136f:
	/* 0x136f: lea    esi,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1372:
	/* 0x1372: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1377:
	/* 0x1377: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_137c:
	/* 0x137c: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_137f:
	/* 0x137f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1384:
	/* 0x1384: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1387:
	/* 0x1387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1389:
	/* 0x1389: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_138b:
	/* 0x138b: js     2968 <snat_v6_nat+0x21e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10600ULL;
	}
x86_l_1391:
	/* 0x1391: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_1395:
	/* 0x1395: je     13cb <snat_v6_nat+0xc47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13cb;
	}
x86_l_1397:
	/* 0x1397: cmp    r15d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 17ULL);
x86_l_139b:
	/* 0x139b: je     13bc <snat_v6_nat+0xc38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13bc;
	}
x86_l_139d:
	/* 0x139d: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_13a0:
	/* 0x13a0: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_13a5:
	/* 0x13a5: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_13a9:
	/* 0x13a9: jne    13db <snat_v6_nat+0xc57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13db;
	}
x86_l_13ab:
	/* 0x13ab: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13b0:
	/* 0x13b0: jmp    13d0 <snat_v6_nat+0xc4c> */
	goto x86_l_13d0;
x86_l_13b2:
	/* 0x13b2: mov    eax,0xffffff6f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967151ULL);
x86_l_13b7:
	/* 0x13b7: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_13bc:
	/* 0x13bc: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_13c1:
	/* 0x13c1: mov    DWORD PTR [rsp+0x50],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383712ULL);
x86_l_13c9:
	/* 0x13c9: jmp    13d8 <snat_v6_nat+0xc54> */
	goto x86_l_13d8;
x86_l_13cb:
	/* 0x13cb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_13d0:
	/* 0x13d0: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_13d8:
	/* 0x13d8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13db:
	/* 0x13db: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
	return 5088ULL;
}

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5088ULL: goto x86_l_13e0;
	case 5094ULL: goto x86_l_13e6;
	case 5099ULL: goto x86_l_13eb;
	case 5103ULL: goto x86_l_13ef;
	case 5109ULL: goto x86_l_13f5;
	case 5112ULL: goto x86_l_13f8;
	case 5122ULL: goto x86_l_1402;
	case 5126ULL: goto x86_l_1406;
	case 5131ULL: goto x86_l_140b;
	case 5137ULL: goto x86_l_1411;
	case 5145ULL: goto x86_l_1419;
	case 5149ULL: goto x86_l_141d;
	case 5152ULL: goto x86_l_1420;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5165ULL: goto x86_l_142d;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5175ULL: goto x86_l_1437;
	case 5177ULL: goto x86_l_1439;
	case 5179ULL: goto x86_l_143b;
	case 5185ULL: goto x86_l_1441;
	case 5189ULL: goto x86_l_1445;
	case 5194ULL: goto x86_l_144a;
	case 5198ULL: goto x86_l_144e;
	case 5203ULL: goto x86_l_1453;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5217ULL: goto x86_l_1461;
	case 5221ULL: goto x86_l_1465;
	case 5223ULL: goto x86_l_1467;
	case 5225ULL: goto x86_l_1469;
	case 5231ULL: goto x86_l_146f;
	case 5236ULL: goto x86_l_1474;
	case 5239ULL: goto x86_l_1477;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5249ULL: goto x86_l_1481;
	case 5253ULL: goto x86_l_1485;
	case 5258ULL: goto x86_l_148a;
	case 5263ULL: goto x86_l_148f;
	case 5265ULL: goto x86_l_1491;
	case 5272ULL: goto x86_l_1498;
	case 5274ULL: goto x86_l_149a;
	case 5276ULL: goto x86_l_149c;
	case 5282ULL: goto x86_l_14a2;
	case 5290ULL: goto x86_l_14aa;
	case 5292ULL: goto x86_l_14ac;
	case 5300ULL: goto x86_l_14b4;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5315ULL: goto x86_l_14c3;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5330ULL: goto x86_l_14d2;
	case 5332ULL: goto x86_l_14d4;
	case 5335ULL: goto x86_l_14d7;
	case 5337ULL: goto x86_l_14d9;
	case 5339ULL: goto x86_l_14db;
	case 5343ULL: goto x86_l_14df;
	case 5348ULL: goto x86_l_14e4;
	case 5355ULL: goto x86_l_14eb;
	case 5360ULL: goto x86_l_14f0;
	case 5363ULL: goto x86_l_14f3;
	case 5366ULL: goto x86_l_14f6;
	case 5368ULL: goto x86_l_14f8;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5378ULL: goto x86_l_1502;
	case 5383ULL: goto x86_l_1507;
	case 5386ULL: goto x86_l_150a;
	case 5395ULL: goto x86_l_1513;
	case 5404ULL: goto x86_l_151c;
	case 5414ULL: goto x86_l_1526;
	case 5419ULL: goto x86_l_152b;
	case 5426ULL: goto x86_l_1532;
	case 5431ULL: goto x86_l_1537;
	case 5436ULL: goto x86_l_153c;
	case 5438ULL: goto x86_l_153e;
	case 5441ULL: goto x86_l_1541;
	case 5443ULL: goto x86_l_1543;
	case 5446ULL: goto x86_l_1546;
	case 5450ULL: goto x86_l_154a;
	case 5455ULL: goto x86_l_154f;
	case 5460ULL: goto x86_l_1554;
	case 5465ULL: goto x86_l_1559;
	case 5470ULL: goto x86_l_155e;
	case 5475ULL: goto x86_l_1563;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5506ULL: goto x86_l_1582;
	case 5511ULL: goto x86_l_1587;
	case 5513ULL: goto x86_l_1589;
	case 5515ULL: goto x86_l_158b;
	case 5520ULL: goto x86_l_1590;
	case 5526ULL: goto x86_l_1596;
	case 5535ULL: goto x86_l_159f;
	case 5537ULL: goto x86_l_15a1;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5546ULL: goto x86_l_15aa;
	case 5549ULL: goto x86_l_15ad;
	case 5551ULL: goto x86_l_15af;
	case 5556ULL: goto x86_l_15b4;
	case 5558ULL: goto x86_l_15b6;
	case 5563ULL: goto x86_l_15bb;
	case 5569ULL: goto x86_l_15c1;
	case 5573ULL: goto x86_l_15c5;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5585ULL: goto x86_l_15d1;
	case 5589ULL: goto x86_l_15d5;
	case 5593ULL: goto x86_l_15d9;
	case 5598ULL: goto x86_l_15de;
	case 5601ULL: goto x86_l_15e1;
	case 5603ULL: goto x86_l_15e3;
	case 5608ULL: goto x86_l_15e8;
	case 5610ULL: goto x86_l_15ea;
	case 5612ULL: goto x86_l_15ec;
	case 5616ULL: goto x86_l_15f0;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5625ULL: goto x86_l_15f9;
	case 5627ULL: goto x86_l_15fb;
	case 5631ULL: goto x86_l_15ff;
	case 5641ULL: goto x86_l_1609;
	case 5644ULL: goto x86_l_160c;
	case 5649ULL: goto x86_l_1611;
	case 5653ULL: goto x86_l_1615;
	case 5656ULL: goto x86_l_1618;
	case 5659ULL: goto x86_l_161b;
	case 5663ULL: goto x86_l_161f;
	case 5668ULL: goto x86_l_1624;
	case 5672ULL: goto x86_l_1628;
	case 5676ULL: goto x86_l_162c;
	case 5680ULL: goto x86_l_1630;
	case 5684ULL: goto x86_l_1634;
	case 5687ULL: goto x86_l_1637;
	case 5689ULL: goto x86_l_1639;
	case 5696ULL: goto x86_l_1640;
	case 5698ULL: goto x86_l_1642;
	case 5701ULL: goto x86_l_1645;
	case 5704ULL: goto x86_l_1648;
	case 5706ULL: goto x86_l_164a;
	case 5711ULL: goto x86_l_164f;
	case 5713ULL: goto x86_l_1651;
	case 5717ULL: goto x86_l_1655;
	case 5719ULL: goto x86_l_1657;
	case 5723ULL: goto x86_l_165b;
	case 5725ULL: goto x86_l_165d;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5741ULL: goto x86_l_166d;
	case 5743ULL: goto x86_l_166f;
	case 5747ULL: goto x86_l_1673;
	case 5751ULL: goto x86_l_1677;
	case 5755ULL: goto x86_l_167b;
	case 5762ULL: goto x86_l_1682;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5784ULL: goto x86_l_1698;
	case 5786ULL: goto x86_l_169a;
	case 5793ULL: goto x86_l_16a1;
	case 5795ULL: goto x86_l_16a3;
	case 5802ULL: goto x86_l_16aa;
	case 5810ULL: goto x86_l_16b2;
	case 5822ULL: goto x86_l_16be;
	case 5834ULL: goto x86_l_16ca;
	case 5846ULL: goto x86_l_16d6;
	case 5855ULL: goto x86_l_16df;
	case 5864ULL: goto x86_l_16e8;
	case 5873ULL: goto x86_l_16f1;
	case 5882ULL: goto x86_l_16fa;
	case 5889ULL: goto x86_l_1701;
	case 5892ULL: goto x86_l_1704;
	case 5894ULL: goto x86_l_1706;
	case 5901ULL: goto x86_l_170d;
	case 5905ULL: goto x86_l_1711;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5917ULL: goto x86_l_171d;
	case 5921ULL: goto x86_l_1721;
	case 5923ULL: goto x86_l_1723;
	case 5926ULL: goto x86_l_1726;
	case 5928ULL: goto x86_l_1728;
	case 5935ULL: goto x86_l_172f;
	case 5939ULL: goto x86_l_1733;
	case 5943ULL: goto x86_l_1737;
	case 5945ULL: goto x86_l_1739;
	case 5951ULL: goto x86_l_173f;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5963ULL: goto x86_l_174b;
	case 5965ULL: goto x86_l_174d;
	case 5969ULL: goto x86_l_1751;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5980ULL: goto x86_l_175c;
	case 5984ULL: goto x86_l_1760;
	case 5994ULL: goto x86_l_176a;
	case 5997ULL: goto x86_l_176d;
	case 6002ULL: goto x86_l_1772;
	case 6006ULL: goto x86_l_1776;
	case 6010ULL: goto x86_l_177a;
	case 6013ULL: goto x86_l_177d;
	case 6016ULL: goto x86_l_1780;
	case 6024ULL: goto x86_l_1788;
	case 6032ULL: goto x86_l_1790;
	case 6039ULL: goto x86_l_1797;
	case 6041ULL: goto x86_l_1799;
	case 6048ULL: goto x86_l_17a0;
	case 6051ULL: goto x86_l_17a3;
	case 6053ULL: goto x86_l_17a5;
	case 6060ULL: goto x86_l_17ac;
	case 6062ULL: goto x86_l_17ae;
	case 6065ULL: goto x86_l_17b1;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6075ULL: goto x86_l_17bb;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6093ULL: goto x86_l_17cd;
	case 6095ULL: goto x86_l_17cf;
	case 6097ULL: goto x86_l_17d1;
	case 6099ULL: goto x86_l_17d3;
	case 6101ULL: goto x86_l_17d5;
	case 6103ULL: goto x86_l_17d7;
	case 6105ULL: goto x86_l_17d9;
	case 6112ULL: goto x86_l_17e0;
	case 6119ULL: goto x86_l_17e7;
	case 6126ULL: goto x86_l_17ee;
	case 6128ULL: goto x86_l_17f0;
	case 6135ULL: goto x86_l_17f7;
	case 6138ULL: goto x86_l_17fa;
	case 6140ULL: goto x86_l_17fc;
	case 6149ULL: goto x86_l_1805;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6162ULL: goto x86_l_1812;
	case 6167ULL: goto x86_l_1817;
	case 6175ULL: goto x86_l_181f;
	case 6178ULL: goto x86_l_1822;
	case 6180ULL: goto x86_l_1824;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6190ULL: goto x86_l_182e;
	case 6193ULL: goto x86_l_1831;
	case 6199ULL: goto x86_l_1837;
	case 6204ULL: goto x86_l_183c;
	case 6206ULL: goto x86_l_183e;
	case 6208ULL: goto x86_l_1840;
	case 6210ULL: goto x86_l_1842;
	case 6217ULL: goto x86_l_1849;
	case 6221ULL: goto x86_l_184d;
	case 6225ULL: goto x86_l_1851;
	case 6227ULL: goto x86_l_1853;
	case 6231ULL: goto x86_l_1857;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6249ULL: goto x86_l_1869;
	case 6253ULL: goto x86_l_186d;
	case 6257ULL: goto x86_l_1871;
	case 6262ULL: goto x86_l_1876;
	case 6267ULL: goto x86_l_187b;
	case 6272ULL: goto x86_l_1880;
	case 6276ULL: goto x86_l_1884;
	case 6280ULL: goto x86_l_1888;
	case 6284ULL: goto x86_l_188c;
	case 6289ULL: goto x86_l_1891;
	case 6295ULL: goto x86_l_1897;
	case 6300ULL: goto x86_l_189c;
	case 6304ULL: goto x86_l_18a0;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6322ULL: goto x86_l_18b2;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6337ULL: goto x86_l_18c1;
	case 6343ULL: goto x86_l_18c7;
	case 6348ULL: goto x86_l_18cc;
	case 6352ULL: goto x86_l_18d0;
	case 6358ULL: goto x86_l_18d6;
	case 6365ULL: goto x86_l_18dd;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6375ULL: goto x86_l_18e7;
	case 6378ULL: goto x86_l_18ea;
	case 6384ULL: goto x86_l_18f0;
	case 6389ULL: goto x86_l_18f5;
	case 6391ULL: goto x86_l_18f7;
	case 6393ULL: goto x86_l_18f9;
	case 6395ULL: goto x86_l_18fb;
	case 6402ULL: goto x86_l_1902;
	case 6406ULL: goto x86_l_1906;
	case 6410ULL: goto x86_l_190a;
	case 6412ULL: goto x86_l_190c;
	case 6416ULL: goto x86_l_1910;
	case 6423ULL: goto x86_l_1917;
	case 6432ULL: goto x86_l_1920;
	case 6441ULL: goto x86_l_1929;
	case 6450ULL: goto x86_l_1932;
	case 6459ULL: goto x86_l_193b;
	case 6468ULL: goto x86_l_1944;
	case 6477ULL: goto x86_l_194d;
	case 6485ULL: goto x86_l_1955;
	case 6490ULL: goto x86_l_195a;
	case 6495ULL: goto x86_l_195f;
	case 6500ULL: goto x86_l_1964;
	case 6505ULL: goto x86_l_1969;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6530ULL: goto x86_l_1982;
	case 6537ULL: goto x86_l_1989;
	case 6540ULL: goto x86_l_198c;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6555ULL: goto x86_l_199b;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6571ULL: goto x86_l_19ab;
	case 6576ULL: goto x86_l_19b0;
	case 6579ULL: goto x86_l_19b3;
	case 6581ULL: goto x86_l_19b5;
	case 6583ULL: goto x86_l_19b7;
	case 6589ULL: goto x86_l_19bd;
	case 6592ULL: goto x86_l_19c0;
	case 6598ULL: goto x86_l_19c6;
	case 6605ULL: goto x86_l_19cd;
	case 6610ULL: goto x86_l_19d2;
	case 6613ULL: goto x86_l_19d5;
	case 6615ULL: goto x86_l_19d7;
	case 6618ULL: goto x86_l_19da;
	case 6620ULL: goto x86_l_19dc;
	case 6627ULL: goto x86_l_19e3;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6637ULL: goto x86_l_19ed;
	case 6642ULL: goto x86_l_19f2;
	case 6647ULL: goto x86_l_19f7;
	case 6649ULL: goto x86_l_19f9;
	case 6651ULL: goto x86_l_19fb;
	case 6653ULL: goto x86_l_19fd;
	case 6660ULL: goto x86_l_1a04;
	case 6664ULL: goto x86_l_1a08;
	case 6668ULL: goto x86_l_1a0c;
	case 6670ULL: goto x86_l_1a0e;
	case 6674ULL: goto x86_l_1a12;
	case 6681ULL: goto x86_l_1a19;
	case 6685ULL: goto x86_l_1a1d;
	case 6697ULL: goto x86_l_1a29;
	case 6709ULL: goto x86_l_1a35;
	case 6721ULL: goto x86_l_1a41;
	case 6730ULL: goto x86_l_1a4a;
	case 6739ULL: goto x86_l_1a53;
	case 6748ULL: goto x86_l_1a5c;
	case 6757ULL: goto x86_l_1a65;
	case 6766ULL: goto x86_l_1a6e;
	case 6775ULL: goto x86_l_1a77;
	case 6784ULL: goto x86_l_1a80;
	case 6793ULL: goto x86_l_1a89;
	case 6802ULL: goto x86_l_1a92;
	case 6811ULL: goto x86_l_1a9b;
	case 6819ULL: goto x86_l_1aa3;
	case 6824ULL: goto x86_l_1aa8;
	case 6829ULL: goto x86_l_1aad;
	case 6837ULL: goto x86_l_1ab5;
	case 6845ULL: goto x86_l_1abd;
	case 6851ULL: goto x86_l_1ac3;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6866ULL: goto x86_l_1ad2;
	case 6871ULL: goto x86_l_1ad7;
	case 6876ULL: goto x86_l_1adc;
	default: return 0xffffffffffffffffULL;
	}
x86_l_13e0:
	/* 0x13e0: jne    1474 <snat_v6_nat+0xcf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1474;
	}
x86_l_13e6:
	/* 0x13e6: mov    QWORD PTR [rsp+0x40],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13eb:
	/* 0x13eb: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_13ef:
	/* 0x13ef: ja     14b9 <snat_v6_nat+0xd35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_14b9;
	}
x86_l_13f5:
	/* 0x13f5: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_13f8:
	/* 0x13f8: movabs rcx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_1402:
	/* 0x1402: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1406:
	/* 0x1406: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_140b:
	/* 0x140b: jae    7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2023ULL;
	}
x86_l_1411:
	/* 0x1411: movzx  eax,WORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 176ULL);
x86_l_1419:
	/* 0x1419: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141d:
	/* 0x141d: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1420:
	/* 0x1420: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1423:
	/* 0x1423: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1428:
	/* 0x1428: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142d:
	/* 0x142d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_142f:
	/* 0x142f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1434:
	/* 0x1434: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1437:
	/* 0x1437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1439:
	/* 0x1439: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_143b:
	/* 0x143b: js     2968 <snat_v6_nat+0x21e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10600ULL;
	}
x86_l_1441:
	/* 0x1441: movzx  ecx,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1445:
	/* 0x1445: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_144a:
	/* 0x144a: lea    esi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_144e:
	/* 0x144e: mov    r8d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1453:
	/* 0x1453: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1457:
	/* 0x1457: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_145c:
	/* 0x145c: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1461:
	/* 0x1461: mov    edx,DWORD PTR [rsp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_1465:
	/* 0x1465: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1467:
	/* 0x1467: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1469:
	/* 0x1469: js     295e <snat_v6_nat+0x21da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10590ULL;
	}
x86_l_146f:
	/* 0x146f: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1474:
	/* 0x1474: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_1477:
	/* 0x1477: jne    14a2 <snat_v6_nat+0xd1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_14a2;
	}
x86_l_1479:
	/* 0x1479: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_147c:
	/* 0x147c: mov    r8d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1481:
	/* 0x1481: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1485:
	/* 0x1485: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_148a:
	/* 0x148a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_148f:
	/* 0x148f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1491:
	/* 0x1491: mov    ecx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1498:
	/* 0x1498: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149a:
	/* 0x149a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_149c:
	/* 0x149c: js     295e <snat_v6_nat+0x21da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10590ULL;
	}
x86_l_14a2:
	/* 0x14a2: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_14aa:
	/* 0x14aa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ac:
	/* 0x14ac: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14b4:
	/* 0x14b4: jmp    27c1 <snat_v6_nat+0x203d> */
	return 10177ULL;
x86_l_14b9:
	/* 0x14b9: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_14be:
	/* 0x14be: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_14c3:
	/* 0x14c3: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_14ca:
	/* 0x14ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14cf:
	/* 0x14cf: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_14d2:
	/* 0x14d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d4:
	/* 0x14d4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d7:
	/* 0x14d7: je     154f <snat_v6_nat+0xdcb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_154f;
	}
x86_l_14d9:
	/* 0x14d9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14db:
	/* 0x14db: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14df:
	/* 0x14df: jmp    8c4 <snat_v6_nat+0x140> */
	return 2244ULL;
x86_l_14e4:
	/* 0x14e4: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_14eb:
	/* 0x14eb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14f0:
	/* 0x14f0: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_14f3:
	/* 0x14f3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_14f6:
	/* 0x14f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f8:
	/* 0x14f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fa:
	/* 0x14fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14fc:
	/* 0x14fc: je     8c4 <snat_v6_nat+0x140> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2244ULL;
	}
x86_l_1502:
	/* 0x1502: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1507:
	/* 0x1507: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150a:
	/* 0x150a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1513:
	/* 0x1513: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_151c:
	/* 0x151c: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1526:
	/* 0x1526: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_152b:
	/* 0x152b: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1532:
	/* 0x1532: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1537:
	/* 0x1537: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153c:
	/* 0x153c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153e:
	/* 0x153e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1541:
	/* 0x1541: je     1563 <snat_v6_nat+0xddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1563;
	}
x86_l_1543:
	/* 0x1543: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1546:
	/* 0x1546: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_154a:
	/* 0x154a: jmp    8c4 <snat_v6_nat+0x140> */
	return 2244ULL;
x86_l_154f:
	/* 0x154f: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_1554:
	/* 0x1554: jmp    a7e <snat_v6_nat+0x2fa> */
	return 2686ULL;
x86_l_1559:
	/* 0x1559: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_155e:
	/* 0x155e: jmp    bed <snat_v6_nat+0x469> */
	return 3053ULL;
x86_l_1563:
	/* 0x1563: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_156c:
	/* 0x156c: mov    QWORD PTR [rsp+0x68],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1571:
	/* 0x1571: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1578:
	/* 0x1578: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_157d:
	/* 0x157d: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1582:
	/* 0x1582: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1587:
	/* 0x1587: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1589:
	/* 0x1589: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158b:
	/* 0x158b: jmp    8c4 <snat_v6_nat+0x140> */
	return 2244ULL;
x86_l_1590:
	/* 0x1590: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1596:
	/* 0x1596: cmp    WORD PTR [rsp+0xa0],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 687194767366ULL);
x86_l_159f:
	/* 0x159f: jne    15d9 <snat_v6_nat+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15d9;
	}
x86_l_15a1:
	/* 0x15a1: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a5:
	/* 0x15a5: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_15a7:
	/* 0x15a7: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_15aa:
	/* 0x15aa: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_15ad:
	/* 0x15ad: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_15af:
	/* 0x15af: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15b4:
	/* 0x15b4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_15b6:
	/* 0x15b6: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_15bb:
	/* 0x15bb: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_15c1:
	/* 0x15c1: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_15c5:
	/* 0x15c5: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c8:
	/* 0x15c8: je     15d9 <snat_v6_nat+0xe55> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d9;
	}
x86_l_15ca:
	/* 0x15ca: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_15d1:
	/* 0x15d1: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_15d5:
	/* 0x15d5: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15d9:
	/* 0x15d9: shr    DWORD PTR [rsp+0x10],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 68719476744ULL);
x86_l_15de:
	/* 0x15de: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e1:
	/* 0x15e1: je     15f2 <snat_v6_nat+0xe6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f2;
	}
x86_l_15e3:
	/* 0x15e3: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_15e8:
	/* 0x15e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ea:
	/* 0x15ea: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15ec:
	/* 0x15ec: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_15f0:
	/* 0x15f0: jmp    1615 <snat_v6_nat+0xe91> */
	goto x86_l_1615;
x86_l_15f2:
	/* 0x15f2: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_15f7:
	/* 0x15f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f9:
	/* 0x15f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15fb:
	/* 0x15fb: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_15ff:
	/* 0x15ff: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1609:
	/* 0x1609: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1611:
	/* 0x1611: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1615:
	/* 0x1615: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1618:
	/* 0x1618: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_161b:
	/* 0x161b: mov    DWORD PTR [r15+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_161f:
	/* 0x161f: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1624:
	/* 0x1624: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1628:
	/* 0x1628: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_162c:
	/* 0x162c: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1630:
	/* 0x1630: mov    DWORD PTR [rsp+0x10],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1634:
	/* 0x1634: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1637:
	/* 0x1637: je     164a <snat_v6_nat+0xec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_164a;
	}
x86_l_1639:
	/* 0x1639: mov    rsi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1640:
	/* 0x1640: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1642:
	/* 0x1642: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1645:
	/* 0x1645: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1648:
	/* 0x1648: jmp    164f <snat_v6_nat+0xecb> */
	goto x86_l_164f;
x86_l_164a:
	/* 0x164a: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_164f:
	/* 0x164f: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1651:
	/* 0x1651: mov    edx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1655:
	/* 0x1655: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1657:
	/* 0x1657: mov    DWORD PTR [rsp+0x10],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_165b:
	/* 0x165b: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_165d:
	/* 0x165d: mov    rbx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1665:
	/* 0x1665: jb     166f <snat_v6_nat+0xeeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_166f;
	}
x86_l_1667:
	/* 0x1667: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1669:
	/* 0x1669: cmp    cl,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_166d:
	/* 0x166d: je     1684 <snat_v6_nat+0xf00> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1684;
	}
x86_l_166f:
	/* 0x166f: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1673:
	/* 0x1673: mov    BYTE PTR [r15+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1677:
	/* 0x1677: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167b:
	/* 0x167b: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1682:
	/* 0x1682: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1684:
	/* 0x1684: mov    DWORD PTR [r12+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1689:
	/* 0x1689: mov    BYTE PTR [r12+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_168f:
	/* 0x168f: movzx  r15d,BYTE PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1694:
	/* 0x1694: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1698:
	/* 0x1698: jne    16a3 <snat_v6_nat+0xf1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a3;
	}
x86_l_169a:
	/* 0x169a: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_16a1:
	/* 0x16a1: jmp    16aa <snat_v6_nat+0xf26> */
	goto x86_l_16aa;
x86_l_16a3:
	/* 0x16a3: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_16aa:
	/* 0x16aa: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_16b2:
	/* 0x16b2: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_16be:
	/* 0x16be: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_16ca:
	/* 0x16ca: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_16d6:
	/* 0x16d6: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_16df:
	/* 0x16df: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_16e8:
	/* 0x16e8: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_16f1:
	/* 0x16f1: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_16fa:
	/* 0x16fa: mov    rcx,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1701:
	/* 0x1701: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1704:
	/* 0x1704: je     1717 <snat_v6_nat+0xf93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1717;
	}
x86_l_1706:
	/* 0x1706: mov    rax,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_170d:
	/* 0x170d: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1711:
	/* 0x1711: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1715:
	/* 0x1715: jmp    171d <snat_v6_nat+0xf99> */
	goto x86_l_171d;
x86_l_1717:
	/* 0x1717: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_171d:
	/* 0x171d: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1721:
	/* 0x1721: jne    173f <snat_v6_nat+0xfbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_173f;
	}
x86_l_1723:
	/* 0x1723: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1726:
	/* 0x1726: je     1739 <snat_v6_nat+0xfb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1739;
	}
x86_l_1728:
	/* 0x1728: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_172f:
	/* 0x172f: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1733:
	/* 0x1733: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1737:
	/* 0x1737: jmp    173f <snat_v6_nat+0xfbb> */
	goto x86_l_173f;
x86_l_1739:
	/* 0x1739: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_173f:
	/* 0x173f: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1742:
	/* 0x1742: je     1753 <snat_v6_nat+0xfcf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1753;
	}
x86_l_1744:
	/* 0x1744: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1749:
	/* 0x1749: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174b:
	/* 0x174b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_174d:
	/* 0x174d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1751:
	/* 0x1751: jmp    1776 <snat_v6_nat+0xff2> */
	goto x86_l_1776;
x86_l_1753:
	/* 0x1753: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1758:
	/* 0x1758: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175a:
	/* 0x175a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_175c:
	/* 0x175c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1760:
	/* 0x1760: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_176a:
	/* 0x176a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_176d:
	/* 0x176d: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1772:
	/* 0x1772: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1776:
	/* 0x1776: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_177a:
	/* 0x177a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_177d:
	/* 0x177d: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1780:
	/* 0x1780: mov    DWORD PTR [rsp+0x80],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1788:
	/* 0x1788: movzx  edx,BYTE PTR [rsp+0x8a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 138ULL);
x86_l_1790:
	/* 0x1790: mov    esi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1797:
	/* 0x1797: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1799:
	/* 0x1799: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_17a0:
	/* 0x17a0: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a3:
	/* 0x17a3: je     17b6 <snat_v6_nat+0x1032> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17b6;
	}
x86_l_17a5:
	/* 0x17a5: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_17ac:
	/* 0x17ac: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17ae:
	/* 0x17ae: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_17b1:
	/* 0x17b1: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_17b4:
	/* 0x17b4: jmp    17bb <snat_v6_nat+0x1037> */
	goto x86_l_17bb;
x86_l_17b6:
	/* 0x17b6: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_17bb:
	/* 0x17bb: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_17c3:
	/* 0x17c3: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c8:
	/* 0x17c8: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17cd:
	/* 0x17cd: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17cf:
	/* 0x17cf: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_17d1:
	/* 0x17d1: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_17d3:
	/* 0x17d3: jb     17d9 <snat_v6_nat+0x1055> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_17d9;
	}
x86_l_17d5:
	/* 0x17d5: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_17d7:
	/* 0x17d7: je     17f0 <snat_v6_nat+0x106c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17f0;
	}
x86_l_17d9:
	/* 0x17d9: mov    BYTE PTR [rsp+0x8a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_17e0:
	/* 0x17e0: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17e7:
	/* 0x17e7: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_17ee:
	/* 0x17ee: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f0:
	/* 0x17f0: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_17f7:
	/* 0x17f7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17fa:
	/* 0x17fa: je     180d <snat_v6_nat+0x1089> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_180d;
	}
x86_l_17fc:
	/* 0x17fc: mov    QWORD PTR [rsp+0x70],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337153ULL);
x86_l_1805:
	/* 0x1805: mov    eax,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1808:
	/* 0x1808: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_180d:
	/* 0x180d: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1812:
	/* 0x1812: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1817:
	/* 0x1817: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_181f:
	/* 0x181f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1822:
	/* 0x1822: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1824:
	/* 0x1824: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1826:
	/* 0x1826: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1828:
	/* 0x1828: js     266f <snat_v6_nat+0x1eeb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9839ULL;
	}
x86_l_182e:
	/* 0x182e: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_1831:
	/* 0x1831: je     19ed <snat_v6_nat+0x1269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ed;
	}
x86_l_1837:
	/* 0x1837: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_183c:
	/* 0x183c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_183e:
	/* 0x183e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1840:
	/* 0x1840: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1842:
	/* 0x1842: mov    rcx,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_1849:
	/* 0x1849: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_184d:
	/* 0x184d: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1851:
	/* 0x1851: jbe    1857 <snat_v6_nat+0x10d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1857;
	}
x86_l_1853:
	/* 0x1853: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1857:
	/* 0x1857: mov    rcx,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_185e:
	/* 0x185e: mov    BYTE PTR [rcx+rax*1+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 158913789953ULL);
x86_l_1863:
	/* 0x1863: movzx  edx,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1869:
	/* 0x1869: mov    BYTE PTR [rcx+rax*1+0x24],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 36ULL);
x86_l_186d:
	/* 0x186d: mov    rdx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1871:
	/* 0x1871: mov    rsi,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1876:
	/* 0x1876: mov    QWORD PTR [rcx+rax*1+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_187b:
	/* 0x187b: mov    QWORD PTR [rcx+rax*1+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_1880:
	/* 0x1880: mov    rdx,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1884:
	/* 0x1884: mov    rsi,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1888:
	/* 0x1888: mov    QWORD PTR [rcx+rax*1],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_188c:
	/* 0x188c: mov    QWORD PTR [rcx+rax*1+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_1891:
	/* 0x1891: movzx  edx,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1897:
	/* 0x1897: mov    WORD PTR [rcx+rax*1+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 34ULL);
x86_l_189c:
	/* 0x189c: movzx  edx,WORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_18a0:
	/* 0x18a0: lea    r14,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_18a4:
	/* 0x18a4: mov    WORD PTR [rcx+rax*1+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_18a9:
	/* 0x18a9: mov    rax,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18ae:
	/* 0x18ae: cmp    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_18b2:
	/* 0x18b2: jne    19a4 <snat_v6_nat+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19a4;
	}
x86_l_18b8:
	/* 0x18b8: mov    rax,QWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18bd:
	/* 0x18bd: cmp    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_18c1:
	/* 0x18c1: jne    19a4 <snat_v6_nat+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19a4;
	}
x86_l_18c7:
	/* 0x18c7: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18cc:
	/* 0x18cc: cmp    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d0:
	/* 0x18d0: jne    19a4 <snat_v6_nat+0x1220> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19a4;
	}
x86_l_18d6:
	/* 0x18d6: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_18dd:
	/* 0x18dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18e2:
	/* 0x18e2: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_18e5:
	/* 0x18e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e7:
	/* 0x18e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18ea:
	/* 0x18ea: jne    25ce <snat_v6_nat+0x1e4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9678ULL;
	}
x86_l_18f0:
	/* 0x18f0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_18f5:
	/* 0x18f5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f7:
	/* 0x18f7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18f9:
	/* 0x18f9: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18fb:
	/* 0x18fb: mov    rcx,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_1902:
	/* 0x1902: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1906:
	/* 0x1906: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_190a:
	/* 0x190a: jbe    1910 <snat_v6_nat+0x118c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1910;
	}
x86_l_190c:
	/* 0x190c: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1910:
	/* 0x1910: mov    rcx,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_1917:
	/* 0x1917: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_1920:
	/* 0x1920: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_1929:
	/* 0x1929: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_1932:
	/* 0x1932: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_193b:
	/* 0x193b: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_1944:
	/* 0x1944: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_194d:
	/* 0x194d: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1955:
	/* 0x1955: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_195a:
	/* 0x195a: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_195f:
	/* 0x195f: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_1964:
	/* 0x1964: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_1969:
	/* 0x1969: movzx  edx,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_196f:
	/* 0x196f: mov    WORD PTR [rcx+rax*1+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 48ULL);
x86_l_1974:
	/* 0x1974: lea    r13,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1978:
	/* 0x1978: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_197d:
	/* 0x197d: mov    QWORD PTR [rcx+rax*1+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_1982:
	/* 0x1982: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1989:
	/* 0x1989: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_198c:
	/* 0x198c: je     258d <snat_v6_nat+0x1e09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9613ULL;
	}
x86_l_1992:
	/* 0x1992: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1997:
	/* 0x1997: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1999:
	/* 0x1999: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_199b:
	/* 0x199b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_199f:
	/* 0x199f: jmp    25b0 <snat_v6_nat+0x1e2c> */
	return 9648ULL;
x86_l_19a4:
	/* 0x19a4: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_19ab:
	/* 0x19ab: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_19b0:
	/* 0x19b0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_19b3:
	/* 0x19b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b5:
	/* 0x19b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19b7:
	/* 0x19b7: js     27b5 <snat_v6_nat+0x2031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10165ULL;
	}
x86_l_19bd:
	/* 0x19bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19c0:
	/* 0x19c0: je     27b5 <snat_v6_nat+0x2031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10165ULL;
	}
x86_l_19c6:
	/* 0x19c6: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_19cd:
	/* 0x19cd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19d2:
	/* 0x19d2: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_19d5:
	/* 0x19d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d7:
	/* 0x19d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19da:
	/* 0x19da: je     19ed <snat_v6_nat+0x1269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19ed;
	}
x86_l_19dc:
	/* 0x19dc: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_19e3:
	/* 0x19e3: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_19e8:
	/* 0x19e8: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_19eb:
	/* 0x19eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ed:
	/* 0x19ed: lea    r14,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19f2:
	/* 0x19f2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19f7:
	/* 0x19f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f9:
	/* 0x19f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_19fb:
	/* 0x19fb: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19fd:
	/* 0x19fd: mov    rcx,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_1a04:
	/* 0x1a04: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1a08:
	/* 0x1a08: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1a0c:
	/* 0x1a0c: jbe    1a12 <snat_v6_nat+0x128e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1a12;
	}
x86_l_1a0e:
	/* 0x1a0e: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a12:
	/* 0x1a12: mov    rcx,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_1a19:
	/* 0x1a19: lea    rbx,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1a29:
	/* 0x1a29: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1a35:
	/* 0x1a35: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1a41:
	/* 0x1a41: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1a53:
	/* 0x1a53: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1a5c:
	/* 0x1a5c: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1a65:
	/* 0x1a65: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_1a6e:
	/* 0x1a6e: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_1a77:
	/* 0x1a77: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_1a80:
	/* 0x1a80: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_1a89:
	/* 0x1a89: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_1a92:
	/* 0x1a92: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_1a9b:
	/* 0x1a9b: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    rdx,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1aa8:
	/* 0x1aa8: mov    rsi,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aad:
	/* 0x1aad: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    QWORD PTR [rsp+0x88],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1abd:
	/* 0x1abd: movzx  ebp,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1ac3:
	/* 0x1ac3: mov    WORD PTR [rsp+0x90],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1acb:
	/* 0x1acb: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ace:
	/* 0x1ace: mov    rsi,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad2:
	/* 0x1ad2: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_1ad7:
	/* 0x1ad7: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_1adc:
	/* 0x1adc: mov    BYTE PTR [rsp+0x3d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005057ULL);
	return 6881ULL;
}

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6881ULL: goto x86_l_1ae1;
	case 6887ULL: goto x86_l_1ae7;
	case 6891ULL: goto x86_l_1aeb;
	case 6895ULL: goto x86_l_1aef;
	case 6900ULL: goto x86_l_1af4;
	case 6905ULL: goto x86_l_1af9;
	case 6910ULL: goto x86_l_1afe;
	case 6913ULL: goto x86_l_1b01;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6933ULL: goto x86_l_1b15;
	case 6938ULL: goto x86_l_1b1a;
	case 6945ULL: goto x86_l_1b21;
	case 6951ULL: goto x86_l_1b27;
	case 6957ULL: goto x86_l_1b2d;
	case 6961ULL: goto x86_l_1b31;
	case 6965ULL: goto x86_l_1b35;
	case 6967ULL: goto x86_l_1b37;
	case 6970ULL: goto x86_l_1b3a;
	case 6972ULL: goto x86_l_1b3c;
	case 6975ULL: goto x86_l_1b3f;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6994ULL: goto x86_l_1b52;
	case 6997ULL: goto x86_l_1b55;
	case 7001ULL: goto x86_l_1b59;
	case 7004ULL: goto x86_l_1b5c;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7016ULL: goto x86_l_1b68;
	case 7021ULL: goto x86_l_1b6d;
	case 7028ULL: goto x86_l_1b74;
	case 7031ULL: goto x86_l_1b77;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7040ULL: goto x86_l_1b80;
	case 7042ULL: goto x86_l_1b82;
	case 7046ULL: goto x86_l_1b86;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7055ULL: goto x86_l_1b8f;
	case 7057ULL: goto x86_l_1b91;
	case 7061ULL: goto x86_l_1b95;
	case 7071ULL: goto x86_l_1b9f;
	case 7074ULL: goto x86_l_1ba2;
	case 7079ULL: goto x86_l_1ba7;
	case 7083ULL: goto x86_l_1bab;
	case 7088ULL: goto x86_l_1bb0;
	case 7095ULL: goto x86_l_1bb7;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7118ULL: goto x86_l_1bce;
	case 7124ULL: goto x86_l_1bd4;
	case 7129ULL: goto x86_l_1bd9;
	case 7132ULL: goto x86_l_1bdc;
	case 7134ULL: goto x86_l_1bde;
	case 7140ULL: goto x86_l_1be4;
	case 7146ULL: goto x86_l_1bea;
	case 7152ULL: goto x86_l_1bf0;
	case 7157ULL: goto x86_l_1bf5;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7164ULL: goto x86_l_1bfc;
	case 7167ULL: goto x86_l_1bff;
	case 7170ULL: goto x86_l_1c02;
	case 7174ULL: goto x86_l_1c06;
	case 7178ULL: goto x86_l_1c0a;
	case 7181ULL: goto x86_l_1c0d;
	case 7183ULL: goto x86_l_1c0f;
	case 7191ULL: goto x86_l_1c17;
	case 7198ULL: goto x86_l_1c1e;
	case 7203ULL: goto x86_l_1c23;
	case 7208ULL: goto x86_l_1c28;
	case 7213ULL: goto x86_l_1c2d;
	case 7216ULL: goto x86_l_1c30;
	case 7218ULL: goto x86_l_1c32;
	case 7224ULL: goto x86_l_1c38;
	case 7230ULL: goto x86_l_1c3e;
	case 7236ULL: goto x86_l_1c44;
	case 7238ULL: goto x86_l_1c46;
	case 7240ULL: goto x86_l_1c48;
	case 7243ULL: goto x86_l_1c4b;
	case 7247ULL: goto x86_l_1c4f;
	case 7250ULL: goto x86_l_1c52;
	case 7253ULL: goto x86_l_1c55;
	case 7255ULL: goto x86_l_1c57;
	case 7262ULL: goto x86_l_1c5e;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7279ULL: goto x86_l_1c6f;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7293ULL: goto x86_l_1c7d;
	case 7295ULL: goto x86_l_1c7f;
	case 7301ULL: goto x86_l_1c85;
	case 7307ULL: goto x86_l_1c8b;
	case 7313ULL: goto x86_l_1c91;
	case 7315ULL: goto x86_l_1c93;
	case 7317ULL: goto x86_l_1c95;
	case 7319ULL: goto x86_l_1c97;
	case 7322ULL: goto x86_l_1c9a;
	case 7325ULL: goto x86_l_1c9d;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7337ULL: goto x86_l_1ca9;
	case 7344ULL: goto x86_l_1cb0;
	case 7349ULL: goto x86_l_1cb5;
	case 7354ULL: goto x86_l_1cba;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7364ULL: goto x86_l_1cc4;
	case 7370ULL: goto x86_l_1cca;
	case 7376ULL: goto x86_l_1cd0;
	case 7382ULL: goto x86_l_1cd6;
	case 7384ULL: goto x86_l_1cd8;
	case 7386ULL: goto x86_l_1cda;
	case 7388ULL: goto x86_l_1cdc;
	case 7391ULL: goto x86_l_1cdf;
	case 7394ULL: goto x86_l_1ce2;
	case 7397ULL: goto x86_l_1ce5;
	case 7399ULL: goto x86_l_1ce7;
	case 7406ULL: goto x86_l_1cee;
	case 7413ULL: goto x86_l_1cf5;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7429ULL: goto x86_l_1d05;
	case 7434ULL: goto x86_l_1d0a;
	case 7437ULL: goto x86_l_1d0d;
	case 7439ULL: goto x86_l_1d0f;
	case 7445ULL: goto x86_l_1d15;
	case 7451ULL: goto x86_l_1d1b;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7461ULL: goto x86_l_1d25;
	case 7463ULL: goto x86_l_1d27;
	case 7466ULL: goto x86_l_1d2a;
	case 7469ULL: goto x86_l_1d2d;
	case 7472ULL: goto x86_l_1d30;
	case 7474ULL: goto x86_l_1d32;
	case 7481ULL: goto x86_l_1d39;
	case 7488ULL: goto x86_l_1d40;
	case 7493ULL: goto x86_l_1d45;
	case 7498ULL: goto x86_l_1d4a;
	case 7503ULL: goto x86_l_1d4f;
	case 7506ULL: goto x86_l_1d52;
	case 7508ULL: goto x86_l_1d54;
	case 7514ULL: goto x86_l_1d5a;
	case 7520ULL: goto x86_l_1d60;
	case 7526ULL: goto x86_l_1d66;
	case 7528ULL: goto x86_l_1d68;
	case 7530ULL: goto x86_l_1d6a;
	case 7532ULL: goto x86_l_1d6c;
	case 7535ULL: goto x86_l_1d6f;
	case 7538ULL: goto x86_l_1d72;
	case 7541ULL: goto x86_l_1d75;
	case 7543ULL: goto x86_l_1d77;
	case 7550ULL: goto x86_l_1d7e;
	case 7557ULL: goto x86_l_1d85;
	case 7562ULL: goto x86_l_1d8a;
	case 7567ULL: goto x86_l_1d8f;
	case 7573ULL: goto x86_l_1d95;
	case 7578ULL: goto x86_l_1d9a;
	case 7581ULL: goto x86_l_1d9d;
	case 7583ULL: goto x86_l_1d9f;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7601ULL: goto x86_l_1db1;
	case 7603ULL: goto x86_l_1db3;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7610ULL: goto x86_l_1dba;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7618ULL: goto x86_l_1dc2;
	case 7625ULL: goto x86_l_1dc9;
	case 7632ULL: goto x86_l_1dd0;
	case 7637ULL: goto x86_l_1dd5;
	case 7642ULL: goto x86_l_1dda;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7658ULL: goto x86_l_1dea;
	case 7664ULL: goto x86_l_1df0;
	case 7670ULL: goto x86_l_1df6;
	case 7672ULL: goto x86_l_1df8;
	case 7674ULL: goto x86_l_1dfa;
	case 7676ULL: goto x86_l_1dfc;
	case 7679ULL: goto x86_l_1dff;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7687ULL: goto x86_l_1e07;
	case 7694ULL: goto x86_l_1e0e;
	case 7701ULL: goto x86_l_1e15;
	case 7706ULL: goto x86_l_1e1a;
	case 7711ULL: goto x86_l_1e1f;
	case 7717ULL: goto x86_l_1e25;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7727ULL: goto x86_l_1e2f;
	case 7733ULL: goto x86_l_1e35;
	case 7739ULL: goto x86_l_1e3b;
	case 7745ULL: goto x86_l_1e41;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7751ULL: goto x86_l_1e47;
	case 7754ULL: goto x86_l_1e4a;
	case 7757ULL: goto x86_l_1e4d;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7769ULL: goto x86_l_1e59;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7794ULL: goto x86_l_1e72;
	case 7796ULL: goto x86_l_1e74;
	case 7802ULL: goto x86_l_1e7a;
	case 7808ULL: goto x86_l_1e80;
	case 7814ULL: goto x86_l_1e86;
	case 7816ULL: goto x86_l_1e88;
	case 7818ULL: goto x86_l_1e8a;
	case 7820ULL: goto x86_l_1e8c;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7829ULL: goto x86_l_1e95;
	case 7831ULL: goto x86_l_1e97;
	case 7838ULL: goto x86_l_1e9e;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7855ULL: goto x86_l_1eaf;
	case 7861ULL: goto x86_l_1eb5;
	case 7866ULL: goto x86_l_1eba;
	case 7869ULL: goto x86_l_1ebd;
	case 7871ULL: goto x86_l_1ebf;
	case 7877ULL: goto x86_l_1ec5;
	case 7883ULL: goto x86_l_1ecb;
	case 7889ULL: goto x86_l_1ed1;
	case 7891ULL: goto x86_l_1ed3;
	case 7893ULL: goto x86_l_1ed5;
	case 7895ULL: goto x86_l_1ed7;
	case 7898ULL: goto x86_l_1eda;
	case 7901ULL: goto x86_l_1edd;
	case 7904ULL: goto x86_l_1ee0;
	case 7906ULL: goto x86_l_1ee2;
	case 7913ULL: goto x86_l_1ee9;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7938ULL: goto x86_l_1f02;
	case 7940ULL: goto x86_l_1f04;
	case 7946ULL: goto x86_l_1f0a;
	case 7952ULL: goto x86_l_1f10;
	case 7958ULL: goto x86_l_1f16;
	case 7960ULL: goto x86_l_1f18;
	case 7962ULL: goto x86_l_1f1a;
	case 7964ULL: goto x86_l_1f1c;
	case 7967ULL: goto x86_l_1f1f;
	case 7970ULL: goto x86_l_1f22;
	case 7973ULL: goto x86_l_1f25;
	case 7975ULL: goto x86_l_1f27;
	case 7982ULL: goto x86_l_1f2e;
	case 7989ULL: goto x86_l_1f35;
	case 7994ULL: goto x86_l_1f3a;
	case 7999ULL: goto x86_l_1f3f;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8013ULL: goto x86_l_1f4d;
	case 8015ULL: goto x86_l_1f4f;
	case 8021ULL: goto x86_l_1f55;
	case 8027ULL: goto x86_l_1f5b;
	case 8033ULL: goto x86_l_1f61;
	case 8035ULL: goto x86_l_1f63;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8045ULL: goto x86_l_1f6d;
	case 8048ULL: goto x86_l_1f70;
	case 8050ULL: goto x86_l_1f72;
	case 8057ULL: goto x86_l_1f79;
	case 8064ULL: goto x86_l_1f80;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8082ULL: goto x86_l_1f92;
	case 8084ULL: goto x86_l_1f94;
	case 8090ULL: goto x86_l_1f9a;
	case 8096ULL: goto x86_l_1fa0;
	case 8102ULL: goto x86_l_1fa6;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8108ULL: goto x86_l_1fac;
	case 8111ULL: goto x86_l_1faf;
	case 8114ULL: goto x86_l_1fb2;
	case 8117ULL: goto x86_l_1fb5;
	case 8119ULL: goto x86_l_1fb7;
	case 8126ULL: goto x86_l_1fbe;
	case 8133ULL: goto x86_l_1fc5;
	case 8138ULL: goto x86_l_1fca;
	case 8143ULL: goto x86_l_1fcf;
	case 8149ULL: goto x86_l_1fd5;
	case 8154ULL: goto x86_l_1fda;
	case 8157ULL: goto x86_l_1fdd;
	case 8159ULL: goto x86_l_1fdf;
	case 8165ULL: goto x86_l_1fe5;
	case 8171ULL: goto x86_l_1feb;
	case 8177ULL: goto x86_l_1ff1;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8189ULL: goto x86_l_1ffd;
	case 8192ULL: goto x86_l_2000;
	case 8194ULL: goto x86_l_2002;
	case 8201ULL: goto x86_l_2009;
	case 8208ULL: goto x86_l_2010;
	case 8213ULL: goto x86_l_2015;
	case 8218ULL: goto x86_l_201a;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8234ULL: goto x86_l_202a;
	case 8240ULL: goto x86_l_2030;
	case 8246ULL: goto x86_l_2036;
	case 8248ULL: goto x86_l_2038;
	case 8250ULL: goto x86_l_203a;
	case 8252ULL: goto x86_l_203c;
	case 8255ULL: goto x86_l_203f;
	case 8258ULL: goto x86_l_2042;
	case 8261ULL: goto x86_l_2045;
	case 8263ULL: goto x86_l_2047;
	case 8270ULL: goto x86_l_204e;
	case 8277ULL: goto x86_l_2055;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8293ULL: goto x86_l_2065;
	case 8298ULL: goto x86_l_206a;
	case 8301ULL: goto x86_l_206d;
	case 8303ULL: goto x86_l_206f;
	case 8309ULL: goto x86_l_2075;
	case 8315ULL: goto x86_l_207b;
	case 8321ULL: goto x86_l_2081;
	case 8323ULL: goto x86_l_2083;
	case 8325ULL: goto x86_l_2085;
	case 8327ULL: goto x86_l_2087;
	case 8331ULL: goto x86_l_208b;
	case 8335ULL: goto x86_l_208f;
	case 8339ULL: goto x86_l_2093;
	case 8342ULL: goto x86_l_2096;
	case 8350ULL: goto x86_l_209e;
	case 8357ULL: goto x86_l_20a5;
	case 8362ULL: goto x86_l_20aa;
	case 8367ULL: goto x86_l_20af;
	case 8372ULL: goto x86_l_20b4;
	case 8375ULL: goto x86_l_20b7;
	case 8377ULL: goto x86_l_20b9;
	case 8383ULL: goto x86_l_20bf;
	case 8389ULL: goto x86_l_20c5;
	case 8395ULL: goto x86_l_20cb;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8402ULL: goto x86_l_20d2;
	case 8406ULL: goto x86_l_20d6;
	case 8410ULL: goto x86_l_20da;
	case 8414ULL: goto x86_l_20de;
	case 8417ULL: goto x86_l_20e1;
	case 8425ULL: goto x86_l_20e9;
	case 8432ULL: goto x86_l_20f0;
	case 8437ULL: goto x86_l_20f5;
	case 8442ULL: goto x86_l_20fa;
	case 8448ULL: goto x86_l_2100;
	case 8453ULL: goto x86_l_2105;
	case 8456ULL: goto x86_l_2108;
	case 8458ULL: goto x86_l_210a;
	case 8464ULL: goto x86_l_2110;
	case 8470ULL: goto x86_l_2116;
	case 8476ULL: goto x86_l_211c;
	case 8478ULL: goto x86_l_211e;
	case 8480ULL: goto x86_l_2120;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1ae1:
	/* 0x1ae1: movzx  eax,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    BYTE PTR [rsp+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aef:
	/* 0x1aef: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af4:
	/* 0x1af4: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1af9:
	/* 0x1af9: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1afe:
	/* 0x1afe: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b01:
	/* 0x1b01: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b05:
	/* 0x1b05: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b0a:
	/* 0x1b0a: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b0f:
	/* 0x1b0f: movzx  eax,WORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1b15:
	/* 0x1b15: mov    WORD PTR [rsp+0x3a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1b1a:
	/* 0x1b1a: mov    WORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b21:
	/* 0x1b21: movzx  r14d,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1b27:
	/* 0x1b27: movzx  eax,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1b2d:
	/* 0x1b2d: rol    bp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_1b31:
	/* 0x1b31: cmp    bp,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_R14, X86_WIDTH_16);
x86_l_1b35:
	/* 0x1b35: jb     1b3c <snat_v6_nat+0x13b8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1b3c;
	}
x86_l_1b37:
	/* 0x1b37: cmp    bp,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_16);
x86_l_1b3a:
	/* 0x1b3a: jbe    1b5f <snat_v6_nat+0x13db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1b5f;
	}
x86_l_1b3c:
	/* 0x1b3c: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1b3f:
	/* 0x1b3f: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b43:
	/* 0x1b43: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1b48:
	/* 0x1b48: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b4a:
	/* 0x1b4a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b4c:
	/* 0x1b4c: sub    r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b4f:
	/* 0x1b4f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1b52:
	/* 0x1b52: movzx  ebp,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b55:
	/* 0x1b55: imul   ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1b59:
	/* 0x1b59: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1b5c:
	/* 0x1b5c: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b5f:
	/* 0x1b5f: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b64:
	/* 0x1b64: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b68:
	/* 0x1b68: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    rax,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1b74:
	/* 0x1b74: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b77:
	/* 0x1b77: je     1b88 <snat_v6_nat+0x1404> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b88;
	}
x86_l_1b79:
	/* 0x1b79: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1b7e:
	/* 0x1b7e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b80:
	/* 0x1b80: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b82:
	/* 0x1b82: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1b86:
	/* 0x1b86: jmp    1bab <snat_v6_nat+0x1427> */
	goto x86_l_1bab;
x86_l_1b88:
	/* 0x1b88: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b8d:
	/* 0x1b8d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b8f:
	/* 0x1b8f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b91:
	/* 0x1b91: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1b95:
	/* 0x1b95: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ba2:
	/* 0x1ba2: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ba7:
	/* 0x1ba7: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1bab:
	/* 0x1bab: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bb0:
	/* 0x1bb0: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1bb7:
	/* 0x1bb7: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1bbe:
	/* 0x1bbe: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bc3:
	/* 0x1bc3: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1bce:
	/* 0x1bce: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1bd4:
	/* 0x1bd4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1bd9:
	/* 0x1bd9: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_1bdc:
	/* 0x1bdc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bde:
	/* 0x1bde: je     2535 <snat_v6_nat+0x1db1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9525ULL;
	}
x86_l_1be4:
	/* 0x1be4: movzx  ebp,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1bea:
	/* 0x1bea: movzx  r15d,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1bf5:
	/* 0x1bf5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf7:
	/* 0x1bf7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bf9:
	/* 0x1bf9: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1bfc:
	/* 0x1bfc: sub    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1bff:
	/* 0x1bff: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1c02:
	/* 0x1c02: imul   r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1c06:
	/* 0x1c06: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1c0a:
	/* 0x1c0a: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c0d:
	/* 0x1c0d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c0f:
	/* 0x1c0f: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1c17:
	/* 0x1c17: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1c1e:
	/* 0x1c1e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c23:
	/* 0x1c23: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c28:
	/* 0x1c28: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c2d:
	/* 0x1c2d: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_1c30:
	/* 0x1c30: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c32:
	/* 0x1c32: je     26f6 <snat_v6_nat+0x1f72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9974ULL;
	}
x86_l_1c38:
	/* 0x1c38: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1c3e:
	/* 0x1c3e: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1c44:
	/* 0x1c44: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c46:
	/* 0x1c46: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1c48:
	/* 0x1c48: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1c4b:
	/* 0x1c4b: movzx  ebp,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1c4f:
	/* 0x1c4f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1c52:
	/* 0x1c52: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1c55:
	/* 0x1c55: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c57:
	/* 0x1c57: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1c5e:
	/* 0x1c5e: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1c65:
	/* 0x1c65: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c6a:
	/* 0x1c6a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c6f:
	/* 0x1c6f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1c75:
	/* 0x1c75: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c7a:
	/* 0x1c7a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1c7d:
	/* 0x1c7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c7f:
	/* 0x1c7f: je     253f <snat_v6_nat+0x1dbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9535ULL;
	}
x86_l_1c85:
	/* 0x1c85: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1c8b:
	/* 0x1c8b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1c91:
	/* 0x1c91: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1c93:
	/* 0x1c93: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1c95:
	/* 0x1c95: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1c97:
	/* 0x1c97: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1c9a:
	/* 0x1c9a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1c9d:
	/* 0x1c9d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1ca0:
	/* 0x1ca0: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ca2:
	/* 0x1ca2: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1ca9:
	/* 0x1ca9: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1cb0:
	/* 0x1cb0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cb5:
	/* 0x1cb5: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cba:
	/* 0x1cba: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1cbf:
	/* 0x1cbf: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1cc2:
	/* 0x1cc2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cc4:
	/* 0x1cc4: je     254c <snat_v6_nat+0x1dc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9548ULL;
	}
x86_l_1cca:
	/* 0x1cca: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1cd0:
	/* 0x1cd0: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1cd6:
	/* 0x1cd6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1cd8:
	/* 0x1cd8: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1cda:
	/* 0x1cda: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1cdc:
	/* 0x1cdc: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1cdf:
	/* 0x1cdf: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1ce2:
	/* 0x1ce2: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1ce5:
	/* 0x1ce5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ce7:
	/* 0x1ce7: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1cee:
	/* 0x1cee: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1cf5:
	/* 0x1cf5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cfa:
	/* 0x1cfa: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cff:
	/* 0x1cff: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1d05:
	/* 0x1d05: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d0a:
	/* 0x1d0a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1d0d:
	/* 0x1d0d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d0f:
	/* 0x1d0f: je     2559 <snat_v6_nat+0x1dd5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9561ULL;
	}
x86_l_1d15:
	/* 0x1d15: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1d1b:
	/* 0x1d1b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1d21:
	/* 0x1d21: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1d23:
	/* 0x1d23: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d25:
	/* 0x1d25: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d27:
	/* 0x1d27: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d2a:
	/* 0x1d2a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1d2d:
	/* 0x1d2d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d30:
	/* 0x1d30: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d32:
	/* 0x1d32: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1d39:
	/* 0x1d39: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1d40:
	/* 0x1d40: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d45:
	/* 0x1d45: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d4a:
	/* 0x1d4a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d4f:
	/* 0x1d4f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1d52:
	/* 0x1d52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d54:
	/* 0x1d54: je     2566 <snat_v6_nat+0x1de2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9574ULL;
	}
x86_l_1d5a:
	/* 0x1d5a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1d60:
	/* 0x1d60: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1d66:
	/* 0x1d66: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1d68:
	/* 0x1d68: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d6a:
	/* 0x1d6a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1d6c:
	/* 0x1d6c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d6f:
	/* 0x1d6f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1d72:
	/* 0x1d72: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d75:
	/* 0x1d75: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d77:
	/* 0x1d77: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1d7e:
	/* 0x1d7e: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1d85:
	/* 0x1d85: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d8a:
	/* 0x1d8a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d8f:
	/* 0x1d8f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1d95:
	/* 0x1d95: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1d9a:
	/* 0x1d9a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1d9d:
	/* 0x1d9d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d9f:
	/* 0x1d9f: je     2573 <snat_v6_nat+0x1def> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9587ULL;
	}
x86_l_1da5:
	/* 0x1da5: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1dab:
	/* 0x1dab: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1db1:
	/* 0x1db1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1db3:
	/* 0x1db3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1db5:
	/* 0x1db5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1db7:
	/* 0x1db7: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1dba:
	/* 0x1dba: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1dbd:
	/* 0x1dbd: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1dc0:
	/* 0x1dc0: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1dc2:
	/* 0x1dc2: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1dd0:
	/* 0x1dd0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dd5:
	/* 0x1dd5: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1dda:
	/* 0x1dda: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ddf:
	/* 0x1ddf: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1de2:
	/* 0x1de2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1de4:
	/* 0x1de4: je     2580 <snat_v6_nat+0x1dfc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9600ULL;
	}
x86_l_1dea:
	/* 0x1dea: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1df0:
	/* 0x1df0: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1df6:
	/* 0x1df6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1df8:
	/* 0x1df8: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1dfa:
	/* 0x1dfa: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1dfc:
	/* 0x1dfc: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1dff:
	/* 0x1dff: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1e02:
	/* 0x1e02: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1e05:
	/* 0x1e05: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e07:
	/* 0x1e07: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1e15:
	/* 0x1e15: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e1a:
	/* 0x1e1a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e1f:
	/* 0x1e1f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1e25:
	/* 0x1e25: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1e2a:
	/* 0x1e2a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1e2d:
	/* 0x1e2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e2f:
	/* 0x1e2f: je     25ef <snat_v6_nat+0x1e6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9711ULL;
	}
x86_l_1e35:
	/* 0x1e35: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1e3b:
	/* 0x1e3b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1e41:
	/* 0x1e41: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e43:
	/* 0x1e43: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1e45:
	/* 0x1e45: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1e47:
	/* 0x1e47: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e4a:
	/* 0x1e4a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1e4d:
	/* 0x1e4d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1e50:
	/* 0x1e50: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e52:
	/* 0x1e52: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1e59:
	/* 0x1e59: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1e60:
	/* 0x1e60: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e65:
	/* 0x1e65: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1e6f:
	/* 0x1e6f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1e72:
	/* 0x1e72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e74:
	/* 0x1e74: je     25fc <snat_v6_nat+0x1e78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9724ULL;
	}
x86_l_1e7a:
	/* 0x1e7a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1e80:
	/* 0x1e80: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1e86:
	/* 0x1e86: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e88:
	/* 0x1e88: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1e8a:
	/* 0x1e8a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1e8c:
	/* 0x1e8c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e8f:
	/* 0x1e8f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1e92:
	/* 0x1e92: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1e95:
	/* 0x1e95: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e97:
	/* 0x1e97: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1e9e:
	/* 0x1e9e: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1ea5:
	/* 0x1ea5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1eaa:
	/* 0x1eaa: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1eaf:
	/* 0x1eaf: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1eb5:
	/* 0x1eb5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1eba:
	/* 0x1eba: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1ebd:
	/* 0x1ebd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ebf:
	/* 0x1ebf: je     2609 <snat_v6_nat+0x1e85> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9737ULL;
	}
x86_l_1ec5:
	/* 0x1ec5: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1ecb:
	/* 0x1ecb: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1ed1:
	/* 0x1ed1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ed3:
	/* 0x1ed3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ed5:
	/* 0x1ed5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ed7:
	/* 0x1ed7: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1eda:
	/* 0x1eda: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1edd:
	/* 0x1edd: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1ee0:
	/* 0x1ee0: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ee2:
	/* 0x1ee2: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1ef0:
	/* 0x1ef0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ef5:
	/* 0x1ef5: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1efa:
	/* 0x1efa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1eff:
	/* 0x1eff: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1f02:
	/* 0x1f02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f04:
	/* 0x1f04: je     2616 <snat_v6_nat+0x1e92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9750ULL;
	}
x86_l_1f0a:
	/* 0x1f0a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1f10:
	/* 0x1f10: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1f16:
	/* 0x1f16: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f18:
	/* 0x1f18: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1f1a:
	/* 0x1f1a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1f1c:
	/* 0x1f1c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f1f:
	/* 0x1f1f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1f22:
	/* 0x1f22: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1f25:
	/* 0x1f25: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f27:
	/* 0x1f27: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1f2e:
	/* 0x1f2e: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1f35:
	/* 0x1f35: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f3a:
	/* 0x1f3a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f3f:
	/* 0x1f3f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1f45:
	/* 0x1f45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f4a:
	/* 0x1f4a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1f4d:
	/* 0x1f4d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f4f:
	/* 0x1f4f: je     2623 <snat_v6_nat+0x1e9f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9763ULL;
	}
x86_l_1f55:
	/* 0x1f55: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1f5b:
	/* 0x1f5b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1f61:
	/* 0x1f61: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f63:
	/* 0x1f63: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1f65:
	/* 0x1f65: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1f67:
	/* 0x1f67: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f6a:
	/* 0x1f6a: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1f6d:
	/* 0x1f6d: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1f70:
	/* 0x1f70: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f72:
	/* 0x1f72: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1f79:
	/* 0x1f79: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1f80:
	/* 0x1f80: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f85:
	/* 0x1f85: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f8a:
	/* 0x1f8a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f8f:
	/* 0x1f8f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1f92:
	/* 0x1f92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f94:
	/* 0x1f94: je     2630 <snat_v6_nat+0x1eac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9776ULL;
	}
x86_l_1f9a:
	/* 0x1f9a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1fa0:
	/* 0x1fa0: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1fa6:
	/* 0x1fa6: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fa8:
	/* 0x1fa8: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1faa:
	/* 0x1faa: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1fac:
	/* 0x1fac: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1faf:
	/* 0x1faf: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1fb2:
	/* 0x1fb2: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1fb5:
	/* 0x1fb5: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fb7:
	/* 0x1fb7: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1fbe:
	/* 0x1fbe: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1fc5:
	/* 0x1fc5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fca:
	/* 0x1fca: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1fd5:
	/* 0x1fd5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1fda:
	/* 0x1fda: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1fdd:
	/* 0x1fdd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fdf:
	/* 0x1fdf: je     263d <snat_v6_nat+0x1eb9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9789ULL;
	}
x86_l_1fe5:
	/* 0x1fe5: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1feb:
	/* 0x1feb: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_1ff1:
	/* 0x1ff1: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ff3:
	/* 0x1ff3: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ff5:
	/* 0x1ff5: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1ff7:
	/* 0x1ff7: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ffa:
	/* 0x1ffa: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1ffd:
	/* 0x1ffd: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2000:
	/* 0x2000: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2002:
	/* 0x2002: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2009:
	/* 0x2009: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2010:
	/* 0x2010: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2015:
	/* 0x2015: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_201a:
	/* 0x201a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_201f:
	/* 0x201f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2022:
	/* 0x2022: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2024:
	/* 0x2024: je     264a <snat_v6_nat+0x1ec6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9802ULL;
	}
x86_l_202a:
	/* 0x202a: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2030:
	/* 0x2030: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2036:
	/* 0x2036: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2038:
	/* 0x2038: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_203a:
	/* 0x203a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_203c:
	/* 0x203c: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_203f:
	/* 0x203f: imul   ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2042:
	/* 0x2042: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2045:
	/* 0x2045: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2047:
	/* 0x2047: movbe  WORD PTR [rsp+0x38],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_204e:
	/* 0x204e: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2055:
	/* 0x2055: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_205a:
	/* 0x205a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_205f:
	/* 0x205f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2065:
	/* 0x2065: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_206a:
	/* 0x206a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_206d:
	/* 0x206d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_206f:
	/* 0x206f: je     2657 <snat_v6_nat+0x1ed3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9815ULL;
	}
x86_l_2075:
	/* 0x2075: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_207b:
	/* 0x207b: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2081:
	/* 0x2081: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2083:
	/* 0x2083: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2085:
	/* 0x2085: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2087:
	/* 0x2087: movzx  r15d,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_208b:
	/* 0x208b: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_208f:
	/* 0x208f: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2093:
	/* 0x2093: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2096:
	/* 0x2096: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_209e:
	/* 0x209e: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_20a5:
	/* 0x20a5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20aa:
	/* 0x20aa: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_20af:
	/* 0x20af: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_20b4:
	/* 0x20b4: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_20b7:
	/* 0x20b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20b9:
	/* 0x20b9: je     2664 <snat_v6_nat+0x1ee0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9828ULL;
	}
x86_l_20bf:
	/* 0x20bf: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_20c5:
	/* 0x20c5: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_20cb:
	/* 0x20cb: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20cd:
	/* 0x20cd: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_20cf:
	/* 0x20cf: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_20d2:
	/* 0x20d2: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_20d6:
	/* 0x20d6: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_20da:
	/* 0x20da: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_20de:
	/* 0x20de: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20e1:
	/* 0x20e1: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_20e9:
	/* 0x20e9: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_20f0:
	/* 0x20f0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20f5:
	/* 0x20f5: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_20fa:
	/* 0x20fa: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2100:
	/* 0x2100: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2105:
	/* 0x2105: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2108:
	/* 0x2108: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_210a:
	/* 0x210a: je     2685 <snat_v6_nat+0x1f01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9861ULL;
	}
x86_l_2110:
	/* 0x2110: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2116:
	/* 0x2116: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_211c:
	/* 0x211c: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_211e:
	/* 0x211e: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2120:
	/* 0x2120: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
	return 8483ULL;
}

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8483ULL: goto x86_l_2123;
	case 8487ULL: goto x86_l_2127;
	case 8491ULL: goto x86_l_212b;
	case 8495ULL: goto x86_l_212f;
	case 8498ULL: goto x86_l_2132;
	case 8506ULL: goto x86_l_213a;
	case 8513ULL: goto x86_l_2141;
	case 8518ULL: goto x86_l_2146;
	case 8523ULL: goto x86_l_214b;
	case 8528ULL: goto x86_l_2150;
	case 8531ULL: goto x86_l_2153;
	case 8533ULL: goto x86_l_2155;
	case 8539ULL: goto x86_l_215b;
	case 8545ULL: goto x86_l_2161;
	case 8551ULL: goto x86_l_2167;
	case 8553ULL: goto x86_l_2169;
	case 8555ULL: goto x86_l_216b;
	case 8558ULL: goto x86_l_216e;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8570ULL: goto x86_l_217a;
	case 8573ULL: goto x86_l_217d;
	case 8581ULL: goto x86_l_2185;
	case 8588ULL: goto x86_l_218c;
	case 8593ULL: goto x86_l_2191;
	case 8598ULL: goto x86_l_2196;
	case 8604ULL: goto x86_l_219c;
	case 8609ULL: goto x86_l_21a1;
	case 8612ULL: goto x86_l_21a4;
	case 8614ULL: goto x86_l_21a6;
	case 8620ULL: goto x86_l_21ac;
	case 8626ULL: goto x86_l_21b2;
	case 8632ULL: goto x86_l_21b8;
	case 8634ULL: goto x86_l_21ba;
	case 8636ULL: goto x86_l_21bc;
	case 8639ULL: goto x86_l_21bf;
	case 8643ULL: goto x86_l_21c3;
	case 8647ULL: goto x86_l_21c7;
	case 8651ULL: goto x86_l_21cb;
	case 8654ULL: goto x86_l_21ce;
	case 8662ULL: goto x86_l_21d6;
	case 8669ULL: goto x86_l_21dd;
	case 8674ULL: goto x86_l_21e2;
	case 8679ULL: goto x86_l_21e7;
	case 8684ULL: goto x86_l_21ec;
	case 8687ULL: goto x86_l_21ef;
	case 8689ULL: goto x86_l_21f1;
	case 8695ULL: goto x86_l_21f7;
	case 8701ULL: goto x86_l_21fd;
	case 8707ULL: goto x86_l_2203;
	case 8709ULL: goto x86_l_2205;
	case 8711ULL: goto x86_l_2207;
	case 8714ULL: goto x86_l_220a;
	case 8718ULL: goto x86_l_220e;
	case 8722ULL: goto x86_l_2212;
	case 8726ULL: goto x86_l_2216;
	case 8729ULL: goto x86_l_2219;
	case 8737ULL: goto x86_l_2221;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8754ULL: goto x86_l_2232;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8768ULL: goto x86_l_2240;
	case 8770ULL: goto x86_l_2242;
	case 8776ULL: goto x86_l_2248;
	case 8782ULL: goto x86_l_224e;
	case 8788ULL: goto x86_l_2254;
	case 8790ULL: goto x86_l_2256;
	case 8792ULL: goto x86_l_2258;
	case 8795ULL: goto x86_l_225b;
	case 8799ULL: goto x86_l_225f;
	case 8803ULL: goto x86_l_2263;
	case 8807ULL: goto x86_l_2267;
	case 8810ULL: goto x86_l_226a;
	case 8818ULL: goto x86_l_2272;
	case 8825ULL: goto x86_l_2279;
	case 8830ULL: goto x86_l_227e;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8843ULL: goto x86_l_228b;
	case 8845ULL: goto x86_l_228d;
	case 8851ULL: goto x86_l_2293;
	case 8857ULL: goto x86_l_2299;
	case 8863ULL: goto x86_l_229f;
	case 8865ULL: goto x86_l_22a1;
	case 8867ULL: goto x86_l_22a3;
	case 8870ULL: goto x86_l_22a6;
	case 8874ULL: goto x86_l_22aa;
	case 8878ULL: goto x86_l_22ae;
	case 8882ULL: goto x86_l_22b2;
	case 8885ULL: goto x86_l_22b5;
	case 8893ULL: goto x86_l_22bd;
	case 8900ULL: goto x86_l_22c4;
	case 8905ULL: goto x86_l_22c9;
	case 8910ULL: goto x86_l_22ce;
	case 8916ULL: goto x86_l_22d4;
	case 8921ULL: goto x86_l_22d9;
	case 8924ULL: goto x86_l_22dc;
	case 8926ULL: goto x86_l_22de;
	case 8932ULL: goto x86_l_22e4;
	case 8938ULL: goto x86_l_22ea;
	case 8944ULL: goto x86_l_22f0;
	case 8946ULL: goto x86_l_22f2;
	case 8948ULL: goto x86_l_22f4;
	case 8951ULL: goto x86_l_22f7;
	case 8955ULL: goto x86_l_22fb;
	case 8959ULL: goto x86_l_22ff;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8974ULL: goto x86_l_230e;
	case 8981ULL: goto x86_l_2315;
	case 8986ULL: goto x86_l_231a;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 8999ULL: goto x86_l_2327;
	case 9001ULL: goto x86_l_2329;
	case 9007ULL: goto x86_l_232f;
	case 9013ULL: goto x86_l_2335;
	case 9019ULL: goto x86_l_233b;
	case 9021ULL: goto x86_l_233d;
	case 9023ULL: goto x86_l_233f;
	case 9026ULL: goto x86_l_2342;
	case 9030ULL: goto x86_l_2346;
	case 9034ULL: goto x86_l_234a;
	case 9038ULL: goto x86_l_234e;
	case 9041ULL: goto x86_l_2351;
	case 9049ULL: goto x86_l_2359;
	case 9056ULL: goto x86_l_2360;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9080ULL: goto x86_l_2378;
	case 9082ULL: goto x86_l_237a;
	case 9088ULL: goto x86_l_2380;
	case 9094ULL: goto x86_l_2386;
	case 9100ULL: goto x86_l_238c;
	case 9102ULL: goto x86_l_238e;
	case 9104ULL: goto x86_l_2390;
	case 9107ULL: goto x86_l_2393;
	case 9111ULL: goto x86_l_2397;
	case 9115ULL: goto x86_l_239b;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9130ULL: goto x86_l_23aa;
	case 9137ULL: goto x86_l_23b1;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9152ULL: goto x86_l_23c0;
	case 9155ULL: goto x86_l_23c3;
	case 9157ULL: goto x86_l_23c5;
	case 9163ULL: goto x86_l_23cb;
	case 9169ULL: goto x86_l_23d1;
	case 9175ULL: goto x86_l_23d7;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9194ULL: goto x86_l_23ea;
	case 9197ULL: goto x86_l_23ed;
	case 9205ULL: goto x86_l_23f5;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9222ULL: goto x86_l_2406;
	case 9228ULL: goto x86_l_240c;
	case 9233ULL: goto x86_l_2411;
	case 9236ULL: goto x86_l_2414;
	case 9238ULL: goto x86_l_2416;
	case 9244ULL: goto x86_l_241c;
	case 9250ULL: goto x86_l_2422;
	case 9256ULL: goto x86_l_2428;
	case 9258ULL: goto x86_l_242a;
	case 9260ULL: goto x86_l_242c;
	case 9263ULL: goto x86_l_242f;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9275ULL: goto x86_l_243b;
	case 9278ULL: goto x86_l_243e;
	case 9286ULL: goto x86_l_2446;
	case 9293ULL: goto x86_l_244d;
	case 9298ULL: goto x86_l_2452;
	case 9303ULL: goto x86_l_2457;
	case 9308ULL: goto x86_l_245c;
	case 9311ULL: goto x86_l_245f;
	case 9313ULL: goto x86_l_2461;
	case 9319ULL: goto x86_l_2467;
	case 9325ULL: goto x86_l_246d;
	case 9331ULL: goto x86_l_2473;
	case 9333ULL: goto x86_l_2475;
	case 9335ULL: goto x86_l_2477;
	case 9338ULL: goto x86_l_247a;
	case 9342ULL: goto x86_l_247e;
	case 9346ULL: goto x86_l_2482;
	case 9350ULL: goto x86_l_2486;
	case 9353ULL: goto x86_l_2489;
	case 9361ULL: goto x86_l_2491;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9400ULL: goto x86_l_24b8;
	case 9406ULL: goto x86_l_24be;
	case 9412ULL: goto x86_l_24c4;
	case 9414ULL: goto x86_l_24c6;
	case 9416ULL: goto x86_l_24c8;
	case 9419ULL: goto x86_l_24cb;
	case 9423ULL: goto x86_l_24cf;
	case 9426ULL: goto x86_l_24d2;
	case 9429ULL: goto x86_l_24d5;
	case 9431ULL: goto x86_l_24d7;
	case 9438ULL: goto x86_l_24de;
	case 9445ULL: goto x86_l_24e5;
	case 9450ULL: goto x86_l_24ea;
	case 9455ULL: goto x86_l_24ef;
	case 9460ULL: goto x86_l_24f4;
	case 9463ULL: goto x86_l_24f7;
	case 9465ULL: goto x86_l_24f9;
	case 9471ULL: goto x86_l_24ff;
	case 9478ULL: goto x86_l_2506;
	case 9485ULL: goto x86_l_250d;
	case 9488ULL: goto x86_l_2510;
	case 9493ULL: goto x86_l_2515;
	case 9495ULL: goto x86_l_2517;
	case 9498ULL: goto x86_l_251a;
	case 9500ULL: goto x86_l_251c;
	case 9502ULL: goto x86_l_251e;
	case 9507ULL: goto x86_l_2523;
	case 9515ULL: goto x86_l_252b;
	case 9520ULL: goto x86_l_2530;
	case 9525ULL: goto x86_l_2535;
	case 9527ULL: goto x86_l_2537;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9541ULL: goto x86_l_2545;
	case 9543ULL: goto x86_l_2547;
	case 9548ULL: goto x86_l_254c;
	case 9554ULL: goto x86_l_2552;
	case 9556ULL: goto x86_l_2554;
	case 9561ULL: goto x86_l_2559;
	case 9567ULL: goto x86_l_255f;
	case 9569ULL: goto x86_l_2561;
	case 9574ULL: goto x86_l_2566;
	case 9580ULL: goto x86_l_256c;
	case 9582ULL: goto x86_l_256e;
	case 9587ULL: goto x86_l_2573;
	case 9593ULL: goto x86_l_2579;
	case 9595ULL: goto x86_l_257b;
	case 9600ULL: goto x86_l_2580;
	case 9606ULL: goto x86_l_2586;
	case 9608ULL: goto x86_l_2588;
	case 9613ULL: goto x86_l_258d;
	case 9618ULL: goto x86_l_2592;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9626ULL: goto x86_l_259a;
	case 9636ULL: goto x86_l_25a4;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9648ULL: goto x86_l_25b0;
	case 9652ULL: goto x86_l_25b4;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9667ULL: goto x86_l_25c3;
	case 9670ULL: goto x86_l_25c6;
	case 9672ULL: goto x86_l_25c8;
	case 9674ULL: goto x86_l_25ca;
	case 9676ULL: goto x86_l_25cc;
	case 9678ULL: goto x86_l_25ce;
	case 9683ULL: goto x86_l_25d3;
	case 9685ULL: goto x86_l_25d5;
	case 9690ULL: goto x86_l_25da;
	case 9695ULL: goto x86_l_25df;
	case 9698ULL: goto x86_l_25e2;
	case 9704ULL: goto x86_l_25e8;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9717ULL: goto x86_l_25f5;
	case 9719ULL: goto x86_l_25f7;
	case 9724ULL: goto x86_l_25fc;
	case 9730ULL: goto x86_l_2602;
	case 9732ULL: goto x86_l_2604;
	case 9737ULL: goto x86_l_2609;
	case 9743ULL: goto x86_l_260f;
	case 9745ULL: goto x86_l_2611;
	case 9750ULL: goto x86_l_2616;
	case 9756ULL: goto x86_l_261c;
	case 9758ULL: goto x86_l_261e;
	case 9763ULL: goto x86_l_2623;
	case 9769ULL: goto x86_l_2629;
	case 9771ULL: goto x86_l_262b;
	case 9776ULL: goto x86_l_2630;
	case 9782ULL: goto x86_l_2636;
	case 9784ULL: goto x86_l_2638;
	case 9789ULL: goto x86_l_263d;
	case 9795ULL: goto x86_l_2643;
	case 9797ULL: goto x86_l_2645;
	case 9802ULL: goto x86_l_264a;
	case 9808ULL: goto x86_l_2650;
	case 9810ULL: goto x86_l_2652;
	case 9815ULL: goto x86_l_2657;
	case 9821ULL: goto x86_l_265d;
	case 9823ULL: goto x86_l_265f;
	case 9828ULL: goto x86_l_2664;
	case 9834ULL: goto x86_l_266a;
	case 9839ULL: goto x86_l_266f;
	case 9842ULL: goto x86_l_2672;
	case 9844ULL: goto x86_l_2674;
	case 9849ULL: goto x86_l_2679;
	case 9851ULL: goto x86_l_267b;
	case 9856ULL: goto x86_l_2680;
	case 9861ULL: goto x86_l_2685;
	case 9867ULL: goto x86_l_268b;
	case 9869ULL: goto x86_l_268d;
	case 9875ULL: goto x86_l_2693;
	case 9877ULL: goto x86_l_2695;
	case 9883ULL: goto x86_l_269b;
	case 9885ULL: goto x86_l_269d;
	case 9891ULL: goto x86_l_26a3;
	case 9893ULL: goto x86_l_26a5;
	case 9899ULL: goto x86_l_26ab;
	case 9901ULL: goto x86_l_26ad;
	case 9907ULL: goto x86_l_26b3;
	case 9909ULL: goto x86_l_26b5;
	case 9915ULL: goto x86_l_26bb;
	case 9917ULL: goto x86_l_26bd;
	case 9923ULL: goto x86_l_26c3;
	case 9925ULL: goto x86_l_26c5;
	case 9931ULL: goto x86_l_26cb;
	case 9933ULL: goto x86_l_26cd;
	case 9939ULL: goto x86_l_26d3;
	case 9941ULL: goto x86_l_26d5;
	case 9947ULL: goto x86_l_26db;
	case 9949ULL: goto x86_l_26dd;
	case 9955ULL: goto x86_l_26e3;
	case 9957ULL: goto x86_l_26e5;
	case 9963ULL: goto x86_l_26eb;
	case 9965ULL: goto x86_l_26ed;
	case 9971ULL: goto x86_l_26f3;
	case 9974ULL: goto x86_l_26f6;
	case 9978ULL: goto x86_l_26fa;
	case 9985ULL: goto x86_l_2701;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9995ULL: goto x86_l_270b;
	case 9998ULL: goto x86_l_270e;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10007ULL: goto x86_l_2717;
	case 10011ULL: goto x86_l_271b;
	case 10016ULL: goto x86_l_2720;
	case 10019ULL: goto x86_l_2723;
	case 10026ULL: goto x86_l_272a;
	case 10031ULL: goto x86_l_272f;
	case 10034ULL: goto x86_l_2732;
	case 10037ULL: goto x86_l_2735;
	case 10039ULL: goto x86_l_2737;
	case 10041ULL: goto x86_l_2739;
	case 10043ULL: goto x86_l_273b;
	case 10051ULL: goto x86_l_2743;
	case 10056ULL: goto x86_l_2748;
	case 10058ULL: goto x86_l_274a;
	case 10061ULL: goto x86_l_274d;
	case 10068ULL: goto x86_l_2754;
	case 10073ULL: goto x86_l_2759;
	case 10078ULL: goto x86_l_275e;
	case 10080ULL: goto x86_l_2760;
	case 10085ULL: goto x86_l_2765;
	case 10090ULL: goto x86_l_276a;
	case 10093ULL: goto x86_l_276d;
	case 10095ULL: goto x86_l_276f;
	case 10098ULL: goto x86_l_2772;
	case 10103ULL: goto x86_l_2777;
	case 10106ULL: goto x86_l_277a;
	case 10108ULL: goto x86_l_277c;
	case 10118ULL: goto x86_l_2786;
	case 10126ULL: goto x86_l_278e;
	case 10133ULL: goto x86_l_2795;
	case 10141ULL: goto x86_l_279d;
	case 10147ULL: goto x86_l_27a3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2123:
	/* 0x2123: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2127:
	/* 0x2127: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_212b:
	/* 0x212b: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_212f:
	/* 0x212f: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2132:
	/* 0x2132: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_213a:
	/* 0x213a: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2141:
	/* 0x2141: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2146:
	/* 0x2146: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_214b:
	/* 0x214b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2150:
	/* 0x2150: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2153:
	/* 0x2153: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2155:
	/* 0x2155: je     268d <snat_v6_nat+0x1f09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_268d;
	}
x86_l_215b:
	/* 0x215b: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2161:
	/* 0x2161: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2167:
	/* 0x2167: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2169:
	/* 0x2169: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_216b:
	/* 0x216b: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_216e:
	/* 0x216e: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2172:
	/* 0x2172: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2176:
	/* 0x2176: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_217a:
	/* 0x217a: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_217d:
	/* 0x217d: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2185:
	/* 0x2185: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_218c:
	/* 0x218c: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2191:
	/* 0x2191: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2196:
	/* 0x2196: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_219c:
	/* 0x219c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_21a1:
	/* 0x21a1: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_21a4:
	/* 0x21a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21a6:
	/* 0x21a6: je     2695 <snat_v6_nat+0x1f11> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2695;
	}
x86_l_21ac:
	/* 0x21ac: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_21b2:
	/* 0x21b2: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_21b8:
	/* 0x21b8: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_21ba:
	/* 0x21ba: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_21bc:
	/* 0x21bc: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_21bf:
	/* 0x21bf: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_21c3:
	/* 0x21c3: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_21c7:
	/* 0x21c7: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_21cb:
	/* 0x21cb: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21ce:
	/* 0x21ce: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_21d6:
	/* 0x21d6: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_21dd:
	/* 0x21dd: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21e2:
	/* 0x21e2: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21e7:
	/* 0x21e7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_21ec:
	/* 0x21ec: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_21ef:
	/* 0x21ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21f1:
	/* 0x21f1: je     269d <snat_v6_nat+0x1f19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269d;
	}
x86_l_21f7:
	/* 0x21f7: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_21fd:
	/* 0x21fd: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2203:
	/* 0x2203: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2205:
	/* 0x2205: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2207:
	/* 0x2207: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_220a:
	/* 0x220a: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_220e:
	/* 0x220e: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2212:
	/* 0x2212: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2216:
	/* 0x2216: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2219:
	/* 0x2219: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2221:
	/* 0x2221: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2228:
	/* 0x2228: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_222d:
	/* 0x222d: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2232:
	/* 0x2232: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2238:
	/* 0x2238: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_223d:
	/* 0x223d: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2240:
	/* 0x2240: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2242:
	/* 0x2242: je     26a5 <snat_v6_nat+0x1f21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a5;
	}
x86_l_2248:
	/* 0x2248: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_224e:
	/* 0x224e: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2254:
	/* 0x2254: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2256:
	/* 0x2256: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2258:
	/* 0x2258: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_225b:
	/* 0x225b: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_225f:
	/* 0x225f: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2263:
	/* 0x2263: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2267:
	/* 0x2267: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_226a:
	/* 0x226a: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2272:
	/* 0x2272: mov    rdi,QWORD PTR [rip+0x690] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2279:
	/* 0x2279: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_227e:
	/* 0x227e: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2283:
	/* 0x2283: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2288:
	/* 0x2288: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_228b:
	/* 0x228b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228d:
	/* 0x228d: je     26ad <snat_v6_nat+0x1f29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ad;
	}
x86_l_2293:
	/* 0x2293: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2299:
	/* 0x2299: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_229f:
	/* 0x229f: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_22a1:
	/* 0x22a1: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22a3:
	/* 0x22a3: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22a6:
	/* 0x22a6: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_22aa:
	/* 0x22aa: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_22ae:
	/* 0x22ae: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_22b2:
	/* 0x22b2: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_22b5:
	/* 0x22b5: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_22bd:
	/* 0x22bd: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_22c4:
	/* 0x22c4: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22c9:
	/* 0x22c9: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_22ce:
	/* 0x22ce: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_22d4:
	/* 0x22d4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_22d9:
	/* 0x22d9: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_22dc:
	/* 0x22dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22de:
	/* 0x22de: je     26b5 <snat_v6_nat+0x1f31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b5;
	}
x86_l_22e4:
	/* 0x22e4: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_22ea:
	/* 0x22ea: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_22f0:
	/* 0x22f0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_22f2:
	/* 0x22f2: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22f4:
	/* 0x22f4: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_22f7:
	/* 0x22f7: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_22fb:
	/* 0x22fb: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_22ff:
	/* 0x22ff: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2303:
	/* 0x2303: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2306:
	/* 0x2306: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_230e:
	/* 0x230e: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2315:
	/* 0x2315: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_231a:
	/* 0x231a: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_231f:
	/* 0x231f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2324:
	/* 0x2324: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2327:
	/* 0x2327: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2329:
	/* 0x2329: je     26bd <snat_v6_nat+0x1f39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26bd;
	}
x86_l_232f:
	/* 0x232f: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2335:
	/* 0x2335: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_233b:
	/* 0x233b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_233d:
	/* 0x233d: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_233f:
	/* 0x233f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2342:
	/* 0x2342: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2346:
	/* 0x2346: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_234a:
	/* 0x234a: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_234e:
	/* 0x234e: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2351:
	/* 0x2351: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2359:
	/* 0x2359: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2360:
	/* 0x2360: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2365:
	/* 0x2365: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_236a:
	/* 0x236a: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2370:
	/* 0x2370: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2375:
	/* 0x2375: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2378:
	/* 0x2378: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237a:
	/* 0x237a: je     26c5 <snat_v6_nat+0x1f41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26c5;
	}
x86_l_2380:
	/* 0x2380: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2386:
	/* 0x2386: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_238c:
	/* 0x238c: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_238e:
	/* 0x238e: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2390:
	/* 0x2390: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2393:
	/* 0x2393: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2397:
	/* 0x2397: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_239b:
	/* 0x239b: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_239f:
	/* 0x239f: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23a2:
	/* 0x23a2: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_23aa:
	/* 0x23aa: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_23b1:
	/* 0x23b1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23b6:
	/* 0x23b6: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_23bb:
	/* 0x23bb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_23c0:
	/* 0x23c0: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_23c3:
	/* 0x23c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23c5:
	/* 0x23c5: je     26cd <snat_v6_nat+0x1f49> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26cd;
	}
x86_l_23cb:
	/* 0x23cb: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_23d1:
	/* 0x23d1: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_23d7:
	/* 0x23d7: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23d9:
	/* 0x23d9: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_23db:
	/* 0x23db: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_23de:
	/* 0x23de: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_23e2:
	/* 0x23e2: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_23e6:
	/* 0x23e6: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_23ea:
	/* 0x23ea: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23ed:
	/* 0x23ed: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_23f5:
	/* 0x23f5: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_23fc:
	/* 0x23fc: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2401:
	/* 0x2401: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2406:
	/* 0x2406: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_240c:
	/* 0x240c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2411:
	/* 0x2411: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2414:
	/* 0x2414: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2416:
	/* 0x2416: je     26d5 <snat_v6_nat+0x1f51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26d5;
	}
x86_l_241c:
	/* 0x241c: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2422:
	/* 0x2422: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2428:
	/* 0x2428: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_242a:
	/* 0x242a: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_242c:
	/* 0x242c: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_242f:
	/* 0x242f: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2433:
	/* 0x2433: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2437:
	/* 0x2437: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_243b:
	/* 0x243b: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_243e:
	/* 0x243e: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2446:
	/* 0x2446: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_244d:
	/* 0x244d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2452:
	/* 0x2452: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2457:
	/* 0x2457: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_245c:
	/* 0x245c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_245f:
	/* 0x245f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2461:
	/* 0x2461: je     26dd <snat_v6_nat+0x1f59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26dd;
	}
x86_l_2467:
	/* 0x2467: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_246d:
	/* 0x246d: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2473:
	/* 0x2473: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2475:
	/* 0x2475: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2477:
	/* 0x2477: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_247a:
	/* 0x247a: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_247e:
	/* 0x247e: imul   r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_2482:
	/* 0x2482: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2486:
	/* 0x2486: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2489:
	/* 0x2489: movbe  WORD PTR [rsp+0x38],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2491:
	/* 0x2491: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2498:
	/* 0x2498: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_249d:
	/* 0x249d: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24a2:
	/* 0x24a2: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_24a8:
	/* 0x24a8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_24ad:
	/* 0x24ad: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_24b0:
	/* 0x24b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24b2:
	/* 0x24b2: je     26e5 <snat_v6_nat+0x1f61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e5;
	}
x86_l_24b8:
	/* 0x24b8: movzx  eax,WORD PTR [r12+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_24be:
	/* 0x24be: movzx  ecx,WORD PTR [r12+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_24c4:
	/* 0x24c4: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24c6:
	/* 0x24c6: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_24c8:
	/* 0x24c8: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_24cb:
	/* 0x24cb: movzx  edx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_24cf:
	/* 0x24cf: imul   edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_24d2:
	/* 0x24d2: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_24d5:
	/* 0x24d5: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_24d7:
	/* 0x24d7: movbe  WORD PTR [rsp+0x38],dx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_24de:
	/* 0x24de: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_24e5:
	/* 0x24e5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24ea:
	/* 0x24ea: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_24ef:
	/* 0x24ef: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_24f4:
	/* 0x24f4: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_24f7:
	/* 0x24f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24f9:
	/* 0x24f9: je     26ed <snat_v6_nat+0x1f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26ed;
	}
x86_l_24ff:
	/* 0x24ff: mov    DWORD PTR [rsp],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2506:
	/* 0x2506: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_250d:
	/* 0x250d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2510:
	/* 0x2510: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2515:
	/* 0x2515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2517:
	/* 0x2517: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_251a:
	/* 0x251a: je     251e <snat_v6_nat+0x1d9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251e;
	}
x86_l_251c:
	/* 0x251c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_251e:
	/* 0x251e: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_2523:
	/* 0x2523: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_252b:
	/* 0x252b: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2530:
	/* 0x2530: jmp    277c <snat_v6_nat+0x1ff8> */
	goto x86_l_277c;
x86_l_2535:
	/* 0x2535: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2537:
	/* 0x2537: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_253a:
	/* 0x253a: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_253f:
	/* 0x253f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2545:
	/* 0x2545: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2547:
	/* 0x2547: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_254c:
	/* 0x254c: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_2552:
	/* 0x2552: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2554:
	/* 0x2554: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2559:
	/* 0x2559: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_255f:
	/* 0x255f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2561:
	/* 0x2561: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2566:
	/* 0x2566: mov    r14d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 5ULL);
x86_l_256c:
	/* 0x256c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_256e:
	/* 0x256e: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2573:
	/* 0x2573: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_2579:
	/* 0x2579: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257b:
	/* 0x257b: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2580:
	/* 0x2580: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_2586:
	/* 0x2586: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2588:
	/* 0x2588: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_258d:
	/* 0x258d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2592:
	/* 0x2592: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2594:
	/* 0x2594: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2596:
	/* 0x2596: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_259a:
	/* 0x259a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_25a4:
	/* 0x25a4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_25a7:
	/* 0x25a7: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_25ac:
	/* 0x25ac: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_25b0:
	/* 0x25b0: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b4:
	/* 0x25b4: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_25bb:
	/* 0x25bb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25c0:
	/* 0x25c0: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_25c3:
	/* 0x25c3: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_25c6:
	/* 0x25c6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25c8:
	/* 0x25c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25ca:
	/* 0x25ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25cc:
	/* 0x25cc: js     25d3 <snat_v6_nat+0x1e4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_25d3;
	}
x86_l_25ce:
	/* 0x25ce: jmp    27bd <snat_v6_nat+0x2039> */
	return 10173ULL;
x86_l_25d3:
	/* 0x25d3: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_25d5:
	/* 0x25d5: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_25da:
	/* 0x25da: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25df:
	/* 0x25df: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_25e2:
	/* 0x25e2: je     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2023ULL;
	}
x86_l_25e8:
	/* 0x25e8: mov    BYTE PTR [rdx],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25ea:
	/* 0x25ea: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_25ef:
	/* 0x25ef: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_25f5:
	/* 0x25f5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25f7:
	/* 0x25f7: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_25fc:
	/* 0x25fc: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_2602:
	/* 0x2602: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2604:
	/* 0x2604: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2609:
	/* 0x2609: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_260f:
	/* 0x260f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2611:
	/* 0x2611: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2616:
	/* 0x2616: mov    r14d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 11ULL);
x86_l_261c:
	/* 0x261c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_261e:
	/* 0x261e: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2623:
	/* 0x2623: mov    r14d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 12ULL);
x86_l_2629:
	/* 0x2629: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_262b:
	/* 0x262b: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2630:
	/* 0x2630: mov    r14d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 13ULL);
x86_l_2636:
	/* 0x2636: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2638:
	/* 0x2638: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_263d:
	/* 0x263d: mov    r14d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 14ULL);
x86_l_2643:
	/* 0x2643: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2645:
	/* 0x2645: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_264a:
	/* 0x264a: mov    r14d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 15ULL);
x86_l_2650:
	/* 0x2650: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2652:
	/* 0x2652: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2657:
	/* 0x2657: mov    r14d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16ULL);
x86_l_265d:
	/* 0x265d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_265f:
	/* 0x265f: jmp    26f6 <snat_v6_nat+0x1f72> */
	goto x86_l_26f6;
x86_l_2664:
	/* 0x2664: mov    r14d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 17ULL);
x86_l_266a:
	/* 0x266a: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_266f:
	/* 0x266f: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_2672:
	/* 0x2672: je     267b <snat_v6_nat+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267b;
	}
x86_l_2674:
	/* 0x2674: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2679:
	/* 0x2679: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267b:
	/* 0x267b: mov    eax,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967141ULL);
x86_l_2680:
	/* 0x2680: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_2685:
	/* 0x2685: mov    r14d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 18ULL);
x86_l_268b:
	/* 0x268b: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_268d:
	/* 0x268d: mov    r14d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 19ULL);
x86_l_2693:
	/* 0x2693: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_2695:
	/* 0x2695: mov    r14d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 20ULL);
x86_l_269b:
	/* 0x269b: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_269d:
	/* 0x269d: mov    r14d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21ULL);
x86_l_26a3:
	/* 0x26a3: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26a5:
	/* 0x26a5: mov    r14d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 22ULL);
x86_l_26ab:
	/* 0x26ab: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26ad:
	/* 0x26ad: mov    r14d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 23ULL);
x86_l_26b3:
	/* 0x26b3: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26b5:
	/* 0x26b5: mov    r14d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 24ULL);
x86_l_26bb:
	/* 0x26bb: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26bd:
	/* 0x26bd: mov    r14d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 25ULL);
x86_l_26c3:
	/* 0x26c3: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26c5:
	/* 0x26c5: mov    r14d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 26ULL);
x86_l_26cb:
	/* 0x26cb: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26cd:
	/* 0x26cd: mov    r14d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 27ULL);
x86_l_26d3:
	/* 0x26d3: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26d5:
	/* 0x26d5: mov    r14d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 28ULL);
x86_l_26db:
	/* 0x26db: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26dd:
	/* 0x26dd: mov    r14d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 29ULL);
x86_l_26e3:
	/* 0x26e3: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26e5:
	/* 0x26e5: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_26eb:
	/* 0x26eb: jmp    26f3 <snat_v6_nat+0x1f6f> */
	goto x86_l_26f3;
x86_l_26ed:
	/* 0x26ed: mov    r14d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 31ULL);
x86_l_26f3:
	/* 0x26f3: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_26f6:
	/* 0x26f6: mov    DWORD PTR [rsp],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26fa:
	/* 0x26fa: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_2701:
	/* 0x2701: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2704:
	/* 0x2704: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2709:
	/* 0x2709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270b:
	/* 0x270b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_270e:
	/* 0x270e: je     2712 <snat_v6_nat+0x1f8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2712;
	}
x86_l_2710:
	/* 0x2710: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2712:
	/* 0x2712: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2717:
	/* 0x2717: mov    WORD PTR [rbx+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_271b:
	/* 0x271b: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2720:
	/* 0x2720: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2723:
	/* 0x2723: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_272a:
	/* 0x272a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_272f:
	/* 0x272f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_2732:
	/* 0x2732: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2735:
	/* 0x2735: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2737:
	/* 0x2737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2739:
	/* 0x2739: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_273b:
	/* 0x273b: mov    r15,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2743:
	/* 0x2743: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2748:
	/* 0x2748: jns    2777 <snat_v6_nat+0x1ff3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_2777;
	}
x86_l_274a:
	/* 0x274a: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_274d:
	/* 0x274d: mov    rdi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_2754:
	/* 0x2754: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2759:
	/* 0x2759: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_275e:
	/* 0x275e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2760:
	/* 0x2760: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_2765:
	/* 0x2765: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_276a:
	/* 0x276a: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_276d:
	/* 0x276d: je     2772 <snat_v6_nat+0x1fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2772;
	}
x86_l_276f:
	/* 0x276f: mov    BYTE PTR [rcx],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2772:
	/* 0x2772: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2777:
	/* 0x2777: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_277a:
	/* 0x277a: je     27b5 <snat_v6_nat+0x2031> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10165ULL;
	}
x86_l_277c:
	/* 0x277c: movabs rcx,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 4294967296ULL);
x86_l_2786:
	/* 0x2786: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_278e:
	/* 0x278e: mov    rsi,QWORD PTR [rip+0x68d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_2795:
	/* 0x2795: lea    rcx,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_279d:
	/* 0x279d: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_27a3:
	/* 0x27a3: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
	return 10152ULL;
}

static __noinline __u64 cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10152ULL: goto x86_l_27a8;
	case 10158ULL: goto x86_l_27ae;
	case 10160ULL: goto x86_l_27b0;
	case 10163ULL: goto x86_l_27b3;
	case 10165ULL: goto x86_l_27b5;
	case 10167ULL: goto x86_l_27b7;
	case 10173ULL: goto x86_l_27bd;
	case 10177ULL: goto x86_l_27c1;
	case 10183ULL: goto x86_l_27c7;
	case 10189ULL: goto x86_l_27cd;
	case 10194ULL: goto x86_l_27d2;
	case 10198ULL: goto x86_l_27d6;
	case 10202ULL: goto x86_l_27da;
	case 10206ULL: goto x86_l_27de;
	case 10208ULL: goto x86_l_27e0;
	case 10211ULL: goto x86_l_27e3;
	case 10215ULL: goto x86_l_27e7;
	case 10217ULL: goto x86_l_27e9;
	case 10221ULL: goto x86_l_27ed;
	case 10223ULL: goto x86_l_27ef;
	case 10228ULL: goto x86_l_27f4;
	case 10234ULL: goto x86_l_27fa;
	case 10236ULL: goto x86_l_27fc;
	case 10239ULL: goto x86_l_27ff;
	case 10243ULL: goto x86_l_2803;
	case 10253ULL: goto x86_l_280d;
	case 10257ULL: goto x86_l_2811;
	case 10261ULL: goto x86_l_2815;
	case 10266ULL: goto x86_l_281a;
	case 10269ULL: goto x86_l_281d;
	case 10274ULL: goto x86_l_2822;
	case 10277ULL: goto x86_l_2825;
	case 10282ULL: goto x86_l_282a;
	case 10285ULL: goto x86_l_282d;
	case 10287ULL: goto x86_l_282f;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10300ULL: goto x86_l_283c;
	case 10305ULL: goto x86_l_2841;
	case 10308ULL: goto x86_l_2844;
	case 10313ULL: goto x86_l_2849;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10320ULL: goto x86_l_2850;
	case 10323ULL: goto x86_l_2853;
	case 10328ULL: goto x86_l_2858;
	case 10336ULL: goto x86_l_2860;
	case 10342ULL: goto x86_l_2866;
	case 10344ULL: goto x86_l_2868;
	case 10350ULL: goto x86_l_286e;
	case 10353ULL: goto x86_l_2871;
	case 10356ULL: goto x86_l_2874;
	case 10359ULL: goto x86_l_2877;
	case 10363ULL: goto x86_l_287b;
	case 10365ULL: goto x86_l_287d;
	case 10369ULL: goto x86_l_2881;
	case 10371ULL: goto x86_l_2883;
	case 10375ULL: goto x86_l_2887;
	case 10377ULL: goto x86_l_2889;
	case 10383ULL: goto x86_l_288f;
	case 10385ULL: goto x86_l_2891;
	case 10391ULL: goto x86_l_2897;
	case 10397ULL: goto x86_l_289d;
	case 10399ULL: goto x86_l_289f;
	case 10405ULL: goto x86_l_28a5;
	case 10408ULL: goto x86_l_28a8;
	case 10411ULL: goto x86_l_28ab;
	case 10413ULL: goto x86_l_28ad;
	case 10416ULL: goto x86_l_28b0;
	case 10419ULL: goto x86_l_28b3;
	case 10422ULL: goto x86_l_28b6;
	case 10424ULL: goto x86_l_28b8;
	case 10426ULL: goto x86_l_28ba;
	case 10431ULL: goto x86_l_28bf;
	case 10435ULL: goto x86_l_28c3;
	case 10441ULL: goto x86_l_28c9;
	case 10444ULL: goto x86_l_28cc;
	case 10454ULL: goto x86_l_28d6;
	case 10458ULL: goto x86_l_28da;
	case 10464ULL: goto x86_l_28e0;
	case 10468ULL: goto x86_l_28e4;
	case 10473ULL: goto x86_l_28e9;
	case 10477ULL: goto x86_l_28ed;
	case 10479ULL: goto x86_l_28ef;
	case 10484ULL: goto x86_l_28f4;
	case 10489ULL: goto x86_l_28f9;
	case 10494ULL: goto x86_l_28fe;
	case 10497ULL: goto x86_l_2901;
	case 10502ULL: goto x86_l_2906;
	case 10505ULL: goto x86_l_2909;
	case 10507ULL: goto x86_l_290b;
	case 10509ULL: goto x86_l_290d;
	case 10511ULL: goto x86_l_290f;
	case 10516ULL: goto x86_l_2914;
	case 10520ULL: goto x86_l_2918;
	case 10523ULL: goto x86_l_291b;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10535ULL: goto x86_l_2927;
	case 10539ULL: goto x86_l_292b;
	case 10541ULL: goto x86_l_292d;
	case 10543ULL: goto x86_l_292f;
	case 10545ULL: goto x86_l_2931;
	case 10548ULL: goto x86_l_2934;
	case 10550ULL: goto x86_l_2936;
	case 10553ULL: goto x86_l_2939;
	case 10557ULL: goto x86_l_293d;
	case 10562ULL: goto x86_l_2942;
	case 10567ULL: goto x86_l_2947;
	case 10570ULL: goto x86_l_294a;
	case 10572ULL: goto x86_l_294c;
	case 10574ULL: goto x86_l_294e;
	case 10577ULL: goto x86_l_2951;
	case 10579ULL: goto x86_l_2953;
	case 10581ULL: goto x86_l_2955;
	case 10583ULL: goto x86_l_2957;
	case 10585ULL: goto x86_l_2959;
	case 10590ULL: goto x86_l_295e;
	case 10595ULL: goto x86_l_2963;
	case 10600ULL: goto x86_l_2968;
	case 10605ULL: goto x86_l_296d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_27a8:
	/* 0x27a8: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_27ae:
	/* 0x27ae: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_27b0:
	/* 0x27b0: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_27b3:
	/* 0x27b3: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_27b5:
	/* 0x27b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27b7:
	/* 0x27b7: js     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2023ULL;
	}
x86_l_27bd:
	/* 0x27bd: movzx  edx,WORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_27c1:
	/* 0x27c1: movzx  r14d,BYTE PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_27c7:
	/* 0x27c7: movzx  ecx,WORD PTR [r12+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_27cd:
	/* 0x27cd: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27d2:
	/* 0x27d2: cmp    rax,QWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_27d6:
	/* 0x27d6: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27da:
	/* 0x27da: mov    DWORD PTR [rsp+0x40],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27de:
	/* 0x27de: jne    27fc <snat_v6_nat+0x2078> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27fc;
	}
x86_l_27e0:
	/* 0x27e0: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_27e3:
	/* 0x27e3: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_27e7:
	/* 0x27e7: jne    2803 <snat_v6_nat+0x207f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2803;
	}
x86_l_27e9:
	/* 0x27e9: mov    rcx,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27ed:
	/* 0x27ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27ef:
	/* 0x27ef: cmp    QWORD PTR [r12+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27f4:
	/* 0x27f4: je     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2023ULL;
	}
x86_l_27fa:
	/* 0x27fa: jmp    2803 <snat_v6_nat+0x207f> */
	goto x86_l_2803;
x86_l_27fc:
	/* 0x27fc: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_27ff:
	/* 0x27ff: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_2803:
	/* 0x2803: movabs rbp,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 2199023255552ULL);
x86_l_280d:
	/* 0x280d: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_2811:
	/* 0x2811: add    rbx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2815:
	/* 0x2815: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_281a:
	/* 0x281a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_281d:
	/* 0x281d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2822:
	/* 0x2822: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2825:
	/* 0x2825: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_282a:
	/* 0x282a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_282d:
	/* 0x282d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_282f:
	/* 0x282f: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_2832:
	/* 0x2832: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2837:
	/* 0x2837: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_283c:
	/* 0x283c: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_2841:
	/* 0x2841: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_2844:
	/* 0x2844: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2849:
	/* 0x2849: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284c:
	/* 0x284c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_284e:
	/* 0x284e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2850:
	/* 0x2850: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_2853:
	/* 0x2853: and    eax,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_2858:
	/* 0x2858: test   QWORD PTR [rsp+0xa8],rbp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2860:
	/* 0x2860: jne    7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2023ULL;
	}
x86_l_2866:
	/* 0x2866: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2868:
	/* 0x2868: js     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 2023ULL;
	}
x86_l_286e:
	/* 0x286e: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_2871:
	/* 0x2871: mov    rbx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R15, X86_WIDTH_64);
x86_l_2874:
	/* 0x2874: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_2877:
	/* 0x2877: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_287b:
	/* 0x287b: je     289f <snat_v6_nat+0x211b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_289f;
	}
x86_l_287d:
	/* 0x287d: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_2881:
	/* 0x2881: je     2891 <snat_v6_nat+0x210d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2891;
	}
x86_l_2883:
	/* 0x2883: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_2887:
	/* 0x2887: jne    28ad <snat_v6_nat+0x2129> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28ad;
	}
x86_l_2889:
	/* 0x2889: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_288f:
	/* 0x288f: jmp    28a5 <snat_v6_nat+0x2121> */
	goto x86_l_28a5;
x86_l_2891:
	/* 0x2891: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_2897:
	/* 0x2897: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_289d:
	/* 0x289d: jmp    28a8 <snat_v6_nat+0x2124> */
	goto x86_l_28a8;
x86_l_289f:
	/* 0x289f: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_28a5:
	/* 0x28a5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a8:
	/* 0x28a8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28ab:
	/* 0x28ab: jmp    28b6 <snat_v6_nat+0x2132> */
	goto x86_l_28b6;
x86_l_28ad:
	/* 0x28ad: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_28b0:
	/* 0x28b0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b3:
	/* 0x28b3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b6:
	/* 0x28b6: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_28b8:
	/* 0x28b8: jne    2931 <snat_v6_nat+0x21ad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2931;
	}
x86_l_28ba:
	/* 0x28ba: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_28bf:
	/* 0x28bf: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_28c3:
	/* 0x28c3: ja     7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2023ULL;
	}
x86_l_28c9:
	/* 0x28c9: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_28cc:
	/* 0x28cc: movabs rdx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_28d6:
	/* 0x28d6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_28da:
	/* 0x28da: jae    7e7 <snat_v6_nat+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2023ULL;
	}
x86_l_28e0:
	/* 0x28e0: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_28e4:
	/* 0x28e4: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28e9:
	/* 0x28e9: mov    esi,DWORD PTR [rsp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_28ed:
	/* 0x28ed: add    esi,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28ef:
	/* 0x28ef: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28f4:
	/* 0x28f4: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_28f9:
	/* 0x28f9: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28fe:
	/* 0x28fe: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2901:
	/* 0x2901: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2906:
	/* 0x2906: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2909:
	/* 0x2909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_290b:
	/* 0x290b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_290d:
	/* 0x290d: js     2968 <snat_v6_nat+0x21e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2968;
	}
x86_l_290f:
	/* 0x290f: movzx  ecx,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_2914:
	/* 0x2914: lea    esi,[r12+rbx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_2918:
	/* 0x2918: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_291b:
	/* 0x291b: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_291f:
	/* 0x291f: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2924:
	/* 0x2924: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2927:
	/* 0x2927: mov    edx,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_292b:
	/* 0x292b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292d:
	/* 0x292d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_292f:
	/* 0x292f: js     295e <snat_v6_nat+0x21da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_295e;
	}
x86_l_2931:
	/* 0x2931: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_2934:
	/* 0x2934: jne    2957 <snat_v6_nat+0x21d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2957;
	}
x86_l_2936:
	/* 0x2936: add    r12d,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2939:
	/* 0x2939: or     r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_293d:
	/* 0x293d: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_2942:
	/* 0x2942: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2947:
	/* 0x2947: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_294a:
	/* 0x294a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_294c:
	/* 0x294c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_294e:
	/* 0x294e: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_2951:
	/* 0x2951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2953:
	/* 0x2953: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2955:
	/* 0x2955: js     295e <snat_v6_nat+0x21da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_295e;
	}
x86_l_2957:
	/* 0x2957: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2959:
	/* 0x2959: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_295e:
	/* 0x295e: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_2963:
	/* 0x2963: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
x86_l_2968:
	/* 0x2968: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_296d:
	/* 0x296d: jmp    7e7 <snat_v6_nat+0x63> */
	return 2023ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9700U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1701ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1706ULL && __x86_pc <= 3478ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3486ULL && __x86_pc <= 5083ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5088ULL && __x86_pc <= 6876ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6881ULL && __x86_pc <= 8480ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8483ULL && __x86_pc <= 10147ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10152ULL && __x86_pc <= 10605ULL)
			__x86_pc = cilium_bpf_overlay_tail_handle_snat_fwd_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

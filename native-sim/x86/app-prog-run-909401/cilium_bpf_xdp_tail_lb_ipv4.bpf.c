extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_hash_init4_seed;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_affinity;
extern char cilium_lb4_backends_v3;
extern char cilium_lb4_maglev;
extern char cilium_lb4_services_v2;
extern char cilium_lb4_source_range;
extern char cilium_lb_affinity_match;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_nodeport_neigh4;
extern char cilium_snat_v6_external;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 21ULL: goto x86_l_15;
	case 28ULL: goto x86_l_1c;
	case 33ULL: goto x86_l_21;
	case 38ULL: goto x86_l_26;
	case 40ULL: goto x86_l_28;
	case 43ULL: goto x86_l_2b;
	case 45ULL: goto x86_l_2d;
	case 49ULL: goto x86_l_31;
	case 51ULL: goto x86_l_33;
	case 59ULL: goto x86_l_3b;
	case 66ULL: goto x86_l_42;
	case 71ULL: goto x86_l_47;
	case 76ULL: goto x86_l_4c;
	case 78ULL: goto x86_l_4e;
	case 81ULL: goto x86_l_51;
	case 87ULL: goto x86_l_57;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 99ULL: goto x86_l_63;
	case 105ULL: goto x86_l_69;
	case 110ULL: goto x86_l_6e;
	case 113ULL: goto x86_l_71;
	case 118ULL: goto x86_l_76;
	case 120ULL: goto x86_l_78;
	case 122ULL: goto x86_l_7a;
	case 128ULL: goto x86_l_80;
	case 130ULL: goto x86_l_82;
	case 133ULL: goto x86_l_85;
	case 137ULL: goto x86_l_89;
	case 140ULL: goto x86_l_8c;
	case 146ULL: goto x86_l_92;
	case 149ULL: goto x86_l_95;
	case 154ULL: goto x86_l_9a;
	case 157ULL: goto x86_l_9d;
	case 160ULL: goto x86_l_a0;
	case 164ULL: goto x86_l_a4;
	case 167ULL: goto x86_l_a7;
	case 173ULL: goto x86_l_ad;
	case 176ULL: goto x86_l_b0;
	case 181ULL: goto x86_l_b5;
	case 189ULL: goto x86_l_bd;
	case 196ULL: goto x86_l_c4;
	case 201ULL: goto x86_l_c9;
	case 207ULL: goto x86_l_cf;
	case 210ULL: goto x86_l_d2;
	case 213ULL: goto x86_l_d5;
	case 215ULL: goto x86_l_d7;
	case 221ULL: goto x86_l_dd;
	case 229ULL: goto x86_l_e5;
	case 236ULL: goto x86_l_ec;
	case 241ULL: goto x86_l_f1;
	case 244ULL: goto x86_l_f4;
	case 247ULL: goto x86_l_f7;
	case 249ULL: goto x86_l_f9;
	case 256ULL: goto x86_l_100;
	case 258ULL: goto x86_l_102;
	case 266ULL: goto x86_l_10a;
	case 273ULL: goto x86_l_111;
	case 278ULL: goto x86_l_116;
	case 284ULL: goto x86_l_11c;
	case 287ULL: goto x86_l_11f;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 296ULL: goto x86_l_128;
	case 300ULL: goto x86_l_12c;
	case 304ULL: goto x86_l_130;
	case 306ULL: goto x86_l_132;
	case 309ULL: goto x86_l_135;
	case 317ULL: goto x86_l_13d;
	case 324ULL: goto x86_l_144;
	case 329ULL: goto x86_l_149;
	case 332ULL: goto x86_l_14c;
	case 335ULL: goto x86_l_14f;
	case 337ULL: goto x86_l_151;
	case 344ULL: goto x86_l_158;
	case 352ULL: goto x86_l_160;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 370ULL: goto x86_l_172;
	case 373ULL: goto x86_l_175;
	case 376ULL: goto x86_l_178;
	case 378ULL: goto x86_l_17a;
	case 385ULL: goto x86_l_181;
	case 387ULL: goto x86_l_183;
	case 391ULL: goto x86_l_187;
	case 394ULL: goto x86_l_18a;
	case 404ULL: goto x86_l_194;
	case 409ULL: goto x86_l_199;
	case 414ULL: goto x86_l_19e;
	case 421ULL: goto x86_l_1a5;
	case 426ULL: goto x86_l_1aa;
	case 429ULL: goto x86_l_1ad;
	case 432ULL: goto x86_l_1b0;
	case 438ULL: goto x86_l_1b6;
	case 441ULL: goto x86_l_1b9;
	case 445ULL: goto x86_l_1bd;
	case 450ULL: goto x86_l_1c2;
	case 460ULL: goto x86_l_1cc;
	case 467ULL: goto x86_l_1d3;
	case 475ULL: goto x86_l_1db;
	case 485ULL: goto x86_l_1e5;
	case 493ULL: goto x86_l_1ed;
	case 502ULL: goto x86_l_1f6;
	case 507ULL: goto x86_l_1fb;
	case 512ULL: goto x86_l_200;
	case 515ULL: goto x86_l_203;
	case 519ULL: goto x86_l_207;
	case 522ULL: goto x86_l_20a;
	case 527ULL: goto x86_l_20f;
	case 531ULL: goto x86_l_213;
	case 537ULL: goto x86_l_219;
	case 541ULL: goto x86_l_21d;
	case 545ULL: goto x86_l_221;
	case 551ULL: goto x86_l_227;
	case 555ULL: goto x86_l_22b;
	case 559ULL: goto x86_l_22f;
	case 563ULL: goto x86_l_233;
	case 567ULL: goto x86_l_237;
	case 571ULL: goto x86_l_23b;
	case 574ULL: goto x86_l_23e;
	case 578ULL: goto x86_l_242;
	case 582ULL: goto x86_l_246;
	case 586ULL: goto x86_l_24a;
	case 590ULL: goto x86_l_24e;
	case 594ULL: goto x86_l_252;
	case 597ULL: goto x86_l_255;
	case 603ULL: goto x86_l_25b;
	case 606ULL: goto x86_l_25e;
	case 608ULL: goto x86_l_260;
	case 611ULL: goto x86_l_263;
	case 617ULL: goto x86_l_269;
	case 624ULL: goto x86_l_270;
	case 628ULL: goto x86_l_274;
	case 634ULL: goto x86_l_27a;
	case 638ULL: goto x86_l_27e;
	case 642ULL: goto x86_l_282;
	case 648ULL: goto x86_l_288;
	case 651ULL: goto x86_l_28b;
	case 655ULL: goto x86_l_28f;
	case 659ULL: goto x86_l_293;
	case 664ULL: goto x86_l_298;
	case 667ULL: goto x86_l_29b;
	case 673ULL: goto x86_l_2a1;
	case 677ULL: goto x86_l_2a5;
	case 681ULL: goto x86_l_2a9;
	case 686ULL: goto x86_l_2ae;
	case 689ULL: goto x86_l_2b1;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 703ULL: goto x86_l_2bf;
	case 712ULL: goto x86_l_2c8;
	case 717ULL: goto x86_l_2cd;
	case 724ULL: goto x86_l_2d4;
	case 729ULL: goto x86_l_2d9;
	case 734ULL: goto x86_l_2de;
	case 739ULL: goto x86_l_2e3;
	case 741ULL: goto x86_l_2e5;
	case 743ULL: goto x86_l_2e7;
	case 750ULL: goto x86_l_2ee;
	case 755ULL: goto x86_l_2f3;
	case 760ULL: goto x86_l_2f8;
	case 763ULL: goto x86_l_2fb;
	case 768ULL: goto x86_l_300;
	case 770ULL: goto x86_l_302;
	case 772ULL: goto x86_l_304;
	case 779ULL: goto x86_l_30b;
	case 781ULL: goto x86_l_30d;
	case 782ULL: goto x86_l_30e;
	case 787ULL: goto x86_l_313;
	case 795ULL: goto x86_l_31b;
	case 803ULL: goto x86_l_323;
	case 808ULL: goto x86_l_328;
	case 810ULL: goto x86_l_32a;
	case 818ULL: goto x86_l_332;
	case 825ULL: goto x86_l_339;
	case 830ULL: goto x86_l_33e;
	case 836ULL: goto x86_l_344;
	case 839ULL: goto x86_l_347;
	case 842ULL: goto x86_l_34a;
	case 844ULL: goto x86_l_34c;
	case 848ULL: goto x86_l_350;
	case 856ULL: goto x86_l_358;
	case 863ULL: goto x86_l_35f;
	case 868ULL: goto x86_l_364;
	case 871ULL: goto x86_l_367;
	case 874ULL: goto x86_l_36a;
	case 876ULL: goto x86_l_36c;
	case 880ULL: goto x86_l_370;
	case 884ULL: goto x86_l_374;
	case 887ULL: goto x86_l_377;
	case 892ULL: goto x86_l_37c;
	case 898ULL: goto x86_l_382;
	case 903ULL: goto x86_l_387;
	case 908ULL: goto x86_l_38c;
	case 913ULL: goto x86_l_391;
	case 918ULL: goto x86_l_396;
	case 924ULL: goto x86_l_39c;
	case 928ULL: goto x86_l_3a0;
	case 934ULL: goto x86_l_3a6;
	case 936ULL: goto x86_l_3a8;
	case 939ULL: goto x86_l_3ab;
	case 947ULL: goto x86_l_3b3;
	case 951ULL: goto x86_l_3b7;
	case 955ULL: goto x86_l_3bb;
	case 960ULL: goto x86_l_3c0;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 972ULL: goto x86_l_3cc;
	case 976ULL: goto x86_l_3d0;
	case 980ULL: goto x86_l_3d4;
	case 984ULL: goto x86_l_3d8;
	case 988ULL: goto x86_l_3dc;
	case 992ULL: goto x86_l_3e0;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1007ULL: goto x86_l_3ef;
	case 1013ULL: goto x86_l_3f5;
	case 1018ULL: goto x86_l_3fa;
	case 1024ULL: goto x86_l_400;
	case 1027ULL: goto x86_l_403;
	case 1034ULL: goto x86_l_40a;
	case 1039ULL: goto x86_l_40f;
	case 1047ULL: goto x86_l_417;
	case 1050ULL: goto x86_l_41a;
	case 1053ULL: goto x86_l_41d;
	case 1059ULL: goto x86_l_423;
	case 1067ULL: goto x86_l_42b;
	case 1071ULL: goto x86_l_42f;
	case 1075ULL: goto x86_l_433;
	case 1079ULL: goto x86_l_437;
	case 1084ULL: goto x86_l_43c;
	case 1087ULL: goto x86_l_43f;
	case 1093ULL: goto x86_l_445;
	case 1098ULL: goto x86_l_44a;
	case 1101ULL: goto x86_l_44d;
	case 1103ULL: goto x86_l_44f;
	case 1107ULL: goto x86_l_453;
	case 1110ULL: goto x86_l_456;
	case 1112ULL: goto x86_l_458;
	case 1120ULL: goto x86_l_460;
	case 1124ULL: goto x86_l_464;
	case 1126ULL: goto x86_l_466;
	case 1130ULL: goto x86_l_46a;
	case 1138ULL: goto x86_l_472;
	case 1141ULL: goto x86_l_475;
	case 1147ULL: goto x86_l_47b;
	case 1152ULL: goto x86_l_480;
	case 1157ULL: goto x86_l_485;
	case 1161ULL: goto x86_l_489;
	case 1166ULL: goto x86_l_48e;
	case 1170ULL: goto x86_l_492;
	case 1174ULL: goto x86_l_496;
	case 1179ULL: goto x86_l_49b;
	case 1186ULL: goto x86_l_4a2;
	case 1191ULL: goto x86_l_4a7;
	case 1198ULL: goto x86_l_4ae;
	case 1203ULL: goto x86_l_4b3;
	case 1209ULL: goto x86_l_4b9;
	case 1212ULL: goto x86_l_4bc;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1222ULL: goto x86_l_4c6;
	case 1227ULL: goto x86_l_4cb;
	case 1232ULL: goto x86_l_4d0;
	case 1239ULL: goto x86_l_4d7;
	case 1244ULL: goto x86_l_4dc;
	case 1251ULL: goto x86_l_4e3;
	case 1256ULL: goto x86_l_4e8;
	case 1259ULL: goto x86_l_4eb;
	case 1262ULL: goto x86_l_4ee;
	case 1268ULL: goto x86_l_4f4;
	case 1271ULL: goto x86_l_4f7;
	case 1277ULL: goto x86_l_4fd;
	case 1279ULL: goto x86_l_4ff;
	case 1284ULL: goto x86_l_504;
	case 1286ULL: goto x86_l_506;
	case 1291ULL: goto x86_l_50b;
	case 1296ULL: goto x86_l_510;
	case 1304ULL: goto x86_l_518;
	case 1311ULL: goto x86_l_51f;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1323ULL: goto x86_l_52b;
	case 1326ULL: goto x86_l_52e;
	case 1328ULL: goto x86_l_530;
	case 1334ULL: goto x86_l_536;
	case 1341ULL: goto x86_l_53d;
	case 1347ULL: goto x86_l_543;
	case 1352ULL: goto x86_l_548;
	case 1355ULL: goto x86_l_54b;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1367ULL: goto x86_l_557;
	case 1372ULL: goto x86_l_55c;
	case 1376ULL: goto x86_l_560;
	case 1378ULL: goto x86_l_562;
	case 1382ULL: goto x86_l_566;
	case 1386ULL: goto x86_l_56a;
	case 1394ULL: goto x86_l_572;
	case 1399ULL: goto x86_l_577;
	case 1406ULL: goto x86_l_57e;
	case 1410ULL: goto x86_l_582;
	case 1417ULL: goto x86_l_589;
	case 1422ULL: goto x86_l_58e;
	case 1427ULL: goto x86_l_593;
	case 1430ULL: goto x86_l_596;
	case 1432ULL: goto x86_l_598;
	case 1435ULL: goto x86_l_59b;
	case 1438ULL: goto x86_l_59e;
	case 1441ULL: goto x86_l_5a1;
	case 1444ULL: goto x86_l_5a4;
	case 1449ULL: goto x86_l_5a9;
	case 1452ULL: goto x86_l_5ac;
	case 1455ULL: goto x86_l_5af;
	case 1460ULL: goto x86_l_5b4;
	case 1462ULL: goto x86_l_5b6;
	case 1468ULL: goto x86_l_5bc;
	case 1472ULL: goto x86_l_5c0;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1486ULL: goto x86_l_5ce;
	case 1489ULL: goto x86_l_5d1;
	case 1495ULL: goto x86_l_5d7;
	case 1499ULL: goto x86_l_5db;
	case 1501ULL: goto x86_l_5dd;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1516ULL: goto x86_l_5ec;
	case 1520ULL: goto x86_l_5f0;
	case 1526ULL: goto x86_l_5f6;
	case 1533ULL: goto x86_l_5fd;
	case 1538ULL: goto x86_l_602;
	case 1543ULL: goto x86_l_607;
	case 1545ULL: goto x86_l_609;
	case 1547ULL: goto x86_l_60b;
	case 1549ULL: goto x86_l_60d;
	case 1551ULL: goto x86_l_60f;
	case 1554ULL: goto x86_l_612;
	case 1558ULL: goto x86_l_616;
	case 1563ULL: goto x86_l_61b;
	case 1566ULL: goto x86_l_61e;
	case 1572ULL: goto x86_l_624;
	case 1576ULL: goto x86_l_628;
	case 1579ULL: goto x86_l_62b;
	case 1584ULL: goto x86_l_630;
	case 1586ULL: goto x86_l_632;
	case 1589ULL: goto x86_l_635;
	case 1593ULL: goto x86_l_639;
	case 1596ULL: goto x86_l_63c;
	case 1602ULL: goto x86_l_642;
	case 1604ULL: goto x86_l_644;
	case 1609ULL: goto x86_l_649;
	case 1616ULL: goto x86_l_650;
	case 1620ULL: goto x86_l_654;
	case 1625ULL: goto x86_l_659;
	case 1629ULL: goto x86_l_65d;
	case 1635ULL: goto x86_l_663;
	case 1640ULL: goto x86_l_668;
	case 1642ULL: goto x86_l_66a;
	case 1649ULL: goto x86_l_671;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1666ULL: goto x86_l_682;
	case 1669ULL: goto x86_l_685;
	case 1674ULL: goto x86_l_68a;
	case 1681ULL: goto x86_l_691;
	case 1686ULL: goto x86_l_696;
	case 1691ULL: goto x86_l_69b;
	case 1693ULL: goto x86_l_69d;
	case 1696ULL: goto x86_l_6a0;
	case 1702ULL: goto x86_l_6a6;
	case 1706ULL: goto x86_l_6aa;
	case 1711ULL: goto x86_l_6af;
	case 1714ULL: goto x86_l_6b2;
	case 1721ULL: goto x86_l_6b9;
	case 1726ULL: goto x86_l_6be;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21:
	/* 0x21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26:
	/* 0x26: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28:
	/* 0x28: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: je     9a <tail_lb_ipv4+0x9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a;
	}
x86_l_2d:
	/* 0x2d: cmp    DWORD PTR [rax+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_31:
	/* 0x31: je     9a <tail_lb_ipv4+0x9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a;
	}
x86_l_33:
	/* 0x33: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3b:
	/* 0x3b: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_42:
	/* 0x42: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_47:
	/* 0x47: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c:
	/* 0x4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e:
	/* 0x4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: je     b5e <tail_lb_ipv4+0xb5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2910ULL;
	}
x86_l_57:
	/* 0x57: mov    r14d,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b:
	/* 0x5b: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_60:
	/* 0x60: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_63:
	/* 0x63: je     302 <tail_lb_ipv4+0x302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_302;
	}
x86_l_69:
	/* 0x69: mov    eax,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 54ULL);
x86_l_6e:
	/* 0x6e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_71:
	/* 0x71: mov    esi,0xfffffffc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967292ULL);
x86_l_76:
	/* 0x76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78:
	/* 0x78: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7a:
	/* 0x7a: jne    302 <tail_lb_ipv4+0x302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_302;
	}
x86_l_80:
	/* 0x80: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82:
	/* 0x82: mov    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_85:
	/* 0x85: lea    rdx,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_89:
	/* 0x89: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: ja     302 <tail_lb_ipv4+0x302> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_302;
	}
x86_l_92:
	/* 0x92: mov    DWORD PTR [rax],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95:
	/* 0x95: jmp    302 <tail_lb_ipv4+0x302> */
	goto x86_l_302;
x86_l_9a:
	/* 0x9a: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d:
	/* 0x9d: mov    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a0:
	/* 0xa0: lea    rcx,[r15+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_a4:
	/* 0xa4: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: jbe    1c2 <tail_lb_ipv4+0x1c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1c2;
	}
x86_l_ad:
	/* 0xad: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b0:
	/* 0xb0: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_bd:
	/* 0xbd: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_c4:
	/* 0xc4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c9:
	/* 0xc9: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_cf:
	/* 0xcf: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_d2:
	/* 0xd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: je     dd <tail_lb_ipv4+0xdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_dd;
	}
x86_l_d7:
	/* 0xd7: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd:
	/* 0xdd: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e5:
	/* 0xe5: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_ec:
	/* 0xec: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f1:
	/* 0xf1: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_f4:
	/* 0xf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f7:
	/* 0xf7: je     100 <tail_lb_ipv4+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_100;
	}
x86_l_f9:
	/* 0xf9: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_100:
	/* 0x100: neg    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_102:
	/* 0x102: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_10a:
	/* 0x10a: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_111:
	/* 0x111: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_116:
	/* 0x116: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_11c:
	/* 0x11c: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_11f:
	/* 0x11f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_122:
	/* 0x122: je     135 <tail_lb_ipv4+0x135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_135;
	}
x86_l_124:
	/* 0x124: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_128:
	/* 0x128: movzx  ecx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_12c:
	/* 0x12c: movzx  edx,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_130:
	/* 0x130: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_132:
	/* 0x132: mov    DWORD PTR [rax+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_135:
	/* 0x135: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13d:
	/* 0x13d: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_144:
	/* 0x144: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_149:
	/* 0x149: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_14c:
	/* 0x14c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f:
	/* 0x14f: je     158 <tail_lb_ipv4+0x158> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_158;
	}
x86_l_151:
	/* 0x151: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_158:
	/* 0x158: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_160:
	/* 0x160: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_167:
	/* 0x167: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_16c:
	/* 0x16c: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_172:
	/* 0x172: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_175:
	/* 0x175: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_178:
	/* 0x178: je     181 <tail_lb_ipv4+0x181> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_181;
	}
x86_l_17a:
	/* 0x17a: mov    DWORD PTR [rax+0x10],0x790401 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68727407617ULL);
x86_l_181:
	/* 0x181: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183:
	/* 0x183: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_187:
	/* 0x187: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_18a:
	/* 0x18a: movabs rax,0x400790100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17187799296ULL);
x86_l_194:
	/* 0x194: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_199:
	/* 0x199: mov    BYTE PTR [rsp+0x70],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19e:
	/* 0x19e: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a5:
	/* 0x1a5: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1aa:
	/* 0x1aa: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1ad:
	/* 0x1ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b0:
	/* 0x1b0: je     2bf <tail_lb_ipv4+0x2bf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bf;
	}
x86_l_1b6:
	/* 0x1b6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b9:
	/* 0x1b9: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1bd:
	/* 0x1bd: jmp    2e7 <tail_lb_ipv4+0x2e7> */
	goto x86_l_2e7;
x86_l_1c2:
	/* 0x1c2: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_1cc:
	/* 0x1cc: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d3:
	/* 0x1d3: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1db:
	/* 0x1db: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_1e5:
	/* 0x1e5: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1ed:
	/* 0x1ed: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1f6:
	/* 0x1f6: movzx  edx,WORD PTR [r15+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1fb:
	/* 0x1fb: movzx  ecx,BYTE PTR [r15+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_200:
	/* 0x200: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_207:
	/* 0x207: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_20a:
	/* 0x20a: movzx  edx,WORD PTR [r15+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_20f:
	/* 0x20f: lea    rdi,[rsi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_213:
	/* 0x213: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_219:
	/* 0x219: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_21d:
	/* 0x21d: lea    r9,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_221:
	/* 0x221: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_227:
	/* 0x227: cmove  r9,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_22b:
	/* 0x22b: mov    r13d,DWORD PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_22f:
	/* 0x22f: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_233:
	/* 0x233: and    r13d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_237:
	/* 0x237: lea    rdi,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_23b:
	/* 0x23b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23e:
	/* 0x23e: mov    BYTE PTR [rsp+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_242:
	/* 0x242: mov    edx,DWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_246:
	/* 0x246: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24a:
	/* 0x24a: mov    esi,DWORD PTR [r15+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_24e:
	/* 0x24e: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_252:
	/* 0x252: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_255:
	/* 0x255: je     313 <tail_lb_ipv4+0x313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_313;
	}
x86_l_25b:
	/* 0x25b: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_25e:
	/* 0x25e: je     269 <tail_lb_ipv4+0x269> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_269;
	}
x86_l_260:
	/* 0x260: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_263:
	/* 0x263: jne    22d0 <tail_lb_ipv4+0x22d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8912ULL;
	}
x86_l_269:
	/* 0x269: mov    r11,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R11, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_270:
	/* 0x270: cmp    BYTE PTR [r11],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R11, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_274:
	/* 0x274: je     40f <tail_lb_ipv4+0x40f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_40f;
	}
x86_l_27a:
	/* 0x27a: mov    DWORD PTR [rsp+0x70],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27e:
	/* 0x27e: mov    DWORD PTR [rsp+0x74],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_282:
	/* 0x282: mov    WORD PTR [rsp+0x78],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_288:
	/* 0x288: mov    rcx,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R9, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_28f:
	/* 0x28f: mov    BYTE PTR [rsp+0x7a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_293:
	/* 0x293: mov    BYTE PTR [rsp+0x7b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 528280977408ULL);
x86_l_298:
	/* 0x298: test   r9,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R8, X86_WIDTH_64);
x86_l_29b:
	/* 0x29b: jne    13f8 <tail_lb_ipv4+0x13f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5112ULL;
	}
x86_l_2a1:
	/* 0x2a1: lea    rcx,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2a5:
	/* 0x2a5: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2a9:
	/* 0x2a9: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_2ae:
	/* 0x2ae: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2b1:
	/* 0x2b1: jbe    458 <tail_lb_ipv4+0x458> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_458;
	}
x86_l_2b7:
	/* 0x2b7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba:
	/* 0x2ba: jmp    b5 <tail_lb_ipv4+0xb5> */
	goto x86_l_b5;
x86_l_2bf:
	/* 0x2bf: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2c8:
	/* 0x2c8: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2cd:
	/* 0x2cd: mov    rdi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2d4:
	/* 0x2d4: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2d9:
	/* 0x2d9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2de:
	/* 0x2de: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e3:
	/* 0x2e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e5:
	/* 0x2e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e7:
	/* 0x2e7: mov    rsi,QWORD PTR [rip+0xdbd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2ee:
	/* 0x2ee: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2f3:
	/* 0x2f3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2f8:
	/* 0x2f8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_300:
	/* 0x300: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_302:
	/* 0x302: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_304:
	/* 0x304: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_30b:
	/* 0x30b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_30e:
	/* 0x30e: jmp    281c <tail_lb_ipv4+0x281c> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_313:
	/* 0x313: mov    QWORD PTR [rsp+0x80],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_31b:
	/* 0x31b: mov    QWORD PTR [rsp+0x98],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_323:
	/* 0x323: mov    QWORD PTR [rsp+0x20],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_328:
	/* 0x328: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32a:
	/* 0x32a: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_332:
	/* 0x332: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_339:
	/* 0x339: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33e:
	/* 0x33e: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_344:
	/* 0x344: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_347:
	/* 0x347: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34a:
	/* 0x34a: je     350 <tail_lb_ipv4+0x350> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_350;
	}
x86_l_34c:
	/* 0x34c: mov    r12d,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_350:
	/* 0x350: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_358:
	/* 0x358: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_35f:
	/* 0x35f: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_364:
	/* 0x364: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_367:
	/* 0x367: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36a:
	/* 0x36a: je     374 <tail_lb_ipv4+0x374> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_374;
	}
x86_l_36c:
	/* 0x36c: or     r12d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_370:
	/* 0x370: mov    DWORD PTR [rax+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_374:
	/* 0x374: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_377:
	/* 0x377: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_37c:
	/* 0x37c: je     510 <tail_lb_ipv4+0x510> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_510;
	}
x86_l_382:
	/* 0x382: mov    rax,QWORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rsp+0x2e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_38c:
	/* 0x38c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_391:
	/* 0x391: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_396:
	/* 0x396: movzx  r14d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_39c:
	/* 0x39c: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_3a0:
	/* 0x3a0: jne    602 <tail_lb_ipv4+0x602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_602;
	}
x86_l_3a6:
	/* 0x3a6: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a8:
	/* 0x3a8: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ab:
	/* 0x3ab: movzx  ecx,BYTE PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_3b3:
	/* 0x3b3: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3b7:
	/* 0x3b7: add    rsi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_3bb:
	/* 0x3bb: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_3c0:
	/* 0x3c0: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3c3:
	/* 0x3c3: ja     2b7 <tail_lb_ipv4+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b7;
	}
x86_l_3c9:
	/* 0x3c9: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3cc:
	/* 0x3cc: movzx  eax,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3d0:
	/* 0x3d0: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d4:
	/* 0x3d4: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3d8:
	/* 0x3d8: mov    DWORD PTR [rsp+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3dc:
	/* 0x3dc: mov    DWORD PTR [rsp+0x28],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3e0:
	/* 0x3e0: rol    DWORD PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 206158430224ULL);
x86_l_3e5:
	/* 0x3e5: xor    BYTE PTR [rsp+0x35],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 227633266689ULL);
x86_l_3ea:
	/* 0x3ea: test   eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_3ef:
	/* 0x3ef: jne    602 <tail_lb_ipv4+0x602> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_602;
	}
x86_l_3f5:
	/* 0x3f5: cmp    BYTE PTR [rsp+0x34],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 223338299398ULL);
x86_l_3fa:
	/* 0x3fa: jne    6af <tail_lb_ipv4+0x6af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_6af;
	}
x86_l_400:
	/* 0x400: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_403:
	/* 0x403: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_40a:
	/* 0x40a: jmp    6b9 <tail_lb_ipv4+0x6b9> */
	goto x86_l_6b9;
x86_l_40f:
	/* 0x40f: mov    QWORD PTR [rsp+0x98],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_417:
	/* 0x417: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41a:
	/* 0x41a: test   r9,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R8, X86_WIDTH_64);
x86_l_41d:
	/* 0x41d: jne    14a1 <tail_lb_ipv4+0x14a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5281ULL;
	}
x86_l_423:
	/* 0x423: mov    QWORD PTR [rsp+0x80],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_42b:
	/* 0x42b: movzx  esi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_42f:
	/* 0x42f: lea    rdi,[r15+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_433:
	/* 0x433: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_437:
	/* 0x437: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_43c:
	/* 0x43c: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_43f:
	/* 0x43f: ja     b5 <tail_lb_ipv4+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b5;
	}
x86_l_445:
	/* 0x445: mov    QWORD PTR [rsp+0x20],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44a:
	/* 0x44a: add    rsi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_44d:
	/* 0x44d: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44f:
	/* 0x44f: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_453:
	/* 0x453: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_456:
	/* 0x456: jmp    48e <tail_lb_ipv4+0x48e> */
	goto x86_l_48e;
x86_l_458:
	/* 0x458: mov    QWORD PTR [rsp+0x80],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_460:
	/* 0x460: lea    rax,[r15+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_464:
	/* 0x464: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_466:
	/* 0x466: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46a:
	/* 0x46a: mov    QWORD PTR [rsp+0x98],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_472:
	/* 0x472: test   r9,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R10, X86_WIDTH_64);
x86_l_475:
	/* 0x475: jne    14ab <tail_lb_ipv4+0x14ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5291ULL;
	}
x86_l_47b:
	/* 0x47b: mov    QWORD PTR [rsp+0x20],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_480:
	/* 0x480: movzx  ecx,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_485:
	/* 0x485: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_489:
	/* 0x489: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_48e:
	/* 0x48e: mov    BYTE PTR [rsp+0x68],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_492:
	/* 0x492: mov    DWORD PTR [rsp+0x60],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_496:
	/* 0x496: mov    WORD PTR [rsp+0x64],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_49b:
	/* 0x49b: mov    WORD PTR [rsp+0x66],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 438086664192ULL);
x86_l_4a2:
	/* 0x4a2: mov    BYTE PTR [rsp+0x69],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 450971566080ULL);
x86_l_4a7:
	/* 0x4a7: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_4ae:
	/* 0x4ae: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4b3:
	/* 0x4b3: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_4b9:
	/* 0x4b9: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_4bc:
	/* 0x4bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bf:
	/* 0x4bf: jne    4f4 <tail_lb_ipv4+0x4f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4f4;
	}
x86_l_4c1:
	/* 0x4c1: movzx  ebp,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_4c6:
	/* 0x4c6: movzx  eax,WORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 100ULL);
x86_l_4cb:
	/* 0x4cb: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d0:
	/* 0x4d0: mov    WORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_4d7:
	/* 0x4d7: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4dc:
	/* 0x4dc: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_4e3:
	/* 0x4e3: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4e8:
	/* 0x4e8: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_4eb:
	/* 0x4eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ee:
	/* 0x4ee: je     673 <tail_lb_ipv4+0x673> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_673;
	}
x86_l_4f4:
	/* 0x4f4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f7:
	/* 0x4f7: cmp    WORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_4fd:
	/* 0x4fd: jne    55c <tail_lb_ipv4+0x55c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_55c;
	}
x86_l_4ff:
	/* 0x4ff: cmp    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_504:
	/* 0x504: jne    55c <tail_lb_ipv4+0x55c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_55c;
	}
x86_l_506:
	/* 0x506: mov    ebp,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967138ULL);
x86_l_50b:
	/* 0x50b: jmp    b5 <tail_lb_ipv4+0xb5> */
	goto x86_l_b5;
x86_l_510:
	/* 0x510: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_518:
	/* 0x518: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_51f:
	/* 0x51f: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_524:
	/* 0x524: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_529:
	/* 0x529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b:
	/* 0x52b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: je     536 <tail_lb_ipv4+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_536;
	}
x86_l_530:
	/* 0x530: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_536:
	/* 0x536: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_53d:
	/* 0x53d: mov    r14d,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 36ULL);
x86_l_543:
	/* 0x543: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_548:
	/* 0x548: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_54b:
	/* 0x54b: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_550:
	/* 0x550: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_552:
	/* 0x552: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_557:
	/* 0x557: jmp    b5 <tail_lb_ipv4+0xb5> */
	goto x86_l_b5;
x86_l_55c:
	/* 0x55c: cmp    BYTE PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_560:
	/* 0x560: jns    5bc <tail_lb_ipv4+0x5bc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_5bc;
	}
x86_l_562:
	/* 0x562: mov    ecx,DWORD PTR [r15+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_566:
	/* 0x566: movzx  edx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_56a:
	/* 0x56a: mov    DWORD PTR [rsp+0x28],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691904ULL);
x86_l_572:
	/* 0x572: mov    WORD PTR [rsp+0x2c],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_577:
	/* 0x577: mov    WORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_57e:
	/* 0x57e: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_582:
	/* 0x582: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_source_range)));
x86_l_589:
	/* 0x589: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_58e:
	/* 0x58e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_593:
	/* 0x593: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_596:
	/* 0x596: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_598:
	/* 0x598: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_59b:
	/* 0x59b: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_59e:
	/* 0x59e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_5a1:
	/* 0x5a1: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_5a4:
	/* 0x5a4: movzx  edx,BYTE PTR [r15+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_5a9:
	/* 0x5a9: and    dl,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_AND, 64ULL);
x86_l_5ac:
	/* 0x5ac: shr    dl,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_SHR, 6ULL);
x86_l_5af:
	/* 0x5af: mov    ebp,0xffffff4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967119ULL);
x86_l_5b4:
	/* 0x5b4: cmp    cl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_8);
x86_l_5b6:
	/* 0x5b6: je     b5 <tail_lb_ipv4+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5;
	}
x86_l_5bc:
	/* 0x5bc: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_5c0:
	/* 0x5c0: mov    ebp,0xffffff52 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967122ULL);
x86_l_5c5:
	/* 0x5c5: test   cl,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_5c8:
	/* 0x5c8: je     b5 <tail_lb_ipv4+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b5;
	}
x86_l_5ce:
	/* 0x5ce: test   cl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_5d1:
	/* 0x5d1: jne    33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33;
	}
x86_l_5d7:
	/* 0x5d7: test   BYTE PTR [rax+0x9],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705668ULL);
x86_l_5db:
	/* 0x5db: je     5e6 <tail_lb_ipv4+0x5e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5e6;
	}
x86_l_5dd:
	/* 0x5dd: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e0:
	/* 0x5e0: jne    33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_33;
	}
x86_l_5e6:
	/* 0x5e6: movzx  r13d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_5ec:
	/* 0x5ec: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_5f0:
	/* 0x5f0: jne    799 <tail_lb_ipv4+0x799> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1945ULL;
	}
x86_l_5f6:
	/* 0x5f6: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_5fd:
	/* 0x5fd: jmp    7a0 <tail_lb_ipv4+0x7a0> */
	return 1952ULL;
x86_l_602:
	/* 0x602: movzx  eax,BYTE PTR [r15+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_607:
	/* 0x607: and    al,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 15ULL);
x86_l_609:
	/* 0x609: cmp    al,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 7ULL);
x86_l_60b:
	/* 0x60b: jb     659 <tail_lb_ipv4+0x659> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_659;
	}
x86_l_60d:
	/* 0x60d: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60f:
	/* 0x60f: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_612:
	/* 0x612: lea    rdx,[rax+0x2a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_616:
	/* 0x616: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_61b:
	/* 0x61b: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_61e:
	/* 0x61e: ja     2b7 <tail_lb_ipv4+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2b7;
	}
x86_l_624:
	/* 0x624: mov    rcx,QWORD PTR [rax+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_628:
	/* 0x628: movzx  eax,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_62b:
	/* 0x62b: cmp    eax,0x89a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2202ULL);
x86_l_630:
	/* 0x630: jne    659 <tail_lb_ipv4+0x659> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_659;
	}
x86_l_632:
	/* 0x632: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_635:
	/* 0x635: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_639:
	/* 0x639: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_63c:
	/* 0x63c: movbe  DWORD PTR [rsp+0x60],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 96ULL);
x86_l_642:
	/* 0x642: bswap  eax */
	X86_SIM_RUN_OP(X86_OP_BSWAP, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 0);
x86_l_644:
	/* 0x644: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_649:
	/* 0x649: movbe  WORD PTR [rsp+0x64],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 100ULL);
x86_l_650:
	/* 0x650: rol    cx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_654:
	/* 0x654: jmp    6f8 <tail_lb_ipv4+0x6f8> */
	return 1784ULL;
x86_l_659:
	/* 0x659: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_65d:
	/* 0x65d: jne    876 <tail_lb_ipv4+0x876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2166ULL;
	}
x86_l_663:
	/* 0x663: cmp    BYTE PTR [rsp+0x34],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 223338299398ULL);
x86_l_668:
	/* 0x668: jne    68a <tail_lb_ipv4+0x68a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_68a;
	}
x86_l_66a:
	/* 0x66a: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_671:
	/* 0x671: jmp    691 <tail_lb_ipv4+0x691> */
	goto x86_l_691;
x86_l_673:
	/* 0x673: mov    BYTE PTR [rsp+0x68],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_678:
	/* 0x678: movzx  eax,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_67d:
	/* 0x67d: mov    WORD PTR [rsp+0x64],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_682:
	/* 0x682: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_685:
	/* 0x685: jmp    32a <tail_lb_ipv4+0x32a> */
	goto x86_l_32a;
x86_l_68a:
	/* 0x68a: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_691:
	/* 0x691: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_696:
	/* 0x696: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_69b:
	/* 0x69b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69d:
	/* 0x69d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a0:
	/* 0x6a0: je     876 <tail_lb_ipv4+0x876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2166ULL;
	}
x86_l_6a6:
	/* 0x6a6: and    BYTE PTR [rax+0x24],0x7f */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 154618822783ULL);
x86_l_6aa:
	/* 0x6aa: jmp    876 <tail_lb_ipv4+0x876> */
	return 2166ULL;
x86_l_6af:
	/* 0x6af: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_6b9:
	/* 0x6b9: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_6be:
	/* 0x6be: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6c3:
	/* 0x6c3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c8:
	/* 0x6c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
	return 1738ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1738ULL: goto x86_l_6ca;
	case 1741ULL: goto x86_l_6cd;
	case 1747ULL: goto x86_l_6d3;
	case 1751ULL: goto x86_l_6d7;
	case 1758ULL: goto x86_l_6de;
	case 1764ULL: goto x86_l_6e4;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1779ULL: goto x86_l_6f3;
	case 1781ULL: goto x86_l_6f5;
	case 1784ULL: goto x86_l_6f8;
	case 1790ULL: goto x86_l_6fe;
	case 1795ULL: goto x86_l_703;
	case 1799ULL: goto x86_l_707;
	case 1801ULL: goto x86_l_709;
	case 1808ULL: goto x86_l_710;
	case 1810ULL: goto x86_l_712;
	case 1817ULL: goto x86_l_719;
	case 1825ULL: goto x86_l_721;
	case 1830ULL: goto x86_l_726;
	case 1837ULL: goto x86_l_72d;
	case 1840ULL: goto x86_l_730;
	case 1846ULL: goto x86_l_736;
	case 1854ULL: goto x86_l_73e;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1869ULL: goto x86_l_74d;
	case 1878ULL: goto x86_l_756;
	case 1881ULL: goto x86_l_759;
	case 1890ULL: goto x86_l_762;
	case 1900ULL: goto x86_l_76c;
	case 1905ULL: goto x86_l_771;
	case 1912ULL: goto x86_l_778;
	case 1917ULL: goto x86_l_77d;
	case 1922ULL: goto x86_l_782;
	case 1924ULL: goto x86_l_784;
	case 1927ULL: goto x86_l_787;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1940ULL: goto x86_l_794;
	case 1945ULL: goto x86_l_799;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1967ULL: goto x86_l_7af;
	case 1975ULL: goto x86_l_7b7;
	case 1982ULL: goto x86_l_7be;
	case 1987ULL: goto x86_l_7c3;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2004ULL: goto x86_l_7d4;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2020ULL: goto x86_l_7e4;
	case 2023ULL: goto x86_l_7e7;
	case 2031ULL: goto x86_l_7ef;
	case 2039ULL: goto x86_l_7f7;
	case 2045ULL: goto x86_l_7fd;
	case 2048ULL: goto x86_l_800;
	case 2054ULL: goto x86_l_806;
	case 2059ULL: goto x86_l_80b;
	case 2062ULL: goto x86_l_80e;
	case 2065ULL: goto x86_l_811;
	case 2068ULL: goto x86_l_814;
	case 2071ULL: goto x86_l_817;
	case 2073ULL: goto x86_l_819;
	case 2077ULL: goto x86_l_81d;
	case 2080ULL: goto x86_l_820;
	case 2089ULL: goto x86_l_829;
	case 2098ULL: goto x86_l_832;
	case 2108ULL: goto x86_l_83c;
	case 2114ULL: goto x86_l_842;
	case 2119ULL: goto x86_l_847;
	case 2126ULL: goto x86_l_84e;
	case 2131ULL: goto x86_l_853;
	case 2136ULL: goto x86_l_858;
	case 2138ULL: goto x86_l_85a;
	case 2141ULL: goto x86_l_85d;
	case 2147ULL: goto x86_l_863;
	case 2150ULL: goto x86_l_866;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2166ULL: goto x86_l_876;
	case 2174ULL: goto x86_l_87e;
	case 2181ULL: goto x86_l_885;
	case 2186ULL: goto x86_l_88a;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2206ULL: goto x86_l_89e;
	case 2210ULL: goto x86_l_8a2;
	case 2214ULL: goto x86_l_8a6;
	case 2223ULL: goto x86_l_8af;
	case 2232ULL: goto x86_l_8b8;
	case 2239ULL: goto x86_l_8bf;
	case 2243ULL: goto x86_l_8c3;
	case 2252ULL: goto x86_l_8cc;
	case 2261ULL: goto x86_l_8d5;
	case 2268ULL: goto x86_l_8dc;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2281ULL: goto x86_l_8e9;
	case 2289ULL: goto x86_l_8f1;
	case 2293ULL: goto x86_l_8f5;
	case 2298ULL: goto x86_l_8fa;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2313ULL: goto x86_l_909;
	case 2316ULL: goto x86_l_90c;
	case 2322ULL: goto x86_l_912;
	case 2325ULL: goto x86_l_915;
	case 2330ULL: goto x86_l_91a;
	case 2335ULL: goto x86_l_91f;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2356ULL: goto x86_l_934;
	case 2361ULL: goto x86_l_939;
	case 2366ULL: goto x86_l_93e;
	case 2371ULL: goto x86_l_943;
	case 2373ULL: goto x86_l_945;
	case 2375ULL: goto x86_l_947;
	case 2378ULL: goto x86_l_94a;
	case 2381ULL: goto x86_l_94d;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2393ULL: goto x86_l_959;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2408ULL: goto x86_l_968;
	case 2410ULL: goto x86_l_96a;
	case 2413ULL: goto x86_l_96d;
	case 2417ULL: goto x86_l_971;
	case 2421ULL: goto x86_l_975;
	case 2425ULL: goto x86_l_979;
	case 2428ULL: goto x86_l_97c;
	case 2434ULL: goto x86_l_982;
	case 2437ULL: goto x86_l_985;
	case 2442ULL: goto x86_l_98a;
	case 2445ULL: goto x86_l_98d;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2458ULL: goto x86_l_99a;
	case 2461ULL: goto x86_l_99d;
	case 2468ULL: goto x86_l_9a4;
	case 2474ULL: goto x86_l_9aa;
	case 2477ULL: goto x86_l_9ad;
	case 2479ULL: goto x86_l_9af;
	case 2482ULL: goto x86_l_9b2;
	case 2487ULL: goto x86_l_9b7;
	case 2492ULL: goto x86_l_9bc;
	case 2495ULL: goto x86_l_9bf;
	case 2497ULL: goto x86_l_9c1;
	case 2500ULL: goto x86_l_9c4;
	case 2502ULL: goto x86_l_9c6;
	case 2506ULL: goto x86_l_9ca;
	case 2508ULL: goto x86_l_9cc;
	case 2510ULL: goto x86_l_9ce;
	case 2517ULL: goto x86_l_9d5;
	case 2519ULL: goto x86_l_9d7;
	case 2527ULL: goto x86_l_9df;
	case 2530ULL: goto x86_l_9e2;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2548ULL: goto x86_l_9f4;
	case 2550ULL: goto x86_l_9f6;
	case 2553ULL: goto x86_l_9f9;
	case 2559ULL: goto x86_l_9ff;
	case 2566ULL: goto x86_l_a06;
	case 2569ULL: goto x86_l_a09;
	case 2575ULL: goto x86_l_a0f;
	case 2582ULL: goto x86_l_a16;
	case 2586ULL: goto x86_l_a1a;
	case 2590ULL: goto x86_l_a1e;
	case 2595ULL: goto x86_l_a23;
	case 2604ULL: goto x86_l_a2c;
	case 2609ULL: goto x86_l_a31;
	case 2616ULL: goto x86_l_a38;
	case 2621ULL: goto x86_l_a3d;
	case 2626ULL: goto x86_l_a42;
	case 2631ULL: goto x86_l_a47;
	case 2633ULL: goto x86_l_a49;
	case 2635ULL: goto x86_l_a4b;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2644ULL: goto x86_l_a54;
	case 2647ULL: goto x86_l_a57;
	case 2655ULL: goto x86_l_a5f;
	case 2661ULL: goto x86_l_a65;
	case 2663ULL: goto x86_l_a67;
	case 2667ULL: goto x86_l_a6b;
	case 2669ULL: goto x86_l_a6d;
	case 2672ULL: goto x86_l_a70;
	case 2678ULL: goto x86_l_a76;
	case 2688ULL: goto x86_l_a80;
	case 2691ULL: goto x86_l_a83;
	case 2693ULL: goto x86_l_a85;
	case 2695ULL: goto x86_l_a87;
	case 2698ULL: goto x86_l_a8a;
	case 2701ULL: goto x86_l_a8d;
	case 2705ULL: goto x86_l_a91;
	case 2709ULL: goto x86_l_a95;
	case 2713ULL: goto x86_l_a99;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2723ULL: goto x86_l_aa3;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2734ULL: goto x86_l_aae;
	case 2736ULL: goto x86_l_ab0;
	case 2739ULL: goto x86_l_ab3;
	case 2743ULL: goto x86_l_ab7;
	case 2745ULL: goto x86_l_ab9;
	case 2751ULL: goto x86_l_abf;
	case 2754ULL: goto x86_l_ac2;
	case 2760ULL: goto x86_l_ac8;
	case 2763ULL: goto x86_l_acb;
	case 2769ULL: goto x86_l_ad1;
	case 2775ULL: goto x86_l_ad7;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2789ULL: goto x86_l_ae5;
	case 2794ULL: goto x86_l_aea;
	case 2799ULL: goto x86_l_aef;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2811ULL: goto x86_l_afb;
	case 2816ULL: goto x86_l_b00;
	case 2819ULL: goto x86_l_b03;
	case 2825ULL: goto x86_l_b09;
	case 2830ULL: goto x86_l_b0e;
	case 2836ULL: goto x86_l_b14;
	case 2842ULL: goto x86_l_b1a;
	case 2848ULL: goto x86_l_b20;
	case 2852ULL: goto x86_l_b24;
	case 2858ULL: goto x86_l_b2a;
	case 2865ULL: goto x86_l_b31;
	case 2868ULL: goto x86_l_b34;
	case 2874ULL: goto x86_l_b3a;
	case 2880ULL: goto x86_l_b40;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2894ULL: goto x86_l_b4e;
	case 2898ULL: goto x86_l_b52;
	case 2901ULL: goto x86_l_b55;
	case 2905ULL: goto x86_l_b59;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2920ULL: goto x86_l_b68;
	case 2926ULL: goto x86_l_b6e;
	case 2930ULL: goto x86_l_b72;
	case 2932ULL: goto x86_l_b74;
	case 2935ULL: goto x86_l_b77;
	case 2937ULL: goto x86_l_b79;
	case 2940ULL: goto x86_l_b7c;
	case 2943ULL: goto x86_l_b7f;
	case 2945ULL: goto x86_l_b81;
	case 2949ULL: goto x86_l_b85;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2963ULL: goto x86_l_b93;
	case 2967ULL: goto x86_l_b97;
	case 2970ULL: goto x86_l_b9a;
	case 2972ULL: goto x86_l_b9c;
	case 2979ULL: goto x86_l_ba3;
	case 2983ULL: goto x86_l_ba7;
	case 2987ULL: goto x86_l_bab;
	case 2992ULL: goto x86_l_bb0;
	case 2996ULL: goto x86_l_bb4;
	case 2999ULL: goto x86_l_bb7;
	case 3002ULL: goto x86_l_bba;
	case 3004ULL: goto x86_l_bbc;
	case 3009ULL: goto x86_l_bc1;
	case 3011ULL: goto x86_l_bc3;
	case 3013ULL: goto x86_l_bc5;
	case 3016ULL: goto x86_l_bc8;
	case 3020ULL: goto x86_l_bcc;
	case 3022ULL: goto x86_l_bce;
	case 3027ULL: goto x86_l_bd3;
	case 3029ULL: goto x86_l_bd5;
	case 3031ULL: goto x86_l_bd7;
	case 3035ULL: goto x86_l_bdb;
	case 3045ULL: goto x86_l_be5;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3057ULL: goto x86_l_bf1;
	case 3060ULL: goto x86_l_bf4;
	case 3065ULL: goto x86_l_bf9;
	case 3069ULL: goto x86_l_bfd;
	case 3073ULL: goto x86_l_c01;
	case 3076ULL: goto x86_l_c04;
	case 3080ULL: goto x86_l_c08;
	case 3087ULL: goto x86_l_c0f;
	case 3090ULL: goto x86_l_c12;
	case 3092ULL: goto x86_l_c14;
	case 3099ULL: goto x86_l_c1b;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3107ULL: goto x86_l_c23;
	case 3109ULL: goto x86_l_c25;
	case 3114ULL: goto x86_l_c2a;
	case 3116ULL: goto x86_l_c2c;
	case 3119ULL: goto x86_l_c2f;
	case 3121ULL: goto x86_l_c31;
	case 3123ULL: goto x86_l_c33;
	case 3126ULL: goto x86_l_c36;
	case 3128ULL: goto x86_l_c38;
	case 3132ULL: goto x86_l_c3c;
	case 3135ULL: goto x86_l_c3f;
	case 3142ULL: goto x86_l_c46;
	case 3144ULL: goto x86_l_c48;
	case 3151ULL: goto x86_l_c4f;
	case 3154ULL: goto x86_l_c52;
	case 3156ULL: goto x86_l_c54;
	case 3161ULL: goto x86_l_c59;
	case 3163ULL: goto x86_l_c5b;
	case 3166ULL: goto x86_l_c5e;
	case 3169ULL: goto x86_l_c61;
	case 3174ULL: goto x86_l_c66;
	case 3178ULL: goto x86_l_c6a;
	case 3180ULL: goto x86_l_c6c;
	case 3184ULL: goto x86_l_c70;
	case 3190ULL: goto x86_l_c76;
	case 3194ULL: goto x86_l_c7a;
	case 3197ULL: goto x86_l_c7d;
	case 3203ULL: goto x86_l_c83;
	case 3209ULL: goto x86_l_c89;
	case 3215ULL: goto x86_l_c8f;
	case 3218ULL: goto x86_l_c92;
	case 3222ULL: goto x86_l_c96;
	case 3229ULL: goto x86_l_c9d;
	case 3232ULL: goto x86_l_ca0;
	case 3238ULL: goto x86_l_ca6;
	case 3245ULL: goto x86_l_cad;
	case 3249ULL: goto x86_l_cb1;
	case 3253ULL: goto x86_l_cb5;
	case 3258ULL: goto x86_l_cba;
	case 3261ULL: goto x86_l_cbd;
	case 3267ULL: goto x86_l_cc3;
	case 3271ULL: goto x86_l_cc7;
	case 3275ULL: goto x86_l_ccb;
	case 3279ULL: goto x86_l_ccf;
	case 3283ULL: goto x86_l_cd3;
	case 3287ULL: goto x86_l_cd7;
	case 3294ULL: goto x86_l_cde;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3305ULL: goto x86_l_ce9;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3323ULL: goto x86_l_cfb;
	case 3330ULL: goto x86_l_d02;
	case 3332ULL: goto x86_l_d04;
	case 3334ULL: goto x86_l_d06;
	case 3338ULL: goto x86_l_d0a;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3360ULL: goto x86_l_d20;
	case 3363ULL: goto x86_l_d23;
	case 3365ULL: goto x86_l_d25;
	case 3370ULL: goto x86_l_d2a;
	case 3372ULL: goto x86_l_d2c;
	case 3374ULL: goto x86_l_d2e;
	case 3378ULL: goto x86_l_d32;
	case 3380ULL: goto x86_l_d34;
	case 3385ULL: goto x86_l_d39;
	case 3387ULL: goto x86_l_d3b;
	case 3389ULL: goto x86_l_d3d;
	case 3393ULL: goto x86_l_d41;
	case 3403ULL: goto x86_l_d4b;
	case 3406ULL: goto x86_l_d4e;
	case 3411ULL: goto x86_l_d53;
	case 3415ULL: goto x86_l_d57;
	case 3418ULL: goto x86_l_d5a;
	case 3423ULL: goto x86_l_d5f;
	case 3426ULL: goto x86_l_d62;
	case 3432ULL: goto x86_l_d68;
	case 3438ULL: goto x86_l_d6e;
	case 3441ULL: goto x86_l_d71;
	case 3443ULL: goto x86_l_d73;
	case 3445ULL: goto x86_l_d75;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6ca:
	/* 0x6ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6cd:
	/* 0x6cd: je     86f <tail_lb_ipv4+0x86f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_86f;
	}
x86_l_6d3:
	/* 0x6d3: cmp    BYTE PTR [rax+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_6d7:
	/* 0x6d7: mov    WORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_6de:
	/* 0x6de: jns    876 <tail_lb_ipv4+0x876> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_876;
	}
x86_l_6e4:
	/* 0x6e4: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6e8:
	/* 0x6e8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ed:
	/* 0x6ed: movzx  r14d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_6f3:
	/* 0x6f3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f5:
	/* 0x6f5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_6f8:
	/* 0x6f8: rol    QWORD PTR [rsp+0x8],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 34359738400ULL);
x86_l_6fe:
	/* 0x6fe: rol    DWORD PTR [rsp+0x10],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 68719476752ULL);
x86_l_703:
	/* 0x703: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_707:
	/* 0x707: jne    712 <tail_lb_ipv4+0x712> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_712;
	}
x86_l_709:
	/* 0x709: mov    rbp,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_710:
	/* 0x710: jmp    719 <tail_lb_ipv4+0x719> */
	goto x86_l_719;
x86_l_712:
	/* 0x712: mov    rbp,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_719:
	/* 0x719: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_721:
	/* 0x721: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_726:
	/* 0x726: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_72d:
	/* 0x72d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_730:
	/* 0x730: je     94a <tail_lb_ipv4+0x94a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94a;
	}
x86_l_736:
	/* 0x736: and    QWORD PTR [rsp+0x98],rdi */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 152ULL);
x86_l_73e:
	/* 0x73e: je     94a <tail_lb_ipv4+0x94a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_94a;
	}
x86_l_744:
	/* 0x744: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_747:
	/* 0x747: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_749:
	/* 0x749: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_74d:
	/* 0x74d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_756:
	/* 0x756: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_759:
	/* 0x759: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_762:
	/* 0x762: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_76c:
	/* 0x76c: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_771:
	/* 0x771: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_778:
	/* 0x778: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_77d:
	/* 0x77d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_782:
	/* 0x782: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_784:
	/* 0x784: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_787:
	/* 0x787: je     91f <tail_lb_ipv4+0x91f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_91f;
	}
x86_l_78d:
	/* 0x78d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_790:
	/* 0x790: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_794:
	/* 0x794: jmp    947 <tail_lb_ipv4+0x947> */
	goto x86_l_947;
x86_l_799:
	/* 0x799: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_7a0:
	/* 0x7a0: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7a5:
	/* 0x7a5: movabs rcx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1099511627776ULL);
x86_l_7af:
	/* 0x7af: mov    r10,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7b7:
	/* 0x7b7: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_7be:
	/* 0x7be: movzx  esi,BYTE PTR [rsp+0x15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 21ULL);
x86_l_7c3:
	/* 0x7c3: mov    BYTE PTR [rsp+0x90],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7cb:
	/* 0x7cb: movzx  r12d,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_7d0:
	/* 0x7d0: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_7d4:
	/* 0x7d4: mov    QWORD PTR [rsp+0xa8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7dc:
	/* 0x7dc: mov    BYTE PTR [rsp+0x15],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313220ULL);
x86_l_7e1:
	/* 0x7e1: and    rcx,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_7e4:
	/* 0x7e4: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e7:
	/* 0x7e7: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7ef:
	/* 0x7ef: mov    QWORD PTR [rsp+0x88],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7f7:
	/* 0x7f7: je     a65 <tail_lb_ipv4+0xa65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a65;
	}
x86_l_7fd:
	/* 0x7fd: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_800:
	/* 0x800: je     a65 <tail_lb_ipv4+0xa65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a65;
	}
x86_l_806:
	/* 0x806: mov    BYTE PTR [rsp+0x18],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_80b:
	/* 0x80b: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_80e:
	/* 0x80e: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_811:
	/* 0x811: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_814:
	/* 0x814: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_817:
	/* 0x817: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_819:
	/* 0x819: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_81d:
	/* 0x81d: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_820:
	/* 0x820: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_829:
	/* 0x829: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_832:
	/* 0x832: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_83c:
	/* 0x83c: or     rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 256ULL);
x86_l_842:
	/* 0x842: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_847:
	/* 0x847: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_84e:
	/* 0x84e: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_853:
	/* 0x853: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_858:
	/* 0x858: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85a:
	/* 0x85a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: je     a23 <tail_lb_ipv4+0xa23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a23;
	}
x86_l_863:
	/* 0x863: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_866:
	/* 0x866: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_86a:
	/* 0x86a: jmp    a4b <tail_lb_ipv4+0xa4b> */
	goto x86_l_a4b;
x86_l_86f:
	/* 0x86f: mov    WORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_876:
	/* 0x876: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_87e:
	/* 0x87e: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_885:
	/* 0x885: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_88a:
	/* 0x88a: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_890:
	/* 0x890: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_893:
	/* 0x893: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_896:
	/* 0x896: je     89e <tail_lb_ipv4+0x89e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_89e;
	}
x86_l_898:
	/* 0x898: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89e:
	/* 0x89e: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a2:
	/* 0x8a2: mov    ecx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_8a6:
	/* 0x8a6: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_8af:
	/* 0x8af: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_8b8:
	/* 0x8b8: mov    WORD PTR [rsp+0x42],0xffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 283467907071ULL);
x86_l_8bf:
	/* 0x8bf: mov    DWORD PTR [rsp+0x44],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_8c3:
	/* 0x8c3: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_8cc:
	/* 0x8cc: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_8d5:
	/* 0x8d5: mov    WORD PTR [rsp+0x32],0xffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748430335ULL);
x86_l_8dc:
	/* 0x8dc: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8e0:
	/* 0x8e0: movzx  eax,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_8e5:
	/* 0x8e5: mov    BYTE PTR [rsp+0x4c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_8e9:
	/* 0x8e9: rorx   eax,DWORD PTR [rsp+0x10],0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 68719476752ULL);
x86_l_8f1:
	/* 0x8f1: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8f5:
	/* 0x8f5: mov    BYTE PTR [rsp+0x4d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 330712481793ULL);
x86_l_8fa:
	/* 0x8fa: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_901:
	/* 0x901: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_906:
	/* 0x906: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_909:
	/* 0x909: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90c:
	/* 0x90c: je     536 <tail_lb_ipv4+0x536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1334ULL;
	}
x86_l_912:
	/* 0x912: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_915:
	/* 0x915: mov    ebp,0xffffff5f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967135ULL);
x86_l_91a:
	/* 0x91a: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_91f:
	/* 0x91f: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_928:
	/* 0x928: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_92d:
	/* 0x92d: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_934:
	/* 0x934: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_939:
	/* 0x939: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_93e:
	/* 0x93e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_943:
	/* 0x943: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_945:
	/* 0x945: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_947:
	/* 0x947: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_94a:
	/* 0x94a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94d:
	/* 0x94d: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_951:
	/* 0x951: jne    9af <tail_lb_ipv4+0x9af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9af;
	}
x86_l_953:
	/* 0x953: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_959:
	/* 0x959: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_963:
	/* 0x963: and    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_966:
	/* 0x966: jne    9b2 <tail_lb_ipv4+0x9b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_9b2;
	}
x86_l_968:
	/* 0x968: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96a:
	/* 0x96a: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_96d:
	/* 0x96d: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_971:
	/* 0x971: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_975:
	/* 0x975: add    rsi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_979:
	/* 0x979: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: ja     a9e <tail_lb_ipv4+0xa9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a9e;
	}
x86_l_982:
	/* 0x982: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_985:
	/* 0x985: movzx  r15d,WORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_98a:
	/* 0x98a: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_98d:
	/* 0x98d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_992:
	/* 0x992: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_995:
	/* 0x995: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_99a:
	/* 0x99a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_99d:
	/* 0x99d: test   r15d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_32, 1280ULL);
x86_l_9a4:
	/* 0x9a4: jne    1567 <tail_lb_ipv4+0x1567> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5479ULL;
	}
x86_l_9aa:
	/* 0x9aa: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_9ad:
	/* 0x9ad: jmp    9b2 <tail_lb_ipv4+0x9b2> */
	goto x86_l_9b2;
x86_l_9af:
	/* 0x9af: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b2:
	/* 0x9b2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9b7:
	/* 0x9b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9bc:
	/* 0x9bc: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9bf:
	/* 0x9bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c1:
	/* 0x9c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c4:
	/* 0x9c4: je     9ce <tail_lb_ipv4+0x9ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9ce;
	}
x86_l_9c6:
	/* 0x9c6: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_9ca:
	/* 0x9ca: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_9cc:
	/* 0x9cc: js     9f2 <tail_lb_ipv4+0x9f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_9f2;
	}
x86_l_9ce:
	/* 0x9ce: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_9d5:
	/* 0x9d5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d7:
	/* 0x9d7: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9df:
	/* 0x9df: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9e2:
	/* 0x9e2: je     1d71 <tail_lb_ipv4+0x1d71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7537ULL;
	}
x86_l_9e8:
	/* 0x9e8: movzx  ebp,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_9ed:
	/* 0x9ed: jmp    126c <tail_lb_ipv4+0x126c> */
	return 4716ULL;
x86_l_9f2:
	/* 0x9f2: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_9f4:
	/* 0x9f4: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_9f6:
	/* 0x9f6: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_9f9:
	/* 0x9f9: je     c48 <tail_lb_ipv4+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c48;
	}
x86_l_9ff:
	/* 0x9ff: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a06:
	/* 0xa06: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a09:
	/* 0xa09: je     b68 <tail_lb_ipv4+0xb68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b68;
	}
x86_l_a0f:
	/* 0xa0f: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a16:
	/* 0xa16: imul   r13d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_a1a:
	/* 0xa1a: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a1e:
	/* 0xa1e: jmp    b6e <tail_lb_ipv4+0xb6e> */
	goto x86_l_b6e;
x86_l_a23:
	/* 0xa23: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_a2c:
	/* 0xa2c: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a31:
	/* 0xa31: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a38:
	/* 0xa38: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a3d:
	/* 0xa3d: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a42:
	/* 0xa42: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a47:
	/* 0xa47: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a49:
	/* 0xa49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4b:
	/* 0xa4b: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_a4e:
	/* 0xa4e: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_a51:
	/* 0xa51: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_a54:
	/* 0xa54: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_a57:
	/* 0xa57: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a5f:
	/* 0xa5f: movzx  r13d,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_a65:
	/* 0xa65: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a67:
	/* 0xa67: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_a6b:
	/* 0xa6b: jne    aab <tail_lb_ipv4+0xaab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_aab;
	}
x86_l_a6d:
	/* 0xa6d: mov    rcx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_a70:
	/* 0xa70: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_a76:
	/* 0xa76: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_a80:
	/* 0xa80: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_a83:
	/* 0xa83: jne    add <tail_lb_ipv4+0xadd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_add;
	}
x86_l_a85:
	/* 0xa85: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a87:
	/* 0xa87: mov    esi,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a8a:
	/* 0xa8a: mov    r9,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R10, X86_WIDTH_64);
x86_l_a8d:
	/* 0xa8d: movzx  edx,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a91:
	/* 0xa91: lea    r10,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_a95:
	/* 0xa95: add    r10,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_a99:
	/* 0xa99: cmp    r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_a9c:
	/* 0xa9c: jbe    ab0 <tail_lb_ipv4+0xab0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_ab0;
	}
x86_l_a9e:
	/* 0xa9e: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_aa3:
	/* 0xaa3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa6:
	/* 0xaa6: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_aab:
	/* 0xaab: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aae:
	/* 0xaae: jmp    add <tail_lb_ipv4+0xadd> */
	goto x86_l_add;
x86_l_ab0:
	/* 0xab0: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ab3:
	/* 0xab3: movzx  ebp,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_ab7:
	/* 0xab7: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_ab9:
	/* 0xab9: and    ecx,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_abf:
	/* 0xabf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac2:
	/* 0xac2: cmp    ecx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_ac8:
	/* 0xac8: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_acb:
	/* 0xacb: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_ad1:
	/* 0xad1: jne    1572 <tail_lb_ipv4+0x1572> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5490ULL;
	}
x86_l_ad7:
	/* 0xad7: mov    r15b,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_8);
x86_l_ada:
	/* 0xada: mov    r10,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_64);
x86_l_add:
	/* 0xadd: mov    QWORD PTR [rsp+0x80],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ae5:
	/* 0xae5: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aea:
	/* 0xaea: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aef:
	/* 0xaef: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_af4:
	/* 0xaf4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_af9:
	/* 0xaf9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_afb:
	/* 0xafb: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b00:
	/* 0xb00: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b03:
	/* 0xb03: je     1760 <tail_lb_ipv4+0x1760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5984ULL;
	}
x86_l_b09:
	/* 0xb09: cmp    WORD PTR [rax+0x26],r12w */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_b0e:
	/* 0xb0e: jne    1760 <tail_lb_ipv4+0x1760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5984ULL;
	}
x86_l_b14:
	/* 0xb14: test   ebp,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 512ULL);
x86_l_b1a:
	/* 0xb1a: je     d6e <tail_lb_ipv4+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b20:
	/* 0xb20: test   BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_b24:
	/* 0xb24: je     d6e <tail_lb_ipv4+0xd6e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d6e;
	}
x86_l_b2a:
	/* 0xb2a: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b31:
	/* 0xb31: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b34:
	/* 0xb34: mov    WORD PTR [rsp+0x6],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_b3a:
	/* 0xb3a: je     d13 <tail_lb_ipv4+0xd13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d13;
	}
x86_l_b40:
	/* 0xb40: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b47:
	/* 0xb47: mov    r14d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4a:
	/* 0xb4a: lea    edx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_b4e:
	/* 0xb4e: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_b52:
	/* 0xb52: sub    r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b55:
	/* 0xb55: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b59:
	/* 0xb59: jmp    d19 <tail_lb_ipv4+0xd19> */
	goto x86_l_d19;
x86_l_b5e:
	/* 0xb5e: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_b63:
	/* 0xb63: jmp    302 <tail_lb_ipv4+0x302> */
	return 770ULL;
x86_l_b68:
	/* 0xb68: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_b6e:
	/* 0xb6e: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_b72:
	/* 0xb72: jne    bab <tail_lb_ipv4+0xbab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bab;
	}
x86_l_b74:
	/* 0xb74: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_b77:
	/* 0xb77: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b79:
	/* 0xb79: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_b7c:
	/* 0xb7c: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_b7f:
	/* 0xb7f: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_b81:
	/* 0xb81: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b85:
	/* 0xb85: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_b88:
	/* 0xb88: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_b8d:
	/* 0xb8d: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_b93:
	/* 0xb93: cmove  r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_b97:
	/* 0xb97: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9a:
	/* 0xb9a: je     bab <tail_lb_ipv4+0xbab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bab;
	}
x86_l_b9c:
	/* 0xb9c: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ba3:
	/* 0xba3: imul   r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_ba7:
	/* 0xba7: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bab:
	/* 0xbab: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb0:
	/* 0xbb0: movzx  ebp,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bb4:
	/* 0xbb4: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bb7:
	/* 0xbb7: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bba:
	/* 0xbba: je     bce <tail_lb_ipv4+0xbce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_bce;
	}
x86_l_bbc:
	/* 0xbbc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bc1:
	/* 0xbc1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc3:
	/* 0xbc3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bc5:
	/* 0xbc5: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bc8:
	/* 0xbc8: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bcc:
	/* 0xbcc: jmp    bf1 <tail_lb_ipv4+0xbf1> */
	goto x86_l_bf1;
x86_l_bce:
	/* 0xbce: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_bd3:
	/* 0xbd3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd5:
	/* 0xbd5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bd7:
	/* 0xbd7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_bdb:
	/* 0xbdb: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_be5:
	/* 0xbe5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_be8:
	/* 0xbe8: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_bed:
	/* 0xbed: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_bf1:
	/* 0xbf1: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bf4:
	/* 0xbf4: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bf9:
	/* 0xbf9: mov    DWORD PTR [rax+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bfd:
	/* 0xbfd: movzx  edx,BYTE PTR [rax+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_c01:
	/* 0xc01: mov    esi,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c04:
	/* 0xc04: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c08:
	/* 0xc08: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c0f:
	/* 0xc0f: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c12:
	/* 0xc12: je     c25 <tail_lb_ipv4+0xc25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c25;
	}
x86_l_c14:
	/* 0xc14: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c1b:
	/* 0xc1b: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1d:
	/* 0xc1d: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_c20:
	/* 0xc20: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c23:
	/* 0xc23: jmp    c2a <tail_lb_ipv4+0xc2a> */
	goto x86_l_c2a;
x86_l_c25:
	/* 0xc25: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_c2a:
	/* 0xc2a: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c2c:
	/* 0xc2c: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c2f:
	/* 0xc2f: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_c31:
	/* 0xc31: jb     c38 <tail_lb_ipv4+0xc38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c38;
	}
x86_l_c33:
	/* 0xc33: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_c36:
	/* 0xc36: je     c48 <tail_lb_ipv4+0xc48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c48;
	}
x86_l_c38:
	/* 0xc38: mov    BYTE PTR [rax+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_c3c:
	/* 0xc3c: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c3f:
	/* 0xc3f: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c46:
	/* 0xc46: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c48:
	/* 0xc48: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_c4f:
	/* 0xc4f: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c52:
	/* 0xc52: je     c66 <tail_lb_ipv4+0xc66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c66;
	}
x86_l_c54:
	/* 0xc54: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_c59:
	/* 0xc59: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c5b:
	/* 0xc5b: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c5e:
	/* 0xc5e: sub    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_c61:
	/* 0xc61: add QWORD PTR [rax+0x18],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_c66:
	/* 0xc66: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_c6a:
	/* 0xc6a: je     cba <tail_lb_ipv4+0xcba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_cba;
	}
x86_l_c6c:
	/* 0xc6c: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_c70:
	/* 0xc70: jne    124d <tail_lb_ipv4+0x124d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4685ULL;
	}
x86_l_c76:
	/* 0xc76: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_c7a:
	/* 0xc7a: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_c7d:
	/* 0xc7d: je     124d <tail_lb_ipv4+0x124d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4685ULL;
	}
x86_l_c83:
	/* 0xc83: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_c89:
	/* 0xc89: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_c8f:
	/* 0xc8f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_c92:
	/* 0xc92: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c96:
	/* 0xc96: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c9d:
	/* 0xc9d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca0:
	/* 0xca0: je     159b <tail_lb_ipv4+0x159b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5531ULL;
	}
x86_l_ca6:
	/* 0xca6: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_cad:
	/* 0xcad: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_cb1:
	/* 0xcb1: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_cb5:
	/* 0xcb5: jmp    15a1 <tail_lb_ipv4+0x15a1> */
	return 5537ULL;
x86_l_cba:
	/* 0xcba: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_cbd:
	/* 0xcbd: and    ecx,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_cc3:
	/* 0xcc3: cmp    cx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 1ULL);
x86_l_cc7:
	/* 0xcc7: mov    cx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_16, 3ULL);
x86_l_ccb:
	/* 0xccb: sbb    cx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_ccf:
	/* 0xccf: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_cd3:
	/* 0xcd3: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cd7:
	/* 0xcd7: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_cde:
	/* 0xcde: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce0:
	/* 0xce0: test   cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_ce3:
	/* 0xce3: je     124d <tail_lb_ipv4+0x124d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4685ULL;
	}
x86_l_ce9:
	/* 0xce9: mov    r12,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_cf0:
	/* 0xcf0: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf5:
	/* 0xcf5: je     11b4 <tail_lb_ipv4+0x11b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4532ULL;
	}
x86_l_cfb:
	/* 0xcfb: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d02:
	/* 0xd02: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d04:
	/* 0xd04: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d06:
	/* 0xd06: lea    r13d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_d0a:
	/* 0xd0a: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d0e:
	/* 0xd0e: jmp    11ba <tail_lb_ipv4+0x11ba> */
	return 4538ULL;
x86_l_d13:
	/* 0xd13: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_d19:
	/* 0xd19: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_d1c:
	/* 0xd1c: add    r14d,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_d20:
	/* 0xd20: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d23:
	/* 0xd23: je     d34 <tail_lb_ipv4+0xd34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d34;
	}
x86_l_d25:
	/* 0xd25: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d2a:
	/* 0xd2a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d2c:
	/* 0xd2c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d2e:
	/* 0xd2e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d32:
	/* 0xd32: jmp    d57 <tail_lb_ipv4+0xd57> */
	goto x86_l_d57;
x86_l_d34:
	/* 0xd34: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d39:
	/* 0xd39: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d3b:
	/* 0xd3b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d3d:
	/* 0xd3d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d41:
	/* 0xd41: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d4b:
	/* 0xd4b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d4e:
	/* 0xd4e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d53:
	/* 0xd53: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d57:
	/* 0xd57: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_d5a:
	/* 0xd5a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d5f:
	/* 0xd5f: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_d62:
	/* 0xd62: movzx  r12d,WORD PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_d68:
	/* 0xd68: jae    1760 <tail_lb_ipv4+0x1760> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5984ULL;
	}
x86_l_d6e:
	/* 0xd6e: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d71:
	/* 0xd71: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_d73:
	/* 0xd73: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d75:
	/* 0xd75: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
	return 3448ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3448ULL: goto x86_l_d78;
	case 3454ULL: goto x86_l_d7e;
	case 3460ULL: goto x86_l_d84;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3479ULL: goto x86_l_d97;
	case 3483ULL: goto x86_l_d9b;
	case 3487ULL: goto x86_l_d9f;
	case 3489ULL: goto x86_l_da1;
	case 3495ULL: goto x86_l_da7;
	case 3499ULL: goto x86_l_dab;
	case 3501ULL: goto x86_l_dad;
	case 3503ULL: goto x86_l_daf;
	case 3505ULL: goto x86_l_db1;
	case 3508ULL: goto x86_l_db4;
	case 3511ULL: goto x86_l_db7;
	case 3513ULL: goto x86_l_db9;
	case 3517ULL: goto x86_l_dbd;
	case 3520ULL: goto x86_l_dc0;
	case 3525ULL: goto x86_l_dc5;
	case 3531ULL: goto x86_l_dcb;
	case 3535ULL: goto x86_l_dcf;
	case 3538ULL: goto x86_l_dd2;
	case 3540ULL: goto x86_l_dd4;
	case 3547ULL: goto x86_l_ddb;
	case 3551ULL: goto x86_l_ddf;
	case 3555ULL: goto x86_l_de3;
	case 3563ULL: goto x86_l_deb;
	case 3567ULL: goto x86_l_def;
	case 3571ULL: goto x86_l_df3;
	case 3574ULL: goto x86_l_df6;
	case 3576ULL: goto x86_l_df8;
	case 3581ULL: goto x86_l_dfd;
	case 3583ULL: goto x86_l_dff;
	case 3585ULL: goto x86_l_e01;
	case 3588ULL: goto x86_l_e04;
	case 3592ULL: goto x86_l_e08;
	case 3594ULL: goto x86_l_e0a;
	case 3599ULL: goto x86_l_e0f;
	case 3601ULL: goto x86_l_e11;
	case 3603ULL: goto x86_l_e13;
	case 3607ULL: goto x86_l_e17;
	case 3617ULL: goto x86_l_e21;
	case 3620ULL: goto x86_l_e24;
	case 3625ULL: goto x86_l_e29;
	case 3629ULL: goto x86_l_e2d;
	case 3632ULL: goto x86_l_e30;
	case 3640ULL: goto x86_l_e38;
	case 3644ULL: goto x86_l_e3c;
	case 3648ULL: goto x86_l_e40;
	case 3651ULL: goto x86_l_e43;
	case 3655ULL: goto x86_l_e47;
	case 3662ULL: goto x86_l_e4e;
	case 3665ULL: goto x86_l_e51;
	case 3667ULL: goto x86_l_e53;
	case 3674ULL: goto x86_l_e5a;
	case 3676ULL: goto x86_l_e5c;
	case 3679ULL: goto x86_l_e5f;
	case 3682ULL: goto x86_l_e62;
	case 3684ULL: goto x86_l_e64;
	case 3689ULL: goto x86_l_e69;
	case 3695ULL: goto x86_l_e6f;
	case 3697ULL: goto x86_l_e71;
	case 3700ULL: goto x86_l_e74;
	case 3702ULL: goto x86_l_e76;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3709ULL: goto x86_l_e7d;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3723ULL: goto x86_l_e8b;
	case 3725ULL: goto x86_l_e8d;
	case 3732ULL: goto x86_l_e94;
	case 3735ULL: goto x86_l_e97;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3755ULL: goto x86_l_eab;
	case 3759ULL: goto x86_l_eaf;
	case 3761ULL: goto x86_l_eb1;
	case 3765ULL: goto x86_l_eb5;
	case 3771ULL: goto x86_l_ebb;
	case 3775ULL: goto x86_l_ebf;
	case 3778ULL: goto x86_l_ec2;
	case 3784ULL: goto x86_l_ec8;
	case 3790ULL: goto x86_l_ece;
	case 3796ULL: goto x86_l_ed4;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3809ULL: goto x86_l_ee1;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3827ULL: goto x86_l_ef3;
	case 3834ULL: goto x86_l_efa;
	case 3838ULL: goto x86_l_efe;
	case 3842ULL: goto x86_l_f02;
	case 3847ULL: goto x86_l_f07;
	case 3851ULL: goto x86_l_f0b;
	case 3858ULL: goto x86_l_f12;
	case 3860ULL: goto x86_l_f14;
	case 3867ULL: goto x86_l_f1b;
	case 3872ULL: goto x86_l_f20;
	case 3874ULL: goto x86_l_f22;
	case 3881ULL: goto x86_l_f29;
	case 3883ULL: goto x86_l_f2b;
	case 3885ULL: goto x86_l_f2d;
	case 3889ULL: goto x86_l_f31;
	case 3893ULL: goto x86_l_f35;
	case 3895ULL: goto x86_l_f37;
	case 3901ULL: goto x86_l_f3d;
	case 3904ULL: goto x86_l_f40;
	case 3908ULL: goto x86_l_f44;
	case 3912ULL: goto x86_l_f48;
	case 3917ULL: goto x86_l_f4d;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3926ULL: goto x86_l_f56;
	case 3928ULL: goto x86_l_f58;
	case 3931ULL: goto x86_l_f5b;
	case 3935ULL: goto x86_l_f5f;
	case 3937ULL: goto x86_l_f61;
	case 3942ULL: goto x86_l_f66;
	case 3944ULL: goto x86_l_f68;
	case 3946ULL: goto x86_l_f6a;
	case 3950ULL: goto x86_l_f6e;
	case 3960ULL: goto x86_l_f78;
	case 3963ULL: goto x86_l_f7b;
	case 3968ULL: goto x86_l_f80;
	case 3972ULL: goto x86_l_f84;
	case 3975ULL: goto x86_l_f87;
	case 3978ULL: goto x86_l_f8a;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3991ULL: goto x86_l_f97;
	case 3995ULL: goto x86_l_f9b;
	case 4000ULL: goto x86_l_fa0;
	case 4002ULL: goto x86_l_fa2;
	case 4009ULL: goto x86_l_fa9;
	case 4011ULL: goto x86_l_fab;
	case 4014ULL: goto x86_l_fae;
	case 4017ULL: goto x86_l_fb1;
	case 4019ULL: goto x86_l_fb3;
	case 4024ULL: goto x86_l_fb8;
	case 4026ULL: goto x86_l_fba;
	case 4029ULL: goto x86_l_fbd;
	case 4031ULL: goto x86_l_fbf;
	case 4033ULL: goto x86_l_fc1;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4042ULL: goto x86_l_fca;
	case 4045ULL: goto x86_l_fcd;
	case 4052ULL: goto x86_l_fd4;
	case 4054ULL: goto x86_l_fd6;
	case 4059ULL: goto x86_l_fdb;
	case 4061ULL: goto x86_l_fdd;
	case 4066ULL: goto x86_l_fe2;
	case 4070ULL: goto x86_l_fe6;
	case 4075ULL: goto x86_l_feb;
	case 4082ULL: goto x86_l_ff2;
	case 4087ULL: goto x86_l_ff7;
	case 4092ULL: goto x86_l_ffc;
	case 4094ULL: goto x86_l_ffe;
	case 4097ULL: goto x86_l_1001;
	case 4099ULL: goto x86_l_1003;
	case 4102ULL: goto x86_l_1006;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4117ULL: goto x86_l_1015;
	case 4127ULL: goto x86_l_101f;
	case 4130ULL: goto x86_l_1022;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4143ULL: goto x86_l_102f;
	case 4148ULL: goto x86_l_1034;
	case 4155ULL: goto x86_l_103b;
	case 4158ULL: goto x86_l_103e;
	case 4163ULL: goto x86_l_1043;
	case 4168ULL: goto x86_l_1048;
	case 4174ULL: goto x86_l_104e;
	case 4178ULL: goto x86_l_1052;
	case 4181ULL: goto x86_l_1055;
	case 4186ULL: goto x86_l_105a;
	case 4192ULL: goto x86_l_1060;
	case 4197ULL: goto x86_l_1065;
	case 4202ULL: goto x86_l_106a;
	case 4208ULL: goto x86_l_1070;
	case 4213ULL: goto x86_l_1075;
	case 4221ULL: goto x86_l_107d;
	case 4225ULL: goto x86_l_1081;
	case 4229ULL: goto x86_l_1085;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4247ULL: goto x86_l_1097;
	case 4250ULL: goto x86_l_109a;
	case 4253ULL: goto x86_l_109d;
	case 4256ULL: goto x86_l_10a0;
	case 4262ULL: goto x86_l_10a6;
	case 4267ULL: goto x86_l_10ab;
	case 4270ULL: goto x86_l_10ae;
	case 4273ULL: goto x86_l_10b1;
	case 4276ULL: goto x86_l_10b4;
	case 4282ULL: goto x86_l_10ba;
	case 4285ULL: goto x86_l_10bd;
	case 4287ULL: goto x86_l_10bf;
	case 4291ULL: goto x86_l_10c3;
	case 4295ULL: goto x86_l_10c7;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4309ULL: goto x86_l_10d5;
	case 4312ULL: goto x86_l_10d8;
	case 4319ULL: goto x86_l_10df;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4333ULL: goto x86_l_10ed;
	case 4337ULL: goto x86_l_10f1;
	case 4343ULL: goto x86_l_10f7;
	case 4345ULL: goto x86_l_10f9;
	case 4351ULL: goto x86_l_10ff;
	case 4353ULL: goto x86_l_1101;
	case 4355ULL: goto x86_l_1103;
	case 4361ULL: goto x86_l_1109;
	case 4363ULL: goto x86_l_110b;
	case 4365ULL: goto x86_l_110d;
	case 4371ULL: goto x86_l_1113;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4381ULL: goto x86_l_111d;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4391ULL: goto x86_l_1127;
	case 4393ULL: goto x86_l_1129;
	case 4395ULL: goto x86_l_112b;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4405ULL: goto x86_l_1135;
	case 4411ULL: goto x86_l_113b;
	case 4413ULL: goto x86_l_113d;
	case 4420ULL: goto x86_l_1144;
	case 4424ULL: goto x86_l_1148;
	case 4426ULL: goto x86_l_114a;
	case 4428ULL: goto x86_l_114c;
	case 4430ULL: goto x86_l_114e;
	case 4432ULL: goto x86_l_1150;
	case 4435ULL: goto x86_l_1153;
	case 4441ULL: goto x86_l_1159;
	case 4443ULL: goto x86_l_115b;
	case 4447ULL: goto x86_l_115f;
	case 4451ULL: goto x86_l_1163;
	case 4456ULL: goto x86_l_1168;
	case 4461ULL: goto x86_l_116d;
	case 4463ULL: goto x86_l_116f;
	case 4465ULL: goto x86_l_1171;
	case 4470ULL: goto x86_l_1176;
	case 4474ULL: goto x86_l_117a;
	case 4476ULL: goto x86_l_117c;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4485ULL: goto x86_l_1185;
	case 4492ULL: goto x86_l_118c;
	case 4496ULL: goto x86_l_1190;
	case 4503ULL: goto x86_l_1197;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4518ULL: goto x86_l_11a6;
	case 4524ULL: goto x86_l_11ac;
	case 4527ULL: goto x86_l_11af;
	case 4532ULL: goto x86_l_11b4;
	case 4538ULL: goto x86_l_11ba;
	case 4541ULL: goto x86_l_11bd;
	case 4545ULL: goto x86_l_11c1;
	case 4548ULL: goto x86_l_11c4;
	case 4553ULL: goto x86_l_11c9;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4568ULL: goto x86_l_11d8;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4577ULL: goto x86_l_11e1;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4601ULL: goto x86_l_11f9;
	case 4605ULL: goto x86_l_11fd;
	case 4608ULL: goto x86_l_1200;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4621ULL: goto x86_l_120d;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4639ULL: goto x86_l_121f;
	case 4641ULL: goto x86_l_1221;
	case 4644ULL: goto x86_l_1224;
	case 4647ULL: goto x86_l_1227;
	case 4649ULL: goto x86_l_1229;
	case 4654ULL: goto x86_l_122e;
	case 4656ULL: goto x86_l_1230;
	case 4659ULL: goto x86_l_1233;
	case 4661ULL: goto x86_l_1235;
	case 4668ULL: goto x86_l_123c;
	case 4670ULL: goto x86_l_123e;
	case 4673ULL: goto x86_l_1241;
	case 4675ULL: goto x86_l_1243;
	case 4679ULL: goto x86_l_1247;
	case 4683ULL: goto x86_l_124b;
	case 4685ULL: goto x86_l_124d;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4710ULL: goto x86_l_1266;
	case 4716ULL: goto x86_l_126c;
	case 4720ULL: goto x86_l_1270;
	case 4722ULL: goto x86_l_1272;
	case 4729ULL: goto x86_l_1279;
	case 4731ULL: goto x86_l_127b;
	case 4738ULL: goto x86_l_1282;
	case 4747ULL: goto x86_l_128b;
	case 4756ULL: goto x86_l_1294;
	case 4765ULL: goto x86_l_129d;
	case 4774ULL: goto x86_l_12a6;
	case 4783ULL: goto x86_l_12af;
	case 4791ULL: goto x86_l_12b7;
	case 4796ULL: goto x86_l_12bc;
	case 4800ULL: goto x86_l_12c0;
	case 4805ULL: goto x86_l_12c5;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4826ULL: goto x86_l_12da;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4839ULL: goto x86_l_12e7;
	case 4846ULL: goto x86_l_12ee;
	case 4850ULL: goto x86_l_12f2;
	case 4854ULL: goto x86_l_12f6;
	case 4856ULL: goto x86_l_12f8;
	case 4862ULL: goto x86_l_12fe;
	case 4866ULL: goto x86_l_1302;
	case 4868ULL: goto x86_l_1304;
	case 4875ULL: goto x86_l_130b;
	case 4879ULL: goto x86_l_130f;
	case 4881ULL: goto x86_l_1311;
	case 4888ULL: goto x86_l_1318;
	case 4892ULL: goto x86_l_131c;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4904ULL: goto x86_l_1328;
	case 4908ULL: goto x86_l_132c;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4917ULL: goto x86_l_1335;
	case 4919ULL: goto x86_l_1337;
	case 4923ULL: goto x86_l_133b;
	case 4925ULL: goto x86_l_133d;
	case 4930ULL: goto x86_l_1342;
	case 4932ULL: goto x86_l_1344;
	case 4934ULL: goto x86_l_1346;
	case 4938ULL: goto x86_l_134a;
	case 4948ULL: goto x86_l_1354;
	case 4951ULL: goto x86_l_1357;
	case 4956ULL: goto x86_l_135c;
	case 4960ULL: goto x86_l_1360;
	case 4964ULL: goto x86_l_1364;
	case 4967ULL: goto x86_l_1367;
	case 4970ULL: goto x86_l_136a;
	case 4975ULL: goto x86_l_136f;
	case 4980ULL: goto x86_l_1374;
	case 4984ULL: goto x86_l_1378;
	case 4986ULL: goto x86_l_137a;
	case 4990ULL: goto x86_l_137e;
	case 4992ULL: goto x86_l_1380;
	case 4999ULL: goto x86_l_1387;
	case 5001ULL: goto x86_l_1389;
	case 5004ULL: goto x86_l_138c;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5014ULL: goto x86_l_1396;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d78:
	/* 0xd78: je     e8d <tail_lb_ipv4+0xe8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8d;
	}
x86_l_d7e:
	/* 0xd7e: mov    WORD PTR [rsp+0x6],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_d84:
	/* 0xd84: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d8b:
	/* 0xd8b: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8e:
	/* 0xd8e: je     da1 <tail_lb_ipv4+0xda1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_da1;
	}
x86_l_d90:
	/* 0xd90: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d97:
	/* 0xd97: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_d9b:
	/* 0xd9b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d9f:
	/* 0xd9f: jmp    da7 <tail_lb_ipv4+0xda7> */
	goto x86_l_da7;
x86_l_da1:
	/* 0xda1: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_da7:
	/* 0xda7: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_dab:
	/* 0xdab: jne    de3 <tail_lb_ipv4+0xde3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_de3;
	}
x86_l_dad:
	/* 0xdad: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_daf:
	/* 0xdaf: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_db1:
	/* 0xdb1: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_db4:
	/* 0xdb4: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_db7:
	/* 0xdb7: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_db9:
	/* 0xdb9: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dbd:
	/* 0xdbd: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_dc0:
	/* 0xdc0: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_dc5:
	/* 0xdc5: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_dcb:
	/* 0xdcb: cmove  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_dcf:
	/* 0xdcf: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd2:
	/* 0xdd2: je     de3 <tail_lb_ipv4+0xde3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_de3;
	}
x86_l_dd4:
	/* 0xdd4: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ddb:
	/* 0xddb: imul   r12d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_ddf:
	/* 0xddf: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_de3:
	/* 0xde3: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_deb:
	/* 0xdeb: movzx  r14d,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_def:
	/* 0xdef: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_df3:
	/* 0xdf3: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df6:
	/* 0xdf6: je     e0a <tail_lb_ipv4+0xe0a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e0a;
	}
x86_l_df8:
	/* 0xdf8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_dfd:
	/* 0xdfd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dff:
	/* 0xdff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e01:
	/* 0xe01: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_e04:
	/* 0xe04: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_e08:
	/* 0xe08: jmp    e2d <tail_lb_ipv4+0xe2d> */
	goto x86_l_e2d;
x86_l_e0a:
	/* 0xe0a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_e0f:
	/* 0xe0f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e11:
	/* 0xe11: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e13:
	/* 0xe13: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_e17:
	/* 0xe17: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_e21:
	/* 0xe21: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e24:
	/* 0xe24: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_e29:
	/* 0xe29: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_e2d:
	/* 0xe2d: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e30:
	/* 0xe30: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e38:
	/* 0xe38: mov    DWORD PTR [rax+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e3c:
	/* 0xe3c: movzx  edx,BYTE PTR [rax+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_e40:
	/* 0xe40: mov    esi,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e43:
	/* 0xe43: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_e47:
	/* 0xe47: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_e4e:
	/* 0xe4e: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e51:
	/* 0xe51: je     e64 <tail_lb_ipv4+0xe64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e64;
	}
x86_l_e53:
	/* 0xe53: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_e5a:
	/* 0xe5a: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5c:
	/* 0xe5c: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_e5f:
	/* 0xe5f: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e62:
	/* 0xe62: jmp    e69 <tail_lb_ipv4+0xe69> */
	goto x86_l_e69;
x86_l_e64:
	/* 0xe64: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_e69:
	/* 0xe69: movzx  r12d,WORD PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_e6f:
	/* 0xe6f: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e71:
	/* 0xe71: or     r14b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_e74:
	/* 0xe74: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_e76:
	/* 0xe76: jb     e7d <tail_lb_ipv4+0xe7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_e7d;
	}
x86_l_e78:
	/* 0xe78: cmp    dl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_8);
x86_l_e7b:
	/* 0xe7b: je     e8d <tail_lb_ipv4+0xe8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_e8d;
	}
x86_l_e7d:
	/* 0xe7d: mov    BYTE PTR [rax+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_e81:
	/* 0xe81: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e84:
	/* 0xe84: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_e8b:
	/* 0xe8b: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8d:
	/* 0xe8d: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_e94:
	/* 0xe94: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e97:
	/* 0xe97: je     eab <tail_lb_ipv4+0xeab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_eab;
	}
x86_l_e99:
	/* 0xe99: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_e9e:
	/* 0xe9e: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea0:
	/* 0xea0: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ea3:
	/* 0xea3: sub    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_ea6:
	/* 0xea6: add QWORD PTR [rax+0x18],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_eab:
	/* 0xeab: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_eaf:
	/* 0xeaf: je     f07 <tail_lb_ipv4+0xf07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f07;
	}
x86_l_eb1:
	/* 0xeb1: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_eb5:
	/* 0xeb5: jne    fd6 <tail_lb_ipv4+0xfd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fd6;
	}
x86_l_ebb:
	/* 0xebb: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_ebf:
	/* 0xebf: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_ec2:
	/* 0xec2: je     fd6 <tail_lb_ipv4+0xfd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd6;
	}
x86_l_ec8:
	/* 0xec8: mov    WORD PTR [rsp+0x6],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_ece:
	/* 0xece: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_ed4:
	/* 0xed4: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_eda:
	/* 0xeda: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_edd:
	/* 0xedd: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ee1:
	/* 0xee1: mov    r12,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ee8:
	/* 0xee8: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eed:
	/* 0xeed: je     1688 <tail_lb_ipv4+0x1688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5768ULL;
	}
x86_l_ef3:
	/* 0xef3: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_efa:
	/* 0xefa: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_efe:
	/* 0xefe: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f02:
	/* 0xf02: jmp    168e <tail_lb_ipv4+0x168e> */
	return 5774ULL;
x86_l_f07:
	/* 0xf07: or     BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_f0b:
	/* 0xf0b: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_f12:
	/* 0xf12: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f14:
	/* 0xf14: mov    r12,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f1b:
	/* 0xf1b: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f20:
	/* 0xf20: je     f37 <tail_lb_ipv4+0xf37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f37;
	}
x86_l_f22:
	/* 0xf22: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f29:
	/* 0xf29: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2b:
	/* 0xf2b: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f2d:
	/* 0xf2d: lea    r13d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_f31:
	/* 0xf31: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f35:
	/* 0xf35: jmp    f3d <tail_lb_ipv4+0xf3d> */
	goto x86_l_f3d;
x86_l_f37:
	/* 0xf37: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_f3d:
	/* 0xf3d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f40:
	/* 0xf40: movzx  r14d,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f44:
	/* 0xf44: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f48:
	/* 0xf48: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4d:
	/* 0xf4d: je     f61 <tail_lb_ipv4+0xf61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f61;
	}
x86_l_f4f:
	/* 0xf4f: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_f54:
	/* 0xf54: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f56:
	/* 0xf56: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f58:
	/* 0xf58: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f5b:
	/* 0xf5b: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_f5f:
	/* 0xf5f: jmp    f84 <tail_lb_ipv4+0xf84> */
	goto x86_l_f84;
x86_l_f61:
	/* 0xf61: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_f66:
	/* 0xf66: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f68:
	/* 0xf68: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f6a:
	/* 0xf6a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_f6e:
	/* 0xf6e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_f78:
	/* 0xf78: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f7b:
	/* 0xf7b: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_f80:
	/* 0xf80: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_f84:
	/* 0xf84: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f87:
	/* 0xf87: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_f8a:
	/* 0xf8a: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f8e:
	/* 0xf8e: movzx  edx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_f93:
	/* 0xf93: mov    esi,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f97:
	/* 0xf97: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_f9b:
	/* 0xf9b: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fa0:
	/* 0xfa0: je     fb3 <tail_lb_ipv4+0xfb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fb3;
	}
x86_l_fa2:
	/* 0xfa2: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fa9:
	/* 0xfa9: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fab:
	/* 0xfab: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_fae:
	/* 0xfae: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fb1:
	/* 0xfb1: jmp    fb8 <tail_lb_ipv4+0xfb8> */
	goto x86_l_fb8;
x86_l_fb3:
	/* 0xfb3: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_fb8:
	/* 0xfb8: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fba:
	/* 0xfba: or     r14b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_fbd:
	/* 0xfbd: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_fbf:
	/* 0xfbf: jb     fc6 <tail_lb_ipv4+0xfc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_fc6;
	}
x86_l_fc1:
	/* 0xfc1: cmp    dl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R14, X86_WIDTH_8);
x86_l_fc4:
	/* 0xfc4: je     fd6 <tail_lb_ipv4+0xfd6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fd6;
	}
x86_l_fc6:
	/* 0xfc6: mov    BYTE PTR [rax+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_fca:
	/* 0xfca: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fcd:
	/* 0xfcd: mov    rcx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_fd4:
	/* 0xfd4: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd6:
	/* 0xfd6: test   BYTE PTR [rsp+0x15],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313218ULL);
x86_l_fdb:
	/* 0xfdb: jne    1027 <tail_lb_ipv4+0x1027> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1027;
	}
x86_l_fdd:
	/* 0xfdd: movzx  r12d,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_fe2:
	/* 0xfe2: mov    r13d,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe6:
	/* 0xfe6: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_feb:
	/* 0xfeb: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_ff2:
	/* 0xff2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ff7:
	/* 0xff7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1001:
	/* 0x1001: je     1034 <tail_lb_ipv4+0x1034> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1034;
	}
x86_l_1003:
	/* 0x1003: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1006:
	/* 0x1006: cmp    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_100a:
	/* 0x100a: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_100f:
	/* 0x100f: jne    157d <tail_lb_ipv4+0x157d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5501ULL;
	}
x86_l_1015:
	/* 0x1015: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_101f:
	/* 0x101f: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1022:
	/* 0x1022: jmp    1c08 <tail_lb_ipv4+0x1c08> */
	return 7176ULL;
x86_l_1027:
	/* 0x1027: mov    ebp,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967133ULL);
x86_l_102c:
	/* 0x102c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_102f:
	/* 0x102f: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_1034:
	/* 0x1034: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_103b:
	/* 0x103b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_103e:
	/* 0x103e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1043:
	/* 0x1043: cmp    WORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1048:
	/* 0x1048: je     1ac1 <tail_lb_ipv4+0x1ac1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6849ULL;
	}
x86_l_104e:
	/* 0x104e: movzx  eax,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1052:
	/* 0x1052: shl    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1055:
	/* 0x1055: cmp    eax,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33554432ULL);
x86_l_105a:
	/* 0x105a: jne    1168 <tail_lb_ipv4+0x1168> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1168;
	}
x86_l_1060:
	/* 0x1060: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1065:
	/* 0x1065: movzx  r15d,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_106a:
	/* 0x106a: movzx  r14d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1070:
	/* 0x1070: movzx  ebp,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1075:
	/* 0x1075: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_107d:
	/* 0x107d: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1081:
	/* 0x1081: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1085:
	/* 0x1085: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_maglev)));
x86_l_108c:
	/* 0x108c: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1091:
	/* 0x1091: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1097:
	/* 0x1097: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_109a:
	/* 0x109a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_109d:
	/* 0x109d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a0:
	/* 0x10a0: je     143c <tail_lb_ipv4+0x143c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5180ULL;
	}
x86_l_10a6:
	/* 0x10a6: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10ab:
	/* 0x10ab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10ae:
	/* 0x10ae: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_10b1:
	/* 0x10b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b4:
	/* 0x10b4: je     143c <tail_lb_ipv4+0x143c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5180ULL;
	}
x86_l_10ba:
	/* 0x10ba: shl    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_10bd:
	/* 0x10bd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10bf:
	/* 0x10bf: test   r15b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 16ULL);
x86_l_10c3:
	/* 0x10c3: cmove  ecx,r14d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R14, X86_WIDTH_32, X86_CC_E);
x86_l_10c7:
	/* 0x10c7: or     ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_10c9:
	/* 0x10c9: movzx  edi,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_10ce:
	/* 0x10ce: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_hash_init4_seed)));
x86_l_10d5:
	/* 0x10d5: mov    r8d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d8:
	/* 0x10d8: lea    edx,[r8-0x21524105] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073150512891ULL);
x86_l_10df:
	/* 0x10df: add    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 12ULL);
x86_l_10e3:
	/* 0x10e3: lea    esi,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_10e7:
	/* 0x10e7: add    esi,0xdeadbefb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 3735928571ULL);
x86_l_10ed:
	/* 0x10ed: lea    ecx,[r8+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_10f1:
	/* 0x10f1: add    ecx,0xdeadbefb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 3735928571ULL);
x86_l_10f7:
	/* 0x10f7: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f9:
	/* 0x10f9: rorx   edi,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_10ff:
	/* 0x10ff: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1101:
	/* 0x1101: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1103:
	/* 0x1103: rorx   edi,ecx,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 21ULL);
x86_l_1109:
	/* 0x1109: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_110b:
	/* 0x110b: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_110d:
	/* 0x110d: rorx   edi,edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 7ULL);
x86_l_1113:
	/* 0x1113: sub    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1115:
	/* 0x1115: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1117:
	/* 0x1117: rorx   edi,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_111d:
	/* 0x111d: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_111f:
	/* 0x111f: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1121:
	/* 0x1121: rorx   edi,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_1127:
	/* 0x1127: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1129:
	/* 0x1129: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_112b:
	/* 0x112b: rorx   edx,edx,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 18ULL);
x86_l_1131:
	/* 0x1131: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1133:
	/* 0x1133: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1135:
	/* 0x1135: rorx   edx,esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 8ULL);
x86_l_113b:
	/* 0x113b: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_113d:
	/* 0x113d: imul   rdx,rcx,0x2605a5 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 2491813ULL);
x86_l_1144:
	/* 0x1144: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1148:
	/* 0x1148: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_114a:
	/* 0x114a: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_114c:
	/* 0x114c: shr    esi,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_114e:
	/* 0x114e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1150:
	/* 0x1150: shr    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 14ULL);
x86_l_1153:
	/* 0x1153: imul   edx,esi,0x7fed */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RSI, X86_WIDTH_32, 32749ULL);
x86_l_1159:
	/* 0x1159: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_115b:
	/* 0x115b: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_115f:
	/* 0x115f: mov    r13d,DWORD PTR [rax+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_1163:
	/* 0x1163: jmp    143c <tail_lb_ipv4+0x143c> */
	return 5180ULL;
x86_l_1168:
	/* 0x1168: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_116d:
	/* 0x116d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_116f:
	/* 0x116f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1171:
	/* 0x1171: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1176:
	/* 0x1176: movzx  ecx,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_117a:
	/* 0x117a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_117c:
	/* 0x117c: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_117e:
	/* 0x117e: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1180:
	/* 0x1180: mov    WORD PTR [rsp+0x66],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_1185:
	/* 0x1185: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_118c:
	/* 0x118c: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1190:
	/* 0x1190: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_1197:
	/* 0x1197: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_119c:
	/* 0x119c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11a1:
	/* 0x11a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a3:
	/* 0x11a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a6:
	/* 0x11a6: je     1435 <tail_lb_ipv4+0x1435> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5173ULL;
	}
x86_l_11ac:
	/* 0x11ac: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11af:
	/* 0x11af: jmp    143c <tail_lb_ipv4+0x143c> */
	return 5180ULL;
x86_l_11b4:
	/* 0x11b4: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_11ba:
	/* 0x11ba: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_11bd:
	/* 0x11bd: movzx  ebp,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11c1:
	/* 0x11c1: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11c4:
	/* 0x11c4: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c9:
	/* 0x11c9: je     11da <tail_lb_ipv4+0x11da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11da;
	}
x86_l_11cb:
	/* 0x11cb: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_11d0:
	/* 0x11d0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11d2:
	/* 0x11d2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11d4:
	/* 0x11d4: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_11d8:
	/* 0x11d8: jmp    11fd <tail_lb_ipv4+0x11fd> */
	goto x86_l_11fd;
x86_l_11da:
	/* 0x11da: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_11df:
	/* 0x11df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11e1:
	/* 0x11e1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11e3:
	/* 0x11e3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_11e7:
	/* 0x11e7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_11f1:
	/* 0x11f1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_11f4:
	/* 0x11f4: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11f9:
	/* 0x11f9: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_11fd:
	/* 0x11fd: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1200:
	/* 0x1200: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1204:
	/* 0x1204: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1209:
	/* 0x1209: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_120d:
	/* 0x120d: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1211:
	/* 0x1211: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1216:
	/* 0x1216: je     1229 <tail_lb_ipv4+0x1229> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1229;
	}
x86_l_1218:
	/* 0x1218: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_121f:
	/* 0x121f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1221:
	/* 0x1221: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1224:
	/* 0x1224: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1227:
	/* 0x1227: jmp    122e <tail_lb_ipv4+0x122e> */
	goto x86_l_122e;
x86_l_1229:
	/* 0x1229: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_122e:
	/* 0x122e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1230:
	/* 0x1230: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1233:
	/* 0x1233: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1235:
	/* 0x1235: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_123c:
	/* 0x123c: jb     1243 <tail_lb_ipv4+0x1243> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1243;
	}
x86_l_123e:
	/* 0x123e: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1241:
	/* 0x1241: je     124d <tail_lb_ipv4+0x124d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_124d;
	}
x86_l_1243:
	/* 0x1243: mov    BYTE PTR [r14+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1247:
	/* 0x1247: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_124b:
	/* 0x124b: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124d:
	/* 0x124d: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1255:
	/* 0x1255: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1258:
	/* 0x1258: je     33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_125e:
	/* 0x125e: mov    bpl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1261:
	/* 0x1261: cmp    BYTE PTR [rsp+0x14],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_1266:
	/* 0x1266: jne    33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 51ULL;
	}
x86_l_126c:
	/* 0x126c: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1270:
	/* 0x1270: jne    127b <tail_lb_ipv4+0x127b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_127b;
	}
x86_l_1272:
	/* 0x1272: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1279:
	/* 0x1279: jmp    1282 <tail_lb_ipv4+0x1282> */
	goto x86_l_1282;
x86_l_127b:
	/* 0x127b: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1282:
	/* 0x1282: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_128b:
	/* 0x128b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1294:
	/* 0x1294: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_129d:
	/* 0x129d: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_12a6:
	/* 0x12a6: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_12af:
	/* 0x12af: mov    DWORD PTR [rsp+0x54],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252873ULL);
x86_l_12b7:
	/* 0x12b7: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12bc:
	/* 0x12bc: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_12c0:
	/* 0x12c0: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12c5:
	/* 0x12c5: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_12ce:
	/* 0x12ce: mov    WORD PTR [rsp+0x50],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_12d3:
	/* 0x12d3: mov    WORD PTR [rsp+0x4c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514624ULL);
x86_l_12da:
	/* 0x12da: mov    r15,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_12e1:
	/* 0x12e1: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e5:
	/* 0x12e5: je     12f8 <tail_lb_ipv4+0x12f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f8;
	}
x86_l_12e7:
	/* 0x12e7: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_12ee:
	/* 0x12ee: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_12f2:
	/* 0x12f2: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12f6:
	/* 0x12f6: jmp    12fe <tail_lb_ipv4+0x12fe> */
	goto x86_l_12fe;
x86_l_12f8:
	/* 0x12f8: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_12fe:
	/* 0x12fe: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1302:
	/* 0x1302: jne    1328 <tail_lb_ipv4+0x1328> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1328;
	}
x86_l_1304:
	/* 0x1304: mov    WORD PTR [rsp+0x4c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514624ULL);
x86_l_130b:
	/* 0x130b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_130f:
	/* 0x130f: je     1322 <tail_lb_ipv4+0x1322> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1322;
	}
x86_l_1311:
	/* 0x1311: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1318:
	/* 0x1318: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_131c:
	/* 0x131c: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1320:
	/* 0x1320: jmp    1328 <tail_lb_ipv4+0x1328> */
	goto x86_l_1328;
x86_l_1322:
	/* 0x1322: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1328:
	/* 0x1328: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132c:
	/* 0x132c: je     133d <tail_lb_ipv4+0x133d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_133d;
	}
x86_l_132e:
	/* 0x132e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1333:
	/* 0x1333: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1335:
	/* 0x1335: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1337:
	/* 0x1337: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_133b:
	/* 0x133b: jmp    1360 <tail_lb_ipv4+0x1360> */
	goto x86_l_1360;
x86_l_133d:
	/* 0x133d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1342:
	/* 0x1342: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1344:
	/* 0x1344: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1346:
	/* 0x1346: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_134a:
	/* 0x134a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1354:
	/* 0x1354: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1357:
	/* 0x1357: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1360:
	/* 0x1360: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1364:
	/* 0x1364: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1367:
	/* 0x1367: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_136a:
	/* 0x136a: mov    DWORD PTR [rsp+0x48],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_136f:
	/* 0x136f: movzx  edx,BYTE PTR [rsp+0x52] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 82ULL);
x86_l_1374:
	/* 0x1374: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1378:
	/* 0x1378: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_137a:
	/* 0x137a: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137e:
	/* 0x137e: je     1391 <tail_lb_ipv4+0x1391> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1391;
	}
x86_l_1380:
	/* 0x1380: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1387:
	/* 0x1387: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1389:
	/* 0x1389: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_138c:
	/* 0x138c: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_138f:
	/* 0x138f: jmp    1396 <tail_lb_ipv4+0x1396> */
	goto x86_l_1396;
x86_l_1391:
	/* 0x1391: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1396:
	/* 0x1396: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
	return 5016ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5016ULL: goto x86_l_1398;
	case 5018ULL: goto x86_l_139a;
	case 5020ULL: goto x86_l_139c;
	case 5022ULL: goto x86_l_139e;
	case 5024ULL: goto x86_l_13a0;
	case 5026ULL: goto x86_l_13a2;
	case 5030ULL: goto x86_l_13a6;
	case 5034ULL: goto x86_l_13aa;
	case 5041ULL: goto x86_l_13b1;
	case 5043ULL: goto x86_l_13b3;
	case 5050ULL: goto x86_l_13ba;
	case 5053ULL: goto x86_l_13bd;
	case 5055ULL: goto x86_l_13bf;
	case 5064ULL: goto x86_l_13c8;
	case 5066ULL: goto x86_l_13ca;
	case 5069ULL: goto x86_l_13cd;
	case 5072ULL: goto x86_l_13d0;
	case 5077ULL: goto x86_l_13d5;
	case 5082ULL: goto x86_l_13da;
	case 5087ULL: goto x86_l_13df;
	case 5092ULL: goto x86_l_13e4;
	case 5095ULL: goto x86_l_13e7;
	case 5097ULL: goto x86_l_13e9;
	case 5099ULL: goto x86_l_13eb;
	case 5101ULL: goto x86_l_13ed;
	case 5107ULL: goto x86_l_13f3;
	case 5112ULL: goto x86_l_13f8;
	case 5120ULL: goto x86_l_1400;
	case 5128ULL: goto x86_l_1408;
	case 5131ULL: goto x86_l_140b;
	case 5138ULL: goto x86_l_1412;
	case 5143ULL: goto x86_l_1417;
	case 5148ULL: goto x86_l_141c;
	case 5150ULL: goto x86_l_141e;
	case 5153ULL: goto x86_l_1421;
	case 5159ULL: goto x86_l_1427;
	case 5161ULL: goto x86_l_1429;
	case 5165ULL: goto x86_l_142d;
	case 5168ULL: goto x86_l_1430;
	case 5173ULL: goto x86_l_1435;
	case 5177ULL: goto x86_l_1439;
	case 5180ULL: goto x86_l_143c;
	case 5185ULL: goto x86_l_1441;
	case 5192ULL: goto x86_l_1448;
	case 5197ULL: goto x86_l_144d;
	case 5203ULL: goto x86_l_1453;
	case 5206ULL: goto x86_l_1456;
	case 5209ULL: goto x86_l_1459;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5233ULL: goto x86_l_1471;
	case 5241ULL: goto x86_l_1479;
	case 5244ULL: goto x86_l_147c;
	case 5247ULL: goto x86_l_147f;
	case 5249ULL: goto x86_l_1481;
	case 5252ULL: goto x86_l_1484;
	case 5256ULL: goto x86_l_1488;
	case 5261ULL: goto x86_l_148d;
	case 5266ULL: goto x86_l_1492;
	case 5276ULL: goto x86_l_149c;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5291ULL: goto x86_l_14ab;
	case 5296ULL: goto x86_l_14b0;
	case 5303ULL: goto x86_l_14b7;
	case 5308ULL: goto x86_l_14bc;
	case 5313ULL: goto x86_l_14c1;
	case 5315ULL: goto x86_l_14c3;
	case 5318ULL: goto x86_l_14c6;
	case 5320ULL: goto x86_l_14c8;
	case 5323ULL: goto x86_l_14cb;
	case 5325ULL: goto x86_l_14cd;
	case 5331ULL: goto x86_l_14d3;
	case 5333ULL: goto x86_l_14d5;
	case 5337ULL: goto x86_l_14d9;
	case 5346ULL: goto x86_l_14e2;
	case 5349ULL: goto x86_l_14e5;
	case 5358ULL: goto x86_l_14ee;
	case 5368ULL: goto x86_l_14f8;
	case 5376ULL: goto x86_l_1500;
	case 5383ULL: goto x86_l_1507;
	case 5391ULL: goto x86_l_150f;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5401ULL: goto x86_l_1519;
	case 5403ULL: goto x86_l_151b;
	case 5406ULL: goto x86_l_151e;
	case 5410ULL: goto x86_l_1522;
	case 5413ULL: goto x86_l_1525;
	case 5418ULL: goto x86_l_152a;
	case 5423ULL: goto x86_l_152f;
	case 5428ULL: goto x86_l_1534;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5449ULL: goto x86_l_1549;
	case 5457ULL: goto x86_l_1551;
	case 5462ULL: goto x86_l_1556;
	case 5467ULL: goto x86_l_155b;
	case 5469ULL: goto x86_l_155d;
	case 5471ULL: goto x86_l_155f;
	case 5474ULL: goto x86_l_1562;
	case 5479ULL: goto x86_l_1567;
	case 5485ULL: goto x86_l_156d;
	case 5490ULL: goto x86_l_1572;
	case 5496ULL: goto x86_l_1578;
	case 5501ULL: goto x86_l_157d;
	case 5507ULL: goto x86_l_1583;
	case 5517ULL: goto x86_l_158d;
	case 5520ULL: goto x86_l_1590;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5537ULL: goto x86_l_15a1;
	case 5541ULL: goto x86_l_15a5;
	case 5543ULL: goto x86_l_15a7;
	case 5546ULL: goto x86_l_15aa;
	case 5548ULL: goto x86_l_15ac;
	case 5551ULL: goto x86_l_15af;
	case 5554ULL: goto x86_l_15b2;
	case 5556ULL: goto x86_l_15b4;
	case 5562ULL: goto x86_l_15ba;
	case 5564ULL: goto x86_l_15bc;
	case 5569ULL: goto x86_l_15c1;
	case 5575ULL: goto x86_l_15c7;
	case 5579ULL: goto x86_l_15cb;
	case 5586ULL: goto x86_l_15d2;
	case 5589ULL: goto x86_l_15d5;
	case 5591ULL: goto x86_l_15d7;
	case 5598ULL: goto x86_l_15de;
	case 5602ULL: goto x86_l_15e2;
	case 5606ULL: goto x86_l_15e6;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5620ULL: goto x86_l_15f4;
	case 5623ULL: goto x86_l_15f7;
	case 5625ULL: goto x86_l_15f9;
	case 5630ULL: goto x86_l_15fe;
	case 5632ULL: goto x86_l_1600;
	case 5634ULL: goto x86_l_1602;
	case 5638ULL: goto x86_l_1606;
	case 5640ULL: goto x86_l_1608;
	case 5645ULL: goto x86_l_160d;
	case 5647ULL: goto x86_l_160f;
	case 5649ULL: goto x86_l_1611;
	case 5653ULL: goto x86_l_1615;
	case 5663ULL: goto x86_l_161f;
	case 5666ULL: goto x86_l_1622;
	case 5671ULL: goto x86_l_1627;
	case 5675ULL: goto x86_l_162b;
	case 5678ULL: goto x86_l_162e;
	case 5681ULL: goto x86_l_1631;
	case 5686ULL: goto x86_l_1636;
	case 5692ULL: goto x86_l_163c;
	case 5697ULL: goto x86_l_1641;
	case 5701ULL: goto x86_l_1645;
	case 5708ULL: goto x86_l_164c;
	case 5711ULL: goto x86_l_164f;
	case 5713ULL: goto x86_l_1651;
	case 5720ULL: goto x86_l_1658;
	case 5722ULL: goto x86_l_165a;
	case 5725ULL: goto x86_l_165d;
	case 5728ULL: goto x86_l_1660;
	case 5730ULL: goto x86_l_1662;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5740ULL: goto x86_l_166c;
	case 5742ULL: goto x86_l_166e;
	case 5744ULL: goto x86_l_1670;
	case 5747ULL: goto x86_l_1673;
	case 5753ULL: goto x86_l_1679;
	case 5758ULL: goto x86_l_167e;
	case 5763ULL: goto x86_l_1683;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5778ULL: goto x86_l_1692;
	case 5780ULL: goto x86_l_1694;
	case 5782ULL: goto x86_l_1696;
	case 5784ULL: goto x86_l_1698;
	case 5787ULL: goto x86_l_169b;
	case 5790ULL: goto x86_l_169e;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5799ULL: goto x86_l_16a7;
	case 5804ULL: goto x86_l_16ac;
	case 5810ULL: goto x86_l_16b2;
	case 5814ULL: goto x86_l_16b6;
	case 5819ULL: goto x86_l_16bb;
	case 5821ULL: goto x86_l_16bd;
	case 5828ULL: goto x86_l_16c4;
	case 5832ULL: goto x86_l_16c8;
	case 5836ULL: goto x86_l_16cc;
	case 5839ULL: goto x86_l_16cf;
	case 5842ULL: goto x86_l_16d2;
	case 5847ULL: goto x86_l_16d7;
	case 5849ULL: goto x86_l_16d9;
	case 5854ULL: goto x86_l_16de;
	case 5856ULL: goto x86_l_16e0;
	case 5858ULL: goto x86_l_16e2;
	case 5862ULL: goto x86_l_16e6;
	case 5864ULL: goto x86_l_16e8;
	case 5869ULL: goto x86_l_16ed;
	case 5871ULL: goto x86_l_16ef;
	case 5873ULL: goto x86_l_16f1;
	case 5877ULL: goto x86_l_16f5;
	case 5887ULL: goto x86_l_16ff;
	case 5890ULL: goto x86_l_1702;
	case 5895ULL: goto x86_l_1707;
	case 5899ULL: goto x86_l_170b;
	case 5902ULL: goto x86_l_170e;
	case 5905ULL: goto x86_l_1711;
	case 5909ULL: goto x86_l_1715;
	case 5914ULL: goto x86_l_171a;
	case 5918ULL: goto x86_l_171e;
	case 5922ULL: goto x86_l_1722;
	case 5927ULL: goto x86_l_1727;
	case 5929ULL: goto x86_l_1729;
	case 5936ULL: goto x86_l_1730;
	case 5938ULL: goto x86_l_1732;
	case 5941ULL: goto x86_l_1735;
	case 5944ULL: goto x86_l_1738;
	case 5946ULL: goto x86_l_173a;
	case 5951ULL: goto x86_l_173f;
	case 5953ULL: goto x86_l_1741;
	case 5956ULL: goto x86_l_1744;
	case 5958ULL: goto x86_l_1746;
	case 5963ULL: goto x86_l_174b;
	case 5969ULL: goto x86_l_1751;
	case 5971ULL: goto x86_l_1753;
	case 5974ULL: goto x86_l_1756;
	case 5976ULL: goto x86_l_1758;
	case 5980ULL: goto x86_l_175c;
	case 5984ULL: goto x86_l_1760;
	case 5991ULL: goto x86_l_1767;
	case 5993ULL: goto x86_l_1769;
	case 5998ULL: goto x86_l_176e;
	case 6004ULL: goto x86_l_1774;
	case 6008ULL: goto x86_l_1778;
	case 6014ULL: goto x86_l_177e;
	case 6022ULL: goto x86_l_1786;
	case 6027ULL: goto x86_l_178b;
	case 6031ULL: goto x86_l_178f;
	case 6036ULL: goto x86_l_1794;
	case 6043ULL: goto x86_l_179b;
	case 6051ULL: goto x86_l_17a3;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6073ULL: goto x86_l_17b9;
	case 6079ULL: goto x86_l_17bf;
	case 6082ULL: goto x86_l_17c2;
	case 6089ULL: goto x86_l_17c9;
	case 6093ULL: goto x86_l_17cd;
	case 6095ULL: goto x86_l_17cf;
	case 6100ULL: goto x86_l_17d4;
	case 6102ULL: goto x86_l_17d6;
	case 6104ULL: goto x86_l_17d8;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6115ULL: goto x86_l_17e3;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6123ULL: goto x86_l_17eb;
	case 6133ULL: goto x86_l_17f5;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6152ULL: goto x86_l_1808;
	case 6157ULL: goto x86_l_180d;
	case 6161ULL: goto x86_l_1811;
	case 6166ULL: goto x86_l_1816;
	case 6173ULL: goto x86_l_181d;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6184ULL: goto x86_l_1828;
	case 6188ULL: goto x86_l_182c;
	case 6190ULL: goto x86_l_182e;
	case 6197ULL: goto x86_l_1835;
	case 6200ULL: goto x86_l_1838;
	case 6203ULL: goto x86_l_183b;
	case 6205ULL: goto x86_l_183d;
	case 6208ULL: goto x86_l_1840;
	case 6211ULL: goto x86_l_1843;
	case 6214ULL: goto x86_l_1846;
	case 6216ULL: goto x86_l_1848;
	case 6223ULL: goto x86_l_184f;
	case 6228ULL: goto x86_l_1854;
	case 6233ULL: goto x86_l_1859;
	case 6235ULL: goto x86_l_185b;
	case 6238ULL: goto x86_l_185e;
	case 6240ULL: goto x86_l_1860;
	case 6244ULL: goto x86_l_1864;
	case 6248ULL: goto x86_l_1868;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6263ULL: goto x86_l_1877;
	case 6270ULL: goto x86_l_187e;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6298ULL: goto x86_l_189a;
	case 6301ULL: goto x86_l_189d;
	case 6303ULL: goto x86_l_189f;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6322ULL: goto x86_l_18b2;
	case 6327ULL: goto x86_l_18b7;
	case 6331ULL: goto x86_l_18bb;
	case 6334ULL: goto x86_l_18be;
	case 6339ULL: goto x86_l_18c3;
	case 6345ULL: goto x86_l_18c9;
	case 6351ULL: goto x86_l_18cf;
	case 6356ULL: goto x86_l_18d4;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6375ULL: goto x86_l_18e7;
	case 6379ULL: goto x86_l_18eb;
	case 6383ULL: goto x86_l_18ef;
	case 6390ULL: goto x86_l_18f6;
	case 6395ULL: goto x86_l_18fb;
	case 6401ULL: goto x86_l_1901;
	case 6404ULL: goto x86_l_1904;
	case 6407ULL: goto x86_l_1907;
	case 6410ULL: goto x86_l_190a;
	case 6416ULL: goto x86_l_1910;
	case 6421ULL: goto x86_l_1915;
	case 6424ULL: goto x86_l_1918;
	case 6427ULL: goto x86_l_191b;
	case 6430ULL: goto x86_l_191e;
	case 6436ULL: goto x86_l_1924;
	case 6439ULL: goto x86_l_1927;
	case 6441ULL: goto x86_l_1929;
	case 6445ULL: goto x86_l_192d;
	case 6449ULL: goto x86_l_1931;
	case 6451ULL: goto x86_l_1933;
	case 6456ULL: goto x86_l_1938;
	case 6463ULL: goto x86_l_193f;
	case 6466ULL: goto x86_l_1942;
	case 6473ULL: goto x86_l_1949;
	case 6477ULL: goto x86_l_194d;
	case 6481ULL: goto x86_l_1951;
	case 6487ULL: goto x86_l_1957;
	case 6491ULL: goto x86_l_195b;
	case 6497ULL: goto x86_l_1961;
	case 6499ULL: goto x86_l_1963;
	case 6505ULL: goto x86_l_1969;
	case 6507ULL: goto x86_l_196b;
	case 6509ULL: goto x86_l_196d;
	case 6515ULL: goto x86_l_1973;
	case 6517ULL: goto x86_l_1975;
	case 6519ULL: goto x86_l_1977;
	case 6525ULL: goto x86_l_197d;
	case 6527ULL: goto x86_l_197f;
	case 6529ULL: goto x86_l_1981;
	case 6535ULL: goto x86_l_1987;
	case 6537ULL: goto x86_l_1989;
	case 6539ULL: goto x86_l_198b;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6549ULL: goto x86_l_1995;
	case 6555ULL: goto x86_l_199b;
	case 6557ULL: goto x86_l_199d;
	case 6559ULL: goto x86_l_199f;
	case 6565ULL: goto x86_l_19a5;
	case 6567ULL: goto x86_l_19a7;
	case 6574ULL: goto x86_l_19ae;
	case 6578ULL: goto x86_l_19b2;
	case 6580ULL: goto x86_l_19b4;
	case 6582ULL: goto x86_l_19b6;
	case 6584ULL: goto x86_l_19b8;
	case 6586ULL: goto x86_l_19ba;
	case 6589ULL: goto x86_l_19bd;
	case 6595ULL: goto x86_l_19c3;
	case 6597ULL: goto x86_l_19c5;
	case 6601ULL: goto x86_l_19c9;
	case 6605ULL: goto x86_l_19cd;
	case 6611ULL: goto x86_l_19d3;
	case 6613ULL: goto x86_l_19d5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1398:
	/* 0x1398: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_139a:
	/* 0x139a: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_139c:
	/* 0x139c: jb     13a2 <tail_lb_ipv4+0x13a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_13a2;
	}
x86_l_139e:
	/* 0x139e: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_13a0:
	/* 0x13a0: je     13b3 <tail_lb_ipv4+0x13b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13b3;
	}
x86_l_13a2:
	/* 0x13a2: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_13a6:
	/* 0x13a6: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13aa:
	/* 0x13aa: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_13b1:
	/* 0x13b1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b3:
	/* 0x13b3: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_13ba:
	/* 0x13ba: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13bd:
	/* 0x13bd: je     13d5 <tail_lb_ipv4+0x13d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13d5;
	}
x86_l_13bf:
	/* 0x13bf: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_13c8:
	/* 0x13c8: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ca:
	/* 0x13ca: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13cd:
	/* 0x13cd: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_13d0:
	/* 0x13d0: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13d5:
	/* 0x13d5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13da:
	/* 0x13da: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13df:
	/* 0x13df: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13e4:
	/* 0x13e4: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_13e7:
	/* 0x13e7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e9:
	/* 0x13e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13eb:
	/* 0x13eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13ed:
	/* 0x13ed: jns    33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 51ULL;
	}
x86_l_13f3:
	/* 0x13f3: jmp    2688 <tail_lb_ipv4+0x2688> */
	return 9864ULL;
x86_l_13f8:
	/* 0x13f8: mov    QWORD PTR [rsp+0x80],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1400:
	/* 0x1400: mov    QWORD PTR [rsp+0x98],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1408:
	/* 0x1408: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_140b:
	/* 0x140b: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1412:
	/* 0x1412: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1417:
	/* 0x1417: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141c:
	/* 0x141c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141e:
	/* 0x141e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1421:
	/* 0x1421: je     152a <tail_lb_ipv4+0x152a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_152a;
	}
x86_l_1427:
	/* 0x1427: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1429:
	/* 0x1429: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_142d:
	/* 0x142d: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_1430:
	/* 0x1430: jmp    47b <tail_lb_ipv4+0x47b> */
	return 1147ULL;
x86_l_1435:
	/* 0x1435: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1439:
	/* 0x1439: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143c:
	/* 0x143c: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1441:
	/* 0x1441: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_1448:
	/* 0x1448: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_144d:
	/* 0x144d: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1453:
	/* 0x1453: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1456:
	/* 0x1456: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1459:
	/* 0x1459: je     1ab2 <tail_lb_ipv4+0x1ab2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6834ULL;
	}
x86_l_145f:
	/* 0x145f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1462:
	/* 0x1462: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1467:
	/* 0x1467: movzx  r12d,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_146c:
	/* 0x146c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1471:
	/* 0x1471: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1479:
	/* 0x1479: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_147c:
	/* 0x147c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_147f:
	/* 0x147f: je     148d <tail_lb_ipv4+0x148d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_148d;
	}
x86_l_1481:
	/* 0x1481: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_1484:
	/* 0x1484: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1488:
	/* 0x1488: mov    WORD PTR [rax+0x26],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_148d:
	/* 0x148d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1492:
	/* 0x1492: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_149c:
	/* 0x149c: jmp    1c08 <tail_lb_ipv4+0x1c08> */
	return 7176ULL;
x86_l_14a1:
	/* 0x14a1: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_14a6:
	/* 0x14a6: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_14ab:
	/* 0x14ab: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14b0:
	/* 0x14b0: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_14b7:
	/* 0x14b7: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14bc:
	/* 0x14bc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14c1:
	/* 0x14c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c3:
	/* 0x14c3: mov    rbp,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R9, X86_WIDTH_64);
x86_l_14c6:
	/* 0x14c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14c8:
	/* 0x14c8: mov    r9,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14cd:
	/* 0x14cd: je     47b <tail_lb_ipv4+0x47b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1147ULL;
	}
x86_l_14d3:
	/* 0x14d3: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d5:
	/* 0x14d5: mov    r14d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14d9:
	/* 0x14d9: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_14e2:
	/* 0x14e2: sub    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_14e5:
	/* 0x14e5: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_14ee:
	/* 0x14ee: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_14f8:
	/* 0x14f8: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1500:
	/* 0x1500: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1507:
	/* 0x1507: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_150f:
	/* 0x150f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1514:
	/* 0x1514: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1516:
	/* 0x1516: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1519:
	/* 0x1519: je     1534 <tail_lb_ipv4+0x1534> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1534;
	}
x86_l_151b:
	/* 0x151b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_151e:
	/* 0x151e: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1522:
	/* 0x1522: mov    r9,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_1525:
	/* 0x1525: jmp    47b <tail_lb_ipv4+0x47b> */
	return 1147ULL;
x86_l_152a:
	/* 0x152a: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_152f:
	/* 0x152f: jmp    2b7 <tail_lb_ipv4+0x2b7> */
	return 695ULL;
x86_l_1534:
	/* 0x1534: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_153d:
	/* 0x153d: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1542:
	/* 0x1542: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1549:
	/* 0x1549: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1551:
	/* 0x1551: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1556:
	/* 0x1556: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_155b:
	/* 0x155b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155d:
	/* 0x155d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155f:
	/* 0x155f: mov    r9,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_1562:
	/* 0x1562: jmp    47b <tail_lb_ipv4+0x47b> */
	return 1147ULL;
x86_l_1567:
	/* 0x1567: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_156d:
	/* 0x156d: jmp    9b2 <tail_lb_ipv4+0x9b2> */
	return 2482ULL;
x86_l_1572:
	/* 0x1572: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1578:
	/* 0x1578: jmp    ada <tail_lb_ipv4+0xada> */
	return 2778ULL;
x86_l_157d:
	/* 0x157d: test   ebp,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 512ULL);
x86_l_1583:
	/* 0x1583: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_158d:
	/* 0x158d: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_1590:
	/* 0x1590: jne    1043 <tail_lb_ipv4+0x1043> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4163ULL;
	}
x86_l_1596:
	/* 0x1596: jmp    1c08 <tail_lb_ipv4+0x1c08> */
	return 7176ULL;
x86_l_159b:
	/* 0x159b: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_15a1:
	/* 0x15a1: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_15a5:
	/* 0x15a5: jne    15e6 <tail_lb_ipv4+0x15e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_15e6;
	}
x86_l_15a7:
	/* 0x15a7: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_15aa:
	/* 0x15aa: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_15ac:
	/* 0x15ac: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_15af:
	/* 0x15af: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_15b2:
	/* 0x15b2: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_15b4:
	/* 0x15b4: mov    WORD PTR [r12+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15ba:
	/* 0x15ba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15bc:
	/* 0x15bc: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_15c1:
	/* 0x15c1: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_15c7:
	/* 0x15c7: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_15cb:
	/* 0x15cb: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_15d2:
	/* 0x15d2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d5:
	/* 0x15d5: je     15e6 <tail_lb_ipv4+0x15e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15e6;
	}
x86_l_15d7:
	/* 0x15d7: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_15de:
	/* 0x15de: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_15e2:
	/* 0x15e2: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15e6:
	/* 0x15e6: movzx  ebp,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_15ea:
	/* 0x15ea: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15ed:
	/* 0x15ed: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_15f4:
	/* 0x15f4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f7:
	/* 0x15f7: je     1608 <tail_lb_ipv4+0x1608> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1608;
	}
x86_l_15f9:
	/* 0x15f9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_15fe:
	/* 0x15fe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1600:
	/* 0x1600: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1602:
	/* 0x1602: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1606:
	/* 0x1606: jmp    162b <tail_lb_ipv4+0x162b> */
	goto x86_l_162b;
x86_l_1608:
	/* 0x1608: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_160d:
	/* 0x160d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_160f:
	/* 0x160f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1611:
	/* 0x1611: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1615:
	/* 0x1615: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_161f:
	/* 0x161f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1622:
	/* 0x1622: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1627:
	/* 0x1627: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_162b:
	/* 0x162b: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_162e:
	/* 0x162e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1631:
	/* 0x1631: mov    DWORD PTR [r12+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1636:
	/* 0x1636: movzx  ecx,BYTE PTR [r12+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_163c:
	/* 0x163c: mov    edx,DWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1641:
	/* 0x1641: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1645:
	/* 0x1645: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_164c:
	/* 0x164c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164f:
	/* 0x164f: je     1662 <tail_lb_ipv4+0x1662> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1662;
	}
x86_l_1651:
	/* 0x1651: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1658:
	/* 0x1658: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165a:
	/* 0x165a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_165d:
	/* 0x165d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1660:
	/* 0x1660: jmp    1667 <tail_lb_ipv4+0x1667> */
	goto x86_l_1667;
x86_l_1662:
	/* 0x1662: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1667:
	/* 0x1667: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1669:
	/* 0x1669: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_166c:
	/* 0x166c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_166e:
	/* 0x166e: jb     1679 <tail_lb_ipv4+0x1679> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1679;
	}
x86_l_1670:
	/* 0x1670: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1673:
	/* 0x1673: je     9d7 <tail_lb_ipv4+0x9d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2519ULL;
	}
x86_l_1679:
	/* 0x1679: mov    BYTE PTR [r12+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_167e:
	/* 0x167e: mov    DWORD PTR [r12+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1683:
	/* 0x1683: jmp    9ce <tail_lb_ipv4+0x9ce> */
	return 2510ULL;
x86_l_1688:
	/* 0x1688: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_168e:
	/* 0x168e: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_1692:
	/* 0x1692: jne    16cc <tail_lb_ipv4+0x16cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16cc;
	}
x86_l_1694:
	/* 0x1694: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1696:
	/* 0x1696: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1698:
	/* 0x1698: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_169b:
	/* 0x169b: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_169e:
	/* 0x169e: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_16a0:
	/* 0x16a0: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16a5:
	/* 0x16a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16a7:
	/* 0x16a7: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_16ac:
	/* 0x16ac: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_16b2:
	/* 0x16b2: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_16b6:
	/* 0x16b6: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bb:
	/* 0x16bb: je     16cc <tail_lb_ipv4+0x16cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16cc;
	}
x86_l_16bd:
	/* 0x16bd: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_16c4:
	/* 0x16c4: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_16c8:
	/* 0x16c8: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_16cc:
	/* 0x16cc: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_16cf:
	/* 0x16cf: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_16d2:
	/* 0x16d2: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d7:
	/* 0x16d7: je     16e8 <tail_lb_ipv4+0x16e8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16e8;
	}
x86_l_16d9:
	/* 0x16d9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_16de:
	/* 0x16de: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e0:
	/* 0x16e0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16e2:
	/* 0x16e2: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_16e6:
	/* 0x16e6: jmp    170b <tail_lb_ipv4+0x170b> */
	goto x86_l_170b;
x86_l_16e8:
	/* 0x16e8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_16ed:
	/* 0x16ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ef:
	/* 0x16ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16f1:
	/* 0x16f1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_16f5:
	/* 0x16f5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_16ff:
	/* 0x16ff: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1702:
	/* 0x1702: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1707:
	/* 0x1707: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_170b:
	/* 0x170b: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_170e:
	/* 0x170e: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1711:
	/* 0x1711: mov    DWORD PTR [r15+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1715:
	/* 0x1715: movzx  edx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_171a:
	/* 0x171a: mov    ecx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_171e:
	/* 0x171e: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1722:
	/* 0x1722: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1727:
	/* 0x1727: je     173a <tail_lb_ipv4+0x173a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_173a;
	}
x86_l_1729:
	/* 0x1729: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1730:
	/* 0x1730: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1732:
	/* 0x1732: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1735:
	/* 0x1735: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1738:
	/* 0x1738: jmp    173f <tail_lb_ipv4+0x173f> */
	goto x86_l_173f;
x86_l_173a:
	/* 0x173a: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_173f:
	/* 0x173f: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1741:
	/* 0x1741: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1744:
	/* 0x1744: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1746:
	/* 0x1746: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_174b:
	/* 0x174b: movzx  r12d,WORD PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1751:
	/* 0x1751: jb     1758 <tail_lb_ipv4+0x1758> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1758;
	}
x86_l_1753:
	/* 0x1753: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_1756:
	/* 0x1756: je     1769 <tail_lb_ipv4+0x1769> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1769;
	}
x86_l_1758:
	/* 0x1758: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_175c:
	/* 0x175c: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1760:
	/* 0x1760: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1767:
	/* 0x1767: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1769:
	/* 0x1769: cmp    WORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_176e:
	/* 0x176e: je     1ac1 <tail_lb_ipv4+0x1ac1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6849ULL;
	}
x86_l_1774:
	/* 0x1774: test   BYTE PTR [rcx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1778:
	/* 0x1778: je     18b7 <tail_lb_ipv4+0x18b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b7;
	}
x86_l_177e:
	/* 0x177e: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1786:
	/* 0x1786: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_178b:
	/* 0x178b: movzx  eax,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_178f:
	/* 0x178f: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1794:
	/* 0x1794: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_179b:
	/* 0x179b: mov    DWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_17a3:
	/* 0x17a3: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_17aa:
	/* 0x17aa: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17af:
	/* 0x17af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17b4:
	/* 0x17b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b6:
	/* 0x17b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17b9:
	/* 0x17b9: je     18b2 <tail_lb_ipv4+0x18b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b2;
	}
x86_l_17bf:
	/* 0x17bf: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_17c2:
	/* 0x17c2: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_17c9:
	/* 0x17c9: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17cd:
	/* 0x17cd: je     17de <tail_lb_ipv4+0x17de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_17de;
	}
x86_l_17cf:
	/* 0x17cf: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_17d4:
	/* 0x17d4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d6:
	/* 0x17d6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17d8:
	/* 0x17d8: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_17dc:
	/* 0x17dc: jmp    1801 <tail_lb_ipv4+0x1801> */
	goto x86_l_1801;
x86_l_17de:
	/* 0x17de: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_17e3:
	/* 0x17e3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e5:
	/* 0x17e5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17e7:
	/* 0x17e7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_17eb:
	/* 0x17eb: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_17f5:
	/* 0x17f5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_17f8:
	/* 0x17f8: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_17fd:
	/* 0x17fd: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1801:
	/* 0x1801: mov    ecx,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1804:
	/* 0x1804: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1808:
	/* 0x1808: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180d:
	/* 0x180d: movzx  ecx,WORD PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1811:
	/* 0x1811: mov    WORD PTR [rsp+0x74],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_1816:
	/* 0x1816: mov    WORD PTR [rsp+0x76],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_181d:
	/* 0x181d: mov    rcx,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1821:
	/* 0x1821: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_1826:
	/* 0x1826: and    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_1828:
	/* 0x1828: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_182c:
	/* 0x182c: je     183b <tail_lb_ipv4+0x183b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_183b;
	}
x86_l_182e:
	/* 0x182e: mov    rsi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1835:
	/* 0x1835: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1838:
	/* 0x1838: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_183b:
	/* 0x183b: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_183d:
	/* 0x183d: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1840:
	/* 0x1840: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1843:
	/* 0x1843: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1846:
	/* 0x1846: jbe    189f <tail_lb_ipv4+0x189f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_189f;
	}
x86_l_1848:
	/* 0x1848: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_184f:
	/* 0x184f: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1854:
	/* 0x1854: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1859:
	/* 0x1859: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_185b:
	/* 0x185b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_185e:
	/* 0x185e: je     189f <tail_lb_ipv4+0x189f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_189f;
	}
x86_l_1860:
	/* 0x1860: mov    QWORD PTR [rbp+0x0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1864:
	/* 0x1864: mov    r13d,DWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1868:
	/* 0x1868: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_186b:
	/* 0x186b: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1870:
	/* 0x1870: je     18b7 <tail_lb_ipv4+0x18b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_18b7;
	}
x86_l_1872:
	/* 0x1872: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1877:
	/* 0x1877: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_187e:
	/* 0x187e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1883:
	/* 0x1883: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1888:
	/* 0x1888: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188a:
	/* 0x188a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_188d:
	/* 0x188d: jne    1a3d <tail_lb_ipv4+0x1a3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6717ULL;
	}
x86_l_1893:
	/* 0x1893: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_189a:
	/* 0x189a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_189d:
	/* 0x189d: jmp    18b2 <tail_lb_ipv4+0x18b2> */
	goto x86_l_18b2;
x86_l_189f:
	/* 0x189f: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_18a6:
	/* 0x18a6: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18ab:
	/* 0x18ab: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_18b0:
	/* 0x18b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b2:
	/* 0x18b2: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b7:
	/* 0x18b7: movzx  eax,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_18bb:
	/* 0x18bb: shl    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_18be:
	/* 0x18be: cmp    eax,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33554432ULL);
x86_l_18c3:
	/* 0x18c3: jne    19d5 <tail_lb_ipv4+0x19d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19d5;
	}
x86_l_18c9:
	/* 0x18c9: mov    WORD PTR [rsp+0x6],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_18cf:
	/* 0x18cf: movzx  r15d,BYTE PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_18d4:
	/* 0x18d4: movzx  r14d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_18da:
	/* 0x18da: movzx  ebp,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_18df:
	/* 0x18df: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_18e7:
	/* 0x18e7: movzx  eax,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_18eb:
	/* 0x18eb: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18ef:
	/* 0x18ef: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_maglev)));
x86_l_18f6:
	/* 0x18f6: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18fb:
	/* 0x18fb: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1901:
	/* 0x1901: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1904:
	/* 0x1904: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1907:
	/* 0x1907: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_190a:
	/* 0x190a: je     19cd <tail_lb_ipv4+0x19cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cd;
	}
x86_l_1910:
	/* 0x1910: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1915:
	/* 0x1915: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1918:
	/* 0x1918: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_191b:
	/* 0x191b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_191e:
	/* 0x191e: je     19cd <tail_lb_ipv4+0x19cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19cd;
	}
x86_l_1924:
	/* 0x1924: shl    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1927:
	/* 0x1927: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1929:
	/* 0x1929: test   r15b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 16ULL);
x86_l_192d:
	/* 0x192d: cmove  ecx,r14d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R14, X86_WIDTH_32, X86_CC_E);
x86_l_1931:
	/* 0x1931: or     ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_1933:
	/* 0x1933: movzx  edi,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_1938:
	/* 0x1938: mov    rdx,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_hash_init4_seed)));
x86_l_193f:
	/* 0x193f: mov    r8d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1942:
	/* 0x1942: lea    edx,[r8-0x21524105] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073150512891ULL);
x86_l_1949:
	/* 0x1949: add    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 12ULL);
x86_l_194d:
	/* 0x194d: lea    esi,[r8+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1951:
	/* 0x1951: add    esi,0xdeadbefb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 3735928571ULL);
x86_l_1957:
	/* 0x1957: lea    ecx,[r8+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_195b:
	/* 0x195b: add    ecx,0xdeadbefb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 3735928571ULL);
x86_l_1961:
	/* 0x1961: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1963:
	/* 0x1963: rorx   edi,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_1969:
	/* 0x1969: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_196b:
	/* 0x196b: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_196d:
	/* 0x196d: rorx   edi,ecx,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 21ULL);
x86_l_1973:
	/* 0x1973: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1975:
	/* 0x1975: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1977:
	/* 0x1977: rorx   edi,edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 7ULL);
x86_l_197d:
	/* 0x197d: sub    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_197f:
	/* 0x197f: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1981:
	/* 0x1981: rorx   edi,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_1987:
	/* 0x1987: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1989:
	/* 0x1989: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198b:
	/* 0x198b: rorx   edi,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_1991:
	/* 0x1991: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1993:
	/* 0x1993: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1995:
	/* 0x1995: rorx   edx,edx,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 18ULL);
x86_l_199b:
	/* 0x199b: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_199d:
	/* 0x199d: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199f:
	/* 0x199f: rorx   edx,esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 8ULL);
x86_l_19a5:
	/* 0x19a5: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19a7:
	/* 0x19a7: imul   rdx,rcx,0x2605a5 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 2491813ULL);
x86_l_19ae:
	/* 0x19ae: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_19b2:
	/* 0x19b2: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_19b4:
	/* 0x19b4: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19b6:
	/* 0x19b6: shr    esi,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_19b8:
	/* 0x19b8: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19ba:
	/* 0x19ba: shr    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 14ULL);
x86_l_19bd:
	/* 0x19bd: imul   edx,esi,0x7fed */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RSI, X86_WIDTH_32, 32749ULL);
x86_l_19c3:
	/* 0x19c3: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_19c5:
	/* 0x19c5: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_19c9:
	/* 0x19c9: mov    r13d,DWORD PTR [rax+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_19cd:
	/* 0x19cd: movzx  r12d,WORD PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_19d3:
	/* 0x19d3: jmp    1a20 <tail_lb_ipv4+0x1a20> */
	return 6688ULL;
x86_l_19d5:
	/* 0x19d5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
	return 6616ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6616ULL: goto x86_l_19d8;
	case 6621ULL: goto x86_l_19dd;
	case 6624ULL: goto x86_l_19e0;
	case 6626ULL: goto x86_l_19e2;
	case 6628ULL: goto x86_l_19e4;
	case 6633ULL: goto x86_l_19e9;
	case 6635ULL: goto x86_l_19eb;
	case 6637ULL: goto x86_l_19ed;
	case 6639ULL: goto x86_l_19ef;
	case 6644ULL: goto x86_l_19f4;
	case 6651ULL: goto x86_l_19fb;
	case 6655ULL: goto x86_l_19ff;
	case 6662ULL: goto x86_l_1a06;
	case 6667ULL: goto x86_l_1a0b;
	case 6672ULL: goto x86_l_1a10;
	case 6674ULL: goto x86_l_1a12;
	case 6677ULL: goto x86_l_1a15;
	case 6679ULL: goto x86_l_1a17;
	case 6682ULL: goto x86_l_1a1a;
	case 6684ULL: goto x86_l_1a1c;
	case 6688ULL: goto x86_l_1a20;
	case 6693ULL: goto x86_l_1a25;
	case 6700ULL: goto x86_l_1a2c;
	case 6705ULL: goto x86_l_1a31;
	case 6710ULL: goto x86_l_1a36;
	case 6712ULL: goto x86_l_1a38;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6725ULL: goto x86_l_1a45;
	case 6728ULL: goto x86_l_1a48;
	case 6731ULL: goto x86_l_1a4b;
	case 6740ULL: goto x86_l_1a54;
	case 6749ULL: goto x86_l_1a5d;
	case 6758ULL: goto x86_l_1a66;
	case 6767ULL: goto x86_l_1a6f;
	case 6776ULL: goto x86_l_1a78;
	case 6785ULL: goto x86_l_1a81;
	case 6790ULL: goto x86_l_1a86;
	case 6796ULL: goto x86_l_1a8c;
	case 6799ULL: goto x86_l_1a8f;
	case 6804ULL: goto x86_l_1a94;
	case 6811ULL: goto x86_l_1a9b;
	case 6815ULL: goto x86_l_1a9f;
	case 6817ULL: goto x86_l_1aa1;
	case 6824ULL: goto x86_l_1aa8;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6834ULL: goto x86_l_1ab2;
	case 6841ULL: goto x86_l_1ab9;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6856ULL: goto x86_l_1ac8;
	case 6859ULL: goto x86_l_1acb;
	case 6862ULL: goto x86_l_1ace;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6874ULL: goto x86_l_1ada;
	case 6880ULL: goto x86_l_1ae0;
	case 6885ULL: goto x86_l_1ae5;
	case 6887ULL: goto x86_l_1ae7;
	case 6893ULL: goto x86_l_1aed;
	case 6898ULL: goto x86_l_1af2;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6910ULL: goto x86_l_1afe;
	case 6914ULL: goto x86_l_1b02;
	case 6916ULL: goto x86_l_1b04;
	case 6923ULL: goto x86_l_1b0b;
	case 6927ULL: goto x86_l_1b0f;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6939ULL: goto x86_l_1b1b;
	case 6943ULL: goto x86_l_1b1f;
	case 6945ULL: goto x86_l_1b21;
	case 6950ULL: goto x86_l_1b26;
	case 6952ULL: goto x86_l_1b28;
	case 6954ULL: goto x86_l_1b2a;
	case 6958ULL: goto x86_l_1b2e;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6967ULL: goto x86_l_1b37;
	case 6969ULL: goto x86_l_1b39;
	case 6973ULL: goto x86_l_1b3d;
	case 6983ULL: goto x86_l_1b47;
	case 6986ULL: goto x86_l_1b4a;
	case 6991ULL: goto x86_l_1b4f;
	case 6995ULL: goto x86_l_1b53;
	case 6999ULL: goto x86_l_1b57;
	case 7002ULL: goto x86_l_1b5a;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7015ULL: goto x86_l_1b67;
	case 7019ULL: goto x86_l_1b6b;
	case 7021ULL: goto x86_l_1b6d;
	case 7025ULL: goto x86_l_1b71;
	case 7033ULL: goto x86_l_1b79;
	case 7035ULL: goto x86_l_1b7b;
	case 7042ULL: goto x86_l_1b82;
	case 7045ULL: goto x86_l_1b85;
	case 7049ULL: goto x86_l_1b89;
	case 7053ULL: goto x86_l_1b8d;
	case 7055ULL: goto x86_l_1b8f;
	case 7061ULL: goto x86_l_1b95;
	case 7071ULL: goto x86_l_1b9f;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7084ULL: goto x86_l_1bac;
	case 7087ULL: goto x86_l_1baf;
	case 7089ULL: goto x86_l_1bb1;
	case 7091ULL: goto x86_l_1bb3;
	case 7093ULL: goto x86_l_1bb5;
	case 7097ULL: goto x86_l_1bb9;
	case 7101ULL: goto x86_l_1bbd;
	case 7108ULL: goto x86_l_1bc4;
	case 7110ULL: goto x86_l_1bc6;
	case 7117ULL: goto x86_l_1bcd;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7131ULL: goto x86_l_1bdb;
	case 7133ULL: goto x86_l_1bdd;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7161ULL: goto x86_l_1bf9;
	case 7163ULL: goto x86_l_1bfb;
	case 7165ULL: goto x86_l_1bfd;
	case 7170ULL: goto x86_l_1c02;
	case 7176ULL: goto x86_l_1c08;
	case 7184ULL: goto x86_l_1c10;
	case 7188ULL: goto x86_l_1c14;
	case 7192ULL: goto x86_l_1c18;
	case 7198ULL: goto x86_l_1c1e;
	case 7205ULL: goto x86_l_1c25;
	case 7208ULL: goto x86_l_1c28;
	case 7210ULL: goto x86_l_1c2a;
	case 7215ULL: goto x86_l_1c2f;
	case 7217ULL: goto x86_l_1c31;
	case 7219ULL: goto x86_l_1c33;
	case 7223ULL: goto x86_l_1c37;
	case 7225ULL: goto x86_l_1c39;
	case 7230ULL: goto x86_l_1c3e;
	case 7232ULL: goto x86_l_1c40;
	case 7234ULL: goto x86_l_1c42;
	case 7238ULL: goto x86_l_1c46;
	case 7248ULL: goto x86_l_1c50;
	case 7251ULL: goto x86_l_1c53;
	case 7256ULL: goto x86_l_1c58;
	case 7260ULL: goto x86_l_1c5c;
	case 7268ULL: goto x86_l_1c64;
	case 7273ULL: goto x86_l_1c69;
	case 7278ULL: goto x86_l_1c6e;
	case 7282ULL: goto x86_l_1c72;
	case 7287ULL: goto x86_l_1c77;
	case 7294ULL: goto x86_l_1c7e;
	case 7302ULL: goto x86_l_1c86;
	case 7304ULL: goto x86_l_1c88;
	case 7309ULL: goto x86_l_1c8d;
	case 7314ULL: goto x86_l_1c92;
	case 7322ULL: goto x86_l_1c9a;
	case 7329ULL: goto x86_l_1ca1;
	case 7334ULL: goto x86_l_1ca6;
	case 7339ULL: goto x86_l_1cab;
	case 7344ULL: goto x86_l_1cb0;
	case 7346ULL: goto x86_l_1cb2;
	case 7348ULL: goto x86_l_1cb4;
	case 7351ULL: goto x86_l_1cb7;
	case 7360ULL: goto x86_l_1cc0;
	case 7368ULL: goto x86_l_1cc8;
	case 7377ULL: goto x86_l_1cd1;
	case 7381ULL: goto x86_l_1cd5;
	case 7386ULL: goto x86_l_1cda;
	case 7393ULL: goto x86_l_1ce1;
	case 7398ULL: goto x86_l_1ce6;
	case 7403ULL: goto x86_l_1ceb;
	case 7405ULL: goto x86_l_1ced;
	case 7410ULL: goto x86_l_1cf2;
	case 7414ULL: goto x86_l_1cf6;
	case 7417ULL: goto x86_l_1cf9;
	case 7419ULL: goto x86_l_1cfb;
	case 7422ULL: goto x86_l_1cfe;
	case 7427ULL: goto x86_l_1d03;
	case 7429ULL: goto x86_l_1d05;
	case 7432ULL: goto x86_l_1d08;
	case 7434ULL: goto x86_l_1d0a;
	case 7438ULL: goto x86_l_1d0e;
	case 7441ULL: goto x86_l_1d11;
	case 7447ULL: goto x86_l_1d17;
	case 7449ULL: goto x86_l_1d19;
	case 7452ULL: goto x86_l_1d1c;
	case 7457ULL: goto x86_l_1d21;
	case 7459ULL: goto x86_l_1d23;
	case 7464ULL: goto x86_l_1d28;
	case 7469ULL: goto x86_l_1d2d;
	case 7474ULL: goto x86_l_1d32;
	case 7477ULL: goto x86_l_1d35;
	case 7481ULL: goto x86_l_1d39;
	case 7485ULL: goto x86_l_1d3d;
	case 7488ULL: goto x86_l_1d40;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7501ULL: goto x86_l_1d4d;
	case 7503ULL: goto x86_l_1d4f;
	case 7506ULL: goto x86_l_1d52;
	case 7509ULL: goto x86_l_1d55;
	case 7517ULL: goto x86_l_1d5d;
	case 7525ULL: goto x86_l_1d65;
	case 7528ULL: goto x86_l_1d68;
	case 7530ULL: goto x86_l_1d6a;
	case 7533ULL: goto x86_l_1d6d;
	case 7535ULL: goto x86_l_1d6f;
	case 7537ULL: goto x86_l_1d71;
	case 7542ULL: goto x86_l_1d76;
	case 7545ULL: goto x86_l_1d79;
	case 7550ULL: goto x86_l_1d7e;
	case 7554ULL: goto x86_l_1d82;
	case 7556ULL: goto x86_l_1d84;
	case 7560ULL: goto x86_l_1d88;
	case 7562ULL: goto x86_l_1d8a;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7573ULL: goto x86_l_1d95;
	case 7575ULL: goto x86_l_1d97;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7585ULL: goto x86_l_1da1;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7599ULL: goto x86_l_1daf;
	case 7602ULL: goto x86_l_1db2;
	case 7605ULL: goto x86_l_1db5;
	case 7609ULL: goto x86_l_1db9;
	case 7613ULL: goto x86_l_1dbd;
	case 7618ULL: goto x86_l_1dc2;
	case 7621ULL: goto x86_l_1dc5;
	case 7627ULL: goto x86_l_1dcb;
	case 7631ULL: goto x86_l_1dcf;
	case 7635ULL: goto x86_l_1dd3;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7645ULL: goto x86_l_1ddd;
	case 7648ULL: goto x86_l_1de0;
	case 7652ULL: goto x86_l_1de4;
	case 7656ULL: goto x86_l_1de8;
	case 7659ULL: goto x86_l_1deb;
	case 7661ULL: goto x86_l_1ded;
	case 7666ULL: goto x86_l_1df2;
	case 7671ULL: goto x86_l_1df7;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7685ULL: goto x86_l_1e05;
	case 7688ULL: goto x86_l_1e08;
	case 7692ULL: goto x86_l_1e0c;
	case 7696ULL: goto x86_l_1e10;
	case 7700ULL: goto x86_l_1e14;
	case 7703ULL: goto x86_l_1e17;
	case 7706ULL: goto x86_l_1e1a;
	case 7710ULL: goto x86_l_1e1e;
	case 7713ULL: goto x86_l_1e21;
	case 7716ULL: goto x86_l_1e24;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7732ULL: goto x86_l_1e34;
	case 7734ULL: goto x86_l_1e36;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7755ULL: goto x86_l_1e4b;
	case 7760ULL: goto x86_l_1e50;
	case 7769ULL: goto x86_l_1e59;
	case 7773ULL: goto x86_l_1e5d;
	case 7777ULL: goto x86_l_1e61;
	case 7781ULL: goto x86_l_1e65;
	case 7784ULL: goto x86_l_1e68;
	case 7786ULL: goto x86_l_1e6a;
	case 7791ULL: goto x86_l_1e6f;
	case 7796ULL: goto x86_l_1e74;
	case 7800ULL: goto x86_l_1e78;
	case 7805ULL: goto x86_l_1e7d;
	case 7811ULL: goto x86_l_1e83;
	case 7816ULL: goto x86_l_1e88;
	case 7819ULL: goto x86_l_1e8b;
	case 7823ULL: goto x86_l_1e8f;
	case 7826ULL: goto x86_l_1e92;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7837ULL: goto x86_l_1e9d;
	case 7839ULL: goto x86_l_1e9f;
	case 7842ULL: goto x86_l_1ea2;
	case 7845ULL: goto x86_l_1ea5;
	case 7849ULL: goto x86_l_1ea9;
	case 7853ULL: goto x86_l_1ead;
	case 7857ULL: goto x86_l_1eb1;
	case 7860ULL: goto x86_l_1eb4;
	case 7863ULL: goto x86_l_1eb7;
	case 7867ULL: goto x86_l_1ebb;
	case 7870ULL: goto x86_l_1ebe;
	case 7875ULL: goto x86_l_1ec3;
	case 7878ULL: goto x86_l_1ec6;
	case 7884ULL: goto x86_l_1ecc;
	case 7888ULL: goto x86_l_1ed0;
	case 7890ULL: goto x86_l_1ed2;
	case 7894ULL: goto x86_l_1ed6;
	case 7898ULL: goto x86_l_1eda;
	case 7908ULL: goto x86_l_1ee4;
	case 7913ULL: goto x86_l_1ee9;
	case 7921ULL: goto x86_l_1ef1;
	case 7927ULL: goto x86_l_1ef7;
	case 7932ULL: goto x86_l_1efc;
	case 7935ULL: goto x86_l_1eff;
	case 7941ULL: goto x86_l_1f05;
	case 7945ULL: goto x86_l_1f09;
	case 7951ULL: goto x86_l_1f0f;
	case 7959ULL: goto x86_l_1f17;
	case 7962ULL: goto x86_l_1f1a;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7975ULL: goto x86_l_1f27;
	case 7983ULL: goto x86_l_1f2f;
	case 7987ULL: goto x86_l_1f33;
	case 7993ULL: goto x86_l_1f39;
	case 7997ULL: goto x86_l_1f3d;
	case 8001ULL: goto x86_l_1f41;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8015ULL: goto x86_l_1f4f;
	case 8018ULL: goto x86_l_1f52;
	case 8020ULL: goto x86_l_1f54;
	case 8028ULL: goto x86_l_1f5c;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8037ULL: goto x86_l_1f65;
	case 8039ULL: goto x86_l_1f67;
	case 8041ULL: goto x86_l_1f69;
	case 8043ULL: goto x86_l_1f6b;
	case 8046ULL: goto x86_l_1f6e;
	case 8050ULL: goto x86_l_1f72;
	case 8054ULL: goto x86_l_1f76;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8063ULL: goto x86_l_1f7f;
	case 8067ULL: goto x86_l_1f83;
	case 8069ULL: goto x86_l_1f85;
	case 8072ULL: goto x86_l_1f88;
	case 8075ULL: goto x86_l_1f8b;
	case 8077ULL: goto x86_l_1f8d;
	case 8079ULL: goto x86_l_1f8f;
	case 8082ULL: goto x86_l_1f92;
	case 8084ULL: goto x86_l_1f94;
	case 8088ULL: goto x86_l_1f98;
	case 8090ULL: goto x86_l_1f9a;
	case 8095ULL: goto x86_l_1f9f;
	case 8098ULL: goto x86_l_1fa2;
	case 8100ULL: goto x86_l_1fa4;
	case 8103ULL: goto x86_l_1fa7;
	case 8107ULL: goto x86_l_1fab;
	case 8115ULL: goto x86_l_1fb3;
	case 8118ULL: goto x86_l_1fb6;
	case 8120ULL: goto x86_l_1fb8;
	case 8125ULL: goto x86_l_1fbd;
	case 8129ULL: goto x86_l_1fc1;
	case 8135ULL: goto x86_l_1fc7;
	case 8139ULL: goto x86_l_1fcb;
	case 8143ULL: goto x86_l_1fcf;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8160ULL: goto x86_l_1fe0;
	case 8162ULL: goto x86_l_1fe2;
	case 8169ULL: goto x86_l_1fe9;
	case 8171ULL: goto x86_l_1feb;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8190ULL: goto x86_l_1ffe;
	case 8193ULL: goto x86_l_2001;
	case 8199ULL: goto x86_l_2007;
	case 8208ULL: goto x86_l_2010;
	case 8210ULL: goto x86_l_2012;
	case 8212ULL: goto x86_l_2014;
	case 8216ULL: goto x86_l_2018;
	case 8225ULL: goto x86_l_2021;
	case 8228ULL: goto x86_l_2024;
	default: return 0xffffffffffffffffULL;
	}
x86_l_19d8:
	/* 0x19d8: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_19dd:
	/* 0x19dd: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_19e0:
	/* 0x19e0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e2:
	/* 0x19e2: call   rdx */
	X86_SIM_BPF_CALL_REG(X86_RDX);
x86_l_19e4:
	/* 0x19e4: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19e9:
	/* 0x19e9: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19eb:
	/* 0x19eb: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_19ed:
	/* 0x19ed: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_19ef:
	/* 0x19ef: mov    WORD PTR [rsp+0x66],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 102ULL);
x86_l_19f4:
	/* 0x19f4: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_19fb:
	/* 0x19fb: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_19ff:
	/* 0x19ff: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_1a06:
	/* 0x1a06: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a10:
	/* 0x1a10: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a12:
	/* 0x1a12: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a15:
	/* 0x1a15: je     1a1c <tail_lb_ipv4+0x1a1c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a1c;
	}
x86_l_1a17:
	/* 0x1a17: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1a:
	/* 0x1a1a: jmp    1a20 <tail_lb_ipv4+0x1a20> */
	goto x86_l_1a20;
x86_l_1a1c:
	/* 0x1a1c: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1a20:
	/* 0x1a20: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a25:
	/* 0x1a25: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_1a2c:
	/* 0x1a2c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a31:
	/* 0x1a31: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a36:
	/* 0x1a36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a38:
	/* 0x1a38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3b:
	/* 0x1a3b: je     1ab2 <tail_lb_ipv4+0x1ab2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ab2;
	}
x86_l_1a3d:
	/* 0x1a3d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1a45:
	/* 0x1a45: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1a48:
	/* 0x1a48: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1a4b:
	/* 0x1a4b: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1a54:
	/* 0x1a54: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_1a5d:
	/* 0x1a5d: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1a66:
	/* 0x1a66: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1a6f:
	/* 0x1a6f: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a78:
	/* 0x1a78: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1a81:
	/* 0x1a81: movzx  ebp,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_1a86:
	/* 0x1a86: mov    WORD PTR [rsp+0x4e],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1a8f:
	/* 0x1a8f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a94:
	/* 0x1a94: mov    r15,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1a9b:
	/* 0x1a9b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9f:
	/* 0x1a9f: je     1af2 <tail_lb_ipv4+0x1af2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1af2;
	}
x86_l_1aa1:
	/* 0x1aa1: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1aa8:
	/* 0x1aa8: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1aac:
	/* 0x1aac: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ab0:
	/* 0x1ab0: jmp    1af8 <tail_lb_ipv4+0x1af8> */
	goto x86_l_1af8;
x86_l_1ab2:
	/* 0x1ab2: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1ab9:
	/* 0x1ab9: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1abc:
	/* 0x1abc: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_1ac8:
	/* 0x1ac8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1acb:
	/* 0x1acb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ace:
	/* 0x1ace: jne    506 <tail_lb_ipv4+0x506> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1286ULL;
	}
x86_l_1ad4:
	/* 0x1ad4: movzx  eax,BYTE PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1ad8:
	/* 0x1ad8: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_1ada:
	/* 0x1ada: je     1e74 <tail_lb_ipv4+0x1e74> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e74;
	}
x86_l_1ae0:
	/* 0x1ae0: mov    ebp,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967138ULL);
x86_l_1ae5:
	/* 0x1ae5: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_1ae7:
	/* 0x1ae7: je     33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_1aed:
	/* 0x1aed: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_1af2:
	/* 0x1af2: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1af8:
	/* 0x1af8: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1afc:
	/* 0x1afc: jne    1b1b <tail_lb_ipv4+0x1b1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b1b;
	}
x86_l_1afe:
	/* 0x1afe: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b02:
	/* 0x1b02: je     1b15 <tail_lb_ipv4+0x1b15> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b15;
	}
x86_l_1b04:
	/* 0x1b04: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1b0b:
	/* 0x1b0b: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1b0f:
	/* 0x1b0f: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b13:
	/* 0x1b13: jmp    1b1b <tail_lb_ipv4+0x1b1b> */
	goto x86_l_1b1b;
x86_l_1b15:
	/* 0x1b15: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1b1b:
	/* 0x1b1b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1f:
	/* 0x1b1f: je     1b30 <tail_lb_ipv4+0x1b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b30;
	}
x86_l_1b21:
	/* 0x1b21: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1b26:
	/* 0x1b26: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b28:
	/* 0x1b28: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b2a:
	/* 0x1b2a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1b2e:
	/* 0x1b2e: jmp    1b53 <tail_lb_ipv4+0x1b53> */
	goto x86_l_1b53;
x86_l_1b30:
	/* 0x1b30: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b35:
	/* 0x1b35: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b37:
	/* 0x1b37: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b39:
	/* 0x1b39: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1b3d:
	/* 0x1b3d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1b47:
	/* 0x1b47: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1b4a:
	/* 0x1b4a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1b4f:
	/* 0x1b4f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1b53:
	/* 0x1b53: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1b57:
	/* 0x1b57: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b5a:
	/* 0x1b5a: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b5d:
	/* 0x1b5d: mov    DWORD PTR [rsp+0x48],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b62:
	/* 0x1b62: movzx  edx,BYTE PTR [rsp+0x52] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 82ULL);
x86_l_1b67:
	/* 0x1b67: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b6b:
	/* 0x1b6b: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1b6d:
	/* 0x1b6d: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b71:
	/* 0x1b71: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b79:
	/* 0x1b79: je     1b8f <tail_lb_ipv4+0x1b8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b8f;
	}
x86_l_1b7b:
	/* 0x1b7b: mov    r8,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1b82:
	/* 0x1b82: mov    r8d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b85:
	/* 0x1b85: lea    r8d,[r8+r8*4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 0ULL);
x86_l_1b89:
	/* 0x1b89: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b8d:
	/* 0x1b8d: jmp    1b95 <tail_lb_ipv4+0x1b95> */
	goto x86_l_1b95;
x86_l_1b8f:
	/* 0x1b8f: mov    r8d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5ULL);
x86_l_1b95:
	/* 0x1b95: movabs r15,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b9f:
	/* 0x1b9f: mov    rbp,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1ba7:
	/* 0x1ba7: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1baa:
	/* 0x1baa: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1bac:
	/* 0x1bac: cmp    r8d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_1baf:
	/* 0x1baf: jb     1bb5 <tail_lb_ipv4+0x1bb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1bb5;
	}
x86_l_1bb1:
	/* 0x1bb1: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_1bb3:
	/* 0x1bb3: je     1bc6 <tail_lb_ipv4+0x1bc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bc6;
	}
x86_l_1bb5:
	/* 0x1bb5: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1bbd:
	/* 0x1bbd: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1bc4:
	/* 0x1bc4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1bcd:
	/* 0x1bcd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd0:
	/* 0x1bd0: je     1be8 <tail_lb_ipv4+0x1be8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1be8;
	}
x86_l_1bd2:
	/* 0x1bd2: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1bdb:
	/* 0x1bdb: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bdd:
	/* 0x1bdd: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1be0:
	/* 0x1be0: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1be3:
	/* 0x1be3: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1be8:
	/* 0x1be8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bed:
	/* 0x1bed: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bf7:
	/* 0x1bf7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf9:
	/* 0x1bf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bfb:
	/* 0x1bfb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bfd:
	/* 0x1bfd: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c02:
	/* 0x1c02: js     2688 <tail_lb_ipv4+0x2688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9864ULL;
	}
x86_l_1c08:
	/* 0x1c08: movzx  eax,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_1c10:
	/* 0x1c10: mov    BYTE PTR [rsp+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_1c14:
	/* 0x1c14: test   BYTE PTR [rcx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1c18:
	/* 0x1c18: je     1cb4 <tail_lb_ipv4+0x1cb4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cb4;
	}
x86_l_1c1e:
	/* 0x1c1e: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1c25:
	/* 0x1c25: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c28:
	/* 0x1c28: je     1c39 <tail_lb_ipv4+0x1c39> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c39;
	}
x86_l_1c2a:
	/* 0x1c2a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1c2f:
	/* 0x1c2f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c31:
	/* 0x1c31: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c33:
	/* 0x1c33: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1c37:
	/* 0x1c37: jmp    1c5c <tail_lb_ipv4+0x1c5c> */
	goto x86_l_1c5c;
x86_l_1c39:
	/* 0x1c39: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1c3e:
	/* 0x1c3e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c40:
	/* 0x1c40: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c42:
	/* 0x1c42: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1c46:
	/* 0x1c46: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1c50:
	/* 0x1c50: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1c53:
	/* 0x1c53: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1c58:
	/* 0x1c58: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1c5c:
	/* 0x1c5c: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c64:
	/* 0x1c64: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c69:
	/* 0x1c69: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c6e:
	/* 0x1c6e: movzx  ecx,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1c72:
	/* 0x1c72: mov    WORD PTR [rsp+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c77:
	/* 0x1c77: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    DWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_1c86:
	/* 0x1c86: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c88:
	/* 0x1c88: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c8d:
	/* 0x1c8d: mov    DWORD PTR [rsp+0x78],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c92:
	/* 0x1c92: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_1c9a:
	/* 0x1c9a: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_1ca1:
	/* 0x1ca1: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ca6:
	/* 0x1ca6: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cab:
	/* 0x1cab: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1cb0:
	/* 0x1cb0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb2:
	/* 0x1cb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb4:
	/* 0x1cb4: mov    eax,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1cc0:
	/* 0x1cc0: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1cc8:
	/* 0x1cc8: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cd5:
	/* 0x1cd5: mov    BYTE PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_1cda:
	/* 0x1cda: mov    rdi,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_1ce1:
	/* 0x1ce1: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ceb:
	/* 0x1ceb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ced:
	/* 0x1ced: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cf2:
	/* 0x1cf2: movzx  edx,BYTE PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1cf6:
	/* 0x1cf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cf9:
	/* 0x1cf9: je     1d19 <tail_lb_ipv4+0x1d19> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d19;
	}
x86_l_1cfb:
	/* 0x1cfb: test   dl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 8ULL);
x86_l_1cfe:
	/* 0x1cfe: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d03:
	/* 0x1d03: jne    1d23 <tail_lb_ipv4+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d23;
	}
x86_l_1d05:
	/* 0x1d05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d08:
	/* 0x1d08: je     1d23 <tail_lb_ipv4+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d23;
	}
x86_l_1d0a:
	/* 0x1d0a: movzx  ecx,BYTE PTR [rcx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1d0e:
	/* 0x1d0e: and    cl,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_1d11:
	/* 0x1d11: jne    22d0 <tail_lb_ipv4+0x22d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8912ULL;
	}
x86_l_1d17:
	/* 0x1d17: jmp    1d23 <tail_lb_ipv4+0x1d23> */
	goto x86_l_1d23;
x86_l_1d19:
	/* 0x1d19: test   dl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 8ULL);
x86_l_1d1c:
	/* 0x1d1c: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d21:
	/* 0x1d21: jne    1d71 <tail_lb_ipv4+0x1d71> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d71;
	}
x86_l_1d23:
	/* 0x1d23: movzx  r9d,WORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1d28:
	/* 0x1d28: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d2d:
	/* 0x1d2d: movzx  esi,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1d32:
	/* 0x1d32: mov    ecx,DWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d35:
	/* 0x1d35: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d39:
	/* 0x1d39: movzx  edx,WORD PTR [rbp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1d3d:
	/* 0x1d3d: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1d40:
	/* 0x1d40: je     1d47 <tail_lb_ipv4+0x1d47> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d47;
	}
x86_l_1d42:
	/* 0x1d42: mov    WORD PTR [rsp+0x12],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1d47:
	/* 0x1d47: movzx  r10d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_1d4d:
	/* 0x1d4d: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_1d4f:
	/* 0x1d4f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d52:
	/* 0x1d52: test   rdi,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d55:
	/* 0x1d55: mov    DWORD PTR [rsp+0xa8],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d5d:
	/* 0x1d5d: mov    DWORD PTR [rsp+0x88],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1d65:
	/* 0x1d65: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_1d68:
	/* 0x1d68: je     1d7e <tail_lb_ipv4+0x1d7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d7e;
	}
x86_l_1d6a:
	/* 0x1d6a: mov    r11b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 1ULL);
x86_l_1d6d:
	/* 0x1d6d: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d6f:
	/* 0x1d6f: jmp    1db2 <tail_lb_ipv4+0x1db2> */
	goto x86_l_1db2;
x86_l_1d71:
	/* 0x1d71: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1d76:
	/* 0x1d76: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d79:
	/* 0x1d79: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_1d7e:
	/* 0x1d7e: cmp    r10d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 58ULL);
x86_l_1d82:
	/* 0x1d82: je     1da3 <tail_lb_ipv4+0x1da3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1da3;
	}
x86_l_1d84:
	/* 0x1d84: cmp    r10d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 17ULL);
x86_l_1d88:
	/* 0x1d88: je     1d97 <tail_lb_ipv4+0x1d97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d97;
	}
x86_l_1d8a:
	/* 0x1d8a: cmp    r10d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 6ULL);
x86_l_1d8e:
	/* 0x1d8e: jne    1dad <tail_lb_ipv4+0x1dad> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1dad;
	}
x86_l_1d90:
	/* 0x1d90: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_1d95:
	/* 0x1d95: jmp    1da8 <tail_lb_ipv4+0x1da8> */
	goto x86_l_1da8;
x86_l_1d97:
	/* 0x1d97: mov    edi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1d9c:
	/* 0x1d9c: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9f:
	/* 0x1d9f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da1:
	/* 0x1da1: jmp    1db2 <tail_lb_ipv4+0x1db2> */
	goto x86_l_1db2;
x86_l_1da3:
	/* 0x1da3: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1da8:
	/* 0x1da8: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dab:
	/* 0x1dab: jmp    1db2 <tail_lb_ipv4+0x1db2> */
	goto x86_l_1db2;
x86_l_1dad:
	/* 0x1dad: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1daf:
	/* 0x1daf: mov    r11b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_8, 1ULL);
x86_l_1db2:
	/* 0x1db2: mov    r9d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1db5:
	/* 0x1db5: mov    r10d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1db9:
	/* 0x1db9: lea    r15,[r9+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1dc2:
	/* 0x1dc2: cmp    r15,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_R10, X86_WIDTH_64);
x86_l_1dc5:
	/* 0x1dc5: ja     b5 <tail_lb_ipv4+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 181ULL;
	}
x86_l_1dcb:
	/* 0x1dcb: mov    r10d,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dcf:
	/* 0x1dcf: mov    DWORD PTR [r9+0x1e],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1dd3:
	/* 0x1dd3: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1dd6:
	/* 0x1dd6: add    r8d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1dd9:
	/* 0x1dd9: adc    r8d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1ddd:
	/* 0x1ddd: mov    r10d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1de0:
	/* 0x1de0: mov    r9d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1de4:
	/* 0x1de4: lea    r15,[r10+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1de8:
	/* 0x1de8: cmp    r15,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_R9, X86_WIDTH_64);
x86_l_1deb:
	/* 0x1deb: jbe    1df7 <tail_lb_ipv4+0x1df7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1df7;
	}
x86_l_1ded:
	/* 0x1ded: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_1df2:
	/* 0x1df2: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_1df7:
	/* 0x1df7: mov    WORD PTR [rsp+0x6],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1dfd:
	/* 0x1dfd: movzx  r15d,WORD PTR [r10+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R10, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1e02:
	/* 0x1e02: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1e05:
	/* 0x1e05: add    r15d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e08:
	/* 0x1e08: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1e0c:
	/* 0x1e0c: movzx  r12d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e10:
	/* 0x1e10: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1e14:
	/* 0x1e14: add    r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e17:
	/* 0x1e17: mov    r12d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_32);
x86_l_1e1a:
	/* 0x1e1a: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1e1e:
	/* 0x1e1e: add    r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e21:
	/* 0x1e21: not    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1e24:
	/* 0x1e24: mov    WORD PTR [r10+0x18],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R10, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e29:
	/* 0x1e29: test   r11b,r11b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_8);
x86_l_1e2c:
	/* 0x1e2c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e34:
	/* 0x1e34: je     1e50 <tail_lb_ipv4+0x1e50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e50;
	}
x86_l_1e36:
	/* 0x1e36: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_1e40:
	/* 0x1e40: test   QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e45:
	/* 0x1e45: je     1ef7 <tail_lb_ipv4+0x1ef7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ef7;
	}
x86_l_1e4b:
	/* 0x1e4b: jmp    1fb3 <tail_lb_ipv4+0x1fb3> */
	goto x86_l_1fb3;
x86_l_1e50:
	/* 0x1e50: movzx  r11d,BYTE PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_1e59:
	/* 0x1e59: lea    rax,[r10+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1e5d:
	/* 0x1e5d: lea    r15,[r11+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1e61:
	/* 0x1e61: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1e65:
	/* 0x1e65: cmp    r15,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_R9, X86_WIDTH_64);
x86_l_1e68:
	/* 0x1e68: jbe    1e88 <tail_lb_ipv4+0x1e88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e88;
	}
x86_l_1e6a:
	/* 0x1e6a: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1e6f:
	/* 0x1e6f: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_1e74:
	/* 0x1e74: test   BYTE PTR [rcx+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_1e78:
	/* 0x1e78: mov    ebp,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967138ULL);
x86_l_1e7d:
	/* 0x1e7d: je     33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_1e83:
	/* 0x1e83: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
x86_l_1e88:
	/* 0x1e88: add    rax,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e8b:
	/* 0x1e8b: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e8f:
	/* 0x1e8f: test   r11d,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_32);
x86_l_1e92:
	/* 0x1e92: setne  r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_NE);
x86_l_1e96:
	/* 0x1e96: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e99:
	/* 0x1e99: cmp    r15b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 1ULL);
x86_l_1e9d:
	/* 0x1e9d: jne    1eda <tail_lb_ipv4+0x1eda> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1eda;
	}
x86_l_1e9f:
	/* 0x1e9f: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1ea2:
	/* 0x1ea2: add    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ea5:
	/* 0x1ea5: adc    r8d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1ea9:
	/* 0x1ea9: movzx  r11d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ead:
	/* 0x1ead: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1eb1:
	/* 0x1eb1: add    r8d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1eb4:
	/* 0x1eb4: mov    r11d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R8, X86_WIDTH_32);
x86_l_1eb7:
	/* 0x1eb7: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1ebb:
	/* 0x1ebb: add    r11d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ebe:
	/* 0x1ebe: cmp    r11w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_16, 65535ULL);
x86_l_1ec3:
	/* 0x1ec3: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1ec6:
	/* 0x1ec6: mov    r8d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 65535ULL);
x86_l_1ecc:
	/* 0x1ecc: cmovne r8d,r11d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R11, X86_WIDTH_32, X86_CC_NE);
x86_l_1ed0:
	/* 0x1ed0: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ed2:
	/* 0x1ed2: cmovne r8d,r11d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R11, X86_WIDTH_32, X86_CC_NE);
x86_l_1ed6:
	/* 0x1ed6: mov    WORD PTR [rax],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eda:
	/* 0x1eda: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1ee4:
	/* 0x1ee4: test   QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ee9:
	/* 0x1ee9: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1ef1:
	/* 0x1ef1: jne    1fb3 <tail_lb_ipv4+0x1fb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fb3;
	}
x86_l_1ef7:
	/* 0x1ef7: movzx  r11d,WORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1efc:
	/* 0x1efc: test   r11d,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_32);
x86_l_1eff:
	/* 0x1eff: je     1fb3 <tail_lb_ipv4+0x1fb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb3;
	}
x86_l_1f05:
	/* 0x1f05: cmp    si,r11w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R11, X86_WIDTH_16);
x86_l_1f09:
	/* 0x1f09: je     1fb3 <tail_lb_ipv4+0x1fb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb3;
	}
x86_l_1f0f:
	/* 0x1f0f: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f17:
	/* 0x1f17: add    rax,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f1a:
	/* 0x1f1a: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1f1e:
	/* 0x1f1e: cmp    rax,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R9, X86_WIDTH_64);
x86_l_1f21:
	/* 0x1f21: ja     b5 <tail_lb_ipv4+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 181ULL;
	}
x86_l_1f27:
	/* 0x1f27: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f2f:
	/* 0x1f2f: lea    r8,[r10+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1f33:
	/* 0x1f33: mov    WORD PTR [r10+rax*1+0x2],r11w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R10, X86_R11, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 2ULL);
x86_l_1f39:
	/* 0x1f39: lea    rax,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_1f3d:
	/* 0x1f3d: add    rax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1f41:
	/* 0x1f41: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1f46:
	/* 0x1f46: cmp    rax,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R9, X86_WIDTH_64);
x86_l_1f49:
	/* 0x1f49: ja     b5 <tail_lb_ipv4+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 181ULL;
	}
x86_l_1f4f:
	/* 0x1f4f: add    r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f52:
	/* 0x1f52: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1f54:
	/* 0x1f54: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f5c:
	/* 0x1f5c: jne    1f65 <tail_lb_ipv4+0x1f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1f65;
	}
x86_l_1f5e:
	/* 0x1f5e: cmp    WORD PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f63:
	/* 0x1f63: je     1fb3 <tail_lb_ipv4+0x1fb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb3;
	}
x86_l_1f65:
	/* 0x1f65: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_1f67:
	/* 0x1f67: je     1f72 <tail_lb_ipv4+0x1f72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1f72;
	}
x86_l_1f69:
	/* 0x1f69: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1f6b:
	/* 0x1f6b: add    r11d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f6e:
	/* 0x1f6e: adc    r11d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1f72:
	/* 0x1f72: movzx  eax,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f76:
	/* 0x1f76: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1f78:
	/* 0x1f78: add    eax,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f7b:
	/* 0x1f7b: setb   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_B);
x86_l_1f7f:
	/* 0x1f7f: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f83:
	/* 0x1f83: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f85:
	/* 0x1f85: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1f88:
	/* 0x1f88: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1f8b:
	/* 0x1f8b: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f8d:
	/* 0x1f8d: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_1f8f:
	/* 0x1f8f: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1f92:
	/* 0x1f92: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f94:
	/* 0x1f94: cmp    ax,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 65535ULL);
x86_l_1f98:
	/* 0x1f98: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1f9a:
	/* 0x1f9a: mov    esi,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 65535ULL);
x86_l_1f9f:
	/* 0x1f9f: cmovne esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1fa2:
	/* 0x1fa2: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1fa4:
	/* 0x1fa4: cmovne esi,eax */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1fa7:
	/* 0x1fa7: mov    WORD PTR [r8],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fab:
	/* 0x1fab: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1fb3:
	/* 0x1fb3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb6:
	/* 0x1fb6: jne    1fc7 <tail_lb_ipv4+0x1fc7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fc7;
	}
x86_l_1fb8:
	/* 0x1fb8: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fbd:
	/* 0x1fbd: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_1fc1:
	/* 0x1fc1: js     2430 <tail_lb_ipv4+0x2430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9264ULL;
	}
x86_l_1fc7:
	/* 0x1fc7: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1fcf:
	/* 0x1fcf: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fd3:
	/* 0x1fd3: rol    DWORD PTR [rsp+0x10],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 68719476752ULL);
x86_l_1fd8:
	/* 0x1fd8: cmp    DWORD PTR [rsp+0x88],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552262ULL);
x86_l_1fe0:
	/* 0x1fe0: je     1feb <tail_lb_ipv4+0x1feb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1feb;
	}
x86_l_1fe2:
	/* 0x1fe2: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1fe9:
	/* 0x1fe9: jmp    1ff2 <tail_lb_ipv4+0x1ff2> */
	goto x86_l_1ff2;
x86_l_1feb:
	/* 0x1feb: mov    r14,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1ff2:
	/* 0x1ff2: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_1ff7:
	/* 0x1ff7: mov    rax,QWORD PTR [rip+0xdbda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1ffe:
	/* 0x1ffe: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2001:
	/* 0x2001: je     2085 <tail_lb_ipv4+0x2085> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8325ULL;
	}
x86_l_2007:
	/* 0x2007: cmp    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_2010:
	/* 0x2010: je     2085 <tail_lb_ipv4+0x2085> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8325ULL;
	}
x86_l_2012:
	/* 0x2012: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2014:
	/* 0x2014: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2018:
	/* 0x2018: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2021:
	/* 0x2021: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2024:
	/* 0x2024: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
	return 8237ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8237ULL: goto x86_l_202d;
	case 8247ULL: goto x86_l_2037;
	case 8252ULL: goto x86_l_203c;
	case 8259ULL: goto x86_l_2043;
	case 8264ULL: goto x86_l_2048;
	case 8269ULL: goto x86_l_204d;
	case 8271ULL: goto x86_l_204f;
	case 8274ULL: goto x86_l_2052;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8283ULL: goto x86_l_205b;
	case 8285ULL: goto x86_l_205d;
	case 8294ULL: goto x86_l_2066;
	case 8299ULL: goto x86_l_206b;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8316ULL: goto x86_l_207c;
	case 8321ULL: goto x86_l_2081;
	case 8323ULL: goto x86_l_2083;
	case 8325ULL: goto x86_l_2085;
	case 8327ULL: goto x86_l_2087;
	case 8337ULL: goto x86_l_2091;
	case 8342ULL: goto x86_l_2096;
	case 8344ULL: goto x86_l_2098;
	case 8350ULL: goto x86_l_209e;
	case 8358ULL: goto x86_l_20a6;
	case 8360ULL: goto x86_l_20a8;
	case 8362ULL: goto x86_l_20aa;
	case 8365ULL: goto x86_l_20ad;
	case 8373ULL: goto x86_l_20b5;
	case 8377ULL: goto x86_l_20b9;
	case 8381ULL: goto x86_l_20bd;
	case 8384ULL: goto x86_l_20c0;
	case 8390ULL: goto x86_l_20c6;
	case 8393ULL: goto x86_l_20c9;
	case 8397ULL: goto x86_l_20cd;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8407ULL: goto x86_l_20d7;
	case 8412ULL: goto x86_l_20dc;
	case 8415ULL: goto x86_l_20df;
	case 8421ULL: goto x86_l_20e5;
	case 8427ULL: goto x86_l_20eb;
	case 8430ULL: goto x86_l_20ee;
	case 8432ULL: goto x86_l_20f0;
	case 8435ULL: goto x86_l_20f3;
	case 8440ULL: goto x86_l_20f8;
	case 8445ULL: goto x86_l_20fd;
	case 8448ULL: goto x86_l_2100;
	case 8450ULL: goto x86_l_2102;
	case 8453ULL: goto x86_l_2105;
	case 8455ULL: goto x86_l_2107;
	case 8459ULL: goto x86_l_210b;
	case 8462ULL: goto x86_l_210e;
	case 8464ULL: goto x86_l_2110;
	case 8468ULL: goto x86_l_2114;
	case 8471ULL: goto x86_l_2117;
	case 8473ULL: goto x86_l_2119;
	case 8479ULL: goto x86_l_211f;
	case 8485ULL: goto x86_l_2125;
	case 8490ULL: goto x86_l_212a;
	case 8496ULL: goto x86_l_2130;
	case 8503ULL: goto x86_l_2137;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8514ULL: goto x86_l_2142;
	case 8516ULL: goto x86_l_2144;
	case 8523ULL: goto x86_l_214b;
	case 8525ULL: goto x86_l_214d;
	case 8532ULL: goto x86_l_2154;
	case 8541ULL: goto x86_l_215d;
	case 8550ULL: goto x86_l_2166;
	case 8559ULL: goto x86_l_216f;
	case 8568ULL: goto x86_l_2178;
	case 8577ULL: goto x86_l_2181;
	case 8582ULL: goto x86_l_2186;
	case 8587ULL: goto x86_l_218b;
	case 8595ULL: goto x86_l_2193;
	case 8604ULL: goto x86_l_219c;
	case 8613ULL: goto x86_l_21a5;
	case 8620ULL: goto x86_l_21ac;
	case 8627ULL: goto x86_l_21b3;
	case 8631ULL: goto x86_l_21b7;
	case 8633ULL: goto x86_l_21b9;
	case 8640ULL: goto x86_l_21c0;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8650ULL: goto x86_l_21ca;
	case 8656ULL: goto x86_l_21d0;
	case 8660ULL: goto x86_l_21d4;
	case 8662ULL: goto x86_l_21d6;
	case 8669ULL: goto x86_l_21dd;
	case 8673ULL: goto x86_l_21e1;
	case 8675ULL: goto x86_l_21e3;
	case 8682ULL: goto x86_l_21ea;
	case 8686ULL: goto x86_l_21ee;
	case 8690ULL: goto x86_l_21f2;
	case 8692ULL: goto x86_l_21f4;
	case 8698ULL: goto x86_l_21fa;
	case 8702ULL: goto x86_l_21fe;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8711ULL: goto x86_l_2207;
	case 8713ULL: goto x86_l_2209;
	case 8717ULL: goto x86_l_220d;
	case 8719ULL: goto x86_l_220f;
	case 8724ULL: goto x86_l_2214;
	case 8726ULL: goto x86_l_2216;
	case 8728ULL: goto x86_l_2218;
	case 8732ULL: goto x86_l_221c;
	case 8742ULL: goto x86_l_2226;
	case 8745ULL: goto x86_l_2229;
	case 8750ULL: goto x86_l_222e;
	case 8754ULL: goto x86_l_2232;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8764ULL: goto x86_l_223c;
	case 8769ULL: goto x86_l_2241;
	case 8774ULL: goto x86_l_2246;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8784ULL: goto x86_l_2250;
	case 8786ULL: goto x86_l_2252;
	case 8793ULL: goto x86_l_2259;
	case 8795ULL: goto x86_l_225b;
	case 8798ULL: goto x86_l_225e;
	case 8801ULL: goto x86_l_2261;
	case 8803ULL: goto x86_l_2263;
	case 8808ULL: goto x86_l_2268;
	case 8810ULL: goto x86_l_226a;
	case 8812ULL: goto x86_l_226c;
	case 8814ULL: goto x86_l_226e;
	case 8816ULL: goto x86_l_2270;
	case 8818ULL: goto x86_l_2272;
	case 8820ULL: goto x86_l_2274;
	case 8824ULL: goto x86_l_2278;
	case 8828ULL: goto x86_l_227c;
	case 8835ULL: goto x86_l_2283;
	case 8837ULL: goto x86_l_2285;
	case 8844ULL: goto x86_l_228c;
	case 8847ULL: goto x86_l_228f;
	case 8849ULL: goto x86_l_2291;
	case 8858ULL: goto x86_l_229a;
	case 8860ULL: goto x86_l_229c;
	case 8863ULL: goto x86_l_229f;
	case 8866ULL: goto x86_l_22a2;
	case 8871ULL: goto x86_l_22a7;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8886ULL: goto x86_l_22b6;
	case 8889ULL: goto x86_l_22b9;
	case 8891ULL: goto x86_l_22bb;
	case 8893ULL: goto x86_l_22bd;
	case 8895ULL: goto x86_l_22bf;
	case 8901ULL: goto x86_l_22c5;
	case 8910ULL: goto x86_l_22ce;
	case 8912ULL: goto x86_l_22d0;
	case 8920ULL: goto x86_l_22d8;
	case 8927ULL: goto x86_l_22df;
	case 8932ULL: goto x86_l_22e4;
	case 8938ULL: goto x86_l_22ea;
	case 8941ULL: goto x86_l_22ed;
	case 8944ULL: goto x86_l_22f0;
	case 8950ULL: goto x86_l_22f6;
	case 8953ULL: goto x86_l_22f9;
	case 8956ULL: goto x86_l_22fc;
	case 8964ULL: goto x86_l_2304;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8979ULL: goto x86_l_2313;
	case 8982ULL: goto x86_l_2316;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8996ULL: goto x86_l_2324;
	case 9005ULL: goto x86_l_232d;
	case 9008ULL: goto x86_l_2330;
	case 9011ULL: goto x86_l_2333;
	case 9015ULL: goto x86_l_2337;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9029ULL: goto x86_l_2345;
	case 9033ULL: goto x86_l_2349;
	case 9036ULL: goto x86_l_234c;
	case 9042ULL: goto x86_l_2352;
	case 9047ULL: goto x86_l_2357;
	case 9053ULL: goto x86_l_235d;
	case 9057ULL: goto x86_l_2361;
	case 9061ULL: goto x86_l_2365;
	case 9065ULL: goto x86_l_2369;
	case 9072ULL: goto x86_l_2370;
	case 9077ULL: goto x86_l_2375;
	case 9080ULL: goto x86_l_2378;
	case 9082ULL: goto x86_l_237a;
	case 9085ULL: goto x86_l_237d;
	case 9087ULL: goto x86_l_237f;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9100ULL: goto x86_l_238c;
	case 9102ULL: goto x86_l_238e;
	case 9109ULL: goto x86_l_2395;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9126ULL: goto x86_l_23a6;
	case 9128ULL: goto x86_l_23a8;
	case 9134ULL: goto x86_l_23ae;
	case 9139ULL: goto x86_l_23b3;
	case 9143ULL: goto x86_l_23b7;
	case 9145ULL: goto x86_l_23b9;
	case 9153ULL: goto x86_l_23c1;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9171ULL: goto x86_l_23d3;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9179ULL: goto x86_l_23db;
	case 9185ULL: goto x86_l_23e1;
	case 9193ULL: goto x86_l_23e9;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9208ULL: goto x86_l_23f8;
	case 9211ULL: goto x86_l_23fb;
	case 9213ULL: goto x86_l_23fd;
	case 9220ULL: goto x86_l_2404;
	case 9223ULL: goto x86_l_2407;
	case 9230ULL: goto x86_l_240e;
	case 9236ULL: goto x86_l_2414;
	case 9241ULL: goto x86_l_2419;
	case 9244ULL: goto x86_l_241c;
	case 9249ULL: goto x86_l_2421;
	case 9254ULL: goto x86_l_2426;
	case 9259ULL: goto x86_l_242b;
	case 9264ULL: goto x86_l_2430;
	case 9269ULL: goto x86_l_2435;
	case 9277ULL: goto x86_l_243d;
	case 9284ULL: goto x86_l_2444;
	case 9289ULL: goto x86_l_2449;
	case 9295ULL: goto x86_l_244f;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9303ULL: goto x86_l_2457;
	case 9305ULL: goto x86_l_2459;
	case 9309ULL: goto x86_l_245d;
	case 9317ULL: goto x86_l_2465;
	case 9324ULL: goto x86_l_246c;
	case 9329ULL: goto x86_l_2471;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9337ULL: goto x86_l_2479;
	case 9340ULL: goto x86_l_247c;
	case 9347ULL: goto x86_l_2483;
	case 9353ULL: goto x86_l_2489;
	case 9358ULL: goto x86_l_248e;
	case 9361ULL: goto x86_l_2491;
	case 9366ULL: goto x86_l_2496;
	case 9371ULL: goto x86_l_249b;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9380ULL: goto x86_l_24a4;
	case 9382ULL: goto x86_l_24a6;
	case 9388ULL: goto x86_l_24ac;
	case 9395ULL: goto x86_l_24b3;
	case 9400ULL: goto x86_l_24b8;
	case 9402ULL: goto x86_l_24ba;
	case 9409ULL: goto x86_l_24c1;
	case 9413ULL: goto x86_l_24c5;
	case 9417ULL: goto x86_l_24c9;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9426ULL: goto x86_l_24d2;
	case 9432ULL: goto x86_l_24d8;
	case 9440ULL: goto x86_l_24e0;
	case 9442ULL: goto x86_l_24e2;
	case 9444ULL: goto x86_l_24e4;
	case 9446ULL: goto x86_l_24e6;
	case 9449ULL: goto x86_l_24e9;
	case 9452ULL: goto x86_l_24ec;
	case 9454ULL: goto x86_l_24ee;
	case 9459ULL: goto x86_l_24f3;
	case 9463ULL: goto x86_l_24f7;
	case 9466ULL: goto x86_l_24fa;
	case 9471ULL: goto x86_l_24ff;
	case 9477ULL: goto x86_l_2505;
	case 9481ULL: goto x86_l_2509;
	case 9486ULL: goto x86_l_250e;
	case 9488ULL: goto x86_l_2510;
	case 9495ULL: goto x86_l_2517;
	case 9499ULL: goto x86_l_251b;
	case 9503ULL: goto x86_l_251f;
	case 9507ULL: goto x86_l_2523;
	case 9511ULL: goto x86_l_2527;
	case 9516ULL: goto x86_l_252c;
	case 9518ULL: goto x86_l_252e;
	case 9523ULL: goto x86_l_2533;
	case 9525ULL: goto x86_l_2535;
	case 9527ULL: goto x86_l_2537;
	case 9531ULL: goto x86_l_253b;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9540ULL: goto x86_l_2544;
	case 9542ULL: goto x86_l_2546;
	case 9546ULL: goto x86_l_254a;
	case 9556ULL: goto x86_l_2554;
	case 9559ULL: goto x86_l_2557;
	case 9564ULL: goto x86_l_255c;
	case 9568ULL: goto x86_l_2560;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9580ULL: goto x86_l_256c;
	case 9584ULL: goto x86_l_2570;
	case 9587ULL: goto x86_l_2573;
	case 9591ULL: goto x86_l_2577;
	case 9596ULL: goto x86_l_257c;
	case 9598ULL: goto x86_l_257e;
	case 9605ULL: goto x86_l_2585;
	case 9607ULL: goto x86_l_2587;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9615ULL: goto x86_l_258f;
	case 9620ULL: goto x86_l_2594;
	case 9622ULL: goto x86_l_2596;
	case 9625ULL: goto x86_l_2599;
	case 9627ULL: goto x86_l_259b;
	case 9629ULL: goto x86_l_259d;
	case 9632ULL: goto x86_l_25a0;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9643ULL: goto x86_l_25ab;
	case 9646ULL: goto x86_l_25ae;
	case 9653ULL: goto x86_l_25b5;
	case 9655ULL: goto x86_l_25b7;
	case 9662ULL: goto x86_l_25be;
	case 9665ULL: goto x86_l_25c1;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9679ULL: goto x86_l_25cf;
	case 9682ULL: goto x86_l_25d2;
	case 9685ULL: goto x86_l_25d5;
	case 9690ULL: goto x86_l_25da;
	case 9694ULL: goto x86_l_25de;
	case 9696ULL: goto x86_l_25e0;
	case 9700ULL: goto x86_l_25e4;
	case 9706ULL: goto x86_l_25ea;
	case 9711ULL: goto x86_l_25ef;
	case 9715ULL: goto x86_l_25f3;
	case 9717ULL: goto x86_l_25f5;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9734ULL: goto x86_l_2606;
	case 9739ULL: goto x86_l_260b;
	case 9743ULL: goto x86_l_260f;
	case 9750ULL: goto x86_l_2616;
	case 9754ULL: goto x86_l_261a;
	case 9760ULL: goto x86_l_2620;
	case 9767ULL: goto x86_l_2627;
	case 9771ULL: goto x86_l_262b;
	case 9775ULL: goto x86_l_262f;
	case 9780ULL: goto x86_l_2634;
	case 9782ULL: goto x86_l_2636;
	case 9787ULL: goto x86_l_263b;
	case 9791ULL: goto x86_l_263f;
	case 9795ULL: goto x86_l_2643;
	case 9799ULL: goto x86_l_2647;
	case 9804ULL: goto x86_l_264c;
	case 9808ULL: goto x86_l_2650;
	case 9812ULL: goto x86_l_2654;
	case 9819ULL: goto x86_l_265b;
	case 9822ULL: goto x86_l_265e;
	case 9824ULL: goto x86_l_2660;
	case 9830ULL: goto x86_l_2666;
	case 9837ULL: goto x86_l_266d;
	case 9841ULL: goto x86_l_2671;
	case 9843ULL: goto x86_l_2673;
	case 9850ULL: goto x86_l_267a;
	case 9852ULL: goto x86_l_267c;
	case 9854ULL: goto x86_l_267e;
	case 9858ULL: goto x86_l_2682;
	case 9862ULL: goto x86_l_2686;
	case 9864ULL: goto x86_l_2688;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	default: return 0xffffffffffffffffULL;
	}
x86_l_202d:
	/* 0x202d: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_2037:
	/* 0x2037: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_203c:
	/* 0x203c: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2043:
	/* 0x2043: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2048:
	/* 0x2048: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_204d:
	/* 0x204d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204f:
	/* 0x204f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2052:
	/* 0x2052: je     205d <tail_lb_ipv4+0x205d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_205d;
	}
x86_l_2054:
	/* 0x2054: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2057:
	/* 0x2057: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_205b:
	/* 0x205b: jmp    2085 <tail_lb_ipv4+0x2085> */
	goto x86_l_2085;
x86_l_205d:
	/* 0x205d: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2066:
	/* 0x2066: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_206b:
	/* 0x206b: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2072:
	/* 0x2072: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2077:
	/* 0x2077: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_207c:
	/* 0x207c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2081:
	/* 0x2081: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2083:
	/* 0x2083: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2085:
	/* 0x2085: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2087:
	/* 0x2087: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2091:
	/* 0x2091: test   QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2096:
	/* 0x2096: jne    20f0 <tail_lb_ipv4+0x20f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20f0;
	}
x86_l_2098:
	/* 0x2098: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_209e:
	/* 0x209e: cmp    BYTE PTR [rsp+0x88],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552262ULL);
x86_l_20a6:
	/* 0x20a6: jne    20f3 <tail_lb_ipv4+0x20f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_20f3;
	}
x86_l_20a8:
	/* 0x20a8: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20aa:
	/* 0x20aa: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_20ad:
	/* 0x20ad: movzx  ecx,BYTE PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_20b5:
	/* 0x20b5: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_20b9:
	/* 0x20b9: add    rsi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_20bd:
	/* 0x20bd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_20c0:
	/* 0x20c0: ja     a9e <tail_lb_ipv4+0xa9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2718ULL;
	}
x86_l_20c6:
	/* 0x20c6: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20c9:
	/* 0x20c9: movzx  ebp,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_20cd:
	/* 0x20cd: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_20cf:
	/* 0x20cf: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_20d4:
	/* 0x20d4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d7:
	/* 0x20d7: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_20dc:
	/* 0x20dc: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_20df:
	/* 0x20df: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_20e5:
	/* 0x20e5: jne    2732 <tail_lb_ipv4+0x2732> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10034ULL;
	}
x86_l_20eb:
	/* 0x20eb: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_20ee:
	/* 0x20ee: jmp    20f3 <tail_lb_ipv4+0x20f3> */
	goto x86_l_20f3;
x86_l_20f0:
	/* 0x20f0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20f3:
	/* 0x20f3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f8:
	/* 0x20f8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20fd:
	/* 0x20fd: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_2100:
	/* 0x2100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2102:
	/* 0x2102: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2105:
	/* 0x2105: je     2130 <tail_lb_ipv4+0x2130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2130;
	}
x86_l_2107:
	/* 0x2107: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_210b:
	/* 0x210b: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_210e:
	/* 0x210e: je     2130 <tail_lb_ipv4+0x2130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2130;
	}
x86_l_2110:
	/* 0x2110: movzx  edx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2114:
	/* 0x2114: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_2117:
	/* 0x2117: je     2130 <tail_lb_ipv4+0x2130> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2130;
	}
x86_l_2119:
	/* 0x2119: cmp    WORD PTR [rsp+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_211f:
	/* 0x211f: je     249b <tail_lb_ipv4+0x249b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249b;
	}
x86_l_2125:
	/* 0x2125: cmp    dx,WORD PTR [rsp+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_212a:
	/* 0x212a: je     249b <tail_lb_ipv4+0x249b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_249b;
	}
x86_l_2130:
	/* 0x2130: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2137:
	/* 0x2137: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2139:
	/* 0x2139: movzx  ebp,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_213e:
	/* 0x213e: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2142:
	/* 0x2142: jne    214d <tail_lb_ipv4+0x214d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_214d;
	}
x86_l_2144:
	/* 0x2144: mov    r14,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_214b:
	/* 0x214b: jmp    2154 <tail_lb_ipv4+0x2154> */
	goto x86_l_2154;
x86_l_214d:
	/* 0x214d: mov    r14,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_2154:
	/* 0x2154: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_215d:
	/* 0x215d: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_2166:
	/* 0x2166: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_216f:
	/* 0x216f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_2178:
	/* 0x2178: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2181:
	/* 0x2181: movzx  eax,WORD PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2186:
	/* 0x2186: mov    WORD PTR [rsp+0x4e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_218b:
	/* 0x218b: mov    DWORD PTR [rsp+0x54],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252873ULL);
x86_l_2193:
	/* 0x2193: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_219c:
	/* 0x219c: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_21a5:
	/* 0x21a5: mov    WORD PTR [rsp+0x4c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514528ULL);
x86_l_21ac:
	/* 0x21ac: mov    r15,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_21b3:
	/* 0x21b3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b7:
	/* 0x21b7: je     21ca <tail_lb_ipv4+0x21ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21ca;
	}
x86_l_21b9:
	/* 0x21b9: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_21c0:
	/* 0x21c0: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_21c4:
	/* 0x21c4: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_21c8:
	/* 0x21c8: jmp    21d0 <tail_lb_ipv4+0x21d0> */
	goto x86_l_21d0;
x86_l_21ca:
	/* 0x21ca: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_21d0:
	/* 0x21d0: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_21d4:
	/* 0x21d4: jne    21fa <tail_lb_ipv4+0x21fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21fa;
	}
x86_l_21d6:
	/* 0x21d6: mov    WORD PTR [rsp+0x4c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 326417514528ULL);
x86_l_21dd:
	/* 0x21dd: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e1:
	/* 0x21e1: je     21f4 <tail_lb_ipv4+0x21f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f4;
	}
x86_l_21e3:
	/* 0x21e3: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_21ea:
	/* 0x21ea: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_21ee:
	/* 0x21ee: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_21f2:
	/* 0x21f2: jmp    21fa <tail_lb_ipv4+0x21fa> */
	goto x86_l_21fa;
x86_l_21f4:
	/* 0x21f4: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_21fa:
	/* 0x21fa: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21fe:
	/* 0x21fe: je     220f <tail_lb_ipv4+0x220f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_220f;
	}
x86_l_2200:
	/* 0x2200: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2205:
	/* 0x2205: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2207:
	/* 0x2207: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2209:
	/* 0x2209: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_220d:
	/* 0x220d: jmp    2232 <tail_lb_ipv4+0x2232> */
	goto x86_l_2232;
x86_l_220f:
	/* 0x220f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2214:
	/* 0x2214: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2216:
	/* 0x2216: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2218:
	/* 0x2218: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_221c:
	/* 0x221c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2226:
	/* 0x2226: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2229:
	/* 0x2229: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_222e:
	/* 0x222e: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2232:
	/* 0x2232: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2236:
	/* 0x2236: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2239:
	/* 0x2239: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_223c:
	/* 0x223c: mov    DWORD PTR [rsp+0x48],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2241:
	/* 0x2241: movzx  edx,BYTE PTR [rsp+0x52] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 82ULL);
x86_l_2246:
	/* 0x2246: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_224a:
	/* 0x224a: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_224c:
	/* 0x224c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2250:
	/* 0x2250: je     2263 <tail_lb_ipv4+0x2263> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2263;
	}
x86_l_2252:
	/* 0x2252: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2259:
	/* 0x2259: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_225b:
	/* 0x225b: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_225e:
	/* 0x225e: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2261:
	/* 0x2261: jmp    2268 <tail_lb_ipv4+0x2268> */
	goto x86_l_2268;
x86_l_2263:
	/* 0x2263: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_2268:
	/* 0x2268: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_226a:
	/* 0x226a: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_226c:
	/* 0x226c: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_226e:
	/* 0x226e: jb     2274 <tail_lb_ipv4+0x2274> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2274;
	}
x86_l_2270:
	/* 0x2270: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_2272:
	/* 0x2272: je     2285 <tail_lb_ipv4+0x2285> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2285;
	}
x86_l_2274:
	/* 0x2274: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_2278:
	/* 0x2278: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_227c:
	/* 0x227c: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2283:
	/* 0x2283: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2285:
	/* 0x2285: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_228c:
	/* 0x228c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_228f:
	/* 0x228f: je     22a7 <tail_lb_ipv4+0x22a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22a7;
	}
x86_l_2291:
	/* 0x2291: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_229a:
	/* 0x229a: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229c:
	/* 0x229c: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_229f:
	/* 0x229f: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_22a2:
	/* 0x22a2: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22a7:
	/* 0x22a7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22ac:
	/* 0x22ac: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22b1:
	/* 0x22b1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22b6:
	/* 0x22b6: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_22b9:
	/* 0x22b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22bb:
	/* 0x22bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bd:
	/* 0x22bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22bf:
	/* 0x22bf: js     2688 <tail_lb_ipv4+0x2688> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2688;
	}
x86_l_22c5:
	/* 0x22c5: cmp    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_22ce:
	/* 0x22ce: je     2324 <tail_lb_ipv4+0x2324> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2324;
	}
x86_l_22d0:
	/* 0x22d0: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_22d8:
	/* 0x22d8: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_22df:
	/* 0x22df: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e4:
	/* 0x22e4: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_22ea:
	/* 0x22ea: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_22ed:
	/* 0x22ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f0:
	/* 0x22f0: je     2426 <tail_lb_ipv4+0x2426> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2426;
	}
x86_l_22f6:
	/* 0x22f6: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22f9:
	/* 0x22f9: or     ebp,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_22fc:
	/* 0x22fc: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2304:
	/* 0x2304: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_230b:
	/* 0x230b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2310:
	/* 0x2310: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2313:
	/* 0x2313: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2316:
	/* 0x2316: je     33 <tail_lb_ipv4+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_231c:
	/* 0x231c: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_231f:
	/* 0x231f: jmp    33 <tail_lb_ipv4+0x33> */
	return 51ULL;
x86_l_2324:
	/* 0x2324: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_232d:
	/* 0x232d: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2330:
	/* 0x2330: mov    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2333:
	/* 0x2333: lea    rcx,[r14+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_2337:
	/* 0x2337: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_233c:
	/* 0x233c: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_233f:
	/* 0x233f: ja     2b7 <tail_lb_ipv4+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 695ULL;
	}
x86_l_2345:
	/* 0x2345: lea    rcx,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2349:
	/* 0x2349: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_234c:
	/* 0x234c: ja     2b7 <tail_lb_ipv4+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 695ULL;
	}
x86_l_2352:
	/* 0x2352: movzx  r15d,WORD PTR [r14+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_2357:
	/* 0x2357: mov    WORD PTR [rsp+0x2c],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_235d:
	/* 0x235d: mov    ebp,DWORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2361:
	/* 0x2361: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2365:
	/* 0x2365: add    r14,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 26ULL);
x86_l_2369:
	/* 0x2369: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_2370:
	/* 0x2370: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2375:
	/* 0x2375: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2378:
	/* 0x2378: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237a:
	/* 0x237a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_237d:
	/* 0x237d: je     238e <tail_lb_ipv4+0x238e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_238e;
	}
x86_l_237f:
	/* 0x237f: xor    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 0ULL);
x86_l_2381:
	/* 0x2381: xor    r15w,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 4ULL);
x86_l_2386:
	/* 0x2386: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_238a:
	/* 0x238a: or     eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_238c:
	/* 0x238c: je     23ae <tail_lb_ipv4+0x23ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23ae;
	}
x86_l_238e:
	/* 0x238e: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_2395:
	/* 0x2395: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_239a:
	/* 0x239a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_239f:
	/* 0x239f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_23a2:
	/* 0x23a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a4:
	/* 0x23a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a6:
	/* 0x23a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23a8:
	/* 0x23a8: js     24cb <tail_lb_ipv4+0x24cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_24cb;
	}
x86_l_23ae:
	/* 0x23ae: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23b3:
	/* 0x23b3: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_23b7:
	/* 0x23b7: js     2430 <tail_lb_ipv4+0x2430> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2430;
	}
x86_l_23b9:
	/* 0x23b9: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_23c1:
	/* 0x23c1: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_23c8:
	/* 0x23c8: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23cd:
	/* 0x23cd: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_23d3:
	/* 0x23d3: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_23d6:
	/* 0x23d6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: je     23e1 <tail_lb_ipv4+0x23e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23e1;
	}
x86_l_23db:
	/* 0x23db: mov    DWORD PTR [rax],0x9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_23e1:
	/* 0x23e1: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_23e9:
	/* 0x23e9: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_23f0:
	/* 0x23f0: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23f5:
	/* 0x23f5: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_23f8:
	/* 0x23f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23fb:
	/* 0x23fb: je     2407 <tail_lb_ipv4+0x2407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2407;
	}
x86_l_23fd:
	/* 0x23fd: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_2404:
	/* 0x2404: mov    DWORD PTR [rax+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2407:
	/* 0x2407: mov    rsi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_240e:
	/* 0x240e: mov    r14d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 15ULL);
x86_l_2414:
	/* 0x2414: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2419:
	/* 0x2419: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_241c:
	/* 0x241c: mov    edx,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 15ULL);
x86_l_2421:
	/* 0x2421: jmp    550 <tail_lb_ipv4+0x550> */
	return 1360ULL;
x86_l_2426:
	/* 0x2426: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_242b:
	/* 0x242b: jmp    22fc <tail_lb_ipv4+0x22fc> */
	goto x86_l_22fc;
x86_l_2430:
	/* 0x2430: movzx  ebp,WORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 100ULL);
x86_l_2435:
	/* 0x2435: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_243d:
	/* 0x243d: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2444:
	/* 0x2444: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2449:
	/* 0x2449: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_244f:
	/* 0x244f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2452:
	/* 0x2452: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2455:
	/* 0x2455: je     2459 <tail_lb_ipv4+0x2459> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2459;
	}
x86_l_2457:
	/* 0x2457: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2459:
	/* 0x2459: mov    ebp,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_245d:
	/* 0x245d: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2465:
	/* 0x2465: mov    rdi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_246c:
	/* 0x246c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2471:
	/* 0x2471: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2474:
	/* 0x2474: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2477:
	/* 0x2477: je     247c <tail_lb_ipv4+0x247c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_247c;
	}
x86_l_2479:
	/* 0x2479: mov    DWORD PTR [rax+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_247c:
	/* 0x247c: mov    rsi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2483:
	/* 0x2483: mov    r14d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21ULL);
x86_l_2489:
	/* 0x2489: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_248e:
	/* 0x248e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2491:
	/* 0x2491: mov    edx,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2496:
	/* 0x2496: jmp    550 <tail_lb_ipv4+0x550> */
	return 1360ULL;
x86_l_249b:
	/* 0x249b: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24a0:
	/* 0x24a0: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_24a2:
	/* 0x24a2: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_24a4:
	/* 0x24a4: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_24a6:
	/* 0x24a6: je     25b7 <tail_lb_ipv4+0x25b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b7;
	}
x86_l_24ac:
	/* 0x24ac: mov    r12,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_24b3:
	/* 0x24b3: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24b8:
	/* 0x24b8: je     24d2 <tail_lb_ipv4+0x24d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24d2;
	}
x86_l_24ba:
	/* 0x24ba: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_24c1:
	/* 0x24c1: imul   r14d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_24c5:
	/* 0x24c5: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_24c9:
	/* 0x24c9: jmp    24d8 <tail_lb_ipv4+0x24d8> */
	goto x86_l_24d8;
x86_l_24cb:
	/* 0x24cb: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_24cd:
	/* 0x24cd: jmp    2b7 <tail_lb_ipv4+0x2b7> */
	return 695ULL;
x86_l_24d2:
	/* 0x24d2: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_24d8:
	/* 0x24d8: cmp    BYTE PTR [rsp+0x88],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552262ULL);
x86_l_24e0:
	/* 0x24e0: jne    251f <tail_lb_ipv4+0x251f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_251f;
	}
x86_l_24e2:
	/* 0x24e2: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_24e4:
	/* 0x24e4: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_24e6:
	/* 0x24e6: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_24e9:
	/* 0x24e9: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_24ec:
	/* 0x24ec: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_24ee:
	/* 0x24ee: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24f3:
	/* 0x24f3: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_24f7:
	/* 0x24f7: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_24fa:
	/* 0x24fa: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_24ff:
	/* 0x24ff: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_2505:
	/* 0x2505: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2509:
	/* 0x2509: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250e:
	/* 0x250e: je     251f <tail_lb_ipv4+0x251f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_251f;
	}
x86_l_2510:
	/* 0x2510: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2517:
	/* 0x2517: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_251b:
	/* 0x251b: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_251f:
	/* 0x251f: movzx  r13d,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2523:
	/* 0x2523: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2527:
	/* 0x2527: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_252c:
	/* 0x252c: je     253d <tail_lb_ipv4+0x253d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_253d;
	}
x86_l_252e:
	/* 0x252e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2533:
	/* 0x2533: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2535:
	/* 0x2535: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2537:
	/* 0x2537: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_253b:
	/* 0x253b: jmp    2560 <tail_lb_ipv4+0x2560> */
	goto x86_l_2560;
x86_l_253d:
	/* 0x253d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2542:
	/* 0x2542: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2544:
	/* 0x2544: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2546:
	/* 0x2546: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_254a:
	/* 0x254a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2554:
	/* 0x2554: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2557:
	/* 0x2557: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_255c:
	/* 0x255c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2560:
	/* 0x2560: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2563:
	/* 0x2563: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2568:
	/* 0x2568: mov    DWORD PTR [rdx+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_256c:
	/* 0x256c: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2570:
	/* 0x2570: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2573:
	/* 0x2573: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2577:
	/* 0x2577: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_257c:
	/* 0x257c: je     258f <tail_lb_ipv4+0x258f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_258f;
	}
x86_l_257e:
	/* 0x257e: mov    rsi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2585:
	/* 0x2585: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2587:
	/* 0x2587: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_258a:
	/* 0x258a: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_258d:
	/* 0x258d: jmp    2594 <tail_lb_ipv4+0x2594> */
	goto x86_l_2594;
x86_l_258f:
	/* 0x258f: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2594:
	/* 0x2594: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2596:
	/* 0x2596: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2599:
	/* 0x2599: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_259b:
	/* 0x259b: jb     25a2 <tail_lb_ipv4+0x25a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_25a2;
	}
x86_l_259d:
	/* 0x259d: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_25a0:
	/* 0x25a0: je     25b7 <tail_lb_ipv4+0x25b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b7;
	}
x86_l_25a2:
	/* 0x25a2: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25a7:
	/* 0x25a7: mov    BYTE PTR [rcx+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_25ab:
	/* 0x25ab: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25ae:
	/* 0x25ae: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_25b5:
	/* 0x25b5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25b7:
	/* 0x25b7: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_25be:
	/* 0x25be: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25c1:
	/* 0x25c1: je     25da <tail_lb_ipv4+0x25da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25da;
	}
x86_l_25c3:
	/* 0x25c3: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25c8:
	/* 0x25c8: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_25cd:
	/* 0x25cd: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25cf:
	/* 0x25cf: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25d2:
	/* 0x25d2: sub    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_25d5:
	/* 0x25d5: add QWORD PTR [rax+0x18],rdx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_25da:
	/* 0x25da: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_25de:
	/* 0x25de: je     2634 <tail_lb_ipv4+0x2634> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2634;
	}
x86_l_25e0:
	/* 0x25e0: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_25e4:
	/* 0x25e4: jne    22c5 <tail_lb_ipv4+0x22c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22c5;
	}
x86_l_25ea:
	/* 0x25ea: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25ef:
	/* 0x25ef: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_25f3:
	/* 0x25f3: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_25f5:
	/* 0x25f5: je     22c5 <tail_lb_ipv4+0x22c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c5;
	}
x86_l_25fb:
	/* 0x25fb: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2600:
	/* 0x2600: mov    WORD PTR [rcx+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_2606:
	/* 0x2606: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_260b:
	/* 0x260b: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_260f:
	/* 0x260f: mov    r15,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2616:
	/* 0x2616: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_261a:
	/* 0x261a: je     273d <tail_lb_ipv4+0x273d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10045ULL;
	}
x86_l_2620:
	/* 0x2620: mov    rcx,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2627:
	/* 0x2627: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_262b:
	/* 0x262b: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_262f:
	/* 0x262f: jmp    2743 <tail_lb_ipv4+0x2743> */
	return 10051ULL;
x86_l_2634:
	/* 0x2634: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2636:
	/* 0x2636: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_263b:
	/* 0x263b: cmp    ax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 1ULL);
x86_l_263f:
	/* 0x263f: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_2643:
	/* 0x2643: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_2647:
	/* 0x2647: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_264c:
	/* 0x264c: or     ax,WORD PTR [rcx+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_2650:
	/* 0x2650: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2654:
	/* 0x2654: mov    r15,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_265b:
	/* 0x265b: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_265e:
	/* 0x265e: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2660:
	/* 0x2660: je     22c5 <tail_lb_ipv4+0x22c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22c5;
	}
x86_l_2666:
	/* 0x2666: mov    r14,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_266d:
	/* 0x266d: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2671:
	/* 0x2671: je     2695 <tail_lb_ipv4+0x2695> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9877ULL;
	}
x86_l_2673:
	/* 0x2673: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_267a:
	/* 0x267a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267c:
	/* 0x267c: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_267e:
	/* 0x267e: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2682:
	/* 0x2682: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2686:
	/* 0x2686: jmp    269b <tail_lb_ipv4+0x269b> */
	return 9883ULL;
x86_l_2688:
	/* 0x2688: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_268b:
	/* 0x268b: mov    ebp,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967141ULL);
x86_l_2690:
	/* 0x2690: jmp    b5 <tail_lb_ipv4+0xb5> */
	return 181ULL;
	return 9877ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9877ULL: goto x86_l_2695;
	case 9883ULL: goto x86_l_269b;
	case 9886ULL: goto x86_l_269e;
	case 9889ULL: goto x86_l_26a1;
	case 9893ULL: goto x86_l_26a5;
	case 9895ULL: goto x86_l_26a7;
	case 9900ULL: goto x86_l_26ac;
	case 9902ULL: goto x86_l_26ae;
	case 9904ULL: goto x86_l_26b0;
	case 9908ULL: goto x86_l_26b4;
	case 9910ULL: goto x86_l_26b6;
	case 9915ULL: goto x86_l_26bb;
	case 9917ULL: goto x86_l_26bd;
	case 9919ULL: goto x86_l_26bf;
	case 9923ULL: goto x86_l_26c3;
	case 9933ULL: goto x86_l_26cd;
	case 9936ULL: goto x86_l_26d0;
	case 9941ULL: goto x86_l_26d5;
	case 9945ULL: goto x86_l_26d9;
	case 9948ULL: goto x86_l_26dc;
	case 9953ULL: goto x86_l_26e1;
	case 9957ULL: goto x86_l_26e5;
	case 9961ULL: goto x86_l_26e9;
	case 9964ULL: goto x86_l_26ec;
	case 9968ULL: goto x86_l_26f0;
	case 9972ULL: goto x86_l_26f4;
	case 9974ULL: goto x86_l_26f6;
	case 9981ULL: goto x86_l_26fd;
	case 9983ULL: goto x86_l_26ff;
	case 9986ULL: goto x86_l_2702;
	case 9989ULL: goto x86_l_2705;
	case 9991ULL: goto x86_l_2707;
	case 9996ULL: goto x86_l_270c;
	case 9998ULL: goto x86_l_270e;
	case 10001ULL: goto x86_l_2711;
	case 10003ULL: goto x86_l_2713;
	case 10005ULL: goto x86_l_2715;
	case 10008ULL: goto x86_l_2718;
	case 10014ULL: goto x86_l_271e;
	case 10019ULL: goto x86_l_2723;
	case 10023ULL: goto x86_l_2727;
	case 10026ULL: goto x86_l_272a;
	case 10029ULL: goto x86_l_272d;
	case 10034ULL: goto x86_l_2732;
	case 10040ULL: goto x86_l_2738;
	case 10045ULL: goto x86_l_273d;
	case 10051ULL: goto x86_l_2743;
	case 10059ULL: goto x86_l_274b;
	case 10061ULL: goto x86_l_274d;
	case 10063ULL: goto x86_l_274f;
	case 10065ULL: goto x86_l_2751;
	case 10068ULL: goto x86_l_2754;
	case 10071ULL: goto x86_l_2757;
	case 10073ULL: goto x86_l_2759;
	case 10078ULL: goto x86_l_275e;
	case 10082ULL: goto x86_l_2762;
	case 10084ULL: goto x86_l_2764;
	case 10089ULL: goto x86_l_2769;
	case 10095ULL: goto x86_l_276f;
	case 10099ULL: goto x86_l_2773;
	case 10103ULL: goto x86_l_2777;
	case 10105ULL: goto x86_l_2779;
	case 10112ULL: goto x86_l_2780;
	case 10116ULL: goto x86_l_2784;
	case 10120ULL: goto x86_l_2788;
	case 10123ULL: goto x86_l_278b;
	case 10126ULL: goto x86_l_278e;
	case 10130ULL: goto x86_l_2792;
	case 10132ULL: goto x86_l_2794;
	case 10137ULL: goto x86_l_2799;
	case 10139ULL: goto x86_l_279b;
	case 10141ULL: goto x86_l_279d;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10156ULL: goto x86_l_27ac;
	case 10160ULL: goto x86_l_27b0;
	case 10170ULL: goto x86_l_27ba;
	case 10173ULL: goto x86_l_27bd;
	case 10178ULL: goto x86_l_27c2;
	case 10182ULL: goto x86_l_27c6;
	case 10185ULL: goto x86_l_27c9;
	case 10190ULL: goto x86_l_27ce;
	case 10194ULL: goto x86_l_27d2;
	case 10198ULL: goto x86_l_27d6;
	case 10201ULL: goto x86_l_27d9;
	case 10205ULL: goto x86_l_27dd;
	case 10209ULL: goto x86_l_27e1;
	case 10211ULL: goto x86_l_27e3;
	case 10218ULL: goto x86_l_27ea;
	case 10220ULL: goto x86_l_27ec;
	case 10223ULL: goto x86_l_27ef;
	case 10226ULL: goto x86_l_27f2;
	case 10228ULL: goto x86_l_27f4;
	case 10233ULL: goto x86_l_27f9;
	case 10235ULL: goto x86_l_27fb;
	case 10238ULL: goto x86_l_27fe;
	case 10240ULL: goto x86_l_2800;
	case 10242ULL: goto x86_l_2802;
	case 10245ULL: goto x86_l_2805;
	case 10251ULL: goto x86_l_280b;
	case 10256ULL: goto x86_l_2810;
	case 10260ULL: goto x86_l_2814;
	case 10263ULL: goto x86_l_2817;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2695:
	/* 0x2695: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_269b:
	/* 0x269b: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_269e:
	/* 0x269e: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_26a1:
	/* 0x26a1: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26a5:
	/* 0x26a5: je     26b6 <tail_lb_ipv4+0x26b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26b6;
	}
x86_l_26a7:
	/* 0x26a7: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_26ac:
	/* 0x26ac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26ae:
	/* 0x26ae: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_26b0:
	/* 0x26b0: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_26b4:
	/* 0x26b4: jmp    26d9 <tail_lb_ipv4+0x26d9> */
	goto x86_l_26d9;
x86_l_26b6:
	/* 0x26b6: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_26bb:
	/* 0x26bb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26bd:
	/* 0x26bd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_26bf:
	/* 0x26bf: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_26c3:
	/* 0x26c3: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_26cd:
	/* 0x26cd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_26d0:
	/* 0x26d0: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_26d5:
	/* 0x26d5: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_26d9:
	/* 0x26d9: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_26dc:
	/* 0x26dc: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26e1:
	/* 0x26e1: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26e5:
	/* 0x26e5: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_26e9:
	/* 0x26e9: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26ec:
	/* 0x26ec: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_26f0:
	/* 0x26f0: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f4:
	/* 0x26f4: je     2707 <tail_lb_ipv4+0x2707> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2707;
	}
x86_l_26f6:
	/* 0x26f6: mov    rsi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_26fd:
	/* 0x26fd: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26ff:
	/* 0x26ff: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2702:
	/* 0x2702: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2705:
	/* 0x2705: jmp    270c <tail_lb_ipv4+0x270c> */
	goto x86_l_270c;
x86_l_2707:
	/* 0x2707: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_270c:
	/* 0x270c: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_270e:
	/* 0x270e: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2711:
	/* 0x2711: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2713:
	/* 0x2713: jb     271e <tail_lb_ipv4+0x271e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_271e;
	}
x86_l_2715:
	/* 0x2715: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_2718:
	/* 0x2718: je     22c5 <tail_lb_ipv4+0x22c5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8901ULL;
	}
x86_l_271e:
	/* 0x271e: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2723:
	/* 0x2723: mov    BYTE PTR [rcx+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2727:
	/* 0x2727: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_272a:
	/* 0x272a: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_272d:
	/* 0x272d: jmp    22c5 <tail_lb_ipv4+0x22c5> */
	return 8901ULL;
x86_l_2732:
	/* 0x2732: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_2738:
	/* 0x2738: jmp    20f3 <tail_lb_ipv4+0x20f3> */
	return 8435ULL;
x86_l_273d:
	/* 0x273d: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_2743:
	/* 0x2743: cmp    BYTE PTR [rsp+0x88],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 584115552262ULL);
x86_l_274b:
	/* 0x274b: jne    2788 <tail_lb_ipv4+0x2788> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2788;
	}
x86_l_274d:
	/* 0x274d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_274f:
	/* 0x274f: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2751:
	/* 0x2751: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2754:
	/* 0x2754: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2757:
	/* 0x2757: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2759:
	/* 0x2759: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_275e:
	/* 0x275e: mov    WORD PTR [rcx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2762:
	/* 0x2762: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2764:
	/* 0x2764: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2769:
	/* 0x2769: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_276f:
	/* 0x276f: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2773:
	/* 0x2773: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2777:
	/* 0x2777: je     2788 <tail_lb_ipv4+0x2788> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2788;
	}
x86_l_2779:
	/* 0x2779: mov    rax,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2780:
	/* 0x2780: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2784:
	/* 0x2784: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2788:
	/* 0x2788: movzx  ebp,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_278b:
	/* 0x278b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_278e:
	/* 0x278e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2792:
	/* 0x2792: je     27a3 <tail_lb_ipv4+0x27a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27a3;
	}
x86_l_2794:
	/* 0x2794: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2799:
	/* 0x2799: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_279b:
	/* 0x279b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_279d:
	/* 0x279d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_27a1:
	/* 0x27a1: jmp    27c6 <tail_lb_ipv4+0x27c6> */
	goto x86_l_27c6;
x86_l_27a3:
	/* 0x27a3: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_27a8:
	/* 0x27a8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27aa:
	/* 0x27aa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_27ac:
	/* 0x27ac: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_27b0:
	/* 0x27b0: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_27ba:
	/* 0x27ba: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_27bd:
	/* 0x27bd: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_27c2:
	/* 0x27c2: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_27c6:
	/* 0x27c6: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27c9:
	/* 0x27c9: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27ce:
	/* 0x27ce: mov    DWORD PTR [rdx+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_27d2:
	/* 0x27d2: movzx  ecx,BYTE PTR [rdx+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_27d6:
	/* 0x27d6: mov    edx,DWORD PTR [rdx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27d9:
	/* 0x27d9: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_27dd:
	/* 0x27dd: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27e1:
	/* 0x27e1: je     27f4 <tail_lb_ipv4+0x27f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27f4;
	}
x86_l_27e3:
	/* 0x27e3: mov    rsi,QWORD PTR [rip+0xdbd6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_27ea:
	/* 0x27ea: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27ec:
	/* 0x27ec: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_27ef:
	/* 0x27ef: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_27f2:
	/* 0x27f2: jmp    27f9 <tail_lb_ipv4+0x27f9> */
	goto x86_l_27f9;
x86_l_27f4:
	/* 0x27f4: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_27f9:
	/* 0x27f9: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_27fb:
	/* 0x27fb: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_27fe:
	/* 0x27fe: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2800:
	/* 0x2800: jb     280b <tail_lb_ipv4+0x280b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_280b;
	}
x86_l_2802:
	/* 0x2802: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_2805:
	/* 0x2805: je     2139 <tail_lb_ipv4+0x2139> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8505ULL;
	}
x86_l_280b:
	/* 0x280b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2810:
	/* 0x2810: mov    BYTE PTR [rcx+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2814:
	/* 0x2814: mov    DWORD PTR [rcx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2817:
	/* 0x2817: jmp    2130 <tail_lb_ipv4+0x2130> */
	return 8496ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_xdp_tail_lb_ipv4_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 9636U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1736ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1738ULL && __x86_pc <= 3445ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3448ULL && __x86_pc <= 5014ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5016ULL && __x86_pc <= 6613ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6616ULL && __x86_pc <= 8228ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8237ULL && __x86_pc <= 9872ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 9877ULL && __x86_pc <= 10263ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv4_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

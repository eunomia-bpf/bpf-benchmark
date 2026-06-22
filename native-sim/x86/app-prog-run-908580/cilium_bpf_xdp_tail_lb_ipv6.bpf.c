extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_hash_init6_seed;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_affinity;
extern char cilium_lb6_backends_v3;
extern char cilium_lb6_maglev;
extern char cilium_lb6_services_v2;
extern char cilium_lb6_source_range;
extern char cilium_lb_affinity_match;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_nodeport_neigh6;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_0(
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
	case 165ULL: goto x86_l_a5;
	case 168ULL: goto x86_l_a8;
	case 170ULL: goto x86_l_aa;
	case 175ULL: goto x86_l_af;
	case 178ULL: goto x86_l_b2;
	case 183ULL: goto x86_l_b7;
	case 192ULL: goto x86_l_c0;
	case 201ULL: goto x86_l_c9;
	case 210ULL: goto x86_l_d2;
	case 219ULL: goto x86_l_db;
	case 228ULL: goto x86_l_e4;
	case 240ULL: goto x86_l_f0;
	case 252ULL: goto x86_l_fc;
	case 264ULL: goto x86_l_108;
	case 270ULL: goto x86_l_10e;
	case 273ULL: goto x86_l_111;
	case 279ULL: goto x86_l_117;
	case 283ULL: goto x86_l_11b;
	case 289ULL: goto x86_l_121;
	case 294ULL: goto x86_l_126;
	case 304ULL: goto x86_l_130;
	case 308ULL: goto x86_l_134;
	case 310ULL: goto x86_l_136;
	case 315ULL: goto x86_l_13b;
	case 318ULL: goto x86_l_13e;
	case 324ULL: goto x86_l_144;
	case 328ULL: goto x86_l_148;
	case 330ULL: goto x86_l_14a;
	case 333ULL: goto x86_l_14d;
	case 336ULL: goto x86_l_150;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 343ULL: goto x86_l_157;
	case 346ULL: goto x86_l_15a;
	case 352ULL: goto x86_l_160;
	case 355ULL: goto x86_l_163;
	case 362ULL: goto x86_l_16a;
	case 365ULL: goto x86_l_16d;
	case 371ULL: goto x86_l_173;
	case 376ULL: goto x86_l_178;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 387ULL: goto x86_l_183;
	case 393ULL: goto x86_l_189;
	case 397ULL: goto x86_l_18d;
	case 403ULL: goto x86_l_193;
	case 408ULL: goto x86_l_198;
	case 413ULL: goto x86_l_19d;
	case 418ULL: goto x86_l_1a2;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 430ULL: goto x86_l_1ae;
	case 436ULL: goto x86_l_1b4;
	case 439ULL: goto x86_l_1b7;
	case 445ULL: goto x86_l_1bd;
	case 455ULL: goto x86_l_1c7;
	case 458ULL: goto x86_l_1ca;
	case 461ULL: goto x86_l_1cd;
	case 471ULL: goto x86_l_1d7;
	case 474ULL: goto x86_l_1da;
	case 480ULL: goto x86_l_1e0;
	case 484ULL: goto x86_l_1e4;
	case 494ULL: goto x86_l_1ee;
	case 497ULL: goto x86_l_1f1;
	case 503ULL: goto x86_l_1f7;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 516ULL: goto x86_l_204;
	case 519ULL: goto x86_l_207;
	case 523ULL: goto x86_l_20b;
	case 527ULL: goto x86_l_20f;
	case 533ULL: goto x86_l_215;
	case 537ULL: goto x86_l_219;
	case 541ULL: goto x86_l_21d;
	case 543ULL: goto x86_l_21f;
	case 546ULL: goto x86_l_222;
	case 550ULL: goto x86_l_226;
	case 554ULL: goto x86_l_22a;
	case 558ULL: goto x86_l_22e;
	case 561ULL: goto x86_l_231;
	case 567ULL: goto x86_l_237;
	case 570ULL: goto x86_l_23a;
	case 574ULL: goto x86_l_23e;
	case 576ULL: goto x86_l_240;
	case 579ULL: goto x86_l_243;
	case 583ULL: goto x86_l_247;
	case 585ULL: goto x86_l_249;
	case 589ULL: goto x86_l_24d;
	case 591ULL: goto x86_l_24f;
	case 595ULL: goto x86_l_253;
	case 597ULL: goto x86_l_255;
	case 600ULL: goto x86_l_258;
	case 607ULL: goto x86_l_25f;
	case 612ULL: goto x86_l_264;
	case 615ULL: goto x86_l_267;
	case 620ULL: goto x86_l_26c;
	case 622ULL: goto x86_l_26e;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 637ULL: goto x86_l_27d;
	case 644ULL: goto x86_l_284;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 652ULL: goto x86_l_28c;
	case 657ULL: goto x86_l_291;
	case 661ULL: goto x86_l_295;
	case 664ULL: goto x86_l_298;
	case 670ULL: goto x86_l_29e;
	case 673ULL: goto x86_l_2a1;
	case 679ULL: goto x86_l_2a7;
	case 682ULL: goto x86_l_2aa;
	case 688ULL: goto x86_l_2b0;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 704ULL: goto x86_l_2c0;
	case 714ULL: goto x86_l_2ca;
	case 717ULL: goto x86_l_2cd;
	case 723ULL: goto x86_l_2d3;
	case 727ULL: goto x86_l_2d7;
	case 737ULL: goto x86_l_2e1;
	case 740ULL: goto x86_l_2e4;
	case 746ULL: goto x86_l_2ea;
	case 750ULL: goto x86_l_2ee;
	case 753ULL: goto x86_l_2f1;
	case 756ULL: goto x86_l_2f4;
	case 762ULL: goto x86_l_2fa;
	case 765ULL: goto x86_l_2fd;
	case 769ULL: goto x86_l_301;
	case 775ULL: goto x86_l_307;
	case 779ULL: goto x86_l_30b;
	case 783ULL: goto x86_l_30f;
	case 787ULL: goto x86_l_313;
	case 791ULL: goto x86_l_317;
	case 794ULL: goto x86_l_31a;
	case 800ULL: goto x86_l_320;
	case 803ULL: goto x86_l_323;
	case 807ULL: goto x86_l_327;
	case 810ULL: goto x86_l_32a;
	case 814ULL: goto x86_l_32e;
	case 817ULL: goto x86_l_331;
	case 819ULL: goto x86_l_333;
	case 822ULL: goto x86_l_336;
	case 824ULL: goto x86_l_338;
	case 827ULL: goto x86_l_33b;
	case 829ULL: goto x86_l_33d;
	case 833ULL: goto x86_l_341;
	case 840ULL: goto x86_l_348;
	case 842ULL: goto x86_l_34a;
	case 850ULL: goto x86_l_352;
	case 853ULL: goto x86_l_355;
	case 855ULL: goto x86_l_357;
	case 857ULL: goto x86_l_359;
	case 862ULL: goto x86_l_35e;
	case 866ULL: goto x86_l_362;
	case 869ULL: goto x86_l_365;
	case 875ULL: goto x86_l_36b;
	case 878ULL: goto x86_l_36e;
	case 884ULL: goto x86_l_374;
	case 887ULL: goto x86_l_377;
	case 893ULL: goto x86_l_37d;
	case 903ULL: goto x86_l_387;
	case 906ULL: goto x86_l_38a;
	case 909ULL: goto x86_l_38d;
	case 919ULL: goto x86_l_397;
	case 922ULL: goto x86_l_39a;
	case 928ULL: goto x86_l_3a0;
	case 932ULL: goto x86_l_3a4;
	case 942ULL: goto x86_l_3ae;
	case 945ULL: goto x86_l_3b1;
	case 951ULL: goto x86_l_3b7;
	case 955ULL: goto x86_l_3bb;
	case 958ULL: goto x86_l_3be;
	case 962ULL: goto x86_l_3c2;
	case 968ULL: goto x86_l_3c8;
	case 972ULL: goto x86_l_3cc;
	case 976ULL: goto x86_l_3d0;
	case 982ULL: goto x86_l_3d6;
	case 986ULL: goto x86_l_3da;
	case 990ULL: goto x86_l_3de;
	case 994ULL: goto x86_l_3e2;
	case 998ULL: goto x86_l_3e6;
	case 1001ULL: goto x86_l_3e9;
	case 1007ULL: goto x86_l_3ef;
	case 1012ULL: goto x86_l_3f4;
	case 1020ULL: goto x86_l_3fc;
	case 1027ULL: goto x86_l_403;
	case 1032ULL: goto x86_l_408;
	case 1038ULL: goto x86_l_40e;
	case 1041ULL: goto x86_l_411;
	case 1044ULL: goto x86_l_414;
	case 1046ULL: goto x86_l_416;
	case 1052ULL: goto x86_l_41c;
	case 1060ULL: goto x86_l_424;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1075ULL: goto x86_l_433;
	case 1078ULL: goto x86_l_436;
	case 1080ULL: goto x86_l_438;
	case 1087ULL: goto x86_l_43f;
	case 1089ULL: goto x86_l_441;
	case 1097ULL: goto x86_l_449;
	case 1104ULL: goto x86_l_450;
	case 1109ULL: goto x86_l_455;
	case 1115ULL: goto x86_l_45b;
	case 1118ULL: goto x86_l_45e;
	case 1121ULL: goto x86_l_461;
	case 1123ULL: goto x86_l_463;
	case 1127ULL: goto x86_l_467;
	case 1131ULL: goto x86_l_46b;
	case 1135ULL: goto x86_l_46f;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1148ULL: goto x86_l_47c;
	case 1155ULL: goto x86_l_483;
	case 1160ULL: goto x86_l_488;
	case 1163ULL: goto x86_l_48b;
	case 1166ULL: goto x86_l_48e;
	case 1168ULL: goto x86_l_490;
	case 1175ULL: goto x86_l_497;
	case 1183ULL: goto x86_l_49f;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1201ULL: goto x86_l_4b1;
	case 1204ULL: goto x86_l_4b4;
	case 1207ULL: goto x86_l_4b7;
	case 1209ULL: goto x86_l_4b9;
	case 1216ULL: goto x86_l_4c0;
	case 1218ULL: goto x86_l_4c2;
	case 1222ULL: goto x86_l_4c6;
	case 1225ULL: goto x86_l_4c9;
	case 1235ULL: goto x86_l_4d3;
	case 1240ULL: goto x86_l_4d8;
	case 1245ULL: goto x86_l_4dd;
	case 1252ULL: goto x86_l_4e4;
	case 1257ULL: goto x86_l_4e9;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1265ULL: goto x86_l_4f1;
	case 1268ULL: goto x86_l_4f4;
	case 1272ULL: goto x86_l_4f8;
	case 1274ULL: goto x86_l_4fa;
	case 1283ULL: goto x86_l_503;
	case 1288ULL: goto x86_l_508;
	case 1295ULL: goto x86_l_50f;
	case 1300ULL: goto x86_l_514;
	case 1305ULL: goto x86_l_519;
	case 1310ULL: goto x86_l_51e;
	case 1312ULL: goto x86_l_520;
	case 1314ULL: goto x86_l_522;
	case 1321ULL: goto x86_l_529;
	case 1326ULL: goto x86_l_52e;
	case 1331ULL: goto x86_l_533;
	case 1334ULL: goto x86_l_536;
	case 1339ULL: goto x86_l_53b;
	case 1341ULL: goto x86_l_53d;
	case 1343ULL: goto x86_l_53f;
	case 1350ULL: goto x86_l_546;
	case 1352ULL: goto x86_l_548;
	case 1353ULL: goto x86_l_549;
	case 1358ULL: goto x86_l_54e;
	case 1360ULL: goto x86_l_550;
	case 1362ULL: goto x86_l_552;
	case 1365ULL: goto x86_l_555;
	case 1369ULL: goto x86_l_559;
	case 1372ULL: goto x86_l_55c;
	case 1377ULL: goto x86_l_561;
	case 1382ULL: goto x86_l_566;
	case 1385ULL: goto x86_l_569;
	case 1389ULL: goto x86_l_56d;
	case 1392ULL: goto x86_l_570;
	case 1397ULL: goto x86_l_575;
	case 1399ULL: goto x86_l_577;
	case 1403ULL: goto x86_l_57b;
	case 1409ULL: goto x86_l_581;
	case 1413ULL: goto x86_l_585;
	case 1418ULL: goto x86_l_58a;
	case 1423ULL: goto x86_l_58f;
	case 1428ULL: goto x86_l_594;
	case 1433ULL: goto x86_l_599;
	case 1438ULL: goto x86_l_59e;
	case 1443ULL: goto x86_l_5a3;
	case 1448ULL: goto x86_l_5a8;
	case 1453ULL: goto x86_l_5ad;
	case 1456ULL: goto x86_l_5b0;
	case 1458ULL: goto x86_l_5b2;
	case 1461ULL: goto x86_l_5b5;
	case 1464ULL: goto x86_l_5b8;
	case 1470ULL: goto x86_l_5be;
	case 1473ULL: goto x86_l_5c1;
	case 1479ULL: goto x86_l_5c7;
	case 1483ULL: goto x86_l_5cb;
	case 1493ULL: goto x86_l_5d5;
	case 1500ULL: goto x86_l_5dc;
	case 1504ULL: goto x86_l_5e0;
	case 1510ULL: goto x86_l_5e6;
	case 1515ULL: goto x86_l_5eb;
	case 1520ULL: goto x86_l_5f0;
	case 1529ULL: goto x86_l_5f9;
	case 1534ULL: goto x86_l_5fe;
	case 1537ULL: goto x86_l_601;
	case 1541ULL: goto x86_l_605;
	case 1546ULL: goto x86_l_60a;
	case 1549ULL: goto x86_l_60d;
	case 1555ULL: goto x86_l_613;
	case 1557ULL: goto x86_l_615;
	case 1560ULL: goto x86_l_618;
	case 1564ULL: goto x86_l_61c;
	case 1568ULL: goto x86_l_620;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1580ULL: goto x86_l_62c;
	case 1586ULL: goto x86_l_632;
	case 1589ULL: goto x86_l_635;
	case 1594ULL: goto x86_l_63a;
	case 1599ULL: goto x86_l_63f;
	case 1601ULL: goto x86_l_641;
	case 1609ULL: goto x86_l_649;
	case 1616ULL: goto x86_l_650;
	case 1621ULL: goto x86_l_655;
	case 1627ULL: goto x86_l_65b;
	case 1630ULL: goto x86_l_65e;
	case 1633ULL: goto x86_l_661;
	case 1639ULL: goto x86_l_667;
	case 1643ULL: goto x86_l_66b;
	case 1651ULL: goto x86_l_673;
	case 1658ULL: goto x86_l_67a;
	case 1663ULL: goto x86_l_67f;
	case 1666ULL: goto x86_l_682;
	case 1669ULL: goto x86_l_685;
	case 1671ULL: goto x86_l_687;
	case 1675ULL: goto x86_l_68b;
	case 1679ULL: goto x86_l_68f;
	case 1682ULL: goto x86_l_692;
	case 1688ULL: goto x86_l_698;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1703ULL: goto x86_l_6a7;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1718ULL: goto x86_l_6b6;
	case 1723ULL: goto x86_l_6bb;
	case 1728ULL: goto x86_l_6c0;
	case 1733ULL: goto x86_l_6c5;
	case 1738ULL: goto x86_l_6ca;
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
	/* 0xd: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1c:
	/* 0x1c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x2b: je     9a <tail_lb_ipv6+0x9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a;
	}
x86_l_2d:
	/* 0x2d: cmp    DWORD PTR [rax+0x14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_31:
	/* 0x31: je     9a <tail_lb_ipv6+0x9a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9a;
	}
x86_l_33:
	/* 0x33: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3b:
	/* 0x3b: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_42:
	/* 0x42: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
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
	/* 0x51: je     a52 <tail_lb_ipv6+0xa52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2642ULL;
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
	/* 0x63: je     53d <tail_lb_ipv6+0x53d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_53d;
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
	/* 0x7a: jne    53d <tail_lb_ipv6+0x53d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_53d;
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
	/* 0x8c: ja     53d <tail_lb_ipv6+0x53d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_53d;
	}
x86_l_92:
	/* 0x92: mov    DWORD PTR [rax],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95:
	/* 0x95: jmp    53d <tail_lb_ipv6+0x53d> */
	goto x86_l_53d;
x86_l_9a:
	/* 0x9a: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9d:
	/* 0x9d: mov    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a0:
	/* 0xa0: lea    r8,[r12+0x36] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_a5:
	/* 0xa5: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_a8:
	/* 0xa8: jbe    b7 <tail_lb_ipv6+0xb7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_b7;
	}
x86_l_aa:
	/* 0xaa: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_af:
	/* 0xaf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b2:
	/* 0xb2: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	goto x86_l_3f4;
x86_l_b7:
	/* 0xb7: mov    QWORD PTR [rsp+0x6e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 472446402560ULL);
x86_l_c0:
	/* 0xc0: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_c9:
	/* 0xc9: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d2:
	/* 0xd2: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_db:
	/* 0xdb: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_e4:
	/* 0xe4: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_f0:
	/* 0xf0: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_fc:
	/* 0xfc: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_108:
	/* 0x108: movzx  edx,BYTE PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_10e:
	/* 0x10e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111:
	/* 0x111: mov    r13d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 40ULL);
x86_l_117:
	/* 0x117: cmp    rdx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 60ULL);
x86_l_11b:
	/* 0x11b: ja     264 <tail_lb_ipv6+0x264> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_264;
	}
x86_l_121:
	/* 0x121: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_126:
	/* 0x126: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_130:
	/* 0x130: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_134:
	/* 0x134: jae    183 <tail_lb_ipv6+0x183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_183;
	}
x86_l_136:
	/* 0x136: lea    rsi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13b:
	/* 0x13b: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_13e:
	/* 0x13e: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_144:
	/* 0x144: movzx  esi,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_148:
	/* 0x148: mov    edi,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_14a:
	/* 0x14a: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14d:
	/* 0x14d: cmp    edx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 43ULL);
x86_l_150:
	/* 0x150: jle    160 <tail_lb_ipv6+0x160> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_160;
	}
x86_l_152:
	/* 0x152: cmp    edx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 44ULL);
x86_l_155:
	/* 0x155: je     198 <tail_lb_ipv6+0x198> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_198;
	}
x86_l_157:
	/* 0x157: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_15a:
	/* 0x15a: jne    1fd <tail_lb_ipv6+0x1fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1fd;
	}
x86_l_160:
	/* 0x160: movzx  edi,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_163:
	/* 0x163: lea    edi,[rdi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 3), 8ULL);
x86_l_16a:
	/* 0x16a: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_16d:
	/* 0x16d: jne    204 <tail_lb_ipv6+0x204> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204;
	}
x86_l_173:
	/* 0x173: lea    rdx,[r12+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_178:
	/* 0x178: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_17b:
	/* 0x17b: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_181:
	/* 0x181: jmp    1ab <tail_lb_ipv6+0x1ab> */
	goto x86_l_1ab;
x86_l_183:
	/* 0x183: mov    r10d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 0ULL);
x86_l_189:
	/* 0x189: cmp    rdx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 59ULL);
x86_l_18d:
	/* 0x18d: je     3f4 <tail_lb_ipv6+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f4;
	}
x86_l_193:
	/* 0x193: jmp    581 <tail_lb_ipv6+0x581> */
	goto x86_l_581;
x86_l_198:
	/* 0x198: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_19d:
	/* 0x19d: lea    rdx,[r12+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_1a2:
	/* 0x1a2: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_1ab:
	/* 0x1ab: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae:
	/* 0x1ae: rorx   r8,rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDX, X86_WIDTH_64, 0, 32ULL);
x86_l_1b4:
	/* 0x1b4: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1b7:
	/* 0x1b7: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_1bd:
	/* 0x1bd: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_1c7:
	/* 0x1c7: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_1ca:
	/* 0x1ca: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_1cd:
	/* 0x1cd: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_1d7:
	/* 0x1d7: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_1da:
	/* 0x1da: test   edx,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63999ULL);
x86_l_1e0:
	/* 0x1e0: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_1e4:
	/* 0x1e4: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_1ee:
	/* 0x1ee: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_1f1:
	/* 0x1f1: test   edx,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63743ULL);
x86_l_1f7:
	/* 0x1f7: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_1fb:
	/* 0x1fb: jmp    207 <tail_lb_ipv6+0x207> */
	goto x86_l_207;
x86_l_1fd:
	/* 0x1fd: lea    edi,[rdi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 8ULL);
x86_l_204:
	/* 0x204: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_207:
	/* 0x207: lea    r13d,[rdi+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20b:
	/* 0x20b: cmp    sil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 60ULL);
x86_l_20f:
	/* 0x20f: ja     54e <tail_lb_ipv6+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_54e;
	}
x86_l_215:
	/* 0x215: movzx  r9d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_219:
	/* 0x219: bt     rcx,r9 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R9, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: jae    26c <tail_lb_ipv6+0x26c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_26c;
	}
x86_l_21f:
	/* 0x21f: add    edi,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_222:
	/* 0x222: movzx  r8d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_226:
	/* 0x226: lea    rdx,[r12+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_22a:
	/* 0x22a: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_22e:
	/* 0x22e: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_231:
	/* 0x231: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_237:
	/* 0x237: add    r8,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_23a:
	/* 0x23a: movzx  edx,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_23e:
	/* 0x23e: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_240:
	/* 0x240: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_243:
	/* 0x243: cmp    r9d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 43ULL);
x86_l_247:
	/* 0x247: jle    27d <tail_lb_ipv6+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_27d;
	}
x86_l_249:
	/* 0x249: cmp    r9d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 44ULL);
x86_l_24d:
	/* 0x24d: je     28c <tail_lb_ipv6+0x28c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28c;
	}
x86_l_24f:
	/* 0x24f: cmp    r9d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 51ULL);
x86_l_253:
	/* 0x253: jne    27d <tail_lb_ipv6+0x27d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27d;
	}
x86_l_255:
	/* 0x255: movzx  esi,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_258:
	/* 0x258: lea    edi,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_25f:
	/* 0x25f: jmp    2ee <tail_lb_ipv6+0x2ee> */
	goto x86_l_2ee;
x86_l_264:
	/* 0x264: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_267:
	/* 0x267: jmp    581 <tail_lb_ipv6+0x581> */
	goto x86_l_581;
x86_l_26c:
	/* 0x26c: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_26e:
	/* 0x26e: cmp    r9,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 59ULL);
x86_l_272:
	/* 0x272: je     3f4 <tail_lb_ipv6+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f4;
	}
x86_l_278:
	/* 0x278: jmp    581 <tail_lb_ipv6+0x581> */
	goto x86_l_581;
x86_l_27d:
	/* 0x27d: lea    edi,[rdi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 3), 8ULL);
x86_l_284:
	/* 0x284: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_288:
	/* 0x288: je     291 <tail_lb_ipv6+0x291> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_291;
	}
x86_l_28a:
	/* 0x28a: jmp    2ee <tail_lb_ipv6+0x2ee> */
	goto x86_l_2ee;
x86_l_28c:
	/* 0x28c: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_291:
	/* 0x291: lea    rsi,[r8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_295:
	/* 0x295: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_298:
	/* 0x298: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_29e:
	/* 0x29e: mov    rsi,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a1:
	/* 0x2a1: rorx   r8,rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RSI, X86_WIDTH_64, 0, 32ULL);
x86_l_2a7:
	/* 0x2a7: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2aa:
	/* 0x2aa: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_2b0:
	/* 0x2b0: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_2ba:
	/* 0x2ba: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_2bd:
	/* 0x2bd: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_2c0:
	/* 0x2c0: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_2ca:
	/* 0x2ca: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_2cd:
	/* 0x2cd: test   esi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63999ULL);
x86_l_2d3:
	/* 0x2d3: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_2d7:
	/* 0x2d7: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_2e1:
	/* 0x2e1: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_2e4:
	/* 0x2e4: test   esi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63743ULL);
x86_l_2ea:
	/* 0x2ea: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_2ee:
	/* 0x2ee: add    r13d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f1:
	/* 0x2f1: cmp    dl,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 60ULL);
x86_l_2f4:
	/* 0x2f4: ja     581 <tail_lb_ipv6+0x581> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_581;
	}
x86_l_2fa:
	/* 0x2fa: movzx  edi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2fd:
	/* 0x2fd: bt     rcx,rdi */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_301:
	/* 0x301: jae    577 <tail_lb_ipv6+0x577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_577;
	}
x86_l_307:
	/* 0x307: lea    esi,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_30b:
	/* 0x30b: movzx  r8d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30f:
	/* 0x30f: lea    rsi,[r12+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_313:
	/* 0x313: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_317:
	/* 0x317: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_31a:
	/* 0x31a: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_320:
	/* 0x320: add    r8,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_323:
	/* 0x323: movzx  esi,WORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_327:
	/* 0x327: mov    r9d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_32);
x86_l_32a:
	/* 0x32a: shr    r9d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_32e:
	/* 0x32e: cmp    edi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 43ULL);
x86_l_331:
	/* 0x331: jle    34a <tail_lb_ipv6+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_34a;
	}
x86_l_333:
	/* 0x333: cmp    edi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 44ULL);
x86_l_336:
	/* 0x336: je     359 <tail_lb_ipv6+0x359> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_359;
	}
x86_l_338:
	/* 0x338: cmp    edi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 51ULL);
x86_l_33b:
	/* 0x33b: jne    34a <tail_lb_ipv6+0x34a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_34a;
	}
x86_l_33d:
	/* 0x33d: movzx  edx,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_341:
	/* 0x341: lea    edi,[rdx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 8ULL);
x86_l_348:
	/* 0x348: jmp    3bb <tail_lb_ipv6+0x3bb> */
	goto x86_l_3bb;
x86_l_34a:
	/* 0x34a: lea    edi,[r9*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 8ULL);
x86_l_352:
	/* 0x352: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_355:
	/* 0x355: je     35e <tail_lb_ipv6+0x35e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35e;
	}
x86_l_357:
	/* 0x357: jmp    3bb <tail_lb_ipv6+0x3bb> */
	goto x86_l_3bb;
x86_l_359:
	/* 0x359: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_35e:
	/* 0x35e: lea    rdx,[r8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_362:
	/* 0x362: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_365:
	/* 0x365: ja     3ef <tail_lb_ipv6+0x3ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_3ef;
	}
x86_l_36b:
	/* 0x36b: mov    rdx,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36e:
	/* 0x36e: rorx   r8,rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDX, X86_WIDTH_64, 0, 32ULL);
x86_l_374:
	/* 0x374: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_377:
	/* 0x377: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_37d:
	/* 0x37d: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_387:
	/* 0x387: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_38a:
	/* 0x38a: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_38d:
	/* 0x38d: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_397:
	/* 0x397: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_39a:
	/* 0x39a: test   edx,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63999ULL);
x86_l_3a0:
	/* 0x3a0: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_3a4:
	/* 0x3a4: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_3ae:
	/* 0x3ae: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b1:
	/* 0x3b1: test   edx,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63743ULL);
x86_l_3b7:
	/* 0x3b7: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_3bb:
	/* 0x3bb: add    r13d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3be:
	/* 0x3be: cmp    sil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 60ULL);
x86_l_3c2:
	/* 0x3c2: ja     54e <tail_lb_ipv6+0x54e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_54e;
	}
x86_l_3c8:
	/* 0x3c8: movzx  edi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3cc:
	/* 0x3cc: bt     rcx,rdi */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDI, X86_WIDTH_64);
x86_l_3d0:
	/* 0x3d0: jae    575 <tail_lb_ipv6+0x575> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_575;
	}
x86_l_3d6:
	/* 0x3d6: add    r13d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_3da:
	/* 0x3da: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3de:
	/* 0x3de: lea    rdx,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_3e2:
	/* 0x3e2: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3e6:
	/* 0x3e6: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3e9:
	/* 0x3e9: jbe    552 <tail_lb_ipv6+0x552> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_552;
	}
x86_l_3ef:
	/* 0x3ef: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_3f4:
	/* 0x3f4: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3fc:
	/* 0x3fc: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_403:
	/* 0x403: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_408:
	/* 0x408: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_40e:
	/* 0x40e: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_411:
	/* 0x411: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_414:
	/* 0x414: je     41c <tail_lb_ipv6+0x41c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41c;
	}
x86_l_416:
	/* 0x416: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41c:
	/* 0x41c: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_424:
	/* 0x424: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_42b:
	/* 0x42b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_430:
	/* 0x430: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_433:
	/* 0x433: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_436:
	/* 0x436: je     43f <tail_lb_ipv6+0x43f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_43f;
	}
x86_l_438:
	/* 0x438: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_43f:
	/* 0x43f: neg    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_441:
	/* 0x441: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_449:
	/* 0x449: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_450:
	/* 0x450: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_455:
	/* 0x455: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_45b:
	/* 0x45b: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_45e:
	/* 0x45e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_461:
	/* 0x461: je     474 <tail_lb_ipv6+0x474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_474;
	}
x86_l_463:
	/* 0x463: shl    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_467:
	/* 0x467: movzx  ecx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_46b:
	/* 0x46b: movzx  edx,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_46f:
	/* 0x46f: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_471:
	/* 0x471: mov    DWORD PTR [rax+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_474:
	/* 0x474: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_47c:
	/* 0x47c: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_483:
	/* 0x483: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488:
	/* 0x488: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_48b:
	/* 0x48b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_48e:
	/* 0x48e: je     497 <tail_lb_ipv6+0x497> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_497;
	}
x86_l_490:
	/* 0x490: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_497:
	/* 0x497: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_49f:
	/* 0x49f: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_4a6:
	/* 0x4a6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ab:
	/* 0x4ab: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_4b1:
	/* 0x4b1: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_4b4:
	/* 0x4b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: je     4c0 <tail_lb_ipv6+0x4c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c0;
	}
x86_l_4b9:
	/* 0x4b9: mov    DWORD PTR [rax+0x10],0xc30401 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68732257281ULL);
x86_l_4c0:
	/* 0x4c0: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c2:
	/* 0x4c2: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c6:
	/* 0x4c6: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4c9:
	/* 0x4c9: movabs rax,0x400c30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 17192648960ULL);
x86_l_4d3:
	/* 0x4d3: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d8:
	/* 0x4d8: mov    BYTE PTR [rsp+0x50],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4dd:
	/* 0x4dd: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4e4:
	/* 0x4e4: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4e9:
	/* 0x4e9: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_4ec:
	/* 0x4ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ef:
	/* 0x4ef: je     4fa <tail_lb_ipv6+0x4fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4fa;
	}
x86_l_4f1:
	/* 0x4f1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4f4:
	/* 0x4f4: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4f8:
	/* 0x4f8: jmp    522 <tail_lb_ipv6+0x522> */
	goto x86_l_522;
x86_l_4fa:
	/* 0x4fa: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_503:
	/* 0x503: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_508:
	/* 0x508: mov    rdi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_50f:
	/* 0x50f: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_514:
	/* 0x514: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_519:
	/* 0x519: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_51e:
	/* 0x51e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_520:
	/* 0x520: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_522:
	/* 0x522: mov    rsi,QWORD PTR [rip+0x10407] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_529:
	/* 0x529: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_52e:
	/* 0x52e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_533:
	/* 0x533: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_536:
	/* 0x536: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_53b:
	/* 0x53b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53d:
	/* 0x53d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_53f:
	/* 0x53f: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_546:
	/* 0x546: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_548:
	/* 0x548: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_549:
	/* 0x549: jmp    2f8d <tail_lb_ipv6+0x2f8d> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_54e:
	/* 0x54e: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_550:
	/* 0x550: jmp    581 <tail_lb_ipv6+0x581> */
	goto x86_l_581;
x86_l_552:
	/* 0x552: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_555:
	/* 0x555: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_559:
	/* 0x559: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_55c:
	/* 0x55c: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_561:
	/* 0x561: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_566:
	/* 0x566: cmovbe ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_BE);
x86_l_569:
	/* 0x569: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_56d:
	/* 0x56d: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_570:
	/* 0x570: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	goto x86_l_3f4;
x86_l_575:
	/* 0x575: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_577:
	/* 0x577: cmp    rdi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 59ULL);
x86_l_57b:
	/* 0x57b: je     3f4 <tail_lb_ipv6+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f4;
	}
x86_l_581:
	/* 0x581: mov    BYTE PTR [rsp+0x74],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_585:
	/* 0x585: mov    rcx,QWORD PTR [r12+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_58a:
	/* 0x58a: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_58f:
	/* 0x58f: mov    rsi,QWORD PTR [r12+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rsp+0x50],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_599:
	/* 0x599: mov    rdi,QWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_59e:
	/* 0x59e: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5a3:
	/* 0x5a3: mov    rdi,QWORD PTR [r12+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_5a8:
	/* 0x5a8: mov    QWORD PTR [rsp+0x60],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5ad:
	/* 0x5ad: cmp    dl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 6ULL);
x86_l_5b0:
	/* 0x5b0: je     5c7 <tail_lb_ipv6+0x5c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5c7;
	}
x86_l_5b2:
	/* 0x5b2: movzx  edi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b5:
	/* 0x5b5: cmp    edi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 58ULL);
x86_l_5b8:
	/* 0x5b8: je     63a <tail_lb_ipv6+0x63a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_63a;
	}
x86_l_5be:
	/* 0x5be: cmp    edi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 17ULL);
x86_l_5c1:
	/* 0x5c1: jne    2972 <tail_lb_ipv6+0x2972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10610ULL;
	}
x86_l_5c7:
	/* 0x5c7: lea    r9d,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5cb:
	/* 0x5cb: movabs rdi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 2199023255552ULL);
x86_l_5d5:
	/* 0x5d5: mov    r8,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_5dc:
	/* 0x5dc: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e0:
	/* 0x5e0: je     75d <tail_lb_ipv6+0x75d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1885ULL;
	}
x86_l_5e6:
	/* 0x5e6: lea    r14,[r12+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5eb:
	/* 0x5eb: mov    r15,QWORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5f0:
	/* 0x5f0: mov    QWORD PTR [r12+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_5f9:
	/* 0x5f9: mov    DWORD PTR [r12+0xe],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5fe:
	/* 0x5fe: mov    rax,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_64);
x86_l_601:
	/* 0x601: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_605:
	/* 0x605: mov    BYTE PTR [r12+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_60a:
	/* 0x60a: test   r10,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_RDI, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: jne    18da <tail_lb_ipv6+0x18da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6362ULL;
	}
x86_l_613:
	/* 0x613: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_615:
	/* 0x615: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_618:
	/* 0x618: movzx  ecx,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_61c:
	/* 0x61c: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_620:
	/* 0x620: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_624:
	/* 0x624: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_629:
	/* 0x629: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_62c:
	/* 0x62c: jbe    79b <tail_lb_ipv6+0x79b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 1947ULL;
	}
x86_l_632:
	/* 0x632: mov    QWORD PTR [r14],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_635:
	/* 0x635: jmp    af <tail_lb_ipv6+0xaf> */
	goto x86_l_af;
x86_l_63a:
	/* 0x63a: mov    QWORD PTR [rsp+0x48],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_63f:
	/* 0x63f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_641:
	/* 0x641: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_649:
	/* 0x649: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_650:
	/* 0x650: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_655:
	/* 0x655: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_65b:
	/* 0x65b: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_65e:
	/* 0x65e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_661:
	/* 0x661: je     190a <tail_lb_ipv6+0x190a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6410ULL;
	}
x86_l_667:
	/* 0x667: mov    r15d,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_66b:
	/* 0x66b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_673:
	/* 0x673: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_67a:
	/* 0x67a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67f:
	/* 0x67f: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_682:
	/* 0x682: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_685:
	/* 0x685: je     68f <tail_lb_ipv6+0x68f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_68f;
	}
x86_l_687:
	/* 0x687: or     r15d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_68b:
	/* 0x68b: mov    DWORD PTR [rax+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_68f:
	/* 0x68f: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_692:
	/* 0x692: je     fff <tail_lb_ipv6+0xfff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4095ULL;
	}
x86_l_698:
	/* 0x698: mov    rax,QWORD PTR [rsp+0x6e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 110ULL);
x86_l_69d:
	/* 0x69d: mov    QWORD PTR [rsp+0x26],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_6a2:
	/* 0x6a2: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6a7:
	/* 0x6a7: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6ac:
	/* 0x6ac: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6b1:
	/* 0x6b1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6b6:
	/* 0x6b6: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6bb:
	/* 0x6bb: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6c0:
	/* 0x6c0: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6c5:
	/* 0x6c5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ca:
	/* 0x6ca: movzx  eax,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
	return 1743ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1743ULL: goto x86_l_6cf;
	case 1745ULL: goto x86_l_6d1;
	case 1751ULL: goto x86_l_6d7;
	case 1755ULL: goto x86_l_6db;
	case 1757ULL: goto x86_l_6dd;
	case 1760ULL: goto x86_l_6e0;
	case 1763ULL: goto x86_l_6e3;
	case 1767ULL: goto x86_l_6e7;
	case 1771ULL: goto x86_l_6eb;
	case 1776ULL: goto x86_l_6f0;
	case 1779ULL: goto x86_l_6f3;
	case 1785ULL: goto x86_l_6f9;
	case 1788ULL: goto x86_l_6fc;
	case 1791ULL: goto x86_l_6ff;
	case 1796ULL: goto x86_l_704;
	case 1801ULL: goto x86_l_709;
	case 1806ULL: goto x86_l_70e;
	case 1811ULL: goto x86_l_713;
	case 1816ULL: goto x86_l_718;
	case 1821ULL: goto x86_l_71d;
	case 1826ULL: goto x86_l_722;
	case 1831ULL: goto x86_l_727;
	case 1836ULL: goto x86_l_72c;
	case 1841ULL: goto x86_l_731;
	case 1845ULL: goto x86_l_735;
	case 1850ULL: goto x86_l_73a;
	case 1856ULL: goto x86_l_740;
	case 1862ULL: goto x86_l_746;
	case 1867ULL: goto x86_l_74b;
	case 1873ULL: goto x86_l_751;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1888ULL: goto x86_l_760;
	case 1891ULL: goto x86_l_763;
	case 1897ULL: goto x86_l_769;
	case 1901ULL: goto x86_l_76d;
	case 1905ULL: goto x86_l_771;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1917ULL: goto x86_l_77d;
	case 1923ULL: goto x86_l_783;
	case 1928ULL: goto x86_l_788;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1945ULL: goto x86_l_799;
	case 1947ULL: goto x86_l_79b;
	case 1950ULL: goto x86_l_79e;
	case 1952ULL: goto x86_l_7a0;
	case 1956ULL: goto x86_l_7a4;
	case 1961ULL: goto x86_l_7a9;
	case 1967ULL: goto x86_l_7af;
	case 1972ULL: goto x86_l_7b4;
	case 1977ULL: goto x86_l_7b9;
	case 1980ULL: goto x86_l_7bc;
	case 1985ULL: goto x86_l_7c1;
	case 1990ULL: goto x86_l_7c6;
	case 1995ULL: goto x86_l_7cb;
	case 2000ULL: goto x86_l_7d0;
	case 2007ULL: goto x86_l_7d7;
	case 2015ULL: goto x86_l_7df;
	case 2023ULL: goto x86_l_7e7;
	case 2031ULL: goto x86_l_7ef;
	case 2041ULL: goto x86_l_7f9;
	case 2049ULL: goto x86_l_801;
	case 2056ULL: goto x86_l_808;
	case 2064ULL: goto x86_l_810;
	case 2070ULL: goto x86_l_816;
	case 2073ULL: goto x86_l_819;
	case 2076ULL: goto x86_l_81c;
	case 2078ULL: goto x86_l_81e;
	case 2086ULL: goto x86_l_826;
	case 2095ULL: goto x86_l_82f;
	case 2105ULL: goto x86_l_839;
	case 2113ULL: goto x86_l_841;
	case 2120ULL: goto x86_l_848;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2134ULL: goto x86_l_856;
	case 2140ULL: goto x86_l_85c;
	case 2143ULL: goto x86_l_85f;
	case 2152ULL: goto x86_l_868;
	case 2154ULL: goto x86_l_86a;
	case 2162ULL: goto x86_l_872;
	case 2164ULL: goto x86_l_874;
	case 2169ULL: goto x86_l_879;
	case 2174ULL: goto x86_l_87e;
	case 2178ULL: goto x86_l_882;
	case 2180ULL: goto x86_l_884;
	case 2184ULL: goto x86_l_888;
	case 2188ULL: goto x86_l_88c;
	case 2196ULL: goto x86_l_894;
	case 2201ULL: goto x86_l_899;
	case 2208ULL: goto x86_l_8a0;
	case 2212ULL: goto x86_l_8a4;
	case 2217ULL: goto x86_l_8a9;
	case 2222ULL: goto x86_l_8ae;
	case 2227ULL: goto x86_l_8b3;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2247ULL: goto x86_l_8c7;
	case 2249ULL: goto x86_l_8c9;
	case 2252ULL: goto x86_l_8cc;
	case 2255ULL: goto x86_l_8cf;
	case 2258ULL: goto x86_l_8d2;
	case 2261ULL: goto x86_l_8d5;
	case 2266ULL: goto x86_l_8da;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2279ULL: goto x86_l_8e7;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2294ULL: goto x86_l_8f6;
	case 2297ULL: goto x86_l_8f9;
	case 2303ULL: goto x86_l_8ff;
	case 2306ULL: goto x86_l_902;
	case 2312ULL: goto x86_l_908;
	case 2316ULL: goto x86_l_90c;
	case 2318ULL: goto x86_l_90e;
	case 2321ULL: goto x86_l_911;
	case 2327ULL: goto x86_l_917;
	case 2337ULL: goto x86_l_921;
	case 2343ULL: goto x86_l_927;
	case 2347ULL: goto x86_l_92b;
	case 2353ULL: goto x86_l_931;
	case 2360ULL: goto x86_l_938;
	case 2365ULL: goto x86_l_93d;
	case 2371ULL: goto x86_l_943;
	case 2375ULL: goto x86_l_947;
	case 2381ULL: goto x86_l_94d;
	case 2391ULL: goto x86_l_957;
	case 2395ULL: goto x86_l_95b;
	case 2401ULL: goto x86_l_961;
	case 2403ULL: goto x86_l_963;
	case 2406ULL: goto x86_l_966;
	case 2410ULL: goto x86_l_96a;
	case 2415ULL: goto x86_l_96f;
	case 2418ULL: goto x86_l_972;
	case 2424ULL: goto x86_l_978;
	case 2429ULL: goto x86_l_97d;
	case 2432ULL: goto x86_l_980;
	case 2436ULL: goto x86_l_984;
	case 2439ULL: goto x86_l_987;
	case 2441ULL: goto x86_l_989;
	case 2444ULL: goto x86_l_98c;
	case 2450ULL: goto x86_l_992;
	case 2453ULL: goto x86_l_995;
	case 2459ULL: goto x86_l_99b;
	case 2463ULL: goto x86_l_99f;
	case 2471ULL: goto x86_l_9a7;
	case 2474ULL: goto x86_l_9aa;
	case 2480ULL: goto x86_l_9b0;
	case 2485ULL: goto x86_l_9b5;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2498ULL: goto x86_l_9c2;
	case 2504ULL: goto x86_l_9c8;
	case 2508ULL: goto x86_l_9cc;
	case 2511ULL: goto x86_l_9cf;
	case 2517ULL: goto x86_l_9d5;
	case 2522ULL: goto x86_l_9da;
	case 2528ULL: goto x86_l_9e0;
	case 2534ULL: goto x86_l_9e6;
	case 2538ULL: goto x86_l_9ea;
	case 2542ULL: goto x86_l_9ee;
	case 2547ULL: goto x86_l_9f3;
	case 2555ULL: goto x86_l_9fb;
	case 2564ULL: goto x86_l_a04;
	case 2567ULL: goto x86_l_a07;
	case 2572ULL: goto x86_l_a0c;
	case 2579ULL: goto x86_l_a13;
	case 2584ULL: goto x86_l_a18;
	case 2589ULL: goto x86_l_a1d;
	case 2594ULL: goto x86_l_a22;
	case 2596ULL: goto x86_l_a24;
	case 2601ULL: goto x86_l_a29;
	case 2604ULL: goto x86_l_a2c;
	case 2610ULL: goto x86_l_a32;
	case 2614ULL: goto x86_l_a36;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2632ULL: goto x86_l_a48;
	case 2637ULL: goto x86_l_a4d;
	case 2642ULL: goto x86_l_a52;
	case 2647ULL: goto x86_l_a57;
	case 2652ULL: goto x86_l_a5c;
	case 2659ULL: goto x86_l_a63;
	case 2664ULL: goto x86_l_a68;
	case 2674ULL: goto x86_l_a72;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2696ULL: goto x86_l_a88;
	case 2704ULL: goto x86_l_a90;
	case 2708ULL: goto x86_l_a94;
	case 2713ULL: goto x86_l_a99;
	case 2718ULL: goto x86_l_a9e;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2734ULL: goto x86_l_aae;
	case 2737ULL: goto x86_l_ab1;
	case 2745ULL: goto x86_l_ab9;
	case 2753ULL: goto x86_l_ac1;
	case 2759ULL: goto x86_l_ac7;
	case 2762ULL: goto x86_l_aca;
	case 2768ULL: goto x86_l_ad0;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2779ULL: goto x86_l_adb;
	case 2782ULL: goto x86_l_ade;
	case 2784ULL: goto x86_l_ae0;
	case 2788ULL: goto x86_l_ae4;
	case 2791ULL: goto x86_l_ae7;
	case 2800ULL: goto x86_l_af0;
	case 2809ULL: goto x86_l_af9;
	case 2819ULL: goto x86_l_b03;
	case 2825ULL: goto x86_l_b09;
	case 2833ULL: goto x86_l_b11;
	case 2840ULL: goto x86_l_b18;
	case 2848ULL: goto x86_l_b20;
	case 2853ULL: goto x86_l_b25;
	case 2855ULL: goto x86_l_b27;
	case 2858ULL: goto x86_l_b2a;
	case 2864ULL: goto x86_l_b30;
	case 2867ULL: goto x86_l_b33;
	case 2871ULL: goto x86_l_b37;
	case 2876ULL: goto x86_l_b3c;
	case 2886ULL: goto x86_l_b46;
	case 2891ULL: goto x86_l_b4b;
	case 2896ULL: goto x86_l_b50;
	case 2898ULL: goto x86_l_b52;
	case 2902ULL: goto x86_l_b56;
	case 2910ULL: goto x86_l_b5e;
	case 2914ULL: goto x86_l_b62;
	case 2920ULL: goto x86_l_b68;
	case 2924ULL: goto x86_l_b6c;
	case 2928ULL: goto x86_l_b70;
	case 2934ULL: goto x86_l_b76;
	case 2938ULL: goto x86_l_b7a;
	case 2942ULL: goto x86_l_b7e;
	case 2946ULL: goto x86_l_b82;
	case 2950ULL: goto x86_l_b86;
	case 2954ULL: goto x86_l_b8a;
	case 2957ULL: goto x86_l_b8d;
	case 2963ULL: goto x86_l_b93;
	case 2966ULL: goto x86_l_b96;
	case 2970ULL: goto x86_l_b9a;
	case 2973ULL: goto x86_l_b9d;
	case 2977ULL: goto x86_l_ba1;
	case 2981ULL: goto x86_l_ba5;
	case 2983ULL: goto x86_l_ba7;
	case 2987ULL: goto x86_l_bab;
	case 2993ULL: goto x86_l_bb1;
	case 2997ULL: goto x86_l_bb5;
	case 2999ULL: goto x86_l_bb7;
	case 3003ULL: goto x86_l_bbb;
	case 3011ULL: goto x86_l_bc3;
	case 3016ULL: goto x86_l_bc8;
	case 3020ULL: goto x86_l_bcc;
	case 3028ULL: goto x86_l_bd4;
	case 3032ULL: goto x86_l_bd8;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3049ULL: goto x86_l_be9;
	case 3053ULL: goto x86_l_bed;
	case 3056ULL: goto x86_l_bf0;
	case 3062ULL: goto x86_l_bf6;
	case 3065ULL: goto x86_l_bf9;
	case 3068ULL: goto x86_l_bfc;
	case 3075ULL: goto x86_l_c03;
	case 3080ULL: goto x86_l_c08;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3097ULL: goto x86_l_c19;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3109ULL: goto x86_l_c25;
	case 3118ULL: goto x86_l_c2e;
	case 3123ULL: goto x86_l_c33;
	case 3130ULL: goto x86_l_c3a;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3148ULL: goto x86_l_c4c;
	case 3150ULL: goto x86_l_c4e;
	case 3152ULL: goto x86_l_c50;
	case 3155ULL: goto x86_l_c53;
	case 3158ULL: goto x86_l_c56;
	case 3161ULL: goto x86_l_c59;
	case 3169ULL: goto x86_l_c61;
	case 3175ULL: goto x86_l_c67;
	case 3177ULL: goto x86_l_c69;
	case 3181ULL: goto x86_l_c6d;
	case 3183ULL: goto x86_l_c6f;
	case 3186ULL: goto x86_l_c72;
	case 3192ULL: goto x86_l_c78;
	case 3195ULL: goto x86_l_c7b;
	case 3197ULL: goto x86_l_c7d;
	case 3201ULL: goto x86_l_c81;
	case 3203ULL: goto x86_l_c83;
	case 3206ULL: goto x86_l_c86;
	case 3209ULL: goto x86_l_c89;
	case 3213ULL: goto x86_l_c8d;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3226ULL: goto x86_l_c9a;
	case 3229ULL: goto x86_l_c9d;
	case 3232ULL: goto x86_l_ca0;
	case 3234ULL: goto x86_l_ca2;
	case 3240ULL: goto x86_l_ca8;
	case 3243ULL: goto x86_l_cab;
	case 3249ULL: goto x86_l_cb1;
	case 3252ULL: goto x86_l_cb4;
	case 3258ULL: goto x86_l_cba;
	case 3264ULL: goto x86_l_cc0;
	case 3267ULL: goto x86_l_cc3;
	case 3269ULL: goto x86_l_cc5;
	case 3272ULL: goto x86_l_cc8;
	case 3277ULL: goto x86_l_ccd;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3292ULL: goto x86_l_cdc;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3303ULL: goto x86_l_ce7;
	case 3306ULL: goto x86_l_cea;
	case 3311ULL: goto x86_l_cef;
	case 3316ULL: goto x86_l_cf4;
	case 3322ULL: goto x86_l_cfa;
	case 3328ULL: goto x86_l_d00;
	case 3336ULL: goto x86_l_d08;
	case 3342ULL: goto x86_l_d0e;
	case 3347ULL: goto x86_l_d13;
	case 3353ULL: goto x86_l_d19;
	case 3356ULL: goto x86_l_d1c;
	case 3363ULL: goto x86_l_d23;
	case 3366ULL: goto x86_l_d26;
	case 3372ULL: goto x86_l_d2c;
	case 3379ULL: goto x86_l_d33;
	case 3382ULL: goto x86_l_d36;
	case 3386ULL: goto x86_l_d3a;
	case 3390ULL: goto x86_l_d3e;
	case 3393ULL: goto x86_l_d41;
	case 3397ULL: goto x86_l_d45;
	case 3402ULL: goto x86_l_d4a;
	case 3407ULL: goto x86_l_d4f;
	case 3411ULL: goto x86_l_d53;
	case 3417ULL: goto x86_l_d59;
	case 3421ULL: goto x86_l_d5d;
	case 3425ULL: goto x86_l_d61;
	case 3427ULL: goto x86_l_d63;
	case 3431ULL: goto x86_l_d67;
	case 3435ULL: goto x86_l_d6b;
	case 3438ULL: goto x86_l_d6e;
	case 3442ULL: goto x86_l_d72;
	case 3446ULL: goto x86_l_d76;
	case 3450ULL: goto x86_l_d7a;
	case 3454ULL: goto x86_l_d7e;
	case 3457ULL: goto x86_l_d81;
	case 3463ULL: goto x86_l_d87;
	case 3466ULL: goto x86_l_d8a;
	case 3470ULL: goto x86_l_d8e;
	case 3473ULL: goto x86_l_d91;
	case 3477ULL: goto x86_l_d95;
	case 3481ULL: goto x86_l_d99;
	case 3483ULL: goto x86_l_d9b;
	case 3487ULL: goto x86_l_d9f;
	case 3489ULL: goto x86_l_da1;
	case 3493ULL: goto x86_l_da5;
	case 3495ULL: goto x86_l_da7;
	case 3499ULL: goto x86_l_dab;
	case 3507ULL: goto x86_l_db3;
	case 3509ULL: goto x86_l_db5;
	case 3514ULL: goto x86_l_dba;
	case 3518ULL: goto x86_l_dbe;
	case 3524ULL: goto x86_l_dc4;
	case 3529ULL: goto x86_l_dc9;
	case 3533ULL: goto x86_l_dcd;
	case 3541ULL: goto x86_l_dd5;
	case 3545ULL: goto x86_l_dd9;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	default: return 0xffffffffffffffffULL;
	}
x86_l_6cf:
	/* 0x6cf: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_6d1:
	/* 0x6d1: jne    93d <tail_lb_ipv6+0x93d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_93d;
	}
x86_l_6d7:
	/* 0x6d7: lea    edx,[r13+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_6db:
	/* 0x6db: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6dd:
	/* 0x6dd: mov    esi,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6e0:
	/* 0x6e0: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6e3:
	/* 0x6e3: lea    rdi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_6e7:
	/* 0x6e7: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_6eb:
	/* 0x6eb: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_6f0:
	/* 0x6f0: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_6f3:
	/* 0x6f3: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_6f9:
	/* 0x6f9: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6fc:
	/* 0x6fc: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6ff:
	/* 0x6ff: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_704:
	/* 0x704: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_709:
	/* 0x709: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70e:
	/* 0x70e: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_713:
	/* 0x713: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_718:
	/* 0x718: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_71d:
	/* 0x71d: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_722:
	/* 0x722: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_727:
	/* 0x727: rol    DWORD PTR [rsp+0x28],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 171798691856ULL);
x86_l_72c:
	/* 0x72c: movzx  ebp,BYTE PTR [rsp+0x2d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 45ULL);
x86_l_731:
	/* 0x731: xor    bpl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_735:
	/* 0x735: mov    BYTE PTR [rsp+0x2d],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_73a:
	/* 0x73a: test   ecx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_740:
	/* 0x740: jne    93d <tail_lb_ipv6+0x93d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_93d;
	}
x86_l_746:
	/* 0x746: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_74b:
	/* 0x74b: jne    a0c <tail_lb_ipv6+0xa0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a0c;
	}
x86_l_751:
	/* 0x751: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_758:
	/* 0x758: jmp    a13 <tail_lb_ipv6+0xa13> */
	goto x86_l_a13;
x86_l_75d:
	/* 0x75d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_760:
	/* 0x760: test   r10,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_RDI, X86_WIDTH_64);
x86_l_763:
	/* 0x763: jne    1b57 <tail_lb_ipv6+0x1b57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6999ULL;
	}
x86_l_769:
	/* 0x769: movzx  edi,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_76d:
	/* 0x76d: lea    r8,[r12+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_771:
	/* 0x771: add    r8,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_775:
	/* 0x775: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_77a:
	/* 0x77a: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_77d:
	/* 0x77d: ja     3f4 <tail_lb_ipv6+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1012ULL;
	}
x86_l_783:
	/* 0x783: mov    QWORD PTR [rsp+0x78],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_788:
	/* 0x788: mov    QWORD PTR [rsp+0x48],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_78d:
	/* 0x78d: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_790:
	/* 0x790: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_792:
	/* 0x792: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_796:
	/* 0x796: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_799:
	/* 0x799: jmp    7d0 <tail_lb_ipv6+0x7d0> */
	goto x86_l_7d0;
x86_l_79b:
	/* 0x79b: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_79e:
	/* 0x79e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a0:
	/* 0x7a0: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7a4:
	/* 0x7a4: bt     r10,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R10, X86_WIDTH_64, 40ULL);
x86_l_7a9:
	/* 0x7a9: jb     1b61 <tail_lb_ipv6+0x1b61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 7009ULL;
	}
x86_l_7af:
	/* 0x7af: mov    QWORD PTR [rsp+0x78],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_7b4:
	/* 0x7b4: mov    QWORD PTR [rsp+0x48],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7b9:
	/* 0x7b9: mov    QWORD PTR [r14],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bc:
	/* 0x7bc: movzx  edx,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_7c1:
	/* 0x7c1: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7c6:
	/* 0x7c6: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7cb:
	/* 0x7cb: movzx  eax,WORD PTR [rsp+0x72] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 114ULL);
x86_l_7d0:
	/* 0x7d0: mov    BYTE PTR [rsp+0xac],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_7d7:
	/* 0x7d7: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_7df:
	/* 0x7df: mov    QWORD PTR [rsp+0x98],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7e7:
	/* 0x7e7: mov    WORD PTR [rsp+0xa8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7ef:
	/* 0x7ef: mov    WORD PTR [rsp+0xaa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 730144440320ULL);
x86_l_7f9:
	/* 0x7f9: mov    BYTE PTR [rsp+0xad],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342208ULL);
x86_l_801:
	/* 0x801: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_808:
	/* 0x808: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_810:
	/* 0x810: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_816:
	/* 0x816: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_819:
	/* 0x819: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81c:
	/* 0x81c: jne    85c <tail_lb_ipv6+0x85c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_85c;
	}
x86_l_81e:
	/* 0x81e: movzx  ebp,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_826:
	/* 0x826: movzx  r15d,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_82f:
	/* 0x82f: mov    WORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_839:
	/* 0x839: mov    BYTE PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_841:
	/* 0x841: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_848:
	/* 0x848: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_850:
	/* 0x850: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_853:
	/* 0x853: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_856:
	/* 0x856: je     9f3 <tail_lb_ipv6+0x9f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_9f3;
	}
x86_l_85c:
	/* 0x85c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85f:
	/* 0x85f: cmp    WORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_868:
	/* 0x868: jne    87e <tail_lb_ipv6+0x87e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_87e;
	}
x86_l_86a:
	/* 0x86a: cmp    BYTE PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_872:
	/* 0x872: jne    87e <tail_lb_ipv6+0x87e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_87e;
	}
x86_l_874:
	/* 0x874: mov    ebp,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967138ULL);
x86_l_879:
	/* 0x879: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	return 1012ULL;
x86_l_87e:
	/* 0x87e: cmp    BYTE PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_882:
	/* 0x882: jns    8ed <tail_lb_ipv6+0x8ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_8ed;
	}
x86_l_884:
	/* 0x884: add    r12,0x16 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 22ULL);
x86_l_888:
	/* 0x888: movzx  ecx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_88c:
	/* 0x88c: mov    DWORD PTR [rsp+0x8],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738528ULL);
x86_l_894:
	/* 0x894: mov    WORD PTR [rsp+0xc],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_899:
	/* 0x899: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_8a0:
	/* 0x8a0: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a4:
	/* 0x8a4: mov    rdx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a9:
	/* 0x8a9: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8ae:
	/* 0x8ae: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b3:
	/* 0x8b3: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_source_range)));
x86_l_8ba:
	/* 0x8ba: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8bf:
	/* 0x8bf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8c4:
	/* 0x8c4: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8c7:
	/* 0x8c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_8c9:
	/* 0x8c9: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8cc:
	/* 0x8cc: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_8cf:
	/* 0x8cf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_8d2:
	/* 0x8d2: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_8d5:
	/* 0x8d5: movzx  edx,BYTE PTR [r14+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_8da:
	/* 0x8da: and    dl,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_AND, 64ULL);
x86_l_8dd:
	/* 0x8dd: shr    dl,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_SHR, 6ULL);
x86_l_8e0:
	/* 0x8e0: mov    ebp,0xffffff4f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967119ULL);
x86_l_8e5:
	/* 0x8e5: cmp    cl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_8);
x86_l_8e7:
	/* 0x8e7: je     3f4 <tail_lb_ipv6+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1012ULL;
	}
x86_l_8ed:
	/* 0x8ed: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_8f1:
	/* 0x8f1: mov    ebp,0xffffff52 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967122ULL);
x86_l_8f6:
	/* 0x8f6: test   cl,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_8f9:
	/* 0x8f9: je     3f4 <tail_lb_ipv6+0x3f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1012ULL;
	}
x86_l_8ff:
	/* 0x8ff: test   cl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_902:
	/* 0x902: jne    33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 51ULL;
	}
x86_l_908:
	/* 0x908: test   BYTE PTR [rax+0x9],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705668ULL);
x86_l_90c:
	/* 0x90c: je     917 <tail_lb_ipv6+0x917> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_917;
	}
x86_l_90e:
	/* 0x90e: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_911:
	/* 0x911: jne    33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 51ULL;
	}
x86_l_917:
	/* 0x917: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_921:
	/* 0x921: movzx  r14d,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_927:
	/* 0x927: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_92b:
	/* 0x92b: jne    a5c <tail_lb_ipv6+0xa5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_a5c;
	}
x86_l_931:
	/* 0x931: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_938:
	/* 0x938: jmp    a63 <tail_lb_ipv6+0xa63> */
	goto x86_l_a63;
x86_l_93d:
	/* 0x93d: movzx  edi,BYTE PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_943:
	/* 0x943: cmp    rdi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 60ULL);
x86_l_947:
	/* 0x947: ja     f3d <tail_lb_ipv6+0xf3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3901ULL;
	}
x86_l_94d:
	/* 0x94d: movabs rsi,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_957:
	/* 0x957: bt     rsi,rdi */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_95b:
	/* 0x95b: jae    f2e <tail_lb_ipv6+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 3886ULL;
	}
x86_l_961:
	/* 0x961: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_963:
	/* 0x963: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_966:
	/* 0x966: lea    r8,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_96a:
	/* 0x96a: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_96f:
	/* 0x96f: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_972:
	/* 0x972: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_978:
	/* 0x978: movzx  r8d,WORD PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 54ULL);
x86_l_97d:
	/* 0x97d: mov    r9d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R8, X86_WIDTH_32);
x86_l_980:
	/* 0x980: shr    r9d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_984:
	/* 0x984: cmp    edi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 43ULL);
x86_l_987:
	/* 0x987: jle    99b <tail_lb_ipv6+0x99b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_99b;
	}
x86_l_989:
	/* 0x989: cmp    edi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 44ULL);
x86_l_98c:
	/* 0x98c: je     b4b <tail_lb_ipv6+0xb4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b4b;
	}
x86_l_992:
	/* 0x992: cmp    edi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 60ULL);
x86_l_995:
	/* 0x995: jne    b52 <tail_lb_ipv6+0xb52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b52;
	}
x86_l_99b:
	/* 0x99b: movzx  r9d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_99f:
	/* 0x99f: lea    r9d,[r9*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 8ULL);
x86_l_9a7:
	/* 0x9a7: cmp    edi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 60ULL);
x86_l_9aa:
	/* 0x9aa: jne    b5e <tail_lb_ipv6+0xb5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5e;
	}
x86_l_9b0:
	/* 0x9b0: cmp    r9w,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_16, 24ULL);
x86_l_9b5:
	/* 0x9b5: jne    b5e <tail_lb_ipv6+0xb5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5e;
	}
x86_l_9bb:
	/* 0x9bb: lea    rdi,[rcx+0x4e] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_9bf:
	/* 0x9bf: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_9c2:
	/* 0x9c2: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_9c8:
	/* 0x9c8: mov    r11,QWORD PTR [rcx+0x36] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_9cc:
	/* 0x9cc: mov    edi,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R11, X86_WIDTH_32);
x86_l_9cf:
	/* 0x9cf: and    edi,0xffff0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294901760ULL);
x86_l_9d5:
	/* 0x9d5: mov    r9w,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_16, 24ULL);
x86_l_9da:
	/* 0x9da: cmp    edi,0x141b0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 337313792ULL);
x86_l_9e0:
	/* 0x9e0: jne    b5e <tail_lb_ipv6+0xb5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b5e;
	}
x86_l_9e6:
	/* 0x9e6: lea    rax,[rcx+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_9ea:
	/* 0x9ea: add    rcx,0x46 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 70ULL);
x86_l_9ee:
	/* 0x9ee: jmp    eb6 <tail_lb_ipv6+0xeb6> */
	return 3766ULL;
x86_l_9f3:
	/* 0x9f3: mov    BYTE PTR [rsp+0xac],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_9fb:
	/* 0x9fb: mov    WORD PTR [rsp+0xa8],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a04:
	/* 0xa04: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_a07:
	/* 0xa07: jmp    641 <tail_lb_ipv6+0x641> */
	return 1601ULL;
x86_l_a0c:
	/* 0xa0c: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_a13:
	/* 0xa13: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_a18:
	/* 0xa18: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a1d:
	/* 0xa1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a22:
	/* 0xa22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a24:
	/* 0xa24: mov    BYTE PTR [rsp+0x2d],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_a29:
	/* 0xa29: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a2c:
	/* 0xa2c: je     b3c <tail_lb_ipv6+0xb3c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b3c;
	}
x86_l_a32:
	/* 0xa32: cmp    BYTE PTR [rax+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_a36:
	/* 0xa36: mov    WORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_a40:
	/* 0xa40: jns    fff <tail_lb_ipv6+0xfff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 4095ULL;
	}
x86_l_a46:
	/* 0xa46: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a48:
	/* 0xa48: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a4d:
	/* 0xa4d: jmp    ee8 <tail_lb_ipv6+0xee8> */
	return 3816ULL;
x86_l_a52:
	/* 0xa52: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_a57:
	/* 0xa57: jmp    53d <tail_lb_ipv6+0x53d> */
	return 1341ULL;
x86_l_a5c:
	/* 0xa5c: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_a63:
	/* 0xa63: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a68:
	/* 0xa68: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_a72:
	/* 0xa72: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_a79:
	/* 0xa79: movzx  esi,BYTE PTR [rsp+0x75] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 117ULL);
x86_l_a7e:
	/* 0xa7e: mov    BYTE PTR [rsp+0x77],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 119ULL);
x86_l_a83:
	/* 0xa83: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a88:
	/* 0xa88: mov    QWORD PTR [rsp+0xb0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_a90:
	/* 0xa90: movzx  esi,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_a94:
	/* 0xa94: mov    WORD PTR [rsp+0x2],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_a99:
	/* 0xa99: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a9e:
	/* 0xa9e: mov    QWORD PTR [rsp+0xc0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_aa6:
	/* 0xaa6: mov    BYTE PTR [rsp+0x75],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173636ULL);
x86_l_aab:
	/* 0xaab: and    r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_aae:
	/* 0xaae: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab1:
	/* 0xab1: mov    QWORD PTR [rsp+0xd0],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_ab9:
	/* 0xab9: mov    QWORD PTR [rsp+0xb8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_ac1:
	/* 0xac1: je     c67 <tail_lb_ipv6+0xc67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c67;
	}
x86_l_ac7:
	/* 0xac7: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: je     c67 <tail_lb_ipv6+0xc67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c67;
	}
x86_l_ad0:
	/* 0xad0: mov    BYTE PTR [rsp+0x4],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ad5:
	/* 0xad5: mov    rbp,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_adb:
	/* 0xadb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_ade:
	/* 0xade: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae0:
	/* 0xae0: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ae4:
	/* 0xae4: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_ae7:
	/* 0xae7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_af0:
	/* 0xaf0: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_af9:
	/* 0xaf9: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_b03:
	/* 0xb03: or     rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 256ULL);
x86_l_b09:
	/* 0xb09: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b11:
	/* 0xb11: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b18:
	/* 0xb18: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b20:
	/* 0xb20: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b25:
	/* 0xb25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b27:
	/* 0xb27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b2a:
	/* 0xb2a: je     c25 <tail_lb_ipv6+0xc25> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c25;
	}
x86_l_b30:
	/* 0xb30: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b33:
	/* 0xb33: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b37:
	/* 0xb37: jmp    c50 <tail_lb_ipv6+0xc50> */
	goto x86_l_c50;
x86_l_b3c:
	/* 0xb3c: mov    WORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_b46:
	/* 0xb46: jmp    fff <tail_lb_ipv6+0xfff> */
	return 4095ULL;
x86_l_b4b:
	/* 0xb4b: mov    r9w,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_16, 8ULL);
x86_l_b50:
	/* 0xb50: jmp    b5e <tail_lb_ipv6+0xb5e> */
	goto x86_l_b5e;
x86_l_b52:
	/* 0xb52: movzx  edi,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b56:
	/* 0xb56: lea    r9d,[rdi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 8ULL);
x86_l_b5e:
	/* 0xb5e: cmp    r8b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 60ULL);
x86_l_b62:
	/* 0xb62: ja     f3d <tail_lb_ipv6+0xf3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3901ULL;
	}
x86_l_b68:
	/* 0xb68: movzx  r11d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b6c:
	/* 0xb6c: bt     rsi,r11 */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_b70:
	/* 0xb70: jae    db5 <tail_lb_ipv6+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_db5;
	}
x86_l_b76:
	/* 0xb76: movzx  r10d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b7a:
	/* 0xb7a: lea    edi,[r10+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_b7e:
	/* 0xb7e: movzx  r9d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b82:
	/* 0xb82: lea    rdi,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_b86:
	/* 0xb86: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_b8a:
	/* 0xb8a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_b8d:
	/* 0xb8d: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_b93:
	/* 0xb93: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b96:
	/* 0xb96: movzx  edi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b9a:
	/* 0xb9a: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_b9d:
	/* 0xb9d: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ba1:
	/* 0xba1: cmp    r11d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 43ULL);
x86_l_ba5:
	/* 0xba5: jle    bc8 <tail_lb_ipv6+0xbc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_bc8;
	}
x86_l_ba7:
	/* 0xba7: cmp    r11d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 44ULL);
x86_l_bab:
	/* 0xbab: je     d4a <tail_lb_ipv6+0xd4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d4a;
	}
x86_l_bb1:
	/* 0xbb1: cmp    r11d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 51ULL);
x86_l_bb5:
	/* 0xbb5: jne    bc8 <tail_lb_ipv6+0xbc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_bc8;
	}
x86_l_bb7:
	/* 0xbb7: movzx  r8d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bbb:
	/* 0xbbb: lea    r14d,[r8*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 8ULL);
x86_l_bc3:
	/* 0xbc3: jmp    d4f <tail_lb_ipv6+0xd4f> */
	goto x86_l_d4f;
x86_l_bc8:
	/* 0xbc8: movzx  r11d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bcc:
	/* 0xbcc: lea    r14d,[r11*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 3), 8ULL);
x86_l_bd4:
	/* 0xbd4: cmp    r8b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 60ULL);
x86_l_bd8:
	/* 0xbd8: jne    d4f <tail_lb_ipv6+0xd4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d4f;
	}
x86_l_bde:
	/* 0xbde: cmp    r14w,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_16, 24ULL);
x86_l_be3:
	/* 0xbe3: jne    d4f <tail_lb_ipv6+0xd4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d4f;
	}
x86_l_be9:
	/* 0xbe9: lea    r8,[r9+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bed:
	/* 0xbed: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_bf0:
	/* 0xbf0: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_bf6:
	/* 0xbf6: mov    r11,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf9:
	/* 0xbf9: mov    r8d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R11, X86_WIDTH_32);
x86_l_bfc:
	/* 0xbfc: and    r8d,0xffff0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 4294901760ULL);
x86_l_c03:
	/* 0xc03: mov    r14w,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 24ULL);
x86_l_c08:
	/* 0xc08: cmp    r8d,0x141b0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 337313792ULL);
x86_l_c0f:
	/* 0xc0f: jne    d4f <tail_lb_ipv6+0xd4f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d4f;
	}
x86_l_c15:
	/* 0xc15: lea    rax,[r9+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c19:
	/* 0xc19: add    r9,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c1d:
	/* 0xc1d: mov    rcx,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R9, X86_WIDTH_64);
x86_l_c20:
	/* 0xc20: jmp    eb6 <tail_lb_ipv6+0xeb6> */
	return 3766ULL;
x86_l_c25:
	/* 0xc25: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_c2e:
	/* 0xc2e: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c33:
	/* 0xc33: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c3a:
	/* 0xc3a: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c42:
	/* 0xc42: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c47:
	/* 0xc47: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c4c:
	/* 0xc4c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c4e:
	/* 0xc4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c50:
	/* 0xc50: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_c53:
	/* 0xc53: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_c56:
	/* 0xc56: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_c59:
	/* 0xc59: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c61:
	/* 0xc61: movzx  r14d,BYTE PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_c67:
	/* 0xc67: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c69:
	/* 0xc69: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_c6d:
	/* 0xc6d: jne    cc5 <tail_lb_ipv6+0xcc5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cc5;
	}
x86_l_c6f:
	/* 0xc6f: mov    rcx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_c72:
	/* 0xc72: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_c78:
	/* 0xc78: and    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_c7b:
	/* 0xc7b: jne    cc8 <tail_lb_ipv6+0xcc8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_cc8;
	}
x86_l_c7d:
	/* 0xc7d: lea    edx,[r13+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_c81:
	/* 0xc81: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c83:
	/* 0xc83: mov    esi,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c86:
	/* 0xc86: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c89:
	/* 0xc89: lea    r10,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c8d:
	/* 0xc8d: add    r10,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_c91:
	/* 0xc91: cmp    r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_c94:
	/* 0xc94: ja     10d8 <tail_lb_ipv6+0x10d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 4312ULL;
	}
x86_l_c9a:
	/* 0xc9a: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c9d:
	/* 0xc9d: movzx  ebp,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ca0:
	/* 0xca0: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_ca2:
	/* 0xca2: and    ecx,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_ca8:
	/* 0xca8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cab:
	/* 0xcab: cmp    ecx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_cb1:
	/* 0xcb1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_cb4:
	/* 0xcb4: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_cba:
	/* 0xcba: jne    1c29 <tail_lb_ipv6+0x1c29> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7209ULL;
	}
x86_l_cc0:
	/* 0xcc0: mov    r12b,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_8);
x86_l_cc3:
	/* 0xcc3: jmp    cc8 <tail_lb_ipv6+0xcc8> */
	goto x86_l_cc8;
x86_l_cc5:
	/* 0xcc5: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc8:
	/* 0xcc8: mov    QWORD PTR [rsp+0x48],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ccd:
	/* 0xccd: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cd2:
	/* 0xcd2: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cd7:
	/* 0xcd7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cdc:
	/* 0xcdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cde:
	/* 0xcde: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce1:
	/* 0xce1: je     1d16 <tail_lb_ipv6+0x1d16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7446ULL;
	}
x86_l_ce7:
	/* 0xce7: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_cea:
	/* 0xcea: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_cef:
	/* 0xcef: cmp    WORD PTR [r15+0x26],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_cf4:
	/* 0xcf4: jne    1d16 <tail_lb_ipv6+0x1d16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7446ULL;
	}
x86_l_cfa:
	/* 0xcfa: test   ebp,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 512ULL);
x86_l_d00:
	/* 0xd00: mov    DWORD PTR [rsp+0xcc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_d08:
	/* 0xd08: je     11da <tail_lb_ipv6+0x11da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4570ULL;
	}
x86_l_d0e:
	/* 0xd0e: test   BYTE PTR [r15+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_d13:
	/* 0xd13: je     11da <tail_lb_ipv6+0x11da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4570ULL;
	}
x86_l_d19:
	/* 0xd19: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_d1c:
	/* 0xd1c: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d23:
	/* 0xd23: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d26:
	/* 0xd26: je     118d <tail_lb_ipv6+0x118d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4493ULL;
	}
x86_l_d2c:
	/* 0xd2c: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d33:
	/* 0xd33: mov    r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d36:
	/* 0xd36: lea    ecx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_d3a:
	/* 0xd3a: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_d3e:
	/* 0xd3e: sub    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_d41:
	/* 0xd41: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d45:
	/* 0xd45: jmp    1193 <tail_lb_ipv6+0x1193> */
	return 4499ULL;
x86_l_d4a:
	/* 0xd4a: mov    r14w,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 8ULL);
x86_l_d4f:
	/* 0xd4f: cmp    dil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 60ULL);
x86_l_d53:
	/* 0xd53: ja     f3d <tail_lb_ipv6+0xf3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 3901ULL;
	}
x86_l_d59:
	/* 0xd59: movzx  r11d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d5d:
	/* 0xd5d: bt     rsi,r11 */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_d61:
	/* 0xd61: jae    db5 <tail_lb_ipv6+0xdb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_db5;
	}
x86_l_d63:
	/* 0xd63: add    r10d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_d67:
	/* 0xd67: movzx  r9d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d6b:
	/* 0xd6b: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d6e:
	/* 0xd6e: lea    r8d,[r9+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_d72:
	/* 0xd72: movzx  r10d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d76:
	/* 0xd76: lea    r8,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_d7a:
	/* 0xd7a: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_d7e:
	/* 0xd7e: cmp    r8,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_d81:
	/* 0xd81: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_d87:
	/* 0xd87: add    r10,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d8a:
	/* 0xd8a: movzx  r8d,WORD PTR [r10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d8e:
	/* 0xd8e: mov    r14d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_32);
x86_l_d91:
	/* 0xd91: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d95:
	/* 0xd95: cmp    r11d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 43ULL);
x86_l_d99:
	/* 0xd99: jle    dc9 <tail_lb_ipv6+0xdc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_dc9;
	}
x86_l_d9b:
	/* 0xd9b: cmp    r11d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 44ULL);
x86_l_d9f:
	/* 0xd9f: je     e18 <tail_lb_ipv6+0xe18> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3608ULL;
	}
x86_l_da1:
	/* 0xda1: cmp    r11d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 51ULL);
x86_l_da5:
	/* 0xda5: jne    dc9 <tail_lb_ipv6+0xdc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_dc9;
	}
x86_l_da7:
	/* 0xda7: movzx  edi,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_dab:
	/* 0xdab: lea    r14d,[rdi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 8ULL);
x86_l_db3:
	/* 0xdb3: jmp    e1d <tail_lb_ipv6+0xe1d> */
	return 3613ULL;
x86_l_db5:
	/* 0xdb5: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_dba:
	/* 0xdba: cmp    r11,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_64, 59ULL);
x86_l_dbe:
	/* 0xdbe: je     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 175ULL;
	}
x86_l_dc4:
	/* 0xdc4: jmp    f3d <tail_lb_ipv6+0xf3d> */
	return 3901ULL;
x86_l_dc9:
	/* 0xdc9: movzx  r11d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_dcd:
	/* 0xdcd: lea    r14d,[r11*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 3), 8ULL);
x86_l_dd5:
	/* 0xdd5: cmp    dil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 60ULL);
x86_l_dd9:
	/* 0xdd9: jne    e1d <tail_lb_ipv6+0xe1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3613ULL;
	}
x86_l_ddb:
	/* 0xddb: cmp    r14w,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_16, 24ULL);
x86_l_de0:
	/* 0xde0: jne    e1d <tail_lb_ipv6+0xe1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 3613ULL;
	}
	return 3554ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3554ULL: goto x86_l_de2;
	case 3558ULL: goto x86_l_de6;
	case 3561ULL: goto x86_l_de9;
	case 3567ULL: goto x86_l_def;
	case 3570ULL: goto x86_l_df2;
	case 3573ULL: goto x86_l_df5;
	case 3579ULL: goto x86_l_dfb;
	case 3584ULL: goto x86_l_e00;
	case 3590ULL: goto x86_l_e06;
	case 3592ULL: goto x86_l_e08;
	case 3596ULL: goto x86_l_e0c;
	case 3600ULL: goto x86_l_e10;
	case 3603ULL: goto x86_l_e13;
	case 3608ULL: goto x86_l_e18;
	case 3613ULL: goto x86_l_e1d;
	case 3617ULL: goto x86_l_e21;
	case 3623ULL: goto x86_l_e27;
	case 3627ULL: goto x86_l_e2b;
	case 3631ULL: goto x86_l_e2f;
	case 3637ULL: goto x86_l_e35;
	case 3641ULL: goto x86_l_e39;
	case 3644ULL: goto x86_l_e3c;
	case 3647ULL: goto x86_l_e3f;
	case 3651ULL: goto x86_l_e43;
	case 3655ULL: goto x86_l_e47;
	case 3658ULL: goto x86_l_e4a;
	case 3664ULL: goto x86_l_e50;
	case 3667ULL: goto x86_l_e53;
	case 3677ULL: goto x86_l_e5d;
	case 3681ULL: goto x86_l_e61;
	case 3687ULL: goto x86_l_e67;
	case 3691ULL: goto x86_l_e6b;
	case 3697ULL: goto x86_l_e71;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3707ULL: goto x86_l_e7b;
	case 3712ULL: goto x86_l_e80;
	case 3718ULL: goto x86_l_e86;
	case 3722ULL: goto x86_l_e8a;
	case 3725ULL: goto x86_l_e8d;
	case 3731ULL: goto x86_l_e93;
	case 3734ULL: goto x86_l_e96;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3758ULL: goto x86_l_eae;
	case 3762ULL: goto x86_l_eb2;
	case 3766ULL: goto x86_l_eb6;
	case 3770ULL: goto x86_l_eba;
	case 3773ULL: goto x86_l_ebd;
	case 3776ULL: goto x86_l_ec0;
	case 3784ULL: goto x86_l_ec8;
	case 3792ULL: goto x86_l_ed0;
	case 3799ULL: goto x86_l_ed7;
	case 3803ULL: goto x86_l_edb;
	case 3808ULL: goto x86_l_ee0;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3836ULL: goto x86_l_efc;
	case 3841ULL: goto x86_l_f01;
	case 3846ULL: goto x86_l_f06;
	case 3851ULL: goto x86_l_f0b;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3870ULL: goto x86_l_f1e;
	case 3875ULL: goto x86_l_f23;
	case 3877ULL: goto x86_l_f25;
	case 3884ULL: goto x86_l_f2c;
	case 3886ULL: goto x86_l_f2e;
	case 3891ULL: goto x86_l_f33;
	case 3895ULL: goto x86_l_f37;
	case 3901ULL: goto x86_l_f3d;
	case 3903ULL: goto x86_l_f3f;
	case 3909ULL: goto x86_l_f45;
	case 3914ULL: goto x86_l_f4a;
	case 3920ULL: goto x86_l_f50;
	case 3927ULL: goto x86_l_f57;
	case 3932ULL: goto x86_l_f5c;
	case 3939ULL: goto x86_l_f63;
	case 3944ULL: goto x86_l_f68;
	case 3951ULL: goto x86_l_f6f;
	case 3954ULL: goto x86_l_f72;
	case 3960ULL: goto x86_l_f78;
	case 3970ULL: goto x86_l_f82;
	case 3973ULL: goto x86_l_f85;
	case 3979ULL: goto x86_l_f8b;
	case 3981ULL: goto x86_l_f8d;
	case 3985ULL: goto x86_l_f91;
	case 3994ULL: goto x86_l_f9a;
	case 3997ULL: goto x86_l_f9d;
	case 4006ULL: goto x86_l_fa6;
	case 4016ULL: goto x86_l_fb0;
	case 4024ULL: goto x86_l_fb8;
	case 4031ULL: goto x86_l_fbf;
	case 4039ULL: goto x86_l_fc7;
	case 4044ULL: goto x86_l_fcc;
	case 4046ULL: goto x86_l_fce;
	case 4049ULL: goto x86_l_fd1;
	case 4055ULL: goto x86_l_fd7;
	case 4058ULL: goto x86_l_fda;
	case 4062ULL: goto x86_l_fde;
	case 4067ULL: goto x86_l_fe3;
	case 4074ULL: goto x86_l_fea;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4086ULL: goto x86_l_ff6;
	case 4089ULL: goto x86_l_ff9;
	case 4091ULL: goto x86_l_ffb;
	case 4095ULL: goto x86_l_fff;
	case 4103ULL: goto x86_l_1007;
	case 4110ULL: goto x86_l_100e;
	case 4115ULL: goto x86_l_1013;
	case 4121ULL: goto x86_l_1019;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4129ULL: goto x86_l_1021;
	case 4136ULL: goto x86_l_1028;
	case 4144ULL: goto x86_l_1030;
	case 4151ULL: goto x86_l_1037;
	case 4156ULL: goto x86_l_103c;
	case 4159ULL: goto x86_l_103f;
	case 4162ULL: goto x86_l_1042;
	case 4164ULL: goto x86_l_1044;
	case 4170ULL: goto x86_l_104a;
	case 4177ULL: goto x86_l_1051;
	case 4183ULL: goto x86_l_1057;
	case 4188ULL: goto x86_l_105c;
	case 4191ULL: goto x86_l_105f;
	case 4196ULL: goto x86_l_1064;
	case 4198ULL: goto x86_l_1066;
	case 4203ULL: goto x86_l_106b;
	case 4208ULL: goto x86_l_1070;
	case 4217ULL: goto x86_l_1079;
	case 4222ULL: goto x86_l_107e;
	case 4229ULL: goto x86_l_1085;
	case 4237ULL: goto x86_l_108d;
	case 4242ULL: goto x86_l_1092;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	case 4251ULL: goto x86_l_109b;
	case 4259ULL: goto x86_l_10a3;
	case 4263ULL: goto x86_l_10a7;
	case 4265ULL: goto x86_l_10a9;
	case 4275ULL: goto x86_l_10b3;
	case 4281ULL: goto x86_l_10b9;
	case 4284ULL: goto x86_l_10bc;
	case 4286ULL: goto x86_l_10be;
	case 4290ULL: goto x86_l_10c2;
	case 4292ULL: goto x86_l_10c4;
	case 4295ULL: goto x86_l_10c7;
	case 4299ULL: goto x86_l_10cb;
	case 4303ULL: goto x86_l_10cf;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4317ULL: goto x86_l_10dd;
	case 4322ULL: goto x86_l_10e2;
	case 4325ULL: goto x86_l_10e5;
	case 4327ULL: goto x86_l_10e7;
	case 4330ULL: goto x86_l_10ea;
	case 4333ULL: goto x86_l_10ed;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4343ULL: goto x86_l_10f7;
	case 4348ULL: goto x86_l_10fc;
	case 4351ULL: goto x86_l_10ff;
	case 4355ULL: goto x86_l_1103;
	case 4361ULL: goto x86_l_1109;
	case 4367ULL: goto x86_l_110f;
	case 4370ULL: goto x86_l_1112;
	case 4375ULL: goto x86_l_1117;
	case 4380ULL: goto x86_l_111c;
	case 4383ULL: goto x86_l_111f;
	case 4385ULL: goto x86_l_1121;
	case 4388ULL: goto x86_l_1124;
	case 4390ULL: goto x86_l_1126;
	case 4393ULL: goto x86_l_1129;
	case 4397ULL: goto x86_l_112d;
	case 4399ULL: goto x86_l_112f;
	case 4401ULL: goto x86_l_1131;
	case 4408ULL: goto x86_l_1138;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4418ULL: goto x86_l_1142;
	case 4424ULL: goto x86_l_1148;
	case 4429ULL: goto x86_l_114d;
	case 4434ULL: goto x86_l_1152;
	case 4436ULL: goto x86_l_1154;
	case 4438ULL: goto x86_l_1156;
	case 4441ULL: goto x86_l_1159;
	case 4447ULL: goto x86_l_115f;
	case 4454ULL: goto x86_l_1166;
	case 4457ULL: goto x86_l_1169;
	case 4463ULL: goto x86_l_116f;
	case 4470ULL: goto x86_l_1176;
	case 4474ULL: goto x86_l_117a;
	case 4478ULL: goto x86_l_117e;
	case 4483ULL: goto x86_l_1183;
	case 4488ULL: goto x86_l_1188;
	case 4493ULL: goto x86_l_118d;
	case 4499ULL: goto x86_l_1193;
	case 4503ULL: goto x86_l_1197;
	case 4506ULL: goto x86_l_119a;
	case 4508ULL: goto x86_l_119c;
	case 4513ULL: goto x86_l_11a1;
	case 4515ULL: goto x86_l_11a3;
	case 4517ULL: goto x86_l_11a5;
	case 4521ULL: goto x86_l_11a9;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4530ULL: goto x86_l_11b2;
	case 4532ULL: goto x86_l_11b4;
	case 4536ULL: goto x86_l_11b8;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4554ULL: goto x86_l_11ca;
	case 4558ULL: goto x86_l_11ce;
	case 4561ULL: goto x86_l_11d1;
	case 4564ULL: goto x86_l_11d4;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4582ULL: goto x86_l_11e6;
	case 4586ULL: goto x86_l_11ea;
	case 4588ULL: goto x86_l_11ec;
	case 4590ULL: goto x86_l_11ee;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4606ULL: goto x86_l_11fe;
	case 4610ULL: goto x86_l_1202;
	case 4612ULL: goto x86_l_1204;
	case 4619ULL: goto x86_l_120b;
	case 4623ULL: goto x86_l_120f;
	case 4627ULL: goto x86_l_1213;
	case 4629ULL: goto x86_l_1215;
	case 4635ULL: goto x86_l_121b;
	case 4640ULL: goto x86_l_1220;
	case 4642ULL: goto x86_l_1222;
	case 4649ULL: goto x86_l_1229;
	case 4651ULL: goto x86_l_122b;
	case 4654ULL: goto x86_l_122e;
	case 4657ULL: goto x86_l_1231;
	case 4659ULL: goto x86_l_1233;
	case 4664ULL: goto x86_l_1238;
	case 4666ULL: goto x86_l_123a;
	case 4671ULL: goto x86_l_123f;
	case 4677ULL: goto x86_l_1245;
	case 4681ULL: goto x86_l_1249;
	case 4685ULL: goto x86_l_124d;
	case 4687ULL: goto x86_l_124f;
	case 4694ULL: goto x86_l_1256;
	case 4698ULL: goto x86_l_125a;
	case 4702ULL: goto x86_l_125e;
	case 4711ULL: goto x86_l_1267;
	case 4715ULL: goto x86_l_126b;
	case 4719ULL: goto x86_l_126f;
	case 4721ULL: goto x86_l_1271;
	case 4726ULL: goto x86_l_1276;
	case 4728ULL: goto x86_l_1278;
	case 4730ULL: goto x86_l_127a;
	case 4734ULL: goto x86_l_127e;
	case 4736ULL: goto x86_l_1280;
	case 4741ULL: goto x86_l_1285;
	case 4743ULL: goto x86_l_1287;
	case 4745ULL: goto x86_l_1289;
	case 4749ULL: goto x86_l_128d;
	case 4759ULL: goto x86_l_1297;
	case 4762ULL: goto x86_l_129a;
	case 4767ULL: goto x86_l_129f;
	case 4771ULL: goto x86_l_12a3;
	case 4774ULL: goto x86_l_12a6;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4787ULL: goto x86_l_12b3;
	case 4791ULL: goto x86_l_12b7;
	case 4795ULL: goto x86_l_12bb;
	case 4797ULL: goto x86_l_12bd;
	case 4804ULL: goto x86_l_12c4;
	case 4806ULL: goto x86_l_12c6;
	case 4809ULL: goto x86_l_12c9;
	case 4812ULL: goto x86_l_12cc;
	case 4814ULL: goto x86_l_12ce;
	case 4819ULL: goto x86_l_12d3;
	case 4821ULL: goto x86_l_12d5;
	case 4824ULL: goto x86_l_12d8;
	case 4826ULL: goto x86_l_12da;
	case 4828ULL: goto x86_l_12dc;
	case 4831ULL: goto x86_l_12df;
	case 4833ULL: goto x86_l_12e1;
	case 4837ULL: goto x86_l_12e5;
	case 4841ULL: goto x86_l_12e9;
	case 4848ULL: goto x86_l_12f0;
	case 4850ULL: goto x86_l_12f2;
	case 4857ULL: goto x86_l_12f9;
	case 4860ULL: goto x86_l_12fc;
	case 4862ULL: goto x86_l_12fe;
	case 4867ULL: goto x86_l_1303;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4887ULL: goto x86_l_1317;
	case 4890ULL: goto x86_l_131a;
	case 4892ULL: goto x86_l_131c;
	case 4895ULL: goto x86_l_131f;
	case 4901ULL: goto x86_l_1325;
	case 4906ULL: goto x86_l_132a;
	case 4908ULL: goto x86_l_132c;
	case 4914ULL: goto x86_l_1332;
	case 4921ULL: goto x86_l_1339;
	case 4926ULL: goto x86_l_133e;
	case 4931ULL: goto x86_l_1343;
	case 4938ULL: goto x86_l_134a;
	case 4942ULL: goto x86_l_134e;
	case 4948ULL: goto x86_l_1354;
	case 4955ULL: goto x86_l_135b;
	case 4959ULL: goto x86_l_135f;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4980ULL: goto x86_l_1374;
	case 4982ULL: goto x86_l_1376;
	case 4989ULL: goto x86_l_137d;
	case 4994ULL: goto x86_l_1382;
	case 5000ULL: goto x86_l_1388;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5011ULL: goto x86_l_1393;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5024ULL: goto x86_l_13a0;
	case 5030ULL: goto x86_l_13a6;
	case 5034ULL: goto x86_l_13aa;
	case 5036ULL: goto x86_l_13ac;
	case 5040ULL: goto x86_l_13b0;
	case 5042ULL: goto x86_l_13b2;
	case 5045ULL: goto x86_l_13b5;
	case 5048ULL: goto x86_l_13b8;
	case 5050ULL: goto x86_l_13ba;
	case 5055ULL: goto x86_l_13bf;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5068ULL: goto x86_l_13cc;
	case 5072ULL: goto x86_l_13d0;
	case 5079ULL: goto x86_l_13d7;
	case 5082ULL: goto x86_l_13da;
	case 5084ULL: goto x86_l_13dc;
	case 5091ULL: goto x86_l_13e3;
	case 5095ULL: goto x86_l_13e7;
	case 5099ULL: goto x86_l_13eb;
	case 5105ULL: goto x86_l_13f1;
	case 5109ULL: goto x86_l_13f5;
	case 5116ULL: goto x86_l_13fc;
	case 5119ULL: goto x86_l_13ff;
	case 5121ULL: goto x86_l_1401;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5130ULL: goto x86_l_140a;
	case 5134ULL: goto x86_l_140e;
	case 5136ULL: goto x86_l_1410;
	case 5141ULL: goto x86_l_1415;
	case 5143ULL: goto x86_l_1417;
	case 5145ULL: goto x86_l_1419;
	case 5149ULL: goto x86_l_141d;
	case 5159ULL: goto x86_l_1427;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5171ULL: goto x86_l_1433;
	case 5174ULL: goto x86_l_1436;
	case 5178ULL: goto x86_l_143a;
	case 5183ULL: goto x86_l_143f;
	case 5187ULL: goto x86_l_1443;
	case 5191ULL: goto x86_l_1447;
	case 5198ULL: goto x86_l_144e;
	case 5201ULL: goto x86_l_1451;
	case 5203ULL: goto x86_l_1453;
	case 5210ULL: goto x86_l_145a;
	case 5212ULL: goto x86_l_145c;
	case 5215ULL: goto x86_l_145f;
	case 5218ULL: goto x86_l_1462;
	case 5220ULL: goto x86_l_1464;
	default: return 0xffffffffffffffffULL;
	}
x86_l_de2:
	/* 0xde2: lea    rdi,[r10+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_de6:
	/* 0xde6: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_de9:
	/* 0xde9: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_def:
	/* 0xdef: mov    r11,QWORD PTR [r10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df2:
	/* 0xdf2: mov    edi,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R11, X86_WIDTH_32);
x86_l_df5:
	/* 0xdf5: and    edi,0xffff0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 4294901760ULL);
x86_l_dfb:
	/* 0xdfb: mov    r14w,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 24ULL);
x86_l_e00:
	/* 0xe00: cmp    edi,0x141b0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 337313792ULL);
x86_l_e06:
	/* 0xe06: jne    e1d <tail_lb_ipv6+0xe1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e1d;
	}
x86_l_e08:
	/* 0xe08: lea    rax,[r10+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0c:
	/* 0xe0c: add    r10,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e10:
	/* 0xe10: mov    rcx,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R10, X86_WIDTH_64);
x86_l_e13:
	/* 0xe13: jmp    eb6 <tail_lb_ipv6+0xeb6> */
	goto x86_l_eb6;
x86_l_e18:
	/* 0xe18: mov    r14w,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 8ULL);
x86_l_e1d:
	/* 0xe1d: cmp    r8b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 60ULL);
x86_l_e21:
	/* 0xe21: ja     f3d <tail_lb_ipv6+0xf3d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f3d;
	}
x86_l_e27:
	/* 0xe27: movzx  edi,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e2b:
	/* 0xe2b: bt     rsi,rdi */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_e2f:
	/* 0xe2f: jae    f2e <tail_lb_ipv6+0xf2e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_f2e;
	}
x86_l_e35:
	/* 0xe35: lea    eax,[r9+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_e39:
	/* 0xe39: add    eax,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_e3c:
	/* 0xe3c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e3f:
	/* 0xe3f: lea    rsi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_e43:
	/* 0xe43: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_e47:
	/* 0xe47: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e4a:
	/* 0xe4a: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_e50:
	/* 0xe50: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e53:
	/* 0xe53: movabs rax,0x1000080000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1152930300699869185ULL);
x86_l_e5d:
	/* 0xe5d: bt     rax,rdi */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RDI, X86_WIDTH_64);
x86_l_e61:
	/* 0xe61: jae    1183 <tail_lb_ipv6+0x1183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1183;
	}
x86_l_e67:
	/* 0xe67: cmp    r8b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 60ULL);
x86_l_e6b:
	/* 0xe6b: jne    1183 <tail_lb_ipv6+0x1183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1183;
	}
x86_l_e71:
	/* 0xe71: movzx  eax,BYTE PTR [rcx+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_e75:
	/* 0xe75: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_e78:
	/* 0xe78: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e7b:
	/* 0xe7b: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_e80:
	/* 0xe80: jne    1183 <tail_lb_ipv6+0x1183> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1183;
	}
x86_l_e86:
	/* 0xe86: lea    rax,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e8a:
	/* 0xe8a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_e8d:
	/* 0xe8d: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_e93:
	/* 0xe93: mov    r11,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e96:
	/* 0xe96: mov    eax,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R11, X86_WIDTH_32);
x86_l_e99:
	/* 0xe99: and    eax,0xffff0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294901760ULL);
x86_l_e9e:
	/* 0xe9e: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_ea3:
	/* 0xea3: cmp    eax,0x141b0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 337313792ULL);
x86_l_ea8:
	/* 0xea8: jne    af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 175ULL;
	}
x86_l_eae:
	/* 0xeae: lea    rax,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_eb2:
	/* 0xeb2: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_eb6:
	/* 0xeb6: shr    r11,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_eba:
	/* 0xeba: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ebd:
	/* 0xebd: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec0:
	/* 0xec0: mov    DWORD PTR [rsp+0x98],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ec8:
	/* 0xec8: mov    QWORD PTR [rsp+0x9c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_ed0:
	/* 0xed0: mov    DWORD PTR [rsp+0xa4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_ed7:
	/* 0xed7: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_edb:
	/* 0xedb: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ee0:
	/* 0xee0: mov    WORD PTR [rsp+0xa8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ee8:
	/* 0xee8: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_eed:
	/* 0xeed: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ef2:
	/* 0xef2: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ef7:
	/* 0xef7: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_efc:
	/* 0xefc: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f01:
	/* 0xf01: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f06:
	/* 0xf06: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f0b:
	/* 0xf0b: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f10:
	/* 0xf10: rol    DWORD PTR [rsp+0x70],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 481036337168ULL);
x86_l_f15:
	/* 0xf15: movzx  ebp,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_f1a:
	/* 0xf1a: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_f1e:
	/* 0xf1e: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f23:
	/* 0xf23: jne    f5c <tail_lb_ipv6+0xf5c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f5c;
	}
x86_l_f25:
	/* 0xf25: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_f2c:
	/* 0xf2c: jmp    f63 <tail_lb_ipv6+0xf63> */
	goto x86_l_f63;
x86_l_f2e:
	/* 0xf2e: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_f33:
	/* 0xf33: cmp    rdi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_64, 59ULL);
x86_l_f37:
	/* 0xf37: je     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 175ULL;
	}
x86_l_f3d:
	/* 0xf3d: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_f3f:
	/* 0xf3f: jne    fff <tail_lb_ipv6+0xfff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fff;
	}
x86_l_f45:
	/* 0xf45: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_f4a:
	/* 0xf4a: jne    fe3 <tail_lb_ipv6+0xfe3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_fe3;
	}
x86_l_f50:
	/* 0xf50: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_f57:
	/* 0xf57: jmp    fea <tail_lb_ipv6+0xfea> */
	goto x86_l_fea;
x86_l_f5c:
	/* 0xf5c: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_f63:
	/* 0xf63: mov    BYTE PTR [rsp+0x75],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_f68:
	/* 0xf68: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_f6f:
	/* 0xf6f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f72:
	/* 0xf72: je     109b <tail_lb_ipv6+0x109b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_109b;
	}
x86_l_f78:
	/* 0xf78: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_f82:
	/* 0xf82: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_f85:
	/* 0xf85: je     109b <tail_lb_ipv6+0x109b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_109b;
	}
x86_l_f8b:
	/* 0xf8b: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8d:
	/* 0xf8d: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f91:
	/* 0xf91: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f9a:
	/* 0xf9a: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_f9d:
	/* 0xf9d: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fa6:
	/* 0xfa6: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_fb0:
	/* 0xfb0: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fb8:
	/* 0xfb8: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_fbf:
	/* 0xfbf: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fc7:
	/* 0xfc7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fcc:
	/* 0xfcc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fce:
	/* 0xfce: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd1:
	/* 0xfd1: je     1070 <tail_lb_ipv6+0x1070> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1070;
	}
x86_l_fd7:
	/* 0xfd7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_fda:
	/* 0xfda: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fde:
	/* 0xfde: jmp    109b <tail_lb_ipv6+0x109b> */
	goto x86_l_109b;
x86_l_fe3:
	/* 0xfe3: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_fea:
	/* 0xfea: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fef:
	/* 0xfef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff4:
	/* 0xff4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff6:
	/* 0xff6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ff9:
	/* 0xff9: je     fff <tail_lb_ipv6+0xfff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_fff;
	}
x86_l_ffb:
	/* 0xffb: and    BYTE PTR [rax+0x24],0x7f */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 154618822783ULL);
x86_l_fff:
	/* 0xfff: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1007:
	/* 0x1007: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_100e:
	/* 0x100e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1013:
	/* 0x1013: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1019:
	/* 0x1019: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_101c:
	/* 0x101c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_101f:
	/* 0x101f: je     1028 <tail_lb_ipv6+0x1028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1028;
	}
x86_l_1021:
	/* 0x1021: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1028:
	/* 0x1028: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1030:
	/* 0x1030: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1037:
	/* 0x1037: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103c:
	/* 0x103c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_103f:
	/* 0x103f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1042:
	/* 0x1042: je     104a <tail_lb_ipv6+0x104a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_104a;
	}
x86_l_1044:
	/* 0x1044: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104a:
	/* 0x104a: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1051:
	/* 0x1051: mov    r15d,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 37ULL);
x86_l_1057:
	/* 0x1057: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_105c:
	/* 0x105c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_105f:
	/* 0x105f: mov    edx,0x25 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 37ULL);
x86_l_1064:
	/* 0x1064: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1066:
	/* 0x1066: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_106b:
	/* 0x106b: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	return 1012ULL;
x86_l_1070:
	/* 0x1070: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1079:
	/* 0x1079: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_107e:
	/* 0x107e: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1085:
	/* 0x1085: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_108d:
	/* 0x108d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1092:
	/* 0x1092: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1097:
	/* 0x1097: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1099:
	/* 0x1099: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109b:
	/* 0x109b: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_10a3:
	/* 0x10a3: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_10a7:
	/* 0x10a7: jne    10e2 <tail_lb_ipv6+0x10e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10e2;
	}
x86_l_10a9:
	/* 0x10a9: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_10b3:
	/* 0x10b3: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_10b9:
	/* 0x10b9: and    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_AND);
x86_l_10bc:
	/* 0x10bc: jne    1112 <tail_lb_ipv6+0x1112> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1112;
	}
x86_l_10be:
	/* 0x10be: add    r13d,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 26ULL);
x86_l_10c2:
	/* 0x10c2: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c4:
	/* 0x10c4: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10c7:
	/* 0x10c7: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_10cb:
	/* 0x10cb: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_10cf:
	/* 0x10cf: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_10d3:
	/* 0x10d3: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_10d6:
	/* 0x10d6: jbe    10e7 <tail_lb_ipv6+0x10e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_10e7;
	}
x86_l_10d8:
	/* 0x10d8: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_10dd:
	/* 0x10dd: jmp    af <tail_lb_ipv6+0xaf> */
	return 175ULL;
x86_l_10e2:
	/* 0x10e2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e5:
	/* 0x10e5: jmp    1112 <tail_lb_ipv6+0x1112> */
	goto x86_l_1112;
x86_l_10e7:
	/* 0x10e7: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_10ea:
	/* 0x10ea: movzx  ecx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10ed:
	/* 0x10ed: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_10ef:
	/* 0x10ef: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_10f4:
	/* 0x10f4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10f7:
	/* 0x10f7: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_10fc:
	/* 0x10fc: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_10ff:
	/* 0x10ff: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1103:
	/* 0x1103: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_1109:
	/* 0x1109: jne    1c34 <tail_lb_ipv6+0x1c34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7220ULL;
	}
x86_l_110f:
	/* 0x110f: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_1112:
	/* 0x1112: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1117:
	/* 0x1117: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111c:
	/* 0x111c: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_111f:
	/* 0x111f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1121:
	/* 0x1121: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1124:
	/* 0x1124: je     1131 <tail_lb_ipv6+0x1131> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1131;
	}
x86_l_1126:
	/* 0x1126: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1129:
	/* 0x1129: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_112d:
	/* 0x112d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_112f:
	/* 0x112f: js     1152 <tail_lb_ipv6+0x1152> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1152;
	}
x86_l_1131:
	/* 0x1131: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1138:
	/* 0x1138: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113a:
	/* 0x113a: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_113f:
	/* 0x113f: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1142:
	/* 0x1142: je     aa <tail_lb_ipv6+0xaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 170ULL;
	}
x86_l_1148:
	/* 0x1148: movzx  ebp,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_114d:
	/* 0x114d: jmp    19bf <tail_lb_ipv6+0x19bf> */
	return 6591ULL;
x86_l_1152:
	/* 0x1152: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1154:
	/* 0x1154: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1156:
	/* 0x1156: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1159:
	/* 0x1159: je     1488 <tail_lb_ipv6+0x1488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5256ULL;
	}
x86_l_115f:
	/* 0x115f: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1166:
	/* 0x1166: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1169:
	/* 0x1169: je     13a0 <tail_lb_ipv6+0x13a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13a0;
	}
x86_l_116f:
	/* 0x116f: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1176:
	/* 0x1176: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_117a:
	/* 0x117a: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_117e:
	/* 0x117e: jmp    13a6 <tail_lb_ipv6+0x13a6> */
	goto x86_l_13a6;
x86_l_1183:
	/* 0x1183: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_1188:
	/* 0x1188: jmp    af <tail_lb_ipv6+0xaf> */
	return 175ULL;
x86_l_118d:
	/* 0x118d: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_1193:
	/* 0x1193: add    r14d,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1197:
	/* 0x1197: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119a:
	/* 0x119a: je     11ab <tail_lb_ipv6+0x11ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11ab;
	}
x86_l_119c:
	/* 0x119c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_11a1:
	/* 0x11a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a3:
	/* 0x11a3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11a5:
	/* 0x11a5: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_11a9:
	/* 0x11a9: jmp    11ce <tail_lb_ipv6+0x11ce> */
	goto x86_l_11ce;
x86_l_11ab:
	/* 0x11ab: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_11b0:
	/* 0x11b0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b2:
	/* 0x11b2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11b4:
	/* 0x11b4: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_11b8:
	/* 0x11b8: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_11c2:
	/* 0x11c2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_11c5:
	/* 0x11c5: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11ca:
	/* 0x11ca: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_11ce:
	/* 0x11ce: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_11d1:
	/* 0x11d1: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_11d4:
	/* 0x11d4: jae    1d16 <tail_lb_ipv6+0x1d16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7446ULL;
	}
x86_l_11da:
	/* 0x11da: mov    BYTE PTR [rsp+0x4],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11df:
	/* 0x11df: mov    DWORD PTR [rsp+0x84],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_11e6:
	/* 0x11e6: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11ea:
	/* 0x11ea: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_11ec:
	/* 0x11ec: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11ee:
	/* 0x11ee: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_11f1:
	/* 0x11f1: je     12f2 <tail_lb_ipv6+0x12f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f2;
	}
x86_l_11f7:
	/* 0x11f7: mov    rbp,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11fe:
	/* 0x11fe: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1202:
	/* 0x1202: je     1215 <tail_lb_ipv6+0x1215> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1215;
	}
x86_l_1204:
	/* 0x1204: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_120b:
	/* 0x120b: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_120f:
	/* 0x120f: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1213:
	/* 0x1213: jmp    121b <tail_lb_ipv6+0x121b> */
	goto x86_l_121b;
x86_l_1215:
	/* 0x1215: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_121b:
	/* 0x121b: cmp    BYTE PTR [rsp+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_1220:
	/* 0x1220: jne    125e <tail_lb_ipv6+0x125e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_125e;
	}
x86_l_1222:
	/* 0x1222: mov    ecx,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1229:
	/* 0x1229: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_122b:
	/* 0x122b: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_122e:
	/* 0x122e: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1231:
	/* 0x1231: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1233:
	/* 0x1233: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1238:
	/* 0x1238: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_123a:
	/* 0x123a: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_123f:
	/* 0x123f: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_1245:
	/* 0x1245: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1249:
	/* 0x1249: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124d:
	/* 0x124d: je     125e <tail_lb_ipv6+0x125e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_125e;
	}
x86_l_124f:
	/* 0x124f: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1256:
	/* 0x1256: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_125a:
	/* 0x125a: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_125e:
	/* 0x125e: movzx  r12d,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_1267:
	/* 0x1267: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_126b:
	/* 0x126b: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_126f:
	/* 0x126f: je     1280 <tail_lb_ipv6+0x1280> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1280;
	}
x86_l_1271:
	/* 0x1271: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1276:
	/* 0x1276: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1278:
	/* 0x1278: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_127a:
	/* 0x127a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_127e:
	/* 0x127e: jmp    12a3 <tail_lb_ipv6+0x12a3> */
	goto x86_l_12a3;
x86_l_1280:
	/* 0x1280: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1285:
	/* 0x1285: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1287:
	/* 0x1287: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1289:
	/* 0x1289: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_128d:
	/* 0x128d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1297:
	/* 0x1297: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_129a:
	/* 0x129a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_129f:
	/* 0x129f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_12a3:
	/* 0x12a3: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12a6:
	/* 0x12a6: mov    DWORD PTR [r15+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12aa:
	/* 0x12aa: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_12af:
	/* 0x12af: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b3:
	/* 0x12b3: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_12b7:
	/* 0x12b7: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12bb:
	/* 0x12bb: je     12ce <tail_lb_ipv6+0x12ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12ce;
	}
x86_l_12bd:
	/* 0x12bd: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_12c4:
	/* 0x12c4: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c6:
	/* 0x12c6: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_12c9:
	/* 0x12c9: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12cc:
	/* 0x12cc: jmp    12d3 <tail_lb_ipv6+0x12d3> */
	goto x86_l_12d3;
x86_l_12ce:
	/* 0x12ce: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_12d3:
	/* 0x12d3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12d5:
	/* 0x12d5: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12d8:
	/* 0x12d8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_12da:
	/* 0x12da: jb     12e1 <tail_lb_ipv6+0x12e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_12e1;
	}
x86_l_12dc:
	/* 0x12dc: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_12df:
	/* 0x12df: je     12f2 <tail_lb_ipv6+0x12f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_12f2;
	}
x86_l_12e1:
	/* 0x12e1: mov    BYTE PTR [r15+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_12e5:
	/* 0x12e5: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12e9:
	/* 0x12e9: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_12f0:
	/* 0x12f0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12f2:
	/* 0x12f2: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_12f9:
	/* 0x12f9: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12fc:
	/* 0x12fc: je     1310 <tail_lb_ipv6+0x1310> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1310;
	}
x86_l_12fe:
	/* 0x12fe: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1303:
	/* 0x1303: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1305:
	/* 0x1305: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1308:
	/* 0x1308: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_130b:
	/* 0x130b: add QWORD PTR [r15+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1310:
	/* 0x1310: mov    eax,DWORD PTR [rsp+0xcc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1317:
	/* 0x1317: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_131a:
	/* 0x131a: je     1368 <tail_lb_ipv6+0x1368> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1368;
	}
x86_l_131c:
	/* 0x131c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_131f:
	/* 0x131f: jne    15ee <tail_lb_ipv6+0x15ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5614ULL;
	}
x86_l_1325:
	/* 0x1325: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_132a:
	/* 0x132a: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_132c:
	/* 0x132c: je     15ee <tail_lb_ipv6+0x15ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5614ULL;
	}
x86_l_1332:
	/* 0x1332: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1339:
	/* 0x1339: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_133e:
	/* 0x133e: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1343:
	/* 0x1343: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_134a:
	/* 0x134a: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_134e:
	/* 0x134e: je     1c3f <tail_lb_ipv6+0x1c3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7231ULL;
	}
x86_l_1354:
	/* 0x1354: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_135b:
	/* 0x135b: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_135f:
	/* 0x135f: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1363:
	/* 0x1363: jmp    1c45 <tail_lb_ipv6+0x1c45> */
	return 7237ULL;
x86_l_1368:
	/* 0x1368: or     BYTE PTR [r15+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R15, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_136d:
	/* 0x136d: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1374:
	/* 0x1374: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1376:
	/* 0x1376: mov    r12,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_137d:
	/* 0x137d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1382:
	/* 0x1382: je     1554 <tail_lb_ipv6+0x1554> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5460ULL;
	}
x86_l_1388:
	/* 0x1388: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_138f:
	/* 0x138f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1391:
	/* 0x1391: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1393:
	/* 0x1393: lea    r14d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1397:
	/* 0x1397: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_139b:
	/* 0x139b: jmp    155a <tail_lb_ipv6+0x155a> */
	return 5466ULL;
x86_l_13a0:
	/* 0x13a0: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_13a6:
	/* 0x13a6: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_13aa:
	/* 0x13aa: jne    13eb <tail_lb_ipv6+0x13eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13eb;
	}
x86_l_13ac:
	/* 0x13ac: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13b0:
	/* 0x13b0: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_13b2:
	/* 0x13b2: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_13b5:
	/* 0x13b5: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_13b8:
	/* 0x13b8: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_13ba:
	/* 0x13ba: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13bf:
	/* 0x13bf: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_13c1:
	/* 0x13c1: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_13c6:
	/* 0x13c6: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_13cc:
	/* 0x13cc: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_13d0:
	/* 0x13d0: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_13d7:
	/* 0x13d7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13da:
	/* 0x13da: je     13eb <tail_lb_ipv6+0x13eb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_13eb;
	}
x86_l_13dc:
	/* 0x13dc: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_13e3:
	/* 0x13e3: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_13e7:
	/* 0x13e7: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13eb:
	/* 0x13eb: movzx  r13d,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_13f1:
	/* 0x13f1: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13f5:
	/* 0x13f5: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_13fc:
	/* 0x13fc: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ff:
	/* 0x13ff: je     1410 <tail_lb_ipv6+0x1410> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1410;
	}
x86_l_1401:
	/* 0x1401: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1406:
	/* 0x1406: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1408:
	/* 0x1408: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_140a:
	/* 0x140a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_140e:
	/* 0x140e: jmp    1433 <tail_lb_ipv6+0x1433> */
	goto x86_l_1433;
x86_l_1410:
	/* 0x1410: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1415:
	/* 0x1415: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1417:
	/* 0x1417: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1419:
	/* 0x1419: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_141d:
	/* 0x141d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1427:
	/* 0x1427: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_142a:
	/* 0x142a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_142f:
	/* 0x142f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1433:
	/* 0x1433: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1436:
	/* 0x1436: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_143a:
	/* 0x143a: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_143f:
	/* 0x143f: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1443:
	/* 0x1443: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1447:
	/* 0x1447: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_144e:
	/* 0x144e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1451:
	/* 0x1451: je     1464 <tail_lb_ipv6+0x1464> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1464;
	}
x86_l_1453:
	/* 0x1453: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_145a:
	/* 0x145a: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_145c:
	/* 0x145c: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_145f:
	/* 0x145f: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1462:
	/* 0x1462: jmp    1469 <tail_lb_ipv6+0x1469> */
	return 5225ULL;
x86_l_1464:
	/* 0x1464: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
	return 5225ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5225ULL: goto x86_l_1469;
	case 5227ULL: goto x86_l_146b;
	case 5230ULL: goto x86_l_146e;
	case 5232ULL: goto x86_l_1470;
	case 5234ULL: goto x86_l_1472;
	case 5237ULL: goto x86_l_1475;
	case 5239ULL: goto x86_l_1477;
	case 5243ULL: goto x86_l_147b;
	case 5247ULL: goto x86_l_147f;
	case 5254ULL: goto x86_l_1486;
	case 5256ULL: goto x86_l_1488;
	case 5263ULL: goto x86_l_148f;
	case 5266ULL: goto x86_l_1492;
	case 5268ULL: goto x86_l_1494;
	case 5273ULL: goto x86_l_1499;
	case 5275ULL: goto x86_l_149b;
	case 5278ULL: goto x86_l_149e;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5290ULL: goto x86_l_14aa;
	case 5292ULL: goto x86_l_14ac;
	case 5296ULL: goto x86_l_14b0;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5315ULL: goto x86_l_14c3;
	case 5322ULL: goto x86_l_14ca;
	case 5327ULL: goto x86_l_14cf;
	case 5332ULL: goto x86_l_14d4;
	case 5339ULL: goto x86_l_14db;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5356ULL: goto x86_l_14ec;
	case 5360ULL: goto x86_l_14f0;
	case 5364ULL: goto x86_l_14f4;
	case 5369ULL: goto x86_l_14f9;
	case 5373ULL: goto x86_l_14fd;
	case 5378ULL: goto x86_l_1502;
	case 5382ULL: goto x86_l_1506;
	case 5386ULL: goto x86_l_150a;
	case 5390ULL: goto x86_l_150e;
	case 5395ULL: goto x86_l_1513;
	case 5400ULL: goto x86_l_1518;
	case 5407ULL: goto x86_l_151f;
	case 5410ULL: goto x86_l_1522;
	case 5412ULL: goto x86_l_1524;
	case 5418ULL: goto x86_l_152a;
	case 5425ULL: goto x86_l_1531;
	case 5430ULL: goto x86_l_1536;
	case 5436ULL: goto x86_l_153c;
	case 5443ULL: goto x86_l_1543;
	case 5445ULL: goto x86_l_1545;
	case 5447ULL: goto x86_l_1547;
	case 5451ULL: goto x86_l_154b;
	case 5455ULL: goto x86_l_154f;
	case 5460ULL: goto x86_l_1554;
	case 5466ULL: goto x86_l_155a;
	case 5474ULL: goto x86_l_1562;
	case 5477ULL: goto x86_l_1565;
	case 5482ULL: goto x86_l_156a;
	case 5484ULL: goto x86_l_156c;
	case 5489ULL: goto x86_l_1571;
	case 5491ULL: goto x86_l_1573;
	case 5493ULL: goto x86_l_1575;
	case 5497ULL: goto x86_l_1579;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5506ULL: goto x86_l_1582;
	case 5508ULL: goto x86_l_1584;
	case 5512ULL: goto x86_l_1588;
	case 5522ULL: goto x86_l_1592;
	case 5525ULL: goto x86_l_1595;
	case 5530ULL: goto x86_l_159a;
	case 5534ULL: goto x86_l_159e;
	case 5537ULL: goto x86_l_15a1;
	case 5541ULL: goto x86_l_15a5;
	case 5546ULL: goto x86_l_15aa;
	case 5550ULL: goto x86_l_15ae;
	case 5554ULL: goto x86_l_15b2;
	case 5559ULL: goto x86_l_15b7;
	case 5561ULL: goto x86_l_15b9;
	case 5568ULL: goto x86_l_15c0;
	case 5570ULL: goto x86_l_15c2;
	case 5573ULL: goto x86_l_15c5;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5583ULL: goto x86_l_15cf;
	case 5585ULL: goto x86_l_15d1;
	case 5588ULL: goto x86_l_15d4;
	case 5590ULL: goto x86_l_15d6;
	case 5592ULL: goto x86_l_15d8;
	case 5595ULL: goto x86_l_15db;
	case 5597ULL: goto x86_l_15dd;
	case 5601ULL: goto x86_l_15e1;
	case 5605ULL: goto x86_l_15e5;
	case 5612ULL: goto x86_l_15ec;
	case 5614ULL: goto x86_l_15ee;
	case 5619ULL: goto x86_l_15f3;
	case 5621ULL: goto x86_l_15f5;
	case 5626ULL: goto x86_l_15fa;
	case 5631ULL: goto x86_l_15ff;
	case 5635ULL: goto x86_l_1603;
	case 5639ULL: goto x86_l_1607;
	case 5643ULL: goto x86_l_160b;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5660ULL: goto x86_l_161c;
	case 5662ULL: goto x86_l_161e;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	case 5670ULL: goto x86_l_1626;
	case 5674ULL: goto x86_l_162a;
	case 5680ULL: goto x86_l_1630;
	case 5691ULL: goto x86_l_163b;
	case 5693ULL: goto x86_l_163d;
	case 5698ULL: goto x86_l_1642;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5715ULL: goto x86_l_1653;
	case 5718ULL: goto x86_l_1656;
	case 5723ULL: goto x86_l_165b;
	case 5728ULL: goto x86_l_1660;
	case 5734ULL: goto x86_l_1666;
	case 5738ULL: goto x86_l_166a;
	case 5741ULL: goto x86_l_166d;
	case 5746ULL: goto x86_l_1672;
	case 5752ULL: goto x86_l_1678;
	case 5757ULL: goto x86_l_167d;
	case 5762ULL: goto x86_l_1682;
	case 5768ULL: goto x86_l_1688;
	case 5774ULL: goto x86_l_168e;
	case 5782ULL: goto x86_l_1696;
	case 5786ULL: goto x86_l_169a;
	case 5793ULL: goto x86_l_16a1;
	case 5800ULL: goto x86_l_16a8;
	case 5808ULL: goto x86_l_16b0;
	case 5813ULL: goto x86_l_16b5;
	case 5815ULL: goto x86_l_16b7;
	case 5823ULL: goto x86_l_16bf;
	case 5826ULL: goto x86_l_16c2;
	case 5832ULL: goto x86_l_16c8;
	case 5837ULL: goto x86_l_16cd;
	case 5840ULL: goto x86_l_16d0;
	case 5842ULL: goto x86_l_16d2;
	case 5845ULL: goto x86_l_16d5;
	case 5851ULL: goto x86_l_16db;
	case 5855ULL: goto x86_l_16df;
	case 5859ULL: goto x86_l_16e3;
	case 5863ULL: goto x86_l_16e7;
	case 5865ULL: goto x86_l_16e9;
	case 5871ULL: goto x86_l_16ef;
	case 5873ULL: goto x86_l_16f1;
	case 5875ULL: goto x86_l_16f3;
	case 5877ULL: goto x86_l_16f5;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5887ULL: goto x86_l_16ff;
	case 5889ULL: goto x86_l_1701;
	case 5895ULL: goto x86_l_1707;
	case 5897ULL: goto x86_l_1709;
	case 5899ULL: goto x86_l_170b;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5913ULL: goto x86_l_1719;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5923ULL: goto x86_l_1723;
	case 5925ULL: goto x86_l_1725;
	case 5931ULL: goto x86_l_172b;
	case 5933ULL: goto x86_l_172d;
	case 5937ULL: goto x86_l_1731;
	case 5939ULL: goto x86_l_1733;
	case 5943ULL: goto x86_l_1737;
	case 5946ULL: goto x86_l_173a;
	case 5950ULL: goto x86_l_173e;
	case 5954ULL: goto x86_l_1742;
	case 5957ULL: goto x86_l_1745;
	case 5960ULL: goto x86_l_1748;
	case 5963ULL: goto x86_l_174b;
	case 5968ULL: goto x86_l_1750;
	case 5970ULL: goto x86_l_1752;
	case 5972ULL: goto x86_l_1754;
	case 5978ULL: goto x86_l_175a;
	case 5980ULL: goto x86_l_175c;
	case 5983ULL: goto x86_l_175f;
	case 5986ULL: goto x86_l_1762;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5997ULL: goto x86_l_176d;
	case 5999ULL: goto x86_l_176f;
	case 6005ULL: goto x86_l_1775;
	case 6008ULL: goto x86_l_1778;
	case 6010ULL: goto x86_l_177a;
	case 6013ULL: goto x86_l_177d;
	case 6019ULL: goto x86_l_1783;
	case 6021ULL: goto x86_l_1785;
	case 6024ULL: goto x86_l_1788;
	case 6026ULL: goto x86_l_178a;
	case 6032ULL: goto x86_l_1790;
	case 6034ULL: goto x86_l_1792;
	case 6037ULL: goto x86_l_1795;
	case 6040ULL: goto x86_l_1798;
	case 6046ULL: goto x86_l_179e;
	case 6049ULL: goto x86_l_17a1;
	case 6051ULL: goto x86_l_17a3;
	case 6058ULL: goto x86_l_17aa;
	case 6060ULL: goto x86_l_17ac;
	case 6062ULL: goto x86_l_17ae;
	case 6068ULL: goto x86_l_17b4;
	case 6070ULL: goto x86_l_17b6;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6080ULL: goto x86_l_17c0;
	case 6082ULL: goto x86_l_17c2;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6092ULL: goto x86_l_17cc;
	case 6098ULL: goto x86_l_17d2;
	case 6100ULL: goto x86_l_17d4;
	case 6102ULL: goto x86_l_17d6;
	case 6108ULL: goto x86_l_17dc;
	case 6110ULL: goto x86_l_17de;
	case 6112ULL: goto x86_l_17e0;
	case 6118ULL: goto x86_l_17e6;
	case 6120ULL: goto x86_l_17e8;
	case 6122ULL: goto x86_l_17ea;
	case 6128ULL: goto x86_l_17f0;
	case 6130ULL: goto x86_l_17f2;
	case 6137ULL: goto x86_l_17f9;
	case 6141ULL: goto x86_l_17fd;
	case 6143ULL: goto x86_l_17ff;
	case 6145ULL: goto x86_l_1801;
	case 6147ULL: goto x86_l_1803;
	case 6149ULL: goto x86_l_1805;
	case 6152ULL: goto x86_l_1808;
	case 6158ULL: goto x86_l_180e;
	case 6160ULL: goto x86_l_1810;
	case 6167ULL: goto x86_l_1817;
	case 6170ULL: goto x86_l_181a;
	case 6172ULL: goto x86_l_181c;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6198ULL: goto x86_l_1836;
	case 6200ULL: goto x86_l_1838;
	case 6202ULL: goto x86_l_183a;
	case 6204ULL: goto x86_l_183c;
	case 6212ULL: goto x86_l_1844;
	case 6219ULL: goto x86_l_184b;
	case 6223ULL: goto x86_l_184f;
	case 6230ULL: goto x86_l_1856;
	case 6238ULL: goto x86_l_185e;
	case 6243ULL: goto x86_l_1863;
	case 6245ULL: goto x86_l_1865;
	case 6248ULL: goto x86_l_1868;
	case 6254ULL: goto x86_l_186e;
	case 6256ULL: goto x86_l_1870;
	case 6260ULL: goto x86_l_1874;
	case 6264ULL: goto x86_l_1878;
	case 6268ULL: goto x86_l_187c;
	case 6275ULL: goto x86_l_1883;
	case 6280ULL: goto x86_l_1888;
	case 6286ULL: goto x86_l_188e;
	case 6289ULL: goto x86_l_1891;
	case 6292ULL: goto x86_l_1894;
	case 6298ULL: goto x86_l_189a;
	case 6301ULL: goto x86_l_189d;
	case 6306ULL: goto x86_l_18a2;
	case 6310ULL: goto x86_l_18a6;
	case 6315ULL: goto x86_l_18ab;
	case 6320ULL: goto x86_l_18b0;
	case 6328ULL: goto x86_l_18b8;
	case 6331ULL: goto x86_l_18bb;
	case 6334ULL: goto x86_l_18be;
	case 6340ULL: goto x86_l_18c4;
	case 6344ULL: goto x86_l_18c8;
	case 6348ULL: goto x86_l_18cc;
	case 6353ULL: goto x86_l_18d1;
	case 6357ULL: goto x86_l_18d5;
	case 6362ULL: goto x86_l_18da;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6377ULL: goto x86_l_18e9;
	case 6382ULL: goto x86_l_18ee;
	case 6385ULL: goto x86_l_18f1;
	case 6387ULL: goto x86_l_18f3;
	case 6390ULL: goto x86_l_18f6;
	case 6396ULL: goto x86_l_18fc;
	case 6398ULL: goto x86_l_18fe;
	case 6402ULL: goto x86_l_1902;
	case 6405ULL: goto x86_l_1905;
	case 6410ULL: goto x86_l_190a;
	case 6413ULL: goto x86_l_190d;
	case 6418ULL: goto x86_l_1912;
	case 6424ULL: goto x86_l_1918;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6437ULL: goto x86_l_1925;
	case 6439ULL: goto x86_l_1927;
	case 6444ULL: goto x86_l_192c;
	case 6446ULL: goto x86_l_192e;
	case 6448ULL: goto x86_l_1930;
	case 6452ULL: goto x86_l_1934;
	case 6454ULL: goto x86_l_1936;
	case 6459ULL: goto x86_l_193b;
	case 6461ULL: goto x86_l_193d;
	case 6463ULL: goto x86_l_193f;
	case 6467ULL: goto x86_l_1943;
	case 6477ULL: goto x86_l_194d;
	case 6480ULL: goto x86_l_1950;
	case 6485ULL: goto x86_l_1955;
	case 6489ULL: goto x86_l_1959;
	case 6492ULL: goto x86_l_195c;
	case 6496ULL: goto x86_l_1960;
	case 6501ULL: goto x86_l_1965;
	case 6505ULL: goto x86_l_1969;
	case 6509ULL: goto x86_l_196d;
	case 6514ULL: goto x86_l_1972;
	case 6516ULL: goto x86_l_1974;
	case 6523ULL: goto x86_l_197b;
	case 6525ULL: goto x86_l_197d;
	case 6528ULL: goto x86_l_1980;
	case 6531ULL: goto x86_l_1983;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6540ULL: goto x86_l_198c;
	case 6543ULL: goto x86_l_198f;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6552ULL: goto x86_l_1998;
	case 6556ULL: goto x86_l_199c;
	case 6560ULL: goto x86_l_19a0;
	case 6563ULL: goto x86_l_19a3;
	case 6568ULL: goto x86_l_19a8;
	case 6571ULL: goto x86_l_19ab;
	case 6577ULL: goto x86_l_19b1;
	case 6580ULL: goto x86_l_19b4;
	case 6585ULL: goto x86_l_19b9;
	case 6591ULL: goto x86_l_19bf;
	case 6599ULL: goto x86_l_19c7;
	case 6607ULL: goto x86_l_19cf;
	case 6611ULL: goto x86_l_19d3;
	case 6613ULL: goto x86_l_19d5;
	case 6620ULL: goto x86_l_19dc;
	case 6622ULL: goto x86_l_19de;
	case 6629ULL: goto x86_l_19e5;
	case 6638ULL: goto x86_l_19ee;
	case 6647ULL: goto x86_l_19f7;
	case 6656ULL: goto x86_l_1a00;
	case 6665ULL: goto x86_l_1a09;
	case 6674ULL: goto x86_l_1a12;
	case 6682ULL: goto x86_l_1a1a;
	case 6687ULL: goto x86_l_1a1f;
	case 6692ULL: goto x86_l_1a24;
	case 6697ULL: goto x86_l_1a29;
	case 6704ULL: goto x86_l_1a30;
	case 6711ULL: goto x86_l_1a37;
	case 6715ULL: goto x86_l_1a3b;
	case 6717ULL: goto x86_l_1a3d;
	case 6724ULL: goto x86_l_1a44;
	case 6728ULL: goto x86_l_1a48;
	case 6732ULL: goto x86_l_1a4c;
	case 6734ULL: goto x86_l_1a4e;
	case 6740ULL: goto x86_l_1a54;
	case 6744ULL: goto x86_l_1a58;
	case 6746ULL: goto x86_l_1a5a;
	case 6753ULL: goto x86_l_1a61;
	case 6757ULL: goto x86_l_1a65;
	case 6759ULL: goto x86_l_1a67;
	case 6766ULL: goto x86_l_1a6e;
	case 6770ULL: goto x86_l_1a72;
	case 6774ULL: goto x86_l_1a76;
	case 6776ULL: goto x86_l_1a78;
	case 6782ULL: goto x86_l_1a7e;
	case 6786ULL: goto x86_l_1a82;
	case 6788ULL: goto x86_l_1a84;
	case 6793ULL: goto x86_l_1a89;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1469:
	/* 0x1469: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_146b:
	/* 0x146b: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_146e:
	/* 0x146e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1470:
	/* 0x1470: jb     1477 <tail_lb_ipv6+0x1477> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1477;
	}
x86_l_1472:
	/* 0x1472: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_1475:
	/* 0x1475: je     1488 <tail_lb_ipv6+0x1488> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1488;
	}
x86_l_1477:
	/* 0x1477: mov    BYTE PTR [r14+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_147b:
	/* 0x147b: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_147f:
	/* 0x147f: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1486:
	/* 0x1486: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1488:
	/* 0x1488: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_148f:
	/* 0x148f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1492:
	/* 0x1492: je     14a6 <tail_lb_ipv6+0x14a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14a6;
	}
x86_l_1494:
	/* 0x1494: inc QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1499:
	/* 0x1499: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149b:
	/* 0x149b: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_149e:
	/* 0x149e: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_14a1:
	/* 0x14a1: add QWORD PTR [r14+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_14a6:
	/* 0x14a6: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_14aa:
	/* 0x14aa: je     14f9 <tail_lb_ipv6+0x14f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14f9;
	}
x86_l_14ac:
	/* 0x14ac: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_14b0:
	/* 0x14b0: jne    19a3 <tail_lb_ipv6+0x19a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19a3;
	}
x86_l_14b6:
	/* 0x14b6: movzx  eax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_14bb:
	/* 0x14bb: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_14bd:
	/* 0x14bd: je     19a3 <tail_lb_ipv6+0x19a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a3;
	}
x86_l_14c3:
	/* 0x14c3: mov    WORD PTR [r14+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_14ca:
	/* 0x14ca: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_14cf:
	/* 0x14cf: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14d4:
	/* 0x14d4: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_14db:
	/* 0x14db: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14df:
	/* 0x14df: je     2ddf <tail_lb_ipv6+0x2ddf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11743ULL;
	}
x86_l_14e5:
	/* 0x14e5: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_14ec:
	/* 0x14ec: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_14f0:
	/* 0x14f0: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14f4:
	/* 0x14f4: jmp    2de5 <tail_lb_ipv6+0x2de5> */
	return 11749ULL;
x86_l_14f9:
	/* 0x14f9: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_14fd:
	/* 0x14fd: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_1502:
	/* 0x1502: cmp    ax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 1ULL);
x86_l_1506:
	/* 0x1506: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_150a:
	/* 0x150a: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_150e:
	/* 0x150e: or     ax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1513:
	/* 0x1513: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1518:
	/* 0x1518: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_151f:
	/* 0x151f: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1522:
	/* 0x1522: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1524:
	/* 0x1524: je     19a3 <tail_lb_ipv6+0x19a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a3;
	}
x86_l_152a:
	/* 0x152a: mov    r12,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1531:
	/* 0x1531: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1536:
	/* 0x1536: je     1912 <tail_lb_ipv6+0x1912> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1912;
	}
x86_l_153c:
	/* 0x153c: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1543:
	/* 0x1543: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1545:
	/* 0x1545: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1547:
	/* 0x1547: lea    r13d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_154b:
	/* 0x154b: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_154f:
	/* 0x154f: jmp    1918 <tail_lb_ipv6+0x1918> */
	goto x86_l_1918;
x86_l_1554:
	/* 0x1554: mov    r14d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 10ULL);
x86_l_155a:
	/* 0x155a: movzx  ebp,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_1562:
	/* 0x1562: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1565:
	/* 0x1565: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156a:
	/* 0x156a: je     157b <tail_lb_ipv6+0x157b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157b;
	}
x86_l_156c:
	/* 0x156c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1571:
	/* 0x1571: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1573:
	/* 0x1573: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1575:
	/* 0x1575: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1579:
	/* 0x1579: jmp    159e <tail_lb_ipv6+0x159e> */
	goto x86_l_159e;
x86_l_157b:
	/* 0x157b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1580:
	/* 0x1580: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1582:
	/* 0x1582: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1584:
	/* 0x1584: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1588:
	/* 0x1588: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1592:
	/* 0x1592: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1595:
	/* 0x1595: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_159a:
	/* 0x159a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_159e:
	/* 0x159e: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15a1:
	/* 0x15a1: mov    DWORD PTR [r15+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a5:
	/* 0x15a5: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_15aa:
	/* 0x15aa: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15ae:
	/* 0x15ae: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_15b2:
	/* 0x15b2: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b7:
	/* 0x15b7: je     15ca <tail_lb_ipv6+0x15ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ca;
	}
x86_l_15b9:
	/* 0x15b9: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_15c0:
	/* 0x15c0: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c2:
	/* 0x15c2: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_15c5:
	/* 0x15c5: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15c8:
	/* 0x15c8: jmp    15cf <tail_lb_ipv6+0x15cf> */
	goto x86_l_15cf;
x86_l_15ca:
	/* 0x15ca: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_15cf:
	/* 0x15cf: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15d1:
	/* 0x15d1: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_15d4:
	/* 0x15d4: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_15d6:
	/* 0x15d6: jb     15dd <tail_lb_ipv6+0x15dd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_15dd;
	}
x86_l_15d8:
	/* 0x15d8: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_15db:
	/* 0x15db: je     15ee <tail_lb_ipv6+0x15ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ee;
	}
x86_l_15dd:
	/* 0x15dd: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_15e1:
	/* 0x15e1: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15e5:
	/* 0x15e5: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_15ec:
	/* 0x15ec: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15ee:
	/* 0x15ee: test   BYTE PTR [rsp+0x75],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173634ULL);
x86_l_15f3:
	/* 0x15f3: jne    1642 <tail_lb_ipv6+0x1642> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1642;
	}
x86_l_15f5:
	/* 0x15f5: movzx  eax,WORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_15fa:
	/* 0x15fa: mov    WORD PTR [rsp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_15ff:
	/* 0x15ff: mov    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1603:
	/* 0x1603: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1607:
	/* 0x1607: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_160b:
	/* 0x160b: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_1612:
	/* 0x1612: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1617:
	/* 0x1617: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_161c:
	/* 0x161c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161e:
	/* 0x161e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1621:
	/* 0x1621: je     164c <tail_lb_ipv6+0x164c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_164c;
	}
x86_l_1623:
	/* 0x1623: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1626:
	/* 0x1626: cmp    BYTE PTR [rax+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_162a:
	/* 0x162a: je     225f <tail_lb_ipv6+0x225f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8799ULL;
	}
x86_l_1630:
	/* 0x1630: test   DWORD PTR [rsp+0x84],0x200 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683584ULL);
x86_l_163b:
	/* 0x163b: jne    1656 <tail_lb_ipv6+0x1656> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1656;
	}
x86_l_163d:
	/* 0x163d: jmp    225f <tail_lb_ipv6+0x225f> */
	return 8799ULL;
x86_l_1642:
	/* 0x1642: mov    ebp,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967133ULL);
x86_l_1647:
	/* 0x1647: jmp    af <tail_lb_ipv6+0xaf> */
	return 175ULL;
x86_l_164c:
	/* 0x164c: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1653:
	/* 0x1653: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1656:
	/* 0x1656: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_165b:
	/* 0x165b: cmp    WORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1660:
	/* 0x1660: je     2136 <tail_lb_ipv6+0x2136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8502ULL;
	}
x86_l_1666:
	/* 0x1666: movzx  eax,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_166a:
	/* 0x166a: shl    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_166d:
	/* 0x166d: cmp    eax,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33554432ULL);
x86_l_1672:
	/* 0x1672: jne    181c <tail_lb_ipv6+0x181c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_181c;
	}
x86_l_1678:
	/* 0x1678: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_167d:
	/* 0x167d: movzx  r12d,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1682:
	/* 0x1682: movzx  r15d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_1688:
	/* 0x1688: movzx  r14d,WORD PTR [rsp+0x72] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 114ULL);
x86_l_168e:
	/* 0x168e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1696:
	/* 0x1696: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_169a:
	/* 0x169a: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16a1:
	/* 0x16a1: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_maglev)));
x86_l_16a8:
	/* 0x16a8: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16b0:
	/* 0x16b0: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_16b5:
	/* 0x16b5: call   rbp */
	X86_SIM_BPF_CALL_REG(X86_RBP);
x86_l_16b7:
	/* 0x16b7: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_16bf:
	/* 0x16bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16c2:
	/* 0x16c2: je     1874 <tail_lb_ipv6+0x1874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1874;
	}
x86_l_16c8:
	/* 0x16c8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16cd:
	/* 0x16cd: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_16d0:
	/* 0x16d0: call   rbp */
	X86_SIM_BPF_CALL_REG(X86_RBP);
x86_l_16d2:
	/* 0x16d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16d5:
	/* 0x16d5: je     1874 <tail_lb_ipv6+0x1874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1874;
	}
x86_l_16db:
	/* 0x16db: mov    ecx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_16df:
	/* 0x16df: mov    edx,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_16e3:
	/* 0x16e3: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16e7:
	/* 0x16e7: sub    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16e9:
	/* 0x16e9: rorx   edi,esi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 28ULL);
x86_l_16ef:
	/* 0x16ef: xor    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f1:
	/* 0x16f1: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16f3:
	/* 0x16f3: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_16f5:
	/* 0x16f5: rorx   ecx,edi,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 26ULL);
x86_l_16fb:
	/* 0x16fb: xor    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16fd:
	/* 0x16fd: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16ff:
	/* 0x16ff: sub    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1701:
	/* 0x1701: rorx   edx,ecx,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 24ULL);
x86_l_1707:
	/* 0x1707: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1709:
	/* 0x1709: add    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_170b:
	/* 0x170b: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_170d:
	/* 0x170d: rorx   esi,edx,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 16ULL);
x86_l_1713:
	/* 0x1713: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1715:
	/* 0x1715: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1717:
	/* 0x1717: sub    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1719:
	/* 0x1719: rorx   edi,esi,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 13ULL);
x86_l_171f:
	/* 0x171f: xor    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1721:
	/* 0x1721: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1723:
	/* 0x1723: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1725:
	/* 0x1725: rorx   ecx,edi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 28ULL);
x86_l_172b:
	/* 0x172b: xor    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172d:
	/* 0x172d: mov    edx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1731:
	/* 0x1731: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1733:
	/* 0x1733: shl    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1737:
	/* 0x1737: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_173a:
	/* 0x173a: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_173e:
	/* 0x173e: cmove  r8d,r15d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R15, X86_WIDTH_32, X86_CC_E);
x86_l_1742:
	/* 0x1742: or     r8d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_1745:
	/* 0x1745: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1748:
	/* 0x1748: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_174b:
	/* 0x174b: movzx  esi,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_1750:
	/* 0x1750: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1752:
	/* 0x1752: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1754:
	/* 0x1754: rorx   ecx,esi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 28ULL);
x86_l_175a:
	/* 0x175a: xor    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175c:
	/* 0x175c: add    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_175f:
	/* 0x175f: sub    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1762:
	/* 0x1762: rorx   edi,ecx,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 26ULL);
x86_l_1768:
	/* 0x1768: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176b:
	/* 0x176b: add    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_176d:
	/* 0x176d: sub    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_176f:
	/* 0x176f: rorx   r8d,edi,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_32, 0, 24ULL);
x86_l_1775:
	/* 0x1775: xor    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1778:
	/* 0x1778: add    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_177a:
	/* 0x177a: sub    ecx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_177d:
	/* 0x177d: rorx   edx,r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_32, 0, 16ULL);
x86_l_1783:
	/* 0x1783: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1785:
	/* 0x1785: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1788:
	/* 0x1788: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_178a:
	/* 0x178a: rorx   esi,edx,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 13ULL);
x86_l_1790:
	/* 0x1790: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1792:
	/* 0x1792: add    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1795:
	/* 0x1795: sub    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1798:
	/* 0x1798: rorx   ecx,esi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 28ULL);
x86_l_179e:
	/* 0x179e: xor    ecx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a1:
	/* 0x17a1: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17a3:
	/* 0x17a3: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_hash_init6_seed)));
x86_l_17aa:
	/* 0x17aa: add    edx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_17ac:
	/* 0x17ac: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ae:
	/* 0x17ae: rorx   edi,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_17b4:
	/* 0x17b4: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17b6:
	/* 0x17b6: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b8:
	/* 0x17b8: rorx   edi,ecx,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 21ULL);
x86_l_17be:
	/* 0x17be: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17c0:
	/* 0x17c0: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17c2:
	/* 0x17c2: rorx   edi,edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 7ULL);
x86_l_17c8:
	/* 0x17c8: sub    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17ca:
	/* 0x17ca: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17cc:
	/* 0x17cc: rorx   edi,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_17d2:
	/* 0x17d2: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17d4:
	/* 0x17d4: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d6:
	/* 0x17d6: rorx   edi,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_17dc:
	/* 0x17dc: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17de:
	/* 0x17de: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e0:
	/* 0x17e0: rorx   edx,edx,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 18ULL);
x86_l_17e6:
	/* 0x17e6: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17e8:
	/* 0x17e8: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ea:
	/* 0x17ea: rorx   edx,esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 8ULL);
x86_l_17f0:
	/* 0x17f0: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_17f2:
	/* 0x17f2: imul   rdx,rcx,0x2605a5 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 2491813ULL);
x86_l_17f9:
	/* 0x17f9: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_17fd:
	/* 0x17fd: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_17ff:
	/* 0x17ff: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1801:
	/* 0x1801: shr    esi,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_1803:
	/* 0x1803: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1805:
	/* 0x1805: shr    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 14ULL);
x86_l_1808:
	/* 0x1808: imul   edx,esi,0x7fed */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RSI, X86_WIDTH_32, 32749ULL);
x86_l_180e:
	/* 0x180e: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1810:
	/* 0x1810: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1817:
	/* 0x1817: mov    eax,DWORD PTR [rax+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_181a:
	/* 0x181a: jmp    1870 <tail_lb_ipv6+0x1870> */
	goto x86_l_1870;
x86_l_181c:
	/* 0x181c: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1824:
	/* 0x1824: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1829:
	/* 0x1829: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182b:
	/* 0x182b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_182d:
	/* 0x182d: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1832:
	/* 0x1832: movzx  ecx,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1836:
	/* 0x1836: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1838:
	/* 0x1838: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_183a:
	/* 0x183a: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_183c:
	/* 0x183c: mov    WORD PTR [rsp+0xaa],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_1844:
	/* 0x1844: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_184b:
	/* 0x184b: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_184f:
	/* 0x184f: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_1856:
	/* 0x1856: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_185e:
	/* 0x185e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1863:
	/* 0x1863: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1865:
	/* 0x1865: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1868:
	/* 0x1868: je     1b4e <tail_lb_ipv6+0x1b4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6990ULL;
	}
x86_l_186e:
	/* 0x186e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1870:
	/* 0x1870: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1874:
	/* 0x1874: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1878:
	/* 0x1878: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_187c:
	/* 0x187c: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_1883:
	/* 0x1883: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1888:
	/* 0x1888: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_188e:
	/* 0x188e: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_1891:
	/* 0x1891: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1894:
	/* 0x1894: je     2127 <tail_lb_ipv6+0x2127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8487ULL;
	}
x86_l_189a:
	/* 0x189a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_189d:
	/* 0x189d: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18a2:
	/* 0x18a2: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_18a6:
	/* 0x18a6: mov    WORD PTR [rsp+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_18ab:
	/* 0x18ab: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18b0:
	/* 0x18b0: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_18b8:
	/* 0x18b8: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_18bb:
	/* 0x18bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18be:
	/* 0x18be: je     225f <tail_lb_ipv6+0x225f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8799ULL;
	}
x86_l_18c4:
	/* 0x18c4: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18c8:
	/* 0x18c8: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18cc:
	/* 0x18cc: movzx  ecx,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_18d1:
	/* 0x18d1: mov    WORD PTR [rax+0x26],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_18d5:
	/* 0x18d5: jmp    225f <tail_lb_ipv6+0x225f> */
	return 8799ULL;
x86_l_18da:
	/* 0x18da: mov    QWORD PTR [rsp+0x78],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18df:
	/* 0x18df: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_18e2:
	/* 0x18e2: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_18e9:
	/* 0x18e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18ee:
	/* 0x18ee: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_18f1:
	/* 0x18f1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f3:
	/* 0x18f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f6:
	/* 0x18f6: je     1be5 <tail_lb_ipv6+0x1be5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7141ULL;
	}
x86_l_18fc:
	/* 0x18fc: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18fe:
	/* 0x18fe: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1902:
	/* 0x1902: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_1905:
	/* 0x1905: jmp    1c1f <tail_lb_ipv6+0x1c1f> */
	return 7199ULL;
x86_l_190a:
	/* 0x190a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_190d:
	/* 0x190d: jmp    66b <tail_lb_ipv6+0x66b> */
	return 1643ULL;
x86_l_1912:
	/* 0x1912: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1918:
	/* 0x1918: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_191d:
	/* 0x191d: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1920:
	/* 0x1920: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1925:
	/* 0x1925: je     1936 <tail_lb_ipv6+0x1936> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1936;
	}
x86_l_1927:
	/* 0x1927: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_192c:
	/* 0x192c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_192e:
	/* 0x192e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1930:
	/* 0x1930: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1934:
	/* 0x1934: jmp    1959 <tail_lb_ipv6+0x1959> */
	goto x86_l_1959;
x86_l_1936:
	/* 0x1936: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_193b:
	/* 0x193b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193d:
	/* 0x193d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_193f:
	/* 0x193f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1943:
	/* 0x1943: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_194d:
	/* 0x194d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1950:
	/* 0x1950: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1955:
	/* 0x1955: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1959:
	/* 0x1959: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_195c:
	/* 0x195c: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1960:
	/* 0x1960: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1965:
	/* 0x1965: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1969:
	/* 0x1969: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_196d:
	/* 0x196d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1972:
	/* 0x1972: je     1985 <tail_lb_ipv6+0x1985> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1985;
	}
x86_l_1974:
	/* 0x1974: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_197b:
	/* 0x197b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197d:
	/* 0x197d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1980:
	/* 0x1980: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1983:
	/* 0x1983: jmp    198a <tail_lb_ipv6+0x198a> */
	goto x86_l_198a;
x86_l_1985:
	/* 0x1985: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_198a:
	/* 0x198a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_198c:
	/* 0x198c: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_198f:
	/* 0x198f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1991:
	/* 0x1991: jb     1998 <tail_lb_ipv6+0x1998> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1998;
	}
x86_l_1993:
	/* 0x1993: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1996:
	/* 0x1996: je     19a3 <tail_lb_ipv6+0x19a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_19a3;
	}
x86_l_1998:
	/* 0x1998: mov    BYTE PTR [r14+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_199c:
	/* 0x199c: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19a0:
	/* 0x19a0: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a3:
	/* 0x19a3: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19a8:
	/* 0x19a8: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_19ab:
	/* 0x19ab: je     33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_19b1:
	/* 0x19b1: mov    bpl,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_19b4:
	/* 0x19b4: cmp    BYTE PTR [rsp+0x74],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206342ULL);
x86_l_19b9:
	/* 0x19b9: jne    33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 51ULL;
	}
x86_l_19bf:
	/* 0x19bf: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19c7:
	/* 0x19c7: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19cf:
	/* 0x19cf: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_19d3:
	/* 0x19d3: jne    19de <tail_lb_ipv6+0x19de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19de;
	}
x86_l_19d5:
	/* 0x19d5: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_19dc:
	/* 0x19dc: jmp    19e5 <tail_lb_ipv6+0x19e5> */
	goto x86_l_19e5;
x86_l_19de:
	/* 0x19de: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_19e5:
	/* 0x19e5: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_19ee:
	/* 0x19ee: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19f7:
	/* 0x19f7: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a00:
	/* 0x1a00: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a09:
	/* 0x1a09: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1a12:
	/* 0x1a12: mov    DWORD PTR [rsp+0x34],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299402ULL);
x86_l_1a1a:
	/* 0x1a1a: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a24:
	/* 0x1a24: mov    WORD PTR [rsp+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a29:
	/* 0x1a29: mov    WORD PTR [rsp+0x2c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561152ULL);
x86_l_1a30:
	/* 0x1a30: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1a37:
	/* 0x1a37: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a3b:
	/* 0x1a3b: je     1a4e <tail_lb_ipv6+0x1a4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a4e;
	}
x86_l_1a3d:
	/* 0x1a3d: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1a44:
	/* 0x1a44: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1a48:
	/* 0x1a48: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1a4c:
	/* 0x1a4c: jmp    1a54 <tail_lb_ipv6+0x1a54> */
	goto x86_l_1a54;
x86_l_1a4e:
	/* 0x1a4e: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1a54:
	/* 0x1a54: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1a58:
	/* 0x1a58: jne    1a7e <tail_lb_ipv6+0x1a7e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a7e;
	}
x86_l_1a5a:
	/* 0x1a5a: mov    WORD PTR [rsp+0x2c],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561152ULL);
x86_l_1a61:
	/* 0x1a61: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a65:
	/* 0x1a65: je     1a78 <tail_lb_ipv6+0x1a78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1a78;
	}
x86_l_1a67:
	/* 0x1a67: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1a6e:
	/* 0x1a6e: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1a72:
	/* 0x1a72: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1a76:
	/* 0x1a76: jmp    1a7e <tail_lb_ipv6+0x1a7e> */
	goto x86_l_1a7e;
x86_l_1a78:
	/* 0x1a78: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1a7e:
	/* 0x1a7e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a82:
	/* 0x1a82: je     1a93 <tail_lb_ipv6+0x1a93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6803ULL;
	}
x86_l_1a84:
	/* 0x1a84: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1a89:
	/* 0x1a89: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a8b:
	/* 0x1a8b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a8d:
	/* 0x1a8d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
	return 6801ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6801ULL: goto x86_l_1a91;
	case 6803ULL: goto x86_l_1a93;
	case 6808ULL: goto x86_l_1a98;
	case 6810ULL: goto x86_l_1a9a;
	case 6812ULL: goto x86_l_1a9c;
	case 6816ULL: goto x86_l_1aa0;
	case 6826ULL: goto x86_l_1aaa;
	case 6829ULL: goto x86_l_1aad;
	case 6834ULL: goto x86_l_1ab2;
	case 6838ULL: goto x86_l_1ab6;
	case 6842ULL: goto x86_l_1aba;
	case 6845ULL: goto x86_l_1abd;
	case 6848ULL: goto x86_l_1ac0;
	case 6853ULL: goto x86_l_1ac5;
	case 6858ULL: goto x86_l_1aca;
	case 6862ULL: goto x86_l_1ace;
	case 6864ULL: goto x86_l_1ad0;
	case 6868ULL: goto x86_l_1ad4;
	case 6870ULL: goto x86_l_1ad6;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6882ULL: goto x86_l_1ae2;
	case 6885ULL: goto x86_l_1ae5;
	case 6887ULL: goto x86_l_1ae7;
	case 6892ULL: goto x86_l_1aec;
	case 6894ULL: goto x86_l_1aee;
	case 6896ULL: goto x86_l_1af0;
	case 6898ULL: goto x86_l_1af2;
	case 6900ULL: goto x86_l_1af4;
	case 6902ULL: goto x86_l_1af6;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6912ULL: goto x86_l_1b00;
	case 6919ULL: goto x86_l_1b07;
	case 6921ULL: goto x86_l_1b09;
	case 6928ULL: goto x86_l_1b10;
	case 6931ULL: goto x86_l_1b13;
	case 6933ULL: goto x86_l_1b15;
	case 6942ULL: goto x86_l_1b1e;
	case 6944ULL: goto x86_l_1b20;
	case 6947ULL: goto x86_l_1b23;
	case 6950ULL: goto x86_l_1b26;
	case 6955ULL: goto x86_l_1b2b;
	case 6960ULL: goto x86_l_1b30;
	case 6965ULL: goto x86_l_1b35;
	case 6970ULL: goto x86_l_1b3a;
	case 6973ULL: goto x86_l_1b3d;
	case 6975ULL: goto x86_l_1b3f;
	case 6977ULL: goto x86_l_1b41;
	case 6979ULL: goto x86_l_1b43;
	case 6985ULL: goto x86_l_1b49;
	case 6990ULL: goto x86_l_1b4e;
	case 6994ULL: goto x86_l_1b52;
	case 6999ULL: goto x86_l_1b57;
	case 7004ULL: goto x86_l_1b5c;
	case 7009ULL: goto x86_l_1b61;
	case 7014ULL: goto x86_l_1b66;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7031ULL: goto x86_l_1b77;
	case 7036ULL: goto x86_l_1b7c;
	case 7041ULL: goto x86_l_1b81;
	case 7043ULL: goto x86_l_1b83;
	case 7048ULL: goto x86_l_1b88;
	case 7053ULL: goto x86_l_1b8d;
	case 7055ULL: goto x86_l_1b8f;
	case 7061ULL: goto x86_l_1b95;
	case 7063ULL: goto x86_l_1b97;
	case 7066ULL: goto x86_l_1b9a;
	case 7075ULL: goto x86_l_1ba3;
	case 7078ULL: goto x86_l_1ba6;
	case 7087ULL: goto x86_l_1baf;
	case 7097ULL: goto x86_l_1bb9;
	case 7105ULL: goto x86_l_1bc1;
	case 7112ULL: goto x86_l_1bc8;
	case 7120ULL: goto x86_l_1bd0;
	case 7125ULL: goto x86_l_1bd5;
	case 7127ULL: goto x86_l_1bd7;
	case 7130ULL: goto x86_l_1bda;
	case 7132ULL: goto x86_l_1bdc;
	case 7135ULL: goto x86_l_1bdf;
	case 7139ULL: goto x86_l_1be3;
	case 7141ULL: goto x86_l_1be5;
	case 7146ULL: goto x86_l_1bea;
	case 7151ULL: goto x86_l_1bef;
	case 7160ULL: goto x86_l_1bf8;
	case 7165ULL: goto x86_l_1bfd;
	case 7172ULL: goto x86_l_1c04;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7190ULL: goto x86_l_1c16;
	case 7192ULL: goto x86_l_1c18;
	case 7194ULL: goto x86_l_1c1a;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7215ULL: goto x86_l_1c2f;
	case 7220ULL: goto x86_l_1c34;
	case 7226ULL: goto x86_l_1c3a;
	case 7231ULL: goto x86_l_1c3f;
	case 7237ULL: goto x86_l_1c45;
	case 7242ULL: goto x86_l_1c4a;
	case 7244ULL: goto x86_l_1c4c;
	case 7251ULL: goto x86_l_1c53;
	case 7253ULL: goto x86_l_1c55;
	case 7256ULL: goto x86_l_1c58;
	case 7259ULL: goto x86_l_1c5b;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7268ULL: goto x86_l_1c64;
	case 7273ULL: goto x86_l_1c69;
	case 7279ULL: goto x86_l_1c6f;
	case 7283ULL: goto x86_l_1c73;
	case 7287ULL: goto x86_l_1c77;
	case 7289ULL: goto x86_l_1c79;
	case 7296ULL: goto x86_l_1c80;
	case 7300ULL: goto x86_l_1c84;
	case 7304ULL: goto x86_l_1c88;
	case 7312ULL: goto x86_l_1c90;
	case 7315ULL: goto x86_l_1c93;
	case 7319ULL: goto x86_l_1c97;
	case 7321ULL: goto x86_l_1c99;
	case 7326ULL: goto x86_l_1c9e;
	case 7328ULL: goto x86_l_1ca0;
	case 7330ULL: goto x86_l_1ca2;
	case 7334ULL: goto x86_l_1ca6;
	case 7336ULL: goto x86_l_1ca8;
	case 7341ULL: goto x86_l_1cad;
	case 7343ULL: goto x86_l_1caf;
	case 7345ULL: goto x86_l_1cb1;
	case 7349ULL: goto x86_l_1cb5;
	case 7359ULL: goto x86_l_1cbf;
	case 7362ULL: goto x86_l_1cc2;
	case 7367ULL: goto x86_l_1cc7;
	case 7371ULL: goto x86_l_1ccb;
	case 7374ULL: goto x86_l_1cce;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7387ULL: goto x86_l_1cdb;
	case 7391ULL: goto x86_l_1cdf;
	case 7395ULL: goto x86_l_1ce3;
	case 7397ULL: goto x86_l_1ce5;
	case 7404ULL: goto x86_l_1cec;
	case 7406ULL: goto x86_l_1cee;
	case 7409ULL: goto x86_l_1cf1;
	case 7412ULL: goto x86_l_1cf4;
	case 7414ULL: goto x86_l_1cf6;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7431ULL: goto x86_l_1d07;
	case 7433ULL: goto x86_l_1d09;
	case 7436ULL: goto x86_l_1d0c;
	case 7438ULL: goto x86_l_1d0e;
	case 7442ULL: goto x86_l_1d12;
	case 7446ULL: goto x86_l_1d16;
	case 7453ULL: goto x86_l_1d1d;
	case 7455ULL: goto x86_l_1d1f;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7471ULL: goto x86_l_1d2f;
	case 7475ULL: goto x86_l_1d33;
	case 7481ULL: goto x86_l_1d39;
	case 7490ULL: goto x86_l_1d42;
	case 7499ULL: goto x86_l_1d4b;
	case 7508ULL: goto x86_l_1d54;
	case 7512ULL: goto x86_l_1d58;
	case 7517ULL: goto x86_l_1d5d;
	case 7522ULL: goto x86_l_1d62;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7543ULL: goto x86_l_1d77;
	case 7548ULL: goto x86_l_1d7c;
	case 7555ULL: goto x86_l_1d83;
	case 7560ULL: goto x86_l_1d88;
	case 7565ULL: goto x86_l_1d8d;
	case 7567ULL: goto x86_l_1d8f;
	case 7570ULL: goto x86_l_1d92;
	case 7576ULL: goto x86_l_1d98;
	case 7579ULL: goto x86_l_1d9b;
	case 7586ULL: goto x86_l_1da2;
	case 7590ULL: goto x86_l_1da6;
	case 7592ULL: goto x86_l_1da8;
	case 7597ULL: goto x86_l_1dad;
	case 7599ULL: goto x86_l_1daf;
	case 7601ULL: goto x86_l_1db1;
	case 7605ULL: goto x86_l_1db5;
	case 7607ULL: goto x86_l_1db7;
	case 7612ULL: goto x86_l_1dbc;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7620ULL: goto x86_l_1dc4;
	case 7630ULL: goto x86_l_1dce;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7642ULL: goto x86_l_1dda;
	case 7646ULL: goto x86_l_1dde;
	case 7653ULL: goto x86_l_1de5;
	case 7658ULL: goto x86_l_1dea;
	case 7662ULL: goto x86_l_1dee;
	case 7670ULL: goto x86_l_1df6;
	case 7680ULL: goto x86_l_1e00;
	case 7683ULL: goto x86_l_1e03;
	case 7688ULL: goto x86_l_1e08;
	case 7690ULL: goto x86_l_1e0a;
	case 7694ULL: goto x86_l_1e0e;
	case 7696ULL: goto x86_l_1e10;
	case 7703ULL: goto x86_l_1e17;
	case 7706ULL: goto x86_l_1e1a;
	case 7709ULL: goto x86_l_1e1d;
	case 7711ULL: goto x86_l_1e1f;
	case 7714ULL: goto x86_l_1e22;
	case 7717ULL: goto x86_l_1e25;
	case 7720ULL: goto x86_l_1e28;
	case 7722ULL: goto x86_l_1e2a;
	case 7729ULL: goto x86_l_1e31;
	case 7737ULL: goto x86_l_1e39;
	case 7742ULL: goto x86_l_1e3e;
	case 7744ULL: goto x86_l_1e40;
	case 7747ULL: goto x86_l_1e43;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7756ULL: goto x86_l_1e4c;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7765ULL: goto x86_l_1e55;
	case 7767ULL: goto x86_l_1e57;
	case 7771ULL: goto x86_l_1e5b;
	case 7778ULL: goto x86_l_1e62;
	case 7783ULL: goto x86_l_1e67;
	case 7788ULL: goto x86_l_1e6c;
	case 7790ULL: goto x86_l_1e6e;
	case 7793ULL: goto x86_l_1e71;
	case 7796ULL: goto x86_l_1e74;
	case 7802ULL: goto x86_l_1e7a;
	case 7809ULL: goto x86_l_1e81;
	case 7812ULL: goto x86_l_1e84;
	case 7814ULL: goto x86_l_1e86;
	case 7821ULL: goto x86_l_1e8d;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7833ULL: goto x86_l_1e99;
	case 7838ULL: goto x86_l_1e9e;
	case 7842ULL: goto x86_l_1ea2;
	case 7845ULL: goto x86_l_1ea5;
	case 7850ULL: goto x86_l_1eaa;
	case 7856ULL: goto x86_l_1eb0;
	case 7861ULL: goto x86_l_1eb5;
	case 7867ULL: goto x86_l_1ebb;
	case 7873ULL: goto x86_l_1ec1;
	case 7881ULL: goto x86_l_1ec9;
	case 7885ULL: goto x86_l_1ecd;
	case 7892ULL: goto x86_l_1ed4;
	case 7899ULL: goto x86_l_1edb;
	case 7907ULL: goto x86_l_1ee3;
	case 7912ULL: goto x86_l_1ee8;
	case 7914ULL: goto x86_l_1eea;
	case 7917ULL: goto x86_l_1eed;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7931ULL: goto x86_l_1efb;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7941ULL: goto x86_l_1f05;
	case 7947ULL: goto x86_l_1f0b;
	case 7951ULL: goto x86_l_1f0f;
	case 7955ULL: goto x86_l_1f13;
	case 7959ULL: goto x86_l_1f17;
	case 7961ULL: goto x86_l_1f19;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7973ULL: goto x86_l_1f25;
	case 7979ULL: goto x86_l_1f2b;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7985ULL: goto x86_l_1f31;
	case 7991ULL: goto x86_l_1f37;
	case 7993ULL: goto x86_l_1f39;
	case 7995ULL: goto x86_l_1f3b;
	case 7997ULL: goto x86_l_1f3d;
	case 8003ULL: goto x86_l_1f43;
	case 8005ULL: goto x86_l_1f45;
	case 8007ULL: goto x86_l_1f47;
	case 8009ULL: goto x86_l_1f49;
	case 8015ULL: goto x86_l_1f4f;
	case 8017ULL: goto x86_l_1f51;
	case 8019ULL: goto x86_l_1f53;
	case 8021ULL: goto x86_l_1f55;
	case 8027ULL: goto x86_l_1f5b;
	case 8029ULL: goto x86_l_1f5d;
	case 8033ULL: goto x86_l_1f61;
	case 8035ULL: goto x86_l_1f63;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8050ULL: goto x86_l_1f72;
	case 8053ULL: goto x86_l_1f75;
	case 8056ULL: goto x86_l_1f78;
	case 8059ULL: goto x86_l_1f7b;
	case 8064ULL: goto x86_l_1f80;
	case 8066ULL: goto x86_l_1f82;
	case 8068ULL: goto x86_l_1f84;
	case 8074ULL: goto x86_l_1f8a;
	case 8076ULL: goto x86_l_1f8c;
	case 8079ULL: goto x86_l_1f8f;
	case 8082ULL: goto x86_l_1f92;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8093ULL: goto x86_l_1f9d;
	case 8095ULL: goto x86_l_1f9f;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8109ULL: goto x86_l_1fad;
	case 8115ULL: goto x86_l_1fb3;
	case 8117ULL: goto x86_l_1fb5;
	case 8120ULL: goto x86_l_1fb8;
	case 8122ULL: goto x86_l_1fba;
	case 8128ULL: goto x86_l_1fc0;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8136ULL: goto x86_l_1fc8;
	case 8142ULL: goto x86_l_1fce;
	case 8145ULL: goto x86_l_1fd1;
	case 8147ULL: goto x86_l_1fd3;
	case 8154ULL: goto x86_l_1fda;
	case 8156ULL: goto x86_l_1fdc;
	case 8158ULL: goto x86_l_1fde;
	case 8164ULL: goto x86_l_1fe4;
	case 8166ULL: goto x86_l_1fe6;
	case 8168ULL: goto x86_l_1fe8;
	case 8174ULL: goto x86_l_1fee;
	case 8176ULL: goto x86_l_1ff0;
	case 8178ULL: goto x86_l_1ff2;
	case 8184ULL: goto x86_l_1ff8;
	case 8186ULL: goto x86_l_1ffa;
	case 8188ULL: goto x86_l_1ffc;
	case 8194ULL: goto x86_l_2002;
	case 8196ULL: goto x86_l_2004;
	case 8198ULL: goto x86_l_2006;
	case 8204ULL: goto x86_l_200c;
	case 8206ULL: goto x86_l_200e;
	case 8208ULL: goto x86_l_2010;
	case 8214ULL: goto x86_l_2016;
	case 8216ULL: goto x86_l_2018;
	case 8218ULL: goto x86_l_201a;
	case 8224ULL: goto x86_l_2020;
	case 8226ULL: goto x86_l_2022;
	case 8233ULL: goto x86_l_2029;
	case 8237ULL: goto x86_l_202d;
	case 8239ULL: goto x86_l_202f;
	case 8241ULL: goto x86_l_2031;
	case 8243ULL: goto x86_l_2033;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8256ULL: goto x86_l_2040;
	case 8263ULL: goto x86_l_2047;
	case 8266ULL: goto x86_l_204a;
	case 8268ULL: goto x86_l_204c;
	case 8270ULL: goto x86_l_204e;
	case 8275ULL: goto x86_l_2053;
	case 8278ULL: goto x86_l_2056;
	case 8280ULL: goto x86_l_2058;
	case 8282ULL: goto x86_l_205a;
	case 8287ULL: goto x86_l_205f;
	case 8289ULL: goto x86_l_2061;
	case 8291ULL: goto x86_l_2063;
	case 8293ULL: goto x86_l_2065;
	case 8301ULL: goto x86_l_206d;
	case 8308ULL: goto x86_l_2074;
	case 8312ULL: goto x86_l_2078;
	case 8319ULL: goto x86_l_207f;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8334ULL: goto x86_l_208e;
	case 8337ULL: goto x86_l_2091;
	case 8339ULL: goto x86_l_2093;
	case 8341ULL: goto x86_l_2095;
	case 8343ULL: goto x86_l_2097;
	case 8347ULL: goto x86_l_209b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1a91:
	/* 0x1a91: jmp    1ab6 <tail_lb_ipv6+0x1ab6> */
	goto x86_l_1ab6;
x86_l_1a93:
	/* 0x1a93: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1a98:
	/* 0x1a98: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9a:
	/* 0x1a9a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a9c:
	/* 0x1a9c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1aa0:
	/* 0x1aa0: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1aaa:
	/* 0x1aaa: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1aad:
	/* 0x1aad: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ab2:
	/* 0x1ab2: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1ab6:
	/* 0x1ab6: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1aba:
	/* 0x1aba: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1abd:
	/* 0x1abd: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ac0:
	/* 0x1ac0: mov    DWORD PTR [rsp+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ac5:
	/* 0x1ac5: movzx  edx,BYTE PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 50ULL);
x86_l_1aca:
	/* 0x1aca: mov    esi,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ace:
	/* 0x1ace: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1ad0:
	/* 0x1ad0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad4:
	/* 0x1ad4: je     1ae7 <tail_lb_ipv6+0x1ae7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ae7;
	}
x86_l_1ad6:
	/* 0x1ad6: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1add:
	/* 0x1add: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1adf:
	/* 0x1adf: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1ae2:
	/* 0x1ae2: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ae5:
	/* 0x1ae5: jmp    1aec <tail_lb_ipv6+0x1aec> */
	goto x86_l_1aec;
x86_l_1ae7:
	/* 0x1ae7: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1aec:
	/* 0x1aec: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1aee:
	/* 0x1aee: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1af0:
	/* 0x1af0: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1af2:
	/* 0x1af2: jb     1af8 <tail_lb_ipv6+0x1af8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af8;
	}
x86_l_1af4:
	/* 0x1af4: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_1af6:
	/* 0x1af6: je     1b09 <tail_lb_ipv6+0x1b09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b09;
	}
x86_l_1af8:
	/* 0x1af8: mov    BYTE PTR [rsp+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_1afc:
	/* 0x1afc: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b00:
	/* 0x1b00: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1b07:
	/* 0x1b07: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b09:
	/* 0x1b09: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1b10:
	/* 0x1b10: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b13:
	/* 0x1b13: je     1b2b <tail_lb_ipv6+0x1b2b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b2b;
	}
x86_l_1b15:
	/* 0x1b15: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b20:
	/* 0x1b20: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b23:
	/* 0x1b23: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1b26:
	/* 0x1b26: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b2b:
	/* 0x1b2b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b30:
	/* 0x1b30: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b35:
	/* 0x1b35: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b3a:
	/* 0x1b3a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1b3d:
	/* 0x1b3d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b3f:
	/* 0x1b3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b41:
	/* 0x1b41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b43:
	/* 0x1b43: jns    33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 51ULL;
	}
x86_l_1b49:
	/* 0x1b49: jmp    2dc0 <tail_lb_ipv6+0x2dc0> */
	return 11712ULL;
x86_l_1b4e:
	/* 0x1b4e: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1b52:
	/* 0x1b52: jmp    1874 <tail_lb_ipv6+0x1874> */
	return 6260ULL;
x86_l_1b57:
	/* 0x1b57: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_1b5c:
	/* 0x1b5c: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	return 1012ULL;
x86_l_1b61:
	/* 0x1b61: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b66:
	/* 0x1b66: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1b6d:
	/* 0x1b6d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b72:
	/* 0x1b72: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1b75:
	/* 0x1b75: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b77:
	/* 0x1b77: mov    QWORD PTR [rsp+0x48],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b7c:
	/* 0x1b7c: mov    QWORD PTR [rsp+0x78],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b81:
	/* 0x1b81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b83:
	/* 0x1b83: mov    r9,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1b88:
	/* 0x1b88: mov    r10,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b8d:
	/* 0x1b8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b8f:
	/* 0x1b8f: je     7af <tail_lb_ipv6+0x7af> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1967ULL;
	}
x86_l_1b95:
	/* 0x1b95: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b97:
	/* 0x1b97: mov    ebp,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ba3:
	/* 0x1ba3: sub    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1ba6:
	/* 0x1ba6: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1baf:
	/* 0x1baf: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1bb9:
	/* 0x1bb9: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1bc1:
	/* 0x1bc1: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1bc8:
	/* 0x1bc8: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1bd0:
	/* 0x1bd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bd5:
	/* 0x1bd5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd7:
	/* 0x1bd7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bda:
	/* 0x1bda: je     1bef <tail_lb_ipv6+0x1bef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bef;
	}
x86_l_1bdc:
	/* 0x1bdc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1bdf:
	/* 0x1bdf: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1be3:
	/* 0x1be3: jmp    1c1a <tail_lb_ipv6+0x1c1a> */
	goto x86_l_1c1a;
x86_l_1be5:
	/* 0x1be5: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1bea:
	/* 0x1bea: jmp    632 <tail_lb_ipv6+0x632> */
	return 1586ULL;
x86_l_1bef:
	/* 0x1bef: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1bf8:
	/* 0x1bf8: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bfd:
	/* 0x1bfd: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c04:
	/* 0x1c04: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c0c:
	/* 0x1c0c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c11:
	/* 0x1c11: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c16:
	/* 0x1c16: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c18:
	/* 0x1c18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1a:
	/* 0x1c1a: mov    r10,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c1f:
	/* 0x1c1f: mov    r9,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1c24:
	/* 0x1c24: jmp    7af <tail_lb_ipv6+0x7af> */
	return 1967ULL;
x86_l_1c29:
	/* 0x1c29: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1c2f:
	/* 0x1c2f: jmp    cc8 <tail_lb_ipv6+0xcc8> */
	return 3272ULL;
x86_l_1c34:
	/* 0x1c34: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1c3a:
	/* 0x1c3a: jmp    1112 <tail_lb_ipv6+0x1112> */
	return 4370ULL;
x86_l_1c3f:
	/* 0x1c3f: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1c45:
	/* 0x1c45: cmp    BYTE PTR [rsp+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_1c4a:
	/* 0x1c4a: jne    1c88 <tail_lb_ipv6+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c88;
	}
x86_l_1c4c:
	/* 0x1c4c: mov    ecx,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1c53:
	/* 0x1c53: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1c55:
	/* 0x1c55: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1c58:
	/* 0x1c58: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1c5b:
	/* 0x1c5b: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c5d:
	/* 0x1c5d: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c62:
	/* 0x1c62: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1c64:
	/* 0x1c64: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1c69:
	/* 0x1c69: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_1c6f:
	/* 0x1c6f: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1c73:
	/* 0x1c73: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c77:
	/* 0x1c77: je     1c88 <tail_lb_ipv6+0x1c88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c88;
	}
x86_l_1c79:
	/* 0x1c79: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c80:
	/* 0x1c80: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1c84:
	/* 0x1c84: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c88:
	/* 0x1c88: movzx  ebp,WORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 132ULL);
x86_l_1c90:
	/* 0x1c90: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c93:
	/* 0x1c93: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c97:
	/* 0x1c97: je     1ca8 <tail_lb_ipv6+0x1ca8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ca8;
	}
x86_l_1c99:
	/* 0x1c99: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1c9e:
	/* 0x1c9e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca0:
	/* 0x1ca0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ca2:
	/* 0x1ca2: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1ca6:
	/* 0x1ca6: jmp    1ccb <tail_lb_ipv6+0x1ccb> */
	goto x86_l_1ccb;
x86_l_1ca8:
	/* 0x1ca8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1cad:
	/* 0x1cad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1caf:
	/* 0x1caf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cb1:
	/* 0x1cb1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1cb5:
	/* 0x1cb5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1cc2:
	/* 0x1cc2: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1cc7:
	/* 0x1cc7: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1ccb:
	/* 0x1ccb: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cce:
	/* 0x1cce: mov    DWORD PTR [r15+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd2:
	/* 0x1cd2: movzx  edx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    ecx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cdb:
	/* 0x1cdb: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1cdf:
	/* 0x1cdf: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ce3:
	/* 0x1ce3: je     1cf6 <tail_lb_ipv6+0x1cf6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cf6;
	}
x86_l_1ce5:
	/* 0x1ce5: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1cec:
	/* 0x1cec: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cee:
	/* 0x1cee: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1cf1:
	/* 0x1cf1: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1cf4:
	/* 0x1cf4: jmp    1cfb <tail_lb_ipv6+0x1cfb> */
	goto x86_l_1cfb;
x86_l_1cf6:
	/* 0x1cf6: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1cfb:
	/* 0x1cfb: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cfd:
	/* 0x1cfd: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d00:
	/* 0x1d00: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1d02:
	/* 0x1d02: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d07:
	/* 0x1d07: jb     1d0e <tail_lb_ipv6+0x1d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d0e;
	}
x86_l_1d09:
	/* 0x1d09: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_1d0c:
	/* 0x1d0c: je     1d24 <tail_lb_ipv6+0x1d24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d24;
	}
x86_l_1d0e:
	/* 0x1d0e: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1d12:
	/* 0x1d12: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d16:
	/* 0x1d16: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1d1d:
	/* 0x1d1d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d24:
	/* 0x1d24: cmp    WORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1d29:
	/* 0x1d29: je     2136 <tail_lb_ipv6+0x2136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8502ULL;
	}
x86_l_1d2f:
	/* 0x1d2f: test   BYTE PTR [rcx+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1d33:
	/* 0x1d33: je     1e9e <tail_lb_ipv6+0x1e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9e;
	}
x86_l_1d39:
	/* 0x1d39: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1d42:
	/* 0x1d42: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d4b:
	/* 0x1d4b: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d54:
	/* 0x1d54: movzx  eax,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1d58:
	/* 0x1d58: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d5d:
	/* 0x1d5d: mov    BYTE PTR [rsp+0x1a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149696ULL);
x86_l_1d62:
	/* 0x1d62: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1d77:
	/* 0x1d77: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7c:
	/* 0x1d7c: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_1d83:
	/* 0x1d83: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d88:
	/* 0x1d88: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d8d:
	/* 0x1d8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8f:
	/* 0x1d8f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d92:
	/* 0x1d92: je     1e99 <tail_lb_ipv6+0x1e99> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e99;
	}
x86_l_1d98:
	/* 0x1d98: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1d9b:
	/* 0x1d9b: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1da2:
	/* 0x1da2: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da6:
	/* 0x1da6: je     1db7 <tail_lb_ipv6+0x1db7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1db7;
	}
x86_l_1da8:
	/* 0x1da8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1dad:
	/* 0x1dad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1daf:
	/* 0x1daf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1db1:
	/* 0x1db1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1db5:
	/* 0x1db5: jmp    1dda <tail_lb_ipv6+0x1dda> */
	goto x86_l_1dda;
x86_l_1db7:
	/* 0x1db7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1dbc:
	/* 0x1dbc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dbe:
	/* 0x1dbe: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1dc0:
	/* 0x1dc0: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1dc4:
	/* 0x1dc4: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1dce:
	/* 0x1dce: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1dd1:
	/* 0x1dd1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1dd6:
	/* 0x1dd6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1dda:
	/* 0x1dda: mov    ecx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dde:
	/* 0x1dde: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1de5:
	/* 0x1de5: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1dea:
	/* 0x1dea: movzx  ecx,WORD PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1dee:
	/* 0x1dee: mov    WORD PTR [rsp+0x8c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_1df6:
	/* 0x1df6: mov    WORD PTR [rsp+0x8e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_1e00:
	/* 0x1e00: mov    rcx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e03:
	/* 0x1e03: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_1e08:
	/* 0x1e08: and    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_1e0a:
	/* 0x1e0a: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0e:
	/* 0x1e0e: je     1e1d <tail_lb_ipv6+0x1e1d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e1d;
	}
x86_l_1e10:
	/* 0x1e10: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e17:
	/* 0x1e17: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1e1a:
	/* 0x1e1a: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e1d:
	/* 0x1e1d: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1e1f:
	/* 0x1e1f: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e22:
	/* 0x1e22: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1e25:
	/* 0x1e25: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1e28:
	/* 0x1e28: jbe    1e86 <tail_lb_ipv6+0x1e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1e86;
	}
x86_l_1e2a:
	/* 0x1e2a: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_1e31:
	/* 0x1e31: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1e39:
	/* 0x1e39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e3e:
	/* 0x1e3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e40:
	/* 0x1e40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e43:
	/* 0x1e43: je     1e86 <tail_lb_ipv6+0x1e86> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e86;
	}
x86_l_1e45:
	/* 0x1e45: mov    QWORD PTR [r15],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e48:
	/* 0x1e48: mov    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e4c:
	/* 0x1e4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e4e:
	/* 0x1e4e: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e53:
	/* 0x1e53: je     1e9e <tail_lb_ipv6+0x1e9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e9e;
	}
x86_l_1e55:
	/* 0x1e55: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1e57:
	/* 0x1e57: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e5b:
	/* 0x1e5b: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_1e62:
	/* 0x1e62: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e67:
	/* 0x1e67: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e6c:
	/* 0x1e6c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6e:
	/* 0x1e6e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1e71:
	/* 0x1e71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e74:
	/* 0x1e74: jne    20ba <tail_lb_ipv6+0x20ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8378ULL;
	}
x86_l_1e7a:
	/* 0x1e7a: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1e81:
	/* 0x1e81: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e84:
	/* 0x1e84: jmp    1e99 <tail_lb_ipv6+0x1e99> */
	goto x86_l_1e99;
x86_l_1e86:
	/* 0x1e86: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_1e8d:
	/* 0x1e8d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e92:
	/* 0x1e92: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e97:
	/* 0x1e97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e99:
	/* 0x1e99: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e9e:
	/* 0x1e9e: movzx  eax,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1ea2:
	/* 0x1ea2: shl    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 24ULL);
x86_l_1ea5:
	/* 0x1ea5: cmp    eax,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33554432ULL);
x86_l_1eaa:
	/* 0x1eaa: jne    204c <tail_lb_ipv6+0x204c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_204c;
	}
x86_l_1eb0:
	/* 0x1eb0: movzx  r12d,BYTE PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1eb5:
	/* 0x1eb5: movzx  r15d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_1ebb:
	/* 0x1ebb: movzx  r14d,WORD PTR [rsp+0x72] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 114ULL);
x86_l_1ec1:
	/* 0x1ec1: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ec9:
	/* 0x1ec9: movzx  eax,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1ecd:
	/* 0x1ecd: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_maglev)));
x86_l_1edb:
	/* 0x1edb: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1ee3:
	/* 0x1ee3: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1ee8:
	/* 0x1ee8: call   rbp */
	X86_SIM_BPF_CALL_REG(X86_RBP);
x86_l_1eea:
	/* 0x1eea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1eed:
	/* 0x1eed: je     2dcd <tail_lb_ipv6+0x2dcd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11725ULL;
	}
x86_l_1ef3:
	/* 0x1ef3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1efb:
	/* 0x1efb: call   rbp */
	X86_SIM_BPF_CALL_REG(X86_RBP);
x86_l_1efd:
	/* 0x1efd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f00:
	/* 0x1f00: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_1f05:
	/* 0x1f05: je     209b <tail_lb_ipv6+0x209b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_209b;
	}
x86_l_1f0b:
	/* 0x1f0b: mov    ecx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f0f:
	/* 0x1f0f: mov    edx,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_1f13:
	/* 0x1f13: mov    esi,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f17:
	/* 0x1f17: sub    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f19:
	/* 0x1f19: rorx   edi,esi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 28ULL);
x86_l_1f1f:
	/* 0x1f1f: xor    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f21:
	/* 0x1f21: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f23:
	/* 0x1f23: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f25:
	/* 0x1f25: rorx   ecx,edi,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 26ULL);
x86_l_1f2b:
	/* 0x1f2b: xor    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f2d:
	/* 0x1f2d: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f2f:
	/* 0x1f2f: sub    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f31:
	/* 0x1f31: rorx   edx,ecx,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 24ULL);
x86_l_1f37:
	/* 0x1f37: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f39:
	/* 0x1f39: add    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f3b:
	/* 0x1f3b: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f3d:
	/* 0x1f3d: rorx   esi,edx,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 16ULL);
x86_l_1f43:
	/* 0x1f43: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f45:
	/* 0x1f45: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f47:
	/* 0x1f47: sub    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f49:
	/* 0x1f49: rorx   edi,esi,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 13ULL);
x86_l_1f4f:
	/* 0x1f4f: xor    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f51:
	/* 0x1f51: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f53:
	/* 0x1f53: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f55:
	/* 0x1f55: rorx   ecx,edi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 28ULL);
x86_l_1f5b:
	/* 0x1f5b: xor    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f5d:
	/* 0x1f5d: mov    edx,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1f61:
	/* 0x1f61: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f63:
	/* 0x1f63: shl    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_1f67:
	/* 0x1f67: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6a:
	/* 0x1f6a: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_1f6e:
	/* 0x1f6e: cmove  r8d,r15d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R15, X86_WIDTH_32, X86_CC_E);
x86_l_1f72:
	/* 0x1f72: or     r8d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_1f75:
	/* 0x1f75: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f78:
	/* 0x1f78: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f7b:
	/* 0x1f7b: movzx  esi,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_1f80:
	/* 0x1f80: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f82:
	/* 0x1f82: sub    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f84:
	/* 0x1f84: rorx   ecx,esi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 28ULL);
x86_l_1f8a:
	/* 0x1f8a: xor    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f8c:
	/* 0x1f8c: add    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f8f:
	/* 0x1f8f: sub    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f92:
	/* 0x1f92: rorx   edi,ecx,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 26ULL);
x86_l_1f98:
	/* 0x1f98: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9b:
	/* 0x1f9b: add    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f9d:
	/* 0x1f9d: sub    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f9f:
	/* 0x1f9f: rorx   r8d,edi,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_32, 0, 24ULL);
x86_l_1fa5:
	/* 0x1fa5: xor    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fa8:
	/* 0x1fa8: add    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1faa:
	/* 0x1faa: sub    ecx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fad:
	/* 0x1fad: rorx   edx,r8d,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_32, 0, 16ULL);
x86_l_1fb3:
	/* 0x1fb3: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb5:
	/* 0x1fb5: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fb8:
	/* 0x1fb8: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fba:
	/* 0x1fba: rorx   esi,edx,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 13ULL);
x86_l_1fc0:
	/* 0x1fc0: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fc2:
	/* 0x1fc2: add    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fc5:
	/* 0x1fc5: sub    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fc8:
	/* 0x1fc8: rorx   ecx,esi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 28ULL);
x86_l_1fce:
	/* 0x1fce: xor    ecx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fd1:
	/* 0x1fd1: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1fd3:
	/* 0x1fd3: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_hash_init6_seed)));
x86_l_1fda:
	/* 0x1fda: add    edx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1fdc:
	/* 0x1fdc: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fde:
	/* 0x1fde: rorx   edi,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_1fe4:
	/* 0x1fe4: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1fe6:
	/* 0x1fe6: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fe8:
	/* 0x1fe8: rorx   edi,ecx,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 21ULL);
x86_l_1fee:
	/* 0x1fee: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ff0:
	/* 0x1ff0: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff2:
	/* 0x1ff2: rorx   edi,edx,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RDX, X86_WIDTH_32, 0, 7ULL);
x86_l_1ff8:
	/* 0x1ff8: sub    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1ffa:
	/* 0x1ffa: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ffc:
	/* 0x1ffc: rorx   edi,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_2002:
	/* 0x2002: sub    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2004:
	/* 0x2004: xor    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2006:
	/* 0x2006: rorx   edi,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_200c:
	/* 0x200c: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_200e:
	/* 0x200e: xor    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2010:
	/* 0x2010: rorx   edx,edx,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 18ULL);
x86_l_2016:
	/* 0x2016: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2018:
	/* 0x2018: xor    ecx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_201a:
	/* 0x201a: rorx   edx,esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RSI, X86_WIDTH_32, 0, 8ULL);
x86_l_2020:
	/* 0x2020: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2022:
	/* 0x2022: imul   rdx,rcx,0x2605a5 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 2491813ULL);
x86_l_2029:
	/* 0x2029: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_202d:
	/* 0x202d: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_202f:
	/* 0x202f: sub    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2031:
	/* 0x2031: shr    esi,1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 1ULL);
x86_l_2033:
	/* 0x2033: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2035:
	/* 0x2035: shr    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 14ULL);
x86_l_2038:
	/* 0x2038: imul   edx,esi,0x7fed */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RSI, X86_WIDTH_32, 32749ULL);
x86_l_203e:
	/* 0x203e: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2040:
	/* 0x2040: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2047:
	/* 0x2047: mov    ebp,DWORD PTR [rax+rcx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_204a:
	/* 0x204a: jmp    209b <tail_lb_ipv6+0x209b> */
	goto x86_l_209b;
x86_l_204c:
	/* 0x204c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_204e:
	/* 0x204e: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_2053:
	/* 0x2053: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_2056:
	/* 0x2056: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2058:
	/* 0x2058: call   rdx */
	X86_SIM_BPF_CALL_REG(X86_RDX);
x86_l_205a:
	/* 0x205a: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_205f:
	/* 0x205f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2061:
	/* 0x2061: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_2063:
	/* 0x2063: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2065:
	/* 0x2065: mov    WORD PTR [rsp+0xaa],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_206d:
	/* 0x206d: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_2074:
	/* 0x2074: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2078:
	/* 0x2078: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_207f:
	/* 0x207f: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2087:
	/* 0x2087: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_208c:
	/* 0x208c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208e:
	/* 0x208e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2091:
	/* 0x2091: je     2097 <tail_lb_ipv6+0x2097> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2097;
	}
x86_l_2093:
	/* 0x2093: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2095:
	/* 0x2095: jmp    209b <tail_lb_ipv6+0x209b> */
	goto x86_l_209b;
x86_l_2097:
	/* 0x2097: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_209b:
	/* 0x209b: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
	return 8351ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8351ULL: goto x86_l_209f;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8370ULL: goto x86_l_20b2;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8387ULL: goto x86_l_20c3;
	case 8396ULL: goto x86_l_20cc;
	case 8405ULL: goto x86_l_20d5;
	case 8414ULL: goto x86_l_20de;
	case 8423ULL: goto x86_l_20e7;
	case 8432ULL: goto x86_l_20f0;
	case 8438ULL: goto x86_l_20f6;
	case 8443ULL: goto x86_l_20fb;
	case 8448ULL: goto x86_l_2100;
	case 8452ULL: goto x86_l_2104;
	case 8454ULL: goto x86_l_2106;
	case 8459ULL: goto x86_l_210b;
	case 8466ULL: goto x86_l_2112;
	case 8470ULL: goto x86_l_2116;
	case 8472ULL: goto x86_l_2118;
	case 8479ULL: goto x86_l_211f;
	case 8482ULL: goto x86_l_2122;
	case 8485ULL: goto x86_l_2125;
	case 8487ULL: goto x86_l_2127;
	case 8494ULL: goto x86_l_212e;
	case 8497ULL: goto x86_l_2131;
	case 8502ULL: goto x86_l_2136;
	case 8509ULL: goto x86_l_213d;
	case 8512ULL: goto x86_l_2140;
	case 8515ULL: goto x86_l_2143;
	case 8521ULL: goto x86_l_2149;
	case 8525ULL: goto x86_l_214d;
	case 8527ULL: goto x86_l_214f;
	case 8533ULL: goto x86_l_2155;
	case 8538ULL: goto x86_l_215a;
	case 8540ULL: goto x86_l_215c;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8556ULL: goto x86_l_216c;
	case 8560ULL: goto x86_l_2170;
	case 8562ULL: goto x86_l_2172;
	case 8566ULL: goto x86_l_2176;
	case 8568ULL: goto x86_l_2178;
	case 8575ULL: goto x86_l_217f;
	case 8578ULL: goto x86_l_2182;
	case 8581ULL: goto x86_l_2185;
	case 8583ULL: goto x86_l_2187;
	case 8588ULL: goto x86_l_218c;
	case 8592ULL: goto x86_l_2190;
	case 8594ULL: goto x86_l_2192;
	case 8599ULL: goto x86_l_2197;
	case 8601ULL: goto x86_l_2199;
	case 8603ULL: goto x86_l_219b;
	case 8607ULL: goto x86_l_219f;
	case 8609ULL: goto x86_l_21a1;
	case 8614ULL: goto x86_l_21a6;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8622ULL: goto x86_l_21ae;
	case 8632ULL: goto x86_l_21b8;
	case 8635ULL: goto x86_l_21bb;
	case 8640ULL: goto x86_l_21c0;
	case 8644ULL: goto x86_l_21c4;
	case 8648ULL: goto x86_l_21c8;
	case 8651ULL: goto x86_l_21cb;
	case 8653ULL: goto x86_l_21cd;
	case 8657ULL: goto x86_l_21d1;
	case 8662ULL: goto x86_l_21d6;
	case 8666ULL: goto x86_l_21da;
	case 8668ULL: goto x86_l_21dc;
	case 8672ULL: goto x86_l_21e0;
	case 8674ULL: goto x86_l_21e2;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8687ULL: goto x86_l_21ef;
	case 8691ULL: goto x86_l_21f3;
	case 8693ULL: goto x86_l_21f5;
	case 8699ULL: goto x86_l_21fb;
	case 8707ULL: goto x86_l_2203;
	case 8710ULL: goto x86_l_2206;
	case 8712ULL: goto x86_l_2208;
	case 8715ULL: goto x86_l_220b;
	case 8717ULL: goto x86_l_220d;
	case 8719ULL: goto x86_l_220f;
	case 8721ULL: goto x86_l_2211;
	case 8725ULL: goto x86_l_2215;
	case 8729ULL: goto x86_l_2219;
	case 8736ULL: goto x86_l_2220;
	case 8738ULL: goto x86_l_2222;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8750ULL: goto x86_l_222e;
	case 8759ULL: goto x86_l_2237;
	case 8761ULL: goto x86_l_2239;
	case 8764ULL: goto x86_l_223c;
	case 8767ULL: goto x86_l_223f;
	case 8772ULL: goto x86_l_2244;
	case 8777ULL: goto x86_l_2249;
	case 8782ULL: goto x86_l_224e;
	case 8787ULL: goto x86_l_2253;
	case 8789ULL: goto x86_l_2255;
	case 8791ULL: goto x86_l_2257;
	case 8793ULL: goto x86_l_2259;
	case 8799ULL: goto x86_l_225f;
	case 8804ULL: goto x86_l_2264;
	case 8808ULL: goto x86_l_2268;
	case 8813ULL: goto x86_l_226d;
	case 8817ULL: goto x86_l_2271;
	case 8823ULL: goto x86_l_2277;
	case 8830ULL: goto x86_l_227e;
	case 8833ULL: goto x86_l_2281;
	case 8835ULL: goto x86_l_2283;
	case 8840ULL: goto x86_l_2288;
	case 8842ULL: goto x86_l_228a;
	case 8844ULL: goto x86_l_228c;
	case 8848ULL: goto x86_l_2290;
	case 8850ULL: goto x86_l_2292;
	case 8855ULL: goto x86_l_2297;
	case 8857ULL: goto x86_l_2299;
	case 8859ULL: goto x86_l_229b;
	case 8863ULL: goto x86_l_229f;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8881ULL: goto x86_l_22b1;
	case 8885ULL: goto x86_l_22b5;
	case 8894ULL: goto x86_l_22be;
	case 8903ULL: goto x86_l_22c7;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8921ULL: goto x86_l_22d9;
	case 8926ULL: goto x86_l_22de;
	case 8931ULL: goto x86_l_22e3;
	case 8933ULL: goto x86_l_22e5;
	case 8941ULL: goto x86_l_22ed;
	case 8945ULL: goto x86_l_22f1;
	case 8952ULL: goto x86_l_22f8;
	case 8963ULL: goto x86_l_2303;
	case 8971ULL: goto x86_l_230b;
	case 8976ULL: goto x86_l_2310;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9009ULL: goto x86_l_2331;
	case 9014ULL: goto x86_l_2336;
	case 9016ULL: goto x86_l_2338;
	case 9018ULL: goto x86_l_233a;
	case 9026ULL: goto x86_l_2342;
	case 9035ULL: goto x86_l_234b;
	case 9044ULL: goto x86_l_2354;
	case 9047ULL: goto x86_l_2357;
	case 9051ULL: goto x86_l_235b;
	case 9056ULL: goto x86_l_2360;
	case 9061ULL: goto x86_l_2365;
	case 9066ULL: goto x86_l_236a;
	case 9073ULL: goto x86_l_2371;
	case 9078ULL: goto x86_l_2376;
	case 9083ULL: goto x86_l_237b;
	case 9085ULL: goto x86_l_237d;
	case 9090ULL: goto x86_l_2382;
	case 9094ULL: goto x86_l_2386;
	case 9097ULL: goto x86_l_2389;
	case 9099ULL: goto x86_l_238b;
	case 9102ULL: goto x86_l_238e;
	case 9107ULL: goto x86_l_2393;
	case 9117ULL: goto x86_l_239d;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9131ULL: goto x86_l_23ab;
	case 9137ULL: goto x86_l_23b1;
	case 9139ULL: goto x86_l_23b3;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9157ULL: goto x86_l_23c5;
	case 9163ULL: goto x86_l_23cb;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9178ULL: goto x86_l_23da;
	case 9183ULL: goto x86_l_23df;
	case 9188ULL: goto x86_l_23e4;
	case 9195ULL: goto x86_l_23eb;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9207ULL: goto x86_l_23f7;
	case 9212ULL: goto x86_l_23fc;
	case 9217ULL: goto x86_l_2401;
	case 9220ULL: goto x86_l_2404;
	case 9222ULL: goto x86_l_2406;
	case 9227ULL: goto x86_l_240b;
	case 9229ULL: goto x86_l_240d;
	case 9236ULL: goto x86_l_2414;
	case 9239ULL: goto x86_l_2417;
	case 9247ULL: goto x86_l_241f;
	case 9249ULL: goto x86_l_2421;
	case 9252ULL: goto x86_l_2424;
	case 9255ULL: goto x86_l_2427;
	case 9257ULL: goto x86_l_2429;
	case 9262ULL: goto x86_l_242e;
	case 9265ULL: goto x86_l_2431;
	case 9267ULL: goto x86_l_2433;
	case 9270ULL: goto x86_l_2436;
	case 9272ULL: goto x86_l_2438;
	case 9275ULL: goto x86_l_243b;
	case 9277ULL: goto x86_l_243d;
	case 9283ULL: goto x86_l_2443;
	case 9285ULL: goto x86_l_2445;
	case 9291ULL: goto x86_l_244b;
	case 9294ULL: goto x86_l_244e;
	case 9305ULL: goto x86_l_2459;
	case 9307ULL: goto x86_l_245b;
	case 9313ULL: goto x86_l_2461;
	case 9316ULL: goto x86_l_2464;
	case 9318ULL: goto x86_l_2466;
	case 9321ULL: goto x86_l_2469;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9333ULL: goto x86_l_2475;
	case 9339ULL: goto x86_l_247b;
	case 9343ULL: goto x86_l_247f;
	case 9346ULL: goto x86_l_2482;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9368ULL: goto x86_l_2498;
	case 9373ULL: goto x86_l_249d;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9387ULL: goto x86_l_24ab;
	case 9397ULL: goto x86_l_24b5;
	case 9402ULL: goto x86_l_24ba;
	case 9408ULL: goto x86_l_24c0;
	case 9413ULL: goto x86_l_24c5;
	case 9415ULL: goto x86_l_24c7;
	case 9421ULL: goto x86_l_24cd;
	case 9429ULL: goto x86_l_24d5;
	case 9435ULL: goto x86_l_24db;
	case 9439ULL: goto x86_l_24df;
	case 9441ULL: goto x86_l_24e1;
	case 9444ULL: goto x86_l_24e4;
	case 9448ULL: goto x86_l_24e8;
	case 9452ULL: goto x86_l_24ec;
	case 9456ULL: goto x86_l_24f0;
	case 9461ULL: goto x86_l_24f5;
	case 9464ULL: goto x86_l_24f8;
	case 9470ULL: goto x86_l_24fe;
	case 9473ULL: goto x86_l_2501;
	case 9476ULL: goto x86_l_2504;
	case 9481ULL: goto x86_l_2509;
	case 9485ULL: goto x86_l_250d;
	case 9489ULL: goto x86_l_2511;
	case 9493ULL: goto x86_l_2515;
	case 9498ULL: goto x86_l_251a;
	case 9501ULL: goto x86_l_251d;
	case 9507ULL: goto x86_l_2523;
	case 9510ULL: goto x86_l_2526;
	case 9518ULL: goto x86_l_252e;
	case 9520ULL: goto x86_l_2530;
	case 9524ULL: goto x86_l_2534;
	case 9526ULL: goto x86_l_2536;
	case 9534ULL: goto x86_l_253e;
	case 9536ULL: goto x86_l_2540;
	case 9543ULL: goto x86_l_2547;
	case 9545ULL: goto x86_l_2549;
	case 9547ULL: goto x86_l_254b;
	case 9550ULL: goto x86_l_254e;
	case 9553ULL: goto x86_l_2551;
	case 9555ULL: goto x86_l_2553;
	case 9557ULL: goto x86_l_2555;
	case 9560ULL: goto x86_l_2558;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9568ULL: goto x86_l_2560;
	case 9571ULL: goto x86_l_2563;
	case 9573ULL: goto x86_l_2565;
	case 9575ULL: goto x86_l_2567;
	case 9578ULL: goto x86_l_256a;
	case 9580ULL: goto x86_l_256c;
	case 9584ULL: goto x86_l_2570;
	case 9586ULL: goto x86_l_2572;
	case 9591ULL: goto x86_l_2577;
	case 9594ULL: goto x86_l_257a;
	case 9602ULL: goto x86_l_2582;
	case 9605ULL: goto x86_l_2585;
	case 9608ULL: goto x86_l_2588;
	case 9617ULL: goto x86_l_2591;
	case 9619ULL: goto x86_l_2593;
	case 9624ULL: goto x86_l_2598;
	case 9628ULL: goto x86_l_259c;
	case 9634ULL: goto x86_l_25a2;
	case 9639ULL: goto x86_l_25a7;
	case 9644ULL: goto x86_l_25ac;
	case 9649ULL: goto x86_l_25b1;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9669ULL: goto x86_l_25c5;
	case 9674ULL: goto x86_l_25ca;
	case 9679ULL: goto x86_l_25cf;
	case 9684ULL: goto x86_l_25d4;
	case 9688ULL: goto x86_l_25d8;
	case 9694ULL: goto x86_l_25de;
	case 9701ULL: goto x86_l_25e5;
	case 9706ULL: goto x86_l_25ea;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9716ULL: goto x86_l_25f4;
	case 9719ULL: goto x86_l_25f7;
	case 9722ULL: goto x86_l_25fa;
	case 9726ULL: goto x86_l_25fe;
	case 9730ULL: goto x86_l_2602;
	case 9735ULL: goto x86_l_2607;
	case 9738ULL: goto x86_l_260a;
	case 9744ULL: goto x86_l_2610;
	case 9747ULL: goto x86_l_2613;
	case 9750ULL: goto x86_l_2616;
	case 9752ULL: goto x86_l_2618;
	case 9756ULL: goto x86_l_261c;
	case 9764ULL: goto x86_l_2624;
	case 9768ULL: goto x86_l_2628;
	case 9774ULL: goto x86_l_262e;
	case 9776ULL: goto x86_l_2630;
	case 9778ULL: goto x86_l_2632;
	case 9781ULL: goto x86_l_2635;
	case 9784ULL: goto x86_l_2638;
	case 9787ULL: goto x86_l_263b;
	case 9789ULL: goto x86_l_263d;
	case 9791ULL: goto x86_l_263f;
	case 9794ULL: goto x86_l_2642;
	case 9796ULL: goto x86_l_2644;
	case 9800ULL: goto x86_l_2648;
	case 9802ULL: goto x86_l_264a;
	case 9807ULL: goto x86_l_264f;
	case 9810ULL: goto x86_l_2652;
	case 9818ULL: goto x86_l_265a;
	case 9821ULL: goto x86_l_265d;
	case 9824ULL: goto x86_l_2660;
	case 9829ULL: goto x86_l_2665;
	case 9836ULL: goto x86_l_266c;
	case 9841ULL: goto x86_l_2671;
	case 9848ULL: goto x86_l_2678;
	case 9851ULL: goto x86_l_267b;
	case 9857ULL: goto x86_l_2681;
	case 9866ULL: goto x86_l_268a;
	case 9872ULL: goto x86_l_2690;
	case 9874ULL: goto x86_l_2692;
	case 9878ULL: goto x86_l_2696;
	case 9887ULL: goto x86_l_269f;
	case 9890ULL: goto x86_l_26a2;
	case 9899ULL: goto x86_l_26ab;
	case 9909ULL: goto x86_l_26b5;
	case 9917ULL: goto x86_l_26bd;
	case 9924ULL: goto x86_l_26c4;
	case 9932ULL: goto x86_l_26cc;
	case 9937ULL: goto x86_l_26d1;
	case 9939ULL: goto x86_l_26d3;
	case 9942ULL: goto x86_l_26d6;
	case 9944ULL: goto x86_l_26d8;
	case 9947ULL: goto x86_l_26db;
	case 9951ULL: goto x86_l_26df;
	case 9953ULL: goto x86_l_26e1;
	case 9958ULL: goto x86_l_26e6;
	case 9962ULL: goto x86_l_26ea;
	case 9967ULL: goto x86_l_26ef;
	case 9973ULL: goto x86_l_26f5;
	case 9978ULL: goto x86_l_26fa;
	case 9987ULL: goto x86_l_2703;
	case 9992ULL: goto x86_l_2708;
	case 9999ULL: goto x86_l_270f;
	case 10007ULL: goto x86_l_2717;
	case 10012ULL: goto x86_l_271c;
	case 10017ULL: goto x86_l_2721;
	case 10019ULL: goto x86_l_2723;
	case 10021ULL: goto x86_l_2725;
	case 10024ULL: goto x86_l_2728;
	case 10034ULL: goto x86_l_2732;
	case 10039ULL: goto x86_l_2737;
	case 10041ULL: goto x86_l_2739;
	default: return 0xffffffffffffffffULL;
	}
x86_l_209f:
	/* 0x209f: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_20a6:
	/* 0x20a6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20ab:
	/* 0x20ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b0:
	/* 0x20b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20b2:
	/* 0x20b2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_20b5:
	/* 0x20b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20b8:
	/* 0x20b8: je     2127 <tail_lb_ipv6+0x2127> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2127;
	}
x86_l_20ba:
	/* 0x20ba: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20c3:
	/* 0x20c3: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_20cc:
	/* 0x20cc: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_20d5:
	/* 0x20d5: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_20de:
	/* 0x20de: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_20e7:
	/* 0x20e7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_20f0:
	/* 0x20f0: movzx  r12d,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_20f6:
	/* 0x20f6: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_20fb:
	/* 0x20fb: mov    WORD PTR [rsp+0x2e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_2100:
	/* 0x2100: mov    DWORD PTR [rsp+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2104:
	/* 0x2104: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2106:
	/* 0x2106: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_210b:
	/* 0x210b: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2112:
	/* 0x2112: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2116:
	/* 0x2116: je     2167 <tail_lb_ipv6+0x2167> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2167;
	}
x86_l_2118:
	/* 0x2118: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_211f:
	/* 0x211f: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2122:
	/* 0x2122: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2125:
	/* 0x2125: jmp    216c <tail_lb_ipv6+0x216c> */
	goto x86_l_216c;
x86_l_2127:
	/* 0x2127: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_212e:
	/* 0x212e: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2131:
	/* 0x2131: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2136:
	/* 0x2136: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_213d:
	/* 0x213d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2140:
	/* 0x2140: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2143:
	/* 0x2143: jne    874 <tail_lb_ipv6+0x874> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2164ULL;
	}
x86_l_2149:
	/* 0x2149: movzx  eax,BYTE PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_214d:
	/* 0x214d: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_214f:
	/* 0x214f: je     26e1 <tail_lb_ipv6+0x26e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26e1;
	}
x86_l_2155:
	/* 0x2155: mov    ebp,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967138ULL);
x86_l_215a:
	/* 0x215a: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_215c:
	/* 0x215c: je     33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_2162:
	/* 0x2162: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	return 1012ULL;
x86_l_2167:
	/* 0x2167: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_216c:
	/* 0x216c: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_2170:
	/* 0x2170: jne    218c <tail_lb_ipv6+0x218c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_218c;
	}
x86_l_2172:
	/* 0x2172: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2176:
	/* 0x2176: je     2187 <tail_lb_ipv6+0x2187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2187;
	}
x86_l_2178:
	/* 0x2178: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_217f:
	/* 0x217f: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2182:
	/* 0x2182: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2185:
	/* 0x2185: jmp    218c <tail_lb_ipv6+0x218c> */
	goto x86_l_218c;
x86_l_2187:
	/* 0x2187: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_218c:
	/* 0x218c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2190:
	/* 0x2190: je     21a1 <tail_lb_ipv6+0x21a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21a1;
	}
x86_l_2192:
	/* 0x2192: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2197:
	/* 0x2197: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2199:
	/* 0x2199: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_219b:
	/* 0x219b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_219f:
	/* 0x219f: jmp    21c4 <tail_lb_ipv6+0x21c4> */
	goto x86_l_21c4;
x86_l_21a1:
	/* 0x21a1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_21a6:
	/* 0x21a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a8:
	/* 0x21a8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_21aa:
	/* 0x21aa: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_21ae:
	/* 0x21ae: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_21b8:
	/* 0x21b8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_21bb:
	/* 0x21bb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_21c0:
	/* 0x21c0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_21c4:
	/* 0x21c4: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_21c8:
	/* 0x21c8: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_21cb:
	/* 0x21cb: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_21cd:
	/* 0x21cd: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21d1:
	/* 0x21d1: movzx  edx,BYTE PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 50ULL);
x86_l_21d6:
	/* 0x21d6: mov    esi,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21da:
	/* 0x21da: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_21dc:
	/* 0x21dc: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e0:
	/* 0x21e0: je     21f5 <tail_lb_ipv6+0x21f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_21f5;
	}
x86_l_21e2:
	/* 0x21e2: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_21e9:
	/* 0x21e9: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21eb:
	/* 0x21eb: lea    r8d,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_21ef:
	/* 0x21ef: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_21f3:
	/* 0x21f3: jmp    21fb <tail_lb_ipv6+0x21fb> */
	goto x86_l_21fb;
x86_l_21f5:
	/* 0x21f5: mov    r8d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5ULL);
x86_l_21fb:
	/* 0x21fb: mov    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2203:
	/* 0x2203: add    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2206:
	/* 0x2206: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2208:
	/* 0x2208: cmp    r8d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_220b:
	/* 0x220b: jb     2211 <tail_lb_ipv6+0x2211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2211;
	}
x86_l_220d:
	/* 0x220d: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_220f:
	/* 0x220f: je     2222 <tail_lb_ipv6+0x2222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2222;
	}
x86_l_2211:
	/* 0x2211: mov    BYTE PTR [rsp+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_2215:
	/* 0x2215: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2219:
	/* 0x2219: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2220:
	/* 0x2220: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2222:
	/* 0x2222: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2229:
	/* 0x2229: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222c:
	/* 0x222c: je     2244 <tail_lb_ipv6+0x2244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2244;
	}
x86_l_222e:
	/* 0x222e: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_2237:
	/* 0x2237: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2239:
	/* 0x2239: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_223c:
	/* 0x223c: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_223f:
	/* 0x223f: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2244:
	/* 0x2244: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2249:
	/* 0x2249: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_224e:
	/* 0x224e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2253:
	/* 0x2253: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2255:
	/* 0x2255: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2257:
	/* 0x2257: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2259:
	/* 0x2259: js     2dc0 <tail_lb_ipv6+0x2dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11712ULL;
	}
x86_l_225f:
	/* 0x225f: movzx  eax,BYTE PTR [rsp+0x77] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 119ULL);
x86_l_2264:
	/* 0x2264: mov    BYTE PTR [rsp+0x75],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 117ULL);
x86_l_2268:
	/* 0x2268: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_226d:
	/* 0x226d: test   BYTE PTR [rax+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_2271:
	/* 0x2271: je     233a <tail_lb_ipv6+0x233a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_233a;
	}
x86_l_2277:
	/* 0x2277: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_227e:
	/* 0x227e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2281:
	/* 0x2281: je     2292 <tail_lb_ipv6+0x2292> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2292;
	}
x86_l_2283:
	/* 0x2283: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2288:
	/* 0x2288: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_228a:
	/* 0x228a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_228c:
	/* 0x228c: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2290:
	/* 0x2290: jmp    22b5 <tail_lb_ipv6+0x22b5> */
	goto x86_l_22b5;
x86_l_2292:
	/* 0x2292: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2297:
	/* 0x2297: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2299:
	/* 0x2299: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_229b:
	/* 0x229b: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_229f:
	/* 0x229f: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_22a9:
	/* 0x22a9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_22ac:
	/* 0x22ac: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_22b1:
	/* 0x22b1: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_22b5:
	/* 0x22b5: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_22be:
	/* 0x22be: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_22c7:
	/* 0x22c7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_22d0:
	/* 0x22d0: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_22d5:
	/* 0x22d5: movzx  ecx,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_22d9:
	/* 0x22d9: mov    WORD PTR [rsp+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_22de:
	/* 0x22de: mov    BYTE PTR [rsp+0x1a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 111669149696ULL);
x86_l_22e3:
	/* 0x22e3: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22e5:
	/* 0x22e5: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_22ed:
	/* 0x22ed: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_22f1:
	/* 0x22f1: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_22f8:
	/* 0x22f8: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_2303:
	/* 0x2303: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_230b:
	/* 0x230b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2310:
	/* 0x2310: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2318:
	/* 0x2318: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_231d:
	/* 0x231d: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_2324:
	/* 0x2324: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2329:
	/* 0x2329: lea    rdx,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2331:
	/* 0x2331: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2336:
	/* 0x2336: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2338:
	/* 0x2338: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_233a:
	/* 0x233a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2342:
	/* 0x2342: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_234b:
	/* 0x234b: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2354:
	/* 0x2354: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2357:
	/* 0x2357: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235b:
	/* 0x235b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2360:
	/* 0x2360: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2365:
	/* 0x2365: mov    BYTE PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_236a:
	/* 0x236a: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_2371:
	/* 0x2371: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2376:
	/* 0x2376: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_237b:
	/* 0x237b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237d:
	/* 0x237d: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2382:
	/* 0x2382: movzx  ecx,BYTE PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2386:
	/* 0x2386: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2389:
	/* 0x2389: je     23b3 <tail_lb_ipv6+0x23b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23b3;
	}
x86_l_238b:
	/* 0x238b: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_238e:
	/* 0x238e: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2393:
	/* 0x2393: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_239d:
	/* 0x239d: jne    23cb <tail_lb_ipv6+0x23cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_23cb;
	}
x86_l_239f:
	/* 0x239f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23a2:
	/* 0x23a2: je     23cb <tail_lb_ipv6+0x23cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_23cb;
	}
x86_l_23a4:
	/* 0x23a4: movzx  ecx,BYTE PTR [rdi+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_23a8:
	/* 0x23a8: and    cl,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_23ab:
	/* 0x23ab: jne    2972 <tail_lb_ipv6+0x2972> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10610ULL;
	}
x86_l_23b1:
	/* 0x23b1: jmp    23cb <tail_lb_ipv6+0x23cb> */
	goto x86_l_23cb;
x86_l_23b3:
	/* 0x23b3: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_23b6:
	/* 0x23b6: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23bb:
	/* 0x23bb: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_23c5:
	/* 0x23c5: jne    aa <tail_lb_ipv6+0xaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 170ULL;
	}
x86_l_23cb:
	/* 0x23cb: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23d0:
	/* 0x23d0: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23d5:
	/* 0x23d5: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23da:
	/* 0x23da: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23df:
	/* 0x23df: movzx  ecx,WORD PTR [rsp+0x72] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 114ULL);
x86_l_23e4:
	/* 0x23e4: mov    DWORD PTR [rsp+0xc0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_23eb:
	/* 0x23eb: mov    rdi,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_23ef:
	/* 0x23ef: mov    QWORD PTR [rsp+0x58],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_23f4:
	/* 0x23f4: mov    rcx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23f7:
	/* 0x23f7: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23fc:
	/* 0x23fc: movzx  ecx,WORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_2401:
	/* 0x2401: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_2404:
	/* 0x2404: je     240b <tail_lb_ipv6+0x240b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240b;
	}
x86_l_2406:
	/* 0x2406: mov    WORD PTR [rsp+0x72],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 114ULL);
x86_l_240b:
	/* 0x240b: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_240d:
	/* 0x240d: mov    DWORD PTR [rsp+0xb0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2414:
	/* 0x2414: test   rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_2417:
	/* 0x2417: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_241f:
	/* 0x241f: je     2429 <tail_lb_ipv6+0x2429> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2429;
	}
x86_l_2421:
	/* 0x2421: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2424:
	/* 0x2424: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_2427:
	/* 0x2427: jmp    2464 <tail_lb_ipv6+0x2464> */
	goto x86_l_2464;
x86_l_2429:
	/* 0x2429: movzx  ecx,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_242e:
	/* 0x242e: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_2431:
	/* 0x2431: je     245b <tail_lb_ipv6+0x245b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_245b;
	}
x86_l_2433:
	/* 0x2433: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_2436:
	/* 0x2436: je     2445 <tail_lb_ipv6+0x2445> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2445;
	}
x86_l_2438:
	/* 0x2438: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_243b:
	/* 0x243b: jne    2421 <tail_lb_ipv6+0x2421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2421;
	}
x86_l_243d:
	/* 0x243d: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_2443:
	/* 0x2443: jmp    2461 <tail_lb_ipv6+0x2461> */
	goto x86_l_2461;
x86_l_2445:
	/* 0x2445: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_244b:
	/* 0x244b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_244e:
	/* 0x244e: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2459:
	/* 0x2459: jmp    2464 <tail_lb_ipv6+0x2464> */
	goto x86_l_2464;
x86_l_245b:
	/* 0x245b: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2461:
	/* 0x2461: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2464:
	/* 0x2464: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2466:
	/* 0x2466: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2469:
	/* 0x2469: lea    rsi,[rcx+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_246d:
	/* 0x246d: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_2472:
	/* 0x2472: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2475:
	/* 0x2475: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_247b:
	/* 0x247b: mov    QWORD PTR [rcx+0x2e],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_247f:
	/* 0x247f: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2482:
	/* 0x2482: mov    QWORD PTR [rcx+0x26],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2486:
	/* 0x2486: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_248b:
	/* 0x248b: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_2490:
	/* 0x2490: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2495:
	/* 0x2495: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2498:
	/* 0x2498: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_249d:
	/* 0x249d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24a0:
	/* 0x24a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a2:
	/* 0x24a2: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_24a5:
	/* 0x24a5: je     25ea <tail_lb_ipv6+0x25ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25ea;
	}
x86_l_24ab:
	/* 0x24ab: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_24b5:
	/* 0x24b5: test   QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24ba:
	/* 0x24ba: jne    2588 <tail_lb_ipv6+0x2588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2588;
	}
x86_l_24c0:
	/* 0x24c0: movzx  ecx,WORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_24c5:
	/* 0x24c5: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_24c7:
	/* 0x24c7: je     2588 <tail_lb_ipv6+0x2588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2588;
	}
x86_l_24cd:
	/* 0x24cd: cmp    WORD PTR [rsp+0xc0],cx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_24d5:
	/* 0x24d5: je     2588 <tail_lb_ipv6+0x2588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2588;
	}
x86_l_24db:
	/* 0x24db: lea    esi,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24df:
	/* 0x24df: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24e1:
	/* 0x24e1: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_24e4:
	/* 0x24e4: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_24e8:
	/* 0x24e8: lea    rdi,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_24ec:
	/* 0x24ec: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_24f0:
	/* 0x24f0: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_24f5:
	/* 0x24f5: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_24f8:
	/* 0x24f8: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_24fe:
	/* 0x24fe: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2501:
	/* 0x2501: mov    WORD PTR [rsi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2504:
	/* 0x2504: add    r12d,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 120ULL);
x86_l_2509:
	/* 0x2509: movzx  esi,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_250d:
	/* 0x250d: lea    rdi,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_2511:
	/* 0x2511: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2515:
	/* 0x2515: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_251a:
	/* 0x251a: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_251d:
	/* 0x251d: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_2523:
	/* 0x2523: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2526:
	/* 0x2526: cmp    BYTE PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_252e:
	/* 0x252e: jne    2536 <tail_lb_ipv6+0x2536> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2536;
	}
x86_l_2530:
	/* 0x2530: cmp    WORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2534:
	/* 0x2534: je     2588 <tail_lb_ipv6+0x2588> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2588;
	}
x86_l_2536:
	/* 0x2536: cmp    DWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_253e:
	/* 0x253e: je     254e <tail_lb_ipv6+0x254e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_254e;
	}
x86_l_2540:
	/* 0x2540: mov    edx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2547:
	/* 0x2547: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2549:
	/* 0x2549: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_254b:
	/* 0x254b: adc    ecx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_254e:
	/* 0x254e: movzx  edx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2551:
	/* 0x2551: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2553:
	/* 0x2553: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2555:
	/* 0x2555: setb   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_B);
x86_l_2558:
	/* 0x2558: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_255b:
	/* 0x255b: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_255d:
	/* 0x255d: movzx  edx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2560:
	/* 0x2560: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2563:
	/* 0x2563: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2565:
	/* 0x2565: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2567:
	/* 0x2567: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_256a:
	/* 0x256a: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_256c:
	/* 0x256c: cmp    dx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 65535ULL);
x86_l_2570:
	/* 0x2570: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2572:
	/* 0x2572: mov    ecx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65535ULL);
x86_l_2577:
	/* 0x2577: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_257a:
	/* 0x257a: cmp    BYTE PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2582:
	/* 0x2582: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_2585:
	/* 0x2585: mov    WORD PTR [rax],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2588:
	/* 0x2588: cmp    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2591:
	/* 0x2591: jne    25a2 <tail_lb_ipv6+0x25a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_25a2;
	}
x86_l_2593:
	/* 0x2593: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2598:
	/* 0x2598: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_259c:
	/* 0x259c: js     2aa7 <tail_lb_ipv6+0x2aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 10919ULL;
	}
x86_l_25a2:
	/* 0x25a2: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25a7:
	/* 0x25a7: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25ac:
	/* 0x25ac: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25b1:
	/* 0x25b1: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25b6:
	/* 0x25b6: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_25bb:
	/* 0x25bb: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_25c0:
	/* 0x25c0: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25c5:
	/* 0x25c5: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25ca:
	/* 0x25ca: rol    DWORD PTR [rsp+0x70],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 481036337168ULL);
x86_l_25cf:
	/* 0x25cf: movzx  ebp,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_25d4:
	/* 0x25d4: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_25d8:
	/* 0x25d8: je     2665 <tail_lb_ipv6+0x2665> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2665;
	}
x86_l_25de:
	/* 0x25de: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_25e5:
	/* 0x25e5: jmp    266c <tail_lb_ipv6+0x266c> */
	goto x86_l_266c;
x86_l_25ea:
	/* 0x25ea: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25ec:
	/* 0x25ec: mov    esi,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25ef:
	/* 0x25ef: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_25f4:
	/* 0x25f4: add    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_25f7:
	/* 0x25f7: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_25fa:
	/* 0x25fa: lea    rdi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_25fe:
	/* 0x25fe: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2602:
	/* 0x2602: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_2607:
	/* 0x2607: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_260a:
	/* 0x260a: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_2610:
	/* 0x2610: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2613:
	/* 0x2613: movzx  edx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2616:
	/* 0x2616: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2618:
	/* 0x2618: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_261c:
	/* 0x261c: or     sil,BYTE PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 176ULL);
x86_l_2624:
	/* 0x2624: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_2628:
	/* 0x2628: jne    24ab <tail_lb_ipv6+0x24ab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_24ab;
	}
x86_l_262e:
	/* 0x262e: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2630:
	/* 0x2630: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2632:
	/* 0x2632: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_2635:
	/* 0x2635: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2638:
	/* 0x2638: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_263b:
	/* 0x263b: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_263d:
	/* 0x263d: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_263f:
	/* 0x263f: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2642:
	/* 0x2642: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2644:
	/* 0x2644: cmp    dx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 65535ULL);
x86_l_2648:
	/* 0x2648: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_264a:
	/* 0x264a: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_264f:
	/* 0x264f: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_2652:
	/* 0x2652: cmp    BYTE PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_265a:
	/* 0x265a: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_265d:
	/* 0x265d: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2660:
	/* 0x2660: jmp    24ab <tail_lb_ipv6+0x24ab> */
	goto x86_l_24ab;
x86_l_2665:
	/* 0x2665: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_266c:
	/* 0x266c: mov    BYTE PTR [rsp+0x75],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_2671:
	/* 0x2671: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_2678:
	/* 0x2678: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_267b:
	/* 0x267b: je     2725 <tail_lb_ipv6+0x2725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2725;
	}
x86_l_2681:
	/* 0x2681: cmp    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_268a:
	/* 0x268a: je     2725 <tail_lb_ipv6+0x2725> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2725;
	}
x86_l_2690:
	/* 0x2690: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2692:
	/* 0x2692: mov    r14d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2696:
	/* 0x2696: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_269f:
	/* 0x269f: sub    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_26a2:
	/* 0x26a2: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_26ab:
	/* 0x26ab: movabs rax,0x6c02a30209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705289ULL);
x86_l_26b5:
	/* 0x26b5: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_26bd:
	/* 0x26bd: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_26c4:
	/* 0x26c4: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_26cc:
	/* 0x26cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26d1:
	/* 0x26d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d3:
	/* 0x26d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26d6:
	/* 0x26d6: je     26fa <tail_lb_ipv6+0x26fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26fa;
	}
x86_l_26d8:
	/* 0x26d8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_26db:
	/* 0x26db: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_26df:
	/* 0x26df: jmp    2725 <tail_lb_ipv6+0x2725> */
	goto x86_l_2725;
x86_l_26e1:
	/* 0x26e1: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26e6:
	/* 0x26e6: test   BYTE PTR [rax+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_26ea:
	/* 0x26ea: mov    ebp,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967138ULL);
x86_l_26ef:
	/* 0x26ef: je     33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_26f5:
	/* 0x26f5: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	return 1012ULL;
x86_l_26fa:
	/* 0x26fa: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2703:
	/* 0x2703: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2708:
	/* 0x2708: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_270f:
	/* 0x270f: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_2717:
	/* 0x2717: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_271c:
	/* 0x271c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2721:
	/* 0x2721: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2723:
	/* 0x2723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2725:
	/* 0x2725: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2728:
	/* 0x2728: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2732:
	/* 0x2732: test   QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2737:
	/* 0x2737: jne    278f <tail_lb_ipv6+0x278f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10127ULL;
	}
x86_l_2739:
	/* 0x2739: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
	return 10047ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10047ULL: goto x86_l_273f;
	case 10051ULL: goto x86_l_2743;
	case 10053ULL: goto x86_l_2745;
	case 10057ULL: goto x86_l_2749;
	case 10059ULL: goto x86_l_274b;
	case 10062ULL: goto x86_l_274e;
	case 10066ULL: goto x86_l_2752;
	case 10070ULL: goto x86_l_2756;
	case 10074ULL: goto x86_l_275a;
	case 10077ULL: goto x86_l_275d;
	case 10083ULL: goto x86_l_2763;
	case 10086ULL: goto x86_l_2766;
	case 10090ULL: goto x86_l_276a;
	case 10093ULL: goto x86_l_276d;
	case 10098ULL: goto x86_l_2772;
	case 10101ULL: goto x86_l_2775;
	case 10106ULL: goto x86_l_277a;
	case 10109ULL: goto x86_l_277d;
	case 10116ULL: goto x86_l_2784;
	case 10122ULL: goto x86_l_278a;
	case 10125ULL: goto x86_l_278d;
	case 10127ULL: goto x86_l_278f;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10140ULL: goto x86_l_279c;
	case 10143ULL: goto x86_l_279f;
	case 10145ULL: goto x86_l_27a1;
	case 10148ULL: goto x86_l_27a4;
	case 10150ULL: goto x86_l_27a6;
	case 10153ULL: goto x86_l_27a9;
	case 10157ULL: goto x86_l_27ad;
	case 10159ULL: goto x86_l_27af;
	case 10161ULL: goto x86_l_27b1;
	case 10166ULL: goto x86_l_27b6;
	case 10169ULL: goto x86_l_27b9;
	case 10171ULL: goto x86_l_27bb;
	case 10177ULL: goto x86_l_27c1;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10194ULL: goto x86_l_27d2;
	case 10201ULL: goto x86_l_27d9;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10212ULL: goto x86_l_27e4;
	case 10214ULL: goto x86_l_27e6;
	case 10221ULL: goto x86_l_27ed;
	case 10223ULL: goto x86_l_27ef;
	case 10230ULL: goto x86_l_27f6;
	case 10239ULL: goto x86_l_27ff;
	case 10248ULL: goto x86_l_2808;
	case 10257ULL: goto x86_l_2811;
	case 10266ULL: goto x86_l_281a;
	case 10275ULL: goto x86_l_2823;
	case 10280ULL: goto x86_l_2828;
	case 10285ULL: goto x86_l_282d;
	case 10293ULL: goto x86_l_2835;
	case 10302ULL: goto x86_l_283e;
	case 10311ULL: goto x86_l_2847;
	case 10318ULL: goto x86_l_284e;
	case 10325ULL: goto x86_l_2855;
	case 10329ULL: goto x86_l_2859;
	case 10331ULL: goto x86_l_285b;
	case 10338ULL: goto x86_l_2862;
	case 10342ULL: goto x86_l_2866;
	case 10346ULL: goto x86_l_286a;
	case 10348ULL: goto x86_l_286c;
	case 10354ULL: goto x86_l_2872;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10367ULL: goto x86_l_287f;
	case 10371ULL: goto x86_l_2883;
	case 10373ULL: goto x86_l_2885;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10388ULL: goto x86_l_2894;
	case 10390ULL: goto x86_l_2896;
	case 10396ULL: goto x86_l_289c;
	case 10400ULL: goto x86_l_28a0;
	case 10402ULL: goto x86_l_28a2;
	case 10407ULL: goto x86_l_28a7;
	case 10409ULL: goto x86_l_28a9;
	case 10411ULL: goto x86_l_28ab;
	case 10415ULL: goto x86_l_28af;
	case 10417ULL: goto x86_l_28b1;
	case 10422ULL: goto x86_l_28b6;
	case 10424ULL: goto x86_l_28b8;
	case 10426ULL: goto x86_l_28ba;
	case 10430ULL: goto x86_l_28be;
	case 10440ULL: goto x86_l_28c8;
	case 10443ULL: goto x86_l_28cb;
	case 10448ULL: goto x86_l_28d0;
	case 10452ULL: goto x86_l_28d4;
	case 10456ULL: goto x86_l_28d8;
	case 10459ULL: goto x86_l_28db;
	case 10462ULL: goto x86_l_28de;
	case 10467ULL: goto x86_l_28e3;
	case 10472ULL: goto x86_l_28e8;
	case 10476ULL: goto x86_l_28ec;
	case 10478ULL: goto x86_l_28ee;
	case 10482ULL: goto x86_l_28f2;
	case 10484ULL: goto x86_l_28f4;
	case 10491ULL: goto x86_l_28fb;
	case 10493ULL: goto x86_l_28fd;
	case 10496ULL: goto x86_l_2900;
	case 10499ULL: goto x86_l_2903;
	case 10501ULL: goto x86_l_2905;
	case 10506ULL: goto x86_l_290a;
	case 10508ULL: goto x86_l_290c;
	case 10510ULL: goto x86_l_290e;
	case 10512ULL: goto x86_l_2910;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10518ULL: goto x86_l_2916;
	case 10522ULL: goto x86_l_291a;
	case 10526ULL: goto x86_l_291e;
	case 10533ULL: goto x86_l_2925;
	case 10535ULL: goto x86_l_2927;
	case 10542ULL: goto x86_l_292e;
	case 10545ULL: goto x86_l_2931;
	case 10547ULL: goto x86_l_2933;
	case 10556ULL: goto x86_l_293c;
	case 10558ULL: goto x86_l_293e;
	case 10561ULL: goto x86_l_2941;
	case 10564ULL: goto x86_l_2944;
	case 10569ULL: goto x86_l_2949;
	case 10574ULL: goto x86_l_294e;
	case 10579ULL: goto x86_l_2953;
	case 10584ULL: goto x86_l_2958;
	case 10587ULL: goto x86_l_295b;
	case 10589ULL: goto x86_l_295d;
	case 10591ULL: goto x86_l_295f;
	case 10593ULL: goto x86_l_2961;
	case 10599ULL: goto x86_l_2967;
	case 10608ULL: goto x86_l_2970;
	case 10610ULL: goto x86_l_2972;
	case 10618ULL: goto x86_l_297a;
	case 10625ULL: goto x86_l_2981;
	case 10630ULL: goto x86_l_2986;
	case 10636ULL: goto x86_l_298c;
	case 10639ULL: goto x86_l_298f;
	case 10642ULL: goto x86_l_2992;
	case 10648ULL: goto x86_l_2998;
	case 10651ULL: goto x86_l_299b;
	case 10654ULL: goto x86_l_299e;
	case 10662ULL: goto x86_l_29a6;
	case 10669ULL: goto x86_l_29ad;
	case 10674ULL: goto x86_l_29b2;
	case 10677ULL: goto x86_l_29b5;
	case 10680ULL: goto x86_l_29b8;
	case 10686ULL: goto x86_l_29be;
	case 10689ULL: goto x86_l_29c1;
	case 10694ULL: goto x86_l_29c6;
	case 10703ULL: goto x86_l_29cf;
	case 10706ULL: goto x86_l_29d2;
	case 10709ULL: goto x86_l_29d5;
	case 10713ULL: goto x86_l_29d9;
	case 10718ULL: goto x86_l_29de;
	case 10721ULL: goto x86_l_29e1;
	case 10727ULL: goto x86_l_29e7;
	case 10731ULL: goto x86_l_29eb;
	case 10734ULL: goto x86_l_29ee;
	case 10740ULL: goto x86_l_29f4;
	case 10745ULL: goto x86_l_29f9;
	case 10750ULL: goto x86_l_29fe;
	case 10754ULL: goto x86_l_2a02;
	case 10758ULL: goto x86_l_2a06;
	case 10762ULL: goto x86_l_2a0a;
	case 10769ULL: goto x86_l_2a11;
	case 10774ULL: goto x86_l_2a16;
	case 10777ULL: goto x86_l_2a19;
	case 10779ULL: goto x86_l_2a1b;
	case 10782ULL: goto x86_l_2a1e;
	case 10784ULL: goto x86_l_2a20;
	case 10788ULL: goto x86_l_2a24;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10799ULL: goto x86_l_2a2f;
	case 10802ULL: goto x86_l_2a32;
	case 10804ULL: goto x86_l_2a34;
	case 10806ULL: goto x86_l_2a36;
	case 10813ULL: goto x86_l_2a3d;
	case 10818ULL: goto x86_l_2a42;
	case 10823ULL: goto x86_l_2a47;
	case 10826ULL: goto x86_l_2a4a;
	case 10828ULL: goto x86_l_2a4c;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10838ULL: goto x86_l_2a56;
	case 10843ULL: goto x86_l_2a5b;
	case 10847ULL: goto x86_l_2a5f;
	case 10849ULL: goto x86_l_2a61;
	case 10857ULL: goto x86_l_2a69;
	case 10864ULL: goto x86_l_2a70;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	case 10876ULL: goto x86_l_2a7c;
	case 10879ULL: goto x86_l_2a7f;
	case 10881ULL: goto x86_l_2a81;
	case 10888ULL: goto x86_l_2a88;
	case 10895ULL: goto x86_l_2a8f;
	case 10901ULL: goto x86_l_2a95;
	case 10906ULL: goto x86_l_2a9a;
	case 10909ULL: goto x86_l_2a9d;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10927ULL: goto x86_l_2aaf;
	case 10935ULL: goto x86_l_2ab7;
	case 10942ULL: goto x86_l_2abe;
	case 10947ULL: goto x86_l_2ac3;
	case 10953ULL: goto x86_l_2ac9;
	case 10956ULL: goto x86_l_2acc;
	case 10959ULL: goto x86_l_2acf;
	case 10961ULL: goto x86_l_2ad1;
	case 10963ULL: goto x86_l_2ad3;
	case 10971ULL: goto x86_l_2adb;
	case 10978ULL: goto x86_l_2ae2;
	case 10983ULL: goto x86_l_2ae7;
	case 10986ULL: goto x86_l_2aea;
	case 10989ULL: goto x86_l_2aed;
	case 10991ULL: goto x86_l_2aef;
	case 10999ULL: goto x86_l_2af7;
	case 11003ULL: goto x86_l_2afb;
	case 11011ULL: goto x86_l_2b03;
	case 11015ULL: goto x86_l_2b07;
	case 11022ULL: goto x86_l_2b0e;
	case 11028ULL: goto x86_l_2b14;
	case 11033ULL: goto x86_l_2b19;
	case 11036ULL: goto x86_l_2b1c;
	case 11041ULL: goto x86_l_2b21;
	case 11046ULL: goto x86_l_2b26;
	case 11051ULL: goto x86_l_2b2b;
	case 11056ULL: goto x86_l_2b30;
	case 11058ULL: goto x86_l_2b32;
	case 11060ULL: goto x86_l_2b34;
	case 11063ULL: goto x86_l_2b37;
	case 11069ULL: goto x86_l_2b3d;
	case 11076ULL: goto x86_l_2b44;
	case 11079ULL: goto x86_l_2b47;
	case 11081ULL: goto x86_l_2b49;
	case 11088ULL: goto x86_l_2b50;
	case 11092ULL: goto x86_l_2b54;
	case 11096ULL: goto x86_l_2b58;
	case 11098ULL: goto x86_l_2b5a;
	case 11100ULL: goto x86_l_2b5c;
	case 11105ULL: goto x86_l_2b61;
	case 11111ULL: goto x86_l_2b67;
	case 11115ULL: goto x86_l_2b6b;
	case 11117ULL: goto x86_l_2b6d;
	case 11120ULL: goto x86_l_2b70;
	case 11122ULL: goto x86_l_2b72;
	case 11125ULL: goto x86_l_2b75;
	case 11128ULL: goto x86_l_2b78;
	case 11130ULL: goto x86_l_2b7a;
	case 11135ULL: goto x86_l_2b7f;
	case 11137ULL: goto x86_l_2b81;
	case 11142ULL: goto x86_l_2b86;
	case 11148ULL: goto x86_l_2b8c;
	case 11152ULL: goto x86_l_2b90;
	case 11159ULL: goto x86_l_2b97;
	case 11162ULL: goto x86_l_2b9a;
	case 11164ULL: goto x86_l_2b9c;
	case 11171ULL: goto x86_l_2ba3;
	case 11175ULL: goto x86_l_2ba7;
	case 11179ULL: goto x86_l_2bab;
	case 11183ULL: goto x86_l_2baf;
	case 11186ULL: goto x86_l_2bb2;
	case 11190ULL: goto x86_l_2bb6;
	case 11197ULL: goto x86_l_2bbd;
	case 11200ULL: goto x86_l_2bc0;
	case 11202ULL: goto x86_l_2bc2;
	case 11207ULL: goto x86_l_2bc7;
	case 11209ULL: goto x86_l_2bc9;
	case 11211ULL: goto x86_l_2bcb;
	case 11215ULL: goto x86_l_2bcf;
	case 11217ULL: goto x86_l_2bd1;
	case 11222ULL: goto x86_l_2bd6;
	case 11224ULL: goto x86_l_2bd8;
	case 11226ULL: goto x86_l_2bda;
	case 11230ULL: goto x86_l_2bde;
	case 11240ULL: goto x86_l_2be8;
	case 11243ULL: goto x86_l_2beb;
	case 11248ULL: goto x86_l_2bf0;
	case 11252ULL: goto x86_l_2bf4;
	case 11255ULL: goto x86_l_2bf7;
	case 11259ULL: goto x86_l_2bfb;
	case 11264ULL: goto x86_l_2c00;
	case 11268ULL: goto x86_l_2c04;
	case 11272ULL: goto x86_l_2c08;
	case 11276ULL: goto x86_l_2c0c;
	case 11280ULL: goto x86_l_2c10;
	case 11287ULL: goto x86_l_2c17;
	case 11290ULL: goto x86_l_2c1a;
	case 11292ULL: goto x86_l_2c1c;
	case 11299ULL: goto x86_l_2c23;
	case 11301ULL: goto x86_l_2c25;
	case 11304ULL: goto x86_l_2c28;
	case 11307ULL: goto x86_l_2c2b;
	case 11309ULL: goto x86_l_2c2d;
	case 11314ULL: goto x86_l_2c32;
	case 11316ULL: goto x86_l_2c34;
	case 11320ULL: goto x86_l_2c38;
	case 11322ULL: goto x86_l_2c3a;
	case 11326ULL: goto x86_l_2c3e;
	case 11328ULL: goto x86_l_2c40;
	case 11330ULL: goto x86_l_2c42;
	case 11334ULL: goto x86_l_2c46;
	case 11336ULL: goto x86_l_2c48;
	case 11340ULL: goto x86_l_2c4c;
	case 11344ULL: goto x86_l_2c50;
	case 11348ULL: goto x86_l_2c54;
	case 11355ULL: goto x86_l_2c5b;
	case 11357ULL: goto x86_l_2c5d;
	case 11364ULL: goto x86_l_2c64;
	case 11367ULL: goto x86_l_2c67;
	case 11369ULL: goto x86_l_2c69;
	case 11374ULL: goto x86_l_2c6e;
	case 11376ULL: goto x86_l_2c70;
	case 11379ULL: goto x86_l_2c73;
	case 11382ULL: goto x86_l_2c76;
	case 11387ULL: goto x86_l_2c7b;
	case 11391ULL: goto x86_l_2c7f;
	case 11393ULL: goto x86_l_2c81;
	case 11397ULL: goto x86_l_2c85;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11410ULL: goto x86_l_2c92;
	case 11416ULL: goto x86_l_2c98;
	case 11423ULL: goto x86_l_2c9f;
	case 11428ULL: goto x86_l_2ca4;
	case 11433ULL: goto x86_l_2ca9;
	case 11440ULL: goto x86_l_2cb0;
	case 11445ULL: goto x86_l_2cb5;
	case 11451ULL: goto x86_l_2cbb;
	case 11458ULL: goto x86_l_2cc2;
	case 11462ULL: goto x86_l_2cc6;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11474ULL: goto x86_l_2cd2;
	case 11479ULL: goto x86_l_2cd7;
	case 11483ULL: goto x86_l_2cdb;
	case 11487ULL: goto x86_l_2cdf;
	case 11491ULL: goto x86_l_2ce3;
	case 11496ULL: goto x86_l_2ce8;
	case 11501ULL: goto x86_l_2ced;
	case 11508ULL: goto x86_l_2cf4;
	case 11510ULL: goto x86_l_2cf6;
	case 11512ULL: goto x86_l_2cf8;
	case 11518ULL: goto x86_l_2cfe;
	case 11525ULL: goto x86_l_2d05;
	case 11530ULL: goto x86_l_2d0a;
	case 11532ULL: goto x86_l_2d0c;
	case 11539ULL: goto x86_l_2d13;
	case 11541ULL: goto x86_l_2d15;
	case 11543ULL: goto x86_l_2d17;
	case 11547ULL: goto x86_l_2d1b;
	case 11551ULL: goto x86_l_2d1f;
	case 11553ULL: goto x86_l_2d21;
	case 11559ULL: goto x86_l_2d27;
	case 11563ULL: goto x86_l_2d2b;
	case 11566ULL: goto x86_l_2d2e;
	case 11571ULL: goto x86_l_2d33;
	case 11573ULL: goto x86_l_2d35;
	case 11578ULL: goto x86_l_2d3a;
	case 11580ULL: goto x86_l_2d3c;
	case 11582ULL: goto x86_l_2d3e;
	case 11586ULL: goto x86_l_2d42;
	case 11588ULL: goto x86_l_2d44;
	case 11593ULL: goto x86_l_2d49;
	case 11595ULL: goto x86_l_2d4b;
	case 11597ULL: goto x86_l_2d4d;
	case 11601ULL: goto x86_l_2d51;
	case 11611ULL: goto x86_l_2d5b;
	case 11614ULL: goto x86_l_2d5e;
	case 11619ULL: goto x86_l_2d63;
	case 11623ULL: goto x86_l_2d67;
	case 11626ULL: goto x86_l_2d6a;
	case 11630ULL: goto x86_l_2d6e;
	case 11635ULL: goto x86_l_2d73;
	case 11639ULL: goto x86_l_2d77;
	case 11643ULL: goto x86_l_2d7b;
	case 11648ULL: goto x86_l_2d80;
	case 11650ULL: goto x86_l_2d82;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_273f:
	/* 0x273f: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2743:
	/* 0x2743: jne    2792 <tail_lb_ipv6+0x2792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2792;
	}
x86_l_2745:
	/* 0x2745: add    r13d,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 26ULL);
x86_l_2749:
	/* 0x2749: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_274b:
	/* 0x274b: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_274e:
	/* 0x274e: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2752:
	/* 0x2752: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2756:
	/* 0x2756: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_275a:
	/* 0x275a: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_275d:
	/* 0x275d: ja     10d8 <tail_lb_ipv6+0x10d8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 4312ULL;
	}
x86_l_2763:
	/* 0x2763: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2766:
	/* 0x2766: movzx  r14d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_276a:
	/* 0x276a: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_276d:
	/* 0x276d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_2772:
	/* 0x2772: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2775:
	/* 0x2775: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_277a:
	/* 0x277a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_277d:
	/* 0x277d: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_2784:
	/* 0x2784: jne    2dd4 <tail_lb_ipv6+0x2dd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11732ULL;
	}
x86_l_278a:
	/* 0x278a: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_278d:
	/* 0x278d: jmp    2792 <tail_lb_ipv6+0x2792> */
	goto x86_l_2792;
x86_l_278f:
	/* 0x278f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2792:
	/* 0x2792: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2797:
	/* 0x2797: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_279c:
	/* 0x279c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_279f:
	/* 0x279f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a1:
	/* 0x27a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27a4:
	/* 0x27a4: je     27d2 <tail_lb_ipv6+0x27d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d2;
	}
x86_l_27a6:
	/* 0x27a6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_27a9:
	/* 0x27a9: movzx  eax,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_27ad:
	/* 0x27ad: test   al,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 32ULL);
x86_l_27af:
	/* 0x27af: je     27d2 <tail_lb_ipv6+0x27d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d2;
	}
x86_l_27b1:
	/* 0x27b1: movzx  ecx,WORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_27b6:
	/* 0x27b6: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_27b9:
	/* 0x27b9: je     27d2 <tail_lb_ipv6+0x27d2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27d2;
	}
x86_l_27bb:
	/* 0x27bb: cmp    WORD PTR [rsp+0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934592ULL);
x86_l_27c1:
	/* 0x27c1: je     2b30 <tail_lb_ipv6+0x2b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b30;
	}
x86_l_27c7:
	/* 0x27c7: cmp    cx,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_27cc:
	/* 0x27cc: je     2b30 <tail_lb_ipv6+0x2b30> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b30;
	}
x86_l_27d2:
	/* 0x27d2: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_27d9:
	/* 0x27d9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27db:
	/* 0x27db: movzx  ebp,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_27e0:
	/* 0x27e0: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_27e4:
	/* 0x27e4: jne    27ef <tail_lb_ipv6+0x27ef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_27ef;
	}
x86_l_27e6:
	/* 0x27e6: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_27ed:
	/* 0x27ed: jmp    27f6 <tail_lb_ipv6+0x27f6> */
	goto x86_l_27f6;
x86_l_27ef:
	/* 0x27ef: mov    r15,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_27f6:
	/* 0x27f6: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_27ff:
	/* 0x27ff: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2808:
	/* 0x2808: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2811:
	/* 0x2811: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_281a:
	/* 0x281a: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2823:
	/* 0x2823: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2828:
	/* 0x2828: mov    WORD PTR [rsp+0x2e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_282d:
	/* 0x282d: mov    DWORD PTR [rsp+0x34],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299402ULL);
x86_l_2835:
	/* 0x2835: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_283e:
	/* 0x283e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2847:
	/* 0x2847: mov    WORD PTR [rsp+0x2c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561056ULL);
x86_l_284e:
	/* 0x284e: mov    r14,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2855:
	/* 0x2855: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2859:
	/* 0x2859: je     286c <tail_lb_ipv6+0x286c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_286c;
	}
x86_l_285b:
	/* 0x285b: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2862:
	/* 0x2862: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2866:
	/* 0x2866: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_286a:
	/* 0x286a: jmp    2872 <tail_lb_ipv6+0x2872> */
	goto x86_l_2872;
x86_l_286c:
	/* 0x286c: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2872:
	/* 0x2872: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2876:
	/* 0x2876: jne    289c <tail_lb_ipv6+0x289c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_289c;
	}
x86_l_2878:
	/* 0x2878: mov    WORD PTR [rsp+0x2c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561056ULL);
x86_l_287f:
	/* 0x287f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2883:
	/* 0x2883: je     2896 <tail_lb_ipv6+0x2896> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2896;
	}
x86_l_2885:
	/* 0x2885: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_288c:
	/* 0x288c: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2890:
	/* 0x2890: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2894:
	/* 0x2894: jmp    289c <tail_lb_ipv6+0x289c> */
	goto x86_l_289c;
x86_l_2896:
	/* 0x2896: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_289c:
	/* 0x289c: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28a0:
	/* 0x28a0: je     28b1 <tail_lb_ipv6+0x28b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28b1;
	}
x86_l_28a2:
	/* 0x28a2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_28a7:
	/* 0x28a7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a9:
	/* 0x28a9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28ab:
	/* 0x28ab: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_28af:
	/* 0x28af: jmp    28d4 <tail_lb_ipv6+0x28d4> */
	goto x86_l_28d4;
x86_l_28b1:
	/* 0x28b1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_28b6:
	/* 0x28b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b8:
	/* 0x28b8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_28ba:
	/* 0x28ba: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_28be:
	/* 0x28be: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_28c8:
	/* 0x28c8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_28cb:
	/* 0x28cb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_28d0:
	/* 0x28d0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_28d4:
	/* 0x28d4: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_28d8:
	/* 0x28d8: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_28db:
	/* 0x28db: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28de:
	/* 0x28de: mov    DWORD PTR [rsp+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_28e3:
	/* 0x28e3: movzx  edx,BYTE PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 50ULL);
x86_l_28e8:
	/* 0x28e8: mov    esi,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28ec:
	/* 0x28ec: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_28ee:
	/* 0x28ee: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f2:
	/* 0x28f2: je     2905 <tail_lb_ipv6+0x2905> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2905;
	}
x86_l_28f4:
	/* 0x28f4: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_28fb:
	/* 0x28fb: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28fd:
	/* 0x28fd: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_2900:
	/* 0x2900: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2903:
	/* 0x2903: jmp    290a <tail_lb_ipv6+0x290a> */
	goto x86_l_290a;
x86_l_2905:
	/* 0x2905: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_290a:
	/* 0x290a: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_290c:
	/* 0x290c: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_290e:
	/* 0x290e: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_2910:
	/* 0x2910: jb     2916 <tail_lb_ipv6+0x2916> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2916;
	}
x86_l_2912:
	/* 0x2912: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_2914:
	/* 0x2914: je     2927 <tail_lb_ipv6+0x2927> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2927;
	}
x86_l_2916:
	/* 0x2916: mov    BYTE PTR [rsp+0x32],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_291a:
	/* 0x291a: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_291e:
	/* 0x291e: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2925:
	/* 0x2925: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2927:
	/* 0x2927: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_292e:
	/* 0x292e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2931:
	/* 0x2931: je     2949 <tail_lb_ipv6+0x2949> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2949;
	}
x86_l_2933:
	/* 0x2933: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_293c:
	/* 0x293c: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_293e:
	/* 0x293e: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2941:
	/* 0x2941: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2944:
	/* 0x2944: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2949:
	/* 0x2949: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_294e:
	/* 0x294e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2953:
	/* 0x2953: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2958:
	/* 0x2958: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_295b:
	/* 0x295b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_295d:
	/* 0x295d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_295f:
	/* 0x295f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2961:
	/* 0x2961: js     2dc0 <tail_lb_ipv6+0x2dc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 11712ULL;
	}
x86_l_2967:
	/* 0x2967: cmp    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2970:
	/* 0x2970: je     29c6 <tail_lb_ipv6+0x29c6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_29c6;
	}
x86_l_2972:
	/* 0x2972: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_297a:
	/* 0x297a: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2981:
	/* 0x2981: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2986:
	/* 0x2986: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_298c:
	/* 0x298c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_298f:
	/* 0x298f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2992:
	/* 0x2992: je     2b26 <tail_lb_ipv6+0x2b26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b26;
	}
x86_l_2998:
	/* 0x2998: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_299b:
	/* 0x299b: or     ebp,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_299e:
	/* 0x299e: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_29a6:
	/* 0x29a6: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_29ad:
	/* 0x29ad: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29b2:
	/* 0x29b2: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_29b5:
	/* 0x29b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29b8:
	/* 0x29b8: je     33 <tail_lb_ipv6+0x33> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 51ULL;
	}
x86_l_29be:
	/* 0x29be: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_29c1:
	/* 0x29c1: jmp    33 <tail_lb_ipv6+0x33> */
	return 51ULL;
x86_l_29c6:
	/* 0x29c6: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_29cf:
	/* 0x29cf: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29d2:
	/* 0x29d2: mov    eax,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29d5:
	/* 0x29d5: lea    rcx,[r14+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_29d9:
	/* 0x29d9: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_29de:
	/* 0x29de: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_29e1:
	/* 0x29e1: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_29e7:
	/* 0x29e7: lea    rcx,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29eb:
	/* 0x29eb: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_29ee:
	/* 0x29ee: ja     af <tail_lb_ipv6+0xaf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 175ULL;
	}
x86_l_29f4:
	/* 0x29f4: movzx  eax,WORD PTR [r14+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_29f9:
	/* 0x29f9: mov    WORD PTR [rsp+0xc],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_29fe:
	/* 0x29fe: mov    eax,DWORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2a02:
	/* 0x2a02: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a06:
	/* 0x2a06: add    r14,0x16 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 22ULL);
x86_l_2a0a:
	/* 0x2a0a: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_2a11:
	/* 0x2a11: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a16:
	/* 0x2a16: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2a19:
	/* 0x2a19: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a1b:
	/* 0x2a1b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a1e:
	/* 0x2a1e: je     2a36 <tail_lb_ipv6+0x2a36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a36;
	}
x86_l_2a20:
	/* 0x2a20: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a24:
	/* 0x2a24: xor    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 0ULL);
x86_l_2a26:
	/* 0x2a26: movzx  edx,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_2a2b:
	/* 0x2a2b: xor    dx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 4ULL);
x86_l_2a2f:
	/* 0x2a2f: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2a32:
	/* 0x2a32: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2a34:
	/* 0x2a34: je     2a56 <tail_lb_ipv6+0x2a56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a56;
	}
x86_l_2a36:
	/* 0x2a36: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_2a3d:
	/* 0x2a3d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a42:
	/* 0x2a42: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a47:
	/* 0x2a47: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2a4a:
	/* 0x2a4a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a4c:
	/* 0x2a4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4e:
	/* 0x2a4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a50:
	/* 0x2a50: js     2b5a <tail_lb_ipv6+0x2b5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2b5a;
	}
x86_l_2a56:
	/* 0x2a56: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2a5b:
	/* 0x2a5b: cmp    BYTE PTR [rax+0x9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705664ULL);
x86_l_2a5f:
	/* 0x2a5f: js     2aa7 <tail_lb_ipv6+0x2aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2aa7;
	}
x86_l_2a61:
	/* 0x2a61: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2a69:
	/* 0x2a69: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2a70:
	/* 0x2a70: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a75:
	/* 0x2a75: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7a:
	/* 0x2a7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7c:
	/* 0x2a7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a7f:
	/* 0x2a7f: je     2a88 <tail_lb_ipv6+0x2a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a88;
	}
x86_l_2a81:
	/* 0x2a81: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2a88:
	/* 0x2a88: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2a8f:
	/* 0x2a8f: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_2a95:
	/* 0x2a95: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2a9a:
	/* 0x2a9a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a9d:
	/* 0x2a9d: mov    edx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2aa2:
	/* 0x2aa2: jmp    1064 <tail_lb_ipv6+0x1064> */
	return 4196ULL;
x86_l_2aa7:
	/* 0x2aa7: movzx  ebp,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_2aaf:
	/* 0x2aaf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2ab7:
	/* 0x2ab7: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2abe:
	/* 0x2abe: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ac3:
	/* 0x2ac3: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2ac9:
	/* 0x2ac9: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2acc:
	/* 0x2acc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2acf:
	/* 0x2acf: je     2ad3 <tail_lb_ipv6+0x2ad3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ad3;
	}
x86_l_2ad1:
	/* 0x2ad1: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ad3:
	/* 0x2ad3: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2adb:
	/* 0x2adb: mov    rdi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_2ae2:
	/* 0x2ae2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ae7:
	/* 0x2ae7: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_2aea:
	/* 0x2aea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2aed:
	/* 0x2aed: je     2b07 <tail_lb_ipv6+0x2b07> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b07;
	}
x86_l_2aef:
	/* 0x2aef: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2af7:
	/* 0x2af7: mov    QWORD PTR [rax+0xc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2afb:
	/* 0x2afb: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2b03:
	/* 0x2b03: mov    QWORD PTR [rax+0x4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b07:
	/* 0x2b07: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2b0e:
	/* 0x2b0e: mov    r15d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 22ULL);
x86_l_2b14:
	/* 0x2b14: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b19:
	/* 0x2b19: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b1c:
	/* 0x2b1c: mov    edx,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 22ULL);
x86_l_2b21:
	/* 0x2b21: jmp    1064 <tail_lb_ipv6+0x1064> */
	return 4196ULL;
x86_l_2b26:
	/* 0x2b26: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2b2b:
	/* 0x2b2b: jmp    299e <tail_lb_ipv6+0x299e> */
	goto x86_l_299e;
x86_l_2b30:
	/* 0x2b30: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2b32:
	/* 0x2b32: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2b34:
	/* 0x2b34: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_2b37:
	/* 0x2b37: je     2c5d <tail_lb_ipv6+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c5d;
	}
x86_l_2b3d:
	/* 0x2b3d: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2b44:
	/* 0x2b44: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b47:
	/* 0x2b47: je     2b61 <tail_lb_ipv6+0x2b61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b61;
	}
x86_l_2b49:
	/* 0x2b49: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2b50:
	/* 0x2b50: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2b54:
	/* 0x2b54: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2b58:
	/* 0x2b58: jmp    2b67 <tail_lb_ipv6+0x2b67> */
	goto x86_l_2b67;
x86_l_2b5a:
	/* 0x2b5a: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_2b5c:
	/* 0x2b5c: jmp    af <tail_lb_ipv6+0xaf> */
	return 175ULL;
x86_l_2b61:
	/* 0x2b61: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_2b67:
	/* 0x2b67: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2b6b:
	/* 0x2b6b: jne    2bab <tail_lb_ipv6+0x2bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2bab;
	}
x86_l_2b6d:
	/* 0x2b6d: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_2b70:
	/* 0x2b70: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2b72:
	/* 0x2b72: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2b75:
	/* 0x2b75: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2b78:
	/* 0x2b78: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2b7a:
	/* 0x2b7a: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b7f:
	/* 0x2b7f: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_2b81:
	/* 0x2b81: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2b86:
	/* 0x2b86: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_2b8c:
	/* 0x2b8c: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2b90:
	/* 0x2b90: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2b97:
	/* 0x2b97: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b9a:
	/* 0x2b9a: je     2bab <tail_lb_ipv6+0x2bab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bab;
	}
x86_l_2b9c:
	/* 0x2b9c: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2ba3:
	/* 0x2ba3: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2ba7:
	/* 0x2ba7: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2bab:
	/* 0x2bab: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2baf:
	/* 0x2baf: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2bb2:
	/* 0x2bb2: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2bbd:
	/* 0x2bbd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bc0:
	/* 0x2bc0: je     2bd1 <tail_lb_ipv6+0x2bd1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd1;
	}
x86_l_2bc2:
	/* 0x2bc2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2bc7:
	/* 0x2bc7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bc9:
	/* 0x2bc9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2bcb:
	/* 0x2bcb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2bcf:
	/* 0x2bcf: jmp    2bf4 <tail_lb_ipv6+0x2bf4> */
	goto x86_l_2bf4;
x86_l_2bd1:
	/* 0x2bd1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2bd6:
	/* 0x2bd6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bd8:
	/* 0x2bd8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2bda:
	/* 0x2bda: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2bde:
	/* 0x2bde: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2be8:
	/* 0x2be8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2beb:
	/* 0x2beb: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2bf0:
	/* 0x2bf0: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2bf4:
	/* 0x2bf4: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2bf7:
	/* 0x2bf7: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2bfb:
	/* 0x2bfb: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2c00:
	/* 0x2c00: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c04:
	/* 0x2c04: mov    esi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c08:
	/* 0x2c08: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2c0c:
	/* 0x2c0c: mov    DWORD PTR [rsp+0x48],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c10:
	/* 0x2c10: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2c17:
	/* 0x2c17: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c1a:
	/* 0x2c1a: je     2c2d <tail_lb_ipv6+0x2c2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c2d;
	}
x86_l_2c1c:
	/* 0x2c1c: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2c23:
	/* 0x2c23: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c25:
	/* 0x2c25: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2c28:
	/* 0x2c28: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2c2b:
	/* 0x2c2b: jmp    2c32 <tail_lb_ipv6+0x2c32> */
	goto x86_l_2c32;
x86_l_2c2d:
	/* 0x2c2d: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2c32:
	/* 0x2c32: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2c34:
	/* 0x2c34: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c38:
	/* 0x2c38: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2c3a:
	/* 0x2c3a: mov    DWORD PTR [rsp+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c3e:
	/* 0x2c3e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2c40:
	/* 0x2c40: jb     2c48 <tail_lb_ipv6+0x2c48> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2c48;
	}
x86_l_2c42:
	/* 0x2c42: cmp    cl,BYTE PTR [rsp+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 72ULL);
x86_l_2c46:
	/* 0x2c46: je     2c5d <tail_lb_ipv6+0x2c5d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c5d;
	}
x86_l_2c48:
	/* 0x2c48: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2c4c:
	/* 0x2c4c: mov    BYTE PTR [r15+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2c50:
	/* 0x2c50: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c54:
	/* 0x2c54: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2c5b:
	/* 0x2c5b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5d:
	/* 0x2c5d: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_2c64:
	/* 0x2c64: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c67:
	/* 0x2c67: je     2c7b <tail_lb_ipv6+0x2c7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c7b;
	}
x86_l_2c69:
	/* 0x2c69: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_2c6e:
	/* 0x2c6e: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c70:
	/* 0x2c70: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c73:
	/* 0x2c73: sub    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2c76:
	/* 0x2c76: add QWORD PTR [r15+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_2c7b:
	/* 0x2c7b: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2c7f:
	/* 0x2c7f: je     2ccf <tail_lb_ipv6+0x2ccf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ccf;
	}
x86_l_2c81:
	/* 0x2c81: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2c85:
	/* 0x2c85: jne    2967 <tail_lb_ipv6+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2967;
	}
x86_l_2c8b:
	/* 0x2c8b: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2c90:
	/* 0x2c90: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_2c92:
	/* 0x2c92: je     2967 <tail_lb_ipv6+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_2c98:
	/* 0x2c98: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_2c9f:
	/* 0x2c9f: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_2ca4:
	/* 0x2ca4: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2ca9:
	/* 0x2ca9: mov    r12,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2cb0:
	/* 0x2cb0: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cb5:
	/* 0x2cb5: je     2eb8 <tail_lb_ipv6+0x2eb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11960ULL;
	}
x86_l_2cbb:
	/* 0x2cbb: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2cc2:
	/* 0x2cc2: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_2cc6:
	/* 0x2cc6: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2cca:
	/* 0x2cca: jmp    2ebe <tail_lb_ipv6+0x2ebe> */
	return 11966ULL;
x86_l_2ccf:
	/* 0x2ccf: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_2cd2:
	/* 0x2cd2: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_2cd7:
	/* 0x2cd7: cmp    ax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 1ULL);
x86_l_2cdb:
	/* 0x2cdb: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_2cdf:
	/* 0x2cdf: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_2ce3:
	/* 0x2ce3: or     ax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_2ce8:
	/* 0x2ce8: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2ced:
	/* 0x2ced: mov    rcx,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2cf4:
	/* 0x2cf4: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf6:
	/* 0x2cf6: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_2cf8:
	/* 0x2cf8: je     2967 <tail_lb_ipv6+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_2cfe:
	/* 0x2cfe: mov    r13,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_2d05:
	/* 0x2d05: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d0a:
	/* 0x2d0a: je     2d21 <tail_lb_ipv6+0x2d21> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d21;
	}
x86_l_2d0c:
	/* 0x2d0c: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2d13:
	/* 0x2d13: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d15:
	/* 0x2d15: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d17:
	/* 0x2d17: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2d1b:
	/* 0x2d1b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2d1f:
	/* 0x2d1f: jmp    2d27 <tail_lb_ipv6+0x2d27> */
	goto x86_l_2d27;
x86_l_2d21:
	/* 0x2d21: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_2d27:
	/* 0x2d27: movzx  ebp,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d2b:
	/* 0x2d2b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2d2e:
	/* 0x2d2e: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d33:
	/* 0x2d33: je     2d44 <tail_lb_ipv6+0x2d44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2d44;
	}
x86_l_2d35:
	/* 0x2d35: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2d3a:
	/* 0x2d3a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d3c:
	/* 0x2d3c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d3e:
	/* 0x2d3e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2d42:
	/* 0x2d42: jmp    2d67 <tail_lb_ipv6+0x2d67> */
	goto x86_l_2d67;
x86_l_2d44:
	/* 0x2d44: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2d49:
	/* 0x2d49: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d4b:
	/* 0x2d4b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2d4d:
	/* 0x2d4d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2d51:
	/* 0x2d51: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2d5b:
	/* 0x2d5b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2d5e:
	/* 0x2d5e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2d63:
	/* 0x2d63: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2d67:
	/* 0x2d67: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d6a:
	/* 0x2d6a: mov    DWORD PTR [r15+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d6e:
	/* 0x2d6e: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2d73:
	/* 0x2d73: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d77:
	/* 0x2d77: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2d7b:
	/* 0x2d7b: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d80:
	/* 0x2d80: je     2d93 <tail_lb_ipv6+0x2d93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11667ULL;
	}
x86_l_2d82:
	/* 0x2d82: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2d89:
	/* 0x2d89: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d8b:
	/* 0x2d8b: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
	return 11662ULL;
}

static __noinline __u64 cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 11662ULL: goto x86_l_2d8e;
	case 11665ULL: goto x86_l_2d91;
	case 11667ULL: goto x86_l_2d93;
	case 11672ULL: goto x86_l_2d98;
	case 11674ULL: goto x86_l_2d9a;
	case 11677ULL: goto x86_l_2d9d;
	case 11679ULL: goto x86_l_2d9f;
	case 11681ULL: goto x86_l_2da1;
	case 11684ULL: goto x86_l_2da4;
	case 11690ULL: goto x86_l_2daa;
	case 11694ULL: goto x86_l_2dae;
	case 11698ULL: goto x86_l_2db2;
	case 11705ULL: goto x86_l_2db9;
	case 11707ULL: goto x86_l_2dbb;
	case 11712ULL: goto x86_l_2dc0;
	case 11715ULL: goto x86_l_2dc3;
	case 11720ULL: goto x86_l_2dc8;
	case 11725ULL: goto x86_l_2dcd;
	case 11727ULL: goto x86_l_2dcf;
	case 11732ULL: goto x86_l_2dd4;
	case 11738ULL: goto x86_l_2dda;
	case 11743ULL: goto x86_l_2ddf;
	case 11749ULL: goto x86_l_2de5;
	case 11753ULL: goto x86_l_2de9;
	case 11755ULL: goto x86_l_2deb;
	case 11759ULL: goto x86_l_2def;
	case 11761ULL: goto x86_l_2df1;
	case 11764ULL: goto x86_l_2df4;
	case 11767ULL: goto x86_l_2df7;
	case 11769ULL: goto x86_l_2df9;
	case 11774ULL: goto x86_l_2dfe;
	case 11776ULL: goto x86_l_2e00;
	case 11781ULL: goto x86_l_2e05;
	case 11787ULL: goto x86_l_2e0b;
	case 11791ULL: goto x86_l_2e0f;
	case 11795ULL: goto x86_l_2e13;
	case 11797ULL: goto x86_l_2e15;
	case 11804ULL: goto x86_l_2e1c;
	case 11808ULL: goto x86_l_2e20;
	case 11812ULL: goto x86_l_2e24;
	case 11817ULL: goto x86_l_2e29;
	case 11820ULL: goto x86_l_2e2c;
	case 11824ULL: goto x86_l_2e30;
	case 11826ULL: goto x86_l_2e32;
	case 11831ULL: goto x86_l_2e37;
	case 11833ULL: goto x86_l_2e39;
	case 11835ULL: goto x86_l_2e3b;
	case 11839ULL: goto x86_l_2e3f;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11848ULL: goto x86_l_2e48;
	case 11850ULL: goto x86_l_2e4a;
	case 11854ULL: goto x86_l_2e4e;
	case 11864ULL: goto x86_l_2e58;
	case 11867ULL: goto x86_l_2e5b;
	case 11872ULL: goto x86_l_2e60;
	case 11876ULL: goto x86_l_2e64;
	case 11879ULL: goto x86_l_2e67;
	case 11883ULL: goto x86_l_2e6b;
	case 11888ULL: goto x86_l_2e70;
	case 11892ULL: goto x86_l_2e74;
	case 11896ULL: goto x86_l_2e78;
	case 11900ULL: goto x86_l_2e7c;
	case 11902ULL: goto x86_l_2e7e;
	case 11909ULL: goto x86_l_2e85;
	case 11911ULL: goto x86_l_2e87;
	case 11914ULL: goto x86_l_2e8a;
	case 11917ULL: goto x86_l_2e8d;
	case 11919ULL: goto x86_l_2e8f;
	case 11924ULL: goto x86_l_2e94;
	case 11926ULL: goto x86_l_2e96;
	case 11929ULL: goto x86_l_2e99;
	case 11931ULL: goto x86_l_2e9b;
	case 11936ULL: goto x86_l_2ea0;
	case 11938ULL: goto x86_l_2ea2;
	case 11941ULL: goto x86_l_2ea5;
	case 11947ULL: goto x86_l_2eab;
	case 11951ULL: goto x86_l_2eaf;
	case 11955ULL: goto x86_l_2eb3;
	case 11960ULL: goto x86_l_2eb8;
	case 11966ULL: goto x86_l_2ebe;
	case 11970ULL: goto x86_l_2ec2;
	case 11972ULL: goto x86_l_2ec4;
	case 11975ULL: goto x86_l_2ec7;
	case 11977ULL: goto x86_l_2ec9;
	case 11980ULL: goto x86_l_2ecc;
	case 11983ULL: goto x86_l_2ecf;
	case 11985ULL: goto x86_l_2ed1;
	case 11990ULL: goto x86_l_2ed6;
	case 11992ULL: goto x86_l_2ed8;
	case 11997ULL: goto x86_l_2edd;
	case 12003ULL: goto x86_l_2ee3;
	case 12007ULL: goto x86_l_2ee7;
	case 12012ULL: goto x86_l_2eec;
	case 12014ULL: goto x86_l_2eee;
	case 12021ULL: goto x86_l_2ef5;
	case 12025ULL: goto x86_l_2ef9;
	case 12029ULL: goto x86_l_2efd;
	case 12033ULL: goto x86_l_2f01;
	case 12036ULL: goto x86_l_2f04;
	case 12041ULL: goto x86_l_2f09;
	case 12043ULL: goto x86_l_2f0b;
	case 12048ULL: goto x86_l_2f10;
	case 12050ULL: goto x86_l_2f12;
	case 12052ULL: goto x86_l_2f14;
	case 12056ULL: goto x86_l_2f18;
	case 12058ULL: goto x86_l_2f1a;
	case 12063ULL: goto x86_l_2f1f;
	case 12065ULL: goto x86_l_2f21;
	case 12067ULL: goto x86_l_2f23;
	case 12071ULL: goto x86_l_2f27;
	case 12081ULL: goto x86_l_2f31;
	case 12084ULL: goto x86_l_2f34;
	case 12089ULL: goto x86_l_2f39;
	case 12093ULL: goto x86_l_2f3d;
	case 12096ULL: goto x86_l_2f40;
	case 12100ULL: goto x86_l_2f44;
	case 12105ULL: goto x86_l_2f49;
	case 12109ULL: goto x86_l_2f4d;
	case 12113ULL: goto x86_l_2f51;
	case 12118ULL: goto x86_l_2f56;
	case 12120ULL: goto x86_l_2f58;
	case 12127ULL: goto x86_l_2f5f;
	case 12129ULL: goto x86_l_2f61;
	case 12132ULL: goto x86_l_2f64;
	case 12135ULL: goto x86_l_2f67;
	case 12137ULL: goto x86_l_2f69;
	case 12142ULL: goto x86_l_2f6e;
	case 12144ULL: goto x86_l_2f70;
	case 12147ULL: goto x86_l_2f73;
	case 12149ULL: goto x86_l_2f75;
	case 12151ULL: goto x86_l_2f77;
	case 12154ULL: goto x86_l_2f7a;
	case 12160ULL: goto x86_l_2f80;
	case 12164ULL: goto x86_l_2f84;
	case 12168ULL: goto x86_l_2f88;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2d8e:
	/* 0x2d8e: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2d91:
	/* 0x2d91: jmp    2d98 <tail_lb_ipv6+0x2d98> */
	goto x86_l_2d98;
x86_l_2d93:
	/* 0x2d93: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2d98:
	/* 0x2d98: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2d9a:
	/* 0x2d9a: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2d9d:
	/* 0x2d9d: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2d9f:
	/* 0x2d9f: jb     2daa <tail_lb_ipv6+0x2daa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2daa;
	}
x86_l_2da1:
	/* 0x2da1: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_2da4:
	/* 0x2da4: je     2967 <tail_lb_ipv6+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10599ULL;
	}
x86_l_2daa:
	/* 0x2daa: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2dae:
	/* 0x2dae: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2db2:
	/* 0x2db2: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2db9:
	/* 0x2db9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dbb:
	/* 0x2dbb: jmp    2967 <tail_lb_ipv6+0x2967> */
	return 10599ULL;
x86_l_2dc0:
	/* 0x2dc0: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_2dc3:
	/* 0x2dc3: mov    ebp,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967141ULL);
x86_l_2dc8:
	/* 0x2dc8: jmp    3f4 <tail_lb_ipv6+0x3f4> */
	return 1012ULL;
x86_l_2dcd:
	/* 0x2dcd: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2dcf:
	/* 0x2dcf: jmp    209b <tail_lb_ipv6+0x209b> */
	return 8347ULL;
x86_l_2dd4:
	/* 0x2dd4: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_2dda:
	/* 0x2dda: jmp    2792 <tail_lb_ipv6+0x2792> */
	return 10130ULL;
x86_l_2ddf:
	/* 0x2ddf: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2de5:
	/* 0x2de5: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2de9:
	/* 0x2de9: jne    2e24 <tail_lb_ipv6+0x2e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2e24;
	}
x86_l_2deb:
	/* 0x2deb: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2def:
	/* 0x2def: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2df1:
	/* 0x2df1: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2df4:
	/* 0x2df4: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2df7:
	/* 0x2df7: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2df9:
	/* 0x2df9: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dfe:
	/* 0x2dfe: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2e00:
	/* 0x2e00: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2e05:
	/* 0x2e05: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_2e0b:
	/* 0x2e0b: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2e0f:
	/* 0x2e0f: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e13:
	/* 0x2e13: je     2e24 <tail_lb_ipv6+0x2e24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e24;
	}
x86_l_2e15:
	/* 0x2e15: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2e1c:
	/* 0x2e1c: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2e20:
	/* 0x2e20: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2e24:
	/* 0x2e24: movzx  ebp,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_2e29:
	/* 0x2e29: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2e2c:
	/* 0x2e2c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e30:
	/* 0x2e30: je     2e41 <tail_lb_ipv6+0x2e41> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e41;
	}
x86_l_2e32:
	/* 0x2e32: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2e37:
	/* 0x2e37: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e39:
	/* 0x2e39: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e3b:
	/* 0x2e3b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2e3f:
	/* 0x2e3f: jmp    2e64 <tail_lb_ipv6+0x2e64> */
	goto x86_l_2e64;
x86_l_2e41:
	/* 0x2e41: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2e46:
	/* 0x2e46: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e48:
	/* 0x2e48: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2e4a:
	/* 0x2e4a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2e4e:
	/* 0x2e4e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2e58:
	/* 0x2e58: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2e5b:
	/* 0x2e5b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2e60:
	/* 0x2e60: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2e64:
	/* 0x2e64: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e67:
	/* 0x2e67: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e6b:
	/* 0x2e6b: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2e70:
	/* 0x2e70: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2e74:
	/* 0x2e74: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2e78:
	/* 0x2e78: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7c:
	/* 0x2e7c: je     2e8f <tail_lb_ipv6+0x2e8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e8f;
	}
x86_l_2e7e:
	/* 0x2e7e: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2e85:
	/* 0x2e85: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e87:
	/* 0x2e87: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2e8a:
	/* 0x2e8a: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2e8d:
	/* 0x2e8d: jmp    2e94 <tail_lb_ipv6+0x2e94> */
	goto x86_l_2e94;
x86_l_2e8f:
	/* 0x2e8f: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2e94:
	/* 0x2e94: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2e96:
	/* 0x2e96: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2e99:
	/* 0x2e99: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2e9b:
	/* 0x2e9b: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2ea0:
	/* 0x2ea0: jb     2eab <tail_lb_ipv6+0x2eab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2eab;
	}
x86_l_2ea2:
	/* 0x2ea2: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_2ea5:
	/* 0x2ea5: je     113f <tail_lb_ipv6+0x113f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4415ULL;
	}
x86_l_2eab:
	/* 0x2eab: mov    BYTE PTR [r14+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2eaf:
	/* 0x2eaf: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2eb3:
	/* 0x2eb3: jmp    1131 <tail_lb_ipv6+0x1131> */
	return 4401ULL;
x86_l_2eb8:
	/* 0x2eb8: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_2ebe:
	/* 0x2ebe: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2ec2:
	/* 0x2ec2: jne    2efd <tail_lb_ipv6+0x2efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2efd;
	}
x86_l_2ec4:
	/* 0x2ec4: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_2ec7:
	/* 0x2ec7: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_2ec9:
	/* 0x2ec9: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_2ecc:
	/* 0x2ecc: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_2ecf:
	/* 0x2ecf: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2ed1:
	/* 0x2ed1: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2ed6:
	/* 0x2ed6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2ed8:
	/* 0x2ed8: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2edd:
	/* 0x2edd: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_2ee3:
	/* 0x2ee3: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_2ee7:
	/* 0x2ee7: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eec:
	/* 0x2eec: je     2efd <tail_lb_ipv6+0x2efd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2efd;
	}
x86_l_2eee:
	/* 0x2eee: mov    rax,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2ef5:
	/* 0x2ef5: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2ef9:
	/* 0x2ef9: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2efd:
	/* 0x2efd: movzx  ebp,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2f01:
	/* 0x2f01: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2f04:
	/* 0x2f04: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f09:
	/* 0x2f09: je     2f1a <tail_lb_ipv6+0x2f1a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f1a;
	}
x86_l_2f0b:
	/* 0x2f0b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_2f10:
	/* 0x2f10: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f12:
	/* 0x2f12: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f14:
	/* 0x2f14: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_2f18:
	/* 0x2f18: jmp    2f3d <tail_lb_ipv6+0x2f3d> */
	goto x86_l_2f3d;
x86_l_2f1a:
	/* 0x2f1a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_2f1f:
	/* 0x2f1f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f21:
	/* 0x2f21: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_2f23:
	/* 0x2f23: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_2f27:
	/* 0x2f27: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_2f31:
	/* 0x2f31: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2f34:
	/* 0x2f34: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2f39:
	/* 0x2f39: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_2f3d:
	/* 0x2f3d: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f40:
	/* 0x2f40: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f44:
	/* 0x2f44: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_2f49:
	/* 0x2f49: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f4d:
	/* 0x2f4d: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_2f51:
	/* 0x2f51: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f56:
	/* 0x2f56: je     2f69 <tail_lb_ipv6+0x2f69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f69;
	}
x86_l_2f58:
	/* 0x2f58: mov    rsi,QWORD PTR [rip+0x10406] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_2f5f:
	/* 0x2f5f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f61:
	/* 0x2f61: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_2f64:
	/* 0x2f64: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2f67:
	/* 0x2f67: jmp    2f6e <tail_lb_ipv6+0x2f6e> */
	goto x86_l_2f6e;
x86_l_2f69:
	/* 0x2f69: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_2f6e:
	/* 0x2f6e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2f70:
	/* 0x2f70: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_2f73:
	/* 0x2f73: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2f75:
	/* 0x2f75: jb     2f80 <tail_lb_ipv6+0x2f80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f80;
	}
x86_l_2f77:
	/* 0x2f77: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_2f7a:
	/* 0x2f7a: je     27db <tail_lb_ipv6+0x27db> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10203ULL;
	}
x86_l_2f80:
	/* 0x2f80: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_2f84:
	/* 0x2f84: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2f88:
	/* 0x2f88: jmp    27d2 <tail_lb_ipv6+0x27d2> */
	return 10194ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int cilium_bpf_xdp_tail_lb_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 11296U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1738ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1743ULL && __x86_pc <= 3552ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3554ULL && __x86_pc <= 5220ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5225ULL && __x86_pc <= 6797ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6801ULL && __x86_pc <= 8347ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8351ULL && __x86_pc <= 10041ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10047ULL && __x86_pc <= 11659ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 11662ULL && __x86_pc <= 12168ULL)
			__x86_pc = cilium_bpf_xdp_tail_lb_ipv6_x86_chunk_7(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

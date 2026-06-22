extern char CONFIG_ITER_NUM;
extern char buffer_heap_map;
extern char config_map;
extern char data_heap;
extern char fdinstall_map;
extern char process_call_heap;
extern char retprobe_map;
extern char sleepable_preload;
extern char socktrack_map;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_ipv6_ext_heap;
extern char tg_rb_events;
extern char tg_stats_map;
extern char usdt_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 31ULL: goto x86_l_1f;
	case 39ULL: goto x86_l_27;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 65ULL: goto x86_l_41;
	case 68ULL: goto x86_l_44;
	case 75ULL: goto x86_l_4b;
	case 81ULL: goto x86_l_51;
	case 92ULL: goto x86_l_5c;
	case 99ULL: goto x86_l_63;
	case 107ULL: goto x86_l_6b;
	case 112ULL: goto x86_l_70;
	case 114ULL: goto x86_l_72;
	case 117ULL: goto x86_l_75;
	case 123ULL: goto x86_l_7b;
	case 126ULL: goto x86_l_7e;
	case 133ULL: goto x86_l_85;
	case 140ULL: goto x86_l_8c;
	case 145ULL: goto x86_l_91;
	case 147ULL: goto x86_l_93;
	case 151ULL: goto x86_l_97;
	case 157ULL: goto x86_l_9d;
	case 160ULL: goto x86_l_a0;
	case 166ULL: goto x86_l_a6;
	case 171ULL: goto x86_l_ab;
	case 179ULL: goto x86_l_b3;
	case 182ULL: goto x86_l_b6;
	case 186ULL: goto x86_l_ba;
	case 189ULL: goto x86_l_bd;
	case 194ULL: goto x86_l_c2;
	case 199ULL: goto x86_l_c7;
	case 203ULL: goto x86_l_cb;
	case 210ULL: goto x86_l_d2;
	case 222ULL: goto x86_l_de;
	case 230ULL: goto x86_l_e6;
	case 238ULL: goto x86_l_ee;
	case 243ULL: goto x86_l_f3;
	case 249ULL: goto x86_l_f9;
	case 251ULL: goto x86_l_fb;
	case 255ULL: goto x86_l_ff;
	case 258ULL: goto x86_l_102;
	case 260ULL: goto x86_l_104;
	case 263ULL: goto x86_l_107;
	case 268ULL: goto x86_l_10c;
	case 277ULL: goto x86_l_115;
	case 282ULL: goto x86_l_11a;
	case 284ULL: goto x86_l_11c;
	case 292ULL: goto x86_l_124;
	case 299ULL: goto x86_l_12b;
	case 307ULL: goto x86_l_133;
	case 312ULL: goto x86_l_138;
	case 314ULL: goto x86_l_13a;
	case 317ULL: goto x86_l_13d;
	case 319ULL: goto x86_l_13f;
	case 321ULL: goto x86_l_141;
	case 324ULL: goto x86_l_144;
	case 328ULL: goto x86_l_148;
	case 330ULL: goto x86_l_14a;
	case 334ULL: goto x86_l_14e;
	case 339ULL: goto x86_l_153;
	case 344ULL: goto x86_l_158;
	case 349ULL: goto x86_l_15d;
	case 354ULL: goto x86_l_162;
	case 359ULL: goto x86_l_167;
	case 362ULL: goto x86_l_16a;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 377ULL: goto x86_l_179;
	case 382ULL: goto x86_l_17e;
	case 385ULL: goto x86_l_181;
	case 389ULL: goto x86_l_185;
	case 392ULL: goto x86_l_188;
	case 398ULL: goto x86_l_18e;
	case 404ULL: goto x86_l_194;
	case 407ULL: goto x86_l_197;
	case 411ULL: goto x86_l_19b;
	case 416ULL: goto x86_l_1a0;
	case 424ULL: goto x86_l_1a8;
	case 429ULL: goto x86_l_1ad;
	case 434ULL: goto x86_l_1b2;
	case 439ULL: goto x86_l_1b7;
	case 446ULL: goto x86_l_1be;
	case 449ULL: goto x86_l_1c1;
	case 451ULL: goto x86_l_1c3;
	case 454ULL: goto x86_l_1c6;
	case 459ULL: goto x86_l_1cb;
	case 461ULL: goto x86_l_1cd;
	case 466ULL: goto x86_l_1d2;
	case 471ULL: goto x86_l_1d7;
	case 474ULL: goto x86_l_1da;
	case 479ULL: goto x86_l_1df;
	case 481ULL: goto x86_l_1e1;
	case 483ULL: goto x86_l_1e3;
	case 485ULL: goto x86_l_1e5;
	case 488ULL: goto x86_l_1e8;
	case 492ULL: goto x86_l_1ec;
	case 494ULL: goto x86_l_1ee;
	case 499ULL: goto x86_l_1f3;
	case 506ULL: goto x86_l_1fa;
	case 508ULL: goto x86_l_1fc;
	case 513ULL: goto x86_l_201;
	case 517ULL: goto x86_l_205;
	case 520ULL: goto x86_l_208;
	case 523ULL: goto x86_l_20b;
	case 530ULL: goto x86_l_212;
	case 532ULL: goto x86_l_214;
	case 537ULL: goto x86_l_219;
	case 539ULL: goto x86_l_21b;
	case 544ULL: goto x86_l_220;
	case 546ULL: goto x86_l_222;
	case 553ULL: goto x86_l_229;
	case 555ULL: goto x86_l_22b;
	case 560ULL: goto x86_l_230;
	case 565ULL: goto x86_l_235;
	case 570ULL: goto x86_l_23a;
	case 575ULL: goto x86_l_23f;
	case 577ULL: goto x86_l_241;
	case 579ULL: goto x86_l_243;
	case 581ULL: goto x86_l_245;
	case 584ULL: goto x86_l_248;
	case 589ULL: goto x86_l_24d;
	case 592ULL: goto x86_l_250;
	case 600ULL: goto x86_l_258;
	case 606ULL: goto x86_l_25e;
	case 610ULL: goto x86_l_262;
	case 612ULL: goto x86_l_264;
	case 616ULL: goto x86_l_268;
	case 621ULL: goto x86_l_26d;
	case 623ULL: goto x86_l_26f;
	case 627ULL: goto x86_l_273;
	case 633ULL: goto x86_l_279;
	case 637ULL: goto x86_l_27d;
	case 643ULL: goto x86_l_283;
	case 648ULL: goto x86_l_288;
	case 651ULL: goto x86_l_28b;
	case 657ULL: goto x86_l_291;
	case 661ULL: goto x86_l_295;
	case 667ULL: goto x86_l_29b;
	case 672ULL: goto x86_l_2a0;
	case 676ULL: goto x86_l_2a4;
	case 681ULL: goto x86_l_2a9;
	case 683ULL: goto x86_l_2ab;
	case 687ULL: goto x86_l_2af;
	case 693ULL: goto x86_l_2b5;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 707ULL: goto x86_l_2c3;
	case 711ULL: goto x86_l_2c7;
	case 717ULL: goto x86_l_2cd;
	case 721ULL: goto x86_l_2d1;
	case 727ULL: goto x86_l_2d7;
	case 732ULL: goto x86_l_2dc;
	case 736ULL: goto x86_l_2e0;
	case 742ULL: goto x86_l_2e6;
	case 747ULL: goto x86_l_2eb;
	case 750ULL: goto x86_l_2ee;
	case 756ULL: goto x86_l_2f4;
	case 761ULL: goto x86_l_2f9;
	case 764ULL: goto x86_l_2fc;
	case 770ULL: goto x86_l_302;
	case 775ULL: goto x86_l_307;
	case 779ULL: goto x86_l_30b;
	case 785ULL: goto x86_l_311;
	case 789ULL: goto x86_l_315;
	case 795ULL: goto x86_l_31b;
	case 799ULL: goto x86_l_31f;
	case 805ULL: goto x86_l_325;
	case 809ULL: goto x86_l_329;
	case 815ULL: goto x86_l_32f;
	case 820ULL: goto x86_l_334;
	case 824ULL: goto x86_l_338;
	case 830ULL: goto x86_l_33e;
	case 834ULL: goto x86_l_342;
	case 840ULL: goto x86_l_348;
	case 844ULL: goto x86_l_34c;
	case 850ULL: goto x86_l_352;
	case 854ULL: goto x86_l_356;
	case 860ULL: goto x86_l_35c;
	case 866ULL: goto x86_l_362;
	case 871ULL: goto x86_l_367;
	case 875ULL: goto x86_l_36b;
	case 881ULL: goto x86_l_371;
	case 885ULL: goto x86_l_375;
	case 891ULL: goto x86_l_37b;
	case 895ULL: goto x86_l_37f;
	case 901ULL: goto x86_l_385;
	case 905ULL: goto x86_l_389;
	case 911ULL: goto x86_l_38f;
	case 916ULL: goto x86_l_394;
	case 920ULL: goto x86_l_398;
	case 922ULL: goto x86_l_39a;
	case 927ULL: goto x86_l_39f;
	case 931ULL: goto x86_l_3a3;
	case 937ULL: goto x86_l_3a9;
	case 941ULL: goto x86_l_3ad;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 950ULL: goto x86_l_3b6;
	case 953ULL: goto x86_l_3b9;
	case 955ULL: goto x86_l_3bb;
	case 961ULL: goto x86_l_3c1;
	case 963ULL: goto x86_l_3c3;
	case 969ULL: goto x86_l_3c9;
	case 971ULL: goto x86_l_3cb;
	case 975ULL: goto x86_l_3cf;
	case 977ULL: goto x86_l_3d1;
	case 981ULL: goto x86_l_3d5;
	case 983ULL: goto x86_l_3d7;
	case 989ULL: goto x86_l_3dd;
	case 991ULL: goto x86_l_3df;
	case 995ULL: goto x86_l_3e3;
	case 997ULL: goto x86_l_3e5;
	case 1001ULL: goto x86_l_3e9;
	case 1003ULL: goto x86_l_3eb;
	case 1005ULL: goto x86_l_3ed;
	case 1011ULL: goto x86_l_3f3;
	case 1013ULL: goto x86_l_3f5;
	case 1017ULL: goto x86_l_3f9;
	case 1019ULL: goto x86_l_3fb;
	case 1023ULL: goto x86_l_3ff;
	case 1025ULL: goto x86_l_401;
	case 1031ULL: goto x86_l_407;
	case 1033ULL: goto x86_l_409;
	case 1039ULL: goto x86_l_40f;
	case 1041ULL: goto x86_l_411;
	case 1047ULL: goto x86_l_417;
	case 1049ULL: goto x86_l_419;
	case 1053ULL: goto x86_l_41d;
	case 1055ULL: goto x86_l_41f;
	case 1061ULL: goto x86_l_425;
	case 1063ULL: goto x86_l_427;
	case 1066ULL: goto x86_l_42a;
	case 1071ULL: goto x86_l_42f;
	case 1082ULL: goto x86_l_43a;
	case 1089ULL: goto x86_l_441;
	case 1097ULL: goto x86_l_449;
	case 1102ULL: goto x86_l_44e;
	case 1104ULL: goto x86_l_450;
	case 1107ULL: goto x86_l_453;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1117ULL: goto x86_l_45d;
	case 1120ULL: goto x86_l_460;
	case 1122ULL: goto x86_l_462;
	case 1125ULL: goto x86_l_465;
	case 1133ULL: goto x86_l_46d;
	case 1140ULL: goto x86_l_474;
	case 1144ULL: goto x86_l_478;
	case 1152ULL: goto x86_l_480;
	case 1157ULL: goto x86_l_485;
	case 1159ULL: goto x86_l_487;
	case 1165ULL: goto x86_l_48d;
	case 1173ULL: goto x86_l_495;
	case 1178ULL: goto x86_l_49a;
	case 1186ULL: goto x86_l_4a2;
	case 1190ULL: goto x86_l_4a6;
	case 1194ULL: goto x86_l_4aa;
	case 1200ULL: goto x86_l_4b0;
	case 1208ULL: goto x86_l_4b8;
	case 1215ULL: goto x86_l_4bf;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1230ULL: goto x86_l_4ce;
	case 1236ULL: goto x86_l_4d4;
	case 1239ULL: goto x86_l_4d7;
	case 1246ULL: goto x86_l_4de;
	case 1253ULL: goto x86_l_4e5;
	case 1258ULL: goto x86_l_4ea;
	case 1260ULL: goto x86_l_4ec;
	case 1263ULL: goto x86_l_4ef;
	case 1269ULL: goto x86_l_4f5;
	case 1272ULL: goto x86_l_4f8;
	case 1275ULL: goto x86_l_4fb;
	case 1278ULL: goto x86_l_4fe;
	case 1283ULL: goto x86_l_503;
	case 1289ULL: goto x86_l_509;
	case 1296ULL: goto x86_l_510;
	case 1303ULL: goto x86_l_517;
	case 1308ULL: goto x86_l_51c;
	case 1313ULL: goto x86_l_521;
	case 1316ULL: goto x86_l_524;
	case 1321ULL: goto x86_l_529;
	case 1323ULL: goto x86_l_52b;
	case 1328ULL: goto x86_l_530;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1342ULL: goto x86_l_53e;
	case 1349ULL: goto x86_l_545;
	case 1352ULL: goto x86_l_548;
	case 1357ULL: goto x86_l_54d;
	case 1362ULL: goto x86_l_552;
	case 1374ULL: goto x86_l_55e;
	case 1378ULL: goto x86_l_562;
	case 1383ULL: goto x86_l_567;
	case 1388ULL: goto x86_l_56c;
	case 1390ULL: goto x86_l_56e;
	case 1394ULL: goto x86_l_572;
	case 1396ULL: goto x86_l_574;
	case 1400ULL: goto x86_l_578;
	case 1406ULL: goto x86_l_57e;
	case 1410ULL: goto x86_l_582;
	case 1416ULL: goto x86_l_588;
	case 1428ULL: goto x86_l_594;
	case 1436ULL: goto x86_l_59c;
	case 1444ULL: goto x86_l_5a4;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1461ULL: goto x86_l_5b5;
	case 1467ULL: goto x86_l_5bb;
	case 1471ULL: goto x86_l_5bf;
	case 1477ULL: goto x86_l_5c5;
	case 1480ULL: goto x86_l_5c8;
	case 1485ULL: goto x86_l_5cd;
	case 1487ULL: goto x86_l_5cf;
	case 1490ULL: goto x86_l_5d2;
	case 1495ULL: goto x86_l_5d7;
	case 1500ULL: goto x86_l_5dc;
	case 1505ULL: goto x86_l_5e1;
	case 1510ULL: goto x86_l_5e6;
	case 1513ULL: goto x86_l_5e9;
	case 1518ULL: goto x86_l_5ee;
	case 1520ULL: goto x86_l_5f0;
	case 1525ULL: goto x86_l_5f5;
	case 1530ULL: goto x86_l_5fa;
	case 1535ULL: goto x86_l_5ff;
	case 1540ULL: goto x86_l_604;
	case 1545ULL: goto x86_l_609;
	case 1550ULL: goto x86_l_60e;
	case 1555ULL: goto x86_l_613;
	case 1557ULL: goto x86_l_615;
	case 1562ULL: goto x86_l_61a;
	case 1566ULL: goto x86_l_61e;
	case 1574ULL: goto x86_l_626;
	case 1577ULL: goto x86_l_629;
	case 1579ULL: goto x86_l_62b;
	case 1583ULL: goto x86_l_62f;
	case 1588ULL: goto x86_l_634;
	case 1593ULL: goto x86_l_639;
	case 1598ULL: goto x86_l_63e;
	case 1603ULL: goto x86_l_643;
	case 1608ULL: goto x86_l_648;
	case 1613ULL: goto x86_l_64d;
	case 1615ULL: goto x86_l_64f;
	case 1620ULL: goto x86_l_654;
	case 1624ULL: goto x86_l_658;
	case 1632ULL: goto x86_l_660;
	case 1634ULL: goto x86_l_662;
	case 1642ULL: goto x86_l_66a;
	case 1650ULL: goto x86_l_672;
	case 1655ULL: goto x86_l_677;
	case 1660ULL: goto x86_l_67c;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1672ULL: goto x86_l_688;
	case 1680ULL: goto x86_l_690;
	case 1688ULL: goto x86_l_698;
	case 1691ULL: goto x86_l_69b;
	case 1697ULL: goto x86_l_6a1;
	case 1708ULL: goto x86_l_6ac;
	case 1715ULL: goto x86_l_6b3;
	case 1723ULL: goto x86_l_6bb;
	case 1728ULL: goto x86_l_6c0;
	case 1730ULL: goto x86_l_6c2;
	case 1733ULL: goto x86_l_6c5;
	case 1739ULL: goto x86_l_6cb;
	case 1742ULL: goto x86_l_6ce;
	case 1747ULL: goto x86_l_6d3;
	case 1755ULL: goto x86_l_6db;
	case 1761ULL: goto x86_l_6e1;
	case 1766ULL: goto x86_l_6e6;
	case 1771ULL: goto x86_l_6eb;
	case 1773ULL: goto x86_l_6ed;
	case 1780ULL: goto x86_l_6f4;
	case 1788ULL: goto x86_l_6fc;
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
	/* 0xd: mov    DWORD PTR [rsp+0xec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1013612281856ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x9e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0xec] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     dc6 <generic_usdt_process_event+0xdc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3526ULL;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    r12d,DWORD PTR [rax+0x5efc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_41:
	/* 0x41: mov    ebp,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_44:
	/* 0x44: cmp    rbp,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 8999ULL);
x86_l_4b:
	/* 0x4b: ja     4a2 <generic_usdt_process_event+0x4a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_4a2;
	}
x86_l_51:
	/* 0x51: mov    DWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5c:
	/* 0x5c: mov    rdi,QWORD PTR [rip+0x9e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_63:
	/* 0x63: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_6b:
	/* 0x6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_70:
	/* 0x70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72:
	/* 0x72: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: je     4a2 <generic_usdt_process_event+0x4a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a2;
	}
x86_l_7b:
	/* 0x7b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_85:
	/* 0x85: mov    rdi,QWORD PTR [rip+0x9e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_8c:
	/* 0x8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_97:
	/* 0x97: jg     4a2 <generic_usdt_process_event+0x4a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_4a2;
	}
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     4a2 <generic_usdt_process_event+0x4a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4a2;
	}
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0xc0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_b3:
	/* 0xb3: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_b6:
	/* 0xb6: and    r13d,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_ba:
	/* 0xba: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_bd:
	/* 0xbd: mov    r12d,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_c2:
	/* 0xc2: movsxd rdi,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_c7:
	/* 0xc7: lea    rbp,[r15+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_cb:
	/* 0xcb: add    rbp,0x5ea0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24224ULL);
x86_l_d2:
	/* 0xd2: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_de:
	/* 0xde: mov    rsi,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_e6:
	/* 0xe6: mov    QWORD PTR [rsp+0xe0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_ee:
	/* 0xee: mov    QWORD PTR [rsp+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3:
	/* 0xf3: test   edi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 256ULL);
x86_l_f9:
	/* 0xf9: jne    10c <generic_usdt_process_event+0x10c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_10c;
	}
x86_l_fb:
	/* 0xfb: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_ff:
	/* 0xff: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_102:
	/* 0x102: jbe    17e <generic_usdt_process_event+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_17e;
	}
x86_l_104:
	/* 0x104: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_107:
	/* 0x107: jmp    258 <generic_usdt_process_event+0x258> */
	goto x86_l_258;
x86_l_10c:
	/* 0x10c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_115:
	/* 0x115: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_11a:
	/* 0x11a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11c:
	/* 0x11c: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_124:
	/* 0x124: mov    rdi,QWORD PTR [rip+0x9e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_12b:
	/* 0x12b: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_133:
	/* 0x133: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138:
	/* 0x138: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a:
	/* 0x13a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d:
	/* 0x13d: je     16c <generic_usdt_process_event+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_16c;
	}
x86_l_13f:
	/* 0x13f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141:
	/* 0x141: mov    DWORD PTR [rbp+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_144:
	/* 0x144: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_148:
	/* 0x148: jne    16c <generic_usdt_process_event+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16c;
	}
x86_l_14a:
	/* 0x14a: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_14e:
	/* 0x14e: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_153:
	/* 0x153: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_158:
	/* 0x158: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15d:
	/* 0x15d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_162:
	/* 0x162: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_167:
	/* 0x167: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_16a:
	/* 0x16a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c:
	/* 0x16c: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_171:
	/* 0x171: mov    QWORD PTR [rsp+0xe0],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_179:
	/* 0x179: jmp    258 <generic_usdt_process_event+0x258> */
	goto x86_l_258;
x86_l_17e:
	/* 0x17e: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_181:
	/* 0x181: lea    rcx,[rdx+rdx*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_185:
	/* 0x185: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_188:
	/* 0x188: cmp    WORD PTR [rax+rcx*1+0x76],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RCX, 0), 506806140928ULL);
x86_l_18e:
	/* 0x18e: je     258 <generic_usdt_process_event+0x258> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_258;
	}
x86_l_194:
	/* 0x194: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_197:
	/* 0x197: add    rax,0x70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 112ULL);
x86_l_19b:
	/* 0x19b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a0:
	/* 0x1a0: lea    rax,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1a8:
	/* 0x1a8: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ad:
	/* 0x1ad: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1b2:
	/* 0x1b2: mov    QWORD PTR [rsp+0x68],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b7:
	/* 0x1b7: mov    rax,QWORD PTR [rip+0x9e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_1be:
	/* 0x1be: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1:
	/* 0x1c1: je     222 <generic_usdt_process_event+0x222> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_222;
	}
x86_l_1c3:
	/* 0x1c3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c6:
	/* 0x1c6: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_1cb:
	/* 0x1cb: jmp    1ee <generic_usdt_process_event+0x1ee> */
	goto x86_l_1ee;
x86_l_1cd:
	/* 0x1cd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2:
	/* 0x1d2: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d7:
	/* 0x1d7: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1da:
	/* 0x1da: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1df:
	/* 0x1df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e1:
	/* 0x1e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e3:
	/* 0x1e3: js     245 <generic_usdt_process_event+0x245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_245;
	}
x86_l_1e5:
	/* 0x1e5: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1e8:
	/* 0x1e8: cmp    r15,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 10ULL);
x86_l_1ec:
	/* 0x1ec: je     250 <generic_usdt_process_event+0x250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250;
	}
x86_l_1ee:
	/* 0x1ee: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1f3:
	/* 0x1f3: cmp    WORD PTR [rax+r15*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 25769803776ULL);
x86_l_1fa:
	/* 0x1fa: je     250 <generic_usdt_process_event+0x250> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_250;
	}
x86_l_1fc:
	/* 0x1fc: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_201:
	/* 0x201: mov    edx,DWORD PTR [rax+r15*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 3), 0ULL);
x86_l_205:
	/* 0x205: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_208:
	/* 0x208: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20b:
	/* 0x20b: cmp    WORD PTR [rax+r15*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 3), 17179869184ULL);
x86_l_212:
	/* 0x212: je     1e5 <generic_usdt_process_event+0x1e5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e5;
	}
x86_l_214:
	/* 0x214: cmp    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_219:
	/* 0x219: je     1cd <generic_usdt_process_event+0x1cd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1cd;
	}
x86_l_21b:
	/* 0x21b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_220:
	/* 0x220: jmp    1d2 <generic_usdt_process_event+0x1d2> */
	goto x86_l_1d2;
x86_l_222:
	/* 0x222: lea    rsi,[rip+0x9e8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 2536ULL);
x86_l_229:
	/* 0x229: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22b:
	/* 0x22b: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_230:
	/* 0x230: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_235:
	/* 0x235: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_23a:
	/* 0x23a: mov    edi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 10ULL);
x86_l_23f:
	/* 0x23f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_241:
	/* 0x241: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243:
	/* 0x243: jmp    250 <generic_usdt_process_event+0x250> */
	goto x86_l_250;
x86_l_245:
	/* 0x245: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_248:
	/* 0x248: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24d:
	/* 0x24d: mov    DWORD PTR [rax],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_250:
	/* 0x250: mov    rsi,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_258:
	/* 0x258: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_25e:
	/* 0x25e: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_262:
	/* 0x262: jg     2a0 <generic_usdt_process_event+0x2a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2a0;
	}
x86_l_264:
	/* 0x264: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_268:
	/* 0x268: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_26d:
	/* 0x26d: jg     2dc <generic_usdt_process_event+0x2dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2dc;
	}
x86_l_26f:
	/* 0x26f: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_273:
	/* 0x273: jg     367 <generic_usdt_process_event+0x367> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_367;
	}
x86_l_279:
	/* 0x279: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_27d:
	/* 0x27d: jg     3f5 <generic_usdt_process_event+0x3f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3f5;
	}
x86_l_283:
	/* 0x283: lea    eax,[r12-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_288:
	/* 0x288: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_28b:
	/* 0x28b: jb     3bb <generic_usdt_process_event+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3bb;
	}
x86_l_291:
	/* 0x291: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_295:
	/* 0x295: je     3bb <generic_usdt_process_event+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3bb;
	}
x86_l_29b:
	/* 0x29b: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_2a0:
	/* 0x2a0: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_2a4:
	/* 0x2a4: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a9:
	/* 0x2a9: jle    307 <generic_usdt_process_event+0x307> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_307;
	}
x86_l_2ab:
	/* 0x2ab: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_2af:
	/* 0x2af: jg     334 <generic_usdt_process_event+0x334> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_334;
	}
x86_l_2b5:
	/* 0x2b5: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_2ba:
	/* 0x2ba: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bd:
	/* 0x2bd: jb     409 <generic_usdt_process_event+0x409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_409;
	}
x86_l_2c3:
	/* 0x2c3: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_2c7:
	/* 0x2c7: je     42a <generic_usdt_process_event+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a;
	}
x86_l_2cd:
	/* 0x2cd: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_2d1:
	/* 0x2d1: je     3c3 <generic_usdt_process_event+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c3;
	}
x86_l_2d7:
	/* 0x2d7: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_2dc:
	/* 0x2dc: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_2e0:
	/* 0x2e0: jg     394 <generic_usdt_process_event+0x394> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_394;
	}
x86_l_2e6:
	/* 0x2e6: lea    eax,[r12-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_2eb:
	/* 0x2eb: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ee:
	/* 0x2ee: jb     42a <generic_usdt_process_event+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_42a;
	}
x86_l_2f4:
	/* 0x2f4: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_2f9:
	/* 0x2f9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2fc:
	/* 0x2fc: jb     3bb <generic_usdt_process_event+0x3bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_3bb;
	}
x86_l_302:
	/* 0x302: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_307:
	/* 0x307: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_30b:
	/* 0x30b: jg     3b1 <generic_usdt_process_event+0x3b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3b1;
	}
x86_l_311:
	/* 0x311: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_315:
	/* 0x315: je     3c3 <generic_usdt_process_event+0x3c3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c3;
	}
x86_l_31b:
	/* 0x31b: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_31f:
	/* 0x31f: je     409 <generic_usdt_process_event+0x409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_409;
	}
x86_l_325:
	/* 0x325: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_329:
	/* 0x329: je     41f <generic_usdt_process_event+0x41f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41f;
	}
x86_l_32f:
	/* 0x32f: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_334:
	/* 0x334: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_338:
	/* 0x338: jle    3df <generic_usdt_process_event+0x3df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_3df;
	}
x86_l_33e:
	/* 0x33e: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_342:
	/* 0x342: je     42a <generic_usdt_process_event+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a;
	}
x86_l_348:
	/* 0x348: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_34c:
	/* 0x34c: je     3ed <generic_usdt_process_event+0x3ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ed;
	}
x86_l_352:
	/* 0x352: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_356:
	/* 0x356: jne    427 <generic_usdt_process_event+0x427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_427;
	}
x86_l_35c:
	/* 0x35c: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_362:
	/* 0x362: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_367:
	/* 0x367: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_36b:
	/* 0x36b: jg     409 <generic_usdt_process_event+0x409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_409;
	}
x86_l_371:
	/* 0x371: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_375:
	/* 0x375: je     42a <generic_usdt_process_event+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a;
	}
x86_l_37b:
	/* 0x37b: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_37f:
	/* 0x37f: je     401 <generic_usdt_process_event+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_401;
	}
x86_l_385:
	/* 0x385: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_389:
	/* 0x389: je     41f <generic_usdt_process_event+0x41f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_41f;
	}
x86_l_38f:
	/* 0x38f: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_394:
	/* 0x394: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_398:
	/* 0x398: jg     3cb <generic_usdt_process_event+0x3cb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3cb;
	}
x86_l_39a:
	/* 0x39a: mov    r15,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_39f:
	/* 0x39f: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_3a3:
	/* 0x3a3: je     42a <generic_usdt_process_event+0x42a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_42a;
	}
x86_l_3a9:
	/* 0x3a9: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_3ad:
	/* 0x3ad: je     3ed <generic_usdt_process_event+0x3ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ed;
	}
x86_l_3af:
	/* 0x3af: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_3b1:
	/* 0x3b1: lea    eax,[r12-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_3b6:
	/* 0x3b6: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3b9:
	/* 0x3b9: jae    419 <generic_usdt_process_event+0x419> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_419;
	}
x86_l_3bb:
	/* 0x3bb: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_3c1:
	/* 0x3c1: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_3c3:
	/* 0x3c3: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_3c9:
	/* 0x3c9: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_3cb:
	/* 0x3cb: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_3cf:
	/* 0x3cf: je     411 <generic_usdt_process_event+0x411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_411;
	}
x86_l_3d1:
	/* 0x3d1: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_3d5:
	/* 0x3d5: jne    427 <generic_usdt_process_event+0x427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_427;
	}
x86_l_3d7:
	/* 0x3d7: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_3dd:
	/* 0x3dd: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_3df:
	/* 0x3df: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_3e3:
	/* 0x3e3: je     3ed <generic_usdt_process_event+0x3ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ed;
	}
x86_l_3e5:
	/* 0x3e5: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_3e9:
	/* 0x3e9: je     401 <generic_usdt_process_event+0x401> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_401;
	}
x86_l_3eb:
	/* 0x3eb: jmp    427 <generic_usdt_process_event+0x427> */
	goto x86_l_427;
x86_l_3ed:
	/* 0x3ed: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_3f3:
	/* 0x3f3: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_3f5:
	/* 0x3f5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_3f9:
	/* 0x3f9: je     409 <generic_usdt_process_event+0x409> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_409;
	}
x86_l_3fb:
	/* 0x3fb: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_3ff:
	/* 0x3ff: jne    427 <generic_usdt_process_event+0x427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_427;
	}
x86_l_401:
	/* 0x401: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_407:
	/* 0x407: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_409:
	/* 0x409: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_40f:
	/* 0x40f: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_411:
	/* 0x411: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_417:
	/* 0x417: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_419:
	/* 0x419: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_41d:
	/* 0x41d: jne    427 <generic_usdt_process_event+0x427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_427;
	}
x86_l_41f:
	/* 0x41f: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_425:
	/* 0x425: jmp    42a <generic_usdt_process_event+0x42a> */
	goto x86_l_42a;
x86_l_427:
	/* 0x427: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_42a:
	/* 0x42a: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42f:
	/* 0x42f: mov    DWORD PTR [rsp+0xf4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1047972020224ULL);
x86_l_43a:
	/* 0x43a: mov    rdi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_441:
	/* 0x441: lea    rsi,[rsp+0xf4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_449:
	/* 0x449: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44e:
	/* 0x44e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_450:
	/* 0x450: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_453:
	/* 0x453: je     49a <generic_usdt_process_event+0x49a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_49a;
	}
x86_l_455:
	/* 0x455: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_45a:
	/* 0x45a: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_45d:
	/* 0x45d: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_460:
	/* 0x460: jbe    49a <generic_usdt_process_event+0x49a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_49a;
	}
x86_l_462:
	/* 0x462: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_465:
	/* 0x465: mov    ecx,DWORD PTR [rax+r13*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 24224ULL);
x86_l_46d:
	/* 0x46d: mov    DWORD PTR [rax+rbp*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 144ULL);
x86_l_474:
	/* 0x474: lea    r13,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_478:
	/* 0x478: mov    QWORD PTR [rax+r15*8+0x5e78],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 3), 24184ULL);
x86_l_480:
	/* 0x480: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_485:
	/* 0x485: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_487:
	/* 0x487: je     530 <generic_usdt_process_event+0x530> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_530;
	}
x86_l_48d:
	/* 0x48d: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_495:
	/* 0x495: jmp    d8e <generic_usdt_process_event+0xd8e> */
	return 3470ULL;
x86_l_49a:
	/* 0x49a: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_4a2:
	/* 0x4a2: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4a6:
	/* 0x4a6: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_4aa:
	/* 0x4aa: jg     da0 <generic_usdt_process_event+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3488ULL;
	}
x86_l_4b0:
	/* 0x4b0: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4bf:
	/* 0x4bf: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4c4:
	/* 0x4c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4c9:
	/* 0x4c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cb:
	/* 0x4cb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: je     da0 <generic_usdt_process_event+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3488ULL;
	}
x86_l_4d4:
	/* 0x4d4: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_4d7:
	/* 0x4d7: add    rsi,0x5ef8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 24312ULL);
x86_l_4de:
	/* 0x4de: mov    rdi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_4e5:
	/* 0x4e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ea:
	/* 0x4ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ec:
	/* 0x4ec: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4ef:
	/* 0x4ef: je     da0 <generic_usdt_process_event+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3488ULL;
	}
x86_l_4f5:
	/* 0x4f5: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_4f8:
	/* 0x4f8: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_4fb:
	/* 0x4fb: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_4fe:
	/* 0x4fe: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_503:
	/* 0x503: je     da0 <generic_usdt_process_event+0xda0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3488ULL;
	}
x86_l_509:
	/* 0x509: mov    DWORD PTR [r14+0x5efc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24316ULL);
x86_l_510:
	/* 0x510: mov    rsi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_517:
	/* 0x517: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_51c:
	/* 0x51c: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_521:
	/* 0x521: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_524:
	/* 0x524: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_529:
	/* 0x529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b:
	/* 0x52b: jmp    da0 <generic_usdt_process_event+0xda0> */
	return 3488ULL;
x86_l_530:
	/* 0x530: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_534:
	/* 0x534: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_53e:
	/* 0x53e: and    r13d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_545:
	/* 0x545: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_548:
	/* 0x548: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54d:
	/* 0x54d: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_552:
	/* 0x552: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_55e:
	/* 0x55e: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_562:
	/* 0x562: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56c:
	/* 0x56c: jle    5b1 <generic_usdt_process_event+0x5b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_5b1;
	}
x86_l_56e:
	/* 0x56e: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_572:
	/* 0x572: je     5cf <generic_usdt_process_event+0x5cf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5cf;
	}
x86_l_574:
	/* 0x574: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_578:
	/* 0x578: je     62b <generic_usdt_process_event+0x62b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_62b;
	}
x86_l_57e:
	/* 0x57e: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_582:
	/* 0x582: jne    ac3 <generic_usdt_process_event+0xac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2755ULL;
	}
x86_l_588:
	/* 0x588: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rsp+0x100],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_59c:
	/* 0x59c: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_5a4:
	/* 0x5a4: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_5ac:
	/* 0x5ac: jmp    6a1 <generic_usdt_process_event+0x6a1> */
	goto x86_l_6a1;
x86_l_5b1:
	/* 0x5b1: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_5b5:
	/* 0x5b5: je     662 <generic_usdt_process_event+0x662> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_662;
	}
x86_l_5bb:
	/* 0x5bb: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_5bf:
	/* 0x5bf: jne    ac3 <generic_usdt_process_event+0xac3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 2755ULL;
	}
x86_l_5c5:
	/* 0x5c5: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_5c8:
	/* 0x5c8: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5cd:
	/* 0x5cd: jmp    5fa <generic_usdt_process_event+0x5fa> */
	goto x86_l_5fa;
x86_l_5cf:
	/* 0x5cf: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: lea    r15,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d7:
	/* 0x5d7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5dc:
	/* 0x5dc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e1:
	/* 0x5e1: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5e6:
	/* 0x5e6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5e9:
	/* 0x5e9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ee:
	/* 0x5ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f0:
	/* 0x5f0: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5f5:
	/* 0x5f5: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5fa:
	/* 0x5fa: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5ff:
	/* 0x5ff: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_604:
	/* 0x604: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_609:
	/* 0x609: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_60e:
	/* 0x60e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_613:
	/* 0x613: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_615:
	/* 0x615: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_61a:
	/* 0x61a: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_61e:
	/* 0x61e: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_626:
	/* 0x626: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_629:
	/* 0x629: jmp    6a1 <generic_usdt_process_event+0x6a1> */
	goto x86_l_6a1;
x86_l_62b:
	/* 0x62b: add    rdx,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_62f:
	/* 0x62f: mov    QWORD PTR [rsp+0x50],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_634:
	/* 0x634: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_639:
	/* 0x639: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63e:
	/* 0x63e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_643:
	/* 0x643: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_648:
	/* 0x648: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_64d:
	/* 0x64d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64f:
	/* 0x64f: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_654:
	/* 0x654: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_658:
	/* 0x658: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_660:
	/* 0x660: jmp    6a1 <generic_usdt_process_event+0x6a1> */
	goto x86_l_6a1;
x86_l_662:
	/* 0x662: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_66a:
	/* 0x66a: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_672:
	/* 0x672: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_677:
	/* 0x677: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_67c:
	/* 0x67c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_681:
	/* 0x681: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_686:
	/* 0x686: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_688:
	/* 0x688: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_690:
	/* 0x690: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_698:
	/* 0x698: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_69b:
	/* 0x69b: je     b97 <generic_usdt_process_event+0xb97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 2967ULL;
	}
x86_l_6a1:
	/* 0x6a1: mov    DWORD PTR [rsp+0xac],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374912ULL);
x86_l_6ac:
	/* 0x6ac: mov    rdi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_6b3:
	/* 0x6b3: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_6bb:
	/* 0x6bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c0:
	/* 0x6c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c2:
	/* 0x6c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6c5:
	/* 0x6c5: je     782 <generic_usdt_process_event+0x782> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1922ULL;
	}
x86_l_6cb:
	/* 0x6cb: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6d3:
	/* 0x6d3: mov    QWORD PTR [rsp+0xd8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_6db:
	/* 0x6db: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_6e1:
	/* 0x6e1: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e6:
	/* 0x6e6: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_6eb:
	/* 0x6eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ed:
	/* 0x6ed: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_6f4:
	/* 0x6f4: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_6fc:
	/* 0x6fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
	return 1793ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1793ULL: goto x86_l_701;
	case 1798ULL: goto x86_l_706;
	case 1803ULL: goto x86_l_70b;
	case 1805ULL: goto x86_l_70d;
	case 1813ULL: goto x86_l_715;
	case 1821ULL: goto x86_l_71d;
	case 1825ULL: goto x86_l_721;
	case 1833ULL: goto x86_l_729;
	case 1838ULL: goto x86_l_72e;
	case 1843ULL: goto x86_l_733;
	case 1848ULL: goto x86_l_738;
	case 1856ULL: goto x86_l_740;
	case 1861ULL: goto x86_l_745;
	case 1866ULL: goto x86_l_74a;
	case 1868ULL: goto x86_l_74c;
	case 1876ULL: goto x86_l_754;
	case 1880ULL: goto x86_l_758;
	case 1885ULL: goto x86_l_75d;
	case 1890ULL: goto x86_l_762;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1902ULL: goto x86_l_76e;
	case 1908ULL: goto x86_l_774;
	case 1913ULL: goto x86_l_779;
	case 1915ULL: goto x86_l_77b;
	case 1920ULL: goto x86_l_780;
	case 1922ULL: goto x86_l_782;
	case 1925ULL: goto x86_l_785;
	case 1933ULL: goto x86_l_78d;
	case 1938ULL: goto x86_l_792;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1962ULL: goto x86_l_7aa;
	case 1964ULL: goto x86_l_7ac;
	case 1969ULL: goto x86_l_7b1;
	case 1974ULL: goto x86_l_7b6;
	case 1976ULL: goto x86_l_7b8;
	case 1979ULL: goto x86_l_7bb;
	case 1986ULL: goto x86_l_7c2;
	case 1996ULL: goto x86_l_7cc;
	case 2003ULL: goto x86_l_7d3;
	case 2013ULL: goto x86_l_7dd;
	case 2018ULL: goto x86_l_7e2;
	case 2027ULL: goto x86_l_7eb;
	case 2036ULL: goto x86_l_7f4;
	case 2041ULL: goto x86_l_7f9;
	case 2050ULL: goto x86_l_802;
	case 2059ULL: goto x86_l_80b;
	case 2068ULL: goto x86_l_814;
	case 2073ULL: goto x86_l_819;
	case 2081ULL: goto x86_l_821;
	case 2088ULL: goto x86_l_828;
	case 2096ULL: goto x86_l_830;
	case 2100ULL: goto x86_l_834;
	case 2105ULL: goto x86_l_839;
	case 2110ULL: goto x86_l_83e;
	case 2115ULL: goto x86_l_843;
	case 2120ULL: goto x86_l_848;
	case 2125ULL: goto x86_l_84d;
	case 2130ULL: goto x86_l_852;
	case 2135ULL: goto x86_l_857;
	case 2138ULL: goto x86_l_85a;
	case 2140ULL: goto x86_l_85c;
	case 2145ULL: goto x86_l_861;
	case 2150ULL: goto x86_l_866;
	case 2158ULL: goto x86_l_86e;
	case 2161ULL: goto x86_l_871;
	case 2166ULL: goto x86_l_876;
	case 2168ULL: goto x86_l_878;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2186ULL: goto x86_l_88a;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2198ULL: goto x86_l_896;
	case 2203ULL: goto x86_l_89b;
	case 2211ULL: goto x86_l_8a3;
	case 2214ULL: goto x86_l_8a6;
	case 2219ULL: goto x86_l_8ab;
	case 2221ULL: goto x86_l_8ad;
	case 2226ULL: goto x86_l_8b2;
	case 2230ULL: goto x86_l_8b6;
	case 2235ULL: goto x86_l_8bb;
	case 2242ULL: goto x86_l_8c2;
	case 2245ULL: goto x86_l_8c5;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2277ULL: goto x86_l_8e5;
	case 2282ULL: goto x86_l_8ea;
	case 2284ULL: goto x86_l_8ec;
	case 2289ULL: goto x86_l_8f1;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2308ULL: goto x86_l_904;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2323ULL: goto x86_l_913;
	case 2328ULL: goto x86_l_918;
	case 2334ULL: goto x86_l_91e;
	case 2338ULL: goto x86_l_922;
	case 2343ULL: goto x86_l_927;
	case 2348ULL: goto x86_l_92c;
	case 2353ULL: goto x86_l_931;
	case 2356ULL: goto x86_l_934;
	case 2358ULL: goto x86_l_936;
	case 2363ULL: goto x86_l_93b;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2379ULL: goto x86_l_94b;
	case 2384ULL: goto x86_l_950;
	case 2387ULL: goto x86_l_953;
	case 2389ULL: goto x86_l_955;
	case 2393ULL: goto x86_l_959;
	case 2398ULL: goto x86_l_95e;
	case 2406ULL: goto x86_l_966;
	case 2411ULL: goto x86_l_96b;
	case 2416ULL: goto x86_l_970;
	case 2419ULL: goto x86_l_973;
	case 2421ULL: goto x86_l_975;
	case 2426ULL: goto x86_l_97a;
	case 2434ULL: goto x86_l_982;
	case 2442ULL: goto x86_l_98a;
	case 2445ULL: goto x86_l_98d;
	case 2453ULL: goto x86_l_995;
	case 2456ULL: goto x86_l_998;
	case 2459ULL: goto x86_l_99b;
	case 2464ULL: goto x86_l_9a0;
	case 2467ULL: goto x86_l_9a3;
	case 2475ULL: goto x86_l_9ab;
	case 2477ULL: goto x86_l_9ad;
	case 2480ULL: goto x86_l_9b0;
	case 2484ULL: goto x86_l_9b4;
	case 2487ULL: goto x86_l_9b7;
	case 2491ULL: goto x86_l_9bb;
	case 2493ULL: goto x86_l_9bd;
	case 2496ULL: goto x86_l_9c0;
	case 2498ULL: goto x86_l_9c2;
	case 2505ULL: goto x86_l_9c9;
	case 2508ULL: goto x86_l_9cc;
	case 2513ULL: goto x86_l_9d1;
	case 2519ULL: goto x86_l_9d7;
	case 2525ULL: goto x86_l_9dd;
	case 2531ULL: goto x86_l_9e3;
	case 2534ULL: goto x86_l_9e6;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2543ULL: goto x86_l_9ef;
	case 2546ULL: goto x86_l_9f2;
	case 2550ULL: goto x86_l_9f6;
	case 2553ULL: goto x86_l_9f9;
	case 2556ULL: goto x86_l_9fc;
	case 2559ULL: goto x86_l_9ff;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2574ULL: goto x86_l_a0e;
	case 2577ULL: goto x86_l_a11;
	case 2583ULL: goto x86_l_a17;
	case 2588ULL: goto x86_l_a1c;
	case 2593ULL: goto x86_l_a21;
	case 2599ULL: goto x86_l_a27;
	case 2601ULL: goto x86_l_a29;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2617ULL: goto x86_l_a39;
	case 2622ULL: goto x86_l_a3e;
	case 2627ULL: goto x86_l_a43;
	case 2632ULL: goto x86_l_a48;
	case 2634ULL: goto x86_l_a4a;
	case 2639ULL: goto x86_l_a4f;
	case 2644ULL: goto x86_l_a54;
	case 2650ULL: goto x86_l_a5a;
	case 2656ULL: goto x86_l_a60;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2670ULL: goto x86_l_a6e;
	case 2675ULL: goto x86_l_a73;
	case 2678ULL: goto x86_l_a76;
	case 2680ULL: goto x86_l_a78;
	case 2685ULL: goto x86_l_a7d;
	case 2690ULL: goto x86_l_a82;
	case 2694ULL: goto x86_l_a86;
	case 2699ULL: goto x86_l_a8b;
	case 2704ULL: goto x86_l_a90;
	case 2706ULL: goto x86_l_a92;
	case 2712ULL: goto x86_l_a98;
	case 2717ULL: goto x86_l_a9d;
	case 2724ULL: goto x86_l_aa4;
	case 2726ULL: goto x86_l_aa6;
	case 2731ULL: goto x86_l_aab;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2750ULL: goto x86_l_abe;
	case 2755ULL: goto x86_l_ac3;
	case 2763ULL: goto x86_l_acb;
	case 2767ULL: goto x86_l_acf;
	case 2773ULL: goto x86_l_ad5;
	case 2776ULL: goto x86_l_ad8;
	case 2786ULL: goto x86_l_ae2;
	case 2790ULL: goto x86_l_ae6;
	case 2796ULL: goto x86_l_aec;
	case 2804ULL: goto x86_l_af4;
	case 2809ULL: goto x86_l_af9;
	case 2820ULL: goto x86_l_b04;
	case 2827ULL: goto x86_l_b0b;
	case 2835ULL: goto x86_l_b13;
	case 2840ULL: goto x86_l_b18;
	case 2842ULL: goto x86_l_b1a;
	case 2845ULL: goto x86_l_b1d;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2859ULL: goto x86_l_b2b;
	case 2863ULL: goto x86_l_b2f;
	case 2868ULL: goto x86_l_b34;
	case 2873ULL: goto x86_l_b39;
	case 2879ULL: goto x86_l_b3f;
	case 2883ULL: goto x86_l_b43;
	case 2888ULL: goto x86_l_b48;
	case 2894ULL: goto x86_l_b4e;
	case 2898ULL: goto x86_l_b52;
	case 2904ULL: goto x86_l_b58;
	case 2909ULL: goto x86_l_b5d;
	case 2912ULL: goto x86_l_b60;
	case 2918ULL: goto x86_l_b66;
	case 2923ULL: goto x86_l_b6b;
	case 2929ULL: goto x86_l_b71;
	case 2934ULL: goto x86_l_b76;
	case 2939ULL: goto x86_l_b7b;
	case 2944ULL: goto x86_l_b80;
	case 2949ULL: goto x86_l_b85;
	case 2954ULL: goto x86_l_b8a;
	case 2962ULL: goto x86_l_b92;
	case 2967ULL: goto x86_l_b97;
	case 2975ULL: goto x86_l_b9f;
	case 2986ULL: goto x86_l_baa;
	case 2993ULL: goto x86_l_bb1;
	case 3001ULL: goto x86_l_bb9;
	case 3006ULL: goto x86_l_bbe;
	case 3008ULL: goto x86_l_bc0;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3024ULL: goto x86_l_bd0;
	case 3030ULL: goto x86_l_bd6;
	case 3034ULL: goto x86_l_bda;
	case 3040ULL: goto x86_l_be0;
	case 3044ULL: goto x86_l_be4;
	case 3050ULL: goto x86_l_bea;
	case 3054ULL: goto x86_l_bee;
	case 3060ULL: goto x86_l_bf4;
	case 3064ULL: goto x86_l_bf8;
	case 3070ULL: goto x86_l_bfe;
	case 3074ULL: goto x86_l_c02;
	case 3079ULL: goto x86_l_c07;
	case 3084ULL: goto x86_l_c0c;
	case 3089ULL: goto x86_l_c11;
	case 3095ULL: goto x86_l_c17;
	case 3102ULL: goto x86_l_c1e;
	case 3105ULL: goto x86_l_c21;
	case 3111ULL: goto x86_l_c27;
	case 3116ULL: goto x86_l_c2c;
	case 3119ULL: goto x86_l_c2f;
	case 3124ULL: goto x86_l_c34;
	case 3129ULL: goto x86_l_c39;
	case 3134ULL: goto x86_l_c3e;
	case 3142ULL: goto x86_l_c46;
	case 3147ULL: goto x86_l_c4b;
	case 3155ULL: goto x86_l_c53;
	case 3160ULL: goto x86_l_c58;
	case 3162ULL: goto x86_l_c5a;
	case 3165ULL: goto x86_l_c5d;
	case 3167ULL: goto x86_l_c5f;
	case 3175ULL: goto x86_l_c67;
	case 3178ULL: goto x86_l_c6a;
	case 3185ULL: goto x86_l_c71;
	case 3191ULL: goto x86_l_c77;
	case 3194ULL: goto x86_l_c7a;
	case 3196ULL: goto x86_l_c7c;
	case 3200ULL: goto x86_l_c80;
	case 3203ULL: goto x86_l_c83;
	case 3211ULL: goto x86_l_c8b;
	case 3217ULL: goto x86_l_c91;
	case 3220ULL: goto x86_l_c94;
	case 3222ULL: goto x86_l_c96;
	case 3225ULL: goto x86_l_c99;
	case 3227ULL: goto x86_l_c9b;
	case 3230ULL: goto x86_l_c9e;
	case 3238ULL: goto x86_l_ca6;
	case 3243ULL: goto x86_l_cab;
	case 3247ULL: goto x86_l_caf;
	case 3254ULL: goto x86_l_cb6;
	case 3259ULL: goto x86_l_cbb;
	case 3262ULL: goto x86_l_cbe;
	case 3264ULL: goto x86_l_cc0;
	case 3268ULL: goto x86_l_cc4;
	case 3273ULL: goto x86_l_cc9;
	case 3278ULL: goto x86_l_cce;
	case 3283ULL: goto x86_l_cd3;
	case 3288ULL: goto x86_l_cd8;
	case 3293ULL: goto x86_l_cdd;
	case 3295ULL: goto x86_l_cdf;
	case 3300ULL: goto x86_l_ce4;
	case 3304ULL: goto x86_l_ce8;
	case 3312ULL: goto x86_l_cf0;
	case 3317ULL: goto x86_l_cf5;
	case 3322ULL: goto x86_l_cfa;
	case 3327ULL: goto x86_l_cff;
	case 3331ULL: goto x86_l_d03;
	case 3336ULL: goto x86_l_d08;
	case 3338ULL: goto x86_l_d0a;
	case 3346ULL: goto x86_l_d12;
	case 3351ULL: goto x86_l_d17;
	case 3356ULL: goto x86_l_d1c;
	case 3361ULL: goto x86_l_d21;
	case 3369ULL: goto x86_l_d29;
	case 3374ULL: goto x86_l_d2e;
	case 3376ULL: goto x86_l_d30;
	case 3381ULL: goto x86_l_d35;
	case 3386ULL: goto x86_l_d3a;
	case 3392ULL: goto x86_l_d40;
	case 3396ULL: goto x86_l_d44;
	case 3401ULL: goto x86_l_d49;
	case 3406ULL: goto x86_l_d4e;
	case 3411ULL: goto x86_l_d53;
	case 3414ULL: goto x86_l_d56;
	case 3416ULL: goto x86_l_d58;
	case 3424ULL: goto x86_l_d60;
	case 3435ULL: goto x86_l_d6b;
	case 3446ULL: goto x86_l_d76;
	case 3448ULL: goto x86_l_d78;
	case 3451ULL: goto x86_l_d7b;
	case 3456ULL: goto x86_l_d80;
	case 3463ULL: goto x86_l_d87;
	case 3467ULL: goto x86_l_d8b;
	case 3470ULL: goto x86_l_d8e;
	case 3472ULL: goto x86_l_d90;
	case 3474ULL: goto x86_l_d92;
	case 3478ULL: goto x86_l_d96;
	case 3482ULL: goto x86_l_d9a;
	case 3488ULL: goto x86_l_da0;
	case 3499ULL: goto x86_l_dab;
	case 3506ULL: goto x86_l_db2;
	case 3511ULL: goto x86_l_db7;
	case 3516ULL: goto x86_l_dbc;
	case 3519ULL: goto x86_l_dbf;
	case 3524ULL: goto x86_l_dc4;
	case 3526ULL: goto x86_l_dc6;
	case 3528ULL: goto x86_l_dc8;
	case 3535ULL: goto x86_l_dcf;
	case 3537ULL: goto x86_l_dd1;
	case 3538ULL: goto x86_l_dd2;
	case 3543ULL: goto x86_l_dd7;
	case 3547ULL: goto x86_l_ddb;
	case 3552ULL: goto x86_l_de0;
	case 3558ULL: goto x86_l_de6;
	case 3562ULL: goto x86_l_dea;
	case 3568ULL: goto x86_l_df0;
	case 3572ULL: goto x86_l_df4;
	case 3578ULL: goto x86_l_dfa;
	case 3582ULL: goto x86_l_dfe;
	case 3588ULL: goto x86_l_e04;
	case 3592ULL: goto x86_l_e08;
	case 3597ULL: goto x86_l_e0d;
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3611ULL: goto x86_l_e1b;
	case 3616ULL: goto x86_l_e20;
	case 3620ULL: goto x86_l_e24;
	case 3624ULL: goto x86_l_e28;
	case 3628ULL: goto x86_l_e2c;
	case 3633ULL: goto x86_l_e31;
	case 3638ULL: goto x86_l_e36;
	case 3643ULL: goto x86_l_e3b;
	case 3645ULL: goto x86_l_e3d;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3658ULL: goto x86_l_e4a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_701:
	/* 0x701: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_706:
	/* 0x706: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70b:
	/* 0x70b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70d:
	/* 0x70d: mov    r12,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_715:
	/* 0x715: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_71d:
	/* 0x71d: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_721:
	/* 0x721: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_729:
	/* 0x729: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_72e:
	/* 0x72e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_733:
	/* 0x733: lea    rcx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_738:
	/* 0x738: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_740:
	/* 0x740: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_745:
	/* 0x745: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_74a:
	/* 0x74a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74c:
	/* 0x74c: mov    r15,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_754:
	/* 0x754: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_758:
	/* 0x758: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_75d:
	/* 0x75d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_762:
	/* 0x762: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_767:
	/* 0x767: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_76c:
	/* 0x76c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76e:
	/* 0x76e: cmp    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_774:
	/* 0x774: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_779:
	/* 0x779: je     792 <generic_usdt_process_event+0x792> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_792;
	}
x86_l_77b:
	/* 0x77b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_780:
	/* 0x780: jmp    7e2 <generic_usdt_process_event+0x7e2> */
	goto x86_l_7e2;
x86_l_782:
	/* 0x782: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_785:
	/* 0x785: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_78d:
	/* 0x78d: jmp    d7b <generic_usdt_process_event+0xd7b> */
	goto x86_l_d7b;
x86_l_792:
	/* 0x792: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_796:
	/* 0x796: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_79b:
	/* 0x79b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7a0:
	/* 0x7a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7a5:
	/* 0x7a5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7aa:
	/* 0x7aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7ac:
	/* 0x7ac: cmp    QWORD PTR [rsp+0x50],r15 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7b1:
	/* 0x7b1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7b6:
	/* 0x7b6: je     7e2 <generic_usdt_process_event+0x7e2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_7e2;
	}
x86_l_7b8:
	/* 0x7b8: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_7bb:
	/* 0x7bb: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_7c2:
	/* 0x7c2: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_7cc:
	/* 0x7cc: mov    QWORD PTR [r13+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_7d3:
	/* 0x7d3: mov    WORD PTR [r13+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_7dd:
	/* 0x7dd: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_7e2:
	/* 0x7e2: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_7eb:
	/* 0x7eb: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_7f4:
	/* 0x7f4: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7f9:
	/* 0x7f9: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_802:
	/* 0x802: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_80b:
	/* 0x80b: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_814:
	/* 0x814: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_819:
	/* 0x819: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_821:
	/* 0x821: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_828:
	/* 0x828: mov    BYTE PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_830:
	/* 0x830: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_834:
	/* 0x834: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_839:
	/* 0x839: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_83e:
	/* 0x83e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_843:
	/* 0x843: lea    r13,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_848:
	/* 0x848: lea    r15,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_84d:
	/* 0x84d: lea    rbp,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_852:
	/* 0x852: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_857:
	/* 0x857: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_85a:
	/* 0x85a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_85c:
	/* 0x85c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_861:
	/* 0x861: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_866:
	/* 0x866: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_86e:
	/* 0x86e: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_871:
	/* 0x871: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_876:
	/* 0x876: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_878:
	/* 0x878: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_87d:
	/* 0x87d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_882:
	/* 0x882: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_887:
	/* 0x887: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_88a:
	/* 0x88a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88f:
	/* 0x88f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_891:
	/* 0x891: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_896:
	/* 0x896: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_89b:
	/* 0x89b: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_8a3:
	/* 0x8a3: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_8a6:
	/* 0x8a6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8ab:
	/* 0x8ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ad:
	/* 0x8ad: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8b2:
	/* 0x8b2: add    rax,0xffffffffffffffe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551584ULL);
x86_l_8b6:
	/* 0x8b6: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8bb:
	/* 0x8bb: mov    rax,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&CONFIG_ITER_NUM)));
x86_l_8c2:
	/* 0x8c2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c5:
	/* 0x8c5: je     a9d <generic_usdt_process_event+0xa9d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a9d;
	}
x86_l_8cb:
	/* 0x8cb: mov    ebp,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2048ULL);
x86_l_8d0:
	/* 0x8d0: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_8d6:
	/* 0x8d6: mov    r13,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8db:
	/* 0x8db: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8e0:
	/* 0x8e0: mov    r12,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8e5:
	/* 0x8e5: cmp    r13,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 80ULL);
x86_l_8ea:
	/* 0x8ea: jne    8f7 <generic_usdt_process_event+0x8f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8f7;
	}
x86_l_8ec:
	/* 0x8ec: cmp    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 88ULL);
x86_l_8f1:
	/* 0x8f1: je     b8a <generic_usdt_process_event+0xb8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b8a;
	}
x86_l_8f7:
	/* 0x8f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8fc:
	/* 0x8fc: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_904:
	/* 0x904: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_909:
	/* 0x909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90b:
	/* 0x90b: cmp    r13,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 208ULL);
x86_l_913:
	/* 0x913: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_918:
	/* 0x918: je     a34 <generic_usdt_process_event+0xa34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a34;
	}
x86_l_91e:
	/* 0x91e: lea    r15,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_922:
	/* 0x922: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_927:
	/* 0x927: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_92c:
	/* 0x92c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_931:
	/* 0x931: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_934:
	/* 0x934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_936:
	/* 0x936: cmp    QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_93b:
	/* 0x93b: je     a34 <generic_usdt_process_event+0xa34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a34;
	}
x86_l_941:
	/* 0x941: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_946:
	/* 0x946: lea    rdi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_94b:
	/* 0x94b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_950:
	/* 0x950: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_953:
	/* 0x953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_955:
	/* 0x955: add    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_959:
	/* 0x959: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_95e:
	/* 0x95e: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_966:
	/* 0x966: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_96b:
	/* 0x96b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_970:
	/* 0x970: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_973:
	/* 0x973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_975:
	/* 0x975: mov    r15,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_97a:
	/* 0x97a: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_982:
	/* 0x982: mov    r12d,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_98a:
	/* 0x98a: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_98d:
	/* 0x98d: mov    r13d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_995:
	/* 0x995: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_998:
	/* 0x998: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_99b:
	/* 0x99b: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_9a0:
	/* 0x9a0: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_9a3:
	/* 0x9a3: add    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 160ULL);
x86_l_9ab:
	/* 0x9ab: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ad:
	/* 0x9ad: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_9b0:
	/* 0x9b0: seta   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_A);
x86_l_9b4:
	/* 0x9b4: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_9b7:
	/* 0x9b7: cmovb  ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_B);
x86_l_9bb:
	/* 0x9bb: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9bd:
	/* 0x9bd: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_9c0:
	/* 0x9c0: sub    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9c2:
	/* 0x9c2: mov    DWORD PTR [rsp+0x88],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_9c9:
	/* 0x9c9: sub    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_9cc:
	/* 0x9cc: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9d1:
	/* 0x9d1: jb     c4b <generic_usdt_process_event+0xc4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_c4b;
	}
x86_l_9d7:
	/* 0x9d7: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_9dd:
	/* 0x9dd: ja     c4b <generic_usdt_process_event+0xc4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_c4b;
	}
x86_l_9e3:
	/* 0x9e3: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_9e6:
	/* 0x9e6: jbe    9ed <generic_usdt_process_event+0x9ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_9ed;
	}
x86_l_9e8:
	/* 0x9e8: mov    BYTE PTR [r15+rax*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 47ULL);
x86_l_9ed:
	/* 0x9ed: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ef:
	/* 0x9ef: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_9f2:
	/* 0x9f2: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_9f6:
	/* 0x9f6: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_9f9:
	/* 0x9f9: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9fc:
	/* 0x9fc: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9ff:
	/* 0x9ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a04:
	/* 0xa04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a06:
	/* 0xa06: mov    QWORD PTR [rsp+0x80],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a0e:
	/* 0xa0e: cmp    r13d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R13, X86_R12, X86_WIDTH_32);
x86_l_a11:
	/* 0xa11: jbe    c4b <generic_usdt_process_event+0xc4b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_c4b;
	}
x86_l_a17:
	/* 0xa17: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a1c:
	/* 0xa1c: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a21:
	/* 0xa21: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a27:
	/* 0xa27: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_a29:
	/* 0xa29: jne    8d6 <generic_usdt_process_event+0x8d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8d6;
	}
x86_l_a2f:
	/* 0xa2f: jmp    c4b <generic_usdt_process_event+0xc4b> */
	goto x86_l_c4b;
x86_l_a34:
	/* 0xa34: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a39:
	/* 0xa39: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a3e:
	/* 0xa3e: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a43:
	/* 0xa43: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a48:
	/* 0xa48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4a:
	/* 0xa4a: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a4f:
	/* 0xa4f: cmp    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 64ULL);
x86_l_a54:
	/* 0xa54: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a5a:
	/* 0xa5a: je     c3e <generic_usdt_process_event+0xc3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c3e;
	}
x86_l_a60:
	/* 0xa60: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a64:
	/* 0xa64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a69:
	/* 0xa69: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a6e:
	/* 0xa6e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a73:
	/* 0xa73: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_a76:
	/* 0xa76: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a78:
	/* 0xa78: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a7d:
	/* 0xa7d: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a82:
	/* 0xa82: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_a86:
	/* 0xa86: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a8b:
	/* 0xa8b: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a90:
	/* 0xa90: dec    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_a92:
	/* 0xa92: jne    8d6 <generic_usdt_process_event+0x8d6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8d6;
	}
x86_l_a98:
	/* 0xa98: jmp    c4b <generic_usdt_process_event+0xc4b> */
	goto x86_l_c4b;
x86_l_a9d:
	/* 0xa9d: lea    rsi,[rip+0x9df] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 2527ULL);
x86_l_aa4:
	/* 0xaa4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa6:
	/* 0xaa6: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aab:
	/* 0xaab: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_ab0:
	/* 0xab0: mov    eax,0xb5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 181ULL);
x86_l_ab5:
	/* 0xab5: mov    edi,0x800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2048ULL);
x86_l_aba:
	/* 0xaba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abc:
	/* 0xabc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abe:
	/* 0xabe: jmp    c4b <generic_usdt_process_event+0xc4b> */
	goto x86_l_c4b;
x86_l_ac3:
	/* 0xac3: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_acb:
	/* 0xacb: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_acf:
	/* 0xacf: ja     b97 <generic_usdt_process_event+0xb97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b97;
	}
x86_l_ad5:
	/* 0xad5: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_ad8:
	/* 0xad8: movabs rcx,0x11c1f2027cf2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19524686609650ULL);
x86_l_ae2:
	/* 0xae2: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_ae6:
	/* 0xae6: jae    b97 <generic_usdt_process_event+0xb97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b97;
	}
x86_l_aec:
	/* 0xaec: mov    QWORD PTR [rsp+0xd8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_af4:
	/* 0xaf4: mov    QWORD PTR [rsp+0x38],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_af9:
	/* 0xaf9: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_b04:
	/* 0xb04: mov    rdi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_b0b:
	/* 0xb0b: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_b13:
	/* 0xb13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b18:
	/* 0xb18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1a:
	/* 0xb1a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1d:
	/* 0xb1d: je     c2c <generic_usdt_process_event+0xc2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c2c;
	}
x86_l_b23:
	/* 0xb23: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b28:
	/* 0xb28: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b2b:
	/* 0xb2b: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_b2f:
	/* 0xb2f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b34:
	/* 0xb34: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_b39:
	/* 0xb39: jle    dd7 <generic_usdt_process_event+0xdd7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_dd7;
	}
x86_l_b3f:
	/* 0xb3f: cmp    r12d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 30ULL);
x86_l_b43:
	/* 0xb43: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b48:
	/* 0xb48: jle    f32 <generic_usdt_process_event+0xf32> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3890ULL;
	}
x86_l_b4e:
	/* 0xb4e: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_b52:
	/* 0xb52: jg     1028 <generic_usdt_process_event+0x1028> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4136ULL;
	}
x86_l_b58:
	/* 0xb58: lea    eax,[r12-0x1f] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551585ULL);
x86_l_b5d:
	/* 0xb5d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b60:
	/* 0xb60: jae    15a1 <generic_usdt_process_event+0x15a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5537ULL;
	}
x86_l_b66:
	/* 0xb66: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b6b:
	/* 0xb6b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_b71:
	/* 0xb71: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b7b:
	/* 0xb7b: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b80:
	/* 0xb80: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_b85:
	/* 0xb85: jmp    122c <generic_usdt_process_event+0x122c> */
	return 4652ULL;
x86_l_b8a:
	/* 0xb8a: mov    BYTE PTR [rsp+0x8c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 601295421441ULL);
x86_l_b92:
	/* 0xb92: jmp    c4b <generic_usdt_process_event+0xc4b> */
	goto x86_l_c4b;
x86_l_b97:
	/* 0xb97: mov    QWORD PTR [rsp+0xd8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_b9f:
	/* 0xb9f: mov    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_baa:
	/* 0xbaa: mov    rdi,QWORD PTR [rip+0x9dd] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_bb1:
	/* 0xbb1: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_bb9:
	/* 0xbb9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bbe:
	/* 0xbbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc0:
	/* 0xbc0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc3:
	/* 0xbc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bc6:
	/* 0xbc6: je     1e7a <generic_usdt_process_event+0x1e7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7802ULL;
	}
x86_l_bcc:
	/* 0xbcc: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_bd0:
	/* 0xbd0: jg     fe9 <generic_usdt_process_event+0xfe9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 4073ULL;
	}
x86_l_bd6:
	/* 0xbd6: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_bda:
	/* 0xbda: jle    114c <generic_usdt_process_event+0x114c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4428ULL;
	}
x86_l_be0:
	/* 0xbe0: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_be4:
	/* 0xbe4: jle    14be <generic_usdt_process_event+0x14be> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5310ULL;
	}
x86_l_bea:
	/* 0xbea: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_bee:
	/* 0xbee: je     1cff <generic_usdt_process_event+0x1cff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7423ULL;
	}
x86_l_bf4:
	/* 0xbf4: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_bf8:
	/* 0xbf8: je     1c7a <generic_usdt_process_event+0x1c7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7290ULL;
	}
x86_l_bfe:
	/* 0xbfe: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_c02:
	/* 0xc02: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c07:
	/* 0xc07: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c0c:
	/* 0xc0c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c11:
	/* 0xc11: jne    1e84 <generic_usdt_process_event+0x1e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7812ULL;
	}
x86_l_c17:
	/* 0xc17: mov    DWORD PTR [rbp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_c1e:
	/* 0xc1e: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c21:
	/* 0xc21: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_c27:
	/* 0xc27: jmp    1e84 <generic_usdt_process_event+0x1e84> */
	return 7812ULL;
x86_l_c2c:
	/* 0xc2c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c2f:
	/* 0xc2f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c34:
	/* 0xc34: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c39:
	/* 0xc39: jmp    2377 <generic_usdt_process_event+0x2377> */
	return 9079ULL;
x86_l_c3e:
	/* 0xc3e: mov    BYTE PTR [rsp+0x8c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 601295421441ULL);
x86_l_c46:
	/* 0xc46: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c4b:
	/* 0xc4b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c53:
	/* 0xc53: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c58:
	/* 0xc58: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5a:
	/* 0xc5a: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_c5d:
	/* 0xc5d: je     c9b <generic_usdt_process_event+0xc9b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c9b;
	}
x86_l_c5f:
	/* 0xc5f: cmp    BYTE PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_c67:
	/* 0xc67: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_c6a:
	/* 0xc6a: mov    edx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c71:
	/* 0xc71: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_c77:
	/* 0xc77: sub    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c7a:
	/* 0xc7a: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_c7c:
	/* 0xc7c: cmovle r15d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDX, X86_WIDTH_32, X86_CC_LE);
x86_l_c80:
	/* 0xc80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c83:
	/* 0xc83: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_c8b:
	/* 0xc8b: je     d78 <generic_usdt_process_event+0xd78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_d78;
	}
x86_l_c91:
	/* 0xc91: mov    bpl,cl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_8);
x86_l_c94:
	/* 0xc94: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c96:
	/* 0xc96: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c99:
	/* 0xc99: jmp    ca6 <generic_usdt_process_event+0xca6> */
	goto x86_l_ca6;
x86_l_c9b:
	/* 0xc9b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c9e:
	/* 0xc9e: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_ca6:
	/* 0xca6: mov    r13,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cab:
	/* 0xcab: lea    rdi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_caf:
	/* 0xcaf: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_cb6:
	/* 0xcb6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cbb:
	/* 0xcbb: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_cbe:
	/* 0xcbe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc0:
	/* 0xcc0: mov    DWORD PTR [r13+0x0],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc4:
	/* 0xcc4: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cc9:
	/* 0xcc9: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cce:
	/* 0xcce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cd3:
	/* 0xcd3: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cd8:
	/* 0xcd8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cdd:
	/* 0xcdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdf:
	/* 0xcdf: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ce4:
	/* 0xce4: add    rcx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_ce8:
	/* 0xce8: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_cf0:
	/* 0xcf0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_cf5:
	/* 0xcf5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cfa:
	/* 0xcfa: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cff:
	/* 0xcff: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_d03:
	/* 0xd03: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d08:
	/* 0xd08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d0a:
	/* 0xd0a: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d12:
	/* 0xd12: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d17:
	/* 0xd17: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_d1c:
	/* 0xd1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d21:
	/* 0xd21: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d29:
	/* 0xd29: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_d2e:
	/* 0xd2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d30:
	/* 0xd30: mov    DWORD PTR [r13+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_d35:
	/* 0xd35: movzx  eax,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_d3a:
	/* 0xd3a: mov    WORD PTR [r13+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_d40:
	/* 0xd40: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_d44:
	/* 0xd44: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d49:
	/* 0xd49: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d4e:
	/* 0xd4e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_d53:
	/* 0xd53: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_d56:
	/* 0xd56: jns    d80 <generic_usdt_process_event+0xd80> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_d80;
	}
x86_l_d58:
	/* 0xd58: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_d60:
	/* 0xd60: mov    DWORD PTR [rcx+rax*4+0x5ea0],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104045582745599ULL);
x86_l_d6b:
	/* 0xd6b: mov    DWORD PTR [rcx+rbp*1+0x90],0xffffffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 622770257919ULL);
x86_l_d76:
	/* 0xd76: jmp    d8e <generic_usdt_process_event+0xd8e> */
	goto x86_l_d8e;
x86_l_d78:
	/* 0xd78: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7b:
	/* 0xd7b: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d80:
	/* 0xd80: and    r15d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_d87:
	/* 0xd87: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_d8b:
	/* 0xd8b: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_d8e:
	/* 0xd8e: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d90:
	/* 0xd90: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_d92:
	/* 0xd92: mov    DWORD PTR [r14+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d96:
	/* 0xd96: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_d9a:
	/* 0xd9a: jle    4b0 <generic_usdt_process_event+0x4b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 1200ULL;
	}
x86_l_da0:
	/* 0xda0: mov    DWORD PTR [r14+0x5efc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104436424769536ULL);
x86_l_dab:
	/* 0xdab: mov    rsi,QWORD PTR [rip+0x9df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&usdt_calls)));
x86_l_db2:
	/* 0xdb2: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_db7:
	/* 0xdb7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_dbc:
	/* 0xdbc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_dc4:
	/* 0xdc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc6:
	/* 0xdc6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dc8:
	/* 0xdc8: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_dcf:
	/* 0xdcf: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_dd1:
	/* 0xdd1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_dd2:
	/* 0xdd2: jmp    3984 <__do_bytes+0xc4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_dd7:
	/* 0xdd7: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_ddb:
	/* 0xddb: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de0:
	/* 0xde0: jg     f64 <generic_usdt_process_event+0xf64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 3940ULL;
	}
x86_l_de6:
	/* 0xde6: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_dea:
	/* 0xdea: jle    11e1 <generic_usdt_process_event+0x11e1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 4577ULL;
	}
x86_l_df0:
	/* 0xdf0: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_df4:
	/* 0xdf4: je     178e <generic_usdt_process_event+0x178e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6030ULL;
	}
x86_l_dfa:
	/* 0xdfa: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_dfe:
	/* 0xdfe: je     fc6 <generic_usdt_process_event+0xfc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4038ULL;
	}
x86_l_e04:
	/* 0xe04: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_e08:
	/* 0xe08: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e0d:
	/* 0xe0d: jne    237c <generic_usdt_process_event+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9084ULL;
	}
x86_l_e13:
	/* 0xe13: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_e16:
	/* 0xe16: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e1b:
	/* 0xe1b: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e24:
	/* 0xe24: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_e28:
	/* 0xe28: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e2c:
	/* 0xe2c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e31:
	/* 0xe31: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e36:
	/* 0xe36: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e3b:
	/* 0xe3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3d:
	/* 0xe3d: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_e41:
	/* 0xe41: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_e45:
	/* 0xe45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e4a:
	/* 0xe4a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 3663ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3663ULL: goto x86_l_e4f;
	case 3668ULL: goto x86_l_e54;
	case 3670ULL: goto x86_l_e56;
	case 3674ULL: goto x86_l_e5a;
	case 3681ULL: goto x86_l_e61;
	case 3686ULL: goto x86_l_e66;
	case 3691ULL: goto x86_l_e6b;
	case 3696ULL: goto x86_l_e70;
	case 3698ULL: goto x86_l_e72;
	case 3702ULL: goto x86_l_e76;
	case 3709ULL: goto x86_l_e7d;
	case 3714ULL: goto x86_l_e82;
	case 3719ULL: goto x86_l_e87;
	case 3724ULL: goto x86_l_e8c;
	case 3726ULL: goto x86_l_e8e;
	case 3730ULL: goto x86_l_e92;
	case 3737ULL: goto x86_l_e99;
	case 3742ULL: goto x86_l_e9e;
	case 3747ULL: goto x86_l_ea3;
	case 3752ULL: goto x86_l_ea8;
	case 3754ULL: goto x86_l_eaa;
	case 3758ULL: goto x86_l_eae;
	case 3765ULL: goto x86_l_eb5;
	case 3770ULL: goto x86_l_eba;
	case 3775ULL: goto x86_l_ebf;
	case 3780ULL: goto x86_l_ec4;
	case 3782ULL: goto x86_l_ec6;
	case 3786ULL: goto x86_l_eca;
	case 3794ULL: goto x86_l_ed2;
	case 3802ULL: goto x86_l_eda;
	case 3810ULL: goto x86_l_ee2;
	case 3818ULL: goto x86_l_eea;
	case 3822ULL: goto x86_l_eee;
	case 3825ULL: goto x86_l_ef1;
	case 3831ULL: goto x86_l_ef7;
	case 3834ULL: goto x86_l_efa;
	case 3840ULL: goto x86_l_f00;
	case 3844ULL: goto x86_l_f04;
	case 3849ULL: goto x86_l_f09;
	case 3854ULL: goto x86_l_f0e;
	case 3857ULL: goto x86_l_f11;
	case 3862ULL: goto x86_l_f16;
	case 3864ULL: goto x86_l_f18;
	case 3869ULL: goto x86_l_f1d;
	case 3874ULL: goto x86_l_f22;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3885ULL: goto x86_l_f2d;
	case 3890ULL: goto x86_l_f32;
	case 3894ULL: goto x86_l_f36;
	case 3900ULL: goto x86_l_f3c;
	case 3904ULL: goto x86_l_f40;
	case 3910ULL: goto x86_l_f46;
	case 3914ULL: goto x86_l_f4a;
	case 3920ULL: goto x86_l_f50;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3935ULL: goto x86_l_f5f;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3948ULL: goto x86_l_f6c;
	case 3954ULL: goto x86_l_f72;
	case 3959ULL: goto x86_l_f77;
	case 3962ULL: goto x86_l_f7a;
	case 3968ULL: goto x86_l_f80;
	case 3972ULL: goto x86_l_f84;
	case 3978ULL: goto x86_l_f8a;
	case 3983ULL: goto x86_l_f8f;
	case 3988ULL: goto x86_l_f94;
	case 3993ULL: goto x86_l_f99;
	case 3998ULL: goto x86_l_f9e;
	case 4003ULL: goto x86_l_fa3;
	case 4006ULL: goto x86_l_fa6;
	case 4008ULL: goto x86_l_fa8;
	case 4013ULL: goto x86_l_fad;
	case 4018ULL: goto x86_l_fb2;
	case 4023ULL: goto x86_l_fb7;
	case 4028ULL: goto x86_l_fbc;
	case 4031ULL: goto x86_l_fbf;
	case 4036ULL: goto x86_l_fc4;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4053ULL: goto x86_l_fd5;
	case 4058ULL: goto x86_l_fda;
	case 4063ULL: goto x86_l_fdf;
	case 4068ULL: goto x86_l_fe4;
	case 4073ULL: goto x86_l_fe9;
	case 4077ULL: goto x86_l_fed;
	case 4082ULL: goto x86_l_ff2;
	case 4088ULL: goto x86_l_ff8;
	case 4093ULL: goto x86_l_ffd;
	case 4096ULL: goto x86_l_1000;
	case 4102ULL: goto x86_l_1006;
	case 4108ULL: goto x86_l_100c;
	case 4113ULL: goto x86_l_1011;
	case 4118ULL: goto x86_l_1016;
	case 4121ULL: goto x86_l_1019;
	case 4126ULL: goto x86_l_101e;
	case 4129ULL: goto x86_l_1021;
	case 4131ULL: goto x86_l_1023;
	case 4136ULL: goto x86_l_1028;
	case 4140ULL: goto x86_l_102c;
	case 4146ULL: goto x86_l_1032;
	case 4150ULL: goto x86_l_1036;
	case 4156ULL: goto x86_l_103c;
	case 4160ULL: goto x86_l_1040;
	case 4166ULL: goto x86_l_1046;
	case 4171ULL: goto x86_l_104b;
	case 4176ULL: goto x86_l_1050;
	case 4181ULL: goto x86_l_1055;
	case 4189ULL: goto x86_l_105d;
	case 4197ULL: goto x86_l_1065;
	case 4205ULL: goto x86_l_106d;
	case 4213ULL: goto x86_l_1075;
	case 4221ULL: goto x86_l_107d;
	case 4229ULL: goto x86_l_1085;
	case 4237ULL: goto x86_l_108d;
	case 4245ULL: goto x86_l_1095;
	case 4253ULL: goto x86_l_109d;
	case 4261ULL: goto x86_l_10a5;
	case 4269ULL: goto x86_l_10ad;
	case 4277ULL: goto x86_l_10b5;
	case 4285ULL: goto x86_l_10bd;
	case 4292ULL: goto x86_l_10c4;
	case 4297ULL: goto x86_l_10c9;
	case 4302ULL: goto x86_l_10ce;
	case 4307ULL: goto x86_l_10d3;
	case 4310ULL: goto x86_l_10d6;
	case 4312ULL: goto x86_l_10d8;
	case 4315ULL: goto x86_l_10db;
	case 4321ULL: goto x86_l_10e1;
	case 4325ULL: goto x86_l_10e5;
	case 4330ULL: goto x86_l_10ea;
	case 4335ULL: goto x86_l_10ef;
	case 4340ULL: goto x86_l_10f4;
	case 4345ULL: goto x86_l_10f9;
	case 4348ULL: goto x86_l_10fc;
	case 4350ULL: goto x86_l_10fe;
	case 4353ULL: goto x86_l_1101;
	case 4359ULL: goto x86_l_1107;
	case 4364ULL: goto x86_l_110c;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4377ULL: goto x86_l_1119;
	case 4383ULL: goto x86_l_111f;
	case 4388ULL: goto x86_l_1124;
	case 4393ULL: goto x86_l_1129;
	case 4398ULL: goto x86_l_112e;
	case 4401ULL: goto x86_l_1131;
	case 4403ULL: goto x86_l_1133;
	case 4405ULL: goto x86_l_1135;
	case 4410ULL: goto x86_l_113a;
	case 4415ULL: goto x86_l_113f;
	case 4421ULL: goto x86_l_1145;
	case 4423ULL: goto x86_l_1147;
	case 4428ULL: goto x86_l_114c;
	case 4432ULL: goto x86_l_1150;
	case 4438ULL: goto x86_l_1156;
	case 4442ULL: goto x86_l_115a;
	case 4448ULL: goto x86_l_1160;
	case 4453ULL: goto x86_l_1165;
	case 4457ULL: goto x86_l_1169;
	case 4462ULL: goto x86_l_116e;
	case 4467ULL: goto x86_l_1173;
	case 4473ULL: goto x86_l_1179;
	case 4476ULL: goto x86_l_117c;
	case 4483ULL: goto x86_l_1183;
	case 4491ULL: goto x86_l_118b;
	case 4494ULL: goto x86_l_118e;
	case 4497ULL: goto x86_l_1191;
	case 4503ULL: goto x86_l_1197;
	case 4506ULL: goto x86_l_119a;
	case 4512ULL: goto x86_l_11a0;
	case 4515ULL: goto x86_l_11a3;
	case 4521ULL: goto x86_l_11a9;
	case 4524ULL: goto x86_l_11ac;
	case 4530ULL: goto x86_l_11b2;
	case 4533ULL: goto x86_l_11b5;
	case 4539ULL: goto x86_l_11bb;
	case 4544ULL: goto x86_l_11c0;
	case 4549ULL: goto x86_l_11c5;
	case 4555ULL: goto x86_l_11cb;
	case 4560ULL: goto x86_l_11d0;
	case 4565ULL: goto x86_l_11d5;
	case 4570ULL: goto x86_l_11da;
	case 4575ULL: goto x86_l_11df;
	case 4577ULL: goto x86_l_11e1;
	case 4581ULL: goto x86_l_11e5;
	case 4583ULL: goto x86_l_11e7;
	case 4587ULL: goto x86_l_11eb;
	case 4593ULL: goto x86_l_11f1;
	case 4599ULL: goto x86_l_11f7;
	case 4604ULL: goto x86_l_11fc;
	case 4609ULL: goto x86_l_1201;
	case 4614ULL: goto x86_l_1206;
	case 4619ULL: goto x86_l_120b;
	case 4624ULL: goto x86_l_1210;
	case 4626ULL: goto x86_l_1212;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4647ULL: goto x86_l_1227;
	case 4652ULL: goto x86_l_122c;
	case 4654ULL: goto x86_l_122e;
	case 4659ULL: goto x86_l_1233;
	case 4664ULL: goto x86_l_1238;
	case 4672ULL: goto x86_l_1240;
	case 4677ULL: goto x86_l_1245;
	case 4682ULL: goto x86_l_124a;
	case 4686ULL: goto x86_l_124e;
	case 4692ULL: goto x86_l_1254;
	case 4696ULL: goto x86_l_1258;
	case 4701ULL: goto x86_l_125d;
	case 4706ULL: goto x86_l_1262;
	case 4712ULL: goto x86_l_1268;
	case 4716ULL: goto x86_l_126c;
	case 4721ULL: goto x86_l_1271;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4737ULL: goto x86_l_1281;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4747ULL: goto x86_l_128b;
	case 4752ULL: goto x86_l_1290;
	case 4755ULL: goto x86_l_1293;
	case 4761ULL: goto x86_l_1299;
	case 4765ULL: goto x86_l_129d;
	case 4769ULL: goto x86_l_12a1;
	case 4773ULL: goto x86_l_12a5;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4788ULL: goto x86_l_12b4;
	case 4790ULL: goto x86_l_12b6;
	case 4794ULL: goto x86_l_12ba;
	case 4798ULL: goto x86_l_12be;
	case 4803ULL: goto x86_l_12c3;
	case 4808ULL: goto x86_l_12c8;
	case 4813ULL: goto x86_l_12cd;
	case 4815ULL: goto x86_l_12cf;
	case 4819ULL: goto x86_l_12d3;
	case 4826ULL: goto x86_l_12da;
	case 4831ULL: goto x86_l_12df;
	case 4836ULL: goto x86_l_12e4;
	case 4841ULL: goto x86_l_12e9;
	case 4843ULL: goto x86_l_12eb;
	case 4847ULL: goto x86_l_12ef;
	case 4854ULL: goto x86_l_12f6;
	case 4859ULL: goto x86_l_12fb;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4871ULL: goto x86_l_1307;
	case 4875ULL: goto x86_l_130b;
	case 4882ULL: goto x86_l_1312;
	case 4887ULL: goto x86_l_1317;
	case 4892ULL: goto x86_l_131c;
	case 4894ULL: goto x86_l_131e;
	case 4898ULL: goto x86_l_1322;
	case 4905ULL: goto x86_l_1329;
	case 4910ULL: goto x86_l_132e;
	case 4915ULL: goto x86_l_1333;
	case 4917ULL: goto x86_l_1335;
	case 4921ULL: goto x86_l_1339;
	case 4929ULL: goto x86_l_1341;
	case 4937ULL: goto x86_l_1349;
	case 4945ULL: goto x86_l_1351;
	case 4953ULL: goto x86_l_1359;
	case 4956ULL: goto x86_l_135c;
	case 4960ULL: goto x86_l_1360;
	case 4963ULL: goto x86_l_1363;
	case 4969ULL: goto x86_l_1369;
	case 4972ULL: goto x86_l_136c;
	case 4978ULL: goto x86_l_1372;
	case 4982ULL: goto x86_l_1376;
	case 4987ULL: goto x86_l_137b;
	case 4992ULL: goto x86_l_1380;
	case 4995ULL: goto x86_l_1383;
	case 5000ULL: goto x86_l_1388;
	case 5002ULL: goto x86_l_138a;
	case 5007ULL: goto x86_l_138f;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5020ULL: goto x86_l_139c;
	case 5023ULL: goto x86_l_139f;
	case 5028ULL: goto x86_l_13a4;
	case 5032ULL: goto x86_l_13a8;
	case 5038ULL: goto x86_l_13ae;
	case 5042ULL: goto x86_l_13b2;
	case 5047ULL: goto x86_l_13b7;
	case 5052ULL: goto x86_l_13bc;
	case 5058ULL: goto x86_l_13c2;
	case 5061ULL: goto x86_l_13c5;
	case 5069ULL: goto x86_l_13cd;
	case 5077ULL: goto x86_l_13d5;
	case 5085ULL: goto x86_l_13dd;
	case 5093ULL: goto x86_l_13e5;
	case 5101ULL: goto x86_l_13ed;
	case 5109ULL: goto x86_l_13f5;
	case 5117ULL: goto x86_l_13fd;
	case 5125ULL: goto x86_l_1405;
	case 5133ULL: goto x86_l_140d;
	case 5141ULL: goto x86_l_1415;
	case 5144ULL: goto x86_l_1418;
	case 5148ULL: goto x86_l_141c;
	case 5152ULL: goto x86_l_1420;
	case 5157ULL: goto x86_l_1425;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5169ULL: goto x86_l_1431;
	case 5172ULL: goto x86_l_1434;
	case 5178ULL: goto x86_l_143a;
	case 5181ULL: goto x86_l_143d;
	case 5185ULL: goto x86_l_1441;
	case 5190ULL: goto x86_l_1446;
	case 5197ULL: goto x86_l_144d;
	case 5202ULL: goto x86_l_1452;
	case 5207ULL: goto x86_l_1457;
	case 5212ULL: goto x86_l_145c;
	case 5214ULL: goto x86_l_145e;
	case 5220ULL: goto x86_l_1464;
	case 5223ULL: goto x86_l_1467;
	case 5228ULL: goto x86_l_146c;
	case 5232ULL: goto x86_l_1470;
	case 5238ULL: goto x86_l_1476;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5252ULL: goto x86_l_1484;
	case 5257ULL: goto x86_l_1489;
	case 5263ULL: goto x86_l_148f;
	case 5271ULL: goto x86_l_1497;
	case 5278ULL: goto x86_l_149e;
	case 5281ULL: goto x86_l_14a1;
	case 5286ULL: goto x86_l_14a6;
	case 5289ULL: goto x86_l_14a9;
	case 5292ULL: goto x86_l_14ac;
	case 5294ULL: goto x86_l_14ae;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5305ULL: goto x86_l_14b9;
	case 5310ULL: goto x86_l_14be;
	case 5314ULL: goto x86_l_14c2;
	case 5320ULL: goto x86_l_14c8;
	case 5324ULL: goto x86_l_14cc;
	case 5329ULL: goto x86_l_14d1;
	case 5334ULL: goto x86_l_14d6;
	case 5339ULL: goto x86_l_14db;
	case 5345ULL: goto x86_l_14e1;
	case 5354ULL: goto x86_l_14ea;
	case 5361ULL: goto x86_l_14f1;
	case 5366ULL: goto x86_l_14f6;
	case 5371ULL: goto x86_l_14fb;
	case 5374ULL: goto x86_l_14fe;
	case 5379ULL: goto x86_l_1503;
	case 5386ULL: goto x86_l_150a;
	case 5391ULL: goto x86_l_150f;
	case 5393ULL: goto x86_l_1511;
	case 5398ULL: goto x86_l_1516;
	case 5403ULL: goto x86_l_151b;
	case 5408ULL: goto x86_l_1520;
	case 5413ULL: goto x86_l_1525;
	case 5416ULL: goto x86_l_1528;
	case 5421ULL: goto x86_l_152d;
	case 5423ULL: goto x86_l_152f;
	case 5430ULL: goto x86_l_1536;
	case 5435ULL: goto x86_l_153b;
	case 5440ULL: goto x86_l_1540;
	case 5445ULL: goto x86_l_1545;
	case 5448ULL: goto x86_l_1548;
	case 5450ULL: goto x86_l_154a;
	case 5457ULL: goto x86_l_1551;
	case 5464ULL: goto x86_l_1558;
	case 5469ULL: goto x86_l_155d;
	case 5474ULL: goto x86_l_1562;
	case 5479ULL: goto x86_l_1567;
	case 5481ULL: goto x86_l_1569;
	case 5488ULL: goto x86_l_1570;
	case 5495ULL: goto x86_l_1577;
	case 5500ULL: goto x86_l_157c;
	case 5505ULL: goto x86_l_1581;
	case 5508ULL: goto x86_l_1584;
	case 5513ULL: goto x86_l_1589;
	case 5516ULL: goto x86_l_158c;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	default: return 0xffffffffffffffffULL;
	}
x86_l_e4f:
	/* 0xe4f: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_e54:
	/* 0xe54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e56:
	/* 0xe56: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e5a:
	/* 0xe5a: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_e61:
	/* 0xe61: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e66:
	/* 0xe66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e6b:
	/* 0xe6b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e70:
	/* 0xe70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e72:
	/* 0xe72: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e76:
	/* 0xe76: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_e7d:
	/* 0xe7d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e82:
	/* 0xe82: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e87:
	/* 0xe87: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_e8c:
	/* 0xe8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8e:
	/* 0xe8e: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e92:
	/* 0xe92: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_e99:
	/* 0xe99: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e9e:
	/* 0xe9e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ea3:
	/* 0xea3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ea8:
	/* 0xea8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eaa:
	/* 0xeaa: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_eae:
	/* 0xeae: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_eb5:
	/* 0xeb5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_eba:
	/* 0xeba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ebf:
	/* 0xebf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ec4:
	/* 0xec4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec6:
	/* 0xec6: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_eca:
	/* 0xeca: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed2:
	/* 0xed2: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_eda:
	/* 0xeda: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ee2:
	/* 0xee2: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_eea:
	/* 0xeea: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_eee:
	/* 0xeee: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_ef1:
	/* 0xef1: je     2076 <generic_usdt_process_event+0x2076> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8310ULL;
	}
x86_l_ef7:
	/* 0xef7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_efa:
	/* 0xefa: jne    20a6 <generic_usdt_process_event+0x20a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8358ULL;
	}
x86_l_f00:
	/* 0xf00: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f04:
	/* 0xf04: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f09:
	/* 0xf09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f0e:
	/* 0xf0e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_f11:
	/* 0xf11: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f16:
	/* 0xf16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f18:
	/* 0xf18: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f1d:
	/* 0xf1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f22:
	/* 0xf22: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f25:
	/* 0xf25: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f2a:
	/* 0xf2a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_f2d:
	/* 0xf2d: jmp    20a4 <generic_usdt_process_event+0x20a4> */
	return 8356ULL;
x86_l_f32:
	/* 0xf32: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_f36:
	/* 0xf36: jg     11c0 <generic_usdt_process_event+0x11c0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_11c0;
	}
x86_l_f3c:
	/* 0xf3c: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_f40:
	/* 0xf40: je     15d5 <generic_usdt_process_event+0x15d5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5589ULL;
	}
x86_l_f46:
	/* 0xf46: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_f4a:
	/* 0xf4a: je     1699 <generic_usdt_process_event+0x1699> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5785ULL;
	}
x86_l_f50:
	/* 0xf50: cmp    r12d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 28ULL);
x86_l_f54:
	/* 0xf54: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f59:
	/* 0xf59: je     11f1 <generic_usdt_process_event+0x11f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f1;
	}
x86_l_f5f:
	/* 0xf5f: jmp    237c <generic_usdt_process_event+0x237c> */
	return 9084ULL;
x86_l_f64:
	/* 0xf64: lea    eax,[r12-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_f69:
	/* 0xf69: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f6c:
	/* 0xf6c: jb     11f1 <generic_usdt_process_event+0x11f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_11f1;
	}
x86_l_f72:
	/* 0xf72: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_f77:
	/* 0xf77: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f7a:
	/* 0xf7a: jb     1212 <generic_usdt_process_event+0x1212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1212;
	}
x86_l_f80:
	/* 0xf80: cmp    r12d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 14ULL);
x86_l_f84:
	/* 0xf84: jne    237c <generic_usdt_process_event+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9084ULL;
	}
x86_l_f8a:
	/* 0xf8a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f8f:
	/* 0xf8f: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f94:
	/* 0xf94: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f99:
	/* 0xf99: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f9e:
	/* 0xf9e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fa3:
	/* 0xfa3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fa6:
	/* 0xfa6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa8:
	/* 0xfa8: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fad:
	/* 0xfad: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_fb2:
	/* 0xfb2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fb7:
	/* 0xfb7: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fbc:
	/* 0xfbc: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_fbf:
	/* 0xfbf: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fc4:
	/* 0xfc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fc6:
	/* 0xfc6: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fcb:
	/* 0xfcb: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fd0:
	/* 0xfd0: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fd5:
	/* 0xfd5: mov    ecx,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4097ULL);
x86_l_fda:
	/* 0xfda: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_fdf:
	/* 0xfdf: mov    esi,0x1001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4097ULL);
x86_l_fe4:
	/* 0xfe4: jmp    196b <generic_usdt_process_event+0x196b> */
	return 6507ULL;
x86_l_fe9:
	/* 0xfe9: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_fed:
	/* 0xfed: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff2:
	/* 0xff2: jle    13a4 <generic_usdt_process_event+0x13a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13a4;
	}
x86_l_ff8:
	/* 0xff8: lea    ecx,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_ffd:
	/* 0xffd: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1000:
	/* 0x1000: jae    1245 <generic_usdt_process_event+0x1245> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1245;
	}
x86_l_1006:
	/* 0x1006: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_100c:
	/* 0x100c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1011:
	/* 0x1011: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1016:
	/* 0x1016: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1019:
	/* 0x1019: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_101e:
	/* 0x101e: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1021:
	/* 0x1021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1023:
	/* 0x1023: jmp    1e7a <generic_usdt_process_event+0x1e7a> */
	return 7802ULL;
x86_l_1028:
	/* 0x1028: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_102c:
	/* 0x102c: je     1948 <generic_usdt_process_event+0x1948> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6472ULL;
	}
x86_l_1032:
	/* 0x1032: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_1036:
	/* 0x1036: je     198a <generic_usdt_process_event+0x198a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6538ULL;
	}
x86_l_103c:
	/* 0x103c: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_1040:
	/* 0x1040: jne    237c <generic_usdt_process_event+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9084ULL;
	}
x86_l_1046:
	/* 0x1046: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_104b:
	/* 0x104b: mov    BYTE PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1050:
	/* 0x1050: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1055:
	/* 0x1055: mov    QWORD PTR [rdi+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_105d:
	/* 0x105d: mov    QWORD PTR [rdi+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1065:
	/* 0x1065: mov    QWORD PTR [rdi+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_106d:
	/* 0x106d: mov    QWORD PTR [rdi+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1075:
	/* 0x1075: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_107d:
	/* 0x107d: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1085:
	/* 0x1085: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_108d:
	/* 0x108d: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1095:
	/* 0x1095: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_109d:
	/* 0x109d: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10a5:
	/* 0x10a5: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10ad:
	/* 0x10ad: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_10b5:
	/* 0x10b5: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10bd:
	/* 0x10bd: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c4:
	/* 0x10c4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10c9:
	/* 0x10c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10ce:
	/* 0x10ce: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_10d3:
	/* 0x10d3: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_10d6:
	/* 0x10d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d8:
	/* 0x10d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10db:
	/* 0x10db: js     236c <generic_usdt_process_event+0x236c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9068ULL;
	}
x86_l_10e1:
	/* 0x10e1: lea    r12,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_10e5:
	/* 0x10e5: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_10ea:
	/* 0x10ea: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10ef:
	/* 0x10ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10f4:
	/* 0x10f4: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_10f9:
	/* 0x10f9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_10fc:
	/* 0x10fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fe:
	/* 0x10fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1101:
	/* 0x1101: js     236c <generic_usdt_process_event+0x236c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9068ULL;
	}
x86_l_1107:
	/* 0x1107: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_110c:
	/* 0x110c: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1110:
	/* 0x1110: cmp    BYTE PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1115:
	/* 0x1115: sete   BYTE PTR [rax+0x2] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RAX, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_E)), 2ULL);
x86_l_1119:
	/* 0x1119: je     2339 <generic_usdt_process_event+0x2339> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9017ULL;
	}
x86_l_111f:
	/* 0x111f: mov    ecx,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 108ULL);
x86_l_1124:
	/* 0x1124: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1129:
	/* 0x1129: mov    esi,0x6c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 108ULL);
x86_l_112e:
	/* 0x112e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1131:
	/* 0x1131: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1133:
	/* 0x1133: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1135:
	/* 0x1135: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_113a:
	/* 0x113a: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_113f:
	/* 0x113f: js     236c <generic_usdt_process_event+0x236c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9068ULL;
	}
x86_l_1145:
	/* 0x1145: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_1147:
	/* 0x1147: jmp    2364 <generic_usdt_process_event+0x2364> */
	return 9060ULL;
x86_l_114c:
	/* 0x114c: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1150:
	/* 0x1150: jg     146c <generic_usdt_process_event+0x146c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_146c;
	}
x86_l_1156:
	/* 0x1156: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_115a:
	/* 0x115a: je     1a23 <generic_usdt_process_event+0x1a23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6691ULL;
	}
x86_l_1160:
	/* 0x1160: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1165:
	/* 0x1165: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1169:
	/* 0x1169: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_116e:
	/* 0x116e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1173:
	/* 0x1173: jne    1e84 <generic_usdt_process_event+0x1e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7812ULL;
	}
x86_l_1179:
	/* 0x1179: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_117c:
	/* 0x117c: lea    r12,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1183:
	/* 0x1183: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_118b:
	/* 0x118b: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_118e:
	/* 0x118e: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1191:
	/* 0x1191: jle    21f0 <generic_usdt_process_event+0x21f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 8688ULL;
	}
x86_l_1197:
	/* 0x1197: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_119a:
	/* 0x119a: je     2464 <generic_usdt_process_event+0x2464> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9316ULL;
	}
x86_l_11a0:
	/* 0x11a0: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11a3:
	/* 0x11a3: je     246f <generic_usdt_process_event+0x246f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9327ULL;
	}
x86_l_11a9:
	/* 0x11a9: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_11ac:
	/* 0x11ac: jne    2895 <generic_usdt_process_event+0x2895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10389ULL;
	}
x86_l_11b2:
	/* 0x11b2: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_11b5:
	/* 0x11b5: add    rax,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_11bb:
	/* 0x11bb: jmp    2483 <generic_usdt_process_event+0x2483> */
	return 9347ULL;
x86_l_11c0:
	/* 0x11c0: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11c5:
	/* 0x11c5: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_11cb:
	/* 0x11cb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11d0:
	/* 0x11d0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_11d5:
	/* 0x11d5: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11da:
	/* 0x11da: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_11df:
	/* 0x11df: jmp    122c <generic_usdt_process_event+0x122c> */
	goto x86_l_122c;
x86_l_11e1:
	/* 0x11e1: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_11e5:
	/* 0x11e5: je     1212 <generic_usdt_process_event+0x1212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1212;
	}
x86_l_11e7:
	/* 0x11e7: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_11eb:
	/* 0x11eb: jne    237c <generic_usdt_process_event+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9084ULL;
	}
x86_l_11f1:
	/* 0x11f1: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_11f7:
	/* 0x11f7: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11fc:
	/* 0x11fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1201:
	/* 0x1201: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1206:
	/* 0x1206: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_120b:
	/* 0x120b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1210:
	/* 0x1210: jmp    122c <generic_usdt_process_event+0x122c> */
	goto x86_l_122c;
x86_l_1212:
	/* 0x1212: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1217:
	/* 0x1217: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_121d:
	/* 0x121d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1222:
	/* 0x1222: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1227:
	/* 0x1227: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_122c:
	/* 0x122c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122e:
	/* 0x122e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1233:
	/* 0x1233: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1238:
	/* 0x1238: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1240:
	/* 0x1240: jmp    d53 <generic_usdt_process_event+0xd53> */
	return 3411ULL;
x86_l_1245:
	/* 0x1245: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_124a:
	/* 0x124a: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_124e:
	/* 0x124e: je     1de8 <generic_usdt_process_event+0x1de8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7656ULL;
	}
x86_l_1254:
	/* 0x1254: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_1258:
	/* 0x1258: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_125d:
	/* 0x125d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1262:
	/* 0x1262: jne    1e84 <generic_usdt_process_event+0x1e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7812ULL;
	}
x86_l_1268:
	/* 0x1268: add    r8,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_126c:
	/* 0x126c: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1271:
	/* 0x1271: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1277:
	/* 0x1277: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_127c:
	/* 0x127c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1281:
	/* 0x1281: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1286:
	/* 0x1286: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_128b:
	/* 0x128b: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1290:
	/* 0x1290: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1293:
	/* 0x1293: je     241e <generic_usdt_process_event+0x241e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9246ULL;
	}
x86_l_1299:
	/* 0x1299: mov    QWORD PTR [rbp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_129d:
	/* 0x129d: lea    rdi,[rbp+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_12a1:
	/* 0x12a1: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12a5:
	/* 0x12a5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12aa:
	/* 0x12aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12af:
	/* 0x12af: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12b4:
	/* 0x12b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12b6:
	/* 0x12b6: lea    rdi,[rbp+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_12ba:
	/* 0x12ba: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_12be:
	/* 0x12be: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12c3:
	/* 0x12c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c8:
	/* 0x12c8: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_12cd:
	/* 0x12cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cf:
	/* 0x12cf: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12d3:
	/* 0x12d3: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_12da:
	/* 0x12da: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12df:
	/* 0x12df: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12e4:
	/* 0x12e4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_12e9:
	/* 0x12e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12eb:
	/* 0x12eb: lea    rdi,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12ef:
	/* 0x12ef: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_12f6:
	/* 0x12f6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12fb:
	/* 0x12fb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1300:
	/* 0x1300: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1305:
	/* 0x1305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1307:
	/* 0x1307: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_130b:
	/* 0x130b: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_1312:
	/* 0x1312: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1317:
	/* 0x1317: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_131c:
	/* 0x131c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131e:
	/* 0x131e: lea    rdi,[rbp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1322:
	/* 0x1322: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_1329:
	/* 0x1329: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_132e:
	/* 0x132e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1333:
	/* 0x1333: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1335:
	/* 0x1335: lea    r12,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1339:
	/* 0x1339: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1341:
	/* 0x1341: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1349:
	/* 0x1349: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1351:
	/* 0x1351: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1359:
	/* 0x1359: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: movzx  eax,WORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1360:
	/* 0x1360: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1363:
	/* 0x1363: je     23a7 <generic_usdt_process_event+0x23a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9127ULL;
	}
x86_l_1369:
	/* 0x1369: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_136c:
	/* 0x136c: jne    23d7 <generic_usdt_process_event+0x23d7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9175ULL;
	}
x86_l_1372:
	/* 0x1372: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1376:
	/* 0x1376: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_137b:
	/* 0x137b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1380:
	/* 0x1380: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1383:
	/* 0x1383: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1388:
	/* 0x1388: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138a:
	/* 0x138a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_138f:
	/* 0x138f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1394:
	/* 0x1394: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1397:
	/* 0x1397: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_139c:
	/* 0x139c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_139f:
	/* 0x139f: jmp    23d5 <generic_usdt_process_event+0x23d5> */
	return 9173ULL;
x86_l_13a4:
	/* 0x13a4: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_13a8:
	/* 0x13a8: je     1e96 <generic_usdt_process_event+0x1e96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7830ULL;
	}
x86_l_13ae:
	/* 0x13ae: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_13b2:
	/* 0x13b2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13b7:
	/* 0x13b7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_13bc:
	/* 0x13bc: jne    1e84 <generic_usdt_process_event+0x1e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7812ULL;
	}
x86_l_13c2:
	/* 0x13c2: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_13c5:
	/* 0x13c5: mov    QWORD PTR [rbp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_13cd:
	/* 0x13cd: mov    QWORD PTR [rbp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13d5:
	/* 0x13d5: mov    QWORD PTR [rbp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_13dd:
	/* 0x13dd: mov    QWORD PTR [rbp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_13e5:
	/* 0x13e5: mov    QWORD PTR [rbp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13ed:
	/* 0x13ed: mov    QWORD PTR [rbp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13f5:
	/* 0x13f5: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_13fd:
	/* 0x13fd: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1405:
	/* 0x1405: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_140d:
	/* 0x140d: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1415:
	/* 0x1415: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: lea    rdi,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_141c:
	/* 0x141c: lea    rdx,[r8+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1420:
	/* 0x1420: mov    ecx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 63ULL);
x86_l_1425:
	/* 0x1425: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_142a:
	/* 0x142a: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_142f:
	/* 0x142f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1431:
	/* 0x1431: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1434:
	/* 0x1434: js     232e <generic_usdt_process_event+0x232e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9006ULL;
	}
x86_l_143a:
	/* 0x143a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_143d:
	/* 0x143d: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1441:
	/* 0x1441: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1446:
	/* 0x1446: add    rdx,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_144d:
	/* 0x144d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1452:
	/* 0x1452: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1457:
	/* 0x1457: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_145c:
	/* 0x145c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145e:
	/* 0x145e: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1464:
	/* 0x1464: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_1467:
	/* 0x1467: jmp    2c1b <generic_usdt_process_event+0x2c1b> */
	return 11291ULL;
x86_l_146c:
	/* 0x146c: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1470:
	/* 0x1470: je     1a88 <generic_usdt_process_event+0x1a88> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6792ULL;
	}
x86_l_1476:
	/* 0x1476: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_147a:
	/* 0x147a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_147f:
	/* 0x147f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1484:
	/* 0x1484: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1489:
	/* 0x1489: jne    1e84 <generic_usdt_process_event+0x1e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7812ULL;
	}
x86_l_148f:
	/* 0x148f: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1497:
	/* 0x1497: and    r12d,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_149e:
	/* 0x149e: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_14a1:
	/* 0x14a1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14a6:
	/* 0x14a6: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_14a9:
	/* 0x14a9: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_14ac:
	/* 0x14ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ae:
	/* 0x14ae: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14b3:
	/* 0x14b3: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_14b6:
	/* 0x14b6: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_14b9:
	/* 0x14b9: jmp    1e84 <generic_usdt_process_event+0x1e84> */
	return 7812ULL;
x86_l_14be:
	/* 0x14be: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_14c2:
	/* 0x14c2: je     1d91 <generic_usdt_process_event+0x1d91> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7569ULL;
	}
x86_l_14c8:
	/* 0x14c8: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_14cc:
	/* 0x14cc: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14d1:
	/* 0x14d1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_14d6:
	/* 0x14d6: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14db:
	/* 0x14db: jne    1e84 <generic_usdt_process_event+0x1e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7812ULL;
	}
x86_l_14e1:
	/* 0x14e1: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_14ea:
	/* 0x14ea: lea    rdx,[r13+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_14f1:
	/* 0x14f1: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14f6:
	/* 0x14f6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14fb:
	/* 0x14fb: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_14fe:
	/* 0x14fe: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1503:
	/* 0x1503: lea    r15,[r13+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_150a:
	/* 0x150a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_150f:
	/* 0x150f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1511:
	/* 0x1511: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1516:
	/* 0x1516: mov    edx,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 128ULL);
x86_l_151b:
	/* 0x151b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1520:
	/* 0x1520: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1525:
	/* 0x1525: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1528:
	/* 0x1528: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_152d:
	/* 0x152d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152f:
	/* 0x152f: lea    rdi,[rbp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1536:
	/* 0x1536: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_153b:
	/* 0x153b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1540:
	/* 0x1540: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1545:
	/* 0x1545: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1548:
	/* 0x1548: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154a:
	/* 0x154a: lea    rdi,[rbp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1551:
	/* 0x1551: lea    rdx,[r13+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1558:
	/* 0x1558: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_155d:
	/* 0x155d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1562:
	/* 0x1562: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1567:
	/* 0x1567: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1569:
	/* 0x1569: add    rbp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1570:
	/* 0x1570: add    r13,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_1577:
	/* 0x1577: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_157c:
	/* 0x157c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1581:
	/* 0x1581: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1584:
	/* 0x1584: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1589:
	/* 0x1589: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_158c:
	/* 0x158c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158e:
	/* 0x158e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1593:
	/* 0x1593: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
	return 5526ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5526ULL: goto x86_l_1596;
	case 5532ULL: goto x86_l_159c;
	case 5537ULL: goto x86_l_15a1;
	case 5541ULL: goto x86_l_15a5;
	case 5547ULL: goto x86_l_15ab;
	case 5552ULL: goto x86_l_15b0;
	case 5555ULL: goto x86_l_15b3;
	case 5558ULL: goto x86_l_15b6;
	case 5561ULL: goto x86_l_15b9;
	case 5567ULL: goto x86_l_15bf;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5579ULL: goto x86_l_15cb;
	case 5584ULL: goto x86_l_15d0;
	case 5589ULL: goto x86_l_15d5;
	case 5598ULL: goto x86_l_15de;
	case 5603ULL: goto x86_l_15e3;
	case 5605ULL: goto x86_l_15e5;
	case 5609ULL: goto x86_l_15e9;
	case 5614ULL: goto x86_l_15ee;
	case 5622ULL: goto x86_l_15f6;
	case 5627ULL: goto x86_l_15fb;
	case 5632ULL: goto x86_l_1600;
	case 5637ULL: goto x86_l_1605;
	case 5643ULL: goto x86_l_160b;
	case 5648ULL: goto x86_l_1610;
	case 5650ULL: goto x86_l_1612;
	case 5657ULL: goto x86_l_1619;
	case 5661ULL: goto x86_l_161d;
	case 5668ULL: goto x86_l_1624;
	case 5673ULL: goto x86_l_1629;
	case 5678ULL: goto x86_l_162e;
	case 5680ULL: goto x86_l_1630;
	case 5683ULL: goto x86_l_1633;
	case 5689ULL: goto x86_l_1639;
	case 5692ULL: goto x86_l_163c;
	case 5700ULL: goto x86_l_1644;
	case 5703ULL: goto x86_l_1647;
	case 5708ULL: goto x86_l_164c;
	case 5713ULL: goto x86_l_1651;
	case 5716ULL: goto x86_l_1654;
	case 5721ULL: goto x86_l_1659;
	case 5723ULL: goto x86_l_165b;
	case 5730ULL: goto x86_l_1662;
	case 5734ULL: goto x86_l_1666;
	case 5738ULL: goto x86_l_166a;
	case 5743ULL: goto x86_l_166f;
	case 5746ULL: goto x86_l_1672;
	case 5748ULL: goto x86_l_1674;
	case 5752ULL: goto x86_l_1678;
	case 5756ULL: goto x86_l_167c;
	case 5760ULL: goto x86_l_1680;
	case 5764ULL: goto x86_l_1684;
	case 5769ULL: goto x86_l_1689;
	case 5774ULL: goto x86_l_168e;
	case 5776ULL: goto x86_l_1690;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5788ULL: goto x86_l_169c;
	case 5793ULL: goto x86_l_16a1;
	case 5801ULL: goto x86_l_16a9;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5816ULL: goto x86_l_16b8;
	case 5819ULL: goto x86_l_16bb;
	case 5821ULL: goto x86_l_16bd;
	case 5829ULL: goto x86_l_16c5;
	case 5831ULL: goto x86_l_16c7;
	case 5837ULL: goto x86_l_16cd;
	case 5840ULL: goto x86_l_16d0;
	case 5846ULL: goto x86_l_16d6;
	case 5850ULL: goto x86_l_16da;
	case 5855ULL: goto x86_l_16df;
	case 5861ULL: goto x86_l_16e5;
	case 5866ULL: goto x86_l_16ea;
	case 5871ULL: goto x86_l_16ef;
	case 5876ULL: goto x86_l_16f4;
	case 5879ULL: goto x86_l_16f7;
	case 5881ULL: goto x86_l_16f9;
	case 5886ULL: goto x86_l_16fe;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5904ULL: goto x86_l_1710;
	case 5909ULL: goto x86_l_1715;
	case 5911ULL: goto x86_l_1717;
	case 5916ULL: goto x86_l_171c;
	case 5920ULL: goto x86_l_1720;
	case 5925ULL: goto x86_l_1725;
	case 5930ULL: goto x86_l_172a;
	case 5935ULL: goto x86_l_172f;
	case 5940ULL: goto x86_l_1734;
	case 5942ULL: goto x86_l_1736;
	case 5950ULL: goto x86_l_173e;
	case 5955ULL: goto x86_l_1743;
	case 5960ULL: goto x86_l_1748;
	case 5968ULL: goto x86_l_1750;
	case 5971ULL: goto x86_l_1753;
	case 5976ULL: goto x86_l_1758;
	case 5982ULL: goto x86_l_175e;
	case 5991ULL: goto x86_l_1767;
	case 5997ULL: goto x86_l_176d;
	case 6005ULL: goto x86_l_1775;
	case 6009ULL: goto x86_l_1779;
	case 6014ULL: goto x86_l_177e;
	case 6017ULL: goto x86_l_1781;
	case 6020ULL: goto x86_l_1784;
	case 6025ULL: goto x86_l_1789;
	case 6030ULL: goto x86_l_178e;
	case 6035ULL: goto x86_l_1793;
	case 6040ULL: goto x86_l_1798;
	case 6044ULL: goto x86_l_179c;
	case 6052ULL: goto x86_l_17a4;
	case 6057ULL: goto x86_l_17a9;
	case 6062ULL: goto x86_l_17ae;
	case 6064ULL: goto x86_l_17b0;
	case 6068ULL: goto x86_l_17b4;
	case 6073ULL: goto x86_l_17b9;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6088ULL: goto x86_l_17c8;
	case 6090ULL: goto x86_l_17ca;
	case 6094ULL: goto x86_l_17ce;
	case 6102ULL: goto x86_l_17d6;
	case 6107ULL: goto x86_l_17db;
	case 6112ULL: goto x86_l_17e0;
	case 6117ULL: goto x86_l_17e5;
	case 6119ULL: goto x86_l_17e7;
	case 6123ULL: goto x86_l_17eb;
	case 6131ULL: goto x86_l_17f3;
	case 6136ULL: goto x86_l_17f8;
	case 6141ULL: goto x86_l_17fd;
	case 6146ULL: goto x86_l_1802;
	case 6148ULL: goto x86_l_1804;
	case 6157ULL: goto x86_l_180d;
	case 6165ULL: goto x86_l_1815;
	case 6170ULL: goto x86_l_181a;
	case 6175ULL: goto x86_l_181f;
	case 6180ULL: goto x86_l_1824;
	case 6185ULL: goto x86_l_1829;
	case 6187ULL: goto x86_l_182b;
	case 6195ULL: goto x86_l_1833;
	case 6203ULL: goto x86_l_183b;
	case 6208ULL: goto x86_l_1840;
	case 6213ULL: goto x86_l_1845;
	case 6218ULL: goto x86_l_184a;
	case 6220ULL: goto x86_l_184c;
	case 6229ULL: goto x86_l_1855;
	case 6234ULL: goto x86_l_185a;
	case 6242ULL: goto x86_l_1862;
	case 6247ULL: goto x86_l_1867;
	case 6252ULL: goto x86_l_186c;
	case 6257ULL: goto x86_l_1871;
	case 6260ULL: goto x86_l_1874;
	case 6262ULL: goto x86_l_1876;
	case 6270ULL: goto x86_l_187e;
	case 6273ULL: goto x86_l_1881;
	case 6276ULL: goto x86_l_1884;
	case 6282ULL: goto x86_l_188a;
	case 6285ULL: goto x86_l_188d;
	case 6291ULL: goto x86_l_1893;
	case 6295ULL: goto x86_l_1897;
	case 6303ULL: goto x86_l_189f;
	case 6308ULL: goto x86_l_18a4;
	case 6313ULL: goto x86_l_18a9;
	case 6318ULL: goto x86_l_18ae;
	case 6320ULL: goto x86_l_18b0;
	case 6328ULL: goto x86_l_18b8;
	case 6333ULL: goto x86_l_18bd;
	case 6337ULL: goto x86_l_18c1;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6354ULL: goto x86_l_18d2;
	case 6362ULL: goto x86_l_18da;
	case 6370ULL: goto x86_l_18e2;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6388ULL: goto x86_l_18f4;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6399ULL: goto x86_l_18ff;
	case 6403ULL: goto x86_l_1903;
	case 6408ULL: goto x86_l_1908;
	case 6413ULL: goto x86_l_190d;
	case 6416ULL: goto x86_l_1910;
	case 6421ULL: goto x86_l_1915;
	case 6424ULL: goto x86_l_1918;
	case 6426ULL: goto x86_l_191a;
	case 6434ULL: goto x86_l_1922;
	case 6442ULL: goto x86_l_192a;
	case 6447ULL: goto x86_l_192f;
	case 6452ULL: goto x86_l_1934;
	case 6457ULL: goto x86_l_1939;
	case 6459ULL: goto x86_l_193b;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6487ULL: goto x86_l_1957;
	case 6492ULL: goto x86_l_195c;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6507ULL: goto x86_l_196b;
	case 6509ULL: goto x86_l_196d;
	case 6512ULL: goto x86_l_1970;
	case 6515ULL: goto x86_l_1973;
	case 6521ULL: goto x86_l_1979;
	case 6525ULL: goto x86_l_197d;
	case 6529ULL: goto x86_l_1981;
	case 6533ULL: goto x86_l_1985;
	case 6538ULL: goto x86_l_198a;
	case 6543ULL: goto x86_l_198f;
	case 6548ULL: goto x86_l_1994;
	case 6557ULL: goto x86_l_199d;
	case 6566ULL: goto x86_l_19a6;
	case 6574ULL: goto x86_l_19ae;
	case 6579ULL: goto x86_l_19b3;
	case 6584ULL: goto x86_l_19b8;
	case 6587ULL: goto x86_l_19bb;
	case 6592ULL: goto x86_l_19c0;
	case 6595ULL: goto x86_l_19c3;
	case 6597ULL: goto x86_l_19c5;
	case 6600ULL: goto x86_l_19c8;
	case 6606ULL: goto x86_l_19ce;
	case 6611ULL: goto x86_l_19d3;
	case 6614ULL: goto x86_l_19d6;
	case 6620ULL: goto x86_l_19dc;
	case 6623ULL: goto x86_l_19df;
	case 6629ULL: goto x86_l_19e5;
	case 6633ULL: goto x86_l_19e9;
	case 6638ULL: goto x86_l_19ee;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6653ULL: goto x86_l_19fd;
	case 6655ULL: goto x86_l_19ff;
	case 6659ULL: goto x86_l_1a03;
	case 6664ULL: goto x86_l_1a08;
	case 6668ULL: goto x86_l_1a0c;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6694ULL: goto x86_l_1a26;
	case 6698ULL: goto x86_l_1a2a;
	case 6705ULL: goto x86_l_1a31;
	case 6717ULL: goto x86_l_1a3d;
	case 6722ULL: goto x86_l_1a42;
	case 6728ULL: goto x86_l_1a48;
	case 6733ULL: goto x86_l_1a4d;
	case 6736ULL: goto x86_l_1a50;
	case 6739ULL: goto x86_l_1a53;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6747ULL: goto x86_l_1a5b;
	case 6753ULL: goto x86_l_1a61;
	case 6756ULL: goto x86_l_1a64;
	case 6762ULL: goto x86_l_1a6a;
	case 6765ULL: goto x86_l_1a6d;
	case 6771ULL: goto x86_l_1a73;
	case 6774ULL: goto x86_l_1a76;
	case 6780ULL: goto x86_l_1a7c;
	case 6787ULL: goto x86_l_1a83;
	case 6792ULL: goto x86_l_1a88;
	case 6796ULL: goto x86_l_1a8c;
	case 6800ULL: goto x86_l_1a90;
	case 6805ULL: goto x86_l_1a95;
	case 6810ULL: goto x86_l_1a9a;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6823ULL: goto x86_l_1aa7;
	case 6828ULL: goto x86_l_1aac;
	case 6830ULL: goto x86_l_1aae;
	case 6834ULL: goto x86_l_1ab2;
	case 6839ULL: goto x86_l_1ab7;
	case 6844ULL: goto x86_l_1abc;
	case 6849ULL: goto x86_l_1ac1;
	case 6854ULL: goto x86_l_1ac6;
	case 6856ULL: goto x86_l_1ac8;
	case 6860ULL: goto x86_l_1acc;
	case 6865ULL: goto x86_l_1ad1;
	case 6870ULL: goto x86_l_1ad6;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6882ULL: goto x86_l_1ae2;
	case 6886ULL: goto x86_l_1ae6;
	case 6891ULL: goto x86_l_1aeb;
	case 6896ULL: goto x86_l_1af0;
	case 6901ULL: goto x86_l_1af5;
	case 6906ULL: goto x86_l_1afa;
	case 6908ULL: goto x86_l_1afc;
	case 6912ULL: goto x86_l_1b00;
	case 6917ULL: goto x86_l_1b05;
	case 6922ULL: goto x86_l_1b0a;
	case 6927ULL: goto x86_l_1b0f;
	case 6932ULL: goto x86_l_1b14;
	case 6934ULL: goto x86_l_1b16;
	case 6938ULL: goto x86_l_1b1a;
	case 6943ULL: goto x86_l_1b1f;
	case 6948ULL: goto x86_l_1b24;
	case 6953ULL: goto x86_l_1b29;
	case 6958ULL: goto x86_l_1b2e;
	case 6960ULL: goto x86_l_1b30;
	case 6964ULL: goto x86_l_1b34;
	case 6969ULL: goto x86_l_1b39;
	case 6974ULL: goto x86_l_1b3e;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6986ULL: goto x86_l_1b4a;
	case 6990ULL: goto x86_l_1b4e;
	case 6995ULL: goto x86_l_1b53;
	case 7000ULL: goto x86_l_1b58;
	case 7005ULL: goto x86_l_1b5d;
	case 7010ULL: goto x86_l_1b62;
	case 7012ULL: goto x86_l_1b64;
	case 7019ULL: goto x86_l_1b6b;
	case 7023ULL: goto x86_l_1b6f;
	case 7028ULL: goto x86_l_1b74;
	case 7033ULL: goto x86_l_1b79;
	case 7038ULL: goto x86_l_1b7e;
	case 7043ULL: goto x86_l_1b83;
	case 7045ULL: goto x86_l_1b85;
	case 7049ULL: goto x86_l_1b89;
	case 7054ULL: goto x86_l_1b8e;
	case 7059ULL: goto x86_l_1b93;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7071ULL: goto x86_l_1b9f;
	case 7075ULL: goto x86_l_1ba3;
	case 7080ULL: goto x86_l_1ba8;
	case 7085ULL: goto x86_l_1bad;
	case 7090ULL: goto x86_l_1bb2;
	case 7095ULL: goto x86_l_1bb7;
	case 7097ULL: goto x86_l_1bb9;
	case 7102ULL: goto x86_l_1bbe;
	case 7107ULL: goto x86_l_1bc3;
	case 7112ULL: goto x86_l_1bc8;
	case 7115ULL: goto x86_l_1bcb;
	case 7120ULL: goto x86_l_1bd0;
	case 7122ULL: goto x86_l_1bd2;
	case 7129ULL: goto x86_l_1bd9;
	case 7134ULL: goto x86_l_1bde;
	case 7139ULL: goto x86_l_1be3;
	case 7144ULL: goto x86_l_1be8;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7154ULL: goto x86_l_1bf2;
	case 7159ULL: goto x86_l_1bf7;
	case 7167ULL: goto x86_l_1bff;
	case 7172ULL: goto x86_l_1c04;
	case 7177ULL: goto x86_l_1c09;
	case 7180ULL: goto x86_l_1c0c;
	case 7185ULL: goto x86_l_1c11;
	case 7187ULL: goto x86_l_1c13;
	case 7191ULL: goto x86_l_1c17;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7209ULL: goto x86_l_1c29;
	case 7214ULL: goto x86_l_1c2e;
	case 7216ULL: goto x86_l_1c30;
	case 7220ULL: goto x86_l_1c34;
	case 7228ULL: goto x86_l_1c3c;
	case 7233ULL: goto x86_l_1c41;
	case 7238ULL: goto x86_l_1c46;
	case 7243ULL: goto x86_l_1c4b;
	case 7245ULL: goto x86_l_1c4d;
	case 7249ULL: goto x86_l_1c51;
	case 7256ULL: goto x86_l_1c58;
	case 7261ULL: goto x86_l_1c5d;
	case 7266ULL: goto x86_l_1c62;
	case 7269ULL: goto x86_l_1c65;
	case 7274ULL: goto x86_l_1c6a;
	case 7277ULL: goto x86_l_1c6d;
	case 7279ULL: goto x86_l_1c6f;
	case 7285ULL: goto x86_l_1c75;
	case 7290ULL: goto x86_l_1c7a;
	case 7295ULL: goto x86_l_1c7f;
	case 7302ULL: goto x86_l_1c86;
	case 7307ULL: goto x86_l_1c8b;
	case 7312ULL: goto x86_l_1c90;
	case 7315ULL: goto x86_l_1c93;
	case 7320ULL: goto x86_l_1c98;
	case 7322ULL: goto x86_l_1c9a;
	case 7326ULL: goto x86_l_1c9e;
	case 7333ULL: goto x86_l_1ca5;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1596:
	/* 0x1596: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_159c:
	/* 0x159c: jmp    1e84 <generic_usdt_process_event+0x1e84> */
	return 7812ULL;
x86_l_15a1:
	/* 0x15a1: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_15a5:
	/* 0x15a5: jne    237c <generic_usdt_process_event+0x237c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 9084ULL;
	}
x86_l_15ab:
	/* 0x15ab: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15b0:
	/* 0x15b0: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_15b3:
	/* 0x15b3: add    rdx,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15b6:
	/* 0x15b6: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_15b9:
	/* 0x15b9: and    esi,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15bf:
	/* 0x15bf: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15c4:
	/* 0x15c4: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15c9:
	/* 0x15c9: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_15cb:
	/* 0x15cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_15d0:
	/* 0x15d0: jmp    196b <generic_usdt_process_event+0x196b> */
	goto x86_l_196b;
x86_l_15d5:
	/* 0x15d5: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_15de:
	/* 0x15de: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_15e3:
	/* 0x15e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e5:
	/* 0x15e5: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_15e9:
	/* 0x15e9: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15ee:
	/* 0x15ee: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15f6:
	/* 0x15f6: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15fb:
	/* 0x15fb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1600:
	/* 0x1600: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1605:
	/* 0x1605: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_160b:
	/* 0x160b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1610:
	/* 0x1610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1612:
	/* 0x1612: mov    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1619:
	/* 0x1619: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_161d:
	/* 0x161d: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&fdinstall_map)));
x86_l_1624:
	/* 0x1624: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1629:
	/* 0x1629: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162e:
	/* 0x162e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1630:
	/* 0x1630: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1633:
	/* 0x1633: je     1f13 <generic_usdt_process_event+0x1f13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7955ULL;
	}
x86_l_1639:
	/* 0x1639: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163c:
	/* 0x163c: lea    rdx,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1644:
	/* 0x1644: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1647:
	/* 0x1647: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_164c:
	/* 0x164c: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1651:
	/* 0x1651: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1654:
	/* 0x1654: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1659:
	/* 0x1659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_165b:
	/* 0x165b: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1662:
	/* 0x1662: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1666:
	/* 0x1666: lea    rsi,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_166a:
	/* 0x166a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_166f:
	/* 0x166f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1672:
	/* 0x1672: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1674:
	/* 0x1674: lea    rdi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1678:
	/* 0x1678: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_167c:
	/* 0x167c: lea    rdx,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1680:
	/* 0x1680: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1684:
	/* 0x1684: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1689:
	/* 0x1689: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_168e:
	/* 0x168e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1690:
	/* 0x1690: add    r15,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1694:
	/* 0x1694: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_1699:
	/* 0x1699: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_169c:
	/* 0x169c: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16a1:
	/* 0x16a1: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_16a9:
	/* 0x16a9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_16ae:
	/* 0x16ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b3:
	/* 0x16b3: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_16b8:
	/* 0x16b8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16bb:
	/* 0x16bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bd:
	/* 0x16bd: movzx  eax,BYTE PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 184ULL);
x86_l_16c5:
	/* 0x16c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16c7:
	/* 0x16c7: je     1f1f <generic_usdt_process_event+0x1f1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7967ULL;
	}
x86_l_16cd:
	/* 0x16cd: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d0:
	/* 0x16d0: jne    2128 <generic_usdt_process_event+0x2128> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8488ULL;
	}
x86_l_16d6:
	/* 0x16d6: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_16da:
	/* 0x16da: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16df:
	/* 0x16df: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_16e5:
	/* 0x16e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_16ea:
	/* 0x16ea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16ef:
	/* 0x16ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16f4:
	/* 0x16f4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_16f7:
	/* 0x16f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f9:
	/* 0x16f9: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16fe:
	/* 0x16fe: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1706:
	/* 0x1706: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_170b:
	/* 0x170b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1710:
	/* 0x1710: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1715:
	/* 0x1715: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1717:
	/* 0x1717: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_171c:
	/* 0x171c: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1720:
	/* 0x1720: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1725:
	/* 0x1725: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_172a:
	/* 0x172a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_172f:
	/* 0x172f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1734:
	/* 0x1734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1736:
	/* 0x1736: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_173e:
	/* 0x173e: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1743:
	/* 0x1743: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1748:
	/* 0x1748: lea    r12,[r13*1+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 144ULL);
x86_l_1750:
	/* 0x1750: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1753:
	/* 0x1753: test   BYTE PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_1758:
	/* 0x1758: je     29ae <generic_usdt_process_event+0x29ae> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10670ULL;
	}
x86_l_175e:
	/* 0x175e: cmp    QWORD PTR [rsp+0x10],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719480832ULL);
x86_l_1767:
	/* 0x1767: jb     2986 <generic_usdt_process_event+0x2986> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10630ULL;
	}
x86_l_176d:
	/* 0x176d: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1775:
	/* 0x1775: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1779:
	/* 0x1779: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_177e:
	/* 0x177e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1781:
	/* 0x1781: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1784:
	/* 0x1784: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1789:
	/* 0x1789: jmp    1fb5 <generic_usdt_process_event+0x1fb5> */
	return 8117ULL;
x86_l_178e:
	/* 0x178e: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1793:
	/* 0x1793: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1798:
	/* 0x1798: lea    rdi,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_179c:
	/* 0x179c: lea    rdx,[r12+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_17a4:
	/* 0x17a4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17a9:
	/* 0x17a9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17ae:
	/* 0x17ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17b0:
	/* 0x17b0: lea    rdi,[r15+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_17b4:
	/* 0x17b4: lea    rdx,[r12+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17b9:
	/* 0x17b9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17be:
	/* 0x17be: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c3:
	/* 0x17c3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17c8:
	/* 0x17c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ca:
	/* 0x17ca: lea    rdi,[r15+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17ce:
	/* 0x17ce: lea    rdx,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_17d6:
	/* 0x17d6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17db:
	/* 0x17db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17e0:
	/* 0x17e0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_17e5:
	/* 0x17e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e7:
	/* 0x17e7: lea    rdi,[r15+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_17eb:
	/* 0x17eb: lea    rdx,[r12+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17f3:
	/* 0x17f3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17f8:
	/* 0x17f8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17fd:
	/* 0x17fd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1802:
	/* 0x1802: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1804:
	/* 0x1804: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_180d:
	/* 0x180d: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1815:
	/* 0x1815: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_181a:
	/* 0x181a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_181f:
	/* 0x181f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1824:
	/* 0x1824: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1829:
	/* 0x1829: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182b:
	/* 0x182b: lea    rdx,[r12+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1833:
	/* 0x1833: lea    rdi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_183b:
	/* 0x183b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1840:
	/* 0x1840: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1845:
	/* 0x1845: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_184a:
	/* 0x184a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184c:
	/* 0x184c: movzx  r15d,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1855:
	/* 0x1855: add    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_185a:
	/* 0x185a: lea    rdi,[rsp+0xab] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171ULL);
x86_l_1862:
	/* 0x1862: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1867:
	/* 0x1867: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_186c:
	/* 0x186c: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1871:
	/* 0x1871: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1874:
	/* 0x1874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1876:
	/* 0x1876: movzx  eax,BYTE PTR [rsp+0xab] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 171ULL);
x86_l_187e:
	/* 0x187e: shr    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_1881:
	/* 0x1881: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1884:
	/* 0x1884: je     1fc6 <generic_usdt_process_event+0x1fc6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8134ULL;
	}
x86_l_188a:
	/* 0x188a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_188d:
	/* 0x188d: jne    3327 <generic_usdt_process_event+0x3327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 13095ULL;
	}
x86_l_1893:
	/* 0x1893: lea    rdx,[r15+0x9] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_1897:
	/* 0x1897: lea    rdi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_189f:
	/* 0x189f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18a4:
	/* 0x18a4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18a9:
	/* 0x18a9: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_18ae:
	/* 0x18ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b0:
	/* 0x18b0: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_18b8:
	/* 0x18b8: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18bd:
	/* 0x18bd: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18c1:
	/* 0x18c1: mov    WORD PTR [rdi+0x26],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757250ULL);
x86_l_18c7:
	/* 0x18c7: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18cb:
	/* 0x18cb: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d2:
	/* 0x18d2: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18da:
	/* 0x18da: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18e2:
	/* 0x18e2: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_18ea:
	/* 0x18ea: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_18ef:
	/* 0x18ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f4:
	/* 0x18f4: lea    r13,[rdi+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18f8:
	/* 0x18f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_18fd:
	/* 0x18fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18ff:
	/* 0x18ff: add    r15,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1903:
	/* 0x1903: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1908:
	/* 0x1908: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_190d:
	/* 0x190d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1910:
	/* 0x1910: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1915:
	/* 0x1915: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1918:
	/* 0x1918: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191a:
	/* 0x191a: lea    rdx,[r12+0xb6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 182ULL);
x86_l_1922:
	/* 0x1922: lea    rdi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_192a:
	/* 0x192a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_192f:
	/* 0x192f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1934:
	/* 0x1934: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1939:
	/* 0x1939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193b:
	/* 0x193b: movzx  ebp,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_1943:
	/* 0x1943: jmp    31c3 <generic_usdt_process_event+0x31c3> */
	return 12739ULL;
x86_l_1948:
	/* 0x1948: mov    edx,0x120 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 288ULL);
x86_l_194d:
	/* 0x194d: add    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_1952:
	/* 0x1952: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1957:
	/* 0x1957: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_195c:
	/* 0x195c: mov    ecx,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_1961:
	/* 0x1961: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1966:
	/* 0x1966: mov    esi,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_196b:
	/* 0x196b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196d:
	/* 0x196d: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1970:
	/* 0x1970: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1973:
	/* 0x1973: js     2372 <generic_usdt_process_event+0x2372> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 9074ULL;
	}
x86_l_1979:
	/* 0x1979: lea    eax,[r15-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_197d:
	/* 0x197d: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1981:
	/* 0x1981: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_1985:
	/* 0x1985: jmp    2372 <generic_usdt_process_event+0x2372> */
	return 9074ULL;
x86_l_198a:
	/* 0x198a: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_198f:
	/* 0x198f: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1994:
	/* 0x1994: mov    QWORD PTR [r12+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_199d:
	/* 0x199d: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_19a6:
	/* 0x19a6: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ae:
	/* 0x19ae: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19b3:
	/* 0x19b3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19b8:
	/* 0x19b8: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_19bb:
	/* 0x19bb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_19c0:
	/* 0x19c0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19c3:
	/* 0x19c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c5:
	/* 0x19c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19c8:
	/* 0x19c8: js     2265 <generic_usdt_process_event+0x2265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 8805ULL;
	}
x86_l_19ce:
	/* 0x19ce: movzx  eax,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19d3:
	/* 0x19d3: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_19d6:
	/* 0x19d6: je     2210 <generic_usdt_process_event+0x2210> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8720ULL;
	}
x86_l_19dc:
	/* 0x19dc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19df:
	/* 0x19df: jne    224c <generic_usdt_process_event+0x224c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8780ULL;
	}
x86_l_19e5:
	/* 0x19e5: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19e9:
	/* 0x19e9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19ee:
	/* 0x19ee: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19f3:
	/* 0x19f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19f8:
	/* 0x19f8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_19fd:
	/* 0x19fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19ff:
	/* 0x19ff: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a03:
	/* 0x1a03: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a08:
	/* 0x1a08: mov    QWORD PTR [rcx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a0c:
	/* 0x1a0c: lea    rdi,[rcx+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1a10:
	/* 0x1a10: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a14:
	/* 0x1a14: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a19:
	/* 0x1a19: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1a1e:
	/* 0x1a1e: jmp    2242 <generic_usdt_process_event+0x2242> */
	return 8770ULL;
x86_l_1a23:
	/* 0x1a23: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1a26:
	/* 0x1a26: lea    rbp,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1a2a:
	/* 0x1a2a: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1a31:
	/* 0x1a31: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_1a3d:
	/* 0x1a3d: test   BYTE PTR [rsp+0x20],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953488ULL);
x86_l_1a42:
	/* 0x1a42: jne    213f <generic_usdt_process_event+0x213f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8511ULL;
	}
x86_l_1a48:
	/* 0x1a48: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a4d:
	/* 0x1a4d: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1a50:
	/* 0x1a50: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1a53:
	/* 0x1a53: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a55:
	/* 0x1a55: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1a58:
	/* 0x1a58: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1a5b:
	/* 0x1a5b: jle    2389 <generic_usdt_process_event+0x2389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 9097ULL;
	}
x86_l_1a61:
	/* 0x1a61: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1a64:
	/* 0x1a64: je     2b24 <generic_usdt_process_event+0x2b24> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11044ULL;
	}
x86_l_1a6a:
	/* 0x1a6a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a6d:
	/* 0x1a6d: je     2b2d <generic_usdt_process_event+0x2b2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11053ULL;
	}
x86_l_1a73:
	/* 0x1a73: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1a76:
	/* 0x1a76: jne    2b40 <generic_usdt_process_event+0x2b40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11072ULL;
	}
x86_l_1a7c:
	/* 0x1a7c: lea    rax,[rbx+0x5e70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24176ULL);
x86_l_1a83:
	/* 0x1a83: jmp    2b3d <generic_usdt_process_event+0x2b3d> */
	return 11069ULL;
x86_l_1a88:
	/* 0x1a88: lea    r13,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a8c:
	/* 0x1a8c: lea    r15,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a90:
	/* 0x1a90: mov    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a95:
	/* 0x1a95: lea    rdx,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1aa7:
	/* 0x1aa7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1aac:
	/* 0x1aac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aae:
	/* 0x1aae: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ab2:
	/* 0x1ab2: lea    rdx,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ab7:
	/* 0x1ab7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1abc:
	/* 0x1abc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ac1:
	/* 0x1ac1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ac6:
	/* 0x1ac6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ac8:
	/* 0x1ac8: lea    rdi,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1acc:
	/* 0x1acc: lea    rdx,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ad1:
	/* 0x1ad1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ad6:
	/* 0x1ad6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1adb:
	/* 0x1adb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ae0:
	/* 0x1ae0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae2:
	/* 0x1ae2: lea    rdi,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1ae6:
	/* 0x1ae6: lea    rdx,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1af0:
	/* 0x1af0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1af5:
	/* 0x1af5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1afa:
	/* 0x1afa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1afc:
	/* 0x1afc: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b00:
	/* 0x1b00: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b05:
	/* 0x1b05: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b0a:
	/* 0x1b0a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b0f:
	/* 0x1b0f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b14:
	/* 0x1b14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b16:
	/* 0x1b16: lea    rdi,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b1a:
	/* 0x1b1a: lea    rdx,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b24:
	/* 0x1b24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b29:
	/* 0x1b29: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b2e:
	/* 0x1b2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b30:
	/* 0x1b30: lea    rdi,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b34:
	/* 0x1b34: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b39:
	/* 0x1b39: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b3e:
	/* 0x1b3e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b43:
	/* 0x1b43: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b48:
	/* 0x1b48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b4a:
	/* 0x1b4a: lea    rdi,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1b4e:
	/* 0x1b4e: lea    rdx,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b53:
	/* 0x1b53: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b58:
	/* 0x1b58: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b62:
	/* 0x1b62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b64:
	/* 0x1b64: mov    DWORD PTR [rbp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1b6b:
	/* 0x1b6b: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b6f:
	/* 0x1b6f: lea    rdx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b74:
	/* 0x1b74: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b79:
	/* 0x1b79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b7e:
	/* 0x1b7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1b83:
	/* 0x1b83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b85:
	/* 0x1b85: lea    rdi,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b89:
	/* 0x1b89: lea    rdx,[r12+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b93:
	/* 0x1b93: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b98:
	/* 0x1b98: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b9d:
	/* 0x1b9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b9f:
	/* 0x1b9f: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ba3:
	/* 0x1ba3: lea    rdx,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ba8:
	/* 0x1ba8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bad:
	/* 0x1bad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bb7:
	/* 0x1bb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bb9:
	/* 0x1bb9: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1bcb:
	/* 0x1bcb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bd0:
	/* 0x1bd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd2:
	/* 0x1bd2: add    r12,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1bd9:
	/* 0x1bd9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bde:
	/* 0x1bde: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1be3:
	/* 0x1be3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1be8:
	/* 0x1be8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1bed:
	/* 0x1bed: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bf0:
	/* 0x1bf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf2:
	/* 0x1bf2: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bf7:
	/* 0x1bf7: lea    rdx,[r12+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1bff:
	/* 0x1bff: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c04:
	/* 0x1c04: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c09:
	/* 0x1c09: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1c0c:
	/* 0x1c0c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c11:
	/* 0x1c11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c13:
	/* 0x1c13: lea    rdi,[rbp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1c17:
	/* 0x1c17: lea    rdx,[r12+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1c1f:
	/* 0x1c1f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c24:
	/* 0x1c24: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c29:
	/* 0x1c29: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c2e:
	/* 0x1c2e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c30:
	/* 0x1c30: lea    rdi,[rbp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1c34:
	/* 0x1c34: lea    rdx,[r12+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c41:
	/* 0x1c41: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c46:
	/* 0x1c46: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c4b:
	/* 0x1c4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4d:
	/* 0x1c4d: add    rbp,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_1c51:
	/* 0x1c51: add    r12,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1c58:
	/* 0x1c58: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c62:
	/* 0x1c62: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1c65:
	/* 0x1c65: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c6a:
	/* 0x1c6a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1c6d:
	/* 0x1c6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c6f:
	/* 0x1c6f: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_1c75:
	/* 0x1c75: jmp    1e7a <generic_usdt_process_event+0x1e7a> */
	return 7802ULL;
x86_l_1c7a:
	/* 0x1c7a: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c7f:
	/* 0x1c7f: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c86:
	/* 0x1c86: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c8b:
	/* 0x1c8b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c90:
	/* 0x1c90: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1c93:
	/* 0x1c93: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1c98:
	/* 0x1c98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9a:
	/* 0x1c9a: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c9e:
	/* 0x1c9e: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1ca5:
	/* 0x1ca5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
	return 7338ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7338ULL: goto x86_l_1caa;
	case 7343ULL: goto x86_l_1caf;
	case 7348ULL: goto x86_l_1cb4;
	case 7350ULL: goto x86_l_1cb6;
	case 7354ULL: goto x86_l_1cba;
	case 7361ULL: goto x86_l_1cc1;
	case 7366ULL: goto x86_l_1cc6;
	case 7371ULL: goto x86_l_1ccb;
	case 7376ULL: goto x86_l_1cd0;
	case 7378ULL: goto x86_l_1cd2;
	case 7382ULL: goto x86_l_1cd6;
	case 7389ULL: goto x86_l_1cdd;
	case 7394ULL: goto x86_l_1ce2;
	case 7399ULL: goto x86_l_1ce7;
	case 7402ULL: goto x86_l_1cea;
	case 7407ULL: goto x86_l_1cef;
	case 7410ULL: goto x86_l_1cf2;
	case 7412ULL: goto x86_l_1cf4;
	case 7418ULL: goto x86_l_1cfa;
	case 7423ULL: goto x86_l_1cff;
	case 7428ULL: goto x86_l_1d04;
	case 7432ULL: goto x86_l_1d08;
	case 7437ULL: goto x86_l_1d0d;
	case 7442ULL: goto x86_l_1d12;
	case 7445ULL: goto x86_l_1d15;
	case 7450ULL: goto x86_l_1d1a;
	case 7452ULL: goto x86_l_1d1c;
	case 7456ULL: goto x86_l_1d20;
	case 7460ULL: goto x86_l_1d24;
	case 7465ULL: goto x86_l_1d29;
	case 7470ULL: goto x86_l_1d2e;
	case 7475ULL: goto x86_l_1d33;
	case 7477ULL: goto x86_l_1d35;
	case 7481ULL: goto x86_l_1d39;
	case 7485ULL: goto x86_l_1d3d;
	case 7490ULL: goto x86_l_1d42;
	case 7495ULL: goto x86_l_1d47;
	case 7500ULL: goto x86_l_1d4c;
	case 7502ULL: goto x86_l_1d4e;
	case 7506ULL: goto x86_l_1d52;
	case 7510ULL: goto x86_l_1d56;
	case 7515ULL: goto x86_l_1d5b;
	case 7520ULL: goto x86_l_1d60;
	case 7525ULL: goto x86_l_1d65;
	case 7527ULL: goto x86_l_1d67;
	case 7531ULL: goto x86_l_1d6b;
	case 7535ULL: goto x86_l_1d6f;
	case 7540ULL: goto x86_l_1d74;
	case 7545ULL: goto x86_l_1d79;
	case 7548ULL: goto x86_l_1d7c;
	case 7553ULL: goto x86_l_1d81;
	case 7556ULL: goto x86_l_1d84;
	case 7558ULL: goto x86_l_1d86;
	case 7564ULL: goto x86_l_1d8c;
	case 7569ULL: goto x86_l_1d91;
	case 7574ULL: goto x86_l_1d96;
	case 7579ULL: goto x86_l_1d9b;
	case 7584ULL: goto x86_l_1da0;
	case 7587ULL: goto x86_l_1da3;
	case 7592ULL: goto x86_l_1da8;
	case 7595ULL: goto x86_l_1dab;
	case 7597ULL: goto x86_l_1dad;
	case 7601ULL: goto x86_l_1db1;
	case 7605ULL: goto x86_l_1db5;
	case 7610ULL: goto x86_l_1dba;
	case 7615ULL: goto x86_l_1dbf;
	case 7620ULL: goto x86_l_1dc4;
	case 7622ULL: goto x86_l_1dc6;
	case 7626ULL: goto x86_l_1dca;
	case 7630ULL: goto x86_l_1dce;
	case 7635ULL: goto x86_l_1dd3;
	case 7640ULL: goto x86_l_1dd8;
	case 7643ULL: goto x86_l_1ddb;
	case 7648ULL: goto x86_l_1de0;
	case 7651ULL: goto x86_l_1de3;
	case 7656ULL: goto x86_l_1de8;
	case 7660ULL: goto x86_l_1dec;
	case 7665ULL: goto x86_l_1df1;
	case 7670ULL: goto x86_l_1df6;
	case 7675ULL: goto x86_l_1dfb;
	case 7680ULL: goto x86_l_1e00;
	case 7683ULL: goto x86_l_1e03;
	case 7685ULL: goto x86_l_1e05;
	case 7689ULL: goto x86_l_1e09;
	case 7692ULL: goto x86_l_1e0c;
	case 7696ULL: goto x86_l_1e10;
	case 7701ULL: goto x86_l_1e15;
	case 7706ULL: goto x86_l_1e1a;
	case 7711ULL: goto x86_l_1e1f;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7722ULL: goto x86_l_1e2a;
	case 7725ULL: goto x86_l_1e2d;
	case 7729ULL: goto x86_l_1e31;
	case 7734ULL: goto x86_l_1e36;
	case 7739ULL: goto x86_l_1e3b;
	case 7744ULL: goto x86_l_1e40;
	case 7749ULL: goto x86_l_1e45;
	case 7752ULL: goto x86_l_1e48;
	case 7754ULL: goto x86_l_1e4a;
	case 7758ULL: goto x86_l_1e4e;
	case 7763ULL: goto x86_l_1e53;
	case 7768ULL: goto x86_l_1e58;
	case 7771ULL: goto x86_l_1e5b;
	case 7776ULL: goto x86_l_1e60;
	case 7781ULL: goto x86_l_1e65;
	case 7786ULL: goto x86_l_1e6a;
	case 7789ULL: goto x86_l_1e6d;
	case 7794ULL: goto x86_l_1e72;
	case 7796ULL: goto x86_l_1e74;
	case 7802ULL: goto x86_l_1e7a;
	case 7807ULL: goto x86_l_1e7f;
	case 7812ULL: goto x86_l_1e84;
	case 7820ULL: goto x86_l_1e8c;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7838ULL: goto x86_l_1e9e;
	case 7846ULL: goto x86_l_1ea6;
	case 7854ULL: goto x86_l_1eae;
	case 7862ULL: goto x86_l_1eb6;
	case 7870ULL: goto x86_l_1ebe;
	case 7878ULL: goto x86_l_1ec6;
	case 7886ULL: goto x86_l_1ece;
	case 7894ULL: goto x86_l_1ed6;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7913ULL: goto x86_l_1ee9;
	case 7918ULL: goto x86_l_1eee;
	case 7923ULL: goto x86_l_1ef3;
	case 7928ULL: goto x86_l_1ef8;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7938ULL: goto x86_l_1f02;
	case 7941ULL: goto x86_l_1f05;
	case 7947ULL: goto x86_l_1f0b;
	case 7950ULL: goto x86_l_1f0e;
	case 7955ULL: goto x86_l_1f13;
	case 7962ULL: goto x86_l_1f1a;
	case 7967ULL: goto x86_l_1f1f;
	case 7972ULL: goto x86_l_1f24;
	case 7980ULL: goto x86_l_1f2c;
	case 7985ULL: goto x86_l_1f31;
	case 7990ULL: goto x86_l_1f36;
	case 7995ULL: goto x86_l_1f3b;
	case 8000ULL: goto x86_l_1f40;
	case 8002ULL: goto x86_l_1f42;
	case 8006ULL: goto x86_l_1f46;
	case 8011ULL: goto x86_l_1f4b;
	case 8016ULL: goto x86_l_1f50;
	case 8021ULL: goto x86_l_1f55;
	case 8026ULL: goto x86_l_1f5a;
	case 8029ULL: goto x86_l_1f5d;
	case 8031ULL: goto x86_l_1f5f;
	case 8039ULL: goto x86_l_1f67;
	case 8044ULL: goto x86_l_1f6c;
	case 8049ULL: goto x86_l_1f71;
	case 8057ULL: goto x86_l_1f79;
	case 8060ULL: goto x86_l_1f7c;
	case 8068ULL: goto x86_l_1f84;
	case 8074ULL: goto x86_l_1f8a;
	case 8083ULL: goto x86_l_1f93;
	case 8089ULL: goto x86_l_1f99;
	case 8097ULL: goto x86_l_1fa1;
	case 8101ULL: goto x86_l_1fa5;
	case 8106ULL: goto x86_l_1faa;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8117ULL: goto x86_l_1fb5;
	case 8122ULL: goto x86_l_1fba;
	case 8125ULL: goto x86_l_1fbd;
	case 8129ULL: goto x86_l_1fc1;
	case 8134ULL: goto x86_l_1fc6;
	case 8139ULL: goto x86_l_1fcb;
	case 8150ULL: goto x86_l_1fd6;
	case 8158ULL: goto x86_l_1fde;
	case 8165ULL: goto x86_l_1fe5;
	case 8173ULL: goto x86_l_1fed;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8187ULL: goto x86_l_1ffb;
	case 8189ULL: goto x86_l_1ffd;
	case 8192ULL: goto x86_l_2000;
	case 8198ULL: goto x86_l_2006;
	case 8201ULL: goto x86_l_2009;
	case 8204ULL: goto x86_l_200c;
	case 8208ULL: goto x86_l_2010;
	case 8212ULL: goto x86_l_2014;
	case 8215ULL: goto x86_l_2017;
	case 8219ULL: goto x86_l_201b;
	case 8223ULL: goto x86_l_201f;
	case 8228ULL: goto x86_l_2024;
	case 8233ULL: goto x86_l_2029;
	case 8238ULL: goto x86_l_202e;
	case 8243ULL: goto x86_l_2033;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8270ULL: goto x86_l_204e;
	case 8276ULL: goto x86_l_2054;
	case 8279ULL: goto x86_l_2057;
	case 8285ULL: goto x86_l_205d;
	case 8288ULL: goto x86_l_2060;
	case 8294ULL: goto x86_l_2066;
	case 8301ULL: goto x86_l_206d;
	case 8305ULL: goto x86_l_2071;
	case 8310ULL: goto x86_l_2076;
	case 8314ULL: goto x86_l_207a;
	case 8319ULL: goto x86_l_207f;
	case 8324ULL: goto x86_l_2084;
	case 8327ULL: goto x86_l_2087;
	case 8332ULL: goto x86_l_208c;
	case 8334ULL: goto x86_l_208e;
	case 8338ULL: goto x86_l_2092;
	case 8343ULL: goto x86_l_2097;
	case 8348ULL: goto x86_l_209c;
	case 8351ULL: goto x86_l_209f;
	case 8356ULL: goto x86_l_20a4;
	case 8358ULL: goto x86_l_20a6;
	case 8362ULL: goto x86_l_20aa;
	case 8366ULL: goto x86_l_20ae;
	case 8370ULL: goto x86_l_20b2;
	case 8375ULL: goto x86_l_20b7;
	case 8380ULL: goto x86_l_20bc;
	case 8385ULL: goto x86_l_20c1;
	case 8388ULL: goto x86_l_20c4;
	case 8390ULL: goto x86_l_20c6;
	case 8394ULL: goto x86_l_20ca;
	case 8399ULL: goto x86_l_20cf;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8412ULL: goto x86_l_20dc;
	case 8414ULL: goto x86_l_20de;
	case 8418ULL: goto x86_l_20e2;
	case 8424ULL: goto x86_l_20e8;
	case 8429ULL: goto x86_l_20ed;
	case 8434ULL: goto x86_l_20f2;
	case 8441ULL: goto x86_l_20f9;
	case 8446ULL: goto x86_l_20fe;
	case 8451ULL: goto x86_l_2103;
	case 8453ULL: goto x86_l_2105;
	case 8456ULL: goto x86_l_2108;
	case 8462ULL: goto x86_l_210e;
	case 8464ULL: goto x86_l_2110;
	case 8468ULL: goto x86_l_2114;
	case 8472ULL: goto x86_l_2118;
	case 8476ULL: goto x86_l_211c;
	case 8479ULL: goto x86_l_211f;
	case 8483ULL: goto x86_l_2123;
	case 8488ULL: goto x86_l_2128;
	case 8500ULL: goto x86_l_2134;
	case 8506ULL: goto x86_l_213a;
	case 8511ULL: goto x86_l_213f;
	case 8516ULL: goto x86_l_2144;
	case 8518ULL: goto x86_l_2146;
	case 8522ULL: goto x86_l_214a;
	case 8524ULL: goto x86_l_214c;
	case 8529ULL: goto x86_l_2151;
	case 8533ULL: goto x86_l_2155;
	case 8536ULL: goto x86_l_2158;
	case 8540ULL: goto x86_l_215c;
	case 8544ULL: goto x86_l_2160;
	case 8549ULL: goto x86_l_2165;
	case 8554ULL: goto x86_l_216a;
	case 8559ULL: goto x86_l_216f;
	case 8568ULL: goto x86_l_2178;
	case 8576ULL: goto x86_l_2180;
	case 8584ULL: goto x86_l_2188;
	case 8591ULL: goto x86_l_218f;
	case 8593ULL: goto x86_l_2191;
	case 8601ULL: goto x86_l_2199;
	case 8606ULL: goto x86_l_219e;
	case 8611ULL: goto x86_l_21a3;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	case 8618ULL: goto x86_l_21aa;
	case 8624ULL: goto x86_l_21b0;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8638ULL: goto x86_l_21be;
	case 8648ULL: goto x86_l_21c8;
	case 8653ULL: goto x86_l_21cd;
	case 8660ULL: goto x86_l_21d4;
	case 8665ULL: goto x86_l_21d9;
	case 8670ULL: goto x86_l_21de;
	case 8672ULL: goto x86_l_21e0;
	case 8675ULL: goto x86_l_21e3;
	case 8681ULL: goto x86_l_21e9;
	case 8683ULL: goto x86_l_21eb;
	case 8688ULL: goto x86_l_21f0;
	case 8691ULL: goto x86_l_21f3;
	case 8697ULL: goto x86_l_21f9;
	case 8700ULL: goto x86_l_21fc;
	case 8706ULL: goto x86_l_2202;
	case 8709ULL: goto x86_l_2205;
	case 8715ULL: goto x86_l_220b;
	case 8720ULL: goto x86_l_2210;
	case 8725ULL: goto x86_l_2215;
	case 8730ULL: goto x86_l_221a;
	case 8734ULL: goto x86_l_221e;
	case 8739ULL: goto x86_l_2223;
	case 8744ULL: goto x86_l_2228;
	case 8749ULL: goto x86_l_222d;
	case 8751ULL: goto x86_l_222f;
	case 8756ULL: goto x86_l_2234;
	case 8760ULL: goto x86_l_2238;
	case 8765ULL: goto x86_l_223d;
	case 8770ULL: goto x86_l_2242;
	case 8775ULL: goto x86_l_2247;
	case 8778ULL: goto x86_l_224a;
	case 8780ULL: goto x86_l_224c;
	case 8785ULL: goto x86_l_2251;
	case 8789ULL: goto x86_l_2255;
	case 8795ULL: goto x86_l_225b;
	case 8800ULL: goto x86_l_2260;
	case 8805ULL: goto x86_l_2265;
	case 8811ULL: goto x86_l_226b;
	case 8816ULL: goto x86_l_2270;
	case 8821ULL: goto x86_l_2275;
	case 8826ULL: goto x86_l_227a;
	case 8831ULL: goto x86_l_227f;
	case 8836ULL: goto x86_l_2284;
	case 8841ULL: goto x86_l_2289;
	case 8846ULL: goto x86_l_228e;
	case 8848ULL: goto x86_l_2290;
	case 8851ULL: goto x86_l_2293;
	case 8857ULL: goto x86_l_2299;
	case 8862ULL: goto x86_l_229e;
	case 8866ULL: goto x86_l_22a2;
	case 8874ULL: goto x86_l_22aa;
	case 8879ULL: goto x86_l_22af;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8891ULL: goto x86_l_22bb;
	case 8896ULL: goto x86_l_22c0;
	case 8901ULL: goto x86_l_22c5;
	case 8909ULL: goto x86_l_22cd;
	case 8912ULL: goto x86_l_22d0;
	case 8917ULL: goto x86_l_22d5;
	case 8922ULL: goto x86_l_22da;
	case 8930ULL: goto x86_l_22e2;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8941ULL: goto x86_l_22ed;
	case 8949ULL: goto x86_l_22f5;
	case 8954ULL: goto x86_l_22fa;
	case 8959ULL: goto x86_l_22ff;
	case 8964ULL: goto x86_l_2304;
	case 8967ULL: goto x86_l_2307;
	case 8969ULL: goto x86_l_2309;
	case 8975ULL: goto x86_l_230f;
	case 8978ULL: goto x86_l_2312;
	case 8984ULL: goto x86_l_2318;
	case 8986ULL: goto x86_l_231a;
	case 8994ULL: goto x86_l_2322;
	case 8997ULL: goto x86_l_2325;
	case 9001ULL: goto x86_l_2329;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9012ULL: goto x86_l_2334;
	case 9017ULL: goto x86_l_2339;
	case 9021ULL: goto x86_l_233d;
	case 9026ULL: goto x86_l_2342;
	case 9031ULL: goto x86_l_2347;
	case 9036ULL: goto x86_l_234c;
	case 9039ULL: goto x86_l_234f;
	case 9041ULL: goto x86_l_2351;
	case 9044ULL: goto x86_l_2354;
	case 9046ULL: goto x86_l_2356;
	case 9048ULL: goto x86_l_2358;
	case 9053ULL: goto x86_l_235d;
	case 9058ULL: goto x86_l_2362;
	case 9060ULL: goto x86_l_2364;
	case 9065ULL: goto x86_l_2369;
	case 9068ULL: goto x86_l_236c;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9084ULL: goto x86_l_237c;
	case 9092ULL: goto x86_l_2384;
	case 9097ULL: goto x86_l_2389;
	case 9100ULL: goto x86_l_238c;
	case 9106ULL: goto x86_l_2392;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1caa:
	/* 0x1caa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1caf:
	/* 0x1caf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cb4:
	/* 0x1cb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cb6:
	/* 0x1cb6: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cba:
	/* 0x1cba: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1cc1:
	/* 0x1cc1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1cc6:
	/* 0x1cc6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cd0:
	/* 0x1cd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd2:
	/* 0x1cd2: add    rbp,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1cd6:
	/* 0x1cd6: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1cdd:
	/* 0x1cdd: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce2:
	/* 0x1ce2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ce7:
	/* 0x1ce7: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1cea:
	/* 0x1cea: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1cef:
	/* 0x1cef: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1cf2:
	/* 0x1cf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf4:
	/* 0x1cf4: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1cfa:
	/* 0x1cfa: jmp    1e7a <generic_usdt_process_event+0x1e7a> */
	goto x86_l_1e7a;
x86_l_1cff:
	/* 0x1cff: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d04:
	/* 0x1d04: lea    rdx,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d08:
	/* 0x1d08: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d0d:
	/* 0x1d0d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d12:
	/* 0x1d12: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1d15:
	/* 0x1d15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d1a:
	/* 0x1d1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1c:
	/* 0x1d1c: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d20:
	/* 0x1d20: lea    rdx,[r15+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1d24:
	/* 0x1d24: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d29:
	/* 0x1d29: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d2e:
	/* 0x1d2e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d33:
	/* 0x1d33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d35:
	/* 0x1d35: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d39:
	/* 0x1d39: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d3d:
	/* 0x1d3d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d42:
	/* 0x1d42: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d47:
	/* 0x1d47: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d4c:
	/* 0x1d4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d4e:
	/* 0x1d4e: lea    rdi,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d52:
	/* 0x1d52: lea    rdx,[r15+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d56:
	/* 0x1d56: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d5b:
	/* 0x1d5b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d60:
	/* 0x1d60: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1d65:
	/* 0x1d65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d67:
	/* 0x1d67: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1d6b:
	/* 0x1d6b: add    r15,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1d74:
	/* 0x1d74: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d79:
	/* 0x1d79: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1d7c:
	/* 0x1d7c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1d81:
	/* 0x1d81: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d84:
	/* 0x1d84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d86:
	/* 0x1d86: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_1d8c:
	/* 0x1d8c: jmp    1e7a <generic_usdt_process_event+0x1e7a> */
	goto x86_l_1e7a;
x86_l_1d91:
	/* 0x1d91: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1d96:
	/* 0x1d96: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d9b:
	/* 0x1d9b: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1da0:
	/* 0x1da0: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1da3:
	/* 0x1da3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1da8:
	/* 0x1da8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1dab:
	/* 0x1dab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dad:
	/* 0x1dad: lea    rdi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1db1:
	/* 0x1db1: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1db5:
	/* 0x1db5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1dba:
	/* 0x1dba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dbf:
	/* 0x1dbf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1dc4:
	/* 0x1dc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc6:
	/* 0x1dc6: add    rbp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1dca:
	/* 0x1dca: add    r15,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1dce:
	/* 0x1dce: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1dd3:
	/* 0x1dd3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd8:
	/* 0x1dd8: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1ddb:
	/* 0x1ddb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1de0:
	/* 0x1de0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1de3:
	/* 0x1de3: jmp    1e72 <generic_usdt_process_event+0x1e72> */
	goto x86_l_1e72;
x86_l_1de8:
	/* 0x1de8: lea    rdx,[r8+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dec:
	/* 0x1dec: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1df1:
	/* 0x1df1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1df6:
	/* 0x1df6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dfb:
	/* 0x1dfb: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e00:
	/* 0x1e00: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_1e03:
	/* 0x1e03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e05:
	/* 0x1e05: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e09:
	/* 0x1e09: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0c:
	/* 0x1e0c: lea    rdx,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e10:
	/* 0x1e10: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e15:
	/* 0x1e15: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1e1a:
	/* 0x1e1a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e1f:
	/* 0x1e1f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e24:
	/* 0x1e24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e26:
	/* 0x1e26: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e2a:
	/* 0x1e2a: mov    DWORD PTR [rbp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e2d:
	/* 0x1e2d: add    r15,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_1e31:
	/* 0x1e31: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e36:
	/* 0x1e36: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1e3b:
	/* 0x1e3b: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e40:
	/* 0x1e40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e45:
	/* 0x1e45: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1e48:
	/* 0x1e48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e4a:
	/* 0x1e4a: add    rbp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1e4e:
	/* 0x1e4e: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1e53:
	/* 0x1e53: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e58:
	/* 0x1e58: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e5b:
	/* 0x1e5b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e60:
	/* 0x1e60: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_1e65:
	/* 0x1e65: add    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_1e6a:
	/* 0x1e6a: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1e6d:
	/* 0x1e6d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1e72:
	/* 0x1e72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e74:
	/* 0x1e74: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_1e7a:
	/* 0x1e7a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e7f:
	/* 0x1e7f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1e84:
	/* 0x1e84: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1e8c:
	/* 0x1e8c: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e91:
	/* 0x1e91: jmp    d53 <generic_usdt_process_event+0xd53> */
	return 3411ULL;
x86_l_1e96:
	/* 0x1e96: mov    QWORD PTR [rbp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1e9e:
	/* 0x1e9e: mov    QWORD PTR [rbp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ea6:
	/* 0x1ea6: mov    QWORD PTR [rbp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1eae:
	/* 0x1eae: mov    QWORD PTR [rbp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1eb6:
	/* 0x1eb6: mov    QWORD PTR [rbp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ebe:
	/* 0x1ebe: mov    QWORD PTR [rbp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ec6:
	/* 0x1ec6: mov    QWORD PTR [rbp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1ece:
	/* 0x1ece: mov    QWORD PTR [rbp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ed6:
	/* 0x1ed6: mov    QWORD PTR [rbp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1ede:
	/* 0x1ede: mov    r12,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_64);
x86_l_1ee1:
	/* 0x1ee1: mov    QWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ee9:
	/* 0x1ee9: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1eee:
	/* 0x1eee: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ef3:
	/* 0x1ef3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef8:
	/* 0x1ef8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1efd:
	/* 0x1efd: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_1f00:
	/* 0x1f00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f02:
	/* 0x1f02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f05:
	/* 0x1f05: je     2270 <generic_usdt_process_event+0x2270> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2270;
	}
x86_l_1f0b:
	/* 0x1f0b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f0e:
	/* 0x1f0e: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_1f13:
	/* 0x1f13: mov    r15,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1f1a:
	/* 0x1f1a: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_1f1f:
	/* 0x1f1f: lea    rdx,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f24:
	/* 0x1f24: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f2c:
	/* 0x1f2c: mov    ebx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 8ULL);
x86_l_1f31:
	/* 0x1f31: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f36:
	/* 0x1f36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f3b:
	/* 0x1f3b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f40:
	/* 0x1f40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f42:
	/* 0x1f42: add    r12,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1f46:
	/* 0x1f46: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f4b:
	/* 0x1f4b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1f50:
	/* 0x1f50: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f55:
	/* 0x1f55: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f5d:
	/* 0x1f5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5f:
	/* 0x1f5f: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f67:
	/* 0x1f67: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f6c:
	/* 0x1f6c: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f71:
	/* 0x1f71: lea    r12,[r13*1+0x90] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 144ULL);
x86_l_1f79:
	/* 0x1f79: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f7c:
	/* 0x1f7c: test   BYTE PTR [rsp+0xb0],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244128ULL);
x86_l_1f84:
	/* 0x1f84: je     2a26 <generic_usdt_process_event+0x2a26> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10790ULL;
	}
x86_l_1f8a:
	/* 0x1f8a: cmp    QWORD PTR [rsp+0x20],0x1000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438957568ULL);
x86_l_1f93:
	/* 0x1f93: jb     29ff <generic_usdt_process_event+0x29ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 10751ULL;
	}
x86_l_1f99:
	/* 0x1f99: mov    DWORD PTR [r12],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1fa1:
	/* 0x1fa1: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1fa5:
	/* 0x1fa5: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1faa:
	/* 0x1faa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fad:
	/* 0x1fad: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1fb0:
	/* 0x1fb0: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fb5:
	/* 0x1fb5: call   0 <generic_usdt_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 8122ULL);
	__x86_sim_call_depth++;
	return 13709ULL;
x86_l_1fba:
	/* 0x1fba: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1fbd:
	/* 0x1fbd: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1fc1:
	/* 0x1fc1: jmp    c2f <generic_usdt_process_event+0xc2f> */
	return 3119ULL;
x86_l_1fc6:
	/* 0x1fc6: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1fd6:
	/* 0x1fd6: movzx  ebp,WORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 184ULL);
x86_l_1fde:
	/* 0x1fde: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_ipv6_ext_heap)));
x86_l_1fe5:
	/* 0x1fe5: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1fed:
	/* 0x1fed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ff7:
	/* 0x1ff7: lea    r13,[rcx+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1ffb:
	/* 0x1ffb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ffd:
	/* 0x1ffd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2000:
	/* 0x2000: je     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12656ULL;
	}
x86_l_2006:
	/* 0x2006: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2009:
	/* 0x2009: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_200c:
	/* 0x200c: mov    BYTE PTR [rax+0x5],0xff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21474836735ULL);
x86_l_2010:
	/* 0x2010: mov    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_2014:
	/* 0x2014: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_2017:
	/* 0x2017: add    rdi,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_201b:
	/* 0x201b: lea    rdx,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_201f:
	/* 0x201f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2024:
	/* 0x2024: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2029:
	/* 0x2029: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_202e:
	/* 0x202e: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_2033:
	/* 0x2033: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2035:
	/* 0x2035: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2038:
	/* 0x2038: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_203e:
	/* 0x203e: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2043:
	/* 0x2043: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2046:
	/* 0x2046: jg     2a7a <generic_usdt_process_event+0x2a7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 10874ULL;
	}
x86_l_204c:
	/* 0x204c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_204e:
	/* 0x204e: je     2b13 <generic_usdt_process_event+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11027ULL;
	}
x86_l_2054:
	/* 0x2054: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2057:
	/* 0x2057: je     2b13 <generic_usdt_process_event+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11027ULL;
	}
x86_l_205d:
	/* 0x205d: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2060:
	/* 0x2060: jne    2cf1 <generic_usdt_process_event+0x2cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11505ULL;
	}
x86_l_2066:
	/* 0x2066: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_206d:
	/* 0x206d: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2071:
	/* 0x2071: jmp    2c3b <generic_usdt_process_event+0x2c3b> */
	return 11323ULL;
x86_l_2076:
	/* 0x2076: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_207a:
	/* 0x207a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_207f:
	/* 0x207f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2084:
	/* 0x2084: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_2087:
	/* 0x2087: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_208c:
	/* 0x208c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_208e:
	/* 0x208e: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2092:
	/* 0x2092: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2097:
	/* 0x2097: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_209c:
	/* 0x209c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_209f:
	/* 0x209f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20a4:
	/* 0x20a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a6:
	/* 0x20a6: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20aa:
	/* 0x20aa: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20ae:
	/* 0x20ae: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_20b2:
	/* 0x20b2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20b7:
	/* 0x20b7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20bc:
	/* 0x20bc: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20c1:
	/* 0x20c1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_20c4:
	/* 0x20c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c6:
	/* 0x20c6: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_20ca:
	/* 0x20ca: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20cf:
	/* 0x20cf: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20d4:
	/* 0x20d4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_20d9:
	/* 0x20d9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20dc:
	/* 0x20dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20de:
	/* 0x20de: movzx  eax,WORD PTR [rbp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20e2:
	/* 0x20e2: movbe  WORD PTR [rbp+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_20e8:
	/* 0x20e8: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_20ed:
	/* 0x20ed: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20f2:
	/* 0x20f2: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_20f9:
	/* 0x20f9: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_20fe:
	/* 0x20fe: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2103:
	/* 0x2103: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2105:
	/* 0x2105: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2108:
	/* 0x2108: je     3327 <generic_usdt_process_event+0x3327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 13095ULL;
	}
x86_l_210e:
	/* 0x210e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2110:
	/* 0x2110: mov    DWORD PTR [r13+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2114:
	/* 0x2114: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2118:
	/* 0x2118: mov    QWORD PTR [r13+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_211c:
	/* 0x211c: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_211f:
	/* 0x211f: mov    DWORD PTR [r13+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2123:
	/* 0x2123: jmp    3327 <generic_usdt_process_event+0x3327> */
	return 13095ULL;
x86_l_2128:
	/* 0x2128: mov    QWORD PTR [rbp+r13*1+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 618475290624ULL);
x86_l_2134:
	/* 0x2134: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_213a:
	/* 0x213a: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_213f:
	/* 0x213f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2144:
	/* 0x2144: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2146:
	/* 0x2146: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_214a:
	/* 0x214a: jne    2155 <generic_usdt_process_event+0x2155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2155;
	}
x86_l_214c:
	/* 0x214c: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2151:
	/* 0x2151: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2155:
	/* 0x2155: mov    r12,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_64);
x86_l_2158:
	/* 0x2158: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_215c:
	/* 0x215c: mov    rdx,QWORD PTR [rbx+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2160:
	/* 0x2160: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2165:
	/* 0x2165: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_216a:
	/* 0x216a: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_216f:
	/* 0x216f: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_2178:
	/* 0x2178: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2180:
	/* 0x2180: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2188:
	/* 0x2188: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_218f:
	/* 0x218f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2191:
	/* 0x2191: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2199:
	/* 0x2199: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_219e:
	/* 0x219e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21a3:
	/* 0x21a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21a5:
	/* 0x21a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21a7:
	/* 0x21a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21aa:
	/* 0x21aa: je     2ad1 <generic_usdt_process_event+0x2ad1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10961ULL;
	}
x86_l_21b0:
	/* 0x21b0: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_21b2:
	/* 0x21b2: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21b7:
	/* 0x21b7: mov    WORD PTR [rsp+0x42],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 283467841541ULL);
x86_l_21be:
	/* 0x21be: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_21c8:
	/* 0x21c8: mov    QWORD PTR [rsp+0x44],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_21cd:
	/* 0x21cd: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_21d4:
	/* 0x21d4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_21d9:
	/* 0x21d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21de:
	/* 0x21de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e0:
	/* 0x21e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21e3:
	/* 0x21e3: je     2aa7 <generic_usdt_process_event+0x2aa7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10919ULL;
	}
x86_l_21e9:
	/* 0x21e9: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_21eb:
	/* 0x21eb: jmp    2ad1 <generic_usdt_process_event+0x2ad1> */
	return 10961ULL;
x86_l_21f0:
	/* 0x21f0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21f3:
	/* 0x21f3: je     247a <generic_usdt_process_event+0x247a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9338ULL;
	}
x86_l_21f9:
	/* 0x21f9: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21fc:
	/* 0x21fc: jne    2895 <generic_usdt_process_event+0x2895> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 10389ULL;
	}
x86_l_2202:
	/* 0x2202: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_2205:
	/* 0x2205: add    rax,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_220b:
	/* 0x220b: jmp    2483 <generic_usdt_process_event+0x2483> */
	return 9347ULL;
x86_l_2210:
	/* 0x2210: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2215:
	/* 0x2215: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221a:
	/* 0x221a: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_221e:
	/* 0x221e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2223:
	/* 0x2223: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2228:
	/* 0x2228: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_222d:
	/* 0x222d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_222f:
	/* 0x222f: lea    rdi,[r12+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2234:
	/* 0x2234: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2238:
	/* 0x2238: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_223d:
	/* 0x223d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2242:
	/* 0x2242: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2247:
	/* 0x2247: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_224a:
	/* 0x224a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224c:
	/* 0x224c: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2251:
	/* 0x2251: movzx  eax,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2255:
	/* 0x2255: movbe  WORD PTR [rcx+0x2],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_225b:
	/* 0x225b: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2260:
	/* 0x2260: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2265:
	/* 0x2265: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_226b:
	/* 0x226b: jmp    2372 <generic_usdt_process_event+0x2372> */
	goto x86_l_2372;
x86_l_2270:
	/* 0x2270: lea    rdi,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2275:
	/* 0x2275: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_227a:
	/* 0x227a: mov    edx,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 63ULL);
x86_l_227f:
	/* 0x227f: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_2284:
	/* 0x2284: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2289:
	/* 0x2289: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_228e:
	/* 0x228e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2290:
	/* 0x2290: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2293:
	/* 0x2293: js     1f0b <generic_usdt_process_event+0x1f0b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1f0b;
	}
x86_l_2299:
	/* 0x2299: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_229e:
	/* 0x229e: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22a2:
	/* 0x22a2: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22aa:
	/* 0x22aa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22af:
	/* 0x22af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22b4:
	/* 0x22b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22b9:
	/* 0x22b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22bb:
	/* 0x22bb: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22c0:
	/* 0x22c0: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_22c5:
	/* 0x22c5: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22cd:
	/* 0x22cd: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_22d0:
	/* 0x22d0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22d5:
	/* 0x22d5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22da:
	/* 0x22da: add    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_22e2:
	/* 0x22e2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e7:
	/* 0x22e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e9:
	/* 0x22e9: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_22ed:
	/* 0x22ed: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_22f5:
	/* 0x22f5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_22fa:
	/* 0x22fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22ff:
	/* 0x22ff: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2304:
	/* 0x2304: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2307:
	/* 0x2307: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2309:
	/* 0x2309: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_230f:
	/* 0x230f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2312:
	/* 0x2312: jne    2c16 <generic_usdt_process_event+0x2c16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11286ULL;
	}
x86_l_2318:
	/* 0x2318: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_231a:
	/* 0x231a: cmp    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_2322:
	/* 0x2322: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_2325:
	/* 0x2325: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2329:
	/* 0x2329: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_232e:
	/* 0x232e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2331:
	/* 0x2331: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2334:
	/* 0x2334: jmp    2c1b <generic_usdt_process_event+0x2c1b> */
	return 11291ULL;
x86_l_2339:
	/* 0x2339: add    r15,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3ULL);
x86_l_233d:
	/* 0x233d: mov    ecx,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 107ULL);
x86_l_2342:
	/* 0x2342: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2347:
	/* 0x2347: mov    esi,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 107ULL);
x86_l_234c:
	/* 0x234c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_234f:
	/* 0x234f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2351:
	/* 0x2351: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2354:
	/* 0x2354: mov    al,0x6b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 107ULL);
x86_l_2356:
	/* 0x2356: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2358:
	/* 0x2358: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_235d:
	/* 0x235d: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2362:
	/* 0x2362: js     236c <generic_usdt_process_event+0x236c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_236c;
	}
x86_l_2364:
	/* 0x2364: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2369:
	/* 0x2369: mov    BYTE PTR [rcx+0x3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_236c:
	/* 0x236c: mov    r15d,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 112ULL);
x86_l_2372:
	/* 0x2372: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2377:
	/* 0x2377: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_237c:
	/* 0x237c: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_2384:
	/* 0x2384: jmp    d53 <generic_usdt_process_event+0xd53> */
	return 3411ULL;
x86_l_2389:
	/* 0x2389: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_238c:
	/* 0x238c: je     2b36 <generic_usdt_process_event+0x2b36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11062ULL;
	}
x86_l_2392:
	/* 0x2392: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
	return 9109ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 9109ULL: goto x86_l_2395;
	case 9115ULL: goto x86_l_239b;
	case 9122ULL: goto x86_l_23a2;
	case 9127ULL: goto x86_l_23a7;
	case 9131ULL: goto x86_l_23ab;
	case 9136ULL: goto x86_l_23b0;
	case 9141ULL: goto x86_l_23b5;
	case 9144ULL: goto x86_l_23b8;
	case 9149ULL: goto x86_l_23bd;
	case 9151ULL: goto x86_l_23bf;
	case 9155ULL: goto x86_l_23c3;
	case 9160ULL: goto x86_l_23c8;
	case 9165ULL: goto x86_l_23cd;
	case 9168ULL: goto x86_l_23d0;
	case 9173ULL: goto x86_l_23d5;
	case 9175ULL: goto x86_l_23d7;
	case 9178ULL: goto x86_l_23da;
	case 9182ULL: goto x86_l_23de;
	case 9186ULL: goto x86_l_23e2;
	case 9190ULL: goto x86_l_23e6;
	case 9195ULL: goto x86_l_23eb;
	case 9200ULL: goto x86_l_23f0;
	case 9205ULL: goto x86_l_23f5;
	case 9208ULL: goto x86_l_23f8;
	case 9210ULL: goto x86_l_23fa;
	case 9214ULL: goto x86_l_23fe;
	case 9219ULL: goto x86_l_2403;
	case 9224ULL: goto x86_l_2408;
	case 9229ULL: goto x86_l_240d;
	case 9232ULL: goto x86_l_2410;
	case 9234ULL: goto x86_l_2412;
	case 9239ULL: goto x86_l_2417;
	case 9246ULL: goto x86_l_241e;
	case 9250ULL: goto x86_l_2422;
	case 9255ULL: goto x86_l_2427;
	case 9262ULL: goto x86_l_242e;
	case 9267ULL: goto x86_l_2433;
	case 9272ULL: goto x86_l_2438;
	case 9274ULL: goto x86_l_243a;
	case 9277ULL: goto x86_l_243d;
	case 9279ULL: goto x86_l_243f;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9290ULL: goto x86_l_244a;
	case 9294ULL: goto x86_l_244e;
	case 9298ULL: goto x86_l_2452;
	case 9301ULL: goto x86_l_2455;
	case 9305ULL: goto x86_l_2459;
	case 9311ULL: goto x86_l_245f;
	case 9316ULL: goto x86_l_2464;
	case 9319ULL: goto x86_l_2467;
	case 9325ULL: goto x86_l_246d;
	case 9327ULL: goto x86_l_246f;
	case 9330ULL: goto x86_l_2472;
	case 9336ULL: goto x86_l_2478;
	case 9338ULL: goto x86_l_247a;
	case 9341ULL: goto x86_l_247d;
	case 9347ULL: goto x86_l_2483;
	case 9350ULL: goto x86_l_2486;
	case 9358ULL: goto x86_l_248e;
	case 9364ULL: goto x86_l_2494;
	case 9367ULL: goto x86_l_2497;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9384ULL: goto x86_l_24a8;
	case 9389ULL: goto x86_l_24ad;
	case 9394ULL: goto x86_l_24b2;
	case 9399ULL: goto x86_l_24b7;
	case 9404ULL: goto x86_l_24bc;
	case 9406ULL: goto x86_l_24be;
	case 9411ULL: goto x86_l_24c3;
	case 9413ULL: goto x86_l_24c5;
	case 9419ULL: goto x86_l_24cb;
	case 9424ULL: goto x86_l_24d0;
	case 9429ULL: goto x86_l_24d5;
	case 9432ULL: goto x86_l_24d8;
	case 9440ULL: goto x86_l_24e0;
	case 9447ULL: goto x86_l_24e7;
	case 9453ULL: goto x86_l_24ed;
	case 9458ULL: goto x86_l_24f2;
	case 9462ULL: goto x86_l_24f6;
	case 9464ULL: goto x86_l_24f8;
	case 9470ULL: goto x86_l_24fe;
	case 9473ULL: goto x86_l_2501;
	case 9478ULL: goto x86_l_2506;
	case 9483ULL: goto x86_l_250b;
	case 9491ULL: goto x86_l_2513;
	case 9496ULL: goto x86_l_2518;
	case 9498ULL: goto x86_l_251a;
	case 9503ULL: goto x86_l_251f;
	case 9505ULL: goto x86_l_2521;
	case 9511ULL: goto x86_l_2527;
	case 9515ULL: goto x86_l_252b;
	case 9521ULL: goto x86_l_2531;
	case 9526ULL: goto x86_l_2536;
	case 9530ULL: goto x86_l_253a;
	case 9535ULL: goto x86_l_253f;
	case 9541ULL: goto x86_l_2545;
	case 9546ULL: goto x86_l_254a;
	case 9551ULL: goto x86_l_254f;
	case 9556ULL: goto x86_l_2554;
	case 9558ULL: goto x86_l_2556;
	case 9563ULL: goto x86_l_255b;
	case 9565ULL: goto x86_l_255d;
	case 9571ULL: goto x86_l_2563;
	case 9576ULL: goto x86_l_2568;
	case 9581ULL: goto x86_l_256d;
	case 9588ULL: goto x86_l_2574;
	case 9594ULL: goto x86_l_257a;
	case 9602ULL: goto x86_l_2582;
	case 9604ULL: goto x86_l_2584;
	case 9610ULL: goto x86_l_258a;
	case 9613ULL: goto x86_l_258d;
	case 9618ULL: goto x86_l_2592;
	case 9623ULL: goto x86_l_2597;
	case 9628ULL: goto x86_l_259c;
	case 9630ULL: goto x86_l_259e;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9639ULL: goto x86_l_25a7;
	case 9645ULL: goto x86_l_25ad;
	case 9653ULL: goto x86_l_25b5;
	case 9657ULL: goto x86_l_25b9;
	case 9663ULL: goto x86_l_25bf;
	case 9668ULL: goto x86_l_25c4;
	case 9672ULL: goto x86_l_25c8;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9688ULL: goto x86_l_25d8;
	case 9693ULL: goto x86_l_25dd;
	case 9698ULL: goto x86_l_25e2;
	case 9700ULL: goto x86_l_25e4;
	case 9705ULL: goto x86_l_25e9;
	case 9707ULL: goto x86_l_25eb;
	case 9713ULL: goto x86_l_25f1;
	case 9718ULL: goto x86_l_25f6;
	case 9723ULL: goto x86_l_25fb;
	case 9728ULL: goto x86_l_2600;
	case 9734ULL: goto x86_l_2606;
	case 9740ULL: goto x86_l_260c;
	case 9743ULL: goto x86_l_260f;
	case 9745ULL: goto x86_l_2611;
	case 9751ULL: goto x86_l_2617;
	case 9754ULL: goto x86_l_261a;
	case 9759ULL: goto x86_l_261f;
	case 9764ULL: goto x86_l_2624;
	case 9769ULL: goto x86_l_2629;
	case 9774ULL: goto x86_l_262e;
	case 9776ULL: goto x86_l_2630;
	case 9781ULL: goto x86_l_2635;
	case 9783ULL: goto x86_l_2637;
	case 9789ULL: goto x86_l_263d;
	case 9794ULL: goto x86_l_2642;
	case 9802ULL: goto x86_l_264a;
	case 9806ULL: goto x86_l_264e;
	case 9812ULL: goto x86_l_2654;
	case 9817ULL: goto x86_l_2659;
	case 9821ULL: goto x86_l_265d;
	case 9826ULL: goto x86_l_2662;
	case 9832ULL: goto x86_l_2668;
	case 9837ULL: goto x86_l_266d;
	case 9842ULL: goto x86_l_2672;
	case 9847ULL: goto x86_l_2677;
	case 9849ULL: goto x86_l_2679;
	case 9854ULL: goto x86_l_267e;
	case 9856ULL: goto x86_l_2680;
	case 9862ULL: goto x86_l_2686;
	case 9867ULL: goto x86_l_268b;
	case 9872ULL: goto x86_l_2690;
	case 9878ULL: goto x86_l_2696;
	case 9884ULL: goto x86_l_269c;
	case 9887ULL: goto x86_l_269f;
	case 9892ULL: goto x86_l_26a4;
	case 9895ULL: goto x86_l_26a7;
	case 9898ULL: goto x86_l_26aa;
	case 9904ULL: goto x86_l_26b0;
	case 9907ULL: goto x86_l_26b3;
	case 9912ULL: goto x86_l_26b8;
	case 9917ULL: goto x86_l_26bd;
	case 9920ULL: goto x86_l_26c0;
	case 9925ULL: goto x86_l_26c5;
	case 9927ULL: goto x86_l_26c7;
	case 9932ULL: goto x86_l_26cc;
	case 9934ULL: goto x86_l_26ce;
	case 9940ULL: goto x86_l_26d4;
	case 9948ULL: goto x86_l_26dc;
	case 9952ULL: goto x86_l_26e0;
	case 9958ULL: goto x86_l_26e6;
	case 9963ULL: goto x86_l_26eb;
	case 9967ULL: goto x86_l_26ef;
	case 9972ULL: goto x86_l_26f4;
	case 9978ULL: goto x86_l_26fa;
	case 9983ULL: goto x86_l_26ff;
	case 9988ULL: goto x86_l_2704;
	case 9993ULL: goto x86_l_2709;
	case 9995ULL: goto x86_l_270b;
	case 10000ULL: goto x86_l_2710;
	case 10002ULL: goto x86_l_2712;
	case 10008ULL: goto x86_l_2718;
	case 10013ULL: goto x86_l_271d;
	case 10018ULL: goto x86_l_2722;
	case 10023ULL: goto x86_l_2727;
	case 10029ULL: goto x86_l_272d;
	case 10035ULL: goto x86_l_2733;
	case 10038ULL: goto x86_l_2736;
	case 10041ULL: goto x86_l_2739;
	case 10043ULL: goto x86_l_273b;
	case 10049ULL: goto x86_l_2741;
	case 10052ULL: goto x86_l_2744;
	case 10057ULL: goto x86_l_2749;
	case 10062ULL: goto x86_l_274e;
	case 10067ULL: goto x86_l_2753;
	case 10072ULL: goto x86_l_2758;
	case 10074ULL: goto x86_l_275a;
	case 10079ULL: goto x86_l_275f;
	case 10081ULL: goto x86_l_2761;
	case 10087ULL: goto x86_l_2767;
	case 10092ULL: goto x86_l_276c;
	case 10100ULL: goto x86_l_2774;
	case 10104ULL: goto x86_l_2778;
	case 10110ULL: goto x86_l_277e;
	case 10115ULL: goto x86_l_2783;
	case 10119ULL: goto x86_l_2787;
	case 10124ULL: goto x86_l_278c;
	case 10130ULL: goto x86_l_2792;
	case 10135ULL: goto x86_l_2797;
	case 10140ULL: goto x86_l_279c;
	case 10145ULL: goto x86_l_27a1;
	case 10147ULL: goto x86_l_27a3;
	case 10152ULL: goto x86_l_27a8;
	case 10154ULL: goto x86_l_27aa;
	case 10160ULL: goto x86_l_27b0;
	case 10165ULL: goto x86_l_27b5;
	case 10170ULL: goto x86_l_27ba;
	case 10177ULL: goto x86_l_27c1;
	case 10183ULL: goto x86_l_27c7;
	case 10188ULL: goto x86_l_27cc;
	case 10191ULL: goto x86_l_27cf;
	case 10194ULL: goto x86_l_27d2;
	case 10200ULL: goto x86_l_27d8;
	case 10203ULL: goto x86_l_27db;
	case 10208ULL: goto x86_l_27e0;
	case 10213ULL: goto x86_l_27e5;
	case 10218ULL: goto x86_l_27ea;
	case 10220ULL: goto x86_l_27ec;
	case 10222ULL: goto x86_l_27ee;
	case 10227ULL: goto x86_l_27f3;
	case 10229ULL: goto x86_l_27f5;
	case 10235ULL: goto x86_l_27fb;
	case 10243ULL: goto x86_l_2803;
	case 10247ULL: goto x86_l_2807;
	case 10253ULL: goto x86_l_280d;
	case 10258ULL: goto x86_l_2812;
	case 10262ULL: goto x86_l_2816;
	case 10267ULL: goto x86_l_281b;
	case 10273ULL: goto x86_l_2821;
	case 10278ULL: goto x86_l_2826;
	case 10283ULL: goto x86_l_282b;
	case 10288ULL: goto x86_l_2830;
	case 10290ULL: goto x86_l_2832;
	case 10295ULL: goto x86_l_2837;
	case 10297ULL: goto x86_l_2839;
	case 10299ULL: goto x86_l_283b;
	case 10304ULL: goto x86_l_2840;
	case 10309ULL: goto x86_l_2845;
	case 10316ULL: goto x86_l_284c;
	case 10318ULL: goto x86_l_284e;
	case 10321ULL: goto x86_l_2851;
	case 10327ULL: goto x86_l_2857;
	case 10330ULL: goto x86_l_285a;
	case 10335ULL: goto x86_l_285f;
	case 10340ULL: goto x86_l_2864;
	case 10345ULL: goto x86_l_2869;
	case 10348ULL: goto x86_l_286c;
	case 10351ULL: goto x86_l_286f;
	case 10353ULL: goto x86_l_2871;
	case 10358ULL: goto x86_l_2876;
	case 10360ULL: goto x86_l_2878;
	case 10362ULL: goto x86_l_287a;
	case 10370ULL: goto x86_l_2882;
	case 10375ULL: goto x86_l_2887;
	case 10380ULL: goto x86_l_288c;
	case 10384ULL: goto x86_l_2890;
	case 10389ULL: goto x86_l_2895;
	case 10392ULL: goto x86_l_2898;
	case 10397ULL: goto x86_l_289d;
	case 10405ULL: goto x86_l_28a5;
	case 10413ULL: goto x86_l_28ad;
	case 10419ULL: goto x86_l_28b3;
	case 10424ULL: goto x86_l_28b8;
	case 10426ULL: goto x86_l_28ba;
	case 10430ULL: goto x86_l_28be;
	case 10432ULL: goto x86_l_28c0;
	case 10437ULL: goto x86_l_28c5;
	case 10441ULL: goto x86_l_28c9;
	case 10445ULL: goto x86_l_28cd;
	case 10449ULL: goto x86_l_28d1;
	case 10454ULL: goto x86_l_28d6;
	case 10459ULL: goto x86_l_28db;
	case 10464ULL: goto x86_l_28e0;
	case 10469ULL: goto x86_l_28e5;
	case 10477ULL: goto x86_l_28ed;
	case 10485ULL: goto x86_l_28f5;
	case 10492ULL: goto x86_l_28fc;
	case 10494ULL: goto x86_l_28fe;
	case 10502ULL: goto x86_l_2906;
	case 10507ULL: goto x86_l_290b;
	case 10512ULL: goto x86_l_2910;
	case 10514ULL: goto x86_l_2912;
	case 10516ULL: goto x86_l_2914;
	case 10519ULL: goto x86_l_2917;
	case 10525ULL: goto x86_l_291d;
	case 10527ULL: goto x86_l_291f;
	case 10532ULL: goto x86_l_2924;
	case 10539ULL: goto x86_l_292b;
	case 10549ULL: goto x86_l_2935;
	case 10554ULL: goto x86_l_293a;
	case 10561ULL: goto x86_l_2941;
	case 10566ULL: goto x86_l_2946;
	case 10571ULL: goto x86_l_294b;
	case 10573ULL: goto x86_l_294d;
	case 10576ULL: goto x86_l_2950;
	case 10582ULL: goto x86_l_2956;
	case 10584ULL: goto x86_l_2958;
	case 10589ULL: goto x86_l_295d;
	case 10591ULL: goto x86_l_295f;
	case 10599ULL: goto x86_l_2967;
	case 10604ULL: goto x86_l_296c;
	case 10612ULL: goto x86_l_2974;
	case 10616ULL: goto x86_l_2978;
	case 10621ULL: goto x86_l_297d;
	case 10625ULL: goto x86_l_2981;
	case 10630ULL: goto x86_l_2986;
	case 10637ULL: goto x86_l_298d;
	case 10645ULL: goto x86_l_2995;
	case 10650ULL: goto x86_l_299a;
	case 10654ULL: goto x86_l_299e;
	case 10661ULL: goto x86_l_29a5;
	case 10664ULL: goto x86_l_29a8;
	case 10670ULL: goto x86_l_29ae;
	case 10675ULL: goto x86_l_29b3;
	case 10681ULL: goto x86_l_29b9;
	case 10687ULL: goto x86_l_29bf;
	case 10691ULL: goto x86_l_29c3;
	case 10696ULL: goto x86_l_29c8;
	case 10701ULL: goto x86_l_29cd;
	case 10704ULL: goto x86_l_29d0;
	case 10706ULL: goto x86_l_29d2;
	case 10708ULL: goto x86_l_29d4;
	case 10710ULL: goto x86_l_29d6;
	case 10715ULL: goto x86_l_29db;
	case 10719ULL: goto x86_l_29df;
	case 10724ULL: goto x86_l_29e4;
	case 10727ULL: goto x86_l_29e7;
	case 10732ULL: goto x86_l_29ec;
	case 10740ULL: goto x86_l_29f4;
	case 10746ULL: goto x86_l_29fa;
	case 10751ULL: goto x86_l_29ff;
	case 10758ULL: goto x86_l_2a06;
	case 10766ULL: goto x86_l_2a0e;
	case 10771ULL: goto x86_l_2a13;
	case 10775ULL: goto x86_l_2a17;
	case 10782ULL: goto x86_l_2a1e;
	case 10785ULL: goto x86_l_2a21;
	case 10790ULL: goto x86_l_2a26;
	case 10795ULL: goto x86_l_2a2b;
	case 10801ULL: goto x86_l_2a31;
	case 10807ULL: goto x86_l_2a37;
	case 10811ULL: goto x86_l_2a3b;
	case 10816ULL: goto x86_l_2a40;
	case 10821ULL: goto x86_l_2a45;
	case 10827ULL: goto x86_l_2a4b;
	case 10830ULL: goto x86_l_2a4e;
	case 10832ULL: goto x86_l_2a50;
	case 10834ULL: goto x86_l_2a52;
	case 10836ULL: goto x86_l_2a54;
	case 10841ULL: goto x86_l_2a59;
	case 10845ULL: goto x86_l_2a5d;
	case 10850ULL: goto x86_l_2a62;
	case 10853ULL: goto x86_l_2a65;
	case 10856ULL: goto x86_l_2a68;
	case 10861ULL: goto x86_l_2a6d;
	case 10869ULL: goto x86_l_2a75;
	case 10874ULL: goto x86_l_2a7a;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2395:
	/* 0x2395: jne    2b40 <generic_usdt_process_event+0x2b40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 11072ULL;
	}
x86_l_239b:
	/* 0x239b: lea    rax,[rbx+0x5e58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24152ULL);
x86_l_23a2:
	/* 0x23a2: jmp    2b3d <generic_usdt_process_event+0x2b3d> */
	return 11069ULL;
x86_l_23a7:
	/* 0x23a7: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23ab:
	/* 0x23ab: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23b0:
	/* 0x23b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23b5:
	/* 0x23b5: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_23b8:
	/* 0x23b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23bd:
	/* 0x23bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23bf:
	/* 0x23bf: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23c3:
	/* 0x23c3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_23c8:
	/* 0x23c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23cd:
	/* 0x23cd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_23d0:
	/* 0x23d0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_23d5:
	/* 0x23d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d7:
	/* 0x23d7: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_23da:
	/* 0x23da: lea    rdi,[r13+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23de:
	/* 0x23de: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23e2:
	/* 0x23e2: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_23e6:
	/* 0x23e6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_23eb:
	/* 0x23eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23f0:
	/* 0x23f0: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_23f5:
	/* 0x23f5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23f8:
	/* 0x23f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23fa:
	/* 0x23fa: lea    rdi,[r13+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_23fe:
	/* 0x23fe: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2403:
	/* 0x2403: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2408:
	/* 0x2408: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_240d:
	/* 0x240d: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2410:
	/* 0x2410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2412:
	/* 0x2412: movzx  eax,WORD PTR [r13+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_2417:
	/* 0x2417: movbe  WORD PTR [r13+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_241e:
	/* 0x241e: mov    rax,QWORD PTR [rbp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2422:
	/* 0x2422: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2427:
	/* 0x2427: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&socktrack_map)));
x86_l_242e:
	/* 0x242e: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2433:
	/* 0x2433: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2438:
	/* 0x2438: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_243a:
	/* 0x243a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_243d:
	/* 0x243d: je     2459 <generic_usdt_process_event+0x2459> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2459;
	}
x86_l_243f:
	/* 0x243f: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2441:
	/* 0x2441: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2446:
	/* 0x2446: mov    DWORD PTR [r13+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_244a:
	/* 0x244a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_244e:
	/* 0x244e: mov    QWORD PTR [r13+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2452:
	/* 0x2452: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2455:
	/* 0x2455: mov    DWORD PTR [r13+0x7c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_2459:
	/* 0x2459: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_245f:
	/* 0x245f: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_2464:
	/* 0x2464: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_2467:
	/* 0x2467: add    rax,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_246d:
	/* 0x246d: jmp    2483 <generic_usdt_process_event+0x2483> */
	goto x86_l_2483;
x86_l_246f:
	/* 0x246f: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_2472:
	/* 0x2472: add    rax,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_2478:
	/* 0x2478: jmp    2483 <generic_usdt_process_event+0x2483> */
	goto x86_l_2483;
x86_l_247a:
	/* 0x247a: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_247d:
	/* 0x247d: add    rax,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_2483:
	/* 0x2483: mov    r13,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2486:
	/* 0x2486: test   BYTE PTR [rsp+0xb0],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244112ULL);
x86_l_248e:
	/* 0x248e: jne    28b3 <generic_usdt_process_event+0x28b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28b3;
	}
x86_l_2494:
	/* 0x2494: test   r13,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_64);
x86_l_2497:
	/* 0x2497: je     295d <generic_usdt_process_event+0x295d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_295d;
	}
x86_l_249d:
	/* 0x249d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_24a2:
	/* 0x24a2: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_24a8:
	/* 0x24a8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_24ad:
	/* 0x24ad: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b2:
	/* 0x24b2: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24b7:
	/* 0x24b7: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24bc:
	/* 0x24bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24be:
	/* 0x24be: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_24c3:
	/* 0x24c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_24c5:
	/* 0x24c5: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_24cb:
	/* 0x24cb: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24d0:
	/* 0x24d0: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_24d5:
	/* 0x24d5: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_24d8:
	/* 0x24d8: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_24e0:
	/* 0x24e0: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_24e7:
	/* 0x24e7: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_24ed:
	/* 0x24ed: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24f2:
	/* 0x24f2: lea    rbp,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_24f6:
	/* 0x24f6: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_24f8:
	/* 0x24f8: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_24fe:
	/* 0x24fe: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2501:
	/* 0x2501: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2506:
	/* 0x2506: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_250b:
	/* 0x250b: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2513:
	/* 0x2513: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2518:
	/* 0x2518: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251a:
	/* 0x251a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_251f:
	/* 0x251f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2521:
	/* 0x2521: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_2527:
	/* 0x2527: cmp    r13,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 1ULL);
x86_l_252b:
	/* 0x252b: je     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_2531:
	/* 0x2531: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2536:
	/* 0x2536: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_253a:
	/* 0x253a: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_253f:
	/* 0x253f: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2545:
	/* 0x2545: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_254a:
	/* 0x254a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_254f:
	/* 0x254f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2554:
	/* 0x2554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2556:
	/* 0x2556: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_255b:
	/* 0x255b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_255d:
	/* 0x255d: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_2563:
	/* 0x2563: mov    rbx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2568:
	/* 0x2568: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_256d:
	/* 0x256d: cmp    rbx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 4094ULL);
x86_l_2574:
	/* 0x2574: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_257a:
	/* 0x257a: add    rbp,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2582:
	/* 0x2582: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_2584:
	/* 0x2584: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_258a:
	/* 0x258a: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_258d:
	/* 0x258d: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2592:
	/* 0x2592: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2597:
	/* 0x2597: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_259c:
	/* 0x259c: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_259e:
	/* 0x259e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a0:
	/* 0x25a0: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25a5:
	/* 0x25a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25a7:
	/* 0x25a7: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_25ad:
	/* 0x25ad: add    QWORD PTR [rsp+0x90],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_25b5:
	/* 0x25b5: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_25b9:
	/* 0x25b9: jb     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2967;
	}
x86_l_25bf:
	/* 0x25bf: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25c4:
	/* 0x25c4: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25c8:
	/* 0x25c8: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25cd:
	/* 0x25cd: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_25d3:
	/* 0x25d3: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_25d8:
	/* 0x25d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25dd:
	/* 0x25dd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_25e2:
	/* 0x25e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e4:
	/* 0x25e4: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_25e9:
	/* 0x25e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25eb:
	/* 0x25eb: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_25f1:
	/* 0x25f1: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_25f6:
	/* 0x25f6: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_25fb:
	/* 0x25fb: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2600:
	/* 0x2600: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2606:
	/* 0x2606: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_260c:
	/* 0x260c: add    rbx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_260f:
	/* 0x260f: mov    edi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_32);
x86_l_2611:
	/* 0x2611: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2617:
	/* 0x2617: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_261a:
	/* 0x261a: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_261f:
	/* 0x261f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2624:
	/* 0x2624: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2629:
	/* 0x2629: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_262e:
	/* 0x262e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2630:
	/* 0x2630: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2635:
	/* 0x2635: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2637:
	/* 0x2637: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_263d:
	/* 0x263d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2642:
	/* 0x2642: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_264a:
	/* 0x264a: cmp    r13,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 3ULL);
x86_l_264e:
	/* 0x264e: je     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_2654:
	/* 0x2654: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2659:
	/* 0x2659: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_265d:
	/* 0x265d: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2662:
	/* 0x2662: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2668:
	/* 0x2668: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_266d:
	/* 0x266d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2672:
	/* 0x2672: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2677:
	/* 0x2677: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2679:
	/* 0x2679: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_267e:
	/* 0x267e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2680:
	/* 0x2680: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_2686:
	/* 0x2686: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_268b:
	/* 0x268b: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2690:
	/* 0x2690: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_2696:
	/* 0x2696: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_269c:
	/* 0x269c: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_269f:
	/* 0x269f: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_26a4:
	/* 0x26a4: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26a7:
	/* 0x26a7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_26aa:
	/* 0x26aa: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_26b0:
	/* 0x26b0: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26b3:
	/* 0x26b3: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26b8:
	/* 0x26b8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_26bd:
	/* 0x26bd: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_26c0:
	/* 0x26c0: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26c5:
	/* 0x26c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26c7:
	/* 0x26c7: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_26cc:
	/* 0x26cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26ce:
	/* 0x26ce: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_26d4:
	/* 0x26d4: add    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_26dc:
	/* 0x26dc: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_26e0:
	/* 0x26e0: jb     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2967;
	}
x86_l_26e6:
	/* 0x26e6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_26eb:
	/* 0x26eb: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_26ef:
	/* 0x26ef: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_26f4:
	/* 0x26f4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_26fa:
	/* 0x26fa: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_26ff:
	/* 0x26ff: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2704:
	/* 0x2704: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2709:
	/* 0x2709: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270b:
	/* 0x270b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2710:
	/* 0x2710: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2712:
	/* 0x2712: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_2718:
	/* 0x2718: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_271d:
	/* 0x271d: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2722:
	/* 0x2722: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2727:
	/* 0x2727: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_272d:
	/* 0x272d: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_2733:
	/* 0x2733: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2736:
	/* 0x2736: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_2739:
	/* 0x2739: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_273b:
	/* 0x273b: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2741:
	/* 0x2741: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2744:
	/* 0x2744: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2749:
	/* 0x2749: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_274e:
	/* 0x274e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2753:
	/* 0x2753: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2758:
	/* 0x2758: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_275a:
	/* 0x275a: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_275f:
	/* 0x275f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2761:
	/* 0x2761: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_2767:
	/* 0x2767: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_276c:
	/* 0x276c: add    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2774:
	/* 0x2774: cmp    r13,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 5ULL);
x86_l_2778:
	/* 0x2778: je     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_277e:
	/* 0x277e: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2783:
	/* 0x2783: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2787:
	/* 0x2787: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_278c:
	/* 0x278c: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2792:
	/* 0x2792: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2797:
	/* 0x2797: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_279c:
	/* 0x279c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_27a1:
	/* 0x27a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27a3:
	/* 0x27a3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27a8:
	/* 0x27a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27aa:
	/* 0x27aa: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_27b0:
	/* 0x27b0: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_27b5:
	/* 0x27b5: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_27ba:
	/* 0x27ba: cmp    rbp,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 4094ULL);
x86_l_27c1:
	/* 0x27c1: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_27c7:
	/* 0x27c7: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27cc:
	/* 0x27cc: add    rdi,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27cf:
	/* 0x27cf: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_27d2:
	/* 0x27d2: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_27d8:
	/* 0x27d8: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27db:
	/* 0x27db: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27e0:
	/* 0x27e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_27e5:
	/* 0x27e5: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_27ea:
	/* 0x27ea: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_27ec:
	/* 0x27ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27ee:
	/* 0x27ee: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_27f3:
	/* 0x27f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27f5:
	/* 0x27f5: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_27fb:
	/* 0x27fb: add    QWORD PTR [rsp+0x90],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2803:
	/* 0x2803: cmp    r13,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 7ULL);
x86_l_2807:
	/* 0x2807: jb     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2967;
	}
x86_l_280d:
	/* 0x280d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2812:
	/* 0x2812: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_2816:
	/* 0x2816: lea    rdi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_281b:
	/* 0x281b: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2821:
	/* 0x2821: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2826:
	/* 0x2826: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_282b:
	/* 0x282b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2830:
	/* 0x2830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2832:
	/* 0x2832: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2837:
	/* 0x2837: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2839:
	/* 0x2839: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_283b:
	/* 0x283b: mov    r13,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2840:
	/* 0x2840: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_2845:
	/* 0x2845: cmp    r13,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4094ULL);
x86_l_284c:
	/* 0x284c: ja     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2887;
	}
x86_l_284e:
	/* 0x284e: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2851:
	/* 0x2851: and    ebp,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2857:
	/* 0x2857: add    rbp,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_285a:
	/* 0x285a: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_285f:
	/* 0x285f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2864:
	/* 0x2864: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2869:
	/* 0x2869: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_286c:
	/* 0x286c: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_286f:
	/* 0x286f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2871:
	/* 0x2871: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_2876:
	/* 0x2876: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2878:
	/* 0x2878: js     2887 <generic_usdt_process_event+0x2887> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2887;
	}
x86_l_287a:
	/* 0x287a: add    QWORD PTR [rsp+0x90],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 144ULL);
x86_l_2882:
	/* 0x2882: jmp    2967 <generic_usdt_process_event+0x2967> */
	goto x86_l_2967;
x86_l_2887:
	/* 0x2887: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_288c:
	/* 0x288c: mov    DWORD PTR [r12+rax*1],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2890:
	/* 0x2890: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_2895:
	/* 0x2895: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2898:
	/* 0x2898: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_289d:
	/* 0x289d: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_28a5:
	/* 0x28a5: test   BYTE PTR [rsp+0xb0],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 755914244112ULL);
x86_l_28ad:
	/* 0x28ad: je     2967 <generic_usdt_process_event+0x2967> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2967;
	}
x86_l_28b3:
	/* 0x28b3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_28b8:
	/* 0x28b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28ba:
	/* 0x28ba: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_28be:
	/* 0x28be: jne    28c9 <generic_usdt_process_event+0x28c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_28c9;
	}
x86_l_28c0:
	/* 0x28c0: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_28c5:
	/* 0x28c5: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28c9:
	/* 0x28c9: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_28cd:
	/* 0x28cd: mov    rdx,QWORD PTR [rbp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28d1:
	/* 0x28d1: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_28d6:
	/* 0x28d6: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28db:
	/* 0x28db: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_28e0:
	/* 0x28e0: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28e5:
	/* 0x28e5: mov    QWORD PTR [rsp+0x98],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_28ed:
	/* 0x28ed: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_28f5:
	/* 0x28f5: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_28fc:
	/* 0x28fc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28fe:
	/* 0x28fe: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2906:
	/* 0x2906: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_290b:
	/* 0x290b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2910:
	/* 0x2910: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2912:
	/* 0x2912: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2914:
	/* 0x2914: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2917:
	/* 0x2917: je     2b01 <generic_usdt_process_event+0x2b01> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 11009ULL;
	}
x86_l_291d:
	/* 0x291d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_291f:
	/* 0x291f: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2924:
	/* 0x2924: mov    WORD PTR [rsp+0x42],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 283467841541ULL);
x86_l_292b:
	/* 0x292b: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_2935:
	/* 0x2935: mov    QWORD PTR [rsp+0x44],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_293a:
	/* 0x293a: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2941:
	/* 0x2941: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2946:
	/* 0x2946: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_294b:
	/* 0x294b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294d:
	/* 0x294d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2950:
	/* 0x2950: je     2add <generic_usdt_process_event+0x2add> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 10973ULL;
	}
x86_l_2956:
	/* 0x2956: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2958:
	/* 0x2958: jmp    2b01 <generic_usdt_process_event+0x2b01> */
	return 11009ULL;
x86_l_295d:
	/* 0x295d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_295f:
	/* 0x295f: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2967:
	/* 0x2967: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_296c:
	/* 0x296c: mov    r15,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2974:
	/* 0x2974: mov    DWORD PTR [r12+rax*1],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2978:
	/* 0x2978: mov    DWORD PTR [r12+rax*1+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4ULL);
x86_l_297d:
	/* 0x297d: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2981:
	/* 0x2981: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	return 11286ULL;
x86_l_2986:
	/* 0x2986: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_298d:
	/* 0x298d: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2995:
	/* 0x2995: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_299a:
	/* 0x299a: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_299e:
	/* 0x299e: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_29a5:
	/* 0x29a5: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29a8:
	/* 0x29a8: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_29ae:
	/* 0x29ae: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b3:
	/* 0x29b3: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_29b9:
	/* 0x29b9: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_29bf:
	/* 0x29bf: cmovb  r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_29c3:
	/* 0x29c3: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_29c8:
	/* 0x29c8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_29cd:
	/* 0x29cd: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_29d0:
	/* 0x29d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29d2:
	/* 0x29d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d4:
	/* 0x29d4: js     29ec <generic_usdt_process_event+0x29ec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_29ec;
	}
x86_l_29d6:
	/* 0x29d6: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29db:
	/* 0x29db: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29df:
	/* 0x29df: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29e4:
	/* 0x29e4: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_29e7:
	/* 0x29e7: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_29ec:
	/* 0x29ec: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_29f4:
	/* 0x29f4: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_29fa:
	/* 0x29fa: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_29ff:
	/* 0x29ff: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2a06:
	/* 0x2a06: mov    DWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a0e:
	/* 0x2a0e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2a13:
	/* 0x2a13: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a17:
	/* 0x2a17: and    r12d,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2a1e:
	/* 0x2a1e: add    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a21:
	/* 0x2a21: mov    ebx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 12ULL);
x86_l_2a26:
	/* 0x2a26: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a2b:
	/* 0x2a2b: cmp    rax,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4095ULL);
x86_l_2a31:
	/* 0x2a31: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_2a37:
	/* 0x2a37: cmovb  r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_B);
x86_l_2a3b:
	/* 0x2a3b: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a40:
	/* 0x2a40: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2a45:
	/* 0x2a45: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2a4b:
	/* 0x2a4b: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2a4e:
	/* 0x2a4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a50:
	/* 0x2a50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a52:
	/* 0x2a52: js     2a6d <generic_usdt_process_event+0x2a6d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2a6d;
	}
x86_l_2a54:
	/* 0x2a54: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a59:
	/* 0x2a59: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a5d:
	/* 0x2a5d: mov    DWORD PTR [r12+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a62:
	/* 0x2a62: add    rbx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2a65:
	/* 0x2a65: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_2a68:
	/* 0x2a68: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_2a6d:
	/* 0x2a6d: mov    DWORD PTR [r12],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2a75:
	/* 0x2a75: jmp    332d <generic_usdt_process_event+0x332d> */
	return 13101ULL;
x86_l_2a7a:
	/* 0x2a7a: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
	return 10877ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 10877ULL: goto x86_l_2a7d;
	case 10883ULL: goto x86_l_2a83;
	case 10886ULL: goto x86_l_2a86;
	case 10892ULL: goto x86_l_2a8c;
	case 10897ULL: goto x86_l_2a91;
	case 10903ULL: goto x86_l_2a97;
	case 10910ULL: goto x86_l_2a9e;
	case 10914ULL: goto x86_l_2aa2;
	case 10919ULL: goto x86_l_2aa7;
	case 10930ULL: goto x86_l_2ab2;
	case 10937ULL: goto x86_l_2ab9;
	case 10939ULL: goto x86_l_2abb;
	case 10944ULL: goto x86_l_2ac0;
	case 10952ULL: goto x86_l_2ac8;
	case 10957ULL: goto x86_l_2acd;
	case 10959ULL: goto x86_l_2acf;
	case 10961ULL: goto x86_l_2ad1;
	case 10968ULL: goto x86_l_2ad8;
	case 10973ULL: goto x86_l_2add;
	case 10981ULL: goto x86_l_2ae5;
	case 10988ULL: goto x86_l_2aec;
	case 10990ULL: goto x86_l_2aee;
	case 10995ULL: goto x86_l_2af3;
	case 11000ULL: goto x86_l_2af8;
	case 11005ULL: goto x86_l_2afd;
	case 11007ULL: goto x86_l_2aff;
	case 11009ULL: goto x86_l_2b01;
	case 11014ULL: goto x86_l_2b06;
	case 11022ULL: goto x86_l_2b0e;
	case 11027ULL: goto x86_l_2b13;
	case 11032ULL: goto x86_l_2b18;
	case 11039ULL: goto x86_l_2b1f;
	case 11044ULL: goto x86_l_2b24;
	case 11051ULL: goto x86_l_2b2b;
	case 11053ULL: goto x86_l_2b2d;
	case 11060ULL: goto x86_l_2b34;
	case 11062ULL: goto x86_l_2b36;
	case 11069ULL: goto x86_l_2b3d;
	case 11072ULL: goto x86_l_2b40;
	case 11077ULL: goto x86_l_2b45;
	case 11085ULL: goto x86_l_2b4d;
	case 11090ULL: goto x86_l_2b52;
	case 11095ULL: goto x86_l_2b57;
	case 11100ULL: goto x86_l_2b5c;
	case 11106ULL: goto x86_l_2b62;
	case 11111ULL: goto x86_l_2b67;
	case 11113ULL: goto x86_l_2b69;
	case 11121ULL: goto x86_l_2b71;
	case 11125ULL: goto x86_l_2b75;
	case 11127ULL: goto x86_l_2b77;
	case 11134ULL: goto x86_l_2b7e;
	case 11136ULL: goto x86_l_2b80;
	case 11143ULL: goto x86_l_2b87;
	case 11147ULL: goto x86_l_2b8b;
	case 11152ULL: goto x86_l_2b90;
	case 11155ULL: goto x86_l_2b93;
	case 11158ULL: goto x86_l_2b96;
	case 11163ULL: goto x86_l_2b9b;
	case 11166ULL: goto x86_l_2b9e;
	case 11171ULL: goto x86_l_2ba3;
	case 11174ULL: goto x86_l_2ba6;
	case 11178ULL: goto x86_l_2baa;
	case 11183ULL: goto x86_l_2baf;
	case 11190ULL: goto x86_l_2bb6;
	case 11197ULL: goto x86_l_2bbd;
	case 11202ULL: goto x86_l_2bc2;
	case 11205ULL: goto x86_l_2bc5;
	case 11211ULL: goto x86_l_2bcb;
	case 11214ULL: goto x86_l_2bce;
	case 11220ULL: goto x86_l_2bd4;
	case 11227ULL: goto x86_l_2bdb;
	case 11233ULL: goto x86_l_2be1;
	case 11237ULL: goto x86_l_2be5;
	case 11241ULL: goto x86_l_2be9;
	case 11246ULL: goto x86_l_2bee;
	case 11251ULL: goto x86_l_2bf3;
	case 11254ULL: goto x86_l_2bf6;
	case 11256ULL: goto x86_l_2bf8;
	case 11258ULL: goto x86_l_2bfa;
	case 11260ULL: goto x86_l_2bfc;
	case 11264ULL: goto x86_l_2c00;
	case 11268ULL: goto x86_l_2c04;
	case 11271ULL: goto x86_l_2c07;
	case 11273ULL: goto x86_l_2c09;
	case 11280ULL: goto x86_l_2c10;
	case 11286ULL: goto x86_l_2c16;
	case 11291ULL: goto x86_l_2c1b;
	case 11296ULL: goto x86_l_2c20;
	case 11301ULL: goto x86_l_2c25;
	case 11306ULL: goto x86_l_2c2a;
	case 11311ULL: goto x86_l_2c2f;
	case 11318ULL: goto x86_l_2c36;
	case 11323ULL: goto x86_l_2c3b;
	case 11327ULL: goto x86_l_2c3f;
	case 11331ULL: goto x86_l_2c43;
	case 11336ULL: goto x86_l_2c48;
	case 11340ULL: goto x86_l_2c4c;
	case 11346ULL: goto x86_l_2c52;
	case 11356ULL: goto x86_l_2c5c;
	case 11360ULL: goto x86_l_2c60;
	case 11366ULL: goto x86_l_2c66;
	case 11370ULL: goto x86_l_2c6a;
	case 11373ULL: goto x86_l_2c6d;
	case 11378ULL: goto x86_l_2c72;
	case 11381ULL: goto x86_l_2c75;
	case 11386ULL: goto x86_l_2c7a;
	case 11391ULL: goto x86_l_2c7f;
	case 11396ULL: goto x86_l_2c84;
	case 11400ULL: goto x86_l_2c88;
	case 11403ULL: goto x86_l_2c8b;
	case 11408ULL: goto x86_l_2c90;
	case 11410ULL: goto x86_l_2c92;
	case 11413ULL: goto x86_l_2c95;
	case 11419ULL: goto x86_l_2c9b;
	case 11424ULL: goto x86_l_2ca0;
	case 11427ULL: goto x86_l_2ca3;
	case 11429ULL: goto x86_l_2ca5;
	case 11431ULL: goto x86_l_2ca7;
	case 11433ULL: goto x86_l_2ca9;
	case 11436ULL: goto x86_l_2cac;
	case 11438ULL: goto x86_l_2cae;
	case 11441ULL: goto x86_l_2cb1;
	case 11443ULL: goto x86_l_2cb3;
	case 11450ULL: goto x86_l_2cba;
	case 11454ULL: goto x86_l_2cbe;
	case 11456ULL: goto x86_l_2cc0;
	case 11459ULL: goto x86_l_2cc3;
	case 11461ULL: goto x86_l_2cc5;
	case 11464ULL: goto x86_l_2cc8;
	case 11466ULL: goto x86_l_2cca;
	case 11471ULL: goto x86_l_2ccf;
	case 11473ULL: goto x86_l_2cd1;
	case 11480ULL: goto x86_l_2cd8;
	case 11484ULL: goto x86_l_2cdc;
	case 11486ULL: goto x86_l_2cde;
	case 11491ULL: goto x86_l_2ce3;
	case 11498ULL: goto x86_l_2cea;
	case 11503ULL: goto x86_l_2cef;
	case 11505ULL: goto x86_l_2cf1;
	case 11510ULL: goto x86_l_2cf6;
	case 11515ULL: goto x86_l_2cfb;
	case 11520ULL: goto x86_l_2d00;
	case 11527ULL: goto x86_l_2d07;
	case 11532ULL: goto x86_l_2d0c;
	case 11534ULL: goto x86_l_2d0e;
	case 11539ULL: goto x86_l_2d13;
	case 11543ULL: goto x86_l_2d17;
	case 11547ULL: goto x86_l_2d1b;
	case 11552ULL: goto x86_l_2d20;
	case 11556ULL: goto x86_l_2d24;
	case 11562ULL: goto x86_l_2d2a;
	case 11572ULL: goto x86_l_2d34;
	case 11576ULL: goto x86_l_2d38;
	case 11582ULL: goto x86_l_2d3e;
	case 11586ULL: goto x86_l_2d42;
	case 11589ULL: goto x86_l_2d45;
	case 11594ULL: goto x86_l_2d4a;
	case 11597ULL: goto x86_l_2d4d;
	case 11602ULL: goto x86_l_2d52;
	case 11607ULL: goto x86_l_2d57;
	case 11612ULL: goto x86_l_2d5c;
	case 11616ULL: goto x86_l_2d60;
	case 11619ULL: goto x86_l_2d63;
	case 11624ULL: goto x86_l_2d68;
	case 11626ULL: goto x86_l_2d6a;
	case 11629ULL: goto x86_l_2d6d;
	case 11635ULL: goto x86_l_2d73;
	case 11640ULL: goto x86_l_2d78;
	case 11643ULL: goto x86_l_2d7b;
	case 11645ULL: goto x86_l_2d7d;
	case 11647ULL: goto x86_l_2d7f;
	case 11649ULL: goto x86_l_2d81;
	case 11652ULL: goto x86_l_2d84;
	case 11654ULL: goto x86_l_2d86;
	case 11657ULL: goto x86_l_2d89;
	case 11659ULL: goto x86_l_2d8b;
	case 11666ULL: goto x86_l_2d92;
	case 11670ULL: goto x86_l_2d96;
	case 11672ULL: goto x86_l_2d98;
	case 11675ULL: goto x86_l_2d9b;
	case 11677ULL: goto x86_l_2d9d;
	case 11680ULL: goto x86_l_2da0;
	case 11682ULL: goto x86_l_2da2;
	case 11687ULL: goto x86_l_2da7;
	case 11689ULL: goto x86_l_2da9;
	case 11696ULL: goto x86_l_2db0;
	case 11700ULL: goto x86_l_2db4;
	case 11702ULL: goto x86_l_2db6;
	case 11707ULL: goto x86_l_2dbb;
	case 11714ULL: goto x86_l_2dc2;
	case 11719ULL: goto x86_l_2dc7;
	case 11721ULL: goto x86_l_2dc9;
	case 11726ULL: goto x86_l_2dce;
	case 11733ULL: goto x86_l_2dd5;
	case 11738ULL: goto x86_l_2dda;
	case 11740ULL: goto x86_l_2ddc;
	case 11745ULL: goto x86_l_2de1;
	case 11749ULL: goto x86_l_2de5;
	case 11753ULL: goto x86_l_2de9;
	case 11758ULL: goto x86_l_2dee;
	case 11762ULL: goto x86_l_2df2;
	case 11768ULL: goto x86_l_2df8;
	case 11778ULL: goto x86_l_2e02;
	case 11782ULL: goto x86_l_2e06;
	case 11788ULL: goto x86_l_2e0c;
	case 11792ULL: goto x86_l_2e10;
	case 11795ULL: goto x86_l_2e13;
	case 11800ULL: goto x86_l_2e18;
	case 11803ULL: goto x86_l_2e1b;
	case 11808ULL: goto x86_l_2e20;
	case 11813ULL: goto x86_l_2e25;
	case 11818ULL: goto x86_l_2e2a;
	case 11822ULL: goto x86_l_2e2e;
	case 11825ULL: goto x86_l_2e31;
	case 11830ULL: goto x86_l_2e36;
	case 11832ULL: goto x86_l_2e38;
	case 11835ULL: goto x86_l_2e3b;
	case 11841ULL: goto x86_l_2e41;
	case 11846ULL: goto x86_l_2e46;
	case 11849ULL: goto x86_l_2e49;
	case 11851ULL: goto x86_l_2e4b;
	case 11853ULL: goto x86_l_2e4d;
	case 11855ULL: goto x86_l_2e4f;
	case 11858ULL: goto x86_l_2e52;
	case 11860ULL: goto x86_l_2e54;
	case 11863ULL: goto x86_l_2e57;
	case 11865ULL: goto x86_l_2e59;
	case 11872ULL: goto x86_l_2e60;
	case 11876ULL: goto x86_l_2e64;
	case 11878ULL: goto x86_l_2e66;
	case 11881ULL: goto x86_l_2e69;
	case 11883ULL: goto x86_l_2e6b;
	case 11886ULL: goto x86_l_2e6e;
	case 11888ULL: goto x86_l_2e70;
	case 11893ULL: goto x86_l_2e75;
	case 11895ULL: goto x86_l_2e77;
	case 11902ULL: goto x86_l_2e7e;
	case 11906ULL: goto x86_l_2e82;
	case 11908ULL: goto x86_l_2e84;
	case 11913ULL: goto x86_l_2e89;
	case 11920ULL: goto x86_l_2e90;
	case 11925ULL: goto x86_l_2e95;
	case 11927ULL: goto x86_l_2e97;
	case 11932ULL: goto x86_l_2e9c;
	case 11939ULL: goto x86_l_2ea3;
	case 11944ULL: goto x86_l_2ea8;
	case 11946ULL: goto x86_l_2eaa;
	case 11951ULL: goto x86_l_2eaf;
	case 11955ULL: goto x86_l_2eb3;
	case 11959ULL: goto x86_l_2eb7;
	case 11964ULL: goto x86_l_2ebc;
	case 11968ULL: goto x86_l_2ec0;
	case 11974ULL: goto x86_l_2ec6;
	case 11984ULL: goto x86_l_2ed0;
	case 11988ULL: goto x86_l_2ed4;
	case 11994ULL: goto x86_l_2eda;
	case 11998ULL: goto x86_l_2ede;
	case 12001ULL: goto x86_l_2ee1;
	case 12006ULL: goto x86_l_2ee6;
	case 12009ULL: goto x86_l_2ee9;
	case 12014ULL: goto x86_l_2eee;
	case 12019ULL: goto x86_l_2ef3;
	case 12024ULL: goto x86_l_2ef8;
	case 12028ULL: goto x86_l_2efc;
	case 12031ULL: goto x86_l_2eff;
	case 12036ULL: goto x86_l_2f04;
	case 12038ULL: goto x86_l_2f06;
	case 12041ULL: goto x86_l_2f09;
	case 12047ULL: goto x86_l_2f0f;
	case 12052ULL: goto x86_l_2f14;
	case 12055ULL: goto x86_l_2f17;
	case 12057ULL: goto x86_l_2f19;
	case 12059ULL: goto x86_l_2f1b;
	case 12061ULL: goto x86_l_2f1d;
	case 12064ULL: goto x86_l_2f20;
	case 12066ULL: goto x86_l_2f22;
	case 12069ULL: goto x86_l_2f25;
	case 12071ULL: goto x86_l_2f27;
	case 12078ULL: goto x86_l_2f2e;
	case 12082ULL: goto x86_l_2f32;
	case 12084ULL: goto x86_l_2f34;
	case 12087ULL: goto x86_l_2f37;
	case 12089ULL: goto x86_l_2f39;
	case 12092ULL: goto x86_l_2f3c;
	case 12094ULL: goto x86_l_2f3e;
	case 12099ULL: goto x86_l_2f43;
	case 12101ULL: goto x86_l_2f45;
	case 12108ULL: goto x86_l_2f4c;
	case 12112ULL: goto x86_l_2f50;
	case 12114ULL: goto x86_l_2f52;
	case 12119ULL: goto x86_l_2f57;
	case 12126ULL: goto x86_l_2f5e;
	case 12131ULL: goto x86_l_2f63;
	case 12133ULL: goto x86_l_2f65;
	case 12138ULL: goto x86_l_2f6a;
	case 12145ULL: goto x86_l_2f71;
	case 12150ULL: goto x86_l_2f76;
	case 12152ULL: goto x86_l_2f78;
	case 12157ULL: goto x86_l_2f7d;
	case 12161ULL: goto x86_l_2f81;
	case 12165ULL: goto x86_l_2f85;
	case 12170ULL: goto x86_l_2f8a;
	case 12174ULL: goto x86_l_2f8e;
	case 12180ULL: goto x86_l_2f94;
	case 12190ULL: goto x86_l_2f9e;
	case 12194ULL: goto x86_l_2fa2;
	case 12200ULL: goto x86_l_2fa8;
	case 12204ULL: goto x86_l_2fac;
	case 12207ULL: goto x86_l_2faf;
	case 12212ULL: goto x86_l_2fb4;
	case 12215ULL: goto x86_l_2fb7;
	case 12220ULL: goto x86_l_2fbc;
	case 12225ULL: goto x86_l_2fc1;
	case 12230ULL: goto x86_l_2fc6;
	case 12234ULL: goto x86_l_2fca;
	case 12237ULL: goto x86_l_2fcd;
	case 12242ULL: goto x86_l_2fd2;
	case 12244ULL: goto x86_l_2fd4;
	case 12247ULL: goto x86_l_2fd7;
	case 12253ULL: goto x86_l_2fdd;
	case 12258ULL: goto x86_l_2fe2;
	case 12261ULL: goto x86_l_2fe5;
	case 12263ULL: goto x86_l_2fe7;
	case 12265ULL: goto x86_l_2fe9;
	case 12267ULL: goto x86_l_2feb;
	case 12270ULL: goto x86_l_2fee;
	case 12272ULL: goto x86_l_2ff0;
	case 12275ULL: goto x86_l_2ff3;
	case 12277ULL: goto x86_l_2ff5;
	case 12284ULL: goto x86_l_2ffc;
	case 12288ULL: goto x86_l_3000;
	case 12290ULL: goto x86_l_3002;
	case 12293ULL: goto x86_l_3005;
	case 12295ULL: goto x86_l_3007;
	case 12298ULL: goto x86_l_300a;
	case 12300ULL: goto x86_l_300c;
	case 12305ULL: goto x86_l_3011;
	case 12307ULL: goto x86_l_3013;
	case 12314ULL: goto x86_l_301a;
	case 12318ULL: goto x86_l_301e;
	case 12320ULL: goto x86_l_3020;
	case 12325ULL: goto x86_l_3025;
	case 12332ULL: goto x86_l_302c;
	case 12337ULL: goto x86_l_3031;
	case 12339ULL: goto x86_l_3033;
	case 12344ULL: goto x86_l_3038;
	case 12351ULL: goto x86_l_303f;
	case 12356ULL: goto x86_l_3044;
	case 12358ULL: goto x86_l_3046;
	case 12363ULL: goto x86_l_304b;
	case 12367ULL: goto x86_l_304f;
	case 12371ULL: goto x86_l_3053;
	case 12376ULL: goto x86_l_3058;
	case 12380ULL: goto x86_l_305c;
	case 12386ULL: goto x86_l_3062;
	case 12396ULL: goto x86_l_306c;
	case 12400ULL: goto x86_l_3070;
	case 12406ULL: goto x86_l_3076;
	case 12410ULL: goto x86_l_307a;
	case 12413ULL: goto x86_l_307d;
	case 12418ULL: goto x86_l_3082;
	case 12421ULL: goto x86_l_3085;
	case 12426ULL: goto x86_l_308a;
	case 12431ULL: goto x86_l_308f;
	case 12436ULL: goto x86_l_3094;
	case 12440ULL: goto x86_l_3098;
	case 12443ULL: goto x86_l_309b;
	case 12448ULL: goto x86_l_30a0;
	case 12450ULL: goto x86_l_30a2;
	case 12453ULL: goto x86_l_30a5;
	case 12459ULL: goto x86_l_30ab;
	case 12464ULL: goto x86_l_30b0;
	case 12467ULL: goto x86_l_30b3;
	case 12469ULL: goto x86_l_30b5;
	case 12471ULL: goto x86_l_30b7;
	case 12473ULL: goto x86_l_30b9;
	case 12476ULL: goto x86_l_30bc;
	case 12478ULL: goto x86_l_30be;
	case 12481ULL: goto x86_l_30c1;
	case 12483ULL: goto x86_l_30c3;
	case 12490ULL: goto x86_l_30ca;
	case 12494ULL: goto x86_l_30ce;
	case 12496ULL: goto x86_l_30d0;
	case 12499ULL: goto x86_l_30d3;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2a7d:
	/* 0x2a7d: je     2c2a <generic_usdt_process_event+0x2c2a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2c2a;
	}
x86_l_2a83:
	/* 0x2a83: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2a86:
	/* 0x2a86: je     2b13 <generic_usdt_process_event+0x2b13> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2b13;
	}
x86_l_2a8c:
	/* 0x2a8c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2a91:
	/* 0x2a91: jne    2cf1 <generic_usdt_process_event+0x2cf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2cf1;
	}
x86_l_2a97:
	/* 0x2a97: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2a9e:
	/* 0x2a9e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2aa2:
	/* 0x2aa2: jmp    2c3b <generic_usdt_process_event+0x2c3b> */
	goto x86_l_2c3b;
x86_l_2aa7:
	/* 0x2aa7: mov    DWORD PTR [rsp+0xb8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982465ULL);
x86_l_2ab2:
	/* 0x2ab2: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2ab9:
	/* 0x2ab9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2abb:
	/* 0x2abb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ac0:
	/* 0x2ac0: lea    rdx,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2ac8:
	/* 0x2ac8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2acd:
	/* 0x2acd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2acf:
	/* 0x2acf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad1:
	/* 0x2ad1: mov    DWORD PTR [rbp+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_2ad8:
	/* 0x2ad8: jmp    2c10 <generic_usdt_process_event+0x2c10> */
	goto x86_l_2c10;
x86_l_2add:
	/* 0x2add: mov    DWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_2ae5:
	/* 0x2ae5: mov    rdi,QWORD PTR [rip+0x9e2] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_2aec:
	/* 0x2aec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aee:
	/* 0x2aee: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2af3:
	/* 0x2af3: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2af8:
	/* 0x2af8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2afd:
	/* 0x2afd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2aff:
	/* 0x2aff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b01:
	/* 0x2b01: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b06:
	/* 0x2b06: mov    DWORD PTR [r12+rax*1],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 4294967292ULL);
x86_l_2b0e:
	/* 0x2b0e: jmp    2c10 <generic_usdt_process_event+0x2c10> */
	goto x86_l_2c10;
x86_l_2b13:
	/* 0x2b13: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2b18:
	/* 0x2b18: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2b1f:
	/* 0x2b1f: jmp    2c36 <generic_usdt_process_event+0x2c36> */
	goto x86_l_2c36;
x86_l_2b24:
	/* 0x2b24: lea    rax,[rbx+0x5e60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24160ULL);
x86_l_2b2b:
	/* 0x2b2b: jmp    2b3d <generic_usdt_process_event+0x2b3d> */
	goto x86_l_2b3d;
x86_l_2b2d:
	/* 0x2b2d: lea    rax,[rbx+0x5e68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24168ULL);
x86_l_2b34:
	/* 0x2b34: jmp    2b3d <generic_usdt_process_event+0x2b3d> */
	goto x86_l_2b3d;
x86_l_2b36:
	/* 0x2b36: lea    rax,[rbx+0x5e50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24144ULL);
x86_l_2b3d:
	/* 0x2b3d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b40:
	/* 0x2b40: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b45:
	/* 0x2b45: lea    rdi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2b4d:
	/* 0x2b4d: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b52:
	/* 0x2b52: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2b57:
	/* 0x2b57: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2b5c:
	/* 0x2b5c: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_2b62:
	/* 0x2b62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2b67:
	/* 0x2b67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b69:
	/* 0x2b69: mov    r12,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2b71:
	/* 0x2b71: test   r13b,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_8, 32ULL);
x86_l_2b75:
	/* 0x2b75: je     2bd4 <generic_usdt_process_event+0x2bd4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2bd4;
	}
x86_l_2b77:
	/* 0x2b77: cmp    r12,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4096ULL);
x86_l_2b7e:
	/* 0x2b7e: jb     2baf <generic_usdt_process_event+0x2baf> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2baf;
	}
x86_l_2b80:
	/* 0x2b80: mov    DWORD PTR [rbp+0x0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2b87:
	/* 0x2b87: add    rbp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2b8b:
	/* 0x2b8b: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b90:
	/* 0x2b90: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b93:
	/* 0x2b93: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2b96:
	/* 0x2b96: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b9b:
	/* 0x2b9b: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_2b9e:
	/* 0x2b9e: call   0 <generic_usdt_process_event> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 11171ULL);
	__x86_sim_call_depth++;
	return 13709ULL;
x86_l_2ba3:
	/* 0x2ba3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2ba6:
	/* 0x2ba6: add    r15,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2baa:
	/* 0x2baa: jmp    1e7a <generic_usdt_process_event+0x1e7a> */
	return 7802ULL;
x86_l_2baf:
	/* 0x2baf: add    rbx,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_2bb6:
	/* 0x2bb6: mov    DWORD PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bbd:
	/* 0x2bbd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2bc2:
	/* 0x2bc2: lea    ebp,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bc5:
	/* 0x2bc5: and    ebp,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_2bcb:
	/* 0x2bcb: add    rbp,rbx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bce:
	/* 0x2bce: mov    r15d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 12ULL);
x86_l_2bd4:
	/* 0x2bd4: cmp    r12,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4095ULL);
x86_l_2bdb:
	/* 0x2bdb: mov    r13d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4095ULL);
x86_l_2be1:
	/* 0x2be1: cmovb  r13,r12 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_64, X86_CC_B);
x86_l_2be5:
	/* 0x2be5: lea    rdi,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be9:
	/* 0x2be9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2bee:
	/* 0x2bee: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2bf3:
	/* 0x2bf3: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_2bf6:
	/* 0x2bf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bf8:
	/* 0x2bf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2bfa:
	/* 0x2bfa: js     2c09 <generic_usdt_process_event+0x2c09> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_2c09;
	}
x86_l_2bfc:
	/* 0x2bfc: mov    DWORD PTR [rbp+0x0],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c00:
	/* 0x2c00: mov    DWORD PTR [rbp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c04:
	/* 0x2c04: add    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c07:
	/* 0x2c07: jmp    2c16 <generic_usdt_process_event+0x2c16> */
	goto x86_l_2c16;
x86_l_2c09:
	/* 0x2c09: mov    DWORD PTR [rbp+0x0],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_2c10:
	/* 0x2c10: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_2c16:
	/* 0x2c16: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c1b:
	/* 0x2c1b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2c20:
	/* 0x2c20: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c25:
	/* 0x2c25: jmp    1e84 <generic_usdt_process_event+0x1e84> */
	return 7812ULL;
x86_l_2c2a:
	/* 0x2c2a: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2c2f:
	/* 0x2c2f: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2c36:
	/* 0x2c36: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2c3b:
	/* 0x2c3b: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2c3f:
	/* 0x2c3f: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c43:
	/* 0x2c43: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2c48:
	/* 0x2c48: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2c4c:
	/* 0x2c4c: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13134ULL;
	}
x86_l_2c52:
	/* 0x2c52: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2c5c:
	/* 0x2c5c: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2c60:
	/* 0x2c60: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13134ULL;
	}
x86_l_2c66:
	/* 0x2c66: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2c6a:
	/* 0x2c6a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2c6d:
	/* 0x2c6d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2c72:
	/* 0x2c72: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c75:
	/* 0x2c75: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2c7a:
	/* 0x2c7a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2c7f:
	/* 0x2c7f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c84:
	/* 0x2c84: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c88:
	/* 0x2c88: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c8b:
	/* 0x2c8b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2c90:
	/* 0x2c90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c92:
	/* 0x2c92: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c95:
	/* 0x2c95: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_2c9b:
	/* 0x2c9b: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2ca0:
	/* 0x2ca0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2ca3:
	/* 0x2ca3: jg     2cc0 <generic_usdt_process_event+0x2cc0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2cc0;
	}
x86_l_2ca5:
	/* 0x2ca5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ca7:
	/* 0x2ca7: je     2cde <generic_usdt_process_event+0x2cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cde;
	}
x86_l_2ca9:
	/* 0x2ca9: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2cac:
	/* 0x2cac: je     2cde <generic_usdt_process_event+0x2cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cde;
	}
x86_l_2cae:
	/* 0x2cae: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2cb1:
	/* 0x2cb1: jne    2d0e <generic_usdt_process_event+0x2d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d0e;
	}
x86_l_2cb3:
	/* 0x2cb3: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2cba:
	/* 0x2cba: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2cbe:
	/* 0x2cbe: jmp    2d13 <generic_usdt_process_event+0x2d13> */
	goto x86_l_2d13;
x86_l_2cc0:
	/* 0x2cc0: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2cc3:
	/* 0x2cc3: je     2cfb <generic_usdt_process_event+0x2cfb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cfb;
	}
x86_l_2cc5:
	/* 0x2cc5: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2cc8:
	/* 0x2cc8: je     2cde <generic_usdt_process_event+0x2cde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2cde;
	}
x86_l_2cca:
	/* 0x2cca: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2ccf:
	/* 0x2ccf: jne    2d0e <generic_usdt_process_event+0x2d0e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2d0e;
	}
x86_l_2cd1:
	/* 0x2cd1: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2cd8:
	/* 0x2cd8: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2cdc:
	/* 0x2cdc: jmp    2d13 <generic_usdt_process_event+0x2d13> */
	goto x86_l_2d13;
x86_l_2cde:
	/* 0x2cde: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2ce3:
	/* 0x2ce3: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2cea:
	/* 0x2cea: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2cef:
	/* 0x2cef: jmp    2d13 <generic_usdt_process_event+0x2d13> */
	goto x86_l_2d13;
x86_l_2cf1:
	/* 0x2cf1: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2cf6:
	/* 0x2cf6: jmp    2c3b <generic_usdt_process_event+0x2c3b> */
	goto x86_l_2c3b;
x86_l_2cfb:
	/* 0x2cfb: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2d00:
	/* 0x2d00: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d07:
	/* 0x2d07: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2d0c:
	/* 0x2d0c: jmp    2d13 <generic_usdt_process_event+0x2d13> */
	goto x86_l_2d13;
x86_l_2d0e:
	/* 0x2d0e: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2d13:
	/* 0x2d13: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2d17:
	/* 0x2d17: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d1b:
	/* 0x2d1b: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2d20:
	/* 0x2d20: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2d24:
	/* 0x2d24: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13134ULL;
	}
x86_l_2d2a:
	/* 0x2d2a: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2d34:
	/* 0x2d34: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2d38:
	/* 0x2d38: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13134ULL;
	}
x86_l_2d3e:
	/* 0x2d3e: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2d42:
	/* 0x2d42: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2d45:
	/* 0x2d45: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2d4a:
	/* 0x2d4a: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d4d:
	/* 0x2d4d: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2d52:
	/* 0x2d52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2d57:
	/* 0x2d57: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d5c:
	/* 0x2d5c: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2d60:
	/* 0x2d60: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2d63:
	/* 0x2d63: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2d68:
	/* 0x2d68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d6a:
	/* 0x2d6a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d6d:
	/* 0x2d6d: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_2d73:
	/* 0x2d73: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2d78:
	/* 0x2d78: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2d7b:
	/* 0x2d7b: jg     2d98 <generic_usdt_process_event+0x2d98> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2d98;
	}
x86_l_2d7d:
	/* 0x2d7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d7f:
	/* 0x2d7f: je     2db6 <generic_usdt_process_event+0x2db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db6;
	}
x86_l_2d81:
	/* 0x2d81: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2d84:
	/* 0x2d84: je     2db6 <generic_usdt_process_event+0x2db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db6;
	}
x86_l_2d86:
	/* 0x2d86: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2d89:
	/* 0x2d89: jne    2ddc <generic_usdt_process_event+0x2ddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ddc;
	}
x86_l_2d8b:
	/* 0x2d8b: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2d92:
	/* 0x2d92: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2d96:
	/* 0x2d96: jmp    2de1 <generic_usdt_process_event+0x2de1> */
	goto x86_l_2de1;
x86_l_2d98:
	/* 0x2d98: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2d9b:
	/* 0x2d9b: je     2dc9 <generic_usdt_process_event+0x2dc9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2dc9;
	}
x86_l_2d9d:
	/* 0x2d9d: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2da0:
	/* 0x2da0: je     2db6 <generic_usdt_process_event+0x2db6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2db6;
	}
x86_l_2da2:
	/* 0x2da2: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2da7:
	/* 0x2da7: jne    2ddc <generic_usdt_process_event+0x2ddc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2ddc;
	}
x86_l_2da9:
	/* 0x2da9: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2db0:
	/* 0x2db0: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2db4:
	/* 0x2db4: jmp    2de1 <generic_usdt_process_event+0x2de1> */
	goto x86_l_2de1;
x86_l_2db6:
	/* 0x2db6: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dbb:
	/* 0x2dbb: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2dc2:
	/* 0x2dc2: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2dc7:
	/* 0x2dc7: jmp    2de1 <generic_usdt_process_event+0x2de1> */
	goto x86_l_2de1;
x86_l_2dc9:
	/* 0x2dc9: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2dce:
	/* 0x2dce: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2dd5:
	/* 0x2dd5: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2dda:
	/* 0x2dda: jmp    2de1 <generic_usdt_process_event+0x2de1> */
	goto x86_l_2de1;
x86_l_2ddc:
	/* 0x2ddc: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2de1:
	/* 0x2de1: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2de5:
	/* 0x2de5: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de9:
	/* 0x2de9: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2dee:
	/* 0x2dee: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2df2:
	/* 0x2df2: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13134ULL;
	}
x86_l_2df8:
	/* 0x2df8: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e02:
	/* 0x2e02: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2e06:
	/* 0x2e06: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13134ULL;
	}
x86_l_2e0c:
	/* 0x2e0c: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2e10:
	/* 0x2e10: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2e13:
	/* 0x2e13: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e18:
	/* 0x2e18: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e1b:
	/* 0x2e1b: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2e20:
	/* 0x2e20: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2e25:
	/* 0x2e25: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e2a:
	/* 0x2e2a: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e2e:
	/* 0x2e2e: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e31:
	/* 0x2e31: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2e36:
	/* 0x2e36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e38:
	/* 0x2e38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e3b:
	/* 0x2e3b: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_2e41:
	/* 0x2e41: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2e46:
	/* 0x2e46: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2e49:
	/* 0x2e49: jg     2e66 <generic_usdt_process_event+0x2e66> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2e66;
	}
x86_l_2e4b:
	/* 0x2e4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2e4d:
	/* 0x2e4d: je     2e84 <generic_usdt_process_event+0x2e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e84;
	}
x86_l_2e4f:
	/* 0x2e4f: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2e52:
	/* 0x2e52: je     2e84 <generic_usdt_process_event+0x2e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e84;
	}
x86_l_2e54:
	/* 0x2e54: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2e57:
	/* 0x2e57: jne    2eaa <generic_usdt_process_event+0x2eaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eaa;
	}
x86_l_2e59:
	/* 0x2e59: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2e60:
	/* 0x2e60: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2e64:
	/* 0x2e64: jmp    2eaf <generic_usdt_process_event+0x2eaf> */
	goto x86_l_2eaf;
x86_l_2e66:
	/* 0x2e66: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2e69:
	/* 0x2e69: je     2e97 <generic_usdt_process_event+0x2e97> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e97;
	}
x86_l_2e6b:
	/* 0x2e6b: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2e6e:
	/* 0x2e6e: je     2e84 <generic_usdt_process_event+0x2e84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2e84;
	}
x86_l_2e70:
	/* 0x2e70: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2e75:
	/* 0x2e75: jne    2eaa <generic_usdt_process_event+0x2eaa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2eaa;
	}
x86_l_2e77:
	/* 0x2e77: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2e7e:
	/* 0x2e7e: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2e82:
	/* 0x2e82: jmp    2eaf <generic_usdt_process_event+0x2eaf> */
	goto x86_l_2eaf;
x86_l_2e84:
	/* 0x2e84: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e89:
	/* 0x2e89: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e90:
	/* 0x2e90: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2e95:
	/* 0x2e95: jmp    2eaf <generic_usdt_process_event+0x2eaf> */
	goto x86_l_2eaf;
x86_l_2e97:
	/* 0x2e97: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2e9c:
	/* 0x2e9c: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2ea3:
	/* 0x2ea3: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ea8:
	/* 0x2ea8: jmp    2eaf <generic_usdt_process_event+0x2eaf> */
	goto x86_l_2eaf;
x86_l_2eaa:
	/* 0x2eaa: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2eaf:
	/* 0x2eaf: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2eb3:
	/* 0x2eb3: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2eb7:
	/* 0x2eb7: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2ebc:
	/* 0x2ebc: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2ec0:
	/* 0x2ec0: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13134ULL;
	}
x86_l_2ec6:
	/* 0x2ec6: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2ed0:
	/* 0x2ed0: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2ed4:
	/* 0x2ed4: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13134ULL;
	}
x86_l_2eda:
	/* 0x2eda: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2ede:
	/* 0x2ede: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2ee1:
	/* 0x2ee1: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ee6:
	/* 0x2ee6: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2ee9:
	/* 0x2ee9: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2eee:
	/* 0x2eee: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2ef3:
	/* 0x2ef3: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ef8:
	/* 0x2ef8: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2efc:
	/* 0x2efc: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2eff:
	/* 0x2eff: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2f04:
	/* 0x2f04: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f06:
	/* 0x2f06: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f09:
	/* 0x2f09: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_2f0f:
	/* 0x2f0f: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2f14:
	/* 0x2f14: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2f17:
	/* 0x2f17: jg     2f34 <generic_usdt_process_event+0x2f34> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2f34;
	}
x86_l_2f19:
	/* 0x2f19: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f1b:
	/* 0x2f1b: je     2f52 <generic_usdt_process_event+0x2f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f52;
	}
x86_l_2f1d:
	/* 0x2f1d: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2f20:
	/* 0x2f20: je     2f52 <generic_usdt_process_event+0x2f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f52;
	}
x86_l_2f22:
	/* 0x2f22: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2f25:
	/* 0x2f25: jne    2f78 <generic_usdt_process_event+0x2f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f78;
	}
x86_l_2f27:
	/* 0x2f27: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2f2e:
	/* 0x2f2e: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_2f32:
	/* 0x2f32: jmp    2f7d <generic_usdt_process_event+0x2f7d> */
	goto x86_l_2f7d;
x86_l_2f34:
	/* 0x2f34: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_2f37:
	/* 0x2f37: je     2f65 <generic_usdt_process_event+0x2f65> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f65;
	}
x86_l_2f39:
	/* 0x2f39: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_2f3c:
	/* 0x2f3c: je     2f52 <generic_usdt_process_event+0x2f52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f52;
	}
x86_l_2f3e:
	/* 0x2f3e: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_2f43:
	/* 0x2f43: jne    2f78 <generic_usdt_process_event+0x2f78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2f78;
	}
x86_l_2f45:
	/* 0x2f45: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_2f4c:
	/* 0x2f4c: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_2f50:
	/* 0x2f50: jmp    2f7d <generic_usdt_process_event+0x2f7d> */
	goto x86_l_2f7d;
x86_l_2f52:
	/* 0x2f52: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f57:
	/* 0x2f57: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2f5e:
	/* 0x2f5e: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f63:
	/* 0x2f63: jmp    2f7d <generic_usdt_process_event+0x2f7d> */
	goto x86_l_2f7d;
x86_l_2f65:
	/* 0x2f65: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_2f6a:
	/* 0x2f6a: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2f71:
	/* 0x2f71: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2f76:
	/* 0x2f76: jmp    2f7d <generic_usdt_process_event+0x2f7d> */
	goto x86_l_2f7d;
x86_l_2f78:
	/* 0x2f78: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2f7d:
	/* 0x2f7d: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_2f81:
	/* 0x2f81: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f85:
	/* 0x2f85: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_2f8a:
	/* 0x2f8a: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_2f8e:
	/* 0x2f8e: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13134ULL;
	}
x86_l_2f94:
	/* 0x2f94: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2f9e:
	/* 0x2f9e: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_2fa2:
	/* 0x2fa2: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13134ULL;
	}
x86_l_2fa8:
	/* 0x2fa8: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_2fac:
	/* 0x2fac: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_2faf:
	/* 0x2faf: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fb4:
	/* 0x2fb4: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fb7:
	/* 0x2fb7: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_2fbc:
	/* 0x2fbc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2fc1:
	/* 0x2fc1: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fc6:
	/* 0x2fc6: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2fca:
	/* 0x2fca: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2fcd:
	/* 0x2fcd: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2fd2:
	/* 0x2fd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fd4:
	/* 0x2fd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2fd7:
	/* 0x2fd7: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_2fdd:
	/* 0x2fdd: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_2fe2:
	/* 0x2fe2: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_2fe5:
	/* 0x2fe5: jg     3002 <generic_usdt_process_event+0x3002> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3002;
	}
x86_l_2fe7:
	/* 0x2fe7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fe9:
	/* 0x2fe9: je     3020 <generic_usdt_process_event+0x3020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3020;
	}
x86_l_2feb:
	/* 0x2feb: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2fee:
	/* 0x2fee: je     3020 <generic_usdt_process_event+0x3020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3020;
	}
x86_l_2ff0:
	/* 0x2ff0: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_2ff3:
	/* 0x2ff3: jne    3046 <generic_usdt_process_event+0x3046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3046;
	}
x86_l_2ff5:
	/* 0x2ff5: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_2ffc:
	/* 0x2ffc: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_3000:
	/* 0x3000: jmp    304b <generic_usdt_process_event+0x304b> */
	goto x86_l_304b;
x86_l_3002:
	/* 0x3002: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_3005:
	/* 0x3005: je     3033 <generic_usdt_process_event+0x3033> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3033;
	}
x86_l_3007:
	/* 0x3007: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_300a:
	/* 0x300a: je     3020 <generic_usdt_process_event+0x3020> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3020;
	}
x86_l_300c:
	/* 0x300c: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_3011:
	/* 0x3011: jne    3046 <generic_usdt_process_event+0x3046> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3046;
	}
x86_l_3013:
	/* 0x3013: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_301a:
	/* 0x301a: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_301e:
	/* 0x301e: jmp    304b <generic_usdt_process_event+0x304b> */
	goto x86_l_304b;
x86_l_3020:
	/* 0x3020: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3025:
	/* 0x3025: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_302c:
	/* 0x302c: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3031:
	/* 0x3031: jmp    304b <generic_usdt_process_event+0x304b> */
	goto x86_l_304b;
x86_l_3033:
	/* 0x3033: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3038:
	/* 0x3038: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_303f:
	/* 0x303f: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3044:
	/* 0x3044: jmp    304b <generic_usdt_process_event+0x304b> */
	goto x86_l_304b;
x86_l_3046:
	/* 0x3046: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_304b:
	/* 0x304b: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_304f:
	/* 0x304f: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3053:
	/* 0x3053: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3058:
	/* 0x3058: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_305c:
	/* 0x305c: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 13134ULL;
	}
x86_l_3062:
	/* 0x3062: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_306c:
	/* 0x306c: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_3070:
	/* 0x3070: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 13134ULL;
	}
x86_l_3076:
	/* 0x3076: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_307a:
	/* 0x307a: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_307d:
	/* 0x307d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3082:
	/* 0x3082: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3085:
	/* 0x3085: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_308a:
	/* 0x308a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_308f:
	/* 0x308f: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3094:
	/* 0x3094: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3098:
	/* 0x3098: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_309b:
	/* 0x309b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_30a0:
	/* 0x30a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a2:
	/* 0x30a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30a5:
	/* 0x30a5: js     3170 <generic_usdt_process_event+0x3170> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 12656ULL;
	}
x86_l_30ab:
	/* 0x30ab: movzx  eax,BYTE PTR [r15+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 5ULL);
x86_l_30b0:
	/* 0x30b0: cmp    eax,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 50ULL);
x86_l_30b3:
	/* 0x30b3: jg     30d0 <generic_usdt_process_event+0x30d0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_30d0;
	}
x86_l_30b5:
	/* 0x30b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30b7:
	/* 0x30b7: je     30ee <generic_usdt_process_event+0x30ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12526ULL;
	}
x86_l_30b9:
	/* 0x30b9: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_30bc:
	/* 0x30bc: je     30ee <generic_usdt_process_event+0x30ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12526ULL;
	}
x86_l_30be:
	/* 0x30be: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_30c1:
	/* 0x30c1: jne    3114 <generic_usdt_process_event+0x3114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 12564ULL;
	}
x86_l_30c3:
	/* 0x30c3: mov    WORD PTR [r15+0x2],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934600ULL);
x86_l_30ca:
	/* 0x30ca: mov    ax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_30ce:
	/* 0x30ce: jmp    3119 <generic_usdt_process_event+0x3119> */
	return 12569ULL;
x86_l_30d0:
	/* 0x30d0: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_30d3:
	/* 0x30d3: je     3101 <generic_usdt_process_event+0x3101> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 12545ULL;
	}
	return 12501ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_7(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 12501ULL: goto x86_l_30d5;
	case 12504ULL: goto x86_l_30d8;
	case 12506ULL: goto x86_l_30da;
	case 12511ULL: goto x86_l_30df;
	case 12513ULL: goto x86_l_30e1;
	case 12520ULL: goto x86_l_30e8;
	case 12524ULL: goto x86_l_30ec;
	case 12526ULL: goto x86_l_30ee;
	case 12531ULL: goto x86_l_30f3;
	case 12538ULL: goto x86_l_30fa;
	case 12543ULL: goto x86_l_30ff;
	case 12545ULL: goto x86_l_3101;
	case 12550ULL: goto x86_l_3106;
	case 12557ULL: goto x86_l_310d;
	case 12562ULL: goto x86_l_3112;
	case 12564ULL: goto x86_l_3114;
	case 12569ULL: goto x86_l_3119;
	case 12573ULL: goto x86_l_311d;
	case 12577ULL: goto x86_l_3121;
	case 12582ULL: goto x86_l_3126;
	case 12586ULL: goto x86_l_312a;
	case 12592ULL: goto x86_l_3130;
	case 12602ULL: goto x86_l_313a;
	case 12606ULL: goto x86_l_313e;
	case 12612ULL: goto x86_l_3144;
	case 12616ULL: goto x86_l_3148;
	case 12619ULL: goto x86_l_314b;
	case 12624ULL: goto x86_l_3150;
	case 12627ULL: goto x86_l_3153;
	case 12632ULL: goto x86_l_3158;
	case 12637ULL: goto x86_l_315d;
	case 12642ULL: goto x86_l_3162;
	case 12646ULL: goto x86_l_3166;
	case 12649ULL: goto x86_l_3169;
	case 12654ULL: goto x86_l_316e;
	case 12656ULL: goto x86_l_3170;
	case 12658ULL: goto x86_l_3172;
	case 12666ULL: goto x86_l_317a;
	case 12670ULL: goto x86_l_317e;
	case 12675ULL: goto x86_l_3183;
	case 12680ULL: goto x86_l_3188;
	case 12687ULL: goto x86_l_318f;
	case 12691ULL: goto x86_l_3193;
	case 12696ULL: goto x86_l_3198;
	case 12701ULL: goto x86_l_319d;
	case 12704ULL: goto x86_l_31a0;
	case 12709ULL: goto x86_l_31a5;
	case 12711ULL: goto x86_l_31a7;
	case 12715ULL: goto x86_l_31ab;
	case 12719ULL: goto x86_l_31af;
	case 12724ULL: goto x86_l_31b4;
	case 12729ULL: goto x86_l_31b9;
	case 12734ULL: goto x86_l_31be;
	case 12737ULL: goto x86_l_31c1;
	case 12739ULL: goto x86_l_31c3;
	case 12743ULL: goto x86_l_31c7;
	case 12745ULL: goto x86_l_31c9;
	case 12749ULL: goto x86_l_31cd;
	case 12752ULL: goto x86_l_31d0;
	case 12758ULL: goto x86_l_31d6;
	case 12763ULL: goto x86_l_31db;
	case 12772ULL: goto x86_l_31e4;
	case 12776ULL: goto x86_l_31e8;
	case 12781ULL: goto x86_l_31ed;
	case 12785ULL: goto x86_l_31f1;
	case 12790ULL: goto x86_l_31f6;
	case 12795ULL: goto x86_l_31fb;
	case 12800ULL: goto x86_l_3200;
	case 12802ULL: goto x86_l_3202;
	case 12806ULL: goto x86_l_3206;
	case 12810ULL: goto x86_l_320a;
	case 12814ULL: goto x86_l_320e;
	case 12819ULL: goto x86_l_3213;
	case 12824ULL: goto x86_l_3218;
	case 12826ULL: goto x86_l_321a;
	case 12831ULL: goto x86_l_321f;
	case 12840ULL: goto x86_l_3228;
	case 12844ULL: goto x86_l_322c;
	case 12849ULL: goto x86_l_3231;
	case 12853ULL: goto x86_l_3235;
	case 12858ULL: goto x86_l_323a;
	case 12863ULL: goto x86_l_323f;
	case 12868ULL: goto x86_l_3244;
	case 12870ULL: goto x86_l_3246;
	case 12874ULL: goto x86_l_324a;
	case 12878ULL: goto x86_l_324e;
	case 12882ULL: goto x86_l_3252;
	case 12887ULL: goto x86_l_3257;
	case 12892ULL: goto x86_l_325c;
	case 12897ULL: goto x86_l_3261;
	case 12899ULL: goto x86_l_3263;
	case 12901ULL: goto x86_l_3265;
	case 12906ULL: goto x86_l_326a;
	case 12913ULL: goto x86_l_3271;
	case 12918ULL: goto x86_l_3276;
	case 12922ULL: goto x86_l_327a;
	case 12926ULL: goto x86_l_327e;
	case 12932ULL: goto x86_l_3284;
	case 12938ULL: goto x86_l_328a;
	case 12945ULL: goto x86_l_3291;
	case 12953ULL: goto x86_l_3299;
	case 12958ULL: goto x86_l_329e;
	case 12963ULL: goto x86_l_32a3;
	case 12969ULL: goto x86_l_32a9;
	case 12974ULL: goto x86_l_32ae;
	case 12977ULL: goto x86_l_32b1;
	case 12979ULL: goto x86_l_32b3;
	case 12987ULL: goto x86_l_32bb;
	case 12990ULL: goto x86_l_32be;
	case 12992ULL: goto x86_l_32c0;
	case 12996ULL: goto x86_l_32c4;
	case 13001ULL: goto x86_l_32c9;
	case 13006ULL: goto x86_l_32ce;
	case 13011ULL: goto x86_l_32d3;
	case 13019ULL: goto x86_l_32db;
	case 13023ULL: goto x86_l_32df;
	case 13028ULL: goto x86_l_32e4;
	case 13030ULL: goto x86_l_32e6;
	case 13038ULL: goto x86_l_32ee;
	case 13043ULL: goto x86_l_32f3;
	case 13047ULL: goto x86_l_32f7;
	case 13052ULL: goto x86_l_32fc;
	case 13056ULL: goto x86_l_3300;
	case 13061ULL: goto x86_l_3305;
	case 13066ULL: goto x86_l_330a;
	case 13068ULL: goto x86_l_330c;
	case 13072ULL: goto x86_l_3310;
	case 13076ULL: goto x86_l_3314;
	case 13080ULL: goto x86_l_3318;
	case 13085ULL: goto x86_l_331d;
	case 13088ULL: goto x86_l_3320;
	case 13093ULL: goto x86_l_3325;
	case 13095ULL: goto x86_l_3327;
	case 13101ULL: goto x86_l_332d;
	case 13106ULL: goto x86_l_3332;
	case 13111ULL: goto x86_l_3337;
	case 13116ULL: goto x86_l_333c;
	case 13121ULL: goto x86_l_3341;
	case 13129ULL: goto x86_l_3349;
	case 13134ULL: goto x86_l_334e;
	case 13142ULL: goto x86_l_3356;
	case 13147ULL: goto x86_l_335b;
	case 13152ULL: goto x86_l_3360;
	case 13155ULL: goto x86_l_3363;
	case 13157ULL: goto x86_l_3365;
	case 13159ULL: goto x86_l_3367;
	case 13160ULL: goto x86_l_3368;
	case 13161ULL: goto x86_l_3369;
	case 13164ULL: goto x86_l_336c;
	case 13167ULL: goto x86_l_336f;
	case 13174ULL: goto x86_l_3376;
	case 13176ULL: goto x86_l_3378;
	case 13180ULL: goto x86_l_337c;
	case 13184ULL: goto x86_l_3380;
	case 13187ULL: goto x86_l_3383;
	case 13190ULL: goto x86_l_3386;
	case 13192ULL: goto x86_l_3388;
	case 13199ULL: goto x86_l_338f;
	case 13201ULL: goto x86_l_3391;
	case 13203ULL: goto x86_l_3393;
	case 13207ULL: goto x86_l_3397;
	case 13209ULL: goto x86_l_3399;
	case 13214ULL: goto x86_l_339e;
	case 13219ULL: goto x86_l_33a3;
	case 13221ULL: goto x86_l_33a5;
	case 13226ULL: goto x86_l_33aa;
	case 13231ULL: goto x86_l_33af;
	case 13234ULL: goto x86_l_33b2;
	case 13238ULL: goto x86_l_33b6;
	case 13241ULL: goto x86_l_33b9;
	case 13246ULL: goto x86_l_33be;
	case 13248ULL: goto x86_l_33c0;
	case 13250ULL: goto x86_l_33c2;
	case 13255ULL: goto x86_l_33c7;
	case 13257ULL: goto x86_l_33c9;
	case 13259ULL: goto x86_l_33cb;
	case 13263ULL: goto x86_l_33cf;
	case 13265ULL: goto x86_l_33d1;
	case 13270ULL: goto x86_l_33d6;
	case 13274ULL: goto x86_l_33da;
	case 13275ULL: goto x86_l_33db;
	case 13277ULL: goto x86_l_33dd;
	case 13278ULL: goto x86_l_33de;
	case 13279ULL: goto x86_l_33df;
	case 13281ULL: goto x86_l_33e1;
	case 13283ULL: goto x86_l_33e3;
	case 13285ULL: goto x86_l_33e5;
	case 13287ULL: goto x86_l_33e7;
	case 13288ULL: goto x86_l_33e8;
	case 13292ULL: goto x86_l_33ec;
	case 13295ULL: goto x86_l_33ef;
	case 13299ULL: goto x86_l_33f3;
	case 13303ULL: goto x86_l_33f7;
	case 13307ULL: goto x86_l_33fb;
	case 13310ULL: goto x86_l_33fe;
	case 13312ULL: goto x86_l_3400;
	case 13316ULL: goto x86_l_3404;
	case 13322ULL: goto x86_l_340a;
	case 13326ULL: goto x86_l_340e;
	case 13331ULL: goto x86_l_3413;
	case 13336ULL: goto x86_l_3418;
	case 13341ULL: goto x86_l_341d;
	case 13346ULL: goto x86_l_3422;
	case 13348ULL: goto x86_l_3424;
	case 13353ULL: goto x86_l_3429;
	case 13359ULL: goto x86_l_342f;
	case 13364ULL: goto x86_l_3434;
	case 13369ULL: goto x86_l_3439;
	case 13374ULL: goto x86_l_343e;
	case 13379ULL: goto x86_l_3443;
	case 13384ULL: goto x86_l_3448;
	case 13387ULL: goto x86_l_344b;
	case 13389ULL: goto x86_l_344d;
	case 13394ULL: goto x86_l_3452;
	case 13400ULL: goto x86_l_3458;
	case 13405ULL: goto x86_l_345d;
	case 13410ULL: goto x86_l_3462;
	case 13415ULL: goto x86_l_3467;
	case 13420ULL: goto x86_l_346c;
	case 13423ULL: goto x86_l_346f;
	case 13425ULL: goto x86_l_3471;
	case 13429ULL: goto x86_l_3475;
	case 13434ULL: goto x86_l_347a;
	case 13439ULL: goto x86_l_347f;
	case 13444ULL: goto x86_l_3484;
	case 13449ULL: goto x86_l_3489;
	case 13452ULL: goto x86_l_348c;
	case 13454ULL: goto x86_l_348e;
	case 13458ULL: goto x86_l_3492;
	case 13462ULL: goto x86_l_3496;
	case 13466ULL: goto x86_l_349a;
	case 13469ULL: goto x86_l_349d;
	case 13473ULL: goto x86_l_34a1;
	case 13475ULL: goto x86_l_34a3;
	case 13477ULL: goto x86_l_34a5;
	case 13480ULL: goto x86_l_34a8;
	case 13483ULL: goto x86_l_34ab;
	case 13488ULL: goto x86_l_34b0;
	case 13490ULL: goto x86_l_34b2;
	case 13493ULL: goto x86_l_34b5;
	case 13497ULL: goto x86_l_34b9;
	case 13499ULL: goto x86_l_34bb;
	case 13503ULL: goto x86_l_34bf;
	case 13505ULL: goto x86_l_34c1;
	case 13508ULL: goto x86_l_34c4;
	case 13510ULL: goto x86_l_34c6;
	case 13513ULL: goto x86_l_34c9;
	case 13518ULL: goto x86_l_34ce;
	case 13521ULL: goto x86_l_34d1;
	case 13527ULL: goto x86_l_34d7;
	case 13534ULL: goto x86_l_34de;
	case 13540ULL: goto x86_l_34e4;
	case 13543ULL: goto x86_l_34e7;
	case 13545ULL: goto x86_l_34e9;
	case 13550ULL: goto x86_l_34ee;
	case 13552ULL: goto x86_l_34f0;
	case 13555ULL: goto x86_l_34f3;
	case 13559ULL: goto x86_l_34f7;
	case 13563ULL: goto x86_l_34fb;
	case 13566ULL: goto x86_l_34fe;
	case 13569ULL: goto x86_l_3501;
	case 13574ULL: goto x86_l_3506;
	case 13576ULL: goto x86_l_3508;
	case 13580ULL: goto x86_l_350c;
	case 13583ULL: goto x86_l_350f;
	case 13588ULL: goto x86_l_3514;
	case 13590ULL: goto x86_l_3516;
	case 13595ULL: goto x86_l_351b;
	case 13598ULL: goto x86_l_351e;
	case 13600ULL: goto x86_l_3520;
	case 13604ULL: goto x86_l_3524;
	case 13609ULL: goto x86_l_3529;
	case 13614ULL: goto x86_l_352e;
	case 13619ULL: goto x86_l_3533;
	case 13624ULL: goto x86_l_3538;
	case 13626ULL: goto x86_l_353a;
	case 13630ULL: goto x86_l_353e;
	case 13635ULL: goto x86_l_3543;
	case 13637ULL: goto x86_l_3545;
	case 13641ULL: goto x86_l_3549;
	case 13646ULL: goto x86_l_354e;
	case 13651ULL: goto x86_l_3553;
	case 13654ULL: goto x86_l_3556;
	case 13659ULL: goto x86_l_355b;
	case 13662ULL: goto x86_l_355e;
	case 13664ULL: goto x86_l_3560;
	case 13669ULL: goto x86_l_3565;
	case 13673ULL: goto x86_l_3569;
	case 13677ULL: goto x86_l_356d;
	case 13681ULL: goto x86_l_3571;
	case 13683ULL: goto x86_l_3573;
	case 13685ULL: goto x86_l_3575;
	case 13689ULL: goto x86_l_3579;
	case 13694ULL: goto x86_l_357e;
	case 13698ULL: goto x86_l_3582;
	case 13699ULL: goto x86_l_3583;
	case 13701ULL: goto x86_l_3585;
	case 13703ULL: goto x86_l_3587;
	case 13705ULL: goto x86_l_3589;
	case 13707ULL: goto x86_l_358b;
	case 13708ULL: goto x86_l_358c;
	case 13709ULL: goto x86_l_358d;
	case 13710ULL: goto x86_l_358e;
	case 13712ULL: goto x86_l_3590;
	case 13714ULL: goto x86_l_3592;
	case 13716ULL: goto x86_l_3594;
	case 13718ULL: goto x86_l_3596;
	case 13719ULL: goto x86_l_3597;
	case 13720ULL: goto x86_l_3598;
	case 13723ULL: goto x86_l_359b;
	case 13726ULL: goto x86_l_359e;
	case 13729ULL: goto x86_l_35a1;
	case 13732ULL: goto x86_l_35a4;
	case 13740ULL: goto x86_l_35ac;
	case 13747ULL: goto x86_l_35b3;
	case 13752ULL: goto x86_l_35b8;
	case 13757ULL: goto x86_l_35bd;
	case 13759ULL: goto x86_l_35bf;
	case 13762ULL: goto x86_l_35c2;
	case 13764ULL: goto x86_l_35c4;
	case 13767ULL: goto x86_l_35c7;
	case 13773ULL: goto x86_l_35cd;
	case 13778ULL: goto x86_l_35d2;
	case 13780ULL: goto x86_l_35d4;
	case 13783ULL: goto x86_l_35d7;
	case 13787ULL: goto x86_l_35db;
	case 13791ULL: goto x86_l_35df;
	case 13795ULL: goto x86_l_35e3;
	case 13797ULL: goto x86_l_35e5;
	case 13802ULL: goto x86_l_35ea;
	case 13806ULL: goto x86_l_35ee;
	case 13811ULL: goto x86_l_35f3;
	case 13813ULL: goto x86_l_35f5;
	case 13817ULL: goto x86_l_35f9;
	case 13821ULL: goto x86_l_35fd;
	case 13825ULL: goto x86_l_3601;
	case 13829ULL: goto x86_l_3605;
	case 13833ULL: goto x86_l_3609;
	case 13836ULL: goto x86_l_360c;
	case 13839ULL: goto x86_l_360f;
	case 13842ULL: goto x86_l_3612;
	case 13845ULL: goto x86_l_3615;
	case 13850ULL: goto x86_l_361a;
	case 13852ULL: goto x86_l_361c;
	case 13854ULL: goto x86_l_361e;
	case 13861ULL: goto x86_l_3625;
	case 13864ULL: goto x86_l_3628;
	case 13866ULL: goto x86_l_362a;
	case 13868ULL: goto x86_l_362c;
	case 13872ULL: goto x86_l_3630;
	case 13875ULL: goto x86_l_3633;
	case 13877ULL: goto x86_l_3635;
	case 13879ULL: goto x86_l_3637;
	case 13881ULL: goto x86_l_3639;
	case 13883ULL: goto x86_l_363b;
	case 13890ULL: goto x86_l_3642;
	case 13892ULL: goto x86_l_3644;
	case 13894ULL: goto x86_l_3646;
	case 13897ULL: goto x86_l_3649;
	case 13900ULL: goto x86_l_364c;
	case 13905ULL: goto x86_l_3651;
	case 13909ULL: goto x86_l_3655;
	case 13910ULL: goto x86_l_3656;
	case 13912ULL: goto x86_l_3658;
	case 13914ULL: goto x86_l_365a;
	case 13916ULL: goto x86_l_365c;
	case 13918ULL: goto x86_l_365e;
	case 13919ULL: goto x86_l_365f;
	case 13920ULL: goto x86_l_3660;
	case 13921ULL: goto x86_l_3661;
	case 13923ULL: goto x86_l_3663;
	case 13925ULL: goto x86_l_3665;
	case 13927ULL: goto x86_l_3667;
	case 13929ULL: goto x86_l_3669;
	case 13930ULL: goto x86_l_366a;
	case 13931ULL: goto x86_l_366b;
	case 13934ULL: goto x86_l_366e;
	case 13937ULL: goto x86_l_3671;
	case 13940ULL: goto x86_l_3674;
	case 13943ULL: goto x86_l_3677;
	case 13948ULL: goto x86_l_367c;
	case 13950ULL: goto x86_l_367e;
	case 13956ULL: goto x86_l_3684;
	case 13959ULL: goto x86_l_3687;
	default: return 0xffffffffffffffffULL;
	}
x86_l_30d5:
	/* 0x30d5: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_30d8:
	/* 0x30d8: je     30ee <generic_usdt_process_event+0x30ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_30ee;
	}
x86_l_30da:
	/* 0x30da: cmp    eax,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 255ULL);
x86_l_30df:
	/* 0x30df: jne    3114 <generic_usdt_process_event+0x3114> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3114;
	}
x86_l_30e1:
	/* 0x30e1: mov    WORD PTR [r15+0x2],0x28 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934632ULL);
x86_l_30e8:
	/* 0x30e8: mov    ax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 40ULL);
x86_l_30ec:
	/* 0x30ec: jmp    3119 <generic_usdt_process_event+0x3119> */
	goto x86_l_3119;
x86_l_30ee:
	/* 0x30ee: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_30f3:
	/* 0x30f3: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_30fa:
	/* 0x30fa: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_30ff:
	/* 0x30ff: jmp    3119 <generic_usdt_process_event+0x3119> */
	goto x86_l_3119;
x86_l_3101:
	/* 0x3101: movzx  eax,BYTE PTR [r15+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_3106:
	/* 0x3106: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_310d:
	/* 0x310d: mov    WORD PTR [r15+0x2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_3112:
	/* 0x3112: jmp    3119 <generic_usdt_process_event+0x3119> */
	goto x86_l_3119;
x86_l_3114:
	/* 0x3114: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3119:
	/* 0x3119: add    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_311d:
	/* 0x311d: mov    WORD PTR [r15],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3121:
	/* 0x3121: movzx  ebp,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3126:
	/* 0x3126: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_312a:
	/* 0x312a: ja     334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_334e;
	}
x86_l_3130:
	/* 0x3130: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_313a:
	/* 0x313a: bt     rcx,rbp */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_313e:
	/* 0x313e: jae    334e <generic_usdt_process_event+0x334e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_334e;
	}
x86_l_3144:
	/* 0x3144: mov    BYTE PTR [r15+0x5],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_3148:
	/* 0x3148: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_314b:
	/* 0x314b: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3150:
	/* 0x3150: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3153:
	/* 0x3153: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_3158:
	/* 0x3158: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_315d:
	/* 0x315d: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3162:
	/* 0x3162: movzx  edx,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3166:
	/* 0x3166: add    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3169:
	/* 0x3169: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_316e:
	/* 0x316e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3170:
	/* 0x3170: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3172:
	/* 0x3172: mov    BYTE PTR [rsp+0xac],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_317a:
	/* 0x317a: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_317e:
	/* 0x317e: mov    r15,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3183:
	/* 0x3183: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3188:
	/* 0x3188: mov    WORD PTR [r15+0x26],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757258ULL);
x86_l_318f:
	/* 0x318f: lea    rdx,[r13+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3193:
	/* 0x3193: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3198:
	/* 0x3198: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_319d:
	/* 0x319d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_31a0:
	/* 0x31a0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31a5:
	/* 0x31a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31a7:
	/* 0x31a7: lea    rdi,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31ab:
	/* 0x31ab: add    r13,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_31af:
	/* 0x31af: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_31b4:
	/* 0x31b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31b9:
	/* 0x31b9: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_31be:
	/* 0x31be: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_31c1:
	/* 0x31c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31c3:
	/* 0x31c3: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_31c7:
	/* 0x31c7: je     321a <generic_usdt_process_event+0x321a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_321a;
	}
x86_l_31c9:
	/* 0x31c9: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_31cd:
	/* 0x31cd: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_31d0:
	/* 0x31d0: jne    3265 <generic_usdt_process_event+0x3265> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3265;
	}
x86_l_31d6:
	/* 0x31d6: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31db:
	/* 0x31db: movzx  r13d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_31e4:
	/* 0x31e4: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_31e8:
	/* 0x31e8: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31ed:
	/* 0x31ed: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_31f1:
	/* 0x31f1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_31f6:
	/* 0x31f6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_31fb:
	/* 0x31fb: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3200:
	/* 0x3200: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3202:
	/* 0x3202: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3206:
	/* 0x3206: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_320a:
	/* 0x320a: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_320e:
	/* 0x320e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3213:
	/* 0x3213: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3218:
	/* 0x3218: jmp    325c <generic_usdt_process_event+0x325c> */
	goto x86_l_325c;
x86_l_321a:
	/* 0x321a: mov    r15,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_321f:
	/* 0x321f: movzx  r13d,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_3228:
	/* 0x3228: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_322c:
	/* 0x322c: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3231:
	/* 0x3231: lea    rdi,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3235:
	/* 0x3235: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_323a:
	/* 0x323a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_323f:
	/* 0x323f: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3244:
	/* 0x3244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3246:
	/* 0x3246: lea    rdi,[rbp+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_324a:
	/* 0x324a: lea    rdx,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_324e:
	/* 0x324e: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_3252:
	/* 0x3252: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3257:
	/* 0x3257: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_325c:
	/* 0x325c: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_3261:
	/* 0x3261: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3263:
	/* 0x3263: jmp    3271 <generic_usdt_process_event+0x3271> */
	goto x86_l_3271;
x86_l_3265:
	/* 0x3265: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_326a:
	/* 0x326a: mov    DWORD PTR [rax+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3271:
	/* 0x3271: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3276:
	/* 0x3276: movzx  eax,WORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_327a:
	/* 0x327a: movzx  ecx,WORD PTR [rdx+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_327e:
	/* 0x327e: movbe  WORD PTR [rdx+0x20],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3284:
	/* 0x3284: movbe  WORD PTR [rdx+0x22],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RDX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_328a:
	/* 0x328a: add    r12,0xe0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 224ULL);
x86_l_3291:
	/* 0x3291: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_3299:
	/* 0x3299: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_329e:
	/* 0x329e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32a3:
	/* 0x32a3: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_32a9:
	/* 0x32a9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32ae:
	/* 0x32ae: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_32b1:
	/* 0x32b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32b3:
	/* 0x32b3: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_32bb:
	/* 0x32bb: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_32be:
	/* 0x32be: je     3327 <generic_usdt_process_event+0x3327> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3327;
	}
x86_l_32c0:
	/* 0x32c0: add    rcx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_32c4:
	/* 0x32c4: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32c9:
	/* 0x32c9: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_32ce:
	/* 0x32ce: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_32d3:
	/* 0x32d3: mov    rdx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_32db:
	/* 0x32db: add    rdx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 5ULL);
x86_l_32df:
	/* 0x32df: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_32e4:
	/* 0x32e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32e6:
	/* 0x32e6: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_32ee:
	/* 0x32ee: mov    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_32f3:
	/* 0x32f3: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_32f7:
	/* 0x32f7: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32fc:
	/* 0x32fc: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3300:
	/* 0x3300: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3305:
	/* 0x3305: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_330a:
	/* 0x330a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_330c:
	/* 0x330c: add    rbp,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 60ULL);
x86_l_3310:
	/* 0x3310: lea    rdx,[r12+r13*8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 3), 0ULL);
x86_l_3314:
	/* 0x3314: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3318:
	/* 0x3318: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_331d:
	/* 0x331d: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_3320:
	/* 0x3320: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_3325:
	/* 0x3325: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3327:
	/* 0x3327: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_332d:
	/* 0x332d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3332:
	/* 0x3332: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3337:
	/* 0x3337: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_333c:
	/* 0x333c: mov    rbx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3341:
	/* 0x3341: mov    r12,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_3349:
	/* 0x3349: jmp    d53 <generic_usdt_process_event+0xd53> */
	return 3411ULL;
x86_l_334e:
	/* 0x334e: mov    WORD PTR [rsp+0xc8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_3356:
	/* 0x3356: jmp    3172 <generic_usdt_process_event+0x3172> */
	goto x86_l_3172;
x86_l_335b:
	/* 0x335b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3360:
	/* 0x3360: cmp    edi,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 9ULL);
x86_l_3363:
	/* 0x3363: ja     33dd <extract_arg_depth+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_33dd;
	}
x86_l_3365:
	/* 0x3365: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3367:
	/* 0x3367: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3368:
	/* 0x3368: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3369:
	/* 0x3369: mov    r8,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_336c:
	/* 0x336c: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_336f:
	/* 0x336f: cmp    WORD PTR [r8+r9*8+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 25769803776ULL);
x86_l_3376:
	/* 0x3376: je     33d6 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d6;
	}
x86_l_3378:
	/* 0x3378: mov    rcx,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_337c:
	/* 0x337c: mov    edx,DWORD PTR [r8+r9*8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 3), 0ULL);
x86_l_3380:
	/* 0x3380: add    rdx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_3383:
	/* 0x3383: mov    QWORD PTR [rcx],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3386:
	/* 0x3386: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3388:
	/* 0x3388: cmp    WORD PTR [r8+r9*8+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_R9, 3), 17179869184ULL);
x86_l_338f:
	/* 0x338f: je     33d6 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33d6;
	}
x86_l_3391:
	/* 0x3391: mov    ebx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_32);
x86_l_3393:
	/* 0x3393: cmp    BYTE PTR [rsi+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3397:
	/* 0x3397: je     33a5 <extract_arg_depth+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_33a5;
	}
x86_l_3399:
	/* 0x3399: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_339e:
	/* 0x339e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_33a3:
	/* 0x33a3: jmp    33af <extract_arg_depth+0x54> */
	goto x86_l_33af;
x86_l_33a5:
	/* 0x33a5: mov    edi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 8ULL);
x86_l_33aa:
	/* 0x33aa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_33af:
	/* 0x33af: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_33b2:
	/* 0x33b2: mov    rdi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_33b6:
	/* 0x33b6: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33b9:
	/* 0x33b9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_33be:
	/* 0x33be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_33c0:
	/* 0x33c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_33c2:
	/* 0x33c2: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_33c7:
	/* 0x33c7: jns    33d6 <extract_arg_depth+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_33d6;
	}
x86_l_33c9:
	/* 0x33c9: inc    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_33cb:
	/* 0x33cb: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33cf:
	/* 0x33cf: mov    DWORD PTR [rax],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33d1:
	/* 0x33d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33d6:
	/* 0x33d6: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_33da:
	/* 0x33da: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_33db:
	/* 0x33db: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_33dd:
	/* 0x33dd: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_33de:
	/* 0x33de: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_33df:
	/* 0x33df: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_33e1:
	/* 0x33e1: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_33e3:
	/* 0x33e3: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_33e5:
	/* 0x33e5: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_33e7:
	/* 0x33e7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_33e8:
	/* 0x33e8: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_33ec:
	/* 0x33ec: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_33ef:
	/* 0x33ef: mov    r12,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33f3:
	/* 0x33f3: mov    rdx,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_33f7:
	/* 0x33f7: mov    r15,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33fb:
	/* 0x33fb: cmp    r12,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_33fe:
	/* 0x33fe: jne    340a <cwd_read_v61+0x2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_340a;
	}
x86_l_3400:
	/* 0x3400: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3404:
	/* 0x3404: je     3575 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3575;
	}
x86_l_340a:
	/* 0x340a: lea    r14,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_340e:
	/* 0x340e: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3413:
	/* 0x3413: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3418:
	/* 0x3418: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_341d:
	/* 0x341d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3422:
	/* 0x3422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3424:
	/* 0x3424: cmp    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_3429:
	/* 0x3429: je     3520 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3520;
	}
x86_l_342f:
	/* 0x342f: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3434:
	/* 0x3434: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3439:
	/* 0x3439: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_343e:
	/* 0x343e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3443:
	/* 0x3443: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3448:
	/* 0x3448: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_344b:
	/* 0x344b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_344d:
	/* 0x344d: cmp    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3452:
	/* 0x3452: je     3520 <cwd_read_v61+0x142> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3520;
	}
x86_l_3458:
	/* 0x3458: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_345d:
	/* 0x345d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3462:
	/* 0x3462: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3467:
	/* 0x3467: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_346c:
	/* 0x346c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_346f:
	/* 0x346f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3471:
	/* 0x3471: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_3475:
	/* 0x3475: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_347a:
	/* 0x347a: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_347f:
	/* 0x347f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3484:
	/* 0x3484: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_3489:
	/* 0x3489: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_348c:
	/* 0x348c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_348e:
	/* 0x348e: mov    r15,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3492:
	/* 0x3492: mov    rcx,QWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3496:
	/* 0x3496: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_349a:
	/* 0x349a: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_349d:
	/* 0x349d: mov    r12d,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34a1:
	/* 0x34a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34a3:
	/* 0x34a3: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_34a5:
	/* 0x34a5: sub    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34a8:
	/* 0x34a8: cmovb  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_34ab:
	/* 0x34ab: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_34b0:
	/* 0x34b0: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34b2:
	/* 0x34b2: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34b5:
	/* 0x34b5: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_34b9:
	/* 0x34b9: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_34bb:
	/* 0x34bb: cmovb  esi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_34bf:
	/* 0x34bf: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34c1:
	/* 0x34c1: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_34c4:
	/* 0x34c4: sub    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_34c6:
	/* 0x34c6: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_34c9:
	/* 0x34c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_34ce:
	/* 0x34ce: sub    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_34d1:
	/* 0x34d1: jb     357e <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_357e;
	}
x86_l_34d7:
	/* 0x34d7: cmp    rcx,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 4095ULL);
x86_l_34de:
	/* 0x34de: ja     357e <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_357e;
	}
x86_l_34e4:
	/* 0x34e4: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34e7:
	/* 0x34e7: jbe    34ee <cwd_read_v61+0x110> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_34ee;
	}
x86_l_34e9:
	/* 0x34e9: mov    BYTE PTR [r15+rcx*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RCX, 0), 47ULL);
x86_l_34ee:
	/* 0x34ee: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34f0:
	/* 0x34f0: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_34f3:
	/* 0x34f3: seta   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_A);
x86_l_34f7:
	/* 0x34f7: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_34fb:
	/* 0x34fb: add    r15,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34fe:
	/* 0x34fe: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3501:
	/* 0x3501: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3506:
	/* 0x3506: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3508:
	/* 0x3508: mov    QWORD PTR [rbx+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_350c:
	/* 0x350c: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_350f:
	/* 0x350f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3514:
	/* 0x3514: jbe    357e <cwd_read_v61+0x1a0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_357e;
	}
x86_l_3516:
	/* 0x3516: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_351b:
	/* 0x351b: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_351e:
	/* 0x351e: jmp    3571 <cwd_read_v61+0x193> */
	goto x86_l_3571;
x86_l_3520:
	/* 0x3520: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3524:
	/* 0x3524: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3529:
	/* 0x3529: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_352e:
	/* 0x352e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3533:
	/* 0x3533: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3538:
	/* 0x3538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_353a:
	/* 0x353a: mov    rax,QWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_353e:
	/* 0x353e: cmp    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_3543:
	/* 0x3543: je     3575 <cwd_read_v61+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3575;
	}
x86_l_3545:
	/* 0x3545: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_3549:
	/* 0x3549: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_354e:
	/* 0x354e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_3553:
	/* 0x3553: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3556:
	/* 0x3556: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_355b:
	/* 0x355b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_355e:
	/* 0x355e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3560:
	/* 0x3560: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3565:
	/* 0x3565: mov    QWORD PTR [rbx+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3569:
	/* 0x3569: add    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_356d:
	/* 0x356d: mov    QWORD PTR [rbx+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3571:
	/* 0x3571: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3573:
	/* 0x3573: jmp    357e <cwd_read_v61+0x1a0> */
	goto x86_l_357e;
x86_l_3575:
	/* 0x3575: mov    BYTE PTR [rbx+0x3c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_3579:
	/* 0x3579: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_357e:
	/* 0x357e: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3582:
	/* 0x3582: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3583:
	/* 0x3583: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3585:
	/* 0x3585: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_3587:
	/* 0x3587: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3589:
	/* 0x3589: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_358b:
	/* 0x358b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_358c:
	/* 0x358c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_358d:
	/* 0x358d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_358e:
	/* 0x358e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3590:
	/* 0x3590: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3592:
	/* 0x3592: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3594:
	/* 0x3594: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3596:
	/* 0x3596: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_3597:
	/* 0x3597: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_3598:
	/* 0x3598: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_359b:
	/* 0x359b: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_359e:
	/* 0x359e: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_35a1:
	/* 0x35a1: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_35a4:
	/* 0x35a4: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_35ac:
	/* 0x35ac: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_35b3:
	/* 0x35b3: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35b8:
	/* 0x35b8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35bd:
	/* 0x35bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35bf:
	/* 0x35bf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35c2:
	/* 0x35c2: je     3635 <data_event_bytes+0xa8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3635;
	}
x86_l_35c4:
	/* 0x35c4: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_35c7:
	/* 0x35c7: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35cd:
	/* 0x35cd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_35d2:
	/* 0x35d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35d4:
	/* 0x35d4: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_35d7:
	/* 0x35d7: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_35db:
	/* 0x35db: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_35df:
	/* 0x35df: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_35e3:
	/* 0x35e3: jne    35ee <data_event_bytes+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_35ee;
	}
x86_l_35e5:
	/* 0x35e5: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_35ea:
	/* 0x35ea: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35ee:
	/* 0x35ee: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_35f3:
	/* 0x35f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35f5:
	/* 0x35f5: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35f9:
	/* 0x35f9: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35fd:
	/* 0x35fd: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3601:
	/* 0x3601: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3605:
	/* 0x3605: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3609:
	/* 0x3609: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_360c:
	/* 0x360c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_360f:
	/* 0x360f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3612:
	/* 0x3612: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3615:
	/* 0x3615: call   3660 <do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13850ULL);
	__x86_sim_call_depth++;
	goto x86_l_3660;
x86_l_361a:
	/* 0x361a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_361c:
	/* 0x361c: js     3639 <data_event_bytes+0xac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3639;
	}
x86_l_361e:
	/* 0x361e: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3625:
	/* 0x3625: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_3628:
	/* 0x3628: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_362a:
	/* 0x362a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_362c:
	/* 0x362c: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3630:
	/* 0x3630: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_3633:
	/* 0x3633: jmp    3646 <data_event_bytes+0xb9> */
	goto x86_l_3646;
x86_l_3635:
	/* 0x3635: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3637:
	/* 0x3637: jmp    3651 <data_event_bytes+0xc4> */
	goto x86_l_3651;
x86_l_3639:
	/* 0x3639: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_363b:
	/* 0x363b: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3642:
	/* 0x3642: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3644:
	/* 0x3644: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3646:
	/* 0x3646: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3649:
	/* 0x3649: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_364c:
	/* 0x364c: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_3651:
	/* 0x3651: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3655:
	/* 0x3655: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3656:
	/* 0x3656: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3658:
	/* 0x3658: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_365a:
	/* 0x365a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_365c:
	/* 0x365c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_365e:
	/* 0x365e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_365f:
	/* 0x365f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3660:
	/* 0x3660: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_3661:
	/* 0x3661: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_3663:
	/* 0x3663: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_3665:
	/* 0x3665: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_3667:
	/* 0x3667: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3669:
	/* 0x3669: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_366a:
	/* 0x366a: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_366b:
	/* 0x366b: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_366e:
	/* 0x366e: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_3671:
	/* 0x3671: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_3674:
	/* 0x3674: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_3677:
	/* 0x3677: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13948ULL);
	__x86_sim_call_depth++;
	return 14528ULL;
x86_l_367c:
	/* 0x367c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_367e:
	/* 0x367e: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 14375ULL;
	}
x86_l_3684:
	/* 0x3684: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_3687:
	/* 0x3687: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
	return 13966ULL;
}

static __noinline __u64 tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_8(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 13966ULL: goto x86_l_368e;
	case 13969ULL: goto x86_l_3691;
	case 13972ULL: goto x86_l_3694;
	case 13978ULL: goto x86_l_369a;
	case 13982ULL: goto x86_l_369e;
	case 13985ULL: goto x86_l_36a1;
	case 13988ULL: goto x86_l_36a4;
	case 13993ULL: goto x86_l_36a9;
	case 13995ULL: goto x86_l_36ab;
	case 14001ULL: goto x86_l_36b1;
	case 14006ULL: goto x86_l_36b6;
	case 14009ULL: goto x86_l_36b9;
	case 14012ULL: goto x86_l_36bc;
	case 14015ULL: goto x86_l_36bf;
	case 14018ULL: goto x86_l_36c2;
	case 14024ULL: goto x86_l_36c8;
	case 14028ULL: goto x86_l_36cc;
	case 14031ULL: goto x86_l_36cf;
	case 14034ULL: goto x86_l_36d2;
	case 14039ULL: goto x86_l_36d7;
	case 14041ULL: goto x86_l_36d9;
	case 14047ULL: goto x86_l_36df;
	case 14052ULL: goto x86_l_36e4;
	case 14055ULL: goto x86_l_36e7;
	case 14058ULL: goto x86_l_36ea;
	case 14061ULL: goto x86_l_36ed;
	case 14064ULL: goto x86_l_36f0;
	case 14070ULL: goto x86_l_36f6;
	case 14074ULL: goto x86_l_36fa;
	case 14077ULL: goto x86_l_36fd;
	case 14080ULL: goto x86_l_3700;
	case 14085ULL: goto x86_l_3705;
	case 14087ULL: goto x86_l_3707;
	case 14093ULL: goto x86_l_370d;
	case 14098ULL: goto x86_l_3712;
	case 14101ULL: goto x86_l_3715;
	case 14104ULL: goto x86_l_3718;
	case 14107ULL: goto x86_l_371b;
	case 14110ULL: goto x86_l_371e;
	case 14116ULL: goto x86_l_3724;
	case 14120ULL: goto x86_l_3728;
	case 14123ULL: goto x86_l_372b;
	case 14126ULL: goto x86_l_372e;
	case 14131ULL: goto x86_l_3733;
	case 14133ULL: goto x86_l_3735;
	case 14139ULL: goto x86_l_373b;
	case 14144ULL: goto x86_l_3740;
	case 14147ULL: goto x86_l_3743;
	case 14150ULL: goto x86_l_3746;
	case 14153ULL: goto x86_l_3749;
	case 14156ULL: goto x86_l_374c;
	case 14162ULL: goto x86_l_3752;
	case 14166ULL: goto x86_l_3756;
	case 14169ULL: goto x86_l_3759;
	case 14172ULL: goto x86_l_375c;
	case 14177ULL: goto x86_l_3761;
	case 14179ULL: goto x86_l_3763;
	case 14185ULL: goto x86_l_3769;
	case 14190ULL: goto x86_l_376e;
	case 14193ULL: goto x86_l_3771;
	case 14196ULL: goto x86_l_3774;
	case 14199ULL: goto x86_l_3777;
	case 14202ULL: goto x86_l_377a;
	case 14208ULL: goto x86_l_3780;
	case 14212ULL: goto x86_l_3784;
	case 14215ULL: goto x86_l_3787;
	case 14218ULL: goto x86_l_378a;
	case 14223ULL: goto x86_l_378f;
	case 14225ULL: goto x86_l_3791;
	case 14231ULL: goto x86_l_3797;
	case 14236ULL: goto x86_l_379c;
	case 14239ULL: goto x86_l_379f;
	case 14242ULL: goto x86_l_37a2;
	case 14245ULL: goto x86_l_37a5;
	case 14248ULL: goto x86_l_37a8;
	case 14254ULL: goto x86_l_37ae;
	case 14258ULL: goto x86_l_37b2;
	case 14261ULL: goto x86_l_37b5;
	case 14264ULL: goto x86_l_37b8;
	case 14269ULL: goto x86_l_37bd;
	case 14271ULL: goto x86_l_37bf;
	case 14273ULL: goto x86_l_37c1;
	case 14278ULL: goto x86_l_37c6;
	case 14281ULL: goto x86_l_37c9;
	case 14284ULL: goto x86_l_37cc;
	case 14287ULL: goto x86_l_37cf;
	case 14290ULL: goto x86_l_37d2;
	case 14296ULL: goto x86_l_37d8;
	case 14300ULL: goto x86_l_37dc;
	case 14303ULL: goto x86_l_37df;
	case 14306ULL: goto x86_l_37e2;
	case 14311ULL: goto x86_l_37e7;
	case 14313ULL: goto x86_l_37e9;
	case 14315ULL: goto x86_l_37eb;
	case 14320ULL: goto x86_l_37f0;
	case 14323ULL: goto x86_l_37f3;
	case 14326ULL: goto x86_l_37f6;
	case 14329ULL: goto x86_l_37f9;
	case 14332ULL: goto x86_l_37fc;
	case 14338ULL: goto x86_l_3802;
	case 14341ULL: goto x86_l_3805;
	case 14344ULL: goto x86_l_3808;
	case 14347ULL: goto x86_l_380b;
	case 14350ULL: goto x86_l_380e;
	case 14355ULL: goto x86_l_3813;
	case 14357ULL: goto x86_l_3815;
	case 14359ULL: goto x86_l_3817;
	case 14364ULL: goto x86_l_381c;
	case 14367ULL: goto x86_l_381f;
	case 14370ULL: goto x86_l_3822;
	case 14375ULL: goto x86_l_3827;
	case 14378ULL: goto x86_l_382a;
	case 14386ULL: goto x86_l_3832;
	case 14393ULL: goto x86_l_3839;
	case 14398ULL: goto x86_l_383e;
	case 14403ULL: goto x86_l_3843;
	case 14405ULL: goto x86_l_3845;
	case 14408ULL: goto x86_l_3848;
	case 14410ULL: goto x86_l_384a;
	case 14414ULL: goto x86_l_384e;
	case 14416ULL: goto x86_l_3850;
	case 14420ULL: goto x86_l_3854;
	case 14422ULL: goto x86_l_3856;
	case 14426ULL: goto x86_l_385a;
	case 14428ULL: goto x86_l_385c;
	case 14432ULL: goto x86_l_3860;
	case 14434ULL: goto x86_l_3862;
	case 14440ULL: goto x86_l_3868;
	case 14442ULL: goto x86_l_386a;
	case 14446ULL: goto x86_l_386e;
	case 14448ULL: goto x86_l_3870;
	case 14452ULL: goto x86_l_3874;
	case 14454ULL: goto x86_l_3876;
	case 14458ULL: goto x86_l_387a;
	case 14460ULL: goto x86_l_387c;
	case 14466ULL: goto x86_l_3882;
	case 14468ULL: goto x86_l_3884;
	case 14474ULL: goto x86_l_388a;
	case 14476ULL: goto x86_l_388c;
	case 14482ULL: goto x86_l_3892;
	case 14484ULL: goto x86_l_3894;
	case 14490ULL: goto x86_l_389a;
	case 14492ULL: goto x86_l_389c;
	case 14498ULL: goto x86_l_38a2;
	case 14500ULL: goto x86_l_38a4;
	case 14506ULL: goto x86_l_38aa;
	case 14510ULL: goto x86_l_38ae;
	case 14513ULL: goto x86_l_38b1;
	case 14517ULL: goto x86_l_38b5;
	case 14518ULL: goto x86_l_38b6;
	case 14520ULL: goto x86_l_38b8;
	case 14522ULL: goto x86_l_38ba;
	case 14524ULL: goto x86_l_38bc;
	case 14526ULL: goto x86_l_38be;
	case 14527ULL: goto x86_l_38bf;
	case 14528ULL: goto x86_l_38c0;
	case 14530ULL: goto x86_l_38c2;
	case 14532ULL: goto x86_l_38c4;
	case 14534ULL: goto x86_l_38c6;
	case 14535ULL: goto x86_l_38c7;
	case 14536ULL: goto x86_l_38c8;
	case 14539ULL: goto x86_l_38cb;
	case 14545ULL: goto x86_l_38d1;
	case 14548ULL: goto x86_l_38d4;
	case 14551ULL: goto x86_l_38d7;
	case 14558ULL: goto x86_l_38de;
	case 14563ULL: goto x86_l_38e3;
	case 14567ULL: goto x86_l_38e7;
	case 14571ULL: goto x86_l_38eb;
	case 14576ULL: goto x86_l_38f0;
	case 14578ULL: goto x86_l_38f2;
	case 14580ULL: goto x86_l_38f4;
	case 14582ULL: goto x86_l_38f6;
	case 14584ULL: goto x86_l_38f8;
	case 14588ULL: goto x86_l_38fc;
	case 14592ULL: goto x86_l_3900;
	case 14600ULL: goto x86_l_3908;
	case 14607ULL: goto x86_l_390f;
	case 14612ULL: goto x86_l_3914;
	case 14617ULL: goto x86_l_3919;
	case 14619ULL: goto x86_l_391b;
	case 14622ULL: goto x86_l_391e;
	case 14624ULL: goto x86_l_3920;
	case 14628ULL: goto x86_l_3924;
	case 14630ULL: goto x86_l_3926;
	case 14637ULL: goto x86_l_392d;
	case 14642ULL: goto x86_l_3932;
	case 14647ULL: goto x86_l_3937;
	case 14650ULL: goto x86_l_393a;
	case 14655ULL: goto x86_l_393f;
	case 14658ULL: goto x86_l_3942;
	case 14661ULL: goto x86_l_3945;
	case 14663ULL: goto x86_l_3947;
	case 14665ULL: goto x86_l_3949;
	case 14667ULL: goto x86_l_394b;
	case 14669ULL: goto x86_l_394d;
	case 14676ULL: goto x86_l_3954;
	case 14678ULL: goto x86_l_3956;
	case 14685ULL: goto x86_l_395d;
	case 14687ULL: goto x86_l_395f;
	case 14692ULL: goto x86_l_3964;
	case 14695ULL: goto x86_l_3967;
	case 14698ULL: goto x86_l_396a;
	case 14700ULL: goto x86_l_396c;
	case 14702ULL: goto x86_l_396e;
	case 14704ULL: goto x86_l_3970;
	case 14706ULL: goto x86_l_3972;
	case 14709ULL: goto x86_l_3975;
	case 14712ULL: goto x86_l_3978;
	case 14716ULL: goto x86_l_397c;
	case 14717ULL: goto x86_l_397d;
	case 14719ULL: goto x86_l_397f;
	case 14721ULL: goto x86_l_3981;
	case 14723ULL: goto x86_l_3983;
	default: return 0xffffffffffffffffULL;
	}
x86_l_368e:
	/* 0x368e: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3691:
	/* 0x3691: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_3694:
	/* 0x3694: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_369a:
	/* 0x369a: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_369e:
	/* 0x369e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36a1:
	/* 0x36a1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_36a4:
	/* 0x36a4: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 13993ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_36a9:
	/* 0x36a9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36ab:
	/* 0x36ab: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_36b1:
	/* 0x36b1: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_36b6:
	/* 0x36b6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_36b9:
	/* 0x36b9: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36bc:
	/* 0x36bc: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_36bf:
	/* 0x36bf: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36c2:
	/* 0x36c2: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_36c8:
	/* 0x36c8: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_36cc:
	/* 0x36cc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36cf:
	/* 0x36cf: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_36d2:
	/* 0x36d2: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14039ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_36d7:
	/* 0x36d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36d9:
	/* 0x36d9: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_36df:
	/* 0x36df: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_36e4:
	/* 0x36e4: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_36e7:
	/* 0x36e7: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_36ea:
	/* 0x36ea: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_36ed:
	/* 0x36ed: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_36f0:
	/* 0x36f0: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_36f6:
	/* 0x36f6: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_36fa:
	/* 0x36fa: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_36fd:
	/* 0x36fd: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3700:
	/* 0x3700: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14085ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_3705:
	/* 0x3705: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3707:
	/* 0x3707: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_370d:
	/* 0x370d: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3712:
	/* 0x3712: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3715:
	/* 0x3715: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3718:
	/* 0x3718: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_371b:
	/* 0x371b: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_371e:
	/* 0x371e: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_3724:
	/* 0x3724: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3728:
	/* 0x3728: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_372b:
	/* 0x372b: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_372e:
	/* 0x372e: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14131ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_3733:
	/* 0x3733: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3735:
	/* 0x3735: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_373b:
	/* 0x373b: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_3740:
	/* 0x3740: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3743:
	/* 0x3743: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3746:
	/* 0x3746: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3749:
	/* 0x3749: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_374c:
	/* 0x374c: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_3752:
	/* 0x3752: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3756:
	/* 0x3756: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3759:
	/* 0x3759: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_375c:
	/* 0x375c: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14177ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_3761:
	/* 0x3761: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3763:
	/* 0x3763: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_3769:
	/* 0x3769: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_376e:
	/* 0x376e: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_3771:
	/* 0x3771: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3774:
	/* 0x3774: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_3777:
	/* 0x3777: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_377a:
	/* 0x377a: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_3780:
	/* 0x3780: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3784:
	/* 0x3784: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3787:
	/* 0x3787: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_378a:
	/* 0x378a: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14223ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_378f:
	/* 0x378f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3791:
	/* 0x3791: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_3797:
	/* 0x3797: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_379c:
	/* 0x379c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_379f:
	/* 0x379f: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37a2:
	/* 0x37a2: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37a5:
	/* 0x37a5: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37a8:
	/* 0x37a8: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_37ae:
	/* 0x37ae: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_37b2:
	/* 0x37b2: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37b5:
	/* 0x37b5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_37b8:
	/* 0x37b8: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14269ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_37bd:
	/* 0x37bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37bf:
	/* 0x37bf: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_37c1:
	/* 0x37c1: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37c6:
	/* 0x37c6: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_37c9:
	/* 0x37c9: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37cc:
	/* 0x37cc: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37cf:
	/* 0x37cf: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37d2:
	/* 0x37d2: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_37d8:
	/* 0x37d8: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_37dc:
	/* 0x37dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37df:
	/* 0x37df: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_37e2:
	/* 0x37e2: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14311ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_37e7:
	/* 0x37e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37e9:
	/* 0x37e9: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_37eb:
	/* 0x37eb: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_37f0:
	/* 0x37f0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_37f3:
	/* 0x37f3: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_37f6:
	/* 0x37f6: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_37f9:
	/* 0x37f9: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_37fc:
	/* 0x37fc: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_3802:
	/* 0x3802: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3805:
	/* 0x3805: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3808:
	/* 0x3808: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_380b:
	/* 0x380b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_380e:
	/* 0x380e: call   38c0 <__do_bytes> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 14355ULL);
	__x86_sim_call_depth++;
	goto x86_l_38c0;
x86_l_3813:
	/* 0x3813: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3815:
	/* 0x3815: js     3827 <do_bytes+0x1c7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3827;
	}
x86_l_3817:
	/* 0x3817: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_381c:
	/* 0x381c: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_381f:
	/* 0x381f: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3822:
	/* 0x3822: jmp    38ae <do_bytes+0x24e> */
	goto x86_l_38ae;
x86_l_3827:
	/* 0x3827: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_382a:
	/* 0x382a: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3832:
	/* 0x3832: mov    rdi,QWORD PTR [rip+0x320] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3839:
	/* 0x3839: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_383e:
	/* 0x383e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3843:
	/* 0x3843: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3845:
	/* 0x3845: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3848:
	/* 0x3848: je     38ae <do_bytes+0x24e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38ae;
	}
x86_l_384a:
	/* 0x384a: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_384e:
	/* 0x384e: jg     386a <do_bytes+0x20a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_386a;
	}
x86_l_3850:
	/* 0x3850: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_3854:
	/* 0x3854: je     3884 <do_bytes+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3884;
	}
x86_l_3856:
	/* 0x3856: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_385a:
	/* 0x385a: je     389c <do_bytes+0x23c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_389c;
	}
x86_l_385c:
	/* 0x385c: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_3860:
	/* 0x3860: jne    3894 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3894;
	}
x86_l_3862:
	/* 0x3862: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_3868:
	/* 0x3868: jmp    38aa <do_bytes+0x24a> */
	goto x86_l_38aa;
x86_l_386a:
	/* 0x386a: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_386e:
	/* 0x386e: je     388c <do_bytes+0x22c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_388c;
	}
x86_l_3870:
	/* 0x3870: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_3874:
	/* 0x3874: je     38a4 <do_bytes+0x244> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_38a4;
	}
x86_l_3876:
	/* 0x3876: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_387a:
	/* 0x387a: jne    3894 <do_bytes+0x234> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_3894;
	}
x86_l_387c:
	/* 0x387c: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_3882:
	/* 0x3882: jmp    38aa <do_bytes+0x24a> */
	goto x86_l_38aa;
x86_l_3884:
	/* 0x3884: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_388a:
	/* 0x388a: jmp    38aa <do_bytes+0x24a> */
	goto x86_l_38aa;
x86_l_388c:
	/* 0x388c: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_3892:
	/* 0x3892: jmp    38aa <do_bytes+0x24a> */
	goto x86_l_38aa;
x86_l_3894:
	/* 0x3894: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_389a:
	/* 0x389a: jmp    38aa <do_bytes+0x24a> */
	goto x86_l_38aa;
x86_l_389c:
	/* 0x389c: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_38a2:
	/* 0x38a2: jmp    38aa <do_bytes+0x24a> */
	goto x86_l_38aa;
x86_l_38a4:
	/* 0x38a4: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_38aa:
	/* 0x38aa: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_38ae:
	/* 0x38ae: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_38b1:
	/* 0x38b1: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_38b5:
	/* 0x38b5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_38b6:
	/* 0x38b6: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_38b8:
	/* 0x38b8: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_38ba:
	/* 0x38ba: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_38bc:
	/* 0x38bc: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_38be:
	/* 0x38be: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_38bf:
	/* 0x38bf: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_38c0:
	/* 0x38c0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_38c2:
	/* 0x38c2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_38c4:
	/* 0x38c4: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_38c6:
	/* 0x38c6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_38c7:
	/* 0x38c7: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_38c8:
	/* 0x38c8: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_38cb:
	/* 0x38cb: js     394d <__do_bytes+0x8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_394d;
	}
x86_l_38d1:
	/* 0x38d1: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_38d4:
	/* 0x38d4: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_38d7:
	/* 0x38d7: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_38de:
	/* 0x38de: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_38e3:
	/* 0x38e3: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_38e7:
	/* 0x38e7: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38eb:
	/* 0x38eb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_38f0:
	/* 0x38f0: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_38f2:
	/* 0x38f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38f4:
	/* 0x38f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38f6:
	/* 0x38f6: js     3972 <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3972;
	}
x86_l_38f8:
	/* 0x38f8: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38fc:
	/* 0x38fc: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3900:
	/* 0x3900: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_3908:
	/* 0x3908: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_390f:
	/* 0x390f: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3914:
	/* 0x3914: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3919:
	/* 0x3919: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_391b:
	/* 0x391b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_391e:
	/* 0x391e: je     3956 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3956;
	}
x86_l_3920:
	/* 0x3920: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3924:
	/* 0x3924: je     3956 <__do_bytes+0x96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3956;
	}
x86_l_3926:
	/* 0x3926: mov    rsi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_392d:
	/* 0x392d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3932:
	/* 0x3932: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3937:
	/* 0x3937: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_393a:
	/* 0x393a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_393f:
	/* 0x393f: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3942:
	/* 0x3942: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_3945:
	/* 0x3945: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3947:
	/* 0x3947: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3949:
	/* 0x3949: js     3972 <__do_bytes+0xb2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_3972;
	}
x86_l_394b:
	/* 0x394b: jmp    3975 <__do_bytes+0xb5> */
	goto x86_l_3975;
x86_l_394d:
	/* 0x394d: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3954:
	/* 0x3954: jmp    3975 <__do_bytes+0xb5> */
	goto x86_l_3975;
x86_l_3956:
	/* 0x3956: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_395d:
	/* 0x395d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_395f:
	/* 0x395f: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3964:
	/* 0x3964: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3967:
	/* 0x3967: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_396a:
	/* 0x396a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_396c:
	/* 0x396c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_396e:
	/* 0x396e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3970:
	/* 0x3970: jns    3975 <__do_bytes+0xb5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_3975;
	}
x86_l_3972:
	/* 0x3972: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3975:
	/* 0x3975: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3978:
	/* 0x3978: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_397c:
	/* 0x397c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_397d:
	/* 0x397d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_397f:
	/* 0x397f: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3981:
	/* 0x3981: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3983:
	/* 0x3983: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 13144U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1788ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1793ULL && __x86_pc <= 3658ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3663ULL && __x86_pc <= 5523ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5526ULL && __x86_pc <= 7333ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 7338ULL && __x86_pc <= 9106ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 9109ULL && __x86_pc <= 10874ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 10877ULL && __x86_pc <= 12499ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_6(__x86_state, __x86_pc);
		else if (__x86_pc >= 12501ULL && __x86_pc <= 13959ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_7(__x86_state, __x86_pc);
		else if (__x86_pc >= 13966ULL && __x86_pc <= 14723ULL)
			__x86_pc = tetragon_bpf_generic_usdt_v61_generic_usdt_process_event_x86_chunk_8(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

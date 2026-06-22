extern char buffer_heap_map;
extern char config_map;
extern char process_call_heap;
extern char retprobe_map;
extern char tg_errmetrics_map;
extern char tp_calls;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 10ULL: goto x86_l_a;
	case 13ULL: goto x86_l_d;
	case 24ULL: goto x86_l_18;
	case 29ULL: goto x86_l_1d;
	case 36ULL: goto x86_l_24;
	case 44ULL: goto x86_l_2c;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 55ULL: goto x86_l_37;
	case 58ULL: goto x86_l_3a;
	case 64ULL: goto x86_l_40;
	case 67ULL: goto x86_l_43;
	case 74ULL: goto x86_l_4a;
	case 80ULL: goto x86_l_50;
	case 91ULL: goto x86_l_5b;
	case 96ULL: goto x86_l_60;
	case 103ULL: goto x86_l_67;
	case 111ULL: goto x86_l_6f;
	case 113ULL: goto x86_l_71;
	case 116ULL: goto x86_l_74;
	case 122ULL: goto x86_l_7a;
	case 125ULL: goto x86_l_7d;
	case 132ULL: goto x86_l_84;
	case 137ULL: goto x86_l_89;
	case 144ULL: goto x86_l_90;
	case 146ULL: goto x86_l_92;
	case 149ULL: goto x86_l_95;
	case 155ULL: goto x86_l_9b;
	case 158ULL: goto x86_l_9e;
	case 164ULL: goto x86_l_a4;
	case 172ULL: goto x86_l_ac;
	case 180ULL: goto x86_l_b4;
	case 183ULL: goto x86_l_b7;
	case 185ULL: goto x86_l_b9;
	case 190ULL: goto x86_l_be;
	case 195ULL: goto x86_l_c3;
	case 207ULL: goto x86_l_cf;
	case 214ULL: goto x86_l_d6;
	case 216ULL: goto x86_l_d8;
	case 224ULL: goto x86_l_e0;
	case 229ULL: goto x86_l_e5;
	case 235ULL: goto x86_l_eb;
	case 239ULL: goto x86_l_ef;
	case 241ULL: goto x86_l_f1;
	case 245ULL: goto x86_l_f5;
	case 251ULL: goto x86_l_fb;
	case 255ULL: goto x86_l_ff;
	case 261ULL: goto x86_l_105;
	case 266ULL: goto x86_l_10a;
	case 269ULL: goto x86_l_10d;
	case 275ULL: goto x86_l_113;
	case 279ULL: goto x86_l_117;
	case 285ULL: goto x86_l_11d;
	case 290ULL: goto x86_l_122;
	case 292ULL: goto x86_l_124;
	case 297ULL: goto x86_l_129;
	case 303ULL: goto x86_l_12f;
	case 307ULL: goto x86_l_133;
	case 309ULL: goto x86_l_135;
	case 313ULL: goto x86_l_139;
	case 315ULL: goto x86_l_13b;
	case 319ULL: goto x86_l_13f;
	case 325ULL: goto x86_l_145;
	case 329ULL: goto x86_l_149;
	case 335ULL: goto x86_l_14f;
	case 340ULL: goto x86_l_154;
	case 343ULL: goto x86_l_157;
	case 349ULL: goto x86_l_15d;
	case 353ULL: goto x86_l_161;
	case 359ULL: goto x86_l_167;
	case 364ULL: goto x86_l_16c;
	case 368ULL: goto x86_l_170;
	case 374ULL: goto x86_l_176;
	case 379ULL: goto x86_l_17b;
	case 382ULL: goto x86_l_17e;
	case 388ULL: goto x86_l_184;
	case 393ULL: goto x86_l_189;
	case 396ULL: goto x86_l_18c;
	case 402ULL: goto x86_l_192;
	case 407ULL: goto x86_l_197;
	case 411ULL: goto x86_l_19b;
	case 417ULL: goto x86_l_1a1;
	case 421ULL: goto x86_l_1a5;
	case 427ULL: goto x86_l_1ab;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 441ULL: goto x86_l_1b9;
	case 447ULL: goto x86_l_1bf;
	case 452ULL: goto x86_l_1c4;
	case 456ULL: goto x86_l_1c8;
	case 462ULL: goto x86_l_1ce;
	case 466ULL: goto x86_l_1d2;
	case 472ULL: goto x86_l_1d8;
	case 476ULL: goto x86_l_1dc;
	case 482ULL: goto x86_l_1e2;
	case 486ULL: goto x86_l_1e6;
	case 492ULL: goto x86_l_1ec;
	case 497ULL: goto x86_l_1f1;
	case 501ULL: goto x86_l_1f5;
	case 503ULL: goto x86_l_1f7;
	case 507ULL: goto x86_l_1fb;
	case 509ULL: goto x86_l_1fd;
	case 513ULL: goto x86_l_201;
	case 519ULL: goto x86_l_207;
	case 523ULL: goto x86_l_20b;
	case 525ULL: goto x86_l_20d;
	case 530ULL: goto x86_l_212;
	case 534ULL: goto x86_l_216;
	case 536ULL: goto x86_l_218;
	case 539ULL: goto x86_l_21b;
	case 543ULL: goto x86_l_21f;
	case 549ULL: goto x86_l_225;
	case 553ULL: goto x86_l_229;
	case 555ULL: goto x86_l_22b;
	case 557ULL: goto x86_l_22d;
	case 562ULL: goto x86_l_232;
	case 565ULL: goto x86_l_235;
	case 567ULL: goto x86_l_237;
	case 573ULL: goto x86_l_23d;
	case 575ULL: goto x86_l_23f;
	case 579ULL: goto x86_l_243;
	case 581ULL: goto x86_l_245;
	case 585ULL: goto x86_l_249;
	case 587ULL: goto x86_l_24b;
	case 593ULL: goto x86_l_251;
	case 595ULL: goto x86_l_253;
	case 599ULL: goto x86_l_257;
	case 601ULL: goto x86_l_259;
	case 605ULL: goto x86_l_25d;
	case 607ULL: goto x86_l_25f;
	case 613ULL: goto x86_l_265;
	case 615ULL: goto x86_l_267;
	case 621ULL: goto x86_l_26d;
	case 623ULL: goto x86_l_26f;
	case 627ULL: goto x86_l_273;
	case 629ULL: goto x86_l_275;
	case 633ULL: goto x86_l_279;
	case 635ULL: goto x86_l_27b;
	case 641ULL: goto x86_l_281;
	case 643ULL: goto x86_l_283;
	case 649ULL: goto x86_l_289;
	case 651ULL: goto x86_l_28b;
	case 657ULL: goto x86_l_291;
	case 659ULL: goto x86_l_293;
	case 663ULL: goto x86_l_297;
	case 665ULL: goto x86_l_299;
	case 671ULL: goto x86_l_29f;
	case 673ULL: goto x86_l_2a1;
	case 676ULL: goto x86_l_2a4;
	case 687ULL: goto x86_l_2af;
	case 692ULL: goto x86_l_2b4;
	case 699ULL: goto x86_l_2bb;
	case 707ULL: goto x86_l_2c3;
	case 709ULL: goto x86_l_2c5;
	case 712ULL: goto x86_l_2c8;
	case 714ULL: goto x86_l_2ca;
	case 719ULL: goto x86_l_2cf;
	case 722ULL: goto x86_l_2d2;
	case 725ULL: goto x86_l_2d5;
	case 727ULL: goto x86_l_2d7;
	case 734ULL: goto x86_l_2de;
	case 741ULL: goto x86_l_2e5;
	case 745ULL: goto x86_l_2e9;
	case 753ULL: goto x86_l_2f1;
	case 759ULL: goto x86_l_2f7;
	case 761ULL: goto x86_l_2f9;
	case 767ULL: goto x86_l_2ff;
	case 770ULL: goto x86_l_302;
	case 773ULL: goto x86_l_305;
	case 781ULL: goto x86_l_30d;
	case 789ULL: goto x86_l_315;
	case 793ULL: goto x86_l_319;
	case 796ULL: goto x86_l_31c;
	case 798ULL: goto x86_l_31e;
	case 806ULL: goto x86_l_326;
	case 811ULL: goto x86_l_32b;
	case 818ULL: goto x86_l_332;
	case 823ULL: goto x86_l_337;
	case 825ULL: goto x86_l_339;
	case 828ULL: goto x86_l_33c;
	case 830ULL: goto x86_l_33e;
	case 836ULL: goto x86_l_344;
	case 841ULL: goto x86_l_349;
	case 848ULL: goto x86_l_350;
	case 851ULL: goto x86_l_353;
	case 853ULL: goto x86_l_355;
	case 856ULL: goto x86_l_358;
	case 858ULL: goto x86_l_35a;
	case 860ULL: goto x86_l_35c;
	case 862ULL: goto x86_l_35e;
	case 865ULL: goto x86_l_361;
	case 870ULL: goto x86_l_366;
	case 872ULL: goto x86_l_368;
	case 879ULL: goto x86_l_36f;
	case 884ULL: goto x86_l_374;
	case 891ULL: goto x86_l_37b;
	case 894ULL: goto x86_l_37e;
	case 899ULL: goto x86_l_383;
	case 901ULL: goto x86_l_385;
	case 912ULL: goto x86_l_390;
	case 917ULL: goto x86_l_395;
	case 924ULL: goto x86_l_39c;
	case 927ULL: goto x86_l_39f;
	case 932ULL: goto x86_l_3a4;
	case 934ULL: goto x86_l_3a6;
	case 936ULL: goto x86_l_3a8;
	case 943ULL: goto x86_l_3af;
	case 945ULL: goto x86_l_3b1;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 957ULL: goto x86_l_3bd;
	case 960ULL: goto x86_l_3c0;
	case 965ULL: goto x86_l_3c5;
	case 970ULL: goto x86_l_3ca;
	case 975ULL: goto x86_l_3cf;
	case 984ULL: goto x86_l_3d8;
	case 988ULL: goto x86_l_3dc;
	case 990ULL: goto x86_l_3de;
	case 994ULL: goto x86_l_3e2;
	case 996ULL: goto x86_l_3e4;
	case 1000ULL: goto x86_l_3e8;
	case 1006ULL: goto x86_l_3ee;
	case 1008ULL: goto x86_l_3f0;
	case 1012ULL: goto x86_l_3f4;
	case 1018ULL: goto x86_l_3fa;
	case 1022ULL: goto x86_l_3fe;
	case 1024ULL: goto x86_l_400;
	case 1036ULL: goto x86_l_40c;
	case 1044ULL: goto x86_l_414;
	case 1052ULL: goto x86_l_41c;
	case 1057ULL: goto x86_l_421;
	case 1062ULL: goto x86_l_426;
	case 1067ULL: goto x86_l_42b;
	case 1072ULL: goto x86_l_430;
	case 1077ULL: goto x86_l_435;
	case 1079ULL: goto x86_l_437;
	case 1084ULL: goto x86_l_43c;
	case 1092ULL: goto x86_l_444;
	case 1095ULL: goto x86_l_447;
	case 1101ULL: goto x86_l_44d;
	case 1112ULL: goto x86_l_458;
	case 1117ULL: goto x86_l_45d;
	case 1124ULL: goto x86_l_464;
	case 1132ULL: goto x86_l_46c;
	case 1134ULL: goto x86_l_46e;
	case 1137ULL: goto x86_l_471;
	case 1140ULL: goto x86_l_474;
	case 1146ULL: goto x86_l_47a;
	case 1150ULL: goto x86_l_47e;
	case 1156ULL: goto x86_l_484;
	case 1160ULL: goto x86_l_488;
	case 1165ULL: goto x86_l_48d;
	case 1171ULL: goto x86_l_493;
	case 1175ULL: goto x86_l_497;
	case 1181ULL: goto x86_l_49d;
	case 1185ULL: goto x86_l_4a1;
	case 1191ULL: goto x86_l_4a7;
	case 1195ULL: goto x86_l_4ab;
	case 1201ULL: goto x86_l_4b1;
	case 1205ULL: goto x86_l_4b5;
	case 1211ULL: goto x86_l_4bb;
	case 1218ULL: goto x86_l_4c2;
	case 1220ULL: goto x86_l_4c4;
	case 1225ULL: goto x86_l_4c9;
	case 1230ULL: goto x86_l_4ce;
	case 1235ULL: goto x86_l_4d3;
	case 1238ULL: goto x86_l_4d6;
	case 1243ULL: goto x86_l_4db;
	case 1245ULL: goto x86_l_4dd;
	case 1249ULL: goto x86_l_4e1;
	case 1254ULL: goto x86_l_4e6;
	case 1259ULL: goto x86_l_4eb;
	case 1262ULL: goto x86_l_4ee;
	case 1267ULL: goto x86_l_4f3;
	case 1272ULL: goto x86_l_4f8;
	case 1274ULL: goto x86_l_4fa;
	case 1278ULL: goto x86_l_4fe;
	case 1282ULL: goto x86_l_502;
	case 1290ULL: goto x86_l_50a;
	case 1301ULL: goto x86_l_515;
	case 1306ULL: goto x86_l_51a;
	case 1313ULL: goto x86_l_521;
	case 1321ULL: goto x86_l_529;
	case 1323ULL: goto x86_l_52b;
	case 1326ULL: goto x86_l_52e;
	case 1332ULL: goto x86_l_534;
	case 1335ULL: goto x86_l_537;
	case 1341ULL: goto x86_l_53d;
	case 1346ULL: goto x86_l_542;
	case 1351ULL: goto x86_l_547;
	case 1353ULL: goto x86_l_549;
	case 1360ULL: goto x86_l_550;
	case 1365ULL: goto x86_l_555;
	case 1373ULL: goto x86_l_55d;
	case 1378ULL: goto x86_l_562;
	case 1380ULL: goto x86_l_564;
	case 1388ULL: goto x86_l_56c;
	case 1392ULL: goto x86_l_570;
	case 1400ULL: goto x86_l_578;
	case 1408ULL: goto x86_l_580;
	case 1412ULL: goto x86_l_584;
	case 1417ULL: goto x86_l_589;
	case 1425ULL: goto x86_l_591;
	case 1430ULL: goto x86_l_596;
	case 1438ULL: goto x86_l_59e;
	case 1440ULL: goto x86_l_5a0;
	case 1448ULL: goto x86_l_5a8;
	case 1452ULL: goto x86_l_5ac;
	case 1457ULL: goto x86_l_5b1;
	case 1462ULL: goto x86_l_5b6;
	case 1467ULL: goto x86_l_5bb;
	case 1469ULL: goto x86_l_5bd;
	case 1475ULL: goto x86_l_5c3;
	case 1480ULL: goto x86_l_5c8;
	case 1482ULL: goto x86_l_5ca;
	case 1487ULL: goto x86_l_5cf;
	case 1489ULL: goto x86_l_5d1;
	case 1495ULL: goto x86_l_5d7;
	case 1500ULL: goto x86_l_5dc;
	case 1504ULL: goto x86_l_5e0;
	case 1509ULL: goto x86_l_5e5;
	case 1514ULL: goto x86_l_5ea;
	case 1519ULL: goto x86_l_5ef;
	case 1521ULL: goto x86_l_5f1;
	case 1526ULL: goto x86_l_5f6;
	case 1531ULL: goto x86_l_5fb;
	case 1533ULL: goto x86_l_5fd;
	case 1536ULL: goto x86_l_600;
	case 1543ULL: goto x86_l_607;
	case 1553ULL: goto x86_l_611;
	case 1561ULL: goto x86_l_619;
	case 1572ULL: goto x86_l_624;
	case 1577ULL: goto x86_l_629;
	case 1586ULL: goto x86_l_632;
	case 1595ULL: goto x86_l_63b;
	case 1600ULL: goto x86_l_640;
	case 1605ULL: goto x86_l_645;
	case 1610ULL: goto x86_l_64a;
	case 1619ULL: goto x86_l_653;
	case 1628ULL: goto x86_l_65c;
	case 1637ULL: goto x86_l_665;
	case 1642ULL: goto x86_l_66a;
	case 1647ULL: goto x86_l_66f;
	case 1651ULL: goto x86_l_673;
	case 1656ULL: goto x86_l_678;
	case 1661ULL: goto x86_l_67d;
	case 1665ULL: goto x86_l_681;
	case 1670ULL: goto x86_l_686;
	case 1675ULL: goto x86_l_68b;
	case 1680ULL: goto x86_l_690;
	case 1683ULL: goto x86_l_693;
	case 1685ULL: goto x86_l_695;
	case 1690ULL: goto x86_l_69a;
	case 1693ULL: goto x86_l_69d;
	case 1698ULL: goto x86_l_6a2;
	case 1706ULL: goto x86_l_6aa;
	case 1708ULL: goto x86_l_6ac;
	case 1713ULL: goto x86_l_6b1;
	case 1716ULL: goto x86_l_6b4;
	case 1721ULL: goto x86_l_6b9;
	case 1729ULL: goto x86_l_6c1;
	case 1731ULL: goto x86_l_6c3;
	case 1736ULL: goto x86_l_6c8;
	case 1739ULL: goto x86_l_6cb;
	case 1744ULL: goto x86_l_6d0;
	case 1752ULL: goto x86_l_6d8;
	case 1754ULL: goto x86_l_6da;
	case 1759ULL: goto x86_l_6df;
	case 1763ULL: goto x86_l_6e3;
	case 1768ULL: goto x86_l_6e8;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1780ULL: goto x86_l_6f4;
	case 1785ULL: goto x86_l_6f9;
	case 1787ULL: goto x86_l_6fb;
	case 1792ULL: goto x86_l_700;
	case 1797ULL: goto x86_l_705;
	case 1802ULL: goto x86_l_70a;
	case 1807ULL: goto x86_l_70f;
	case 1809ULL: goto x86_l_711;
	case 1812ULL: goto x86_l_714;
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
	/* 0xa: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x6587] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     3a6 <generic_tracepoint_process_event_2+0x3a6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3a6;
	}
x86_l_37:
	/* 0x37: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    ebp,DWORD PTR [rax+0x5eec] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_40:
	/* 0x40: mov    ebx,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_43:
	/* 0x43: cmp    rbx,0x2327 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 8999ULL);
x86_l_4a:
	/* 0x4a: ja     315 <generic_tracepoint_process_event_2+0x315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_315;
	}
x86_l_50:
	/* 0x50: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_5b:
	/* 0x5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60:
	/* 0x60: mov    rdi,QWORD PTR [rip+0x6587] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_67:
	/* 0x67: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_6f:
	/* 0x6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71:
	/* 0x71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: je     315 <generic_tracepoint_process_event_2+0x315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315;
	}
x86_l_7a:
	/* 0x7a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: lea    rsi,[rax+0x5ee8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24296ULL);
x86_l_84:
	/* 0x84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89:
	/* 0x89: mov    rdi,QWORD PTR [rip+0x6587] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_90:
	/* 0x90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92:
	/* 0x92: cmp    ebp,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4ULL);
x86_l_95:
	/* 0x95: jg     315 <generic_tracepoint_process_event_2+0x315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_315;
	}
x86_l_9b:
	/* 0x9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: je     315 <generic_tracepoint_process_event_2+0x315> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_315;
	}
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x98],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0xc0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_b4:
	/* 0xb4: and    ebp,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_b7:
	/* 0xb7: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_b9:
	/* 0xb9: mov    r12d,DWORD PTR [rax+rcx*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 4ULL);
x86_l_be:
	/* 0xbe: movsxd r13,DWORD PTR [rax+rcx*4+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_RCX, 2, X86_WIDTH_32), 24ULL);
x86_l_c3:
	/* 0xc3: mov    DWORD PTR [r15+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_cf:
	/* 0xcf: test   r13d,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 256ULL);
x86_l_d6:
	/* 0xd6: jne    122 <generic_tracepoint_process_event_2+0x122> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_122;
	}
x86_l_d8:
	/* 0xd8: mov    rax,QWORD PTR [r15+rcx*8+0x5e50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 3), 24144ULL);
x86_l_e0:
	/* 0xe0: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e5:
	/* 0xe5: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_eb:
	/* 0xeb: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_ef:
	/* 0xef: jle    135 <generic_tracepoint_process_event_2+0x135> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_135;
	}
x86_l_f1:
	/* 0xf1: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_f5:
	/* 0xf5: jle    197 <generic_tracepoint_process_event_2+0x197> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_197;
	}
x86_l_fb:
	/* 0xfb: cmp    r12d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 38ULL);
x86_l_ff:
	/* 0xff: jg     1f1 <generic_tracepoint_process_event_2+0x1f1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f1;
	}
x86_l_105:
	/* 0x105: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_10a:
	/* 0x10a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10d:
	/* 0x10d: jb     267 <generic_tracepoint_process_event_2+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_267;
	}
x86_l_113:
	/* 0x113: cmp    r12d,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 37ULL);
x86_l_117:
	/* 0x117: je     2a4 <generic_tracepoint_process_event_2+0x2a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4;
	}
x86_l_11d:
	/* 0x11d: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_122:
	/* 0x122: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124:
	/* 0x124: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_129:
	/* 0x129: mov    r15d,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 144ULL);
x86_l_12f:
	/* 0x12f: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_133:
	/* 0x133: jg     f1 <generic_tracepoint_process_event_2+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_f1;
	}
x86_l_135:
	/* 0x135: cmp    r12d,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 11ULL);
x86_l_139:
	/* 0x139: jg     16c <generic_tracepoint_process_event_2+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_16c;
	}
x86_l_13b:
	/* 0x13b: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_13f:
	/* 0x13f: jg     1c4 <generic_tracepoint_process_event_2+0x1c4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1c4;
	}
x86_l_145:
	/* 0x145: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_149:
	/* 0x149: jg     253 <generic_tracepoint_process_event_2+0x253> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_253;
	}
x86_l_14f:
	/* 0x14f: lea    eax,[r12-0x2] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_154:
	/* 0x154: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_157:
	/* 0x157: jb     237 <generic_tracepoint_process_event_2+0x237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_237;
	}
x86_l_15d:
	/* 0x15d: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_161:
	/* 0x161: je     237 <generic_tracepoint_process_event_2+0x237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_237;
	}
x86_l_167:
	/* 0x167: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_16c:
	/* 0x16c: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_170:
	/* 0x170: jg     212 <generic_tracepoint_process_event_2+0x212> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_212;
	}
x86_l_176:
	/* 0x176: lea    eax,[r12-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_17b:
	/* 0x17b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_17e:
	/* 0x17e: jb     2a4 <generic_tracepoint_process_event_2+0x2a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2a4;
	}
x86_l_184:
	/* 0x184: lea    eax,[r12-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_189:
	/* 0x189: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18c:
	/* 0x18c: jb     237 <generic_tracepoint_process_event_2+0x237> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_237;
	}
x86_l_192:
	/* 0x192: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_197:
	/* 0x197: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_19b:
	/* 0x19b: jg     22d <generic_tracepoint_process_event_2+0x22d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_22d;
	}
x86_l_1a1:
	/* 0x1a1: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_1a5:
	/* 0x1a5: je     283 <generic_tracepoint_process_event_2+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283;
	}
x86_l_1ab:
	/* 0x1ab: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_1af:
	/* 0x1af: je     267 <generic_tracepoint_process_event_2+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267;
	}
x86_l_1b5:
	/* 0x1b5: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_1b9:
	/* 0x1b9: je     299 <generic_tracepoint_process_event_2+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_299;
	}
x86_l_1bf:
	/* 0x1bf: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_1c4:
	/* 0x1c4: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1c8:
	/* 0x1c8: jg     267 <generic_tracepoint_process_event_2+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_267;
	}
x86_l_1ce:
	/* 0x1ce: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1d2:
	/* 0x1d2: je     2a4 <generic_tracepoint_process_event_2+0x2a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4;
	}
x86_l_1d8:
	/* 0x1d8: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1dc:
	/* 0x1dc: je     25f <generic_tracepoint_process_event_2+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f;
	}
x86_l_1e2:
	/* 0x1e2: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1e6:
	/* 0x1e6: je     299 <generic_tracepoint_process_event_2+0x299> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_299;
	}
x86_l_1ec:
	/* 0x1ec: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_1f1:
	/* 0x1f1: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_1f5:
	/* 0x1f5: jle    26f <generic_tracepoint_process_event_2+0x26f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_26f;
	}
x86_l_1f7:
	/* 0x1f7: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_1fb:
	/* 0x1fb: je     25f <generic_tracepoint_process_event_2+0x25f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25f;
	}
x86_l_1fd:
	/* 0x1fd: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_201:
	/* 0x201: je     2a4 <generic_tracepoint_process_event_2+0x2a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4;
	}
x86_l_207:
	/* 0x207: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_20b:
	/* 0x20b: je     27b <generic_tracepoint_process_event_2+0x27b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b;
	}
x86_l_20d:
	/* 0x20d: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_212:
	/* 0x212: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_216:
	/* 0x216: jg     23f <generic_tracepoint_process_event_2+0x23f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_23f;
	}
x86_l_218:
	/* 0x218: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_21b:
	/* 0x21b: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_21f:
	/* 0x21f: je     2a4 <generic_tracepoint_process_event_2+0x2a4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2a4;
	}
x86_l_225:
	/* 0x225: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_229:
	/* 0x229: je     27b <generic_tracepoint_process_event_2+0x27b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_27b;
	}
x86_l_22b:
	/* 0x22b: jmp    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	goto x86_l_2a1;
x86_l_22d:
	/* 0x22d: lea    eax,[r12-0x1d] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551587ULL);
x86_l_232:
	/* 0x232: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_235:
	/* 0x235: jae    293 <generic_tracepoint_process_event_2+0x293> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_293;
	}
x86_l_237:
	/* 0x237: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_23d:
	/* 0x23d: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_23f:
	/* 0x23f: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_243:
	/* 0x243: je     28b <generic_tracepoint_process_event_2+0x28b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_28b;
	}
x86_l_245:
	/* 0x245: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_249:
	/* 0x249: jne    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a1;
	}
x86_l_24b:
	/* 0x24b: mov    r15d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 32ULL);
x86_l_251:
	/* 0x251: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_253:
	/* 0x253: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_257:
	/* 0x257: je     267 <generic_tracepoint_process_event_2+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_267;
	}
x86_l_259:
	/* 0x259: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_25d:
	/* 0x25d: jne    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a1;
	}
x86_l_25f:
	/* 0x25f: mov    r15d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 64ULL);
x86_l_265:
	/* 0x265: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_267:
	/* 0x267: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_26d:
	/* 0x26d: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_26f:
	/* 0x26f: cmp    r12d,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 39ULL);
x86_l_273:
	/* 0x273: je     283 <generic_tracepoint_process_event_2+0x283> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_283;
	}
x86_l_275:
	/* 0x275: cmp    r12d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 40ULL);
x86_l_279:
	/* 0x279: jne    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a1;
	}
x86_l_27b:
	/* 0x27b: mov    r15d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 24ULL);
x86_l_281:
	/* 0x281: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_283:
	/* 0x283: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_289:
	/* 0x289: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_28b:
	/* 0x28b: mov    r15d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 152ULL);
x86_l_291:
	/* 0x291: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_293:
	/* 0x293: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_297:
	/* 0x297: jne    2a1 <generic_tracepoint_process_event_2+0x2a1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2a1;
	}
x86_l_299:
	/* 0x299: mov    r15d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 80ULL);
x86_l_29f:
	/* 0x29f: jmp    2a4 <generic_tracepoint_process_event_2+0x2a4> */
	goto x86_l_2a4;
x86_l_2a1:
	/* 0x2a1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a4:
	/* 0x2a4: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_2af:
	/* 0x2af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b4:
	/* 0x2b4: mov    rdi,QWORD PTR [rip+0x657b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_2bb:
	/* 0x2bb: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_2c3:
	/* 0x2c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5:
	/* 0x2c5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2c8:
	/* 0x2c8: je     305 <generic_tracepoint_process_event_2+0x305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_305;
	}
x86_l_2ca:
	/* 0x2ca: mov    ecx,0x3ffb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16379ULL);
x86_l_2cf:
	/* 0x2cf: sub    rcx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_2d2:
	/* 0x2d2: cmp    rcx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_2d5:
	/* 0x2d5: jbe    305 <generic_tracepoint_process_event_2+0x305> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_305;
	}
x86_l_2d7:
	/* 0x2d7: mov    ecx,DWORD PTR [rax+rbp*4+0x5ea0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 2), 24224ULL);
x86_l_2de:
	/* 0x2de: mov    DWORD PTR [rax+rbx*1+0x90],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 144ULL);
x86_l_2e5:
	/* 0x2e5: lea    r15,[rbx+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e9:
	/* 0x2e9: mov    QWORD PTR [rax+rbp*8+0x5e78],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 3), 24184ULL);
x86_l_2f1:
	/* 0x2f1: mov    r8d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4ULL);
x86_l_2f7:
	/* 0x2f7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2f9:
	/* 0x2f9: je     3b7 <generic_tracepoint_process_event_2+0x3b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3b7;
	}
x86_l_2ff:
	/* 0x2ff: add    r8d,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_302:
	/* 0x302: mov    ebx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_32);
x86_l_305:
	/* 0x305: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_30d:
	/* 0x30d: mov    rbp,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_315:
	/* 0x315: mov    DWORD PTR [r14+0x4],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_319:
	/* 0x319: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_31c:
	/* 0x31c: jg     385 <generic_tracepoint_process_event_2+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_385;
	}
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_326:
	/* 0x326: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_32b:
	/* 0x32b: mov    rdi,QWORD PTR [rip+0x657b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_332:
	/* 0x332: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_337:
	/* 0x337: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_339:
	/* 0x339: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_33c:
	/* 0x33c: je     385 <generic_tracepoint_process_event_2+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385;
	}
x86_l_33e:
	/* 0x33e: add    rax,0x5ee8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 24296ULL);
x86_l_344:
	/* 0x344: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_349:
	/* 0x349: mov    rdi,QWORD PTR [rip+0x657b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_350:
	/* 0x350: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_353:
	/* 0x353: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_355:
	/* 0x355: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_358:
	/* 0x358: je     385 <generic_tracepoint_process_event_2+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385;
	}
x86_l_35a:
	/* 0x35a: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_35c:
	/* 0x35c: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_35e:
	/* 0x35e: and    ecx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_361:
	/* 0x361: cmp    DWORD PTR [rax+rcx*4+0x40],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 279172874239ULL);
x86_l_366:
	/* 0x366: je     385 <generic_tracepoint_process_event_2+0x385> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_385;
	}
x86_l_368:
	/* 0x368: mov    DWORD PTR [r14+0x5eec],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24300ULL);
x86_l_36f:
	/* 0x36f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_374:
	/* 0x374: mov    rsi,QWORD PTR [rip+0x657b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_37b:
	/* 0x37b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_37e:
	/* 0x37e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_383:
	/* 0x383: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_385:
	/* 0x385: mov    DWORD PTR [r14+0x5eec],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104367705292800ULL);
x86_l_390:
	/* 0x390: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_395:
	/* 0x395: mov    rsi,QWORD PTR [rip+0x657b] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tp_calls)));
x86_l_39c:
	/* 0x39c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_39f:
	/* 0x39f: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_3a4:
	/* 0x3a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6:
	/* 0x3a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a8:
	/* 0x3a8: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_3af:
	/* 0x3af: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3b1:
	/* 0x3b1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3b2:
	/* 0x3b2: jmp    265b <generic_tracepoint_process_event_2+0x265b> ; native-link entry RET */
	return 0xffffffffffffffffULL;
x86_l_3b7:
	/* 0x3b7: add    rax,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_3bd:
	/* 0x3bd: add    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3c0:
	/* 0x3c0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3c5:
	/* 0x3c5: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_3ca:
	/* 0x3ca: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cf:
	/* 0x3cf: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3d8:
	/* 0x3d8: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_3dc:
	/* 0x3dc: jg     3f0 <generic_tracepoint_process_event_2+0x3f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_3f0;
	}
x86_l_3de:
	/* 0x3de: cmp    r12d,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 15ULL);
x86_l_3e2:
	/* 0x3e2: je     421 <generic_tracepoint_process_event_2+0x421> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_421;
	}
x86_l_3e4:
	/* 0x3e4: cmp    r12d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 16ULL);
x86_l_3e8:
	/* 0x3e8: je     4e6 <generic_tracepoint_process_event_2+0x4e6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4e6;
	}
x86_l_3ee:
	/* 0x3ee: jmp    44d <generic_tracepoint_process_event_2+0x44d> */
	goto x86_l_44d;
x86_l_3f0:
	/* 0x3f0: cmp    r12d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 24ULL);
x86_l_3f4:
	/* 0x3f4: je     4c9 <generic_tracepoint_process_event_2+0x4c9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4c9;
	}
x86_l_3fa:
	/* 0x3fa: cmp    r12d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 42ULL);
x86_l_3fe:
	/* 0x3fe: jne    44d <generic_tracepoint_process_event_2+0x44d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_44d;
	}
x86_l_400:
	/* 0x400: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_40c:
	/* 0x40c: mov    QWORD PTR [rsp+0xd0],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_414:
	/* 0x414: lea    rax,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_41c:
	/* 0x41c: jmp    502 <generic_tracepoint_process_event_2+0x502> */
	goto x86_l_502;
x86_l_421:
	/* 0x421: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_426:
	/* 0x426: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_42b:
	/* 0x42b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_430:
	/* 0x430: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_435:
	/* 0x435: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_437:
	/* 0x437: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_43c:
	/* 0x43c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_444:
	/* 0x444: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_447:
	/* 0x447: jne    50a <generic_tracepoint_process_event_2+0x50a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_50a;
	}
x86_l_44d:
	/* 0x44d: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_458:
	/* 0x458: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45d:
	/* 0x45d: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_464:
	/* 0x464: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_46c:
	/* 0x46c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46e:
	/* 0x46e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_471:
	/* 0x471: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_474:
	/* 0x474: je     1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7459ULL;
	}
x86_l_47a:
	/* 0x47a: cmp    r12d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 25ULL);
x86_l_47e:
	/* 0x47e: jg     9bb <generic_tracepoint_process_event_2+0x9bb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 2491ULL;
	}
x86_l_484:
	/* 0x484: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_488:
	/* 0x488: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_48d:
	/* 0x48d: jle    9f2 <generic_tracepoint_process_event_2+0x9f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 2546ULL;
	}
x86_l_493:
	/* 0x493: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_497:
	/* 0x497: jle    dc2 <generic_tracepoint_process_event_2+0xdc2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 3522ULL;
	}
x86_l_49d:
	/* 0x49d: cmp    r12d,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 21ULL);
x86_l_4a1:
	/* 0x4a1: je     10e4 <generic_tracepoint_process_event_2+0x10e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4324ULL;
	}
x86_l_4a7:
	/* 0x4a7: cmp    r12d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 22ULL);
x86_l_4ab:
	/* 0x4ab: je     1073 <generic_tracepoint_process_event_2+0x1073> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4211ULL;
	}
x86_l_4b1:
	/* 0x4b1: cmp    r12d,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 23ULL);
x86_l_4b5:
	/* 0x4b5: jne    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7459ULL;
	}
x86_l_4bb:
	/* 0x4bb: mov    DWORD PTR [rcx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_4c2:
	/* 0x4c2: mov    DWORD PTR [rcx],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c4:
	/* 0x4c4: jmp    9e7 <generic_tracepoint_process_event_2+0x9e7> */
	return 2535ULL;
x86_l_4c9:
	/* 0x4c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4ce:
	/* 0x4ce: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4d3:
	/* 0x4d3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4d6:
	/* 0x4d6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4db:
	/* 0x4db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dd:
	/* 0x4dd: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e1:
	/* 0x4e1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4e6:
	/* 0x4e6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4eb:
	/* 0x4eb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_4ee:
	/* 0x4ee: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4f3:
	/* 0x4f3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_4f8:
	/* 0x4f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fa:
	/* 0x4fa: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fe:
	/* 0x4fe: add    rax,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_50a:
	/* 0x50a: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_515:
	/* 0x515: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51a:
	/* 0x51a: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&buffer_heap_map)));
x86_l_521:
	/* 0x521: lea    rsi,[rsp+0xbc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_529:
	/* 0x529: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52b:
	/* 0x52b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52e:
	/* 0x52e: je     5d1 <generic_tracepoint_process_event_2+0x5d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5d1;
	}
x86_l_534:
	/* 0x534: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: add    rax,0x1000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4096ULL);
x86_l_53d:
	/* 0x53d: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_542:
	/* 0x542: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_547:
	/* 0x547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_549:
	/* 0x549: lea    rdx,[rax+0xd30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3376ULL);
x86_l_550:
	/* 0x550: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_555:
	/* 0x555: lea    rdi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_55d:
	/* 0x55d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_562:
	/* 0x562: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564:
	/* 0x564: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_56c:
	/* 0x56c: lea    rax,[r15+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_578:
	/* 0x578: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_580:
	/* 0x580: lea    rdx,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_584:
	/* 0x584: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_589:
	/* 0x589: lea    rdi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_591:
	/* 0x591: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_596:
	/* 0x596: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_59e:
	/* 0x59e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a0:
	/* 0x5a0: mov    r13,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5a8:
	/* 0x5a8: lea    rdx,[r13+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ac:
	/* 0x5ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5b1:
	/* 0x5b1: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5b6:
	/* 0x5b6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5bb:
	/* 0x5bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bd:
	/* 0x5bd: cmp    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5c3:
	/* 0x5c3: mov    ebp,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4096ULL);
x86_l_5c8:
	/* 0x5c8: je     5dc <generic_tracepoint_process_event_2+0x5dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_5dc;
	}
x86_l_5ca:
	/* 0x5ca: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5cf:
	/* 0x5cf: jmp    629 <generic_tracepoint_process_event_2+0x629> */
	goto x86_l_629;
x86_l_5d1:
	/* 0x5d1: mov    r8d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4ULL);
x86_l_5d7:
	/* 0x5d7: jmp    2ff <generic_tracepoint_process_event_2+0x2ff> */
	goto x86_l_2ff;
x86_l_5dc:
	/* 0x5dc: lea    rdx,[r13+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e0:
	/* 0x5e0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_5e5:
	/* 0x5e5: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ea:
	/* 0x5ea: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5ef:
	/* 0x5ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f1:
	/* 0x5f1: cmp    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f6:
	/* 0x5f6: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_5fb:
	/* 0x5fb: je     629 <generic_tracepoint_process_event_2+0x629> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_629;
	}
x86_l_5fd:
	/* 0x5fd: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_600:
	/* 0x600: add    rcx,0xff6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4086ULL);
x86_l_607:
	/* 0x607: movabs rax,0x6574656c65642820 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 7310579611361093664ULL);
x86_l_611:
	/* 0x611: mov    QWORD PTR [r12+0xff6],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4086ULL);
x86_l_619:
	/* 0x619: mov    WORD PTR [r12+0xffe],0x2964 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17583596120420ULL);
x86_l_624:
	/* 0x624: mov    ebp,0xff6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4086ULL);
x86_l_629:
	/* 0x629: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_632:
	/* 0x632: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_63b:
	/* 0x63b: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_640:
	/* 0x640: lea    r12,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_645:
	/* 0x645: lea    r13,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_64a:
	/* 0x64a: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_653:
	/* 0x653: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_65c:
	/* 0x65c: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_665:
	/* 0x665: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_66a:
	/* 0x66a: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_66f:
	/* 0x66f: mov    DWORD PTR [rsp+0x48],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_673:
	/* 0x673: lea    rbp,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_678:
	/* 0x678: mov    BYTE PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_67d:
	/* 0x67d: add    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_681:
	/* 0x681: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_686:
	/* 0x686: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_68b:
	/* 0x68b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_690:
	/* 0x690: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_693:
	/* 0x693: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_695:
	/* 0x695: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_69a:
	/* 0x69a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_69d:
	/* 0x69d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6a2:
	/* 0x6a2: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6aa:
	/* 0x6aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ac:
	/* 0x6ac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6b1:
	/* 0x6b1: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_6b4:
	/* 0x6b4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6b9:
	/* 0x6b9: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_6c1:
	/* 0x6c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c3:
	/* 0x6c3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_6c8:
	/* 0x6c8: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_6cb:
	/* 0x6cb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6d0:
	/* 0x6d0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6d8:
	/* 0x6d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6da:
	/* 0x6da: mov    r15,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6df:
	/* 0x6df: lea    rax,[r15-0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551584ULL);
x86_l_6e3:
	/* 0x6e3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e8:
	/* 0x6e8: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6ed:
	/* 0x6ed: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_6f2:
	/* 0x6f2: jne    751 <generic_tracepoint_process_event_2+0x751> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1873ULL;
	}
x86_l_6f4:
	/* 0x6f4: cmp    r15,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_6f9:
	/* 0x6f9: jne    751 <generic_tracepoint_process_event_2+0x751> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1873ULL;
	}
x86_l_6fb:
	/* 0x6fb: mov    BYTE PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_700:
	/* 0x700: mov    r8,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_705:
	/* 0x705: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_70a:
	/* 0x70a: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_70f:
	/* 0x70f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_711:
	/* 0x711: cmp    rcx,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_714:
	/* 0x714: je     25d3 <generic_tracepoint_process_event_2+0x25d3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9683ULL;
	}
	return 1818ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1818ULL: goto x86_l_71a;
	case 1823ULL: goto x86_l_71f;
	case 1826ULL: goto x86_l_722;
	case 1830ULL: goto x86_l_726;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1841ULL: goto x86_l_731;
	case 1845ULL: goto x86_l_735;
	case 1848ULL: goto x86_l_738;
	case 1854ULL: goto x86_l_73e;
	case 1860ULL: goto x86_l_744;
	case 1863ULL: goto x86_l_747;
	case 1865ULL: goto x86_l_749;
	case 1868ULL: goto x86_l_74c;
	case 1873ULL: goto x86_l_751;
	case 1878ULL: goto x86_l_756;
	case 1883ULL: goto x86_l_75b;
	case 1888ULL: goto x86_l_760;
	case 1893ULL: goto x86_l_765;
	case 1896ULL: goto x86_l_768;
	case 1898ULL: goto x86_l_76a;
	case 1903ULL: goto x86_l_76f;
	case 1909ULL: goto x86_l_775;
	case 1914ULL: goto x86_l_77a;
	case 1919ULL: goto x86_l_77f;
	case 1922ULL: goto x86_l_782;
	case 1927ULL: goto x86_l_787;
	case 1930ULL: goto x86_l_78a;
	case 1932ULL: goto x86_l_78c;
	case 1936ULL: goto x86_l_790;
	case 1942ULL: goto x86_l_796;
	case 1947ULL: goto x86_l_79b;
	case 1952ULL: goto x86_l_7a0;
	case 1957ULL: goto x86_l_7a5;
	case 1960ULL: goto x86_l_7a8;
	case 1962ULL: goto x86_l_7aa;
	case 1966ULL: goto x86_l_7ae;
	case 1971ULL: goto x86_l_7b3;
	case 1976ULL: goto x86_l_7b8;
	case 1981ULL: goto x86_l_7bd;
	case 1984ULL: goto x86_l_7c0;
	case 1986ULL: goto x86_l_7c2;
	case 1991ULL: goto x86_l_7c7;
	case 1996ULL: goto x86_l_7cc;
	case 2000ULL: goto x86_l_7d0;
	case 2003ULL: goto x86_l_7d3;
	case 2007ULL: goto x86_l_7d7;
	case 2009ULL: goto x86_l_7d9;
	case 2011ULL: goto x86_l_7db;
	case 2013ULL: goto x86_l_7dd;
	case 2016ULL: goto x86_l_7e0;
	case 2021ULL: goto x86_l_7e5;
	case 2024ULL: goto x86_l_7e8;
	case 2026ULL: goto x86_l_7ea;
	case 2030ULL: goto x86_l_7ee;
	case 2032ULL: goto x86_l_7f0;
	case 2035ULL: goto x86_l_7f3;
	case 2038ULL: goto x86_l_7f6;
	case 2041ULL: goto x86_l_7f9;
	case 2044ULL: goto x86_l_7fc;
	case 2049ULL: goto x86_l_801;
	case 2052ULL: goto x86_l_804;
	case 2055ULL: goto x86_l_807;
	case 2061ULL: goto x86_l_80d;
	case 2068ULL: goto x86_l_814;
	case 2074ULL: goto x86_l_81a;
	case 2076ULL: goto x86_l_81c;
	case 2082ULL: goto x86_l_822;
	case 2086ULL: goto x86_l_826;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2098ULL: goto x86_l_832;
	case 2101ULL: goto x86_l_835;
	case 2106ULL: goto x86_l_83a;
	case 2108ULL: goto x86_l_83c;
	case 2113ULL: goto x86_l_841;
	case 2118ULL: goto x86_l_846;
	case 2123ULL: goto x86_l_84b;
	case 2128ULL: goto x86_l_850;
	case 2133ULL: goto x86_l_855;
	case 2135ULL: goto x86_l_857;
	case 2139ULL: goto x86_l_85b;
	case 2144ULL: goto x86_l_860;
	case 2147ULL: goto x86_l_863;
	case 2152ULL: goto x86_l_868;
	case 2154ULL: goto x86_l_86a;
	case 2159ULL: goto x86_l_86f;
	case 2163ULL: goto x86_l_873;
	case 2169ULL: goto x86_l_879;
	case 2173ULL: goto x86_l_87d;
	case 2178ULL: goto x86_l_882;
	case 2183ULL: goto x86_l_887;
	case 2188ULL: goto x86_l_88c;
	case 2191ULL: goto x86_l_88f;
	case 2193ULL: goto x86_l_891;
	case 2197ULL: goto x86_l_895;
	case 2202ULL: goto x86_l_89a;
	case 2206ULL: goto x86_l_89e;
	case 2211ULL: goto x86_l_8a3;
	case 2216ULL: goto x86_l_8a8;
	case 2221ULL: goto x86_l_8ad;
	case 2223ULL: goto x86_l_8af;
	case 2228ULL: goto x86_l_8b4;
	case 2234ULL: goto x86_l_8ba;
	case 2239ULL: goto x86_l_8bf;
	case 2244ULL: goto x86_l_8c4;
	case 2249ULL: goto x86_l_8c9;
	case 2251ULL: goto x86_l_8cb;
	case 2256ULL: goto x86_l_8d0;
	case 2262ULL: goto x86_l_8d6;
	case 2267ULL: goto x86_l_8db;
	case 2272ULL: goto x86_l_8e0;
	case 2275ULL: goto x86_l_8e3;
	case 2280ULL: goto x86_l_8e8;
	case 2283ULL: goto x86_l_8eb;
	case 2285ULL: goto x86_l_8ed;
	case 2289ULL: goto x86_l_8f1;
	case 2295ULL: goto x86_l_8f7;
	case 2300ULL: goto x86_l_8fc;
	case 2305ULL: goto x86_l_901;
	case 2310ULL: goto x86_l_906;
	case 2313ULL: goto x86_l_909;
	case 2315ULL: goto x86_l_90b;
	case 2319ULL: goto x86_l_90f;
	case 2324ULL: goto x86_l_914;
	case 2329ULL: goto x86_l_919;
	case 2334ULL: goto x86_l_91e;
	case 2337ULL: goto x86_l_921;
	case 2339ULL: goto x86_l_923;
	case 2344ULL: goto x86_l_928;
	case 2349ULL: goto x86_l_92d;
	case 2353ULL: goto x86_l_931;
	case 2356ULL: goto x86_l_934;
	case 2360ULL: goto x86_l_938;
	case 2362ULL: goto x86_l_93a;
	case 2364ULL: goto x86_l_93c;
	case 2366ULL: goto x86_l_93e;
	case 2369ULL: goto x86_l_941;
	case 2374ULL: goto x86_l_946;
	case 2377ULL: goto x86_l_949;
	case 2379ULL: goto x86_l_94b;
	case 2383ULL: goto x86_l_94f;
	case 2385ULL: goto x86_l_951;
	case 2388ULL: goto x86_l_954;
	case 2391ULL: goto x86_l_957;
	case 2394ULL: goto x86_l_95a;
	case 2397ULL: goto x86_l_95d;
	case 2402ULL: goto x86_l_962;
	case 2405ULL: goto x86_l_965;
	case 2408ULL: goto x86_l_968;
	case 2414ULL: goto x86_l_96e;
	case 2421ULL: goto x86_l_975;
	case 2427ULL: goto x86_l_97b;
	case 2429ULL: goto x86_l_97d;
	case 2435ULL: goto x86_l_983;
	case 2439ULL: goto x86_l_987;
	case 2444ULL: goto x86_l_98c;
	case 2447ULL: goto x86_l_98f;
	case 2451ULL: goto x86_l_993;
	case 2454ULL: goto x86_l_996;
	case 2459ULL: goto x86_l_99b;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2471ULL: goto x86_l_9a7;
	case 2476ULL: goto x86_l_9ac;
	case 2481ULL: goto x86_l_9b1;
	case 2486ULL: goto x86_l_9b6;
	case 2491ULL: goto x86_l_9bb;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2506ULL: goto x86_l_9ca;
	case 2511ULL: goto x86_l_9cf;
	case 2514ULL: goto x86_l_9d2;
	case 2520ULL: goto x86_l_9d8;
	case 2525ULL: goto x86_l_9dd;
	case 2530ULL: goto x86_l_9e2;
	case 2533ULL: goto x86_l_9e5;
	case 2535ULL: goto x86_l_9e7;
	case 2541ULL: goto x86_l_9ed;
	case 2546ULL: goto x86_l_9f2;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2559ULL: goto x86_l_9ff;
	case 2563ULL: goto x86_l_a03;
	case 2569ULL: goto x86_l_a09;
	case 2573ULL: goto x86_l_a0d;
	case 2579ULL: goto x86_l_a13;
	case 2586ULL: goto x86_l_a1a;
	case 2588ULL: goto x86_l_a1c;
	case 2591ULL: goto x86_l_a1f;
	case 2594ULL: goto x86_l_a22;
	case 2600ULL: goto x86_l_a28;
	case 2603ULL: goto x86_l_a2b;
	case 2609ULL: goto x86_l_a31;
	case 2612ULL: goto x86_l_a34;
	case 2615ULL: goto x86_l_a37;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2636ULL: goto x86_l_a4c;
	case 2643ULL: goto x86_l_a53;
	case 2648ULL: goto x86_l_a58;
	case 2652ULL: goto x86_l_a5c;
	case 2657ULL: goto x86_l_a61;
	case 2660ULL: goto x86_l_a64;
	case 2665ULL: goto x86_l_a69;
	case 2667ULL: goto x86_l_a6b;
	case 2672ULL: goto x86_l_a70;
	case 2676ULL: goto x86_l_a74;
	case 2682ULL: goto x86_l_a7a;
	case 2686ULL: goto x86_l_a7e;
	case 2691ULL: goto x86_l_a83;
	case 2696ULL: goto x86_l_a88;
	case 2701ULL: goto x86_l_a8d;
	case 2704ULL: goto x86_l_a90;
	case 2706ULL: goto x86_l_a92;
	case 2710ULL: goto x86_l_a96;
	case 2715ULL: goto x86_l_a9b;
	case 2719ULL: goto x86_l_a9f;
	case 2724ULL: goto x86_l_aa4;
	case 2729ULL: goto x86_l_aa9;
	case 2734ULL: goto x86_l_aae;
	case 2736ULL: goto x86_l_ab0;
	case 2741ULL: goto x86_l_ab5;
	case 2747ULL: goto x86_l_abb;
	case 2752ULL: goto x86_l_ac0;
	case 2757ULL: goto x86_l_ac5;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2769ULL: goto x86_l_ad1;
	case 2775ULL: goto x86_l_ad7;
	case 2780ULL: goto x86_l_adc;
	case 2785ULL: goto x86_l_ae1;
	case 2788ULL: goto x86_l_ae4;
	case 2793ULL: goto x86_l_ae9;
	case 2796ULL: goto x86_l_aec;
	case 2798ULL: goto x86_l_aee;
	case 2802ULL: goto x86_l_af2;
	case 2808ULL: goto x86_l_af8;
	case 2813ULL: goto x86_l_afd;
	case 2818ULL: goto x86_l_b02;
	case 2823ULL: goto x86_l_b07;
	case 2826ULL: goto x86_l_b0a;
	case 2828ULL: goto x86_l_b0c;
	case 2832ULL: goto x86_l_b10;
	case 2837ULL: goto x86_l_b15;
	case 2842ULL: goto x86_l_b1a;
	case 2847ULL: goto x86_l_b1f;
	case 2850ULL: goto x86_l_b22;
	case 2852ULL: goto x86_l_b24;
	case 2857ULL: goto x86_l_b29;
	case 2862ULL: goto x86_l_b2e;
	case 2866ULL: goto x86_l_b32;
	case 2869ULL: goto x86_l_b35;
	case 2873ULL: goto x86_l_b39;
	case 2875ULL: goto x86_l_b3b;
	case 2877ULL: goto x86_l_b3d;
	case 2879ULL: goto x86_l_b3f;
	case 2882ULL: goto x86_l_b42;
	case 2887ULL: goto x86_l_b47;
	case 2890ULL: goto x86_l_b4a;
	case 2892ULL: goto x86_l_b4c;
	case 2896ULL: goto x86_l_b50;
	case 2898ULL: goto x86_l_b52;
	case 2901ULL: goto x86_l_b55;
	case 2904ULL: goto x86_l_b58;
	case 2907ULL: goto x86_l_b5b;
	case 2910ULL: goto x86_l_b5e;
	case 2915ULL: goto x86_l_b63;
	case 2918ULL: goto x86_l_b66;
	case 2921ULL: goto x86_l_b69;
	case 2927ULL: goto x86_l_b6f;
	case 2934ULL: goto x86_l_b76;
	case 2940ULL: goto x86_l_b7c;
	case 2942ULL: goto x86_l_b7e;
	case 2948ULL: goto x86_l_b84;
	case 2952ULL: goto x86_l_b88;
	case 2957ULL: goto x86_l_b8d;
	case 2960ULL: goto x86_l_b90;
	case 2964ULL: goto x86_l_b94;
	case 2967ULL: goto x86_l_b97;
	case 2972ULL: goto x86_l_b9c;
	case 2974ULL: goto x86_l_b9e;
	case 2979ULL: goto x86_l_ba3;
	case 2984ULL: goto x86_l_ba8;
	case 2989ULL: goto x86_l_bad;
	case 2994ULL: goto x86_l_bb2;
	case 2999ULL: goto x86_l_bb7;
	case 3004ULL: goto x86_l_bbc;
	case 3008ULL: goto x86_l_bc0;
	case 3014ULL: goto x86_l_bc6;
	case 3018ULL: goto x86_l_bca;
	case 3024ULL: goto x86_l_bd0;
	case 3028ULL: goto x86_l_bd4;
	case 3033ULL: goto x86_l_bd9;
	case 3038ULL: goto x86_l_bde;
	case 3043ULL: goto x86_l_be3;
	case 3046ULL: goto x86_l_be6;
	case 3048ULL: goto x86_l_be8;
	case 3053ULL: goto x86_l_bed;
	case 3056ULL: goto x86_l_bf0;
	case 3062ULL: goto x86_l_bf6;
	case 3067ULL: goto x86_l_bfb;
	case 3072ULL: goto x86_l_c00;
	case 3077ULL: goto x86_l_c05;
	case 3081ULL: goto x86_l_c09;
	case 3086ULL: goto x86_l_c0e;
	case 3091ULL: goto x86_l_c13;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3102ULL: goto x86_l_c1e;
	case 3107ULL: goto x86_l_c23;
	case 3112ULL: goto x86_l_c28;
	case 3114ULL: goto x86_l_c2a;
	case 3119ULL: goto x86_l_c2f;
	case 3126ULL: goto x86_l_c36;
	case 3131ULL: goto x86_l_c3b;
	case 3136ULL: goto x86_l_c40;
	case 3138ULL: goto x86_l_c42;
	case 3143ULL: goto x86_l_c47;
	case 3150ULL: goto x86_l_c4e;
	case 3155ULL: goto x86_l_c53;
	case 3160ULL: goto x86_l_c58;
	case 3162ULL: goto x86_l_c5a;
	case 3167ULL: goto x86_l_c5f;
	case 3174ULL: goto x86_l_c66;
	case 3179ULL: goto x86_l_c6b;
	case 3184ULL: goto x86_l_c70;
	case 3186ULL: goto x86_l_c72;
	case 3191ULL: goto x86_l_c77;
	case 3198ULL: goto x86_l_c7e;
	case 3203ULL: goto x86_l_c83;
	case 3208ULL: goto x86_l_c88;
	case 3210ULL: goto x86_l_c8a;
	case 3213ULL: goto x86_l_c8d;
	case 3217ULL: goto x86_l_c91;
	case 3224ULL: goto x86_l_c98;
	case 3232ULL: goto x86_l_ca0;
	case 3240ULL: goto x86_l_ca8;
	case 3248ULL: goto x86_l_cb0;
	case 3252ULL: goto x86_l_cb4;
	case 3255ULL: goto x86_l_cb7;
	case 3261ULL: goto x86_l_cbd;
	case 3264ULL: goto x86_l_cc0;
	case 3270ULL: goto x86_l_cc6;
	case 3274ULL: goto x86_l_cca;
	case 3279ULL: goto x86_l_ccf;
	case 3282ULL: goto x86_l_cd2;
	case 3287ULL: goto x86_l_cd7;
	case 3289ULL: goto x86_l_cd9;
	case 3294ULL: goto x86_l_cde;
	case 3297ULL: goto x86_l_ce1;
	case 3302ULL: goto x86_l_ce6;
	case 3305ULL: goto x86_l_ce9;
	case 3310ULL: goto x86_l_cee;
	case 3314ULL: goto x86_l_cf2;
	case 3320ULL: goto x86_l_cf8;
	case 3324ULL: goto x86_l_cfc;
	case 3330ULL: goto x86_l_d02;
	case 3338ULL: goto x86_l_d0a;
	case 3346ULL: goto x86_l_d12;
	case 3354ULL: goto x86_l_d1a;
	case 3362ULL: goto x86_l_d22;
	case 3370ULL: goto x86_l_d2a;
	case 3378ULL: goto x86_l_d32;
	case 3386ULL: goto x86_l_d3a;
	case 3394ULL: goto x86_l_d42;
	case 3402ULL: goto x86_l_d4a;
	case 3409ULL: goto x86_l_d51;
	case 3413ULL: goto x86_l_d55;
	case 3417ULL: goto x86_l_d59;
	case 3422ULL: goto x86_l_d5e;
	case 3427ULL: goto x86_l_d63;
	case 3429ULL: goto x86_l_d65;
	case 3432ULL: goto x86_l_d68;
	case 3438ULL: goto x86_l_d6e;
	case 3443ULL: goto x86_l_d73;
	case 3447ULL: goto x86_l_d77;
	case 3454ULL: goto x86_l_d7e;
	case 3459ULL: goto x86_l_d83;
	case 3464ULL: goto x86_l_d88;
	case 3467ULL: goto x86_l_d8b;
	case 3472ULL: goto x86_l_d90;
	default: return 0xffffffffffffffffULL;
	}
x86_l_71a:
	/* 0x71a: cmp    BYTE PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_71f:
	/* 0x71f: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_722:
	/* 0x722: mov    esi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_726:
	/* 0x726: mov    r15d,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4096ULL);
x86_l_72c:
	/* 0x72c: sub    r15d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_72f:
	/* 0x72f: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_731:
	/* 0x731: cmovle r15d,esi */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RSI, X86_WIDTH_32, X86_CC_LE);
x86_l_735:
	/* 0x735: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_738:
	/* 0x738: mov    r8d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4ULL);
x86_l_73e:
	/* 0x73e: je     2ff <generic_tracepoint_process_event_2+0x2ff> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 767ULL;
	}
x86_l_744:
	/* 0x744: mov    bpl,dl */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_8);
x86_l_747:
	/* 0x747: add    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_749:
	/* 0x749: mov    r8,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_74c:
	/* 0x74c: jmp    25d6 <generic_tracepoint_process_event_2+0x25d6> */
	return 9686ULL;
x86_l_751:
	/* 0x751: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_756:
	/* 0x756: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_75b:
	/* 0x75b: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_760:
	/* 0x760: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_765:
	/* 0x765: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_768:
	/* 0x768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76a:
	/* 0x76a: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_76f:
	/* 0x76f: je     857 <generic_tracepoint_process_event_2+0x857> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_857;
	}
x86_l_775:
	/* 0x775: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_77a:
	/* 0x77a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_77f:
	/* 0x77f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_782:
	/* 0x782: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_787:
	/* 0x787: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_78a:
	/* 0x78a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78c:
	/* 0x78c: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_790:
	/* 0x790: je     857 <generic_tracepoint_process_event_2+0x857> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_857;
	}
x86_l_796:
	/* 0x796: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_79b:
	/* 0x79b: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7a0:
	/* 0x7a0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a5:
	/* 0x7a5: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_7a8:
	/* 0x7a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7aa:
	/* 0x7aa: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_7ae:
	/* 0x7ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_7b3:
	/* 0x7b3: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7b8:
	/* 0x7b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_7bd:
	/* 0x7bd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_7c0:
	/* 0x7c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c2:
	/* 0x7c2: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7c7:
	/* 0x7c7: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7cc:
	/* 0x7cc: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_7d0:
	/* 0x7d0: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_7d3:
	/* 0x7d3: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7d7:
	/* 0x7d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d9:
	/* 0x7d9: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_7db:
	/* 0x7db: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7dd:
	/* 0x7dd: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_7e0:
	/* 0x7e0: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_7e5:
	/* 0x7e5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e8:
	/* 0x7e8: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_7ea:
	/* 0x7ea: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_7ee:
	/* 0x7ee: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_7f0:
	/* 0x7f0: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_7f3:
	/* 0x7f3: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7f6:
	/* 0x7f6: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_7f9:
	/* 0x7f9: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7fc:
	/* 0x7fc: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_801:
	/* 0x801: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_804:
	/* 0x804: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_807:
	/* 0x807: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_80d:
	/* 0x80d: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_814:
	/* 0x814: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_81a:
	/* 0x81a: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_81c:
	/* 0x81c: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_822:
	/* 0x822: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_826:
	/* 0x826: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_82b:
	/* 0x82b: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_82e:
	/* 0x82e: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_832:
	/* 0x832: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_835:
	/* 0x835: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_83a:
	/* 0x83a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83c:
	/* 0x83c: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_841:
	/* 0x841: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_846:
	/* 0x846: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_84b:
	/* 0x84b: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_850:
	/* 0x850: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_855:
	/* 0x855: jmp    8a8 <generic_tracepoint_process_event_2+0x8a8> */
	goto x86_l_8a8;
x86_l_857:
	/* 0x857: lea    rdx,[r15-0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551600ULL);
x86_l_85b:
	/* 0x85b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_860:
	/* 0x860: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_863:
	/* 0x863: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_868:
	/* 0x868: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86a:
	/* 0x86a: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_86f:
	/* 0x86f: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_873:
	/* 0x873: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_879:
	/* 0x879: add    r15,0xfffffffffffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551608ULL);
x86_l_87d:
	/* 0x87d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_882:
	/* 0x882: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_887:
	/* 0x887: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_88c:
	/* 0x88c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_88f:
	/* 0x88f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_891:
	/* 0x891: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_895:
	/* 0x895: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_89a:
	/* 0x89a: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_89e:
	/* 0x89e: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8a3:
	/* 0x8a3: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8a8:
	/* 0x8a8: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_8ad:
	/* 0x8ad: jne    8ba <generic_tracepoint_process_event_2+0x8ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8ba;
	}
x86_l_8af:
	/* 0x8af: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_8b4:
	/* 0x8b4: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_8ba:
	/* 0x8ba: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8bf:
	/* 0x8bf: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8c4:
	/* 0x8c4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8c9:
	/* 0x8c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8cb:
	/* 0x8cb: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_8d0:
	/* 0x8d0: je     a58 <generic_tracepoint_process_event_2+0xa58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a58;
	}
x86_l_8d6:
	/* 0x8d6: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8db:
	/* 0x8db: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8e0:
	/* 0x8e0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8e3:
	/* 0x8e3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8e8:
	/* 0x8e8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8eb:
	/* 0x8eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ed:
	/* 0x8ed: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f1:
	/* 0x8f1: je     a58 <generic_tracepoint_process_event_2+0xa58> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a58;
	}
x86_l_8f7:
	/* 0x8f7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8fc:
	/* 0x8fc: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_901:
	/* 0x901: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_906:
	/* 0x906: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_909:
	/* 0x909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90b:
	/* 0x90b: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_90f:
	/* 0x90f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_914:
	/* 0x914: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_919:
	/* 0x919: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_91e:
	/* 0x91e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_921:
	/* 0x921: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_923:
	/* 0x923: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_928:
	/* 0x928: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_92d:
	/* 0x92d: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_931:
	/* 0x931: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_934:
	/* 0x934: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_938:
	/* 0x938: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93a:
	/* 0x93a: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_93c:
	/* 0x93c: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_93e:
	/* 0x93e: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_941:
	/* 0x941: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_946:
	/* 0x946: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_949:
	/* 0x949: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_94b:
	/* 0x94b: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_94f:
	/* 0x94f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_951:
	/* 0x951: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_954:
	/* 0x954: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_957:
	/* 0x957: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_95a:
	/* 0x95a: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_95d:
	/* 0x95d: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_962:
	/* 0x962: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_965:
	/* 0x965: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_968:
	/* 0x968: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_96e:
	/* 0x96e: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_975:
	/* 0x975: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_97b:
	/* 0x97b: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_97d:
	/* 0x97d: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_983:
	/* 0x983: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_987:
	/* 0x987: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_98c:
	/* 0x98c: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_98f:
	/* 0x98f: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_993:
	/* 0x993: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_996:
	/* 0x996: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_99b:
	/* 0x99b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99d:
	/* 0x99d: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9a2:
	/* 0x9a2: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9a7:
	/* 0x9a7: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ac:
	/* 0x9ac: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b1:
	/* 0x9b1: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9b6:
	/* 0x9b6: jmp    aa9 <generic_tracepoint_process_event_2+0xaa9> */
	goto x86_l_aa9;
x86_l_9bb:
	/* 0x9bb: cmp    r12d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 32ULL);
x86_l_9bf:
	/* 0x9bf: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9c4:
	/* 0x9c4: jle    cee <generic_tracepoint_process_event_2+0xcee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_cee;
	}
x86_l_9ca:
	/* 0x9ca: lea    eax,[r12-0x21] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551583ULL);
x86_l_9cf:
	/* 0x9cf: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9d2:
	/* 0x9d2: jae    bbc <generic_tracepoint_process_event_2+0xbbc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_bbc;
	}
x86_l_9d8:
	/* 0x9d8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9dd:
	/* 0x9dd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9e2:
	/* 0x9e2: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_9e5:
	/* 0x9e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e7:
	/* 0x9e7: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_9ed:
	/* 0x9ed: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_9f2:
	/* 0x9f2: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_9f5:
	/* 0x9f5: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_9f9:
	/* 0x9f9: jg     d90 <generic_tracepoint_process_event_2+0xd90> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d90;
	}
x86_l_9ff:
	/* 0x9ff: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_a03:
	/* 0xa03: je     e72 <generic_tracepoint_process_event_2+0xe72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 3698ULL;
	}
x86_l_a09:
	/* 0xa09: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_a0d:
	/* 0xa0d: jne    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7459ULL;
	}
x86_l_a13:
	/* 0xa13: lea    rbp,[rax+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a1a:
	/* 0xa1a: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_a1c:
	/* 0xa1c: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_a1f:
	/* 0xa1f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a22:
	/* 0xa22: jle    149b <generic_tracepoint_process_event_2+0x149b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5275ULL;
	}
x86_l_a28:
	/* 0xa28: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a2b:
	/* 0xa2b: je     15ea <generic_tracepoint_process_event_2+0x15ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5610ULL;
	}
x86_l_a31:
	/* 0xa31: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_a34:
	/* 0xa34: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a37:
	/* 0xa37: je     15f6 <generic_tracepoint_process_event_2+0x15f6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5622ULL;
	}
x86_l_a3d:
	/* 0xa3d: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a40:
	/* 0xa40: jne    1a9c <generic_tracepoint_process_event_2+0x1a9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 6812ULL;
	}
x86_l_a46:
	/* 0xa46: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_a49:
	/* 0xa49: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_a4c:
	/* 0xa4c: add    rcx,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_a53:
	/* 0xa53: jmp    1612 <generic_tracepoint_process_event_2+0x1612> */
	return 5650ULL;
x86_l_a58:
	/* 0xa58: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a5c:
	/* 0xa5c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a61:
	/* 0xa61: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a64:
	/* 0xa64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a69:
	/* 0xa69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6b:
	/* 0xa6b: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a70:
	/* 0xa70: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_a74:
	/* 0xa74: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_a7a:
	/* 0xa7a: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a7e:
	/* 0xa7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a83:
	/* 0xa83: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a88:
	/* 0xa88: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a8d:
	/* 0xa8d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a90:
	/* 0xa90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a92:
	/* 0xa92: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a96:
	/* 0xa96: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a9b:
	/* 0xa9b: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a9f:
	/* 0xa9f: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aa4:
	/* 0xaa4: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa9:
	/* 0xaa9: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_aae:
	/* 0xaae: jne    abb <generic_tracepoint_process_event_2+0xabb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_abb;
	}
x86_l_ab0:
	/* 0xab0: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_ab5:
	/* 0xab5: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_abb:
	/* 0xabb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ac0:
	/* 0xac0: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ac5:
	/* 0xac5: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_aca:
	/* 0xaca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_acc:
	/* 0xacc: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_ad1:
	/* 0xad1: je     1297 <generic_tracepoint_process_event_2+0x1297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4759ULL;
	}
x86_l_ad7:
	/* 0xad7: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_adc:
	/* 0xadc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ae1:
	/* 0xae1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ae4:
	/* 0xae4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ae9:
	/* 0xae9: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_aec:
	/* 0xaec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aee:
	/* 0xaee: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af2:
	/* 0xaf2: je     1297 <generic_tracepoint_process_event_2+0x1297> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4759ULL;
	}
x86_l_af8:
	/* 0xaf8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_afd:
	/* 0xafd: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b02:
	/* 0xb02: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b07:
	/* 0xb07: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b0a:
	/* 0xb0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0c:
	/* 0xb0c: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_b10:
	/* 0xb10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b15:
	/* 0xb15: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b1a:
	/* 0xb1a: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_b1f:
	/* 0xb1f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b22:
	/* 0xb22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b24:
	/* 0xb24: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b29:
	/* 0xb29: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b2e:
	/* 0xb2e: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_b32:
	/* 0xb32: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b35:
	/* 0xb35: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b39:
	/* 0xb39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3b:
	/* 0xb3b: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_b3d:
	/* 0xb3d: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b3f:
	/* 0xb3f: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_b42:
	/* 0xb42: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_b47:
	/* 0xb47: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4a:
	/* 0xb4a: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_b4c:
	/* 0xb4c: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_b50:
	/* 0xb50: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_b52:
	/* 0xb52: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_b55:
	/* 0xb55: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b58:
	/* 0xb58: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_b5b:
	/* 0xb5b: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b5e:
	/* 0xb5e: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b63:
	/* 0xb63: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_b66:
	/* 0xb66: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_b69:
	/* 0xb69: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_b6f:
	/* 0xb6f: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_b76:
	/* 0xb76: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_b7c:
	/* 0xb7c: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_b7e:
	/* 0xb7e: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_b84:
	/* 0xb84: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b88:
	/* 0xb88: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_b8d:
	/* 0xb8d: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b90:
	/* 0xb90: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_b94:
	/* 0xb94: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_b97:
	/* 0xb97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b9c:
	/* 0xb9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9e:
	/* 0xb9e: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ba3:
	/* 0xba3: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ba8:
	/* 0xba8: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bad:
	/* 0xbad: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb2:
	/* 0xbb2: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bb7:
	/* 0xbb7: jmp    12e8 <generic_tracepoint_process_event_2+0x12e8> */
	return 4840ULL;
x86_l_bbc:
	/* 0xbbc: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_bc0:
	/* 0xbc0: je     11a2 <generic_tracepoint_process_event_2+0x11a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4514ULL;
	}
x86_l_bc6:
	/* 0xbc6: cmp    r12d,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 41ULL);
x86_l_bca:
	/* 0xbca: jne    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7459ULL;
	}
x86_l_bd0:
	/* 0xbd0: add    rbp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_bd4:
	/* 0xbd4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_bd9:
	/* 0xbd9: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bde:
	/* 0xbde: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_be3:
	/* 0xbe3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_be6:
	/* 0xbe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be8:
	/* 0xbe8: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bed:
	/* 0xbed: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_bf0:
	/* 0xbf0: je     15df <generic_tracepoint_process_event_2+0x15df> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5599ULL;
	}
x86_l_bf6:
	/* 0xbf6: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_bfb:
	/* 0xbfb: mov    QWORD PTR [r12+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c00:
	/* 0xc00: lea    rdi,[r12+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_c05:
	/* 0xc05: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c09:
	/* 0xc09: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c0e:
	/* 0xc0e: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c13:
	/* 0xc13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c15:
	/* 0xc15: lea    rdi,[r12+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_c1a:
	/* 0xc1a: lea    rdx,[r15+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_c1e:
	/* 0xc1e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c23:
	/* 0xc23: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_c28:
	/* 0xc28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c2a:
	/* 0xc2a: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c2f:
	/* 0xc2f: lea    rdx,[r15+0x23c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c36:
	/* 0xc36: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c3b:
	/* 0xc3b: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c40:
	/* 0xc40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c42:
	/* 0xc42: lea    rdi,[r12+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c47:
	/* 0xc47: lea    rdx,[r15+0x23e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 574ULL);
x86_l_c4e:
	/* 0xc4e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c53:
	/* 0xc53: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c58:
	/* 0xc58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5a:
	/* 0xc5a: lea    rdi,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c5f:
	/* 0xc5f: lea    rdx,[r15+0x20c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_c66:
	/* 0xc66: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c6b:
	/* 0xc6b: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c70:
	/* 0xc70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c72:
	/* 0xc72: lea    rdi,[r12+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c77:
	/* 0xc77: lea    rdx,[r15+0x208] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_c7e:
	/* 0xc7e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c83:
	/* 0xc83: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c88:
	/* 0xc88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8a:
	/* 0xc8a: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_c8d:
	/* 0xc8d: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_c91:
	/* 0xc91: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c98:
	/* 0xc98: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ca0:
	/* 0xca0: mov    QWORD PTR [rax+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ca8:
	/* 0xca8: mov    QWORD PTR [rax+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_cb0:
	/* 0xcb0: movzx  ecx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_cb4:
	/* 0xcb4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_cb7:
	/* 0xcb7: je     1577 <generic_tracepoint_process_event_2+0x1577> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5495ULL;
	}
x86_l_cbd:
	/* 0xcbd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cc0:
	/* 0xcc0: jne    15a2 <generic_tracepoint_process_event_2+0x15a2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5538ULL;
	}
x86_l_cc6:
	/* 0xcc6: lea    rdx,[r15+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cca:
	/* 0xcca: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ccf:
	/* 0xccf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_cd2:
	/* 0xcd2: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_cd7:
	/* 0xcd7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cd9:
	/* 0xcd9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cde:
	/* 0xcde: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ce1:
	/* 0xce1: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_ce6:
	/* 0xce6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_ce9:
	/* 0xce9: jmp    159b <generic_tracepoint_process_event_2+0x159b> */
	return 5531ULL;
x86_l_cee:
	/* 0xcee: cmp    r12d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 26ULL);
x86_l_cf2:
	/* 0xcf2: je     1223 <generic_tracepoint_process_event_2+0x1223> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4643ULL;
	}
x86_l_cf8:
	/* 0xcf8: cmp    r12d,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 27ULL);
x86_l_cfc:
	/* 0xcfc: jne    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7459ULL;
	}
x86_l_d02:
	/* 0xd02: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_d0a:
	/* 0xd0a: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_d12:
	/* 0xd12: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_d1a:
	/* 0xd1a: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_d22:
	/* 0xd22: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d2a:
	/* 0xd2a: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_d32:
	/* 0xd32: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_d3a:
	/* 0xd3a: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d42:
	/* 0xd42: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d4a:
	/* 0xd4a: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d51:
	/* 0xd51: add    rdi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_d55:
	/* 0xd55: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d59:
	/* 0xd59: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_d5e:
	/* 0xd5e: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_d63:
	/* 0xd63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d65:
	/* 0xd65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d68:
	/* 0xd68: js     128f <generic_tracepoint_process_event_2+0x128f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4751ULL;
	}
x86_l_d6e:
	/* 0xd6e: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d73:
	/* 0xd73: add    rdi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_d77:
	/* 0xd77: add    rbp,0x348 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 840ULL);
x86_l_d7e:
	/* 0xd7e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d83:
	/* 0xd83: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d88:
	/* 0xd88: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_d8b:
	/* 0xd8b: jmp    1066 <generic_tracepoint_process_event_2+0x1066> */
	return 4198ULL;
x86_l_d90:
	/* 0xd90: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
	return 3476ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 3476ULL: goto x86_l_d94;
	case 3482ULL: goto x86_l_d9a;
	case 3486ULL: goto x86_l_d9e;
	case 3492ULL: goto x86_l_da4;
	case 3498ULL: goto x86_l_daa;
	case 3503ULL: goto x86_l_daf;
	case 3506ULL: goto x86_l_db2;
	case 3509ULL: goto x86_l_db5;
	case 3512ULL: goto x86_l_db8;
	case 3514ULL: goto x86_l_dba;
	case 3517ULL: goto x86_l_dbd;
	case 3522ULL: goto x86_l_dc2;
	case 3526ULL: goto x86_l_dc6;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3551ULL: goto x86_l_ddf;
	case 3558ULL: goto x86_l_de6;
	case 3565ULL: goto x86_l_ded;
	case 3570ULL: goto x86_l_df2;
	case 3575ULL: goto x86_l_df7;
	case 3580ULL: goto x86_l_dfc;
	case 3583ULL: goto x86_l_dff;
	case 3585ULL: goto x86_l_e01;
	case 3590ULL: goto x86_l_e06;
	case 3595ULL: goto x86_l_e0b;
	case 3598ULL: goto x86_l_e0e;
	case 3603ULL: goto x86_l_e13;
	case 3605ULL: goto x86_l_e15;
	case 3613ULL: goto x86_l_e1d;
	case 3618ULL: goto x86_l_e22;
	case 3623ULL: goto x86_l_e27;
	case 3626ULL: goto x86_l_e2a;
	case 3628ULL: goto x86_l_e2c;
	case 3636ULL: goto x86_l_e34;
	case 3643ULL: goto x86_l_e3b;
	case 3648ULL: goto x86_l_e40;
	case 3653ULL: goto x86_l_e45;
	case 3655ULL: goto x86_l_e47;
	case 3662ULL: goto x86_l_e4e;
	case 3669ULL: goto x86_l_e55;
	case 3674ULL: goto x86_l_e5a;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3685ULL: goto x86_l_e65;
	case 3687ULL: goto x86_l_e67;
	case 3693ULL: goto x86_l_e6d;
	case 3698ULL: goto x86_l_e72;
	case 3701ULL: goto x86_l_e75;
	case 3704ULL: goto x86_l_e78;
	case 3711ULL: goto x86_l_e7f;
	case 3720ULL: goto x86_l_e88;
	case 3724ULL: goto x86_l_e8c;
	case 3730ULL: goto x86_l_e92;
	case 3734ULL: goto x86_l_e96;
	case 3736ULL: goto x86_l_e98;
	case 3740ULL: goto x86_l_e9c;
	case 3746ULL: goto x86_l_ea2;
	case 3750ULL: goto x86_l_ea6;
	case 3756ULL: goto x86_l_eac;
	case 3760ULL: goto x86_l_eb0;
	case 3766ULL: goto x86_l_eb6;
	case 3770ULL: goto x86_l_eba;
	case 3776ULL: goto x86_l_ec0;
	case 3783ULL: goto x86_l_ec7;
	case 3788ULL: goto x86_l_ecc;
	case 3792ULL: goto x86_l_ed0;
	case 3796ULL: goto x86_l_ed4;
	case 3804ULL: goto x86_l_edc;
	case 3808ULL: goto x86_l_ee0;
	case 3813ULL: goto x86_l_ee5;
	case 3816ULL: goto x86_l_ee8;
	case 3821ULL: goto x86_l_eed;
	case 3824ULL: goto x86_l_ef0;
	case 3826ULL: goto x86_l_ef2;
	case 3831ULL: goto x86_l_ef7;
	case 3835ULL: goto x86_l_efb;
	case 3840ULL: goto x86_l_f00;
	case 3845ULL: goto x86_l_f05;
	case 3847ULL: goto x86_l_f07;
	case 3852ULL: goto x86_l_f0c;
	case 3856ULL: goto x86_l_f10;
	case 3861ULL: goto x86_l_f15;
	case 3866ULL: goto x86_l_f1a;
	case 3868ULL: goto x86_l_f1c;
	case 3873ULL: goto x86_l_f21;
	case 3877ULL: goto x86_l_f25;
	case 3882ULL: goto x86_l_f2a;
	case 3887ULL: goto x86_l_f2f;
	case 3889ULL: goto x86_l_f31;
	case 3894ULL: goto x86_l_f36;
	case 3898ULL: goto x86_l_f3a;
	case 3903ULL: goto x86_l_f3f;
	case 3908ULL: goto x86_l_f44;
	case 3910ULL: goto x86_l_f46;
	case 3915ULL: goto x86_l_f4b;
	case 3919ULL: goto x86_l_f4f;
	case 3924ULL: goto x86_l_f54;
	case 3929ULL: goto x86_l_f59;
	case 3931ULL: goto x86_l_f5b;
	case 3936ULL: goto x86_l_f60;
	case 3940ULL: goto x86_l_f64;
	case 3945ULL: goto x86_l_f69;
	case 3950ULL: goto x86_l_f6e;
	case 3952ULL: goto x86_l_f70;
	case 3957ULL: goto x86_l_f75;
	case 3961ULL: goto x86_l_f79;
	case 3966ULL: goto x86_l_f7e;
	case 3971ULL: goto x86_l_f83;
	case 3973ULL: goto x86_l_f85;
	case 3982ULL: goto x86_l_f8e;
	case 3987ULL: goto x86_l_f93;
	case 3991ULL: goto x86_l_f97;
	case 3996ULL: goto x86_l_f9c;
	case 4001ULL: goto x86_l_fa1;
	case 4003ULL: goto x86_l_fa3;
	case 4008ULL: goto x86_l_fa8;
	case 4012ULL: goto x86_l_fac;
	case 4017ULL: goto x86_l_fb1;
	case 4022ULL: goto x86_l_fb6;
	case 4024ULL: goto x86_l_fb8;
	case 4029ULL: goto x86_l_fbd;
	case 4033ULL: goto x86_l_fc1;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4045ULL: goto x86_l_fcd;
	case 4049ULL: goto x86_l_fd1;
	case 4054ULL: goto x86_l_fd6;
	case 4057ULL: goto x86_l_fd9;
	case 4062ULL: goto x86_l_fde;
	case 4064ULL: goto x86_l_fe0;
	case 4071ULL: goto x86_l_fe7;
	case 4076ULL: goto x86_l_fec;
	case 4081ULL: goto x86_l_ff1;
	case 4086ULL: goto x86_l_ff6;
	case 4089ULL: goto x86_l_ff9;
	case 4091ULL: goto x86_l_ffb;
	case 4096ULL: goto x86_l_1000;
	case 4103ULL: goto x86_l_1007;
	case 4108ULL: goto x86_l_100c;
	case 4116ULL: goto x86_l_1014;
	case 4121ULL: goto x86_l_1019;
	case 4123ULL: goto x86_l_101b;
	case 4128ULL: goto x86_l_1020;
	case 4135ULL: goto x86_l_1027;
	case 4140ULL: goto x86_l_102c;
	case 4145ULL: goto x86_l_1031;
	case 4147ULL: goto x86_l_1033;
	case 4152ULL: goto x86_l_1038;
	case 4159ULL: goto x86_l_103f;
	case 4164ULL: goto x86_l_1044;
	case 4169ULL: goto x86_l_1049;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4182ULL: goto x86_l_1056;
	case 4187ULL: goto x86_l_105b;
	case 4190ULL: goto x86_l_105e;
	case 4195ULL: goto x86_l_1063;
	case 4198ULL: goto x86_l_1066;
	case 4200ULL: goto x86_l_1068;
	case 4206ULL: goto x86_l_106e;
	case 4211ULL: goto x86_l_1073;
	case 4218ULL: goto x86_l_107a;
	case 4223ULL: goto x86_l_107f;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4234ULL: goto x86_l_108a;
	case 4236ULL: goto x86_l_108c;
	case 4241ULL: goto x86_l_1091;
	case 4248ULL: goto x86_l_1098;
	case 4253ULL: goto x86_l_109d;
	case 4258ULL: goto x86_l_10a2;
	case 4260ULL: goto x86_l_10a4;
	case 4265ULL: goto x86_l_10a9;
	case 4272ULL: goto x86_l_10b0;
	case 4277ULL: goto x86_l_10b5;
	case 4282ULL: goto x86_l_10ba;
	case 4284ULL: goto x86_l_10bc;
	case 4288ULL: goto x86_l_10c0;
	case 4295ULL: goto x86_l_10c7;
	case 4300ULL: goto x86_l_10cc;
	case 4303ULL: goto x86_l_10cf;
	case 4308ULL: goto x86_l_10d4;
	case 4311ULL: goto x86_l_10d7;
	case 4313ULL: goto x86_l_10d9;
	case 4319ULL: goto x86_l_10df;
	case 4324ULL: goto x86_l_10e4;
	case 4328ULL: goto x86_l_10e8;
	case 4333ULL: goto x86_l_10ed;
	case 4336ULL: goto x86_l_10f0;
	case 4341ULL: goto x86_l_10f5;
	case 4344ULL: goto x86_l_10f8;
	case 4346ULL: goto x86_l_10fa;
	case 4351ULL: goto x86_l_10ff;
	case 4355ULL: goto x86_l_1103;
	case 4360ULL: goto x86_l_1108;
	case 4365ULL: goto x86_l_110d;
	case 4367ULL: goto x86_l_110f;
	case 4372ULL: goto x86_l_1114;
	case 4376ULL: goto x86_l_1118;
	case 4381ULL: goto x86_l_111d;
	case 4386ULL: goto x86_l_1122;
	case 4388ULL: goto x86_l_1124;
	case 4393ULL: goto x86_l_1129;
	case 4397ULL: goto x86_l_112d;
	case 4402ULL: goto x86_l_1132;
	case 4407ULL: goto x86_l_1137;
	case 4409ULL: goto x86_l_1139;
	case 4413ULL: goto x86_l_113d;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4425ULL: goto x86_l_1149;
	case 4430ULL: goto x86_l_114e;
	case 4433ULL: goto x86_l_1151;
	case 4435ULL: goto x86_l_1153;
	case 4441ULL: goto x86_l_1159;
	case 4446ULL: goto x86_l_115e;
	case 4451ULL: goto x86_l_1163;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4465ULL: goto x86_l_1171;
	case 4467ULL: goto x86_l_1173;
	case 4472ULL: goto x86_l_1178;
	case 4476ULL: goto x86_l_117c;
	case 4481ULL: goto x86_l_1181;
	case 4486ULL: goto x86_l_1186;
	case 4488ULL: goto x86_l_1188;
	case 4492ULL: goto x86_l_118c;
	case 4496ULL: goto x86_l_1190;
	case 4501ULL: goto x86_l_1195;
	case 4504ULL: goto x86_l_1198;
	case 4509ULL: goto x86_l_119d;
	case 4512ULL: goto x86_l_11a0;
	case 4514ULL: goto x86_l_11a2;
	case 4518ULL: goto x86_l_11a6;
	case 4523ULL: goto x86_l_11ab;
	case 4528ULL: goto x86_l_11b0;
	case 4531ULL: goto x86_l_11b3;
	case 4534ULL: goto x86_l_11b6;
	case 4539ULL: goto x86_l_11bb;
	case 4541ULL: goto x86_l_11bd;
	case 4545ULL: goto x86_l_11c1;
	case 4549ULL: goto x86_l_11c5;
	case 4553ULL: goto x86_l_11c9;
	case 4558ULL: goto x86_l_11ce;
	case 4563ULL: goto x86_l_11d3;
	case 4568ULL: goto x86_l_11d8;
	case 4570ULL: goto x86_l_11da;
	case 4574ULL: goto x86_l_11de;
	case 4579ULL: goto x86_l_11e3;
	case 4583ULL: goto x86_l_11e7;
	case 4588ULL: goto x86_l_11ec;
	case 4593ULL: goto x86_l_11f1;
	case 4598ULL: goto x86_l_11f6;
	case 4601ULL: goto x86_l_11f9;
	case 4603ULL: goto x86_l_11fb;
	case 4607ULL: goto x86_l_11ff;
	case 4612ULL: goto x86_l_1204;
	case 4617ULL: goto x86_l_1209;
	case 4622ULL: goto x86_l_120e;
	case 4625ULL: goto x86_l_1211;
	case 4630ULL: goto x86_l_1216;
	case 4632ULL: goto x86_l_1218;
	case 4638ULL: goto x86_l_121e;
	case 4643ULL: goto x86_l_1223;
	case 4651ULL: goto x86_l_122b;
	case 4659ULL: goto x86_l_1233;
	case 4667ULL: goto x86_l_123b;
	case 4675ULL: goto x86_l_1243;
	case 4683ULL: goto x86_l_124b;
	case 4691ULL: goto x86_l_1253;
	case 4699ULL: goto x86_l_125b;
	case 4707ULL: goto x86_l_1263;
	case 4715ULL: goto x86_l_126b;
	case 4722ULL: goto x86_l_1272;
	case 4727ULL: goto x86_l_1277;
	case 4732ULL: goto x86_l_127c;
	case 4737ULL: goto x86_l_1281;
	case 4740ULL: goto x86_l_1284;
	case 4742ULL: goto x86_l_1286;
	case 4745ULL: goto x86_l_1289;
	case 4751ULL: goto x86_l_128f;
	case 4754ULL: goto x86_l_1292;
	case 4759ULL: goto x86_l_1297;
	case 4763ULL: goto x86_l_129b;
	case 4768ULL: goto x86_l_12a0;
	case 4771ULL: goto x86_l_12a3;
	case 4776ULL: goto x86_l_12a8;
	case 4778ULL: goto x86_l_12aa;
	case 4783ULL: goto x86_l_12af;
	case 4787ULL: goto x86_l_12b3;
	case 4793ULL: goto x86_l_12b9;
	case 4797ULL: goto x86_l_12bd;
	case 4802ULL: goto x86_l_12c2;
	case 4807ULL: goto x86_l_12c7;
	case 4812ULL: goto x86_l_12cc;
	case 4815ULL: goto x86_l_12cf;
	case 4817ULL: goto x86_l_12d1;
	case 4821ULL: goto x86_l_12d5;
	case 4826ULL: goto x86_l_12da;
	case 4830ULL: goto x86_l_12de;
	case 4835ULL: goto x86_l_12e3;
	case 4840ULL: goto x86_l_12e8;
	case 4845ULL: goto x86_l_12ed;
	case 4847ULL: goto x86_l_12ef;
	case 4852ULL: goto x86_l_12f4;
	case 4858ULL: goto x86_l_12fa;
	case 4863ULL: goto x86_l_12ff;
	case 4868ULL: goto x86_l_1304;
	case 4873ULL: goto x86_l_1309;
	case 4875ULL: goto x86_l_130b;
	case 4880ULL: goto x86_l_1310;
	case 4886ULL: goto x86_l_1316;
	case 4891ULL: goto x86_l_131b;
	case 4896ULL: goto x86_l_1320;
	case 4899ULL: goto x86_l_1323;
	case 4904ULL: goto x86_l_1328;
	case 4907ULL: goto x86_l_132b;
	case 4909ULL: goto x86_l_132d;
	case 4913ULL: goto x86_l_1331;
	case 4919ULL: goto x86_l_1337;
	case 4924ULL: goto x86_l_133c;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4937ULL: goto x86_l_1349;
	case 4939ULL: goto x86_l_134b;
	case 4943ULL: goto x86_l_134f;
	case 4948ULL: goto x86_l_1354;
	case 4953ULL: goto x86_l_1359;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4973ULL: goto x86_l_136d;
	case 4977ULL: goto x86_l_1371;
	case 4980ULL: goto x86_l_1374;
	case 4984ULL: goto x86_l_1378;
	case 4986ULL: goto x86_l_137a;
	case 4988ULL: goto x86_l_137c;
	case 4990ULL: goto x86_l_137e;
	case 4993ULL: goto x86_l_1381;
	case 4998ULL: goto x86_l_1386;
	case 5001ULL: goto x86_l_1389;
	case 5003ULL: goto x86_l_138b;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5012ULL: goto x86_l_1394;
	case 5015ULL: goto x86_l_1397;
	case 5018ULL: goto x86_l_139a;
	case 5021ULL: goto x86_l_139d;
	case 5026ULL: goto x86_l_13a2;
	case 5029ULL: goto x86_l_13a5;
	case 5032ULL: goto x86_l_13a8;
	case 5038ULL: goto x86_l_13ae;
	case 5045ULL: goto x86_l_13b5;
	case 5051ULL: goto x86_l_13bb;
	case 5053ULL: goto x86_l_13bd;
	case 5059ULL: goto x86_l_13c3;
	case 5063ULL: goto x86_l_13c7;
	case 5068ULL: goto x86_l_13cc;
	case 5071ULL: goto x86_l_13cf;
	case 5075ULL: goto x86_l_13d3;
	case 5078ULL: goto x86_l_13d6;
	case 5083ULL: goto x86_l_13db;
	case 5085ULL: goto x86_l_13dd;
	case 5090ULL: goto x86_l_13e2;
	case 5095ULL: goto x86_l_13e7;
	case 5100ULL: goto x86_l_13ec;
	case 5105ULL: goto x86_l_13f1;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5122ULL: goto x86_l_1402;
	case 5126ULL: goto x86_l_1406;
	case 5128ULL: goto x86_l_1408;
	case 5136ULL: goto x86_l_1410;
	case 5140ULL: goto x86_l_1414;
	case 5145ULL: goto x86_l_1419;
	case 5150ULL: goto x86_l_141e;
	case 5155ULL: goto x86_l_1423;
	case 5160ULL: goto x86_l_1428;
	case 5169ULL: goto x86_l_1431;
	case 5174ULL: goto x86_l_1436;
	default: return 0xffffffffffffffffULL;
	}
x86_l_d94:
	/* 0xd94: je     ecc <generic_tracepoint_process_event_2+0xecc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ecc;
	}
x86_l_d9a:
	/* 0xd9a: cmp    r12d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 18ULL);
x86_l_d9e:
	/* 0xd9e: jne    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7459ULL;
	}
x86_l_da4:
	/* 0xda4: and    esi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_daa:
	/* 0xdaa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_daf:
	/* 0xdaf: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_db2:
	/* 0xdb2: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dba:
	/* 0xdba: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_dbd:
	/* 0xdbd: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_dc2:
	/* 0xdc2: cmp    r12d,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 19ULL);
x86_l_dc6:
	/* 0xdc6: je     115e <generic_tracepoint_process_event_2+0x115e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_115e;
	}
x86_l_dcc:
	/* 0xdcc: cmp    r12d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 20ULL);
x86_l_dd0:
	/* 0xdd0: jne    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7459ULL;
	}
x86_l_dd6:
	/* 0xdd6: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ddf:
	/* 0xddf: lea    r13,[rbp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_de6:
	/* 0xde6: lea    rdx,[rbp+0x110] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_ded:
	/* 0xded: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_df2:
	/* 0xdf2: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_df7:
	/* 0xdf7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dfc:
	/* 0xdfc: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_dff:
	/* 0xdff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e01:
	/* 0xe01: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_e06:
	/* 0xe06: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e0b:
	/* 0xe0b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_e0e:
	/* 0xe0e: mov    esi,0x80 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 128ULL);
x86_l_e13:
	/* 0xe13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e15:
	/* 0xe15: lea    rdi,[r12+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e1d:
	/* 0xe1d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e22:
	/* 0xe22: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e27:
	/* 0xe27: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_e2a:
	/* 0xe2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2c:
	/* 0xe2c: lea    rdi,[r12+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e34:
	/* 0xe34: lea    rdx,[rbp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_e3b:
	/* 0xe3b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e40:
	/* 0xe40: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e45:
	/* 0xe45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e47:
	/* 0xe47: add    r12,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_e4e:
	/* 0xe4e: add    rbp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_e55:
	/* 0xe55: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e5a:
	/* 0xe5a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_e5d:
	/* 0xe5d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e62:
	/* 0xe62: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e65:
	/* 0xe65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e67:
	/* 0xe67: mov    r8d,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 152ULL);
x86_l_e6d:
	/* 0xe6d: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_e72:
	/* 0xe72: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_e75:
	/* 0xe75: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e78:
	/* 0xe78: add    r15,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_e7f:
	/* 0xe7f: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e88:
	/* 0xe88: test   r13b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_8, 16ULL);
x86_l_e8c:
	/* 0xe8c: jne    13fb <generic_tracepoint_process_event_2+0x13fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_13fb;
	}
x86_l_e92:
	/* 0xe92: and    r13d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_e96:
	/* 0xe96: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e98:
	/* 0xe98: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_e9c:
	/* 0xe9c: jle    1557 <generic_tracepoint_process_event_2+0x1557> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		return 5463ULL;
	}
x86_l_ea2:
	/* 0xea2: cmp    r13d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 3ULL);
x86_l_ea6:
	/* 0xea6: je     1ca1 <generic_tracepoint_process_event_2+0x1ca1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7329ULL;
	}
x86_l_eac:
	/* 0xeac: cmp    r13d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4ULL);
x86_l_eb0:
	/* 0xeb0: je     1caa <generic_tracepoint_process_event_2+0x1caa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7338ULL;
	}
x86_l_eb6:
	/* 0xeb6: cmp    r13d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 5ULL);
x86_l_eba:
	/* 0xeba: jne    1cbe <generic_tracepoint_process_event_2+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_ec0:
	/* 0xec0: add    r12,0x5e70 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24176ULL);
x86_l_ec7:
	/* 0xec7: jmp    1cba <generic_tracepoint_process_event_2+0x1cba> */
	return 7354ULL;
x86_l_ecc:
	/* 0xecc: lea    r13,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ed0:
	/* 0xed0: lea    rax,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ed4:
	/* 0xed4: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_edc:
	/* 0xedc: lea    rdx,[rbp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee0:
	/* 0xee0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_ee5:
	/* 0xee5: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_ee8:
	/* 0xee8: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_eed:
	/* 0xeed: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_ef0:
	/* 0xef0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef2:
	/* 0xef2: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ef7:
	/* 0xef7: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_efb:
	/* 0xefb: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f00:
	/* 0xf00: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f05:
	/* 0xf05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f07:
	/* 0xf07: lea    rdi,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0c:
	/* 0xf0c: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f10:
	/* 0xf10: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f15:
	/* 0xf15: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f1a:
	/* 0xf1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f1c:
	/* 0xf1c: lea    rdi,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_f21:
	/* 0xf21: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_f25:
	/* 0xf25: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f2a:
	/* 0xf2a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f2f:
	/* 0xf2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f31:
	/* 0xf31: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f36:
	/* 0xf36: lea    rdx,[rbp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3a:
	/* 0xf3a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f3f:
	/* 0xf3f: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f44:
	/* 0xf44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f46:
	/* 0xf46: lea    rdi,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f4b:
	/* 0xf4b: lea    rdx,[rbp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_f4f:
	/* 0xf4f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f54:
	/* 0xf54: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f59:
	/* 0xf59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5b:
	/* 0xf5b: lea    rdi,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f60:
	/* 0xf60: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f64:
	/* 0xf64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f69:
	/* 0xf69: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f6e:
	/* 0xf6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f70:
	/* 0xf70: lea    rdi,[r12+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_f75:
	/* 0xf75: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f79:
	/* 0xf79: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f7e:
	/* 0xf7e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_f83:
	/* 0xf83: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f85:
	/* 0xf85: mov    DWORD PTR [r12+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_f8e:
	/* 0xf8e: lea    rdi,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f93:
	/* 0xf93: lea    rdx,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f97:
	/* 0xf97: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f9c:
	/* 0xf9c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_fa1:
	/* 0xfa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa3:
	/* 0xfa3: lea    rdi,[r12+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fa8:
	/* 0xfa8: lea    rdx,[rbp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fac:
	/* 0xfac: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fb1:
	/* 0xfb1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb6:
	/* 0xfb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb8:
	/* 0xfb8: lea    rdi,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fbd:
	/* 0xfbd: lea    rdx,[rbp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fc1:
	/* 0xfc1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fc6:
	/* 0xfc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fcb:
	/* 0xfcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fcd:
	/* 0xfcd: lea    rdx,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fd1:
	/* 0xfd1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fd6:
	/* 0xfd6: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_fd9:
	/* 0xfd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fde:
	/* 0xfde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe0:
	/* 0xfe0: add    rbp,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_fe7:
	/* 0xfe7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_fec:
	/* 0xfec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff1:
	/* 0xff1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ff6:
	/* 0xff6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_ff9:
	/* 0xff9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffb:
	/* 0xffb: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1000:
	/* 0x1000: lea    rdx,[r15+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1007:
	/* 0x1007: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_100c:
	/* 0x100c: mov    rdi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1014:
	/* 0x1014: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1019:
	/* 0x1019: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101b:
	/* 0x101b: lea    rdi,[r12+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1020:
	/* 0x1020: lea    rdx,[r15+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1027:
	/* 0x1027: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_102c:
	/* 0x102c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1031:
	/* 0x1031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1033:
	/* 0x1033: lea    rdi,[r12+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1038:
	/* 0x1038: lea    rdx,[r15+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_103f:
	/* 0x103f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1044:
	/* 0x1044: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1049:
	/* 0x1049: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104b:
	/* 0x104b: add    r12,0x4c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 76ULL);
x86_l_104f:
	/* 0x104f: add    r15,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1056:
	/* 0x1056: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_105b:
	/* 0x105b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_105e:
	/* 0x105e: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1063:
	/* 0x1063: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1066:
	/* 0x1066: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1068:
	/* 0x1068: mov    r8d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 80ULL);
x86_l_106e:
	/* 0x106e: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_1073:
	/* 0x1073: lea    rdx,[rbp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_107a:
	/* 0x107a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_107f:
	/* 0x107f: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1082:
	/* 0x1082: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1087:
	/* 0x1087: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_108a:
	/* 0x108a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108c:
	/* 0x108c: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1091:
	/* 0x1091: lea    rdx,[rbp+0xcc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_1098:
	/* 0x1098: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_109d:
	/* 0x109d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10a2:
	/* 0x10a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a4:
	/* 0x10a4: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a9:
	/* 0x10a9: lea    rdx,[rbp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_10b0:
	/* 0x10b0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10b5:
	/* 0x10b5: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10ba:
	/* 0x10ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bc:
	/* 0x10bc: add    r12,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_10c0:
	/* 0x10c0: add    rbp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_10c7:
	/* 0x10c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10cc:
	/* 0x10cc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_10cf:
	/* 0x10cf: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10d4:
	/* 0x10d4: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_10d7:
	/* 0x10d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d9:
	/* 0x10d9: mov    r8d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 16ULL);
x86_l_10df:
	/* 0x10df: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_10e4:
	/* 0x10e4: lea    rdx,[rbp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10e8:
	/* 0x10e8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_10ed:
	/* 0x10ed: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_10f0:
	/* 0x10f0: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_10f5:
	/* 0x10f5: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_10f8:
	/* 0x10f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fa:
	/* 0x10fa: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10ff:
	/* 0x10ff: lea    rdx,[rbp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1103:
	/* 0x1103: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1108:
	/* 0x1108: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_110d:
	/* 0x110d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_110f:
	/* 0x110f: lea    rdi,[r12+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1114:
	/* 0x1114: lea    rdx,[rbp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1118:
	/* 0x1118: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_111d:
	/* 0x111d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1122:
	/* 0x1122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1124:
	/* 0x1124: lea    rdi,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1129:
	/* 0x1129: lea    rdx,[rbp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_112d:
	/* 0x112d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1132:
	/* 0x1132: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1137:
	/* 0x1137: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1139:
	/* 0x1139: add    r12,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_113d:
	/* 0x113d: add    rbp,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1141:
	/* 0x1141: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1146:
	/* 0x1146: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1149:
	/* 0x1149: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_114e:
	/* 0x114e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1151:
	/* 0x1151: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1153:
	/* 0x1153: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_1159:
	/* 0x1159: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_115e:
	/* 0x115e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1163:
	/* 0x1163: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_1166:
	/* 0x1166: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_116b:
	/* 0x116b: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_116e:
	/* 0x116e: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1171:
	/* 0x1171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1173:
	/* 0x1173: lea    rdi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1178:
	/* 0x1178: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_117c:
	/* 0x117c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1181:
	/* 0x1181: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1186:
	/* 0x1186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1188:
	/* 0x1188: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_118c:
	/* 0x118c: add    rbp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_1190:
	/* 0x1190: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1195:
	/* 0x1195: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1198:
	/* 0x1198: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_119d:
	/* 0x119d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: jmp    1216 <generic_tracepoint_process_event_2+0x1216> */
	goto x86_l_1216;
x86_l_11a2:
	/* 0x11a2: lea    rdx,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11a6:
	/* 0x11a6: mov    ecx,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 113ULL);
x86_l_11ab:
	/* 0x11ab: lea    rax,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b0:
	/* 0x11b0: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_11b3:
	/* 0x11b3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_11b6:
	/* 0x11b6: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11bb:
	/* 0x11bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11bd:
	/* 0x11bd: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11c1:
	/* 0x11c1: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c5:
	/* 0x11c5: lea    rdx,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11c9:
	/* 0x11c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ce:
	/* 0x11ce: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d3:
	/* 0x11d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_11d8:
	/* 0x11d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11da:
	/* 0x11da: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11de:
	/* 0x11de: mov    DWORD PTR [r12+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11e3:
	/* 0x11e3: add    rbp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_11e7:
	/* 0x11e7: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_11ec:
	/* 0x11ec: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11f1:
	/* 0x11f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_11f6:
	/* 0x11f6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_11f9:
	/* 0x11f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11fb:
	/* 0x11fb: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_11ff:
	/* 0x11ff: mov    eax,0x73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 115ULL);
x86_l_1204:
	/* 0x1204: mov    edx,0x3e8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1000ULL);
x86_l_1209:
	/* 0x1209: add    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_120e:
	/* 0x120e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1211:
	/* 0x1211: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1216:
	/* 0x1216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1218:
	/* 0x1218: mov    r8d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 24ULL);
x86_l_121e:
	/* 0x121e: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_1223:
	/* 0x1223: mov    QWORD PTR [rdi+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_122b:
	/* 0x122b: mov    QWORD PTR [rdi+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1233:
	/* 0x1233: mov    QWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_123b:
	/* 0x123b: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1243:
	/* 0x1243: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_124b:
	/* 0x124b: mov    QWORD PTR [rdi+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1253:
	/* 0x1253: mov    QWORD PTR [rdi+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_125b:
	/* 0x125b: mov    QWORD PTR [rdi+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1263:
	/* 0x1263: mov    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_126b:
	/* 0x126b: mov    QWORD PTR [rdi],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1272:
	/* 0x1272: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1277:
	/* 0x1277: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_127c:
	/* 0x127c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1281:
	/* 0x1281: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1284:
	/* 0x1284: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1286:
	/* 0x1286: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1289:
	/* 0x1289: je     14c2 <generic_tracepoint_process_event_2+0x14c2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5314ULL;
	}
x86_l_128f:
	/* 0x128f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1292:
	/* 0x1292: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_1297:
	/* 0x1297: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_129b:
	/* 0x129b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12a0:
	/* 0x12a0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_12a3:
	/* 0x12a3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12a8:
	/* 0x12a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12aa:
	/* 0x12aa: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12af:
	/* 0x12af: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_12b3:
	/* 0x12b3: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_12b9:
	/* 0x12b9: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_12bd:
	/* 0x12bd: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12c2:
	/* 0x12c2: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12c7:
	/* 0x12c7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_12cc:
	/* 0x12cc: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12cf:
	/* 0x12cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d1:
	/* 0x12d1: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d5:
	/* 0x12d5: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12da:
	/* 0x12da: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12de:
	/* 0x12de: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12e3:
	/* 0x12e3: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12e8:
	/* 0x12e8: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_12ed:
	/* 0x12ed: jne    12fa <generic_tracepoint_process_event_2+0x12fa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_12fa;
	}
x86_l_12ef:
	/* 0x12ef: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_12f4:
	/* 0x12f4: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_12fa:
	/* 0x12fa: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_12ff:
	/* 0x12ff: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1304:
	/* 0x1304: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1309:
	/* 0x1309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130b:
	/* 0x130b: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_1310:
	/* 0x1310: je     1ae0 <generic_tracepoint_process_event_2+0x1ae0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6880ULL;
	}
x86_l_1316:
	/* 0x1316: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_131b:
	/* 0x131b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1320:
	/* 0x1320: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1323:
	/* 0x1323: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1328:
	/* 0x1328: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_132b:
	/* 0x132b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132d:
	/* 0x132d: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1331:
	/* 0x1331: je     1ae0 <generic_tracepoint_process_event_2+0x1ae0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 6880ULL;
	}
x86_l_1337:
	/* 0x1337: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_133c:
	/* 0x133c: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1341:
	/* 0x1341: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1346:
	/* 0x1346: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1349:
	/* 0x1349: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134b:
	/* 0x134b: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_134f:
	/* 0x134f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1354:
	/* 0x1354: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1359:
	/* 0x1359: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_135e:
	/* 0x135e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1361:
	/* 0x1361: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1363:
	/* 0x1363: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1368:
	/* 0x1368: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_136d:
	/* 0x136d: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1371:
	/* 0x1371: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1374:
	/* 0x1374: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1378:
	/* 0x1378: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137a:
	/* 0x137a: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_137c:
	/* 0x137c: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_137e:
	/* 0x137e: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1381:
	/* 0x1381: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1386:
	/* 0x1386: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1389:
	/* 0x1389: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_138b:
	/* 0x138b: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_138f:
	/* 0x138f: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1391:
	/* 0x1391: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1394:
	/* 0x1394: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1397:
	/* 0x1397: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_139a:
	/* 0x139a: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_139d:
	/* 0x139d: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13a2:
	/* 0x13a2: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_13a5:
	/* 0x13a5: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_13a8:
	/* 0x13a8: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_13ae:
	/* 0x13ae: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_13b5:
	/* 0x13b5: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_13bb:
	/* 0x13bb: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_13bd:
	/* 0x13bd: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_13c3:
	/* 0x13c3: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_13c7:
	/* 0x13c7: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_13cc:
	/* 0x13cc: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_13cf:
	/* 0x13cf: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_13d3:
	/* 0x13d3: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_13d6:
	/* 0x13d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13e2:
	/* 0x13e2: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13e7:
	/* 0x13e7: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13ec:
	/* 0x13ec: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13f1:
	/* 0x13f1: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13f6:
	/* 0x13f6: jmp    1b31 <generic_tracepoint_process_event_2+0x1b31> */
	return 6961ULL;
x86_l_13fb:
	/* 0x13fb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1400:
	/* 0x1400: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1402:
	/* 0x1402: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1406:
	/* 0x1406: jne    1414 <generic_tracepoint_process_event_2+0x1414> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1414;
	}
x86_l_1408:
	/* 0x1408: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1410:
	/* 0x1410: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1414:
	/* 0x1414: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1419:
	/* 0x1419: mov    rdx,QWORD PTR [r12+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_141e:
	/* 0x141e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1423:
	/* 0x1423: mov    QWORD PTR [rsp+0x18],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1428:
	/* 0x1428: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1431:
	/* 0x1431: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1436:
	/* 0x1436: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
	return 5179ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5179ULL: goto x86_l_143b;
	case 5184ULL: goto x86_l_1440;
	case 5191ULL: goto x86_l_1447;
	case 5196ULL: goto x86_l_144c;
	case 5201ULL: goto x86_l_1451;
	case 5203ULL: goto x86_l_1453;
	case 5205ULL: goto x86_l_1455;
	case 5208ULL: goto x86_l_1458;
	case 5214ULL: goto x86_l_145e;
	case 5216ULL: goto x86_l_1460;
	case 5220ULL: goto x86_l_1464;
	case 5227ULL: goto x86_l_146b;
	case 5237ULL: goto x86_l_1475;
	case 5242ULL: goto x86_l_147a;
	case 5247ULL: goto x86_l_147f;
	case 5254ULL: goto x86_l_1486;
	case 5257ULL: goto x86_l_1489;
	case 5259ULL: goto x86_l_148b;
	case 5262ULL: goto x86_l_148e;
	case 5268ULL: goto x86_l_1494;
	case 5270ULL: goto x86_l_1496;
	case 5275ULL: goto x86_l_149b;
	case 5278ULL: goto x86_l_149e;
	case 5281ULL: goto x86_l_14a1;
	case 5287ULL: goto x86_l_14a7;
	case 5290ULL: goto x86_l_14aa;
	case 5296ULL: goto x86_l_14b0;
	case 5299ULL: goto x86_l_14b3;
	case 5302ULL: goto x86_l_14b6;
	case 5309ULL: goto x86_l_14bd;
	case 5314ULL: goto x86_l_14c2;
	case 5319ULL: goto x86_l_14c7;
	case 5323ULL: goto x86_l_14cb;
	case 5328ULL: goto x86_l_14d0;
	case 5333ULL: goto x86_l_14d5;
	case 5338ULL: goto x86_l_14da;
	case 5340ULL: goto x86_l_14dc;
	case 5343ULL: goto x86_l_14df;
	case 5349ULL: goto x86_l_14e5;
	case 5354ULL: goto x86_l_14ea;
	case 5358ULL: goto x86_l_14ee;
	case 5363ULL: goto x86_l_14f3;
	case 5368ULL: goto x86_l_14f8;
	case 5373ULL: goto x86_l_14fd;
	case 5375ULL: goto x86_l_14ff;
	case 5380ULL: goto x86_l_1504;
	case 5384ULL: goto x86_l_1508;
	case 5389ULL: goto x86_l_150d;
	case 5394ULL: goto x86_l_1512;
	case 5399ULL: goto x86_l_1517;
	case 5404ULL: goto x86_l_151c;
	case 5406ULL: goto x86_l_151e;
	case 5410ULL: goto x86_l_1522;
	case 5415ULL: goto x86_l_1527;
	case 5420ULL: goto x86_l_152c;
	case 5425ULL: goto x86_l_1531;
	case 5428ULL: goto x86_l_1534;
	case 5430ULL: goto x86_l_1536;
	case 5433ULL: goto x86_l_1539;
	case 5435ULL: goto x86_l_153b;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5445ULL: goto x86_l_1545;
	case 5450ULL: goto x86_l_154a;
	case 5452ULL: goto x86_l_154c;
	case 5458ULL: goto x86_l_1552;
	case 5463ULL: goto x86_l_1557;
	case 5467ULL: goto x86_l_155b;
	case 5473ULL: goto x86_l_1561;
	case 5477ULL: goto x86_l_1565;
	case 5483ULL: goto x86_l_156b;
	case 5490ULL: goto x86_l_1572;
	case 5495ULL: goto x86_l_1577;
	case 5499ULL: goto x86_l_157b;
	case 5504ULL: goto x86_l_1580;
	case 5507ULL: goto x86_l_1583;
	case 5512ULL: goto x86_l_1588;
	case 5514ULL: goto x86_l_158a;
	case 5518ULL: goto x86_l_158e;
	case 5523ULL: goto x86_l_1593;
	case 5526ULL: goto x86_l_1596;
	case 5531ULL: goto x86_l_159b;
	case 5533ULL: goto x86_l_159d;
	case 5538ULL: goto x86_l_15a2;
	case 5542ULL: goto x86_l_15a6;
	case 5546ULL: goto x86_l_15aa;
	case 5550ULL: goto x86_l_15ae;
	case 5555ULL: goto x86_l_15b3;
	case 5560ULL: goto x86_l_15b8;
	case 5563ULL: goto x86_l_15bb;
	case 5566ULL: goto x86_l_15be;
	case 5568ULL: goto x86_l_15c0;
	case 5572ULL: goto x86_l_15c4;
	case 5577ULL: goto x86_l_15c9;
	case 5582ULL: goto x86_l_15ce;
	case 5585ULL: goto x86_l_15d1;
	case 5587ULL: goto x86_l_15d3;
	case 5592ULL: goto x86_l_15d8;
	case 5599ULL: goto x86_l_15df;
	case 5605ULL: goto x86_l_15e5;
	case 5610ULL: goto x86_l_15ea;
	case 5613ULL: goto x86_l_15ed;
	case 5620ULL: goto x86_l_15f4;
	case 5622ULL: goto x86_l_15f6;
	case 5625ULL: goto x86_l_15f9;
	case 5628ULL: goto x86_l_15fc;
	case 5635ULL: goto x86_l_1603;
	case 5637ULL: goto x86_l_1605;
	case 5640ULL: goto x86_l_1608;
	case 5643ULL: goto x86_l_160b;
	case 5650ULL: goto x86_l_1612;
	case 5653ULL: goto x86_l_1615;
	case 5657ULL: goto x86_l_1619;
	case 5663ULL: goto x86_l_161f;
	case 5666ULL: goto x86_l_1622;
	case 5672ULL: goto x86_l_1628;
	case 5677ULL: goto x86_l_162d;
	case 5682ULL: goto x86_l_1632;
	case 5687ULL: goto x86_l_1637;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5699ULL: goto x86_l_1643;
	case 5701ULL: goto x86_l_1645;
	case 5707ULL: goto x86_l_164b;
	case 5712ULL: goto x86_l_1650;
	case 5717ULL: goto x86_l_1655;
	case 5720ULL: goto x86_l_1658;
	case 5728ULL: goto x86_l_1660;
	case 5735ULL: goto x86_l_1667;
	case 5741ULL: goto x86_l_166d;
	case 5744ULL: goto x86_l_1670;
	case 5748ULL: goto x86_l_1674;
	case 5751ULL: goto x86_l_1677;
	case 5754ULL: goto x86_l_167a;
	case 5759ULL: goto x86_l_167f;
	case 5764ULL: goto x86_l_1684;
	case 5772ULL: goto x86_l_168c;
	case 5774ULL: goto x86_l_168e;
	case 5779ULL: goto x86_l_1693;
	case 5781ULL: goto x86_l_1695;
	case 5787ULL: goto x86_l_169b;
	case 5791ULL: goto x86_l_169f;
	case 5797ULL: goto x86_l_16a5;
	case 5802ULL: goto x86_l_16aa;
	case 5806ULL: goto x86_l_16ae;
	case 5811ULL: goto x86_l_16b3;
	case 5816ULL: goto x86_l_16b8;
	case 5821ULL: goto x86_l_16bd;
	case 5823ULL: goto x86_l_16bf;
	case 5828ULL: goto x86_l_16c4;
	case 5830ULL: goto x86_l_16c6;
	case 5836ULL: goto x86_l_16cc;
	case 5841ULL: goto x86_l_16d1;
	case 5846ULL: goto x86_l_16d6;
	case 5851ULL: goto x86_l_16db;
	case 5857ULL: goto x86_l_16e1;
	case 5863ULL: goto x86_l_16e7;
	case 5871ULL: goto x86_l_16ef;
	case 5874ULL: goto x86_l_16f2;
	case 5877ULL: goto x86_l_16f5;
	case 5882ULL: goto x86_l_16fa;
	case 5887ULL: goto x86_l_16ff;
	case 5892ULL: goto x86_l_1704;
	case 5894ULL: goto x86_l_1706;
	case 5899ULL: goto x86_l_170b;
	case 5901ULL: goto x86_l_170d;
	case 5907ULL: goto x86_l_1713;
	case 5912ULL: goto x86_l_1718;
	case 5920ULL: goto x86_l_1720;
	case 5924ULL: goto x86_l_1724;
	case 5930ULL: goto x86_l_172a;
	case 5935ULL: goto x86_l_172f;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5949ULL: goto x86_l_173d;
	case 5954ULL: goto x86_l_1742;
	case 5956ULL: goto x86_l_1744;
	case 5961ULL: goto x86_l_1749;
	case 5963ULL: goto x86_l_174b;
	case 5969ULL: goto x86_l_1751;
	case 5974ULL: goto x86_l_1756;
	case 5979ULL: goto x86_l_175b;
	case 5987ULL: goto x86_l_1763;
	case 5993ULL: goto x86_l_1769;
	case 5999ULL: goto x86_l_176f;
	case 6004ULL: goto x86_l_1774;
	case 6007ULL: goto x86_l_1777;
	case 6010ULL: goto x86_l_177a;
	case 6016ULL: goto x86_l_1780;
	case 6019ULL: goto x86_l_1783;
	case 6024ULL: goto x86_l_1788;
	case 6029ULL: goto x86_l_178d;
	case 6037ULL: goto x86_l_1795;
	case 6039ULL: goto x86_l_1797;
	case 6044ULL: goto x86_l_179c;
	case 6046ULL: goto x86_l_179e;
	case 6052ULL: goto x86_l_17a4;
	case 6060ULL: goto x86_l_17ac;
	case 6068ULL: goto x86_l_17b4;
	case 6072ULL: goto x86_l_17b8;
	case 6078ULL: goto x86_l_17be;
	case 6083ULL: goto x86_l_17c3;
	case 6087ULL: goto x86_l_17c7;
	case 6092ULL: goto x86_l_17cc;
	case 6097ULL: goto x86_l_17d1;
	case 6102ULL: goto x86_l_17d6;
	case 6104ULL: goto x86_l_17d8;
	case 6109ULL: goto x86_l_17dd;
	case 6111ULL: goto x86_l_17df;
	case 6117ULL: goto x86_l_17e5;
	case 6122ULL: goto x86_l_17ea;
	case 6127ULL: goto x86_l_17ef;
	case 6132ULL: goto x86_l_17f4;
	case 6138ULL: goto x86_l_17fa;
	case 6144ULL: goto x86_l_1800;
	case 6152ULL: goto x86_l_1808;
	case 6155ULL: goto x86_l_180b;
	case 6163ULL: goto x86_l_1813;
	case 6169ULL: goto x86_l_1819;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6182ULL: goto x86_l_1826;
	case 6187ULL: goto x86_l_182b;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6196ULL: goto x86_l_1834;
	case 6202ULL: goto x86_l_183a;
	case 6207ULL: goto x86_l_183f;
	case 6215ULL: goto x86_l_1847;
	case 6219ULL: goto x86_l_184b;
	case 6225ULL: goto x86_l_1851;
	case 6230ULL: goto x86_l_1856;
	case 6234ULL: goto x86_l_185a;
	case 6239ULL: goto x86_l_185f;
	case 6244ULL: goto x86_l_1864;
	case 6249ULL: goto x86_l_1869;
	case 6251ULL: goto x86_l_186b;
	case 6256ULL: goto x86_l_1870;
	case 6258ULL: goto x86_l_1872;
	case 6264ULL: goto x86_l_1878;
	case 6269ULL: goto x86_l_187d;
	case 6274ULL: goto x86_l_1882;
	case 6282ULL: goto x86_l_188a;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6299ULL: goto x86_l_189b;
	case 6307ULL: goto x86_l_18a3;
	case 6310ULL: goto x86_l_18a6;
	case 6316ULL: goto x86_l_18ac;
	case 6319ULL: goto x86_l_18af;
	case 6324ULL: goto x86_l_18b4;
	case 6329ULL: goto x86_l_18b9;
	case 6337ULL: goto x86_l_18c1;
	case 6339ULL: goto x86_l_18c3;
	case 6344ULL: goto x86_l_18c8;
	case 6346ULL: goto x86_l_18ca;
	case 6352ULL: goto x86_l_18d0;
	case 6360ULL: goto x86_l_18d8;
	case 6368ULL: goto x86_l_18e0;
	case 6372ULL: goto x86_l_18e4;
	case 6378ULL: goto x86_l_18ea;
	case 6383ULL: goto x86_l_18ef;
	case 6387ULL: goto x86_l_18f3;
	case 6392ULL: goto x86_l_18f8;
	case 6397ULL: goto x86_l_18fd;
	case 6402ULL: goto x86_l_1902;
	case 6404ULL: goto x86_l_1904;
	case 6409ULL: goto x86_l_1909;
	case 6411ULL: goto x86_l_190b;
	case 6417ULL: goto x86_l_1911;
	case 6422ULL: goto x86_l_1916;
	case 6427ULL: goto x86_l_191b;
	case 6432ULL: goto x86_l_1920;
	case 6438ULL: goto x86_l_1926;
	case 6444ULL: goto x86_l_192c;
	case 6452ULL: goto x86_l_1934;
	case 6455ULL: goto x86_l_1937;
	case 6458ULL: goto x86_l_193a;
	case 6464ULL: goto x86_l_1940;
	case 6467ULL: goto x86_l_1943;
	case 6472ULL: goto x86_l_1948;
	case 6477ULL: goto x86_l_194d;
	case 6482ULL: goto x86_l_1952;
	case 6484ULL: goto x86_l_1954;
	case 6489ULL: goto x86_l_1959;
	case 6491ULL: goto x86_l_195b;
	case 6497ULL: goto x86_l_1961;
	case 6502ULL: goto x86_l_1966;
	case 6510ULL: goto x86_l_196e;
	case 6514ULL: goto x86_l_1972;
	case 6520ULL: goto x86_l_1978;
	case 6525ULL: goto x86_l_197d;
	case 6529ULL: goto x86_l_1981;
	case 6534ULL: goto x86_l_1986;
	case 6539ULL: goto x86_l_198b;
	case 6544ULL: goto x86_l_1990;
	case 6546ULL: goto x86_l_1992;
	case 6551ULL: goto x86_l_1997;
	case 6553ULL: goto x86_l_1999;
	case 6559ULL: goto x86_l_199f;
	case 6564ULL: goto x86_l_19a4;
	case 6569ULL: goto x86_l_19a9;
	case 6576ULL: goto x86_l_19b0;
	case 6582ULL: goto x86_l_19b6;
	case 6587ULL: goto x86_l_19bb;
	case 6590ULL: goto x86_l_19be;
	case 6596ULL: goto x86_l_19c4;
	case 6599ULL: goto x86_l_19c7;
	case 6604ULL: goto x86_l_19cc;
	case 6609ULL: goto x86_l_19d1;
	case 6612ULL: goto x86_l_19d4;
	case 6614ULL: goto x86_l_19d6;
	case 6619ULL: goto x86_l_19db;
	case 6621ULL: goto x86_l_19dd;
	case 6627ULL: goto x86_l_19e3;
	case 6635ULL: goto x86_l_19eb;
	case 6640ULL: goto x86_l_19f0;
	case 6643ULL: goto x86_l_19f3;
	case 6648ULL: goto x86_l_19f8;
	case 6650ULL: goto x86_l_19fa;
	case 6654ULL: goto x86_l_19fe;
	case 6656ULL: goto x86_l_1a00;
	case 6664ULL: goto x86_l_1a08;
	case 6668ULL: goto x86_l_1a0c;
	case 6672ULL: goto x86_l_1a10;
	case 6676ULL: goto x86_l_1a14;
	case 6681ULL: goto x86_l_1a19;
	case 6686ULL: goto x86_l_1a1e;
	case 6691ULL: goto x86_l_1a23;
	case 6696ULL: goto x86_l_1a28;
	case 6701ULL: goto x86_l_1a2d;
	case 6706ULL: goto x86_l_1a32;
	case 6711ULL: goto x86_l_1a37;
	case 6718ULL: goto x86_l_1a3e;
	case 6723ULL: goto x86_l_1a43;
	case 6728ULL: goto x86_l_1a48;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6735ULL: goto x86_l_1a4f;
	case 6741ULL: goto x86_l_1a55;
	case 6743ULL: goto x86_l_1a57;
	case 6747ULL: goto x86_l_1a5b;
	case 6754ULL: goto x86_l_1a62;
	case 6764ULL: goto x86_l_1a6c;
	case 6769ULL: goto x86_l_1a71;
	case 6774ULL: goto x86_l_1a76;
	case 6781ULL: goto x86_l_1a7d;
	case 6784ULL: goto x86_l_1a80;
	case 6786ULL: goto x86_l_1a82;
	case 6789ULL: goto x86_l_1a85;
	case 6795ULL: goto x86_l_1a8b;
	case 6797ULL: goto x86_l_1a8d;
	case 6802ULL: goto x86_l_1a92;
	case 6807ULL: goto x86_l_1a97;
	case 6812ULL: goto x86_l_1a9c;
	case 6815ULL: goto x86_l_1a9f;
	case 6820ULL: goto x86_l_1aa4;
	case 6828ULL: goto x86_l_1aac;
	case 6832ULL: goto x86_l_1ab0;
	case 6838ULL: goto x86_l_1ab6;
	case 6840ULL: goto x86_l_1ab8;
	case 6842ULL: goto x86_l_1aba;
	case 6850ULL: goto x86_l_1ac2;
	case 6858ULL: goto x86_l_1aca;
	case 6863ULL: goto x86_l_1acf;
	case 6868ULL: goto x86_l_1ad4;
	case 6872ULL: goto x86_l_1ad8;
	case 6875ULL: goto x86_l_1adb;
	case 6880ULL: goto x86_l_1ae0;
	case 6884ULL: goto x86_l_1ae4;
	case 6889ULL: goto x86_l_1ae9;
	case 6892ULL: goto x86_l_1aec;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6904ULL: goto x86_l_1af8;
	case 6908ULL: goto x86_l_1afc;
	case 6914ULL: goto x86_l_1b02;
	case 6918ULL: goto x86_l_1b06;
	case 6923ULL: goto x86_l_1b0b;
	case 6928ULL: goto x86_l_1b10;
	case 6933ULL: goto x86_l_1b15;
	case 6936ULL: goto x86_l_1b18;
	case 6938ULL: goto x86_l_1b1a;
	case 6942ULL: goto x86_l_1b1e;
	default: return 0xffffffffffffffffULL;
	}
x86_l_143b:
	/* 0x143b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1440:
	/* 0x1440: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_1447:
	/* 0x1447: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_144c:
	/* 0x144c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1451:
	/* 0x1451: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1453:
	/* 0x1453: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1455:
	/* 0x1455: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1458:
	/* 0x1458: je     1c6a <generic_tracepoint_process_event_2+0x1c6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7274ULL;
	}
x86_l_145e:
	/* 0x145e: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1460:
	/* 0x1460: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1464:
	/* 0x1464: mov    WORD PTR [rsp+0x2],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934597ULL);
x86_l_146b:
	/* 0x146b: movabs rax,0x200000046 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934662ULL);
x86_l_1475:
	/* 0x1475: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_147a:
	/* 0x147a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147f:
	/* 0x147f: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1486:
	/* 0x1486: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1489:
	/* 0x1489: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148b:
	/* 0x148b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_148e:
	/* 0x148e: je     1c44 <generic_tracepoint_process_event_2+0x1c44> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7236ULL;
	}
x86_l_1494:
	/* 0x1494: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1496:
	/* 0x1496: jmp    1c6a <generic_tracepoint_process_event_2+0x1c6a> */
	return 7274ULL;
x86_l_149b:
	/* 0x149b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_149e:
	/* 0x149e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14a1:
	/* 0x14a1: je     1605 <generic_tracepoint_process_event_2+0x1605> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1605;
	}
x86_l_14a7:
	/* 0x14a7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_14aa:
	/* 0x14aa: jne    1a9c <generic_tracepoint_process_event_2+0x1a9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a9c;
	}
x86_l_14b0:
	/* 0x14b0: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_14b3:
	/* 0x14b3: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_14b6:
	/* 0x14b6: add    rcx,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_14bd:
	/* 0x14bd: jmp    1612 <generic_tracepoint_process_event_2+0x1612> */
	goto x86_l_1612;
x86_l_14c2:
	/* 0x14c2: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14c7:
	/* 0x14c7: lea    rdi,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14cb:
	/* 0x14cb: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_14d0:
	/* 0x14d0: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14d5:
	/* 0x14d5: mov    esi,0x3f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 63ULL);
x86_l_14da:
	/* 0x14da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14dc:
	/* 0x14dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14df:
	/* 0x14df: js     128f <generic_tracepoint_process_event_2+0x128f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		return 4751ULL;
	}
x86_l_14e5:
	/* 0x14e5: mov    r15,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_14ea:
	/* 0x14ea: lea    rdx,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ee:
	/* 0x14ee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_14f3:
	/* 0x14f3: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14f8:
	/* 0x14f8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_14fd:
	/* 0x14fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14ff:
	/* 0x14ff: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1504:
	/* 0x1504: lea    rdi,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1508:
	/* 0x1508: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_150d:
	/* 0x150d: mov    edx,0x348 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 840ULL);
x86_l_1512:
	/* 0x1512: add    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 104ULL);
x86_l_1517:
	/* 0x1517: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_151c:
	/* 0x151c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_151e:
	/* 0x151e: add    r15,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_1522:
	/* 0x1522: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1527:
	/* 0x1527: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_152c:
	/* 0x152c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1531:
	/* 0x1531: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1534:
	/* 0x1534: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1536:
	/* 0x1536: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1539:
	/* 0x1539: jne    154c <generic_tracepoint_process_event_2+0x154c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_154c;
	}
x86_l_153b:
	/* 0x153b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153d:
	/* 0x153d: cmp    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1542:
	/* 0x1542: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1545:
	/* 0x1545: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_154a:
	/* 0x154a: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154c:
	/* 0x154c: mov    r8d,0x50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 80ULL);
x86_l_1552:
	/* 0x1552: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_1557:
	/* 0x1557: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_155b:
	/* 0x155b: je     1cb3 <generic_tracepoint_process_event_2+0x1cb3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7347ULL;
	}
x86_l_1561:
	/* 0x1561: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1565:
	/* 0x1565: jne    1cbe <generic_tracepoint_process_event_2+0x1cbe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 7358ULL;
	}
x86_l_156b:
	/* 0x156b: add    r12,0x5e58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24152ULL);
x86_l_1572:
	/* 0x1572: jmp    1cba <generic_tracepoint_process_event_2+0x1cba> */
	return 7354ULL;
x86_l_1577:
	/* 0x1577: lea    rdx,[r15+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_157b:
	/* 0x157b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1580:
	/* 0x1580: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1583:
	/* 0x1583: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1588:
	/* 0x1588: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_158a:
	/* 0x158a: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_158e:
	/* 0x158e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1593:
	/* 0x1593: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1596:
	/* 0x1596: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_159b:
	/* 0x159b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159d:
	/* 0x159d: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15a2:
	/* 0x15a2: lea    rdi,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a6:
	/* 0x15a6: lea    r12,[r15+0xc] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15aa:
	/* 0x15aa: add    r15,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_15ae:
	/* 0x15ae: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15b3:
	/* 0x15b3: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15b8:
	/* 0x15b8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15bb:
	/* 0x15bb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15be:
	/* 0x15be: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15c0:
	/* 0x15c0: lea    rdi,[r15+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_15c4:
	/* 0x15c4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_15c9:
	/* 0x15c9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_15ce:
	/* 0x15ce: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_15d1:
	/* 0x15d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d3:
	/* 0x15d3: movzx  eax,WORD PTR [r15+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_15d8:
	/* 0x15d8: movbe  WORD PTR [r15+0x22],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_15df:
	/* 0x15df: mov    r8d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 64ULL);
x86_l_15e5:
	/* 0x15e5: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_15ea:
	/* 0x15ea: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15ed:
	/* 0x15ed: add    rcx,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_15f4:
	/* 0x15f4: jmp    1612 <generic_tracepoint_process_event_2+0x1612> */
	goto x86_l_1612;
x86_l_15f6:
	/* 0x15f6: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_15f9:
	/* 0x15f9: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_15fc:
	/* 0x15fc: add    rcx,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_1603:
	/* 0x1603: jmp    1612 <generic_tracepoint_process_event_2+0x1612> */
	goto x86_l_1612;
x86_l_1605:
	/* 0x1605: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1608:
	/* 0x1608: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: add    rcx,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_1612:
	/* 0x1612: mov    r12,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1615:
	/* 0x1615: test   sil,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 16ULL);
x86_l_1619:
	/* 0x1619: jne    19f0 <generic_tracepoint_process_event_2+0x19f0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19f0;
	}
x86_l_161f:
	/* 0x161f: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_1622:
	/* 0x1622: je     1ab8 <generic_tracepoint_process_event_2+0x1ab8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ab8;
	}
x86_l_1628:
	/* 0x1628: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_162d:
	/* 0x162d: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1632:
	/* 0x1632: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1637:
	/* 0x1637: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_163c:
	/* 0x163c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163e:
	/* 0x163e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1643:
	/* 0x1643: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1645:
	/* 0x1645: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_164b:
	/* 0x164b: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1650:
	/* 0x1650: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1655:
	/* 0x1655: mov    rax,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1660:
	/* 0x1660: cmp    rdx,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 4094ULL);
x86_l_1667:
	/* 0x1667: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_166d:
	/* 0x166d: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1670:
	/* 0x1670: add    r13,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_1674:
	/* 0x1674: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1677:
	/* 0x1677: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_167a:
	/* 0x167a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_167f:
	/* 0x167f: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1684:
	/* 0x1684: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_168c:
	/* 0x168c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168e:
	/* 0x168e: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1693:
	/* 0x1693: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1695:
	/* 0x1695: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_169b:
	/* 0x169b: cmp    r12,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 1ULL);
x86_l_169f:
	/* 0x169f: je     1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac2;
	}
x86_l_16a5:
	/* 0x16a5: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_16aa:
	/* 0x16aa: lea    rdx,[rax+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ae:
	/* 0x16ae: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16b3:
	/* 0x16b3: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16b8:
	/* 0x16b8: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_16bd:
	/* 0x16bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bf:
	/* 0x16bf: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_16c4:
	/* 0x16c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16c6:
	/* 0x16c6: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_16cc:
	/* 0x16cc: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16d1:
	/* 0x16d1: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_16d6:
	/* 0x16d6: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16db:
	/* 0x16db: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_16e1:
	/* 0x16e1: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_16e7:
	/* 0x16e7: add    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_16ef:
	/* 0x16ef: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_16f2:
	/* 0x16f2: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16f5:
	/* 0x16f5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_16fa:
	/* 0x16fa: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16ff:
	/* 0x16ff: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1704:
	/* 0x1704: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1706:
	/* 0x1706: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_170b:
	/* 0x170b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_170d:
	/* 0x170d: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_1713:
	/* 0x1713: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1718:
	/* 0x1718: add    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_1720:
	/* 0x1720: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_1724:
	/* 0x1724: jb     1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ac2;
	}
x86_l_172a:
	/* 0x172a: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_172f:
	/* 0x172f: lea    rdx,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1733:
	/* 0x1733: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1738:
	/* 0x1738: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_173d:
	/* 0x173d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1742:
	/* 0x1742: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1744:
	/* 0x1744: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1749:
	/* 0x1749: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174b:
	/* 0x174b: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_1751:
	/* 0x1751: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1756:
	/* 0x1756: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_175b:
	/* 0x175b: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1763:
	/* 0x1763: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_1769:
	/* 0x1769: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_176f:
	/* 0x176f: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1774:
	/* 0x1774: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1777:
	/* 0x1777: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_177a:
	/* 0x177a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1780:
	/* 0x1780: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1783:
	/* 0x1783: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1788:
	/* 0x1788: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_178d:
	/* 0x178d: mov    rsi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1795:
	/* 0x1795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1797:
	/* 0x1797: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_179c:
	/* 0x179c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_179e:
	/* 0x179e: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_17a4:
	/* 0x17a4: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_17ac:
	/* 0x17ac: add    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_17b4:
	/* 0x17b4: cmp    r12,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 3ULL);
x86_l_17b8:
	/* 0x17b8: je     1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac2;
	}
x86_l_17be:
	/* 0x17be: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_17c3:
	/* 0x17c3: lea    rdx,[rax+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17c7:
	/* 0x17c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17cc:
	/* 0x17cc: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17d1:
	/* 0x17d1: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17d6:
	/* 0x17d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d8:
	/* 0x17d8: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_17dd:
	/* 0x17dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17df:
	/* 0x17df: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_17e5:
	/* 0x17e5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17ea:
	/* 0x17ea: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_17ef:
	/* 0x17ef: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_17f4:
	/* 0x17f4: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_17fa:
	/* 0x17fa: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_1800:
	/* 0x1800: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1808:
	/* 0x1808: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_180b:
	/* 0x180b: mov    QWORD PTR [rsp+0x88],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1813:
	/* 0x1813: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1819:
	/* 0x1819: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_181c:
	/* 0x181c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1821:
	/* 0x1821: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1826:
	/* 0x1826: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_182b:
	/* 0x182b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182d:
	/* 0x182d: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1832:
	/* 0x1832: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1834:
	/* 0x1834: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_183a:
	/* 0x183a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_183f:
	/* 0x183f: add    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_1847:
	/* 0x1847: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_184b:
	/* 0x184b: jb     1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ac2;
	}
x86_l_1851:
	/* 0x1851: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1856:
	/* 0x1856: lea    rdx,[rax+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_185a:
	/* 0x185a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_185f:
	/* 0x185f: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1864:
	/* 0x1864: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1869:
	/* 0x1869: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186b:
	/* 0x186b: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1870:
	/* 0x1870: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1872:
	/* 0x1872: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_1878:
	/* 0x1878: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_187d:
	/* 0x187d: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_1882:
	/* 0x1882: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_188a:
	/* 0x188a: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_1890:
	/* 0x1890: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_1896:
	/* 0x1896: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_189b:
	/* 0x189b: add    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_18a3:
	/* 0x18a3: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_18a6:
	/* 0x18a6: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_18ac:
	/* 0x18ac: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18af:
	/* 0x18af: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18b4:
	/* 0x18b4: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18b9:
	/* 0x18b9: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_18c1:
	/* 0x18c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c3:
	/* 0x18c3: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_18c8:
	/* 0x18c8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18ca:
	/* 0x18ca: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_18d0:
	/* 0x18d0: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_18d8:
	/* 0x18d8: add    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_18e0:
	/* 0x18e0: cmp    r12,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 5ULL);
x86_l_18e4:
	/* 0x18e4: je     1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1ac2;
	}
x86_l_18ea:
	/* 0x18ea: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18ef:
	/* 0x18ef: lea    rdx,[rax+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18f3:
	/* 0x18f3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18f8:
	/* 0x18f8: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18fd:
	/* 0x18fd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1902:
	/* 0x1902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1904:
	/* 0x1904: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1909:
	/* 0x1909: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_190b:
	/* 0x190b: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_1911:
	/* 0x1911: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1916:
	/* 0x1916: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_191b:
	/* 0x191b: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1920:
	/* 0x1920: cmp    rax,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4094ULL);
x86_l_1926:
	/* 0x1926: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_192c:
	/* 0x192c: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1934:
	/* 0x1934: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1937:
	/* 0x1937: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_193a:
	/* 0x193a: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_1940:
	/* 0x1940: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1943:
	/* 0x1943: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1948:
	/* 0x1948: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_194d:
	/* 0x194d: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1952:
	/* 0x1952: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1954:
	/* 0x1954: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1959:
	/* 0x1959: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195b:
	/* 0x195b: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_1961:
	/* 0x1961: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1966:
	/* 0x1966: add    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_196e:
	/* 0x196e: cmp    r12,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 7ULL);
x86_l_1972:
	/* 0x1972: jb     1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ac2;
	}
x86_l_1978:
	/* 0x1978: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_197d:
	/* 0x197d: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_1981:
	/* 0x1981: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1986:
	/* 0x1986: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198b:
	/* 0x198b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1990:
	/* 0x1990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1992:
	/* 0x1992: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_1997:
	/* 0x1997: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1999:
	/* 0x1999: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_199f:
	/* 0x199f: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19a4:
	/* 0x19a4: mov    ecx,0xfffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967293ULL);
x86_l_19a9:
	/* 0x19a9: cmp    r12,0xffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 4094ULL);
x86_l_19b0:
	/* 0x19b0: ja     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a92;
	}
x86_l_19b6:
	/* 0x19b6: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_19bb:
	/* 0x19bb: add    rdi,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19be:
	/* 0x19be: and    edi,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_19c4:
	/* 0x19c4: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19c7:
	/* 0x19c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_19cc:
	/* 0x19cc: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19d1:
	/* 0x19d1: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_19d4:
	/* 0x19d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d6:
	/* 0x19d6: mov    ecx,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967294ULL);
x86_l_19db:
	/* 0x19db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19dd:
	/* 0x19dd: js     1a92 <generic_tracepoint_process_event_2+0x1a92> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1a92;
	}
x86_l_19e3:
	/* 0x19e3: add    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 128ULL);
x86_l_19eb:
	/* 0x19eb: jmp    1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	goto x86_l_1ac2;
x86_l_19f0:
	/* 0x19f0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_19f3:
	/* 0x19f3: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_19f8:
	/* 0x19f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19fa:
	/* 0x19fa: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_19fe:
	/* 0x19fe: jne    1a0c <generic_tracepoint_process_event_2+0x1a0c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a0c;
	}
x86_l_1a00:
	/* 0x1a00: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1a08:
	/* 0x1a08: mov    rax,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a10:
	/* 0x1a10: mov    rdx,QWORD PTR [r13+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a14:
	/* 0x1a14: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a19:
	/* 0x1a19: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a23:
	/* 0x1a23: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a28:
	/* 0x1a28: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a2d:
	/* 0x1a2d: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a37:
	/* 0x1a37: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_1a3e:
	/* 0x1a3e: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a43:
	/* 0x1a43: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a48:
	/* 0x1a48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a4a:
	/* 0x1a4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a4c:
	/* 0x1a4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a4f:
	/* 0x1a4f: je     1c96 <generic_tracepoint_process_event_2+0x1c96> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7318ULL;
	}
x86_l_1a55:
	/* 0x1a55: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1a57:
	/* 0x1a57: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    WORD PTR [rsp+0x2],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8589934597ULL);
x86_l_1a62:
	/* 0x1a62: movabs rax,0x200000057 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934679ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    QWORD PTR [rsp+0x4],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a71:
	/* 0x1a71: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a76:
	/* 0x1a76: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1a7d:
	/* 0x1a7d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a80:
	/* 0x1a80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a82:
	/* 0x1a82: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a85:
	/* 0x1a85: je     1c76 <generic_tracepoint_process_event_2+0x1c76> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 7286ULL;
	}
x86_l_1a8b:
	/* 0x1a8b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a8d:
	/* 0x1a8d: jmp    1c96 <generic_tracepoint_process_event_2+0x1c96> */
	return 7318ULL;
x86_l_1a92:
	/* 0x1a92: mov    DWORD PTR [rbp+r15*1+0x0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1a97:
	/* 0x1a97: jmp    1d1d <generic_tracepoint_process_event_2+0x1d1d> */
	return 7453ULL;
x86_l_1a9c:
	/* 0x1a9c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a9f:
	/* 0x1a9f: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1aa4:
	/* 0x1aa4: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1aac:
	/* 0x1aac: test   sil,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_8, 16ULL);
x86_l_1ab0:
	/* 0x1ab0: jne    19f3 <generic_tracepoint_process_event_2+0x19f3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19f3;
	}
x86_l_1ab6:
	/* 0x1ab6: jmp    1ac2 <generic_tracepoint_process_event_2+0x1ac2> */
	goto x86_l_1ac2;
x86_l_1ab8:
	/* 0x1ab8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aba:
	/* 0x1aba: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ac2:
	/* 0x1ac2: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1aca:
	/* 0x1aca: mov    DWORD PTR [rbp+r15*1+0x0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1acf:
	/* 0x1acf: mov    DWORD PTR [rbp+r15*1+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_1ad4:
	/* 0x1ad4: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_1adb:
	/* 0x1adb: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	return 7459ULL;
x86_l_1ae0:
	/* 0x1ae0: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1aec:
	/* 0x1aec: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1af1:
	/* 0x1af1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af3:
	/* 0x1af3: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1af8:
	/* 0x1af8: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1afc:
	/* 0x1afc: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_1b02:
	/* 0x1b02: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b06:
	/* 0x1b06: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b0b:
	/* 0x1b0b: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b10:
	/* 0x1b10: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b15:
	/* 0x1b15: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b18:
	/* 0x1b18: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1a:
	/* 0x1b1a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
	return 6947ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 6947ULL: goto x86_l_1b23;
	case 6951ULL: goto x86_l_1b27;
	case 6956ULL: goto x86_l_1b2c;
	case 6961ULL: goto x86_l_1b31;
	case 6966ULL: goto x86_l_1b36;
	case 6968ULL: goto x86_l_1b38;
	case 6973ULL: goto x86_l_1b3d;
	case 6979ULL: goto x86_l_1b43;
	case 6984ULL: goto x86_l_1b48;
	case 6989ULL: goto x86_l_1b4d;
	case 6994ULL: goto x86_l_1b52;
	case 6996ULL: goto x86_l_1b54;
	case 7001ULL: goto x86_l_1b59;
	case 7007ULL: goto x86_l_1b5f;
	case 7012ULL: goto x86_l_1b64;
	case 7017ULL: goto x86_l_1b69;
	case 7020ULL: goto x86_l_1b6c;
	case 7025ULL: goto x86_l_1b71;
	case 7028ULL: goto x86_l_1b74;
	case 7030ULL: goto x86_l_1b76;
	case 7034ULL: goto x86_l_1b7a;
	case 7040ULL: goto x86_l_1b80;
	case 7045ULL: goto x86_l_1b85;
	case 7050ULL: goto x86_l_1b8a;
	case 7055ULL: goto x86_l_1b8f;
	case 7058ULL: goto x86_l_1b92;
	case 7060ULL: goto x86_l_1b94;
	case 7064ULL: goto x86_l_1b98;
	case 7069ULL: goto x86_l_1b9d;
	case 7074ULL: goto x86_l_1ba2;
	case 7079ULL: goto x86_l_1ba7;
	case 7082ULL: goto x86_l_1baa;
	case 7084ULL: goto x86_l_1bac;
	case 7089ULL: goto x86_l_1bb1;
	case 7094ULL: goto x86_l_1bb6;
	case 7098ULL: goto x86_l_1bba;
	case 7101ULL: goto x86_l_1bbd;
	case 7105ULL: goto x86_l_1bc1;
	case 7107ULL: goto x86_l_1bc3;
	case 7109ULL: goto x86_l_1bc5;
	case 7111ULL: goto x86_l_1bc7;
	case 7114ULL: goto x86_l_1bca;
	case 7119ULL: goto x86_l_1bcf;
	case 7122ULL: goto x86_l_1bd2;
	case 7124ULL: goto x86_l_1bd4;
	case 7128ULL: goto x86_l_1bd8;
	case 7130ULL: goto x86_l_1bda;
	case 7133ULL: goto x86_l_1bdd;
	case 7136ULL: goto x86_l_1be0;
	case 7139ULL: goto x86_l_1be3;
	case 7142ULL: goto x86_l_1be6;
	case 7147ULL: goto x86_l_1beb;
	case 7150ULL: goto x86_l_1bee;
	case 7153ULL: goto x86_l_1bf1;
	case 7159ULL: goto x86_l_1bf7;
	case 7166ULL: goto x86_l_1bfe;
	case 7172ULL: goto x86_l_1c04;
	case 7174ULL: goto x86_l_1c06;
	case 7180ULL: goto x86_l_1c0c;
	case 7184ULL: goto x86_l_1c10;
	case 7189ULL: goto x86_l_1c15;
	case 7192ULL: goto x86_l_1c18;
	case 7196ULL: goto x86_l_1c1c;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7206ULL: goto x86_l_1c26;
	case 7211ULL: goto x86_l_1c2b;
	case 7216ULL: goto x86_l_1c30;
	case 7221ULL: goto x86_l_1c35;
	case 7226ULL: goto x86_l_1c3a;
	case 7231ULL: goto x86_l_1c3f;
	case 7236ULL: goto x86_l_1c44;
	case 7247ULL: goto x86_l_1c4f;
	case 7252ULL: goto x86_l_1c54;
	case 7259ULL: goto x86_l_1c5b;
	case 7262ULL: goto x86_l_1c5e;
	case 7270ULL: goto x86_l_1c66;
	case 7272ULL: goto x86_l_1c68;
	case 7274ULL: goto x86_l_1c6a;
	case 7281ULL: goto x86_l_1c71;
	case 7286ULL: goto x86_l_1c76;
	case 7294ULL: goto x86_l_1c7e;
	case 7299ULL: goto x86_l_1c83;
	case 7306ULL: goto x86_l_1c8a;
	case 7309ULL: goto x86_l_1c8d;
	case 7314ULL: goto x86_l_1c92;
	case 7316ULL: goto x86_l_1c94;
	case 7318ULL: goto x86_l_1c96;
	case 7327ULL: goto x86_l_1c9f;
	case 7329ULL: goto x86_l_1ca1;
	case 7336ULL: goto x86_l_1ca8;
	case 7338ULL: goto x86_l_1caa;
	case 7345ULL: goto x86_l_1cb1;
	case 7347ULL: goto x86_l_1cb3;
	case 7354ULL: goto x86_l_1cba;
	case 7358ULL: goto x86_l_1cbe;
	case 7363ULL: goto x86_l_1cc3;
	case 7368ULL: goto x86_l_1cc8;
	case 7373ULL: goto x86_l_1ccd;
	case 7378ULL: goto x86_l_1cd2;
	case 7383ULL: goto x86_l_1cd7;
	case 7385ULL: goto x86_l_1cd9;
	case 7390ULL: goto x86_l_1cde;
	case 7397ULL: goto x86_l_1ce5;
	case 7403ULL: goto x86_l_1ceb;
	case 7407ULL: goto x86_l_1cef;
	case 7411ULL: goto x86_l_1cf3;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7424ULL: goto x86_l_1d00;
	case 7426ULL: goto x86_l_1d02;
	case 7428ULL: goto x86_l_1d04;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7437ULL: goto x86_l_1d0d;
	case 7441ULL: goto x86_l_1d11;
	case 7444ULL: goto x86_l_1d14;
	case 7446ULL: goto x86_l_1d16;
	case 7453ULL: goto x86_l_1d1d;
	case 7459ULL: goto x86_l_1d23;
	case 7463ULL: goto x86_l_1d27;
	case 7468ULL: goto x86_l_1d2c;
	case 7472ULL: goto x86_l_1d30;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7485ULL: goto x86_l_1d3d;
	case 7487ULL: goto x86_l_1d3f;
	case 7492ULL: goto x86_l_1d44;
	case 7496ULL: goto x86_l_1d48;
	case 7502ULL: goto x86_l_1d4e;
	case 7506ULL: goto x86_l_1d52;
	case 7511ULL: goto x86_l_1d57;
	case 7516ULL: goto x86_l_1d5c;
	case 7521ULL: goto x86_l_1d61;
	case 7524ULL: goto x86_l_1d64;
	case 7526ULL: goto x86_l_1d66;
	case 7530ULL: goto x86_l_1d6a;
	case 7535ULL: goto x86_l_1d6f;
	case 7539ULL: goto x86_l_1d73;
	case 7544ULL: goto x86_l_1d78;
	case 7549ULL: goto x86_l_1d7d;
	case 7554ULL: goto x86_l_1d82;
	case 7556ULL: goto x86_l_1d84;
	case 7561ULL: goto x86_l_1d89;
	case 7567ULL: goto x86_l_1d8f;
	case 7572ULL: goto x86_l_1d94;
	case 7577ULL: goto x86_l_1d99;
	case 7582ULL: goto x86_l_1d9e;
	case 7584ULL: goto x86_l_1da0;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7605ULL: goto x86_l_1db5;
	case 7608ULL: goto x86_l_1db8;
	case 7613ULL: goto x86_l_1dbd;
	case 7616ULL: goto x86_l_1dc0;
	case 7618ULL: goto x86_l_1dc2;
	case 7622ULL: goto x86_l_1dc6;
	case 7628ULL: goto x86_l_1dcc;
	case 7633ULL: goto x86_l_1dd1;
	case 7638ULL: goto x86_l_1dd6;
	case 7643ULL: goto x86_l_1ddb;
	case 7646ULL: goto x86_l_1dde;
	case 7648ULL: goto x86_l_1de0;
	case 7652ULL: goto x86_l_1de4;
	case 7657ULL: goto x86_l_1de9;
	case 7662ULL: goto x86_l_1dee;
	case 7667ULL: goto x86_l_1df3;
	case 7670ULL: goto x86_l_1df6;
	case 7672ULL: goto x86_l_1df8;
	case 7677ULL: goto x86_l_1dfd;
	case 7682ULL: goto x86_l_1e02;
	case 7686ULL: goto x86_l_1e06;
	case 7689ULL: goto x86_l_1e09;
	case 7693ULL: goto x86_l_1e0d;
	case 7695ULL: goto x86_l_1e0f;
	case 7697ULL: goto x86_l_1e11;
	case 7699ULL: goto x86_l_1e13;
	case 7702ULL: goto x86_l_1e16;
	case 7707ULL: goto x86_l_1e1b;
	case 7710ULL: goto x86_l_1e1e;
	case 7712ULL: goto x86_l_1e20;
	case 7716ULL: goto x86_l_1e24;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7727ULL: goto x86_l_1e2f;
	case 7730ULL: goto x86_l_1e32;
	case 7735ULL: goto x86_l_1e37;
	case 7738ULL: goto x86_l_1e3a;
	case 7741ULL: goto x86_l_1e3d;
	case 7747ULL: goto x86_l_1e43;
	case 7754ULL: goto x86_l_1e4a;
	case 7760ULL: goto x86_l_1e50;
	case 7762ULL: goto x86_l_1e52;
	case 7768ULL: goto x86_l_1e58;
	case 7772ULL: goto x86_l_1e5c;
	case 7777ULL: goto x86_l_1e61;
	case 7780ULL: goto x86_l_1e64;
	case 7784ULL: goto x86_l_1e68;
	case 7787ULL: goto x86_l_1e6b;
	case 7792ULL: goto x86_l_1e70;
	case 7794ULL: goto x86_l_1e72;
	case 7799ULL: goto x86_l_1e77;
	case 7804ULL: goto x86_l_1e7c;
	case 7809ULL: goto x86_l_1e81;
	case 7814ULL: goto x86_l_1e86;
	case 7819ULL: goto x86_l_1e8b;
	case 7821ULL: goto x86_l_1e8d;
	case 7825ULL: goto x86_l_1e91;
	case 7830ULL: goto x86_l_1e96;
	case 7833ULL: goto x86_l_1e99;
	case 7838ULL: goto x86_l_1e9e;
	case 7840ULL: goto x86_l_1ea0;
	case 7845ULL: goto x86_l_1ea5;
	case 7849ULL: goto x86_l_1ea9;
	case 7855ULL: goto x86_l_1eaf;
	case 7859ULL: goto x86_l_1eb3;
	case 7864ULL: goto x86_l_1eb8;
	case 7869ULL: goto x86_l_1ebd;
	case 7874ULL: goto x86_l_1ec2;
	case 7877ULL: goto x86_l_1ec5;
	case 7879ULL: goto x86_l_1ec7;
	case 7883ULL: goto x86_l_1ecb;
	case 7888ULL: goto x86_l_1ed0;
	case 7892ULL: goto x86_l_1ed4;
	case 7897ULL: goto x86_l_1ed9;
	case 7902ULL: goto x86_l_1ede;
	case 7907ULL: goto x86_l_1ee3;
	case 7909ULL: goto x86_l_1ee5;
	case 7914ULL: goto x86_l_1eea;
	case 7920ULL: goto x86_l_1ef0;
	case 7925ULL: goto x86_l_1ef5;
	case 7930ULL: goto x86_l_1efa;
	case 7935ULL: goto x86_l_1eff;
	case 7937ULL: goto x86_l_1f01;
	case 7942ULL: goto x86_l_1f06;
	case 7948ULL: goto x86_l_1f0c;
	case 7953ULL: goto x86_l_1f11;
	case 7958ULL: goto x86_l_1f16;
	case 7961ULL: goto x86_l_1f19;
	case 7966ULL: goto x86_l_1f1e;
	case 7969ULL: goto x86_l_1f21;
	case 7971ULL: goto x86_l_1f23;
	case 7975ULL: goto x86_l_1f27;
	case 7981ULL: goto x86_l_1f2d;
	case 7986ULL: goto x86_l_1f32;
	case 7991ULL: goto x86_l_1f37;
	case 7996ULL: goto x86_l_1f3c;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8005ULL: goto x86_l_1f45;
	case 8010ULL: goto x86_l_1f4a;
	case 8015ULL: goto x86_l_1f4f;
	case 8020ULL: goto x86_l_1f54;
	case 8023ULL: goto x86_l_1f57;
	case 8025ULL: goto x86_l_1f59;
	case 8030ULL: goto x86_l_1f5e;
	case 8035ULL: goto x86_l_1f63;
	case 8039ULL: goto x86_l_1f67;
	case 8042ULL: goto x86_l_1f6a;
	case 8046ULL: goto x86_l_1f6e;
	case 8048ULL: goto x86_l_1f70;
	case 8050ULL: goto x86_l_1f72;
	case 8052ULL: goto x86_l_1f74;
	case 8055ULL: goto x86_l_1f77;
	case 8060ULL: goto x86_l_1f7c;
	case 8063ULL: goto x86_l_1f7f;
	case 8065ULL: goto x86_l_1f81;
	case 8069ULL: goto x86_l_1f85;
	case 8071ULL: goto x86_l_1f87;
	case 8074ULL: goto x86_l_1f8a;
	case 8077ULL: goto x86_l_1f8d;
	case 8080ULL: goto x86_l_1f90;
	case 8083ULL: goto x86_l_1f93;
	case 8088ULL: goto x86_l_1f98;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8100ULL: goto x86_l_1fa4;
	case 8107ULL: goto x86_l_1fab;
	case 8113ULL: goto x86_l_1fb1;
	case 8115ULL: goto x86_l_1fb3;
	case 8121ULL: goto x86_l_1fb9;
	case 8125ULL: goto x86_l_1fbd;
	case 8130ULL: goto x86_l_1fc2;
	case 8133ULL: goto x86_l_1fc5;
	case 8137ULL: goto x86_l_1fc9;
	case 8140ULL: goto x86_l_1fcc;
	case 8145ULL: goto x86_l_1fd1;
	case 8147ULL: goto x86_l_1fd3;
	case 8152ULL: goto x86_l_1fd8;
	case 8157ULL: goto x86_l_1fdd;
	case 8162ULL: goto x86_l_1fe2;
	case 8167ULL: goto x86_l_1fe7;
	case 8172ULL: goto x86_l_1fec;
	case 8174ULL: goto x86_l_1fee;
	case 8178ULL: goto x86_l_1ff2;
	case 8183ULL: goto x86_l_1ff7;
	case 8186ULL: goto x86_l_1ffa;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8198ULL: goto x86_l_2006;
	case 8202ULL: goto x86_l_200a;
	case 8208ULL: goto x86_l_2010;
	case 8212ULL: goto x86_l_2014;
	case 8217ULL: goto x86_l_2019;
	case 8222ULL: goto x86_l_201e;
	case 8227ULL: goto x86_l_2023;
	case 8230ULL: goto x86_l_2026;
	case 8232ULL: goto x86_l_2028;
	case 8236ULL: goto x86_l_202c;
	case 8241ULL: goto x86_l_2031;
	case 8245ULL: goto x86_l_2035;
	case 8250ULL: goto x86_l_203a;
	case 8255ULL: goto x86_l_203f;
	case 8260ULL: goto x86_l_2044;
	case 8262ULL: goto x86_l_2046;
	case 8267ULL: goto x86_l_204b;
	case 8273ULL: goto x86_l_2051;
	case 8278ULL: goto x86_l_2056;
	case 8283ULL: goto x86_l_205b;
	case 8288ULL: goto x86_l_2060;
	case 8290ULL: goto x86_l_2062;
	case 8295ULL: goto x86_l_2067;
	case 8301ULL: goto x86_l_206d;
	case 8306ULL: goto x86_l_2072;
	case 8311ULL: goto x86_l_2077;
	case 8314ULL: goto x86_l_207a;
	case 8319ULL: goto x86_l_207f;
	case 8322ULL: goto x86_l_2082;
	case 8324ULL: goto x86_l_2084;
	case 8328ULL: goto x86_l_2088;
	case 8334ULL: goto x86_l_208e;
	case 8339ULL: goto x86_l_2093;
	case 8344ULL: goto x86_l_2098;
	case 8349ULL: goto x86_l_209d;
	case 8352ULL: goto x86_l_20a0;
	case 8354ULL: goto x86_l_20a2;
	case 8358ULL: goto x86_l_20a6;
	case 8363ULL: goto x86_l_20ab;
	case 8368ULL: goto x86_l_20b0;
	case 8373ULL: goto x86_l_20b5;
	case 8376ULL: goto x86_l_20b8;
	case 8378ULL: goto x86_l_20ba;
	case 8383ULL: goto x86_l_20bf;
	case 8388ULL: goto x86_l_20c4;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8399ULL: goto x86_l_20cf;
	case 8401ULL: goto x86_l_20d1;
	case 8403ULL: goto x86_l_20d3;
	case 8405ULL: goto x86_l_20d5;
	case 8408ULL: goto x86_l_20d8;
	case 8413ULL: goto x86_l_20dd;
	case 8416ULL: goto x86_l_20e0;
	case 8418ULL: goto x86_l_20e2;
	case 8422ULL: goto x86_l_20e6;
	case 8424ULL: goto x86_l_20e8;
	case 8427ULL: goto x86_l_20eb;
	case 8430ULL: goto x86_l_20ee;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8441ULL: goto x86_l_20f9;
	case 8444ULL: goto x86_l_20fc;
	case 8447ULL: goto x86_l_20ff;
	case 8453ULL: goto x86_l_2105;
	case 8460ULL: goto x86_l_210c;
	case 8466ULL: goto x86_l_2112;
	case 8468ULL: goto x86_l_2114;
	case 8474ULL: goto x86_l_211a;
	case 8478ULL: goto x86_l_211e;
	case 8483ULL: goto x86_l_2123;
	case 8486ULL: goto x86_l_2126;
	case 8490ULL: goto x86_l_212a;
	case 8493ULL: goto x86_l_212d;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8505ULL: goto x86_l_2139;
	case 8510ULL: goto x86_l_213e;
	case 8515ULL: goto x86_l_2143;
	case 8520ULL: goto x86_l_2148;
	case 8525ULL: goto x86_l_214d;
	case 8527ULL: goto x86_l_214f;
	case 8531ULL: goto x86_l_2153;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b23:
	/* 0x1b23: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b27:
	/* 0x1b27: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b2c:
	/* 0x1b2c: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b31:
	/* 0x1b31: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1b36:
	/* 0x1b36: jne    1b43 <generic_tracepoint_process_event_2+0x1b43> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1b43;
	}
x86_l_1b38:
	/* 0x1b38: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1b3d:
	/* 0x1b3d: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_1b43:
	/* 0x1b43: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b48:
	/* 0x1b48: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b52:
	/* 0x1b52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b54:
	/* 0x1b54: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_1b59:
	/* 0x1b59: je     1d2c <generic_tracepoint_process_event_2+0x1d2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2c;
	}
x86_l_1b5f:
	/* 0x1b5f: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b64:
	/* 0x1b64: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b69:
	/* 0x1b69: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1b6c:
	/* 0x1b6c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b71:
	/* 0x1b71: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b74:
	/* 0x1b74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b76:
	/* 0x1b76: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7a:
	/* 0x1b7a: je     1d2c <generic_tracepoint_process_event_2+0x1d2c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1d2c;
	}
x86_l_1b80:
	/* 0x1b80: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b85:
	/* 0x1b85: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b8a:
	/* 0x1b8a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1b8f:
	/* 0x1b8f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1b92:
	/* 0x1b92: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b94:
	/* 0x1b94: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1b98:
	/* 0x1b98: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b9d:
	/* 0x1b9d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1ba7:
	/* 0x1ba7: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1baa:
	/* 0x1baa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bac:
	/* 0x1bac: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bb1:
	/* 0x1bb1: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1bba:
	/* 0x1bba: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1bbd:
	/* 0x1bbd: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bc1:
	/* 0x1bc1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bc3:
	/* 0x1bc3: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1bc5:
	/* 0x1bc5: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1bc7:
	/* 0x1bc7: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1bca:
	/* 0x1bca: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1bcf:
	/* 0x1bcf: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd2:
	/* 0x1bd2: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1bd4:
	/* 0x1bd4: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1bd8:
	/* 0x1bd8: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1bda:
	/* 0x1bda: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1bdd:
	/* 0x1bdd: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1be0:
	/* 0x1be0: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1be3:
	/* 0x1be3: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1be6:
	/* 0x1be6: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1beb:
	/* 0x1beb: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1bee:
	/* 0x1bee: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1bf1:
	/* 0x1bf1: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_1bf7:
	/* 0x1bf7: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_1bfe:
	/* 0x1bfe: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_1c04:
	/* 0x1c04: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1c06:
	/* 0x1c06: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_1c0c:
	/* 0x1c0c: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1c10:
	/* 0x1c10: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_1c15:
	/* 0x1c15: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1c18:
	/* 0x1c18: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1c1c:
	/* 0x1c1c: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1c1f:
	/* 0x1c1f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1c24:
	/* 0x1c24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c26:
	/* 0x1c26: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c30:
	/* 0x1c30: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c35:
	/* 0x1c35: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c3a:
	/* 0x1c3a: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c3f:
	/* 0x1c3f: jmp    1d7d <generic_tracepoint_process_event_2+0x1d7d> */
	goto x86_l_1d7d;
x86_l_1c44:
	/* 0x1c44: mov    DWORD PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_1c4f:
	/* 0x1c4f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c54:
	/* 0x1c54: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c5b:
	/* 0x1c5b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1c5e:
	/* 0x1c5e: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1c66:
	/* 0x1c66: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c68:
	/* 0x1c68: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c6a:
	/* 0x1c6a: mov    DWORD PTR [r15],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967292ULL);
x86_l_1c71:
	/* 0x1c71: jmp    1d1d <generic_tracepoint_process_event_2+0x1d1d> */
	goto x86_l_1d1d;
x86_l_1c76:
	/* 0x1c76: mov    DWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_1c7e:
	/* 0x1c7e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c83:
	/* 0x1c83: mov    rdi,QWORD PTR [rip+0x657e] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_1c8a:
	/* 0x1c8a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1c8d:
	/* 0x1c8d: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c92:
	/* 0x1c92: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c94:
	/* 0x1c94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c96:
	/* 0x1c96: mov    DWORD PTR [rbp+r15*1+0x0],0xfffffffc */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4294967292ULL);
x86_l_1c9f:
	/* 0x1c9f: jmp    1d1d <generic_tracepoint_process_event_2+0x1d1d> */
	goto x86_l_1d1d;
x86_l_1ca1:
	/* 0x1ca1: add    r12,0x5e60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24160ULL);
x86_l_1ca8:
	/* 0x1ca8: jmp    1cba <generic_tracepoint_process_event_2+0x1cba> */
	goto x86_l_1cba;
x86_l_1caa:
	/* 0x1caa: add    r12,0x5e68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24168ULL);
x86_l_1cb1:
	/* 0x1cb1: jmp    1cba <generic_tracepoint_process_event_2+0x1cba> */
	goto x86_l_1cba;
x86_l_1cb3:
	/* 0x1cb3: add    r12,0x5e50 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 24144ULL);
x86_l_1cba:
	/* 0x1cba: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cc8:
	/* 0x1cc8: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ccd:
	/* 0x1ccd: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1cd2:
	/* 0x1cd2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1cd7:
	/* 0x1cd7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd9:
	/* 0x1cd9: mov    r13,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1cde:
	/* 0x1cde: cmp    r13,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 4095ULL);
x86_l_1ce5:
	/* 0x1ce5: mov    r12d,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4095ULL);
x86_l_1ceb:
	/* 0x1ceb: cmovb  r12,r13 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R13, X86_WIDTH_64, X86_CC_B);
x86_l_1cef:
	/* 0x1cef: lea    rdi,[r15+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cf3:
	/* 0x1cf3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1cf8:
	/* 0x1cf8: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1cfb:
	/* 0x1cfb: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1d00:
	/* 0x1d00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d02:
	/* 0x1d02: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d04:
	/* 0x1d04: js     1d16 <generic_tracepoint_process_event_2+0x1d16> */
	if (X86_SIM_L_EVAL_CC(X86_CC_S)) {
		goto x86_l_1d16;
	}
x86_l_1d06:
	/* 0x1d06: mov    DWORD PTR [r15],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d09:
	/* 0x1d09: mov    DWORD PTR [r15+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d0d:
	/* 0x1d0d: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1d11:
	/* 0x1d11: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_1d14:
	/* 0x1d14: jmp    1d23 <generic_tracepoint_process_event_2+0x1d23> */
	goto x86_l_1d23;
x86_l_1d16:
	/* 0x1d16: mov    DWORD PTR [r15],0xfffffffe */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4294967294ULL);
x86_l_1d1d:
	/* 0x1d1d: mov    r8d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4ULL);
x86_l_1d23:
	/* 0x1d23: add    r8d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1d27:
	/* 0x1d27: jmp    2ff <generic_tracepoint_process_event_2+0x2ff> */
	return 767ULL;
x86_l_1d2c:
	/* 0x1d2c: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d30:
	/* 0x1d30: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d35:
	/* 0x1d35: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d38:
	/* 0x1d38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d3d:
	/* 0x1d3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d3f:
	/* 0x1d3f: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d44:
	/* 0x1d44: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1d48:
	/* 0x1d48: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_1d4e:
	/* 0x1d4e: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1d52:
	/* 0x1d52: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d57:
	/* 0x1d57: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d5c:
	/* 0x1d5c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d61:
	/* 0x1d61: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1d64:
	/* 0x1d64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d66:
	/* 0x1d66: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d6a:
	/* 0x1d6a: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d6f:
	/* 0x1d6f: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d73:
	/* 0x1d73: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d78:
	/* 0x1d78: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d7d:
	/* 0x1d7d: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1d82:
	/* 0x1d82: jne    1d8f <generic_tracepoint_process_event_2+0x1d8f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d8f;
	}
x86_l_1d84:
	/* 0x1d84: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1d89:
	/* 0x1d89: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_1d8f:
	/* 0x1d8f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1d94:
	/* 0x1d94: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d99:
	/* 0x1d99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1d9e:
	/* 0x1d9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da0:
	/* 0x1da0: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_1da5:
	/* 0x1da5: je     1e8d <generic_tracepoint_process_event_2+0x1e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e8d;
	}
x86_l_1dab:
	/* 0x1dab: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1db0:
	/* 0x1db0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1db5:
	/* 0x1db5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1db8:
	/* 0x1db8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dbd:
	/* 0x1dbd: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1dc0:
	/* 0x1dc0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc2:
	/* 0x1dc2: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dc6:
	/* 0x1dc6: je     1e8d <generic_tracepoint_process_event_2+0x1e8d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1e8d;
	}
x86_l_1dcc:
	/* 0x1dcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1dd1:
	/* 0x1dd1: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1dd6:
	/* 0x1dd6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ddb:
	/* 0x1ddb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1dde:
	/* 0x1dde: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1de0:
	/* 0x1de0: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1de4:
	/* 0x1de4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1de9:
	/* 0x1de9: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1dee:
	/* 0x1dee: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1df3:
	/* 0x1df3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1df6:
	/* 0x1df6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df8:
	/* 0x1df8: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dfd:
	/* 0x1dfd: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e02:
	/* 0x1e02: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1e06:
	/* 0x1e06: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e09:
	/* 0x1e09: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e0d:
	/* 0x1e0d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e0f:
	/* 0x1e0f: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1e11:
	/* 0x1e11: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e13:
	/* 0x1e13: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1e16:
	/* 0x1e16: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1e1b:
	/* 0x1e1b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e1e:
	/* 0x1e1e: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1e20:
	/* 0x1e20: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1e24:
	/* 0x1e24: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1e26:
	/* 0x1e26: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1e29:
	/* 0x1e29: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e2c:
	/* 0x1e2c: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1e2f:
	/* 0x1e2f: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1e32:
	/* 0x1e32: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1e37:
	/* 0x1e37: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e3a:
	/* 0x1e3a: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1e3d:
	/* 0x1e3d: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_1e43:
	/* 0x1e43: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_1e4a:
	/* 0x1e4a: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_1e50:
	/* 0x1e50: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1e52:
	/* 0x1e52: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_1e58:
	/* 0x1e58: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1e5c:
	/* 0x1e5c: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_1e61:
	/* 0x1e61: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e64:
	/* 0x1e64: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1e68:
	/* 0x1e68: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1e6b:
	/* 0x1e6b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e70:
	/* 0x1e70: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e72:
	/* 0x1e72: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e77:
	/* 0x1e77: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e81:
	/* 0x1e81: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1e86:
	/* 0x1e86: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e8b:
	/* 0x1e8b: jmp    1ede <generic_tracepoint_process_event_2+0x1ede> */
	goto x86_l_1ede;
x86_l_1e8d:
	/* 0x1e8d: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e91:
	/* 0x1e91: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1e96:
	/* 0x1e96: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1e99:
	/* 0x1e99: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1e9e:
	/* 0x1e9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ea0:
	/* 0x1ea0: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ea5:
	/* 0x1ea5: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1ea9:
	/* 0x1ea9: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_1eaf:
	/* 0x1eaf: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1eb3:
	/* 0x1eb3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1eb8:
	/* 0x1eb8: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ebd:
	/* 0x1ebd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1ec2:
	/* 0x1ec2: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ec5:
	/* 0x1ec5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec7:
	/* 0x1ec7: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ecb:
	/* 0x1ecb: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ed0:
	/* 0x1ed0: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ed4:
	/* 0x1ed4: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1ed9:
	/* 0x1ed9: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ede:
	/* 0x1ede: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_1ee3:
	/* 0x1ee3: jne    1ef0 <generic_tracepoint_process_event_2+0x1ef0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ef0;
	}
x86_l_1ee5:
	/* 0x1ee5: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_1eea:
	/* 0x1eea: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_1ef0:
	/* 0x1ef0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ef5:
	/* 0x1ef5: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1efa:
	/* 0x1efa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1eff:
	/* 0x1eff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f01:
	/* 0x1f01: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_1f06:
	/* 0x1f06: je     1fee <generic_tracepoint_process_event_2+0x1fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fee;
	}
x86_l_1f0c:
	/* 0x1f0c: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f11:
	/* 0x1f11: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f16:
	/* 0x1f16: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1f19:
	/* 0x1f19: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f1e:
	/* 0x1f1e: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f21:
	/* 0x1f21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f23:
	/* 0x1f23: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f27:
	/* 0x1f27: je     1fee <generic_tracepoint_process_event_2+0x1fee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fee;
	}
x86_l_1f2d:
	/* 0x1f2d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f32:
	/* 0x1f32: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f37:
	/* 0x1f37: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1f3c:
	/* 0x1f3c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f3f:
	/* 0x1f3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f41:
	/* 0x1f41: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_1f45:
	/* 0x1f45: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1f4a:
	/* 0x1f4a: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1f4f:
	/* 0x1f4f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1f54:
	/* 0x1f54: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1f57:
	/* 0x1f57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f59:
	/* 0x1f59: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f5e:
	/* 0x1f5e: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1f63:
	/* 0x1f63: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_1f67:
	/* 0x1f67: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1f6a:
	/* 0x1f6a: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f6e:
	/* 0x1f6e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f70:
	/* 0x1f70: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1f72:
	/* 0x1f72: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f74:
	/* 0x1f74: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_1f77:
	/* 0x1f77: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_1f7c:
	/* 0x1f7c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f7f:
	/* 0x1f7f: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1f81:
	/* 0x1f81: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_1f85:
	/* 0x1f85: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_1f87:
	/* 0x1f87: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_1f8a:
	/* 0x1f8a: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1f8d:
	/* 0x1f8d: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_1f90:
	/* 0x1f90: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1f93:
	/* 0x1f93: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f98:
	/* 0x1f98: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1f9b:
	/* 0x1f9b: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1f9e:
	/* 0x1f9e: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_1fa4:
	/* 0x1fa4: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_1fab:
	/* 0x1fab: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_1fb1:
	/* 0x1fb1: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_1fb3:
	/* 0x1fb3: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_1fb9:
	/* 0x1fb9: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1fbd:
	/* 0x1fbd: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_1fc2:
	/* 0x1fc2: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fc5:
	/* 0x1fc5: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_1fc9:
	/* 0x1fc9: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1fcc:
	/* 0x1fcc: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1fd1:
	/* 0x1fd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd3:
	/* 0x1fd3: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1fd8:
	/* 0x1fd8: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1fdd:
	/* 0x1fdd: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1fe2:
	/* 0x1fe2: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fe7:
	/* 0x1fe7: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1fec:
	/* 0x1fec: jmp    203f <generic_tracepoint_process_event_2+0x203f> */
	goto x86_l_203f;
x86_l_1fee:
	/* 0x1fee: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ff2:
	/* 0x1ff2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ff7:
	/* 0x1ff7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ffa:
	/* 0x1ffa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1fff:
	/* 0x1fff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2001:
	/* 0x2001: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2006:
	/* 0x2006: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_200a:
	/* 0x200a: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 9654ULL;
	}
x86_l_2010:
	/* 0x2010: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2014:
	/* 0x2014: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2019:
	/* 0x2019: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_201e:
	/* 0x201e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2023:
	/* 0x2023: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2026:
	/* 0x2026: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2028:
	/* 0x2028: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_202c:
	/* 0x202c: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2031:
	/* 0x2031: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2035:
	/* 0x2035: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_203a:
	/* 0x203a: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_203f:
	/* 0x203f: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2044:
	/* 0x2044: jne    2051 <generic_tracepoint_process_event_2+0x2051> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2051;
	}
x86_l_2046:
	/* 0x2046: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_204b:
	/* 0x204b: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_2051:
	/* 0x2051: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2056:
	/* 0x2056: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_205b:
	/* 0x205b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2060:
	/* 0x2060: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2062:
	/* 0x2062: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_2067:
	/* 0x2067: je     214f <generic_tracepoint_process_event_2+0x214f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214f;
	}
x86_l_206d:
	/* 0x206d: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2072:
	/* 0x2072: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2077:
	/* 0x2077: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_207a:
	/* 0x207a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_207f:
	/* 0x207f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2082:
	/* 0x2082: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2084:
	/* 0x2084: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2088:
	/* 0x2088: je     214f <generic_tracepoint_process_event_2+0x214f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_214f;
	}
x86_l_208e:
	/* 0x208e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2093:
	/* 0x2093: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2098:
	/* 0x2098: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_209d:
	/* 0x209d: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_20a0:
	/* 0x20a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a2:
	/* 0x20a2: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_20a6:
	/* 0x20a6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_20ab:
	/* 0x20ab: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_20b0:
	/* 0x20b0: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_20b5:
	/* 0x20b5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_20b8:
	/* 0x20b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20ba:
	/* 0x20ba: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_20bf:
	/* 0x20bf: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20c4:
	/* 0x20c4: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_20c8:
	/* 0x20c8: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_20cb:
	/* 0x20cb: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20cf:
	/* 0x20cf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20d1:
	/* 0x20d1: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_20d3:
	/* 0x20d3: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20d5:
	/* 0x20d5: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_20d8:
	/* 0x20d8: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_20dd:
	/* 0x20dd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20e0:
	/* 0x20e0: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_20e2:
	/* 0x20e2: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_20e6:
	/* 0x20e6: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_20e8:
	/* 0x20e8: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_20eb:
	/* 0x20eb: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_20ee:
	/* 0x20ee: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_20f1:
	/* 0x20f1: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_20f4:
	/* 0x20f4: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_20f9:
	/* 0x20f9: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_20fc:
	/* 0x20fc: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_20ff:
	/* 0x20ff: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_2105:
	/* 0x2105: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_210c:
	/* 0x210c: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_2112:
	/* 0x2112: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2114:
	/* 0x2114: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		return 9572ULL;
	}
x86_l_211a:
	/* 0x211a: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_211e:
	/* 0x211e: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_2123:
	/* 0x2123: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2126:
	/* 0x2126: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_212a:
	/* 0x212a: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_212d:
	/* 0x212d: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2132:
	/* 0x2132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2134:
	/* 0x2134: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2139:
	/* 0x2139: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_213e:
	/* 0x213e: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2143:
	/* 0x2143: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2148:
	/* 0x2148: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_214d:
	/* 0x214d: jmp    21a0 <generic_tracepoint_process_event_2+0x21a0> */
	return 8608ULL;
x86_l_214f:
	/* 0x214f: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2153:
	/* 0x2153: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
	return 8536ULL;
}

static __noinline __u64 tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8536ULL: goto x86_l_2158;
	case 8539ULL: goto x86_l_215b;
	case 8544ULL: goto x86_l_2160;
	case 8546ULL: goto x86_l_2162;
	case 8551ULL: goto x86_l_2167;
	case 8555ULL: goto x86_l_216b;
	case 8561ULL: goto x86_l_2171;
	case 8565ULL: goto x86_l_2175;
	case 8570ULL: goto x86_l_217a;
	case 8575ULL: goto x86_l_217f;
	case 8580ULL: goto x86_l_2184;
	case 8583ULL: goto x86_l_2187;
	case 8585ULL: goto x86_l_2189;
	case 8589ULL: goto x86_l_218d;
	case 8594ULL: goto x86_l_2192;
	case 8598ULL: goto x86_l_2196;
	case 8603ULL: goto x86_l_219b;
	case 8608ULL: goto x86_l_21a0;
	case 8613ULL: goto x86_l_21a5;
	case 8615ULL: goto x86_l_21a7;
	case 8620ULL: goto x86_l_21ac;
	case 8626ULL: goto x86_l_21b2;
	case 8631ULL: goto x86_l_21b7;
	case 8636ULL: goto x86_l_21bc;
	case 8641ULL: goto x86_l_21c1;
	case 8643ULL: goto x86_l_21c3;
	case 8648ULL: goto x86_l_21c8;
	case 8654ULL: goto x86_l_21ce;
	case 8659ULL: goto x86_l_21d3;
	case 8664ULL: goto x86_l_21d8;
	case 8667ULL: goto x86_l_21db;
	case 8672ULL: goto x86_l_21e0;
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8681ULL: goto x86_l_21e9;
	case 8687ULL: goto x86_l_21ef;
	case 8692ULL: goto x86_l_21f4;
	case 8697ULL: goto x86_l_21f9;
	case 8702ULL: goto x86_l_21fe;
	case 8705ULL: goto x86_l_2201;
	case 8707ULL: goto x86_l_2203;
	case 8711ULL: goto x86_l_2207;
	case 8716ULL: goto x86_l_220c;
	case 8721ULL: goto x86_l_2211;
	case 8726ULL: goto x86_l_2216;
	case 8729ULL: goto x86_l_2219;
	case 8731ULL: goto x86_l_221b;
	case 8736ULL: goto x86_l_2220;
	case 8741ULL: goto x86_l_2225;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8752ULL: goto x86_l_2230;
	case 8754ULL: goto x86_l_2232;
	case 8756ULL: goto x86_l_2234;
	case 8758ULL: goto x86_l_2236;
	case 8761ULL: goto x86_l_2239;
	case 8766ULL: goto x86_l_223e;
	case 8769ULL: goto x86_l_2241;
	case 8771ULL: goto x86_l_2243;
	case 8775ULL: goto x86_l_2247;
	case 8777ULL: goto x86_l_2249;
	case 8780ULL: goto x86_l_224c;
	case 8783ULL: goto x86_l_224f;
	case 8786ULL: goto x86_l_2252;
	case 8789ULL: goto x86_l_2255;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8800ULL: goto x86_l_2260;
	case 8806ULL: goto x86_l_2266;
	case 8813ULL: goto x86_l_226d;
	case 8819ULL: goto x86_l_2273;
	case 8821ULL: goto x86_l_2275;
	case 8827ULL: goto x86_l_227b;
	case 8831ULL: goto x86_l_227f;
	case 8836ULL: goto x86_l_2284;
	case 8839ULL: goto x86_l_2287;
	case 8843ULL: goto x86_l_228b;
	case 8846ULL: goto x86_l_228e;
	case 8851ULL: goto x86_l_2293;
	case 8853ULL: goto x86_l_2295;
	case 8858ULL: goto x86_l_229a;
	case 8863ULL: goto x86_l_229f;
	case 8868ULL: goto x86_l_22a4;
	case 8873ULL: goto x86_l_22a9;
	case 8878ULL: goto x86_l_22ae;
	case 8880ULL: goto x86_l_22b0;
	case 8884ULL: goto x86_l_22b4;
	case 8889ULL: goto x86_l_22b9;
	case 8892ULL: goto x86_l_22bc;
	case 8897ULL: goto x86_l_22c1;
	case 8899ULL: goto x86_l_22c3;
	case 8904ULL: goto x86_l_22c8;
	case 8908ULL: goto x86_l_22cc;
	case 8914ULL: goto x86_l_22d2;
	case 8918ULL: goto x86_l_22d6;
	case 8923ULL: goto x86_l_22db;
	case 8928ULL: goto x86_l_22e0;
	case 8933ULL: goto x86_l_22e5;
	case 8936ULL: goto x86_l_22e8;
	case 8938ULL: goto x86_l_22ea;
	case 8942ULL: goto x86_l_22ee;
	case 8947ULL: goto x86_l_22f3;
	case 8951ULL: goto x86_l_22f7;
	case 8956ULL: goto x86_l_22fc;
	case 8961ULL: goto x86_l_2301;
	case 8966ULL: goto x86_l_2306;
	case 8968ULL: goto x86_l_2308;
	case 8973ULL: goto x86_l_230d;
	case 8979ULL: goto x86_l_2313;
	case 8984ULL: goto x86_l_2318;
	case 8989ULL: goto x86_l_231d;
	case 8994ULL: goto x86_l_2322;
	case 8996ULL: goto x86_l_2324;
	case 9001ULL: goto x86_l_2329;
	case 9007ULL: goto x86_l_232f;
	case 9012ULL: goto x86_l_2334;
	case 9017ULL: goto x86_l_2339;
	case 9020ULL: goto x86_l_233c;
	case 9025ULL: goto x86_l_2341;
	case 9028ULL: goto x86_l_2344;
	case 9030ULL: goto x86_l_2346;
	case 9034ULL: goto x86_l_234a;
	case 9040ULL: goto x86_l_2350;
	case 9045ULL: goto x86_l_2355;
	case 9050ULL: goto x86_l_235a;
	case 9055ULL: goto x86_l_235f;
	case 9058ULL: goto x86_l_2362;
	case 9060ULL: goto x86_l_2364;
	case 9064ULL: goto x86_l_2368;
	case 9069ULL: goto x86_l_236d;
	case 9074ULL: goto x86_l_2372;
	case 9079ULL: goto x86_l_2377;
	case 9082ULL: goto x86_l_237a;
	case 9084ULL: goto x86_l_237c;
	case 9089ULL: goto x86_l_2381;
	case 9094ULL: goto x86_l_2386;
	case 9098ULL: goto x86_l_238a;
	case 9101ULL: goto x86_l_238d;
	case 9105ULL: goto x86_l_2391;
	case 9107ULL: goto x86_l_2393;
	case 9109ULL: goto x86_l_2395;
	case 9111ULL: goto x86_l_2397;
	case 9114ULL: goto x86_l_239a;
	case 9119ULL: goto x86_l_239f;
	case 9122ULL: goto x86_l_23a2;
	case 9124ULL: goto x86_l_23a4;
	case 9128ULL: goto x86_l_23a8;
	case 9130ULL: goto x86_l_23aa;
	case 9133ULL: goto x86_l_23ad;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9142ULL: goto x86_l_23b6;
	case 9147ULL: goto x86_l_23bb;
	case 9150ULL: goto x86_l_23be;
	case 9153ULL: goto x86_l_23c1;
	case 9159ULL: goto x86_l_23c7;
	case 9166ULL: goto x86_l_23ce;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9180ULL: goto x86_l_23dc;
	case 9184ULL: goto x86_l_23e0;
	case 9189ULL: goto x86_l_23e5;
	case 9192ULL: goto x86_l_23e8;
	case 9196ULL: goto x86_l_23ec;
	case 9199ULL: goto x86_l_23ef;
	case 9204ULL: goto x86_l_23f4;
	case 9206ULL: goto x86_l_23f6;
	case 9211ULL: goto x86_l_23fb;
	case 9216ULL: goto x86_l_2400;
	case 9221ULL: goto x86_l_2405;
	case 9226ULL: goto x86_l_240a;
	case 9231ULL: goto x86_l_240f;
	case 9233ULL: goto x86_l_2411;
	case 9237ULL: goto x86_l_2415;
	case 9242ULL: goto x86_l_241a;
	case 9245ULL: goto x86_l_241d;
	case 9250ULL: goto x86_l_2422;
	case 9252ULL: goto x86_l_2424;
	case 9257ULL: goto x86_l_2429;
	case 9261ULL: goto x86_l_242d;
	case 9267ULL: goto x86_l_2433;
	case 9271ULL: goto x86_l_2437;
	case 9276ULL: goto x86_l_243c;
	case 9281ULL: goto x86_l_2441;
	case 9286ULL: goto x86_l_2446;
	case 9289ULL: goto x86_l_2449;
	case 9291ULL: goto x86_l_244b;
	case 9295ULL: goto x86_l_244f;
	case 9300ULL: goto x86_l_2454;
	case 9304ULL: goto x86_l_2458;
	case 9309ULL: goto x86_l_245d;
	case 9314ULL: goto x86_l_2462;
	case 9319ULL: goto x86_l_2467;
	case 9321ULL: goto x86_l_2469;
	case 9326ULL: goto x86_l_246e;
	case 9332ULL: goto x86_l_2474;
	case 9337ULL: goto x86_l_2479;
	case 9342ULL: goto x86_l_247e;
	case 9347ULL: goto x86_l_2483;
	case 9349ULL: goto x86_l_2485;
	case 9354ULL: goto x86_l_248a;
	case 9360ULL: goto x86_l_2490;
	case 9365ULL: goto x86_l_2495;
	case 9370ULL: goto x86_l_249a;
	case 9373ULL: goto x86_l_249d;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9387ULL: goto x86_l_24ab;
	case 9393ULL: goto x86_l_24b1;
	case 9398ULL: goto x86_l_24b6;
	case 9403ULL: goto x86_l_24bb;
	case 9408ULL: goto x86_l_24c0;
	case 9411ULL: goto x86_l_24c3;
	case 9413ULL: goto x86_l_24c5;
	case 9417ULL: goto x86_l_24c9;
	case 9422ULL: goto x86_l_24ce;
	case 9427ULL: goto x86_l_24d3;
	case 9432ULL: goto x86_l_24d8;
	case 9435ULL: goto x86_l_24db;
	case 9437ULL: goto x86_l_24dd;
	case 9442ULL: goto x86_l_24e2;
	case 9447ULL: goto x86_l_24e7;
	case 9451ULL: goto x86_l_24eb;
	case 9454ULL: goto x86_l_24ee;
	case 9458ULL: goto x86_l_24f2;
	case 9460ULL: goto x86_l_24f4;
	case 9462ULL: goto x86_l_24f6;
	case 9464ULL: goto x86_l_24f8;
	case 9467ULL: goto x86_l_24fb;
	case 9472ULL: goto x86_l_2500;
	case 9475ULL: goto x86_l_2503;
	case 9477ULL: goto x86_l_2505;
	case 9481ULL: goto x86_l_2509;
	case 9483ULL: goto x86_l_250b;
	case 9486ULL: goto x86_l_250e;
	case 9489ULL: goto x86_l_2511;
	case 9492ULL: goto x86_l_2514;
	case 9495ULL: goto x86_l_2517;
	case 9500ULL: goto x86_l_251c;
	case 9503ULL: goto x86_l_251f;
	case 9506ULL: goto x86_l_2522;
	case 9512ULL: goto x86_l_2528;
	case 9519ULL: goto x86_l_252f;
	case 9525ULL: goto x86_l_2535;
	case 9527ULL: goto x86_l_2537;
	case 9529ULL: goto x86_l_2539;
	case 9533ULL: goto x86_l_253d;
	case 9538ULL: goto x86_l_2542;
	case 9541ULL: goto x86_l_2545;
	case 9545ULL: goto x86_l_2549;
	case 9548ULL: goto x86_l_254c;
	case 9553ULL: goto x86_l_2551;
	case 9555ULL: goto x86_l_2553;
	case 9560ULL: goto x86_l_2558;
	case 9565ULL: goto x86_l_255d;
	case 9570ULL: goto x86_l_2562;
	case 9572ULL: goto x86_l_2564;
	case 9575ULL: goto x86_l_2567;
	case 9578ULL: goto x86_l_256a;
	case 9583ULL: goto x86_l_256f;
	case 9586ULL: goto x86_l_2572;
	case 9588ULL: goto x86_l_2574;
	case 9593ULL: goto x86_l_2579;
	case 9598ULL: goto x86_l_257e;
	case 9602ULL: goto x86_l_2582;
	case 9607ULL: goto x86_l_2587;
	case 9610ULL: goto x86_l_258a;
	case 9615ULL: goto x86_l_258f;
	case 9617ULL: goto x86_l_2591;
	case 9622ULL: goto x86_l_2596;
	case 9626ULL: goto x86_l_259a;
	case 9628ULL: goto x86_l_259c;
	case 9632ULL: goto x86_l_25a0;
	case 9637ULL: goto x86_l_25a5;
	case 9642ULL: goto x86_l_25aa;
	case 9647ULL: goto x86_l_25af;
	case 9650ULL: goto x86_l_25b2;
	case 9652ULL: goto x86_l_25b4;
	case 9654ULL: goto x86_l_25b6;
	case 9659ULL: goto x86_l_25bb;
	case 9664ULL: goto x86_l_25c0;
	case 9667ULL: goto x86_l_25c3;
	case 9672ULL: goto x86_l_25c8;
	case 9674ULL: goto x86_l_25ca;
	case 9677ULL: goto x86_l_25cd;
	case 9683ULL: goto x86_l_25d3;
	case 9686ULL: goto x86_l_25d6;
	case 9690ULL: goto x86_l_25da;
	case 9697ULL: goto x86_l_25e1;
	case 9702ULL: goto x86_l_25e6;
	case 9705ULL: goto x86_l_25e9;
	case 9708ULL: goto x86_l_25ec;
	case 9711ULL: goto x86_l_25ef;
	case 9713ULL: goto x86_l_25f1;
	case 9717ULL: goto x86_l_25f5;
	case 9722ULL: goto x86_l_25fa;
	case 9727ULL: goto x86_l_25ff;
	case 9732ULL: goto x86_l_2604;
	case 9740ULL: goto x86_l_260c;
	case 9742ULL: goto x86_l_260e;
	case 9747ULL: goto x86_l_2613;
	case 9752ULL: goto x86_l_2618;
	case 9756ULL: goto x86_l_261c;
	case 9761ULL: goto x86_l_2621;
	case 9766ULL: goto x86_l_2626;
	case 9768ULL: goto x86_l_2628;
	case 9773ULL: goto x86_l_262d;
	case 9778ULL: goto x86_l_2632;
	case 9781ULL: goto x86_l_2635;
	case 9786ULL: goto x86_l_263a;
	case 9788ULL: goto x86_l_263c;
	case 9793ULL: goto x86_l_2641;
	case 9797ULL: goto x86_l_2645;
	case 9803ULL: goto x86_l_264b;
	case 9807ULL: goto x86_l_264f;
	case 9811ULL: goto x86_l_2653;
	case 9814ULL: goto x86_l_2656;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2158:
	/* 0x2158: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_215b:
	/* 0x215b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2160:
	/* 0x2160: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2162:
	/* 0x2162: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2167:
	/* 0x2167: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_216b:
	/* 0x216b: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b6;
	}
x86_l_2171:
	/* 0x2171: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2175:
	/* 0x2175: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_217a:
	/* 0x217a: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_217f:
	/* 0x217f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2184:
	/* 0x2184: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2187:
	/* 0x2187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2189:
	/* 0x2189: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_218d:
	/* 0x218d: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2192:
	/* 0x2192: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2196:
	/* 0x2196: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_219b:
	/* 0x219b: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_21a0:
	/* 0x21a0: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_21a5:
	/* 0x21a5: jne    21b2 <generic_tracepoint_process_event_2+0x21b2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_21b2;
	}
x86_l_21a7:
	/* 0x21a7: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_21ac:
	/* 0x21ac: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_21b2:
	/* 0x21b2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21b7:
	/* 0x21b7: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_21bc:
	/* 0x21bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21c1:
	/* 0x21c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21c3:
	/* 0x21c3: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_21c8:
	/* 0x21c8: je     22b0 <generic_tracepoint_process_event_2+0x22b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b0;
	}
x86_l_21ce:
	/* 0x21ce: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21d3:
	/* 0x21d3: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21d8:
	/* 0x21d8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_21db:
	/* 0x21db: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e0:
	/* 0x21e0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_21e3:
	/* 0x21e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21e5:
	/* 0x21e5: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21e9:
	/* 0x21e9: je     22b0 <generic_tracepoint_process_event_2+0x22b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_22b0;
	}
x86_l_21ef:
	/* 0x21ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_21f4:
	/* 0x21f4: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_21f9:
	/* 0x21f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21fe:
	/* 0x21fe: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2201:
	/* 0x2201: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2203:
	/* 0x2203: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2207:
	/* 0x2207: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_220c:
	/* 0x220c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2211:
	/* 0x2211: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2216:
	/* 0x2216: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_2219:
	/* 0x2219: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221b:
	/* 0x221b: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2220:
	/* 0x2220: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2225:
	/* 0x2225: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_2229:
	/* 0x2229: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_222c:
	/* 0x222c: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2230:
	/* 0x2230: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2232:
	/* 0x2232: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2234:
	/* 0x2234: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2236:
	/* 0x2236: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_2239:
	/* 0x2239: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_223e:
	/* 0x223e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2241:
	/* 0x2241: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2243:
	/* 0x2243: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2247:
	/* 0x2247: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_2249:
	/* 0x2249: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_224c:
	/* 0x224c: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_224f:
	/* 0x224f: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2252:
	/* 0x2252: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2255:
	/* 0x2255: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_225a:
	/* 0x225a: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_225d:
	/* 0x225d: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_2260:
	/* 0x2260: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_2266:
	/* 0x2266: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_226d:
	/* 0x226d: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_2273:
	/* 0x2273: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2275:
	/* 0x2275: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2564;
	}
x86_l_227b:
	/* 0x227b: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_227f:
	/* 0x227f: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_2284:
	/* 0x2284: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2287:
	/* 0x2287: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_228b:
	/* 0x228b: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_228e:
	/* 0x228e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2293:
	/* 0x2293: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2295:
	/* 0x2295: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_229a:
	/* 0x229a: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_229f:
	/* 0x229f: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22a4:
	/* 0x22a4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22a9:
	/* 0x22a9: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22ae:
	/* 0x22ae: jmp    2301 <generic_tracepoint_process_event_2+0x2301> */
	goto x86_l_2301;
x86_l_22b0:
	/* 0x22b0: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22b4:
	/* 0x22b4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22b9:
	/* 0x22b9: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22bc:
	/* 0x22bc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22c1:
	/* 0x22c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c3:
	/* 0x22c3: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22c8:
	/* 0x22c8: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_22cc:
	/* 0x22cc: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b6;
	}
x86_l_22d2:
	/* 0x22d2: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_22d6:
	/* 0x22d6: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_22db:
	/* 0x22db: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22e0:
	/* 0x22e0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_22e5:
	/* 0x22e5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22e8:
	/* 0x22e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22ea:
	/* 0x22ea: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22ee:
	/* 0x22ee: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_22f3:
	/* 0x22f3: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22f7:
	/* 0x22f7: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_22fc:
	/* 0x22fc: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2301:
	/* 0x2301: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2306:
	/* 0x2306: jne    2313 <generic_tracepoint_process_event_2+0x2313> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2313;
	}
x86_l_2308:
	/* 0x2308: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_230d:
	/* 0x230d: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_2313:
	/* 0x2313: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2318:
	/* 0x2318: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_231d:
	/* 0x231d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2322:
	/* 0x2322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2324:
	/* 0x2324: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_2329:
	/* 0x2329: je     2411 <generic_tracepoint_process_event_2+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2411;
	}
x86_l_232f:
	/* 0x232f: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2334:
	/* 0x2334: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2339:
	/* 0x2339: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_233c:
	/* 0x233c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2341:
	/* 0x2341: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2344:
	/* 0x2344: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2346:
	/* 0x2346: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_234a:
	/* 0x234a: je     2411 <generic_tracepoint_process_event_2+0x2411> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2411;
	}
x86_l_2350:
	/* 0x2350: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2355:
	/* 0x2355: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_235a:
	/* 0x235a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_235f:
	/* 0x235f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_2362:
	/* 0x2362: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2364:
	/* 0x2364: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_2368:
	/* 0x2368: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_236d:
	/* 0x236d: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2372:
	/* 0x2372: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_2377:
	/* 0x2377: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_237a:
	/* 0x237a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237c:
	/* 0x237c: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2381:
	/* 0x2381: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2386:
	/* 0x2386: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_238a:
	/* 0x238a: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_238d:
	/* 0x238d: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2391:
	/* 0x2391: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2393:
	/* 0x2393: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_2395:
	/* 0x2395: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2397:
	/* 0x2397: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_239a:
	/* 0x239a: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_239f:
	/* 0x239f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23a2:
	/* 0x23a2: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_23a4:
	/* 0x23a4: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_23a8:
	/* 0x23a8: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_23aa:
	/* 0x23aa: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_23ad:
	/* 0x23ad: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_23b0:
	/* 0x23b0: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_23b3:
	/* 0x23b3: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_23b6:
	/* 0x23b6: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_23bb:
	/* 0x23bb: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23be:
	/* 0x23be: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_23c1:
	/* 0x23c1: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_23c7:
	/* 0x23c7: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_23ce:
	/* 0x23ce: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_23d4:
	/* 0x23d4: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_23d6:
	/* 0x23d6: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2564;
	}
x86_l_23dc:
	/* 0x23dc: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_23e0:
	/* 0x23e0: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_23e5:
	/* 0x23e5: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23e8:
	/* 0x23e8: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_23ec:
	/* 0x23ec: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_23ef:
	/* 0x23ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_23f4:
	/* 0x23f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23f6:
	/* 0x23f6: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_23fb:
	/* 0x23fb: mov    r12,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2400:
	/* 0x2400: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2405:
	/* 0x2405: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_240a:
	/* 0x240a: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_240f:
	/* 0x240f: jmp    2462 <generic_tracepoint_process_event_2+0x2462> */
	goto x86_l_2462;
x86_l_2411:
	/* 0x2411: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2415:
	/* 0x2415: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_241a:
	/* 0x241a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_241d:
	/* 0x241d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2422:
	/* 0x2422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2424:
	/* 0x2424: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2429:
	/* 0x2429: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_242d:
	/* 0x242d: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b6;
	}
x86_l_2433:
	/* 0x2433: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2437:
	/* 0x2437: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_243c:
	/* 0x243c: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2441:
	/* 0x2441: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2446:
	/* 0x2446: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2449:
	/* 0x2449: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_244b:
	/* 0x244b: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244f:
	/* 0x244f: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2454:
	/* 0x2454: lea    rdx,[r15+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2458:
	/* 0x2458: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_245d:
	/* 0x245d: mov    r12,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2462:
	/* 0x2462: cmp    r12,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_2467:
	/* 0x2467: jne    2474 <generic_tracepoint_process_event_2+0x2474> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2474;
	}
x86_l_2469:
	/* 0x2469: cmp    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_246e:
	/* 0x246e: je     6fb <generic_tracepoint_process_event_2+0x6fb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 1787ULL;
	}
x86_l_2474:
	/* 0x2474: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2479:
	/* 0x2479: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_247e:
	/* 0x247e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2483:
	/* 0x2483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2485:
	/* 0x2485: cmp    r12,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 96ULL);
x86_l_248a:
	/* 0x248a: je     257e <generic_tracepoint_process_event_2+0x257e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257e;
	}
x86_l_2490:
	/* 0x2490: lea    r13,[r12+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2495:
	/* 0x2495: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_249a:
	/* 0x249a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_249d:
	/* 0x249d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24a2:
	/* 0x24a2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_24a5:
	/* 0x24a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24a7:
	/* 0x24a7: cmp    QWORD PTR [rsp],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24ab:
	/* 0x24ab: je     257e <generic_tracepoint_process_event_2+0x257e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_257e;
	}
x86_l_24b1:
	/* 0x24b1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24b6:
	/* 0x24b6: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_24bb:
	/* 0x24bb: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_24c0:
	/* 0x24c0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_24c3:
	/* 0x24c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24c5:
	/* 0x24c5: add    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_24c9:
	/* 0x24c9: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24ce:
	/* 0x24ce: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_24d3:
	/* 0x24d3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_24d8:
	/* 0x24d8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_24db:
	/* 0x24db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24dd:
	/* 0x24dd: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_24e2:
	/* 0x24e2: mov    r15,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_24e7:
	/* 0x24e7: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_24eb:
	/* 0x24eb: sub    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_24ee:
	/* 0x24ee: mov    edi,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_24f2:
	/* 0x24f2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24f4:
	/* 0x24f4: mov    edx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_24f6:
	/* 0x24f6: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_24f8:
	/* 0x24f8: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_24fb:
	/* 0x24fb: add    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 112ULL);
x86_l_2500:
	/* 0x2500: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2503:
	/* 0x2503: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2505:
	/* 0x2505: seta   r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_A);
x86_l_2509:
	/* 0x2509: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_250b:
	/* 0x250b: cmovb  ecx,edi */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDI, X86_WIDTH_32, X86_CC_B);
x86_l_250e:
	/* 0x250e: add    r8d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2511:
	/* 0x2511: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_2514:
	/* 0x2514: sub    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2517:
	/* 0x2517: mov    DWORD PTR [rsp+0x48],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_251c:
	/* 0x251c: sub    r15,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R8, X86_WIDTH_64, X86_ALU_SUB);
x86_l_251f:
	/* 0x251f: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_2522:
	/* 0x2522: jb     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 1797ULL;
	}
x86_l_2528:
	/* 0x2528: cmp    r15,0xfff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 4095ULL);
x86_l_252f:
	/* 0x252f: ja     705 <generic_tracepoint_process_event_2+0x705> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 1797ULL;
	}
x86_l_2535:
	/* 0x2535: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_2537:
	/* 0x2537: jbe    2564 <generic_tracepoint_process_event_2+0x2564> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_2564;
	}
x86_l_2539:
	/* 0x2539: lea    r12,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_253d:
	/* 0x253d: mov    BYTE PTR [rax+r15*1],0x2f */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_R15, 0), 47ULL);
x86_l_2542:
	/* 0x2542: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2545:
	/* 0x2545: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2549:
	/* 0x2549: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_254c:
	/* 0x254c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2551:
	/* 0x2551: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2553:
	/* 0x2553: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2558:
	/* 0x2558: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_255d:
	/* 0x255d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2562:
	/* 0x2562: jmp    25bb <generic_tracepoint_process_event_2+0x25bb> */
	goto x86_l_25bb;
x86_l_2564:
	/* 0x2564: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2567:
	/* 0x2567: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_256a:
	/* 0x256a: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_256f:
	/* 0x256f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2572:
	/* 0x2572: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2574:
	/* 0x2574: mov    QWORD PTR [rsp+0x40],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2579:
	/* 0x2579: jmp    700 <generic_tracepoint_process_event_2+0x700> */
	return 1792ULL;
x86_l_257e:
	/* 0x257e: lea    rdx,[r15+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2582:
	/* 0x2582: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2587:
	/* 0x2587: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_258a:
	/* 0x258a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_258f:
	/* 0x258f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2591:
	/* 0x2591: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2596:
	/* 0x2596: cmp    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_259a:
	/* 0x259a: je     25b6 <generic_tracepoint_process_event_2+0x25b6> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_25b6;
	}
x86_l_259c:
	/* 0x259c: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_25a0:
	/* 0x25a0: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_25a5:
	/* 0x25a5: lea    rdi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25aa:
	/* 0x25aa: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_25af:
	/* 0x25af: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_25b2:
	/* 0x25b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25b4:
	/* 0x25b4: jmp    25bb <generic_tracepoint_process_event_2+0x25bb> */
	goto x86_l_25bb;
x86_l_25b6:
	/* 0x25b6: mov    BYTE PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_25bb:
	/* 0x25bb: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_25c0:
	/* 0x25c0: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_25c3:
	/* 0x25c3: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25c8:
	/* 0x25c8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25ca:
	/* 0x25ca: cmp    rcx,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_25cd:
	/* 0x25cd: jne    71a <generic_tracepoint_process_event_2+0x71a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 1818ULL;
	}
x86_l_25d3:
	/* 0x25d3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d6:
	/* 0x25d6: lea    rdi,[rax+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25da:
	/* 0x25da: and    r15d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_25e1:
	/* 0x25e1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_25e6:
	/* 0x25e6: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_25e9:
	/* 0x25e9: mov    rdx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_25ec:
	/* 0x25ec: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_25ef:
	/* 0x25ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_25f1:
	/* 0x25f1: mov    DWORD PTR [r12],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25f5:
	/* 0x25f5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_25fa:
	/* 0x25fa: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_25ff:
	/* 0x25ff: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2604:
	/* 0x2604: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_260c:
	/* 0x260c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_260e:
	/* 0x260e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2613:
	/* 0x2613: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2618:
	/* 0x2618: add    rdx,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_261c:
	/* 0x261c: lea    rdi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2621:
	/* 0x2621: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2626:
	/* 0x2626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2628:
	/* 0x2628: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_262d:
	/* 0x262d: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2632:
	/* 0x2632: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2635:
	/* 0x2635: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_263a:
	/* 0x263a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_263c:
	/* 0x263c: mov    DWORD PTR [r12+r15*1+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 4ULL);
x86_l_2641:
	/* 0x2641: movzx  eax,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2645:
	/* 0x2645: mov    WORD PTR [r12+r15*1+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_R15, 0), 8ULL);
x86_l_264b:
	/* 0x264b: add    r15d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_264f:
	/* 0x264f: add    r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_2653:
	/* 0x2653: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_2656:
	/* 0x2656: jmp    2ff <generic_tracepoint_process_event_2+0x2ff> */
	return 767ULL;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 8952U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1812ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1818ULL && __x86_pc <= 3472ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 3476ULL && __x86_pc <= 5174ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 5179ULL && __x86_pc <= 6942ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 6947ULL && __x86_pc <= 8531ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 8536ULL && __x86_pc <= 9814ULL)
			__x86_pc = tetragon_bpf_generic_tracepoint_generic_tracepoint_process_event_2_x86_chunk_5(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();

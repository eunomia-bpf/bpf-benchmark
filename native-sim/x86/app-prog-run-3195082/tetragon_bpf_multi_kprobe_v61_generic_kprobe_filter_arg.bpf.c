extern char addr4lpm_maps;
extern char addr6lpm_maps;
extern char argfilter_maps;
extern char filter_map;
extern char heap_ro_zero;
extern char kprobe_calls;
extern char process_call_heap;
extern char retprobe_map;
extern char string_maps_0;
extern char string_maps_1;
extern char string_maps_10;
extern char string_maps_2;
extern char string_maps_3;
extern char string_maps_4;
extern char string_maps_5;
extern char string_maps_6;
extern char string_maps_7;
extern char string_maps_8;
extern char string_maps_9;
extern char string_maps_heap;
extern char string_postfix_maps;
extern char string_postfix_maps_heap;
extern char string_prefix_maps;
extern char string_prefix_maps_heap;
extern char substring_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../x86_sim_local_bpf.h"
#define __x86_sim_abi (__x86_state->xdp_abi)

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_0(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 0ULL: goto x86_l_0;
	case 1ULL: goto x86_l_1;
	case 3ULL: goto x86_l_3;
	case 7ULL: goto x86_l_7;
	case 10ULL: goto x86_l_a;
	case 18ULL: goto x86_l_12;
	case 25ULL: goto x86_l_19;
	case 30ULL: goto x86_l_1e;
	case 35ULL: goto x86_l_23;
	case 37ULL: goto x86_l_25;
	case 40ULL: goto x86_l_28;
	case 46ULL: goto x86_l_2e;
	case 49ULL: goto x86_l_31;
	case 56ULL: goto x86_l_38;
	case 63ULL: goto x86_l_3f;
	case 70ULL: goto x86_l_46;
	case 75ULL: goto x86_l_4b;
	case 77ULL: goto x86_l_4d;
	case 80ULL: goto x86_l_50;
	case 86ULL: goto x86_l_56;
	case 94ULL: goto x86_l_5e;
	case 100ULL: goto x86_l_64;
	case 103ULL: goto x86_l_67;
	case 106ULL: goto x86_l_6a;
	case 109ULL: goto x86_l_6d;
	case 118ULL: goto x86_l_76;
	case 124ULL: goto x86_l_7c;
	case 126ULL: goto x86_l_7e;
	case 131ULL: goto x86_l_83;
	case 135ULL: goto x86_l_87;
	case 139ULL: goto x86_l_8b;
	case 143ULL: goto x86_l_8f;
	case 147ULL: goto x86_l_93;
	case 152ULL: goto x86_l_98;
	case 156ULL: goto x86_l_9c;
	case 159ULL: goto x86_l_9f;
	case 163ULL: goto x86_l_a3;
	case 165ULL: goto x86_l_a5;
	case 171ULL: goto x86_l_ab;
	case 175ULL: goto x86_l_af;
	case 178ULL: goto x86_l_b2;
	case 180ULL: goto x86_l_b4;
	case 185ULL: goto x86_l_b9;
	case 189ULL: goto x86_l_bd;
	case 192ULL: goto x86_l_c0;
	case 194ULL: goto x86_l_c2;
	case 200ULL: goto x86_l_c8;
	case 204ULL: goto x86_l_cc;
	case 207ULL: goto x86_l_cf;
	case 209ULL: goto x86_l_d1;
	case 214ULL: goto x86_l_d6;
	case 218ULL: goto x86_l_da;
	case 221ULL: goto x86_l_dd;
	case 223ULL: goto x86_l_df;
	case 228ULL: goto x86_l_e4;
	case 232ULL: goto x86_l_e8;
	case 237ULL: goto x86_l_ed;
	case 239ULL: goto x86_l_ef;
	case 243ULL: goto x86_l_f3;
	case 247ULL: goto x86_l_f7;
	case 253ULL: goto x86_l_fd;
	case 255ULL: goto x86_l_ff;
	case 261ULL: goto x86_l_105;
	case 265ULL: goto x86_l_109;
	case 267ULL: goto x86_l_10b;
	case 271ULL: goto x86_l_10f;
	case 277ULL: goto x86_l_115;
	case 280ULL: goto x86_l_118;
	case 286ULL: goto x86_l_11e;
	case 290ULL: goto x86_l_122;
	case 296ULL: goto x86_l_128;
	case 298ULL: goto x86_l_12a;
	case 302ULL: goto x86_l_12e;
	case 308ULL: goto x86_l_134;
	case 312ULL: goto x86_l_138;
	case 318ULL: goto x86_l_13e;
	case 322ULL: goto x86_l_142;
	case 328ULL: goto x86_l_148;
	case 332ULL: goto x86_l_14c;
	case 338ULL: goto x86_l_152;
	case 341ULL: goto x86_l_155;
	case 346ULL: goto x86_l_15a;
	case 350ULL: goto x86_l_15e;
	case 353ULL: goto x86_l_161;
	case 358ULL: goto x86_l_166;
	case 364ULL: goto x86_l_16c;
	case 369ULL: goto x86_l_171;
	case 373ULL: goto x86_l_175;
	case 379ULL: goto x86_l_17b;
	case 385ULL: goto x86_l_181;
	case 387ULL: goto x86_l_183;
	case 393ULL: goto x86_l_189;
	case 398ULL: goto x86_l_18e;
	case 401ULL: goto x86_l_191;
	case 407ULL: goto x86_l_197;
	case 410ULL: goto x86_l_19a;
	case 412ULL: goto x86_l_19c;
	case 416ULL: goto x86_l_1a0;
	case 422ULL: goto x86_l_1a6;
	case 431ULL: goto x86_l_1af;
	case 437ULL: goto x86_l_1b5;
	case 445ULL: goto x86_l_1bd;
	case 450ULL: goto x86_l_1c2;
	case 454ULL: goto x86_l_1c6;
	case 461ULL: goto x86_l_1cd;
	case 464ULL: goto x86_l_1d0;
	case 467ULL: goto x86_l_1d3;
	case 469ULL: goto x86_l_1d5;
	case 472ULL: goto x86_l_1d8;
	case 474ULL: goto x86_l_1da;
	case 477ULL: goto x86_l_1dd;
	case 480ULL: goto x86_l_1e0;
	case 486ULL: goto x86_l_1e6;
	case 489ULL: goto x86_l_1e9;
	case 495ULL: goto x86_l_1ef;
	case 500ULL: goto x86_l_1f4;
	case 503ULL: goto x86_l_1f7;
	case 505ULL: goto x86_l_1f9;
	case 508ULL: goto x86_l_1fc;
	case 511ULL: goto x86_l_1ff;
	case 513ULL: goto x86_l_201;
	case 516ULL: goto x86_l_204;
	case 519ULL: goto x86_l_207;
	case 525ULL: goto x86_l_20d;
	case 528ULL: goto x86_l_210;
	case 534ULL: goto x86_l_216;
	case 538ULL: goto x86_l_21a;
	case 543ULL: goto x86_l_21f;
	case 548ULL: goto x86_l_224;
	case 551ULL: goto x86_l_227;
	case 557ULL: goto x86_l_22d;
	case 560ULL: goto x86_l_230;
	case 563ULL: goto x86_l_233;
	case 569ULL: goto x86_l_239;
	case 572ULL: goto x86_l_23c;
	case 575ULL: goto x86_l_23f;
	case 581ULL: goto x86_l_245;
	case 586ULL: goto x86_l_24a;
	case 589ULL: goto x86_l_24d;
	case 595ULL: goto x86_l_253;
	case 598ULL: goto x86_l_256;
	case 600ULL: goto x86_l_258;
	case 603ULL: goto x86_l_25b;
	case 609ULL: goto x86_l_261;
	case 612ULL: goto x86_l_264;
	case 618ULL: goto x86_l_26a;
	case 621ULL: goto x86_l_26d;
	case 623ULL: goto x86_l_26f;
	case 626ULL: goto x86_l_272;
	case 632ULL: goto x86_l_278;
	case 634ULL: goto x86_l_27a;
	case 644ULL: goto x86_l_284;
	case 648ULL: goto x86_l_288;
	case 650ULL: goto x86_l_28a;
	case 655ULL: goto x86_l_28f;
	case 659ULL: goto x86_l_293;
	case 665ULL: goto x86_l_299;
	case 675ULL: goto x86_l_2a3;
	case 679ULL: goto x86_l_2a7;
	case 685ULL: goto x86_l_2ad;
	case 690ULL: goto x86_l_2b2;
	case 695ULL: goto x86_l_2b7;
	case 698ULL: goto x86_l_2ba;
	case 701ULL: goto x86_l_2bd;
	case 707ULL: goto x86_l_2c3;
	case 710ULL: goto x86_l_2c6;
	case 716ULL: goto x86_l_2cc;
	case 719ULL: goto x86_l_2cf;
	case 725ULL: goto x86_l_2d5;
	case 730ULL: goto x86_l_2da;
	case 733ULL: goto x86_l_2dd;
	case 735ULL: goto x86_l_2df;
	case 738ULL: goto x86_l_2e2;
	case 740ULL: goto x86_l_2e4;
	case 743ULL: goto x86_l_2e7;
	case 749ULL: goto x86_l_2ed;
	case 754ULL: goto x86_l_2f2;
	case 759ULL: goto x86_l_2f7;
	case 764ULL: goto x86_l_2fc;
	case 766ULL: goto x86_l_2fe;
	case 769ULL: goto x86_l_301;
	case 771ULL: goto x86_l_303;
	case 774ULL: goto x86_l_306;
	case 777ULL: goto x86_l_309;
	case 779ULL: goto x86_l_30b;
	case 788ULL: goto x86_l_314;
	case 794ULL: goto x86_l_31a;
	case 797ULL: goto x86_l_31d;
	case 805ULL: goto x86_l_325;
	case 811ULL: goto x86_l_32b;
	case 813ULL: goto x86_l_32d;
	case 823ULL: goto x86_l_337;
	case 826ULL: goto x86_l_33a;
	case 828ULL: goto x86_l_33c;
	case 831ULL: goto x86_l_33f;
	case 833ULL: goto x86_l_341;
	case 836ULL: goto x86_l_344;
	case 838ULL: goto x86_l_346;
	case 843ULL: goto x86_l_34b;
	case 845ULL: goto x86_l_34d;
	case 850ULL: goto x86_l_352;
	case 852ULL: goto x86_l_354;
	case 855ULL: goto x86_l_357;
	case 858ULL: goto x86_l_35a;
	case 860ULL: goto x86_l_35c;
	case 865ULL: goto x86_l_361;
	case 867ULL: goto x86_l_363;
	case 872ULL: goto x86_l_368;
	case 874ULL: goto x86_l_36a;
	case 879ULL: goto x86_l_36f;
	case 884ULL: goto x86_l_374;
	case 886ULL: goto x86_l_376;
	case 889ULL: goto x86_l_379;
	case 891ULL: goto x86_l_37b;
	case 896ULL: goto x86_l_380;
	case 899ULL: goto x86_l_383;
	case 905ULL: goto x86_l_389;
	case 908ULL: goto x86_l_38c;
	case 912ULL: goto x86_l_390;
	case 918ULL: goto x86_l_396;
	case 923ULL: goto x86_l_39b;
	case 927ULL: goto x86_l_39f;
	case 934ULL: goto x86_l_3a6;
	case 941ULL: goto x86_l_3ad;
	case 946ULL: goto x86_l_3b2;
	case 951ULL: goto x86_l_3b7;
	case 954ULL: goto x86_l_3ba;
	case 959ULL: goto x86_l_3bf;
	case 961ULL: goto x86_l_3c1;
	case 968ULL: goto x86_l_3c8;
	case 973ULL: goto x86_l_3cd;
	case 978ULL: goto x86_l_3d2;
	case 981ULL: goto x86_l_3d5;
	case 986ULL: goto x86_l_3da;
	case 988ULL: goto x86_l_3dc;
	case 990ULL: goto x86_l_3de;
	case 994ULL: goto x86_l_3e2;
	case 996ULL: goto x86_l_3e4;
	case 997ULL: goto x86_l_3e5;
	case 1002ULL: goto x86_l_3ea;
	case 1005ULL: goto x86_l_3ed;
	case 1013ULL: goto x86_l_3f5;
	case 1015ULL: goto x86_l_3f7;
	case 1021ULL: goto x86_l_3fd;
	case 1029ULL: goto x86_l_405;
	case 1031ULL: goto x86_l_407;
	case 1037ULL: goto x86_l_40d;
	case 1045ULL: goto x86_l_415;
	case 1047ULL: goto x86_l_417;
	case 1053ULL: goto x86_l_41d;
	case 1061ULL: goto x86_l_425;
	case 1063ULL: goto x86_l_427;
	case 1069ULL: goto x86_l_42d;
	case 1077ULL: goto x86_l_435;
	case 1079ULL: goto x86_l_437;
	case 1085ULL: goto x86_l_43d;
	case 1093ULL: goto x86_l_445;
	case 1095ULL: goto x86_l_447;
	case 1102ULL: goto x86_l_44e;
	case 1109ULL: goto x86_l_455;
	case 1114ULL: goto x86_l_45a;
	case 1119ULL: goto x86_l_45f;
	case 1122ULL: goto x86_l_462;
	case 1127ULL: goto x86_l_467;
	case 1129ULL: goto x86_l_469;
	case 1133ULL: goto x86_l_46d;
	case 1138ULL: goto x86_l_472;
	case 1140ULL: goto x86_l_474;
	case 1145ULL: goto x86_l_479;
	case 1150ULL: goto x86_l_47e;
	case 1157ULL: goto x86_l_485;
	case 1162ULL: goto x86_l_48a;
	case 1167ULL: goto x86_l_48f;
	case 1169ULL: goto x86_l_491;
	case 1172ULL: goto x86_l_494;
	case 1178ULL: goto x86_l_49a;
	case 1185ULL: goto x86_l_4a1;
	case 1190ULL: goto x86_l_4a6;
	case 1195ULL: goto x86_l_4ab;
	case 1197ULL: goto x86_l_4ad;
	case 1202ULL: goto x86_l_4b2;
	case 1203ULL: goto x86_l_4b3;
	case 1206ULL: goto x86_l_4b6;
	case 1208ULL: goto x86_l_4b8;
	case 1211ULL: goto x86_l_4bb;
	case 1213ULL: goto x86_l_4bd;
	case 1215ULL: goto x86_l_4bf;
	case 1217ULL: goto x86_l_4c1;
	case 1220ULL: goto x86_l_4c4;
	case 1223ULL: goto x86_l_4c7;
	case 1225ULL: goto x86_l_4c9;
	case 1227ULL: goto x86_l_4cb;
	case 1228ULL: goto x86_l_4cc;
	case 1229ULL: goto x86_l_4cd;
	case 1232ULL: goto x86_l_4d0;
	case 1234ULL: goto x86_l_4d2;
	case 1236ULL: goto x86_l_4d4;
	case 1241ULL: goto x86_l_4d9;
	case 1245ULL: goto x86_l_4dd;
	case 1247ULL: goto x86_l_4df;
	case 1252ULL: goto x86_l_4e4;
	case 1256ULL: goto x86_l_4e8;
	case 1258ULL: goto x86_l_4ea;
	case 1268ULL: goto x86_l_4f4;
	case 1272ULL: goto x86_l_4f8;
	case 1274ULL: goto x86_l_4fa;
	case 1277ULL: goto x86_l_4fd;
	case 1282ULL: goto x86_l_502;
	case 1285ULL: goto x86_l_505;
	case 1288ULL: goto x86_l_508;
	case 1290ULL: goto x86_l_50a;
	case 1292ULL: goto x86_l_50c;
	case 1295ULL: goto x86_l_50f;
	case 1298ULL: goto x86_l_512;
	case 1300ULL: goto x86_l_514;
	case 1304ULL: goto x86_l_518;
	case 1307ULL: goto x86_l_51b;
	case 1312ULL: goto x86_l_520;
	case 1315ULL: goto x86_l_523;
	case 1318ULL: goto x86_l_526;
	case 1320ULL: goto x86_l_528;
	case 1322ULL: goto x86_l_52a;
	case 1326ULL: goto x86_l_52e;
	case 1329ULL: goto x86_l_531;
	case 1334ULL: goto x86_l_536;
	case 1337ULL: goto x86_l_539;
	case 1340ULL: goto x86_l_53c;
	case 1342ULL: goto x86_l_53e;
	case 1344ULL: goto x86_l_540;
	case 1348ULL: goto x86_l_544;
	case 1351ULL: goto x86_l_547;
	case 1356ULL: goto x86_l_54c;
	case 1359ULL: goto x86_l_54f;
	case 1362ULL: goto x86_l_552;
	case 1364ULL: goto x86_l_554;
	case 1366ULL: goto x86_l_556;
	case 1368ULL: goto x86_l_558;
	case 1371ULL: goto x86_l_55b;
	case 1373ULL: goto x86_l_55d;
	case 1375ULL: goto x86_l_55f;
	case 1385ULL: goto x86_l_569;
	case 1389ULL: goto x86_l_56d;
	case 1391ULL: goto x86_l_56f;
	case 1395ULL: goto x86_l_573;
	case 1396ULL: goto x86_l_574;
	case 1397ULL: goto x86_l_575;
	case 1398ULL: goto x86_l_576;
	case 1401ULL: goto x86_l_579;
	case 1403ULL: goto x86_l_57b;
	case 1407ULL: goto x86_l_57f;
	case 1409ULL: goto x86_l_581;
	case 1414ULL: goto x86_l_586;
	case 1418ULL: goto x86_l_58a;
	case 1420ULL: goto x86_l_58c;
	case 1425ULL: goto x86_l_591;
	case 1426ULL: goto x86_l_592;
	case 1427ULL: goto x86_l_593;
	case 1432ULL: goto x86_l_598;
	case 1436ULL: goto x86_l_59c;
	case 1438ULL: goto x86_l_59e;
	case 1448ULL: goto x86_l_5a8;
	case 1452ULL: goto x86_l_5ac;
	case 1454ULL: goto x86_l_5ae;
	case 1459ULL: goto x86_l_5b3;
	case 1460ULL: goto x86_l_5b4;
	case 1461ULL: goto x86_l_5b5;
	case 1466ULL: goto x86_l_5ba;
	case 1467ULL: goto x86_l_5bb;
	case 1468ULL: goto x86_l_5bc;
	case 1470ULL: goto x86_l_5be;
	case 1472ULL: goto x86_l_5c0;
	case 1474ULL: goto x86_l_5c2;
	case 1475ULL: goto x86_l_5c3;
	case 1479ULL: goto x86_l_5c7;
	case 1488ULL: goto x86_l_5d0;
	case 1497ULL: goto x86_l_5d9;
	case 1506ULL: goto x86_l_5e2;
	case 1515ULL: goto x86_l_5eb;
	case 1524ULL: goto x86_l_5f4;
	case 1531ULL: goto x86_l_5fb;
	case 1539ULL: goto x86_l_603;
	case 1542ULL: goto x86_l_606;
	case 1544ULL: goto x86_l_608;
	case 1547ULL: goto x86_l_60b;
	default: return 0xffffffffffffffffULL;
	}
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_12:
	/* 0x12: mov    rdi,QWORD PTR [rip+0x5c97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_19:
	/* 0x19: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1e:
	/* 0x1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23:
	/* 0x23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25:
	/* 0x25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: je     3dc <generic_kprobe_filter_arg+0x3dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3dc;
	}
x86_l_2e:
	/* 0x2e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: mov    r12d,DWORD PTR [rax+0x5f00] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_38:
	/* 0x38: lea    rsi,[rax+0x5ef8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24312ULL);
x86_l_3f:
	/* 0x3f: mov    rdi,QWORD PTR [rip+0x5c97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&filter_map)));
x86_l_46:
	/* 0x46: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b:
	/* 0x4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d:
	/* 0x4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: je     3c1 <generic_kprobe_filter_arg+0x3c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c1;
	}
x86_l_56:
	/* 0x56: cmp    BYTE PTR [r14+0x5ee0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104316165685248ULL);
x86_l_5e:
	/* 0x5e: je     3c1 <generic_kprobe_filter_arg+0x3c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c1;
	}
x86_l_64:
	/* 0x64: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_67:
	/* 0x67: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_6a:
	/* 0x6a: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_6d:
	/* 0x6d: cmp    BYTE PTR [r14+rax*1+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 104183021699072ULL);
x86_l_76:
	/* 0x76: je     105 <generic_kprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105;
	}
x86_l_7c:
	/* 0x7c: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7e:
	/* 0x7e: mov    ecx,DWORD PTR [r15+rax*4+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 4ULL);
x86_l_83:
	/* 0x83: lea    rdx,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_87:
	/* 0x87: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_8b:
	/* 0x8b: lea    rax,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_8f:
	/* 0x8f: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_93:
	/* 0x93: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_98:
	/* 0x98: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_9c:
	/* 0x9c: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9f:
	/* 0x9f: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a3:
	/* 0xa3: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_a5:
	/* 0xa5: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_ab:
	/* 0xab: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_af:
	/* 0xaf: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b2:
	/* 0xb2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_b4:
	/* 0xb4: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_b9:
	/* 0xb9: mov    eax,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_bd:
	/* 0xbd: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c0:
	/* 0xc0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_c2:
	/* 0xc2: and    ecx,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_c8:
	/* 0xc8: mov    ecx,DWORD PTR [rcx+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_cc:
	/* 0xcc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cf:
	/* 0xcf: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_d1:
	/* 0xd1: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_d6:
	/* 0xd6: mov    ebp,DWORD PTR [rax+r15*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_da:
	/* 0xda: add    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dd:
	/* 0xdd: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_df:
	/* 0xdf: and    eax,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_e4:
	/* 0xe4: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8:
	/* 0xe8: cmp    DWORD PTR [r15+rax*1],0x19 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 25ULL);
x86_l_ed:
	/* 0xed: jae    15a <generic_kprobe_filter_arg+0x15a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_15a;
	}
x86_l_ef:
	/* 0xef: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3:
	/* 0xf3: cmp    rax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1ULL);
x86_l_f7:
	/* 0xf7: je     3c1 <generic_kprobe_filter_arg+0x3c1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3c1;
	}
x86_l_fd:
	/* 0xfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ff:
	/* 0xff: jne    39b <generic_kprobe_filter_arg+0x39b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_39b;
	}
x86_l_105:
	/* 0x105: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_109:
	/* 0x109: jg     12a <generic_kprobe_filter_arg+0x12a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_12a;
	}
x86_l_10b:
	/* 0x10b: cmp    r12d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967295ULL);
x86_l_10f:
	/* 0x10f: je     3ea <generic_kprobe_filter_arg+0x3ea> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3ea;
	}
x86_l_115:
	/* 0x115: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_118:
	/* 0x118: je     3f7 <generic_kprobe_filter_arg+0x3f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3f7;
	}
x86_l_11e:
	/* 0x11e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_122:
	/* 0x122: je     407 <generic_kprobe_filter_arg+0x407> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_407;
	}
x86_l_128:
	/* 0x128: jmp    148 <generic_kprobe_filter_arg+0x148> */
	goto x86_l_148;
x86_l_12a:
	/* 0x12a: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_12e:
	/* 0x12e: je     417 <generic_kprobe_filter_arg+0x417> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_417;
	}
x86_l_134:
	/* 0x134: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_138:
	/* 0x138: je     427 <generic_kprobe_filter_arg+0x427> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_427;
	}
x86_l_13e:
	/* 0x13e: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_142:
	/* 0x142: je     437 <generic_kprobe_filter_arg+0x437> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_437;
	}
x86_l_148:
	/* 0x148: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_14c:
	/* 0x14c: jg     469 <generic_kprobe_filter_arg+0x469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_469;
	}
x86_l_152:
	/* 0x152: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_155:
	/* 0x155: jmp    447 <generic_kprobe_filter_arg+0x447> */
	goto x86_l_447;
x86_l_15a:
	/* 0x15a: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e:
	/* 0x15e: add    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_161:
	/* 0x161: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_166:
	/* 0x166: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_16c:
	/* 0x16c: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171:
	/* 0x171: mov    edi,DWORD PTR [rax+r13*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 2), 0ULL);
x86_l_175:
	/* 0x175: test   edi,0x3ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 1023ULL);
x86_l_17b:
	/* 0x17b: je     ef <generic_kprobe_filter_arg+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_ef;
	}
x86_l_181:
	/* 0x181: add    edi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_183:
	/* 0x183: and    edi,0x3ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 1023ULL);
x86_l_189:
	/* 0x189: mov    ecx,DWORD PTR [r15+rdi*1+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 4ULL);
x86_l_18e:
	/* 0x18e: cmp    ecx,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 35ULL);
x86_l_191:
	/* 0x191: je     105 <generic_kprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105;
	}
x86_l_197:
	/* 0x197: add    rdi,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19a:
	/* 0x19a: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c:
	/* 0x19c: cmp    rax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4ULL);
x86_l_1a0:
	/* 0x1a0: ja     105 <generic_kprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_105;
	}
x86_l_1a6:
	/* 0x1a6: cmp    DWORD PTR [r14+rax*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 104041287778304ULL);
x86_l_1af:
	/* 0x1af: jne    105 <generic_kprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105;
	}
x86_l_1b5:
	/* 0x1b5: mov    rax,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_1bd:
	/* 0x1bd: and    eax,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_1c2:
	/* 0x1c2: lea    rsi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1c6:
	/* 0x1c6: add    rsi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_1cd:
	/* 0x1cd: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1d0:
	/* 0x1d0: cmp    eax,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 27ULL);
x86_l_1d3:
	/* 0x1d3: jle    1f4 <generic_kprobe_filter_arg+0x1f4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1f4;
	}
x86_l_1d5:
	/* 0x1d5: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1d8:
	/* 0x1d8: jg     224 <generic_kprobe_filter_arg+0x224> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_224;
	}
x86_l_1da:
	/* 0x1da: lea    edx,[rax-0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551588ULL);
x86_l_1dd:
	/* 0x1dd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_1e0:
	/* 0x1e0: jb     26a <generic_kprobe_filter_arg+0x26a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26a;
	}
x86_l_1e6:
	/* 0x1e6: cmp    eax,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 37ULL);
x86_l_1e9:
	/* 0x1e9: je     34d <generic_kprobe_filter_arg+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d;
	}
x86_l_1ef:
	/* 0x1ef: jmp    389 <generic_kprobe_filter_arg+0x389> */
	goto x86_l_389;
x86_l_1f4:
	/* 0x1f4: cmp    eax,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1f7:
	/* 0x1f7: jle    24a <generic_kprobe_filter_arg+0x24a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_24a;
	}
x86_l_1f9:
	/* 0x1f9: lea    edx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_1fc:
	/* 0x1fc: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_1ff:
	/* 0x1ff: jb     26a <generic_kprobe_filter_arg+0x26a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_26a;
	}
x86_l_201:
	/* 0x201: lea    ecx,[rax-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_204:
	/* 0x204: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_207:
	/* 0x207: jb     34d <generic_kprobe_filter_arg+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_34d;
	}
x86_l_20d:
	/* 0x20d: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_210:
	/* 0x210: jne    389 <generic_kprobe_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_216:
	/* 0x216: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_21a:
	/* 0x21a: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 543ULL);
	__x86_sim_call_depth++;
	goto x86_l_4b2;
x86_l_21f:
	/* 0x21f: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_224:
	/* 0x224: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_227:
	/* 0x227: jg     33c <generic_kprobe_filter_arg+0x33c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_33c;
	}
x86_l_22d:
	/* 0x22d: lea    ecx,[rax-0x26] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551578ULL);
x86_l_230:
	/* 0x230: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_233:
	/* 0x233: jb     2f7 <generic_kprobe_filter_arg+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2f7;
	}
x86_l_239:
	/* 0x239: add    eax,0xffffffd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967256ULL);
x86_l_23c:
	/* 0x23c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23f:
	/* 0x23f: jb     2ed <generic_kprobe_filter_arg+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2ed;
	}
x86_l_245:
	/* 0x245: jmp    389 <generic_kprobe_filter_arg+0x389> */
	goto x86_l_389;
x86_l_24a:
	/* 0x24a: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_24d:
	/* 0x24d: jg     2da <generic_kprobe_filter_arg+0x2da> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2da;
	}
x86_l_253:
	/* 0x253: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_256:
	/* 0x256: je     26a <generic_kprobe_filter_arg+0x26a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_26a;
	}
x86_l_258:
	/* 0x258: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_25b:
	/* 0x25b: je     36a <generic_kprobe_filter_arg+0x36a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_36a;
	}
x86_l_261:
	/* 0x261: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_264:
	/* 0x264: jne    389 <generic_kprobe_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_26a:
	/* 0x26a: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_26d:
	/* 0x26d: jle    2b7 <generic_kprobe_filter_arg+0x2b7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_2b7;
	}
x86_l_26f:
	/* 0x26f: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_272:
	/* 0x272: ja     354 <generic_kprobe_filter_arg+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_354;
	}
x86_l_278:
	/* 0x278: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_27a:
	/* 0x27a: movabs r8,0x1e00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 128849018880ULL);
x86_l_284:
	/* 0x284: bt     r8,rdx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RDX, X86_WIDTH_64);
x86_l_288:
	/* 0x288: jb     2fe <generic_kprobe_filter_arg+0x2fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2fe;
	}
x86_l_28a:
	/* 0x28a: mov    ecx,0x60000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1610612736ULL);
x86_l_28f:
	/* 0x28f: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: jb     363 <generic_kprobe_filter_arg+0x363> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_363;
	}
x86_l_299:
	/* 0x299: movabs rcx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 6442450944ULL);
x86_l_2a3:
	/* 0x2a3: bt     rcx,rdx */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: jae    354 <generic_kprobe_filter_arg+0x354> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_354;
	}
x86_l_2ad:
	/* 0x2ad: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 690ULL);
	__x86_sim_call_depth++;
	goto x86_l_575;
x86_l_2b2:
	/* 0x2b2: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_2b7:
	/* 0x2b7: lea    ecx,[rax-0xa] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551606ULL);
x86_l_2ba:
	/* 0x2ba: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2bd:
	/* 0x2bd: jb     37b <generic_kprobe_filter_arg+0x37b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_37b;
	}
x86_l_2c3:
	/* 0x2c3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c6:
	/* 0x2c6: je     35c <generic_kprobe_filter_arg+0x35c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c;
	}
x86_l_2cc:
	/* 0x2cc: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2cf:
	/* 0x2cf: je     35c <generic_kprobe_filter_arg+0x35c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_35c;
	}
x86_l_2d5:
	/* 0x2d5: jmp    389 <generic_kprobe_filter_arg+0x389> */
	goto x86_l_389;
x86_l_2da:
	/* 0x2da: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_2dd:
	/* 0x2dd: je     2ed <generic_kprobe_filter_arg+0x2ed> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2ed;
	}
x86_l_2df:
	/* 0x2df: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_2e2:
	/* 0x2e2: je     2f7 <generic_kprobe_filter_arg+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_2f7;
	}
x86_l_2e4:
	/* 0x2e4: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_2e7:
	/* 0x2e7: jne    389 <generic_kprobe_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_2ed:
	/* 0x2ed: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 754ULL);
	__x86_sim_call_depth++;
	goto x86_l_5bc;
x86_l_2f2:
	/* 0x2f2: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_2f7:
	/* 0x2f7: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_2fc:
	/* 0x2fc: jmp    36f <generic_kprobe_filter_arg+0x36f> */
	goto x86_l_36f;
x86_l_2fe:
	/* 0x2fe: cmp    ecx,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 30ULL);
x86_l_301:
	/* 0x301: jne    37b <generic_kprobe_filter_arg+0x37b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_37b;
	}
x86_l_303:
	/* 0x303: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_306:
	/* 0x306: and    eax,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 7ULL);
x86_l_309:
	/* 0x309: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_30b:
	/* 0x30b: cmp    DWORD PTR [r14+rcx*4+0x5ea0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 104041287778304ULL);
x86_l_314:
	/* 0x314: jne    105 <generic_kprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_105;
	}
x86_l_31a:
	/* 0x31a: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31d:
	/* 0x31d: mov    rdx,QWORD PTR [r14+rax*8+0x5e78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 3), 24184ULL);
x86_l_325:
	/* 0x325: and    edx,0x7ff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 2047ULL);
x86_l_32b:
	/* 0x32b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_32d:
	/* 0x32d: andn   rcx,rcx,QWORD PTR [r14+rdx*1+0x90] */
	X86_SIM_L_EXEC_ANDN_MEM(X86_RCX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_R14)), 144ULL);
x86_l_337:
	/* 0x337: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_33a:
	/* 0x33a: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_33c:
	/* 0x33c: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_33f:
	/* 0x33f: je     34d <generic_kprobe_filter_arg+0x34d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_34d;
	}
x86_l_341:
	/* 0x341: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_344:
	/* 0x344: jne    389 <generic_kprobe_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_346:
	/* 0x346: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 843ULL);
	__x86_sim_call_depth++;
	return 2301ULL;
x86_l_34b:
	/* 0x34b: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_34d:
	/* 0x34d: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 850ULL);
	__x86_sim_call_depth++;
	goto x86_l_4b2;
x86_l_352:
	/* 0x352: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_354:
	/* 0x354: lea    ecx,[rax-0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551604ULL);
x86_l_357:
	/* 0x357: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_35a:
	/* 0x35a: jae    376 <generic_kprobe_filter_arg+0x376> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_376;
	}
x86_l_35c:
	/* 0x35c: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 865ULL);
	__x86_sim_call_depth++;
	return 2472ULL;
x86_l_361:
	/* 0x361: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_363:
	/* 0x363: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 872ULL);
	__x86_sim_call_depth++;
	return 2543ULL;
x86_l_368:
	/* 0x368: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_36a:
	/* 0x36a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_36f:
	/* 0x36f: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 884ULL);
	__x86_sim_call_depth++;
	return 2614ULL;
x86_l_374:
	/* 0x374: jmp    380 <generic_kprobe_filter_arg+0x380> */
	goto x86_l_380;
x86_l_376:
	/* 0x376: cmp    eax,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_379:
	/* 0x379: jne    389 <generic_kprobe_filter_arg+0x389> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_389;
	}
x86_l_37b:
	/* 0x37b: call   0 <generic_kprobe_filter_arg> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 896ULL);
	__x86_sim_call_depth++;
	return 2777ULL;
x86_l_380:
	/* 0x380: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_383:
	/* 0x383: je     105 <generic_kprobe_filter_arg+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_105;
	}
x86_l_389:
	/* 0x389: inc    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_38c:
	/* 0x38c: cmp    r13,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 6ULL);
x86_l_390:
	/* 0x390: jne    16c <generic_kprobe_filter_arg+0x16c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16c;
	}
x86_l_396:
	/* 0x396: jmp    ef <generic_kprobe_filter_arg+0xef> */
	goto x86_l_ef;
x86_l_39b:
	/* 0x39b: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39f:
	/* 0x39f: mov    DWORD PTR [r14+0x5f04],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24324ULL);
x86_l_3a6:
	/* 0x3a6: mov    rsi,QWORD PTR [rip+0x5cb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_3ad:
	/* 0x3ad: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_3b2:
	/* 0x3b2: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3b7:
	/* 0x3b7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3ba:
	/* 0x3ba: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_3bf:
	/* 0x3bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1:
	/* 0x3c1: mov    rsi,QWORD PTR [rip+0x5cb0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_3c8:
	/* 0x3c8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_3cd:
	/* 0x3cd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3d2:
	/* 0x3d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3d5:
	/* 0x3d5: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_3da:
	/* 0x3da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc:
	/* 0x3dc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3de:
	/* 0x3de: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3e2:
	/* 0x3e2: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3e4:
	/* 0x3e4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3e5:
	/* 0x3e5: jmp    24d3 <filter_file_type+0xa4> ; native-link entry RET */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_3ea:
	/* 0x3ea: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ed:
	/* 0x3ed: cmp    BYTE PTR [r14+0x5ec1],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104183021699072ULL);
x86_l_3f5:
	/* 0x3f5: jne    447 <generic_kprobe_filter_arg+0x447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_447;
	}
x86_l_3f7:
	/* 0x3f7: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_3fd:
	/* 0x3fd: cmp    BYTE PTR [r14+0x5ec2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104187316666368ULL);
x86_l_405:
	/* 0x405: jne    447 <generic_kprobe_filter_arg+0x447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_447;
	}
x86_l_407:
	/* 0x407: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_40d:
	/* 0x40d: cmp    BYTE PTR [r14+0x5ec3],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104191611633664ULL);
x86_l_415:
	/* 0x415: jne    447 <generic_kprobe_filter_arg+0x447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_447;
	}
x86_l_417:
	/* 0x417: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_41d:
	/* 0x41d: cmp    BYTE PTR [r14+0x5ec4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104195906600960ULL);
x86_l_425:
	/* 0x425: jne    447 <generic_kprobe_filter_arg+0x447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_447;
	}
x86_l_427:
	/* 0x427: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_42d:
	/* 0x42d: cmp    BYTE PTR [r14+0x5ec5],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104200201568256ULL);
x86_l_435:
	/* 0x435: jne    447 <generic_kprobe_filter_arg+0x447> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_447;
	}
x86_l_437:
	/* 0x437: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_43d:
	/* 0x43d: cmp    BYTE PTR [r14+0x5ec6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104204496535552ULL);
x86_l_445:
	/* 0x445: je     469 <generic_kprobe_filter_arg+0x469> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_469;
	}
x86_l_447:
	/* 0x447: mov    DWORD PTR [r14+0x5f00],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24320ULL);
x86_l_44e:
	/* 0x44e: mov    rsi,QWORD PTR [rip+0x5cb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&kprobe_calls)));
x86_l_455:
	/* 0x455: mov    ecx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_45a:
	/* 0x45a: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_45f:
	/* 0x45f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_462:
	/* 0x462: mov    edx,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_467:
	/* 0x467: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_469:
	/* 0x469: mov    rbx,QWORD PTR [r14+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46d:
	/* 0x46d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_472:
	/* 0x472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_479:
	/* 0x479: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47e:
	/* 0x47e: mov    rdi,QWORD PTR [rip+0x5cb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_485:
	/* 0x485: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48a:
	/* 0x48a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_48f:
	/* 0x48f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_491:
	/* 0x491: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_494:
	/* 0x494: je     3dc <generic_kprobe_filter_arg+0x3dc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_3dc;
	}
x86_l_49a:
	/* 0x49a: mov    rdi,QWORD PTR [rip+0x5cb3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&retprobe_map)));
x86_l_4a1:
	/* 0x4a1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a6:
	/* 0x4a6: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_4ab:
	/* 0x4ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ad:
	/* 0x4ad: jmp    3dc <generic_kprobe_filter_arg+0x3dc> */
	goto x86_l_3dc;
x86_l_4b2:
	/* 0x4b2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_4b3:
	/* 0x4b3: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4b6:
	/* 0x4b6: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b8:
	/* 0x4b8: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4bb:
	/* 0x4bb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_4bd:
	/* 0x4bd: jne    4cd <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_4cd;
	}
x86_l_4bf:
	/* 0x4bf: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_4c1:
	/* 0x4c1: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_4c4:
	/* 0x4c4: cmp    eax,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_4c7:
	/* 0x4c7: je     4cd <filter_file_buf+0x1b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_4cd;
	}
x86_l_4c9:
	/* 0x4c9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4cb:
	/* 0x4cb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_4cc:
	/* 0x4cc: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_4cd:
	/* 0x4cd: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_4d0:
	/* 0x4d0: ja     50c <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_50c;
	}
x86_l_4d2:
	/* 0x4d2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_4d4:
	/* 0x4d4: mov    edi,0x4000100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 67109120ULL);
x86_l_4d9:
	/* 0x4d9: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4dd:
	/* 0x4dd: jb     540 <filter_file_buf+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_540;
	}
x86_l_4df:
	/* 0x4df: mov    edi,0x8000200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 134218240ULL);
x86_l_4e4:
	/* 0x4e4: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4e8:
	/* 0x4e8: jb     52a <filter_file_buf+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_52a;
	}
x86_l_4ea:
	/* 0x4ea: movabs rdi,0x3000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 206158430208ULL);
x86_l_4f4:
	/* 0x4f4: bt     rdi,rax */
	X86_SIM_L_EXEC_BT(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: jae    50c <filter_file_buf+0x5a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_50c;
	}
x86_l_4fa:
	/* 0x4fa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4fd:
	/* 0x4fd: call   242f <filter_file_type> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1282ULL);
	__x86_sim_call_depth++;
	return 9263ULL;
x86_l_502:
	/* 0x502: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_505:
	/* 0x505: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_508:
	/* 0x508: jbe    55d <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_55d;
	}
x86_l_50a:
	/* 0x50a: jmp    573 <filter_file_buf+0xc1> */
	goto x86_l_573;
x86_l_50c:
	/* 0x50c: lea    eax,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_50f:
	/* 0x50f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_512:
	/* 0x512: jae    556 <filter_file_buf+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_556;
	}
x86_l_514:
	/* 0x514: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_518:
	/* 0x518: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_51b:
	/* 0x51b: call   118d <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1312ULL);
	__x86_sim_call_depth++;
	return 4493ULL;
x86_l_520:
	/* 0x520: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_523:
	/* 0x523: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_526:
	/* 0x526: jbe    55d <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_55d;
	}
x86_l_528:
	/* 0x528: jmp    573 <filter_file_buf+0xc1> */
	goto x86_l_573;
x86_l_52a:
	/* 0x52a: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_52e:
	/* 0x52e: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_531:
	/* 0x531: call   fa5 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1334ULL);
	__x86_sim_call_depth++;
	return 4005ULL;
x86_l_536:
	/* 0x536: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_539:
	/* 0x539: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_53c:
	/* 0x53c: jbe    55d <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_55d;
	}
x86_l_53e:
	/* 0x53e: jmp    573 <filter_file_buf+0xc1> */
	goto x86_l_573;
x86_l_540:
	/* 0x540: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_544:
	/* 0x544: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_547:
	/* 0x547: call   10ed <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1356ULL);
	__x86_sim_call_depth++;
	return 4333ULL;
x86_l_54c:
	/* 0x54c: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_54f:
	/* 0x54f: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_552:
	/* 0x552: jbe    55d <filter_file_buf+0xab> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_55d;
	}
x86_l_554:
	/* 0x554: jmp    573 <filter_file_buf+0xc1> */
	goto x86_l_573;
x86_l_556:
	/* 0x556: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_558:
	/* 0x558: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_55b:
	/* 0x55b: ja     573 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_573;
	}
x86_l_55d:
	/* 0x55d: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_55f:
	/* 0x55f: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_569:
	/* 0x569: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_56d:
	/* 0x56d: jae    573 <filter_file_buf+0xc1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_573;
	}
x86_l_56f:
	/* 0x56f: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_573:
	/* 0x573: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_574:
	/* 0x574: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_575:
	/* 0x575: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_576:
	/* 0x576: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_579:
	/* 0x579: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57b:
	/* 0x57b: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_57f:
	/* 0x57f: ja     5ba <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_5ba;
	}
x86_l_581:
	/* 0x581: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_586:
	/* 0x586: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_58a:
	/* 0x58a: jae    593 <filter_8ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_593;
	}
x86_l_58c:
	/* 0x58c: call   1fd7 <filter_8ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1425ULL);
	__x86_sim_call_depth++;
	return 8151ULL;
x86_l_591:
	/* 0x591: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_592:
	/* 0x592: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_593:
	/* 0x593: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_598:
	/* 0x598: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: jb     5b5 <filter_8ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_5b5;
	}
x86_l_59e:
	/* 0x59e: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_5a8:
	/* 0x5a8: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_5ac:
	/* 0x5ac: jae    5ba <filter_8ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_5ba;
	}
x86_l_5ae:
	/* 0x5ae: call   21f1 <filter_8ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1459ULL);
	__x86_sim_call_depth++;
	return 8689ULL;
x86_l_5b3:
	/* 0x5b3: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5b4:
	/* 0x5b4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5b5:
	/* 0x5b5: call   23a9 <filter_8ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 1466ULL);
	__x86_sim_call_depth++;
	return 9129ULL;
x86_l_5ba:
	/* 0x5ba: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_5bc:
	/* 0x5bc: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_5be:
	/* 0x5be: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_5c0:
	/* 0x5c0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_5c2:
	/* 0x5c2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_5c3:
	/* 0x5c3: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_5c7:
	/* 0x5c7: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_5d0:
	/* 0x5d0: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_5d9:
	/* 0x5d9: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5e2:
	/* 0x5e2: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5eb:
	/* 0x5eb: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5f4:
	/* 0x5f4: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fb:
	/* 0x5fb: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_603:
	/* 0x603: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_606:
	/* 0x606: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_608:
	/* 0x608: cmp    edx,0x27 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_60b:
	/* 0x60b: jg     623 <filter_inet+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 1571ULL;
	}
	return 1549ULL;
}

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_1(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 1549ULL: goto x86_l_60d;
	case 1552ULL: goto x86_l_610;
	case 1558ULL: goto x86_l_616;
	case 1561ULL: goto x86_l_619;
	case 1564ULL: goto x86_l_61c;
	case 1566ULL: goto x86_l_61e;
	case 1571ULL: goto x86_l_623;
	case 1574ULL: goto x86_l_626;
	case 1576ULL: goto x86_l_628;
	case 1579ULL: goto x86_l_62b;
	case 1582ULL: goto x86_l_62e;
	case 1588ULL: goto x86_l_634;
	case 1591ULL: goto x86_l_637;
	case 1593ULL: goto x86_l_639;
	case 1596ULL: goto x86_l_63c;
	case 1598ULL: goto x86_l_63e;
	case 1601ULL: goto x86_l_641;
	case 1603ULL: goto x86_l_643;
	case 1606ULL: goto x86_l_646;
	case 1609ULL: goto x86_l_649;
	case 1615ULL: goto x86_l_64f;
	case 1618ULL: goto x86_l_652;
	case 1621ULL: goto x86_l_655;
	case 1627ULL: goto x86_l_65b;
	case 1632ULL: goto x86_l_660;
	case 1635ULL: goto x86_l_663;
	case 1641ULL: goto x86_l_669;
	case 1644ULL: goto x86_l_66c;
	case 1650ULL: goto x86_l_672;
	case 1653ULL: goto x86_l_675;
	case 1659ULL: goto x86_l_67b;
	case 1664ULL: goto x86_l_680;
	case 1667ULL: goto x86_l_683;
	case 1672ULL: goto x86_l_688;
	case 1676ULL: goto x86_l_68c;
	case 1681ULL: goto x86_l_691;
	case 1685ULL: goto x86_l_695;
	case 1690ULL: goto x86_l_69a;
	case 1694ULL: goto x86_l_69e;
	case 1699ULL: goto x86_l_6a3;
	case 1704ULL: goto x86_l_6a8;
	case 1707ULL: goto x86_l_6ab;
	case 1710ULL: goto x86_l_6ae;
	case 1712ULL: goto x86_l_6b0;
	case 1715ULL: goto x86_l_6b3;
	case 1717ULL: goto x86_l_6b5;
	case 1720ULL: goto x86_l_6b8;
	case 1722ULL: goto x86_l_6ba;
	case 1725ULL: goto x86_l_6bd;
	case 1727ULL: goto x86_l_6bf;
	case 1730ULL: goto x86_l_6c2;
	case 1732ULL: goto x86_l_6c4;
	case 1735ULL: goto x86_l_6c7;
	case 1741ULL: goto x86_l_6cd;
	case 1745ULL: goto x86_l_6d1;
	case 1750ULL: goto x86_l_6d6;
	case 1753ULL: goto x86_l_6d9;
	case 1759ULL: goto x86_l_6df;
	case 1762ULL: goto x86_l_6e2;
	case 1768ULL: goto x86_l_6e8;
	case 1771ULL: goto x86_l_6eb;
	case 1773ULL: goto x86_l_6ed;
	case 1778ULL: goto x86_l_6f2;
	case 1781ULL: goto x86_l_6f5;
	case 1783ULL: goto x86_l_6f7;
	case 1786ULL: goto x86_l_6fa;
	case 1792ULL: goto x86_l_700;
	case 1796ULL: goto x86_l_704;
	case 1798ULL: goto x86_l_706;
	case 1802ULL: goto x86_l_70a;
	case 1806ULL: goto x86_l_70e;
	case 1808ULL: goto x86_l_710;
	case 1811ULL: goto x86_l_713;
	case 1814ULL: goto x86_l_716;
	case 1816ULL: goto x86_l_718;
	case 1819ULL: goto x86_l_71b;
	case 1821ULL: goto x86_l_71d;
	case 1824ULL: goto x86_l_720;
	case 1827ULL: goto x86_l_723;
	case 1833ULL: goto x86_l_729;
	case 1836ULL: goto x86_l_72c;
	case 1839ULL: goto x86_l_72f;
	case 1845ULL: goto x86_l_735;
	case 1848ULL: goto x86_l_738;
	case 1854ULL: goto x86_l_73e;
	case 1859ULL: goto x86_l_743;
	case 1862ULL: goto x86_l_746;
	case 1868ULL: goto x86_l_74c;
	case 1871ULL: goto x86_l_74f;
	case 1877ULL: goto x86_l_755;
	case 1880ULL: goto x86_l_758;
	case 1886ULL: goto x86_l_75e;
	case 1889ULL: goto x86_l_761;
	case 1895ULL: goto x86_l_767;
	case 1900ULL: goto x86_l_76c;
	case 1904ULL: goto x86_l_770;
	case 1908ULL: goto x86_l_774;
	case 1910ULL: goto x86_l_776;
	case 1913ULL: goto x86_l_779;
	case 1917ULL: goto x86_l_77d;
	case 1920ULL: goto x86_l_780;
	case 1924ULL: goto x86_l_784;
	case 1926ULL: goto x86_l_786;
	case 1928ULL: goto x86_l_788;
	case 1931ULL: goto x86_l_78b;
	case 1933ULL: goto x86_l_78d;
	case 1936ULL: goto x86_l_790;
	case 1938ULL: goto x86_l_792;
	case 1944ULL: goto x86_l_798;
	case 1948ULL: goto x86_l_79c;
	case 1950ULL: goto x86_l_79e;
	case 1956ULL: goto x86_l_7a4;
	case 1960ULL: goto x86_l_7a8;
	case 1962ULL: goto x86_l_7aa;
	case 1967ULL: goto x86_l_7af;
	case 1970ULL: goto x86_l_7b2;
	case 1972ULL: goto x86_l_7b4;
	case 1976ULL: goto x86_l_7b8;
	case 1979ULL: goto x86_l_7bb;
	case 1981ULL: goto x86_l_7bd;
	case 1984ULL: goto x86_l_7c0;
	case 1990ULL: goto x86_l_7c6;
	case 1993ULL: goto x86_l_7c9;
	case 1996ULL: goto x86_l_7cc;
	case 2000ULL: goto x86_l_7d0;
	case 2007ULL: goto x86_l_7d7;
	case 2012ULL: goto x86_l_7dc;
	case 2017ULL: goto x86_l_7e1;
	case 2019ULL: goto x86_l_7e3;
	case 2022ULL: goto x86_l_7e6;
	case 2028ULL: goto x86_l_7ec;
	case 2031ULL: goto x86_l_7ef;
	case 2039ULL: goto x86_l_7f7;
	case 2043ULL: goto x86_l_7fb;
	case 2045ULL: goto x86_l_7fd;
	case 2048ULL: goto x86_l_800;
	case 2051ULL: goto x86_l_803;
	case 2057ULL: goto x86_l_809;
	case 2062ULL: goto x86_l_80e;
	case 2067ULL: goto x86_l_813;
	case 2069ULL: goto x86_l_815;
	case 2075ULL: goto x86_l_81b;
	case 2078ULL: goto x86_l_81e;
	case 2083ULL: goto x86_l_823;
	case 2085ULL: goto x86_l_825;
	case 2091ULL: goto x86_l_82b;
	case 2094ULL: goto x86_l_82e;
	case 2099ULL: goto x86_l_833;
	case 2102ULL: goto x86_l_836;
	case 2105ULL: goto x86_l_839;
	case 2109ULL: goto x86_l_83d;
	case 2116ULL: goto x86_l_844;
	case 2121ULL: goto x86_l_849;
	case 2126ULL: goto x86_l_84e;
	case 2128ULL: goto x86_l_850;
	case 2131ULL: goto x86_l_853;
	case 2133ULL: goto x86_l_855;
	case 2136ULL: goto x86_l_858;
	case 2144ULL: goto x86_l_860;
	case 2148ULL: goto x86_l_864;
	case 2153ULL: goto x86_l_869;
	case 2158ULL: goto x86_l_86e;
	case 2162ULL: goto x86_l_872;
	case 2167ULL: goto x86_l_877;
	case 2172ULL: goto x86_l_87c;
	case 2177ULL: goto x86_l_881;
	case 2179ULL: goto x86_l_883;
	case 2184ULL: goto x86_l_888;
	case 2187ULL: goto x86_l_88b;
	case 2190ULL: goto x86_l_88e;
	case 2192ULL: goto x86_l_890;
	case 2195ULL: goto x86_l_893;
	case 2198ULL: goto x86_l_896;
	case 2200ULL: goto x86_l_898;
	case 2203ULL: goto x86_l_89b;
	case 2206ULL: goto x86_l_89e;
	case 2209ULL: goto x86_l_8a1;
	case 2211ULL: goto x86_l_8a3;
	case 2213ULL: goto x86_l_8a5;
	case 2216ULL: goto x86_l_8a8;
	case 2218ULL: goto x86_l_8aa;
	case 2222ULL: goto x86_l_8ae;
	case 2225ULL: goto x86_l_8b1;
	case 2228ULL: goto x86_l_8b4;
	case 2233ULL: goto x86_l_8b9;
	case 2237ULL: goto x86_l_8bd;
	case 2238ULL: goto x86_l_8be;
	case 2240ULL: goto x86_l_8c0;
	case 2242ULL: goto x86_l_8c2;
	case 2244ULL: goto x86_l_8c4;
	case 2245ULL: goto x86_l_8c5;
	case 2250ULL: goto x86_l_8ca;
	case 2253ULL: goto x86_l_8cd;
	case 2256ULL: goto x86_l_8d0;
	case 2258ULL: goto x86_l_8d2;
	case 2261ULL: goto x86_l_8d5;
	case 2264ULL: goto x86_l_8d8;
	case 2267ULL: goto x86_l_8db;
	case 2269ULL: goto x86_l_8dd;
	case 2272ULL: goto x86_l_8e0;
	case 2274ULL: goto x86_l_8e2;
	case 2277ULL: goto x86_l_8e5;
	case 2279ULL: goto x86_l_8e7;
	case 2284ULL: goto x86_l_8ec;
	case 2287ULL: goto x86_l_8ef;
	case 2290ULL: goto x86_l_8f2;
	case 2292ULL: goto x86_l_8f4;
	case 2295ULL: goto x86_l_8f7;
	case 2297ULL: goto x86_l_8f9;
	case 2299ULL: goto x86_l_8fb;
	case 2301ULL: goto x86_l_8fd;
	case 2302ULL: goto x86_l_8fe;
	case 2306ULL: goto x86_l_902;
	case 2309ULL: goto x86_l_905;
	case 2313ULL: goto x86_l_909;
	case 2317ULL: goto x86_l_90d;
	case 2321ULL: goto x86_l_911;
	case 2323ULL: goto x86_l_913;
	case 2327ULL: goto x86_l_917;
	case 2329ULL: goto x86_l_919;
	case 2333ULL: goto x86_l_91d;
	case 2336ULL: goto x86_l_920;
	case 2338ULL: goto x86_l_922;
	case 2341ULL: goto x86_l_925;
	case 2346ULL: goto x86_l_92a;
	case 2349ULL: goto x86_l_92d;
	case 2353ULL: goto x86_l_931;
	case 2355ULL: goto x86_l_933;
	case 2365ULL: goto x86_l_93d;
	case 2369ULL: goto x86_l_941;
	case 2371ULL: goto x86_l_943;
	case 2375ULL: goto x86_l_947;
	case 2379ULL: goto x86_l_94b;
	case 2380ULL: goto x86_l_94c;
	case 2381ULL: goto x86_l_94d;
	case 2385ULL: goto x86_l_951;
	case 2387ULL: goto x86_l_953;
	case 2391ULL: goto x86_l_957;
	case 2393ULL: goto x86_l_959;
	case 2395ULL: goto x86_l_95b;
	case 2399ULL: goto x86_l_95f;
	case 2401ULL: goto x86_l_961;
	case 2404ULL: goto x86_l_964;
	case 2407ULL: goto x86_l_967;
	case 2409ULL: goto x86_l_969;
	case 2414ULL: goto x86_l_96e;
	case 2417ULL: goto x86_l_971;
	case 2421ULL: goto x86_l_975;
	case 2423ULL: goto x86_l_977;
	case 2433ULL: goto x86_l_981;
	case 2437ULL: goto x86_l_985;
	case 2439ULL: goto x86_l_987;
	case 2443ULL: goto x86_l_98b;
	case 2447ULL: goto x86_l_98f;
	case 2448ULL: goto x86_l_990;
	case 2449ULL: goto x86_l_991;
	case 2452ULL: goto x86_l_994;
	case 2456ULL: goto x86_l_998;
	case 2461ULL: goto x86_l_99d;
	case 2466ULL: goto x86_l_9a2;
	case 2470ULL: goto x86_l_9a6;
	case 2471ULL: goto x86_l_9a7;
	case 2472ULL: goto x86_l_9a8;
	case 2473ULL: goto x86_l_9a9;
	case 2476ULL: goto x86_l_9ac;
	case 2478ULL: goto x86_l_9ae;
	case 2482ULL: goto x86_l_9b2;
	case 2484ULL: goto x86_l_9b4;
	case 2489ULL: goto x86_l_9b9;
	case 2493ULL: goto x86_l_9bd;
	case 2495ULL: goto x86_l_9bf;
	case 2500ULL: goto x86_l_9c4;
	case 2501ULL: goto x86_l_9c5;
	case 2502ULL: goto x86_l_9c6;
	case 2507ULL: goto x86_l_9cb;
	case 2511ULL: goto x86_l_9cf;
	case 2513ULL: goto x86_l_9d1;
	case 2523ULL: goto x86_l_9db;
	case 2527ULL: goto x86_l_9df;
	case 2529ULL: goto x86_l_9e1;
	case 2534ULL: goto x86_l_9e6;
	case 2535ULL: goto x86_l_9e7;
	case 2536ULL: goto x86_l_9e8;
	case 2541ULL: goto x86_l_9ed;
	case 2542ULL: goto x86_l_9ee;
	case 2543ULL: goto x86_l_9ef;
	case 2544ULL: goto x86_l_9f0;
	case 2547ULL: goto x86_l_9f3;
	case 2549ULL: goto x86_l_9f5;
	case 2553ULL: goto x86_l_9f9;
	case 2555ULL: goto x86_l_9fb;
	case 2560ULL: goto x86_l_a00;
	case 2564ULL: goto x86_l_a04;
	case 2566ULL: goto x86_l_a06;
	case 2571ULL: goto x86_l_a0b;
	case 2572ULL: goto x86_l_a0c;
	case 2573ULL: goto x86_l_a0d;
	case 2578ULL: goto x86_l_a12;
	case 2582ULL: goto x86_l_a16;
	case 2584ULL: goto x86_l_a18;
	case 2594ULL: goto x86_l_a22;
	case 2598ULL: goto x86_l_a26;
	case 2600ULL: goto x86_l_a28;
	case 2605ULL: goto x86_l_a2d;
	case 2606ULL: goto x86_l_a2e;
	case 2607ULL: goto x86_l_a2f;
	case 2612ULL: goto x86_l_a34;
	case 2613ULL: goto x86_l_a35;
	case 2614ULL: goto x86_l_a36;
	case 2615ULL: goto x86_l_a37;
	case 2618ULL: goto x86_l_a3a;
	case 2621ULL: goto x86_l_a3d;
	case 2624ULL: goto x86_l_a40;
	case 2628ULL: goto x86_l_a44;
	case 2630ULL: goto x86_l_a46;
	case 2633ULL: goto x86_l_a49;
	case 2636ULL: goto x86_l_a4c;
	case 2638ULL: goto x86_l_a4e;
	case 2641ULL: goto x86_l_a51;
	case 2643ULL: goto x86_l_a53;
	case 2646ULL: goto x86_l_a56;
	case 2649ULL: goto x86_l_a59;
	case 2651ULL: goto x86_l_a5b;
	case 2654ULL: goto x86_l_a5e;
	case 2656ULL: goto x86_l_a60;
	case 2659ULL: goto x86_l_a63;
	case 2661ULL: goto x86_l_a65;
	case 2663ULL: goto x86_l_a67;
	case 2666ULL: goto x86_l_a6a;
	case 2668ULL: goto x86_l_a6c;
	case 2671ULL: goto x86_l_a6f;
	case 2673ULL: goto x86_l_a71;
	case 2676ULL: goto x86_l_a74;
	case 2678ULL: goto x86_l_a76;
	case 2681ULL: goto x86_l_a79;
	case 2686ULL: goto x86_l_a7e;
	case 2688ULL: goto x86_l_a80;
	case 2691ULL: goto x86_l_a83;
	case 2693ULL: goto x86_l_a85;
	case 2696ULL: goto x86_l_a88;
	case 2698ULL: goto x86_l_a8a;
	case 2701ULL: goto x86_l_a8d;
	case 2706ULL: goto x86_l_a92;
	case 2708ULL: goto x86_l_a94;
	case 2711ULL: goto x86_l_a97;
	case 2716ULL: goto x86_l_a9c;
	case 2718ULL: goto x86_l_a9e;
	case 2721ULL: goto x86_l_aa1;
	case 2726ULL: goto x86_l_aa6;
	case 2728ULL: goto x86_l_aa8;
	case 2731ULL: goto x86_l_aab;
	case 2733ULL: goto x86_l_aad;
	case 2738ULL: goto x86_l_ab2;
	case 2741ULL: goto x86_l_ab5;
	case 2744ULL: goto x86_l_ab8;
	case 2746ULL: goto x86_l_aba;
	case 2748ULL: goto x86_l_abc;
	case 2758ULL: goto x86_l_ac6;
	case 2762ULL: goto x86_l_aca;
	case 2764ULL: goto x86_l_acc;
	case 2766ULL: goto x86_l_ace;
	case 2769ULL: goto x86_l_ad1;
	case 2772ULL: goto x86_l_ad4;
	case 2775ULL: goto x86_l_ad7;
	case 2776ULL: goto x86_l_ad8;
	case 2777ULL: goto x86_l_ad9;
	case 2778ULL: goto x86_l_ada;
	case 2781ULL: goto x86_l_add;
	case 2783ULL: goto x86_l_adf;
	case 2787ULL: goto x86_l_ae3;
	case 2789ULL: goto x86_l_ae5;
	case 2794ULL: goto x86_l_aea;
	case 2798ULL: goto x86_l_aee;
	case 2800ULL: goto x86_l_af0;
	case 2805ULL: goto x86_l_af5;
	case 2806ULL: goto x86_l_af6;
	case 2807ULL: goto x86_l_af7;
	case 2812ULL: goto x86_l_afc;
	case 2816ULL: goto x86_l_b00;
	case 2818ULL: goto x86_l_b02;
	case 2828ULL: goto x86_l_b0c;
	case 2832ULL: goto x86_l_b10;
	case 2834ULL: goto x86_l_b12;
	case 2839ULL: goto x86_l_b17;
	default: return 0xffffffffffffffffULL;
	}
x86_l_60d:
	/* 0x60d: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_610:
	/* 0x610: je     6a8 <filter_inet+0xec> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_6a8;
	}
x86_l_616:
	/* 0x616: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_619:
	/* 0x619: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_61c:
	/* 0x61c: je     634 <filter_inet+0x78> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_634;
	}
x86_l_61e:
	/* 0x61e: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_623:
	/* 0x623: cmp    edx,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_626:
	/* 0x626: je     680 <filter_inet+0xc4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_680;
	}
x86_l_628:
	/* 0x628: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_62e:
	/* 0x62e: jne    8b9 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8b9;
	}
x86_l_634:
	/* 0x634: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_637:
	/* 0x637: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_639:
	/* 0x639: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_63c:
	/* 0x63c: jle    6b5 <filter_inet+0xf9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6b5;
	}
x86_l_63e:
	/* 0x63e: cmp    ecx,0x17 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 23ULL);
x86_l_641:
	/* 0x641: jg     660 <filter_inet+0xa4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_660;
	}
x86_l_643:
	/* 0x643: lea    edx,[rcx-0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551596ULL);
x86_l_646:
	/* 0x646: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_649:
	/* 0x649: jb     706 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_706;
	}
x86_l_64f:
	/* 0x64f: lea    edx,[rcx-0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551594ULL);
x86_l_652:
	/* 0x652: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_655:
	/* 0x655: jb     700 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_700;
	}
x86_l_65b:
	/* 0x65b: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_660:
	/* 0x660: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_663:
	/* 0x663: jg     743 <filter_inet+0x187> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_743;
	}
x86_l_669:
	/* 0x669: cmp    ecx,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 24ULL);
x86_l_66c:
	/* 0x66c: je     776 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_776;
	}
x86_l_672:
	/* 0x672: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_675:
	/* 0x675: je     76c <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76c;
	}
x86_l_67b:
	/* 0x67b: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_680:
	/* 0x680: movzx  eax,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_683:
	/* 0x683: mov    WORD PTR [rsp+0x46],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_688:
	/* 0x688: movzx  eax,WORD PTR [rsi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_68c:
	/* 0x68c: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_691:
	/* 0x691: mov    rax,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_695:
	/* 0x695: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69a:
	/* 0x69a: mov    rax,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_69e:
	/* 0x69e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6a3:
	/* 0x6a3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6a8:
	/* 0x6a8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ab:
	/* 0x6ab: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6ae:
	/* 0x6ae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b0:
	/* 0x6b0: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_6b3:
	/* 0x6b3: jg     63e <filter_inet+0x82> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_63e;
	}
x86_l_6b5:
	/* 0x6b5: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_6b8:
	/* 0x6b8: jle    6d6 <filter_inet+0x11a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_6d6;
	}
x86_l_6ba:
	/* 0x6ba: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6bd:
	/* 0x6bd: jg     6f2 <filter_inet+0x136> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_6f2;
	}
x86_l_6bf:
	/* 0x6bf: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_6c2:
	/* 0x6c2: je     700 <filter_inet+0x144> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_700;
	}
x86_l_6c4:
	/* 0x6c4: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6c7:
	/* 0x6c7: jne    8b9 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8b9;
	}
x86_l_6cd:
	/* 0x6cd: movzx  eax,WORD PTR [rsi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_6d1:
	/* 0x6d1: jmp    8ae <filter_inet+0x2f2> */
	goto x86_l_8ae;
x86_l_6d6:
	/* 0x6d6: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_6d9:
	/* 0x6d9: je     776 <filter_inet+0x1ba> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_776;
	}
x86_l_6df:
	/* 0x6df: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_6e2:
	/* 0x6e2: je     76c <filter_inet+0x1b0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_76c;
	}
x86_l_6e8:
	/* 0x6e8: cmp    ecx,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 15ULL);
x86_l_6eb:
	/* 0x6eb: je     706 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_706;
	}
x86_l_6ed:
	/* 0x6ed: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_6f2:
	/* 0x6f2: cmp    ecx,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 18ULL);
x86_l_6f5:
	/* 0x6f5: je     706 <filter_inet+0x14a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_706;
	}
x86_l_6f7:
	/* 0x6f7: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_6fa:
	/* 0x6fa: jne    8b9 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8b9;
	}
x86_l_700:
	/* 0x700: movzx  edx,WORD PTR [rsi+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_704:
	/* 0x704: jmp    70a <filter_inet+0x14e> */
	goto x86_l_70a;
x86_l_706:
	/* 0x706: movzx  edx,WORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_70a:
	/* 0x70a: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_70e:
	/* 0x70e: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_710:
	/* 0x710: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_713:
	/* 0x713: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_716:
	/* 0x716: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_718:
	/* 0x718: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_71b:
	/* 0x71b: jg     78d <filter_inet+0x1d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_78d;
	}
x86_l_71d:
	/* 0x71d: lea    edx,[rcx-0xd] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551603ULL);
x86_l_720:
	/* 0x720: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_723:
	/* 0x723: jb     7b4 <filter_inet+0x1f8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_7b4;
	}
x86_l_729:
	/* 0x729: lea    edx,[rcx-0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551601ULL);
x86_l_72c:
	/* 0x72c: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_72f:
	/* 0x72f: jb     809 <filter_inet+0x24d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_809;
	}
x86_l_735:
	/* 0x735: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_738:
	/* 0x738: je     8b1 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b1;
	}
x86_l_73e:
	/* 0x73e: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_743:
	/* 0x743: cmp    ecx,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 28ULL);
x86_l_746:
	/* 0x746: je     8aa <filter_inet+0x2ee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8aa;
	}
x86_l_74c:
	/* 0x74c: cmp    ecx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 29ULL);
x86_l_74f:
	/* 0x74f: jne    8b9 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8b9;
	}
x86_l_755:
	/* 0x755: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_758:
	/* 0x758: jne    8dd <filter_inet+0x321> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8dd;
	}
x86_l_75e:
	/* 0x75e: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_761:
	/* 0x761: jne    8e7 <filter_inet+0x32b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8e7;
	}
x86_l_767:
	/* 0x767: jmp    8b1 <filter_inet+0x2f5> */
	goto x86_l_8b1;
x86_l_76c:
	/* 0x76c: mov    rbx,QWORD PTR [rsi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_770:
	/* 0x770: mov    r14,QWORD PTR [rsi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_774:
	/* 0x774: jmp    77d <filter_inet+0x1c1> */
	goto x86_l_77d;
x86_l_776:
	/* 0x776: mov    rbx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_779:
	/* 0x779: mov    r14,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_77d:
	/* 0x77d: mov    r15,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBX, X86_WIDTH_64);
x86_l_780:
	/* 0x780: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_784:
	/* 0x784: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_786:
	/* 0x786: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_788:
	/* 0x788: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_78b:
	/* 0x78b: jle    71d <filter_inet+0x161> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_71d;
	}
x86_l_78d:
	/* 0x78d: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_790:
	/* 0x790: ja     7fd <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_7fd;
	}
x86_l_792:
	/* 0x792: mov    r8d,0x500000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5242880ULL);
x86_l_798:
	/* 0x798: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_79c:
	/* 0x79c: jb     813 <filter_inet+0x257> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_813;
	}
x86_l_79e:
	/* 0x79e: mov    r8d,0xa00000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 10485760ULL);
x86_l_7a4:
	/* 0x7a4: bt     r8d,ecx */
	X86_SIM_L_EXEC_BT(X86_R8, X86_RCX, X86_WIDTH_32);
x86_l_7a8:
	/* 0x7a8: jb     823 <filter_inet+0x267> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_823;
	}
x86_l_7aa:
	/* 0x7aa: mov    edx,0x3000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 50331648ULL);
x86_l_7af:
	/* 0x7af: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7b2:
	/* 0x7b2: jae    7fd <filter_inet+0x241> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_7fd;
	}
x86_l_7b4:
	/* 0x7b4: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_7b8:
	/* 0x7b8: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_7bb:
	/* 0x7bb: je     833 <filter_inet+0x277> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_833;
	}
x86_l_7bd:
	/* 0x7bd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7c0:
	/* 0x7c0: jne    8a3 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8a3;
	}
x86_l_7c6:
	/* 0x7c6: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_7c9:
	/* 0x7c9: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7cc:
	/* 0x7cc: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d0:
	/* 0x7d0: mov    rdi,QWORD PTR [rip+0x1c10] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr4lpm_maps)));
x86_l_7d7:
	/* 0x7d7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7dc:
	/* 0x7dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7e1:
	/* 0x7e1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e3:
	/* 0x7e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e6:
	/* 0x7e6: je     8c5 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c5;
	}
x86_l_7ec:
	/* 0x7ec: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7ef:
	/* 0x7ef: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_7f7:
	/* 0x7f7: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7fb:
	/* 0x7fb: jmp    877 <filter_inet+0x2bb> */
	goto x86_l_877;
x86_l_7fd:
	/* 0x7fd: add    ecx,0xffffffee */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967278ULL);
x86_l_800:
	/* 0x800: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_803:
	/* 0x803: jae    8b9 <filter_inet+0x2fd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_8b9;
	}
x86_l_809:
	/* 0x809: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_80e:
	/* 0x80e: jmp    8b4 <filter_inet+0x2f8> */
	goto x86_l_8b4;
x86_l_813:
	/* 0x813: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_815:
	/* 0x815: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_81b:
	/* 0x81b: setb   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_B);
x86_l_81e:
	/* 0x81e: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_823:
	/* 0x823: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_825:
	/* 0x825: cmp    edx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1024ULL);
x86_l_82b:
	/* 0x82b: setae  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_AE);
x86_l_82e:
	/* 0x82e: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_833:
	/* 0x833: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_836:
	/* 0x836: mov    eax,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_839:
	/* 0x839: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83d:
	/* 0x83d: mov    rdi,QWORD PTR [rip+0x1c10] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&addr6lpm_maps)));
x86_l_844:
	/* 0x844: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_849:
	/* 0x849: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84e:
	/* 0x84e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_850:
	/* 0x850: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_853:
	/* 0x853: je     8c5 <filter_inet+0x309> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8c5;
	}
x86_l_855:
	/* 0x855: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_858:
	/* 0x858: mov    DWORD PTR [rsp+0xc],0x80 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607680ULL);
x86_l_860:
	/* 0x860: mov    DWORD PTR [rsp+0x10],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_864:
	/* 0x864: mov    DWORD PTR [rsp+0x14],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_869:
	/* 0x869: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_86e:
	/* 0x86e: shr    r14,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_872:
	/* 0x872: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_877:
	/* 0x877: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_87c:
	/* 0x87c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_881:
	/* 0x881: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_883:
	/* 0x883: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_888:
	/* 0x888: lea    edx,[rcx-0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551592ULL);
x86_l_88b:
	/* 0x88b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_88e:
	/* 0x88e: jb     8d2 <filter_inet+0x316> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_8d2;
	}
x86_l_890:
	/* 0x890: add    ecx,0xfffffff3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294967283ULL);
x86_l_893:
	/* 0x893: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_896:
	/* 0x896: ja     8a3 <filter_inet+0x2e7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_8a3;
	}
x86_l_898:
	/* 0x898: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89b:
	/* 0x89b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_89e:
	/* 0x89e: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8a1:
	/* 0x8a1: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_8a3:
	/* 0x8a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a5:
	/* 0x8a5: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8a8:
	/* 0x8a8: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_8aa:
	/* 0x8aa: movzx  eax,WORD PTR [rsi+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_8ae:
	/* 0x8ae: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b1:
	/* 0x8b1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_8b4:
	/* 0x8b4: call   1f52 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2233ULL);
	__x86_sim_call_depth++;
	return 8018ULL;
x86_l_8b9:
	/* 0x8b9: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_8bd:
	/* 0x8bd: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_8be:
	/* 0x8be: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_8c0:
	/* 0x8c0: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_8c4:
	/* 0x8c4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_8c5:
	/* 0x8c5: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8ca:
	/* 0x8ca: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_8cd:
	/* 0x8cd: cmp    eax,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 24ULL);
x86_l_8d0:
	/* 0x8d0: jmp    8d5 <filter_inet+0x319> */
	goto x86_l_8d5;
x86_l_8d2:
	/* 0x8d2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8d5:
	/* 0x8d5: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_8d8:
	/* 0x8d8: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8db:
	/* 0x8db: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_8dd:
	/* 0x8dd: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_8e0:
	/* 0x8e0: jne    8ef <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_8ef;
	}
x86_l_8e2:
	/* 0x8e2: test   r8,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_64);
x86_l_8e5:
	/* 0x8e5: je     8ef <filter_inet+0x333> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8ef;
	}
x86_l_8e7:
	/* 0x8e7: movzx  eax,BYTE PTR [r8+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_8ec:
	/* 0x8ec: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ef:
	/* 0x8ef: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_8f2:
	/* 0x8f2: je     8b1 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b1;
	}
x86_l_8f4:
	/* 0x8f4: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_8f7:
	/* 0x8f7: je     8b1 <filter_inet+0x2f5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_8b1;
	}
x86_l_8f9:
	/* 0x8f9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8fb:
	/* 0x8fb: jmp    8b9 <filter_inet+0x2fd> */
	goto x86_l_8b9;
x86_l_8fd:
	/* 0x8fd: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8fe:
	/* 0x8fe: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_902:
	/* 0x902: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_905:
	/* 0x905: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_909:
	/* 0x909: movzx  edx,BYTE PTR [rcx+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_90d:
	/* 0x90d: mov    r8d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_911:
	/* 0x911: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_913:
	/* 0x913: cmp    r8d,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 25ULL);
x86_l_917:
	/* 0x917: jg     94d <filter_sockaddr_un+0x50> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_94d;
	}
x86_l_919:
	/* 0x919: lea    ecx,[r8-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_91d:
	/* 0x91d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_920:
	/* 0x920: jae    95b <filter_sockaddr_un+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_95b;
	}
x86_l_922:
	/* 0x922: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_925:
	/* 0x925: call   118d <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2346ULL);
	__x86_sim_call_depth++;
	return 4493ULL;
x86_l_92a:
	/* 0x92a: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_92d:
	/* 0x92d: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_931:
	/* 0x931: ja     947 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_947;
	}
x86_l_933:
	/* 0x933: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_93d:
	/* 0x93d: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_941:
	/* 0x941: jae    947 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_947;
	}
x86_l_943:
	/* 0x943: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_947:
	/* 0x947: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_94b:
	/* 0x94b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_94c:
	/* 0x94c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_94d:
	/* 0x94d: cmp    r8d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 28ULL);
x86_l_951:
	/* 0x951: je     991 <filter_sockaddr_un+0x94> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_991;
	}
x86_l_953:
	/* 0x953: cmp    r8d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 26ULL);
x86_l_957:
	/* 0x957: je     961 <filter_sockaddr_un+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_961;
	}
x86_l_959:
	/* 0x959: jmp    947 <filter_sockaddr_un+0x4a> */
	goto x86_l_947;
x86_l_95b:
	/* 0x95b: cmp    r8d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 8ULL);
x86_l_95f:
	/* 0x95f: jne    947 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_947;
	}
x86_l_961:
	/* 0x961: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_964:
	/* 0x964: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_967:
	/* 0x967: mov    edi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_969:
	/* 0x969: call   10ed <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2414ULL);
	__x86_sim_call_depth++;
	return 4333ULL;
x86_l_96e:
	/* 0x96e: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_971:
	/* 0x971: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_975:
	/* 0x975: ja     947 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_947;
	}
x86_l_977:
	/* 0x977: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_981:
	/* 0x981: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_985:
	/* 0x985: jae    947 <filter_sockaddr_un+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_947;
	}
x86_l_987:
	/* 0x987: xor    rax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_XOR, 1ULL);
x86_l_98b:
	/* 0x98b: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_98f:
	/* 0x98f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_990:
	/* 0x990: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_991:
	/* 0x991: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_994:
	/* 0x994: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_998:
	/* 0x998: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_99d:
	/* 0x99d: call   1f52 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2466ULL);
	__x86_sim_call_depth++;
	return 8018ULL;
x86_l_9a2:
	/* 0x9a2: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_9a6:
	/* 0x9a6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_9a7:
	/* 0x9a7: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9a8:
	/* 0x9a8: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_9a9:
	/* 0x9a9: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9ac:
	/* 0x9ac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ae:
	/* 0x9ae: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_9b2:
	/* 0x9b2: ja     9ed <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_9ed;
	}
x86_l_9b4:
	/* 0x9b4: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_9b9:
	/* 0x9b9: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9bd:
	/* 0x9bd: jae    9c6 <filter_32ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9c6;
	}
x86_l_9bf:
	/* 0x9bf: call   1b88 <filter_32ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2500ULL);
	__x86_sim_call_depth++;
	return 7048ULL;
x86_l_9c4:
	/* 0x9c4: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9c5:
	/* 0x9c5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9c6:
	/* 0x9c6: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_9cb:
	/* 0x9cb: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9cf:
	/* 0x9cf: jb     9e8 <filter_32ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_9e8;
	}
x86_l_9d1:
	/* 0x9d1: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_9db:
	/* 0x9db: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9df:
	/* 0x9df: jae    9ed <filter_32ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_9ed;
	}
x86_l_9e1:
	/* 0x9e1: call   1d9c <filter_32ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2534ULL);
	__x86_sim_call_depth++;
	return 7580ULL;
x86_l_9e6:
	/* 0x9e6: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9e7:
	/* 0x9e7: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9e8:
	/* 0x9e8: call   1f52 <filter_32ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2541ULL);
	__x86_sim_call_depth++;
	return 8018ULL;
x86_l_9ed:
	/* 0x9ed: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_9ee:
	/* 0x9ee: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_9ef:
	/* 0x9ef: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_9f0:
	/* 0x9f0: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9f3:
	/* 0x9f3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f5:
	/* 0x9f5: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_9f9:
	/* 0x9f9: ja     a34 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_a34;
	}
x86_l_9fb:
	/* 0x9fb: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_a00:
	/* 0xa00: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a04:
	/* 0xa04: jae    a0d <filter_16ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a0d;
	}
x86_l_a06:
	/* 0xa06: call   1730 <filter_16ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2571ULL);
	__x86_sim_call_depth++;
	return 5936ULL;
x86_l_a0b:
	/* 0xa0b: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a0c:
	/* 0xa0c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a0d:
	/* 0xa0d: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_a12:
	/* 0xa12: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a16:
	/* 0xa16: jb     a2f <filter_16ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a2f;
	}
x86_l_a18:
	/* 0xa18: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_a22:
	/* 0xa22: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_a26:
	/* 0xa26: jae    a34 <filter_16ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_a34;
	}
x86_l_a28:
	/* 0xa28: call   194a <filter_16ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2605ULL);
	__x86_sim_call_depth++;
	return 6474ULL;
x86_l_a2d:
	/* 0xa2d: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a2e:
	/* 0xa2e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a2f:
	/* 0xa2f: call   1b02 <filter_16ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2612ULL);
	__x86_sim_call_depth++;
	return 6914ULL;
x86_l_a34:
	/* 0xa34: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_a35:
	/* 0xa35: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_a36:
	/* 0xa36: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_a37:
	/* 0xa37: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_a3a:
	/* 0xa3a: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a3d:
	/* 0xa3d: movsxd rcx,edx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_a40:
	/* 0xa40: mov    edx,DWORD PTR [rsi+rcx*1-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 18446744073709551612ULL);
x86_l_a44:
	/* 0xa44: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_a46:
	/* 0xa46: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a49:
	/* 0xa49: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a4c:
	/* 0xa4c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a4e:
	/* 0xa4e: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_a51:
	/* 0xa51: jg     a67 <filter_char_buf+0x31> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a67;
	}
x86_l_a53:
	/* 0xa53: lea    edi,[rcx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_a56:
	/* 0xa56: cmp    edi,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_a59:
	/* 0xa59: jb     a9e <filter_char_buf+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_a9e;
	}
x86_l_a5b:
	/* 0xa5b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a5e:
	/* 0xa5e: je     a94 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a94;
	}
x86_l_a60:
	/* 0xa60: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_a63:
	/* 0xa63: je     a76 <filter_char_buf+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a76;
	}
x86_l_a65:
	/* 0xa65: jmp    ab5 <filter_char_buf+0x7f> */
	goto x86_l_ab5;
x86_l_a67:
	/* 0xa67: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_a6a:
	/* 0xa6a: jg     a80 <filter_char_buf+0x4a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_a80;
	}
x86_l_a6c:
	/* 0xa6c: cmp    ecx,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 26ULL);
x86_l_a6f:
	/* 0xa6f: je     a94 <filter_char_buf+0x5e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_a94;
	}
x86_l_a71:
	/* 0xa71: cmp    ecx,0x1b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 27ULL);
x86_l_a74:
	/* 0xa74: jne    ab5 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ab5;
	}
x86_l_a76:
	/* 0xa76: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a79:
	/* 0xa79: call   fa5 <filter_char_buf_postfix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2686ULL);
	__x86_sim_call_depth++;
	return 4005ULL;
x86_l_a7e:
	/* 0xa7e: jmp    ab2 <filter_char_buf+0x7c> */
	goto x86_l_ab2;
x86_l_a80:
	/* 0xa80: cmp    ecx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33ULL);
x86_l_a83:
	/* 0xa83: je     aa8 <filter_char_buf+0x72> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_aa8;
	}
x86_l_a85:
	/* 0xa85: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_a88:
	/* 0xa88: jne    ab5 <filter_char_buf+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ab5;
	}
x86_l_a8a:
	/* 0xa8a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a8d:
	/* 0xa8d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a92:
	/* 0xa92: jmp    aad <filter_char_buf+0x77> */
	goto x86_l_aad;
x86_l_a94:
	/* 0xa94: mov    edi,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a97:
	/* 0xa97: call   10ed <filter_char_buf_prefix> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2716ULL);
	__x86_sim_call_depth++;
	return 4333ULL;
x86_l_a9c:
	/* 0xa9c: jmp    ab2 <filter_char_buf+0x7c> */
	goto x86_l_ab2;
x86_l_a9e:
	/* 0xa9e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: call   118d <filter_char_buf_equal> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2726ULL);
	__x86_sim_call_depth++;
	return 4493ULL;
x86_l_aa6:
	/* 0xaa6: jmp    ab2 <filter_char_buf+0x7c> */
	goto x86_l_ab2;
x86_l_aa8:
	/* 0xaa8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aab:
	/* 0xaab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aad:
	/* 0xaad: call   151a <filter_char_substring> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2738ULL);
	__x86_sim_call_depth++;
	return 5402ULL;
x86_l_ab2:
	/* 0xab2: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ab5:
	/* 0xab5: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_ab8:
	/* 0xab8: ja     ad7 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ad7;
	}
x86_l_aba:
	/* 0xaba: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_abc:
	/* 0xabc: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_ac6:
	/* 0xac6: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aca:
	/* 0xaca: jae    ad7 <filter_char_buf+0xa1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_ad7;
	}
x86_l_acc:
	/* 0xacc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ace:
	/* 0xace: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad1:
	/* 0xad1: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_ad4:
	/* 0xad4: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_ad7:
	/* 0xad7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_ad9:
	/* 0xad9: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_ada:
	/* 0xada: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_add:
	/* 0xadd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_adf:
	/* 0xadf: cmp    rcx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32ULL);
x86_l_ae3:
	/* 0xae3: ja     b1e <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 2846ULL;
	}
x86_l_ae5:
	/* 0xae5: mov    edx,0x101e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4126ULL);
x86_l_aea:
	/* 0xaea: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: jae    af7 <filter_64ty+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_af7;
	}
x86_l_af0:
	/* 0xaf0: call   b20 <filter_64ty_selector_val> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2805ULL);
	__x86_sim_call_depth++;
	return 2848ULL;
x86_l_af5:
	/* 0xaf5: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_af6:
	/* 0xaf6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_af7:
	/* 0xaf7: mov    edx,0xc00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3072ULL);
x86_l_afc:
	/* 0xafc: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b00:
	/* 0xb00: jb     b19 <filter_64ty+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 2841ULL;
	}
x86_l_b02:
	/* 0xb02: movabs rdx,0x180000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 6442450944ULL);
x86_l_b0c:
	/* 0xb0c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b10:
	/* 0xb10: jae    b1e <filter_64ty+0x45> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 2846ULL;
	}
x86_l_b12:
	/* 0xb12: call   d52 <filter_64ty_range> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2839ULL);
	__x86_sim_call_depth++;
	return 3410ULL;
x86_l_b17:
	/* 0xb17: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
	return 2840ULL;
}

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_2(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 2840ULL: goto x86_l_b18;
	case 2841ULL: goto x86_l_b19;
	case 2846ULL: goto x86_l_b1e;
	case 2847ULL: goto x86_l_b1f;
	case 2848ULL: goto x86_l_b20;
	case 2851ULL: goto x86_l_b23;
	case 2856ULL: goto x86_l_b28;
	case 2860ULL: goto x86_l_b2c;
	case 2862ULL: goto x86_l_b2e;
	case 2872ULL: goto x86_l_b38;
	case 2876ULL: goto x86_l_b3c;
	case 2878ULL: goto x86_l_b3e;
	case 2879ULL: goto x86_l_b3f;
	case 2884ULL: goto x86_l_b44;
	case 2888ULL: goto x86_l_b48;
	case 2890ULL: goto x86_l_b4a;
	case 2893ULL: goto x86_l_b4d;
	case 2897ULL: goto x86_l_b51;
	case 2903ULL: goto x86_l_b57;
	case 2905ULL: goto x86_l_b59;
	case 2908ULL: goto x86_l_b5c;
	case 2911ULL: goto x86_l_b5f;
	case 2912ULL: goto x86_l_b60;
	case 2916ULL: goto x86_l_b64;
	case 2918ULL: goto x86_l_b66;
	case 2921ULL: goto x86_l_b69;
	case 2925ULL: goto x86_l_b6d;
	case 2927ULL: goto x86_l_b6f;
	case 2930ULL: goto x86_l_b72;
	case 2933ULL: goto x86_l_b75;
	case 2939ULL: goto x86_l_b7b;
	case 2943ULL: goto x86_l_b7f;
	case 2945ULL: goto x86_l_b81;
	case 2948ULL: goto x86_l_b84;
	case 2954ULL: goto x86_l_b8a;
	case 2958ULL: goto x86_l_b8e;
	case 2960ULL: goto x86_l_b90;
	case 2963ULL: goto x86_l_b93;
	case 2969ULL: goto x86_l_b99;
	case 2973ULL: goto x86_l_b9d;
	case 2975ULL: goto x86_l_b9f;
	case 2980ULL: goto x86_l_ba4;
	case 2983ULL: goto x86_l_ba7;
	case 2985ULL: goto x86_l_ba9;
	case 2988ULL: goto x86_l_bac;
	case 2994ULL: goto x86_l_bb2;
	case 2997ULL: goto x86_l_bb5;
	case 3000ULL: goto x86_l_bb8;
	case 3006ULL: goto x86_l_bbe;
	case 3011ULL: goto x86_l_bc3;
	case 3014ULL: goto x86_l_bc6;
	case 3020ULL: goto x86_l_bcc;
	case 3023ULL: goto x86_l_bcf;
	case 3027ULL: goto x86_l_bd3;
	case 3033ULL: goto x86_l_bd9;
	case 3036ULL: goto x86_l_bdc;
	case 3039ULL: goto x86_l_bdf;
	case 3045ULL: goto x86_l_be5;
	case 3049ULL: goto x86_l_be9;
	case 3055ULL: goto x86_l_bef;
	case 3058ULL: goto x86_l_bf2;
	case 3064ULL: goto x86_l_bf8;
	case 3068ULL: goto x86_l_bfc;
	case 3074ULL: goto x86_l_c02;
	case 3077ULL: goto x86_l_c05;
	case 3083ULL: goto x86_l_c0b;
	case 3087ULL: goto x86_l_c0f;
	case 3093ULL: goto x86_l_c15;
	case 3098ULL: goto x86_l_c1a;
	case 3101ULL: goto x86_l_c1d;
	case 3104ULL: goto x86_l_c20;
	case 3110ULL: goto x86_l_c26;
	case 3115ULL: goto x86_l_c2b;
	case 3118ULL: goto x86_l_c2e;
	case 3124ULL: goto x86_l_c34;
	case 3127ULL: goto x86_l_c37;
	case 3131ULL: goto x86_l_c3b;
	case 3137ULL: goto x86_l_c41;
	case 3140ULL: goto x86_l_c44;
	case 3143ULL: goto x86_l_c47;
	case 3149ULL: goto x86_l_c4d;
	case 3153ULL: goto x86_l_c51;
	case 3159ULL: goto x86_l_c57;
	case 3162ULL: goto x86_l_c5a;
	case 3168ULL: goto x86_l_c60;
	case 3172ULL: goto x86_l_c64;
	case 3178ULL: goto x86_l_c6a;
	case 3181ULL: goto x86_l_c6d;
	case 3187ULL: goto x86_l_c73;
	case 3191ULL: goto x86_l_c77;
	case 3197ULL: goto x86_l_c7d;
	case 3202ULL: goto x86_l_c82;
	case 3205ULL: goto x86_l_c85;
	case 3208ULL: goto x86_l_c88;
	case 3210ULL: goto x86_l_c8a;
	case 3214ULL: goto x86_l_c8e;
	case 3220ULL: goto x86_l_c94;
	case 3223ULL: goto x86_l_c97;
	case 3225ULL: goto x86_l_c99;
	case 3229ULL: goto x86_l_c9d;
	case 3235ULL: goto x86_l_ca3;
	case 3238ULL: goto x86_l_ca6;
	case 3240ULL: goto x86_l_ca8;
	case 3244ULL: goto x86_l_cac;
	case 3250ULL: goto x86_l_cb2;
	case 3253ULL: goto x86_l_cb5;
	case 3259ULL: goto x86_l_cbb;
	case 3261ULL: goto x86_l_cbd;
	case 3271ULL: goto x86_l_cc7;
	case 3275ULL: goto x86_l_ccb;
	case 3281ULL: goto x86_l_cd1;
	case 3283ULL: goto x86_l_cd3;
	case 3286ULL: goto x86_l_cd6;
	case 3290ULL: goto x86_l_cda;
	case 3296ULL: goto x86_l_ce0;
	case 3299ULL: goto x86_l_ce3;
	case 3302ULL: goto x86_l_ce6;
	case 3304ULL: goto x86_l_ce8;
	case 3308ULL: goto x86_l_cec;
	case 3314ULL: goto x86_l_cf2;
	case 3317ULL: goto x86_l_cf5;
	case 3319ULL: goto x86_l_cf7;
	case 3323ULL: goto x86_l_cfb;
	case 3329ULL: goto x86_l_d01;
	case 3332ULL: goto x86_l_d04;
	case 3334ULL: goto x86_l_d06;
	case 3338ULL: goto x86_l_d0a;
	case 3344ULL: goto x86_l_d10;
	case 3346ULL: goto x86_l_d12;
	case 3349ULL: goto x86_l_d15;
	case 3353ULL: goto x86_l_d19;
	case 3359ULL: goto x86_l_d1f;
	case 3362ULL: goto x86_l_d22;
	case 3365ULL: goto x86_l_d25;
	case 3367ULL: goto x86_l_d27;
	case 3371ULL: goto x86_l_d2b;
	case 3377ULL: goto x86_l_d31;
	case 3380ULL: goto x86_l_d34;
	case 3382ULL: goto x86_l_d36;
	case 3386ULL: goto x86_l_d3a;
	case 3392ULL: goto x86_l_d40;
	case 3395ULL: goto x86_l_d43;
	case 3397ULL: goto x86_l_d45;
	case 3401ULL: goto x86_l_d49;
	case 3407ULL: goto x86_l_d4f;
	case 3409ULL: goto x86_l_d51;
	case 3410ULL: goto x86_l_d52;
	case 3413ULL: goto x86_l_d55;
	case 3416ULL: goto x86_l_d58;
	case 3419ULL: goto x86_l_d5b;
	case 3425ULL: goto x86_l_d61;
	case 3430ULL: goto x86_l_d66;
	case 3433ULL: goto x86_l_d69;
	case 3439ULL: goto x86_l_d6f;
	case 3442ULL: goto x86_l_d72;
	case 3445ULL: goto x86_l_d75;
	case 3447ULL: goto x86_l_d77;
	case 3452ULL: goto x86_l_d7c;
	case 3456ULL: goto x86_l_d80;
	case 3458ULL: goto x86_l_d82;
	case 3462ULL: goto x86_l_d86;
	case 3468ULL: goto x86_l_d8c;
	case 3471ULL: goto x86_l_d8f;
	case 3474ULL: goto x86_l_d92;
	case 3480ULL: goto x86_l_d98;
	case 3484ULL: goto x86_l_d9c;
	case 3486ULL: goto x86_l_d9e;
	case 3490ULL: goto x86_l_da2;
	case 3496ULL: goto x86_l_da8;
	case 3499ULL: goto x86_l_dab;
	case 3505ULL: goto x86_l_db1;
	case 3509ULL: goto x86_l_db5;
	case 3511ULL: goto x86_l_db7;
	case 3515ULL: goto x86_l_dbb;
	case 3521ULL: goto x86_l_dc1;
	case 3524ULL: goto x86_l_dc4;
	case 3530ULL: goto x86_l_dca;
	case 3532ULL: goto x86_l_dcc;
	case 3536ULL: goto x86_l_dd0;
	case 3542ULL: goto x86_l_dd6;
	case 3546ULL: goto x86_l_dda;
	case 3552ULL: goto x86_l_de0;
	case 3557ULL: goto x86_l_de5;
	case 3560ULL: goto x86_l_de8;
	case 3564ULL: goto x86_l_dec;
	case 3568ULL: goto x86_l_df0;
	case 3572ULL: goto x86_l_df4;
	case 3575ULL: goto x86_l_df7;
	case 3578ULL: goto x86_l_dfa;
	case 3581ULL: goto x86_l_dfd;
	case 3587ULL: goto x86_l_e03;
	case 3591ULL: goto x86_l_e07;
	case 3595ULL: goto x86_l_e0b;
	case 3599ULL: goto x86_l_e0f;
	case 3603ULL: goto x86_l_e13;
	case 3606ULL: goto x86_l_e16;
	case 3609ULL: goto x86_l_e19;
	case 3612ULL: goto x86_l_e1c;
	case 3618ULL: goto x86_l_e22;
	case 3622ULL: goto x86_l_e26;
	case 3626ULL: goto x86_l_e2a;
	case 3630ULL: goto x86_l_e2e;
	case 3634ULL: goto x86_l_e32;
	case 3637ULL: goto x86_l_e35;
	case 3640ULL: goto x86_l_e38;
	case 3643ULL: goto x86_l_e3b;
	case 3649ULL: goto x86_l_e41;
	case 3653ULL: goto x86_l_e45;
	case 3656ULL: goto x86_l_e48;
	case 3660ULL: goto x86_l_e4c;
	case 3664ULL: goto x86_l_e50;
	case 3669ULL: goto x86_l_e55;
	case 3672ULL: goto x86_l_e58;
	case 3675ULL: goto x86_l_e5b;
	case 3677ULL: goto x86_l_e5d;
	case 3682ULL: goto x86_l_e62;
	case 3686ULL: goto x86_l_e66;
	case 3688ULL: goto x86_l_e68;
	case 3692ULL: goto x86_l_e6c;
	case 3694ULL: goto x86_l_e6e;
	case 3695ULL: goto x86_l_e6f;
	case 3698ULL: goto x86_l_e72;
	case 3702ULL: goto x86_l_e76;
	case 3706ULL: goto x86_l_e7a;
	case 3710ULL: goto x86_l_e7e;
	case 3713ULL: goto x86_l_e81;
	case 3716ULL: goto x86_l_e84;
	case 3719ULL: goto x86_l_e87;
	case 3725ULL: goto x86_l_e8d;
	case 3729ULL: goto x86_l_e91;
	case 3733ULL: goto x86_l_e95;
	case 3737ULL: goto x86_l_e99;
	case 3741ULL: goto x86_l_e9d;
	case 3744ULL: goto x86_l_ea0;
	case 3747ULL: goto x86_l_ea3;
	case 3750ULL: goto x86_l_ea6;
	case 3752ULL: goto x86_l_ea8;
	case 3756ULL: goto x86_l_eac;
	case 3760ULL: goto x86_l_eb0;
	case 3764ULL: goto x86_l_eb4;
	case 3768ULL: goto x86_l_eb8;
	case 3771ULL: goto x86_l_ebb;
	case 3774ULL: goto x86_l_ebe;
	case 3777ULL: goto x86_l_ec1;
	case 3779ULL: goto x86_l_ec3;
	case 3783ULL: goto x86_l_ec7;
	case 3786ULL: goto x86_l_eca;
	case 3790ULL: goto x86_l_ece;
	case 3794ULL: goto x86_l_ed2;
	case 3797ULL: goto x86_l_ed5;
	case 3800ULL: goto x86_l_ed8;
	case 3802ULL: goto x86_l_eda;
	case 3805ULL: goto x86_l_edd;
	case 3808ULL: goto x86_l_ee0;
	case 3810ULL: goto x86_l_ee2;
	case 3814ULL: goto x86_l_ee6;
	case 3816ULL: goto x86_l_ee8;
	case 3820ULL: goto x86_l_eec;
	case 3822ULL: goto x86_l_eee;
	case 3825ULL: goto x86_l_ef1;
	case 3827ULL: goto x86_l_ef3;
	case 3831ULL: goto x86_l_ef7;
	case 3833ULL: goto x86_l_ef9;
	case 3837ULL: goto x86_l_efd;
	case 3843ULL: goto x86_l_f03;
	case 3846ULL: goto x86_l_f06;
	case 3848ULL: goto x86_l_f08;
	case 3850ULL: goto x86_l_f0a;
	case 3854ULL: goto x86_l_f0e;
	case 3856ULL: goto x86_l_f10;
	case 3860ULL: goto x86_l_f14;
	case 3866ULL: goto x86_l_f1a;
	case 3868ULL: goto x86_l_f1c;
	case 3870ULL: goto x86_l_f1e;
	case 3873ULL: goto x86_l_f21;
	case 3876ULL: goto x86_l_f24;
	case 3879ULL: goto x86_l_f27;
	case 3881ULL: goto x86_l_f29;
	case 3884ULL: goto x86_l_f2c;
	case 3885ULL: goto x86_l_f2d;
	case 3887ULL: goto x86_l_f2f;
	case 3888ULL: goto x86_l_f30;
	case 3892ULL: goto x86_l_f34;
	case 3895ULL: goto x86_l_f37;
	case 3898ULL: goto x86_l_f3a;
	case 3902ULL: goto x86_l_f3e;
	case 3906ULL: goto x86_l_f42;
	case 3913ULL: goto x86_l_f49;
	case 3918ULL: goto x86_l_f4e;
	case 3923ULL: goto x86_l_f53;
	case 3925ULL: goto x86_l_f55;
	case 3928ULL: goto x86_l_f58;
	case 3930ULL: goto x86_l_f5a;
	case 3933ULL: goto x86_l_f5d;
	case 3936ULL: goto x86_l_f60;
	case 3941ULL: goto x86_l_f65;
	case 3946ULL: goto x86_l_f6a;
	case 3951ULL: goto x86_l_f6f;
	case 3953ULL: goto x86_l_f71;
	case 3956ULL: goto x86_l_f74;
	case 3959ULL: goto x86_l_f77;
	case 3961ULL: goto x86_l_f79;
	case 3964ULL: goto x86_l_f7c;
	case 3966ULL: goto x86_l_f7e;
	case 3969ULL: goto x86_l_f81;
	case 3972ULL: goto x86_l_f84;
	case 3974ULL: goto x86_l_f86;
	case 3976ULL: goto x86_l_f88;
	case 3980ULL: goto x86_l_f8c;
	case 3981ULL: goto x86_l_f8d;
	case 3983ULL: goto x86_l_f8f;
	case 3984ULL: goto x86_l_f90;
	case 3987ULL: goto x86_l_f93;
	case 3990ULL: goto x86_l_f96;
	case 3992ULL: goto x86_l_f98;
	case 3994ULL: goto x86_l_f9a;
	case 3997ULL: goto x86_l_f9d;
	case 4001ULL: goto x86_l_fa1;
	case 4002ULL: goto x86_l_fa2;
	case 4004ULL: goto x86_l_fa4;
	case 4005ULL: goto x86_l_fa5;
	case 4007ULL: goto x86_l_fa7;
	case 4009ULL: goto x86_l_fa9;
	case 4010ULL: goto x86_l_faa;
	case 4014ULL: goto x86_l_fae;
	case 4016ULL: goto x86_l_fb0;
	case 4019ULL: goto x86_l_fb3;
	case 4023ULL: goto x86_l_fb7;
	case 4031ULL: goto x86_l_fbf;
	case 4038ULL: goto x86_l_fc6;
	case 4043ULL: goto x86_l_fcb;
	case 4048ULL: goto x86_l_fd0;
	case 4050ULL: goto x86_l_fd2;
	case 4053ULL: goto x86_l_fd5;
	case 4055ULL: goto x86_l_fd7;
	case 4057ULL: goto x86_l_fd9;
	case 4063ULL: goto x86_l_fdf;
	case 4066ULL: goto x86_l_fe2;
	case 4072ULL: goto x86_l_fe8;
	case 4079ULL: goto x86_l_fef;
	case 4084ULL: goto x86_l_ff4;
	case 4089ULL: goto x86_l_ff9;
	case 4091ULL: goto x86_l_ffb;
	case 4094ULL: goto x86_l_ffe;
	case 4100ULL: goto x86_l_1004;
	case 4103ULL: goto x86_l_1007;
	case 4106ULL: goto x86_l_100a;
	case 4111ULL: goto x86_l_100f;
	case 4114ULL: goto x86_l_1012;
	case 4117ULL: goto x86_l_1015;
	case 4119ULL: goto x86_l_1017;
	case 4121ULL: goto x86_l_1019;
	case 4124ULL: goto x86_l_101c;
	case 4127ULL: goto x86_l_101f;
	case 4131ULL: goto x86_l_1023;
	case 4134ULL: goto x86_l_1026;
	case 4138ULL: goto x86_l_102a;
	case 4140ULL: goto x86_l_102c;
	case 4147ULL: goto x86_l_1033;
	case 4151ULL: goto x86_l_1037;
	case 4155ULL: goto x86_l_103b;
	case 4162ULL: goto x86_l_1042;
	case 4167ULL: goto x86_l_1047;
	case 4171ULL: goto x86_l_104b;
	case 4175ULL: goto x86_l_104f;
	case 4179ULL: goto x86_l_1053;
	case 4181ULL: goto x86_l_1055;
	case 4185ULL: goto x86_l_1059;
	case 4189ULL: goto x86_l_105d;
	case 4196ULL: goto x86_l_1064;
	case 4201ULL: goto x86_l_1069;
	case 4205ULL: goto x86_l_106d;
	case 4209ULL: goto x86_l_1071;
	case 4211ULL: goto x86_l_1073;
	case 4215ULL: goto x86_l_1077;
	case 4219ULL: goto x86_l_107b;
	case 4226ULL: goto x86_l_1082;
	case 4231ULL: goto x86_l_1087;
	case 4235ULL: goto x86_l_108b;
	case 4238ULL: goto x86_l_108e;
	case 4241ULL: goto x86_l_1091;
	case 4243ULL: goto x86_l_1093;
	case 4247ULL: goto x86_l_1097;
	case 4249ULL: goto x86_l_1099;
	default: return 0xffffffffffffffffULL;
	}
x86_l_b18:
	/* 0xb18: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b19:
	/* 0xb19: call   f2d <filter_64ty_map> */
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr - 8;
	X86_SIM_L_STACK_WRITE((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64, 2846ULL);
	__x86_sim_call_depth++;
	goto x86_l_f2d;
x86_l_b1e:
	/* 0xb1e: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_b1f:
	/* 0xb1f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b20:
	/* 0xb20: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b23:
	/* 0xb23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b28:
	/* 0xb28: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_b2c:
	/* 0xb2c: ja     ba4 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_ba4;
	}
x86_l_b2e:
	/* 0xb2e: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_b38:
	/* 0xb38: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b3c:
	/* 0xb3c: jae    b3f <filter_64ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b3f;
	}
x86_l_b3e:
	/* 0xb3e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b3f:
	/* 0xb3f: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_b44:
	/* 0xb44: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_b48:
	/* 0xb48: jae    b60 <filter_64ty_selector_val+0x40> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_b60;
	}
x86_l_b4a:
	/* 0xb4a: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4d:
	/* 0xb4d: cmp    rdx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_b51:
	/* 0xb51: jne    c82 <filter_64ty_selector_val+0x162> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_c82;
	}
x86_l_b57:
	/* 0xb57: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b59:
	/* 0xb59: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b5c:
	/* 0xb5c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b5f:
	/* 0xb5f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_b60:
	/* 0xb60: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_b64:
	/* 0xb64: jne    ba4 <filter_64ty_selector_val+0x84> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_ba4;
	}
x86_l_b66:
	/* 0xb66: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b69:
	/* 0xb69: test   QWORD PTR [rdi+0x10],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6d:
	/* 0xb6d: jne    b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b3e;
	}
x86_l_b6f:
	/* 0xb6f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b72:
	/* 0xb72: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_b75:
	/* 0xb75: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_b7b:
	/* 0xb7b: test   QWORD PTR [rdi+0x18],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b7f:
	/* 0xb7f: jne    b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b3e;
	}
x86_l_b81:
	/* 0xb81: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_b84:
	/* 0xb84: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_b8a:
	/* 0xb8a: test   QWORD PTR [rdi+0x20],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b8e:
	/* 0xb8e: jne    b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b3e;
	}
x86_l_b90:
	/* 0xb90: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_b93:
	/* 0xb93: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_b99:
	/* 0xb99: test   QWORD PTR [rdi+0x28],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b9d:
	/* 0xb9d: jne    b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_b3e;
	}
x86_l_b9f:
	/* 0xb9f: jmp    d4f <filter_64ty_selector_val+0x22f> */
	goto x86_l_d4f;
x86_l_ba4:
	/* 0xba4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ba7:
	/* 0xba7: je     c1a <filter_64ty_selector_val+0xfa> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_c1a;
	}
x86_l_ba9:
	/* 0xba9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bac:
	/* 0xbac: jne    d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_d4f;
	}
x86_l_bb2:
	/* 0xbb2: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bb5:
	/* 0xbb5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_bb8:
	/* 0xbb8: ja     d12 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d12;
	}
x86_l_bbe:
	/* 0xbbe: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_bc3:
	/* 0xbc3: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_bc6:
	/* 0xbc6: jae    d12 <filter_64ty_selector_val+0x1f2> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_d12;
	}
x86_l_bcc:
	/* 0xbcc: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bcf:
	/* 0xbcf: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_bd3:
	/* 0xbd3: jl     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b3e;
	}
x86_l_bd9:
	/* 0xbd9: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bdc:
	/* 0xbdc: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_bdf:
	/* 0xbdf: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_be5:
	/* 0xbe5: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_be9:
	/* 0xbe9: jl     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b3e;
	}
x86_l_bef:
	/* 0xbef: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_bf2:
	/* 0xbf2: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_bf8:
	/* 0xbf8: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_bfc:
	/* 0xbfc: jl     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b3e;
	}
x86_l_c02:
	/* 0xc02: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c05:
	/* 0xc05: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_c0b:
	/* 0xc0b: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c0f:
	/* 0xc0f: jl     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_b3e;
	}
x86_l_c15:
	/* 0xc15: jmp    d4f <filter_64ty_selector_val+0x22f> */
	goto x86_l_d4f;
x86_l_c1a:
	/* 0xc1a: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c1d:
	/* 0xc1d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c20:
	/* 0xc20: ja     cd3 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_cd3;
	}
x86_l_c26:
	/* 0xc26: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_c2b:
	/* 0xc2b: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_c2e:
	/* 0xc2e: jae    cd3 <filter_64ty_selector_val+0x1b3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_cd3;
	}
x86_l_c34:
	/* 0xc34: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c37:
	/* 0xc37: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_c3b:
	/* 0xc3b: jg     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b3e;
	}
x86_l_c41:
	/* 0xc41: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c44:
	/* 0xc44: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_c47:
	/* 0xc47: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_c4d:
	/* 0xc4d: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c51:
	/* 0xc51: jg     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b3e;
	}
x86_l_c57:
	/* 0xc57: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_c5a:
	/* 0xc5a: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_c60:
	/* 0xc60: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c64:
	/* 0xc64: jg     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b3e;
	}
x86_l_c6a:
	/* 0xc6a: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_c6d:
	/* 0xc6d: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_c73:
	/* 0xc73: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_c77:
	/* 0xc77: jg     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_b3e;
	}
x86_l_c7d:
	/* 0xc7d: jmp    d4f <filter_64ty_selector_val+0x22f> */
	goto x86_l_d4f;
x86_l_c82:
	/* 0xc82: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c85:
	/* 0xc85: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_c88:
	/* 0xc88: jb     cb2 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cb2;
	}
x86_l_c8a:
	/* 0xc8a: cmp    rdx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_c8e:
	/* 0xc8e: je     b57 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b57;
	}
x86_l_c94:
	/* 0xc94: cmp    esi,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 25ULL);
x86_l_c97:
	/* 0xc97: jb     cb2 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cb2;
	}
x86_l_c99:
	/* 0xc99: cmp    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_c9d:
	/* 0xc9d: je     b57 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b57;
	}
x86_l_ca3:
	/* 0xca3: cmp    esi,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 33ULL);
x86_l_ca6:
	/* 0xca6: jb     cb2 <filter_64ty_selector_val+0x192> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_cb2;
	}
x86_l_ca8:
	/* 0xca8: cmp    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_cac:
	/* 0xcac: je     b57 <filter_64ty_selector_val+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_b57;
	}
x86_l_cb2:
	/* 0xcb2: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_cb5:
	/* 0xcb5: ja     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_d4f;
	}
x86_l_cbb:
	/* 0xcbb: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_cbd:
	/* 0xcbd: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_cc7:
	/* 0xcc7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: jb     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b3e;
	}
x86_l_cd1:
	/* 0xcd1: jmp    d4f <filter_64ty_selector_val+0x22f> */
	goto x86_l_d4f;
x86_l_cd3:
	/* 0xcd3: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd6:
	/* 0xcd6: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_cda:
	/* 0xcda: ja     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b3e;
	}
x86_l_ce0:
	/* 0xce0: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce3:
	/* 0xce3: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_ce6:
	/* 0xce6: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_ce8:
	/* 0xce8: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_cec:
	/* 0xcec: ja     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b3e;
	}
x86_l_cf2:
	/* 0xcf2: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_cf5:
	/* 0xcf5: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_cf7:
	/* 0xcf7: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_cfb:
	/* 0xcfb: ja     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b3e;
	}
x86_l_d01:
	/* 0xd01: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_d04:
	/* 0xd04: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_d06:
	/* 0xd06: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d0a:
	/* 0xd0a: ja     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_b3e;
	}
x86_l_d10:
	/* 0xd10: jmp    d4f <filter_64ty_selector_val+0x22f> */
	goto x86_l_d4f;
x86_l_d12:
	/* 0xd12: mov    rcx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d15:
	/* 0xd15: cmp    rcx,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_d19:
	/* 0xd19: jb     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b3e;
	}
x86_l_d1f:
	/* 0xd1f: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d22:
	/* 0xd22: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_d25:
	/* 0xd25: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_d27:
	/* 0xd27: cmp    rcx,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d2b:
	/* 0xd2b: jb     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b3e;
	}
x86_l_d31:
	/* 0xd31: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d34:
	/* 0xd34: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_d36:
	/* 0xd36: cmp    rcx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_d3a:
	/* 0xd3a: jb     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b3e;
	}
x86_l_d40:
	/* 0xd40: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_d43:
	/* 0xd43: jb     d4f <filter_64ty_selector_val+0x22f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_d4f;
	}
x86_l_d45:
	/* 0xd45: cmp    rcx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_d49:
	/* 0xd49: jb     b3e <filter_64ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_b3e;
	}
x86_l_d4f:
	/* 0xd4f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d51:
	/* 0xd51: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_d52:
	/* 0xd52: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d55:
	/* 0xd55: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d58:
	/* 0xd58: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d5b:
	/* 0xd5b: ja     e55 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_e55;
	}
x86_l_d61:
	/* 0xd61: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_d66:
	/* 0xd66: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_d69:
	/* 0xd69: jae    e55 <filter_64ty_range+0x103> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_e55;
	}
x86_l_d6f:
	/* 0xd6f: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d72:
	/* 0xd72: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_d75:
	/* 0xd75: jne    de5 <filter_64ty_range+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_de5;
	}
x86_l_d77:
	/* 0xd77: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d7c:
	/* 0xd7c: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d80:
	/* 0xd80: jg     d8c <filter_64ty_range+0x3a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_d8c;
	}
x86_l_d82:
	/* 0xd82: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_d86:
	/* 0xd86: jle    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e6e;
	}
x86_l_d8c:
	/* 0xd8c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d8f:
	/* 0xd8f: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_d92:
	/* 0xd92: jb     f1c <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1c;
	}
x86_l_d98:
	/* 0xd98: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9c:
	/* 0xd9c: jg     da8 <filter_64ty_range+0x56> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_da8;
	}
x86_l_d9e:
	/* 0xd9e: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_da2:
	/* 0xda2: jle    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e6e;
	}
x86_l_da8:
	/* 0xda8: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_dab:
	/* 0xdab: jb     f1c <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1c;
	}
x86_l_db1:
	/* 0xdb1: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_db5:
	/* 0xdb5: jg     dc1 <filter_64ty_range+0x6f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_dc1;
	}
x86_l_db7:
	/* 0xdb7: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_dbb:
	/* 0xdbb: jle    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e6e;
	}
x86_l_dc1:
	/* 0xdc1: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_dc4:
	/* 0xdc4: jb     f1c <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1c;
	}
x86_l_dca:
	/* 0xdca: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dcc:
	/* 0xdcc: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dd0:
	/* 0xdd0: jg     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_f1e;
	}
x86_l_dd6:
	/* 0xdd6: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_dda:
	/* 0xdda: jle    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_e6e;
	}
x86_l_de0:
	/* 0xde0: jmp    f1e <filter_64ty_range+0x1cc> */
	goto x86_l_f1e;
x86_l_de5:
	/* 0xde5: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de8:
	/* 0xde8: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dec:
	/* 0xdec: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_df0:
	/* 0xdf0: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_df4:
	/* 0xdf4: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_df7:
	/* 0xdf7: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_dfa:
	/* 0xdfa: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_dfd:
	/* 0xdfd: jb     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1e;
	}
x86_l_e03:
	/* 0xe03: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e07:
	/* 0xe07: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_e0b:
	/* 0xe0b: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e0f:
	/* 0xe0f: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e13:
	/* 0xe13: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e16:
	/* 0xe16: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e19:
	/* 0xe19: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_e1c:
	/* 0xe1c: jb     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1e;
	}
x86_l_e22:
	/* 0xe22: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e26:
	/* 0xe26: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_e2a:
	/* 0xe2a: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_e2e:
	/* 0xe2e: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_e32:
	/* 0xe32: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e35:
	/* 0xe35: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_e38:
	/* 0xe38: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_e3b:
	/* 0xe3b: jb     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1e;
	}
x86_l_e41:
	/* 0xe41: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e45:
	/* 0xe45: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_e48:
	/* 0xe48: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_e4c:
	/* 0xe4c: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_e50:
	/* 0xe50: jmp    ed2 <filter_64ty_range+0x180> */
	goto x86_l_ed2;
x86_l_e55:
	/* 0xe55: mov    rsi,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e58:
	/* 0xe58: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_e5b:
	/* 0xe5b: jne    e6f <filter_64ty_range+0x11d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_e6f;
	}
x86_l_e5d:
	/* 0xe5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e62:
	/* 0xe62: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e66:
	/* 0xe66: ja     eda <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_eda;
	}
x86_l_e68:
	/* 0xe68: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e6c:
	/* 0xe6c: ja     eda <filter_64ty_range+0x188> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_eda;
	}
x86_l_e6e:
	/* 0xe6e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_e6f:
	/* 0xe6f: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e72:
	/* 0xe72: cmp    QWORD PTR [rdi+0x10],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e76:
	/* 0xe76: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e7a:
	/* 0xe7a: cmp    rsi,QWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 24ULL);
x86_l_e7e:
	/* 0xe7e: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_e81:
	/* 0xe81: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_e84:
	/* 0xe84: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e87:
	/* 0xe87: jb     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1e;
	}
x86_l_e8d:
	/* 0xe8d: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e91:
	/* 0xe91: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_e95:
	/* 0xe95: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_e99:
	/* 0xe99: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_e9d:
	/* 0xe9d: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_ea0:
	/* 0xea0: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_ea3:
	/* 0xea3: cmp    eax,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 41ULL);
x86_l_ea6:
	/* 0xea6: jb     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1e;
	}
x86_l_ea8:
	/* 0xea8: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eac:
	/* 0xeac: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_eb0:
	/* 0xeb0: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_eb4:
	/* 0xeb4: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_eb8:
	/* 0xeb8: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_ebb:
	/* 0xebb: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_ebe:
	/* 0xebe: cmp    eax,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 57ULL);
x86_l_ec1:
	/* 0xec1: jb     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1e;
	}
x86_l_ec3:
	/* 0xec3: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ec7:
	/* 0xec7: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_eca:
	/* 0xeca: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_ece:
	/* 0xece: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_ed2:
	/* 0xed2: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_ed5:
	/* 0xed5: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_ed8:
	/* 0xed8: jmp    f1e <filter_64ty_range+0x1cc> */
	goto x86_l_f1e;
x86_l_eda:
	/* 0xeda: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_edd:
	/* 0xedd: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_ee0:
	/* 0xee0: jb     f1c <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1c;
	}
x86_l_ee2:
	/* 0xee2: cmp    QWORD PTR [rdi+0x20],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee6:
	/* 0xee6: ja     eee <filter_64ty_range+0x19c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_eee;
	}
x86_l_ee8:
	/* 0xee8: cmp    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_eec:
	/* 0xeec: jbe    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e6e;
	}
x86_l_eee:
	/* 0xeee: cmp    edx,0x29 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 41ULL);
x86_l_ef1:
	/* 0xef1: jb     f1c <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1c;
	}
x86_l_ef3:
	/* 0xef3: cmp    QWORD PTR [rdi+0x30],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ef7:
	/* 0xef7: ja     f03 <filter_64ty_range+0x1b1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f03;
	}
x86_l_ef9:
	/* 0xef9: cmp    rsi,QWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 56ULL);
x86_l_efd:
	/* 0xefd: jbe    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e6e;
	}
x86_l_f03:
	/* 0xf03: cmp    edx,0x39 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 57ULL);
x86_l_f06:
	/* 0xf06: jb     f1c <filter_64ty_range+0x1ca> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_f1c;
	}
x86_l_f08:
	/* 0xf08: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0a:
	/* 0xf0a: cmp    QWORD PTR [rdi+0x40],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f0e:
	/* 0xf0e: ja     f1e <filter_64ty_range+0x1cc> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_f1e;
	}
x86_l_f10:
	/* 0xf10: cmp    rsi,QWORD PTR [rdi+0x48] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 72ULL);
x86_l_f14:
	/* 0xf14: jbe    e6e <filter_64ty_range+0x11c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_e6e;
	}
x86_l_f1a:
	/* 0xf1a: jmp    f1e <filter_64ty_range+0x1cc> */
	goto x86_l_f1e;
x86_l_f1c:
	/* 0xf1c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f1e:
	/* 0xf1e: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_f21:
	/* 0xf21: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f24:
	/* 0xf24: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_f27:
	/* 0xf27: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_f29:
	/* 0xf29: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f2c:
	/* 0xf2c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f2d:
	/* 0xf2d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_f2f:
	/* 0xf2f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_f30:
	/* 0xf30: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_f34:
	/* 0xf34: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f37:
	/* 0xf37: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_f3a:
	/* 0xf3a: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_f3e:
	/* 0xf3e: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f42:
	/* 0xf42: mov    rdi,QWORD PTR [rip+0xae0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_f49:
	/* 0xf49: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f4e:
	/* 0xf4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f53:
	/* 0xf53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f55:
	/* 0xf55: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f58:
	/* 0xf58: je     f86 <filter_64ty_map+0x59> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f86;
	}
x86_l_f5a:
	/* 0xf5a: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_f5d:
	/* 0xf5d: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f60:
	/* 0xf60: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f65:
	/* 0xf65: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f6a:
	/* 0xf6a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f6f:
	/* 0xf6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f71:
	/* 0xf71: mov    ecx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f74:
	/* 0xf74: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f77:
	/* 0xf77: je     f90 <filter_64ty_map+0x63> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_f90;
	}
x86_l_f79:
	/* 0xf79: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f7c:
	/* 0xf7c: jne    f98 <filter_64ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_f98;
	}
x86_l_f7e:
	/* 0xf7e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f81:
	/* 0xf81: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_f84:
	/* 0xf84: jmp    f9a <filter_64ty_map+0x6d> */
	goto x86_l_f9a;
x86_l_f86:
	/* 0xf86: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f88:
	/* 0xf88: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_f8c:
	/* 0xf8c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f8d:
	/* 0xf8d: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f8f:
	/* 0xf8f: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_f90:
	/* 0xf90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f93:
	/* 0xf93: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f96:
	/* 0xf96: jmp    f9a <filter_64ty_map+0x6d> */
	goto x86_l_f9a;
x86_l_f98:
	/* 0xf98: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9a:
	/* 0xf9a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f9d:
	/* 0xf9d: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_fa1:
	/* 0xfa1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_fa2:
	/* 0xfa2: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_fa4:
	/* 0xfa4: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_fa5:
	/* 0xfa5: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_fa7:
	/* 0xfa7: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_fa9:
	/* 0xfa9: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_faa:
	/* 0xfaa: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_fae:
	/* 0xfae: mov    ebx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_32);
x86_l_fb0:
	/* 0xfb0: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_fb3:
	/* 0xfb3: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fb7:
	/* 0xfb7: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_fbf:
	/* 0xfbf: mov    rdi,QWORD PTR [rip+0x2440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps)));
x86_l_fc6:
	/* 0xfc6: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fcb:
	/* 0xfcb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fd0:
	/* 0xfd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fd2:
	/* 0xfd2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fd5:
	/* 0xfd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd7:
	/* 0xfd7: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_fd9:
	/* 0xfd9: je     10e3 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4323ULL;
	}
x86_l_fdf:
	/* 0xfdf: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_fe2:
	/* 0xfe2: je     10e3 <filter_char_buf_postfix+0x13e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4323ULL;
	}
x86_l_fe8:
	/* 0xfe8: mov    rdi,QWORD PTR [rip+0x2440] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_postfix_maps_heap)));
x86_l_fef:
	/* 0xfef: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff4:
	/* 0xff4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff9:
	/* 0xff9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffb:
	/* 0xffb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ffe:
	/* 0xffe: je     10e1 <filter_char_buf_postfix+0x13c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4321ULL;
	}
x86_l_1004:
	/* 0x1004: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1007:
	/* 0x1007: cmp    ebx,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 127ULL);
x86_l_100a:
	/* 0x100a: mov    eax,0x7f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 127ULL);
x86_l_100f:
	/* 0x100f: cmovb  eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_B);
x86_l_1012:
	/* 0x1012: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_1015:
	/* 0x1015: mov    DWORD PTR [rsi],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1017:
	/* 0x1017: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_1019:
	/* 0x1019: lea    ecx,[rbx-0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551612ULL);
x86_l_101c:
	/* 0x101c: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_101f:
	/* 0x101f: add    rdx,0x7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 7ULL);
x86_l_1023:
	/* 0x1023: lea    edi,[rbx-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_1026:
	/* 0x1026: lea    r8d,[rbx-0x2] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_102a:
	/* 0x102a: dec    ebx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_102c:
	/* 0x102c: mov    r9,0xfffffffffffffffd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_1033:
	/* 0x1033: lea    r10d,[rbx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1037:
	/* 0x1037: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_103b:
	/* 0x103b: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1042:
	/* 0x1042: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1047:
	/* 0x1047: mov    BYTE PTR [rdx-0x3],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_104b:
	/* 0x104b: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_104f:
	/* 0x104f: cmp    r10,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_1053:
	/* 0x1053: je     10ca <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4298ULL;
	}
x86_l_1055:
	/* 0x1055: lea    r11d,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1059:
	/* 0x1059: add    r11d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_105d:
	/* 0x105d: and    r11d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1064:
	/* 0x1064: movzx  r11d,BYTE PTR [r14+r11*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R11, 0, X86_WIDTH_8), 0ULL);
x86_l_1069:
	/* 0x1069: mov    BYTE PTR [rdx-0x2],r11b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R11, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551614ULL);
x86_l_106d:
	/* 0x106d: cmp    r10,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1071:
	/* 0x1071: je     10ca <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4298ULL;
	}
x86_l_1073:
	/* 0x1073: lea    r10d,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1077:
	/* 0x1077: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_107b:
	/* 0x107b: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1082:
	/* 0x1082: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_1087:
	/* 0x1087: mov    BYTE PTR [rdx-0x1],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_108b:
	/* 0x108b: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_108e:
	/* 0x108e: add    r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1091:
	/* 0x1091: je     10ca <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4298ULL;
	}
x86_l_1093:
	/* 0x1093: cmp    r9,0xffffffffffffff81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_64, 18446744073709551489ULL);
x86_l_1097:
	/* 0x1097: je     10ca <filter_char_buf_postfix+0x125> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 4298ULL;
	}
x86_l_1099:
	/* 0x1099: lea    r10d,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R9, 0), 0ULL);
	return 4253ULL;
}

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_3(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 4253ULL: goto x86_l_109d;
	case 4257ULL: goto x86_l_10a1;
	case 4264ULL: goto x86_l_10a8;
	case 4269ULL: goto x86_l_10ad;
	case 4272ULL: goto x86_l_10b0;
	case 4276ULL: goto x86_l_10b4;
	case 4280ULL: goto x86_l_10b8;
	case 4284ULL: goto x86_l_10bc;
	case 4288ULL: goto x86_l_10c0;
	case 4292ULL: goto x86_l_10c4;
	case 4298ULL: goto x86_l_10ca;
	case 4303ULL: goto x86_l_10cf;
	case 4306ULL: goto x86_l_10d2;
	case 4308ULL: goto x86_l_10d4;
	case 4311ULL: goto x86_l_10d7;
	case 4313ULL: goto x86_l_10d9;
	case 4316ULL: goto x86_l_10dc;
	case 4319ULL: goto x86_l_10df;
	case 4321ULL: goto x86_l_10e1;
	case 4323ULL: goto x86_l_10e3;
	case 4327ULL: goto x86_l_10e7;
	case 4328ULL: goto x86_l_10e8;
	case 4330ULL: goto x86_l_10ea;
	case 4332ULL: goto x86_l_10ec;
	case 4333ULL: goto x86_l_10ed;
	case 4334ULL: goto x86_l_10ee;
	case 4336ULL: goto x86_l_10f0;
	case 4338ULL: goto x86_l_10f2;
	case 4339ULL: goto x86_l_10f3;
	case 4340ULL: goto x86_l_10f4;
	case 4342ULL: goto x86_l_10f6;
	case 4345ULL: goto x86_l_10f9;
	case 4349ULL: goto x86_l_10fd;
	case 4356ULL: goto x86_l_1104;
	case 4363ULL: goto x86_l_110b;
	case 4368ULL: goto x86_l_1110;
	case 4373ULL: goto x86_l_1115;
	case 4375ULL: goto x86_l_1117;
	case 4378ULL: goto x86_l_111a;
	case 4380ULL: goto x86_l_111c;
	case 4382ULL: goto x86_l_111e;
	case 4384ULL: goto x86_l_1120;
	case 4387ULL: goto x86_l_1123;
	case 4389ULL: goto x86_l_1125;
	case 4396ULL: goto x86_l_112c;
	case 4399ULL: goto x86_l_112f;
	case 4404ULL: goto x86_l_1134;
	case 4406ULL: goto x86_l_1136;
	case 4409ULL: goto x86_l_1139;
	case 4411ULL: goto x86_l_113b;
	case 4417ULL: goto x86_l_1141;
	case 4422ULL: goto x86_l_1146;
	case 4425ULL: goto x86_l_1149;
	case 4432ULL: goto x86_l_1150;
	case 4434ULL: goto x86_l_1152;
	case 4437ULL: goto x86_l_1155;
	case 4441ULL: goto x86_l_1159;
	case 4444ULL: goto x86_l_115c;
	case 4449ULL: goto x86_l_1161;
	case 4452ULL: goto x86_l_1164;
	case 4454ULL: goto x86_l_1166;
	case 4459ULL: goto x86_l_116b;
	case 4462ULL: goto x86_l_116e;
	case 4465ULL: goto x86_l_1171;
	case 4467ULL: goto x86_l_1173;
	case 4470ULL: goto x86_l_1176;
	case 4472ULL: goto x86_l_1178;
	case 4475ULL: goto x86_l_117b;
	case 4478ULL: goto x86_l_117e;
	case 4480ULL: goto x86_l_1180;
	case 4482ULL: goto x86_l_1182;
	case 4486ULL: goto x86_l_1186;
	case 4487ULL: goto x86_l_1187;
	case 4489ULL: goto x86_l_1189;
	case 4491ULL: goto x86_l_118b;
	case 4492ULL: goto x86_l_118c;
	case 4493ULL: goto x86_l_118d;
	case 4494ULL: goto x86_l_118e;
	case 4496ULL: goto x86_l_1190;
	case 4498ULL: goto x86_l_1192;
	case 4500ULL: goto x86_l_1194;
	case 4502ULL: goto x86_l_1196;
	case 4503ULL: goto x86_l_1197;
	case 4507ULL: goto x86_l_119b;
	case 4515ULL: goto x86_l_11a3;
	case 4521ULL: goto x86_l_11a9;
	case 4527ULL: goto x86_l_11af;
	case 4530ULL: goto x86_l_11b2;
	case 4535ULL: goto x86_l_11b7;
	case 4537ULL: goto x86_l_11b9;
	case 4540ULL: goto x86_l_11bc;
	case 4546ULL: goto x86_l_11c2;
	case 4549ULL: goto x86_l_11c5;
	case 4552ULL: goto x86_l_11c8;
	case 4555ULL: goto x86_l_11cb;
	case 4557ULL: goto x86_l_11cd;
	case 4560ULL: goto x86_l_11d0;
	case 4562ULL: goto x86_l_11d2;
	case 4564ULL: goto x86_l_11d4;
	case 4567ULL: goto x86_l_11d7;
	case 4569ULL: goto x86_l_11d9;
	case 4571ULL: goto x86_l_11db;
	case 4574ULL: goto x86_l_11de;
	case 4576ULL: goto x86_l_11e0;
	case 4578ULL: goto x86_l_11e2;
	case 4580ULL: goto x86_l_11e4;
	case 4583ULL: goto x86_l_11e7;
	case 4587ULL: goto x86_l_11eb;
	case 4591ULL: goto x86_l_11ef;
	case 4593ULL: goto x86_l_11f1;
	case 4596ULL: goto x86_l_11f4;
	case 4599ULL: goto x86_l_11f7;
	case 4606ULL: goto x86_l_11fe;
	case 4610ULL: goto x86_l_1202;
	case 4613ULL: goto x86_l_1205;
	case 4618ULL: goto x86_l_120a;
	case 4624ULL: goto x86_l_1210;
	case 4629ULL: goto x86_l_1215;
	case 4631ULL: goto x86_l_1217;
	case 4637ULL: goto x86_l_121d;
	case 4642ULL: goto x86_l_1222;
	case 4644ULL: goto x86_l_1224;
	case 4650ULL: goto x86_l_122a;
	case 4655ULL: goto x86_l_122f;
	case 4657ULL: goto x86_l_1231;
	case 4660ULL: goto x86_l_1234;
	case 4665ULL: goto x86_l_1239;
	case 4669ULL: goto x86_l_123d;
	case 4673ULL: goto x86_l_1241;
	case 4680ULL: goto x86_l_1248;
	case 4687ULL: goto x86_l_124f;
	case 4693ULL: goto x86_l_1255;
	case 4696ULL: goto x86_l_1258;
	case 4698ULL: goto x86_l_125a;
	case 4700ULL: goto x86_l_125c;
	case 4702ULL: goto x86_l_125e;
	case 4705ULL: goto x86_l_1261;
	case 4707ULL: goto x86_l_1263;
	case 4713ULL: goto x86_l_1269;
	case 4715ULL: goto x86_l_126b;
	case 4718ULL: goto x86_l_126e;
	case 4720ULL: goto x86_l_1270;
	case 4723ULL: goto x86_l_1273;
	case 4725ULL: goto x86_l_1275;
	case 4731ULL: goto x86_l_127b;
	case 4733ULL: goto x86_l_127d;
	case 4739ULL: goto x86_l_1283;
	case 4741ULL: goto x86_l_1285;
	case 4747ULL: goto x86_l_128b;
	case 4749ULL: goto x86_l_128d;
	case 4755ULL: goto x86_l_1293;
	case 4758ULL: goto x86_l_1296;
	case 4761ULL: goto x86_l_1299;
	case 4766ULL: goto x86_l_129e;
	case 4770ULL: goto x86_l_12a2;
	case 4776ULL: goto x86_l_12a8;
	case 4781ULL: goto x86_l_12ad;
	case 4783ULL: goto x86_l_12af;
	case 4790ULL: goto x86_l_12b6;
	case 4795ULL: goto x86_l_12bb;
	case 4800ULL: goto x86_l_12c0;
	case 4803ULL: goto x86_l_12c3;
	case 4805ULL: goto x86_l_12c5;
	case 4808ULL: goto x86_l_12c8;
	case 4815ULL: goto x86_l_12cf;
	case 4820ULL: goto x86_l_12d4;
	case 4823ULL: goto x86_l_12d7;
	case 4825ULL: goto x86_l_12d9;
	case 4828ULL: goto x86_l_12dc;
	case 4830ULL: goto x86_l_12de;
	case 4835ULL: goto x86_l_12e3;
	case 4838ULL: goto x86_l_12e6;
	case 4844ULL: goto x86_l_12ec;
	case 4847ULL: goto x86_l_12ef;
	case 4853ULL: goto x86_l_12f5;
	case 4858ULL: goto x86_l_12fa;
	case 4862ULL: goto x86_l_12fe;
	case 4864ULL: goto x86_l_1300;
	case 4869ULL: goto x86_l_1305;
	case 4872ULL: goto x86_l_1308;
	case 4876ULL: goto x86_l_130c;
	case 4879ULL: goto x86_l_130f;
	case 4884ULL: goto x86_l_1314;
	case 4889ULL: goto x86_l_1319;
	case 4891ULL: goto x86_l_131b;
	case 4893ULL: goto x86_l_131d;
	case 4896ULL: goto x86_l_1320;
	case 4898ULL: goto x86_l_1322;
	case 4903ULL: goto x86_l_1327;
	case 4907ULL: goto x86_l_132b;
	case 4910ULL: goto x86_l_132e;
	case 4917ULL: goto x86_l_1335;
	case 4922ULL: goto x86_l_133a;
	case 4927ULL: goto x86_l_133f;
	case 4929ULL: goto x86_l_1341;
	case 4934ULL: goto x86_l_1346;
	case 4937ULL: goto x86_l_1349;
	case 4941ULL: goto x86_l_134d;
	case 4944ULL: goto x86_l_1350;
	case 4949ULL: goto x86_l_1355;
	case 4954ULL: goto x86_l_135a;
	case 4956ULL: goto x86_l_135c;
	case 4958ULL: goto x86_l_135e;
	case 4961ULL: goto x86_l_1361;
	case 4963ULL: goto x86_l_1363;
	case 4968ULL: goto x86_l_1368;
	case 4972ULL: goto x86_l_136c;
	case 4976ULL: goto x86_l_1370;
	case 4983ULL: goto x86_l_1377;
	case 4988ULL: goto x86_l_137c;
	case 4993ULL: goto x86_l_1381;
	case 4996ULL: goto x86_l_1384;
	case 4998ULL: goto x86_l_1386;
	case 5003ULL: goto x86_l_138b;
	case 5007ULL: goto x86_l_138f;
	case 5009ULL: goto x86_l_1391;
	case 5013ULL: goto x86_l_1395;
	case 5015ULL: goto x86_l_1397;
	case 5019ULL: goto x86_l_139b;
	case 5025ULL: goto x86_l_13a1;
	case 5029ULL: goto x86_l_13a5;
	case 5035ULL: goto x86_l_13ab;
	case 5039ULL: goto x86_l_13af;
	case 5045ULL: goto x86_l_13b5;
	case 5052ULL: goto x86_l_13bc;
	case 5057ULL: goto x86_l_13c1;
	case 5062ULL: goto x86_l_13c6;
	case 5067ULL: goto x86_l_13cb;
	case 5071ULL: goto x86_l_13cf;
	case 5073ULL: goto x86_l_13d1;
	case 5077ULL: goto x86_l_13d5;
	case 5083ULL: goto x86_l_13db;
	case 5087ULL: goto x86_l_13df;
	case 5093ULL: goto x86_l_13e5;
	case 5097ULL: goto x86_l_13e9;
	case 5103ULL: goto x86_l_13ef;
	case 5110ULL: goto x86_l_13f6;
	case 5115ULL: goto x86_l_13fb;
	case 5120ULL: goto x86_l_1400;
	case 5125ULL: goto x86_l_1405;
	case 5129ULL: goto x86_l_1409;
	case 5135ULL: goto x86_l_140f;
	case 5139ULL: goto x86_l_1413;
	case 5145ULL: goto x86_l_1419;
	case 5149ULL: goto x86_l_141d;
	case 5155ULL: goto x86_l_1423;
	case 5162ULL: goto x86_l_142a;
	case 5167ULL: goto x86_l_142f;
	case 5172ULL: goto x86_l_1434;
	case 5177ULL: goto x86_l_1439;
	case 5180ULL: goto x86_l_143c;
	case 5182ULL: goto x86_l_143e;
	case 5186ULL: goto x86_l_1442;
	case 5192ULL: goto x86_l_1448;
	case 5199ULL: goto x86_l_144f;
	case 5204ULL: goto x86_l_1454;
	case 5209ULL: goto x86_l_1459;
	case 5214ULL: goto x86_l_145e;
	case 5221ULL: goto x86_l_1465;
	case 5226ULL: goto x86_l_146a;
	case 5231ULL: goto x86_l_146f;
	case 5233ULL: goto x86_l_1471;
	case 5240ULL: goto x86_l_1478;
	case 5245ULL: goto x86_l_147d;
	case 5250ULL: goto x86_l_1482;
	case 5252ULL: goto x86_l_1484;
	case 5259ULL: goto x86_l_148b;
	case 5264ULL: goto x86_l_1490;
	case 5269ULL: goto x86_l_1495;
	case 5271ULL: goto x86_l_1497;
	case 5278ULL: goto x86_l_149e;
	case 5283ULL: goto x86_l_14a3;
	case 5288ULL: goto x86_l_14a8;
	case 5290ULL: goto x86_l_14aa;
	case 5297ULL: goto x86_l_14b1;
	case 5302ULL: goto x86_l_14b6;
	case 5307ULL: goto x86_l_14bb;
	case 5309ULL: goto x86_l_14bd;
	case 5316ULL: goto x86_l_14c4;
	case 5321ULL: goto x86_l_14c9;
	case 5326ULL: goto x86_l_14ce;
	case 5328ULL: goto x86_l_14d0;
	case 5335ULL: goto x86_l_14d7;
	case 5340ULL: goto x86_l_14dc;
	case 5345ULL: goto x86_l_14e1;
	case 5350ULL: goto x86_l_14e6;
	case 5352ULL: goto x86_l_14e8;
	case 5355ULL: goto x86_l_14eb;
	case 5357ULL: goto x86_l_14ed;
	case 5360ULL: goto x86_l_14f0;
	case 5365ULL: goto x86_l_14f5;
	case 5370ULL: goto x86_l_14fa;
	case 5372ULL: goto x86_l_14fc;
	case 5375ULL: goto x86_l_14ff;
	case 5377ULL: goto x86_l_1501;
	case 5380ULL: goto x86_l_1504;
	case 5383ULL: goto x86_l_1507;
	case 5385ULL: goto x86_l_1509;
	case 5387ULL: goto x86_l_150b;
	case 5391ULL: goto x86_l_150f;
	case 5392ULL: goto x86_l_1510;
	case 5394ULL: goto x86_l_1512;
	case 5396ULL: goto x86_l_1514;
	case 5398ULL: goto x86_l_1516;
	case 5400ULL: goto x86_l_1518;
	case 5401ULL: goto x86_l_1519;
	case 5402ULL: goto x86_l_151a;
	case 5403ULL: goto x86_l_151b;
	case 5405ULL: goto x86_l_151d;
	case 5407ULL: goto x86_l_151f;
	case 5409ULL: goto x86_l_1521;
	case 5411ULL: goto x86_l_1523;
	case 5412ULL: goto x86_l_1524;
	case 5413ULL: goto x86_l_1525;
	case 5416ULL: goto x86_l_1528;
	case 5419ULL: goto x86_l_152b;
	case 5421ULL: goto x86_l_152d;
	case 5423ULL: goto x86_l_152f;
	case 5429ULL: goto x86_l_1535;
	case 5431ULL: goto x86_l_1537;
	case 5437ULL: goto x86_l_153d;
	case 5442ULL: goto x86_l_1542;
	case 5444ULL: goto x86_l_1544;
	case 5447ULL: goto x86_l_1547;
	case 5452ULL: goto x86_l_154c;
	case 5456ULL: goto x86_l_1550;
	case 5461ULL: goto x86_l_1555;
	case 5468ULL: goto x86_l_155c;
	case 5471ULL: goto x86_l_155f;
	case 5473ULL: goto x86_l_1561;
	case 5476ULL: goto x86_l_1564;
	case 5482ULL: goto x86_l_156a;
	case 5485ULL: goto x86_l_156d;
	case 5487ULL: goto x86_l_156f;
	case 5489ULL: goto x86_l_1571;
	case 5492ULL: goto x86_l_1574;
	case 5495ULL: goto x86_l_1577;
	case 5498ULL: goto x86_l_157a;
	case 5500ULL: goto x86_l_157c;
	case 5502ULL: goto x86_l_157e;
	case 5506ULL: goto x86_l_1582;
	case 5509ULL: goto x86_l_1585;
	case 5511ULL: goto x86_l_1587;
	case 5515ULL: goto x86_l_158b;
	case 5517ULL: goto x86_l_158d;
	case 5519ULL: goto x86_l_158f;
	case 5524ULL: goto x86_l_1594;
	case 5528ULL: goto x86_l_1598;
	case 5531ULL: goto x86_l_159b;
	case 5535ULL: goto x86_l_159f;
	case 5539ULL: goto x86_l_15a3;
	case 5543ULL: goto x86_l_15a7;
	case 5547ULL: goto x86_l_15ab;
	case 5550ULL: goto x86_l_15ae;
	case 5554ULL: goto x86_l_15b2;
	case 5558ULL: goto x86_l_15b6;
	case 5562ULL: goto x86_l_15ba;
	case 5566ULL: goto x86_l_15be;
	case 5568ULL: goto x86_l_15c0;
	case 5571ULL: goto x86_l_15c3;
	case 5574ULL: goto x86_l_15c6;
	case 5576ULL: goto x86_l_15c8;
	case 5578ULL: goto x86_l_15ca;
	case 5580ULL: goto x86_l_15cc;
	case 5586ULL: goto x86_l_15d2;
	case 5591ULL: goto x86_l_15d7;
	case 5595ULL: goto x86_l_15db;
	case 5601ULL: goto x86_l_15e1;
	case 5605ULL: goto x86_l_15e5;
	case 5608ULL: goto x86_l_15e8;
	case 5612ULL: goto x86_l_15ec;
	case 5618ULL: goto x86_l_15f2;
	case 5623ULL: goto x86_l_15f7;
	case 5625ULL: goto x86_l_15f9;
	case 5631ULL: goto x86_l_15ff;
	case 5636ULL: goto x86_l_1604;
	case 5638ULL: goto x86_l_1606;
	case 5641ULL: goto x86_l_1609;
	case 5646ULL: goto x86_l_160e;
	case 5650ULL: goto x86_l_1612;
	case 5655ULL: goto x86_l_1617;
	case 5662ULL: goto x86_l_161e;
	case 5665ULL: goto x86_l_1621;
	case 5667ULL: goto x86_l_1623;
	default: return 0xffffffffffffffffULL;
	}
x86_l_109d:
	/* 0x109d: add    r10d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 3ULL);
x86_l_10a1:
	/* 0x10a1: and    r10d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_10a8:
	/* 0x10a8: movzx  r10d,BYTE PTR [r14+r10*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_R10, 0, X86_WIDTH_8), 0ULL);
x86_l_10ad:
	/* 0x10ad: mov    BYTE PTR [rdx],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b0:
	/* 0x10b0: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_10b4:
	/* 0x10b4: lea    r10,[rax+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_10b8:
	/* 0x10b8: add    r10,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10bc:
	/* 0x10bc: add    r9,0xfffffffffffffffc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_ADD, 18446744073709551612ULL);
x86_l_10c0:
	/* 0x10c0: cmp    r10,0xfffffffffffffffd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 18446744073709551613ULL);
x86_l_10c4:
	/* 0x10c4: jne    1033 <filter_char_buf_postfix+0x8e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 4147ULL;
	}
x86_l_10ca:
	/* 0x10ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10cf:
	/* 0x10cf: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_10d2:
	/* 0x10d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d4:
	/* 0x10d4: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10d7:
	/* 0x10d7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d9:
	/* 0x10d9: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_10dc:
	/* 0x10dc: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_10df:
	/* 0x10df: jmp    10e3 <filter_char_buf_postfix+0x13e> */
	goto x86_l_10e3;
x86_l_10e1:
	/* 0x10e1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e3:
	/* 0x10e3: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10e7:
	/* 0x10e7: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_10e8:
	/* 0x10e8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_10ea:
	/* 0x10ea: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_10ed:
	/* 0x10ed: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_10ee:
	/* 0x10ee: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_10f0:
	/* 0x10f0: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_10f2:
	/* 0x10f2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_10f3:
	/* 0x10f3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_10f4:
	/* 0x10f4: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_10f6:
	/* 0x10f6: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_10f9:
	/* 0x10f9: mov    DWORD PTR [rsp+0x4],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10fd:
	/* 0x10fd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1104:
	/* 0x1104: mov    rdi,QWORD PTR [rip+0x23a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps)));
x86_l_110b:
	/* 0x110b: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1110:
	/* 0x1110: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1115:
	/* 0x1115: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1117:
	/* 0x1117: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_111a:
	/* 0x111a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111c:
	/* 0x111c: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_111e:
	/* 0x111e: je     1182 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1182;
	}
x86_l_1120:
	/* 0x1120: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1123:
	/* 0x1123: je     1182 <filter_char_buf_prefix+0x95> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1182;
	}
x86_l_1125:
	/* 0x1125: mov    rdi,QWORD PTR [rip+0x23a0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_prefix_maps_heap)));
x86_l_112c:
	/* 0x112c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_112f:
	/* 0x112f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1134:
	/* 0x1134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1136:
	/* 0x1136: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1139:
	/* 0x1139: je     1180 <filter_char_buf_prefix+0x93> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1180;
	}
x86_l_113b:
	/* 0x113b: cmp    ebp,0xff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 255ULL);
x86_l_1141:
	/* 0x1141: mov    esi,0xff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 255ULL);
x86_l_1146:
	/* 0x1146: cmovb  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_B);
x86_l_1149:
	/* 0x1149: lea    ecx,[rsi*8+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 0ULL);
x86_l_1150:
	/* 0x1150: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1152:
	/* 0x1152: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1155:
	/* 0x1155: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1159:
	/* 0x1159: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_115c:
	/* 0x115c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1161:
	/* 0x1161: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_1164:
	/* 0x1164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1166:
	/* 0x1166: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_116b:
	/* 0x116b: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_116e:
	/* 0x116e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1171:
	/* 0x1171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1173:
	/* 0x1173: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1176:
	/* 0x1176: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1178:
	/* 0x1178: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_117b:
	/* 0x117b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_117e:
	/* 0x117e: jmp    1182 <filter_char_buf_prefix+0x95> */
	goto x86_l_1182;
x86_l_1180:
	/* 0x1180: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1182:
	/* 0x1182: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1186:
	/* 0x1186: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1187:
	/* 0x1187: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1189:
	/* 0x1189: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_118b:
	/* 0x118b: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_118c:
	/* 0x118c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_118d:
	/* 0x118d: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_118e:
	/* 0x118e: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_1190:
	/* 0x1190: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1192:
	/* 0x1192: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1194:
	/* 0x1194: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1196:
	/* 0x1196: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1197:
	/* 0x1197: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_119b:
	/* 0x119b: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_11a3:
	/* 0x11a3: cmp    edx,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4096ULL);
x86_l_11a9:
	/* 0x11a9: ja     1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1509;
	}
x86_l_11af:
	/* 0x11af: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11b2:
	/* 0x11b2: cmp    eax,0x90 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_11b7:
	/* 0x11b7: ja     120a <filter_char_buf_equal+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_120a;
	}
x86_l_11b9:
	/* 0x11b9: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11bc:
	/* 0x11bc: imul   ecx,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RCX, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11c2:
	/* 0x11c2: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_11c5:
	/* 0x11c5: and    ecx,0xfffffff8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967288ULL);
x86_l_11c8:
	/* 0x11c8: lea    ecx,[rcx+rcx*2] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 0ULL);
x86_l_11cb:
	/* 0x11cb: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_11cd:
	/* 0x11cd: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_11d0:
	/* 0x11d0: je     11db <filter_char_buf_equal+0x4e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11db;
	}
x86_l_11d2:
	/* 0x11d2: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_11d4:
	/* 0x11d4: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_11d7:
	/* 0x11d7: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_11d9:
	/* 0x11d9: je     11f4 <filter_char_buf_equal+0x67> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_11f4;
	}
x86_l_11db:
	/* 0x11db: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11de:
	/* 0x11de: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_11e0:
	/* 0x11e0: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_11e2:
	/* 0x11e2: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_11e4:
	/* 0x11e4: add    eax,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 24ULL);
x86_l_11e7:
	/* 0x11e7: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11eb:
	/* 0x11eb: cmp    cx,0x78 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 120ULL);
x86_l_11ef:
	/* 0x11ef: ja     1248 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1248;
	}
x86_l_11f1:
	/* 0x11f1: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_11f4:
	/* 0x11f4: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11f7:
	/* 0x11f7: imul   r12d,eax,0xab */
	X86_SIM_L_EXEC_IMUL_IMM(X86_R12, X86_RAX, X86_WIDTH_32, 171ULL);
x86_l_11fe:
	/* 0x11fe: shr    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 12ULL);
x86_l_1202:
	/* 0x1202: dec    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_1205:
	/* 0x1205: jmp    1293 <filter_char_buf_equal+0x106> */
	goto x86_l_1293;
x86_l_120a:
	/* 0x120a: mov    r14d,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 256ULL);
x86_l_1210:
	/* 0x1210: cmp    eax,0x101 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 257ULL);
x86_l_1215:
	/* 0x1215: jb     1248 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1248;
	}
x86_l_1217:
	/* 0x1217: mov    r14d,0x200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 512ULL);
x86_l_121d:
	/* 0x121d: cmp    eax,0x201 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 513ULL);
x86_l_1222:
	/* 0x1222: jb     1248 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1248;
	}
x86_l_1224:
	/* 0x1224: mov    r14d,0x400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1024ULL);
x86_l_122a:
	/* 0x122a: cmp    eax,0x401 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1025ULL);
x86_l_122f:
	/* 0x122f: jb     1248 <filter_char_buf_equal+0xbb> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1248;
	}
x86_l_1231:
	/* 0x1231: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1234:
	/* 0x1234: cmp    eax,0x801 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2049ULL);
x86_l_1239:
	/* 0x1239: setae  r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_AE);
x86_l_123d:
	/* 0x123d: shl    r14d,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 11ULL);
x86_l_1241:
	/* 0x1241: add    r14d,0x800 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2048ULL);
x86_l_1248:
	/* 0x1248: lea    eax,[r14-0x100] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551360ULL);
x86_l_124f:
	/* 0x124f: rorx   eax,eax,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RAX, X86_WIDTH_32, 0, 8ULL);
x86_l_1255:
	/* 0x1255: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1258:
	/* 0x1258: jg     126b <filter_char_buf_equal+0xde> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_126b;
	}
x86_l_125a:
	/* 0x125a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_125c:
	/* 0x125c: je     1285 <filter_char_buf_equal+0xf8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1285;
	}
x86_l_125e:
	/* 0x125e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1261:
	/* 0x1261: jne    127d <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_127d;
	}
x86_l_1263:
	/* 0x1263: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1269:
	/* 0x1269: jmp    1293 <filter_char_buf_equal+0x106> */
	goto x86_l_1293;
x86_l_126b:
	/* 0x126b: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_126e:
	/* 0x126e: je     128d <filter_char_buf_equal+0x100> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_128d;
	}
x86_l_1270:
	/* 0x1270: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1273:
	/* 0x1273: jne    127d <filter_char_buf_equal+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_127d;
	}
x86_l_1275:
	/* 0x1275: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_127b:
	/* 0x127b: jmp    1293 <filter_char_buf_equal+0x106> */
	goto x86_l_1293;
x86_l_127d:
	/* 0x127d: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1283:
	/* 0x1283: jmp    1293 <filter_char_buf_equal+0x106> */
	goto x86_l_1293;
x86_l_1285:
	/* 0x1285: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_128b:
	/* 0x128b: jmp    1293 <filter_char_buf_equal+0x106> */
	goto x86_l_1293;
x86_l_128d:
	/* 0x128d: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1293:
	/* 0x1293: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1296:
	/* 0x1296: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_1299:
	/* 0x1299: mov    r13d,DWORD PTR [rdi+rax*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 16ULL);
x86_l_129e:
	/* 0x129e: cmp    r13d,0xffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967295ULL);
x86_l_12a2:
	/* 0x12a2: je     1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1509;
	}
x86_l_12a8:
	/* 0x12a8: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12ad:
	/* 0x12ad: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_12af:
	/* 0x12af: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_heap)));
x86_l_12b6:
	/* 0x12b6: lea    r15,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12bb:
	/* 0x12bb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12c0:
	/* 0x12c0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12c3:
	/* 0x12c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c5:
	/* 0x12c5: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_12c8:
	/* 0x12c8: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_12cf:
	/* 0x12cf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12d4:
	/* 0x12d4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12d7:
	/* 0x12d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d9:
	/* 0x12d9: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_12dc:
	/* 0x12dc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12de:
	/* 0x12de: mov    QWORD PTR [rsp+0x8],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e3:
	/* 0x12e3: test   rbx,rbx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_64);
x86_l_12e6:
	/* 0x12e6: je     150b <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150b;
	}
x86_l_12ec:
	/* 0x12ec: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_12ef:
	/* 0x12ef: je     150b <filter_char_buf_equal+0x37e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_150b;
	}
x86_l_12f5:
	/* 0x12f5: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12fa:
	/* 0x12fa: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_12fe:
	/* 0x12fe: jg     1341 <filter_char_buf_equal+0x1b4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1341;
	}
x86_l_1300:
	/* 0x1300: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1305:
	/* 0x1305: mov    BYTE PTR [rax],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1308:
	/* 0x1308: lea    rdi,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_130c:
	/* 0x130c: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_130f:
	/* 0x130f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1314:
	/* 0x1314: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1319:
	/* 0x1319: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_131b:
	/* 0x131b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131d:
	/* 0x131d: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1320:
	/* 0x1320: jbe    1386 <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1386;
	}
x86_l_1322:
	/* 0x1322: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1327:
	/* 0x1327: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_132b:
	/* 0x132b: inc    rdi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_132e:
	/* 0x132e: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1335:
	/* 0x1335: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_133a:
	/* 0x133a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_133f:
	/* 0x133f: jmp    1381 <filter_char_buf_equal+0x1f4> */
	goto x86_l_1381;
x86_l_1341:
	/* 0x1341: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1346:
	/* 0x1346: mov    WORD PTR [rax],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1349:
	/* 0x1349: lea    rdi,[rax+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_134d:
	/* 0x134d: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_1350:
	/* 0x1350: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1355:
	/* 0x1355: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_135a:
	/* 0x135a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_135c:
	/* 0x135c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135e:
	/* 0x135e: sub    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1361:
	/* 0x1361: jbe    1386 <filter_char_buf_equal+0x1f9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1386;
	}
x86_l_1363:
	/* 0x1363: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1368:
	/* 0x1368: lea    rdi,[rax+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_136c:
	/* 0x136c: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1370:
	/* 0x1370: and    r14d,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1377:
	/* 0x1377: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_137c:
	/* 0x137c: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1381:
	/* 0x1381: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1384:
	/* 0x1384: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1386:
	/* 0x1386: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_138b:
	/* 0x138b: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_138f:
	/* 0x138f: jle    13cb <filter_char_buf_equal+0x23e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_13cb;
	}
x86_l_1391:
	/* 0x1391: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1395:
	/* 0x1395: jg     1405 <filter_char_buf_equal+0x278> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1405;
	}
x86_l_1397:
	/* 0x1397: cmp    r12d,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 5ULL);
x86_l_139b:
	/* 0x139b: je     14bd <filter_char_buf_equal+0x330> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14bd;
	}
x86_l_13a1:
	/* 0x13a1: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_13a5:
	/* 0x13a5: je     1484 <filter_char_buf_equal+0x2f7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1484;
	}
x86_l_13ab:
	/* 0x13ab: cmp    r12d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 7ULL);
x86_l_13af:
	/* 0x13af: jne    1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1509;
	}
x86_l_13b5:
	/* 0x13b5: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_7)));
x86_l_13bc:
	/* 0x13bc: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13c1:
	/* 0x13c1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13c6:
	/* 0x13c6: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_13cb:
	/* 0x13cb: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_13cf:
	/* 0x13cf: jle    1439 <filter_char_buf_equal+0x2ac> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1439;
	}
x86_l_13d1:
	/* 0x13d1: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_13d5:
	/* 0x13d5: je     14aa <filter_char_buf_equal+0x31d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14aa;
	}
x86_l_13db:
	/* 0x13db: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_13df:
	/* 0x13df: je     1471 <filter_char_buf_equal+0x2e4> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1471;
	}
x86_l_13e5:
	/* 0x13e5: cmp    r12d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4ULL);
x86_l_13e9:
	/* 0x13e9: jne    1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1509;
	}
x86_l_13ef:
	/* 0x13ef: mov    rdi,QWORD PTR [rip+0x2010] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_4)));
x86_l_13f6:
	/* 0x13f6: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13fb:
	/* 0x13fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1400:
	/* 0x1400: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_1405:
	/* 0x1405: cmp    r12d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1409:
	/* 0x1409: je     14d0 <filter_char_buf_equal+0x343> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_14d0;
	}
x86_l_140f:
	/* 0x140f: cmp    r12d,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1413:
	/* 0x1413: je     1497 <filter_char_buf_equal+0x30a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1497;
	}
x86_l_1419:
	/* 0x1419: cmp    r12d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 10ULL);
x86_l_141d:
	/* 0x141d: jne    1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1509;
	}
x86_l_1423:
	/* 0x1423: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_10)));
x86_l_142a:
	/* 0x142a: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_142f:
	/* 0x142f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1434:
	/* 0x1434: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_1439:
	/* 0x1439: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_143c:
	/* 0x143c: je     145e <filter_char_buf_equal+0x2d1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_145e;
	}
x86_l_143e:
	/* 0x143e: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1442:
	/* 0x1442: jne    1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1509;
	}
x86_l_1448:
	/* 0x1448: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_1)));
x86_l_144f:
	/* 0x144f: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1454:
	/* 0x1454: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1459:
	/* 0x1459: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_145e:
	/* 0x145e: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_0)));
x86_l_1465:
	/* 0x1465: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_146a:
	/* 0x146a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_146f:
	/* 0x146f: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_1471:
	/* 0x1471: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_3)));
x86_l_1478:
	/* 0x1478: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_147d:
	/* 0x147d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1482:
	/* 0x1482: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_1484:
	/* 0x1484: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_6)));
x86_l_148b:
	/* 0x148b: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1490:
	/* 0x1490: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1495:
	/* 0x1495: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_1497:
	/* 0x1497: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_9)));
x86_l_149e:
	/* 0x149e: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14a3:
	/* 0x14a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14a8:
	/* 0x14a8: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_14aa:
	/* 0x14aa: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_2)));
x86_l_14b1:
	/* 0x14b1: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14b6:
	/* 0x14b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14bb:
	/* 0x14bb: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_14bd:
	/* 0x14bd: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_5)));
x86_l_14c4:
	/* 0x14c4: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14c9:
	/* 0x14c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ce:
	/* 0x14ce: jmp    14e1 <filter_char_buf_equal+0x354> */
	goto x86_l_14e1;
x86_l_14d0:
	/* 0x14d0: mov    rdi,QWORD PTR [rip+0x200c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&string_maps_8)));
x86_l_14d7:
	/* 0x14d7: lea    rcx,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14dc:
	/* 0x14dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14e1:
	/* 0x14e1: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14e6:
	/* 0x14e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e8:
	/* 0x14e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14eb:
	/* 0x14eb: je     1509 <filter_char_buf_equal+0x37c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1509;
	}
x86_l_14ed:
	/* 0x14ed: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14f0:
	/* 0x14f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f5:
	/* 0x14f5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14fa:
	/* 0x14fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14fc:
	/* 0x14fc: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14ff:
	/* 0x14ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1501:
	/* 0x1501: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1504:
	/* 0x1504: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1507:
	/* 0x1507: jmp    150b <filter_char_buf_equal+0x37e> */
	goto x86_l_150b;
x86_l_1509:
	/* 0x1509: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150b:
	/* 0x150b: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_150f:
	/* 0x150f: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1510:
	/* 0x1510: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1512:
	/* 0x1512: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1514:
	/* 0x1514: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1516:
	/* 0x1516: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1518:
	/* 0x1518: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1519:
	/* 0x1519: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_151a:
	/* 0x151a: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_151b:
	/* 0x151b: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_151d:
	/* 0x151d: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_151f:
	/* 0x151f: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_1521:
	/* 0x1521: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_1523:
	/* 0x1523: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1524:
	/* 0x1524: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1525:
	/* 0x1525: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_1528:
	/* 0x1528: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_152b:
	/* 0x152b: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_152d:
	/* 0x152d: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_152f:
	/* 0x152f: je     15f7 <filter_char_substring+0xdd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15f7;
	}
x86_l_1535:
	/* 0x1535: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_1537:
	/* 0x1537: je     1694 <filter_char_substring+0x17a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5780ULL;
	}
x86_l_153d:
	/* 0x153d: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1542:
	/* 0x1542: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1544:
	/* 0x1544: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1547:
	/* 0x1547: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_154c:
	/* 0x154c: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1550:
	/* 0x1550: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1555:
	/* 0x1555: mov    rdi,QWORD PTR [rip+0x2643] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_155c:
	/* 0x155c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_155f:
	/* 0x155f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1561:
	/* 0x1561: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1564:
	/* 0x1564: je     1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5912ULL;
	}
x86_l_156a:
	/* 0x156a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_156d:
	/* 0x156d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_156f:
	/* 0x156f: jmp    157c <filter_char_substring+0x62> */
	goto x86_l_157c;
x86_l_1571:
	/* 0x1571: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1574:
	/* 0x1574: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1577:
	/* 0x1577: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_157a:
	/* 0x157a: je     15d2 <filter_char_substring+0xb8> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15d2;
	}
x86_l_157c:
	/* 0x157c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157e:
	/* 0x157e: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1582:
	/* 0x1582: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: jae    1571 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1571;
	}
x86_l_1587:
	/* 0x1587: movsx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_158b:
	/* 0x158b: test   edi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_32);
x86_l_158d:
	/* 0x158d: je     15ca <filter_char_substring+0xb0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_15ca;
	}
x86_l_158f:
	/* 0x158f: movsx  r9d,BYTE PTR [rdx+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R9, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_1594:
	/* 0x1594: lea    r10d,[r9-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_1598:
	/* 0x1598: mov    r8d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R9, X86_WIDTH_32);
x86_l_159b:
	/* 0x159b: or     r8d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_159f:
	/* 0x159f: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_15a3:
	/* 0x15a3: cmovae r8d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_32, X86_CC_AE);
x86_l_15a7:
	/* 0x15a7: lea    r10d,[rdi-0x41] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551551ULL);
x86_l_15ab:
	/* 0x15ab: mov    r9d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RDI, X86_WIDTH_32);
x86_l_15ae:
	/* 0x15ae: or     r9d,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_OR, 32ULL);
x86_l_15b2:
	/* 0x15b2: cmp    r10d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 26ULL);
x86_l_15b6:
	/* 0x15b6: cmovae r9d,edi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_32, X86_CC_AE);
x86_l_15ba:
	/* 0x15ba: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_15be:
	/* 0x15be: ja     1571 <filter_char_substring+0x57> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1571;
	}
x86_l_15c0:
	/* 0x15c0: inc    rsi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15c3:
	/* 0x15c3: cmp    r8d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_R9, X86_WIDTH_32);
x86_l_15c6:
	/* 0x15c6: je     157e <filter_char_substring+0x64> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_157e;
	}
x86_l_15c8:
	/* 0x15c8: jmp    1571 <filter_char_substring+0x57> */
	goto x86_l_1571;
x86_l_15ca:
	/* 0x15ca: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_15cc:
	/* 0x15cc: jns    1729 <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		return 5929ULL;
	}
x86_l_15d2:
	/* 0x15d2: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15d7:
	/* 0x15d7: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_15db:
	/* 0x15db: jae    1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 5912ULL;
	}
x86_l_15e1:
	/* 0x15e1: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_15e5:
	/* 0x15e5: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_15e8:
	/* 0x15e8: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_15ec:
	/* 0x15ec: jne    1547 <filter_char_substring+0x2d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1547;
	}
x86_l_15f2:
	/* 0x15f2: jmp    1718 <filter_char_substring+0x1fe> */
	return 5912ULL;
x86_l_15f7:
	/* 0x15f7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_15f9:
	/* 0x15f9: je     16d7 <filter_char_substring+0x1bd> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 5847ULL;
	}
x86_l_15ff:
	/* 0x15ff: lea    r13,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1604:
	/* 0x1604: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1606:
	/* 0x1606: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1609:
	/* 0x1609: mov    eax,DWORD PTR [r14+rbx*4+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 2), 16ULL);
x86_l_160e:
	/* 0x160e: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1612:
	/* 0x1612: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1617:
	/* 0x1617: mov    rdi,QWORD PTR [rip+0x2651] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_161e:
	/* 0x161e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1621:
	/* 0x1621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1623:
	/* 0x1623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
	return 5670ULL;
}

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_4(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 5670ULL: goto x86_l_1626;
	case 5676ULL: goto x86_l_162c;
	case 5679ULL: goto x86_l_162f;
	case 5681ULL: goto x86_l_1631;
	case 5683ULL: goto x86_l_1633;
	case 5686ULL: goto x86_l_1636;
	case 5689ULL: goto x86_l_1639;
	case 5692ULL: goto x86_l_163c;
	case 5694ULL: goto x86_l_163e;
	case 5696ULL: goto x86_l_1640;
	case 5700ULL: goto x86_l_1644;
	case 5703ULL: goto x86_l_1647;
	case 5705ULL: goto x86_l_1649;
	case 5709ULL: goto x86_l_164d;
	case 5712ULL: goto x86_l_1650;
	case 5714ULL: goto x86_l_1652;
	case 5718ULL: goto x86_l_1656;
	case 5720ULL: goto x86_l_1658;
	case 5724ULL: goto x86_l_165c;
	case 5728ULL: goto x86_l_1660;
	case 5731ULL: goto x86_l_1663;
	case 5733ULL: goto x86_l_1665;
	case 5735ULL: goto x86_l_1667;
	case 5737ULL: goto x86_l_1669;
	case 5743ULL: goto x86_l_166f;
	case 5748ULL: goto x86_l_1674;
	case 5752ULL: goto x86_l_1678;
	case 5758ULL: goto x86_l_167e;
	case 5762ULL: goto x86_l_1682;
	case 5765ULL: goto x86_l_1685;
	case 5769ULL: goto x86_l_1689;
	case 5775ULL: goto x86_l_168f;
	case 5780ULL: goto x86_l_1694;
	case 5785ULL: goto x86_l_1699;
	case 5792ULL: goto x86_l_16a0;
	case 5797ULL: goto x86_l_16a5;
	case 5801ULL: goto x86_l_16a9;
	case 5805ULL: goto x86_l_16ad;
	case 5810ULL: goto x86_l_16b2;
	case 5813ULL: goto x86_l_16b5;
	case 5816ULL: goto x86_l_16b8;
	case 5818ULL: goto x86_l_16ba;
	case 5821ULL: goto x86_l_16bd;
	case 5823ULL: goto x86_l_16bf;
	case 5827ULL: goto x86_l_16c3;
	case 5830ULL: goto x86_l_16c6;
	case 5834ULL: goto x86_l_16ca;
	case 5836ULL: goto x86_l_16cc;
	case 5843ULL: goto x86_l_16d3;
	case 5845ULL: goto x86_l_16d5;
	case 5847ULL: goto x86_l_16d7;
	case 5852ULL: goto x86_l_16dc;
	case 5859ULL: goto x86_l_16e3;
	case 5864ULL: goto x86_l_16e8;
	case 5868ULL: goto x86_l_16ec;
	case 5872ULL: goto x86_l_16f0;
	case 5877ULL: goto x86_l_16f5;
	case 5880ULL: goto x86_l_16f8;
	case 5883ULL: goto x86_l_16fb;
	case 5885ULL: goto x86_l_16fd;
	case 5888ULL: goto x86_l_1700;
	case 5890ULL: goto x86_l_1702;
	case 5894ULL: goto x86_l_1706;
	case 5897ULL: goto x86_l_1709;
	case 5901ULL: goto x86_l_170d;
	case 5903ULL: goto x86_l_170f;
	case 5910ULL: goto x86_l_1716;
	case 5912ULL: goto x86_l_1718;
	case 5914ULL: goto x86_l_171a;
	case 5918ULL: goto x86_l_171e;
	case 5919ULL: goto x86_l_171f;
	case 5921ULL: goto x86_l_1721;
	case 5923ULL: goto x86_l_1723;
	case 5925ULL: goto x86_l_1725;
	case 5927ULL: goto x86_l_1727;
	case 5928ULL: goto x86_l_1728;
	case 5929ULL: goto x86_l_1729;
	case 5934ULL: goto x86_l_172e;
	case 5936ULL: goto x86_l_1730;
	case 5939ULL: goto x86_l_1733;
	case 5944ULL: goto x86_l_1738;
	case 5948ULL: goto x86_l_173c;
	case 5950ULL: goto x86_l_173e;
	case 5960ULL: goto x86_l_1748;
	case 5964ULL: goto x86_l_174c;
	case 5966ULL: goto x86_l_174e;
	case 5967ULL: goto x86_l_174f;
	case 5972ULL: goto x86_l_1754;
	case 5976ULL: goto x86_l_1758;
	case 5978ULL: goto x86_l_175a;
	case 5981ULL: goto x86_l_175d;
	case 5984ULL: goto x86_l_1760;
	case 5990ULL: goto x86_l_1766;
	case 5992ULL: goto x86_l_1768;
	case 5995ULL: goto x86_l_176b;
	case 5998ULL: goto x86_l_176e;
	case 5999ULL: goto x86_l_176f;
	case 6003ULL: goto x86_l_1773;
	case 6005ULL: goto x86_l_1775;
	case 6008ULL: goto x86_l_1778;
	case 6011ULL: goto x86_l_177b;
	case 6013ULL: goto x86_l_177d;
	case 6016ULL: goto x86_l_1780;
	case 6019ULL: goto x86_l_1783;
	case 6025ULL: goto x86_l_1789;
	case 6028ULL: goto x86_l_178c;
	case 6030ULL: goto x86_l_178e;
	case 6033ULL: goto x86_l_1791;
	case 6039ULL: goto x86_l_1797;
	case 6042ULL: goto x86_l_179a;
	case 6044ULL: goto x86_l_179c;
	case 6047ULL: goto x86_l_179f;
	case 6053ULL: goto x86_l_17a5;
	case 6056ULL: goto x86_l_17a8;
	case 6058ULL: goto x86_l_17aa;
	case 6063ULL: goto x86_l_17af;
	case 6066ULL: goto x86_l_17b2;
	case 6068ULL: goto x86_l_17b4;
	case 6071ULL: goto x86_l_17b7;
	case 6077ULL: goto x86_l_17bd;
	case 6080ULL: goto x86_l_17c0;
	case 6083ULL: goto x86_l_17c3;
	case 6089ULL: goto x86_l_17c9;
	case 6094ULL: goto x86_l_17ce;
	case 6097ULL: goto x86_l_17d1;
	case 6103ULL: goto x86_l_17d7;
	case 6106ULL: goto x86_l_17da;
	case 6109ULL: goto x86_l_17dd;
	case 6115ULL: goto x86_l_17e3;
	case 6118ULL: goto x86_l_17e6;
	case 6121ULL: goto x86_l_17e9;
	case 6127ULL: goto x86_l_17ef;
	case 6130ULL: goto x86_l_17f2;
	case 6136ULL: goto x86_l_17f8;
	case 6139ULL: goto x86_l_17fb;
	case 6145ULL: goto x86_l_1801;
	case 6148ULL: goto x86_l_1804;
	case 6154ULL: goto x86_l_180a;
	case 6157ULL: goto x86_l_180d;
	case 6163ULL: goto x86_l_1813;
	case 6166ULL: goto x86_l_1816;
	case 6172ULL: goto x86_l_181c;
	case 6177ULL: goto x86_l_1821;
	case 6180ULL: goto x86_l_1824;
	case 6183ULL: goto x86_l_1827;
	case 6189ULL: goto x86_l_182d;
	case 6194ULL: goto x86_l_1832;
	case 6197ULL: goto x86_l_1835;
	case 6203ULL: goto x86_l_183b;
	case 6206ULL: goto x86_l_183e;
	case 6209ULL: goto x86_l_1841;
	case 6215ULL: goto x86_l_1847;
	case 6218ULL: goto x86_l_184a;
	case 6221ULL: goto x86_l_184d;
	case 6227ULL: goto x86_l_1853;
	case 6230ULL: goto x86_l_1856;
	case 6236ULL: goto x86_l_185c;
	case 6239ULL: goto x86_l_185f;
	case 6245ULL: goto x86_l_1865;
	case 6248ULL: goto x86_l_1868;
	case 6254ULL: goto x86_l_186e;
	case 6257ULL: goto x86_l_1871;
	case 6263ULL: goto x86_l_1877;
	case 6266ULL: goto x86_l_187a;
	case 6272ULL: goto x86_l_1880;
	case 6277ULL: goto x86_l_1885;
	case 6280ULL: goto x86_l_1888;
	case 6283ULL: goto x86_l_188b;
	case 6285ULL: goto x86_l_188d;
	case 6288ULL: goto x86_l_1890;
	case 6294ULL: goto x86_l_1896;
	case 6297ULL: goto x86_l_1899;
	case 6299ULL: goto x86_l_189b;
	case 6302ULL: goto x86_l_189e;
	case 6308ULL: goto x86_l_18a4;
	case 6311ULL: goto x86_l_18a7;
	case 6313ULL: goto x86_l_18a9;
	case 6316ULL: goto x86_l_18ac;
	case 6322ULL: goto x86_l_18b2;
	case 6325ULL: goto x86_l_18b5;
	case 6331ULL: goto x86_l_18bb;
	case 6333ULL: goto x86_l_18bd;
	case 6343ULL: goto x86_l_18c7;
	case 6347ULL: goto x86_l_18cb;
	case 6353ULL: goto x86_l_18d1;
	case 6355ULL: goto x86_l_18d3;
	case 6358ULL: goto x86_l_18d6;
	case 6361ULL: goto x86_l_18d9;
	case 6367ULL: goto x86_l_18df;
	case 6370ULL: goto x86_l_18e2;
	case 6373ULL: goto x86_l_18e5;
	case 6375ULL: goto x86_l_18e7;
	case 6378ULL: goto x86_l_18ea;
	case 6384ULL: goto x86_l_18f0;
	case 6387ULL: goto x86_l_18f3;
	case 6389ULL: goto x86_l_18f5;
	case 6392ULL: goto x86_l_18f8;
	case 6398ULL: goto x86_l_18fe;
	case 6401ULL: goto x86_l_1901;
	case 6403ULL: goto x86_l_1903;
	case 6406ULL: goto x86_l_1906;
	case 6412ULL: goto x86_l_190c;
	case 6414ULL: goto x86_l_190e;
	case 6417ULL: goto x86_l_1911;
	case 6420ULL: goto x86_l_1914;
	case 6426ULL: goto x86_l_191a;
	case 6429ULL: goto x86_l_191d;
	case 6432ULL: goto x86_l_1920;
	case 6434ULL: goto x86_l_1922;
	case 6437ULL: goto x86_l_1925;
	case 6443ULL: goto x86_l_192b;
	case 6446ULL: goto x86_l_192e;
	case 6448ULL: goto x86_l_1930;
	case 6451ULL: goto x86_l_1933;
	case 6457ULL: goto x86_l_1939;
	case 6460ULL: goto x86_l_193c;
	case 6462ULL: goto x86_l_193e;
	case 6465ULL: goto x86_l_1941;
	case 6471ULL: goto x86_l_1947;
	case 6473ULL: goto x86_l_1949;
	case 6474ULL: goto x86_l_194a;
	case 6477ULL: goto x86_l_194d;
	case 6480ULL: goto x86_l_1950;
	case 6483ULL: goto x86_l_1953;
	case 6489ULL: goto x86_l_1959;
	case 6494ULL: goto x86_l_195e;
	case 6497ULL: goto x86_l_1961;
	case 6503ULL: goto x86_l_1967;
	case 6506ULL: goto x86_l_196a;
	case 6509ULL: goto x86_l_196d;
	case 6511ULL: goto x86_l_196f;
	case 6516ULL: goto x86_l_1974;
	case 6519ULL: goto x86_l_1977;
	case 6521ULL: goto x86_l_1979;
	case 6524ULL: goto x86_l_197c;
	case 6530ULL: goto x86_l_1982;
	case 6533ULL: goto x86_l_1985;
	case 6536ULL: goto x86_l_1988;
	case 6542ULL: goto x86_l_198e;
	case 6545ULL: goto x86_l_1991;
	case 6547ULL: goto x86_l_1993;
	case 6550ULL: goto x86_l_1996;
	case 6556ULL: goto x86_l_199c;
	case 6559ULL: goto x86_l_199f;
	case 6565ULL: goto x86_l_19a5;
	case 6568ULL: goto x86_l_19a8;
	case 6570ULL: goto x86_l_19aa;
	case 6573ULL: goto x86_l_19ad;
	case 6579ULL: goto x86_l_19b3;
	case 6582ULL: goto x86_l_19b6;
	case 6588ULL: goto x86_l_19bc;
	case 6590ULL: goto x86_l_19be;
	case 6593ULL: goto x86_l_19c1;
	case 6599ULL: goto x86_l_19c7;
	case 6602ULL: goto x86_l_19ca;
	case 6608ULL: goto x86_l_19d0;
	case 6613ULL: goto x86_l_19d5;
	case 6616ULL: goto x86_l_19d8;
	case 6619ULL: goto x86_l_19db;
	case 6623ULL: goto x86_l_19df;
	case 6626ULL: goto x86_l_19e2;
	case 6629ULL: goto x86_l_19e5;
	case 6632ULL: goto x86_l_19e8;
	case 6635ULL: goto x86_l_19eb;
	case 6641ULL: goto x86_l_19f1;
	case 6644ULL: goto x86_l_19f4;
	case 6648ULL: goto x86_l_19f8;
	case 6651ULL: goto x86_l_19fb;
	case 6655ULL: goto x86_l_19ff;
	case 6658ULL: goto x86_l_1a02;
	case 6661ULL: goto x86_l_1a05;
	case 6664ULL: goto x86_l_1a08;
	case 6670ULL: goto x86_l_1a0e;
	case 6673ULL: goto x86_l_1a11;
	case 6677ULL: goto x86_l_1a15;
	case 6680ULL: goto x86_l_1a18;
	case 6684ULL: goto x86_l_1a1c;
	case 6687ULL: goto x86_l_1a1f;
	case 6690ULL: goto x86_l_1a22;
	case 6693ULL: goto x86_l_1a25;
	case 6699ULL: goto x86_l_1a2b;
	case 6702ULL: goto x86_l_1a2e;
	case 6705ULL: goto x86_l_1a31;
	case 6708ULL: goto x86_l_1a34;
	case 6712ULL: goto x86_l_1a38;
	case 6714ULL: goto x86_l_1a3a;
	case 6717ULL: goto x86_l_1a3d;
	case 6720ULL: goto x86_l_1a40;
	case 6722ULL: goto x86_l_1a42;
	case 6727ULL: goto x86_l_1a47;
	case 6730ULL: goto x86_l_1a4a;
	case 6732ULL: goto x86_l_1a4c;
	case 6735ULL: goto x86_l_1a4f;
	case 6737ULL: goto x86_l_1a51;
	case 6738ULL: goto x86_l_1a52;
	case 6741ULL: goto x86_l_1a55;
	case 6744ULL: goto x86_l_1a58;
	case 6748ULL: goto x86_l_1a5c;
	case 6751ULL: goto x86_l_1a5f;
	case 6754ULL: goto x86_l_1a62;
	case 6757ULL: goto x86_l_1a65;
	case 6760ULL: goto x86_l_1a68;
	case 6766ULL: goto x86_l_1a6e;
	case 6769ULL: goto x86_l_1a71;
	case 6773ULL: goto x86_l_1a75;
	case 6776ULL: goto x86_l_1a78;
	case 6780ULL: goto x86_l_1a7c;
	case 6783ULL: goto x86_l_1a7f;
	case 6786ULL: goto x86_l_1a82;
	case 6789ULL: goto x86_l_1a85;
	case 6791ULL: goto x86_l_1a87;
	case 6794ULL: goto x86_l_1a8a;
	case 6798ULL: goto x86_l_1a8e;
	case 6801ULL: goto x86_l_1a91;
	case 6805ULL: goto x86_l_1a95;
	case 6808ULL: goto x86_l_1a98;
	case 6811ULL: goto x86_l_1a9b;
	case 6814ULL: goto x86_l_1a9e;
	case 6816ULL: goto x86_l_1aa0;
	case 6819ULL: goto x86_l_1aa3;
	case 6822ULL: goto x86_l_1aa6;
	case 6825ULL: goto x86_l_1aa9;
	case 6829ULL: goto x86_l_1aad;
	case 6832ULL: goto x86_l_1ab0;
	case 6835ULL: goto x86_l_1ab3;
	case 6837ULL: goto x86_l_1ab5;
	case 6840ULL: goto x86_l_1ab8;
	case 6843ULL: goto x86_l_1abb;
	case 6845ULL: goto x86_l_1abd;
	case 6848ULL: goto x86_l_1ac0;
	case 6850ULL: goto x86_l_1ac2;
	case 6853ULL: goto x86_l_1ac5;
	case 6855ULL: goto x86_l_1ac7;
	case 6858ULL: goto x86_l_1aca;
	case 6860ULL: goto x86_l_1acc;
	case 6863ULL: goto x86_l_1acf;
	case 6865ULL: goto x86_l_1ad1;
	case 6868ULL: goto x86_l_1ad4;
	case 6874ULL: goto x86_l_1ada;
	case 6877ULL: goto x86_l_1add;
	case 6879ULL: goto x86_l_1adf;
	case 6881ULL: goto x86_l_1ae1;
	case 6884ULL: goto x86_l_1ae4;
	case 6886ULL: goto x86_l_1ae6;
	case 6889ULL: goto x86_l_1ae9;
	case 6895ULL: goto x86_l_1aef;
	case 6897ULL: goto x86_l_1af1;
	case 6899ULL: goto x86_l_1af3;
	case 6902ULL: goto x86_l_1af6;
	case 6905ULL: goto x86_l_1af9;
	case 6908ULL: goto x86_l_1afc;
	case 6910ULL: goto x86_l_1afe;
	case 6913ULL: goto x86_l_1b01;
	case 6914ULL: goto x86_l_1b02;
	case 6916ULL: goto x86_l_1b04;
	case 6917ULL: goto x86_l_1b05;
	case 6921ULL: goto x86_l_1b09;
	case 6924ULL: goto x86_l_1b0c;
	case 6927ULL: goto x86_l_1b0f;
	case 6931ULL: goto x86_l_1b13;
	case 6935ULL: goto x86_l_1b17;
	case 6942ULL: goto x86_l_1b1e;
	case 6947ULL: goto x86_l_1b23;
	case 6952ULL: goto x86_l_1b28;
	case 6954ULL: goto x86_l_1b2a;
	case 6957ULL: goto x86_l_1b2d;
	case 6959ULL: goto x86_l_1b2f;
	case 6962ULL: goto x86_l_1b32;
	case 6966ULL: goto x86_l_1b36;
	case 6971ULL: goto x86_l_1b3b;
	case 6976ULL: goto x86_l_1b40;
	case 6981ULL: goto x86_l_1b45;
	case 6983ULL: goto x86_l_1b47;
	case 6986ULL: goto x86_l_1b4a;
	case 6988ULL: goto x86_l_1b4c;
	case 6991ULL: goto x86_l_1b4f;
	case 6993ULL: goto x86_l_1b51;
	case 6998ULL: goto x86_l_1b56;
	case 7001ULL: goto x86_l_1b59;
	case 7003ULL: goto x86_l_1b5b;
	case 7006ULL: goto x86_l_1b5e;
	case 7009ULL: goto x86_l_1b61;
	case 7011ULL: goto x86_l_1b63;
	case 7013ULL: goto x86_l_1b65;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1626:
	/* 0x1626: je     1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1718;
	}
x86_l_162c:
	/* 0x162c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_162f:
	/* 0x162f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1631:
	/* 0x1631: jmp    163e <filter_char_substring+0x124> */
	goto x86_l_163e;
x86_l_1633:
	/* 0x1633: inc    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1636:
	/* 0x1636: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1639:
	/* 0x1639: cmp    rcx,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_163c:
	/* 0x163c: je     166f <filter_char_substring+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_166f;
	}
x86_l_163e:
	/* 0x163e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1640:
	/* 0x1640: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1644:
	/* 0x1644: cmp    rdi,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_1647:
	/* 0x1647: jae    1633 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1633;
	}
x86_l_1649:
	/* 0x1649: movzx  edi,BYTE PTR [rax+rsi*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RSI, 0, X86_WIDTH_8), 0ULL);
x86_l_164d:
	/* 0x164d: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_1650:
	/* 0x1650: je     1667 <filter_char_substring+0x14d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1667;
	}
x86_l_1652:
	/* 0x1652: cmp    rsi,0x62 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 98ULL);
x86_l_1656:
	/* 0x1656: ja     1633 <filter_char_substring+0x119> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1633;
	}
x86_l_1658:
	/* 0x1658: lea    r8,[rsi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_165c:
	/* 0x165c: cmp    BYTE PTR [rdx+rsi*1],dil */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDX, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_1660:
	/* 0x1660: mov    rsi,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_64);
x86_l_1663:
	/* 0x1663: je     1640 <filter_char_substring+0x126> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1640;
	}
x86_l_1665:
	/* 0x1665: jmp    1633 <filter_char_substring+0x119> */
	goto x86_l_1633;
x86_l_1667:
	/* 0x1667: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1669:
	/* 0x1669: jns    1729 <filter_char_substring+0x20f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NS)) {
		goto x86_l_1729;
	}
x86_l_166f:
	/* 0x166f: lea    eax,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1674:
	/* 0x1674: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_1678:
	/* 0x1678: jae    1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1718;
	}
x86_l_167e:
	/* 0x167e: add    r12d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 4ULL);
x86_l_1682:
	/* 0x1682: inc    rbx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_1685:
	/* 0x1685: cmp    rbx,0x64 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 100ULL);
x86_l_1689:
	/* 0x1689: jne    1609 <filter_char_substring+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 5641ULL;
	}
x86_l_168f:
	/* 0x168f: jmp    1718 <filter_char_substring+0x1fe> */
	goto x86_l_1718;
x86_l_1694:
	/* 0x1694: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_1699:
	/* 0x1699: mov    r15,QWORD PTR [rip+0x2663] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_16a0:
	/* 0x16a0: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16a5:
	/* 0x16a5: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_16a9:
	/* 0x16a9: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16ad:
	/* 0x16ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16b2:
	/* 0x16b2: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16b5:
	/* 0x16b5: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_16b8:
	/* 0x16b8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ba:
	/* 0x16ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16bd:
	/* 0x16bd: je     1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1718;
	}
x86_l_16bf:
	/* 0x16bf: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_16c3:
	/* 0x16c3: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_16c6:
	/* 0x16c6: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_16ca:
	/* 0x16ca: jae    1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1718;
	}
x86_l_16cc:
	/* 0x16cc: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_16d3:
	/* 0x16d3: jne    16a5 <filter_char_substring+0x18b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16a5;
	}
x86_l_16d5:
	/* 0x16d5: jmp    1718 <filter_char_substring+0x1fe> */
	goto x86_l_1718;
x86_l_16d7:
	/* 0x16d7: mov    ebx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 16ULL);
x86_l_16dc:
	/* 0x16dc: mov    r15,QWORD PTR [rip+0x2665] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&substring_map)));
x86_l_16e3:
	/* 0x16e3: lea    r12,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16e8:
	/* 0x16e8: mov    eax,DWORD PTR [r14+rbx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBX, 0), 0ULL);
x86_l_16ec:
	/* 0x16ec: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_16f0:
	/* 0x16f0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16f5:
	/* 0x16f5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_16f8:
	/* 0x16f8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_16fb:
	/* 0x16fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fd:
	/* 0x16fd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1700:
	/* 0x1700: je     1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1718;
	}
x86_l_1702:
	/* 0x1702: add    rbx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1706:
	/* 0x1706: lea    eax,[rbx-0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551608ULL);
x86_l_1709:
	/* 0x1709: cmp    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_170d:
	/* 0x170d: jae    1718 <filter_char_substring+0x1fe> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1718;
	}
x86_l_170f:
	/* 0x170f: cmp    rbx,0x1a0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 416ULL);
x86_l_1716:
	/* 0x1716: jne    16e8 <filter_char_substring+0x1ce> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_16e8;
	}
x86_l_1718:
	/* 0x1718: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171a:
	/* 0x171a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_171e:
	/* 0x171e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_171f:
	/* 0x171f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1721:
	/* 0x1721: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1723:
	/* 0x1723: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1725:
	/* 0x1725: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1727:
	/* 0x1727: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1728:
	/* 0x1728: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1729:
	/* 0x1729: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_172e:
	/* 0x172e: jmp    171a <filter_char_substring+0x200> */
	goto x86_l_171a;
x86_l_1730:
	/* 0x1730: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1733:
	/* 0x1733: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1738:
	/* 0x1738: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_173c:
	/* 0x173c: ja     17af <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_17af;
	}
x86_l_173e:
	/* 0x173e: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1748:
	/* 0x1748: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_174c:
	/* 0x174c: jae    174f <filter_16ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_174f;
	}
x86_l_174e:
	/* 0x174e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_174f:
	/* 0x174f: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1754:
	/* 0x1754: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1758:
	/* 0x1758: jae    176f <filter_16ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_176f;
	}
x86_l_175a:
	/* 0x175a: movzx  edx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_175d:
	/* 0x175d: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1760:
	/* 0x1760: jne    1885 <filter_16ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1885;
	}
x86_l_1766:
	/* 0x1766: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1768:
	/* 0x1768: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_176b:
	/* 0x176b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_176e:
	/* 0x176e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_176f:
	/* 0x176f: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1773:
	/* 0x1773: jne    17af <filter_16ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_17af;
	}
x86_l_1775:
	/* 0x1775: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1778:
	/* 0x1778: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_177b:
	/* 0x177b: jne    174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_174e;
	}
x86_l_177d:
	/* 0x177d: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1780:
	/* 0x1780: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1783:
	/* 0x1783: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1789:
	/* 0x1789: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_178c:
	/* 0x178c: jne    174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_174e;
	}
x86_l_178e:
	/* 0x178e: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1791:
	/* 0x1791: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1797:
	/* 0x1797: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_179a:
	/* 0x179a: jne    174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_174e;
	}
x86_l_179c:
	/* 0x179c: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_179f:
	/* 0x179f: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_17a5:
	/* 0x17a5: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_17a8:
	/* 0x17a8: jne    174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_174e;
	}
x86_l_17aa:
	/* 0x17aa: jmp    1947 <filter_16ty_selector_val+0x217> */
	goto x86_l_1947;
x86_l_17af:
	/* 0x17af: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17b2:
	/* 0x17b2: je     1821 <filter_16ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1821;
	}
x86_l_17b4:
	/* 0x17b4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17b7:
	/* 0x17b7: jne    1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1947;
	}
x86_l_17bd:
	/* 0x17bd: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17c0:
	/* 0x17c0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_17c3:
	/* 0x17c3: ja     190e <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_190e;
	}
x86_l_17c9:
	/* 0x17c9: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_17ce:
	/* 0x17ce: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_17d1:
	/* 0x17d1: jae    190e <filter_16ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_190e;
	}
x86_l_17d7:
	/* 0x17d7: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17da:
	/* 0x17da: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17dd:
	/* 0x17dd: jg     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_174e;
	}
x86_l_17e3:
	/* 0x17e3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e6:
	/* 0x17e6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_17e9:
	/* 0x17e9: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_17ef:
	/* 0x17ef: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_17f2:
	/* 0x17f2: jg     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_174e;
	}
x86_l_17f8:
	/* 0x17f8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_17fb:
	/* 0x17fb: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1801:
	/* 0x1801: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1804:
	/* 0x1804: jg     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_174e;
	}
x86_l_180a:
	/* 0x180a: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_180d:
	/* 0x180d: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1813:
	/* 0x1813: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1816:
	/* 0x1816: jg     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_174e;
	}
x86_l_181c:
	/* 0x181c: jmp    1947 <filter_16ty_selector_val+0x217> */
	goto x86_l_1947;
x86_l_1821:
	/* 0x1821: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1824:
	/* 0x1824: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1827:
	/* 0x1827: ja     18d3 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_18d3;
	}
x86_l_182d:
	/* 0x182d: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1832:
	/* 0x1832: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1835:
	/* 0x1835: jae    18d3 <filter_16ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_18d3;
	}
x86_l_183b:
	/* 0x183b: movsx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_183e:
	/* 0x183e: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1841:
	/* 0x1841: jl     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_174e;
	}
x86_l_1847:
	/* 0x1847: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_184a:
	/* 0x184a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_184d:
	/* 0x184d: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1853:
	/* 0x1853: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1856:
	/* 0x1856: jl     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_174e;
	}
x86_l_185c:
	/* 0x185c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_185f:
	/* 0x185f: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1865:
	/* 0x1865: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1868:
	/* 0x1868: jl     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_174e;
	}
x86_l_186e:
	/* 0x186e: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1871:
	/* 0x1871: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1877:
	/* 0x1877: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_187a:
	/* 0x187a: jl     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_174e;
	}
x86_l_1880:
	/* 0x1880: jmp    1947 <filter_16ty_selector_val+0x217> */
	goto x86_l_1947;
x86_l_1885:
	/* 0x1885: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1888:
	/* 0x1888: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_188b:
	/* 0x188b: jb     18b2 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18b2;
	}
x86_l_188d:
	/* 0x188d: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1890:
	/* 0x1890: je     1766 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1766;
	}
x86_l_1896:
	/* 0x1896: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1899:
	/* 0x1899: jb     18b2 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18b2;
	}
x86_l_189b:
	/* 0x189b: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_189e:
	/* 0x189e: je     1766 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1766;
	}
x86_l_18a4:
	/* 0x18a4: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_18a7:
	/* 0x18a7: jb     18b2 <filter_16ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_18b2;
	}
x86_l_18a9:
	/* 0x18a9: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_18ac:
	/* 0x18ac: je     1766 <filter_16ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1766;
	}
x86_l_18b2:
	/* 0x18b2: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_18b5:
	/* 0x18b5: ja     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1947;
	}
x86_l_18bb:
	/* 0x18bb: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_18bd:
	/* 0x18bd: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_18c7:
	/* 0x18c7: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_18cb:
	/* 0x18cb: jb     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_174e;
	}
x86_l_18d1:
	/* 0x18d1: jmp    1947 <filter_16ty_selector_val+0x217> */
	goto x86_l_1947;
x86_l_18d3:
	/* 0x18d3: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18d6:
	/* 0x18d6: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18d9:
	/* 0x18d9: jb     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_174e;
	}
x86_l_18df:
	/* 0x18df: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e2:
	/* 0x18e2: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_18e5:
	/* 0x18e5: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_18e7:
	/* 0x18e7: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18ea:
	/* 0x18ea: jb     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_174e;
	}
x86_l_18f0:
	/* 0x18f0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_18f3:
	/* 0x18f3: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_18f5:
	/* 0x18f5: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18f8:
	/* 0x18f8: jb     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_174e;
	}
x86_l_18fe:
	/* 0x18fe: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1901:
	/* 0x1901: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1903:
	/* 0x1903: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1906:
	/* 0x1906: jb     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_174e;
	}
x86_l_190c:
	/* 0x190c: jmp    1947 <filter_16ty_selector_val+0x217> */
	goto x86_l_1947;
x86_l_190e:
	/* 0x190e: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1911:
	/* 0x1911: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1914:
	/* 0x1914: ja     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_174e;
	}
x86_l_191a:
	/* 0x191a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191d:
	/* 0x191d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1920:
	/* 0x1920: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1922:
	/* 0x1922: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1925:
	/* 0x1925: ja     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_174e;
	}
x86_l_192b:
	/* 0x192b: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_192e:
	/* 0x192e: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_1930:
	/* 0x1930: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1933:
	/* 0x1933: ja     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_174e;
	}
x86_l_1939:
	/* 0x1939: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_193c:
	/* 0x193c: jb     1947 <filter_16ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1947;
	}
x86_l_193e:
	/* 0x193e: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1941:
	/* 0x1941: ja     174e <filter_16ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_174e;
	}
x86_l_1947:
	/* 0x1947: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1949:
	/* 0x1949: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_194a:
	/* 0x194a: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_194d:
	/* 0x194d: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1950:
	/* 0x1950: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1953:
	/* 0x1953: ja     1a3a <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1a3a;
	}
x86_l_1959:
	/* 0x1959: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_195e:
	/* 0x195e: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1961:
	/* 0x1961: jae    1a3a <filter_16ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a3a;
	}
x86_l_1967:
	/* 0x1967: movsx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_196a:
	/* 0x196a: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_196d:
	/* 0x196d: jne    19d5 <filter_16ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_19d5;
	}
x86_l_196f:
	/* 0x196f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1974:
	/* 0x1974: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1977:
	/* 0x1977: jg     1982 <filter_16ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1982;
	}
x86_l_1979:
	/* 0x1979: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_197c:
	/* 0x197c: jge    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a51;
	}
x86_l_1982:
	/* 0x1982: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1985:
	/* 0x1985: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1988:
	/* 0x1988: jb     1af1 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af1;
	}
x86_l_198e:
	/* 0x198e: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1991:
	/* 0x1991: jg     199c <filter_16ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_199c;
	}
x86_l_1993:
	/* 0x1993: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1996:
	/* 0x1996: jge    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a51;
	}
x86_l_199c:
	/* 0x199c: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_199f:
	/* 0x199f: jb     1af1 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af1;
	}
x86_l_19a5:
	/* 0x19a5: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19a8:
	/* 0x19a8: jg     19b3 <filter_16ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_19b3;
	}
x86_l_19aa:
	/* 0x19aa: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_19ad:
	/* 0x19ad: jge    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a51;
	}
x86_l_19b3:
	/* 0x19b3: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_19b6:
	/* 0x19b6: jb     1af1 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af1;
	}
x86_l_19bc:
	/* 0x19bc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19be:
	/* 0x19be: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19c1:
	/* 0x19c1: jg     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1af3;
	}
x86_l_19c7:
	/* 0x19c7: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_19ca:
	/* 0x19ca: jge    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_1a51;
	}
x86_l_19d0:
	/* 0x19d0: jmp    1af3 <filter_16ty_range+0x1a9> */
	goto x86_l_1af3;
x86_l_19d5:
	/* 0x19d5: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19d8:
	/* 0x19d8: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19db:
	/* 0x19db: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19df:
	/* 0x19df: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19e2:
	/* 0x19e2: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_19e5:
	/* 0x19e5: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_19e8:
	/* 0x19e8: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_19eb:
	/* 0x19eb: jb     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af3;
	}
x86_l_19f1:
	/* 0x19f1: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19f4:
	/* 0x19f4: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_19f8:
	/* 0x19f8: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_19fb:
	/* 0x19fb: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_19ff:
	/* 0x19ff: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a02:
	/* 0x1a02: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a05:
	/* 0x1a05: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a08:
	/* 0x1a08: jb     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af3;
	}
x86_l_1a0e:
	/* 0x1a0e: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a11:
	/* 0x1a11: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1a15:
	/* 0x1a15: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a18:
	/* 0x1a18: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_1a1c:
	/* 0x1a1c: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a1f:
	/* 0x1a1f: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a22:
	/* 0x1a22: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1a25:
	/* 0x1a25: jb     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af3;
	}
x86_l_1a2b:
	/* 0x1a2b: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a2e:
	/* 0x1a2e: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1a31:
	/* 0x1a31: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1a34:
	/* 0x1a34: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_1a38:
	/* 0x1a38: jmp    1aad <filter_16ty_range+0x163> */
	goto x86_l_1aad;
x86_l_1a3a:
	/* 0x1a3a: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a3d:
	/* 0x1a3d: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1a40:
	/* 0x1a40: jne    1a52 <filter_16ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1a52;
	}
x86_l_1a42:
	/* 0x1a42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a47:
	/* 0x1a47: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a4a:
	/* 0x1a4a: ja     1ab5 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ab5;
	}
x86_l_1a4c:
	/* 0x1a4c: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a4f:
	/* 0x1a4f: jb     1ab5 <filter_16ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ab5;
	}
x86_l_1a51:
	/* 0x1a51: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1a52:
	/* 0x1a52: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a55:
	/* 0x1a55: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a58:
	/* 0x1a58: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a5c:
	/* 0x1a5c: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1a5f:
	/* 0x1a5f: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_1a62:
	/* 0x1a62: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a65:
	/* 0x1a65: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1a68:
	/* 0x1a68: jb     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af3;
	}
x86_l_1a6e:
	/* 0x1a6e: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a71:
	/* 0x1a71: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a75:
	/* 0x1a75: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a78:
	/* 0x1a78: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a7c:
	/* 0x1a7c: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a7f:
	/* 0x1a7f: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a82:
	/* 0x1a82: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a85:
	/* 0x1a85: jb     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af3;
	}
x86_l_1a87:
	/* 0x1a87: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a8a:
	/* 0x1a8a: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1a8e:
	/* 0x1a8e: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a91:
	/* 0x1a91: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_1a95:
	/* 0x1a95: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1a98:
	/* 0x1a98: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1a9b:
	/* 0x1a9b: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1a9e:
	/* 0x1a9e: jb     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af3;
	}
x86_l_1aa0:
	/* 0x1aa0: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aa3:
	/* 0x1aa3: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1aa6:
	/* 0x1aa6: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1aa9:
	/* 0x1aa9: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_1aad:
	/* 0x1aad: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ab0:
	/* 0x1ab0: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ab3:
	/* 0x1ab3: jmp    1af3 <filter_16ty_range+0x1a9> */
	goto x86_l_1af3;
x86_l_1ab5:
	/* 0x1ab5: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ab8:
	/* 0x1ab8: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1abb:
	/* 0x1abb: jb     1af1 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af1;
	}
x86_l_1abd:
	/* 0x1abd: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ac0:
	/* 0x1ac0: ja     1ac7 <filter_16ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ac7;
	}
x86_l_1ac2:
	/* 0x1ac2: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1ac5:
	/* 0x1ac5: jae    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a51;
	}
x86_l_1ac7:
	/* 0x1ac7: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1aca:
	/* 0x1aca: jb     1af1 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af1;
	}
x86_l_1acc:
	/* 0x1acc: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1acf:
	/* 0x1acf: ja     1ada <filter_16ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ada;
	}
x86_l_1ad1:
	/* 0x1ad1: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ad4:
	/* 0x1ad4: jae    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a51;
	}
x86_l_1ada:
	/* 0x1ada: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1add:
	/* 0x1add: jb     1af1 <filter_16ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1af1;
	}
x86_l_1adf:
	/* 0x1adf: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae1:
	/* 0x1ae1: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ae4:
	/* 0x1ae4: ja     1af3 <filter_16ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1af3;
	}
x86_l_1ae6:
	/* 0x1ae6: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ae9:
	/* 0x1ae9: jae    1a51 <filter_16ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1a51;
	}
x86_l_1aef:
	/* 0x1aef: jmp    1af3 <filter_16ty_range+0x1a9> */
	goto x86_l_1af3;
x86_l_1af1:
	/* 0x1af1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1af3:
	/* 0x1af3: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1af6:
	/* 0x1af6: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1af9:
	/* 0x1af9: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1afc:
	/* 0x1afc: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1afe:
	/* 0x1afe: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b01:
	/* 0x1b01: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b02:
	/* 0x1b02: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1b04:
	/* 0x1b04: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1b05:
	/* 0x1b05: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1b09:
	/* 0x1b09: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1b0c:
	/* 0x1b0c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1b0f:
	/* 0x1b0f: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1b13:
	/* 0x1b13: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b17:
	/* 0x1b17: mov    rdi,QWORD PTR [rip+0x13d0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1b1e:
	/* 0x1b1e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b23:
	/* 0x1b23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b28:
	/* 0x1b28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2a:
	/* 0x1b2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b2d:
	/* 0x1b2d: je     1b63 <filter_16ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1b63;
	}
x86_l_1b2f:
	/* 0x1b2f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1b32:
	/* 0x1b32: movzx  eax,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b36:
	/* 0x1b36: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3b:
	/* 0x1b3b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b40:
	/* 0x1b40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b45:
	/* 0x1b45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b47:
	/* 0x1b47: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b4a:
	/* 0x1b4a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b4c:
	/* 0x1b4c: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1b4f:
	/* 0x1b4f: ja     1b7d <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 7037ULL;
	}
x86_l_1b51:
	/* 0x1b51: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1b56:
	/* 0x1b56: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b59:
	/* 0x1b59: jae    1b6d <filter_16ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 7021ULL;
	}
x86_l_1b5b:
	/* 0x1b5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5e:
	/* 0x1b5e: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1b61:
	/* 0x1b61: jmp    1b7d <filter_16ty_map+0x7b> */
	return 7037ULL;
x86_l_1b63:
	/* 0x1b63: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b65:
	/* 0x1b65: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
	return 7017ULL;
}

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_5(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 7017ULL: goto x86_l_1b69;
	case 7018ULL: goto x86_l_1b6a;
	case 7020ULL: goto x86_l_1b6c;
	case 7021ULL: goto x86_l_1b6d;
	case 7026ULL: goto x86_l_1b72;
	case 7029ULL: goto x86_l_1b75;
	case 7031ULL: goto x86_l_1b77;
	case 7034ULL: goto x86_l_1b7a;
	case 7037ULL: goto x86_l_1b7d;
	case 7040ULL: goto x86_l_1b80;
	case 7044ULL: goto x86_l_1b84;
	case 7045ULL: goto x86_l_1b85;
	case 7047ULL: goto x86_l_1b87;
	case 7048ULL: goto x86_l_1b88;
	case 7051ULL: goto x86_l_1b8b;
	case 7056ULL: goto x86_l_1b90;
	case 7060ULL: goto x86_l_1b94;
	case 7062ULL: goto x86_l_1b96;
	case 7072ULL: goto x86_l_1ba0;
	case 7076ULL: goto x86_l_1ba4;
	case 7078ULL: goto x86_l_1ba6;
	case 7079ULL: goto x86_l_1ba7;
	case 7084ULL: goto x86_l_1bac;
	case 7088ULL: goto x86_l_1bb0;
	case 7090ULL: goto x86_l_1bb2;
	case 7092ULL: goto x86_l_1bb4;
	case 7095ULL: goto x86_l_1bb7;
	case 7101ULL: goto x86_l_1bbd;
	case 7103ULL: goto x86_l_1bbf;
	case 7106ULL: goto x86_l_1bc2;
	case 7109ULL: goto x86_l_1bc5;
	case 7110ULL: goto x86_l_1bc6;
	case 7114ULL: goto x86_l_1bca;
	case 7116ULL: goto x86_l_1bcc;
	case 7118ULL: goto x86_l_1bce;
	case 7121ULL: goto x86_l_1bd1;
	case 7123ULL: goto x86_l_1bd3;
	case 7126ULL: goto x86_l_1bd6;
	case 7129ULL: goto x86_l_1bd9;
	case 7135ULL: goto x86_l_1bdf;
	case 7138ULL: goto x86_l_1be2;
	case 7140ULL: goto x86_l_1be4;
	case 7143ULL: goto x86_l_1be7;
	case 7149ULL: goto x86_l_1bed;
	case 7152ULL: goto x86_l_1bf0;
	case 7154ULL: goto x86_l_1bf2;
	case 7157ULL: goto x86_l_1bf5;
	case 7163ULL: goto x86_l_1bfb;
	case 7166ULL: goto x86_l_1bfe;
	case 7168ULL: goto x86_l_1c00;
	case 7173ULL: goto x86_l_1c05;
	case 7176ULL: goto x86_l_1c08;
	case 7178ULL: goto x86_l_1c0a;
	case 7181ULL: goto x86_l_1c0d;
	case 7187ULL: goto x86_l_1c13;
	case 7190ULL: goto x86_l_1c16;
	case 7193ULL: goto x86_l_1c19;
	case 7199ULL: goto x86_l_1c1f;
	case 7204ULL: goto x86_l_1c24;
	case 7207ULL: goto x86_l_1c27;
	case 7213ULL: goto x86_l_1c2d;
	case 7215ULL: goto x86_l_1c2f;
	case 7218ULL: goto x86_l_1c32;
	case 7224ULL: goto x86_l_1c38;
	case 7227ULL: goto x86_l_1c3b;
	case 7230ULL: goto x86_l_1c3e;
	case 7236ULL: goto x86_l_1c44;
	case 7239ULL: goto x86_l_1c47;
	case 7245ULL: goto x86_l_1c4d;
	case 7248ULL: goto x86_l_1c50;
	case 7254ULL: goto x86_l_1c56;
	case 7257ULL: goto x86_l_1c59;
	case 7263ULL: goto x86_l_1c5f;
	case 7266ULL: goto x86_l_1c62;
	case 7272ULL: goto x86_l_1c68;
	case 7275ULL: goto x86_l_1c6b;
	case 7281ULL: goto x86_l_1c71;
	case 7286ULL: goto x86_l_1c76;
	case 7289ULL: goto x86_l_1c79;
	case 7292ULL: goto x86_l_1c7c;
	case 7298ULL: goto x86_l_1c82;
	case 7303ULL: goto x86_l_1c87;
	case 7306ULL: goto x86_l_1c8a;
	case 7312ULL: goto x86_l_1c90;
	case 7314ULL: goto x86_l_1c92;
	case 7317ULL: goto x86_l_1c95;
	case 7323ULL: goto x86_l_1c9b;
	case 7326ULL: goto x86_l_1c9e;
	case 7329ULL: goto x86_l_1ca1;
	case 7335ULL: goto x86_l_1ca7;
	case 7338ULL: goto x86_l_1caa;
	case 7344ULL: goto x86_l_1cb0;
	case 7347ULL: goto x86_l_1cb3;
	case 7353ULL: goto x86_l_1cb9;
	case 7356ULL: goto x86_l_1cbc;
	case 7362ULL: goto x86_l_1cc2;
	case 7365ULL: goto x86_l_1cc5;
	case 7371ULL: goto x86_l_1ccb;
	case 7374ULL: goto x86_l_1cce;
	case 7380ULL: goto x86_l_1cd4;
	case 7385ULL: goto x86_l_1cd9;
	case 7388ULL: goto x86_l_1cdc;
	case 7391ULL: goto x86_l_1cdf;
	case 7393ULL: goto x86_l_1ce1;
	case 7396ULL: goto x86_l_1ce4;
	case 7402ULL: goto x86_l_1cea;
	case 7405ULL: goto x86_l_1ced;
	case 7407ULL: goto x86_l_1cef;
	case 7410ULL: goto x86_l_1cf2;
	case 7416ULL: goto x86_l_1cf8;
	case 7419ULL: goto x86_l_1cfb;
	case 7421ULL: goto x86_l_1cfd;
	case 7424ULL: goto x86_l_1d00;
	case 7430ULL: goto x86_l_1d06;
	case 7433ULL: goto x86_l_1d09;
	case 7439ULL: goto x86_l_1d0f;
	case 7441ULL: goto x86_l_1d11;
	case 7451ULL: goto x86_l_1d1b;
	case 7455ULL: goto x86_l_1d1f;
	case 7461ULL: goto x86_l_1d25;
	case 7463ULL: goto x86_l_1d27;
	case 7465ULL: goto x86_l_1d29;
	case 7468ULL: goto x86_l_1d2c;
	case 7474ULL: goto x86_l_1d32;
	case 7477ULL: goto x86_l_1d35;
	case 7480ULL: goto x86_l_1d38;
	case 7482ULL: goto x86_l_1d3a;
	case 7485ULL: goto x86_l_1d3d;
	case 7491ULL: goto x86_l_1d43;
	case 7494ULL: goto x86_l_1d46;
	case 7496ULL: goto x86_l_1d48;
	case 7499ULL: goto x86_l_1d4b;
	case 7505ULL: goto x86_l_1d51;
	case 7508ULL: goto x86_l_1d54;
	case 7510ULL: goto x86_l_1d56;
	case 7513ULL: goto x86_l_1d59;
	case 7519ULL: goto x86_l_1d5f;
	case 7521ULL: goto x86_l_1d61;
	case 7523ULL: goto x86_l_1d63;
	case 7526ULL: goto x86_l_1d66;
	case 7532ULL: goto x86_l_1d6c;
	case 7535ULL: goto x86_l_1d6f;
	case 7538ULL: goto x86_l_1d72;
	case 7540ULL: goto x86_l_1d74;
	case 7543ULL: goto x86_l_1d77;
	case 7549ULL: goto x86_l_1d7d;
	case 7552ULL: goto x86_l_1d80;
	case 7554ULL: goto x86_l_1d82;
	case 7557ULL: goto x86_l_1d85;
	case 7563ULL: goto x86_l_1d8b;
	case 7566ULL: goto x86_l_1d8e;
	case 7568ULL: goto x86_l_1d90;
	case 7571ULL: goto x86_l_1d93;
	case 7577ULL: goto x86_l_1d99;
	case 7579ULL: goto x86_l_1d9b;
	case 7580ULL: goto x86_l_1d9c;
	case 7583ULL: goto x86_l_1d9f;
	case 7586ULL: goto x86_l_1da2;
	case 7589ULL: goto x86_l_1da5;
	case 7595ULL: goto x86_l_1dab;
	case 7600ULL: goto x86_l_1db0;
	case 7603ULL: goto x86_l_1db3;
	case 7609ULL: goto x86_l_1db9;
	case 7611ULL: goto x86_l_1dbb;
	case 7614ULL: goto x86_l_1dbe;
	case 7616ULL: goto x86_l_1dc0;
	case 7621ULL: goto x86_l_1dc5;
	case 7624ULL: goto x86_l_1dc8;
	case 7626ULL: goto x86_l_1dca;
	case 7629ULL: goto x86_l_1dcd;
	case 7635ULL: goto x86_l_1dd3;
	case 7638ULL: goto x86_l_1dd6;
	case 7641ULL: goto x86_l_1dd9;
	case 7647ULL: goto x86_l_1ddf;
	case 7650ULL: goto x86_l_1de2;
	case 7652ULL: goto x86_l_1de4;
	case 7655ULL: goto x86_l_1de7;
	case 7661ULL: goto x86_l_1ded;
	case 7664ULL: goto x86_l_1df0;
	case 7670ULL: goto x86_l_1df6;
	case 7673ULL: goto x86_l_1df9;
	case 7675ULL: goto x86_l_1dfb;
	case 7678ULL: goto x86_l_1dfe;
	case 7684ULL: goto x86_l_1e04;
	case 7687ULL: goto x86_l_1e07;
	case 7693ULL: goto x86_l_1e0d;
	case 7695ULL: goto x86_l_1e0f;
	case 7698ULL: goto x86_l_1e12;
	case 7704ULL: goto x86_l_1e18;
	case 7707ULL: goto x86_l_1e1b;
	case 7713ULL: goto x86_l_1e21;
	case 7718ULL: goto x86_l_1e26;
	case 7721ULL: goto x86_l_1e29;
	case 7724ULL: goto x86_l_1e2c;
	case 7728ULL: goto x86_l_1e30;
	case 7731ULL: goto x86_l_1e33;
	case 7734ULL: goto x86_l_1e36;
	case 7737ULL: goto x86_l_1e39;
	case 7740ULL: goto x86_l_1e3c;
	case 7746ULL: goto x86_l_1e42;
	case 7749ULL: goto x86_l_1e45;
	case 7753ULL: goto x86_l_1e49;
	case 7756ULL: goto x86_l_1e4c;
	case 7760ULL: goto x86_l_1e50;
	case 7763ULL: goto x86_l_1e53;
	case 7766ULL: goto x86_l_1e56;
	case 7769ULL: goto x86_l_1e59;
	case 7775ULL: goto x86_l_1e5f;
	case 7778ULL: goto x86_l_1e62;
	case 7782ULL: goto x86_l_1e66;
	case 7785ULL: goto x86_l_1e69;
	case 7789ULL: goto x86_l_1e6d;
	case 7792ULL: goto x86_l_1e70;
	case 7795ULL: goto x86_l_1e73;
	case 7798ULL: goto x86_l_1e76;
	case 7804ULL: goto x86_l_1e7c;
	case 7807ULL: goto x86_l_1e7f;
	case 7810ULL: goto x86_l_1e82;
	case 7813ULL: goto x86_l_1e85;
	case 7817ULL: goto x86_l_1e89;
	case 7819ULL: goto x86_l_1e8b;
	case 7821ULL: goto x86_l_1e8d;
	case 7824ULL: goto x86_l_1e90;
	case 7826ULL: goto x86_l_1e92;
	case 7831ULL: goto x86_l_1e97;
	case 7834ULL: goto x86_l_1e9a;
	case 7836ULL: goto x86_l_1e9c;
	case 7839ULL: goto x86_l_1e9f;
	case 7841ULL: goto x86_l_1ea1;
	case 7842ULL: goto x86_l_1ea2;
	case 7845ULL: goto x86_l_1ea5;
	case 7848ULL: goto x86_l_1ea8;
	case 7852ULL: goto x86_l_1eac;
	case 7855ULL: goto x86_l_1eaf;
	case 7858ULL: goto x86_l_1eb2;
	case 7861ULL: goto x86_l_1eb5;
	case 7864ULL: goto x86_l_1eb8;
	case 7870ULL: goto x86_l_1ebe;
	case 7873ULL: goto x86_l_1ec1;
	case 7877ULL: goto x86_l_1ec5;
	case 7880ULL: goto x86_l_1ec8;
	case 7884ULL: goto x86_l_1ecc;
	case 7887ULL: goto x86_l_1ecf;
	case 7890ULL: goto x86_l_1ed2;
	case 7893ULL: goto x86_l_1ed5;
	case 7895ULL: goto x86_l_1ed7;
	case 7898ULL: goto x86_l_1eda;
	case 7902ULL: goto x86_l_1ede;
	case 7905ULL: goto x86_l_1ee1;
	case 7909ULL: goto x86_l_1ee5;
	case 7912ULL: goto x86_l_1ee8;
	case 7915ULL: goto x86_l_1eeb;
	case 7918ULL: goto x86_l_1eee;
	case 7920ULL: goto x86_l_1ef0;
	case 7923ULL: goto x86_l_1ef3;
	case 7926ULL: goto x86_l_1ef6;
	case 7929ULL: goto x86_l_1ef9;
	case 7933ULL: goto x86_l_1efd;
	case 7936ULL: goto x86_l_1f00;
	case 7939ULL: goto x86_l_1f03;
	case 7941ULL: goto x86_l_1f05;
	case 7944ULL: goto x86_l_1f08;
	case 7947ULL: goto x86_l_1f0b;
	case 7949ULL: goto x86_l_1f0d;
	case 7952ULL: goto x86_l_1f10;
	case 7954ULL: goto x86_l_1f12;
	case 7957ULL: goto x86_l_1f15;
	case 7959ULL: goto x86_l_1f17;
	case 7962ULL: goto x86_l_1f1a;
	case 7964ULL: goto x86_l_1f1c;
	case 7967ULL: goto x86_l_1f1f;
	case 7969ULL: goto x86_l_1f21;
	case 7972ULL: goto x86_l_1f24;
	case 7978ULL: goto x86_l_1f2a;
	case 7981ULL: goto x86_l_1f2d;
	case 7983ULL: goto x86_l_1f2f;
	case 7985ULL: goto x86_l_1f31;
	case 7988ULL: goto x86_l_1f34;
	case 7990ULL: goto x86_l_1f36;
	case 7993ULL: goto x86_l_1f39;
	case 7999ULL: goto x86_l_1f3f;
	case 8001ULL: goto x86_l_1f41;
	case 8003ULL: goto x86_l_1f43;
	case 8006ULL: goto x86_l_1f46;
	case 8009ULL: goto x86_l_1f49;
	case 8012ULL: goto x86_l_1f4c;
	case 8014ULL: goto x86_l_1f4e;
	case 8017ULL: goto x86_l_1f51;
	case 8018ULL: goto x86_l_1f52;
	case 8020ULL: goto x86_l_1f54;
	case 8021ULL: goto x86_l_1f55;
	case 8025ULL: goto x86_l_1f59;
	case 8028ULL: goto x86_l_1f5c;
	case 8031ULL: goto x86_l_1f5f;
	case 8035ULL: goto x86_l_1f63;
	case 8039ULL: goto x86_l_1f67;
	case 8046ULL: goto x86_l_1f6e;
	case 8051ULL: goto x86_l_1f73;
	case 8056ULL: goto x86_l_1f78;
	case 8058ULL: goto x86_l_1f7a;
	case 8061ULL: goto x86_l_1f7d;
	case 8063ULL: goto x86_l_1f7f;
	case 8066ULL: goto x86_l_1f82;
	case 8069ULL: goto x86_l_1f85;
	case 8074ULL: goto x86_l_1f8a;
	case 8079ULL: goto x86_l_1f8f;
	case 8084ULL: goto x86_l_1f94;
	case 8086ULL: goto x86_l_1f96;
	case 8089ULL: goto x86_l_1f99;
	case 8091ULL: goto x86_l_1f9b;
	case 8094ULL: goto x86_l_1f9e;
	case 8096ULL: goto x86_l_1fa0;
	case 8101ULL: goto x86_l_1fa5;
	case 8104ULL: goto x86_l_1fa8;
	case 8106ULL: goto x86_l_1faa;
	case 8109ULL: goto x86_l_1fad;
	case 8112ULL: goto x86_l_1fb0;
	case 8114ULL: goto x86_l_1fb2;
	case 8116ULL: goto x86_l_1fb4;
	case 8120ULL: goto x86_l_1fb8;
	case 8121ULL: goto x86_l_1fb9;
	case 8123ULL: goto x86_l_1fbb;
	case 8124ULL: goto x86_l_1fbc;
	case 8129ULL: goto x86_l_1fc1;
	case 8132ULL: goto x86_l_1fc4;
	case 8134ULL: goto x86_l_1fc6;
	case 8137ULL: goto x86_l_1fc9;
	case 8140ULL: goto x86_l_1fcc;
	case 8143ULL: goto x86_l_1fcf;
	case 8147ULL: goto x86_l_1fd3;
	case 8148ULL: goto x86_l_1fd4;
	case 8150ULL: goto x86_l_1fd6;
	case 8151ULL: goto x86_l_1fd7;
	case 8154ULL: goto x86_l_1fda;
	case 8159ULL: goto x86_l_1fdf;
	case 8163ULL: goto x86_l_1fe3;
	case 8165ULL: goto x86_l_1fe5;
	case 8175ULL: goto x86_l_1fef;
	case 8179ULL: goto x86_l_1ff3;
	case 8181ULL: goto x86_l_1ff5;
	case 8182ULL: goto x86_l_1ff6;
	case 8187ULL: goto x86_l_1ffb;
	case 8191ULL: goto x86_l_1fff;
	case 8193ULL: goto x86_l_2001;
	case 8196ULL: goto x86_l_2004;
	case 8199ULL: goto x86_l_2007;
	case 8205ULL: goto x86_l_200d;
	case 8207ULL: goto x86_l_200f;
	case 8210ULL: goto x86_l_2012;
	case 8213ULL: goto x86_l_2015;
	case 8214ULL: goto x86_l_2016;
	case 8218ULL: goto x86_l_201a;
	case 8220ULL: goto x86_l_201c;
	case 8223ULL: goto x86_l_201f;
	case 8226ULL: goto x86_l_2022;
	case 8228ULL: goto x86_l_2024;
	case 8231ULL: goto x86_l_2027;
	case 8234ULL: goto x86_l_202a;
	case 8240ULL: goto x86_l_2030;
	case 8243ULL: goto x86_l_2033;
	case 8245ULL: goto x86_l_2035;
	case 8248ULL: goto x86_l_2038;
	case 8254ULL: goto x86_l_203e;
	case 8257ULL: goto x86_l_2041;
	case 8259ULL: goto x86_l_2043;
	case 8262ULL: goto x86_l_2046;
	case 8268ULL: goto x86_l_204c;
	case 8271ULL: goto x86_l_204f;
	case 8273ULL: goto x86_l_2051;
	case 8278ULL: goto x86_l_2056;
	case 8281ULL: goto x86_l_2059;
	case 8283ULL: goto x86_l_205b;
	case 8286ULL: goto x86_l_205e;
	case 8292ULL: goto x86_l_2064;
	case 8295ULL: goto x86_l_2067;
	case 8298ULL: goto x86_l_206a;
	case 8304ULL: goto x86_l_2070;
	case 8309ULL: goto x86_l_2075;
	case 8312ULL: goto x86_l_2078;
	case 8318ULL: goto x86_l_207e;
	case 8321ULL: goto x86_l_2081;
	case 8324ULL: goto x86_l_2084;
	case 8330ULL: goto x86_l_208a;
	case 8333ULL: goto x86_l_208d;
	default: return 0xffffffffffffffffULL;
	}
x86_l_1b69:
	/* 0x1b69: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b6a:
	/* 0x1b6a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b6c:
	/* 0x1b6c: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b6d:
	/* 0x1b6d: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1b72:
	/* 0x1b72: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1b75:
	/* 0x1b75: jae    1b7d <filter_16ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1b7d;
	}
x86_l_1b77:
	/* 0x1b77: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b7a:
	/* 0x1b7a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1b7d:
	/* 0x1b7d: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b80:
	/* 0x1b80: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1b84:
	/* 0x1b84: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1b85:
	/* 0x1b85: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1b87:
	/* 0x1b87: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1b88:
	/* 0x1b88: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b90:
	/* 0x1b90: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1b94:
	/* 0x1b94: ja     1c05 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1c05;
	}
x86_l_1b96:
	/* 0x1b96: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1ba0:
	/* 0x1ba0: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1ba4:
	/* 0x1ba4: jae    1ba7 <filter_32ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ba7;
	}
x86_l_1ba6:
	/* 0x1ba6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1ba7:
	/* 0x1ba7: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1bac:
	/* 0x1bac: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1bb0:
	/* 0x1bb0: jae    1bc6 <filter_32ty_selector_val+0x3e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1bc6;
	}
x86_l_1bb2:
	/* 0x1bb2: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb4:
	/* 0x1bb4: cmp    edx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1bb7:
	/* 0x1bb7: jne    1cd9 <filter_32ty_selector_val+0x151> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1cd9;
	}
x86_l_1bbd:
	/* 0x1bbd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bbf:
	/* 0x1bbf: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1bc2:
	/* 0x1bc2: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1bc5:
	/* 0x1bc5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1bc6:
	/* 0x1bc6: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_1bca:
	/* 0x1bca: jne    1c05 <filter_32ty_selector_val+0x7d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1c05;
	}
x86_l_1bcc:
	/* 0x1bcc: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bce:
	/* 0x1bce: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bd1:
	/* 0x1bd1: jne    1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ba6;
	}
x86_l_1bd3:
	/* 0x1bd3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd6:
	/* 0x1bd6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1bd9:
	/* 0x1bd9: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1bdf:
	/* 0x1bdf: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1be2:
	/* 0x1be2: jne    1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ba6;
	}
x86_l_1be4:
	/* 0x1be4: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1be7:
	/* 0x1be7: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1bed:
	/* 0x1bed: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bf0:
	/* 0x1bf0: jne    1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ba6;
	}
x86_l_1bf2:
	/* 0x1bf2: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1bf5:
	/* 0x1bf5: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1bfb:
	/* 0x1bfb: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1bfe:
	/* 0x1bfe: jne    1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ba6;
	}
x86_l_1c00:
	/* 0x1c00: jmp    1d99 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d99;
x86_l_1c05:
	/* 0x1c05: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1c08:
	/* 0x1c08: je     1c76 <filter_32ty_selector_val+0xee> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1c76;
	}
x86_l_1c0a:
	/* 0x1c0a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c0d:
	/* 0x1c0d: jne    1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1d99;
	}
x86_l_1c13:
	/* 0x1c13: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c16:
	/* 0x1c16: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c19:
	/* 0x1c19: ja     1d61 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d61;
	}
x86_l_1c1f:
	/* 0x1c1f: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c24:
	/* 0x1c24: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c27:
	/* 0x1c27: jae    1d61 <filter_32ty_selector_val+0x1d9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d61;
	}
x86_l_1c2d:
	/* 0x1c2d: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c2f:
	/* 0x1c2f: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c32:
	/* 0x1c32: jl     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1ba6;
	}
x86_l_1c38:
	/* 0x1c38: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c3b:
	/* 0x1c3b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1c3e:
	/* 0x1c3e: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1c44:
	/* 0x1c44: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1c47:
	/* 0x1c47: jl     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1ba6;
	}
x86_l_1c4d:
	/* 0x1c4d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1c50:
	/* 0x1c50: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1c56:
	/* 0x1c56: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1c59:
	/* 0x1c59: jl     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1ba6;
	}
x86_l_1c5f:
	/* 0x1c5f: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1c62:
	/* 0x1c62: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1c68:
	/* 0x1c68: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1c6b:
	/* 0x1c6b: jl     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		goto x86_l_1ba6;
	}
x86_l_1c71:
	/* 0x1c71: jmp    1d99 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d99;
x86_l_1c76:
	/* 0x1c76: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1c79:
	/* 0x1c79: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1c7c:
	/* 0x1c7c: ja     1d27 <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d27;
	}
x86_l_1c82:
	/* 0x1c82: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1c87:
	/* 0x1c87: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1c8a:
	/* 0x1c8a: jae    1d27 <filter_32ty_selector_val+0x19f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1d27;
	}
x86_l_1c90:
	/* 0x1c90: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c92:
	/* 0x1c92: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1c95:
	/* 0x1c95: jg     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ba6;
	}
x86_l_1c9b:
	/* 0x1c9b: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c9e:
	/* 0x1c9e: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1ca1:
	/* 0x1ca1: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1ca7:
	/* 0x1ca7: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1caa:
	/* 0x1caa: jg     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ba6;
	}
x86_l_1cb0:
	/* 0x1cb0: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1cb3:
	/* 0x1cb3: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1cb9:
	/* 0x1cb9: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1cbc:
	/* 0x1cbc: jg     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ba6;
	}
x86_l_1cc2:
	/* 0x1cc2: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1cc5:
	/* 0x1cc5: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1ccb:
	/* 0x1ccb: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1cce:
	/* 0x1cce: jg     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ba6;
	}
x86_l_1cd4:
	/* 0x1cd4: jmp    1d99 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d99;
x86_l_1cd9:
	/* 0x1cd9: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cdc:
	/* 0x1cdc: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_1cdf:
	/* 0x1cdf: jb     1d06 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d06;
	}
x86_l_1ce1:
	/* 0x1ce1: cmp    edx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1ce4:
	/* 0x1ce4: je     1bbd <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bbd;
	}
x86_l_1cea:
	/* 0x1cea: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1ced:
	/* 0x1ced: jb     1d06 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d06;
	}
x86_l_1cef:
	/* 0x1cef: cmp    edx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1cf2:
	/* 0x1cf2: je     1bbd <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bbd;
	}
x86_l_1cf8:
	/* 0x1cf8: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1cfb:
	/* 0x1cfb: jb     1d06 <filter_32ty_selector_val+0x17e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d06;
	}
x86_l_1cfd:
	/* 0x1cfd: cmp    edx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d00:
	/* 0x1d00: je     1bbd <filter_32ty_selector_val+0x35> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1bbd;
	}
x86_l_1d06:
	/* 0x1d06: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_1d09:
	/* 0x1d09: ja     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1d99;
	}
x86_l_1d0f:
	/* 0x1d0f: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1d11:
	/* 0x1d11: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_1d1b:
	/* 0x1d1b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1d1f:
	/* 0x1d1f: jb     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ba6;
	}
x86_l_1d25:
	/* 0x1d25: jmp    1d99 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d99;
x86_l_1d27:
	/* 0x1d27: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d29:
	/* 0x1d29: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d2c:
	/* 0x1d2c: ja     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ba6;
	}
x86_l_1d32:
	/* 0x1d32: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d35:
	/* 0x1d35: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d38:
	/* 0x1d38: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1d3a:
	/* 0x1d3a: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d3d:
	/* 0x1d3d: ja     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ba6;
	}
x86_l_1d43:
	/* 0x1d43: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d46:
	/* 0x1d46: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1d48:
	/* 0x1d48: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d4b:
	/* 0x1d4b: ja     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ba6;
	}
x86_l_1d51:
	/* 0x1d51: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d54:
	/* 0x1d54: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1d56:
	/* 0x1d56: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d59:
	/* 0x1d59: ja     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1ba6;
	}
x86_l_1d5f:
	/* 0x1d5f: jmp    1d99 <filter_32ty_selector_val+0x211> */
	goto x86_l_1d99;
x86_l_1d61:
	/* 0x1d61: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d63:
	/* 0x1d63: cmp    ecx,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_1d66:
	/* 0x1d66: jb     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ba6;
	}
x86_l_1d6c:
	/* 0x1d6c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d6f:
	/* 0x1d6f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_1d72:
	/* 0x1d72: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1d74:
	/* 0x1d74: cmp    ecx,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1d77:
	/* 0x1d77: jb     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ba6;
	}
x86_l_1d7d:
	/* 0x1d7d: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1d80:
	/* 0x1d80: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1d82:
	/* 0x1d82: cmp    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 24ULL);
x86_l_1d85:
	/* 0x1d85: jb     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ba6;
	}
x86_l_1d8b:
	/* 0x1d8b: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_1d8e:
	/* 0x1d8e: jb     1d99 <filter_32ty_selector_val+0x211> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1d99;
	}
x86_l_1d90:
	/* 0x1d90: cmp    ecx,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1d93:
	/* 0x1d93: jb     1ba6 <filter_32ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1ba6;
	}
x86_l_1d99:
	/* 0x1d99: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d9b:
	/* 0x1d9b: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1d9c:
	/* 0x1d9c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d9f:
	/* 0x1d9f: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1da2:
	/* 0x1da2: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1da5:
	/* 0x1da5: ja     1e8b <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1e8b;
	}
x86_l_1dab:
	/* 0x1dab: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_1db0:
	/* 0x1db0: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_1db3:
	/* 0x1db3: jae    1e8b <filter_32ty_range+0xef> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1e8b;
	}
x86_l_1db9:
	/* 0x1db9: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dbb:
	/* 0x1dbb: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1dbe:
	/* 0x1dbe: jne    1e26 <filter_32ty_range+0x8a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1e26;
	}
x86_l_1dc0:
	/* 0x1dc0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1dc5:
	/* 0x1dc5: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc8:
	/* 0x1dc8: jg     1dd3 <filter_32ty_range+0x37> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1dd3;
	}
x86_l_1dca:
	/* 0x1dca: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1dcd:
	/* 0x1dcd: jle    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ea1;
	}
x86_l_1dd3:
	/* 0x1dd3: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1dd6:
	/* 0x1dd6: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1dd9:
	/* 0x1dd9: jb     1f41 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f41;
	}
x86_l_1ddf:
	/* 0x1ddf: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1de2:
	/* 0x1de2: jg     1ded <filter_32ty_range+0x51> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ded;
	}
x86_l_1de4:
	/* 0x1de4: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1de7:
	/* 0x1de7: jle    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ea1;
	}
x86_l_1ded:
	/* 0x1ded: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1df0:
	/* 0x1df0: jb     1f41 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f41;
	}
x86_l_1df6:
	/* 0x1df6: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1df9:
	/* 0x1df9: jg     1e04 <filter_32ty_range+0x68> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1e04;
	}
x86_l_1dfb:
	/* 0x1dfb: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1dfe:
	/* 0x1dfe: jle    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ea1;
	}
x86_l_1e04:
	/* 0x1e04: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1e07:
	/* 0x1e07: jb     1f41 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f41;
	}
x86_l_1e0d:
	/* 0x1e0d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e0f:
	/* 0x1e0f: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e12:
	/* 0x1e12: jg     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1f43;
	}
x86_l_1e18:
	/* 0x1e18: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e1b:
	/* 0x1e1b: jle    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_LE)) {
		goto x86_l_1ea1;
	}
x86_l_1e21:
	/* 0x1e21: jmp    1f43 <filter_32ty_range+0x1a7> */
	goto x86_l_1f43;
x86_l_1e26:
	/* 0x1e26: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e29:
	/* 0x1e29: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e2c:
	/* 0x1e2c: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e30:
	/* 0x1e30: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e33:
	/* 0x1e33: setle  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_LE);
x86_l_1e36:
	/* 0x1e36: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e39:
	/* 0x1e39: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1e3c:
	/* 0x1e3c: jb     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f43;
	}
x86_l_1e42:
	/* 0x1e42: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e45:
	/* 0x1e45: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e49:
	/* 0x1e49: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1e4c:
	/* 0x1e4c: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e50:
	/* 0x1e50: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e53:
	/* 0x1e53: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e56:
	/* 0x1e56: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e59:
	/* 0x1e59: jb     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f43;
	}
x86_l_1e5f:
	/* 0x1e5f: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e62:
	/* 0x1e62: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_1e66:
	/* 0x1e66: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1e69:
	/* 0x1e69: setle  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_LE);
x86_l_1e6d:
	/* 0x1e6d: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1e70:
	/* 0x1e70: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e73:
	/* 0x1e73: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1e76:
	/* 0x1e76: jb     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f43;
	}
x86_l_1e7c:
	/* 0x1e7c: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e7f:
	/* 0x1e7f: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_1e82:
	/* 0x1e82: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1e85:
	/* 0x1e85: setle  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_LE);
x86_l_1e89:
	/* 0x1e89: jmp    1efd <filter_32ty_range+0x161> */
	goto x86_l_1efd;
x86_l_1e8b:
	/* 0x1e8b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e8d:
	/* 0x1e8d: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_1e90:
	/* 0x1e90: jne    1ea2 <filter_32ty_range+0x106> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ea2;
	}
x86_l_1e92:
	/* 0x1e92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e97:
	/* 0x1e97: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e9a:
	/* 0x1e9a: ja     1f05 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f05;
	}
x86_l_1e9c:
	/* 0x1e9c: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1e9f:
	/* 0x1e9f: ja     1f05 <filter_32ty_range+0x169> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f05;
	}
x86_l_1ea1:
	/* 0x1ea1: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1ea2:
	/* 0x1ea2: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ea5:
	/* 0x1ea5: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ea8:
	/* 0x1ea8: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1eac:
	/* 0x1eac: cmp    esi,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_1eaf:
	/* 0x1eaf: setbe  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_BE);
x86_l_1eb2:
	/* 0x1eb2: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1eb5:
	/* 0x1eb5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1eb8:
	/* 0x1eb8: jb     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f43;
	}
x86_l_1ebe:
	/* 0x1ebe: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ec1:
	/* 0x1ec1: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1ec5:
	/* 0x1ec5: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1ec8:
	/* 0x1ec8: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1ecc:
	/* 0x1ecc: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ecf:
	/* 0x1ecf: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ed2:
	/* 0x1ed2: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1ed5:
	/* 0x1ed5: jb     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f43;
	}
x86_l_1ed7:
	/* 0x1ed7: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1eda:
	/* 0x1eda: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_1ede:
	/* 0x1ede: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1ee1:
	/* 0x1ee1: setbe  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_BE);
x86_l_1ee5:
	/* 0x1ee5: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_1ee8:
	/* 0x1ee8: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_1eeb:
	/* 0x1eeb: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_1eee:
	/* 0x1eee: jb     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f43;
	}
x86_l_1ef0:
	/* 0x1ef0: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ef3:
	/* 0x1ef3: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_1ef6:
	/* 0x1ef6: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1ef9:
	/* 0x1ef9: setbe  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_BE);
x86_l_1efd:
	/* 0x1efd: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f00:
	/* 0x1f00: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f03:
	/* 0x1f03: jmp    1f43 <filter_32ty_range+0x1a7> */
	goto x86_l_1f43;
x86_l_1f05:
	/* 0x1f05: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f08:
	/* 0x1f08: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_1f0b:
	/* 0x1f0b: jb     1f41 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f41;
	}
x86_l_1f0d:
	/* 0x1f0d: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1f10:
	/* 0x1f10: ja     1f17 <filter_32ty_range+0x17b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f17;
	}
x86_l_1f12:
	/* 0x1f12: cmp    esi,DWORD PTR [rdi+0x1c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 28ULL);
x86_l_1f15:
	/* 0x1f15: jbe    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ea1;
	}
x86_l_1f17:
	/* 0x1f17: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_1f1a:
	/* 0x1f1a: jb     1f41 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f41;
	}
x86_l_1f1c:
	/* 0x1f1c: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1f1f:
	/* 0x1f1f: ja     1f2a <filter_32ty_range+0x18e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f2a;
	}
x86_l_1f21:
	/* 0x1f21: cmp    esi,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 36ULL);
x86_l_1f24:
	/* 0x1f24: jbe    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ea1;
	}
x86_l_1f2a:
	/* 0x1f2a: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_1f2d:
	/* 0x1f2d: jb     1f41 <filter_32ty_range+0x1a5> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_1f41;
	}
x86_l_1f2f:
	/* 0x1f2f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f31:
	/* 0x1f31: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1f34:
	/* 0x1f34: ja     1f43 <filter_32ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1f43;
	}
x86_l_1f36:
	/* 0x1f36: cmp    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1f39:
	/* 0x1f39: jbe    1ea1 <filter_32ty_range+0x105> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_1ea1;
	}
x86_l_1f3f:
	/* 0x1f3f: jmp    1f43 <filter_32ty_range+0x1a7> */
	goto x86_l_1f43;
x86_l_1f41:
	/* 0x1f41: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f43:
	/* 0x1f43: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_1f46:
	/* 0x1f46: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1f49:
	/* 0x1f49: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_1f4c:
	/* 0x1f4c: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_1f4e:
	/* 0x1f4e: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1f51:
	/* 0x1f51: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1f52:
	/* 0x1f52: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_1f54:
	/* 0x1f54: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1f55:
	/* 0x1f55: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_1f59:
	/* 0x1f59: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1f5c:
	/* 0x1f5c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_1f5f:
	/* 0x1f5f: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1f63:
	/* 0x1f63: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f67:
	/* 0x1f67: mov    rdi,QWORD PTR [rip+0xf60] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_1f6e:
	/* 0x1f6e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1f73:
	/* 0x1f73: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f78:
	/* 0x1f78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f7a:
	/* 0x1f7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f7d:
	/* 0x1f7d: je     1fb2 <filter_32ty_map+0x60> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_1fb2;
	}
x86_l_1f7f:
	/* 0x1f7f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1f82:
	/* 0x1f82: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f85:
	/* 0x1f85: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8a:
	/* 0x1f8a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f8f:
	/* 0x1f8f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f94:
	/* 0x1f94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f96:
	/* 0x1f96: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f99:
	/* 0x1f99: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f9b:
	/* 0x1f9b: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_1f9e:
	/* 0x1f9e: ja     1fcc <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_1fcc;
	}
x86_l_1fa0:
	/* 0x1fa0: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_1fa5:
	/* 0x1fa5: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fa8:
	/* 0x1fa8: jae    1fbc <filter_32ty_map+0x6a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fbc;
	}
x86_l_1faa:
	/* 0x1faa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fad:
	/* 0x1fad: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_1fb0:
	/* 0x1fb0: jmp    1fcc <filter_32ty_map+0x7a> */
	goto x86_l_1fcc;
x86_l_1fb2:
	/* 0x1fb2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fb4:
	/* 0x1fb4: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1fb8:
	/* 0x1fb8: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1fb9:
	/* 0x1fb9: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1fbb:
	/* 0x1fbb: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fbc:
	/* 0x1fbc: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_1fc1:
	/* 0x1fc1: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_1fc4:
	/* 0x1fc4: jae    1fcc <filter_32ty_map+0x7a> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1fcc;
	}
x86_l_1fc6:
	/* 0x1fc6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fc9:
	/* 0x1fc9: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1fcc:
	/* 0x1fcc: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fcf:
	/* 0x1fcf: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_1fd3:
	/* 0x1fd3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1fd4:
	/* 0x1fd4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1fd6:
	/* 0x1fd6: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1fd7:
	/* 0x1fd7: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1fda:
	/* 0x1fda: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fdf:
	/* 0x1fdf: cmp    rcx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 37ULL);
x86_l_1fe3:
	/* 0x1fe3: ja     2056 <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2056;
	}
x86_l_1fe5:
	/* 0x1fe5: movabs rdx,0x200c000040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280128ULL);
x86_l_1fef:
	/* 0x1fef: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1ff3:
	/* 0x1ff3: jae    1ff6 <filter_8ty_selector_val+0x1f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_1ff6;
	}
x86_l_1ff5:
	/* 0x1ff5: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_1ff6:
	/* 0x1ff6: mov    edx,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 24ULL);
x86_l_1ffb:
	/* 0x1ffb: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1fff:
	/* 0x1fff: jae    2016 <filter_8ty_selector_val+0x3f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2016;
	}
x86_l_2001:
	/* 0x2001: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2004:
	/* 0x2004: cmp    DWORD PTR [rdi+0x10],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2007:
	/* 0x2007: jne    212c <filter_8ty_selector_val+0x155> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8492ULL;
	}
x86_l_200d:
	/* 0x200d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_200f:
	/* 0x200f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_2012:
	/* 0x2012: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_2015:
	/* 0x2015: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2016:
	/* 0x2016: cmp    rcx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 12ULL);
x86_l_201a:
	/* 0x201a: jne    2056 <filter_8ty_selector_val+0x7f> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_2056;
	}
x86_l_201c:
	/* 0x201c: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_201f:
	/* 0x201f: test   DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2022:
	/* 0x2022: jne    1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff5;
	}
x86_l_2024:
	/* 0x2024: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2027:
	/* 0x2027: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_202a:
	/* 0x202a: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8686ULL;
	}
x86_l_2030:
	/* 0x2030: test   DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2033:
	/* 0x2033: jne    1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff5;
	}
x86_l_2035:
	/* 0x2035: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2038:
	/* 0x2038: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8686ULL;
	}
x86_l_203e:
	/* 0x203e: test   DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2041:
	/* 0x2041: jne    1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff5;
	}
x86_l_2043:
	/* 0x2043: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2046:
	/* 0x2046: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8686ULL;
	}
x86_l_204c:
	/* 0x204c: test   DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_204f:
	/* 0x204f: jne    1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_1ff5;
	}
x86_l_2051:
	/* 0x2051: jmp    21ee <filter_8ty_selector_val+0x217> */
	return 8686ULL;
x86_l_2056:
	/* 0x2056: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2059:
	/* 0x2059: je     20c8 <filter_8ty_selector_val+0xf1> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8392ULL;
	}
x86_l_205b:
	/* 0x205b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_205e:
	/* 0x205e: jne    21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		return 8686ULL;
	}
x86_l_2064:
	/* 0x2064: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2067:
	/* 0x2067: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_206a:
	/* 0x206a: ja     21b5 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8629ULL;
	}
x86_l_2070:
	/* 0x2070: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2075:
	/* 0x2075: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_2078:
	/* 0x2078: jae    21b5 <filter_8ty_selector_val+0x1de> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		return 8629ULL;
	}
x86_l_207e:
	/* 0x207e: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2081:
	/* 0x2081: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2084:
	/* 0x2084: jg     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_1ff5;
	}
x86_l_208a:
	/* 0x208a: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_208d:
	/* 0x208d: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
	return 8336ULL;
}

static __noinline __u64 tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_6(
	struct x86_sim_state *__x86_state, __u64 __x86_pc)
{
	switch (__x86_pc) {
	case 8336ULL: goto x86_l_2090;
	case 8342ULL: goto x86_l_2096;
	case 8345ULL: goto x86_l_2099;
	case 8351ULL: goto x86_l_209f;
	case 8354ULL: goto x86_l_20a2;
	case 8360ULL: goto x86_l_20a8;
	case 8363ULL: goto x86_l_20ab;
	case 8369ULL: goto x86_l_20b1;
	case 8372ULL: goto x86_l_20b4;
	case 8378ULL: goto x86_l_20ba;
	case 8381ULL: goto x86_l_20bd;
	case 8387ULL: goto x86_l_20c3;
	case 8392ULL: goto x86_l_20c8;
	case 8395ULL: goto x86_l_20cb;
	case 8398ULL: goto x86_l_20ce;
	case 8404ULL: goto x86_l_20d4;
	case 8409ULL: goto x86_l_20d9;
	case 8412ULL: goto x86_l_20dc;
	case 8418ULL: goto x86_l_20e2;
	case 8421ULL: goto x86_l_20e5;
	case 8424ULL: goto x86_l_20e8;
	case 8430ULL: goto x86_l_20ee;
	case 8433ULL: goto x86_l_20f1;
	case 8436ULL: goto x86_l_20f4;
	case 8442ULL: goto x86_l_20fa;
	case 8445ULL: goto x86_l_20fd;
	case 8451ULL: goto x86_l_2103;
	case 8454ULL: goto x86_l_2106;
	case 8460ULL: goto x86_l_210c;
	case 8463ULL: goto x86_l_210f;
	case 8469ULL: goto x86_l_2115;
	case 8472ULL: goto x86_l_2118;
	case 8478ULL: goto x86_l_211e;
	case 8481ULL: goto x86_l_2121;
	case 8487ULL: goto x86_l_2127;
	case 8492ULL: goto x86_l_212c;
	case 8495ULL: goto x86_l_212f;
	case 8498ULL: goto x86_l_2132;
	case 8500ULL: goto x86_l_2134;
	case 8503ULL: goto x86_l_2137;
	case 8509ULL: goto x86_l_213d;
	case 8512ULL: goto x86_l_2140;
	case 8514ULL: goto x86_l_2142;
	case 8517ULL: goto x86_l_2145;
	case 8523ULL: goto x86_l_214b;
	case 8526ULL: goto x86_l_214e;
	case 8528ULL: goto x86_l_2150;
	case 8531ULL: goto x86_l_2153;
	case 8537ULL: goto x86_l_2159;
	case 8540ULL: goto x86_l_215c;
	case 8546ULL: goto x86_l_2162;
	case 8548ULL: goto x86_l_2164;
	case 8558ULL: goto x86_l_216e;
	case 8562ULL: goto x86_l_2172;
	case 8568ULL: goto x86_l_2178;
	case 8570ULL: goto x86_l_217a;
	case 8573ULL: goto x86_l_217d;
	case 8576ULL: goto x86_l_2180;
	case 8582ULL: goto x86_l_2186;
	case 8585ULL: goto x86_l_2189;
	case 8588ULL: goto x86_l_218c;
	case 8590ULL: goto x86_l_218e;
	case 8593ULL: goto x86_l_2191;
	case 8599ULL: goto x86_l_2197;
	case 8602ULL: goto x86_l_219a;
	case 8604ULL: goto x86_l_219c;
	case 8607ULL: goto x86_l_219f;
	case 8613ULL: goto x86_l_21a5;
	case 8616ULL: goto x86_l_21a8;
	case 8618ULL: goto x86_l_21aa;
	case 8621ULL: goto x86_l_21ad;
	case 8627ULL: goto x86_l_21b3;
	case 8629ULL: goto x86_l_21b5;
	case 8632ULL: goto x86_l_21b8;
	case 8635ULL: goto x86_l_21bb;
	case 8641ULL: goto x86_l_21c1;
	case 8644ULL: goto x86_l_21c4;
	case 8647ULL: goto x86_l_21c7;
	case 8649ULL: goto x86_l_21c9;
	case 8652ULL: goto x86_l_21cc;
	case 8658ULL: goto x86_l_21d2;
	case 8661ULL: goto x86_l_21d5;
	case 8663ULL: goto x86_l_21d7;
	case 8666ULL: goto x86_l_21da;
	case 8672ULL: goto x86_l_21e0;
	case 8675ULL: goto x86_l_21e3;
	case 8677ULL: goto x86_l_21e5;
	case 8680ULL: goto x86_l_21e8;
	case 8686ULL: goto x86_l_21ee;
	case 8688ULL: goto x86_l_21f0;
	case 8689ULL: goto x86_l_21f1;
	case 8692ULL: goto x86_l_21f4;
	case 8695ULL: goto x86_l_21f7;
	case 8698ULL: goto x86_l_21fa;
	case 8704ULL: goto x86_l_2200;
	case 8709ULL: goto x86_l_2205;
	case 8712ULL: goto x86_l_2208;
	case 8718ULL: goto x86_l_220e;
	case 8721ULL: goto x86_l_2211;
	case 8724ULL: goto x86_l_2214;
	case 8726ULL: goto x86_l_2216;
	case 8731ULL: goto x86_l_221b;
	case 8734ULL: goto x86_l_221e;
	case 8736ULL: goto x86_l_2220;
	case 8739ULL: goto x86_l_2223;
	case 8745ULL: goto x86_l_2229;
	case 8748ULL: goto x86_l_222c;
	case 8751ULL: goto x86_l_222f;
	case 8757ULL: goto x86_l_2235;
	case 8760ULL: goto x86_l_2238;
	case 8762ULL: goto x86_l_223a;
	case 8765ULL: goto x86_l_223d;
	case 8771ULL: goto x86_l_2243;
	case 8774ULL: goto x86_l_2246;
	case 8780ULL: goto x86_l_224c;
	case 8783ULL: goto x86_l_224f;
	case 8785ULL: goto x86_l_2251;
	case 8788ULL: goto x86_l_2254;
	case 8794ULL: goto x86_l_225a;
	case 8797ULL: goto x86_l_225d;
	case 8803ULL: goto x86_l_2263;
	case 8805ULL: goto x86_l_2265;
	case 8808ULL: goto x86_l_2268;
	case 8814ULL: goto x86_l_226e;
	case 8817ULL: goto x86_l_2271;
	case 8823ULL: goto x86_l_2277;
	case 8828ULL: goto x86_l_227c;
	case 8831ULL: goto x86_l_227f;
	case 8834ULL: goto x86_l_2282;
	case 8838ULL: goto x86_l_2286;
	case 8841ULL: goto x86_l_2289;
	case 8844ULL: goto x86_l_228c;
	case 8847ULL: goto x86_l_228f;
	case 8850ULL: goto x86_l_2292;
	case 8856ULL: goto x86_l_2298;
	case 8859ULL: goto x86_l_229b;
	case 8863ULL: goto x86_l_229f;
	case 8866ULL: goto x86_l_22a2;
	case 8870ULL: goto x86_l_22a6;
	case 8873ULL: goto x86_l_22a9;
	case 8876ULL: goto x86_l_22ac;
	case 8879ULL: goto x86_l_22af;
	case 8885ULL: goto x86_l_22b5;
	case 8888ULL: goto x86_l_22b8;
	case 8892ULL: goto x86_l_22bc;
	case 8895ULL: goto x86_l_22bf;
	case 8899ULL: goto x86_l_22c3;
	case 8902ULL: goto x86_l_22c6;
	case 8905ULL: goto x86_l_22c9;
	case 8908ULL: goto x86_l_22cc;
	case 8914ULL: goto x86_l_22d2;
	case 8917ULL: goto x86_l_22d5;
	case 8920ULL: goto x86_l_22d8;
	case 8923ULL: goto x86_l_22db;
	case 8927ULL: goto x86_l_22df;
	case 8929ULL: goto x86_l_22e1;
	case 8932ULL: goto x86_l_22e4;
	case 8935ULL: goto x86_l_22e7;
	case 8937ULL: goto x86_l_22e9;
	case 8942ULL: goto x86_l_22ee;
	case 8945ULL: goto x86_l_22f1;
	case 8947ULL: goto x86_l_22f3;
	case 8950ULL: goto x86_l_22f6;
	case 8952ULL: goto x86_l_22f8;
	case 8953ULL: goto x86_l_22f9;
	case 8956ULL: goto x86_l_22fc;
	case 8959ULL: goto x86_l_22ff;
	case 8963ULL: goto x86_l_2303;
	case 8966ULL: goto x86_l_2306;
	case 8969ULL: goto x86_l_2309;
	case 8972ULL: goto x86_l_230c;
	case 8975ULL: goto x86_l_230f;
	case 8981ULL: goto x86_l_2315;
	case 8984ULL: goto x86_l_2318;
	case 8988ULL: goto x86_l_231c;
	case 8991ULL: goto x86_l_231f;
	case 8995ULL: goto x86_l_2323;
	case 8998ULL: goto x86_l_2326;
	case 9001ULL: goto x86_l_2329;
	case 9004ULL: goto x86_l_232c;
	case 9006ULL: goto x86_l_232e;
	case 9009ULL: goto x86_l_2331;
	case 9013ULL: goto x86_l_2335;
	case 9016ULL: goto x86_l_2338;
	case 9020ULL: goto x86_l_233c;
	case 9023ULL: goto x86_l_233f;
	case 9026ULL: goto x86_l_2342;
	case 9029ULL: goto x86_l_2345;
	case 9031ULL: goto x86_l_2347;
	case 9034ULL: goto x86_l_234a;
	case 9037ULL: goto x86_l_234d;
	case 9040ULL: goto x86_l_2350;
	case 9044ULL: goto x86_l_2354;
	case 9047ULL: goto x86_l_2357;
	case 9050ULL: goto x86_l_235a;
	case 9052ULL: goto x86_l_235c;
	case 9055ULL: goto x86_l_235f;
	case 9058ULL: goto x86_l_2362;
	case 9060ULL: goto x86_l_2364;
	case 9063ULL: goto x86_l_2367;
	case 9065ULL: goto x86_l_2369;
	case 9068ULL: goto x86_l_236c;
	case 9070ULL: goto x86_l_236e;
	case 9073ULL: goto x86_l_2371;
	case 9075ULL: goto x86_l_2373;
	case 9078ULL: goto x86_l_2376;
	case 9080ULL: goto x86_l_2378;
	case 9083ULL: goto x86_l_237b;
	case 9089ULL: goto x86_l_2381;
	case 9092ULL: goto x86_l_2384;
	case 9094ULL: goto x86_l_2386;
	case 9096ULL: goto x86_l_2388;
	case 9099ULL: goto x86_l_238b;
	case 9101ULL: goto x86_l_238d;
	case 9104ULL: goto x86_l_2390;
	case 9110ULL: goto x86_l_2396;
	case 9112ULL: goto x86_l_2398;
	case 9114ULL: goto x86_l_239a;
	case 9117ULL: goto x86_l_239d;
	case 9120ULL: goto x86_l_23a0;
	case 9123ULL: goto x86_l_23a3;
	case 9125ULL: goto x86_l_23a5;
	case 9128ULL: goto x86_l_23a8;
	case 9129ULL: goto x86_l_23a9;
	case 9131ULL: goto x86_l_23ab;
	case 9132ULL: goto x86_l_23ac;
	case 9136ULL: goto x86_l_23b0;
	case 9139ULL: goto x86_l_23b3;
	case 9142ULL: goto x86_l_23b6;
	case 9146ULL: goto x86_l_23ba;
	case 9150ULL: goto x86_l_23be;
	case 9157ULL: goto x86_l_23c5;
	case 9162ULL: goto x86_l_23ca;
	case 9167ULL: goto x86_l_23cf;
	case 9169ULL: goto x86_l_23d1;
	case 9172ULL: goto x86_l_23d4;
	case 9174ULL: goto x86_l_23d6;
	case 9177ULL: goto x86_l_23d9;
	case 9181ULL: goto x86_l_23dd;
	case 9186ULL: goto x86_l_23e2;
	case 9191ULL: goto x86_l_23e7;
	case 9196ULL: goto x86_l_23ec;
	case 9198ULL: goto x86_l_23ee;
	case 9201ULL: goto x86_l_23f1;
	case 9203ULL: goto x86_l_23f3;
	case 9206ULL: goto x86_l_23f6;
	case 9208ULL: goto x86_l_23f8;
	case 9213ULL: goto x86_l_23fd;
	case 9216ULL: goto x86_l_2400;
	case 9218ULL: goto x86_l_2402;
	case 9221ULL: goto x86_l_2405;
	case 9224ULL: goto x86_l_2408;
	case 9226ULL: goto x86_l_240a;
	case 9228ULL: goto x86_l_240c;
	case 9232ULL: goto x86_l_2410;
	case 9233ULL: goto x86_l_2411;
	case 9235ULL: goto x86_l_2413;
	case 9236ULL: goto x86_l_2414;
	case 9241ULL: goto x86_l_2419;
	case 9244ULL: goto x86_l_241c;
	case 9246ULL: goto x86_l_241e;
	case 9249ULL: goto x86_l_2421;
	case 9252ULL: goto x86_l_2424;
	case 9255ULL: goto x86_l_2427;
	case 9259ULL: goto x86_l_242b;
	case 9260ULL: goto x86_l_242c;
	case 9262ULL: goto x86_l_242e;
	case 9263ULL: goto x86_l_242f;
	case 9264ULL: goto x86_l_2430;
	case 9268ULL: goto x86_l_2434;
	case 9275ULL: goto x86_l_243b;
	case 9277ULL: goto x86_l_243d;
	case 9283ULL: goto x86_l_2443;
	case 9289ULL: goto x86_l_2449;
	case 9292ULL: goto x86_l_244c;
	case 9296ULL: goto x86_l_2450;
	case 9300ULL: goto x86_l_2454;
	case 9305ULL: goto x86_l_2459;
	case 9310ULL: goto x86_l_245e;
	case 9315ULL: goto x86_l_2463;
	case 9317ULL: goto x86_l_2465;
	case 9321ULL: goto x86_l_2469;
	case 9325ULL: goto x86_l_246d;
	case 9330ULL: goto x86_l_2472;
	case 9332ULL: goto x86_l_2474;
	case 9335ULL: goto x86_l_2477;
	case 9337ULL: goto x86_l_2479;
	case 9339ULL: goto x86_l_247b;
	case 9344ULL: goto x86_l_2480;
	case 9350ULL: goto x86_l_2486;
	case 9355ULL: goto x86_l_248b;
	case 9357ULL: goto x86_l_248d;
	case 9359ULL: goto x86_l_248f;
	case 9362ULL: goto x86_l_2492;
	case 9365ULL: goto x86_l_2495;
	case 9367ULL: goto x86_l_2497;
	case 9370ULL: goto x86_l_249a;
	case 9372ULL: goto x86_l_249c;
	case 9374ULL: goto x86_l_249e;
	case 9376ULL: goto x86_l_24a0;
	case 9378ULL: goto x86_l_24a2;
	case 9381ULL: goto x86_l_24a5;
	case 9383ULL: goto x86_l_24a7;
	case 9386ULL: goto x86_l_24aa;
	case 9388ULL: goto x86_l_24ac;
	case 9390ULL: goto x86_l_24ae;
	case 9392ULL: goto x86_l_24b0;
	case 9394ULL: goto x86_l_24b2;
	case 9397ULL: goto x86_l_24b5;
	case 9399ULL: goto x86_l_24b7;
	case 9402ULL: goto x86_l_24ba;
	case 9404ULL: goto x86_l_24bc;
	case 9406ULL: goto x86_l_24be;
	case 9408ULL: goto x86_l_24c0;
	case 9410ULL: goto x86_l_24c2;
	case 9413ULL: goto x86_l_24c5;
	case 9417ULL: goto x86_l_24c9;
	case 9418ULL: goto x86_l_24ca;
	case 9419ULL: goto x86_l_24cb;
	case 9421ULL: goto x86_l_24cd;
	case 9425ULL: goto x86_l_24d1;
	case 9426ULL: goto x86_l_24d2;
	default: return 0xffffffffffffffffULL;
	}
x86_l_2090:
	/* 0x2090: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_2096:
	/* 0x2096: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2099:
	/* 0x2099: jg     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8181ULL;
	}
x86_l_209f:
	/* 0x209f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_20a2:
	/* 0x20a2: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_20a8:
	/* 0x20a8: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20ab:
	/* 0x20ab: jg     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8181ULL;
	}
x86_l_20b1:
	/* 0x20b1: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_20b4:
	/* 0x20b4: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_20ba:
	/* 0x20ba: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_20bd:
	/* 0x20bd: jg     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		return 8181ULL;
	}
x86_l_20c3:
	/* 0x20c3: jmp    21ee <filter_8ty_selector_val+0x217> */
	goto x86_l_21ee;
x86_l_20c8:
	/* 0x20c8: mov    ecx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20cb:
	/* 0x20cb: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_20ce:
	/* 0x20ce: ja     217a <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_217a;
	}
x86_l_20d4:
	/* 0x20d4: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_20d9:
	/* 0x20d9: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_20dc:
	/* 0x20dc: jae    217a <filter_8ty_selector_val+0x1a3> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_217a;
	}
x86_l_20e2:
	/* 0x20e2: movsx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_20e5:
	/* 0x20e5: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e8:
	/* 0x20e8: jl     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8181ULL;
	}
x86_l_20ee:
	/* 0x20ee: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_20f1:
	/* 0x20f1: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_20f4:
	/* 0x20f4: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_20fa:
	/* 0x20fa: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_20fd:
	/* 0x20fd: jl     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8181ULL;
	}
x86_l_2103:
	/* 0x2103: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2106:
	/* 0x2106: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_210c:
	/* 0x210c: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_210f:
	/* 0x210f: jl     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8181ULL;
	}
x86_l_2115:
	/* 0x2115: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_2118:
	/* 0x2118: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_211e:
	/* 0x211e: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2121:
	/* 0x2121: jl     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_L)) {
		return 8181ULL;
	}
x86_l_2127:
	/* 0x2127: jmp    21ee <filter_8ty_selector_val+0x217> */
	goto x86_l_21ee;
x86_l_212c:
	/* 0x212c: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_212f:
	/* 0x212f: cmp    esi,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 13ULL);
x86_l_2132:
	/* 0x2132: jb     2159 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2159;
	}
x86_l_2134:
	/* 0x2134: cmp    DWORD PTR [rdi+0x14],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2137:
	/* 0x2137: je     200d <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8205ULL;
	}
x86_l_213d:
	/* 0x213d: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_2140:
	/* 0x2140: jb     2159 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2159;
	}
x86_l_2142:
	/* 0x2142: cmp    DWORD PTR [rdi+0x18],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2145:
	/* 0x2145: je     200d <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8205ULL;
	}
x86_l_214b:
	/* 0x214b: cmp    esi,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_214e:
	/* 0x214e: jb     2159 <filter_8ty_selector_val+0x182> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2159;
	}
x86_l_2150:
	/* 0x2150: cmp    DWORD PTR [rdi+0x1c],edx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2153:
	/* 0x2153: je     200d <filter_8ty_selector_val+0x36> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		return 8205ULL;
	}
x86_l_2159:
	/* 0x2159: cmp    ecx,0x25 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 37ULL);
x86_l_215c:
	/* 0x215c: ja     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_21ee;
	}
x86_l_2162:
	/* 0x2162: mov    ecx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_2164:
	/* 0x2164: movabs rdx,0x200c000050 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 137640280144ULL);
x86_l_216e:
	/* 0x216e: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_2172:
	/* 0x2172: jb     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8181ULL;
	}
x86_l_2178:
	/* 0x2178: jmp    21ee <filter_8ty_selector_val+0x217> */
	goto x86_l_21ee;
x86_l_217a:
	/* 0x217a: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_217d:
	/* 0x217d: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2180:
	/* 0x2180: jb     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8181ULL;
	}
x86_l_2186:
	/* 0x2186: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2189:
	/* 0x2189: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_218c:
	/* 0x218c: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_218e:
	/* 0x218e: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2191:
	/* 0x2191: jb     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8181ULL;
	}
x86_l_2197:
	/* 0x2197: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_219a:
	/* 0x219a: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_219c:
	/* 0x219c: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_219f:
	/* 0x219f: jb     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8181ULL;
	}
x86_l_21a5:
	/* 0x21a5: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_21a8:
	/* 0x21a8: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_21aa:
	/* 0x21aa: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21ad:
	/* 0x21ad: jb     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		return 8181ULL;
	}
x86_l_21b3:
	/* 0x21b3: jmp    21ee <filter_8ty_selector_val+0x217> */
	goto x86_l_21ee;
x86_l_21b5:
	/* 0x21b5: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_21b8:
	/* 0x21b8: cmp    DWORD PTR [rdi+0x10],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21bb:
	/* 0x21bb: ja     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8181ULL;
	}
x86_l_21c1:
	/* 0x21c1: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_21c4:
	/* 0x21c4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_21c7:
	/* 0x21c7: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_21c9:
	/* 0x21c9: cmp    DWORD PTR [rdi+0x14],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21cc:
	/* 0x21cc: ja     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8181ULL;
	}
x86_l_21d2:
	/* 0x21d2: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_21d5:
	/* 0x21d5: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_21d7:
	/* 0x21d7: cmp    DWORD PTR [rdi+0x18],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_21da:
	/* 0x21da: ja     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8181ULL;
	}
x86_l_21e0:
	/* 0x21e0: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_21e3:
	/* 0x21e3: jb     21ee <filter_8ty_selector_val+0x217> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_21ee;
	}
x86_l_21e5:
	/* 0x21e5: cmp    DWORD PTR [rdi+0x1c],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_21e8:
	/* 0x21e8: ja     1ff5 <filter_8ty_selector_val+0x1e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		return 8181ULL;
	}
x86_l_21ee:
	/* 0x21ee: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21f0:
	/* 0x21f0: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_21f1:
	/* 0x21f1: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21f4:
	/* 0x21f4: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_21f7:
	/* 0x21f7: cmp    eax,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_21fa:
	/* 0x21fa: ja     22e1 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_22e1;
	}
x86_l_2200:
	/* 0x2200: mov    edx,0x1402 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5122ULL);
x86_l_2205:
	/* 0x2205: bt     edx,eax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_2208:
	/* 0x2208: jae    22e1 <filter_8ty_range+0xf0> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22e1;
	}
x86_l_220e:
	/* 0x220e: movsx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2211:
	/* 0x2211: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_2214:
	/* 0x2214: jne    227c <filter_8ty_range+0x8b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_227c;
	}
x86_l_2216:
	/* 0x2216: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_221b:
	/* 0x221b: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_221e:
	/* 0x221e: jg     2229 <filter_8ty_range+0x38> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2229;
	}
x86_l_2220:
	/* 0x2220: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2223:
	/* 0x2223: jge    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22f8;
	}
x86_l_2229:
	/* 0x2229: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222c:
	/* 0x222c: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_222f:
	/* 0x222f: jb     2398 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2398;
	}
x86_l_2235:
	/* 0x2235: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2238:
	/* 0x2238: jg     2243 <filter_8ty_range+0x52> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_2243;
	}
x86_l_223a:
	/* 0x223a: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_223d:
	/* 0x223d: jge    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22f8;
	}
x86_l_2243:
	/* 0x2243: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2246:
	/* 0x2246: jb     2398 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2398;
	}
x86_l_224c:
	/* 0x224c: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_224f:
	/* 0x224f: jg     225a <filter_8ty_range+0x69> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_225a;
	}
x86_l_2251:
	/* 0x2251: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2254:
	/* 0x2254: jge    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22f8;
	}
x86_l_225a:
	/* 0x225a: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_225d:
	/* 0x225d: jb     2398 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2398;
	}
x86_l_2263:
	/* 0x2263: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2265:
	/* 0x2265: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2268:
	/* 0x2268: jg     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_G)) {
		goto x86_l_239a;
	}
x86_l_226e:
	/* 0x226e: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2271:
	/* 0x2271: jge    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_GE)) {
		goto x86_l_22f8;
	}
x86_l_2277:
	/* 0x2277: jmp    239a <filter_8ty_range+0x1a9> */
	goto x86_l_239a;
x86_l_227c:
	/* 0x227c: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227f:
	/* 0x227f: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2282:
	/* 0x2282: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_2286:
	/* 0x2286: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2289:
	/* 0x2289: setge  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_GE);
x86_l_228c:
	/* 0x228c: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_228f:
	/* 0x228f: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2292:
	/* 0x2292: jb     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_239a;
	}
x86_l_2298:
	/* 0x2298: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_229b:
	/* 0x229b: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_229f:
	/* 0x229f: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_22a2:
	/* 0x22a2: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_22a6:
	/* 0x22a6: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22a9:
	/* 0x22a9: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22ac:
	/* 0x22ac: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_22af:
	/* 0x22af: jb     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_239a;
	}
x86_l_22b5:
	/* 0x22b5: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_22b8:
	/* 0x22b8: setle  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_LE);
x86_l_22bc:
	/* 0x22bc: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22bf:
	/* 0x22bf: setge  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_GE);
x86_l_22c3:
	/* 0x22c3: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_22c6:
	/* 0x22c6: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_22c9:
	/* 0x22c9: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_22cc:
	/* 0x22cc: jb     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_239a;
	}
x86_l_22d2:
	/* 0x22d2: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22d5:
	/* 0x22d5: setle  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_LE);
x86_l_22d8:
	/* 0x22d8: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_22db:
	/* 0x22db: setge  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_GE);
x86_l_22df:
	/* 0x22df: jmp    2354 <filter_8ty_range+0x163> */
	goto x86_l_2354;
x86_l_22e1:
	/* 0x22e1: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_22e4:
	/* 0x22e4: cmp    ecx,0x1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 31ULL);
x86_l_22e7:
	/* 0x22e7: jne    22f9 <filter_8ty_range+0x108> */
	if (X86_SIM_L_EVAL_CC(X86_CC_NE)) {
		goto x86_l_22f9;
	}
x86_l_22e9:
	/* 0x22e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22ee:
	/* 0x22ee: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f1:
	/* 0x22f1: ja     235c <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_235c;
	}
x86_l_22f3:
	/* 0x22f3: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_22f6:
	/* 0x22f6: jb     235c <filter_8ty_range+0x16b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_235c;
	}
x86_l_22f8:
	/* 0x22f8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_22f9:
	/* 0x22f9: mov    eax,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22fc:
	/* 0x22fc: cmp    DWORD PTR [rdi+0x10],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22ff:
	/* 0x22ff: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2303:
	/* 0x2303: cmp    DWORD PTR [rdi+0x14],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2306:
	/* 0x2306: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_2309:
	/* 0x2309: and    dl,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_230c:
	/* 0x230c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_230f:
	/* 0x230f: jb     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_239a;
	}
x86_l_2315:
	/* 0x2315: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2318:
	/* 0x2318: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_231c:
	/* 0x231c: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_231f:
	/* 0x231f: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_2323:
	/* 0x2323: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_2326:
	/* 0x2326: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2329:
	/* 0x2329: cmp    eax,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_232c:
	/* 0x232c: jb     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_239a;
	}
x86_l_232e:
	/* 0x232e: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2331:
	/* 0x2331: setbe  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_BE);
x86_l_2335:
	/* 0x2335: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2338:
	/* 0x2338: setae  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_AE);
x86_l_233c:
	/* 0x233c: and    r9b,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_8, X86_ALU_AND);
x86_l_233f:
	/* 0x233f: or     dl,r9b */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R9, X86_WIDTH_8, X86_ALU_OR);
x86_l_2342:
	/* 0x2342: cmp    eax,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33ULL);
x86_l_2345:
	/* 0x2345: jb     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_239a;
	}
x86_l_2347:
	/* 0x2347: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_234a:
	/* 0x234a: setbe  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_BE);
x86_l_234d:
	/* 0x234d: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2350:
	/* 0x2350: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_2354:
	/* 0x2354: and    sil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_2357:
	/* 0x2357: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_235a:
	/* 0x235a: jmp    239a <filter_8ty_range+0x1a9> */
	goto x86_l_239a;
x86_l_235c:
	/* 0x235c: mov    edx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_235f:
	/* 0x235f: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_2362:
	/* 0x2362: jb     2398 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2398;
	}
x86_l_2364:
	/* 0x2364: cmp    DWORD PTR [rdi+0x18],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2367:
	/* 0x2367: ja     236e <filter_8ty_range+0x17d> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_236e;
	}
x86_l_2369:
	/* 0x2369: cmp    DWORD PTR [rdi+0x1c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_236c:
	/* 0x236c: jae    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22f8;
	}
x86_l_236e:
	/* 0x236e: cmp    edx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 25ULL);
x86_l_2371:
	/* 0x2371: jb     2398 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2398;
	}
x86_l_2373:
	/* 0x2373: cmp    DWORD PTR [rdi+0x20],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2376:
	/* 0x2376: ja     2381 <filter_8ty_range+0x190> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2381;
	}
x86_l_2378:
	/* 0x2378: cmp    DWORD PTR [rdi+0x24],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_237b:
	/* 0x237b: jae    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22f8;
	}
x86_l_2381:
	/* 0x2381: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_2384:
	/* 0x2384: jb     2398 <filter_8ty_range+0x1a7> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_2398;
	}
x86_l_2386:
	/* 0x2386: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2388:
	/* 0x2388: cmp    DWORD PTR [rdi+0x28],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_238b:
	/* 0x238b: ja     239a <filter_8ty_range+0x1a9> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_239a;
	}
x86_l_238d:
	/* 0x238d: cmp    DWORD PTR [rdi+0x2c],esi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2390:
	/* 0x2390: jae    22f8 <filter_8ty_range+0x107> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_22f8;
	}
x86_l_2396:
	/* 0x2396: jmp    239a <filter_8ty_range+0x1a9> */
	goto x86_l_239a;
x86_l_2398:
	/* 0x2398: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_239a:
	/* 0x239a: cmp    ecx,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_239d:
	/* 0x239d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_23a0:
	/* 0x23a0: xor    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_XOR, 1ULL);
x86_l_23a3:
	/* 0x23a3: and    dl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_8, X86_ALU_AND);
x86_l_23a5:
	/* 0x23a5: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23a8:
	/* 0x23a8: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_23a9:
	/* 0x23a9: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_23ab:
	/* 0x23ab: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_23ac:
	/* 0x23ac: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_23b0:
	/* 0x23b0: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_23b3:
	/* 0x23b3: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_23b6:
	/* 0x23b6: movzx  eax,BYTE PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_23ba:
	/* 0x23ba: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23be:
	/* 0x23be: mov    rdi,QWORD PTR [rip+0x1840] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&argfilter_maps)));
x86_l_23c5:
	/* 0x23c5: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23ca:
	/* 0x23ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23cf:
	/* 0x23cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d1:
	/* 0x23d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d4:
	/* 0x23d4: je     240a <filter_8ty_map+0x61> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_240a;
	}
x86_l_23d6:
	/* 0x23d6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_23d9:
	/* 0x23d9: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23dd:
	/* 0x23dd: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e2:
	/* 0x23e2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23e7:
	/* 0x23e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23ec:
	/* 0x23ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23ee:
	/* 0x23ee: mov    edx,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_23f1:
	/* 0x23f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_23f3:
	/* 0x23f3: cmp    edx,0x1d */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 29ULL);
x86_l_23f6:
	/* 0x23f6: ja     2424 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_2424;
	}
x86_l_23f8:
	/* 0x23f8: mov    esi,0x30038400 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 805536768ULL);
x86_l_23fd:
	/* 0x23fd: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_2400:
	/* 0x2400: jae    2414 <filter_8ty_map+0x6b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2414;
	}
x86_l_2402:
	/* 0x2402: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2405:
	/* 0x2405: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_2408:
	/* 0x2408: jmp    2424 <filter_8ty_map+0x7b> */
	goto x86_l_2424;
x86_l_240a:
	/* 0x240a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_240c:
	/* 0x240c: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2410:
	/* 0x2410: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2411:
	/* 0x2411: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2413:
	/* 0x2413: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_2414:
	/* 0x2414: mov    esi,0xc0800 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 788480ULL);
x86_l_2419:
	/* 0x2419: bt     esi,edx */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_241c:
	/* 0x241c: jae    2424 <filter_8ty_map+0x7b> */
	if (X86_SIM_L_EVAL_CC(X86_CC_AE)) {
		goto x86_l_2424;
	}
x86_l_241e:
	/* 0x241e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2421:
	/* 0x2421: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_2424:
	/* 0x2424: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2427:
	/* 0x2427: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_242b:
	/* 0x242b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_242c:
	/* 0x242c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_242e:
	/* 0x242e: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_242f:
	/* 0x242f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_2430:
	/* 0x2430: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_2434:
	/* 0x2434: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_243b:
	/* 0x243b: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_243d:
	/* 0x243d: cmp    rax,0x1000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 4096ULL);
x86_l_2443:
	/* 0x2443: ja     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_A)) {
		goto x86_l_24cb;
	}
x86_l_2449:
	/* 0x2449: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_244c:
	/* 0x244c: lea    rcx,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_2450:
	/* 0x2450: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2454:
	/* 0x2454: lea    rdi,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2459:
	/* 0x2459: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_245e:
	/* 0x245e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_2463:
	/* 0x2463: mov    ecx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2465:
	/* 0x2465: lea    rdx,[rsi+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2469:
	/* 0x2469: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_246d:
	/* 0x246d: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_2472:
	/* 0x2472: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2474:
	/* 0x2474: mov    edx,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2477:
	/* 0x2477: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2479:
	/* 0x2479: je     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cb;
	}
x86_l_247b:
	/* 0x247b: movzx  ecx,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2480:
	/* 0x2480: and    ecx,0xf000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 61440ULL);
x86_l_2486:
	/* 0x2486: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_248b:
	/* 0x248b: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_248d:
	/* 0x248d: je     24cd <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_248f:
	/* 0x248f: mov    edx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2492:
	/* 0x2492: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_2495:
	/* 0x2495: jbe    24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_BE)) {
		goto x86_l_24cb;
	}
x86_l_2497:
	/* 0x2497: mov    esi,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_249a:
	/* 0x249a: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_249c:
	/* 0x249c: je     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cb;
	}
x86_l_249e:
	/* 0x249e: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_24a0:
	/* 0x24a0: je     24cd <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_24a2:
	/* 0x24a2: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_24a5:
	/* 0x24a5: jb     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24cb;
	}
x86_l_24a7:
	/* 0x24a7: mov    esi,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_24aa:
	/* 0x24aa: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_24ac:
	/* 0x24ac: je     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cb;
	}
x86_l_24ae:
	/* 0x24ae: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_24b0:
	/* 0x24b0: je     24cd <filter_file_type+0x9e> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cd;
	}
x86_l_24b2:
	/* 0x24b2: cmp    edx,0x15 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 21ULL);
x86_l_24b5:
	/* 0x24b5: jb     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_B)) {
		goto x86_l_24cb;
	}
x86_l_24b7:
	/* 0x24b7: mov    edx,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_24ba:
	/* 0x24ba: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_24bc:
	/* 0x24bc: je     24cb <filter_file_type+0x9c> */
	if (X86_SIM_L_EVAL_CC(X86_CC_E)) {
		goto x86_l_24cb;
	}
x86_l_24be:
	/* 0x24be: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24c0:
	/* 0x24c0: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_24c2:
	/* 0x24c2: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_24c5:
	/* 0x24c5: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24c9:
	/* 0x24c9: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_24ca:
	/* 0x24ca: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
x86_l_24cb:
	/* 0x24cb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24cd:
	/* 0x24cd: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_24d1:
	/* 0x24d1: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_24d2:
	/* 0x24d2: ret */
	if (__x86_sim_call_depth == 0)
		return 0xffffffffffffffffULL;
	__x86_sim_call_depth--;
	__x86_sim_ret_addr = X86_SIM_L_STACK_READ((__s64)(long)__x86_rsp.ptr, X86_WIDTH_64);
	__x86_rsp.ptr = (__u8 *)__x86_rsp.ptr + 8;
	return __x86_sim_ret_addr;
	return 0xffffffffffffffffULL;
}

SEC("xdp")
int tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_sim_xdp(struct xdp_md *ctx)
{
	struct x86_sim_state __x86_state_storage = {};
	X86_SIM_L_BIND_COMMON_STATE(&__x86_state_storage);
	__x86_sim_abi.data = (void *)(long)ctx->data;
	__x86_sim_abi.data_end = (void *)(long)ctx->data_end;
	__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__x86_rdi.ptr = &__x86_sim_abi;
	__x86_rdi_tag = X86_SIM_TAG_ABI;
	__u64 __x86_pc = 0ULL;
	for (__u32 __x86_iter = 0; __x86_iter < 10504U; __x86_iter++) {
		if (__x86_pc == 0xffffffffffffffffULL)
			break;
		if (__x86_pc >= 0ULL && __x86_pc <= 1547ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_0(__x86_state, __x86_pc);
		else if (__x86_pc >= 1549ULL && __x86_pc <= 2839ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_1(__x86_state, __x86_pc);
		else if (__x86_pc >= 2840ULL && __x86_pc <= 4249ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_2(__x86_state, __x86_pc);
		else if (__x86_pc >= 4253ULL && __x86_pc <= 5667ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_3(__x86_state, __x86_pc);
		else if (__x86_pc >= 5670ULL && __x86_pc <= 7013ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_4(__x86_state, __x86_pc);
		else if (__x86_pc >= 7017ULL && __x86_pc <= 8333ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_5(__x86_state, __x86_pc);
		else if (__x86_pc >= 8336ULL && __x86_pc <= 9426ULL)
			__x86_pc = tetragon_bpf_multi_kprobe_v61_generic_kprobe_filter_arg_x86_chunk_6(__x86_state, __x86_pc);
		else
			__x86_pc = 0xffffffffffffffffULL;
	}
	if (__x86_pc != 0xffffffffffffffffULL)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64);
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
